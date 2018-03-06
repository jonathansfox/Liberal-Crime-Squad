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

#include "common/ledgerEnums.h"
#include "common/ledger.h"

#include "basemode/liberalagenda.h"
// for liberalagenda

#include "items/itemPool.h"
#include "items/lootTypePool.h"

#include "common/commonactions.h"
#include "common/commonactionsCreature.h"
// for char endcheck(char cause=END_OTHER)

#include "log/log.h"

#include "common/commondisplay.h"
// for set_alignment_color and delimiter

#include "common/translateid.h"
// for  int getpoolcreature(int id);

#include "title/titlescreen.h"
// for void reset;

#include "title/highscore.h"
// for viewhighscores, in event of endgame

#include "politics/politics.h"
//for publicmood

#include "monthly/lcsmonthly.h"
//for void printnews(short l,short newspaper);

//#include "monthly/sleeper_update.h"
void sleepereffect(Creature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM]);

//#include "monthly/justice.h"
void trial(Creature &g);
char prison(Creature &g);

#include "daily/daily.h"
//for dispersalcheck and securitytable
void dispersalcheck(char &clearformess);

#include <cursesAlternative.h>
#include <constant_strings.h>
#include <set_color_support.h>

//#include <common\\getnames.h>
std::string getview(short view, bool shortname);

#include "locations/locationsPool.h"
#include "common/creaturePool.h"

/* end the game and clean up */
void end_game(int err = EXIT_SUCCESS);

extern vector<Creature *> pool;
extern Log gamelog;
extern vector<Location *> location;
#include "common/musicClass.h"
extern MusicClass music;
extern int year;
extern char endgamestate;
extern string singleDot;
extern char newscherrybusted;
extern int day;
extern int month;
extern short lawList[LAWNUM];
extern char disbanding;
extern short attitude[VIEWNUM];
extern short public_interest[VIEWNUM];
extern short background_liberal_influence[VIEWNUM];
extern vector<ArmorType *> armortype;
class Ledger ledger;
extern bool stalinmode;
extern int disbandtime;
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
	short oldlaw[LAWNUM];
	memmove(oldlaw, lawList, sizeof(short)*LAWNUM);
	int l, v, p;
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
	for (l = 0; l < LocationsPool::getInstance().lenpool(); l++) location[l]->newrental = 0;
	//YOUR PAPER AND PUBLIC OPINION AND STUFF
	vector<int> nploc;
	for (l = 0; l < LocationsPool::getInstance().lenpool(); l++)
	{
		if ((location[l]->compound_walls & COMPOUND_PRINTINGPRESS) &&
			!location[l]->siege.siege&&
			location[l]->renting != RENTING_CCS) nploc.push_back(l);
	}
	// Check for game over
	endcheck(END_DEAD);
	dispersalcheck(clearformess);
	int guardianpower = 0;
	if (len(nploc) && !disbanding)
	{
		//DO SPECIAL EDITIONS
		int loottypeindex = choosespecialedition(clearformess);
		if (loottypeindex != -1)
		{
			guardianpower += 10 * len(nploc);
			printnews(loottypeindex, len(nploc));
			if (LootTypePool::getInstance().getIdName(loottypeindex) == tag_LOOT_INTHQDISK || //For special edition xml file? -XML
				LootTypePool::getInstance().getIdName(loottypeindex) == tag_LOOT_SECRETDOCUMENTS)
			{
				for (int l = 0; l < len(nploc); l++)
					criminalizepool(LAWFLAG_TREASON, -1, nploc[l]);
			}
		}
	}
	int libpower[VIEWNUM] = { 0 };
	//STORIES STALE EVEN IF NOT PRINTED
	for (v = 0; v < VIEWNUM; v++)public_interest[v] /= 2;
	int conspower = 200 - attitude[VIEW_AMRADIO] - attitude[VIEW_CABLENEWS];
	//HAVING SLEEPERS
	for (int pl = CreaturePool::getInstance().lenpool() - 1; pl > 0; pl--)
		if (pool[pl]->alive && (pool[pl]->flag & CREATUREFLAG_SLEEPER))
			sleepereffect(*pool[pl], clearformess, canseethings, libpower);
	//Manage graffiti
	for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++) // Check each location
	{
		for (int c = len(location[l]->changes) - 1; c >= 0; c--) // Each change to the map
		{
			if (location[l]->changes[c].flag == SITEBLOCK_GRAFFITI ||
				location[l]->changes[c].flag == SITEBLOCK_GRAFFITI_CCS ||
				location[l]->changes[c].flag == SITEBLOCK_GRAFFITI_OTHER) // Find changes that refer specifically to graffiti
			{
				int power = 0, align = 0;
				if (location[l]->changes[c].flag == SITEBLOCK_GRAFFITI) align = 1;
				if (location[l]->changes[c].flag == SITEBLOCK_GRAFFITI_CCS) align = -1;
				//Purge graffiti from more secure sites (or from non-secure
				//sites about once every five years), but these will
				//influence people more for the current month
				if (securityable(LocationsPool::getInstance().getLocationType(l)))
				{
					location[l]->changes.erase(location[l]->changes.begin() + c);
					power = 5;
				}
				else
				{
					if (location[l]->renting == RENTING_CCS)
						location[l]->changes[c].flag = SITEBLOCK_GRAFFITI_CCS; // Convert to CCS tags
					else if (location[l]->renting == RENTING_PERMANENT)
						location[l]->changes[c].flag = SITEBLOCK_GRAFFITI; // Convert to LCS tags
					else
					{
						power = 1;
						if (!LCSrandom(10))
							location[l]->changes[c].flag = SITEBLOCK_GRAFFITI_OTHER; // Convert to other tags
						if (!LCSrandom(10) && endgamestate < ENDGAME_CCS_DEFEATED&&endgamestate>0)
							location[l]->changes[c].flag = SITEBLOCK_GRAFFITI_CCS; // Convert to CCS tags
						if (!LCSrandom(30))
							location[l]->changes.erase(location[l]->changes.begin() + c); // Clean up
					}
				}
				if (align == 1)
				{
					background_liberal_influence[VIEW_LIBERALCRIMESQUAD] += power;
					background_liberal_influence[VIEW_CONSERVATIVECRIMESQUAD] += power;
				}
				else if (align == -1)
				{
					background_liberal_influence[VIEW_LIBERALCRIMESQUAD] -= power;
					background_liberal_influence[VIEW_CONSERVATIVECRIMESQUAD] -= power;
				}
			}
		}
	}
	int mediabalance = 0;
	int issuebalance[VIEWNUM - 5];
	//int stimulus=0;
	//double cost=0;
	//double tax=0;
	//PUBLIC OPINION NATURAL MOVES
	for (v = 0; v < VIEWNUM; v++)
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
	for (int s = 0; s < CreaturePool::getInstance().lenpool(); s++)
	{
		pool[s]->train(SKILL_SEDUCTION, loveslaves(*pool[s]) * 5);
		if (pool[s]->flag & CREATUREFLAG_LOVESLAVE)
			pool[s]->train(SKILL_SEDUCTION, 5);
	}
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
			mvaddstrAlt(0, 23, "LCS MONTHLY INTELLIGENCE REPORT");
			mvaddstrAlt(2, 27, "CURRENT POLITICAL TRENDS");
			int numviews = (endgamestate >= ENDGAME_CCS_DEFEATED || newscherrybusted < 2) ? VIEWNUM - 1 : VIEWNUM;
			for (int v = -1 - stalinmode, y = 4, x = 0, pip; v < numviews; v++)
			{
				if ((y - 4) * 2 >= numviews + 1 + stalinmode) y = 4, x = 40;
				for (pip = 2; pip >= -2; pip--)
				{
					set_alignment_color(pip, true);
					if (pip == 2) mvaddcharAlt(y, x + 22, '\x11');
					addstrAlt("ÄÄÄ");
					if (pip == -2) addcharAlt('\x10');
				}
				if (v >= 0) pip = 14 - (attitude[v] * 14) / 100;
				else pip = 14 - (publicmood(v) * 14) / 100;
				set_alignment_color((14 - pip) / 3 - 2, true);
				mvaddstrAlt(y, x, getview(v, false));
				mvaddcharAlt(y++, x + 23 + pip, 'O');
			}
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			mvaddstrAlt(23, 0, "Elite Liberal ");
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt("-  ");
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			addstrAlt("Liberal  ");
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt("-  ");
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			addstrAlt("moderate  ");
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt("-  ");
			set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
			addstrAlt("Conservative  ");
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt("-  ");
			set_color_easy(RED_ON_BLACK_BRIGHT);
			addstrAlt("Arch-Conservative");
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(24, 0, "Press any key to reflect on these poll numbers.");
			clearformess = 1;
			getkeyAlt();
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
		mvaddstrAlt(12,  10, "The Liberal Crime Squad is now just a memory.", gamelog);
		gamelog.newline();
		getkeyAlt();
		set_color_easy(WHITE_ON_BLACK);
		eraseAlt();
		mvaddstrAlt(12,  12, "The last LCS members have all been hunted down.", gamelog);
		gamelog.newline();
		getkeyAlt();
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		eraseAlt();
		mvaddstrAlt(12,  14, "They will never see the utopia they dreamed of...", gamelog);
		gamelog.newline();
		gamelog.nextMessage();
		getkeyAlt();
		savehighscore(END_DISBANDLOSS);
		viewhighscores();
		end_game();
	}
	//UPDATE THE WORLD IN CASE THE LAWS HAVE CHANGED
	updateworld_laws(lawList, oldlaw);
	//THE SYSTEM!
	for (p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
	{
		if (disbanding) break;
		if (!pool[p]->alive) continue;
		if (pool[p]->flag & CREATUREFLAG_SLEEPER) continue;
		if (pool[p]->location == -1) continue;
		if (LocationsPool::getInstance().getLocationType(pool[p]->location) == SITE_GOVERNMENT_POLICESTATION)
		{
			if (clearformess) eraseAlt();
			else makedelimiter();
			if (pool[p]->flag & CREATUREFLAG_MISSING)
			{
				set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
				mvaddstrAlt(8,  1, "Cops re-polluted ", gamelog);
				addstrAlt(pool[p]->name, gamelog);
				addstrAlt("'s mind with Conservatism!", gamelog);
				gamelog.nextMessage();
				getkeyAlt();
				removesquadinfo(*pool[p]);
				delete_and_remove(pool, p);
				continue;
			}
			else if (pool[p]->flag & CREATUREFLAG_ILLEGALALIEN && lawList[LAW_IMMIGRATION] != 2)
			{
				set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
				mvaddstrAlt(8,  1, pool[p]->name, gamelog);
				addstrAlt(" has been shipped out to the INS to face ", gamelog);
				if (lawList[LAW_IMMIGRATION] == -2 && lawList[LAW_DEATHPENALTY] == -2)
					addstrAlt("execution.", gamelog);
				else addstrAlt("deportation.", gamelog);
				gamelog.newline();
				getkeyAlt();
				removesquadinfo(*pool[p]);
				delete_and_remove(pool, p);
				continue;
			}
			else
			{
				//TRY TO GET RACKETEERING CHARGE
				int copstrength = 100;
				if (lawList[LAW_POLICEBEHAVIOR] == -2) copstrength = 200;
				if (lawList[LAW_POLICEBEHAVIOR] == -1) copstrength = 150;
				if (lawList[LAW_POLICEBEHAVIOR] == 1) copstrength = 75;
				if (lawList[LAW_POLICEBEHAVIOR] == 2) copstrength = 50;
				copstrength = (copstrength*pool[p]->heat) / 4;
				if (copstrength > 200)copstrength = 200;
				//Confession check
				if (LCSrandom(copstrength) > pool[p]->juice + pool[p]->get_attribute(ATTRIBUTE_HEART, true) * 5 -
					pool[p]->get_attribute(ATTRIBUTE_WISDOM, true) * 5 + pool[p]->get_skill(SKILL_PSYCHOLOGY) * 5
					/*+ pool[p]->get_skill(SKILL_SURVIVAL)*5*/ && pool[p]->hireid != -1)
				{
					int nullify = 0;
					int p2 = getpoolcreature(pool[p]->hireid);
					if (pool[p2]->alive && (pool[p2]->location == -1 || LocationsPool::getInstance().getLocationType(pool[p2]->location) != SITE_GOVERNMENT_PRISON))
					{  //Charge the boss with racketeering!
						criminalize(*pool[p2], LAWFLAG_RACKETEERING);
						//Rack up testimonies against the boss in court!
						pool[p2]->confessions++;
					}
					if (!nullify)
					{  //Issue a raid on this guy's base!
						if (pool[p]->base >= 0)LocationsPool::getInstance().addHeat(pool[p]->base, 300);
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(8,  1, pool[p]->name, gamelog);
						addstrAlt(" has broken under the pressure and ratted you out!", gamelog);
						gamelog.newline();
						getkeyAlt();
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(9,  1, "The traitor will testify in court, and safehouses may be compromised.", gamelog);
						gamelog.nextMessage();
						getkeyAlt();
						removesquadinfo(*pool[p]);
						delete_and_remove(pool, p);
						continue; //no trial for this person; skip to next person
					}
					//else continue to trial
				}
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8,  1, pool[p]->name, gamelog);
				addstrAlt(" is moved to the courthouse for trial.", gamelog);
				gamelog.nextMessage();
				getkeyAlt();
				pool[p]->location = find_site_index_in_same_city(SITE_GOVERNMENT_COURTHOUSE, pool[p]->location);
				Armor prisoner(*armortype[getarmortype(tag_ARMOR_PRISONER)]);
				pool[p]->give_armor(prisoner, NULL);
			}
		}
		else if (LocationsPool::getInstance().getLocationType(pool[p]->location) == SITE_GOVERNMENT_COURTHOUSE)
		{
			trial(*pool[p]); clearformess = 1;
		}
		else if (LocationsPool::getInstance().getLocationType(pool[p]->location) == SITE_GOVERNMENT_PRISON)
			if (prison(*pool[p])) clearformess = 1;
	}
	//NUKE EXECUTION VICTIMS
	for (p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
	{
		if (pool[p]->location == -1) continue;
		if (LocationsPool::getInstance().getLocationType(pool[p]->location) == SITE_GOVERNMENT_PRISON&&!pool[p]->alive)
		{
			removesquadinfo(*pool[p]);
			pool[p]->die();
			pool[p]->location = -1;
		}
	}
	//MUST DO AN END OF GAME CHECK HERE BECAUSE OF EXECUTIONS
	endcheck(END_EXECUTED);
	//DISPERSAL CHECK
	dispersalcheck(clearformess);
	//FUND REPORTS
	if (canseethings)fundreport(clearformess);
	ledger.resetMonthlyAmounts();
	if (clearformess) eraseAlt();
	//HEAL CLINIC PEOPLE
	for (p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (disbanding) break;
		if (!(pool[p]->alive)) continue;
		if (pool[p]->clinic>0)
		{
			pool[p]->clinic--;
			for (int w = 0; w < BODYPARTNUM; w++)
			{
				if ((pool[p]->wound[w] & WOUND_NASTYOFF) || (pool[p]->wound[w] & WOUND_CLEANOFF))
					pool[p]->wound[w] = (char)WOUND_CLEANOFF;
				else pool[p]->wound[w] = 0;
			}
			int healthdamage = 0;
			if (pool[p]->special[SPECIALWOUND_RIGHTLUNG] != 1)
			{
				pool[p]->special[SPECIALWOUND_RIGHTLUNG] = 1;
				if (LCSrandom(2)) healthdamage++;
			}
			if (pool[p]->special[SPECIALWOUND_LEFTLUNG] != 1)
			{
				pool[p]->special[SPECIALWOUND_LEFTLUNG] = 1;
				if (LCSrandom(2)) healthdamage++;
			}
			if (pool[p]->special[SPECIALWOUND_HEART] != 1)
			{
				pool[p]->special[SPECIALWOUND_HEART] = 1;
				if (LCSrandom(3)) healthdamage++;
			}
			pool[p]->special[SPECIALWOUND_LIVER] = 1;
			pool[p]->special[SPECIALWOUND_STOMACH] = 1;
			pool[p]->special[SPECIALWOUND_RIGHTKIDNEY] = 1;
			pool[p]->special[SPECIALWOUND_LEFTKIDNEY] = 1;
			pool[p]->special[SPECIALWOUND_SPLEEN] = 1;
			pool[p]->special[SPECIALWOUND_RIBS] = RIBNUM;
			if (!pool[p]->special[SPECIALWOUND_NECK])
				pool[p]->special[SPECIALWOUND_NECK] = 2;
			if (!pool[p]->special[SPECIALWOUND_UPPERSPINE])
				pool[p]->special[SPECIALWOUND_UPPERSPINE] = 2;
			if (!pool[p]->special[SPECIALWOUND_LOWERSPINE])
				pool[p]->special[SPECIALWOUND_LOWERSPINE] = 2;
			// Inflict permanent health damage
			pool[p]->set_attribute(ATTRIBUTE_HEALTH, pool[p]->get_attribute(ATTRIBUTE_HEALTH, 0) - healthdamage);
			if (pool[p]->get_attribute(ATTRIBUTE_HEALTH, 0) <= 0)
				pool[p]->set_attribute(ATTRIBUTE_HEALTH, 1);
			if (pool[p]->blood <= 20 && pool[p]->clinic <= 2)pool[p]->blood = 50;
			if (pool[p]->blood <= 50 && pool[p]->clinic <= 1)pool[p]->blood = 75;
			// If at clinic and in critical condition, transfer to university hospital
			if (pool[p]->clinic > 2 &&
				pool[p]->location > -1 &&
				LocationsPool::getInstance().getLocationType(pool[p]->location) == SITE_HOSPITAL_CLINIC)
			{
				int hospital = find_site_index_in_same_city(SITE_HOSPITAL_UNIVERSITY, pool[p]->location);
				if (hospital != -1)
				{
					pool[p]->location = hospital;
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8,  1, pool[p]->name, gamelog);
					addstrAlt(" has been transferred to ", gamelog);
					addstrAlt(LocationsPool::getInstance().getLocationName(hospital), gamelog);
					addstrAlt(singleDot, gamelog);
					gamelog.nextMessage();
					getkeyAlt();
				}
			}
			// End treatment
			if (pool[p]->clinic == 0)
			{
				pool[p]->blood = 100;
				if (clearformess) eraseAlt();
				else makedelimiter();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8,  1, pool[p]->name, gamelog);
				addstrAlt(" has left ", gamelog);
				addstrAlt(LocationsPool::getInstance().getLocationName(pool[p]->location), gamelog);
				addstrAlt(singleDot, gamelog);
				gamelog.nextMessage();
				int hs = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, pool[p]->location);
				if (hs == -1) hs = 0; //TODO: Error unable to find location
				if (LocationsPool::getInstance().isThereASiegeHere(pool[p]->base) ||
					LocationsPool::getInstance().getRentingType(pool[p]->base) == RENTING_NOCONTROL)
					pool[p]->base = hs;
				pool[p]->location = pool[p]->base;
				getkeyAlt();
			}
		}
	}
}
