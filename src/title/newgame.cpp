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

#include <externs.h>

#include "common\\set_color_support.h"
extern vector<string> founderQuestions;

/* select new game options */
static bool getSetValue(string s);
static int getMagnitudeFromString(string s);
static int getSkillFromString(string s);
static int getAttributeFromString(string s);
static int getCreatureFromString(string s);
static int getBaseFromString(string s);
static string enumToCreatureString(int i);
void setup_newgame()
{
	//TODO IsaacG Get rid of these "while(true) break;" loops
	music.play(MUSIC_NEWGAME);
	bool classicmode = false;
	bool strongccs = false;
	bool nightmarelaws = false;
	multipleCityMode = false;
	stalinmode = false;

	clear();
	while (true)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		move(4, 6);
		addstr("New Game of Liberal Crime Squad: Advanced Gameplay Options");
		move(7, 0);
		set_color_easy(WHITE_ON_BLACK);
		if (classicmode)
			addstr("[X]");
		else addstr("[ ]");
		addstr(" A - Classic Mode: No Conservative Crime Squad.");
		move(9, 0);
		if (!classicmode)
			set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		if (strongccs)
			addstr("[X]");
		else addstr("[ ]");
		addstr(" B - We Didn't Start The Fire: The CCS starts active and extremely strong.");
		move(11, 0);
		set_color_easy(WHITE_ON_BLACK);
		if (nightmarelaws)
			addstr("[X]");
		else addstr("[ ]");
		addstr(" C - Nightmare Mode: Liberalism is forgotten. Is it too late to fight back?");
		move(13, 0);
		set_color_easy(WHITE_ON_BLACK);
		if (multipleCityMode)
			addstr("[X]");
		else addstr("[ ]");
		addstr(" D - National LCS: Advanced play across multiple cities.");
		move(15, 0);
		if (nocourtpurge)
			addstr("[X]");
		else addstr("[ ]");
		addstr(" E - Marathon Mode: Prevent Liberals from amending the Constitution.");
#ifdef ALLOWSTALIN
		move(17, 0);
		if (stalinmode)
			addstr("[X]");
		else addstr("[ ]");
		addstr(" F - Stalinist Mode: Enable Stalinist Comrade Squad (not fully implemented).");
		move(21, 4);
#else // ALLOWSTALIN
		move(19, 4);
#endif // ALLOWSTALIN
		addstr("Press any other key to continue...");

		int c = getkey();

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
#ifdef ALLOWSTALIN
		if (c == 'f')
		{
			stalinmode = !stalinmode;
			continue;
		}
#endif
		break;
	}
	if (nightmarelaws)
	{
		for (int l = 0; l < LAWNUM; l++)
			law[l] = ALIGN_ARCHCONSERVATIVE;
		for (int a = 0; a < VIEWNUM-3; a++)
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

	clear();
	while (true)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		move(4, 6);
		addstr("New Game of Liberal Crime Squad: Your Agenda");
		move(7, 0);
		set_color_easy(WHITE_ON_BLACK);
		if (wincondition == WINCONDITION_ELITE)
			addstr("[X]");
		else addstr("[ ]");
		addstr(" A - No Compromise Classic - I will make all our laws Elite Liberal!");
		move(9, 0);
		if (!classicmode)
			set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		if (wincondition == WINCONDITION_EASY)
			addstr("[X]");
		else addstr("[ ]");
		addstr(" B - Democrat Mode - Most laws must be Elite Liberal, some can be Liberal.");
		move(13, 4);
		set_color_easy(WHITE_ON_BLACK);
		addstr("Press any other key to continue...");

		int c = getkey();

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

	clear();
	while (true)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		move(4, 6);
		addstr("New Game of Liberal Crime Squad: Field Learning");
		set_color_easy(WHITE_ON_BLACK);
		move(5, 6);
		addstr("(affects Security, Stealth, Disguise, & Driving)");
		move(8, 0);
		if (fieldskillrate == FIELDSKILLRATE_FAST)
			addstr("[X]");
		else addstr("[ ]");
		addstr(" A - Fast skills - Grinding is Conservative!");
		move(10, 0);
		if (fieldskillrate == FIELDSKILLRATE_CLASSIC)
			addstr("[X]");
		else addstr("[ ]");
		addstr(" B - Classic - Excellence requires practice.");
		move(12, 0);
		if (fieldskillrate == FIELDSKILLRATE_HARD)
			addstr("[X]");
		else addstr("[ ]");
		addstr(" C - Hard Mode - Learn from the best, or face arrest!");
		move(16, 4);
		set_color_easy(WHITE_ON_BLACK);
		addstr("Press any other key to continue...");

		int c = getkey();

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
#ifdef BLIND
	newcr->special[SPECIALWOUND_RIGHTEYE] = 1;
	newcr->special[SPECIALWOUND_LEFTEYE] = 1;
#endif
#ifdef SPINE
	newcr->special[SPECIALWOUND_UPPERSPINE] = 1;
	newcr->special[SPECIALWOUND_LOWERSPINE] = 1;
#endif
#ifdef NOFACE
	newcr->special[SPECIALWOUND_TONGUE] = 1;
	newcr->special[SPECIALWOUND_RIGHTEYE] = 1;
	newcr->special[SPECIALWOUND_LEFTEYE] = 1;
	newcr->special[SPECIALWOUND_NOSE] = 1;
#endif
#ifdef NOWALK
	newcr->special[SPECIALWOUND_UPPERSPINE] = 1;
	newcr->special[SPECIALWOUND_LOWERSPINE] = 1;
	newcr->special[SPECIALWOUND_NECK] = 1;
	newcr->wound[BODYPART_LEG_RIGHT] = 1;
	newcr->wound[BODYPART_LEG_LEFT] = 1;
#endif
#ifdef INTERNAL
	newcr->special[SPECIALWOUND_RIGHTLUNG] = 1;
	newcr->special[SPECIALWOUND_LEFTLUNG] = 1;
	newcr->special[SPECIALWOUND_HEART] = 1;
	newcr->special[SPECIALWOUND_LIVER] = 1;
	newcr->special[SPECIALWOUND_STOMACH] = 1;
	newcr->special[SPECIALWOUND_LEFTKIDNEY] = 1;
	newcr->special[SPECIALWOUND_RIGHTKIDNEY] = 1;
	newcr->special[SPECIALWOUND_SPLEEN] = 1;
#endif

	char first[3][80];
	char last[80];
	bool male = LCSrandom(2); // whether or not starting gender is male
	char gender = newcr->gender_liberal = newcr->gender_conservative = (male ? GENDER_MALE : GENDER_FEMALE);
	do {
		firstname(first[0], GENDER_NEUTRAL);
		firstname(first[1], GENDER_MALE);
		firstname(first[2], GENDER_FEMALE);
		lastname(last);
	} while (strcmp(first[0], last) == 0 && strcmp(first[1], last) == 0 && strcmp(first[2], last) == 0);

	{
		Armor a(*armortype[getarmortype("ARMOR_CLOTHES")]);
		newcr->give_armor(a, NULL);
	}

	bool choices = true;

	while (true)
	{
		erase();

		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		move(4, 6);
		addstr("The Founder of the Liberal Crime Squad");

		move(7, 2);
		addstr("FIRST NAME: ");
		addstr(first[(int)gender]);
		move(7, 30);
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		addstr(" (Press A to have your parents reconsider)");

		move(9, 2);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		addstr("LAST NAME: ");
		addstr(last);
		move(9, 30);
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		addstr(" (Press B to be born to a different family)");

		move(11, 2);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		addstr("SEX: ");
		if (newcr->gender_conservative == GENDER_MALE)
		{
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			addstr("Male");
		}
		else if (newcr->gender_conservative == GENDER_FEMALE)
		{
			set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
			addstr("Female");
		}
		else
		{
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			addstr("It's Complicated");
		}
		move(11, 30);
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		addstr(" (Press C to change your sex at birth)");

		move(13, 2);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		addstr("HISTORY: ");
		if (choices)
		{
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			addstr("Let Me Choose");
		}
		else
		{
			set_color_easy(RED_ON_BLACK_BRIGHT);
			addstr("Let Fate Decide");
		}
		move(13, 30);
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		addstr(" (Press D to toggle childhood)");

		if (!multipleCityMode)
		{
			move(15, 2);
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			addstr("CITY: ");
			addstr(lcityname);
			move(15, 30);
			set_color_easy(BLACK_ON_BLACK_BRIGHT);
			addstr(" (Press E to relocate)");
		}

		move(19 - multipleCityMode * 2, 4);
		set_color_easy(WHITE_ON_BLACK);
		addstr("Press any other key when ready to begin...");

		int c = getkey();

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
	strcat(newcr->propername, " ");
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
	int MAX_CHOICES = 10;
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
		string first = founderQuestions[i];
		if (first.substr(0, 6) == "HEADER") {
			if (first.substr(6, 1) == " ") {
				header = first.substr(7);
				header_2 = "";
			}
			else  if (first.substr(6, 2) == "_2") {
				header_2 = first.substr(9);
			}
		}
		else if (first.substr(0, 6) == "ANSWER") {
			if (firstAnswer) {

				if (first.substr(6, 1) == " ") {
					answer = first.substr(7);
					answer_2 = "";
					firstAnswer = false;
				}
				else  if (first.substr(6, 2) == "_2") {
					answer_2 = first.substr(9);
				}
			}
			else {
				if (first.substr(6, 1) == " ") {
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
				if (first.substr(8, 1) == " ") {
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
			else if (first.substr(0, 5) == "ARMOR") {
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
				clear();
				addstr("INVALID TAG ");
				addstr(founderQuestions[i]);
				getkey();
				clear();
			}
			if (invalidTag) {
				clear();
				addstr("INVALID TAG ");
				addstr(founderQuestions[i]);
				getkey();
				clear();
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
		clear();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		move(0, 0);
		addstr(allQuestions[i].HEADER);
		move(1, 0);
		addstr(allQuestions[i].HEADER_2);
		set_color_easy(WHITE_ON_BLACK);
		move(2, 0);
		addstr(allQuestions[i].QUESTION);
		move(3, 0);
		addstr(allQuestions[i].QUESTION_2);
		// print answers
		char selection;
		if (!choices) {
			int offset = LCSrandom(allQuestions[i].choices.size());
			selection = 'a' + offset;
			string currentOption = " - ";
			move(5 + 2 * offset, 0);
			addstr(allOptions.substr(offset, 1));
			addstr(currentOption);
			addstr(allQuestions[i].choices[offset].ANSWER);
			move(6 + 2 * offset, 0);
			addstr(allQuestions[i].choices[offset].ANSWER_2);
			getkey();
		}
		else {
			for (int j = 0; j < allQuestions[i].choices.size(); j++) {
				string currentOption = " - ";
				move(5 + 2 * j, 0);
				addstr(allOptions.substr(j, 1));
				addstr(currentOption);
				addstr(allQuestions[i].choices[j].ANSWER);
				move(6 + 2 * j, 0);
				addstr(allQuestions[i].choices[j].ANSWER_2);

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
		Impact currentImpact = impactsToApply[i];
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
				clear();
				move(0, 0);
				addstr("ERROR");
				move(1, 0);
				addstr(currentImpact.item_to_influcence);
				break;
			}

			break;
		default:

			clear();
			move(0, 0);
			addstr("ERROR");
			move(1, 0);
			addstr(currentImpact.type);
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
		Weapon neww(*weapontype[getweapontype("WEAPON_AUTORIFLE_AK47")]);
		Clip newc(*cliptype[getcliptype("CLIP_ASSAULT")], 9);
		newcr->give_weapon(neww, NULL);
		newcr->take_clips(newc, 9);
	}
	if (sports_car) {

		startcar = new Vehicle(*vehicletype[getvehicletype("SPORTSCAR")]);
		startcar->add_heat(10);
		vehicle.push_back(startcar);
		newcr->pref_carid = startcar->id();
	}
	erase();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	move(2, 2);
	addstr("A NEW CONSERVATIVE ERA", gamelog);
	gamelog.newline();

	set_color_easy(WHITE_ON_BLACK);
	move(4, 2);
	addstr("The Year is ", gamelog);
	addstr(year, gamelog);
	addstr(".", gamelog);
	move(6, 2);
	gamelog.newline();
	addstr("Conservative President ", gamelog);
	char president[80];
	generate_name(president, GENDER_WHITEMALEPATRIARCH);
	addstr(president, gamelog);
	addstr(" ends his second term with approval", gamelog);
	move(7, 2);
	gamelog.newline();
	addstr("ratings in the high 70s, and is succeeded by hardcore Arch-Conservative", gamelog);
	move(8, 2);
	gamelog.newline();
	addstr(execname[EXEC_PRESIDENT], gamelog);
	addstr(".", gamelog);
	gamelog.nextMessage();

	move(10, 2);
	addstr("With Conservatives sweeping into power in the House of Representatives", gamelog);
	move(11, 2);
	gamelog.newline();
	addstr("and Senate, and a Conservative majority in the Supreme Court of the", gamelog);
	move(12, 2);
	gamelog.newline();
	addstr("United States, commentators are hailing it as the beginning of a new", gamelog);
	move(13, 2);
	gamelog.newline();
	addstr("Conservative era.", gamelog);
	gamelog.nextMessage();

	move(15, 2);
	set_color_easy(RED_ON_BLACK_BRIGHT);
	addstr("President ", gamelog);
	addstr(execname[EXEC_PRESIDENT], gamelog);
	addstr(" has asked the new Congress to move quickly", gamelog);
	move(16, 2);
	gamelog.newline();
	addstr("to rubber stamp his radical Arch-Conservative agenda. ", gamelog);
	set_color_easy(WHITE_ON_BLACK);
	addstr("The left seems", gamelog);
	gamelog.newline();
	move(17, 2);
	addstr("powerless to stop this imminent trampling of Liberal Sanity and Justice.", gamelog);
	gamelog.nextMessage();

	move(19, 2);
	addstr("In this dark time, the Liberal Crime Squad is born...", gamelog);
	gamelog.nextMessage();

	getkey();

	erase();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	move(0, 0);
	addstr("What is your name to the People?");
	set_color_easy(WHITE_ON_BLACK);
	move(1, 0);
	addstr("Press enter to be known by your real name instead.");

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
					if (recruit->get_weapon().get_itemtypename() == "WEAPON_AUTORIFLE_AK47" ||
						recruit->get_weapon().get_itemtypename() == "WEAPON_SMG_MP5" ||
						!recruit->is_armed())
					{
						Weapon w(*weapontype[getweapontype("WEAPON_SEMIPISTOL_9MM")]);
						recruit->give_weapon(w, NULL);
						Clip c(*cliptype[getcliptype("CLIP_9")], 4);
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

#ifdef GIVEBLOODYARMOR
			Armor *newa = new Armor(*armortype[getarmortype("ARMOR_CLOTHES")]);
			newa->set_bloody(true);
			location[l]->loot.push_back(newi);
#endif

#ifdef HIGHFUNDS
			ledger.force_funds(100000);
#endif

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
static bool getSetValue(string s) {
	int j = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			j = i;
			break;
		}
	}
	return j > -1 && (s[j] == '-' || s[j] == '+');
}
static int getMagnitudeFromString(string s) {
	bool spaceUnfound = true;
	int j = 0;
	for (int i = s.size() - 2; i > 0 && spaceUnfound; i--) {
		if (s[i] == ' ') {
			spaceUnfound = false;
			j = i;

		}
	}
	if (spaceUnfound) {
		clear();
		move(0, 0);
		addstr("ERROR");
		move(1, 0);
		addstr(s);
		getkey();
	}
	return atoi(s.substr(j));
}
static int getSkillFromString(string s) {
	if (s.substr(0, 9) == "SKILL_ART") {
		return SKILL_ART;
	}
	else if (s.substr(0, 9) == "SKILL_AXE") {
		return SKILL_AXE;
	}
	else if (s.substr(0, 14) == "SKILL_BUSINESS") {
		return SKILL_BUSINESS;
	}
	else if (s.substr(0, 10) == "SKILL_CLUB") {
		return SKILL_CLUB;
	}
	else if (s.substr(0, 15) == "SKILL_COMPUTERS") {
		return SKILL_COMPUTERS;
	}
	else if (s.substr(0, 14) == "SKILL_DISGUISE") {
		return SKILL_DISGUISE;
	}
	else if (s.substr(0, 11) == "SKILL_DODGE") {
		return SKILL_DODGE;
	}
	else if (s.substr(0, 13) == "SKILL_DRIVING") {
		return SKILL_DRIVING;
	}
	else if (s.substr(0, 14) == "SKILL_FIRSTAID") {
		return SKILL_FIRSTAID;
	}
	else if (s.substr(0, 18) == "SKILL_HEAVYWEAPONS") {
		return SKILL_HEAVYWEAPONS;
	}
	else if (s.substr(0, 11) == "SKILL_KNIFE") {
		return SKILL_KNIFE;
	}
	else if (s.substr(0, 9) == "SKILL_LAW") {
		return SKILL_LAW;
	}
	else if (s.substr(0, 16) == "SKILL_HANDTOHAND") {
		return SKILL_HANDTOHAND;
	}
	else if (s.substr(0, 11) == "SKILL_MUSIC") {
		return SKILL_MUSIC;
	}
	else if (s.substr(0, 16) == "SKILL_PERSUASION") {
		return SKILL_PERSUASION;
	}
	else if (s.substr(0, 12) == "SKILL_PISTOL") {
		return SKILL_PISTOL;
	}
	else if (s.substr(0, 16) == "SKILL_PSYCHOLOGY") {
		return SKILL_PSYCHOLOGY;
	}
	else if (s.substr(0, 14) == "SKILL_RELIGION") {
		return SKILL_RELIGION;
	}
	else if (s.substr(0, 11) == "SKILL_RIFLE") {
		return SKILL_RIFLE;
	}
	else if (s.substr(0, 13) == "SKILL_SCIENCE") {
		return SKILL_SCIENCE;
	}
	else if (s.substr(0, 14) == "SKILL_SECURITY") {
		return SKILL_SECURITY;
	}
	else if (s.substr(0, 15) == "SKILL_SEDUCTION") {
		return SKILL_SEDUCTION;
	}
	else if (s.substr(0, 13) == "SKILL_SHOTGUN") {
		return SKILL_SHOTGUN;
	}
	else if (s.substr(0, 9) == "SKILL_SMG") {
		return SKILL_SMG;
	}
	else if (s.substr(0, 13) == "SKILL_STEALTH") {
		return SKILL_STEALTH;
	}
	else if (s.substr(0, 17) == "SKILL_STREETSENSE") {
		return SKILL_STREETSENSE;
	}
	else if (s.substr(0, 11) == "SKILL_SWORD") {
		return SKILL_SWORD;
	}
	else if (s.substr(0, 15) == "SKILL_TAILORING") {
		return SKILL_TAILORING;
	}
	else if (s.substr(0, 14) == "SKILL_TEACHING") {
		return SKILL_TEACHING;
	}
	else if (s.substr(0, 14) == "SKILL_THROWING") {
		return SKILL_THROWING;
	}
	else if (s.substr(0, 13) == "SKILL_WRITING") {
		return SKILL_WRITING;
	}
	else {
		return -1;
	}
}
static int getAttributeFromString(string s) {
	if (s.substr(0, 15) == "ATTRIBUTE_HEART") {
		return ATTRIBUTE_HEART;
	}
	else if (s.substr(0, 16) == "ATTRIBUTE_WISDOM") {
		return ATTRIBUTE_WISDOM;
	}
	else if (s.substr(0, 22) == "ATTRIBUTE_INTELLIGENCE") {
		return ATTRIBUTE_INTELLIGENCE;
	}
	else if (s.substr(0, 17) == "ATTRIBUTE_AGILITY") {
		return ATTRIBUTE_AGILITY;
	}
	else if (s.substr(0, 18) == "ATTRIBUTE_STRENGTH") {
		return ATTRIBUTE_STRENGTH;
	}
	else if (s.substr(0, 16) == "ATTRIBUTE_HEALTH") {
		return ATTRIBUTE_HEALTH;
	}
	else if (s.substr(0, 18) == "ATTRIBUTE_CHARISMA") {
		return ATTRIBUTE_CHARISMA;
	}
	else {
		return -1;
	}
}
static int getCreatureFromString(string s) {
	if (s.substr(0, 16) == "CREATURE_BOUNCER") {
		return CREATURE_BOUNCER;
	}
	else if (s.substr(0, 22) == "CREATURE_SECURITYGUARD") {
		return CREATURE_SECURITYGUARD;
	}
	else if (s.substr(0, 26) == "CREATURE_SCIENTIST_LABTECH") {
		return CREATURE_SCIENTIST_LABTECH;
	}
	else if (s.substr(0, 26) == "CREATURE_SCIENTIST_EMINENT") {
		return CREATURE_SCIENTIST_EMINENT;
	}
	else if (s.substr(0, 26) == "CREATURE_CORPORATE_MANAGER") {
		return CREATURE_CORPORATE_MANAGER;
	}
	else if (s.substr(0, 22) == "CREATURE_CORPORATE_CEO") {
		return CREATURE_CORPORATE_CEO;
	}
	else if (s.substr(0, 23) == "CREATURE_WORKER_SERVANT") {
		return CREATURE_WORKER_SERVANT;
	}
	else if (s.substr(0, 23) == "CREATURE_WORKER_JANITOR") {
		return CREATURE_WORKER_JANITOR;
	}
	else if (s.substr(0, 25) == "CREATURE_WORKER_SWEATSHOP") {
		return CREATURE_WORKER_SWEATSHOP;
	}
	else if (s.substr(0, 32) == "CREATURE_WORKER_FACTORY_NONUNION") {
		return CREATURE_WORKER_FACTORY_NONUNION;
	}
	else if (s.substr(0, 29) == "CREATURE_WORKER_FACTORY_CHILD") {
		return CREATURE_WORKER_FACTORY_CHILD;
	}
	else if (s.substr(0, 25) == "CREATURE_WORKER_SECRETARY") {
		return CREATURE_WORKER_SECRETARY;
	}
	else if (s.substr(0, 29) == "CREATURE_WORKER_FACTORY_UNION") {
		return CREATURE_WORKER_FACTORY_UNION;
	}
	else if (s.substr(0, 17) == "CREATURE_LANDLORD") {
		return CREATURE_LANDLORD;
	}
	else if (s.substr(0, 17) == "CREATURE_TEENAGER") {
		return CREATURE_TEENAGER;
	}
	else if (s.substr(0, 12) == "CREATURE_COP") {
		return CREATURE_COP;
	}
	else if (s.substr(0, 13) == "CREATURE_SWAT") {
		return CREATURE_SWAT;
	}
	else if (s.substr(0, 19) == "CREATURE_DEATHSQUAD") {
		return CREATURE_DEATHSQUAD;
	}
	else if (s.substr(0, 20) == "CREATURE_FIREFIGHTER") {
		return CREATURE_FIREFIGHTER;
	}
	else if (s.substr(0, 17) == "CREATURE_EDUCATOR") {
		return CREATURE_EDUCATOR;
	}
	else if (s.substr(0, 17) == "CREATURE_GANGUNIT") {
		return CREATURE_GANGUNIT;
	}
	else if (s.substr(0, 22) == "CREATURE_JUDGE_LIBERAL") {
		return CREATURE_JUDGE_LIBERAL;
	}
	else if (s.substr(0, 27) == "CREATURE_JUDGE_CONSERVATIVE") {
		return CREATURE_JUDGE_CONSERVATIVE;
	}
	else if (s.substr(0, 14) == "CREATURE_AGENT") {
		return CREATURE_AGENT;
	}
	else if (s.substr(0, 25) == "CREATURE_RADIOPERSONALITY") {
		return CREATURE_RADIOPERSONALITY;
	}
	else if (s.substr(0, 19) == "CREATURE_NEWSANCHOR") {
		return CREATURE_NEWSANCHOR;
	}
	else if (s.substr(0, 16) == "CREATURE_GENETIC") {
		return CREATURE_GENETIC;
	}
	else if (s.substr(0, 17) == "CREATURE_GUARDDOG") {
		return CREATURE_GUARDDOG;
	}
	else if (s.substr(0, 17) == "CREATURE_PRISONER") {
		return CREATURE_PRISONER;
	}
	else if (s.substr(0, 14) == "CREATURE_JUROR") {
		return CREATURE_JUROR;
	}
	else if (s.substr(0, 15) == "CREATURE_LAWYER") {
		return CREATURE_LAWYER;
	}
	else if (s.substr(0, 20) == "CREATURE_SEWERWORKER") {
		return CREATURE_SEWERWORKER;
	}
	else if (s.substr(0, 23) == "CREATURE_COLLEGESTUDENT") {
		return CREATURE_COLLEGESTUDENT;
	}
	else if (s.substr(0, 17) == "CREATURE_MUSICIAN") {
		return CREATURE_MUSICIAN;
	}
	else if (s.substr(0, 22) == "CREATURE_MATHEMATICIAN") {
		return CREATURE_MATHEMATICIAN;
	}
	else if (s.substr(0, 16) == "CREATURE_TEACHER") {
		return CREATURE_TEACHER;
	}
	else if (s.substr(0, 18) == "CREATURE_HSDROPOUT") {
		return CREATURE_HSDROPOUT;
	}
	else if (s.substr(0, 12) == "CREATURE_BUM") {
		return CREATURE_BUM;
	}
	else if (s.substr(0, 19) == "CREATURE_GANGMEMBER") {
		return CREATURE_GANGMEMBER;
	}
	else if (s.substr(0, 18) == "CREATURE_CRACKHEAD") {
		return CREATURE_CRACKHEAD;
	}
	else if (s.substr(0, 15) == "CREATURE_PRIEST") {
		return CREATURE_PRIEST;
	}
	else if (s.substr(0, 17) == "CREATURE_ENGINEER") {
		return CREATURE_ENGINEER;
	}
	else if (s.substr(0, 23) == "CREATURE_FASTFOODWORKER") {
		return CREATURE_FASTFOODWORKER;
	}
	else if (s.substr(0, 14) == "CREATURE_BAKER") {
		return CREATURE_BAKER;
	}
	else if (s.substr(0, 16) == "CREATURE_BARISTA") {
		return CREATURE_BARISTA;
	}
	else if (s.substr(0, 18) == "CREATURE_BARTENDER") {
		return CREATURE_BARTENDER;
	}
	else if (s.substr(0, 21) == "CREATURE_TELEMARKETER") {
		return CREATURE_TELEMARKETER;
	}
	else if (s.substr(0, 20) == "CREATURE_CARSALESMAN") {
		return CREATURE_CARSALESMAN;
	}
	else if (s.substr(0, 21) == "CREATURE_OFFICEWORKER") {
		return CREATURE_OFFICEWORKER;
	}
	else if (s.substr(0, 22) == "CREATURE_FOOTBALLCOACH") {
		return CREATURE_FOOTBALLCOACH;
	}
	else if (s.substr(0, 19) == "CREATURE_PROSTITUTE") {
		return CREATURE_PROSTITUTE;
	}
	else if (s.substr(0, 16) == "CREATURE_MAILMAN") {
		return CREATURE_MAILMAN;
	}
	else if (s.substr(0, 19) == "CREATURE_GARBAGEMAN") {
		return CREATURE_GARBAGEMAN;
	}
	else if (s.substr(0, 16) == "CREATURE_PLUMBER") {
		return CREATURE_PLUMBER;
	}
	else if (s.substr(0, 13) == "CREATURE_CHEF") {
		return CREATURE_CHEF;
	}
	else if (s.substr(0, 27) == "CREATURE_CONSTRUCTIONWORKER") {
		return CREATURE_CONSTRUCTIONWORKER;
	}
	else if (s.substr(0, 24) == "CREATURE_AMATEURMAGICIAN") {
		return CREATURE_AMATEURMAGICIAN;
	}
	else if (s.substr(0, 13) == "CREATURE_TANK") {
		return CREATURE_TANK;
	}
	else if (s.substr(0, 13) == "CREATURE_MERC") {
		return CREATURE_MERC;
	}
	else if (s.substr(0, 13) == "CREATURE_HICK") {
		return CREATURE_HICK;
	}
	else if (s.substr(0, 16) == "CREATURE_SOLDIER") {
		return CREATURE_SOLDIER;
	}
	else if (s.substr(0, 16) == "CREATURE_VETERAN") {
		return CREATURE_VETERAN;
	}
	else if (s.substr(0, 25) == "CREATURE_HARDENED_VETERAN") {
		return CREATURE_HARDENED_VETERAN;
	}
	else if (s.substr(0, 20) == "CREATURE_PRISONGUARD") {
		return CREATURE_PRISONGUARD;
	}
	else if (s.substr(0, 15) == "CREATURE_HIPPIE") {
		return CREATURE_HIPPIE;
	}
	else if (s.substr(0, 19) == "CREATURE_CRITIC_ART") {
		return CREATURE_CRITIC_ART;
	}
	else if (s.substr(0, 21) == "CREATURE_CRITIC_MUSIC") {
		return CREATURE_CRITIC_MUSIC;
	}
	else if (s.substr(0, 18) == "CREATURE_SOCIALITE") {
		return CREATURE_SOCIALITE;
	}
	else if (s.substr(0, 19) == "CREATURE_PROGRAMMER") {
		return CREATURE_PROGRAMMER;
	}
	else if (s.substr(0, 16) == "CREATURE_RETIREE") {
		return CREATURE_RETIREE;
	}
	else if (s.substr(0, 16) == "CREATURE_PAINTER") {
		return CREATURE_PAINTER;
	}
	else if (s.substr(0, 17) == "CREATURE_SCULPTOR") {
		return CREATURE_SCULPTOR;
	}
	else if (s.substr(0, 15) == "CREATURE_AUTHOR") {
		return CREATURE_AUTHOR;
	}
	else if (s.substr(0, 19) == "CREATURE_JOURNALIST") {
		return CREATURE_JOURNALIST;
	}
	else if (s.substr(0, 15) == "CREATURE_DANCER") {
		return CREATURE_DANCER;
	}
	else if (s.substr(0, 21) == "CREATURE_PHOTOGRAPHER") {
		return CREATURE_PHOTOGRAPHER;
	}
	else if (s.substr(0, 18) == "CREATURE_CAMERAMAN") {
		return CREATURE_CAMERAMAN;
	}
	else if (s.substr(0, 20) == "CREATURE_HAIRSTYLIST") {
		return CREATURE_HAIRSTYLIST;
	}
	else if (s.substr(0, 24) == "CREATURE_FASHIONDESIGNER") {
		return CREATURE_FASHIONDESIGNER;
	}
	else if (s.substr(0, 14) == "CREATURE_CLERK") {
		return CREATURE_CLERK;
	}
	else if (s.substr(0, 14) == "CREATURE_THIEF") {
		return CREATURE_THIEF;
	}
	else if (s.substr(0, 14) == "CREATURE_ACTOR") {
		return CREATURE_ACTOR;
	}
	else if (s.substr(0, 23) == "CREATURE_YOGAINSTRUCTOR") {
		return CREATURE_YOGAINSTRUCTOR;
	}
	else if (s.substr(0, 22) == "CREATURE_MARTIALARTIST") {
		return CREATURE_MARTIALARTIST;
	}
	else if (s.substr(0, 16) == "CREATURE_ATHLETE") {
		return CREATURE_ATHLETE;
	}
	else if (s.substr(0, 14) == "CREATURE_BIKER") {
		return CREATURE_BIKER;
	}
	else if (s.substr(0, 16) == "CREATURE_TRUCKER") {
		return CREATURE_TRUCKER;
	}
	else if (s.substr(0, 19) == "CREATURE_TAXIDRIVER") {
		return CREATURE_TAXIDRIVER;
	}
	else if (s.substr(0, 12) == "CREATURE_NUN") {
		return CREATURE_NUN;
	}
	else if (s.substr(0, 15) == "CREATURE_MUTANT") {
		return CREATURE_MUTANT;
	}
	else if (s.substr(0, 15) == "CREATURE_DOCTOR") {
		return CREATURE_DOCTOR;
	}
	else if (s.substr(0, 14) == "CREATURE_NURSE") {
		return CREATURE_NURSE;
	}
	else if (s.substr(0, 22) == "CREATURE_CCS_VIGILANTE") {
		return CREATURE_CCS_VIGILANTE;
	}
	else if (s.substr(0, 29) == "CREATURE_CCS_ARCHCONSERVATIVE") {
		return CREATURE_CCS_ARCHCONSERVATIVE;
	}
	else if (s.substr(0, 26) == "CREATURE_POLITICALACTIVIST") {
		return CREATURE_POLITICALACTIVIST;
	}
	else if (s.substr(0, 20) == "CREATURE_CCS_MOLOTOV") {
		return CREATURE_CCS_MOLOTOV;
	}
	else if (s.substr(0, 19) == "CREATURE_CCS_SNIPER") {
		return CREATURE_CCS_SNIPER;
	}
	else if (s.substr(0, 21) == "CREATURE_PSYCHOLOGIST") {
		return CREATURE_PSYCHOLOGIST;
	}
	else if (s.substr(0, 18) == "CREATURE_LOCKSMITH") {
		return CREATURE_LOCKSMITH;
	}
	else if (s.substr(0, 23) == "CREATURE_MILITARYPOLICE") {
		return CREATURE_MILITARYPOLICE;
	}
	else if (s.substr(0, 13) == "CREATURE_SEAL") {
		return CREATURE_SEAL;
	}
	else if (s.substr(0, 24) == "CREATURE_MILITARYOFFICER") {
		return CREATURE_MILITARYOFFICER;
	}
	else if (s.substr(0, 20) == "CREATURE_BANK_TELLER") {
		return CREATURE_BANK_TELLER;
	}
	else if (s.substr(0, 21) == "CREATURE_BANK_MANAGER") {
		return CREATURE_BANK_MANAGER;
	}
	else if (s.substr(0, 23) == "CREATURE_SECRET_SERVICE") {
		return CREATURE_SECRET_SERVICE;
	}
	else if (s.substr(0, 19) == "CREATURE_POLITICIAN") {
		return CREATURE_POLITICIAN;
	}
	else {
		return -1;
	}
}
static string enumToCreatureString(int i) {
	switch (i) {
	case CREATURE_BOUNCER:
		return "CREATURE_BOUNCER";
	case CREATURE_SECURITYGUARD:
		return "CREATURE_SECURITYGUARD";
	case CREATURE_SCIENTIST_LABTECH:
		return "CREATURE_SCIENTIST_LABTECH";
	case CREATURE_SCIENTIST_EMINENT:
		return "CREATURE_SCIENTIST_EMINENT";
	case CREATURE_CORPORATE_MANAGER:
		return "CREATURE_CORPORATE_MANAGER";
	case CREATURE_CORPORATE_CEO:
		return "CREATURE_CORPORATE_CEO";
	case CREATURE_WORKER_SERVANT:
		return "CREATURE_WORKER_SERVANT";
	case CREATURE_WORKER_JANITOR:
		return "CREATURE_WORKER_JANITOR";
	case CREATURE_WORKER_SWEATSHOP:
		return "CREATURE_WORKER_SWEATSHOP";
	case CREATURE_WORKER_FACTORY_NONUNION:
		return "CREATURE_WORKER_FACTORY_NONUNION";
	case CREATURE_WORKER_FACTORY_CHILD:
		return "CREATURE_WORKER_FACTORY_CHILD";
	case CREATURE_WORKER_SECRETARY:
		return "CREATURE_WORKER_SECRETARY";
	case CREATURE_WORKER_FACTORY_UNION:
		return "CREATURE_WORKER_FACTORY_UNION";
	case CREATURE_LANDLORD:
		return "CREATURE_LANDLORD";
	case CREATURE_TEENAGER:
		return "CREATURE_TEENAGER";
	case CREATURE_COP:
		return "CREATURE_COP";
	case CREATURE_SWAT:
		return "CREATURE_SWAT";
	case CREATURE_DEATHSQUAD:
		return "CREATURE_DEATHSQUAD";
	case CREATURE_FIREFIGHTER:
		return "CREATURE_FIREFIGHTER";
	case CREATURE_EDUCATOR:
		return "CREATURE_EDUCATOR";
	case CREATURE_GANGUNIT:
		return "CREATURE_GANGUNIT";
	case CREATURE_JUDGE_LIBERAL:
		return "CREATURE_JUDGE_LIBERAL";
	case CREATURE_JUDGE_CONSERVATIVE:
		return "CREATURE_JUDGE_CONSERVATIVE";
	case CREATURE_AGENT:
		return "CREATURE_AGENT";
	case CREATURE_RADIOPERSONALITY:
		return "CREATURE_RADIOPERSONALITY";
	case CREATURE_NEWSANCHOR:
		return "CREATURE_NEWSANCHOR";
	case CREATURE_GENETIC:
		return "CREATURE_GENETIC";
	case CREATURE_GUARDDOG:
		return "CREATURE_GUARDDOG";
	case CREATURE_PRISONER:
		return "CREATURE_PRISONER";
	case CREATURE_JUROR:
		return "CREATURE_JUROR";
	case CREATURE_LAWYER:
		return "CREATURE_LAWYER";
	case CREATURE_SEWERWORKER:
		return "CREATURE_SEWERWORKER";
	case CREATURE_COLLEGESTUDENT:
		return "CREATURE_COLLEGESTUDENT";
	case CREATURE_MUSICIAN:
		return "CREATURE_MUSICIAN";
	case CREATURE_MATHEMATICIAN:
		return "CREATURE_MATHEMATICIAN";
	case CREATURE_TEACHER:
		return "CREATURE_TEACHER";
	case CREATURE_HSDROPOUT:
		return "CREATURE_HSDROPOUT";
	case CREATURE_BUM:
		return "CREATURE_BUM";
	case CREATURE_GANGMEMBER:
		return "CREATURE_GANGMEMBER";
	case CREATURE_CRACKHEAD:
		return "CREATURE_CRACKHEAD";
	case CREATURE_PRIEST:
		return "CREATURE_PRIEST";
	case CREATURE_ENGINEER:
		return "CREATURE_ENGINEER";
	case CREATURE_FASTFOODWORKER:
		return "CREATURE_FASTFOODWORKER";
	case CREATURE_BAKER:
		return "CREATURE_BAKER";
	case CREATURE_BARISTA:
		return "CREATURE_BARISTA";
	case CREATURE_BARTENDER:
		return "CREATURE_BARTENDER";
	case CREATURE_TELEMARKETER:
		return "CREATURE_TELEMARKETER";
	case CREATURE_CARSALESMAN:
		return "CREATURE_CARSALESMAN";
	case CREATURE_OFFICEWORKER:
		return "CREATURE_OFFICEWORKER";
	case CREATURE_FOOTBALLCOACH:
		return "CREATURE_FOOTBALLCOACH";
	case CREATURE_PROSTITUTE:
		return "CREATURE_PROSTITUTE";
	case CREATURE_MAILMAN:
		return "CREATURE_MAILMAN";
	case CREATURE_GARBAGEMAN:
		return "CREATURE_GARBAGEMAN";
	case CREATURE_PLUMBER:
		return "CREATURE_PLUMBER";
	case CREATURE_CHEF:
		return "CREATURE_CHEF";
	case CREATURE_CONSTRUCTIONWORKER:
		return "CREATURE_CONSTRUCTIONWORKER";
	case CREATURE_AMATEURMAGICIAN:
		return "CREATURE_AMATEURMAGICIAN";
	case CREATURE_TANK:
		return "CREATURE_TANK";
	case CREATURE_MERC:
		return "CREATURE_MERC";
	case CREATURE_HICK:
		return "CREATURE_HICK";
	case CREATURE_SOLDIER:
		return "CREATURE_SOLDIER";
	case CREATURE_VETERAN:
		return "CREATURE_VETERAN";
	case CREATURE_HARDENED_VETERAN:
		return "CREATURE_HARDENED_VETERAN";
	case CREATURE_PRISONGUARD:
		return "CREATURE_PRISONGUARD";
	case CREATURE_HIPPIE:
		return "CREATURE_HIPPIE";
	case CREATURE_CRITIC_ART:
		return "CREATURE_CRITIC_ART";
	case CREATURE_CRITIC_MUSIC:
		return "CREATURE_CRITIC_MUSIC";
	case CREATURE_SOCIALITE:
		return "CREATURE_SOCIALITE";
	case CREATURE_PROGRAMMER:
		return "CREATURE_PROGRAMMER";
	case CREATURE_RETIREE:
		return "CREATURE_RETIREE";
	case CREATURE_PAINTER:
		return "CREATURE_PAINTER";
	case CREATURE_SCULPTOR:
		return "CREATURE_SCULPTOR";
	case CREATURE_AUTHOR:
		return "CREATURE_AUTHOR";
	case CREATURE_JOURNALIST:
		return "CREATURE_JOURNALIST";
	case CREATURE_DANCER:
		return "CREATURE_DANCER";
	case CREATURE_PHOTOGRAPHER:
		return "CREATURE_PHOTOGRAPHER";
	case CREATURE_CAMERAMAN:
		return "CREATURE_CAMERAMAN";
	case CREATURE_HAIRSTYLIST:
		return "CREATURE_HAIRSTYLIST";
	case CREATURE_FASHIONDESIGNER:
		return "CREATURE_FASHIONDESIGNER";
	case CREATURE_CLERK:
		return "CREATURE_CLERK";
	case CREATURE_THIEF:
		return "CREATURE_THIEF";
	case CREATURE_ACTOR:
		return "CREATURE_ACTOR";
	case CREATURE_YOGAINSTRUCTOR:
		return "CREATURE_YOGAINSTRUCTOR";
	case CREATURE_MARTIALARTIST:
		return "CREATURE_MARTIALARTIST";
	case CREATURE_ATHLETE:
		return "CREATURE_ATHLETE";
	case CREATURE_BIKER:
		return "CREATURE_BIKER";
	case CREATURE_TRUCKER:
		return "CREATURE_TRUCKER";
	case CREATURE_TAXIDRIVER:
		return "CREATURE_TAXIDRIVER";
	case CREATURE_NUN:
		return "CREATURE_NUN";
	case CREATURE_MUTANT:
		return "CREATURE_MUTANT";
	case CREATURE_DOCTOR:
		return "CREATURE_DOCTOR";
	case CREATURE_NURSE:
		return "CREATURE_NURSE";
	case CREATURE_CCS_VIGILANTE:
		return "CREATURE_CCS_VIGILANTE";
	case CREATURE_CCS_ARCHCONSERVATIVE:
		return "CREATURE_CCS_ARCHCONSERVATIVE";
	case CREATURE_POLITICALACTIVIST:
		return "CREATURE_POLITICALACTIVIST";
	case CREATURE_CCS_MOLOTOV:
		return "CREATURE_CCS_MOLOTOV";
	case CREATURE_CCS_SNIPER:
		return "CREATURE_CCS_SNIPER";
	case CREATURE_PSYCHOLOGIST:
		return "CREATURE_PSYCHOLOGIST";
	case CREATURE_LOCKSMITH:
		return "CREATURE_LOCKSMITH";
	case CREATURE_MILITARYPOLICE:
		return "CREATURE_MILITARYPOLICE";
	case CREATURE_SEAL:
		return "CREATURE_SEAL";
	case CREATURE_MILITARYOFFICER:
		return "CREATURE_MILITARYOFFICER";
	case CREATURE_BANK_TELLER:
		return "CREATURE_BANK_TELLER";
	case CREATURE_BANK_MANAGER:
		return "CREATURE_BANK_MANAGER";
	case CREATURE_SECRET_SERVICE:
		return "CREATURE_SECRET_SERVICE";
	case CREATURE_POLITICIAN:
		return "CREATURE_POLITICIAN";
	default:
		return "";
	}
}
static int getBaseFromString(string s) {
	string baseString = s.substr(5);
	// note this does not include all possible sites, only the ones that can be mapped
	if (baseString.substr(0, 24) == "SITE_RESIDENTIAL_SHELTER") {
		return SITE_RESIDENTIAL_SHELTER;
	}
	else if (baseString.substr(0, 25) == "SITE_RESIDENTIAL_TENEMENT") {
		return SITE_RESIDENTIAL_TENEMENT;
	}
	else if (baseString.substr(0, 26) == "SITE_RESIDENTIAL_APARTMENT") {
		return SITE_RESIDENTIAL_APARTMENT;
	}
	else if (baseString.substr(0, 34) == "SITE_RESIDENTIAL_APARTMENT_UPSCALE") {
		return SITE_RESIDENTIAL_APARTMENT_UPSCALE;
	}
	else if (baseString.substr(0, 28) == "SITE_RESIDENTIAL_BOMBSHELTER") {
		return SITE_RESIDENTIAL_BOMBSHELTER;
	}
	else if (baseString.substr(0, 25) == "SITE_LABORATORY_COSMETICS") {
		return SITE_LABORATORY_COSMETICS;
	}
	else if (baseString.substr(0, 23) == "SITE_LABORATORY_GENETIC") {
		return SITE_LABORATORY_GENETIC;
	}
	else if (baseString.substr(0, 29) == "SITE_GOVERNMENT_POLICESTATION") {
		return SITE_GOVERNMENT_POLICESTATION;
	}
	else if (baseString.substr(0, 26) == "SITE_GOVERNMENT_COURTHOUSE") {
		return SITE_GOVERNMENT_COURTHOUSE;
	}
	else if (baseString.substr(0, 22) == "SITE_GOVERNMENT_PRISON") {
		return SITE_GOVERNMENT_PRISON;
	}
	else if (baseString.substr(0, 30) == "SITE_GOVERNMENT_INTELLIGENCEHQ") {
		return SITE_GOVERNMENT_INTELLIGENCEHQ;
	}
	else if (baseString.substr(0, 27) == "SITE_GOVERNMENT_FIRESTATION") {
		return SITE_GOVERNMENT_FIRESTATION;
	}
	else if (baseString.substr(0, 23) == "SITE_INDUSTRY_SWEATSHOP") {
		return SITE_INDUSTRY_SWEATSHOP;
	}
	else if (baseString.substr(0, 22) == "SITE_INDUSTRY_POLLUTER") {
		return SITE_INDUSTRY_POLLUTER;
	}
	else if (baseString.substr(0, 21) == "SITE_INDUSTRY_NUCLEAR") {
		return SITE_INDUSTRY_NUCLEAR;
	}
	else if (baseString.substr(0, 23) == "SITE_INDUSTRY_WAREHOUSE") {
		return SITE_INDUSTRY_WAREHOUSE;
	}
	else if (baseString.substr(0, 27) == "SITE_CORPORATE_HEADQUARTERS") {
		return SITE_CORPORATE_HEADQUARTERS;
	}
	else if (baseString.substr(0, 20) == "SITE_CORPORATE_HOUSE") {
		return SITE_CORPORATE_HOUSE;
	}
	else if (baseString.substr(0, 18) == "SITE_MEDIA_AMRADIO") {
		return SITE_MEDIA_AMRADIO;
	}
	else if (baseString.substr(0, 20) == "SITE_MEDIA_CABLENEWS") {
		return SITE_MEDIA_CABLENEWS;
	}
	else if (baseString.substr(0, 24) == "SITE_BUSINESS_CRACKHOUSE") {
		return SITE_BUSINESS_CRACKHOUSE;
	}
	else if (baseString.substr(0, 22) == "SITE_BUSINESS_JUICEBAR") {
		return SITE_BUSINESS_JUICEBAR;
	}
	else if (baseString.substr(0, 22) == "SITE_BUSINESS_CIGARBAR") {
		return SITE_BUSINESS_CIGARBAR;
	}
	else if (baseString.substr(0, 24) == "SITE_BUSINESS_LATTESTAND") {
		return SITE_BUSINESS_LATTESTAND;
	}
	else if (baseString.substr(0, 23) == "SITE_BUSINESS_VEGANCOOP") {
		return SITE_BUSINESS_VEGANCOOP;
	}
	else if (baseString.substr(0, 26) == "SITE_BUSINESS_INTERNETCAFE") {
		return SITE_BUSINESS_INTERNETCAFE;
	}
	else if (baseString.substr(0, 25) == "SITE_BUSINESS_BARANDGRILL") {
		return SITE_BUSINESS_BARANDGRILL;
	}
	else if (baseString.substr(0, 23) == "SITE_OUTDOOR_PUBLICPARK") {
		return SITE_OUTDOOR_PUBLICPARK;
	}
	else if (baseString.substr(0, 19) == "SITE_OUTDOOR_BUNKER") {
		return SITE_OUTDOOR_BUNKER;
	}
	else if (baseString.substr(0, 24) == "SITE_GOVERNMENT_ARMYBASE") {
		return SITE_GOVERNMENT_ARMYBASE;
	}
	else if (baseString.substr(0, 18) == "SITE_BUSINESS_BANK") {
		return SITE_BUSINESS_BANK;
	}
	else if (baseString.substr(0, 32) == "SITE_GOVERNMENT_LIBERAL_PARTY_HQ") {
		return SITE_GOVERNMENT_LIBERAL_PARTY_HQ;
	}
	else if (baseString.substr(0, 27) == "SITE_GOVERNMENT_WHITE_HOUSE") {
		return SITE_GOVERNMENT_WHITE_HOUSE;
	}
	else return -1;
}

// IsaacG
// I wrote a program in java to auto generate the contents of the 'getXfromString' functions
// and figured I'd run it on these ones not currently in use, in case someone else
// wants them
static int getSpecialWoundFromString(string s);
static int getSpecialWoundFromString(string s) {
	if (s.substr(0, 18) == "SPECIALWOUND_TEETH") {
		return SPECIALWOUND_TEETH;
	}
	else if (s.substr(0, 21) == "SPECIALWOUND_RIGHTEYE") {
		return SPECIALWOUND_RIGHTEYE;
	}
	else if (s.substr(0, 20) == "SPECIALWOUND_LEFTEYE") {
		return SPECIALWOUND_LEFTEYE;
	}
	else if (s.substr(0, 17) == "SPECIALWOUND_NOSE") {
		return SPECIALWOUND_NOSE;
	}
	else if (s.substr(0, 19) == "SPECIALWOUND_TONGUE") {
		return SPECIALWOUND_TONGUE;
	}
	else if (s.substr(0, 22) == "SPECIALWOUND_RIGHTLUNG") {
		return SPECIALWOUND_RIGHTLUNG;
	}
	else if (s.substr(0, 21) == "SPECIALWOUND_LEFTLUNG") {
		return SPECIALWOUND_LEFTLUNG;
	}
	else if (s.substr(0, 18) == "SPECIALWOUND_HEART") {
		return SPECIALWOUND_HEART;
	}
	else if (s.substr(0, 18) == "SPECIALWOUND_LIVER") {
		return SPECIALWOUND_LIVER;
	}
	else if (s.substr(0, 20) == "SPECIALWOUND_STOMACH") {
		return SPECIALWOUND_STOMACH;
	}
	else if (s.substr(0, 24) == "SPECIALWOUND_RIGHTKIDNEY") {
		return SPECIALWOUND_RIGHTKIDNEY;
	}
	else if (s.substr(0, 23) == "SPECIALWOUND_LEFTKIDNEY") {
		return SPECIALWOUND_LEFTKIDNEY;
	}
	else if (s.substr(0, 19) == "SPECIALWOUND_SPLEEN") {
		return SPECIALWOUND_SPLEEN;
	}
	else if (s.substr(0, 17) == "SPECIALWOUND_RIBS") {
		return SPECIALWOUND_RIBS;
	}
	else if (s.substr(0, 17) == "SPECIALWOUND_NECK") {
		return SPECIALWOUND_NECK;
	}
	else if (s.substr(0, 23) == "SPECIALWOUND_UPPERSPINE") {
		return SPECIALWOUND_UPPERSPINE;
	}
	else if (s.substr(0, 23) == "SPECIALWOUND_LOWERSPINE") {
		return SPECIALWOUND_LOWERSPINE;
	}
}