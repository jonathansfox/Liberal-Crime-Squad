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
extern char newscherrybusted;
extern vector<Location *> location;
extern short exec[EXECNUM];
 vector<vector<string>> no_free_speech_flirt;
 vector<vector<string>> pickupLines;
 vector<string> dog_rejection;
 vector<string> mutant_rejection;
 vector<string> that_is_disturbing;
 vector<string> that_is_not_disturbing;
 vector<vector<string>> lovingly_talk_to_dog;
 vector<vector<string>> normal_talk_to_dog;
 vector<vector<string>> lovingly_talk_to_mutant;
 vector<vector<string>> normal_talk_to_mutant;
 vector<string> robbing_bank;
 vector<string> teller_gestures;
 vector<string> teller_complies;
 vector<string> come_at_me_bro;
 vector<string> backs_off;
 vector<string> threaten_hostage;
 vector<string> please_spare_hostage;
 vector<string> who_cares_about_hostage;
 vector<string> hostage_negotiation;
 vector<string> please_no_more;
 vector<string> let_hostages_go;
 vector<string> go_ahead_and_die;
 vector<string> agree_to_release_hostages;
string while_naked;
char heyMisterDog(Creature &a, Creature &tk);
char heyMisterMonster(Creature &a, Creature &tk);
char talkInCombat(Creature &a, Creature &tk);
char talkToBankTeller(Creature &a, Creature &tk);
char talkToGeneric(Creature &a, Creature &tk);
char wannaHearSomethingDisturbing(Creature &a, Creature &tk);
char talkAboutIssues(Creature &a, Creature &tk);
char doYouComeHereOften(Creature &a, Creature &tk);
char heyINeedAGun(Creature &a, Creature &tk);
char heyIWantToRentARoom(Creature &a, Creature &tk);
char heyIWantToCancelMyRoom(Creature &a, Creature &tk);
typedef map<short, string> shortAndString;
shortAndString conservativeLegalArgument;
typedef map<short, vector<string>> shortAndTwoStrings;
 shortAndTwoStrings talkAboutTheIssues;
 shortAndString youAreStupidTalkAboutIssues;
 shortAndString issueTooLiberal;
 string saysComma;
 string respondsComma;
 string colonSpace;
 extern string singleDot;
/* bluff, date, issues */
char talk(Creature &a, const int t)
{
	Creature &tk = encounter[t];
	// TALKING TO DOGS
	if (tk.type == CREATURE_GUARDDOG && tk.align != ALIGN_LIBERAL)
	{
		return heyMisterDog(a, tk);
	}
	// TALKING TO MONSTERS
	if (tk.type == CREATURE_GENETIC && tk.align != ALIGN_LIBERAL)
	{
		return heyMisterMonster(a, tk);
	}
	// BLUFFING
	if ((sitealarm || location[cursite]->siege.siege) && tk.enemy())
	{
		return talkInCombat(a, tk);
	}
	return talkToGeneric(a, tk);
}
char talkToBankTeller(Creature &a, Creature &tk)
{
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK);
	/*moveAlt(9,1);
	addstrAlt(a.name);
	addstrAlt(" prepares to rob the bank:");*/
	const bool is_naked = a.is_naked() && a.animalgloss != ANIMALGLOSS_ANIMAL;
	moveAlt(11, 1);
	addstrAlt("A - Quietly pass the teller a robbery note");
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
	moveAlt(12, 1);
	addstrAlt("B - Threaten bystanders and demand access to the vault");
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
	moveAlt(13, 1);
	addstrAlt("C - On second thought, don't rob the bank");
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
	int c;
	do c = getkey(); while (c<'a'&&c>'c');
	switch (c)
	{
	case 'a':
		clearcommandarea(); clearmessagearea(); clearmaparea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(9, 1);
		addstrAlt(a.name, gamelog);
		addstrAlt(" slips the teller a note: ", gamelog);
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		moveAlt(10, 1);
		addstrAlt(pickrandom(robbing_bank), gamelog);
		gamelog.newline();
		getkey();
		if (location[cursite]->highsecurity)
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			moveAlt(11, 1);
			addstrAlt("The bank teller reads the note, ", gamelog);
			addstrAlt(pickrandom(teller_gestures), gamelog);
			moveAlt(12, 1);
			addstrAlt("and dives for cover as the guards move in on the squad!", gamelog);
			gamelog.newline();
			getkey();
			sitealarm = 1;
			criminalize(a, LAWFLAG_BANKROBBERY);
			sitestory->crime.push_back(CRIME_BANKTELLERROBBERY);
			sitecrime += 30;
			makecreature(encounter[0], CREATURE_MERC);
			makecreature(encounter[1], CREATURE_MERC);
			makecreature(encounter[2], CREATURE_MERC);
			makecreature(encounter[3], CREATURE_MERC);
		}
		else
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			moveAlt(11, 1);
			addstrAlt("The bank teller reads the note, ", gamelog);
			addstrAlt(pickrandom(teller_complies), gamelog);
			moveAlt(12, 1);
			addstrAlt("and slips several bricks of cash into the squad's bag.", gamelog);
			gamelog.newline();
			getkey();
			criminalize(a, LAWFLAG_BANKROBBERY);
			sitestory->crime.push_back(CRIME_BANKTELLERROBBERY);
			sitecrime += 30;
			sitealarmtimer = 0;
			activesquad->loot.push_back(new Money(5000));
		}
		tk.cantbluff = 1;
		return 1;
	case 'b':
	{
		clearcommandarea(); clearmessagearea(); clearmaparea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		Creature *armed_liberal = NULL;
		for (int i = 0; i < 6; i++)
		{
			if (activesquad->squad[i] &&
				activesquad->squad[i]->get_weapon().is_threatening())
			{
				armed_liberal = activesquad->squad[i];
				break;
			}
		}
		if (armed_liberal)
		{
			moveAlt(9, 1);
			addstrAlt(armed_liberal->name, gamelog);
			addstrAlt(" brandishes the ", gamelog);
			addstrAlt(armed_liberal->get_weapon().get_shortname(0), gamelog);
			addstrAlt(singleDot, gamelog);
			gamelog.newline();
			getkey();
			clearmessagearea();
		}
		moveAlt(10, 1);
		addstrAlt(a.name, gamelog);
		addstrAlt(saysComma, gamelog);
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		moveAlt(11, 1);
		addstrAlt("\"", gamelog);
		addstrAlt(slogan, gamelog);
		gamelog.record(singleSpace);
		moveAlt(12, 1);
		addstrAlt("OPEN THE VAULT, NOW!\"", gamelog);
		gamelog.newline();
		getkey();
		const int roll = a.skill_roll(SKILL_PERSUASION);
		int difficulty = DIFFICULTY_VERYEASY;
		if (armed_liberal == NULL)
			difficulty += 12;
		if (location[cursite]->highsecurity > 0)
			difficulty += 12;
		clearcommandarea(); clearmessagearea(); clearmaparea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		if (roll < difficulty)
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			moveAlt(9, 1);
			addstrAlt("The bank teller and dives for cover as ", gamelog);
			moveAlt(10, 1);
			addstrAlt("guards move in on the squad!", gamelog);
			gamelog.newline();
			getkey();
			sitealarm = 1;
			sitealienate = 2;
			criminalizeparty(LAWFLAG_BANKROBBERY);
			sitestory->crime.push_back(CRIME_BANKSTICKUP);
			sitecrime += 50;
			CreatureTypes guard = CREATURE_SECURITYGUARD;
			if (location[cursite]->highsecurity>0) guard = CREATURE_MERC;
			makecreature(encounter[0], guard);
			makecreature(encounter[1], guard);
			makecreature(encounter[2], guard);
			makecreature(encounter[3], guard);
			makecreature(encounter[4], guard);
			makecreature(encounter[5], guard);
		}
		else
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			moveAlt(9, 1);
			addstrAlt("The bank employees hesitantly cooperate!", gamelog);
			gamelog.newline();
			getkey();
			moveAlt(10, 1);
			addstrAlt("The vault is open!", gamelog);
			gamelog.newline();
			getkey();
			criminalizeparty(LAWFLAG_BANKROBBERY);
			sitestory->crime.push_back(CRIME_BANKSTICKUP);
			sitecrime += 50;
			sitealarm = 1;
			sitealienate = 2;
			for (int x = 0; x < MAPX; x++)
				for (int y = 0; y < MAPY; y++)
					for (int z = 0; z < MAPZ; z++)
					{
						levelmap[x][y][z].flag &= ~SITEBLOCK_LOCKED;
						if (levelmap[x][y][z].flag & SITEBLOCK_METAL)
							levelmap[x][y][z].flag &= ~SITEBLOCK_DOOR;
						if (levelmap[x][y][z].special == SPECIAL_BANK_VAULT)
							levelmap[x][y][z].special = SPECIAL_NONE;
					}
			encounter[0].exists = false;
		}
	}
	default:
	case 'c':
		return 0;
	}
}
char talkToGeneric(Creature &a, Creature &tk)
{
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(9, 1);
	addstrAlt(a.name);
	addstrAlt(" talks to ");
	switch (tk.align)
	{
	case ALIGN_CONSERVATIVE:
		set_color_easy(RED_ON_BLACK_BRIGHT);
		break;
	case ALIGN_LIBERAL:
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		break;
	case ALIGN_MODERATE:
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		break;
	}
	addstrAlt(tk.name);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	add_age(tk);
	addstrAlt(":");
	const bool is_naked = a.is_naked() && a.animalgloss != ANIMALGLOSS_ANIMAL;
	set_color_easy(WHITE_ON_BLACK);
	moveAlt(11, 1);
	addstrAlt("A - Strike up a conversation about politics");
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
	moveAlt(12, 1);
	if (tk.can_date(a))set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	addstrAlt("B - Drop a pickup line");
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
	set_color_easy(WHITE_ON_BLACK);
	moveAlt(13, 1);
	addstrAlt("C - On second thought, don't say anything");
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
	if (tk.type == CREATURE_LANDLORD&&location[cursite]->renting == -1)
	{
		moveAlt(14, 1);
		addstrAlt("D - Rent a room");
		if (is_naked)addstrAlt(while_naked);
		addstrAlt(singleDot);
	}
	else if (tk.type == CREATURE_LANDLORD&&location[cursite]->renting > 0)
	{
		moveAlt(14, 1);
		addstrAlt("D - Stop renting a room");
		if (is_naked)addstrAlt(while_naked);
		addstrAlt(singleDot);
	}
	else if (tk.type == CREATURE_GANGMEMBER || tk.type == CREATURE_MERC)
	{
		moveAlt(14, 1);
		addstrAlt("D - Buy weapons");
		if (is_naked)addstrAlt(while_naked);
		addstrAlt(singleDot);
	}
	else if (tk.type == CREATURE_BANK_TELLER)
	{
		moveAlt(14, 1);
		addstrAlt("D - Rob the bank");
		if (is_naked)addstrAlt(while_naked);
		addstrAlt(singleDot);
	}
	while (true)
	{
		const int c = getkey();
		switch (c)
		{
		case 'a':
			return wannaHearSomethingDisturbing(a, tk);
		case 'b':
			if (!tk.can_date(a)) break;
			return doYouComeHereOften(a, tk);
		case 'c':
			return 0;
		case 'd':
			if (tk.type == CREATURE_LANDLORD&&location[cursite]->renting == -1)
				return heyIWantToRentARoom(a, tk);
			else if (tk.type == CREATURE_LANDLORD && location[cursite]->renting > 0)
				return heyIWantToCancelMyRoom(a, tk);
			else if (tk.type == CREATURE_GANGMEMBER || tk.type == CREATURE_MERC)
				return heyINeedAGun(a, tk);
			else if (tk.type == CREATURE_BANK_TELLER)
				return talkToBankTeller(a, tk);
			break;
		}
	}
}
char heyIWantToCancelMyRoom(Creature &a, Creature &tk)
{
	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(9, 1);
	addstrAlt(a.name, gamelog);
	addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	moveAlt(10, 1);
	addstrAlt("\"I'd like cancel my room.\"", gamelog);
	gamelog.newline();
	getkey();
	const bool is_naked = a.is_naked() && a.animalgloss != ANIMALGLOSS_ANIMAL;
	if (is_naked)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(12, 1);
		addstrAlt(tk.name, gamelog);
		addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		moveAlt(13, 1);
		addstrAlt("\"Put some clothes on before I call the cops.\"", gamelog);
		gamelog.newline();
		getkey();
		return 1;
	}
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(12, 1);
	addstrAlt(tk.name, gamelog);
	addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	moveAlt(13, 1);
	addstrAlt("\"Alright. Please clear out your room.\"", gamelog);
	gamelog.newline();
	getkey();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(15, 1);
	addstrAlt("<Your possessions at this location have been moved to the shelter.>", gamelog);
	gamelog.newline();
	getkey();
	location[cursite]->renting = RENTING_NOCONTROL;
	//MOVE ALL ITEMS AND SQUAD MEMBERS
	const int hs = find_homeless_shelter(cursite);
	for (int p = 0; p < len(pool); p++)
	{
		if (pool[p]->location == cursite)pool[p]->location = hs;
		if (pool[p]->base == cursite)pool[p]->base = hs;
	}
	location[hs]->getloot(location[cursite]->loot);
	location[cursite]->compound_walls = 0;
	location[cursite]->compound_stores = 0;
	location[cursite]->front_business = -1;
	return 1;
}
char heyIWantToRentARoom(Creature &a, Creature &tk)
{
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(9, 1); addstrAlt(a.name, gamelog); addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	moveAlt(10, 1);
	addstrAlt("\"I'd like to rent a room.\"", gamelog);
	gamelog.newline();
	getkey();
	const bool is_naked = a.is_naked() && a.animalgloss != ANIMALGLOSS_ANIMAL;
	if (is_naked)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(12, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		moveAlt(13, 1);
		addstrAlt("\"Put some clothes on before I call the cops.\"", gamelog);
		gamelog.newline();
		getkey();
		return 1;
	}
	int rent;
	switch (location[cursite]->type)
	{
	default:rent = 200; break;
	case SITE_RESIDENTIAL_APARTMENT:rent = 650; break;
	case SITE_RESIDENTIAL_APARTMENT_UPSCALE:rent = 1500; break;
	}
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(12, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	moveAlt(13, 1);
	addstrAlt("\"It'll be $", gamelog);
	addstrAlt(rent, gamelog);
	addstrAlt(" a month.", gamelog);
	gamelog.newline();
	moveAlt(14, 1);
	addstrAlt("I'll need $", gamelog);
	addstrAlt(rent, gamelog);
	addstrAlt(" now as a security deposit.\"", gamelog);
	gamelog.newline();
	getkey();
	clearcommandarea(); clearmessagearea(); clearmaparea();
	while (true)
	{
		int c = 'a';
		if (ledger.get_funds() < rent)set_color_easy(BLACK_ON_BLACK_BRIGHT);
		moveAlt(11, 1);
		addstrAlt("A - Accept.");
		set_color_easy(WHITE_ON_BLACK);
		moveAlt(12, 1);
		addstrAlt("B - Decline.");
		moveAlt(13, 1);
		addstrAlt("C - Threaten the landlord.");
		c = getkey();
		switch (c)
		{
		case 'a': // Accept rent deal
			if (ledger.get_funds() < rent) break;
			clearcommandarea(); clearmessagearea(); clearmaparea();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			moveAlt(9, 1); addstrAlt(a.name, gamelog); addstrAlt(saysComma, gamelog);
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			moveAlt(10, 1);
			addstrAlt("\"I'll take it.\"", gamelog);
			gamelog.newline();
			getkey();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			moveAlt(12, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			moveAlt(13, 1);
			addstrAlt("\"Rent is due by the third of every month.", gamelog);
			gamelog.newline();
			moveAlt(14, 1);
			addstrAlt("We'll start next month.\"", gamelog);
			gamelog.newline();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			addstrAlt(" <turns away>");
			getkey();
			ledger.subtract_funds(rent, EXPENSE_RENT);
			location[cursite]->renting = rent;
			location[cursite]->newrental = 1;
			basesquad(activesquad, cursite);
			return 1;
		case 'b': // Refuse rent deal
			clearcommandarea(); clearmessagearea(); clearmaparea();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			moveAlt(9, 1); addstrAlt(a.name, gamelog); addstrAlt(saysComma, gamelog);
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			moveAlt(10, 1);
			addstrAlt("\"Whoa, I was looking for something cheaper.\"", gamelog);
			gamelog.newline();
			getkey();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			moveAlt(12, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			moveAlt(13, 1);
			addstrAlt("\"Not my problem...\"", gamelog);
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			addstrAlt(" <turns away>", gamelog);
			gamelog.newline();
			getkey();
			return 1;
		case 'c': // Threaten landlord
			clearcommandarea(); clearmessagearea(); clearmaparea();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			Creature *armed_liberal = NULL;
			for (int i = 0; i < 6; i++)
			{
				if (activesquad->squad[i] &&
					activesquad->squad[i]->get_weapon().is_threatening())
				{
					armed_liberal = activesquad->squad[i];
					break;
				}
			}
			if (armed_liberal)
			{
				moveAlt(9, 1);
				addstrAlt(armed_liberal->name, gamelog);
				addstrAlt(" brandishes the ", gamelog);
				addstrAlt(armed_liberal->get_weapon().get_shortname(0), gamelog);
				addstrAlt(singleDot, gamelog);
				gamelog.newline();
				getkey();
				clearmessagearea();
			}
			moveAlt(9, 1);
			addstrAlt(a.name, gamelog);
			addstrAlt(saysComma, gamelog);
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			moveAlt(10, 1);
			addstrAlt("\"What's the price for the Liberal Crime Squad?\"", gamelog);
			gamelog.newline();
			getkey();
			const int roll = a.skill_roll(SKILL_PERSUASION);
			int difficulty = DIFFICULTY_FORMIDABLE;
			if (newscherrybusted == false)
				difficulty += 6;
			if (armed_liberal == NULL)
				difficulty += 6;
			if (roll < difficulty - 1)
			{
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				moveAlt(12, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
				set_color_easy(CYAN_ON_BLACK_BRIGHT);
				moveAlt(13, 1);
				addstrAlt("\"I think you'd better leave.\"", gamelog);
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				addstrAlt(" <crosses arms>", gamelog);
				gamelog.newline();
				getkey();
				tk.cantbluff = 1;
				return 1;
			}
			else
			{
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				moveAlt(12, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
				set_color_easy(CYAN_ON_BLACK_BRIGHT);
				moveAlt(13, 1);
				addstrAlt("\"Jesus... it's yours...\"", gamelog);
				gamelog.newline();
				getkey();
				int rent;
				// Either he calls the cops...
				if (roll < difficulty)
				{
					for (int i = 0; i < 6; i++)
						if (activesquad->squad[i])
							criminalize(*(activesquad->squad[i]), LAWFLAG_EXTORTION);
					location[cursite]->siege.timeuntillocated = 2;
					rent = 10000000; // Yeah he's kicking you out next month
				}
				// ...or it's yours for free
				else rent = 0;
				location[cursite]->renting = rent;
				location[cursite]->newrental = true;
				basesquad(activesquad, cursite);
				return 1;
			}
		}
	}
}
char heyINeedAGun(Creature &a, Creature &tk)
{
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(9, 1); addstrAlt(a.name, gamelog); addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	moveAlt(10, 1);
	addstrAlt("\"Hey, I need a gun.\"", gamelog);
	gamelog.newline();
	getkey();
	const bool is_naked = a.is_naked() && a.animalgloss != ANIMALGLOSS_ANIMAL;
	if (is_naked)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(12, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		moveAlt(13, 1);
		addstrAlt("\"Jesus...\"", gamelog);
		gamelog.newline();
		getkey();
		return 1;
	}
	// IsaacG Migrate Strings
	if (a.get_armor().get_itemtypename() == tag_ARMOR_POLICEUNIFORM ||
		a.get_armor().get_itemtypename() == tag_ARMOR_POLICEARMOR ||
		a.get_armor().get_itemtypename() == tag_ARMOR_SWATARMOR ||
		(lawList[LAW_POLICEBEHAVIOR] == -2 && lawList[LAW_DEATHPENALTY] == -2 &&
			a.get_armor().get_itemtypename() == tag_ARMOR_DEATHSQUADUNIFORM))
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(12, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		moveAlt(13, 1);
		addstrAlt("\"I don't sell guns, officer.\"", gamelog);
		gamelog.newline();
		getkey();
		return 1;
	}
	if (sitealarm != 0)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(12, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		moveAlt(13, 1);
		addstrAlt("\"We can talk when things are calm.\"", gamelog);
		gamelog.newline();
		getkey();
		return 1;
	}
	switch (location[cursite]->type)
	{
	case SITE_OUTDOOR_BUNKER:
	case SITE_BUSINESS_CRACKHOUSE:
	case SITE_BUSINESS_BARANDGRILL:
	case SITE_BUSINESS_ARMSDEALER:
	case SITE_RESIDENTIAL_TENEMENT:
	case SITE_RESIDENTIAL_BOMBSHELTER:
	case SITE_RESIDENTIAL_SHELTER:
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(12, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		moveAlt(13, 1);
		addstrAlt("\"What exactly do you need?\"", gamelog);
		gamelog.newline();
		getkey();
		armsdealer(cursite);
		return 1;
	default:
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(12, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		moveAlt(13, 1);
		addstrAlt("\"Uhhh... not a good place for this.\"", gamelog);
		gamelog.newline();
		getkey();
		return 1;
	}
}
char wannaHearSomethingDisturbing(Creature &a, Creature &tk)
{
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(9, 1); addstrAlt(a.name, gamelog); addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	moveAlt(10, 1);
	addstrAlt("\"Do you want to hear something disturbing?\"", gamelog);
	gamelog.newline();
	getkey();
	bool interested = tk.talkreceptive();
	if (!interested && a.skill_check(SKILL_PERSUASION, DIFFICULTY_AVERAGE))
		interested = true;
	if ((tk.animalgloss == ANIMALGLOSS_ANIMAL&&tk.align != ALIGN_LIBERAL) ||
		tk.animalgloss == ANIMALGLOSS_TANK)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(12, 1); addstrAlt(tk.name, gamelog);
		switch (tk.type)
		{
		case CREATURE_TANK: addstrAlt(" rumbles disinterestedly.", gamelog); break;
		case CREATURE_GUARDDOG: addstrAlt(" barks.", gamelog); break;
		default: addstrAlt(" doesn't understand.", gamelog); break;
		}
		gamelog.newline();
		getkey();
		return 1;
	}
	else if (strcmp(tk.name, "Prisoner") != 0 && interested)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(12, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		moveAlt(13, 1);
		addstrAlt("\"What?\"", gamelog);
		gamelog.newline();
		getkey();
		return talkAboutIssues(a, tk);
	}
	else
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(12, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		moveAlt(13, 1);
		if (strcmp(tk.name, "Prisoner") == 0)
		{
			if (tk.align == ALIGN_LIBERAL)
				addstrAlt("\"Now's not the time!\"", gamelog);
			else addstrAlt("\"Leave me alone.\"", gamelog);
		}
		else addstrAlt("\"No.\"", gamelog);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		addstrAlt(" <turns away>", gamelog);
		gamelog.newline();
		getkey();
		return 1;
	}
}
char doYouComeHereOften(Creature &a, Creature &tk)
{
	int y = 12;
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(9, 1); addstrAlt(a.name, gamelog); addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	moveAlt(10, 1);
	vector<string> selected_flirt;
	int line;
	if (lawList[LAW_FREESPEECH] == -2)
	{
		selected_flirt = pickrandom(no_free_speech_flirt);
	}
	else
	{
		selected_flirt = pickrandom(pickupLines);
		/*int current_flirt = LCSrandom(pickupLines.size);
		for(int i = 0; i < 5; i++){
		selected_flirt.push_back(pickupLines[current_flirt][i]);
		}*/
	}
	addstrAlt(selected_flirt[0], gamelog);
	if (selected_flirt[1] != "") {
		moveAlt(11, 1); y++;
		addstrAlt(selected_flirt[1], gamelog);
	}
	gamelog.newline();
	getkey();
	bool succeeded = false;
	int difficulty = DIFFICULTY_HARD;
	if (tk.type == CREATURE_CORPORATE_CEO)
		difficulty = DIFFICULTY_HEROIC;
	const bool is_naked = a.is_naked() && a.animalgloss != ANIMALGLOSS_ANIMAL;
	if (is_naked) difficulty -= 4;
	if (a.skill_check(SKILL_SEDUCTION, difficulty))
		succeeded = true;
	if ((tk.animalgloss == ANIMALGLOSS_ANIMAL&&lawList[LAW_ANIMALRESEARCH] != 2 && a.animalgloss != ANIMALGLOSS_ANIMAL) ||
		tk.animalgloss == ANIMALGLOSS_TANK)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(y++, 1); addstrAlt(tk.name, gamelog);
		switch (tk.type)
		{
		case CREATURE_TANK:
			addstrAlt(" shakes its turret a firm 'no'.", gamelog);
			break;
		case CREATURE_GUARDDOG:
			addstrAlt(saysComma, gamelog);
			moveAlt(y, 1);
			set_color_easy(RED_ON_BLACK_BRIGHT);
			addstrAlt(pickrandom(dog_rejection), gamelog);
			tk.align = ALIGN_CONSERVATIVE;
			tk.cantbluff = 1;
			break;
		case CREATURE_GENETIC:
			addstrAlt(saysComma, gamelog);
			moveAlt(y, 1);
			set_color_easy(RED_ON_BLACK_BRIGHT);
			addstrAlt(pickrandom(mutant_rejection), gamelog);
			tk.align = ALIGN_CONSERVATIVE;
			tk.cantbluff = 1;
			break;
		default:
			addstrAlt(" doesn't quite pick up on the subtext.", gamelog);
		}
		gamelog.newline();
		getkey();
		return 1;
	}
	a.train(SKILL_SEDUCTION, LCSrandom(5) + 2);
	//IsaacG Migrate Strings
	if ((a.get_armor().get_itemtypename() == tag_ARMOR_POLICEUNIFORM // Police property on armor? -XML
		|| a.get_armor().get_itemtypename() == tag_ARMOR_POLICEARMOR
		|| a.get_armor().get_itemtypename() == tag_ARMOR_SWATARMOR
		|| (lawList[LAW_POLICEBEHAVIOR] == ALIGN_ARCHCONSERVATIVE && lawList[LAW_DEATHPENALTY] == ALIGN_ARCHCONSERVATIVE
			&& a.get_armor().get_itemtypename() == tag_ARMOR_DEATHSQUADUNIFORM))
		&& tk.type == CREATURE_PROSTITUTE)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(y++, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(RED_ON_BLACK_BRIGHT);
		moveAlt(y++, 1);
		addstrAlt("\"Dirty. You know that's illegal, officer.\"", gamelog);
		gamelog.newline();
		getkey();
		tk.cantbluff = 1;
	}
	else if (succeeded)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(y++, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		moveAlt(y++, 1);
		addstrAlt(selected_flirt[2], gamelog);
		gamelog.newline();
		getkey();
		moveAlt(++y, 1);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(y++, 1);
		addstrAlt(a.name, gamelog);
		addstrAlt(" and ", gamelog);
		addstrAlt(tk.name, gamelog);
		addstrAlt(" make plans for tonight", gamelog);
		if (strcmp(tk.name, "Prisoner") == 0)
		{
			addstrAlt(", and ", gamelog);
			moveAlt(y++, 1);
			addstrAlt(tk.name, gamelog);
			addstrAlt(" breaks for the exit", gamelog);
			criminalize(tk, LAWFLAG_ESCAPED);
		}
		addstrAlt(".  ", gamelog);
		gamelog.newline();
		getkey();
		datest *newd = NULL;
		for (int d = 0; d < len(date); d++)
		{
			if (date[d]->mac_id == a.id)
			{
				newd = date[d];
				break;
			}
		}
		if (newd == NULL)
		{
			newd = new datest;
			newd->mac_id = a.id;
			newd->city = location[a.location]->city;
			date.push_back(newd);
		}
		Creature *newcr = new Creature;
		*newcr = tk;
		newcr->namecreature();
		newcr->location = a.location;
		newcr->base = a.base;
		newd->date.push_back(newcr);
		// TODO this is a pointer subtracting another pointer in order to calculate the index, change it
		delenc(&tk - encounter, 0);
	}
	else
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(y++, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(RED_ON_BLACK_BRIGHT);
		moveAlt(y++, 1);
		if (tk.type == CREATURE_CORPORATE_CEO)
		{
			if (a.gender_liberal != GENDER_MALE)
				addstrAlt("\"I'm a happily married man, sweetie.\"", gamelog);
			else addstrAlt("\"This ain't Brokeback Mountain, son.\"", gamelog);
		}
		else
		{
			addstrAlt(selected_flirt[3], gamelog);
			if (selected_flirt[4] != "") {
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				addstrAlt(selected_flirt[4], gamelog);
			}
		}
		gamelog.newline();
		getkey();
		tk.cantbluff = 1;
	}
	return 1;
}
char talkAboutIssues(Creature &a, Creature &tk)
{
	const int lw = LCSrandom(LAWNUM); // pick a random law to talk about
	bool succeeded = false;
	bool you_are_stupid = false;
	bool issue_too_liberal = false;
	if (!(a.attribute_check(ATTRIBUTE_INTELLIGENCE, DIFFICULTY_EASY)))
		you_are_stupid = true;
	else if (lawList[lw] == ALIGN_ELITELIBERAL && newscherrybusted)
		issue_too_liberal = true;
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(9, 1); addstrAlt(a.name, gamelog); addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	int y = 10;
	moveAlt(y++, 1);
	if (you_are_stupid)
	{
		if (lw == LAW_POLICEBEHAVIOR) {
			if (lawList[LAW_FREESPEECH] == ALIGN_ARCHCONSERVATIVE)
				addstrAlt("\"[The police are not doing their job very well!]\"", gamelog);
			else
				addstrAlt("\"The cops suck!\"", gamelog);
		}
		else {
			addstrAlt(youAreStupidTalkAboutIssues[lw]);
		}
	}
	else if (issue_too_liberal)
	{
		 
		addstrAlt(issueTooLiberal[lw]);
	}
	else
	{
		if (lw == LAW_POLLUTION) {
			addstrAlt("\"Industries that stop at nothing to become more profitable are polluting ", gamelog); moveAlt(y++, 1);
			if (tk.animalgloss == ANIMALGLOSS_ANIMAL) addstrAlt("the environment in ways that hurt not only humans, but animals too.", gamelog);
			else addstrAlt("the environment in ways that hurt not only animals, but people too.", gamelog);
		}
		else {
			addstrAlt(talkAboutTheIssues[lw][0], gamelog);
			moveAlt(y++, 1);
			addstrAlt(talkAboutTheIssues[lw][1], gamelog);
		}
	}
	gamelog.newline();
	getkey();
	int difficulty = DIFFICULTY_VERYEASY;
	if (tk.align == ALIGN_CONSERVATIVE)
		difficulty += 7;
	if (!(tk.talkreceptive()))
		difficulty += 7;
	if (you_are_stupid)
		difficulty += 5;
	if (issue_too_liberal)
		difficulty += 5;
	const bool is_naked = a.is_naked() && a.animalgloss != ANIMALGLOSS_ANIMAL;
	if (is_naked)
		difficulty += 5;
	succeeded = a.skill_check(SKILL_PERSUASION, difficulty);
	// Prisoners never accept to join you, you must liberate them instead
	if (succeeded && strcmp(tk.name, "Prisoner") != 0)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt((++y)++, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		moveAlt(y++, 1);
		if (tk.type == CREATURE_MUTANT&&tk.get_attribute(ATTRIBUTE_INTELLIGENCE, true) < 3)
			addstrAlt("\"Aaaahhh...\"", gamelog);
		else
		{
			switch (LCSrandom(10))
			{
			case 0: addstrAlt("\"Oh, really?\"", gamelog);
				getkey();
				moveAlt(y++, 1);
				set_color_easy(GREEN_ON_BLACK_BRIGHT);
				addstrAlt("\"Yeah, really!\"", gamelog);
				break;
			case 1: addstrAlt("\"You got anything to smoke on you?\"", gamelog);
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				addstrAlt("*cough*", gamelog);
				break;
			default:
				addstrAlt(pickrandom(that_is_disturbing), gamelog);
				break;
			}
		}
		gamelog.newline();
		getkey();
		moveAlt(++y, 1);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		addstrAlt("After more discussion, ", gamelog);
		addstrAlt(tk.name, gamelog);
		addstrAlt(" agrees to come by later tonight.", gamelog);
		gamelog.newline();
		getkey();
		Creature *newcr = new Creature;
		*newcr = tk;
		newcr->namecreature();
		recruitst *newrst = new recruitst;
		newrst->recruit = newcr;
		newrst->recruiter_id = a.id;
		recruit.push_back(newrst);
		// TODO this is a pointer subtracting another pointer in order to calculate the index, change it
		delenc(&tk - encounter, 0);
		return 1;
	}
	else
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt((++y)++, 1); addstrAlt(tk.name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		if (tk.type == CREATURE_MUTANT&&
			tk.get_attribute(ATTRIBUTE_INTELLIGENCE, true) < 3)
		{
			moveAlt(y++, 1);
			addstrAlt("\"Ugh.  Pfft.\"", gamelog);
		}
		else
		{
			if (tk.align == ALIGN_CONSERVATIVE && you_are_stupid)
			{
				moveAlt(y++, 1);
				if (tk.type == CREATURE_GANGUNIT)
					addstrAlt("\"Do you want me to arrest you?\"", gamelog);
				else if (tk.type == CREATURE_DEATHSQUAD)
					addstrAlt("\"If you don't shut up, I'm going to shoot you.\"", gamelog);
				else
				{
					addstrAlt(pickrandom(that_is_not_disturbing), gamelog);
				}
			}
			else if (tk.align != ALIGN_LIBERAL && tk.attribute_check(ATTRIBUTE_WISDOM, DIFFICULTY_AVERAGE))
			{
				moveAlt(y++, 1);
				addstrAlt(conservativeLegalArgument[lw], gamelog);
			}
			else
			{
				moveAlt(y++, 1);
				addstrAlt("\"Whatever.\"", gamelog);
			}
		}
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		addstrAlt(" <turns away>", gamelog);
		gamelog.newline();
		getkey();
		tk.cantbluff = 1;
		return 1;
	}
}
char talkInCombat(Creature &a, Creature &tk)
{
	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(9, 1);
	addstrAlt(a.name, gamelog);
	addstrAlt(" talks to ", gamelog);
	switch (tk.align)
	{
	case ALIGN_CONSERVATIVE: set_color_easy(RED_ON_BLACK_BRIGHT); break;
	case ALIGN_LIBERAL: set_color_easy(GREEN_ON_BLACK_BRIGHT); break;
	case ALIGN_MODERATE: set_color_easy(WHITE_ON_BLACK_BRIGHT); break;
	}
	addstrAlt(tk.name, gamelog);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	addstrAlt(":", gamelog);
	gamelog.newline();
	int c = 0, hostages = 0, weaponhostage = 0;
	bool cop = 0;
	for (int i = 0; i < 6; i++)
	{
		if (activesquad->squad[i] &&
			activesquad->squad[i]->prisoner&&
			activesquad->squad[i]->prisoner->alive&&
			activesquad->squad[i]->prisoner->enemy())
		{
			hostages++;
			if (activesquad->squad[i]->get_weapon().can_threaten_hostages())
				weaponhostage++;
		}
	}
	if (tk.type == CREATURE_COP ||
		tk.type == CREATURE_GANGUNIT ||
		tk.type == CREATURE_DEATHSQUAD ||
		tk.type == CREATURE_SWAT ||
		tk.type == CREATURE_SECURITYGUARD ||
		tk.type == CREATURE_MERC ||
		tk.type == CREATURE_SOLDIER ||
		tk.type == CREATURE_MILITARYPOLICE ||
		tk.type == CREATURE_MILITARYOFFICER ||
		tk.type == CREATURE_SEAL)
	{
		cop = 1;
	}
	set_color_easy(WHITE_ON_BLACK);
	moveAlt(11, 1);
	addstrAlt("A - Intimidate");
	if (!hostages)set_color_easy(BLACK_ON_BLACK_BRIGHT);
	moveAlt(12, 1);
	addstrAlt("B - Threaten hostages");
	if (tk.cantbluff != 2)set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	moveAlt(13, 1);
	addstrAlt("C - Bluff");
	if (cop)set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	moveAlt(14, 1);
	addstrAlt("D - Surrender to authorities");
	set_color_easy(WHITE_ON_BLACK);
	while (true)
	{
		c = getkey();
		if (c == 'a')break;
		if (c == 'b' && hostages)break;
		if (c == 'c' && tk.cantbluff != 2)break;
		if (c == 'd' && cop)break;
	}
	if (c == 'a')
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveSixteenOne();
		addstrAlt(a.name, gamelog);
		addstrAlt(colonSpace, gamelog);
		moveSeventeenOne();
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		switch (LCSrandom(4))
		{
		case 0:
		{   // Formatting the slogan so that it always has quotes around it and punctuation
			if (slogan[0] != '"') addcharAlt('"', gamelog);
			addstrAlt(slogan, gamelog);
			const int last = len(slogan);
			if (last && slogan[last - 1] != '"' && slogan[last - 1] != '!' && slogan[last - 1] != '.' && slogan[last - 1] != '?')
				addcharAlt('!', gamelog);
			if (last && slogan[last - 1] != '"') addcharAlt('"', gamelog);
			if (!sitestory->claimed)
				sitestory->claimed = 1;
			break;
		}
		default:
			addstrAlt(pickrandom(come_at_me_bro), gamelog);
			break;
		}
		getkey();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		for (int e = 0; e < ENCMAX; e++)
		{
			if (encounter[e].exists&&encounter[e].alive&&encounter[e].enemy())
			{
				const int attack = a.juice / 50 + attitude[VIEW_LIBERALCRIMESQUAD] / 10;
				const int defense = encounter[e].attribute_roll(ATTRIBUTE_WISDOM);
				if (attack > defense)
				{
					if (encounter[e].type == CREATURE_COP ||
						encounter[e].type == CREATURE_GANGUNIT ||
						encounter[e].type == CREATURE_SWAT ||
						encounter[e].type == CREATURE_DEATHSQUAD ||
						encounter[e].type == CREATURE_SOLDIER ||
						encounter[e].type == CREATURE_HARDENED_VETERAN ||
						encounter[e].type == CREATURE_CCS_ARCHCONSERVATIVE ||
						encounter[e].type == CREATURE_AGENT ||
						encounter[e].type == CREATURE_SECRET_SERVICE)
					{
						if (LCSrandom(3)) continue;
					}
					clearmessagearea();
					moveSixteenOne();
					addstrAlt(encounter[e].name, gamelog);
					addstrAlt(singleSpace + pickrandom(backs_off), gamelog);
					delenc(e, 0);
					addjuice(a, 2, 200); // Instant juice!
					getkey();
				}
			}
		}
	}
	else if (c == 'b')
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveSixteenOne();
		addstrAlt(a.name, gamelog);
		addstrAlt(colonSpace, gamelog);
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		moveSeventeenOne();
		switch (LCSrandom(6))
		{
		case 0:addstrAlt("\"Don't push the LCS!\"", gamelog);
			if (!sitestory->claimed)sitestory->claimed = 1; break;
		case 1:
			if (lawList[LAW_FREESPEECH] == -2)addstrAlt("\"Don't [play] with me!\"", gamelog);
			else addstrAlt("\"Don't fuck with me!\"", gamelog);
			break;
		default:
			addstrAlt(pickrandom(threaten_hostage), gamelog);
			break;
		}
		gamelog.newline();
		sitecrime += 5;
		criminalizeparty(LAWFLAG_KIDNAPPING);
		addjuice(a, -2, -10); // DE-juice for this shit
		getkey();
		bool noretreat = false;
		if (weaponhostage)
		{
			int e;
			for (e = 0; e < ENCMAX; e++)
			{
				if (encounter[e].exists&&encounter[e].alive&&
					encounter[e].enemy() && encounter[e].blood>70)
				{
					if ((encounter[e].type == CREATURE_DEATHSQUAD ||
						encounter[e].type == CREATURE_SOLDIER ||
						encounter[e].type == CREATURE_HARDENED_VETERAN ||
						encounter[e].type == CREATURE_CCS_ARCHCONSERVATIVE ||
						encounter[e].type == CREATURE_AGENT ||
						encounter[e].type == CREATURE_MERC ||
						encounter[e].type == CREATURE_COP ||
						encounter[e].type == CREATURE_GANGUNIT ||
						encounter[e].type == CREATURE_SWAT ||
						encounter[e].type == CREATURE_SECRET_SERVICE) &&
						LCSrandom(5))
					{
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						clearmessagearea();
						moveSixteenOne();
						addstrAlt(encounter[e].name, gamelog);
						addstrAlt(colonSpace, gamelog);
						moveSeventeenOne();
						if (encounter[e].align != ALIGN_CONSERVATIVE ||
							(encounter[e].type == CREATURE_SECRET_SERVICE&&exec[EXEC_PRESIDENT] > ALIGN_CONSERVATIVE))
						{
							set_color_easy(GREEN_ON_BLACK_BRIGHT);
							addstrAlt(pickrandom(please_spare_hostage), gamelog);
						}
						else
						{
							set_color_easy(RED_ON_BLACK_BRIGHT);
							if (((encounter[e].type == CREATURE_DEATHSQUAD ||
								encounter[e].type == CREATURE_AGENT ||
								encounter[e].type == CREATURE_MERC ||
								encounter[e].type == CREATURE_CCS_ARCHCONSERVATIVE ||
								encounter[e].type == CREATURE_GANGUNIT))
								&& encounter[e].align == ALIGN_CONSERVATIVE)
							{
								addstrAlt(pickrandom(who_cares_about_hostage), gamelog);
							}
							else
							{
								switch (LCSrandom(5))
								{
								case 0:
									if (hostages > 1)
										addstrAlt("\"Release your hostages, and nobody gets hurt.\"", gamelog);
									else addstrAlt("\"Let the hostage go, and nobody gets hurt.\"", gamelog);
									break;
								default:
									addstrAlt(pickrandom(hostage_negotiation), gamelog);
									break;
								}
							}
						}
						gamelog.newline();
						getkey();
						noretreat = true;
						break;
					}
				}
			}
			if (noretreat == false)
			{
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				clearmessagearea();
				moveSixteenOne();
				addstrAlt("The ploy works! The Conservatives back off.", gamelog);
				gamelog.newline();
				for (int i = ENCMAX; i >= 0; i--)
				{
					if (encounter[i].exists&&
						encounter[i].alive&&
						encounter[i].align <= -1)
					{
						delenc(i, 0);
					}
				}
				getkey();
			}
			else
			{
				set_color_easy(WHITE_ON_BLACK);
				clearcommandarea();
				clearmessagearea();
				clearmaparea();
				moveAlt(9, 1);
				addstrAlt("How should ");
				addstrAlt(a.name);
				addstrAlt(" respond?");
				moveAlt(11, 1);
				if (hostages > 1)
					addstrAlt("A - Execute a hostage");
				else
					addstrAlt("A - Execute the hostage");
				moveAlt(12, 1);
				if (hostages > 1)
					addstrAlt("B - Offer to trade the hostages for freedom");
				else
					addstrAlt("B - Offer to trade the hostage for freedom");
				moveAlt(13, 1);
				addstrAlt("C - No reply");
				while (true)
				{
					c = getkey();
					if (c == 'a' || c == 'b')break; // TODO: something to happen if you press 'c'
				}
				if (c == 'a')
				{
					Creature* executer = 0;
					if (a.prisoner)
						executer = &a;
					else for (int i = 0; i < 6; i++)
					{
						if (activesquad->squad[i] &&
							activesquad->squad[i]->prisoner &&
							activesquad->squad[i]->prisoner->alive &&
							activesquad->squad[i]->prisoner->enemy())
						{
							executer = activesquad->squad[i];
							break;
						}
					}
					moveSixteenOne();
					set_color_easy(RED_ON_BLACK_BRIGHT);
					if (executer->get_weapon().is_ranged()
						&& executer->get_weapon().get_ammoamount()>0)
					{
						addstrAlt("BLAM!", gamelog);
						gamelog.newline();
						executer->get_weapon().decrease_ammo(1); //What if it doesn't use ammo? -XML
					}
					else
					{
						addstrAlt("CRUNCH!", gamelog);
						gamelog.newline();
					}
					getkey();
					moveSeventeenOne();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					addstrAlt(executer->name, gamelog);
					addstrAlt(" drops ", gamelog);
					addstrAlt(executer->prisoner->name, gamelog);
					addstrAlt("'s body.", gamelog);
					gamelog.newline();
					addjuice(*executer, -5, -50); // DE-juice for this shit
					sitecrime += 10;
					sitestory->crime.push_back(CRIME_KILLEDSOMEBODY);
					criminalize(*executer, LAWFLAG_MURDER);
					if (executer->prisoner->type == CREATURE_CORPORATE_CEO ||
						executer->prisoner->type == CREATURE_RADIOPERSONALITY ||
						executer->prisoner->type == CREATURE_NEWSANCHOR ||
						executer->prisoner->type == CREATURE_SCIENTIST_EMINENT ||
						executer->prisoner->type == CREATURE_JUDGE_CONSERVATIVE)sitecrime += 30;
					makeloot(*executer->prisoner, groundloot);
					getkey();
					delete_and_nullify(executer->prisoner);
					if (hostages > 1 && LCSrandom(2))
					{
						clearmessagearea();
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						moveSixteenOne();
						addstrAlt(encounter[e].name, gamelog);
						addstrAlt(colonSpace, gamelog);
						set_color_easy(RED_ON_BLACK_BRIGHT);
						moveSeventeenOne();
						if (lawList[LAW_FREESPEECH] > ALIGN_ARCHCONSERVATIVE)
							addstrAlt("\"Fuck! ", gamelog);
						else addstrAlt("\"[No!] ", gamelog);
						addstrAlt(pickrandom(please_no_more), gamelog);
						gamelog.newline();
						for (int i = ENCMAX; i >= 0; i--)
							if (encounter[i].exists && encounter[i].enemy() && encounter[i].alive)
								delenc(i, 0);
						getkey();
					}
				}
				else if (c == 'b')
				{
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					moveSixteenOne();
					addstrAlt(a.name, gamelog);
					addstrAlt(colonSpace, gamelog);
					set_color_easy(GREEN_ON_BLACK_BRIGHT);
					moveSeventeenOne();
					switch (LCSrandom(5))
					{
					case 0:
						if (hostages > 1) addstrAlt("\"Back off and we'll let the hostages go.\"", gamelog);
						else addstrAlt("\"Back off and the hostage goes free.\"", gamelog);
						break;
					default:
						addstrAlt(pickrandom(let_hostages_go), gamelog);
						break;
					}
					gamelog.newline();
					getkey();
					if (((encounter[e].type == CREATURE_DEATHSQUAD ||
						encounter[e].type == CREATURE_AGENT ||
						encounter[e].type == CREATURE_MERC ||
						encounter[e].type == CREATURE_CCS_ARCHCONSERVATIVE ||
						encounter[e].type == CREATURE_GANGUNIT) &&
						LCSrandom(2)) && encounter[e].align == ALIGN_CONSERVATIVE)
					{
						clearmessagearea();
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						moveSixteenOne();
						addstrAlt(encounter[e].name, gamelog);
						addstrAlt(colonSpace, gamelog);
						set_color_easy(RED_ON_BLACK_BRIGHT);
						moveSeventeenOne();
						addstrAlt(pickrandom(go_ahead_and_die), gamelog);
						gamelog.newline();
						getkey();
					}
					else
					{
						clearmessagearea();
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						moveSixteenOne();
						addstrAlt(encounter[e].name, gamelog);
						addstrAlt(colonSpace, gamelog);
						set_color_easy(RED_ON_BLACK_BRIGHT);
						moveSeventeenOne();
						addstrAlt(pickrandom(agree_to_release_hostages), gamelog);
						gamelog.newline();
						getkey();
						for (int i = ENCMAX; i >= 0; i--)
							if (encounter[i].exists&&encounter[i].enemy() && encounter[i].alive)
								delenc(i, 0);
						clearmessagearea();
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						moveSixteenOne();
						juiceparty(15, 200); // Instant juice for successful hostage negotiation
						if (hostages > 1)addstrAlt("The squad releases all hostages in the trade.", gamelog);
						else addstrAlt("The squad releases the hostage in the trade.", gamelog);
						gamelog.newline();
						for (int i = 0; i < 6; i++)
						{
							if (activesquad->squad[i] &&
								activesquad->squad[i]->prisoner &&
								activesquad->squad[i]->prisoner->enemy())
							{
								delete_and_nullify(activesquad->squad[i]->prisoner);
							}
						}
						getkey();
					}
				}
			}
		}
		else
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			clearmessagearea();
			moveSixteenOne();
			addstrAlt(tk.name, gamelog);
			addstrAlt(" isn't interested in your pathetic threats.", gamelog);
			gamelog.newline();
			getkey();
		}
	}
	else if (c == 'c')
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveSixteenOne();
		if (location[cursite]->siege.siege)
		{
			addstrAlt(a.name, gamelog);
			addstrAlt(singleSpace, gamelog);
			switch (location[cursite]->siege.siegetype)
			{
			case SIEGE_POLICE:
				addstrAlt("pretends to be part of a police raid.", gamelog);
				break;
			case SIEGE_CIA:
				addstrAlt("pretends to be a Secret Agent.", gamelog);
				break;
			case SIEGE_CCS:
			case SIEGE_HICKS:
				switch (LCSrandom(2))
				{
				case 0:
					addstrAlt("pretends to be Mountain ", gamelog);
					moveSeventeenOne();
					addstrAlt("like Patrick Swayze in Next of Kin.", gamelog);
					break;
				case 1:
					addstrAlt("squeals like Ned Beatty ", gamelog);
					moveSeventeenOne();
					addstrAlt("in Deliverance.", gamelog);
					break;
				}
				break;
			case SIEGE_CORPORATE:
				addstrAlt("pretends to be a mercenary.", gamelog);
				break;
			case SIEGE_FIREMEN:
				addstrAlt("lights a match and throws it on the ground. ", gamelog);
				if ((!(levelmap[locx][locy][locz].flag & SITEBLOCK_FIRE_END) ||
					!(levelmap[locx][locy][locz].flag & SITEBLOCK_FIRE_PEAK) ||
					!(levelmap[locx][locy][locz].flag & SITEBLOCK_FIRE_START) ||
					!(levelmap[locx][locy][locz].flag & SITEBLOCK_DEBRIS)) && !LCSrandom(10))
				{
					levelmap[locx][locy][locz].flag |= SITEBLOCK_FIRE_START;
					moveSeventeenOne();
					addstrAlt("The carpet smolders, then bursts into flame.", gamelog);
					gamelog.newline();
					moveAlt(18, 1);
					addstrAlt("Perhaps that was a bad idea...", gamelog);
				}
				break;
			}
		}
		else        //Special bluff messages for various uniforms
		{
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			if (a.get_armor().get_itemtypename() == tag_ARMOR_POLICEUNIFORM ||
				a.get_armor().get_itemtypename() == tag_ARMOR_POLICEARMOR ||
				a.get_armor().get_itemtypename() == tag_ARMOR_SWATARMOR)
			{
				addstrAlt("\"The situation is under control.\"", gamelog);
			}
			else if (a.get_armor().get_itemtypename() == tag_ARMOR_BUNKERGEAR)
			{
				if (siteonfire) addstrAlt("\"Fire! Evacuate immediately!\"", gamelog);
				else addstrAlt("\"Everything's in check.\"", gamelog);
			}
			else if (a.get_armor().get_itemtypename() == tag_ARMOR_LABCOAT)
				addstrAlt("\"Make way, I'm a doctor!\"", gamelog);
			else if (a.get_armor().get_itemtypename() == tag_ARMOR_DEATHSQUADUNIFORM)
				addstrAlt("\"Non-targets please leave the site.\"", gamelog);
			else if (a.get_armor().get_itemtypename() == tag_ARMOR_MITHRIL)
			{
				addstrAlt(a.name, gamelog);
				addstrAlt(" engraves ", gamelog);
				set_color_easy(CYAN_ON_BLACK_BRIGHT);
				addstrAlt("Elbereth", gamelog);     //Fanciful multicolor message
				set_color_easy(GREEN_ON_BLACK_BRIGHT);
				addstrAlt(" on the floor.", gamelog);
			}
			else
			{
				addstrAlt(a.name, gamelog);
				addstrAlt(" talks like a Conservative ", gamelog);
				moveSeventeenOne();
				addstrAlt("and pretends to belong here.", gamelog);
			}
		}
		gamelog.newline();
		getkey();
		bool fooled = true;
		int e;
		for (e = 0; e < ENCMAX; e++)
		{
			if (encounter[e].exists&&encounter[e].alive&&
				encounter[e].enemy())
			{
				const int roll = a.skill_roll(SKILL_DISGUISE);
				const int diff = encounter[e].get_attribute(ATTRIBUTE_WISDOM, true)>10 ? DIFFICULTY_CHALLENGING : DIFFICULTY_AVERAGE;
				fooled = roll >= diff;
				if (roll + 1 == diff && fieldskillrate == FIELDSKILLRATE_HARD)
					a.train(SKILL_DISGUISE, 20);
				if (!fooled) break;
			}
		}
		switch (fieldskillrate)
		{
		case FIELDSKILLRATE_FAST:
			a.train(SKILL_DISGUISE, 50); break;
		case FIELDSKILLRATE_CLASSIC:
			a.train(SKILL_DISGUISE, 20); break;
		case FIELDSKILLRATE_HARD:
			a.train(SKILL_DISGUISE, 0); break;
		}
		if (!fooled)
		{
			clearmessagearea();
			set_color_easy(RED_ON_BLACK_BRIGHT);
			moveSixteenOne();
			if (encounter[e].type == CREATURE_HICK)
			{
				addstrAlt("But ", gamelog);
				addstrAlt(encounter[e].name, gamelog);
				addstrAlt(" weren't born yesterday.", gamelog);
			}
			else
			{
				addstrAlt(encounter[e].name, gamelog);
				if (lawList[LAW_FREESPEECH] == ALIGN_ARCHCONSERVATIVE)
					addstrAlt(" is not fooled by that [act].", gamelog);
				else addstrAlt(" is not fooled by that crap.", gamelog);
			}
			getkey();
		}
		else
		{
			clearmessagearea();
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			moveSixteenOne();
			addstrAlt("The Enemy is fooled and departs.", gamelog);
			getkey();
			for (int e = ENCMAX - 1; e >= 0; e--)
				if (encounter[e].exists&&encounter[e].alive&&encounter[e].enemy())
					delenc(e, 0);
		}
		gamelog.newline();
	}
	else
	{
		moveAlt(14, 1);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		addstrAlt("The Squad is arrested.", gamelog);
		gamelog.newline();
		getkey();
		int stolen = 0;
		// Police assess stolen goods in inventory
		for (int l = 0; l < len(activesquad->loot); l++)
			if (activesquad->loot[l]->is_loot())
				stolen++;
		for (int i = 0; i < 6; i++)
		{
			if (activesquad->squad[i])
			{
				activesquad->squad[i]->crimes_suspected[LAWFLAG_THEFT] += stolen;
				capturecreature(*activesquad->squad[i]);
			}
			activesquad->squad[i] = NULL;
		}
		location[cursite]->siege.siege = 0;
	}
	return 1;
}
char heyMisterDog(Creature &a, Creature &tk)
{
	bool success = false;
	string pitch;
	string response;
	// Find most Heartful Liberal
	int bestp = 0;
	for (int p = 0; p<6; p++)
	{
		if (activesquad->squad[p] &&
			activesquad->squad[p]->get_attribute(ATTRIBUTE_HEART, true) >
			activesquad->squad[bestp]->get_attribute(ATTRIBUTE_HEART, true))
		{
			bestp = p;
		}
	}
	// Say something unbelievably hippie
	if (activesquad->squad[bestp]->get_attribute(ATTRIBUTE_HEART, true) >= 15)
	{
		success = true;
		vector<string> which_choice = pickrandom(lovingly_talk_to_dog);
		pitch = which_choice[0];
		response = which_choice[1];
	}
	else // or not
	{
		tk.cantbluff = 1;
		vector<string> which_choice = pickrandom(normal_talk_to_dog);
		pitch = which_choice[0];
		response = which_choice[1];
	}
	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(10, 1);
	addstrAlt(activesquad->squad[bestp]->name, gamelog);
	addstrAlt(saysComma, gamelog);
	moveAlt(11, 1);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	addstrAlt(pitch, gamelog);
	gamelog.newline();
	getkey();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(13, 1);
	addstrAlt(tk.name, gamelog);
	addstrAlt(saysComma, gamelog);
	moveAlt(14, 1);
	set_color_easy(YELLOW_ON_BLACK_BRIGHT);
	addstrAlt(response, gamelog);
	gamelog.newline();
	getkey();
	if (success)
		for (int i = 0; i < ENCMAX; i++)
			if (encounter[i].type == CREATURE_GUARDDOG)
				encounter[i].align = ALIGN_LIBERAL;
	return 1;
}
char heyMisterMonster(Creature &a, Creature &tk)
{
	bool success = false;
	string pitch;
	string response;
	// Find most Heartful Liberal
	int bestp = 0;
	for (int p = 0; p<6; p++)
	{
		if (activesquad->squad[p] &&
			activesquad->squad[p]->get_attribute(ATTRIBUTE_HEART, true) >
			activesquad->squad[bestp]->get_attribute(ATTRIBUTE_HEART, true))
		{
			bestp = p;
		}
	}
	// Say something diplomatic
	if (activesquad->squad[bestp]->get_attribute(ATTRIBUTE_HEART, true) >= 15)
	{
		success = true;
		vector<string> which_choice = pickrandom(lovingly_talk_to_mutant);
		pitch = which_choice[0];
		response = which_choice[1];
	}
	else // or not
	{
		tk.cantbluff = 1;
		vector<string> which_choice = pickrandom(normal_talk_to_mutant);
		pitch = which_choice[0];
		response = which_choice[1];
	}
	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(10, 1);
	addstrAlt(activesquad->squad[bestp]->name, gamelog);
	addstrAlt(saysComma, gamelog);
	moveAlt(11, 1);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	addstrAlt(pitch, gamelog);
	gamelog.newline();
	getkey();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(13, 1);
	addstrAlt(tk.name, gamelog);
	addstrAlt(saysComma, gamelog);
	moveAlt(14, 1);
	set_color_easy(YELLOW_ON_BLACK_BRIGHT);
	addstrAlt(response, gamelog);
	gamelog.newline();
	getkey();
	if (success)
		for (int i = 0; i < ENCMAX; i++)
			if (encounter[i].type == CREATURE_GENETIC)
				encounter[i].align = ALIGN_LIBERAL;
	return 1;
}