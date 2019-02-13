
#define	GETNAMES_CPP
#include "../includes.h"
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
// set to use that character set, such as this e with an accent: é
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
// select CONST_getnames000, choose CONST_getnamesB037,
// then choose CONST_getnames001.
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

vector<string> city_names;
std::string gettitle(const int align, const int juice)
{
	if (align == -1)
	{
		if (juice <= -50)
		{
			if (lawList[LAW_FREESPEECH] == -2) return CONST_DARN_WORTHLESS;
			else return CONST_DAMN_WORTHLESS;
		}
		else if (juice <= -10) return CONST_CONSERVATIVE_DREGS;
		else if (juice < 0) return CONST_CONSERVATIVE_PUNK;
		else if (juice < 10) return CONST_MINDLESS_CONSERVATIVE;
		else if (juice < 50) return CONST_WRONG_THINKER;
		else if (juice < 100)
		{
			if (lawList[LAW_FREESPEECH] == -2) return CONST_STUBBORN_AS_HECK;
			else return CONST_STUBBORN_AS_HELL;
		}
		else if (juice < 200)
		{
			if (lawList[LAW_FREESPEECH] == -2) return CONST_HEARTLESS_JERK;
			else return CONST_HEARTLESS_BASTARD;
		}
		else if (juice < 500) return CONST_INSANE_VIGILANTE;
		else if (juice < 1000) return CONST_getnames017;
		else return CONST_EVIL_INCARNATE;
	}
	else if (align == 0)
	{
		if (juice <= -50)
		{
			if (lawList[LAW_FREESPEECH] == -2) return CONST_DARN_WORTHLESS;
			else return CONST_DAMN_WORTHLESS;
		}
		else if (juice <= -10) return CONST_SOCIETY_S_DREGS;
		else if (juice < 0) return CONST_NON_LIBERAL_PUNK;
		else if (juice < 10) return CONST_NON_LIBERAL;
		else if (juice < 50) return CONST_HARD_WORKING;
		else if (juice < 100) return CONST_RESPECTED;
		else if (juice < 200) return CONST_UPSTANDING_CITIZEN;
		else if (juice < 500) return CONST_GREAT_PERSON;
		else if (juice < 1000) return CONST_PEACEMAKER;
		else return CONST_PEACE_PRIZE_WINNER;
	}
	else
	{
		if (juice <= -50)
		{
			if (lawList[LAW_FREESPEECH] == -2) return CONST_DARN_WORTHLESS;
			else return CONST_DAMN_WORTHLESS;
		}
		else if (juice <= -10) return CONST_SOCIETY_S_DREGS;
		else if (juice < 0) return CONST_PUNK;
		else if (juice < 10) return CONST_CIVILIAN;
		else if (juice < 50) return CONST_ACTIVIST;
		else if (juice < 100) return CONST_SOCIALIST_THREAT;
		else if (juice < 200) return CONST_REVOLUTIONARY;
		else if (juice < 500) return CONST_URBAN_COMMANDO;
		else if (juice < 1000) return CONST_LIBERAL_GUARDIAN;
		else return CONST_getnames040;
	}
}

map<short, vector<string> > getViewString;
std::string getview(short view, bool shortname)
{
	if (shortname)
	{
		if (getViewString.count(view)) {
			return getViewString[view][0];
		}
		else
			return CONST_BUGS;
	}
	else
	{
		if (getViewString.count(view)) {
			return getViewString[view][1];
		}
		else
			return CONST_BUGGY_SOFTWARE;
	}
}
map<short, string> getLawString;

map<short, string> getLawFlagString;
map<short, map<short, string> > getLawFlagStringFull;
//string findingBugs;

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
vector<file_and_text_collection> get_names_text_file_collection = {
	/*getnames.cpp*/
	customText(&city_names, names + CONST_CITY_NAMES_TXT),
	customText(&getMonth, MOSTLY_ENDINGS_FOLDER + CONST_GETMONTH_TXT),
};
map<short, string> getAlignString;
//string moderateLC;
//string BUGGY_STRING;
std::string getalign(short alignment, bool capitalize)
{
	if (capitalize == false && alignment == ALIGN_MODERATE) {
		return moderateLC;
	}
	else if (getAlignString.count(alignment) > 0) {
		return getAlignString[alignment];
	}
	else {
		return BUGGY_STRING;
	}
}