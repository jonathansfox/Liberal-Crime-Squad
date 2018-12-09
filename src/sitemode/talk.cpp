#define	TALK_CPP
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
vector<vector<string> > no_free_speech_flirt;
vector<vector<string> > pickupLines;
vector<vector<string> > lovingly_talk_to_mutant;
vector<vector<string> > normal_talk_to_mutant;
vector<vector<string> > lovingly_talk_to_dog;
vector<vector<string> > normal_talk_to_dog;
vector<string> dog_rejection;
vector<string> mutant_rejection;
vector<string> that_is_disturbing;
vector<string> that_is_not_disturbing;
vector<string> robbing_bank;
vector<string> teller_gestures;
vector<string> teller_complies;
//const int DOUBLE_LINE = 2;
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
vector<file_and_text_collection> talk_file_collection = {
	/*talk.cpp*/
	customText(&no_free_speech_flirt, talky + CONST_talk012, PICKUP_LINE_SIZE),
	customText(&pickupLines, talky + CONST_talk013, PICKUP_LINE_SIZE),
	customText(&lovingly_talk_to_mutant, talky + CONST_talk014, DOUBLE_LINE),
	customText(&normal_talk_to_mutant, talky + CONST_talk015, DOUBLE_LINE),
	customText(&lovingly_talk_to_dog, talky + CONST_talk016, DOUBLE_LINE),
	customText(&normal_talk_to_dog, talky + CONST_talk017, DOUBLE_LINE),
	customText(&dog_rejection, talky + CONST_talk018),
	customText(&mutant_rejection, talky + CONST_talk019),
	customText(&that_is_disturbing, talky + CONST_talk020),
	customText(&that_is_not_disturbing, talky + CONST_talk021),
	customText(&robbing_bank, talky + CONST_talk022),
	customText(&teller_gestures, talky + CONST_talk023),
	customText(&teller_complies, talky + CONST_talk024),
	//talk in combat
	customText(&come_at_me_bro, talk_combat + CONST_talk025),
	customText(&backs_off, talk_combat + CONST_talk026),
	customText(&threaten_hostage, talk_combat + CONST_talk027),
	customText(&please_spare_hostage, talk_combat + CONST_talk028),
	customText(&who_cares_about_hostage, talk_combat + CONST_talk029),
	customText(&hostage_negotiation, talk_combat + CONST_talk030),
	customText(&please_no_more, talk_combat + CONST_talk031),
	customText(&let_hostages_go, talk_combat + CONST_talk032),
	customText(&go_ahead_and_die, talk_combat + CONST_talk033),
	customText(&agree_to_release_hostages, talk_combat + CONST_talk034),
};
//string while_naked;
map<short, string> conservativeLegalArgument;
map<short, vector<string> > talkAboutTheIssues;
map<short, string> youAreStupidTalkAboutIssues;
map<short, string> issueTooLiberal;
//
/* bluff, date, issues */
void talk(DeprecatedCreature &a, const int t)
{
	DeprecatedCreature &tk = encounter[t];
	// TALKING TO DOGS
	if (tk.type == CREATURE_GUARDDOG && tk.align != ALIGN_LIBERAL)
	{
		 heyMisterDog(tk);
	}else
	// TALKING TO MONSTERS
	if (tk.type == CREATURE_GENETIC && tk.align != ALIGN_LIBERAL)
	{
		 heyMisterMonster(tk);
	}else
	// BLUFFING
	if ((isThereASiteAlarm() || LocationsPool::getInstance().isThereASiegeHere(getCurrentSite())) && tk.enemy())
	{
		 talkInCombat(a, tk);
	}
	else {
		 talkToGeneric(a, tk);
	}
}
char talkToBankTeller(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK);
	const bool is_naked = a.is_naked() && a.animalgloss != ANIMALGLOSS_ANIMAL;
	mvaddstrAlt(11, 1, unnamed_String_Talk_cpp_001);
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
	mvaddstrAlt(12, 1, unnamed_String_Talk_cpp_002);
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_003);
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
	int c = pressSpecificKey('a', 'b', 'c');
	switch (c)
	{
	case 'a':
		clearcommandarea(); clearmessagearea(); clearmaparea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(9, 1, a.getNameAndAlignment().name, gamelog);
		addstrAlt(unnamed_String_Talk_cpp_004, gamelog);
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		mvaddstrAlt(10, 1, pickrandom(robbing_bank), gamelog);
		gamelog.newline();
		pressAnyKey();
		if (LocationsPool::getInstance().get_specific_integer(INT_ISTHISPLACEHIGHSECURITY, getCurrentSite()))
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(11, 1, unnamed_String_Talk_cpp_005, gamelog);
			addstrAlt(pickrandom(teller_gestures), gamelog);
			mvaddstrAlt(12, 1, unnamed_String_Talk_cpp_006, gamelog);
			gamelog.newline();
			pressAnyKey();
			setSiteAlarmOne();
			criminalize(a, LAWFLAG_BANKROBBERY);
			sitestory->crime.push_back(CRIME_BANKTELLERROBBERY);
			sitecrime += 30;
			makecreature(0, CREATURE_MERC);
			makecreature(1, CREATURE_MERC);
			makecreature(2, CREATURE_MERC);
			makecreature(3, CREATURE_MERC);
		}
		else
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(11, 1, unnamed_String_Talk_cpp_007, gamelog);
			addstrAlt(pickrandom(teller_complies), gamelog);
			mvaddstrAlt(12, 1, unnamed_String_Talk_cpp_008, gamelog);
			gamelog.newline();
			pressAnyKey();
			criminalize(a, LAWFLAG_BANKROBBERY);
			sitestory->crime.push_back(CRIME_BANKTELLERROBBERY);
			sitecrime += 30;
			sitealarmtimer = 0;
			giveActiveSquadThisLoot(new Money(5000));
		}
		tk.make_cantbluff_one();
		return 1;
	case 'b':
	{
		clearcommandarea(); clearmessagearea(); clearmaparea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		DeprecatedCreature *armed_liberal = NULL;
		for (int i = 0; i < 6; i++)
		{
			if (activesquad->squad[i] &&
				activesquad->squad[i]->get_weapon().get_specific_bool(BOOL_THREATENING_))
			{
				armed_liberal = activesquad->squad[i];
				break;
			}
		}
		if (armed_liberal)
		{
			mvaddstrAlt(9, 1, armed_liberal->getNameAndAlignment().name, gamelog);
			addstrAlt(unnamed_String_Talk_cpp_009, gamelog);
			addstrAlt(armed_liberal->get_weapon().get_shortname(0), gamelog);
			addstrAlt(singleDot, gamelog);
			gamelog.newline();
			pressAnyKey();
			clearmessagearea();
		}
		mvaddstrAlt(10, 1, a.getNameAndAlignment().name, gamelog);
		addstrAlt(saysComma, gamelog);
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		mvaddstrAlt(11, 1, unnamed_String_Talk_cpp_010, gamelog);
		addstrAlt(slogan_str, gamelog);
		gamelog.record(singleSpace);
		mvaddstrAlt(12, 1, unnamed_String_Talk_cpp_011, gamelog);
		gamelog.newline();
		pressAnyKey();
		const int roll = a.skill_roll(SKILL_PERSUASION);
		int difficulty = DIFFICULTY_VERYEASY;
		if (armed_liberal == NULL)
			difficulty += 12;
		if (LocationsPool::getInstance().get_specific_integer(INT_ISTHISPLACEHIGHSECURITY, getCurrentSite()))
			difficulty += 12;
		clearcommandarea(); clearmessagearea(); clearmaparea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		if (roll < difficulty)
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(9, 1, unnamed_String_Talk_cpp_012, gamelog);
			mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_013, gamelog);
			gamelog.newline();
			pressAnyKey();
			setSiteAlarmOne();
			sitealienate = 2;
			criminalizeparty(LAWFLAG_BANKROBBERY);
			sitestory->crime.push_back(CRIME_BANKSTICKUP);
			sitecrime += 50;
			CreatureTypes guard = CREATURE_SECURITYGUARD;
			if (LocationsPool::getInstance().get_specific_integer(INT_ISTHISPLACEHIGHSECURITY, getCurrentSite())) guard = CREATURE_MERC;
			makecreature(0, guard);
			makecreature(1, guard);
			makecreature(2, guard);
			makecreature(3, guard);
			makecreature(4, guard);
			makecreature(5, guard);
		}
		else
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(9, 1, unnamed_String_Talk_cpp_014, gamelog);
			gamelog.newline();
			pressAnyKey();
			mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_015, gamelog);
			gamelog.newline();
			pressAnyKey();
			criminalizeparty(LAWFLAG_BANKROBBERY);
			sitestory->crime.push_back(CRIME_BANKSTICKUP);
			sitecrime += 50;
			setSiteAlarmOne();
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
			setEncounterZeroExistsFalse();
		}
	}
	default:
	case 'c':
		return 0;
	}
}
char talkToGeneric(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, a.getNameAndAlignment().name);
	addstrAlt(unnamed_String_Talk_cpp_016);
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
	addstrAlt(tk.getNameAndAlignment().name);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	addstrAlt(get_age_string(tk.getCreatureBio(), tk.animalgloss));
	addstrAlt(unnamed_String_Talk_cpp_017);
	const bool is_naked = a.is_naked() && a.animalgloss != ANIMALGLOSS_ANIMAL;
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(11, 1, unnamed_String_Talk_cpp_018);
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
	if (tk.can_date(a.getCreatureBio().age, a.animalgloss))set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, unnamed_String_Talk_cpp_019);
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_020);
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
	if (tk.type == CREATURE_LANDLORD && LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE, getCurrentSite()) == -1)
	{
		mvaddstrAlt(14, 1, unnamed_String_Talk_cpp_021);
		if (is_naked)addstrAlt(while_naked);
		addstrAlt(singleDot);
	}
	else if (tk.type == CREATURE_LANDLORD && LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE, getCurrentSite()) > 0)
	{
		mvaddstrAlt(14, 1, unnamed_String_Talk_cpp_022);
		if (is_naked)addstrAlt(while_naked);
		addstrAlt(singleDot);
	}
	else if (tk.type == CREATURE_GANGMEMBER || tk.type == CREATURE_MERC)
	{
		mvaddstrAlt(14, 1, unnamed_String_Talk_cpp_023);
		if (is_naked)addstrAlt(while_naked);
		addstrAlt(singleDot);
	}
	else if (tk.type == CREATURE_BANK_TELLER)
	{
		mvaddstrAlt(14, 1, unnamed_String_Talk_cpp_024);
		if (is_naked)addstrAlt(while_naked);
		addstrAlt(singleDot);
	}
	while (true)
	{
		const int c = getkeyAlt();
		switch (c)
		{
		case 'a':
			wannaHearSomethingDisturbing(a, tk);
			return 1;
		case 'b':
			if (!tk.can_date(a.getCreatureBio().age, a.animalgloss)) break;
			doYouComeHereOften(a, tk);
			return 1;
		case 'c':
			return 0;
		case 'd':
			if (tk.type == CREATURE_LANDLORD && LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE, getCurrentSite()) == -1)
			{
				heyIWantToRentARoom(a, tk);
				return 1;
			}
			else if (tk.type == CREATURE_LANDLORD && LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE, getCurrentSite()) > 0)
			{
				heyIWantToCancelMyRoom(a, tk);
				return 1;
			}
			else if (tk.type == CREATURE_GANGMEMBER || tk.type == CREATURE_MERC)
			{
				heyINeedAGun(a, tk);
				return 1;
			}
			else if (tk.type == CREATURE_BANK_TELLER)
			{
				return talkToBankTeller(a, tk);
			}
			break;
		}
	}
}
// #include "../common/creaturePool.h"
void heyIWantToCancelMyRoom(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, a.getNameAndAlignment().name, gamelog);
	addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_025, gamelog);
	gamelog.newline();
	pressAnyKey();
	const bool is_naked = a.is_naked() && a.animalgloss != ANIMALGLOSS_ANIMAL;
	if (is_naked)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog);
		addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_026, gamelog);
		gamelog.newline();
		pressAnyKey();
		return;
	}
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog);
	addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_027, gamelog);
	gamelog.newline();
	pressAnyKey();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(15, 1, unnamed_String_Talk_cpp_028, gamelog);
	gamelog.newline();
	pressAnyKey();

	moveEverythingAwayFromSite(getCurrentSite());

}

/* common - assigns a new base to all members of a squad */
void heyIWantToRentARoom(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, a.getNameAndAlignment().name, gamelog); addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_029, gamelog);
	gamelog.newline();
	pressAnyKey();
	const bool is_naked = a.is_naked() && a.animalgloss != ANIMALGLOSS_ANIMAL;
	if (is_naked)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_030, gamelog);
		gamelog.newline();
		pressAnyKey();
		return;
	}
	int rent;
	switch (LocationsPool::getInstance().getLocationType(getCurrentSite()))
	{
	default:rent = 200; break;
	case SITE_RESIDENTIAL_APARTMENT:rent = 650; break;
	case SITE_RESIDENTIAL_APARTMENT_UPSCALE:rent = 1500; break;
	}
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_031, gamelog);
	addstrAlt(rent, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_032, gamelog);
	gamelog.newline();
	mvaddstrAlt(14, 1, unnamed_String_Talk_cpp_033, gamelog);
	addstrAlt(rent, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_034, gamelog);
	gamelog.newline();
	pressAnyKey();
	clearcommandarea(); clearmessagearea(); clearmaparea();
	while (true)
	{
		int c = 'a';
		if (ledger.get_funds() < rent)set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(11, 1, unnamed_String_Talk_cpp_035);
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(12, 1, unnamed_String_Talk_cpp_036);
		mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_037);
		c = getkeyAlt();
		switch (c)
		{
		case 'a': // Accept rent deal
			if (ledger.get_funds() < rent) break;
			clearcommandarea(); clearmessagearea(); clearmaparea();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(9, 1, a.getNameAndAlignment().name, gamelog); addstrAlt(saysComma, gamelog);
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_038, gamelog);
			gamelog.newline();
			pressAnyKey();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_039, gamelog);
			gamelog.newline();
			mvaddstrAlt(14, 1, unnamed_String_Talk_cpp_040, gamelog);
			gamelog.newline();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			addstrAlt(unnamed_String_Talk_cpp_041);
			pressAnyKey();
			ledger.subtract_funds(rent, EXPENSE_RENT);
			locationIsNowRented(getCurrentSite(), rent);
			basesquad(activesquad, getCurrentSite());
			return;
		case 'b': // Refuse rent deal
			clearcommandarea(); clearmessagearea(); clearmaparea();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(9, 1, a.getNameAndAlignment().name, gamelog); addstrAlt(saysComma, gamelog);
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_042, gamelog);
			gamelog.newline();
			pressAnyKey();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_043, gamelog);
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			addstrAlt(unnamed_String_Talk_cpp_044, gamelog);
			gamelog.newline();
			pressAnyKey();
			return;
		case 'c': // Threaten landlord
			clearcommandarea(); clearmessagearea(); clearmaparea();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			DeprecatedCreature *armed_liberal = NULL;
			for (int i = 0; i < 6; i++)
			{
				if (activesquad->squad[i] &&
					activesquad->squad[i]->get_weapon().get_specific_bool(BOOL_THREATENING_))
				{
					armed_liberal = activesquad->squad[i];
					break;
				}
			}
			if (armed_liberal)
			{
				mvaddstrAlt(9, 1, armed_liberal->getNameAndAlignment().name, gamelog);
				addstrAlt(unnamed_String_Talk_cpp_045, gamelog);
				addstrAlt(armed_liberal->get_weapon().get_shortname(0), gamelog);
				addstrAlt(singleDot, gamelog);
				gamelog.newline();
				pressAnyKey();
				clearmessagearea();
			}
			mvaddstrAlt(9, 1, a.getNameAndAlignment().name, gamelog);
			addstrAlt(saysComma, gamelog);
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_046, gamelog);
			gamelog.newline();
			pressAnyKey();
			const int roll = a.skill_roll(SKILL_PERSUASION);
			int difficulty = DIFFICULTY_FORMIDABLE;
			if (!newscherrybusted)
				difficulty += 6;
			if (armed_liberal == NULL)
				difficulty += 6;
			if (roll < difficulty - 1)
			{
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
				set_color_easy(CYAN_ON_BLACK_BRIGHT);
				mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_047, gamelog);
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				addstrAlt(unnamed_String_Talk_cpp_048, gamelog);
				gamelog.newline();
				pressAnyKey();
				tk.make_cantbluff_one();
				return;
			}
			else
			{
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
				set_color_easy(CYAN_ON_BLACK_BRIGHT);
				mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_049, gamelog);
				gamelog.newline();
				pressAnyKey();
				int rent;
				// Either he calls the cops...
				if (roll < difficulty)
				{
					for (int i = 0; i < 6; i++)
						if (activesquad->squad[i])
							criminalize(*(activesquad->squad[i]), LAWFLAG_EXTORTION);
					LocationsPool::getInstance().setSiegetimeuntillocated(getCurrentSite(), 2);
					rent = 10000000; // Yeah he's kicking you out next month
				}
				// ...or it's yours for free
				else rent = 0;
				locationIsNowRented(getCurrentSite(), rent);
				basesquad(activesquad, getCurrentSite());
				return;
			}
		}
	}
}

void heyINeedAGun(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, a.getNameAndAlignment().name, gamelog); addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_050, gamelog);
	gamelog.newline();
	pressAnyKey();
	const bool is_naked = a.is_naked() && a.animalgloss != ANIMALGLOSS_ANIMAL;
	if (is_naked)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_051, gamelog);
		gamelog.newline();
		pressAnyKey();
		return;
	}
	// IsaacG Migrate Strings
	if (a.get_armor().get_itemtypename() == tag_ARMOR_POLICEUNIFORM ||
		a.get_armor().get_itemtypename() == tag_ARMOR_POLICEARMOR ||
		a.get_armor().get_itemtypename() == tag_ARMOR_SWATARMOR ||
		(lawList[LAW_POLICEBEHAVIOR] == -2 && lawList[LAW_DEATHPENALTY] == -2 &&
			a.get_armor().get_itemtypename() == tag_ARMOR_DEATHSQUADUNIFORM))
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_052, gamelog);
		gamelog.newline();
		pressAnyKey();
		return;
	}
	if (isThereASiteAlarm())
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_053, gamelog);
		gamelog.newline();
		pressAnyKey();
		return;
	}
	switch (LocationsPool::getInstance().getLocationType(getCurrentSite()))
	{
	case SITE_OUTDOOR_BUNKER:
	case SITE_BUSINESS_CRACKHOUSE:
	case SITE_BUSINESS_BARANDGRILL:
	case SITE_BUSINESS_ARMSDEALER:
	case SITE_RESIDENTIAL_TENEMENT:
	case SITE_RESIDENTIAL_BOMBSHELTER:
	case SITE_RESIDENTIAL_SHELTER:
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_054, gamelog);
		gamelog.newline();
		pressAnyKey();
		armsdealer(getCurrentSite());
		return;
	default:
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_055, gamelog);
		gamelog.newline();
		pressAnyKey();
		return;
	}
}
void wannaHearSomethingDisturbing(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, a.getNameAndAlignment().name, gamelog); addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_056, gamelog);
	gamelog.newline();
	pressAnyKey();
	bool interested = tk.talkreceptive();
	if (!interested && a.skill_check(SKILL_PERSUASION, DIFFICULTY_AVERAGE))
		interested = true;
	if ((tk.animalgloss == ANIMALGLOSS_ANIMAL && tk.align != ALIGN_LIBERAL) ||
		tk.animalgloss == ANIMALGLOSS_TANK)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog);
		switch (tk.type)
		{
		case CREATURE_TANK: addstrAlt(unnamed_String_Talk_cpp_057, gamelog); break;
		case CREATURE_GUARDDOG: addstrAlt(unnamed_String_Talk_cpp_058, gamelog); break;
		default: addstrAlt(unnamed_String_Talk_cpp_059, gamelog); break;
		}
		gamelog.newline();
		pressAnyKey();
	}
	else if (strcmp(tk.getNameAndAlignment().name.data(), unnamed_String_Talk_cpp_060.data()) != 0 && interested)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_061, gamelog);
		gamelog.newline();
		pressAnyKey();
		talkAboutIssues(a, tk);
	}
	else
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		if (strcmp(tk.getNameAndAlignment().name.data(), unnamed_String_Talk_cpp_060.data()) == 0)
		{
			if (tk.align == ALIGN_LIBERAL)
				mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_062, gamelog);
			else mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_063, gamelog);
		}
		else mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_064, gamelog);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		addstrAlt(unnamed_String_Talk_cpp_065, gamelog);
		gamelog.newline();
		pressAnyKey();
	}
}
void doYouComeHereOften(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	int y = 12;
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, a.getNameAndAlignment().name, gamelog); addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	vector<string> selected_flirt;
	int line;
	if (lawList[LAW_FREESPEECH] == -2)
	{
		selected_flirt = pickrandom(no_free_speech_flirt);
	}
	else
	{
		selected_flirt = pickrandom(pickupLines);
	}
	mvaddstrAlt(10, 1, selected_flirt[0], gamelog);
	if (selected_flirt[1] != blankString) {
		y++;
		mvaddstrAlt(11, 1, selected_flirt[1], gamelog);
	}
	gamelog.newline();
	pressAnyKey();
	bool succeeded = false;
	int difficulty = DIFFICULTY_HARD;
	if (tk.type == CREATURE_CORPORATE_CEO)
		difficulty = DIFFICULTY_HEROIC;
	const bool is_naked = a.is_naked() && a.animalgloss != ANIMALGLOSS_ANIMAL;
	if (is_naked) difficulty -= 4;
	if (a.skill_check(SKILL_SEDUCTION, difficulty))
		succeeded = true;
	if ((tk.animalgloss == ANIMALGLOSS_ANIMAL && lawList[LAW_ANIMALRESEARCH] != 2 && a.animalgloss != ANIMALGLOSS_ANIMAL) ||
		tk.animalgloss == ANIMALGLOSS_TANK)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(y++, 1, tk.getNameAndAlignment().name, gamelog);
		switch (tk.type)
		{
		case CREATURE_TANK:
			addstrAlt(unnamed_String_Talk_cpp_066, gamelog);
			break;
		case CREATURE_GUARDDOG:
			addstrAlt(saysComma, gamelog);
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(y, 1, pickrandom(dog_rejection), gamelog);
			tk.align = ALIGN_CONSERVATIVE;
			tk.make_cantbluff_one();
			break;
		case CREATURE_GENETIC:
			addstrAlt(saysComma, gamelog);
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(y, 1, pickrandom(mutant_rejection), gamelog);
			tk.align = ALIGN_CONSERVATIVE;
			tk.make_cantbluff_one();
			break;
		default:
			addstrAlt(unnamed_String_Talk_cpp_067, gamelog);
		}
		gamelog.newline();
		pressAnyKey();
		return;
	}
	a.train(SKILL_SEDUCTION, LCSrandom(5) + 2);
	if ((a.get_armor().get_itemtypename() == tag_ARMOR_POLICEUNIFORM // Police property on armor? -XML
		|| a.get_armor().get_itemtypename() == tag_ARMOR_POLICEARMOR
		|| a.get_armor().get_itemtypename() == tag_ARMOR_SWATARMOR
		|| (lawList[LAW_POLICEBEHAVIOR] == ALIGN_ARCHCONSERVATIVE && lawList[LAW_DEATHPENALTY] == ALIGN_ARCHCONSERVATIVE
			&& a.get_armor().get_itemtypename() == tag_ARMOR_DEATHSQUADUNIFORM))
		&& tk.type == CREATURE_PROSTITUTE)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(y++, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(RED_ON_BLACK_BRIGHT);
		mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_068, gamelog);
		gamelog.newline();
		pressAnyKey();
		tk.make_cantbluff_one();
	}
	else if (succeeded)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(y++, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		mvaddstrAlt(y++, 1, selected_flirt[2], gamelog);
		gamelog.newline();
		pressAnyKey();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		++y;
		mvaddstrAlt(y++, 1, a.getNameAndAlignment().name, gamelog);
		addstrAlt(unnamed_String_Talk_cpp_069, gamelog);
		addstrAlt(tk.getNameAndAlignment().name, gamelog);
		addstrAlt(unnamed_String_Talk_cpp_070, gamelog);
		if (strcmp(tk.getNameAndAlignment().name.data(), unnamed_String_Talk_cpp_060.data()) == 0)
		{
			addstrAlt(unnamed_String_Talk_cpp_071, gamelog);
			mvaddstrAlt(y++, 1, tk.getNameAndAlignment().name, gamelog);
			addstrAlt(unnamed_String_Talk_cpp_072, gamelog);
			criminalize(tk, LAWFLAG_ESCAPED);
		}
		addstrAlt(unnamed_String_Talk_cpp_073, gamelog);
		gamelog.newline();
		pressAnyKey();
		newDate(a, tk);
	}
	else
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(y++, 1, tk.getNameAndAlignment().name, gamelog);
		addstrAlt(respondsComma, gamelog);
		set_color_easy(RED_ON_BLACK_BRIGHT);
		if (tk.type == CREATURE_CORPORATE_CEO)
		{
			if (a.gender_liberal != GENDER_MALE)
				mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_074, gamelog);
			else mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_075, gamelog);
		}
		else
		{
			mvaddstrAlt(y++, 1, selected_flirt[3], gamelog);
			if (selected_flirt[4] != blankString) {
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(y++, 1, selected_flirt[4], gamelog);
			}
		}
		gamelog.newline();
		pressAnyKey();
		tk.make_cantbluff_one();
	}
}
void talkAboutIssues(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	const int lw = LCSrandom(LAWNUM); // pick a random law to talk about
	bool succeeded = false;
	bool you_are_stupid = false;
	bool issue_too_liberal = false;
	if (!(a.attribute_check(ATTRIBUTE_INTELLIGENCE, DIFFICULTY_EASY)))
		you_are_stupid = true;
	else if (lawList[lw] == ALIGN_ELITELIBERAL && newscherrybusted)
		issue_too_liberal = true;

	printTalkAboutIssuesHeader(a.getNameAndAlignment().name);

	if (you_are_stupid)
	{
		printTalkAboutIssuesWhenStupid(lw);
	}
	else if (issue_too_liberal)
	{
		printTalkAboutIssuesTooLiberal(lw);
	}
	else
	{
		printTalkAboutIssuesNormal(lw, tk.animalgloss);
	}

	

	pressAnyKey();
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
	const bool extraline = you_are_stupid || issue_too_liberal;
	const int special_case = LCSrandom(10);
	bool another_extraline = !special_case;
	// Prisoners never accept to join you, you must liberate them instead

	if (succeeded && !isPrisoner(tk.getNameAndAlignment().name))
	{
		bool unableToSpeak = tk.type == CREATURE_MUTANT && tk.get_attribute(ATTRIBUTE_INTELLIGENCE, true) < 3;
		if (unableToSpeak) {
			printUnableToSpeakAgree(tk.getNameAndAlignment().name, extraline);
		}
		else
		{
			printThatIsDisturbing(tk.getNameAndAlignment().name, extraline, special_case);
		}
		pressAnyKey();
		printAgreesToComeByLater(tk.getNameAndAlignment().name, extraline, another_extraline && !unableToSpeak);
		pressAnyKey();
		DeprecatedCreature *newcr = new DeprecatedCreature;
		*newcr = tk;
		newcr->namecreature();
		newRecruit(newcr, a.id);
		delenc(tk);
	}
	else
	{
		if (tk.type == CREATURE_MUTANT &&
			tk.get_attribute(ATTRIBUTE_INTELLIGENCE, true) < 3)
		{
			printMutantTalkAboutIssues(tk.getNameAndAlignment().name, extraline);
		}
		else
		{
			const bool tkConservativeCounter = tk.align != ALIGN_LIBERAL && tk.attribute_check(ATTRIBUTE_WISDOM, DIFFICULTY_AVERAGE);
			if (tk.align == ALIGN_CONSERVATIVE && you_are_stupid)
			{
				printConservativeRespondsToStupid(tk.type, extraline);
			}
			else if (tkConservativeCounter)
			{
				printConservativeCounter(extraline, lw);
			}
			else
			{
				printRejectTalk(extraline);
			}
		}
		printTurnsAway();
		pressAnyKey();
		tk.make_cantbluff_one();
	}
}


bool isPrisoner(const string tkname) {
	return strcmp(tkname.data(), unnamed_String_Talk_cpp_081.data()) != 0;
}


void pressKeyAInCombat(DeprecatedCreature &a) {
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();
	printThreatenEnemy(a.getNameAndAlignment().name);
	pressAnyKey();
	for (int e = 0; e < ENCMAX; e++)
	{
		if (encounter[e].exists&&encounter[e].alive&&encounter[e].enemy)
		{
			const int attack = a.juice / 50 + attitude[VIEW_LIBERALCRIMESQUAD] / 10;
			const int defense = encounterWisdomRoll(e);
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
				printAnotherOneBacksOff(encounter[e].name);
				delenc(e, 0);
				addjuice(a, 2, 200); // Instant juice!
				pressAnyKey();
			}
		}
	}
}


void pressedKeyAWithHostage(DeprecatedCreature &a, const int hostages, const int e) {
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();
	DeprecatedCreature* executer = 0;
	if (a.is_holding_body())
		executer = &a;
	else for (int i = 0; i < 6; i++)
	{
		if (activesquad->squad[i] &&
			activesquad->squad[i]->is_holding_body() &&
			activesquad->squad[i]->is_prisoner_alive() &&
			activesquad->squad[i]->is_prisoner_enemy())
		{
			executer = activesquad->squad[i];
			break;
		}
	}
	
	if (executer->get_weapon().is_ranged()
		&& executer->get_weapon().get_ammoamount() > 0)
	{
		printExecutionGunshot();
		executer->get_weapon().decrease_ammo(1); //What if it doesn't use ammo? -XML
	}
	else
	{
		printExecutionBareHands();
	}
	
	pressAnyKey();
	printDiscardsBody(executer->getNameAndAlignment().name, executer->get_prisoner_name());
	addjuice(*executer, -5, -50); // DE-juice for this shit
	sitecrime += 10;
	sitestory->crime.push_back(CRIME_KILLEDSOMEBODY);
	criminalize(*executer, LAWFLAG_MURDER);
	if (executer->get_prisoner_type() == CREATURE_CORPORATE_CEO ||
		executer->get_prisoner_type() == CREATURE_RADIOPERSONALITY ||
		executer->get_prisoner_type() == CREATURE_NEWSANCHOR ||
		executer->get_prisoner_type() == CREATURE_SCIENTIST_EMINENT ||
		executer->get_prisoner_type() == CREATURE_JUDGE_CONSERVATIVE)sitecrime += 30;
	executer->make_prisoner_ground_loot();
	pressAnyKey();
	executer->delete_and_nullify_prisoner();
	if (hostages > 1 && LCSrandom(2))
	{
		printEnemyWatchesHostageDeath(encounter[e].name);
		for (int i = ENCMAX - 1; i >= 0; i--)
		{
			if (encounter[i].exists && encounter[i].enemy && encounter[i].alive)
			{
				delenc(i, 0);
			}
		}
		pressAnyKey();
	}
}
void pressedKeyBWithHostage(DeprecatedCreature &a, const int hostages, const int e) {
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();
	printLetUsGoAndTheyGoFree(a.getNameAndAlignment().name, hostages);
	pressAnyKey();
	if (((encounter[e].type == CREATURE_DEATHSQUAD ||
		encounter[e].type == CREATURE_AGENT ||
		encounter[e].type == CREATURE_MERC ||
		encounter[e].type == CREATURE_CCS_ARCHCONSERVATIVE ||
		encounter[e].type == CREATURE_GANGUNIT) &&
		LCSrandom(2)) && encounter[e].align == ALIGN_CONSERVATIVE)
	{
		printEnemyAllowsHostagesToDie(encounter[e].name);
		pressAnyKey();
	}
	else
	{

		printReleaseHostagesHeader(encounter[e].name);
		pressAnyKey();
		printReleaseHostagesFooter(hostages);
		for (int i = ENCMAX - 1; i >= 0; i--) {
			if (encounter[i].exists&&encounter[i].enemy && encounter[i].alive)
			{
				delenc(i, 0);
			}
		}
		for (int i = 0; i < 6; i++)
		{
			if (activesquad->squad[i] &&
				activesquad->squad[i]->is_holding_body() &&
				activesquad->squad[i]->is_prisoner_enemy())
			{
				activesquad->squad[i]->delete_and_nullify_prisoner();
			}
		}
		pressAnyKey();
	}
}

void pressKeyBInCombat(DeprecatedCreature &a, DeprecatedCreature &tk, const int hostages, const int weaponhostage) {
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();
	printThreatenHostages(a.getNameAndAlignment().name);
	sitecrime += 5;
	criminalizeparty(LAWFLAG_KIDNAPPING);
	addjuice(a, -2, -10); // DE-juice for this shit
	pressAnyKey();
	if (weaponhostage)
	{
		bool noretreat = false;
		int e = 0;
		for (; e < ENCMAX; e++)
		{
			if (encounter[e].exists&&encounter[e].alive&&
				encounter[e].enemy && encounter[e].blood > 70)
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
					printHostageNegotiation(encounter[e].name, encounter[e].type, encounter[e].align, hostages);
					pressAnyKey();
					noretreat = true;
					break;
				}
			}
		}
		if (e == ENCMAX) { e--; }
		if (noretreat == false)
		{
			printPloyWorksEnemyBacksOff();
			for (int i = ENCMAX - 1; i >= 0; i--)
			{
				if (encounter[i].exists&&
					encounter[i].alive&&
					encounter[i].align <= -1)
				{
					delenc(i, 0);
				}
			}
			pressAnyKey();
		}
		else
		{
			printHowShouldWeRespond(a.getNameAndAlignment().name, hostages);
			char c = pressSpecificKey('a', 'b'); // TODO: something to happen if you press 'c'
			switch (c) {
			case 'a':
				pressedKeyAWithHostage(a, hostages, e);
				break;

			case 'b':
				pressedKeyBWithHostage(a, hostages, e);
				break;


			}
		}
	}
	else
	{
		printEnemyIgnoresThreat(tk.getNameAndAlignment().name);
		pressAnyKey();
	}
}

void pressKeyCInCombat(DeprecatedCreature &a) {
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();

	if (LocationsPool::getInstance().isThereASiegeHere(getCurrentSite()))
	{
		printSiegeBluff(a.getNameAndAlignment().name, LocationsPool::getInstance().getSiegeType(getCurrentSite()));
		
	}
	else        //Special bluff messages for various uniforms
	{
		if (a.get_armor().get_itemtypename() == tag_ARMOR_POLICEUNIFORM ||
			a.get_armor().get_itemtypename() == tag_ARMOR_POLICEARMOR ||
			a.get_armor().get_itemtypename() == tag_ARMOR_SWATARMOR)
		{
			printPoliceBluff();
		}
		else if (a.get_armor().get_itemtypename() == tag_ARMOR_BUNKERGEAR)
		{
			printBunkerGearBluff();
		}
		else if (a.get_armor().get_itemtypename() == tag_ARMOR_LABCOAT)
			printLabCoatBluff();
		else if (a.get_armor().get_itemtypename() == tag_ARMOR_DEATHSQUADUNIFORM)
			printDeathSquadBluff();
		else if (a.get_armor().get_itemtypename() == tag_ARMOR_MITHRIL)
		{
			printEngraveElbereth(a.getNameAndAlignment().name);
		}
		else
		{
			printITalkLikeAConservative(a.getNameAndAlignment().name);
		}

	}
	pressAnyKey();
	bool fooled = true;
	int e = 0;
	for (; e < ENCMAX; e++)
	{
		if (encounter[e].exists&&encounter[e].alive&&
			encounter[e].enemy)
		{
			const int roll = a.skill_roll(SKILL_DISGUISE);
			const int diff = getDifficultyBasedOnEncounterWisdom(e);
			fooled = roll >= diff;
			if (roll + 1 == diff && fieldskillrate == FIELDSKILLRATE_HARD)
				a.train(SKILL_DISGUISE, 20);
			if (!fooled) break;
		}
	}
	if (e == ENCMAX) { e--; }
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
		if (encounter[e].type == CREATURE_HICK)
		{
			printWeWerentBornYesterday(encounter[e].name);
		}
		else
		{
			printXeIsNotFooled(encounter[e].name);
		}
		pressAnyKey();
	}
	else
	{
		printTheEnemyIsFooled();
		pressAnyKey();
		for (int e = ENCMAX - 1; e >= 0; e--)
			if (encounter[e].exists&&encounter[e].alive&&encounter[e].enemy)
				delenc(e, 0);
	}
}
void pressKeyDInCombat() {
	printTheSquadIsArrested();
	pressAnyKey();
	int stolen = 0;
	// Police assess stolen goods in inventory
	for (int l = 0; l < len(activesquad->loot); l++)
		if (activesquad->loot[l]->whatIsThis() == THIS_IS_LOOT)
			stolen++;
	for (int i = 0; i < 6; i++)
	{
		if (activesquad->squad[i])
		{
			for (int j = 0; j < stolen; j++) {
				activesquad->squad[i]->criminalize_me(LAWFLAG_THEFT);
			}
			capturecreature(*activesquad->squad[i]);
		}
		activesquad->squad[i] = NULL;
	}
	LocationsPool::getInstance().isThereASiegeHere(getCurrentSite(), 0);
}
char haveActiveSquadTalk(const int sp, const int t) {
	DeprecatedCreature &tk = encounter[t];
	// TALKING TO DOGS
	if (tk.type == CREATURE_GUARDDOG && tk.align != ALIGN_LIBERAL)
	{
		heyMisterDog(tk);
		return 1;
	}
	else {
		// TALKING TO MONSTERS
		if (tk.type == CREATURE_GENETIC && tk.align != ALIGN_LIBERAL)
		{
			heyMisterMonster(tk);
			return 1;
		}
		else
			// BLUFFING
			if ((isThereASiteAlarm() || LocationsPool::getInstance().isThereASiegeHere(getCurrentSite())) && tk.enemy())
			{
				talkInCombat(*activesquad->squad[sp], tk);
				return 1;
			}
			else {
				return talkToGeneric(*activesquad->squad[sp], tk);
			}
	}

}
void talkInCombat(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	printTalksToThem(a.name, tk.align, tk.getNameAndAlignment().name);
	int c = 0, hostages = 0, weaponhostage = 0;
	bool cop = 0;
	for (int i = 0; i < 6; i++)
	{
		if (activesquad->squad[i] &&
			activesquad->squad[i]->is_holding_body() &&
			activesquad->squad[i]->is_prisoner_alive() &&
			activesquad->squad[i]->is_prisoner_enemy())
		{
			hostages++;
			if (activesquad->squad[i]->get_weapon().get_specific_bool(BOOL_CAN_THREATEN_HOSTAGES_))
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
	printTalkOptionsDuringCombat(hostages, tk.is_cantbluff_two(), cop);
	while (true)
	{
		c = getkeyAlt();
		if (c == 'a')break;
		if (c == 'b' && hostages)break;
		if (c == 'c' && !tk.is_cantbluff_two())break;
		if (c == 'd' && cop)break;
	}
	switch (c) {
	case 'a':

		pressKeyAInCombat(a);
		break;

	case 'b':

		pressKeyBInCombat(a, tk, hostages, weaponhostage);
		break;

	case 'c':

		pressKeyCInCombat(a);
		break;

	case 'd':

		pressKeyDInCombat();
		break;

	}
}
int findMostHeartfulLiberal() {
	int bestp = 0;
	for (int p = 0; p < 6; p++)
	{
		if (activesquad->squad[p] &&
			activesquad->squad[p]->get_attribute(ATTRIBUTE_HEART, true) >
			activesquad->squad[bestp]->get_attribute(ATTRIBUTE_HEART, true))
		{
			bestp = p;
		}
	}
	return bestp;
}

void heyMisterDog(DeprecatedCreature &tk)
{
	bool success = false;
	string pitch;
	string response;
	// Find most Heartful Liberal
	int bestp = findMostHeartfulLiberal();
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
		tk.make_cantbluff_one();
		vector<string> which_choice = pickrandom(normal_talk_to_dog);
		pitch = which_choice[0];
		response = which_choice[1];
	}

	printSpecialRecruitment(activesquad->squad[bestp]->getNameAndAlignment().name, tk.getNameAndAlignment().name, pitch, response);
	pressAnyKey();

	if (success) {
		liberalizeEncounterIfThisType(CREATURE_GUARDDOG);
	}
}
void heyMisterMonster(DeprecatedCreature &tk)
{
	bool success = false;
	string pitch;
	string response;
	// Find most Heartful Liberal
	int bestp = findMostHeartfulLiberal();
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
		tk.make_cantbluff_one();
		vector<string> which_choice = pickrandom(normal_talk_to_mutant);
		pitch = which_choice[0];
		response = which_choice[1];
	}

	printSpecialRecruitment(activesquad->squad[bestp]->getNameAndAlignment().name, tk.getNameAndAlignment().name, pitch, response);
	pressAnyKey();

	if (success) {
		liberalizeEncounterIfThisType(CREATURE_GENETIC);
	}
}

/* ensures that the creature's work location is appropriate to its type */
int verifyworklocation(const int type, const int worklocation)
{
	int okaysite[SITENUM];
	memset(okaysite, 0, SITENUM * sizeof(int));

	// TODO this can be extracted to a table
	if (type == CREATURE_CCS_ARCHCONSERVATIVE || type == CREATURE_CCS_MOLOTOV ||
		type == CREATURE_CCS_SNIPER || type == CREATURE_CCS_VIGILANTE) {

		if (ccs_kills == 2)okaysite[SITE_OUTDOOR_BUNKER] = 1;
		if (ccs_kills == 1)okaysite[SITE_RESIDENTIAL_BOMBSHELTER] = 1;
		if (ccs_kills == 0)okaysite[SITE_BUSINESS_BARANDGRILL] = 1;
	}
	else {
		if (okaySiteList.count(type)) {
			for (SiteTypes s : okaySiteList[type]) {
				okaysite[s] = 1;
			}
		}
		else {
			for (SiteTypes s : defaultSiteList) {
				okaysite[s] = 1;
			}
		}
	}
	int new_work_location = worklocation;
	char swap = 0;
	// TODO possible alwaysfalse conditional, investigate
	if (worklocation == -1) swap = 1;
	else if (!okaysite[(int)LocationsPool::getInstance().getLocationType((int)worklocation)]) swap = 1;
	if (swap)
	{
		//int city = location[location]->city;
		//PICK A TYPE OF WORK LOCATION
		//worklocation=choose_one(okaysite,SITENUM,0);
		//FIND ONE OF THESE
		vector<int> goodlist;
		//find_site_index_in_city(worklocation, location[location]->city);
		for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
			//if(location[l]->type==worklocation && (!multipleCityMode || location[l]->city == location))
			if (okaysite[(int)LocationsPool::getInstance().getLocationType(l)] &&
				(!multipleCityMode || LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONCITY,l)
					==
					LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONCITY,worklocation)))
				goodlist.push_back(l);
		// Sadler - This line sometimes causes a memory fault
		//               Only thing I can think of is if loop above didn't
		//               find any locations of type == to worklocation
		//               My hunch is that some locations, such as the 1st four
		//               are special and cannot be used here..
		//
		//   TODO There was a bug in the makecharacter() code where the
		//   SITE_OUTOFTOWN was not set properly. This was fixed but the bug here
		//   is still occurring, normally at the Latte Bar Downtown ;
		if (!len(goodlist)) new_work_location = 0;
		else new_work_location = pickrandom(goodlist);
	}
	return new_work_location;
}

