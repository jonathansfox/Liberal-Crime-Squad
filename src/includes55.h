




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
#include "sdl/SDL.h"
#include "sdl/SDL_mixer.h"

#include "includesDeprecated.h"
#include "creatureConstants.h"
#include "includesRandom.h"
/* This is declared again lower down, just needed here for this header. */
std::string tostring(long i);
//#include "vehicle/vehicletype.h"
//#include "vehicle/vehicle.h"


//just a float that is initialized to 0
//#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
//#include "activityST.h"

//int get_associated_attribute(int skill_type);

#include "includesSDS.h"
#include "includesSDS2.h"
// misc.cpp

#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../common/interval.h"
#include "../log/log.h"
#include "../cursesAlternative.h"

enum Bodyparts
{
	BODYPART_HEAD,
	BODYPART_BODY,
	BODYPART_ARM_RIGHT,
	BODYPART_ARM_LEFT,
	BODYPART_LEG_RIGHT,
	BODYPART_LEG_LEFT,
	BODYPARTNUM
};

#include "../creature/creatureEnums.h"
#include "../customMaps.h"
#include "../common/musicClass.h"

/* pick a descriptor acronym */
vector<string> sexdescAcronym;
/* what kind of person? */
vector<string> sexwhoAcronym;
/* seeking acronym */
vector<string> sexseekAcronym;
/* what type of sex? */
vector<string> sextypeAcronym;
map<short, string> musicList;
extern char artdir[MAX_PATH_SIZE];
extern char endgamestate;
extern char newscherrybusted;
extern int month;
extern int year;
extern Log gamelog;
extern map<short, map<short, string> > getLawFlagStringFull;
extern map<short, string> getLawFlagString;
extern map<short, string> getLawString;
extern MusicClass music;
extern short exec[EXECNUM];
extern short interface_pgup;
extern short lawList[LAWNUM];
extern short presparty;
extern short public_interest[VIEWNUM];
#include "locations/locationsEnums.h"

void generate_name(char *first, char *last, char gender);
void firstname(char *str, char gender);
string lastname(bool archconservative);

vector<int> maleOrFemale = {
	GENDER_MALE,
	GENDER_FEMALE
};
/* fills a string with a proper name */
void generate_name(char *str, char gender = GENDER_NEUTRAL);
/* get a first and last name for the same person */
void generate_name(char *first, char *last, char gender = GENDER_NEUTRAL);

string lastname(bool archconservative = false);
const char* statename(int state = -1);
void generate_long_name(char *first, char *middle, char *last, char gender = GENDER_NEUTRAL);

