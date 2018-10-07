
#include "../includes.h"

const string tag_POLICECAR = "POLICECAR";
const string tag_WEAPON_SPRAYCAN = "WEAPON_SPRAYCAN";
const string tag_WEAPON = "WEAPON";
const string blankString = "";
const string CONST_activities106 = " has ";
const string CONST_activities121 = "!";
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
// select CONST_activities004, choose CONST_activitiesB187,
// then choose CONST_activities005.
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
#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../items/armortype.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../basemode/activate.h"
// for armor_makedifficulty
#include "../items/loottype.h"
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
#include "../common/commondisplayCreature.h"
// for addstr
#include "../common/translateid.h"
// for  int getsquad(int)
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
// for void criminalize(Creature &,short);
#include "../common/getnames.h"
// for std::string getview(short, bool)
#include "../politics/politics.h"
//for int publicmood(int l);
#include "../combat/chase.h"
#include "../combat/chaseCreature.h"
//for void makechasers(long sitetype,long sitecrime);
#include "../combat/fightCreature.h"  
        
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"

void makeloot(DeprecatedCreature &cr, vector<Item *> &loot);
const string singleDot = ".";
const string singleSpace = " ";
vector<string> quality_0;
vector<string> quality_20;
vector<string> quality_35;
vector<string> quality_50;
vector<string> words_meaning_hacked;
vector<string> enemy_website;
vector<string> win_hand_to_hand;
vector<string> lose_hand_to_hand;
vector<string> car_wont_start;
vector<string> gets_nervous;
vector<string> cant_hotwire_car;
vector<string> almost_hotwire_car;
vector<string> cant_find_keys;
vector<string> cant_find_keys_no_free_speech;
map< Views, stringConnectedToView > pollingData;
map< Activity, CreatureSkill> trainingActivity;
const string activities = "activities\\";

const string CONST_activities022 = "cant_find_keys_no_free_speech.txt";
const string CONST_activities021 = "cant_find_keys.txt";
const string CONST_activities020 = "almost_hotwire_car.txt";
const string CONST_activities019 = "cant_hotwire_car.txt";
const string CONST_activities018 = "gets_nervous.txt";
const string CONST_activities017 = "car_wont_start.txt";
const string CONST_activities016 = "lose_hand_to_hand.txt";
const string CONST_activities015 = "win_hand_to_hand.txt";
const string CONST_activities014 = "enemy_website.txt";
const string CONST_activities013 = "words_meaning_hacked.txt";
const string CONST_activities012 = "quality_50.txt";
const string CONST_activities011 = "quality_35.txt";
const string CONST_activities010 = "quality_20.txt";
const string CONST_activities009 = "quality_0.txt";
vector<file_and_text_collection> activities_text_file_collection = {
	/*activities.cpp*/
	customText(&quality_0, activities + CONST_activities009),
	customText(&quality_20, activities + CONST_activities010),
	customText(&quality_35, activities + CONST_activities011),
	customText(&quality_50, activities + CONST_activities012),
	customText(&words_meaning_hacked, activities + CONST_activities013),
	customText(&enemy_website, activities + CONST_activities014),
	customText(&win_hand_to_hand, activities + CONST_activities015),
	customText(&lose_hand_to_hand, activities + CONST_activities016),
	customText(&car_wont_start, activities + CONST_activities017),
	customText(&gets_nervous, activities + CONST_activities018),
	customText(&cant_hotwire_car, activities + CONST_activities019),
	customText(&almost_hotwire_car, activities + CONST_activities020),
	customText(&cant_find_keys, activities + CONST_activities021),
	customText(&cant_find_keys_no_free_speech, activities + CONST_activities022),
};
void doActivitySolicitDonations(vector<DeprecatedCreature *> &solicit, char &clearformess);
void doActivitySellTshirts(vector<DeprecatedCreature *> &tshirts, char &clearformess);
void doActivitySellArt(vector<DeprecatedCreature *> &art, char &clearformess);
void doActivitySellMusic(vector<DeprecatedCreature *> &music, char &clearformess);
void doActivitySellBrownies(vector<DeprecatedCreature *> &brownies, char &clearformess);
void doActivityHacking(vector<DeprecatedCreature *> &hack, char &clearformess);
void doActivityGraffiti(vector<DeprecatedCreature *> &graffiti, char &clearformess);
void doActivityProstitution(vector<DeprecatedCreature *> &prostitutes, char &clearformess);
void doActivityLearn(vector<DeprecatedCreature *> &students, char &clearformess);
void doActivityTrouble(vector<DeprecatedCreature *> &trouble, char &clearformess);
void doActivityTeach(vector<DeprecatedCreature *> &teachers, char &clearformess);
void doActivityBury(vector<DeprecatedCreature *> &bury, char &clearformess);
void adjustblogpower(int &power)
{
	if (power < 20)
	{
		addstrAlt(pickrandom(quality_0));
		power = -signed(LCSrandom(2));
	}
	else if (power < 35)
	{
		addstrAlt(pickrandom(quality_20));
		power = 1;
	}
	else if (power < 50)
	{
		addstrAlt(pickrandom(quality_35));
		power = 2;
	}
	else
	{
		addstrAlt(pickrandom(quality_50));
		power = 3;
	}
}
struct trainItem {
	CreatureSkill whichSkill;
	int experience;
	int maxLevel;
	trainItem(CreatureSkill whichSkill_, int experience_, int maxLevel_) :whichSkill(whichSkill_), experience(experience_), maxLevel(maxLevel_) {}
};
struct stringAndMaybeTrain {
	string str;
	vector<trainItem> trainingItem;
	stringAndMaybeTrain(const string& str_, const vector<trainItem>& trainingItem_) : str(str_), trainingItem(trainingItem_) {}
};
const string CONST_activities026 = " peruses some sewing magazines.";
const string CONST_activities025 = " cleans the kitchen.";
const string CONST_activities024 = " reorganizes the armor closet.";
const string CONST_activities023 = " tidies up the safehouse.";
vector<stringAndMaybeTrain> cleanSafeHouse = {
	stringAndMaybeTrain(CONST_activities023, vector<trainItem>({})),
	stringAndMaybeTrain(CONST_activities024, vector<trainItem>({})),
	stringAndMaybeTrain(CONST_activities025, vector<trainItem>({})),
	stringAndMaybeTrain(CONST_activities026, vector<trainItem>({ trainItem(SKILL_TAILORING, 1,MAXATTRIBUTE) }))
};
void findArmorToRepair(Armor* armor, Item* pile, int &pileindex, vector<Item* > *pilelist, DeprecatedCreature cr);

int armor_makedifficulty(Armor& type, DeprecatedCreature *cr); //Replace with Armor class method? -XML
int armor_makedifficulty(ArmorType& type, DeprecatedCreature *cr); //Replace with Armor class method? -XML
const string CONST_activities033 = " ruined";
const string CONST_activities032 = " repairs what little can be fixed of ";
const string CONST_activities031 = " finds there is no hope of repairing ";
const string CONST_activities030 = " repairs ";
const string CONST_activities029 = " is working to repair ";
const string CONST_activities028 = " cleans ";
const string CONST_activities027 = " disposes of ";
void repairarmor(DeprecatedCreature &cr, char &clearformess)
{
	extern Log gamelog;
	extern vector<Deprecatedsquadst *> squad;
	Armor *armor = NULL;
	Item *pile = NULL;
	vector<Item *> *pilelist = NULL;
	int pileindex = 0;
	// Clean yourself up first
	if (cr.get_armor().is_bloody() || cr.get_armor().is_damaged())
		armor = &cr.get_armor();
	else if (cr.squadid != -1)
	{
		int sq = getsquad(cr.squadid);
		for (int l = 0; l < len(squad[sq]->loot); l++)
			if (squad[sq]->loot[l]->whatIsThis() == THIS_IS_ARMOR)
			{
				Armor* a = static_cast<Armor*>(squad[sq]->loot[l]); //cast -XML
				if (a->is_bloody() || a->is_damaged())
				{
					armor = a;
					pile = squad[sq]->loot[l];
					pileindex = l;
					pilelist = &squad[sq]->loot;
					break;
				}
			}
	}
	// Multiple passes, to find the best item to work on
	if (cr.location != -1 && armor == NULL) {
		findArmorToRepair(armor, pile, pileindex, pilelist, cr);

	}
	if (clearformess) eraseAlt();
	else makedelimiter();
	if (armor == NULL)
	{
		mvaddstrAlt(8, 1, cr.name, gamelog);
		stringAndMaybeTrain cleaningString = pickrandom(cleanSafeHouse);
		addstrAlt(cleaningString.str, gamelog);
		for (trainItem o : cleaningString.trainingItem) {
			cr.train(o.whichSkill, o.experience, o.maxLevel);
		}
		gamelog.nextMessage();
		pressAnyKey();
	}
	else
	{
		string armorname = armor->get_name();// Get name before we maybe destroy it
		bool repairfailed = false;
		bool qualityReduction = !LCSrandom(10);
		bool armorDestroyed = !armor->decrease_quality(0);
		if (armor->is_damaged())
		{
			long dif = armor_makedifficulty(*armor, &cr);
			dif >>= (armor->get_quality() - 1);  // it is easy to patch up rags
			cr.train(SKILL_TAILORING, dif / 2 + 1);
			if (LCSrandom(1 + dif / 2)) repairfailed = true;
		}
		else {
			repairfailed = true;
		}
		if (armorDestroyed)
			repairfailed = false;  // Its dead, Jim; stop trying to fix it
		if (repairfailed)
			qualityReduction = false; // Low skill repairers shredding your shirts seem too harsh
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(8, 1);
		std::string result = blankString;
		result += cr.name;
		if (armorDestroyed)
		{
			set_color_easy(RED_ON_BLACK_BRIGHT);
			result += CONST_activities027;
		}
		else if (repairfailed && armor->is_bloody())
		{
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			result += CONST_activities028;
		}
		else if (repairfailed)
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			result += CONST_activities029;
		}
		else
		{
			if (!qualityReduction)
			{
				set_color_easy(GREEN_ON_BLACK_BRIGHT);
				result += CONST_activities030;
			}
			else
			{
				armorDestroyed = !armor->decrease_quality(1);
				if (armorDestroyed)
				{
					set_color_easy(RED_ON_BLACK_BRIGHT);
					result += CONST_activities031;
				}
				else
				{
					set_color_easy(YELLOW_ON_BLACK_BRIGHT);
					result += CONST_activities032;
				}
			}
		}
		if (pile)
		{
			result += armor->aan();
		}
		else
			result += cr.hisher();
		if (armorDestroyed)
			result += CONST_activities033;
		result += singleSpace + armorname + singleDot;
		addstrAlt(result, gamelog);
		gamelog.nextMessage();
		if (pile)
		{
			if (pile->get_number() > 1)
			{
				Item *newpile = pile->split(pile->get_number() - 1);
				pilelist->push_back(newpile);
			}
		}
		armor->set_bloody(false);
		if (!repairfailed)
		{
			armor->set_damaged(false);
		}
		if (armorDestroyed)
		{
			if (!pile) // repairer was wearing it
			{
				cr.strip(NULL);
			}
			else // scrap from stockpile
			{
				delete_and_remove(*pilelist, pileindex);
			}
		}
		pressAnyKey();
	}
}
void addLootToLoc(int loc, Item* it);
char tryFindCloth(int cursite);
/* armor manufacture */
const string CONST_activities042 = " wasted the materials for a";
const string CONST_activities041 = "th-rate";
const string CONST_activities040 = "fourth-rate";
const string CONST_activities039 = "third-rate";
const string CONST_activities038 = "second-rate";
const string CONST_activities037 = "first-rate";
const string CONST_activities036 = " has made a ";
const string CONST_activities035 = " cannot find enough cloth to reduce clothing costs.";
const string CONST_activities034 = " cannot afford material for clothing.";
void makearmor(DeprecatedCreature &cr, char &clearformess)
{
	extern Log gamelog;
	extern class Ledger ledger;
	extern vector<Deprecatedsquadst *> squad;
	extern vector<ArmorType *> armortype;
	int at = cr.activity.arg;
	int cost = armortype[at]->get_make_price();
	int hcost = (cost >> 1) + 1;
	int dif = armor_makedifficulty(*armortype[at], &cr);
	if (ledger.get_funds() < hcost)
	{
		if (clearformess) eraseAlt();
		else makedelimiter();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8, 1, cr.name, gamelog);
		addstrAlt(CONST_activities034, gamelog);
		gamelog.nextMessage();
		pressAnyKey();
		return;
	}
	else
	{
		char foundcloth = 0;
		if (cr.squadid != -1)
		{
			int sq = getsquad(cr.squadid);
			for (int l = 0; l < len(squad[sq]->loot); l++)
				if (squad[sq]->loot[l]->whatIsThis() == THIS_IS_LOOT &&
					(squad[sq]->loot[l])->is_cloth()) //cast -XML
				{
					if (squad[sq]->loot[l]->get_number() == 1)
						delete_and_remove(squad[sq]->loot, l);
					else squad[sq]->loot[l]->decrease_number(1);
					foundcloth = 1;
					break;
				}
		}
		if (!foundcloth) foundcloth = tryFindCloth(cr.location);
		if (!foundcloth&&ledger.get_funds() < cost)
		{
			if (clearformess) eraseAlt();
			else makedelimiter();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 1, cr.name, gamelog);
			addstrAlt(CONST_activities035, gamelog);
			gamelog.nextMessage();
			pressAnyKey();
		}
		else
		{
			if (foundcloth) ledger.subtract_funds(hcost, EXPENSE_MANUFACTURE);
			else ledger.subtract_funds(cost, EXPENSE_MANUFACTURE);
			cr.train(SKILL_TAILORING, dif * 2 + 1);
			int quality = 1;
			while (LCSrandom(10) < dif && quality <= armortype[at]->get_quality_levels())
				quality++;
			if (clearformess) eraseAlt();
			else makedelimiter();
			Item *it = new Armor(at, quality);
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 1, cr.name, gamelog);
			if (quality <= ((Armor*)it)->get_quality_levels())
			{
				addstrAlt(CONST_activities036, gamelog);
				switch (quality)
				{
				case 1:addstrAlt(CONST_activities037, gamelog); break;
				case 2:addstrAlt(CONST_activities038, gamelog); break;
				case 3:addstrAlt(CONST_activities039, gamelog); break;
				case 4:addstrAlt(CONST_activities040, gamelog); break;
				default:addstrAlt(quality, gamelog); addstrAlt(CONST_activities041, gamelog); break;
				}
				addLootToLoc(cr.location, it);
			}
			else
			{
				addstrAlt(CONST_activities042, gamelog);
			}
			addstrAlt(singleSpace, gamelog);
			addstrAlt(armortype[at]->get_name(), gamelog);
			addstrAlt(singleDot, gamelog);
			gamelog.nextMessage();
			pressAnyKey();
		}
	}
}
/* search for polls */
map<short, string> supportsLiberalLaw;
int get_noise_based_on_skill(const int creatureskill) {
	int noise;

	if (creatureskill < 1) noise = 18 + LCSrandom(3); // 18 to 20
	else if (creatureskill < 2) noise = 16 + LCSrandom(2); // 16 or 17
	else if (creatureskill < 3) noise = 14 + LCSrandom(2); // 14 or 15
	else if (creatureskill < 4) noise = 12 + LCSrandom(2); // 12 or 13
	else if (creatureskill < 5) noise = 10 + LCSrandom(2); // 10 or 11
	else if (creatureskill < 6) noise = 8 + LCSrandom(2); // 8 or 9
	else if (creatureskill < 7) noise = 7;
	else if (creatureskill < 9) noise = 6;
	else if (creatureskill < 11) noise = 5;
	else if (creatureskill < 14) noise = 4;
	else if (creatureskill < 18) noise = 3;
	else noise = 2;

	return noise;
}
void print_issue_box(const int noise) {
	const string CONST_activities060 = "    ";
	const string CONST_activities059 = "Enter - Done";
	const string CONST_activities058 = " Liberal percentage points.";
	const string CONST_activities057 = "Results are +/- ";
	const string CONST_activities056 = "XX% Issue ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ?Public Interest";
	const string CONST_activities055 = "Additional notable findings:";
	//Header for issue box
	mvaddstrAlt(6, 0, CONST_activities055);
	mvaddstrAlt(7, 0, CONST_activities056);
	//Footer
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(23, 0, CONST_activities057);
	addstrAlt(noise);
	addstrAlt(CONST_activities058);
	mvaddstrAlt(24, 0, CONST_activities059);
	mvaddstrAlt(24, 40, addprevpagestr() + CONST_activities060 + addnextpagestr());
}
const string CONST_activities076 = "wanted amnesty for illegal immigrants";
const string CONST_activities075 = "condemned unnecessary immigration regulations";
const string CONST_activities074 = "believed in legalizing marijuana";
const string CONST_activities073 = "supported keeping marijuana legal";
const string CONST_activities072 = "% ";
const string CONST_activities071 = "??";
const string CONST_activities070 = "None     ";
const string CONST_activities069 = "Low      ";
const string CONST_activities068 = "Moderate ";
const string CONST_activities067 = "High     ";
const string CONST_activities066 = "Very High";
const string CONST_activities063 = "Unknown  ";
const string CONST_activities062 = "........................................................";
const string CONST_activities061 = "                                                                                ";
void draw_issue_page(const int page, const int noise, const int survey[], const char SURVEY_PAGE_SIZE) {


	extern short lawList[LAWNUM];
	extern char newscherrybusted;
	extern char endgamestate;
	extern short public_interest[VIEWNUM];
	extern Log gamelog;

	int y = 8;
	//Draw each line
	for (int v = page * SURVEY_PAGE_SIZE; v < (page + 1)*SURVEY_PAGE_SIZE; v++, y++)
	{
		if (v >= VIEWNUM || (v == VIEW_CONSERVATIVECRIMESQUAD && (endgamestate >= ENDGAME_CCS_DEFEATED || newscherrybusted < 2)))
		{
			mvaddstrAlt(y, 0, CONST_activities061);
			continue;
		}
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(y, 4, CONST_activities062);
		if (noise >= 7 || survey[v] == -1) addstrAlt(CONST_activities063);
		else if (noise >= 4)
		{
			if (public_interest[v] > 50) addstrAlt(CONST_activities067);
			else addstrAlt(CONST_activities069);
		}
		else
		{
			if (public_interest[v] > 100) addstrAlt(CONST_activities066);
			else if (public_interest[v] > 50) addstrAlt(CONST_activities067);
			else if (public_interest[v] > 10) addstrAlt(CONST_activities068);
			else if (public_interest[v]) addstrAlt(CONST_activities069);
			else addstrAlt(CONST_activities070);
		}
		if (survey[v] == -1)set_color_easy(BLACK_ON_BLACK_BRIGHT);
		else if (survey[v] < 10)set_color_easy(RED_ON_BLACK_BRIGHT);
		else if (survey[v] < 30)set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
		else if (survey[v] < 50)set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		else if (survey[v] < 70)set_color_easy(BLUE_ON_BLACK_BRIGHT);
		else if (survey[v] < 90)set_color_easy(CYAN_ON_BLACK_BRIGHT);
		else set_color_easy(GREEN_ON_BLACK_BRIGHT);
		moveAlt(y, 0);
		if (survey[v] == -1) addstrAlt(CONST_activities071);
		else
		{
			if (survey[v] < 10)addcharAlt('0');
			addstrAlt(survey[v]);
		}
		addstrAlt(CONST_activities072);
		if (v == VIEW_DRUGS) {
			if (lawList[LAW_DRUGS] >= 1) addstrAlt(CONST_activities073);
			else addstrAlt(CONST_activities074);
		}
		else if (v == VIEW_IMMIGRATION) {
			if (lawList[LAW_IMMIGRATION] >= 1) addstrAlt(CONST_activities075);
			else addstrAlt(CONST_activities076);
		}
		else {
			addstrAlt(supportsLiberalLaw[v]);
		}
	}
}
void printMostConcernedAbout(const int maxview) {
	//const string CONST_activities048 = "political terrorism.";
	extern short attitude[VIEWNUM];
	extern short lawList[LAWNUM];

	const string CONST_activities053 = "Liberal Media Bias.";
	const string CONST_activities052 = "Conservative Media Bias.";
	const string CONST_activities051 = "the LCS terrorists.";
	const string CONST_activities050 = "the Liberal Crime Squad.";
	const string CONST_activities049 = "activist political groups.";
	switch (maxview)
	{
		//case VIEW_POLITICALVIOLENCE:
		//   if(attitude[VIEW_POLITICALVIOLENCE]>50) addstrAlt(CONST_activities047);
		//   else addstrAlt(CONST_activities048);
		//   break;
	case VIEW_LIBERALCRIMESQUAD:
	case VIEW_LIBERALCRIMESQUADPOS:
		if (attitude[VIEW_LIBERALCRIMESQUAD] < 50) addstrAlt(CONST_activities049);
		else
		{
			if (attitude[VIEW_LIBERALCRIMESQUADPOS] > 50) addstrAlt(CONST_activities050);
			else addstrAlt(CONST_activities051);
		}
		break;
	case VIEW_AMRADIO:
	case VIEW_CABLENEWS:
		if (attitude[VIEW_AMRADIO] + attitude[VIEW_CABLENEWS] > 100) addstrAlt(CONST_activities052);
		else addstrAlt(CONST_activities053);
		break;
	default:
		stringConnectedToView currentView = pollingData[(Views)maxview];
		if (attitude[maxview] > 50) {
			addstrAlt(pollingData[(Views)maxview].aboveFifty);
		}
		else {
			if (lawList[maxview] == 2) {
				addstrAlt(pollingData[(Views)maxview].belowFiftyEliteLiberalLaw);
			}
			else if (lawList[maxview] >= 1) {
				addstrAlt(pollingData[(Views)maxview].belowFiftyLiberalLaw);
			}
			else {
				addstrAlt(currentView.belowFifty);
			}
		}
		break;
	}
}
int surveyValue(const int v, const int noise, const int misschance) {
	extern short attitude[VIEWNUM];
	extern short public_interest[VIEWNUM];
	extern bool SHOWMECHANICS;
	int survey;
	survey = attitude[v];
	//MAKE SURVEY ACCURATE IF DEBUGGING
	if (!SHOWMECHANICS) {
		do { survey += LCSrandom(noise * 2 + 1) - noise; } while (!LCSrandom(20));
	}
	if (survey < 0) survey = 0;
	if (survey > 100) survey = 100;
	if (!SHOWMECHANICS) {
		if (LCSrandom(public_interest[v] + 100) < int(misschance)) survey = -1;
	}
	if (v == VIEW_LIBERALCRIMESQUAD && attitude[v] == 0) survey = -1;
	return survey;
}
int findmaxview(const int _maxview, const int v) {
	extern short public_interest[VIEWNUM];
	int maxview = _maxview;
	if (v != VIEW_LIBERALCRIMESQUAD && v != VIEW_LIBERALCRIMESQUADPOS/*&&v!=VIEW_POLITICALVIOLENCE*/)
	{
		if (_maxview != -1) { if (public_interest[v] > public_interest[_maxview]) maxview = v; }
		else { if (public_interest[v] > 0) maxview = v; }
	}
	return maxview;

}
const string CONST_activities054 = "The public is not concerned with politics right now.";

const string CONST_activities047 = "taking strong action.";
const string CONST_activities046 = "The people are most concerned about ";
const string CONST_activities045 = "President ";
const string CONST_activities044 = "% had a favorable opinion of ";
const string CONST_activities043 = "Survey of Public Opinion, According to Recent Polls";
void survey(DeprecatedCreature *cr)
{
	static const char SURVEY_PAGE_SIZE = 14;
	extern Log gamelog;
	extern MusicClass music;
	extern short interface_pgup;
	extern short interface_pgdn;
	extern Log gamelog;
	extern char newscherrybusted;
	extern char endgamestate;
	extern Deprecatednewsstoryst *sitestory;
	extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	extern short exec[EXECNUM];
	music.play(MUSIC_ELECTIONS);
	const int creatureskill = cr->skill_roll(SKILL_COMPUTERS);
	const int misschance = max(30 - creatureskill, 5);
	const int noise = get_noise_based_on_skill(creatureskill);
	int survey[VIEWNUM];
	int maxview = -1;
	for (int v = 0; v < VIEWNUM; v++)
	{
		survey[v] = surveyValue(v, noise, misschance);
		maxview = findmaxview(maxview, v);
	}
	if (survey[VIEW_LIBERALCRIMESQUAD] <= 0) survey[VIEW_LIBERALCRIMESQUADPOS] = -1;
	eraseAlt();
	//TODO: Sort out the gamelog for this.
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(0, 0, CONST_activities043);
	int approval = presidentapproval();
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(2, 0, approval / 10 + (LCSrandom(noise * 2 + 1) - noise), gamelog);
	addstrAlt(CONST_activities044);
	set_alignment_color(exec[EXEC_PRESIDENT], true);
	addstrAlt(CONST_activities045);
	addstrAlt(execname[EXEC_PRESIDENT]);
	set_color_easy(WHITE_ON_BLACK);
	addstrAlt(singleDot);
	//Top excitement issue
	if (maxview != -1)
	{
		mvaddstrAlt(4, 0, CONST_activities046);
		printMostConcernedAbout(maxview);
	}
	else
	{
		mvaddstrAlt(4, 0, CONST_activities054);
	}
	print_issue_box(noise);
	int page = 0;
	const int maxpage = VIEWNUM / SURVEY_PAGE_SIZE;
	int c = '0';
	while (c != 'x' && c != ENTER && c != ESC && c != SPACEBAR)
	{
		//Keep pages within bounds
		if (page < 0) page = maxpage;
		if (page > maxpage) page = 0;
		//Start from the top
		draw_issue_page(page, noise, survey, SURVEY_PAGE_SIZE);
		do {
			c = getkeyAlt();
			if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) {}
			else if (c == interface_pgup || c == KEY_UP || c == KEY_LEFT) { page--; }
			else if (c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) { page++; }
		} while (c != 'x' && c != ENTER && c != ESC && c != SPACEBAR && c != interface_pgup && c != KEY_UP && c != KEY_LEFT && c != interface_pgdn && c != KEY_DOWN && c != KEY_RIGHT);

	}
}
// Police accost your liberal!
void attemptarrest(DeprecatedCreature & liberal, const char* str, int clearformess)
{

	const string CONST_activities077 = " is accosted by police while ";

	extern Log gamelog;
	extern Deprecatednewsstoryst *sitestory;
	extern chaseseqst chaseseq;
	extern vector<Deprecatednewsstoryst *> newsstory;
	if (str)
	{
		if (clearformess) eraseAlt();
		else makedelimiter();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8, 1, liberal.name, gamelog);
		addstrAlt(CONST_activities077, gamelog);
		addstrAlt(str, gamelog);
		addstrAlt(CONST_activities121, gamelog);
		gamelog.nextMessage();
		pressAnyKey();
	}
	// Chase sequence! Wee!
	makechasers(-1, 5);
	if (!sitestory)
	{
		Deprecatednewsstoryst *ns = new Deprecatednewsstoryst;
		ns->type = NEWSSTORY_WANTEDARREST; // TODO: Make a more generic catch-all arrest story
		ns->loc = -1;
		newsstory.push_back(ns);
		sitestory = ns;
	}
	chaseseq.clean();
	chaseseq.location = LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONPARENT,liberal.location);
	footchase(liberal);
}
// While galavanting in public, your liberals may be ambushed by police
int checkforarrest(DeprecatedCreature & liberal, const char* string, int clearformess)
{
	extern Deprecatednewsstoryst *sitestory;
	extern vector<Deprecatednewsstoryst *> newsstory;
	bool arrest = false;
	if (!liberal.animalgloss && liberal.is_naked() && LCSrandom(2))
	{
		criminalize(liberal, LAWFLAG_DISTURBANCE);
		Deprecatednewsstoryst *ns = new Deprecatednewsstoryst;
		ns->type = NEWSSTORY_NUDITYARREST;
		ns->loc = -1;
		newsstory.push_back(ns);
		sitestory = ns;
		arrest = true;
	}
	else if (liberal.heat > liberal.get_skill(SKILL_STREETSENSE) * 10)
	{
		if (!LCSrandom(50))
		{
			Deprecatednewsstoryst *ns = new Deprecatednewsstoryst;
			ns->type = NEWSSTORY_WANTEDARREST;
			ns->loc = -1;
			newsstory.push_back(ns);
			sitestory = ns;
			arrest = true;
		}
	}
	if (arrest) attemptarrest(liberal, string, clearformess);
	return arrest;
}
#include "../common/creaturePool.h"
/* misc activation related things */
// *JDSRETURN*
void funds_and_trouble(char &clearformess)
{
	extern short background_liberal_influence[VIEWNUM];
	//ACTIVITIES FOR INDIVIDUALS
	extern vector<DeprecatedCreature *> pool;
	vector<DeprecatedCreature *> trouble, hack, bury, solicit, tshirts, art, music, graffiti, brownies, prostitutes, teachers, students;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (!pool[p]->alive) continue;
		if (pool[p]->location == -1)
		{
			pool[p]->activity.type = ACTIVITY_NONE;
			continue;
		}
		switch (pool[p]->activity.type)
		{
		case ACTIVITY_TEACH_FIGHTING:
		case ACTIVITY_TEACH_POLITICS:
		case ACTIVITY_TEACH_COVERT:
			teachers.push_back(pool[p]);
			break;
		case ACTIVITY_CCFRAUD:
		case ACTIVITY_DOS_RACKET:
		case ACTIVITY_DOS_ATTACKS:
		case ACTIVITY_HACKING:
			hack.push_back(pool[p]);
			break;
		case ACTIVITY_GRAFFITI:
			graffiti.push_back(pool[p]);
			break;
		case ACTIVITY_TROUBLE:
			trouble.push_back(pool[p]);
			break;
		case ACTIVITY_COMMUNITYSERVICE:
			addjuice(*pool[p], 1, 10);
			change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 1, 0, 80);
			break;
		case ACTIVITY_SELL_TSHIRTS:
			tshirts.push_back(pool[p]);
			break;
		case ACTIVITY_SELL_ART:
			art.push_back(pool[p]);
			break;
		case ACTIVITY_SELL_MUSIC:
			music.push_back(pool[p]);
			break;
		case ACTIVITY_DONATIONS:
			solicit.push_back(pool[p]);
			break;
		case ACTIVITY_SELL_DRUGS:
			brownies.push_back(pool[p]);
			break;
		case ACTIVITY_PROSTITUTION:
			prostitutes.push_back(pool[p]);
			break;
		case ACTIVITY_BURY:
			bury.push_back(pool[p]);
			pool[p]->activity.type = ACTIVITY_NONE;
			break;
		case ACTIVITY_CLINIC:
			hospitalize(find_site_index_in_same_city(SITE_HOSPITAL_CLINIC, pool[p]->location), *pool[p]);
			pool[p]->activity.type = ACTIVITY_NONE;
			break;
		case ACTIVITY_STUDY_DEBATING:
		case ACTIVITY_STUDY_MARTIAL_ARTS:
		case ACTIVITY_STUDY_DRIVING:
		case ACTIVITY_STUDY_PSYCHOLOGY:
		case ACTIVITY_STUDY_FIRST_AID:
		case ACTIVITY_STUDY_LAW:
		case ACTIVITY_STUDY_DISGUISE:
		case ACTIVITY_STUDY_SCIENCE:
		case ACTIVITY_STUDY_BUSINESS:
			//case ACTIVITY_STUDY_COOKING:
		case ACTIVITY_STUDY_GYMNASTICS:
		case ACTIVITY_STUDY_ART:
		case ACTIVITY_STUDY_TEACHING:
		case ACTIVITY_STUDY_MUSIC:
		case ACTIVITY_STUDY_WRITING:
		case ACTIVITY_STUDY_LOCKSMITHING:
		case ACTIVITY_STUDY_COMPUTERS:
		case ACTIVITY_STUDY_FENCING:
		case ACTIVITY_STUDY_WEAVING:
		case ACTIVITY_STUDY_RELIGION:
			//case ACTIVITY_STUDY_MAGIC:
		case ACTIVITY_STUDY_CLUB:
		case ACTIVITY_STUDY_STREETSENSE:
		case ACTIVITY_STUDY_THROWING:
		case ACTIVITY_STUDY_STEALTH:
		case ACTIVITY_STUDY_SEDUCTION:
			students.push_back(pool[p]);
			break;
		case ACTIVITY_SLEEPER_JOINLCS:
			if (!LocationsPool::getInstance().isThereASiegeHere(find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, pool[p]->location)))
			{
				pool[p]->activity.type = ACTIVITY_NONE;
				pool[p]->flag &= ~CREATUREFLAG_SLEEPER;
				pool[p]->location = pool[p]->base = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, pool[p]->location);
			}
			//Letters to the editor
		case ACTIVITY_WRITE_LETTERS:
			if (pool[p]->skill_check(SKILL_WRITING, DIFFICULTY_EASY))
				background_liberal_influence[randomissue()] += 5;
			pool[p]->train(SKILL_WRITING, LCSrandom(5) + 1);
			break;
			//Guardian Essays
			//Basically letters to the editor, but thrice as potent, and can backfire
		case ACTIVITY_WRITE_GUARDIAN:
			if (pool[p]->skill_check(SKILL_WRITING, DIFFICULTY_EASY))
				background_liberal_influence[randomissue()] += 15;
			else
				background_liberal_influence[randomissue()] -= 15;
			pool[p]->train(SKILL_WRITING, LCSrandom(5) + 1);
			break;
		}
	}
	doActivitySolicitDonations(solicit, clearformess);
	doActivitySellTshirts(tshirts, clearformess);
	doActivitySellArt(art, clearformess);
	doActivitySellMusic(music, clearformess);
	doActivitySellBrownies(brownies, clearformess);
	doActivityHacking(hack, clearformess);
	doActivityGraffiti(graffiti, clearformess);
	doActivityProstitution(prostitutes, clearformess);
	doActivityLearn(students, clearformess);
	doActivityTrouble(trouble, clearformess);
	doActivityTeach(teachers, clearformess);
	doActivityBury(bury, clearformess);
}
void doActivitySolicitDonations(vector<DeprecatedCreature *> &solicit, char &clearformess)
{  //SOLICITORS
	const string CONST_activities079 = "soliciting donations";
	extern class Ledger ledger;
	long total_income = 0;
	for (int s = 0; s < len(solicit); s++)
	{
		if (!checkforarrest(*solicit[s], CONST_activities079.c_str(), clearformess))
		{
			int income = solicit[s]->skill_roll(SKILL_PERSUASION) *
				solicit[s]->get_armor().get_professionalism() + 1;
			// Country's alignment dramatically affects effectiveness
			// The more conservative the country, the more effective
			if (publicmood(-1) > 90) income /= 2;
			if (publicmood(-1) > 65) income /= 2;
			if (publicmood(-1) > 35) income /= 2;
			if (publicmood(-1) > 10) income /= 2;
			solicit[s]->income = income;
			total_income += income;
			solicit[s]->train(SKILL_PERSUASION, max(5 - solicit[s]->get_skill(SKILL_PERSUASION), 2));
		}
	}
	ledger.add_funds(total_income, INCOME_DONATIONS);
}
void doActivitySellTshirts(vector<DeprecatedCreature *> &tshirts, char &clearformess)
{
	const string CONST_activities080 = "selling shirts";
	extern class Ledger ledger;
	extern short background_liberal_influence[VIEWNUM];
	for (int s = 0; s < len(tshirts); s++)
	{
		if (!checkforarrest(*tshirts[s], CONST_activities080.c_str(), clearformess))
		{
			long money = (tshirts[s]->skill_roll(SKILL_TAILORING) +
				tshirts[s]->skill_roll(SKILL_BUSINESS)) / 2;
			// Country's alignment affects effectiveness
			// In a Liberal country, there are many competing vendors
			if (publicmood(-1) > 65) money /= 2;
			if (publicmood(-1) > 35) money /= 2;
			//If you're selling epic shirts enough they'll have some political impact
			if (tshirts[s]->skill_check(SKILL_TAILORING, DIFFICULTY_FORMIDABLE))
				background_liberal_influence[randomissue()] += 5;
			tshirts[s]->income = money;
			ledger.add_funds(money, INCOME_TSHIRTS);
			tshirts[s]->train(SKILL_TAILORING, max(7 - tshirts[s]->get_skill(SKILL_TAILORING), 2));
			tshirts[s]->train(SKILL_BUSINESS, max(7 - tshirts[s]->get_skill(SKILL_BUSINESS), 2));
		}
	}
}
void doActivitySellArt(vector<DeprecatedCreature *> &art, char &clearformess)
{
	const string CONST_activities081 = "sketching portraits";
	extern class Ledger ledger;
	extern short background_liberal_influence[VIEWNUM];
	for (int s = 0; s < len(art); s++)
	{
		if (!checkforarrest(*art[s], CONST_activities081.c_str(), clearformess))
		{
			long money = art[s]->skill_roll(SKILL_ART);
			// Country's alignment affects effectiveness
			// In a Liberal country, there are many competing vendors
			if (publicmood(-1) > 65) money /= 2;
			if (publicmood(-1) > 35) money /= 2;
			//Epic Liberal art may have positive political effect
			if (art[s]->skill_check(SKILL_ART, DIFFICULTY_FORMIDABLE))
				background_liberal_influence[randomissue()] += 5;
			art[s]->income = money;
			ledger.add_funds(money, INCOME_SKETCHES);
			art[s]->train(SKILL_ART, max(7 - art[s]->get_skill(SKILL_ART), 4));
		}
	}
}
void doActivitySellMusic(vector<DeprecatedCreature *> &music, char &clearformess)
{
	const string CONST_activities082 = "playing music";
	extern class Ledger ledger;
	extern short background_liberal_influence[VIEWNUM];
	for (int s = 0; s < len(music); s++)
	{
		if (!checkforarrest(*music[s], CONST_activities082.c_str(), clearformess))
		{
			long money = music[s]->skill_roll(SKILL_MUSIC) / 2;
			bool has_instrument = music[s]->get_weapon().get_specific_bool(BOOL_INSTRUMENT_);
			if (has_instrument) money *= 4;
			// Country's alignment affects effectiveness
			// In a Liberal country, there are many competing vendors
			if (publicmood(-1) > 65) money /= 2;
			if (publicmood(-1) > 35) money /= 2;
			//Epic Liberal protest songs
			if (music[s]->skill_check(SKILL_MUSIC, DIFFICULTY_FORMIDABLE))
				background_liberal_influence[randomissue()] += has_instrument ? 10 : 5;
			ledger.add_funds(money, INCOME_BUSKING);
			music[s]->income = money;
			if (has_instrument) music[s]->train(SKILL_MUSIC, max(7 - music[s]->get_skill(SKILL_MUSIC), 4));
			else music[s]->train(SKILL_MUSIC, max(5 - music[s]->get_skill(SKILL_MUSIC), 2));
		}
	}
}
void doActivitySellBrownies(vector<DeprecatedCreature *> &brownies, char &clearformess)
{
	const string CONST_activities083 = "selling brownies";
	extern Deprecatednewsstoryst *sitestory;
	extern class Ledger ledger;
	extern short lawList[LAWNUM];
	extern vector<Deprecatednewsstoryst *> newsstory;
	for (int s = 0; s < len(brownies); s++)
	{
		//Check for police search
		int dodgelawroll = LCSrandom(1 + 30 * lawList[LAW_DRUGS] + 3);
		//Saved by street sense?
		if (dodgelawroll == 0)
			dodgelawroll = brownies[s]->skill_check(SKILL_STREETSENSE, DIFFICULTY_AVERAGE);
		if (dodgelawroll == 0 && lawList[LAW_DRUGS] <= 0) // Busted!
		{
			Deprecatednewsstoryst *ns = new Deprecatednewsstoryst;
			ns->type = NEWSSTORY_DRUGARREST;
			ns->loc = -1;
			newsstory.push_back(ns);
			sitestory = ns;
			criminalize(*brownies[s], LAWFLAG_BROWNIES);
			attemptarrest(*brownies[s], CONST_activities083.c_str(), clearformess);
		}
		long money = brownies[s]->skill_roll(SKILL_PERSUASION) +
			brownies[s]->skill_roll(SKILL_BUSINESS) +
			brownies[s]->skill_roll(SKILL_STREETSENSE);
		// more money when more illegal
		if (lawList[LAW_DRUGS] == -2) money *= 4;
		if (lawList[LAW_DRUGS] == -1) money *= 2;
		if (lawList[LAW_DRUGS] == 1) money /= 4;
		if (lawList[LAW_DRUGS] == 2) money /= 8;
		brownies[s]->income = money;
		ledger.add_funds(money, INCOME_BROWNIES);
		// Make the sale
		brownies[s]->train(SKILL_PERSUASION, max(4 - brownies[s]->get_skill(SKILL_PERSUASION), 1));
		// Know the streets
		brownies[s]->train(SKILL_STREETSENSE, max(7 - brownies[s]->get_skill(SKILL_STREETSENSE), 3));
		// Manage your money
		brownies[s]->train(SKILL_BUSINESS, max(10 - brownies[s]->get_skill(SKILL_BUSINESS), 3));
	}
}
vector<activityData> hackingActivities;
#include "../items/lootTypePoolItem.h"
void doActivityHacking(vector<DeprecatedCreature *> &hack, char &clearformess)
{
	const string CONST_activities088 = " a ";
	const string CONST_activities086 = "Your hackers have ";
	const string CONST_activities084 = "Your Hackers have ";
	extern Log gamelog;
	extern class Ledger ledger;
	if (len(hack))
	{
		vector<DeprecatedCreature *> cc,/*web,ddos,*/truehack;
		//First, do accounting to figure out who's doing what
		for (int h = 0; h < len(hack); h++)
		{
			switch (hack[h]->activity.type)
			{
			case ACTIVITY_CCFRAUD:
				hack[h]->train(SKILL_COMPUTERS, 2);
				cc.push_back(hack[h]);
				break;
			case ACTIVITY_DOS_ATTACKS:
				hack[h]->train(SKILL_COMPUTERS, 2);
				//web.push_back(hack[h]);
				break;
			case ACTIVITY_DOS_RACKET:
				hack[h]->train(SKILL_COMPUTERS, 4);
				// ddos.push_back(hack[h]);
				break;
			case ACTIVITY_HACKING:
				hack[h]->train(SKILL_COMPUTERS, 4);
				truehack.push_back(hack[h]);
				break;
			}
		}
		char msg[200] = { 0 };
		//MAJOR HACKING
		int hack_skill = 0;
		for (int h = 0; h < len(truehack); h++)
			hack_skill = max(hack_skill, truehack[h]->skill_roll(SKILL_COMPUTERS));
		if (DIFFICULTY_HEROIC <= hack_skill + len(truehack) - 1)
		{
			if (len(truehack) > 1) strcpy(msg, CONST_activities084.c_str());
			else { strcpy(msg, truehack[0]->name); strcat(msg, CONST_activities106.c_str()); }
			int trackdif = 0, juiceval = 0;
			int short crime = 0;
			activityData currentActivity = pickrandom(hackingActivities);
			strcat(msg, currentActivity.msgString);
			trackdif = currentActivity.difficulty;
			crime = currentActivity.crime;
			juiceval = currentActivity.juiceval;
			if (len(currentActivity.lootType) > 0) {
				addLootToLoc(hack[0]->location, getNewLoot(pickrandom(currentActivity.lootType)));
			}
			for (ChangeOfOpinion o : currentActivity.opinion) {
				change_public_opinion(o.view, o.x, o.y, o.z);
			}
			if (trackdif > hack_skill + LCSrandom(5) - 2)
				for (int h = 0; h < len(truehack); h++)
					criminalize(*hack[h], crime);
			// Award juice to the hacking team for a job well done
			for (int h = 0; h < len(truehack); h++)
				addjuice(*truehack[h], juiceval, 200);
		}
		else if (DIFFICULTY_FORMIDABLE <= hack_skill + len(truehack) - 1)
		{
			int issue = LCSrandom(VIEWNUM - 5), crime = LAWFLAG_INFORMATION;
			if (len(truehack) > 1) strcpy(msg, CONST_activities086.c_str());
			else { strcpy(msg, truehack[0]->name); strcat(msg, CONST_activities106.c_str()); }
			strcat(msg, pickrandom(words_meaning_hacked).data());
			strcat(msg, CONST_activities088.c_str());
			strcat(msg, pickrandom(enemy_website).data());
			strcat(msg, singleDot.data());
			change_public_opinion(issue, 1);
			if (DIFFICULTY_HEROIC > hack_skill + LCSrandom(5) - 2)
				for (int h = 0; h < len(truehack); h++)
					criminalize(*truehack[h], crime);
			// Award juice to the hacking team for a job well done
			for (int h = 0; h < len(truehack); h++)
				addjuice(*truehack[h], 5, 100);
		}
		if (msg[0])
		{
			if (clearformess) eraseAlt();
			else makedelimiter();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 1, msg, gamelog);
			gamelog.nextMessage();
			msg[0] = 0;
			pressAnyKey();
		}
		//CREDIT CARD FRAUD
		for (int h = 0; h < len(cc); h++)
		{
			hack_skill = cc[h]->skill_roll(SKILL_COMPUTERS);
			int difficulty = DIFFICULTY_CHALLENGING;
			if (difficulty <= hack_skill)
			{
				// *JDS* You get between $1 and $100, plus an extra $1-50 every
				// time you pass a check against your hacking skill, where chance of
				// failure is one over the adjusted hackers' skill divided by four. Once
				// a check fails, no more money is gained. This check will be made
				// up to 20 times, at which point the loop breaks. The skill check
				// here doesn't take into account funding.
				int fundgain = LCSrandom(101);
				while (difficulty < hack_skill)
				{
					fundgain += LCSrandom(51);
					difficulty += 2;
				}
				ledger.add_funds(fundgain, INCOME_CCFRAUD);
				cc[h]->income = fundgain / len(cc);
				if (fundgain / 25 > LCSrandom(hack_skill + 1))
					criminalize(*cc[h], LAWFLAG_CCFRAUD);
			}
			if (msg[0])
			{
				if (clearformess) eraseAlt();
				else makedelimiter();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8, 1, msg, gamelog); //TODO: Log this?
				gamelog.nextMessage();
				msg[0] = 0;
				pressAnyKey();
			}
		}
	}
}
string gimmeASprayCan(DeprecatedCreature* graffiti);
void buyMeASprayCan(DeprecatedCreature* graffiti);
void doActivityGraffiti(vector<DeprecatedCreature *> &graffiti, char &clearformess)
{
	const string CONST_activities100 = " has begun work on a large mural about ";
	const string CONST_activities099 = " works through the night on a large mural.";
	const string CONST_activities098 = " mural about ";
	const string CONST_activities097 = " beautiful";
	const string CONST_activities096 = " has completed a";
	const string CONST_activities095 = " while spraying an LCS tag!";
	const string CONST_activities094 = " while working on the mural!";
	const string CONST_activities093 = " was spotted by the police";
	const string CONST_activities092 = " needs a spraycan equipped to do graffiti.";
	const string CONST_activities091 = " bought spraypaint for graffiti.";
	const string CONST_activities090 = " from ";
	const string CONST_activities089 = " grabbed a ";
	extern Deprecatednewsstoryst *sitestory;
	extern Log gamelog;
	extern class Ledger ledger;
	extern short public_interest[VIEWNUM];
	extern short background_liberal_influence[VIEWNUM];
	extern vector<Deprecatednewsstoryst *> newsstory;
	if (len(graffiti))
	{
		for (int s = 0; s < len(graffiti); s++)
		{
			if (!graffiti[s]->get_weapon().get_specific_bool(BOOL_CAN_GRAFFITI_))
			{
				if (clearformess) eraseAlt();
				else makedelimiter();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8, 1, graffiti[s]->name, gamelog);
				//Check base inventory for a spraycan
				bool foundone = false;
				string gottaCan = gimmeASprayCan(graffiti[s]);
				if (len(gottaCan)) {
					foundone = true;
					addstrAlt(CONST_activities089, gamelog);
					addstrAlt(gottaCan, gamelog);
					addstrAlt(CONST_activities090, gamelog);
					addstrAlt(LocationsPool::getInstance().getLocationName(graffiti[s]->base)); //TODO: Explicitly log it, or will the game log it?
					addstrAlt(singleDot, gamelog);
					pressAnyKey();
				}

				if (!foundone && ledger.get_funds() >= 20)
				{
					ledger.subtract_funds(20, EXPENSE_SHOPPING);
					addstrAlt(CONST_activities091, gamelog);
					pressAnyKey();
					buyMeASprayCan(graffiti[s]);
				}
				else if (!foundone)
				{
					addstrAlt(CONST_activities092, gamelog);
					graffiti[s]->activity.type = ACTIVITY_NONE;
					pressAnyKey();
				}
				gamelog.nextMessage(); //Next message now so that we don't have to type it for every case.
			}
			int issue = VIEW_LIBERALCRIMESQUAD, power = 1;
			if (clearformess) eraseAlt();
			else makedelimiter();
			if (!LCSrandom(10) &&
				!(graffiti[s]->skill_check(SKILL_STREETSENSE, DIFFICULTY_AVERAGE)))
			{
				if (clearformess) eraseAlt();
				else makedelimiter();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8, 1, graffiti[s]->name, gamelog);
				addstrAlt(CONST_activities093, gamelog);
				criminalize(*graffiti[s], LAWFLAG_VANDALISM);
				graffiti[s]->train(SKILL_STREETSENSE, 20);
				if (graffiti[s]->activity.arg != -1)
				{
					addstrAlt(CONST_activities094, gamelog);
					graffiti[s]->activity.arg = -1;
				}
				else addstrAlt(CONST_activities095, gamelog);
				gamelog.nextMessage();
				Deprecatednewsstoryst *ns = new Deprecatednewsstoryst;
				ns->type = NEWSSTORY_GRAFFITIARREST;
				ns->loc = -1;
				ns->positive = 0;
				newsstory.push_back(ns);
				sitestory = ns;
				pressAnyKey();
				attemptarrest(*graffiti[s], NULL, clearformess);
			}
			else if (graffiti[s]->activity.arg != -1)
			{
				power = 0;
				if (!LCSrandom(3))
				{
					issue = graffiti[s]->activity.arg;
					power = graffiti[s]->skill_roll(SKILL_ART) / 3;
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8, 1, graffiti[s]->name, gamelog);
					addstrAlt(CONST_activities096, gamelog);
					if (power > 3)addstrAlt(CONST_activities097, gamelog);
					addstrAlt(CONST_activities098, gamelog);
					addstrAlt(getview(issue, false), gamelog);
					addstrAlt(singleDot, gamelog);
					gamelog.nextMessage();
					graffiti[s]->activity.arg = -1;
					addjuice(*graffiti[s], power, power * 20);
					change_public_opinion(issue, power);
					graffiti[s]->train(SKILL_ART, max(10 - graffiti[s]->get_skill(SKILL_ART) / 2, 1));
					pressAnyKey();
				}
				else
				{
					power = 0;
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8, 1, graffiti[s]->name, gamelog);
					addstrAlt(CONST_activities099, gamelog);
					gamelog.nextMessage();
					graffiti[s]->train(SKILL_ART, max(10 - graffiti[s]->get_skill(SKILL_ART) / 2, 1));
					pressAnyKey();
				}
			}
			else if (!LCSrandom(max(30 - graffiti[s]->get_skill(SKILL_ART) * 2, 5)))
			{
				issue = randomissue();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8, 1, graffiti[s]->name, gamelog);
				addstrAlt(CONST_activities100, gamelog);
				addstrAlt(getview(issue, false), gamelog);
				addstrAlt(singleDot, gamelog);
				gamelog.nextMessage();
				graffiti[s]->activity.arg = issue;
				power = 0;
				graffiti[s]->train(SKILL_ART, max(10 - graffiti[s]->get_skill(SKILL_ART) / 2, 1));
				pressAnyKey();
			}
			graffiti[s]->train(SKILL_ART, max(4 - graffiti[s]->get_skill(SKILL_ART), 0));
			if (issue == VIEW_LIBERALCRIMESQUAD)
			{
				change_public_opinion(VIEW_LIBERALCRIMESQUAD, LCSrandom(2), 0, 65);
				change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, !LCSrandom(8), 0, 65);
				public_interest[issue] += power;
			}
			else
			{
				change_public_opinion(VIEW_LIBERALCRIMESQUAD, LCSrandom(2) + 1, 0, 85);
				change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, !LCSrandom(4), 0, 65);
				public_interest[issue] += power;
				background_liberal_influence[issue] += power;
			}
		}
	}
}
void doActivityProstitution(vector<DeprecatedCreature *> &prostitutes, char &clearformess)
{
	const string CONST_activities102 = " was nearly caught in a prostitution sting.";
	const string CONST_activities101 = " has been arrested in a prostitution sting.";
	extern Log gamelog;
	extern class Ledger ledger;
	for (int p = len(prostitutes) - 1; p >= 0; p--)
	{
		// Business once every three days or so
		if (LCSrandom(3)) continue;
		//char num[20];
		long fundgain = 0;
		char caught = 0;
		// Skill determies how much money you get
		int performance = prostitutes[p]->skill_roll(SKILL_SEDUCTION);
		if (performance > DIFFICULTY_HEROIC)
			fundgain = LCSrandom(201) + 200;
		else
			fundgain = LCSrandom(10 * performance) + 10 * performance;
		// Street sense check or deal with slimy people that reduce dignity and juice
		if (!LCSrandom(3) &&
			!(prostitutes[p]->skill_check(SKILL_STREETSENSE, DIFFICULTY_AVERAGE)))
		{
			addjuice(*prostitutes[p], -!LCSrandom(3), -20);
		}
		// Gain seduction and street sense
		prostitutes[p]->train(SKILL_SEDUCTION, max(10 - prostitutes[p]->get_skill(SKILL_SEDUCTION), 0));
		prostitutes[p]->train(SKILL_STREETSENSE, max(10 - prostitutes[p]->get_skill(SKILL_STREETSENSE), 0));
		if (!LCSrandom(50)) // Police sting?
		{
			if (!(prostitutes[p]->skill_check(SKILL_STREETSENSE, DIFFICULTY_AVERAGE))) // Street sense to avoid
			{
				if (clearformess) eraseAlt();
				else makedelimiter();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8, 1, prostitutes[p]->name, gamelog);
				addstrAlt(CONST_activities101, gamelog);
				gamelog.nextMessage();
				addjuice(*prostitutes[p], -7, -30);
				pressAnyKey();
				caught = 1;
				removesquadinfo(*prostitutes[p]);
				prostitutes[p]->carid = -1;
				prostitutes[p]->location = find_site_index_in_same_city(SITE_GOVERNMENT_POLICESTATION, prostitutes[p]->location);
				prostitutes[p]->drop_weapons_and_clips(NULL);
				prostitutes[p]->activity.type = ACTIVITY_NONE;
				criminalize(*prostitutes[p], LAWFLAG_PROSTITUTION);
			}
			else
			{
				if (clearformess) eraseAlt();
				else makedelimiter();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8, 1, prostitutes[p]->name, gamelog);
				addstrAlt(CONST_activities102, gamelog);
				gamelog.nextMessage();
				addjuice(*prostitutes[p], 5, 0);
				pressAnyKey();
			}
		}
		if (!caught)
		{
			prostitutes[p]->train(SKILL_STREETSENSE, max(5 - prostitutes[p]->get_skill(SKILL_STREETSENSE), 0));
			ledger.add_funds(fundgain, INCOME_PROSTITUTION);
			prostitutes[p]->income = fundgain;
		}
	}
}
void doActivityLearn(vector<DeprecatedCreature *> &students, char &clearformess)
{
	const string CONST_activities104 = " can.";
	const string CONST_activities103 = " has learned as much as ";
	extern Log gamelog;
	extern class Ledger ledger;
	for (int s = len(students) - 1; s >= 0; s--)
	{
		if (ledger.get_funds() < 60) break;
		ledger.subtract_funds(60, EXPENSE_TRAINING);
		int skill[2] = { -1, -1 };
		int effectiveness[2] = { 20, 20 };
		skill[0] = trainingActivity[(Activity)(students[s]->activity.type)];
		bool worthcontinuing = false;
		for (int i = 0; i < 2; i++)
			if (skill[i] != -1)
			{  // rapid decrease in effectiveness as your skill gets higher.
				effectiveness[i] /= (students[s]->get_skill(skill[i]) + 1);
				if (effectiveness[i] < 1)
					effectiveness[i] = 1;
				students[s]->train(skill[i], effectiveness[i]);
				if (students[s]->get_skill(skill[i]) < students[s]->skill_cap(skill[i]))
					worthcontinuing = true;
			}
		if (!worthcontinuing)
		{
			students[s]->activity.type = ACTIVITY_NONE;
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 1, students[s]->name, gamelog);
			addstrAlt(CONST_activities103, gamelog);
			addstrAlt(students[s]->heshe(), gamelog);
			addstrAlt(CONST_activities104, gamelog);
			gamelog.nextMessage();
			pressAnyKey();
		}
	}
}
void finishTrouble(short &crime, long &juiceval, const int mod, const vector<DeprecatedCreature *> trouble) {
	const string CONST_activities117 = "set up a mock sweatshop in the middle of the mall!";
	const string CONST_activities116 = "burned a corporate symbol and denounced capitalism!";
	const string CONST_activities115 = "distributed fliers graphically illustrating CIA torture!";
	const string CONST_activities114 = "distributed fliers graphically illustrating executions!";
	const string CONST_activities113 = "squirted business people with fake polluted water!";
	const string CONST_activities112 = "dressed up and pretended to be a radioactive mutant!";
	const string CONST_activities111 = "dressed up and pretended to be radioactive mutants!";
	const string CONST_activities110 = "gone downtown and reenacted a police beating!";
	const string CONST_activities109 = "posted horrifying dead abortion doctor pictures downtown!";
	const string CONST_activities108 = "disrupted a traditional wedding at a church!";
	const string CONST_activities107 = "run around uptown splashing paint on fur coats!";
	extern Log gamelog;
	extern Deprecatednewsstoryst *sitestory;
	extern short public_interest[VIEWNUM];
	extern short lawList[LAWNUM];
	extern short background_liberal_influence[VIEWNUM];
	extern vector<Deprecatednewsstoryst *> newsstory;
	char done = 0;
	do
	{
		switch (LCSrandom(10))
		{
		case 0:
			addstrAlt(CONST_activities107, gamelog);
			juiceval = 2;
			crime = LAWFLAG_ASSAULT;
			change_public_opinion(VIEW_LIBERALCRIMESQUAD, mod);
			change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, mod >> 1, 0, 70);
			public_interest[VIEW_ANIMALRESEARCH] += mod;
			background_liberal_influence[VIEW_ANIMALRESEARCH] += mod;
			done = 1;
			break;
		case 1:
		{
			if (lawList[LAW_GAY] < 2)
			{
				addstrAlt(CONST_activities108, gamelog);
				change_public_opinion(VIEW_LIBERALCRIMESQUAD, mod);
				change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, mod, 0, 70);
				public_interest[VIEW_GAY] += mod;
				background_liberal_influence[VIEW_GAY] += mod;
				juiceval = 2;
				crime = LAWFLAG_DISTURBANCE;
				done = 1;
			}
			break;
		}
		case 2:
		{
			if (lawList[LAW_ABORTION] < 2)
			{
				addstrAlt(CONST_activities109, gamelog);
				change_public_opinion(VIEW_LIBERALCRIMESQUAD, mod);
				change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, mod, 0, 70);
				public_interest[VIEW_WOMEN] += mod;
				background_liberal_influence[VIEW_WOMEN] += mod;
				juiceval = 1;
				done = 1;
			}
			break;
		}
		case 3:
		{
			if (lawList[LAW_POLICEBEHAVIOR] < 2)
			{
				addstrAlt(CONST_activities110, gamelog);
				change_public_opinion(VIEW_LIBERALCRIMESQUAD, mod);
				change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, mod, 0, 70);
				public_interest[VIEW_POLICEBEHAVIOR] += mod;
				background_liberal_influence[VIEW_POLICEBEHAVIOR] += mod;
				juiceval = 2;
				crime = LAWFLAG_DISTURBANCE;
				done = 1;
			}
			break;
		}
		case 4:
		{
			if (lawList[LAW_NUCLEARPOWER] < 2)
			{
				if (len(trouble) > 1)addstrAlt(CONST_activities111, gamelog);
				else addstrAlt(CONST_activities112, gamelog);
				change_public_opinion(VIEW_LIBERALCRIMESQUAD, mod);
				change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, mod, 0, 70);
				public_interest[VIEW_NUCLEARPOWER] += mod;
				background_liberal_influence[VIEW_NUCLEARPOWER] += mod;
				juiceval = 2;
				crime = LAWFLAG_DISTURBANCE;
				done = 1;
			}
			break;
		}
		case 5:
		{
			if (lawList[LAW_POLLUTION] < 2)
			{
				addstrAlt(CONST_activities113, gamelog);
				change_public_opinion(VIEW_LIBERALCRIMESQUAD, mod);
				change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, mod, 0, 70);
				public_interest[VIEW_POLLUTION] += mod;
				background_liberal_influence[VIEW_POLLUTION] += mod;
				juiceval = 2;
				crime = LAWFLAG_DISTURBANCE;
				done = 1;
			}
			break;
		}
		case 6:
		{
			if (lawList[LAW_DEATHPENALTY] < 2)
			{
				addstrAlt(CONST_activities114, gamelog);
				change_public_opinion(VIEW_LIBERALCRIMESQUAD, mod);
				change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, mod, 0, 70);
				public_interest[VIEW_DEATHPENALTY] += mod;
				background_liberal_influence[VIEW_DEATHPENALTY] += mod;
				juiceval = 1;
				done = 1;
			}
			break;
		}
		case 7:
		{
			addstrAlt(CONST_activities115, gamelog);
			change_public_opinion(VIEW_LIBERALCRIMESQUAD, mod);
			change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, mod, 0, 70);
			public_interest[VIEW_TORTURE] += mod;
			background_liberal_influence[VIEW_TORTURE] += mod;
			juiceval = 1;
			done = 1;
			break;
		}
		case 8:
		{
			addstrAlt(CONST_activities116, gamelog);
			change_public_opinion(VIEW_LIBERALCRIMESQUAD, mod);
			change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, mod, 0, 70);
			public_interest[VIEW_CORPORATECULTURE] += mod;
			background_liberal_influence[VIEW_CORPORATECULTURE] += mod;
			if (lawList[LAW_CORPORATE] == -2)
			{               // In extreme corporate culture cases this should give a flag burning charge! -- kviiri
				juiceval = 2;  // Done -- SlatersQuest
				crime = LAWFLAG_BURNFLAG;
			}
			else juiceval = 1;
			done = 1;
			break;
		}
		case 9:
		{
			addstrAlt(CONST_activities117, gamelog);
			change_public_opinion(VIEW_LIBERALCRIMESQUAD, mod);
			change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, mod, 0, 70);
			public_interest[VIEW_SWEATSHOPS] += mod;
			background_liberal_influence[VIEW_SWEATSHOPS] += mod;
			juiceval += 1;
			done = 1;
			break;
		}
		}
	} while (!done);
}
void doActivityTrouble(vector<DeprecatedCreature *> &trouble, char &clearformess)
{
	const string CONST_activities139 = "broken!";
	const string CONST_activities138 = "'s last unbroken rib is ";
	const string CONST_activities137 = "'s rib is ";
	const string CONST_activities136 = "One of ";
	const string CONST_activities135 = "'s ribs are ";
	const string CONST_activities134 = " of ";
	const string CONST_activities133 = "All ";
	const string CONST_activities132 = "'s tooth has been pulled out with pliers!";
	const string CONST_activities131 = "'s teeth have been smashed out on the curb.";
	const string CONST_activities130 = "'s neck has been broken!";
	const string CONST_activities129 = "'s upper spine has been broken!";
	const string CONST_activities128 = "'s lower spine has been broken!";
	const string CONST_activities127 = " is severely beaten before the mob is broken up.";
	const string CONST_activities126 = " out of everyone who got close!";
	const string CONST_activities125 = "shit";
	const string CONST_activities124 = "[tar]";
	const string CONST_activities123 = " beat the ";
	const string CONST_activities122 = "The mob scatters!";
	const string CONST_activities120 = " brandishes the ";
	const string CONST_activities119 = " is cornered by a mob of angry rednecks.";
	const string CONST_activities118 = "causing trouble";
	const string CONST_activities105 = "Your Activists have ";
	extern Log gamelog;
	extern Deprecatednewsstoryst *sitestory;
	extern short public_interest[VIEWNUM];
	extern short lawList[LAWNUM];
	extern short background_liberal_influence[VIEWNUM];
	extern vector<Deprecatednewsstoryst *> newsstory;
	if (len(trouble))
	{
		long juiceval = 0;
		short crime = 0;
		if (clearformess) eraseAlt();
		else makedelimiter();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(8, 1);
		if (len(trouble) > 1) addstrAlt(CONST_activities105, gamelog);
		else { addstrAlt(trouble[0]->name, gamelog); addstrAlt(CONST_activities106, gamelog); }
		int power = 0;
		for (int t = 0; t < len(trouble); t++)
			power += trouble[t]->skill_roll(SKILL_PERSUASION) +
			trouble[t]->skill_roll(SKILL_STREETSENSE);
		int mod = 1;
		if (LCSrandom(10) < power) mod++;
		if (LCSrandom(20) < power) mod++;
		if (LCSrandom(40) < power) mod++;
		if (LCSrandom(60) < power) mod++;
		if (LCSrandom(80) < power) mod++;
		if (LCSrandom(100) < power) mod++;

		finishTrouble(crime, juiceval, mod, trouble);

		gamelog.nextMessage(); //Do this now so that it doesn't have to be done in every case up there.
		pressAnyKey();
		if (crime != 0)
		{
			for (int t = 0; t < len(trouble); t++)
			{
				if (!LCSrandom(30) &&
					!(trouble[t]->skill_check(SKILL_STREETSENSE, DIFFICULTY_AVERAGE)))
				{
					if (clearformess) eraseAlt();
					else makedelimiter();
					if (!LCSrandom(4))
					{
						Deprecatednewsstoryst *ns = new Deprecatednewsstoryst;
						ns->type = NEWSSTORY_WANTEDARREST; // should probably create a NEWSSTORY_TROUBLEARREST and implement it fully
						ns->loc = -1;                      // but this will have to do for now
						ns->positive = 0;
						newsstory.push_back(ns);
						sitestory = ns;
						attemptarrest(*trouble[t], CONST_activities118.c_str(), clearformess);
					}
					else
					{
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(8, 1, trouble[t]->name, gamelog);
						addstrAlt(CONST_activities119, gamelog);
						gamelog.nextMessage();
						pressAnyKey();
						bool wonfight = false;
						if (trouble[t]->get_weapon().get_specific_bool(BOOL_THREATENING_))
						{
							if (clearformess) eraseAlt();
							else makedelimiter();
							set_color_easy(WHITE_ON_BLACK_BRIGHT);
							mvaddstrAlt(8, 1, trouble[t]->name, gamelog);
							addstrAlt(CONST_activities120, gamelog);
							addstrAlt(trouble[t]->get_weapon().get_name(), gamelog);
							addstrAlt(CONST_activities121, gamelog);
							gamelog.nextMessage();
							pressAnyKey();
							if (clearformess) eraseAlt();
							else makedelimiter();
							set_color_easy(WHITE_ON_BLACK_BRIGHT);
							mvaddstrAlt(8, 1, CONST_activities122, gamelog);
							gamelog.nextMessage();
							pressAnyKey();
							addjuice(*trouble[t], 5, 20);
							wonfight = true;
						}
						else
						{
							for (int count = 0; count <= LCSrandom(5) + 2; count++)
							{
								if (clearformess) eraseAlt();
								else makedelimiter();
								if (trouble[t]->skill_roll(SKILL_HANDTOHAND) > LCSrandom(6) + count)
								{
									set_color_easy(CYAN_ON_BLACK_BRIGHT);
									mvaddstrAlt(8, 1, trouble[t]->name, gamelog);
									addstrAlt(singleSpace, gamelog);
									addstrAlt(pickrandom(win_hand_to_hand), gamelog);
									gamelog.nextMessage();
									pressAnyKey();
									wonfight = true;
								}
								else
								{
									set_color_easy(YELLOW_ON_BLACK_BRIGHT);
									mvaddstrAlt(8, 1, trouble[t]->name, gamelog);
									addstrAlt(singleSpace, gamelog);
									addstrAlt(pickrandom(lose_hand_to_hand), gamelog);
									gamelog.nextMessage();
									pressAnyKey();
									count++; // fight goes faster when you're losing
									wonfight = false;
								}
							}
							if (wonfight)
							{
								if (clearformess) eraseAlt();
								else makedelimiter();
								set_color_easy(GREEN_ON_BLACK_BRIGHT);
								mvaddstrAlt(8, 1, trouble[t]->name, gamelog);
								addstrAlt(CONST_activities123, gamelog);
								if (lawList[LAW_FREESPEECH] == -2)
									addstrAlt(CONST_activities124, gamelog);
								else addstrAlt(CONST_activities125, gamelog);
								addstrAlt(CONST_activities126, gamelog);
								gamelog.nextMessage();
								pressAnyKey();
								addjuice(*trouble[t], 30, 300);
								if (trouble[t]->blood > 70)trouble[t]->blood = 70;
							}
						}
						if (!wonfight)
						{
							if (clearformess) eraseAlt();
							else makedelimiter();
							set_color_easy(RED_ON_BLACK_BRIGHT);
							mvaddstrAlt(8, 1, trouble[t]->name, gamelog);
							addstrAlt(CONST_activities127, gamelog);
							gamelog.nextMessage();
							trouble[t]->activity.type = ACTIVITY_CLINIC;
							pressAnyKey();
							addjuice(*trouble[t], -10, -50);
							if (trouble[t]->blood > 10)trouble[t]->blood = 10;
							if (!LCSrandom(5))
							{
								if (clearformess) eraseAlt();
								else makedelimiter();
								switch (LCSrandom(10))
								{
								case 0:
									if (trouble[t]->special[SPECIALWOUND_LOWERSPINE] == 1)
									{
										mvaddstrAlt(8, 1, trouble[t]->name, gamelog);
										addstrAlt(CONST_activities128, gamelog);
										gamelog.nextMessage();
										trouble[t]->special[SPECIALWOUND_LOWERSPINE] = 0;
										pressAnyKey();
									}
									break;
								case 1:
									if (trouble[t]->special[SPECIALWOUND_UPPERSPINE] == 1)
									{
										mvaddstrAlt(8, 1, trouble[t]->name, gamelog);
										addstrAlt(CONST_activities129, gamelog);
										gamelog.nextMessage();
										trouble[t]->special[SPECIALWOUND_UPPERSPINE] = 0;
										pressAnyKey();
									}
									break;
								case 2:
									if (trouble[t]->special[SPECIALWOUND_NECK] == 1)
									{
										mvaddstrAlt(8, 1, trouble[t]->name, gamelog);
										addstrAlt(CONST_activities130, gamelog);
										gamelog.nextMessage();
										trouble[t]->special[SPECIALWOUND_NECK] = 0;
										pressAnyKey();
									}
									break;
								case 3:
									if (trouble[t]->special[SPECIALWOUND_TEETH] > 0)
									{
										mvaddstrAlt(8, 1, trouble[t]->name);
										if (trouble[t]->special[SPECIALWOUND_TEETH] > 1)addstrAlt(CONST_activities131, gamelog);
										else addstrAlt(CONST_activities132, gamelog);
										gamelog.nextMessage();
										trouble[t]->special[SPECIALWOUND_TEETH] = 0;
										pressAnyKey();
									}
									break;
								default:
								{
									if (trouble[t]->special[SPECIALWOUND_RIBS] > 0)
									{
										int ribminus = LCSrandom(RIBNUM) + 1;
										if (ribminus > trouble[t]->special[SPECIALWOUND_RIBS])ribminus = trouble[t]->special[SPECIALWOUND_RIBS];
										moveAlt(8, 1);
										if (ribminus > 1)
										{
											if (ribminus == trouble[t]->special[SPECIALWOUND_RIBS])
												addstrAlt(CONST_activities133, gamelog);
											addstrAlt(ribminus, gamelog);
											addstrAlt(CONST_activities134, gamelog);
											addstrAlt(trouble[t]->name, gamelog);
											addstrAlt(CONST_activities135, gamelog);
										}
										else if (trouble[t]->special[SPECIALWOUND_RIBS] > 1)
										{
											addstrAlt(CONST_activities136, gamelog);
											addstrAlt(trouble[t]->name, gamelog);
											addstrAlt(CONST_activities137, gamelog);
										}
										else
										{
											addstrAlt(trouble[t]->name);
											addstrAlt(CONST_activities138, gamelog);
										}
										addstrAlt(CONST_activities139, gamelog);
										gamelog.nextMessage();
										pressAnyKey();
										trouble[t]->special[SPECIALWOUND_RIBS] -= ribminus;
									}
									break;
								}
								}
							}
						}
					}
				}
			}
		}
		for (int h = 0; h < len(trouble); h++)
			addjuice(*trouble[h], juiceval, 40);
	}
}
void doActivityTeach(vector<DeprecatedCreature *> &teachers, char &clearformess)
{
	extern class Ledger ledger;
	extern vector<DeprecatedCreature *> pool;
	for (int t = 0; t < len(teachers); t++)
	{
		int skillarray[14];
		int cost = 0, students = 0;
		//Build a list of skills to train and determine the cost for running
		//a class depending on what the teacher is teaching
		switch (teachers[t]->activity.type)
		{
		case ACTIVITY_TEACH_POLITICS:
			cost = 2;
			skillarray[0] = SKILL_LAW;
			skillarray[1] = SKILL_PERSUASION;
			skillarray[2] = SKILL_WRITING;
			skillarray[3] = SKILL_RELIGION;
			skillarray[4] = SKILL_BUSINESS;
			skillarray[5] = SKILL_SCIENCE;
			skillarray[6] = SKILL_STREETSENSE;
			skillarray[7] = SKILL_MUSIC;
			skillarray[8] = SKILL_ART;
			skillarray[9] = -1;
			break;
		case ACTIVITY_TEACH_COVERT:
			cost = 6;
			skillarray[0] = SKILL_SECURITY;
			skillarray[1] = SKILL_COMPUTERS;
			skillarray[2] = SKILL_DISGUISE;
			skillarray[3] = SKILL_TAILORING;
			skillarray[4] = SKILL_STEALTH;
			skillarray[5] = SKILL_SEDUCTION;
			skillarray[6] = SKILL_PSYCHOLOGY;
			skillarray[7] = SKILL_DRIVING;
			skillarray[8] = -1;
			break;
		case ACTIVITY_TEACH_FIGHTING:
			cost = 10;
			skillarray[0] = SKILL_KNIFE;
			skillarray[1] = SKILL_SWORD;
			skillarray[2] = SKILL_CLUB;
			skillarray[3] = SKILL_PISTOL;
			skillarray[4] = SKILL_RIFLE;
			skillarray[5] = SKILL_SHOTGUN;
			skillarray[6] = SKILL_HEAVYWEAPONS;
			skillarray[7] = SKILL_AXE;
			skillarray[8] = SKILL_SMG;
			skillarray[9] = SKILL_THROWING;
			skillarray[10] = SKILL_HANDTOHAND;
			skillarray[11] = SKILL_DODGE;
			skillarray[12] = SKILL_FIRSTAID;
			skillarray[13] = -1;
			break;
		}
		//Count potential students for this teacher to get an idea of efficiency
		for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
		{
			//If they're at the location
			if (pool[p]->location == teachers[t]->location &&
				pool[p]->align == ALIGN_LIBERAL &&
				pool[p]->alive)
			{
				//Step through the array of skills to train
				for (int i = 0; i < 13; i++)           //Any reason why we aren't using a while(true) loop or something even more dynamic? --kviiri
				{
					//If no more skills to train, stop
					if (skillarray[i] == -1) break;
					//Otherwise, if the student has less skill than the teacher, train the student
					//proportional to the difference in skill between teacher and student times the
					//teacher's ability at teaching
					if (pool[p]->get_skill(skillarray[i]) < teachers[t]->get_skill(skillarray[i]) - 1 &&
						pool[p]->get_skill(skillarray[i]) < teachers[t]->get_skill(SKILL_TEACHING) + 2 &&
						pool[p]->get_skill(skillarray[i]) < pool[p]->skill_cap(skillarray[i]))
					{
						students++;
					}
				}
			}
		}
		//Check funds.
		if (ledger.get_funds() < min(students, 10)*cost)
			continue; //Can't afford to teach them. Continue with next teacher.
					  //Walk through and train people
		for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
		{
			//If they're at the location
			if (pool[p]->location == teachers[t]->location &&
				pool[p]->align == ALIGN_LIBERAL &&
				pool[p]->alive)
			{
				//Step through the array of skills to train
				for (int i = 0; i < 13; i++)
				{
					//If no more skills to train, stop
					if (skillarray[i] == -1)break;
					//Otherwise, if the student has less skill than the teacher, train the student
					//proportional to the difference in skill between teacher and student times the
					//teacher's ability at teaching
					if (pool[p]->get_skill(skillarray[i]) < teachers[t]->get_skill(skillarray[i]) - 1 &&
						pool[p]->get_skill(skillarray[i]) < teachers[t]->get_skill(SKILL_TEACHING) + 2 &&
						pool[p]->get_skill(skillarray[i]) < pool[p]->skill_cap(skillarray[i]))
					{
						// Teach based on teacher's skill in the topic plus skill in teaching, minus
						// student's skill in the topic
						int teach = teachers[t]->get_skill(skillarray[i]) +
							teachers[t]->get_skill(SKILL_TEACHING) -
							pool[p]->get_skill(skillarray[i]);
						//at ten students, cost no longer goes up, but effectiveness goes down.
						if (students > 10)
						{
							//teach = (teach * 10) / students; //teach at 50% speed with twice as many students.
							teach = ((teach * 30 / students) + teach) / 4; //62.5% speed with twice as many students.
						}
						if (teach < 1)
							teach = 1;
						// Cap at 10 points per day
						if (teach > 10)
							teach = 10;
						pool[p]->train(skillarray[i], teach);
						/*if(students<10)
						{
						students++;
						ledger.subtract_funds(cost,EXPENSE_TRAINING);
						if(students==10)cost=0;
						}*/
					}
				}
			}
		}
		ledger.subtract_funds(cost*min(students, 10), EXPENSE_TRAINING);
		teachers[t]->train(SKILL_TEACHING, min(students, 10));
	}
}
void lootTheBody(DeprecatedCreature &cr, int base);
void doActivityBury(vector<DeprecatedCreature *> &bury, char &clearformess)
{
	const string CONST_activities141 = "'s body";
	const string CONST_activities140 = "burying ";
	extern Deprecatednewsstoryst *sitestory;
	extern vector<DeprecatedCreature *> pool;
	extern vector<Deprecatednewsstoryst *> newsstory;
	if (len(bury))
	{
		for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
		{
			if (pool[p]->alive) continue;
			bool arrest_attempted = false;
			lootTheBody(*pool[p], bury[0]->base);

			for (int b = 0; b < len(bury); b++)
			{
				if (!arrest_attempted && !(bury[b]->skill_check(SKILL_STREETSENSE, DIFFICULTY_EASY)))
				{
					arrest_attempted = true; // Only attempt one burial arrest per body
					Deprecatednewsstoryst *ns = new Deprecatednewsstoryst;
					ns->type = NEWSSTORY_BURIALARREST;
					ns->loc = -1;
					newsstory.push_back(ns);
					sitestory = ns;
					criminalize(*bury[b], LAWFLAG_BURIAL);
					char str[100];
					strcpy(str, CONST_activities140.c_str());
					strcat(str, pool[p]->name);
					strcat(str, CONST_activities141.c_str());
					attemptarrest(*bury[b], str, clearformess);
					// If a liberal is spotted they should not do more burials.
					bury.erase(bury.begin() + b--);
					break;
				}
			}
			//BURY (even if interrupted)
			delete_and_remove(pool, p);
			if (!len(bury)) break; //Stop burials if none are left doing them.
		}
	}
}
int lenVehicleType();
int steal_difficultytofind(const int v);
string vehicleTypelongname(const int p);
bool carselect(DeprecatedCreature &cr, short &cartype)
{
	const string spaceDashSpace = " ";
	const string CONST_activities145 = "Press a Letter to select a Type of Car";
	const string CONST_activities144 = "ÄÄÄÄTYPEÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄDIFFICULTY TO FIND UNATTENDEDÄÄ";
	const string CONST_activities143 = " try to find and steal today?";
	const string CONST_activities142 = "What type of car will ";
	extern short interface_pgup;
	extern short interface_pgdn;
	cartype = -1;
	vector<int> cart;
	for (int a = 0; a < lenVehicleType(); a++)
		if (steal_difficultytofind(a) < 10) cart.push_back(a);
	int page = 0;
	while (true)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0, 0, CONST_activities142);
		addstrAlt(cr.name);
		addstrAlt(CONST_activities143);
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(1, 0, CONST_activities144);
		int y = 2;
		for (int p = page * 19; p < len(cart) && p < page * 19 + 19; p++)
		{
			set_color_easy(WHITE_ON_BLACK);
			moveAlt(y, 0);
			addcharAlt(y + 'A' - 2); addstrAlt(spaceDashSpace);
			addstrAlt(vehicleTypelongname(cart[p]));
			moveAlt(y++, 49);
			displayDifficulty(steal_difficultytofind(cart[p]));
		}
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(22, 0, CONST_activities145);
		mvaddstrAlt(23, 0, addpagestr());
		int c = getkeyAlt();
		//PAGE UP
		if ((c == interface_pgup || c == KEY_UP || c == KEY_LEFT) && page > 0) page--;
		//PAGE DOWN
		if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page + 1) * 19 < len(cart)) page++;
		if (c >= 'a'&&c <= 's')
		{
			int p = page * 19 + c - 'a';
			if (p < len(cart))
			{
				cartype = cart[p];
				return true;
			}
		}
		// Too easy to accidentally back out
		// Not a big problem if this page isn't skippable
		// (There's no immediate risk in picking a car)
		// - JDS
		//if(c=='x'||c==ENTER||c==ESC||c==SPACEBAR)break;
	}
	return false;
}

void observeAlarm(const bool sensealarm, const bool alarmon, const string name, const string carname) {
	extern Log gamelog;
	const string CONST_activities162 = " stands by the ";
	const string CONST_activities161 = "THIS IS THE VIPER!   STAND AWAY!";
	const string CONST_activities160 = "THE VIPER:   ";
	const string CONST_activities158 = "STAND AWAY FROM THE VEHICLE!   <BEEP!!> <BEEP!!>";
	const string CONST_activities183 = "<BEEP!!> <BEEP!!> <BEEP!!> <BEEP!!>";
	//const string CONST_activities182 = "REMOVE YOURSELF FROM THE VEHICLE!   <BEEP!!> <BEEP!!>";
	const string CONST_activities181 = ":   ";
	const string CONST_activities180 = "THE VIPER";
	if (alarmon)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(10, 0);
		if (sensealarm)addstrAlt(CONST_activities180);
		else addstrAlt(carname);
		addstrAlt(CONST_activities181);
		set_color_easy(RED_ON_BLACK_BRIGHT);
		if (sensealarm)addstrAlt(CONST_activities158);
		else addstrAlt(CONST_activities183);
	}
	else if (sensealarm)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(10, 0, CONST_activities160);
		set_color_easy(RED_ON_BLACK_BRIGHT);
		addstrAlt(CONST_activities161, gamelog);
		gamelog.nextMessage();
	}
	else
	{
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(10, 0, name, gamelog);
		addstrAlt(CONST_activities162, gamelog);
		addstrAlt(carname, gamelog);
		addstrAlt(singleDot, gamelog);
		gamelog.nextMessage();
	}
}
string wasUnableToFind(const string old);
string considerLeaving(const bool sensealarm, const bool alarmon, const string name);

const string CONST_activities164 = "B - Break the window.";
const string CONST_activities163 = "A - Pick the lock.";
const string CONST_activities175 = " but it is still somewhat intact.";
const string CONST_activities174 = " with a ";
const string CONST_activities173 = " cracks the window";
const string CONST_activities171 = " smashes the window";
const string CONST_activities170 = " fiddles with the lock with no luck.";
const string CONST_activities176 = "An alarm suddenly starts blaring!";
const string CONST_activities169 = " jimmies the car door open.";
const string CONST_activities202 = " has been spotted by a passerby!";

const string CONST_activities178 = "Adventures in Liberal Car Theft";

bool enterCar(DeprecatedCreature &cr, const bool sensealarm, bool &alarmon, string carname, const bool touchalarm, char &windowdamage) {
	extern Log gamelog;
	extern vector<Deprecatednewsstoryst *> newsstory;
	extern Deprecatednewsstoryst *sitestory;
	extern chaseseqst chaseseq;
	extern short mode;
	extern short fieldskillrate;

	for (bool entered = false; !entered;)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0, 0, CONST_activities178);
		printcreatureinfo(&cr);
		makedelimiter();

		observeAlarm(sensealarm != 0, alarmon, cr.name, carname);

		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(12, 0, CONST_activities163);
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(13, 0, CONST_activities164);
		moveAlt(14, 0);

		addstrAlt(considerLeaving(sensealarm, alarmon, cr.name));

		char method = -1;
		while (method == -1)
		{
			int c = getkeyAlt();
			if (c == 'a')method = 0;
			if (c == 'b')method = 1;
			if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) { return false; } /* try again tomorrow */
		}
		//PICK LOCK
		if (method == 0)
		{
			if (cr.skill_check(SKILL_SECURITY, DIFFICULTY_AVERAGE))
			{
				switch (fieldskillrate)
				{
				case FIELDSKILLRATE_FAST:
					cr.train(SKILL_SECURITY, 25); break;
				case FIELDSKILLRATE_CLASSIC:
					cr.train(SKILL_SECURITY, max(5 - cr.get_skill(SKILL_SECURITY), 0)); break;
				case FIELDSKILLRATE_HARD:
					cr.train(SKILL_SECURITY, 0); break;
				}
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 0, cr.name, gamelog);
				addstrAlt(CONST_activities169, gamelog);
				gamelog.nextMessage();
				pressAnyKey();
				entered = true;
			}
			else
			{
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 0, cr.name, gamelog);
				addstrAlt(CONST_activities170, gamelog);
				gamelog.nextMessage();
				pressAnyKey();
			}
		}
		//BREAK WINDOW
		if (method == 1)
		{
			int difficulty = static_cast<int>(DIFFICULTY_EASY / cr.get_weapon().get_bashstrengthmod()) - windowdamage;
			if (cr.attribute_check(ATTRIBUTE_STRENGTH, difficulty))
			{
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 0, cr.name, gamelog);
				addstrAlt(CONST_activities171, gamelog);
				if (cr.get_weapon().get_bashstrengthmod() > 1)
				{
					addstrAlt(CONST_activities174, gamelog);
					addstrAlt(cr.get_weapon().get_name(2), gamelog);
				}
				addstrAlt(singleDot, gamelog);
				gamelog.nextMessage();
				windowdamage = 10;
				pressAnyKey();
				entered = true;
			}
			else
			{
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 0, cr.name, gamelog);
				addstrAlt(CONST_activities173, gamelog);
				if (cr.get_weapon().get_bashstrengthmod() > 1)
				{
					addstrAlt(CONST_activities174, gamelog);
					addstrAlt(cr.get_weapon().get_name(2), gamelog);
				}
				addstrAlt(CONST_activities175, gamelog);
				gamelog.nextMessage();
				windowdamage++;
				pressAnyKey();
			}
		}
		//ALARM CHECK
		int y = 17;
		if (touchalarm || sensealarm)
		{
			if (!alarmon)
			{
				set_color_easy(YELLOW_ON_BLACK_BRIGHT);
				mvaddstrAlt(y++, 0, CONST_activities176, gamelog);
				gamelog.nextMessage();
				pressAnyKey();
				alarmon = true;
			}
		}
		//NOTICE CHECK
		if (!LCSrandom(50) || (!LCSrandom(5) && alarmon))
		{
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(y++, 0, cr.name, gamelog);
			addstrAlt(CONST_activities202, gamelog);
			gamelog.nextMessage();
			pressAnyKey();
			//FOOT CHASE
			chaseseq.clean();
			chaseseq.location = LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONPARENT,cr.location);
			Deprecatednewsstoryst *ns = new Deprecatednewsstoryst;
			ns->type = NEWSSTORY_CARTHEFT;
			newsstory.push_back(ns);
			sitestory = ns;
			makechasers(-1, 5);
			if (footchase(cr)) {
				mode = GAMEMODE_BASE;
				return false;
			} // Switched to return false; this will cause you to try again tomorrow
			else {
				mode = GAMEMODE_BASE;
				return false;
			}
		}
	}
	return true;
}

enum CarHotwireMethod {
	UNDETERMINED,
	ATTEMPT_HOTWIRE,
	USE_KEYS
};
const string CONST_activities201 = "If they were here, I'd have found them by now.";
const string CONST_activities200 = "I don't think they're in here...";
const string CONST_activities199 = "Are they even in here?";
const string CONST_activities198 = ": <rummaging> ";
const string CONST_activities197 = " found the keys ";
const string CONST_activities196 = "Holy shit!  ";
const string CONST_activities195 = "Holy [Car Keys]!  ";
const string CONST_activities194 = "under the back seat!";
const string CONST_activities193 = "under the front seat!";
const string CONST_activities192 = "in the glove compartment!";
const string CONST_activities191 = "above the pull-down sunblock thingy!";
const string CONST_activities190 = "in the ignition.  Damn.";
const string CONST_activities189 = "in SPACE. With ALIENS. Seriously.";
bool attempt_find_keys(const bool keys_in_car, const int key_location, const int key_search_total, int& y, DeprecatedCreature &cr) {
	extern Log gamelog;

	extern short lawList[LAWNUM];
	bool started = false;
	int difficulty;
	string location;
	if (!keys_in_car)
	{
		difficulty = DIFFICULTY_IMPOSSIBLE;
		location = CONST_activities189;
	}
	else switch (key_location)
	{
	case 0:
	default:
		difficulty = DIFFICULTY_AUTOMATIC;
		location = CONST_activities190;
		break;
	case 1:
		difficulty = DIFFICULTY_EASY;
		location = CONST_activities191;
		break;
	case 2:
		difficulty = DIFFICULTY_EASY;
		location = CONST_activities192;
		break;
	case 3:
		difficulty = DIFFICULTY_AVERAGE;
		location = CONST_activities193;
		break;
	case 4:
		difficulty = DIFFICULTY_HARD;
		location = CONST_activities194;
		break;
	}
	if (cr.attribute_check(ATTRIBUTE_INTELLIGENCE, difficulty))
	{
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		moveAlt(y++, 0);
		if (lawList[LAW_FREESPEECH] == -2)addstrAlt(CONST_activities195, gamelog); // Holy car keys Batman!
		else addstrAlt(CONST_activities196, gamelog);
		addstrAlt(cr.name, gamelog);
		addstrAlt(CONST_activities197, gamelog);
		addstrAlt(location, gamelog);
		started = true;
	}
	else
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(y++, 0, cr.name, gamelog);
		addstrAlt(CONST_activities198, gamelog);
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		if (key_search_total == 5)
			addstrAlt(CONST_activities199, gamelog);
		else if (key_search_total == 10)
			addstrAlt(CONST_activities200, gamelog);
		else if (key_search_total == 15)
			addstrAlt(CONST_activities201, gamelog);
		else if (key_search_total > 15)
		{
			addstrAlt(pickrandom(car_wont_start), gamelog);
		}
		else
		{
			if (lawList[LAW_FREESPEECH] == -2) {
				addstrAlt(pickrandom(cant_find_keys_no_free_speech));
			}
			else {
				addstrAlt(pickrandom(cant_find_keys));
			}
		}
	}
	return started;
}
//const string CONST_activities202 = " has been spotted by a passerby!";

//const string CONST_activities178 = "Adventures in Liberal Car Theft";
const string CONST_activities188 = " hotwires the car!";
const string CONST_activities187 = "Enter - The Viper has finally deterred ";
const string CONST_activities186 = "Enter - Call it a day.";
const string CONST_activities185 = "B - Desperately search for keys.";
const string CONST_activities184 = "A - Hotwire the car.";


const string CONST_activities183 = "<BEEP!!> <BEEP!!> <BEEP!!> <BEEP!!>";
const string CONST_activities182 = "REMOVE YOURSELF FROM THE VEHICLE!   <BEEP!!> <BEEP!!>";
const string CONST_activities181 = ":   ";
const string CONST_activities180 = "THE VIPER";


const string CONST_activities179 = " is behind the wheel of a ";
bool startCar(DeprecatedCreature &cr, const string carname, const bool alarmon, const bool sensealarm) {
	extern Log gamelog;

	char keys_in_car = LCSrandom(5) > 0, key_search_total = 0;
	int key_location = LCSrandom(5), nervous_counter = 0;





	extern vector<Deprecatednewsstoryst *> newsstory;
	extern Deprecatednewsstoryst *sitestory;
	extern chaseseqst chaseseq;
	extern short mode;
	extern short fieldskillrate;
	extern short lawList[LAWNUM];
	bool started = false;
	while (!started)
	{
		nervous_counter++;
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0, 0, CONST_activities178);
		printcreatureinfo(&cr);
		makedelimiter();
		int y = 10;
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(y++, 0, cr.name, gamelog);
		addstrAlt(CONST_activities179, gamelog);
		addstrAlt(carname, gamelog);
		addstrAlt(singleDot, gamelog);
		gamelog.nextMessage();
		if (alarmon)
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			moveAlt(y++, 0);
			if (sensealarm)addstrAlt(CONST_activities180);
			else addstrAlt(carname);
			addstrAlt(CONST_activities181);
			set_color_easy(RED_ON_BLACK_BRIGHT);
			if (sensealarm)addstrAlt(CONST_activities182);
			else addstrAlt(CONST_activities183);
		}
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt((++y)++, 0, CONST_activities184);
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(y++, 0, CONST_activities185);
		moveAlt(y++, 0);
		if (!sensealarm)addstrAlt(CONST_activities186);
		else { addstrAlt(CONST_activities187); addstrAlt(cr.name); addstrAlt(singleDot); }
		y++;
		CarHotwireMethod method = UNDETERMINED;
		while (method == UNDETERMINED)
		{
			int c = getkeyAlt();
			if (c == 'a') method = ATTEMPT_HOTWIRE;
			if (c == 'b') method = USE_KEYS;
			if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) { return false; } // Call it a day and try again tomorrow
		}
		//HOTWIRE CAR
		if (method == ATTEMPT_HOTWIRE)
		{
			if (cr.skill_check(SKILL_SECURITY, DIFFICULTY_CHALLENGING))
			{
				switch (fieldskillrate)
				{
				case FIELDSKILLRATE_FAST:
					cr.train(SKILL_SECURITY, 50); break;
				case FIELDSKILLRATE_CLASSIC:
					cr.train(SKILL_SECURITY, max(10 - cr.get_skill(SKILL_SECURITY), 0)); break;
				case FIELDSKILLRATE_HARD:
					cr.train(SKILL_SECURITY, 0); break;
				}
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(y++, 0, cr.name, gamelog);
				addstrAlt(CONST_activities188, gamelog);
				gamelog.nextMessage();
				pressAnyKey();
				started = true;
			}
			else
			{
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(y++, 0, cr.name, gamelog);
				int flavor_text;
				if (cr.get_skill(SKILL_SECURITY) < 4)
					addstrAlt(pickrandom(cant_hotwire_car));
				else {
					if (LCSrandom(cant_hotwire_car.size() + almost_hotwire_car.size()) >= cant_hotwire_car.size()) {
						addstrAlt(pickrandom(almost_hotwire_car));
					}
					else {
						addstrAlt(pickrandom(cant_hotwire_car));
					}
				}
				gamelog.nextMessage();
				pressAnyKey();
			}
		}
		else
			//KEYS
			if (method == USE_KEYS)
			{
				started = attempt_find_keys(keys_in_car, key_location, key_search_total, y, cr);
				if (!started) {
					key_search_total++;
				}
				gamelog.nextMessage();
				pressAnyKey();
			}
			else {
				// ERROR
				// currently no other method
			}
			//NOTICE CHECK
			if (!started && (!LCSrandom(50) || (!LCSrandom(5) && alarmon)))
			{
				set_color_easy(RED_ON_BLACK_BRIGHT);
				mvaddstrAlt(y++, 0, cr.name, gamelog);
				addstrAlt(CONST_activities202, gamelog);
				gamelog.nextMessage();
				pressAnyKey();
				//FOOT CHASE
				chaseseq.clean();
				chaseseq.location = LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONPARENT,cr.location);
				Deprecatednewsstoryst *ns = new Deprecatednewsstoryst;
				ns->type = NEWSSTORY_CARTHEFT;
				newsstory.push_back(ns);
				sitestory = ns;
				makechasers(-1, 5);
				if (footchase(cr)) {
					mode = GAMEMODE_BASE;
					return false;
				}
				else {
					mode = GAMEMODE_BASE;
					return false;
				}
			}
			// Nervous message check
			else if (!started && (LCSrandom(7) + 5) < nervous_counter)
			{
				nervous_counter = 0;
				moveAlt(++y, 0); y++;
				set_color_easy(YELLOW_ON_BLACK_BRIGHT);
				addstrAlt(cr.name, gamelog);
				addstrAlt(singleSpace, gamelog);
				addstrAlt(pickrandom(gets_nervous), gamelog);
				gamelog.nextMessage();
				pressAnyKey();
			}
	}
	return true;
}

Vehicle* getVehicleOfThisType(int cartype);
void newVehicle(Vehicle *startcar);
/* steal a car */
//const string CONST_activities186 = "Enter - Call it a day.";
//const string CONST_activities178 = "Adventures in Liberal Car Theft";
const string CONST_activities153 = "A - Approach the driver's side door.";
const string CONST_activities152 = " looks from a distance at an empty ";
const string CONST_activities150 = " found a ";
const string CONST_activities147 = " looks around for an accessible vehicle...";
bool stealcar(DeprecatedCreature &cr, char &clearformess)
{

	extern Log gamelog;
	extern MusicClass music;
	extern short mode;
	extern short interface_pgup;
	extern short interface_pgdn;
	extern Deprecatednewsstoryst *sitestory;
	extern chaseseqst chaseseq;
	extern short fieldskillrate;
	extern short lawList[LAWNUM];
	extern vector<Deprecatednewsstoryst *> newsstory;
	music.play(MUSIC_CARTHEFT);
	clearformess = 1;
	short cartype;
	if (carselect(cr, cartype))
	{
		int diff = steal_difficultytofind(cartype) * 2;
		Vehicle *v = NULL;
		int old = cartype;
		cr.train(SKILL_STREETSENSE, 5);
		//THEFT SEQUENCE
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0, 0, CONST_activities178, gamelog);
		gamelog.nextMessage();
		printcreatureinfo(&cr);
		makedelimiter();
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(10, 0, cr.name, gamelog);
		addstrAlt(CONST_activities147, gamelog);
		pressAnyKey();
		//ROUGH DAY
		if (!cr.skill_check(SKILL_STREETSENSE, diff))
			do cartype = LCSrandom(lenVehicleType());
		while (cartype == old || LCSrandom(10) < steal_difficultytofind(cartype));
		v = getVehicleOfThisType(cartype);
		string carname = v->fullname();
		mvaddstrAlt(11, 0, cr.name, gamelog);
		if (old != cartype)
		{
			addstrAlt(wasUnableToFind(vehicleTypelongname(old)), gamelog);
		}
		else addstrAlt(CONST_activities150, gamelog);
		addstrAlt(v->longname(), gamelog);
		addstrAlt(singleDot, gamelog);
		gamelog.nextMessage();
		pressAnyKey();
		//APPROACH?
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0, 0, CONST_activities178);
		printcreatureinfo(&cr);
		makedelimiter();
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(10, 0, cr.name, gamelog);
		addstrAlt(CONST_activities152, gamelog);
		addstrAlt(carname, gamelog);
		addstrAlt(singleDot, gamelog);
		gamelog.nextMessage();
		mvaddstrAlt(12, 0, CONST_activities153);
		mvaddstrAlt(13, 0, CONST_activities186);
		while (true)
		{
			int c = getkeyAlt();
			if (c == 'a')break;
			if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) { delete v; return false; }
		}
		//SECURITY?
		bool alarmon = false, sensealarm = LCSrandom(100) < v->sensealarmchance(),
			touchalarm = LCSrandom(100) < v->touchalarmchance();
		char windowdamage = 0;
		if (!enterCar(cr, sensealarm, alarmon, carname, touchalarm, windowdamage)) {
			delete v;
			return false;
		}
		//START CAR
		//char ignition_progress=0;
		if (!startCar(cr, carname, alarmon, sensealarm)) {
			delete v;
			return false;
		}
		//CHASE SEQUENCE
		//CAR IS OFFICIAL, THOUGH CAN BE DELETE BY chasesequence()
		addjuice(cr, v->steal_juice(), 100);
		newVehicle(v);
		v->add_heat(14 + v->steal_extraheat());
		v->set_location(cr.base);
		// Automatically assign this car to this driver, if no other one is present
		if (cr.pref_carid == -1)
		{
			cr.pref_carid = v->id();
			cr.pref_is_driver = true;
		}
		chaseseq.clean();
		chaseseq.location = LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONPARENT,cr.location);
		int chaselev = !LCSrandom(13 - windowdamage);
		if (chaselev > 0 || (v->vtypeidname() == tag_POLICECAR && LCSrandom(2))) //Identify police cruiser. Temporary solution? -XML
		{
			v->add_heat(10);
			chaselev = 1;
			Deprecatednewsstoryst *ns = new Deprecatednewsstoryst;
			ns->type = NEWSSTORY_CARTHEFT;
			newsstory.push_back(ns);
			sitestory = ns;
			makechasers(-1, chaselev);
			if (!chasesequence(cr, *v)) // Caught or killed in the chase. Do not need to delete vehicle.
				return 0;
		}
		return 1;
	}
	return 0;
}
/* get a wheelchair */
void getwheelchair(DeprecatedCreature &cr, char &clearformess)
{
	const string CONST_activities204 = " was unable to get a wheelchair.  Maybe tomorrow...";
	const string CONST_activities203 = " has procured a wheelchair.";
	extern Log gamelog;
	if (clearformess) eraseAlt();
	else makedelimiter();
	if (LCSrandom(2))
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8, 1, cr.name, gamelog);
		addstrAlt(CONST_activities203, gamelog);
		cr.flag |= CREATUREFLAG_WHEELCHAIR;
	}
	else
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8, 1, cr.name, gamelog);
		addstrAlt(CONST_activities204, gamelog);
	}
	gamelog.nextMessage();
	pressAnyKey();
}
