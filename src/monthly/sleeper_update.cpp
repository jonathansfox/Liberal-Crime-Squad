#include "../includes.h"
const string CONST_sleeper_update046 = "canseethings";
const string CONST_sleeper_update045 = "abstracted debate";
const string CONST_sleeper_update044 = "liberal power";

const string tag_LOOT = "LOOT";
const string tag_LOOT_COMPUTER = "LOOT_COMPUTER";
const string tag_LOOT_PDA = "LOOT_PDA";
const string tag_LOOT_CELLPHONE = "LOOT_CELLPHONE";
const string tag_LOOT_SECRETDOCUMENTS = "LOOT_SECRETDOCUMENTS";
const string tag_ARMOR_BLACKSUIT = "ARMOR_BLACKSUIT";
const string tag_ARMOR = "ARMOR";
const string tag_WEAPON = "WEAPON";
const string tag_WEAPON_CARBINE_M4 = "WEAPON_CARBINE_M4";
const string tag_WEAPON_SHOTGUN_PUMP = "WEAPON_SHOTGUN_PUMP";
const string tag_WEAPON_AUTORIFLE_M16 = "WEAPON_AUTORIFLE_M16";
const string tag_WEAPON_SMG_MP5 = "WEAPON_SMG_MP5";
const string tag_LOOT_SILVERWARE = "LOOT_SILVERWARE";
const string tag_LOOT_CHEMICAL = "LOOT_CHEMICAL";
const string tag_ARMOR_ARMYARMOR = "ARMOR_ARMYARMOR";
const string tag_LOOT_POLICERECORDS = "LOOT_POLICERECORDS";
const string tag_ARMOR_POLICEARMOR = "ARMOR_POLICEARMOR";
const string tag_ARMOR_SWATARMOR = "ARMOR_SWATARMOR";
const string tag_ARMOR_POLICEUNIFORM = "ARMOR_POLICEUNIFORM";
const string tag_ARMOR_DEATHSQUADUNIFORM = "ARMOR_DEATHSQUADUNIFORM";
const string tag_WEAPON_SEMIRIFLE_AR15 = "WEAPON_SEMIRIFLE_AR15";
const string tag_WEAPON_SEMIPISTOL_45 = "WEAPON_SEMIPISTOL_45";
const string tag_LOOT_MICROPHONE = "LOOT_MICROPHONE";
const string tag_LOOT_CABLENEWSFILES = "LOOT_CABLENEWSFILES";
const string tag_LOOT_AMRADIOFILES = "LOOT_AMRADIOFILES";
const string tag_LOOT_FAMILYPHOTO = "LOOT_FAMILYPHOTO";
const string tag_LOOT_CHEAPJEWELERY = "LOOT_CHEAPJEWELERY";
const string tag_LOOT_WATCH = "LOOT_WATCH";
const string tag_LOOT_TRINKET = "LOOT_TRINKET";
const string tag_LOOT_CORPFILES = "LOOT_CORPFILES";
const string tag_LOOT_FINECLOTH = "LOOT_FINECLOTH";
const string tag_WEAPON_SHANK = "WEAPON_SHANK";
const string tag_LOOT_JUDGEFILES = "LOOT_JUDGEFILES";
const string tag_LOOT_LABEQUIPMENT = "LOOT_LABEQUIPMENT";
const string tag_LOOT_RESEARCHFILES = "LOOT_RESEARCHFILES";
const string tag_LOOT_EXPENSIVEJEWELERY = "LOOT_EXPENSIVEJEWELERY";
const string tag_LOOT_DIRTYSOCK = "LOOT_DIRTYSOCK";
const string tag_LOOT_KIDART = "LOOT_KIDART";
const string tag_LOOT_CCS_BACKERLIST = "LOOT_CCS_BACKERLIST";
const string tag_LOOT_PRISONFILES = "LOOT_PRISONFILES";
/*
This file is part of Liberal Crime Squad.                                           //
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
/* monthly - sleeper behavior */
const string blankString = "";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
#include "../creature/creature.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
//#include "sitemode/newencounter.h"
void prepareencounter(short type, char sec);
#include "../items/lootTypePoolItem.h"
//#include "common/commonactions.h"
void change_public_opinion(int v, int power, char affect = 1, char cap = 100);
#include "../common/commonactionsCreature.h"
#include "../log/log.h"
#include "../common/translateid.h"
// for  int getloottype(int id);
#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include "../common/creaturePoolCreature.h"
#include "../locations/locationsPool.h"
Log gamelog; //The gamelog.
Log xmllog; // Log for xml errors or bad values.
extern int stat_recruits;
extern string string_sleeper;
 string they_are_stashed;
extern string singleDot;
string hasBeenCaughtSnooping;
string isNowHomeless;
string hasLeakedIntelligence;
string hasLeakedPolice;
string hasLeakedCorporate;
string hasLeakedPrison;
string hasLeakedCableNews;
string hasLeakedAMRadio;
string hasLeakedAnimalResearch;
string hasLeakedJudiciary;
string papersAreStashed;
string hasLeakedCCS;
string diskIsStashed;
string arrestedWhileEmbezzling;
string arrestedWhileStealing;
string droppedOffPackage;
string itemNotFound;
string lostStolenItem;
string contactModAuthor;
string hasRecruited;
string looksForwardToServing;
extern short lawList[LAWNUM];
extern char disbanding;
extern short attitude[VIEWNUM];
extern class Ledger ledger;
extern Creature encounter[ENCMAX];
/*********************************
**
**   SLEEPERS INFLUENCING
**     PUBLIC OPINION
**
**********************************/
void sleeper_influence(Creature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM])
{
	int power = (cr.get_attribute(ATTRIBUTE_CHARISMA, true) +
		cr.get_attribute(ATTRIBUTE_HEART, true) +
		cr.get_attribute(ATTRIBUTE_INTELLIGENCE, true) +
		cr.get_skill(SKILL_PERSUASION));
	// Profession specific skills
	switch (cr.type)
	{
	case CREATURE_CRITIC_ART:
		power += cr.get_skill(SKILL_WRITING);
	case CREATURE_PAINTER:
	case CREATURE_SCULPTOR:
		power += cr.get_skill(SKILL_ART);
		break;
	case CREATURE_CRITIC_MUSIC:
		power += cr.get_skill(SKILL_WRITING);
	case CREATURE_MUSICIAN:
		power += cr.get_skill(SKILL_MUSIC);
		break;
	case CREATURE_AUTHOR:
	case CREATURE_JOURNALIST:
		power += cr.get_skill(SKILL_WRITING);
		break;
	case CREATURE_JUDGE_CONSERVATIVE:
		power += cr.get_skill(SKILL_WRITING);
	case CREATURE_LAWYER:
		power += cr.get_skill(SKILL_LAW);
		break;
	case CREATURE_SCIENTIST_LABTECH:
	case CREATURE_SCIENTIST_EMINENT:
		power += cr.get_skill(SKILL_SCIENCE);
		break;
	case CREATURE_CORPORATE_CEO:
	case CREATURE_CORPORATE_MANAGER:
		power += cr.get_skill(SKILL_BUSINESS);
		break;
	case CREATURE_PRIEST:
	case CREATURE_NUN:
		power += cr.get_skill(SKILL_RELIGION);
		break;
	case CREATURE_EDUCATOR:
		power += cr.get_skill(SKILL_PSYCHOLOGY);
		break;
	}
	// Adjust power for super sleepers
	switch (cr.type)
	{
	case CREATURE_CORPORATE_CEO:
	case CREATURE_POLITICIAN:
	case CREATURE_SCIENTIST_EMINENT:
		power *= 20;
		break;
	case CREATURE_DEATHSQUAD:
	case CREATURE_EDUCATOR:
	case CREATURE_MILITARYOFFICER:
		power *= 6;
		break;
	case CREATURE_ACTOR:
	case CREATURE_GANGUNIT:
	case CREATURE_MILITARYPOLICE:
	case CREATURE_SEAL:
		power *= 4;
		break;
	default:
		power *= 2;
		break;
	}
	power = static_cast<int>(power*cr.infiltration);
	switch (cr.type)
	{
		/* Radio Personalities and News Anchors subvert Conservative news stations by
		reducing their audience and twisting views on the issues. As their respective
		media establishments become marginalized, so does their influence. */
	case CREATURE_RADIOPERSONALITY:
		change_public_opinion(VIEW_AMRADIO, 1);
		for (int i = 0; i < VIEWNUM - 3; i++)
		{
			libpower[i] += power*(100 - attitude[VIEW_AMRADIO]) / 100;
		}
		break;
	case CREATURE_NEWSANCHOR:
		change_public_opinion(VIEW_CABLENEWS, 1);
		for (int i = 0; i < VIEWNUM - 3; i++)
		{
			libpower[i] += power*(100 - attitude[VIEW_CABLENEWS]) / 100;
		}
		break;
		/* Cultural leaders block - influences cultural issues */
	case CREATURE_PRIEST:
	case CREATURE_PAINTER:
	case CREATURE_SCULPTOR:
	case CREATURE_AUTHOR:
	case CREATURE_JOURNALIST:
	case CREATURE_PSYCHOLOGIST:
	case CREATURE_MUSICIAN:
	case CREATURE_CRITIC_ART:
	case CREATURE_CRITIC_MUSIC:
	case CREATURE_ACTOR:
		libpower[VIEW_WOMEN] += power;
		libpower[VIEW_CIVILRIGHTS] += power;
		libpower[VIEW_GAY] += power;
		libpower[VIEW_FREESPEECH] += power;
		libpower[VIEW_DRUGS] += power;
		libpower[VIEW_IMMIGRATION] += power;
		break;
		/* Legal block - influences an array of social issues */
	case CREATURE_JUDGE_CONSERVATIVE:
		libpower[VIEW_JUSTICES] += power;
		libpower[VIEW_FREESPEECH] += power;
		libpower[VIEW_INTELLIGENCE] += power;
	case CREATURE_LAWYER:
		libpower[VIEW_POLICEBEHAVIOR] += power;
		libpower[VIEW_DEATHPENALTY] += power;
		libpower[VIEW_GUNCONTROL] += power;
		libpower[VIEW_DRUGS] += power;
		break;
		/* Scientists block */
	case CREATURE_SCIENTIST_EMINENT:
		libpower[VIEW_POLLUTION] += power;
	case CREATURE_SCIENTIST_LABTECH:
		libpower[VIEW_NUCLEARPOWER] += power;
		libpower[VIEW_ANIMALRESEARCH] += power;
		libpower[VIEW_GENETICS] += power;
		break;
		/* Corporate block */
	case CREATURE_CORPORATE_CEO:
		libpower[VIEW_CEOSALARY] += power;
	case CREATURE_CORPORATE_MANAGER:
		libpower[VIEW_WOMEN] += power;
		libpower[VIEW_TAXES] += power;
		libpower[VIEW_CORPORATECULTURE] += power;
		libpower[VIEW_SWEATSHOPS] += power;
		libpower[VIEW_POLLUTION] += power;
		libpower[VIEW_CIVILRIGHTS] += power;
		break;
		/* Law enforcement block */
	case CREATURE_DEATHSQUAD:
		libpower[VIEW_PRISONS] += power;
		libpower[VIEW_DEATHPENALTY] += power;
	case CREATURE_SWAT:
	case CREATURE_COP:
	case CREATURE_GANGUNIT:
		libpower[VIEW_POLICEBEHAVIOR] += power;
		libpower[VIEW_DRUGS] += power;
		libpower[VIEW_TORTURE] += power;
		libpower[VIEW_GUNCONTROL] += power;
		libpower[VIEW_PRISONS] += power;
		break;
		/* Prison block */
	case CREATURE_EDUCATOR:
	case CREATURE_PRISONGUARD:
	case CREATURE_PRISONER:
		libpower[VIEW_POLICEBEHAVIOR] += power;
		libpower[VIEW_DEATHPENALTY] += power;
		libpower[VIEW_DRUGS] += power;
		libpower[VIEW_TORTURE] += power;
		libpower[VIEW_PRISONS] += power;
		break;
		/* Intelligence block */
	case CREATURE_SECRET_SERVICE:
		libpower[VIEW_INTELLIGENCE] += power;
		break;
	case CREATURE_AGENT:
		libpower[VIEW_INTELLIGENCE] += power;
		libpower[VIEW_TORTURE] += power;
		libpower[VIEW_PRISONS] += power;
		libpower[VIEW_FREESPEECH] += power;
		break;
		/* Military block */
	case CREATURE_MERC:
		libpower[VIEW_GUNCONTROL] += power;
		break;
	case CREATURE_SOLDIER:
	case CREATURE_VETERAN:
	case CREATURE_MILITARYPOLICE:
	case CREATURE_MILITARYOFFICER:
	case CREATURE_SEAL:
		libpower[VIEW_MILITARY] += power;
		libpower[VIEW_TORTURE] += power;
		libpower[VIEW_GAY] += power;
		libpower[VIEW_WOMEN] += power;
		break;
		/* Sweatshop workers */
	case CREATURE_WORKER_SWEATSHOP:
		libpower[VIEW_IMMIGRATION] += power;
		libpower[VIEW_SWEATSHOPS] += power;
		break;
		/* No influence at all block - for people were liberal anyway, or have no way of doing any good */
	case CREATURE_WORKER_FACTORY_CHILD:
	case CREATURE_GENETIC:
	case CREATURE_GUARDDOG:
	case CREATURE_BUM:
	case CREATURE_CRACKHEAD:
	case CREATURE_TANK:
	case CREATURE_HIPPIE: // too liberal to be a proper sleeper
	case CREATURE_WORKER_FACTORY_UNION: // same
	case CREATURE_JUDGE_LIBERAL: // more again
	case CREATURE_MUTANT:
		return;
		/* Miscellaneous block -- includes everyone else */
	case CREATURE_POLITICIAN:
	{
		int a = LCSrandom(VIEWNUM - 5);
		int b = LCSrandom(VIEWNUM - 5);
		while (b == a)b = LCSrandom(VIEWNUM - 5);
		int c = LCSrandom(VIEWNUM - 5);
		while (c == a || c == b)c = LCSrandom(VIEWNUM - 5);
		libpower[a] += power;
		libpower[b] += power;
		libpower[c] += power;
	}
	break;
	case CREATURE_FIREFIGHTER:
		if (lawList[LAW_FREESPEECH] == -2)
		{
			libpower[VIEW_FREESPEECH] += power;
			break;
		}
	default: // Affect a random issue
		pickrandom(libpower) += power;
	}
}
/*********************************
**
**   SLEEPERS SNOOPING AROUND
**
**********************************/
void creatureLeaksIntel(Creature cr, const string& leak, const string& stashed) {
	eraseAlt();
	mvaddstrAlt(6, 1, string_sleeper, gamelog);
	addstrAlt(cr.name, gamelog);
	addstrAlt(leak, gamelog);
	gamelog.newline();
	mvaddstrAlt(7, 1, stashed, gamelog);
	gamelog.nextMessage();
}
void sleeper_spy(Creature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM])
{
	int homes = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, cr.location);
	if (LCSrandom(100) > 100 * cr.infiltration)
	{
		cr.juice -= 1;
		if (cr.juice < -2)
		{
			eraseAlt();
			mvaddstrAlt(6,  1, string_sleeper, gamelog);
			addstrAlt(cr.name, gamelog);
			addstrAlt(hasBeenCaughtSnooping, gamelog);
			gamelog.newline();
			mvaddstrAlt(8,  1, isNowHomeless, gamelog);
			gamelog.nextMessage();
	 	pressAnyKey();
			removesquadinfo(cr);
			cr.location = homes;
			cr.base = homes;
			cr.drop_weapons_and_clips(NULL);
			cr.activity.type = ACTIVITY_NONE;
			cr.flag &= ~CREATUREFLAG_SLEEPER;
		}
		return;
	}
	// Improves juice, as confidence improves
	if (cr.juice < 100)
	{
		cr.juice += 10;
		if (cr.juice > 100) cr.juice = 100;
	}
	LocationsPool::getInstance().setLocationMappedAndUnhidden(cr.base);
	bool pause = false;
	switch (cr.type)
	{
	case CREATURE_SECRET_SERVICE:
	case CREATURE_AGENT:
	case CREATURE_POLITICIAN:
		// Agents can leak intelligence files to you
		if (!LocationsPool::getInstance().isThereASiegeHere(homes)&&canseethings)
		{
			if (LCSrandom(lawList[LAW_PRIVACY] + 3)) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_SECRETDOCUMENTS, homes);
			creatureLeaksIntel(cr, hasLeakedIntelligence, they_are_stashed);
			pause = true;
		}
		break;
	case CREATURE_DEATHSQUAD:
	case CREATURE_SWAT:
	case CREATURE_COP:
	case CREATURE_GANGUNIT:
		// Cops can leak police files to you
		if (!LocationsPool::getInstance().isThereASiegeHere(homes)&&canseethings)
		{
			if (LCSrandom(lawList[LAW_POLICEBEHAVIOR] + 3)) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_POLICERECORDS, homes);
			creatureLeaksIntel(cr, hasLeakedPolice, they_are_stashed);
			pause = true;
		}
		break;
	case CREATURE_CORPORATE_MANAGER:
	case CREATURE_CORPORATE_CEO:
		// Can leak corporate files to you
		if (!LocationsPool::getInstance().isThereASiegeHere(homes)&&canseethings)
		{
			if (LCSrandom(lawList[LAW_CORPORATE] + 3) && cr.type != CREATURE_CORPORATE_CEO) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_CORPFILES, homes);
			creatureLeaksIntel(cr, hasLeakedCorporate, they_are_stashed);
			pause = true;
		}
		break;
	case CREATURE_EDUCATOR:
	case CREATURE_PRISONGUARD:
		if (!LocationsPool::getInstance().isThereASiegeHere(homes) &&canseethings)
		{
			if (LCSrandom(lawList[LAW_POLICEBEHAVIOR] + 3)) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_PRISONFILES, homes);
			creatureLeaksIntel(cr, hasLeakedPrison, they_are_stashed);
			pause = true;
		}
		break;
	case CREATURE_NEWSANCHOR:
		if (!LocationsPool::getInstance().isThereASiegeHere(homes) &&canseethings)
		{
			// More likely to leak these documents the more restrictive
			// free speech is -- because the more free the society, the
			// less any particular action the media takes seems scandalous
			if (LCSrandom(lawList[LAW_FREESPEECH] + 3)) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_CABLENEWSFILES, homes);
			creatureLeaksIntel(cr, hasLeakedCableNews, papersAreStashed);
			pause = true;
		}
		break;
	case CREATURE_RADIOPERSONALITY:
		if (!LocationsPool::getInstance().isThereASiegeHere(homes) &&canseethings)
		{
			// More likely to leak these documents the more restrictive
			// free speech is -- because the more free the society, the
			// less any particular action the media takes seems scandalous
			if (LCSrandom(lawList[LAW_FREESPEECH] + 3)) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_AMRADIOFILES, homes);
			creatureLeaksIntel(cr, hasLeakedAMRadio, papersAreStashed);
			pause = true;
		}
		break;
	case CREATURE_SCIENTIST_LABTECH:
	case CREATURE_SCIENTIST_EMINENT:
		if (!LocationsPool::getInstance().isThereASiegeHere(homes) &&canseethings)
		{
			if (LCSrandom(lawList[LAW_ANIMALRESEARCH] + 3)) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_RESEARCHFILES, homes);
			creatureLeaksIntel(cr, hasLeakedAnimalResearch, they_are_stashed);
			pause = true;
		}
		break;
	case CREATURE_JUDGE_CONSERVATIVE:
		if (!LocationsPool::getInstance().isThereASiegeHere(homes) &&canseethings)
		{
			if (LCSrandom(5)) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_JUDGEFILES, homes);
			creatureLeaksIntel(cr, hasLeakedJudiciary, papersAreStashed);
			pause = true;
		}
		break;
	case CREATURE_CCS_ARCHCONSERVATIVE:
		if (!LocationsPool::getInstance().isThereASiegeHere(homes)&&canseethings)
		{
			if (ccsexposure >= CCSEXPOSURE_LCSGOTDATA) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_CCS_BACKERLIST, homes);
			creatureLeaksIntel(cr, hasLeakedCCS, diskIsStashed);
			pause = true;
			ccsexposure = CCSEXPOSURE_LCSGOTDATA;
		}
		break;
	}
	if (pause) getkeyAlt();
}
/*********************************
**
**   SLEEPERS EMBEZZLING FUNDS
**
**********************************/
void sleeper_embezzle(Creature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM])
{
	if (LCSrandom(100) > 100 * cr.infiltration)
	{
		cr.juice -= 1;
		if (cr.juice < -2)
		{
			eraseAlt();
			mvaddstrAlt(6,  1, string_sleeper, gamelog);
			addstrAlt(cr.name, gamelog);
			addstrAlt(arrestedWhileEmbezzling, gamelog);
			gamelog.nextMessage();
	 	pressAnyKey();
			cr.crimes_suspected[LAWFLAG_COMMERCE]++;
			removesquadinfo(cr);
			cr.location = find_site_index_in_same_city(SITE_GOVERNMENT_POLICESTATION, cr.location);
			cr.drop_weapons_and_clips(NULL);
			cr.activity.type = ACTIVITY_NONE;
			cr.flag &= ~CREATUREFLAG_SLEEPER;
		}
		return;
	}
	// Improves juice, as confidence improves
	if (cr.juice < 100)
	{
		cr.juice += 10;
		if (cr.juice > 100) cr.juice = 100;
	}
	int income;
	switch (cr.type)
	{
	case CREATURE_CORPORATE_CEO:
		income = static_cast<int>(50000 * cr.infiltration);
		break;
	case CREATURE_SCIENTIST_EMINENT:
	case CREATURE_CORPORATE_MANAGER:
	case CREATURE_BANK_MANAGER:
	case CREATURE_POLITICIAN:
		income = static_cast<int>(5000 * cr.infiltration);
		break;
	default:
		income = static_cast<int>(500 * cr.infiltration);
		break;
	}
	ledger.add_funds(income, INCOME_EMBEZZLEMENT);
}
struct stringAndInt
{
	string str;
	int integer;
	stringAndInt(const string& str_, int integer_) : str(str_), integer(integer_) {}
	stringAndInt(int integer_, const string& str_) : str(str_), integer(integer_) {}
};
string randomString(vector<stringAndInt>);
string randomString(vector<stringAndInt> outputList) {
	for (stringAndInt s : outputList) {
		if (!LCSrandom(s.integer)) {
			return s.str;
		}
	}
	return outputList[len(outputList) - 1].str;
}
/*********************************
**
**   SLEEPERS STEALING THINGS
**
**********************************/
void sleeper_steal(Creature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM])
{
	if (LCSrandom(100) > 100 * cr.infiltration)
	{
		cr.juice -= 1;
		if (cr.juice < -2)
		{
			eraseAlt();
			mvaddstrAlt(6,  1, string_sleeper, gamelog);
			addstrAlt(cr.name, gamelog);
			addstrAlt(arrestedWhileStealing, gamelog);
			gamelog.nextMessage();
	 	pressAnyKey();
			cr.crimes_suspected[LAWFLAG_THEFT]++;
			removesquadinfo(cr);
			cr.location = find_site_index_in_same_city(SITE_GOVERNMENT_POLICESTATION, cr.location);
			cr.drop_weapons_and_clips(NULL);
			cr.activity.type = ACTIVITY_NONE;
			cr.flag &= ~CREATUREFLAG_SLEEPER;
		}
		return;
	}
	// Improves juice, as confidence improves
	if (cr.juice < 100)
	{
		cr.juice += 10;
		if (cr.juice > 100)cr.juice = 100;
	}
	cr.infiltration -= LCSrandom(10)*0.01f - 0.02f; //No effectiveness drop before? -Niel
													//Item *item;
	string item;
	int shelter = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, cr.location);
	int number_of_items = LCSrandom(10) + 1;
	int itemindex = -1; // have to check case item not found to avoid brave modders segfaults.
	int numberofxmlfails = 0; // Tell them how many fails
	while (number_of_items--)
	{
		bool loot = false;
		bool armor = false;
		bool weapon = false;
		switch (LocationsPool::getInstance().getLocationType(cr.location)) //Temporary (transitionally) solution until sites are done. -XML
		{
		case SITE_RESIDENTIAL_TENEMENT:
			item = randomString({ stringAndInt(3, tag_LOOT_KIDART),
				stringAndInt(2, tag_LOOT_DIRTYSOCK),
				stringAndInt(1, tag_LOOT_FAMILYPHOTO) });
			loot = true;
			break;
		case SITE_RESIDENTIAL_APARTMENT:
			item = randomString({ stringAndInt(5, tag_LOOT_CELLPHONE),
				stringAndInt(4, tag_LOOT_SILVERWARE),
				stringAndInt(3, tag_LOOT_TRINKET),
				stringAndInt(2, tag_LOOT_CHEAPJEWELERY),
				stringAndInt(1,  tag_LOOT_COMPUTER) });
			loot = true;
			break;
		case SITE_RESIDENTIAL_APARTMENT_UPSCALE:
			item = randomString({ stringAndInt(10, tag_LOOT_EXPENSIVEJEWELERY),
				stringAndInt(5, tag_LOOT_CELLPHONE),
				stringAndInt(4, tag_LOOT_SILVERWARE),
				stringAndInt(3, tag_LOOT_PDA),
				stringAndInt(2, tag_LOOT_CHEAPJEWELERY),
				stringAndInt(1,  tag_LOOT_COMPUTER) });
			loot = true;
			break;
		case SITE_LABORATORY_COSMETICS:
		case SITE_INDUSTRY_NUCLEAR:
		case SITE_LABORATORY_GENETIC:
			item = randomString({ stringAndInt(5, tag_LOOT_RESEARCHFILES),
				stringAndInt(2, tag_LOOT_LABEQUIPMENT),
				stringAndInt(2, tag_LOOT_COMPUTER),
				stringAndInt(5, tag_LOOT_PDA),
				stringAndInt(5, tag_LOOT_CHEMICAL),
				stringAndInt(1,  tag_LOOT_COMPUTER) });
			loot = true;
			break;
		case SITE_GOVERNMENT_COURTHOUSE:
			item = randomString({ stringAndInt(5, tag_LOOT_JUDGEFILES),
				stringAndInt(3, tag_LOOT_CELLPHONE),
				stringAndInt(2, tag_LOOT_PDA),
				stringAndInt(1,  tag_LOOT_COMPUTER) });
			loot = true;
			break;
		case SITE_GOVERNMENT_PRISON:
			item = randomString({ stringAndInt(1, tag_WEAPON_SHANK) });
			weapon = true;
			break;
		case SITE_BUSINESS_BANK:
		case SITE_GOVERNMENT_FIRESTATION:
			item = randomString({ stringAndInt(2, tag_LOOT_TRINKET),
				stringAndInt(1,  tag_LOOT_COMPUTER) });
			loot = true;
			break;
		case SITE_INDUSTRY_SWEATSHOP:
			item = randomString({ stringAndInt(1, tag_LOOT_FINECLOTH) });
			loot = true;
			break;
		case SITE_INDUSTRY_POLLUTER:
			item = randomString({ stringAndInt(1, tag_LOOT_CHEMICAL) });
			loot = true;
			break;
		case SITE_CORPORATE_HEADQUARTERS:
			item = randomString({ stringAndInt(5, tag_LOOT_CORPFILES),
				stringAndInt(3, tag_LOOT_CELLPHONE),
				stringAndInt(2, tag_LOOT_PDA),
				stringAndInt(1,  tag_LOOT_COMPUTER) });
			loot = true;
			break;
		case SITE_CORPORATE_HOUSE:
			item = randomString({ stringAndInt(8, tag_LOOT_TRINKET),
				stringAndInt(7, tag_LOOT_WATCH),
				stringAndInt(6, tag_LOOT_PDA),
				stringAndInt(5, tag_LOOT_CELLPHONE),
				stringAndInt(4, tag_LOOT_SILVERWARE),
				stringAndInt(3, tag_LOOT_CHEAPJEWELERY),
				stringAndInt(2, tag_LOOT_FAMILYPHOTO),
				stringAndInt(1,  tag_LOOT_COMPUTER) });
			loot = true;
			break;
		case SITE_MEDIA_AMRADIO:
			item = randomString({ stringAndInt(5, tag_LOOT_AMRADIOFILES),
				stringAndInt(4, tag_LOOT_MICROPHONE),
				stringAndInt(3, tag_LOOT_PDA),
				stringAndInt(2, tag_LOOT_CELLPHONE),
				stringAndInt(1,  tag_LOOT_COMPUTER) });
			loot = true;
			break;
		case SITE_MEDIA_CABLENEWS:
			item = randomString({ stringAndInt(5, tag_LOOT_CABLENEWSFILES),
				stringAndInt(4, tag_LOOT_MICROPHONE),
				stringAndInt(3, tag_LOOT_PDA),
				stringAndInt(2, tag_LOOT_CELLPHONE),
				stringAndInt(1,  tag_LOOT_COMPUTER) });
			loot = true;
			break;
		case SITE_GOVERNMENT_POLICESTATION:
			if (!LCSrandom(3))
			{
				item = randomString({ stringAndInt(4, tag_WEAPON_SMG_MP5),
					stringAndInt(3, tag_WEAPON_SEMIPISTOL_45),
					stringAndInt(2, tag_WEAPON_SHOTGUN_PUMP),
					stringAndInt(1,  tag_WEAPON_SEMIRIFLE_AR15) });
				weapon = true;
			}
			else if (!LCSrandom(2))
			{
				if (lawList[LAW_POLICEBEHAVIOR] == -2 && lawList[LAW_DEATHPENALTY] == -2 && !LCSrandom(4))item = tag_ARMOR_DEATHSQUADUNIFORM;
				else item = randomString({ stringAndInt(3, tag_ARMOR_POLICEUNIFORM),
					stringAndInt(2, tag_ARMOR_SWATARMOR),
					stringAndInt(1,  tag_ARMOR_POLICEARMOR) });
				armor = true;
			}
			else
			{
				item = randomString({ stringAndInt(5, tag_LOOT_POLICERECORDS),
					stringAndInt(3, tag_LOOT_CELLPHONE),
					stringAndInt(2, tag_LOOT_PDA),
					stringAndInt(1,  tag_LOOT_COMPUTER) });
				loot = true;
			}
			break;
		case SITE_GOVERNMENT_ARMYBASE:
			if (!LCSrandom(3))
			{
				item = randomString({
					stringAndInt(3,  tag_WEAPON_CARBINE_M4),
					stringAndInt(1, tag_WEAPON_AUTORIFLE_M16) });
				weapon = true;
			}
			else if (!LCSrandom(2))
			{
				item = randomString({ stringAndInt(1, tag_ARMOR_ARMYARMOR) });
				armor = true;
			}
			else
			{
				item = randomString({ stringAndInt(5, tag_LOOT_SECRETDOCUMENTS),
					stringAndInt(3, tag_LOOT_CELLPHONE),
					stringAndInt(2, tag_LOOT_CHEMICAL),
					stringAndInt(1,  tag_LOOT_SILVERWARE) });
				loot = true;
			}
			break;
		case SITE_GOVERNMENT_WHITE_HOUSE:
		case SITE_GOVERNMENT_INTELLIGENCEHQ:
			if (!LCSrandom(3))
			{
				item = randomString({ stringAndInt(4, tag_WEAPON_SMG_MP5),
					stringAndInt(3, tag_WEAPON_AUTORIFLE_M16),
					stringAndInt(2, tag_WEAPON_SHOTGUN_PUMP),
					stringAndInt(1,  tag_WEAPON_CARBINE_M4) });
				weapon = true;
			}
			else if (!LCSrandom(2))
			{
				item = randomString({ stringAndInt(1, tag_ARMOR_BLACKSUIT) });
				armor = true;
			}
			else
			{
				item = randomString({ stringAndInt(5, tag_LOOT_SECRETDOCUMENTS),
					stringAndInt(3, tag_LOOT_CELLPHONE),
					stringAndInt(2, tag_LOOT_PDA),
					stringAndInt(1,  tag_LOOT_COMPUTER) });
				loot = true;
			}
			break;
		}
		if (loot) {
			itemindex = getloottype(item);
			if (itemindex > -1) { LocationsPool::getInstance().stashThisLootHere(item, shelter);}
			else { numberofxmlfails++; }
		}
		else if (armor) {
			itemindex = getarmortype(item);
			if (itemindex > -1) {
				LocationsPool::getInstance().stashThisArmorHere( itemindex,  shelter);}
			else { numberofxmlfails++; }
		}
		else if (weapon) {
			itemindex = getweapontype(item);
			if (itemindex > -1) { LocationsPool::getInstance().stashThisWeaponHere( itemindex, shelter);}
			else { numberofxmlfails++; }
		}
		else {
			numberofxmlfails++;
		}
	}
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK);   mvaddstrAlt(6,  1, string_sleeper, gamelog);
	addstrAlt(cr.name, gamelog);
	addstrAlt(droppedOffPackage, gamelog);
	gamelog.nextMessage();
	if (numberofxmlfails > 0) {
		set_color_easy(RED_ON_BLUE_BRIGHT);
		mvaddstrAlt(8,  1, itemNotFound, xmllog);
		mvaddstrAlt(9,  1, numberofxmlfails, xmllog);
		addstrAlt(lostStolenItem, xmllog);
		set_color_easy(RED_ON_GREEN_BRIGHT);
		mvaddstrAlt(11,  1, contactModAuthor, xmllog);
		xmllog.nextMessage();
	}
 	pressAnyKey();
}
/*********************************
**
**   SLEEPERS CREATING SCANDALS
**
**********************************/
void sleeper_scandal(Creature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM])
{
	// Add content here!
	return;
}
/*********************************
**
**   SLEEPERS RECRUITING
**
**********************************/
void sleeper_recruit(Creature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM])
{
	if (subordinatesleft(cr))
	{
		prepareencounter(LocationsPool::getInstance().getLocationType(cr.worklocation), 0);
		for (int e = 0; e < 18; e++)
		{
			if (encounter[e].exists == false)
				break;
			if (encounter[e].worklocation == cr.worklocation || !LCSrandom(5))
			{
				if (encounter[e].align != 1 && LCSrandom(5))continue;
				Creature* recruit = new Creature(encounter[e]);
				liberalize(*recruit, 0);
				recruit->namecreature();
				recruit->hireid = cr.id;
				if (recruit->infiltration > cr.infiltration)
				{
					recruit->infiltration = cr.infiltration;
				}
				recruit->flag |= CREATUREFLAG_SLEEPER;
				LocationsPool::getInstance().setLocationMappedAndUnhidden(recruit->worklocation);
				addCreature(recruit);
				eraseAlt();
				mvaddstrAlt(6,  1, string_sleeper, gamelog);
				addstrAlt(cr.name, gamelog);
				addstrAlt(hasRecruited, gamelog);
				addstrAlt(recruit->get_type_name(), gamelog);
				addstrAlt(singleDot, gamelog);
				gamelog.newline();
				mvaddstrAlt(8,  1, recruit->name, gamelog);
				addstrAlt(looksForwardToServing, gamelog);
				gamelog.nextMessage();
		 	pressAnyKey();
				if (!subordinatesleft(cr))cr.activity.type = ACTIVITY_NONE;
				stat_recruits++;
				break;
			}
		}
	}
	return;
}
/**********************************************************************
** *JDS*
** ----- The sleeper system has been completely reworked.
** - Sleepers no longer directly influence the issues. They now affect
** the broad CONST_sleeper_update044 stats across many issues, which are used
** as a kind of monthly liberal roll akin to AM Radio and Cable News.
** - Each sleeper can affect one or more issue, throwing their power
** into the CONST_sleeper_update045 on that issue.
** - After all of the sleepers have contributed to the liberal power
** stats, a roll is made on each issue to see whether the liberals
** make background progress on those issues.
** - Several sleepers have special abilities. Lawyers and Judges, as
** always, can aid your people in the legal system. Police officers,
** corporate managers, CEOs, and agents can all now leak secret
** documents of the appropriate types, and they will make a check
** each month. This will only happen if the homeless shelter is not
** under siege, and CONST_sleeper_update046 is enabled (eg, you're not in prison
** or disbanded or some other situation where your sleeper can't get
** in touch with anyone in your squad).
** - News Anchors and Radio Personalities remain the two most powerful
** sleepers.
**********************************************************************/
void sleepereffect(Creature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM])
{
	if (disbanding)cr.activity.type = ACTIVITY_SLEEPER_LIBERAL;
	int infiltrate = 1;
	switch (cr.activity.type)
	{
	case ACTIVITY_SLEEPER_LIBERAL:
		sleeper_influence(cr, clearformess, canseethings, libpower);
		cr.infiltration -= 0.02f;
		break;
	case ACTIVITY_SLEEPER_EMBEZZLE:
		sleeper_embezzle(cr, clearformess, canseethings, libpower);
		break;
	case ACTIVITY_SLEEPER_STEAL:
		sleeper_steal(cr, clearformess, canseethings, libpower);
		infiltrate = 0;
		break;
	case ACTIVITY_SLEEPER_RECRUIT:
		sleeper_recruit(cr, clearformess, canseethings, libpower);
		break;
	case ACTIVITY_SLEEPER_SPY:
		sleeper_spy(cr, clearformess, canseethings, libpower);
		break;
	case ACTIVITY_SLEEPER_SCANDAL:
		sleeper_scandal(cr, clearformess, canseethings, libpower);
		break;
	case ACTIVITY_NONE:
	case ACTIVITY_SLEEPER_JOINLCS:
	default:
		break;
	}
	if (infiltrate) cr.infiltration += LCSrandom(8)*0.01f - 0.02f;
	if (cr.infiltration >= 1)
		cr.infiltration = 1;
	if (cr.infiltration <= 0)
		cr.infiltration = 0;
}