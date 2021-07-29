




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

#include "includesLen.h"
#include <iostream>
#include "includesDeprecated.h"


enum EndGameStatus
{
	ENDGAME_NONE,
	ENDGAME_CCS_APPEARANCE,
	ENDGAME_CCS_ATTACKS,
	ENDGAME_CCS_SIEGES,
	ENDGAME_CCS_DEFEATED,
	ENDGAME_MARTIALLAW,
	ENDGAMENUM
};

/* *JDS* I'm making laws an array instead of a bunch
 * of bits which are either on or off. Each charge can be
 * duplicated, for multiple counts, and intense focus
 * for wanted persons.
 */
enum Lawflags
{
	LAWFLAG_TREASON,      // "Treason"
	LAWFLAG_TERRORISM,    // "Terrorism"
	LAWFLAG_MURDER,       // "Murder"
	LAWFLAG_KIDNAPPING,   // "Kidnapping"
	LAWFLAG_BANKROBBERY,  // "Bank robbery"
	LAWFLAG_ARSON,        // "Arson"
	LAWFLAG_BURNFLAG,     // "Flag burning" / "Flag Murder"
	LAWFLAG_SPEECH,       // "Harmful speech"
	LAWFLAG_BROWNIES,     // "Drug dealing"
	LAWFLAG_ESCAPED,      // "Escaping prison"
	LAWFLAG_HELPESCAPE,   // "Releasing prisoners"
	LAWFLAG_JURY,         // "Jury tampering"
	LAWFLAG_RACKETEERING, // "Racketeering"
	LAWFLAG_EXTORTION,    // "Extortion"
	LAWFLAG_ARMEDASSAULT, // "Armed assault"
	LAWFLAG_ASSAULT,      // "Assault"
	LAWFLAG_CARTHEFT,     // "Grand theft auto"
	LAWFLAG_CCFRAUD,      // "Credit card fraud"
	LAWFLAG_THEFT,        // "Theft"
	LAWFLAG_PROSTITUTION, // "Prostitution"
	LAWFLAG_HIREILLEGAL,  // "Hiring illegal aliens" / "Hiring undocumented workers"
	LAWFLAG_COMMERCE,     // "Electronic sabotage"
	LAWFLAG_INFORMATION,  // "Hacking"
	LAWFLAG_BURIAL,       // "Unlawful burial"
	LAWFLAG_BREAKING,     // "Breaking and entering"
	LAWFLAG_VANDALISM,    // "Vandalism"
	LAWFLAG_RESIST,       // "Resisting arrest"
	LAWFLAG_DISTURBANCE,  // "Disturbing the peace"
	LAWFLAG_PUBLICNUDITY, // "Public nudity"
	LAWFLAG_LOITERING,    // "Loitering"
	LAWFLAGNUM
};

/* *JDS* In addition to laws being an array,
 * each law will be associated with a tag_heat value,
 * indicating how much that particular crime draws
 * police attention to the wanted person, and to the
 * LCS as a whole. This is a global array, available
 * at runtime and indexed to the lawflag enum, so that
 * code can dynamically look up these heat values as
 * needed at runtime.
 */


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


enum PoliticalParties
{
	LIBERAL_PARTY,
	CONSERVATIVE_PARTY,
	STALINIST_PARTY,
	PARTYNUM
};

#include "creatureConstants.h"
#include "includesRandom.h"
/* This is declared again lower down, just needed here for this header. */
std::string tostring(long i);

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

