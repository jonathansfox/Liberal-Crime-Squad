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

#include "vehicle/vehicletype.h"
#include "vehicle/vehicle.h"

#include "basemode/baseactions.h"
// for orderparty

#include "sitemode/sitedisplay.h"

//#include "sitemode/advance.h"
void creatureadvance();

//#include "sitemode/miscactions.h"
void reloadparty(bool wasteful = false);

//#include "sitemode/sitemode.h"
void mode_site(short loc);

#include "common/commonactions.h"
#include "common/commonactionsCreature.h"
// for void cleangonesquads();

#include "log/log.h"
// for commondisplay.h
#include "common/commondisplay.h"
// for void printfunds(int,int,char*)

#include "common/translateid.h"
// for  int getsquad(int)

#include "politics/politics.h"
//for  int publicmood(int l);

#include "combat/fight.h"   
//for void autopromote(int loc);

#include "combat/chase.h"
//for void evasiverun();


#include <cursesAlternative.h>
#include <customMaps.h>
#include <set_color_support.h>
extern vector<Creature *> pool;
extern Log gamelog;
extern vector<Location *> location;
#include "locations/locationsPool.h"
#include "common/musicClass.h"
extern MusicClass music;
extern short mode;
extern char endgamestate;
extern char foughtthisround;
extern int stat_dead;
extern int ccs_siege_kills;
 vector<string> words_meaning_news;
 vector<string> newspaper_first_name;
 vector<string> newspaper_last_name;
 vector<string> insult_for_liberal;
 vector<string> word_replacing_liberal;

extern string check_status_of_squad_liberal;
extern string show_squad_liberal_status;
extern string singleDot;
extern string change_squad_order;
vector<string> engageConservativesEscape;
vector<string> engageConservatives;
vector<string> nextSiegeAgain;
vector<string> nextSiege;

const string siege = "siege\\";
const string mostlyendings = "mostlyendings\\";
vector<file_and_text_collection> siege_text_file_collection = {

	/*siege.cpp*/
	customText(&words_meaning_news, siege + "words_meaning_news.txt"),
	customText(&newspaper_first_name, siege + "newspaper_first_name.txt"),
	customText(&newspaper_last_name, siege + "newspaper_last_name.txt"),
	customText(&insult_for_liberal, siege + "insult_for_liberal.txt"),
	customText(&word_replacing_liberal, siege + "word_replacing_liberal.txt"),

	customText(&nextSiege, mostlyendings + "nextSiege.txt"),
	customText(&nextSiegeAgain, mostlyendings + "nextSiegeAgain.txt"),
	customText(&engageConservatives, mostlyendings + "engageConservatives.txt"),
	customText(&engageConservativesEscape, mostlyendings + "engageConservativesEscape.txt"),
};

extern int selectedsiege;
extern short offended_corps;
extern short offended_cia;
extern short offended_amradio;
extern short offended_cablenews;
extern short offended_firemen;
extern short lawList[LAWNUM];
extern vector<Vehicle *> vehicle;
extern short attitude[VIEWNUM];
extern string commaSpace;

extern char disbanding;
extern string singleSpace;
extern squadst *activesquad;
extern class Ledger ledger;
extern vector<squadst *> squad;
extern short cursite;
extern vector<newsstoryst *> newsstory;
extern Creature encounter[ENCMAX];
extern short party_status;
extern newsstoryst *sitestory;

extern long cursquadid;
extern int police_heat;
extern char ccs_kills;

void emptyEncounter();
void fillEncounter(CreatureTypes c, int numleft);

#include "common/creaturePool.h"

/* TODO
make it less likely to be raided based on:
- the number of sleepers.
- how effective said sleepers are.
- what action each sleeper is doing (promoting liberalism decreases chance while promoting conservatism increases chance)
- what the sleeper does for a living (police officers are more influential than janitors, for instance)
make it more likely to be raided:
- when a liberal hacks or steals credit cards.
- dead bodies in the base. [DONE]
*/
/* siege - gives up on sieges with empty locations */
/* Work in progress. It works, but needs to be called in more places. */
/* Currently, it only works when you confront a siege and then fail. */
/* siege - handles giving up */
void giveup()
{
	int loc = -1;
	if (selectedsiege != -1)loc = selectedsiege;
	if (activesquad != NULL)loc = activesquad->squad[0]->location;
	if (loc == -1)return;
	if (LocationsPool::getInstance().getRentingType(loc) > 1)location[loc]->renting = RENTING_NOCONTROL;
	//IF POLICE, END SIEGE
	if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_POLICE ||
		LocationsPool::getInstance().getSiegeType(loc) == SIEGE_FIREMEN)
	{
		music.play(MUSIC_SIEGE);
		int polsta = find_site_index_in_same_city(SITE_GOVERNMENT_POLICESTATION, loc);
		//END SIEGE
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(1, 1);
		if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_POLICE && LocationsPool::getInstance().getSiegeEscalationState(loc) == 0)
			addstrAlt("The police", gamelog);
		else if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_POLICE && LocationsPool::getInstance().getSiegeEscalationState(loc) >= 1)
			addstrAlt("The soldiers", gamelog);
		else addstrAlt("The firemen", gamelog);
		addstrAlt(" confiscate everything, including Squad weapons.", gamelog);
		gamelog.newline();
		int kcount = 0, pcount = 0, icount = 0, p;
		char kname[100], pname[100], pcname[100];
		for (p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
		{
			if (pool[p]->location != loc || !pool[p]->alive) continue;
			if (pool[p]->flag&CREATUREFLAG_ILLEGALALIEN) icount++;
			if (pool[p]->flag&CREATUREFLAG_MISSING&&pool[p]->align == -1)
			{
				kcount++;
				strcpy(kname, pool[p]->propername);
				if (pool[p]->type == CREATURE_RADIOPERSONALITY) offended_amradio = 1;
				if (pool[p]->type == CREATURE_NEWSANCHOR) offended_cablenews = 1;
				//clear interrogation data if deleted
				delete pool[p]->activity.intr();
			}
		}
		//CRIMINALIZE POOL IF FOUND WITH KIDNAP VICTIM OR ALIEN
		if (kcount) criminalizepool(LAWFLAG_KIDNAPPING, -1, loc);
		if (icount) criminalizepool(LAWFLAG_HIREILLEGAL, -1, loc);
		if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_FIREMEN && location[loc]->compound_walls&COMPOUND_PRINTINGPRESS)
			criminalizepool(LAWFLAG_SPEECH, -1, loc); // Criminalize pool for unacceptable speech
													  //LOOK FOR PRISONERS (MUST BE AFTER CRIMINALIZATION ABOVE)
		for (p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
		{
			if (pool[p]->location != loc || !pool[p]->alive) continue;
			if (iscriminal(*pool[p]) && !(pool[p]->flag&CREATUREFLAG_MISSING&&pool[p]->align == -1))
			{
				pcount++;
				strcpy(pname, pool[p]->propername);
				strcpy(pcname, pool[p]->name);
			}
		}
		if (kcount == 1)
		{
			mvaddstrAlt(3, 1, kname);
			addstrAlt(" is rehabilitated and freed.", gamelog);
			gamelog.newline();
		}
		if (kcount > 1)
		{
			mvaddstrAlt(3, 1, "The kidnap victims are rehabilitated and freed.", gamelog);
			gamelog.newline();
		}
		if (pcount == 1)
		{
			mvaddstrAlt(5, 1, pname, gamelog);
			if (strcmp(pname, pcname))
			{
				addstrAlt(", aka ", gamelog);
				addstrAlt(pcname, gamelog);
				addstrAlt(",", gamelog);
			}
			mvaddstrAlt(6, 1, "is taken to the police station.", gamelog);
			gamelog.newline();
		}
		if (pcount > 1)
		{
			mvaddstrAlt(5, 1, pcount, gamelog);
			addstrAlt(" Liberals are taken to the police station.", gamelog);
			gamelog.newline();
		}
		if (ledger.get_funds() > 0)
		{
			if (ledger.get_funds() <= 2000 || location[loc]->siege.siegetype == SIEGE_FIREMEN)
			{
				mvaddstrAlt(8, 1, "Fortunately, your funds remain intact.", gamelog);
				gamelog.newline();
			}
			else
			{
				moveAlt(8, 1);
				int confiscated = LCSrandom(LCSrandom(ledger.get_funds() - 2000) + 1) + 1000;
				if (ledger.get_funds() - confiscated > 50000)
					confiscated += ledger.get_funds() - 30000 - LCSrandom(20000) - confiscated;
				addstr_fl(gamelog, "Law enforcement has confiscated $%d in LCS funds.", confiscated);
				gamelog.newline();
				ledger.subtract_funds(confiscated, EXPENSE_CONFISCATED);
			}
		}
		if (location[loc]->siege.siegetype == SIEGE_FIREMEN)
		{
			if (location[loc]->compound_walls & COMPOUND_PRINTINGPRESS)
			{
				mvaddstrAlt(10, 1, "The printing press is dismantled and burned.", gamelog);
				gamelog.newline();
				location[loc]->compound_walls &= ~COMPOUND_PRINTINGPRESS;
			}
		}
		else
		{
			if (location[loc]->compound_walls)
			{
				mvaddstrAlt(10, 1, "The compound is dismantled.", gamelog);
				gamelog.newline();
				location[loc]->compound_walls = 0;
			}
		}
		if (location[loc]->front_business != -1)
		{
			mvaddstrAlt(12, 1, "Materials relating to the business front have been taken.", gamelog);
			gamelog.newline();
			location[loc]->front_business = -1;
		}
		getkeyAlt();
		if (location[loc]->siege.siegetype == SIEGE_FIREMEN)
			offended_firemen = 0; // Firemen do not hold grudges
		for (p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
		{
			if (pool[p]->location != loc) continue;
			//ALL KIDNAP VICTIMS FREED REGARDLESS OF CRIMES
			if ((pool[p]->flag & CREATUREFLAG_MISSING) ||
				!pool[p]->alive)
			{
				// Clear actions for anybody who was tending to this person
				for (int i = 0; i < CreaturePool::getInstance().lenpool(); i++)
					if (pool[i]->alive&&pool[i]->activity.type == ACTIVITY_HOSTAGETENDING && pool[i]->activity.arg == pool[p]->id)
						pool[i]->activity.type = ACTIVITY_NONE;
				removesquadinfo(*pool[p]);
				delete_and_remove(pool, p);
				continue;
			}
			//TAKE SQUAD EQUIPMENT
			if (pool[p]->squadid != -1)
			{
				int sq = getsquad(pool[p]->squadid);
				if (sq != -1)delete_and_clear(squad[sq]->loot);
			}
			pool[p]->drop_weapons_and_clips(NULL);
			if (iscriminal(*pool[p]))
			{
				removesquadinfo(*pool[p]);
				pool[p]->location = polsta;
				pool[p]->activity.type = ACTIVITY_NONE;
			}
		}
		location[loc]->siege.siege = 0;
	}
	else
	{
		//OTHERWISE IT IS SUICIDE
		int killnumber = 0;
		for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
		{
			if (pool[p]->location != loc) continue;
			if (pool[p]->alive&&pool[p]->align == 1) stat_dead++;
			killnumber++;
			removesquadinfo(*pool[p]);
			pool[p]->die();
			pool[p]->location = -1;
		}
		if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_CCS && LocationsPool::getInstance().getLocationType(loc) == SITE_INDUSTRY_WAREHOUSE)
			location[loc]->renting = RENTING_CCS; // CCS Captures warehouse
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(1, 1, "Everyone in the ", gamelog);
		addstrAlt(LocationsPool::getInstance().getLocationName(loc), gamelog);
		addstrAlt(" is slain.", gamelog);
		gamelog.newline();
		if (!endcheck(-2)) music.play(MUSIC_SIEGE); // play correct music for if we lost the game or didn't lose it
		getkeyAlt();
		newsstoryst *ns = new newsstoryst;
		ns->type = NEWSSTORY_MASSACRE;
		ns->loc = loc;
		ns->crime.push_back(LocationsPool::getInstance().getSiegeType(loc));
		ns->crime.push_back(killnumber);
		newsstory.push_back(ns);
		//MUST SET cursite TO SATISFY endcheck() CODE
		int tmp = cursite;
		cursite = loc;
		endcheck();
		cursite = tmp;
		location[loc]->siege.siege = 0;
	}
	//CONFISCATE MATERIAL
	delete_and_clear(location[loc]->loot);
	for (int v = len(vehicle) - 1; v >= 0; v--)
		if (vehicle[v]->get_location() == loc)
			delete_and_remove(vehicle, v);
	gamelog.newline();
}
void resolvesafehouses()
{
	for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
	{
		if (LocationsPool::getInstance().getRentingType(l)>= 0 && LocationsPool::getInstance().isThereASiegeHere(l))
		{
			cleangonesquads();
			selectedsiege = l; // hack for calling giveup()
			giveup();
		}
	}
}
/* siege - "you are wanted for _______ and other crimes..." */
void statebrokenlaws(int loc)
{
	music.play(MUSIC_SIEGE);
	short breakercount[LAWFLAGNUM] = { 0 };
	int typenum = 0, criminalcount = 0, kidnapped = 0;
	char kname[100];
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (!pool[p]->alive || pool[p]->location != loc) continue;
		if (pool[p]->flag&CREATUREFLAG_KIDNAPPED)
		{
			strcpy(kname, pool[p]->propername);
			kidnapped++;
		}
		if (iscriminal(*pool[p])) criminalcount++;
		for (int i = 0; i < LAWFLAGNUM; i++) if (pool[p]->crimes_suspected[i]) breakercount[i]++;
	}
	for (int i = 0; i < LAWFLAGNUM; i++) if (breakercount[i]) typenum++;
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(1, 1);
	if (location[loc]->siege.underattack) addstrAlt("You hear shouts:", gamelog);
	else addstrAlt("You hear a blaring voice on a loudspeaker:", gamelog);
	gamelog.newline();
	moveAlt(3, 1);
	if (LocationsPool::getInstance().getSiegeEscalationState(loc) >= 2 && publicmood(-1) < 20)
		addstrAlt("In the name of God, your campaign of terror ends here!", gamelog);
	else addstrAlt("Surrender yourselves!", gamelog);
	gamelog.newline();
	moveAlt(4, 1);
	//KIDNAP VICTIM
	if (kidnapped)
	{
		addstrAlt("Release ", gamelog);
		addstrAlt(kname, gamelog);
		if (kidnapped > 1) addstrAlt(" and the others", gamelog);
		addstrAlt(" unharmed!", gamelog);
	}
	//TREASON
	else if (breakercount[LAWFLAG_TREASON])
		addstrAlt("You are wanted for treason", gamelog);
	//TERRORISM
	else if (breakercount[LAWFLAG_TERRORISM])
		addstrAlt("You are wanted for terrorism", gamelog);
	//MURDERER
	else if (breakercount[LAWFLAG_MURDER])
		addstrAlt("You are wanted for first degree murder", gamelog);
	//KIDNAPPER
	else if (breakercount[LAWFLAG_KIDNAPPING])
		addstrAlt("You are wanted for kidnapping", gamelog);
	//BANK ROBBER
	else if (breakercount[LAWFLAG_BANKROBBERY])
		addstrAlt("You are wanted for bank robbery", gamelog);
	//ARSONIST
	else if (breakercount[LAWFLAG_ARSON])
		addstrAlt("You are wanted for arson", gamelog);
	//BURN FLAG
	else if (breakercount[LAWFLAG_BURNFLAG])
	{
		if (lawList[LAW_FLAGBURNING] == -2)addstrAlt("You are wanted for Flag Murder", gamelog);
		else if (lawList[LAW_FLAGBURNING] == -1)addstrAlt("You are wanted for felony flag burning", gamelog);
		else addstrAlt("You are wanted for flag burning", gamelog);
	}
	//SPEECH
	else if (breakercount[LAWFLAG_SPEECH])
		addstrAlt("You are wanted for sedition", gamelog);
	//BROWNIES
	else if (breakercount[LAWFLAG_BROWNIES])
		addstrAlt("You are wanted for sale and distribution of a controlled substance", gamelog);
	//ESCAPED
	else if (breakercount[LAWFLAG_ESCAPED])
		addstrAlt("You are wanted for escaping prison", gamelog);
	//HELP ESCAPED
	else if (breakercount[LAWFLAG_HELPESCAPE])
		addstrAlt("You are wanted for aiding a prison escape", gamelog);
	//JURY
	else if (breakercount[LAWFLAG_JURY])
		addstrAlt("You are wanted for jury tampering", gamelog);
	//RACKETEERING
	else if (breakercount[LAWFLAG_RACKETEERING])
		addstrAlt("You are wanted for racketeering", gamelog);
	//EXTORTION
	else if (breakercount[LAWFLAG_EXTORTION])
		addstrAlt("You are wanted for extortion", gamelog);
	//ASSAULT
	else if (breakercount[LAWFLAG_ARMEDASSAULT])
		addstrAlt("You are wanted for assault with a deadly weapon", gamelog);
	//ASSAULT
	else if (breakercount[LAWFLAG_ASSAULT])
		addstrAlt("You are wanted for misdemeanor assault", gamelog);
	//CAR THEFT
	else if (breakercount[LAWFLAG_CARTHEFT])
		addstrAlt("You are wanted for grand theft auto", gamelog);
	//CC FRAUD
	else if (breakercount[LAWFLAG_CCFRAUD])
		addstrAlt("You are wanted for credit card fraud", gamelog);
	//THIEF
	else if (breakercount[LAWFLAG_THEFT])
		addstrAlt("You are wanted for petty larceny", gamelog);
	//PROSTITUTION
	else if (breakercount[LAWFLAG_PROSTITUTION])
		addstrAlt("You are wanted for prostitution", gamelog);
	//HIRE ILLEGAL
	else if (breakercount[LAWFLAG_HIREILLEGAL])
		addstrAlt((lawList[LAW_IMMIGRATION] < 1 ? "You are wanted for hiring an illegal alien" : "You are wanted for hiring an undocumented worker"), gamelog);
	//GUN USE
	/*else if(breakercount[LAWFLAG_GUNUSE])
	addstrAlt("You are wanted for firing an illegal weapon", gamelog);
	//GUN CARRY
	else if(breakercount[LAWFLAG_GUNCARRY])
	addstrAlt("You are wanted for possession of an illegal weapon", gamelog);*/
	//COMMERCE
	else if (breakercount[LAWFLAG_COMMERCE])
		addstrAlt("You are wanted for interference with interstate commerce", gamelog);
	//INFORMATION
	else if (breakercount[LAWFLAG_INFORMATION])
		addstrAlt("You are wanted for unlawful access of an information system", gamelog);
	//UNLAWFUL BURIAL
	else if (breakercount[LAWFLAG_BURIAL])
		addstrAlt("You are wanted for unlawful burial", gamelog);
	//BREAKING
	else if (breakercount[LAWFLAG_BREAKING])
		addstrAlt("You are wanted for breaking and entering", gamelog);
	//VANDALISM
	else if (breakercount[LAWFLAG_VANDALISM])
		addstrAlt("You are wanted for vandalism", gamelog);
	//RESIST
	else if (breakercount[LAWFLAG_RESIST])
		addstrAlt("You are wanted for resisting arrest", gamelog);
	//DISTURBANCE
	else if (breakercount[LAWFLAG_DISTURBANCE])
		addstrAlt("You are wanted for disturbing the peace", gamelog);
	//PUBLIC NUDITY
	else if (breakercount[LAWFLAG_PUBLICNUDITY])
		addstrAlt("You are wanted for indecent exposure", gamelog);
	//LOITERING
	else if (breakercount[LAWFLAG_LOITERING])
		addstrAlt("You are wanted for loitering", gamelog);
	//THEY WERE LOOKING FOR SOMEONE ELSE
	else addstrAlt("You are wanted for harboring a fugitive from justice", gamelog);
	if (!kidnapped)
	{
		if (typenum > 1) addstrAlt(" and other crimes", gamelog);
		addstrAlt(singleDot, gamelog);
	}
	gamelog.nextMessage();
	getkeyAlt();
}
void statebrokenlaws(Creature & cr)
{
	bool kidnapped = (cr.flag&CREATUREFLAG_KIDNAPPED), criminal = false, breakercount[LAWFLAGNUM];
	for (int i = 0; i < LAWFLAGNUM; i++)
		if (cr.crimes_suspected[i]) breakercount[i] = true, criminal = true;
		else breakercount[i] = false;
		if (!criminal && !kidnapped) return;
		set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		addstrAlt("WANTED FOR ");
		//KIDNAP VICTIM
		if (kidnapped)
			addstrAlt("REHABILITATION");
		//TREASON
		else if (breakercount[LAWFLAG_TREASON])
			addstrAlt("TREASON");
		//TERRORISM
		else if (breakercount[LAWFLAG_TERRORISM])
			addstrAlt("TERRORISM");
		//MURDERER
		else if (breakercount[LAWFLAG_MURDER])
			addstrAlt("MURDER");
		//KIDNAPPER
		else if (breakercount[LAWFLAG_KIDNAPPING])
			addstrAlt("KIDNAPPING");
		//BANK ROBBER
		else if (breakercount[LAWFLAG_BANKROBBERY])
			addstrAlt("BANK ROBBERY");
		//ARSONIST
		else if (breakercount[LAWFLAG_BANKROBBERY])
			addstrAlt("ARSON");
		//BURN FLAG
		else if (breakercount[LAWFLAG_BURNFLAG])
			addstrAlt(lawList[LAW_FLAGBURNING] == -2 ? "FLAG MURDER" : "FLAG BURNING");
		//SPEECH
		else if (breakercount[LAWFLAG_SPEECH])
			addstrAlt("HARMFUL SPEECH");
		//BROWNIES
		else if (breakercount[LAWFLAG_BROWNIES])
			addstrAlt("DRUG DEALING");
		//ESCAPED
		else if (breakercount[LAWFLAG_ESCAPED])
			addstrAlt("ESCAPING PRISON");
		//HELP ESCAPED
		else if (breakercount[LAWFLAG_HELPESCAPE])
			addstrAlt("RELEASING PRISONERS");
		//JURY
		else if (breakercount[LAWFLAG_JURY])
			addstrAlt("JURY TAMPERING");
		//RACKETEERING
		else if (breakercount[LAWFLAG_RACKETEERING])
			addstrAlt("RACKETEERING");
		//EXTORTION
		else if (breakercount[LAWFLAG_EXTORTION])
			addstrAlt("EXTORTION");
		//ASSAULT
		else if (breakercount[LAWFLAG_ARMEDASSAULT])
			addstrAlt("ARMED ASSAULT");
		//ASSAULT
		else if (breakercount[LAWFLAG_ASSAULT])
			addstrAlt("ASSAULT");
		//CAR THEFT
		else if (breakercount[LAWFLAG_CARTHEFT])
			addstrAlt("GRAND THEFT AUTO");
		//CC FRAUD
		else if (breakercount[LAWFLAG_CCFRAUD])
			addstrAlt("CREDIT CARD FRAUD");
		//THIEF
		else if (breakercount[LAWFLAG_THEFT])
			addstrAlt("THEFT");
		//PROSTITUTION
		else if (breakercount[LAWFLAG_PROSTITUTION])
			addstrAlt("PROSTITUTION");
		//HIRE ILLEGAL
		else if (breakercount[LAWFLAG_HIREILLEGAL])
			addstrAlt(lawList[LAW_IMMIGRATION] < 1 ? "HIRING ILLEGAL ALIENS" : "HIRING UNDOCUMENTED WORKERS");
		//GUN USE
		/*else if(breakercount[LAWFLAG_GUNUSE])
		addstrAlt("FIRING ILLEGAL WEAPONS");
		//GUN CARRY
		else if(breakercount[LAWFLAG_GUNCARRY])
		addstrAlt("CARRYING ILLEGAL WEAPONS");*/
		//COMMERCE
		else if (breakercount[LAWFLAG_COMMERCE])
			addstrAlt("ELECTRONIC SABOTAGE");
		//INFORMATION
		else if (breakercount[LAWFLAG_INFORMATION])
			addstrAlt("HACKING");
		//UNLAWFUL BURIAL
		else if (breakercount[LAWFLAG_BURIAL])
			addstrAlt("UNLAWFUL BURIAL");
		//BREAKING
		else if (breakercount[LAWFLAG_BREAKING])
			addstrAlt("BREAKING AND ENTERING");
		//VANDALISM
		else if (breakercount[LAWFLAG_VANDALISM])
			addstrAlt("VANDALISM");
		//RESIST
		else if (breakercount[LAWFLAG_RESIST])
			addstrAlt("RESISTING ARREST");
		//DISTURBANCE
		else if (breakercount[LAWFLAG_DISTURBANCE])
			addstrAlt("DISTURBING THE PEACE");
		//PUBLIC NUDITY
		else if (breakercount[LAWFLAG_PUBLICNUDITY])
			addstrAlt("PUBLIC NUDITY");
		//LOITERING
		else if (breakercount[LAWFLAG_LOITERING])
			addstrAlt("LOITERING");
}
/* siege - updates upcoming sieges */
void siegecheck(char canseethings)
{
	if (disbanding)return;
	// Upkeep - even base-less should be considered.
	// XXX - candidate to create nice function?
	// Cleanse record on things that aren't illegal right now
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (lawList[LAW_FLAGBURNING] > 0)pool[p]->crimes_suspected[LAWFLAG_BURNFLAG] = 0;
		if (lawList[LAW_DRUGS] > 0)pool[p]->crimes_suspected[LAWFLAG_BROWNIES] = 0;
		if (lawList[LAW_IMMIGRATION] == 2)pool[p]->flag &= ~CREATUREFLAG_ILLEGALALIEN;
		if (lawList[LAW_FREESPEECH] > -2)pool[p]->crimes_suspected[LAWFLAG_SPEECH] = 0;
	}
	if (lawList[LAW_FREESPEECH] > -2)offended_firemen = 0;
	//FIRST, THE COPS
	int numpres;
	for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
	{
		if (LocationsPool::getInstance().isThisSiteClosed(find_site_index_in_same_city(SITE_GOVERNMENT_POLICESTATION, l)))
		{
			location[l]->heat = static_cast<int>(location[l]->heat * 0.95);
		}
		if (LocationsPool::getInstance().isThereASiegeHere(l))continue;
		if (LocationsPool::getInstance().getRentingType(l) == RENTING_NOCONTROL)continue;
		numpres = 0;
		if (location[l]->siege.timeuntillocated == -2)
		{
			//IF JUST SIEGED, BUY SOME TIME
			location[l]->siege.timeuntillocated = -1;
		}
		else
		{
			//HUNTING
			if (location[l]->siege.timeuntillocated>0)
			{
				if (location[l]->front_business == -1 || LCSrandom(2))
				{
					location[l]->siege.timeuntillocated--;
					// Hunt faster if location is extremely hot
					if (location[l]->heat > 100)
					{
						int hunt_speed;
						hunt_speed = location[l]->heat / 50;
						while (hunt_speed&&location[l]->siege.timeuntillocated > 1)
						{
							location[l]->siege.timeuntillocated--;
							hunt_speed--;
						}
					}
				}
			}
			//CHECK FOR CRIMINALS AT THIS BASE
			int crimes = 0;
			//int heatprotection=0;
			for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
			{
				// Sleepers and people not at this base don't count
				if (pool[p]->location != l || pool[p]->flag & CREATUREFLAG_SLEEPER)continue;
				if (!pool[p]->alive) // Corpses attract attention
				{
					crimes += 5;
					continue;
				}
				if (pool[p]->flag & CREATUREFLAG_KIDNAPPED && pool[p]->align != 1)
				{
					crimes += 5 * pool[p]->joindays; // Kidnapped persons increase heat
					continue;
				}
				if (pool[p]->align != 1)continue; // Non-liberals don't count other than that
				numpres++;
				// Accumulate heat from liberals who have it, but let them bleed it off in the process
				if (pool[p]->heat > 0)
				{
					crimes += pool[p]->heat / (pool[p]->activity.type == ACTIVITY_NONE ? 60 : 10) + 1;
					pool[p]->heat -= min(pool[p]->activity.type == ACTIVITY_NONE ? pool[p]->heat / 10 : 5, pool[p]->heat);
				}
			}
			// Determine how effective your current safehouse
			// is at keeping the police confused
			location[l]->update_heat_protection();
			// Let the place cool off if not accumulating heat
			if (crimes < location[l]->heat)
			{
				location[l]->heat -= 1;
				if (location[l]->heat < 0)
					location[l]->heat = 0;
			}
			else
			{
				// Update location heat
				if (crimes > location[l]->heat) location[l]->heat += (crimes - location[l]->heat) / 10 + 1;
				// Begin planning siege if high heat on location
				if (location[l]->heat > location[l]->heat_protection &&
					LCSrandom(500) < location[l]->heat &&
					!(location[l]->siege.timeuntillocated >= 0)) //Do not re-plan siege.
				{
					// Set time until siege is carried out
					location[l]->siege.timeuntillocated += 2 + LCSrandom(6);
				}
			}
			// Sleepers at the police department may give a warning just before police raids
			if (location[l]->siege.timeuntillocated == 1)
			{
				int policesleeperwarning = 0;
				for (int pl = 0; pl < CreaturePool::getInstance().lenpool(); pl++)
				{
					if (pool[pl]->flag & CREATUREFLAG_SLEEPER &&
						pool[pl]->location != -1 &&
						location[pool[pl]->location]->type == SITE_GOVERNMENT_POLICESTATION &&
						location[pool[pl]->location]->city == location[l]->city)
					{
						//if(pool[pl]->infiltration*100>LCSrandom(50))
						{
							policesleeperwarning = 1;
							break;
						}
					}
				}
				if (policesleeperwarning)
				{
					eraseAlt();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8,  1, "You have received advance warning from your sleepers regarding ", gamelog);
					mvaddstrAlt(9,  1, "an imminent police raid on ", gamelog);
					addstrAlt(location[l]->getname());
					addstrAlt(singleDot, gamelog);
					gamelog.newline();
					if (location[l]->siege.escalationstate >= 1)
					{
						mvaddstrAlt(11,  1, "The fighting force will be composed of national guard troops.", gamelog);
					}
					if (location[l]->siege.escalationstate >= 2)
					{
						mvaddstrAlt(12,  1, "A tank will cover the entrance to the compound.", gamelog);
					}
					if (location[l]->siege.escalationstate >= 3)
					{
						mvaddstrAlt(13,  1, "Planes will bomb the compound during the siege, and the final ", gamelog);
						mvaddstrAlt(14,  1, "attack will be carried out by SEAL Team 6.", gamelog);
					}
					gamelog.nextMessage(); //Write out buffer to prepare for next message.
					mvaddstrAlt(15,  1, "Press Esc to ponder the situation...");
					int c;
					do c = getkeyAlt(); while (c != 'x'&&c != ESC);
				}
			}
			//COPS RAID THIS LOCATION
			if (!location[l]->siege.timeuntillocated)
			{
				location[l]->siege.timeuntillocated = -2;
				location[l]->heat = 0;
				if (numpres > 0)
				{
					music.play(MUSIC_SIEGE);
					eraseAlt();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8,  1, "The police have surrounded the ", gamelog);
					addstrAlt(location[l]->getname(), gamelog);
					addstrAlt("!", gamelog);
					gamelog.newline();
					location[l]->siege.underattack = 0;
					getkeyAlt();
					//MENTION ESCALATION STATE
					if (location[l]->siege.escalationstate >= 1)
					{
						mvaddstrAlt(9,  1, "National Guard troops are replacing normal SWAT units.", gamelog);
						gamelog.nextMessage();
						getkeyAlt();
					}
					if (location[l]->siege.escalationstate >= 2)
					{
						moveAlt(10, 1);
						if (location[l]->compound_walls & COMPOUND_TANKTRAPS)
							addstrAlt("An M1 Abrams Tank is stopped by the tank traps.", gamelog);
						else addstrAlt("An M1 Abrams Tank takes up position outside the compound.", gamelog);
						gamelog.nextMessage();
						getkeyAlt();
					}
					if (location[l]->siege.escalationstate >= 3)
					{
						mvaddstrAlt(11,  1, "You hear jet bombers streak overhead.", gamelog);
						gamelog.nextMessage();
						getkeyAlt();
					}
					// "You are wanted for blahblah and other crimes."
					statebrokenlaws(l);
					location[l]->siege.siege = 1;
					location[l]->siege.siegetype = SIEGE_POLICE;
					location[l]->siege.lights_off = 0;
					location[l]->siege.cameras_off = 0;
				}
				else
				{
					eraseAlt();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8,  1, "The cops have raided the ", gamelog);
					addstrAlt(location[l]->getname(), gamelog);
					addstrAlt(", an unoccupied safehouse.", gamelog);
					gamelog.newline();
					getkeyAlt();
					int y = 9;
					for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
					{
						if (pool[p]->location != l) continue;
						if (!pool[p]->alive)
						{
							mvaddstrAlt(y,  1, pool[p]->name, gamelog);
							addstrAlt("'s corpse has been recovered.", gamelog);
							gamelog.newline();
							getkeyAlt();
							delete_and_remove(pool, p);
							y++;
							continue;
						}
						if (pool[p]->align != 1)
						{
							mvaddstrAlt(y,  1, pool[p]->name, gamelog);
							addstrAlt(" has been rescued.", gamelog);
							gamelog.newline();
							getkeyAlt();
							delete_and_remove(pool, p);
							y++;
							continue;
						}
					}
					gamelog.newline();
					delete_and_clear(location[l]->loot);
					for (int v = len(vehicle) - 1; v >= 0; v--)
						if (vehicle[v]->get_location() == l)
							delete_and_remove(vehicle, v);
				}
			}
			//OTHER OFFENDABLE ENTITIES
			//CORPS
			if (location[l]->heat&&location[l]->siege.timeuntilcorps == -1 && !location[l]->siege.siege&&offended_corps&&!LCSrandom(600) && numpres > 0)
			{
				location[l]->siege.timeuntilcorps = LCSrandom(3) + 1;
				// *JDS* CEO sleepers may give a warning before corp raids
				int ceosleepercount = 0;
				for (int pl = 0; pl < CreaturePool::getInstance().lenpool(); pl++)
				{
					if (pool[pl]->flag & CREATUREFLAG_SLEEPER&&
						pool[pl]->type == CREATURE_CORPORATE_CEO)
					{
						ceosleepercount = 1;
					}
				}
				if (ceosleepercount || !LCSrandom(5))
				{
					eraseAlt();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8,  1, "You have received ", gamelog);
					if (ceosleepercount)addstrAlt("your sleeper CEO's warning", gamelog);
					else addstrAlt("an anonymous tip", gamelog);
					addstrAlt(" that the Corporations ", gamelog);
					mvaddstrAlt(9,  1, "are hiring mercenaries to attack ", gamelog);
					if (ceosleepercount)addstrAlt(location[l]->getname(), gamelog);
					else addstrAlt("the LCS", gamelog);
					addstrAlt(singleDot, gamelog);
					gamelog.nextMessage();
					getkeyAlt();
				}
			}
			else if (location[l]->siege.timeuntilcorps > 0)location[l]->siege.timeuntilcorps--; // Corp raid countdown!
			else if (location[l]->siege.timeuntilcorps == 0 && !location[l]->siege.siege&&offended_corps&&numpres > 0)
			{
				music.play(MUSIC_SIEGE);
				location[l]->siege.timeuntilcorps = -1;
				// Corps raid!
				eraseAlt();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8,  1, "Corporate mercenaries are raiding the ", gamelog);
				addstrAlt(location[l]->getname(), gamelog);
				addstrAlt("!", gamelog);
				gamelog.nextMessage();
				getkeyAlt();
				location[l]->siege.siege = 1;
				location[l]->siege.siegetype = SIEGE_CORPORATE;
				location[l]->siege.underattack = 1;
				location[l]->siege.lights_off = 0;
				location[l]->siege.cameras_off = 0;
				offended_corps = 0;
			}
			else if (location[l]->siege.timeuntilcorps == 0)location[l]->siege.timeuntilcorps = -1; // Silently call off foiled corp raids
																									//CONSERVATIVE CRIME SQUAD
			bool ccs_active = endgamestate >= ENDGAME_CCS_APPEARANCE && endgamestate < ENDGAME_CCS_DEFEATED;
			bool target_interesting = endgamestate >= ENDGAME_CCS_SIEGES || location[l]->compound_walls & COMPOUND_PRINTINGPRESS;
			if (ccs_active && target_interesting)
			{
				if (location[l]->heat&&location[l]->siege.timeuntilccs == -1 && !location[l]->siege.siege&&!LCSrandom(60) && numpres>0)
				{
					location[l]->siege.timeuntilccs = LCSrandom(3) + 1;
					// CCS sleepers may give a warning before raids
					int ccssleepercount = 0;
					for (int pl = 0; pl < CreaturePool::getInstance().lenpool(); pl++)
					{
						if (pool[pl]->flag & CREATUREFLAG_SLEEPER &&
							(pool[pl]->type == CREATURE_CCS_VIGILANTE || pool[pl]->type == CREATURE_CCS_ARCHCONSERVATIVE ||
								pool[pl]->type == CREATURE_CCS_MOLOTOV || pool[pl]->type == CREATURE_CCS_SNIPER))
						{
							ccssleepercount = 1;
							break;
						}
					}
					if (ccssleepercount > 0)
					{
						eraseAlt();
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(8,  1, "You have received a sleeper warning that the CCS ", gamelog);
						mvaddstrAlt(9,  1, " is gearing up to attack ", gamelog);
						addstrAlt(location[l]->name, gamelog);
						addstrAlt(singleDot, gamelog);
						gamelog.nextMessage();
						getkeyAlt();
					}
				}
				else if (location[l]->siege.timeuntilccs > 0)location[l]->siege.timeuntilccs--; // CCS raid countdown!
				else if (location[l]->siege.timeuntilccs == 0 && !location[l]->siege.siege&&numpres > 0)
				{
					music.play(MUSIC_SIEGE);
					location[l]->siege.timeuntilccs = -1;
					// CCS raid!
					eraseAlt();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8,  1, "A screeching truck pulls up to ", gamelog);
					addstrAlt(location[l]->getname(), gamelog);
					addstrAlt("!", gamelog);
					gamelog.newline();
					getkeyAlt();
					if (!(location[l]->compound_walls & COMPOUND_TANKTRAPS) &&
						!LCSrandom(5))
					{
						// CCS Carbombs safehouse!!
						eraseAlt();
						set_color_easy(RED_ON_BLACK_BRIGHT);
						mvaddstrAlt(8,  1, "The truck plows into the building and explodes!", gamelog);
						gamelog.nextMessage();
						getkeyAlt();
						eraseAlt();
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(0,  1, "CCS CAR BOMBING CASUALTY REPORT");
						mvaddstrAlt(2,  1, "KILLED: ");
						int killed_y = 2;
						int killed_x = 9;
						mvaddstrAlt(6,  1, "INJURED: ");
						int injured_y = 6;
						int injured_x = 10;
						for (int i = 0; i < CreaturePool::getInstance().lenpool(); i++)
						{
							if (pool[i]->location == l)
							{
								if (LCSrandom(2))
								{
									int namelength = len(pool[i]->name);
									pool[i]->blood -= LCSrandom(101 - pool[i]->juice / 10) + 10;
									if (pool[i]->blood < 0)
									{
										if (killed_x + namelength > 78)
										{
											killed_y++;
											killed_x = 1;
											//Add limit for killed_y.
										}
										moveAlt(killed_y, killed_x);
										pool[i]->die();
										set_alignment_color(pool[i]->align, false);
										addstrAlt(pool[i]->name);
										addstrAlt(commaSpace);
										killed_x += namelength + 2;
									}
									else
									{
										if (injured_x + namelength > 78)
										{
											injured_y++;
											injured_x = 1;
											//Add limit for injured_y.
										}
										moveAlt(injured_y, injured_x);
										set_alignment_color(pool[i]->align, false);
										addstrAlt(pool[i]->name);
										addstrAlt(commaSpace);
										injured_x += namelength + 2;
									}
									//set_alignment_color(pool[i]->align,false);
									//addstrAlt(pool[i]->name);
								}
							}
						}
						getkeyAlt();
					}
					else
					{
						// CCS Raids safehouse
						eraseAlt();
						set_color_easy(RED_ON_BLACK_BRIGHT);
						mvaddstrAlt(8,  1, "CCS members pour out of the truck and shoot in the front doors!", gamelog);
						gamelog.nextMessage();
						getkeyAlt();
						location[l]->siege.siege = 1;
						location[l]->siege.siegetype = SIEGE_CCS;
						location[l]->siege.underattack = 1;
						location[l]->siege.lights_off = 0;
						location[l]->siege.cameras_off = 0;
					}
				}
				else if (location[l]->siege.timeuntilccs == 0)location[l]->siege.timeuntilccs = -1; // Silently call off foiled ccs raids
			}
			//CIA
			if (location[l]->heat&&location[l]->siege.timeuntilcia == -1 && !location[l]->siege.siege&&offended_cia&&!LCSrandom(300) && numpres > 0)
			{
				location[l]->siege.timeuntilcia = LCSrandom(3) + 1;
				// *JDS* agent sleepers may give a warning before cia raids
				int agentsleepercount = 0;
				for (int pl = 0; pl < CreaturePool::getInstance().lenpool(); pl++)
				{
					if (pool[pl]->flag & CREATUREFLAG_SLEEPER&&
						pool[pl]->type == CREATURE_AGENT)
					{
						//if(pool[pl]->infiltration*100>LCSrandom(100))
						{
							agentsleepercount = 1;
							break;
						}
					}
				}
				if (agentsleepercount)
				{
					eraseAlt();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8,  1, "A sleeper agent has reported that the CIA is planning ", gamelog);
					mvaddstrAlt(9,  1, "to launch an attack on ", gamelog);
					addstrAlt(location[l]->getname(), gamelog);
					addstrAlt(singleDot, gamelog);
					gamelog.nextMessage();
					getkeyAlt();
				}
			}
			else if (location[l]->siege.timeuntilcia > 0)location[l]->siege.timeuntilcia--; // CIA raid countdown!
			else if (location[l]->siege.timeuntilcia == 0 && !location[l]->siege.siege&&offended_cia&&numpres > 0)
			{
				music.play(MUSIC_SIEGE);
				location[l]->siege.timeuntilcia = -1;
				// CIA raids!
				eraseAlt();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8,  1, "Unmarked black vans are surrounding the ", gamelog);
				addstrAlt(location[l]->getname(), gamelog);
				addstrAlt("!", gamelog);
				gamelog.newline();
				if (location[l]->compound_walls & COMPOUND_CAMERAS)
				{
					mvaddstrAlt(9,  1, "Through some form of high technology, they've managed ", gamelog);
					mvaddstrAlt(10,  1, "to shut off the lights and the cameras!", gamelog);
					gamelog.nextMessage();
				}
				else if (location[l]->compound_walls & COMPOUND_GENERATOR)
				{
					mvaddstrAlt(9,  1, "Through some form of high technology, they've managed ", gamelog);
					mvaddstrAlt(10,  1, "to shut off the lights!", gamelog);
					gamelog.nextMessage();
				}
				else
				{
					mvaddstrAlt(9,  1, "They've shut off the lights!", gamelog);
					gamelog.nextMessage();
				}
				getkeyAlt();
				location[l]->siege.siege = 1;
				location[l]->siege.siegetype = SIEGE_CIA;
				location[l]->siege.underattack = 1;
				location[l]->siege.lights_off = 1;
				location[l]->siege.cameras_off = 1;
			}
			else if (location[l]->siege.timeuntilcia == 0)location[l]->siege.timeuntilcia = -1; // Silently call off foiled cia raids
																								//HICKS
			if (!location[l]->siege.siege&&offended_amradio&&attitude[VIEW_AMRADIO] <= 35 && !LCSrandom(600) && numpres > 0)
			{
				music.play(MUSIC_SIEGE);
				eraseAlt();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8,  1, "Masses dissatisfied with your lack of respect for AM Radio ", gamelog);
				mvaddstrAlt(9,  1, "are storming the ", gamelog);
				addstrAlt(location[l]->getname(), gamelog);
				addstrAlt("!", gamelog);
				gamelog.nextMessage();
				getkeyAlt();
				location[l]->siege.siege = 1;
				location[l]->siege.siegetype = SIEGE_HICKS;
				location[l]->siege.underattack = 1;
				location[l]->siege.lights_off = 0;
				location[l]->siege.cameras_off = 0;
				offended_amradio = 0;
			}
			if (!location[l]->siege.siege&&offended_cablenews&&attitude[VIEW_CABLENEWS] <= 35 && !LCSrandom(600) && numpres > 0)
			{
				music.play(MUSIC_SIEGE);
				eraseAlt();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8,  1, "Masses dissatisfied with your lack of respect for Cable News ", gamelog);
				mvaddstrAlt(9,  1, "are storming the ", gamelog);
				addstrAlt(location[l]->getname(), gamelog);
				addstrAlt("!", gamelog);
				gamelog.nextMessage();
				getkeyAlt();
				location[l]->siege.siege = 1;
				location[l]->siege.siegetype = SIEGE_HICKS;
				location[l]->siege.underattack = 1;
				location[l]->siege.lights_off = 0;
				location[l]->siege.cameras_off = 0;
				offended_cablenews = 0;
			}
			//Firemen
			if (lawList[LAW_FREESPEECH] == -2 && location[l]->siege.timeuntilfiremen == -1 && !location[l]->siege.siege &&
				offended_firemen && numpres > 0 && location[l]->compound_walls & COMPOUND_PRINTINGPRESS && !LCSrandom(90))
			{
				location[l]->siege.timeuntilfiremen = LCSrandom(3) + 1;
				// Sleeper Firemen can warn you of an impending raid
				int firemensleepercount = 0;
				for (int pl = 0; pl < CreaturePool::getInstance().lenpool(); pl++)
					if (pool[pl]->flag & CREATUREFLAG_SLEEPER &&
						pool[pl]->type == CREATURE_FIREFIGHTER &&
						location[pool[pl]->location]->city == location[l]->city)
						firemensleepercount++;
				if (LCSrandom(firemensleepercount + 1) > 0 || !LCSrandom(10))
				{
					eraseAlt();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					moveAlt(8, 1);
					if (firemensleepercount) addstrAlt("A sleeper Fireman has informed you that ", gamelog);
					else addstrAlt("Word in the underground is that ", gamelog);
					mvaddstrAlt(9,  1, "the Firemen are planning to burn ", gamelog);
					addstrAlt(location[l]->name, gamelog);
					addstrAlt(singleDot, gamelog);
					gamelog.nextMessage();
					getkeyAlt();
				}
			}
			else if (location[l]->siege.timeuntilfiremen > 0) location[l]->siege.timeuntilfiremen--;
			else if (lawList[LAW_FREESPEECH] == -2 && location[l]->siege.timeuntilfiremen == 0 && !location[l]->siege.siege&&numpres > 0)
			{
				music.play(MUSIC_SIEGE);
				location[l]->siege.timeuntilfiremen = -1;
				// Firemen raid!
				eraseAlt();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8,  1, "Screaming fire engines pull up to the ", gamelog);
				addstrAlt(location[l]->getname(), gamelog);
				addstrAlt("!", gamelog);
				gamelog.newline();
				mvaddstrAlt(9,  1, "Armored firemen swarm out, pilot lights burning.", gamelog);
				gamelog.newline();
				getkeyAlt();
				eraseAlt();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(1,  1, "You hear a screeching voice over the sound of fire engine sirens:", gamelog);
				gamelog.newline();
				mvaddstrAlt(3,  1, "Surrender yourselves!", gamelog);
				gamelog.newline();
				mvaddstrAlt(4,  1, "Unacceptable Speech has occurred at this location.", gamelog);
				gamelog.newline();
				mvaddstrAlt(6,  1, "Come quietly and you will not be harmed.", gamelog);
				gamelog.nextMessage();
				getkeyAlt();
				location[l]->siege.siege = 1;
				location[l]->siege.siegetype = SIEGE_FIREMEN;
				location[l]->siege.underattack = 1;
				location[l]->siege.lights_off = 0;
				location[l]->siege.cameras_off = 0;
				offended_firemen = 0;
			}
			else if (lawList[LAW_FREESPEECH] == -2 && location[l]->siege.timeuntilfiremen == 0)
			{
				location[l]->siege.timeuntilfiremen = -1;
				eraseAlt();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8,  1, "The Firemen have raided the ", gamelog);
				addstrAlt(location[l]->getname(), gamelog);
				addstrAlt(", an unoccupied safehouse.", gamelog);
				gamelog.newline();
				getkeyAlt();
				int y = 9;
				for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
				{
					if (pool[p]->location != l)continue;
					if (!pool[p]->alive)
					{
						mvaddstrAlt(y++,  1, pool[p]->name, gamelog);
						addstrAlt("'s corpse has been recovered.", gamelog);
						gamelog.newline();
						getkeyAlt();
						delete_and_remove(pool, p);
						continue;
					}
					if (pool[p]->align != 1)
					{
						mvaddstrAlt(y++,  1, pool[p]->name, gamelog);
						addstrAlt(" has been rescued.", gamelog);
						gamelog.newline();
						getkeyAlt();
						delete_and_remove(pool, p);
						continue;
					}
				}
				delete_and_clear(location[l]->loot);
				if (location[l]->compound_walls & COMPOUND_PRINTINGPRESS)
				{
					mvaddstrAlt(10,  1, "The printing press is dismantled and burned.", gamelog);
					gamelog.newline();
					location[l]->compound_walls &= ~COMPOUND_PRINTINGPRESS;
					offended_firemen = 0;
				}
				if (location[l]->front_business != -1)
				{
					mvaddstrAlt(12,  1, "Materials relating to the business front have been destroyed.", gamelog);
					gamelog.newline();
					location[l]->front_business = -1;
				}
				gamelog.newline();
			}
			else if (lawList[LAW_FREESPEECH] <= -1 && location[l]->siege.timeuntilfiremen == 0)
				location[l]->siege.timeuntilfiremen = -1, offended_firemen = 0;
		}
	}
}
/* siege - checks how many people are eating at the site */
int numbereating(int loc)
{
	int eaters = 0;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++) //Must be here, alive, Liberal, and not a sleeper, to count as an eater
		if (pool[p]->location == loc && pool[p]->alive&&pool[p]->align == 1 && !(pool[p]->flag&CREATUREFLAG_SLEEPER)) eaters++;
	return eaters;
}
/* siege - updates sieges in progress */
void siegeturn(char clearformess)
{
	if (disbanding)return;
	// Count people at each location
	int l;
	//int hs=-1;
	int* liberalcount = new int[len(location)];
	char* food_prep = new char[len(location)];
	// Clear food_prep and liberalcount lists
	std::memset(food_prep, 0, len(location));
	std::memset(liberalcount, 0, sizeof(int)*len(location));
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (!pool[p]->alive)continue; // Dead people don't count
		if (pool[p]->align != 1)continue; // Non-liberals don't count
		if (pool[p]->location == -1)continue; // Vacationers don't count
		liberalcount[pool[p]->location]++;
	}
	for (l = 0; l < len(location); l++) if (location[l]->siege.siege)
	{
		//resolve sieges with no people
		if (liberalcount[l] == 0)
		{
			eraseAlt();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(8,  1, "Conservatives have raided the ", gamelog);
			addstrAlt(location[l]->getname(), gamelog);
			addstrAlt(", an unoccupied safehouse.", gamelog);
			gamelog.newline();
			if (location[l]->siege.siegetype == SIEGE_CCS&&location[l]->type == SITE_INDUSTRY_WAREHOUSE)
				location[l]->renting = RENTING_CCS; // CCS Captures warehouse
			getkeyAlt();
			int y = 9;
			for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
			{
				if (pool[p]->location != l) continue;
				if (!pool[p]->alive)
				{
					mvaddstrAlt(y++,  1, pool[p]->name);
					addstrAlt("'s corpse has been recovered.", gamelog);
					gamelog.newline();
					getkeyAlt();
					delete_and_remove(pool, p);
					continue;
				}
				if (pool[p]->align != 1)
				{
					mvaddstrAlt(y++,  1, pool[p]->name);
					addstrAlt(" has been rescued.", gamelog);
					gamelog.newline();
					getkeyAlt();
					delete_and_remove(pool, p);
					continue;
				}
			}
			delete_and_clear(location[l]->loot);
			for (int v = len(vehicle) - 1; v >= 0; v--) if (vehicle[v]->get_location() == l) delete_and_remove(vehicle, v);
			gamelog.newline();
			location[l]->siege.siege = 0;
		}
		if (!location[l]->siege.underattack)
		{
			// Seperate logging message.
			gamelog.record("A day passes while under siege...");
			gamelog.newline();
			//EAT
			bool starving = false;
			int eaters = numbereating(l);
			if (location[l]->compound_stores == 0 && eaters > 0)
			{
				starving = true;
				if (clearformess) eraseAlt();
				else makedelimiter();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8,  1, "Your Liberals are starving!", gamelog);
				gamelog.newline();
				getkeyAlt();
			}
			if (location[l]->compound_stores >= eaters) location[l]->compound_stores -= eaters;
			else location[l]->compound_stores = 0;
			//ATTACK!
			char attack = 0;
			for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
			{
				if (!pool[p]->alive || pool[p]->location != l) continue;
				if (starving) pool[p]->blood -= LCSrandom(8) + 4;
				// Check if liberal starved to death.
				if (pool[p]->blood <= 0)
				{
					pool[p]->die();
					if (clearformess) eraseAlt();
					else makedelimiter();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8,  1, pool[p]->name, gamelog);
					addstrAlt(" has starved to death.", gamelog);
					gamelog.newline();
					getkeyAlt();
				}
			}
			if (!LCSrandom(12))attack = 1;
			if (attack)
			{
				if (clearformess) eraseAlt();
				else makedelimiter();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8,  1, "The cops are coming!", gamelog);
				gamelog.newline();
				getkeyAlt();
				location[l]->siege.underattack = 1;
			}
			else
			{
				char no_bad = 1;
				//CUT LIGHTS
				if (!location[l]->siege.lights_off &&
					!(location[l]->compound_walls & COMPOUND_GENERATOR) && !LCSrandom(10))
				{
					no_bad = 0;
					if (clearformess) eraseAlt();
					else makedelimiter();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8,  1, "The police have cut the lights!", gamelog);
					gamelog.newline();
					getkeyAlt();
					location[l]->siege.lights_off = 1;
				}
				//SNIPER
				if (!(location[l]->compound_walls & COMPOUND_BASIC) && !LCSrandom(5))
				{
					no_bad = 0;
					vector<int> pol;
					for (int p = 0; p<CreaturePool::getInstance().lenpool(); p++) if (pool[p]->alive&&pool[p]->location == l) pol.push_back(p);
					if (len(pol))
					{
						if (clearformess) eraseAlt();
						else makedelimiter();
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						moveAlt(8, 1);
						int targ = pickrandom(pol);
						if ((int)LCSrandom(50)>pool[targ]->juice)
						{
							addstrAlt("A sniper takes out ", gamelog);
							addstrAlt(pool[targ]->name, gamelog);
							addstrAlt("!", gamelog);
							gamelog.newline();
							if (pool[targ]->align == 1) stat_dead++, liberalcount[l]--;
							removesquadinfo(*pool[targ]);
							pool[targ]->die();
						}
						else
						{
							addstrAlt("A sniper nearly hits ", gamelog);
							addstrAlt(pool[targ]->name, gamelog);
							addstrAlt("!", gamelog);
							gamelog.newline();
						}
						getkeyAlt();
					}
				}
				if (location[l]->siege.escalationstate >= 3 && !LCSrandom(3))
				{
					no_bad = 0;
					//AIR STRIKE!
					bool hit = true;
					if (clearformess) eraseAlt();
					else makedelimiter();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8,  1, "You hear planes streak overhead!", gamelog);
					gamelog.newline();
					getkeyAlt();
					bool hasAAGun = location[l]->compound_walls & COMPOUND_AAGUN;
					bool hasGenerator = location[l]->compound_walls & COMPOUND_GENERATOR;
					if (hasAAGun)
					{
						if (clearformess) eraseAlt();
						else makedelimiter();
						mvaddstrAlt(8,  1, "The thunder of the anti-aircraft gun shakes the compound!", gamelog);
						gamelog.newline();
						getkeyAlt();
						if (clearformess) eraseAlt();
						else makedelimiter();
						moveAlt(8, 1);
						if (LCSrandom(5))
						{
							hit = false;
							if (LCSrandom(2)) addstrAlt("You didn't shoot any down, but you've made them think twice!", gamelog);
							else
							{
								addstrAlt("Hit! One of the bombers slams into to the ground.", gamelog);
								gamelog.newline();
								getkeyAlt();
								if (clearformess) eraseAlt();
								else makedelimiter();
								mvaddstrAlt(8,  1, "It's all over the TV. Everyone in the Liberal Crime Squad gains 20 juice!", gamelog);
								for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++) addjuice(*pool[p], 20, 1000);
							}
							gamelog.newline();
							getkeyAlt();
						}
						else
						{
							addstrAlt("A skilled pilot gets through!", gamelog);
							gamelog.newline();
							getkeyAlt();
						}
					}
					if (hit)
					{
						if (clearformess) eraseAlt();
						else makedelimiter();
						mvaddstrAlt(8,  1, "Explosions rock the compound!", gamelog);
						gamelog.newline();
						getkeyAlt();
						if (hasAAGun && !LCSrandom(3))
						{
							if (clearformess) eraseAlt();
							else makedelimiter();
							mvaddstrAlt(8,  1, "The anti-aircraft gun takes a direct hit!", gamelog);
							gamelog.newline();
							getkeyAlt();
							if (clearformess) eraseAlt();
							else makedelimiter();
							mvaddstrAlt(8,  1, "There's nothing left but smoking wreckage...", gamelog);
							gamelog.newline();
							getkeyAlt();
							location[l]->compound_walls &= ~COMPOUND_AAGUN;
						}
						else if (hasGenerator && !LCSrandom(3))
						{
							if (clearformess) eraseAlt();
							else makedelimiter();
							mvaddstrAlt(8,  1, "The generator has been destroyed!", gamelog);
							gamelog.newline();
							getkeyAlt();
							if (clearformess) eraseAlt();
							else makedelimiter();
							mvaddstrAlt(8,  1, "The lights fade and all is dark.", gamelog);
							gamelog.newline();
							getkeyAlt();
							location[l]->compound_walls &= ~COMPOUND_GENERATOR;
							location[l]->siege.lights_off = 1;
						}
						if (!LCSrandom(2))
						{
							vector<int> pol;
							for (int p = 0; p<CreaturePool::getInstance().lenpool(); p++) if (pool[p]->alive&&pool[p]->location == l) pol.push_back(p);
							if (len(pol))
							{
								if (clearformess) eraseAlt();
								else makedelimiter();
								set_color_easy(WHITE_ON_BLACK_BRIGHT);
								moveAlt(8, 1);
								int targ = pickrandom(pol);
								if ((int)LCSrandom(100)>pool[targ]->juice)
								{
									addstrAlt(pool[targ]->name, gamelog);
									addstrAlt(" was killed in the bombing!", gamelog);
									gamelog.newline();
									if (pool[targ]->align == 1) stat_dead++, liberalcount[l]--;
									removesquadinfo(*pool[targ]);
									pool[targ]->die();
								}
								else
								{
									addstrAlt(pool[targ]->name, gamelog);
									addstrAlt(" narrowly avoided death!", gamelog);
									gamelog.newline();
								}
								getkeyAlt();
							}
						}
						else
						{
							if (clearformess) eraseAlt();
							else makedelimiter();
							mvaddstrAlt(8,  1, "Fortunately, no one is hurt.", gamelog);
							gamelog.newline();
							getkeyAlt();
						}
					}
				}
				if ((location[l]->compound_walls & COMPOUND_TANKTRAPS) &&
					location[l]->siege.escalationstate >= 3 && !LCSrandom(15))
				{
					no_bad = 0;
					//ENGINEERS
					if (clearformess) eraseAlt();
					else makedelimiter();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8,  1, "Army engineers have removed your tank traps.", gamelog);
					gamelog.newline();
					getkeyAlt();
					if (clearformess) moveAlt(9, 1);
					else
					{
						makedelimiter();
						moveAlt(8, 1);
					}
					addstrAlt("The tank moves forward to your compound entrance.", gamelog);
					gamelog.newline();
					getkeyAlt();
					location[l]->compound_walls &= ~COMPOUND_TANKTRAPS;
				}
				//NEED GOOD THINGS TO BALANCE THE BAD
				// ELITE REPORTER SNEAKS IN
				if (!LCSrandom(20) && no_bad&&liberalcount[l] > 0)
				{
					char repname[200];
					generate_name(repname);
					set_color_easy(WHITE_ON_BLACK);
					eraseAlt();
					mvaddstrAlt(1,  1, "Elitist ", gamelog);
					addstrAlt(repname, gamelog);
					addstrAlt(" from the ", gamelog);
					addstrAlt(pickrandom(words_meaning_news), gamelog);
					addstrAlt(singleSpace);
					addstrAlt(pickrandom(newspaper_first_name), gamelog);
					addstrAlt(singleSpace, gamelog);
					addstrAlt(pickrandom(newspaper_last_name), gamelog);
					mvaddstrAlt(2,  1, "got into the compound somehow!", gamelog);
					gamelog.newline();
					getkeyAlt();
					int best = 0;
					for (int p = 0, bestvalue = -1000; p < CreaturePool::getInstance().lenpool(); p++)
					{
						if (!pool[p]->alive || pool[p]->align != 1 || pool[p]->location != l) continue;
						int sum = pool[p]->get_attribute(ATTRIBUTE_INTELLIGENCE, true)
							+ pool[p]->get_attribute(ATTRIBUTE_HEART, true)
							+ pool[p]->get_skill(SKILL_PERSUASION)
							+ pool[p]->juice;
						if (sum > bestvalue) best = p, bestvalue = sum;
					}
					mvaddstrAlt(4,  1, pool[best]->name, gamelog);
					addstrAlt(" decides to give an interview.", gamelog);
					gamelog.newline();
					getkeyAlt();
					mvaddstrAlt(6,  1, "The interview is wide-ranging, covering a variety of topics.", gamelog);
					gamelog.newline();
					getkeyAlt();
					int segmentpower = pool[best]->attribute_roll(ATTRIBUTE_INTELLIGENCE)
						+ pool[best]->attribute_roll(ATTRIBUTE_HEART)
						+ pool[best]->skill_roll(SKILL_PERSUASION)
						+ pool[best]->skill_roll(SKILL_PERSUASION)
						+ pool[best]->skill_roll(SKILL_PERSUASION);
					moveAlt(8, 1);
					if (segmentpower < 15)
					{
						addstrAlt(repname, gamelog);
						addstrAlt(" canceled the interview halfway through", gamelog);
						mvaddstrAlt(9,  1, "and later used the material for a Broadway play called", gamelog);
						moveAlt(10, 1);
						switch (LCSrandom(insult_for_liberal.size() + 1))
						{
						case 0: if (lawList[LAW_FREESPEECH] == -2) addstrAlt("Dumb", gamelog);
								else addstrAlt("Retarded", gamelog); break;
						default:
							addstrAlt(pickrandom(insult_for_liberal));
							break;
						}
						addstrAlt(singleSpace, gamelog);
						addstrAlt(pickrandom(word_replacing_liberal));
						addstrAlt(singleDot, gamelog);
						gamelog.newline();
					}
					else if (segmentpower < 20)
					{
						addstrAlt("But the interview is so boring that ", gamelog);
						addstrAlt(repname, gamelog);
						addstrAlt(" falls asleep.", gamelog);
						gamelog.newline();
					}
					else if (segmentpower < 25)
					{
						addstrAlt("But ", gamelog);
						addstrAlt(pool[best]->name, gamelog);
						addstrAlt(" stutters nervously the whole time.", gamelog);
						gamelog.newline();
					}
					else if (segmentpower < 30)
					{
						addstrAlt(pool[best]->name, gamelog);
						addstrAlt("'s verbal finesse leaves something to be desired.", gamelog);
						gamelog.newline();
					}
					else if (segmentpower < 45)
					{
						addstrAlt(pool[best]->name, gamelog);
						addstrAlt(" represents the LCS well.", gamelog);
						gamelog.newline();
					}
					else if (segmentpower < 60)
					{
						addstrAlt("The discussion was exciting and dynamic.", gamelog);
						mvaddstrAlt(9,  1, "Even the Cable News and AM Radio spend days talking about it.", gamelog);
						gamelog.newline();
					}
					else
					{
						addstrAlt(repname);
						addstrAlt(" later went on to win a Pulitzer for it.", gamelog);
						mvaddstrAlt(9,  1, "Virtually everyone in America was moved by ", gamelog);
						addstrAlt(pool[best]->name, gamelog);
						addstrAlt("'s words.", gamelog);
						gamelog.newline();
					}
					getkeyAlt();
					//CHECK PUBLIC OPINION
					change_public_opinion(VIEW_LIBERALCRIMESQUAD, 20);
					change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, (segmentpower - 25) / 2, segmentpower + 50);
					for (int v = 0; v < 5; v++) change_public_opinion(LCSrandom(VIEWNUM - 3), (segmentpower - 25) / 2);
				}
			}
			gamelog.newline(); // single blank line after every siege day
		} // end if(!location[l]->siege.underattack)
	} // end for(l=0;l<len(location);l++) if(location[l]->siege.siege)
	delete[] liberalcount;
	delete[] food_prep;
}

/* siege - checks how many days of food left at the site */
int fooddaysleft(int loc)
{
	int eaters = numbereating(loc);
	if (eaters == 0) return -1;
	return location[loc]->compound_stores / eaters + ((location[loc]->compound_stores%eaters) > eaters / 2);
}
/* siege - what happens when you escaped the siege */
void escapesiege(char won)
{
	//TEXT IF DIDN'T WIN
	if (!won)
	{
		music.play(MUSIC_CONQUER);
		//GIVE INFO SCREEN
		eraseAlt();
		set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		mvaddstrAlt(1, 32, "You have escaped!", gamelog);
		gamelog.nextMessage();
		set_color_easy(WHITE_ON_BLACK);
		int yLevel = 3;
		for (int i = 0; i < len(engageConservativesEscape); i++) {
			mvaddstrAlt(yLevel + i, 11, engageConservativesEscape[i]);
		}
		yLevel += len(engageConservativesEscape);
		int homes = -1;
		if (activesquad)
			if (activesquad->squad[0] != NULL)
				homes = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, activesquad->squad[0]->location);
		set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		mvaddstrAlt(yLevel + 1, 11, "Press any key to split up and lay low for a few days");
		// Seperate logging text
		gamelog.log("Your Liberals split up and lay low for a few days.");
		getkeyAlt();
		//dump retrieved loot in homeless shelter - is there anywhere better to put it?
		if (activesquad&&homes != -1) location[homes]->getloot(activesquad->loot);
		activesquad = NULL; //active squad cannot be disbanded in removesquadinfo,
							//but we need to disband current squad as the people are going to be 'away'.
							//GET RID OF DEAD, etc.
		if (LocationsPool::getInstance().getRentingType(cursite) > 1)location[cursite]->renting = RENTING_NOCONTROL;
		for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
		{
			if (pool[p]->location != cursite) continue;
			if (!pool[p]->alive)
			{
				delete_and_remove(pool, p);
				continue;
			}
			//BASE EVERYONE LEFT AT HOMELESS SHELTER
			removesquadinfo(*pool[p]);
			pool[p]->hiding = LCSrandom(3) + 2;
			if (pool[p]->align == 1) // not a hostage
				pool[p]->location = -1;
			else // hostages don't go into hiding, just shove em into the homeless shelter
				pool[p]->location = homes;
			pool[p]->base = homes;
		}
		delete_and_clear(location[cursite]->loot);
		for (int v = len(vehicle) - 1; v >= 0; v--)
			if (vehicle[v]->get_location() == cursite)
				delete_and_remove(vehicle, v);
		location[cursite]->compound_walls = 0;
		location[cursite]->compound_stores = 0;
		location[cursite]->front_business = -1;
		LocationsPool::getInstance().initLocation(cursite);
	}
	//SET UP NEW SIEGE CHARACTERISTICS, INCLUDING TIMING
	location[cursite]->siege.siege = 0;
	if (won&&LocationsPool::getInstance().getSiegeType(cursite) == SIEGE_POLICE)
	{
		location[cursite]->siege.timeuntillocated = LCSrandom(4) + 4;
		location[cursite]->siege.escalationstate++;
		if (police_heat < 4) police_heat++;
	}
}
/* siege - flavor text when you fought off the raid */
void conquertext()
{
	//GIVE INFO SCREEN
	music.play(MUSIC_CONQUER);
	eraseAlt();
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(1, 26, "* * * * *   VICTORY   * * * * *", gamelog);
	gamelog.newline();
	if (LocationsPool::getInstance().getSiegeType(cursite) == SIEGE_POLICE)
	{
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(3, 16, "The Conservative automatons have been driven back ÄÄ for ", gamelog);
		mvaddstrAlt(4, 11, "the time being.  While they are regrouping, you might consider ", gamelog);
		mvaddstrAlt(5, 11, "abandoning this safe house for a safer location.", gamelog);
	}
	else
	{
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(3, 16, "The Conservative automatons have been driven back.  ", gamelog);
		mvaddstrAlt(4, 11, "Unfortunately, you will never truly be safe from ", gamelog);
		mvaddstrAlt(5, 11, "this filth until the Liberal Agenda is realized.", gamelog);
	}
	gamelog.nextMessage();
	mvaddstrAlt(7, 19, "Press C to Continue Liberally.");
	while (getkeyAlt() != 'c');
}
// Siege -- Mass combat outside safehouse
char sally_forth_aux(int loc)
{
	int p;
	reloadparty();
	siegest siege = location[loc]->siege;
	cursite = loc;
	emptyEncounter();
	switch (siege.siegetype)
	{
	case SIEGE_CIA:
	case SIEGE_HICKS:
	case SIEGE_CORPORATE:
	case SIEGE_CCS:
	case SIEGE_FIREMEN:
	default:
		// So yeah, WTF is the reason there isn't a break statement here???
		// If everything ends up in the SIEGE_POLICE case we shouldn't even have a switch statement here at all.
	case SIEGE_POLICE: // Currently only police sieges should allow this
					   // SWAT teams
		if (siege.escalationstate == 0)
			fillEncounter(CREATURE_SWAT, ENCMAX - 9);
		// Military
		else if (siege.escalationstate >= 1)
			fillEncounter(CREATURE_SOLDIER, ENCMAX - 9);
		// M1 Tank
		if (siege.escalationstate >= 2 && !(location[loc]->compound_walls & COMPOUND_TANKTRAPS))
			makecreature(encounter[ENCMAX - 9], CREATURE_TANK);
		break;
	}
	mode = GAMEMODE_CHASEFOOT;
	music.play(MUSIC_DEFENSE);
	bool ranaway = false;
	while (true)
	{
		// Count heroes
		int partysize = 0, partyalive = 0;
		for (p = 0; p < CreaturePool::getInstance().lenpool(); p++) if (pool[p]->align == 1 && pool[p]->location == cursite&&!(pool[p]->flag&CREATUREFLAG_SLEEPER))
		{
			partysize++;
			if (pool[p]->alive) partyalive++;
		}
		// Count bad guys
		int encsize = 0;
		for (int e = 0; e < ENCMAX; e++) if (encounter[e].exists) encsize++;
		// Let's roll
		autopromote(loc);
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(0,  0, location[loc]->getname());
		// Player's party
		if (partyalive == 0) party_status = -1;
		printparty();
		if (partyalive > 0)
		{
			// Options
			if (partysize > 1)set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(9,  40, change_squad_order);
			if (partysize > 0 && (party_status == -1 || partysize > 1))set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(10,  40, check_status_of_squad_liberal);
			if (party_status != -1)set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(11,  40, show_squad_liberal_status);
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(9,  1, "D - Escape");
			mvaddstrAlt(10,  1, "E - Equip");
			mvaddstrAlt(11,  1, "F - Fight!");
			mvaddstrAlt(12,  1, "G - Surrender");
		}
		else
		{
			endcheck(END_BUT_NOT_END); // play the right music in case we're dead
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(9,  1, "C - Reflect on your Conservative judgment.");
		}
		// Enemies
		printencounter();
		// check if we fought the previous loop; if so, add a blank gamelog line
		if (foughtthisround) gamelog.newline();
		foughtthisround = 0;
		int c = getkeyAlt();
		// Reflecting on your poor judgment
		if (partyalive == 0 && c == 'c'&&!endcheck())
		{
			mode = GAMEMODE_BASE;
			return 0;
		}
		// Providing orders
		if (partyalive > 0)
		{
			// Reorder
			if (c == 'o'&&partysize > 1) orderparty();
			// View status
			if (c == '0') party_status = -1;
			// Character info
			if (c >= '1'&&c <= '6') if (activesquad->squad[c - '1'] != NULL)
			{
				if (party_status == c - '1')fullstatus(party_status);
				else party_status = c - '1';
			}
			// Surrender
			if (c == 'g') giveup();
			// Run away
			if (c == 'd')
			{
				if (encounter[0].exists&&encounter[0].type == CREATURE_COP)
				{
					sitestory->crime.push_back(CRIME_FOOTCHASE);
					criminalizeparty(LAWFLAG_RESIST);
				}
				evasiverun();
				enemyattack();
				creatureadvance();
				ranaway = true;
			}
			if (c == 'f')
			{
				youattack();
				enemyattack();
				creatureadvance();
			}
			if (c == 'e') LocationsPool::getInstance().equipLoc(loc, -1);
			// Check for victory
			partysize = 0, partyalive = 0;
			for (p = 0; p < CreaturePool::getInstance().lenpool(); p++) if (pool[p]->align == 1 && pool[p]->location == cursite&&!(pool[p]->flag&CREATUREFLAG_SLEEPER))
			{
				partysize++;
				if (pool[p]->alive) partyalive++;
			}
			int baddiecount = 0;
			for (int e = 0; e < ENCMAX; e++) if (encounter[e].enemy() && encounter[e].alive&&encounter[e].exists) baddiecount++;
			if (partyalive&&!baddiecount)
			{
				for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++) for (int w = 0; w < BODYPARTNUM; w++) pool[p]->wound[w] &= ~WOUND_BLEEDING;
				mode = GAMEMODE_BASE;
				if (ranaway)
				{
					music.play(MUSIC_CONQUER);
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					clearmessagearea();
					mvaddstrAlt(16,  1, "You're free!", gamelog);
					gamelog.nextMessage();
					getkeyAlt();
					escapesiege(false);
					return 1;
				}
				else
				{
					music.play(MUSIC_CONQUER);
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					clearmessagearea();
					mvaddstrAlt(16,  1, "The siege is broken!", gamelog);
					gamelog.nextMessage();
					getkeyAlt();
					conquertext();
					escapesiege(true);
					return 2;
				}
			}
		}
	}
	mode = GAMEMODE_BASE;
	return 1;
}
/* siege - prepares for exiting the siege to fight the attackers head on */
void sally_forth()
{  //GIVE INFO SCREEN
	music.play(MUSIC_DEFENSE);
	eraseAlt();
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(1,  26, "UNDER SIEGE: ESCAPE OR ENGAGE");
	set_color_easy(WHITE_ON_BLACK);
	int yLevel = 3;
	for (int i = 0; i < len(nextSiege); i++) {
		mvaddstrAlt(yLevel + i,  11, nextSiege[i]);
	}
	yLevel++;
	yLevel += len(nextSiege);
	for (int i = 0; i < len(nextSiegeAgain); i++) {
		mvaddstrAlt(yLevel + i,  11, nextSiegeAgain[i]);
	}
	int loc = -1;
	if (selectedsiege != -1)loc = selectedsiege;
	if (activesquad != NULL)loc = activesquad->squad[0]->location;
	if (loc == -1)return;
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(23,  11, "Press any key to Confront the Conservative Aggressors");
	// Seperate logging text
	gamelog.log("Your Liberals sally forth to confront the siege.");
	getkeyAlt();
	if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_CCS&&LocationsPool::getInstance().getLocationType(loc) == SITE_INDUSTRY_WAREHOUSE)
		location[loc]->renting = RENTING_CCS; // CCS Captures warehouse -- this will be reversed if you fight them off
											  //CRIMINALIZE
	if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_POLICE) criminalizepool(LAWFLAG_RESIST, -1, loc);
	//DELETE ALL SQUADS IN THIS AREA UNLESS THEY ARE THE activesquad
	for (int sq = len(squad) - 1; sq >= 0; sq--)
		if (squad[sq] != activesquad&&squad[sq]->squad[0])
			if (squad[sq]->squad[0]->location == loc)
			{
				if (activesquad)
				{
					for (int p = 0; p < 6; p++)
					{
						if (!squad[sq]->squad[p]) continue;
						squad[sq]->squad[p]->squadid = -1;
					}
					delete_and_remove(squad, sq);
				}
				else activesquad = squad[sq];
			}
	// No squads at the location? Form a new one.
	if (!activesquad)
	{
		squad.push_back(new squadst);
		squad.back()->id = cursquadid++;
		strcpy(squad.back()->name, LocationsPool::getInstance().getLocationNameWithGetnameMethod(selectedsiege, true).c_str());
		strcat(squad.back()->name, " Defense");
		int i = 0;
		for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
			if (pool[p]->location == selectedsiege&&pool[p]->alive&&pool[p]->align == 1)
			{
				squad.back()->squad[i] = pool[p];
				pool[p]->squadid = squad.back()->id;
				if (++i >= 6) break;
			}
		activesquad = squad.back();
	}
	//MAKE SURE PARTY IS ORGANIZED
	autopromote(loc);
	//START FIGHTING
	newsstoryst *ns = new newsstoryst;
	ns->type = NEWSSTORY_SQUAD_ESCAPED;
	ns->positive = 1;
	ns->loc = loc;
	ns->siegetype = LocationsPool::getInstance().getSiegeType(loc);
	newsstory.push_back(ns);
	sitestory = ns;
	char result = sally_forth_aux(loc);
	if (result == 2) ns->type = NEWSSTORY_SQUAD_BROKESIEGE;
	// If you fail, make sure the safehouse isn't under siege anymore by
	// forcing you to "give up".
	if (result == 0)
	{
		gamelog.log("You have been defeated.");
		resolvesafehouses();
	}
}
/* siege - prepares for entering site mode to fight the siege */
void escape_engage()
{
	music.play(MUSIC_DEFENSE);
	//GIVE INFO SCREEN
	eraseAlt();
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(1,  26, "UNDER ATTACK: ESCAPE OR ENGAGE");
	set_color_easy(WHITE_ON_BLACK);
	int yLevel = 3;
	for (int i = 0; i < len(engageConservatives); i++) {
		mvaddstrAlt(yLevel + i,  11, engageConservatives[i]);
	}
	yLevel += len(engageConservatives);
	int loc = -1;
	if (selectedsiege != -1) loc = selectedsiege;
	if (activesquad != NULL) loc = activesquad->squad[0]->location;
	if (loc == -1) return;
	if (location[loc]->compound_walls&COMPOUND_CAMERAS)
	{
		mvaddstrAlt(yLevel,  16, "Your security cameras let you see units on the (M)ap.");
	}
	if (location[loc]->compound_walls&COMPOUND_TRAPS)
	{
		mvaddstrAlt(yLevel + 1,  16, "Your traps will harass the enemy, but not the Squad.");
	}
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(23,  11, "Press any key to Confront the Conservative Aggressors");
	// Seperate logging text
	gamelog.log("Your Liberals confront the Conservatives within the safehouse.");
	getkeyAlt();
	if (location[loc]->siege.siegetype == SIEGE_CCS&&LocationsPool::getInstance().getLocationType(loc) == SITE_INDUSTRY_WAREHOUSE)
		location[loc]->renting = RENTING_CCS; // CCS Captures warehouse -- this will be reversed if you fight them off
											  //CRIMINALIZE
	if (location[loc]->siege.siegetype == SIEGE_POLICE) criminalizepool(LAWFLAG_RESIST, -1, loc);
	//DELETE ALL SQUADS IN THIS AREA UNLESS THEY ARE THE activesquad
	for (int sq = len(squad) - 1; sq >= 0; sq--)
		if (squad[sq] != activesquad&&squad[sq]->squad[0])
			if (squad[sq]->squad[0]->location == loc)
			{
				if (activesquad)
				{
					for (int p = 0; p < 6; p++)
					{
						if (!squad[sq]->squad[p]) continue;
						squad[sq]->squad[p]->squadid = -1;
					}
					delete_and_remove(squad, sq);
				}
				else activesquad = squad[sq];
			}
	// No squads at the location? Form a new one.
	if (!activesquad)
	{
		squad.push_back(new squadst);
		squad.back()->id = cursquadid++;
		strcpy(squad.back()->name, LocationsPool::getInstance().getLocationNameWithGetnameMethod(selectedsiege, true).c_str());
		strcat(squad.back()->name, " Defense");
		int i = 0;
		for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++) if (pool[p]->location == selectedsiege&&pool[p]->alive&&pool[p]->align == 1)
		{
			squad.back()->squad[i] = pool[p];
			pool[p]->squadid = squad.back()->id;
			if (++i >= 6) break;
		}
		activesquad = squad.back();
	}
	//MAKE SURE PARTY IS ORGANIZED
	autopromote(loc);
	//START FIGHTING
	newsstoryst *ns = new newsstoryst;
	if (location[loc]->siege.underattack) ns->type = NEWSSTORY_SQUAD_FLEDATTACK;
	else ns->type = NEWSSTORY_SQUAD_ESCAPED;
	ns->positive = 1;
	ns->loc = loc;
	ns->siegetype = location[loc]->siege.siegetype;
	newsstory.push_back(ns);
	mode_site(loc);
}

/* siege - flavor text when you crush a CCS safe house */
void conquertextccs()
{
	music.play(MUSIC_CONQUER);
	//GIVE INFO SCREEN
	eraseAlt();
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(1,  26, "* * * * *   VICTORY   * * * * *", gamelog);
	gamelog.newline();
	if (ccs_kills < 3)
	{
		set_color_easy(WHITE_ON_BLACK);
		moveAlt(3, 16);
		if (ccs_siege_kills > 10)
		{
			addstrAlt("Gunfire still ringing in their ears, the squad revels in ", gamelog);
			mvaddstrAlt(4,  11, "their victory.  ", gamelog);
		}
		else
		{
			addstrAlt("The CCS Lieutenant lying dead at their feet, the squad ", gamelog);
			mvaddstrAlt(4,  11, "slips away.  ");
		}
		addstrAlt("The CCS Founder wasn't here, but for now, their ", gamelog);
		mvaddstrAlt(5,  11, "power has been severely weakened.  Once the safehouse cools off, ", gamelog);
		mvaddstrAlt(6,  11, "this will make a fine base for future Liberal operations.", gamelog);
	}
	else
	{
		moveAlt(3, 16);
		if (ccs_siege_kills > 10)
		{
			addstrAlt("Gunfire still ringing in their ears, the squad revels in ", gamelog);
			mvaddstrAlt(4,  11, "their final victory.  ", gamelog);
			mvaddstrAlt(6,  16, "As your Liberals pick through the remains of the safehouse, ", gamelog);
			mvaddstrAlt(7,  11, "it is increasingly clear that this was the CCS's last safehouse.", gamelog);
		}
		else
		{
			addstrAlt("The CCS Founder lying dead at their feet, the squad ", gamelog);
			mvaddstrAlt(4,  11, "slips away.  ", gamelog);
			mvaddstrAlt(6,  16, "With its Founder killed in the heart of their own base, ", gamelog);
			mvaddstrAlt(7,  11, "the last of the enemy's morale and confidence is shattered.", gamelog);
		}
		gamelog.newline();
		mvaddstrAlt(9,  16, "The CCS has been completely destroyed.  Now wasn't there a ", gamelog);
		mvaddstrAlt(10,  16, "revolution to attend to?", gamelog);
		gamelog.newline();
		mvaddstrAlt(12,  5, "+200 JUICE TO EVERYONE FOR ERADICATING THE CONSERVATIVE CRIME SQUAD", gamelog);
		for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++) addjuice(*pool[p], 200, 1000);
	}
	gamelog.nextMessage();
	mvaddstrAlt(15,  19, "Press C to Continue Liberally.");
	while (getkeyAlt() != 'c');
}
