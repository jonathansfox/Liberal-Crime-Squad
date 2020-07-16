




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

enum BillStatus
{
	BILL_SIGNED = -2,
	BILL_OVERRIDE_VETO = -1,
	BILL_PASSED_CONGRESS = 0,
	BILL_FAILED = 1
};
#ifdef	LCSMONTHLY_CPP
// lcsmonthly.cpp

#include "../creature/newcreature.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../items/itemPool.h"
#include "../items/lootTypePool.h"
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
// for addpage and delimiter
//#include "../common/equipment.h"
void consolidateloot(vector<Item *> &loot);
//#include "../common/translateid.h"
int getloottype(const string &idname);
void removeItemFromSquad(const int loottypeindex);
#include "../common/commonactions.h"
// for void change_public_opinion(int,int,char =1,char=100);
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
map<short, string> expenseTypes;
map<short, string> incomeTypes;
void constructLootIndices(vector<bool> &havetype, vector<int> &loottypeindex, const vector<string> dox);

extern CCSexposure ccsexposure;
extern char disbanding;
extern class Ledger ledger;
extern Log gamelog;
extern MusicClass music;
extern short lawList[LAWNUM];
extern short offended_amradio;
extern short offended_cablenews;
extern short offended_cia;
extern short offended_corps;
extern short offended_firemen;

const string THIS_IS_BOUND_TO_RILE_UP_CORPS = "This is bound to get the Corporations a little riled up.";
const string major_news_take_it_up = "The major networks and publications take it up and run it for weeks.";

const string CONST_PROMISING_SOMEONE_COMPANY_PROFITS_IN_EXCHANGE_FOR_SEXUAL_FAVORS = "promising someone company profits in exchange for sexual favors.";
const string CONST_THAT_SEEM_TO_TOUCH_ON_EVERY_FETISH_KNOWN_TO_MAN = "that seem to touch on every fetish known to man.";
const string CONST_TO_THE_FDA_OFFICIAL_OVERSEEING_THE_CEO_S_PRODUCTS = "to the FDA official overseeing the CEO's products.";
const string CONST_IMPLYING_THAT_HE_HAS_ENSLAVED_HIS_HOUSESERVANTS = "implying that he has enslaved his houseservants.";
const string CONST_TO_HIMSELF_THEY_RE_VERY_STEAMY = "to himself.  They're very steamy.";
const string CONST_TO_AN_ILLICIT_GAY_LOVER = "to an illicit gay lover.";
const string CONST_TO_THE_JUDGE_THAT_ACQUIT_HIM_IN_A_CORRUPTION_TRIAL = "to the judge that acquit him in a corruption trial.";
const string CONST_ADDRESSED_TO_HIS_PET_DOG_YIKES = "addressed to his pet dog.  Yikes.";

const string CONST_PLAYING_WITH_FECES_AND_URINE = "playing with feces and urine.";
const string CONST_TORTURING_AN_EMPLOYEE_WITH_A_HOT_IRON = "torturing an employee with a hot iron.";
const string CONST_WAVING_A_NAZI_FLAG_AT_A_SUPREMACIST_RALLY = "waving a Nazi flag at a supremacist rally.";
const string CONST_CASTRATING_HIMSELF = "castrating himself.";
const string CONST_MAKING_OUT_WITH_AN_FDA_OFFICIAL_OVERSEEING_THE_CEO_S_PRODUCTS = "making out with an FDA official overseeing the CEO's products.";
const string CONST_TONGUE_KISSING_AN_INFAMOUS_DICTATOR = "tongue-kissing an infamous dictator.";
const string CONST_ENGAGING_IN_HEAVY_BONDAGE_A_CUCUMBER_WAS_INVOLVED_IN_SOME_WAY = "engaging in heavy bondage.  A cucumber was involved in some way.";
const string CONST_PARTICIPATING_IN_A_MURDER = "participating in a murder.";
const string CONST_DIGGING_UP_GRAVES_AND_SLEEPING_WITH_THE_DEAD = "digging up graves and sleeping with the dead.";
const string CONST_ENGAGING_IN_LEWD_BEHAVIOR_WITH_ANIMALS = "engaging in lewd behavior with animals.";
const string CONST_SHOWING_THAT_HE_HAS_ENGAGED_IN_CONSISTENT_TAX_EVASION = "showing that he has engaged in consistent tax evasion.";
const string CONST_DESCRIBING_AN_INTRICATE_TAX_SCHEME = "describing an intricate tax scheme.";
const string CONST_CHEERFULLY_DESCRIBING_FOREIGN_CORPORATE_SWEATSHOPS = "cheerfully describing foreign corporate sweatshops.";
const string CONST_CONTAINING_A_MEMO_TERMINATE_THE_PREGNANCY_I_TERMINATE_YOU = "containing a memo: \"Terminate the pregnancy, I terminate you.\"";
const string CONST_WITH_A_LIST_OF_GAY_EMPLOYEES_ENTITLED_HOMO_WORKERS = "with a list of gay employees entitled \"Homo-workers\".";
const string CONST_DESCRIBING_A_GENETIC_MONSTER_CREATED_IN_A_LAB = "describing a genetic monster created in a lab.";
const string CONST_DOCUMENTING_THE_INFILTRATION_OF_A_PRO_CHOICE_GROUP = "documenting the infiltration of a pro-choice group.";
const string CONST_USED_TO_KEEP_TABS_ON_GAY_CITIZENS = "used to keep tabs on gay citizens.";
const string CONST_DOCUMENTING_HARMFUL_SPEECH_MADE_BY_INNOCENT_CITIZENS = "documenting \"harmful speech\" made by innocent citizens.";
const string CONST_CONTAINING_PRIVATE_INFORMATION_ON_INNOCENT_CITIZENS = "containing private information on innocent citizens.";
const string CONST_DOCUMENTING_THE_PLANNED_ASSASSINATION_OF_A_LIBERAL_FEDERAL_JUDGE = "documenting the planned assassination of a Liberal federal judge.";
const string CONST_DOCUMENTING_THE_OVERTHROW_OF_A_GOVERNMENT = "documenting the overthrow of a government.";

const string CONST_DOCUMENTING_WIDESPREAD_CORRUPTION_IN_THE_FORCE = "documenting widespread corruption in the force.";
const string CONST_DOCUMENTING_A_FORCED_CONFESSION = "documenting a forced confession.";
const string CONST_DOCUMENTING_A_SYSTEMATIC_INVASION_OF_PRIVACY_BY_THE_FORCE = "documenting a systematic invasion of privacy by the force.";
const string CONST_DOCUMENTING_A_POLICE_TORTURE_CASE = "documenting a police torture case.";
const string CONST_DOCUMENTING_HUMAN_RIGHTS_ABUSES_BY_THE_FORCE = "documenting human rights abuses by the force.";

const string CONST_DOCUMENTING_GLADIATORIAL_MATCHES_HELD_BETWEEN_PRISONERS_BY_GUARDS = "documenting gladiatorial matches held between prisoners by guards.";
const string CONST_PROMISING_CONSERVATIVE_RULINGS_IN_EXCHANGE_FOR_APPOINTMENTS = "promising Conservative rulings in exchange for appointments.";
const string CONST_TAKING_BRIBES_TO_ACQUIT_MURDERERS = "taking bribes to acquit murderers.";

const string CONST_SHOWING_HUMAN_TEST_SUBJECTS_DYING_UNDER_GENETIC_RESEARCH = "showing human test subjects dying under genetic research.";
const string CONST_COVERING_UP_THE_ACCIDENTAL_CREATION_OF_A_GENETIC_MONSTER = "covering up the accidental creation of a genetic monster.";
const string CONST_STUDYING_THE_EFFECTS_OF_TORTURE_ON_CATS = "studying the effects of torture on cats.";
const string CONST_DOCUMENTING_HORRIFIC_ANIMAL_RIGHTS_ABUSES = "documenting horrific animal rights abuses.";


const string CONST_DOCUMENTING_WIDESPREAD_CORRUPTION_AMONG_PRISON_EMPLOYEES = "documenting widespread corruption among prison employees.";
const string CONST_DOCUMENTING_A_PRISON_TORTURE_CASE = "documenting a prison torture case.";
const string CONST_DOCUMENTING_HUMAN_RIGHTS_ABUSES_BY_PRISON_GUARDS = "documenting human rights abuses by prison guards.";


const string CONST_PLANNING_TO_DRUM_UP_A_FALSE_SCANDAL_ABOUT_A_LIBERAL_FIGURE = "planning to drum up a false scandal about a Liberal figure.";
const string CONST_INSTRUCTING_A_FEMALE_ANCHOR_TO_GET_SEXIER_OR_GET_A_NEW_JOB = "instructing a female anchor to 'get sexier or get a new job'.";
const string CONST_MANDATING_NEGATIVE_COVERAGE_OF_LIBERAL_POLITICIANS = "mandating negative coverage of Liberal politicians.";
const string CONST_CALLING_THEIR_NEWS_THE_VANGUARD_OF_CONSERVATIVE_THOUGHT = "calling their news 'the vanguard of Conservative thought'.";

const string CONST_SAYING_IT_S_OKAY_TO_LIE_THEY_DON_T_NEED_THE_TRUTH = "saying 'it's okay to lie, they don't need the truth'.";
const string CONST_CALLING_LISTENERS_SHEEP_TO_BE_TOLD_WHAT_TO_THINK = "calling listeners 'sheep to be told what to think'.";


const string CONST_PRESS_ANY_KEY_TO_REFLECT_ON_THE_REPORT = "Press any key to reflect on the report.";
const string CONST_PRESS_ENTER_TO_REFLECT_ON_THE_REPORT = "Press Enter to reflect on the report.  ";
const string DOLLAR_SIGN = "$";
const string CONST_TOTAL_LIQUID_ASSETS = "Total Liquid Assets:";
const string CONST_MISCELLANEOUS_LOOT = "Miscellaneous Loot";
const string CONST_AMMUNITION = "Ammunition";
const string CONST_CLOTHING_AND_ARMOR = "Clothing and Armor";
const string CONST_TOOLS_AND_WEAPONS = "Tools and Weapons";
const string CONST_CASH = "Cash";
const string DOLLAR_ZERO = " ($0)";
const string PAREN_MINUS_DOLLAR = " (-$";
const string PAREN_PLUS_DOLLAR = " (+$";
const string CONST_X_MINUS_SIGN = "-";
const string CONST_X_PLUS_SIGN = "+";
const string CONST_NET_CHANGE_THIS_MONTH_DAY = "Net Change This Month (Day):";
const string MINUS_DOLLAR = "-$";
const string PLUS_DOLLAR = "+$";
const string CONST_LIBERAL_CRIME_SQUAD_FUNDING_REPORT = "Liberal Crime Squad: Funding Report";
const string CONST_THIS_IS_BOUND_TO_GET_THE_CONSERVATIVE_MASSES_A_LITTLE_RILED_UP = "This is bound to get the Conservative masses a little riled up.";

const string CONST_THE_LIBERAL_GUARDIAN_RUNS_A_STORY_FEATURING_AM_RADIO_PLANS = "The Liberal Guardian runs a story featuring AM radio plans ";

const string CONST_THE_LIBERAL_GUARDIAN_RUNS_A_STORY_FEATURING_CABLE_NEWS_MEMOS = "The Liberal Guardian runs a story featuring cable news memos ";

const string CONST_THE_LIBERAL_GUARDIAN_RUNS_A_STORY_FEATURING_PRISON_DOCUMENTS = "The Liberal Guardian runs a story featuring prison documents ";

const string CONST_THE_LIBERAL_GUARDIAN_RUNS_A_STORY_FEATURING_RESEARCH_PAPERS = "The Liberal Guardian runs a story featuring research papers ";

const string CONST_THE_LIBERAL_GUARDIAN_RUNS_A_STORY_WITH_EVIDENCE_OF_A_CONSERVATIVE_JUDGE = "The Liberal Guardian runs a story with evidence of a Conservative judge ";

const string CONST_THE_LIBERAL_GUARDIAN_RUNS_A_STORY_FEATURING_POLICE_RECORDS = "The Liberal Guardian runs a story featuring police records ";
const string CONST_THIS_IS_BOUND_TO_GET_THE_GOVERNMENT_A_LITTLE_RILED_UP = "This is bound to get the Government a little riled up.";

const string CONST_THE_LIBERAL_GUARDIAN_RUNS_A_STORY_FEATURING_CIA_AND_OTHER_INTELLIGENCE_FILES = "The Liberal Guardian runs a story featuring CIA and other intelligence files ";
const string CONST_THIS_IS_THE_BEGINNING_OF_THE_END_FOR_THE_CONSERVATIVE_CRIME_SQUAD = "This is the beginning of the end for the Conservative Crime Squad.";
const string CONST_NEWS_DENOUNCE_THE_CCS = "News denounce the CCS.";
const string CONST_TOWARD_THE_REVELATIONS_AND_THE_SPEED_WITH_WHICH_EVEN_AM_RADIO_AND_CABLE = "toward the revelations, and the speed with which even AM Radio and Cable";
const string CONST_FOR_MONTHS_ONE_THING_IS_CLEAR_HOWEVER_FROM_THE_IMMEDIATE_PUBLIC_REACTION = "for months. One thing is clear, however, from the immediate public reaction";
const string CONST_COUNTRY_AND_THE_FULL_RAMIFICATIONS_OF_THIS_REVELATION_MAY_NOT_BE_FELT = "country, and the full ramifications of this revelation may not be felt";
const string CONST_THE_SCANDAL_REACHES_INTO_THE_HEART_OF_THE_CONSERVATIVE_LEADERSHIP_IN_THE = "The scandal reaches into the heart of the Conservative leadership in the";
const string CONST_AGAINST = "against.";
const string CONST_AS_A_FOIL_WHEN_NO_OTHER_ENEMIES_WERE_PRESENT_TO_DIRECT_PUBLIC_ENERGY = "as a foil when no other enemies were present to direct public energy";
const string CONST_ABOVE_PROSECUTION_AND_COULD_HUNT_DOWN_LAW_ABIDING_LIBERALS_AND_ACT = "above prosecution, and could hunt down law-abiding Liberals and act";
const string CONST_EXTENSIVE_PLANNING_TO_CREATE_AN_EXTRA_JUDICIAL_DEATH_SQUAD_THAT_WOULD_BE = "extensive planning to create an extra-judicial death squad that would be";
const string CONST_IN_THE_STATE_AND_FEDERAL_GOVERNMENTS_SECTIONS_PRECISELY_DOCUMENT_THE = "in the state and federal governments. Sections precisely document the";
const string CONST_RESPONSIBILITIES_OF_CONSERVATIVE_CRIME_SQUAD_SYMPATHIZERS_AND_SUPPORTERS = "responsibilities of Conservative Crime Squad sympathizers and supporters";
const string CONST_THE_CCS_ORGANIZATION_ALSO_REVEALING_IN_EXTREME_DETAIL_THE_NAMES_AND = "the CCS organization, also revealing in extreme detail the names and ";
const string CONST_THE_LIBERAL_GUARDIAN_RUNS_MORE_THAN_ONE_THOUSAND_PAGES_OF_DOCUMENTS_ABOUT = "The Liberal Guardian runs more than one thousand pages of documents about ";

const string CONST_THE_LIBERAL_GUARDIAN_RUNS_A_STORY_FEATURING_CORPORATE_FILES = "The Liberal Guardian runs a story featuring Corporate files ";
const string CONST_THE_LIBERAL_GUARDIAN_RUNS_A_STORY_FEATURING_A_MAJOR_CEO_S_TAX_PAPERS = "The Liberal Guardian runs a story featuring a major CEO's tax papers ";

const string CONST_THE_LIBERAL_GUARDIAN_RUNS_A_STORY_FEATURING_LOVE_LETTERS_FROM_A_MAJOR_CEO = "The Liberal Guardian runs a story featuring love letters from a major CEO ";

const string CONST_THE_LIBERAL_GUARDIAN_RUNS_A_STORY_FEATURING_PHOTOS_OF_A_MAJOR_CEO = "The Liberal Guardian runs a story featuring photos of a major CEO ";
const string CONST_ENTER_NOT_IN_THIS_MONTH_S_LIBERAL_GUARDIAN = "Enter - Not in this month's Liberal Guardian";
const string CONST_DO_YOU_WANT_TO_RUN_A_SPECIAL_EDITION = "Do you want to run a special edition?";
const string CONST_X_LIBERAL_GUARDIAN = "Liberal Guardian.";
const string CONST_THE_RESPONSE_IS_ELECTRIC_EVERYONE_IS_TALKING_ABOUT_THIS_MONTH_S = "The response is electric. Everyone is talking about this month's ";
const string CONST_THE_RESPONSE_IS_VERY_STRONG_PEOPLE_ARE_CHANGING_THEIR_MINDS = "The response is very strong. People are changing their minds.";
const string CONST_MANY_PEOPLE_ARE_READING_IT = "Many people are reading it.";
const string CONST_A_FAIR_NUMBER_OF_PEOPLE_ARE_READING_IT = "A fair number of people are reading it.";
const string CONST_VERY_FEW_PEOPLE_SEEM_TO_BE_INTERESTED = "Very few people seem to be interested.";
const string CONST_UNFORTUNATELY_NOBODY_SEEMS_INTERESTED = "Unfortunately, nobody seems interested.";
const string CONST_THE_ONLY_READERS_ARE_CONSERVATIVES_WHO_SEEM_TO_THINK_IT_S_FUNNY = "The only readers are Conservatives, who seem to think it's funny.";
const string CONST_IS_PUBLISHED = " is published.";
const string CONST_THE_MONTHLY_LIBERAL_GUARDIAN_ONLINE_NEWSLETTER = "The monthly Liberal Guardian online newsletter";
const string CONST_THE_MONTHLY_LIBERAL_GUARDIAN_NEWSPAPER = "The monthly Liberal Guardian newspaper";

const string tag_LOOT_AMRADIOFILES = "LOOT_AMRADIOFILES";
const string tag_LOOT = "LOOT";
const string tag_LOOT_CABLENEWSFILES = "LOOT_CABLENEWSFILES";
const string tag_LOOT_PRISONFILES = "LOOT_PRISONFILES";
const string tag_LOOT_RESEARCHFILES = "LOOT_RESEARCHFILES";
const string tag_LOOT_JUDGEFILES = "LOOT_JUDGEFILES";
const string tag_LOOT_POLICERECORDS = "LOOT_POLICERECORDS";
const string tag_LOOT_SECRETDOCUMENTS = "LOOT_SECRETDOCUMENTS";
const string tag_LOOT_INTHQDISK = "LOOT_INTHQDISK";
const string tag_LOOT_CCS_BACKERLIST = "LOOT_CCS_BACKERLIST";
const string tag_LOOT_CORPFILES = "LOOT_CORPFILES";
const string tag_LOOT_CEOTAXPAPERS = "LOOT_CEOTAXPAPERS";
const string tag_LOOT_CEOLOVELETTERS = "LOOT_CEOLOVELETTERS";
const string tag_LOOT_CEOPHOTOS = "LOOT_CEOPHOTOS";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";

enum lootTypeTags {
	ENUM_tag_LOOT_CEOPHOTOS,
	ENUM_tag_LOOT_CEOLOVELETTERS,
	ENUM_tag_LOOT_CEOTAXPAPERS,
	ENUM_tag_LOOT_CORPFILES,
	ENUM_tag_LOOT_CCS_BACKERLIST,
	ENUM_tag_LOOT_INTHQDISK,
	ENUM_tag_LOOT_SECRETDOCUMENTS,
	ENUM_tag_LOOT_POLICERECORDS,
	ENUM_tag_LOOT_JUDGEFILES,
	ENUM_tag_LOOT_RESEARCHFILES,
	ENUM_tag_LOOT_PRISONFILES,
	ENUM_tag_LOOT_CABLENEWSFILES,
	ENUM_tag_LOOT_AMRADIOFILES,
};
map<string, int> lootTypeIDEnum = {
	map<string, int> ::value_type(tag_LOOT_CEOPHOTOS, ENUM_tag_LOOT_CEOPHOTOS),
	map<string, int> ::value_type(tag_LOOT_CEOLOVELETTERS, ENUM_tag_LOOT_CEOLOVELETTERS),
	map<string, int> ::value_type(tag_LOOT_CEOTAXPAPERS, ENUM_tag_LOOT_CEOTAXPAPERS),
	map<string, int> ::value_type(tag_LOOT_CORPFILES, ENUM_tag_LOOT_CORPFILES),
	map<string, int> ::value_type(tag_LOOT_CCS_BACKERLIST, ENUM_tag_LOOT_CCS_BACKERLIST),
	map<string, int> ::value_type(tag_LOOT_INTHQDISK, ENUM_tag_LOOT_INTHQDISK),
	map<string, int> ::value_type(tag_LOOT_SECRETDOCUMENTS, ENUM_tag_LOOT_SECRETDOCUMENTS),
	map<string, int> ::value_type(tag_LOOT_POLICERECORDS, ENUM_tag_LOOT_POLICERECORDS),
	map<string, int> ::value_type(tag_LOOT_JUDGEFILES, ENUM_tag_LOOT_JUDGEFILES),
	map<string, int> ::value_type(tag_LOOT_RESEARCHFILES, ENUM_tag_LOOT_RESEARCHFILES),
	map<string, int> ::value_type(tag_LOOT_PRISONFILES, ENUM_tag_LOOT_PRISONFILES),
	map<string, int> ::value_type(tag_LOOT_CABLENEWSFILES, ENUM_tag_LOOT_CABLENEWSFILES),
	map<string, int> ::value_type(tag_LOOT_AMRADIOFILES, ENUM_tag_LOOT_AMRADIOFILES),
};
static const char dotdotdot[] = ". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ";
//Temporary, maybe put special edition definition into an xml file. -XML
static const string document_types[] =
{  // This list MUST be in alphabetical order for binary_search() to work right
	tag_LOOT_AMRADIOFILES,
	tag_LOOT_CABLENEWSFILES,
	tag_LOOT_CCS_BACKERLIST,
	tag_LOOT_CEOLOVELETTERS,
	tag_LOOT_CEOPHOTOS,
	tag_LOOT_CEOTAXPAPERS,
	tag_LOOT_CORPFILES,
	tag_LOOT_INTHQDISK,
	tag_LOOT_JUDGEFILES,
	tag_LOOT_POLICERECORDS,
	tag_LOOT_PRISONFILES,
	tag_LOOT_RESEARCHFILES,
	tag_LOOT_SECRETDOCUMENTS
};
#endif	//LCSMONTHLY_CPP
#endif // INCLUDES_H_INCLUDED
