#include "../includes.h"
const string CONST_talk040 = "# ";
const string CONST_talk039 = "allText.txt";
const string CONST_talk038 = " ";
const string CONST_talk034 = "agree_to_release_hostages.txt";
const string CONST_talk033 = "go_ahead_and_die.txt";
const string CONST_talk032 = "let_hostages_go.txt";
const string CONST_talk031 = "please_no_more.txt";
const string CONST_talk030 = "hostage_negotiation.txt";
const string CONST_talk029 = "who_cares_about_hostage.txt";
const string CONST_talk028 = "please_spare_hostage.txt";
const string CONST_talk027 = "threaten_hostage.txt";
const string CONST_talk026 = "backs_off.txt";
const string CONST_talk025 = "come_at_me_bro.txt";
const string CONST_talk024 = "teller_complies.txt";
const string CONST_talk023 = "teller_gestures.txt";
const string CONST_talk022 = "robbing_bank.txt";
const string CONST_talk021 = "that_is_not_disturbing.txt";
const string CONST_talk020 = "that_is_disturbing.txt";
const string CONST_talk019 = "mutant_rejection.txt";
const string CONST_talk018 = "dog_rejection.txt";
const string CONST_talk017 = "normal_talk_to_dog.txt";
const string CONST_talk016 = "lovingly_talk_to_dog.txt";
const string CONST_talk015 = "normal_talk_to_mutant.txt";
const string CONST_talk014 = "lovingly_talk_to_mutant.txt";
const string CONST_talk013 = "pickupLines.txt";
const string CONST_talk012 = "no_free_speech_flirt.txt";

const string tag_ARMOR_MITHRIL = "ARMOR_MITHRIL";
const string tag_ARMOR = "ARMOR";
const string tag_ARMOR_DEATHSQUADUNIFORM = "ARMOR_DEATHSQUADUNIFORM";
const string tag_ARMOR_LABCOAT = "ARMOR_LABCOAT";
const string tag_ARMOR_BUNKERGEAR = "ARMOR_BUNKERGEAR";
const string tag_ARMOR_SWATARMOR = "ARMOR_SWATARMOR";
const string tag_ARMOR_POLICEUNIFORM = "ARMOR_POLICEUNIFORM";
const string blankString = "";
const string tag_ARMOR_POLICEARMOR = "ARMOR_POLICEARMOR";
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
// for renting
#include "../sitemode/sitedisplay.h"
#include "../items/money.h"
#include "../log/log.h"
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
// for void basesquad(squadst *st,long loc);

/*
daily.cpp
*/
/* active squad visits the arms dealer */
void armsdealer(int loc);

#include "../combat/fight.h"
// for void delenc(short e,char loot);
//void delenc(Creature &tk);
//void delenc(const int e, const int i);
#include "../combat/fightCreature.h"  
//for void capturecreature(Creature &t);
#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
void moveEverythingAwayFromSite(int cursite);
#include "../customMaps.h"

//const string tag_ARMOR_MITHRIL = "ARMOR_MITHRIL";
/*
daily.cpp
*/
/* active squad visits the arms dealer */
void armsdealer(int loc);

// #include "../combat/fight.h"
// for void delenc(short e,char loot);
void delenc(DeprecatedCreature &tk);
// #include "../locations/locationsPool.h"
void moveEverythingAwayFromSite(int cursite);
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
const string talky = "talk\\";
const int PICKUP_LINE_SIZE = 5;
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
const string talk_combat = "talk_combat\\";
const int DOUBLE_LINE = 2;
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
string while_naked;
char heyMisterDog(DeprecatedCreature &tk);
char heyMisterMonster(DeprecatedCreature &tk);
char talkInCombat(DeprecatedCreature &a, DeprecatedCreature &tk);
char talkToBankTeller(DeprecatedCreature &a, DeprecatedCreature &tk);
char talkToGeneric(DeprecatedCreature &a, DeprecatedCreature &tk);
char wannaHearSomethingDisturbing(DeprecatedCreature &a, DeprecatedCreature &tk);
char talkAboutIssues(DeprecatedCreature &a, DeprecatedCreature &tk);
char doYouComeHereOften(DeprecatedCreature &a, DeprecatedCreature &tk);
char heyINeedAGun(DeprecatedCreature &a, DeprecatedCreature &tk);
char heyIWantToRentARoom(DeprecatedCreature &a, DeprecatedCreature &tk);
char heyIWantToCancelMyRoom(DeprecatedCreature &a, DeprecatedCreature &tk);
map<short, string> conservativeLegalArgument;
map<short, vector<string> > talkAboutTheIssues;
map<short, string> youAreStupidTalkAboutIssues;
map<short, string> issueTooLiberal;
string saysComma;
string respondsComma;
string colonSpace;
string unnamed_String_Talk_cpp_001;
string unnamed_String_Talk_cpp_002;
string unnamed_String_Talk_cpp_003;
string unnamed_String_Talk_cpp_004;
string unnamed_String_Talk_cpp_005;
string unnamed_String_Talk_cpp_006;
string unnamed_String_Talk_cpp_007;
string unnamed_String_Talk_cpp_008;
string unnamed_String_Talk_cpp_009;
string unnamed_String_Talk_cpp_010;
string unnamed_String_Talk_cpp_011;
string unnamed_String_Talk_cpp_012;
string unnamed_String_Talk_cpp_013;
string unnamed_String_Talk_cpp_014;
string unnamed_String_Talk_cpp_015;
string unnamed_String_Talk_cpp_016;
string unnamed_String_Talk_cpp_017;
string unnamed_String_Talk_cpp_018;
string unnamed_String_Talk_cpp_019;
string unnamed_String_Talk_cpp_020;
string unnamed_String_Talk_cpp_021;
string unnamed_String_Talk_cpp_022;
string unnamed_String_Talk_cpp_023;
string unnamed_String_Talk_cpp_024;
string unnamed_String_Talk_cpp_025;
string unnamed_String_Talk_cpp_026;
string unnamed_String_Talk_cpp_027;
string unnamed_String_Talk_cpp_028;
string unnamed_String_Talk_cpp_029;
string unnamed_String_Talk_cpp_030;
string unnamed_String_Talk_cpp_031;
string unnamed_String_Talk_cpp_032;
string unnamed_String_Talk_cpp_033;
string unnamed_String_Talk_cpp_034;
string unnamed_String_Talk_cpp_035;
string unnamed_String_Talk_cpp_036;
string unnamed_String_Talk_cpp_037;
string unnamed_String_Talk_cpp_038;
string unnamed_String_Talk_cpp_039;
string unnamed_String_Talk_cpp_040;
string unnamed_String_Talk_cpp_041;
string unnamed_String_Talk_cpp_042;
string unnamed_String_Talk_cpp_043;
string unnamed_String_Talk_cpp_044;
string unnamed_String_Talk_cpp_045;
string unnamed_String_Talk_cpp_046;
string unnamed_String_Talk_cpp_047;
string unnamed_String_Talk_cpp_048;
string unnamed_String_Talk_cpp_049;
string unnamed_String_Talk_cpp_050;
string unnamed_String_Talk_cpp_051;
string unnamed_String_Talk_cpp_052;
string unnamed_String_Talk_cpp_053;
string unnamed_String_Talk_cpp_054;
string unnamed_String_Talk_cpp_055;
string unnamed_String_Talk_cpp_056;
string unnamed_String_Talk_cpp_057;
string unnamed_String_Talk_cpp_058;
string unnamed_String_Talk_cpp_059;
string unnamed_String_Talk_cpp_060;
string unnamed_String_Talk_cpp_061;
string unnamed_String_Talk_cpp_062;
string unnamed_String_Talk_cpp_063;
string unnamed_String_Talk_cpp_064;
string unnamed_String_Talk_cpp_065;
string unnamed_String_Talk_cpp_066;
string unnamed_String_Talk_cpp_067;
string unnamed_String_Talk_cpp_068;
string unnamed_String_Talk_cpp_069;
string unnamed_String_Talk_cpp_070;
string unnamed_String_Talk_cpp_071;
string unnamed_String_Talk_cpp_072;
string unnamed_String_Talk_cpp_073;
string unnamed_String_Talk_cpp_074;
string unnamed_String_Talk_cpp_075;
string unnamed_String_Talk_cpp_076;
string unnamed_String_Talk_cpp_077;
string unnamed_String_Talk_cpp_078;
string unnamed_String_Talk_cpp_079;
string unnamed_String_Talk_cpp_080;
string unnamed_String_Talk_cpp_081;
string unnamed_String_Talk_cpp_082;
string unnamed_String_Talk_cpp_083;
string unnamed_String_Talk_cpp_084;
string unnamed_String_Talk_cpp_085;
string unnamed_String_Talk_cpp_086;
string unnamed_String_Talk_cpp_087;
string unnamed_String_Talk_cpp_088;
string unnamed_String_Talk_cpp_089;
string unnamed_String_Talk_cpp_090;
string unnamed_String_Talk_cpp_091;
string unnamed_String_Talk_cpp_092;
string unnamed_String_Talk_cpp_093;
string unnamed_String_Talk_cpp_094;
string unnamed_String_Talk_cpp_095;
string unnamed_String_Talk_cpp_096;
string unnamed_String_Talk_cpp_097;
string unnamed_String_Talk_cpp_098;
string unnamed_String_Talk_cpp_099;
string unnamed_String_Talk_cpp_100;
string unnamed_String_Talk_cpp_101;
string unnamed_String_Talk_cpp_102;
string unnamed_String_Talk_cpp_103;
string unnamed_String_Talk_cpp_104;
string unnamed_String_Talk_cpp_105;
string unnamed_String_Talk_cpp_106;
string unnamed_String_Talk_cpp_107;
string unnamed_String_Talk_cpp_108;
string unnamed_String_Talk_cpp_109;
string unnamed_String_Talk_cpp_110;
string unnamed_String_Talk_cpp_111;
string unnamed_String_Talk_cpp_112;
string unnamed_String_Talk_cpp_113;
string unnamed_String_Talk_cpp_114;
string unnamed_String_Talk_cpp_115;
string unnamed_String_Talk_cpp_116;
string unnamed_String_Talk_cpp_117;
string unnamed_String_Talk_cpp_118;
string unnamed_String_Talk_cpp_119;
string unnamed_String_Talk_cpp_120;
string unnamed_String_Talk_cpp_121;
string unnamed_String_Talk_cpp_122;
string unnamed_String_Talk_cpp_123;
string unnamed_String_Talk_cpp_124;
string unnamed_String_Talk_cpp_125;
string unnamed_String_Talk_cpp_126;
string unnamed_String_Talk_cpp_127;
string unnamed_String_Talk_cpp_128;
string unnamed_String_Talk_cpp_129;
string unnamed_String_Talk_cpp_130;
string unnamed_String_Talk_cpp_131;
string unnamed_String_Talk_cpp_132;
string unnamed_String_Talk_cpp_133;
string unnamed_String_Talk_cpp_134;
string unnamed_String_Talk_cpp_135;
string unnamed_String_Talk_cpp_136;
string unnamed_String_Talk_cpp_137;
string unnamed_String_Talk_cpp_138;
string unnamed_String_Talk_cpp_139;
string unnamed_String_Talk_cpp_140;
string unnamed_String_Talk_cpp_141;
string unnamed_String_Talk_cpp_142;
string unnamed_String_Talk_cpp_143;
string unnamed_String_Talk_cpp_144;
string unnamed_String_Talk_cpp_145;
string unnamed_String_Talk_cpp_146;
string unnamed_String_Talk_cpp_147;
string unnamed_String_Talk_cpp_148;
string unnamed_String_Talk_cpp_149;
/* bluff, date, issues */
bool isThereASiteAlarm();

short getCurrentSite();
char talk(DeprecatedCreature &a, const int t)
{
	extern DeprecatedCreature encounter[ENCMAX];
	DeprecatedCreature &tk = encounter[t];
	// TALKING TO DOGS
	if (tk.type == CREATURE_GUARDDOG && tk.align != ALIGN_LIBERAL)
	{
		return heyMisterDog(tk);
	}
	// TALKING TO MONSTERS
	if (tk.type == CREATURE_GENETIC && tk.align != ALIGN_LIBERAL)
	{
		return heyMisterMonster(tk);
	}
	// BLUFFING
	if ((isThereASiteAlarm() || LocationsPool::getInstance().isThereASiegeHere(getCurrentSite())) && tk.enemy())
	{
		return talkInCombat(a, tk);
	}
	return talkToGeneric(a, tk);
}
const string singleSpace = " ";
extern string singleDot;
void setSiteAlarmOne();
void setEncounterZeroExistsFalse();
void giveActiveSquadThisLoot(Item* de);
char talkToBankTeller(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	extern Log gamelog;

	extern Deprecatednewsstoryst *sitestory;
	extern int sitecrime;
	extern Deprecatedsquadst *activesquad;
	extern short sitealienate;

	extern string slogan_str;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short sitealarmtimer;
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
			return wannaHearSomethingDisturbing(a, tk);
		case 'b':
			if (!tk.can_date(a.getCreatureBio().age, a.animalgloss)) break;
			return doYouComeHereOften(a, tk);
		case 'c':
			return 0;
		case 'd':
			if (tk.type == CREATURE_LANDLORD && LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE, getCurrentSite()) == -1)
				return heyIWantToRentARoom(a, tk);
			else if (tk.type == CREATURE_LANDLORD && LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE, getCurrentSite()) > 0)
				return heyIWantToCancelMyRoom(a, tk);
			else if (tk.type == CREATURE_GANGMEMBER || tk.type == CREATURE_MERC)
				return heyINeedAGun(a, tk);
			else if (tk.type == CREATURE_BANK_TELLER)
				return talkToBankTeller(a, tk);
			break;
		}
	}
}
// #include "../common/creaturePool.h"
void locationIsNowRented(int l, int rent);
char heyIWantToCancelMyRoom(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	extern Log gamelog;
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
		return 1;
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

	return 1;
}

/* common - assigns a new base to all members of a squad */
void basesquad(Deprecatedsquadst *st, long loc);
char heyIWantToRentARoom(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	extern Log gamelog;
	extern char newscherrybusted;
	extern Deprecatedsquadst *activesquad;
	extern class Ledger ledger;
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
		return 1;
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
			return 1;
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
			return 1;
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
				return 1;
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
				return 1;
			}
		}
	}
}

char heyINeedAGun(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	extern Log gamelog;
	extern short lawList[LAWNUM];
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
		mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_052, gamelog);
		gamelog.newline();
		pressAnyKey();
		return 1;
	}
	if (isThereASiteAlarm())
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_053, gamelog);
		gamelog.newline();
		pressAnyKey();
		return 1;
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
		return 1;
	default:
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_055, gamelog);
		gamelog.newline();
		pressAnyKey();
		return 1;
	}
}
char wannaHearSomethingDisturbing(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	extern Log gamelog;
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
		return 1;
	}
	else if (strcmp(tk.getNameAndAlignment().name.data(), unnamed_String_Talk_cpp_060.data()) != 0 && interested)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(12, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_061, gamelog);
		gamelog.newline();
		pressAnyKey();
		return talkAboutIssues(a, tk);
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
		return 1;
	}
}
int getCity(int l);
void newDate(DeprecatedCreature &a, DeprecatedCreature &tk);
char doYouComeHereOften(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	extern Log gamelog;
	extern short lawList[LAWNUM];
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
		return 1;
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
	return 1;
}
void newRecruit(DeprecatedCreature *cr, int c);
char talkAboutIssues(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	extern Log gamelog;
	extern char newscherrybusted;
	extern short lawList[LAWNUM];
	const int lw = LCSrandom(LAWNUM); // pick a random law to talk about
	bool succeeded = false;
	bool you_are_stupid = false;
	bool issue_too_liberal = false;
	if (!(a.attribute_check(ATTRIBUTE_INTELLIGENCE, DIFFICULTY_EASY)))
		you_are_stupid = true;
	else if (lawList[lw] == ALIGN_ELITELIBERAL && newscherrybusted)
		issue_too_liberal = true;
	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, a.getNameAndAlignment().name, gamelog);
	addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	int y = 10;
	if (you_are_stupid)
	{
		if (lw == LAW_POLICEBEHAVIOR) {
			if (lawList[LAW_FREESPEECH] == ALIGN_ARCHCONSERVATIVE)
				mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_076, gamelog);
			else
				mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_077, gamelog);
		}
		else {
			mvaddstrAlt(y++, 1, youAreStupidTalkAboutIssues[lw]);
		}
	}
	else if (issue_too_liberal)
	{

		mvaddstrAlt(y++, 1, issueTooLiberal[lw]);
	}
	else
	{
		if (lw == LAW_POLLUTION) {
			mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_078, gamelog);
			if (tk.animalgloss == ANIMALGLOSS_ANIMAL) mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_079, gamelog);
			else mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_080, gamelog);
		}
		else {
			mvaddstrAlt(y++, 1, talkAboutTheIssues[lw][0], gamelog);
			mvaddstrAlt(y++, 1, talkAboutTheIssues[lw][1], gamelog);
		}
	}
	gamelog.newline();
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
	// Prisoners never accept to join you, you must liberate them instead
	if (succeeded && strcmp(tk.getNameAndAlignment().name.data(), unnamed_String_Talk_cpp_081.data()) != 0)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt((++y)++, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		if (tk.type == CREATURE_MUTANT && tk.get_attribute(ATTRIBUTE_INTELLIGENCE, true) < 3)
			mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_082, gamelog);
		else
		{
			switch (LCSrandom(10))
			{
			case 0: mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_083, gamelog);
				pressAnyKey();
				set_color_easy(GREEN_ON_BLACK_BRIGHT);
				mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_084, gamelog);
				break;
			case 1: mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_085, gamelog);
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				addstrAlt(unnamed_String_Talk_cpp_086, gamelog);
				break;
			default:
				mvaddstrAlt(y++, 1, pickrandom(that_is_disturbing), gamelog);
				break;
			}
		}
		gamelog.newline();
		pressAnyKey();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(++y, 1, unnamed_String_Talk_cpp_087, gamelog);
		addstrAlt(tk.getNameAndAlignment().name, gamelog);
		addstrAlt(unnamed_String_Talk_cpp_088, gamelog);
		gamelog.newline();
		pressAnyKey();
		DeprecatedCreature *newcr = new DeprecatedCreature;
		*newcr = tk;
		newcr->namecreature();
		newRecruit(newcr, a.id);
		delenc(tk);
		return 1;
	}
	else
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt((++y)++, 1, tk.getNameAndAlignment().name, gamelog); addstrAlt(respondsComma, gamelog);
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		if (tk.type == CREATURE_MUTANT &&
			tk.get_attribute(ATTRIBUTE_INTELLIGENCE, true) < 3)
		{
			mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_089, gamelog);
		}
		else
		{
			if (tk.align == ALIGN_CONSERVATIVE && you_are_stupid)
			{
				if (tk.type == CREATURE_GANGUNIT)
					mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_090, gamelog);
				else if (tk.type == CREATURE_DEATHSQUAD)
					mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_091, gamelog);
				else
				{
					mvaddstrAlt(y++, 1, pickrandom(that_is_not_disturbing), gamelog);
				}
			}
			else if (tk.align != ALIGN_LIBERAL && tk.attribute_check(ATTRIBUTE_WISDOM, DIFFICULTY_AVERAGE))
			{
				mvaddstrAlt(y++, 1, conservativeLegalArgument[lw], gamelog);
			}
			else
			{
				mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_092, gamelog);
			}
		}
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		addstrAlt(unnamed_String_Talk_cpp_093, gamelog);
		gamelog.newline();
		pressAnyKey();
		tk.make_cantbluff_one();
		return 1;
	}
}
vector<NameAndAlignment> getEncounterNameAndAlignment();
int encounterWisdomRoll(const int e);
void pressKeyAInCombat(DeprecatedCreature &a) {
	extern Log gamelog;
	extern Deprecatednewsstoryst *sitestory;
	extern short attitude[VIEWNUM];
	extern string slogan_str;
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, a.getNameAndAlignment().name, gamelog);
	addstrAlt(colonSpace, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	switch (LCSrandom(4))
	{
	case 0:
	{   // Formatting the slogan so that it always has quotes around it and punctuation
		if (slogan_str[0] != '"') mvaddcharAlt(17, 1, '"');
		mvaddstrAlt(17, 1 + (slogan_str[0] != '"' ? 1 : 0), slogan_str, gamelog);
		const int last = len(slogan_str);
		if (last && slogan_str[last - 1] != '"' && slogan_str[last - 1] != '!' && slogan_str[last - 1] != '.' && slogan_str[last - 1] != '?')
			addcharAlt('!', gamelog);
		if (last && slogan_str[last - 1] != '"') addcharAlt('"', gamelog);
		if (!sitestory->claimed)
			sitestory->claimed = 1;
		break;
	}
	default:
		mvaddstrAlt(17, 1, pickrandom(come_at_me_bro), gamelog);
		break;
	}
	pressAnyKey();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
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
				clearmessagearea();
				mvaddstrAlt(16, 1, encounter[e].name, gamelog);
				addstrAlt(singleSpace + pickrandom(backs_off), gamelog);
				delenc(e, 0);
				addjuice(a, 2, 200); // Instant juice!
				pressAnyKey();
			}
		}
	}
}
vector<NameAndAlignment> getEncounterNameAndAlignment();
void pressedKeyAWithHostage(DeprecatedCreature &a, const int hostages, const int e) {
	extern Log gamelog;
	extern int sitecrime;
	extern short lawList[LAWNUM];
	extern Deprecatednewsstoryst *sitestory;
	extern Deprecatedsquadst *activesquad;
	extern short exec[EXECNUM];
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();
	DeprecatedCreature* executer = 0;
	if (a.is_holding_body())
		executer = &a;
	else for (int i = 0; i < 6; i++)
	{
		if (activesquad->squad[i] &&
			activesquad->squad[i]->is_holding_body() &&
			activesquad->squad[i]->prisoner->alive &&
			activesquad->squad[i]->prisoner->enemy())
		{
			executer = activesquad->squad[i];
			break;
		}
	}
	set_color_easy(RED_ON_BLACK_BRIGHT);
	{
		string executerGetAmmo;
		if (executer->get_weapon().is_ranged()
			&& executer->get_weapon().get_ammoamount() > 0)
		{
			executerGetAmmo = (unnamed_String_Talk_cpp_113);
			executer->get_weapon().decrease_ammo(1); //What if it doesn't use ammo? -XML
		}
		else
		{
			executerGetAmmo = (unnamed_String_Talk_cpp_114);
		}
		mvaddstrAlt(16, 1, executerGetAmmo, gamelog);
	}
	gamelog.newline();
	pressAnyKey();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(17, 1, executer->getNameAndAlignment().name, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_115, gamelog);
	addstrAlt(executer->prisoner->getNameAndAlignment().name, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_116, gamelog);
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
	makeloot(*executer->prisoner);
	pressAnyKey();
	delete_and_nullify(executer->prisoner);
	if (hostages > 1 && LCSrandom(2))
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, encounter[e].name, gamelog);
		addstrAlt(colonSpace, gamelog);
		set_color_easy(RED_ON_BLACK_BRIGHT);
		mvaddstrAlt(17, 1, lawList[LAW_FREESPEECH] > ALIGN_ARCHCONSERVATIVE ? unnamed_String_Talk_cpp_117 : unnamed_String_Talk_cpp_118, gamelog);
		addstrAlt(pickrandom(please_no_more), gamelog);
		gamelog.newline();
		for (int i = ENCMAX - 1; i >= 0; i--)
			if (encounter[i].exists && encounter[i].enemy && encounter[i].alive)
				delenc(i, 0);
		pressAnyKey();
	}
}
void pressedKeyBWithHostage(DeprecatedCreature &a, const int hostages, const int e) {
	extern Log gamelog;
	extern int sitecrime;
	extern short lawList[LAWNUM];
	extern Deprecatednewsstoryst *sitestory;
	extern Deprecatedsquadst *activesquad;
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();
	extern short exec[EXECNUM];

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, a.getNameAndAlignment().name, gamelog);
	addstrAlt(colonSpace, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	{
		string nameHostages;
		if (LCSrandom(5))
		{
			if (hostages > 1) nameHostages = (unnamed_String_Talk_cpp_119);
			else nameHostages = (unnamed_String_Talk_cpp_120);
		}
		else {
			nameHostages = (pickrandom(let_hostages_go));
		}
		mvaddstrAlt(17, 1, nameHostages, gamelog);
	}
	gamelog.newline();
	pressAnyKey();
	if (((encounter[e].type == CREATURE_DEATHSQUAD ||
		encounter[e].type == CREATURE_AGENT ||
		encounter[e].type == CREATURE_MERC ||
		encounter[e].type == CREATURE_CCS_ARCHCONSERVATIVE ||
		encounter[e].type == CREATURE_GANGUNIT) &&
		LCSrandom(2)) && encounter[e].align == ALIGN_CONSERVATIVE)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, encounter[e].name, gamelog);
		addstrAlt(colonSpace, gamelog);
		set_color_easy(RED_ON_BLACK_BRIGHT);
		mvaddstrAlt(17, 1, pickrandom(go_ahead_and_die), gamelog);
		gamelog.newline();
		pressAnyKey();
	}
	else
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, encounter[e].name, gamelog);
		addstrAlt(colonSpace, gamelog);
		set_color_easy(RED_ON_BLACK_BRIGHT);
		mvaddstrAlt(17, 1, pickrandom(agree_to_release_hostages), gamelog);
		gamelog.newline();
		pressAnyKey();
		for (int i = ENCMAX - 1; i >= 0; i--)
			if (encounter[i].exists&&encounter[i].enemy && encounter[i].alive)
				delenc(i, 0);
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		juiceparty(15, 200); // Instant juice for successful hostage negotiation
		mvaddstrAlt(16, 1, hostages > 1 ? unnamed_String_Talk_cpp_121 : unnamed_String_Talk_cpp_122, gamelog);
		gamelog.newline();
		for (int i = 0; i < 6; i++)
		{
			if (activesquad->squad[i] &&
				activesquad->squad[i]->is_holding_body() &&
				activesquad->squad[i]->prisoner->enemy())
			{
				delete_and_nullify(activesquad->squad[i]->prisoner);
			}
		}
		pressAnyKey();
	}
}
void pressKeyBInCombat(DeprecatedCreature &a, DeprecatedCreature &tk, const int hostages, const int weaponhostage) {
	extern int sitecrime;
	extern Log gamelog;
	extern short lawList[LAWNUM];
	extern Deprecatednewsstoryst *sitestory;
	extern Deprecatedsquadst *activesquad;
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();
	extern short exec[EXECNUM];

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, a.getNameAndAlignment().name + colonSpace, gamelog);
	{
		string anotherHostageThing;
		switch (LCSrandom(6))
		{
		case 0:anotherHostageThing = (unnamed_String_Talk_cpp_100);
			if (!sitestory->claimed)sitestory->claimed = 1; break;
		case 1:
			if (lawList[LAW_FREESPEECH] == -2)anotherHostageThing = (unnamed_String_Talk_cpp_101);
			else anotherHostageThing = (unnamed_String_Talk_cpp_102);
			break;
		default:
			anotherHostageThing = (pickrandom(threaten_hostage));
			break;
		}
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		mvaddstrAlt(17, 1, anotherHostageThing, gamelog);
	}
	gamelog.newline();
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
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					clearmessagearea();
					mvaddstrAlt(16, 1, encounter[e].name, gamelog);
					addstrAlt(colonSpace, gamelog);
					if (encounter[e].align != ALIGN_CONSERVATIVE ||
						(encounter[e].type == CREATURE_SECRET_SERVICE && exec[EXEC_PRESIDENT] > ALIGN_CONSERVATIVE))
					{
						set_color_easy(GREEN_ON_BLACK_BRIGHT);
						mvaddstrAlt(17, 1, pickrandom(please_spare_hostage), gamelog);
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
							mvaddstrAlt(17, 1, pickrandom(who_cares_about_hostage), gamelog);
						}
						else
						{
							string moreHostageQuestions;
							if (LCSrandom(5)) {
								moreHostageQuestions = (pickrandom(hostage_negotiation));
							}
							else {
								if (hostages > 1)
									moreHostageQuestions = (unnamed_String_Talk_cpp_103);
								else moreHostageQuestions = (unnamed_String_Talk_cpp_104);
							}
							mvaddstrAlt(17, 1, moreHostageQuestions, gamelog);
						}
					}
					gamelog.newline();
					pressAnyKey();
					noretreat = true;
					break;
				}
			}
		}
		if (e == ENCMAX) { e--; }
		if (noretreat == false)
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			clearmessagearea();
			mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_105, gamelog);
			gamelog.newline();
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
			set_color_easy(WHITE_ON_BLACK);
			clearcommandarea();
			clearmessagearea();
			clearmaparea();
			mvaddstrAlt(9, 1, unnamed_String_Talk_cpp_106);
			addstrAlt(a.getNameAndAlignment().name);
			addstrAlt(unnamed_String_Talk_cpp_107);
			mvaddstrAlt(11, 1, hostages > 1 ? (unnamed_String_Talk_cpp_108) : (unnamed_String_Talk_cpp_109));
			mvaddstrAlt(12, 1, hostages > 1 ? (unnamed_String_Talk_cpp_110) : (unnamed_String_Talk_cpp_111));
			mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_112);
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
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		clearmessagearea();
		mvaddstrAlt(16, 1, tk.getNameAndAlignment().name, gamelog);
		addstrAlt(unnamed_String_Talk_cpp_123, gamelog);
		gamelog.newline();
		pressAnyKey();
	}
}
int getDifficultyBasedOnEncounterWisdom(const int e);
void pressKeyCInCombat(DeprecatedCreature &a) {
	extern Log gamelog;
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short lawList[LAWNUM];
	extern coordinatest loc_coord;
	extern short siteonfire;
	extern short fieldskillrate;

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	if (LocationsPool::getInstance().isThereASiegeHere(getCurrentSite()))
	{
		mvaddstrAlt(16, 1, a.getNameAndAlignment().name, gamelog);
		addstrAlt(singleSpace, gamelog);
		switch (LocationsPool::getInstance().getSiegeType(getCurrentSite()))
		{
		case SIEGE_POLICE:
			addstrAlt(unnamed_String_Talk_cpp_124, gamelog);
			break;
		case SIEGE_CIA:
			addstrAlt(unnamed_String_Talk_cpp_125, gamelog);
			break;
		case SIEGE_CCS:
		case SIEGE_HICKS:
			switch (LCSrandom(2))
			{
			case 0:
				addstrAlt(unnamed_String_Talk_cpp_126, gamelog);
				mvaddstrAlt(17, 1, unnamed_String_Talk_cpp_127, gamelog);
				break;
			case 1:
				addstrAlt(unnamed_String_Talk_cpp_128, gamelog);
				mvaddstrAlt(17, 1, unnamed_String_Talk_cpp_129, gamelog);
				break;
			}
			break;
		case SIEGE_CORPORATE:
			addstrAlt(unnamed_String_Talk_cpp_130, gamelog);
			break;
		case SIEGE_FIREMEN:
			addstrAlt(unnamed_String_Talk_cpp_131, gamelog);
			if ((!(levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].flag & SITEBLOCK_FIRE_END) ||
				!(levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].flag & SITEBLOCK_FIRE_PEAK) ||
				!(levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].flag & SITEBLOCK_FIRE_START) ||
				!(levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].flag & SITEBLOCK_DEBRIS)) && !LCSrandom(10))
			{
				levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].flag |= SITEBLOCK_FIRE_START;
				mvaddstrAlt(17, 1, unnamed_String_Talk_cpp_132, gamelog);
				gamelog.newline();
				mvaddstrAlt(18, 1, unnamed_String_Talk_cpp_133, gamelog);
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
			mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_134, gamelog);
		}
		else if (a.get_armor().get_itemtypename() == tag_ARMOR_BUNKERGEAR)
		{
			if (siteonfire) mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_135, gamelog);
			else mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_136, gamelog);
		}
		else if (a.get_armor().get_itemtypename() == tag_ARMOR_LABCOAT)
			mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_137, gamelog);
		else if (a.get_armor().get_itemtypename() == tag_ARMOR_DEATHSQUADUNIFORM)
			mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_138, gamelog);
		else if (a.get_armor().get_itemtypename() == tag_ARMOR_MITHRIL)
		{
			mvaddstrAlt(16, 1, a.getNameAndAlignment().name, gamelog);
			addstrAlt(unnamed_String_Talk_cpp_139, gamelog);
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			addstrAlt(unnamed_String_Talk_cpp_140, gamelog);     //Fanciful multicolor message
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			addstrAlt(unnamed_String_Talk_cpp_141, gamelog);
		}
		else
		{
			mvaddstrAlt(16, 1, a.getNameAndAlignment().name, gamelog);
			addstrAlt(unnamed_String_Talk_cpp_142, gamelog);
			mvaddstrAlt(17, 1, unnamed_String_Talk_cpp_143, gamelog);
		}

	}
	gamelog.newline();
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
		clearmessagearea();
		set_color_easy(RED_ON_BLACK_BRIGHT);
		if (encounter[e].type == CREATURE_HICK)
		{
			mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_144, gamelog);
			addstrAlt(encounter[e].name, gamelog);
			addstrAlt(unnamed_String_Talk_cpp_145, gamelog);
		}
		else
		{
			mvaddstrAlt(16, 1, encounter[e].name, gamelog);
			if (lawList[LAW_FREESPEECH] == ALIGN_ARCHCONSERVATIVE)
				addstrAlt(unnamed_String_Talk_cpp_146, gamelog);
			else addstrAlt(unnamed_String_Talk_cpp_147, gamelog);
		}
		pressAnyKey();
	}
	else
	{
		clearmessagearea();
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_148, gamelog);
		pressAnyKey();
		for (int e = ENCMAX - 1; e >= 0; e--)
			if (encounter[e].exists&&encounter[e].alive&&encounter[e].enemy)
				delenc(e, 0);
	}
	gamelog.newline();
}

void pressKeyDInCombat() {
	extern Log gamelog;
	extern Deprecatedsquadst *activesquad;

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(14, 1, unnamed_String_Talk_cpp_149, gamelog);
	gamelog.newline();
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
char haveActiveSquadTalk(const int sp, const int tk) {
	extern Deprecatedsquadst *activesquad;
	return talk(*activesquad->squad[sp], tk);
}
char talkInCombat(DeprecatedCreature &a, DeprecatedCreature &tk)
{
	extern Log gamelog;
	extern Deprecatednewsstoryst *sitestory;
	extern int sitecrime;
	extern Deprecatedsquadst *activesquad;
	extern coordinatest loc_coord;
	extern short siteonfire;
	extern short fieldskillrate;

	extern short exec[EXECNUM];
	extern string slogan_str;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short lawList[LAWNUM];
	extern short attitude[VIEWNUM];

	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, a.getNameAndAlignment().name, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_094, gamelog);
	switch (tk.align)
	{
	case ALIGN_CONSERVATIVE: set_color_easy(RED_ON_BLACK_BRIGHT); break;
	case ALIGN_LIBERAL: set_color_easy(GREEN_ON_BLACK_BRIGHT); break;
	case ALIGN_MODERATE: set_color_easy(WHITE_ON_BLACK_BRIGHT); break;
	}
	addstrAlt(tk.getNameAndAlignment().name, gamelog);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	addstrAlt(unnamed_String_Talk_cpp_095, gamelog);
	gamelog.newline();
	int c = 0, hostages = 0, weaponhostage = 0;
	bool cop = 0;
	for (int i = 0; i < 6; i++)
	{
		if (activesquad->squad[i] &&
			activesquad->squad[i]->is_holding_body() &&
			activesquad->squad[i]->prisoner->alive&&
			activesquad->squad[i]->prisoner->enemy())
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
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(11, 1, unnamed_String_Talk_cpp_096);
	if (!hostages)set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, unnamed_String_Talk_cpp_097);
	if (!tk.is_cantbluff_two())set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_098);
	if (cop)set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(14, 1, unnamed_String_Talk_cpp_099);
	set_color_easy(WHITE_ON_BLACK);

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
	return 1;
}
int findMostHeartfulLiberal() {
	extern Deprecatedsquadst *activesquad;

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
void printSpecialRecruitment(const string aname, const string tkname, const string pitch, const string response) {
	extern Log gamelog;
	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, aname, gamelog);
	addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(11, 1, pitch, gamelog);
	gamelog.newline();
	pressAnyKey();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, tkname, gamelog);
	addstrAlt(saysComma, gamelog);
	set_color_easy(YELLOW_ON_BLACK_BRIGHT);
	mvaddstrAlt(14, 1, response, gamelog);
	gamelog.newline();
	pressAnyKey();

}
void liberalizeEncounterIfThisType(const int type);
char heyMisterDog(DeprecatedCreature &tk)
{
	extern Log gamelog;
	extern Deprecatedsquadst *activesquad;
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

	if (success)
		liberalizeEncounterIfThisType(CREATURE_GUARDDOG);
	return 1;
}
char heyMisterMonster(DeprecatedCreature &tk)
{
	extern Log gamelog;
	extern Deprecatedsquadst *activesquad;
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

	if (success)
		liberalizeEncounterIfThisType(CREATURE_GENETIC);
	return 1;
}


//const string CONST_talk039 = "allText.txt";
string study_string1;
string study_string2;
vector<string> allText;
vector<file_and_text_collection> text_file_collection = {
	customText(&allText, CONST_talk039),
};



extern string findingBugs;
extern string undefined;
extern string NONE;
extern string YEA;
extern string NAY;
extern string AND;
extern string counts_of;
extern string feels_sick_and;
extern string check_status_of_squad_liberal;
extern string show_squad_liberal_status;
extern string change_squad_order;
extern string string_sleeper;
extern string execution_in_three_months;
extern string major_news_take_it_up;
extern string they_are_stashed;
extern string they_ll_round_you_up;
extern string conservativesRemakeWorld;
extern string bound_to_rile_up;
extern string establishPrisonReform;
extern string improvePrisonConditions;
extern string stalinistsRemakeWorld;
extern string chooseALiberalTo;
extern string youWentOnVacation;
extern string youWentIntoHiding;
extern string whileYouWereInPrison;
extern string youDisappearedSafely;
extern string proposeConservative;
extern string proposeStalinist;
extern string enter_done;
extern string beingFollowedBySwine;
extern string lostThem;
extern string hereTheyCome;
extern string spaceDashSpace;
extern string currentLocation;
extern string safeHouse;
extern string enemySafeHouse;
extern string closedDown;
extern string highSecurity;
extern string needCar;
extern string spaceParanthesisDollar;
extern string paranthesisDollar;
extern string closeParenthesis;
extern string underSiege;
extern string percentSign;
extern string secrecyLevel;
extern string heatLevel;
extern string travelDifCity;
extern string smellsPanic;
extern string moderateLC;
extern string buggyString;
extern string isSeized;
extern string selectA;
extern string selectAn;
extern string enterDash;
extern string accordingToSourcesAtScene;
extern string accordingToPoliceSources;
extern string ampersandR;
extern string singleDot;
extern string membersOfLCS;
extern string lcsSpokeseperson;
extern string policeSpokesperson;
extern string pressKeyToReflect;
extern string pressLToViewHighScores;
extern string ampersandC;
extern string saysComma;
extern string while_naked;
extern string respondsComma;
extern string colonSpace;
extern string theLCS;
extern string notASkill;
extern string notAnAttribute;
extern string vehicleSportsCar;
extern string aNewConEra;
extern string theYearIs;
extern string conservativePresident;
extern string endsSecondTerm;
extern string highSeventiesApprovePres;
extern string conMajorityHouse;
extern string senateConMajority;
extern string beginningOfNew;
extern string conEra;
extern string thePresident;
extern string hasAskedCongressBeQuick;
extern string rubberStampArchCon;
extern string theLeftSeems;
extern string powerlessToStop;
extern string inThisDarkTime;
extern string whatIsYourName;
extern string pressEnterToBeRealName;
extern string invalidTag;
extern string theDocSaid;
extern string aBoy;
extern string aGirl;
extern string intersex;
extern string myParents;
extern string insistedOtherwise;
extern string they;
extern string namedMe;
extern string error;
extern string theFounder;
extern string firstName;
extern string pressAtoReconsider;
extern string lastName;
extern string pressBtoBeReborn;
extern string sexIs;
extern string male;
extern string female;
extern string itsComplicated;
extern string pressCtoChangeSex;
extern string history;
extern string letMeChoose;
extern string letFateDecide;
extern string pressDtoToggle;
extern string city;
extern string pressEtoRelocate;
extern string pressAnyKeyString;
extern string allOptions;
extern string unSelected;
extern string isSelected;
extern string pressAnyOtherKey;
extern string notCreature;
extern string notValidMap;
extern string notSpecialWound;
extern string newGameAdvanced;
extern string a_classicMode;
extern string b_weDidntStartIt;
extern string c_nightmareMode;
extern string d_nationalLCS;
extern string e_marathonMode;
extern string f_stalinistMode;
extern string newGameYourAgenda;
extern string a_noComprimise;
extern string b_democrat;
extern string newGameFieldLearn;
extern string affectsTheseSkills;
extern string a_fastSkills;
extern string b_classic;
extern string c_hardMode;
extern string deleteSave;
extern string chooseSave;
extern string titleScreenLine;
extern string newGame;
extern string pressToSelectSave;
extern string pressToDeleteSave;
extern string vToSwitchXToQuit;
extern string areYouSureDelte;
extern string questionYSlashN;
extern string pressMtoTurnOffMusic;
extern string pressMtoTurnOnMusic;
extern string inWhatWorld;
extern string enterNameForSave;
extern string pleaseEnterName;
extern string prettyPlease;
extern string justEnterName;
extern string liberalCrimeSquad;
extern string inspiredByOubliette;
extern string copyrightTarn;
extern string bayTwelveProductions;
extern string lcsHyperlink;
extern string vChar;
extern string maintainedByOpenSource;
extern string kingDrakeHyperlink;
extern string lcsForumHyperlink;
extern string lcsWikiHyperlink;
extern string pressESCToQuit;
extern string pressAnyKeyToPursue;
extern string plusChar;
extern string dotDat;
extern string itemType;
extern string doesNotExistItem;
extern string vehicleType;
extern string doesNotExistVehicle;
extern string couldNotLoad;
extern string itemClassClip;
extern string itemClassWeapon;
extern string itemClassArmor;
extern string itemClassLoot;
extern string itemClassMoney;
extern string failedToLoadSitemaps;
extern string debugCode;
extern string activated;
extern string failedToLoad;
extern string exclamationPoint;
extern string defaultMissingForMask;
extern string defaultUnknownForMask;
extern string ableToStopBleed;
extern string sWounds;
extern string isBurned;
extern string drops;
extern string sBody;
extern string hasBeenCaughtSnooping;
extern string isNowHomeless;
extern string hasLeakedIntelligence;
extern string hasLeakedPolice;
extern string hasLeakedCorporate;
extern string hasLeakedPrison;
extern string hasLeakedCableNews;
extern string hasLeakedAMRadio;
extern string hasLeakedAnimalResearch;
extern string hasLeakedJudiciary;
extern string papersAreStashed;
extern string hasLeakedCCS;
extern string diskIsStashed;
extern string arrestedWhileEmbezzling;
extern string arrestedWhileStealing;
extern string droppedOffPackage;
extern string itemNotFound;
extern string lostStolenItem;
extern string contactModAuthor;
extern string hasRecruited;
extern string looksForwardToServing;
extern string toSpend;
extern string chooseAColor;
extern string theseColorsAreCon;
extern string thisColor;
extern string notEnoughMoney;
extern string chooseVehicle;
extern string thisVehicle;
extern string weDontNeedCar;
extern string enterLeave;
extern string b_chooseBuyer;
extern string s_sellCar;
extern string s_sellThe;
extern string g_getCar;
extern string f_fixWounds;
extern string univer;
extern string numRecruit;
extern string numMartyr;
extern string numKills;
extern string numKidnap;
extern string cashTaxed;
extern string cashSpent;
extern string flagsBought;
extern string flagsBurned;
extern string noValid;
extern string heLiElite;
extern string heLiLiber;
extern string heLiBrought;
extern string heLiBlot;
extern string heLiMob;
extern string heLiDownsized;
extern string heLiKIA;
extern string hecoReag;
extern string heLiDie;
extern string heLiExec;
extern string heLiVaca;
extern string heLiHide;
extern string heLiHunted;
extern string heLiScattered;
extern string heLiOutCrime;
extern string heLiBurned;
extern string hecoStalinized;
extern string dotSpace;
extern string liberalHelpOn;
extern string pressAnyKeyToReturn;
extern string commaSpace;
vector<string*> allTextString = {
	&respondsComma,
	&saysComma,
	&while_naked,
	&colonSpace,
	&pressLToViewHighScores,
	&ampersandC,
	&commaSpace,
	&findingBugs,
	&undefined,
	&NONE,
	&YEA,
	&NAY,
	&AND,
	&counts_of,
	&feels_sick_and,
	&show_squad_liberal_status,
	&change_squad_order,
	&string_sleeper,
	&execution_in_three_months,
	&major_news_take_it_up,
	&they_are_stashed,
	&they_ll_round_you_up,
	&conservativesRemakeWorld,
	&bound_to_rile_up,
	&establishPrisonReform,
	&improvePrisonConditions,
	&stalinistsRemakeWorld,
	&chooseALiberalTo,
	&youWentOnVacation,
	&youWentIntoHiding,
	&whileYouWereInPrison,
	&youDisappearedSafely,
	&proposeConservative,
	&proposeStalinist,

	&enter_done,
	&beingFollowedBySwine,
	&lostThem,
	&hereTheyCome,
	&spaceDashSpace,
	&currentLocation,
	&safeHouse,
	&enemySafeHouse,
	&closedDown,
	&highSecurity,
	&needCar,
	&spaceParanthesisDollar,
	&paranthesisDollar,
	&closeParenthesis,
	&underSiege,
	&percentSign,
	&secrecyLevel,
	&heatLevel,
	&travelDifCity,
	&smellsPanic,
	&moderateLC,
	&buggyString,
	&isSeized,
	&selectA,
	&selectAn,
	&enterDash,
	&accordingToSourcesAtScene,
	&accordingToPoliceSources,
	&ampersandR,
	&singleDot,
	&membersOfLCS,
	&lcsSpokeseperson,
	&policeSpokesperson,
	&pressKeyToReflect,
	&theLCS,
	&notASkill,
	&notAnAttribute,
	&vehicleSportsCar,
	&aNewConEra,
	&theYearIs,
	&conservativePresident,
	&endsSecondTerm,
	&highSeventiesApprovePres,
	&conMajorityHouse,
	&senateConMajority,
	&beginningOfNew,
	&conEra,
	&thePresident,
	&hasAskedCongressBeQuick,
	&rubberStampArchCon,
	&theLeftSeems,
	&powerlessToStop,
	&inThisDarkTime,
	&whatIsYourName,
	&pressEnterToBeRealName,
	&invalidTag,
	&theDocSaid,
	&aBoy,
	&aGirl,
	&intersex,
	&myParents,
	&insistedOtherwise,
	&they,
	&namedMe,
	&error,
	&theFounder,
	&firstName,
	&pressAtoReconsider,
	&lastName,
	&pressBtoBeReborn,
	&sexIs,
	&male,
	&female,
	&itsComplicated,
	&pressCtoChangeSex,
	&history,
	&letMeChoose,
	&letFateDecide,
	&pressDtoToggle,
	&city,
	&pressEtoRelocate,
	&pressAnyKeyString,
	&allOptions,
	&unSelected,
	&isSelected,
	&pressAnyOtherKey,
	&notCreature,
	&notValidMap,
	&notSpecialWound,
	&newGameAdvanced,
	&a_classicMode,
	&b_weDidntStartIt,
	&c_nightmareMode,
	&d_nationalLCS,
	&e_marathonMode,
	&f_stalinistMode,
	&newGameYourAgenda,
	&a_noComprimise,
	&b_democrat,
	&newGameFieldLearn,
	&affectsTheseSkills,
	&a_fastSkills,
	&b_classic,
	&c_hardMode,
	&deleteSave,
	&chooseSave,
	&titleScreenLine,
	&newGame,
	&pressToSelectSave,
	&pressToDeleteSave,
	&vToSwitchXToQuit,
	&areYouSureDelte,
	&questionYSlashN,
	&pressMtoTurnOffMusic,
	&pressMtoTurnOnMusic,
	&inWhatWorld,
	&enterNameForSave,
	&pleaseEnterName,
	&prettyPlease,
	&justEnterName,
	&liberalCrimeSquad,
	&inspiredByOubliette,
	&copyrightTarn,
	&bayTwelveProductions,
	&lcsHyperlink,
	&vChar,
	&maintainedByOpenSource,
	&kingDrakeHyperlink,
	&lcsForumHyperlink,
	&lcsWikiHyperlink,
	&pressESCToQuit,
	&pressAnyKeyToPursue,
	&plusChar,
	&dotDat,
	&itemType,
	&doesNotExistItem,
	&vehicleType,
	&doesNotExistVehicle,
	&couldNotLoad,
	&itemClassClip,
	&itemClassWeapon,
	&itemClassArmor,
	&itemClassLoot,
	&itemClassMoney,
	&failedToLoadSitemaps,
	&debugCode,
	&activated,
	&failedToLoad,
	&exclamationPoint,
	&defaultMissingForMask,
	&defaultUnknownForMask,
	&ableToStopBleed,
	&sWounds,
	&isBurned,
	&drops,
	&sBody,
	&hasBeenCaughtSnooping,
	&isNowHomeless,
	&hasLeakedIntelligence,
	&hasLeakedPolice,
	&hasLeakedCorporate,
	&hasLeakedPrison,
	&hasLeakedCableNews,
	&hasLeakedAMRadio,
	&hasLeakedAnimalResearch,
	&hasLeakedJudiciary,
	&papersAreStashed,
	&hasLeakedCCS,
	&diskIsStashed,
	&arrestedWhileEmbezzling,
	&arrestedWhileStealing,
	&droppedOffPackage,
	&itemNotFound,
	&lostStolenItem,
	&contactModAuthor,
	&hasRecruited,
	&looksForwardToServing,
	&toSpend,
	&chooseAColor,
	&theseColorsAreCon,
	&thisColor,
	&notEnoughMoney,
	&chooseVehicle,
	&thisVehicle,
	&weDontNeedCar,
	&enterLeave,
	&b_chooseBuyer,
	&s_sellCar,
	&s_sellThe,
	&g_getCar,
	&f_fixWounds,
	&univer,
	&numRecruit,
	&numMartyr,
	&numKills,
	&numKidnap,
	&cashTaxed,
	&cashSpent,
	&flagsBought,
	&flagsBurned,
	&noValid,
	&heLiElite,
	&heLiLiber,
	&heLiBrought,
	&heLiBlot,
	&heLiMob,
	&heLiDownsized,
	&heLiKIA,
	&hecoReag,
	&heLiDie,
	&heLiExec,
	&heLiVaca,
	&heLiHide,
	&heLiHunted,
	&heLiScattered,
	&heLiOutCrime,
	&heLiBurned,
	&hecoStalinized,
	&dotSpace,
	&unnamed_String_Talk_cpp_001,
	&unnamed_String_Talk_cpp_002,
	&unnamed_String_Talk_cpp_003,
	&unnamed_String_Talk_cpp_004,
	&unnamed_String_Talk_cpp_005,
	&unnamed_String_Talk_cpp_006,
	&unnamed_String_Talk_cpp_007,
	&unnamed_String_Talk_cpp_008,
	&unnamed_String_Talk_cpp_009,
	&unnamed_String_Talk_cpp_010,
	&unnamed_String_Talk_cpp_011,
	&unnamed_String_Talk_cpp_012,
	&unnamed_String_Talk_cpp_013,
	&unnamed_String_Talk_cpp_014,
	&unnamed_String_Talk_cpp_015,
	&unnamed_String_Talk_cpp_016,
	&unnamed_String_Talk_cpp_017,
	&unnamed_String_Talk_cpp_018,
	&unnamed_String_Talk_cpp_019,
	&unnamed_String_Talk_cpp_020,
	&unnamed_String_Talk_cpp_021,
	&unnamed_String_Talk_cpp_022,
	&unnamed_String_Talk_cpp_023,
	&unnamed_String_Talk_cpp_024,
	&unnamed_String_Talk_cpp_025,
	&unnamed_String_Talk_cpp_026,
	&unnamed_String_Talk_cpp_027,
	&unnamed_String_Talk_cpp_028,
	&unnamed_String_Talk_cpp_029,
	&unnamed_String_Talk_cpp_030,
	&unnamed_String_Talk_cpp_031,
	&unnamed_String_Talk_cpp_032,
	&unnamed_String_Talk_cpp_033,
	&unnamed_String_Talk_cpp_034,
	&unnamed_String_Talk_cpp_035,
	&unnamed_String_Talk_cpp_036,
	&unnamed_String_Talk_cpp_037,
	&unnamed_String_Talk_cpp_038,
	&unnamed_String_Talk_cpp_039,
	&unnamed_String_Talk_cpp_040,
	&unnamed_String_Talk_cpp_041,
	&unnamed_String_Talk_cpp_042,
	&unnamed_String_Talk_cpp_043,
	&unnamed_String_Talk_cpp_044,
	&unnamed_String_Talk_cpp_045,
	&unnamed_String_Talk_cpp_046,
	&unnamed_String_Talk_cpp_047,
	&unnamed_String_Talk_cpp_048,
	&unnamed_String_Talk_cpp_049,
	&unnamed_String_Talk_cpp_050,
	&unnamed_String_Talk_cpp_051,
	&unnamed_String_Talk_cpp_052,
	&unnamed_String_Talk_cpp_053,
	&unnamed_String_Talk_cpp_054,
	&unnamed_String_Talk_cpp_055,
	&unnamed_String_Talk_cpp_056,
	&unnamed_String_Talk_cpp_057,
	&unnamed_String_Talk_cpp_058,
	&unnamed_String_Talk_cpp_059,
	&unnamed_String_Talk_cpp_060,
	&unnamed_String_Talk_cpp_061,
	&unnamed_String_Talk_cpp_062,
	&unnamed_String_Talk_cpp_063,
	&unnamed_String_Talk_cpp_064,
	&unnamed_String_Talk_cpp_065,
	&unnamed_String_Talk_cpp_066,
	&unnamed_String_Talk_cpp_067,
	&unnamed_String_Talk_cpp_068,
	&unnamed_String_Talk_cpp_069,
	&unnamed_String_Talk_cpp_070,
	&unnamed_String_Talk_cpp_071,
	&unnamed_String_Talk_cpp_072,
	&unnamed_String_Talk_cpp_073,
	&unnamed_String_Talk_cpp_074,
	&unnamed_String_Talk_cpp_075,
	&unnamed_String_Talk_cpp_076,
	&unnamed_String_Talk_cpp_077,
	&unnamed_String_Talk_cpp_078,
	&unnamed_String_Talk_cpp_079,
	&unnamed_String_Talk_cpp_080,
	&unnamed_String_Talk_cpp_081,
	&unnamed_String_Talk_cpp_082,
	&unnamed_String_Talk_cpp_083,
	&unnamed_String_Talk_cpp_084,
	&unnamed_String_Talk_cpp_085,
	&unnamed_String_Talk_cpp_086,
	&unnamed_String_Talk_cpp_087,
	&unnamed_String_Talk_cpp_088,
	&unnamed_String_Talk_cpp_089,
	&unnamed_String_Talk_cpp_090,
	&unnamed_String_Talk_cpp_091,
	&unnamed_String_Talk_cpp_092,
	&unnamed_String_Talk_cpp_093,
	&unnamed_String_Talk_cpp_094,
	&unnamed_String_Talk_cpp_095,
	&unnamed_String_Talk_cpp_096,
	&unnamed_String_Talk_cpp_097,
	&unnamed_String_Talk_cpp_098,
	&unnamed_String_Talk_cpp_099,
	&unnamed_String_Talk_cpp_100,
	&unnamed_String_Talk_cpp_101,
	&unnamed_String_Talk_cpp_102,
	&unnamed_String_Talk_cpp_103,
	&unnamed_String_Talk_cpp_104,
	&unnamed_String_Talk_cpp_105,
	&unnamed_String_Talk_cpp_106,
	&unnamed_String_Talk_cpp_107,
	&unnamed_String_Talk_cpp_108,
	&unnamed_String_Talk_cpp_109,
	&unnamed_String_Talk_cpp_110,
	&unnamed_String_Talk_cpp_111,
	&unnamed_String_Talk_cpp_112,
	&unnamed_String_Talk_cpp_113,
	&unnamed_String_Talk_cpp_114,
	&unnamed_String_Talk_cpp_115,
	&unnamed_String_Talk_cpp_116,
	&unnamed_String_Talk_cpp_117,
	&unnamed_String_Talk_cpp_118,
	&unnamed_String_Talk_cpp_119,
	&unnamed_String_Talk_cpp_120,
	&unnamed_String_Talk_cpp_121,
	&unnamed_String_Talk_cpp_122,
	&unnamed_String_Talk_cpp_123,
	&unnamed_String_Talk_cpp_124,
	&unnamed_String_Talk_cpp_125,
	&unnamed_String_Talk_cpp_126,
	&unnamed_String_Talk_cpp_127,
	&unnamed_String_Talk_cpp_128,
	&unnamed_String_Talk_cpp_129,
	&unnamed_String_Talk_cpp_130,
	&unnamed_String_Talk_cpp_131,
	&unnamed_String_Talk_cpp_132,
	&unnamed_String_Talk_cpp_133,
	&unnamed_String_Talk_cpp_134,
	&unnamed_String_Talk_cpp_135,
	&unnamed_String_Talk_cpp_136,
	&unnamed_String_Talk_cpp_137,
	&unnamed_String_Talk_cpp_138,
	&unnamed_String_Talk_cpp_139,
	&unnamed_String_Talk_cpp_140,
	&unnamed_String_Talk_cpp_141,
	&unnamed_String_Talk_cpp_142,
	&unnamed_String_Talk_cpp_143,
	&unnamed_String_Talk_cpp_144,
	&unnamed_String_Talk_cpp_145,
	&unnamed_String_Talk_cpp_146,
	&unnamed_String_Talk_cpp_147,
	&unnamed_String_Talk_cpp_148,
	&unnamed_String_Talk_cpp_149,
	&liberalHelpOn,
	&pressAnyKeyToReturn,
	&study_string1,
	&study_string2,
};
bool initialize_incomplete_txt() {
	int i = 0;
	check_status_of_squad_liberal.append(CONST_talk040);
	check_status_of_squad_liberal.append(allText[i++]);
	for (string* str : allTextString) {
		*str = allText[i++];
	}
	return i == len(allText);
}

map<int, vector<SiteTypes> > okaySiteList = {
	map<int, vector<SiteTypes> >::value_type(CREATURE_BOUNCER,
		{
			SITE_BUSINESS_CIGARBAR,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_POLITICIAN,
		{
			SITE_GOVERNMENT_WHITE_HOUSE,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_CORPORATE_CEO,
		{
			SITE_CORPORATE_HEADQUARTERS,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_SECURITYGUARD,
		{
			SITE_RESIDENTIAL_APARTMENT_UPSCALE,
			SITE_LABORATORY_COSMETICS,
			SITE_LABORATORY_GENETIC,
			SITE_GOVERNMENT_COURTHOUSE,
			SITE_GOVERNMENT_INTELLIGENCEHQ,
			SITE_INDUSTRY_SWEATSHOP,
			SITE_INDUSTRY_POLLUTER,
			SITE_INDUSTRY_NUCLEAR,
			SITE_CORPORATE_HEADQUARTERS,
			SITE_CORPORATE_HOUSE,
			SITE_MEDIA_AMRADIO,
			SITE_MEDIA_CABLENEWS,
			SITE_BUSINESS_CIGARBAR,
			SITE_BUSINESS_BANK,
			//SITE_GOVERNMENT_FIRESTATION,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_BANK_MANAGER,
		{
			SITE_BUSINESS_BANK,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_BANK_TELLER,
		{
			SITE_BUSINESS_BANK,

		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_SCIENTIST_LABTECH,
		{
			SITE_LABORATORY_COSMETICS,
			SITE_LABORATORY_GENETIC,
			SITE_INDUSTRY_NUCLEAR,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_SCIENTIST_EMINENT,
		{
			SITE_LABORATORY_COSMETICS,
			SITE_LABORATORY_GENETIC,
			SITE_INDUSTRY_NUCLEAR,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_CORPORATE_MANAGER,
		{
			SITE_LABORATORY_COSMETICS,
			SITE_LABORATORY_GENETIC,
			SITE_INDUSTRY_SWEATSHOP,
			SITE_INDUSTRY_POLLUTER,
			SITE_INDUSTRY_NUCLEAR,
			SITE_CORPORATE_HEADQUARTERS,
			SITE_MEDIA_AMRADIO,
			SITE_MEDIA_CABLENEWS,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_WORKER_SERVANT,
		{
			SITE_CORPORATE_HOUSE,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_WORKER_JANITOR,
		{
			SITE_RESIDENTIAL_TENEMENT,
			SITE_RESIDENTIAL_APARTMENT,
			SITE_RESIDENTIAL_APARTMENT_UPSCALE,
			SITE_LABORATORY_COSMETICS,
			SITE_LABORATORY_GENETIC,
			SITE_HOSPITAL_CLINIC,
			SITE_HOSPITAL_UNIVERSITY,
			SITE_GOVERNMENT_POLICESTATION,
			SITE_GOVERNMENT_COURTHOUSE,
			SITE_GOVERNMENT_PRISON,
			SITE_GOVERNMENT_INTELLIGENCEHQ,
			SITE_INDUSTRY_POLLUTER,
			SITE_INDUSTRY_NUCLEAR,
			SITE_CORPORATE_HEADQUARTERS,
			SITE_MEDIA_AMRADIO,
			SITE_MEDIA_CABLENEWS,
			SITE_BUSINESS_PAWNSHOP,
			SITE_BUSINESS_CRACKHOUSE,
			SITE_BUSINESS_JUICEBAR,
			SITE_BUSINESS_CIGARBAR,
			SITE_BUSINESS_LATTESTAND,
			SITE_BUSINESS_VEGANCOOP,
			SITE_BUSINESS_INTERNETCAFE,
			SITE_BUSINESS_DEPTSTORE,
			SITE_BUSINESS_HALLOWEEN,
			SITE_GOVERNMENT_FIRESTATION,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_WORKER_SWEATSHOP,
		{
			SITE_INDUSTRY_SWEATSHOP,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_WORKER_FACTORY_NONUNION,
		{
			SITE_INDUSTRY_POLLUTER,
		}
		),
			map<int, vector<SiteTypes> >::value_type(CREATURE_WORKER_FACTORY_CHILD,
				{
					SITE_INDUSTRY_POLLUTER,
				}
				),
			map<int, vector<SiteTypes> >::value_type(CREATURE_WORKER_SECRETARY,
				{
					SITE_LABORATORY_COSMETICS,
					SITE_LABORATORY_GENETIC,
					SITE_HOSPITAL_CLINIC,
					SITE_HOSPITAL_UNIVERSITY,
					SITE_GOVERNMENT_POLICESTATION,
					SITE_GOVERNMENT_COURTHOUSE,
					SITE_GOVERNMENT_INTELLIGENCEHQ,
					SITE_INDUSTRY_POLLUTER,
					SITE_INDUSTRY_NUCLEAR,
					SITE_CORPORATE_HEADQUARTERS,
					SITE_CORPORATE_HOUSE,
					SITE_MEDIA_AMRADIO,
					SITE_MEDIA_CABLENEWS,
					SITE_GOVERNMENT_FIRESTATION,
					SITE_GOVERNMENT_WHITE_HOUSE,
				}
				),
			map<int, vector<SiteTypes> >::value_type(CREATURE_WORKER_FACTORY_UNION,
				{
					SITE_INDUSTRY_POLLUTER,
				}
				),
		map<int, vector<SiteTypes> >::value_type(CREATURE_LANDLORD,
			{
				SITE_RESIDENTIAL_TENEMENT,
				SITE_RESIDENTIAL_APARTMENT,
				SITE_RESIDENTIAL_APARTMENT_UPSCALE,
			}
			),
		map<int, vector<SiteTypes> >::value_type(CREATURE_TEENAGER,
			{
				SITE_RESIDENTIAL_TENEMENT,
				SITE_RESIDENTIAL_APARTMENT,
				SITE_RESIDENTIAL_APARTMENT_UPSCALE,
				SITE_RESIDENTIAL_SHELTER,
				SITE_CORPORATE_HOUSE,
			}
			),
			map<int, vector<SiteTypes> >::value_type(CREATURE_COP,
				{
					SITE_GOVERNMENT_POLICESTATION,
				}
				),
			map<int, vector<SiteTypes> >::value_type(CREATURE_DEATHSQUAD,
				{
					SITE_GOVERNMENT_POLICESTATION,
				}
				),
		map<int, vector<SiteTypes> >::value_type(CREATURE_FIREFIGHTER,
			{
				SITE_GOVERNMENT_FIRESTATION,
			}
			),
		map<int, vector<SiteTypes> >::value_type(CREATURE_GANGUNIT,
			{
				SITE_GOVERNMENT_POLICESTATION,
			}
			),
			map<int, vector<SiteTypes> >::value_type(CREATURE_SWAT,
				{
					SITE_GOVERNMENT_POLICESTATION,
				}
				),
			map<int, vector<SiteTypes> >::value_type(CREATURE_JUDGE_LIBERAL,
				{
					SITE_GOVERNMENT_COURTHOUSE,
				}
				),
			map<int, vector<SiteTypes> >::value_type(CREATURE_JUDGE_CONSERVATIVE,
				{
					SITE_GOVERNMENT_COURTHOUSE,
				}
				),
			map<int, vector<SiteTypes> >::value_type(CREATURE_SECRET_SERVICE,
				{
					SITE_GOVERNMENT_WHITE_HOUSE,
				}
				),
			map<int, vector<SiteTypes> >::value_type(CREATURE_AGENT,
				{
					SITE_GOVERNMENT_INTELLIGENCEHQ,
				}
				),
		map<int, vector<SiteTypes> >::value_type(CREATURE_RADIOPERSONALITY,
			{
				SITE_MEDIA_AMRADIO,
			}
			),
		map<int, vector<SiteTypes> >::value_type(CREATURE_NEWSANCHOR,
			{
				SITE_MEDIA_CABLENEWS,
			}
			),
				map<int, vector<SiteTypes> >::value_type(CREATURE_GENETIC,
					{
						SITE_LABORATORY_GENETIC,
					}
					),
				map<int, vector<SiteTypes> >::value_type(CREATURE_GUARDDOG,
					{
						SITE_GOVERNMENT_PRISON,
						SITE_GOVERNMENT_INTELLIGENCEHQ,
						SITE_CORPORATE_HOUSE,
						SITE_GOVERNMENT_ARMYBASE,
					}
					),
					map<int, vector<SiteTypes> >::value_type(CREATURE_PRISONER,
						{
							SITE_RESIDENTIAL_TENEMENT,
							SITE_RESIDENTIAL_SHELTER,
						}
						),
					map<int, vector<SiteTypes> >::value_type(CREATURE_JUROR,
						{
							SITE_RESIDENTIAL_APARTMENT,
							SITE_RESIDENTIAL_TENEMENT,
							SITE_RESIDENTIAL_SHELTER,
						}
						),
					map<int, vector<SiteTypes> >::value_type(CREATURE_LAWYER,
						{
							SITE_GOVERNMENT_COURTHOUSE,
							SITE_GOVERNMENT_WHITE_HOUSE,
						}
						),
				map<int, vector<SiteTypes> >::value_type(CREATURE_DOCTOR,
					{
						SITE_DOWNTOWN,
						SITE_UDISTRICT,
					}
					),
				map<int, vector<SiteTypes> >::value_type(CREATURE_PSYCHOLOGIST,
					{
						SITE_DOWNTOWN,
						SITE_UDISTRICT,
					}
					),
				map<int, vector<SiteTypes> >::value_type(CREATURE_NURSE,
					{
						SITE_DOWNTOWN,
						SITE_UDISTRICT,
						SITE_INDUSTRIAL,
					}
					),
					map<int, vector<SiteTypes> >::value_type(CREATURE_SEWERWORKER,
						{
							SITE_DOWNTOWN,
							SITE_UDISTRICT,
							SITE_INDUSTRIAL,
						}
						),
				map<int, vector<SiteTypes> >::value_type(CREATURE_COLLEGESTUDENT,
					{
						SITE_UDISTRICT,
					}
					),
				map<int, vector<SiteTypes> >::value_type(CREATURE_MUSICIAN,
					{
						SITE_DOWNTOWN,
						SITE_UDISTRICT,
						SITE_INDUSTRIAL,
					}
					),
				map<int, vector<SiteTypes> >::value_type(CREATURE_MATHEMATICIAN,
					{
						SITE_UDISTRICT,
					}
					),
				map<int, vector<SiteTypes> >::value_type(CREATURE_TEACHER,
					{
						SITE_DOWNTOWN,
						SITE_UDISTRICT,
						SITE_INDUSTRIAL,
					}
					),
					map<int, vector<SiteTypes> >::value_type(CREATURE_HSDROPOUT,
						{
							SITE_INDUSTRIAL,
						}
						),
					map<int, vector<SiteTypes> >::value_type(CREATURE_BUM,
						{
							SITE_DOWNTOWN,	
							SITE_UDISTRICT,

							SITE_INDUSTRIAL,
							SITE_RESIDENTIAL_SHELTER,
						}
						),

				map<int, vector<SiteTypes> >::value_type(CREATURE_GANGMEMBER,
					{
						SITE_BUSINESS_CRACKHOUSE,
					}
					),
						map<int, vector<SiteTypes> >::value_type(CREATURE_CRACKHEAD,
							{
								SITE_BUSINESS_CRACKHOUSE,
							}
							),
						map<int, vector<SiteTypes> >::value_type(CREATURE_PRIEST,
							{
								SITE_DOWNTOWN,
								SITE_UDISTRICT,
								SITE_INDUSTRIAL,
							}
							),
							map<int, vector<SiteTypes> >::value_type(CREATURE_ENGINEER,
								{
									SITE_MEDIA_AMRADIO,
									SITE_MEDIA_CABLENEWS,
									SITE_INDUSTRY_NUCLEAR,
								}
								),
							map<int, vector<SiteTypes> >::value_type(CREATURE_FASTFOODWORKER,
								{
									SITE_DOWNTOWN,
									SITE_UDISTRICT,
									SITE_INDUSTRIAL,
								}
								),
							map<int, vector<SiteTypes> >::value_type(CREATURE_BAKER,
								{
									SITE_DOWNTOWN,
									SITE_UDISTRICT,
									SITE_INDUSTRIAL,
								}
								),
						map<int, vector<SiteTypes> >::value_type(CREATURE_BARISTA,
							{
								SITE_BUSINESS_LATTESTAND,
								SITE_BUSINESS_INTERNETCAFE,
							}
							),
						map<int, vector<SiteTypes> >::value_type(CREATURE_BARTENDER,
							{
								SITE_BUSINESS_CIGARBAR,
								SITE_DOWNTOWN,
								SITE_UDISTRICT,
								SITE_INDUSTRIAL,
							}
							),
						map<int, vector<SiteTypes> >::value_type(CREATURE_TELEMARKETER,
							{
								SITE_DOWNTOWN,
								SITE_UDISTRICT,
								SITE_INDUSTRIAL,
							}
							),
							map<int, vector<SiteTypes> >::value_type(CREATURE_CARSALESMAN,
								{
									SITE_BUSINESS_CARDEALERSHIP,
								}
								),
						map<int, vector<SiteTypes> >::value_type(CREATURE_OFFICEWORKER,
							{
								SITE_LABORATORY_COSMETICS,
								SITE_LABORATORY_GENETIC,
								SITE_HOSPITAL_CLINIC,
								SITE_HOSPITAL_UNIVERSITY,
								SITE_GOVERNMENT_COURTHOUSE,
								SITE_CORPORATE_HEADQUARTERS,
								SITE_MEDIA_AMRADIO,
								SITE_MEDIA_CABLENEWS,
								SITE_BUSINESS_DEPTSTORE,
								SITE_GOVERNMENT_WHITE_HOUSE,
							}
							),
					map<int, vector<SiteTypes> >::value_type(CREATURE_FOOTBALLCOACH,
						{
							SITE_UDISTRICT,
						}
						),
						map<int, vector<SiteTypes> >::value_type(CREATURE_PROSTITUTE,
							{
								SITE_DOWNTOWN,
								SITE_UDISTRICT,
								SITE_INDUSTRIAL,
							}
							),
						map<int, vector<SiteTypes> >::value_type(CREATURE_MAILMAN,
							{
								SITE_DOWNTOWN,
								SITE_UDISTRICT,
								SITE_INDUSTRIAL,
							}
							),
							map<int, vector<SiteTypes> >::value_type(CREATURE_GARBAGEMAN,
								{
									SITE_DOWNTOWN,
									SITE_UDISTRICT,
									SITE_INDUSTRIAL,
								}
								),
						map<int, vector<SiteTypes> >::value_type(CREATURE_PLUMBER,
							{
								SITE_DOWNTOWN,
								SITE_UDISTRICT,
								SITE_INDUSTRIAL,
							}
							),
								map<int, vector<SiteTypes> >::value_type(CREATURE_CHEF,
									{
										SITE_DOWNTOWN,
										SITE_UDISTRICT,
										SITE_INDUSTRIAL,
										SITE_BUSINESS_CIGARBAR,
									}
									),
									map<int, vector<SiteTypes> >::value_type(CREATURE_CONSTRUCTIONWORKER,
										{
											SITE_DOWNTOWN,
											SITE_UDISTRICT,
											SITE_INDUSTRIAL,
										}
										),
									map<int, vector<SiteTypes> >::value_type(CREATURE_AMATEURMAGICIAN,
										{
											SITE_DOWNTOWN,
											SITE_UDISTRICT,
											SITE_INDUSTRIAL,
										}
										),
									map<int, vector<SiteTypes> >::value_type(CREATURE_TANK,
										{
											SITE_GOVERNMENT_ARMYBASE,
										}
										),
							map<int, vector<SiteTypes> >::value_type(CREATURE_MERC,
								{
									SITE_CORPORATE_HEADQUARTERS,
									SITE_CORPORATE_HOUSE,
									SITE_INDUSTRY_NUCLEAR,
									SITE_LABORATORY_GENETIC,
									SITE_BUSINESS_BANK,
								}
								),
								map<int, vector<SiteTypes> >::value_type(CREATURE_HICK,
									{
										SITE_MEDIA_AMRADIO,
										SITE_MEDIA_CABLENEWS,
										SITE_OUTOFTOWN,
									}
									),
								map<int, vector<SiteTypes> >::value_type(CREATURE_VETERAN,
									{
										SITE_DOWNTOWN,
										SITE_UDISTRICT,
										SITE_INDUSTRIAL,
									}
									),
									map<int, vector<SiteTypes> >::value_type(CREATURE_HARDENED_VETERAN,
										{
											SITE_GOVERNMENT_ARMYBASE,
										}
										),
								map<int, vector<SiteTypes> >::value_type(CREATURE_SOLDIER,
									{
										SITE_GOVERNMENT_ARMYBASE,
									}
									),
								map<int, vector<SiteTypes> >::value_type(CREATURE_MILITARYPOLICE,
									{
										SITE_GOVERNMENT_ARMYBASE,
									}
									),
								map<int, vector<SiteTypes> >::value_type(CREATURE_MILITARYOFFICER,
									{
										SITE_GOVERNMENT_ARMYBASE,
									}
									),
							map<int, vector<SiteTypes> >::value_type(CREATURE_SEAL,
								{
									SITE_GOVERNMENT_ARMYBASE,
								}
								),
								map<int, vector<SiteTypes> >::value_type(CREATURE_EDUCATOR,
									{
										SITE_GOVERNMENT_PRISON,
									}
									),
								map<int, vector<SiteTypes> >::value_type(CREATURE_PRISONGUARD,
									{
										SITE_GOVERNMENT_PRISON,
									}
									),
								map<int, vector<SiteTypes> >::value_type(CREATURE_HIPPIE,
									{
										SITE_BUSINESS_VEGANCOOP,
									}
									),
									map<int, vector<SiteTypes> >::value_type(CREATURE_CRITIC_ART,
										{
											SITE_DOWNTOWN,
											SITE_UDISTRICT,
											SITE_INDUSTRIAL,
											SITE_MEDIA_CABLENEWS,
										}
										),
								map<int, vector<SiteTypes> >::value_type(CREATURE_CRITIC_MUSIC,

									{
										SITE_DOWNTOWN,
										SITE_UDISTRICT,
										SITE_INDUSTRIAL,
										SITE_MEDIA_AMRADIO,
									}
									),
										map<int, vector<SiteTypes> >::value_type(CREATURE_SOCIALITE,
											{
												SITE_DOWNTOWN,
												SITE_UDISTRICT,
												SITE_INDUSTRIAL,
											}
											),
											map<int, vector<SiteTypes> >::value_type(CREATURE_PROGRAMMER,
												{
													SITE_DOWNTOWN,
													SITE_UDISTRICT,
													SITE_INDUSTRIAL,
													SITE_GOVERNMENT_INTELLIGENCEHQ,
													SITE_CORPORATE_HEADQUARTERS,
												}
												),
											map<int, vector<SiteTypes> >::value_type(CREATURE_RETIREE,
												{
													SITE_DOWNTOWN,
													SITE_UDISTRICT,
													SITE_INDUSTRIAL,
												}
												),
									map<int, vector<SiteTypes> >::value_type(CREATURE_PAINTER,
										{
											SITE_DOWNTOWN,
											SITE_UDISTRICT,
											SITE_INDUSTRIAL,
										}
										),
										map<int, vector<SiteTypes> >::value_type(CREATURE_SCULPTOR,
											{
												SITE_DOWNTOWN,
												SITE_UDISTRICT,
												SITE_INDUSTRIAL,
											}
											),
										map<int, vector<SiteTypes> >::value_type(CREATURE_AUTHOR,
											{
												SITE_DOWNTOWN,
												SITE_UDISTRICT,
												SITE_INDUSTRIAL,
											}
											),
											map<int, vector<SiteTypes> >::value_type(CREATURE_JOURNALIST,
												{
													SITE_DOWNTOWN,
													SITE_UDISTRICT,
													SITE_INDUSTRIAL,
												}
												),
										map<int, vector<SiteTypes> >::value_type(CREATURE_DANCER,
											{
												SITE_DOWNTOWN,
												SITE_UDISTRICT,
												SITE_INDUSTRIAL,
											}
											),
									map<int, vector<SiteTypes> >::value_type(CREATURE_PHOTOGRAPHER,
										{
											SITE_MEDIA_CABLENEWS,
										}
										),
								map<int, vector<SiteTypes> >::value_type(CREATURE_CAMERAMAN,
									{
										SITE_MEDIA_CABLENEWS,
									}
									),
									map<int, vector<SiteTypes> >::value_type(CREATURE_HAIRSTYLIST,
										{
											SITE_DOWNTOWN,
											SITE_UDISTRICT,
											SITE_INDUSTRIAL,
										}
										),
										map<int, vector<SiteTypes> >::value_type(CREATURE_FASHIONDESIGNER,
											{
												SITE_DOWNTOWN,
												SITE_UDISTRICT,
												SITE_INDUSTRIAL,
											}
											),
										map<int, vector<SiteTypes> >::value_type(CREATURE_CLERK,
											{
												SITE_BUSINESS_JUICEBAR,
												SITE_BUSINESS_LATTESTAND,
												SITE_BUSINESS_INTERNETCAFE,
												SITE_BUSINESS_DEPTSTORE,
												SITE_BUSINESS_HALLOWEEN,
											}
											),
									map<int, vector<SiteTypes> >::value_type(CREATURE_THIEF,
										{
											SITE_DOWNTOWN,
											SITE_UDISTRICT,
											SITE_INDUSTRIAL,
										}
										),
										map<int, vector<SiteTypes> >::value_type(CREATURE_ACTOR,
											{
												SITE_DOWNTOWN,
												SITE_UDISTRICT,
												SITE_INDUSTRIAL,
											}
											),
												map<int, vector<SiteTypes> >::value_type(CREATURE_YOGAINSTRUCTOR,
													{
														SITE_BUSINESS_VEGANCOOP,
													}
													),
													map<int, vector<SiteTypes> >::value_type(CREATURE_MARTIALARTIST,
														{
															SITE_DOWNTOWN,
															SITE_UDISTRICT,
															SITE_INDUSTRIAL,
														}
														),
													map<int, vector<SiteTypes> >::value_type(CREATURE_ATHLETE,
														{
															SITE_UDISTRICT,
														}
														),
													map<int, vector<SiteTypes> >::value_type(CREATURE_BIKER,
														{
															SITE_DOWNTOWN,
															SITE_UDISTRICT,
															SITE_INDUSTRIAL,
														}
														),
											map<int, vector<SiteTypes> >::value_type(CREATURE_TRUCKER,
												{
													SITE_OUTOFTOWN,
												}
												),
												map<int, vector<SiteTypes> >::value_type(CREATURE_TAXIDRIVER,
													{
														SITE_DOWNTOWN,
														SITE_UDISTRICT,
														SITE_INDUSTRIAL,
													}
													),
												map<int, vector<SiteTypes> >::value_type(CREATURE_NUN,
													{
														SITE_DOWNTOWN,
														SITE_UDISTRICT,
														SITE_INDUSTRIAL,
													}
													),
													map<int, vector<SiteTypes> >::value_type(CREATURE_LOCKSMITH,
														{
															SITE_DOWNTOWN,
															SITE_UDISTRICT,
															SITE_INDUSTRIAL,
														}
														),
};

vector<SiteTypes> defaultSiteList = {
	SITE_RESIDENTIAL_SHELTER
};
/* ensures that the creature's work location is appropriate to its type */
int verifyworklocation(const int type, const int worklocation)
{
	extern bool multipleCityMode;
	extern char ccs_kills;
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

