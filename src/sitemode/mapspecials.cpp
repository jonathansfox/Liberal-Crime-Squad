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

#include <includes.h>
#include "creature/creature.h"

#include "sitemode/advance.h"

#include "sitemode/miscactions.h"

#include "sitemode/sitedisplay.h"

#include "sitemode/stealth.h"

#include "items/loottype.h"

#include "items/loot.h"

#include "items/money.h"

//#include "common/consolesupport.h"
// for void set_color(short,short,bool)

#include "log/log.h"

#include "common/commonactions.h"

#include "common/commonactionsCreature.h"
// for void addjuice(Creature &cr, long juice, long cap);


#include "common/translateid.h"
// for  int getloottype(int id);

//#include "combat/fight.h"
void enemyattack();


#include <cursesAlternative.h>
#include <constant_strings.h>
#include <set_color_support.h>
#include "locations/locationsPool.h"
extern vector<Creature *> pool;
extern Log gamelog;
extern short postalarmtimer;
extern short mode;
extern char endgamestate;
extern short sitetype;
extern string string_sleeper;
extern string singleDot;
extern short cursite;
extern short sitealarm;
extern Creature encounter[ENCMAX];
extern siteblockst levelmap[MAPX][MAPY][MAPZ];
extern int locx;
extern int locy;
extern int locz;
extern squadst *activesquad;
extern newsstoryst *sitestory; 
extern short lawList[LAWNUM];
extern short sitealarmtimer;
extern int sitecrime;
extern short sitealienate;
extern bool deagle;
extern vector<WeaponType *> weapontype;
extern vector<ClipType *> cliptype;
extern bool m249;
extern vector<ArmorType *> armortype;
extern UniqueCreatures uniqueCreatures;
char run_broadcast(bool tv_broadcast);

#include "common/creaturePool.h"

string itemClassClip;
string itemClassWeapon;
string itemClassArmor;
string itemClassLoot;
string itemClassMoney;
/* Used by load() to create items of the correct class. */
Item* create_item(const std::string& inputXml)
{
	Item* it = NULL;
	CMarkup xml;
	xml.SetDoc(inputXml);
	xml.FindElem();
	string itemclass = xml.GetTagName();
	if (itemclass == itemClassClip)
		it = new Clip(inputXml);
	else if (itemclass == itemClassWeapon)
		it = new Weapon(inputXml);
	else if (itemclass == itemClassArmor)
		it = new Armor(inputXml);
	else if (itemclass == itemClassLoot)
		it = new Loot(inputXml);
	else if (itemclass == itemClassMoney)
		it = new Money(inputXml);
	return it;
}
void special_bouncer_greet_squad()
{
	// add a bouncer if there isn't one in the first slot
	if (!sitealarm && LocationsPool::getInstance().getRentingType(cursite) != RENTING_PERMANENT)
	{
		if (LocationsPool::getInstance().getRentingType(cursite) == RENTING_CCS)
		{
			makecreature(encounter[0], CREATURE_CCS_VIGILANTE);
			makecreature(encounter[1], CREATURE_CCS_VIGILANTE);
		}
		else if (!encounter[0].exists || encounter[0].type != CREATURE_BOUNCER)
		{
			makecreature(encounter[0], CREATURE_BOUNCER);
			makecreature(encounter[1], CREATURE_BOUNCER);
		}
	}
}
void emptyEncounter();

intAndStringVector rejectionReasons;
intAndStringVector caseRejectionReasons;

 // the vector<string> 'caseREJECTED' and 'rejected' are similar but not identicle.
 // TODO the precise differences should be made more apparant
vector<string> rejectedBecauseSmellFunny;
vector<string> notRejected;

 vector<string> randomCrime;

 vector<string> caseREJECTED_NUDE;
 vector<string> caseREJECTED_WEAPONS;
 vector<string> caseNOT_REJECTED;

 const string mostlyendings = "mostlyendings\\";
#include <customMaps.h>
 vector<file_and_text_collection> map_specials_text_file_collection = {
 customText(&rejectedBecauseSmellFunny, mostlyendings + "rejectedBecauseSmellFunny.txt"),
	 customText(&notRejected, mostlyendings + "notRejected.txt"),
	 customText(&randomCrime, mostlyendings + "randomCrime.txt"),
	 customText(&caseREJECTED_NUDE, mostlyendings + "caseREJECTED_NUDE.txt"),
	 customText(&caseREJECTED_WEAPONS, mostlyendings + "caseREJECTED_WEAPONS.txt"),
	 customText(&caseNOT_REJECTED, mostlyendings + "caseNOT_REJECTED.txt"),
	 };
void special_bouncer_assess_squad()
{
	if (LocationsPool::getInstance().getRentingType(cursite) == RENTING_PERMANENT) return;
	bool autoadmit = 0;
	char sleepername[80];
	emptyEncounter();
	special_bouncer_greet_squad();
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (pool[p]->base == cursite&&pool[p]->type == CREATURE_BOUNCER)
		{
			autoadmit = 1;
			strcpy(sleepername, pool[p]->name);
			strcpy(encounter[0].name, sleepername);
			encounter[0].align = 1;
			break;
		}
	}
	//clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(16, 1);
	if (autoadmit)
	{
		addstrAlt(string_sleeper, gamelog);
		addstrAlt(sleepername, gamelog);
		addstrAlt(" smirks and lets the squad in.", gamelog);
		gamelog.newline();
		levelmap[locx][locy][locz].special = -1;
	}
	else
	{
		if (LocationsPool::getInstance().getRentingType(cursite) == RENTING_CCS)
			addstrAlt("The Conservative scum block the door.", gamelog);
		else
			addstrAlt("The bouncer assesses your squad.", gamelog);
		gamelog.newline();
		levelmap[locx][locy][locz].special = SPECIAL_CLUB_BOUNCER_SECONDVISIT;
	}
	printencounter();
	getkeyAlt();
	char rejected = NOT_REJECTED;
	// Size up the squad for entry
	if (!autoadmit)
	{
		for (int s = 0; s<6; s++)
		{
			if (activesquad->squad[s])
			{
				// Wrong clothes? Gone
				if (activesquad->squad[s]->is_naked() && activesquad->squad[s]->animalgloss != ANIMALGLOSS_ANIMAL)
					if (rejected>REJECTED_NUDE)rejected = REJECTED_NUDE;
				if (!hasdisguise(*activesquad->squad[s]))
					if (rejected > REJECTED_DRESSCODE)rejected = REJECTED_DRESSCODE;
				// Busted, cheap, bloody clothes? Gone
				if (activesquad->squad[s]->get_armor().is_bloody())
					if (rejected > REJECTED_BLOODYCLOTHES)rejected = REJECTED_BLOODYCLOTHES;
				if (activesquad->squad[s]->get_armor().is_damaged())
					if (rejected > REJECTED_DAMAGEDCLOTHES)rejected = REJECTED_DAMAGEDCLOTHES;
				if (activesquad->squad[s]->get_armor().get_quality() != 1)
					if (rejected > REJECTED_SECONDRATECLOTHES)rejected = REJECTED_SECONDRATECLOTHES;
				// Suspicious weapons? Gone
				if (weaponcheck(*activesquad->squad[s]) > 0)
					if (rejected > REJECTED_WEAPONS)rejected = REJECTED_WEAPONS;
				// Fail a tough disguise check? Gone
				if (disguisesite(sitetype) && !(activesquad->squad[s]->skill_check(SKILL_DISGUISE, DIFFICULTY_CHALLENGING)))
					if (rejected > REJECTED_SMELLFUNNY)rejected = REJECTED_SMELLFUNNY;
				// Underage? Gone
				if (activesquad->squad[s]->age<18)
					if (rejected>REJECTED_UNDERAGE)rejected = REJECTED_UNDERAGE;
				// Not a gentleman by their definition?
				if (sitetype == SITE_BUSINESS_CIGARBAR &&
					(activesquad->squad[s]->gender_conservative != GENDER_MALE ||
						activesquad->squad[s]->gender_liberal == GENDER_FEMALE) &&
					lawList[LAW_WOMEN] < 1)
				{
					// Are you passing as a man? Are you skilled enough to pull it off?
					if (activesquad->squad[s]->gender_liberal == GENDER_FEMALE)
					{
						// Not a man by your own definition either
						if (rejected > REJECTED_FEMALE)rejected = REJECTED_FEMALE;
					}
					else if (disguisesite(sitetype) && !(activesquad->squad[s]->skill_check(SKILL_DISGUISE, DIFFICULTY_HARD)) && lawList[LAW_GAY] != 2)
					{
						// Not skilled enough to pull it off
						if (rejected > REJECTED_FEMALEISH)rejected = REJECTED_FEMALEISH;
					}
				}
				// High security in gentleman's club? Gone
				if (sitetype == SITE_BUSINESS_CIGARBAR && LocationsPool::getInstance().isThisPlaceHighSecurity(cursite))
					if (rejected > REJECTED_GUESTLIST)rejected = REJECTED_GUESTLIST;
				if (LocationsPool::getInstance().getRentingType(cursite) == RENTING_CCS && LocationsPool::getInstance().getLocationType(cursite) != SITE_BUSINESS_BARANDGRILL)
					rejected = REJECTED_CCS;
			}
		}
		moveAlt(17, 1);
		if (rejectionReasons.count(rejected)) {
			set_color_easy(RED_ON_BLACK_BRIGHT);
			addstrAlt(pickrandom(rejectionReasons[rejected]), gamelog);
		}else
		switch (rejected)
		{
		case REJECTED_SMELLFUNNY:
			set_color_easy(RED_ON_BLACK_BRIGHT);
			if (!LCSrandom(len(rejectedBecauseSmellFunny) - 1)) {
				if (lawList[LAW_FREESPEECH] == -2)addstrAlt("\"Get the [heck] out of here.\"", gamelog);
				else if (lawList[LAW_FREESPEECH] == 2)addstrAlt("\"Get the fuck out of here.\"", gamelog);
				else addstrAlt("\"Get the hell out of here.\"", gamelog);
			}
			else {
				addstrAlt(pickrandom(rejectedBecauseSmellFunny), gamelog);
			}
			break;
		case NOT_REJECTED:
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			addstrAlt(pickrandom(notRejected), gamelog);
			break;
		}
		gamelog.newline();
		getkeyAlt();
	}
	else encounter[0].exists = 0;
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	for (int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++)
		{
			if (levelmap[locx + dx][locy + dy][locz].flag & SITEBLOCK_DOOR)
			{
				if (rejected < NOT_REJECTED)
				{
					levelmap[locx + dx][locy + dy][locz].flag |= SITEBLOCK_LOCKED;
					levelmap[locx + dx][locy + dy][locz].flag |= SITEBLOCK_CLOCK;
				}
				else levelmap[locx + dx][locy + dy][locz].flag &= ~SITEBLOCK_DOOR;
			}
		}
	encounter[0].cantbluff = 1;
}
void special_lab_cosmetics_cagedanimals()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "You see fluffy white rabbits in a locked cage.", gamelog);
		gamelog.newline();
		mvaddstrAlt(17,  1, "Free them? (Yes or No)");
		int c = getkeyAlt();
		if (c == 'y')
		{
			char actual;
			if (unlock(UNLOCK_CAGE, actual))
			{
				int time = 20 + LCSrandom(10);
				if (time < 1)time = 1;
				if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
				sitecrime++;
				juiceparty(3, 100);
				sitestory->crime.push_back(CRIME_FREE_RABBITS);
				criminalizeparty(LAWFLAG_VANDALISM);
			}
			if (actual)
			{
				alienationcheck(0);
				noticecheck(-1);
				levelmap[locx][locy][locz].special = -1;
			}
			return;
		}
		else if (c == 'n')return;
	}
}
void special_readsign(int sign)
{
	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	switch (sign) //TODO: Log these?
	{
	case SPECIAL_SIGN_ONE:
		switch (LocationsPool::getInstance().getLocationType(cursite))
		{
		default:
			mvaddstrAlt(16,  1, "\"The best way not to fail is to succeed.\"");
			break;
		case SITE_INDUSTRY_NUCLEAR:
			mvaddstrAlt(16,  1, "Welcome to the NPP Nuclear Plant. Please enjoy");
			mvaddstrAlt(17,  1, "the museum displays in the gift shop.");
			break;
		case SITE_RESIDENTIAL_TENEMENT:
		case SITE_RESIDENTIAL_APARTMENT:
		case SITE_RESIDENTIAL_APARTMENT_UPSCALE:
			mvaddstrAlt(16,  1, "The landlord's office is the first door");
			mvaddstrAlt(17,  1, "on the left.");
			break;
		}
		break;
	case SPECIAL_SIGN_TWO:
		switch (LocationsPool::getInstance().getLocationType(cursite))
		{
		default:
			mvaddstrAlt(16,  1, "\"Great work is done by people who do great work.\"");
			break;
		}
		break;
	case SPECIAL_SIGN_THREE:
		switch (LocationsPool::getInstance().getLocationType(cursite))
		{
		default:
			mvaddstrAlt(16,  1, "Employees Only");
			break;
		}
		break;
	}
	getkeyAlt();
}
void special_nuclear_onoff()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		if (lawList[LAW_NUCLEARPOWER] == 2)
		{
			mvaddstrAlt(16,  1, "You see the nuclear waste center control room.", gamelog);
			gamelog.newline();
			mvaddstrAlt(17,  1, "Attempt to release nuclear waste? (Yes or No)");
		}
		else
		{
			mvaddstrAlt(16,  1, "You see the nuclear power plant control room.", gamelog);
			gamelog.newline();
			mvaddstrAlt(17,  1, "Mess with the reactor settings? (Yes or No)");
		}
		int c = getkeyAlt();
		if (c == 'y')
		{
			clearmessagearea();
			levelmap[locx][locy][locz].special = -1;
			char max = DIFFICULTY_HARD;
			Creature* maxs = 0;
			for (int p = 0; p < 6; p++)
			{
				if (activesquad->squad[p] != NULL&&activesquad->squad[p]->alive)
				{
					if (activesquad->squad[p]->skill_check(SKILL_SCIENCE, max))
					{
						maxs = activesquad->squad[p];
						break;
					}
				}
			}
			if (maxs)
			{
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, maxs->name, gamelog);
				addstrAlt(" presses the big red button!", gamelog);
				gamelog.newline();
				getkeyAlt();
				mvaddstrAlt(17,  1, singleDot, gamelog);
				getkeyAlt();
				addstrAlt(singleDot, gamelog);
				getkeyAlt();
				addstrAlt(singleDot, gamelog);
				getkeyAlt();
				if (lawList[LAW_NUCLEARPOWER] == 2)
				{
					mvaddstrAlt(17,  1, "The nuclear waste gets released into the state's water supply!", gamelog);
					gamelog.newline();
					change_public_opinion(VIEW_NUCLEARPOWER, 15, 0, 95);
					change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, -50, 0, 0);
					getkeyAlt();
					juiceparty(40, 1000); // Instant juice!
					sitecrime += 25; //Shutdown Site
					sitestory->crime.push_back(CRIME_SHUTDOWNREACTOR);
				}
				else
				{
					mvaddstrAlt(16,  1, "A deafening alarm sounds!", gamelog);
					gamelog.newline();
					addstrAlt("                "); // Remove remaining part of previous text.
					mvaddstrAlt(17,  1, "The reactor is overheating!", gamelog);
					gamelog.newline();
					change_public_opinion(VIEW_NUCLEARPOWER, 15, 0, 95);
					getkeyAlt();
					juiceparty(100, 1000); // Instant juice!
					sitecrime += 50; //Shutdown Site
					sitestory->crime.push_back(CRIME_SHUTDOWNREACTOR);
				}
			}
			else
			{
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, "After some failed attempts, and a very loud alarm, ", gamelog);
				mvaddstrAlt(17,  1, "the Squad resigns to just leaving a threatening note.", gamelog);
				gamelog.newline();
				getkeyAlt();
				juiceparty(15, 500);
			}
			sitealarm = 1;
			alienationcheck(1);
			levelmap[locx][locy][locz].special = -1;
			sitecrime += 5;
			criminalizeparty(LAWFLAG_TERRORISM);
			return;
		}
		else if (c == 'n')return;
	}
}
void fillEncounter(CreatureTypes c, int numleft);
void special_lab_genetic_cagedanimals()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "You see horrible misshapen creatures in a sealed cage.", gamelog);
		gamelog.newline();
		mvaddstrAlt(17,  1, "Free them? (Yes or No)");
		int c = getkeyAlt();
		if (c == 'y')
		{
			char actual;
			if (unlock(UNLOCK_CAGE_HARD, actual))
			{
				int time = 20 + LCSrandom(10);
				if (time < 1)time = 1;
				if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
				sitecrime++;
				juiceparty(5, 200);
				sitestory->crime.push_back(CRIME_FREE_BEASTS);
				criminalizeparty(LAWFLAG_VANDALISM);
				if (!LCSrandom(2))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16,  1, "Uh, maybe that idea was Conservative in retrospect...", gamelog);
					gamelog.newline();
					int numleft = LCSrandom(6) + 1;
					fillEncounter(CREATURE_GENETIC, numleft);
					if (mode == GAMEMODE_CHASECAR ||
						mode == GAMEMODE_CHASEFOOT)printchaseencounter();
					else printencounter();
					getkeyAlt();
					sitealarm = 1;
					alienationcheck(1);
				}
				else
				{
					alienationcheck(0);
				}
			}
			else if (actual)
			{
				noticecheck(-1);
			}
			if (actual)
			{
				levelmap[locx][locy][locz].special = -1;
			}
			return;
		}
		else if (c == 'n')return;
	}
}
void special_policestation_lockup()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "You see prisoners in the detention room.", gamelog);
		gamelog.newline();
		mvaddstrAlt(17,  1, "Free them? (Yes or No)");
		int c = getkeyAlt();
		if (c == 'y')
		{
			char actual;
			if (unlock(UNLOCK_CELL, actual))
			{
				int numleft = LCSrandom(8) + 2;
				fillEncounter(CREATURE_PRISONER, numleft);
				juiceparty(50, 1000);
				sitecrime += 20;
				int time = 20 + LCSrandom(10);
				if (time < 1)time = 1;
				if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
				if (mode == GAMEMODE_CHASECAR ||
					mode == GAMEMODE_CHASEFOOT)printchaseencounter();
				else printencounter();
				refreshAlt();
				partyrescue(SPECIAL_POLICESTATION_LOCKUP);
			}
			if (actual)
			{
				alienationcheck(1);
				noticecheck(-1, DIFFICULTY_HARD);
				levelmap[locx][locy][locz].special = -1;
				sitecrime += 2;
				sitestory->crime.push_back(CRIME_POLICE_LOCKUP);
				criminalizeparty(LAWFLAG_HELPESCAPE);
			}
			return;
		}
		else if (c == 'n')return;
	}
}
void special_courthouse_lockup()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "You see prisoners in the Courthouse jail.", gamelog);
		gamelog.newline();
		mvaddstrAlt(17,  1, "Free them? (Yes or No)");
		int c = getkeyAlt();
		if (c == 'y')
		{
			char actual;
			if (unlock(UNLOCK_CELL, actual))
			{
				int numleft = LCSrandom(8) + 2;
				fillEncounter(CREATURE_PRISONER, numleft);
				juiceparty(50, 1000);
				sitecrime += 20;
				int time = 20 + LCSrandom(10);
				if (time < 1)time = 1;
				if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
				if (mode == GAMEMODE_CHASECAR ||
					mode == GAMEMODE_CHASEFOOT)printchaseencounter();
				else printencounter();
				refreshAlt();
				partyrescue(SPECIAL_COURTHOUSE_LOCKUP);
			}
			if (actual)
			{
				alienationcheck(1);
				noticecheck(-1, DIFFICULTY_HARD);
				levelmap[locx][locy][locz].special = -1;
				sitecrime += 3;
				sitestory->crime.push_back(CRIME_COURTHOUSE_LOCKUP);
				criminalizeparty(LAWFLAG_HELPESCAPE);
			}
			return;
		}
		else if (c == 'n')return;
	}
}
void special_courthouse_jury()
{
	int p;
	if (sitealarm || sitealienate)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "It appears as if this room has been ", gamelog);
		mvaddstrAlt(17,  1, "vacated in a hurry.", gamelog);
		gamelog.newline();
		getkeyAlt();
		return;
	}
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "You've found a Jury in deliberations!", gamelog);
		gamelog.newline();
		mvaddstrAlt(17,  1, "Attempt to influence them? (Yes or No)");
		int c = getkeyAlt();
		if (c == 'y')
		{
			levelmap[locx][locy][locz].special = -1;
			char succeed = 0;
			int maxattack = 0;
			int maxp = -1;
			for (p = 0; p<6; p++)
			{
				if (activesquad->squad[p] != NULL)
				{
					if (activesquad->squad[p]->alive)
					{
						if (activesquad->squad[p]->get_attribute(ATTRIBUTE_CHARISMA, true) +
							activesquad->squad[p]->get_attribute(ATTRIBUTE_INTELLIGENCE, true) +
							activesquad->squad[p]->get_skill(SKILL_PERSUASION) +
							activesquad->squad[p]->get_skill(SKILL_LAW)>maxattack)
						{
							maxattack = activesquad->squad[p]->get_attribute(ATTRIBUTE_CHARISMA, true) +
								activesquad->squad[p]->get_attribute(ATTRIBUTE_INTELLIGENCE, true) +
								activesquad->squad[p]->get_skill(SKILL_PERSUASION) +
								activesquad->squad[p]->get_skill(SKILL_LAW);
							maxp = p;
						}
					}
				}
			}
			if (maxp > -1)
			{
				int p = maxp;
				activesquad->squad[p]->train(SKILL_PERSUASION, 20);
				activesquad->squad[p]->train(SKILL_LAW, 20);
				if (activesquad->squad[p]->skill_check(SKILL_PERSUASION, DIFFICULTY_HARD) &&
					activesquad->squad[p]->skill_check(SKILL_LAW, DIFFICULTY_CHALLENGING))succeed = 1;
				if (succeed)
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16,  1, activesquad->squad[p]->name, gamelog);
					addstrAlt(" works the room like in Twelve Angry Men, and the jury ", gamelog);
					mvaddstrAlt(17,  1, "concludes that ", gamelog);//XXX: This is very awkward grammar.
					addstrAlt(pickrandom(randomCrime), gamelog);
					addstrAlt(" wasn't really wrong here.", gamelog);
					gamelog.newline();
					getkeyAlt();
					alienationcheck(0);
					noticecheck(-1);
					//INSTANT JUICE BONUS
					addjuice(*(activesquad->squad[p]), 25, 200);
				}
				else
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16,  1, activesquad->squad[p]->name, gamelog);
					addstrAlt(" wasn't quite convincing...", gamelog);
					gamelog.newline();
					getkeyAlt();
					int numleft = 12;
					fillEncounter(CREATURE_JUROR, numleft);
					if (mode == GAMEMODE_CHASECAR ||
						mode == GAMEMODE_CHASEFOOT)printchaseencounter();
					else printencounter();
					refreshAlt();
					sitealarm = 1;
					sitealienate = 2;
					sitecrime += 10;
					sitestory->crime.push_back(CRIME_JURYTAMPERING);
					criminalizeparty(LAWFLAG_JURY);
				}
			}
			return;
		}
		else if (c == 'n')return;
	}
}
#include "items/lootTypePoolItem.h"
void special_prison_control(short prison_control_type)
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "You've found the ", gamelog);
		if (prison_control_type == SPECIAL_PRISON_CONTROL_LOW)
			addstrAlt("low security ", gamelog);
		else if (prison_control_type == SPECIAL_PRISON_CONTROL_MEDIUM)
			addstrAlt("medium security ", gamelog);
		else if (prison_control_type == SPECIAL_PRISON_CONTROL_HIGH)
			addstrAlt("high security ", gamelog);
		addstrAlt("prison control room.", gamelog);
		gamelog.newline();
		mvaddstrAlt(17,  1, "Free the prisoners? (Yes or No)");
		int c = getkeyAlt();
		if (c == 'y')
		{
			int numleft = LCSrandom(8) + 2;
			if (prison_control_type == SPECIAL_PRISON_CONTROL_LOW)
			{
				switch (lawList[LAW_DEATHPENALTY])
				{
				case -1: numleft = LCSrandom(6) + 2; break;
				case -2: numleft = LCSrandom(3) + 1; break;
				}
			}
			else if (prison_control_type == SPECIAL_PRISON_CONTROL_MEDIUM)
			{
				switch (lawList[LAW_DEATHPENALTY])
				{
				case 2: numleft = LCSrandom(4) + 1;
				case 1: numleft = LCSrandom(6) + 1;
				}
			}
			else if (prison_control_type == SPECIAL_PRISON_CONTROL_HIGH)
			{
				switch (lawList[LAW_DEATHPENALTY])
				{
				case  2: numleft = 0; break;
				case  1: numleft = LCSrandom(4); break;
				case -1: numleft += LCSrandom(4); break;
				case -2: numleft += LCSrandom(4) + 2; break;
				}
			}
			fillEncounter(CREATURE_PRISONER, numleft);
			int time = 20 + LCSrandom(10);
			if (time < 1)time = 1;
			if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
			if (mode == GAMEMODE_CHASECAR ||
				mode == GAMEMODE_CHASEFOOT)printchaseencounter();
			else printencounter();
			refreshAlt();
			partyrescue(prison_control_type);
			alienationcheck(1);
			noticecheck(-1);
			levelmap[locx][locy][locz].special = -1;
			sitecrime += 30;
			juiceparty(50, 1000);
			sitestory->crime.push_back(CRIME_PRISON_RELEASE);
			criminalizeparty(LAWFLAG_HELPESCAPE);
			return;
		}
		else if (c == 'n')return;
	}
}
void special_intel_supercomputer()
{
	if (sitealarm || sitealienate)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "The security alert has caused the ", gamelog);
		mvaddstrAlt(17,  1, "computer to shut down.", gamelog);
		gamelog.newline();
		getkeyAlt();
		return;
	}
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "You've found the Intelligence Supercomputer.", gamelog);
		gamelog.newline();
		mvaddstrAlt(17,  1, "Hack it? (Yes or No)");
		int c = getkeyAlt();
		if (c == 'y')
		{
			char actual;
			if (hack(HACK_SUPERCOMPUTER, actual))
			{
				clearmessagearea();
				//char *loot;
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, "The Squad obtains sensitive information", gamelog);
				if (endgamestate >= ENDGAME_CCS_APPEARANCE && endgamestate < ENDGAME_CCS_DEFEATED && ccsexposure < CCSEXPOSURE_LCSGOTDATA)
				{
					addstrAlt(",", gamelog);
					mvaddstrAlt(17,  1, "including a list of government backers of the CCS.", gamelog);
					activesquad->loot.push_back(getNewLoot(tag_LOOT_CCS_BACKERLIST));
					ccsexposure = CCSEXPOSURE_LCSGOTDATA;
				}
				else
				{
					addstrAlt(singleDot, gamelog);
				}
				gamelog.newline();
				juiceparty(50, 1000);
				activesquad->loot.push_back(getNewLoot(tag_LOOT_INTHQDISK));
				getkeyAlt();
			}
			if (actual)
			{
				int time = 20 + LCSrandom(10);
				if (time < 1)time = 1;
				if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
				alienationcheck(1);
				noticecheck(-1, DIFFICULTY_HARD);
				levelmap[locx][locy][locz].special = -1;
				sitecrime += 3;
				sitestory->crime.push_back(CRIME_HACK_INTEL);
				criminalizeparty(LAWFLAG_TREASON);
			}
			return;
		}
		else if (c == 'n')return;
	}
}
void special_graffiti()
{
	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16,  1, "The squad sprays Liberal Graffiti!", gamelog);
	gamelog.newline();
	if (!sitestory->claimed)
		sitestory->claimed = 1;
	getkeyAlt();
	int time = 20 + LCSrandom(10);
	if (time < 1)time = 1;
	if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
	alienationcheck(0);
	noticecheck(-1, DIFFICULTY_HARD);
	levelmap[locx][locy][locz].flag |= SITEBLOCK_GRAFFITI;
	levelmap[locx][locy][locz].flag &= ~(SITEBLOCK_GRAFFITI_CCS | SITEBLOCK_GRAFFITI_OTHER);
	if (!LocationsPool::getInstance().isThisPlaceHighSecurity(cursite))
	{
		LocationsPool::getInstance().eraseAndReplaceGraffiti(cursite, locx, locy, locz);
	}
	sitecrime++;
	for (int i = 0; i < 6; i++)
	{
		if (activesquad->squad[i])
			addjuice(*(activesquad->squad[i]), 1, 50);
	}
	criminalizeparty(LAWFLAG_VANDALISM);
	sitestory->crime.push_back(CRIME_TAGGING);
	return;
}
void special_sweatshop_equipment()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "You see some textile equipment.", gamelog);
		gamelog.newline();
		mvaddstrAlt(17,  1, "Destroy it? (Yes or No)");
		int c = getkeyAlt();
		if (c == 'y')
		{
			int time = 20 + LCSrandom(10);
			if (time < 1)time = 1;
			if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
			alienationcheck(0);
			noticecheck(-1, DIFFICULTY_HEROIC);
			levelmap[locx][locy][locz].special = -1;
			levelmap[locx][locy][locz].flag |= SITEBLOCK_DEBRIS;
			sitecrime++;
			juiceparty(5, 100);
			sitestory->crime.push_back(CRIME_BREAK_SWEATSHOP);
			criminalizeparty(LAWFLAG_VANDALISM);
			return;
		}
		else if (c == 'n')return;
	}
}
void special_polluter_equipment()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "You see some industrial equipment.", gamelog);
		gamelog.newline();
		mvaddstrAlt(17,  1, "Destroy it? (Yes or No)");
		int c = getkeyAlt();
		if (c == 'y')
		{
			int time = 20 + LCSrandom(10);
			if (time < 1)time = 1;
			if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
			change_public_opinion(VIEW_POLLUTION, 2, 1, 70);
			alienationcheck(0);
			noticecheck(-1, DIFFICULTY_HEROIC);
			levelmap[locx][locy][locz].special = -1;
			levelmap[locx][locy][locz].flag |= SITEBLOCK_DEBRIS;
			sitecrime += 2;
			juiceparty(5, 100);
			sitestory->crime.push_back(CRIME_BREAK_FACTORY);
			criminalizeparty(LAWFLAG_VANDALISM);
			return;
		}
		else if (c == 'n')return;
	}
}
void special_house_photos()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "You've found a safe.", gamelog);
		gamelog.newline();
		mvaddstrAlt(17,  1, "Open it? (Yes or No)");
		int c = getkeyAlt();
		if (c == 'y')
		{
			char actual;
			if (unlock(UNLOCK_SAFE, actual))
			{
				bool empty = true;
				if (deagle == false)
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16,  1, "The squad has found a Desert Eagle.", gamelog);
					gamelog.newline();
					getkeyAlt();
					Weapon* de = new Weapon(*weapontype[getweapontype(tag_WEAPON_DESERT_EAGLE)]);
					Clip r(*cliptype[getcliptype(tag_CLIP_50AE)]);
					de->reload(r);
					activesquad->loot.push_back(de);
					Item *it = new Clip(*cliptype[getcliptype(tag_CLIP_50AE)], 9);
					activesquad->loot.push_back(it);
					deagle = true;
					empty = false;
				}
				if (LCSrandom(2))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16,  1, "This guy sure had a lot of $100 bills.", gamelog);
					gamelog.newline();
					getkeyAlt();
					Item *it = new Money(1000 * (1 + LCSrandom(10)));
					activesquad->loot.push_back(it);
					empty = false;
				}
				if (LCSrandom(2))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16,  1, "The squad Liberates some expensive jewelery.", gamelog);
					gamelog.newline();
					getkeyAlt();
					activesquad->loot.push_back(getNewLoot(tag_LOOT_EXPENSIVEJEWELERY, 3));
					empty = false;
				}
				if (!LCSrandom(3))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16,  1, "There are some... very compromising photos here.", gamelog);
					gamelog.newline();
					getkeyAlt();
					activesquad->loot.push_back(getNewLoot(tag_LOOT_CEOPHOTOS));
					empty = false;
				}
				if (!LCSrandom(3))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16,  1, "There are some drugs here.", gamelog);
					gamelog.newline();
					getkeyAlt();
					empty = false;
				}
				if (!LCSrandom(3))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16,  1, "Wow, get a load of these love letters. ", gamelog);
					mvaddstrAlt(17,  1, "The squad will take those.");
					gamelog.newline();
					getkeyAlt();
					activesquad->loot.push_back(getNewLoot(tag_LOOT_CEOLOVELETTERS));
					empty = false;
				}
				if (!LCSrandom(3))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16,  1, "These documents show serious tax evasion.", gamelog);
					gamelog.newline();
					getkeyAlt();
					activesquad->loot.push_back(getNewLoot(tag_LOOT_CEOTAXPAPERS));
					empty = false;
				}
				if (empty)
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16,  1, "Wow, it's empty.  That sucks.", gamelog);
					gamelog.newline();
					getkeyAlt();
				}
				else
				{
					juiceparty(50, 1000);
					sitecrime += 40;
					sitestory->crime.push_back(CRIME_HOUSE_PHOTOS);
					criminalizeparty(LAWFLAG_THEFT);
					int time = 20 + LCSrandom(10);
					if (time < 1)time = 1;
					if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
				}
			}
			if (actual)
			{
				alienationcheck(0);
				noticecheck(-1);
				levelmap[locx][locy][locz].special = -1;
			}
			return;
		}
		else if (c == 'n')return;
	}
}
void special_armory()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "You've found the armory.", gamelog);
		gamelog.newline();
		mvaddstrAlt(17,  1, "Break in? (Yes or No)");
		int c = getkeyAlt();
		if (c == 'y')
		{
			clearmessagearea();
			sitealarm = 1;
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(16,  1, "Alarms go off!", gamelog);
			gamelog.newline();
			getkeyAlt();
			bool empty = true;
			Item *it;
			if (m249 == false && LocationsPool::getInstance().getLocationType(cursite) == SITE_GOVERNMENT_ARMYBASE)
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, "Jackpot! The squad found a M249 Machine Gun!", gamelog);
				gamelog.newline();
				getkeyAlt();
				Weapon* de = new Weapon(*weapontype[getweapontype(tag_WEAPON_M249_MACHINEGUN)]);
				Clip r(*cliptype[getcliptype(tag_CLIP_DRUM)]);
				de->reload(r);
				activesquad->loot.push_back(de);
				it = new Clip(*cliptype[getcliptype(tag_CLIP_DRUM)], 9);
				activesquad->loot.push_back(it);
				m249 = true;
				empty = false;
			}
			if (LCSrandom(2))
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, "The squad finds some M16 Assault Rifles.", gamelog);
				gamelog.newline();
				getkeyAlt();
				int num = 0;
				do
				{
					Weapon* de = new Weapon(*weapontype[getweapontype(tag_WEAPON_AUTORIFLE_M16)]);
					Clip r(*cliptype[getcliptype(tag_CLIP_ASSAULT)]);
					de->reload(r);
					activesquad->loot.push_back(de);
					it = new Clip(*cliptype[getcliptype(tag_CLIP_ASSAULT)], 5);
					activesquad->loot.push_back(it);
					num++;
				} while (num < 2 || (LCSrandom(2) && num < 5));
				empty = false;
			}
			if (LCSrandom(2))
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, "The squad finds some M4 Carbines.", gamelog);
				gamelog.newline();
				getkeyAlt();
				int num = 0;
				do
				{
					Weapon* de = new Weapon(*weapontype[getweapontype(tag_WEAPON_CARBINE_M4)]);
					Clip r(*cliptype[getcliptype(tag_CLIP_ASSAULT)]);
					de->reload(r);
					activesquad->loot.push_back(de);
					it = new Clip(*cliptype[getcliptype(tag_CLIP_ASSAULT)], 5);
					activesquad->loot.push_back(it);
					num++;
				} while (num < 2 || (LCSrandom(2) && num < 5));
				empty = false;
			}
			if (LCSrandom(2))
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, "The squad finds some body armor.", gamelog);
				gamelog.newline();
				getkeyAlt();
				int num = 0;
				do
				{
					Armor* de;
					if (LocationsPool::getInstance().getLocationType(cursite) == SITE_GOVERNMENT_ARMYBASE)
						de = new Armor(*armortype[getarmortype(tag_ARMOR_ARMYARMOR)]);
					else
						de = new Armor(*armortype[getarmortype(tag_ARMOR_CIVILLIANARMOR)]);
					activesquad->loot.push_back(de);
					num++;
				} while (num < 2 || (LCSrandom(2) && num < 5));
				empty = false;
			}
			if (empty)
			{
				criminalizeparty(LAWFLAG_TREASON);
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, "It's a trap!  The armory is empty.", gamelog);
				gamelog.newline();
				getkeyAlt();
				int numleft = LCSrandom(8) + 2;
				if (LocationsPool::getInstance().getLocationType(cursite) == SITE_GOVERNMENT_ARMYBASE) {
					fillEncounter(CREATURE_SOLDIER, numleft);
				}
				else {
					fillEncounter(CREATURE_MERC, numleft);
				}
			}
			else
			{
				juiceparty(50, 1000);
				sitecrime += 40;
				sitestory->crime.push_back(CRIME_ARMORY);
				criminalizeparty(LAWFLAG_THEFT);
				criminalizeparty(LAWFLAG_TREASON);
				int time = 20 + LCSrandom(10);
				if (time < 1)time = 1;
				if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, "Guards are everywhere!", gamelog);
				gamelog.newline();
				getkeyAlt();
				int numleft = LCSrandom(4) + 2;
				if (LocationsPool::getInstance().getLocationType(cursite) == SITE_GOVERNMENT_ARMYBASE) {
					fillEncounter(CREATURE_SOLDIER, numleft);
				}
				else {
					fillEncounter(CREATURE_MERC, numleft);
				}
			}
			alienationcheck(0);
			noticecheck(-1);
			levelmap[locx][locy][locz].special = -1;
			return;
		}
		else if (c == 'n')return;
	}
}
void special_corporate_files()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "You've found a safe.", gamelog);
		gamelog.newline();
		mvaddstrAlt(17,  1, "Open it? (Yes or No)");
		int c = getkeyAlt();
		if (c == 'y')
		{
			char actual;
			if (unlock(UNLOCK_SAFE, actual))
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, "The Squad has found some very interesting files.", gamelog);
				gamelog.newline();
				activesquad->loot.push_back(getNewLoot(tag_LOOT_CORPFILES));
				activesquad->loot.push_back(getNewLoot(tag_LOOT_CORPFILES));
				juiceparty(50, 1000);
				sitecrime += 40;
				int time = 20 + LCSrandom(10);
				if (time < 1)time = 1;
				if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
				getkeyAlt();
			}
			if (actual)
			{
				alienationcheck(0);
				noticecheck(-1);
				levelmap[locx][locy][locz].special = -1;
				sitecrime += 3;
				sitestory->crime.push_back(CRIME_CORP_FILES);
				criminalizeparty(LAWFLAG_THEFT);
			}
			return;
		}
		else if (c == 'n')return;
	}
}
void special_radio_broadcaststudio()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		if (sitealarm || sitealienate)
		{
			mvaddstrAlt(16,  1, "The radio broadcasters left the equipment on in ", gamelog);
			mvaddstrAlt(17,  1, "their rush to get out.", gamelog);
			gamelog.newline();
			addstrAlt(" Take over the studio? (Yes or No)");
		}
		else
		{
			mvaddstrAlt(16,  1, "You've found a radio broadcasting room.", gamelog);
			gamelog.newline();
			mvaddstrAlt(17,  1, "Interrupt this evening's programming? (Yes or No)");
		}
		int c = getkeyAlt();
		if (c == 'y')
		{
			if (run_broadcast(false))
			{
				sitestory->claimed = 2;
				levelmap[locx][locy][locz].special = -1;
			}
			return;
		}
		else if (c == 'n')return;
	}
}
void special_news_broadcaststudio()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		if (sitealarm || sitealienate)
		{
			mvaddstrAlt(16,  1, "The Cable News broadcasters left the equipment on in", gamelog);
			mvaddstrAlt(17,  1, "their rush to get out.");
			gamelog.newline();
			addstrAlt(" Take over the studio? (Yes or No)");
		}
		else
		{
			mvaddstrAlt(16,  1, "You've found a Cable News broadcasting studio.", gamelog);
			mvaddstrAlt(17,  1, "Start an impromptu news program? (Yes or No)");
		}
		int c = getkeyAlt();
		if (c == 'y')
		{
			if (run_broadcast(true))
			{
				sitestory->claimed = 2;
				levelmap[locx][locy][locz].special = -1;
			}
			return;
		}
		else if (c == 'n')return;
	}
}
void special_display_case()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "You see a display case.", gamelog);
		mvaddstrAlt(17,  1, "Smash it? (Yes or No)");
		int c = getkeyAlt();
		if (c == 'y')
		{
			int time = 20 + LCSrandom(10);
			if (time < 1)time = 1;
			if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
			alienationcheck(0);
			noticecheck(-1, DIFFICULTY_HEROIC);
			levelmap[locx][locy][locz].special = -1;
			levelmap[locx][locy][locz].flag |= SITEBLOCK_DEBRIS;
			sitecrime++;
			juiceparty(5, 100);
			sitestory->crime.push_back(CRIME_VANDALISM);
			criminalizeparty(LAWFLAG_VANDALISM);
			return;
		}
		else if (c == 'n')return;
	}
}
void spawn_security()
{
	// add a bouncer if there isn't one in the first slot
	if (!sitealarm && !encounter[0].exists)
	{
		switch (LocationsPool::getInstance().getLocationType(cursite))
		{
		default:
		case SITE_CORPORATE_HEADQUARTERS:
		case SITE_CORPORATE_HOUSE:
		case SITE_BUSINESS_ARMSDEALER:
		case SITE_BUSINESS_BANK:
		case SITE_INDUSTRY_NUCLEAR:
			makecreature(encounter[0], CREATURE_MERC);
			makecreature(encounter[1], CREATURE_MERC);
			break;
		case SITE_GOVERNMENT_POLICESTATION:
		case SITE_GOVERNMENT_COURTHOUSE:
		case SITE_OUTDOOR_PUBLICPARK:
			makecreature(encounter[0], CREATURE_COP);
			makecreature(encounter[1], CREATURE_COP);
			break;
		case SITE_GOVERNMENT_PRISON:
			makecreature(encounter[0], CREATURE_PRISONGUARD);
			makecreature(encounter[1], CREATURE_PRISONGUARD);
			makecreature(encounter[2], CREATURE_GUARDDOG);
			break;
		case SITE_GOVERNMENT_WHITE_HOUSE:
			makecreature(encounter[0], CREATURE_SECRET_SERVICE);
			makecreature(encounter[1], CREATURE_SECRET_SERVICE);
			makecreature(encounter[2], CREATURE_SECRET_SERVICE);
			makecreature(encounter[3], CREATURE_SECRET_SERVICE);
			break;
		case SITE_GOVERNMENT_INTELLIGENCEHQ:
			makecreature(encounter[0], CREATURE_AGENT);
			makecreature(encounter[1], CREATURE_AGENT);
			makecreature(encounter[2], CREATURE_GUARDDOG);
			break;
		case SITE_GOVERNMENT_ARMYBASE:
			makecreature(encounter[0], CREATURE_MILITARYPOLICE);
			makecreature(encounter[1], CREATURE_MILITARYPOLICE);
			break;
		case SITE_BUSINESS_BARANDGRILL:
		case SITE_RESIDENTIAL_BOMBSHELTER:
		case SITE_OUTDOOR_BUNKER:
			if (LocationsPool::getInstance().getRentingType(cursite) == RENTING_CCS)
			{
				makecreature(encounter[0], CREATURE_CCS_VIGILANTE);
				makecreature(encounter[1], CREATURE_CCS_VIGILANTE);
			}
		}
	}
}
void special_security(bool metaldetect)
{
	char autoadmit = 0;
	char sleepername[80];
	emptyEncounter();
	spawn_security();
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (pool[p]->base == cursite)
		{
			autoadmit = 1;
			if (pool[p]->type == encounter[0].type)
			{
				autoadmit = 2;
				strcpy(sleepername, pool[p]->name);
				strcpy(encounter[0].name, sleepername);
				encounter[0].align = 1;
				encounter[0].cantbluff = 1;
				break;
			}
		}
	}
	//clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(16, 1);
	if (sitealarm)
	{
		addstrAlt("The security checkpoint is abandoned.", gamelog);
		gamelog.newline();
		levelmap[locx][locy][locz].special = SPECIAL_NONE;
		return;
	}
	else if (autoadmit)
	{
		addstrAlt("The squad flashes ID badges.", gamelog);
		metaldetect = false;
		gamelog.newline();
		levelmap[locx][locy][locz].special = SPECIAL_SECURITY_SECONDVISIT;
	}
	else
	{
		if (metaldetect) addstrAlt("The squad steps into a metal detector.", gamelog);
		else addstrAlt("This door is guarded.", gamelog);
		gamelog.newline();
		levelmap[locx][locy][locz].special = SPECIAL_SECURITY_SECONDVISIT;
	}
	printencounter();
	getkeyAlt();
	char rejected = NOT_REJECTED;
	// Size up the squad for entry
	for (int s = 0; s<6; s++)
	{
		if (activesquad->squad[s])
		{
			// Wrong clothes? Gone
			if (activesquad->squad[s]->is_naked() && activesquad->squad[s]->animalgloss != ANIMALGLOSS_ANIMAL)
				if (rejected>REJECTED_NUDE)rejected = REJECTED_NUDE;
			if (autoadmit<1 && !hasdisguise(*activesquad->squad[s]))
				if (rejected>REJECTED_DRESSCODE)rejected = REJECTED_DRESSCODE;
			// Busted, cheap, bloody clothes? Gone
			if (autoadmit<2 && activesquad->squad[s]->get_armor().is_bloody())
				if (rejected>REJECTED_BLOODYCLOTHES)rejected = REJECTED_BLOODYCLOTHES;
			if (autoadmit<2 && activesquad->squad[s]->get_armor().is_damaged())
				if (rejected>REJECTED_DAMAGEDCLOTHES)rejected = REJECTED_DAMAGEDCLOTHES;
			if (autoadmit<2 && activesquad->squad[s]->get_armor().get_quality() != 1)
				if (rejected>REJECTED_SECONDRATECLOTHES)rejected = REJECTED_SECONDRATECLOTHES;
			// Suspicious weapons? Gone
			if (autoadmit < 2 && weaponcheck(*activesquad->squad[s], metaldetect)>0)
				if (rejected > REJECTED_WEAPONS)rejected = REJECTED_WEAPONS;
			// Fail a tough disguise check? Gone
			if (autoadmit<1 && disguisesite(sitetype) && !(activesquad->squad[s]->skill_check(SKILL_DISGUISE, DIFFICULTY_CHALLENGING)))
				if (rejected>REJECTED_SMELLFUNNY)rejected = REJECTED_SMELLFUNNY;
			// Underage? Gone
			if (autoadmit < 1 && activesquad->squad[s]->age<18)
				if (rejected>REJECTED_UNDERAGE)rejected = REJECTED_UNDERAGE;
		}
	}   
	moveAlt(17, 1);

	if (caseRejectionReasons.count(rejected)) {
		set_color_easy(RED_ON_BLACK_BRIGHT);
		addstrAlt(pickrandom(caseRejectionReasons[rejected]), gamelog);
	}
	else
	switch (rejected)
	{
	case REJECTED_NUDE:
		set_color_easy(RED_ON_BLACK_BRIGHT);
		if (autoadmit) addstrAlt("\"Jesus! Put some clothes on!\"", gamelog);
		else addstrAlt(pickrandom(caseREJECTED_NUDE), gamelog);
		gamelog.newline();
		break;
	case REJECTED_WEAPONS:
		set_color_easy(RED_ON_BLACK_BRIGHT);
		if (metaldetect)
		{
			addstrAlt("-BEEEP- -BEEEP- -BEEEP-", gamelog);
			sitealarm = 1;
		}
		else addstrAlt(pickrandom(caseREJECTED_WEAPONS), gamelog);
		gamelog.newline();
		break;
	case NOT_REJECTED:
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		addstrAlt(pickrandom(caseNOT_REJECTED), gamelog);
		gamelog.newline();
		break;
	}
	getkeyAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	for (int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++)
		{
			if (levelmap[locx + dx][locy + dy][locz].flag & SITEBLOCK_DOOR)
			{
				if (rejected < NOT_REJECTED)
				{
					levelmap[locx + dx][locy + dy][locz].flag |= SITEBLOCK_LOCKED;
					levelmap[locx + dx][locy + dy][locz].flag |= SITEBLOCK_CLOCK;
				}
				else levelmap[locx + dx][locy + dy][locz].flag &= ~SITEBLOCK_DOOR;
			}
		}
	encounter[0].cantbluff = 1;
}
void special_security_checkpoint()
{
	special_security(false);
}
void special_security_metaldetectors()
{
	special_security(true);
}
void special_security_secondvisit()
{
	spawn_security();
}
void special_bank_vault()
{
	clearmessagearea();
	mvaddstrAlt(16,  1, "The vault door has three layers: A combo lock, ", gamelog);
	mvaddstrAlt(17,  1, "an electronic lock, and a biometric lock.", gamelog);
	gamelog.newline();
	getkeyAlt();
	clearmessagearea();
	mvaddstrAlt(16,  1, "You will need a security expert, a computer ", gamelog);
	mvaddstrAlt(17,  1, "expert, and one of the bank managers.", gamelog);
	gamelog.newline();
	getkeyAlt();
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (pool[p]->type == CREATURE_BANK_MANAGER &&
			pool[p]->flag & CREATUREFLAG_SLEEPER &&
			pool[p]->base == cursite)
		{
			clearmessagearea();
			mvaddstrAlt(16,  1, string_sleeper, gamelog);
			addstrAlt(pool[p]->name, gamelog);
			addstrAlt(" can handle the biometrics, ", gamelog);
			mvaddstrAlt(17,  1, "but you'll still have to crack the other locks.", gamelog);
			gamelog.newline();
			getkeyAlt();
			break;
		}
	}
	while (true)
	{
		clearmessagearea();
		mvaddstrAlt(16,  1, "Open the bank vault? (Yes or No)");
		int c = getkeyAlt();
		if (c == 'y')
		{
			char actual;
			clearmessagearea();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(16,  1, "First is the combo lock that will have ", gamelog);
			mvaddstrAlt(17,  1, "be cracked by a security expert.", gamelog);
			gamelog.newline();
			getkeyAlt();
			if (!unlock(UNLOCK_VAULT, actual))
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, "The squad can only dream of the money ", gamelog);
				mvaddstrAlt(17,  1, "on the other side of this door...", gamelog);
				gamelog.newline();
				getkeyAlt();
				levelmap[locx][locy][locz].special = -1;
			}
			else
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, "Next is the electronic lock that will have ", gamelog);
				mvaddstrAlt(17,  1, "be bypassed by a computer expert.", gamelog);
				gamelog.newline();
				getkeyAlt();
				if (!hack(HACK_VAULT, actual))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16,  1, "The money was so close the squad could taste it!", gamelog);
					gamelog.newline();
					getkeyAlt();
					levelmap[locx][locy][locz].special = -1;
				}
				else
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16,  1, "Last is the biometric lock that keyed only ", gamelog);
					mvaddstrAlt(17,  1, "to the bank's managers.", gamelog);
					gamelog.newline();
					getkeyAlt();
					Creature *manager = 0;
					bool canbreakin = false;
					for (int s = 0; s < 6; s++)
					{
						Creature *c = activesquad->squad[s];
						if (c)
						{
							if (c->type == CREATURE_BANK_MANAGER)
							{
								manager = c;
								if (c->joindays < 30 && !(c->flag & CREATUREFLAG_KIDNAPPED))
								{
									clearmessagearea();
									set_color_easy(WHITE_ON_BLACK_BRIGHT);
									mvaddstrAlt(16,  1, c->name, gamelog);
									addstrAlt(" opens the vault.", gamelog);
									gamelog.newline();
									getkeyAlt();
									canbreakin = true;
									break;
								}
							}
							if (c->prisoner && c->prisoner->type == CREATURE_BANK_MANAGER)
							{
								clearmessagearea();
								set_color_easy(WHITE_ON_BLACK_BRIGHT);
								mvaddstrAlt(16,  1, "The hostage is forced to open the vault.", gamelog);
								gamelog.newline();
								getkeyAlt();
								canbreakin = true;
								break;
							}
						}
					}
					if (!canbreakin)
					{
						for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
						{
							if (pool[p]->base == cursite && pool[p]->type == CREATURE_BANK_MANAGER)
							{
								clearmessagearea();
								set_color_easy(WHITE_ON_BLACK_BRIGHT);
								mvaddstrAlt(16,  1, string_sleeper, gamelog);
								addstrAlt(pool[p]->name, gamelog);
								addstrAlt(" opens the vault, ", gamelog);
								mvaddstrAlt(17,  1, "and will join the active LCS to avoid arrest.", gamelog);
								gamelog.newline();
								getkeyAlt();
								canbreakin = true;
								pool[p]->location = pool[p]->base = activesquad->squad[0]->base;
								pool[p]->flag &= ~CREATUREFLAG_SLEEPER;
								pool[p]->activity.type = ACTIVITY_NONE;
								pool[p]->crimes_suspected[LAWFLAG_BANKROBBERY]++;
								break;
							}
						}
					}
					if (canbreakin)
					{
						criminalizeparty(LAWFLAG_BANKROBBERY);
						sitecrime += 20;
						sitestory->crime.push_back(CRIME_BANKVAULTROBBERY);
						levelmap[locx + 1][locy][locz].flag &= ~SITEBLOCK_DOOR;
						levelmap[locx - 1][locy][locz].flag &= ~SITEBLOCK_DOOR;
						levelmap[locx][locy + 1][locz].flag &= ~SITEBLOCK_DOOR;
						levelmap[locx][locy - 1][locz].flag &= ~SITEBLOCK_DOOR;
						levelmap[locx][locy][locz].special = -1;
					}
					else
					{
						if (manager)
						{
							clearmessagearea();
							set_color_easy(WHITE_ON_BLACK_BRIGHT);
							mvaddstrAlt(16,  1, manager->name, gamelog);
							addstrAlt(" is no longer recognized.", gamelog);
							gamelog.newline();
							getkeyAlt();
						}
						else
						{
							clearmessagearea();
							set_color_easy(WHITE_ON_BLACK_BRIGHT);
							mvaddstrAlt(16,  1, "The squad has nobody that can do the job.", gamelog);
							gamelog.newline();
							getkeyAlt();
						}
					}
				}
			}
			if (actual)
			{
				alienationcheck(0);
				noticecheck(-1);
			}
			return;
		}
		else if (c == 'n')return;
	}
}
void special_bank_teller()
{
	if (sitealarm || sitealienate ||
		LocationsPool::getInstance().isThereASiegeHere(cursite))
	{
		clearmessagearea(false);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "The teller window is empty.", gamelog);
		gamelog.newline();
		levelmap[locx][locy][locz].special = -1;
		getkeyAlt();
	}
	else
	{
		clearmessagearea(false);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "A bank teller is available.", gamelog);
		gamelog.newline();
		levelmap[locx][locy][locz].special = -1;
		getkeyAlt();
		emptyEncounter();
		makecreature(encounter[0], CREATURE_BANK_TELLER);
	}
}
void special_bank_money()
{
	static int swat_counter = 0;
	clearmessagearea(false);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(16,  1, "The squad loads bricks of cash into a duffel bag.", gamelog);
	gamelog.newline();
	levelmap[locx][locy][locz].special = -1;
	activesquad->loot.push_back(new Money(20000));
	sitecrime += 20;
	if (postalarmtimer <= 80) swat_counter = 0;
	if (!sitealarm && sitealarmtimer != 0) sitealarmtimer = 0;
	else if (!sitealarm && !LCSrandom(2)) sitealarm = 1;
	else if (sitealarm && postalarmtimer <= 60) postalarmtimer += 20;
	else if (sitealarm && postalarmtimer <= 80 && LCSrandom(2)) postalarmtimer = 81;
	else if (sitealarm && postalarmtimer > 80 && LCSrandom(2) && swat_counter < 2)
	{
		getkeyAlt();
		if (swat_counter > 0)
			mvaddstrAlt(17, 1, "Another SWAT team moves in!!", gamelog);
		else
			mvaddstrAlt(17, 1, "A SWAT team storms the vault!!", gamelog);
		gamelog.newline();
		swat_counter++;
		int swatnum = 9;
		fillEncounter(CREATURE_SWAT, swatnum);
	}
	getkeyAlt();
}
void special_oval_office()
{
	// Clear entire Oval Office area
	for (int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++)
		{
			if (levelmap[locx + dx][locy + dy][locz].special == SPECIAL_OVAL_OFFICE_NW ||
				levelmap[locx + dx][locy + dy][locz].special == SPECIAL_OVAL_OFFICE_NE ||
				levelmap[locx + dx][locy + dy][locz].special == SPECIAL_OVAL_OFFICE_SW ||
				levelmap[locx + dx][locy + dy][locz].special == SPECIAL_OVAL_OFFICE_SE)
			{
				levelmap[locx + dx][locy + dy][locz].special = -1;
			}
		}
	if (sitealarm)
	{
		emptyEncounter();
		clearmessagearea(false);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "The President isn't here... ", gamelog);
		printsitemap(locx, locy, locz);
		getkeyAlt();
		mvaddstrAlt(17,  1, "Secret Service agents ambush the squad!", gamelog);
		gamelog.newline();
		for (int e = 0; e < 6; e++)makecreature(encounter[e], CREATURE_SECRET_SERVICE);
		printencounter();
		getkeyAlt();
		enemyattack();
		creatureadvance();
	}
	else
	{
		emptyEncounter();
		clearmessagearea(false);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "The President is in the Oval Office.", gamelog);
		gamelog.newline();
		printsitemap(locx, locy, locz);
		for (int e = 0; e < 2; e++)makecreature(encounter[e], CREATURE_SECRET_SERVICE);
		encounter[2] = uniqueCreatures.President();
		printencounter();
		getkeyAlt();
	}
}
void special_ccs_boss()
{
	if (sitealarm || sitealienate ||
		LocationsPool::getInstance().isThereASiegeHere(cursite))
	{
		clearmessagearea(false);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "The CCS leader is ready for you!", gamelog);
		gamelog.newline();
		levelmap[locx][locy][locz].special = -1;
		getkeyAlt();
		emptyEncounter();
		makecreature(encounter[0], CREATURE_CCS_ARCHCONSERVATIVE);
		makecreature(encounter[1], CREATURE_CCS_VIGILANTE);
		makecreature(encounter[2], CREATURE_CCS_VIGILANTE);
		makecreature(encounter[3], CREATURE_CCS_VIGILANTE);
		makecreature(encounter[4], CREATURE_CCS_VIGILANTE);
		makecreature(encounter[5], CREATURE_CCS_VIGILANTE);
	}
	else
	{
		clearmessagearea(false);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "The CCS leader is here.", gamelog);
		gamelog.newline();
		levelmap[locx][locy][locz].special = -1;
		getkeyAlt();
		emptyEncounter();
		makecreature(encounter[0], CREATURE_CCS_ARCHCONSERVATIVE);
	}
}
