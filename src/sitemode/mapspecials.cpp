#define	MAPSPECIALS_CPP
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
char checkActiveSquadForRejection(const char autoadmit, const bool metaldetect) {
	char rejected = NOT_REJECTED;
	// Size up the squad for entry
	for (int s = 0; s < 6; s++)
	{
		if (activesquad->squad[s])
		{
			// Wrong clothes? Gone
			if (activesquad->squad[s]->is_naked() && activesquad->squad[s]->animalgloss != ANIMALGLOSS_ANIMAL)
				if (rejected > REJECTED_NUDE)rejected = REJECTED_NUDE;
			if (autoadmit < 1 && !hasdisguise(*activesquad->squad[s]))
				if (rejected > REJECTED_DRESSCODE)rejected = REJECTED_DRESSCODE;
			// Busted, cheap, bloody clothes? Gone
			if (autoadmit < 2 && activesquad->squad[s]->get_armor().is_bloody())
				if (rejected > REJECTED_BLOODYCLOTHES)rejected = REJECTED_BLOODYCLOTHES;
			if (autoadmit < 2 && activesquad->squad[s]->get_armor().is_damaged())
				if (rejected > REJECTED_DAMAGEDCLOTHES)rejected = REJECTED_DAMAGEDCLOTHES;
			if (autoadmit < 2 && activesquad->squad[s]->get_armor().get_quality() != 1)
				if (rejected > REJECTED_SECONDRATECLOTHES)rejected = REJECTED_SECONDRATECLOTHES;
			// Suspicious weapons? Gone
			if (autoadmit < 2 && weaponcheck(*activesquad->squad[s], metaldetect)>0)
				if (rejected > REJECTED_WEAPONS)rejected = REJECTED_WEAPONS;
			// Fail a tough disguise check? Gone
			if (autoadmit < 1 && disguisesite(sitetype) && !(activesquad->squad[s]->skill_check(SKILL_DISGUISE, DIFFICULTY_CHALLENGING)))
				if (rejected > REJECTED_SMELLFUNNY)rejected = REJECTED_SMELLFUNNY;
			// Underage? Gone
			if (autoadmit < 1 && activesquad->squad[s]->getCreatureBio().age < 18)
				if (rejected > REJECTED_UNDERAGE)rejected = REJECTED_UNDERAGE;
		}
	}
	return rejected;
}
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
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();
	// add a bouncer if there isn't one in the first slot
	// IsaacG Change in behavior: adds a bouncer whether or not there is one in the first slot
	if (!isThereASiteAlarm() && LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE, getCurrentSite()) != RENTING_PERMANENT)
	{
		if (LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE, getCurrentSite()) == RENTING_CCS)
		{
			makecreature(0, CREATURE_CCS_VIGILANTE);
			makecreature(1, CREATURE_CCS_VIGILANTE);
		}
		else //if (!encounter[0].exists || encounter[0].type != CREATURE_BOUNCER)
		{
			makecreature(0, CREATURE_BOUNCER);
			makecreature(1, CREATURE_BOUNCER);
		}
	}
}
map<int, vector<string> > rejectionReasons;
map<int, vector<string> > caseRejectionReasons;
// the vector<string> 'caseREJECTED' and 'rejected' are similar but not identicle.
// TODO the precise differences should be made more apparant
vector<string> rejectedBecauseSmellFunny;
vector<string> notRejected;
vector<string> randomCrime;
vector<string> caseREJECTED_NUDE;
vector<string> caseREJECTED_WEAPONS;
vector<string> caseNOT_REJECTED;
vector<file_and_text_collection> map_specials_text_file_collection = {
customText(&rejectedBecauseSmellFunny, mostlyendings + CONST_mapspecials024),
	customText(&notRejected, mostlyendings + CONST_mapspecials025),
	customText(&randomCrime, mostlyendings + CONST_mapspecials026),
	customText(&caseREJECTED_NUDE, mostlyendings + CONST_mapspecials027),
	customText(&caseREJECTED_WEAPONS, mostlyendings + CONST_mapspecials028),
	customText(&caseNOT_REJECTED, mostlyendings + CONST_mapspecials029),
};
char sizeUpSquadForEntry(const bool autoadmit) {


	char rejected = NOT_REJECTED;
	// Size up the squad for entry
	if (!autoadmit)
	{
		for (int s = 0; s < 6; s++)
		{
			if (activesquad->squad[s])
			{
				// Wrong clothes? Gone
				if (activesquad->squad[s]->is_naked() && activesquad->squad[s]->animalgloss != ANIMALGLOSS_ANIMAL)
					if (rejected > REJECTED_NUDE)rejected = REJECTED_NUDE;
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
				if (activesquad->squad[s]->getCreatureBio().age < 18)
					if (rejected > REJECTED_UNDERAGE)rejected = REJECTED_UNDERAGE;
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
				if (sitetype == SITE_BUSINESS_CIGARBAR && LocationsPool::getInstance().get_specific_integer(INT_ISTHISPLACEHIGHSECURITY, getCurrentSite()))
					if (rejected > REJECTED_GUESTLIST)rejected = REJECTED_GUESTLIST;
				if (LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE, getCurrentSite()) == RENTING_CCS && LocationsPool::getInstance().getLocationType(getCurrentSite()) != SITE_BUSINESS_BARANDGRILL)
					rejected = REJECTED_CCS;
			}
		}
		moveAlt(17, 1);
		if (rejectionReasons.count(rejected)) {
			set_color_easy(RED_ON_BLACK_BRIGHT);
			addstrAlt(pickrandom(rejectionReasons[rejected]), gamelog);
		}
		else
			switch (rejected)
			{
			case REJECTED_SMELLFUNNY:
				set_color_easy(RED_ON_BLACK_BRIGHT);
				if (!LCSrandom(len(rejectedBecauseSmellFunny) - 1)) {
					if (lawList[LAW_FREESPEECH] == -2)addstrAlt(CONST_mapspecials033, gamelog);
					else if (lawList[LAW_FREESPEECH] == 2)addstrAlt(CONST_mapspecialsX01, gamelog);
					else addstrAlt(CONST_mapspecialsX02, gamelog);
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
		pressAnyKey();
	}
	else {
		setEncounterZeroExistsFalse();
	}
	return rejected;
}
void special_bouncer_assess_squad()
{

	if (LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE, getCurrentSite()) == RENTING_PERMANENT) return;
	bool autoadmit = 0;
	char sleepername[80];
	emptyEncounter();
	special_bouncer_greet_squad();
	{
		string name = getSleeperBouncerName(getCurrentSite());
		if (name.size()) {
			autoadmit = 1;
			strcpy(sleepername, name.data());
			encounter[0].rename(sleepername);
			encounter[0].align = 1;
		}

	}
	//clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(16, 1);
	if (autoadmit)
	{
		addstrAlt(string_sleeper, gamelog);
		addstrAlt(sleepername, gamelog);
		addstrAlt(CONST_mapspecials030, gamelog);
		gamelog.newline();
		levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
	}
	else
	{
		if (LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE, getCurrentSite()) == RENTING_CCS)
			addstrAlt(CONST_mapspecials031, gamelog);
		else
			addstrAlt(CONST_mapspecials032, gamelog);
		gamelog.newline();
		levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = SPECIAL_CLUB_BOUNCER_SECONDVISIT;
	}
	printencounter();
	pressAnyKey();
	char rejected = sizeUpSquadForEntry(autoadmit);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	for (int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++)
		{
			if (levelmap[loc_coord.locx + dx][loc_coord.locy + dy][loc_coord.locz].flag & SITEBLOCK_DOOR)
			{
				if (rejected < NOT_REJECTED)
				{
					levelmap[loc_coord.locx + dx][loc_coord.locy + dy][loc_coord.locz].flag |= SITEBLOCK_LOCKED;
					levelmap[loc_coord.locx + dx][loc_coord.locy + dy][loc_coord.locz].flag |= SITEBLOCK_CLOCK;
				}
				else levelmap[loc_coord.locx + dx][loc_coord.locy + dy][loc_coord.locz].flag &= ~SITEBLOCK_DOOR;
			}
		}
	encounter[0].make_cantbluff_one();
}
void special_lab_cosmetics_cagedanimals()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, CONST_mapspecials036, gamelog);
		gamelog.newline();
		mvaddstrAlt(17, 1, CONST_mapspecials062);
		int c = getkeyAlt();
		if (c == 'y')
		{
			UnlockAttempt actualy = unlock(UNLOCK_CAGE);
			if (actualy == UNLOCKED)
			{
				int time = 20 + LCSrandom(10);
				if (time < 1)time = 1;
				if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
				sitecrime++;
				juiceparty(3, 100);
				addCrimeToSiteStory(CRIME_FREE_RABBITS);
				criminalizeparty(LAWFLAG_VANDALISM);
			}
			if (actualy != NEVERMIND)
			{
				alienationcheck(0);
				noticecheck(-1);
				levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
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
		switch (LocationsPool::getInstance().getLocationType(getCurrentSite()))
		{
		default:
			mvaddstrAlt(16, 1, CONST_mapspecialsX03);
			break;
		case SITE_INDUSTRY_NUCLEAR:
			mvaddstrAlt(16, 1, CONST_mapspecials039);
			mvaddstrAlt(17, 1, CONST_mapspecials040);
			break;
		case SITE_RESIDENTIAL_TENEMENT:
		case SITE_RESIDENTIAL_APARTMENT:
		case SITE_RESIDENTIAL_APARTMENT_UPSCALE:
			mvaddstrAlt(16, 1, CONST_mapspecials041);
			mvaddstrAlt(17, 1, CONST_mapspecials042);
			break;
		}
		break;
	case SPECIAL_SIGN_TWO:
		switch (LocationsPool::getInstance().getLocationType(getCurrentSite()))
		{
		default:
			mvaddstrAlt(16, 1, CONST_mapspecialsX04);
			break;
		}
		break;
	case SPECIAL_SIGN_THREE:
		switch (LocationsPool::getInstance().getLocationType(getCurrentSite()))
		{
		default:
			mvaddstrAlt(16, 1, CONST_mapspecials044);
			break;
		}
		break;
	}
	pressAnyKey();
}
void special_nuclear_onoff()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		if (lawList[LAW_NUCLEARPOWER] == 2)
		{
			mvaddstrAlt(16, 1, CONST_mapspecials045, gamelog);
			gamelog.newline();
			mvaddstrAlt(17, 1, CONST_mapspecials046);
		}
		else
		{
			mvaddstrAlt(16, 1, CONST_mapspecials047, gamelog);
			gamelog.newline();
			mvaddstrAlt(17, 1, CONST_mapspecials048);
		}
		int c = getkeyAlt();
		if (c == 'y')
		{
			clearmessagearea();
			levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
			char max = DIFFICULTY_HARD;
			DeprecatedCreature* maxs = 0;
			for (int p = 0; p < 6; p++)
			{
				if (activesquad->squad[p] != NULL && activesquad->squad[p]->getNameAndAlignment().alive)
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
				mvaddstrAlt(16, 1, maxs->getNameAndAlignment().name, gamelog);
				addstrAlt(CONST_mapspecials049, gamelog);
				gamelog.newline();
				pressAnyKey();
				mvaddstrAlt(17, 1, singleDot, gamelog);
				pressAnyKey();
				addstrAlt(singleDot, gamelog);
				pressAnyKey();
				addstrAlt(singleDot, gamelog);
				pressAnyKey();
				if (lawList[LAW_NUCLEARPOWER] == 2)
				{
					mvaddstrAlt(17, 1, CONST_mapspecials050, gamelog);
					gamelog.newline();
					change_public_opinion(VIEW_NUCLEARPOWER, 15, 0, 95);
					change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, -50, 0, 0);
					pressAnyKey();
					juiceparty(40, 1000); // Instant juice!
					sitecrime += 25; //Shutdown Site
					addCrimeToSiteStory(CRIME_SHUTDOWNREACTOR);
				}
				else
				{
					mvaddstrAlt(16, 1, CONST_mapspecials051, gamelog);
					gamelog.newline();
					addstrAlt(CONST_mapspecials052); // Remove remaining part of previous text.
					mvaddstrAlt(17, 1, CONST_mapspecials053, gamelog);
					gamelog.newline();
					change_public_opinion(VIEW_NUCLEARPOWER, 15, 0, 95);
					pressAnyKey();
					juiceparty(100, 1000); // Instant juice!
					sitecrime += 50; //Shutdown Site
					addCrimeToSiteStory(CRIME_SHUTDOWNREACTOR);
				}
			}
			else
			{
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 1, CONST_mapspecials054, gamelog);
				mvaddstrAlt(17, 1, CONST_mapspecials055, gamelog);
				gamelog.newline();
				pressAnyKey();
				juiceparty(15, 500);
			}
			setSiteAlarmOne();
			alienationcheck(1);
			levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
			sitecrime += 5;
			criminalizeparty(LAWFLAG_TERRORISM);
			return;
		}
		else if (c == 'n')return;
	}
}
void special_lab_genetic_cagedanimals()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, CONST_mapspecials056, gamelog);
		gamelog.newline();
		mvaddstrAlt(17, 1, CONST_mapspecials062);
		int c = getkeyAlt();
		if (c == 'y')
		{
			UnlockAttempt actualy = unlock(UNLOCK_CAGE_HARD);
			if (actualy == UNLOCKED)
			{
				int time = 20 + LCSrandom(10);
				if (time < 1)time = 1;
				if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
				sitecrime++;
				juiceparty(5, 200);
				addCrimeToSiteStory(CRIME_FREE_BEASTS);
				criminalizeparty(LAWFLAG_VANDALISM);
				if (!LCSrandom(2))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16, 1, CONST_mapspecials058, gamelog);
					gamelog.newline();
					int numleft = LCSrandom(6) + 1;
					fillEncounter(CREATURE_GENETIC, numleft);
					if (mode == GAMEMODE_CHASECAR ||
						mode == GAMEMODE_CHASEFOOT)printchaseencounter();
					else printencounter();
					pressAnyKey();
					setSiteAlarmOne();
					alienationcheck(1);
				}
				else
				{
					alienationcheck(0);
				}
			}
			else if (actualy == LOUD_FAILURE)
			{
				noticecheck(-1);
			}
			if (actualy != NEVERMIND)
			{
				levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
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
		mvaddstrAlt(16, 1, CONST_mapspecials059, gamelog);
		gamelog.newline();
		mvaddstrAlt(17, 1, CONST_mapspecials062);
		int c = getkeyAlt();
		if (c == 'y')
		{
			UnlockAttempt actualy = unlock(UNLOCK_CELL);
			if (actualy == UNLOCKED)
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
			if (actualy != NEVERMIND)
			{
				alienationcheck(1);
				noticecheck(-1, DIFFICULTY_HARD);
				levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
				sitecrime += 2;
				addCrimeToSiteStory(CRIME_POLICE_LOCKUP);
				criminalizeparty(LAWFLAG_HELPESCAPE);
			}
			return;
		}
		else if (c == 'n')return;
	}
}


void courtLockupPressY() {

	UnlockAttempt actualy = unlock(UNLOCK_CELL);
	if (actualy == UNLOCKED)
	{
		int numleft = LCSrandom(8) + 2;
		fillEncounter(CREATURE_PRISONER, numleft);
		juiceparty(50, 1000);
		sitecrime += 20;
		int time = 20 + LCSrandom(10);
		if (time < 1) { time = 1; }
		if (sitealarmtimer > time || sitealarmtimer == -1) { sitealarmtimer = time; }
		if (mode == GAMEMODE_CHASECAR ||
			mode == GAMEMODE_CHASEFOOT)
		{
			printchaseencounter();
		}
		else { 
			printencounter(); 
		}
		refreshAlt();
		partyrescue(SPECIAL_COURTHOUSE_LOCKUP);
	}
	if (actualy != NEVERMIND)
	{
		alienationcheck(1);
		noticecheck(-1, DIFFICULTY_HARD);
		levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
		sitecrime += 3;
		addCrimeToSiteStory(CRIME_COURTHOUSE_LOCKUP);
		criminalizeparty(LAWFLAG_HELPESCAPE);
	}
}
void special_courthouse_lockup()
{
	int c;
	do
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, CONST_mapspecials061, gamelog);
		gamelog.newline();
		mvaddstrAlt(17, 1, CONST_mapspecials062);

		c = getkeyAlt();

		if (c == 'y')
		{
			courtLockupPressY();
		}

	}while (c != 'y' && c != 'n');
	return;
}
void special_courthouse_jury()
{
	if (isThereASiteAlarm() || sitealienate)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, CONST_mapspecials063, gamelog);
		mvaddstrAlt(17, 1, CONST_mapspecials064, gamelog);
		gamelog.newline();
		pressAnyKey();
		return;
	}
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, CONST_mapspecials065, gamelog);
		gamelog.newline();
		mvaddstrAlt(17, 1, CONST_mapspecials066);
		int c = getkeyAlt();
		if (c == 'y')
		{
			levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
			int maxattack = 0;
			int maxp = -1;
			for (int p = 0; p < 6; p++)
			{
				if (activesquad->squad[p] != NULL)
				{
					if (activesquad->squad[p]->getNameAndAlignment().alive)
					{
						if (activesquad->squad[p]->get_attribute(ATTRIBUTE_CHARISMA, true) +
							activesquad->squad[p]->get_attribute(ATTRIBUTE_INTELLIGENCE, true) +
							activesquad->squad[p]->get_skill(SKILL_PERSUASION) +
							activesquad->squad[p]->get_skill(SKILL_LAW) > maxattack)
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
					activesquad->squad[p]->skill_check(SKILL_LAW, DIFFICULTY_CHALLENGING))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16, 1, activesquad->squad[p]->getNameAndAlignment().name, gamelog);
					addstrAlt(CONST_mapspecials067, gamelog);
					mvaddstrAlt(17, 1, CONST_mapspecials068, gamelog);//XXX: This is very awkward grammar.
					addstrAlt(pickrandom(randomCrime), gamelog);
					addstrAlt(CONST_mapspecials069, gamelog);
					gamelog.newline();
					pressAnyKey();
					alienationcheck(0);
					noticecheck(-1);
					//INSTANT JUICE BONUS
					addjuice(*(activesquad->squad[p]), 25, 200);
				}
				else
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16, 1, activesquad->squad[p]->getNameAndAlignment().name, gamelog);
					addstrAlt(CONST_mapspecials070, gamelog);
					gamelog.newline();
					pressAnyKey();
					int numleft = 12;
					fillEncounter(CREATURE_JUROR, numleft);
					if (mode == GAMEMODE_CHASECAR ||
						mode == GAMEMODE_CHASEFOOT)printchaseencounter();
					else printencounter();
					refreshAlt();
					setSiteAlarmOne();
					sitealienate = 2;
					sitecrime += 10;
					addCrimeToSiteStory(CRIME_JURYTAMPERING);
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
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, CONST_mapspecials071, gamelog);
		if (prison_control_type == SPECIAL_PRISON_CONTROL_LOW)
			addstrAlt(CONST_mapspecials072, gamelog);
		else if (prison_control_type == SPECIAL_PRISON_CONTROL_MEDIUM)
			addstrAlt(CONST_mapspecials073, gamelog);
		else if (prison_control_type == SPECIAL_PRISON_CONTROL_HIGH)
			addstrAlt(CONST_mapspecials074, gamelog);
		addstrAlt(CONST_mapspecials075, gamelog);
		gamelog.newline();
		mvaddstrAlt(17, 1, CONST_mapspecials076);
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
			levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
			sitecrime += 30;
			juiceparty(50, 1000);
			addCrimeToSiteStory(CRIME_PRISON_RELEASE);
			criminalizeparty(LAWFLAG_HELPESCAPE);
			return;
		}
		else if (c == 'n')return;
	}
}
void special_intel_supercomputer()
{
	if (isThereASiteAlarm() || sitealienate)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, CONST_mapspecials077, gamelog);
		mvaddstrAlt(17, 1, CONST_mapspecials078, gamelog);
		gamelog.newline();
		pressAnyKey();
		return;
	}
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, CONST_mapspecials079, gamelog);
		gamelog.newline();
		mvaddstrAlt(17, 1, CONST_mapspecials080);
		int c = getkeyAlt();
		if (c == 'y')
		{
			UnlockAttempt actualy = hack(HACK_SUPERCOMPUTER);
			if (actualy == UNLOCKED)
			{
				clearmessagearea();
				//char *loot;
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 1, CONST_mapspecials081, gamelog);
				if (endgamestate >= ENDGAME_CCS_APPEARANCE && endgamestate < ENDGAME_CCS_DEFEATED && ccsexposure < CCSEXPOSURE_LCSGOTDATA)
				{
					addstrAlt(CONST_mapspecials082, gamelog);
					mvaddstrAlt(17, 1, CONST_mapspecials083, gamelog);
					giveActiveSquadLoot(tag_LOOT_CCS_BACKERLIST);
					ccsexposure = CCSEXPOSURE_LCSGOTDATA;
				}
				else
				{
					addstrAlt(singleDot, gamelog);
				}
				gamelog.newline();
				juiceparty(50, 1000);
				giveActiveSquadLoot(tag_LOOT_INTHQDISK);
				pressAnyKey();
			}
			if (actualy != NEVERMIND)
			{
				int time = 20 + LCSrandom(10);
				if (time < 1)time = 1;
				if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
				alienationcheck(1);
				noticecheck(-1, DIFFICULTY_HARD);
				levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
				sitecrime += 3;
				addCrimeToSiteStory(CRIME_HACK_INTEL);
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
	mvaddstrAlt(16, 1, CONST_mapspecials084, gamelog);
	gamelog.newline();
	claimSiteStoryOne();
	pressAnyKey();
	int time = 20 + LCSrandom(10);
	if (time < 1)time = 1;
	if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
	alienationcheck(0);
	noticecheck(-1, DIFFICULTY_HARD);
	levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].flag |= SITEBLOCK_GRAFFITI;
	levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].flag &= ~(SITEBLOCK_GRAFFITI_CCS | SITEBLOCK_GRAFFITI_OTHER);
	if (!LocationsPool::getInstance().get_specific_integer(INT_ISTHISPLACEHIGHSECURITY, getCurrentSite()))
	{
		LocationsPool::getInstance().eraseAndReplaceGraffiti(getCurrentSite(), loc_coord.locx, loc_coord.locy, loc_coord.locz);
	}
	sitecrime++;
	juiceActiveSquad(1, 50);
	criminalizeparty(LAWFLAG_VANDALISM); 
	addCrimeToSiteStory(CRIME_TAGGING);
	return;
}
void special_sweatshop_equipment()
{
	while (true)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, CONST_mapspecials085, gamelog);
		gamelog.newline();
		mvaddstrAlt(17, 1, CONST_mapspecials088);
		int c = getkeyAlt();
		if (c == 'y')
		{
			int time = 20 + LCSrandom(10);
			if (time < 1)time = 1;
			if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
			alienationcheck(0);
			noticecheck(-1, DIFFICULTY_HEROIC);
			levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
			levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].flag |= SITEBLOCK_DEBRIS;
			sitecrime++;
			juiceparty(5, 100);
			addCrimeToSiteStory(CRIME_BREAK_SWEATSHOP);
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
		mvaddstrAlt(16, 1, CONST_mapspecials087, gamelog);
		gamelog.newline();
		mvaddstrAlt(17, 1, CONST_mapspecials088);
		int c = getkeyAlt();
		if (c == 'y')
		{
			int time = 20 + LCSrandom(10);
			if (time < 1)time = 1;
			if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
			change_public_opinion(VIEW_POLLUTION, 2, 1, 70);
			alienationcheck(0);
			noticecheck(-1, DIFFICULTY_HEROIC);
			levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
			levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].flag |= SITEBLOCK_DEBRIS;
			sitecrime += 2;
			juiceparty(5, 100);
			addCrimeToSiteStory(CRIME_BREAK_FACTORY);
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
		mvaddstrAlt(16, 1, CONST_mapspecials109, gamelog);
		gamelog.newline();
		mvaddstrAlt(17, 1, CONST_mapspecials110);
		int c = getkeyAlt();
		if (c == 'y')
		{
			UnlockAttempt actualy = unlock(UNLOCK_SAFE);
			if (actualy == UNLOCKED)
			{
				bool empty = true;
				if (deagle == false)
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16, 1, CONST_mapspecials091, gamelog);
					gamelog.newline();
					pressAnyKey();
					Weapon* de = new Weapon(*weapontype[getweapontype(tag_WEAPON_DESERT_EAGLE)]);
					Clip r(*cliptype[getcliptype(tag_CLIP_50AE)]);
					de->reload(r);
					giveActiveSquadThisLoot(de);
					Item *it = new Clip(*cliptype[getcliptype(tag_CLIP_50AE)], 9);
					giveActiveSquadThisLoot(it);
					deagle = true;
					empty = false;
				}
				if (LCSrandom(2))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16, 1, CONST_mapspecials092, gamelog);
					gamelog.newline();
					pressAnyKey();
					Item *it = new Money(1000 * (1 + LCSrandom(10)));
					giveActiveSquadThisLoot(it);
					empty = false;
				}
				if (LCSrandom(2))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16, 1, CONST_mapspecials093, gamelog);
					gamelog.newline();
					pressAnyKey();
					giveActiveSquadThisLoot(getNewLoot(tag_LOOT_EXPENSIVEJEWELERY, 3));
					empty = false;
				}
				if (!LCSrandom(3))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16, 1, CONST_mapspecials094, gamelog);
					gamelog.newline();
					pressAnyKey();
					giveActiveSquadThisLoot(getNewLoot(tag_LOOT_CEOPHOTOS));
					empty = false;
				}
				if (!LCSrandom(3))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16, 1, CONST_mapspecials095, gamelog);
					gamelog.newline();
					pressAnyKey();
					empty = false;
				}
				if (!LCSrandom(3))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16, 1, CONST_mapspecials096, gamelog);
					mvaddstrAlt(17, 1, CONST_mapspecials097);
					gamelog.newline();
					pressAnyKey();
					giveActiveSquadThisLoot(getNewLoot(tag_LOOT_CEOLOVELETTERS));
					empty = false;
				}
				if (!LCSrandom(3))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16, 1, CONST_mapspecials098, gamelog);
					gamelog.newline();
					pressAnyKey();
					giveActiveSquadThisLoot(getNewLoot(tag_LOOT_CEOTAXPAPERS));
					empty = false;
				}
				if (empty)
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16, 1, CONST_mapspecials099, gamelog);
					gamelog.newline();
					pressAnyKey();
				}
				else
				{
					juiceparty(50, 1000);
					sitecrime += 40;
					addCrimeToSiteStory(CRIME_HOUSE_PHOTOS);
					criminalizeparty(LAWFLAG_THEFT);
					int time = 20 + LCSrandom(10);
					if (time < 1)time = 1;
					if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
				}
			}
			if (actualy != NEVERMIND)
			{
				alienationcheck(0);
				noticecheck(-1);
				levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
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
		mvaddstrAlt(16, 1, CONST_mapspecials100, gamelog);
		gamelog.newline();
		mvaddstrAlt(17, 1, CONST_mapspecials101);
		int c = getkeyAlt();
		if (c == 'y')
		{
			clearmessagearea();
			setSiteAlarmOne();
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(16, 1, CONST_mapspecials102, gamelog);
			gamelog.newline();
			pressAnyKey();
			bool empty = true;
			Item *it;
			if (m249 == false && LocationsPool::getInstance().getLocationType(getCurrentSite()) == SITE_GOVERNMENT_ARMYBASE)
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 1, CONST_mapspecials103, gamelog);
				gamelog.newline();
				pressAnyKey();
				Weapon* de = new Weapon(*weapontype[getweapontype(tag_WEAPON_M249_MACHINEGUN)]);
				Clip r(*cliptype[getcliptype(tag_CLIP_DRUM)]);
				de->reload(r);
				giveActiveSquadThisLoot(de);
				it = new Clip(*cliptype[getcliptype(tag_CLIP_DRUM)], 9);
				giveActiveSquadThisLoot(it);
				m249 = true;
				empty = false;
			}
			if (LCSrandom(2))
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 1, CONST_mapspecials104, gamelog);
				gamelog.newline();
				pressAnyKey();
				int num = 0;
				do
				{
					Weapon* de = new Weapon(*weapontype[getweapontype(tag_WEAPON_AUTORIFLE_M16)]);
					Clip r(*cliptype[getcliptype(tag_CLIP_ASSAULT)]);
					de->reload(r);
					giveActiveSquadThisLoot(de);
					it = new Clip(*cliptype[getcliptype(tag_CLIP_ASSAULT)], 5);
					giveActiveSquadThisLoot(it);
					num++;
				} while (num < 2 || (LCSrandom(2) && num < 5));
				empty = false;
			}
			if (LCSrandom(2))
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 1, CONST_mapspecials105, gamelog);
				gamelog.newline();
				pressAnyKey();
				int num = 0;
				do
				{
					Weapon* de = new Weapon(*weapontype[getweapontype(tag_WEAPON_CARBINE_M4)]);
					Clip r(*cliptype[getcliptype(tag_CLIP_ASSAULT)]);
					de->reload(r);
					giveActiveSquadThisLoot(de);
					it = new Clip(*cliptype[getcliptype(tag_CLIP_ASSAULT)], 5);
					giveActiveSquadThisLoot(it);
					num++;
				} while (num < 2 || (LCSrandom(2) && num < 5));
				empty = false;
			}
			if (LCSrandom(2))
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 1, CONST_mapspecials106, gamelog);
				gamelog.newline();
				pressAnyKey();
				int num = 0;
				do
				{
					Armor* de;
					if (LocationsPool::getInstance().getLocationType(getCurrentSite()) == SITE_GOVERNMENT_ARMYBASE)
						de = new Armor(getarmortype(tag_ARMOR_ARMYARMOR));
					else
						de = new Armor(getarmortype(tag_ARMOR_CIVILLIANARMOR));
					giveActiveSquadThisLoot(de);
					num++;
				} while (num < 2 || (LCSrandom(2) && num < 5));
				empty = false;
			}
			if (empty)
			{
				criminalizeparty(LAWFLAG_TREASON);
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 1, CONST_mapspecials107, gamelog);
				gamelog.newline();
				pressAnyKey();
				int numleft = LCSrandom(8) + 2;
				if (LocationsPool::getInstance().getLocationType(getCurrentSite()) == SITE_GOVERNMENT_ARMYBASE) {
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
				addCrimeToSiteStory(CRIME_ARMORY);
				criminalizeparty(LAWFLAG_THEFT);
				criminalizeparty(LAWFLAG_TREASON);
				int time = 20 + LCSrandom(10);
				if (time < 1)time = 1;
				if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 1, CONST_mapspecials108, gamelog);
				gamelog.newline();
				pressAnyKey();
				int numleft = LCSrandom(4) + 2;
				if (LocationsPool::getInstance().getLocationType(getCurrentSite()) == SITE_GOVERNMENT_ARMYBASE) {
					fillEncounter(CREATURE_SOLDIER, numleft);
				}
				else {
					fillEncounter(CREATURE_MERC, numleft);
				}
			}
			alienationcheck(0);
			noticecheck(-1);
			levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
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
		mvaddstrAlt(16, 1, CONST_mapspecials109, gamelog);
		gamelog.newline();
		mvaddstrAlt(17, 1, CONST_mapspecials110);
		int c = getkeyAlt();
		if (c == 'y')
		{
			UnlockAttempt actualy = unlock(UNLOCK_SAFE);
			if (actualy == UNLOCKED)
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 1, CONST_mapspecials111, gamelog);
				gamelog.newline();
				giveActiveSquadLoot(tag_LOOT_CORPFILES);
				giveActiveSquadLoot(tag_LOOT_CORPFILES);
				juiceparty(50, 1000);
				sitecrime += 40;
				int time = 20 + LCSrandom(10);
				if (time < 1)time = 1;
				if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
				pressAnyKey();
			}
			if (actualy != NEVERMIND)
			{
				alienationcheck(0);
				noticecheck(-1);
				levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
				sitecrime += 3;
				addCrimeToSiteStory(CRIME_CORP_FILES);
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
		if (isThereASiteAlarm() || sitealienate)
		{
			mvaddstrAlt(16, 1, CONST_mapspecials112, gamelog);
			mvaddstrAlt(17, 1, CONST_mapspecials118, gamelog);
			gamelog.newline();
			addstrAlt(CONST_mapspecials119);
		}
		else
		{
			mvaddstrAlt(16, 1, CONST_mapspecials115, gamelog);
			gamelog.newline();
			mvaddstrAlt(17, 1, CONST_mapspecials116);
		}
		int c = getkeyAlt();
		if (c == 'y')
		{
			if (run_broadcast(false))
			{
				claimSiteStory();
				levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
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
		if (isThereASiteAlarm() || sitealienate)
		{
			mvaddstrAlt(16, 1, CONST_mapspecials117, gamelog);
			mvaddstrAlt(17, 1, CONST_mapspecials118);
			gamelog.newline();
			addstrAlt(CONST_mapspecials119);
		}
		else
		{
			mvaddstrAlt(16, 1, CONST_mapspecials120, gamelog);
			mvaddstrAlt(17, 1, CONST_mapspecials121);
		}
		int c = getkeyAlt();
		if (c == 'y')
		{
			if (run_broadcast(true))
			{
				claimSiteStory();
				levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
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
		mvaddstrAlt(16, 1, CONST_mapspecials122, gamelog);
		mvaddstrAlt(17, 1, CONST_mapspecials123);
		int c = getkeyAlt();
		if (c == 'y')
		{
			int time = 20 + LCSrandom(10);
			if (time < 1)time = 1;
			if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
			alienationcheck(0);
			noticecheck(-1, DIFFICULTY_HEROIC);
			levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
			levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].flag |= SITEBLOCK_DEBRIS;
			sitecrime++;
			juiceparty(5, 100);
			addCrimeToSiteStory(CRIME_VANDALISM);
			criminalizeparty(LAWFLAG_VANDALISM);
			return;
		}
		else if (c == 'n')return;
	}
}
void spawn_security()
{
	// add a bouncer if there isn't one in the first slot
	if (!isThereASiteAlarm() && !getEncounterNameAndAlignment()[0].exists)
	{
		switch (LocationsPool::getInstance().getLocationType(getCurrentSite()))
		{
		default:
		case SITE_CORPORATE_HEADQUARTERS:
		case SITE_CORPORATE_HOUSE:
		case SITE_BUSINESS_ARMSDEALER:
		case SITE_BUSINESS_BANK:
		case SITE_INDUSTRY_NUCLEAR:
			makecreature(0, CREATURE_MERC);
			makecreature(1, CREATURE_MERC);
			break;
		case SITE_GOVERNMENT_POLICESTATION:
		case SITE_GOVERNMENT_COURTHOUSE:
		case SITE_OUTDOOR_PUBLICPARK:
			makecreature(0, CREATURE_COP);
			makecreature(1, CREATURE_COP);
			break;
		case SITE_GOVERNMENT_PRISON:
			makecreature(0, CREATURE_PRISONGUARD);
			makecreature(1, CREATURE_PRISONGUARD);
			makecreature(2, CREATURE_GUARDDOG);
			break;
		case SITE_GOVERNMENT_WHITE_HOUSE:
			makecreature(0, CREATURE_SECRET_SERVICE);
			makecreature(1, CREATURE_SECRET_SERVICE);
			makecreature(2, CREATURE_SECRET_SERVICE);
			makecreature(3, CREATURE_SECRET_SERVICE);
			break;
		case SITE_GOVERNMENT_INTELLIGENCEHQ:
			makecreature(0, CREATURE_AGENT);
			makecreature(1, CREATURE_AGENT);
			makecreature(2, CREATURE_GUARDDOG);
			break;
		case SITE_GOVERNMENT_ARMYBASE:
			makecreature(0, CREATURE_MILITARYPOLICE);
			makecreature(1, CREATURE_MILITARYPOLICE);
			break;
		case SITE_BUSINESS_BARANDGRILL:
		case SITE_RESIDENTIAL_BOMBSHELTER:
		case SITE_OUTDOOR_BUNKER:
			if (LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE, getCurrentSite()) == RENTING_CCS)
			{
				makecreature(0, CREATURE_CCS_VIGILANTE);
				makecreature(1, CREATURE_CCS_VIGILANTE);
			}
		}
	}
}
void lock_or_unlock_adjacent_doors(const bool rejected) {


	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++)
		{
			if (levelmap[loc_coord.locx + dx][loc_coord.locy + dy][loc_coord.locz].flag & SITEBLOCK_DOOR)
			{
				if (rejected)
				{
					levelmap[loc_coord.locx + dx][loc_coord.locy + dy][loc_coord.locz].flag |= SITEBLOCK_LOCKED;
					levelmap[loc_coord.locx + dx][loc_coord.locy + dy][loc_coord.locz].flag |= SITEBLOCK_CLOCK;
				}
				else levelmap[loc_coord.locx + dx][loc_coord.locy + dy][loc_coord.locz].flag &= ~SITEBLOCK_DOOR;
			}
		}
	}
}
void special_security(bool metaldetect)
{
	char autoadmit = 0;
	emptyEncounter();
	spawn_security();
	{
		autoadmit = doWeHaveASleeperHere(getCurrentSite());
		string name = getSleeperSecurityName(getCurrentSite(), encounter[0].type);
		if (name.size()) {
			autoadmit = 2;
			encounter[0].rename(name);
			encounter[0].align = 1;
			encounter[0].make_cantbluff_one();
		}
	}
	//clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(16, 1);
	if (isThereASiteAlarm())
	{
		addstrAlt(CONST_mapspecials124, gamelog);
		gamelog.newline();
		levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = SPECIAL_NONE;
		return;
	}
	else if (autoadmit)
	{
		addstrAlt(CONST_mapspecials125, gamelog);
		metaldetect = false;
		gamelog.newline();
		levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = SPECIAL_SECURITY_SECONDVISIT;
	}
	else
	{
		if (metaldetect) addstrAlt(CONST_mapspecials126, gamelog);
		else addstrAlt(CONST_mapspecials127, gamelog);
		gamelog.newline();
		levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = SPECIAL_SECURITY_SECONDVISIT;
	}
	printencounter();
	pressAnyKey();
	char rejected = checkActiveSquadForRejection(autoadmit, metaldetect);
	moveAlt(17, 1);
	if (caseRejectionReasons.count(rejected)) {
		set_color_easy(RED_ON_BLACK_BRIGHT);
		addstrAlt(pickrandom(caseRejectionReasons[rejected]), gamelog);
	}
	else {
		switch (rejected)
		{
		case REJECTED_NUDE:
			set_color_easy(RED_ON_BLACK_BRIGHT);
			if (autoadmit) addstrAlt(CONST_mapspecials128, gamelog);
			else addstrAlt(pickrandom(caseREJECTED_NUDE), gamelog);
			gamelog.newline();
			break;
		case REJECTED_WEAPONS:
			set_color_easy(RED_ON_BLACK_BRIGHT);
			if (metaldetect)
			{
				addstrAlt(CONST_mapspecials129, gamelog);
				setSiteAlarmOne();
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
	}
	pressAnyKey();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);

	lock_or_unlock_adjacent_doors(rejected != NOT_REJECTED);

	encounter[0].make_cantbluff_one();
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
	mvaddstrAlt(16, 1, CONST_mapspecials130, gamelog);
	mvaddstrAlt(17, 1, CONST_mapspecials131, gamelog);
	gamelog.newline();
	pressAnyKey();
	clearmessagearea();
	mvaddstrAlt(16, 1, CONST_mapspecials132, gamelog);
	mvaddstrAlt(17, 1, CONST_mapspecials133, gamelog);
	gamelog.newline();
	pressAnyKey();
	{
		string sleeperBanker = getSleeperBankerName(getCurrentSite());
		if (sleeperBanker.size()) {
			clearmessagearea();
			mvaddstrAlt(16, 1, string_sleeper, gamelog);
			addstrAlt(sleeperBanker, gamelog);
			addstrAlt(CONST_mapspecials134, gamelog);
			mvaddstrAlt(17, 1, CONST_mapspecials135, gamelog);
			gamelog.newline();
			pressAnyKey();
		}
	}
	while (true)
	{
		clearmessagearea();
		mvaddstrAlt(16, 1, CONST_mapspecials136);
		int c = getkeyAlt();
		if (c == 'y')
		{
			clearmessagearea();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(16, 1, CONST_mapspecials137, gamelog);
			mvaddstrAlt(17, 1, CONST_mapspecials138, gamelog);
			gamelog.newline();
			pressAnyKey();
			UnlockAttempt actualy = unlock(UNLOCK_VAULT);
			if (actualy != UNLOCKED)
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 1, CONST_mapspecials139, gamelog);
				mvaddstrAlt(17, 1, CONST_mapspecials140, gamelog);
				gamelog.newline();
				pressAnyKey();
				levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
			}
			else
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 1, CONST_mapspecials141, gamelog);
				mvaddstrAlt(17, 1, CONST_mapspecials142, gamelog);
				gamelog.newline();
				pressAnyKey();
				actualy = hack(HACK_VAULT);
				if (actualy != UNLOCKED)
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16, 1, CONST_mapspecials143, gamelog);
					gamelog.newline();
					pressAnyKey();
					levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
				}
				else
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16, 1, CONST_mapspecials144, gamelog);
					mvaddstrAlt(17, 1, CONST_mapspecials145, gamelog);
					gamelog.newline();
					pressAnyKey();
					DeprecatedCreature *manager = 0;
					bool canbreakin = false;
					for (int s = 0; s < 6; s++)
					{
						DeprecatedCreature *c = activesquad->squad[s];
						if (c)
						{
							if (c->type == CREATURE_BANK_MANAGER)
							{
								manager = c;
								if (c->joindays < 30 && !(c->flag & CREATUREFLAG_KIDNAPPED))
								{
									clearmessagearea();
									set_color_easy(WHITE_ON_BLACK_BRIGHT);
									mvaddstrAlt(16, 1, c->getNameAndAlignment().name, gamelog);
									addstrAlt(CONST_mapspecials146, gamelog);
									gamelog.newline();
									pressAnyKey();
									canbreakin = true;
									break;
								}
							}
							if (c->is_holding_body() && c->get_prisoner_type() == CREATURE_BANK_MANAGER)
							{
								clearmessagearea();
								set_color_easy(WHITE_ON_BLACK_BRIGHT);
								mvaddstrAlt(16, 1, CONST_mapspecials147, gamelog);
								gamelog.newline();
								pressAnyKey();
								canbreakin = true;
								break;
							}
						}
					}
					if (!canbreakin)
					{
						string sleeperBankRobber = haveSleeperBankerCrackSafe(getCurrentSite(), activesquad->squad[0]->base);
						if (sleeperBankRobber.size()) {
							clearmessagearea();
							set_color_easy(WHITE_ON_BLACK_BRIGHT);
							mvaddstrAlt(16, 1, string_sleeper, gamelog);
							addstrAlt(sleeperBankRobber, gamelog);
							addstrAlt(CONST_mapspecials148, gamelog);
							mvaddstrAlt(17, 1, CONST_mapspecials149, gamelog);
							gamelog.newline();
							pressAnyKey();
							canbreakin = true;
						}
					}
					if (canbreakin)
					{
						criminalizeparty(LAWFLAG_BANKROBBERY);
						sitecrime += 20;
						sitestory->crime.push_back(CRIME_BANKVAULTROBBERY);
						levelmap[loc_coord.locx + 1][loc_coord.locy][loc_coord.locz].flag &= ~SITEBLOCK_DOOR;
						levelmap[loc_coord.locx - 1][loc_coord.locy][loc_coord.locz].flag &= ~SITEBLOCK_DOOR;
						levelmap[loc_coord.locx][loc_coord.locy + 1][loc_coord.locz].flag &= ~SITEBLOCK_DOOR;
						levelmap[loc_coord.locx][loc_coord.locy - 1][loc_coord.locz].flag &= ~SITEBLOCK_DOOR;
						levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
					}
					else
					{
						if (manager)
						{
							clearmessagearea();
							set_color_easy(WHITE_ON_BLACK_BRIGHT);
							mvaddstrAlt(16, 1, manager->getNameAndAlignment().name, gamelog);
							addstrAlt(CONST_mapspecials150, gamelog);
							gamelog.newline();
							pressAnyKey();
						}
						else
						{
							clearmessagearea();
							set_color_easy(WHITE_ON_BLACK_BRIGHT);
							mvaddstrAlt(16, 1, CONST_mapspecials151, gamelog);
							gamelog.newline();
							pressAnyKey();
						}
					}
				}
			}
			if (actualy != NEVERMIND)
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
	if (isThereASiteAlarm() || sitealienate ||
		LocationsPool::getInstance().isThereASiegeHere(getCurrentSite()))
	{
		clearmessagearea(false);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, CONST_mapspecials152, gamelog);
		gamelog.newline();
		levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
		pressAnyKey();
	}
	else
	{
		clearmessagearea(false);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, CONST_mapspecials153, gamelog);
		gamelog.newline();
		levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
		pressAnyKey();
		emptyEncounter();
		makecreature(0, CREATURE_BANK_TELLER);
	}
}
void special_bank_money()
{
	static int swat_counter = 0;
	clearmessagearea(false);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_mapspecials154, gamelog);
	gamelog.newline();
	levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
	giveActiveSquadMoney(20000);
	sitecrime += 20;
	if (postalarmtimer <= 80) swat_counter = 0;
	if (!isThereASiteAlarm() && sitealarmtimer != 0) sitealarmtimer = 0;
	else if (!isThereASiteAlarm() && !LCSrandom(2)) setSiteAlarmOne();
	else if (isThereASiteAlarm() && postalarmtimer <= 60) postalarmtimer += 20;
	else if (isThereASiteAlarm() && postalarmtimer <= 80 && LCSrandom(2)) postalarmtimer = 81;
	else if (isThereASiteAlarm() && postalarmtimer > 80 && LCSrandom(2) && swat_counter < 2)
	{
		pressAnyKey();
		if (swat_counter > 0)
			mvaddstrAlt(17, 1, CONST_mapspecials155, gamelog);
		else
			mvaddstrAlt(17, 1, CONST_mapspecials156, gamelog);
		gamelog.newline();
		swat_counter++;
		int swatnum = 9;
		fillEncounter(CREATURE_SWAT, swatnum);
	}
	pressAnyKey();
}
void special_oval_office()
{
	// Clear entire Oval Office area
	for (int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++)
		{
			if (levelmap[loc_coord.locx + dx][loc_coord.locy + dy][loc_coord.locz].special == SPECIAL_OVAL_OFFICE_NW ||
				levelmap[loc_coord.locx + dx][loc_coord.locy + dy][loc_coord.locz].special == SPECIAL_OVAL_OFFICE_NE ||
				levelmap[loc_coord.locx + dx][loc_coord.locy + dy][loc_coord.locz].special == SPECIAL_OVAL_OFFICE_SW ||
				levelmap[loc_coord.locx + dx][loc_coord.locy + dy][loc_coord.locz].special == SPECIAL_OVAL_OFFICE_SE)
			{
				levelmap[loc_coord.locx + dx][loc_coord.locy + dy][loc_coord.locz].special = -1;
			}
		}
	if (isThereASiteAlarm())
	{
		emptyEncounter();
		clearmessagearea(false);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, CONST_mapspecials157, gamelog);
		printsitemap(loc_coord.locx, loc_coord.locy, loc_coord.locz);
		pressAnyKey();
		mvaddstrAlt(17, 1, CONST_mapspecials158, gamelog);
		gamelog.newline();
		for (int e = 0; e < 6; e++)makecreature(e, CREATURE_SECRET_SERVICE);
		printencounter();
		pressAnyKey();
		enemyattack();
		creatureadvance();
	}
	else
	{
		emptyEncounter();
		clearmessagearea(false);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, CONST_mapspecials159, gamelog);
		gamelog.newline();
		printsitemap(loc_coord.locx, loc_coord.locy, loc_coord.locz);
		for (int e = 0; e < 2; e++)makecreature(e, CREATURE_SECRET_SERVICE);
		spawnPresident();
		printencounter();
		pressAnyKey();
	}
}
void special_ccs_boss()
{
	if (isThereASiteAlarm() || sitealienate ||
		LocationsPool::getInstance().isThereASiegeHere(getCurrentSite()))
	{
		clearmessagearea(false);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, CONST_mapspecials160, gamelog);
		gamelog.newline();
		levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
		pressAnyKey();
		emptyEncounter();
		makecreature(0, CREATURE_CCS_ARCHCONSERVATIVE);
		makecreature(1, CREATURE_CCS_VIGILANTE);
		makecreature(2, CREATURE_CCS_VIGILANTE);
		makecreature(3, CREATURE_CCS_VIGILANTE);
		makecreature(4, CREATURE_CCS_VIGILANTE);
		makecreature(5, CREATURE_CCS_VIGILANTE);
	}
	else
	{
		clearmessagearea(false);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, CONST_mapspecials161, gamelog);
		gamelog.newline();
		levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special = -1;
		pressAnyKey();
		emptyEncounter();
		makecreature(0, CREATURE_CCS_ARCHCONSERVATIVE);
	}
}