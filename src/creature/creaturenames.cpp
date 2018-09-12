
#include "../includes.h"
const string CONST_creaturenames008 = "archconservative_last_names.txt";
const string CONST_creaturenames007 = "regular_last_names.txt";
const string CONST_creaturenames006 = "great_white_male_patriarch_first_names.txt";
const string CONST_creaturenames005 = "gender_neutral_first_names.txt";
const string CONST_creaturenames004 = "female_first_names.txt";
const string CONST_creaturenames003 = "male_first_names.txt";

const string blankString = "";
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
// select CONST_creaturenames001, choose CONST_creaturenamesB010,
// then choose CONST_creaturenames002.
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
#include "../creature/creatureEnums.h"
#include "../customMaps.h"
vector<string> male_first_names;
vector<string> female_first_names;
vector<string> gender_neutral_first_names;
vector<string> great_white_male_patriarch_first_names;
vector<string> regular_last_names;
vector<string> archconservative_last_names;
const string names = "names\\";
vector<file_and_text_collection> names_text_file_collection = {
	/*creaturenames.cpp*/
	customText(&male_first_names, names + CONST_creaturenames003),
	customText(&female_first_names, names + CONST_creaturenames004),
	customText(&gender_neutral_first_names, names + CONST_creaturenames005),
	customText(&great_white_male_patriarch_first_names, names + CONST_creaturenames006),
	customText(&regular_last_names, names + CONST_creaturenames007),
	customText(&archconservative_last_names, names + CONST_creaturenames008),
};
extern string closeParenthesis;
extern string singleSpace;
void generate_name(char *first, char *last, char gender);
void firstname(char *str, char gender);
string lastname(bool archconservative);
	/* fills a string with a proper name 
	void generate_name(char *str, char gender)
	{
		char first[80];
		char last[80];
		generate_name(first, last, gender);
		strcpy(str, first);
		strcat(str, singleSpace.data());
		strcat(str, last);
	}
	/* get a first and last name for the same person 
	void generate_name(char *first, char *last, char gender)
	{
		do {
			firstname(first, gender);
			strcpy(last, lastname(gender == GENDER_WHITEMALEPATRIARCH).data());
		} while (strcmp(first, last) == 0);
	}
	/* get a first, middle, and last name for the same person 
	void generate_long_name(char *first, char *middle, char *last, char gender)
	{
		// pick either male or female so we can have 75% chance of first and middle names having matching genders
		if (gender == GENDER_NEUTRAL)
			gender = (LCSrandom(2) ? GENDER_MALE : GENDER_FEMALE);
		do {
			firstname(first, gender);
			if (LCSrandom(2)) // middle name is a first name
				firstname(middle, (gender == GENDER_WHITEMALEPATRIARCH || LCSrandom(2) ? gender : GENDER_NEUTRAL)); // 25% chance for middle name of other gender unless white male patriarch
			else // middle name is a last name
				strcpy(middle, lastname(gender == GENDER_WHITEMALEPATRIARCH).data());
			strcpy(last, lastname(gender == GENDER_WHITEMALEPATRIARCH).data());
		} while (strcmp(first, middle) == 0 && strcmp(first, last) == 0 && strcmp(middle, last) == 0);
	}
	/* gets a random first name 
	void firstname(char *str, char gender)
	{
		const string CONST_creaturenames009 = "Errol";
		strcpy(str, blankString.c_str());
		int roll, nametable;
		// If we don't care if the name is male or female, pick one randomly
		// This ensures gender balance in the names chosen
		if (gender == GENDER_NEUTRAL)
			gender = (LCSrandom(2) ? GENDER_MALE : GENDER_FEMALE);
		// For white male Arch-Conservative politicians
		if (gender == GENDER_WHITEMALEPATRIARCH)
			nametable = GENDER_WHITEMALEPATRIARCH;
		// Assign a name from the available names for each gender
		if (gender == GENDER_MALE)
		{
			// Roll on the number of gender-specific names,
			// plus the number of gender-neutral names
			roll = LCSrandom(len(male_first_names) +
				len(gender_neutral_first_names));
			// Decide whether to use a gender-specific name
			// or a gender-neutral name
			if (roll >= len(gender_neutral_first_names))
				nametable = GENDER_MALE;
			else
				nametable = GENDER_NEUTRAL;
		}
		else if (gender == GENDER_FEMALE)
		{
			// (Same here, just use the number of female names instead)
			roll = LCSrandom(len(female_first_names) +
				len(gender_neutral_first_names));
			if (roll >= len(gender_neutral_first_names))
				nametable = GENDER_FEMALE;
			else
				nametable = GENDER_NEUTRAL;
		}
		if (nametable == GENDER_MALE) {
			//IsaacG string.data() returns the char* representation of the string
			strcat(str, pickrandom(male_first_names).data());
		}
		else if (nametable == GENDER_FEMALE) {
			strcat(str, pickrandom(female_first_names).data());
		}
		else if (nametable == GENDER_NEUTRAL) {
			strcat(str, pickrandom(gender_neutral_first_names).data());
		}
		else if (nametable == GENDER_WHITEMALEPATRIARCH) {
			strcat(str, pickrandom(great_white_male_patriarch_first_names).data());
		}
		else
			strcat(str, CONST_creaturenames009.c_str());
	}
	string lastname(bool archconservative)
		//{{{ Last Name
	{
		char str[80];
		strcpy(str, blankString.c_str());
		// For non-Arch-Conservatives, pick from ALL last names
		if (!archconservative)
		{
			// Roll on the number of non-Arch-Conservative last names,
			// plus the number of regular last names
			int roll = LCSrandom(len(regular_last_names) +
				len(archconservative_last_names));
			// Decide whether to use an Arch-Conservative last name
			// or a regular last name
			archconservative = (roll >= len(regular_last_names));
		}
		// Now the archconservative variable might be true even if the function wasn't called that way,
		// but if it WAS called that way it's definitely true... this way non-Arch-Conservatives get
		// random last names out of all the last names, while Arch-Conservatives are limited to their own
		// last names
		if (archconservative)
			strcat(str, pickrandom(archconservative_last_names).data());
		else
			strcat(str, pickrandom(regular_last_names).data());
		return str;
	}
	*/