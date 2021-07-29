




/*
	File created by Chris Johnson.
	These were previously all in game.cpp.

	This file includes all the the enums, defines, and included headers required globally by all components.

	All code released under GNU GPL.
*/
#include <windows.h>
#include <vector>
#include <map>
#include <deque>
#include "cmarkup/Markup.h"
using namespace std;

#include "includesLen.h"
#include <iostream>
#include "includesDeprecated.h"

enum Views
{
	VIEW_STALIN = -2, // this one is -2 and is actually calculated based on views >=0 and <VIEWNUM-3
	VIEW_MOOD, // this one is -1 and is likewise calculated based on views >=0 and <VIEWNUM-3
	VIEW_GAY, // view #0, the first one that is actually in the attitude[] array
	VIEW_DEATHPENALTY,
	VIEW_TAXES,
	VIEW_NUCLEARPOWER,
	VIEW_ANIMALRESEARCH,
	VIEW_POLICEBEHAVIOR,
	VIEW_TORTURE,
	VIEW_INTELLIGENCE,
	VIEW_FREESPEECH,
	VIEW_GENETICS,
	VIEW_JUSTICES,
	VIEW_GUNCONTROL,
	VIEW_SWEATSHOPS,
	VIEW_POLLUTION,
	VIEW_CORPORATECULTURE,
	VIEW_CEOSALARY,
	VIEW_WOMEN,//XXX: VIEW_ABORTION DOES NOT EXIST
	VIEW_CIVILRIGHTS,
	VIEW_DRUGS,
	VIEW_IMMIGRATION,
	VIEW_MILITARY,
	VIEW_PRISONS,
	//*JDS* I'm using VIEWNUM-5 in a random generator that rolls a
	//random issue, not including the media/politicalviolence ones, and this will
	//break if these stop being the last 4 issues; do a search
	//for VIEWNUM-5 to change it if it needs to be changed.
	VIEW_AMRADIO,
	VIEW_CABLENEWS,
	//THESE THREE MUST BE LAST FOR VIEWNUM-3 TO WORK IN PLACES
	VIEW_LIBERALCRIMESQUAD,
	VIEW_LIBERALCRIMESQUADPOS,
	//THIS ONE MUST BE LAST. randomissue RELIES ON IT BEING LAST TO IGNORE IT IF
	//CCS IS DEAD.
	VIEW_CONSERVATIVECRIMESQUAD,
	VIEWNUM
};


enum Laws
{
	LAW_STALIN = -2, // not a real law: this is -2 and is actually calculated based on views >=0 and <VIEWNUM-3
	LAW_MOOD, // not a real law: this is -1 and is likewise calculated based on views >=0 and <VIEWNUM-3
	LAW_ABORTION, // law #0, the first one that is actually in the law[] array
	LAW_ANIMALRESEARCH,
	LAW_POLICEBEHAVIOR,
	LAW_PRIVACY,
	LAW_DEATHPENALTY,
	LAW_NUCLEARPOWER,
	LAW_POLLUTION,
	LAW_LABOR,
	LAW_GAY,
	LAW_CORPORATE,
	LAW_FREESPEECH,
	LAW_FLAGBURNING,
	LAW_GUNCONTROL,
	LAW_TAX,
	LAW_WOMEN,
	LAW_CIVILRIGHTS,
	LAW_DRUGS,
	LAW_IMMIGRATION,
	LAW_ELECTIONS,
	LAW_MILITARY,
	LAW_PRISONS,
	LAW_TORTURE,
	LAWNUM
};

enum Execs
{
	EXEC_PRESIDENT,
	EXEC_VP,
	EXEC_STATE,
	EXEC_ATTORNEY,
	EXECNUM
};

enum SortingChoices
{
	SORTING_NONE,
	SORTING_NAME,
	SORTING_LOCATION_AND_NAME,
	SORTING_SQUAD_OR_NAME,
	SORTINGNUM
};


enum ActiveSortingChoices
{
	SORTINGCHOICE_LIBERALS, //They're prefixed SORTINGCHOICE because they're used as
	SORTINGCHOICE_HOSTAGES, //array indices for the array activesortingchoice.
	SORTINGCHOICE_CLINIC,   //activesortingchoice holds the chosen way to sort the lists.
	SORTINGCHOICE_JUSTICE,
	SORTINGCHOICE_SLEEPERS,
	SORTINGCHOICE_DEAD,
	SORTINGCHOICE_AWAY,
	SORTINGCHOICE_ACTIVATE,
	SORTINGCHOICE_ACTIVATESLEEPERS,
	SORTINGCHOICE_ASSEMBLESQUAD,
	SORTINGCHOICE_BASEASSIGN,
	SORTINGCHOICENUM
};

#include "includesRandom.h"

//int get_associated_attribute(int skill_type);

//#ifdef	GAME_CPP
// game.cpp

#include "creature/newcreature.h"
#include "../items/armortype.h"
#include "common/interval.h"
#include "vehicle/vehicletype.h"
#include "vehicle/vehicle.h"
void loadgraphics();
#include "items/loottype.h"
#include "creature/augmenttype.h"
// Reads in an entire configuration file
// Returns 0 for read successful, returns -1 if failed read
int readConfigFile(const std::string& filename);
#include "log/log.h"
//for the gamelog
// for getkey
#include "common/stringconversion.h"
//for string conversion
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
bool fixcleartype = false;
struct pointerAndString {
	bool *super_collection;
	string fileName;
	pointerAndString(bool *super_, const string& file_) : fileName(file_), super_collection(super_) {}
};
struct fullName {
	string first;
	string middle;
	string last;

};
void init_console();
void initialize_debug_defines();
#include "common/musicClass.h"
const int CITY_NAMELEN = 80;


bool mainSeven(bool xml_loaded_ok);
extern bool DISPLAYDEBUG;
extern bool PERFECTLAWS;
extern bool REVOLUTIONNOW;
extern bool SHITLAWS;
extern char artdir[MAX_PATH_SIZE];
extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern char lcityname[CITY_NAMELEN];
extern Log gamelog; //The gamelog.
extern MusicClass music;
extern short  exec[EXECNUM];
extern short activesortingchoice[SORTINGCHOICENUM];
extern short attitude[VIEWNUM];
extern short background_liberal_influence[VIEWNUM];
extern short court[COURTNUM];
extern short house[HOUSENUM];
extern short lawList[LAWNUM];
extern short public_interest[VIEWNUM];
extern short senate[SENATENUM];
extern unsigned long attorneyseed[RNG_SIZE];
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
extern vector<file_and_text_collection> reviewmode_text_file_collection;
extern vector<file_and_text_collection> siege_text_file_collection;
extern vector<file_and_text_collection> stealth_text_file_collection;
extern vector<file_and_text_collection> talk_file_collection;
extern vector<file_and_text_collection> title_screen_text_files;
extern vector<pointerAndString> debug_defines;
fullName generate_long_name(char gender = GENDER_NEUTRAL);

void set_title(char *s);

//#endif//GAME_CPP
//#endif// INCLUDES_H_INCLUDED
