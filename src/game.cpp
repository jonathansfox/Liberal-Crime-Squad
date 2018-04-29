#include "includes.h"
const string CONST_game015 = "masktype";
const string CONST_game014 = "default";
const string CONST_game013 = "Unspecified error with custom text";
const string CONST_game012 = "We need a slogan!";
const string CONST_game011 = "debug_defines.txt";
const string CONST_game010 = "File Error: InitiateMoreIncompleteText";
const string CONST_game009 = "File Error: InitiateIncompleteText";
const string CONST_game008 = "File Error: ";
const string CONST_game006 = "Comment Found";
const string CONST_game005 = "sitemaps.txt";
const string CONST_game004 = "Liberal Crime Squad ";

const string blankString = "";
//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//Copyright (c) 2002,2003,2004 by Tarn Adams                                            //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////
//This file is part of Liberal Crime Squad.                                             //
//                                                                                      //
//      Liberal Crime Squad is free software; you can redistribute it and/or modify     //
//      it under the terms of the GNU General Public License as published by            //
//      the Free Software Foundation; either version 2 of the License, or               //
//      (at your option) any later version.                                             //
//                                                                                      //
//      Liberal Crime Squad is distributed in the hope that it will be useful,          //
//      but WITHOUT ANY WARRANTY; without even the implied warranty of                  //
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.   See the                  //
//      GNU General Public License for more details.                                    //
//                                                                                      //
//      You should have received a copy of the GNU General Public License               //
//      along with Liberal Crime Squad; if not, write to the Free Software              //
//      Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA   02111-1307   USA     //
//////////////////////////////////////////////////////////////////////////////////////////
//outstanding issues
   //site trucker-type bug still happens (latte-stand)
      //might have to do with missing location in the verifyworklocation() loop
         //but cannot locate instance of this
   //can have hostage in court?
//changes 3.10 alpha 1
   //added AZERTY keyboard support
   //added bullet-proof vests
   //added SWAT units
   //reduced chance of hitting bystanders
   //added multiple hit chances for automatic weapons
   //added extra hit probability for shotguns
   //removed sever types from handguns and knives
   //fixed bug in newspaper site emphasis
   //reduced fence values for armor
   //sleepers can warn before raids
   //courts made more difficult
   //hacking harder, a little less rewarding
   //sleeper overhaul
   //dating conservatives, kidnapping on dates more risky
   //made it easier to maintain LCS integrity when someone high up is arrested
   //changed version variable to 31001
//changes 3.09
   //udistrict -> outoftown for the outskirts location
   //in advanceday(), made people going on vacation drop off squad loot
      //if they are the last person in their squad (or else it would be deleted)
   //added a function to every instance where a vehicle is deleted that
      //makes sure that the liberal car preferences are nullified
   //update version number on the title screen
   //changed version variable to 30900
   //changed activesquad to squad[sq] in one portion of the squad movement code
   //added a tweak to verifyworklocation(), but problem probably still exists
//changes 3.08
   //siegetype occurred many times where it shouldn't have in a majornewspaper() if statement
   //added loitering offense if no other offense exists
   //fixed the wheelchair bug in assemblesquad()
//OUTSTANDING ISSUES:
//possible bug with hauling people
//somebody claims saving works only 3/4 of the time (no confirmation)
//somebody claims squads don't move (sounds like older version bug, they haven't told me version)
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
#include "creature/creature.h"
#include "common/interval.h"
#include "vehicle/vehicletype.h"
#include "vehicle/vehicle.h"
//#include "news/news.h"
void loadgraphics();
#include "creature/creaturetype.h"
#include "items/loottype.h"
#include "creature/augmenttype.h"
//#include "configfile.h"
// Reads in an entire configuration file
// Returns 0 for read successful, returns -1 if failed read
int readConfigFile(const std::string& filename);
#include "log/log.h"
//for the gamelog
#include "common/consolesupport.h"
// for getkey
#include "common/stringconversion.h"
//for string conversion
//#include "common/getnames.h"
std::string cityname();
#include "common/translateid.h"
// for  getarmortype 
#include "title/initfile.h"
//for void loadinitfile();
#include "title/titlescreen.h"
//for void mode_title();
#include "common/creaturePool.h"
#include "locations/locationsPool.h"
#include "cursesAlternative.h"
#include "customMaps.h"
/* end the game and clean up */
void end_game(int err = EXIT_SUCCESS);
struct highscorest
{
	char valid, endtype, slogan[SLOGAN_LEN];
	int month, year, stat_recruits, stat_kidnappings, stat_dead, stat_kills, stat_funds, stat_spent, stat_buys, stat_burns;
};
highscorest score[SCORENUM];
#ifdef WIN32
bool fixcleartype=false;
#endif
struct pointerAndString {
	bool *super_collection;
	string fileName;
	pointerAndString(bool *super_, const string& file_) : fileName(file_), super_collection(super_) {}
};
//int mainSeven(bool xml_loaded_ok);
void init_console();
extern Log gamelog; //The gamelog.
void initialize_debug_defines();
void mainOne() {
	init_console(); // do this FIRST
					//start curses
	initscrAlt();
	gamelog.initialize(GAMELOG_FILEPATH, OVERWRITE_GAMELOG, NEWLINEMODE_GAMELOG); //Initialize the gamelog (and also initialize artdir and homedir)
	title_screen::getInstance();
	CreaturePool::getInstance();
	LocationsPool::getInstance();
}
void mainTwo() {
	time_t t = time(0);
	struct tm *now = localtime(&t); //Do not need to deallocate this. Statically allocated by system
	char datetime[41];
	sprintf(datetime, "---------%i-%02i-%02i %02i:%02i:%02i---------\n\n\n",
		now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec); //YYYY-MM-DD HH:MM:SS format
	gamelog.log(string("\n\n\n---------- PROGRAM STARTED ----------\n") + datetime);
}
#include "common/musicClass.h"
void mainThree() {
	extern MusicClass music;
	music.play(MUSIC_TITLEMODE); // initialize music and play title mode song (do this BEFORE displaying anything on the screen, but AFTER initializing artdir and homedir)
								 // set window title
	char wtitle[50];
	strcpy(wtitle, CONST_game004);
	strcat(wtitle, PACKAGE_VERSION);
	set_title(wtitle);
}
string failedToLoadSitemaps;
string debugCode;
string activated;
string failedToLoad;
string exclamationPoint;
string defaultMissingForMask;
string defaultUnknownForMask;
int oldMapMode = 0; // -1 if we're using the old map generation functions.
void mainFour() {
	noechoAlt();
	//initialize curses color
	start_colorAlt();
	initMainRNG();
	//initialize the array of color pairs
	for (int i = 0; i<8; i++)
		for (int j = 0; j<8; j++)
		{
			if (i == 0 && j == 0)
			{
				init_pairAlt(7 * 8, 0, 0);
				continue;
			}
			if (i == 7 && j == 0) continue;
			init_pairAlt(i * 8 + j, i, j);
		}
	//turns off cursor
	curs_setAlt(0);
	//begin the game loop
	keypadAlt(TRUE);
	raw_outputAlt(TRUE);
	//Loading Graphics...
	loadgraphics();
	//Loading Init File Options...
	loadinitfile();
	//Loading sitemaps.txt...
	oldMapMode = !readConfigFile(CONST_game005); // load site map data
	if (oldMapMode)
	{
		addstrAlt(failedToLoadSitemaps, gamelog);
		gamelog.nextMessage();
 	pressAnyKey();
	}
	//Setting initial game data...
}
void mainFive() {
	extern short activesortingchoice[];
	extern short attitude[];
	extern short public_interest[];
	extern short background_liberal_influence[];
	extern short lawList[];
	//Initialize sorting choices.
	for (int s = 0; s < SORTINGCHOICENUM; s++)
		activesortingchoice[s] = SORTING_NONE;
	for (int v = 0; v < VIEWNUM; v++)
	{
		attitude[v] = 30 + LCSrandom(25);
		public_interest[v] = 0;
		background_liberal_influence[v] = 0;
	}
	attitude[VIEW_LIBERALCRIMESQUAD] = 0;
	attitude[VIEW_LIBERALCRIMESQUADPOS] = 5;
	//attitude[VIEW_POLITICALVIOLENCE]=5;
	if (REVOLUTIONNOW) {
		for (int v = 0; v < VIEWNUM; v++)
			attitude[v] = 100;
	}
	if (SHITLAWS) {
		for (int l = 0; l < LAWNUM; l++) { lawList[l] = -2; }
	}else
	if (PERFECTLAWS) {
		for (int l = 0; l < LAWNUM; l++) { lawList[l] = 2; }
	}
	else {
		lawList[LAW_ABORTION] = 1;
		lawList[LAW_ANIMALRESEARCH] = -1;
		lawList[LAW_POLICEBEHAVIOR] = -1;
		lawList[LAW_PRIVACY] = -1;
		lawList[LAW_DEATHPENALTY] = -1;
		lawList[LAW_NUCLEARPOWER] = -1;
		lawList[LAW_POLLUTION] = -1;
		lawList[LAW_LABOR] = 0;
		lawList[LAW_GAY] = 1;
		lawList[LAW_CORPORATE] = 0;
		lawList[LAW_FREESPEECH] = 0;
		lawList[LAW_FLAGBURNING] = 1;
		lawList[LAW_GUNCONTROL] = -1;
		lawList[LAW_TAX] = 0;
		lawList[LAW_WOMEN] = 1;
		lawList[LAW_CIVILRIGHTS] = 1;
		lawList[LAW_DRUGS] = -1;
		lawList[LAW_IMMIGRATION] = 0;
		lawList[LAW_ELECTIONS] = 0;
		lawList[LAW_MILITARY] = -1;
		lawList[LAW_PRISONS] = 0;
		lawList[LAW_TORTURE] = -1;
	}
}
string fixLineSpecialCharacter(char * toFix) {
	string str = blankString;
	for (int i = 0; i < len(toFix); i++) {
		bool special = (static_cast<int> (toFix[i])) == -61;
		if (special) {
			i++;
			char c;
			switch (toFix[i]) {
			case -87: // 'é'
				c = (char)0x82;
				break;
			case -74: // 'ö'
				c = (char)0x94;
				break;
			case -95: // 'á'
				c = (char)0xa0;
				break;
			case -83: // 'í'
				c = (char)0xa1;
				break;
			case -77: // 'ó'
				c = (char)0xa2;
				break;
			case -70: // 'ú'
				c = (char)0xa3;
				break;
			case (int) '¼':
				// 'ü'
				c = (char)0x81;
				break;
			case (int) '«':
				// 'ë'
				c = (char)0x89;
				break;
			case (int) '²':
				// 'ò'
				c = (char)0x95;
				break;
			case (int) '¢':
				// 'â'
				c = (char)0x83;
				break;
			case (int) '´':
				// 'ô'
				c = (char)0x93;
				break;
				/*
				case (int) 'Â':
				// '¢'
				// This letter does not use the escape character '-61'
				// meaning it would need its own switch statement
				// in addition to the hassle of determining what escape character is used
				c = (char) 0x9b;
				break;
				*/
			default:
				c = toFix[i];
				break;
			}
			str += c;
		}
		else {
			str += toFix[i];
		}
	}
	return str;
}
extern char artdir[];
bool isThisNotComment(char* currentLine) {
	return currentLine[0] != '#' && currentLine[1] != '#';
}
// populate_from_text extracts plaintext and puts it in a two dimensional vector of strings.
// returns true if file loads, false if not.
bool populate_from_txt(vector< vector<string> >& types, const string& fileName, const int dimension)
{
	types.clear();
	const int line_length = 2048;
	bool success = false;
	ifstream txtFile;
	txtFile.open(string(artdir) + fileName);
	if (txtFile.fail()) {
		cout << failedToLoad + fileName + exclamationPoint << endl;
 	pressAnyKey();
	}
	else {
		while (!txtFile.eof()) {
			char currentLine[line_length];
			txtFile.getline(currentLine, line_length);
			const bool notComment = isThisNotComment(currentLine);
			if (notComment) {
				vector<string> line;
				line.push_back(currentLine);
				for (int i = 0; i < dimension - 1 && !txtFile.eof(); i++) {
					// whether the line is not a comment, and is also the line whose contents are optional
					// Testing until obtain proper data from file
					txtFile.getline(currentLine, line_length);
					strcpy(currentLine, fixLineSpecialCharacter(currentLine));
					line.push_back(currentLine);
					if (!isThisNotComment(currentLine)) {
						cout << CONST_game006 << endl << currentLine << endl;
				 	pressAnyKey();
					}
				}
				types.push_back(line);
			}
		}
	}
	success = types.size() > 0;
	if (!success) {
		addstrAlt(CONST_game008 + fileName);
 	pressAnyKey();
	}
	return success;
}
bool populate_from_txt(vector<string> & types, const string& fileName)
{
	types.clear();
	const int line_length = 2048;
	bool success = false;
	ifstream txtFile;
	txtFile.open(string(artdir) + fileName);
	if (txtFile.fail()) {
		cout << failedToLoad + fileName + exclamationPoint << endl;
 	pressAnyKey();
	}
	else {
		cout << endl;
		while (!txtFile.eof()) {
			char currentLine[line_length];
			txtFile.getline(currentLine, line_length);
			const bool notComment = (currentLine[0] && currentLine[0] != '#');
			if (notComment) {
				strcpy(currentLine, fixLineSpecialCharacter(currentLine));
				types.push_back(currentLine);
			}
		}
	}
	success = types.size() > 0;
	if (!success) {
		addstrAlt(CONST_game008 + fileName);
 	pressAnyKey();
	}
	return success;
}
bool initialize_incomplete_txt();
bool initialize_more_incomplete_txt();
bool initialize_txt();
bool initialize_txt() {
	extern vector<file_and_text_collection> activate_text_file_collection;
	extern vector<file_and_text_collection> activities_text_file_collection;
	extern vector<file_and_text_collection> baseactions_text_file_collection;
	extern vector<file_and_text_collection> chase_text_file_collection;
	extern vector<file_and_text_collection> common_text_file_collection;
	extern vector<file_and_text_collection> creature_text_file_collection;
	extern vector<file_and_text_collection> creaturetypes_text_file_collection;
	extern vector<file_and_text_collection> date_text_file_collection;
	extern vector<file_and_text_collection> endgame_text_file_collection;
	extern vector<file_and_text_collection> externally_stored_data_text_file_collection;
	extern vector<file_and_text_collection> fighty_text_file_collection;
	extern vector<file_and_text_collection> get_names_text_file_collection;
	extern vector<file_and_text_collection> globals_text_file_collection;
	extern vector<file_and_text_collection> interrogate_text_file_collection;
	extern vector<file_and_text_collection> justice_text_file_collection;
	extern vector<file_and_text_collection> liberl_agenda_text_file_collection;
	extern vector<file_and_text_collection> locations_text_file_collection;
	extern vector<file_and_text_collection> locationspool_text_file_collection;
	extern vector<file_and_text_collection> majorevent_text_file_collection;
	extern vector<file_and_text_collection> map_specials_text_file_collection;
	extern vector<file_and_text_collection> misc_activities_text_file_collection;
	extern vector<file_and_text_collection> misc_text_file_collection;
	extern vector<file_and_text_collection> names_text_file_collection;
	extern vector<file_and_text_collection> newgame_file_collection;
	extern vector<file_and_text_collection> politics_text_file_collection;
	extern vector<file_and_text_collection> talk_file_collection;
	extern vector<file_and_text_collection> text_file_collection;
	extern vector<file_and_text_collection> title_screen_text_files;
	extern vector<file_and_text_collection> reviewmode_text_file_collection;
	extern vector<file_and_text_collection> siege_text_file_collection;
	extern vector<file_and_text_collection> stealth_text_file_collection;
	vector<vector<file_and_text_collection> > vast_text_collection = { 
		activate_text_file_collection,
		activities_text_file_collection,
		baseactions_text_file_collection,
		chase_text_file_collection,
		common_text_file_collection,
		creature_text_file_collection,
		creaturetypes_text_file_collection,
		date_text_file_collection,
		endgame_text_file_collection,
		externally_stored_data_text_file_collection,
		fighty_text_file_collection,
		get_names_text_file_collection,
		globals_text_file_collection,
		interrogate_text_file_collection,
		justice_text_file_collection,
		liberl_agenda_text_file_collection,
		locations_text_file_collection,
		locationspool_text_file_collection,
		majorevent_text_file_collection,
		map_specials_text_file_collection,
		misc_activities_text_file_collection,
		misc_text_file_collection,
		names_text_file_collection,
		newgame_file_collection,
		politics_text_file_collection,
		talk_file_collection,
		text_file_collection,
		title_screen_text_files,
		reviewmode_text_file_collection,
		siege_text_file_collection,
		stealth_text_file_collection,
	};
	bool loaded = true;
	
	for (vector<file_and_text_collection> file : vast_text_collection) {
		for (file_and_text_collection f : file) {
			if (f.superCollection) {
				loaded &= populate_from_txt(*f.super_collection, f.fileName, f.dimensions);
			}
			else {
				loaded &= populate_from_txt(*f.collection, f.fileName);
			}
		}
	}
	loaded &= initialize_incomplete_txt();
	if (!loaded) {
		addstrAlt(CONST_game009 );
 	pressAnyKey();
	}
	else {
		loaded &= initialize_more_incomplete_txt();
		if (!loaded) {
			addstrAlt(CONST_game010);
	 	pressAnyKey();
		}
	}
	return loaded;
}
void initialize_debug_defines() {
	extern vector<pointerAndString> debug_defines;
	string fileName = CONST_game011;
	ifstream txtFile;
	txtFile.open(string(artdir) + fileName);
	//int debug_codes = 0;
	if (txtFile.fail()) {
		// debug file not found, don't do anything
	}
	else {
		clearAlt();
		int y = 0;
		while (!txtFile.eof()) {
			char currentLine[800];
			txtFile.getline(currentLine, 800);
			const bool notComment = isThisNotComment(currentLine);
			if (notComment) {
				for (pointerAndString p : debug_defines) {
					if (currentLine == p.fileName) {
						*(p.super_collection) = true;
						mvaddstrAlt(y++, 0, debugCode + p.fileName + activated);
					}
				}
			}
		}
		if (DISPLAYDEBUG) {
	 	pressAnyKey();
		}
	}
}
void mainSix() {
	extern char slogan[];
	extern short senate[];
	extern short house[];
	extern short court[];
	extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
	extern short  exec[];
	extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	extern vector<string> default_slogans;
	strcpy(slogan, CONST_game012);
	if (!LCSrandom(20))
	{
		strcpy(slogan, pickrandom(default_slogans));
	}
	for (int s = 0; s<SENATENUM; s++)
	{
		if (s<25) senate[s] = -2;
		else if (s<60) senate[s] = -1;
		else if (s<80) senate[s] = 0;
		else if (s<95) senate[s] = 1;
		else senate[s] = 2;
	}
	for (int h = 0; h<HOUSENUM; h++)
	{
		if (h<50) house[h] = -2;
		else if (h<250) house[h] = -1;
		else if (h<350) house[h] = 0;
		else if (h<400) house[h] = 1;
		else house[h] = 2;
	}
	for (int c = 0; c<COURTNUM; c++)
	{
		if (c<3) court[c] = -2;
		else if (c<5) court[c] = -1;
		else if (c<5) court[c] = 0;
		else if (c<8) court[c] = 1;
		else court[c] = 2;
		do
		{
			if (court[c] == -2) generate_name(courtname[c], GENDER_WHITEMALEPATRIARCH);
			else generate_name(courtname[c]);
		} while (len(courtname[c])>20);
	}
	for (int e = 0; e<EXECNUM; e++)
	{
		exec[e] = -2;
		generate_name(execname[e], GENDER_WHITEMALEPATRIARCH);
	}
	extern unsigned long attorneyseed[4];
	initOtherRNG(attorneyseed);
	extern char lcityname[];
	strcpy(lcityname, cityname());
}
bool mainSeven(bool xml_loaded_ok);
int main(int argc, char* argv[])
{
	mainOne();
	mainTwo();
	initialize_debug_defines();
	bool xml_loaded_ok = initialize_txt();
	if (!xml_loaded_ok) {
		mvaddstrAlt(0, 0, CONST_game013);
 	pressAnyKey();
	}
	mainThree();
	mainFour();
	mainFive();
	mainSix();
	// Main Loop
	if (!mainSeven(xml_loaded_ok)) {
		// This function closes the entire program, and can be called anywhere
		end_game(EXIT_FAILURE);
	}
	else {
		clearAlt();
		title_screen::getInstance().mode_title();
	}
}
bool populate_masks_from_xml(vector<ArmorType*>& masks, const string& file, Log& log)
{
	CMarkup xml;
	if (!xml.Load(string(artdir) + file))
	{ //File is missing or not valid XML.
		addstrAlt(failedToLoad + file + exclamationPoint, log);
 	pressAnyKey();
		return false; //Abort.
	}
	xml.FindElem();
	xml.IntoElem();
	int defaultindex;
	if (xml.FindElem(CONST_game014)) defaultindex = getarmortype(xml.GetData());
	else
	{
		addstrAlt(defaultMissingForMask, log);
 	pressAnyKey();
		return false; //Abort.
	}
	if (defaultindex == -1)
	{
		addstrAlt(defaultUnknownForMask, log);
 	pressAnyKey();
		return false; //Abort.
	}
	xml.ResetMainPos();
	while (xml.FindElem(CONST_game015)) masks.push_back(new ArmorType(*masks[defaultindex], xml.GetSubDoc()));
	return true;
}