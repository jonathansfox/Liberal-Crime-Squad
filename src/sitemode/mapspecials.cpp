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

#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
extern vector<Creature *> pool;
extern Log gamelog;
extern vector<Location *> location;
extern vector<LootType *> loottype;
extern short postalarmtimer;
extern short mode;
extern char endgamestate;
extern short sitetype;
extern string string_sleeper;
extern string singleDot;
enum bouncer_reject_reason
{
	REJECTED_CCS,
	REJECTED_NUDE,
	REJECTED_WEAPONS,
	REJECTED_UNDERAGE,
	REJECTED_FEMALEISH,
	REJECTED_FEMALE,
	REJECTED_BLOODYCLOTHES,
	REJECTED_DAMAGEDCLOTHES,
	REJECTED_CROSSDRESSING,
	REJECTED_GUESTLIST,
	REJECTED_DRESSCODE,
	REJECTED_SECONDRATECLOTHES,
	REJECTED_SMELLFUNNY,
	NOT_REJECTED
};
char run_broadcast(bool tv_broadcast);
void special_bouncer_greet_squad()
{
	// add a bouncer if there isn't one in the first slot
	if (!sitealarm && location[cursite]->renting != RENTING_PERMANENT)
	{
		if (location[cursite]->renting == RENTING_CCS)
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
 vector<string> rejectedByCCS;
 vector<string> rejectedBecauseNude;
 vector<string> rejectedBecauseUnderage;
 vector<string> rejectedBecauseFemale;
 vector<string> rejectedBecauseFemaleish;
 vector<string> rejectedBecauseDresscode;
 vector<string> rejectedBecauseSmellFunny;
 vector<string> rejectedBecauseBloodyClothes;
 vector<string> rejectedBecauseDamagedClothes;
 vector<string> rejectedBecauseSecondRateClothes;
 vector<string> rejectedBecauseWeapons;
 vector<string> rejectedBecauseGuestList;
 vector<string> notRejected;
 vector<string> randomCrime;
 // the vector<string> 'caseREJECTED' and 'rejected' are similar but not identicle.
 // TODO the precise differences should be made more apparant
 vector<string> caseREJECTED_NUDE;
 vector<string> caseREJECTED_UNDERAGE;
 vector<string> caseREJECTED_DRESSCODE;
 vector<string> caseREJECTED_SMELLFUNNY;
 vector<string> caseREJECTED_BLOODYCLOTHES;
 vector<string> caseREJECTED_DAMAGEDCLOTHES;
 vector<string> caseREJECTED_SECONDRATECLOTHES;
 vector<string> caseREJECTED_WEAPONS;
 vector<string> caseNOT_REJECTED;
void special_bouncer_assess_squad()
{
	if (location[cursite]->renting == RENTING_PERMANENT) return;
	bool autoadmit = 0;
	char sleepername[80];
	emptyEncounter();
	special_bouncer_greet_squad();
	for (int p = 0; p < len(pool); p++)
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
	set_color(COLOR_WHITE, COLOR_BLACK, 1);
	moveSixteenOne();
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
		if (location[cursite]->renting == RENTING_CCS)
			addstrAlt("The Conservative scum block the door.", gamelog);
		else
			addstrAlt("The bouncer assesses your squad.", gamelog);
		gamelog.newline();
		levelmap[locx][locy][locz].special = SPECIAL_CLUB_BOUNCER_SECONDVISIT;
	}
	printencounter();
	getkey();
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
				if (sitetype == SITE_BUSINESS_CIGARBAR && location[cursite]->highsecurity)
					if (rejected > REJECTED_GUESTLIST)rejected = REJECTED_GUESTLIST;
				if (location[cursite]->renting == RENTING_CCS && location[cursite]->type != SITE_BUSINESS_BARANDGRILL)
					rejected = REJECTED_CCS;
			}
		}
		moveSeventeenOne();
		switch (rejected)
		{
		case REJECTED_CCS:
			set_color(COLOR_RED, COLOR_BLACK, 1);
			addstrAlt(pickrandom(rejectedByCCS), gamelog);
			break;
		case REJECTED_NUDE:
			set_color(COLOR_RED, COLOR_BLACK, 1);
			addstrAlt(pickrandom(rejectedBecauseNude), gamelog);
			break;
		case REJECTED_UNDERAGE:
			set_color(COLOR_RED, COLOR_BLACK, 1);
			addstrAlt(pickrandom(rejectedBecauseUnderage), gamelog);
			break;
		case REJECTED_FEMALE:
			set_color(COLOR_RED, COLOR_BLACK, 1);
			addstrAlt(pickrandom(rejectedBecauseFemale), gamelog);
			break;
		case REJECTED_FEMALEISH:
			set_color(COLOR_RED, COLOR_BLACK, 1);
			addstrAlt(pickrandom(rejectedBecauseFemaleish), gamelog);
			break;
		case REJECTED_DRESSCODE:
			set_color(COLOR_RED, COLOR_BLACK, 1);
			addstrAlt(pickrandom(rejectedBecauseDresscode), gamelog);
			break;
		case REJECTED_SMELLFUNNY:
			set_color(COLOR_RED, COLOR_BLACK, 1);
			if (!LCSrandom(len(rejectedBecauseSmellFunny) - 1)) {
				if (lawList[LAW_FREESPEECH] == -2)addstrAlt("\"Get the [heck] out of here.\"", gamelog);
				else if (lawList[LAW_FREESPEECH] == 2)addstrAlt("\"Get the fuck out of here.\"", gamelog);
				else addstrAlt("\"Get the hell out of here.\"", gamelog);
			}
			else {
				addstrAlt(pickrandom(rejectedBecauseSmellFunny), gamelog);
			}
			break;
		case REJECTED_BLOODYCLOTHES:
			set_color(COLOR_RED, COLOR_BLACK, 1);
			addstrAlt(pickrandom(rejectedBecauseBloodyClothes), gamelog);
			break;
		case REJECTED_DAMAGEDCLOTHES:
			set_color(COLOR_RED, COLOR_BLACK, 1);
			addstrAlt(pickrandom(rejectedBecauseBloodyClothes), gamelog);
			break;
		case REJECTED_SECONDRATECLOTHES:
			set_color(COLOR_RED, COLOR_BLACK, 1);
			addstrAlt(pickrandom(rejectedBecauseSecondRateClothes), gamelog);
			break;
		case REJECTED_WEAPONS:
			set_color(COLOR_RED, COLOR_BLACK, 1);
			addstrAlt(pickrandom(rejectedBecauseWeapons), gamelog);
			break;
		case REJECTED_GUESTLIST:
			set_color(COLOR_RED, COLOR_BLACK, 1);
			addstrAlt(pickrandom(rejectedBecauseGuestList), gamelog);
			break;
		case NOT_REJECTED:
			set_color(COLOR_GREEN, COLOR_BLACK, 1);
			addstrAlt(pickrandom(notRejected), gamelog);
			break;
		}
		gamelog.newline();
		getkey();
	}
	else encounter[0].exists = 0;
	set_color(COLOR_WHITE, COLOR_BLACK, 1);
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
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("You see fluffy white rabbits in a locked cage.", gamelog);
		gamelog.newline();
		moveSeventeenOne();
		addstrAlt("Free them? (Yes or No)");
		int c = getkey();
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
	set_color(COLOR_WHITE, COLOR_BLACK, 1);
	switch (sign) //TODO: Log these?
	{
	case SPECIAL_SIGN_ONE:
		switch (location[cursite]->type)
		{
		default:
			moveSixteenOne();
			addstrAlt("\"The best way not to fail is to succeed.\"");
			break;
		case SITE_INDUSTRY_NUCLEAR:
			moveSixteenOne();
			addstrAlt("Welcome to the NPP Nuclear Plant. Please enjoy");
			moveSeventeenOne();
			addstrAlt("the museum displays in the gift shop.");
			break;
		case SITE_RESIDENTIAL_TENEMENT:
		case SITE_RESIDENTIAL_APARTMENT:
		case SITE_RESIDENTIAL_APARTMENT_UPSCALE:
			moveSixteenOne();
			addstrAlt("The landlord's office is the first door");
			moveSeventeenOne();
			addstrAlt("on the left.");
			break;
		}
		break;
	case SPECIAL_SIGN_TWO:
		switch (location[cursite]->type)
		{
		default:
			moveSixteenOne();
			addstrAlt("\"Great work is done by people who do great work.\"");
			break;
		}
		break;
	case SPECIAL_SIGN_THREE:
		switch (location[cursite]->type)
		{
		default:
			moveSixteenOne();
			addstrAlt("Employees Only");
			break;
		}
		break;
	}
	getkey();
}
void special_nuclear_onoff()
{
	while (true)
	{
		clearmessagearea();
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		if (lawList[LAW_NUCLEARPOWER] == 2)
		{
			moveSixteenOne();
			addstrAlt("You see the nuclear waste center control room.", gamelog);
			gamelog.newline();
			moveSeventeenOne();
			addstrAlt("Attempt to release nuclear waste? (Yes or No)");
		}
		else
		{
			moveSixteenOne();
			addstrAlt("You see the nuclear power plant control room.", gamelog);
			gamelog.newline();
			moveSeventeenOne();
			addstrAlt("Mess with the reactor settings? (Yes or No)");
		}
		int c = getkey();
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
				set_color(COLOR_WHITE, COLOR_BLACK, 1);
				moveSixteenOne();
				addstrAlt(maxs->name, gamelog);
				addstrAlt(" presses the big red button!", gamelog);
				gamelog.newline();
				getkey();
				moveSeventeenOne();
				addstrAlt(singleDot, gamelog);
				getkey();
				addstrAlt(singleDot, gamelog);
				getkey();
				addstrAlt(singleDot, gamelog);
				getkey();
				if (lawList[LAW_NUCLEARPOWER] == 2)
				{
					moveSeventeenOne();
					addstrAlt("The nuclear waste gets released into the state's water supply!", gamelog);
					gamelog.newline();
					change_public_opinion(VIEW_NUCLEARPOWER, 15, 0, 95);
					change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, -50, 0, 0);
					getkey();
					juiceparty(40, 1000); // Instant juice!
					sitecrime += 25; //Shutdown Site
					sitestory->crime.push_back(CRIME_SHUTDOWNREACTOR);
				}
				else
				{
					moveSixteenOne();
					addstrAlt("A deafening alarm sounds!", gamelog);
					gamelog.newline();
					addstrAlt("                "); // Remove remaining part of previous text.
					moveSeventeenOne();
					addstrAlt("The reactor is overheating!", gamelog);
					gamelog.newline();
					change_public_opinion(VIEW_NUCLEARPOWER, 15, 0, 95);
					getkey();
					juiceparty(100, 1000); // Instant juice!
					sitecrime += 50; //Shutdown Site
					sitestory->crime.push_back(CRIME_SHUTDOWNREACTOR);
				}
			}
			else
			{
				set_color(COLOR_WHITE, COLOR_BLACK, 1);
				moveSixteenOne();
				addstrAlt("After some failed attempts, and a very loud alarm, ", gamelog);
				moveSeventeenOne();
				addstrAlt("the Squad resigns to just leaving a threatening note.", gamelog);
				gamelog.newline();
				getkey();
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
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("You see horrible misshapen creatures in a sealed cage.", gamelog);
		gamelog.newline();
		moveSeventeenOne();
		addstrAlt("Free them? (Yes or No)");
		int c = getkey();
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
					set_color(COLOR_WHITE, COLOR_BLACK, 1);
					moveSixteenOne();
					addstrAlt("Uh, maybe that idea was Conservative in retrospect...", gamelog);
					gamelog.newline();
					int numleft = LCSrandom(6) + 1;
					fillEncounter(CREATURE_GENETIC, numleft);
					if (mode == GAMEMODE_CHASECAR ||
						mode == GAMEMODE_CHASEFOOT)printchaseencounter();
					else printencounter();
					getkey();
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
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("You see prisoners in the detention room.", gamelog);
		gamelog.newline();
		moveSeventeenOne();
		addstrAlt("Free them? (Yes or No)");
		int c = getkey();
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
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("You see prisoners in the Courthouse jail.", gamelog);
		gamelog.newline();
		moveSeventeenOne();
		addstrAlt("Free them? (Yes or No)");
		int c = getkey();
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
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("It appears as if this room has been ", gamelog);
		moveSeventeenOne();
		addstrAlt("vacated in a hurry.", gamelog);
		gamelog.newline();
		getkey();
		return;
	}
	while (true)
	{
		clearmessagearea();
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("You've found a Jury in deliberations!", gamelog);
		gamelog.newline();
		moveSeventeenOne();
		addstrAlt("Attempt to influence them? (Yes or No)");
		int c = getkey();
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
					set_color(COLOR_WHITE, COLOR_BLACK, 1);
					moveSixteenOne();
					addstrAlt(activesquad->squad[p]->name, gamelog);
					addstrAlt(" works the room like in Twelve Angry Men, and the jury ", gamelog);
					moveSeventeenOne();
					addstrAlt("concludes that ", gamelog);//XXX: This is very awkward grammar.
					addstrAlt(pickrandom(randomCrime), gamelog);
					addstrAlt(" wasn't really wrong here.", gamelog);
					gamelog.newline();
					getkey();
					alienationcheck(0);
					noticecheck(-1);
					//INSTANT JUICE BONUS
					addjuice(*(activesquad->squad[p]), 25, 200);
				}
				else
				{
					clearmessagearea();
					set_color(COLOR_WHITE, COLOR_BLACK, 1);
					moveSixteenOne();
					addstrAlt(activesquad->squad[p]->name, gamelog);
					addstrAlt(" wasn't quite convincing...", gamelog);
					gamelog.newline();
					getkey();
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
void special_prison_control(short prison_control_type)
{
	while (true)
	{
		clearmessagearea();
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("You've found the ", gamelog);
		if (prison_control_type == SPECIAL_PRISON_CONTROL_LOW)
			addstrAlt("low security ", gamelog);
		else if (prison_control_type == SPECIAL_PRISON_CONTROL_MEDIUM)
			addstrAlt("medium security ", gamelog);
		else if (prison_control_type == SPECIAL_PRISON_CONTROL_HIGH)
			addstrAlt("high security ", gamelog);
		addstrAlt("prison control room.", gamelog);
		gamelog.newline();
		moveSeventeenOne();
		addstrAlt("Free the prisoners? (Yes or No)");
		int c = getkey();
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
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("The security alert has caused the ", gamelog);
		moveSeventeenOne();
		addstrAlt("computer to shut down.", gamelog);
		gamelog.newline();
		getkey();
		return;
	}
	while (true)
	{
		clearmessagearea();
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("You've found the Intelligence Supercomputer.", gamelog);
		gamelog.newline();
		moveSeventeenOne();
		addstrAlt("Hack it? (Yes or No)");
		int c = getkey();
		if (c == 'y')
		{
			char actual;
			if (hack(HACK_SUPERCOMPUTER, actual))
			{
				clearmessagearea();
				//char *loot;
				set_color(COLOR_WHITE, COLOR_BLACK, 1);
				moveSixteenOne();
				addstrAlt("The Squad obtains sensitive information", gamelog);
				if (endgamestate >= ENDGAME_CCS_APPEARANCE && endgamestate < ENDGAME_CCS_DEFEATED && ccsexposure < CCSEXPOSURE_LCSGOTDATA)
				{
					addstrAlt(",", gamelog);
					moveSeventeenOne();
					addstrAlt("including a list of government backers of the CCS.", gamelog);
					Item *it = new Loot(*loottype[getloottype(tag_LOOT_CCS_BACKERLIST)]);
					activesquad->loot.push_back(it);
					ccsexposure = CCSEXPOSURE_LCSGOTDATA;
				}
				else
				{
					addstrAlt(singleDot, gamelog);
				}
				gamelog.newline();
				juiceparty(50, 1000);
				Item *it = new Loot(*loottype[getloottype(tag_LOOT_INTHQDISK)]);
				activesquad->loot.push_back(it);
				getkey();
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
	set_color(COLOR_WHITE, COLOR_BLACK, 1);
	moveSixteenOne();
	addstrAlt("The squad sprays Liberal Graffiti!", gamelog);
	gamelog.newline();
	if (!sitestory->claimed)
		sitestory->claimed = 1;
	getkey();
	int time = 20 + LCSrandom(10);
	if (time < 1)time = 1;
	if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
	alienationcheck(0);
	noticecheck(-1, DIFFICULTY_HARD);
	levelmap[locx][locy][locz].flag |= SITEBLOCK_GRAFFITI;
	levelmap[locx][locy][locz].flag &= ~(SITEBLOCK_GRAFFITI_CCS | SITEBLOCK_GRAFFITI_OTHER);
	if (!location[cursite]->highsecurity)
	{
		// Erase any previous semi-permanent graffiti here
		for (int i = 0; i < len(location[cursite]->changes); i++)
		{
			if ((location[cursite]->changes[i].x == locx) &&
				(location[cursite]->changes[i].y == locy) &&
				(location[cursite]->changes[i].z == locz) &&
				((location[cursite]->changes[i].flag == SITEBLOCK_GRAFFITI) ||
					(location[cursite]->changes[i].flag == SITEBLOCK_GRAFFITI_CCS) ||
					(location[cursite]->changes[i].flag == SITEBLOCK_GRAFFITI_OTHER)))
			{
				location[cursite]->changes.erase(location[cursite]->changes.begin() + i);
				break;
			}
		}
		// Add new semi-permanent graffiti
		struct sitechangest change(locx, locy, locz, SITEBLOCK_GRAFFITI);
		location[cursite]->changes.push_back(change);
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
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("You see some textile equipment.", gamelog);
		gamelog.newline();
		moveSeventeenOne();
		addstrAlt("Destroy it? (Yes or No)");
		int c = getkey();
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
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("You see some industrial equipment.", gamelog);
		gamelog.newline();
		moveSeventeenOne();
		addstrAlt("Destroy it? (Yes or No)");
		int c = getkey();
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
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("You've found a safe.", gamelog);
		gamelog.newline();
		moveSeventeenOne();
		addstrAlt("Open it? (Yes or No)");
		int c = getkey();
		if (c == 'y')
		{
			char actual;
			if (unlock(UNLOCK_SAFE, actual))
			{
				bool empty = true;
				Item *it;
				if (deagle == false)
				{
					clearmessagearea();
					set_color(COLOR_WHITE, COLOR_BLACK, 1);
					moveSixteenOne();
					addstrAlt("The squad has found a Desert Eagle.", gamelog);
					gamelog.newline();
					getkey();
					Weapon* de = new Weapon(*weapontype[getweapontype(tag_WEAPON_DESERT_EAGLE)]);
					Clip r(*cliptype[getcliptype(tag_CLIP_50AE)]);
					de->reload(r);
					activesquad->loot.push_back(de);
					it = new Clip(*cliptype[getcliptype(tag_CLIP_50AE)], 9);
					activesquad->loot.push_back(it);
					deagle = true;
					empty = false;
				}
				if (LCSrandom(2))
				{
					clearmessagearea();
					set_color(COLOR_WHITE, COLOR_BLACK, 1);
					moveSixteenOne();
					addstrAlt("This guy sure had a lot of $100 bills.", gamelog);
					gamelog.newline();
					getkey();
					it = new Money(1000 * (1 + LCSrandom(10)));
					activesquad->loot.push_back(it);
					empty = false;
				}
				if (LCSrandom(2))
				{
					clearmessagearea();
					set_color(COLOR_WHITE, COLOR_BLACK, 1);
					moveSixteenOne();
					addstrAlt("The squad Liberates some expensive jewelery.", gamelog);
					gamelog.newline();
					getkey();
					it = new Loot(*loottype[getloottype(tag_LOOT_EXPENSIVEJEWELERY)], 3);
					activesquad->loot.push_back(it);
					empty = false;
				}
				if (!LCSrandom(3))
				{
					clearmessagearea();
					set_color(COLOR_WHITE, COLOR_BLACK, 1);
					moveSixteenOne();
					addstrAlt("There are some... very compromising photos here.", gamelog);
					gamelog.newline();
					getkey();
					it = new Loot(*loottype[getloottype(tag_LOOT_CEOPHOTOS)]);
					activesquad->loot.push_back(it);
					empty = false;
				}
				if (!LCSrandom(3))
				{
					clearmessagearea();
					set_color(COLOR_WHITE, COLOR_BLACK, 1);
					moveSixteenOne();
					addstrAlt("There are some drugs here.", gamelog);
					gamelog.newline();
					getkey();
					empty = false;
				}
				if (!LCSrandom(3))
				{
					clearmessagearea();
					set_color(COLOR_WHITE, COLOR_BLACK, 1);
					moveSixteenOne();
					addstrAlt("Wow, get a load of these love letters. ", gamelog);
					moveSeventeenOne();
					addstrAlt("The squad will take those.");
					gamelog.newline();
					getkey();
					it = new Loot(*loottype[getloottype(tag_LOOT_CEOLOVELETTERS)]);
					activesquad->loot.push_back(it);
					empty = false;
				}
				if (!LCSrandom(3))
				{
					clearmessagearea();
					set_color(COLOR_WHITE, COLOR_BLACK, 1);
					moveSixteenOne();
					addstrAlt("These documents show serious tax evasion.", gamelog);
					gamelog.newline();
					getkey();
					it = new Loot(*loottype[getloottype(tag_LOOT_CEOTAXPAPERS)]);
					activesquad->loot.push_back(it);
					empty = false;
				}
				if (empty)
				{
					clearmessagearea();
					set_color(COLOR_WHITE, COLOR_BLACK, 1);
					moveSixteenOne();
					addstrAlt("Wow, it's empty.  That sucks.", gamelog);
					gamelog.newline();
					getkey();
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
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("You've found the armory.", gamelog);
		gamelog.newline();
		moveSeventeenOne();
		addstrAlt("Break in? (Yes or No)");
		int c = getkey();
		if (c == 'y')
		{
			clearmessagearea();
			sitealarm = 1;
			moveSixteenOne();
			set_color(COLOR_RED, COLOR_BLACK, 1);
			addstrAlt("Alarms go off!", gamelog);
			gamelog.newline();
			getkey();
			bool empty = true;
			Item *it;
			if (m249 == false && location[cursite]->type == SITE_GOVERNMENT_ARMYBASE)
			{
				clearmessagearea();
				set_color(COLOR_WHITE, COLOR_BLACK, 1);
				moveSixteenOne();
				addstrAlt("Jackpot! The squad found a M249 Machine Gun!", gamelog);
				gamelog.newline();
				getkey();
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
				set_color(COLOR_WHITE, COLOR_BLACK, 1);
				moveSixteenOne();
				addstrAlt("The squad finds some M16 Assault Rifles.", gamelog);
				gamelog.newline();
				getkey();
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
				set_color(COLOR_WHITE, COLOR_BLACK, 1);
				moveSixteenOne();
				addstrAlt("The squad finds some M4 Carbines.", gamelog);
				gamelog.newline();
				getkey();
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
				set_color(COLOR_WHITE, COLOR_BLACK, 1);
				moveSixteenOne();
				addstrAlt("The squad finds some body armor.", gamelog);
				gamelog.newline();
				getkey();
				int num = 0;
				do
				{
					Armor* de;
					if (location[cursite]->type == SITE_GOVERNMENT_ARMYBASE)
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
				set_color(COLOR_WHITE, COLOR_BLACK, 1);
				moveSixteenOne();
				addstrAlt("It's a trap!  The armory is empty.", gamelog);
				gamelog.newline();
				getkey();
				int numleft = LCSrandom(8) + 2;
				if (location[cursite]->type == SITE_GOVERNMENT_ARMYBASE) {
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
				set_color(COLOR_WHITE, COLOR_BLACK, 1);
				moveSixteenOne();
				addstrAlt("Guards are everywhere!", gamelog);
				gamelog.newline();
				getkey();
				int numleft = LCSrandom(4) + 2;
				if (location[cursite]->type == SITE_GOVERNMENT_ARMYBASE) {
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
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("You've found a safe.", gamelog);
		gamelog.newline();
		moveSeventeenOne();
		addstrAlt("Open it? (Yes or No)");
		int c = getkey();
		if (c == 'y')
		{
			char actual;
			if (unlock(UNLOCK_SAFE, actual))
			{
				clearmessagearea();
				set_color(COLOR_WHITE, COLOR_BLACK, 1);
				moveSixteenOne();
				addstrAlt("The Squad has found some very interesting files.", gamelog);
				gamelog.newline();
				Item *it = new Loot(*loottype[getloottype(tag_LOOT_CORPFILES)]);
				activesquad->loot.push_back(it);
				it = new Loot(*loottype[getloottype(tag_LOOT_CORPFILES)]);
				activesquad->loot.push_back(it);
				juiceparty(50, 1000);
				sitecrime += 40;
				int time = 20 + LCSrandom(10);
				if (time < 1)time = 1;
				if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
				getkey();
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
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		if (sitealarm || sitealienate)
		{
			moveSixteenOne();
			addstrAlt("The radio broadcasters left the equipment on in ", gamelog);
			moveSeventeenOne();
			addstrAlt("their rush to get out.", gamelog);
			gamelog.newline();
			addstrAlt(" Take over the studio? (Yes or No)");
		}
		else
		{
			moveSixteenOne();
			addstrAlt("You've found a radio broadcasting room.", gamelog);
			gamelog.newline();
			moveSeventeenOne();
			addstrAlt("Interrupt this evening's programming? (Yes or No)");
		}
		int c = getkey();
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
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		if (sitealarm || sitealienate)
		{
			moveSixteenOne();
			addstrAlt("The Cable News broadcasters left the equipment on in", gamelog);
			moveSeventeenOne();
			addstrAlt("their rush to get out.");
			gamelog.newline();
			addstrAlt(" Take over the studio? (Yes or No)");
		}
		else
		{
			moveSixteenOne();
			addstrAlt("You've found a Cable News broadcasting studio.", gamelog);
			moveSeventeenOne();
			addstrAlt("Start an impromptu news program? (Yes or No)");
		}
		int c = getkey();
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
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("You see a display case.", gamelog);
		moveSeventeenOne();
		addstrAlt("Smash it? (Yes or No)");
		int c = getkey();
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
		switch (location[cursite]->type)
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
			if (location[cursite]->renting == RENTING_CCS)
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
	for (int p = 0; p < len(pool); p++)
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
	set_color(COLOR_WHITE, COLOR_BLACK, 1);
	moveSixteenOne();
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
	getkey();
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
	moveSeventeenOne();
	switch (rejected)
	{
	case REJECTED_NUDE:
		set_color(COLOR_RED, COLOR_BLACK, 1);
		if (autoadmit) addstrAlt("\"Jesus! Put some clothes on!\"", gamelog);
		else addstrAlt(pickrandom(caseREJECTED_NUDE), gamelog);
		gamelog.newline();
		break;
	case REJECTED_UNDERAGE:
		set_color(COLOR_RED, COLOR_BLACK, 1);
		addstrAlt(pickrandom(caseREJECTED_UNDERAGE), gamelog);
		gamelog.newline();
		break;
	case REJECTED_DRESSCODE:
		set_color(COLOR_RED, COLOR_BLACK, 1);
		addstrAlt(pickrandom(caseREJECTED_DRESSCODE), gamelog);
		gamelog.newline();
		break;
	case REJECTED_SMELLFUNNY:
		set_color(COLOR_RED, COLOR_BLACK, 1);
		addstrAlt(pickrandom(caseREJECTED_SMELLFUNNY), gamelog);
		gamelog.newline();
		break;
	case REJECTED_BLOODYCLOTHES:
		set_color(COLOR_RED, COLOR_BLACK, 1);
		addstrAlt(pickrandom(caseREJECTED_BLOODYCLOTHES), gamelog);
		gamelog.newline();
		break;
	case REJECTED_DAMAGEDCLOTHES:
		set_color(COLOR_RED, COLOR_BLACK, 1);
		addstrAlt(pickrandom(caseREJECTED_DAMAGEDCLOTHES), gamelog);
		gamelog.newline();
		break;
	case REJECTED_SECONDRATECLOTHES:
		set_color(COLOR_RED, COLOR_BLACK, 1);
		addstrAlt(pickrandom(caseREJECTED_SECONDRATECLOTHES), gamelog);
		gamelog.newline();
		break;
	case REJECTED_WEAPONS:
		set_color(COLOR_RED, COLOR_BLACK, 1);
		if (metaldetect)
		{
			addstrAlt("-BEEEP- -BEEEP- -BEEEP-", gamelog);
			sitealarm = 1;
		}
		else addstrAlt(pickrandom(caseREJECTED_WEAPONS), gamelog);
		gamelog.newline();
		break;
	case NOT_REJECTED:
		set_color(COLOR_GREEN, COLOR_BLACK, 1);
		addstrAlt(pickrandom(caseNOT_REJECTED), gamelog);
		gamelog.newline();
		break;
	}
	getkey();
	set_color(COLOR_WHITE, COLOR_BLACK, 1);
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
	moveSixteenOne();
	addstrAlt("The vault door has three layers: A combo lock, ", gamelog);
	moveSeventeenOne();
	addstrAlt("an electronic lock, and a biometric lock.", gamelog);
	gamelog.newline();
	getkey();
	clearmessagearea();
	moveSixteenOne();
	addstrAlt("You will need a security expert, a computer ", gamelog);
	moveSeventeenOne();
	addstrAlt("expert, and one of the bank managers.", gamelog);
	gamelog.newline();
	getkey();
	for (int p = 0; p < len(pool); p++)
	{
		if (pool[p]->type == CREATURE_BANK_MANAGER &&
			pool[p]->flag & CREATUREFLAG_SLEEPER &&
			pool[p]->base == cursite)
		{
			clearmessagearea();
			moveSixteenOne();
			addstrAlt(string_sleeper, gamelog);
			addstrAlt(pool[p]->name, gamelog);
			addstrAlt(" can handle the biometrics, ", gamelog);
			moveSeventeenOne();
			addstrAlt("but you'll still have to crack the other locks.", gamelog);
			gamelog.newline();
			getkey();
			break;
		}
	}
	while (true)
	{
		clearmessagearea();
		moveSixteenOne();
		addstrAlt("Open the bank vault? (Yes or No)");
		int c = getkey();
		if (c == 'y')
		{
			char actual;
			clearmessagearea();
			set_color(COLOR_WHITE, COLOR_BLACK, 1);
			moveSixteenOne();
			addstrAlt("First is the combo lock that will have ", gamelog);
			moveSeventeenOne();
			addstrAlt("be cracked by a security expert.", gamelog);
			gamelog.newline();
			getkey();
			if (!unlock(UNLOCK_VAULT, actual))
			{
				clearmessagearea();
				set_color(COLOR_WHITE, COLOR_BLACK, 1);
				moveSixteenOne();
				addstrAlt("The squad can only dream of the money ", gamelog);
				moveSeventeenOne();
				addstrAlt("on the other side of this door...", gamelog);
				gamelog.newline();
				getkey();
				levelmap[locx][locy][locz].special = -1;
			}
			else
			{
				clearmessagearea();
				set_color(COLOR_WHITE, COLOR_BLACK, 1);
				moveSixteenOne();
				addstrAlt("Next is the electronic lock that will have ", gamelog);
				moveSeventeenOne();
				addstrAlt("be bypassed by a computer expert.", gamelog);
				gamelog.newline();
				getkey();
				if (!hack(HACK_VAULT, actual))
				{
					clearmessagearea();
					set_color(COLOR_WHITE, COLOR_BLACK, 1);
					moveSixteenOne();
					addstrAlt("The money was so close the squad could taste it!", gamelog);
					gamelog.newline();
					getkey();
					levelmap[locx][locy][locz].special = -1;
				}
				else
				{
					clearmessagearea();
					set_color(COLOR_WHITE, COLOR_BLACK, 1);
					moveSixteenOne();
					addstrAlt("Last is the biometric lock that keyed only ", gamelog);
					moveSeventeenOne();
					addstrAlt("to the bank's managers.", gamelog);
					gamelog.newline();
					getkey();
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
									set_color(COLOR_WHITE, COLOR_BLACK, 1);
									moveSixteenOne();
									addstrAlt(c->name, gamelog);
									addstrAlt(" opens the vault.", gamelog);
									gamelog.newline();
									getkey();
									canbreakin = true;
									break;
								}
							}
							if (c->prisoner && c->prisoner->type == CREATURE_BANK_MANAGER)
							{
								clearmessagearea();
								set_color(COLOR_WHITE, COLOR_BLACK, 1);
								moveSixteenOne();
								addstrAlt("The hostage is forced to open the vault.", gamelog);
								gamelog.newline();
								getkey();
								canbreakin = true;
								break;
							}
						}
					}
					if (!canbreakin)
					{
						for (int p = 0; p < len(pool); p++)
						{
							if (pool[p]->base == cursite && pool[p]->type == CREATURE_BANK_MANAGER)
							{
								clearmessagearea();
								set_color(COLOR_WHITE, COLOR_BLACK, 1);
								moveSixteenOne();
								addstrAlt(string_sleeper, gamelog);
								addstrAlt(pool[p]->name, gamelog);
								addstrAlt(" opens the vault, ", gamelog);
								moveSeventeenOne();
								addstrAlt("and will join the active LCS to avoid arrest.", gamelog);
								gamelog.newline();
								getkey();
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
							set_color(COLOR_WHITE, COLOR_BLACK, 1);
							moveSixteenOne();
							addstrAlt(manager->name, gamelog);
							addstrAlt(" is no longer recognized.", gamelog);
							gamelog.newline();
							getkey();
						}
						else
						{
							clearmessagearea();
							set_color(COLOR_WHITE, COLOR_BLACK, 1);
							moveSixteenOne();
							addstrAlt("The squad has nobody that can do the job.", gamelog);
							gamelog.newline();
							getkey();
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
		location[cursite]->siege.siege)
	{
		clearmessagearea(false);
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("The teller window is empty.", gamelog);
		gamelog.newline();
		levelmap[locx][locy][locz].special = -1;
		getkey();
	}
	else
	{
		clearmessagearea(false);
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("A bank teller is available.", gamelog);
		gamelog.newline();
		levelmap[locx][locy][locz].special = -1;
		getkey();
		emptyEncounter();
		makecreature(encounter[0], CREATURE_BANK_TELLER);
	}
}
void special_bank_money()
{
	static int swat_counter = 0;
	clearmessagearea(false);
	set_color(COLOR_GREEN, COLOR_BLACK, 1);
	moveSixteenOne();
	addstrAlt("The squad loads bricks of cash into a duffel bag.", gamelog);
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
		getkey();
		moveSeventeenOne();
		if (swat_counter > 0)
			addstrAlt("Another SWAT team moves in!!", gamelog);
		else
			addstrAlt("A SWAT team storms the vault!!", gamelog);
		gamelog.newline();
		swat_counter++;
		int swatnum = 9;
		fillEncounter(CREATURE_SWAT, swatnum);
	}
	getkey();
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
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("The President isn't here... ", gamelog);
		printsitemap(locx, locy, locz);
		getkey();
		moveSeventeenOne();
		addstrAlt("Secret Service agents ambush the squad!", gamelog);
		gamelog.newline();
		for (int e = 0; e < 6; e++)makecreature(encounter[e], CREATURE_SECRET_SERVICE);
		printencounter();
		getkey();
		enemyattack();
		creatureadvance();
	}
	else
	{
		emptyEncounter();
		clearmessagearea(false);
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("The President is in the Oval Office.", gamelog);
		gamelog.newline();
		printsitemap(locx, locy, locz);
		for (int e = 0; e < 2; e++)makecreature(encounter[e], CREATURE_SECRET_SERVICE);
		encounter[2] = uniqueCreatures.President();
		printencounter();
		getkey();
	}
}
void special_ccs_boss()
{
	if (sitealarm || sitealienate ||
		location[cursite]->siege.siege)
	{
		clearmessagearea(false);
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("The CCS leader is ready for you!", gamelog);
		gamelog.newline();
		levelmap[locx][locy][locz].special = -1;
		getkey();
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
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveSixteenOne();
		addstrAlt("The CCS leader is here.", gamelog);
		gamelog.newline();
		levelmap[locx][locy][locz].special = -1;
		getkey();
		emptyEncounter();
		makecreature(encounter[0], CREATURE_CCS_ARCHCONSERVATIVE);
	}
}