
#include "../includes.h"
const string CONST_commondisplay000 = ",";
const string CONST_commondisplay202 = " (";
const string CONST_commondisplay201 = "Name: ";
const string CONST_commondisplay200 = "Code name: ";
const string CONST_commondisplay212 = ": ";
const string CONST_commondisplay199 = ".00";
const string CONST_commondisplay198 = "99+";
const string CONST_commondisplay197 = "00";
const string CONST_commondisplay196 = ".";
const string CONST_commondisplay194 = "NOW   MAX";
const string CONST_commondisplay193 = "SKILL";
const string CONST_commondisplay003 = "On \"Foot\"";
const string CONST_commondisplay158 = "On Foot";
const string CONST_commondisplay157 = "Wheelchair";
const string CONST_commondisplay156 = "-D";
const string CONST_commondisplay220 = "                                                                                ";
const string CONST_commondisplay153 = "Weapon: ";
const string CONST_commondisplay119 = "Cut";
const string CONST_commondisplay118 = "Bruised";
const string CONST_commondisplay117 = "Shot";
const string CONST_commondisplay116 = "Liberal";
const string CONST_commondisplay115 = "Animal";
const string CONST_commondisplay114 = "Severed";
const string CONST_commondisplay113 = "Ripped off";
const string CONST_commondisplay112 = "Left Leg:";
const string CONST_commondisplay111 = "Right Leg:";
const string CONST_commondisplay110 = "Left Arm:";
const string CONST_commondisplay109 = "Right Arm:";
const string CONST_commondisplay108 = "Body:";
const string CONST_commondisplay107 = "Head:";
const string CONST_commondisplay154 = "Clothes: ";
const string CONST_commondisplay180 = "Missing Teeth";
const string CONST_commondisplay178 = "No Teeth";
const string CONST_commondisplay177 = "No Tongue";



const string tag_0 = "0";
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
// select CONST_commondisplay001, choose CONST_commondisplayB178,
// then choose CONST_commondisplay002.
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
#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locationsEnums.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../sitemode/stealth.h"
#include "../common/getnames.h"
std::string gettitle(const int align, const int juice);
bool isThereNoActivesquad();
// for getmonth
#include "../common/translateid.h"
// for  int getcar(int)
#include "../common/commonactionsCreature.h"
// for void sortliberals(std::vector<Creature *>&,short,bool)
#include "../daily/siege.h"
// for statebrokenlaws(cr);
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
extern string commaSpace;
extern string singleSpace;
extern string closeParenthesis;

bool isThereASiteAlarm();
void makedelimiter(int y = 8, int x = 0);

map<int, map<bool, ColorSetup> > alignmentColors = {
	// Liberal activism
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_ARCHCONSERVATIVE,{ map<bool, ColorSetup>::value_type(true, RED_ON_BLACK_BRIGHT) }),
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_CONSERVATIVE,{ map<bool, ColorSetup>::value_type(true, MAGENTA_ON_BLACK_BRIGHT), map<bool, ColorSetup>::value_type(false, RED_ON_BLACK_BRIGHT) }),
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_MODERATE,{ map<bool, ColorSetup>::value_type(true, YELLOW_ON_BLACK_BRIGHT) }),
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_LIBERAL,{ map<bool, ColorSetup>::value_type(true, CYAN_ON_BLACK_BRIGHT), map<bool, ColorSetup>::value_type(false, GREEN_ON_BLACK_BRIGHT) }),
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_ELITELIBERAL,{ map<bool, ColorSetup>::value_type(true, GREEN_ON_BLACK_BRIGHT) }),
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_STALINIST,{ map<bool, ColorSetup>::value_type(true, RED_ON_BLACK_BRIGHT) }),
};
// Sets the text color to the thematic color for the given alignment
// extended_range forces colors to be set on a 5 point scale instead
// of just basic liberal-moderate-conservative
void set_alignment_color(short alignment, bool extended_range)
{
	if (alignmentColors.count(alignment)) {
		if (alignmentColors[alignment].count(extended_range)) {
			set_color_easy(alignmentColors[alignment][extended_range]);
		}
		else {
			set_color_easy(alignmentColors[alignment][true]);
		}
	}
	else {
		// This should not happen! Set a strange color to indicate an error!
		set_color_easy(YELLOW_ON_RED_BRIGHT_BLINK);
	}
}
map<int, ColorSetup> activityColors = {
	// Liberal activism
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_LIBERAL, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_TROUBLE, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_GRAFFITI, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_DOS_ATTACKS, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_HACKING, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_WRITE_LETTERS, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_WRITE_GUARDIAN, GREEN_ON_BLACK_BRIGHT),
	// Recruitment
	map<int, ColorSetup>::value_type(ACTIVITY_RECRUITING, GREEN_ON_BLACK),
	// Less exciting liberal activities
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_SPY, BLUE_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_COMMUNITYSERVICE, BLUE_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_POLLS, BLUE_ON_BLACK_BRIGHT),
	// Stealing things
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_STEAL, CYAN_ON_BLACK),
	map<int, ColorSetup>::value_type(ACTIVITY_WHEELCHAIR, CYAN_ON_BLACK),
	map<int, ColorSetup>::value_type(ACTIVITY_STEALCARS, CYAN_ON_BLACK),
	// Illegal fundraising
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_EMBEZZLE, RED_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_SELL_DRUGS, RED_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_PROSTITUTION, RED_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_CCFRAUD, RED_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_DOS_RACKET, RED_ON_BLACK_BRIGHT),
	// Legal fundraising
	map<int, ColorSetup>::value_type(ACTIVITY_DONATIONS, CYAN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_SELL_TSHIRTS, CYAN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_SELL_ART, CYAN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_SELL_MUSIC, CYAN_ON_BLACK_BRIGHT),
	// Clothing/garment stuff
	map<int, ColorSetup>::value_type(ACTIVITY_REPAIR_ARMOR, CYAN_ON_BLACK),
	map<int, ColorSetup>::value_type(ACTIVITY_MAKE_ARMOR, CYAN_ON_BLACK),
	// Teaching
	map<int, ColorSetup>::value_type(ACTIVITY_TEACH_POLITICS, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_TEACH_FIGHTING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_TEACH_COVERT, MAGENTA_ON_BLACK_BRIGHT),
	//and studying
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_DEBATING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_MARTIAL_ARTS, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_DRIVING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_PSYCHOLOGY, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_FIRST_AID, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_LAW, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_DISGUISE, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_SCIENCE, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_BUSINESS, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_GYMNASTICS, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_ART, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_MUSIC, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_TEACHING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_WRITING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_LOCKSMITHING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_COMPUTERS, MAGENTA_ON_BLACK_BRIGHT),
	//map<int, ColorSetup>::value_type(ACTIVITY_STUDY_COOKING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_FENCING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_WEAVING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_RELIGION, MAGENTA_ON_BLACK_BRIGHT),
	//map<int, ColorSetup>::value_type(ACTIVITY_STUDY_MAGIC, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_CLUB, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_STREETSENSE, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_THROWING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_STEALTH, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_SEDUCTION, MAGENTA_ON_BLACK_BRIGHT),
	// Interrogating
	map<int, ColorSetup>::value_type(ACTIVITY_HOSTAGETENDING, YELLOW_ON_BLACK_BRIGHT),
	// Dealing with your injuries
	map<int, ColorSetup>::value_type(ACTIVITY_CLINIC, RED_ON_BLACK),
	// Doing something Conservative
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_CONSERVATIVE, RED_ON_BLACK_BRIGHT),
	// Dealing with the dead
	map<int, ColorSetup>::value_type(ACTIVITY_BURY, BLACK_ON_BLACK_BRIGHT),
	// Nothing terribly important
	map<int, ColorSetup>::value_type(ACTIVITY_HEAL, WHITE_ON_BLACK),// Identical to none in practice
	map<int, ColorSetup>::value_type(ACTIVITY_NONE, WHITE_ON_BLACK),
	// Going somewhere
	map<int, ColorSetup>::value_type(ACTIVITY_VISIT, YELLOW_ON_BLACK_BRIGHT),
	// Quitting being a sleeper to join the LCS
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_JOINLCS, RED_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_AUGMENT, BLUE_ON_BLACK_BRIGHT),
};
// Sets the text color per activity type
void set_activity_color(long activity_type)
{
	if (activityColors.count(activity_type)) {
		set_color_easy(activityColors[activity_type]);
	}
	else {
		// This should not happen! Set a strange color to indicate an error!
		set_color_easy(YELLOW_ON_RED_BRIGHT);

	}
}
/* draws a horizontal line across the screen */
//void makedelimiter(int y = 8, int x = 0);
/* draws a horizontal line across the screen */
void makedelimiter(int y, int x)
{
	const string CONST_commondisplay005 = "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ";
	const string CONST_commondisplay004 = "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂ";
	extern short mode;
	extern bool mapshowing;
	set_color_easy(WHITE_ON_BLACK);
	if (mode == GAMEMODE_SITE && y == 8 && x == 0 && mapshowing) // special case: there is a map on the right in site mode
		mvaddstrAlt(y, x, CONST_commondisplay004); // 80 characters
	else // normal delimiter
		mvaddstrAlt(y, x, CONST_commondisplay005); // 80 characters
}
string perfectlyHealthy(const int align, const int animalgloss, const char smll) {

	const string CONST_commondisplay044 = "Moderate";
	const string CONST_commondisplay043 = "Conservative";
	const string CONST_commondisplay042 = "Consrvtv";

	if (align == -1)
	{
		set_color_easy(RED_ON_BLACK_BRIGHT);
		if (smll)return (CONST_commondisplay042);
		else return (CONST_commondisplay043);
	}
	else if (align == 0)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		return (CONST_commondisplay044);
	}
	else
	{
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		if (animalgloss == ANIMALGLOSS_ANIMAL)
			return (CONST_commondisplay115);
		else return (CONST_commondisplay116);
	}
}
string bleedingOut(const int alive, const int blood, const char smll) {

	const string CONST_commondisplay013 = "Lightly Wounded";
	const string CONST_commondisplay012 = "LtWound";
	const string CONST_commondisplay011 = "Wounded";
	const string CONST_commondisplay010 = "Badly Wounded";
	const string CONST_commondisplay009 = "BadWound";
	const string CONST_commondisplay008 = "Near Death";
	const string CONST_commondisplay007 = "NearDETH";
	const string CONST_commondisplay006 = "Deceased";

	if (!alive)
	{
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		return (CONST_commondisplay006);
	}
	else if (blood <= 20)
	{
		if (smll)return (CONST_commondisplay007);
		else return (CONST_commondisplay008);
	}
	else if (blood <= 50)
	{
		if (smll)return (CONST_commondisplay009);
		else return (CONST_commondisplay010);
	}
	else if (blood <= 75)
	{
		return (CONST_commondisplay011);
	}
	else// if (blood < 100)
	{
		if (smll)return (CONST_commondisplay012);
		else return (CONST_commondisplay013);
	}
}
string missingArmAndOrLeg(const int armok, const int legok, const char smll, const bool bleeding) {
	const string CONST_commondisplay029 = "One Leg";
	const string CONST_commondisplay028 = "One Arm";
	const string CONST_commondisplay027 = "One Arm, One Leg";
	const string CONST_commondisplay026 = "1Arm1Leg";
	const string CONST_commondisplay025 = "No Legs";
	const string CONST_commondisplay024 = "No Arms";
	const string CONST_commondisplay023 = "One Limb";
	const string CONST_commondisplay022 = "No Limbs";

	if (legok == 0 && armok == 0)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		return (CONST_commondisplay022);
	}
	else if ((legok == 1 && armok == 0) || (armok == 1 && legok == 0))
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		return (CONST_commondisplay023);
	}
	else if (legok == 2 && armok == 0)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		return (CONST_commondisplay024);
	}
	else if (legok == 0 && armok == 2)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		return (CONST_commondisplay025);
	}
	else if (legok == 1 && armok == 1)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		if (smll)return (CONST_commondisplay026);
		else return (CONST_commondisplay027);
	}
	else if (armok == 1)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		return (CONST_commondisplay028);
	}
	else// if (legok == 1)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		return (CONST_commondisplay029);
	}
}
string missingPartOfFace(const char lefteye, const char righteye, const char nose, const bool bleeding, const char smll) {
	const string CONST_commondisplay036 = "Missing Eye";
	const string CONST_commondisplay035 = "One Eye";
	const string CONST_commondisplay034 = "Missing Nose";
	const string CONST_commondisplay033 = "NoseGone";
	const string CONST_commondisplay032 = "Face Mutilated";
	const string CONST_commondisplay031 = "FaceMutl";
	const string CONST_commondisplay030 = "Blind";

	if (righteye == 0 &&
		lefteye == 0)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		return (CONST_commondisplay030);
	}
	else if ((righteye == 0 ||
		lefteye == 0) &&
		nose == 0)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		if (smll)return (CONST_commondisplay031);
		else return (CONST_commondisplay032);
	}
	else if (nose == 0)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		if (smll)return (CONST_commondisplay033);
		else return (CONST_commondisplay034);
	}
	else //if (g.special[SPECIALWOUND_RIGHTEYE] == 0 ||
		 //g.special[SPECIALWOUND_LEFTEYE] == 0)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		if (smll)return (CONST_commondisplay035);
		else return (CONST_commondisplay036);
	}
}
//const string CONST_commondisplay180 = "Missing Teeth";
//const string CONST_commondisplay178 = "No Teeth";
//const string CONST_commondisplay177 = "No Tongue";

const string CONST_commondisplay040 = "MisTeeth";
const string CONST_commondisplay037 = "NoTongue";
const string CONST_commondisplay021 = "Face Gone";
const string CONST_commondisplay020 = "FaceGone";
const string CONST_commondisplay019 = "Paraplegic";
const string CONST_commondisplay018 = "Parapleg";
const string CONST_commondisplay017 = "Quadraplegic";
const string CONST_commondisplay016 = "Quadpleg";
const string CONST_commondisplay015 = "Neck Broken";
const string CONST_commondisplay014 = "NckBroke";
string getHealthStat(CreatureHealth g, const char smll) {

	bool bleeding = false;

	for (int w = 0; w < BODYPARTNUM; w++)
	{
		if (g.wound[w] & WOUND_BLEEDING)bleeding = true;
	}

	int armok = 2, legok = 2;
	if (g.wound[BODYPART_ARM_RIGHT] & (WOUND_NASTYOFF | WOUND_CLEANOFF)) { armok--; }
	if (g.wound[BODYPART_ARM_LEFT] & (WOUND_NASTYOFF | WOUND_CLEANOFF)) { armok--; }
	if (g.wound[BODYPART_LEG_RIGHT] & (WOUND_NASTYOFF | WOUND_CLEANOFF)) { legok--; }
	if (g.wound[BODYPART_LEG_LEFT] & (WOUND_NASTYOFF | WOUND_CLEANOFF)) { legok--; }


	if (bleeding)set_color_easy(RED_ON_BLACK_BRIGHT);
	else set_color_easy(WHITE_ON_BLACK_BRIGHT);

	if (!g.alive || g.blood < 100) {
		return bleedingOut(g.alive, g.blood, smll);
	}
	else if (g.special[SPECIALWOUND_NECK] == 2)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		if (smll)return (CONST_commondisplay014);
		else return (CONST_commondisplay015);
	}
	else if (g.special[SPECIALWOUND_UPPERSPINE] == 2)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		if (smll)return (CONST_commondisplay016);
		else return (CONST_commondisplay017);
	}
	else if (g.special[SPECIALWOUND_LOWERSPINE] == 2)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		if (smll)return (CONST_commondisplay018);
		else return (CONST_commondisplay019);
	}
	else if (g.special[SPECIALWOUND_RIGHTEYE] == 0 &&
		g.special[SPECIALWOUND_LEFTEYE] == 0 &&
		g.special[SPECIALWOUND_NOSE] == 0)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		if (smll)return (CONST_commondisplay020);
		else return (CONST_commondisplay021);
	}
	else if (armok != 2 || legok != 2) {
		return missingArmAndOrLeg(armok, legok, smll, bleeding);
	}
	else if (g.special[SPECIALWOUND_RIGHTEYE] == 0 ||
		g.special[SPECIALWOUND_LEFTEYE] == 0 ||
		g.special[SPECIALWOUND_NOSE] == 0) {
		return missingPartOfFace(g.special[SPECIALWOUND_LEFTEYE], g.special[SPECIALWOUND_RIGHTEYE], g.special[SPECIALWOUND_NOSE], bleeding, smll);
	}
	else if (g.special[SPECIALWOUND_TONGUE] == 0)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		if (smll)return (CONST_commondisplay037);
		else return (CONST_commondisplay177);
	}
	else if (g.special[SPECIALWOUND_TEETH] == 0)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		return (CONST_commondisplay178);
	}
	else if (g.special[SPECIALWOUND_TEETH] < TOOTHNUM)
	{
		if (!bleeding)set_color_easy(GREEN_ON_BLACK);
		if (smll)return (CONST_commondisplay040);
		else return (CONST_commondisplay180);
	}
	else
	{
		return perfectlyHealthy(g.align, g.animalgloss, smll);
	}
}
/* prints a character's health description (One Leg, Liberal, NearDETH...) */
void printhealthstat(CreatureHealth g, int y, int x, char smll)
{
	string wound = getHealthStat(g, smll);
	mvaddstrAlt(y, x, wound);
}
void printAttributesAsKnowledgePermits(CreatureAttributeList cr, unsigned char knowledge) {
	const string CONST_commondisplay067 = "?";
	const string CONST_commondisplay066 = "Char:   ";
	const string CONST_commondisplay064 = "Str:    ";
	const string CONST_commondisplay062 = "Agi:    ";
	const string CONST_commondisplay060 = "Hlth:   ";
	const string CONST_commondisplay058 = "Wis:    ";
	const string CONST_commondisplay056 = "Int:    ";
	const string CONST_commondisplay054 = "Hrt:    ";
	mvaddstrAlt(2, 0, CONST_commondisplay054 + ((knowledge > 0) ? tostring(cr.get_attribute(ATTRIBUTE_HEART, true)) : CONST_commondisplay067));
	mvaddstrAlt(3, 0, CONST_commondisplay056 + ((knowledge > 0) ? tostring(cr.get_attribute(ATTRIBUTE_INTELLIGENCE, true)) : CONST_commondisplay067));
	mvaddstrAlt(4, 0, CONST_commondisplay058 + ((knowledge > 0) ? tostring(cr.get_attribute(ATTRIBUTE_WISDOM, true)) : CONST_commondisplay067));
	mvaddstrAlt(5, 0, CONST_commondisplay060 + ((knowledge > 1) ? tostring(cr.get_attribute(ATTRIBUTE_HEALTH, true)) : CONST_commondisplay067));
	mvaddstrAlt(2, 11, CONST_commondisplay062 + ((knowledge > 1) ? tostring(cr.get_attribute(ATTRIBUTE_AGILITY, true)) : CONST_commondisplay067));
	mvaddstrAlt(3, 11, CONST_commondisplay064 + ((knowledge > 1) ? tostring(cr.get_attribute(ATTRIBUTE_STRENGTH, true)) : CONST_commondisplay067));
	mvaddstrAlt(4, 11, CONST_commondisplay066 + ((knowledge > 0) ? tostring(cr.get_attribute(ATTRIBUTE_CHARISMA, true)) : CONST_commondisplay067));
}
/* checks if a creature's weapon is suspicious or illegal */
char weaponcheck(const DeprecatedCreature &cr, bool metaldetect = false);
/* checks if a creature's uniform is appropriate to the location */
char hasdisguise(const DeprecatedCreature &cr);
//void printcreatureinfo(DeprecatedCreature *cr, unsigned char knowledge = 255);
string getVehicleShortname(int i);
const string CONST_commondisplay053 = "an angry Hangin' Judge";
const string CONST_commondisplay052 = "a frightened Eminent Scientist";
const string CONST_commondisplay051 = "a smarmy News Anchor";
const string CONST_commondisplay050 = "a crying Radio Personality";
const string CONST_commondisplay049 = "a squirming CEO";
const string CONST_commondisplay048 = "a cursing Politician";
map<int, string> prisoner_description = {
	map<int, string>::value_type(CREATURE_POLITICIAN, CONST_commondisplay048),
	map<int, string>::value_type(CREATURE_CORPORATE_CEO, CONST_commondisplay049),
	map<int, string>::value_type(CREATURE_RADIOPERSONALITY, CONST_commondisplay050),
	map<int, string>::value_type(CREATURE_NEWSANCHOR, CONST_commondisplay051),
	map<int, string>::value_type(CREATURE_SCIENTIST_EMINENT, CONST_commondisplay052),
	map<int, string>::value_type(CREATURE_JUDGE_CONSERVATIVE, CONST_commondisplay053),
};
void set_color_for_disguise(DeprecatedCreature* cr) {

	extern short sitealarmtimer;

	switch (hasdisguise(*cr))
	{
	case 1:set_color_easy(GREEN_ON_BLACK_BRIGHT); break;
	case 2:set_color_easy(YELLOW_ON_BLACK_BRIGHT); break;
	default:
		if (cr->get_armor().get_stealth_value() > 1)
			set_color_easy(BLACK_ON_BLACK_BRIGHT);
		else set_color_easy(RED_ON_BLACK_BRIGHT);
	}
	if (sitealarmtimer >= 0 || isThereASiteAlarm())
		if (cr->get_armor().get_stealth_value() > 1)
			set_color_easy(BLACK_ON_BLACK_BRIGHT);

}
void printWounds(DeprecatedCreature *cr) {
	const string CONST_commondisplay092 = "Brn";
	const string CONST_commondisplay091 = "Trn";
	const string CONST_commondisplay089 = "Brs";
	const string CONST_commondisplay088 = "Sht";
	const string CONST_commondisplay085 = "Clean sever";

	for (int w = 0; w < BODYPARTNUM; w++)
	{
		if (cr->getCreatureHealth().wound[w] & WOUND_BLEEDING)set_color_easy(RED_ON_BLACK_BRIGHT);
		else set_color_easy(WHITE_ON_BLACK);
		moveAlt(2 + w, 49);
		switch (w)
		{
		case BODYPART_HEAD:addstrAlt(CONST_commondisplay107); break;
		case BODYPART_BODY:addstrAlt(CONST_commondisplay108); break;
		case BODYPART_ARM_RIGHT:addstrAlt(CONST_commondisplay109); break;
		case BODYPART_ARM_LEFT:addstrAlt(CONST_commondisplay110); break;
		case BODYPART_LEG_RIGHT:addstrAlt(CONST_commondisplay111); break;
		case BODYPART_LEG_LEFT:addstrAlt(CONST_commondisplay112); break;
		}
		moveAlt(2 + w, 61);
		if (cr->getCreatureHealth().wound[w] & WOUND_NASTYOFF)addstrAlt(CONST_commondisplay113);
		else if (cr->getCreatureHealth().wound[w] & WOUND_CLEANOFF)addstrAlt(CONST_commondisplay085);
		else
		{
			int sum = 0;
			if (cr->getCreatureHealth().wound[w] & WOUND_SHOT)sum++;
			if (cr->getCreatureHealth().wound[w] & WOUND_CUT)sum++;
			if (cr->getCreatureHealth().wound[w] & WOUND_BRUISED)sum++;
			if (cr->getCreatureHealth().wound[w] & WOUND_BURNED)sum++;
			if (cr->getCreatureHealth().wound[w] & WOUND_TORN)sum++;
			if (sum == 0)
			{
				set_color_easy(GREEN_ON_BLACK_BRIGHT);
				if (cr->getCreatureHealth().animalgloss == ANIMALGLOSS_ANIMAL)
					addstrAlt(CONST_commondisplay115);
				else addstrAlt(CONST_commondisplay116);
			}
			if (cr->getCreatureHealth().wound[w] & WOUND_SHOT) { addstrAlt(CONST_commondisplay088); sum--; if (sum > 0)addstrAlt(CONST_commondisplay000); }
			if (cr->getCreatureHealth().wound[w] & WOUND_BRUISED) { addstrAlt(CONST_commondisplay089); sum--; if (sum > 0)addstrAlt(CONST_commondisplay000); }
			if (cr->getCreatureHealth().wound[w] & WOUND_CUT) { addstrAlt(CONST_commondisplay119); sum--; if (sum > 0)addstrAlt(CONST_commondisplay000); }
			if (cr->getCreatureHealth().wound[w] & WOUND_TORN) { addstrAlt(CONST_commondisplay091); sum--; if (sum > 0)addstrAlt(CONST_commondisplay000); }
			if (cr->getCreatureHealth().wound[w] & WOUND_BURNED) { addstrAlt(CONST_commondisplay092); sum--; if (sum > 0)addstrAlt(CONST_commondisplay000); }
		}
	}
}
void set_color_for_armor(const Armor armor);
void setColorForArmor(const Armor ar);
/* character info at top of screen */
const string CONST_commondisplay077 = "Top Skills:";
const string CONST_commondisplay075 = "???????";

const string CONST_commondisplay068 = "Trans: ";

const string CONST_commondisplay047 = ", holding ";
void printcreatureinfo(DeprecatedCreature *cr, unsigned char knowledge)
{


	extern short sitealarmtimer;
	extern int year;
	extern short mode;
	extern char showcarprefs;
	makedelimiter(1);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(1, 2, cr->getNameAndAlignment().name);
	addstrAlt(commaSpace);
	addstrAlt(gettitle(cr->getCreatureHealth().align, cr->juice));
	if (cr->is_holding_body())
	{
		string prisoner_info = CONST_commondisplay047;
		if (prisoner_description.count(cr->prisoner->type) >= 1) {
			prisoner_info += prisoner_description[cr->prisoner->type];
		}
		else {
			prisoner_info += cr->prisoner->getNameAndAlignment().name;
		}
		addstrAlt(prisoner_info);
	}
	printAttributesAsKnowledgePermits(cr->getCreatureAttributeList(), knowledge);
	mvaddstrAlt(5, 11, CONST_commondisplay068);
	long v = -1;
	if (showcarprefs == 1)v = id_getcar(cr->pref_carid);
	else v = id_getcar(cr->carid);
	string str;
	if (v != -1 && showcarprefs != -1)
	{
		(str = getVehicleShortname(v));
		char d;
		if (showcarprefs == 1)d = cr->pref_is_driver;
		else d = cr->is_driver;
		if (d)(str += CONST_commondisplay156);
	}
	else
	{
		int legok = 2;
		if ((cr->getCreatureHealth().wound[BODYPART_LEG_RIGHT] & WOUND_NASTYOFF) ||
			(cr->getCreatureHealth().wound[BODYPART_LEG_RIGHT] & WOUND_CLEANOFF))legok--;
		if ((cr->getCreatureHealth().wound[BODYPART_LEG_LEFT] & WOUND_NASTYOFF) ||
			(cr->getCreatureHealth().wound[BODYPART_LEG_LEFT] & WOUND_CLEANOFF))legok--;
		if (cr->flag & CREATUREFLAG_WHEELCHAIR) { (str = CONST_commondisplay157); }
		else if (legok >= 1) { (str = CONST_commondisplay158); }
		else { (str = CONST_commondisplay003); }
	}
	addstrAlt(str);
	if (mode != GAMEMODE_SITE) { 
		set_color_easy(WHITE_ON_BLACK); 
	}
	else {
		switch (weaponcheck(*cr))
		{
		case -1:
		case 0:set_color_easy(GREEN_ON_BLACK_BRIGHT); break;
		case 1:set_color_easy(YELLOW_ON_BLACK_BRIGHT); break;
		case 2:set_color_easy(RED_ON_BLACK_BRIGHT); break;
		}
	}
	mvaddstrAlt(6, 0, CONST_commondisplay153);
	addstrAlt(cr->get_weapon_string(1));
	if (mode != GAMEMODE_SITE)
	{
		set_color_for_armor(cr->get_armor());
	}
	else
	{
		set_color_for_disguise(cr);
	}
	mvaddstrAlt(7, 0, CONST_commondisplay154);
	addstrAlt(cr->get_armor_string(false));
	set_color_easy(WHITE_ON_BLACK);
	char used[SKILLNUM];
	memset(used, 0, sizeof(char)*SKILLNUM);
	int snum = 5;
	char printed = 1;
	while (snum > 0 && printed)
	{
		printed = 0;
		int max = 0;
		long maxs = -1;
		for (int s = 0; s < SKILLNUM; s++)
		{
			if ((cr->get_skill(s) * 10000 + cr->get_skill_ip(s)) > max && !used[s])
			{
				max = (cr->get_skill(s) * 10000 + cr->get_skill_ip(s));
				maxs = s;
			}
		}
		if (maxs != -1)
		{
			used[maxs] = 1;
			printed = 1;
			// Maxed skills are cyan
			if (cr->skill_cap(maxs) != 0 && cr->get_skill(maxs) >= cr->skill_cap(maxs))set_color_easy(CYAN_ON_BLACK_BRIGHT);
			// About to level up skills are white
			else if (cr->get_skill_ip(maxs) >= 100 + (10 * cr->get_skill(maxs)) &&
				cr->get_skill(maxs) < cr->skill_cap(maxs))set_color_easy(WHITE_ON_BLACK_BRIGHT);
			// <1 skills are dark gray
			else if (cr->get_skill(maxs) < 1)set_color_easy(BLACK_ON_BLACK_BRIGHT);
			// >=1 skills are light gray
			else set_color_easy(WHITE_ON_BLACK);
			moveAlt(3 + 5 - snum, 31);
			if (knowledge > 5 - snum)
				addstrAlt(skill_enum_to_string(maxs));
			else addstrAlt(CONST_commondisplay075);
			addstrAlt(CONST_commondisplay212);
			if (knowledge > 7 - snum)
				addstrAlt(cr->get_skill(maxs));
			else addcharAlt('?');
			if (snum == 5 && printed)
			{
				set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(2, 31, CONST_commondisplay077);
			}
		}
		snum--;
	}
	int woundsum = 0;
	for (int w = 0; w < BODYPARTNUM; w++)
		if (cr->getCreatureHealth().wound[w] != 0)woundsum++;
	printhealthstat(cr->getCreatureHealth(), 1, 49, FALSE);
	if (woundsum > 0)
	{
		printWounds(cr);
		set_color_easy(WHITE_ON_BLACK);
	}
}

void clearRowsTwoThroughSeven() {
	for (int i = 2; i < 8; i++)
	{
		mvaddstrAlt(i, 0, CONST_commondisplay220); // 80 spaces
	}
}

void printcreatureinfo(DeprecatedCreature *cr, unsigned char knowledge = 255);
/* party info at top of screen */
const string CONST_commondisplay101 = " (1)";
const string CONST_commondisplay100 = " (XX)";
const string CONST_commondisplay097 = "/";
const string CONST_commondisplay096 = "+H";
const string CONST_commondisplay094 = "#ÄCODE NAMEÄÄÄÄÄÄÄÄÄÄÄÄSKILLÄÄÄWEAPONÄÄÄÄÄÄÄÄÄARMORÄÄÄÄÄÄÄÄÄÄHEALTHÄÄÄTRANSPORTÄ";
void printparty()
{
	extern Deprecatedsquadst *activesquad;
	extern short party_status;
	extern char showcarprefs;
	extern short mode;
	extern bool mapshowing;

	extern short sitealarmtimer;
	DeprecatedCreature *party[6] = { NULL,NULL,NULL,NULL,NULL,NULL };
	if (activesquad != NULL)
		for (int p = 0; p < 6; p++)party[p] = activesquad->squad[p];
	set_color_easy(WHITE_ON_BLACK);
	clearRowsTwoThroughSeven();
	if (party_status != -1 && party[party_status] == NULL)party_status = -1;
	if (party_status != -1)
	{
		printcreatureinfo(party[party_status]);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(1, 0, party_status + 1);
	}
	else
	{
		char str[200];
		mvaddstrAlt(1, 0, CONST_commondisplay094); // 80 characters
		for (int p = 0; p < 6; p++)
		{
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(p + 2, 0, CONST_commondisplay220); // 80 spaces
			mvaddcharAlt(p + 2, 0, '1' + p);
			if (party[p] != NULL)
			{
				if (party[p]->is_holding_body())set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
				else set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(p + 2, 2, party[p]->getNameAndAlignment().name);
				if (party[p]->is_holding_body())addstrAlt(CONST_commondisplay096);
				int skill = 0;
				char bright = 0;
				for (int sk = 0; sk < SKILLNUM; sk++)
				{
					skill += (int)party[p]->get_skill(sk);
					if (party[p]->get_skill_ip(sk) >= 100 + (10 * party[p]->get_skill(sk)) &&
						party[p]->get_skill(sk) < party[p]->skill_cap(sk))bright = 1;
				}
				set_color_easy(bright ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
				mvaddstrAlt(p + 2, 23, skill);
				addstrAlt(CONST_commondisplay097);
				addstrAlt(party[p]->get_weapon_skill());
				moveAlt(p + 2, 31);
				if (mode != GAMEMODE_SITE) { set_color_easy(WHITE_ON_BLACK); }
				// TODO This is key to the weapon display being red when back at base bug
				// Figure out how
				else {
					switch (weaponcheck(*party[p]))
					{
					case -1:
					case 0:set_color_easy(GREEN_ON_BLACK_BRIGHT); break;
					case 1:set_color_easy(YELLOW_ON_BLACK_BRIGHT); break;
					case 2:set_color_easy(RED_ON_BLACK_BRIGHT); break;
					}
				}
				if (party[p]->has_thrown_weapon && len(party[p]->extra_throwing_weapons))
					addstrAlt(party[p]->extra_throwing_weapons[0]->get_shortname(0));
				else addstrAlt(party[p]->get_weapon().get_shortname(0));
				//set_color_easy(WHITE_ON_BLACK);
				if (party[p]->get_weapon().get_ammoamount() > 0)
				{
					//set_color_easy(WHITE_ON_BLACK);
					addstrAlt(CONST_commondisplay202);
					addstrAlt(party[p]->get_weapon().get_ammoamount());
					addstrAlt(closeParenthesis);
				}
				else if (party[p]->get_weapon().uses_ammo())
				{
					set_color_easy(BLACK_ON_BLACK_BRIGHT);
					if (len(party[p]->clips))
					{
						addstrAlt(CONST_commondisplay202);
						addstrAlt(party[p]->count_clips());
						addstrAlt(closeParenthesis);
					}
					else
						addstrAlt(CONST_commondisplay100);
				}
				else if (party[p]->get_weapon().is_throwable() && !party[p]->has_thrown_weapon)
					addstrAlt(CONST_commondisplay101);
				else if (party[p]->has_thrown_weapon && len(party[p]->extra_throwing_weapons))
				{
					set_color_easy(BLACK_ON_BLACK_BRIGHT);
					addstrAlt(CONST_commondisplay202);
					addstrAlt(party[p]->count_weapons() - party[p]->is_armed());
					addstrAlt(closeParenthesis);
				}
				if (mode != GAMEMODE_SITE)
				{
					setColorForArmor(party[p]->get_armor());
				}
				else
				{
					switch (hasdisguise(*party[p]))
					{
					case 1:set_color_easy(GREEN_ON_BLACK_BRIGHT); break;
					case 2:set_color_easy(YELLOW_ON_BLACK_BRIGHT); break;
					default:
						if (party[p]->get_armor().get_stealth_value() > 1)
							set_color_easy(BLACK_ON_BLACK_BRIGHT);
						else set_color_easy(RED_ON_BLACK_BRIGHT);
						break;
					}
					if (sitealarmtimer >= 0 || isThereASiteAlarm())
						if (party[p]->get_armor().get_stealth_value() > 1)
							set_color_easy(BLACK_ON_BLACK_BRIGHT);
				}
				mvaddstrAlt(p + 2, 46, party[p]->get_armor().get_shortname());
				printhealthstat(party[p]->getCreatureHealth(), p + 2, 61, TRUE);
				set_color_easy(WHITE_ON_BLACK);
				moveAlt(p + 2, 70);
				long v = -1;
				if (showcarprefs == 1)v = id_getcar(party[p]->pref_carid);
				else v = id_getcar(party[p]->carid);
				if (v != -1 && showcarprefs != -1)
				{
					strcpy(str, getVehicleShortname(v).c_str());
					if (showcarprefs == 1 ? party[p]->pref_is_driver : party[p]->is_driver)strcat(str, CONST_commondisplay156.c_str());
				}
				else
				{
					int legok = 2;
					if ((party[p]->getCreatureHealth().wound[BODYPART_LEG_RIGHT] & WOUND_NASTYOFF) ||
						(party[p]->getCreatureHealth().wound[BODYPART_LEG_RIGHT] & WOUND_CLEANOFF))legok--;
					if ((party[p]->getCreatureHealth().wound[BODYPART_LEG_LEFT] & WOUND_NASTYOFF) ||
						(party[p]->getCreatureHealth().wound[BODYPART_LEG_LEFT] & WOUND_CLEANOFF))legok--;
					if (party[p]->flag & CREATUREFLAG_WHEELCHAIR)strcpy(str, CONST_commondisplay157.c_str());
					else if (legok >= 1)strcpy(str, CONST_commondisplay158.c_str());
					else strcpy(str, CONST_commondisplay003.c_str());
				}
				addstrAlt(str);
			}
		}
	}
	makedelimiter();
}
void printwoundstat(CreatureHealth cr, int y, int x)
{
	const string CONST_commondisplay121 = "Burned";
	const string CONST_commondisplay120 = "Torn";
	// Add wound status
	for (int w = 0; w < BODYPARTNUM; w++)
	{
		if (cr.wound[w] & WOUND_BLEEDING)set_color_easy(RED_ON_BLACK_BRIGHT);
		else set_color_easy(WHITE_ON_BLACK);
		moveAlt(y + w, x);
		switch (w)
		{
		case BODYPART_HEAD:addstrAlt(CONST_commondisplay107); break;
		case BODYPART_BODY:addstrAlt(CONST_commondisplay108); break;
		case BODYPART_ARM_RIGHT:addstrAlt(CONST_commondisplay109); break;
		case BODYPART_ARM_LEFT:addstrAlt(CONST_commondisplay110); break;
		case BODYPART_LEG_RIGHT:addstrAlt(CONST_commondisplay111); break;
		case BODYPART_LEG_LEFT:addstrAlt(CONST_commondisplay112); break;
		}
		moveAlt(y + w, x + 11);
		if (cr.wound[w] & WOUND_NASTYOFF)addstrAlt(CONST_commondisplay113);
		else if (cr.wound[w] & WOUND_CLEANOFF)addstrAlt(CONST_commondisplay114);
		else
		{
			int sum = 0;
			if (cr.wound[w] & WOUND_SHOT)sum++;
			if (cr.wound[w] & WOUND_CUT)sum++;
			if (cr.wound[w] & WOUND_BRUISED)sum++;
			if (cr.wound[w] & WOUND_BURNED)sum++;
			if (cr.wound[w] & WOUND_TORN)sum++;
			if (sum == 0)
			{
				set_color_easy(GREEN_ON_BLACK_BRIGHT);
				if (cr.animalgloss == ANIMALGLOSS_ANIMAL)
					addstrAlt(CONST_commondisplay115);
				else addstrAlt(CONST_commondisplay116);
			}
			if (cr.wound[w] & WOUND_SHOT) { addstrAlt(CONST_commondisplay117); sum--; if (sum > 0)addstrAlt(CONST_commondisplay000); }
			if (cr.wound[w] & WOUND_BRUISED) { addstrAlt(CONST_commondisplay118); sum--; if (sum > 0)addstrAlt(CONST_commondisplay000); }
			if (cr.wound[w] & WOUND_CUT) { addstrAlt(CONST_commondisplay119); sum--; if (sum > 0)addstrAlt(CONST_commondisplay000); }
			if (cr.wound[w] & WOUND_TORN) { addstrAlt(CONST_commondisplay120); sum--; if (sum > 0)addstrAlt(CONST_commondisplay000); }
			if (cr.wound[w] & WOUND_BURNED) { addstrAlt(CONST_commondisplay121); sum--; if (sum > 0)addstrAlt(CONST_commondisplay000); }
		}
	}
}
string juiceUntilLevelUp(const int juice) {

	const string CONST_commondisplay138 = "1000";
	const string CONST_commondisplay137 = "500";
	const string CONST_commondisplay136 = "200";
	const string CONST_commondisplay135 = "100";
	const string CONST_commondisplay134 = "50";
	const string CONST_commondisplay133 = "10";
	const string CONST_commondisplay132 = "Next:  ";

	string howMuchJuice;
	if (juice < 1000)
	{
		howMuchJuice = CONST_commondisplay132;
		if (juice < 0) howMuchJuice += tag_0;
		else if (juice < 10) howMuchJuice += CONST_commondisplay133;
		else if (juice < 50) howMuchJuice += CONST_commondisplay134;
		else if (juice < 100) howMuchJuice += CONST_commondisplay135;
		else if (juice < 200) howMuchJuice += CONST_commondisplay136;
		else if (juice < 500) howMuchJuice += CONST_commondisplay137;
		else  howMuchJuice += CONST_commondisplay138;
	}
	return howMuchJuice;
}

string twoDigits(const int x) {
	return x < 10 ? tostring(0) + tostring(x) : tostring(x);
}
void printCreatureAttributes(DeprecatedCreature &cr) {

	const string CONST_commondisplay145 = "Charisma: ";
	const string CONST_commondisplay144 = "Strength: ";
	const string CONST_commondisplay143 = "Agility: ";
	const string CONST_commondisplay142 = "Health: ";
	const string CONST_commondisplay141 = "Wisdom: ";
	const string CONST_commondisplay140 = "Intelligence: ";
	const string CONST_commondisplay139 = "Heart: ";

	mvaddstrAlt(5, 0, CONST_commondisplay139);
	addstrAlt(cr.get_attribute(ATTRIBUTE_HEART, true));
	mvaddstrAlt(6, 0, CONST_commondisplay140);
	addstrAlt(cr.get_attribute(ATTRIBUTE_INTELLIGENCE, true));
	mvaddstrAlt(7, 0, CONST_commondisplay141);
	addstrAlt(cr.get_attribute(ATTRIBUTE_WISDOM, true));
	mvaddstrAlt(8, 0, CONST_commondisplay142);
	addstrAlt(cr.get_attribute(ATTRIBUTE_HEALTH, true));
	mvaddstrAlt(9, 0, CONST_commondisplay143);
	addstrAlt(cr.get_attribute(ATTRIBUTE_AGILITY, true));
	mvaddstrAlt(10, 0, CONST_commondisplay144);
	addstrAlt(cr.get_attribute(ATTRIBUTE_STRENGTH, true));
	mvaddstrAlt(11, 0, CONST_commondisplay145);
	addstrAlt(cr.get_attribute(ATTRIBUTE_CHARISMA, true));
}
void printCreatureSkills(DeprecatedCreature &cr) {
	char used[SKILLNUM];
	memset(used, 0, sizeof(char)*SKILLNUM);
	int skills_max = 16;
	char printed = 1;
	for (int skills_shown = 0; skills_shown < skills_max&&printed; skills_shown++)
	{
		printed = 0;
		int max = 0;
		long maxs = -1;
		for (int s = 0; s < SKILLNUM; s++)
		{
			if ((cr.get_skill(s) * 10000 + cr.get_skill_ip(s)) > max && !used[s])
			{
				max = (cr.get_skill(s) * 10000 + cr.get_skill_ip(s));
				maxs = s;
			}
		}
		if (maxs != -1)
		{
			used[maxs] = 1;
			printed = 1;
			// Maxed skills are cyan
			if (cr.skill_cap(maxs) != 0 && cr.get_skill(maxs) >= cr.skill_cap(maxs))set_color_easy(CYAN_ON_BLACK_BRIGHT);
			// About to level up skills are white
			else if (cr.get_skill_ip(maxs) >= 100 + (10 * cr.get_skill(maxs)) &&
				cr.get_skill(maxs) < cr.skill_cap(maxs))set_color_easy(WHITE_ON_BLACK_BRIGHT);
			// <1 skills are dark gray
			else if (cr.get_skill(maxs) < 1)set_color_easy(BLACK_ON_BLACK_BRIGHT);
			// >=1 skills are light gray
			else set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(6 + skills_shown, 28, skill_enum_to_string(maxs));
			addstrAlt(CONST_commondisplay212);
			moveAlt(6 + skills_shown, 42);
			addstrAlt(twoDigits(cr.get_skill(maxs)) + CONST_commondisplay196);
			if (cr.get_skill_ip(maxs) < 100 + (10 * cr.get_skill(maxs)))
			{
				if ((cr.get_skill_ip(maxs) * 100) / (100 + (10 * cr.get_skill(maxs))) != 0)
				{
					if ((cr.get_skill_ip(maxs) * 100) / (100 + (10 * cr.get_skill(maxs))) < 10)
						addcharAlt('0');
					addstrAlt((cr.get_skill_ip(maxs) * 100) / (100 + (10 * cr.get_skill(maxs))));
				}
				else addstrAlt(CONST_commondisplay197);
			}
			else addstrAlt(CONST_commondisplay198);
			if (cr.skill_cap(maxs) == 0 || cr.get_skill(maxs) < cr.skill_cap(maxs))
				set_color_easy(BLACK_ON_BLACK_BRIGHT);
			moveAlt(6 + skills_shown, 48);
			addstrAlt(twoDigits(cr.skill_cap(maxs)) + CONST_commondisplay199);
		}
	}
}
vector<string> printSpecialWounds(const char special[SPECIALWOUNDNUM]);
/* full screen character sheet */

void statebrokenlaws(CreatureJustice cr, const int flag);
const string CONST_commondisplay167 = "Scheduled Dates:    ";
const string CONST_commondisplay166 = "s";
const string CONST_commondisplay165 = " Romantic Interest";
const string CONST_commondisplay164 = "Scheduled Meetings: ";
const string CONST_commondisplay163 = "Can't Recruit";
const string CONST_commondisplay162 = "Enlightened ";
const string CONST_commondisplay161 = " Max";
const string CONST_commondisplay160 = " Recruits / ";
const string CONST_commondisplay155 = "Car: ";
const string CONST_commondisplay131 = "Juice: ";
const string CONST_commondisplay130 = "*";
const string CONST_commondisplay129 = ", Genderqueer";
const string CONST_commondisplay128 = ", Female";
const string CONST_commondisplay127 = ", Male";
const string CONST_commondisplay126 = " (Age ";
const string CONST_commondisplay125 = "Born ";
void printliberalstats_a(const CreatureBio cr, const CreatureJustice cr_2, const int flag) {

	extern int year;
	extern int day;
	extern int month;

	set_color_easy(WHITE_ON_BLACK);
	// Add name
	mvaddstrAlt(2, 0, CONST_commondisplay201);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	addstrAlt(cr_2.name);
	set_color_easy(WHITE_ON_BLACK);
	if (strcmp(cr_2.propername.data(), cr_2.name.data()) != 0)
	{
		//The names do not match, print real name as well
		addstrAlt(CONST_commondisplay202);
		addstrAlt(cr_2.propername);
		addstrAlt(closeParenthesis);
	}
	addstrAlt(commaSpace);
	addstrAlt(gettitle(cr_2.align, cr_2.juice));
	addstrAlt(CONST_commondisplay202);
	addstrAlt(cr_2.get_type_name);
	addstrAlt(closeParenthesis);
	moveAlt(3, 0);
	// Add birthdate
	addstrAlt(CONST_commondisplay125);
	addstrAlt(getmonth(cr.birthday_month));
	addstrAlt(singleSpace);
	addstrAlt(cr.birthday_day);
	addstrAlt(commaSpace);
	if (cr.birthday_month < month ||
		(cr.birthday_month == month && cr.birthday_day <= day))
		addstrAlt(year - cr.age);
	else addstrAlt(year - 1 - cr.age);
	// Add age
	addstrAlt(CONST_commondisplay126);
	addstrAlt(cr.age);
	// Assess their gender in an Elite Liberal way
	if (cr.gender_liberal == GENDER_MALE)
		addstrAlt(CONST_commondisplay127);
	else if (cr.gender_liberal == GENDER_FEMALE)
		addstrAlt(CONST_commondisplay128);
	else addstrAlt(CONST_commondisplay129);
	// DON'T Note if there's some conflict with Conservative society's perceptions
	//if(cr.gender_liberal != cr.gender_conservative && cr.gender_liberal != GENDER_NEUTRAL)
	//   addstrAlt(CONST_commondisplay130);
	addstrAlt(closeParenthesis);
	moveAlt(3, 46);
	statebrokenlaws(cr_2, flag);
	set_color_easy(WHITE_ON_BLACK);
	// Add juice
	mvaddstrAlt(10, 16, CONST_commondisplay131);
	addstrAlt(cr_2.juice);
	mvaddstrAlt(11, 16, juiceUntilLevelUp(cr_2.juice));

}

void printliberalstats_c(const CreatureCar cr, const CreatureInventory cr_2, const CreatureHealth cr_3, const int flag) {

	extern char showcarprefs;

	set_color_easy(WHITE_ON_BLACK);
	// Add weapon
	mvaddstrAlt(13, 0, CONST_commondisplay153);
	addstrAlt(cr_2.get_weapon_string);
	// Add clothing
	mvaddstrAlt(14, 0, CONST_commondisplay154);
	addstrAlt(cr_2.get_armor_string);
	// Add vehicle
	mvaddstrAlt(15, 0, CONST_commondisplay155);
	long v = -1;
	if (showcarprefs == 1)v = id_getcar(cr.pref_carid);
	else v = id_getcar(cr.carid);
	if (v != -1 && showcarprefs != -1)
	{
		addstrAlt(getVehicleShortname(v));
		char d;
		if (showcarprefs == 1)d = cr.pref_is_driver;
		else d = cr.is_driver;
		if (d)addstrAlt(CONST_commondisplay156);
	}
	else
	{
		int legok = 2;
		if ((cr_3.wound[BODYPART_LEG_RIGHT] & WOUND_NASTYOFF) ||
			(cr_3.wound[BODYPART_LEG_RIGHT] & WOUND_CLEANOFF))legok--;
		if ((cr_3.wound[BODYPART_LEG_LEFT] & WOUND_NASTYOFF) ||
			(cr_3.wound[BODYPART_LEG_LEFT] & WOUND_CLEANOFF))legok--;
		if (flag & CREATUREFLAG_WHEELCHAIR)addstrAlt(CONST_commondisplay157);
		else if (legok >= 1)addstrAlt(CONST_commondisplay158);
		else addstrAlt(CONST_commondisplay003);
	}

}
void printliberalstats_d(DeprecatedCreature &cr) {

	// Add recruit stats
	if (cr.flag != CREATUREFLAG_BRAINWASHED)
	{
		mvaddstrAlt(18, 55, maxsubordinates(cr) - subordinatesleft(cr));
		addstrAlt(CONST_commondisplay160);
		addstrAlt(maxsubordinates(cr));
		addstrAlt(CONST_commondisplay161);
	}
	else
	{
		mvaddstrAlt(18, 55, CONST_commondisplay162);
		addstrAlt(CONST_commondisplay163);
	}
	// Any meetings with potential recruits scheduled?
	if (scheduledmeetings(cr))
	{
		mvaddstrAlt(20, 55, CONST_commondisplay164);
		addstrAlt(scheduledmeetings(cr));
	}
	// Add seduction stats
	moveAlt(19, 55);
	int lovers = loveslaves(cr);
	if (cr.flag & CREATUREFLAG_LOVESLAVE)
		lovers++;
	if (lovers)
	{
		addstrAlt(lovers);
		addstrAlt(CONST_commondisplay165);
		if (lovers > 1)addstrAlt(CONST_commondisplay166);
	}
	// Any dates with potential love interests scheduled?
	if (scheduleddates(cr))
	{
		mvaddstrAlt(21, 55, CONST_commondisplay167);
		addstrAlt(scheduleddates(cr));
	}


}
void printliberalstats_e(const CreatureHealth getCreatureHealth) {


	printwoundstat(getCreatureHealth, 5, 55);
	//SPECIAL WOUNDS
	{
		set_color_easy(RED_ON_BLACK);
		int y = 17;
		for (string str : printSpecialWounds(getCreatureHealth.special)) {

			mvaddstrAlt(y++, 0, str);
		}
	}


}
void printliberalstats_f(DeprecatedCreature &cr) {


	set_color_easy(WHITE_ON_BLACK);
	for (int i = 0, y = 12; i < AUGMENTATIONNUM; i++, y++)
	{
		if (cr.get_augmentation(i).type == -1) continue;
		mvaddstrAlt(y, 55, Augmentation::get_name(i));
		addstrAlt(CONST_commondisplay212);
		addstrAlt(cr.get_augmentation(i).name);
	}

}

void printliberalstats(DeprecatedCreature &cr)
{
	printliberalstats_a(cr.getCreatureBio(), cr.getCreatureJustice(), cr.flag);

	// Add attributes
	printCreatureAttributes(cr);
	// Add highest skills
	mvaddstrAlt(5, 28, CONST_commondisplay193);
	mvaddstrAlt(5, 43, CONST_commondisplay194);
	printCreatureSkills(cr);

	printliberalstats_c(cr.getCreatureCar(), cr.getCreatureInventory(), cr.getCreatureHealth(), cr.flag);
	printliberalstats_d(cr);
	printliberalstats_e(cr.getCreatureHealth());
	printliberalstats_f(cr);
}
/* Full screen character sheet, skills only edition */
void printliberalskills(CreatureJustice cr, ListOfCreatureSkills cr_2) {

	// Add name
	set_color_easy(WHITE_ON_BLACK);
	moveAlt(2, 0);
	if (strcmp(cr.propername.data(), cr.name.data()) != 0)
		addstrAlt(CONST_commondisplay200);
	else addstrAlt(CONST_commondisplay201);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	addstrAlt(cr.name);
	set_color_easy(WHITE_ON_BLACK);
	addstrAlt(commaSpace);
	addstrAlt(gettitle(cr.align, cr.juice));
	addstrAlt(CONST_commondisplay202);
	addstrAlt(cr.get_type_name);
	addstrAlt(closeParenthesis);
	// Add all skills
	for (int s = 0; s < SKILLNUM; s++)
	{
		if (s % 3 == 0 && s < 9)
		{
			set_color_easy(WHITE_ON_BLACK);
			moveAlt(4, 27 * (s / 3));
			addstrAlt(CONST_commondisplay193);
			moveAlt(4, 15 + 27 * (s / 3));
			addstrAlt(CONST_commondisplay194);
		}
		// Maxed skills are cyan
		if (cr_2.skill_cap(s) != 0 && cr_2.get_skill(s) >= cr_2.skill_cap(s))set_color_easy(CYAN_ON_BLACK_BRIGHT);
		// About to level up skills are white
		else if (cr_2.get_skill_ip(s) >= 100 + (10 * cr_2.get_skill(s)) &&
			cr_2.get_skill(s) < cr_2.skill_cap(s))set_color_easy(WHITE_ON_BLACK_BRIGHT);
		// <1 skills are dark gray
		else if (cr_2.get_skill(s) < 1)set_color_easy(BLACK_ON_BLACK_BRIGHT);
		// >=1 skills are light gray
		else set_color_easy(WHITE_ON_BLACK);
		moveAlt(5 + s / 3, 27 * (s % 3));
		addstrAlt(skill_enum_to_string(s));
		addstrAlt(CONST_commondisplay212);
		moveAlt(5 + s / 3, 14 + 27 * (s % 3));
		addstrAlt(twoDigits(cr_2.get_skill(s)) + CONST_commondisplay196);
		if (cr_2.get_skill_ip(s) < 100 + (10 * cr_2.get_skill(s)))
		{
			if ((cr_2.get_skill_ip(s) * 100) / (100 + (10 * cr_2.get_skill(s))) != 0)
			{
				if ((cr_2.get_skill_ip(s) * 100) / (100 + (10 * cr_2.get_skill(s))) < 10)
					addstrAlt(tag_0);
				addstrAlt((cr_2.get_skill_ip(s) * 100) / (100 + (10 * cr_2.get_skill(s))));
			}
			else addstrAlt(CONST_commondisplay197);
		}
		else addstrAlt(CONST_commondisplay198);
		if (cr_2.skill_cap(s) == 0 || cr_2.get_skill(s) < cr_2.skill_cap(s))
			set_color_easy(BLACK_ON_BLACK_BRIGHT);
		moveAlt(5 + s / 3, 20 + 27 * (s % 3));
		addstrAlt(twoDigits(cr_2.skill_cap(s)) + CONST_commondisplay199.c_str());
	}
	set_color_easy(WHITE_ON_BLACK);
}

/* Full screen character sheet, crime sheet */
void printliberalcrimes(CreatureJustice cr)
{
	const string CONST_commondisplay211 = "NUM";
	const string CONST_commondisplay210 = "CRIME";
	const string CONST_commondisplay209 = " months in prison.";
	const string CONST_commondisplay208 = "Sentenced to ";
	const string CONST_commondisplay207 = "Serving ";
	const string CONST_commondisplay206 = "Sentenced to life in prison";
	const string CONST_commondisplay205 = "Serving life in prison";
	const string CONST_commondisplay204 = "Sentenced to DEATH";
	const string CONST_commondisplay203 = "On DEATH ROW";
	// Add name
	set_color_easy(WHITE_ON_BLACK);
	if (strcmp(cr.propername.data(), cr.name.data()) != 0)
		mvaddstrAlt(2, 0, CONST_commondisplay200);
	else mvaddstrAlt(2, 0, CONST_commondisplay201);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	addstrAlt(cr.name);
	set_color_easy(WHITE_ON_BLACK);
	addstrAlt(commaSpace);
	addstrAlt(gettitle(cr.align, cr.juice));
	addstrAlt(CONST_commondisplay202);
	addstrAlt(cr.get_type_name);
	addstrAlt(closeParenthesis);
	// Show outstanding convictions in addition to untried crimes
	if (cr.deathpenalty)
	{
		set_color_easy(RED_ON_BLACK_BRIGHT);
		if (LocationsPool::getInstance().getLocationType(cr.location) == SITE_GOVERNMENT_PRISON)
			mvaddstrAlt(3, 0, CONST_commondisplay203);
		else mvaddstrAlt(3, 0, CONST_commondisplay204);
	}
	else if (cr.sentence < 0)
	{
		set_color_easy(RED_ON_BLACK_BRIGHT);
		if (LocationsPool::getInstance().getLocationType(cr.location) == SITE_GOVERNMENT_PRISON)
			mvaddstrAlt(3, 0, CONST_commondisplay205);
		else mvaddstrAlt(3, 0, CONST_commondisplay206);
	}
	else if (cr.sentence > 0)
	{
		set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		if (LocationsPool::getInstance().getLocationType(cr.location) == SITE_GOVERNMENT_PRISON)
			mvaddstrAlt(3, 0, CONST_commondisplay207);
		else mvaddstrAlt(3, 0, CONST_commondisplay208);
		addstrAlt(cr.sentence);
		addstrAlt(CONST_commondisplay209);
	}
	// Add all crimes
	for (int i = 0; i < LAWFLAGNUM; i++)
	{
		if (i % 2 == 0 && i < 4)
		{
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(4, 40 * (i / 2), CONST_commondisplay210);
			mvaddstrAlt(4, 30 + 40 * (i / 2), CONST_commondisplay211);
		}
		// Commited crimes are yellow
		if (cr.crimes_suspected[i] > 0)
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(5 + i / 2, 40 * (i % 2), getlawflag(i) + CONST_commondisplay212);
		mvaddstrAlt(5 + i / 2, 30 + 40 * (i % 2), twoDigits(cr.crimes_suspected[i]));
	}
	set_color_easy(WHITE_ON_BLACK);
}
/* full character sheet (with surrounding interface) */
void fullstatus(const int _p)
{
	int p = _p;
	const string CONST_commondisplay219 = "What is the new code name?                                                      ";
	const string CONST_commondisplay218 = "    UP/DOWN  - More Info";
	const string CONST_commondisplay217 = "Press any other key to continue the Struggle";
	const string CONST_commondisplay216 = "    LEFT/RIGHT - Other Liberals";
	const string CONST_commondisplay215 = "N - Change Code Name      G - Fix Gender Label";
	const string CONST_commondisplay214 = "Profile of a Liberal";
	extern Deprecatedsquadst *activesquad;
	if (isThereNoActivesquad())return;
	const int pagenum = 3;
	int page = 0;
	while (true)
	{
		eraseAlt();
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		mvaddstrAlt(0, 0, CONST_commondisplay214);
		if (page == 0) { 
			printliberalstats(*activesquad->squad[p]);
		}
		else if (page == 1) printliberalskills(activesquad->squad[p]->getCreatureJustice(), activesquad->squad[p]->getListOfCreatureSkills());
		else if (page == 2) printliberalcrimes(activesquad->squad[p]->getCreatureJustice());
		mvaddstrAlt(23, 0, CONST_commondisplay215);
		if (activesquad->squad[1] != NULL)
			addstrAlt(CONST_commondisplay216);
		mvaddstrAlt(24, 0, CONST_commondisplay217);
		addstrAlt(CONST_commondisplay218);
		int c = getkeyAlt();
		if (activesquad->squad[1] != NULL && ((c == KEY_LEFT) || (c == KEY_RIGHT)))
		{
			int sx = (c == KEY_LEFT) ? -1 : 1;
			do p = (p + 6 + sx) % 6; while (activesquad->squad[p] == NULL);
		}
		else if (c == KEY_DOWN)
		{
			page++;
			page %= pagenum;
		}
		else if (c == KEY_UP)
		{
			page--;
			if (page < 0) page = pagenum - 1;
			page %= pagenum;
		}
		else if (c == 'n')
		{
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(23, 0, CONST_commondisplay219); // 80 characters
			mvaddstrAlt(24, 0, CONST_commondisplay220); // 80 spaces
			activesquad->squad[p]->new_name();
		}
		else if (c == 'g')
		{
			activesquad->squad[p]->gender_liberal++;
			if (activesquad->squad[p]->gender_liberal > 2)
				activesquad->squad[p]->gender_liberal = 0;
		}
		else break;
	}
}
