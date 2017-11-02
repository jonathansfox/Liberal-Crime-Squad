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
extern bool multipleCityMode;
extern MusicClass music;
extern int year;
extern char endgamestate;
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern string tag_ARMOR;
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
		moveZeroZero();
		addstrAlt("ERROR");
		moveOneZero();
		addstrAlt(s);
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
		addstrAlt("ERROR");
		addstrAlt(s);
		addstrAlt("Not a skill");
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
		addstrAlt("ERROR");
		addstrAlt(s);
		addstrAlt("Not an attribute");
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
		addstrAlt("ERROR");
		addstrAlt(s);
		addstrAlt("Not a creature");
		getkey();
		return -1;
	}
}
string enumToCreatureString(const int i) {
	if (enumToCreature.count(i)) {
		return enumToCreature[i];
	}
	else {
		return "";
	}
}
int getBaseFromString(const string s) {
	const string baseString = s.substr(5);
	int output = findSubstring(getBaseEnumFromString, baseString);
	if (output >= 0) {
		return output;
	}
	else {// ERROR
		addstrAlt("ERROR");
		addstrAlt(s);
		addstrAlt("Not a valid mappable site");
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
		addstrAlt("ERROR");
		addstrAlt(s);
		addstrAlt("Not a special wound");
		getkey();
		return -1;
	}
}
/* select new game options */
void setup_newgame()
{
	//TODO IsaacG Get rid of these "while(true) break;" loops
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
		moveAlt(4, 6);
		addstrAlt("New Game of Liberal Crime Squad: Advanced Gameplay Options");
		moveAlt(7, 0);
		set_color_easy(WHITE_ON_BLACK);
		if (classicmode)
			addstrAlt("[X]");
		else addstrAlt("[ ]");
		addstrAlt(" A - Classic Mode: No Conservative Crime Squad.");
		moveAlt(9, 0);
		if (!classicmode)
			set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		if (strongccs)
			addstrAlt("[X]");
		else addstrAlt("[ ]");
		addstrAlt(" B - We Didn't Start The Fire: The CCS starts active and extremely strong.");
		moveAlt(11, 0);
		set_color_easy(WHITE_ON_BLACK);
		if (nightmarelaws)
			addstrAlt("[X]");
		else addstrAlt("[ ]");
		addstrAlt(" C - Nightmare Mode: Liberalism is forgotten. Is it too late to fight back?");
		moveAlt(13, 0);
		set_color_easy(WHITE_ON_BLACK);
		if (multipleCityMode)
			addstrAlt("[X]");
		else addstrAlt("[ ]");
		addstrAlt(" D - National LCS: Advanced play across multiple cities.");
		moveAlt(15, 0);
		if (nocourtpurge)
			addstrAlt("[X]");
		else addstrAlt("[ ]");
		addstrAlt(" E - Marathon Mode: Prevent Liberals from amending the Constitution.");
		if (ALLOWSTALIN) {
			moveAlt(17, 0);
			if (stalinmode)
				addstrAlt("[X]");
			else addstrAlt("[ ]");
			addstrAlt(" F - Stalinist Mode: Enable Stalinist Comrade Squad (not fully implemented).");
			moveAlt(21, 4);
		}
		else {// ALLOWSTALIN
			moveAlt(19, 4);
		}// ALLOWSTALIN
		addstrAlt("Press any other key to continue...");
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
		moveAlt(4, 6);
		addstrAlt("New Game of Liberal Crime Squad: Your Agenda");
		moveAlt(7, 0);
		set_color_easy(WHITE_ON_BLACK);
		if (wincondition == WINCONDITION_ELITE)
			addstrAlt("[X]");
		else addstrAlt("[ ]");
		addstrAlt(" A - No Compromise Classic - I will make all our laws Elite Liberal!");
		moveAlt(9, 0);
		if (!classicmode)
			set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		if (wincondition == WINCONDITION_EASY)
			addstrAlt("[X]");
		else addstrAlt("[ ]");
		addstrAlt(" B - Democrat Mode - Most laws must be Elite Liberal, some can be Liberal.");
		moveAlt(13, 4);
		set_color_easy(WHITE_ON_BLACK);
		addstrAlt("Press any other key to continue...");
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
		moveAlt(4, 6);
		addstrAlt("New Game of Liberal Crime Squad: Field Learning");
		set_color_easy(WHITE_ON_BLACK);
		moveAlt(5, 6);
		addstrAlt("(affects Security, Stealth, Disguise, & Driving)");
		moveAlt(8, 0);
		if (fieldskillrate == FIELDSKILLRATE_FAST)
			addstrAlt("[X]");
		else addstrAlt("[ ]");
		addstrAlt(" A - Fast skills - Grinding is Conservative!");
		moveAlt(10, 0);
		if (fieldskillrate == FIELDSKILLRATE_CLASSIC)
			addstrAlt("[X]");
		else addstrAlt("[ ]");
		addstrAlt(" B - Classic - Excellence requires practice.");
		moveAlt(12, 0);
		if (fieldskillrate == FIELDSKILLRATE_HARD)
			addstrAlt("[X]");
		else addstrAlt("[ ]");
		addstrAlt(" C - Hard Mode - Learn from the best, or face arrest!");
		moveAlt(16, 4);
		set_color_easy(WHITE_ON_BLACK);
		addstrAlt("Press any other key to continue...");
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
extern string spaceDashSpace;
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
	const bool male = LCSrandom(2); // whether or not starting gender is male
	char gender = newcr->gender_liberal = newcr->gender_conservative = (male ? GENDER_MALE : GENDER_FEMALE);
	do {
		firstname(first[0], GENDER_NEUTRAL);
		firstname(first[1], GENDER_MALE);
		firstname(first[2], GENDER_FEMALE);
		lastname(last);
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
		moveAlt(4, 6);
		addstrAlt("The Founder of the Liberal Crime Squad");
		moveAlt(7, 2);
		addstrAlt("FIRST NAME: ");
		addstrAlt(first[(int)gender]);
		moveAlt(7, 30);
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		addstrAlt(" (Press A to have your parents reconsider)");
		moveAlt(9, 2);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		addstrAlt("LAST NAME: ");
		addstrAlt(last);
		moveAlt(9, 30);
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		addstrAlt(" (Press B to be born to a different family)");
		moveAlt(11, 2);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		addstrAlt("SEX: ");
		if (newcr->gender_conservative == GENDER_MALE)
		{
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			addstrAlt("Male");
		}
		else if (newcr->gender_conservative == GENDER_FEMALE)
		{
			set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
			addstrAlt("Female");
		}
		else
		{
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			addstrAlt("It's Complicated");
		}
		moveAlt(11, 30);
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		addstrAlt(" (Press C to change your sex at birth)");
		moveAlt(13, 2);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		addstrAlt("HISTORY: ");
		if (choices)
		{
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			addstrAlt("Let Me Choose");
		}
		else
		{
			set_color_easy(RED_ON_BLACK_BRIGHT);
			addstrAlt("Let Fate Decide");
		}
		moveAlt(13, 30);
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		addstrAlt(" (Press D to toggle childhood)");
		if (!multipleCityMode)
		{
			moveAlt(15, 2);
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			addstrAlt("CITY: ");
			addstrAlt(lcityname);
			moveAlt(15, 30);
			set_color_easy(BLACK_ON_BLACK_BRIGHT);
			addstrAlt(" (Press E to relocate)");
		}
		moveAlt(19 - multipleCityMode * 2, 4);
		set_color_easy(WHITE_ON_BLACK);
		addstrAlt("Press any other key when ready to begin...");
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
				lastname(last);
			} while (strcmp(first[0], last) == 0 && strcmp(first[1], last) == 0 && strcmp(first[2], last) == 0);
			continue;
		}
		if (c == 'c')
		{
			if ((newcr->gender_conservative == GENDER_FEMALE && !male) ||
				(newcr->gender_conservative == GENDER_NEUTRAL && male))
				newcr->gender_conservative = GENDER_MALE;
			else if ((newcr->gender_conservative == GENDER_MALE && !male) ||
				(newcr->gender_conservative == GENDER_FEMALE && male))
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
	string allOptions = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
	vector<Question> allQuestions;
	bool firstQuestion = true;
	bool firstAnswer = true;
	Question currentQuestion;
	Choice currentChoice;
	string header = "";
	string header_2 = "";
	string answer = "";
	string answer_2 = "";
	int birth_year = 1984; // default birth year, month, and day in case left undefined
	int birth_month = 1;
	int birth_day = 1;
	for (int i = 0; i < founderQuestions.size(); i++) {
		const string first = founderQuestions[i];
		if (first.substr(0, 6) == "HEADER") {
			if (first.substr(6, 1) == singleSpace) {
				header = first.substr(7);
				header_2 = "";
			}
			else  if (first.substr(6, 2) == "_2") {
				header_2 = first.substr(9);
			}
		}
		else if (first.substr(0, 6) == "ANSWER") {
			if (firstAnswer) {
				if (first.substr(6, 1) == singleSpace) {
					answer = first.substr(7);
					answer_2 = "";
					firstAnswer = false;
				}
				else  if (first.substr(6, 2) == "_2") {
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
					answer_2 = "";
				}
				else  if (first.substr(6, 2) == "_2") {
					answer_2 = first.substr(9);
				}
			}
		}
		else if (first.substr(0, 8) == "QUESTION") {
			if (!firstQuestion) {
				if (first.substr(8, 1) == singleSpace) {
					currentChoice.ANSWER = answer;
					currentChoice.ANSWER_2 = answer_2;
					currentQuestion.choices.push_back(currentChoice);
					allQuestions.push_back(currentQuestion);
					currentQuestion.choices.clear();
					currentChoice.impact.clear();
					currentChoice.ANSWER = "";
					currentChoice.ANSWER_2 = "";
					currentQuestion.HEADER = header;
					currentQuestion.HEADER_2 = header_2;
					currentQuestion.QUESTION = first.substr(9);
					currentQuestion.QUESTION_2 = "";
					firstAnswer = true;
				}
				else if (first.substr(8, 2) == "_2") {
					currentQuestion.QUESTION_2 = first.substr(12);
				}
			}
			else {
				firstQuestion = false;
				firstAnswer = true;
				currentChoice.ANSWER = "";
				currentChoice.ANSWER_2 = "";
				currentQuestion.HEADER = header;
				currentQuestion.HEADER_2 = header_2;
				currentQuestion.QUESTION = first.substr(9);
				currentQuestion.QUESTION_2 = "";
			}
		}
		else {
			bool invalidTag = false;
			Impact currentImpact;
			if (first.substr(0, 6) == "SKILL_") {
				currentImpact.type = SKILL;
				currentImpact.item_to_influcence = getSkillFromString(founderQuestions[i]);
				currentImpact.set_value = getSetValue(founderQuestions[i]);
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
				if (currentImpact.item_to_influcence == -1) {
					invalidTag = true;
				}
			}
			else if (first.substr(0, 10) == "ATTRIBUTE_") {
				currentImpact.type = ATTRIBUTE;
				currentImpact.item_to_influcence = getAttributeFromString(founderQuestions[i]);
				currentImpact.set_value = getSetValue(founderQuestions[i]);
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
				if (currentImpact.item_to_influcence == -1) {
					invalidTag = true;
				}
			}
			else if (first.substr(0, 9) == "STARTING_") {
				currentImpact.type = OTHER;
				currentImpact.set_value = true;
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
				if (first.substr(9, 5) == "MONTH") {
					currentImpact.item_to_influcence = STARTING_MONTH;
				}
				else if (first.substr(9, 3) == "DAY") {
					currentImpact.item_to_influcence = STARTING_DAY;
				}
				else if (first.substr(9, 4) == "YEAR") {
					currentImpact.item_to_influcence = STARTING_YEAR;
				}
				else {
					invalidTag = true;
				}
			}
			else if (first.substr(0, 9) == "BIRTHDAY_") {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = 0;
				currentImpact.set_value = true;
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
				if (first.substr(9, 5) == "MONTH") {
					currentImpact.item_to_influcence = BIRTH_MONTH;
				}
				else if (first.substr(9, 3) == "DAY") {
					currentImpact.item_to_influcence = BIRTH_DAY;
				}
				else if (first.substr(9, 4) == "YEAR") {
					currentImpact.item_to_influcence = BIRTH_YEAR;
				}
				else {
					invalidTag = true;
				}
			}
			else if (first.substr(0, 5) == "MONEY") {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = MONEY;
				currentImpact.set_value = getSetValue(founderQuestions[i]);
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			}
			else if (first.substr(0, 13) == "DATING_LAWYER") {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = DATING_LAWYER;
				currentImpact.set_value = true;
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			}
			else if (first.substr(0, 3) == "GAY") {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = GAY;
				currentImpact.set_value = true;
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			}
			else if (first.substr(0, 7) == "HASMAPS") {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = HAS_MAPS;
				currentImpact.set_value = true;
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			}
			else if (first.substr(0, 8) == "CREATURE") {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = CREATURE;
				currentImpact.set_value = true;
				currentImpact.magnitude = getCreatureFromString(founderQuestions[i].substr(9));
			}
			else if (first.substr(0, 4) == "BASE") {
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
			else if (first.substr(0, 5) == "JUICE") {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = JUICE;
				currentImpact.set_value = getSetValue(founderQuestions[i]);
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			}
			else if (first.substr(0, 13) == "RECRUITS_GANG") {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = RECRUITS;
				currentImpact.set_value = true;
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			}
			else if (first.substr(0, 13) == "ASSAULT_RIFLE") {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = ASSAULT_RIFLE;
				currentImpact.set_value = true;
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			}
			else if (first.substr(0, 10) == "SPORTS_CAR") {
				currentImpact.type = OTHER;
				currentImpact.item_to_influcence = SPORTS_CAR;
				currentImpact.set_value = true;
				currentImpact.magnitude = getMagnitudeFromString(founderQuestions[i]);
			}
			else {
				clearAlt();
				addstrAlt("INVALID TAG ");
				addstrAlt(founderQuestions[i]);
				getkey();
				clearAlt();
			}
			if (invalidTag) {
				clearAlt();
				addstrAlt("INVALID TAG ");
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
		moveZeroZero();
		addstrAlt(allQuestions[i].HEADER);
		moveOneZero();
		addstrAlt(allQuestions[i].HEADER_2);
		set_color_easy(WHITE_ON_BLACK);
		moveAlt(2, 0);
		addstrAlt(allQuestions[i].QUESTION);
		moveAlt(3, 0);
		addstrAlt(allQuestions[i].QUESTION_2);
		if (i == 0) {
			moveAlt(17, 0);
			addstrAlt("The doctor said I was ");
			set_color(COLOR_WHITE, COLOR_BLACK, 1);
			if (newcr->gender_conservative == GENDER_MALE)
				addstrAlt("a boy");
			else if (newcr->gender_conservative == GENDER_FEMALE)
				addstrAlt("a girl");
			else
				addstrAlt("an intersex baby");
			set_color(COLOR_WHITE, COLOR_BLACK, 0);
			addstrAlt(singleDot);
			moveAlt(19, 0);
			addstrAlt("My parents ");
			if (newcr->gender_conservative == GENDER_NEUTRAL)
			{
				addstrAlt("insisted otherwise.");
				moveAlt(20, 0);
				addstrAlt("They ");
			}
			addstrAlt("named me ");
			set_color(COLOR_WHITE, COLOR_BLACK, 1);
			addstrAlt(newcr->propername);
			set_color(COLOR_WHITE, COLOR_BLACK, 0);
			addstrAlt(singleDot);
		}

		// print answers
		char selection;
		if (!choices) {
			int offset = LCSrandom(allQuestions[i].choices.size());
			selection = 'a' + offset;
			string currentOption = spaceDashSpace;
			moveAlt(5 + 2 * offset, 0);
			addstrAlt(allOptions.substr(offset, 1));
			addstrAlt(currentOption);
			addstrAlt(allQuestions[i].choices[offset].ANSWER);
			moveAlt(6 + 2 * offset, 0);
			addstrAlt(allQuestions[i].choices[offset].ANSWER_2);
			getkey();
		}
		else {
			for (int j = 0; j < allQuestions[i].choices.size(); j++) {
				string currentOption = spaceDashSpace;
				moveAlt(5 + 2 * j, 0);
				addstrAlt(allOptions.substr(j, 1));
				addstrAlt(currentOption);
				addstrAlt(allQuestions[i].choices[j].ANSWER);
				moveAlt(6 + 2 * j, 0);
				addstrAlt(allQuestions[i].choices[j].ANSWER_2);
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
				moveZeroZero();
				addstrAlt("ERROR");
				moveOneZero();
				addstrAlt(currentImpact.item_to_influcence);
				break;
			}
			break;
		default:
			clearAlt();
			moveZeroZero();
			addstrAlt("ERROR");
			moveOneZero();
			addstrAlt(currentImpact.type);
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
		startcar = new Vehicle(*vehicletype[getvehicletype("SPORTSCAR")]);
		startcar->add_heat(10);
		vehicle.push_back(startcar);
		newcr->pref_carid = startcar->id();
	}
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(2, 2);
	addstrAlt("A NEW CONSERVATIVE ERA", gamelog);
	gamelog.newline();
	set_color_easy(WHITE_ON_BLACK);
	moveAlt(4, 2);
	addstrAlt("The Year is ", gamelog);
	addstrAlt(year, gamelog);
	addstrAlt(singleDot, gamelog);
	moveAlt(6, 2);
	gamelog.newline();
	addstrAlt("Conservative President ", gamelog);
	char president[80];
	generate_name(president, GENDER_WHITEMALEPATRIARCH);
	addstrAlt(president, gamelog);
	addstrAlt(" ends his second term with approval", gamelog);
	moveAlt(7, 2);
	gamelog.newline();
	addstrAlt("ratings in the high 70s, and is succeeded by hardcore Arch-Conservative", gamelog);
	moveAlt(8, 2);
	gamelog.newline();
	addstrAlt(execname[EXEC_PRESIDENT], gamelog);
	addstrAlt(singleDot, gamelog);
	gamelog.nextMessage();
	moveAlt(10, 2);
	addstrAlt("With Conservatives sweeping into power in the House of Representatives", gamelog);
	moveAlt(11, 2);
	gamelog.newline();
	addstrAlt("and Senate, and a Conservative majority in the Supreme Court of the", gamelog);
	moveAlt(12, 2);
	gamelog.newline();
	addstrAlt("United States, commentators are hailing it as the beginning of a new", gamelog);
	moveAlt(13, 2);
	gamelog.newline();
	addstrAlt("Conservative era.", gamelog);
	gamelog.nextMessage();
	moveAlt(15, 2);
	set_color_easy(RED_ON_BLACK_BRIGHT);
	addstrAlt("President ", gamelog);
	addstrAlt(execname[EXEC_PRESIDENT], gamelog);
	addstrAlt(" has asked the new Congress to move quickly", gamelog);
	moveAlt(16, 2);
	gamelog.newline();
	addstrAlt("to rubber stamp his radical Arch-Conservative agenda. ", gamelog);
	set_color_easy(WHITE_ON_BLACK);
	addstrAlt("The left seems", gamelog);
	gamelog.newline();
	moveAlt(17, 2);
	addstrAlt("powerless to stop this imminent trampling of Liberal Sanity and Justice.", gamelog);
	gamelog.nextMessage();
	moveAlt(19, 2);
	addstrAlt("In this dark time, the Liberal Crime Squad is born...", gamelog);
	gamelog.nextMessage();
	getkey();
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveZeroZero();
	addstrAlt("What is your name to the People?");
	set_color_easy(WHITE_ON_BLACK);
	moveOneZero();
	addstrAlt("Press enter to be known by your real name instead.");
	enter_name(2, 0, newcr->name, CREATURE_NAMELEN, newcr->propername);
	pool.push_back(newcr);
	make_world(hasmaps);
	squadst *newsq = new squadst;
	newsq->id = 0; cursquadid++;
	newsq->squad[0] = newcr;
	newcr->squadid = 0;
	strcpy(newsq->name, "The Liberal Crime Squad");
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
