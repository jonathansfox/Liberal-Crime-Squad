
#include "../includes.h"
const string CONST_monthlyB015 = "C++ Source Code Editor (with encoding)";
const string CONST_monthly017 = "They will never see the utopia they dreamed of...";
const string CONST_monthly016 = "The last LCS members have all been hunted down.";
const string CONST_monthly015 = "The Liberal Crime Squad is now just a memory.";
const string CONST_monthly014 = "Press any key to reflect on these poll numbers.";
const string CONST_monthly013 = "Arch-Conservative";
const string CONST_monthly012 = "-  ";
const string CONST_monthly011 = "Conservative  ";
const string CONST_monthly009 = "moderate  ";
const string CONST_monthly007 = "Liberal  ";
const string CONST_monthly005 = "Elite Liberal ";
const string CONST_monthly004 = "ÄÄÄ";
const string CONST_monthly003 = "CURRENT POLITICAL TRENDS";
const string CONST_monthly002 = "LCS MONTHLY INTELLIGENCE REPORT";
const string CONST_monthly001 = "OEM United States - Codepage 437";
const string CONST_monthly000 = "Open With...";
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
// select CONST_monthly000, choose CONST_monthlyB015,
// then choose CONST_monthly001.
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

#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../basemode/liberalagenda.h"
// for liberalagenda
//#include "../items/itemPool.h"
//#include "../items/lootTypePool.h"
//#include "../common/commonactions.h"
char endcheck(char cause);
void change_public_opinion(int v, int power, char affect = 1, char cap = 100);
#include "../log/log.h"
#include "../common/commondisplay.h"
// for set_alignment_color and delimiter
#include "../common/translateid.h"
// for  int getpoolcreature(int id);
#include "../title/titlescreen.h"
// for void reset;
#include "../title/highscore.h"
// for viewhighscores, in event of EndGameStatus
#include "../politics/politics.h"
//for publicmood
//#include "../monthly/lcsmonthly.h"
void fundreport(char &clearformess);
//#include "../daily/daily.h"
//for dispersalcheck and securitytable
void dispersalcheck(char &clearformess);
#include "../cursesAlternative.h"
#include "../set_color_support.h"
//#include <common\\getnames.h>
std::string getview(short view, bool shortname);
#include "../locations/locationsPool.h"
#include "../locations/locationsEnums.h"
#include "../common/creaturePool.h"
#include "../common/creaturePoolHeader.h"
/* end the game and clean up */
void end_game(int err = EXIT_SUCCESS);
void clearRentExemptions();
void publishSpecialEditions(char &clearformess);
void manageGrafiti();

extern string singleDot;

#include "../common/musicClass.h"
/* rename various buildings according to the new laws */
void updateworld_laws(short *law, short *oldlaw)
{  // NOTE: make sure to keep code here matching code in initlocation() in locations.cpp for when names are changed
	if (((law[LAW_POLICEBEHAVIOR] == -2 && law[LAW_DEATHPENALTY] == -2) ||
		(oldlaw[LAW_POLICEBEHAVIOR] == -2 && oldlaw[LAW_DEATHPENALTY] == -2)) &&
		(law[LAW_POLICEBEHAVIOR] != oldlaw[LAW_POLICEBEHAVIOR] ||
			law[LAW_DEATHPENALTY] != oldlaw[LAW_DEATHPENALTY]))
		for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
			if (LocationsPool::getInstance().getLocationType(l) == SITE_GOVERNMENT_POLICESTATION) // Police Station or Death Squad HQ?
				LocationsPool::getInstance().initSite(l);
	if ((law[LAW_DEATHPENALTY] == -2 || oldlaw[LAW_DEATHPENALTY] == -2) &&
		law[LAW_DEATHPENALTY] != oldlaw[LAW_DEATHPENALTY])
		for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
			if (LocationsPool::getInstance().getLocationType(l) == SITE_GOVERNMENT_COURTHOUSE) // Courthouse or judge hall?
				LocationsPool::getInstance().initSite(l);
	if ((law[LAW_FREESPEECH] == -2 || oldlaw[LAW_FREESPEECH] == -2) &&
		law[LAW_FREESPEECH] != oldlaw[LAW_FREESPEECH])
		for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
			if (LocationsPool::getInstance().getLocationType(l) == SITE_GOVERNMENT_FIRESTATION) // Fire station or Fireman HQ?
				LocationsPool::getInstance().initSite(l);
	if ((law[LAW_PRISONS] == -2 || oldlaw[LAW_PRISONS] == -2) &&
		law[LAW_PRISONS] != oldlaw[LAW_PRISONS])
		for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
			if (LocationsPool::getInstance().getLocationType(l) == SITE_GOVERNMENT_PRISON) // Prison or re-ed camp?
				LocationsPool::getInstance().initSite(l);
	if ((law[LAW_NUCLEARPOWER] == 2 || oldlaw[LAW_NUCLEARPOWER] == 2) &&
		law[LAW_NUCLEARPOWER] != oldlaw[LAW_NUCLEARPOWER])
		for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
			if (LocationsPool::getInstance().getLocationType(l) == SITE_INDUSTRY_NUCLEAR) // Nuclear Power Plant, or Nuclear Waste Center?
				LocationsPool::getInstance().initSite(l);
	if (((law[LAW_PRIVACY] == -2 && law[LAW_POLICEBEHAVIOR] == -2) ||
		(oldlaw[LAW_PRIVACY] == -2 && oldlaw[LAW_POLICEBEHAVIOR] == -2)) &&
		(law[LAW_PRIVACY] != oldlaw[LAW_PRIVACY] ||
			law[LAW_POLICEBEHAVIOR] != oldlaw[LAW_POLICEBEHAVIOR]))
		for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
			if (LocationsPool::getInstance().getLocationType(l) == SITE_GOVERNMENT_INTELLIGENCEHQ) // Intelligence HQ or ministry of love?
				LocationsPool::getInstance().initSite(l);
	if ((law[LAW_MILITARY] == -2 || oldlaw[LAW_MILITARY] == -2) &&
		law[LAW_MILITARY] != oldlaw[LAW_MILITARY])
		for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
			if (LocationsPool::getInstance().getLocationType(l) == SITE_GOVERNMENT_ARMYBASE) // Army Base or Ministry of Peace?
				LocationsPool::getInstance().initSite(l);
	if ((law[LAW_GUNCONTROL] == 2 || oldlaw[LAW_GUNCONTROL] == 2) &&
		law[LAW_GUNCONTROL] != oldlaw[LAW_GUNCONTROL])
		for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
			if (LocationsPool::getInstance().getLocationType(l) == SITE_BUSINESS_PAWNSHOP) // Do they mention guns in the title?
				LocationsPool::getInstance().initSite(l);
	if (((law[LAW_CORPORATE] == -2 && law[LAW_TAX] == -2) ||
		(oldlaw[LAW_CORPORATE] == -2 && oldlaw[LAW_TAX] == -2)) &&
		(law[LAW_CORPORATE] != oldlaw[LAW_CORPORATE] ||
			law[LAW_TAX] != oldlaw[LAW_TAX]))
		for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
			if (LocationsPool::getInstance().getLocationType(l) == SITE_CORPORATE_HOUSE) // CEO house or CEO Castle?
				LocationsPool::getInstance().initSite(l);
	if ((law[LAW_DRUGS] == 2 || oldlaw[LAW_DRUGS] == 2) &&
		law[LAW_DRUGS] != oldlaw[LAW_DRUGS])
		for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
			if (LocationsPool::getInstance().getLocationType(l) == SITE_BUSINESS_CRACKHOUSE  // Crack House, or Recreational Drugs Center?
				&&LocationsPool::getInstance().getRentingType(l) < 0) // Only rename locations not under LCS control, to avoid switching names around under the player
				LocationsPool::getInstance().initSite(l);
}
/* does end of month actions */
void passmonth(char &clearformess, char canseethings)
{
	// Show polls when you can't see things
	extern bool SHOWWAIT;
	// Show die rolls, 100% accurate poll numbers
	extern bool SHOWMECHANICS;
	extern Log gamelog;
	extern MusicClass music;
	extern int year;
	extern char endgamestate;
	extern char newscherrybusted;
	extern int day;
	extern int month;
	extern char disbanding;
	extern bool stalinmode;
	extern int disbandtime;
	extern class Ledger ledger;
	extern short lawList[LAWNUM];
	extern short attitude[VIEWNUM];
	extern short public_interest[VIEWNUM];
	extern short background_liberal_influence[VIEWNUM];
	short oldlaw[LAWNUM];
	memmove(oldlaw, lawList, sizeof(short)*LAWNUM);
	int l, p;
	//TIME ADVANCE
	day = 1;
	month++;
	if (month == 13)
	{
		month = 1;
		year++;
	}
	switch (endgamestate)
	{
	case ENDGAME_NONE:
		if (publicmood(-1) > 60)
		{
			endgamestate = ENDGAME_CCS_APPEARANCE;
			attitude[VIEW_CONSERVATIVECRIMESQUAD] = 0;
		}
		break;
	case ENDGAME_CCS_APPEARANCE:
		if (publicmood(-1) > 80)
			endgamestate = ENDGAME_CCS_ATTACKS;
		break;
	case ENDGAME_CCS_ATTACKS:
		if (publicmood(-1) > 90)
			endgamestate = ENDGAME_CCS_SIEGES;
		break;
	case ENDGAME_CCS_SIEGES:
	case ENDGAME_CCS_DEFEATED:
		//if(publicmood(-1)>85&&presparty!=LIBERAL_PARTY)
		//   endgamestate=ENDGAME_MARTIALLAW;
		break;
	}
	//CLEAR RENT EXEMPTIONS
	clearRentExemptions();
	// Check for game over
	endcheck(END_DEAD);
	dispersalcheck(clearformess);
	if (!disbanding) {
		publishSpecialEditions(clearformess);
	}
	int libpower[VIEWNUM] = { 0 };
	//STORIES STALE EVEN IF NOT PRINTED
	for (int v = 0; v < VIEWNUM; v++)public_interest[v] /= 2;
	int conspower = 200 - attitude[VIEW_AMRADIO] - attitude[VIEW_CABLENEWS];
	//HAVING SLEEPERS
	havingSleepers(clearformess, canseethings, libpower);
	manageGrafiti();
	int mediabalance = 0;
	int issuebalance[VIEWNUM - 5];
	//int stimulus=0;
	//double cost=0;
	//double tax=0;
	//PUBLIC OPINION NATURAL MOVES
	for (int v = 0; v < VIEWNUM; v++)
	{
		// Liberal essays add their power to the effect of sleepers
		libpower[v] += background_liberal_influence[v];
		background_liberal_influence[v] = static_cast<short>(background_liberal_influence[v] * 0.66);
		if (v == VIEW_LIBERALCRIMESQUADPOS) continue;
		if (v == VIEW_LIBERALCRIMESQUAD) continue;
		//if(v==VIEW_POLITICALVIOLENCE)
		//{
		//   change_public_opinion(VIEW_POLITICALVIOLENCE,-1,0);
		//   continue;
		//}
		if (v == VIEW_CONSERVATIVECRIMESQUAD) continue;
		if (v != VIEW_AMRADIO&&v != VIEW_CABLENEWS)
		{
			issuebalance[v] = libpower[v] - conspower;
			mediabalance += issuebalance[v];
			// Heavy randomization -- balance of power just biases the roll
			int roll = issuebalance[v] + LCSrandom(400) - 200;
			// If +/-50 to either side, that side wins the tug-of-war
			if (roll < -50)
				change_public_opinion(v, -1, 0);
			else if (roll > 50)
				change_public_opinion(v, 1, 0);
			else // Else random movement
				change_public_opinion(v, LCSrandom(2) * 2 - 1, 0);
		}
		// AM Radio and Cable News popularity slowly shift to reflect public
		// opinion over time -- if left unchecked, their subtle influence
		// on society will become a self-perpetuating Conservative nightmare!
		else if (v == VIEW_AMRADIO || v == VIEW_CABLENEWS)
		{
			if (publicmood(-1) < attitude[v])change_public_opinion(v, -1);
			else change_public_opinion(v, 1);
		}
	}
	// Temporary Stalinizing Code (TODO: Implement the Stalinist Comrade Squad for changing public opinion, then remove this)
	if (stalinmode) for (int v = 0; v < VIEWNUM - 3; v++)
	{
		if (stalinview(v, false)) { if ((attitude[v] += 3)>100) attitude[v] = 100; }
		else { if (--attitude[v] < 0) attitude[v] = 0; }
	}
	// End Temporary Stalinizing Code (TODO: Implement the Stalinist Comrade Squad for changing public opinion, then remove this)
	// Seduction monthly experience stipends for those liberals
	// who have been getting it on with their love slaves/masters
	// in the background
	giveSeductionExperienceToLoveSlaves();
	/*******************************************************
	*                 INTELLIGENCE REPORT                  *
	*     ONLY IF SHOWMECHANICS OR SHOWWAIT IS DEFINED     *
	*        EYES ONLY - LCS PROPERTY - TOP SECRET         *
	*******************************************************/
	if (SHOWMECHANICS || SHOWWAIT)
		if (canseethings)
		{
			music.play(MUSIC_ELECTIONS);
			eraseAlt();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(0, 23, CONST_monthly002);
			mvaddstrAlt(2, 27, CONST_monthly003);
			int numviews = (endgamestate >= ENDGAME_CCS_DEFEATED || newscherrybusted < 2) ? VIEWNUM - 1 : VIEWNUM;
			for (int v = -1 - stalinmode, y = 4, x = 0, pip; v < numviews; v++)
			{
				if ((y - 4) * 2 >= numviews + 1 + stalinmode) y = 4, x = 40;
				for (pip = 2; pip >= -2; pip--)
				{
					set_alignment_color(pip, true);
					if (pip == 2) mvaddcharAlt(y, x + 22, '\x11');
					addstrAlt(CONST_monthly004);
					if (pip == -2) addcharAlt('\x10');
				}
				if (v >= 0) pip = 14 - (attitude[v] * 14) / 100;
				else pip = 14 - (publicmood(v) * 14) / 100;
				set_alignment_color((14 - pip) / 3 - 2, true);
				mvaddstrAlt(y, x, getview(v, false));
				mvaddcharAlt(y++, x + 23 + pip, 'O');
			}
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			mvaddstrAlt(23, 0, CONST_monthly005);
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt(CONST_monthly012);
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			addstrAlt(CONST_monthly007);
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt(CONST_monthly012);
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			addstrAlt(CONST_monthly009);
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt(CONST_monthly012);
			set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
			addstrAlt(CONST_monthly011);
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt(CONST_monthly012);
			set_color_easy(RED_ON_BLACK_BRIGHT);
			addstrAlt(CONST_monthly013);
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(24, 0, CONST_monthly014);
			clearformess = 1;
	 	pressAnyKey();
		}
	/*******************************************************
	*                                                      *
	*               END INTELLIGENCE REPORT                *
	*                                                      *
	*******************************************************/
	//ELECTIONS
	if (month == 11) { elections(clearformess, canseethings); clearformess = 1; }
	//SUPREME COURT
	if (month == 6) { supremecourt(clearformess, canseethings); clearformess = 1; }
	//CONGRESS
	congress(clearformess, canseethings); clearformess = 1;
	//DID YOU WIN?
	if (wincheck())
	{
		liberalagenda(1);
		savehighscore(END_WON);
		viewhighscores();
		end_game();
	}
	//CONTROL LONG DISBANDS
	if (disbanding&&year - disbandtime >= 50)
	{
		music.play(MUSIC_DEFEAT);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		eraseAlt();
		mvaddstrAlt(12,  10, CONST_monthly015, gamelog);
		gamelog.newline();
 	pressAnyKey();
		set_color_easy(WHITE_ON_BLACK);
		eraseAlt();
		mvaddstrAlt(12,  12, CONST_monthly016, gamelog);
		gamelog.newline();
 	pressAnyKey();
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		eraseAlt();
		mvaddstrAlt(12,  14, CONST_monthly017, gamelog);
		gamelog.newline();
		gamelog.nextMessage();
 	pressAnyKey();
		savehighscore(END_DISBANDLOSS);
		viewhighscores();
		end_game();
	}
	//UPDATE THE WORLD IN CASE THE LAWS HAVE CHANGED
	updateworld_laws(lawList, oldlaw);
	//THE SYSTEM!
	if (!disbanding) {
		monthlyRunTheSystem(clearformess);
	}
	
	//NUKE EXECUTION VICTIMS
	monthlyRunExecutions();
	
	//MUST DO AN END OF GAME CHECK HERE BECAUSE OF EXECUTIONS
	endcheck(END_EXECUTED);
	//DISPERSAL CHECK
	dispersalcheck(clearformess);
	//FUND REPORTS
	if (canseethings)fundreport(clearformess);
	ledger.resetMonthlyAmounts();
	if (clearformess) eraseAlt();
	//HEAL CLINIC PEOPLE
	if (!disbanding) {
		monthlyRunHealClinicPeople(clearformess);
	}
	
}