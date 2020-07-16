




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
#ifdef	JUSTICE_CPP
// justice.cpp

const string counts_of = " counts of ";
const string execution_in_three_months = "The execution is scheduled to occur three months from now.";
const string justice = "justice\\";
const string CONST_HIRING_AN_UNDOCUMENTED_WORKER = "hiring an undocumented worker";
const string CONST_X_HIRING_UNDOCUMENTED_WORKERS = "hiring undocumented workers";
const string CONST_MONTHS = " months.";
const string CONST_IS_DUE_TO_BE_EXECUTED_IN = " is due to be executed in ";
const string CONST_IS_DUE_TO_BE_RELEASED_NEXT_MONTH = " is due to be released next month.";
const string CONST_IS_DUE_TO_BE_EXECUTED_NEXT_MONTH = " is due to be executed next month.";
const string CONST_NO_DOUBT_THERE_ARE_SOME_MENTAL_SCARS_BUT_THE_LIBERAL_IS_BACK = "No doubt there are some mental scars, but the Liberal is back.";
const string CONST_HAS_BEEN_RELEASED_FROM_PRISON = " has been released from prison.";
const string CONST_IF_YOU_CAN_T_PROTECT_YOUR_OWN_PEOPLE_WHO_CAN_YOU_PROTECT = "If you can't protect your own people, who can you protect?";
const string CONST_HAS_FAILED_THE_LIBERAL_CRIME_SQUAD = " has failed the Liberal Crime Squad.";
const string CONST_X_BY_SPACE = "by ";
const string CONST_TODAY_THE_CONSERVATIVE_MACHINE_EXECUTED = "Today, the Conservative Machine executed ";
const string CONST_FOR_SHAME = "FOR SHAME:";
const string CONST_DUE_TO_THE_ABOLITION_OF_THE_DEATH_PENALTY = "due to the abolition of the death penalty.";
const string CONST_S_DEATH_SENTENCE_HAS_BEEN_COMMUTED_TO_LIFE = "'s death sentence has been commuted to life, ";
const string CONST_SEEMS_TO_BE_MOSTLY_FINE_THOUGH = " seems to be mostly fine, though.";
const string CONST_IS_KINDA_LOSING_IT_IN_HERE_JUICE_THAT_IS = " is kinda losing it in here. Juice, that is.";
const string CONST_HAS_BECOME_A_MORE_HARDENED_JUICIER_CRIMINAL = " has become a more hardened, Juicier criminal.";
const string CONST_THE_LCS_WILL_RISE_AGAIN_MULTIPLE_LCS_MEMBERS_ESCAPE = "The LCS will rise again! Multiple LCS members escape!";
const string CONST_ANOTHER_IMPRISONED_LCS_MEMBER_ALSO_GETS_OUT = "Another imprisoned LCS member also gets out!";
const string CONST_ESCAPED_FROM_PRISON = " escaped from prison!";
const string CONST_INTENTIONALLY_ODS_ON_SMUGGLED_DRUGS_THEN_BREAKS_OUT_OF_THE_MEDICAL_WARD = " intentionally ODs on smuggled drugs, then breaks out of the medical ward!";
const string CONST_JIMMIES_THE_CELL_DOOR_AND_CUTS_THE_OUTER_FENCE_IN_THE_DEAD_OF_NIGHT = " jimmies the cell door and cuts the outer fence in the dead of night!";
const string CONST_PUTS_ON_SMUGGLED_STREET_CLOTHES_AND_CALMLY_WALKS_OUT_OF_PRISON = " puts on smuggled street clothes and calmly walks out of prison.";
const string CONST_CODES_A_VIRUS_ON_A_SMUGGLED_PHONE_THAT_OPENS_ALL_THE_PRISON_DOORS = " codes a virus on a smuggled phone that opens all the prison doors!";
const string CONST_LEADS_A_RIOT_WITH_DOZENS_OF_PRISONERS_CHANTING_THE_LCS_SLOGAN = " leads a riot with dozens of prisoners chanting the LCS slogan!";
const string CONST_MANAGED_TO_AVOID_LASTING_INJURY = " managed to avoid lasting injury.";
const string CONST_IS_FOUND_DEAD = " is found dead.";
const string CONST_IS_BADLY_HURT_IN_THE_PROCESS = " is badly hurt in the process.";
const string CONST_CONSUMES_DRUGS_THAT_SIMULATE_DEATH_AND_IS_THROWN_OUT_WITH_THE_TRASH = " consumes drugs that simulate death, and is thrown out with the trash!";
const string CONST_PICKS_THE_LOCK_ON_THEIR_LEG_CHAINS_AND_THEN_SNEAKS_AWAY = " picks the lock on their leg chains and then sneaks away!";
const string CONST_WEARS_AN_ELECTRICIAN_S_OUTFIT_AND_RIDES_AWAY_WITH_SOME_CONTRACTORS = " wears an electrician's outfit and rides away with some contractors.";
const string CONST_LEADS_THE_OPPRESSED_PRISONERS_AND_OVERWHELMS_THE_PRISON_GUARDS = " leads the oppressed prisoners and overwhelms the prison guards!";
const string CONST_X_REMAINS_STRONG = " remains strong.";
const string CONST_ABANDONS_THE_LIBERAL_CRIME_SQUAD = " abandons the Liberal Crime Squad!";
const string CONST_ONLY_STAYS_LOYAL_TO_THE_LCS_FOR = " only stays loyal to the LCS for ";
const string CONST_SILENTLY_GROWS_WISER = " silently grows Wiser...";
const string CONST_FEELS_BAD_ABOUT_LCS_ACTIONS_AND_LOSES_JUICE = " feels bad about LCS actions, and loses juice!";
const string CONST_THE_COURT_ACCEPTS_THE_PLEA = "The court accepts the plea.";
const string CONST_NOLO = "nolo";
const string CONST_LESS_A_MONTH_FOR_TIME_ALREADY_SERVED = ", less a month for time already served.";
const string CONST_WILL_BE_RETURNED_TO_PRISON_TO_RESUME_AN_EARLIER_SENTENCE = " will be returned to prison to resume an earlier sentence";
const string CONST_IS_FREE = " is free!";
const string CONST_NOT_GUILTY = "NOT GUILTY!";
const string CONST_THE_PROSECUTION_DECLINES_TO_RE_TRY_THE_CASE = "The prosecution declines to re-try the case.";
const string CONST_THE_CASE_WILL_BE_RE_TRIED_NEXT_MONTH = "The case will be re-tried next month.";
const string CONST_BUT_THEY_CAN_T_REACH_A_VERDICT = "But they can't reach a verdict!";
const string CONST_THE_JURY_HAS_RETURNED_FROM_DELIBERATIONS = "The jury has returned from deliberations.";
const string CONST_THE_JURY_LEAVES_TO_CONSIDER_THE_CASE = "The jury leaves to consider the case.";
const string CONST_TO_ACQUIT = " to acquit)";
const string CONST_NEED = ", need ";
const string CONST_X_SPACE_PARENTHESIS = " (";
const string CONST_HAD_THE_JURY_JUDGE_AND_PROSECUTION_CRYING_FOR_FREEDOM = " had the jury, judge, and prosecution crying for freedom.";
const string CONST_MADE_A_VERY_POWERFUL_CASE = " made a very powerful case.";
const string CONST_WORKED_THE_JURY_VERY_WELL = " worked the jury very well.";
const string CONST_S_ARGUMENTS_WERE_PRETTY_GOOD = "'s arguments were pretty good.";
const string CONST_DID_ALL_RIGHT_BUT_MADE_SOME_MISTAKES = " did all right, but made some mistakes.";
const string CONST_S_CASE_REALLY_SUCKED = "'s case really sucked.";
const string CONST_MAKES_ONE_HORRIBLE_MISTAKE_AFTER_ANOTHER = " makes one horrible mistake after another.";
const string CONST_CONDUCTS_AN_INCREDIBLE_DEFENSE = " conducts an incredible defense.";
const string CONST_AND_SHOUT_NOT_GUILTY_BEFORE_DELIBERATIONS_EVEN_BEGAN = "and shout \"NOT GUILTY!\" before deliberations even began.";
const string CONST_S_ARGUMENTS_MADE_SEVERAL_OF_THE_JURORS_STAND_UP = "'s arguments made several of the jurors stand up ";
const string CONST_THE_DEFENSE_IS_EXTREMELY_COMPELLING = "The defense is extremely compelling.";
const string CONST_THE_DEFENSE_MAKES_THE_PROSECUTION_LOOK_LIKE_AMATEURS = "The defense makes the prosecution look like amateurs.";
const string CONST_THE_DEFENSE_WAS_REALLY_SLICK = "The defense was really slick.";
const string CONST_DEFENSE_ARGUMENTS_WERE_PRETTY_GOOD = "Defense arguments were pretty good.";
const string CONST_THE_DEFENSE_WAS_LACKLUSTER = "The defense was lackluster.";
const string CONST_THE_DEFENSE_IS_TOTALLY_LAME = "The defense is totally lame.";
const string CONST_THE_DEFENSE_ATTORNEY_ACCIDENTALLY_SAID_MY_CLIENT_IS_GUILTY_DURING_CLOSING = "The defense attorney accidentally said \"My client is GUILTY!\" during closing.";
const string CONST_THE_DEFENSE_ATTORNEY_RARELY_SHOWED_UP = "The defense attorney rarely showed up.";
const string CONST_TO_CONVICT = " to convict)";
const string CONST_X_TO_PLUS = " to +";
const string PARENTHESIS_PLUS = " (+";
const string CONST_THE_PROSECUTION_IS_INCREDIBLY_STRONG = "The prosecution is incredibly strong.";
const string CONST_THE_PROSECUTION_MAKES_AN_AIRTIGHT_CASE = "The prosecution makes an airtight case.";
const string CONST_THE_PROSECUTION_S_CASE_IS_SOLID = "The prosecution's case is solid.";
const string CONST_THE_PROSECUTION_GIVES_A_STANDARD_PRESENTATION = "The prosecution gives a standard presentation.";
const string CONST_THE_PROSECUTION_S_PRESENTATION_IS_TERRIBLE = "The prosecution's presentation is terrible.";
const string CONST_THE_JURY_IS_A_BIT_CONSERVATIVE = "The jury is a bit Conservative.";
const string CONST_THE_JURY_IS_QUITE_MODERATE = "The jury is quite moderate.";
const string CONST_THE_JURY_IS_FAIRLY_LIBERAL = "The jury is fairly Liberal.";
const string CONST_S_BEST_FRIEND_FROM_CHILDHOOD_IS_A_JUROR = "'s best friend from childhood is a juror.";
const string CONST_S_CONSERVATIVE_ARCH_NEMESIS_WILL_REPRESENT_THE_PROSECUTION = "'s CONSERVATIVE ARCH-NEMESIS will represent the prosecution!!!";
const string CONST_S_FAVOR = "'s favor!";
const string CONST_ENSURES_THE_JURY_IS_STACKED_IN = " ensures the jury is stacked in ";
const string CONST_THE_TRIAL_PROCEEDS_JURY_SELECTION_IS_FIRST = "The trial proceeds.  Jury selection is first.";
const string CONST_IS_STANDING_TRIAL = " is standing trial.";
const string CONST_INTELLIGENCE = "Intelligence: ";
const string CONST_X_LAW_COLON = "Law: ";
const string CONST_CHARISMA = "Charisma: ";
const string CONST_X_PERSUASION_COLON = "Persuasion: ";
const string HEART_COLON = "Heart: ";
const string CONST_S_OFFER_TO_ASSIST_PRO_BONO = "'s offer to assist pro bono.";
const string CONST_E_ACCEPT_SLEEPER = "E - Accept sleeper ";
const string CONST_D_PAY_5000_TO_HIRE_ACE_LIBERAL_ATTORNEY = "D - Pay $5000 to hire ace Liberal attorney ";
const string CONST_C_PLEAD_GUILTY = "C - Plead guilty.";
const string CONST_B_DEFEND_SELF = "B - Defend self!";
const string CONST_A_USE_A_COURT_APPOINTED_ATTORNEY = "A - Use a court-appointed attorney.";
const string CONST_HOW_WILL_YOU_CONDUCT_THE_DEFENSE = "How will you conduct the defense?";
const string CONST_A_FORMER_LCS_MEMBER_WILL_TESTIFY_AGAINST = "A former LCS member will testify against ";
const string CONST_FORMER_LCS_MEMBERS_WILL_TESTIFY_AGAINST = " former LCS members will testify against ";
const string CONST_X_LOITERING = "loitering";
const string CONST_INDECENT_EXPOSURE = "indecent exposure";
const string CONST_X_DISTURBING_THE_PEACE = "disturbing the peace";
const string CONST_X_RESISTING_ARREST = "resisting arrest";
const string CONST_X_VANDALISM = "vandalism";
const string CONST_X_BREAKING_AND_ENTERING = "breaking and entering";
const string CONST_X_UNLAWFUL_BURIAL = "unlawful burial";
const string CONST_UNLAWFUL_ACCESS_OF_AN_INFORMATION_SYSTEM = "unlawful access of an information system";
const string CONST_INTERFERENCE_WITH_INTERSTATE_COMMERCE = "interference with interstate commerce";
const string CONST_POSSESSION_OF_AN_ILLEGAL_WEAPON = "possession of an illegal weapon";
const string CONST_FIRING_AN_ILLEGAL_WEAPON = "firing an illegal weapon";
const string CONST_HIRING_AN_ILLEGAL_ALIEN = "hiring an illegal alien";
const string CONST_X_HIRING_ILLEGAL_ALIENS = "hiring illegal aliens";
const string CONST_X_PROSTITUTION = "prostitution";
const string CONST_PETTY_LARCENY = "petty larceny";
const string CONST_X_CREDIT_CARD_FRAUD_LOWERCASE = "credit card fraud";
const string CONST_X_GRAND_THEFT_AUTO = "grand theft auto";
const string CONST_MISDEMEANOR_ASSAULT = "misdemeanor assault";
const string CONST_FELONY_ASSAULT = "felony assault";
const string CONST_X_EXTORTION = "extortion";
const string CONST_X_RACKETEERING = "racketeering";
const string CONST_X_JURY_TAMPERING = "jury tampering";
const string CONST_AIDING_A_PRISON_ESCAPE = "aiding a prison escape";
const string CONST_X_ESCAPING_PRISON = "escaping prison";
const string CONST_X_DRUG_DEALING = "drug dealing";
const string CONST_SEDITION = "sedition";
const string CONST_X_FLAG_BURNING_LOWERCASE = "flag burning";
const string CONST_FELONY_FLAG_BURNING = "felony flag burning";
const string CONST_X_FLAG_MURDER = "Flag Murder";
const string CONST_X_ARSON = "arson";
const string CONST_X_BANK_ROBBERY = "bank robbery";
const string CONST_X_KIDNAPPING = "kidnapping";
const string CONST_X_MURDER = "murder";
const string CONST_X_TERRORISM = "terrorism";
const string CONST_X_TREASON = "treason";
const string CONST_IS_CHARGED_WITH = ", is charged with ";
const string CONST_THE_DEFENDANT = "The defendant, ";
const string CONST_THE_JUDGE_READS_THE_CHARGES = "The judge reads the charges:";
const string CONST_READS_THE_CHARGES_TRYING_TO_HIDE_A_SMILE = " reads the charges, trying to hide a smile:";
const string CONST_TO_BE_SERVED_CONSECUTIVELY = "to be served consecutively";
const string CONST_TO_BE_SERVED_CONCURRENTLY = "to be served concurrently";
const string CONST_X_COMMA = ",";
const string CONST_IN_PRISON = " in prison";
const string CONST_LETTER_S = "s";
const string CONST_MONTH = " month";
const string CONST_YEARS_IN_PRISON = " years in prison";
const string CONST_LIFE_IN_PRISON = "life in prison";
const string CONST_HAVE_A_NICE_DAY = "Have a nice day, ";
const string CONST_CONSECUTIVE_LIFE_TERMS_IN_PRISON = " consecutive life terms in prison";
const string CONST_YOU_ARE_SENTENCED_TO = ", you are sentenced to ";
const string CONST_CONSIDER_THIS_A_WARNING_YOU_ARE_FREE_TO_GO = ", consider this a warning.  You are free to go.";
const string CONST_YOU_WILL_BE_RETURNED_TO_PRISON_TO_RESUME_IT = "You will be returned to prison to resume it";
const string CONST_THE_COURT_SEES_NO_NEED_TO_ADD_TO_YOUR_EXISTING_SENTENCE = ", the court sees no need to add to your existing sentence.";
const string CONST_YOU_ARE_SENTENCED_TO_DEATH = ", you are sentenced to DEATH!";
const string CONST_YOU_WILL_BE_RETURNED_TO_PRISON_TO_CARRY_OUT_YOUR_DEATH_SENTENCE = ", you will be returned to prison to carry out your death sentence.";
const string CONST_DURING_SENTENCING_THE_JUDGE_GRANTS_SOME_LENIENCY = "During sentencing, the judge grants some leniency.";
const string CONST_GUILTY = "GUILTY!";
const string CONST_GENERAL_EXPERIENCES_TXT = "general_experiences.txt";
const string CONST_BAD_EXPERIENCES_TXT = "bad_experiences.txt";
const string CONST_GOOD_EXPERIENCES_TXT = "good_experiences.txt";
const string CONST_LABOR_CAMP_EXPERIENCES_TXT = "labor_camp_experiences.txt";
const string CONST_REEDUCATION_EXPERIENCES_TXT = "reeducation_experiences.txt";
const string CONST_SUPPOSEDLY_PAINLESS_EXECUTION_METHOD_TXT = "supposedly_painless_execution_method.txt";
const string CONST_STANDARD_EXECUTION_METHODS_TXT = "standard_execution_methods.txt";
const string CONST_CRUEL_AND_UNUSUAL_EXECUTION_METHODS_TXT = "cruel_and_unusual_execution_methods.txt";
const string CONST_CONSERVATIVE_JURY_TXT = "conservative_jury.txt";
const string CONST_LIBERAL_JURY_TXT = "liberal_jury.txt";

const string tag_ARMOR = "ARMOR";
const string tag_ARMOR_CLOTHES = "ARMOR_CLOTHES";
const string tag_ARMOR_WORKCLOTHES = "ARMOR_WORKCLOTHES";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";

const string SINGLE_DOT = ".";
const string CONST_X_COMMA_SPACE = ", ";
const string CONST_SPACE_AND_SPACE = " and ";
const string LETTER_S = "s";

#include "../creature/creature.h"
#include "../locations/locations.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../log/log.h"
//#include "../common/commonactions.h"
int scare_factor(int lawflag, int crimenumber);
#include "../common/commonactionsCreature.h"
// for  bool iscriminal(Creature &)
#include "../common/translateid.h"
// for  int getarmortype
#include "../politics/politics.h"
//for publicmood
#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include "../common/creaturePoolCreature.h"
vector<string> liberal_jury;
vector<string> conservative_jury;
vector<string> cruel_and_unusual_execution_methods;
vector<string> standard_execution_methods;
vector<string> supposedly_painless_execution_method;
vector<string> reeducation_experiences;
vector<string> labor_camp_experiences;
vector<string> good_experiences;
vector<string> bad_experiences;
vector<string> general_experiences;
#include "../customMaps.h"
vector<file_and_text_collection> justice_text_file_collection = {
	/*justice.cpp*/
	customText(&liberal_jury, justice + CONST_LIBERAL_JURY_TXT),
	customText(&conservative_jury, justice + CONST_CONSERVATIVE_JURY_TXT),
	customText(&cruel_and_unusual_execution_methods, justice + CONST_CRUEL_AND_UNUSUAL_EXECUTION_METHODS_TXT),
	customText(&standard_execution_methods, justice + CONST_STANDARD_EXECUTION_METHODS_TXT),
	customText(&supposedly_painless_execution_method, justice + CONST_SUPPOSEDLY_PAINLESS_EXECUTION_METHOD_TXT),
	customText(&reeducation_experiences, justice + CONST_REEDUCATION_EXPERIENCES_TXT),
	customText(&labor_camp_experiences, justice + CONST_LABOR_CAMP_EXPERIENCES_TXT),
	customText(&good_experiences, justice + CONST_GOOD_EXPERIENCES_TXT),
	customText(&bad_experiences, justice + CONST_BAD_EXPERIENCES_TXT),
	customText(&general_experiences, justice + CONST_GENERAL_EXPERIENCES_TXT),
};
#include "../common/musicClass.h"

extern bool SHOWMECHANICS;
extern MusicClass music;
extern class Ledger ledger;
extern unsigned long attorneyseed[RNG_SIZE];
extern unsigned long seed[RNG_SIZE];
extern Log gamelog;
extern int stat_dead;
extern short lawList[LAWNUM];
extern vector<DeprecatedCreature *> pool;

#include "../common/creaturePool.h"
#include "../locations/locationsPool.h"
//void printSingleCrime(const CreatureJustice g, const Lawflags law_flag, const int typenum, const string crime_string, const bool mention_multiple_counts = false);
map<Lawflags, string> crimeBlockOne = {
	map<Lawflags, string>::value_type(LAWFLAG_TREASON, CONST_X_TREASON),
	map<Lawflags, string>::value_type(LAWFLAG_TERRORISM, CONST_X_TERRORISM),
	map<Lawflags, string>::value_type(LAWFLAG_MURDER, CONST_X_MURDER),
	map<Lawflags, string>::value_type(LAWFLAG_KIDNAPPING, CONST_X_KIDNAPPING),
	map<Lawflags, string>::value_type(LAWFLAG_BANKROBBERY, CONST_X_BANK_ROBBERY),
	map<Lawflags, string>::value_type(LAWFLAG_ARSON, CONST_X_ARSON),
};
map<Lawflags, string> crimeBlockTwo = {
	map<Lawflags, string>::value_type(LAWFLAG_SPEECH, CONST_SEDITION),
	map<Lawflags, string>::value_type(LAWFLAG_BROWNIES, CONST_X_DRUG_DEALING),
	map<Lawflags, string>::value_type(LAWFLAG_ESCAPED, CONST_X_ESCAPING_PRISON),
	map<Lawflags, string>::value_type(LAWFLAG_HELPESCAPE, CONST_AIDING_A_PRISON_ESCAPE),
	map<Lawflags, string>::value_type(LAWFLAG_JURY, CONST_X_JURY_TAMPERING),
	map<Lawflags, string>::value_type(LAWFLAG_RACKETEERING, CONST_X_RACKETEERING),
	map<Lawflags, string>::value_type(LAWFLAG_EXTORTION, CONST_X_EXTORTION),
	map<Lawflags, string>::value_type(LAWFLAG_ARMEDASSAULT, CONST_FELONY_ASSAULT),
	map<Lawflags, string>::value_type(LAWFLAG_ASSAULT, CONST_MISDEMEANOR_ASSAULT),
	map<Lawflags, string>::value_type(LAWFLAG_CARTHEFT, CONST_X_GRAND_THEFT_AUTO),
	map<Lawflags, string>::value_type(LAWFLAG_CCFRAUD, CONST_X_CREDIT_CARD_FRAUD_LOWERCASE),
	map<Lawflags, string>::value_type(LAWFLAG_THEFT, CONST_PETTY_LARCENY),
	map<Lawflags, string>::value_type(LAWFLAG_PROSTITUTION, CONST_X_PROSTITUTION),
};
map<Lawflags, string> crimeBlockThree = {
	map<Lawflags, string>::value_type(LAWFLAG_COMMERCE, CONST_INTERFERENCE_WITH_INTERSTATE_COMMERCE),
	map<Lawflags, string>::value_type(LAWFLAG_INFORMATION, CONST_UNLAWFUL_ACCESS_OF_AN_INFORMATION_SYSTEM),
	map<Lawflags, string>::value_type(LAWFLAG_BURIAL, CONST_X_UNLAWFUL_BURIAL),
	map<Lawflags, string>::value_type(LAWFLAG_BREAKING, CONST_X_BREAKING_AND_ENTERING),
	map<Lawflags, string>::value_type(LAWFLAG_VANDALISM, CONST_X_VANDALISM),
	map<Lawflags, string>::value_type(LAWFLAG_RESIST, CONST_X_RESISTING_ARREST),
	map<Lawflags, string>::value_type(LAWFLAG_DISTURBANCE, CONST_X_DISTURBING_THE_PEACE),
	map<Lawflags, string>::value_type(LAWFLAG_PUBLICNUDITY, CONST_INDECENT_EXPOSURE),
	map<Lawflags, string>::value_type(LAWFLAG_LOITERING, CONST_X_LOITERING),
};
map<Lawflags, bool> crimeMultipleCounts = {
	map<Lawflags, bool>::value_type(LAWFLAG_TREASON,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_TERRORISM,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_MURDER,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_KIDNAPPING,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_BANKROBBERY,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_ARSON,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_SPEECH,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_BROWNIES,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_ESCAPED,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_HELPESCAPE,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_JURY,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_RACKETEERING, false),
	map<Lawflags, bool>::value_type(LAWFLAG_EXTORTION,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_ARMEDASSAULT,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_ASSAULT,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_CARTHEFT,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_CCFRAUD,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_THEFT,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_PROSTITUTION,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_COMMERCE,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_INFORMATION,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_BURIAL,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_BREAKING,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_VANDALISM,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_RESIST, false),
	map<Lawflags, bool>::value_type(LAWFLAG_DISTURBANCE,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_PUBLICNUDITY,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_LOITERING, false),
};
enum LegalDefense {
	UNDECIDED = -1,
	COURT_ATTORNEY = 0,
	SELF_REPRESENT = 1,
	PLEAD_GUILTY = 2,
	ACE_ATTORNEY = 3,
	SLEEPER_ATTORNEY = 4
};

#endif	//JUSTICE_CPP
#endif // INCLUDES_H_INCLUDED
