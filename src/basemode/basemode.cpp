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

#include "common/ledger.h"

#include "vehicle/vehicle.h"

#include "basemode/liberalagenda.h"
// for liberalagenda

#include "basemode/baseactions.h"

#include "basemode/activate_sleepers.h"

#include "basemode/activate.h"
// for activate

#include "basemode/reviewmode.h"
// for review

#include "common/translateid.h"
// for  int getsquad(int)

#include "common/consolesupport.h"
// for void set_color(short,short,bool)

#include "common/getnames.h"
// for std::string getmonth(int)

#include "log/log.h"
// for commondisplay.h
#include "common/commondisplay.h"
//for int mvaddstr(int, int, const char*)

#include "common/commonactions.h"
// for int squadsize(const squadst *)

#include "common/equipment.h"
//for void equip(vector<Item *>&,int)

#include "politics/politics.h"
//for bool stalinview(short view,bool islaw)

#include "monthly/monthly.h"
//for  void passmonth(char &clearformess,char canseethings);

#include "daily/daily.h"
//for int monthday();

#include "daily/siege.h"
//for giveup()



#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
extern vector<Creature *> pool;
extern vector<Location *> location;
extern Log gamelog;
extern MusicClass music;
extern int stat_buys;
extern int stat_burns;
extern int year;
extern short exec[EXECNUM];
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern int month;
extern int disbandtime;
 string tag_Sta;
 string tag_Libp;
 string tag_Lib;
 string tag_Mod;
 string tag_Cons;
 string tag_Consp;
 extern string commaSpace;
 extern string singleSpace;
 extern short execterm;
 extern short house[HOUSENUM];
 extern short senate[SENATENUM];
extern short court[COURTNUM];
 extern bool stalinmode;
 extern short lawList[LAWNUM];
 extern short attitude[VIEWNUM];
 extern char cantseereason;
 extern char disbanding;
 extern vector<squadst *> squad;
extern squadst *activesquad;
extern int selectedsiege;
extern vector<Vehicle *> vehicle;
extern class Ledger ledger;
extern int day;
extern char slogan[SLOGAN_LEN];
extern short party_status;

bool show_disbanding_screen(int& oldforcemonth)
{
	if (oldforcemonth == month) return true;
	music.play(MUSIC_DISBANDED);
	for (int p = len(pool) - 1; p >= 0; p--)
	{
		int targetjuice = LCSrandom(100 * (year - disbandtime + 1));
		if (targetjuice > 1000) targetjuice = 1000;
		if (pool[p]->juice < targetjuice&&pool[p]->hireid != -1 && !(pool[p]->flag&CREATUREFLAG_SLEEPER))
			pool[p]->alive = 0; // Kill for the purposes of disbanding all contacts below
	}
	oldforcemonth = month;
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(0,  0, getmonth(month) + singleSpace);
	addstrAlt(year);
	signed char align = exec[EXEC_PRESIDENT];
	set_alignment_color(align, true);
	mvaddstrAlt(1,  0, "President: ");
	addstrAlt(execname[EXEC_PRESIDENT]); addstrAlt(commaSpace);
	addstrAlt(getalign(align));
	if (execterm == 1)addstrAlt(", 1st Term");
	else addstrAlt(", 2nd Term");
	int housemake[6] = { 0,0,0,0,0,0 };
	for (int h = 0; h < HOUSENUM; h++) housemake[house[h] + 2]++;
	if (housemake[5] + min(housemake[0], housemake[4]) >= HOUSEMAJORITY) align = ALIGN_STALINIST; // Stalinists have a majority (perhaps with help from extremists on both sides)
	else if (housemake[0] >= HOUSEMAJORITY) align = ALIGN_ARCHCONSERVATIVE; // Arch-Conservatives have a majority
	else if (housemake[4] >= HOUSEMAJORITY) align = ALIGN_ELITELIBERAL; // Elite Liberals have a majority
	else if (housemake[0] + housemake[1] >= HOUSEMAJORITY) align = ALIGN_CONSERVATIVE; // Conservatives plus Arch-Conservatives have a majority
	else if (housemake[3] + housemake[4] >= HOUSEMAJORITY) align = ALIGN_LIBERAL; // Liberals plus Elite Liberals have a majority
	else align = ALIGN_MODERATE; // nobody has a majority
	set_alignment_color(align, true);
	mvaddstrAlt(2, 0, "House: ");
	if (stalinmode) addstrAlt(tostring(housemake[5]) + tag_Sta);
	addstrAlt(tostring(housemake[4]) + tag_Libp);
	addstrAlt(tostring(housemake[3]) + tag_Lib);
	addstrAlt(tostring(housemake[2]) + tag_Mod);
	addstrAlt(tostring(housemake[1]) + tag_Cons);
	addstrAlt(tostring(housemake[0]) + tag_Consp);
	int senatemake[6] = { 0,0,0,0,0,0 };
	for (int s = 0; s < SENATENUM; s++) senatemake[senate[s] + 2]++;
	senatemake[exec[EXEC_VP] + 2]++; // Vice President is tie-breaking vote in the Senate
	if (senatemake[5] + min(senatemake[0], senatemake[4]) >= SENATEMAJORITY) align = ALIGN_STALINIST; // Stalinists have a majority (perhaps with help from extremists on both sides)
	else if (senatemake[0] >= SENATEMAJORITY) align = ALIGN_ARCHCONSERVATIVE; // Arch-Conservatives have a majority
	else if (senatemake[4] >= SENATEMAJORITY) align = ALIGN_ELITELIBERAL; // Elite Liberals have a majority
	else if (senatemake[0] + senatemake[1] >= SENATEMAJORITY) align = ALIGN_CONSERVATIVE; // Conservatives plus Arch-Conservatives have a majority
	else if (senatemake[3] + senatemake[4] >= SENATEMAJORITY) align = ALIGN_LIBERAL; // Liberals plus Elite Liberals have a majority
	else align = ALIGN_MODERATE; // nobody has a majority
	set_alignment_color(align, true);
	senatemake[exec[EXEC_VP] + 2]--; // Vice President isn't actually a Senator though
	mvaddstrAlt(3, 0, "Senate: ");
	if (stalinmode) addstrAlt(tostring(senatemake[5]) + tag_Sta);
	addstrAlt(tostring(senatemake[4]) + tag_Libp);
	addstrAlt(tostring(senatemake[3]) + tag_Lib);
	addstrAlt(tostring(senatemake[2]) + tag_Mod);
	addstrAlt(tostring(senatemake[1]) + tag_Cons);
	addstrAlt(tostring(senatemake[0]) + tag_Consp);
	int courtmake[6] = { 0,0,0,0,0,0 };
	for (int s = 0; s < COURTNUM; s++) courtmake[court[s] + 2]++;
	if (courtmake[5] + min(courtmake[0], courtmake[4]) >= COURTMAJORITY) align = ALIGN_STALINIST; // Stalinists have a majority (perhaps with help from extremists on both sides)
	else if (courtmake[0] >= COURTMAJORITY) align = ALIGN_ARCHCONSERVATIVE; // Arch-Conservatives have a majority
	else if (courtmake[4] >= COURTMAJORITY) align = ALIGN_ELITELIBERAL; // Elite Liberals have a majority
	else if (courtmake[0] + courtmake[1] >= COURTMAJORITY) align = ALIGN_CONSERVATIVE; // Conservatives plus Arch-Conservatives have a majority
	else if (courtmake[3] + courtmake[4] >= COURTMAJORITY) align = ALIGN_LIBERAL; // Liberals plus Elite Liberals have a majority
	else align = ALIGN_MODERATE; // nobody has a majority
	set_alignment_color(align, true);
	mvaddstrAlt(4, 0, "Supreme Court: ");
	if (stalinmode) addstrAlt(tostring(courtmake[5]) + tag_Sta);
	addstrAlt(tostring(courtmake[4]) + tag_Libp);
	addstrAlt(tostring(courtmake[3]) + tag_Lib);
	addstrAlt(tostring(courtmake[2]) + tag_Mod);
	addstrAlt(tostring(courtmake[1]) + tag_Cons);
	addstrAlt(tostring(courtmake[0]) + tag_Consp);
	for (int l = 0; l < LAWNUM; l++)
	{
		align = lawList[l];
		set_alignment_color(align, true);
		mvaddstrAlt(6 + l / 3, l % 3 * 30, getlaw(l));
	}
	if (stalinmode)
	{
		int stalin = 0; // the Stalinist mood position from 1 to 78 (left=Stalinist, right=Libertarian)
		for (int v = 0; v < VIEWNUM - 3; v++)
			stalin += stalinview(v, false) ? attitude[v] : 100 - attitude[v];
		stalin = 78 - (stalin * 77) / ((VIEWNUM - 3) * 100); // very accurate Stalinist mood positioning!
		if (stalin >= 64) align = ALIGN_ELITELIBERAL;
		else if (stalin >= 48) align = ALIGN_LIBERAL;
		else if (stalin >= 32) align = ALIGN_MODERATE;
		else if (stalin >= 16) align = ALIGN_CONSERVATIVE;
		else align = ALIGN_ARCHCONSERVATIVE;
		set_alignment_color(align, true);
		mvaddstrAlt(17, 33, "Public Mood");
		set_color_easy(RED_ON_BLACK_BRIGHT);
		mvaddstrAlt(17,  1, "Stalinist");
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		mvaddstrAlt(17, 68, "Libertarian");
		set_color_easy(RED_ON_BLACK_BRIGHT);
		mvaddstrAlt(18, 0, "\x11ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
		set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
		mvaddstrAlt(18, 16, "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
		set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		mvaddstrAlt(18, 32, "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		mvaddstrAlt(18, 48, "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		mvaddstrAlt(18, 64, "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\x10");
		set_alignment_color(align, true);
		mvaddcharAlt(18, stalin, 'O');
	}
	int mood = 0; // the mood position from 1 to 78 (left=left-wing, right=right-wing)
	for (int v = 0; v < VIEWNUM - 3; v++) mood += attitude[v];
	mood = 78 - (mood * 77) / ((VIEWNUM - 3) * 100); // very accurate mood positioning!
	if (mood >= 64) align = ALIGN_ARCHCONSERVATIVE;
	else if (mood >= 48) align = ALIGN_CONSERVATIVE;
	else if (mood >= 32) align = ALIGN_MODERATE;
	else if (mood >= 16) align = ALIGN_LIBERAL;
	else align = ALIGN_ELITELIBERAL;
	set_alignment_color(align, true);
	mvaddstrAlt(stalinmode ? 21 : 20, 33, "Public Mood");
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(21, 1, "Liberal");
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(21, 67, "Conservative");
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(22, 0, "\x11ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(22, 16, "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	set_color_easy(YELLOW_ON_BLACK_BRIGHT);
	mvaddstrAlt(22, 32, "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
	mvaddstrAlt(22, 48, "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(22, 64, "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\x10");
	set_alignment_color(align, true);
	mvaddcharAlt(22, mood, 'O');
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(24, 0, "R - Recreate the Liberal Crime Squad                  Any Other Key - Next Month");
	return(getkey() != 'r');
}
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
void mode_base()
{
	char forcewait, canseethings;
	int nonsighttime = 0, oldforcemonth = month, l = 0;
	while (true)
	{
		forcewait = 1, canseethings = 0, cantseereason = CANTSEE_OTHER;
		if (disbanding)
		{
			cantseereason = CANTSEE_DISBANDING;
			disbanding = show_disbanding_screen(oldforcemonth);
		}
		else
		{
			for (int p = 0; p<len(pool); p++)
			{
				if (pool[p]->alive&&
					pool[p]->align == 1 &&
					pool[p]->dating == 0 &&
					pool[p]->hiding == 0 &&
					!(pool[p]->flag & CREATUREFLAG_SLEEPER))
				{
					if (!location[pool[p]->location]->part_of_justice_system())
					{
						canseethings = 1;
						if (pool[p]->clinic == 0) { forcewait = 0; break; }
					}
				}
				else
				{
					if (pool[p]->dating == 1 && cantseereason>CANTSEE_DATING) cantseereason = CANTSEE_DATING;
					else if (pool[p]->hiding != 0 && cantseereason > CANTSEE_HIDING) cantseereason = CANTSEE_HIDING;
				}
			}
		}
		if (!forcewait)
		{
			if (nonsighttime >= 365 * 4)
			{
				music.play(MUSIC_BASEMODE);
				eraseAlt();
				char str[100];
				if (nonsighttime >= 365 * 16)
					strcpy(str, "How long since you've heard these sounds...  times have changed.");
				else if (nonsighttime >= 365 * 8)
					strcpy(str, "It has been a long time.  A lot must have changed...");
				else strcpy(str, "It sure has been a while.  Things might have changed a bit.");
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrCenter(12, str, gamelog);
				gamelog.nextMessage(); //Write out buffer to prepare for the next message.
				getkey();
			}
			nonsighttime = 0;
		}
		int partysize = squadsize(activesquad);
		if (activesquad&&!partysize)
		{
			delete_and_remove(squad, getsquad(activesquad->id));
			activesquad = NULL;
		}
		int safenumber = 0;
		for (l = 0; l < len(location); l++) if (location[l]->is_lcs_safehouse()) safenumber++;
		Location *loc = NULL;
		if (selectedsiege != -1) loc = location[selectedsiege];
		if (activesquad) if (activesquad->squad[0]->location != -1)
			loc = location[activesquad->squad[0]->location];
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
		// Count people at each location
		int* num_present = new int[len(location)];
		for (int i = 0; i < len(location); i++) num_present[i] = 0;
		for (int p = 0; p < len(pool); p++)
		{  // Dead people, non-liberals, and vacationers don't count
			if (!pool[p]->alive || pool[p]->align != 1 || pool[p]->location == -1) continue;
			num_present[pool[p]->location]++;
		}
		char cannotwait = 0;
		for (l = 0; l < len(location); l++)
		{
			if (!location[l]->siege.siege) continue;
			if (location[l]->siege.underattack)
			{
				// Allow siege if no liberals present
				if (num_present[l])cannotwait = 1;
				break;
			}
		}
		delete[] num_present;
		if (!forcewait)
		{
			eraseAlt();
			if (activesquad != NULL) selectedsiege = -1;
			locheader();
			if (selectedsiege != -1)
			{
				printlocation(selectedsiege);
				if (location[selectedsiege]->can_be_upgraded() &&
					!location[selectedsiege]->siege.siege)
				{
					set_color_easy(WHITE_ON_BLACK);
					mvaddstrAlt(8, 1, "I - Invest in this location");
				}
			}
			else if (activesquad != NULL) printparty();
			else makedelimiter();
			if (sieged)
			{
				if (underattack)
				{
					set_color_easy(RED_ON_BLACK_BRIGHT);
					mvaddstrAlt(8, 1, "Under Attack");
				}
				else
				{
					set_color_easy(YELLOW_ON_BLACK_BRIGHT);
					mvaddstrAlt(8, 1, "Under Siege");
					int stock = 1;
					if (loc)stock = loc->compound_stores;
					if (!stock)addstrAlt(" (No Food)");
				}
			}
			if (haveflag) for (int y = 0; y < 7; y++)
			{
				if (y < 6)
				{
					set_color(COLOR_WHITE, y < 4 ? COLOR_BLUE : COLOR_RED, 1);
					if (y == 0) mvaddstrAlt(y + 10, 31, ":.:.:.:.:");
					else if (y < 3) mvaddstrAlt(y + 10, 31, ":::::::::");
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
			mvaddstrAlt(18, 10, "ÄÄÄ ACTIVISM ÄÄÄ");
			mvaddstrAlt(18, 51, "ÄÄÄ PLANNING ÄÄÄ");
			if (partysize&&!underattack) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(19, 40, "E - Equip Squad");
			if (len(vehicle) && partysize) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(19, 60, "V - Vehicles");
			if (len(pool)) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(20, 40, "R - Review Assets and Form Squads");
			if (partysize > 1) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			if (partysize&&!sieged) mvaddstrAlt(8, 30, "O - Reorder");
			if (activesquad&&!sieged) // don't cover up info about siege with irrelevant squad name of a squad that will be disbanded during the siege anyway
			{
				set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(8, 1, activesquad->name);
				addchAlt(CH_BOX_DRAWINGS_LIGHT_HORIZONTAL); //in case of overlap, at least make it clear where the name ends.
			}
			if (len(squad) > 1 || (!activesquad&&len(squad))) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 43, "TAB - Next Squad");
			if (safenumber > 0) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 62, "Z - Next Location");
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(21, 40, "L - The Status of the Liberal Agenda");
			set_color_easy(BLACK_ON_BLACK_BRIGHT);
			for (int p = 0; p < len(pool); p++) if (pool[p]->is_active_liberal())
			{
				if (pool[p]->squadid != -1)
				{
					int sq = getsquad(pool[p]->squadid);
					if (sq != -1) if (squad[sq]->activity.type != ACTIVITY_NONE) continue;
				}
				set_color_easy(WHITE_ON_BLACK);
				break;
			}
			mvaddstrAlt(21, 1, "A - Activate Liberals");
			set_color_easy(BLACK_ON_BLACK_BRIGHT);
			for (int p = 0; p < len(pool); p++)
				if (pool[p]->is_lcs_sleeper())
				{
					set_color_easy(WHITE_ON_BLACK);
					break;
				}
			mvaddstrAlt(21, 25, "B - Sleepers");
			if (partysize)
			{
				if (activesquad->activity.type != ACTIVITY_NONE) set_color_easy(WHITE_ON_BLACK);
				else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			}
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(20, 1, "C - Cancel this Squad's Departure");
			if (sieged)
			{
				if (partysize) set_color_easy(WHITE_ON_BLACK);
				else
				{
					set_color_easy(BLACK_ON_BLACK_BRIGHT);
					for (int p = 0; p < len(pool); p++)
					{
						if (pool[p]->location == selectedsiege)
						{
							set_color_easy(WHITE_ON_BLACK);
							break;
						}
					}
				}
				mvaddstrAlt(19, 1, "F - Escape/Engage");
				set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(19, 23, "G - Give Up");
			}
			else
			{
				if (partysize) set_color_easy(WHITE_ON_BLACK);
				else set_color_easy(BLACK_ON_BLACK_BRIGHT);
				mvaddstrAlt(19, 1, "F - Go forth to stop EVIL");
			}
			//if(partysize>0&&(party_status==-1||partysize>1))set_color_easy(WHITE_ON_BLACK);
			//else set_color(COLOR_BLACK,COLOR_BLACK,1);
			//mvaddstrAlt(19,40,check_status_of_squad_liberal);
			//if(party_status!=-1)set_color_easy(WHITE_ON_BLACK);
			//else set_color(COLOR_BLACK,COLOR_BLACK,1);
			//mvaddstrAlt(18,40,show_squad_liberal_status);
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(23, 40, "X - Live to fight EVIL another day");
			set_color_easy(WHITE_ON_BLACK);
			if (cannotwait) mvaddstrAlt(23, 1, "Cannot Wait until Siege Resolved");
			else
			{
				if (sieged) mvaddstrAlt(23, 1, "W - Wait out the siege");
				else mvaddstrAlt(23, 1, "W - Wait a day");
				if (day == monthday()) addstrAlt(" (next month)");
			}
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(22, 40, "S - FREE SPEECH: the Liberal Slogan");
			if (haveflag)
			{
				if (sieged) set_color_easy(GREEN_ON_BLACK_BRIGHT);
				else set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(22, 1, "P - PROTEST: burn the flag");
			}
			else
			{
				if (ledger.get_funds() >= 20 && !sieged && (selectedsiege != -1 || activesquad != NULL))
					set_color_easy(WHITE_ON_BLACK);
				else set_color_easy(BLACK_ON_BLACK_BRIGHT);
				mvaddstrAlt(22, 1, "P - PATRIOTISM: fly a flag here ($20)");
			}
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			if (haveflag) mvaddstrCenter(17, slogan);
			else mvaddstrCenter(13, slogan);
		}
		switch (int c = forcewait ? 'w' : getkey())
		{
		case 'x': return;
		case 'i': if (selectedsiege != -1)
			if (location[selectedsiege]->can_be_upgraded() && !location[selectedsiege]->siege.siege)
				investlocation(); break;
		case 'l': disbanding = liberalagenda(0); break;
		case 'g': if (sieged) { giveup(); cleangonesquads(); } break;
		case 'f': if (!sieged&&partysize > 0) stopevil();
				  else if (underattack) { escape_engage(); cleangonesquads(); }
				  else if (sieged) { sally_forth(); cleangonesquads(); } break;
		case 'o': if (partysize > 1) orderparty(); break;
		case 'c': if (partysize) activesquad->activity.type = ACTIVITY_NONE; break;
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
		case 'z': if (safenumber) {
			activesquad = NULL;
			for (int l = (selectedsiege == -1 || selectedsiege + 1 >= len(location)) ? 0 : selectedsiege + 1;
			l<len(location); l++)
				if (location[l]->is_lcs_safehouse()) { selectedsiege = l; break; }
				else if (l == len(location) - 1) l = -1;
		} break;
		case 'e': if (partysize&&!underattack&&activesquad->squad[0]->location != -1) {
			short ops = party_status;
			party_status = -1;
			equip(location[activesquad->squad[0]->location]->loot, -1);
			party_status = ops;
		} break;
		case 'r': if (len(pool)) review(); break;
		case 'w': if (forcewait || !cannotwait) {
			char clearformess = forcewait;
			if (!canseethings) nonsighttime++;
			advanceday(clearformess, canseethings);
			if (day>monthday()) passmonth(clearformess, canseethings);
			advancelocations();
			if (forcewait&&day == 1)
			{
				eraseAlt();
				set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(7, 5, "Time passes...", gamelog);
				mvaddstrAlt(9, 12, getmonth(month, true) + singleSpace, gamelog);
				mvaddstrAlt(9, 17, tostring(day) + commaSpace, gamelog);
				mvaddstrAlt(9, 21, year, gamelog);
				gamelog.nextMessage(); //Write out buffer to prepare for the next message.
				refreshAlt();
			}
		} break;
		case 'v': if (len(vehicle) && partysize) {
			short ops = party_status;
			party_status = -1;
			setvehicles();
			party_status = ops;
		} break;
		case 'p': if (haveflag) {
			burnflag();
			stat_burns++;
			if (selectedsiege != -1)
			{
				location[selectedsiege]->haveflag = 0;
				if (lawList[LAW_FLAGBURNING] < 1)
					criminalizepool(LAWFLAG_BURNFLAG, -1, selectedsiege);
			}
			if (activesquad)
			{
				location[activesquad->squad[0]->base]->haveflag = 0;
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
				  else if (ledger.get_funds() >= 20 && !sieged&&loc) {
					  ledger.subtract_funds(20, EXPENSE_COMPOUND);
					  if (loc) loc->haveflag = 1;
					  stat_buys++;
				  } break;
		case 's': getslogan(); break;
		case '0': party_status = -1; break;
		case '1': case '2': case '3': case '4': case '5': case '6':
			if (activesquad) if (activesquad->squad[c - '1']) {
				if (party_status == c - '1') fullstatus(party_status);
				else party_status = c - '1';
			} break;
		}
	}
}

