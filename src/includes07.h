




/*
	File created by Chris Johnson.
	These were previously all in game.cpp.

	This file includes all the the enums, defines, and included headers required globally by all components.

	All code released under GNU GPL.
*/
#ifndef INCLUDES_H_INCLUDED
#define INCLUDES_H_INCLUDED0
constexpr auto __USE_MINGW_ANSI_STDIO = 0;
#include <windows.h>
#include <io.h> //needed for unlink()
#include <direct.h>
#include <ciso646> // alternate keywords included in the ISO C++ standard
// but not directly supported by Microsoft Visual Studio C++
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <time.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sstream>
#include <deque>
#include <queue>
#include <math.h>
#include <cstring>
#include "cmarkup/Markup.h" //For XML.
#include <locale.h>

#include <mbctype.h>




#include <string.h>

using namespace std;


const int BIT1 = (1 << 0);
const int BIT2 = (1 << 1);
const int BIT3 = (1 << 2);
const int BIT4 = (1 << 3);
const int BIT5 = (1 << 4);
const int BIT6 = (1 << 5);
const int BIT7 = (1 << 6);
const int BIT8 = (1 << 7);
const int BIT9 = (1 << 8);
const int BIT10 = (1 << 9);
const int BIT11 = (1 << 10);
const int BIT12 = (1 << 11);
const int BIT13 = (1 << 12);
const int BIT14 = (1 << 13);
const int BIT15 = (1 << 14);
const int BIT16 = (1 << 15);
const int BIT17 = (1 << 16);
const int BIT18 = (1 << 17);
const int BIT19 = (1 << 18);
const int BIT20 = (1 << 19);
const int BIT21 = (1 << 20);
const int BIT22 = (1 << 21);
const int BIT23 = (1 << 22);
const int BIT24 = (1 << 23);
const int BIT25 = (1 << 24);
const int BIT26 = (1 << 25);
const int BIT27 = (1 << 26);
const int BIT28 = (1 << 27);
const int BIT29 = (1 << 28);
const int BIT30 = (1 << 29);
const int BIT31 = (1 << 30);
const int BIT32 = (1 << 31);
const int MAX_PATH_SIZE = 2048;
const int RNG_SIZE = 4;
/* These 6 random number generator functions are implemented in compat.cpp */
unsigned long getSeed();
unsigned long r_num();
long LCSrandom(long max);
void initMainRNG();
void copyRNG(unsigned long(&dest)[RNG_SIZE], unsigned long(&src)[RNG_SIZE]);
void initOtherRNG(unsigned long(&rng)[RNG_SIZE]);
/* Determine size of vectors and any other container that implements the size() function.
This basically includes all types of containers except for the C++11 std::forward_list. */
template <class Container> inline long len(const Container& x)
{
	return x.size();
}
/* Determine array size in pickrandom() and various functions throughout the code.
Only works on actual arrays, not on vectors or other containers. */
template <typename T, size_t N> inline long len(const T(&x)[N])
{
	return N;
}
/* Override of the prior function for null-terminated C-strings as char arrays.
This override allows pickrandom() to pick a random character from a C-string we have as a char array. */
template <size_t N> inline long len(const char(&x)[N])
{
	return strlen(x);
}
/* Override of the prior function for null-terminated C-strings as char pointers.
This override allows pickrandom() to pick a random character from a C-string we have as a char pointer. */
inline long len(const char* x)
{
	return strlen(x);
}
/* Override for when it doesn't work with const in front of the char*
(compilers are weird about template function overrides) */
inline long len(char* x)
{
	return strlen(x);
}
/* Pick a random element from a vector/deque/map/std::string/C++11 std::array/etc. (e.g. a random string from a vector of strings).
It works on any container class that implements the [] operator, size() function, and value_type typename.
This doesn't work if the vector/deque/map/std::string/C++11 std::array/etc. has zero elements. */
template <class Container> inline typename Container::value_type& pickrandom(const Container& x)
{
	return const_cast<typename Container::value_type&>(x[LCSrandom(len(x))]);
}
/* Pick a random element from an array (e.g. a random string from an array of strings).
This doesn't work if the array has zero elements. */
template <typename T, size_t N> inline T& pickrandom(const T(&x)[N])
{
	return const_cast<T&>(x[LCSrandom(len(x))]);
}
/* Pick a random element from a C-string.
Returns '\x0' (null character) for empty string. */
inline char& pickrandom(const char* x)
{
	return const_cast<char&>(x[LCSrandom(len(x))]);
}
/* Override for when it doesn't work with const in front of the char*
(compilers are weird about template function overrides) */
inline char& pickrandom(char* x)
{
	return x[LCSrandom(len(x))];
}
/* Deletes a specified pointer and sets it to NULL. */
template <typename T> inline void delete_and_nullify(T* &o)
{
	delete o;
	o = NULL;
}
/* Deletes and removes a specified pointer from a container. */
template <class Container> inline void delete_and_remove(Container& c, int i)
{
	if (i <= -1) return; // check for invalid index, and don't delete anything in this case
	delete c[i];
	c.erase(c.begin() + i);
}
/* Deletes and removes a specified pointer from 2 containers it's in.
c1 and c2 must not be the same container! */
template <class Container> inline void delete_and_remove(Container& c1, int i1, Container& c2, int i2)
{
	if (i1 <= -1 || i2 <= -1) return; // check for invalid index, and don't delete anything in this case
	if (c1[i1] == c2[i2])
	{ // it's the same pointer, so just delete it once, then remove it from both containers
		delete_and_remove(c1, i1);
		if (c1 != c2 || i1 != i2) c2.erase(c2.begin() + i2); // remove it from 2nd location, unless 2nd location is identical to 1st location
	}
	else
	{ // it's 2 different pointers, so delete them both and remove them from both containers
		delete_and_remove(c1, i1);
		delete_and_remove(c2, i2);
	}
}
/* Deletes and removes all pointers in a container. */
template <class Container> inline void delete_and_clear(Container& c)
{
	while (len(c))
	{
		delete c.back();
		c.pop_back();
	}
}
/* Deletes and removes all pointers that 2 containers have in common. */
template <class Container> inline void delete_and_clear(Container& c1, Container& c2)
{
	for (int i1 = len(c1) - 1; i1 >= 0; i1--)
		for (int i2 = len(c2) - 1; i2 >= 0; i2--)
			if (c1[i1] == c2[i2]) delete_and_remove(c1, i1, c2, i2);
}

enum LCSIO_FLAGS
{
	LCSIO_PRE_ART = 1, /// Append the given file name to the art directory path.
	LCSIO_PRE_HOME = 2 /// Append the given file name to the home directory path.
};
FILE* LCSOpenFile(const char* filename, const char* mode, int flags);
bool LCSOpenFileCPP(std::string filename, std::ios_base::openmode mode, int flags, std::fstream &file);
void LCSCloseFile(FILE* handle);
void LCSCloseFileCPP(std::fstream &file);
void LCSDeleteFile(const char* filename, int flags);
void LCSRenameFile(const char* old_filename, const char* new_filename, int flags);
//returns a list of all files in homedir with extension .dat
vector<string> LCSSaveFiles();

void pause_ms(int t);
void alarmset(int t);
void alarmwait();
#define CH_USE_CP437



#ifndef NDEBUG
#define NDEBUG
#endif


const int TAB = 9;
const int ENTER = 10;
const int ESC = 27;
const int SPACEBAR = 32;

class Log;

enum Alignment
{
	ALIGN_ARCHCONSERVATIVE = -2,
	ALIGN_CONSERVATIVE,
	ALIGN_MODERATE,
	ALIGN_LIBERAL,
	ALIGN_ELITELIBERAL,
	ALIGN_STALINIST
};

enum UnlockTypes
{
	UNLOCK_DOOR,
	UNLOCK_CAGE,
	UNLOCK_CAGE_HARD,
	UNLOCK_CELL,
	UNLOCK_SAFE,
	UNLOCK_ARMORY,
	UNLOCK_VAULT,
	UNLOCKNUM
};

enum HackTypes
{
	HACK_SUPERCOMPUTER,
	HACK_VAULT,
	HACKNUM
};

enum SpecialAttacks
{
	ATTACK_CANNON,
	ATTACK_FLAME,
	ATTACK_SUCK,
	ATTACKNUM
};

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

enum CCSexposure
{
	CCSEXPOSURE_NONE,
	CCSEXPOSURE_LCSGOTDATA,
	CCSEXPOSURE_EXPOSED,
	CCSEXPOSURE_NOBACKERS,
	CCSEXPOSURENUM
};

const int ARMORFLAG_DAMAGED = BIT1;
const int ARMORFLAG_BLOODY = BIT2;


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


enum AnimalGlosses
{
	ANIMALGLOSS_NONE,//IMPORTANT THAT THIS BE HERE AT ZERO
	ANIMALGLOSS_TANK,
	ANIMALGLOSS_ANIMAL,
	ANIMALGLOSSNUM
};

enum Activity
{
	ACTIVITY_NONE,
	ACTIVITY_VISIT,
	ACTIVITY_HOSTAGETENDING,
	ACTIVITY_TROUBLE,
	ACTIVITY_GRAFFITI,
	ACTIVITY_COMMUNITYSERVICE,
	ACTIVITY_SELL_ART,
	ACTIVITY_SELL_MUSIC,
	ACTIVITY_SELL_TSHIRTS,
	ACTIVITY_DONATIONS,
	ACTIVITY_SELL_DRUGS,
	ACTIVITY_PROSTITUTION,
	ACTIVITY_POLLS,
	ACTIVITY_CCFRAUD,
	ACTIVITY_DOS_RACKET,
	ACTIVITY_DOS_ATTACKS,
	ACTIVITY_HACKING,
	ACTIVITY_REPAIR_ARMOR,
	ACTIVITY_MAKE_ARMOR,
	ACTIVITY_STEALCARS,
	ACTIVITY_WHEELCHAIR,
	ACTIVITY_BURY,
	ACTIVITY_WRITE_BLOG,
	ACTIVITY_WRITE_LETTERS,
	ACTIVITY_WRITE_GUARDIAN,
	ACTIVITY_TEACH_POLITICS,
	ACTIVITY_TEACH_FIGHTING,
	ACTIVITY_TEACH_COVERT,
	ACTIVITY_STUDY_DEBATING,
	ACTIVITY_STUDY_MARTIAL_ARTS,
	ACTIVITY_STUDY_DRIVING,
	ACTIVITY_STUDY_PSYCHOLOGY,
	ACTIVITY_STUDY_FIRST_AID,
	ACTIVITY_STUDY_LAW,
	ACTIVITY_STUDY_DISGUISE,
	ACTIVITY_STUDY_SCIENCE,
	ACTIVITY_STUDY_BUSINESS,
	ACTIVITY_STUDY_GYMNASTICS,
	ACTIVITY_STUDY_MUSIC,
	ACTIVITY_STUDY_ART,
	ACTIVITY_STUDY_TEACHING,
	ACTIVITY_STUDY_WRITING,
	ACTIVITY_STUDY_LOCKSMITHING,
	ACTIVITY_STUDY_COMPUTERS,
	ACTIVITY_STUDY_FENCING,
	ACTIVITY_STUDY_WEAVING,
	ACTIVITY_STUDY_RELIGION,
	ACTIVITY_STUDY_CLUB,
	ACTIVITY_STUDY_STREETSENSE,
	ACTIVITY_STUDY_THROWING,
	ACTIVITY_STUDY_STEALTH,
	ACTIVITY_STUDY_SEDUCTION,
	ACTIVITY_CLINIC,
	ACTIVITY_HEAL,
	ACTIVITY_SLEEPER_LIBERAL,
	ACTIVITY_SLEEPER_CONSERVATIVE,
	ACTIVITY_SLEEPER_SPY,
	ACTIVITY_SLEEPER_RECRUIT,
	ACTIVITY_SLEEPER_SCANDAL,
	ACTIVITY_SLEEPER_EMBEZZLE,
	ACTIVITY_SLEEPER_STEAL,
	ACTIVITY_SLEEPER_JOINLCS,
	ACTIVITY_RECRUITING,
	ACTIVITY_AUGMENT,
	ACTIVITYNUM
};



enum CarChaseObstacles
{
	CARCHASE_OBSTACLE_FRUITSTAND,
	CARCHASE_OBSTACLE_TRUCKPULLSOUT,
	CARCHASE_OBSTACLE_CROSSTRAFFIC,
	CARCHASE_OBSTACLE_CHILD,
	CARCHASE_OBSTACLENUM
};

enum SquadStances
{
	SQUADSTANCE_ANONYMOUS,
	SQUADSTANCE_STANDARD,
	SQUADSTANCE_BATTLECOLORS,
	SQUADSTANCE_MAX
};

const int ENCMAX = 18;
// ENCMAX _HAS_ to be 26 or less, or else there aren't enough letters


enum GameModes
{
	GAMEMODE_TITLE,
	GAMEMODE_BASE,
	GAMEMODE_SITE,
	GAMEMODE_CHASECAR,
	GAMEMODE_CHASEFOOT
};

enum MusicModes
{
	MUSIC_TITLEMODE,
	MUSIC_NEWGAME,
	MUSIC_BASEMODE,
	MUSIC_SIEGE,
	MUSIC_ACTIVATE,
	MUSIC_SLEEPERS,
	MUSIC_STOPEVIL,
	MUSIC_REVIEWMODE,
	MUSIC_LIBERALAGENDA,
	MUSIC_DISBANDED,
	MUSIC_FINANCES,
	MUSIC_CARTHEFT,
	MUSIC_ELECTIONS,
	MUSIC_SHOPPING,
	MUSIC_SITEMODE,
	MUSIC_SUSPICIOUS,
	MUSIC_ALARMED,
	MUSIC_HEAVYCOMBAT,
	MUSIC_DEFENSE,
	MUSIC_CONQUER,
	MUSIC_CARCHASE,
	MUSIC_FOOTCHASE,
	MUSIC_INTERROGATION,
	MUSIC_TRIAL,
	MUSIC_RECRUITING,
	MUSIC_DATING,
	MUSIC_NEWSPAPER,
	MUSIC_LACOPS,
	MUSIC_NEWSCAST,
	MUSIC_GLAMSHOW,
	MUSIC_ANCHOR,
	MUSIC_ABORT,
	MUSIC_VICTORY,
	MUSIC_DEFEAT,
	MUSIC_REAGANIFIED,
	MUSIC_STALINIZED,
	MUSIC_OFF, // this one must come immediately after the ones corresponding to music files (this one is to have silence)
	MUSIC_PREVIOUS, // this one must come after MUSIC_OFF (this one is to play the previous song)
	MUSIC_CURRENT, // this one must come after MUSIC_OFF (this one continues playing the current song)
	MUSIC_RANDOM // this one must come after MUSIC_OFF (this one plays a random song)
};

enum WinConditions
{
	WINCONDITION_ELITE,
	WINCONDITION_EASY
};
enum FieldSkillRates
{
	FIELDSKILLRATE_FAST,
	FIELDSKILLRATE_CLASSIC,
	FIELDSKILLRATE_HARD
};

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

enum Crimes
{
	CRIME_STOLEGROUND,
	CRIME_UNLOCKEDDOOR,
	CRIME_BROKEDOWNDOOR,
	CRIME_ATTACKED_MISTAKE,
	CRIME_ATTACKED,
	CRIME_CARCHASE,
	CRIME_CARCRASH,
	CRIME_FOOTCHASE,
	CRIME_KILLEDSOMEBODY,
	CRIME_SHUTDOWNREACTOR,
	CRIME_POLICE_LOCKUP,
	CRIME_COURTHOUSE_LOCKUP,
	CRIME_PRISON_RELEASE,
	CRIME_JURYTAMPERING,
	CRIME_HACK_INTEL,
	CRIME_BREAK_SWEATSHOP,
	CRIME_BREAK_FACTORY,
	CRIME_HOUSE_PHOTOS,
	CRIME_CORP_FILES,
	CRIME_FREE_RABBITS,
	CRIME_FREE_BEASTS,
	CRIME_ARSON,
	CRIME_TAGGING,
	CRIME_ARMORY,
	CRIME_VANDALISM,
	CRIME_BANKVAULTROBBERY,
	CRIME_BANKTELLERROBBERY,
	CRIME_BANKSTICKUP,
	CRIMENUM
};

enum NewsStories
{
	NEWSSTORY_MAJOREVENT,
	NEWSSTORY_SQUAD_SITE,
	NEWSSTORY_SQUAD_ESCAPED,
	NEWSSTORY_SQUAD_FLEDATTACK,
	NEWSSTORY_SQUAD_DEFENDED,
	NEWSSTORY_SQUAD_BROKESIEGE,
	NEWSSTORY_SQUAD_KILLED_SIEGEATTACK,
	NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE,
	NEWSSTORY_SQUAD_KILLED_SITE,
	NEWSSTORY_CCS_SITE,
	NEWSSTORY_CCS_DEFENDED,
	NEWSSTORY_CCS_KILLED_SIEGEATTACK,
	NEWSSTORY_CCS_KILLED_SITE,
	NEWSSTORY_CARTHEFT,
	NEWSSTORY_MASSACRE,
	NEWSSTORY_KIDNAPREPORT,
	NEWSSTORY_NUDITYARREST,
	NEWSSTORY_WANTEDARREST,
	NEWSSTORY_DRUGARREST,
	NEWSSTORY_GRAFFITIARREST,
	NEWSSTORY_BURIALARREST,
	NEWSSTORY_RAID_CORPSESFOUND,
	NEWSSTORY_RAID_GUNSFOUND,
	NEWSSTORY_HOSTAGE_RESCUED,
	NEWSSTORY_HOSTAGE_ESCAPES,
	NEWSSTORY_CCS_NOBACKERS,
	NEWSSTORY_CCS_DEFEATED,
	NEWSSTORY_PRESIDENT_IMPEACHED,
	NEWSSTORY_PRESIDENT_BELIEVED_DEAD,
	NEWSSTORY_PRESIDENT_FOUND_DEAD,
	NEWSSTORY_PRESIDENT_FOUND,
	NEWSSTORY_PRESIDENT_KIDNAPPED,
	NEWSSTORY_PRESIDENT_MISSING,
	NEWSSTORY_PRESIDENT_ASSASSINATED,
	NEWSSTORYNUM
};

const int SQUAD_NAMELEN = 40;


const int SLOGAN_LEN = 80;

const int SCORENUM = 5;

enum EndTypes
{
	END_BUT_NOT_END = -2,
	END_OTHER = -1,
	END_WON,
	END_HICKS,
	END_CIA,
	END_POLICE,
	END_CORP,
	END_REAGAN,
	END_DEAD,
	END_PRISON,
	END_EXECUTED,
	END_DATING,
	END_HIDING,
	END_DISBANDLOSS,
	END_DISPERSED,
	END_CCS,
	END_FIREMEN,
	END_STALIN,
	ENDNUM
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

// full house (100%) - for looping thru full house
const int  HOUSENUM = 435;
// just over half of house (50%+1) - to pass bills
const int  HOUSEMAJORITY = 218;
// 3/5 of house - has no significance other than in seeing if you won game
const int  HOUSECOMFYMAJORITY = 261;
// 2/3 of house - to override veto or pass constitutional amendment
const int  HOUSESUPERMAJORITY = 290;
// full senate (100%) - for looping thru full senate
const int  SENATENUM = 100;
// just over half of senate(50%+1) - to bass bills
const int  SENATEMAJORITY = 51;
// 3/5 of senate - to break filibuster in real world, but in game, has no significance other than seeing if you won
const int  SENATECOMFYMAJORITY = 60;
// 2/3 of senate - to override veto or pass constitutional amendment
const int  SENATESUPERMAJORITY = 67;
// full court (100%) - for looping thru full court
const int  COURTNUM = 9;
// just over half of court (50%+1) - to make majority rulings
const int  COURTMAJORITY = 5;
// 2/3 of court - has no significance other than seeing if you won game
const int  COURTSUPERMAJORITY = 6;
// all states (100%) - for looping thru all states
const int  STATENUM = 50;
// 3/4 of states (75%) - needed to pass constitutional amendments
const int  STATESUPERMAJORITY = 38;

const int  POLITICIAN_NAMELEN = 80;

enum ReviewModes
{
	REVIEWMODE_LIBERALS,
	REVIEWMODE_HOSTAGES,
	REVIEWMODE_CLINIC,
	REVIEWMODE_JUSTICE,
	REVIEWMODE_SLEEPERS,
	REVIEWMODE_DEAD,
	REVIEWMODE_AWAY,
	REVIEWMODENUM
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

/*
   Declarations for every function grouped by folder and file.
   Created by jonathansfox.
*/

/* This is declared again lower down, just needed here for this header. */
std::string tostring(long i);


//

//#include "vehicle/vehicletype.h"
//#include "vehicle/vehicle.h"


//just a float that is initialized to 0
struct Float_Zero
{
	Float_Zero() : n(0.0f) { }
	operator float&() { return n; }
	float n;
};
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
struct InterrogationST
{
	InterrogationST() : druguse(0) { techniques[0] = 1, techniques[1] = 1, techniques[2] = 0, techniques[3] = 0, techniques[4] = 0, techniques[5] = 0; }
	bool techniques[6]; //yesterday's InterrogationST plan
	int druguse; //total days of drug use
				 //Maps individual characters to the rapport built with them
	map<long, struct Float_Zero> rapport;
};

struct ActivityST
{
	ActivityST() : type(0), arg(0), arg2(0) { }
	int type;
	long arg, arg2;
	// return a reference to arg, with arg typecast as a pointer to an object of type InterrogationST,
	// allowing us to easily access and modify the InterrogationST data without typecasting outside this function
	InterrogationST* &intr() { InterrogationST** i = reinterpret_cast<InterrogationST**>(&arg); return *i; }
};

int get_associated_attribute(int skill_type);


enum Bouncer_Reject_Reason
{
	REJECTED_CCS,
	REJECTED_NUDE,
	REJECTED_WEAPONS,
	REJECTED_UNDERAGE,
	REJECTED_FEMALEISH,
	REJECTED_FEMALE,
	REJECTED_BLOODYCLOTHES,
	REJECTED_DAMAGEDCLOTHES,
	REJECTED_CROSSDRESSING,
	REJECTED_GUESTLIST,
	REJECTED_DRESSCODE,
	REJECTED_SECONDRATECLOTHES,
	REJECTED_SMELLFUNNY,
	NOT_REJECTED
};


enum bigListOfEnumTags {
	ENUM_tag_only_sell_legal_items,
	ENUM_tag_fullscreen,
	ENUM_tag_allow_selling,
	ENUM_tag_increase_prices_with_illegality,
	ENUM_tag_department,
	ENUM_tag_entry,
	ENUM_tag_exit,
	ENUM_tag_sell_masks,
	ENUM_tag_letter,
	ENUM_tag_item,

	ENUM_tag_class,
	ENUM_tag_type,
	ENUM_tag_description,
	ENUM_tag_price,
	ENUM_tag_sleeperprice,

	ENUM_tag_alignment,
	ENUM_tag_PUBLIC_MOOD,
	ENUM_tag_LIBERAL,
	ENUM_tag_MODERATE,
	ENUM_tag_CONSERVATIVE,
	ENUM_tag_age,
	ENUM_tag_DOGYEARS,
	ENUM_tag_CHILD,
	ENUM_tag_TEENAGER,
	ENUM_tag_YOUNGADULT,
	ENUM_tag_MATURE,
	ENUM_tag_GRADUATE,
	ENUM_tag_MIDDLEAGED,
	ENUM_tag_SENIOR,
	ENUM_tag_attribute_points,
	ENUM_tag_attributes,
	ENUM_tag_juice,
	ENUM_tag_gender,
	ENUM_tag_infiltration,
	ENUM_tag_money,
	ENUM_tag_skills,
	ENUM_tag_armor,
	ENUM_tag_weapon,
	ENUM_tag_encounter_name,
	ENUM_tag_type_name,

	ENUM_tag_shortname,
	ENUM_tag_shortname_future,
	ENUM_tag_name_sub_1,
	ENUM_tag_name_sub_2,
	ENUM_tag_name_future_sub_1,
	ENUM_tag_name_future_sub_2,
	ENUM_tag_shortname_sub_1,
	ENUM_tag_shortname_sub_2,
	ENUM_tag_shortname_future_sub_1,
	ENUM_tag_shortname_future_sub_2,
	ENUM_tag_can_take_hostages,
	ENUM_tag_threatening,
	ENUM_tag_can_threaten_hostages,
	ENUM_tag_protects_against_kidnapping,
	ENUM_tag_musical_attack,
	ENUM_tag_instrument,
	ENUM_tag_graffiti,
	ENUM_tag_legality,
	ENUM_tag_bashstrengthmod,
	ENUM_tag_auto_break_locks,
	ENUM_tag_suspicious,
	ENUM_tag_size,
	ENUM_tag_attack,

	ENUM_tag_priority,
	ENUM_tag_ranged,
	ENUM_tag_thrown,
	ENUM_tag_can_backstab,
	ENUM_tag_ammotype,
	ENUM_tag_attack_description,
	ENUM_tag_hit_description,
	ENUM_tag_always_describe_hit,
	ENUM_tag_hit_punctuation,
	ENUM_tag_skill,
	ENUM_tag_accuracy_bonus,
	ENUM_tag_number_attacks,
	ENUM_tag_successive_attacks_difficulty,
	ENUM_tag_strength_min,
	ENUM_tag_strength_max,
	ENUM_tag_random_damage,
	ENUM_tag_fixed_damage,
	ENUM_tag_bruises,
	ENUM_tag_tears,
	ENUM_tag_cuts,
	ENUM_tag_burns,
	ENUM_tag_shoots,
	ENUM_tag_bleeding,
	ENUM_tag_severtype,
	ENUM_tag_damages_armor,
	ENUM_tag_armorpiercing,
	ENUM_tag_no_DR_for_limbs_chance,
	ENUM_tag_critical,
	ENUM_tag_fire,

	ENUM_tag_name,
	ENUM_tag_attribute,
	ENUM_tag_effect,
	ENUM_tag_max_age,
	ENUM_tag_min_age,
	ENUM_tag_cost,
	ENUM_tag_difficulty,

	ENUM_tag_make_difficulty,
	ENUM_tag_make_price,
	ENUM_tag_deathsquad_legality,
	ENUM_tag_can_get_bloody,
	ENUM_tag_can_get_damaged,
	ENUM_tag_body_covering,
	ENUM_tag_interrogation,
	ENUM_tag_professionalism,
	ENUM_tag_conceal_weapon_size,
	ENUM_tag_stealth_value,
	ENUM_tag_mask,
	ENUM_tag_surprise,
	ENUM_tag_qualitylevels,
	ENUM_tag_durability,

	ENUM_tag_vtypeidname,
	ENUM_tag_vtypeid,
	ENUM_tag_color,
	ENUM_tag_heat,
	ENUM_tag_location,
	ENUM_tag_myear,
	ENUM_tag_id,

	ENUM_tag_year,
	ENUM_tag_start_at_current_year,
	ENUM_tag_start_at_year,
	ENUM_tag_add_random_up_to_current_year,
	ENUM_tag_add_random,
	ENUM_tag_add,
	ENUM_tag_colors,
	ENUM_tag_display_color,
	ENUM_tag_drivebonus,
	ENUM_tag_base,
	ENUM_tag_skillfactor,
	ENUM_tag_softlimit,
	ENUM_tag_hardlimit,
	ENUM_tag_dodgebonus,
	ENUM_tag_attackbonus,
	ENUM_tag_driver,
	ENUM_tag_passenger,
	ENUM_tag_longname,
	ENUM_tag_stealing,
	ENUM_tag_difficulty_to_find,
	ENUM_tag_extra_heat,
	ENUM_tag_sense_alarm_chance,
	ENUM_tag_touch_alarm_chance,
	ENUM_tag_low_armor_min,
	ENUM_tag_low_armor_max,
	ENUM_tag_high_armor_min,
	ENUM_tag_high_armor_max,
	ENUM_tag_armor_midpoint,
	ENUM_tag_available_at_dealership,
};

string skill_enum_to_string(int skill_type);
string showXmlSkill(int skill_, int value_);
string showXmlAttribute(int attribute_, int value_);

const string PACKAGE_VERSION_STR = "4.12.55";
const int version = 41255;
const int lowestloadversion = 40100;
const int lowestloadscoreversion = 31203;


const string singleDot = ".";
const string dotSpace = ". ";
const string COMMA_SPACE = ", ";
const string spaceDashSpace = " - ";
const string spaceParanthesisDollar = " ($";
const string paranthesisDollar = "($";
const string COLON_SPACE = ": ";
const string ampersandC = "&c";
const string CLOSE_PARENTHESIS = ")";
const string percentSign = "%";
const string singleSpace = " ";

const string CHOOSE_A_LIBERAL_TO = "Choose a Liberal squad member to ";

const string AND = " and ";
const string string_sleeper = "Sleeper ";
const string ampersandR = "&r";
const string show_squad_liberal_status = "0 - Show the squad's Liberal status";
const string HASH_CHECK_STATUS_OF_LIBERAL = "# - Check the status of a squad Liberal";
const string O_CHANGE_SQUAD_ORDER = "O - Change the squad's Liberal order";
const string enter_done = "Enter - Done";
const string undefined = "UNDEFINED";
const string exclamationPoint = "!";
const string failedToLoad = "Failed to load ";
const string pressAnyOtherKey = "Press any other key to continue...";
const string pressAnyKeyString = "Press any other key when ready to begin...";
const string city = "CITY: ";
const string tag_heat = "heat";

#ifdef	TALK_CPP
// talk.cpp

#include "../sitemode/sitedisplay.h"
#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
// for renting
#include "../items/money.h"
//#include "../log/log.h"
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
// for void basesquad(squadst *st,long loc);

#include "../combat/fight.h"
	// for void delenc(short e,char loot);
	//void delenc(Creature &tk);
	//void delenc(const int e, const int i);
#include "../combat/fightCreature.h"  
//for void capturecreature(Creature &t);
#include "../locations/locationsPool.h"
void moveEverythingAwayFromSite(int cursite);
#include "../customMaps.h"

/*
daily.cpp
*/
/* active squad visits the arms dealer */
void armsdealer(int loc);

// #include "../combat/fight.h"
// for void delenc(short e,char loot);
void delenc(DeprecatedCreature &tk);
// #include "../locations/locationsPool.h"
void moveEverythingAwayFromSite(int cursite);
void heyMisterDog(DeprecatedCreature &tk);
void heyMisterMonster(DeprecatedCreature &tk);
void talkInCombat(DeprecatedCreature &a, DeprecatedCreature &tk);
char talkToBankTeller(DeprecatedCreature &a, DeprecatedCreature &tk);
char talkToGeneric(DeprecatedCreature &a, DeprecatedCreature &tk);
void wannaHearSomethingDisturbing(DeprecatedCreature &a, DeprecatedCreature &tk);
void talkAboutIssues(DeprecatedCreature &a, DeprecatedCreature &tk);
void doYouComeHereOften(DeprecatedCreature &a, DeprecatedCreature &tk);
void heyINeedAGun(DeprecatedCreature &a, DeprecatedCreature &tk);
void heyIWantToRentARoom(DeprecatedCreature &a, DeprecatedCreature &tk);
void heyIWantToCancelMyRoom(DeprecatedCreature &a, DeprecatedCreature &tk);
bool isThereASiteAlarm();
void setSiteAlarmOne();
void setEncounterZeroExistsFalse();
void giveActiveSquadThisLoot(Item* de);
void locationIsNowRented(int l, int rent);
void basesquad(Deprecatedsquadst *st, long loc);
int getCity(int l);
void newDate(DeprecatedCreature &a, DeprecatedCreature &tk);
void newRecruit(DeprecatedCreature *cr, int c);
vector<NameAndAlignment> getEncounterNameAndAlignment();
int encounterWisdomRoll(const int e);
int getDifficultyBasedOnEncounterWisdom(const int e);
bool isPrisoner(const string tkname);
short getCurrentSite();

extern bool multipleCityMode;
extern char ccs_kills;
extern char newscherrybusted;
extern class Ledger ledger;
extern coordinatest loc_coord;
extern DeprecatedCreature encounter[ENCMAX];
extern Deprecatednewsstoryst *sitestory;
extern Deprecatedsquadst *activesquad;
extern int sitecrime;
extern short attitude[VIEWNUM];
extern short exec[EXECNUM];
extern short fieldskillrate;
extern short lawList[LAWNUM];
extern short sitealarmtimer;
extern short sitealienate;
extern short siteonfire;
extern siteblockst levelmap[MAPX][MAPY][MAPZ];
extern string slogan_str;


vector<vector<string> > no_free_speech_flirt;
vector<vector<string> > pickupLines;
vector<vector<string> > lovingly_talk_to_mutant;
vector<vector<string> > normal_talk_to_mutant;
vector<vector<string> > lovingly_talk_to_dog;
vector<vector<string> > normal_talk_to_dog;

const int PICKUP_LINE_SIZE = 5;
const int DOUBLE_LINE = 2;

const string tag_ARMOR = "ARMOR";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
const string tag_ARMOR_MITHRIL = "ARMOR_MITHRIL";

const string tag_ARMOR_DEATHSQUADUNIFORM = "ARMOR_DEATHSQUADUNIFORM";
const string tag_ARMOR_LABCOAT = "ARMOR_LABCOAT";
const string tag_ARMOR_BUNKERGEAR = "ARMOR_BUNKERGEAR";
const string tag_ARMOR_SWATARMOR = "ARMOR_SWATARMOR";
const string tag_ARMOR_POLICEUNIFORM = "ARMOR_POLICEUNIFORM";
const string tag_ARMOR_POLICEARMOR = "ARMOR_POLICEARMOR";


map<int, vector<SiteTypes> > okaySiteList = {
	map<int, vector<SiteTypes> >::value_type(CREATURE_BOUNCER,
		{
			SITE_BUSINESS_CIGARBAR,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_POLITICIAN,
		{
			SITE_GOVERNMENT_WHITE_HOUSE,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_CORPORATE_CEO,
		{
			SITE_CORPORATE_HEADQUARTERS,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_SECURITYGUARD,
		{
			SITE_RESIDENTIAL_APARTMENT_UPSCALE,
			SITE_LABORATORY_COSMETICS,
			SITE_LABORATORY_GENETIC,
			SITE_GOVERNMENT_COURTHOUSE,
			SITE_GOVERNMENT_INTELLIGENCEHQ,
			SITE_INDUSTRY_SWEATSHOP,
			SITE_INDUSTRY_POLLUTER,
			SITE_INDUSTRY_NUCLEAR,
			SITE_CORPORATE_HEADQUARTERS,
			SITE_CORPORATE_HOUSE,
			SITE_MEDIA_AMRADIO,
			SITE_MEDIA_CABLENEWS,
			SITE_BUSINESS_CIGARBAR,
			SITE_BUSINESS_BANK,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_BANK_MANAGER,
		{
			SITE_BUSINESS_BANK,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_BANK_TELLER,
		{
			SITE_BUSINESS_BANK,

		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_SCIENTIST_LABTECH,
		{
			SITE_LABORATORY_COSMETICS,
			SITE_LABORATORY_GENETIC,
			SITE_INDUSTRY_NUCLEAR,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_SCIENTIST_EMINENT,
		{
			SITE_LABORATORY_COSMETICS,
			SITE_LABORATORY_GENETIC,
			SITE_INDUSTRY_NUCLEAR,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_CORPORATE_MANAGER,
		{
			SITE_LABORATORY_COSMETICS,
			SITE_LABORATORY_GENETIC,
			SITE_INDUSTRY_SWEATSHOP,
			SITE_INDUSTRY_POLLUTER,
			SITE_INDUSTRY_NUCLEAR,
			SITE_CORPORATE_HEADQUARTERS,
			SITE_MEDIA_AMRADIO,
			SITE_MEDIA_CABLENEWS,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_WORKER_SERVANT,
		{
			SITE_CORPORATE_HOUSE,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_WORKER_JANITOR,
		{
			SITE_RESIDENTIAL_TENEMENT,
			SITE_RESIDENTIAL_APARTMENT,
			SITE_RESIDENTIAL_APARTMENT_UPSCALE,
			SITE_LABORATORY_COSMETICS,
			SITE_LABORATORY_GENETIC,
			SITE_HOSPITAL_CLINIC,
			SITE_HOSPITAL_UNIVERSITY,
			SITE_GOVERNMENT_POLICESTATION,
			SITE_GOVERNMENT_COURTHOUSE,
			SITE_GOVERNMENT_PRISON,
			SITE_GOVERNMENT_INTELLIGENCEHQ,
			SITE_INDUSTRY_POLLUTER,
			SITE_INDUSTRY_NUCLEAR,
			SITE_CORPORATE_HEADQUARTERS,
			SITE_MEDIA_AMRADIO,
			SITE_MEDIA_CABLENEWS,
			SITE_BUSINESS_PAWNSHOP,
			SITE_BUSINESS_CRACKHOUSE,
			SITE_BUSINESS_JUICEBAR,
			SITE_BUSINESS_CIGARBAR,
			SITE_BUSINESS_LATTESTAND,
			SITE_BUSINESS_VEGANCOOP,
			SITE_BUSINESS_INTERNETCAFE,
			SITE_BUSINESS_DEPTSTORE,
			SITE_BUSINESS_HALLOWEEN,
			SITE_GOVERNMENT_FIRESTATION,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_WORKER_SWEATSHOP,
		{
			SITE_INDUSTRY_SWEATSHOP,
		}
		),
	map<int, vector<SiteTypes> >::value_type(CREATURE_WORKER_FACTORY_NONUNION,
		{
			SITE_INDUSTRY_POLLUTER,
		}
		),
			map<int, vector<SiteTypes> >::value_type(CREATURE_WORKER_FACTORY_CHILD,
				{
					SITE_INDUSTRY_POLLUTER,
				}
				),
			map<int, vector<SiteTypes> >::value_type(CREATURE_WORKER_SECRETARY,
				{
					SITE_LABORATORY_COSMETICS,
					SITE_LABORATORY_GENETIC,
					SITE_HOSPITAL_CLINIC,
					SITE_HOSPITAL_UNIVERSITY,
					SITE_GOVERNMENT_POLICESTATION,
					SITE_GOVERNMENT_COURTHOUSE,
					SITE_GOVERNMENT_INTELLIGENCEHQ,
					SITE_INDUSTRY_POLLUTER,
					SITE_INDUSTRY_NUCLEAR,
					SITE_CORPORATE_HEADQUARTERS,
					SITE_CORPORATE_HOUSE,
					SITE_MEDIA_AMRADIO,
					SITE_MEDIA_CABLENEWS,
					SITE_GOVERNMENT_FIRESTATION,
					SITE_GOVERNMENT_WHITE_HOUSE,
				}
				),
			map<int, vector<SiteTypes> >::value_type(CREATURE_WORKER_FACTORY_UNION,
				{
					SITE_INDUSTRY_POLLUTER,
				}
				),
		map<int, vector<SiteTypes> >::value_type(CREATURE_LANDLORD,
			{
				SITE_RESIDENTIAL_TENEMENT,
				SITE_RESIDENTIAL_APARTMENT,
				SITE_RESIDENTIAL_APARTMENT_UPSCALE,
			}
			),
		map<int, vector<SiteTypes> >::value_type(CREATURE_TEENAGER,
			{
				SITE_RESIDENTIAL_TENEMENT,
				SITE_RESIDENTIAL_APARTMENT,
				SITE_RESIDENTIAL_APARTMENT_UPSCALE,
				SITE_RESIDENTIAL_SHELTER,
				SITE_CORPORATE_HOUSE,
			}
			),
			map<int, vector<SiteTypes> >::value_type(CREATURE_COP,
				{
					SITE_GOVERNMENT_POLICESTATION,
				}
				),
			map<int, vector<SiteTypes> >::value_type(CREATURE_DEATHSQUAD,
				{
					SITE_GOVERNMENT_POLICESTATION,
				}
				),
		map<int, vector<SiteTypes> >::value_type(CREATURE_FIREFIGHTER,
			{
				SITE_GOVERNMENT_FIRESTATION,
			}
			),
		map<int, vector<SiteTypes> >::value_type(CREATURE_GANGUNIT,
			{
				SITE_GOVERNMENT_POLICESTATION,
			}
			),
			map<int, vector<SiteTypes> >::value_type(CREATURE_SWAT,
				{
					SITE_GOVERNMENT_POLICESTATION,
				}
				),
			map<int, vector<SiteTypes> >::value_type(CREATURE_JUDGE_LIBERAL,
				{
					SITE_GOVERNMENT_COURTHOUSE,
				}
				),
			map<int, vector<SiteTypes> >::value_type(CREATURE_JUDGE_CONSERVATIVE,
				{
					SITE_GOVERNMENT_COURTHOUSE,
				}
				),
			map<int, vector<SiteTypes> >::value_type(CREATURE_SECRET_SERVICE,
				{
					SITE_GOVERNMENT_WHITE_HOUSE,
				}
				),
			map<int, vector<SiteTypes> >::value_type(CREATURE_AGENT,
				{
					SITE_GOVERNMENT_INTELLIGENCEHQ,
				}
				),
		map<int, vector<SiteTypes> >::value_type(CREATURE_RADIOPERSONALITY,
			{
				SITE_MEDIA_AMRADIO,
			}
			),
		map<int, vector<SiteTypes> >::value_type(CREATURE_NEWSANCHOR,
			{
				SITE_MEDIA_CABLENEWS,
			}
			),
				map<int, vector<SiteTypes> >::value_type(CREATURE_GENETIC,
					{
						SITE_LABORATORY_GENETIC,
					}
					),
				map<int, vector<SiteTypes> >::value_type(CREATURE_GUARDDOG,
					{
						SITE_GOVERNMENT_PRISON,
						SITE_GOVERNMENT_INTELLIGENCEHQ,
						SITE_CORPORATE_HOUSE,
						SITE_GOVERNMENT_ARMYBASE,
					}
					),
					map<int, vector<SiteTypes> >::value_type(CREATURE_PRISONER,
						{
							SITE_RESIDENTIAL_TENEMENT,
							SITE_RESIDENTIAL_SHELTER,
						}
						),
					map<int, vector<SiteTypes> >::value_type(CREATURE_JUROR,
						{
							SITE_RESIDENTIAL_APARTMENT,
							SITE_RESIDENTIAL_TENEMENT,
							SITE_RESIDENTIAL_SHELTER,
						}
						),
					map<int, vector<SiteTypes> >::value_type(CREATURE_LAWYER,
						{
							SITE_GOVERNMENT_COURTHOUSE,
							SITE_GOVERNMENT_WHITE_HOUSE,
						}
						),
				map<int, vector<SiteTypes> >::value_type(CREATURE_DOCTOR,
					{
						SITE_DOWNTOWN,
						SITE_UDISTRICT,
					}
					),
				map<int, vector<SiteTypes> >::value_type(CREATURE_PSYCHOLOGIST,
					{
						SITE_DOWNTOWN,
						SITE_UDISTRICT,
					}
					),
				map<int, vector<SiteTypes> >::value_type(CREATURE_NURSE,
					{
						SITE_DOWNTOWN,
						SITE_UDISTRICT,
						SITE_INDUSTRIAL,
					}
					),
					map<int, vector<SiteTypes> >::value_type(CREATURE_SEWERWORKER,
						{
							SITE_DOWNTOWN,
							SITE_UDISTRICT,
							SITE_INDUSTRIAL,
						}
						),
				map<int, vector<SiteTypes> >::value_type(CREATURE_COLLEGESTUDENT,
					{
						SITE_UDISTRICT,
					}
					),
				map<int, vector<SiteTypes> >::value_type(CREATURE_MUSICIAN,
					{
						SITE_DOWNTOWN,
						SITE_UDISTRICT,
						SITE_INDUSTRIAL,
					}
					),
				map<int, vector<SiteTypes> >::value_type(CREATURE_MATHEMATICIAN,
					{
						SITE_UDISTRICT,
					}
					),
				map<int, vector<SiteTypes> >::value_type(CREATURE_TEACHER,
					{
						SITE_DOWNTOWN,
						SITE_UDISTRICT,
						SITE_INDUSTRIAL,
					}
					),
					map<int, vector<SiteTypes> >::value_type(CREATURE_HSDROPOUT,
						{
							SITE_INDUSTRIAL,
						}
						),
					map<int, vector<SiteTypes> >::value_type(CREATURE_BUM,
						{
							SITE_DOWNTOWN,
							SITE_UDISTRICT,

							SITE_INDUSTRIAL,
							SITE_RESIDENTIAL_SHELTER,
						}
						),

				map<int, vector<SiteTypes> >::value_type(CREATURE_GANGMEMBER,
					{
						SITE_BUSINESS_CRACKHOUSE,
					}
					),
						map<int, vector<SiteTypes> >::value_type(CREATURE_CRACKHEAD,
							{
								SITE_BUSINESS_CRACKHOUSE,
							}
							),
						map<int, vector<SiteTypes> >::value_type(CREATURE_PRIEST,
							{
								SITE_DOWNTOWN,
								SITE_UDISTRICT,
								SITE_INDUSTRIAL,
							}
							),
							map<int, vector<SiteTypes> >::value_type(CREATURE_ENGINEER,
								{
									SITE_MEDIA_AMRADIO,
									SITE_MEDIA_CABLENEWS,
									SITE_INDUSTRY_NUCLEAR,
								}
								),
							map<int, vector<SiteTypes> >::value_type(CREATURE_FASTFOODWORKER,
								{
									SITE_DOWNTOWN,
									SITE_UDISTRICT,
									SITE_INDUSTRIAL,
								}
								),
							map<int, vector<SiteTypes> >::value_type(CREATURE_BAKER,
								{
									SITE_DOWNTOWN,
									SITE_UDISTRICT,
									SITE_INDUSTRIAL,
								}
								),
						map<int, vector<SiteTypes> >::value_type(CREATURE_BARISTA,
							{
								SITE_BUSINESS_LATTESTAND,
								SITE_BUSINESS_INTERNETCAFE,
							}
							),
						map<int, vector<SiteTypes> >::value_type(CREATURE_BARTENDER,
							{
								SITE_BUSINESS_CIGARBAR,
								SITE_DOWNTOWN,
								SITE_UDISTRICT,
								SITE_INDUSTRIAL,
							}
							),
						map<int, vector<SiteTypes> >::value_type(CREATURE_TELEMARKETER,
							{
								SITE_DOWNTOWN,
								SITE_UDISTRICT,
								SITE_INDUSTRIAL,
							}
							),
							map<int, vector<SiteTypes> >::value_type(CREATURE_CARSALESMAN,
								{
									SITE_BUSINESS_CARDEALERSHIP,
								}
								),
						map<int, vector<SiteTypes> >::value_type(CREATURE_OFFICEWORKER,
							{
								SITE_LABORATORY_COSMETICS,
								SITE_LABORATORY_GENETIC,
								SITE_HOSPITAL_CLINIC,
								SITE_HOSPITAL_UNIVERSITY,
								SITE_GOVERNMENT_COURTHOUSE,
								SITE_CORPORATE_HEADQUARTERS,
								SITE_MEDIA_AMRADIO,
								SITE_MEDIA_CABLENEWS,
								SITE_BUSINESS_DEPTSTORE,
								SITE_GOVERNMENT_WHITE_HOUSE,
							}
							),
					map<int, vector<SiteTypes> >::value_type(CREATURE_FOOTBALLCOACH,
						{
							SITE_UDISTRICT,
						}
						),
						map<int, vector<SiteTypes> >::value_type(CREATURE_PROSTITUTE,
							{
								SITE_DOWNTOWN,
								SITE_UDISTRICT,
								SITE_INDUSTRIAL,
							}
							),
						map<int, vector<SiteTypes> >::value_type(CREATURE_MAILMAN,
							{
								SITE_DOWNTOWN,
								SITE_UDISTRICT,
								SITE_INDUSTRIAL,
							}
							),
							map<int, vector<SiteTypes> >::value_type(CREATURE_GARBAGEMAN,
								{
									SITE_DOWNTOWN,
									SITE_UDISTRICT,
									SITE_INDUSTRIAL,
								}
								),
						map<int, vector<SiteTypes> >::value_type(CREATURE_PLUMBER,
							{
								SITE_DOWNTOWN,
								SITE_UDISTRICT,
								SITE_INDUSTRIAL,
							}
							),
								map<int, vector<SiteTypes> >::value_type(CREATURE_CHEF,
									{
										SITE_DOWNTOWN,
										SITE_UDISTRICT,
										SITE_INDUSTRIAL,
										SITE_BUSINESS_CIGARBAR,
									}
									),
									map<int, vector<SiteTypes> >::value_type(CREATURE_CONSTRUCTIONWORKER,
										{
											SITE_DOWNTOWN,
											SITE_UDISTRICT,
											SITE_INDUSTRIAL,
										}
										),
									map<int, vector<SiteTypes> >::value_type(CREATURE_AMATEURMAGICIAN,
										{
											SITE_DOWNTOWN,
											SITE_UDISTRICT,
											SITE_INDUSTRIAL,
										}
										),
									map<int, vector<SiteTypes> >::value_type(CREATURE_TANK,
										{
											SITE_GOVERNMENT_ARMYBASE,
										}
										),
							map<int, vector<SiteTypes> >::value_type(CREATURE_MERC,
								{
									SITE_CORPORATE_HEADQUARTERS,
									SITE_CORPORATE_HOUSE,
									SITE_INDUSTRY_NUCLEAR,
									SITE_LABORATORY_GENETIC,
									SITE_BUSINESS_BANK,
								}
								),
								map<int, vector<SiteTypes> >::value_type(CREATURE_HICK,
									{
										SITE_MEDIA_AMRADIO,
										SITE_MEDIA_CABLENEWS,
										SITE_OUTOFTOWN,
									}
									),
								map<int, vector<SiteTypes> >::value_type(CREATURE_VETERAN,
									{
										SITE_DOWNTOWN,
										SITE_UDISTRICT,
										SITE_INDUSTRIAL,
									}
									),
									map<int, vector<SiteTypes> >::value_type(CREATURE_HARDENED_VETERAN,
										{
											SITE_GOVERNMENT_ARMYBASE,
										}
										),
								map<int, vector<SiteTypes> >::value_type(CREATURE_SOLDIER,
									{
										SITE_GOVERNMENT_ARMYBASE,
									}
									),
								map<int, vector<SiteTypes> >::value_type(CREATURE_MILITARYPOLICE,
									{
										SITE_GOVERNMENT_ARMYBASE,
									}
									),
								map<int, vector<SiteTypes> >::value_type(CREATURE_MILITARYOFFICER,
									{
										SITE_GOVERNMENT_ARMYBASE,
									}
									),
							map<int, vector<SiteTypes> >::value_type(CREATURE_SEAL,
								{
									SITE_GOVERNMENT_ARMYBASE,
								}
								),
								map<int, vector<SiteTypes> >::value_type(CREATURE_EDUCATOR,
									{
										SITE_GOVERNMENT_PRISON,
									}
									),
								map<int, vector<SiteTypes> >::value_type(CREATURE_PRISONGUARD,
									{
										SITE_GOVERNMENT_PRISON,
									}
									),
								map<int, vector<SiteTypes> >::value_type(CREATURE_HIPPIE,
									{
										SITE_BUSINESS_VEGANCOOP,
									}
									),
									map<int, vector<SiteTypes> >::value_type(CREATURE_CRITIC_ART,
										{
											SITE_DOWNTOWN,
											SITE_UDISTRICT,
											SITE_INDUSTRIAL,
											SITE_MEDIA_CABLENEWS,
										}
										),
								map<int, vector<SiteTypes> >::value_type(CREATURE_CRITIC_MUSIC,

									{
										SITE_DOWNTOWN,
										SITE_UDISTRICT,
										SITE_INDUSTRIAL,
										SITE_MEDIA_AMRADIO,
									}
									),
										map<int, vector<SiteTypes> >::value_type(CREATURE_SOCIALITE,
											{
												SITE_DOWNTOWN,
												SITE_UDISTRICT,
												SITE_INDUSTRIAL,
											}
											),
											map<int, vector<SiteTypes> >::value_type(CREATURE_PROGRAMMER,
												{
													SITE_DOWNTOWN,
													SITE_UDISTRICT,
													SITE_INDUSTRIAL,
													SITE_GOVERNMENT_INTELLIGENCEHQ,
													SITE_CORPORATE_HEADQUARTERS,
												}
												),
											map<int, vector<SiteTypes> >::value_type(CREATURE_RETIREE,
												{
													SITE_DOWNTOWN,
													SITE_UDISTRICT,
													SITE_INDUSTRIAL,
												}
												),
									map<int, vector<SiteTypes> >::value_type(CREATURE_PAINTER,
										{
											SITE_DOWNTOWN,
											SITE_UDISTRICT,
											SITE_INDUSTRIAL,
										}
										),
										map<int, vector<SiteTypes> >::value_type(CREATURE_SCULPTOR,
											{
												SITE_DOWNTOWN,
												SITE_UDISTRICT,
												SITE_INDUSTRIAL,
											}
											),
										map<int, vector<SiteTypes> >::value_type(CREATURE_AUTHOR,
											{
												SITE_DOWNTOWN,
												SITE_UDISTRICT,
												SITE_INDUSTRIAL,
											}
											),
											map<int, vector<SiteTypes> >::value_type(CREATURE_JOURNALIST,
												{
													SITE_DOWNTOWN,
													SITE_UDISTRICT,
													SITE_INDUSTRIAL,
												}
												),
										map<int, vector<SiteTypes> >::value_type(CREATURE_DANCER,
											{
												SITE_DOWNTOWN,
												SITE_UDISTRICT,
												SITE_INDUSTRIAL,
											}
											),
									map<int, vector<SiteTypes> >::value_type(CREATURE_PHOTOGRAPHER,
										{
											SITE_MEDIA_CABLENEWS,
										}
										),
								map<int, vector<SiteTypes> >::value_type(CREATURE_CAMERAMAN,
									{
										SITE_MEDIA_CABLENEWS,
									}
									),
									map<int, vector<SiteTypes> >::value_type(CREATURE_HAIRSTYLIST,
										{
											SITE_DOWNTOWN,
											SITE_UDISTRICT,
											SITE_INDUSTRIAL,
										}
										),
										map<int, vector<SiteTypes> >::value_type(CREATURE_FASHIONDESIGNER,
											{
												SITE_DOWNTOWN,
												SITE_UDISTRICT,
												SITE_INDUSTRIAL,
											}
											),
										map<int, vector<SiteTypes> >::value_type(CREATURE_CLERK,
											{
												SITE_BUSINESS_JUICEBAR,
												SITE_BUSINESS_LATTESTAND,
												SITE_BUSINESS_INTERNETCAFE,
												SITE_BUSINESS_DEPTSTORE,
												SITE_BUSINESS_HALLOWEEN,
											}
											),
									map<int, vector<SiteTypes> >::value_type(CREATURE_THIEF,
										{
											SITE_DOWNTOWN,
											SITE_UDISTRICT,
											SITE_INDUSTRIAL,
										}
										),
										map<int, vector<SiteTypes> >::value_type(CREATURE_ACTOR,
											{
												SITE_DOWNTOWN,
												SITE_UDISTRICT,
												SITE_INDUSTRIAL,
											}
											),
												map<int, vector<SiteTypes> >::value_type(CREATURE_YOGAINSTRUCTOR,
													{
														SITE_BUSINESS_VEGANCOOP,
													}
													),
													map<int, vector<SiteTypes> >::value_type(CREATURE_MARTIALARTIST,
														{
															SITE_DOWNTOWN,
															SITE_UDISTRICT,
															SITE_INDUSTRIAL,
														}
														),
													map<int, vector<SiteTypes> >::value_type(CREATURE_ATHLETE,
														{
															SITE_UDISTRICT,
														}
														),
													map<int, vector<SiteTypes> >::value_type(CREATURE_BIKER,
														{
															SITE_DOWNTOWN,
															SITE_UDISTRICT,
															SITE_INDUSTRIAL,
														}
														),
											map<int, vector<SiteTypes> >::value_type(CREATURE_TRUCKER,
												{
													SITE_OUTOFTOWN,
												}
												),
												map<int, vector<SiteTypes> >::value_type(CREATURE_TAXIDRIVER,
													{
														SITE_DOWNTOWN,
														SITE_UDISTRICT,
														SITE_INDUSTRIAL,
													}
													),
												map<int, vector<SiteTypes> >::value_type(CREATURE_NUN,
													{
														SITE_DOWNTOWN,
														SITE_UDISTRICT,
														SITE_INDUSTRIAL,
													}
													),
													map<int, vector<SiteTypes> >::value_type(CREATURE_LOCKSMITH,
														{
															SITE_DOWNTOWN,
															SITE_UDISTRICT,
															SITE_INDUSTRIAL,
														}
														),
};
vector<NameAndAlignment> getEncounterNameAndAlignment();
vector<SiteTypes> defaultSiteList = {
	SITE_RESIDENTIAL_SHELTER
};
void delenc(const short e, const char loot);
void liberalizeEncounterIfThisType(const int type);


void printAgreesToComeByLater(const string tkname, const bool extraline, const bool another_extraline);
void printNonHumanRejection(const string tkname, const int tktype, const bool extraline);
void printConservativeRespondsToStupid(const string tkname, const int tktype, const bool extraline);
void printConservativeCounter(const string tkname, const bool extraline, const int lw);
void printThatIsDisturbing(const string tkname, const bool extraline, const int special_case);

void printRejectTalk(const string tkname, const bool extraline);
void printMutantTalkAboutIssues(const string tkname, const int extraline);
void printUnableToSpeakAgree(const string tkname, const bool extraline);
void printRejectPolicePickupLine(const string tkname, const bool extraline);


void printTalkOptionsDuringCombat(const bool hostages, const bool is_cantbluff_two, const bool cop);
void printTalksToThem(const string aname, const int tkalign, const string tkname);
void printTalkAboutIssuesHeader(const string aname);

void printTalkAboutIssuesWhenStupid(const int lw);
void printTalkAboutIssuesTooLiberal(const int lw);
void printTalkAboutIssuesNormal(const int lw, const int tkanimalgloss);
void printBunkerGearBluff(const short onfire);

void printXeIsNotFooled(const string ename, const bool noFreeSpeech);


enum COMMON_XE_DOES_PRINTABLE {

	eprintITalkLikeAConservative,
	eprintEngraveElbereth,
	eprintWeWerentBornYesterday,
	eprintWannaHearSomething,
	eprintLetMeSellYouAGun,
	eprintNotHereDummy,
	eprintWaitUntilItCoolsDown,
	eprintIDontSellToCops,
	eprintIDontSellToNaked,
	eprintINeedAGun,
	eprintJesusItsYours,
	eprintIWantYouToLeave,
	eprintGiveMeTheLCSPrice,
	eprintEnemyIgnoresThreat,
	eprintAnotherOneBacksOff,
	eprintThreatenEnemy,
	eprintThreatenHostages,
	eprintReleaseHostagesHeader,
	eprintRefuseRentDeal,
	eprintNotMyProblem,
	eprintAcceptRentHeader,
	eprintAcceptRentFooter,
	eprintDemandVaultBeOpened,
	eprintIRobTheBank,
	eprintEnemyWatchesHostageDeath,
	eprintSaysWhat,
	eprintPutSomeDamnClothesOn,
	eprintIWantToRent,
	eprintClearOutYourRoom,
	eprintIWantToCancelRent,
	eprintEnemyAllowsHostagesToDie,
	eprintTalkToHeader,

};
void printCommonXeDoesStatement(const COMMON_XE_DOES_PRINTABLE pr, const string aname);


void printSiegeBluff(const string aname, const int siegeType);

void printHowShouldWeRespond(const string aname, const int hostages);
void printHostageNegotiation(const string ename, const int etype, const int ealign, const int hostages);
void printReleaseHostagesFooter(const int hostages);
void printLetUsGoAndTheyGoFree(const string aname, const int hostages);
void printTurnsAway(const string tkname, const int tkalign);
void printAnimalDoesntUnderstand(const string tkname, const int tktype);
void printThreatensWithAGun(const string aname, const string aweapon);
void printINeedThisMuchRent(const string tkname, const int rent);

void printBrandishWeapon(const string aname, const string aweapon);
void printDiscardsBody(const string aname, const string pname);

void printTalkToMiddle(const int tkalign, const string tkname, const string tkbio);
void printTalkToFooter(const bool is_naked, const bool can_date);

void printSpecialRecruitment(const string aname, const string tkname, const string pitch, const string response);
void printAcceptsPickupLine(const string aname, const string tkname, const vector<string> selected_flirt);
void printRejectsPickupLine(const string tkname, const int tktype, const int agender_liberal, const vector<string> selected_flirt);
void printPickupLine(const string aname, const vector<string> selected_flirt);

enum COMMON_PRINTABLE {

	eprintTurnsAway,
	eprintTheSquadIsArrested,
	eprintTheEnemyIsFooled,
	eprintDeathSquadBluff,
	eprintLabCoatBluff,
	eprintPoliceBluff,
	eprintPloyWorksEnemyBacksOff,
	eprintExecutionGunshot,
	eprintExecutionBareHands,
	eprintYourPossessionsAreRelocated,
	eprintBankerCooperates,
	eprintTheVaultIsOpen,
	eprintGuardsCloseIn,
	eprintTellerComplies,
	eprintTellerAlertsCops,

	eprintOptionsWithinBank,
	eprintTalkToPotentialLandlord,
	eprintTalkToLandlord,
	eprintTalkToGangMemberOrMerc,
	eprintTalkToBankTeller,

	eprintOptionsWithinBankWhileNaked,
	eprintTalkToPotentialLandlordWhileNaked,
	eprintTalkToLandlordWhileNaked,
	eprintTalkToGangMemberOrMercWhileNaked,
	eprintTalkToBankTellerWhileNaked,

	eprintRentingOptions,
	eprintRentingOptionsCannotAfford,

};
void printCommonStatement(const COMMON_PRINTABLE pr);

void pressAnyKey();
int getkeyAlt();
int pressSpecificKey(const int x, const int y);
int pressSpecificKey(const int x, const int y, const int z);
#endif	// TALK_CPP
#endif // INCLUDES_H_INCLUDED
