




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
#ifdef	ACTIVITIES_CPP
// activities.cpp

#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../items/armortype.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../basemode/activate.h"
// for armor_makedifficulty
#include "../items/loottype.h"
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
#include "../common/commondisplayCreature.h"
// for addstr
#include "../common/translateid.h"
// for  int getsquad(int)
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
// for void criminalize(Creature &,short);
#include "../common/getnames.h"
// for std::string getview(short, bool)
#include "../politics/politics.h"
//for int publicmood(int l);
#include "../combat/chase.h"
#include "../combat/chaseCreature.h"
//for void makechasers(long sitetype,long sitecrime);
#include "../combat/fightCreature.h"  

#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
#include "../items/lootTypePoolItem.h"
#include "../common/creaturePool.h"


void doActivitySolicitDonations(vector<DeprecatedCreature *> &solicit, char &clearformess);
void doActivitySellTshirts(vector<DeprecatedCreature *> &tshirts, char &clearformess);
void doActivitySellArt(vector<DeprecatedCreature *> &art, char &clearformess);
void doActivitySellMusic(vector<DeprecatedCreature *> &music, char &clearformess);
void doActivitySellBrownies(vector<DeprecatedCreature *> &brownies, char &clearformess);
void doActivityHacking(vector<DeprecatedCreature *> &hack, char &clearformess);
void doActivityGraffiti(vector<DeprecatedCreature *> &graffiti, char &clearformess);
void doActivityProstitution(vector<DeprecatedCreature *> &prostitutes, char &clearformess);
void doActivityLearn(vector<DeprecatedCreature *> &students, char &clearformess);
void doActivityTrouble(vector<DeprecatedCreature *> &trouble, char &clearformess);
void doActivityTeach(vector<DeprecatedCreature *> &teachers, char &clearformess);
void doActivityBury(vector<DeprecatedCreature *> &bury, char &clearformess);

void addLootToLoc(int loc, Item* it);
char tryFindCloth(int cursite);
string wasUnableToFind(const string old);
string considerLeaving(const bool sensealarm, const bool alarmon, const string name);
extern bool SHOWMECHANICS;
extern char endgamestate;
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern char newscherrybusted;
extern chaseseqst chaseseq;
extern class Ledger ledger;
extern Deprecatednewsstoryst *sitestory;
extern Log gamelog;
extern MusicClass music;
extern short attitude[VIEWNUM];
extern short background_liberal_influence[VIEWNUM];
extern short exec[EXECNUM];
extern short fieldskillrate;
extern short interface_pgdn;
extern short interface_pgup;
extern short lawList[LAWNUM];
extern short mode;
extern short public_interest[VIEWNUM];
extern vector<ArmorType *> armortype;
extern vector<DeprecatedCreature *> pool;
extern vector<Deprecatednewsstoryst *> newsstory;
extern vector<Deprecatedsquadst *> squad;
static const char SURVEY_PAGE_SIZE = 14;
string gimmeASprayCan(DeprecatedCreature* graffiti);
Vehicle* getVehicleOfThisType(int cartype);
void buyMeASprayCan(DeprecatedCreature* graffiti);
void newVehicle(Vehicle *startcar);

enum CarHotwireMethod {
	UNDETERMINED,
	ATTEMPT_HOTWIRE,
	USE_KEYS
};


const string CONST_X_CAN = " can.";
const string CONST_X_HAS_LEARNED_AS_MUCH_AS_ = " has learned as much as ";

const string tag_POLICECAR = "POLICECAR";
const string tag_WEAPON_SPRAYCAN = "WEAPON_SPRAYCAN";
const string tag_WEAPON = "WEAPON";
const string CONST_X_HAS_ = " has ";
const string CONST_X_EXCLAMATION_POINT = "!";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
const string CONST_X_PERUSES_MAGAZINES = " peruses some sewing magazines.";
const string CONST_X_CLEANS_KITCHEN = " cleans the kitchen.";
const string CONST_X_REORGANIZES_CLOSET = " reorganizes the armor closet.";
const string CONST_X_TIDIES_SAFEHOUSE = " tidies up the safehouse.";
const string CONST_X_RUINED = " ruined";
const string CONST_X_REPAIRS_SOMEWHAT = " repairs what little can be fixed of ";
const string CONST_X_NO_HOPE_TO_REPAIR = " finds there is no hope of repairing ";
const string CONST_X_REPAIRS = " repairs ";
const string CONST_X_IS_WORKING_TO_REPAIR = " is working to repair ";
const string CONST_X_CLEANS = " cleans ";
const string CONST_X_DISPOSES_OF = " disposes of ";
const string CONST_X_WASTED_MATERIALS = " wasted the materials for a";
const string CONST_X_TH_RATE = "th-rate";
const string CONST_X_FOURTH_RATE = "fourth-rate";
const string CONST_X_THIRD_RATE = "third-rate";
const string CONST_X_SECOND_RATE = "second-rate";
const string CONST_X_FIRST_RATE = "first-rate";
const string CONST_X_HAS_MADE_A = " has made a ";
const string CONST_X_CANNOT_FIND_CLOTH = " cannot find enough cloth to reduce clothing costs.";
const string CONST_X_CANNOT_AFFORD_MATERIAL = " cannot afford material for clothing.";
const string CONST_X_LITTLE_WHITESPACE = "    ";
const string CONST_X_ENTER_DONE = "Enter - Done";
const string CONST_X_LIBERAL_PERCENTAGE_POINTS = " Liberal percentage points.";
const string CONST_X_RESULTS_ARE_PLUS_MINUS = "Results are +/- ";
const string CONST_X_ISSUE_PUBLIC_INTEREST_HEADER = "XX% Issue 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴횾ublic Interest";
const string CONST_X_ADDITIONAL_FINDINGS = "Additional notable findings:";
const string CONST_X_AMNESTY_FOR_IMMIGRANTS = "wanted amnesty for illegal immigrants";
const string CONST_X_CONDEMN_IMMIGRATION_REGULATIONS = "condemned unnecessary immigration regulations";
const string CONST_X_BELIEVE_IN_LEGAL_MARIJUANA = "believed in legalizing marijuana";
const string CONST_X_SUPPORTED_MARIJUANA_LEGAL = "supported keeping marijuana legal";
const string CONST_X_PERCENT_SIGN = "% ";
const string CONST_X_TWO_QUESTION_MARKS = "??";
const string CONST_X_NONE_SPACE = "None     ";
const string CONST_X_LOW = "Low      ";
const string CONST_X_MODERATE = "Moderate ";
const string CONST_X_HIGH = "High     ";
const string CONST_X_VERY_HIGH = "Very High";
const string CONST_X_UNKNOWN = "Unknown  ";
const string CONST_X_MANY_DOTS = "........................................................";
const string CONST_X_LOTS_OF_WHITESPACE = "                                                                                ";
const string CONST_X_LIBERAL_MEDIA_BIAS = "Liberal Media Bias.";
const string CONST_X_CONSERVATIVE_MEDIA_BIAS = "Conservative Media Bias.";
const string CONST_X_THE_LCS_TERRORISTS = "the LCS terrorists.";
const string CONST_X_THE_LIBERAL_CRIME_SQUAD = "the Liberal Crime Squad.";
const string CONST_X_ACTIVIST_POLITICAL_GROUPS = "activist political groups.";
const string CONST_X_THE_PUBLIC_IS_UNCONCERNED = "The public is not concerned with politics right now.";

const string CONST_X_TAKING_STRONG_ACTION = "taking strong action.";
const string CONST_X_THE_PEOPLE_ARE_MOST_CONCERNED = "The people are most concerned about ";
const string CONST_X_PRESIDENT = "President ";
const string CONST_X_HAD_FAVORABLE_OPINION = "% had a favorable opinion of ";
const string CONST_X_SURVEY_OF_PUBLIC_OPINION = "Survey of Public Opinion, According to Recent Polls";
const string CONST_X_IS_ACCOSTED_BY_POLICE = " is accosted by police while ";
const string CONST_X_SOLICITING_DONATIONS = "soliciting donations";
const string CONST_X_SELLING_SHIRTS = "selling shirts";
const string CONST_X_SKETCHING_PORTRAITS = "sketching portraits";

const string CONST_X_PLAYING_MUSIC = "playing music";
const string CONST_X_SELLING_BROWNIES = "selling brownies";
const string CONST_X_A_SPACE = " a ";
const string CONST_X_YOUR_HACKERS_HAVE_LOWERCASE = "Your hackers have ";
const string CONST_X_YOUR_HACKERS_HAVE_ = "Your Hackers have ";
const string CONST_X_HAS_BEGUN_WORK_ON_A_LARGE_MURAL_ABOUT_ = " has begun work on a large mural about ";
const string CONST_X_WORKS_THROUGH_THE_NIGHT_ON_A_LARGE_MURAL = " works through the night on a large mural.";
const string CONST_X_MURAL_ABOUT_ = " mural about ";
const string CONST_X_BEAUTIFUL = " beautiful";
const string CONST_X_HAS_COMPLETED_A = " has completed a";
const string CONST_X_WHILE_SPRAYING_AN_LCS_TAG = " while spraying an LCS tag!";
const string CONST_X_WHILE_WORKING_ON_THE_MURAL = " while working on the mural!";
const string CONST_X_WAS_SPOTTED_BY_THE_POLICE = " was spotted by the police";
const string CONST_X_NEEDS_A_SPRAYCAN_EQUIPPED_TO_DO_GRAFFITI = " needs a spraycan equipped to do graffiti.";
const string CONST_X_BOUGHT_SPRAYPAINT_FOR_GRAFFITI = " bought spraypaint for graffiti.";
const string CONST_X_FROM_ = " from ";
const string CONST_X_GRABBED_A_ = " grabbed a ";
const string CONST_X_WAS_NEARLY_CAUGHT_IN_A_PROSTITUTION_STING = " was nearly caught in a prostitution sting.";
const string CONST_X_HAS_BEEN_ARRESTED_IN_A_PROSTITUTION_STING = " has been arrested in a prostitution sting.";
const string CONST_X_SET_UP_A_MOCK_SWEATSHOP_IN_THE_MIDDLE_OF_THE_MALL = "set up a mock sweatshop in the middle of the mall!";
const string CONST_X_BURNED_A_CORPORATE_SYMBOL_AND_DENOUNCED_CAPITALISM = "burned a corporate symbol and denounced capitalism!";
const string CONST_X_DISTRIBUTED_FLIERS_GRAPHICALLY_ILLUSTRATING_CIA_TORTURE = "distributed fliers graphically illustrating CIA torture!";
const string CONST_X_DISTRIBUTED_FLIERS_GRAPHICALLY_ILLUSTRATING_EXECUTIONS = "distributed fliers graphically illustrating executions!";
const string CONST_X_SQUIRTED_BUSINESS_PEOPLE_WITH_FAKE_POLLUTED_WATER = "squirted business people with fake polluted water!";
const string CONST_X_DRESSED_UP_AND_PRETENDED_TO_BE_A_RADIOACTIVE_MUTANT = "dressed up and pretended to be a radioactive mutant!";
const string CONST_X_DRESSED_UP_AND_PRETENDED_TO_BE_RADIOACTIVE_MUTANTS = "dressed up and pretended to be radioactive mutants!";
const string CONST_X_GONE_DOWNTOWN_AND_REENACTED_A_POLICE_BEATING = "gone downtown and reenacted a police beating!";
const string CONST_X_POSTED_HORRIFYING_DEAD_ABORTION_DOCTOR_PICTURES_DOWNTOWN = "posted horrifying dead abortion doctor pictures downtown!";
const string CONST_X_DISRUPTED_A_TRADITIONAL_WEDDING_AT_A_CHURCH = "disrupted a traditional wedding at a church!";
const string CONST_X_RUN_AROUND_UPTOWN_SPLASHING_PAINT_ON_FUR_COATS = "run around uptown splashing paint on fur coats!";
const string CONST_X_BROKEN = "broken!";
const string CONST_X_S_LAST_UNBROKEN_RIB_IS_ = "'s last unbroken rib is ";
const string CONST_X_S_RIB_IS_ = "'s rib is ";
const string CONST_X_ONE_OF_ = "One of ";
const string CONST_X_S_RIBS_ARE_ = "'s ribs are ";
const string CONST_X_OF_ = " of ";
const string CONST_X_ALL_SPACE = "All ";
const string CONST_X_S_TOOTH_HAS_BEEN_PULLED_OUT_WITH_PLIERS = "'s tooth has been pulled out with pliers!";
const string CONST_X_S_TEETH_HAVE_BEEN_SMASHED_OUT_ON_THE_CURB = "'s teeth have been smashed out on the curb.";
const string CONST_X_S_NECK_HAS_BEEN_BROKEN = "'s neck has been broken!";
const string CONST_X_S_UPPER_SPINE_HAS_BEEN_BROKEN = "'s upper spine has been broken!";
const string CONST_X_S_LOWER_SPINE_HAS_BEEN_BROKEN = "'s lower spine has been broken!";
const string CONST_X_IS_SEVERELY_BEATEN_BEFORE_THE_MOB_IS_BROKEN_UP = " is severely beaten before the mob is broken up.";
const string CONST_X_OUT_OF_EVERYONE_WHO_GOT_CLOSE = " out of everyone who got close!";
const string CONST_X_SHIT = "shit";
const string CONST_X_TAR = "[tar]";
const string CONST_X_BEAT_THE = " beat the ";
const string CONST_X_THE_MOB_SCATTERS = "The mob scatters!";
const string CONST_X_BRANDISHES_THE_ = " brandishes the ";
const string CONST_X_IS_CORNERED_BY_A_MOB_OF_ANGRY_REDNECKS = " is cornered by a mob of angry rednecks.";
const string CONST_X_CAUSING_TROUBLE = "causing trouble";
const string CONST_X_YOUR_ACTIVISTS_HAVE_ = "Your Activists have ";
const string CONST_X_PRESS_A_LETTER_TO_SELECT_A_TYPE_OF_CAR = "Press a Letter to select a Type of Car";
const string CONST_X_TYPEDIFFICULTY_TO_FIND_UNATTENDED = "컴컴TYPE컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴DIFFICULTY TO FIND UNATTENDED컴";
const string CONST_X_TRY_TO_FIND_AND_STEAL_TODAY = " try to find and steal today?";
const string CONST_X_WHAT_TYPE_OF_CAR_WILL_ = "What type of car will ";
const string CONST_X_STANDS_BY_THE_ = " stands by the ";
const string CONST_X_THIS_IS_THE_VIPER_STAND_AWAY = "THIS IS THE VIPER!   STAND AWAY!";
const string CONST_X_THE_VIPER_COLON = "THE VIPER:   ";
const string CONST_X_STAND_AWAY_FROM_THE_VEHICLE_BEEP_BEEP = "STAND AWAY FROM THE VEHICLE!   <BEEP!!> <BEEP!!>";
const string CONST_X_BEEP_BEEP_BEEP_BEEP = "<BEEP!!> <BEEP!!> <BEEP!!> <BEEP!!>";
const string CONST_X_COLON_SPACE_SPACE = ":   ";
const string CONST_X_THE_VIPER = "THE VIPER";
const string CONST_X_B_BREAK_THE_WINDOW = "B - Break the window.";
const string CONST_X_A_PICK_THE_LOCK = "A - Pick the lock.";
const string CONST_X_BUT_IT_IS_STILL_SOMEWHAT_INTACT = " but it is still somewhat intact.";
const string CONST_X_WITH_A_ = " with a ";
const string CONST_X_CRACKS_THE_WINDOW = " cracks the window";
const string CONST_X_SMASHES_THE_WINDOW = " smashes the window";
const string CONST_X_FIDDLES_WITH_THE_LOCK_WITH_NO_LUCK = " fiddles with the lock with no luck.";
const string CONST_X_AN_ALARM_SUDDENLY_STARTS_BLARING = "An alarm suddenly starts blaring!";
const string CONST_X_JIMMIES_THE_CAR_DOOR_OPEN = " jimmies the car door open.";
const string CONST_X_HAS_BEEN_SPOTTED_BY_A_PASSERBY = " has been spotted by a passerby!";

const string CONST_X_ADVENTURES_IN_LIBERAL_CAR_THEFT = "Adventures in Liberal Car Theft";

const string CONST_X_IF_THEY_WERE_HERE_ID_HAVE_FOUND_THEM_BY_NOW = "If they were here, I'd have found them by now.";
const string CONST_X_I_DONT_THINK_THEYRE_IN_HERE = "I don't think they're in here...";
const string CONST_X_ARE_THEY_EVEN_IN_HERE = "Are they even in here?";
const string CONST_X_RUMMAGING_ = ": <rummaging> ";
const string CONST_X_FOUND_THE_KEYS = " found the keys ";
const string CONST_X_HOLY_SHIT_ = "Holy shit!  ";
const string CONST_X_HOLY_CAR_KEYS_ = "Holy [Car Keys]!  ";
const string CONST_X_UNDER_THE_BACK_SEAT = "under the back seat!";
const string CONST_X_UNDER_THE_FRONT_SEAT = "under the front seat!";
const string CONST_X_IN_THE_GLOVE_COMPARTMENT = "in the glove compartment!";
const string CONST_X_ABOVE_THE_PULLDOWN_SUNBLOCK_THINGY = "above the pull-down sunblock thingy!";
const string CONST_X_IN_THE_IGNITION_DAMN = "in the ignition.  Damn.";
const string CONST_X_IN_SPACE_WITH_ALIENS_SERIOUSLY = "in SPACE. With ALIENS. Seriously.";

const string CONST_X_HOTWIRES_THE_CAR = " hotwires the car!";
const string CONST_X_ENTER_THE_VIPER_HAS_FINALLY_DETERRED_ = "Enter - The Viper has finally deterred ";
const string CONST_CALL_IT_A_DAY_PRESS_ENTER = "Enter - Call it a day.";
const string CONST_X_B_DESPERATELY_SEARCH_FOR_KEYS = "B - Desperately search for keys.";
const string CONST_X_A_HOTWIRE_THE_CAR = "A - Hotwire the car.";


const string CONST_X_REMOVE_YOURSELF_FROM_THE_VEHICLE_BEEP_BEEP = "REMOVE YOURSELF FROM THE VEHICLE!   <BEEP!!> <BEEP!!>";


const string CONST_X_IS_BEHIND_THE_WHEEL_OF_A_ = " is behind the wheel of a ";
const string CONST_X_A_APPROACH_THE_DRIVERS_SIDE_DOOR = "A - Approach the driver's side door.";
const string CONST_X_LOOKS_FROM_A_DISTANCE_AT_AN_EMPTY_ = " looks from a distance at an empty ";
const string CONST_X_FOUND_A = " found a ";
const string CONST_X_LOOKS_AROUND_FOR_AN_ACCESSIBLE_VEHICLE = " looks around for an accessible vehicle...";
const string CONST_X_WAS_UNABLE_TO_GET_A_WHEELCHAIR_MAYBE_TOMORROW = " was unable to get a wheelchair.  Maybe tomorrow...";
const string CONST_X_HAS_PROCURED_A_WHEELCHAIR = " has procured a wheelchair.";
const string ACTIVITIES_FOLDER = "activities\\";

const string CONST_X_CANT_FIND_KEYS_NFS_TXT = "cant_find_keys_no_free_speech.txt";
const string CONST_X_CANT_FIND_KEYS_TXT = "cant_find_keys.txt";
const string CONST_X_ALMOST_HOTWIRE_TXT = "almost_hotwire_car.txt";
const string CONST_X_CANT_HOTWIRE_TXT = "cant_hotwire_car.txt";
const string CONST_X_GETS_NERVOUS_TXT = "gets_nervous.txt";
const string CONST_X_CAR_WONT_START_TXT = "car_wont_start.txt";
const string CONST_X_LOST_HAND_TO_HAND_TXT = "lose_hand_to_hand.txt";
const string CONST_X_WIN_HAND_TO_HAND_TXT = "win_hand_to_hand.txt";
const string CONST_X_ENEMY_WEBSITE_TXT = "enemy_website.txt";
const string CONST_X_WORDS_MEANING_HACKED_TXT = "words_meaning_hacked.txt";
const string CONST_X_QUALITY_50_TXT = "quality_50.txt";
const string CONST_X_QUALITY_35_TXT = "quality_35.txt";
const string CONST_X_QUALITY_20_TXT = "quality_20.txt";
const string CONST_X_QUALITY_0_TXT = "quality_0.txt";
const string CONST_X_S_BODY = "'s body";
const string CONST_X_BURYING_ = "burying ";

#endif	//ACTIVITIES_CPP
#endif // INCLUDES_H_INCLUDED
