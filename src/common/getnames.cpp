/*
Copyright (c) 2002,2003,2004 by Tarn Adams                                            //
//
This file is part of Liberal Crime Squad.                                             //
//
Liberal Crime Squad is free software; you can redistribute it and/or modify     //
it under the terms of the GNU General Public License as published by            //
the Free Software Foundation; either version 2 of the License, or               //
(at your option) any later version.                                             //
//
Liberal Crime Squad is distributed in the hope that it will be useful,          //
but WITHOUT ANY WARRANTY; without even the implied warranty of                  //
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.   See the                  //
GNU General Public License for more details.                                    //
//
You should have received a copy of the GNU General Public License               //
along with Liberal Crime Squad; if not, write to the Free Software              //
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA   02111-1307   USA     //
*/
/*
This file was created by Chris Johnson (grundee@users.sourceforge.net)
by copying code from game.cpp.
To see descriptions of files and functions, see the list at
the bottom of includes.h in the top src folder.
*/
// Note: this file is encoded in the PC-8 / Code Page 437 / OEM-US character set
// (The same character set used by Liberal Crime Squad when it is running)
// Certain special characters won't display correctly unless your text editor is
// set to use that character set, such as this e with an accent: ‚
// In Windows Notepad with the Terminal font, OEM/DOS encoding it should work fine.
// You can set this in Notepad by going to Format->Font and choosing the Terminal font,
// then choosing OEM/DOS in the Script dropdown box.
// In Notepad++ go to the Encoding menu, Character sets, Western European, OEM-US... easy!
// In Code::Blocks's editor go to Settings->Editor->the Other Settings tab and
// then pick WINDOWS-437 from the dropdown box and then choose the radio button
// to make this the default encoding and disable auto-detection of the encoding.
// Then close the file and reopen it (since Code::Blocks detects the encoding
// when it opens the file and it can't be changed after that; what we changed was
// how it detects encoding for files it opens in the future, not files already open).
// In Microsoft Visual C++, right-click the file in the Solution Explorer,
// select "Open With...", choose "C++ Source Code Editor (with encoding)",
// then choose "OEM United States - Codepage 437".
// In MS-DOS Editor (included with Windows as EDIT.COM in your system32 directory),
// the codepage will be correct already since it's running in a console window just
// like Liberal Crime Squad. Well OK, the encoding might be wrong, but then it's wrong
// in Liberal Crime Squad TOO, and to fix it, go to Control Panel, Regional and Language Settings,
// Advanced tab, and choose English (United States) from the dropdown box as the encoding
// for non-Unicode applications, then press OK.
// If you have a Linux or other UNIX-based system you are obviously smart enough
// to figure out for yourself how to open a file in OEM-US PC-8 codepage 437 in
// your favorite text editor. If you're on Mac OS X, well that's UNIX-based, figure
// it out for yourself.

#include <includes.h>
#include "creature/creature.h"
//#include "pdcurses/curses.h"

#include "common/getnames.h"
std::string gettitle(Creature &cr);
//own header



#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
 vector<string> city_names;

 extern short lawList[LAWNUM];
std::string gettitle(Creature &cr)
{
	if (cr.align == -1)
	{
		if (cr.juice <= -50)
		{
			if (lawList[LAW_FREESPEECH] == -2) return "[Darn] Worthless";
			else return "Damn Worthless";
		}
		else if (cr.juice <= -10) return "Conservative Dregs";
		else if (cr.juice < 0) return "Conservative Punk";
		else if (cr.juice < 10) return "Mindless Conservative";
		else if (cr.juice < 50) return "Wrong-Thinker";
		else if (cr.juice < 100)
		{
			if (lawList[LAW_FREESPEECH] == -2) return "Stubborn as [Heck]";
			else return "Stubborn as Hell";
		}
		else if (cr.juice < 200)
		{
			if (lawList[LAW_FREESPEECH] == -2) return "Heartless [Jerk]";
			else return "Heartless Bastard";
		}
		else if (cr.juice < 500) return "Insane Vigilante";
		else if (cr.juice < 1000) return "Arch-Conservative";
		else return "Evil Incarnate";
	}
	else if (cr.align == 0)
	{
		if (cr.juice <= -50)
		{
			if (lawList[LAW_FREESPEECH] == -2) return "[Darn] Worthless";
			else return "Damn Worthless";
		}
		else if (cr.juice <= -10) return "Society's Dregs";
		else if (cr.juice < 0) return "Non-Liberal Punk";
		else if (cr.juice < 10) return "Non-Liberal";
		else if (cr.juice < 50) return "Hard Working";
		else if (cr.juice < 100) return "Respected";
		else if (cr.juice < 200) return "Upstanding Citizen";
		else if (cr.juice < 500) return "Great Person";
		else if (cr.juice < 1000) return "Peacemaker";
		else return "Peace Prize Winner";
	}
	else
	{
		if (cr.juice <= -50)
		{
			if (lawList[LAW_FREESPEECH] == -2) return "[Darn] Worthless";
			else return "Damn Worthless";
		}
		else if (cr.juice <= -10) return "Society's Dregs";
		else if (cr.juice < 0) return "Punk";
		else if (cr.juice < 10) return "Civilian";
		else if (cr.juice < 50) return "Activist";
		else if (cr.juice < 100) return "Socialist Threat";
		else if (cr.juice < 200) return "Revolutionary";
		else if (cr.juice < 500) return "Urban Commando";
		else if (cr.juice < 1000) return "Liberal Guardian";
		else return "Elite Liberal";
	}
}
typedef map<short, vector<string>> shortAndTwoStrings;
 shortAndTwoStrings getViewString;
std::string getview(short view, bool shortname)
{
	if (shortname)
	{
		if (getViewString.count(view)) {
			return getViewString[view][0];
		}
		else
			return "bugs";
	}
	else
	{
		if (getViewString.count(view)) {
			return getViewString[view][1];
		}
		else
			return "Buggy Software";
	}
}
typedef map<short, string > shortAndString;
 shortAndString getLawString;
std::string getlaw(int l)
{
	if (getLawString.count(l)) {
		return getLawString[l];
	}
	else {
		return "Software Bugs";
	}
}
std::string cityname()
{
	return pickrandom(city_names);
}
 shortAndString getLawFlagString;
typedef map<short, shortAndString > shortAndShortAndString;
 shortAndShortAndString getLawFlagStringFull;
int getLawFromFlag(int type);
 string findingBugs;
std::string getlawflag(int type)
{
	if (getLawFlagStringFull.count(type)) {
		return getLawFlagStringFull[type][lawList[getLawFromFlag(type)]];
	}
	else
		if (getLawFlagString.count(type)) {
			return getLawFlagString[type];
		}
		else {
			return findingBugs;
		}
}
// shortname defaults to false
 vector<string> getMonth;
std::string getmonth(int month, bool shortname)
{
	int monthIndex = (month - 1) * 2 + (shortname ? 0 : 1);
	if (monthIndex < len(getMonth)) {
		return getMonth[monthIndex];
	}
	else {
		return getMonth[22 + (shortname ? 0 : 1)];
	}
}
 shortAndString getAlignString;
 string moderateLC;
 string buggyString;
std::string getalign(short alignment, bool capitalize)
{
	if (capitalize == false && alignment == ALIGN_MODERATE) {
		return moderateLC;
	}
	else if (getAlignString.count(alignment) > 0) {
		return getAlignString[alignment];
	}
	else {
		return buggyString;
	}
}
/* Allow the player to enter a name with an optional default */
void enter_name(int y, int x, char *name, int len, const char* defname)
{
	refreshAlt();
	keypadAlt(FALSE);
	raw_outputAlt(FALSE);
	echoAlt();
	curs_setAlt(1);
	mvgetnstrAlt(y, x, name, len - 1); //-1 because 'len' is normally the full space available and we need one for a terminator.
	curs_setAlt(0);
	noechoAlt();
	raw_outputAlt(TRUE);
	keypadAlt(TRUE);
	if ((defname != NULL) && (strncmp(name, "", len - 1) == 0)) strncpy(name, defname, len - 1);
	name[len - 1] = '\0';
}