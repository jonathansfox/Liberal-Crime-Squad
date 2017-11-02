
#ifdef WIN32 // safe to do now that we did that earlier thing defining WIN32 if _WIN32 was defined
#include <windows.h>
#define GO_PORTABLE
#include <io.h> //needed for unlink()
#include <direct.h>
#ifndef __STRICT_ANSI__
#define HAS_STRICMP
#endif
//Visual C++ .NET (7) includes the STL with vector, so we
//will use that, otherwise the HP STL Vector.h will be used.
#ifdef __MINGW32__
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#else
#if _MSC_VER > 1200
#define WIN32_DOTNET
#include <ciso646> // alternate keywords included in the ISO C++ standard
// but not directly supported by Microsoft Visual Studio C++
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#else
#define WIN32_PRE_DOTNET
#include <iostream.h>
#include <fstream.h>
#include "vector.h"
#include "map.h"
#endif
#endif
#endif
#ifndef WIN32
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <unistd.h>
#include <ctype.h>
#define GO_PORTABLE
#if defined(HAVE_WIDE_NCURSES) && defined(__STDC_ISO_10646__)
#define CH_USE_UNICODE
#else
#define CH_USE_ASCII_HACK
#endif
#ifdef HAVE_LIBXCURSES
#define XCURSES
#endif
#ifdef HAVE_LIBNCURSES
#define NCURSES
#endif
#ifdef XCURSES
#define HAVE_PROTO 1
#define CPLUSPLUS  1
/* Try these PDCurses/Xcurses options later...
#define FAST_VIDEO
#define REGISTERWINDOWS
*/
#include <xcurses.h> //This is the X11 Port of PDCurses
//undo PDCurses macros that break vector class
#undef erase // FIXME: Umm... Now erase() and clear() don't work in
#undef clear //       dumpcaps.cpp
#else
#if defined(USE_NCURSES)
#include <ncurses.h>
#define NCURSES
#elif defined(USE_NCURSES_W)
#include <ncursesw/ncurses.h>
#define NCURSES
#elif defined(NCURSES)
#define USE_NCURSES
#include <ncurses.h>
#else
#include <stddef.h>
#include <curses.h>
#endif
// Undo mvaddstr macro and re-implement as function to support overloading
//#ifdef mvaddstr
//   #undef mvaddstr
//   inline int mvaddstr(int y,int x,const char* text) { int ret=move(y,x); if(ret!=ERR) ret=addstr(text); return ret; }
//#endif
#endif
#endif
/*******************************************************************************
*
*                             Logging Stuff
*                             Folder: "log"
*
*******************************************************************************/
using std::fstream;
using std::string;
/* Not in log.cpp, we just need this declared inside this header */
void LCSCloseFileCPP(fstream &file);
/*
Here's an example of how to use gamelog:
We have:
------
move(8,1);
addstr("A sniper takes out ");
addstr(pool[targ]->name);
addstr("!");
------
Change it to:
------
move(8,1);
addstr("A sniper takes out ", gamelog);
addstr(pool[targ]->name, gamelog);
addstr("!", gamelog);
gamelog.nextMessage();
------
If there are times where you want to log stuff differently than displayed in the
game or not to be displayed at all, simply use:
------
gamelog.log("This is a message we don't want the user to see ingame.");
------
Let's say you want to make a newline in a message. Do the following:
------
addstr("A sniper takes out ", gamelog);
addstr(pool[targ]->name, gamelog);
addstr("!", gamelog);
gamelog.newline();
addstr("The sniper breaks into a dance!");
gamelog.nextMessage();
------
*/
//Whether or not it should autonewline logfiles by defualt.
const int  NEWLINEMODE_LOGFILES_DEFAULT = 1;
class Log
{
private:
	//False if not initialized. True if initialized (All of this is via the initialize() function).
	//Makes sure that the programmer initialized the function prior to attempted usage.
	bool initialized;
	string filename; //The name/relevant path of the file.
					 //The file itself.
					 //fstream for easier use in case I (or somebody else) wants to add a "read log" feature.
					 //I would like that; so that one could check events and the like ingame.
	fstream file;
	//Controls the automatic addition of newlines.
	//0 = no newlines.
	//1 = newline.
	//2 = double newlines.
	//TODO: And make it support further automatic newlines (eg. 3, 4, 5, etc). Not
	//really a priority due to the fact that the current system works good enough
	//(when are you going to need more than two doublelines consistently?).
	int newline_mode;
	//What has been recorded so far (used in begl(), endl(), and record()).
	string buffer;
	//This is used to work around all those empty lines output into the log at the
	//end of an encounter's round.
	bool logged_since_last_message;
public:
	Log();
	~Log() { if (initialized) LCSCloseFileCPP(file); }
	/*
	Initializes a new logger.
	parameters:
	- _filename
	- A string. Stores the name/relevant path of the file it's going to be logging to.
	- overwrite_existing
	- A boolean value.
	- true = overwrite existing file.
	- false = append to it.
	- newline_mode
	- An integer value.
	- 0 = no automatic newline. Leaves it up to the caller to properly format the output.
	- 1 = newline
	- 2 = double newline
	*/
	bool initialize(const string& _filename, bool overwrite_existing, int _newline_mode = NEWLINEMODE_LOGFILES_DEFAULT);
	/*
	The following three functions, begl(), endl(), and record(), are specifically
	for the gamelog, not general purpose logging.
	*/
	/*//Tells the print function to route input to this.
	void begl();
	//Stops routing input from the print function.
	void endl();
	//Used in conjuction with the above two.
	//When the print function is called, if begl() has been called, the print function
	//calls this function and passes the text it's supposed to be printing to here
	//so that we can log it.
	void record(string text);*/
	//Adds the text given to the buffer.
	template<typename T> void record(const T& text)
	{
		buffer += text; //Save the text. That's it.
		logged_since_last_message = true; //Ya...something was just logged...
	}
	//Writes out everything currently in the buffer to the file, so as to split the
	//log into logical blocks.
	void nextMessage();
	/*
	Adds the provided text to the file. Logs it, yup.
	parameters:
	- text
	- A string. It's the text that the function is supposed to output.
	Notes:
	- The function automatically appends a newline to the end of the output, if
	not already present, if auto_newline == true.
	Use the record() function in conjunction with the nextMessage() function to log messages.
	Use this function if you want to log something that should not also be displayed ingame.
	*/
	bool log(const string& text);
	//Sets the newline mode.
	//Values work the same as with the initialize function for the newline_mode
	//parameter.
	void newlmode(const int new_newline_mode) { newline_mode = new_newline_mode; }
	//Writes out a newline.
	void newline();
	// read-only access to private member variable logged_since_last_message
	bool hasMessage() { return logged_since_last_message; }
};