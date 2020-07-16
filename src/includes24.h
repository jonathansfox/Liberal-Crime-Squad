




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
#ifdef	LOCATIONSPOOL_CPP
// locationsPool.cpp

#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../items/armortype.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../common/commondisplay.h"
// for void printfunds(int,int,char*)
#include "../common/stringconversion.h"
//for string attribute_enum_to_string(int)
#include "../common/getnames.h"
// for cityname
#include "../common/translateid.h"
// for  getarmortype
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../set_color_support.h"
#include "locationsPool.h"
#include "../common/creaturePoolCreature.h"
#include "../items/money.h"
#include "../recruits.h"
/* creates your founder */
struct newGameArguments {
	const char recruits;
	const char base;
	const bool makelawyer;
	const bool gaylawyer;
	const bool sports_car;
	newGameArguments(char _recruits, char _base, bool _makelawyer, bool _gaylawyer, bool _sports_car) : recruits(_recruits), base(_base), makelawyer(_makelawyer), gaylawyer(_gaylawyer), sports_car(_sports_car) {}
};
Vehicle* newSportsCar();
void newVehicle(Vehicle *startcar);
#include "../common/equipment.h"
#include "../common/creaturePool.h"
void initlocation(Location &loc);
//#include "sitemode/sitemode.h"
void initsite(Location &loc);
#include "../common/commonactionsCreature.h"

#include "../items/lootTypePoolItem.h"
map<short, string> getActivityString;

vector<SiteTypes> classicDowntown = {
	SITE_RESIDENTIAL_APARTMENT_UPSCALE,
	SITE_GOVERNMENT_POLICESTATION,
	SITE_GOVERNMENT_COURTHOUSE,
	SITE_BUSINESS_BANK,
	SITE_GOVERNMENT_FIRESTATION,
	SITE_MEDIA_AMRADIO,
	SITE_MEDIA_CABLENEWS,
	SITE_BUSINESS_CIGARBAR,
	SITE_BUSINESS_LATTESTAND,
};
vector<SiteTypes> classicCommercial = {

	SITE_BUSINESS_DEPTSTORE,
	SITE_BUSINESS_PAWNSHOP,
	SITE_BUSINESS_HALLOWEEN,
	SITE_BUSINESS_CARDEALERSHIP,
};
vector<SiteTypes> classicUptown = {

	SITE_RESIDENTIAL_APARTMENT,
	SITE_HOSPITAL_UNIVERSITY,
	SITE_HOSPITAL_CLINIC,
	SITE_LABORATORY_GENETIC,
	SITE_LABORATORY_COSMETICS,
	SITE_BUSINESS_VEGANCOOP,
	SITE_BUSINESS_JUICEBAR,
	SITE_BUSINESS_INTERNETCAFE,
	SITE_OUTDOOR_PUBLICPARK,
};
vector<SiteTypes> classicOutOfTown = {

	SITE_GOVERNMENT_PRISON,
	SITE_GOVERNMENT_INTELLIGENCEHQ,
	SITE_INDUSTRY_NUCLEAR,
	SITE_CORPORATE_HEADQUARTERS,
	SITE_CORPORATE_HOUSE,
	SITE_GOVERNMENT_ARMYBASE,
};



vector<SiteTypes> seattleDowntown = {

	SITE_RESIDENTIAL_APARTMENT_UPSCALE,
	SITE_GOVERNMENT_POLICESTATION,
	SITE_GOVERNMENT_COURTHOUSE,
	SITE_BUSINESS_BANK,
	SITE_GOVERNMENT_FIRESTATION,
	SITE_MEDIA_AMRADIO,
	SITE_BUSINESS_CIGARBAR,
	SITE_BUSINESS_LATTESTAND,
	SITE_BUSINESS_DEPTSTORE,
};

vector<SiteTypes> seattleUptown = {

	SITE_RESIDENTIAL_APARTMENT,
	SITE_HOSPITAL_UNIVERSITY,
	SITE_HOSPITAL_CLINIC,
	SITE_LABORATORY_GENETIC,
	SITE_LABORATORY_COSMETICS,
	SITE_BUSINESS_VEGANCOOP,
	SITE_BUSINESS_JUICEBAR,
	SITE_BUSINESS_INTERNETCAFE,
	SITE_OUTDOOR_PUBLICPARK,
	SITE_BUSINESS_HALLOWEEN,
};
vector<SiteTypes> seattleOutOfTown = {

	SITE_GOVERNMENT_PRISON,
	SITE_GOVERNMENT_INTELLIGENCEHQ,
	SITE_CORPORATE_HEADQUARTERS,
	SITE_GOVERNMENT_ARMYBASE,
};

vector<SiteTypes> newYorkManhattan = {

	SITE_RESIDENTIAL_APARTMENT_UPSCALE,
	SITE_GOVERNMENT_POLICESTATION,
	SITE_GOVERNMENT_COURTHOUSE,
	SITE_BUSINESS_BANK,
	SITE_CORPORATE_HEADQUARTERS,
	SITE_MEDIA_AMRADIO,
	SITE_MEDIA_CABLENEWS,
	SITE_BUSINESS_CIGARBAR,
	SITE_OUTDOOR_PUBLICPARK,
	SITE_BUSINESS_DEPTSTORE,
	SITE_GOVERNMENT_PRISON,
};

vector<SiteTypes> newYorkLongIsland = {
	SITE_RESIDENTIAL_APARTMENT,
	SITE_GOVERNMENT_FIRESTATION,
	SITE_HOSPITAL_UNIVERSITY,
	SITE_HOSPITAL_CLINIC,
	SITE_BUSINESS_JUICEBAR,
	SITE_BUSINESS_INTERNETCAFE,
	SITE_INDUSTRY_POLLUTER,
	SITE_LABORATORY_GENETIC,
	SITE_GOVERNMENT_ARMYBASE,
};


vector<SiteTypes> losAngelesDowntown = {



	SITE_RESIDENTIAL_APARTMENT,
	SITE_GOVERNMENT_POLICESTATION,
	SITE_GOVERNMENT_COURTHOUSE,
	SITE_BUSINESS_BANK,
	SITE_GOVERNMENT_FIRESTATION,
	SITE_CORPORATE_HEADQUARTERS,
	SITE_HOSPITAL_UNIVERSITY,
	SITE_BUSINESS_DEPTSTORE,

};


vector<SiteTypes> hollyWoodUptown = {


	SITE_RESIDENTIAL_APARTMENT_UPSCALE,
	SITE_BUSINESS_VEGANCOOP,
	SITE_BUSINESS_HALLOWEEN,
	SITE_BUSINESS_CIGARBAR,
	SITE_MEDIA_AMRADIO,
	SITE_OUTDOOR_PUBLICPARK,
	SITE_CORPORATE_HOUSE,


};


vector<SiteTypes> seaportArea = {


	SITE_RESIDENTIAL_TENEMENT,
	SITE_HOSPITAL_CLINIC,
	SITE_LABORATORY_GENETIC,
	SITE_LABORATORY_COSMETICS,
	SITE_INDUSTRY_POLLUTER,
	SITE_BUSINESS_PAWNSHOP,
	SITE_INDUSTRY_SWEATSHOP,
	SITE_BUSINESS_CARDEALERSHIP,


};

vector<SiteTypes> washingtonDCDowntown = {

	SITE_GOVERNMENT_POLICESTATION,
	SITE_GOVERNMENT_FIRESTATION,
	SITE_GOVERNMENT_COURTHOUSE,
	SITE_BUSINESS_BANK,
	SITE_BUSINESS_CARDEALERSHIP,
	SITE_HOSPITAL_CLINIC,
	SITE_HOSPITAL_UNIVERSITY,
	SITE_BUSINESS_DEPTSTORE,

};
#include "../daily/daily.h"
enum cityLocationTagEnums {
	ENUM_tag_Downtown,
	ENUM_tag_University_District,
	ENUM_tag_u_District,
	ENUM_tag_Industrial_District,
	ENUM_tag_i_District,
	ENUM_tag_Shopping,
	ENUM_tag_Outskirts,
	ENUM_tag_Seaport_Area,
	ENUM_tag_Seaport,
	ENUM_tag_Outskirts_amp_Orange_County,
	ENUM_tag_City_Outskirts,
	ENUM_tag_Arlington,
	ENUM_tag_Hollywood,
	ENUM_tag_Greater_Hollywood,
	ENUM_tag_Manhattan,
	ENUM_tag_Manhattan_Island,
	ENUM_tag_Brooklyn_ampersand_Queens,
	ENUM_tag_Long_Island,
	ENUM_tag_The_Bronx
};

// Check if the player wants to move all items to a new location,
// using Shift + a number key.
const char upnums[] = "!@#$%^&*(";
#include "../daily/siege.h"
void addStringYear();
#include "../common/commonactions.h"
#include "../common/musicClass.h"
#include "../customMaps.h"
enum BusinessFronts
{
	BUSINESSFRONT_INSURANCE,
	BUSINESSFRONT_TEMPAGENCY,
	BUSINESSFRONT_RESTAURANT,
	BUSINESSFRONT_MISCELLANEOUS,
	BUSINESSFRONTNUM
};
// Gives you bloody armor
extern bool GIVEBLOODYARMOR;
// Start with lots of money
extern bool HIGHFUNDS;

extern long cursquadid;
extern vector<ClipType *> cliptype;
extern vector<ArmorType *> armortype;

extern bool multipleCityMode;
extern char endgamestate;
extern class Ledger ledger;
extern Deprecatedsquadst *activesquad;
extern int day;
extern int month;
extern int selectedsiege;
extern int stat_kidnappings;
extern int year;
extern MusicClass music;
extern short background_liberal_influence[VIEWNUM];
extern short lawList[LAWNUM];
extern vector<Deprecatedsquadst *> squad;
extern vector<WeaponType *> weapontype;

/* monthly - lets the player choose a special edition for the guardian */
int choosespecialedition(char &clearformess);
/* monthly - guardian - prints liberal guardian special editions */
void printnews(short l, short newspaper);
#include "../items/itemPool.h"
#include "../items/lootTypePool.h"
void giveActiveSquadThisLoot(Item* de);
const string needCar = " (Need Car)";
const string underSiege = " (Under Siege)";
const string secrecyLevel = "Secrecy: ";
const string heatLevel = "Heat: ";
const string travelDifCity = " - Travel to a Different City";
const string currentLocation = " (Current Location)";
const string safeHouse = " (Safe House)";
const string enemySafeHouse = " (Enemy Safe House)";
const string PARENTHESIS_CLOSED_DOWN = " (Closed Down)";
const string highSecurity = " (High Security)";
const string theLCS = "The Liberal Crime Squad";
const string CONST_POSSESSIONS_GO_TO_THE_SHELTER = ".  Possessions go to the shelter.";
const string CONST_EVICTION_NOTICE = "EVICTION NOTICE: ";
const string CONST_SLEEPER_AGENT = "sleeper agent";
const string CONST_AS_A = " as a ";
const string CONST_STAY_AT = "Stay at ";
const string ARROW_RIGHT = "-> ";
const string CONST_REGULAR_MEMBER = "regular member";
const string CONST_COME_TO = "Come to ";
const string TWO_SPACES = "   ";
const string CONST_BEST_SERVE_THE_LIBERAL_CAUSE = " best serve the Liberal cause?";
const string CONST_IN_WHAT_CAPACITY_WILL = "In what capacity will ";
const string CONST_MALL = "Mall";
const string CONST_X_NEW_YORK = ", New York";
const string CONST_CALIFORNIA = ", California";
const string CONST_VIRGINIA = ", Virginia";
const string CONST_OUTSKIRTS = " Outskirts";

const string CONST_NY = ", NY";
const string CONST_CA = ", CA";
const string CONST_VA = ", VA";
const string CONST_REPORTING_BUGS_TO_THE_DEV_TEAM = "Reporting Bugs to the Dev Team";
const string CONST_GOING_TO = "Going to ";
const string CONST_MAKING = "Making ";
const string CONST_A_BUG = "a bug";
const string CONST_TENDING_TO = "Tending to ";
const string CONST_HOW_MANY = "     How many?          ";
const string CONST_Z_STASH_THINGS_AT = "Z - Stash things at ";
const string CONST_Y_GET_THINGS_FROM = "Y - Get things from ";
const string CONST_CURSORS_INCREASE_OR_DECREASE_AMMO_ALLOCATION = "Cursors - Increase or decrease ammo allocation";
const string CONST_S_LIBERALLY_STRIP_A_SQUAD_MEMBER = "S - Liberally Strip a Squad member";
const string CONST_PRESS_A_NUMBER_TO_DROP_THAT_SQUAD_MEMBER_S_CONSERVATIVE_WEAPON = "Press a number to drop that Squad member's Conservative weapon";
const string CONST_PRESS_A_LETTER_TO_EQUIP_A_LIBERAL_ITEM = "Press a letter to equip a Liberal item";
const string CONST_X = " x";
const string CONST_EQUIP_THE_SQUAD = "Equip the Squad";

const string CONST_RECEIVE_IT = "receive it.";
const string CONST_DROP_A_CLIP = "drop a clip.";
const string CONST_RECEIVE_A_CLIP = "receive a clip.";
const string NOT_ERROR_BUT_CONTINUE = "For simplicity this function returns an error message, prompting 'continue;', this is not an error, but it needs to use 'continue;' anyway";
const string CONST_CAN_T_CARRY_ANY_MORE_AMMO = "Can't carry any more ammo.";
const string CONST_THAT_AMMO_DOESN_T_FIT = "That ammo doesn't fit.";
const string CONST_CAN_T_CARRY_AMMO_WITHOUT_A_GUN = "Can't carry ammo without a gun.";
const string CONST_NO_AMMO_AVAILABLE = "No ammo available!";
const string CONST_NO_AMMO_REQUIRED = "No ammo required!";
const string CONST_NO_SPARE_CLIPS = "No spare clips!";
const string CONST_NO_AMMO_TO_DROP = "No ammo to drop!";

const string CONST_STRIP_DOWN = "strip down.";

const string CONST_YOU_CAN_T_EQUIP_THAT = "You can't equip that.";
const string CONST_PRESS_A_LETTER_TO_SELECT_AN_ITEM = "Press a letter to select an item.";
const string CONST_X_X = "x";
const string CONST_locationsPool079 = "/";
const string CONST_SELECT_OBJECTS = "Select Objects";
const string CONST_TO_VIEW_OTHER_BASE_PAGES = ",. to view other base pages.";
const string CONST_SHIFT_AND_A_NUMBER_WILL_MOVE_ALL_ITEMS = "  Shift and a Number will move ALL items!";
const string CONST_T_TO_SORT_BY_TYPE = "T to sort by type.";
const string CONST_T_TO_SORT_BY_LOCATION = "T to sort by location.";
const string CONST_PRESS_A_LETTER_TO_ASSIGN_A_BASE_PRESS_A_NUMBER_TO_SELECT_A_BASE = "Press a Letter to assign a base.  Press a Number to select a base.";
const string CONST_NEW_LOCATION = "NEW LOCATION";
const string CONST_ITEM_CURRENT_LOCATION = "컴컴ITEM컴컴컴컴컴컴컴컴CURRENT LOCATION컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�";
const string CONST_MOVING_EQUIPMENT = "Moving Equipment";
const string CONST_EATING = " Eating";
const string CONST_locationsPool115 = "s";
const string CONST_DAILY_RATION = " Daily Ration";
const string CONST_NOT_ENOUGH_FOOD = "Not Enough Food";
const string CONST_OF_FOOD_LEFT = " of Food Left";
const string CONST_X_SPACE_DAY = " Day";
const string CONST_GENERATOR = "GENERATOR";
const string CONST_LIGHTS_OUT = "LIGHTS OUT";
const string CONST_TANK_TRAPS = "TANK TRAPS";
const string CONST_AA_GUN = "AA GUN";
const string CONST_BOOBY_TRAPS = "BOOBY TRAPS";
const string CONST_CAMERAS_ON = "CAMERAS ON";
const string CONST_CAMERAS_OFF = "CAMERAS OFF";
const string CONST_BUSINESS_FRONT = "BUSINESS FRONT";
const string CONST_PRINTING_PRESS = "PRINTING PRESS";
const string CONST_FORTIFIED_COMPOUND = "FORTIFIED COMPOUND";
const string CONST_THIS_LOCATION_HAS_INSUFFICIENT_FOOD_STORES = "This location has insufficient food stores.";
const string CONST_THIS_LOCATION_HAS_FOOD_FOR_ONLY_A_FEW_DAYS = "This location has food for only a few days.";
const string CONST_YOU_ARE_NOT_UNDER_SIEGE_YET = "You are not under siege...  yet.";
const string CONST_FIREMEN_ARE_RAIDING_THIS_LOCATION = "Firemen are raiding this location!";
const string CONST_THE_CCS_IS_RAIDING_THIS_LOCATION = "The CCS is raiding this location!";
const string CONST_THE_CORPORATIONS_ARE_RAIDING_THIS_LOCATION = "The Corporations are raiding this location!";
const string CONST_THE_MASSES_ARE_STORMING_THIS_LOCATION = "The masses are storming this location!";
const string CONST_THE_CIA_IS_RAIDING_THIS_LOCATION = "The CIA is raiding this location!";
const string CONST_THE_POLICE_ARE_RAIDING_THIS_LOCATION = "The police are raiding this location!";
const string CONST_THE_POLICE_HAVE_SURROUNDED_THIS_LOCATION = "The police have surrounded this location.";
const string CONST_ACTING_INDIVIDUALLY = "Acting Individually";
const string CONST_2_PRESS_Z_TO_ASSEMBLE_A_NEW_SQUAD = "2) Press Z to Assemble a New Squad";
const string CONST_1_R_REVIEW_ASSETS_AND_FORM_SQUADS = "1) R - Review Assets and Form Squads";
const string CONST_TO_FORM_A_NEW_SQUAD = "To form a new squad:";
const string CONST_NO_SQUAD_SELECTED = "No Squad Selected";
const string CONST_ENTER_BACK_ONE_STEP = "Enter - Back one step.";
const string CONST_ENTER_THE_SQUAD_IS_NOT_YET_LIBERAL_ENOUGH = "Enter - The squad is not yet Liberal enough.";
const string CONST_WHERE_WILL_THE_SQUAD_GO = "Where will the Squad go?";
const string MOSTLY_ENDINGS_FOLDER = "mostlyendings\\";
const string CONST_CASEBUSINESSFRONT_MISCELLANEOUS_TXT = "caseBUSINESSFRONT_MISCELLANEOUS.txt";
const string CONST_CASEBUSINESSFRONT_RESTAURANT_TXT = "caseBUSINESSFRONT_RESTAURANT.txt";
const string CONST_CASEBUSINESSFRONT_TEMPAGENCY_TXT = "caseBUSINESSFRONT_TEMPAGENCY.txt";
const string CONST_CASEBUSINESSFRONT_INSURANCE_TXT = "caseBUSINESSFRONT_INSURANCE.txt";
const string CONST_R_STOCKPILE_20_DAILY_RATIONS_OF_FOOD_150 = "R - Stockpile 20 daily rations of food ($150)";
const string CONST_F_SETUP_A_BUSINESS_FRONT_TO_WARD_OFF_SUSPICION_3000 = "F - Setup a Business Front to ward off suspicion ($3000)";
const string CONST_P_BUY_A_PRINTING_PRESS_TO_START_YOUR_OWN_NEWSPAPER_3000 = "P - Buy a Printing Press to start your own newspaper ($3000)";
const string CONST_A_INSTALL_AND_CONCEAL_AN_ILLEGAL_ANTI_AIRCRAFT_GUN_ON_THE_ROOF_200_000 = "A - Install and conceal an illegal Anti-Aircraft gun on the roof ($200,000)";
const string CONST_A_INSTALL_A_PERFECTLY_LEGAL_ANTI_AIRCRAFT_GUN_ON_THE_ROOF_35_000 = "A - Install a perfectly legal Anti-Aircraft gun on the roof ($35,000)";
const string CONST_G_BUY_A_GENERATOR_FOR_EMERGENCY_ELECTRICITY_3000 = "G - Buy a Generator for emergency electricity ($3000)";
const string CONST_T_RING_THE_COMPOUND_WITH_TANK_TRAPS_3000 = "T - Ring the Compound with Tank Traps ($3000)";
const string CONST_B_PLACE_BOOBY_TRAPS_THROUGHOUT_THE_COMPOUND_3000 = "B - Place Booby Traps throughout the Compound ($3000)";
const string CONST_C_PLACE_SECURITY_CAMERAS_AROUND_THE_COMPOUND_2000 = "C - Place Security Cameras around the Compound ($2000)";
const string CONST_W_FORTIFY_THE_COMPOUND_FOR_A_SIEGE_2000 = "W - Fortify the Compound for a Siege ($2000)";
const string CONST_W_FORTIFY_THE_BOMB_SHELTER_ENTRANCES_2000 = "W - Fortify the Bomb Shelter Entrances ($2000)";
const string CONST_W_REPAIR_THE_BUNKER_FORTIFICATIONS_2000 = "W - Repair the Bunker Fortifications ($2000)";
const string CONST_X_IF_YOU_DO_NOT_ENTER_ANYTHING_THEIR_REAL_NAME_WILL_BE_USED = "If you do not enter anything, their real name will be used.";
const string CONST_X_IN_ITS_PRESENCE = " in its presence?";
const string CONST_X_WHAT_NAME_WILL_YOU_USE_FOR_THIS_ = "What name will you use for this ";
const string CONST_locationsPool141 = "The Education of ";
const string CONST_TEMPORARY_SQUAD = "Temporary Squad";
const string tag_WEAPON_SPRAYCAN = "WEAPON_SPRAYCAN";

const string tag_LOOT = "LOOT";
const string tag_LOOT_SECRETDOCUMENTS = "LOOT_SECRETDOCUMENTS";
const string tag_LOOT_INTHQDISK = "LOOT_INTHQDISK";
const string tag_The_Bronx = "The Bronx";
const string tag_Long_Island = "Long Island";
const string tag_Brooklyn_ampersand_Queens = "Brooklyn & Queens";
const string tag_B = "B";
const string tag_Manhattan = "Manhattan";
const string tag_The = "The ";
const string tag_Manhattan_Island = "Manhattan Island";
const string tag_Greater_Hollywood = "Greater Hollywood";
const string tag_Hollywood = "Hollywood";
const string tag_Arlington = "Arlington";
const string tag_City_Outskirts = "City Outskirts";
const string tag_Seaport_Area = "Seaport Area";
const string tag_Shopping = "Shopping";
const string tag_Seaport = "Seaport";
const string tag_Outskirts_amp_Orange_County = "Outskirts & Orange County";
const string tag_Outskirts = "Outskirts";
const string tag_University_District = "University District";
const string tag_i_District = "I-District";
const string tag_Industrial_District = "Industrial District";
const string tag_u_District = "U-District";
const string tag_D = "D";
const string tag_Downtown = "Downtown";
const string tag_National_Mall = "National Mall";
const string tag_ARMOR = "ARMOR";
const string tag_ARMOR_CLOTHES = "ARMOR_CLOTHES";
const string tag_CLIP = "CLIP";
const string tag_CLIP_9 = "CLIP_9";
const string tag_WEAPON = "WEAPON";
const string tag_WEAPON_SEMIPISTOL_9MM = "WEAPON_SEMIPISTOL_9MM";
const string tag_WEAPON_SMG_MP5 = "WEAPON_SMG_MP5";
const string tag_WEAPON_AUTORIFLE_AK47 = "WEAPON_AUTORIFLE_AK47";
map <string, int> cityLocationTags = {
map<string, int>::value_type(tag_Downtown, ENUM_tag_Downtown),
map<string, int>::value_type(tag_University_District, ENUM_tag_University_District),
map<string, int>::value_type(tag_u_District, ENUM_tag_u_District),
map<string, int>::value_type(tag_Industrial_District, ENUM_tag_Industrial_District),
map<string, int>::value_type(tag_i_District, ENUM_tag_i_District),
map<string, int>::value_type(tag_Shopping, ENUM_tag_Shopping),
map<string, int>::value_type(tag_Outskirts, ENUM_tag_Outskirts),
map<string, int>::value_type(tag_Seaport_Area, ENUM_tag_Seaport_Area),
map<string, int>::value_type(tag_Seaport, ENUM_tag_Seaport),
map<string, int>::value_type(tag_Outskirts_amp_Orange_County, ENUM_tag_Outskirts_amp_Orange_County),
map<string, int>::value_type(tag_City_Outskirts, ENUM_tag_City_Outskirts),
map<string, int>::value_type(tag_Arlington, ENUM_tag_Arlington),
map<string, int>::value_type(tag_Hollywood, ENUM_tag_Hollywood),
map<string, int>::value_type(tag_Greater_Hollywood, ENUM_tag_Greater_Hollywood),
map<string, int>::value_type(tag_Manhattan, ENUM_tag_Manhattan),
map<string, int>::value_type(tag_Manhattan_Island, ENUM_tag_Manhattan_Island),
map<string, int>::value_type(tag_Brooklyn_ampersand_Queens, ENUM_tag_Brooklyn_ampersand_Queens),
map<string, int>::value_type(tag_Long_Island, ENUM_tag_Long_Island),
map<string, int>::value_type(tag_The_Bronx, ENUM_tag_The_Bronx)
};
#endif	//LOCATIONSPOOL_CPP
#endif // INCLUDES_H_INCLUDED
