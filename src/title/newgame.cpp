
#include "../includes.h"
const string tag_CLIP = "CLIP";

const string tag_CLIP_ASSAULT = "CLIP_ASSAULT";

const string tag_WEAPON = "WEAPON";

const string tag_WEAPON_AUTORIFLE_AK47 = "WEAPON_AUTORIFLE_AK47";

const string tag_SPORTS_CAR = "SPORTS_CAR";

const string tag_ASSAULT_RIFLE = "ASSAULT_RIFLE";

const string tag_RECRUITS_GANG = "RECRUITS_GANG";

const string tag_JUICE = "JUICE";

const string tag_ARMOR = "ARMOR";

const string tag_B = "B";

const string tag_BASE = "BASE";

const string tag_CREATURE = "CREATURE";

const string tag_HASMAPS = "HASMAPS";

const string tag_GAY = "GAY";

const string tag_D = "D";

const string tag_DATING_LAWYER = "DATING_LAWYER";

const string tag_MONEY = "MONEY";

const string tag_YEAR = "YEAR";

const string tag_Y = "Y";

const string tag_DAY = "DAY";

const string tag_MONTH = "MONTH";

const string tag_BIRTHDAY_ = "BIRTHDAY_";

const string tag_STARTING_ = "STARTING_";

const string tag_ATTRIBUTE_ = "ATTRIBUTE_";

const string tag_SKILL_ = "SKILL_";

const string blankString = "";

const string tag__2 = "_2";

const string tag_QUESTION = "QUESTION";

const string tag_ANSWER = "ANSWER";

const string tag_HEADER = "HEADER";

const string tag_ARMOR_CLOTHES = "ARMOR_CLOTHES";


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

#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../creature/creature.h"
#include "../locations/locations.h"

#include "../common/ledgerEnums.h"
#include "../common/ledger.h"


//#include "../common/consolesupport.h"
// for getkey

#include "../log/log.h"

#include "../common/stringconversion.h"
//for string attribute_enum_to_string(int)

#include "../common/getnames.h"
// for cityname

#include "../common/translateid.h"
// for  getarmortype

#include "../cursesAlternative.h"
#include "../set_color_support.h"

#include "../common/creaturePoolCreature.h"

#include "../common/musicClass.h"


string theLCS;
string notASkill;
string notAnAttribute;

Vehicle* newSportsCar();

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
string pressAnyKeyString;
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

extern UniqueCreatures uniqueCreatures;
extern string singleSpace;
void newVehicle(Vehicle *startcar);
extern string singleDot;
vector<string> founderQuestions;

#include "../customMaps.h"
vector<file_and_text_collection> newgame_file_collection = {
	/*newgame.cpp*/
	customText(&founderQuestions, "newgame\\founderQuestions.txt"),
};
map<string, short> getSkillEnumFromString;
map<short, string> enumToCreature;
map<string, short> getBaseEnumFromString;
map<string, short> getSpecialWoundEnumFromString;
bool getSetValue(const string& s) {
	int j = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			j = i;
			break;
		}
	}
	return j > -1 && (s[j] == '-' || s[j] == '+');
}
int getMagnitudeFromString(const string& s) {
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
		mvaddstrAlt(0, 0, error);
		mvaddstrAlt(1, 0, s);
		pressAnyKey();
	}
	return atoi(s.substr(j).data());
}
// IsaacG Brute force substring matching
// suboptimal, but very very easy to code.
short findSubstring(map<string, short> str, const string& s) {
	for (int i = strlen(s.data()); i >= 0; i--) {
		for (int j = 0; j <= strlen(s.data() - i); j++) {
			if (str.count(s.substr(j, i))) {
				return str[s.substr(j, i)];
			}
		}
	}
	return -1;
}
int getSkillFromString(const string& s) {
	int output = findSubstring(getSkillEnumFromString, s);
	if (output >= 0) {
		return output;
	}
	else {// ERROR
		addstrAlt(error);
		addstrAlt(s);
		addstrAlt(notASkill);
		pressAnyKey();
		return -1;
	}
}
map<string, short> getAttributeEnumFromString;
int getAttributeFromString(const string& s) {
	int output = findSubstring(getAttributeEnumFromString, s);
	if (output >= 0) {
		return output;
	}
	else {// ERROR
		addstrAlt(error);
		addstrAlt(s);
		addstrAlt(notAnAttribute);
		pressAnyKey();
		return -1;
	}
}
map<string, short> getCreatureEnumFromString;
int getCreatureFromString(const string& s) {
	int output = findSubstring(getCreatureEnumFromString, s);
	if (output >= 0) {
		return output;
	}
	else
	{// ERROR
		addstrAlt(error);
		addstrAlt(s);
		addstrAlt(notCreature);
		pressAnyKey();
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
int getBaseFromString(const string& s) {
	const string baseString = s.substr(5);
	int output = findSubstring(getBaseEnumFromString, baseString);
	if (output >= 0) {
		return output;
	}
	else {// ERROR
		addstrAlt(error);
		addstrAlt(s);
		addstrAlt(notValidMap);
		pressAnyKey();
		return -1;
	}
}
int getSpecialWoundFromString(const string& s) {
	int output = findSubstring(getSpecialWoundEnumFromString, s);
	if (output >= 0) {
		return output;
	}
	else {// ERROR
		addstrAlt(error);
		addstrAlt(s);
		addstrAlt(notSpecialWound);
		pressAnyKey();
		return -1;
	}
}
LOOP_CONTINUATION newgame_starting_conditions_getKey(bool &classicmode, bool &strongccs, bool &nightmarelaws) {
	extern bool stalinmode;
	extern bool multipleCityMode;
	extern bool ALLOWSTALIN;
	extern bool notermlimit;           //These determine if ELAs can take place --kviiri
	extern bool nocourtpurge;
	switch (getkeyAlt()) {
	case 'a':

		classicmode = !classicmode;
		break;

	case 'b':
		strongccs = !strongccs;

		break;

	case 'c':
		nightmarelaws = !nightmarelaws;

		break;

	case 'd':
		multipleCityMode = !multipleCityMode;

		break;

	case 'e':

		nocourtpurge = !nocourtpurge;
		notermlimit = !notermlimit;
		break;

	case 'f':
		if (ALLOWSTALIN) {
			stalinmode = !stalinmode;
			return REPEAT;
		} // else return RETURN_ZERO
	default:
		return RETURN_ZERO;
	}
	return REPEAT;
}
void print_newgame_choices(const bool classicmode, const bool strongccs, const bool nightmarelaws) {
	extern bool stalinmode;
	extern bool multipleCityMode;
	extern bool ALLOWSTALIN;
	extern bool notermlimit;           //These determine if ELAs can take place --kviiri
	extern bool nocourtpurge;

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(4, 6, newGameAdvanced);
	set_color_easy(WHITE_ON_BLACK);
	{
		mvaddstrAlt(7, 0, classicmode ? isSelected : unSelected);
		addstrAlt(a_classicMode);
		if (!classicmode)
			set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(9, 0, strongccs ? isSelected : unSelected);
		addstrAlt(b_weDidntStartIt);
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(11, 0, nightmarelaws ? isSelected : unSelected);
		addstrAlt(c_nightmareMode);
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(13, 0, multipleCityMode ? isSelected : unSelected);
		addstrAlt(d_nationalLCS);
		mvaddstrAlt(15, 0, nocourtpurge ? isSelected : unSelected);
		addstrAlt(e_marathonMode);
		int bottomRow;
		if (ALLOWSTALIN) {
			mvaddstrAlt(17, 0, stalinmode ? isSelected : unSelected);
			addstrAlt(f_stalinistMode);
			bottomRow = 21;
		}
		else {// ALLOWSTALIN
			bottomRow = 19;
		}// ALLOWSTALIN
		mvaddstrAlt(bottomRow, 4, pressAnyOtherKey);
	}
}
LOOP_CONTINUATION newgame_starting_conditions(bool &classicmode, bool &strongccs, bool &nightmarelaws) {
	print_newgame_choices(classicmode, strongccs, nightmarelaws);
	return newgame_starting_conditions_getKey(classicmode, strongccs, nightmarelaws);
}
void implementNightmareLaws() {
	extern short lawList[LAWNUM];
	extern short house[HOUSENUM];
	extern short senate[SENATENUM];
	extern short court[COURTNUM];
	extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
	extern short attitude[VIEWNUM];

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
		} while (len(courtname[c]) > 20);
	}
}
LOOP_CONTINUATION implementWinCondition(const bool classicmode) {
	extern short wincondition;

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(4, 6, newGameYourAgenda);
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
	mvaddstrAlt(13, 4, pressAnyOtherKey);
	const int c = getkeyAlt();
	if (c == 'a')
	{
		wincondition = WINCONDITION_ELITE;
		return REPEAT;
	}
	if (c == 'b')
	{
		wincondition = WINCONDITION_EASY;
		return REPEAT;
	}
	return RETURN_ZERO;
}
LOOP_CONTINUATION implementFieldSkillRate() {
	extern short fieldskillrate;

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(4, 6, newGameFieldLearn);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(5, 6, affectsTheseSkills);
	string isThisSelected;
	if (fieldskillrate == FIELDSKILLRATE_FAST)
		isThisSelected = isSelected;
	else isThisSelected = unSelected;
	mvaddstrAlt(8, 0, isThisSelected);
	addstrAlt(a_fastSkills);
	if (fieldskillrate == FIELDSKILLRATE_CLASSIC)
		isThisSelected = isSelected;
	else isThisSelected = unSelected;
	mvaddstrAlt(10, 0, isThisSelected);
	addstrAlt(b_classic);
	if (fieldskillrate == FIELDSKILLRATE_HARD)
		isThisSelected = isSelected;
	else isThisSelected = unSelected;
	mvaddstrAlt(12, 0, isThisSelected);
	addstrAlt(c_hardMode);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(16, 4, pressAnyOtherKey);
	const int c = getkeyAlt();
	if (c == 'a')
	{
		fieldskillrate = FIELDSKILLRATE_FAST;
		return REPEAT;
	}
	if (c == 'b')
	{
		fieldskillrate = FIELDSKILLRATE_CLASSIC;
		return REPEAT;
	}
	if (c == 'c')
	{
		fieldskillrate = FIELDSKILLRATE_HARD;
		return REPEAT;
	}
	return RETURN_ZERO;
}
/* select new game options */
void setup_newgame()
{
	extern char endgamestate;
	extern bool stalinmode;
	extern bool multipleCityMode;
	extern MusicClass music;

	music.play(MUSIC_NEWGAME);
	bool classicmode = false;
	bool strongccs = false;
	bool nightmarelaws = false;
	multipleCityMode = false;
	stalinmode = false;
	clearAlt();
	while (newgame_starting_conditions(classicmode, strongccs, nightmarelaws) == REPEAT)
	{
		;
	}
	if (nightmarelaws)
	{
		implementNightmareLaws();
	}
	if (classicmode)
		endgamestate = ENDGAME_CCS_DEFEATED;
	else if (strongccs)
	{
		endgamestate = ENDGAME_CCS_ATTACKS;
		//attitude[VIEW_POLITICALVIOLENCE]=90;
	}
	clearAlt();
	while (implementWinCondition(classicmode) == REPEAT)
	{
		;
	}
	clearAlt();
	while (implementFieldSkillRate() == REPEAT)
	{
		;
	}
}
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
void printIntroduction() {
	extern Log gamelog;
	extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	extern int year;
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(2, 2, aNewConEra, gamelog);
	gamelog.newline();
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(4, 2, theYearIs, gamelog);
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
	mvaddstrAlt(10, 2, conMajorityHouse, gamelog);
	gamelog.newline();
	mvaddstrAlt(11, 2, senateConMajority, gamelog);
	gamelog.newline();
	mvaddstrAlt(12, 2, beginningOfNew, gamelog);
	gamelog.newline();
	mvaddstrAlt(13, 2, conEra, gamelog);
	gamelog.nextMessage();
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(15, 2, thePresident, gamelog);
	addstrAlt(execname[EXEC_PRESIDENT], gamelog);
	addstrAlt(hasAskedCongressBeQuick, gamelog);
	gamelog.newline();
	mvaddstrAlt(16, 2, rubberStampArchCon, gamelog);
	set_color_easy(WHITE_ON_BLACK);
	addstrAlt(theLeftSeems, gamelog);
	gamelog.newline();
	mvaddstrAlt(17, 2, powerlessToStop, gamelog);
	gamelog.nextMessage();
	mvaddstrAlt(19, 2, inThisDarkTime, gamelog);
	gamelog.nextMessage();
	pressAnyKey();
}
enum founderQuestionTagEnums {
	ENUM_tag_HEADER,
	ENUM_tag_ANSWER,
	ENUM_tag_QUESTION,
	ENUM_tag_SKILL_,
	ENUM_tag_ATTRIBUTE_,
	ENUM_tag_STARTING_,
	ENUM_tag_BIRTHDAY_,
	ENUM_tag_MONEY,
	ENUM_tag_DATING_LAWYER,
	ENUM_tag_GAY,
	ENUM_tag_HASMAPS,
	ENUM_tag_CREATURE,
	ENUM_tag_BASE,
	ENUM_tag_ARMOR,
	ENUM_tag_JUICE,
	ENUM_tag_RECRUITS_GANG,
	ENUM_tag_ASSAULT_RIFLE,
	ENUM_tag_SPORTS_CAR,
};
map<string, int> founderQuestionTags = {
	map<string, int>::value_type(tag_HEADER, ENUM_tag_HEADER),
	map<string, int>::value_type(tag_ANSWER, ENUM_tag_ANSWER),
	map<string, int>::value_type(tag_QUESTION, ENUM_tag_QUESTION),
	map<string, int>::value_type(tag_SKILL_, ENUM_tag_SKILL_),
	map<string, int>::value_type(tag_ATTRIBUTE_, ENUM_tag_ATTRIBUTE_),
	map<string, int>::value_type(tag_STARTING_, ENUM_tag_STARTING_),
	map<string, int>::value_type(tag_BIRTHDAY_, ENUM_tag_BIRTHDAY_),
	map<string, int>::value_type(tag_MONEY, ENUM_tag_MONEY),
	map<string, int>::value_type(tag_DATING_LAWYER, ENUM_tag_DATING_LAWYER),
	map<string, int>::value_type(tag_GAY, ENUM_tag_GAY),
	map<string, int>::value_type(tag_HASMAPS, ENUM_tag_HASMAPS),
	map<string, int>::value_type(tag_CREATURE, ENUM_tag_CREATURE),
	map<string, int>::value_type(tag_BASE, ENUM_tag_BASE),
	map<string, int>::value_type(tag_ARMOR, ENUM_tag_ARMOR),
	map<string, int>::value_type(tag_JUICE, ENUM_tag_JUICE),
	map<string, int>::value_type(tag_RECRUITS_GANG, ENUM_tag_RECRUITS_GANG),
	map<string, int>::value_type(tag_ASSAULT_RIFLE, ENUM_tag_ASSAULT_RIFLE),
	map<string, int>::value_type(tag_SPORTS_CAR, ENUM_tag_SPORTS_CAR),
};
void resetChoiceAndQuestion(Choice &currentChoice, Question &currentQuestion, const string header, const string header_2, const string firstsubstr) {


	currentChoice.ANSWER = blankString;
	currentChoice.ANSWER_2 = blankString;
	currentQuestion.HEADER = header;
	currentQuestion.HEADER_2 = header_2;
	currentQuestion.QUESTION = firstsubstr;
	currentQuestion.QUESTION_2 = blankString;

}
bool getAttributeFromFounderQuestion(const string question, Impact &currentImpact) {

	currentImpact.type = ATTRIBUTE;
	currentImpact.item_to_influcence = getAttributeFromString(question);
	currentImpact.set_value = getSetValue(question);
	currentImpact.magnitude = getMagnitudeFromString(question);

	if (currentImpact.item_to_influcence == -1) {
		return false;
	}
	else {
		return true;
	}
}

bool getSkillFromFounderQuestion(const string question, Impact &currentImpact) {
	currentImpact.type = SKILL;
	currentImpact.item_to_influcence = getSkillFromString(question);
	currentImpact.set_value = getSetValue(question);
	currentImpact.magnitude = getMagnitudeFromString(question);

	if (currentImpact.item_to_influcence == -1) {
		return false;
	}
	else {
		return true;
	}
}

bool getStartingFromFounderQuestion(const string question, Impact &currentImpact, const string first) {

	currentImpact.type = OTHER;
	currentImpact.set_value = true;
	currentImpact.magnitude = getMagnitudeFromString(question);
	if (first.substr(9, 5) == tag_MONTH) {
		currentImpact.item_to_influcence = STARTING_MONTH;
	}
	else if (first.substr(9, 3) == tag_DAY) {
		currentImpact.item_to_influcence = STARTING_DAY;
	}
	else if (first.substr(9, 4) == tag_YEAR) {
		currentImpact.item_to_influcence = STARTING_YEAR;
	}

	if (currentImpact.item_to_influcence == -1) {
		return false;
	}
	else {
		return true;
	}
}

bool getBirthdayFromFounderQuestion(const string question, Impact &currentImpact, const string first) {

	currentImpact.type = OTHER;
	currentImpact.item_to_influcence = -1;
	currentImpact.set_value = true;
	currentImpact.magnitude = getMagnitudeFromString(question);
	if (first.substr(9, 5) == tag_MONTH) {
		currentImpact.item_to_influcence = BIRTH_MONTH;
	}
	else if (first.substr(9, 3) == tag_DAY) {
		currentImpact.item_to_influcence = BIRTH_DAY;
	}
	else if (first.substr(9, 4) == tag_YEAR) {
		currentImpact.item_to_influcence = BIRTH_YEAR;
	}

	if (currentImpact.item_to_influcence == -1) {
		return false;
	}
	else {
		return true;
	}
}

bool getArmorFromFounderQuestion(const string question, Impact &currentImpact) {

	currentImpact.type = OTHER;
	currentImpact.item_to_influcence = ARMOR;
	currentImpact.set_value = true;

	return false;

}
vector<Question> gatherAllFounderQuestions() {
	const int MAX_CHOICES = 10;
	vector<Question> allQuestions;
	bool firstQuestion = true;
	bool firstAnswer = true;
	Question currentQuestion;
	Choice currentChoice;
	string header = blankString;
	string header_2 = blankString;
	string answer = blankString;
	string answer_2 = blankString;

	for (int i = 0; i < founderQuestions.size(); i++) {
		Impact currentImpact;
		bool invalidTag = false;
		const string first = founderQuestions[i];
		int enumTag = -1;
		for (int j = 3; j < 14 && enumTag == -1; j++) {
			if (founderQuestionTags.count(first.substr(0, j))) {
				enumTag = founderQuestionTags[first.substr(0, j)];
			}
		}
		switch (enumTag) {
		case ENUM_tag_HEADER:
			if (first.substr(6, 1) == singleSpace) {
				header = first.substr(7);
				header_2 = blankString;
			}
			else  if (first.substr(6, 2) == tag__2) {
				header_2 = first.substr(9);
			}
			break;
		case ENUM_tag_ANSWER:
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
			break;
		case ENUM_tag_QUESTION:
			if (!firstQuestion) {
				if (first.substr(8, 1) == singleSpace) {
					currentChoice.ANSWER = answer;
					currentChoice.ANSWER_2 = answer_2;
					currentQuestion.choices.push_back(currentChoice);
					allQuestions.push_back(currentQuestion);
					currentQuestion.choices.clear();
					currentChoice.impact.clear();

					firstAnswer = true;

					resetChoiceAndQuestion(currentChoice, currentQuestion, header, header_2, first.substr(9));
				}
				else if (first.substr(8, 2) == tag__2) {
					currentQuestion.QUESTION_2 = first.substr(12);
				}
			}
			else {
				firstQuestion = false;

				firstAnswer = true;

				resetChoiceAndQuestion(currentChoice, currentQuestion, header, header_2, first.substr(9));
			}
			break;
		case ENUM_tag_SKILL_:
			invalidTag = !getSkillFromFounderQuestion(founderQuestions[i], currentImpact);
			break;
		case ENUM_tag_ATTRIBUTE_:
			invalidTag = !getAttributeFromFounderQuestion(founderQuestions[i], currentImpact);
			break;
		case ENUM_tag_STARTING_:
			invalidTag = !getStartingFromFounderQuestion(founderQuestions[i], currentImpact, first);
			break;
		case ENUM_tag_BIRTHDAY_:
			invalidTag = !getBirthdayFromFounderQuestion(founderQuestions[i], currentImpact, first);
			break;
		case ENUM_tag_MONEY:
			currentImpact.type = OTHER;
			currentImpact.item_to_influcence = MONEY;
			currentImpact.set_value = getSetValue(founderQuestions[i]);
			currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			break;
		case ENUM_tag_DATING_LAWYER:
			currentImpact.type = OTHER;
			currentImpact.item_to_influcence = DATING_LAWYER;
			currentImpact.set_value = true;
			currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			break;
		case ENUM_tag_GAY:
			currentImpact.type = OTHER;
			currentImpact.item_to_influcence = GAY;
			currentImpact.set_value = true;
			currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			break;
		case ENUM_tag_HASMAPS:
			currentImpact.type = OTHER;
			currentImpact.item_to_influcence = HAS_MAPS;
			currentImpact.set_value = true;
			currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			break;
		case ENUM_tag_CREATURE:
			currentImpact.type = OTHER;
			currentImpact.item_to_influcence = CREATURE;
			currentImpact.set_value = true;
			currentImpact.magnitude = getCreatureFromString(founderQuestions[i].substr(9));
			break;
		case ENUM_tag_BASE:
			currentImpact.type = OTHER;
			currentImpact.item_to_influcence = BASE;
			currentImpact.set_value = true;
			currentImpact.magnitude = getBaseFromString(founderQuestions[i]);
			if (currentImpact.magnitude == -1) {
				invalidTag = true;
			}
			break;
		case ENUM_tag_ARMOR:
			invalidTag = !getArmorFromFounderQuestion(founderQuestions[i], currentImpact);
			break;
		case ENUM_tag_JUICE:
			currentImpact.type = OTHER;
			currentImpact.item_to_influcence = JUICE;
			currentImpact.set_value = getSetValue(founderQuestions[i]);
			currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			break;
		case ENUM_tag_RECRUITS_GANG:
			currentImpact.type = OTHER;
			currentImpact.item_to_influcence = RECRUITS;
			currentImpact.set_value = true;
			currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			break;
		case ENUM_tag_ASSAULT_RIFLE:
			currentImpact.type = OTHER;
			currentImpact.item_to_influcence = ASSAULT_RIFLE;
			currentImpact.set_value = true;
			currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			break;
		case ENUM_tag_SPORTS_CAR:
			currentImpact.type = OTHER;
			currentImpact.item_to_influcence = SPORTS_CAR;
			currentImpact.set_value = true;
			currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			break;
		default:
			invalidTag = true;
			break;
		}

		if (invalidTag) {
			clearAlt();
			addstrAlt(invalidTag);
			addstrAlt(founderQuestions[i]);
			pressAnyKey();
			clearAlt();
		}
		else {
			currentChoice.impact.push_back(currentImpact);
		}

	}
	// The last choice and question added after the loop ends
	currentChoice.ANSWER = answer;
	currentChoice.ANSWER_2 = answer_2;
	currentQuestion.choices.push_back(currentChoice);
	allQuestions.push_back(currentQuestion);
	return allQuestions;
}
vector<Impact> printQuestionsThenGatherImpacts(vector<Question> allQuestions, const bool choices, const int gender_conservative, const string propername) {

	vector<Impact> impactsToApply;
	for (int i = 0; i < allQuestions.size(); i++) {
		clearAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0, 0, allQuestions[i].HEADER);
		mvaddstrAlt(1, 0, allQuestions[i].HEADER_2);
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(2, 0, allQuestions[i].QUESTION);
		mvaddstrAlt(3, 0, allQuestions[i].QUESTION_2);
		// print answers
		if (i == 0) {
			mvaddstrAlt(17, 0, theDocSaid);
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			if (gender_conservative == GENDER_MALE)
				addstrAlt(aBoy);
			else if (gender_conservative == GENDER_FEMALE)
				addstrAlt(aGirl);
			else
				addstrAlt(intersex);
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt(singleDot);
			mvaddstrAlt(19, 0, myParents);
			if (gender_conservative == GENDER_NEUTRAL)
			{
				addstrAlt(insistedOtherwise);
				mvaddstrAlt(20, 0, they);
			}
			addstrAlt(namedMe);
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			addstrAlt(propername);
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt(singleDot);
		}
		char selection;
		if (!choices) {
			int offset = LCSrandom(allQuestions[i].choices.size());
			selection = 'a' + offset;
			string currentOption = spaceDashSpace;
			mvaddstrAlt(5 + 2 * offset, 0, allOptions.substr(offset, 1) + currentOption + allQuestions[i].choices[offset].ANSWER);
			mvaddstrAlt(6 + 2 * offset, 0, allQuestions[i].choices[offset].ANSWER_2);
			pressAnyKey();
		}
		else {
			for (int j = 0; j < allQuestions[i].choices.size(); j++) {
				string currentOption = spaceDashSpace;
				mvaddstrAlt(5 + 2 * j, 0, allOptions.substr(j, 1) + currentOption + allQuestions[i].choices[j].ANSWER);
				mvaddstrAlt(6 + 2 * j, 0, allQuestions[i].choices[j].ANSWER_2);
			}
			selection = getkeyAlt();
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
	return impactsToApply;
}
void DeprecatedCreature:: make_blind() {

	special[SPECIALWOUND_RIGHTEYE] = 1;
	special[SPECIALWOUND_LEFTEYE] = 1;
}
void DeprecatedCreature:: remove_spine() {

	special[SPECIALWOUND_UPPERSPINE] = 1;
	special[SPECIALWOUND_LOWERSPINE] = 1;
}
void DeprecatedCreature:: remove_face() {

	special[SPECIALWOUND_TONGUE] = 1;
	special[SPECIALWOUND_RIGHTEYE] = 1;
	special[SPECIALWOUND_LEFTEYE] = 1;
	special[SPECIALWOUND_NOSE] = 1;
}
void DeprecatedCreature:: make_paraplegic() {

	special[SPECIALWOUND_UPPERSPINE] = 1;
	special[SPECIALWOUND_LOWERSPINE] = 1;
	special[SPECIALWOUND_NECK] = 1;
	wound[BODYPART_LEG_RIGHT] = 1;
	wound[BODYPART_LEG_LEFT] = 1;
}
void DeprecatedCreature:: severe_internal_damage() {

	special[SPECIALWOUND_RIGHTLUNG] = 1;
	special[SPECIALWOUND_LEFTLUNG] = 1;
	special[SPECIALWOUND_HEART] = 1;
	special[SPECIALWOUND_LIVER] = 1;
	special[SPECIALWOUND_STOMACH] = 1;
	special[SPECIALWOUND_LEFTKIDNEY] = 1;
	special[SPECIALWOUND_RIGHTKIDNEY] = 1;
	special[SPECIALWOUND_SPLEEN] = 1;
}
void DeprecatedCreature::set_attributes_zero() {

	set_attribute(ATTRIBUTE_HEART, 0);
	set_attribute(ATTRIBUTE_WISDOM, 0);
	set_attribute(ATTRIBUTE_INTELLIGENCE, 0);
	set_attribute(ATTRIBUTE_AGILITY, 0);
	set_attribute(ATTRIBUTE_STRENGTH, 0);
	set_attribute(ATTRIBUTE_HEALTH, 0);
	set_attribute(ATTRIBUTE_CHARISMA, 0);
}

void DeprecatedCreature::set_default_values() {
	// Make the founder blind
	extern bool BLIND;
	// Make the founder unable to walk
	extern bool NOWALK;
	// Make the founder have no face
	extern bool NOFACE;
	// Make the founder have a severely injured spine
	extern bool SPINE;
	// Make the founder have severe internal damage
	extern bool INTERNAL;

	align = ALIGN_LIBERAL;
	set_attributes_zero();
	if (BLIND) {
		make_blind();
	}
	if (SPINE) {
		remove_spine();
	}
	if (NOFACE) {
		remove_face();
	}
	if (NOWALK) {
		make_paraplegic();
	}
	if (INTERNAL) {
		severe_internal_damage();
	}
}

bool DeprecatedCreature::print_default_founder_window() {
	extern bool multipleCityMode;
	extern char lcityname[CITY_NAMELEN];

	char first[3][80];
	char last[80];
	const bool is_male = LCSrandom(2); // whether or not starting gender is male
	char gender = gender_liberal = gender_conservative = (is_male ? GENDER_MALE : GENDER_FEMALE);
	do {
		firstname(first[0], GENDER_NEUTRAL);
		firstname(first[1], GENDER_MALE);
		firstname(first[2], GENDER_FEMALE);
		strcpy(last, lastname());
	} while (strcmp(first[0], last) == 0 && strcmp(first[1], last) == 0 && strcmp(first[2], last) == 0);
	{
		Armor a(getarmortype(tag_ARMOR_CLOTHES));
		give_armor(a, NULL);
	}

	bool choices = true;
	while (true)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(4, 6, theFounder);
		mvaddstrAlt(7, 2, firstName);
		addstrAlt(first[(int)gender]);
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(7, 30, pressAtoReconsider);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(9, 2, lastName);
		addstrAlt(last);
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(9, 30, pressBtoBeReborn);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(11, 2, sexIs);
		if (gender_conservative == GENDER_MALE)
		{
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			addstrAlt(male);
		}
		else if (gender_conservative == GENDER_FEMALE)
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
		mvaddstrAlt(11, 30, pressCtoChangeSex);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(13, 2, history);
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
		mvaddstrAlt(13, 30, pressDtoToggle);
		if (!multipleCityMode)
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(15, 2, city);
			addstrAlt(lcityname);
			set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(15, 30, pressEtoRelocate);
		}
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(19 - multipleCityMode * 2, 4, pressAnyKeyString);
		const int c = getkeyAlt();
		if (c == 'a')
		{
			do {
				firstname(first[(int)gender], gender_conservative);
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
			if ((gender_conservative == GENDER_FEMALE && !is_male) ||
				(gender_conservative == GENDER_NEUTRAL && is_male))
				gender_conservative = GENDER_MALE;
			else if ((gender_conservative == GENDER_MALE && !is_male) ||
				(gender_conservative == GENDER_FEMALE && is_male))
				gender_conservative = GENDER_NEUTRAL;
			else
				gender_conservative = GENDER_FEMALE;
			gender = gender_liberal = gender_conservative;
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
	strcpy(propername, first[(int)gender]);
	strcat(propername, singleSpace);
	strcat(propername, last);
	return choices;
}

#include "../recruits.h"
/* creates your founder */
void DeprecatedCreature::giveMeAssaultRifle() {
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;

	Weapon neww(*weapontype[getweapontype(tag_WEAPON_AUTORIFLE_AK47)]);
	Clip newc(*cliptype[getcliptype(tag_CLIP_ASSAULT)], 9);
	give_weapon(neww, NULL);
	take_clips(newc, 9);
}
void makecharacter()
{
	extern UniqueCreatures uniqueCreatures;
	extern Log gamelog;
	extern int year;
	extern int day;
	extern int month;
	extern class Ledger ledger;
	DeprecatedCreature *newcr = new DeprecatedCreature;
	newcr->set_default_values();
	bool choices = newcr->print_default_founder_window();
	int c;
	bool hasmaps = false;
	bool makelawyer = false;
	bool gaylawyer = false;
	char recruits = RECRUITS_NONE;
	char base = SITE_RESIDENTIAL_SHELTER;
	for (int sk = 0; sk < SKILLNUM; sk++)newcr->set_skill((sk), 0);
	bool assault_rifle = false;
	bool sports_car = false;
	int birth_year = 1984; // default birth year, month, and day in case left undefined
	int birth_month = 1;
	int birth_day = 1;

	vector<Question> allQuestions = gatherAllFounderQuestions();

	vector<Impact> impactsToApply = printQuestionsThenGatherImpacts(allQuestions, choices, newcr->gender_conservative, newcr->propername);

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
				mvaddstrAlt(0, 0, error);
				mvaddstrAlt(1, 0, currentImpact.item_to_influcence);
				break;
			}
			break;
		default:
			clearAlt();
			mvaddstrAlt(0, 0, error);
			mvaddstrAlt(1, 0, currentImpact.type);
			break;
		}
	}
	//calculate founder's birthday and age
	newcr->set_date_of_birth(birth_day, birth_month, birth_year);
	if (assault_rifle) {
		newcr->giveMeAssaultRifle();
	}
	printIntroduction();
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(0, 0, whatIsYourName);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(1, 0, pressEnterToBeRealName);
	newcr->new_name_two();
	newcr->addCreature();
	make_world(hasmaps);
	
	newcr->initiateNewgameLocations(newGameArguments(recruits, base, makelawyer, gaylawyer, sports_car));
	uniqueCreatures.initialize();
}
