
#include "../includes.h"

const string blankString = "";
const string CONST_activate066 = "Activate Uninvolved Liberals";
const string CONST_activate067 = "ÄÄÄÄCODE NAMEÄÄÄÄÄÄÄÄÄÄÄÄSKILLÄÄÄHEALTHÄÄÄLOCATIONÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ";
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
// select CONST_activate001, choose CONST_activateB066,
// then choose CONST_activate002.
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
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
string singleDot = ".";
#include "../creature/creature.h"
#include "../locations/locations.h"
#include "../items/armortype.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../creature/augmenttype.h"
#include "../common/translateid.h"
// for  int getsquad(int)
//#include "../common/commonactions.h"
void sorting_prompt(short listforsorting);
#include "../common/commonactionsCreature.h"
// for void sortliberals(std::vector<Creature *>&,short,bool)
#include "../common/commondisplay.h"
#include "../common/commondisplayCreature.h"
// for void printfunds(int,int,char*)
//#include "../common/getnames.h"
string gettitle(DeprecatedCreature &cr);
string getactivity(ActivityST &act);
//#include "../common/help.h"
void HelpActivities(int);
//#include "../common/stringconversion.h"
string attribute_enum_to_string(int);
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
siegest* getseigestFromLocation(int secondaryLocation);
void gotoEquipmentScreen(int loc);
void createTempSquadWithJustThisLiberal(DeprecatedCreature *cr, int cursquadid);
#include "../common/creaturePoolCreature.h"
#include "../common/musicClass.h"
vector<ActivityAndString> data_lessons;
map<Activity, Data_Activity> data_activities;
map<char, vector<ActivityAndString> > activate_menu_items;

vector<CreatureTypes> ACTIVITY_TEACH_FIGHTING_DEFAULT;
// this first block are creatures with All Weapon Skills, Martial Arts, Dodge, and First Aid
vector<CreatureTypes> ACTIVITY_TEACH_COVERT_DEFAULT;
// this second block are creatures with Computers, Security, Stealth, Disguise, Tailoring, Seduction, Psychology, & Driving
vector<CreatureTypes> ACTIVITY_TEACH_POLITICS_DEFAULT;
// this third block are creatures with Writing, Persuasion, Law, Street Sense, Science, Religion, Business, Music, & Art
Activity getDefaultActivityTeaching(DeprecatedCreature *cr) {
	for (CreatureTypes type : ACTIVITY_TEACH_FIGHTING_DEFAULT) {
		if (cr->type == type) {
			return ACTIVITY_TEACH_FIGHTING;
		}
	}
	for (CreatureTypes type : ACTIVITY_TEACH_COVERT_DEFAULT) {
		if (cr->type == type) {
			return ACTIVITY_TEACH_COVERT;
		}
	}
	for (CreatureTypes type : ACTIVITY_TEACH_POLITICS_DEFAULT) {
		if (cr->type == type) {
			return ACTIVITY_TEACH_POLITICS;
		}
	}
	return ACTIVITY_TEACH_POLITICS;

}
extern string closeParenthesis;
string spaceDashSpace;
const string singleSpace = " ";
string commaSpace;
// These two functions handle listing and updating class choices
int classlist = 0;
void listclasses(DeprecatedCreature *cr)
{
	const string CONST_activate007 = "Other classes";
	const string CONST_activate006 = "Classes cost $60 a day. Study what?";
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(10, 40, CONST_activate006);
	for (int i = 0; i < 5; ++i)
	{
		if (i + classlist < len(data_lessons))
		{
			set_color_easy(cr->activity.type == data_lessons[i + classlist].activity ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
			mvaddstrAlt(12 + i, 40, to_string(i + 1) + spaceDashSpace + data_lessons[i + classlist].str);
		}
	}
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(17, 40, to_string(6) + spaceDashSpace + CONST_activate007);
}
void updateclasschoice(DeprecatedCreature *cr, char choice)
{
	if (choice >= '1' && choice <= '5')
	{
		if (choice - '1' + classlist < len(data_lessons))
			cr->activity.type = data_lessons[choice - '1' + classlist].activity;
		listclasses(cr);
	}
	else if (choice == '6')
	{
		classlist += 5;
		if (classlist >= len(data_lessons))
			classlist = 0;
		listclasses(cr);
	}
}
char incrementChar(char c, int i) {
	return c + i;
}
void recruitSelect(DeprecatedCreature &cr)
{
	extern vector<RecruitData> recruitable_creatures;
	const string CONST_activate011 = "Press a Letter to select a Profession";
	const string CONST_activate010 = "ÄÄÄÄTYPEÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄDIFFICULTY TO ARRANGE MEETINGÄÄ";
	const string CONST_activate009 = " try to meet and recruit today?";
	const string CONST_activate008 = "What type of person will ";
	extern short interface_pgup;
	extern short interface_pgdn;
	extern short lawList[LAWNUM];
	// Number of recruitable creatures
	int options = len(recruitable_creatures);
	for (int i = 0; i < options; i++)
	{
		// Dynamic difficulty for certain creatures, recalculated each time the function is called
		if (recruitable_creatures[i].type == CREATURE_MUTANT)
		{
			if (lawList[LAW_NUCLEARPOWER] == -2 && lawList[LAW_POLLUTION] == -2)
				recruitable_creatures[i].difficulty = 2;
			else if (lawList[LAW_NUCLEARPOWER] == -2 || lawList[LAW_POLLUTION] == -2)
				recruitable_creatures[i].difficulty = 6;
			else
				recruitable_creatures[i].difficulty = 9;
		}
	}
	int page = 0;
	while (true)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0, 0, CONST_activate008);
		addstrAlt(cr.name);
		addstrAlt(CONST_activate009);
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(1, 0, CONST_activate010);
		for (int p = page * 19, y = 2; p < options&&p < page * 19 + 19; p++, y++)
		{
			set_color_easy(WHITE_ON_BLACK);
			moveAlt(y, 0);
			addcharAlt(y + 'A' - 2); addstrAlt(spaceDashSpace);
			addstrAlt(recruitable_creatures[p].name);
			moveAlt(y, 49);
			displayDifficulty(recruitable_creatures[p].difficulty);
		}
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(22, 0, CONST_activate011);
		mvaddstrAlt(23, 0, addpagestr());
		int c = getkeyAlt();
		//PAGE UP
		if ((c == interface_pgup || c == KEY_UP || c == KEY_LEFT) && page > 0)page--;
		//PAGE DOWN
		if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page + 1) * 19 < options)page++;
		if (c >= 'a'&&c <= 's')
		{
			int p = page * 19 + (int)(c - 'a');
			if (p < options)
			{
				cr.activity.type = ACTIVITY_RECRUITING;
				cr.activity.arg = recruitable_creatures[p].type;
				break;
			}
		}
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) break;
	}
	return;
}
void show_victim_status(DeprecatedCreature *victim)
{
	const string CONST_activate014 = "Age: ";
	const string CONST_activate013 = "Heart: ";
	const string CONST_activate012 = "Status:";
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(2, 55, CONST_activate012);
	printhealthstat(*victim, 2, 66, true);
	printwoundstat(*victim, 4, 55);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(11, 55, CONST_activate013); mvaddstrAlt(11, 66, victim->get_attribute(ATTRIBUTE_HEART, true));
	mvaddstrAlt(12, 55, CONST_activate014); mvaddstrAlt(12, 66, victim->age);
}
#include <sstream>
vector<string>& split_string(const string &s, char delim, vector<string> &elems) {
	ostringstream oss;
	for (char c : s) {
		if (c == ' ')
		{
			elems.push_back(oss.str());
			oss.str(string());
		}
		else if (c == '\n')
		{
			elems.push_back(oss.str());
			elems.push_back(blankString);
			oss.str(string());
		}
		else oss << c;
	}
	elems.push_back(oss.str());
	return elems;
}
void apply_augmentation(DeprecatedCreature *victim, DeprecatedCreature *cr, AugmentType *selected_aug) {
	extern Log gamelog;

	const string CONST_activate032 = " has been brutally murdered by ";
	const string CONST_activate031 = " has been augmented with ";
	const string CONST_activate030 = " has been horribly disfigured";
	const string CONST_activate029 = "Press any key to return";

	int skills = cr->get_skill(SKILL_SCIENCE) + (cr->get_skill(SKILL_FIRSTAID) / 2);
	int difficulty = selected_aug->get_difficulty();

	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(23, 1, CONST_activate029);
	moveAlt(21, 1);
	int blood_saved = 10 * cr->get_skill(SKILL_SCIENCE) + 15 * cr->get_skill(SKILL_FIRSTAID);
	if (blood_saved > 100) blood_saved = 100;
	victim->blood -= 100 - blood_saved;
	if (skills < difficulty &&
		LCSrandom((100 * difficulty) / skills) < 100)
	{
		unsigned char* wound = nullptr;
		switch (selected_aug->get_type())
		{
		case AUGMENTATION_HEAD:
			wound = &victim->wound[BODYPART_HEAD];
			victim->blood -= 100;
			break;
		case AUGMENTATION_BODY:
			wound = &victim->wound[BODYPART_BODY];
			victim->blood -= 100;
			break;
		case AUGMENTATION_ARMS:
			if (LCSrandom(2))
				wound = &victim->wound[BODYPART_ARM_LEFT];
			else
				wound = &victim->wound[BODYPART_ARM_RIGHT];
			victim->blood -= 25;
			break;
		case AUGMENTATION_LEGS:
			if (LCSrandom(2))
				wound = &victim->wound[BODYPART_LEG_LEFT];
			else
				wound = &victim->wound[BODYPART_LEG_RIGHT];
			victim->blood -= 25;
			break;
		case AUGMENTATION_SKIN:
			if (LCSrandom(2))
				wound = &victim->wound[BODYPART_HEAD];
			else
				wound = &victim->wound[BODYPART_BODY];
			victim->blood -= 50;
			break;
		}
		*wound |= WOUND_NASTYOFF;
		if (victim->blood > 0)
		{
			set_color_easy(RED_ON_BLACK_BRIGHT);
			addstrAlt(string(victim->name) + CONST_activate030, gamelog);
		}
	}
	else //It was successful... but not without some injuries
	{
		unsigned char* wound = nullptr;
		switch (selected_aug->get_type())
		{
		case AUGMENTATION_HEAD:
			wound = &victim->wound[BODYPART_HEAD];
			break;
		case AUGMENTATION_BODY:
			wound = &victim->wound[BODYPART_BODY];
			break;
		case AUGMENTATION_ARMS:
			if (LCSrandom(2))
				wound = &victim->wound[BODYPART_ARM_RIGHT];
			else
				wound = &victim->wound[BODYPART_ARM_LEFT];
			break;
		case AUGMENTATION_LEGS:
			if (LCSrandom(2))
				wound = &victim->wound[BODYPART_LEG_RIGHT];
			else
				wound = &victim->wound[BODYPART_LEG_LEFT];
			break;
		case AUGMENTATION_SKIN:
			wound = &victim->wound[BODYPART_HEAD];
			break;
		}
		*wound |= WOUND_BLEEDING;
		*wound |= WOUND_BRUISED;
		selected_aug->make_augment(victim->get_augmentation(selected_aug->get_type()));
		victim->adjust_attribute(selected_aug->get_attribute(), selected_aug->get_effect());
		cr->train(SKILL_SCIENCE, 15);
		addjuice(*cr, 10, 1000);
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		addstrAlt(string(victim->name) + CONST_activate031 + selected_aug->get_name(), gamelog);
	}
	if (victim->blood <= 0) //Lost too much blood, you killed 'em
	{
		set_color_easy(RED_ON_BLACK_BRIGHT);
		victim->die();
		addstrAlt(string(victim->name) + CONST_activate032 + cr->name, gamelog);
	}
}
void selectAugmentType(vector<AugmentType *> &aug_type, char aug_c, int age);
const string CONST_activate028 = "Are you sure? (y/n)";
const string CONST_activate027 = "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ";
const string CONST_activate026 = "Description";
const string CONST_activate025 = "Chance at Success: ";
const string CONST_activate024 = " +";
const string CONST_activate023 = "Effect: ";
const string CONST_activate022 = "Augmentation: ";
const string CONST_activate021 = "Subject: ";
const string CONST_activate020 = "Select an Augmentation";
const string CONST_activate019 = "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ";
const string CONST_activate017 = "Press a Letter to select a Liberal";
const string CONST_activate016 = "ÄÄÄÄNAMEÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄHEALTHÄÄÄÄÄÄÄÄÄÄÄÄHEARTÄÄÄÄÄÄÄÄAGEÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ";
const string CONST_activate015 = "Select a Liberal to perform experiments on";
void select_augmentation(DeprecatedCreature *cr) //TODO: Finish and general cleanup
{
	extern Log gamelog;
	extern short interface_pgup;
	extern short interface_pgdn;
	DeprecatedCreature *victim = 0;
	vector<DeprecatedCreature *> temppool = getLiberalsSharingLocation(cr);
	int cur_step = 0;
	int page = 0;
	int c = 0;
	int aug_c = 0;
	vector<AugmentType *> aug_type;
	AugmentType *selected_aug;
	while (true)
	{
		eraseAlt();

		switch (cur_step) {
		case 0: //PAGE 0, selecting a liberal
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(0, 0, CONST_activate015);
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(1, 0, CONST_activate016);
			for (int p = page * 19, y = 2; p < len(temppool) && p < page * 19 + 19; p++, y++)
			{
				set_color_easy(WHITE_ON_BLACK); //c==y+'a'-2);
				moveAlt(y, 0);
				addcharAlt(y + 'A' - 2); addstrAlt(spaceDashSpace);
				addstrAlt(temppool[p]->name);
				mvaddstrAlt(y, 49, temppool[p]->get_attribute(ATTRIBUTE_HEART, true));
				mvaddstrAlt(y, 62, temppool[p]->age);
				printhealthstat(*temppool[p], y, 31, TRUE);
			}
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(22, 0, CONST_activate017);
			mvaddstrAlt(23, 0, addpagestr());
			c = getkeyAlt();
			//PAGE UP
			if ((c == interface_pgup || c == KEY_UP || c == KEY_LEFT) && page > 0)page--;
			//PAGE DOWN
			if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page + 1) * 19 < len(temppool))page++;
			if (c >= 'a'&&c <= 's')
			{
				int p = page * 19 + c - 'a';
				if (p < len(temppool))
				{
					victim = temppool[p];
					cur_step = 1;
				}
				else
					victim = 0;
			}
			if (c == 'x' || c == ESC || c == SPACEBAR || c == ENTER) return;
			break;
		case 1: //PAGE 1, selecting an augmentation
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(0, 0, CONST_activate021);
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt(victim->name); addstrAlt(commaSpace); addstrAlt(gettitle(*victim));
			//mvaddstrAlt(1,0,CONST_activate019);
			show_victim_status(victim);
			mvaddstrAlt(2, 1, CONST_activate020);
			for (int p = page * 19, y = 4; p < AUGMENTATIONNUM&&p < page * 19 + 19; p++, y++)
			{
				bool already_augmented = victim->get_augmentation(y - 4).type != -1;
				if (already_augmented) set_color_easy(BLACK_ON_BLACK_BRIGHT);
				else set_color_easy(aug_c == y + 'a' - 4 ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
				moveAlt(y, 1);
				addcharAlt(y + 'A' - 4); addstrAlt(spaceDashSpace);
				addstrAlt(Augmentation::get_name(y - 4));
			}
			if (aug_c >= 'a'&&aug_c <= 'e'&&c >= 'a'&&c <= 'e')
			{
				aug_type.clear();
				if (victim->get_augmentation(aug_c - 'a').type == -1) //False if already augmented on that bodypart.
				{
					selectAugmentType(aug_type, aug_c, victim->age);
				}
			}
			set_color_easy(WHITE_ON_BLACK);
			for (int x = 0, y = 4; x < aug_type.size(); x++, y++)
			{
				mvaddcharAlt(y, 26, y + '1' - 4); addstrAlt(spaceDashSpace);
				addstrAlt(aug_type[x]->get_name());
			}
			//Checks to see if valid input, and moves to next screen
			if (aug_c >= 'a'&&aug_c <= 'e'&&c >= '1'&&c <= '0' + aug_type.size())
			{
				cur_step = 2;
				selected_aug = aug_type[c - '1'];
				break;
			}
			c = getkeyAlt();
			if (c >= 'a'&&c <= 'e') aug_c = c;
			else if (c == ESC)return;
			else if (c == 'x' || c == SPACEBAR || c == ENTER) { cur_step = 0; aug_type.clear(); aug_c = 0; }
			break;
		case 2: //PAGE 2, confirm your choices
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(0, 0, CONST_activate021);
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt(victim->name); addstrAlt(commaSpace); addstrAlt(gettitle(*victim));
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(2, 0, CONST_activate022);
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt(selected_aug->get_name());
			show_victim_status(victim);
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(4, 0, CONST_activate023);
			set_color_easy(WHITE_ON_BLACK);
			string selected_attribute = attribute_enum_to_string(selected_aug->get_attribute());
			addstrAlt((char)(toupper(selected_attribute.at(0))) +
				selected_attribute.substr(1) +
				(selected_aug->get_effect() >= 0 ? CONST_activate024 : singleSpace) +
				tostring(selected_aug->get_effect()));
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(5, 0, CONST_activate025);
			int skills = cr->get_skill(SKILL_SCIENCE) + (cr->get_skill(SKILL_FIRSTAID) / 2);
			int difficulty = selected_aug->get_difficulty();
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt(to_string(100 * skills / difficulty));
			mvaddstrAlt(7, 0, CONST_activate026);
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(8, 0, CONST_activate027);
			vector<string> desc;
			split_string(selected_aug->get_description(), ' ', desc);
			int chars_left = 50;
			int line = 9;
			for (int i = 0; i < desc.size(); i++)
			{
				if (desc[i].length() > 50) continue;
				else if (desc[i] == blankString)
				{
					line++;
					chars_left = 50;
					continue;
				}
				else if (chars_left<0 || desc[i].length()>chars_left)
				{
					line++;
					chars_left = 50;
					i--;
					continue;
				}
				else if (desc[i].length() <= chars_left)
				{
					mvaddstrAlt(line, 50 - chars_left, desc[i]);
					chars_left -= (desc[i].length() + 1);
				}
			}
			mvaddstrAlt(23, 1, CONST_activate028);
			c = getkeyAlt();
			if (c == 'y')
			{
				apply_augmentation(victim, cr, selected_aug);
				show_victim_status(victim);
				pressAnyKey();
				return;
			}
			else if (c == ESC)return;
			else if (c == 'x' || c == SPACEBAR || c == ENTER || c == 'n') { cur_step = 1; selected_aug = nullptr; }
			break;
		}
	}
}
int armor_makedifficulty(ArmorType& type, DeprecatedCreature *cr) //Make class method? -XML
{
	int basedif = type.get_make_difficulty() - cr->get_skill(SKILL_TAILORING) + 3;
	return max(basedif, 0);
}
int armor_makedifficulty(Armor& type, DeprecatedCreature *cr)
{
	extern vector<ArmorType *> armortype;
	return armor_makedifficulty(*armortype[getarmortype(type.get_itemtypename())], cr);
}
/* base - activate - make clothing */
void select_makeclothing(DeprecatedCreature *cr)
{
	const string CONST_activate036 = "Press a Letter to select a Type of Clothing";
	const string CONST_activate035 = "ÄÄÄÄNAMEÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄDIFFICULTYÄÄÄÄÄÄÄÄÄÄÄÄÄCOSTÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ";
	const string CONST_activate034 = " try to make?   (Note: Half Cost if you have cloth)";
	const string CONST_activate033 = "Which will ";
	extern short interface_pgup;
	extern short interface_pgdn;
	extern short lawList[LAWNUM];
	extern vector<ArmorType *> armortype;
	vector<int> armortypei;
	for (int a = 0; a < len(armortype); a++)
	{
		if (armortype[a]->get_make_difficulty() == 0)
			continue;
		if (armortype[a]->deathsquad_legality()
			&& (lawList[LAW_POLICEBEHAVIOR] != -2 || lawList[LAW_DEATHPENALTY] != -2))
			continue;
		armortypei.push_back(a);
	}
	int page = 0;
	while (true)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0, 0, CONST_activate033);
		addstrAlt(cr->name);
		addstrAlt(CONST_activate034);
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(1, 0, CONST_activate035);
		int y = 2;
		for (int p = page * 19; p < len(armortypei) && p < page * 19 + 19; p++, y++)
		{
			set_color_easy(WHITE_ON_BLACK);
			moveAlt(y, 0);
			addcharAlt(y + 'A' - 2); addstrAlt(spaceDashSpace);
			addstrAlt(armortype[armortypei[p]]->get_name());
			moveAlt(y, 37);
			displayDifficulty(MAX(armor_makedifficulty(*armortype[armortypei[p]], cr), 0));
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			string price = '$' + tostring(armortype[armortypei[p]]->get_make_price());
			mvaddstrAlt(y, 64 - len(price), price);
		}
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(22, 0, CONST_activate036);
		mvaddstrAlt(23, 0, addpagestr());
		int c = getkeyAlt();
		//PAGE UP
		if ((c == interface_pgup || c == KEY_UP || c == KEY_LEFT) && page > 0)page--;
		//PAGE DOWN
		if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page + 1) * 19 < len(armortypei))page++;
		if (c >= 'a'&&c <= 's')
		{
			int p = page * 19 + c - 'a';
			if (p < len(armortypei))
			{
				cr->activity.type = ACTIVITY_MAKE_ARMOR;
				cr->activity.arg = armortypei[p]; //Use id name of armor type instead? -XML
				return;
			}
		}
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) break;
	}
}
vector<string> standard_activities_and_data;
void selectOneOfStandardActivities(char c, char choiceChar, DeprecatedCreature *cr) {
	extern bool ZEROMORAL;
	int choice = choiceChar - '1';
	switch (c) {
	case 'a':
		switch (choiceChar)
		{
		case '1':
		case '2':
		case '4':
			//case '5':cr->activity.type=ACTIVITY_DOS_ATTACKS;
		case '5':
		case '6':
			cr->activity.type = activate_menu_items[c][choice].activity;
			break;
		case '3':cr->activity.type = ACTIVITY_GRAFFITI;
			cr->activity.arg = -1;
			break;
		case '7':
			if (cr->location != -1 &&
				LocationsPool::getInstance().get_specific_integer(INT_GETCOMPOUNDWALLS,cr->location) & COMPOUND_PRINTINGPRESS)
			{
				cr->activity.type = ACTIVITY_WRITE_GUARDIAN; break;
			}
		default:
			if (cr->get_attribute(ATTRIBUTE_WISDOM, true) > 7 || cr->juice < 0)
				cr->activity.type = ACTIVITY_COMMUNITYSERVICE;
			else if (cr->get_attribute(ATTRIBUTE_WISDOM, true) > 4)
				cr->activity.type = ACTIVITY_TROUBLE;
			else
			{
				if (cr->get_skill(SKILL_COMPUTERS) > 2)
					cr->activity.type = ACTIVITY_HACKING;
				else if (cr->get_skill(SKILL_ART) > 1)
				{
					cr->activity.type = ACTIVITY_GRAFFITI;
					cr->activity.arg = -1;
				}
				else
					cr->activity.type = ACTIVITY_TROUBLE;
			}
		}
		break;
	case 'b':
		switch (choiceChar)
		{
		case '1':
		case '2':
		case '3':
		case '4':
			cr->activity.type = activate_menu_items[c][choice].activity;
			break;
		default:
			if (cr->get_weapon().get_specific_bool(BOOL_INSTRUMENT_))
				cr->activity.type = ACTIVITY_SELL_MUSIC;
			else if (cr->get_skill(SKILL_ART) > 1)
				cr->activity.type = ACTIVITY_SELL_ART;
			else if (cr->get_skill(SKILL_TAILORING) > 1)
				cr->activity.type = ACTIVITY_SELL_TSHIRTS;
			else if (cr->get_skill(SKILL_MUSIC) > 1)
				cr->activity.type = ACTIVITY_SELL_MUSIC;
			else cr->activity.type = ACTIVITY_DONATIONS;
		}
		break;
	case 'c':
		switch (choiceChar)
		{
		case '1':
		case '3':
			//case '4':cr->activity.type=ACTIVITY_DOS_RACKET;break;
			cr->activity.type = activate_menu_items[c][choice].activity;
			break;
		case '2':
			if (ZEROMORAL || cr->age >= 18)
				cr->activity.type = ACTIVITY_PROSTITUTION; break;
		default:
			if (cr->get_skill(SKILL_COMPUTERS) > 1)
				cr->activity.type = ACTIVITY_CCFRAUD;
			else if (cr->get_skill(SKILL_SEDUCTION) > 1 && (ZEROMORAL || cr->age >= 18))
				cr->activity.type = ACTIVITY_PROSTITUTION;
			else cr->activity.type = ACTIVITY_SELL_DRUGS;
		}
		break;
	case 'd':
		switch (choiceChar)
		{
		case '1': { // Pick type to recruit
			ActivityST oact = cr->activity;
			cr->activity.type = ACTIVITY_NONE;
			recruitSelect(*cr);
			if (cr->activity.type == ACTIVITY_RECRUITING) break;
			else cr->activity = oact;
			break; }
		case '2': { // Pick clothing to make
			ActivityST oact = cr->activity;
			cr->activity.type = ACTIVITY_NONE;
			select_makeclothing(cr);
			if (cr->activity.type == ACTIVITY_MAKE_ARMOR) break;
			else cr->activity = oact;
			break; }
		case '3':
			cr->activity.type = activate_menu_items[c][choice].activity;
			break;
		case '4':
			cr->activity.type = ACTIVITY_STEALCARS;
			break;
		case '5':
			if (!cr->canwalk() && !(cr->flag & CREATUREFLAG_WHEELCHAIR))
				cr->activity.type = ACTIVITY_WHEELCHAIR;
			break;
		case '6': {
			if (cr->get_skill(SKILL_SCIENCE) != 0) {
				ActivityST oact = cr->activity;
				cr->activity.type = ACTIVITY_NONE;
				select_augmentation(cr);
				if (cr->activity.type == ACTIVITY_AUGMENT) break;
				else cr->activity = oact;
			}
			break; }
		}
		break;
	}
}
/* base - activate - hostages */
const string CONST_activate043 = "Press a Letter to select a Conservative";
const string CONST_activate042 = "Day";
const string CONST_activate041 = "Days";
const string CONST_activate040 = "DAYS IN CAPTIVITY";
const string CONST_activate038 = " be watching over?";
const string CONST_activate037 = "Which hostage will ";
void select_tendhostage(DeprecatedCreature *cr)
{
	extern short mode;
	extern short interface_pgup;
	extern short interface_pgdn;
	vector<DeprecatedCreature *> temppool = getHostagesSharingLocation(cr);
	if (!len(temppool))return;
	if (len(temppool) == 1)
	{
		cr->activity.type = ACTIVITY_HOSTAGETENDING;
		cr->activity.arg = temppool[0]->id;
		return;
	}
	int page = 0;
	while (true)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(0, 0, CONST_activate037);
		addstrAlt(cr->name);
		addstrAlt(CONST_activate038);
		mvaddstrAlt(1, 0, CONST_activate067);
		mvaddstrAlt(1, 57, CONST_activate040);
		int y = 2;
		for (int p = page * 19; p < len(temppool) && p < page * 19 + 19; p++, y++)
		{
			set_color_easy(WHITE_ON_BLACK);
			moveAlt(y, 0);
			addcharAlt(y + 'A' - 2); addstrAlt(spaceDashSpace);
			addstrAlt(temppool[p]->name);
			char bright = 0;
			int skill = 0;
			for (int sk = 0; sk < SKILLNUM; sk++)
			{
				skill += temppool[p]->get_skill(sk);
				if (temppool[p]->get_skill_ip(sk) >= 100 + (10 * temppool[p]->get_skill(sk)) &&
					temppool[p]->get_skill(sk) < temppool[p]->skill_cap(sk, true))bright = 1;
			}
			set_color_easy(bright ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
			mvaddstrAlt(y, 25, skill);
			printhealthstat(*temppool[p], y, 33, TRUE);
			if (mode == REVIEWMODE_JUSTICE)set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			else set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(y, 42, LocationsPool::getInstance().getLocationNameWithGetnameMethod(temppool[p]->location, true, true));
			set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
			mvaddstrAlt(y, 57, temppool[p]->joindays);
			addstrAlt(singleSpace);
			if (temppool[p]->joindays > 1)addstrAlt(CONST_activate041);
			else addstrAlt(CONST_activate042);
		}
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(22, 0, CONST_activate043);
		mvaddstrAlt(23, 0, addpagestr());
		int c = getkeyAlt();
		//PAGE UP
		if ((c == interface_pgup || c == KEY_UP || c == KEY_LEFT) && page > 0) page--;
		//PAGE DOWN
		if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page + 1) * 19 < len(temppool)) page++;
		if (c >= 'a'&&c <= 's')
		{
			int p = page * 19 + (int)(c - 'a');
			if (p < len(temppool))
			{
				cr->activity.type = ACTIVITY_HOSTAGETENDING;
				cr->activity.arg = temppool[p]->id;
				return;
			}
		}
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) break;
	}
}
enum LOOP_CONTINUATION {
	RETURN_ZERO,
	RETURN_ONE,
	REPEAT
};
int getKeyInActivate(DeprecatedCreature *cr, const int hostagecount, int &state, const char havedead, const char sieged, const char oldstate) {
	extern long cursquadid;
	int c = getkeyAlt();
	if (c >= 'a'&&c <= 'z') state = c;
	if ((c >= 'a'&&c <= 'z') || (c >= '0'&&c <= '9'))
	{
		int choice = c;
		switch (state)
		{
		case 'a':
		case 'b':
		case 'c':
		case 'd':
			selectOneOfStandardActivities(state, choice, cr);
			break;
		case 't':
			switch (choice)
			{
			case '1':
			case '2':
			case '3':
				// activate_menu_items['t'] starts its index at 0 with ACTIVITY_NONE, instead of starting at 1 the way the other maps do
				// This is a temporary fix as part of a move to basically remove switch(state) as well as switch(choice)
				cr->activity.type = activate_menu_items['t'][(choice - '1') + 1].activity;
				break;
			default:
				cr->activity.type = getDefaultActivityTeaching(cr);
				break;
			}
			break;
		case 'i':
			if (hostagecount > 0)
			{
				ActivityST oact = cr->activity;
				cr->activity.type = ACTIVITY_NONE;
				select_tendhostage(cr);
				if (cr->activity.type == ACTIVITY_HOSTAGETENDING) break;
				else cr->activity = oact;
			}
			state = oldstate;
			break;
		case 'l':
			updateclasschoice(cr, choice);
			break;
		case 'm':
			if (clinictime(*cr)) cr->activity.type = ACTIVITY_CLINIC;
			else state = oldstate;
			break;
		case 'h':
			if (cr->get_skill(SKILL_FIRSTAID)) cr->activity.type = ACTIVITY_HEAL;
			else state = oldstate;
			break;
		case 'z':
			if (havedead) cr->activity.type = ACTIVITY_BURY;
			else state = oldstate;
			break;
		case 'e':
			if (!sieged)
			{

				createTempSquadWithJustThisLiberal(cr, cursquadid);
			}
			state = oldstate;
			break;
		case 'x':
			cr->activity.type = ACTIVITY_NONE;
			break;
		default:
			state = oldstate;
			break;
		}
	}
	return c;
}
const string CONST_activate058 = " will ";
const string CONST_activate057 = "X - Nothing for Now";
const string CONST_activate056 = "Enter - Confirm Selection";
const string CONST_activate055 = "? - Help";
const string CONST_activate054 = "E - Equip this Liberal";
const string CONST_activate053 = "Z - Dispose of bodies";
const string CONST_activate052 = "H - Heal Liberals";
const string CONST_activate051 = "M - Move to the Free Clinic";
const string CONST_activate050 = "L - Learn in the University District";
const string CONST_activate049 = "I - Tend to a Conservative hostage";
const string CONST_activate048 = "T - Teaching Other Liberals";
const string CONST_activate047 = " be doing today?";
const string CONST_activate046 = "Taking Action: What will ";
const string CONST_activate045 = " yesterday. What now?";
const string CONST_activate044 = " made $";
LOOP_CONTINUATION iterateActivate(DeprecatedCreature *cr, const int hostagecount, int &state, const char havedead) {

	extern int selectedsiege;

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK);
	printfunds();
	moveAlt(0, 0);
	if (cr->income)
	{
		addstrAlt(cr->name);
		addstrAlt(CONST_activate044);
		addstrAlt(cr->income);
		addstrAlt(CONST_activate045);
	}
	else
	{
		addstrAlt(CONST_activate046);
		addstrAlt(cr->name);
		addstrAlt(CONST_activate047);
	}
	printcreatureinfo(cr);
	makedelimiter();
	Data_Activity activity = data_activities[(Activity)cr->activity.type];
	if (!state)
	{
		if (activity.key != 'x')
			state = activity.key;
	}
	int oldstate = state;
	for (int i = 0; i < len(standard_activities_and_data); i++) {
		set_color_easy(state == 'a' + i ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
		mvaddstrAlt(10 + i, 1, incrementChar('A', i) + spaceDashSpace + standard_activities_and_data[i]);
	}
	set_color_easy(state == 't' ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
	mvaddstrAlt(14, 1, CONST_activate048);
	if (hostagecount > 0)set_color_easy(state == 'i' ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(15, 1, CONST_activate049);
	set_color_easy(state == 'l' ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
	mvaddstrAlt(16, 1, CONST_activate050);
	if (clinictime(*cr))set_color_easy(state == 'm' ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(17, 1, CONST_activate051);
	if (cr->get_skill(SKILL_FIRSTAID) != 0)
		set_color_easy(state == 'h' ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
	else
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(18, 1, CONST_activate052);
	if (havedead)set_color_easy(state == 'z' ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(19, 1, CONST_activate053);
	char sieged = 0;
	{
		siegest *siege = getseigestFromLocation(selectedsiege);
		if (siege) sieged = siege->siege;
	}
	/*char underattack=0;
	if(siege&&sieged) underattack=siege->underattack;*/
	if (!sieged)
		set_color_easy(WHITE_ON_BLACK);
	else
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(20, 1, CONST_activate054);
	if (state >= 'a' && state < 'a' + len(standard_activities_and_data))
	{
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(19, 40, CONST_activate055);
	}
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(20, 40, CONST_activate056);
	set_color_easy(state == 'x' ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
	mvaddstrAlt(21, 1, CONST_activate057);
	if (state == 'l')
	{
		listclasses(cr);
	}
	else
	{
		int ypos = 10;
		for (ActivityAndString current_item : activate_menu_items[state]) {
			set_color_easy(cr->activity.type == current_item.activity ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
			moveAlt(ypos, 40);
			if (current_item.i > 0)
			{
				addstrAlt(current_item.i);
				addstrAlt(spaceDashSpace);
			}
			ypos++;
			string outputString;
			if (current_item.skill == SKILLNUM) { outputString = current_item.str; }
			else {
				if (cr->get_skill(current_item.skill) >= 8) { outputString = current_item.str3; }
				else
					if (cr->get_skill(current_item.skill) >= 4) { outputString = current_item.str2; }
					else {
						outputString = current_item.str;
					}
			}
			addstrAlt(outputString);
		}
	}
	set_color_easy(WHITE_ON_BLACK);
	moveAlt(22, 3);
	if (activity.show_name)
	{
		addstrAlt(cr->name);
		addstrAlt(CONST_activate058);
	}
	addstrAlt(activity.lineAttempt(0, cr));
	mvaddstrAlt(23, 3, activity.lineAttempt(1, cr));
	mvaddstrAlt(24, 3, activity.lineAttempt(2, cr));
	int c = getKeyInActivate(cr, hostagecount, state, havedead, sieged, oldstate);
	// Enter pressed
	if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) return RETURN_ZERO;
	// ? Pressed
	if (c == '?')
		if (state == 'a' || state == 'b' || state == 'c' || state == 'd')
			HelpActivities(cr->activity.type); // Call activity help pages
	return REPEAT;
}
void activate(DeprecatedCreature *cr)
{
	int hostagecount = countHostagesSharingLocation(cr);
	int state = 0;
	char havedead = countDeadSharingLocation(cr);
	while (iterateActivate(cr, hostagecount, state, havedead) == REPEAT)
	{
		;
	}
}
//Activism
Activity getDefaultActivityActivism(DeprecatedCreature *cr) {
	if (cr->get_attribute(ATTRIBUTE_WISDOM, true) > 7 || cr->juice < 0)
		return ACTIVITY_COMMUNITYSERVICE;
	else if (cr->get_attribute(ATTRIBUTE_WISDOM, true) > 4)
		return ACTIVITY_TROUBLE;
	else
	{
		if (cr->get_skill(SKILL_COMPUTERS) > 2)
			return ACTIVITY_HACKING;
		else if (cr->get_skill(SKILL_ART) > 1)
		{
			cr->activity.arg = -1;
			return ACTIVITY_GRAFFITI;
		}
		else return ACTIVITY_TROUBLE;
	}
}
//Fundraising
Activity getDefaultActivityFundraising(DeprecatedCreature *cr) {
	if (cr->get_weapon().get_specific_bool(BOOL_INSTRUMENT_))
		return ACTIVITY_SELL_MUSIC;
	else if (cr->get_skill(SKILL_ART) > 1)
		return ACTIVITY_SELL_ART;
	else if (cr->get_skill(SKILL_TAILORING) > 1)
		return ACTIVITY_SELL_TSHIRTS;
	else if (cr->get_skill(SKILL_MUSIC) > 1)
		return ACTIVITY_SELL_MUSIC;
	else return ACTIVITY_DONATIONS;
}
//Illegal Fundraising
Activity getDefaultActivityIllegalFundraising(DeprecatedCreature *cr) {
	extern bool ZEROMORAL;
	if (cr->get_skill(SKILL_COMPUTERS) > 1)
		return ACTIVITY_CCFRAUD;
	else if (cr->get_skill(SKILL_SEDUCTION) > 1 && (ZEROMORAL || cr->age >= 18))
		return ACTIVITY_PROSTITUTION;
	else
		return ACTIVITY_SELL_DRUGS;
}
vector<string> bulkActivityString;
const string mostlyendings = "mostlyendings\\";

const string CONST_activate060 = "standard_activities_and_data.txt";
const string CONST_activate059 = "bulkActivityString.txt";
vector<file_and_text_collection> activate_text_file_collection = {
	customText(&bulkActivityString, mostlyendings + CONST_activate059),
	customText(&standard_activities_and_data, mostlyendings + CONST_activate060),
};
void activatebulk()
{
	const string CONST_activate064 = "Press a Letter to Assign an Activity.  Press a Number to select an Activity.";
	const string CONST_activate063 = "BULK ACTIVITY";
	const string CONST_activate062 = "ÄÄÄÄCODE NAMEÄÄÄÄÄÄÄÄÄÄÄÄCURRENT ACTIVITYÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ";
	extern short interface_pgup;
	extern short interface_pgdn;
	vector<DeprecatedCreature *> temppool = activatable_liberals();
	if (!len(temppool)) return;
	int page = 0, selectedactivity = 0;
	while (true)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK);
		printfunds();
		mvaddstrAlt(0, 0, CONST_activate066);
		mvaddstrAlt(1, 0, CONST_activate062);
		mvaddstrAlt(1, 51, CONST_activate063);

		for (int i = 0; i < len(bulkActivityString); i++) {
			set_color_easy(selectedactivity == i ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
			mvaddstrAlt(2 + i, 51, incrementChar('1', i) + spaceDashSpace + bulkActivityString[i]);
		}
		int y = 2;
		for (int p = page * 19; p < len(temppool) && p < page * 19 + 19; p++, y++)
		{
			set_color_easy(WHITE_ON_BLACK);
			moveAlt(y, 0);
			addcharAlt(y + 'A' - 2); addstrAlt(spaceDashSpace);
			addstrAlt(temppool[p]->name);
			moveAlt(y, 25);
			set_activity_color(temppool[p]->activity.type);
			addstrAlt(getactivity(temppool[p]->activity));
			/*if(temppool[p]->activity.type==ACTIVITY_TROUBLE)
			{
			addstrAlt(spaceParanthesisDollar);
			addstrAlt(temppool[p]->activity.arg);
			addstrAlt(closeParenthesis);
			}*/
		}
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(22, 0, CONST_activate064);
		mvaddstrAlt(23, 0, addpagestr());
		int c = getkeyAlt();
		//PAGE UP
		if ((c == interface_pgup || c == KEY_UP || c == KEY_LEFT) && page > 0) page--;
		//PAGE DOWN
		if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page + 1) * 19 < len(temppool)) page++;
		if (c >= 'a'&&c <= 's')
		{
			int p = page * 19 + c - 'a';
			if (p < len(temppool))
			{
				switch (selectedactivity)
				{
				case 0: //Activism
					temppool[p]->activity.type = getDefaultActivityActivism(temppool[p]);
					break;
				case 1: //Fundraising
					temppool[p]->activity.type = getDefaultActivityFundraising(temppool[p]);
					break;
				case 2: //Illegal Fundraising
					temppool[p]->activity.type = getDefaultActivityIllegalFundraising(temppool[p]);
					break;
				case 3: //Check polls
					temppool[p]->activity.type = ACTIVITY_POLLS;
					break;
				case 4: //Steal cars
					temppool[p]->activity.type = ACTIVITY_STEALCARS;
					break;
				case 5: //Volunteer
					temppool[p]->activity.type = ACTIVITY_COMMUNITYSERVICE;
					break;
				case 6: //Repair Clothing
					temppool[p]->activity.type = ACTIVITY_REPAIR_ARMOR;
					break;
				}
			}
		}
		if (c >= '1'&&c <= '7')
			selectedactivity = c - '1';
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) break;
	}
}
/* base - activate the uninvolved */
const string CONST_activate071 = "Press Z to assign simple tasks in bulk.";
const string CONST_activate070 = " T to sort people.";
const string CONST_activate069 = "Press a Letter to Assign an Activity.";
const string CONST_activate068 = "ACTIVITY";
void activate()
{
	extern MusicClass music;
	extern short mode;
	extern short interface_pgup;
	extern short interface_pgdn;
	extern short activesortingchoice[SORTINGCHOICENUM];
	vector<DeprecatedCreature *> temppool = activatable_liberals();
	if (!len(temppool)) return;
	sortliberals(temppool, activesortingchoice[SORTINGCHOICE_ACTIVATE]);
	int page = 0;
	while (true)
	{
		music.play(MUSIC_ACTIVATE);
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK);
		printfunds();
		mvaddstrAlt(0, 0, CONST_activate066);
		mvaddstrAlt(1, 0, CONST_activate067);
		mvaddstrAlt(1, 57, CONST_activate068);
		int y = 2;
		for (int p = page * 19; p < len(temppool) && p < page * 19 + 19; p++, y++)
		{
			set_color_easy(WHITE_ON_BLACK);
			moveAlt(y, 0);
			addcharAlt(y + 'A' - 2); addstrAlt(spaceDashSpace);
			addstrAlt(temppool[p]->name);
			char bright = 0;
			int skill = 0;
			for (int sk = 0; sk < SKILLNUM; sk++)
			{
				skill += temppool[p]->get_skill(sk);
				if (temppool[p]->get_skill_ip(sk) >= 100 + (10 * temppool[p]->get_skill(sk)) &&
					temppool[p]->get_skill(sk) < temppool[p]->skill_cap(sk, true))bright = 1;
			}
			set_color_easy(bright ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
			mvaddstrAlt(y, 25, skill);
			printhealthstat(*temppool[p], y, 33, TRUE);
			if (mode == REVIEWMODE_JUSTICE)set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			else set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(y, 42, LocationsPool::getInstance().getLocationNameWithGetnameMethod(temppool[p]->location, true, true));
			moveAlt(y, 57);
			// Let's add some color here...
			set_activity_color(temppool[p]->activity.type);
			addstrAlt(getactivity(temppool[p]->activity));
		}
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(22, 0, CONST_activate069);
		mvaddstrAlt(23, 0, addpagestr());
		addstrAlt(CONST_activate070);
		mvaddstrAlt(24, 0, CONST_activate071);
		int c = getkeyAlt();
		//PAGE UP
		if ((c == interface_pgup || c == KEY_UP || c == KEY_LEFT) && page > 0) page--;
		//PAGE DOWN
		if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page + 1) * 19 < len(temppool)) page++;
		if (c >= 'a'&&c <= 's')
		{
			int p = page * 19 + c - 'a';
			if (p < len(temppool)) activate(temppool[p]);
		}
		if (c == 't')
		{
			sorting_prompt(SORTINGCHOICE_ACTIVATE);
			sortliberals(temppool, activesortingchoice[SORTINGCHOICE_ACTIVATE], true);
		}
		if (c == 'z') activatebulk();
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) break;
	}
}
