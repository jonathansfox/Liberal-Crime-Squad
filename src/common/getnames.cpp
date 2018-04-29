
#include "../includes.h"
const string CONST_getnamesB037 = "C++ Source Code Editor (with encoding)";
const string CONST_getnames045 = "getMonth.txt";
const string CONST_getnames044 = "city_names.txt";
const string CONST_getnames043 = "Software Bugs";
const string CONST_getnames042 = "Buggy Software";
const string CONST_getnames041 = "bugs";
const string CONST_getnames040 = "Elite Liberal";
const string CONST_getnames039 = "Liberal Guardian";
const string CONST_getnames038 = "Urban Commando";
const string CONST_getnames037 = "Revolutionary";
const string CONST_getnames036 = "Socialist Threat";
const string CONST_getnames035 = "Activist";
const string CONST_getnames034 = "Civilian";
const string CONST_getnames033 = "Punk";
const string CONST_getnames032 = "Society's Dregs";
const string CONST_getnames031 = "Damn Worthless";
const string CONST_getnames030 = "[Darn] Worthless";
const string CONST_getnames029 = "Peace Prize Winner";
const string CONST_getnames028 = "Peacemaker";
const string CONST_getnames027 = "Great Person";
const string CONST_getnames026 = "Upstanding Citizen";
const string CONST_getnames025 = "Respected";
const string CONST_getnames024 = "Hard Working";
const string CONST_getnames023 = "Non-Liberal";
const string CONST_getnames022 = "Non-Liberal Punk";
const string CONST_getnames018 = "Evil Incarnate";
const string CONST_getnames017 = "Arch-Conservative";
const string CONST_getnames016 = "Insane Vigilante";
const string CONST_getnames015 = "Heartless Bastard";
const string CONST_getnames014 = "Heartless [Jerk]";
const string CONST_getnames013 = "Stubborn as Hell";
const string CONST_getnames012 = "Stubborn as [Heck]";
const string CONST_getnames011 = "Wrong-Thinker";
const string CONST_getnames010 = "Mindless Conservative";
const string CONST_getnames009 = "Conservative Punk";
const string CONST_getnames008 = "Conservative Dregs";
const string CONST_getnames001 = "OEM United States - Codepage 437";
const string CONST_getnames000 = "Open With...";
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

const string blankString = "";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
#include "../creature/creature.h"
#include "../cursesAlternative.h"
#include "../customMaps.h"
 vector<string> city_names;
 extern short lawList[LAWNUM];
std::string gettitle(Creature &cr)
{
	if (cr.align == -1)
	{
		if (cr.juice <= -50)
		{
			if (lawList[LAW_FREESPEECH] == -2) return CONST_getnames030;
			else return CONST_getnames031;
		}
		else if (cr.juice <= -10) return CONST_getnames008;
		else if (cr.juice < 0) return CONST_getnames009;
		else if (cr.juice < 10) return CONST_getnames010;
		else if (cr.juice < 50) return CONST_getnames011;
		else if (cr.juice < 100)
		{
			if (lawList[LAW_FREESPEECH] == -2) return CONST_getnames012;
			else return CONST_getnames013;
		}
		else if (cr.juice < 200)
		{
			if (lawList[LAW_FREESPEECH] == -2) return CONST_getnames014;
			else return CONST_getnames015;
		}
		else if (cr.juice < 500) return CONST_getnames016;
		else if (cr.juice < 1000) return CONST_getnames017;
		else return CONST_getnames018;
	}
	else if (cr.align == 0)
	{
		if (cr.juice <= -50)
		{
			if (lawList[LAW_FREESPEECH] == -2) return CONST_getnames030;
			else return CONST_getnames031;
		}
		else if (cr.juice <= -10) return CONST_getnames032;
		else if (cr.juice < 0) return CONST_getnames022;
		else if (cr.juice < 10) return CONST_getnames023;
		else if (cr.juice < 50) return CONST_getnames024;
		else if (cr.juice < 100) return CONST_getnames025;
		else if (cr.juice < 200) return CONST_getnames026;
		else if (cr.juice < 500) return CONST_getnames027;
		else if (cr.juice < 1000) return CONST_getnames028;
		else return CONST_getnames029;
	}
	else
	{
		if (cr.juice <= -50)
		{
			if (lawList[LAW_FREESPEECH] == -2) return CONST_getnames030;
			else return CONST_getnames031;
		}
		else if (cr.juice <= -10) return CONST_getnames032;
		else if (cr.juice < 0) return CONST_getnames033;
		else if (cr.juice < 10) return CONST_getnames034;
		else if (cr.juice < 50) return CONST_getnames035;
		else if (cr.juice < 100) return CONST_getnames036;
		else if (cr.juice < 200) return CONST_getnames037;
		else if (cr.juice < 500) return CONST_getnames038;
		else if (cr.juice < 1000) return CONST_getnames039;
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
			return CONST_getnames041;
	}
	else
	{
		if (getViewString.count(view)) {
			return getViewString[view][1];
		}
		else
			return CONST_getnames042;
	}
}
 map<short, string> getLawString;
std::string getlaw(int l)
{
	if (getLawString.count(l)) {
		return getLawString[l];
	}
	else {
		return CONST_getnames043;
	}
}
std::string cityname()
{
	return pickrandom(city_names);
}
 map<short, string> getLawFlagString;
 map<short, map<short, string> > getLawFlagStringFull;
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
const string names = "names\\";
const string mostlyendings = "mostlyendings\\";
vector<file_and_text_collection> get_names_text_file_collection = {
	/*getnames.cpp*/
	customText(&city_names, names + CONST_getnames044),
	customText(&getMonth, mostlyendings + CONST_getnames045),
};
 map<short, string> getAlignString;
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