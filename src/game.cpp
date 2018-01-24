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

#include <includes.h>

#include "common/interval.h"
#include "common/ledger.h"

#include "vehicle/vehicle.h"

#include "news/news.h"
// for loadgraphics

#include "creature/creaturetype.h"

#include "items/loottype.h"

#include "creature/augmenttype.h"

#include "configfile.h"
// needed for something contained in sitemap.h

#include "sitemode/sitemap.h"

#include "log/log.h"
//for the gamelog

#include "cursesmovie.h"
//for cursesmoviest

#include "common/consolesupport.h"
// for init_console

#include "common/commondisplay.h"
// for addstr

#include "common/stringconversion.h"
//for string conversion

#include "common/getnames.h"
// for std::string cityname()

#include "common/translateid.h"
// for  getarmortype 

#include "define_includes.h"
//for PACKAGE_VERSION

#include "title/initfile.h"
//for void loadinitfile();

#include "title/titlescreen.h"
//for void mode_title();



#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
#include <ctime>

/* end the game and clean up */
void end_game(int err = EXIT_SUCCESS);

string failedToLoadSitemaps;
string debugCode;
string activated;
string failedToLoad;
string exclamationPoint;
string defaultMissingForMask;
string defaultUnknownForMask;

Log gamelog; //The gamelog.
Log xmllog; // Log for xml errors or bad values.
CursesMoviest movie;
unsigned char bigletters[27][5][7][4];
unsigned char newstops[6][80][5][4];
unsigned char newspic[20][78][18][4];
MusicClass music;
char homedir[MAX_PATH_SIZE];
char artdir[MAX_PATH_SIZE];
vector<configSiteMap *> sitemaps; // stores site map info read in from config file
bool multipleCityMode;
unsigned long seed[RNG_SIZE];
vector<ClipType *> cliptype;
vector<WeaponType *> weapontype;
vector<ArmorType *> armortype;
vector<LootType *> loottype;
vector<CreatureType *> creaturetype;
vector<AugmentType *> augmenttype;
vector<VehicleType *> vehicletype;
template<class Type>
bool populate_from_xml(vector<Type*>& types,string file,Log& log);
bool populate_from_txt(vector<vector<string>>& types, string file, int dimension, Log& log);
bool populate_from_txt(vector<string> & types, string fileName, Log& log);
bool populate_masks_from_xml(vector<ArmorType*>& masks,string file,Log& log);
long curcreatureid=0;
vector<Item *> groundloot;
vector<Location *> location;
vector<Vehicle *> vehicle;
char showcarprefs=1;
int oldMapMode=0; // -1 if we're using the old map generation functions.
siteblockst levelmap[MAPX][MAPY][MAPZ];
chaseseqst chaseseq;
char slogan[SLOGAN_LEN];
vector<Creature *> pool;
vector<squadst *> squad;
squadst *activesquad=NULL;
long cursquadid=0;
char disbanding=0;
int disbandtime=0;
char cantseereason;
short activesortingchoice[SORTINGCHOICENUM];
Creature encounter[ENCMAX];
short mode=GAMEMODE_TITLE;
short offended_corps=0;
short offended_cia=0;
short offended_amradio=0;
short offended_cablenews=0;
short offended_firemen=0;
int police_heat=0;
unsigned long attorneyseed[RNG_SIZE];
int selectedsiege=-1;
char lcityname[CITY_NAMELEN];
char newscherrybusted=0;
int month=1;
int year = THEFUTURE ? 2100 : 2009;
int amendnum=28;
bool termlimits=false;
bool deagle=false;
bool m249=false;
UniqueCreatures uniqueCreatures;
short attitude[VIEWNUM];
short public_interest[VIEWNUM];
short background_liberal_influence[VIEWNUM];
short lawList[LAWNUM];
short house[HOUSENUM];
short senate[SENATENUM];
short court[COURTNUM];
char courtname[COURTNUM][POLITICIAN_NAMELEN];
short exec[EXECNUM];
short execterm=1;
char execname[EXECNUM][POLITICIAN_NAMELEN];
short presparty=CONSERVATIVE_PARTY;
char oldPresidentName[POLITICIAN_NAMELEN];
int stat_recruits=0;
int stat_kidnappings=0;
int stat_dead=0;
int stat_kills=0;
int stat_buys=0;
int stat_burns=0;
int ustat_recruits=0;
int ustat_kidnappings=0;
int ustat_dead=0;
int ustat_kills=0;
int ustat_funds=0;
int ustat_spent=0;
int ustat_buys=0;
int ustat_burns=0;
int locx;
int locy;
int locz;
short sitetype;
short sitealienate;
short sitealarm;
short sitealarmtimer;
short postalarmtimer;
short siteonfire;
int sitecrime;
short cursite;
bool mapshowing=false;
bool encounterwarnings=false;
char foughtthisround=0;
short interface_pgup='[';
short interface_pgdn=']';
bool autosave=false;
string savefile_name;
int day=1;
class Ledger ledger;
short party_status=-1;
short wincondition=WINCONDITION_ELITE;
short fieldskillrate=FIELDSKILLRATE_FAST;
bool notermlimit;           //These determine if ELAs can take place --kviiri
bool nocourtpurge;
bool stalinmode;
char endgamestate=ENDGAME_NONE;
char ccsexposure=CCSEXPOSURE_NONE;
char ccs_kills=0;
int ccs_siege_kills=0;
int ccs_boss_kills=0;
vector<datest *> date;
vector<recruitst *> recruit;
vector<newsstoryst *> newsstory;
newsstoryst *sitestory=NULL;
struct highscorest
{
	char valid, endtype, slogan[SLOGAN_LEN];
	int month, year, stat_recruits, stat_kidnappings, stat_dead, stat_kills, stat_funds, stat_spent, stat_buys, stat_burns;
};

highscorest score[SCORENUM];
int yourscore=-1;
#ifdef WIN32
bool fixcleartype=false;
#endif
///
/*
DEBUG DEFINES
*/
// inform player of activated debug codes
bool DISPLAYDEBUG = false;
// Don't save the game
bool NOSAVE = false;
// Enemies don't attack
bool NOENEMYATTACK = false;
// Laws start archconservative
bool SHITLAWS = false;
// Laws start elite liberal
bool PERFECTLAWS = false;
// Public opinion starts at 100% Liberal
bool REVOLUTIONNOW = false;
// Gives you bloody armor
bool GIVEBLOODYARMOR = false;
// Start with lots of money
bool HIGHFUNDS = false;
// Interrogation always enlightens
bool AUTOENLIGHTEN = false;
// Show polls when you can't see things
bool SHOWWAIT = false;
// Show die rolls, 100% accurate poll numbers
bool SHOWMECHANICS = false;
// Make the year 2100
bool THEFUTURE = false;
// Make the founder blind
bool BLIND = false;
// Make the founder unable to walk
bool NOWALK = false;
// Make the founder have no face
bool NOFACE = false;
// Make the founder have a severely injured spine
bool SPINE = false;
// Make the founder have severe internal damage
bool INTERNAL = false;
// Make age not matter for dating or prostitution
bool ZEROMORAL = false;
// Re-seed the Random Number Generator every time it's called
bool MORERANDOM = false;
// Allow experimental, incomplete Stalinist Comrade Squad mode to be chosen for new games
bool ALLOWSTALIN = false;
// Store savefiles in plaintext, making it human readable and editable
bool VERBOSESAVEFILE = false;
// NOVERBOSECOMMENTS only affect anything if VERBOSESAVEFILE is active
// Remove almost all automatically generated comments from verbose savefiles
bool NOVERBOSECOMMENTS = false;

struct pointerAndString {
	bool *super_collection;
	string fileName;
	pointerAndString(bool *super_, string file_) : fileName(file_), super_collection(super_) {}

};

extern vector<pointerAndString> debug_defines;

void mainOne();
void mainTwo();
void mainThree();
void mainFour();
void mainFive();
void mainSix();
int mainSeven(bool xml_loaded_ok);
void init_console();
WINDOW *initscr(void);
extern Log gamelog; //The gamelog.
void initialize_debug_defines();
void mainOne() {
	init_console(); // do this FIRST
					//start curses
	initscr();
	gamelog.initialize(GAMELOG_FILEPATH, OVERWRITE_GAMELOG, NEWLINEMODE_GAMELOG); //Initialize the gamelog (and also initialize artdir and homedir)
}
void mainTwo() {
	////
	time_t t = time(0);
	struct tm *now = localtime(&t); //Do not need to deallocate this. Statically allocated by system
	char datetime[41];
	sprintf(datetime, "---------%i-%02i-%02i %02i:%02i:%02i---------\n\n\n",
		now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec); //YYYY-MM-DD HH:MM:SS format
	gamelog.log(string("\n\n\n---------- PROGRAM STARTED ----------\n") + datetime);
	////
}
extern MusicClass music;
void mainThree() {
	music.play(MUSIC_TITLEMODE); // initialize music and play title mode song (do this BEFORE displaying anything on the screen, but AFTER initializing artdir and homedir)
								 // set window title
	char wtitle[50];
	strcpy(wtitle, "Liberal Crime Squad ");
	strcat(wtitle, PACKAGE_VERSION);
	set_title(wtitle);
	////
}
void mainFour() {
	noecho();
	//initialize curses color
	start_color();
	initMainRNG();
	//initialize the array of color pairs
	for (int i = 0; i<8; i++)
		for (int j = 0; j<8; j++)
		{
			if (i == 0 && j == 0)
			{
				init_pair(7 * 8, 0, 0);
				continue;
			}
			if (i == 7 && j == 0) continue;
			init_pair(i * 8 + j, i, j);
		}
	//turns off cursor
	curs_set(0);
	//begin the game loop
	keypad(stdscr, TRUE);
	raw_output(TRUE);
	//Loading Graphics...
	//getkey();
	loadgraphics();
	//Loading Init File Options...
	//getkey();
	loadinitfile();
	//Loading sitemaps.txt...
	//getkey();
	oldMapMode = !readConfigFile("sitemaps.txt"); // load site map data
	if (oldMapMode)
	{
		addstrAlt(failedToLoadSitemaps, gamelog);
		gamelog.nextMessage();
		getkey();
	}

	//Setting initial game data...
	//getkey();
	////
}
extern short activesortingchoice[];
extern short attitude[];
extern short public_interest[];
extern short background_liberal_influence[];
extern short lawList[];
void mainFive() {
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
	if (SHITLAWS) {
		for (int l = 0; l < LAWNUM; l++) { lawList[l] = -2; }
	}
	if (PERFECTLAWS) {
		for (int l = 0; l < LAWNUM; l++) { lawList[l] = 2; }
	}
	////
}
extern char slogan[];
 vector<string> default_slogans;
extern short senate[];
extern short house[];
extern short court[];
extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
extern short  exec[];
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern unsigned long attorneyseed[4];
extern char lcityname[];
extern Log xmllog;
bool populate_from_txt(vector<string> & types, string fileName);
bool populate_from_txt(vector< vector<string> >& types, string fileName, int dimension);
extern vector<file_and_text_collection> text_file_collection;
bool initialize_incomplete_txt();
bool initialize_more_incomplete_txt();
bool initialize_txt();
bool initialize_txt() {
	bool loaded = true;
	for (file_and_text_collection f : text_file_collection) {
		if (f.superCollection) {
			loaded &= populate_from_txt(*f.super_collection, f.fileName, f.dimensions);
		}
		else {
			loaded &= populate_from_txt(*f.collection, f.fileName);
		}
	}
	loaded &= initialize_incomplete_txt();
	loaded &= initialize_more_incomplete_txt();
	return loaded;
}
extern char artdir[];
void initialize_debug_defines();
void initialize_debug_defines() {
	string fileName = "debug_defines.txt";
	ifstream txtFile;
	char currentLine[800];
	txtFile.open(string(artdir) + fileName);
	int debug_codes = 0;
	if (txtFile.fail()) {
		// debug file not found, don't do anything
	}
	else {
		clearAlt();
		int y = 0;
		while (!txtFile.eof()) {
			txtFile.getline(currentLine, 800);
			const bool notComment = (currentLine[0] && currentLine[0] != '#');
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
			getkey();
		}
	}
}
// populate_from_text extracts plaintext and puts it in a two dimensional vector of strings.
// returns true if file loads, false if not.
static const int line_length = 2048;
bool populate_from_txt(vector< vector<string> >& types, const string fileName, const int dimension)
{
	bool success = false;
	ifstream txtFile;
	char currentLine[line_length];
	txtFile.open(string(artdir) + fileName);
	if (txtFile.fail()) {
		cout << failedToLoad + fileName + exclamationPoint << endl;
		getkey();
	}
	else {
		while (!txtFile.eof()) {
			txtFile.getline(currentLine, line_length);
			const bool notComment = (currentLine[0] && currentLine[0] != '#');
			if (notComment) {
				vector<string> line;
				line.push_back(currentLine);
				for (int i = 0; i < dimension - 1 && !txtFile.eof(); i++) {
					// whether the line is not a comment, and is also the line whose contents are optional
					// Testing until obtain proper data from file
					txtFile.getline(currentLine, line_length);
					line.push_back(currentLine);
					if (currentLine[0] == '#') {
						cout << "Comment Found" << endl << currentLine << endl;
						getkey();
					}
				}
				types.push_back(line);
			}
		}
	}
	success = types.size() > 0;
	return success;
}
bool populate_from_txt(vector<string> & types, const string fileName)
{
	bool success = false;
	ifstream txtFile;
	char currentLine[line_length];
	txtFile.open(string(artdir) + fileName);
	if (txtFile.fail()) {
		cout << failedToLoad + fileName + exclamationPoint << endl;
		getkey();
	}
	else {
		cout << endl;
		while (!txtFile.eof()) {
			txtFile.getline(currentLine, line_length);
			const bool notComment = (currentLine[0] && currentLine[0] != '#');
			if (notComment) {
				types.push_back(currentLine);
			}
		}
	}
	success = types.size() > 0;
	return success;
}
void mainSix() {
	//	char file_name[13];
	//	FILE *file;
	strcpy(slogan, "We need a slogan!");
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
	initOtherRNG(attorneyseed);
	strcpy(lcityname, cityname());
	xmllog.initialize("xmllog", true, 1);
}
extern vector<ClipType *> cliptype;
extern vector<WeaponType *> weapontype;
extern vector<ArmorType *> armortype;
extern vector<LootType *> loottype;
extern vector<CreatureType *> creaturetype;
extern vector<AugmentType *> augmenttype;
extern vector<VehicleType *> vehicletype;
template<class Type>
bool populate_from_xml(vector<Type*>& types, string file, Log& log);
bool populate_masks_from_xml(vector<ArmorType*>& masks, string file, Log& log);
int mainSeven(bool xml_loaded_ok) {
	xml_loaded_ok &= populate_from_xml(vehicletype, "vehicles.xml", xmllog);
	xml_loaded_ok &= populate_from_xml(cliptype, "clips.xml", xmllog);
	xml_loaded_ok &= populate_from_xml(weapontype, "weapons.xml", xmllog);
	xml_loaded_ok &= populate_from_xml(armortype, "armors.xml", xmllog);
	xml_loaded_ok &= populate_masks_from_xml(armortype, "masks.xml", xmllog);
	xml_loaded_ok &= populate_from_xml(loottype, "loot.xml", xmllog);
	xml_loaded_ok &= populate_from_xml(creaturetype, "creatures.xml", xmllog);
	xml_loaded_ok &= populate_from_xml(augmenttype, "augmentations.xml", xmllog);
	if (!xml_loaded_ok) end_game(EXIT_FAILURE);
	//Attempting to load saved game...
	//getkey();
	//Setup complete!
	//getkey();
	clearAlt();
	mode_title();
	//deinitialize curses
	end_game();
	return EXIT_SUCCESS;
}
template<class Type>
bool populate_from_xml(vector<Type*>& types, string file, Log& log)
{
	CMarkup xml;
	if (!xml.Load(string(artdir) + file))
	{ // File is missing or not valid XML.
		addstrAlt(failedToLoad + file + exclamationPoint, log);
		getkey();
		// Will cause abort here or else if file is missing all unrecognized types
		// loaded from a saved game will be deleted. Also, you probably don't want
		// to play with a whole category of things missing anyway. If the file
		// does not have valid xml, then behaviour is kind of undefined so it's
		// best to abort then too.
		return false;
	}
	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem()) types.push_back(new Type(xml.GetSubDoc()));
	return true;
}
int main(int argc, char* argv[])
{
	mainOne();
	mainTwo();
	initialize_debug_defines();
	bool xml_loaded_ok = initialize_txt();
	if (!xml_loaded_ok) {
		mvaddstrAlt(0,0,"Unspecified error with custom text");
		getkey();
	}
	mainThree();
	mainFour();
	mainFive();
	mainSix();
	return mainSeven(xml_loaded_ok);
}

/* Free memory and exit the game */
void end_game(int err)
{
   #ifdef WIN32
   end_cleartype_fix(); // won't do anything unless fixcleartype is true
   #endif
   delete_and_clear(location);
   delete_and_clear(squad);
   delete_and_clear(weapontype);
   delete_and_clear(cliptype);
   delete_and_clear(armortype);
   delete_and_clear(loottype);
   delete_and_clear(creaturetype);
   delete_and_clear(augmenttype);
   delete_and_clear(vehicletype);
   delete_and_clear(vehicle);
   delete_and_clear(pool);
   delete_and_clear(sitemaps);
   delete_and_clear(recruit);
   delete_and_clear(date);
   delete_and_clear(groundloot);
   music.quit(); // shut down music
   endwin();
   exit(err);
}

// populate_from_text extracts plaintext and puts it in a two dimensional vector of strings.
// returns true if file loads, false if not.
bool populate_from_txt(vector< vector<string> >& types, string fileName, int dimension, Log& log)
{
	ifstream txtFile;
	char currentLine[90];
	txtFile.open(string(artdir) + fileName);
	if (txtFile.fail()) {
		addstrAlt(failedToLoad + fileName + exclamationPoint, log);
		cout << endl;
		getkey();
		return false;
	}
	//cout << endl;
	while (!txtFile.eof()) {
		txtFile.getline(currentLine, 90, '\n');
		/*if (!currentLine[0]) {
			cout << "blank" << endl;
		}
		if (currentLine[0] == '\n') {
			cout << "newLine" << endl;
		}*/
		bool notComment = (currentLine[0] && currentLine[0] != '#');
		if (notComment) {
			vector<string> line;
			line.push_back(currentLine);
			//cout << currentLine << endl;
			//types[whichPickup][whichLine] = string(currentLine);
			for (int i = 0; i < dimension - 1 && !txtFile.eof(); i++) {
				// whether the line is not a comment, and is also the line whose contents are optional
					// Testing until obtain proper data from file
					txtFile.getline(currentLine, 90, '\n');
					line.push_back(currentLine);
					//cout << currentLine << endl;
					//types[whichPickup][whichLine] = string(currentLine);
					if (currentLine[0] == '#') {
						cout << "Comment Found" << endl << currentLine << endl;
						getkey();
					}
			}
			types.push_back(line);
		}
	}
	txtFile.close();
	return true;
	}
bool populate_from_txt(vector<string> & types, string fileName, Log& log)
{
	ifstream txtFile;
	char currentLine[90];
	txtFile.open(string(artdir) + fileName);
	if (txtFile.fail()) {
		addstrAlt(failedToLoad + fileName + exclamationPoint, log);
		getkey();
		return false;
	}
	//cout << endl;
	while (!txtFile.eof()) {
		txtFile.getline(currentLine, 90, '\n');
		/*if (!currentLine[0]) {
		cout << "blank" << endl;
		}
		if (currentLine[0] == '\n') {
		cout << "newLine" << endl;
		}*/
		bool notComment = (currentLine[0] && currentLine[0] != '#');
		if (notComment) {
			types.push_back(currentLine);
		}
	}
	txtFile.close();
	return true;
}
bool populate_masks_from_xml(vector<ArmorType*>& masks,string file,Log& log)
{
   CMarkup xml;
   if(!xml.Load(string(artdir)+file))
   { //File is missing or not valid XML.
	   addstrAlt(failedToLoad+file+exclamationPoint,log);
      getkey();
      return false; //Abort.
   }
   xml.FindElem();
   xml.IntoElem();
   int defaultindex;
   if(xml.FindElem("default")) defaultindex=getarmortype(xml.GetData());
   else
   {
	   addstrAlt(defaultMissingForMask,log);
      getkey();
      return false; //Abort.
   }
   if(defaultindex==-1)
   {
	   addstrAlt(defaultUnknownForMask,log);
      getkey();
      return false; //Abort.
   }
   xml.ResetMainPos();
   while(xml.FindElem("masktype")) armortype.push_back(new ArmorType(*armortype[defaultindex],xml.GetSubDoc()));
   return true;
}