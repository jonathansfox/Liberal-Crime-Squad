
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
// select CONST_siege000, choose CONST_siegeB247,
// then choose CONST_siege001.
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

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../basemode/baseactions.h"
// for orderparty
#include "../sitemode/sitedisplay.h"
//#include "../sitemode/advance.h"
void creatureadvance();
//#include "../sitemode/miscactions.h"
void reloadparty(bool wasteful = false);
//#include "../sitemode/sitemode.h"
void mode_site(const short loc);
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
// for void cleangonesquads();
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
// for void printfunds(int,int,char*)
#include "../common/translateid.h"
// for  int getsquad(int)
#include "../politics/politics.h"
//for  int publicmood(int l);
#include "../combat/fight.h"   
//for void autopromote(int loc);
#include "../combat/chase.h"
//for void evasiverun();
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
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

const string commaSpace = ", ";

const string CONST_siege014 = "engageConservativesEscape.txt";
const string CONST_siege013 = "engageConservatives.txt";
const string CONST_siege012 = "nextSiegeAgain.txt";
const string CONST_siege011 = "nextSiege.txt";
const string CONST_siege010 = "word_replacing_liberal.txt";
const string CONST_siege009 = "insult_for_liberal.txt";
const string CONST_siege008 = "newspaper_last_name.txt";
const string CONST_siege007 = "newspaper_first_name.txt";
const string CONST_siege006 = "words_meaning_news.txt";
vector<file_and_text_collection> siege_text_file_collection = {
	/*siege.cpp*/
	customText(&words_meaning_news, siege + CONST_siege006),
	customText(&newspaper_first_name, siege + CONST_siege007),
	customText(&newspaper_last_name, siege + CONST_siege008),
	customText(&insult_for_liberal, siege + CONST_siege009),
	customText(&word_replacing_liberal, siege + CONST_siege010),
	customText(&nextSiege, mostlyendings + CONST_siege011),
	customText(&nextSiegeAgain, mostlyendings + CONST_siege012),
	customText(&engageConservatives, mostlyendings + CONST_siege013),
	customText(&engageConservativesEscape, mostlyendings + CONST_siege014),
};

void createNewStoryMassacre(const int loc, const int killnumber) {
	extern vector<Deprecatednewsstoryst *> newsstory;

	Deprecatednewsstoryst *ns = new Deprecatednewsstoryst;
	ns->type = NEWSSTORY_MASSACRE;
	ns->loc = loc;
	ns->crime.push_back(LocationsPool::getInstance().getSiegeType(loc));
	ns->crime.push_back(killnumber);
	newsstory.push_back(ns);
}

void createNewStoryFieldAttack(const int loc) {
	extern vector<Deprecatednewsstoryst *> newsstory;
	Deprecatednewsstoryst *ns = new Deprecatednewsstoryst;
	if (LocationsPool::getInstance().isThisUnderAttack(loc)) ns->type = NEWSSTORY_SQUAD_FLEDATTACK;
	else ns->type = NEWSSTORY_SQUAD_ESCAPED;
	ns->positive = 1;
	ns->loc = loc;
	ns->siegetype = LocationsPool::getInstance().getSiegeType(loc);
	newsstory.push_back(ns);
}


void emptyEncounter();
void fillEncounter(CreatureTypes c, int numleft);
#include "../common/creaturePool.h"
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
bool hasPrintingPress(int l);
void deletePrintingPress(int loc);
void deleteCompoundWalls(int loc);
void deleteBusinessFront(int loc);
void CCSCapturesSite(int loc);
void endLocationSiege(int l);
void deleteLocationLoot(int l);
void deleteLocationVehicles(int loc);
const string CONST_siege174 = "The printing press is dismantled and burned.";
const string CONST_siege188 = "!";
const string CONST_siege177 = ", an unoccupied safehouse.";
const string CONST_siege179 = " has been rescued.";
const string CONST_siege178 = "'s corpse has been recovered.";
const string CONST_siege167 = "Surrender yourselves!";

int baddieCount();
int encounterSize();
vector<NameAndAlignment> getEncounterNameAndAlignment();
const string CONST_siege029 = "Materials relating to the business front have been taken.";
const string CONST_siege028 = "The compound is dismantled.";
const string CONST_siege026A = "Law enforcement has confiscated $";
const string CONST_siege026B = " in LCS funds.";
const string CONST_siege025 = "Fortunately, your funds remain intact.";
const string CONST_siege024 = " Liberals are taken to the police station.";
const string CONST_siege023 = "is taken to the police station.";
const string CONST_siege022 = ",";
const string CONST_siege021 = ", aka ";
const string CONST_siege020 = "The kidnap victims are rehabilitated and freed.";
const string CONST_siege019 = " is rehabilitated and freed.";
const string CONST_siege018 = " confiscate everything, including Squad weapons.";
const string CONST_siege017 = "The firemen";
const string CONST_siege016 = "The soldiers";
const string CONST_siege015 = "The police";
void surrenderToAuthorities(const int loc) {

	extern Log gamelog;
	extern short offended_firemen;
	extern short offended_amradio;
	extern short offended_cablenews;
	extern MusicClass music;
	extern vector<DeprecatedCreature *> pool;
	extern vector<Deprecatedsquadst *> squad;
	extern class Ledger ledger;

	music.play(MUSIC_SIEGE);
	int polsta = find_site_index_in_same_city(SITE_GOVERNMENT_POLICESTATION, loc);
	//END SIEGE
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_POLICE && LocationsPool::getInstance().getSiegeEscalationState(loc) == 0)
		mvaddstrAlt(1, 1, CONST_siege015, gamelog);
	else if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_POLICE && LocationsPool::getInstance().getSiegeEscalationState(loc) >= 1)
		mvaddstrAlt(1, 1, CONST_siege016, gamelog);
	else mvaddstrAlt(1, 1, CONST_siege017, gamelog);
	addstrAlt(CONST_siege018, gamelog);
	gamelog.newline();
	int kcount = 0, pcount = 0, icount = 0;
	string kname;
	string pname;
	string pcname;
	for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
	{
		if (pool[p]->location != loc || !pool[p]->getNameAndAlignment().alive) continue;
		if (pool[p]->flag&CREATUREFLAG_ILLEGALALIEN) icount++;
		if (pool[p]->flag&CREATUREFLAG_MISSING&&pool[p]->getNameAndAlignment().align == -1)
		{
			kcount++;
			kname = pool[p]->propername;
			if (pool[p]->getNameAndAlignment().type == CREATURE_RADIOPERSONALITY) offended_amradio = 1;
			if (pool[p]->getNameAndAlignment().type == CREATURE_NEWSANCHOR) offended_cablenews = 1;
			//clear InterrogationST data if deleted
			delete pool[p]->activity.intr();
		}
	}
	//CRIMINALIZE POOL IF FOUND WITH KIDNAP VICTIM OR ALIEN
	if (kcount) criminalizepool(LAWFLAG_KIDNAPPING, -1, loc);
	if (icount) criminalizepool(LAWFLAG_HIREILLEGAL, -1, loc);
	if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_FIREMEN && hasPrintingPress(loc))
		criminalizepool(LAWFLAG_SPEECH, -1, loc); // Criminalize pool for unacceptable speech
												  //LOOK FOR PRISONERS (MUST BE AFTER CRIMINALIZATION ABOVE)
	for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
	{
		if (pool[p]->location != loc || !pool[p]->getNameAndAlignment().alive) continue;
		if (iscriminal(pool[p]->getCreatureJustice()) && !(pool[p]->flag&CREATUREFLAG_MISSING&&pool[p]->getNameAndAlignment().align == -1))
		{
			pcount++;
			pname = pool[p]->propername;
			pcname = pool[p]->getNameAndAlignment().name;
		}
	}
	if (kcount == 1)
	{
		mvaddstrAlt(3, 1, kname);
		addstrAlt(CONST_siege019, gamelog);
		gamelog.newline();
	}
	if (kcount > 1)
	{
		mvaddstrAlt(3, 1, CONST_siege020, gamelog);
		gamelog.newline();
	}
	if (pcount == 1)
	{
		mvaddstrAlt(5, 1, pname, gamelog);
		if (pname == pcname)
		{
			addstrAlt(CONST_siege021, gamelog);
			addstrAlt(pcname, gamelog);
			addstrAlt(CONST_siege022, gamelog);
		}
		mvaddstrAlt(6, 1, CONST_siege023, gamelog);
		gamelog.newline();
	}
	if (pcount > 1)
	{
		mvaddstrAlt(5, 1, pcount, gamelog);
		addstrAlt(CONST_siege024, gamelog);
		gamelog.newline();
	}
	if (ledger.get_funds() > 0)
	{
		if (ledger.get_funds() <= 2000 || LocationsPool::getInstance().getSiegeType(loc) == SIEGE_FIREMEN)
		{
			mvaddstrAlt(8, 1, CONST_siege025, gamelog);
			gamelog.newline();
		}
		else
		{
			int confiscated = LCSrandom(LCSrandom(ledger.get_funds() - 2000) + 1) + 1000;
			if (ledger.get_funds() - confiscated > 50000)
				confiscated += ledger.get_funds() - 30000 - LCSrandom(20000) - confiscated;
			mvaddstrAlt(8, 1, CONST_siege026A + tostring(confiscated) + CONST_siege026B, gamelog);
			gamelog.newline();
			ledger.subtract_funds(confiscated, EXPENSE_CONFISCATED);
		}
	}
	if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_FIREMEN)
	{
		if (hasPrintingPress(loc))
		{
			mvaddstrAlt(10, 1, CONST_siege174, gamelog);
			gamelog.newline();
			deletePrintingPress(loc);
		}
	}
	else
	{
		if (LocationsPool::getInstance().get_specific_integer(INT_GETCOMPOUNDWALLS, loc))
		{
			mvaddstrAlt(10, 1, CONST_siege028, gamelog);
			gamelog.newline();
			deleteCompoundWalls(loc);
		}
	}
	if (LocationsPool::getInstance().isThisAFront(loc) != -1)
	{
		mvaddstrAlt(12, 1, CONST_siege029, gamelog);
		gamelog.newline();
		deleteBusinessFront(loc);
	}
	pressAnyKey();
	if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_FIREMEN)
		offended_firemen = 0; // Firemen do not hold grudges
	for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
	{
		if (pool[p]->location != loc) continue;
		//ALL KIDNAP VICTIMS FREED REGARDLESS OF CRIMES
		if ((pool[p]->flag & CREATUREFLAG_MISSING) ||
			!pool[p]->getNameAndAlignment().alive)
		{
			// Clear actions for anybody who was tending to this person
			for (int i = 0; i < CreaturePool::getInstance().lenpool(); i++)
				if (pool[i]->getNameAndAlignment().alive&&pool[i]->activity.type == ACTIVITY_HOSTAGETENDING && pool[i]->activity.arg == pool[p]->id)
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
		if (iscriminal(pool[p]->getCreatureJustice()))
		{
			removesquadinfo(*pool[p]);
			pool[p]->location = polsta;
			pool[p]->activity.type = ACTIVITY_NONE;
		}
	}
}

short getCurrentSite();
void setCurrentSite(const short i);
void surrenderAndDie(const int loc) {
	const string CONST_siege031 = " is slain.";
	const string CONST_siege030 = "Everyone in the ";

	extern int stat_dead;
	extern Log gamelog;
	extern MusicClass music;
	extern vector<DeprecatedCreature *> pool;

	//OTHERWISE IT IS SUICIDE
	int killnumber = 0;
	for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
	{
		if (pool[p]->location != loc) continue;
		if (pool[p]->getNameAndAlignment().alive&&pool[p]->getNameAndAlignment().align == 1) stat_dead++;
		killnumber++;
		removesquadinfo(*pool[p]);
		pool[p]->die();
		pool[p]->location = -1;
	}
	if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_CCS && LocationsPool::getInstance().getLocationType(loc) == SITE_INDUSTRY_WAREHOUSE)
		CCSCapturesSite(loc);
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(1, 1, CONST_siege030, gamelog);
	addstrAlt(LocationsPool::getInstance().getLocationName(loc), gamelog);
	addstrAlt(CONST_siege031, gamelog);
	gamelog.newline();
	if (!endcheck(-2)) music.play(MUSIC_SIEGE); // play correct music for if we lost the game or didn't lose it
	pressAnyKey();
	createNewStoryMassacre(loc, killnumber);
	//MUST SET cursite TO SATISFY endcheck() CODE
	int tmp = getCurrentSite();
	setCurrentSite(loc);
	endcheck();
	setCurrentSite(tmp);
}
const string singleSpace = " ";
void giveup()
{
	extern Log gamelog;
	extern Deprecatedsquadst *activesquad;
	extern int selectedsiege;
	int loc = -1;
	if (selectedsiege != -1)loc = selectedsiege;
	if (activesquad != NULL)loc = activesquad->squad[0]->location;
	if (loc == -1)return;
	if (LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE, loc) > 1)LocationsPool::getInstance().setRenting(loc, RENTING_NOCONTROL);
	//IF POLICE, END SIEGE
	if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_POLICE ||
		LocationsPool::getInstance().getSiegeType(loc) == SIEGE_FIREMEN)
	{
		surrenderToAuthorities(loc);
		endLocationSiege(loc);
	}
	else
	{
		surrenderAndDie(loc);
		endLocationSiege(loc);
	}
	//CONFISCATE MATERIAL
	deleteLocationLoot(loc);
	deleteLocationVehicles(loc);
	gamelog.newline();
}
void resolvesafehouses()
{
	extern int selectedsiege;
	for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
	{
		if (LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE,l) >= 0 && LocationsPool::getInstance().isThereASiegeHere(l))
		{
			cleangonesquads();
			selectedsiege = l; // hack for calling giveup()
			giveup();
		}
	}
}

const string CONST_siege074 = "You are wanted for harboring a fugitive from justice";
const string CONST_siege073 = "You are wanted for loitering";
const string CONST_siege072 = "You are wanted for indecent exposure";
const string CONST_siege071 = "You are wanted for disturbing the peace";
const string CONST_siege070 = "You are wanted for resisting arrest";
const string CONST_siege069 = "You are wanted for vandalism";
const string CONST_siege068 = "You are wanted for breaking and entering";
const string CONST_siege067 = "You are wanted for unlawful burial";
const string CONST_siege066 = "You are wanted for unlawful access of an information system";
const string CONST_siege065 = "You are wanted for interference with interstate commerce";
const string CONST_siege061 = "You are wanted for prostitution";
const string CONST_siege060 = "You are wanted for petty larceny";
const string CONST_siege059 = "You are wanted for credit card fraud";
const string CONST_siege058 = "You are wanted for grand theft auto";
const string CONST_siege057 = "You are wanted for misdemeanor assault";
const string CONST_siege056 = "You are wanted for assault with a deadly weapon";
const string CONST_siege055 = "You are wanted for extortion";
const string CONST_siege054 = "You are wanted for racketeering";
const string CONST_siege053 = "You are wanted for jury tampering";
const string CONST_siege052 = "You are wanted for aiding a prison escape";
const string CONST_siege051 = "You are wanted for escaping prison";
const string CONST_siege050 = "You are wanted for sale and distribution of a controlled substance";
const string CONST_siege049 = "You are wanted for sedition";
const string CONST_siege045 = "You are wanted for arson";
const string CONST_siege044 = "You are wanted for bank robbery";
const string CONST_siege043 = "You are wanted for kidnapping";
const string CONST_siege042 = "You are wanted for first degree murder";
const string CONST_siege041 = "You are wanted for terrorism";
const string CONST_siege040 = "You are wanted for treason";
map<Lawflags, string> youAreWantedForThis = {

	//TREASON
	map<Lawflags, string>::value_type(LAWFLAG_TREASON, CONST_siege040),
	//TERRORISM
	map<Lawflags, string>::value_type(LAWFLAG_TERRORISM, CONST_siege041),
	//MURDERER
	map<Lawflags, string>::value_type(LAWFLAG_MURDER, CONST_siege042),
	//KIDNAPPER
	map<Lawflags, string>::value_type(LAWFLAG_KIDNAPPING, CONST_siege043),
	//BANK ROBBER
	map<Lawflags, string>::value_type(LAWFLAG_BANKROBBERY, CONST_siege044),
	//ARSONIST
	map<Lawflags, string>::value_type(LAWFLAG_ARSON, CONST_siege045),
	//SPEECH
	map<Lawflags, string>::value_type(LAWFLAG_SPEECH, CONST_siege049),
	//BROWNIES
	map<Lawflags, string>::value_type(LAWFLAG_BROWNIES, CONST_siege050),
	//ESCAPED
	map<Lawflags, string>::value_type(LAWFLAG_ESCAPED, CONST_siege051),
	//HELP ESCAPED
	map<Lawflags, string>::value_type(LAWFLAG_HELPESCAPE, CONST_siege052),
	//JURY
	map<Lawflags, string>::value_type(LAWFLAG_JURY, CONST_siege053),
	//RACKETEERING
	map<Lawflags, string>::value_type(LAWFLAG_RACKETEERING, CONST_siege054),
	//EXTORTION
	map<Lawflags, string>::value_type(LAWFLAG_EXTORTION, CONST_siege055),
	//ASSAULT
	map<Lawflags, string>::value_type(LAWFLAG_ARMEDASSAULT, CONST_siege056),
	//ASSAULT
	map<Lawflags, string>::value_type(LAWFLAG_ASSAULT, CONST_siege057),
	//CAR THEFT
	map<Lawflags, string>::value_type(LAWFLAG_CARTHEFT, CONST_siege058),
	//CC FRAUD
	map<Lawflags, string>::value_type(LAWFLAG_CCFRAUD, CONST_siege059),
	//THIEF
	map<Lawflags, string>::value_type(LAWFLAG_THEFT, CONST_siege060),
	//PROSTITUTION
	map<Lawflags, string>::value_type(LAWFLAG_PROSTITUTION, CONST_siege061),
	//COMMERCE
	map<Lawflags, string>::value_type(LAWFLAG_COMMERCE, CONST_siege065),
	//INFORMATION
	map<Lawflags, string>::value_type(LAWFLAG_INFORMATION, CONST_siege066),
	//UNLAWFUL BURIAL
	map<Lawflags, string>::value_type(LAWFLAG_BURIAL, CONST_siege067),
	//BREAKING
	map<Lawflags, string>::value_type(LAWFLAG_BREAKING, CONST_siege068),
	//VANDALISM
	map<Lawflags, string>::value_type(LAWFLAG_VANDALISM, CONST_siege069),
	//RESIST
	map<Lawflags, string>::value_type(LAWFLAG_RESIST, CONST_siege070),
	//DISTURBANCE
	map<Lawflags, string>::value_type(LAWFLAG_DISTURBANCE, CONST_siege071),
	//PUBLIC NUDITY
	map<Lawflags, string>::value_type(LAWFLAG_PUBLICNUDITY, CONST_siege072),
	//LOITERING
	map<Lawflags, string>::value_type(LAWFLAG_LOITERING, CONST_siege073),
};
void printSpecificCrime(const Lawflags crime) {
	extern Log gamelog;
	mvaddstrAlt(4, 1, youAreWantedForThis[crime], gamelog);
}
/* siege - CONST_siege032 */
const string CONST_siege075 = " and other crimes";
const string CONST_siege062 = "You are wanted for hiring an illegal alien";
const string CONST_siege048 = "You are wanted for flag burning";
const string CONST_siege047 = "You are wanted for felony flag burning";
const string CONST_siege046 = "You are wanted for Flag Murder";
const string CONST_siege039 = " unharmed!";
const string CONST_siege038 = " and the others";
const string CONST_siege037 = "Release ";
const string CONST_siege035 = "In the name of God, your campaign of terror ends here!";
const string CONST_siege034 = "You hear a blaring voice on a loudspeaker:";
const string CONST_siege033 = "You hear shouts:";
const string CONST_siegeB252 = "You are wanted for hiring an undocumented worker";
void statebrokenlaws(int loc)
{
	extern Log gamelog;
	extern MusicClass music;
	extern short lawList[LAWNUM];
	extern vector<DeprecatedCreature *> pool;
	music.play(MUSIC_SIEGE);
	short breakercount[LAWFLAGNUM] = { 0 };
	int typenum = 0, criminalcount = 0, kidnapped = 0;
	string kname;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (!pool[p]->getNameAndAlignment().alive || pool[p]->location != loc) continue;
		if (pool[p]->flag&CREATUREFLAG_KIDNAPPED)
		{
			kname = pool[p]->propername;
			kidnapped++;
		}
		if (iscriminal(pool[p]->getCreatureJustice())) criminalcount++;
		CreatureJustice cr_just = pool[p]->getCreatureJustice();
		for (int i = 0; i < LAWFLAGNUM; i++) if (cr_just.crimes_suspected[i]) breakercount[i]++;
	}
	for (int i = 0; i < LAWFLAGNUM; i++) if (breakercount[i]) typenum++;
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	if (LocationsPool::getInstance().isThisUnderAttack(loc)) mvaddstrAlt(1, 1, CONST_siege033, gamelog);
	else mvaddstrAlt(1, 1, CONST_siege034, gamelog);
	gamelog.newline();
	if (LocationsPool::getInstance().getSiegeEscalationState(loc) >= 2 && publicmood(-1) < 20)
		mvaddstrAlt(3, 1, CONST_siege035, gamelog);
	else mvaddstrAlt(3, 1, CONST_siege167, gamelog);
	gamelog.newline();
	//KIDNAP VICTIM
	if (kidnapped)
	{
		mvaddstrAlt(4, 1, CONST_siege037, gamelog);
		addstrAlt(kname, gamelog);
		if (kidnapped > 1) addstrAlt(CONST_siege038, gamelog);
		addstrAlt(CONST_siege039, gamelog);
	}
	//TREASON
	else if (breakercount[LAWFLAG_TREASON])
		printSpecificCrime(LAWFLAG_TREASON);
	//TERRORISM
	else if (breakercount[LAWFLAG_TERRORISM])
		printSpecificCrime(LAWFLAG_TERRORISM);
	//MURDERER
	else if (breakercount[LAWFLAG_MURDER])
		printSpecificCrime(LAWFLAG_MURDER);
	//KIDNAPPER
	else if (breakercount[LAWFLAG_KIDNAPPING])
		printSpecificCrime(LAWFLAG_KIDNAPPING);
	//BANK ROBBER
	else if (breakercount[LAWFLAG_BANKROBBERY])
		printSpecificCrime(LAWFLAG_BANKROBBERY);
	//ARSONIST
	else if (breakercount[LAWFLAG_ARSON])
		printSpecificCrime(LAWFLAG_ARSON);
	//BURN FLAG
	else if (breakercount[LAWFLAG_BURNFLAG])
	{
		if (lawList[LAW_FLAGBURNING] == -2)mvaddstrAlt(4, 1, CONST_siege046, gamelog);
		else if (lawList[LAW_FLAGBURNING] == -1)mvaddstrAlt(4, 1, CONST_siege047, gamelog);
		else mvaddstrAlt(4, 1, CONST_siege048, gamelog);
	}
	//SPEECH
	else if (breakercount[LAWFLAG_SPEECH])
		printSpecificCrime(LAWFLAG_SPEECH);
	//BROWNIES
	else if (breakercount[LAWFLAG_BROWNIES])
		printSpecificCrime(LAWFLAG_BROWNIES);
	//ESCAPED
	else if (breakercount[LAWFLAG_ESCAPED])
		printSpecificCrime(LAWFLAG_ESCAPED);
	//HELP ESCAPED
	else if (breakercount[LAWFLAG_HELPESCAPE])
		printSpecificCrime(LAWFLAG_HELPESCAPE);
	//JURY
	else if (breakercount[LAWFLAG_JURY])
		printSpecificCrime(LAWFLAG_JURY);
	//RACKETEERING
	else if (breakercount[LAWFLAG_RACKETEERING])
		printSpecificCrime(LAWFLAG_RACKETEERING);
	//EXTORTION
	else if (breakercount[LAWFLAG_EXTORTION])
		printSpecificCrime(LAWFLAG_EXTORTION);
	//ASSAULT
	else if (breakercount[LAWFLAG_ARMEDASSAULT])
		printSpecificCrime(LAWFLAG_ARMEDASSAULT);
	//ASSAULT
	else if (breakercount[LAWFLAG_ASSAULT])
		printSpecificCrime(LAWFLAG_ASSAULT);
	//CAR THEFT
	else if (breakercount[LAWFLAG_CARTHEFT])
		printSpecificCrime(LAWFLAG_CARTHEFT);
	//CC FRAUD
	else if (breakercount[LAWFLAG_CCFRAUD])
		printSpecificCrime(LAWFLAG_CCFRAUD);
	//THIEF
	else if (breakercount[LAWFLAG_THEFT])
		printSpecificCrime(LAWFLAG_THEFT);
	//PROSTITUTION
	else if (breakercount[LAWFLAG_PROSTITUTION])
		printSpecificCrime(LAWFLAG_PROSTITUTION);
	//HIRE ILLEGAL
	else if (breakercount[LAWFLAG_HIREILLEGAL])
		mvaddstrAlt(4, 1, (lawList[LAW_IMMIGRATION] < 1 ? CONST_siege062 : CONST_siegeB252), gamelog);
	//COMMERCE
	else if (breakercount[LAWFLAG_COMMERCE])
		printSpecificCrime(LAWFLAG_COMMERCE);
	//INFORMATION
	else if (breakercount[LAWFLAG_INFORMATION])
		printSpecificCrime(LAWFLAG_INFORMATION);
	//UNLAWFUL BURIAL
	else if (breakercount[LAWFLAG_BURIAL])
		printSpecificCrime(LAWFLAG_BURIAL);
	//BREAKING
	else if (breakercount[LAWFLAG_BREAKING])
		printSpecificCrime(LAWFLAG_BREAKING);
	//VANDALISM
	else if (breakercount[LAWFLAG_VANDALISM])
		printSpecificCrime(LAWFLAG_VANDALISM);
	//RESIST
	else if (breakercount[LAWFLAG_RESIST])
		printSpecificCrime(LAWFLAG_RESIST);
	//DISTURBANCE
	else if (breakercount[LAWFLAG_DISTURBANCE])
		printSpecificCrime(LAWFLAG_DISTURBANCE);
	//PUBLIC NUDITY
	else if (breakercount[LAWFLAG_PUBLICNUDITY])
		printSpecificCrime(LAWFLAG_PUBLICNUDITY);
	//LOITERING
	else if (breakercount[LAWFLAG_LOITERING])
		printSpecificCrime(LAWFLAG_LOITERING);
	//THEY WERE LOOKING FOR SOMEONE ELSE
	else mvaddstrAlt(4, 1, CONST_siege074, gamelog);
	if (!kidnapped)
	{
		if (typenum > 1) addstrAlt(CONST_siege075, gamelog);
		addstrAlt(singleDot, gamelog);
	}
	gamelog.nextMessage();
	pressAnyKey();
}

const string CONST_siegeB254 = "HIRING UNDOCUMENTED WORKERS";
const string CONST_siegeB253 = "FLAG BURNING";
const string CONST_siege109 = "LOITERING";
const string CONST_siege108 = "PUBLIC NUDITY";
const string CONST_siege107 = "DISTURBING THE PEACE";
const string CONST_siege106 = "RESISTING ARREST";
const string CONST_siege105 = "VANDALISM";
const string CONST_siege104 = "BREAKING AND ENTERING";
const string CONST_siege103 = "UNLAWFUL BURIAL";
const string CONST_siege102 = "HACKING";
const string CONST_siege101 = "ELECTRONIC SABOTAGE";
const string CONST_siege098 = "HIRING ILLEGAL ALIENS";
const string CONST_siege097 = "PROSTITUTION";
const string CONST_siege096 = "THEFT";
const string CONST_siege095 = "CREDIT CARD FRAUD";
const string CONST_siege094 = "GRAND THEFT AUTO";
const string CONST_siege093 = "ASSAULT";
const string CONST_siege092 = "ARMED ASSAULT";
const string CONST_siege091 = "EXTORTION";
const string CONST_siege090 = "RACKETEERING";
const string CONST_siege089 = "JURY TAMPERING";
const string CONST_siege088 = "RELEASING PRISONERS";
const string CONST_siege087 = "ESCAPING PRISON";
const string CONST_siege086 = "DRUG DEALING";
const string CONST_siege085 = "HARMFUL SPEECH";
const string CONST_siege084 = "FLAG MURDER";
const string CONST_siege083 = "ARSON";
const string CONST_siege082 = "BANK ROBBERY";
const string CONST_siege081 = "KIDNAPPING";
const string CONST_siege080 = "MURDER";
const string CONST_siege079 = "TERRORISM";
const string CONST_siege078 = "TREASON";
map<int, string> mostSeriousCrime = {

	map<int, string>::value_type(LAWFLAG_TREASON,
	CONST_siege078),
	//TERRORISM
	map<int, string>::value_type(LAWFLAG_TERRORISM,
	CONST_siege079),
	//MURDERER
	map<int, string>::value_type(LAWFLAG_MURDER,
	CONST_siege080),
	//KIDNAPPER
	map<int, string>::value_type(LAWFLAG_KIDNAPPING,
	CONST_siege081),
	//BANK ROBBER
	map<int, string>::value_type(LAWFLAG_BANKROBBERY,
	CONST_siege082),
	//ARSONIST
	map<int, string>::value_type(LAWFLAG_BANKROBBERY,
	CONST_siege083),
	//BURN FLAG
	//map<int, string>::value_type(LAWFLAG_BURNFLAG,
	//lawList[LAW_FLAGBURNING] == -2 ? CONST_siege084 : CONST_siegeB253),
};
map<int, string> mostSeriousCrime2 = {
	//BURN FLAG
	//map<int, string>::value_type(LAWFLAG_BURNFLAG,
	//lawList[LAW_FLAGBURNING] == -2 ? CONST_siege084 : CONST_siegeB253),
	//SPEECH
	map<int, string>::value_type(LAWFLAG_SPEECH,
	CONST_siege085),
	//BROWNIES
	map<int, string>::value_type(LAWFLAG_BROWNIES,
	CONST_siege086),
	//ESCAPED
	map<int, string>::value_type(LAWFLAG_ESCAPED,
	CONST_siege087),
	//HELP ESCAPED
	map<int, string>::value_type(LAWFLAG_HELPESCAPE,
	CONST_siege088),
	//JURY
	map<int, string>::value_type(LAWFLAG_JURY,
	CONST_siege089),
	//RACKETEERING
	map<int, string>::value_type(LAWFLAG_RACKETEERING,
	CONST_siege090),
	//EXTORTION
	map<int, string>::value_type(LAWFLAG_EXTORTION,
	CONST_siege091),
	//ASSAULT
	map<int, string>::value_type(LAWFLAG_ARMEDASSAULT,
	CONST_siege092),
	//ASSAULT
	map<int, string>::value_type(LAWFLAG_ASSAULT,
	CONST_siege093),
	//CAR THEFT
	map<int, string>::value_type(LAWFLAG_CARTHEFT,
	CONST_siege094),
	//CC FRAUD
	map<int, string>::value_type(LAWFLAG_CCFRAUD,
	CONST_siege095),
	//THIEF
	map<int, string>::value_type(LAWFLAG_THEFT,
	CONST_siege096),
	//PROSTITUTION
	map<int, string>::value_type(LAWFLAG_PROSTITUTION,
	CONST_siege097),
	//HIRE ILLEGAL
	//map<int, string>::value_type(LAWFLAG_HIREILLEGAL,
	//lawList[LAW_IMMIGRATION] < 1 ? CONST_siege098 : CONST_siegeB254),
};
map<int, string> mostSeriousCrime3 = {
	//HIRE ILLEGAL
	//map<int, string>::value_type(LAWFLAG_HIREILLEGAL,
	//lawList[LAW_IMMIGRATION] < 1 ? CONST_siege098 : CONST_siegeB254),
	//COMMERCE
	map<int, string>::value_type(LAWFLAG_COMMERCE,
	CONST_siege101),
	//INFORMATION
	map<int, string>::value_type(LAWFLAG_INFORMATION,
	CONST_siege102),
	//UNLAWFUL BURIAL
	map<int, string>::value_type(LAWFLAG_BURIAL,
	CONST_siege103),
	//BREAKING
	map<int, string>::value_type(LAWFLAG_BREAKING,
	CONST_siege104),
	//VANDALISM
	map<int, string>::value_type(LAWFLAG_VANDALISM,
	CONST_siege105),
	//RESIST
	map<int, string>::value_type(LAWFLAG_RESIST,
	CONST_siege106),
	//DISTURBANCE
	map<int, string>::value_type(LAWFLAG_DISTURBANCE,
	CONST_siege107),
	//PUBLIC NUDITY
	map<int, string>::value_type(LAWFLAG_PUBLICNUDITY,
	CONST_siege108),
	//LOITERING
	map<int, string>::value_type(LAWFLAG_LOITERING,
	CONST_siege109),
};
void printMostSeriousCrime(const bool breakercount[LAWFLAGNUM]) {

	extern short lawList[LAWNUM];
	for (auto const& x : mostSeriousCrime)
	{
		if (breakercount[x.first]) {
			addstrAlt(x.second);
			return;
		}
	}

	if (breakercount[LAWFLAG_BURNFLAG]) {
		addstrAlt(lawList[LAW_FLAGBURNING] == -2 ? CONST_siege084 : CONST_siegeB253);
		return;
	}

	for (auto const& x : mostSeriousCrime2)
	{
		if (breakercount[x.first]) {
			addstrAlt(x.second);
			return;
		}
	}

	if (breakercount[LAWFLAG_HIREILLEGAL]){
		addstrAlt(lawList[LAW_IMMIGRATION] < 1 ? CONST_siege098 : CONST_siegeB254);
		return;
	}

	for (auto const& x : mostSeriousCrime3)
	{
		if (breakercount[x.first]) {
			addstrAlt(x.second);
			return;
		}
	}
}
void statebrokenlaws(CreatureJustice cr, const int flag)
{
	const string CONST_siege077 = "REHABILITATION";
	const string CONST_siege076 = "WANTED FOR ";
	bool kidnapped = (flag&CREATUREFLAG_KIDNAPPED);
	bool criminal = false;
	bool breakercount[LAWFLAGNUM];
	for (int i = 0; i < LAWFLAGNUM; i++) {
		if (cr.crimes_suspected[i]) { 
			breakercount[i] = true;
			criminal = true;
		}
		else { 
			breakercount[i] = false;
		}
	}
		if (!criminal && !kidnapped) return;

		set_color_easy(YELLOW_ON_BLACK_BRIGHT);

		addstrAlt(CONST_siege076);
		//KIDNAP VICTIM
		if (kidnapped) {
			addstrAlt(CONST_siege077);
		}
		else {
			printMostSeriousCrime(breakercount);
		}
}
/* siege - updates upcoming sieges */
void dropHeatByFivePercent(int l);
int getTimeUntilSiege(int l);
void huntFasterIfSiteIncrediblyHot(int l);
void updateLocationHeatProtection(int l);
void letPlaceCoolOffUnlessCrime(int crimes, int l);
void policeSiege(int l);
void corporateSiege(int l);
void CCSSiege(int l);
void CIASiege(int l);
void hicksSiege(int l);
void firemanSiege(int l);
bool hasCameras(int l);
bool hasAGenerator(int l);
bool hasBusinessFront(int l);
bool siteHasAAGun(int l);
void deleteAAGun(int l);

int allCreatureHeatGeneration(const int l, int& numpres) {
	extern Log gamelog;
	extern short offended_corps;
	int crimes = 0;
	extern vector<DeprecatedCreature *> pool;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		// Sleepers and people not at this base don't count
		if (pool[p]->location != l || pool[p]->flag & CREATUREFLAG_SLEEPER)continue;
		if (!pool[p]->getNameAndAlignment().alive) // Corpses attract attention
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
	return crimes;
}
void possibleWarningFromSleepers(const int l) {
	extern Log gamelog;

	const string CONST_siege116 = "Press Esc to ponder the situation...";
	const string CONST_siege115 = "attack will be carried out by SEAL Team 6.";
	const string CONST_siege114 = "Planes will bomb the compound during the siege, and the final ";
	const string CONST_siege113 = "A tank will cover the entrance to the compound.";
	const string CONST_siege112 = "The fighting force will be composed of national guard troops.";
	const string CONST_siege111 = "an imminent police raid on ";
	const string CONST_siege110 = "You have received advance warning from your sleepers regarding ";

	extern vector<DeprecatedCreature *> pool;
	int policesleeperwarning = 0;
	for (int pl = 0; pl < CreaturePool::getInstance().lenpool(); pl++)
	{
		if (pool[pl]->flag & CREATUREFLAG_SLEEPER &&
			pool[pl]->location != -1 &&
			LocationsPool::getInstance().getLocationType(pool[pl]->location) == SITE_GOVERNMENT_POLICESTATION &&
			LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONCITY,pool[pl]->location) == LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONCITY,l))
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
		mvaddstrAlt(8, 1, CONST_siege110, gamelog);
		mvaddstrAlt(9, 1, CONST_siege111, gamelog);
		addstrAlt(LocationsPool::getInstance().getLocationName(l));
		addstrAlt(singleDot, gamelog);
		gamelog.newline();
		if (LocationsPool::getInstance().getSiegeEscalationState(l) >= 1)
		{
			mvaddstrAlt(11, 1, CONST_siege112, gamelog);
		}
		if (LocationsPool::getInstance().getSiegeEscalationState(l) >= 2)
		{
			mvaddstrAlt(12, 1, CONST_siege113, gamelog);
		}
		if (LocationsPool::getInstance().getSiegeEscalationState(l) >= 3)
		{
			mvaddstrAlt(13, 1, CONST_siege114, gamelog);
			mvaddstrAlt(14, 1, CONST_siege115, gamelog);
		}
		gamelog.nextMessage(); //Write out buffer to prepare for next message.
		mvaddstrAlt(15, 1, CONST_siege116);
		pressSpecificKey('x', ESC);
	}
}
void policeSiegePrintNonePresent(const int l) {

	extern Log gamelog;

	extern MusicClass music;
	extern vector<DeprecatedCreature *> pool;

	const string CONST_siege124 = "The cops have raided the ";

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege124, gamelog);
	addstrAlt(LocationsPool::getInstance().getLocationName(l), gamelog);
	addstrAlt(CONST_siege177, gamelog);
	gamelog.newline();
	pressAnyKey();
	int y = 9;
	for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
	{
		if (pool[p]->location != l) continue;
		if (!pool[p]->getNameAndAlignment().alive)
		{
			mvaddstrAlt(y, 1, pool[p]->getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_siege178, gamelog);
			gamelog.newline();
			pressAnyKey();
			delete_and_remove(pool, p);
			y++;
			continue;
		}
		if (pool[p]->align != 1)
		{
			mvaddstrAlt(y, 1, pool[p]->getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_siege179, gamelog);
			gamelog.newline();
			pressAnyKey();
			delete_and_remove(pool, p);
			y++;
			continue;
		}
	}
	gamelog.newline();
	deleteLocationLoot(l);
	deleteLocationVehicles(l);
}
void policeSiegePrintSomePresent(const int l) {

	extern Log gamelog;

	extern MusicClass music;

	const string CONST_siege122 = "You hear jet bombers streak overhead.";
	const string CONST_siege121 = "An M1 Abrams Tank takes up position outside the compound.";
	const string CONST_siege120 = "An M1 Abrams Tank is stopped by the tank traps.";
	const string CONST_siege119 = "National Guard troops are replacing normal SWAT units.";
	const string CONST_siege117 = "The police have surrounded the ";

	music.play(MUSIC_SIEGE);
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege117, gamelog);
	addstrAlt(LocationsPool::getInstance().getLocationName(l), gamelog);
	addstrAlt(CONST_siege188, gamelog);
	gamelog.newline();
	LocationsPool::getInstance().clearunderattack(l);
	pressAnyKey();
	//MENTION ESCALATION STATE
	if (LocationsPool::getInstance().getSiegeEscalationState(l) >= 1)
	{
		mvaddstrAlt(9, 1, CONST_siege119, gamelog);
		gamelog.nextMessage();
		pressAnyKey();
	}
	if (LocationsPool::getInstance().getSiegeEscalationState(l) >= 2)
	{
		if (LocationsPool::getInstance().get_specific_integer(INT_DOWEHAVETANKTRAPS, l))
			mvaddstrAlt(10, 1, CONST_siege120, gamelog);
		else mvaddstrAlt(10, 1, CONST_siege121, gamelog);
		gamelog.nextMessage();
		pressAnyKey();
	}
	if (LocationsPool::getInstance().getSiegeEscalationState(l) >= 3)
	{
		mvaddstrAlt(11, 1, CONST_siege122, gamelog);
		gamelog.nextMessage();
		pressAnyKey();
	}
	// CONST_siege123
	statebrokenlaws(l);
	policeSiege(l);
}
void policeSiegePrint(const int l, const int numpres) {
	LocationsPool::getInstance().setSiegetimeuntillocated(l, -2);
	LocationsPool::getInstance().clearHeat(l);
	if (numpres > 0)
	{
		policeSiegePrintSomePresent(l);
	}
	else
	{
		policeSiegePrintNonePresent(l);
	}
}

void possiblyWarnOfCorpSiege(const int l) {
	extern Log gamelog;

	extern vector<DeprecatedCreature *> pool;

	const string CONST_siege133 = "the LCS";
	const string CONST_siege132 = "are hiring mercenaries to attack ";
	const string CONST_siege131 = " that the Corporations ";
	const string CONST_siege130 = "an anonymous tip";
	const string CONST_siege129 = "your sleeper CEO's warning";
	const string CONST_siege128 = "You have received ";

	LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_CORPORATE, LCSrandom(3) + 1);
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
		mvaddstrAlt(8, 1, CONST_siege128, gamelog);
		if (ceosleepercount)addstrAlt(CONST_siege129, gamelog);
		else addstrAlt(CONST_siege130, gamelog);
		addstrAlt(CONST_siege131, gamelog);
		mvaddstrAlt(9, 1, CONST_siege132, gamelog);
		if (ceosleepercount)addstrAlt(LocationsPool::getInstance().getLocationName(l), gamelog);
		else addstrAlt(CONST_siege133, gamelog);
		addstrAlt(singleDot, gamelog);
		gamelog.nextMessage();
		pressAnyKey();
	}
}

void corporateSiegePrint(const int l) {
	extern Log gamelog;
	extern short offended_corps;
	const string CONST_siege134 = "Corporate mercenaries are raiding the ";

	extern MusicClass music;

	music.play(MUSIC_SIEGE);
	LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_CORPORATE, -1);
	// Corps raid!
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege134, gamelog);
	addstrAlt(LocationsPool::getInstance().getLocationName(l), gamelog);
	addstrAlt(CONST_siege188, gamelog);
	gamelog.nextMessage();
	pressAnyKey();
	corporateSiege(l);
	offended_corps = 0;
}

const string CONST_siege144 = "CCS members pour out of the truck and shoot in the front doors!";
const string CONST_siege143 = "INJURED: ";
const string CONST_siege142 = "KILLED: ";
const string CONST_siege141 = "CCS CAR BOMBING CASUALTY REPORT";
const string CONST_siege140 = "The truck plows into the building and explodes!";
const string CONST_siege138 = "A screeching truck pulls up to ";
const string CONST_siege137 = " is gearing up to attack ";
const string CONST_siege136 = "You have received a sleeper warning that the CCS ";
void CCSSiegePrint(const int l, const int numpres) {
	extern Log gamelog;
	extern vector<DeprecatedCreature *> pool;
	extern MusicClass music;


	if (LocationsPool::getInstance().get_specific_integer(INT_GETHEAT,l) && LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_CCS, l) == -1 && !LocationsPool::getInstance().isThereASiegeHere(l) && !LCSrandom(60) && numpres > 0)
	{
		LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_CCS, LCSrandom(3) + 1);
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
			mvaddstrAlt(8, 1, CONST_siege136, gamelog);
			mvaddstrAlt(9, 1, CONST_siege137, gamelog);
			addstrAlt(LocationsPool::getInstance().getLocationName(l), gamelog);
			addstrAlt(singleDot, gamelog);
			gamelog.nextMessage();
			pressAnyKey();
		}
	}
	else if (LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_CCS, l) > 0)LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_CCS, LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_CCS, l) - 1); // CCS raid countdown!
	else if (LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_CCS, l) == 0 && !LocationsPool::getInstance().isThereASiegeHere(l) && numpres > 0)
	{
		music.play(MUSIC_SIEGE);
		LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_CCS, -1);
		// CCS raid!
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8, 1, CONST_siege138, gamelog);
		addstrAlt(LocationsPool::getInstance().getLocationName(l), gamelog);
		addstrAlt(CONST_siege188, gamelog);
		gamelog.newline();
		pressAnyKey();
		if (!(LocationsPool::getInstance().get_specific_integer(INT_DOWEHAVETANKTRAPS,l)) &&
			!LCSrandom(5))
		{
			// CCS Carbombs safehouse!!
			eraseAlt();
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 1, CONST_siege140, gamelog);
			gamelog.nextMessage();
			pressAnyKey();
			eraseAlt();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(0, 1, CONST_siege141);
			mvaddstrAlt(2, 1, CONST_siege142);
			int killed_y = 2;
			int killed_x = 9;
			mvaddstrAlt(6, 1, CONST_siege143);
			int injured_y = 6;
			int injured_x = 10;
			for (int i = 0; i < CreaturePool::getInstance().lenpool(); i++)
			{
				if (pool[i]->location == l)
				{
					if (LCSrandom(2))
					{
						int namelength = len(pool[i]->getNameAndAlignment().name);
						pool[i]->blood -= LCSrandom(101 - pool[i]->juice / 10) + 10;
						if (pool[i]->blood < 0)
						{
							if (killed_x + namelength > 78)
							{
								killed_y++;
								killed_x = 1;
								//Add limit for killed_y.
							}
							pool[i]->die();
							set_alignment_color(pool[i]->align, false);
							mvaddstrAlt(injured_y, injured_x, pool[i]->getNameAndAlignment().name);
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
							set_alignment_color(pool[i]->align, false);
							mvaddstrAlt(injured_y, injured_x, pool[i]->getNameAndAlignment().name);
							addstrAlt(commaSpace);
							injured_x += namelength + 2;
						}
						//set_alignment_color(pool[i]->align,false);
						//addstrAlt(pool[i]->name);
					}
				}
			}
			pressAnyKey();
		}
		else
		{
			// CCS Raids safehouse
			eraseAlt();
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 1, CONST_siege144, gamelog);
			gamelog.nextMessage();
			pressAnyKey();
			CCSSiege(l);
		}
	}
	else if (LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_CCS, l) == 0)LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_CCS, -1); // Silently call off foiled ccs raids
}
void printFiremenRaid(const string loc) {
	extern Log gamelog;

	const string CONST_siege169 = "Come quietly and you will not be harmed.";
	const string CONST_siege168 = "Unacceptable Speech has occurred at this location.";
	const string CONST_siege166 = "You hear a screeching voice over the sound of fire engine sirens:";
	const string CONST_siege165 = "Armored firemen swarm out, pilot lights burning.";
	const string CONST_siege163 = "Screaming fire engines pull up to the ";

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege163, gamelog);
	addstrAlt(loc, gamelog);
	addstrAlt(CONST_siege188, gamelog);
	gamelog.newline();
	mvaddstrAlt(9, 1, CONST_siege165, gamelog);
	gamelog.newline();
	pressAnyKey();
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(1, 1, CONST_siege166, gamelog);
	gamelog.newline();
	mvaddstrAlt(3, 1, CONST_siege167, gamelog);
	gamelog.newline();
	mvaddstrAlt(4, 1, CONST_siege168, gamelog);
	gamelog.newline();
	mvaddstrAlt(6, 1, CONST_siege169, gamelog);
	gamelog.nextMessage();
	pressAnyKey();
}
bool incomingRaidFiremen(const int l) {
	extern short lawList[LAWNUM];
	return lawList[LAW_FREESPEECH] == -2 && LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_FIREMEN, l) == 0;
}
void theFiremenHaveRaidedEmptySafehouse(const int l) {
	extern Log gamelog;
	extern vector<DeprecatedCreature *> pool;
	extern short offended_firemen;

	const string CONST_siege175 = "Materials relating to the business front have been destroyed.";
	const string CONST_siege170 = "The Firemen have raided the ";

	LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_FIREMEN, -1);
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege170, gamelog);
	addstrAlt(LocationsPool::getInstance().getLocationName(l), gamelog);
	addstrAlt(CONST_siege177, gamelog);
	gamelog.newline();
	pressAnyKey();
	int y = 9;
	for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
	{
		if (pool[p]->location != l)continue;
		if (!pool[p]->getNameAndAlignment().alive)
		{
			mvaddstrAlt(y++, 1, pool[p]->getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_siege178, gamelog);
			gamelog.newline();
			pressAnyKey();
			delete_and_remove(pool, p);
			continue;
		}
		if (pool[p]->align != 1)
		{
			mvaddstrAlt(y++, 1, pool[p]->getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_siege179, gamelog);
			gamelog.newline();
			pressAnyKey();
			delete_and_remove(pool, p);
			continue;
		}
	}
	deleteLocationLoot(l);
	if (hasPrintingPress(l))
	{
		mvaddstrAlt(10, 1, CONST_siege174, gamelog);
		gamelog.newline();
		deletePrintingPress(l);
		offended_firemen = 0;
	}
	if (hasBusinessFront(l))
	{
		mvaddstrAlt(12, 1, CONST_siege175, gamelog);
		gamelog.newline();
		deleteBusinessFront(l);
	}
	gamelog.newline();
}
void possiblyWarnOfCIARaid(const int l) {
	extern Log gamelog;
	const string CONST_siege146 = "to launch an attack on ";
	const string CONST_siege145 = "A sleeper agent has reported that the CIA is planning ";
	extern vector<DeprecatedCreature *> pool;
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
		mvaddstrAlt(8, 1, CONST_siege145, gamelog);
		mvaddstrAlt(9, 1, CONST_siege146, gamelog);
		addstrAlt(LocationsPool::getInstance().getLocationName(l), gamelog);
		addstrAlt(singleDot, gamelog);
		gamelog.nextMessage();
		pressAnyKey();
	}
}
void printCIASiege(const int l) {
	extern Log gamelog;
	const string CONST_siege153 = "They've shut off the lights!";
	const string CONST_siege152 = "to shut off the lights!";
	const string CONST_siege151 = "Through some form of high technology, they've managed ";
	const string CONST_siege150 = "to shut off the lights and the cameras!";

	const string CONST_siege147 = "Unmarked black vans are surrounding the ";

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege147, gamelog);
	addstrAlt(LocationsPool::getInstance().getLocationName(l), gamelog);
	addstrAlt(CONST_siege188, gamelog);
	gamelog.newline();
	if (hasCameras(l))
	{
		mvaddstrAlt(9, 1, CONST_siege151, gamelog);
		mvaddstrAlt(10, 1, CONST_siege150, gamelog);
		gamelog.nextMessage();
	}
	else if (hasAGenerator(l))
	{
		mvaddstrAlt(9, 1, CONST_siege151, gamelog);
		mvaddstrAlt(10, 1, CONST_siege152, gamelog);
		gamelog.nextMessage();
	}
	else
	{
		mvaddstrAlt(9, 1, CONST_siege153, gamelog);
		gamelog.nextMessage();
	}
	pressAnyKey();
}
void printRadioHicksSiege(const int l) {
	extern Log gamelog;
	const string CONST_siege158 = "are storming the ";
	const string CONST_siege154 = "Masses dissatisfied with your lack of respect for AM Radio ";
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege154, gamelog);
	mvaddstrAlt(9, 1, CONST_siege158, gamelog);
	addstrAlt(LocationsPool::getInstance().getLocationName(l), gamelog);
	addstrAlt(CONST_siege188, gamelog);
	gamelog.nextMessage();
	pressAnyKey();
}
void printCableHicksSiege(const int l) {
	extern Log gamelog;
	const string CONST_siege158 = "are storming the ";
	const string CONST_siege157 = "Masses dissatisfied with your lack of respect for Cable News ";

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege157, gamelog);
	mvaddstrAlt(9, 1, CONST_siege158, gamelog);
	addstrAlt(LocationsPool::getInstance().getLocationName(l), gamelog);
	addstrAlt(CONST_siege188, gamelog);
	gamelog.nextMessage();
	pressAnyKey();
}
void possiblyWarnOfFiremenSiege(const int l) {
	const string CONST_siege162 = "the Firemen are planning to burn ";
	const string CONST_siege161 = "Word in the underground is that ";
	const string CONST_siege160 = "A sleeper Fireman has informed you that ";

	extern Log gamelog;
	extern vector<DeprecatedCreature *> pool;

	int firemensleepercount = 0;
	for (int pl = 0; pl < CreaturePool::getInstance().lenpool(); pl++)
		if (pool[pl]->flag & CREATUREFLAG_SLEEPER &&
			pool[pl]->type == CREATURE_FIREFIGHTER &&
			LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONCITY,pool[pl]->location) == LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONCITY,l))
			firemensleepercount++;
	if (LCSrandom(firemensleepercount + 1) > 0 || !LCSrandom(10))
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		if (firemensleepercount) mvaddstrAlt(8, 1, CONST_siege160, gamelog);
		else mvaddstrAlt(8, 1, CONST_siege161, gamelog);
		mvaddstrAlt(9, 1, CONST_siege162, gamelog);
		addstrAlt(LocationsPool::getInstance().getLocationName(l), gamelog);
		addstrAlt(singleDot, gamelog);
		gamelog.nextMessage();
		pressAnyKey();
	}
}
void huntingSiegePrint(const int l, int& numpres) {

	extern Log gamelog;
	extern char disbanding;
	extern short offended_corps;
	extern short offended_cia;
	extern char endgamestate;
	extern short offended_amradio;
	extern short offended_cablenews;
	extern short offended_firemen;
	extern MusicClass music;
	extern short lawList[LAWNUM];
	extern short attitude[VIEWNUM];
	extern vector<DeprecatedCreature *> pool;


	//HUNTING
	if (getTimeUntilSiege(l) > 0)
	{
		if (LocationsPool::getInstance().isThisAFront(l) == -1 || LCSrandom(2))
		{
			LocationsPool::getInstance().setTimeUntilSiege(l, getTimeUntilSiege(l) - 1);
			// Hunt faster if location is extremely hot
			huntFasterIfSiteIncrediblyHot(l);
		}
	}
	//CHECK FOR CRIMINALS AT THIS BASE
	//int heatprotection=0;
	int crimes = allCreatureHeatGeneration(l, numpres);
	// Determine how effective your current safehouse
	// is at keeping the police confused
	updateLocationHeatProtection(l);
	// Let the place cool off if not accumulating heat
	letPlaceCoolOffUnlessCrime(crimes, l);
	// Sleepers at the police department may give a warning just before police raids
	if (getTimeUntilSiege(l) == 1)
	{
		possibleWarningFromSleepers(l);
	}
	//COPS RAID THIS LOCATION
	if (!getTimeUntilSiege(l))
	{
		policeSiegePrint(l, numpres);
	}
	//OTHER OFFENDABLE ENTITIES
	//CORPS
	if (LocationsPool::getInstance().get_specific_integer(INT_GETHEAT,l) && LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_CORPORATE, l) == -1 && !LocationsPool::getInstance().isThereASiegeHere(l) && offended_corps && !LCSrandom(600) && numpres > 0)
	{
		possiblyWarnOfCorpSiege(l);
	}
	else if (LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_CORPORATE, l) > 0) {
		LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_CORPORATE, LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_CORPORATE, l) - 1); // Corp raid countdown!
	}
	else if (LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_CORPORATE, l) == 0 && !LocationsPool::getInstance().isThereASiegeHere(l) && offended_corps&&numpres > 0)
	{
		corporateSiegePrint(l);
	}
	else if (LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_CORPORATE, l) == 0) {
		LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_CORPORATE, -1); // Silently call off foiled corp raids
	}
	//CONSERVATIVE CRIME SQUAD
	bool ccs_active = endgamestate >= ENDGAME_CCS_APPEARANCE && endgamestate < ENDGAME_CCS_DEFEATED;
	bool target_interesting = endgamestate >= ENDGAME_CCS_SIEGES || hasPrintingPress(l);
	if (ccs_active && target_interesting)
	{
		CCSSiegePrint(l, numpres);
	}
	//CIA
	if (LocationsPool::getInstance().get_specific_integer(INT_GETHEAT,l) && LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_CIA, l) == -1 && !LocationsPool::getInstance().isThereASiegeHere(l) && offended_cia && !LCSrandom(300) && numpres > 0)
	{
		LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_CIA, LCSrandom(3) + 1);
		// *JDS* agent sleepers may give a warning before cia raids
		possiblyWarnOfCIARaid(l);
	}
	else if (LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_CIA, l) > 0)LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_CIA, LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_CIA, l) - 1); // CIA raid countdown!
	else if (LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_CIA, l) == 0 && !LocationsPool::getInstance().isThereASiegeHere(l) && offended_cia&&numpres > 0)
	{
		music.play(MUSIC_SIEGE);
		LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_CIA, -1);
		// CIA raids!
		printCIASiege(l);
		CIASiege(l);
	}
	else if (LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_CIA, l) == 0) {
		LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_CIA, -1); // Silently call off foiled cia raids
	}
	//HICKS
	if (!LocationsPool::getInstance().isThereASiegeHere(l) && offended_amradio&&attitude[VIEW_AMRADIO] <= 35 && !LCSrandom(600) && numpres > 0)
	{
		music.play(MUSIC_SIEGE);
		printRadioHicksSiege(l);
		hicksSiege(l);
		offended_amradio = 0;
	}
	if (!LocationsPool::getInstance().isThereASiegeHere(l) && offended_cablenews&&attitude[VIEW_CABLENEWS] <= 35 && !LCSrandom(600) && numpres > 0)
	{
		music.play(MUSIC_SIEGE);
		printCableHicksSiege(l);
		hicksSiege(l);
		offended_cablenews = 0;
	}
	//Firemen
	if (lawList[LAW_FREESPEECH] == -2 && LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_FIREMEN, l) == -1 && !LocationsPool::getInstance().isThereASiegeHere(l) &&
		offended_firemen && numpres > 0 && hasPrintingPress(l) && !LCSrandom(90))
	{
		LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_FIREMEN, LCSrandom(3) + 1);
		// Sleeper Firemen can warn you of an impending raid
		possiblyWarnOfFiremenSiege(l);
	}
	else if (LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_FIREMEN, l) > 0) LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_FIREMEN, LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_FIREMEN, l) - 1);
	else if (incomingRaidFiremen(l) && !LocationsPool::getInstance().isThereASiegeHere(l) && numpres > 0)
	{
		music.play(MUSIC_SIEGE);
		LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_FIREMEN, -1);
		// Firemen raid!
		printFiremenRaid(LocationsPool::getInstance().getLocationName(l));
		firemanSiege(l);
		offended_firemen = 0;
	}
	else if (incomingRaidFiremen(l))
	{
		theFiremenHaveRaidedEmptySafehouse(l);
	}
	else if (lawList[LAW_FREESPEECH] <= -1 && LocationsPool::getInstance().get_specific_integer(INT_GETTIMEUNTILSIEGE_FIREMEN, l) == 0) {
		LocationsPool::getInstance().setTimeUntilSiege(l, SIEGE_FIREMEN, -1);
		offended_firemen = 0;
	}

}

//TODO There is an absurd amount of duplicated code here
void siegecheck(char canseethings)
{
	extern Log gamelog;
	extern char disbanding;
	extern short offended_firemen;
	extern short lawList[LAWNUM];
	extern vector<DeprecatedCreature *> pool;

	if (disbanding)return;
	// Upkeep - even base-less should be considered.
	// XXX - candidate to create nice function?
	// Cleanse record on things that aren't illegal right now
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		pool[p]->clear_no_longer_crimes();
	}
	if (lawList[LAW_FREESPEECH] > -2)offended_firemen = 0;
	//FIRST, THE COPS
	int numpres;
	for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
	{
		if (LocationsPool::getInstance().get_specific_integer(INT_ISTHISSITECLOSED,find_site_index_in_same_city(SITE_GOVERNMENT_POLICESTATION, l)))
		{
			dropHeatByFivePercent(l);
		}
		if (LocationsPool::getInstance().isThereASiegeHere(l))continue;
		if (LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE,l) == RENTING_NOCONTROL)continue;
		numpres = 0;
		if (getTimeUntilSiege(l) == -2)
		{
			//IF JUST SIEGED, BUY SOME TIME
			LocationsPool::getInstance().setTimeUntilSiege(l, -1);
		}
		else
		{
			huntingSiegePrint(l, numpres);
		}
	}
}
/* siege - checks how many people are eating at the site */
int numbereating(int loc)
{
	extern vector<DeprecatedCreature *> pool;
	int eaters = 0;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++) //Must be here, alive, Liberal, and not a sleeper, to count as an eater
		if (pool[p]->location == loc && pool[p]->getNameAndAlignment().alive&&pool[p]->align == 1 && !(pool[p]->flag&CREATUREFLAG_SLEEPER)) eaters++;
	return eaters;
}
void noOneIsThere(const int l) {
	extern Log gamelog;
	extern vector<DeprecatedCreature *> pool;
	const string CONST_siege176 = "Conservatives have raided the ";
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege176, gamelog);
	addstrAlt(LocationsPool::getInstance().getLocationName(l), gamelog);
	addstrAlt(CONST_siege177, gamelog);
	gamelog.newline();
	if (LocationsPool::getInstance().getSiegeType(l) == SIEGE_CCS && LocationsPool::getInstance().getLocationType(l) == SITE_INDUSTRY_WAREHOUSE)
		CCSCapturesSite(l);
	pressAnyKey();
	int y = 9;
	for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
	{
		if (pool[p]->location != l) continue;
		if (!pool[p]->getNameAndAlignment().alive)
		{
			mvaddstrAlt(y++, 1, pool[p]->getNameAndAlignment().name);
			addstrAlt(CONST_siege178, gamelog);
			gamelog.newline();
			pressAnyKey();
			delete_and_remove(pool, p);
			continue;
		}
		if (pool[p]->align != 1)
		{
			mvaddstrAlt(y++, 1, pool[p]->getNameAndAlignment().name);
			addstrAlt(CONST_siege179, gamelog);
			gamelog.newline();
			pressAnyKey();
			delete_and_remove(pool, p);
			continue;
		}
	}
	deleteLocationLoot(l);
	deleteLocationVehicles(l);
	gamelog.newline();
	endLocationSiege(l);
}
const string CONST_siege202 = "Fortunately, no one is hurt.";
const string CONST_siege201 = " narrowly avoided death!";
const string CONST_siege200 = " was killed in the bombing!";
const string CONST_siege199 = "The lights fade and all is dark.";
const string CONST_siege198 = "The generator has been destroyed!";
const string CONST_siege197 = "There's nothing left but smoking wreckage...";
const string CONST_siege196 = "The anti-aircraft gun takes a direct hit!";
const string CONST_siege195 = "Explosions rock the compound!";
const string CONST_siege194 = "A skilled pilot gets through!";
const string CONST_siege193 = "It's all over the TV. Everyone in the Liberal Crime Squad gains 20 juice!";
const string CONST_siege192 = "Hit! One of the bombers slams into to the ground.";
const string CONST_siege191 = "You didn't shoot any down, but you've made them think twice!";
const string CONST_siege190 = "The thunder of the anti-aircraft gun shakes the compound!";
const string CONST_siege189 = "You hear planes streak overhead!";
void airStrike(const char clearformess, const int l, int &num_liberals) {

	extern Log gamelog;
	extern int stat_dead;
	extern short lawList[LAWNUM];
	extern vector<DeprecatedCreature *> pool;
	void deleteGeneratorLightsOff(int l);


	bool hit = true;
	if (clearformess) eraseAlt();
	else makedelimiter();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege189, gamelog);
	gamelog.newline();
	pressAnyKey();
	bool hasAAGun = siteHasAAGun(l);
	bool hasGenerator = hasAGenerator(l);
	if (hasAAGun)
	{
		if (clearformess) eraseAlt();
		else makedelimiter();
		mvaddstrAlt(8, 1, CONST_siege190, gamelog);
		gamelog.newline();
		pressAnyKey();
		if (clearformess) eraseAlt();
		else makedelimiter();
		if (LCSrandom(5))
		{
			hit = false;
			if (LCSrandom(2)) mvaddstrAlt(8, 1, CONST_siege191, gamelog);
			else
			{
				mvaddstrAlt(8, 1, CONST_siege192, gamelog);
				gamelog.newline();
				pressAnyKey();
				if (clearformess) eraseAlt();
				else makedelimiter();
				mvaddstrAlt(8, 1, CONST_siege193, gamelog);
				for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++) addjuice(*pool[p], 20, 1000);
			}
			gamelog.newline();
			pressAnyKey();
		}
		else
		{
			mvaddstrAlt(8, 1, CONST_siege194, gamelog);
			gamelog.newline();
			pressAnyKey();
		}
	}
	if (hit)
	{
		if (clearformess) eraseAlt();
		else makedelimiter();
		mvaddstrAlt(8, 1, CONST_siege195, gamelog);
		gamelog.newline();
		pressAnyKey();
		if (hasAAGun && !LCSrandom(3))
		{
			if (clearformess) eraseAlt();
			else makedelimiter();
			mvaddstrAlt(8, 1, CONST_siege196, gamelog);
			gamelog.newline();
			pressAnyKey();
			if (clearformess) eraseAlt();
			else makedelimiter();
			mvaddstrAlt(8, 1, CONST_siege197, gamelog);
			gamelog.newline();
			pressAnyKey();
			deleteAAGun(l);
		}
		else if (hasGenerator && !LCSrandom(3))
		{
			if (clearformess) eraseAlt();
			else makedelimiter();
			mvaddstrAlt(8, 1, CONST_siege198, gamelog);
			gamelog.newline();
			pressAnyKey();
			if (clearformess) eraseAlt();
			else makedelimiter();
			mvaddstrAlt(8, 1, CONST_siege199, gamelog);
			gamelog.newline();
			pressAnyKey();
			deleteGeneratorLightsOff(l);
		}
		if (!LCSrandom(2))
		{
			vector<int> pol;
			for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++) if (pool[p]->getNameAndAlignment().alive&&pool[p]->location == l) pol.push_back(p);
			if (len(pol))
			{
				if (clearformess) eraseAlt();
				else makedelimiter();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				int targ = pickrandom(pol);
				if ((int)LCSrandom(100) > pool[targ]->juice)
				{
					mvaddstrAlt(8, 1, pool[targ]->getNameAndAlignment().name, gamelog);
					addstrAlt(CONST_siege200, gamelog);
					gamelog.newline();
					if (pool[targ]->align == 1) stat_dead++, num_liberals--;
					removesquadinfo(*pool[targ]);
					pool[targ]->die();
				}
				else
				{
					mvaddstrAlt(8, 1, pool[targ]->getNameAndAlignment().name, gamelog);
					addstrAlt(CONST_siege201, gamelog);
					gamelog.newline();
				}
				pressAnyKey();
			}
		}
		else
		{
			if (clearformess) eraseAlt();
			else makedelimiter();
			mvaddstrAlt(8, 1, CONST_siege202, gamelog);
			gamelog.newline();
			pressAnyKey();
		}
	}
}
void shotAtBySniper(const char clearformess, const int l, int &num_liberals) {
	const string CONST_siege187 = "A sniper nearly hits ";
	const string CONST_siege185 = "A sniper takes out ";

	extern Log gamelog;
	extern int stat_dead;
	extern vector<DeprecatedCreature *> pool;

	vector<int> pol;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++) if (pool[p]->getNameAndAlignment().alive&&pool[p]->location == l) pol.push_back(p);
	if (len(pol))
	{
		if (clearformess) eraseAlt();
		else makedelimiter();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		int targ = pickrandom(pol);
		if ((int)LCSrandom(50) > pool[targ]->juice)
		{
			mvaddstrAlt(8, 1, CONST_siege185, gamelog);
			addstrAlt(pool[targ]->getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_siege188, gamelog);
			gamelog.newline();
			if (pool[targ]->align == 1) stat_dead++, num_liberals--;
			removesquadinfo(*pool[targ]);
			pool[targ]->die();
		}
		else
		{
			mvaddstrAlt(8, 1, CONST_siege187, gamelog);
			addstrAlt(pool[targ]->getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_siege188, gamelog);
			gamelog.newline();
		}
		pressAnyKey();
	}
}
const string CONST_siege224 = "'s words.";
const string CONST_siege223 = "Virtually everyone in America was moved by ";
const string CONST_siege222 = " later went on to win a Pulitzer for it.";
const string CONST_siege221 = "Even the Cable News and AM Radio spend days talking about it.";
const string CONST_siege220 = "The discussion was exciting and dynamic.";
const string CONST_siege219 = " represents the LCS well.";
const string CONST_siege218 = "'s verbal finesse leaves something to be desired.";
const string CONST_siege217 = " stutters nervously the whole time.";
const string CONST_siege216 = "But ";
const string CONST_siege215 = " falls asleep.";
const string CONST_siege214 = "But the interview is so boring that ";
const string CONST_siege213 = "Retarded";
const string CONST_siege212 = "Dumb";
const string CONST_siege211 = "and later used the material for a Broadway play called";
const string CONST_siege210 = " canceled the interview halfway through";
void printReporterDuringSiege(const string repname, const string name, const int segmentpower) {

	extern Log gamelog;
	extern short lawList[LAWNUM];

	string line_one;
	string line_two = blankString;
	if (segmentpower < 15)
	{
		line_one = repname + CONST_siege210;
		line_two = CONST_siege211;
		if (LCSrandom(insult_for_liberal.size() + 1)) {
			mvaddstrAlt(10, 1, pickrandom(insult_for_liberal));
		}
		else {
			if (lawList[LAW_FREESPEECH] == -2) mvaddstrAlt(10, 1, CONST_siege212, gamelog);
			else mvaddstrAlt(10, 1, CONST_siege213, gamelog);
		}
		addstrAlt(singleSpace, gamelog);
		addstrAlt(pickrandom(word_replacing_liberal));
		addstrAlt(singleDot, gamelog);
	}
	else if (segmentpower < 20)
	{
		line_one = CONST_siege214 + name + CONST_siege215;
	}
	else if (segmentpower < 25)
	{
		line_one = CONST_siege216 + name + CONST_siege217;
	}
	else if (segmentpower < 30)
	{
		line_one = name + CONST_siege218;

	}
	else if (segmentpower < 45)
	{
		line_one = name + CONST_siege219;
	}
	else if (segmentpower < 60)
	{
		line_one = CONST_siege220;
		line_two = CONST_siege221;
	}
	else
	{
		line_one = repname + CONST_siege222;
		line_two = CONST_siege223 + name + CONST_siege224;
	}
	mvaddstrAlt(8, 1, line_one, gamelog);
	if (len(line_two) > 0) {
		mvaddstrAlt(9, 1, line_two, gamelog);
	}
	gamelog.newline();
}
int printBestLCSMemberForNews(const string repname, const int l);
void generateReporterDuringSiege(const int l) {

	extern Log gamelog;
	extern short lawList[LAWNUM];

	const string CONST_siege207 = "got into the compound somehow!";
	const string CONST_siege206 = " from the ";
	const string CONST_siege205 = "Elitist ";

	string repname = generate_name();
	set_color_easy(WHITE_ON_BLACK);
	eraseAlt();
	mvaddstrAlt(1, 1, CONST_siege205, gamelog);
	addstrAlt(repname, gamelog);
	addstrAlt(CONST_siege206, gamelog);
	addstrAlt(pickrandom(words_meaning_news), gamelog);
	addstrAlt(singleSpace);
	addstrAlt(pickrandom(newspaper_first_name), gamelog);
	addstrAlt(singleSpace, gamelog);
	addstrAlt(pickrandom(newspaper_last_name), gamelog);
	mvaddstrAlt(2, 1, CONST_siege207, gamelog);
	gamelog.newline();
	pressAnyKey();
	int segmentpower = printBestLCSMemberForNews(repname, l);
	pressAnyKey();
	//CHECK PUBLIC OPINION
	change_public_opinion(VIEW_LIBERALCRIMESQUAD, 20);
	change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, (segmentpower - 25) / 2, segmentpower + 50);
	for (int v = 0; v < 5; v++) change_public_opinion(LCSrandom(VIEWNUM - 3), (segmentpower - 25) / 2);
}
int siegeDontAttack(const int l, const bool clearformess, int num_liberals) {

	bool getLightsOff(int l);
	void setLightsOff(int l);
	bool hasBasicCompoundWalls(int l);

	const string CONST_siege204 = "The tank moves forward to your compound entrance.";
	const string CONST_siege203 = "Army engineers have removed your tank traps.";
	const string CONST_siege184 = "The police have cut the lights!";
	extern Log gamelog;
	extern int stat_dead;
	extern short lawList[LAWNUM];

	char no_bad = 1;
	//CUT LIGHTS
	if (!getLightsOff(l) &&
		!(hasAGenerator(l)) && !LCSrandom(10))
	{
		no_bad = 0;
		if (clearformess) eraseAlt();
		else makedelimiter();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8, 1, CONST_siege184, gamelog);
		gamelog.newline();
		pressAnyKey();
		setLightsOff(l);
	}
	//SNIPER
	if (!(hasBasicCompoundWalls(l)) && !LCSrandom(5))
	{
		no_bad = 0;
		shotAtBySniper(clearformess, l, num_liberals);
	}
	if (LocationsPool::getInstance().getSiegeEscalationState(l) >= 3 && !LCSrandom(3))
	{
		no_bad = 0;
		//AIR STRIKE!
		airStrike(clearformess, l, num_liberals);
	}
	if ((LocationsPool::getInstance().get_specific_integer(INT_DOWEHAVETANKTRAPS,l)) &&
		LocationsPool::getInstance().getSiegeEscalationState(l) >= 3 && !LCSrandom(15))
	{
		no_bad = 0;
		//ENGINEERS
		if (clearformess) eraseAlt();
		else makedelimiter();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8, 1, CONST_siege203, gamelog);
		gamelog.newline();
		pressAnyKey();
		if (!clearformess)
		{
			makedelimiter();
		}
		mvaddstrAlt(clearformess ? 9 : 8, 1, CONST_siege204, gamelog);
		gamelog.newline();
		pressAnyKey();
		LocationsPool::getInstance().deleteTankTraps(l);
	}
	//NEED GOOD THINGS TO BALANCE THE BAD
	// ELITE REPORTER SNEAKS IN
	if (!LCSrandom(20) && no_bad&&num_liberals > 0)
	{
		generateReporterDuringSiege(l);
	}
	return num_liberals;
}
/* siege - updates sieges in progress */
void reduceCompoundStores(int loc, int amount);
void emptyCompoundStores(int l);
const string CONST_siege183 = "The cops are coming!";
const string CONST_siege182 = " has starved to death.";
const string CONST_siege181 = "Your Liberals are starving!";
const string CONST_siege180 = "A day passes while under siege...";
const string CONST_siege247 = "give up";
void siegeturn(char clearformess)
{
	void setUnderAttack(int l);

	extern Log gamelog;
	extern char disbanding;
	extern int stat_dead;
	extern short lawList[LAWNUM];
	extern vector<DeprecatedCreature *> pool;
	if (disbanding)return;
	// Count people at each location
	//int hs=-1;
	int* liberalcount = new int[LocationsPool::getInstance().lenpool()];
	char* food_prep = new char[LocationsPool::getInstance().lenpool()];
	// Clear food_prep and liberalcount lists
	std::memset(food_prep, 0, LocationsPool::getInstance().lenpool());
	std::memset(liberalcount, 0, sizeof(int)*LocationsPool::getInstance().lenpool());
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (!pool[p]->getNameAndAlignment().alive)continue; // Dead people don't count
		if (pool[p]->align != 1)continue; // Non-liberals don't count
		if (pool[p]->location == -1)continue; // Vacationers don't count
		liberalcount[pool[p]->location]++;
	}
	for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
		if (LocationsPool::getInstance().isThereASiegeHere(l))
		{
			//resolve sieges with no people
			if (liberalcount[l] == 0)
			{
				noOneIsThere(l);
			}
			if (!LocationsPool::getInstance().isThisUnderAttack(l))
			{
				// Seperate logging message.
				gamelog.record(CONST_siege180);
				gamelog.newline();
				//EAT
				bool starving = false;
				int eaters = numbereating(l);
				if (LocationsPool::getInstance().get_specific_integer(INT_GETSTORESAMOUNT,l) == 0 && eaters > 0)
				{
					starving = true;
					if (clearformess) eraseAlt();
					else makedelimiter();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8, 1, CONST_siege181, gamelog);
					gamelog.newline();
					pressAnyKey();
				}
				if (LocationsPool::getInstance().get_specific_integer(INT_GETSTORESAMOUNT,l) >= eaters) reduceCompoundStores(l, eaters);
				else emptyCompoundStores(l);
				//ATTACK!
				char attack = 0;
				for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
				{
					if (!pool[p]->getNameAndAlignment().alive || pool[p]->location != l) continue;
					if (starving) pool[p]->blood -= LCSrandom(8) + 4;
					// Check if liberal starved to death.
					if (pool[p]->blood <= 0)
					{
						pool[p]->die();
						if (clearformess) eraseAlt();
						else makedelimiter();
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(8, 1, pool[p]->getNameAndAlignment().name, gamelog);
						addstrAlt(CONST_siege182, gamelog);
						gamelog.newline();
						pressAnyKey();
					}
				}
				if (!LCSrandom(12))attack = 1;
				if (attack)
				{
					if (clearformess) eraseAlt();
					else makedelimiter();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8, 1, CONST_siege183, gamelog);
					gamelog.newline();
					pressAnyKey();
					setUnderAttack(l);
				}
				else {
					liberalcount[l] = siegeDontAttack(l, clearformess, liberalcount[l]);
				}
				gamelog.newline(); // single blank line after every siege day
			}
		}
	delete[] liberalcount;
	delete[] food_prep;
}
/* siege - checks how many days of food left at the site */
int fooddaysleft(int loc)
{
	int eaters = numbereating(loc);
	if (eaters == 0) return -1;
	return LocationsPool::getInstance().get_specific_integer(INT_GETSTORESAMOUNT,loc) / eaters + ((LocationsPool::getInstance().get_specific_integer(INT_GETSTORESAMOUNT,loc) % eaters) > eaters / 2);
}
void baseEveryoneLeftAtHomelessShelter(const int homes);
void escalateSite(int l);
void dumpLootAtLocation(int homes, vector<Item *>& loot);
/* siege - what happens when you escaped the siege */
void escapesiege(char won)
{
	const string CONST_siege227 = "Your Liberals split up and lay low for a few days.";
	const string CONST_siege226 = "Press any key to split up and lay low for a few days";
	const string CONST_siege225 = "You have escaped!";
	extern Log gamelog;
	extern Deprecatedsquadst *activesquad;
	extern MusicClass music;
	extern int police_heat;
	//TEXT IF DIDN'T WIN
	if (!won)
	{
		music.play(MUSIC_CONQUER);
		//GIVE INFO SCREEN
		eraseAlt();
		set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		mvaddstrAlt(1, 32, CONST_siege225, gamelog);
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
		mvaddstrAlt(yLevel + 1, 11, CONST_siege226);
		// Seperate logging text
		gamelog.log(CONST_siege227);
		pressAnyKey();
		//dump retrieved loot in homeless shelter - is there anywhere better to put it?
		if (activesquad&&homes != -1) dumpLootAtLocation(homes, activesquad->loot);
		activesquad = NULL; //active squad cannot be disbanded in removesquadinfo,
							//but we need to disband current squad as the people are going to be 'away'.
							//GET RID OF DEAD, etc.
		if (LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE, getCurrentSite()) > 1)LocationsPool::getInstance().setRenting(getCurrentSite(), RENTING_NOCONTROL);
		baseEveryoneLeftAtHomelessShelter(homes);
		deleteLocationLoot(getCurrentSite());
		deleteLocationVehicles(getCurrentSite());
		deleteCompoundWalls(getCurrentSite());
		emptyCompoundStores(getCurrentSite());
		deleteBusinessFront(getCurrentSite());
		LocationsPool::getInstance().initLocation(getCurrentSite());
	}
	//SET UP NEW SIEGE CHARACTERISTICS, INCLUDING TIMING
	endLocationSiege(getCurrentSite());
	if (won&&LocationsPool::getInstance().getSiegeType(getCurrentSite()) == SIEGE_POLICE)
	{
		escalateSite(getCurrentSite());
		if (police_heat < 4) police_heat++;
	}
}
const string CONST_siege255 = "* * * * *   VICTORY   * * * * *";
const string CONST_siege274 = "Press C to Continue Liberally.";
/* siege - flavor text when you fought off the raid */
void conquertext()
{
	const string CONST_siege234 = "this filth until the Liberal Agenda is realized.";
	const string CONST_siege233 = "Unfortunately, you will never truly be safe from ";
	const string CONST_siege232 = "The Conservative automatons have been driven back.  ";
	const string CONST_siege231 = "abandoning this safe house for a safer location.";
	const string CONST_siege230 = "the time being.  While they are regrouping, you might consider ";
	const string CONST_siege229 = "The Conservative automatons have been driven back ÄÄ for ";
	extern Log gamelog;
	extern MusicClass music;
	//GIVE INFO SCREEN
	music.play(MUSIC_CONQUER);
	eraseAlt();
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(1, 26, CONST_siege255, gamelog);
	gamelog.newline();
	if (LocationsPool::getInstance().getSiegeType(getCurrentSite()) == SIEGE_POLICE)
	{
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(3, 16, CONST_siege229, gamelog);
		mvaddstrAlt(4, 11, CONST_siege230, gamelog);
		mvaddstrAlt(5, 11, CONST_siege231, gamelog);
	}
	else
	{
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(3, 16, CONST_siege232, gamelog);
		mvaddstrAlt(4, 11, CONST_siege233, gamelog);
		mvaddstrAlt(5, 11, CONST_siege234, gamelog);
	}
	gamelog.nextMessage();
	mvaddstrAlt(7, 19, CONST_siege274);
	while (getkeyAlt() != 'c');
}
siegest getWholeSiege(int l);
void addTank() {

	makecreature(ENCMAX - 9, CREATURE_TANK);
}

void checkIfRunningFromCops() {
	extern Deprecatednewsstoryst *sitestory;
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();
	if (encounter[0].exists&&encounter[0].type == CREATURE_COP)
	{
		sitestory->crime.push_back(CRIME_FOOTCHASE);
		criminalizeparty(LAWFLAG_RESIST);
	}
}
void cancelOutBleeding();
int print_character_info(const int c, const int party_status);
void countHeroes(int &partysize, int &partyalive);
// Siege -- Mass combat outside safehouse
const string CONST_siege242 = "The siege is broken!";
const string CONST_siege241 = "You're free!";
const string CONST_siege240 = "C - Reflect on your Conservative judgment.";
const string CONST_siege239 = "G - Surrender";
const string CONST_siege238 = "F - Fight!";
const string CONST_siege237 = "E - Equip";
const string CONST_siege236 = "D - Escape";

char sally_forth_aux(int loc)
{
	extern Log gamelog;
	extern short mode;
	extern char foughtthisround;
	extern MusicClass music;
	extern short party_status;
	reloadparty();
	siegest siege = getWholeSiege(loc);
	setCurrentSite(loc);
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
		if (siege.escalationstate >= 2 && !(LocationsPool::getInstance().get_specific_integer(INT_DOWEHAVETANKTRAPS,loc)))
			addTank();
		break;
	}
	mode = GAMEMODE_CHASEFOOT;
	music.play(MUSIC_DEFENSE);
	bool ranaway = false;
	while (true)
	{
		// Count heroes
		int partysize = 0, partyalive = 0;
		countHeroes(partysize, partyalive);
		// Count bad guys
		int encsize = encounterSize();
		// Let's roll
		autopromote(loc);
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(0, 0, LocationsPool::getInstance().getLocationName(loc));
		// Player's party
		if (partyalive == 0) party_status = -1;
		printparty();
		if (partyalive > 0)
		{
			// Options
			if (partysize > 1)set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(9, 40, change_squad_order);
			if (partysize > 0 && (party_status == -1 || partysize > 1))set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(10, 40, check_status_of_squad_liberal);
			if (party_status != -1)set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(11, 40, show_squad_liberal_status);
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(9, 1, CONST_siege236);
			mvaddstrAlt(10, 1, CONST_siege237);
			mvaddstrAlt(11, 1, CONST_siege238);
			mvaddstrAlt(12, 1, CONST_siege239);
		}
		else
		{
			endcheck(END_BUT_NOT_END); // play the right music in case we're dead
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(9, 1, CONST_siege240);
		}
		// Enemies
		printencounter();
		// check if we fought the previous loop; if so, add a blank gamelog line
		if (foughtthisround) gamelog.newline();
		foughtthisround = 0;
		int c = getkeyAlt();
		// Reflecting on your poor judgment
		if (partyalive == 0 && c == 'c' && !endcheck())
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
			party_status = print_character_info(c, party_status);
			// Surrender
			if (c == 'g') giveup();
			// Run away
			if (c == 'd')
			{
				checkIfRunningFromCops();
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
			countHeroes(partysize, partyalive);
			int baddiecount = baddieCount();
			if (partyalive && !baddiecount)
			{
				cancelOutBleeding();
				mode = GAMEMODE_BASE;
				if (ranaway)
				{
					music.play(MUSIC_CONQUER);
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					clearmessagearea();
					mvaddstrAlt(16, 1, CONST_siege241, gamelog);
					gamelog.nextMessage();
					pressAnyKey();
					escapesiege(false);
					return 1;
				}
				else
				{
					music.play(MUSIC_CONQUER);
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					clearmessagearea();
					mvaddstrAlt(16, 1, CONST_siege242, gamelog);
					gamelog.nextMessage();
					pressAnyKey();
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

void createNewStoryEscape(const int loc) {
	const string CONST_siege248 = "You have been defeated.";
	extern Log gamelog;
	extern Deprecatednewsstoryst *sitestory;
	extern vector<Deprecatednewsstoryst *> newsstory;
	Deprecatednewsstoryst *ns = new Deprecatednewsstoryst;
	ns->type = NEWSSTORY_SQUAD_ESCAPED;
	ns->positive = 1;
	ns->loc = loc;
	ns->siegetype = LocationsPool::getInstance().getSiegeType(loc);
	newsstory.push_back(ns);
	sitestory = ns;

	char result = sally_forth_aux(loc);

	if (result == 2) ns->type = NEWSSTORY_SQUAD_BROKESIEGE;


	// If you fail, make sure the safehouse isn't under siege anymore by
	// forcing you to CONST_siege247.
	if (result == 0)
	{
		gamelog.log(CONST_siege248);
		resolvesafehouses();
	}
}
int print_character_info(const int c, const int party_status);
int getEscapeEngageLocation();
void deleteAllSquadsInActiveAreaExceptActive(const int loc);
void formANewSquadIfThereAreNone();
const string CONST_siege252 = "Press any key to Confront the Conservative Aggressors";
/* siege - prepares for exiting the siege to fight the attackers head on */
void sally_forth()
{
	const string CONST_siege245 = "Your Liberals sally forth to confront the siege.";
	const string CONST_siege243 = "UNDER SIEGE: ESCAPE OR ENGAGE";
	extern Log gamelog;
	extern int selectedsiege;
	extern MusicClass music;
	extern long cursquadid;
	//GIVE INFO SCREEN
	music.play(MUSIC_DEFENSE);
	eraseAlt();
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(1, 26, CONST_siege243);
	set_color_easy(WHITE_ON_BLACK);
	int yLevel = 3;
	for (int i = 0; i < len(nextSiege); i++) {
		mvaddstrAlt(yLevel + i, 11, nextSiege[i]);
	}
	yLevel++;
	yLevel += len(nextSiege);
	for (int i = 0; i < len(nextSiegeAgain); i++) {
		mvaddstrAlt(yLevel + i, 11, nextSiegeAgain[i]);
	}
	int loc = getEscapeEngageLocation();
	if (loc == -1)return;
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(23, 11, CONST_siege252);
	// Seperate logging text
	gamelog.log(CONST_siege245);
	pressAnyKey();
	if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_CCS && LocationsPool::getInstance().getLocationType(loc) == SITE_INDUSTRY_WAREHOUSE)
		CCSCapturesSite(loc); // CCS Captures warehouse -- this will be reversed if you fight them off
							  //CRIMINALIZE
	if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_POLICE) criminalizepool(LAWFLAG_RESIST, -1, loc);
	//DELETE ALL SQUADS IN THIS AREA UNLESS THEY ARE THE activesquad
	deleteAllSquadsInActiveAreaExceptActive(loc);
	// No squads at the location? Form a new one.
	formANewSquadIfThereAreNone();
	//MAKE SURE PARTY IS ORGANIZED
	autopromote(loc);
	//START FIGHTING
	createNewStoryEscape(loc);
}
/* siege - prepares for entering site mode to fight the siege */
void escape_engage()
{
	const string CONST_siege253 = "Your Liberals confront the Conservatives within the safehouse.";
	const string CONST_siege251 = "Your traps will harass the enemy, but not the Squad.";
	const string CONST_siege250 = "Your security cameras let you see units on the (M)ap.";
	const string CONST_siege249 = "UNDER ATTACK: ESCAPE OR ENGAGE";
	extern Log gamelog;
	extern int selectedsiege;
	extern MusicClass music;
	extern long cursquadid;
	music.play(MUSIC_DEFENSE);
	//GIVE INFO SCREEN
	eraseAlt();
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(1, 26, CONST_siege249);
	set_color_easy(WHITE_ON_BLACK);
	int yLevel = 3;
	for (int i = 0; i < len(engageConservatives); i++) {
		mvaddstrAlt(yLevel + i, 11, engageConservatives[i]);
	}
	yLevel += len(engageConservatives);
	int loc = getEscapeEngageLocation();
	if (loc == -1) return;
	if (LocationsPool::getInstance().siteHasCameras(loc))
	{
		mvaddstrAlt(yLevel, 16, CONST_siege250);
	}
	if (LocationsPool::getInstance().hasTraps(loc))
	{
		mvaddstrAlt(yLevel + 1, 16, CONST_siege251);
	}
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(23, 11, CONST_siege252);
	// Seperate logging text
	gamelog.log(CONST_siege253);
	pressAnyKey();
	if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_CCS && LocationsPool::getInstance().getLocationType(loc) == SITE_INDUSTRY_WAREHOUSE)
		CCSCapturesSite(loc); // CCS Captures warehouse -- this will be reversed if you fight them off
							  //CRIMINALIZE
	if (LocationsPool::getInstance().getSiegeType(loc) == SIEGE_POLICE) criminalizepool(LAWFLAG_RESIST, -1, loc);
	//DELETE ALL SQUADS IN THIS AREA UNLESS THEY ARE THE activesquad
	deleteAllSquadsInActiveAreaExceptActive(loc);
	// No squads at the location? Form a new one.
	formANewSquadIfThereAreNone();
	//MAKE SURE PARTY IS ORGANIZED
	autopromote(loc);
	//START FIGHTING
	createNewStoryFieldAttack(loc);
	mode_site(loc);
}
void juiceEntireCreaturePool(const long juice, const long cap);
/* siege - flavor text when you crush a CCS safe house */
const string CONST_siege273 = "+200 JUICE TO EVERYONE FOR ERADICATING THE CONSERVATIVE CRIME SQUAD";
const string CONST_siege272 = "revolution to attend to?";
const string CONST_siege271 = "The CCS has been completely destroyed.  Now wasn't there a ";
const string CONST_siege270 = "the last of the enemy's morale and confidence is shattered.";
const string CONST_siege269 = "With its Founder killed in the heart of their own base, ";
const string CONST_siege268 = "slips away.  ";
const string CONST_siege267 = "The CCS Founder lying dead at their feet, the squad ";
const string CONST_siege266 = "it is increasingly clear that this was the CCS's last safehouse.";
const string CONST_siege265 = "As your Liberals pick through the remains of the safehouse, ";
const string CONST_siege264 = "their final victory.  ";
const string CONST_siege263 = "Gunfire still ringing in their ears, the squad revels in ";
const string CONST_siege262 = "this will make a fine base for future Liberal operations.";
const string CONST_siege261 = "power has been severely weakened.  Once the safehouse cools off, ";
const string CONST_siege260 = "The CCS Founder wasn't here, but for now, their ";
const string CONST_siege258 = "The CCS Lieutenant lying dead at their feet, the squad ";
const string CONST_siege257 = "their victory.  ";
void conquertextccs()
{
	extern Log gamelog;
	extern MusicClass music;
	extern int ccs_siege_kills;
	extern char ccs_kills;
	music.play(MUSIC_CONQUER);
	//GIVE INFO SCREEN
	eraseAlt();
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(1, 26, CONST_siege255, gamelog);
	gamelog.newline();
	if (ccs_kills < 3)
	{
		set_color_easy(WHITE_ON_BLACK);
		if (ccs_siege_kills > 10)
		{
			mvaddstrAlt(3, 16, CONST_siege263, gamelog);
			mvaddstrAlt(4, 11, CONST_siege257, gamelog);
		}
		else
		{
			mvaddstrAlt(3, 16, CONST_siege258, gamelog);
			mvaddstrAlt(4, 11, CONST_siege268);
		}
		addstrAlt(CONST_siege260, gamelog);
		mvaddstrAlt(5, 11, CONST_siege261, gamelog);
		mvaddstrAlt(6, 11, CONST_siege262, gamelog);
	}
	else
	{
		if (ccs_siege_kills > 10)
		{
			mvaddstrAlt(3, 16, CONST_siege263, gamelog);
			mvaddstrAlt(4, 11, CONST_siege264, gamelog);
			mvaddstrAlt(6, 16, CONST_siege265, gamelog);
			mvaddstrAlt(7, 11, CONST_siege266, gamelog);
		}
		else
		{
			mvaddstrAlt(3, 16, CONST_siege267, gamelog);
			mvaddstrAlt(4, 11, CONST_siege268, gamelog);
			mvaddstrAlt(6, 16, CONST_siege269, gamelog);
			mvaddstrAlt(7, 11, CONST_siege270, gamelog);
		}
		gamelog.newline();
		mvaddstrAlt(9, 16, CONST_siege271, gamelog);
		mvaddstrAlt(10, 16, CONST_siege272, gamelog);
		gamelog.newline();
		mvaddstrAlt(12, 5, CONST_siege273, gamelog);
		juiceEntireCreaturePool(200, 1000);
	}
	gamelog.nextMessage();
	mvaddstrAlt(15, 19, CONST_siege274);
	while (getkeyAlt() != 'c');
}
