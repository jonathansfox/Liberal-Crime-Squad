
#include "../includes.h"

const string tag_Sta = "Sta, ";
const string tag_Libp = "Lib+, ";
const string tag_Lib = "Lib, ";
const string tag_Mod = "Mod, ";
const string tag_Cons = "Cons, ";
const string tag_Consp = "Cons+";
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
// select CONST_basemode006, choose CONST_basemodeB054,
// then choose CONST_basemode007.
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
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
//#include "../pdcurses/curses.h"
#include "../cursesgraphics.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
//#include "../basemode/liberalagenda.h"
bool liberalagenda(signed char won);
#include "../basemode/baseactions.h"
//#include "../basemode/activate_sleepers.h"
void activate_sleepers();
//#include "../basemode/activate.h"
void activate();
//#include "../basemode/reviewmode.h"
void review();
#include "../common/translateid.h"
// for  int getsquad(int)
#include "../common/getnames.h"
// for std::string getmonth(int)
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
//for int mvaddstr(int, int, const char*)
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
//#include "../common/equipment.h"
void equip(vector<Item *> &loot, int loc);
//#include "../politics/politics.h"
bool stalinview(short view, bool islaw);
//#include "../monthly/monthly.h"
void passmonth(char &clearformess,char canseethings);
#include "../daily/daily.h"
//for int monthday();
#include "../daily/siege.h"
//for giveup()
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../common/musicClass.h"
#include "../common/creaturePool.h"
#include "../locations/locationsPool.h"
extern string commaSpace;
extern string singleSpace;
string change_squad_order;
enum CantSeeReason
{
	CANTSEE_DATING = 1,
	CANTSEE_HIDING = 2,
	CANTSEE_OTHER = 3,
	CANTSEE_DISBANDING = 4
};
string check_status_of_squad_liberal;
string show_squad_liberal_status;
void printHouseMake() {
	extern bool stalinmode;
	extern short house[HOUSENUM];
	const string CONST_basemode015 = "House: ";
	int housemake[6] = { 0,0,0,0,0,0 };
	for (int h = 0; h < HOUSENUM; h++) {
		housemake[house[h] + 2]++;
	}
	{
		signed char align;
		if (housemake[5] + min(housemake[0], housemake[4]) >= HOUSEMAJORITY) align = ALIGN_STALINIST; // Stalinists have a majority (perhaps with help from extremists on both sides)
		else if (housemake[0] >= HOUSEMAJORITY) align = ALIGN_ARCHCONSERVATIVE; // Arch-Conservatives have a majority
		else if (housemake[4] >= HOUSEMAJORITY) align = ALIGN_ELITELIBERAL; // Elite Liberals have a majority
		else if (housemake[0] + housemake[1] >= HOUSEMAJORITY) align = ALIGN_CONSERVATIVE; // Conservatives plus Arch-Conservatives have a majority
		else if (housemake[3] + housemake[4] >= HOUSEMAJORITY) align = ALIGN_LIBERAL; // Liberals plus Elite Liberals have a majority
		else align = ALIGN_MODERATE; // nobody has a majority
		set_alignment_color(align, true);
		mvaddstrAlt(2, 0, CONST_basemode015);
		if (stalinmode) {
			addstrAlt(tostring(housemake[5]) + tag_Sta);
		}
		addstrAlt(tostring(housemake[4]) + tag_Libp);
		addstrAlt(tostring(housemake[3]) + tag_Lib);
		addstrAlt(tostring(housemake[2]) + tag_Mod);
		addstrAlt(tostring(housemake[1]) + tag_Cons);
		addstrAlt(tostring(housemake[0]) + tag_Consp);
	}
}
void printSenateMake() {
	const string CONST_basemode016 = "Senate: ";
	extern bool stalinmode;
	extern short exec[EXECNUM];
	extern short senate[SENATENUM];
	int senatemake[6] = { 0,0,0,0,0,0 };
	for (int s = 0; s < SENATENUM; s++) {
		senatemake[senate[s] + 2]++;
	}
	senatemake[exec[EXEC_VP] + 2]++; // Vice President is tie-breaking vote in the Senate
	
	signed char align;
	if (senatemake[5] + min(senatemake[0], senatemake[4]) >= SENATEMAJORITY) align = ALIGN_STALINIST; // Stalinists have a majority (perhaps with help from extremists on both sides)
	else if (senatemake[0] >= SENATEMAJORITY) align = ALIGN_ARCHCONSERVATIVE; // Arch-Conservatives have a majority
	else if (senatemake[4] >= SENATEMAJORITY) align = ALIGN_ELITELIBERAL; // Elite Liberals have a majority
	else if (senatemake[0] + senatemake[1] >= SENATEMAJORITY) align = ALIGN_CONSERVATIVE; // Conservatives plus Arch-Conservatives have a majority
	else if (senatemake[3] + senatemake[4] >= SENATEMAJORITY) align = ALIGN_LIBERAL; // Liberals plus Elite Liberals have a majority
	else align = ALIGN_MODERATE; // nobody has a majority
	set_alignment_color(align, true);
	
	senatemake[exec[EXEC_VP] + 2]--; // Vice President isn't actually a Senator though
	mvaddstrAlt(3, 0, CONST_basemode016);
	if (stalinmode) addstrAlt(tostring(senatemake[5]) + tag_Sta);
	addstrAlt(tostring(senatemake[4]) + tag_Libp);
	addstrAlt(tostring(senatemake[3]) + tag_Lib);
	addstrAlt(tostring(senatemake[2]) + tag_Mod);
	addstrAlt(tostring(senatemake[1]) + tag_Cons);
	addstrAlt(tostring(senatemake[0]) + tag_Consp);
}
void printCourtMake() {
	extern bool stalinmode;
	extern short court[COURTNUM];
	const string CONST_basemode017 = "Supreme Court: ";
	int courtmake[6] = { 0,0,0,0,0,0 };
	for (int s = 0; s < COURTNUM; s++) {
		courtmake[court[s] + 2]++;
	}

	
	signed char align;
	if (courtmake[5] + min(courtmake[0], courtmake[4]) >= COURTMAJORITY) align = ALIGN_STALINIST; // Stalinists have a majority (perhaps with help from extremists on both sides)
	else if (courtmake[0] >= COURTMAJORITY) align = ALIGN_ARCHCONSERVATIVE; // Arch-Conservatives have a majority
	else if (courtmake[4] >= COURTMAJORITY) align = ALIGN_ELITELIBERAL; // Elite Liberals have a majority
	else if (courtmake[0] + courtmake[1] >= COURTMAJORITY) align = ALIGN_CONSERVATIVE; // Conservatives plus Arch-Conservatives have a majority
	else if (courtmake[3] + courtmake[4] >= COURTMAJORITY) align = ALIGN_LIBERAL; // Liberals plus Elite Liberals have a majority
	else align = ALIGN_MODERATE; // nobody has a majority
	set_alignment_color(align, true);
	

	mvaddstrAlt(4, 0, CONST_basemode017);
	if (stalinmode) addstrAlt(tostring(courtmake[5]) + tag_Sta);
	addstrAlt(tostring(courtmake[4]) + tag_Libp);
	addstrAlt(tostring(courtmake[3]) + tag_Lib);
	addstrAlt(tostring(courtmake[2]) + tag_Mod);
	addstrAlt(tostring(courtmake[1]) + tag_Cons);
	addstrAlt(tostring(courtmake[0]) + tag_Consp);
}

void printStalinMood() {
	const string CONST_basemode029 = "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ";
	const string CONST_basemode024 = "Public Mood";
	const string CONST_basemode020 = "Libertarian";
	const string CONST_basemode019 = "Stalinist";
	extern short attitude[VIEWNUM];

	signed char align;
	int stalin = 0; // the Stalinist mood position from 1 to 78 (left=Stalinist, right=Libertarian)
	for (int v = 0; v < VIEWNUM - 3; v++)
	{
		stalin += stalinview(v, false) ? attitude[v] : 100 - attitude[v];
	}
	stalin = 78 - (stalin * 77) / ((VIEWNUM - 3) * 100); // very accurate Stalinist mood positioning!
	if (stalin >= 64) align = ALIGN_ELITELIBERAL;
	else if (stalin >= 48) align = ALIGN_LIBERAL;
	else if (stalin >= 32) align = ALIGN_MODERATE;
	else if (stalin >= 16) align = ALIGN_CONSERVATIVE;
	else align = ALIGN_ARCHCONSERVATIVE;
	set_alignment_color(align, true);
	mvaddstrAlt(17, 33, CONST_basemode024);
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(17, 1, CONST_basemode019);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(17, 68, CONST_basemode020);
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(18, 0, "\x11ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
	mvaddstrAlt(18, 16, CONST_basemode029);
	set_color_easy(YELLOW_ON_BLACK_BRIGHT);
	mvaddstrAlt(18, 32, CONST_basemode029);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(18, 48, CONST_basemode029);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(18, 64, "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\x10");
	set_alignment_color(align, true);
	mvaddcharAlt(18, stalin, 'O');
}
void printMood() {

	extern bool stalinmode;
	if (stalinmode)
	{
		printStalinMood();
	}

	const string CONST_basemode029 = "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ";
	const string CONST_basemode026 = "Conservative";
	const string CONST_basemode025 = "Liberal";
	const string CONST_basemode024 = "Public Mood";
	extern short attitude[VIEWNUM];

	int mood = 0; // the mood position from 1 to 78 (left=left-wing, right=right-wing)
	for (int v = 0; v < VIEWNUM - 3; v++) { mood += attitude[v]; }
	mood = 78 - (mood * 77) / ((VIEWNUM - 3) * 100); // very accurate mood positioning!
	signed char align;
	if (mood >= 64) align = ALIGN_ARCHCONSERVATIVE;
	else if (mood >= 48) align = ALIGN_CONSERVATIVE;
	else if (mood >= 32) align = ALIGN_MODERATE;
	else if (mood >= 16) align = ALIGN_LIBERAL;
	else align = ALIGN_ELITELIBERAL;
	set_alignment_color(align, true);

	mvaddstrAlt(stalinmode ? 21 : 20, 33, CONST_basemode024);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(21, 1, CONST_basemode025);
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(21, 67, CONST_basemode026);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(22, 0, "\x11ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(22, 16, CONST_basemode029);
	set_color_easy(YELLOW_ON_BLACK_BRIGHT);
	mvaddstrAlt(22, 32, CONST_basemode029);
	set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
	mvaddstrAlt(22, 48, CONST_basemode029);
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(22, 64, "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\x10");
	set_alignment_color(align, true);

	mvaddcharAlt(22, mood, 'O');
}
void printLawMake() {
	extern short lawList[LAWNUM];

	for (int l = 0; l < LAWNUM; l++)
	{
		set_alignment_color(lawList[l], true);
		mvaddstrAlt(6 + l / 3, l % 3 * 30, getlaw(l));
	}
}
void addStringYear();
void printMonthAndYear() {
	extern int month;

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(0, 0, getmonth(month) + singleSpace);
	addStringYear();
}
void letTheUnworthyLeave() {
	extern vector<DeprecatedCreature *> pool;
	extern int disbandtime;
	extern int year;

	for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
	{
		int targetjuice = LCSrandom(100 * (year - disbandtime + 1));
		if (targetjuice > 1000) targetjuice = 1000;
		if (pool[p]->juice < targetjuice&&pool[p]->hireid != -1 && !(pool[p]->flag&CREATUREFLAG_SLEEPER))
			pool[p]->un_alive();
	}
}
void printExecMove() {

	const string CONST_basemode014 = ", 2nd Term";
	const string CONST_basemode013 = ", 1st Term";
	const string CONST_basemode012 = "President: ";
	extern short execterm;

	extern short exec[EXECNUM];
	extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	set_alignment_color(exec[EXEC_PRESIDENT], true);
	mvaddstrAlt(1, 0, CONST_basemode012);
	addstrAlt(execname[EXEC_PRESIDENT]);
	addstrAlt(commaSpace);
	addstrAlt(getalign(exec[EXEC_PRESIDENT]));
	if (execterm == 1) {
		addstrAlt(CONST_basemode013);
	}
	else {
		addstrAlt(CONST_basemode014);
	}

}
void printDisbandScreen() {

	const string CONST_basemode030 = "R - Recreate the Liberal Crime Squad                  Any Other Key - Next Month";
	extern MusicClass music;

	music.play(MUSIC_DISBANDED);

	letTheUnworthyLeave();

	eraseAlt();
	printMonthAndYear();

	printExecMove();
	printHouseMake();
	printSenateMake();
	printCourtMake();
	printLawMake();

	printMood();


	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(24, 0, CONST_basemode030);
}
bool show_disbanding_screen(int& oldforcemonth)
{
	extern int month;
	if (oldforcemonth == month) return true;

	oldforcemonth = month;
	printDisbandScreen();

	return(getkeyAlt() != 'r');
}
void printIfLongWait(int nonsighttime) {
	extern MusicClass music;
	extern Log gamelog;
	const string CONST_basemode033 = "It sure has been a while.  Things might have changed a bit.";
	const string CONST_basemode032 = "It has been a long time.  A lot must have changed...";
	const string CONST_basemode031 = "How long since you've heard these sounds...  times have changed.";
	if (nonsighttime >= 365 * 4)
	{
		music.play(MUSIC_BASEMODE);
		eraseAlt();
		char str[100];
		if (nonsighttime >= 365 * 16)
			strcpy(str, CONST_basemode031.c_str());
		else if (nonsighttime >= 365 * 8)
			strcpy(str, CONST_basemode032.c_str());
		else strcpy(str, CONST_basemode033.c_str());
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrCenter(12, str, gamelog);
		gamelog.nextMessage(); //Write out buffer to prepare for the next message.
		pressAnyKey();
	}
}

const string CONST_basemode062 = "P - PATRIOTISM: fly a flag here ($20)";
const string CONST_basemode061 = "P - PROTEST: burn the flag";
const string CONST_basemode060 = "S - FREE SPEECH: the Liberal Slogan";
const string CONST_basemode059 = " (next month)";
const string CONST_basemode058 = "W - Wait a day";
const string CONST_basemode057 = "W - Wait out the siege";
const string CONST_basemode056 = "Cannot Wait until Siege Resolved";
const string CONST_basemode055 = "X - Live to fight EVIL another day";
const string CONST_basemode054 = "F - Go forth to stop EVIL";
const string CONST_basemode053 = "G - Give Up";
const string CONST_basemode052 = "F - Escape/Engage";
const string CONST_basemode051 = "C - Cancel this Squad's Departure";
void stillDontForceWait(const char sieged, const char cannotwait,
	const char haveflag,
	const char partysize) {

	extern int selectedsiege;
	extern Deprecatedsquadst *activesquad;
	extern string slogan_str;
	extern vector<DeprecatedCreature *> pool;
	extern Log gamelog;
	extern class Ledger ledger;
	extern int day;



	if (partysize)
	{
		if (activesquad->activity.type != ACTIVITY_NONE) set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	}
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(20, 1, CONST_basemode051);



	if (sieged)
	{
		if (partysize) set_color_easy(WHITE_ON_BLACK);
		else
		{
			set_color_easy(BLACK_ON_BLACK_BRIGHT);
			for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
			{
				if (pool[p]->location == selectedsiege)
				{
					set_color_easy(WHITE_ON_BLACK);
					break;
				}
			}
		}
		mvaddstrAlt(19, 1, CONST_basemode052);
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(19, 23, CONST_basemode053);
	}
	else
	{
		if (partysize) set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(19, 1, CONST_basemode054);
	}


	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(23, 40, CONST_basemode055);
	set_color_easy(WHITE_ON_BLACK);

	if (cannotwait) mvaddstrAlt(23, 1, CONST_basemode056);
	else
	{
		if (sieged) mvaddstrAlt(23, 1, CONST_basemode057);
		else mvaddstrAlt(23, 1, CONST_basemode058);
		if (day == monthday()) addstrAlt(CONST_basemode059);
	}
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(22, 40, CONST_basemode060);

	if (haveflag)
	{
		if (sieged) set_color_easy(GREEN_ON_BLACK_BRIGHT);
		else set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(22, 1, CONST_basemode061);
	}
	else
	{
		if (ledger.get_funds() >= 20 && !sieged && (selectedsiege != -1 || activesquad != NULL))
			set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(22, 1, CONST_basemode062);
	}

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	if (haveflag) mvaddstrCenter(17, slogan_str);
	else mvaddstrCenter(13, slogan_str);
}
int lenVehiclePool();
const string CONST_basemode050 = "B - Sleepers";
const string CONST_basemode049 = "A - Activate Liberals";
const string CONST_basemode048 = "L - The Status of the Liberal Agenda";
const string CONST_basemode047 = "Z - Next Location";
const string CONST_basemode046 = "TAB - Next Squad";
const string CONST_basemode045 = "O - Reorder";
const string CONST_basemode044 = "R - Review Assets and Form Squads";
const string CONST_basemode043 = "V - Vehicles";
const string CONST_basemode042 = "E - Equip Squad";
const string CONST_basemode041 = "ÄÄÄ PLANNING ÄÄÄ";
const string CONST_basemode040 = "ÄÄÄ ACTIVISM ÄÄÄ";
const string CONST_basemode039 = ":::::::::";
const string CONST_basemode038 = ":.:.:.:.:";
const string CONST_basemode037 = " (No Food)";
const string CONST_basemode036 = "Under Siege";
const string CONST_basemode035 = "Under Attack";
const string CONST_basemode034 = "I - Invest in this location";
void dontForceWait(const char sieged, const char underattack,
	const char haveflag,
	const Location *loc,
	const char safenumber,
	const char partysize) {



	extern int selectedsiege;
	extern Deprecatedsquadst *activesquad;
	extern vector<Deprecatedsquadst *> squad;
	extern vector<DeprecatedCreature *> pool;

	eraseAlt();
	if (activesquad != NULL) selectedsiege = -1;
	locheader();
	if (selectedsiege != -1)
	{
		printlocation(selectedsiege);
		if (LocationsPool::getInstance().canBeUpgraded(selectedsiege) &&
			!LocationsPool::getInstance().isThereASiegeHere(selectedsiege))
		{
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(8, 1, CONST_basemode034);
		}
	}
	else if (activesquad != NULL) printparty();
	else makedelimiter();


	if (sieged)
	{
		if (underattack)
		{
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 1, CONST_basemode035);
		}
		else
		{
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 1, CONST_basemode036);
			int stock = 1;
			if (loc)stock = loc->compound_stores;
			if (!stock)addstrAlt(CONST_basemode037);
		}
	}


	if (haveflag) for (int y = 0; y < 7; y++)
	{
		if (y < 6)
		{
			set_color_easy(y < 4 ? WHITE_ON_BLUE_BRIGHT : WHITE_ON_RED_BRIGHT);
			if (y == 0) mvaddstrAlt(y + 10, 31, CONST_basemode038);
			else if (y < 3) mvaddstrAlt(y + 10, 31, CONST_basemode039);
			else for (int x = 0; x < 9; x++) mvaddchAlt(y + 10, 31 + x, CH_LOWER_HALF_BLOCK);
			set_color_easy(WHITE_ON_RED_BRIGHT);
			for (int x = 9; x < 18; x++) addchAlt(CH_LOWER_HALF_BLOCK);
		}
		else
		{
			set_color_easy(RED_ON_BLACK);
			for (int x = 0; x < 18; x++) mvaddchAlt(y + 10, 31 + x, CH_UPPER_HALF_BLOCK);
		}
	}


	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(18, 10, CONST_basemode040);
	mvaddstrAlt(18, 51, CONST_basemode041);
	if (partysize && !underattack) set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(19, 40, CONST_basemode042);
	if (lenVehiclePool() && partysize) set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(19, 60, CONST_basemode043);
	if (CreaturePool::getInstance().lenpool()) set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(20, 40, CONST_basemode044);
	if (partysize > 1) set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	if (partysize && !sieged) mvaddstrAlt(8, 30, CONST_basemode045);
	if (activesquad && !sieged) // don't cover up info about siege with irrelevant squad name of a squad that will be disbanded during the siege anyway
	{
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(8, 1, activesquad->name);
		addchAlt(CH_BOX_DRAWINGS_LIGHT_HORIZONTAL); //in case of overlap, at least make it clear where the name ends.
	}


	if (len(squad) > 1 || (!activesquad&&len(squad))) set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 43, CONST_basemode046);
	if (safenumber > 0) set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);


	mvaddstrAlt(8, 62, CONST_basemode047);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(21, 40, CONST_basemode048);
	set_color_easy(BLACK_ON_BLACK_BRIGHT);
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++) if (pool[p]->is_active_liberal())
	{
		if (pool[p]->squadid != -1)
		{
			int sq = getsquad(pool[p]->squadid);
			if (sq != -1) if (squad[sq]->activity.type != ACTIVITY_NONE) continue;
		}
		set_color_easy(WHITE_ON_BLACK);
		break;
	}


	mvaddstrAlt(21, 1, CONST_basemode049);
	set_color_easy(BLACK_ON_BLACK_BRIGHT);
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++) {
		if (pool[p]->is_lcs_sleeper())
		{
			set_color_easy(WHITE_ON_BLACK);
			break;
		}
	}

	mvaddstrAlt(21, 25, CONST_basemode050);


}
void pressedThisKeyInBaseMode(const int c) {
	extern char disbanding;
	extern Deprecatedsquadst *activesquad;
	extern int selectedsiege;
	extern short party_status;
	extern vector<Deprecatedsquadst *> squad;

	switch (c)
	{
	case 'i': if (selectedsiege != -1)
		if (LocationsPool::getInstance().canBeUpgraded(selectedsiege) && !LocationsPool::getInstance().isThereASiegeHere(selectedsiege))
			investlocation(); break;
	case 'l': disbanding = liberalagenda(0); break;

	case 'a': activate(); break;
	case 'b': activate_sleepers(); break;
	case TAB: if (len(squad)) {
		if (!activesquad) activesquad = squad[0];
		else for (int sq = 0; sq < len(squad); sq++)
			if (squad[sq] == activesquad)
			{
				if (sq == len(squad) - 1) activesquad = squad[0];
				else activesquad = squad[sq + 1];
				break;
			}
	} break;

	case 'r': if (CreaturePool::getInstance().lenpool()) review(); break;

	case 's': getslogan(); break;
	case '0': party_status = -1; break;
	case '1': case '2': case '3': case '4': case '5': case '6':
		if (activesquad) if (activesquad->squad[c - '1']) {
			if (party_status == c - '1') fullstatus(party_status);
			else party_status = c - '1';
		} break;
	}
}

void findCantSeeReason(char &canseethings, char &forcewait) {
	bool isPartOfJusticeSystem(int cursite);
	extern char cantseereason;
	extern vector<DeprecatedCreature *> pool;

	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (pool[p]->getCreatureHealth().alive&&
			pool[p]->getCreatureHealth().align == 1 &&
			pool[p]->dating == 0 &&
			pool[p]->hiding == 0 &&
			!(pool[p]->flag & CREATUREFLAG_SLEEPER))
		{
			if (!isPartOfJusticeSystem(pool[p]->location))
			{
				canseethings = 1;
				if (pool[p]->clinic == 0) { forcewait = 0; break; }
			}
		}
		else
		{
			if (pool[p]->dating == 1 && cantseereason > CANTSEE_DATING) cantseereason = CANTSEE_DATING;
			else if (pool[p]->hiding != 0 && cantseereason > CANTSEE_HIDING) cantseereason = CANTSEE_HIDING;
		}
	}
}
void burnFlagAtLocation(int l);
void politicalEffectsOfFlagBurning(const char sieged) {
	extern short lawList[LAWNUM];
	extern Deprecatedsquadst *activesquad;
	extern int selectedsiege;

	if (selectedsiege != -1)
	{
		burnFlagAtLocation(selectedsiege);
		if (lawList[LAW_FLAGBURNING] < 1)
			criminalizepool(LAWFLAG_BURNFLAG, -1, selectedsiege);
	}
	if (activesquad)
	{
		burnFlagAtLocation(activesquad->squad[0]->base);
		if (lawList[LAW_FLAGBURNING] < 1)
			criminalizepool(LAWFLAG_BURNFLAG, -1, activesquad->squad[0]->base);
	}
	if (sieged)
	{  //PUBLICITY IF BURN FLAG DURING SIEGE ESPECIALLY IF IT IS REALLY ILLEGAL
		change_public_opinion(VIEW_LIBERALCRIMESQUAD, 1);
		change_public_opinion(VIEW_FREESPEECH, 1, 1, 30);
		if (lawList[LAW_FLAGBURNING] <= 0)
		{
			change_public_opinion(VIEW_LIBERALCRIMESQUAD, 1);
			change_public_opinion(VIEW_FREESPEECH, 1, 1, 50);
		}
		if (lawList[LAW_FLAGBURNING] <= -1)
		{
			change_public_opinion(VIEW_LIBERALCRIMESQUAD, 5);
			change_public_opinion(VIEW_FREESPEECH, 2, 1, 70);
		}
		if (lawList[LAW_FLAGBURNING] == -2)
		{
			change_public_opinion(VIEW_LIBERALCRIMESQUAD, 15);
			change_public_opinion(VIEW_FREESPEECH, 5, 1, 90);
		}
	}
}
int countSafeHouses();
Location* getLocation();
void equipLoot(int l, int loc);
bool isThisSafehouse(int loc);
bool cannotWaitDuringSiege() {
	extern vector<DeprecatedCreature *> pool;

	// Count people at each location
	int* num_present = new int[LocationsPool::getInstance().lenpool()];
	for (int i = 0; i < LocationsPool::getInstance().lenpool(); i++) num_present[i] = 0;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{  // Dead people, non-liberals, and vacationers don't count
		if (!pool[p]->getCreatureHealth().alive || pool[p]->getCreatureHealth().align != 1 || pool[p]->location == -1) continue;
		num_present[pool[p]->location]++;
	}

	char cannotwait = 0;
	for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
	{
		if (!LocationsPool::getInstance().isThereASiegeHere(l)) continue;
		if (LocationsPool::getInstance().isThisUnderAttack(l))
		{
			// Allow siege if no liberals present
			if (num_present[l])cannotwait = 1;
			break;
		}
	}

	delete[] num_present;

	return cannotwait;
}
void pressedKeyWInBaseMode(const char forcewait, const char canseethings, int &nonsighttime) {
	const string CONST_basemode063 = "Time passes...";
	extern int day;
	extern int month;
	extern int year;
	extern Log gamelog;

	char clearformess = forcewait;
	if (!canseethings) nonsighttime++;
	advanceday(clearformess, canseethings);
	if (day > monthday()) passmonth(clearformess, canseethings);
	advancelocations();
	if (forcewait&&day == 1)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(7, 5, CONST_basemode063, gamelog);
		mvaddstrAlt(9, 12, getmonth(month, true) + singleSpace, gamelog);
		mvaddstrAlt(9, 17, tostring(day) + commaSpace, gamelog);
		mvaddstrAlt(9, 21, year, gamelog);
		gamelog.nextMessage(); //Write out buffer to prepare for the next message.
		refreshAlt();
	}
}
void pressedKeyPInBaseMode(const char haveflag, const char sieged, Location *loc) {
	extern class Ledger ledger;
	extern int stat_buys;
	extern int stat_burns;
	if (haveflag) {
		burnflag();
		stat_burns++;
		politicalEffectsOfFlagBurning(sieged);
	}
	else if (ledger.get_funds() >= 20 && !sieged&&loc) {
		ledger.subtract_funds(20, EXPENSE_COMPOUND);
		if (loc) loc->haveflag = 1;
		stat_buys++;
	}
}
int lenVehiclePool();
bool iterate_mode_base(int &nonsighttime, int &oldforcemonth) {

	// FIXME This while(true) loop does not have an exit point  It relies on end_game(); to be called at some point
	// Unless the player presses 'x', at which point this function 'return's

	extern char cantseereason;
	extern char disbanding;
	extern Deprecatedsquadst *activesquad;
	extern Log gamelog;
	extern MusicClass music;
	extern int selectedsiege;
	extern short party_status;
	extern string slogan_str;
	extern vector<Deprecatedsquadst *> squad;
	char forcewait = 1;
	char canseethings = 0;
	cantseereason = CANTSEE_OTHER;
	if (disbanding)
	{
		cantseereason = CANTSEE_DISBANDING;
		disbanding = show_disbanding_screen(oldforcemonth);
	}
	else
	{
		findCantSeeReason(canseethings, forcewait);

	}
	if (!forcewait)
	{
		printIfLongWait(nonsighttime);
		nonsighttime = 0;
	}
	int partysize = activesquadSize();
	if (activesquad && !partysize)
	{
		delete_and_remove(squad, getsquad(activesquad->id));
		activesquad = NULL;
	}
	int safenumber = countSafeHouses();
	Location *loc = getLocation();
	siegest *siege = NULL;
	if (loc) siege = &loc->siege;
	char sieged = 0, underattack = 0;
	if (siege) sieged = siege->siege;
	if (sieged)
	{
		underattack = siege->underattack;
		if (!forcewait) music.play(MUSIC_SIEGE);
		else music.play(MUSIC_DISBANDED);
	}
	else if (!forcewait) music.play(MUSIC_BASEMODE);
	else music.play(MUSIC_DISBANDED);
	char haveflag = 0;
	if (loc) haveflag = loc->haveflag;

	char cannotwait = cannotWaitDuringSiege();

	if (!forcewait) {

		dontForceWait(sieged, underattack,
			haveflag,
			loc,
			safenumber,
			partysize);
		stillDontForceWait(sieged, cannotwait,
			haveflag,
			partysize);
	}
	int c = forcewait ? 'w' : getkeyAlt();
	switch (c) {
	case 'x': return false;

	case 'v': if (lenVehiclePool() && partysize) {
		short ops = party_status;
		party_status = -1;
		setvehicles();
		party_status = ops;
	} break;
	case 'g': if (sieged) { giveup(); cleangonesquads(); } break;
	case 'f': if (!sieged&&partysize > 0) stopevil();
			  else if (underattack) { escape_engage(); cleangonesquads(); }
			  else if (sieged) { sally_forth(); cleangonesquads(); } break;
	case 'z': if (safenumber) {
		activesquad = NULL;
		for (int l = (selectedsiege == -1 || selectedsiege + 1 >= LocationsPool::getInstance().lenpool()) ? 0 : selectedsiege + 1;
			l < LocationsPool::getInstance().lenpool(); l++)
			if (isThisSafehouse(l)) { selectedsiege = l; break; }
			else if (l == LocationsPool::getInstance().lenpool() - 1) l = -1;
	} break;
	case 'e': if (partysize && !underattack&&activesquad->squad[0]->location != -1) {
		short ops = party_status;
		party_status = -1;
		equipLoot(activesquad->squad[0]->location, -1);
		party_status = ops;
	} break;
	case 'o': if (partysize > 1) orderparty(); break;
	case 'c': if (partysize) activesquad->activity.type = ACTIVITY_NONE; break;
	case 'p':
		pressedKeyPInBaseMode(haveflag, sieged, loc);
		break;
	case 'w': if (forcewait || !cannotwait) {
		pressedKeyWInBaseMode(forcewait, canseethings, nonsighttime);
	} break;
	default:
		pressedThisKeyInBaseMode(c);
		break;

	}
	return true;
}
void mode_base()
{
	extern int month;
	int nonsighttime = 0, oldforcemonth = month;
	// FIXME This while(true) loop does not have an exit point  It relies on end_game(); to be called at some point
	// Unless the player presses 'x', at which point this function 'return's
	while (iterate_mode_base(nonsighttime, oldforcemonth))
	{
		;
	}
}
