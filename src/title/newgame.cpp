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

#include "common/ledger.h"

#include "vehicle/vehicle.h"

#include "title/newgame.h"

#include "define_includes.h"
//for ALLOWSTALIN



#include "common/consolesupport.h"
// for void set_color(short,short,bool)

#include "log/log.h"
// for commondisplay.h
#include "common/commondisplay.h"
// for void printfunds(int,int,char*)

#include "common/stringconversion.h"
//for string attribute_enum_to_string(int)

#include "common/getnames.h"
// for cityname

#include "common/translateid.h"
// for  getarmortype

#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>


extern vector<Creature *> pool;
extern Log gamelog;
extern vector<Location *> location;
extern bool multipleCityMode;
extern MusicClass music;
extern int year;
extern char endgamestate;
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern string tag_ARMOR;


string theLCS;
string notASkill;
string notAnAttribute;

string vehicleSportsCar;

string aNewConEra;
string theYearIs;
string conservativePresident;
string endsSecondTerm;
string highSeventiesApprovePres;
string conMajorityHouse;
string senateConMajority;
string beginningOfNew;
string conEra;
string thePresident;
string hasAskedCongressBeQuick;
string rubberStampArchCon;
string theLeftSeems;
string powerlessToStop;
string inThisDarkTime;
string whatIsYourName;
string pressEnterToBeRealName;

string invalidTag;
string theDocSaid;
string aBoy;
string aGirl;
string intersex;
string myParents;
string insistedOtherwise;
string they;
string namedMe;

string error;

string theFounder;
string firstName;
string pressAtoReconsider;
string lastName;
string pressBtoBeReborn;
string sexIs;
string male;
string female;
string itsComplicated;
string pressCtoChangeSex;
string history;
string letMeChoose;
string letFateDecide;
string pressDtoToggle;
string city;
string pressEtoRelocate;
string pressAnyKey;
string allOptions;

string unSelected;
string isSelected;
string pressAnyOtherKey;

string notCreature;
string notValidMap;
string notSpecialWound;
string newGameAdvanced;
string a_classicMode;
string b_weDidntStartIt;
string c_nightmareMode;
string d_nationalLCS;
string e_marathonMode;
string f_stalinistMode;
string newGameYourAgenda;
string a_noComprimise;
string b_democrat;
string newGameFieldLearn;
string affectsTheseSkills;
string a_fastSkills;
string b_classic;
string c_hardMode;

extern string spaceDashSpace;

extern bool notermlimit;           //These determine if ELAs can take place --kviiri
extern bool nocourtpurge;
extern bool stalinmode;
extern short lawList[LAWNUM];
extern short house[HOUSENUM];
extern short senate[SENATENUM];
extern short court[COURTNUM];
extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
extern short wincondition;
extern short fieldskillrate;
extern vector<ArmorType *> armortype;
extern char lcityname[CITY_NAMELEN];
extern string singleSpace;
extern int day;
extern int month;
extern class Ledger ledger;
extern vector<ClipType *> cliptype;
extern vector<WeaponType *> weapontype;
extern vector<Vehicle *> vehicle;
extern string singleDot;
extern long cursquadid;
extern vector<squadst *> squad;
extern squadst *activesquad;
extern UniqueCreatures uniqueCreatures;
extern short attitude[VIEWNUM];
vector<string> founderQuestions;
typedef map<string, short> stringAndShort;
typedef map<short, string > shortAndString;
stringAndShort getSkillEnumFromString;
shortAndString enumToCreature;
stringAndShort getBaseEnumFromString;
stringAndShort getSpecialWoundEnumFromString;

bool getSetValue(const string s) {
	int j = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			j = i;
			break;
		}
	}
	return j > -1 && (s[j] == '-' || s[j] == '+');
}
int getMagnitudeFromString(const string s) {
	bool spaceUnfound = true;
	int j = 0;
	for (int i = s.size() - 2; i > 0 && spaceUnfound; i--) {
		if (s[i] == ' ') {
			spaceUnfound = false;
			j = i;
		}
	}
	if (spaceUnfound) {
		clearAlt();
		mvaddstrAlt(0,  0, error);
		mvaddstrAlt(1,  0, s);
		getkey();
	}
	return atoi(s.substr(j).data());
}
// IsaacG Brute force substring matching
// suboptimal, but very very easy to code.
short findSubstring(stringAndShort str, string s);
short findSubstring(stringAndShort str, string s) {
	for (int i = strlen(s.data()); i >= 0; i--) {
		for (int j = 0; j <= strlen(s.data() - i); j++) {
			if (str.count(s.substr(j, i))) {
				return str[s.substr(j, i)];
			}
		}
	}
	return -1;
}
int getSkillFromString(const string s) {
	int output = findSubstring(getSkillEnumFromString, s);
	if (output >= 0) {
		return output;
	}
	else {// ERROR
		addstrAlt(error);
		addstrAlt(s);
		addstrAlt(notASkill);
		getkey();
		return -1;
	}
}
 stringAndShort getAttributeEnumFromString;
int getAttributeFromString(const string s) {
	int output = findSubstring(getAttributeEnumFromString, s);
	if (output >= 0) {
		return output;
	}
	else {// ERROR
		addstrAlt(error);
		addstrAlt(s);
		addstrAlt(notAnAttribute);
		getkey();
		return -1;
	}
}
 stringAndShort getCreatureEnumFromString;
int getCreatureFromString(const string s) {
	int output = findSubstring(getCreatureEnumFromString, s);
	if (output >= 0) {
		return output;
	}
	else
	{// ERROR
		addstrAlt(error);
		addstrAlt(s);
		addstrAlt(notCreature);
		getkey();
		return -1;
	}
}
string enumToCreatureString(const int i) {
	if (enumToCreature.count(i)) {
		return enumToCreature[i];
	}
	else {
		return blankString;
	}
}
int getBaseFromString(const string s) {
	const string baseString = s.substr(5);
	int output = findSubstring(getBaseEnumFromString, baseString);
	if (output >= 0) {
		return output;
	}
	else {// ERROR
		addstrAlt(error);
		addstrAlt(s);
		addstrAlt(notValidMap);
		getkey();
		return -1;
	}
}
int getSpecialWoundFromString(const string s) {
	int output = findSubstring(getSpecialWoundEnumFromString, s);
	if (output >= 0) {
		return output;
	}
	else {// ERROR
		addstrAlt(error);
		addstrAlt(s);
		addstrAlt(notSpecialWound);
		getkey();
		return -1;
	}
}

/* select new game options */
void setup_newgame()
{
	//TODO IsaacG Get rid of these while(true) break; loops
	music.play(MUSIC_NEWGAME);
	bool classicmode = false;
	bool strongccs = false;
	bool nightmarelaws = false;
	multipleCityMode = false;
	stalinmode = false;
	clearAlt();
	while (true)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(4,  6, newGameAdvanced);
		set_color_easy(WHITE_ON_BLACK);
		{
			string isThisSelected;
			if (classicmode)
				isThisSelected = (isSelected);
			else isThisSelected = (unSelected);
			mvaddstrAlt(7, 0, isThisSelected);
			addstrAlt(a_classicMode);

			if (!classicmode)
				set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			if (strongccs)
				isThisSelected = (isSelected);
			else isThisSelected = (unSelected);
			mvaddstrAlt(9, 0, isThisSelected);
			addstrAlt(b_weDidntStartIt);

			set_color_easy(WHITE_ON_BLACK);
			if (nightmarelaws)
				isThisSelected = (isSelected);
			else isThisSelected = (unSelected);
			mvaddstrAlt(11, 0, isThisSelected);
			addstrAlt(c_nightmareMode);

			set_color_easy(WHITE_ON_BLACK);
			if (multipleCityMode)
				isThisSelected = (isSelected);
			else isThisSelected = (unSelected);
			mvaddstrAlt(13, 0, isThisSelected);
			addstrAlt(d_nationalLCS);

			if (nocourtpurge)
				isThisSelected = (isSelected);
			else isThisSelected = (unSelected);
			mvaddstrAlt(15, 0, isThisSelected);
			addstrAlt(e_marathonMode);

			int bottomRow;
			if (ALLOWSTALIN) {
				if (stalinmode)
					isThisSelected = (isSelected);
				else isThisSelected = (unSelected);
				mvaddstrAlt(17, 0, isThisSelected);
				addstrAlt(f_stalinistMode);
				bottomRow = 21;
			}
			else {// ALLOWSTALIN
				bottomRow = 19;
			}// ALLOWSTALIN
			mvaddstrAlt(bottomRow, 4, pressAnyOtherKey);
		}
		const int c = getkey();
		if (c == 'a')
		{
			classicmode = !classicmode;
			continue;
		}
		if (c == 'b')
		{
			strongccs = !strongccs;
			continue;
		}
		if (c == 'c')
		{
			nightmarelaws = !nightmarelaws;
			continue;
		}
		if (c == 'd')
		{
			multipleCityMode = !multipleCityMode;
			continue;
		}
		if (c == 'e')
		{
			nocourtpurge = !nocourtpurge;
			notermlimit = !notermlimit;
			continue;
		}
		if (ALLOWSTALIN) {
			if (c == 'f')
			{
				stalinmode = !stalinmode;
				continue;
			}
		}
		break;
	}
	if (nightmarelaws)
	{
		for (int l = 0; l < LAWNUM; l++)
			lawList[l] = ALIGN_ARCHCONSERVATIVE;
		for (int a = 0; a < VIEWNUM - 3; a++)
			attitude[a] = (LCSrandom(20));
		for (int s = 0; s < SENATENUM; s++)
		{
			if (s < 55) senate[s] = ALIGN_ARCHCONSERVATIVE;
			else if (s < 70) senate[s] = ALIGN_CONSERVATIVE;
			else if (s < 80) senate[s] = ALIGN_MODERATE;
			else if (s < 97) senate[s] = ALIGN_LIBERAL;
			else senate[s] = ALIGN_ELITELIBERAL;
		}
		for (int h = 0; h < HOUSENUM; h++)
		{
			if (h < 220) house[h] = ALIGN_ARCHCONSERVATIVE;
			else if (h < 350) house[h] = ALIGN_CONSERVATIVE;
			else if (h < 400) house[h] = ALIGN_MODERATE;
			else if (h < 425) house[h] = ALIGN_LIBERAL;
			else house[h] = ALIGN_ELITELIBERAL;
		}
		for (int c = 0; c < COURTNUM; c++)
		{
			if (c < 5) court[c] = ALIGN_ARCHCONSERVATIVE;
			else if (c < 7) court[c] = ALIGN_CONSERVATIVE;
			else if (c < 8) court[c] = ALIGN_MODERATE;
			else if (c < 8) court[c] = ALIGN_LIBERAL;
			else court[c] = ALIGN_ELITELIBERAL;
			do
			{
				if (court[c] == ALIGN_ARCHCONSERVATIVE)
					generate_name(courtname[c], GENDER_WHITEMALEPATRIARCH);
				else generate_name(courtname[c]);
			} while (len(courtname[c])>20);
		}
	}
	if (classicmode)
		endgamestate = ENDGAME_CCS_DEFEATED;
	else if (strongccs)
	{
		endgamestate = ENDGAME_CCS_ATTACKS;
		//attitude[VIEW_POLITICALVIOLENCE]=90;
	}
	clearAlt();
	while (true)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(4,  6, newGameYourAgenda);

		set_color_easy(WHITE_ON_BLACK);
		string isThisSelected;
		if (wincondition == WINCONDITION_ELITE)
			isThisSelected = (isSelected);
		else isThisSelected = (unSelected);
		mvaddstrAlt(7, 0, isThisSelected);
		addstrAlt(a_noComprimise);

		ColorSetup useThisColor;
		if (!classicmode)
			useThisColor = (WHITE_ON_BLACK);
		else useThisColor = (BLACK_ON_BLACK_BRIGHT);
		set_color_easy(useThisColor);
		if (wincondition == WINCONDITION_EASY)
			isThisSelected = (isSelected);
		else isThisSelected = (unSelected);
		mvaddstrAlt(9, 0, isThisSelected);
		addstrAlt(b_democrat);

		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(13,  4, pressAnyOtherKey);
		const int c = getkey();
		if (c == 'a')
		{
			wincondition = WINCONDITION_ELITE;
			continue;
		}
		if (c == 'b')
		{
			wincondition = WINCONDITION_EASY;
			continue;
		}
		break;
	}
	clearAlt();
	while (true)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(4,  6, newGameFieldLearn);
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(5,  6, affectsTheseSkills);
		string isThisSelected;

		if (fieldskillrate == FIELDSKILLRATE_FAST)
			isThisSelected = (isSelected);
		else isThisSelected = (unSelected);
		mvaddstrAlt(8, 0, isThisSelected);
		addstrAlt(a_fastSkills);

		if (fieldskillrate == FIELDSKILLRATE_CLASSIC)
			isThisSelected = (isSelected);
		else isThisSelected = (unSelected);
		mvaddstrAlt(10, 0, isThisSelected);
		addstrAlt(b_classic);

		if (fieldskillrate == FIELDSKILLRATE_HARD)
			isThisSelected = (isSelected);
		else isThisSelected = (unSelected);
		mvaddstrAlt(12, 0, isThisSelected);
		addstrAlt(c_hardMode);

		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(16,  4, pressAnyOtherKey);
		const int c = getkey();
		if (c == 'a')
		{
			fieldskillrate = FIELDSKILLRATE_FAST;
			continue;
		}
		if (c == 'b')
		{
			fieldskillrate = FIELDSKILLRATE_CLASSIC;
			continue;
		}
		if (c == 'c')
		{
			fieldskillrate = FIELDSKILLRATE_HARD;
			continue;
		}
		break;
	}
}
enum recruits
{
	RECRUITS_GANG,
	RECRUITS_NONE
};
enum Stat_Or_Attribute {
	SKILL,
	ATTRIBUTE,
	OTHER
};
enum Other_Influence {
	BIRTH_MONTH,
	BIRTH_DAY,
	BIRTH_YEAR,
	STARTING_MONTH,
	STARTING_DAY,
	STARTING_YEAR,
	GAY,
	DATING_LAWYER,
	DATING,
	HAS_MAPS,
	JUICE,
	SPORTS_CAR,
	ASSAULT_RIFLE,
	MONEY,
	BASE,
	CREATURE,
	ARMOR,
	RECRUITS
};
struct Impact {
	Stat_Or_Attribute type;
	int item_to_influcence;
	int magnitude;
	bool set_value;
};
struct Choice {
	string ANSWER;
	string ANSWER_2;
	vector<Impact> impact;
};
struct Question {
	string HEADER;
	string HEADER_2;
	string QUESTION;
	string QUESTION_2;
	vector<Choice> choices;
};
const int MAX_CHOICES = 10;

/* creates your founder */
void makecharacter()
{
	Creature *newcr = new Creature;
	newcr->align = ALIGN_LIBERAL;
	newcr->set_attribute(ATTRIBUTE_HEART, 0);
	newcr->set_attribute(ATTRIBUTE_WISDOM, 0);
	newcr->set_attribute(ATTRIBUTE_INTELLIGENCE, 0);
	newcr->set_attribute(ATTRIBUTE_AGILITY, 0);
	newcr->set_attribute(ATTRIBUTE_STRENGTH, 0);
	newcr->set_attribute(ATTRIBUTE_HEALTH, 0);
	newcr->set_attribute(ATTRIBUTE_CHARISMA, 0);
	if (BLIND) {
		newcr->special[SPECIALWOUND_RIGHTEYE] = 1;
		newcr->special[SPECIALWOUND_LEFTEYE] = 1;
	}
	if (SPINE) {
		newcr->special[SPECIALWOUND_UPPERSPINE] = 1;
		newcr->special[SPECIALWOUND_LOWERSPINE] = 1;
	}
	if (NOFACE) {
		newcr->special[SPECIALWOUND_TONGUE] = 1;
		newcr->special[SPECIALWOUND_RIGHTEYE] = 1;
		newcr->special[SPECIALWOUND_LEFTEYE] = 1;
		newcr->special[SPECIALWOUND_NOSE] = 1;
	}
	if (NOWALK) {
		newcr->special[SPECIALWOUND_UPPERSPINE] = 1;
		newcr->special[SPECIALWOUND_LOWERSPINE] = 1;
		newcr->special[SPECIALWOUND_NECK] = 1;
		newcr->wound[BODYPART_LEG_RIGHT] = 1;
		newcr->wound[BODYPART_LEG_LEFT] = 1;
	}
	if (INTERNAL) {
		newcr->special[SPECIALWOUND_RIGHTLUNG] = 1;
		newcr->special[SPECIALWOUND_LEFTLUNG] = 1;
		newcr->special[SPECIALWOUND_HEART] = 1;
		newcr->special[SPECIALWOUND_LIVER] = 1;
		newcr->special[SPECIALWOUND_STOMACH] = 1;
		newcr->special[SPECIALWOUND_LEFTKIDNEY] = 1;
		newcr->special[SPECIALWOUND_RIGHTKIDNEY] = 1;
		newcr->special[SPECIALWOUND_SPLEEN] = 1;
	}
	char first[3][80];
	char last[80];
	const bool is_male = LCSrandom(2); // whether or not starting gender is male
	char gender = newcr->gender_liberal = newcr->gender_conservative = (is_male ? GENDER_MALE : GENDER_FEMALE);
	do {
		firstname(first[0], GENDER_NEUTRAL);
		firstname(first[1], GENDER_MALE);
		firstname(first[2], GENDER_FEMALE);
		strcpy(last, lastname());
	} while (strcmp(first[0], last) == 0 && strcmp(first[1], last) == 0 && strcmp(first[2], last) == 0);
	{
		Armor a(*armortype[getarmortype(tag_ARMOR_CLOTHES)]);
		newcr->give_armor(a, NULL);
	}
	bool choices = true;
	while (true)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(4,  6, theFounder);
		mvaddstrAlt(7,  2, firstName);
		addstrAlt(first[(int)gender]);
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(7,  30, pressAtoReconsider);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(9,  2, lastName);
		addstrAlt(last);
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(9,  30, pressBtoBeReborn);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(11,  2, sexIs);
		if (newcr->gender_conservative == GENDER_MALE)
		{
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			addstrAlt(male);
		}
		else if (newcr->gender_conservative == GENDER_FEMALE)
		{
			set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
			addstrAlt(female);
		}
		else
		{
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			addstrAlt(itsComplicated);
		}
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(11,  30, pressCtoChangeSex);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(13,  2, history);
		if (choices)
		{
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			addstrAlt(letMeChoose);
		}
		else
		{
			set_color_easy(RED_ON_BLACK_BRIGHT);
			addstrAlt(letFateDecide);
		}
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(13,  30, pressDtoToggle);
		if (!multipleCityMode)
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(15,  2, city);
			addstrAlt(lcityname);
			set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(15,  30, pressEtoRelocate);
		}
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(19 - multipleCityMode * 2,  4, pressAnyKey);
		const int c = getkey();
		if (c == 'a')
		{
			do {
				firstname(first[(int)gender], newcr->gender_conservative);
			} while (strcmp(first[(int)gender], last) == 0);
			continue;
		}
		if (c == 'b')
		{
			do {
				strcpy(last, lastname());
			} while (strcmp(first[0], last) == 0 && strcmp(first[1], last) == 0 && strcmp(first[2], last) == 0);
			continue;
		}
		if (c == 'c')
		{
			if ((newcr->gender_conservative == GENDER_FEMALE && !is_male) ||
				(newcr->gender_conservative == GENDER_NEUTRAL && is_male))
				newcr->gender_conservative = GENDER_MALE;
			else if ((newcr->gender_conservative == GENDER_MALE && !is_male) ||
				(newcr->gender_conservative == GENDER_FEMALE && is_male))
				newcr->gender_conservative = GENDER_NEUTRAL;
			else
				newcr->gender_conservative = GENDER_FEMALE;
			gender = newcr->gender_liberal = newcr->gender_conservative;
			continue;
		}
		if (c == 'd')
		{
			choices = !choices;
			continue;
		}
		if (c == 'e' && !multipleCityMode)
		{
			strcpy(lcityname, cityname());
			continue;
		}
		break;
	}
	strcpy(newcr->propername, first[(int)gender]);
	strcat(newcr->propername, singleSpace);
	strcat(newcr->propername, last);
	int c;
	bool hasmaps = false;
	bool makelawyer = false;
	bool gaylawyer = false;
	Vehicle * startcar = NULL;
	char recruits = RECRUITS_NONE;
	char base = SITE_RESIDENTIAL_SHELTER;
	for (int sk = 0; sk < SKILLNUM; sk++)newcr->set_skill((sk), 0);
	bool assault_rifle = false;
	bool sports_car = false;
	
	vector<Question> allQuestions;
	bool firstQuestion = true;
	bool firstAnswer = true;
	Question currentQuestion;
	Choice currentChoice;
	string header = blankString;
	string header_2 = blankString;
	string answer = blankString;
	string answer_2 = blankString;
	int birth_year = 1984; // default birth year, month, and day in case left undefined
	int birth_month = 1;
	int birth_day = 1;
	//IsaacG This loop needs a rewrite
	for (int i = 0; i < founderQuestions.size(); i++) {
		const string first = founderQuestions[i];
		if (first.substr(0, 6) == tag_HEADER) {
			if (first.substr(6, 1) == singleSpace) {
				header = first.substr(7);
				header_2 = blankString;
			}
			else  if (first.substr(6, 2) == tag__2) {
				header_2 = first.substr(9);
			}
		}
		else if (first.substr(0, 6) == tag_ANSWER) {
			if (firstAnswer) {
				if (first.substr(6, 1) == singleSpace) {
					answer = first.substr(7);
					answer_2 = blankString;
					firstAnswer = false;
				}
				else  if (first.substr(6, 2) == tag__2) {
					answer_2 = first.substr(9);
				}
			}
			else {
				if (first.substr(6, 1) == singleSpace) {
					currentChoice.ANSWER = answer;
					currentChoice.ANSWER_2 = answer_2;
					if (currentQuestion.choices.size() < MAX_CHOICES - 1) {
						currentQuestion.choices.push_back(currentChoice);
					}
					currentChoice.impact.clear();
					answer = first.substr(7);
					answer_2 = blankString;
				}
				else  if (first.substr(6, 2) == tag__2) {
					answer_2 = first.substr(9);
				}
			}
		}
		else if (first.substr(0, 8) == tag_QUESTION) {
			if (!firstQuestion) {
				if (first.substr(8, 1) == singleSpace) {
					currentChoice.ANSWER = answer;
					currentChoice.ANSWER_2 = answer_2;
					currentQuestion.choices.push_back(currentChoice);
					allQuestions.push_back(currentQuestion);
					currentQuestion.choices.clear();
					currentChoice.impact.clear();
					currentChoice.ANSWER = blankString;
					currentChoice.ANSWER_2 = blankString;
					currentQuestion.HEADER = header;
					currentQuestion.HEADER_2 = header_2;
					currentQuestion.QUESTION = first.substr(9);
					currentQuestion.QUESTION_2 = blankString;
					firstAnswer = true;
				}
				else if (first.substr(8, 2) == tag__2) {
					currentQuestion.QUESTION_2 = first.substr(12);
				}
			}
			else {
				firstQuestion = false;
				firstAnswer = true;
				currentChoice.ANSWER = blankString;
				currentChoice.ANSWER_2 = blankString;
				currentQuestion.HEADER = header;
				currentQuestion.HEADER_2 = header_2;
				currentQuestion.QUESTION = first.substr(9);
				currentQuestion.QUESTION_2 = blankString;
			}
		}
		else {
			bool invalidTag = false;
			Impact currentImpact;
			if (first.substr(0, 6) == tag_SKILL_) {
				currentImpact.type = SKILL;
				currentImpact.item_to_influcence = getSkillFromString(founderQuestions[i]);
				currentImpact.set_value = getSetValue(founderQuestions[i]);
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
				if (currentImpact.item_to_influcence == -1) {
					invalidTag = true;
				}
			}
			else if (first.substr(0, 10) == tag_ATTRIBUTE_) {
				currentImpact.type = ATTRIBUTE;
				currentImpact.item_to_influcence = getAttributeFromString(founderQuestions[i]);
				currentImpact.set_value = getSetValue(founderQuestions[i]);
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
				if (currentImpact.item_to_influcence == -1) {
					invalidTag = true;
				}
			}
			else if (first.substr(0, 9) == tag_STARTING_) {
				currentImpact.type = OTHER;
				currentImpact.set_value = true;
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
				if (first.substr(9, 5) == tag_MONTH) {
					currentImpact.item_to_influcence = STARTING_MONTH;
				}
				else if (first.substr(9, 3) == tag_DAY) {
					currentImpact.item_to_influcence = STARTING_DAY;
				}
				else if (first.substr(9, 4) == tag_YEAR) {
					currentImpact.item_to_influcence = STARTING_YEAR;
				}
				else {
					invalidTag = true;
				}
			}
			else if (first.substr(0, 9) == tag_BIRTHDAY_) {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = 0;
				currentImpact.set_value = true;
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
				if (first.substr(9, 5) == tag_MONTH) {
					currentImpact.item_to_influcence = BIRTH_MONTH;
				}
				else if (first.substr(9, 3) == tag_DAY) {
					currentImpact.item_to_influcence = BIRTH_DAY;
				}
				else if (first.substr(9, 4) == tag_YEAR) {
					currentImpact.item_to_influcence = BIRTH_YEAR;
				}
				else {
					invalidTag = true;
				}
			}
			else if (first.substr(0, 5) == tag_MONEY) {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = MONEY;
				currentImpact.set_value = getSetValue(founderQuestions[i]);
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			}
			else if (first.substr(0, 13) == tag_DATING_LAWYER) {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = DATING_LAWYER;
				currentImpact.set_value = true;
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			}
			else if (first.substr(0, 3) == tag_GAY) {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = GAY;
				currentImpact.set_value = true;
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			}
			else if (first.substr(0, 7) == tag_HASMAPS) {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = HAS_MAPS;
				currentImpact.set_value = true;
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			}
			else if (first.substr(0, 8) == tag_CREATURE) {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = CREATURE;
				currentImpact.set_value = true;
				currentImpact.magnitude = getCreatureFromString(founderQuestions[i].substr(9));
			}
			else if (first.substr(0, 4) == tag_BASE) {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = BASE;
				currentImpact.set_value = true;
				currentImpact.magnitude = getBaseFromString(founderQuestions[i]);
				if (currentImpact.magnitude == -1) {
					invalidTag = true;
				}
			}
			else if (first.substr(0, 5) == tag_ARMOR) {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = ARMOR;
				currentImpact.set_value = true;
				invalidTag = true;
			}
			else if (first.substr(0, 5) == tag_JUICE) {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = JUICE;
				currentImpact.set_value = getSetValue(founderQuestions[i]);
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			}
			else if (first.substr(0, 13) == tag_RECRUITS_GANG) {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = RECRUITS;
				currentImpact.set_value = true;
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			}
			else if (first.substr(0, 13) == tag_ASSAULT_RIFLE) {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = ASSAULT_RIFLE;
				currentImpact.set_value = true;
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			}
			else if (first.substr(0, 10) == tag_SPORTS_CAR) {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = SPORTS_CAR;
				currentImpact.set_value = true;
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			}
			else {
				clearAlt();
				addstrAlt(invalidTag);
				addstrAlt(founderQuestions[i]);
				getkey();
				clearAlt();
			}
			if (invalidTag) {
				clearAlt();
				addstrAlt(invalidTag);
				addstrAlt(founderQuestions[i]);
				getkey();
				clearAlt();
			}
			else {
				currentChoice.impact.push_back(currentImpact);
			}
		}
	}
	// The last choice and question added after the loop ends
	currentChoice.ANSWER = answer;
	currentChoice.ANSWER_2 = answer_2;
	currentQuestion.choices.push_back(currentChoice);
	allQuestions.push_back(currentQuestion);
	vector<Impact> impactsToApply;
	for (int i = 0; i < allQuestions.size(); i++) {
		clearAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0,  0, allQuestions[i].HEADER);
		mvaddstrAlt(1,  0, allQuestions[i].HEADER_2);
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(2,  0, allQuestions[i].QUESTION);
		mvaddstrAlt(3,  0, allQuestions[i].QUESTION_2);
		if (i == 0) {
			mvaddstrAlt(17,  0, theDocSaid);
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			if (newcr->gender_conservative == GENDER_MALE)
				addstrAlt(aBoy);
			else if (newcr->gender_conservative == GENDER_FEMALE)
				addstrAlt(aGirl);
			else
				addstrAlt(intersex);
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt(singleDot);
			mvaddstrAlt(19,  0, myParents);
			if (newcr->gender_conservative == GENDER_NEUTRAL)
			{
				addstrAlt(insistedOtherwise);
				mvaddstrAlt(20,  0, they);
			}
			addstrAlt(namedMe);
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			addstrAlt(newcr->propername);
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt(singleDot);
		}

		// print answers
		char selection;
		if (!choices) {
			int offset = LCSrandom(allQuestions[i].choices.size());
			selection = 'a' + offset;
			string currentOption = spaceDashSpace;
			mvaddstrAlt(5 + 2 * offset, 0, allOptions.substr(offset, 1) + currentOption + allQuestions[i].choices[offset].ANSWER);
			mvaddstrAlt(6 + 2 * offset, 0, allQuestions[i].choices[offset].ANSWER_2);
			getkey();
		}
		else {
			for (int j = 0; j < allQuestions[i].choices.size(); j++) {
				string currentOption = spaceDashSpace;
				mvaddstrAlt(5 + 2 * j, 0, allOptions.substr(j, 1) + currentOption + allQuestions[i].choices[j].ANSWER);
				mvaddstrAlt(6 + 2 * j, 0, allQuestions[i].choices[j].ANSWER_2);
			}
			selection = getkey();
		}
		if (selection >= 'a' && selection < 'a' + allQuestions[i].choices.size()) {
			//IsaacG I assume there's a way to combine vectors that is easier and/or
			// more elegant than this, but whatever, this works.
			int impactNumber = allQuestions[i].choices[selection - 'a'].impact.size();
			vector<Impact> currentImpacts = allQuestions[i].choices[selection - 'a'].impact;
			for (int j = 0; j < impactNumber; j++) {
				impactsToApply.push_back(currentImpacts[j]);
			}
		}
		else {
			i--;
		}
	}
	for (int i = 0; i < impactsToApply.size(); i++) {
		const Impact currentImpact = impactsToApply[i];
		switch (currentImpact.type) {
		case SKILL:
			if (currentImpact.set_value) {
				newcr->set_skill((currentImpact.item_to_influcence), currentImpact.magnitude);
			}
			else {
				newcr->set_skill((currentImpact.item_to_influcence), newcr->get_skill((currentImpact.item_to_influcence)) + currentImpact.magnitude);
			}
			break;
		case ATTRIBUTE:
			if (currentImpact.set_value) {
				newcr->set_attribute((currentImpact.item_to_influcence), currentImpact.magnitude);
			}
			else {
				newcr->adjust_attribute((currentImpact.item_to_influcence), currentImpact.magnitude);
			}
			break;
		case OTHER:
			switch (currentImpact.item_to_influcence) {
			case BIRTH_MONTH:
				birth_month = currentImpact.magnitude;
				break;
			case				   BIRTH_DAY:
				birth_day = currentImpact.magnitude;
				break;
			case				   BIRTH_YEAR:
				birth_year = currentImpact.magnitude;
				break;
			case				   STARTING_MONTH:
				month = currentImpact.magnitude;
				break;
			case				   STARTING_DAY:
				day = currentImpact.magnitude;
				break;
			case				   STARTING_YEAR:
				year = currentImpact.magnitude;
				break;
			case				   GAY:
				gaylawyer = currentImpact.magnitude == 1;
				break;
			case				   DATING_LAWYER:
				makelawyer = currentImpact.magnitude == 1;
				break;
			case				   HAS_MAPS:
				hasmaps = currentImpact.magnitude == 1;
				break;
			case JUICE:
				if (currentImpact.set_value) {
					newcr->juice = currentImpact.magnitude;
				}
				else {
					newcr->juice += currentImpact.magnitude;
				}
				break;
			case				   SPORTS_CAR:
				sports_car = currentImpact.magnitude == 1;
				break;
			case				   ASSAULT_RIFLE:
				assault_rifle = currentImpact.magnitude == 1;
				break;
			case				   MONEY:
				if (currentImpact.set_value) {
					ledger.force_funds(currentImpact.magnitude);
				}
				else {
					ledger.force_funds(ledger.get_funds() + currentImpact.magnitude);
				}
				break;
			case				   BASE:
				base = currentImpact.magnitude;
				break;
			case				   CREATURE:
				newcr->type = (CreatureTypes)currentImpact.magnitude;
				newcr->type_idname = enumToCreatureString(currentImpact.magnitude);
				break;
			case				   ARMOR:
				// TODO Not Implemented
				break;
			case				   RECRUITS:
				if (currentImpact.magnitude == 1) {
					recruits = RECRUITS_GANG;
				}
				else {
					recruits = RECRUITS_NONE;
				}
				break;
			default:
				clearAlt();
				mvaddstrAlt(0,  0, error);
				mvaddstrAlt(1,  0, currentImpact.item_to_influcence);
				break;
			}
			break;
		default:
			clearAlt();
			mvaddstrAlt(0,  0, error);
			mvaddstrAlt(1,  0, currentImpact.type);
			break;
		}
	}
	//calculate founder's birthday and age
	newcr->birthday_day = birth_day;
	newcr->birthday_month = birth_month;
	newcr->age = year - birth_year;
	// Don't count this year in founder's age if starting before birthday
	if (month < newcr->birthday_month ||
		(month == newcr->birthday_month && day < newcr->birthday_day))
	{
		newcr->age--;
	}
	if (assault_rifle) {
		Weapon neww(*weapontype[getweapontype(tag_WEAPON_AUTORIFLE_AK47)]);
		Clip newc(*cliptype[getcliptype(tag_CLIP_ASSAULT)], 9);
		newcr->give_weapon(neww, NULL);
		newcr->take_clips(newc, 9);
	}
	if (sports_car) {
		startcar = new Vehicle(*vehicletype[getvehicletype(vehicleSportsCar)]);
		startcar->add_heat(10);
		vehicle.push_back(startcar);
		newcr->pref_carid = startcar->id();
	}
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(2,  2, aNewConEra, gamelog);
	gamelog.newline();
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(4,  2, theYearIs, gamelog);
	addstrAlt(year, gamelog);
	addstrAlt(singleDot, gamelog);
	gamelog.newline();
	mvaddstrAlt(6, 2, conservativePresident, gamelog);
	char president[80];
	generate_name(president, GENDER_WHITEMALEPATRIARCH);
	addstrAlt(president, gamelog);
	addstrAlt(endsSecondTerm, gamelog);
	gamelog.newline();
	mvaddstrAlt(7, 2, highSeventiesApprovePres, gamelog);
	gamelog.newline();
	mvaddstrAlt(8, 2, execname[EXEC_PRESIDENT], gamelog);
	addstrAlt(singleDot, gamelog);
	gamelog.nextMessage();
	mvaddstrAlt(10,  2, conMajorityHouse, gamelog);
	gamelog.newline();
	mvaddstrAlt(11, 2, senateConMajority, gamelog);
	gamelog.newline();
	mvaddstrAlt(12, 2, beginningOfNew, gamelog);
	gamelog.newline();
	mvaddstrAlt(13, 2, conEra, gamelog);
	gamelog.nextMessage();
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(15,  2, thePresident, gamelog);
	addstrAlt(execname[EXEC_PRESIDENT], gamelog);
	addstrAlt(hasAskedCongressBeQuick, gamelog);
	gamelog.newline();
	mvaddstrAlt(16, 2, rubberStampArchCon, gamelog);
	set_color_easy(WHITE_ON_BLACK);
	addstrAlt(theLeftSeems, gamelog);
	gamelog.newline();
	mvaddstrAlt(17,  2, powerlessToStop, gamelog);
	gamelog.nextMessage();
	mvaddstrAlt(19,  2, inThisDarkTime, gamelog);
	gamelog.nextMessage();
	getkey();
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(0,  0, whatIsYourName);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(1,  0, pressEnterToBeRealName);
	enter_name(2, 0, newcr->name, CREATURE_NAMELEN, newcr->propername);
	pool.push_back(newcr);
	make_world(hasmaps);
	squadst *newsq = new squadst;
	newsq->id = 0; cursquadid++;
	newsq->squad[0] = newcr;
	newcr->squadid = 0;
	strcpy(newsq->name, theLCS);
	for (int l = 0; l < len(location); l++)
	{
		if (location[l]->type == base)
		{
			newcr->base = l;
			newcr->location = l;
			if (startcar) startcar->set_location(l);
			switch (base)
			{
			case SITE_RESIDENTIAL_APARTMENT_UPSCALE:location[l]->renting = 500; break;
			case SITE_RESIDENTIAL_APARTMENT:location[l]->renting = 200; break;
			case SITE_RESIDENTIAL_TENEMENT:location[l]->renting = 100; break;
			case SITE_BUSINESS_CRACKHOUSE:
				location[l]->renting = RENTING_PERMANENT;
				location[l]->compound_stores += 100;
				break;
			}
			location[l]->newrental = 1;
			switch (recruits)
			{
			case RECRUITS_GANG:
				for (int i = 0; i < 4; i++)
				{
					Creature* recruit = new Creature;
					makecreature(*recruit, CREATURE_GANGMEMBER);
					if (recruit->get_weapon().get_itemtypename() == tag_WEAPON_AUTORIFLE_AK47 ||
						recruit->get_weapon().get_itemtypename() == tag_WEAPON_SMG_MP5 ||
						!recruit->is_armed())
					{
						Weapon w(*weapontype[getweapontype(tag_WEAPON_SEMIPISTOL_9MM)]);
						recruit->give_weapon(w, NULL);
						Clip c(*cliptype[getcliptype(tag_CLIP_9)], 4);
						recruit->take_clips(c, 4);
						recruit->reload(false);
					}
					recruit->align = ALIGN_LIBERAL;
					recruit->set_attribute(ATTRIBUTE_HEART,
						recruit->get_attribute(ATTRIBUTE_HEART, false) +
						recruit->get_attribute(ATTRIBUTE_WISDOM, false) / 2);
					recruit->set_attribute(ATTRIBUTE_WISDOM,
						recruit->get_attribute(ATTRIBUTE_WISDOM, false) / 2);
					recruit->namecreature();
					strcpy(recruit->name, recruit->propername);
					recruit->location = l;
					recruit->base = l;
					recruit->hireid = newcr->id;
					newsq->squad[i + 1] = recruit;
					recruit->squadid = newsq->id;
					pool.push_back(recruit);
				}
				break;
			}
			if (GIVEBLOODYARMOR) {
				Armor *newa = new Armor(*armortype[getarmortype(tag_ARMOR_CLOTHES)]);
				newa->set_bloody(true);
				location[l]->loot.push_back(newa);
			}
			if (HIGHFUNDS) {
				ledger.force_funds(100000);
			}
			break;
		}
	}
	//newcr->juice=0;
	squad.push_back(newsq);
	activesquad = newsq;
	if (makelawyer)
	{
		Creature* lawyer = new Creature;
		makecreature(*lawyer, CREATURE_LAWYER);
		// Make sure lawyer is of the appropriate gender for dating the main character;
		// opposite sex by default, same sex if the option was chosen that mentions
		// homosexuality
		if (gaylawyer)
		{
			lawyer->gender_conservative = lawyer->gender_liberal = newcr->gender_conservative;
			// neutral founder gets neutral partner
		}
		else
		{
			if (newcr->gender_conservative == GENDER_MALE)
				lawyer->gender_liberal = lawyer->gender_conservative = GENDER_FEMALE;
			if (newcr->gender_conservative == GENDER_FEMALE)
				lawyer->gender_liberal = lawyer->gender_conservative = GENDER_MALE;
			// neutral founder gets random partner
		}
		// Ensure the lawyer has good heart/wisdom stats
		if (lawyer->get_attribute(ATTRIBUTE_HEART, false) < newcr->get_attribute(ATTRIBUTE_HEART, false) - 2)
			lawyer->adjust_attribute(ATTRIBUTE_HEART, -2);
		lawyer->set_attribute(ATTRIBUTE_WISDOM, 1);
		lawyer->namecreature();
		lawyer->flag |= CREATUREFLAG_SLEEPER;
		lawyer->flag |= CREATUREFLAG_LOVESLAVE;
		lawyer->align = ALIGN_LIBERAL;
		lawyer->infiltration = 0.3f;
		lawyer->age = 28;
		location[lawyer->worklocation]->mapped = 1;
		lawyer->hireid = newcr->id;
		pool.push_back(lawyer);
		lawyer->location = lawyer->base = lawyer->worklocation;
	}
	uniqueCreatures.initialize();
}
