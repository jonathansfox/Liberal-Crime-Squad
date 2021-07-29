




/*
	File created by Chris Johnson.
	These were previously all in game.cpp.

	This file includes all the the enums, defines, and included headers required globally by all components.

	All code released under GNU GPL.
*/
#include <windows.h>
#include <vector>
#include <map>
#include <deque>
#include "cmarkup/Markup.h"
using namespace std;


/* Determine size of vectors and any other container that implements the size() function.
This basically includes all types of containers except for the C++11 std::forward_list. */
template <class Container> inline long len(const Container& x)
{
	return x.size();
}
/* Determine array size in pickrandom() and various functions throughout the code.
Only works on actual arrays, not on vectors or other containers. */
template <typename T, size_t N> inline long len(const T(&x)[N])
{
	return N;
}
/* Override of the prior function for null-terminated C-strings as char arrays.
This override allows pickrandom() to pick a random character from a C-string we have as a char array. */
template <size_t N> inline long len(const char(&x)[N])
{
	return strlen(x);
}
/* Override of the prior function for null-terminated C-strings as char pointers.
This override allows pickrandom() to pick a random character from a C-string we have as a char pointer. */
inline long len(const char* x)
{
	return strlen(x);
}
/* Override for when it doesn't work with const in front of the char*
(compilers are weird about template function overrides) */
inline long len(char* x)
{
	return strlen(x);
}
/* Pick a random element from a vector/deque/map/std::string/C++11 std::array/etc. (e.g. a random string from a vector of strings).
It works on any container class that implements the [] operator, size() function, and value_type typename.
This doesn't work if the vector/deque/map/std::string/C++11 std::array/etc. has zero elements. */
template <class Container> inline typename Container::value_type& pickrandom(const Container& x)
{
	return const_cast<typename Container::value_type&>(x[LCSrandom(len(x))]);
}
/* Pick a random element from an array (e.g. a random string from an array of strings).
This doesn't work if the array has zero elements. */
template <typename T, size_t N> inline T& pickrandom(const T(&x)[N])
{
	return const_cast<T&>(x[LCSrandom(len(x))]);
}

enum LCSIO_FLAGS
{
	LCSIO_PRE_ART = 1, /// Append the given file name to the art directory path.
	LCSIO_PRE_HOME = 2 /// Append the given file name to the home directory path.
};
#include <iostream>
FILE* LCSOpenFile(const char* filename, const char* mode, int flags);
bool LCSOpenFileCPP(std::string filename, std::ios_base::openmode mode, int flags, std::fstream &file);
void LCSCloseFile(FILE* handle);
void LCSCloseFileCPP(std::fstream &file);
void LCSDeleteFile(const char* filename, int flags);
void LCSRenameFile(const char* old_filename, const char* new_filename, int flags);
//returns a list of all files in homedir with extension .dat
vector<string> LCSSaveFiles();

void pause_ms(int t);
void alarmset(int t);
void alarmwait();
//#define CH_USE_CP437



class Log;



const int SLOGAN_LEN = 80;

const int SCORENUM = 5;

enum EndTypes
{
	END_BUT_NOT_END = -2,
	END_OTHER = -1,
	END_WON,
	END_HICKS,
	END_CIA,
	END_POLICE,
	END_CORP,
	END_REAGAN,
	END_DEAD,
	END_PRISON,
	END_EXECUTED,
	END_DATING,
	END_HIDING,
	END_DISBANDLOSS,
	END_DISPERSED,
	END_CCS,
	END_FIREMEN,
	END_STALIN,
	ENDNUM
};



//#ifdef	HIGHSCORE_CPP
// highscore.cpp

#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../title/titlescreen.h"
#include "../common/getnames.h"
// for getmonth
#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include "../common/musicClass.h"

extern class Ledger ledger;
extern int month;
extern int stat_burns;
extern int stat_buys;
extern int stat_dead;
extern int stat_kidnappings;
extern int stat_kills;
extern int stat_recruits;
extern int ustat_burns;
extern int ustat_buys;
extern int ustat_dead;
extern int ustat_funds;
extern int ustat_kidnappings;
extern int ustat_kills;
extern int ustat_recruits;
extern int ustat_spent;
extern int year;
extern int yourscore;
extern MusicClass music;
extern string slogan_str;


MusicModes getEndingMusic(EndTypes e);
string getEndingString(EndTypes e);
struct  saveLoadChunk {
	void * Buffer;
	size_t      ElementSize;
	size_t      ElementCount;
	saveLoadChunk(void * _Buffer, int _ElementSize, int _ElementCount) :Buffer(_Buffer), ElementSize(_ElementSize), ElementCount(_ElementCount) {}
};

struct highscorest
{
	char valid, endtype, slogan[SLOGAN_LEN];
	int month, year, stat_recruits, stat_kidnappings, stat_dead, stat_kills, stat_funds, stat_spent, stat_buys, stat_burns;
};
highscorest score[SCORENUM];

vector<saveLoadChunk> highScoreSaveLoad = {
	saveLoadChunk(&ustat_recruits, sizeof(int), 1),
	saveLoadChunk(&ustat_dead, sizeof(int), 1),
	saveLoadChunk(&ustat_kills, sizeof(int), 1),
	saveLoadChunk(&ustat_kidnappings, sizeof(int), 1),
	saveLoadChunk(&ustat_funds, sizeof(int), 1),
	saveLoadChunk(&ustat_spent, sizeof(int), 1),
	saveLoadChunk(&ustat_buys, sizeof(int), 1),
	saveLoadChunk(&ustat_burns, sizeof(int), 1),
	saveLoadChunk(score, sizeof(highscorest), SCORENUM)
};
//#endif//HIGHSCORE_CPP
//#endif// INCLUDES_H_INCLUDED
