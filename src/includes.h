


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

#include "sdl/SDL.h"
#include "sdl/SDL_mixer.h"

#include <string.h>


using namespace std;

// Macro definition 
#ifndef MAX
// maximum of 2 numbers
#define MAX(a,b) (((a)<(b))?(b):(a))
#endif
#ifndef MIN
// minimum of 2 numbers
#define MIN(a,b) (((a)>(b))?(b):(a))
#endif
#ifndef ABS
// absolute value of a number
#define ABS(x) ((x)<0)?(-x):(x)
#endif
#ifndef DIFF
// difference between 2 numbers (absolute value of subtracting one from the other)
#define DIFF(x,y) ((x)<(y)?((y)-(x)):((x)-(y)))
#endif
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
					   //LCSIO_PRE_CONFIG = 3 /// Append the given file name to the config directory path.
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
	//LAWFLAG_GUNUSE,     // "Firing illegal weapons"
	//LAWFLAG_GUNCARRY,   // "Carrying illegal weapons"
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
	//ACTIVITY_STUDY_COOKING,
	ACTIVITY_STUDY_GYMNASTICS,
	ACTIVITY_STUDY_MUSIC,
	ACTIVITY_STUDY_ART,
	ACTIVITY_STUDY_TEACHING,
	ACTIVITY_STUDY_WRITING,
	ACTIVITY_STUDY_LOCKSMITHING,
	ACTIVITY_STUDY_COMPUTERS,
	// Terra Vitae
	ACTIVITY_STUDY_FENCING,
	ACTIVITY_STUDY_WEAVING,
	ACTIVITY_STUDY_RELIGION,
	// ACTIVITY_STUDY_MAGIC,
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
	//VIEW_POLITICALVIOLENCE,
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
//};

//enum shopItemTagEnums {
	ENUM_tag_class,
	ENUM_tag_type,
	ENUM_tag_description,
	ENUM_tag_price,
	ENUM_tag_sleeperprice,
//	ENUM_tag_letter,

//};

//enum creatureTypeTagEnums {
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
//};

//enum weaponTypeTagEnum {
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
//};

//enum attackSTEnums {
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
//};

//enum augmentTagEnums {
	ENUM_tag_name,
//	ENUM_tag_type,
	ENUM_tag_attribute,
	ENUM_tag_effect,
//	ENUM_tag_description,
	ENUM_tag_max_age,
	ENUM_tag_min_age,
	ENUM_tag_cost,
	ENUM_tag_difficulty,
//};

//enum armorTypeInitEnums {
	ENUM_tag_make_difficulty,
	ENUM_tag_make_price,
	ENUM_tag_deathsquad_legality,
	ENUM_tag_can_get_bloody,
	ENUM_tag_can_get_damaged,
//	ENUM_tag_armor,
	ENUM_tag_body_covering,
//	ENUM_tag_shortname,
	ENUM_tag_interrogation,
	ENUM_tag_professionalism,
	ENUM_tag_conceal_weapon_size,
	ENUM_tag_stealth_value,
	ENUM_tag_mask,
	ENUM_tag_surprise,
//	ENUM_tag_description,
	ENUM_tag_qualitylevels,
	ENUM_tag_durability,
//};

//enum vehicleTagEnums {
	ENUM_tag_vtypeidname,
	ENUM_tag_vtypeid,
	ENUM_tag_color,
	ENUM_tag_heat,
	ENUM_tag_location,
	ENUM_tag_myear,
	ENUM_tag_id,
//};

//enum vehicleTypeTagsEnums {
	ENUM_tag_year,
	ENUM_tag_start_at_current_year,
	ENUM_tag_start_at_year,
	ENUM_tag_add_random_up_to_current_year,
	ENUM_tag_add_random,
	ENUM_tag_add,
	ENUM_tag_colors,
//	ENUM_tag_color,
	ENUM_tag_display_color,
	ENUM_tag_drivebonus,
	ENUM_tag_base,
	ENUM_tag_skillfactor,
	ENUM_tag_softlimit,
	ENUM_tag_hardlimit,
	ENUM_tag_dodgebonus,
//	ENUM_tag_base,
//	ENUM_tag_skillfactor,
//	ENUM_tag_softlimit,
//	ENUM_tag_hardlimit,
	ENUM_tag_attackbonus,
	ENUM_tag_driver,
	ENUM_tag_passenger,
	ENUM_tag_longname,
//	ENUM_tag_shortname,
	ENUM_tag_stealing,
	ENUM_tag_difficulty_to_find,
//	ENUM_tag_juice,
	ENUM_tag_extra_heat,
	ENUM_tag_sense_alarm_chance,
	ENUM_tag_touch_alarm_chance,
//	ENUM_tag_armor,
	ENUM_tag_low_armor_min,
	ENUM_tag_low_armor_max,
	ENUM_tag_high_armor_min,
	ENUM_tag_high_armor_max,
	ENUM_tag_armor_midpoint,
	ENUM_tag_available_at_dealership,
//	ENUM_tag_price,
//	ENUM_tag_sleeperprice
};

string skill_enum_to_string(int skill_type);
string showXmlSkill(int skill_, int value_);
string showXmlAttribute(int attribute_, int value_);
//using namespace std;

const string PACKAGE_VERSION_STR = "4.12.32";
const int version = 41232;
const int lowestloadversion = 40100;
const int lowestloadscoreversion = 31203;

const string blankString = "";
const string singleDot = ".";
const string dotSpace = ". ";
const string commaSpace = ", ";
const string spaceDashSpace = " - ";
const string spaceParanthesisDollar = " ($";
const string paranthesisDollar = "($";
const string colonSpace = ": ";
const string ampersandC = "&c";
const string closeParenthesis = ")";
const string percentSign = "%";
const string singleSpace = " ";

const string chooseALiberalTo = "Choose a Liberal squad member to ";

const string AND = " and ";
const string string_sleeper = "Sleeper ";
const string ampersandR = "&r";
const string show_squad_liberal_status = "0 - Show the squad's Liberal status";
const string check_status_of_squad_liberal = "# - Check the status of a squad Liberal";
const string change_squad_order = "O - Change the squad's Liberal order";
const string enter_done = "Enter - Done";
const string undefined = "UNDEFINED";
const string exclamationPoint = "!";
const string failedToLoad = "Failed to load ";
const string pressAnyOtherKey = "Press any other key to continue...";
const string pressAnyKeyString = "Press any other key when ready to begin...";
const string city = "CITY: ";
const string tag_heat = "heat";

#ifdef	ACTIVATE_CPP
//activate.cpp


#include "../creature/creature.h"
#include "../locations/locations.h"
#include "../items/armortype.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../creature/augmenttype.h"
#include "../common/translateid.h"
// for  int getsquad(int)
//#include "../common/commonactions.h"
void sorting_prompt(short listforsorting);
#include "../common/commonactionsCreature.h"
// for void sortliberals(std::vector<Creature *>&,short,bool)
#include "../common/commondisplay.h"
#include "../common/commondisplayCreature.h"
// for void printfunds(int,int,char*)
//#include "../common/getnames.h"
std::string gettitle(const int align, const int juice);
string getactivity(ActivityST &act);
//#include "../common/help.h"
void HelpActivities(int);
//#include "../common/stringconversion.h"
string attribute_enum_to_string(int);
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
siegest* getseigestFromLocation(int secondaryLocation);
void gotoEquipmentScreen(int loc);
void createTempSquadWithJustThisLiberal(DeprecatedCreature *cr, int cursquadid);
#include "../common/creaturePoolCreature.h"
#include "../common/musicClass.h"


extern vector<RecruitData> recruitable_creatures;

extern short lawList[LAWNUM];
extern Log gamelog;

extern Log gamelog;
extern vector<ArmorType *> armortype;

extern short lawList[LAWNUM];
extern vector<ArmorType *> armortype;
extern bool ZEROMORAL;
extern short mode;
extern long cursquadid;
extern int selectedsiege;

extern bool ZEROMORAL;
extern MusicClass music;
extern short mode;
extern short activesortingchoice[SORTINGCHOICENUM];

const string CONST_activate066 = "Activate Uninvolved Liberals";
const string CONST_activate067 = "컴컴CODE NAME컴컴컴컴컴컴SKILL컴횴EALTH컴횸OCATION컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";

const string CONST_activate007 = "Other classes";
const string CONST_activate006 = "Classes cost $60 a day. Study what?";
const string CONST_activate011 = "Press a Letter to select a Profession";
const string CONST_activate010 = "컴컴TYPE컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴횯IFFICULTY TO ARRANGE MEETING컴";
const string CONST_activate009 = " try to meet and recruit today?";
const string CONST_activate008 = "What type of person will ";
const string CONST_activate014 = "Age: ";
const string CONST_activate013 = "Heart: ";
const string CONST_activate012 = "Status:";
const string CONST_activate032 = " has been brutally murdered by ";
const string CONST_activate031 = " has been augmented with ";
const string CONST_activate030 = " has been horribly disfigured";
const string CONST_activate029 = "Press any key to return";
const string CONST_activate028 = "Are you sure? (y/n)";
const string CONST_activate027 = "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴";
const string CONST_activate026 = "Description";
const string CONST_activate025 = "Chance at Success: ";
const string CONST_activate024 = " +";
const string CONST_activate023 = "Effect: ";
const string CONST_activate022 = "Augmentation: ";
const string CONST_activate021 = "Subject: ";
const string CONST_activate020 = "Select an Augmentation";
const string CONST_activate019 = "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴";
const string CONST_activate017 = "Press a Letter to select a Liberal";
const string CONST_activate016 = "컴컴NAME컴컴컴컴컴컴컴컴컴컴컴횴EALTH컴컴컴컴컴컴HEART컴컴컴컴AGE컴컴컴컴컴컴컴�";
const string CONST_activate015 = "Select a Liberal to perform experiments on";
const string CONST_activate036 = "Press a Letter to select a Type of Clothing";
const string CONST_activate035 = "컴컴NAME컴컴컴컴컴컴컴컴컴컴컴컴컴컴횯IFFICULTY컴컴컴컴컴컴횮OST컴컴컴컴컴컴컴컴";
const string CONST_activate034 = " try to make?   (Note: Half Cost if you have cloth)";
const string CONST_activate033 = "Which will ";
const string CONST_activate043 = "Press a Letter to select a Conservative";
const string CONST_activate042 = "Day";
const string CONST_activate041 = "Days";
const string CONST_activate040 = "DAYS IN CAPTIVITY";
const string CONST_activate038 = " be watching over?";
const string CONST_activate037 = "Which hostage will ";
const string CONST_activate058 = " will ";
const string CONST_activate057 = "X - Nothing for Now";
const string CONST_activate056 = "Enter - Confirm Selection";
const string CONST_activate055 = "? - Help";
const string CONST_activate054 = "E - Equip this Liberal";
const string CONST_activate053 = "Z - Dispose of bodies";
const string CONST_activate052 = "H - Heal Liberals";
const string CONST_activate051 = "M - Move to the Free Clinic";
const string CONST_activate050 = "L - Learn in the University District";
const string CONST_activate049 = "I - Tend to a Conservative hostage";
const string CONST_activate048 = "T - Teaching Other Liberals";
const string CONST_activate047 = " be doing today?";
const string CONST_activate046 = "Taking Action: What will ";
const string CONST_activate045 = " yesterday. What now?";
const string CONST_activate044 = " made $";
const string CONST_activate064 = "Press a Letter to Assign an Activity.  Press a Number to select an Activity.";
const string CONST_activate063 = "BULK ACTIVITY";
const string CONST_activate062 = "컴컴CODE NAME컴컴컴컴컴컴CURRENT ACTIVITY컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�";
const string CONST_activate071 = "Press Z to assign simple tasks in bulk.";
const string CONST_activate070 = " T to sort people.";
const string CONST_activate069 = "Press a Letter to Assign an Activity.";
const string CONST_activate068 = "ACTIVITY";
const string mostlyendings = "mostlyendings\\";

const string CONST_activate060 = "standard_activities_and_data.txt";
const string CONST_activate059 = "bulkActivityString.txt";
vector<ActivityAndString> data_lessons;
map<Activity, Data_Activity> data_activities;
map<char, vector<ActivityAndString> > activate_menu_items;

vector<CreatureTypes> ACTIVITY_TEACH_FIGHTING_DEFAULT;
// this first block are creatures with All Weapon Skills, Martial Arts, Dodge, and First Aid
vector<CreatureTypes> ACTIVITY_TEACH_COVERT_DEFAULT;
// this second block are creatures with Computers, Security, Stealth, Disguise, Tailoring, Seduction, Psychology, & Driving
vector<CreatureTypes> ACTIVITY_TEACH_POLITICS_DEFAULT;
// this third block are creatures with Writing, Persuasion, Law, Street Sense, Science, Religion, Business, Music, & Art

#endif	//ACTIVATE_CPP
#ifdef	ACTIVATE_SLEEPERS_CPP
//activate_sleepers.cpp
#include "../creature/creature.h"
//#include "../common/commonactions.h"
void sorting_prompt(short listforsorting);
#include "../common/commonactionsCreature.h"
// for void sortliberals(std::vector<Creature *>&,short,bool)
#include "../common/commondisplay.h"
//#include "../common/commondisplayCreature.h"
void printcreatureinfo(DeprecatedCreature *cr, unsigned char knowledge = 255);
//#include "../common/getnames.h"
string getactivity(ActivityST &act);
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
#include "../common/creaturePoolCreature.h"
//extern string spaceDashSpace;
//extern string percentSign;


//	extern string percentSign;
extern MusicClass music;
extern short activesortingchoice[SORTINGCHOICENUM];
//// #include "../common/commonactions.h"
void sorting_prompt(short listforsorting);
string getactivity(ActivityST &act);
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";

const string CONST_activate_sleepers023 = " will steal equipment and send it to the Shelter.";
const string CONST_activate_sleepers022 = " will embezzle money for the LCS.";
const string CONST_activate_sleepers021 = " will snoop around for secrets and enemy plans.";
const string CONST_activate_sleepers020 = " will try to recruit additional sleeper agents.";
const string CONST_activate_sleepers019 = " will build support for Liberal causes.";
const string CONST_activate_sleepers018 = " will stay out of trouble.";
const string CONST_activate_sleepers017 = "3 - Steal Equipment";
const string CONST_activate_sleepers016 = "2 - Embezzle Funds";
const string CONST_activate_sleepers015 = "1 - Uncover Secrets";
const string CONST_activate_sleepers014 = "3 - [Need More Juice to Recruit]";
const string CONST_activate_sleepers013 = "3 - [Enlightened Can't Recruit]";
const string CONST_activate_sleepers012 = "3 - Expand Sleeper Network";
const string CONST_activate_sleepers011 = "2 - Advocate Liberalism";
const string CONST_activate_sleepers010 = "1 - Lay Low";
const string CONST_activate_sleepers009 = "Enter - Confirm Selection";
const string CONST_activate_sleepers008 = "C - Join the Active LCS";
const string CONST_activate_sleepers007 = "B - Espionage";
const string CONST_activate_sleepers006 = "A - Communication and Advocacy";
const string CONST_activate_sleepers005 = " focus on?";
const string CONST_activate_sleepers004 = "Taking Undercover Action:   What will ";

const string CONST_activate_sleepers031 = " T to sort people.";
const string CONST_activate_sleepers030 = "Press a Letter to Assign an Activity.";
const string CONST_activate_sleepers029 = "Effectiveness: ";
const string CONST_activate_sleepers028 = "ACTIVITY";
const string CONST_activate_sleepers027 = "SITE";
const string CONST_activate_sleepers026 = "JOB";
const string CONST_activate_sleepers025 = "CODE NAME";
const string CONST_activate_sleepers024 = "Activate Sleeper Agents";

#endif	//ACTIVATE_SLEEPERS_CPP
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
extern Log gamelog;
extern vector<Deprecatedsquadst *> squad;
extern Log gamelog;
extern class Ledger ledger;
extern vector<Deprecatedsquadst *> squad;
extern vector<ArmorType *> armortype;

extern short lawList[LAWNUM];
extern char newscherrybusted;
extern char endgamestate;
extern short public_interest[VIEWNUM];
extern Log gamelog;


extern class Ledger ledger;
extern short background_liberal_influence[VIEWNUM];
extern Deprecatednewsstoryst *sitestory;
extern class Ledger ledger;
extern short lawList[LAWNUM];
extern vector<Deprecatednewsstoryst *> newsstory;
extern Log gamelog;
extern class Ledger ledger;
string gimmeASprayCan(DeprecatedCreature* graffiti);
void buyMeASprayCan(DeprecatedCreature* graffiti);
extern Deprecatednewsstoryst *sitestory;
extern Log gamelog;
extern class Ledger ledger;
extern short public_interest[VIEWNUM];
extern short background_liberal_influence[VIEWNUM];
extern vector<Deprecatednewsstoryst *> newsstory;
extern Log gamelog;
extern class Ledger ledger;
extern Log gamelog;
extern class Ledger ledger;
extern Log gamelog;
extern Deprecatednewsstoryst *sitestory;
extern short public_interest[VIEWNUM];
extern short lawList[LAWNUM];
extern short background_liberal_influence[VIEWNUM];
extern vector<Deprecatednewsstoryst *> newsstory;
extern Log gamelog;
extern Deprecatednewsstoryst *sitestory;
extern short public_interest[VIEWNUM];
extern short lawList[LAWNUM];
extern short background_liberal_influence[VIEWNUM];
extern vector<Deprecatednewsstoryst *> newsstory;
extern class Ledger ledger;
extern vector<DeprecatedCreature *> pool;
extern Deprecatednewsstoryst *sitestory;
extern vector<DeprecatedCreature *> pool;
extern vector<Deprecatednewsstoryst *> newsstory;
string wasUnableToFind(const string old);
string considerLeaving(const bool sensealarm, const bool alarmon, const string name);

extern Log gamelog;
extern vector<Deprecatednewsstoryst *> newsstory;
extern Deprecatednewsstoryst *sitestory;
extern chaseseqst chaseseq;
extern short mode;
extern short fieldskillrate;

enum CarHotwireMethod {
	UNDETERMINED,
	ATTEMPT_HOTWIRE,
	USE_KEYS
};
extern Log gamelog;

extern short lawList[LAWNUM];
extern Log gamelog;

extern vector<Deprecatednewsstoryst *> newsstory;
extern Deprecatednewsstoryst *sitestory;
extern chaseseqst chaseseq;
extern short mode;
extern short fieldskillrate;
extern short lawList[LAWNUM];
Vehicle* getVehicleOfThisType(int cartype);
void newVehicle(Vehicle *startcar);
extern Log gamelog;
extern MusicClass music;
extern short mode;
extern Deprecatednewsstoryst *sitestory;
extern chaseseqst chaseseq;
extern short fieldskillrate;
extern short lawList[LAWNUM];
extern vector<Deprecatednewsstoryst *> newsstory;
extern Log gamelog;

extern short attitude[VIEWNUM];
extern short lawList[LAWNUM];
extern short attitude[VIEWNUM];
extern short public_interest[VIEWNUM];
extern bool SHOWMECHANICS;
static const char SURVEY_PAGE_SIZE = 14;
extern short public_interest[VIEWNUM];
extern Log gamelog;
extern MusicClass music;
extern short interface_pgup;
extern short interface_pgdn;
extern Log gamelog;
extern char newscherrybusted;
extern char endgamestate;
extern Deprecatednewsstoryst *sitestory;
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern short exec[EXECNUM];
extern Log gamelog;
extern Deprecatednewsstoryst *sitestory;
extern chaseseqst chaseseq;
extern vector<Deprecatednewsstoryst *> newsstory;
extern Deprecatednewsstoryst *sitestory;
extern vector<Deprecatednewsstoryst *> newsstory;
extern short background_liberal_influence[VIEWNUM];
//ACTIVITIES FOR INDIVIDUALS
extern vector<DeprecatedCreature *> pool;
extern class Ledger ledger;
extern class Ledger ledger;
extern short background_liberal_influence[VIEWNUM];
extern class Ledger ledger;
extern short background_liberal_influence[VIEWNUM];
const string CONST_activities104 = " can.";
const string CONST_activities103 = " has learned as much as ";

const string tag_POLICECAR = "POLICECAR";
const string tag_WEAPON_SPRAYCAN = "WEAPON_SPRAYCAN";
const string tag_WEAPON = "WEAPON";
const string CONST_activities106 = " has ";
const string CONST_activities121 = "!";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
const string CONST_activities026 = " peruses some sewing magazines.";
const string CONST_activities025 = " cleans the kitchen.";
const string CONST_activities024 = " reorganizes the armor closet.";
const string CONST_activities023 = " tidies up the safehouse.";
const string CONST_activities033 = " ruined";
const string CONST_activities032 = " repairs what little can be fixed of ";
const string CONST_activities031 = " finds there is no hope of repairing ";
const string CONST_activities030 = " repairs ";
const string CONST_activities029 = " is working to repair ";
const string CONST_activities028 = " cleans ";
const string CONST_activities027 = " disposes of ";
const string CONST_activities042 = " wasted the materials for a";
const string CONST_activities041 = "th-rate";
const string CONST_activities040 = "fourth-rate";
const string CONST_activities039 = "third-rate";
const string CONST_activities038 = "second-rate";
const string CONST_activities037 = "first-rate";
const string CONST_activities036 = " has made a ";
const string CONST_activities035 = " cannot find enough cloth to reduce clothing costs.";
const string CONST_activities034 = " cannot afford material for clothing.";
const string CONST_activities060 = "    ";
const string CONST_activities059 = "Enter - Done";
const string CONST_activities058 = " Liberal percentage points.";
const string CONST_activities057 = "Results are +/- ";
const string CONST_activities056 = "XX% Issue 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?Public Interest";
const string CONST_activities055 = "Additional notable findings:";
const string CONST_activities076 = "wanted amnesty for illegal immigrants";
const string CONST_activities075 = "condemned unnecessary immigration regulations";
const string CONST_activities074 = "believed in legalizing marijuana";
const string CONST_activities073 = "supported keeping marijuana legal";
const string CONST_activities072 = "% ";
const string CONST_activities071 = "??";
const string CONST_activities070 = "None     ";
const string CONST_activities069 = "Low      ";
const string CONST_activities068 = "Moderate ";
const string CONST_activities067 = "High     ";
const string CONST_activities066 = "Very High";
const string CONST_activities063 = "Unknown  ";
const string CONST_activities062 = "........................................................";
const string CONST_activities061 = "                                                                                ";
const string CONST_activities053 = "Liberal Media Bias.";
const string CONST_activities052 = "Conservative Media Bias.";
const string CONST_activities051 = "the LCS terrorists.";
const string CONST_activities050 = "the Liberal Crime Squad.";
const string CONST_activities049 = "activist political groups.";
const string CONST_activities054 = "The public is not concerned with politics right now.";

const string CONST_activities047 = "taking strong action.";
const string CONST_activities046 = "The people are most concerned about ";
const string CONST_activities045 = "President ";
const string CONST_activities044 = "% had a favorable opinion of ";
const string CONST_activities043 = "Survey of Public Opinion, According to Recent Polls";
const string CONST_activities077 = " is accosted by police while ";
const string CONST_activities079 = "soliciting donations";
const string CONST_activities080 = "selling shirts";
const string CONST_activities081 = "sketching portraits";

const string CONST_activities082 = "playing music";
const string CONST_activities083 = "selling brownies";
const string CONST_activities088 = " a ";
const string CONST_activities086 = "Your hackers have ";
const string CONST_activities084 = "Your Hackers have ";
const string CONST_activities100 = " has begun work on a large mural about ";
const string CONST_activities099 = " works through the night on a large mural.";
const string CONST_activities098 = " mural about ";
const string CONST_activities097 = " beautiful";
const string CONST_activities096 = " has completed a";
const string CONST_activities095 = " while spraying an LCS tag!";
const string CONST_activities094 = " while working on the mural!";
const string CONST_activities093 = " was spotted by the police";
const string CONST_activities092 = " needs a spraycan equipped to do graffiti.";
const string CONST_activities091 = " bought spraypaint for graffiti.";
const string CONST_activities090 = " from ";
const string CONST_activities089 = " grabbed a ";
const string CONST_activities102 = " was nearly caught in a prostitution sting.";
const string CONST_activities101 = " has been arrested in a prostitution sting.";
const string CONST_activities117 = "set up a mock sweatshop in the middle of the mall!";
const string CONST_activities116 = "burned a corporate symbol and denounced capitalism!";
const string CONST_activities115 = "distributed fliers graphically illustrating CIA torture!";
const string CONST_activities114 = "distributed fliers graphically illustrating executions!";
const string CONST_activities113 = "squirted business people with fake polluted water!";
const string CONST_activities112 = "dressed up and pretended to be a radioactive mutant!";
const string CONST_activities111 = "dressed up and pretended to be radioactive mutants!";
const string CONST_activities110 = "gone downtown and reenacted a police beating!";
const string CONST_activities109 = "posted horrifying dead abortion doctor pictures downtown!";
const string CONST_activities108 = "disrupted a traditional wedding at a church!";
const string CONST_activities107 = "run around uptown splashing paint on fur coats!";
const string CONST_activities139 = "broken!";
const string CONST_activities138 = "'s last unbroken rib is ";
const string CONST_activities137 = "'s rib is ";
const string CONST_activities136 = "One of ";
const string CONST_activities135 = "'s ribs are ";
const string CONST_activities134 = " of ";
const string CONST_activities133 = "All ";
const string CONST_activities132 = "'s tooth has been pulled out with pliers!";
const string CONST_activities131 = "'s teeth have been smashed out on the curb.";
const string CONST_activities130 = "'s neck has been broken!";
const string CONST_activities129 = "'s upper spine has been broken!";
const string CONST_activities128 = "'s lower spine has been broken!";
const string CONST_activities127 = " is severely beaten before the mob is broken up.";
const string CONST_activities126 = " out of everyone who got close!";
const string CONST_activities125 = "shit";
const string CONST_activities124 = "[tar]";
const string CONST_activities123 = " beat the ";
const string CONST_activities122 = "The mob scatters!";
const string CONST_activities120 = " brandishes the ";
const string CONST_activities119 = " is cornered by a mob of angry rednecks.";
const string CONST_activities118 = "causing trouble";
const string CONST_activities105 = "Your Activists have ";
const string CONST_activities145 = "Press a Letter to select a Type of Car";
const string CONST_activities144 = "컴컴TYPE컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴DIFFICULTY TO FIND UNATTENDED컴";
const string CONST_activities143 = " try to find and steal today?";
const string CONST_activities142 = "What type of car will ";
const string CONST_activities162 = " stands by the ";
const string CONST_activities161 = "THIS IS THE VIPER!   STAND AWAY!";
const string CONST_activities160 = "THE VIPER:   ";
const string CONST_activities158 = "STAND AWAY FROM THE VEHICLE!   <BEEP!!> <BEEP!!>";
const string CONST_activities183 = "<BEEP!!> <BEEP!!> <BEEP!!> <BEEP!!>";
const string CONST_activities181 = ":   ";
const string CONST_activities180 = "THE VIPER";
const string CONST_activities164 = "B - Break the window.";
const string CONST_activities163 = "A - Pick the lock.";
const string CONST_activities175 = " but it is still somewhat intact.";
const string CONST_activities174 = " with a ";
const string CONST_activities173 = " cracks the window";
const string CONST_activities171 = " smashes the window";
const string CONST_activities170 = " fiddles with the lock with no luck.";
const string CONST_activities176 = "An alarm suddenly starts blaring!";
const string CONST_activities169 = " jimmies the car door open.";
const string CONST_activities202 = " has been spotted by a passerby!";

const string CONST_activities178 = "Adventures in Liberal Car Theft";

const string CONST_activities201 = "If they were here, I'd have found them by now.";
const string CONST_activities200 = "I don't think they're in here...";
const string CONST_activities199 = "Are they even in here?";
const string CONST_activities198 = ": <rummaging> ";
const string CONST_activities197 = " found the keys ";
const string CONST_activities196 = "Holy shit!  ";
const string CONST_activities195 = "Holy [Car Keys]!  ";
const string CONST_activities194 = "under the back seat!";
const string CONST_activities193 = "under the front seat!";
const string CONST_activities192 = "in the glove compartment!";
const string CONST_activities191 = "above the pull-down sunblock thingy!";
const string CONST_activities190 = "in the ignition.  Damn.";
const string CONST_activities189 = "in SPACE. With ALIENS. Seriously.";

const string CONST_activities188 = " hotwires the car!";
const string CONST_activities187 = "Enter - The Viper has finally deterred ";
const string CONST_activities186 = "Enter - Call it a day.";
const string CONST_activities185 = "B - Desperately search for keys.";
const string CONST_activities184 = "A - Hotwire the car.";


const string CONST_activities182 = "REMOVE YOURSELF FROM THE VEHICLE!   <BEEP!!> <BEEP!!>";


const string CONST_activities179 = " is behind the wheel of a ";
const string CONST_activities153 = "A - Approach the driver's side door.";
const string CONST_activities152 = " looks from a distance at an empty ";
const string CONST_activities150 = " found a ";
const string CONST_activities147 = " looks around for an accessible vehicle...";
const string CONST_activities204 = " was unable to get a wheelchair.  Maybe tomorrow...";
const string CONST_activities203 = " has procured a wheelchair.";
const string activities = "activities\\";

const string CONST_activities022 = "cant_find_keys_no_free_speech.txt";
const string CONST_activities021 = "cant_find_keys.txt";
const string CONST_activities020 = "almost_hotwire_car.txt";
const string CONST_activities019 = "cant_hotwire_car.txt";
const string CONST_activities018 = "gets_nervous.txt";
const string CONST_activities017 = "car_wont_start.txt";
const string CONST_activities016 = "lose_hand_to_hand.txt";
const string CONST_activities015 = "win_hand_to_hand.txt";
const string CONST_activities014 = "enemy_website.txt";
const string CONST_activities013 = "words_meaning_hacked.txt";
const string CONST_activities012 = "quality_50.txt";
const string CONST_activities011 = "quality_35.txt";
const string CONST_activities010 = "quality_20.txt";
const string CONST_activities009 = "quality_0.txt";
// doActivityBury
const string CONST_activities141 = "'s body";
const string CONST_activities140 = "burying ";

#endif	//ACTIVITIES_CPP
#ifdef	ADVANCE_CPP

// advance.cpp

#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"

#include "sitedisplay.h"

#include "../log/log.h"

//#include "common/commondisplay.h"
void printparty();

#include "../common/commonactions.h"
// for void criminalizeparty(short crime)

#include "../combat/fight.h"
#include "../combat/fightCreature.h"  

//#include "combat/haulkidnap.h"
void squadgrab_immobile(char dead);
//#include "combat/haulkidnapCreature.h"

#include "../cursesAlternative.h"
#include "../set_color_support.h"

#include "../locations/locationsPool.h"
#include "../common/creaturePool.h"

void addLocationChange(int cursite, sitechangest change);
//string smellsPanic;
void squadgrab_immobile(char dead);
//// #include "combat/haulkidnapCreature.h"
void freehostage(DeprecatedCreature &cr, char situation);
void advancecreature(const int e);
bool isThereASiteAlarm();
void setSiteAlarmOne();
void resetSiteAlarm();
extern Deprecatedsquadst *activesquad;
extern Deprecatednewsstoryst *sitestory;
extern coordinatest loc_coord;
extern Log gamelog;
extern short mode;
extern int stat_dead;
extern int stat_kills;
extern int ccs_siege_kills;
extern int ccs_boss_kills;
extern int sitecrime;
extern siteblockst levelmap[MAPX][MAPY][MAPZ];
extern short lawList[LAWNUM];
extern int sitecrime;

extern short sitealarmtimer;
extern short siteonfire;
extern Log gamelog;
extern short postalarmtimer;
extern siteblockst levelmap[MAPX][MAPY][MAPZ];
extern int sitecrime;
extern Deprecatednewsstoryst *sitestory;

extern Deprecatedsquadst *activesquad;
extern Log gamelog;
extern short mode;

//string smellsPanic;


vector<NameAndAlignment> getEncounterNameAndAlignment();
short getCurrentSite();
const string smellsPanic = "The Squad smells Conservative panic.";
const string ableToStopBleed = " was able to slow the bleeding of";
const string sWounds = "'s wounds.";
const string isBurned = " is burned!";
const string drops = " drops ";
const string sBody = "'s body.";
const string tag_value = "value";

const string tag_attribute = "attribute";


const string tag_skill = "skill";

#endif	 //ADVANCE_CPP
#ifdef	ARMOR_CPP
// armor.cpp

#include "../items/itemtype.h"
#include "../items/item.h"
#include "../items/armortype.h"
#include "../items/armor.h"
//own header
#include "../common/stringconversion.h"
//for int stringtobool(std::string)
#include "../common/translateid.h"
// for  int getarmortype


const string CONST_armor011 = "]";
const string CONST_armor010 = "[";
const string tag_D = "D";
const string tag_B = "B";
const string tag_X = "X";
const string tag_quality = "quality";
const string tag_false = "false";
const string tag_damaged = "damaged";
const string tag_true = "true";
const string tag_bloody = "bloody";
const string tag_blood = "blood";
const string tag_armor = "armor";
const string ruinedName = "Tattered Rags";

extern vector<ArmorType *> armortype;
#endif	//ARMOR_CPP
#ifdef	ARMORTYPE_CPP
// armortype.cpp
#include "../creature/creatureEnums.h"
//#include "../items/item.h"
#include "../items/itemtype.h"
//#include "../items/armor.h"
#include "../items/armortype.h"
//own header
#include "../common/stringconversion.h"
//for stringtobool

const string CONST_armortypeB044 = ": ";

const string CONST_armortype055 = "UNDEF";
const string CONST_armortype054 = "Unknown element for armor type ";
const string CONST_armortype053 = "::InterrogationST: ";
const string CONST_armortype051 = "::armor: ";
const string CONST_armortype049 = "::body_covering::conceal_face: ";
const string CONST_armortype048 = "Invalid boolean value for armor type ";
const string CONST_armortype047 = "::body_covering::legs: ";
const string CONST_armortype045 = "::body_covering::arms: ";
const string CONST_armortype043 = "::body_covering::head: ";
const string CONST_armortype041 = "::body_covering::body: ";
const string CONST_armortype037 = "::armor::fireprotection: ";
const string CONST_armortype035 = "::deathsquad_legality: ";

const string tag_durability = "durability";
const string tag_qualitylevels = "qualitylevels";
const string tag_quality = "quality";
const string tag_description = "description";
const string tag_surprise = "surprise";
const string tag_mask = "mask";
const string tag_stealth = "stealth";
const string tag_stealth_value = "stealth_value";
const string tag_conceal_weapon_size = "conceal_weapon_size";
const string tag_professionalism = "professionalism";
const string tag_drugbonus = "drugbonus";
const string tag_assaultbonus = "assaultbonus";
const string tag_basepower = "basepower";
const string tag_base = "base";
const string tag_interrogation = "interrogation";
const string tag_shortname = "shortname";
const string tag_conceals_face = "conceals_face";
const string tag_legs = "legs";
const string tag_arms = "arms";
const string tag_head = "head";
const string tag_body = "body";
const string tag_body_covering = "body_covering";
const string tag_fire = "fire";
const string tag_fireprotection = "fireprotection";
const string tag_limbs = "limbs";
const string tag_armor = "armor";
const string tag_can_get_damaged = "can_get_damaged";
const string tag_can_get_bloody = "can_get_bloody";
const string tag_deathsquad_legality = "deathsquad_legality";
const string tag_make_price = "make_price";
const string tag_make_difficulty = "make_difficulty";

map<string, int> armorTypeInitTags = {
	map<string, int>::value_type(tag_make_difficulty, ENUM_tag_make_difficulty),
	map<string, int>::value_type(tag_make_price, ENUM_tag_make_price),
	map<string, int>::value_type(tag_deathsquad_legality, ENUM_tag_deathsquad_legality),
	map<string, int>::value_type(tag_can_get_bloody, ENUM_tag_can_get_bloody),
	map<string, int>::value_type(tag_can_get_damaged, ENUM_tag_can_get_damaged),
	map<string, int>::value_type(tag_armor, ENUM_tag_armor),
	map<string, int>::value_type(tag_body_covering, ENUM_tag_body_covering),
	map<string, int>::value_type(tag_shortname, ENUM_tag_shortname),
	map<string, int>::value_type(tag_interrogation, ENUM_tag_interrogation),
	map<string, int>::value_type(tag_professionalism, ENUM_tag_professionalism),
	map<string, int>::value_type(tag_conceal_weapon_size, ENUM_tag_conceal_weapon_size),
	map<string, int>::value_type(tag_stealth_value, ENUM_tag_stealth_value),
	map<string, int>::value_type(tag_mask, ENUM_tag_mask),
	map<string, int>::value_type(tag_surprise, ENUM_tag_surprise),
	map<string, int>::value_type(tag_description, ENUM_tag_description),
	map<string, int>::value_type(tag_qualitylevels, ENUM_tag_qualitylevels),
	map<string, int>::value_type(tag_durability, ENUM_tag_durability),
};
extern int year;
#endif	//ARMORTYPE_CPP
#ifdef	AUGMENTATION_CPP
// augmentation.cpp
#include "augmentation.h"

const string CONST_augmentation017 = "Conservative Swine! (Bug)";
const string CONST_augmentation016 = "Skin";
const string CONST_augmentation015 = "Legs";
const string CONST_augmentation014 = "Arms";
const string CONST_augmentation013 = "Body";
const string CONST_augmentation012 = "Head";
const string tag_skin = "skin";
const string tag_effect = "effect";
const string tag_type = "type";
const string tag_name = "name";
const string tag_augmentation = "augmentation";

const string tag_value = "value";
const string tag_attribute = "attribute";

const string tag_legs = "legs";
const string tag_arms = "arms";
const string tag_body = "body";
const string tag_head = "head";

#endif	//AUGMENTATION_CPP
#ifdef	AUGMENTTYPE_CPP
// augmenttype.cpp

#include "augmentation.h"
#include "augmenttype.h"
//own header
#include "../log/log.h"
// for log
#include "../common/stringconversion.h"

const string CONST_augmenttypeB014 = " lacks idname.";
const string CONST_augmenttype013 = "Augment type ";
const string CONST_augmenttype012 = "LACKS IDNAME ";

const string tag_difficulty = "difficulty";
const string tag_cost = "cost";
const string tag_min_age = "min_age";
const string tag_max_age = "max_age";
const string tag_description = "description";
const string tag_effect = "effect";
const string tag_attribute = "attribute";
const string tag_type = "type";
const string tag_name = "name";
const string tag_idname = "idname";
const string tag_id = "id";


map<string, int> augmentTags = {
	map<string, int>::value_type(tag_name, ENUM_tag_name),
	map<string, int>::value_type(tag_type, ENUM_tag_type),
	map<string, int>::value_type(tag_attribute, ENUM_tag_attribute),
	map<string, int>::value_type(tag_effect, ENUM_tag_effect),
	map<string, int>::value_type(tag_description, ENUM_tag_description),
	map<string, int>::value_type(tag_max_age, ENUM_tag_max_age),
	map<string, int>::value_type(tag_min_age, ENUM_tag_min_age),
	map<string, int>::value_type(tag_cost, ENUM_tag_cost),
	map<string, int>::value_type(tag_difficulty, ENUM_tag_difficulty),
};
extern Log xmllog;
#endif	//AUGMENTTYPE_CPP
#ifdef	AUTOMATEDDATATESTS_CPP
// automatedDataTests.cpp
#include "cursesAlternative.h"

//string_to_activity;
extern map<short, string>  conservativeLegalArgument;
//string_to_law;
extern map<short, string>  youAreStupidTalkAboutIssues;
//string_to_law;
extern map<short, string>  issueTooLiberal;
//string_to_law;
extern map<short, string>  issueEventString;
//string_to_view; [LCSrandom(VIEWNUM - 3)]
extern map<short, string>  conservatiseLaw;
//string_to_law;
extern map<short, string>  liberalizeLaw;
//string_to_law;
extern map<short, string>  discussIssues;
//string_to_view; LCSrandom(VIEWNUM);
extern map<short, string>  discussesIssues;
//string_to_view; LCSrandom(VIEWNUM);
extern map<short, vector<string> >  talkAboutTheIssues; // 0~1
//string_to_law;
extern map<short, vector<string> >  endgameLawStrings; // 0~7
//string_to_law;
void testCreature();

const string CONST_automatedDataTests013 = "TEST";
const string CONST_automatedDataTests008 = "SUCCESS";

extern bool multipleCityMode;
extern short lawList[LAWNUM];
#endif	//AUTOMATEDDATATESTS_CPP
#ifdef	BASEACTIONS_CPP
// baseactions.cpp


#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
//#include "../cursesgraphics.h"

#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
//#include "../common/getnames.h"
void enter_name(int, int, char*, int, const char*);
#include "../common/commondisplay.h"
// for void printparty(void)
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/creaturePool.h"
//extern string singleSpace;
//string enter_done;
//extern string spaceDashSpace;
// string chooseALiberalTo;
// string string_sleeper;

int getkey_cap_alt();
extern Deprecatedsquadst *activesquad;
int lenVehiclePool();
int getCarID(const int l);
string getCarFullname(const int l);
extern char slogan[SLOGAN_LEN];
extern string slogan_str;
extern vector<string> default_slogans;
extern short party_status;
extern Deprecatedsquadst *activesquad;
extern Deprecatedsquadst *activesquad;

const string CONST_baseactions004 = "vehicleParagraph.txt";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
const string mostlyendings = "mostlyendings\\";
const string CONST_baseactions012 = "be a passenger.";
const string CONST_baseactions011 = "drive it.";
const string CONST_baseactions010 = "Choosing the Right Liberal Vehicle";
// orderparty
const string CONST_baseactions009 = " in Spot ";
const string CONST_baseactions008 = "Choose squad member to replace ";
const string CONST_baseactions007 = "Choose squad member to move";
// getslogan
const string CONST_baseactions006 = "                                                                                          ";
const string CONST_baseactions005 = "What is your new slogan?";

#endif	//BASEACTIONS_CPP
#ifdef	BASEMODE_CPP
// basemode.cpp
#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
//#include "../pdcurses/curses.h"
#include "../cursesgraphics.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
//#include "../basemode/liberalagenda.h"
bool liberalagenda(signed char won);
#include "../basemode/baseactions.h"
//#include "../basemode/activate_sleepers.h"
void activate_sleepers();
//#include "../basemode/activate.h"
void activate();
//#include "../basemode/reviewmode.h"
void review();
#include "../common/translateid.h"
// for  int getsquad(int)
#include "../common/getnames.h"
// for std::string getmonth(int)
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
//for int mvaddstr(int, int, const char*)
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
//#include "../common/equipment.h"
void equip(vector<Item *> &loot, int loc);
//#include "../politics/politics.h"
bool stalinview(short view, bool islaw);
//#include "../monthly/monthly.h"
void passmonth(char &clearformess, char canseethings);
#include "../daily/daily.h"
//for int monthday();
#include "../daily/siege.h"
//for giveup()
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../common/musicClass.h"
#include "../common/creaturePool.h"
#include "../locations/locationsPool.h"
//extern string commaSpace;
//extern string singleSpace;
//string change_squad_order;
enum CantSeeReason
{
	CANTSEE_DATING = 1,
	CANTSEE_HIDING = 2,
	CANTSEE_OTHER = 3,
	CANTSEE_DISBANDING = 4
};
//string show_squad_liberal_status;

const string CONST_basemode062 = "P - PATRIOTISM: fly a flag here ($20)";
const string CONST_basemode061 = "P - PROTEST: burn the flag";
const string CONST_basemode060 = "S - FREE SPEECH: the Liberal Slogan";
const string CONST_basemode059 = " (next month)";
const string CONST_basemode058 = "W - Wait a day";
const string CONST_basemode057 = "W - Wait out the siege";
const string CONST_basemode056 = "Cannot Wait until Siege Resolved";
const string CONST_basemode055 = "X - Live to fight EVIL another day";
const string CONST_basemode054 = "F - Go forth to stop EVIL";
const string CONST_basemode053 = "G - Give Up";
const string CONST_basemode052 = "F - Escape/Engage";
const string CONST_basemode051 = "C - Cancel this Squad's Departure";
const string CONST_basemode050 = "B - Sleepers";
const string CONST_basemode049 = "A - Activate Liberals";
const string CONST_basemode048 = "L - The Status of the Liberal Agenda";
const string CONST_basemode047 = "Z - Next Location";
const string CONST_basemode046 = "TAB - Next Squad";
const string CONST_basemode045 = "O - Reorder";
const string CONST_basemode044 = "R - Review Assets and Form Squads";
const string CONST_basemode043 = "V - Vehicles";
const string CONST_basemode042 = "E - Equip Squad";
const string CONST_basemode041 = "컴� PLANNING 컴�";
const string CONST_basemode040 = "컴� ACTIVISM 컴�";
const string CONST_basemode039 = ":::::::::";
const string CONST_basemode038 = ":.:.:.:.:";
const string CONST_basemode037 = " (No Food)";
const string CONST_basemode036 = "Under Siege";
const string CONST_basemode035 = "Under Attack";
const string CONST_basemode034 = "I - Invest in this location";

const string tag_Sta = "Sta, ";
const string tag_Libp = "Lib+, ";
const string tag_Lib = "Lib, ";
const string tag_Mod = "Mod, ";
const string tag_Cons = "Cons, ";
const string tag_Consp = "Cons+";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
const string CONST_basemode015 = "House: ";
const string CONST_basemode016 = "Senate: ";
const string CONST_basemode017 = "Supreme Court: ";
const string CONST_basemode029 = "컴컴컴컴컴컴컴컴";
const string CONST_basemode024 = "Public Mood";
const string CONST_basemode020 = "Libertarian";
const string CONST_basemode019 = "Stalinist";
//const string CONST_basemode029 = "컴컴컴컴컴컴컴컴";
const string CONST_basemode026 = "Conservative";
const string CONST_basemode025 = "Liberal";
//const string CONST_basemode024 = "Public Mood";
const string CONST_basemode014 = ", 2nd Term";
const string CONST_basemode013 = ", 1st Term";
const string CONST_basemode012 = "President: ";
const string CONST_basemode030 = "R - Recreate the Liberal Crime Squad                  Any Other Key - Next Month";
//printIfLongWait
const string CONST_basemode033 = "It sure has been a while.  Things might have changed a bit.";
const string CONST_basemode032 = "It has been a long time.  A lot must have changed...";
const string CONST_basemode031 = "How long since you've heard these sounds...  times have changed.";
	//pressedKeyWInBaseMode
const string CONST_basemode063 = "Time passes...";

extern bool stalinmode;
extern short house[HOUSENUM];
extern bool stalinmode;
extern short exec[EXECNUM];
extern short senate[SENATENUM];
extern bool stalinmode;
extern short court[COURTNUM];
extern short attitude[VIEWNUM];
extern bool stalinmode;
extern short attitude[VIEWNUM];
void addStringYear();
extern int month;
extern vector<DeprecatedCreature *> pool;
extern int disbandtime;
extern int year;
extern short execterm;

extern short exec[EXECNUM];
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern MusicClass music;
extern int month;
extern MusicClass music;
extern Log gamelog;

extern int selectedsiege;
extern Deprecatedsquadst *activesquad;
extern string slogan_str;
extern vector<DeprecatedCreature *> pool;
extern Log gamelog;
extern class Ledger ledger;
extern int day;

int lenVehiclePool();
void printFlag();


extern int selectedsiege;
extern Deprecatedsquadst *activesquad;
extern vector<Deprecatedsquadst *> squad;
extern vector<DeprecatedCreature *> pool;
extern char disbanding;
extern Deprecatedsquadst *activesquad;
extern int selectedsiege;
extern short party_status;
extern vector<Deprecatedsquadst *> squad;
bool isPartOfJusticeSystem(int cursite);
extern char cantseereason;
extern vector<DeprecatedCreature *> pool;
extern short lawList[LAWNUM];
extern Deprecatedsquadst *activesquad;
extern int selectedsiege;
void burnFlagAtLocation(int l);
int countSafeHouses();
Location* getLocation();
void equipLoot(int l, int loc);
bool isThisSafehouse(int loc);
extern vector<DeprecatedCreature *> pool;
extern int day;
extern int month;
extern int year;
extern Log gamelog;
extern class Ledger ledger;
extern int stat_buys;
extern int stat_burns;
int lenVehiclePool();
extern char cantseereason;
extern char disbanding;
extern Deprecatedsquadst *activesquad;
extern Log gamelog;
extern MusicClass music;
extern int selectedsiege;
extern short party_status;
extern string slogan_str;
extern vector<Deprecatedsquadst *> squad;
extern int month;
#endif	//BASEMODE_CPP
#ifdef	CHASE_CPP
// chase.cpp

#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
//#include "basemode/baseactions.h"
void orderparty();
//#include "sitemode/advance.h"
void creatureadvance();
#include "../sitemode/sitedisplay.h"
//#include "sitemode/miscactions.h"
void reloadparty(bool wasteful = false);
#include "../log/log.h"
// for gamelog
#include "../common/translateid.h"
// for  int id_getcar(int)
#include "../common/commondisplay.h"
// for addstr (with log)
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
//#include "common/equipment.h"
void equip(vector<Item *> &loot, int loc);
#include "fight.h"
#include "fightCreature.h"  
// for void youattack();
#include "haulkidnapCreature.h"
// for  void kidnaptransfer(Creature &cr);
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
#include "../common/creaturePool.h"
//extern string change_squad_order;
//extern string check_status_of_squad_liberal;
//extern string show_squad_liberal_status;
//extern string singleSpace;
//extern string singleDot;
enum LOOP_CONTINUATION {
	RETURN_ZERO,
	RETURN_ONE,
	REPEAT
};
vector<NameAndAlignment> getEncounterNameAndAlignment();
void makecreature(const int x, const short type);
//const string enter_done = "Enter - Done";
const string hereTheyCome = "Here they come!";
const string beingFollowedBySwine = "being followed by Conservative swine!";
const string lostThem = "It looks like you've lost them!";
const string isSeized = " is seized, ";

const string CONST_chase015 = "carchase_obstacle_child.txt";
const string CONST_chase014 = "carchase_obstacle_cross_traffic.txt";
const string CONST_chase013 = "carchase_obstacle_truck_pulls_out.txt";
const string CONST_chase012 = "carchase_obstacle_fruit_stand.txt";
const string CONST_chase011 = "carchase_obstacle_none.txt";
const string CONST_chase010 = "die_in_car.txt";
const string CONST_chase009 = "car_crash_fatalities.txt";
const string CONST_chase008 = "car_crash_modes.txt";
const string CONST_chase007 = "car_plows_through.txt";
const string CONST_chase006 = "car_speed.txt";

const string CONST_chase048 = " is still on your tail!";
const string CONST_chase079 = "C - Reflect on your lack of skill.";
const string CONST_chase076 = "F - Fight!";
const string CONST_chase075 = "E - Equip";
const string CONST_chase074 = "D - Try to lose them!";

const string tag_POLICECAR = "POLICECAR";
const string tag_The = "The ";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
const string mostlyendings = "mostlyendings\\";
const string chase = "chase\\";
const string CONST_chase020 = " is free.";
const string CONST_chase019 = "s are free.";
const string CONST_chase018 = "Your hostage";
const string CONST_chase017 = "You pull over and are arrested.";
const string CONST_chase016 = "You stop and are arrested.";
const string CONST_chase024 = "You scale a small building and leap between rooftops!";
const string CONST_chase023 = "You climb a fence in record time!";
const string CONST_chase022 = "You run as fast as you can!";
const string CONST_chase021 = "You suddenly dart into an alley!";
const string CONST_chase031 = "thrown to the ground, and tazed repeatedly!";
const string CONST_chase030 = "thrown to the ground, and tazed to death!";
const string CONST_chase029 = "pushed to the ground, and handcuffed!";
const string CONST_chase032 = "thrown to the ground, and shot in the head!";
const string CONST_chase033 = " crushed beneath the tank's treads!";
const string CONST_chase035 = "thrown to the ground, and beaten senseless!";
const string CONST_chase034 = "thrown to the ground, and beaten to death!";
const string CONST_chase028 = " breaks away!";
const string CONST_chase026 = " can't keep up!";
const string CONST_chase025 = " tips into a pool. The tank is trapped!";
const string CONST_chase040 = "G - Give Up";
const string CONST_chase036 = "As you exit the site, you notice that you are ";
const string CONST_chase047 = " brakes hard and nearly crashes!";
const string CONST_chase046 = " backs off for safety.";
const string CONST_chase045 = " skids out!";
const string CONST_chase044 = " falls behind!";
const string CONST_chase043 = "You make obscene gestures at the pursuers!";
const string CONST_chase042 = "You boldly weave through oncoming traffic!";
const string CONST_chase058 = " crawls free of the car, shivering with pain.";
const string CONST_chase057 = " gasps in pain, but lives, for now.";
const string CONST_chase056 = " feet.";
const string CONST_chase055 = " wheelchair.";
const string CONST_chase054 = " and struggles to ";
const string CONST_chase053 = "car frame";
const string CONST_chase052 = " grips the ";
const string CONST_chase051 = " seat, out cold, and dies.";
const string CONST_chase050 = " slumps in ";
const string CONST_chase049 = "Your ";
const string CONST_chase064 = " takes over the wheel.";
const string CONST_chase065 = "You swerve to avoid the obstacle!";
const string CONST_chase078 = "P - Pull over";
const string CONST_chase077 = "B - Bail out and run!";
const string CONST_chase073 = "As you pull away from the site, you notice that you are ";
const string CONST_chase094 = "STATIONWAGON";
const string CONST_chase093 = "PICKUP";
const string CONST_chase092 = "JEEP";
const string CONST_chase091 = "SUV";
const string CONST_chase090 = "AGENTCAR";
const string CONST_chase088 = "HMMWV";
//crashenemycar

const string CONST_chase063 = " hits a parked car and flips over.";
const string CONST_chase062 = "The person inside is squashed into a cube.";
const string CONST_chase061 = "Everyone inside is peeled off against the pavement.";
const string CONST_chase060 = " spins out and crashes.";
const string CONST_chase059 = " slams into a building.";
// obstacledrive

const string CONST_chase072 = "Both sides refrain from endangering the child...";
const string CONST_chase071 = "The Conservative bastards unleash a hail of gunfire!";
const string CONST_chase070 = "You slow down and carefully avoid the kid.";
const string CONST_chase069 = "The fruit seller is squashed!";
const string CONST_chase068 = "Fruit smashes all over the windshield!";
const string CONST_chase067 = "You slow down, and carefully evade the truck.";
const string CONST_chase066 = "You slow down, and turn the corner.";


void emptyEncounter();

vector<string> car_speed;
vector<string> car_plows_through;
vector<string> car_crash_modes;
vector<string> car_crash_fatalities;
vector<string> die_in_car;
vector<string> carchase_obstacle_none;
vector<string> carchase_obstacle_fruit_stand;
vector<string> carchase_obstacle_truck_pulls_out;
vector<string> carchase_obstacle_cross_traffic;
vector<string> carchase_obstacle_child;
vector<file_and_text_collection> chase_text_file_collection = {
	/*chase.cpp*/
	customText(&car_speed, chase + CONST_chase006),
	customText(&car_plows_through, chase + CONST_chase007),
	customText(&car_crash_modes, chase + CONST_chase008),
	customText(&car_crash_fatalities, chase + CONST_chase009),
	customText(&die_in_car, chase + CONST_chase010),
	customText(&carchase_obstacle_none, mostlyendings + CONST_chase011),
	customText(&carchase_obstacle_fruit_stand, mostlyendings + CONST_chase012),
	customText(&carchase_obstacle_truck_pulls_out, mostlyendings + CONST_chase013),
	customText(&carchase_obstacle_cross_traffic, mostlyendings + CONST_chase014),
	customText(&carchase_obstacle_child, mostlyendings + CONST_chase015),
};
map<short, vector<string> > carchaseObstacles;
//string beingFollowedBySwine;
//string lostThem;
//string hereTheyCome;
//string isSeized;
const int DRIVING_RANDOMNESS = 13;
void deleteVehicles(vector<Vehicle *>& carid);
extern chaseseqst chaseseq;
extern short mode;
extern Deprecatedsquadst *activesquad;
extern Log gamelog;
extern Log gamelog;
extern short lawList[LAWNUM];
extern Deprecatedsquadst *activesquad;
extern Deprecatedsquadst *activesquad;
extern Log gamelog;
extern DeprecatedCreature encounter[ENCMAX];
extern short lawList[LAWNUM];
extern chaseseqst chaseseq;
extern short party_status;
extern chaseseqst chaseseq;
extern Deprecatedsquadst *activesquad;
int encounterSize();
int baddieCount(const bool in_car);
int baddieCount();
extern chaseseqst chaseseq;
extern char foughtthisround;
extern Deprecatedsquadst *activesquad;
extern short party_status;
extern Deprecatednewsstoryst *sitestory;
extern Log gamelog;
extern chaseseqst chaseseq;
extern MusicClass music;
extern short mode;
extern Log gamelog;
extern DeprecatedCreature encounter[ENCMAX];
int driveskill(DeprecatedCreature &cr, int v);
extern chaseseqst chaseseq;
extern Deprecatedsquadst *activesquad;
extern short fieldskillrate;
extern Log gamelog;
extern DeprecatedCreature encounter[ENCMAX];
extern int stat_dead;
extern chaseseqst chaseseq;
extern Deprecatedsquadst *activesquad;
extern Log gamelog;
int getEncounterCarID(const int p);
extern chaseseqst chaseseq;
extern Log gamelog;
extern chaseseqst chaseseq;
extern Deprecatedsquadst *activesquad;
extern Deprecatednewsstoryst *sitestory;
extern Log gamelog;
extern DeprecatedCreature encounter[ENCMAX];
extern chaseseqst chaseseq;
extern Deprecatedsquadst *activesquad;
extern Deprecatednewsstoryst *sitestory;
extern Log gamelog;
extern DeprecatedCreature encounter[ENCMAX];
extern Log gamelog;
extern Log gamelog;
extern chaseseqst chaseseq;
extern short party_status;
extern chaseseqst chaseseq;
extern Deprecatedsquadst *activesquad;

extern short mode;
extern chaseseqst chaseseq;
extern Deprecatedsquadst *activesquad;
extern short party_status;
extern Deprecatednewsstoryst *sitestory;
extern Log gamelog;
extern chaseseqst chaseseq;
extern short party_status;
void addCreatueVehiclesToCollection(DeprecatedCreature *cr[6], vector<Vehicle *> &veh);
extern MusicClass music;
extern short mode;
extern chaseseqst chaseseq;
extern Deprecatedsquadst *activesquad;
extern Log gamelog;
extern short mode;
extern chaseseqst chaseseq;
extern short mode;
extern Deprecatedsquadst *activesquad;
extern DeprecatedCreature encounter[ENCMAX];
void conservatise(const int e);
Vehicle* getVehicleOfThisType(int cartype);
extern char endgamestate;
extern chaseseqst chaseseq;
extern DeprecatedCreature encounter[ENCMAX];
extern short lawList[LAWNUM];
void removeCreatureFromSquad(DeprecatedCreature &cr, int oldsqid);
extern Deprecatedsquadst *activesquad;
extern short party_status;
extern long cursquadid;
extern Deprecatedsquadst *activesquad;
extern short party_status;
extern long cursquadid;
extern Log gamelog;
#endif	//CHASE_CPP
#ifdef	CLIP_CPP
// clip.cpp
#include "../creature/creatureEnums.h"
#include "../items/itemtype.h"
#include "../items/item.h"
#include "../items/cliptype.h"
#include "../items/clip.h"
//own header
#include "../common/translateid.h"
// for  int getcliptype

const string CONST_clipB003 = ": ";
const string CONST_clip002 = "Unknown element for clip type ";

const string tag_ammo = "ammo";
const string tag_clip = "clip";

extern vector<ClipType *> cliptype;
#endif	//CLIP_CPP
#ifdef	COMMONACTIONS_CPP
// commonactions.cpp

#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"

//#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locationsEnums.h"
//#include "../pdcurses/curses.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../common/translateid.h"
// for  int getsquad(int)
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
// for makedelimeter
#include "../title/highscore.h"       
//for void savehighscore(char endtype)
#include "../politics/politics.h"
//for int publicmood(int l)
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/creaturePool.h"
/* end the game and clean up */
void end_game(int err = EXIT_SUCCESS);
//extern string singleSpace;
//extern string spaceDashSpace;
//extern string singleDot;

const string enterDash = "Enter - ";
const string selectA = "Press a Letter to select a ";
const string selectAn = "Press a Letter to select an ";

const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
const string CONST_commonactions008 = "harmful speech";
const string CONST_commonactions007 = "month";
const string CONST_commonactions006 = "months";
const string CONST_commonactions005 = " for ";
const string CONST_commonactions004 = " will be at ";
const string mostlyendings = "mostlyendings\\";
const string CONST_commonactions009 = "methodOfSorting.txt";
const string CONST_commonactions010 = "Choose how to sort list of ";
const string CONST_commonactions012 = "$";

short getCurrentSite();
extern short mode;
extern Deprecatedsquadst *activesquad;
extern vector<Deprecatedsquadst *> squad;
extern short activesortingchoice[SORTINGCHOICENUM];
extern class Ledger ledger;
extern Log gamelog;
#endif	//COMMONACTIONS_CPP
#ifdef	COMMONDISPLAY_CPP
// commondisplay.cpp
#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locationsEnums.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../sitemode/stealth.h"
#include "../common/getnames.h"
std::string gettitle(const int align, const int juice);
bool isThereNoActivesquad();
// for getmonth
#include "../common/translateid.h"
// for  int getcar(int)
#include "../common/commonactionsCreature.h"
// for void sortliberals(std::vector<Creature *>&,short,bool)
#include "../daily/siege.h"
// for statebrokenlaws(cr);
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
//extern string commaSpace;
//extern string singleSpace;
//extern string closeParenthesis;

bool isThereASiteAlarm();
void makedelimiter(int y = 8, int x = 0);


const string CONST_commondisplay000 = ",";
const string CONST_commondisplay202 = " (";
const string CONST_commondisplay201 = "Name: ";
const string CONST_commondisplay200 = "Code name: ";
const string CONST_commondisplay212 = ": ";
const string CONST_commondisplay199 = ".00";
const string CONST_commondisplay198 = "99+";
const string CONST_commondisplay197 = "00";
const string CONST_commondisplay196 = ".";
const string CONST_commondisplay194 = "NOW   MAX";
const string CONST_commondisplay193 = "SKILL";
const string CONST_commondisplay003 = "On \"Foot\"";
const string CONST_commondisplay158 = "On Foot";
const string CONST_commondisplay157 = "Wheelchair";
const string CONST_commondisplay156 = "-D";
const string CONST_commondisplay220 = "                                                                                ";
const string CONST_commondisplay153 = "Weapon: ";
const string CONST_commondisplay119 = "Cut";
const string CONST_commondisplay118 = "Bruised";
const string CONST_commondisplay117 = "Shot";
const string CONST_commondisplay116 = "Liberal";
const string CONST_commondisplay115 = "Animal";
const string CONST_commondisplay114 = "Severed";
const string CONST_commondisplay113 = "Ripped off";
const string CONST_commondisplay112 = "Left Leg:";
const string CONST_commondisplay111 = "Right Leg:";
const string CONST_commondisplay110 = "Left Arm:";
const string CONST_commondisplay109 = "Right Arm:";
const string CONST_commondisplay108 = "Body:";
const string CONST_commondisplay107 = "Head:";
const string CONST_commondisplay154 = "Clothes: ";
const string CONST_commondisplay180 = "Missing Teeth";
const string CONST_commondisplay178 = "No Teeth";
const string CONST_commondisplay177 = "No Tongue";



const string tag_0 = "0";
const string CONST_commondisplay005 = "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴";
const string CONST_commondisplay004 = "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컫컴컴컴컴컴컴컴컴컴컴컴컴컫";
const string CONST_commondisplay044 = "Moderate";
const string CONST_commondisplay043 = "Conservative";
const string CONST_commondisplay042 = "Consrvtv";
const string CONST_commondisplay013 = "Lightly Wounded";
const string CONST_commondisplay012 = "LtWound";
const string CONST_commondisplay011 = "Wounded";
const string CONST_commondisplay010 = "Badly Wounded";
const string CONST_commondisplay009 = "BadWound";
const string CONST_commondisplay008 = "Near Death";
const string CONST_commondisplay007 = "NearDETH";
const string CONST_commondisplay006 = "Deceased";
const string CONST_commondisplay029 = "One Leg";
const string CONST_commondisplay028 = "One Arm";
const string CONST_commondisplay027 = "One Arm, One Leg";
const string CONST_commondisplay026 = "1Arm1Leg";
const string CONST_commondisplay025 = "No Legs";
const string CONST_commondisplay024 = "No Arms";
const string CONST_commondisplay023 = "One Limb";
const string CONST_commondisplay022 = "No Limbs";
const string CONST_commondisplay036 = "Missing Eye";
const string CONST_commondisplay035 = "One Eye";
const string CONST_commondisplay034 = "Missing Nose";
const string CONST_commondisplay033 = "NoseGone";
const string CONST_commondisplay032 = "Face Mutilated";
const string CONST_commondisplay031 = "FaceMutl";
const string CONST_commondisplay030 = "Blind";

const string CONST_commondisplay040 = "MisTeeth";
const string CONST_commondisplay037 = "NoTongue";
const string CONST_commondisplay021 = "Face Gone";
const string CONST_commondisplay020 = "FaceGone";
const string CONST_commondisplay019 = "Paraplegic";
const string CONST_commondisplay018 = "Parapleg";
const string CONST_commondisplay017 = "Quadraplegic";
const string CONST_commondisplay016 = "Quadpleg";
const string CONST_commondisplay015 = "Neck Broken";
const string CONST_commondisplay014 = "NckBroke";
const string CONST_commondisplay067 = "?";
const string CONST_commondisplay066 = "Char:   ";
const string CONST_commondisplay064 = "Str:    ";
const string CONST_commondisplay062 = "Agi:    ";
const string CONST_commondisplay060 = "Hlth:   ";
const string CONST_commondisplay058 = "Wis:    ";
const string CONST_commondisplay056 = "Int:    ";
const string CONST_commondisplay054 = "Hrt:    ";
const string CONST_commondisplay053 = "an angry Hangin' Judge";
const string CONST_commondisplay052 = "a frightened Eminent Scientist";
const string CONST_commondisplay051 = "a smarmy News Anchor";
const string CONST_commondisplay050 = "a crying Radio Personality";
const string CONST_commondisplay049 = "a squirming CEO";
const string CONST_commondisplay048 = "a cursing Politician";
const string CONST_commondisplay092 = "Brn";
const string CONST_commondisplay091 = "Trn";
const string CONST_commondisplay089 = "Brs";
const string CONST_commondisplay088 = "Sht";
const string CONST_commondisplay085 = "Clean sever";
const string CONST_commondisplay077 = "Top Skills:";
const string CONST_commondisplay075 = "???????";

const string CONST_commondisplay068 = "Trans: ";

const string CONST_commondisplay047 = ", holding ";
const string CONST_commondisplay101 = " (1)";
const string CONST_commondisplay100 = " (XX)";
const string CONST_commondisplay097 = "/";
const string CONST_commondisplay096 = "+H";
const string CONST_commondisplay094 = "#횮ODE NAME컴컴컴컴컴컴SKILL컴훇EAPON컴컴컴컴횫RMOR컴컴컴컴컴HEALTH컴훂RANSPORT�";
const string CONST_commondisplay121 = "Burned";
const string CONST_commondisplay120 = "Torn";
const string CONST_commondisplay167 = "Scheduled Dates:    ";
const string CONST_commondisplay166 = "s";
const string CONST_commondisplay165 = " Romantic Interest";
const string CONST_commondisplay164 = "Scheduled Meetings: ";
const string CONST_commondisplay163 = "Can't Recruit";
const string CONST_commondisplay162 = "Enlightened ";
const string CONST_commondisplay161 = " Max";
const string CONST_commondisplay160 = " Recruits / ";
const string CONST_commondisplay155 = "Car: ";
const string CONST_commondisplay131 = "Juice: ";
const string CONST_commondisplay130 = "*";
const string CONST_commondisplay129 = ", Genderqueer";
const string CONST_commondisplay128 = ", Female";
const string CONST_commondisplay127 = ", Male";
const string CONST_commondisplay126 = " (Age ";
const string CONST_commondisplay125 = "Born ";
//juiceuntillevelup


const string CONST_commondisplay138 = "1000";
const string CONST_commondisplay137 = "500";
const string CONST_commondisplay136 = "200";
const string CONST_commondisplay135 = "100";
const string CONST_commondisplay134 = "50";
const string CONST_commondisplay133 = "10";
const string CONST_commondisplay132 = "Next:  ";
//printcreatureattributes


const string CONST_commondisplay145 = "Charisma: ";
const string CONST_commondisplay144 = "Strength: ";
const string CONST_commondisplay143 = "Agility: ";
const string CONST_commondisplay142 = "Health: ";
const string CONST_commondisplay141 = "Wisdom: ";
const string CONST_commondisplay140 = "Intelligence: ";
const string CONST_commondisplay139 = "Heart: ";
//printliberalcrimes

const string CONST_commondisplay211 = "NUM";
const string CONST_commondisplay210 = "CRIME";
const string CONST_commondisplay209 = " months in prison.";
const string CONST_commondisplay208 = "Sentenced to ";
const string CONST_commondisplay207 = "Serving ";
const string CONST_commondisplay206 = "Sentenced to life in prison";
const string CONST_commondisplay205 = "Serving life in prison";
const string CONST_commondisplay204 = "Sentenced to DEATH";
const string CONST_commondisplay203 = "On DEATH ROW";
//fullstatus

const string CONST_commondisplay219 = "What is the new code name?                                                      ";
const string CONST_commondisplay218 = "    UP/DOWN  - More Info";
const string CONST_commondisplay217 = "Press any other key to continue the Struggle";
const string CONST_commondisplay216 = "    LEFT/RIGHT - Other Liberals";
const string CONST_commondisplay215 = "N - Change Code Name      G - Fix Gender Label";
const string CONST_commondisplay214 = "Profile of a Liberal";

map<int, map<bool, ColorSetup> > alignmentColors = {
	// Liberal activism
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_ARCHCONSERVATIVE,{ map<bool, ColorSetup>::value_type(true, RED_ON_BLACK_BRIGHT) }),
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_CONSERVATIVE,{ map<bool, ColorSetup>::value_type(true, MAGENTA_ON_BLACK_BRIGHT), map<bool, ColorSetup>::value_type(false, RED_ON_BLACK_BRIGHT) }),
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_MODERATE,{ map<bool, ColorSetup>::value_type(true, YELLOW_ON_BLACK_BRIGHT) }),
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_LIBERAL,{ map<bool, ColorSetup>::value_type(true, CYAN_ON_BLACK_BRIGHT), map<bool, ColorSetup>::value_type(false, GREEN_ON_BLACK_BRIGHT) }),
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_ELITELIBERAL,{ map<bool, ColorSetup>::value_type(true, GREEN_ON_BLACK_BRIGHT) }),
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_STALINIST,{ map<bool, ColorSetup>::value_type(true, RED_ON_BLACK_BRIGHT) }),
};
map<int, ColorSetup> activityColors = {
	// Liberal activism
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_LIBERAL, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_TROUBLE, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_GRAFFITI, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_DOS_ATTACKS, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_HACKING, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_WRITE_LETTERS, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_WRITE_GUARDIAN, GREEN_ON_BLACK_BRIGHT),
	// Recruitment
	map<int, ColorSetup>::value_type(ACTIVITY_RECRUITING, GREEN_ON_BLACK),
	// Less exciting liberal activities
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_SPY, BLUE_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_COMMUNITYSERVICE, BLUE_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_POLLS, BLUE_ON_BLACK_BRIGHT),
	// Stealing things
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_STEAL, CYAN_ON_BLACK),
	map<int, ColorSetup>::value_type(ACTIVITY_WHEELCHAIR, CYAN_ON_BLACK),
	map<int, ColorSetup>::value_type(ACTIVITY_STEALCARS, CYAN_ON_BLACK),
	// Illegal fundraising
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_EMBEZZLE, RED_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_SELL_DRUGS, RED_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_PROSTITUTION, RED_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_CCFRAUD, RED_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_DOS_RACKET, RED_ON_BLACK_BRIGHT),
	// Legal fundraising
	map<int, ColorSetup>::value_type(ACTIVITY_DONATIONS, CYAN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_SELL_TSHIRTS, CYAN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_SELL_ART, CYAN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_SELL_MUSIC, CYAN_ON_BLACK_BRIGHT),
	// Clothing/garment stuff
	map<int, ColorSetup>::value_type(ACTIVITY_REPAIR_ARMOR, CYAN_ON_BLACK),
	map<int, ColorSetup>::value_type(ACTIVITY_MAKE_ARMOR, CYAN_ON_BLACK),
	// Teaching
	map<int, ColorSetup>::value_type(ACTIVITY_TEACH_POLITICS, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_TEACH_FIGHTING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_TEACH_COVERT, MAGENTA_ON_BLACK_BRIGHT),
	//and studying
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_DEBATING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_MARTIAL_ARTS, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_DRIVING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_PSYCHOLOGY, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_FIRST_AID, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_LAW, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_DISGUISE, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_SCIENCE, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_BUSINESS, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_GYMNASTICS, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_ART, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_MUSIC, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_TEACHING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_WRITING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_LOCKSMITHING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_COMPUTERS, MAGENTA_ON_BLACK_BRIGHT),
	//map<int, ColorSetup>::value_type(ACTIVITY_STUDY_COOKING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_FENCING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_WEAVING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_RELIGION, MAGENTA_ON_BLACK_BRIGHT),
	//map<int, ColorSetup>::value_type(ACTIVITY_STUDY_MAGIC, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_CLUB, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_STREETSENSE, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_THROWING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_STEALTH, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_SEDUCTION, MAGENTA_ON_BLACK_BRIGHT),
	// Interrogating
	map<int, ColorSetup>::value_type(ACTIVITY_HOSTAGETENDING, YELLOW_ON_BLACK_BRIGHT),
	// Dealing with your injuries
	map<int, ColorSetup>::value_type(ACTIVITY_CLINIC, RED_ON_BLACK),
	// Doing something Conservative
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_CONSERVATIVE, RED_ON_BLACK_BRIGHT),
	// Dealing with the dead
	map<int, ColorSetup>::value_type(ACTIVITY_BURY, BLACK_ON_BLACK_BRIGHT),
	// Nothing terribly important
	map<int, ColorSetup>::value_type(ACTIVITY_HEAL, WHITE_ON_BLACK),// Identical to none in practice
	map<int, ColorSetup>::value_type(ACTIVITY_NONE, WHITE_ON_BLACK),
	// Going somewhere
	map<int, ColorSetup>::value_type(ACTIVITY_VISIT, YELLOW_ON_BLACK_BRIGHT),
	// Quitting being a sleeper to join the LCS
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_JOINLCS, RED_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_AUGMENT, BLUE_ON_BLACK_BRIGHT),
};
extern short mode;
extern bool mapshowing;
/* checks if a creature's weapon is suspicious or illegal */
char weaponcheck(const DeprecatedCreature &cr, bool metaldetect = false);
/* checks if a creature's uniform is appropriate to the location */
char hasdisguise(const DeprecatedCreature &cr);
//void printcreatureinfo(DeprecatedCreature *cr, unsigned char knowledge = 255);
string getVehicleShortname(int i);
map<int, string> prisoner_description = {
	map<int, string>::value_type(CREATURE_POLITICIAN, CONST_commondisplay048),
	map<int, string>::value_type(CREATURE_CORPORATE_CEO, CONST_commondisplay049),
	map<int, string>::value_type(CREATURE_RADIOPERSONALITY, CONST_commondisplay050),
	map<int, string>::value_type(CREATURE_NEWSANCHOR, CONST_commondisplay051),
	map<int, string>::value_type(CREATURE_SCIENTIST_EMINENT, CONST_commondisplay052),
	map<int, string>::value_type(CREATURE_JUDGE_CONSERVATIVE, CONST_commondisplay053),
};
extern short sitealarmtimer;

void set_color_for_armor(const Armor armor);
void setColorForArmor(const Armor ar);
extern short sitealarmtimer;
extern int year;
extern short mode;
extern char showcarprefs;
void printcreatureinfo(DeprecatedCreature *cr, unsigned char knowledge = 255);
extern Deprecatedsquadst *activesquad;
extern short party_status;
extern char showcarprefs;
extern short mode;
extern bool mapshowing;

extern short sitealarmtimer;
vector<string> printSpecialWounds(const char special[SPECIALWOUNDNUM]);
/* full screen character sheet */

void statebrokenlaws(CreatureJustice cr, const int flag);
extern int year;
extern int day;
extern int month;
extern char showcarprefs;
extern Deprecatedsquadst *activesquad;
#endif	//COMMONDISPLAY_CPP
#ifdef	CONFIGFILE_CPP
// configfile.cpp

#include "../items/itemtype.h"
#include "../items/item.h"
// needed for locations
#include "../locations/locations.h"
#include "../configfile.h"
//own header
#include "../cursesAlternative.h"
//extern string singleSpace;
const string attemptingToOpenFile = "Attempting to open filename: ";

const string CONST_configfile008 = "_Specials.csv";
const string CONST_configfile007 = "_Tiles.csv";
const string CONST_configfile006 = "mapCSV_Bank2_Tiles.csv";
const string CONST_configfile003 = "mapCSV_Bank_Tiles.csv";
const string CONST_configfile002 = "mapCSV_";
const string CONST_configfile001 = "OBJECT";

extern char artdir[MAX_PATH_SIZE];
map<int, SpecialBlocks> mapCBSpecial = {
	map<int, SpecialBlocks>::value_type(0,  SPECIAL_NONE),
	map<int, SpecialBlocks>::value_type(1,  SPECIAL_LAB_COSMETICS_CAGEDANIMALS),
	map<int, SpecialBlocks>::value_type(2,  SPECIAL_LAB_GENETIC_CAGEDANIMALS),
	map<int, SpecialBlocks>::value_type(3,  SPECIAL_POLICESTATION_LOCKUP),
	map<int, SpecialBlocks>::value_type(4,  SPECIAL_COURTHOUSE_LOCKUP),
	map<int, SpecialBlocks>::value_type(5,  SPECIAL_COURTHOUSE_JURYROOM),
	map<int, SpecialBlocks>::value_type(6,  SPECIAL_PRISON_CONTROL),
	map<int, SpecialBlocks>::value_type(7,  SPECIAL_PRISON_CONTROL_LOW),
	map<int, SpecialBlocks>::value_type(8,  SPECIAL_PRISON_CONTROL_MEDIUM),
	map<int, SpecialBlocks>::value_type(9,  SPECIAL_PRISON_CONTROL_HIGH),
	map<int, SpecialBlocks>::value_type(10,  SPECIAL_INTEL_SUPERCOMPUTER),
	map<int, SpecialBlocks>::value_type(11,  SPECIAL_SWEATSHOP_EQUIPMENT),
	map<int, SpecialBlocks>::value_type(12,  SPECIAL_POLLUTER_EQUIPMENT),
	map<int, SpecialBlocks>::value_type(13,  SPECIAL_NUCLEAR_ONOFF),
	map<int, SpecialBlocks>::value_type(14,  SPECIAL_HOUSE_PHOTOS),
	map<int, SpecialBlocks>::value_type(15,  SPECIAL_HOUSE_CEO),
	map<int, SpecialBlocks>::value_type(16,  SPECIAL_CORPORATE_FILES),
	map<int, SpecialBlocks>::value_type(17,  SPECIAL_RADIO_BROADCASTSTUDIO),
	map<int, SpecialBlocks>::value_type(18,  SPECIAL_NEWS_BROADCASTSTUDIO),
	map<int, SpecialBlocks>::value_type(19,  SPECIAL_APARTMENT_LANDLORD),
	map<int, SpecialBlocks>::value_type(20,  SPECIAL_SIGN_ONE),
	map<int, SpecialBlocks>::value_type(21,  SPECIAL_RESTAURANT_TABLE),
	map<int, SpecialBlocks>::value_type(22,  SPECIAL_CAFE_COMPUTER),
	map<int, SpecialBlocks>::value_type(23,  SPECIAL_PARK_BENCH),
	map<int, SpecialBlocks>::value_type(24,  SPECIAL_STAIRS_UP),
	map<int, SpecialBlocks>::value_type(25,  SPECIAL_STAIRS_DOWN),
	map<int, SpecialBlocks>::value_type(26,  SPECIAL_CLUB_BOUNCER),
	map<int, SpecialBlocks>::value_type(27,  SPECIAL_CLUB_BOUNCER_SECONDVISIT),
	map<int, SpecialBlocks>::value_type(28,  SPECIAL_ARMORY),
	map<int, SpecialBlocks>::value_type(29,  SPECIAL_DISPLAY_CASE),
	map<int, SpecialBlocks>::value_type(30,  SPECIAL_SIGN_TWO),
	map<int, SpecialBlocks>::value_type(31,  SPECIAL_SIGN_THREE),
	map<int, SpecialBlocks>::value_type(32,  SPECIAL_SECURITY_CHECKPOINT),
	map<int, SpecialBlocks>::value_type(33,  SPECIAL_SECURITY_METALDETECTORS),
	map<int, SpecialBlocks>::value_type(34,  SPECIAL_SECURITY_SECONDVISIT),
	map<int, SpecialBlocks>::value_type(35,  SPECIAL_BANK_VAULT),
	map<int, SpecialBlocks>::value_type(36,  SPECIAL_BANK_TELLER),
	map<int, SpecialBlocks>::value_type(37,  SPECIAL_BANK_MONEY),
	map<int, SpecialBlocks>::value_type(38,  SPECIAL_CCS_BOSS),
	map<int, SpecialBlocks>::value_type(39,  SPECIAL_OVAL_OFFICE_NW),
	map<int, SpecialBlocks>::value_type(40,  SPECIAL_OVAL_OFFICE_NE),
	map<int, SpecialBlocks>::value_type(41,  SPECIAL_OVAL_OFFICE_SW),
	map<int, SpecialBlocks>::value_type(42,  SPECIAL_OVAL_OFFICE_SE),
};
extern siteblockst levelmap[MAPX][MAPY][MAPZ];
#endif	//CONFIGFILE_CPP
#ifdef	CREATURE_CPP
// creature.cpp

#include "../creature/creature.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../sitemode/stealth.h"
// for hasdisguise
//#include "../common/stringconversion.h"
string attribute_enum_to_string(int attribute);
#include "../common/translateid.h"
// for  int getweapontype(int )
//#include "../politics/politics.h"
/* politics -- promotes the Vice President to President, and replaces VP */
void promoteVP();
//only use here. --Schmel924
#include "../combat/chaseCreature.h"
//for Vehicle* getChaseVehicle(const Creature &c);
		//hmm --Schmel924
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include "../set_color_support.h"

const string CONST_creatureD162 = "z";

const string CONST_creatureC161 = "x";

const string CONST_creatureB162 = "/";
const string CONST_creatureB161 = "selves";
const string CONST_creatureB160 = "them";
const string CONST_creatureB159 = "her";
const string CONST_creatureB158 = "themself";
const string CONST_creatureB157 = "hers";
const string CONST_creatureB154 = "heANDshe";
const string CONST_creatureB153 = "xyr";
const string CONST_creatureB066 = "xem";
const string CONST_creature151 = "?";
const string CONST_creature150 = ", Ambiguous";
const string CONST_creature149 = ", Female";
const string CONST_creature148 = ", Male";
const string CONST_creature147 = "Very Old";
const string CONST_creature146 = "80s";
const string CONST_creature145 = "70s";
const string CONST_creature144 = "60s";
const string CONST_creature143 = "50s";
const string CONST_creature142 = "40s";
const string CONST_creature141 = "30s";
const string CONST_creature140 = "20s";
const string CONST_creature138 = " (";
const string CONST_creature137 = " (?)";
const string CONST_creature136 = "None";
const string CONST_creature135 = " (0/";
const string CONST_creature134 = " (1/";
const string CONST_creature132 = "self";
const string CONST_creature131 = "xemself";
const string CONST_creature130 = "Xem";
const string CONST_creature129 = "Her";
const string CONST_creature128 = "Him";
const string CONST_creature127 = "s";
const string CONST_creature126 = "xyrs";
const string CONST_creature125 = "Xyr";
const string CONST_creature123 = "His";
const string CONST_creature122 = "zemself";
const string CONST_creature121 = "zurz";
const string CONST_creature120 = "zem";
const string CONST_creature119 = "zur";
const string CONST_creature118 = "zee";
const string CONST_creature117 = "xe";
const string CONST_creature116 = "Xe";
const string CONST_creature115 = "She";
const string CONST_creature114 = "He";
const string CONST_creature113 = "President ";
const string CONST_creature112 = "CCS Heavy";
const string CONST_creature111 = "Soldier";
const string CONST_creature110 = "Elite Security";
const string CONST_creature109 = "Enlightened Judge";
const string CONST_creature108 = "New Union Worker";
const string CONST_creature107 = "Jaded Liberal Judge";
const string CONST_creature106 = "Ex-Union Worker";
const string CONST_creature105 = ", IMPOSSIBLE";
const string CONST_creature104 = ", Difficulty ";
const string CONST_creature103 = " SkillCheck(";
const string CONST_creature102 = ", Outcome of ";
const string CONST_creature101 = "Adjusted Attribute Value ";
const string CONST_creature100 = "automatic failure";
const string CONST_creature099 = ", Skill Value ";
const string CONST_creature098 = " SkillRoll(";
const string CONST_creature097 = "-=ILLEGAL SKILL ROLL=-";
const string CONST_creature094 = " AttributeCheck(";
const string CONST_creature092 = ", Attribute Level ";
const string CONST_creature091 = " AttributeRoll(";
const string CONST_creature090 = "%f";
const string CONST_creature089 = "Scruffy";
const string CONST_creature087 = "CREATURE_WORKER_JANITOR";
const string CONST_creature086 = "ccs_covername_other.txt";
const string CONST_creature085 = "ccs_covername_shotgun.txt";
const string CONST_creatureX01 = "he";
const string CONST_creatureX02 = "she";
const string CONST_creatureX03 = "his";
const string CONST_creatureX04 = "her";
const string CONST_creatureX05 = "xyr";
const string CONST_creatureX06 = "him";
const string CONST_creatureX07 = "xem";

const string tag_value = "value";
const string tag_ARMOR = "ARMOR";
const string tag_ARMOR_NONE = "ARMOR_NONE";
const string tag_WEAPON = "WEAPON";
const string tag_WEAPON_NONE = "WEAPON_NONE";
const string tag_Pres = "Pres";
const string tag_Pres_state = "Pres_state";
const string tag_Pres_ID = "Pres_ID";
const string tag_CEO = "CEO";
const string tag_CEO_state = "CEO_state";
const string tag_CEO_ID = "CEO_ID";
const string tag_uniquecreatures = "uniquecreatures";
const string tag_WEAPON_SHOTGUN_PUMP = "WEAPON_SHOTGUN_PUMP";
const string tag_ARMOR_HEAVYARMOR = "ARMOR_HEAVYARMOR";
const string tag_ARMOR_ARMYARMOR = "ARMOR_ARMYARMOR";
const string tag_ARMOR_CIVILLIANARMOR = "ARMOR_CIVILLIANARMOR";
const string tag_reports_to_police = "reports_to_police";
const string tag_kidnap_resistant = "kidnap_resistant";
const string tag_talkreceptive = "talkreceptive";
const string tag_seethroughstealth = "seethroughstealth";
const string tag_seethroughdisguise = "seethroughdisguise";
const string tag_dontname = "dontname";
const string tag_flag = "flag";
const string tag_pref_is_driver = "pref_is_driver";
const string tag_pref_carid = "pref_carid";
const string tag_is_driver = "is_driver";
const string tag_carid = "carid";
const string tag_arg = "arg";
const string tag_arg2 = "arg2";
const string tag_type = "type";
const string tag_activity = "activity";
const string tag_base = "base";
const string tag_cantbluff = "cantbluff";
const string tag_worklocation = "worklocation";
const string tag_location = "location";
const string tag_crimes_suspected = "crimes_suspected";
const string tag_special = "special";
const string tag_blood = "blood";
const string tag_wound = "wound";
const string tag_income = "income";
const string tag_juice = "juice";
const string tag_money = "money";
const string tag_has_thrown_weapon = "has_thrown_weapon";
const string tag_stunned = "stunned";
const string tag_forceinc = "forceinc";
const string tag_meetings = "meetings";
const string tag_hireid = "hireid";
const string tag_id = "id";
const string tag_deathdays = "deathdays";
const string tag_joindays = "joindays";
const string tag_deathpenalty = "deathpenalty";
const string tag_confessions = "confessions";
const string tag_sentence = "sentence";
const string tag_prisoner = "prisoner";
const string tag_trainingsubject = "trainingsubject";
const string tag_trainingtime = "trainingtime";
const string tag_hiding = "hiding";
const string tag_dating = "dating";
const string tag_clinic = "clinic";
const string tag_specialattack = "specialattack";
const string tag_animalgloss = "animalgloss";
const string tag_infiltration = "infiltration";
const string tag_type_idname = "type_idname";
const string tag_alive = "alive";
const string tag_align = "align";
const string tag_exists = "exists";
const string tag_birthday_day = "birthday_day";
const string tag_birthday_month = "birthday_month";
const string tag_age = "age";
const string tag_squadid = "squadid";
const string tag_gender = "gender";
const string tag_gender_liberal = "gender_liberal";
const string tag_gender_conservative = "gender_conservative";
const string tag_propername = "propername";
const string tag_name = "name";
const string tag_skill_experience = "skill_experience";
const string tag_skill = "skill";
const string tag_creature = "creature";
const string tag_clip = "clip";
const string tag_augmentation = "augmentation";
const string tag_armor = "armor";
const string tag_weapon = "weapon";
const string tag_attribute = "attribute";
const string tag_ARMOR_CLOTHES = "ARMOR_CLOTHES";
const string creature = "creature\\";

vector<string> ccs_covername_shotgun;
vector<string> ccs_covername_other;
vector<file_and_text_collection> creature_text_file_collection = {
	/*creature.cpp*/
	customText(&ccs_covername_shotgun, creature + CONST_creature085),
	customText(&ccs_covername_other, creature + CONST_creature086),
};
//extern string commaSpace;
extern long curcreatureid;
// Show die rolls, 100% accurate poll numbers
extern bool SHOWMECHANICS;
//	extern string closeParenthesis;
//	extern string closeParenthesis;
	// Show die rolls, 100% accurate poll numbers
extern bool SHOWMECHANICS;
/* checks if a creature's uniform is appropriate to the location */
char hasdisguise(const DeprecatedCreature &cr);
//	extern string closeParenthesis;
extern Log gamelog;
// Show die rolls, 100% accurate poll numbers
extern bool SHOWMECHANICS;
//	extern string closeParenthesis;
	// Show die rolls, 100% accurate poll numbers
extern bool SHOWMECHANICS;
extern UniqueCreatures uniqueCreatures;
// Make age not matter for dating or prostitution
extern bool ZEROMORAL;
extern UniqueCreatures uniqueCreatures;
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern char oldPresidentName[POLITICIAN_NAMELEN];
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern short exec[EXECNUM];
#endif	//CREATURE_CPP
#ifdef	CREATURENAMES_CPP
// creaturenames.cpp

const string CONST_creaturenames008 = "archconservative_last_names.txt";
const string CONST_creaturenames007 = "regular_last_names.txt";
const string CONST_creaturenames006 = "great_white_male_patriarch_first_names.txt";
const string CONST_creaturenames005 = "gender_neutral_first_names.txt";
const string CONST_creaturenames004 = "female_first_names.txt";
const string CONST_creaturenames003 = "male_first_names.txt";
const string names = "names\\";
#endif	//CREATURENAMES_CPP
#ifdef	CREATUREPOOL_CPP
// creaturePool.cpp


const string tag_ARMOR = "ARMOR";
const string tag_ARMOR_PRISONER = "ARMOR_PRISONER";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
const string CONST_creaturePool007 = "The Liberal is now at your command as a normal squad member.";
const string CONST_creaturePool006 = " has been outed by your bold attack!";
const string CONST_creaturePool046 = "This whole thing was a mistake. There won't be another meeting.";
const string CONST_creaturePool045 = " comes off as slightly insane.";
const string CONST_creaturePool044 = " needs more experience.";
const string CONST_creaturePool043 = "Maybe ";
const string CONST_creaturePool042 = " really understands the problem.";
const string CONST_creaturePool041 = " isn't convinced ";
const string CONST_creaturePool040 = "They'll meet again tomorrow.";
const string CONST_creaturePool039 = "'s arguments.";
const string CONST_creaturePool038 = " is skeptical about some of ";
const string CONST_creaturePool037 = "They'll definitely meet again tomorrow.";
const string CONST_creaturePool036 = "'s views to be insightful.";
const string CONST_creaturePool035 = " found ";
const string CONST_creaturePool034 = " views on ";
const string CONST_creaturePool033 = " explains ";
const string CONST_creaturePool032 = " shares ";
const string CONST_creaturePool031 = " accepts, and is eager to get started.";
const string CONST_creaturePool030 = " join the Liberal Crime Squad.";
const string CONST_creaturePool029 = " offers to let ";
const string CONST_creaturePool028 = "D - Break off the meetings.";
const string CONST_creaturePool027 = " isn't ready to join the LCS.";
const string CONST_creaturePool026 = "C - ";
const string CONST_creaturePool025 = " needs more Juice to recruit.";
const string CONST_creaturePool023 = " join the LCS as a full member.";
const string CONST_creaturePool022 = "C - Offer to let ";
const string CONST_creaturePool021 = "B - Just casually chat with them and discuss politics.";
const string CONST_creaturePool020 = "A - Spend $50 on props and a book for them to keep afterward.";
const string CONST_creaturePool019 = " approach the situation?";
const string CONST_creaturePool018 = "How should ";
const string CONST_creaturePool017 = " kind of regrets agreeing to this.";
const string CONST_creaturePool016 = " is ready to fight for the Liberal Cause.";
const string CONST_creaturePool015 = " feels something needs to be done.";
const string CONST_creaturePool014 = " is interested in learning more.";
const string CONST_creaturePool013 = " will take a lot of persuading.";
const string CONST_creaturePool012 = "Meeting with ";
const string CONST_creaturePool011 = "!";
const string CONST_creaturePool010 = "Get it together, ";
const string CONST_creaturePool009 = "due to multiple booking of recruitment sessions.";
const string CONST_creaturePool008 = " accidentally missed the meeting with ";
const string CONST_creaturePool047 = " has escaped!";
const string CONST_creaturePool049 = "'s injuries require professional treatment.";
const string CONST_creaturePool048 = " has died of injuries.";
const string CONST_creaturePool061 = " has lost touch with the Liberal Crime Squad.";
const string CONST_creaturePool060 = " has abandoned the LCS.";
const string CONST_creaturePool059 = "The Liberal has gone into hiding...";
const string CONST_creaturePool071 = " has left ";
const string CONST_creaturePool070 = " has been transferred to ";

//void monthlyRunTheSystem(char &clearformess) {
	const string CONST_creaturePool069 = " is moved to the courthouse for trial.";
	const string CONST_creaturePool068 = "The traitor will testify in court, and safehouses may be compromised.";
	const string CONST_creaturePool067 = " has broken under the pressure and ratted you out!";
	const string CONST_creaturePool066 = "deportation.";
	const string CONST_creaturePool065 = "execution.";
	const string CONST_creaturePool064 = " has been shipped out to the INS to face ";
	const string CONST_creaturePool063 = "'s mind with Conservatism!";
	const string CONST_creaturePool062 = "Cops re-polluted ";
	//promotesubhordinates
	const string CONST_creaturePool057 = " is the new leader of the Liberal Crime Squad!";
	const string CONST_creaturePool056 = " has died.";
	const string CONST_creaturePool055 = " in the command chain.";
	const string CONST_creaturePool054 = " will take over for ";
	const string CONST_creaturePool053 = "due to the death of ";
	const string CONST_creaturePool052 = " has promoted ";
	const string CONST_creaturePool051 = "There are none left with the courage and conviction to lead....";

#include "../creature/creature.h"
	////

	//#include "../creature/deprecatedCreatureA.h"

#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../common/creaturePool.h"
#include "../common/creaturePoolCreature.h"
//extern string string_sleeper;
#include "../cursesAlternative.h"
#include "../log/log.h"
//#include "../common/consolesupport.h"
#include "../sitemode/advance.h"
/* handles end of round stuff for one creature */
	void advancecreature(DeprecatedCreature &cr);
#include "../common/commonactionsCreature.h"
#include "../combat/fightCreature.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
	//extern string commaSpace;
#include "../set_color_support.h"
#include "../common/commondisplay.h"
#include "../common/commondisplayCreature.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../common/getnames.h"
//extern string singleDot;
	enum LOOP_CONTINUATION {
		RETURN_ZERO,
		RETURN_ONE,
		REPEAT
	};
	extern Log gamelog;
	extern int stat_recruits;
	extern class Ledger ledger;

	extern Log gamelog;
	extern class Ledger ledger;


	extern MusicClass music;
	extern Log gamelog;
#include "../common/translateid.h"
	// for  int getpoolcreature(int)
#include "../daily/siege.h"
	enum DispersalTypes
	{
		DISPERSAL_SAFE = -1,
		DISPERSAL_BOSSSAFE,
		DISPERSAL_NOCONTACT,
		DISPERSAL_BOSSINPRISON,
		DISPERSAL_HIDING,
		DISPERSAL_BOSSINHIDING,
		DISPERSAL_ABANDONLCS
	};
#include "../common/commonactions.h"
	extern Log gamelog;
	extern char disbanding;
	extern vector<Deprecatedsquadst *> squad;
	//#include "../monthly/justice.h"
	void trial(DeprecatedCreature &g);
	char prison(DeprecatedCreature &g);
	extern Log gamelog;
	extern short lawList[LAWNUM];
	extern Log gamelog;
	//#include "../monthly/sleeper_update.h"
	void sleepereffect(DeprecatedCreature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM]);
	void savehighscore(char endtype);
	void viewhighscores(int musicoverride = MUSIC_OFF);
	void end_game(int err = EXIT_SUCCESS);
	short getCurrentSite();
	extern MusicClass music;
#endif	//CREATUREPOOL_CPP
#ifdef	CREATURETYPE_CPP
// creaturetype.cpp

	const string NONE = "NONE";
	const string CONST_creaturetypeB086 = ": ";
	const string CONST_creaturetypeB080 = " lacks idname.";
	const string CONST_creaturetypeB078 = ", ";
	const string CONST_creaturetypeB075 = " in ";
	const string CONST_creaturetype074 = "Fireman";
	const string CONST_creaturetype073 = "Car Salesman";
	const string CONST_creaturetype072 = "Migrant Worker";
	const string CONST_creaturetype071 = "Custodian";
	const string CONST_creaturetype070 = "Slave";
	const string CONST_creaturetype069 = "type_name not defined for ";
	const string CONST_creaturetype068 = "Unknown element for ";
	const string CONST_creaturetype067 = "Invalid armor type for ";
	const string CONST_creaturetype066 = "Unknown skill for ";
	const string CONST_creaturetype065 = "Invalid gender for ";
	const string CONST_creaturetype064 = "Unknown attribute in ";
	const string CONST_creaturetype063 = "Invalid alignment for ";
	const string CONST_creaturetype062 = "Creature type ";
	const string CONST_creaturetype061 = "LACKS IDNAME ";
	const string CONST_creaturetype060 = "Invalid clip type for ";
	const string CONST_creaturetype059 = "can not be used by ";
	const string CONST_creaturetype058 = "In ";
	const string CONST_creaturetype057 = "Invalid weapon type for ";
	const string CONST_creaturetype056 = "Unknown element for weapon in ";
	const string CONST_creaturetype055 = "Invalid interval for ";

	const string tag_ARMOR = "ARMOR";
	const string tag_ARMOR_NONE = "ARMOR_NONE";
	const string tag_CLIP_45 = "CLIP_45";
	const string tag_CLIP = "CLIP";
	const string tag_WEAPON = "WEAPON";
	const string tag_WEAPON_SEMIPISTOL_45 = "WEAPON_SEMIPISTOL_45";
	const string tag_CLIP_9 = "CLIP_9";
	const string tag_WEAPON_SEMIPISTOL_9MM = "WEAPON_SEMIPISTOL_9MM";
	const string tag_CLIP_38 = "CLIP_38";
	const string tag_WEAPON_REVOLVER_38 = "WEAPON_REVOLVER_38";
	const string tag_WEAPON_NONE = "WEAPON_NONE";
	const string tag_CIVILIAN = "CIVILIAN";
	const string tag_type = "type";
	const string tag_type_name = "type_name";
	const string tag_encounter_name = "encounter_name";
	const string tag_creature = "creature";
	const string tag_weapon = "weapon";
	const string tag_armor = "armor";
	const string tag_skills = "skills";
	const string tag_skill = "skill";
	const string tag_money = "money";
	const string tag_infiltration = "infiltration";
	const string tag_gender = "gender";
	const string tag_juice = "juice";
	const string tag_attributes = "attributes";
	const string tag_attribute = "attribute";
	const string tag_attribute_points = "attribute_points";
	const string tag_SENIOR = "SENIOR";
	const string tag_MI = "MI";
	const string tag_MIDDLEAGED = "MIDDLEAGED";
	const string tag_GRADUATE = "GRADUATE";
	const string tag_MATURE = "MATURE";
	const string tag_Y = "Y";
	const string tag_YOUNGADULT = "YOUNGADULT";
	const string tag_TEENAGER = "TEENAGER";
	const string tag_CHILD = "CHILD";
	const string tag_CHI = "CHI";
	const string tag_D = "D";
	const string tag_DOGYEARS = "DOGYEARS";
	const string tag_age = "age";
	const string tag_CONSERVATIVE = "CONSERVATIVE";
	const string tag_MODERATE = "MODERATE";
	const string tag_LIBERAL = "LIBERAL";
	const string tag_PUBLIC_MOOD = "PUBLIC MOOD";
	const string tag_align = "align";
	const string tag_alignment = "alignment";
	const string tag_idname = "idname";
	const string tag_id = "id";
	const string tag_APPROPRIATE = "APPROPRIATE";
	const string tag_number_clips = "number_clips";
	const string tag_clip = "clip";
	const string tag_cliptype = "cliptype";
	const string tag_number_weapons = "number_weapons";
	const string tag_value = "value";
	const string tag_CLIP_BUCKSHOT = "CLIP_BUCKSHOT";
	const string tag_CLIP_SMG = "CLIP_SMG";
	const string tag_CLIP_ASSAULT = "CLIP_ASSAULT";
	const string tag_WEAPON_AUTORIFLE_AK47 = "WEAPON_AUTORIFLE_AK47";
	const string tag_CLIP_44 = "CLIP_44";
	const string tag_WEAPON_AXE = "WEAPON_AXE";
	const string tag_CLIP_GASOLINE = "CLIP_GASOLINE";
	const string tag_WEAPON_TORCH = "WEAPON_TORCH";
	const string tag_WEAPON_PITCHFORK = "WEAPON_PITCHFORK";
	const string tag_WEAPON_GAVEL = "WEAPON_GAVEL";

	const string CONST_creaturetypes049 = "Giant Mosquito";
	const string CONST_creaturetypes048 = "Flaming Rabbit";
	const string CONST_creaturetypes047 = "Pet ";
	const string CONST_creaturetypes046 = "CCS Team Leader";
	const string CONST_creaturetypes045 = "Firefighter";
	const string CONST_creaturetypes044 = "Fireman";
	const string CONST_creaturetypes043 = "Police Negotiator";
	const string CONST_creaturetypes042 = "CEO ";
	const string CONST_creaturetypes041 = "Enforcer";
	const string CONST_creaturetypes040 = "genetic_monster.txt";
	const string CONST_creaturetypes039 = "words_meaning_hick.txt";
	const string CONST_creaturetypesX01 = "CCS Lieutenant";
	const string CONST_creaturetypesX02 = "CCS Founder";

	const string tag_WEAPON_FLAMETHROWER = "WEAPON_FLAMETHROWER";
	const string tag_LOOT_COMPUTER = "LOOT_COMPUTER";
	const string tag_LOOT_CHEAPJEWELERY = "LOOT_CHEAPJEWELERY";
	const string tag_LOOT_TRINKET = "LOOT_TRINKET";
	const string tag_LOOT_SILVERWARE = "LOOT_SILVERWARE";
	const string tag_LOOT_CELLPHONE = "LOOT_CELLPHONE";
	const string tag_ARMOR_CIVILLIANARMOR = "ARMOR_CIVILLIANARMOR";
	const string tag_ARMOR_SECURITYUNIFORM = "ARMOR_SECURITYUNIFORM";
	const string tag_ARMOR_ARMYARMOR = "ARMOR_ARMYARMOR";
	const string tag_ARMOR_HEAVYARMOR = "ARMOR_HEAVYARMOR";
	const string tag_ARMOR_CHEAPSUIT = "ARMOR_CHEAPSUIT";
	const string tag_ARMOR_WORKCLOTHES = "ARMOR_WORKCLOTHES";
	const string tag_ARMOR_CLOTHES = "ARMOR_CLOTHES";
	const string tag_ARMOR_TRENCHCOAT = "ARMOR_TRENCHCOAT";
	const string tag_WEAPON_AUTORIFLE_M16 = "WEAPON_AUTORIFLE_M16";
	const string tag_WEAPON_SMG_MP5 = "WEAPON_SMG_MP5";
	const string tag_WEAPON_CARBINE_M4 = "WEAPON_CARBINE_M4";
	const string tag_WEAPON_REVOLVER_44 = "WEAPON_REVOLVER_44";
	const string tag_LOOT_PDA = "LOOT_PDA";
	const string tag_LOOT_MICROPHONE = "LOOT_MICROPHONE";
	const string tag_LOOT_CABLENEWSFILES = "LOOT_CABLENEWSFILES";
	const string tag_LOOT_AMRADIOFILES = "LOOT_AMRADIOFILES";
	const string tag_LOOT_FAMILYPHOTO = "LOOT_FAMILYPHOTO";
	const string tag_LOOT_WATCH = "LOOT_WATCH";
	const string tag_ARMOR_BONDAGEGEAR = "ARMOR_BONDAGEGEAR";
	const string tag_ARMOR_EXPENSIVESUIT = "ARMOR_EXPENSIVESUIT";
	const string tag_ARMOR_EXPENSIVEDRESS = "ARMOR_EXPENSIVEDRESS";
	const string tag_LOOT_CORPFILES = "LOOT_CORPFILES";
	const string tag_LOOT_CHEMICAL = "LOOT_CHEMICAL";
	const string tag_LOOT_FINECLOTH = "LOOT_FINECLOTH";
	const string tag_ARMOR_BUNKERGEAR = "ARMOR_BUNKERGEAR";
	const string tag_LOOT_SECRETDOCUMENTS = "LOOT_SECRETDOCUMENTS";
	const string tag_WEAPON_SHANK = "WEAPON_SHANK";
	const string tag_ARMOR_PRISONER = "ARMOR_PRISONER";
	const string tag_LOOT_JUDGEFILES = "LOOT_JUDGEFILES";
	const string tag_LOOT_POLICERECORDS = "LOOT_POLICERECORDS";
	const string tag_ARMOR_POLICEARMOR = "ARMOR_POLICEARMOR";
	const string tag_ARMOR_SWATARMOR = "ARMOR_SWATARMOR";
	const string tag_ARMOR_POLICEUNIFORM = "ARMOR_POLICEUNIFORM";
	const string tag_ARMOR_DEATHSQUADUNIFORM = "ARMOR_DEATHSQUADUNIFORM";
	const string tag_WEAPON_SHOTGUN_PUMP = "WEAPON_SHOTGUN_PUMP";
	const string tag_WEAPON_NIGHTSTICK = "WEAPON_NIGHTSTICK";
	const string tag_LOOT_LABEQUIPMENT = "LOOT_LABEQUIPMENT";
	const string tag_LOOT_RESEARCHFILES = "LOOT_RESEARCHFILES";
	const string tag_LOOT_EXPENSIVEJEWELERY = "LOOT_EXPENSIVEJEWELERY";
	const string tag_ARMOR_BLACKROBE = "ARMOR_BLACKROBE";
	const string tag_ARMOR_LABCOAT = "ARMOR_LABCOAT";
	const string tag_ARMOR_BLACKDRESS = "ARMOR_BLACKDRESS";
	const string tag_ARMOR_BLACKSUIT = "ARMOR_BLACKSUIT";
	const string tag_WEAPON_SEMIRIFLE_AR15 = "WEAPON_SEMIRIFLE_AR15";
	const string tag_WEAPON_COMBATKNIFE = "WEAPON_COMBATKNIFE";
	const string tag_WEAPON_BASEBALLBAT = "WEAPON_BASEBALLBAT";
	const string tag_WEAPON_DAISHO = "WEAPON_DAISHO";
	const string tag_ARMOR_CLOWNSUIT = "ARMOR_CLOWNSUIT";
	const string tag_ARMOR_DONKEYSUIT = "ARMOR_DONKEYSUIT";
	const string tag_ARMOR_ELEPHANTSUIT = "ARMOR_ELEPHANTSUIT";
	const string tag_ARMOR_CHEAPDRESS = "ARMOR_CHEAPDRESS";
	const string tag_WEAPON_GUITAR = "WEAPON_GUITAR";
	const string tag_LOOT_DIRTYSOCK = "LOOT_DIRTYSOCK";
	const string tag_LOOT_KIDART = "LOOT_KIDART";
	const string tag_ARMOR_TOGA = "ARMOR_TOGA";
	const string tag_WEAPON_SYRINGE = "WEAPON_SYRINGE";
	const string tag_WEAPON_CHAIN = "WEAPON_CHAIN";
	const string tag_WEAPON_CROWBAR = "WEAPON_CROWBAR";
	const string creature = "creature\\";

#include "../creature/creature.h"
#include "../locations/locationsEnums.h"
#include "../common/interval.h"
#include "creaturetype.h"
	//own header
#include "../log/log.h"
// for LOG
#include "../common/translateid.h"
// for  int getweapontype(int)
#include "../common/stringconversion.h"
//for creaturetype_string_to_enum
#include "../politics/politics.h"
//for int publicmood(int l);

	map<string, int> creatureTypeTags = {
		map<string, int>::value_type(tag_alignment, ENUM_tag_alignment),
		map<string, int>::value_type(tag_PUBLIC_MOOD, ENUM_tag_PUBLIC_MOOD),
		map<string, int>::value_type(tag_LIBERAL, ENUM_tag_LIBERAL),
		map<string, int>::value_type(tag_MODERATE, ENUM_tag_MODERATE),
		map<string, int>::value_type(tag_CONSERVATIVE, ENUM_tag_CONSERVATIVE),
		map<string, int>::value_type(tag_age, ENUM_tag_age),
		map<string, int>::value_type(tag_DOGYEARS, ENUM_tag_DOGYEARS),
		map<string, int>::value_type(tag_CHILD, ENUM_tag_CHILD),
		map<string, int>::value_type(tag_TEENAGER, ENUM_tag_TEENAGER),
		map<string, int>::value_type(tag_YOUNGADULT, ENUM_tag_YOUNGADULT),
		map<string, int>::value_type(tag_MATURE, ENUM_tag_MATURE),
		map<string, int>::value_type(tag_GRADUATE, ENUM_tag_GRADUATE),
		map<string, int>::value_type(tag_MIDDLEAGED, ENUM_tag_MIDDLEAGED),
		map<string, int>::value_type(tag_SENIOR, ENUM_tag_SENIOR),
		map<string, int>::value_type(tag_attribute_points, ENUM_tag_attribute_points),
		map<string, int>::value_type(tag_attributes, ENUM_tag_attributes),
		map<string, int>::value_type(tag_juice, ENUM_tag_juice),
		map<string, int>::value_type(tag_gender, ENUM_tag_gender),
		map<string, int>::value_type(tag_infiltration, ENUM_tag_infiltration),
		map<string, int>::value_type(tag_money, ENUM_tag_money),
		map<string, int>::value_type(tag_skills, ENUM_tag_skills),
		map<string, int>::value_type(tag_armor, ENUM_tag_armor),
		map<string, int>::value_type(tag_weapon, ENUM_tag_weapon),
		map<string, int>::value_type(tag_encounter_name, ENUM_tag_encounter_name),
		map<string, int>::value_type(tag_type_name, ENUM_tag_type_name),

	};

	//string undefined;
	//	extern string NONE;
	extern Log xmllog;
	vector<CreatureTypes> armAsCivilian = {
		// Curiously, CREATURE_CRACKHEAD has a chance to be armed with a shank, regardless of whether they are granted a civilian weapon
		CREATURE_CRACKHEAD, CREATURE_MUTANT, CREATURE_BUM, CREATURE_WORKER_FACTORY_UNION, CREATURE_WORKER_FACTORY_NONUNION, CREATURE_SCIENTIST_EMINENT, CREATURE_SCIENTIST_LABTECH
	};

	map<short, vector<CreatureTypes> > replaceTheseCreatures = {
		// The original code has a 1/10 chance to replace with CREATURE_THIEF
		// Otherwise, random selection between the other five.
		// This code changes this to a 1/11 chance to replace with CREATURE_THIEF
		// Which is close enough.
		map<CreatureTypes, vector<CreatureTypes> >::value_type(CREATURE_PRISONER,{ CREATURE_THIEF, CREATURE_GANGMEMBER, CREATURE_PROSTITUTE, CREATURE_CRACKHEAD, CREATURE_TEENAGER, CREATURE_HSDROPOUT, CREATURE_GANGMEMBER, CREATURE_PROSTITUTE, CREATURE_CRACKHEAD, CREATURE_TEENAGER, CREATURE_HSDROPOUT })

	};
	vector<CreatureTypes> doNotArmInThisFunction = {
		CREATURE_JUDGE_LIBERAL,
		CREATURE_POLITICIAN,
		CREATURE_CORPORATE_MANAGER,
		CREATURE_WORKER_SERVANT,
		CREATURE_WORKER_JANITOR,
		CREATURE_WORKER_SECRETARY,
		CREATURE_LANDLORD,
		CREATURE_BANK_TELLER,
		CREATURE_BANK_MANAGER,
		CREATURE_TEENAGER,
		CREATURE_SOLDIER,
		CREATURE_VETERAN,
		CREATURE_HARDENED_VETERAN,
		CREATURE_SWAT,
		CREATURE_DEATHSQUAD,
		CREATURE_GANGUNIT,
		CREATURE_AGENT,
		CREATURE_SECRET_SERVICE,
		CREATURE_RADIOPERSONALITY,
		CREATURE_NEWSANCHOR,
		CREATURE_JUROR,
		CREATURE_WORKER_FACTORY_CHILD,
		CREATURE_SEWERWORKER,
		CREATURE_COLLEGESTUDENT,
		CREATURE_MUSICIAN,
		CREATURE_MATHEMATICIAN,
		CREATURE_TEACHER,
		CREATURE_HSDROPOUT,
		CREATURE_PRIEST,
		CREATURE_ENGINEER,
		CREATURE_TELEMARKETER,
		CREATURE_CARSALESMAN,
		CREATURE_OFFICEWORKER,
		CREATURE_MAILMAN,
		CREATURE_GARBAGEMAN,
		CREATURE_PLUMBER,
		CREATURE_CHEF,
		CREATURE_CONSTRUCTIONWORKER,
		CREATURE_AMATEURMAGICIAN,
		CREATURE_AUTHOR,
		CREATURE_JOURNALIST,
		CREATURE_CRITIC_ART,
		CREATURE_CRITIC_MUSIC,
		CREATURE_BIKER,
		CREATURE_TRUCKER,
		CREATURE_TAXIDRIVER,
		CREATURE_PROGRAMMER,
		CREATURE_NUN,
		CREATURE_RETIREE,
		CREATURE_PAINTER,
		CREATURE_SCULPTOR,
		CREATURE_DANCER,
		CREATURE_PHOTOGRAPHER,
		CREATURE_CAMERAMAN,
		CREATURE_HAIRSTYLIST,
		CREATURE_FASHIONDESIGNER,
		CREATURE_CLERK,
		CREATURE_ACTOR,
		CREATURE_YOGAINSTRUCTOR,
		CREATURE_MARTIALARTIST,
		CREATURE_ATHLETE,
		CREATURE_LOCKSMITH,
		CREATURE_MILITARYPOLICE,
		CREATURE_SEAL,
		// These are not used in the switch statement anymore, but appear in the defaultWeapons collection
		//CREATURE_SECURITY_GUARD
		//CRREATURE_MERC
	};
	struct weaponLayout {
		string weaponTag;
		string clipTag;
		int ammunition;
		weaponLayout(string whichSkill_, string experience_, int maxLevel_) :weaponTag(whichSkill_), clipTag(experience_), ammunition(maxLevel_) {}
		weaponLayout(string whichSkill_) :weaponTag(whichSkill_), clipTag(""), ammunition(0) {}
		weaponLayout() : weaponLayout(tag_WEAPON_NONE) {}
	};
	struct fullWeaponLayout {
		weaponLayout cplus;
		weaponLayout c;
		weaponLayout moderate;
		weaponLayout l;
		weaponLayout lplus;
		fullWeaponLayout() : cplus(weaponLayout()), c(weaponLayout()), moderate(weaponLayout()), l(weaponLayout()), lplus(weaponLayout()) {}
		fullWeaponLayout(weaponLayout cplus_, weaponLayout c_, weaponLayout moderate_, weaponLayout l_, weaponLayout lplus_) : cplus(cplus_), c(c_), moderate(moderate_), l(l_), lplus(lplus_) {}

	};


	map<const short, const fullWeaponLayout> defaultWeapons = {
		map<const short, const fullWeaponLayout>::value_type(CREATURE_BOUNCER, fullWeaponLayout(weaponLayout(tag_WEAPON_SMG_MP5, tag_CLIP_SMG, 4), weaponLayout(tag_WEAPON_REVOLVER_44, tag_CLIP_44, 4), weaponLayout(tag_WEAPON_REVOLVER_38, tag_CLIP_38, 4), weaponLayout(tag_WEAPON_NIGHTSTICK), weaponLayout(tag_WEAPON_NIGHTSTICK))),
		map<const short, const fullWeaponLayout>::value_type(CREATURE_SECURITYGUARD, fullWeaponLayout(weaponLayout(tag_WEAPON_SMG_MP5, tag_CLIP_SMG, 4), weaponLayout(tag_WEAPON_NIGHTSTICK), weaponLayout(tag_WEAPON_NIGHTSTICK), weaponLayout(tag_WEAPON_NIGHTSTICK), weaponLayout(tag_WEAPON_REVOLVER_38, tag_CLIP_38, 4))),
		map<const short, const fullWeaponLayout>::value_type(CREATURE_MERC, fullWeaponLayout(weaponLayout(tag_WEAPON_AUTORIFLE_M16, tag_CLIP_ASSAULT, 7), weaponLayout(tag_WEAPON_AUTORIFLE_M16, tag_CLIP_ASSAULT, 7), weaponLayout(tag_WEAPON_AUTORIFLE_M16, tag_CLIP_ASSAULT, 7), weaponLayout(tag_WEAPON_SEMIRIFLE_AR15, tag_CLIP_ASSAULT, 7), weaponLayout(tag_WEAPON_SEMIRIFLE_AR15, tag_CLIP_ASSAULT, 7))),

	};

#define AGE_TEENAGER    14+LCSrandom(4)  /* HS dropout, teenager, some fast food workers */
#define AGE_YOUNGADULT  18+LCSrandom(18) /* young lads and ladies */
	extern short lawList[LAWNUM];
	extern vector<WeaponType *> weapontype;
	extern vector<ClipType *> cliptype;
#include "locations/locationsPool.h"
#include "sitemode/stealth.h"
	short getCurrentSite();
	extern short mode;
	extern short sitetype;
	struct fullName {
		string first;
		string middle;
		string last;

	};
	fullName generate_long_name(char gender = GENDER_NEUTRAL);
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern short lawList[LAWNUM];
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern short lawList[LAWNUM];
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern short lawList[LAWNUM];
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern short lawList[LAWNUM];
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern short lawList[LAWNUM];
	extern vector<ClipType *> cliptype;
	extern short lawList[LAWNUM];
	extern vector<WeaponType *> weapontype;
	bool isThereASiteAlarm();

	extern vector<WeaponType *> weapontype;
	extern vector<ClipType *> cliptype;
	extern short lawList[LAWNUM];
	extern short mode;

	extern char endgamestate;
	extern vector<WeaponType *> weapontype;
	extern vector<ClipType *> cliptype;
	extern short mode;
	extern short sitetype;
	extern char ccs_kills;

	extern char endgamestate;
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern short lawList[LAWNUM];
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern short lawList[LAWNUM];
	extern short mode;
	extern short sitetype;
	extern char ccs_kills;

	extern char endgamestate;
	extern short lawList[LAWNUM];
	extern short lawList[LAWNUM];
	extern vector<WeaponType *> weapontype;
	extern short mode;
	extern short sitetype;
	extern char ccs_kills;

	extern char endgamestate;
	extern short lawList[LAWNUM];
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern vector<WeaponType *> weapontype;
	extern vector<ClipType *> cliptype;
	extern short sitealienate;
#include "customMaps.h"
	vector<string> words_meaning_hick;
	vector<string> genetic_monster;
	vector<file_and_text_collection> creaturetypes_text_file_collection = {
		/*creaturetypes.cpp*/
		customText(&words_meaning_hick, creature + CONST_creaturetypes039),
		customText(&genetic_monster, creature + CONST_creaturetypes040),
	};

	extern vector<WeaponType *> weapontype;
	extern Log xmllog;
#endif	//CREATURETYPE_CPP
#ifdef	CURSESALTERNATIVE_CPP
// cursesAlternative.cpp

#endif	//CURSESALTERNATIVE_CPP
#ifdef	CURSESMOVIE_CPP
// cursesmovie.cpp

	const string CONST_cursesmovie001 = "rb";
	const string CONST_cursesmovie000 = "wb";
#endif	//CURSESMOVIE_CPP
#ifdef	DAILY_CPP
// daily.cpp

	const string notEnoughMoney = "You don't have enough money!";
	const string chooseAColor = "Choose a color";
	const string theseColorsAreCon = "These colors are Conservative";
	const string thisColor = "Color";
	const string chooseVehicle = "Choose a vehicle";
	const string thisVehicle = "Vehicle";
	const string weDontNeedCar = "We don't need a Conservative car";
	const string b_chooseBuyer = "B - Choose a buyer";
	const string s_sellCar = "S - Sell a car";
	const string s_sellThe = "S - Sell the ";
	const string g_getCar = "G - Get a Liberal car";
	const string toSpend = "SPEND.";
	const string enterLeave = "Enter - Leave";
	const string f_fixWounds = "F - Go in and fix up Conservative wounds";
	const string CONST_daily007 = " was too hot to risk.";
	const string CONST_daily006 = " decided ";
	const string CONST_daily024 = " regains contact with the LCS.";
	const string CONST_daily023 = "CREATURE_POLITICALACTIVIST";
	const string CONST_daily022 = "CREATURE_TEENAGER";
	const string CONST_daily021 = ". The Liberal will be missed.";
	const string CONST_daily020 = " has passed away at the age of ";
	const string CONST_daily019 = " surfs the Net for recent opinion polls.";
	const string CONST_daily018 = "Why is the squad here?   (S)afe House, to cause (T)rouble, or (B)oth?";
	const string CONST_daily017 = " has arrived at ";
	const string CONST_daily016 = " looks around ";
	const string CONST_daily013 = " arrives in ";
	const string CONST_daily012 = "%s spent $%d on tickets to go to %s.";
	const string CONST_daily011 = "%s couldn't afford tickets to go to %s.";
	const string CONST_daily010 = "travel location";
	const string CONST_daily009 = " didn't have a car to get to ";
	const string CONST_daily008 = " couldn't use the ";
//	const string CONST_daily007 = " was too hot to risk.";
//	const string CONST_daily006 = " decided ";
	const string CONST_daily005 = " instead of ";
	const string CONST_daily004 = " acted with ";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";
	const string CONST_shopsnstuff008 = "oubliette.xml";
	const string CONST_shopsnstuff007 = "deptstore.xml";
	const string CONST_shopsnstuff006 = "P - Repaint car, replace plates and tags ($500)";
	const string CONST_shopsnstuff005 = "pawnshop.xml";
	const string CONST_shopsnstuff004 = "armsdealer.xml";
//	const string CONST_daily024 = " regains contact with the LCS.";
//	const string CONST_daily023 = "CREATURE_POLITICALACTIVIST";
//	const string CONST_daily022 = "CREATURE_TEENAGER";
//	const string CONST_daily021 = ". The Liberal will be missed.";
//	const string CONST_daily020 = " has passed away at the age of ";
//	const string CONST_daily019 = " surfs the Net for recent opinion polls.";
//	const string CONST_daily005 = " instead of ";
//	const string CONST_daily004 = " acted with ";
//	const string singleDot = ".";
//	const string CONST_daily008 = " couldn't use the ";
//	const string singleDot = ".";
//	const string CONST_daily018 = "Why is the squad here?   (S)afe House, to cause (T)rouble, or (B)oth?";
//	const string CONST_daily017 = " has arrived at ";
//	const string CONST_daily016 = " looks around ";
//	const string CONST_daily013 = " arrives in ";
	const string CONST_daily012A = " spent $";
	const string CONST_daily012B = " on tickets to go to ";
	const string CONST_daily012C = ".";
	const string CONST_daily011A = " couldn't afford tickets to go to %";
	const string CONST_daily011B = ".";
//	const string CONST_daily010 = "travel location";
//	const string CONST_daily009 = " didn't have a car to get to ";
//	const string singleDot = ".";

#include "../creature/creature.h"
////

#include "../creature/deprecatedCreatureA.h"

#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
//#include "../news/news.h"
	void majornewspaper(char &clearformess, char canseethings);
	//#include "../sitemode/sitemode.h"
	void mode_site(const short loc);
#include "../log/log.h"
	// for commondisplay.h
#include "../common/commondisplay.h"
// for makedelimeter
#include "../common/getnames.h"
// for std::string getactivity(ActivityST)
#include "../common/translateid.h"
// for  int getsquad(int)
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
/* tells how many total members a squad has (including dead members) */
// for void basesquad(squadst *,long)
#include "../daily/daily.h"
/* squad members with no chain of command lose contact */
	void dispersalcheck(char &clearformess);

#include "../daily/activities.h"
	//for void repairarmor(Creature &cr,char &clearformess); and stealcar
#include "../daily/siege.h"        
//for sigeturn and siegecheck
//#include "../daily/recruit.h"
	void recruitment_activity(DeprecatedCreature &cr);
	char completerecruitmeeting(Deprecatedrecruitst &d, const int p);
	//#include "../daily/date.h"
	char completevacation(Deprecateddatest &d, int p);
	char completedate(Deprecateddatest &d, int p);
#include "../combat/chaseCreature.h"
	//for int driveskill(Creature &cr,Vehicle &v);
	//hmm --Schmel924
#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include "../title/titlescreen.h"
#include "../locations/locationsPool.h"
#include "../common/creaturePool.h"




/*
shopsnstuff.cpp
*/


#include "../sitemode/shop.h"
#include "../common/musicClass.h"
//extern string closeParenthesis;
//extern string undefined;
//extern string check_status_of_squad_liberal;

/* active squad visits the hospital */
/* active squad visits the hospital */

/* common - moves all squad members and their cars to a new location */
	void locatesquad(Deprecatedsquadst *st, long loc);
	/* common - assigns a new base to all members of a squad */
	void basesquad(Deprecatedsquadst *st, long loc);

	void locateActiveSquad(const int loc);
	extern Deprecatedsquadst *activesquad;
	extern MusicClass music;
	extern short party_status;
	extern Deprecatedsquadst *activesquad;
	extern MusicClass music;
	extern char artdir[MAX_PATH_SIZE];
	extern Deprecatedsquadst *activesquad;
	extern MusicClass music;
	extern char artdir[MAX_PATH_SIZE];
	extern short party_status;
	int lenVehicleType();
	string vehicleTypelongname(const int p);
	Vehicle* getVehicleFromTypeYear(const int carchoice, const int colorchoice, const int year);
	int getVehicleTypePrice(const int carchoice);
	int getVehicleTypeSleeperPrice(const int carchoice);
	vector<string> getVehicleTypeColor(const int carchoice);
	bool vehicletypeavailableatshop(const int i);
	DeprecatedCreature* findSleeperCarSalesman(int loc);
	//	extern string spaceParanthesisDollar;
	extern Deprecatedsquadst *activesquad;
	extern MusicClass music;
	extern int year;
	extern short party_status;
	extern class Ledger ledger;
	extern vector<Vehicle *> vehicle;

	void determineMedicalSupportAtEachLocation(bool clearformess);
	extern int day;
	extern int month;
	extern Log gamelog;
	extern vector<DeprecatedCreature *> pool;
	extern vector<Deprecatednewsstoryst *> newsstory;
	extern char disbanding;
	extern vector<Deprecatedrecruitst *> recruit;
	extern vector<DeprecatedCreature *> pool;
	extern vector<Deprecatedrecruitst *> recruit;
	extern char disbanding;
	extern int day;
	extern class Ledger ledger;
	/* hostage tending */
	void tendhostage(DeprecatedCreature *cr, char &clearformess);
	/* armor repair */
	void repairarmor(DeprecatedCreature &cr, char &clearformess);
	/* armor manufacture */
	void makearmor(DeprecatedCreature &cr, char &clearformess);
	/* search for polls */
	void survey(DeprecatedCreature *cr);
	/* steal a car */
	bool stealcar(DeprecatedCreature &cr, char &clearformess);
	bool carselect(DeprecatedCreature &cr, short &cartype);
	/* get a wheelchair */
	void getwheelchair(DeprecatedCreature &cr, char &clearformess);
	extern Log gamelog;
	extern vector<DeprecatedCreature *> pool;
	extern Log gamelog;
	extern vector<Deprecatedsquadst *> squad;
	string getVehicleFullname(int i);
	extern Log gamelog;
	extern vector<Deprecatedsquadst *> squad;
	int driveskill(DeprecatedCreature &cr, int v);
	extern Log gamelog;
	extern vector<Deprecatedsquadst *> squad;
	extern Log gamelog;
	extern vector<Deprecatedsquadst *> squad;
	extern short fieldskillrate;
	extern vector<Deprecatedsquadst *> squad;
	extern char showcarprefs;
	extern Deprecatedsquadst *activesquad;
	extern Log gamelog;
	extern vector<Deprecatedsquadst *> squad;
	extern vector<Deprecatednewsstoryst *> newsstory;
	extern Deprecatedsquadst *activesquad;
	extern Log gamelog;
	extern vector<Deprecatedsquadst *> squad;
	extern class Ledger ledger;
	extern vector<DeprecatedCreature *> pool;
	void doDates(char &clearformess);
	void clearCarStates();
	extern char showcarprefs;
	extern char disbanding;
	extern class Ledger ledger;
#endif	//DAILY_CPP
#ifdef	DATE_CPP
// date.cpp

	const string CONST_dateB104 = "'s ";
	const string CONST_dateB103 = " cell phone.";
	const string CONST_dateB102 = " pet";
	const string CONST_dateB101 = " favourite TV show.";
	const string CONST_dateB100 = " hair.";
	const string CONST_dateB099 = "'s frozen Conservative heart.";
	const string CONST_date103 = "The Liberal wakes up in the police station...";
	const string CONST_date102 = " remembers seeing!";
	const string CONST_date101 = "'s fist is the last thing ";
	const string CONST_date100 = " has failed to kidnap the Conservative.";
	const string CONST_date099 = " manages to get away on the way back to the safehouse!";
	const string CONST_date098 = "If you do not enter anything, their real name will be used.";
	const string CONST_date097 = " in its presence?";
	const string CONST_date096 = "What name will you use for this ";
	const string CONST_date095 = "The Education of ";
	const string CONST_date094 = " kidnaps the Conservative!";
	const string CONST_date093 = " struggles and yells for help, but nobody comes.";
	const string CONST_date092 = " doesn't resist.";
	const string CONST_date091 = "not to [resist]!";
	const string CONST_date090 = "not to fuck around!";
	const string CONST_date089 = " seizes the Conservative swine from behind and warns it";
	const string CONST_date088 = "to the corporate slave's throat!";
	const string CONST_date087 = " grabs the Conservative from behind, holding the ";
	const string CONST_date086 = "and threatens to blow the Conservative's brains out!";
	const string CONST_date085 = " comes back from the bathroom toting the ";
	const string CONST_date084 = "E - Just kidnap the Conservative bitch.";
	const string CONST_date083 = "D - Break it off.";
	const string CONST_date082 = "C - Spend a week on a cheap vacation (must be uninjured).";
	const string CONST_date081 = "C - Spend a week on a cheap vacation (stands up any other dates).";
	const string CONST_date080 = "B - Try to get through the evening without spending a penny.";
	const string CONST_date079 = "A - Spend a hundred bucks tonight to get the ball rolling.";
	const string CONST_date078 = " approach the situation?";
	const string CONST_date077 = "How should ";
	const string CONST_date076 = "Seeing ";
	const string CONST_date075 = "Things go downhill fast.";
	const string CONST_date074 = " mixes up the names of ";
	const string CONST_date073A = " realizes ";
	const string CONST_date073B = " has committed to eating ";
	const string CONST_date073C = " meals at once.";;
	const string CONST_date072 = "Ruh roh...";
	const string CONST_date071 = "Unfortunately, they turn up at the same time.";
	const string CONST_date070 = "Unfortunately, they all turn up at the same time.";
	const string CONST_date069 = ".  An ambush was set for the lying dog...";
	const string CONST_date068 = "Unfortunately, they know each other and had been discussing";
	const string CONST_date067 = "Unfortunately, they all know each other and had been discussing";
	const string CONST_date066 = " at ";
	const string CONST_date065 = "dates to manage with ";
	const string CONST_date064 = "a hot date with ";
	const string CONST_date063 = "a \"hot\" date with ";
	const string CONST_date062 = " has ";
	const string CONST_date061 = " is back from vacation.";
	const string CONST_date060 = "This relationship is over.";
	const string CONST_date059 = " can sense that things just aren't working out.";
	const string CONST_date058 = " from meeting ";
	const string CONST_date057 = "schedule for keeping ";
	const string CONST_date056 = "mind-bending ";
	const string CONST_date055 = "detailed ";
	const string CONST_date054 = "complicated ";
	const string CONST_date053 = "intricate ";
	const string CONST_date052 = "awe-inspiring ";
	const string CONST_date051 = "notices ";
	const string CONST_date050 = "The date starts well, but goes horribly wrong when ";
	const string CONST_date049 = " escapes the police ambush!";
	const string CONST_date048 = "But ";
	const string CONST_date047 = " has been arrested.";
	const string CONST_date046 = " was leaking information to the police the whole time!";
	const string CONST_date045 = "'s mind with wisdom!!!";
	const string CONST_date044 = " actually curses ";
	const string CONST_date043 = "Talking with ";
	const string CONST_date042 = "They'll meet again tomorrow.";
	const string CONST_date041 = " to recharge ";
	const string CONST_date040 = " to go to a birthday party.";
	const string CONST_date039 = " six-legged pig.";
	const string CONST_date038 = " fish.";
	const string CONST_date037 = " dog.";
	const string CONST_date036 = " cat.";
	const string CONST_date035 = " to take care of ";
	const string CONST_date034 = " to catch ";
	const string CONST_date033 = " due to an early meeting tomorrow.";
	const string CONST_date032 = " due to an allergy attack.";
	const string CONST_date031 = " to wash ";
	const string CONST_date030 = " seemed to have fun, but left early";
	const string CONST_date028 = " knows all about that already.";
	const string CONST_date027 = " was able to create a map of the site with this information.";
	const string CONST_date026 = " turns the topic of discussion to the ";
	const string CONST_date025 = " is slowly warming ";
	const string CONST_date021 = "The Self-Nullifying Infatuation of ";
	const string CONST_date020 = "'s totally unconditional love-slave!";
	const string CONST_date019 = " is ";
	const string CONST_date018 = "In fact, ";
	const string CONST_date017 = "It was fun though. They agree to part ways amicably.";
	const string CONST_date016 = " relationship.";
	const string CONST_date015 = "yet another";
	const string CONST_date014 = "another";
	const string CONST_date013 = " isn't seductive enough to juggle ";
	const string CONST_date012 = " people!";
	const string CONST_date011 = "someone!";
	const string CONST_date010 = " is already dating ";
	const string CONST_date008 = "'s unique life philosophy...";
	const string CONST_date007 = " is quite taken with ";
	const string CONST_date006 = "date_fail.txt";

	const string tag_ARMOR = "ARMOR";
	const string tag_ARMOR_CLOTHES = "ARMOR_CLOTHES";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";
	const string datey = "date\\";

#include "../creature/creature.h"
	////

#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"
//#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
#include "../common/commondisplayCreature.h"
// for  addstr
#include "../common/commonactionsCreature.h"
// for int loveslavesleft(const Creature&)
#include "../common/getnames.h"
// for void enter_name(int,int,char *,int,const char *=NULL)
//#include "../common/translateid.h"
	int getarmortype(const string &idname);
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../common/creaturePoolCreature.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
	vector<string> date_fail;
	vector<file_and_text_collection> date_text_file_collection = {
		/*date.cpp*/
		customText(&date_fail, datey + CONST_date006),
	};
	enum DateResults
	{
		DATERESULT_MEETTOMORROW,
		DATERESULT_BREAKUP,
		DATERESULT_JOINED,
		DATERESULT_ARRESTED
	};
	extern MusicClass music;
	extern int stat_recruits;
	extern Log gamelog;
	extern short lawList[LAWNUM];
	extern vector<DeprecatedCreature *> pool;
	extern MusicClass music;
	extern Log gamelog;
	extern vector<DeprecatedCreature *> pool;
	extern MusicClass music;
	extern int stat_kidnappings;
	extern Log gamelog;
	extern class Ledger ledger;
	extern short lawList[LAWNUM];
	extern vector<DeprecatedCreature *> pool;
	int getpoolcreature(int id);
	char completedate(Deprecateddatest &d, int p);
	void removesquadinfo(DeprecatedCreature &cr);
	char completevacation(Deprecateddatest &d, int p);
#endif	//DATE_CPP
#ifdef	ENDGAME_CPP
// endgame.cpp

	const string conservativesRemakeWorld = "The Conservatives have made the world in their image.";
	const string stalinistsRemakeWorld = "The Stalinists have made the world in their image.";
	const string youWentOnVacation = "You went on vacation when the country was on the verge of collapse.";
	const string youWentIntoHiding = "You went into hiding when the country was on the verge of collapse.";
	const string whileYouWereInPrison = "While you were on the inside, the country degenerated...";
	const string youDisappearedSafely = "You disappeared safely, but you hadn't done enough.";
	const string proposeConservative = "The Arch-Conservative Congress is proposing an ARCH-CONSERVATIVE AMENDMENT!";
	const string proposeStalinist = "The Stalinist Congress is proposing a STALINIST AMENDMENT!";
	const string they_ll_round_you_up = "They'll round up the last of you up eventually.  All is lost.";
	const string pressKeyToReflect = "Press any key to reflect on what has happened.";
	const string YEA = " Yea";
	const string NAY = " Nay";
	const string CONST_endgame047 = "Press any key to breathe a sigh of relief.                   ";
	const string CONST_endgame046 = "Press any key to reflect on what has happened ONE LAST TIME.";
	const string CONST_endgame045 = "Press 'C' to watch the ratification process unfold.";
	const string CONST_endgame044 = "INVALID ALIGNMENT FOR AMENDMENT";
	const string CONST_endgame043 = "Press any key to hold new elections!                           ";
	const string CONST_endgame041 = "A National Convention has proposed an ELITE LIBERAL AMENDMENT!";
	const string CONST_endgame039 = "the Senate.";
	const string CONST_endgame038 = "the President's choosing with the advice and consent of";
	const string CONST_endgame037 = ", also of";
	const string CONST_endgame036 = "a Proper Justice";
	const string CONST_endgame035 = "Proper Justices";
	const string CONST_endgame034 = "choosing to be replaced by ";
	const string CONST_endgame033 = " of the President's";
	const string CONST_endgame032 = "a Conservative country";
	const string CONST_endgame031 = "Conservative countries";
	const string CONST_endgame030 = "be deported to ";
	const string CONST_endgame029 = " will";
	const string CONST_endgame028 = "s";
	const string CONST_endgame027 = "not serve on the Supreme Court.  Said former citizen";
	const string CONST_endgame026 = " may";
	const string CONST_endgame024 = "In particular, the aforementioned former citizen";
	const string CONST_endgame023 = " branded Arch-Conservative:";
	const string CONST_endgame022 = " is";
	const string CONST_endgame021 = "s are";
	const string CONST_endgame020 = "The following former citizen";
	const string CONST_endgame019 = "The Elite Liberal Congress is proposing an ELITE LIBERAL AMENDMENT!";
	const string CONST_endgame018 = " to the United States Constitution:";
	const string CONST_endgame017 = "Proposed Amendment ";
	const string CONST_endgame016 = "AMENDMENT REJECTED.";
	const string CONST_endgame015 = "AMENDMENT ADOPTED.";
	const string CONST_endgame014 = "Nay";
	const string CONST_endgame013 = "Yea";
	const string CONST_endgame012 = "Press any key to watch the State votes unfold.              ";
	const string CONST_endgame011 = "Press any key to watch the Congressional votes unfold.     ";
	const string CONST_endgame010 = "Senate";
	const string CONST_endgame009 = "House";
	const string CONST_endgame008 = "The Ratification Process:";
	const string CONST_endgame007 = "stalinizedCabinet.txt";
	const string CONST_endgame006 = "reaganifiedCabinet.txt";
	const string CONST_endgame005 = "stalinistPrison.txt";
	const string CONST_endgame004 = "conservativePrison.txt";
	const string CONST_endgame003 = "amendmentPass.txt";
	const string CONST_endgame002 = "archConservativeAmendment.txt";
	const string CONST_endgame001 = "stalinAmendment.txt";
	const string mostlyendings = "mostlyendings\\";

#include "../creature/creatureEnums.h"
	/* fills a string with a proper name */
	void generate_name(char *str, char gender = GENDER_NEUTRAL);
#include "../basemode/liberalagenda.h"
	// for liberalagenda
	//#include "../log/log.h"
	// for commondisplay.h
#include "../common/commondisplay.h"
// for void printfunds(int,int,char*)
#include "../common/misc.h"
// for char* statename(int)
		 //shouldn't be in getnames? --Schmel924
// for romannumeral (int)
		 //only usage here --Schmel924
#include "../title/titlescreen.h"
// for void reset;
#include "../title/highscore.h"
// for void savehighscore(char endtype);
//#include "../monthly/EndGameStatus.h"
//own header
		//does not compile without --Schmel924
#include "../politics/politics.h"
//for publicmood
#include "../cursesAlternative.h"
#include <gui_constants.h>
#include "../set_color_support.h"
/* end the game and clean up */
	void end_game(int err = EXIT_SUCCESS);
#include "../common/musicClass.h"
	vector<int> state_biases;
	vector<string> reaganifiedCabinet;
	vector<string> stalinizedCabinet;
	vector<string> archConservativeAmendment;
	vector<string> stalinAmendment;

	vector<string> conservativePrison;
	vector<string> stalinistPrison;
	vector<string> amendmentPass;
#include "../customMaps.h"
	vector<file_and_text_collection> endgame_text_file_collection = {
		customText(&stalinAmendment, mostlyendings + CONST_endgame001),
		customText(&archConservativeAmendment, mostlyendings + CONST_endgame002),
		customText(&amendmentPass, mostlyendings + CONST_endgame003),
		customText(&conservativePrison, mostlyendings + CONST_endgame004),
		customText(&stalinistPrison, mostlyendings + CONST_endgame005),
		customText(&reaganifiedCabinet, mostlyendings + CONST_endgame006),
		customText(&stalinizedCabinet, mostlyendings + CONST_endgame007),
	};
	struct fullName {
		string first;
		string middle;
		string last;

	};
	fullName generate_long_name(char gender);
	extern MusicClass music;
	extern short house[HOUSENUM];
	extern short senate[SENATENUM];
	extern short attitude[VIEWNUM];
	extern int amendnum;
	fullName generate_long_name(char gender = GENDER_NEUTRAL);
	extern MusicClass music;
	extern int amendnum;
	extern short court[COURTNUM];
	extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
	extern MusicClass music;
	extern int amendnum;
	extern bool termlimits;
	extern MusicClass music;
	extern int amendnum;
	extern char cantseereason;
	extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	extern short exec[EXECNUM];
	extern short lawList[LAWNUM];
#endif	//ENDGAME_CPP
#ifdef	EXTERNALLYSTOREDDATA_CPP
// externallyStoredData.cpp

	const string study_string1 = "attend classes in the University District";
	const string study_string2 = "at a cost of $60 a day.";

	const string talky = "talk\\";
	const string mostlyendings = "mostlyendings\\";
	const string CONST_externallyStoredDataC1087 = "Sell Liberal Art";
	const string CONST_externallyStoredDataC1086 = "Sell Liberal T-Shirts";
	const string CONST_externallyStoredDataC1085 = "uncontrolled immigration.";
	const string CONST_externallyStoredDataC1084 = "legalizing nuclear power.";
	const string CONST_externallyStoredDataC1083 = "restoring the death penalty.";
	const string CONST_externallyStoredDataC1082 = "Classes cost up to $60/day to conduct. All Liberals able will attend.";
	const string CONST_externallyStoredDataC1081 = "Classes cost up to $20/day to conduct. All Liberals able will attend.";
	const string CONST_externallyStoredDataC1080 = "will create and sell paintings embracing the Liberal agenda.";
	const string CONST_externallyStoredDataC1079 = "will print and distribute shirts with Liberal slogans.";
	const string CONST_externallyStoredDataC1078 = "activist is.";
	const string CONST_externallyStoredDataC1077 = "Multiple hackers will increase chances of both success and detection.";
	const string CONST_externallyStoredDataC1076 = "and intelligence will provide better results.";

	const string CONST_externallyStoredDataB1077 = "Drug Law";
	const string CONST_externallyStoredDataB1076 = "Tax Law";
	const string CONST_externallyStoredDataB1075 = "Freedom of Speech";
	const string CONST_externallyStoredDataB1074 = "Corporate Ethics";
	const string CONST_externallyStoredDataB1073 = "Homosexual Rights";
	const string CONST_externallyStoredDataB1072 = "Workers' Rights";
	const string CONST_externallyStoredDataB1071 = "Capital Punishment";
	const string CONST_externallyStoredDataB1070 = "Privacy";
	const string CONST_externallyStoredDataB1069 = "Police Behavior";
	const string CONST_externallyStoredDataB1068 = "Animal Research";
	const string CONST_externallyStoredDataB1067 = "The CCS Terrorists";
	const string CONST_externallyStoredDataB1066 = "Why We Rock";
	const string CONST_externallyStoredDataB1065 = "Who We Are";
	const string CONST_externallyStoredDataB1064 = "The Need For Action";
	const string CONST_externallyStoredDataB1063 = "Cable \"News\" Lies";
	const string CONST_externallyStoredDataB1062 = "AM Radio Propaganda";
	const string CONST_externallyStoredDataB1061 = "Immigrant Rights";
	const string CONST_externallyStoredDataB1060 = "Oppressive Drug Laws";
	const string CONST_externallyStoredDataB1059 = "Racial Equality";
	const string CONST_externallyStoredDataB1058 = "Gender Equality";
	const string CONST_externallyStoredDataB1057 = "CEO Compensation";
	const string CONST_externallyStoredDataB1056 = "Corporate Corruption";
	const string CONST_externallyStoredDataB1054 = "Mass Shootings";
	const string CONST_externallyStoredDataB1053 = "The Judiciary";
	const string CONST_externallyStoredDataB1052 = "Dangerous GMOs";
	const string CONST_externallyStoredDataB1050 = "The Prison System";
	const string CONST_externallyStoredDataB1049 = "Torture";
	const string CONST_externallyStoredDataB1048 = "Police Misconduct";
	const string CONST_externallyStoredDataB1047 = "Animal Cruelty";
	const string CONST_externallyStoredDataB1046 = "Nuclear Meltdowns";
	const string CONST_externallyStoredDataB1045 = "The Tax Structure";
	const string CONST_externallyStoredDataB1044 = "Barbaric Executions";
	const string CONST_externallyStoredDataB1043 = "LGBTQ Rights";
	const string CONST_externallyStoredDataB1042 = "Public Mood";
	const string CONST_externallyStoredDataB1041 = "Play Liberal Music";
	const string CONST_externallyStoredDataB1040 = "Sell Paintings";
	const string CONST_externallyStoredDataB1039 = "Sell Embroidered Shirts";
	const string CONST_externallyStoredDataB1038 = "enhancing interrogations.";
	const string CONST_externallyStoredDataB1037 = "the CCS terrorists.";
	const string CONST_externallyStoredDataB1036 = "defending the nation.";
	const string CONST_externallyStoredDataB1035 = "protecting the Second Amendment.";
	const string CONST_externallyStoredDataB1034 = "troublemaking minorities.";
	const string CONST_externallyStoredDataB1033 = "women.";
	const string CONST_externallyStoredDataB1032 = "drug abuse.";
	const string CONST_externallyStoredDataB1031 = "illegal immigration.";
	const string CONST_externallyStoredDataB1030 = "putting the prisoners in line.";
	const string CONST_externallyStoredDataB1029 = "resisting communist wage limits.";
	const string CONST_externallyStoredDataB1028 = "excessive regulation of corporations.";
	const string CONST_externallyStoredDataB1027 = "excessive regulation of industry.";
	const string CONST_externallyStoredDataB1026 = "corrupt union thugs.";
	const string CONST_externallyStoredDataB1025 = "appointing proper Conservative justices.";
	const string CONST_externallyStoredDataB1024 = "excessive regulation of genetic research.";
	const string CONST_externallyStoredDataB1023 = "ending hate speech.";
	const string CONST_externallyStoredDataB1022 = "national security and intelligence.";
	const string CONST_externallyStoredDataB1021 = "expanding police powers.";
	const string CONST_externallyStoredDataB1020 = "excessive regulation of animal research.";
	const string CONST_externallyStoredDataB1019 = "threats to nuclear power.";
	const string CONST_externallyStoredDataB1018 = "the excessive tax burden.";
	const string CONST_externallyStoredDataB1017 = "protecting the death penalty.";
	const string CONST_externallyStoredDataB1016 = "protecting the traditional family.";
	const string CONST_externallyStoredDataB1015 = "Classes cost up to $100/day to conduct. All Liberals able will attend.";
	const string CONST_externallyStoredDataB1014 = "Seduction, Psychology, Driving";
	const string CONST_externallyStoredDataB1013 = "Religion, Business, Music, Art";
	const string CONST_externallyStoredDataB1012 = "physically superior.";
	const string CONST_externallyStoredDataB1011 = "major websites.";
	const string CONST_externallyStoredDataB1010 = "magical shimmering doorways to the adamantium pits.";
	const string CONST_externallyStoredDataB1009 = "or play guitar if one is equipped.";
	const string CONST_externallyStoredDataB1008 = "will make pretty paintings and sell them on the streets.";
	const string CONST_externallyStoredDataB1007 = "will embroider shirts and sell them on the street.";
	const string CONST_externallyStoredDataB1006 = "Based on persuasion, public's view on the cause, and how well dressed the";
	const string CONST_externallyStoredDataB1005 = "Computer skill and intelligence will give more frequent results.";
	const string CONST_externallyStoredDataB1004 = "will give greater effect.";
	const string CONST_externallyStoredDataB1003 = "Polls will give an idea on how the liberal agenda is going. Computers";
	const string CONST_externallyStoredDataB1002 = "enhance the liberal effect.";
	const string CONST_externallyStoredDataB1001 = "that is Liberal.";

	const string CONST_externallyStoredData999 = "SITE_OUTDOOR_BUNKER";
	const string CONST_externallyStoredData998 = "SITE_OUTDOOR_PUBLICPARK";
	const string CONST_externallyStoredData997 = "SITE_BUSINESS_BARANDGRILL";
	const string CONST_externallyStoredData996 = "SITE_BUSINESS_INTERNETCAFE";
	const string CONST_externallyStoredData995 = "SITE_BUSINESS_VEGANCOOP";
	const string CONST_externallyStoredData994 = "SITE_BUSINESS_LATTESTAND";
	const string CONST_externallyStoredData993 = "SITE_BUSINESS_CIGARBAR";
	const string CONST_externallyStoredData992 = "SITE_BUSINESS_JUICEBAR";
	const string CONST_externallyStoredData991 = "SITE_BUSINESS_CRACKHOUSE";
	const string CONST_externallyStoredData990 = "SITE_MEDIA_CABLENEWS";
	const string CONST_externallyStoredData989 = "SITE_MEDIA_AMRADIO";
	const string CONST_externallyStoredData988 = "SITE_CORPORATE_HOUSE";
	const string CONST_externallyStoredData987 = "SITE_CORPORATE_HEADQUARTERS";
	const string CONST_externallyStoredData986 = "SITE_INDUSTRY_WAREHOUSE";
	const string CONST_externallyStoredData985 = "SITE_INDUSTRY_NUCLEAR";
	const string CONST_externallyStoredData984 = "SITE_INDUSTRY_POLLUTER";
	const string CONST_externallyStoredData983 = "SITE_INDUSTRY_SWEATSHOP";
	const string CONST_externallyStoredData982 = "SITE_GOVERNMENT_FIRESTATION";
	const string CONST_externallyStoredData981 = "SITE_GOVERNMENT_INTELLIGENCEHQ";
	const string CONST_externallyStoredData980 = "SITE_GOVERNMENT_PRISON";
	const string CONST_externallyStoredData979 = "SITE_GOVERNMENT_COURTHOUSE";
	const string CONST_externallyStoredData978 = "SITE_GOVERNMENT_POLICESTATION";
	const string CONST_externallyStoredData977 = "SITE_LABORATORY_GENETIC";
	const string CONST_externallyStoredData976 = "SITE_LABORATORY_COSMETICS";
	const string CONST_externallyStoredData975 = "SITE_RESIDENTIAL_BOMBSHELTER";
	const string CONST_externallyStoredData974 = "SITE_RESIDENTIAL_APARTMENT_UPSCALE";
	const string CONST_externallyStoredData973 = "SITE_RESIDENTIAL_APARTMENT";
	const string CONST_externallyStoredData972 = "SITE_RESIDENTIAL_TENEMENT";
	const string CONST_externallyStoredData971 = "SITE_RESIDENTIAL_SHELTER";
	const string CONST_externallyStoredData970 = "CREATURE_POLITICIAN";
	const string CONST_externallyStoredData969 = "CREATURE_SECRET_SERVICE";
	const string CONST_externallyStoredData968 = "CREATURE_BANK_MANAGER";
	const string CONST_externallyStoredData967 = "CREATURE_BANK_TELLER";
	const string CONST_externallyStoredData966 = "CREATURE_MILITARYOFFICER";
	const string CONST_externallyStoredData965 = "CREATURE_SEAL";
	const string CONST_externallyStoredData964 = "CREATURE_MILITARYPOLICE";
	const string CONST_externallyStoredData963 = "CREATURE_LOCKSMITH";
	const string CONST_externallyStoredData962 = "CREATURE_PSYCHOLOGIST";
	const string CONST_externallyStoredData961 = "CREATURE_CCS_SNIPER";
	const string CONST_externallyStoredData960 = "CREATURE_CCS_MOLOTOV";
	const string CONST_externallyStoredData959 = "CREATURE_POLITICALACTIVIST";
	const string CONST_externallyStoredData958 = "CREATURE_CCS_ARCHCONSERVATIVE";
	const string CONST_externallyStoredData957 = "CREATURE_CCS_VIGILANTE";
	const string CONST_externallyStoredData956 = "CREATURE_NURSE";
	const string CONST_externallyStoredData955 = "CREATURE_DOCTOR";
	const string CONST_externallyStoredData954 = "CREATURE_MUTANT";
	const string CONST_externallyStoredData953 = "CREATURE_NUN";
	const string CONST_externallyStoredData952 = "CREATURE_TAXIDRIVER";
	const string CONST_externallyStoredData951 = "CREATURE_TRUCKER";
	const string CONST_externallyStoredData950 = "CREATURE_BIKER";
	const string CONST_externallyStoredData949 = "CREATURE_ATHLETE";
	const string CONST_externallyStoredData948 = "CREATURE_MARTIALARTIST";
	const string CONST_externallyStoredData947 = "CREATURE_YOGAINSTRUCTOR";
	const string CONST_externallyStoredData946 = "CREATURE_ACTOR";
	const string CONST_externallyStoredData945 = "CREATURE_THIEF";
	const string CONST_externallyStoredData944 = "CREATURE_CLERK";
	const string CONST_externallyStoredData943 = "CREATURE_FASHIONDESIGNER";
	const string CONST_externallyStoredData942 = "CREATURE_HAIRSTYLIST";
	const string CONST_externallyStoredData941 = "CREATURE_CAMERAMAN";
	const string CONST_externallyStoredData940 = "CREATURE_PHOTOGRAPHER";
	const string CONST_externallyStoredData939 = "CREATURE_DANCER";
	const string CONST_externallyStoredData938 = "CREATURE_JOURNALIST";
	const string CONST_externallyStoredData937 = "CREATURE_AUTHOR";
	const string CONST_externallyStoredData936 = "CREATURE_SCULPTOR";
	const string CONST_externallyStoredData935 = "CREATURE_PAINTER";
	const string CONST_externallyStoredData934 = "CREATURE_RETIREE";
	const string CONST_externallyStoredData933 = "CREATURE_PROGRAMMER";
	const string CONST_externallyStoredData932 = "CREATURE_SOCIALITE";
	const string CONST_externallyStoredData931 = "CREATURE_CRITIC_MUSIC";
	const string CONST_externallyStoredData930 = "CREATURE_CRITIC_ART";
	const string CONST_externallyStoredData929 = "CREATURE_HIPPIE";
	const string CONST_externallyStoredData928 = "CREATURE_PRISONGUARD";
	const string CONST_externallyStoredData927 = "CREATURE_HARDENED_VETERAN";
	const string CONST_externallyStoredData926 = "CREATURE_VETERAN";
	const string CONST_externallyStoredData925 = "CREATURE_SOLDIER";
	const string CONST_externallyStoredData924 = "CREATURE_HICK";
	const string CONST_externallyStoredData923 = "CREATURE_MERC";
	const string CONST_externallyStoredData922 = "CREATURE_TANK";
	const string CONST_externallyStoredData921 = "CREATURE_AMATEURMAGICIAN";
	const string CONST_externallyStoredData920 = "CREATURE_CONSTRUCTIONWORKER";
	const string CONST_externallyStoredData919 = "CREATURE_CHEF";
	const string CONST_externallyStoredData918 = "CREATURE_PLUMBER";
	const string CONST_externallyStoredData917 = "CREATURE_GARBAGEMAN";
	const string CONST_externallyStoredData916 = "CREATURE_MAILMAN";
	const string CONST_externallyStoredData915 = "CREATURE_PROSTITUTE";
	const string CONST_externallyStoredData914 = "CREATURE_FOOTBALLCOACH";
	const string CONST_externallyStoredData913 = "CREATURE_OFFICEWORKER";
	const string CONST_externallyStoredData912 = "CREATURE_CARSALESMAN";
	const string CONST_externallyStoredData911 = "CREATURE_TELEMARKETER";
	const string CONST_externallyStoredData910 = "CREATURE_BARTENDER";
	const string CONST_externallyStoredData909 = "CREATURE_BARISTA";
	const string CONST_externallyStoredData908 = "CREATURE_BAKER";
	const string CONST_externallyStoredData907 = "CREATURE_FASTFOODWORKER";
	const string CONST_externallyStoredData906 = "CREATURE_ENGINEER";
	const string CONST_externallyStoredData905 = "CREATURE_PRIEST";
	const string CONST_externallyStoredData904 = "CREATURE_CRACKHEAD";
	const string CONST_externallyStoredData903 = "CREATURE_GANGMEMBER";
	const string CONST_externallyStoredData902 = "CREATURE_BUM";
	const string CONST_externallyStoredData901 = "CREATURE_HSDROPOUT";
	const string CONST_externallyStoredData900 = "CREATURE_TEACHER";
	const string CONST_externallyStoredData899 = "CREATURE_MATHEMATICIAN";
	const string CONST_externallyStoredData898 = "CREATURE_MUSICIAN";
	const string CONST_externallyStoredData897 = "CREATURE_COLLEGESTUDENT";
	const string CONST_externallyStoredData896 = "CREATURE_SEWERWORKER";
	const string CONST_externallyStoredData895 = "CREATURE_LAWYER";
	const string CONST_externallyStoredData894 = "CREATURE_JUROR";
	const string CONST_externallyStoredData893 = "CREATURE_PRISONER";
	const string CONST_externallyStoredData892 = "CREATURE_GUARDDOG";
	const string CONST_externallyStoredData891 = "CREATURE_GENETIC";
	const string CONST_externallyStoredData890 = "CREATURE_NEWSANCHOR";
	const string CONST_externallyStoredData889 = "CREATURE_RADIOPERSONALITY";
	const string CONST_externallyStoredData888 = "CREATURE_AGENT";
	const string CONST_externallyStoredData887 = "CREATURE_JUDGE_CONSERVATIVE";
	const string CONST_externallyStoredData886 = "CREATURE_JUDGE_LIBERAL";
	const string CONST_externallyStoredData885 = "CREATURE_GANGUNIT";
	const string CONST_externallyStoredData884 = "CREATURE_EDUCATOR";
	const string CONST_externallyStoredData883 = "CREATURE_FIREFIGHTER";
	const string CONST_externallyStoredData882 = "CREATURE_DEATHSQUAD";
	const string CONST_externallyStoredData881 = "CREATURE_SWAT";
	const string CONST_externallyStoredData880 = "CREATURE_COP";
	const string CONST_externallyStoredData879 = "CREATURE_TEENAGER";
	const string CONST_externallyStoredData878 = "CREATURE_LANDLORD";
	const string CONST_externallyStoredData877 = "CREATURE_WORKER_FACTORY_UNION";
	const string CONST_externallyStoredData876 = "CREATURE_WORKER_SECRETARY";
	const string CONST_externallyStoredData875 = "CREATURE_WORKER_FACTORY_CHILD";
	const string CONST_externallyStoredData874 = "CREATURE_WORKER_FACTORY_NONUNION";
	const string CONST_externallyStoredData873 = "CREATURE_WORKER_SWEATSHOP";
	const string CONST_externallyStoredData872 = "CREATURE_WORKER_JANITOR";
	const string CONST_externallyStoredData871 = "CREATURE_WORKER_SERVANT";
	const string CONST_externallyStoredData870 = "CREATURE_CORPORATE_CEO";
	const string CONST_externallyStoredData869 = "CREATURE_CORPORATE_MANAGER";
	const string CONST_externallyStoredData868 = "CREATURE_SCIENTIST_EMINENT";
	const string CONST_externallyStoredData867 = "CREATURE_SCIENTIST_LABTECH";
	const string CONST_externallyStoredData866 = "CREATURE_SECURITYGUARD";
	const string CONST_externallyStoredData865 = "CREATURE_BOUNCER";
	const string CONST_externallyStoredData864 = "ATTRIBUTE_CHARISMA";
	const string CONST_externallyStoredData863 = "ATTRIBUTE_HEALTH";
	const string CONST_externallyStoredData862 = "ATTRIBUTE_STRENGTH";
	const string CONST_externallyStoredData861 = "ATTRIBUTE_AGILITY";
	const string CONST_externallyStoredData860 = "ATTRIBUTE_INTELLIGENCE";
	const string CONST_externallyStoredData859 = "ATTRIBUTE_WISDOM";
	const string CONST_externallyStoredData858 = "ATTRIBUTE_HEART";
	const string CONST_externallyStoredData857 = "SKILL_WRITING";
	const string CONST_externallyStoredData856 = "SKILL_THROWING";
	const string CONST_externallyStoredData855 = "SKILL_TEACHING";
	const string CONST_externallyStoredData854 = "SKILL_TAILORING";
	const string CONST_externallyStoredData853 = "SKILL_SWORD";
	const string CONST_externallyStoredData852 = "SKILL_STREETSENSE";
	const string CONST_externallyStoredData851 = "SKILL_STEALTH";
	const string CONST_externallyStoredData850 = "SKILL_SMG";
	const string CONST_externallyStoredData849 = "SKILL_SHOTGUN";
	const string CONST_externallyStoredData848 = "SKILL_SEDUCTION";
	const string CONST_externallyStoredData847 = "SKILL_SECURITY";
	const string CONST_externallyStoredData846 = "SKILL_SCIENCE";
	const string CONST_externallyStoredData845 = "SKILL_RIFLE";
	const string CONST_externallyStoredData844 = "SKILL_RELIGION";
	const string CONST_externallyStoredData843 = "SKILL_PSYCHOLOGY";
	const string CONST_externallyStoredData842 = "SKILL_PISTOL";
	const string CONST_externallyStoredData841 = "SKILL_PERSUASION";
	const string CONST_externallyStoredData840 = "SKILL_MUSIC";
	const string CONST_externallyStoredData839 = "SKILL_HANDTOHAND";
	const string CONST_externallyStoredData838 = "SKILL_LAW";
	const string CONST_externallyStoredData837 = "SKILL_KNIFE";
	const string CONST_externallyStoredData836 = "SKILL_HEAVYWEAPONS";
	const string CONST_externallyStoredData835 = "SKILL_FIRSTAID";
	const string CONST_externallyStoredData834 = "SKILL_DRIVING";
	const string CONST_externallyStoredData833 = "SKILL_DODGE";
	const string CONST_externallyStoredData832 = "SKILL_DISGUISE";
	const string CONST_externallyStoredData831 = "SKILL_COMPUTERS";
	const string CONST_externallyStoredData830 = "SKILL_CLUB";
	const string CONST_externallyStoredData829 = "SKILL_BUSINESS";
	const string CONST_externallyStoredData828 = "SKILL_AXE";
	const string CONST_externallyStoredData827 = "SKILL_ART";
	const string CONST_externallyStoredData720 = "Hiring undocumented workers";
	const string CONST_externallyStoredData718 = "Hiring illegal aliens";
	const string CONST_externallyStoredData715 = "Flag burning";
	const string CONST_externallyStoredData710 = "Flag Murder";
	const string CONST_externallyStoredData709 = "Loitering";
	const string CONST_externallyStoredData708 = "Public nudity";
	const string CONST_externallyStoredData707 = "Disturbing the peace";
	const string CONST_externallyStoredData706 = "Resisting arrest";
	const string CONST_externallyStoredData705 = "Vandalism";
	const string CONST_externallyStoredData704 = "Breaking and entering";
	const string CONST_externallyStoredData703 = "Unlawful burial";
	const string CONST_externallyStoredData702 = "Hacking";
	const string CONST_externallyStoredData701 = "Electronic sabotage";
	const string CONST_externallyStoredData700 = "Carrying illegal weapons";
	const string CONST_externallyStoredData699 = "Firing illegal weapons";
	const string CONST_externallyStoredData698 = "Prostitution";
	const string CONST_externallyStoredData697 = "Theft";
	const string CONST_externallyStoredData696 = "Credit card fraud";
	const string CONST_externallyStoredData695 = "Grand theft auto";
	const string CONST_externallyStoredData694 = "Assault";
	const string CONST_externallyStoredData693 = "Armed assault";
	const string CONST_externallyStoredData692 = "Extortion";
	const string CONST_externallyStoredData691 = "Racketeering";
	const string CONST_externallyStoredData690 = "Jury tampering";
	const string CONST_externallyStoredData689 = "Releasing prisoners";
	const string CONST_externallyStoredData688 = "Escaping prison";
	const string CONST_externallyStoredData687 = "Drug dealing";
	const string CONST_externallyStoredData686 = "Harmful speech";
	const string CONST_externallyStoredData685 = "Arson";
	const string CONST_externallyStoredData684 = "Bank robbery";
	const string CONST_externallyStoredData683 = "Kidnapping";
	const string CONST_externallyStoredData682 = "Murder";
	const string CONST_externallyStoredData681 = "Terrorism";
	const string CONST_externallyStoredData680 = "Treason";
	const string CONST_externallyStoredData679 = "Human Rights";
	const string CONST_externallyStoredData678 = "Prison Regulation";
	const string CONST_externallyStoredData677 = "Military Spending";
	const string CONST_externallyStoredData676 = "Election Reform";
	const string CONST_externallyStoredData675 = "Immigration";
	const string CONST_externallyStoredData674 = "Drug Laws";
	const string CONST_externallyStoredData673 = "Civil Rights";
	const string CONST_externallyStoredData672 = "Women's Rights";
	const string CONST_externallyStoredData671 = "Tax Structure";
	const string CONST_externallyStoredData670 = "Gun Control";
	const string CONST_externallyStoredData669 = "Flag Burning";
	const string CONST_externallyStoredData668 = "Free Speech";
	const string CONST_externallyStoredData667 = "Corporate Law";
	const string CONST_externallyStoredData666 = "Gay Rights";
	const string CONST_externallyStoredData665 = "Labor Laws";
	const string CONST_externallyStoredData664 = "Pollution";
	const string CONST_externallyStoredData663 = "Nuclear Power";
	const string CONST_externallyStoredData662 = "Death Penalty";
	const string CONST_externallyStoredData661 = "Privacy Rights";
	const string CONST_externallyStoredData660 = "Police Regulation";
	const string CONST_externallyStoredData659 = "Animal Rights";
	const string CONST_externallyStoredData658 = "Abortion Rights";
	const string CONST_externallyStoredData657 = "the CCS";
	const string CONST_externallyStoredData656 = "the LCS";
	const string CONST_externallyStoredData654 = "political violence";
	const string CONST_externallyStoredData653 = "cable news";
	const string CONST_externallyStoredData652 = "AM radio";
	const string CONST_externallyStoredData651 = "the military";
	const string CONST_externallyStoredData650 = "immigration";
	const string CONST_externallyStoredData649 = "drugs";
	const string CONST_externallyStoredData648 = "civil rights";
	const string CONST_externallyStoredData647 = "women's rights";
	const string CONST_externallyStoredData646 = "CEO compensation";
	const string CONST_externallyStoredData645 = "corporations";
	const string CONST_externallyStoredData644 = "pollution";
	const string CONST_externallyStoredData643 = "labor unions";
	const string CONST_externallyStoredData642 = "gun control";
	const string CONST_externallyStoredData641 = "judges";
	const string CONST_externallyStoredData640 = "genetic research";
	const string CONST_externallyStoredData639 = "free speech";
	const string CONST_externallyStoredData638 = "privacy";
	const string CONST_externallyStoredData637 = "the prison system";
	const string CONST_externallyStoredData636 = "torture";
	const string CONST_externallyStoredData635 = "cops";
	const string CONST_externallyStoredData634 = "animal cruelty";
	const string CONST_externallyStoredData633 = "nuclear power";
	const string CONST_externallyStoredData632 = "taxes";
	const string CONST_externallyStoredData631 = "the death penalty";
	const string CONST_externallyStoredData630 = "LGBTQ rights";
	const string CONST_externallyStoredData629 = "public mood";
	const string CONST_externallyStoredData628 = "Stalinism";
	const string CONST_externallyStoredData627 = "Augmenting Liberal";
	const string CONST_externallyStoredData626 = "Stealing Equipment";
	const string CONST_externallyStoredData625 = "Embezzling Funds";
	const string CONST_externallyStoredData624 = "Creating a Scandal";
	const string CONST_externallyStoredData623 = "Quitting Job";
	const string CONST_externallyStoredData622 = "Recruiting Sleepers";
	const string CONST_externallyStoredData621 = "Snooping Around";
	const string CONST_externallyStoredData620 = "Spouting Conservatism";
	const string CONST_externallyStoredData619 = "Promoting Liberalism";
	const string CONST_externallyStoredData618 = "Attending Classes";
	const string CONST_externallyStoredData592 = "Going to Free CLINIC";
	const string CONST_externallyStoredData591 = "Writing news";
	const string CONST_externallyStoredData590 = "Writing letters";
	const string CONST_externallyStoredData589 = "Laying Low";
	const string CONST_externallyStoredData588 = "Tending to Injuries";
	const string CONST_externallyStoredData587 = "Selling Brownies";
	const string CONST_externallyStoredData586 = "Soliciting Donations";
	const string CONST_externallyStoredData585 = "Disposing of Bodies";
	const string CONST_externallyStoredData584 = "Selling Music";
	const string CONST_externallyStoredData583 = "Teaching Covert Ops";
	const string CONST_externallyStoredData582 = "Teaching Fighting";
	const string CONST_externallyStoredData581 = "Teaching Politics";
	const string CONST_externallyStoredData580 = "Selling Art";
	const string CONST_externallyStoredData579 = "Selling T-Shirts";
	const string CONST_externallyStoredData578 = "Hacking Networks";
	const string CONST_externallyStoredData577 = "Attacking Websites";
	const string CONST_externallyStoredData576 = "Extorting Websites";
	const string CONST_externallyStoredData575 = "Credit Card Fraud";
	const string CONST_externallyStoredData574 = "Making Graffiti";
	const string CONST_externallyStoredData573 = "Volunteering";
	const string CONST_externallyStoredData572 = "Prostituting";
	const string CONST_externallyStoredData571 = "Causing Trouble";
	const string CONST_externallyStoredData570 = "Gathering Opinion Info";
	const string CONST_externallyStoredData569 = "Stealing a Car";
	const string CONST_externallyStoredData568 = "Procuring a Wheelchair";
	const string CONST_externallyStoredData567 = "Repairing Clothing";
	const string CONST_externallyStoredData566 = "Recruiting";
	const string CONST_externallyStoredData564 = "New York";
	const string CONST_externallyStoredData563 = "Los Angeles";
	const string CONST_externallyStoredData562 = "A Tropical Paradise.";
	const string CONST_externallyStoredData561 = "The Pride of the South.";
	const string CONST_externallyStoredData560 = "Murder Capital of America.";
	const string CONST_externallyStoredData559 = "Mafia Headquarters.";
	const string CONST_externallyStoredData558 = "The Nation's Capital.";
	const string CONST_externallyStoredData557 = "Wall Street and Big Media.";
	const string CONST_externallyStoredData556 = "Hollywood and Trade.";
	const string CONST_externallyStoredData555 = "Birthplace of the LCS.";
	const string CONST_externallyStoredData554 = "]";
	const string CONST_externallyStoredData553 = "Sleeper";
	const string CONST_externallyStoredData552 = " [";
	const string CONST_externallyStoredData550 = "In Hiding";
	const string CONST_externallyStoredData547 = "In Jail";
	const string CONST_externallyStoredData544 = "Arrested";
	const string CONST_externallyStoredData543 = "   [";
	const string CONST_externallyStoredData542 = "Enlightened";
	const string CONST_externallyStoredData541 = "/";
	const string CONST_externallyStoredData540 = "Seduced";
	const string CONST_externallyStoredData539 = "Recruited/";
	const string CONST_externallyStoredData538 = "DAYS UNTIL RETURN";
	const string CONST_externallyStoredData537 = "DAYS SINCE PASSING";
	const string CONST_externallyStoredData536 = "PROFESSION";
	const string CONST_externallyStoredData535 = "PROGNOSIS";
	const string CONST_externallyStoredData534 = "MONTHS LEFT";
	const string CONST_externallyStoredData533 = "DAYS IN CAPTIVITY";
	const string CONST_externallyStoredData532 = "SQUAD / ACTIVITY";
	const string CONST_externallyStoredData531 = "Liberals that are Away";
	const string CONST_externallyStoredData530 = "Liberal Martyrs and Dead Bodies";
	const string CONST_externallyStoredData529 = "Sleepers";
	const string CONST_externallyStoredData528 = "Liberals and the Justice System";
	const string CONST_externallyStoredData527 = "Liberals in CLINICS";
	const string CONST_externallyStoredData526 = "Conservative Automatons in Captivity";
	const string CONST_externallyStoredData525 = "Active Liberals";
	const string CONST_externallyStoredData524 = "TRINKET";
	const string CONST_externallyStoredData523 = "SILVERWARE";
	const string CONST_externallyStoredData522 = "WATCH";
	const string CONST_externallyStoredData521 = "MICROPHONE";
	const string CONST_externallyStoredData520 = "CELLPHONE";
	const string CONST_externallyStoredData519 = "FINEJEWELERY";
	const string CONST_externallyStoredData518 = "POLICERECORDS";
	const string CONST_externallyStoredData517 = "AMRADIOFILES";
	const string CONST_externallyStoredData516 = "CABLENEWSFILES";
	const string CONST_externallyStoredData515 = "PRISONFILES";
	const string CONST_externallyStoredData514 = "RESEARCHFILES";
	const string CONST_externallyStoredData513 = "JUDGEFILES";
	const string CONST_externallyStoredData512 = "CORPFILES";
	const string CONST_externallyStoredData511 = "INTHQDISK";
	const string CONST_externallyStoredData510 = "CEOPHOTOS";
	const string CONST_externallyStoredData509 = "SECRETDOCUMENTS";
	const string CONST_externallyStoredData508 = "CHEAPJEWELERY";
	const string CONST_externallyStoredData507 = "LAPTOP";
	const string CONST_externallyStoredData506 = "LABEQUIPMENT";
	const string CONST_externallyStoredData505 = "PDA";
	const string CONST_externallyStoredData504 = "CHEMICAL";
	const string CONST_externallyStoredData503 = "FINECLOTH";
	const string CONST_externallyStoredData502 = "CLUB_BOUNCER_SECONDVISIT";
	const string CONST_externallyStoredData501 = "CLUB_BOUNCER";
	const string CONST_externallyStoredData500 = "STAIRS_DOWN";
	const string CONST_externallyStoredData499 = "STAIRS_UP";
	const string CONST_externallyStoredData498 = "PARK_BENCH";
	const string CONST_externallyStoredData497 = "CAFE_COMPUTER";
	const string CONST_externallyStoredData496 = "RESTAURANT_TABLE";
	const string CONST_externallyStoredData495 = "APARTMENT_SIGN";
	const string CONST_externallyStoredData494 = "APARTMENT_LANDLORD";
	const string CONST_externallyStoredData493 = "NEWS_BROADCASTSTUDIO";
	const string CONST_externallyStoredData492 = "RADIO_BROADCASTSTUDIO";
	const string CONST_externallyStoredData491 = "CORPORATE_FILES";
	const string CONST_externallyStoredData490 = "HOUSE_CEO";
	const string CONST_externallyStoredData489 = "ARMYBASE_ARMORY";
	const string CONST_externallyStoredData488 = "HOUSE_PHOTOS";
	const string CONST_externallyStoredData487 = "NUCLEAR_ONOFF";
	const string CONST_externallyStoredData486 = "POLLUTER_EQUIPMENT";
	const string CONST_externallyStoredData485 = "SWEATSHOP_EQUIPMENT";
	const string CONST_externallyStoredData484 = "INTEL_SUPERCOMPUTER";
	const string CONST_externallyStoredData483 = "PRISON_CONTROL_HIGH";
	const string CONST_externallyStoredData482 = "PRISON_CONTROL_MEDIUM";
	const string CONST_externallyStoredData481 = "PRISON_CONTROL_LOW";
	const string CONST_externallyStoredData480 = "PRISON_CONTROL";
	const string CONST_externallyStoredData479 = "COURTHOUSE_JURYROOM";
	const string CONST_externallyStoredData478 = "COURTHOUSE_LOCKUP";
	const string CONST_externallyStoredData477 = "POLICESTATION_LOCKUP";
	const string CONST_externallyStoredData476 = "LAB_GENETIC_CAGEDANIMALS";
	const string CONST_externallyStoredData475 = "LAB_COSMETICS_CAGEDANIMALS";
	const string CONST_externallyStoredData446 = "OUTDOOR_PUBLICPARK";
	const string CONST_externallyStoredData445 = "GENERIC_ONEROOM";
	const string CONST_externallyStoredData444 = "OUTDOOR_LATTESTAND";
	const string CONST_externallyStoredData443 = "BUSINESS_RESTRICTEDCAFE";
	const string CONST_externallyStoredData442 = "BUSINESS_INTERNETCAFE";
	const string CONST_externallyStoredData441 = "BUSINESS_CAFE";
	const string CONST_externallyStoredData440 = "MEDIA_CABLENEWS";
	const string CONST_externallyStoredData439 = "MEDIA_AMRADIO";
	const string CONST_externallyStoredData438 = "CORPORATE_HOUSE";
	const string CONST_externallyStoredData437 = "CORPORATE_HEADQUARTERS";
	const string CONST_externallyStoredData436 = "INDUSTRY_NUCLEAR";
	const string CONST_externallyStoredData435 = "INDUSTRY_POLLUTER";
	const string CONST_externallyStoredData434 = "INDUSTRY_SWEATSHOP";
	const string CONST_externallyStoredData433 = "GOVERNMENT_ARMYBASE";
	const string CONST_externallyStoredData432 = "GOVERNMENT_WHITE_HOUSE";
	const string CONST_externallyStoredData431 = "GOVERNMENT_INTELLIGENCEHQ";
	const string CONST_externallyStoredData430 = "GOVERNMENT_PRISON";
	const string CONST_externallyStoredData429 = "GOVERNMENT_COURTHOUSE";
	const string CONST_externallyStoredData428 = "GOVERNMENT_POLICESTATION";
	const string CONST_externallyStoredData427 = "LABORATORY_GENETICS";
	const string CONST_externallyStoredData426 = "LABORATORY_COSMETICS";
	const string CONST_externallyStoredData425 = "GENERIC_LOBBY";
	const string CONST_externallyStoredData420 = "GENERIC_UNSECURE";
	const string CONST_externallyStoredData417 = "RESIDENTIAL_APARTMENT";
	const string CONST_externallyStoredData414 = "WhiteHouse";
	const string CONST_externallyStoredData413 = "NuclearPlant";
	const string CONST_externallyStoredData412 = "Bank";
	const string CONST_externallyStoredData411 = "Park";
	const string CONST_externallyStoredData410 = "VeganCoOp";
	const string CONST_externallyStoredData409 = "LatteStand";
	const string CONST_externallyStoredData408 = "CigarBar";
	const string CONST_externallyStoredData407 = "InternetCafe";
	const string CONST_externallyStoredData406 = "JuiceBar";
	const string CONST_externallyStoredData405 = "CableNews";
	const string CONST_externallyStoredData404 = "RadioStation";
	const string CONST_externallyStoredData403 = "CEOHouse";
	const string CONST_externallyStoredData402 = "CorporateHQ";
	const string CONST_externallyStoredData401 = "Factory";
	const string CONST_externallyStoredData400 = "Sweatshop";
	const string CONST_externallyStoredData399 = "FireStation";
	const string CONST_externallyStoredData398 = "ArmyBase";
	const string CONST_externallyStoredData397 = "IntelligenceHQ";
	const string CONST_externallyStoredData396 = "Prison";
	const string CONST_externallyStoredData395 = "Courthouse";
	const string CONST_externallyStoredData394 = "PoliceStation";
	const string CONST_externallyStoredData393 = "GeneticsLab";
	const string CONST_externallyStoredData392 = "CosmeticsLab";
	const string CONST_externallyStoredData391 = "Bunker";
	const string CONST_externallyStoredData390 = "BombShelter";
	const string CONST_externallyStoredData389 = "BarAndGrill";
	const string CONST_externallyStoredData388 = "CrackHouse";
	const string CONST_externallyStoredData387 = "HomelessShelter";
	const string CONST_externallyStoredData386 = "Warehouse";
	const string CONST_externallyStoredData385 = "ApartmentDowntown";
	const string CONST_externallyStoredData384 = "ApartmentUniversity";
	const string CONST_externallyStoredData383 = "ApartmentIndustrial";
	const string CONST_externallyStoredData382 = "Other Expenses";
	const string CONST_externallyStoredData381 = "T-Shirt Materials";
	const string CONST_externallyStoredData380 = "Training";
	const string CONST_externallyStoredData379 = "Safehouse Investments";
	const string CONST_externallyStoredData378 = "Rent";
	const string CONST_externallyStoredData377 = "Recruitment";
	const string CONST_externallyStoredData376 = "Purchasing Goods";
	const string CONST_externallyStoredData375 = "New Cars";
	const string CONST_externallyStoredData374 = "Manufacturing";
	const string CONST_externallyStoredData373 = "Legal Fees";
	const string CONST_externallyStoredData372 = "Hostage Tending";
	const string CONST_externallyStoredData371 = "Groceries";
	const string CONST_externallyStoredData370 = "Drawing Materials";
	const string CONST_externallyStoredData369 = "Dating";
	const string CONST_externallyStoredData368 = "Confiscated";
	const string CONST_externallyStoredData367 = "Activism";
	const string CONST_externallyStoredData366 = "Other Income";
	const string CONST_externallyStoredData365 = "T-Shirt Sales";
	const string CONST_externallyStoredData364 = "Thievery";
	const string CONST_externallyStoredData363 = "Street Music";
	const string CONST_externallyStoredData361 = "Pawning Goods";
	const string CONST_externallyStoredData360 = "Hustling";
	const string CONST_externallyStoredData358 = "Embezzlement";
	const string CONST_externallyStoredData357 = "Drawing Sales";
	const string CONST_externallyStoredData356 = "Donations";
	const string CONST_externallyStoredData354 = "Car Sales";
	const string CONST_externallyStoredData353 = "Brownies";
	const string CONST_externallyStoredData352 = "ERROR: INVALID VALUE FOR SORTINGCHOICE!";
	const string CONST_externallyStoredData351 = "squadless members.";
	const string CONST_externallyStoredData350 = "available Liberals.";
	const string CONST_externallyStoredData349 = "sleeper activity.";
	const string CONST_externallyStoredData348 = "Liberal activity.";
	const string CONST_externallyStoredData347 = "people away.";
	const string CONST_externallyStoredData346 = "dead people.";
	const string CONST_externallyStoredData345 = "sleepers.";
	const string CONST_externallyStoredData344 = "oppressed Liberals.";
	const string CONST_externallyStoredData343 = "Liberals in hospital.";
	const string CONST_externallyStoredData342 = "hostages.";
	const string CONST_externallyStoredData341 = "active Liberals.";
	const string CONST_externallyStoredData340 = "Teacher";
	const string CONST_externallyStoredData339 = "Taxi Driver";
	const string CONST_externallyStoredData338 = "Psychologist";
	const string CONST_externallyStoredData337 = "Prostitute";
	const string CONST_externallyStoredData336 = "Mutant";
	const string CONST_externallyStoredData335 = "Musician";
	const string CONST_externallyStoredData334 = "Martial Artist";
	const string CONST_externallyStoredData333 = "Locksmith";
	const string CONST_externallyStoredData332 = "Lawyer";
	const string CONST_externallyStoredData331 = "Judge";
	const string CONST_externallyStoredData330 = "Journalist";
	const string CONST_externallyStoredData329 = "Hippie";
	const string CONST_externallyStoredData328 = "Gang Member";
	const string CONST_externallyStoredData327 = "Fashion Designer";
	const string CONST_externallyStoredData326 = "Doctor";
	const string CONST_externallyStoredData325 = "Dancer";
	const string CONST_externallyStoredData324 = "Computer Programmer";
	const string CONST_externallyStoredData323 = "College Student";
	const string CONST_externallyStoredData322 = "Athlete";
	const string CONST_externallyStoredData321 = "Army Veteran";
	const string CONST_externallyStoredData320 = "Urban Warfare";
	const string CONST_externallyStoredData319 = "Infiltration";
	const string CONST_externallyStoredData318 = "Political Activism";
	const string CONST_externallyStoredData317 = "Teach Liberals About What?";
	const string CONST_externallyStoredData316 = "Augment a Liberal";
	const string CONST_externallyStoredData315 = "Procure a Wheelchair";
	const string CONST_externallyStoredData314 = "Steal a Car";
	const string CONST_externallyStoredData313 = "Repair Clothing";
	const string CONST_externallyStoredData312 = "Make Clothing";
	const string CONST_externallyStoredData310 = "Steal Credit Card Numbers";
	const string CONST_externallyStoredData309 = "Electronic Protection Racket";
	const string CONST_externallyStoredData307 = "Sell Brownies";
	const string CONST_externallyStoredData306 = "Play Street Music";
	const string CONST_externallyStoredData305 = "Sell Portrait Sketches";
	const string CONST_externallyStoredData304 = "Sell Tie-Dyed T-Shirts";
	const string CONST_externallyStoredData303 = "Solicit Donations";
	const string CONST_externallyStoredData302 = "Write for The Liberal Guardian";
	const string CONST_externallyStoredData301 = "Write to Newspapers";
	const string CONST_externallyStoredData299 = "Harass Websites";
	const string CONST_externallyStoredData298 = "Search Opinion Polls";
	const string CONST_externallyStoredData297 = "Graffiti";
	const string CONST_externallyStoredData296 = "Liberal Disobedience";
	const string CONST_externallyStoredData295 = "Community Service";
	const string CONST_externallyStoredData294 = "intercepted internal media emails.";
	const string CONST_externallyStoredData293 = "pilfered files from a Corporate server.";
	const string CONST_externallyStoredData292 = "uncovered information on dangerous research.";
	const string CONST_externallyStoredData291 = "discovered evidence of judicial corruption.";
	const string CONST_externallyStoredData290 = "sabotaged a genetics research company's network.";
	const string CONST_externallyStoredData289 = "subverted a Conservative family forum.";
	const string CONST_externallyStoredData288 = "broke into military networks leaving LCS slogans.";
	const string CONST_externallyStoredData287 = "caused a scare by breaking into a CIA network.";
	const string CONST_externallyStoredData286 = "spread videos of racist police brutality.";
	const string CONST_externallyStoredData285 = "published emails revealing CEO tax evasion.";
	const string CONST_externallyStoredData284 = "revealed huge political bias in INS processes.";
	const string CONST_externallyStoredData283 = "Buying Drinks";
	const string CONST_externallyStoredData281 = "Basketball";
	const string CONST_externallyStoredData280 = "Police Procedure";
	const string CONST_externallyStoredData279 = "Baseball";
	const string CONST_externallyStoredData278 = "Magic";
	const string CONST_externallyStoredData276 = "Weaving";
	const string CONST_externallyStoredData275 = "Fencing";
	const string CONST_externallyStoredData274 = "Computer Science";
	const string CONST_externallyStoredData273 = "Locksmithing";
	const string CONST_externallyStoredData271 = "Education";
	const string CONST_externallyStoredData269 = "Gymnastics";
	const string CONST_externallyStoredData268 = "Kung Fu";
	const string CONST_externallyStoredData267 = "Theatre";
	const string CONST_externallyStoredData266 = "Painting";
	const string CONST_externallyStoredData264 = "Drivers Ed";
	const string CONST_externallyStoredData263 = "Physics";
	const string CONST_externallyStoredData262 = "Criminal Law";
	const string CONST_externallyStoredData260 = "Economics";
	const string CONST_externallyStoredData259 = "Public Policy";
	const string CONST_externallyStoredData258 = "ending the use of torture.";
	const string CONST_externallyStoredData257 = "the Conservative Crime Squad.";
	const string CONST_externallyStoredData256 = "military imperialism.";
	const string CONST_externallyStoredData255 = "gun violence.";
	const string CONST_externallyStoredData254 = "civil rights.";
	const string CONST_externallyStoredData253 = "women's equality.";
	const string CONST_externallyStoredData252 = "drug rights.";
	const string CONST_externallyStoredData251 = "immigrant rights.";
	const string CONST_externallyStoredData250 = "stopping the prisoners' suffering.";
	const string CONST_externallyStoredData249 = "severe income inequality.";
	const string CONST_externallyStoredData248 = "corporate corruption.";
	const string CONST_externallyStoredData247 = "threats to the environment.";
	const string CONST_externallyStoredData246 = "threats to labor rights.";
	const string CONST_externallyStoredData245 = "appointing proper Liberal justices.";
	const string CONST_externallyStoredData244 = "the dangers of genetic engineering.";
	const string CONST_externallyStoredData243 = "protecting free speech.";
	const string CONST_externallyStoredData242 = "civil liberties and personal privacy.";
	const string CONST_externallyStoredData241 = "preventing police brutality.";
	const string CONST_externallyStoredData240 = "brutal animal research practices.";
	const string CONST_externallyStoredData239 = "the dangers of nuclear power.";
	const string CONST_externallyStoredData238 = "the oppressive tax structure.";
	const string CONST_externallyStoredData237 = "the unjust death penalty.";
	const string CONST_externallyStoredData236 = "protecting gay rights.";
	const string CONST_externallyStoredData235 = "Skills Trained: All Weapon Skills, Martial Arts, Dodge, First Aid";
	const string CONST_externallyStoredData234 = "Skills Trained: Computers, Security, Stealth, Disguise, Tailoring,";
	const string CONST_externallyStoredData233 = "Skills Trained: Writing, Persuasion, Law, Street Sense, Science,";
	const string CONST_externallyStoredData232 = "bury dead bodies.";
	const string CONST_externallyStoredData231 = "go to the clinic.";
	const string CONST_externallyStoredData230 = "tend to hostages.";
	const string CONST_externallyStoredData229 = "attempt first aid.";
	const string CONST_externallyStoredData228 = "will augment another Liberal to make them";
	const string CONST_externallyStoredData227 = "try to find a wheelchair.";
	const string CONST_externallyStoredData226 = "repair clothing.";
	const string CONST_externallyStoredData225 = "make clothing.";
	const string CONST_externallyStoredData224 = "try to find and steal a car.";
	const string CONST_externallyStoredData223 = "try to find someone to join the LCS.";
	const string CONST_externallyStoredData222 = "demand money in exchange for not bringing down";
	const string CONST_externallyStoredData221 = "commit credit card fraud online.";
	const string CONST_externallyStoredData220 = "trade sex for money.";
	const string CONST_externallyStoredData219 = "bake and sell special adult brownies that open";
	const string CONST_externallyStoredData218 = "go out into the streets and drum on buckets,";
	const string CONST_externallyStoredData217 = "sketch people and sell portraits back to them.";
	const string CONST_externallyStoredData216 = "tie-dye T-shirts and sell them on the street.";
	const string CONST_externallyStoredData215 = "walk around and ask for donations to the LCS.";
	const string CONST_externallyStoredData214 = "write articles for the LCS's newspaper.";
	const string CONST_externallyStoredData213 = "write letters to newspapers about current events.";
	const string CONST_externallyStoredData212 = "harass websites and hack private networks.";
	const string CONST_externallyStoredData211 = "harass Conservative websites. Computer skill";
	const string CONST_externallyStoredData210 = "search the internet for public opinion polls.";
	const string CONST_externallyStoredData209 = "spray political graffiti. Art and Heart will";
	const string CONST_externallyStoredData208 = "create public disturbances. ";
	const string CONST_externallyStoredData207 = "help the elderly, local library, anything";
	const string CONST_externallyStoredData206 = "helpTopics.txt";
	const string CONST_externallyStoredData205 = "state_biases.txt";
	const string CONST_externallyStoredData204 = "endgameLawStrings.txt";
	const string CONST_externallyStoredData203 = "talkAboutTheIssues.txt";
	const string CONST_externallyStoredData202 = "discussesIssues.txt";
	const string CONST_externallyStoredData201 = "discussIssues.txt";
	const string CONST_externallyStoredData200 = "liberalizeLaw.txt";
	const string CONST_externallyStoredData199 = "conservatiseLaw.txt";
	const string CONST_externallyStoredData198 = "issueEventString.txt";
	const string CONST_externallyStoredData197 = "issueTooLiberal.txt";
	const string CONST_externallyStoredData196 = "youAreStupidTalkAboutIssues.txt";
	const string CONST_externallyStoredData195 = "conservativeLegalArgument.txt";
	const string CONST_externallyStoredData194 = "caseREJECTED_SECONDRATECLOTHES.txt";
	const string CONST_externallyStoredData193 = "caseREJECTED_DAMAGEDCLOTHES.txt";
	const string CONST_externallyStoredData192 = "caseREJECTED_BLOODYCLOTHES.txt";
	const string CONST_externallyStoredData191 = "caseREJECTED_SMELLFUNNY.txt";
	const string CONST_externallyStoredData190 = "caseREJECTED_DRESSCODE.txt";
	const string CONST_externallyStoredData189 = "caseREJECTED_UNDERAGE.txt";
	const string CONST_externallyStoredData188 = "rejectedBecauseGuestList.txt";
	const string CONST_externallyStoredData187 = "rejectedBecauseWeapons.txt";
	const string CONST_externallyStoredData186 = "rejectedBecauseSecondRateClothes.txt";
	const string CONST_externallyStoredData185 = "rejectedBecauseDamagedClothes.txt";
	const string CONST_externallyStoredData184 = "rejectedBecauseBloodyClothes.txt";
	const string CONST_externallyStoredData183 = "rejectedBecauseDresscode.txt";
	const string CONST_externallyStoredData182 = "rejectedBecauseFemaleish.txt";
	const string CONST_externallyStoredData181 = "rejectedBecauseFemale.txt";
	const string CONST_externallyStoredData180 = "rejectedBecauseUnderage.txt";
	const string CONST_externallyStoredData179 = "rejectedBecauseNude.txt";
	const string CONST_externallyStoredData178 = "rejectedByCCS.txt";
	const string CONST_externallyStoredData177 = "VIEWNUM";
	const string CONST_externallyStoredData176 = "VIEW_CONSERVATIVECRIMESQUAD";
	const string CONST_externallyStoredData175 = "VIEW_LIBERALCRIMESQUADPOS";
	const string CONST_externallyStoredData174 = "VIEW_LIBERALCRIMESQUAD";
	const string CONST_externallyStoredData173 = "VIEW_CABLENEWS";
	const string CONST_externallyStoredData172 = "VIEW_AMRADIO";
	const string CONST_externallyStoredData171 = "VIEW_PRISONS";
	const string CONST_externallyStoredData170 = "VIEW_MILITARY";
	const string CONST_externallyStoredData169 = "VIEW_IMMIGRATION";
	const string CONST_externallyStoredData168 = "VIEW_DRUGS";
	const string CONST_externallyStoredData167 = "VIEW_CIVILRIGHTS";
	const string CONST_externallyStoredData166 = "VIEW_WOMEN";
	const string CONST_externallyStoredData165 = "VIEW_CEOSALARY";
	const string CONST_externallyStoredData164 = "VIEW_CORPORATECULTURE";
	const string CONST_externallyStoredData163 = "VIEW_POLLUTION";
	const string CONST_externallyStoredData162 = "VIEW_SWEATSHOPS";
	const string CONST_externallyStoredData161 = "VIEW_GUNCONTROL";
	const string CONST_externallyStoredData160 = "VIEW_JUSTICES";
	const string CONST_externallyStoredData159 = "VIEW_GENETICS";
	const string CONST_externallyStoredData158 = "VIEW_FREESPEECH";
	const string CONST_externallyStoredData157 = "VIEW_INTELLIGENCE";
	const string CONST_externallyStoredData156 = "VIEW_TORTURE";
	const string CONST_externallyStoredData155 = "VIEW_POLICEBEHAVIOR";
	const string CONST_externallyStoredData154 = "VIEW_ANIMALRESEARCH";
	const string CONST_externallyStoredData153 = "VIEW_NUCLEARPOWER";
	const string CONST_externallyStoredData152 = "VIEW_TAXES";
	const string CONST_externallyStoredData151 = "VIEW_DEATHPENALTY";
	const string CONST_externallyStoredData150 = "VIEW_GAY";
	const string CONST_externallyStoredData149 = "VIEW_MOOD";
	const string CONST_externallyStoredData148 = "VIEW_STALIN";
	const string CONST_externallyStoredData147 = "LAWNUM";
	const string CONST_externallyStoredData146 = "LAW_TORTURE";
	const string CONST_externallyStoredData145 = "LAW_PRISONS";
	const string CONST_externallyStoredData144 = "LAW_MILITARY";
	const string CONST_externallyStoredData143 = "LAW_ELECTIONS";
	const string CONST_externallyStoredData142 = "LAW_IMMIGRATION";
	const string CONST_externallyStoredData141 = "LAW_DRUGS";
	const string CONST_externallyStoredData140 = "LAW_CIVILRIGHTS";
	const string CONST_externallyStoredData139 = "LAW_WOMEN";
	const string CONST_externallyStoredData138 = "LAW_TAX";
	const string CONST_externallyStoredData137 = "LAW_GUNCONTROL";
	const string CONST_externallyStoredData136 = "LAW_FLAGBURNING";
	const string CONST_externallyStoredData135 = "LAW_FREESPEECH";
	const string CONST_externallyStoredData134 = "LAW_CORPORATE";
	const string CONST_externallyStoredData133 = "LAW_GAY";
	const string CONST_externallyStoredData132 = "LAW_LABOR";
	const string CONST_externallyStoredData131 = "LAW_POLLUTION";
	const string CONST_externallyStoredData130 = "LAW_NUCLEARPOWER";
	const string CONST_externallyStoredData129 = "LAW_DEATHPENALTY";
	const string CONST_externallyStoredData128 = "LAW_PRIVACY";
	const string CONST_externallyStoredData127 = "LAW_POLICEBEHAVIOR";
	const string CONST_externallyStoredData126 = "LAW_ANIMALRESEARCH";
	const string CONST_externallyStoredData125 = "LAW_ABORTION";
	const string CONST_externallyStoredData124 = "LAW_MOOD";
	const string CONST_externallyStoredData123 = "LAW_STALIN";
	const string CONST_externallyStoredData122 = "theGreatUnknown";
	const string CONST_externallyStoredData121 = "ACTIVITYNUM";
	const string CONST_externallyStoredData120 = "ACTIVITY_AUGMENT";
	const string CONST_externallyStoredData1193 = "OPEN";
	const string CONST_externallyStoredData1192 = "FIRE_END";
	const string CONST_externallyStoredData1191 = "FIRE_PEAK";
	const string CONST_externallyStoredData1190 = "FIRE_START";
	const string CONST_externallyStoredData119 = "ACTIVITY_RECRUITING";
	const string CONST_externallyStoredData1189 = "GRAFFITI_OTHER";
	const string CONST_externallyStoredData1188 = "GRAFFITI_CCS";
	const string CONST_externallyStoredData1187 = "GRAFFITI";
	const string CONST_externallyStoredData1186 = "DEBRIS";
	const string CONST_externallyStoredData1185 = "OUTDOOR";
	const string CONST_externallyStoredData1184 = "GRASSY";
	const string CONST_externallyStoredData1183 = "BLOODY2";
	const string CONST_externallyStoredData1182 = "BLOODY";
	const string CONST_externallyStoredData1181 = "RESTRICTED";
	const string CONST_externallyStoredData1180 = "CLOCK";
	const string CONST_externallyStoredData118 = "ACTIVITY_SLEEPER_JOINLCS";
	const string CONST_externallyStoredData1179 = "KLOCK";
	const string CONST_externallyStoredData1178 = "LOCKED";
	const string CONST_externallyStoredData1177 = "KNOWN";
	const string CONST_externallyStoredData1176 = "DOOR";
	const string CONST_externallyStoredData1175 = "BLOCK";
	const string CONST_externallyStoredData1174 = "EXIT";
	const string CONST_externallyStoredData1173 = "stalinized";
	const string CONST_externallyStoredData1172 = "reaganified";
	const string CONST_externallyStoredData1171 = "defeat";
	const string CONST_externallyStoredData1170 = "victory";
	const string CONST_externallyStoredData117 = "ACTIVITY_SLEEPER_STEAL";
	const string CONST_externallyStoredData1169 = "abort";
	const string CONST_externallyStoredData1168 = "anchor";
	const string CONST_externallyStoredData1167 = "glamshow";
	const string CONST_externallyStoredData1166 = "newscast";
	const string CONST_externallyStoredData1165 = "lacops";
	const string CONST_externallyStoredData1164 = "newspaper";
	const string CONST_externallyStoredData1163 = "recruiting";
	const string CONST_externallyStoredData1162 = "trial";
	const string CONST_externallyStoredData1161 = "footchase";
	const string CONST_externallyStoredData1160 = "carchase";
	const string CONST_externallyStoredData116 = "ACTIVITY_SLEEPER_EMBEZZLE";
	const string CONST_externallyStoredData1159 = "conquer";
	const string CONST_externallyStoredData1158 = "defense";
	const string CONST_externallyStoredData1157 = "heavycombat";
	const string CONST_externallyStoredData1156 = "Pastorale";
	const string CONST_externallyStoredData1155 = "alarmed";
	const string CONST_externallyStoredData1154 = "sitemode";
	const string CONST_externallyStoredData1153 = "shopping";
	const string CONST_externallyStoredData1152 = "elections";
	const string CONST_externallyStoredData1151 = "cartheft";
	const string CONST_externallyStoredData1150 = "finances";
	const string CONST_externallyStoredData115 = "ACTIVITY_SLEEPER_SCANDAL";
	const string CONST_externallyStoredData1149 = "disbanded";
	const string CONST_externallyStoredData1148 = "liberalagenda";
	const string CONST_externallyStoredData1147 = "reviewmode";
	const string CONST_externallyStoredData1146 = "stopevil";
	const string CONST_externallyStoredData1145 = "sleepers";
	const string CONST_externallyStoredData1144 = "activate";
	const string CONST_externallyStoredData1143 = "siege";
	const string CONST_externallyStoredData1142 = "Mars";
	const string CONST_externallyStoredData1141 = "basemode";
	const string CONST_externallyStoredData1140 = "newgame";
	const string CONST_externallyStoredData114 = "ACTIVITY_SLEEPER_RECRUIT";
	const string CONST_externallyStoredData1139 = "titlemode";
	const string CONST_externallyStoredData1138 = "Stalinist";
	const string CONST_externallyStoredData1137 = "Elite Liberal";
	const string CONST_externallyStoredData1136 = "Liberal";
	const string CONST_externallyStoredData1135 = "Moderate";
	const string CONST_externallyStoredData1134 = "Conservative";
	const string CONST_externallyStoredData1133 = "Arch-Conservative";
	const string CONST_externallyStoredData1132 = "CHA";
	const string CONST_externallyStoredData1131 = "HLTH";
	const string CONST_externallyStoredData1130 = "HRT";
	const string CONST_externallyStoredData113 = "ACTIVITY_SLEEPER_SPY";
	const string CONST_externallyStoredData1129 = "INT";
	const string CONST_externallyStoredData1128 = "WIS";
	const string CONST_externallyStoredData1127 = "AGI";
	const string CONST_externallyStoredData1126 = "STR";
	const string CONST_externallyStoredData1125 = "Dodge";
	const string CONST_externallyStoredData1124 = "First Aid";
	const string CONST_externallyStoredData1123 = "Seduction";
	const string CONST_externallyStoredData1122 = "Street Sense";
	const string CONST_externallyStoredData1121 = "Teaching";
	const string CONST_externallyStoredData1120 = "Stealth";
	const string CONST_externallyStoredData112 = "ACTIVITY_SLEEPER_CONSERVATIVE";
	const string CONST_externallyStoredData1119 = "Business";
	const string CONST_externallyStoredData1118 = "Science";
	const string CONST_externallyStoredData1117 = "Religion";
	const string CONST_externallyStoredData1116 = "Art";
	const string CONST_externallyStoredData1115 = "Music";
	const string CONST_externallyStoredData1114 = "Writing";
	const string CONST_externallyStoredData1113 = "Driving";
	const string CONST_externallyStoredData1112 = "Tailoring";
	const string CONST_externallyStoredData1111 = "Law";
	const string CONST_externallyStoredData1110 = "Computers";
	const string CONST_externallyStoredData111 = "ACTIVITY_SLEEPER_LIBERAL";
	const string CONST_externallyStoredData1109 = "Disguise";
	const string CONST_externallyStoredData1108 = "Security";
	const string CONST_externallyStoredData1107 = "Psychology";
	const string CONST_externallyStoredData1106 = "Persuasion";
	const string CONST_externallyStoredData1105 = "SMG";
	const string CONST_externallyStoredData1104 = "Shotgun";
	const string CONST_externallyStoredData1103 = "Heavy Weapons";
	const string CONST_externallyStoredData1102 = "Rifle";
	const string CONST_externallyStoredData1101 = "Pistol";
	const string CONST_externallyStoredData1100 = "Axe";
	const string CONST_externallyStoredData110 = "ACTIVITY_HEAL";
	const string CONST_externallyStoredData1099 = "Club";
	const string CONST_externallyStoredData1098 = "Throwing";
	const string CONST_externallyStoredData1097 = "Sword";
	const string CONST_externallyStoredData1096 = "Knife";
	const string CONST_externallyStoredData1095 = "Martial Arts";
	const string CONST_externallyStoredData1094 = "F - Slam the brakes!";
	const string CONST_externallyStoredData1093 = "D - Swerve around him!";
	const string CONST_externallyStoredData1092 = "A kid runs into the street for his ball!";
	const string CONST_externallyStoredData1091 = "F - Slow down and turn!";
	const string CONST_externallyStoredData1090 = "D - Run the light anyway!";
	const string CONST_externallyStoredData109 = "ACTIVITY_CLINIC";
	const string CONST_externallyStoredData1089 = "There's a red light with cross traffic ahead!";
	const string CONST_externallyStoredData1088 = "F - Slow down!";
	const string CONST_externallyStoredData1087 = "D - Speed around it!";
	const string CONST_externallyStoredData1086 = "A truck pulls out in your path!";
	const string CONST_externallyStoredData1085 = "F - Play it safe and plow through it!";
	const string CONST_externallyStoredData1084 = "D - Swerve to avoid hitting anyone!";
	const string CONST_externallyStoredData1083 = "You are speeding toward a flimsy fruit stand!";
	const string CONST_externallyStoredData1082 = "Washington, DC";
	const string CONST_externallyStoredData1081 = "Miami, FL";
	const string CONST_externallyStoredData1080 = "Atlanta, GA";
	const string CONST_externallyStoredData108 = "ACTIVITY_STUDY_SEDUCTION";
	const string CONST_externallyStoredData1079 = "Detroit, MI";
	const string CONST_externallyStoredData1078 = "Chicago, IL";
	const string CONST_externallyStoredData1077 = "Los Angeles, CA";
	const string CONST_externallyStoredData1076 = "New York, NY";
	const string CONST_externallyStoredData1075 = "Seattle, WA";
	const string CONST_externallyStoredData1074 = "were murdered trying to escape from a police siege yesterday, according ";
	const string CONST_externallyStoredData1073 = "were slain trying to escape from a police siege yesterday, according ";
	const string CONST_externallyStoredData1072 = "were murdered during a police raid yesterday, according ";
	const string CONST_externallyStoredData1071 = "were slain during a police raid yesterday, according ";
	const string CONST_externallyStoredData1070 = "violently broke a police siege yesterday, according ";
	const string CONST_externallyStoredData107 = "ACTIVITY_STUDY_STEALTH";
	const string CONST_externallyStoredData1069 = "fought off a police raid yesterday, according ";
	const string CONST_externallyStoredData1068 = "escaped from police officers during a raid yesterday, according ";
	const string CONST_externallyStoredData1067 = "escaped from a police siege yesterday, according ";
	const string CONST_externallyStoredData1066 = "The Stalinist Party claims victory!";
	const string CONST_externallyStoredData1065 = "The Progressive Elite Social Liberal Green Party claims victory!";
	const string CONST_externallyStoredData1064 = "The Liberal Party claims victory!";
	const string CONST_externallyStoredData1063 = "The next two years promise to be more of the same.";
	const string CONST_externallyStoredData1062 = "The Conservative Party claims victory!";
	const string CONST_externallyStoredData1061 = "The $$ U.S.A. Flag Eagle $$ Conservative Tea Party claims victory!";
	const string CONST_externallyStoredData1060 = "thought political violence was justified";
	const string CONST_externallyStoredData106 = "ACTIVITY_STUDY_THROWING";
	const string CONST_externallyStoredData1059 = "have a negative opinion of cable news programs";
	const string CONST_externallyStoredData1058 = "do not like AM radio";
	const string CONST_externallyStoredData1057 = "wanted to end prisoner abuse and torture";
	const string CONST_externallyStoredData1056 = "held the Conservative Crime Squad in contempt";
	const string CONST_externallyStoredData1055 = "of these held the Liberal Crime Squad in high regard";
	const string CONST_externallyStoredData1054 = "respected the power of the Liberal Crime Squad";
	const string CONST_externallyStoredData1053 = "opposed increasing military spending";
	const string CONST_externallyStoredData1052 = "are concerned about gun violence";
	const string CONST_externallyStoredData1051 = "felt more work was needed for racial equality";
	const string CONST_externallyStoredData1050 = "favored doing more for gender equality";
	const string CONST_externallyStoredData105 = "ACTIVITY_STUDY_STREETSENSE";
	const string CONST_externallyStoredData1049 = "believed that CEO salaries are too great";
	const string CONST_externallyStoredData1048 = "were disgusted by corporate malfeasance";
	const string CONST_externallyStoredData1047 = "thought industry should lower pollution";
	const string CONST_externallyStoredData1046 = "would boycott companies that used sweatshops";
	const string CONST_externallyStoredData1045 = "were for the appointment of Liberal justices";
	const string CONST_externallyStoredData1044 = "abhorred genetically altered food products";
	const string CONST_externallyStoredData1043 = "believed in unfettered free speech";
	const string CONST_externallyStoredData1042 = "thought the intelligence community invades privacy";
	const string CONST_externallyStoredData1041 = "wanted stronger measures to prevent torture";
	const string CONST_externallyStoredData1040 = "were critical of the police";
	const string CONST_externallyStoredData104 = "ACTIVITY_STUDY_CLUB";
	const string CONST_externallyStoredData1039 = "deplored animal research";
	const string CONST_externallyStoredData1038 = "were terrified of nuclear power";
	const string CONST_externallyStoredData1037 = "were against cutting taxes";
	const string CONST_externallyStoredData1036 = "opposed the death penalty";
	const string CONST_externallyStoredData1035 = "were in favor of equal rights for homosexuals";
	const string CONST_externallyStoredData1034 = "left leg";
	const string CONST_externallyStoredData1033 = "right leg";
	const string CONST_externallyStoredData1032 = "left arm";
	const string CONST_externallyStoredData1031 = "right arm";
	const string CONST_externallyStoredData1030 = "left rear leg";
	const string CONST_externallyStoredData103 = "ACTIVITY_STUDY_RELIGION";
	const string CONST_externallyStoredData1029 = "right rear leg";
	const string CONST_externallyStoredData1028 = "left front leg";
	const string CONST_externallyStoredData1027 = "right front leg";
	const string CONST_externallyStoredData1026 = "left tread";
	const string CONST_externallyStoredData1025 = "right tread";
	const string CONST_externallyStoredData1024 = "left side";
	const string CONST_externallyStoredData1023 = "right side";
	const string CONST_externallyStoredData1022 = "front";
	const string CONST_externallyStoredData1021 = "turret";
	const string CONST_externallyStoredData1020 = "SPECIALWOUND_LOWERSPINE";
	const string CONST_externallyStoredData102 = "ACTIVITY_STUDY_WEAVING";
	const string CONST_externallyStoredData1019 = "SPECIALWOUND_UPPERSPINE";
	const string CONST_externallyStoredData1018 = "SPECIALWOUND_NECK";
	const string CONST_externallyStoredData1017 = "SPECIALWOUND_RIBS";
	const string CONST_externallyStoredData1016 = "SPECIALWOUND_SPLEEN";
	const string CONST_externallyStoredData1015 = "SPECIALWOUND_LEFTKIDNEY";
	const string CONST_externallyStoredData1014 = "SPECIALWOUND_RIGHTKIDNEY";
	const string CONST_externallyStoredData1013 = "SPECIALWOUND_STOMACH";
	const string CONST_externallyStoredData1012 = "SPECIALWOUND_LIVER";
	const string CONST_externallyStoredData1011 = "SPECIALWOUND_HEART";
	const string CONST_externallyStoredData1010 = "SPECIALWOUND_LEFTLUNG";
	const string CONST_externallyStoredData101 = "ACTIVITY_STUDY_FENCING";
	const string CONST_externallyStoredData1009 = "SPECIALWOUND_RIGHTLUNG";
	const string CONST_externallyStoredData1008 = "SPECIALWOUND_TONGUE";
	const string CONST_externallyStoredData1007 = "SPECIALWOUND_NOSE";
	const string CONST_externallyStoredData1006 = "SPECIALWOUND_LEFTEYE";
	const string CONST_externallyStoredData1005 = "SPECIALWOUND_RIGHTEYE";
	const string CONST_externallyStoredData1004 = "SPECIALWOUND_TEETH";
	const string CONST_externallyStoredData1003 = "SITE_GOVERNMENT_WHITE_HOUSE";
	const string CONST_externallyStoredData1002 = "SITE_GOVERNMENT_LIBERAL_PARTY_HQ";
	const string CONST_externallyStoredData1001 = "SITE_BUSINESS_BANK";
	const string CONST_externallyStoredData1000 = "SITE_GOVERNMENT_ARMYBASE";
	const string CONST_externallyStoredData100 = "ACTIVITY_STUDY_COMPUTERS";
	const string CONST_externallyStoredData099 = "ACTIVITY_STUDY_LOCKSMITHING";
	const string CONST_externallyStoredData098 = "ACTIVITY_STUDY_WRITING";
	const string CONST_externallyStoredData097 = "ACTIVITY_STUDY_TEACHING";
	const string CONST_externallyStoredData096 = "ACTIVITY_STUDY_ART";
	const string CONST_externallyStoredData095 = "ACTIVITY_STUDY_MUSIC";
	const string CONST_externallyStoredData094 = "ACTIVITY_STUDY_GYMNASTICS";
	const string CONST_externallyStoredData093 = "ACTIVITY_STUDY_BUSINESS";
	const string CONST_externallyStoredData092 = "ACTIVITY_STUDY_SCIENCE";
	const string CONST_externallyStoredData091 = "ACTIVITY_STUDY_DISGUISE";
	const string CONST_externallyStoredData090 = "ACTIVITY_STUDY_LAW";
	const string CONST_externallyStoredData089 = "ACTIVITY_STUDY_FIRST_AID";
	const string CONST_externallyStoredData088 = "ACTIVITY_STUDY_PSYCHOLOGY";
	const string CONST_externallyStoredData087 = "ACTIVITY_STUDY_DRIVING";
	const string CONST_externallyStoredData086 = "ACTIVITY_STUDY_MARTIAL_ARTS";
	const string CONST_externallyStoredData085 = "ACTIVITY_STUDY_DEBATING";
	const string CONST_externallyStoredData084 = "ACTIVITY_TEACH_COVERT";
	const string CONST_externallyStoredData083 = "ACTIVITY_TEACH_FIGHTING";
	const string CONST_externallyStoredData082 = "ACTIVITY_TEACH_POLITICS";
	const string CONST_externallyStoredData081 = "ACTIVITY_WRITE_GUARDIAN";
	const string CONST_externallyStoredData080 = "ACTIVITY_WRITE_LETTERS";
	const string CONST_externallyStoredData079 = "ACTIVITY_WRITE_BLOG";
	const string CONST_externallyStoredData078 = "ACTIVITY_BURY";
	const string CONST_externallyStoredData077 = "ACTIVITY_WHEELCHAIR";
	const string CONST_externallyStoredData076 = "ACTIVITY_STEALCARS";
	const string CONST_externallyStoredData075 = "ACTIVITY_MAKE_ARMOR";
	const string CONST_externallyStoredData074 = "ACTIVITY_REPAIR_ARMOR";
	const string CONST_externallyStoredData073 = "ACTIVITY_HACKING";
	const string CONST_externallyStoredData072 = "ACTIVITY_DOS_ATTACKS";
	const string CONST_externallyStoredData071 = "ACTIVITY_DOS_RACKET";
	const string CONST_externallyStoredData070 = "ACTIVITY_CCFRAUD";
	const string CONST_externallyStoredData069 = "ACTIVITY_POLLS";
	const string CONST_externallyStoredData068 = "ACTIVITY_PROSTITUTION";
	const string CONST_externallyStoredData067 = "ACTIVITY_SELL_DRUGS";
	const string CONST_externallyStoredData066 = "ACTIVITY_DONATIONS";
	const string CONST_externallyStoredData065 = "ACTIVITY_SELL_TSHIRTS";
	const string CONST_externallyStoredData064 = "ACTIVITY_SELL_MUSIC";
	const string CONST_externallyStoredData063 = "ACTIVITY_SELL_ART";
	const string CONST_externallyStoredData062 = "ACTIVITY_COMMUNITYSERVICE";
	const string CONST_externallyStoredData061 = "ACTIVITY_GRAFFITI";
	const string CONST_externallyStoredData060 = "ACTIVITY_TROUBLE";
	const string CONST_externallyStoredData059 = "ACTIVITY_HOSTAGETENDING";
	const string CONST_externallyStoredData058 = "ACTIVITY_VISIT";
	const string CONST_externallyStoredData057 = "ACTIVITY_NONE";
	const string CONST_externallyStoredData056 = " ";

	const string tag_LOOT = "LOOT";
	const string tag_dating = "dating";
	const string tag_interrogation = "interrogation";
	const string tag_suspicious = "suspicious";
	const string tag_body = "body";
	const string tag_head = "head";
	const string tag_Travel = "Travel";
	const string tag_City_Outskirts = "City Outskirts";
	const string tag_Outskirts = "Outskirts";
	const string tag_i_District = "I-District";
	const string tag_Industrial_District = "Industrial District";
	const string tag_Shopping = "Shopping";
	const string tag_University_District = "University District";
	const string tag_u_District = "U-District";
	const string tag_D = "D";
	const string tag_Downtown = "Downtown";
	const string tag_DC = "DC";
	const string tag_Miami = "Miami";
	const string tag_MI = "MI";
	const string tag_ATL = "ATL";
	const string tag_Atlanta = "Atlanta";
	const string tag_DET = "DET";
	const string tag_Detroit = "Detroit";
	const string tag_Chicago = "Chicago";
	const string tag_CHI = "CHI";
	const string tag_NYC = "NYC";
	const string tag_LA = "LA";
	const string tag_SEA = "SEA";
	const string tag_Seattle = "Seattle";
	const string tag_LOOT_TRINKET = "LOOT_TRINKET";
	const string tag_LOOT_SILVERWARE = "LOOT_SILVERWARE";
	const string tag_LOOT_WATCH = "LOOT_WATCH";
	const string tag_LOOT_MICROPHONE = "LOOT_MICROPHONE";
	const string tag_LOOT_CELLPHONE = "LOOT_CELLPHONE";
	const string tag_LOOT_EXPENSIVEJEWELERY = "LOOT_EXPENSIVEJEWELERY";
	const string tag_LOOT_POLICERECORDS = "LOOT_POLICERECORDS";
	const string tag_LOOT_AMRADIOFILES = "LOOT_AMRADIOFILES";
	const string tag_LOOT_CABLENEWSFILES = "LOOT_CABLENEWSFILES";
	const string tag_LOOT_PRISONFILES = "LOOT_PRISONFILES";
	const string tag_LOOT_RESEARCHFILES = "LOOT_RESEARCHFILES";
	const string tag_LOOT_JUDGEFILES = "LOOT_JUDGEFILES";
	const string tag_LOOT_CORPFILES = "LOOT_CORPFILES";
	const string tag_LOOT_INTHQDISK = "LOOT_INTHQDISK";
	const string tag_LOOT_CEOPHOTOS = "LOOT_CEOPHOTOS";
	const string tag_LOOT_SECRETDOCUMENTS = "LOOT_SECRETDOCUMENTS";
	const string tag_LOOT_CHEAPJEWELERY = "LOOT_CHEAPJEWELERY";
	const string tag_LOOT_COMPUTER = "LOOT_COMPUTER";
	const string tag_LOOT_LABEQUIPMENT = "LOOT_LABEQUIPMENT";
	const string tag_LOOT_PDA = "LOOT_PDA";
	const string tag_LOOT_CHEMICAL = "LOOT_CHEMICAL";
	const string tag_LOOT_FINECLOTH = "LOOT_FINECLOTH";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";


#include "../creature/creature.h"
#include "../locations/locations.h"
#include "../common/ledgerEnums.h"
#include "../customMaps.h"
#include "../set_color_support.h"
	file_and_text_collection customText(vector<string>  *collection_, string fileName_) {
		file_and_text_collection newWound;
		newWound.collection = collection_;
		newWound.fileName = fileName_;
		newWound.superCollection = false;
		return newWound;
	}
	file_and_text_collection customText(string fileName_) {
		file_and_text_collection newWound;
		vector<string> vsr;
		vsr.push_back(CONST_externallyStoredData056);
		newWound.collection = &vsr;
		newWound.fileName = fileName_;
		newWound.superCollection = false;
		return newWound;
	}
	file_and_text_collection customText(vector<vector<string> >  *collection_, string fileName_, int dimensions_) {
		file_and_text_collection newWound;
		newWound.super_collection = collection_;
		newWound.fileName = fileName_;
		newWound.dimensions = dimensions_;
		newWound.superCollection = true;
		return newWound;
	}
	file_and_text_collection customText(string fileName_, int dimensions_) {
		file_and_text_collection newWound;
		newWound.fileName = fileName_;
		newWound.dimensions = dimensions_;
		newWound.superCollection = true;
		return newWound;
	}
	struct stringAndColor
	{
		string str;
		ColorSetup type;
		stringAndColor(string str_, ColorSetup type_) : str(str_), type(type_) { }
		stringAndColor(ColorSetup type_, string str_) : str(str_), type(type_) { }
	};
	int getLawFromFlag(int type);

	// from activities.cpp
	//extern string study_string1;
	//extern string study_string2;
	extern  map<Activity, Data_Activity> data_activities;
	extern map< Views, stringConnectedToView > pollingData;
	extern map< Activity, CreatureSkill> trainingActivity;
	extern vector<ActivityAndString> data_lessons;
	extern vector<activityData> hackingActivities;
	extern map<char, vector<ActivityAndString> > activate_menu_items;
	extern vector<RecruitData> recruitable_creatures;
	extern map<short, string> trainingActivitySorting;
	extern map<short, string> incomeTypes;
	extern map<short, string> expenseTypes;
	extern map<short, string> siteReadMap;
	extern map<short, string> buildThisSite;
	extern map<string, short> getSpecial;
	extern map<string, short> getUnique;
	extern map<string, string> getLootString;
	extern map<short, string> reviewStrings;
	extern map<short, string> reviewStringsSecondLine;
	extern vector<stringAndColor> liberalListAndColor;
	extern map<short, string> issueEventString;
	extern map<short, string> conservatiseLaw;
	extern map<short, string> liberalizeLaw;
	extern map<short, string> discussIssues;
	extern map<short, string> discussesIssues;
	extern map<short, string> getCityDescription;
	extern map<short, vector<string> > getSiteName;
	extern map<short, vector<string> > endgameLawStrings;
	extern map<short, string> getActivityString;
	extern map<short, vector<string> > getViewString;
	extern map<short, string> getLawString;
	extern map<short, string> getLawFlagString;
	extern map<short, map<short, string> > getLawFlagStringFull;
	extern vector<int> state_biases;
	extern map<short, string> enumToCreature;
	extern map<string, short> getSkillEnumFromString;
	extern map<string, short> getAttributeEnumFromString;
	extern map<string, short> getCreatureEnumFromString;
	extern map<string, short> getBaseEnumFromString;
	extern map<string, short> getSpecialWoundEnumFromString;
	extern map<short, string> conservativeLegalArgument;
	extern map<short, string> youAreStupidTalkAboutIssues;
	extern map<short, string> issueTooLiberal;
	extern map<short, vector<string> > talkAboutTheIssues;
	extern map<short, string> tankBodyParts;
	extern map<short, string> animalBodyParts;
	extern map<short, string> humanBodyParts;
	extern map<short, string> supportsLiberalLaw;
	extern map<short, string> winnerOfElection;
	extern map<short, vector<string> > newsStories;
	extern map<short, string> cityNames;
	extern map<short, vector<string> > carchaseObstacles;
	extern map<short, string> skillEnumToString;
	extern map<short, string> attEnumToString;
	extern map<short, string> getAlignString;
	extern map<short, string> musicList;
	extern vector<CreatureTypes> ACTIVITY_TEACH_POLITICS_DEFAULT;
	extern vector<CreatureTypes> ACTIVITY_TEACH_COVERT_DEFAULT;
	extern vector<CreatureTypes> ACTIVITY_TEACH_FIGHTING_DEFAULT;
	vector<string> conservativeLegalArgumentUnprocessed;
	vector<string> youAreStupidTalkAboutIssuesUnprocessed;
	vector<string> issueTooLiberalUnprocessed;
	vector<string> issueEventStringUnprocessed;
	vector<string> conservatiseLawUnprocessed;
	vector<string> liberalizeLawUnprocessed;
	vector<string> discussIssuesUnprocessed;
	vector<string> discussesIssuesUnprocessed;
	vector<string> talkAboutTheIssuesUnprocessed;
	vector<string> endgameLawStringsUnprocessed;
	vector<string> helpTopicUnprocessed;
	extern map<short, vector<string> > helpTopics;
	extern vector<string> theGreatUnknown;
	vector<string> state_biases_Unprocessed;
	map<string, short> string_to_activity = {
		map<string, short>::value_type(CONST_externallyStoredData057, ACTIVITY_NONE),
		map<string, short>::value_type(CONST_externallyStoredData058, ACTIVITY_VISIT),
		map<string, short>::value_type(CONST_externallyStoredData059, ACTIVITY_HOSTAGETENDING),
		map<string, short>::value_type(CONST_externallyStoredData060, ACTIVITY_TROUBLE),
		map<string, short>::value_type(CONST_externallyStoredData061, ACTIVITY_GRAFFITI),
		map<string, short>::value_type(CONST_externallyStoredData062, ACTIVITY_COMMUNITYSERVICE),
		map<string, short>::value_type(CONST_externallyStoredData063, ACTIVITY_SELL_ART),
		map<string, short>::value_type(CONST_externallyStoredData064, ACTIVITY_SELL_MUSIC),
		map<string, short>::value_type(CONST_externallyStoredData065, ACTIVITY_SELL_TSHIRTS),
		map<string, short>::value_type(CONST_externallyStoredData066, ACTIVITY_DONATIONS),
		map<string, short>::value_type(CONST_externallyStoredData067, ACTIVITY_SELL_DRUGS),
		map<string, short>::value_type(CONST_externallyStoredData068, ACTIVITY_PROSTITUTION),
		map<string, short>::value_type(CONST_externallyStoredData069, ACTIVITY_POLLS),
		map<string, short>::value_type(CONST_externallyStoredData070, ACTIVITY_CCFRAUD),
		map<string, short>::value_type(CONST_externallyStoredData071, ACTIVITY_DOS_RACKET),
		map<string, short>::value_type(CONST_externallyStoredData072, ACTIVITY_DOS_ATTACKS),
		map<string, short>::value_type(CONST_externallyStoredData073, ACTIVITY_HACKING),
		map<string, short>::value_type(CONST_externallyStoredData074, ACTIVITY_REPAIR_ARMOR),
		map<string, short>::value_type(CONST_externallyStoredData075, ACTIVITY_MAKE_ARMOR),
		map<string, short>::value_type(CONST_externallyStoredData076, ACTIVITY_STEALCARS),
		map<string, short>::value_type(CONST_externallyStoredData077, ACTIVITY_WHEELCHAIR),
		map<string, short>::value_type(CONST_externallyStoredData078, ACTIVITY_BURY),
		map<string, short>::value_type(CONST_externallyStoredData079, ACTIVITY_WRITE_BLOG),
		map<string, short>::value_type(CONST_externallyStoredData080, ACTIVITY_WRITE_LETTERS),
		map<string, short>::value_type(CONST_externallyStoredData081, ACTIVITY_WRITE_GUARDIAN),
		map<string, short>::value_type(CONST_externallyStoredData082, ACTIVITY_TEACH_POLITICS),
		map<string, short>::value_type(CONST_externallyStoredData083, ACTIVITY_TEACH_FIGHTING),
		map<string, short>::value_type(CONST_externallyStoredData084, ACTIVITY_TEACH_COVERT),
		map<string, short>::value_type(CONST_externallyStoredData085, ACTIVITY_STUDY_DEBATING),
		map<string, short>::value_type(CONST_externallyStoredData086, ACTIVITY_STUDY_MARTIAL_ARTS),
		map<string, short>::value_type(CONST_externallyStoredData087, ACTIVITY_STUDY_DRIVING),
		map<string, short>::value_type(CONST_externallyStoredData088, ACTIVITY_STUDY_PSYCHOLOGY),
		map<string, short>::value_type(CONST_externallyStoredData089, ACTIVITY_STUDY_FIRST_AID),
		map<string, short>::value_type(CONST_externallyStoredData090, ACTIVITY_STUDY_LAW),
		map<string, short>::value_type(CONST_externallyStoredData091, ACTIVITY_STUDY_DISGUISE),
		map<string, short>::value_type(CONST_externallyStoredData092, ACTIVITY_STUDY_SCIENCE),
		map<string, short>::value_type(CONST_externallyStoredData093, ACTIVITY_STUDY_BUSINESS),
		map<string, short>::value_type(CONST_externallyStoredData094, ACTIVITY_STUDY_GYMNASTICS),
		map<string, short>::value_type(CONST_externallyStoredData095, ACTIVITY_STUDY_MUSIC),
		map<string, short>::value_type(CONST_externallyStoredData096, ACTIVITY_STUDY_ART),
		map<string, short>::value_type(CONST_externallyStoredData097, ACTIVITY_STUDY_TEACHING),
		map<string, short>::value_type(CONST_externallyStoredData098, ACTIVITY_STUDY_WRITING),
		map<string, short>::value_type(CONST_externallyStoredData099, ACTIVITY_STUDY_LOCKSMITHING),
		map<string, short>::value_type(CONST_externallyStoredData100, ACTIVITY_STUDY_COMPUTERS),
		//ACTIVITY_STUDY_COOKING
		map<string, short>::value_type(CONST_externallyStoredData101, ACTIVITY_STUDY_FENCING),
		map<string, short>::value_type(CONST_externallyStoredData102, ACTIVITY_STUDY_WEAVING),
		map<string, short>::value_type(CONST_externallyStoredData103, ACTIVITY_STUDY_RELIGION),
		//ACTIVITY_STUDY_MAGIC
		map<string, short>::value_type(CONST_externallyStoredData104, ACTIVITY_STUDY_CLUB),
		map<string, short>::value_type(CONST_externallyStoredData105, ACTIVITY_STUDY_STREETSENSE),
		map<string, short>::value_type(CONST_externallyStoredData106, ACTIVITY_STUDY_THROWING),
		map<string, short>::value_type(CONST_externallyStoredData107, ACTIVITY_STUDY_STEALTH),
		map<string, short>::value_type(CONST_externallyStoredData108, ACTIVITY_STUDY_SEDUCTION),
		map<string, short>::value_type(CONST_externallyStoredData109, ACTIVITY_CLINIC),
		map<string, short>::value_type(CONST_externallyStoredData110, ACTIVITY_HEAL),
		map<string, short>::value_type(CONST_externallyStoredData111, ACTIVITY_SLEEPER_LIBERAL),
		map<string, short>::value_type(CONST_externallyStoredData112, ACTIVITY_SLEEPER_CONSERVATIVE),
		map<string, short>::value_type(CONST_externallyStoredData113, ACTIVITY_SLEEPER_SPY),
		map<string, short>::value_type(CONST_externallyStoredData114, ACTIVITY_SLEEPER_RECRUIT),
		map<string, short>::value_type(CONST_externallyStoredData115, ACTIVITY_SLEEPER_SCANDAL),
		map<string, short>::value_type(CONST_externallyStoredData116, ACTIVITY_SLEEPER_EMBEZZLE),
		map<string, short>::value_type(CONST_externallyStoredData117, ACTIVITY_SLEEPER_STEAL),
		map<string, short>::value_type(CONST_externallyStoredData118, ACTIVITY_SLEEPER_JOINLCS),
		map<string, short>::value_type(CONST_externallyStoredData119, ACTIVITY_RECRUITING),
		map<string, short>::value_type(CONST_externallyStoredData120, ACTIVITY_AUGMENT),
		map<string, short>::value_type(CONST_externallyStoredData121, ACTIVITYNUM),
		map<string, short>::value_type(CONST_externallyStoredData122, -1),
	};
	map<string, short> string_to_law = {
		map<string, short>::value_type(CONST_externallyStoredData123, LAW_STALIN),
		map<string, short>::value_type(CONST_externallyStoredData124, LAW_MOOD),
		map<string, short>::value_type(CONST_externallyStoredData125, LAW_ABORTION),
		map<string, short>::value_type(CONST_externallyStoredData126, LAW_ANIMALRESEARCH),
		map<string, short>::value_type(CONST_externallyStoredData127, LAW_POLICEBEHAVIOR),
		map<string, short>::value_type(CONST_externallyStoredData128, LAW_PRIVACY),
		map<string, short>::value_type(CONST_externallyStoredData129, LAW_DEATHPENALTY),
		map<string, short>::value_type(CONST_externallyStoredData130, LAW_NUCLEARPOWER),
		map<string, short>::value_type(CONST_externallyStoredData131, LAW_POLLUTION),
		map<string, short>::value_type(CONST_externallyStoredData132, LAW_LABOR),
		map<string, short>::value_type(CONST_externallyStoredData133, LAW_GAY),
		map<string, short>::value_type(CONST_externallyStoredData134, LAW_CORPORATE),
		map<string, short>::value_type(CONST_externallyStoredData135, LAW_FREESPEECH),
		map<string, short>::value_type(CONST_externallyStoredData136, LAW_FLAGBURNING),
		map<string, short>::value_type(CONST_externallyStoredData137, LAW_GUNCONTROL),
		map<string, short>::value_type(CONST_externallyStoredData138, LAW_TAX),
		map<string, short>::value_type(CONST_externallyStoredData139, LAW_WOMEN),
		map<string, short>::value_type(CONST_externallyStoredData140, LAW_CIVILRIGHTS),
		map<string, short>::value_type(CONST_externallyStoredData141, LAW_DRUGS),
		map<string, short>::value_type(CONST_externallyStoredData142, LAW_IMMIGRATION),
		map<string, short>::value_type(CONST_externallyStoredData143, LAW_ELECTIONS),
		map<string, short>::value_type(CONST_externallyStoredData144, LAW_MILITARY),
		map<string, short>::value_type(CONST_externallyStoredData145, LAW_PRISONS),
		map<string, short>::value_type(CONST_externallyStoredData146, LAW_TORTURE),
		map<string, short>::value_type(CONST_externallyStoredData147, LAWNUM),
	};
	map<string, short> string_to_view = {
		map<string, short>::value_type(CONST_externallyStoredData148, VIEW_STALIN),
		map<string, short>::value_type(CONST_externallyStoredData149, VIEW_MOOD),
		map<string, short>::value_type(CONST_externallyStoredData150, VIEW_GAY),
		map<string, short>::value_type(CONST_externallyStoredData151, VIEW_DEATHPENALTY),
		map<string, short>::value_type(CONST_externallyStoredData152, VIEW_TAXES),
		map<string, short>::value_type(CONST_externallyStoredData153, VIEW_NUCLEARPOWER),
		map<string, short>::value_type(CONST_externallyStoredData154, VIEW_ANIMALRESEARCH),
		map<string, short>::value_type(CONST_externallyStoredData155, VIEW_POLICEBEHAVIOR),
		map<string, short>::value_type(CONST_externallyStoredData156, VIEW_TORTURE),
		map<string, short>::value_type(CONST_externallyStoredData157, VIEW_INTELLIGENCE),
		map<string, short>::value_type(CONST_externallyStoredData158, VIEW_FREESPEECH),
		map<string, short>::value_type(CONST_externallyStoredData159, VIEW_GENETICS),
		map<string, short>::value_type(CONST_externallyStoredData160, VIEW_JUSTICES),
		map<string, short>::value_type(CONST_externallyStoredData161, VIEW_GUNCONTROL),
		map<string, short>::value_type(CONST_externallyStoredData162, VIEW_SWEATSHOPS),
		map<string, short>::value_type(CONST_externallyStoredData163, VIEW_POLLUTION),
		map<string, short>::value_type(CONST_externallyStoredData164, VIEW_CORPORATECULTURE),
		map<string, short>::value_type(CONST_externallyStoredData165, VIEW_CEOSALARY),
		map<string, short>::value_type(CONST_externallyStoredData166, VIEW_WOMEN),
		map<string, short>::value_type(CONST_externallyStoredData167, VIEW_CIVILRIGHTS),
		map<string, short>::value_type(CONST_externallyStoredData168, VIEW_DRUGS),
		map<string, short>::value_type(CONST_externallyStoredData169, VIEW_IMMIGRATION),
		map<string, short>::value_type(CONST_externallyStoredData170, VIEW_MILITARY),
		map<string, short>::value_type(CONST_externallyStoredData171, VIEW_PRISONS),
		map<string, short>::value_type(CONST_externallyStoredData172, VIEW_AMRADIO),
		map<string, short>::value_type(CONST_externallyStoredData173, VIEW_CABLENEWS),
		map<string, short>::value_type(CONST_externallyStoredData174, VIEW_LIBERALCRIMESQUAD),
		map<string, short>::value_type(CONST_externallyStoredData175, VIEW_LIBERALCRIMESQUADPOS),
		map<string, short>::value_type(CONST_externallyStoredData176, VIEW_CONSERVATIVECRIMESQUAD),
		map<string, short>::value_type(CONST_externallyStoredData177, VIEWNUM),
	};
	// TODO these should have error detection, but that is kinda low priority
	void processTheUnprocessed(vector<string> &unprocessed, map<short, string> &processed, map<string, short> string_to_short);
	void processTheUnprocessed(vector<string> &unprocessed, map<short, vector<string> > &processed, map<string, short> string_to_short);
	extern map<string, short> site_tile_list;
	extern map<int, vector<string> > rejectionReasons;
	extern map<int, vector<string> > caseRejectionReasons;
	vector<string> rejectedByCCS;
	vector<string> rejectedBecauseNude;
	vector<string> rejectedBecauseUnderage;
	vector<string> rejectedBecauseFemale;
	vector<string> rejectedBecauseFemaleish;
	vector<string> rejectedBecauseDresscode;
	vector<string> rejectedBecauseBloodyClothes;
	vector<string> rejectedBecauseDamagedClothes;
	vector<string> rejectedBecauseSecondRateClothes;
	vector<string> rejectedBecauseWeapons;
	vector<string> rejectedBecauseGuestList;
	// the vector<string> 'caseREJECTED' and 'rejected' are similar but not identicle.
	// TODO the precise differences should be made more apparant
	vector<string> caseREJECTED_UNDERAGE;
	vector<string> caseREJECTED_DRESSCODE;
	vector<string> caseREJECTED_SMELLFUNNY;
	vector<string> caseREJECTED_BLOODYCLOTHES;
	vector<string> caseREJECTED_DAMAGEDCLOTHES;
	vector<string> caseREJECTED_SECONDRATECLOTHES;
	vector<file_and_text_collection> externally_stored_data_text_file_collection = {
		customText(&rejectedByCCS, mostlyendings + CONST_externallyStoredData178),
		customText(&rejectedBecauseNude, mostlyendings + CONST_externallyStoredData179),
		customText(&rejectedBecauseUnderage, mostlyendings + CONST_externallyStoredData180),
		customText(&rejectedBecauseFemale, mostlyendings + CONST_externallyStoredData181),
		customText(&rejectedBecauseFemaleish, mostlyendings + CONST_externallyStoredData182),
		customText(&rejectedBecauseDresscode, mostlyendings + CONST_externallyStoredData183),
		customText(&rejectedBecauseBloodyClothes, mostlyendings + CONST_externallyStoredData184),
		customText(&rejectedBecauseDamagedClothes, mostlyendings + CONST_externallyStoredData185),
		customText(&rejectedBecauseSecondRateClothes, mostlyendings + CONST_externallyStoredData186),
		customText(&rejectedBecauseWeapons, mostlyendings + CONST_externallyStoredData187),
		customText(&rejectedBecauseGuestList, mostlyendings + CONST_externallyStoredData188),
		customText(&caseREJECTED_UNDERAGE, mostlyendings + CONST_externallyStoredData189),
		customText(&caseREJECTED_DRESSCODE, mostlyendings + CONST_externallyStoredData190),
		customText(&caseREJECTED_SMELLFUNNY, mostlyendings + CONST_externallyStoredData191),
		customText(&caseREJECTED_BLOODYCLOTHES, mostlyendings + CONST_externallyStoredData192),
		customText(&caseREJECTED_DAMAGEDCLOTHES, mostlyendings + CONST_externallyStoredData193),
		customText(&caseREJECTED_SECONDRATECLOTHES, mostlyendings + CONST_externallyStoredData194),
		customText(&conservativeLegalArgumentUnprocessed, talky + CONST_externallyStoredData195),
		customText(&youAreStupidTalkAboutIssuesUnprocessed, talky + CONST_externallyStoredData196),
		customText(&issueTooLiberalUnprocessed, talky + CONST_externallyStoredData197),
		customText(&issueEventStringUnprocessed, talky + CONST_externallyStoredData198),
		customText(&conservatiseLawUnprocessed, talky + CONST_externallyStoredData199),
		customText(&liberalizeLawUnprocessed, talky + CONST_externallyStoredData200),
		customText(&discussIssuesUnprocessed, talky + CONST_externallyStoredData201),
		customText(&discussesIssuesUnprocessed, talky + CONST_externallyStoredData202),
		customText(&talkAboutTheIssuesUnprocessed, talky + CONST_externallyStoredData203),
		customText(&endgameLawStringsUnprocessed, talky + CONST_externallyStoredData204),
		customText(&state_biases_Unprocessed, mostlyendings + CONST_externallyStoredData205),
		customText(&helpTopicUnprocessed, CONST_externallyStoredData206),
	};
	bool initialize_more_incomplete_txt();
#endif	//EXTERNALLYSTOREDDATA_CPP
#ifdef	EXTERNALLYSTOREDTEXT_CPP
// externallyStoredText.cpp

	const string CONST_externallyStoredText022 = "NOVERBOSECOMMENTS";
	const string CONST_externallyStoredText021 = "VERBOSESAVEFILE";
	const string CONST_externallyStoredText020 = "ALLOWSTALIN";
	const string CONST_externallyStoredText019 = "MORERANDOM";
	const string CONST_externallyStoredText018 = "ZEROMORAL";
	const string CONST_externallyStoredText017 = "INTERNAL";
	const string CONST_externallyStoredText016 = "SPINE";
	const string CONST_externallyStoredText015 = "NOFACE";
	const string CONST_externallyStoredText014 = "NOWALK";
	const string CONST_externallyStoredText013 = "BLIND";
	const string CONST_externallyStoredText012 = "THEFUTURE";
	const string CONST_externallyStoredText011 = "SHOWMECHANICS";
	const string CONST_externallyStoredText010 = "SHOWWAIT";
	const string CONST_externallyStoredText009 = "AUTOENLIGHTEN";
	const string CONST_externallyStoredText008 = "HIGHFUNDS";
	const string CONST_externallyStoredText007 = "GIVEBLOODYARMOR";
	const string CONST_externallyStoredText006 = "REVOLUTIONNOW";
	const string CONST_externallyStoredText005 = "PERFECTLAWS";
	const string CONST_externallyStoredText004 = "SHITLAWS";
	const string CONST_externallyStoredText003 = "NOENEMYATTACK";
	const string CONST_externallyStoredText002 = "NOSAVE";
	const string CONST_externallyStoredText001 = "DISPLAYDEBUG";

#include "../creature/creatureEnums.h"
#include <queue>
#include <map>
#include "../customMaps.h"
	struct pointerAndString {
		bool *super_collection;
		string fileName;
		pointerAndString(bool *super_, const string& file_) : fileName(file_), super_collection(super_) {}
	};

	/*
	DEBUG DEFINES
	*/
	// inform player of activated debug codes
	extern bool DISPLAYDEBUG;
	// Don't save the game
	extern bool NOSAVE;
	// Enemies don't attack
	extern bool NOENEMYATTACK;
	// Laws start archconservative
	extern bool SHITLAWS;
	// Laws start elite liberal
	extern bool PERFECTLAWS;
	// Public opinion starts at 100% Liberal
	extern bool REVOLUTIONNOW;
	// Gives you bloody armor
	extern bool GIVEBLOODYARMOR;
	// Start with lots of money
	extern bool HIGHFUNDS;
	// Interrogation always enlightens
	extern bool AUTOENLIGHTEN;
	// Show polls when you can't see things
	extern bool SHOWWAIT;
	// Show die rolls, 100% accurate poll numbers
	extern bool SHOWMECHANICS;
	// Make the year 2100
	extern bool THEFUTURE;
	// Make the founder blind
	extern bool BLIND;
	// Make the founder unable to walk
	extern bool NOWALK;
	// Make the founder have no face
	extern bool NOFACE;
	// Make the founder have a severely injured spine
	extern bool SPINE;
	// Make the founder have severe internal damage
	extern bool INTERNAL;
	// Make age not matter for dating or prostitution
	extern bool ZEROMORAL;
	// Re-seed the Random Number Generator every time it's called
	extern bool MORERANDOM;
	// Allow experimental, incomplete Stalinist Comrade Squad mode to be chosen for new games
	extern bool ALLOWSTALIN;
	// Store savefiles in plaintext, making it human readable and editable
	extern bool VERBOSESAVEFILE;
	// NOVERBOSECOMMENTS only affect anything if VERBOSESAVEFILE is active
	// Remove almost all automatically generated comments from verbose savefiles
	extern bool NOVERBOSECOMMENTS;

	vector<pointerAndString> debug_defines = {
		pointerAndString(&DISPLAYDEBUG, CONST_externallyStoredText001),
		pointerAndString(&NOSAVE, CONST_externallyStoredText002),
		pointerAndString(&NOENEMYATTACK, CONST_externallyStoredText003),
		pointerAndString(&SHITLAWS, CONST_externallyStoredText004),
		pointerAndString(&PERFECTLAWS, CONST_externallyStoredText005),
		pointerAndString(&REVOLUTIONNOW, CONST_externallyStoredText006),
		pointerAndString(&GIVEBLOODYARMOR, CONST_externallyStoredText007),
		pointerAndString(&HIGHFUNDS, CONST_externallyStoredText008),
		pointerAndString(&AUTOENLIGHTEN, CONST_externallyStoredText009),
		pointerAndString(&SHOWWAIT, CONST_externallyStoredText010),
		pointerAndString(&SHOWMECHANICS, CONST_externallyStoredText011),
		pointerAndString(&THEFUTURE, CONST_externallyStoredText012),
		pointerAndString(&BLIND, CONST_externallyStoredText013),
		pointerAndString(&NOWALK, CONST_externallyStoredText014),
		pointerAndString(&NOFACE, CONST_externallyStoredText015),
		pointerAndString(&SPINE, CONST_externallyStoredText016),
		pointerAndString(&INTERNAL, CONST_externallyStoredText017),
		pointerAndString(&ZEROMORAL, CONST_externallyStoredText018),
		pointerAndString(&MORERANDOM, CONST_externallyStoredText019),
		pointerAndString(&ALLOWSTALIN, CONST_externallyStoredText020),
		pointerAndString(&VERBOSESAVEFILE, CONST_externallyStoredText021),
		pointerAndString(&NOVERBOSECOMMENTS, CONST_externallyStoredText022)
	};
#endif	//EXTERNALLYSTOREDTEXT_CPP
#ifdef	FIGHT_CPP
// fight.cpp

	const string fighty = "fight\\";
	const string mostlyendings = "mostlyendings\\";
	const string CONST_fight239 = "'s neck is broken!";
	const string CONST_fight238 = "'s neck bones are shattered!";
	const string CONST_fight237 = "'s nose is removed!";
	const string CONST_fight236 = "'s nose is cut off!";
	const string CONST_fight235 = "'s nose is torn off!";
	const string CONST_fight234 = "'s nose is burned away!";
	const string CONST_fight233 = "'s nose is blasted off!";
	const string CONST_fight232 = "'s tongue is removed!";
	const string CONST_fight231 = "'s tongue is cut off!";
	const string CONST_fight230 = "'s tongue is torn out!";
	const string CONST_fight229 = "'s tongue is burned away!";
	const string CONST_fight228 = "'s tongue is blasted off!";
	const string CONST_fight227 = "'s left eye is removed!";
	const string CONST_fight226 = "'s left eye is poked out!";
	const string CONST_fight225 = "'s left eye is torn out!";
	const string CONST_fight224 = "'s left eye is burned away!";
	const string CONST_fight223 = "'s left eye is blasted out!";
	const string CONST_fight222 = "'s right eye is removed!";
	const string CONST_fight221 = "'s right eye is poked out!";
	const string CONST_fight220 = "'s right eye is torn out!";
	const string CONST_fight219 = "'s right eye is burned away!";
	const string CONST_fight218 = "'s right eye is blasted out!";
	const string CONST_fight217 = "knocked out!";
	const string CONST_fight216 = "cut out!";
	const string CONST_fight215 = "gouged out!";
	const string CONST_fight214 = "burned away!";
	const string CONST_fight213 = "shot out!";
	const string CONST_fight212 = "'s last tooth is ";
	const string CONST_fight211 = "'s teeth is ";
	const string CONST_fight210 = "One of ";
	const string CONST_fight209 = "'s teeth are ";
	const string CONST_fight208 = " of ";
	const string CONST_fight207 = "All ";
	const string CONST_fight206 = "'s face is removed!";
	const string CONST_fight205 = "'s face is cut away!";
	const string CONST_fight204 = "'s face is torn off!";
	const string CONST_fight203 = "'s face is burned away!";
	const string CONST_fight202 = "'s face is blasted off!";
	const string CONST_fight201 = "broken!";
	const string CONST_fight200 = "shot apart!";
	const string CONST_fight199 = "'s last unbroken rib is ";
	const string CONST_fight198 = "'s rib is ";
	const string CONST_fight196 = "'s ribs are ";
	const string CONST_fight193 = "'s spleen is punctured!";
	const string CONST_fight192 = "'s spleen is torn!";
	const string CONST_fight191 = "'s spleen is blasted!";
	const string CONST_fight190 = "'s left kidney is punctured!";
	const string CONST_fight189 = "'s left kidney is torn!";
	const string CONST_fight188 = "'s left kidney is blasted!";
	const string CONST_fight187 = "'s right kidney is punctured!";
	const string CONST_fight186 = "'s right kidney is torn!";
	const string CONST_fight185 = "'s right kidney is blasted!";
	const string CONST_fight184 = "'s stomach is punctured!";
	const string CONST_fight183 = "'s stomach is torn!";
	const string CONST_fight182 = "'s stomach is blasted!";
	const string CONST_fight181 = "'s liver is punctured!";
	const string CONST_fight180 = "'s liver is torn!";
	const string CONST_fight179 = "'s liver is blasted!";
	const string CONST_fight178 = "'s heart is punctured!";
	const string CONST_fight177 = "'s heart is torn!";
	const string CONST_fight176 = "'s heart is blasted!";
	const string CONST_fight175 = "'s left lung is punctured!";
	const string CONST_fight174 = "'s left lung is torn!";
	const string CONST_fight173 = "'s left lung is blasted!";
	const string CONST_fight172 = "'s right lung is punctured!";
	const string CONST_fight171 = "'s right lung is torn!";
	const string CONST_fight170 = "'s right lung is blasted!";
	const string CONST_fight169 = "'s lower spine is broken!";
	const string CONST_fight168 = "'s lower spine is shattered!";
	const string CONST_fight167 = "'s upper spine is broken!";
	const string CONST_fight166 = "'s upper spine is shattered!";
	const string CONST_fight165 = "'s body.";
	const string CONST_fight164 = " drops ";
	const string CONST_fight163 = "super enemy";
	const string CONST_fight162 = "dangerous enemies";
	const string CONST_fight161 = "super enemies";
	const string CONST_fight160 = " misses completely!";
	const string CONST_fight159 = " just barely missed!";
	const string CONST_fight158 = " missed!";
	const string CONST_fight154 = " knocks the blow aside and counters!";
	const string CONST_fight153 = " to no effect.";
	const string CONST_fight152 = " BLOWING IT OFF!";
	const string CONST_fight151 = " CUTTING IT OFF!";
	const string CONST_fight150 = " BLOWING IT IN HALF!";
	const string CONST_fight149 = " BLOWING IT APART!";
	const string CONST_fight148 = " CUTTING IT IN HALF!";
	const string CONST_fight146 = "!";
	const string CONST_fight145 = "'s corpse";
	const string CONST_fight144 = " shields ";
	const string CONST_fight143 = " heroically";
	const string CONST_fight142 = " misguidedly";
	const string CONST_fight141 = "(ATK %d, DEF %d, DAMMOD %d, DAMAGE %d, AP %d)";
	const string CONST_fight140 = "the ";
	const string CONST_fight139 = "The attack bounces off ";
	const string CONST_fight138 = " through ";
	const string CONST_fight137 = "striking";
	const string CONST_fight136 = "'s ";
	const string CONST_fight135 = " hits ";
	const string CONST_fight134 = " stabs ";
	const string CONST_fight132 = " with a ";
	const string CONST_fight131 = "sneaks up on";
	const string CONST_fight130 = "bites";
	const string CONST_fight129 = "stabs";
	const string CONST_fight128 = "breathes fire at";
	const string CONST_fight127 = "fires a 120mm shell at";
	const string CONST_fight126 = "gracefully strikes at";
	const string CONST_fight125 = "jump kicks";
	const string CONST_fight124 = "strikes at";
	const string CONST_fight123 = "kicks";
	const string CONST_fight122 = "grapples with";
	const string CONST_fight121 = "swings at";
	const string CONST_fight120 = "punches";
	const string CONST_fight119 = "MISTAKENLY ";
	const string CONST_fight118 = " readies another ";
	const string CONST_fight117 = " reloads.";
	const string CONST_fight116 = "actual";
	const string CONST_fight114 = "\"A plague on both your houses...\"";
	const string CONST_fight113 = " speaks these final words: ";
	const string CONST_fight112 = "soils the floor.";
	const string CONST_fight111 = "[makes a mess].";
	const string CONST_fight110 = " gasps a last breath and ";
	const string CONST_fight109 = "something about Jesus, and dies.";
	const string CONST_fight108 = "something [good] about Jesus, and dies.";
	const string CONST_fight107 = " sweats profusely, murmurs ";
	const string CONST_fight106 = "the neck hole, then is quiet.";
	const string CONST_fight105 = " sucks a last breath through ";
	const string CONST_fight104 = "neck and falls to the side.";
	const string CONST_fight103 = "neck and runs down the hall.";
	const string CONST_fight102 = " out of the ";
	const string CONST_fight101 = "[red water]";
	const string CONST_fight100 = " squirts ";
	const string CONST_fight099 = "moment then crumples over.";
	const string CONST_fight098 = " sits headless for a ";
	const string CONST_fight097 = " stands headless for a ";
	const string CONST_fight096 = "is no head, and slumps over.";
	const string CONST_fight095 = "is no head, and falls.";
	const string CONST_fight094 = " reaches once where there ";
	const string CONST_fight093 = " has been destroyed.";
	const string CONST_fight091 = "'s grasp.";
	const string CONST_fight090 = " slips from";
	const string CONST_fight089 = "NULL BODYPART";
	const string CONST_fight088 = " remains strong.";
	const string CONST_fight087 = " has turned Liberal!";
	const string CONST_fight086 = "'s Heart swells!";
	const string CONST_fight085 = " seems less badass!";
	const string CONST_fight083 = " doesn't want to fight anymore";
	const string CONST_fight081 = " is turned Conservative";
	const string CONST_fight080 = " can't bear to leave!";
	const string CONST_fight079 = " is tainted with Wisdom!";
	const string CONST_fight078 = " loses juice!";
	const string CONST_fight077 = " already agrees with ";
	const string CONST_fight076 = " is immune to the attack!";
	const string CONST_fight074 = "rocks out at";
	const string CONST_fight073 = "plays country songs at";
	const string CONST_fight072 = "plays protest songs at";
	const string CONST_fight071 = " at";
	const string CONST_fight070 = "blows a harmonica";
	const string CONST_fight069 = "strums the ";
	const string CONST_fight068 = "sings to";
	const string CONST_fight067 = "plays a song for";
	const string CONST_fight060 = "explains ethical research to";
	const string CONST_fight059 = "explains the benefits of research to";
	const string CONST_fight057 = " spits up a cluster of bloody bubbles.";
	const string CONST_fight056 = " [makes a mess].";
	const string CONST_fight055 = " vomits up a clot of blood.";
	const string CONST_fight049 = "'s gums start chattering.";
	const string CONST_fight048 = "'s tooth starts chattering.";
	const string CONST_fight047 = "'s teeth start chattering.";
	const string CONST_fight046 = " pisses on the floor, moaning.";
	const string CONST_fight045 = " [makes a mess], moaning.";
	const string CONST_fight044 = " stares out with hollow sockets.";
	const string CONST_fight043 = " stares into space with one empty eye.";
	const string CONST_fight042 = " stares off into space.";
	const string CONST_fight041 = " leans against the door.";
	const string CONST_fight040 = " stumbles against a wall.";
	const string CONST_fight039 = " soils the floor.";
	const string CONST_fight038 = " [makes a stinky].";
	const string CONST_fight035 = " times";
	const string CONST_fight034 = " five times";
	const string CONST_fight033 = " four times";
	const string CONST_fight032 = " three times";
	const string CONST_fight031 = " twice";
	const string CONST_fight030 = "evasionStringsAlt.txt";
	const string CONST_fight029 = "evasionStrings.txt";
	const string CONST_fight028 = "body_falls_apart.txt";
	const string CONST_fight027 = "double_line_death.txt";
	const string CONST_fight026 = "bleeding_animal.txt";
	const string CONST_fight025 = "paralyzed_tank.txt";
	const string CONST_fight024 = "paralyzed_text.txt";
	const string CONST_fight023 = "stunned_text.txt";
	const string CONST_fight022 = "bleeding_to_death.txt";
	const string CONST_fight021 = "cry_alarm.txt";
	const string CONST_fight020 = "scientist_debate.txt";
	const string CONST_fight019 = "police_debate.txt";
	const string CONST_fight018 = "military_debate.txt";
	const string CONST_fight017 = "media_debate.txt";
	const string CONST_fight016 = "other_politician_debate.txt";
	const string CONST_fight015 = "conservative_politician_debate.txt";
	const string CONST_fight014 = "other_ceo_debate.txt";
	const string CONST_fight013 = "conservative_ceo_debate.txt";
	const string CONST_fight012 = "judge_debate.txt";
	const string CONST_fight011 = "escape_crawling.txt";
	const string CONST_fight010 = "escape_running.txt";
	const string CONST_fightX01 = " cries \"Mommy!\"";
	const string CONST_fightX02 = " murmurs \"What about my offspring?\"";
	const string CONST_fightX03 = " murmurs \"What about my puppies?\"";
	const string CONST_fightX04 = " murmurs \"What about my children?\"";
	const string CONST_fightX05 = "\"Better dead than liberal...\"";

	const string tag_ARMOR = "ARMOR";
	const string tag_ARMOR_PRISONER = "ARMOR_PRISONER";
	const string tag_ARMOR_CLOTHES = "ARMOR_CLOTHES";
	const string tag_false = "false";
	const string tag_blood = "blood";
	const string tag_The = "The ";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";

#include "../creature/creature.h"
	////

	//#include "../creature/deprecatedCreatureA.h"
	//#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../sitemode/stealth.h"
#include "../sitemode/sitedisplay.h"
#include "../items/money.h"
#include "../log/log.h"
// for gamelog
//#include "../common/translateid.h"
	int getarmortype(const string &idname);
	//#include "../common/commondisplay.h"
	void printparty();
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
	//#include "../combat/chaseCreature.h"
	Vehicle* getChaseVehicle(const DeprecatedCreature &c);
	DeprecatedCreature* getChaseDriver(const DeprecatedCreature &c);
	//#include "../combat/haulkidnapCreature.h"
	void freehostage(DeprecatedCreature &cr, char situation);
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/creaturePool.h"
	vector<string> escape_running;
	vector<string> escape_crawling;
	vector<string> judge_debate;
	vector<string> conservative_ceo_debate;
	vector<string> other_ceo_debate;
	vector<string> conservative_politician_debate;
	vector<string> other_politician_debate;
	vector<string> media_debate;
	vector<string> military_debate;
	vector<string> police_debate;
	vector<string> scientist_debate;
	vector<string> cry_alarm;
	vector<string> bleeding_to_death;
	vector<string> stunned_text;
	vector<string> paralyzed_text;
	vector<string> paralyzed_tank;
	vector<string> bleeding_animal;
	vector<vector<string> > double_line_death;
	vector<string> body_falls_apart;
	vector<string> evasionStringsAlt;
	vector<string> evasionStrings;
	const int DOUBLE_LINE = 2;
	vector<file_and_text_collection> fighty_text_file_collection = {
		/*fight.cpp*/
		customText(&escape_running, fighty + CONST_fight010),
		customText(&escape_crawling, fighty + CONST_fight011),
		customText(&judge_debate, fighty + CONST_fight012),
		customText(&conservative_ceo_debate, fighty + CONST_fight013),
		customText(&other_ceo_debate, fighty + CONST_fight014),
		customText(&conservative_politician_debate, fighty + CONST_fight015),
		customText(&other_politician_debate, fighty + CONST_fight016),
		customText(&media_debate, fighty + CONST_fight017),
		customText(&military_debate, fighty + CONST_fight018),
		customText(&police_debate, fighty + CONST_fight019),
		customText(&scientist_debate, fighty + CONST_fight020),
		customText(&cry_alarm, fighty + CONST_fight021),
		customText(&bleeding_to_death, fighty + CONST_fight022),
		customText(&stunned_text, fighty + CONST_fight023),
		customText(&paralyzed_text, fighty + CONST_fight024),
		customText(&paralyzed_tank, fighty + CONST_fight025),
		customText(&bleeding_animal, fighty + CONST_fight026),
		customText(&double_line_death, fighty + CONST_fight027, DOUBLE_LINE),
		customText(&body_falls_apart, fighty + CONST_fight028),
		customText(&evasionStrings, mostlyendings + CONST_fight029),
		customText(&evasionStringsAlt, mostlyendings + CONST_fight030),
	};
	// extern string singleSpace;
	// extern string singleDot;
	// extern string commaSpace;
	vector<Item *> groundloot;


	vector<NameAndAlignment> getEncounterNameAndAlignment();
	void delenc(const short e, const char loot);
	string specialWoundPossibilityBody(
		DeprecatedCreature &target,
		const char breakdam,
		const char pokedam,
		const char damtype
	);
	string specialWoundPossibilityHead(
		DeprecatedCreature &target,
		const char breakdam,
		const char heavydam,
		const char damtype
	);
	extern Log gamelog;
	extern short mode;
	extern short lawList[LAWNUM];
	map<short, string> tankBodyParts;
	map<short, string> animalBodyParts;
	map<short, string> humanBodyParts;
	std::string burstHitString(int bursthits);
	void bloodyUpEncounterArmor();
	extern short mode;
	extern Deprecatedsquadst *activesquad;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short mode;
	extern Log gamelog;
	/* attack handling for an individual creature and its target */
	// returns a boolean representing whether it was the intended target or CONST_fight116
	// so bool actual does not need to be passed by reference
	bool attack(DeprecatedCreature &a, DeprecatedCreature &t, const char mistake, const bool force_melee = false);

	extern short mode;
	extern Log gamelog;
	extern short mode;
	extern Log gamelog;
	extern Deprecatedsquadst *activesquad;
	void setSiteAlarmOne();
	string howGracefulAttack(int handToHand);
	string dismemberingWound(const int w, const int wound);
	int bodypartSeverAmount(const int w);

	class AttackInfliction {
	public:
		AttackInfliction(const bool, const int, const int, const attackst);
		const bool sneak_attack;
		const int aroll;
		const int droll;
		const attackst attack_used;
	};
	AttackInfliction::AttackInfliction(const bool _sneak_attack, const int _aroll, const int _droll, const attackst _attack_used) : sneak_attack(_sneak_attack), aroll(_aroll < 0 ? 0 : _aroll),
		droll(_droll < 0 ? 0 : _droll),
		attack_used(_attack_used) {


	}
	class AttackSeverity {
	public:
		AttackSeverity::AttackSeverity(const int, const int, const int, const int);
		const int damamount;
		const int damagearmor;
		const int severtype;
		const int hit_location;

	};
	AttackSeverity::AttackSeverity(const int _damamount, const int _damagearmor, const int _severtype, const int w) : damamount(_damamount),
		damagearmor(_damagearmor),
		severtype(_severtype),
		hit_location(w)
	{


	}
	extern short mode;
	extern int stat_dead;
	extern int stat_kills;
	extern int ccs_siege_kills;
	extern int ccs_boss_kills;
	extern Log gamelog;
	extern Deprecatednewsstoryst *sitestory;

	extern int sitecrime;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short lawList[LAWNUM];

	struct damageDetails {
		const int mod;
		const int hit_location;
		const int extraarmor;
		const char armorpiercing;
		damageDetails(int _mod, int _hit_location, int _extraarmor, char _armorpiercing) : mod(_mod), hit_location(_hit_location), extraarmor(_extraarmor), armorpiercing(_armorpiercing) {};
	};
	extern short mode;
	extern Log gamelog;

	void addLocationChange(int cursite, sitechangest change);
	extern short mode;

	extern Deprecatednewsstoryst *sitestory;

	extern int sitecrime;
	extern coordinatest loc_coord;

	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern DeprecatedCreature encounter[ENCMAX];
	extern vector<DeprecatedCreature *> pool;
	bool attackPoolEncounter(const int p, const int t, const char mistake, const bool force_melee = false);
	void addLocationChange(int cursite, sitechangest change);
	bool isThereASiteAlarm();
	extern short mode;
	extern Log gamelog;
	extern short sitealarmtimer;
	extern Deprecatedsquadst *activesquad;
	extern Deprecatednewsstoryst *sitestory;

	extern int sitecrime;
	extern DeprecatedCreature encounter[ENCMAX];
	vector<NameAndAlignment> getEncounterNameAndAlignment();
	extern char foughtthisround;
	extern Deprecatedsquadst *activesquad;
	extern Deprecatednewsstoryst *sitestory;
	extern int sitecrime;
	extern vector<DeprecatedCreature *> pool;
	enum LOOP_CONTINUATION {
		RETURN_ZERO,
		RETURN_ONE,
		REPEAT
	};
	void conservatise(const int e);
	extern short mode;
	extern char foughtthisround;
	extern Log gamelog;
	extern Deprecatedsquadst *activesquad;

	extern int sitecrime;
	// Enemies don't attack
	extern bool NOENEMYATTACK;
	extern DeprecatedCreature encounter[ENCMAX];
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern Log gamelog;
	extern short mode;
	extern char foughtthisround;

	extern Deprecatedsquadst *activesquad;

	extern bool NOENEMYATTACK;
	extern DeprecatedCreature encounter[ENCMAX];
	extern short sitetype;
	extern Deprecatedsquadst *activesquad;
	extern vector<DeprecatedCreature *> pool;
	short  getCurrentSite();
	extern Log gamelog;
	extern short lawList[LAWNUM];
	extern short mode;
	extern Log gamelog;
	extern Deprecatedsquadst *activesquad;
	extern short lawList[LAWNUM];
	extern DeprecatedCreature encounter[ENCMAX];
	extern short mode;
	extern Log gamelog;
	extern short lawList[LAWNUM];
	extern string slogan_str;
#endif	//FIGHT_CPP
#ifdef	GAME_CPP
// game.cpp

#include "creature/newcreature.h"
#include "../items/armortype.h"
#include "common/interval.h"
#include "vehicle/vehicletype.h"
#include "vehicle/vehicle.h"
//#include "news/news.h"
	void loadgraphics();
#include "items/loottype.h"
#include "creature/augmenttype.h"
	//#include "configfile.h"
	// Reads in an entire configuration file
	// Returns 0 for read successful, returns -1 if failed read
	int readConfigFile(const std::string& filename);
#include "log/log.h"
	//for the gamelog
	//#include "common/consolesupport.h"
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
#ifdef WIN32
	bool fixcleartype = false;
#endif
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
	//int mainSeven(bool xml_loaded_ok);
	void init_console();
	void initialize_debug_defines();
	extern Log gamelog; //The gamelog.
	extern Log gamelog; //The gamelog.
#include "common/musicClass.h"
	void set_title(char *s);
	const string defaultMissingForMask = "Default missing for masks!";
	const string defaultUnknownForMask = "Default for masks is not a known armor type!";
	const string activated = " activated";
	const string debugCode = "debug code ";
	const string failedToLoadSitemaps = "Failed to load sitemaps.txt! Reverting to old map mode.";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";
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

	extern MusicClass music;
	// Laws start archconservative
	extern bool SHITLAWS;
	// Laws start elite liberal
	extern bool PERFECTLAWS;
	// Public opinion starts at 100% Liberal
	extern bool REVOLUTIONNOW;
	extern short activesortingchoice[];
	extern short attitude[];
	extern short public_interest[];
	extern short background_liberal_influence[];
	extern short lawList[];
	extern char artdir[];
	extern char artdir[];
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
	//extern vector<file_and_text_collection> text_file_collection;
	extern vector<file_and_text_collection> title_screen_text_files;
	extern vector<file_and_text_collection> reviewmode_text_file_collection;
	extern vector<file_and_text_collection> siege_text_file_collection;
	extern vector<file_and_text_collection> stealth_text_file_collection;

	// inform player of activated debug codes
	extern bool DISPLAYDEBUG;
	extern char artdir[];
	extern vector<pointerAndString> debug_defines;
	extern short senate[];
	extern short house[];
	fullName generate_long_name(char gender = GENDER_NEUTRAL);
	extern short court[];
	extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
	extern short  exec[];
	extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	bool mainSeven(bool xml_loaded_ok);
	extern char artdir[];

	extern Log gamelog; //The gamelog.
	extern unsigned long attorneyseed[4];
	extern char lcityname[];
#endif	//GAME_CPP
#ifdef	GETNAMES_CPP
// getnames.cpp

#include "../creature/newcreature.h"
#include "../cursesAlternative.h"
#include "../customMaps.h"
	extern short lawList[LAWNUM];
	const string moderateLC = "moderate";
	const string buggyString = "Buggy";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";
	const string names = "names\\";
	const string mostlyendings = "mostlyendings\\";
	const string CONST_getnames045 = "getMonth.txt";
	const string CONST_getnames044 = "city_names.txt";
	const string CONST_getnames043 = "Software Bugs";
	const string CONST_getnames042 = "Buggy Software";
	const string CONST_getnames041 = "bugs";
	const string CONST_getnames040 = "Elite Liberal";
	const string CONST_getnames039 = "Liberal Guardian";
	const string CONST_getnames038 = "Urban Commando";
	const string CONST_getnames037 = "Revolutionary";
	const string CONST_getnames036 = "Socialist Threat";
	const string CONST_getnames035 = "Activist";
	const string CONST_getnames034 = "Civilian";
	const string CONST_getnames033 = "Punk";
	const string CONST_getnames032 = "Society's Dregs";
	const string CONST_getnames031 = "Damn Worthless";
	const string CONST_getnames030 = "[Darn] Worthless";
	const string CONST_getnames029 = "Peace Prize Winner";
	const string CONST_getnames028 = "Peacemaker";
	const string CONST_getnames027 = "Great Person";
	const string CONST_getnames026 = "Upstanding Citizen";
	const string CONST_getnames025 = "Respected";
	const string CONST_getnames024 = "Hard Working";
	const string CONST_getnames023 = "Non-Liberal";
	const string CONST_getnames022 = "Non-Liberal Punk";
	const string CONST_getnames018 = "Evil Incarnate";
	const string CONST_getnames017 = "Arch-Conservative";
	const string CONST_getnames016 = "Insane Vigilante";
	const string CONST_getnames015 = "Heartless Bastard";
	const string CONST_getnames014 = "Heartless [Jerk]";
	const string CONST_getnames013 = "Stubborn as Hell";
	const string CONST_getnames012 = "Stubborn as [Heck]";
	const string CONST_getnames011 = "Wrong-Thinker";
	const string CONST_getnames010 = "Mindless Conservative";
	const string CONST_getnames009 = "Conservative Punk";
	const string CONST_getnames008 = "Conservative Dregs";
#endif	//GETNAMES_CPP
#ifdef	GLOBALS_CPP
// globals.cpp

#include "creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"

#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../items/armortype.h"
#include "common/interval.h"
// needed for creaturetype
#include "vehicle/vehicletype.h"
#include "vehicle/vehicle.h"
#include "creature/creaturetype.h"
#include "creature/augmenttype.h"
//#include "common/consolesupport.h"
// for end_cleartype_fix()
#include "common/musicClass.h"
#include "common/creaturePool.h"
#include "locations/locationsPool.h"
#include "items/itemPool.h"
#include "items/lootTypePool.h"
	void delete_and_clear_sitemaps();
	void delete_and_clear_groundloot();
	int endwinAlt(void);
	void delete_and_clear_vehicle_types();
	void delete_and_clear_date_pool();
	void delete_and_clear_weapon_type();
#include <common\\consolesupport.h>
#include "items/loottype.h"
#include "log/log.h"
#include "cursesAlternative.h"
	//extern string failedToLoad;
	//extern string exclamationPoint;
	int driveskill(DeprecatedCreature &cr, Vehicle &v);
	bool populate_masks_from_xml(vector<ArmorType*>& masks, const string& file, Log& log);
	int getweapontype(const string &idname);
	extern vector<WeaponType *> weapontype;
#include "common/ledgerEnums.h"
#include "common/ledger.h"
	extern class Ledger ledger;
	void makeloot(DeprecatedCreature &cr);
	extern short mode;
	extern DeprecatedCreature encounter[ENCMAX];
#include "items/money.h"
	Item* getNewLoot(const string& newLootType, int num = 1);
	void addjuice(DeprecatedCreature &cr, long juice, long cap);
	extern vector<DeprecatedCreature *> pool;
	extern vector<DeprecatedCreature *> pool;
	extern vector<DeprecatedCreature *> pool;
	void fullstatus(const int party_status);
	void removesquadinfo(DeprecatedCreature &cr);
	extern vector<DeprecatedCreature *> pool;
	void printReporterDuringSiege(const string repname, const string name, const int segmentpower);
	extern vector<DeprecatedCreature *> pool;
	extern Log gamelog;
	Deprecatednewsstoryst* lastNewsStory();
	extern Deprecatednewsstoryst *sitestory;
	extern Deprecatednewsstoryst *sitestory;
	void assemblesquad(Deprecatedsquadst *cursquad);
	extern Deprecatedsquadst *activesquad;
	extern Deprecatedsquadst *activesquad;
	extern vector<DeprecatedCreature *> pool;
	extern vector<Deprecatedsquadst *> squad;
	int getloottype(const string &idname);
	extern vector<Deprecatedsquadst *> squad;
	void consolidateloot(vector<Item *> &loot);
	int getloottype(const string &idname);
	void criminalize(DeprecatedCreature &cr, short crime);
	int subordinatesleft(const DeprecatedCreature& cr);
	void addCreature(DeprecatedCreature* cr);
#include "common/creaturePoolCreature.h"

	//string hasRecruited;
	//string looksForwardToServing;
	//	extern string string_sleeper;
	extern Log gamelog;
	const string hasRecruited = " has recruited a new ";
	const string looksForwardToServing = " looks forward serving the Liberal cause!";
	const string CONST_game012 = "We need a slogan!";
	const string tag_WEAPON_FLAMETHROWER = "WEAPON_FLAMETHROWER";
	const string tag_WEAPON_DESERT_EAGLE = "WEAPON_DESERT_EAGLE";
	const string CONST_siege254 = " Defense";
	const string CONST_siege209 = "The interview is wide-ranging, covering a variety of topics.";
	const string CONST_siege208 = " decides to give an interview.";
	const string CONST_globals013 = "augmentations.xml";
	const string CONST_globals012 = "creatures.xml";
	const string CONST_globals011 = "loot.xml";
	const string CONST_globals010 = "masks.xml";
	const string CONST_globals009 = "armors.xml";
	const string CONST_globals008 = "weapons.xml";
	const string CONST_globals007 = "clips.xml";
	const string CONST_globals006 = "vehicles.xml";
	const string CONST_globals005 = "xmllog";
	const string CONST_globals004 = "default_slogans.txt";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";

	extern vector<LootType *> loottype;
	extern vector<WeaponType *> weapontype;
	extern vector<VehicleType *> vehicletype;
	extern Log xmllog;
#endif	//GLOBALS_CPP
#ifdef	HAULKIDNAP_CPP
// haulkidnap.cpp

	const string CONST_haulkidnapD01 = " Is The Only Viable Target";
	const string CONST_haulkidnapD02 = "Still Kidnap? [Y/N]";
	const string CONST_haulkidnap035 = " hauls ";
	const string CONST_haulkidnap034 = " is left to be captured.";
	const string CONST_haulkidnap033 = "Nobody can carry Martyr ";
	const string CONST_haulkidnap032 = " can no longer handle ";
	const string CONST_haulkidnap031 = "                                  ";
	const string CONST_haulkidnap030 = "The hostage shouts for help!      ";
	const string CONST_haulkidnap029 = "release their hostage.";
	const string CONST_haulkidnap027 = "No hostages are being held.       ";
	const string CONST_haulkidnap026 = "                                                     ";
	const string CONST_haulkidnap025 = "All of the targets are too dangerous.                ";
	const string CONST_haulkidnap024 = "Kidnap whom?";
	const string CONST_haulkidnap023 = "do the job.";
	const string CONST_haulkidnap021 = "No one can do the job.            ";
	const string CONST_haulkidnap020 = " is captured.";
	const string CONST_haulkidnap019 = " is recaptured.";
	const string CONST_haulkidnap018 = "A hostage escapes!";
	const string CONST_haulkidnap017 = " is captured";
	const string CONST_haulkidnap016 = " is recaptured";
	const string CONST_haulkidnap015 = " and a hostage is freed";
	const string CONST_haulkidnap012 = "and says, ";
	const string CONST_haulkidnap011 = " the ";
	const string CONST_haulkidnap010 = " shows ";
	const string CONST_haulkidnap009 = " writhes away!";
	const string CONST_haulkidnap008 = "but ";
	const string CONST_haulkidnap007 = " grabs at ";
	const string CONST_haulkidnap006 = " is struggling and screaming!";
	const string CONST_haulkidnap005 = "!";
	const string CONST_haulkidnap004 = " snatches ";
	const string CONST_haulkidnapX01 = "\"[Please], be cool.\"";
	const string CONST_haulkidnapX02 = "\"Bitch, be cool.\"";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";

#include "../creature/creature.h"
	////

	//#include "../creature/deprecatedCreatureA.h"
	//#include "../creature/deprecatedCreatureB.h"
	//#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../sitemode/advance.h"
// for creatureadvance
#include "../sitemode/stealth.h"
#include "../sitemode/sitedisplay.h"
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
// for printparty
//// #include "../common/commonactions.h"
	void criminalizeparty(short crime);
	//// #include "../common/commonactionsCreature.h"
	void removesquadinfo(DeprecatedCreature &cr);
	/* roll on the kidnap attempt and show the results */
#include "set_color_support.h"
#include "cursesAlternative.h"
//string AND;
	void conservatise(const int cr);

	void capturecreature(DeprecatedCreature &t);
	vector<NameAndAlignment> getEncounterNameAndAlignment();

	bool isThereASiteAlarm();
	void setSiteAlarmOne();
	extern short offended_amradio;
	extern short offended_cablenews;
	extern Deprecatedsquadst *activesquad;
	extern int sitecrime;
	//extern string chooseALiberalTo;
	//extern string spaceDashSpace;
	void enemyattack();
	void delenc(const short e, const char loot);
	extern short party_status;

	extern short sitealarmtimer;
	extern Deprecatedsquadst *activesquad;
	extern DeprecatedCreature encounter[ENCMAX];
	extern short lawList[LAWNUM];
	void makeloot(DeprecatedCreature &cr);
	extern short party_status;

	extern Deprecatedsquadst *activesquad;
	extern Log gamelog;

	extern short mode;
	extern Log gamelog;
	extern DeprecatedCreature encounter[ENCMAX];
#endif	//HAULKIDNAP_CPP
#ifdef HELP_CPP

	const string liberalHelpOn = "Liberal help on:";
	const string pressAnyKeyToReturn = "   Press any key - Return to previous screen";
#endif //HELP_CPP
#ifdef	HIGHSCORE_CPP
// highscore.cpp

#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../title/titlescreen.h"
#include "../common/getnames.h"
// for getmonth
#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include "../common/musicClass.h"



	MusicModes getEndingMusic(EndTypes e);
	string getEndingString(EndTypes e);
	struct  saveLoadChunk {
		void * Buffer;
		size_t      ElementSize;
		size_t      ElementCount;
		saveLoadChunk(void * _Buffer, int _ElementSize, int _ElementCount) :Buffer(_Buffer), ElementSize(_ElementSize), ElementCount(_ElementCount) {}
	};

	struct highscorest
	{
		char valid, endtype, slogan[SLOGAN_LEN];
		int month, year, stat_recruits, stat_kidnappings, stat_dead, stat_kills, stat_funds, stat_spent, stat_buys, stat_burns;
	};
	extern int ustat_recruits;
	extern int ustat_kidnappings;
	extern int ustat_dead;
	extern int ustat_kills;
	extern int ustat_funds;
	extern int ustat_spent;
	extern int ustat_buys;
	extern int ustat_burns;
	highscorest score[SCORENUM];

	vector<saveLoadChunk> highScoreSaveLoad = {
		saveLoadChunk(&ustat_recruits, sizeof(int), 1),
		saveLoadChunk(&ustat_dead, sizeof(int), 1),
		saveLoadChunk(&ustat_kills, sizeof(int), 1),
		saveLoadChunk(&ustat_kidnappings, sizeof(int), 1),
		saveLoadChunk(&ustat_funds, sizeof(int), 1),
		saveLoadChunk(&ustat_spent, sizeof(int), 1),
		saveLoadChunk(&ustat_buys, sizeof(int), 1),
		saveLoadChunk(&ustat_burns, sizeof(int), 1),
		saveLoadChunk(score, sizeof(highscorest), SCORENUM)
	};
	extern int ustat_recruits;
	extern int ustat_kidnappings;
	extern int ustat_dead;
	extern int ustat_kills;
	extern int ustat_funds;
	extern int ustat_spent;
	extern int ustat_buys;
	extern int ustat_burns;
	extern int stat_buys;
	extern int stat_burns;
	extern int stat_kidnappings;
	extern int year;
	extern int stat_dead;
	extern int stat_kills;
	extern int stat_recruits;
	extern int yourscore;
	extern int month;
	extern class Ledger ledger;
	//	extern int version;
	extern string slogan_str;
	extern int ustat_recruits;
	extern int ustat_kidnappings;
	extern int ustat_dead;
	extern int ustat_kills;
	extern int ustat_funds;
	extern int ustat_spent;
	extern int ustat_buys;
	extern int ustat_burns;
	extern int stat_buys;
	extern int stat_burns;
	extern int stat_kidnappings;
	extern int year;
	extern int stat_dead;
	extern int stat_kills;
	extern int stat_recruits;
	extern MusicClass music;
	extern int yourscore;
	const string univer = "Universal Liberal Statistics:";
	const string numRecruit = "Recruits: ";
	const string numMartyr = "Martyrs: ";
	const string numKills = "Kills: ";
	const string numKidnap = "Kidnappings: ";
	const string cashTaxed = "$ Taxed: ";
	const string cashSpent = "$ Spent: ";
	const string flagsBought = "Flags Bought: ";
	const string flagsBurned = "Flags Burned: ";
	const string noValid = "No valid scores, press any button to return.";
	const string heLiElite = "The Liberal ELITE";
	const string heLiLiber = "The Liberal Crime Squad liberalized the country in ";
	const string heLiBrought = "The Liberal Crime Squad was brought to justice in ";
	const string heLiBlot = "The Liberal Crime Squad was blotted out in ";
	const string heLiMob = "The Liberal Crime Squad was mobbed in ";
	const string heLiDownsized = "The Liberal Crime Squad was downsized in ";
	const string heLiKIA = "The Liberal Crime Squad was KIA in ";
	const string hecoReag = "The country was Reaganified in ";
	const string heLiDie = "The Liberal Crime Squad died in prison in ";
	const string heLiExec = "The Liberal Crime Squad was executed in ";
	const string heLiVaca = "The Liberal Crime Squad was on vacation in ";
	const string heLiHide = "The Liberal Crime Squad was in permanent hiding in ";
	const string heLiHunted = "The Liberal Crime Squad was hunted down in ";
	const string heLiScattered = "The Liberal Crime Squad was scattered in ";
	const string heLiOutCrime = "The Liberal Crime Squad was out-Crime Squadded in ";
	const string heLiBurned = "The Liberal Crime Squad was burned in ";
	const string hecoStalinized = "The country was Stalinized in ";
	const string CONST_highscoreB003 = "wb";
	const string CONST_highscoreB002 = "rb";
	const string CONST_highscore002 = "score.dat";
#endif	//HIGHSCORE_CPP
#ifdef	INITFILE_CPP

// initfile.cpp

#include "../common/stringconversion.h"
//for int stringtobool(std::string boolstr);
//#include "../common/consolesupport.h"
// for void begin_cleartype_fix();
#include "../title/titlescreen.h"
	extern short interface_pgup;
	extern short interface_pgdn;
	extern bool fixcleartype;
	const string CONST_initfile006 = "init.txt";

	const string tag_fixcleartype = "fixcleartype";
	const string tag_autosave = "autosave";
	const string tag_page = "page";
	const string tag_brackets = "brackets";
	const string tag_azerty = "azerty";
	const string tag_pagekeys = "pagekeys";
#endif	//INITFILE_CPP
#ifdef	INTERROGATION_CPP
// interrogation.cpp

	const string feels_sick_and = " feels sick to the stomach afterward and ";
	const string interrogate = "interrogation\\";
	const string CONST_news1030 = "\"";
	const string CONST_interrogationB150 = "hugs ";
	const string CONST_interrogation167 = "Press any key to reflect on this.";
	const string CONST_interrogation166 = "'s disappearance has not yet been reported.";
	const string CONST_interrogation165 = " was able to create a map of the site with this information.";
	const string CONST_interrogation164 = "Unfortunately, none of it is useful to the LCS.";
	const string CONST_interrogation163 = " reveals details about the ";
	const string CONST_interrogation162 = "The conversion is convincing enough that the police no longer consider it a kidnapping.";
	const string CONST_interrogation161 = "The Automaton has been Enlightened!   Your Liberal ranks are swelling!";
	const string CONST_interrogation160 = " grows colder.";
	const string CONST_interrogation159 = "'s interrogation.";
	const string CONST_interrogation158 = " under ";
	const string CONST_interrogation157 = " is dead";
	const string CONST_interrogation156 = " has committed suicide.";
	const string CONST_interrogation155 = " has been tainted with wisdom!";
	const string CONST_interrogation154 = "!";
	const string CONST_interrogation153 = " turns the tables on ";
	const string CONST_interrogation152 = " holds firm.";
	const string CONST_interrogation148 = " begs for the nightmare to end.";
	const string CONST_interrogation147 = " curls up and";
	const string CONST_interrogation146 = " to stop looking like Hitler.";
	const string CONST_interrogation145 = " screams for ";
	const string CONST_interrogation144 = " begs Hitler to stay and kill ";
	const string CONST_interrogation143 = "talks about hugging ";
	const string CONST_interrogation142 = " stammers and ";
	const string CONST_interrogation140 = " takes it well.";
	const string CONST_interrogation139 = "'s weakened body crumbles under the brutal assault.";
	const string CONST_interrogation138 = " is badly hurt.";
	const string CONST_interrogation137 = " seems to be getting the message.";
	const string CONST_interrogation136 = "A detailed map has been created of ";
	const string CONST_interrogation134 = " beats information out of the pathetic thing.";
	const string CONST_interrogation133 = " wonders about death.";
	const string CONST_interrogation132 = " wonders about apples.";
	const string CONST_interrogation131 = " cries helplessly.";
	const string CONST_interrogation130 = " barks helplessly.";
	const string CONST_interrogation129 = " curls up in the corner and doesn't move.";
	const string CONST_interrogation128 = " goes limp in the restraints.";
	const string CONST_interrogation127 = "mommy.";
	const string CONST_interrogation126 = "God's mercy.";
	const string CONST_interrogation125 = "John Lennon's mercy.";
	const string CONST_interrogation124 = " screams helplessly for ";
	const string CONST_interrogation123 = "!\" in its face.";
	const string CONST_interrogation122 = "! ";
	const string CONST_interrogation121 = " the Automaton";
	const string CONST_interrogation120 = "'s guards beat";
	const string CONST_interrogation119 = " beat";
	const string CONST_interrogation118 = " beats";
	const string CONST_interrogation115 = "screaming \"";
	const string CONST_interrogation114 = " had a near-death experience and met John Lennon.";
	const string CONST_interrogation113 = " had a near-death experience and met God in heaven.";
	const string CONST_interrogation112 = " clumsily rescues it from cardiac arrest with a defibrillator.";
	const string CONST_interrogation111 = " from any health damage.";
	const string CONST_interrogation110 = " skillfully saves ";
	const string CONST_interrogation109 = " deftly rescues it from cardiac arrest with a defibrillator.";
	const string CONST_interrogation108 = "'s incompetence at first aid.";
	const string CONST_interrogation107 = " dies due to ";
	const string CONST_interrogation106 = "'s weakened state.";
	const string CONST_interrogation105 = "It is a lethal overdose in ";
	const string CONST_interrogation104 = " pants.";
	const string CONST_interrogation103 = " has a panic attack and shits ";
	const string CONST_interrogation102 = " has a panic attack and [makes a stinky].";
	const string CONST_interrogation101 = " flatlines.";
	const string CONST_interrogation100 = " uses a defibrillator repeatedly but ";
	const string CONST_interrogation099 = " foams at the mouth and its eyes roll back in its skull.";
	const string CONST_interrogation098 = "It is subjected to dangerous hallucinogens.";
	const string CONST_interrogation097 = "converted into a makeshift cell.";
	const string CONST_interrogation096 = " is locked in a back room ";
	const string CONST_interrogation095 = "in the middle of a back room.";
	const string CONST_interrogation094 = " is tied hands and feet to a metal chair";
	const string CONST_interrogation093 = "The Automaton";
	const string CONST_interrogation092 = ": Day ";
	const string CONST_interrogation091 = "The Education of ";
	const string CONST_interrogation089 = " in cold blood.";
	const string CONST_interrogation088 = "execute ";
	const string CONST_interrogation087 = "There is no one able to get up the nerve to ";
	const string CONST_interrogation085 = " by ";
	const string CONST_interrogation084 = " executes ";
	const string CONST_interrogation082 = "The Final Education of ";
	const string CONST_interrogation081 = "Press Enter to Confirm the Plan";
	const string CONST_interrogation080 = "K - Kill the Hostage";
	const string CONST_interrogation079 = "($50)";
	const string CONST_interrogation078 = "Hallucinogenic Drugs    ";
	const string CONST_interrogation077 = "No ";
	const string CONST_interrogation076 = "E - ";
	const string CONST_interrogation075 = "($250)";
	const string CONST_interrogation074 = "Expensive Props     ";
	const string CONST_interrogation072 = "D - ";
	const string CONST_interrogation071 = "Violently Beaten    ";
	const string CONST_interrogation070 = "Not ";
	const string CONST_interrogation069 = "C - ";
	const string CONST_interrogation068 = "Physical Restraints   ";
	const string CONST_interrogation066 = "B - ";
	const string CONST_interrogation065 = "Attempt to Convert";
	const string CONST_interrogation064 = "No Verbal Contact     ";
	const string CONST_interrogation063 = "A - ";
	const string CONST_interrogation062 = "Selecting a Liberal Interrogation Plan";
	const string CONST_interrogation061 = "The Execution of an Automaton         ";
	const string CONST_interrogation058 = "murder ";
	const string CONST_interrogation057 = "The Conservative would like to ";
	const string CONST_interrogation056 = "The Conservative hates ";
	const string CONST_interrogation055 = "toward ";
	const string CONST_interrogation054 = "The Conservative is uncooperative ";
	const string CONST_interrogation053 = "The Conservative likes ";
	const string CONST_interrogation052 = " as its only friend.";
	const string CONST_interrogation051 = "to ";
	const string CONST_interrogation050 = "The Conservative clings helplessly ";
	const string CONST_interrogation049 = "Outfit: ";
	const string CONST_interrogation048 = "Wisdom: ";
	const string CONST_interrogation047 = "Heart: ";
	const string CONST_interrogation046 = "Psychology Skill: ";
	const string CONST_interrogation045 = "Health: ";
	const string CONST_interrogation044 = "Lead Interrogator: ";
	const string CONST_interrogation039 = "Prisoner: ";
	const string CONST_interrogation038 = "                                  ";
	const string CONST_interrogation037 = "cling_to_science.txt";
	const string CONST_interrogation036 = "cling_to_business.txt";
	const string CONST_interrogation035 = "cling_to_science_one_line.txt";
	const string CONST_interrogation034 = "cling_to_business_one_line.txt";
	const string CONST_interrogation033 = "vanilla_recruit.txt";
	const string CONST_interrogation032 = "discuss.txt";
	const string CONST_interrogation031 = "cling_to_religion_one_line.txt";
	const string CONST_interrogation030 = "cling_to_religion.txt";
	const string CONST_interrogation029 = "clinging_one_line.txt";
	const string CONST_interrogation028 = "cling_to_interrogater.txt";
	const string CONST_interrogation027 = "interrogater_shows_compassion.txt";
	const string CONST_interrogation026 = "interrogater_shows_compassion_one_line.txt";
	const string CONST_interrogation025 = "develops_hatred.txt";
	const string CONST_interrogation024 = "develops_hatred_one_line.txt";
	const string CONST_interrogation023 = "smarter_than_you.txt";
	const string CONST_interrogation022 = "smarter_than_you_one_line.txt";
	const string CONST_interrogation021 = "good_trip_companion.txt";
	const string CONST_interrogation020 = "bad_trip.txt";
	const string CONST_interrogation019 = "fall_in_love.txt";
	const string CONST_interrogation018 = "good_trip.txt";
	const string CONST_interrogation017 = "self_wounding.txt";
	const string CONST_interrogation016 = "broods_over_death.txt";
	const string CONST_interrogation015 = "partial_conversion.txt";
	const string CONST_interrogation014 = "resist_drugs.txt";
	const string CONST_interrogation013 = "use_props.txt";
	const string CONST_interrogation012 = "prays_on_drugs.txt";
	const string CONST_interrogation011 = "prays.txt";
	const string CONST_interrogation010 = "words_to_scream.txt";
	const string CONST_interrogation009 = "words_meaning_screaming.txt";
	const string CONST_interrogation008 = "beat_with_props.txt";
	const string CONST_interrogation007 = "screaming.txt";
	const string CONST_interrogation006 = "low_heart_torture_props.txt";
	const string CONST_interrogation005 = "feels_sick.txt";
	const string CONST_interrogation004 = "execution.txt";

	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";

#include "../creature/creature.h"
#include "../locations/locationsEnums.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../log/log.h"
#include "../common/commondisplayCreature.h"
	// for void printhealthstat(Creature &,int,int,char);
#include "../common/getnames.h"
// for std::string getview(short ,bool );
#include "../common/commonactionsCreature.h"
// for  void sleeperize_prompt(Creature &,Creature &,int);
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../common/creaturePoolCreature.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
	vector<string> execution;
	vector<string> feels_sick;
	vector<string> low_heart_torture_props;
	vector<string> screaming;
	vector<string> beat_with_props;
	vector<string> words_meaning_screaming;
	vector<string> words_to_scream;
	vector<string> prays;
	vector<string> prays_on_drugs;
	vector<string> use_props;
	vector<string> resist_drugs;
	vector<string> partial_conversion;
	vector<string> broods_over_death;
	vector<string> self_wounding;
	vector<string> good_trip;
	vector<vector<string> > fall_in_love;
	vector<vector<string> > bad_trip;
	vector<vector<string> > good_trip_companion;
	vector<string> smarter_than_you_one_line;
	vector<vector<string> > smarter_than_you;
	vector<string> develops_hatred_one_line;
	vector<vector<string> > develops_hatred;
	vector<string> interrogater_shows_compassion_one_line;
	vector<vector<string> > interrogater_shows_compassion;
	vector<vector<string> > cling_to_interrogater;
	vector<string> clinging_one_line;
	vector<vector<string> > cling_to_religion;
	vector<string> cling_to_religion_one_line;
	vector<vector<string> > discuss;
	vector<string> vanilla_recruit;
	vector<vector<string> > cling_to_business;
	vector<vector<string> > cling_to_science;
	vector<string> cling_to_business_one_line;
	vector<string> cling_to_science_one_line;
	const int DOUBLE_LINE = 2;
	vector<file_and_text_collection> interrogate_text_file_collection = {
		/*InterrogationST.cpp*/
		customText(&execution, interrogate + CONST_interrogation004),
		customText(&feels_sick, interrogate + CONST_interrogation005),
		customText(&low_heart_torture_props, interrogate + CONST_interrogation006),
		customText(&screaming, interrogate + CONST_interrogation007),
		customText(&beat_with_props, interrogate + CONST_interrogation008),
		customText(&words_meaning_screaming, interrogate + CONST_interrogation009),
		customText(&words_to_scream, interrogate + CONST_interrogation010),
		customText(&prays, interrogate + CONST_interrogation011),
		customText(&prays_on_drugs, interrogate + CONST_interrogation012),
		customText(&use_props, interrogate + CONST_interrogation013),
		customText(&resist_drugs, interrogate + CONST_interrogation014),
		customText(&partial_conversion, interrogate + CONST_interrogation015),
		customText(&broods_over_death, interrogate + CONST_interrogation016),
		customText(&self_wounding, interrogate + CONST_interrogation017),
		customText(&good_trip, interrogate + CONST_interrogation018),
		customText(&fall_in_love, interrogate + CONST_interrogation019, DOUBLE_LINE),
		customText(&bad_trip, interrogate + CONST_interrogation020, DOUBLE_LINE),
		customText(&good_trip_companion, interrogate + CONST_interrogation021, DOUBLE_LINE),
		customText(&smarter_than_you_one_line, interrogate + CONST_interrogation022),
		customText(&smarter_than_you, interrogate + CONST_interrogation023, DOUBLE_LINE),
		customText(&develops_hatred_one_line, interrogate + CONST_interrogation024),
		customText(&develops_hatred, interrogate + CONST_interrogation025, DOUBLE_LINE),
		customText(&interrogater_shows_compassion_one_line, interrogate + CONST_interrogation026),
		customText(&interrogater_shows_compassion, interrogate + CONST_interrogation027, DOUBLE_LINE),
		customText(&cling_to_interrogater, interrogate + CONST_interrogation028, DOUBLE_LINE),
		customText(&clinging_one_line, interrogate + CONST_interrogation029),
		customText(&cling_to_religion, interrogate + CONST_interrogation030, DOUBLE_LINE),
		customText(&cling_to_religion_one_line, interrogate + CONST_interrogation031),
		customText(&discuss, interrogate + CONST_interrogation032, DOUBLE_LINE),
		customText(&vanilla_recruit, interrogate + CONST_interrogation033),
		customText(&cling_to_business_one_line, interrogate + CONST_interrogation034),
		customText(&cling_to_science_one_line, interrogate + CONST_interrogation035),
		customText(&cling_to_business, interrogate + CONST_interrogation036, DOUBLE_LINE),
		customText(&cling_to_science, interrogate + CONST_interrogation037, DOUBLE_LINE),
	};
	// string feels_sick_and;
	//extern string singleDot;
	//extern string AND;
	//extern string singleSpace;
	//extern string commaSpace;
	enum InterrogationTechnqiues
	{
		TECHNIQUE_TALK,
		TECHNIQUE_RESTRAIN,
		TECHNIQUE_BEAT,
		TECHNIQUE_PROPS,
		TECHNIQUE_DRUGS,
		TECHNIQUE_KILL
	};
	string getDespairString(const bool drugs, const bool restrain, const bool religion);
	string victimPrays(const bool onDrugs);
	string getFallsInLove(const string name, const bool restrain);
	string getBadTrip(const string name, const bool restrain, const bool rapport);
	string outPsychologyCaptor(const string name);
	string triedConvertingTheAbused(const string name);
	string feelsBadForAbused(const string name);
	string stockholmSyndrome(const string name);
	string failToBreakReligion(const string a, const string cr);
	string failedToBreakBusiness(const string a, const string cr);
	string failedToBreakScience(const string a, const string cr);
	extern Log gamelog;
	extern Log gamelog;
	extern int stat_recruits;
	extern Log gamelog;
	extern int stat_kills;
	extern Log gamelog;
	extern Log gamelog;
	// Interrogation always enlightens
	extern bool AUTOENLIGHTEN;
	extern Log gamelog;
	extern MusicClass music;
	extern int stat_recruits;
	extern int stat_kills;
	extern class Ledger ledger;
	extern short lawList[LAWNUM];
#endif	//INTERROGATION_CPP
#ifdef	ITEM_CPP
// item.cpp
	const string CONST_item007 = "a";
	const string CONST_item006 = "an";
	const string CONST_item005 = "number";
	const string CONST_item004 = "itemtypeid";
	const string CONST_item003 = "itemtypename";

#endif	//ITEM_CPP
#ifdef	ITEMTYPE_CPP
// itemtype.cpp


#include "../items/itemtype.h"
	extern int year;
	const string CONST_itemtype007 = "Unknown element for item type << idname_ << ";
	const string CONST_itemtype006 = "LACKS IDNAME ";
	const string CONST_itemtype005 = "UNDEFINED";

	const string tag_fencevalue = "fencevalue";
	const string tag_name_future = "name_future";
	const string tag_name = "name";
	const string tag_idname = "idname";
	const string tag_id = "id";
#endif	//ITEMTYPE_CPP
#ifdef	JUSTICE_CPP
// justice.cpp

	const string counts_of = " counts of ";
	const string execution_in_three_months = "The execution is scheduled to occur three months from now.";
	const string justice = "justice\\";
	const string CONST_justiceB174 = "hiring an undocumented worker";
	const string CONST_justiceB173 = "hiring undocumented workers";
	const string CONST_justice182 = " months.";
	const string CONST_justice181 = " is due to be executed in ";
	const string CONST_justice180 = " is due to be released next month.";
	const string CONST_justice179 = " is due to be executed next month.";
	const string CONST_justice178 = "No doubt there are some mental scars, but the Liberal is back.";
	const string CONST_justice177 = " has been released from prison.";
	const string CONST_justice176 = "If you can't protect your own people, who can you protect?";
	const string CONST_justice175 = " has failed the Liberal Crime Squad.";
	const string CONST_justice174 = "by ";
	const string CONST_justice173 = "Today, the Conservative Machine executed ";
	const string CONST_justice172 = "FOR SHAME:";
	const string CONST_justice171 = "due to the abolition of the death penalty.";
	const string CONST_justice170 = "'s death sentence has been commuted to life, ";
	const string CONST_justice169 = " seems to be mostly fine, though.";
	const string CONST_justice168 = " is kinda losing it in here. Juice, that is.";
	const string CONST_justice167 = " has become a more hardened, Juicier criminal.";
	const string CONST_justice166 = "The LCS will rise again! Multiple LCS members escape!";
	const string CONST_justice165 = "Another imprisoned LCS member also gets out!";
	const string CONST_justice164 = " escaped from prison!";
	const string CONST_justice163 = " intentionally ODs on smuggled drugs, then breaks out of the medical ward!";
	const string CONST_justice162 = " jimmies the cell door and cuts the outer fence in the dead of night!";
	const string CONST_justice161 = " puts on smuggled street clothes and calmly walks out of prison.";
	const string CONST_justice160 = " codes a virus on a smuggled phone that opens all the prison doors!";
	const string CONST_justice159 = " leads a riot with dozens of prisoners chanting the LCS slogan!";
	const string CONST_justice158 = " managed to avoid lasting injury.";
	const string CONST_justice157 = " is found dead.";
	const string CONST_justice156 = " is badly hurt in the process.";
	const string CONST_justice152 = " consumes drugs that simulate death, and is thrown out with the trash!";
	const string CONST_justice151 = " picks the lock on their leg chains and then sneaks away!";
	const string CONST_justice150 = " wears an electrician's outfit and rides away with some contractors.";
	const string CONST_justice149 = " leads the oppressed prisoners and overwhelms the prison guards!";
	const string CONST_justice148 = " remains strong.";
	const string CONST_justice147 = " abandons the Liberal Crime Squad!";
	const string CONST_justice146 = " only stays loyal to the LCS for ";
	const string CONST_justice145 = " silently grows Wiser...";
	const string CONST_justice144 = " feels bad about LCS actions, and loses juice!";
	const string CONST_justice143 = "The court accepts the plea.";
	const string CONST_justice142 = "nolo";
	const string CONST_justice141 = ", less a month for time already served.";
	const string CONST_justice140 = " will be returned to prison to resume an earlier sentence";
	const string CONST_justice139 = " is free!";
	const string CONST_justice138 = "NOT GUILTY!";
	const string CONST_justice134 = "The prosecution declines to re-try the case.";
	const string CONST_justice133 = "The case will be re-tried next month.";
	const string CONST_justice132 = "But they can't reach a verdict!";
	const string CONST_justice131 = "The jury has returned from deliberations.";
	const string CONST_justice130 = "The jury leaves to consider the case.";
	const string CONST_justice129 = " to acquit)";
	const string CONST_justice128 = ", need ";
	const string CONST_justice127 = " (";
	const string CONST_justice126 = " had the jury, judge, and prosecution crying for freedom.";
	const string CONST_justice125 = " made a very powerful case.";
	const string CONST_justice124 = " worked the jury very well.";
	const string CONST_justice123 = "'s arguments were pretty good.";
	const string CONST_justice122 = " did all right, but made some mistakes.";
	const string CONST_justice121 = "'s case really sucked.";
	const string CONST_justice120 = " makes one horrible mistake after another.";
	const string CONST_justice119 = " conducts an incredible defense.";
	const string CONST_justice118 = "and shout \"NOT GUILTY!\" before deliberations even began.";
	const string CONST_justice117 = "'s arguments made several of the jurors stand up ";
	const string CONST_justice116 = "The defense is extremely compelling.";
	const string CONST_justice115 = "The defense makes the prosecution look like amateurs.";
	const string CONST_justice114 = "The defense was really slick.";
	const string CONST_justice113 = "Defense arguments were pretty good.";
	const string CONST_justice112 = "The defense was lackluster.";
	const string CONST_justice111 = "The defense is totally lame.";
	const string CONST_justice110 = "The defense attorney accidentally said \"My client is GUILTY!\" during closing.";
	const string CONST_justice109 = "The defense attorney rarely showed up.";
	const string CONST_justice108 = " to convict)";
	const string CONST_justice107 = " to +";
	const string CONST_justice106 = " (+";
	const string CONST_justice105 = "The prosecution is incredibly strong.";
	const string CONST_justice104 = "The prosecution makes an airtight case.";
	const string CONST_justice103 = "The prosecution's case is solid.";
	const string CONST_justice102 = "The prosecution gives a standard presentation.";
	const string CONST_justice101 = "The prosecution's presentation is terrible.";
	const string CONST_justice098 = "The jury is a bit Conservative.";
	const string CONST_justice097 = "The jury is quite moderate.";
	const string CONST_justice096 = "The jury is fairly Liberal.";
	const string CONST_justice095 = "'s best friend from childhood is a juror.";
	const string CONST_justice094 = "'s CONSERVATIVE ARCH-NEMESIS will represent the prosecution!!!";
	const string CONST_justice093 = "'s favor!";
	const string CONST_justice092 = " ensures the jury is stacked in ";
	const string CONST_justice091 = "The trial proceeds.  Jury selection is first.";
	const string CONST_justice090 = " is standing trial.";
	const string CONST_justice089 = "Intelligence: ";
	const string CONST_justice088 = "Law: ";
	const string CONST_justice087 = "Charisma: ";
	const string CONST_justice086 = "Persuasion: ";
	const string CONST_justice085 = "Heart: ";
	const string CONST_justice084 = "'s offer to assist pro bono.";
	const string CONST_justice083 = "E - Accept sleeper ";
	const string CONST_justice082 = "D - Pay $5000 to hire ace Liberal attorney ";
	const string CONST_justice081 = "C - Plead guilty.";
	const string CONST_justice080 = "B - Defend self!";
	const string CONST_justice079 = "A - Use a court-appointed attorney.";
	const string CONST_justice078 = "How will you conduct the defense?";
	const string CONST_justice077 = "A former LCS member will testify against ";
	const string CONST_justice076 = " former LCS members will testify against ";
	const string CONST_justice075 = "loitering";
	const string CONST_justice074 = "indecent exposure";
	const string CONST_justice073 = "disturbing the peace";
	const string CONST_justice072 = "resisting arrest";
	const string CONST_justice071 = "vandalism";
	const string CONST_justice070 = "breaking and entering";
	const string CONST_justice069 = "unlawful burial";
	const string CONST_justice068 = "unlawful access of an information system";
	const string CONST_justice067 = "interference with interstate commerce";
	const string CONST_justice066 = "possession of an illegal weapon";
	const string CONST_justice065 = "firing an illegal weapon";
	const string CONST_justice064 = "hiring an illegal alien";
	const string CONST_justice063 = "hiring illegal aliens";
	const string CONST_justice062 = "prostitution";
	const string CONST_justice061 = "petty larceny";
	const string CONST_justice060 = "credit card fraud";
	const string CONST_justice059 = "grand theft auto";
	const string CONST_justice058 = "misdemeanor assault";
	const string CONST_justice057 = "felony assault";
	const string CONST_justice056 = "extortion";
	const string CONST_justice055 = "racketeering";
	const string CONST_justice054 = "jury tampering";
	const string CONST_justice053 = "aiding a prison escape";
	const string CONST_justice052 = "escaping prison";
	const string CONST_justice051 = "drug dealing";
	const string CONST_justice050 = "sedition";
	const string CONST_justice049 = "flag burning";
	const string CONST_justice048 = "felony flag burning";
	const string CONST_justice047 = "Flag Murder";
	const string CONST_justice046 = "arson";
	const string CONST_justice045 = "bank robbery";
	const string CONST_justice044 = "kidnapping";
	const string CONST_justice043 = "murder";
	const string CONST_justice042 = "terrorism";
	const string CONST_justice041 = "treason";
	const string CONST_justice040 = ", is charged with ";
	const string CONST_justice039 = "The defendant, ";
	const string CONST_justice038 = "The judge reads the charges:";
	const string CONST_justice037 = " reads the charges, trying to hide a smile:";
	const string CONST_justice035 = "to be served consecutively";
	const string CONST_justice034 = "to be served concurrently";
	const string CONST_justice033 = ",";
	const string CONST_justice032 = " in prison";
	const string CONST_justice031 = "s";
	const string CONST_justice030 = " month";
	const string CONST_justice029 = " years in prison";
	const string CONST_justice028 = "life in prison";
	const string CONST_justice027 = "Have a nice day, ";
	const string CONST_justice026 = " consecutive life terms in prison";
	const string CONST_justice025 = ", you are sentenced to ";
	const string CONST_justice024 = ", consider this a warning.  You are free to go.";
	const string CONST_justice022 = "You will be returned to prison to resume it";
	const string CONST_justice021 = ", the court sees no need to add to your existing sentence.";
	const string CONST_justice020 = ", you are sentenced to DEATH!";
	const string CONST_justice019 = ", you will be returned to prison to carry out your death sentence.";
	const string CONST_justice018 = "During sentencing, the judge grants some leniency.";
	const string CONST_justice017 = "GUILTY!";
	const string CONST_justice016 = "general_experiences.txt";
	const string CONST_justice015 = "bad_experiences.txt";
	const string CONST_justice014 = "good_experiences.txt";
	const string CONST_justice013 = "labor_camp_experiences.txt";
	const string CONST_justice012 = "reeducation_experiences.txt";
	const string CONST_justice011 = "supposedly_painless_execution_method.txt";
	const string CONST_justice010 = "standard_execution_methods.txt";
	const string CONST_justice009 = "cruel_and_unusual_execution_methods.txt";
	const string CONST_justice008 = "conservative_jury.txt";
	const string CONST_justice007 = "liberal_jury.txt";

	const string tag_ARMOR = "ARMOR";
	const string tag_ARMOR_CLOTHES = "ARMOR_CLOTHES";
	const string tag_ARMOR_WORKCLOTHES = "ARMOR_WORKCLOTHES";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";

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
		customText(&liberal_jury, justice + CONST_justice007),
		customText(&conservative_jury, justice + CONST_justice008),
		customText(&cruel_and_unusual_execution_methods, justice + CONST_justice009),
		customText(&standard_execution_methods, justice + CONST_justice010),
		customText(&supposedly_painless_execution_method, justice + CONST_justice011),
		customText(&reeducation_experiences, justice + CONST_justice012),
		customText(&labor_camp_experiences, justice + CONST_justice013),
		customText(&good_experiences, justice + CONST_justice014),
		customText(&bad_experiences, justice + CONST_justice015),
		customText(&general_experiences, justice + CONST_justice016),
	};
#include "../common/musicClass.h"
	// string counts_of; 
	//extern string string_sleeper;
	//extern string singleDot;
	//extern string AND;
	//extern string commaSpace;
	//extern string singleSpace;
	// string execution_in_three_months;
#include "../common/creaturePool.h"
#include "../locations/locationsPool.h"
	void printSingleCrime(const CreatureJustice g, const Lawflags law_flag, const int typenum, const string crime_string, const bool mention_multiple_counts = false);
	map<Lawflags, string> crimeBlockOne = {
		map<Lawflags, string>::value_type(LAWFLAG_TREASON, CONST_justice041),
		map<Lawflags, string>::value_type(LAWFLAG_TERRORISM, CONST_justice042),
		map<Lawflags, string>::value_type(LAWFLAG_MURDER, CONST_justice043),
		map<Lawflags, string>::value_type(LAWFLAG_KIDNAPPING, CONST_justice044),
		map<Lawflags, string>::value_type(LAWFLAG_BANKROBBERY, CONST_justice045),
		map<Lawflags, string>::value_type(LAWFLAG_ARSON, CONST_justice046),
	};
	map<Lawflags, string> crimeBlockTwo = {
		map<Lawflags, string>::value_type(LAWFLAG_SPEECH, CONST_justice050),
		map<Lawflags, string>::value_type(LAWFLAG_BROWNIES, CONST_justice051),
		map<Lawflags, string>::value_type(LAWFLAG_ESCAPED, CONST_justice052),
		map<Lawflags, string>::value_type(LAWFLAG_HELPESCAPE, CONST_justice053),
		map<Lawflags, string>::value_type(LAWFLAG_JURY, CONST_justice054),
		map<Lawflags, string>::value_type(LAWFLAG_RACKETEERING, CONST_justice055),
		map<Lawflags, string>::value_type(LAWFLAG_EXTORTION, CONST_justice056),
		map<Lawflags, string>::value_type(LAWFLAG_ARMEDASSAULT, CONST_justice057),
		map<Lawflags, string>::value_type(LAWFLAG_ASSAULT, CONST_justice058),
		map<Lawflags, string>::value_type(LAWFLAG_CARTHEFT, CONST_justice059),
		map<Lawflags, string>::value_type(LAWFLAG_CCFRAUD, CONST_justice060),
		map<Lawflags, string>::value_type(LAWFLAG_THEFT, CONST_justice061),
		map<Lawflags, string>::value_type(LAWFLAG_PROSTITUTION, CONST_justice062),
	};
	map<Lawflags, string> crimeBlockThree = {
		map<Lawflags, string>::value_type(LAWFLAG_COMMERCE, CONST_justice067),
		map<Lawflags, string>::value_type(LAWFLAG_INFORMATION, CONST_justice068),
		map<Lawflags, string>::value_type(LAWFLAG_BURIAL, CONST_justice069),
		map<Lawflags, string>::value_type(LAWFLAG_BREAKING, CONST_justice070),
		map<Lawflags, string>::value_type(LAWFLAG_VANDALISM, CONST_justice071),
		map<Lawflags, string>::value_type(LAWFLAG_RESIST, CONST_justice072),
		map<Lawflags, string>::value_type(LAWFLAG_DISTURBANCE, CONST_justice073),
		map<Lawflags, string>::value_type(LAWFLAG_PUBLICNUDITY, CONST_justice074),
		map<Lawflags, string>::value_type(LAWFLAG_LOITERING, CONST_justice075),
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
	extern Log gamelog;
	extern short lawList[LAWNUM];
	enum LegalDefense {
		UNDECIDED = -1,
		COURT_ATTORNEY = 0,
		SELF_REPRESENT = 1,
		PLEAD_GUILTY = 2,
		ACE_ATTORNEY = 3,
		SLEEPER_ATTORNEY = 4
	};
	// Show die rolls, 100% accurate poll numbers
	extern bool SHOWMECHANICS;
	extern Log gamelog;
	extern Log gamelog;
	extern MusicClass music;
	extern class Ledger ledger;
	extern unsigned long attorneyseed[RNG_SIZE];
	extern unsigned long seed[RNG_SIZE];
	extern Log gamelog;
	extern vector<DeprecatedCreature *> pool;
	extern Log gamelog;
	extern Log gamelog;
	extern vector<DeprecatedCreature *> pool;
	extern Log gamelog;
	extern int stat_dead;
	extern short lawList[LAWNUM];
	extern vector<DeprecatedCreature *> pool;
#endif	//JUSTICE_CPP
#ifdef	LCSIO_CPP
// lcsio.cpp

#include <tinydir.h>
	extern char homedir[MAX_PATH_SIZE];
	extern char artdir[MAX_PATH_SIZE];
	const string arttest = "newspic.cpc";
	const string CONST_lcsio014 = ".dat";
	const string CONST_lcsio013 = ".";
	const string CONST_lcsio012 = ".lcs/";
	const string CONST_lcsio011 = "/";
	const string CONST_lcsio010 = "./";
	const string CONST_lcsio009 = "HOME";
	const string CONST_lcsio008 = "../art/";
	const string CONST_lcsio007 = "./art/";
	const string CONST_lcsio006 = "/usr/games/lcs/art/";
	const string CONST_lcsio005 = "/usr/games/share/lcs/art/";
	const string CONST_lcsio004 = "/usr/share/lcs/art/";
	const string CONST_lcsio003 = "/usr/local/share/lcs/art/";
	const string CONST_lcsio002 = "/lcs/art/";
	const string CONST_lcsioX01 = "score";

#endif	//LCSIO_CPP
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
//extern string spaceDashSpace;
//extern string closeParenthesis;
// string bound_to_rile_up;
// string major_news_take_it_up;
	map<short, string> expenseTypes;
	map<short, string> incomeTypes;
	void constructLootIndices(vector<bool> &havetype, vector<int> &loottypeindex, const vector<string> dox);
	extern MusicClass music;

	extern Log gamelog;
	extern CCSexposure ccsexposure;
	extern Log gamelog;
	extern short offended_corps;
	extern Log gamelog;
	extern short offended_corps;
	extern Log gamelog;
	extern short offended_corps;
	extern Log gamelog;
	extern short offended_corps;
	extern Log gamelog;
	extern short offended_cia;
	extern Log gamelog;

	extern short offended_cablenews;
	extern Log gamelog;
	const string bound_to_rile_up = "This is bound to get the Corporations a little riled up.";
	const string major_news_take_it_up = "The major networks and publications take it up and run it for weeks.";

	const string CONST_lcsmonthly050 = "promising someone company profits in exchange for sexual favors.";
	const string CONST_lcsmonthly049 = "that seem to touch on every fetish known to man.";
	const string CONST_lcsmonthly048 = "to the FDA official overseeing the CEO's products.";
	const string CONST_lcsmonthly047 = "implying that he has enslaved his houseservants.";
	const string CONST_lcsmonthly046 = "to himself.  They're very steamy.";
	const string CONST_lcsmonthly045 = "to an illicit gay lover.";
	const string CONST_lcsmonthly044 = "to the judge that acquit him in a corruption trial.";
	const string CONST_lcsmonthly043 = "addressed to his pet dog.  Yikes.";

	const string CONST_lcsmonthly041 = "playing with feces and urine.";
	const string CONST_lcsmonthly040 = "torturing an employee with a hot iron.";
	const string CONST_lcsmonthly039 = "waving a Nazi flag at a supremacist rally.";
	const string CONST_lcsmonthly038 = "castrating himself.";
	const string CONST_lcsmonthly037 = "making out with an FDA official overseeing the CEO's products.";
	const string CONST_lcsmonthly036 = "tongue-kissing an infamous dictator.";
	const string CONST_lcsmonthly035 = "engaging in heavy bondage.  A cucumber was involved in some way.";
	const string CONST_lcsmonthly034 = "participating in a murder.";
	const string CONST_lcsmonthly033 = "digging up graves and sleeping with the dead.";
	const string CONST_lcsmonthly032 = "engaging in lewd behavior with animals.";
	const string CONST_lcsmonthly052 = "showing that he has engaged in consistent tax evasion.";
	const string CONST_lcsmonthly058 = "describing an intricate tax scheme.";
	const string CONST_lcsmonthly057 = "cheerfully describing foreign corporate sweatshops.";
	const string CONST_lcsmonthly056 = "containing a memo: \"Terminate the pregnancy, I terminate you.\"";
	const string CONST_lcsmonthly055 = "with a list of gay employees entitled \"Homo-workers\".";
	const string CONST_lcsmonthly054 = "describing a genetic monster created in a lab.";
	const string CONST_lcsmonthly079 = "documenting the infiltration of a pro-choice group.";
	const string CONST_lcsmonthly078 = "used to keep tabs on gay citizens.";
	const string CONST_lcsmonthly077 = "documenting \"harmful speech\" made by innocent citizens.";
	const string CONST_lcsmonthly076 = "containing private information on innocent citizens.";
	const string CONST_lcsmonthly075 = "documenting the planned assassination of a Liberal federal judge.";
	const string CONST_lcsmonthly074 = "documenting the overthrow of a government.";

	const string CONST_lcsmonthly086 = "documenting widespread corruption in the force.";
	const string CONST_lcsmonthly085 = "documenting a forced confession.";
	const string CONST_lcsmonthly084 = "documenting a systematic invasion of privacy by the force.";
	const string CONST_lcsmonthly083 = "documenting a police torture case.";
	const string CONST_lcsmonthly082 = "documenting human rights abuses by the force.";

	const string CONST_lcsmonthly100 = "documenting gladiatorial matches held between prisoners by guards.";
	const string CONST_lcsmonthly090 = "promising Conservative rulings in exchange for appointments.";
	const string CONST_lcsmonthly089 = "taking bribes to acquit murderers.";

	const string CONST_lcsmonthly095 = "showing human test subjects dying under genetic research.";
	const string CONST_lcsmonthly094 = "covering up the accidental creation of a genetic monster.";
	const string CONST_lcsmonthly093 = "studying the effects of torture on cats.";
	const string CONST_lcsmonthly092 = "documenting horrific animal rights abuses.";


	const string CONST_lcsmonthly099 = "documenting widespread corruption among prison employees.";
	const string CONST_lcsmonthly098 = "documenting a prison torture case.";
	const string CONST_lcsmonthly097 = "documenting human rights abuses by prison guards.";


	const string CONST_lcsmonthly110 = "planning to drum up a false scandal about a Liberal figure.";
	const string CONST_lcsmonthly105 = "instructing a female anchor to 'get sexier or get a new job'.";
	const string CONST_lcsmonthly103 = "mandating negative coverage of Liberal politicians.";
	const string CONST_lcsmonthly102 = "calling their news 'the vanguard of Conservative thought'.";

	const string CONST_lcsmonthly109 = "saying 'it's okay to lie, they don't need the truth'.";
	const string CONST_lcsmonthly108 = "calling listeners 'sheep to be told what to think'.";


	const string CONST_lcsmonthly140 = "Press any key to reflect on the report.";
	const string CONST_lcsmonthly139 = "Press Enter to reflect on the report.  ";
	const string CONST_lcsmonthly138 = "$";
	const string CONST_lcsmonthly137 = "Total Liquid Assets:";
	const string CONST_lcsmonthly135 = "Miscellaneous Loot";
	const string CONST_lcsmonthly133 = "Ammunition";
	const string CONST_lcsmonthly131 = "Clothing and Armor";
	const string CONST_lcsmonthly129 = "Tools and Weapons";
	const string CONST_lcsmonthly127 = "Cash";
	const string CONST_lcsmonthly126 = " ($0)";
	const string CONST_lcsmonthly125 = " (-$";
	const string CONST_lcsmonthly124 = " (+$";
	const string CONST_lcsmonthly122 = "-";
	const string CONST_lcsmonthly121 = "+";
	const string CONST_lcsmonthly120 = "Net Change This Month (Day):";
	const string CONST_lcsmonthly117 = "-$";
	const string CONST_lcsmonthly114 = "+$";
	const string CONST_lcsmonthly113 = "Liberal Crime Squad: Funding Report";
	const string CONST_lcsmonthly111 = "This is bound to get the Conservative masses a little riled up.";

	const string CONST_lcsmonthly107 = "The Liberal Guardian runs a story featuring AM radio plans ";

	const string CONST_lcsmonthly101 = "The Liberal Guardian runs a story featuring cable news memos ";

	const string CONST_lcsmonthly096 = "The Liberal Guardian runs a story featuring prison documents ";

	const string CONST_lcsmonthly091 = "The Liberal Guardian runs a story featuring research papers ";

	const string CONST_lcsmonthly088 = "The Liberal Guardian runs a story with evidence of a Conservative judge ";

	const string CONST_lcsmonthly081 = "The Liberal Guardian runs a story featuring police records ";
	const string CONST_lcsmonthly080 = "This is bound to get the Government a little riled up.";

	const string CONST_lcsmonthly073 = "The Liberal Guardian runs a story featuring CIA and other intelligence files ";
	const string CONST_lcsmonthly072 = "This is the beginning of the end for the Conservative Crime Squad.";
	const string CONST_lcsmonthly071 = "News denounce the CCS.";
	const string CONST_lcsmonthly070 = "toward the revelations, and the speed with which even AM Radio and Cable";
	const string CONST_lcsmonthly069 = "for months. One thing is clear, however, from the immediate public reaction";
	const string CONST_lcsmonthly068 = "country, and the full ramifications of this revelation may not be felt";
	const string CONST_lcsmonthly067 = "The scandal reaches into the heart of the Conservative leadership in the";
	const string CONST_lcsmonthly066 = "against.";
	const string CONST_lcsmonthly065 = "as a foil when no other enemies were present to direct public energy";
	const string CONST_lcsmonthly064 = "above prosecution, and could hunt down law-abiding Liberals and act";
	const string CONST_lcsmonthly063 = "extensive planning to create an extra-judicial death squad that would be";
	const string CONST_lcsmonthly062 = "in the state and federal governments. Sections precisely document the";
	const string CONST_lcsmonthly061 = "responsibilities of Conservative Crime Squad sympathizers and supporters";
	const string CONST_lcsmonthly060 = "the CCS organization, also revealing in extreme detail the names and ";
	const string CONST_lcsmonthly059 = "The Liberal Guardian runs more than one thousand pages of documents about ";

	const string CONST_lcsmonthly053 = "The Liberal Guardian runs a story featuring Corporate files ";
	const string CONST_lcsmonthly051 = "The Liberal Guardian runs a story featuring a major CEO's tax papers ";

	const string CONST_lcsmonthly042 = "The Liberal Guardian runs a story featuring love letters from a major CEO ";

	const string CONST_lcsmonthly031 = "The Liberal Guardian runs a story featuring photos of a major CEO ";
	const string CONST_lcsmonthly030 = "Enter - Not in this month's Liberal Guardian";
	const string CONST_lcsmonthly029 = "Do you want to run a special edition?";
	const string CONST_lcsmonthly028 = "Liberal Guardian.";
	const string CONST_lcsmonthly027 = "The response is electric. Everyone is talking about this month's ";
	const string CONST_lcsmonthly026 = "The response is very strong. People are changing their minds.";
	const string CONST_lcsmonthly025 = "Many people are reading it.";
	const string CONST_lcsmonthly024 = "A fair number of people are reading it.";
	const string CONST_lcsmonthly023 = "Very few people seem to be interested.";
	const string CONST_lcsmonthly022 = "Unfortunately, nobody seems interested.";
	const string CONST_lcsmonthly021 = "The only readers are Conservatives, who seem to think it's funny.";
	const string CONST_lcsmonthly020 = " is published.";
	const string CONST_lcsmonthly019 = "The monthly Liberal Guardian online newsletter";
	const string CONST_lcsmonthly018 = "The monthly Liberal Guardian newspaper";

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

	extern short offended_amradio;
	extern Log gamelog;
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
	extern short offended_firemen;
	extern MusicClass music;
	extern short lawList[LAWNUM];
	static const char dotdotdot[] = ". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ";
	extern class Ledger ledger;
	extern char disbanding;
	extern MusicClass music;
	extern class Ledger ledger;
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
#ifdef	LIBERALAGENDA_CPP
// liberalagenda.cpp

#include "../creature/creatureEnums.h"
//#include "../common/commondisplay.h"
	void set_alignment_color(short alignment, bool extended_range = false);
	//#include "../common/getnames.h"
	string getlaw(int l);
	//#include "../common/commonactions.h"
	void cleangonesquads();
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../common/musicClass.h"
	vector<string> supremeChars;
	vector<string> courtChars;
	//string pressLToViewHighScores;
	map<short, vector<string> > endgameLawStrings;
#include "../common/creaturePool.h"
	enum Pages
	{
		PAGE_LEADERS,
		PAGE_ISSUES_A,
		PAGE_ISSUES_B,
		//PAGE_POLLS_A,
		//PAGE_POLLS_B
		PAGENUM
	};
	vector<string> disbandingMessage;
	vector<string> issue_phrases;

	extern int year;
	extern int disbandtime;
	extern bool stalinmode;
	extern short wincondition;
	extern short lawList[LAWNUM];
	extern short court[COURTNUM];
	extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
	extern bool stalinmode;
	extern short house[HOUSENUM];
	extern short senate[SENATENUM];
	extern short exec[EXECNUM];
	extern short execterm;
	extern short exec[EXECNUM];
	extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	extern short court[COURTNUM];
	extern short wincondition;
	extern short lawList[LAWNUM];
	extern short exec[EXECNUM];
	extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	extern MusicClass music;
	extern short wincondition;
	const string pressLToViewHighScores = "Press 'L' to view the high score list.";

	const string mostlyendings = "mostlyendings\\";

	const string CONST_liberalagenda012 = "courtChars.txt";
	const string CONST_liberalagenda011 = "supremeChars.txt";
	const string CONST_liberalagenda010 = "issue_phrases.txt";
	const string CONST_liberalagenda009 = "disbandingMessage.txt";
	vector<file_and_text_collection> liberl_agenda_text_file_collection = {
	customText(&disbandingMessage, mostlyendings + CONST_liberalagenda009),
	customText(&issue_phrases, mostlyendings + CONST_liberalagenda010),
	customText(&supremeChars, mostlyendings + CONST_liberalagenda011),
	customText(&courtChars, mostlyendings + CONST_liberalagenda012),
	};
	const string CONST_liberalagenda014 = "Type this Liberal phrase to confirm (press a wrong letter to rethink it):";
	const string CONST_liberalagenda013 = "Are you sure you want to disband?";
	const string CONST_liberalagenda066 = "Press D to disband and wait. Use cursors for other pages. Any other key to exit.";
	const string CONST_liberalagenda064 = "Arch-Conservative";
	const string CONST_liberalagenda063 = "-  ";
	const string CONST_liberalagenda062 = "Conservative  ";
	const string CONST_liberalagenda060 = "moderate  ";
	const string CONST_liberalagenda058 = "Liberal  ";
	const string CONST_liberalagenda056 = "Elite Liberal  ";
	const string CONST_liberalagenda055 = "Stalinist  ";
	const string CONST_liberalagenda044 = "Trial Judges";
	const string CONST_liberalagenda043 = "Stalinist Show";
	const string CONST_liberalagenda042 = "Replaced By";
	const string CONST_liberalagenda041 = "Ethics Officers";
	const string CONST_liberalagenda040 = "By Corporate";
	const string CONST_liberalagenda039 = "Replaced";
	const string CONST_liberalagenda038 = "Senate: ";
	const string CONST_liberalagenda037 = "House: ";
	const string CONST_liberalagenda034 = "Attorney General: ";
	const string CONST_liberalagenda033 = "Internal Affairs Commissar: ";
	const string CONST_liberalagenda032 = "Minister of Truth: ";
	const string CONST_liberalagenda031 = "Secretary of State: ";
	const string CONST_liberalagenda030 = "Foreign Affairs Commissar: ";
	const string CONST_liberalagenda029 = "Minister of Peace: ";
	const string CONST_liberalagenda028 = "Vice President: ";
	const string CONST_liberalagenda027 = "Premier: ";
	const string CONST_liberalagenda026 = "Minister of Love: ";
	const string CONST_liberalagenda025 = "(2nd Term):";
	const string CONST_liberalagenda024 = "(1st Term):";
	const string CONST_liberalagenda023 = "President ";
	const string CONST_liberalagenda022 = "General Secretary: ";
	const string CONST_liberalagenda021 = "King: ";
	const string CONST_liberalagenda036 = "The Congress consists of Stalinist Party loyalists.";
	const string CONST_liberalagenda035 = "The Congress consists of CEOs and televangelists.";

	const string CONST_liberalagenda020 = "�                 훤袴袴袴袴賈袴袴袴袴袴鳩袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴";
	const string CONST_liberalagenda019 = "� GENERAL SUMMARY � ISSUES A � ISSUES B �";
	const string CONST_liberalagenda018 = "�袴袴袴袴袴袴袴袴敲컴컴컴컴컴쩡컴컴컴컴커";
	const string CONST_liberalagenda050 = "鳩袴袴袴袴袴袴袴袴鳩袴袴袴袴暠          훤袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴";
	const string CONST_liberalagenda049 = "� GENERAL SUMMARY � ISSUES A � ISSUES B �";
	const string CONST_liberalagenda048 = "旼컴컴컴컴컴컴컴컴쩡컴컴컴컴케袴袴袴袴袴�";
	const string CONST_liberalagenda047 = "鳩袴袴袴袴袴袴袴袴�          훤袴袴袴袴賈袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴�";
	const string CONST_liberalagenda046 = "� GENERAL SUMMARY � ISSUES A � ISSUES B �";
	const string CONST_liberalagenda045 = "旼컴컴컴컴컴컴컴컴�袴袴袴袴袴뼛컴컴컴컴커";
	const string CONST_liberalagenda054 = "The country has been Stalinized.";
	const string CONST_liberalagenda053 = "The country has been Reaganified.";
	const string CONST_liberalagenda052 = "The country has achieved Elite Liberal status!";
	const string CONST_liberalagenda051 = "The country has achieved Liberal status!";

	const string CONST_liberalagenda017 = "The Status of the Liberal Agenda";
	const string CONST_liberalagenda016 = "The Abject Failure of the Liberal Agenda";
	const string CONST_liberalagenda015 = "The Triumph of the Liberal Agenda";
	const string tag_Sta = "Sta, ";
	const string tag_Libp = "Lib+, ";
	const string tag_Lib = "Lib, ";
	const string tag_Mod = "Mod, ";
	const string tag_Cons = "Cons, ";
	const string tag_Consp = "Cons+";
#endif	//LIBERALAGENDA_CPP
#ifdef	LOCATIONS_CPP
// locations.cpp

#include "../creature/newcreature.h"
#include "../locations/locations.h"
#include "../common/creaturePool.h"
//extern string singleSpace;
//extern string commaSpace;
#include "../customMaps.h"
	void strcpy(char* c, string str);
	void strcat(char* c, string str);
	extern short lawList[LAWNUM];
	const string CONST_locationsB130 = "Bunker";
	const string CONST_locationsB129 = "Bar & Grill";
	const string CONST_locationsB128 = "Bomb Shelter";
	const string CONST_locationsB127 = "Oubliette";
	const string CONST_locationsB126 = "Clinic";
	const string CONST_locationsB125 = "U Hospital";
	const string CONST_locationsB124 = "Radio Station";
	const string CONST_locationsB123 = "News Station";
	const string CONST_locationsB122 = "Chem Fact";
	const string CONST_locationsB121 = "Refinery";
	const string CONST_locationsB120 = "Plast Fact";
	const string CONST_locationsB119 = "Alum Fact";
	const string CONST_locationsB118 = "Shelter";
	const string CONST_locationsB117 = "CEO House";
	const string CONST_locationsB116 = "Bank";
	const string CONST_locationsB115 = "Corp. HQ";
	const string CONST_locationsB114 = "Minipax";
	const string CONST_locationsB113 = "Int. HQ";
	const string CONST_locationsB112 = "Miniluv";
	const string CONST_locationsB111 = "NPower Plant";
	const string CONST_locationsB110 = "NWaste Center";
	const string CONST_locationsB109 = "Judge Hall";
	const string CONST_locations114 = "Black Market";
	const string CONST_locations113 = "Robert E. Lee Bunker";
	const string CONST_locations112 = "Desert Eagle Bar & Grill";
	const string CONST_locations111 = "Fallout Shelter";
	const string CONST_locations110 = "Park";
	const string CONST_locations109 = " Park";
	const string CONST_locations108 = "Latte Stand";
	const string CONST_locations107 = " Latte Stand";
	const string CONST_locations106 = "Cigar Bar";
	const string CONST_locations105 = " Gentlemen's Club";
	const string CONST_locations104 = "Net Cafe";
	const string CONST_locations103 = " Internet Cafe";
	const string CONST_locations102 = "Vegan Co-op";
	const string CONST_locations101 = " Vegan Co-op";
	const string CONST_locations100 = "Juice Bar";
	const string CONST_locations099 = " Juice Bar";
	const string CONST_locations098 = "Crack House";
	const string CONST_locations096 = "Dispensary";
	const string CONST_locations095 = "Marijuana Dispensary";
	const string CONST_locations094 = "Cannabis Lounge";
	const string CONST_locations092 = "Coffee House";
	const string CONST_locations090 = "Drugs Center";
	const string CONST_locations089 = "Recreational Drugs Center";
	const string CONST_locations088 = " St. ";
	const string CONST_locations087 = "Sweatshop";
	const string CONST_locations086 = " Garment Makers";
	const string CONST_locations085 = "The Oubliette";
	const string CONST_locations084 = "Dept. Store";
	const string CONST_locations083 = "'s Department Store";
	const string CONST_locations082 = "Used Cars";
	const string CONST_locations081 = "'s Used Cars";
	const string CONST_locations080 = "Cosmetics Lab";
	const string CONST_locations079 = " Cosmetics";
	const string CONST_locations078 = "Genetics Lab";
	const string CONST_locations077 = " Genetics";
	const string CONST_locations076 = "The Free Clinic";
	const string CONST_locations075 = "The University Hospital";
	const string CONST_locations074 = "Projects";
	const string CONST_locations073 = " St. Housing Projects";
	const string CONST_locations072 = " Apts";
	const string CONST_locations071 = " Apartments";
	const string CONST_locations070 = " Condos";
	const string CONST_locations069 = " Condominiums";
	const string CONST_locations068 = "AM Radio Station";
	const string CONST_locations067 = "Cable News Station";
	const string CONST_locations066 = "Chemical Factory";
	const string CONST_locations065 = "Auto Plant";
	const string CONST_locations064 = "Oil Refinery";
	const string CONST_locations063 = "Plastic Factory";
	const string CONST_locations062 = "Aluminum Factory";
	const string CONST_locations061 = "Building";
	const string CONST_locations060 = "Building Site";
	const string CONST_locations059 = "Toy";
	const string CONST_locations058 = "Toy Factory";
	const string CONST_locations057 = "Packing";
	const string CONST_locations056 = "Packing Plant";
	const string CONST_locations055 = "Steel";
	const string CONST_locations054 = "Steel Plant";
	const string CONST_locations053 = "Drill";
	const string CONST_locations052 = "Drill Factory";
	const string CONST_locations051 = "Fertilizer";
	const string CONST_locations050 = "Fertilizer Plant";
	const string CONST_locations049 = "Cement";
	const string CONST_locations048 = "Cement Factory";
	const string CONST_locations047 = "Paper Mill";
	const string CONST_locations045 = "Warehouse";
	const string CONST_locations043 = "Meat Plant";
	const string CONST_locations041 = "Abandoned ";
	const string CONST_locations040 = "Homeless Shelter";
	const string CONST_locations039 = "CEO Residence";
	const string CONST_locations038 = "CEO Castle";
	const string CONST_locations037 = "Pawnshop";
	const string CONST_locations036 = " Pawn & Gun";
	const string CONST_locations035 = "'s Pawnshop";
	const string CONST_locations034 = "American Bank Corp";
	const string CONST_locations033 = "Corporate HQ";
	const string CONST_locations032 = "White House";
	const string CONST_locations031 = "Army Base";
	const string CONST_locations030 = " Army Base";
	const string CONST_locations029 = "Ministry of Peace";
	const string CONST_locations028 = "Intelligence HQ";
	const string CONST_locations027 = "Ministry of Love";
	const string CONST_locations026 = "Nuclear Power Plant";
	const string CONST_locations025 = "Nuclear Waste Center";
	const string CONST_locations024 = "Prison";
	const string CONST_locations023 = " Prison";
	const string CONST_locations022 = "Joycamp";
	const string CONST_locations021 = " Forced Labor Camp";
	const string CONST_locations020 = "Fire Station";
	const string CONST_locations019 = "Fireman HQ";
	const string CONST_locations018 = "Courthouse";
	const string CONST_locations017 = "Halls of Ultimate Judgment";
	const string CONST_locations016 = "Police Station";
	const string CONST_locations015 = "Death Squad HQ";
	const string CONST_locations014 = "latte_name_2.txt";
	const string CONST_locations013 = "latte_name.txt";
	const string CONST_locations012 = "cafe_name_2.txt";
	const string CONST_locations011 = "cafe_name.txt";
	const string CONST_locations010 = "vegan_name_2.txt";
	const string CONST_locations009 = "vegan_name.txt";
	const string CONST_locations008 = "juice_name_2.txt";
	const string CONST_locations007 = "juice_name.txt";
	const string CONST_locations006 = "labor_camp_name_2.txt";
	const string CONST_locations005 = "labor_camp_name.txt";

	const string tag_The = "The ";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";
	const string locations = "locations\\";

	// Finds a location with the corresponding type and returns
	// its index in the location array
	vector<string> labor_camp_name;
	vector<string> labor_camp_name_2;
	vector<string> juice_name;
	vector<string> juice_name_2;
	vector<string> vegan_name;
	vector<string> vegan_name_2;
	vector<string> cafe_name;
	vector<string> cafe_name_2;
	vector<string> latte_name;
	vector<string> latte_name_2;
	vector<file_and_text_collection> locations_text_file_collection = {
		/*locations.cpp*/
		customText(&labor_camp_name, locations + CONST_locations005),
		customText(&labor_camp_name_2, locations + CONST_locations006),
		customText(&juice_name, locations + CONST_locations007),
		customText(&juice_name_2, locations + CONST_locations008),
		customText(&vegan_name, locations + CONST_locations009),
		customText(&vegan_name_2, locations + CONST_locations010),
		customText(&cafe_name, locations + CONST_locations011),
		customText(&cafe_name_2, locations + CONST_locations012),
		customText(&latte_name, locations + CONST_locations013),
		customText(&latte_name_2, locations + CONST_locations014),
	};
#endif	//LOCATIONS_CPP
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
	// Gives you bloody armor
	extern bool GIVEBLOODYARMOR;
	// Start with lots of money
	extern bool HIGHFUNDS;
	extern class Ledger ledger;
	extern long cursquadid;
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern vector<Deprecatedsquadst *> squad;
	extern Deprecatedsquadst *activesquad;
#include "../common/equipment.h"
#include "../common/creaturePool.h"
	void initlocation(Location &loc);
	//#include "sitemode/sitemode.h"
	void initsite(Location &loc);
#include "../common/commonactionsCreature.h"

#include "../items/lootTypePoolItem.h"
	extern bool multipleCityMode;
	extern short lawList[LAWNUM];
	map<short, string> getActivityString;

	extern vector<ArmorType *> armortype;
	extern vector<WeaponType *> weapontype;
	extern Deprecatedsquadst *activesquad;
	extern vector<Deprecatedsquadst *> squad;
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
	//extern string singleSpace;
	//extern string commaSpace;
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

	extern bool multipleCityMode;
	// Check if the player wants to move all items to a new location,
	// using Shift + a number key.
	const char upnums[] = "!@#$%^&*(";
#include "../daily/siege.h"
	void addStringYear();
	extern Deprecatedsquadst *activesquad;
	extern int selectedsiege;
	extern int day;
	extern int month;
	extern int year;
#include "../common/commonactions.h"
#include "../common/musicClass.h"
	extern class Ledger ledger;
	extern bool multipleCityMode;
	extern class Ledger ledger;
	extern Deprecatedsquadst *activesquad;
	extern bool multipleCityMode;
	extern MusicClass music;
#include "../customMaps.h"
	enum BusinessFronts
	{
		BUSINESSFRONT_INSURANCE,
		BUSINESSFRONT_TEMPAGENCY,
		BUSINESSFRONT_RESTAURANT,
		BUSINESSFRONT_MISCELLANEOUS,
		BUSINESSFRONTNUM
	};
	extern class Ledger ledger;
	extern int selectedsiege;
	extern short lawList[LAWNUM];
	extern Deprecatedsquadst *activesquad;
	extern int stat_kidnappings;
	extern class Ledger ledger;
	/* monthly - lets the player choose a special edition for the guardian */
	int choosespecialedition(char &clearformess);
	/* monthly - guardian - prints liberal guardian special editions */
	void printnews(short l, short newspaper);
#include "../items/itemPool.h"
#include "../items/lootTypePool.h"
	extern char endgamestate;
	extern short background_liberal_influence[VIEWNUM];
	extern Deprecatedsquadst *activesquad;

	extern Deprecatedsquadst *activesquad;
	extern Deprecatedsquadst *activesquad;
	extern vector<Deprecatedsquadst *> squad;
	void giveActiveSquadThisLoot(Item* de);
	extern vector<WeaponType *> weapontype;
	extern Deprecatedsquadst *activesquad;
	extern int selectedsiege;
	const string needCar = " (Need Car)";
	const string underSiege = " (Under Siege)";
	const string secrecyLevel = "Secrecy: ";
	const string heatLevel = "Heat: ";
	const string travelDifCity = " - Travel to a Different City";
	const string currentLocation = " (Current Location)";
	const string safeHouse = " (Safe House)";
	const string enemySafeHouse = " (Enemy Safe House)";
	const string closedDown = " (Closed Down)";
	const string highSecurity = " (High Security)";
	const string theLCS = "The Liberal Crime Squad";
	const string CONST_locationsPool036 = ".  Possessions go to the shelter.";
	const string CONST_locationsPool035 = "EVICTION NOTICE: ";
	const string CONST_locationsPool046 = "sleeper agent";
	const string CONST_locationsPool045 = " as a ";
	const string CONST_locationsPool044 = "Stay at ";
	const string CONST_locationsPool043 = "-> ";
	const string CONST_locationsPool042 = "regular member";
	const string CONST_locationsPool040 = "Come to ";
	const string CONST_locationsPool039 = "   ";
	const string CONST_locationsPool038 = " best serve the Liberal cause?";
	const string CONST_locationsPool037 = "In what capacity will ";
	const string CONST_locationsPool047 = "Mall";
	const string CONST_locationsPool051 = ", New York";
	const string CONST_locationsPool050 = ", California";
	const string CONST_locationsPool049 = ", Virginia";
	const string CONST_locationsPool048 = " Outskirts";

	const string CONST_locationsPoolB146 = ", NY";
	const string CONST_locationsPoolB145 = ", CA";
	const string CONST_locationsPoolB144 = ", VA";
	const string CONST_locationsPool056 = "Reporting Bugs to the Dev Team";
	const string CONST_locationsPool055 = "Going to ";
	const string CONST_locationsPool054 = "Making ";
	const string CONST_locationsPool053 = "a bug";
	const string CONST_locationsPool052 = "Tending to ";
	const string CONST_locationsPool057 = "     How many?          ";
	const string CONST_locationsPool065 = "Z - Stash things at ";
	const string CONST_locationsPool064 = "Y - Get things from ";
	const string CONST_locationsPool063 = "Cursors - Increase or decrease ammo allocation";
	const string CONST_locationsPool062 = "S - Liberally Strip a Squad member";
	const string CONST_locationsPool061 = "Press a number to drop that Squad member's Conservative weapon";
	const string CONST_locationsPool060 = "Press a letter to equip a Liberal item";
	const string CONST_locationsPool059 = " x";
	const string CONST_locationsPool058 = "Equip the Squad";

	const string CONST_locationsPool069 = "receive it.";
	const string CONST_locationsPool068 = "drop a clip.";
	const string CONST_locationsPool067 = "receive a clip.";
	const string NOT_ERROR_BUT_CONTINUE = "For simplicity this function returns an error message, prompting 'continue;', this is not an error, but it needs to use 'continue;' anyway";
	const string CONST_locationsPool076 = "Can't carry any more ammo.";
	const string CONST_locationsPool075 = "That ammo doesn't fit.";
	const string CONST_locationsPool074 = "Can't carry ammo without a gun.";
	const string CONST_locationsPool073 = "No ammo available!";
	const string CONST_locationsPool072 = "No ammo required!";
	const string CONST_locationsPool071 = "No spare clips!";
	const string CONST_locationsPool070 = "No ammo to drop!";

	const string CONST_locationsPool077 = "strip down.";

	const string CONST_locationsPool066 = "You can't equip that.";
	const string CONST_locationsPool081 = "Press a letter to select an item.";
	const string CONST_locationsPool080 = "x";
	const string CONST_locationsPool079 = "/";
	const string CONST_locationsPool078 = "Select Objects";
	const string CONST_locationsPool089 = ",. to view other base pages.";
	const string CONST_locationsPool088 = "  Shift and a Number will move ALL items!";
	const string CONST_locationsPool087 = "T to sort by type.";
	const string CONST_locationsPool086 = "T to sort by location.";
	const string CONST_locationsPool085 = "Press a Letter to assign a base.  Press a Number to select a base.";
	const string CONST_locationsPool084 = "NEW LOCATION";
	const string CONST_locationsPool083 = "----ITEM----------------CURRENT LOCATION---------------------------------------";
	const string CONST_locationsPool082 = "Moving Equipment";
	const string CONST_locationsPool116 = " Eating";
	const string CONST_locationsPool115 = "s";
	const string CONST_locationsPool114 = " Daily Ration";
	const string CONST_locationsPool113 = "Not Enough Food";
	const string CONST_locationsPool112 = " of Food Left";
	const string CONST_locationsPool111 = " Day";
	const string CONST_locationsPool110 = "GENERATOR";
	const string CONST_locationsPool109 = "LIGHTS OUT";
	const string CONST_locationsPool108 = "TANK TRAPS";
	const string CONST_locationsPool107 = "AA GUN";
	const string CONST_locationsPool106 = "BOOBY TRAPS";
	const string CONST_locationsPool105 = "CAMERAS ON";
	const string CONST_locationsPool104 = "CAMERAS OFF";
	const string CONST_locationsPool103 = "BUSINESS FRONT";
	const string CONST_locationsPool102 = "PRINTING PRESS";
	const string CONST_locationsPool101 = "FORTIFIED COMPOUND";
	const string CONST_locationsPool100 = "This location has insufficient food stores.";
	const string CONST_locationsPool099 = "This location has food for only a few days.";
	const string CONST_locationsPool098 = "You are not under siege...  yet.";
	const string CONST_locationsPool097 = "Firemen are raiding this location!";
	const string CONST_locationsPool096 = "The CCS is raiding this location!";
	const string CONST_locationsPool095 = "The Corporations are raiding this location!";
	const string CONST_locationsPool094 = "The masses are storming this location!";
	const string CONST_locationsPool093 = "The CIA is raiding this location!";
	const string CONST_locationsPool092 = "The police are raiding this location!";
	const string CONST_locationsPool091 = "The police have surrounded this location.";
	const string CONST_locationsPool121 = "Acting Individually";
	const string CONST_locationsPool120 = "2) Press Z to Assemble a New Squad";
	const string CONST_locationsPool119 = "1) R - Review Assets and Form Squads";
	const string CONST_locationsPool118 = "To form a new squad:";
	const string CONST_locationsPool117 = "No Squad Selected";
	const string CONST_locationsPool124 = "Enter - Back one step.";
	const string CONST_locationsPool123 = "Enter - The squad is not yet Liberal enough.";
	const string CONST_locationsPool122 = "Where will the Squad go?";
	const string mostlyendings = "mostlyendings\\";
	const string CONST_locationsPool128 = "caseBUSINESSFRONT_MISCELLANEOUS.txt";
	const string CONST_locationsPool127 = "caseBUSINESSFRONT_RESTAURANT.txt";
	const string CONST_locationsPool126 = "caseBUSINESSFRONT_TEMPAGENCY.txt";
	const string CONST_locationsPool125 = "caseBUSINESSFRONT_INSURANCE.txt";
	const string CONST_locationsPool140 = "R - Stockpile 20 daily rations of food ($150)";
	const string CONST_locationsPool139 = "F - Setup a Business Front to ward off suspicion ($3000)";
	const string CONST_locationsPool138 = "P - Buy a Printing Press to start your own newspaper ($3000)";
	const string CONST_locationsPool137 = "A - Install and conceal an illegal Anti-Aircraft gun on the roof ($200,000)";
	const string CONST_locationsPool136 = "A - Install a perfectly legal Anti-Aircraft gun on the roof ($35,000)";
	const string CONST_locationsPool135 = "G - Buy a Generator for emergency electricity ($3000)";
	const string CONST_locationsPool134 = "T - Ring the Compound with Tank Traps ($3000)";
	const string CONST_locationsPool133 = "B - Place Booby Traps throughout the Compound ($3000)";
	const string CONST_locationsPool132 = "C - Place Security Cameras around the Compound ($2000)";
	const string CONST_locationsPool131 = "W - Fortify the Compound for a Siege ($2000)";
	const string CONST_locationsPool130 = "W - Fortify the Bomb Shelter Entrances ($2000)";
	const string CONST_locationsPool129 = "W - Repair the Bunker Fortifications ($2000)";
	const string CONST_locationsPool144 = "If you do not enter anything, their real name will be used.";
	const string CONST_locationsPool143 = " in its presence?";
	const string CONST_locationsPool142 = "What name will you use for this ";
	const string CONST_locationsPool141 = "The Education of ";
	const string CONST_locationsPool145 = "Temporary Squad";
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
#ifdef	LOG_CPP
// log.cpp

	const string CONST_log001 = "last message";

#endif	//LOG_CPP
#ifdef	LOOTTYPE_CPP
// loottype.cpp

	const string CONST_loottype009 = "::cloth: ";
	const string CONST_loottype008 = "Invalid boolean value for loot type ";
	const string CONST_loottype007 = "::no_quick_fencing: ";
	const string CONST_loottype005 = "::stackable: ";

	const string tag_cloth = "cloth";
	const string tag_no = "no";
	const string tag_no_quick_fencing = "no_quick_fencing";
	const string tag_stackable = "stackable";
#endif	//LOOTTYPE_CPP
#ifdef	LOOTTYPEPOOL_CPP
// lootTypePool.cpp

	const string CONST_lootTypePool000 = "loot";
#endif	//LOOTTYPEPOOL_CPP
#ifdef	MAPSPECIALS_CPP
// mapspecials.cpp

#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../sitemode/advance.h"
#include "../sitemode/miscactions.h"
#include "../sitemode/sitedisplay.h"
#include "../sitemode/stealth.h"
#include "../items/loottype.h"
#include "../items/loot.h"
#include "../items/money.h"
#include "../log/log.h"
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
// for void addjuice(DeprecatedCreature &cr, long juice, long cap);
#include "../common/translateid.h"
// for  int getloottype(int id);
//#include "../combat/fight.h"
	void enemyattack();
#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
	//extern string string_sleeper;
	//extern string singleDot;
	char run_broadcast(bool tv_broadcast);
#include "../common/creaturePool.h"
#include "../common/creaturePoolHeader.h"

	/* Used by load() to create items of the correct class. */

	bool isThereASiteAlarm();
	void setSiteAlarmOne();

	void addCrimeToSiteStory(const int crime);
	void giveActiveSquadLoot(const string loot);
	void claimSiteStory();
	vector<NameAndAlignment> getEncounterNameAndAlignment();
	void claimSiteStoryOne();
	void juiceActiveSquad(const long juice, const long cap);
	void giveActiveSquadThisLoot(Item* de);
	/* checks if a creature's weapon is suspicious or illegal */
	char weaponcheck(const DeprecatedCreature &cr, bool metaldetect = false);
	/* checks if a creature's uniform is appropriate to the location */
	char hasdisguise(const DeprecatedCreature &cr);
	short getCurrentSite();
	void makecreature(const int x, const short type);
	void emptyEncounter();
#include "../customMaps.h"
	void setEncounterZeroExistsFalse();
	extern short sitetype;
	extern Deprecatedsquadst *activesquad;
	extern Log gamelog;
	extern short lawList[LAWNUM];
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern DeprecatedCreature encounter[ENCMAX];
	extern int sitecrime;
	extern short sitealarmtimer;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern Deprecatedsquadst *activesquad;
	extern int sitecrime;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short lawList[LAWNUM];
	void fillEncounter(CreatureTypes c, int numleft);
	extern short mode;
	extern int sitecrime;
	extern short sitealarmtimer;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern coordinatest loc_coord;
	extern short mode;
	extern int sitecrime;
	extern short sitealarmtimer;
	extern Log gamelog;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short mode;
	extern int sitecrime;
	extern short sitealarmtimer;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];

	extern short sitealienate;
	extern short mode;
	extern Deprecatedsquadst *activesquad;
	extern int sitecrime;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
#include "../items/lootTypePoolItem.h"
	extern short mode;
	extern int sitecrime;
	extern short sitealarmtimer;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short lawList[LAWNUM];
	extern CCSexposure ccsexposure;
	extern short sitealienate;
	extern char endgamestate;
	extern int sitecrime;
	extern short sitealarmtimer;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern int sitecrime;
	extern short sitealarmtimer;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern int sitecrime;
	extern short sitealarmtimer;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern int sitecrime;
	extern short sitealarmtimer;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern bool deagle;
	extern int sitecrime;
	extern short sitealarmtimer;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern vector<WeaponType *> weapontype;
	extern vector<ClipType *> cliptype;
	extern bool m249;
	extern int sitecrime;
	extern short sitealarmtimer;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern vector<WeaponType *> weapontype;
	extern vector<ClipType *> cliptype;
	extern int sitecrime;
	extern short sitealarmtimer;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short sitealienate;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short sitealienate;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern int sitecrime;
	extern short sitealarmtimer;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short sitetype;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern DeprecatedCreature encounter[ENCMAX];
	extern Deprecatednewsstoryst *sitestory;
	extern Deprecatedsquadst *activesquad;
	extern int sitecrime;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short sitealienate;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	void giveActiveSquadMoney(const int money);
	extern short sitealarmtimer;
	extern int sitecrime;
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern short postalarmtimer;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	void spawnPresident();
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern Log gamelog;
	extern coordinatest loc_coord;
	extern short sitealienate;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	const string itemClassClip = "clip";
	const string itemClassWeapon = "weapon";
	const string itemClassArmor = "armor";
	const string itemClassLoot = "loot";
	const string itemClassMoney = "money";
	const string mostlyendings = "mostlyendings\\";
	const string CONST_mapspecialsX01 = "\"Get the fuck out of here.\"";
	const string CONST_mapspecialsX02 = "\"Get the hell out of here.\"";
	const string CONST_mapspecialsX03 = "\"The best way not to fail is to succeed.\"";
	const string CONST_mapspecialsX04 = "\"Great work is done by people who do great work.\"";

	const string CONST_mapspecials161 = "The CCS leader is here.";
	const string CONST_mapspecials160 = "The CCS leader is ready for you!";
	const string CONST_mapspecials159 = "The President is in the Oval Office.";
	const string CONST_mapspecials158 = "Secret Service agents ambush the squad!";
	const string CONST_mapspecials157 = "The President isn't here... ";
	const string CONST_mapspecials156 = "A SWAT team storms the vault!!";
	const string CONST_mapspecials155 = "Another SWAT team moves in!!";
	const string CONST_mapspecials154 = "The squad loads bricks of cash into a duffel bag.";
	const string CONST_mapspecials153 = "A bank teller is available.";
	const string CONST_mapspecials152 = "The teller window is empty.";
	const string CONST_mapspecials151 = "The squad has nobody that can do the job.";
	const string CONST_mapspecials150 = " is no longer recognized.";
	const string CONST_mapspecials149 = "and will join the active LCS to avoid arrest.";
	const string CONST_mapspecials148 = " opens the vault, ";
	const string CONST_mapspecials147 = "The hostage is forced to open the vault.";
	const string CONST_mapspecials146 = " opens the vault.";
	const string CONST_mapspecials145 = "to the bank's managers.";
	const string CONST_mapspecials144 = "Last is the biometric lock that keyed only ";
	const string CONST_mapspecials143 = "The money was so close the squad could taste it!";
	const string CONST_mapspecials142 = "be bypassed by a computer expert.";
	const string CONST_mapspecials141 = "Next is the electronic lock that will have ";
	const string CONST_mapspecials140 = "on the other side of this door...";
	const string CONST_mapspecials139 = "The squad can only dream of the money ";
	const string CONST_mapspecials138 = "be cracked by a security expert.";
	const string CONST_mapspecials137 = "First is the combo lock that will have ";
	const string CONST_mapspecials136 = "Open the bank vault? (Yes or No)";
	const string CONST_mapspecials135 = "but you'll still have to crack the other locks.";
	const string CONST_mapspecials134 = " can handle the biometrics, ";
	const string CONST_mapspecials133 = "expert, and one of the bank managers.";
	const string CONST_mapspecials132 = "You will need a security expert, a computer ";
	const string CONST_mapspecials131 = "an electronic lock, and a biometric lock.";
	const string CONST_mapspecials130 = "The vault door has three layers: A combo lock, ";
	const string CONST_mapspecials129 = "-BEEEP- -BEEEP- -BEEEP-";
	const string CONST_mapspecials128 = "\"Jesus! Put some clothes on!\"";
	const string CONST_mapspecials127 = "This door is guarded.";
	const string CONST_mapspecials126 = "The squad steps into a metal detector.";
	const string CONST_mapspecials125 = "The squad flashes ID badges.";
	const string CONST_mapspecials124 = "The security checkpoint is abandoned.";
	const string CONST_mapspecials123 = "Smash it? (Yes or No)";
	const string CONST_mapspecials122 = "You see a display case.";
	const string CONST_mapspecials121 = "Start an impromptu news program? (Yes or No)";
	const string CONST_mapspecials120 = "You've found a Cable News broadcasting studio.";
	const string CONST_mapspecials119 = " Take over the studio? (Yes or No)";
	const string CONST_mapspecials118 = "their rush to get out.";
	const string CONST_mapspecials117 = "The Cable News broadcasters left the equipment on in";
	const string CONST_mapspecials116 = "Interrupt this evening's programming? (Yes or No)";
	const string CONST_mapspecials115 = "You've found a radio broadcasting room.";
	const string CONST_mapspecials112 = "The radio broadcasters left the equipment on in ";
	const string CONST_mapspecials111 = "The Squad has found some very interesting files.";
	const string CONST_mapspecials110 = "Open it? (Yes or No)";
	const string CONST_mapspecials109 = "You've found a safe.";
	const string CONST_mapspecials108 = "Guards are everywhere!";
	const string CONST_mapspecials107 = "It's a trap!  The armory is empty.";
	const string CONST_mapspecials106 = "The squad finds some body armor.";
	const string CONST_mapspecials105 = "The squad finds some M4 Carbines.";
	const string CONST_mapspecials104 = "The squad finds some M16 Assault Rifles.";
	const string CONST_mapspecials103 = "Jackpot! The squad found a M249 Machine Gun!";
	const string CONST_mapspecials102 = "Alarms go off!";
	const string CONST_mapspecials101 = "Break in? (Yes or No)";
	const string CONST_mapspecials100 = "You've found the armory.";
	const string CONST_mapspecials099 = "Wow, it's empty.  That sucks.";
	const string CONST_mapspecials098 = "These documents show serious tax evasion.";
	const string CONST_mapspecials097 = "The squad will take those.";
	const string CONST_mapspecials096 = "Wow, get a load of these love letters. ";
	const string CONST_mapspecials095 = "There are some drugs here.";
	const string CONST_mapspecials094 = "There are some... very compromising photos here.";
	const string CONST_mapspecials093 = "The squad Liberates some expensive jewelery.";
	const string CONST_mapspecials092 = "This guy sure had a lot of $100 bills.";
	const string CONST_mapspecials091 = "The squad has found a Desert Eagle.";
	const string CONST_mapspecials088 = "Destroy it? (Yes or No)";
	const string CONST_mapspecials087 = "You see some industrial equipment.";
	const string CONST_mapspecials085 = "You see some textile equipment.";
	const string CONST_mapspecials084 = "The squad sprays Liberal Graffiti!";
	const string CONST_mapspecials083 = "including a list of government backers of the CCS.";
	const string CONST_mapspecials082 = ",";
	const string CONST_mapspecials081 = "The Squad obtains sensitive information";
	const string CONST_mapspecials080 = "Hack it? (Yes or No)";
	const string CONST_mapspecials079 = "You've found the Intelligence Supercomputer.";
	const string CONST_mapspecials078 = "computer to shut down.";
	const string CONST_mapspecials077 = "The security alert has caused the ";
	const string CONST_mapspecials076 = "Free the prisoners? (Yes or No)";
	const string CONST_mapspecials075 = "prison control room.";
	const string CONST_mapspecials074 = "high security ";
	const string CONST_mapspecials073 = "medium security ";
	const string CONST_mapspecials072 = "low security ";
	const string CONST_mapspecials071 = "You've found the ";
	const string CONST_mapspecials070 = " wasn't quite convincing...";
	const string CONST_mapspecials069 = " wasn't really wrong here.";
	const string CONST_mapspecials068 = "concludes that ";
	const string CONST_mapspecials067 = " works the room like in Twelve Angry Men, and the jury ";
	const string CONST_mapspecials066 = "Attempt to influence them? (Yes or No)";
	const string CONST_mapspecials065 = "You've found a Jury in deliberations!";
	const string CONST_mapspecials064 = "vacated in a hurry.";
	const string CONST_mapspecials063 = "It appears as if this room has been ";
	const string CONST_mapspecials062 = "Free them? (Yes or No)";
	const string CONST_mapspecials061 = "You see prisoners in the Courthouse jail.";
	const string CONST_mapspecials059 = "You see prisoners in the detention room.";
	const string CONST_mapspecials058 = "Uh, maybe that idea was Conservative in retrospect...";
	const string CONST_mapspecials056 = "You see horrible misshapen creatures in a sealed cage.";
	const string CONST_mapspecials055 = "the Squad resigns to just leaving a threatening note.";
	const string CONST_mapspecials054 = "After some failed attempts, and a very loud alarm, ";
	const string CONST_mapspecials053 = "The reactor is overheating!";
	const string CONST_mapspecials052 = "                ";
	const string CONST_mapspecials051 = "A deafening alarm sounds!";
	const string CONST_mapspecials050 = "The nuclear waste gets released into the state's water supply!";
	const string CONST_mapspecials049 = " presses the big red button!";
	const string CONST_mapspecials048 = "Mess with the reactor settings? (Yes or No)";
	const string CONST_mapspecials047 = "You see the nuclear power plant control room.";
	const string CONST_mapspecials046 = "Attempt to release nuclear waste? (Yes or No)";
	const string CONST_mapspecials045 = "You see the nuclear waste center control room.";
	const string CONST_mapspecials044 = "Employees Only";
	const string CONST_mapspecials042 = "on the left.";
	const string CONST_mapspecials041 = "The landlord's office is the first door";
	const string CONST_mapspecials040 = "the museum displays in the gift shop.";
	const string CONST_mapspecials039 = "Welcome to the NPP Nuclear Plant. Please enjoy";
	const string CONST_mapspecials036 = "You see fluffy white rabbits in a locked cage.";
	const string CONST_mapspecials033 = "\"Get the [heck] out of here.\"";
	const string CONST_mapspecials032 = "The bouncer assesses your squad.";
	const string CONST_mapspecials031 = "The Conservative scum block the door.";
	const string CONST_mapspecials030 = " smirks and lets the squad in.";
	const string CONST_mapspecials029 = "caseNOT_REJECTED.txt";
	const string CONST_mapspecials028 = "caseREJECTED_WEAPONS.txt";
	const string CONST_mapspecials027 = "caseREJECTED_NUDE.txt";
	const string CONST_mapspecials026 = "randomCrime.txt";
	const string CONST_mapspecials025 = "notRejected.txt";
	const string CONST_mapspecials024 = "rejectedBecauseSmellFunny.txt";
	const string CONST_mapspecials020 = "";
	const string tag_LOOT_CORPFILES = "LOOT_CORPFILES";
	const string tag_LOOT = "LOOT";
	const string tag_ARMOR_CIVILLIANARMOR = "ARMOR_CIVILLIANARMOR";
	const string tag_ARMOR = "ARMOR";
	const string tag_ARMOR_ARMYARMOR = "ARMOR_ARMYARMOR";
	const string tag_CLIP = "CLIP";
	const string tag_CLIP_ASSAULT = "CLIP_ASSAULT";
	const string tag_WEAPON = "WEAPON";
	const string tag_WEAPON_CARBINE_M4 = "WEAPON_CARBINE_M4";
	const string tag_WEAPON_AUTORIFLE_M16 = "WEAPON_AUTORIFLE_M16";
	const string tag_CLIP_DRUM = "CLIP_DRUM";
	const string tag_WEAPON_M249_MACHINEGUN = "WEAPON_M249_MACHINEGUN";
	const string tag_LOOT_CEOTAXPAPERS = "LOOT_CEOTAXPAPERS";
	const string tag_LOOT_CEOLOVELETTERS = "LOOT_CEOLOVELETTERS";
	const string tag_LOOT_CEOPHOTOS = "LOOT_CEOPHOTOS";
	const string tag_LOOT_EXPENSIVEJEWELERY = "LOOT_EXPENSIVEJEWELERY";
	const string tag_CLIP_50AE = "CLIP_50AE";
	const string tag_WEAPON_DESERT_EAGLE = "WEAPON_DESERT_EAGLE";
	const string tag_LOOT_INTHQDISK = "LOOT_INTHQDISK";
	const string tag_LOOT_CCS_BACKERLIST = "LOOT_CCS_BACKERLIST";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";
#endif	//MAPSPECIALS_CPP
#ifdef	MISC_CPP
// misc.cpp

#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../common/interval.h"
#include "../log/log.h"
#include "../cursesAlternative.h"
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
	extern Log gamelog;
	extern MusicClass music;
	extern short interface_pgup;
	extern short interface_pgup;
	extern short interface_pgup;
	extern int month;
	extern int year;
	extern char newscherrybusted;
	extern char endgamestate;
	extern short public_interest[VIEWNUM];
	extern vector<string> male_first_names;
	extern vector<string> female_first_names;
	extern vector<string> gender_neutral_first_names;
	extern vector<string> great_white_male_patriarch_first_names;
	extern vector<string> regular_last_names;
	extern vector<string> archconservative_last_names;

	extern Log gamelog;
	extern char artdir[MAX_PATH_SIZE];
	extern char endgamestate;
	extern short lawList[LAWNUM];

	extern char endgamestate;
	extern short lawList[LAWNUM];
	extern char endgamestate;
	extern short exec[EXECNUM];

	extern short lawList[LAWNUM];
	extern char endgamestate;

#include "locations/locationsEnums.h"
	const vector<string> numberTimesHit =
	{
		"",
		" twice",
		" three",
		" four",
		" five",
	};
	extern map<short, string> getLawString;
	extern vector<string> city_names;
	//		extern string findingBugs;
	extern map<short, string> getLawFlagString;
	extern map<short, map<short, string> > getLawFlagStringFull;
	extern short lawList[LAWNUM];

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

	vector<string> two_to_five = {
		"two",
		"three",
		"four",
		"five"
	};
	extern vector<string> vigilante_murder;
	extern vector<string> why_chase_ended;


	extern vector<string> book_title;
	extern vector<string> book_title_2;
	extern vector<string> random_nationality;
	extern vector<string> conservative_oppose_book;

	extern vector<string> petty_violence;
	extern vector<string> his_her;
	extern vector<string> older_younger;
	extern vector<string> brother_sister;

	extern int year;

	extern vector<string> AMorPM;
	//		extern string ampersandR;
	//		extern string singleDot;

	extern vector<string> liberalCrime;


	extern short lawList[LAWNUM];

	extern vector<string> judge_with_prostitute;
	extern vector<string> judge_with_prostitute_no_free_speech;
	extern vector<string> judge_with_prostitute_full_free_speech;

	extern int year;
	extern short presparty;
	extern vector<string> crazy_conservative_act;

	extern vector<string> bribe_officers;

	extern short lawList[LAWNUM];

	extern vector<string> radio_host_lost_mind;


	extern int year;
	extern short presparty;

	extern vector<string> radio_name;
	extern vector<string> radio_name_2;


	extern vector<string> radio_host_crazy_quote;

	extern vector<string> my_idol;


	extern int year;
	extern short presparty;

	extern short lawList[LAWNUM];
	extern vector<string> prison_book_title_2;

	extern vector<string> prison_book_title;

	extern vector<string> animal_research_country;

	extern short lawList[LAWNUM];

	extern short lawList[LAWNUM];

	extern vector<string> drug_name;

	extern short lawList[LAWNUM];
	extern vector<string> chimp_drug_impact;

	extern vector<string> drug_name_2;
	extern vector<string> chimp_drug_horror;


	extern vector<string> family_values_company_name;
	extern vector<string> family_values_company_name_2;
	extern vector<string> family_values_company_name_3;
	extern vector<string> pollution_consumption;
	extern vector<string> pollution_consumption_2;
	extern vector<string> i_like_polution;
	extern vector<string> distrust_liberals;

	extern vector<string> tech_giant_name;
	extern vector<string> tech_giant_name_2;

	extern short lawList[LAWNUM];

	extern vector<string> bullshit_no_free_speech;
	extern vector<string> bullshit;

	extern vector<string> gene_corp_name;
	extern vector<string> gene_corp_name_2;
	extern vector<string> gene_product_name;
	extern vector<string> gene_product_name_2;
	extern vector<string> gene_product_benefit;


	extern vector<string> gene_product_cost;
	extern vector<string> mutilated_corpse;

	extern vector<string> evidence_of_child_murder;
	extern vector<string> break_in_murder_case;

	extern vector<string> terrorist_plot;
	extern vector<string> terrorist_plot_no_free_speech;

	//		extern string commaSpace;


	extern vector<string> terrorist_group;


	extern vector<string> fm_radio_name;
	extern vector<string> fm_radio_name_2;

	extern short lawList[LAWNUM];
	extern short lawList[LAWNUM];
	extern vector<string> public_place;
	const vector<string> vicious_killing_of_guard = {
		"slit the guard's throat with a shank",
		"strangled the guard to death with a knotted bed sheet",
		"chewed out the guard's throat",
		"hit all 36 pressure points of death on the guard",
		"electrocuted the guard with high-voltage wires",
		"thrown the guard out the top-storey window",
		"tricked another guard into shooting the guard dead",
		"burnt the guard to a crisp using a lighter and some gasoline",
		"eaten the guard's liver with some fava beans and a nice chianti",
		"performed deadly experiments on the guard unheard of since Dr. Mengele"
	};
	extern short lawList[LAWNUM];
	extern short lawList[LAWNUM];
	extern short lawList[LAWNUM];
	extern vector<string> prays;
	extern vector<string> prays_on_drugs;
	extern vector<vector<string> > fall_in_love;
	extern vector<vector<string> > bad_trip;
	extern vector<string> smarter_than_you_one_line;
	extern vector<vector<string> > smarter_than_you;
	extern vector<string> develops_hatred_one_line;
	extern vector<vector<string> > develops_hatred;
	extern vector<string> interrogater_shows_compassion_one_line;
	extern vector<vector<string> > interrogater_shows_compassion;
	extern vector<vector<string> > cling_to_interrogater;
	extern vector<string> clinging_one_line;
	extern vector<vector<string> > cling_to_religion;
	extern vector<string> cling_to_religion_one_line;
	extern vector<vector<string> > cling_to_business;
	extern vector<string> cling_to_business_one_line;
	extern vector<vector<string> > cling_to_science;
	extern vector<string> cling_to_science_one_line;

	//		extern string singleDot;
	//		extern string ampersandR;
	const string findingBugs = "Finding bugs";
	const string mostlyendings = "mostlyendings\\";
	const string CONST_commondisplay223 = "PGDN";
	const string CONST_commondisplay222 = ":";
	const string CONST_commondisplay221 = "]";
	const string CONST_commondisplay22Z = " - Next";
	const string CONST_commondisplay226 = "PGUP";
	const string CONST_commondisplay225 = ";";
	const string CONST_commondisplay224 = "[";
	const string CONST_commondisplay22Y = " - Previous";
	const string CONST_commondisplay229 = "PGUP/PGDN";
	const string CONST_commondisplay228 = "; and :";
	const string CONST_commondisplay227 = "[]";
	const string CONST_commondisplay22X = " to view other Liberal pages.";
//	const string singleSpace = " ";
	const string CONST_fight035 = " times";
	const string CONST_getnames043 = "Software Bugs";
	const string CONST_creaturenames009 = "Errol";
	const string CONST_news700 = "her";
	const string CONST_news378 = "his";
	const string CONST_news647 = "[hurting spree]";
	const string CONST_news242 = "called the police on a cellphone and they arrived shortly thereafter. ";
	const string CONST_news241 = "verses of the Bible at the stunned onlookers. Someone ";
	const string CONST_news240 = " remained at the scene after the shooting, screaming ";
	const string CONST_news239 = " Witnesses report that ";
	const string CONST_news238 = ", is in custody.&r";
	const string CONST_news230 = "Dr. ";
	const string CONST_news229 = " Clinic yesterday. ";
	const string CONST_news228 = "gunned down outside of the ";
	const string CONST_news227 = "A doctor that routinely performed abortions was ruthlessly ";
	const string CONST_news226 = "A doctor that routinely performed semi-legal abortions was ruthlessly ";
	const string CONST_news225 = "A doctor that routinely performed illegal abortions was ruthlessly ";
	const string CONST_news224 = "A doctor that routinely performed illegal abortion-murders was ruthlessly ";

	const string CONST_news246 = "had been completed.&r";
	const string CONST_news245 = " surrendered without a struggle, reportedly saying that God's work ";
	const string CONST_news244 = " abortion doctors as opposed to arresting them.&r";
	const string CONST_news243 = " later admitted to being a rogue FBI vigilante, hunting down ";

	const string CONST_news250 = " and ";
	const string CONST_news249 = "wife";
	const string CONST_news248 = " is survived by ";

	const string CONST_news237 = "The suspected shooter, ";
	const string CONST_news236 = " times and died immediately in the parking lot. ";
	const string CONST_news235 = " was hit ";
	const string CONST_news234 = "shots were fired from a nearby vehicle. ";
	const string CONST_news233 = " car when, according to police reports, ";
	const string CONST_news232 = " was walking to ";

	const string CONST_newsB925 = "husband";
	const string CONST_news255 = " children.&r";

	const string CONST_news270 = "taking swipes";
	const string CONST_news269 = "urinating out the window";
	const string CONST_news268 = "pissing out the window";
	const string CONST_news267 = "[relieving themselves] out the window";
	const string CONST_news266 = "throwing beer bottles";
	const string CONST_news265 = "throwing [juice boxes]";


	const string CONST_news258 = "a homosexual, was ";
	const string CONST_news257 = "a known homosexual, was ";
	const string CONST_news256 = "a known sexual deviant, was ";

	const string CONST_news279 = ", even though being gay is deviant, as we all know.";
	const string CONST_news278 = " is a known faggot";
	const string CONST_news277 = ", despite the fact that ";
	const string CONST_news276 = "aggravated nature of the offense";
	const string CONST_news275 = "prosecute this case as a hate crime, due to the ";
	const string CONST_news274 = " Authorities have stated that they will vigorously ";
	const string CONST_news273 = "at which point they were taken into custody. Nobody was seriously injured during the incident.";
	const string CONST_news272 = "The chase ended when ";
	const string CONST_news271 = " at the pursuing police cruisers. ";

	const string CONST_news264 = "murderers swerving wildly, ";
	const string CONST_news263 = " Witnesses of the freeway chase described the pickup of the alleged ";
	const string CONST_news262 = "have not yet been released.";
	const string CONST_news261 = "were apprehended after a high speed chase. Their names ";
	const string CONST_news260 = "A police spokesperson reported that four suspects ";
	const string CONST_news259 = " here yesterday. ";
	const string CONST_news441 = "_";

	const string CONST_news345 = "?";
	const string CONST_news344 = "Mamma, why did they kill ";
	const string CONST_news343 = " dead?";
	const string CONST_news342 = "Mamma, is ";
	const string CONST_news340 = "many area children spontaneously broke into tears. One child was ";
	const string CONST_news339 = " When the decision to ban the book was announced yesterday, ";
	const string CONST_news338 = " as key evidence of the dark nature of the book.";
	const string CONST_news337 = "a child that ";
	const string CONST_news336 = "a child that said a magic spell at her parents";
	const string CONST_news335 = "a child that swore in class";
	const string CONST_news334 = "In their complaint, the groups cited an incident involving ";
	const string CONST_news332 = "some conservatives feel that the books ";
	const string CONST_news331 = "Although the series is adored by children worldwide, ";
	const string CONST_news329 = ". ";
	const string CONST_news328 = " author ";
	const string CONST_news327 = "_, is the third in an immensely popular series by ";
	const string CONST_news325 = "_and_the_";
	const string CONST_news322 = " The book, ";
	const string CONST_news321 = "the city bowed to pressure from religious groups.";
	const string CONST_news320 = " - A children's story has been removed from libraries here after ";

	const string CONST_newsX02 = "heard saying, \"";

	const string CONST_news1030 = "\"";

	const string CONST_news485 = ". ";
	const string CONST_news458 = ".\"";

	const string CONST_news306 = "can be put to death in this country.";
	const string CONST_news305 = "tragedy, it will be that our nation is now evaluating the ease with which people ";
	const string CONST_news304 = "and more events are expected this evening. If there is a bright side to be found from this ";
	const string CONST_news303 = " Candlelight vigils were held throughout the country last night during the execution, ";
	const string CONST_news301 = "The family wants closure. We don't have time for another trial";
	const string CONST_news300 = "End of story";
	const string CONST_news299 = "Assassin, serial killer, either way 컴 guilty. ";
	const string CONST_news298 = "The convict is always referred to by three names. ";
	const string CONST_news297 = "Let's not forget the convict is colored. You know how their kind are";
	const string CONST_news295 = "spokesperson for the governor saying, ";
	const string CONST_news294 = "The state still went through with the execution, with a ";
	const string CONST_news293 = " was framed. ";
	const string CONST_news292 = "an admission from a former prosecutor that ";
	const string CONST_news291 = "a battery of negative DNA tests. ";
	const string CONST_news290 = "a confession from another convict. ";
	const string CONST_news289 = "have been produced, including ";
	const string CONST_news288 = "Since then, numerous pieces of exculpatory evidence ";
	const string CONST_news287 = " of 13 serial murders. ";
	const string CONST_news286 = " was convicted in ";
	const string CONST_news284 = " Correctional Facility.&r";
	const string CONST_news283 = " yesterday at the ";
	const string CONST_news282 = ":";
	const string CONST_news281 = " was pronounced dead at ";
	const string CONST_news280 = " - An innocent citizen has been put to death in the electric chair. ";

	const string CONST_news318 = "You think about that before you continue slanging accusations";
	const string CONST_news317 = "these files deal with the one and not the other. ";
	const string CONST_news316 = "It might be a bit presumptive to assume that ";
	const string CONST_news315 = "Well, you know, there's privacy, and there's privacy. ";
	const string CONST_news313 = " The FBI refused to comment initially, but when confronted with the information, ";
	const string CONST_news312 = "\"deal with the undesirables\", although this phrase is not clarified. ";
	const string CONST_news311 = " More disturbingly, the files make reference to a plan to ";
	const string CONST_news310 = "unions, working for liberal organizations 컴 even ";
	const string CONST_news309 = "The files contain information on which people have been attending demonstrations, organizing ";
	const string CONST_news308 = "This newspaper yesterday received a collection of files from a source in the Federal Bureau of Investigations. ";
	const string CONST_news307 = "Washington, DC - The FBI might be keeping tabs on you. ";

	const string CONST_newsX01 = "a spokesperson stated, \"";
	const string CONST_news349 = " has resigned in disgrace after being caught with a prostitute.";
	const string CONST_news348 = " has resigned in disgrace after being caught with a [civil servant].";

	const string CONST_news361 = "the judge would be going on a Bible retreat for a few weeks to ";
	const string CONST_news360 = " could not be reached for comment, although an aid stated that ";
	const string CONST_news358 = " in exchange for their silence.";
	const string CONST_news357 = " reportedly offered ";
	const string CONST_news355 = "when police broke into the hotel room they saw ";
	const string CONST_news354 = "According to sources familiar with the particulars, ";
	const string CONST_news353 = " last week in a hotel during a police sting operation. ";
	const string CONST_news352 = ", was found with ";
	const string CONST_news351 = ", who once ";
	const string CONST_news347 = " - Conservative federal judge ";


	const string CONST_newsB928 = "\"Make things right with the Almighty Father.\"";
	const string CONST_news381 = " g*dd*mn mind";
	const string CONST_news380 = " [gosh darn] mind";
	const string CONST_news379 = " goddamn mind";
	const string CONST_news377 = "lost ";
	const string CONST_news390 = "to the FM band.";
	const string CONST_news389 = "pastures. Of these, many said that they would be switching over ";
	const string CONST_news388 = "have decided to leave the program for saner ";
	const string CONST_news387 = "fully half of the host's most loyal supporters ";
	const string CONST_news386 = "According to a poll completed yesterday, ";
	const string CONST_news385 = "the damage might already be done. ";
	const string CONST_news384 = " issued an apology later in the program, but ";
	const string CONST_news376 = " had ";
	const string CONST_news374 = "\", a former fan of the show, ";
	const string CONST_news373 = "liberal media establishment!";
	const string CONST_news372 = "current president!";
	const string CONST_news371 = "and the greatest living example of a reverse racist is the ";
	const string CONST_news368 = "'s monologue for the evening began the way that fans ";
	const string CONST_news366 = "\".";
	const string CONST_news364 = " went off for fifteen minutes in an inexplicable rant ";
	const string CONST_news363 = " - Well-known AM radio personality ";

	const string CONST_newsX03 = "two nights ago during the syndicated radio program \"";
	const string CONST_newsX04 = "had come to expect, with attacks on the \"liberal media establishment\"";
	const string CONST_newsX05 = "the \"elite liberal agenda\". But when the radio icon said, \"";
	const string CONST_newsX06 = ", knew that \"";
	const string CONST_newsX07 = ". After that, it just got worse and worse.\"";

	const string CONST_news398 = "university";
	const string CONST_news397 = "high school";
	const string CONST_news396 = "middle school";
	const string CONST_news395 = "elementary school";
	const string CONST_news407 = "University";
	const string CONST_news406 = "High School";
	const string CONST_news405 = "Middle School";
	const string CONST_news404 = "Elementary School";
	const string CONST_news393 = "shooting rampage";
	const string CONST_news428 = " committed suicide";
	const string CONST_news427 = " [feel deeply asleep]";
	const string CONST_news402 = "mow down";
	const string CONST_news401 = "[scare]";

	const string CONST_newsB943 = "him";
	const string CONST_news864 = "killed ";

	const string CONST_news426 = " and wounded dozens more. ";
	const string CONST_news424 = "[hurt some people]. ";
	const string CONST_news423 = " When the police arrived, the student had already ";
	const string CONST_news422 = " as well.&r";
	const string CONST_news421 = "shot";
	const string CONST_news420 = "[unfortunately harmed]";
	const string CONST_news419 = ", they were ";
	const string CONST_news417 = "When other students tried to wrestle the weapons away from ";
	const string CONST_news416 = " students and teachers inside. ";
	const string CONST_news415 = "spraying bullets at";
	const string CONST_news414 = "[scaring]";

	const string CONST_news433 = " was disturbingly obsessed with guns and death.&r";
	const string CONST_news432 = "she";
	const string CONST_news431 = "reports indicate that the student kept a journal that showed ";
	const string CONST_news430 = " Investigators are currently searching the student's belongings, and initial ";
	const string CONST_news429 = " shortly afterwards.&r";
	const string CONST_news413 = "classrooms, ";
	const string CONST_news412 = " while classes were in session, then systematically started breaking into ";
	const string CONST_news411 = "university ";
	const string CONST_news410 = "school ";
	const string CONST_news409 = " entered the ";
	const string CONST_news403 = " more than a dozen classmates and two teachers at ";
	const string CONST_news400 = ", used a variety of guns to ";
	const string CONST_news394 = " at a local ";
	const string CONST_news391 = "A student has gone on a ";


	const string CONST_newsB935 = "he";
	const string CONST_news443 = "Buttlord";
	const string CONST_news442 = "[Bum]lord";
	const string CONST_news453 = "AIDS";
	const string CONST_news452 = "GRIDS";

	const string CONST_news456 = "helluva";
	const string CONST_news455 = "[difficult]";
	const string CONST_news457 = " choice, and I would only have a few seconds before they made it for me";
	const string CONST_news454 = " the other. A ";
	const string CONST_news451 = "Maybe lose an eye the one way, maybe catch ";
	const string CONST_news450 = "My shank's under the mattress. Better to be brave and fight or chicken out and let them take it? ";
	const string CONST_news449 = "with dark glares of bare lust, as football players might stare at a stupefied, drunken, helpless teenager. ";
	const string CONST_news448 = "I was trapped with them now. There were three, looking me over ";
	const string CONST_news447 = "coming to a halt with a deafening clang that said it all 컴 ";
	const string CONST_news446 = "The steel bars grated forward in their rails, ";
	const string CONST_news445 = " Take this excerpt, \"";
	const string CONST_news444 = "_.&r";
	const string CONST_news440 = "'s new tour-de-force, _";
	const string CONST_news438 = "have these works been as poignant as ";
	const string CONST_news437 = "prison theme lately in its offerings for mass consumption, rarely ";
	const string CONST_news436 = "Although popular culture has used, or perhaps overused, the ";
	const string CONST_news435 = "detail what goes on behind bars. ";
	const string CONST_news434 = " - A former prisoner has written a book describing in horrifying ";
	const string CONST_news476 = "here report that they have discovered an amazing new wonder drug. ";
	const string CONST_news475 = " report that they have discovered an amazing new wonder drug. ";
	const string CONST_news474 = "from ";
	const string CONST_news479 = "Anal";
	const string CONST_news478 = "Bum-Bum";
	const string CONST_news482 = "corrects erectile dysfunction in chimpanzees";
	const string CONST_news481 = "[helps chimpanzees reproduce]";


	const string CONST_news492 = " The first phase of human trials is slated to begin in a few months.";
	const string CONST_news490 = "I think the media should be focusing on the enormous benefits of this drug.";
	const string CONST_news489 = "While we understand your concerns, any worries are entirely unfounded. ";
	const string CONST_news488 = ". We have a very experienced research team. ";
	const string CONST_news487 = "a spokesperson for the research team stated that, \"It really isn't so bad as all that. Chimpanzees are very resilient creatures. ";
	const string CONST_news486 = "Fielding questions about the ethics of their experiments from reporters during a press conference yesterday, ";
//	const string CONST_news485 = ". ";
	const string CONST_news484 = " Along with bonobos, chimpanzees are our closest cousins";
	const string CONST_news480 = ", the drug apparently ";
	const string CONST_news477 = "Called ";
	const string CONST_news473 = " - Researchers ";

	const string CONST_news571 = "needs to take a breather on this one. We don't see why there's such a rush to judgment here. ";
	const string CONST_news570 = "before we urge any action. Society really just ";
	const string CONST_news569 = "there's work left to be done. We should study much more ";
	const string CONST_news568 = "Why is there contention on the pollution question? It's because ";
	const string CONST_news567 = "All we've done is introduced a little clarity into the ongoing debate. ";
	const string CONST_news566 = " these issues to their own advantage. ";
	const string CONST_news565 = ". You have to realize that ";
	const string CONST_news564 = "a spokesperson stated that, \"";
	const string CONST_news563 = " When questioned about the science behind these results, ";
	const string CONST_news562 = " might actually ";
	const string CONST_news561 = "Among the most startling of the think tank's findings is that ";
	const string CONST_news560 = "and the latest science on the issue. ";
	const string CONST_news559 = " recently released a wide-ranging report detailing recent trends ";
	const string CONST_news558 = " - Pollution might not be so bad after all. The ";

	const string CONST_news587 = "of the tech industry but is also indicative of a full economic recover.&r";
	const string CONST_news586 = "analysts suggest that not only does the expansion speak to the health ";
	const string CONST_news585 = "futures of some of the companies in the tech sector. On the whole, however, ";
	const string CONST_news584 = "although the dampened movement might be expected due to the uncertain ";
	const string CONST_news583 = "The markets reportedly responded to the announcement with mild interest, ";
	const string CONST_news582 = "this welcome news is bound to be a pleasant surprise to those in the unemployment lines. ";
	const string CONST_news581 = "of large corporations to export jobs overseas these days, ";
	const string CONST_news580 = "light of the tendency ";
	const string CONST_news579 = "Given the state of the economy recently and in ";
	const string CONST_news578 = " increasing its payrolls by over ten thousand workers alone. ";
	const string CONST_news577 = "tech giant ";
	const string CONST_news576 = "are expected in the first month, with ";
	const string CONST_news575 = "during the next quarter. Over thirty thousand jobs ";
	const string CONST_news574 = "will be expanding their work forces considerably ";
	const string CONST_news573 = "at a joint news conference here that they ";
	const string CONST_news572 = " - Several major companies have announced ";

	const string CONST_news517 = "this amazing new product actually ";
	const string CONST_news516 = "According to the public relations representative speaking, ";
	const string CONST_news515 = "\", during an afternoon PowerPoint presentation. ";
	const string CONST_news514 = ", presented their product, \"";

	const string CONST_news525 = "but the GM industry operates at a higher ethical standard. That goes without saying.";
	const string CONST_news524 = "No. That's just ridiculous. I mean, sure companies have put unsafe products out, ";
	const string CONST_news523 = ". Would we stake the reputation of our company on unsafe products? ";
	const string CONST_news522 = " is just a load of ";
	const string CONST_news521 = "Look, these products are safe. That thing about the ";
	const string CONST_news520 = "One in particular said, \"";
	const string CONST_news519 = "in their dismissal of the criticism which often follows the industry. ";
	const string CONST_news518 = " Spokespeople for the GM corporations were universal ";
	const string CONST_news513 = " One such corporation, ";
	const string CONST_news512 = "booths and gave talks to wide-eyed onlookers.";
	const string CONST_news511 = "to showcase its upcoming products. Over thirty companies set up ";
	const string CONST_news510 = " - The genetic foods industry staged a major event here yesterday ";

	const string CONST_news467 = " dead and ";
	const string CONST_news466 = " [in a better place]";
	const string CONST_news472 = "the death penalty in this case.";
	const string CONST_news471 = "life imprisonment in this case.";
	const string CONST_news470 = "seeking ";
	const string CONST_news469 = " The district attorney's office has already repeatedly said it will be ";
	const string CONST_news468 = ". Sources say that the police got a break in the case when ";
	const string CONST_news465 = "only to turn up later";
	const string CONST_news464 = ". Over twenty children in the past two years have gone missing, ";
	const string CONST_news463 = " was detained yesterday afternoon, reportedly in possession of ";
	const string CONST_news462 = "according to a spokesperson for the police department here. ";
	const string CONST_news461 = "string of brutal child killings that has kept everyone in the area on edge, ";
	const string CONST_news460 = "The authorities have apprehended their primary suspect in the ";
	const string CONST_news459 = " - Perhaps parents can rest easier tonight. ";
	const string CONST_newsX08 = " The spokesperson further stated, \"";
	const string CONST_news508 = "this new age.";
	const string CONST_news507 = "for what we feel are the essential tools for combating terrorism in ";
	const string CONST_news506 = "The Head of the Agency will be sending a request to Congress ";
	const string CONST_news505 = "However, let me also say that there's more that needs to be done. ";
	const string CONST_news504 = "civilization before they can destroy American families. ";
	const string CONST_news503 = "providing us with the tools we need to neutralize these enemies of ";
	const string CONST_news502 = "that we are grateful to the Congress and this Administration for ";
	const string CONST_news501 = "I won't compromise our sources and methods, but let me just say ";
	const string CONST_news499 = "was to occur.";
	const string CONST_news498 = "terrorist organization allowed the plot to be foiled just days before it ";
	const string CONST_news497 = ". However, intelligence garnered from deep within the mysterious ";
	const string CONST_news496 = " planned to ";
	const string CONST_news495 = " According to a spokesperson for the agency, ";
	const string CONST_news494 = "would have occurred on American soil.";
	const string CONST_news493 = "Washington, DC - The CIA announced yesterday that it has averted a terror attack that ";

	const string CONST_news541 = " consultations with a Magic 8-Ball";
	const string CONST_news540 = " family";
	const string CONST_news539 = " close personal friendship with the ";
	const string CONST_news538 = " personal philosophy of liberty";
	const string CONST_news537 = " deserved another chance";
	const string CONST_news536 = " belief that ";
	const string CONST_news535 = " belief that the crimes were a vast right-wing conspiracy";
	const string CONST_news534 = " general feeling about police corruption";
	const string CONST_news533 = "ten-year-old eyewitness testimony";
	const string CONST_newsB937 = "If I were to be released, I would surely kill again.\"";

	const string CONST_news557 = "completely strapped for cash.&r";
	const string CONST_news556 = "to the current economic doldrums that have left the state ";
	const string CONST_news555 = "has stated that the case will not be retried, due ";
	const string CONST_news554 = " A spokesperson for the district attorney ";
	const string CONST_news552 = "Thank you for saving me from myself. ";
	const string CONST_news551 = " confessed and was sentenced to life, saying \"";
	const string CONST_news550 = "covered in the victims' blood. ";
	const string CONST_news549 = " was found with the murder weapon, ";
	const string CONST_news548 = "After an intensive manhunt, ";
	const string CONST_news547 = " slayings. ";
	const string CONST_news546 = " was convicted of the now-infamous ";
	const string CONST_news545 = " Ten years ago, ";
	const string CONST_news544 = " grants was not coerced in any way.&r";
	const string CONST_news543 = ", which even Justice ";
	const string CONST_news542 = ", despite the confession of ";

	const string CONST_news531 = "made the decision based on ";
	const string CONST_news530 = " of the notoriously liberal circuit of appeals here ";
	const string CONST_news529 = "Justice ";
	const string CONST_news528 = " was overturned by a federal judge yesterday. ";
	const string CONST_news527 = " - The conviction of confessed serial killer ";
	const string CONST_news608 = "masturbated";
	const string CONST_news607 = "[had fun]";
	const string CONST_news606 = "breastfed from a lactating woman";
	const string CONST_news605 = "[fed] from a [woman]";
	const string CONST_news604 = "breastfed from an exposed woman";
	const string CONST_news603 = "[fed] from [an indecent] woman";
	const string CONST_news602 = "screamed \"f*ck the police those g*dd*mn m*th*f*ck*rs. I got a f*cking ticket this morning and I'm f*cking p*ss*d as sh*t.\"";
	const string CONST_news601 = "screamed \"[darn] the police those [big dumb jerks]. I got a [stupid] ticket this morning and I'm [so angry].\"";
	const string CONST_news599 = "encouraged listeners to call in and relieve themselves";
	const string CONST_news598 = "encouraged listeners to call in and take a piss";
	const string CONST_news597 = "encouraged listeners to call in and [urinate]";
	const string CONST_news596 = "had intercourse";
	const string CONST_news595 = "fucked";
	const string CONST_news594 = "[had consensual intercourse in the missionary position]";
	const string CONST_newsX09 = "screamed \"fuck the police those goddamn motherfuckers. I got a fucking ticket this morning and I'm fucking pissed as shit.\"";

	const string CONST_news616 = "some";
	const string CONST_news615 = "dozens of";
	const string CONST_news614 = "hundreds of";
	const string CONST_news613 = "several hundred";
	const string CONST_news612 = "thousands of";
	const string CONST_news623 = "within the town. ";
	const string CONST_news622 = "in neighboring towns. ";
	const string CONST_news621 = "within the county. ";
	const string CONST_news620 = "from all over the state. ";
	const string CONST_news619 = "across the nation. ";
	const string CONST_news625 = "stated that the incident is under investigation.";
	const string CONST_news624 = " A spokesperson for the FCC ";
	const string CONST_news618 = "from irate listeners ";
	const string CONST_news617 = " complaints ";
	const string CONST_news611 = "the FCC received ";
	const string CONST_news610 = " later apologized, ";
	const string CONST_news609 = " on the air. Although ";

	const string CONST_news593 = " reportedly ";
	const string CONST_news592 = "\", ";
	const string CONST_news591 = "'s ";
	const string CONST_news590 = "broadcast of the program \"";
	const string CONST_news589 = " has brought radio entertainment to a new low. During yesterday's ";
	const string CONST_news588 = " - Infamous FM radio shock jock ";
	const string CONST_newsB939 = "Miss ";
	const string CONST_news638 = "Mr. ";
	const string CONST_news637 = "Mrs. ";
	const string CONST_news636 = "Ms. ";
	const string CONST_news648 = "mass shooting";
	const string CONST_news642 = "firefight, killing the attacker ";
	const string CONST_news641 = "firefight, [putting the attacker to sleep] ";

	const string CONST_newsB940 = "he ";

	const string CONST_news650 = "'s heroic actions.\"";
	const string CONST_news649 = " if not for ";
	const string CONST_news646 = " The spokesperson for the police department said, \"We'd have a yet another ";
	const string CONST_news645 = "could hurt anyone else.&r";
	const string CONST_news644 = "she ";
	const string CONST_news643 = "before ";

	const string CONST_news640 = " became more agitated, the heroic citizen was forced to engage the shooter in a ";
	const string CONST_news639 = " attempted to talk down the shooter, but as ";
	const string CONST_news635 = " Initially, ";
	const string CONST_news634 = " to take cover while others called the police.&r";
	const string CONST_news633 = "forcing ";
	const string CONST_news632 = "The citizen pulled a concealed handgun and fired once at the shooter, ";
	const string CONST_news631 = " sprung into action. ";
	const string CONST_news630 = " opened fire at the ";
	const string CONST_news629 = " After ";
	const string CONST_news628 = " was prevented by a bystander with a gun.";
	const string CONST_news626 = " - In a surprising turn, a ";
	const string CONST_news678 = "Imma kill all you b*tches, startin' with this m*th*f*ck*r here.";
	const string CONST_news677 = "[I will harm all police officers], startin' with this [one] here.";
	const string CONST_news676 = "Imma kill all you bitches, startin' with this mothafucker here.";
	const string CONST_news675 = "Why the f*ck am I talkin' to you? I'd rather kill this pig.";
	const string CONST_news674 = "Why [am I] talkin' to you? I'd rather [harm this police officer.]";
	const string CONST_news673 = "Why the fuck am I talkin' to you? I'd rather kill this pig.";
	const string CONST_news672 = "F*ck a m*th*f*ck*n' bull. I'm killin' this pig sh*t.";
	const string CONST_news671 = "[Too late.] [I am going to harm this police officer.]";
	const string CONST_news670 = "Fuck a muthafuckin' bull. I'm killin' this pig shit.";
	const string CONST_news669 = "Ah, f*ck this sh*t. This punk b*tch is f*ckin' dead!";
	const string CONST_news668 = "Ah, [no way.] This [police officer will be harmed!]";
	const string CONST_news667 = "Ah, fuck this shit. This punk bitch is fuckin' dead!";
	const string CONST_news684 = "killed the guard";
	const string CONST_news683 = "[harmed] the guard";

	const string CONST_newsB944 = "neo-pagan";
//	const string CONST_newsB943 = "him";
	const string CONST_newsB942 = "Bloods";

	const string CONST_news708 = " altar";
	const string CONST_news707 = "Satanic";
	const string CONST_news706 = "sacrificed the guard on a makeshift ";

	const string CONST_news701 = " off";
	const string CONST_news699 = "taken the guard to the execution chamber and finished ";
	const string CONST_news695 = "Crips";
	const string CONST_news694 = "poisoned the guard with drugs smuggled into the prison by the ";
	const string CONST_news693 = " own gun";
	const string CONST_news691 = "shot the guard with ";
	const string CONST_news690 = " cell";
	const string CONST_news688 = "smashed the guard's skull with the toilet seat from ";
	const string CONST_news711 = "beaten to death";
	const string CONST_news710 = "[also harmed]";

	const string CONST_news657 = " Two weeks ago, convicted rapist ";
	const string CONST_news656 = " Two weeks ago, convicted [reproduction fiend] ";

	const string CONST_newsB941 = "himself";

	const string CONST_news712 = " while \"resisting capture\", according to a prison spokesperson.";
	const string CONST_news709 = ". The prisoner was ";
	const string CONST_news682 = " had already ";
	const string CONST_news681 = "the hostage, but ";
	const string CONST_news680 = " The tower was breached in an attempt to reach ";
	const string CONST_news666 = " reportedly screamed into the receiver \"";
	const string CONST_news665 = " days, but talks were cut short when ";
	const string CONST_news664 = "attempted to negotiate by phone for ";
	const string CONST_news663 = "Authorities locked down the prison and ";
	const string CONST_news662 = " with the guard in a prison tower. ";
	const string CONST_news661 = "herself";
	const string CONST_news660 = " and barricaded ";
	const string CONST_news659 = ", overpowered ";
	const string CONST_news658 = ", an inmate at ";
	const string CONST_news655 = " captor.";
	const string CONST_news653 = "death of both the prison guard being held hostage and ";
	const string CONST_news652 = " Correctional Facility ended tragically yesterday with the ";
	const string CONST_news651 = " - The hostage crisis at the ";
	const string CONST_activities149 = " but did find a ";
	const string CONST_activities148 = " was unable to find a ";
//	const string singleDot = ".";
	const string CONST_activities186 = "Enter - Call it a day.";

	const string CONST_activities168 = "Enter - Yes, the Viper has deterred ";
	const string CONST_activities167 = " is deterred.";
	const string CONST_activities166 = "Enter - The Viper?   ";
	const string CONST_interrogation133 = " wonders about death.";
	const string CONST_interrogation132 = " wonders about apples.";
	const string CONST_interrogation131 = " cries helplessly.";
	const string CONST_interrogation130 = " barks helplessly.";
	const string CONST_interrogation129 = " curls up in the corner and doesn't move.";
	const string CONST_interrogation128 = " goes limp in the restraints.";
	const string CONST_interrogation127 = "mommy.";
	const string CONST_interrogation126 = "God's mercy.";
	const string CONST_interrogation125 = "John Lennon's mercy.";
	const string CONST_interrogation124 = " screams helplessly for ";

	const string CONST_interrogation143 = "talks about hugging ";
	const string CONST_interrogation142 = " stammers and ";

	const string CONST_interrogationB150 = "hugs ";
//	const string singleDot = ".";

	const string CONST_interrogation148 = " begs for the nightmare to end.";
	const string CONST_interrogation147 = " curls up and";
	const string CONST_interrogation146 = " to stop looking like Hitler.";
	const string CONST_interrogation145 = " screams for ";
	const string CONST_interrogation144 = " begs Hitler to stay and kill ";
	const string CONST_fight126 = "gracefully strikes at";
	const string CONST_fight125 = "jump kicks";
	const string CONST_fight124 = "strikes at";
	const string CONST_fight123 = "kicks";
	const string CONST_fight122 = "grapples with";
	const string CONST_fight121 = "swings at";
	const string CONST_fight120 = "punches";
	const string CONST_fight152 = " BLOWING IT OFF!";
	const string CONST_fight151 = " CUTTING IT OFF!";
	const string CONST_fight150 = " BLOWING IT IN HALF!";
	const string CONST_fight149 = " BLOWING IT APART!";
	const string CONST_fight148 = " CUTTING IT IN HALF!";
	const string CONST_commondisplay180 = "Missing Teeth";
	const string CONST_commondisplay178 = "No Teeth";
	const string CONST_commondisplay177 = "No Tongue";

	const string CONST_commondisplay188 = "Broken Ribs";
	const string CONST_commondisplay187 = "Broken Rib";
	const string CONST_commondisplay186 = "All Ribs Broken";
	const string CONST_commondisplay185 = "Busted Spleen";
	const string CONST_commondisplay184 = "Stomach Injured";
	const string CONST_commondisplay183 = "L. Kidney Damaged";
	const string CONST_commondisplay182 = "R. Kidney Damaged";
	const string CONST_commondisplay181 = "Liver Damaged";
	const string CONST_commondisplay179 = "Missing a Tooth";
	const string CONST_commondisplay176 = "No Nose";
	const string CONST_commondisplay175 = "No Left Eye";
	const string CONST_commondisplay174 = "No Right Eye";
	const string CONST_commondisplay173 = "Broken Lw Spine";
	const string CONST_commondisplay172 = "Broken Up Spine";
	const string CONST_commondisplay171 = "Broken Neck";
	const string CONST_commondisplay170 = "L. Lung Collapsed";
	const string CONST_commondisplay169 = "R. Lung Collapsed";
	const string CONST_commondisplay168 = "Heart Punctured";
	const string CONST_miscC026 = "): ";

	const string CONST_miscB025 = ".mid:  ";
	const string CONST_miscB024 = ".mid";
	const string CONST_miscB023 = ".ogg:  ";
	const string CONST_miscB022 = ".ogg";
	const string CONST_miscB021 = "/";
	const string CONST_miscB020 = ".mid as MIDI fallback)";
	const string CONST_misc019 = "1234567890-";
	const string CONST_misc018 = "SDL_mixer function Mix_PlayMusic() failed:  ";
	const string CONST_misc017 = "Pastorale";
	const string CONST_misc016 = "Mars";
	const string CONST_misc015 = "Ogg Vorbis support failed to load. MIDI music will be used instead if possible.";
	const string CONST_misc014 = "Unable to initialize SDL_mixer:  ";
	const string CONST_misc013 = "Unable to initialize SDL:  ";
	const string CONST_misc012 = "SDL_mixer function Mix_LoadMUS() failed to load ";
	const string CONST_misc011 = "midi/";
	const string CONST_misc009 = "ogg/";
	const string CONST_misc008 = "Loading MIDI music (";
	const string CONST_misc007 = "(with ";
	const string CONST_misc006 = "Loading Ogg Vorbis music (";
	const string CONST_misc005 = "listOfStates.txt";
	const string CONST_misc004 = "sextypeAcronym.txt";
	const string CONST_misc003 = "sexseekAcronym.txt";
	const string CONST_misc002 = "sexwhoAcronym.txt";
	const string CONST_misc001 = "sexdescAcronym.txt";
	vector<string> listOfStates;
	vector<file_and_text_collection> misc_text_file_collection = {
	customText(&sexdescAcronym, mostlyendings + CONST_misc001),
	customText(&sexwhoAcronym, mostlyendings + CONST_misc002),
	customText(&sexseekAcronym, mostlyendings + CONST_misc003),
	customText(&sextypeAcronym, mostlyendings + CONST_misc004),
	customText(&listOfStates, mostlyendings + CONST_misc005),
	};
	const vector<string> elementary = { CONST_news395, CONST_news404 };
	const vector<string> middle = { CONST_news396, CONST_news405 };
	const vector<string> high = { CONST_news397, CONST_news406 };
	const vector<string> university = { CONST_news398, CONST_news407 };
	map<int, vector<string> > SchoolTypes = {
		map<int, vector<string> >::value_type(0, elementary),
		map<int,  vector<string> >::value_type(1, middle),
		map<int,  vector<string> >::value_type(2, high),
		map<int,  vector<string> >::value_type(3, university),
	};

#endif	//MISC_CPP
#ifdef	MISCACTIONS_CPP

// miscactions.cpp


#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locationsEnums.h"
//#include "../sitemode/sitedisplay.h"
	void clearmessagearea(bool redrawmaparea = true);
#include "../log/log.h"
	//#include "../common/commondisplay.h"
	void printparty();
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
	// for void criminalizeparty
	//#include "../daily/daily.h"
	char securityable(int type);

#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../customMaps.h"
	short getCurrentSite();
#include "miscactions.h"
	vector<string> was_abused;
	map<short, string> discussIssues;
	map<short, string> discussesIssues;
	const string activities = "activities\\";

	// extern string singleDot;
	// extern string singleSpace;
	void fillEncounter(CreatureTypes c, int numleft);
	void whoAreWaitingForRescue(vector<DeprecatedCreature *>& waiting_for_rescue, int cursite, short special);
	//vector<string> was_abused;
	//vector<file_and_text_collection> misc_activities_text_file_collection = {
		/*miscactions.cpp*/
		//customText(&was_abused, activities + CONST_miscactions004),
	//};
	void fillEncounter(CreatureTypes c, int numleft);
	//map<short, string> discussIssues;
	//map<short, string> discussesIssues;
	map<int, CheckDifficulty> unlockDifficulty = {
		map<int, CheckDifficulty>::value_type(UNLOCK_CAGE,        DIFFICULTY_VERYEASY),
		map<int, CheckDifficulty>::value_type(UNLOCK_CAGE_HARD,   DIFFICULTY_AVERAGE),
		map<int, CheckDifficulty>::value_type(UNLOCK_CELL,        DIFFICULTY_FORMIDABLE),
		map<int, CheckDifficulty>::value_type(UNLOCK_ARMORY,      DIFFICULTY_HEROIC),
		map<int, CheckDifficulty>::value_type(UNLOCK_SAFE,        DIFFICULTY_HEROIC),
		map<int, CheckDifficulty>::value_type(UNLOCK_VAULT,       DIFFICULTY_HEROIC),
	};
	extern Deprecatedsquadst *activesquad;
	extern Log gamelog;
	extern short fieldskillrate;
	bool isThereASiteAlarm();
	void setSiteAlarmOne();
	extern Deprecatedsquadst *activesquad;
	extern Log gamelog;
	extern short sitealarmtimer;
	extern Deprecatedsquadst *activesquad;
	extern Log gamelog;
	vector<NameAndAlignment> getEncounterNameAndAlignment();
	extern Deprecatedsquadst *activesquad;
	extern Log gamelog;

	extern short sitealienate;
	extern Log gamelog;
	extern Deprecatedsquadst *activesquad;
	extern Deprecatedsquadst *activesquad;
	const string CONST_miscactions077 = "You'll have to come back later.";
	const string CONST_miscactions076 = "There's nobody left to carry the others.";
	const string CONST_miscactions074 = "There's nobody left to carry ";
	const string CONST_miscactions073 = " will have to haul a Liberal.";
	const string CONST_miscactions072 = "so ";
	const string CONST_miscactions071 = " from the Conservatives.";
	const string CONST_miscactions070 = "You've rescued ";
	const string CONST_miscactions067 = "at their desks.  The Squad might yet escape.";
	const string CONST_miscactions066 = "The show was so good that security listened to it ";
	const string CONST_miscactions065 = " that security watched it ";
	const string CONST_miscactions064 = "entertaining";
	const string CONST_miscactions063 = "hilarious";
	const string CONST_miscactions062 = "The show was so ";
	const string CONST_miscactions061 = "after the show!";
	const string CONST_miscactions060 = "Security is waiting for the Squad ";
	const string CONST_miscactions059 = "They no longer feel alienated.";
	const string CONST_miscactions058 = "Moderates at the station appreciated the show.";
	const string CONST_miscactions057 = ", the hostage, is kept off-air.";
	const string CONST_miscactions056 = " is forced on to ";
	const string CONST_miscactions055 = "The hostage ";
	const string CONST_miscactions054 = "It was the best hour of AM radio EVER.";
	const string CONST_miscactions053 = "It was thought-provoking, even humorous.";
	const string CONST_miscactions052 = "The Squad put on a good show.";
	const string CONST_miscactions051 = "The show was all right.";
	const string CONST_miscactions050 = "It is mediocre radio.";
	const string CONST_miscactions049 = "It is a very boring hour.";
	const string CONST_miscactions048 = "The show really sucks.";
	const string CONST_miscactions047 = "The Squad sounds wholly insane.";
	const string CONST_miscactions046 = "It was the best hour of Cable TV EVER.";
	const string CONST_miscactions042 = "It is mediocre TV.";
	const string CONST_miscactions039 = "The Squad looks completely insane.";
	const string CONST_miscactions038 = "The Squad takes control of the microphone and ";
	const string CONST_miscactions037 = "The Squad steps in front of the cameras and ";
	const string CONST_miscactions036 = "the broadcast never happens.";
	const string CONST_miscactions035 = "The Conservatives in the room hurry the Squad, so ";
	const string CONST_miscactions034 = "Including the BLIND HACKER you brought.";
	const string CONST_miscactions033 = "You can't find anyone to do the job.";
	const string CONST_miscactions032 = " bypass the vault's electronic lock.";
	const string CONST_miscactions031 = " bypass the supercomputer security.";
	const string CONST_miscactions030 = " see how to";
	const string CONST_miscactions029 = " couldn't";
	const string CONST_miscactions028 = "!";
	const string CONST_miscactions027 = " despite being blind";
	const string CONST_miscactions026 = " disabled the second layer of security";
	const string CONST_miscactions025 = " burned a disk of top secret files";
	const string CONST_miscactions024 = " has";
	const string CONST_miscactions022 = " kicks the door";
	const string CONST_miscactions021 = " rams into the door";
	const string CONST_miscactions020 = "Alarms go off!";
	const string CONST_miscactions018 = "kicks in the door";
	const string CONST_miscactions017 = "rams open the door";
	const string CONST_miscactions016 = "smashes in the door";
	const string CONST_miscactions015 = "uses a crowbar on the door";
	const string CONST_miscactions013 = " can't figure the lock out.";
	const string CONST_miscactions012 = " is close, but can't quite get the lock open.";
	const string CONST_miscactions010 = "cracks the combo locks";
	const string CONST_miscactions009 = "unlocks the cell";
	const string CONST_miscactions008 = "opens the armory";
	const string CONST_miscactions007 = "cracks the safe";
	const string CONST_miscactions006 = "unlocks the cage";
	const string CONST_miscactions005 = "unlocks the door";
	const string CONST_miscactions004 = "was_abused.txt";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";
	vector<file_and_text_collection> misc_activities_text_file_collection = {
		/*miscactions.cpp*/
		customText(&was_abused, activities + CONST_miscactions004),
	};
#endif	//MISCACTIONS_CPP
#ifdef	MONEY_CPP
// money.cpp

	const string CONST_money003 = "$";
	const string CONST_money002 = "amount";

	const string tag_money = "money";
#endif	//MONEY_CPP
#ifdef	MONTHLY_CPP
// monthly.cpp

#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../basemode/liberalagenda.h"
// for liberalagenda
//#include "../items/itemPool.h"
//#include "../items/lootTypePool.h"
//#include "../common/commonactions.h"
	char endcheck(char cause);
	void change_public_opinion(int v, int power, char affect = 1, char cap = 100);
#include "../log/log.h"
#include "../common/commondisplay.h"
	// for set_alignment_color and delimiter
#include "../common/translateid.h"
// for  int getpoolcreature(int id);
#include "../title/titlescreen.h"
// for void reset;
#include "../title/highscore.h"
// for viewhighscores, in event of EndGameStatus
#include "../politics/politics.h"
//for publicmood
//#include "../monthly/lcsmonthly.h"
	void fundreport(char &clearformess);
	//#include "../daily/daily.h"
	//for dispersalcheck and securitytable
	void dispersalcheck(char &clearformess);
#include "../cursesAlternative.h"
#include "../set_color_support.h"
	//#include <common\\getnames.h>
	std::string getview(short view, bool shortname);
#include "../locations/locationsPool.h"
#include "../locations/locationsEnums.h"
#include "../common/creaturePool.h"
#include "../common/creaturePoolHeader.h"
	/* end the game and clean up */
	void end_game(int err = EXIT_SUCCESS);
	void clearRentExemptions();
	void publishSpecialEditions(char &clearformess);
	void manageGrafiti();

	//extern string singleDot;

#include "../common/musicClass.h"
	extern short attitude[VIEWNUM];
	extern short background_liberal_influence[VIEWNUM];

	extern MusicClass music;
	extern char endgamestate;
	extern char newscherrybusted;
	extern bool stalinmode;
	extern short attitude[VIEWNUM];
	extern char endgamestate;
	extern short attitude[VIEWNUM];
	extern Log gamelog;
	extern MusicClass music;
	// Show polls when you can't see things
	extern bool SHOWWAIT;
	// Show die rolls, 100% accurate poll numbers
	extern bool SHOWMECHANICS;
	extern Log gamelog;
	extern int year;
	extern int day;
	extern int month;
	extern char disbanding;
	extern bool stalinmode;
	extern int disbandtime;
	extern class Ledger ledger;
	extern short lawList[LAWNUM];
	extern short attitude[VIEWNUM];
	extern short public_interest[VIEWNUM];
	extern short background_liberal_influence[VIEWNUM];
	const string CONST_monthly017 = "They will never see the utopia they dreamed of...";
	const string CONST_monthly016 = "The last LCS members have all been hunted down.";
	const string CONST_monthly015 = "The Liberal Crime Squad is now just a memory.";

//	const string CONST_monthly017 = "They will never see the utopia they dreamed of...";
//	const string CONST_monthly016 = "The last LCS members have all been hunted down.";
//	const string CONST_monthly015 = "The Liberal Crime Squad is now just a memory.";
	const string CONST_monthly014 = "Press any key to reflect on these poll numbers.";
	const string CONST_monthly013 = "Arch-Conservative";
	const string CONST_monthly012 = "-  ";
	const string CONST_monthly011 = "Conservative  ";
	const string CONST_monthly009 = "moderate  ";
	const string CONST_monthly007 = "Liberal  ";
	const string CONST_monthly005 = "Elite Liberal ";
	const string CONST_monthly004 = "컴�";
	const string CONST_monthly003 = "CURRENT POLITICAL TRENDS";
	const string CONST_monthly002 = "LCS MONTHLY INTELLIGENCE REPORT";
#endif	//MONTHLY_CPP
#ifdef	NEWENCOUNTER_CPP
// newencounter.cpp


#include "../creature/newcreature.h"
#include "../locations/locations.h"

#include "../locations/locationsPool.h"
	void fillEncounter(CreatureTypes c, int numleft);
	void emptyEncounter();
	map<int, vector<int> > locationsSpawners = {
		map<int, vector<int> >::value_type(SITE_BUSINESS_JUICEBAR,{
		CREATURE_TEENAGER, 10,
		CREATURE_JUDGE_LIBERAL, 1,
		CREATURE_COLLEGESTUDENT, 10,
		CREATURE_MUSICIAN, 2,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_TEACHER, 1,
		CREATURE_HSDROPOUT, 1,
		CREATURE_ENGINEER, 1,
		CREATURE_FASTFOODWORKER, 1,
		CREATURE_BAKER, 1,
		CREATURE_BARISTA, 1,
		CREATURE_BARTENDER, 1,
		CREATURE_TELEMARKETER, 1,
		CREATURE_CARSALESMAN, 1,
		CREATURE_OFFICEWORKER, 1,
		CREATURE_MAILMAN, 1,
		CREATURE_CHEF, 1,
		CREATURE_NURSE, 1,
		CREATURE_AMATEURMAGICIAN, 1,
		CREATURE_HIPPIE, 6,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_SOCIALITE, 2,
		CREATURE_PROGRAMMER, 1,
		CREATURE_RETIREE, 1,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_CAMERAMAN, 1,
		CREATURE_HAIRSTYLIST, 1,
		CREATURE_FASHIONDESIGNER, 1,
		CREATURE_CLERK, 1,
		CREATURE_THIEF, 1,
		CREATURE_ACTOR, 1,
		CREATURE_YOGAINSTRUCTOR, 1,
		CREATURE_MARTIALARTIST, 1,
		CREATURE_ATHLETE, 1,
		CREATURE_LOCKSMITH, 1
			}),
		map<int, vector<int> >::value_type(SITE_BUSINESS_CIGARBAR,{
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_CORPORATE_MANAGER, 30,
		CREATURE_COP, 5,
		CREATURE_JUDGE_CONSERVATIVE, 1,
		CREATURE_RADIOPERSONALITY, 1,
		CREATURE_NEWSANCHOR, 1,
		CREATURE_MILITARYOFFICER, 1,
		CREATURE_LAWYER, 15,
		CREATURE_DOCTOR, 10,
		CREATURE_PSYCHOLOGIST, 1,
		CREATURE_MUSICIAN, 1,
		CREATURE_ENGINEER, 10,
		CREATURE_BARTENDER, 10,
		CREATURE_FOOTBALLCOACH, 1,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_SOCIALITE, 2,
		CREATURE_RETIREE, 1,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_FASHIONDESIGNER, 1,
		CREATURE_THIEF, 1,
		CREATURE_ACTOR, 1,
		CREATURE_ATHLETE, 1,
		CREATURE_FIREFIGHTER, 1,
		CREATURE_LOCKSMITH, 1, }),
		map<int, vector<int> >::value_type(SITE_BUSINESS_CRACKHOUSE,{
		CREATURE_TEENAGER, 100,
		CREATURE_MUSICIAN, 1,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_HSDROPOUT, 30,
		CREATURE_BUM, 200,
		CREATURE_GANGMEMBER, 200,
		CREATURE_CRACKHEAD, 200,
		CREATURE_PROSTITUTE, 200,
		CREATURE_BIKER, 5,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_THIEF, 3,
		CREATURE_ACTOR, 1,
		CREATURE_JOURNALIST, 2 }
		),
		map<int, vector<int> >::value_type(SITE_GOVERNMENT_WHITE_HOUSE,{
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_WORKER_JANITOR, 2,
		CREATURE_WORKER_SECRETARY, 2,
		CREATURE_TEENAGER, 1,
		CREATURE_JUDGE_LIBERAL, 1,
		CREATURE_JUDGE_CONSERVATIVE, 1,
		CREATURE_AGENT, 2,
		CREATURE_MILITARYOFFICER, 3,
		CREATURE_LAWYER, 3,
		CREATURE_DOCTOR, 1,
		CREATURE_COLLEGESTUDENT, 1,
		CREATURE_TEACHER, 1,
		CREATURE_OFFICEWORKER, 5,
		CREATURE_FOOTBALLCOACH, 1,
		CREATURE_CHEF, 1,
		CREATURE_VETERAN, 1,
		CREATURE_JOURNALIST, 2,
		CREATURE_SOCIALITE, 1,
		CREATURE_PHOTOGRAPHER, 2,
		CREATURE_CAMERAMAN, 1,
		CREATURE_HAIRSTYLIST, 1,
		CREATURE_CLERK, 5,
		CREATURE_ACTOR, 1,
		CREATURE_ATHLETE, 1 }
		),
		map<int, vector<int> >::value_type(SITE_OUTDOOR_PUBLICPARK,{
		CREATURE_SECURITYGUARD, 5,
		CREATURE_SCIENTIST_LABTECH, 10,
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_CORPORATE_MANAGER, 10,
		CREATURE_WORKER_JANITOR, 5,
		CREATURE_WORKER_SECRETARY, 15,
		CREATURE_TEENAGER, 5,
		CREATURE_COP, 5,
		CREATURE_JUDGE_LIBERAL, 1,
		CREATURE_JUDGE_CONSERVATIVE, 1,
		CREATURE_AGENT, 1,
		CREATURE_RADIOPERSONALITY, 1,
		CREATURE_NEWSANCHOR, 1,
		CREATURE_MILITARYOFFICER, 1,
		CREATURE_LAWYER, 5,
		CREATURE_DOCTOR, 5,
		CREATURE_PSYCHOLOGIST, 1,
		CREATURE_NURSE, 5,
		CREATURE_SEWERWORKER, 1,
		CREATURE_COLLEGESTUDENT, 30,
		CREATURE_MUSICIAN, 5,
		CREATURE_MATHEMATICIAN, 5,
		CREATURE_TEACHER, 5,
		CREATURE_HSDROPOUT, 1,
		CREATURE_BUM, 1,
		CREATURE_GANGMEMBER, 1,
		CREATURE_CRACKHEAD, 1,
		CREATURE_PRIEST, 1,
		CREATURE_ENGINEER, 5,
		CREATURE_FASTFOODWORKER, 5,
		CREATURE_BAKER, 1,
		CREATURE_BARISTA, 10,
		CREATURE_BARTENDER, 1,
		CREATURE_TELEMARKETER, 5,
		CREATURE_CARSALESMAN, 3,
		CREATURE_OFFICEWORKER, 10,
		CREATURE_FOOTBALLCOACH, 1,
		CREATURE_PROSTITUTE, 1,
		CREATURE_MAILMAN, 1,
		CREATURE_GARBAGEMAN, 1,
		CREATURE_PLUMBER, 1,
		CREATURE_CHEF, 1,
		CREATURE_CONSTRUCTIONWORKER, 3,
		CREATURE_AMATEURMAGICIAN, 1,
		CREATURE_MERC, 1,
		CREATURE_SOLDIER, 1,
		CREATURE_VETERAN, 3,
		CREATURE_HIPPIE, 1,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_SOCIALITE, 1,
		CREATURE_BIKER, 1,
		CREATURE_TRUCKER, 1,
		CREATURE_TAXIDRIVER, 1,
		CREATURE_PROGRAMMER, 5,
		CREATURE_RETIREE, 3,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_CAMERAMAN, 1,
		CREATURE_HAIRSTYLIST, 1,
		CREATURE_FASHIONDESIGNER, 1,
		CREATURE_CLERK, 1,
		CREATURE_THIEF, 1,
		CREATURE_ACTOR, 1,
		CREATURE_YOGAINSTRUCTOR, 1,
		CREATURE_MARTIALARTIST, 1,
		CREATURE_ATHLETE, 1,
		CREATURE_FIREFIGHTER, 1,
		CREATURE_LOCKSMITH, 1 }
		),
		map<int, vector<int> >::value_type(SITE_BUSINESS_LATTESTAND,{
		CREATURE_SECURITYGUARD, 5,
		CREATURE_SCIENTIST_LABTECH, 10,
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_CORPORATE_MANAGER, 10,
		CREATURE_WORKER_JANITOR, 5,
		CREATURE_WORKER_SECRETARY, 15,
		CREATURE_TEENAGER, 5,
		CREATURE_COP, 5,
		CREATURE_JUDGE_LIBERAL, 1,
		CREATURE_JUDGE_CONSERVATIVE, 1,
		CREATURE_AGENT, 1,
		CREATURE_RADIOPERSONALITY, 1,
		CREATURE_NEWSANCHOR, 1,
		CREATURE_MILITARYOFFICER, 1,
		CREATURE_LAWYER, 5,
		CREATURE_DOCTOR, 5,
		CREATURE_PSYCHOLOGIST, 1,
		CREATURE_NURSE, 5,
		CREATURE_SEWERWORKER, 1,
		CREATURE_COLLEGESTUDENT, 30,
		CREATURE_MUSICIAN, 5,
		CREATURE_MATHEMATICIAN, 5,
		CREATURE_TEACHER, 5,
		CREATURE_HSDROPOUT, 1,
		CREATURE_BUM, 1,
		CREATURE_GANGMEMBER, 1,
		CREATURE_CRACKHEAD, 1,
		CREATURE_PRIEST, 1,
		CREATURE_ENGINEER, 5,
		CREATURE_FASTFOODWORKER, 5,
		CREATURE_BAKER, 1,
		CREATURE_BARISTA, 10,
		CREATURE_BARTENDER, 1,
		CREATURE_TELEMARKETER, 5,
		CREATURE_CARSALESMAN, 3,
		CREATURE_OFFICEWORKER, 10,
		CREATURE_FOOTBALLCOACH, 1,
		CREATURE_PROSTITUTE, 1,
		CREATURE_MAILMAN, 1,
		CREATURE_GARBAGEMAN, 1,
		CREATURE_PLUMBER, 1,
		CREATURE_CHEF, 1,
		CREATURE_CONSTRUCTIONWORKER, 3,
		CREATURE_AMATEURMAGICIAN, 1,
		CREATURE_MERC, 1,
		CREATURE_SOLDIER, 1,
		CREATURE_VETERAN, 3,
		CREATURE_HIPPIE, 1,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_SOCIALITE, 1,
		CREATURE_BIKER, 1,
		CREATURE_TRUCKER, 1,
		CREATURE_TAXIDRIVER, 1,
		CREATURE_PROGRAMMER, 5,
		CREATURE_RETIREE, 3,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_CAMERAMAN, 1,
		CREATURE_HAIRSTYLIST, 1,
		CREATURE_FASHIONDESIGNER, 1,
		CREATURE_CLERK, 1,
		CREATURE_THIEF, 1,
		CREATURE_ACTOR, 1,
		CREATURE_YOGAINSTRUCTOR, 1,
		CREATURE_MARTIALARTIST, 1,
		CREATURE_ATHLETE, 1,
		CREATURE_FIREFIGHTER, 1,
		CREATURE_LOCKSMITH, 1 }
		),
		map<int, vector<int> >::value_type(SITE_BUSINESS_VEGANCOOP,{
		CREATURE_TEENAGER, 5,
		CREATURE_JUDGE_LIBERAL, 1,
		CREATURE_COLLEGESTUDENT, 50,
		CREATURE_MUSICIAN, 20,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_TEACHER, 1,
		CREATURE_HSDROPOUT, 10,
		CREATURE_BUM, 1,
		CREATURE_HIPPIE, 50,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_RETIREE, 1,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_YOGAINSTRUCTOR, 2 }
		),
		map<int, vector<int> >::value_type(SITE_BUSINESS_INTERNETCAFE,{
		CREATURE_SCIENTIST_LABTECH, 5,
		CREATURE_CORPORATE_MANAGER, 3,
		CREATURE_TEENAGER, 15,
		CREATURE_LAWYER, 3,
		CREATURE_COLLEGESTUDENT, 25,
		CREATURE_MUSICIAN, 2,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_TEACHER, 5,
		CREATURE_ENGINEER, 15,
		CREATURE_DOCTOR, 1,
		CREATURE_BARISTA, 10,
		CREATURE_CARSALESMAN, 3,
		CREATURE_OFFICEWORKER, 15,
		CREATURE_WORKER_SECRETARY, 5,
		CREATURE_HIPPIE, 1,
		CREATURE_PROGRAMMER, 15,
		CREATURE_RETIREE, 5,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_CAMERAMAN, 1,
		CREATURE_CLERK, 1,
		CREATURE_LOCKSMITH, 1 }
		),
		map<int, vector<int> >::value_type(SITE_RESIDENTIAL_SHELTER,{
		CREATURE_WORKER_JANITOR, 5,
		CREATURE_TEENAGER, 20,
		CREATURE_MUSICIAN, 3,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_BUM, 200,
		CREATURE_GANGMEMBER, 5,
		CREATURE_CRACKHEAD, 50,
		CREATURE_PROSTITUTE, 10,
		CREATURE_AMATEURMAGICIAN, 1,
		CREATURE_HIPPIE, 1,
		CREATURE_NURSE, 5,
		CREATURE_BIKER, 1,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_THIEF, 5,
		CREATURE_ACTOR, 1, }
		),
		map<int, vector<int> >::value_type(SITE_RESIDENTIAL_TENEMENT,{
		CREATURE_SECURITYGUARD, 1,
		CREATURE_SCIENTIST_LABTECH, 1,
		CREATURE_WORKER_JANITOR, 3,
		CREATURE_WORKER_SECRETARY, 2,
		CREATURE_TEENAGER, 5,
		CREATURE_SEWERWORKER, 1,
		CREATURE_COLLEGESTUDENT, 1,
		CREATURE_MUSICIAN, 1,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_TEACHER, 1,
		CREATURE_HSDROPOUT, 3,
		CREATURE_BUM, 3,
		CREATURE_GANGMEMBER, 3,
		CREATURE_CRACKHEAD, 3,
		CREATURE_FASTFOODWORKER, 1,
		CREATURE_BARISTA, 1,
		CREATURE_BARTENDER, 1,
		CREATURE_TELEMARKETER, 1,
		CREATURE_CARSALESMAN, 1,
		CREATURE_OFFICEWORKER, 1,
		CREATURE_PROSTITUTE, 3,
		CREATURE_MAILMAN, 1,
		CREATURE_GARBAGEMAN, 1,
		CREATURE_CONSTRUCTIONWORKER, 1,
		CREATURE_AMATEURMAGICIAN, 1,
		CREATURE_HICK, 1,
		CREATURE_SOLDIER, 1,
		CREATURE_VETERAN, 2,
		CREATURE_HIPPIE, 1,
		CREATURE_BIKER, 1,
		CREATURE_TAXIDRIVER, 1,
		CREATURE_RETIREE, 1,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_HAIRSTYLIST, 1,
		CREATURE_CLERK, 1,
		CREATURE_THIEF, 1,
		CREATURE_ACTOR, 1,
		CREATURE_FIREFIGHTER, 1,
		CREATURE_LOCKSMITH, 1 }
		),
		map<int, vector<int> >::value_type(SITE_RESIDENTIAL_APARTMENT,{

		CREATURE_SECURITYGUARD, 1,
		CREATURE_SCIENTIST_LABTECH, 1,
		CREATURE_CORPORATE_MANAGER, 1,
		CREATURE_WORKER_JANITOR, 1,
		CREATURE_WORKER_SECRETARY, 1,
		CREATURE_TEENAGER, 3,
		CREATURE_COP, 1,
		CREATURE_LAWYER, 1,
		CREATURE_SEWERWORKER, 1,
		CREATURE_COLLEGESTUDENT, 1,
		CREATURE_MUSICIAN, 1,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_TEACHER, 1,
		CREATURE_PRIEST, 1,
		CREATURE_ENGINEER, 1,
		CREATURE_FASTFOODWORKER, 1,
		CREATURE_BAKER, 1,
		CREATURE_BARISTA, 1,
		CREATURE_BARTENDER, 1,
		CREATURE_TELEMARKETER, 1,
		CREATURE_CARSALESMAN, 1,
		CREATURE_OFFICEWORKER, 1,
		CREATURE_FOOTBALLCOACH, 1,
		CREATURE_MAILMAN, 1,
		CREATURE_DOCTOR, 1,
		CREATURE_PSYCHOLOGIST, 1,
		CREATURE_NURSE, 1,
		CREATURE_GARBAGEMAN, 1,
		CREATURE_PLUMBER, 1,
		CREATURE_CHEF, 1,
		CREATURE_CONSTRUCTIONWORKER, 1,
		CREATURE_AMATEURMAGICIAN, 1,
		CREATURE_SOLDIER, 1,
		CREATURE_VETERAN, 2,
		CREATURE_HIPPIE, 1,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_TAXIDRIVER, 1,
		CREATURE_PROGRAMMER, 1,
		CREATURE_RETIREE, 1,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_CAMERAMAN, 1,
		CREATURE_HAIRSTYLIST, 1,
		CREATURE_CLERK, 1,
		CREATURE_THIEF, 1,
		CREATURE_ACTOR, 1,
		CREATURE_YOGAINSTRUCTOR, 1,
		CREATURE_MARTIALARTIST, 1,
		CREATURE_ATHLETE, 1,
		CREATURE_FIREFIGHTER, 1,
		CREATURE_LOCKSMITH, 1 }
		),
		map<int, vector<int> >::value_type(SITE_RESIDENTIAL_APARTMENT_UPSCALE,{
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_CORPORATE_MANAGER, 5,
		CREATURE_WORKER_JANITOR, 5,
		CREATURE_WORKER_SECRETARY, 1,
		CREATURE_TEENAGER, 3,
		CREATURE_JUDGE_LIBERAL, 1,
		CREATURE_JUDGE_CONSERVATIVE, 1,
		CREATURE_RADIOPERSONALITY, 1,
		CREATURE_NEWSANCHOR, 1,
		CREATURE_LAWYER, 5,
		CREATURE_DOCTOR, 5,
		CREATURE_PSYCHOLOGIST, 1,
		CREATURE_NURSE, 1,
		CREATURE_COLLEGESTUDENT, 1,
		CREATURE_MUSICIAN, 1,
		CREATURE_PROSTITUTE, 3,
		CREATURE_MAILMAN, 1,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_SOCIALITE, 2,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_FASHIONDESIGNER, 1,
		CREATURE_THIEF, 1,
		CREATURE_ACTOR, 1,
		CREATURE_ATHLETE, 1,
		CREATURE_LOCKSMITH, 1 }
		),
		map<int, vector<int> >::value_type(SITE_LABORATORY_COSMETICS,{
		CREATURE_SCIENTIST_LABTECH, 10,
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_CORPORATE_MANAGER, 1,
		CREATURE_WORKER_JANITOR, 10,
		CREATURE_WORKER_SECRETARY, 10,
		CREATURE_OFFICEWORKER, 10 }
		),
		map<int, vector<int> >::value_type(SITE_INDUSTRY_NUCLEAR,{
		CREATURE_SCIENTIST_LABTECH, 10,
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_CORPORATE_MANAGER, 1,
		CREATURE_WORKER_JANITOR, 10,
		CREATURE_WORKER_SECRETARY, 10,
		CREATURE_OFFICEWORKER, 10 }
		),
		map<int, vector<int> >::value_type(SITE_LABORATORY_GENETIC,{
		CREATURE_SCIENTIST_LABTECH, 10,
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_CORPORATE_MANAGER, 1,
		CREATURE_DOCTOR, 1,
		CREATURE_WORKER_JANITOR, 10,
		CREATURE_WORKER_SECRETARY, 10,
		CREATURE_OFFICEWORKER, 10 }
		),
		map<int, vector<int> >::value_type(SITE_GOVERNMENT_POLICESTATION,{
		CREATURE_SCIENTIST_LABTECH, 1,
		CREATURE_CORPORATE_MANAGER, 1,
		CREATURE_WORKER_JANITOR, 50,
		CREATURE_WORKER_SECRETARY, 1,
		CREATURE_TEENAGER, 5,
		CREATURE_JUDGE_LIBERAL, 1,
		CREATURE_JUDGE_CONSERVATIVE, 1,
		CREATURE_AGENT, 1,
		CREATURE_RADIOPERSONALITY, 1,
		CREATURE_NEWSANCHOR, 1,
		CREATURE_MILITARYOFFICER, 1,
		CREATURE_LAWYER, 1,
		CREATURE_DOCTOR, 1,
		CREATURE_PSYCHOLOGIST, 1,
		CREATURE_NURSE, 1,
		CREATURE_SEWERWORKER, 1,
		CREATURE_COLLEGESTUDENT, 1,
		CREATURE_MUSICIAN, 1,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_TEACHER, 1,
		CREATURE_HSDROPOUT, 10,
		CREATURE_BUM, 10,
		CREATURE_GANGMEMBER, 10,
		CREATURE_CRACKHEAD, 10,
		CREATURE_PRIEST, 5,
		CREATURE_ENGINEER, 1,
		CREATURE_FASTFOODWORKER, 1,
		CREATURE_BAKER, 1,
		CREATURE_BARISTA, 1,
		CREATURE_BARTENDER, 1,
		CREATURE_TELEMARKETER, 1,
		CREATURE_CARSALESMAN, 1,
		CREATURE_OFFICEWORKER, 1,
		CREATURE_FOOTBALLCOACH, 1,
		CREATURE_PROSTITUTE, 10,
		CREATURE_MAILMAN, 1,
		CREATURE_GARBAGEMAN, 1,
		CREATURE_PLUMBER, 1,
		CREATURE_CHEF, 1,
		CREATURE_CONSTRUCTIONWORKER, 1,
		CREATURE_AMATEURMAGICIAN, 1,
		CREATURE_HICK, 1,
		CREATURE_SOLDIER, 1,
		CREATURE_VETERAN, 2,
		CREATURE_HIPPIE, 1,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_SOCIALITE, 1,
		CREATURE_BIKER, 5,
		CREATURE_TRUCKER, 1,
		CREATURE_TAXIDRIVER, 1,
		CREATURE_PROGRAMMER, 1,
		CREATURE_NUN, 1,
		CREATURE_RETIREE, 1,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_CAMERAMAN, 1,
		CREATURE_HAIRSTYLIST, 1,
		CREATURE_FASHIONDESIGNER, 1,
		CREATURE_CLERK, 1,
		CREATURE_THIEF, 10,
		CREATURE_ACTOR, 1,
		CREATURE_YOGAINSTRUCTOR, 1,
		CREATURE_MARTIALARTIST, 1,
		CREATURE_ATHLETE, 1,
		//CREATURE_FIREFIGHTER]+=1,
		CREATURE_LOCKSMITH, 5 }       //Forensic locksmiths
		),
		map<int, vector<int> >::value_type(SITE_GOVERNMENT_COURTHOUSE,{
		CREATURE_SCIENTIST_LABTECH, 1,
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_CORPORATE_MANAGER, 1,
		CREATURE_WORKER_JANITOR, 50,
		CREATURE_WORKER_SECRETARY, 50,
		CREATURE_TEENAGER, 1,
		CREATURE_JUDGE_LIBERAL, 20,
		CREATURE_JUDGE_CONSERVATIVE, 20,
		CREATURE_AGENT, 1,
		CREATURE_RADIOPERSONALITY, 1,
		CREATURE_NEWSANCHOR, 1,
		CREATURE_MILITARYOFFICER, 1,
		CREATURE_LAWYER, 200,
		CREATURE_PSYCHOLOGIST, 20,
		CREATURE_SEWERWORKER, 1,
		CREATURE_COLLEGESTUDENT, 1,
		CREATURE_MUSICIAN, 1,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_TEACHER, 1,
		CREATURE_HSDROPOUT, 1,
		CREATURE_BUM, 1,
		CREATURE_GANGMEMBER, 1,
		CREATURE_CRACKHEAD, 1,
		CREATURE_PRIEST, 1,
		CREATURE_ENGINEER, 1,
		CREATURE_FASTFOODWORKER, 1,
		CREATURE_BAKER, 1,
		CREATURE_BARISTA, 1,
		CREATURE_BARTENDER, 1,
		CREATURE_TELEMARKETER, 1,
		CREATURE_CARSALESMAN, 2,
		CREATURE_OFFICEWORKER, 50,
		CREATURE_FOOTBALLCOACH, 1,
		CREATURE_PROSTITUTE, 1,
		CREATURE_MAILMAN, 1,
		CREATURE_GARBAGEMAN, 1,
		CREATURE_PLUMBER, 1,
		CREATURE_CHEF, 1,
		CREATURE_CONSTRUCTIONWORKER, 1,
		CREATURE_AMATEURMAGICIAN, 1,
		CREATURE_HICK, 1,
		CREATURE_SOLDIER, 1,
		CREATURE_VETERAN, 2,
		CREATURE_HIPPIE, 1,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_SOCIALITE, 1,
		CREATURE_BIKER, 1,
		CREATURE_TRUCKER, 1,
		CREATURE_TAXIDRIVER, 1,
		CREATURE_PROGRAMMER, 1,
		CREATURE_NUN, 1,
		CREATURE_RETIREE, 1,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_CAMERAMAN, 1,
		CREATURE_HAIRSTYLIST, 1,
		CREATURE_FASHIONDESIGNER, 1,
		CREATURE_CLERK, 1,
		CREATURE_THIEF, 3,
		CREATURE_ACTOR, 1,
		CREATURE_YOGAINSTRUCTOR, 1,
		CREATURE_MARTIALARTIST, 1,
		CREATURE_ATHLETE, 1,
		//CREATURE_FIREFIGHTER]+=1,
		CREATURE_LOCKSMITH, 5 }
		),
		map<int, vector<int> >::value_type(SITE_GOVERNMENT_FIRESTATION,{
		CREATURE_WORKER_JANITOR, 5,
		CREATURE_WORKER_SECRETARY, 2,
		CREATURE_NURSE, 2,
		CREATURE_PRIEST, 5,
		CREATURE_JOURNALIST, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_FIREFIGHTER, 100 }
		),
		map<int, vector<int> >::value_type(SITE_GOVERNMENT_INTELLIGENCEHQ,{
		CREATURE_WORKER_JANITOR, 50,
		CREATURE_WORKER_SECRETARY, 50,
		CREATURE_GUARDDOG, 50,
		CREATURE_MATHEMATICIAN, 5,
		CREATURE_PROGRAMMER, 5,
		CREATURE_MILITARYOFFICER, 5 }


		),
		map<int, vector<int> >::value_type(SITE_GOVERNMENT_ARMYBASE,{
		CREATURE_SOLDIER, 750,
		CREATURE_GUARDDOG, 20,
		CREATURE_MILITARYPOLICE, 100,
		CREATURE_MILITARYOFFICER, 20,
		CREATURE_SEAL, 20 }


		),
		map<int, vector<int> >::value_type(SITE_INDUSTRY_SWEATSHOP,{
		CREATURE_CORPORATE_MANAGER, 5,
		CREATURE_WORKER_SWEATSHOP, 800 }

		),
		map<int, vector<int> >::value_type(SITE_INDUSTRY_POLLUTER,{
		CREATURE_CORPORATE_MANAGER, 1,
		CREATURE_WORKER_JANITOR, 10,
		CREATURE_WORKER_SECRETARY, 10 }
		),
		map<int, vector<int> >::value_type(SITE_CORPORATE_HEADQUARTERS,{

		CREATURE_CORPORATE_MANAGER, 20,
		CREATURE_WORKER_JANITOR, 20,
		CREATURE_WORKER_SECRETARY, 40,
		CREATURE_JUDGE_CONSERVATIVE, 1,
		CREATURE_LAWYER, 20,
		CREATURE_PRIEST, 1,
		CREATURE_OFFICEWORKER, 80,
		CREATURE_PROSTITUTE, 1 }


		),
		map<int, vector<int> >::value_type(SITE_CORPORATE_HOUSE,{
		CREATURE_WORKER_SERVANT, 30,
		CREATURE_WORKER_SECRETARY, 5,
		CREATURE_TEENAGER, 5,
		CREATURE_GENETIC, 1,
		CREATURE_LAWYER, 5,
		CREATURE_PRIEST, 1,
		CREATURE_PROSTITUTE, 1 }

		),
		map<int, vector<int> >::value_type(SITE_MEDIA_AMRADIO,{
		CREATURE_CORPORATE_MANAGER, 2,
		CREATURE_WORKER_JANITOR, 10,
		CREATURE_WORKER_SECRETARY, 10,
		CREATURE_RADIOPERSONALITY, 2,
		CREATURE_ENGINEER, 20,
		CREATURE_OFFICEWORKER, 40 }


		),
		map<int, vector<int> >::value_type(SITE_MEDIA_CABLENEWS,{
		CREATURE_CORPORATE_MANAGER, 5,
		CREATURE_WORKER_JANITOR, 20,
		CREATURE_WORKER_SECRETARY, 20,
		CREATURE_NEWSANCHOR, 2,
		CREATURE_ENGINEER, 40,
		CREATURE_OFFICEWORKER, 40,
		CREATURE_PHOTOGRAPHER, 5,
		CREATURE_CAMERAMAN, 5 }

		)
	};
	extern short mode;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short lawList[LAWNUM];
	extern short mode;
	extern coordinatest loc_coord;
	extern short lawList[LAWNUM];
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern coordinatest loc_coord;
	extern short lawList[LAWNUM];
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short siteonfire;
	extern short sitetype;
	extern short lawList[LAWNUM];
	short getCurrentSite();
	bool populateEncounter(const int type, int creaturearray[CREATURENUM], const char sec);
	void conservatiseEncslot(const int encslot);
	extern short mode;
	extern coordinatest loc_coord;
	extern short postalarmtimer;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	void conservatise(const int c);
	void damage_creature(const int e);
	vector<NameAndAlignment> getEncounterNameAndAlignment();
	extern short sitetype;
	extern short lawList[LAWNUM];
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";

#endif	//NEWENCOUNTER_CPP
#ifdef	NEWGAME_CPP
// newgame.cpp

#include "../creature/creature.h"
#include "../locations/locations.h"

#include "../common/ledgerEnums.h"
#include "../common/ledger.h"

#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"

//#include "../common/consolesupport.h"
// for getkey

#include "../log/log.h"

#include "../common/stringconversion.h"
//for string attribute_enum_to_string(int)

#include "../common/getnames.h"
// for cityname

#include "../common/translateid.h"
// for  getarmortype

#include "../cursesAlternative.h"
#include "../set_color_support.h"

#include "../common/creaturePoolCreature.h"

#include "../common/musicClass.h"



	vector<string> founderQuestions;

#include "../customMaps.h"
	vector<file_and_text_collection> newgame_file_collection = {
		/*newgame.cpp*/
		customText(&founderQuestions, "newgame\\founderQuestions.txt"),
	};
	map<string, short> getSkillEnumFromString;
	map<short, string> enumToCreature;
	map<string, short> getBaseEnumFromString;
	map<string, short> getSpecialWoundEnumFromString;
	extern short wincondition;
	extern short fieldskillrate;
	extern char endgamestate;
	extern bool stalinmode;
	extern bool multipleCityMode;
	extern MusicClass music;
	extern Log gamelog;
	extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	extern int year;
	extern bool multipleCityMode;
	extern char lcityname[CITY_NAMELEN];

	Vehicle* newSportsCar();

	enum LOOP_CONTINUATION {
		RETURN_ZERO,
		RETURN_ONE,
		REPEAT
	};

	//extern string spaceDashSpace;

	extern UniqueCreatures uniqueCreatures;
	//extern string singleSpace;
	void newVehicle(Vehicle *startcar);
	//extern string singleDot;
	extern bool stalinmode;
	extern bool multipleCityMode;
	extern bool ALLOWSTALIN;
	extern bool notermlimit;           //These determine if ELAs can take place --kviiri
	extern bool nocourtpurge;

	extern short lawList[LAWNUM];
	extern short house[HOUSENUM];
	extern short senate[SENATENUM];
	extern short court[COURTNUM];
	extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
	extern short attitude[VIEWNUM];
	enum Stat_Or_Attribute {
		SKILL,
		ATTRIBUTE,
		OTHER
	};
	enum Other_Influence {
		BIRTH_MONTH,
		BIRTH_DAY,
		BIRTH_YEAR,
		STARTING_MONTH,
		STARTING_DAY,
		STARTING_YEAR,
		GAY,
		DATING_LAWYER,
		DATING,
		HAS_MAPS,
		JUICE,
		SPORTS_CAR,
		ASSAULT_RIFLE,
		MONEY,
		BASE,
		CREATURE,
		ARMOR,
		RECRUITS
	};
	struct Impact {
		Stat_Or_Attribute type;
		int item_to_influcence;
		int magnitude;
		bool set_value;
	};
	struct Choice {
		string ANSWER;
		string ANSWER_2;
		vector<Impact> impact;
	};
	struct Question {
		string HEADER;
		string HEADER_2;
		string QUESTION;
		string QUESTION_2;
		vector<Choice> choices;
	};
	enum founderQuestionTagEnums {
		ENUM_tag_HEADER,
		ENUM_tag_ANSWER,
		ENUM_tag_QUESTION,
		ENUM_tag_SKILL_,
		ENUM_tag_ATTRIBUTE_,
		ENUM_tag_STARTING_,
		ENUM_tag_BIRTHDAY_,
		ENUM_tag_MONEY,
		ENUM_tag_DATING_LAWYER,
		ENUM_tag_GAY,
		ENUM_tag_HASMAPS,
		ENUM_tag_CREATURE,
		ENUM_tag_BASE,
		ENUM_tag_ARMOR,
		ENUM_tag_JUICE,
		ENUM_tag_RECRUITS_GANG,
		ENUM_tag_ASSAULT_RIFLE,
		ENUM_tag_SPORTS_CAR,
	};
	
	const int MAX_CHOICES = 10;
	// Make the founder blind
	extern bool BLIND;
	// Make the founder unable to walk
	extern bool NOWALK;
	// Make the founder have no face
	extern bool NOFACE;
	// Make the founder have a severely injured spine
	extern bool SPINE;
	// Make the founder have severe internal damage
	extern bool INTERNAL;

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
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern UniqueCreatures uniqueCreatures;
	extern Log gamelog;
	extern int year;
	extern int day;
	extern int month;
	extern class Ledger ledger;
	const string whatIsYourName = "What is your name to the People?";
	const string pressEnterToBeRealName = "Press enter to be known by your real name instead.";
	const string allOptions = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const string pressBtoBeReborn = " (Press B to be born to a different family)";
	const string pressCtoChangeSex = " (Press C to change your sex at birth)";
	const string history = "HISTORY: ";
	const string letMeChoose = "Let Me Choose";
	const string letFateDecide = "Let Fate Decide";
	const string pressDtoToggle = " (Press D to toggle childhood)";
	const string pressEtoRelocate = " (Press E to relocate)";
	const string sexIs = "SEX: ";
	const string male = "Male";
	const string female = "Female";
	const string itsComplicated = "It's Complicated";
	const string theFounder = "The Founder of the Liberal Crime Squad";
	const string firstName = "FIRST NAME: ";
	const string pressAtoReconsider = " (Press A to have your parents reconsider)";
	const string lastName = "LAST NAME: ";
	const string theDocSaid = "The doctor said I was ";
	const string aBoy = "a boy";
	const string aGirl = "a girl";
	const string intersex = "an intersex baby";
	const string myParents = "My parents ";
	const string insistedOtherwise = "insisted otherwise.";
	const string they = "They ";
	const string namedMe = "named me ";
	const string aNewConEra = "A NEW CONSERVATIVE ERA";
	const string theYearIs = "The Year is ";
	const string conservativePresident = "Conservative President ";
	const string endsSecondTerm = " ends his second term with approval";
	const string highSeventiesApprovePres = "ratings in the high 70s, and is succeeded by hardcore Arch-Conservative";
	const string conMajorityHouse = "With Conservatives sweeping into power in the House of Representatives";
	const string senateConMajority = "and Senate, and a Conservative majority in the Supreme Court of the";
	const string beginningOfNew = "United States, commentators are hailing it as the beginning of a new";
	const string conEra = "Conservative era.";
	const string thePresident = "President ";
	const string hasAskedCongressBeQuick = " has asked the new Congress to move quickly";
	const string rubberStampArchCon = "to rubber stamp his radical Arch-Conservative agenda. ";
	const string theLeftSeems = "The left seems";
	const string powerlessToStop = "powerless to stop this imminent trampling of Liberal Sanity and Justice.";
	const string inThisDarkTime = "In this dark time, the Liberal Crime Squad is born...";
	const string unSelected = "[ ]";
	const string isSelected = "[X]";
	const string newGameAdvanced = "New Game of Liberal Crime Squad: Advanced Gameplay Options";
	const string a_classicMode = " A - Classic Mode: No Conservative Crime Squad.";
	const string b_weDidntStartIt = " B - We Didn't Start The Fire: The CCS starts active and extremely strong.";
	const string c_nightmareMode = " C - Nightmare Mode: Liberalism is forgotten. Is it too late to fight back?";
	const string d_nationalLCS = " D - National LCS: Advanced play across multiple cities.";
	const string e_marathonMode = " E - Marathon Mode: Prevent Liberals from amending the Constitution.";
	const string f_stalinistMode = " F - Stalinist Mode: Enable Stalinist Comrade Squad (not fully implemented).";
	const string newGameYourAgenda = "New Game of Liberal Crime Squad: Your Agenda";
	const string a_noComprimise = " A - No Compromise Classic - I will make all our laws Elite Liberal!";
	const string b_democrat = " B - Democrat Mode - Most laws must be Elite Liberal, some can be Liberal.";
	const string newGameFieldLearn = "New Game of Liberal Crime Squad: Field Learning";
	const string affectsTheseSkills = "(affects Security, Stealth, Disguise, & Driving)";
	const string a_fastSkills = " A - Fast skills - Grinding is Conservative!";
	const string b_classic = " B - Classic - Excellence requires practice.";
	const string c_hardMode = " C - Hard Mode - Learn from the best, or face arrest!";
	const string notCreature = "Not a creature";
	const string notValidMap = "Not a valid mappable site";
	const string notSpecialWound = "Not a special wound";
	const string notASkill = "Not a skill";
	const string notAnAttribute = "Not an attribute";
	const string error = "ERROR";
	const string tag_CLIP = "CLIP";
	const string tag_CLIP_ASSAULT = "CLIP_ASSAULT";
	const string tag_WEAPON = "WEAPON";
	const string tag_WEAPON_AUTORIFLE_AK47 = "WEAPON_AUTORIFLE_AK47";
	const string tag_SPORTS_CAR = "SPORTS_CAR";
	const string tag_ASSAULT_RIFLE = "ASSAULT_RIFLE";
	const string tag_RECRUITS_GANG = "RECRUITS_GANG";
	const string tag_JUICE = "JUICE";
	const string tag_ARMOR = "ARMOR";
	const string tag_B = "B";
	const string tag_BASE = "BASE";
	const string tag_CREATURE = "CREATURE";
	const string tag_HASMAPS = "HASMAPS";
	const string tag_GAY = "GAY";
	const string tag_D = "D";
	const string tag_DATING_LAWYER = "DATING_LAWYER";
	const string tag_MONEY = "MONEY";
	const string tag_YEAR = "YEAR";
	const string tag_Y = "Y";
	const string tag_DAY = "DAY";
	const string tag_MONTH = "MONTH";
	const string tag_BIRTHDAY_ = "BIRTHDAY_";
	const string tag_STARTING_ = "STARTING_";
	const string tag_ATTRIBUTE_ = "ATTRIBUTE_";
	const string tag_SKILL_ = "SKILL_";
	const string tag__2 = "_2";
	const string tag_QUESTION = "QUESTION";
	const string tag_ANSWER = "ANSWER";
	const string tag_HEADER = "HEADER";
	const string tag_ARMOR_CLOTHES = "ARMOR_CLOTHES";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";
	map<string, int> founderQuestionTags = {
		map<string, int>::value_type(tag_HEADER, ENUM_tag_HEADER),
		map<string, int>::value_type(tag_ANSWER, ENUM_tag_ANSWER),
		map<string, int>::value_type(tag_QUESTION, ENUM_tag_QUESTION),
		map<string, int>::value_type(tag_SKILL_, ENUM_tag_SKILL_),
		map<string, int>::value_type(tag_ATTRIBUTE_, ENUM_tag_ATTRIBUTE_),
		map<string, int>::value_type(tag_STARTING_, ENUM_tag_STARTING_),
		map<string, int>::value_type(tag_BIRTHDAY_, ENUM_tag_BIRTHDAY_),
		map<string, int>::value_type(tag_MONEY, ENUM_tag_MONEY),
		map<string, int>::value_type(tag_DATING_LAWYER, ENUM_tag_DATING_LAWYER),
		map<string, int>::value_type(tag_GAY, ENUM_tag_GAY),
		map<string, int>::value_type(tag_HASMAPS, ENUM_tag_HASMAPS),
		map<string, int>::value_type(tag_CREATURE, ENUM_tag_CREATURE),
		map<string, int>::value_type(tag_BASE, ENUM_tag_BASE),
		map<string, int>::value_type(tag_ARMOR, ENUM_tag_ARMOR),
		map<string, int>::value_type(tag_JUICE, ENUM_tag_JUICE),
		map<string, int>::value_type(tag_RECRUITS_GANG, ENUM_tag_RECRUITS_GANG),
		map<string, int>::value_type(tag_ASSAULT_RIFLE, ENUM_tag_ASSAULT_RIFLE),
		map<string, int>::value_type(tag_SPORTS_CAR, ENUM_tag_SPORTS_CAR),
	};
#endif	//NEWGAME_CPP
#ifdef	NEWS_CPP
// news.cpp

#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"
//#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../common/commonactions.h"
//#include "../common/stringconversion.h"
	inline char* strcpy(char* dest, const std::string& src) { return strcpy(dest, src.c_str()); }
	inline char* strcat(char* dest, const std::string& src) { return strcat(dest, src.c_str()); }
	inline char* strcat(char* dest, long src) { return strcat(dest, tostring(src)); }
#include "../common/getnames.h"
#include "../common/misc.h"
	// from cursesgraphics.h
#define CH_BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL 0xc5
#define CH_FULL_BLOCK 0xdb
#define CH_LIGHT_SHADE 0xb0
#define CH_MEDIUM_SHADE 0xb1
#define CH_DARK_SHADE 0xb2
// from daily.h
	int monthday();
#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include "../common/creaturePool.h"
#include "../locations/locationsPool.h"
#include "../cursesmovie.h"
	//extern string singleSpace;
	vector<Deprecatednewsstoryst *> newsstory;
	Deprecatednewsstoryst* lastNewsStory() {
		return newsstory[len(newsstory) - 1];
	}
#include "../common/musicClass.h"
	extern char endgamestate;
	map<short, vector<string> > newsStories;
	map<short, string> cityNames;
	vector<string> liberalCrime;
	vector<string> AMorPM;
	vector<string> book_title;
	vector<string> book_title_2;
	vector<string> random_nationality;
	vector<string> conservative_oppose_book;
	vector<string> radio_name;
	vector<string> radio_name_2;
	vector<string> vigilante_murder;
	vector<string> why_chase_ended;
	vector<string> crazy_conservative_act;
	vector<string> bribe_officers;
	vector<string> my_idol;
	vector<string> prison_book_title;
	vector<string> prison_book_title_2;
	vector<string> mutilated_corpse;
	vector<string> evidence_of_child_murder;
	vector<string> break_in_murder_case;
	vector<string> animal_research_country;
	vector<string> drug_name;
	vector<string> drug_name_2;
	vector<string> chimp_drug_impact;
	vector<string> chimp_drug_horror;
	vector<string> terrorist_group;
	vector<string> terrorist_plot;
	vector<string> terrorist_plot_no_free_speech;
	vector<string> gene_corp_name;
	vector<string> gene_corp_name_2;
	vector<string> gene_product_name;
	vector<string> gene_product_name_2;
	vector<string> gene_product_benefit;
	vector<string> gene_product_cost;
	vector<string> bullshit_no_free_speech;
	vector<string> bullshit;
	vector<string> petty_violence;
	vector<string> his_her;
	vector<string> older_younger;
	vector<string> brother_sister;
	vector<string> judge_with_prostitute;
	vector<string> judge_with_prostitute_no_free_speech;
	vector<string> judge_with_prostitute_full_free_speech;
	vector<string> radio_host_crazy_quote;
	vector<string> radio_host_lost_mind;
	vector<string> family_values_company_name;
	vector<string> family_values_company_name_2;
	vector<string> family_values_company_name_3;
	vector<string> pollution_consumption;
	vector<string> pollution_consumption_2;
	vector<string> i_like_polution;
	vector<string> distrust_liberals;
	vector<string> tech_giant_name;
	vector<string> tech_giant_name_2;
	vector<string> fm_radio_name;
	vector<string> fm_radio_name_2;
	vector<string> public_place;
	vector<string> reagan_bad;
	vector<string> reagan_bad_2;
	vector<string> ceo_behaving_badly;
	vector<string> reagan_good;
	vector<string> reagan_good_2;
	vector<string> cable_name;
	vector<string> cable_name_2;
	vector<string> cable_city;
	vector<string> cable_city_2;
	vector<string> ccs_adjective;
	vector<string> ccs_adjective_2;
	vector<string> ccs_adjective_3;
	vector<string> ccs_noun;
	vector<string> personalAds;
	vector<string> personalAdsLG;
	vector<string> caseNEWSSTORY_CCS_DEFEATED;
	vector<string> caseNEWSSTORY_CCS_NOBACKERS;
	vector<vector<string> > adListB;
	vector<vector<string> > adList;
	const int AD_LENGTH = 4;
#include "../customMaps.h"
	
	void displaynewspicture(int p, int y);
	void displaycenterednewsfont(const std::string& str, int y);
	void preparepage(const Deprecatednewsstoryst ns, const bool liberalguardian);

	extern char endgamestate;
	extern CCSexposure ccsexposure;
	extern short lawList[LAWNUM];
	extern short house[HOUSENUM];
	extern short senate[SENATENUM];
	extern CCSexposure ccsexposure;
	extern short lawList[LAWNUM];
	extern short public_interest[VIEWNUM];
	const vector<int> randombox = {
		CH_LIGHT_SHADE,
		CH_MEDIUM_SHADE,
		CH_DARK_SHADE,
		CH_FULL_BLOCK,
		CH_BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL,
		'*'
	};
	string sexdesc();
	string sexwho();
	string sexseek();
	string sextype();

	string constructeventstory(const short view, const char positive);

	const int PICTURE_MUTANT_BEAST = 0;
	const int PICTURE_CEO = 1;
	const int PICTURE_BOOK = 2;
	const int PICTURE_MELTDOWN = 3;
	const int PICTURE_GENETICS = 4;
	const int PICTURE_RIVERFIRE = 5;
	const int PICTURE_DOLLARS = 6;
	const int PICTURE_TINKYWINKY = 7;
	const int PICTURE_OIL = 8;
	const int PICTURE_TERRORISTS = 9;
	const int PICTURE_KKK = 10;
	const int PICTURE_TSHIRT = 11;
	extern CursesMoviest movie;
	extern MusicClass music;

	const string membersOfLCS = "Members of the Liberal Crime Squad ";
	const string lcsSpokeseperson = "to a Liberal Crime Squad spokesperson.";
	const string policeSpokesperson = "to a spokesperson from the police department.";
	const string accordingToSourcesAtScene = "  According to sources that were at the scene, ";
	const string accordingToPoliceSources = "  According to police sources that were at the scene, ";
	const string CONST_newsX01 = "a spokesperson stated, \"";
	const string CONST_newsX02 = "heard saying, \"";
	const string CONST_newsX03 = "two nights ago during the syndicated radio program \"";
	const string CONST_newsX04 = "had come to expect, with attacks on the \"liberal media establishment\"";
	const string CONST_newsX05 = "the \"elite liberal agenda\".  But when the radio icon said, \"";
	const string CONST_newsX06 = ", knew that \"";
	const string CONST_newsX07 = ".  After that, it just got worse and worse.\"";
	const string CONST_newsX08 = "   The spokesperson further stated, \"";
	const string CONST_newsX09 = "screamed \"fuck the police those goddamn motherfuckers.  I got a fucking ticket this morning and I'm fucking pissed as shit.\"";
	const string CONST_newsX10 = "  The slogan, \"";
	const string CONST_newsX11 = "  One uttered the words, \"";
	const string CONST_newsX12 = "  As they left, they shouted, \"";
	const string CONST_newsX13 = "  One of them was rumored to have cried out, \"";
	const string CONST_newsX14 = "  Witnesses reported hearing the phrase, \"";
	const string CONST_newsX15 = "According to one person familiar with the case, \"";

	const string CONST_newsB955 = ".\"";
	const string CONST_newsB948 = "Reagan was wrong";
	const string CONST_newsB947 = "rb";
	const string CONST_newsB944 = "neo-pagan";
	const string CONST_newsB943 = "him";
	const string CONST_newsB942 = "Bloods";
	const string CONST_newsB941 = "himself";
	const string CONST_newsB940 = "he ";
	const string CONST_newsB939 = "Miss ";
	const string CONST_newsB937 = "If I were to be released, I would surely kill again.\"";
	const string CONST_newsB935 = "he";
	const string CONST_newsB928 = "\"Make things right with the Almighty Father.\"";
	const string CONST_newsB925 = "husband";

	const string CONST_news999 = "burned unrecognizable.  ";
	const string CONST_news998 = "The recovered body was ";
	const string CONST_news997 = "The recovered bodies were ";
	const string CONST_news996 = "They have to be stopped before they kill again";
	const string CONST_news995 = "This is the doing of the Conservative Crime Squad butchers.  ";
	const string CONST_news994 = "no names, no faces, not even where it happened really";
	const string CONST_news993 = "Look, it was a Conservative Crime Squad hit, that's all we know, ";
	const string CONST_news992 = "just covering it up";
	const string CONST_news991 = "with in the past.  *When* the police can't figure this one out, they're ";
	const string CONST_news990 = "known to work with several corporations we've had confrontations ";
	const string CONST_news989 = "This massacre has the signature mark of a group of mercenaries ";
	const string CONST_news988 = "It was execution style.  Professional.  We've got nothing";
	const string CONST_news987 = "inspired by the Conservative media's brainwashing propaganda";
	const string CONST_news986 = "We have reason to believe that this brutal massacre was ";
	const string CONST_news985 = "been bite marks.  Nothing recognizable left.  Complete carnage.";
	const string CONST_news984 = "Burned...  stabbed with, maybe, pitchforks.  There may have ";
	const string CONST_news983 = "intelligence community";
	const string CONST_news982 = "previous actions to uncover human rights abuses and corruption in the ";
	const string CONST_news981 = "carried out by the Central Intelligence Agency in retaliation for our ";
	const string CONST_news980 = "We have strong evidence that this was an extra-judicial slaughter ";
	const string CONST_news979 = "D*mnd*st thing I've ever seen";
	const string CONST_news978 = "Damnedest thing I've ever seen";
	const string CONST_news977 = "[Craziest] thing I've ever seen";
	const string CONST_news976 = "fingerprints.  Like, it was all smooth.  ";
	const string CONST_news975 = "The body had no face or ";
	const string CONST_news974 = "The bodies had no faces or ";
	const string CONST_news973 = "According to an LCS spokesperson, \"";
	const string CONST_news972 = "of the LCS targeted simply due to their political beliefs.  ";
	const string CONST_news971 = "victim was a member ";
	const string CONST_news970 = "victims were members ";
	const string CONST_news969 = "  The Liberal Crime Squad has claimed that the ";
	const string CONST_news968 = "unwilling to pursue the case with any serious effort.";
	const string CONST_news967 = "  The police have opened an investigation into the massacre, but seem ";
	const string CONST_news965 = "  Privately, sources in the department confide that there aren't any leads.  ";
	const string CONST_news964 = "the police department, the matter is under investigation as a homicide.";
	const string CONST_news963 = "  According to a spokesperson for ";
	const string CONST_news962 = " yesterday.";
	const string CONST_news961 = " found in the ";
	const string CONST_news960 = " A body was ";
	const string CONST_news959 = " Two bodies were ";
	const string CONST_news958 = " bodies were ";
	const string CONST_news957 = "MASSACRE";
	const string CONST_news955 = "MYSTERIOUS";
	const string CONST_news954 = "CCS MASSACRE";
	const string CONST_news947 = "\" before passing out.";
	const string CONST_news945 = "\" was found painted on the walls.";
	const string CONST_news943 = "The Liberal Crime Squad ended the dangerous high-speed chase in order to protect the public, and attempted to escape on foot.  ";
	const string CONST_news942 = "There was also a foot chase when the suspect or suspects bailed out after the high-speed pursuit.  ";
	const string CONST_news941 = "Details about injuries were not released.  ";
	const string CONST_news940 = "One vehicle crashed.  ";
	const string CONST_news939 = " vehicles crashed.  ";
	const string CONST_news938 = "pursuit of the LCS.  ";
	const string CONST_news937 = "  Conservative operatives engaged in a reckless ";
	const string CONST_news936 = "following the incident.  ";
	const string CONST_news935 = "  It is known that there was a high-speed chase ";
	const string CONST_news934 = "picked locks";
	const string CONST_news933 = "unlawful entry";
	const string CONST_news932 = "broke down doors";
	const string CONST_news931 = "breaking and entering";
	const string CONST_news930 = "marked the site for Liberation";
	const string CONST_news929 = "vandalism";
	const string CONST_news928 = "damaged enemy infrastructure";
	const string CONST_news927 = "destruction of private property";
	const string CONST_news926 = "liberated abused animals";
	const string CONST_news925 = "tampering with lab animals";
	const string CONST_news924 = "liberated enemy resources";
	const string CONST_news923 = "theft";
	const string CONST_news922 = "engaged in combat with Conservative forces";
	const string CONST_news921 = "violence";
	const string CONST_news920 = "more violence";
	const string CONST_news918 = "murder";
	const string CONST_news917 = "set fire to Conservative property";
	const string CONST_news916 = "arson";
	const string CONST_news915 = "engaged in ";
	const string CONST_news914 = "  Further details are sketchy, but police sources suggest that the CCS ";
	const string CONST_news913 = "  The Liberal Crime Squad ";
	const string CONST_news911 = "  Further details are sketchy, but police sources suggest that the LCS ";
	const string CONST_news910 = "  The Liberal Crime Squad was attempting to uncover the company's Conservative corruption.";
	const string CONST_news909 = "executives on the scene seemed very nervous about something.";
	const string CONST_news908 = "  The Liberal Crime Squad was attempting to uncover the CEO's Conservative corruption.";
	const string CONST_news907 = "the owner of the house seemed very frantic about some missing property.";
	const string CONST_news906 = "  Liberal Crime Squad infiltration specialists worked to liberate weapons from the oppressors.";
	const string CONST_news905 = "the Liberal Crime Squad attempted to break into the armory.";
	const string CONST_news903 = "  Liberal Crime Squad computer specialists worked to liberate information from CIA computers.";
	const string CONST_news902 = "intelligence officials seemed very nervous about something.";
	const string CONST_news901 = "may have interfered with jury deliberations.";
	const string CONST_news900 = "  The Liberal Crime Squad has apologized over reports that the operation ";
	const string CONST_news899 = "trust and attempted to influence a jury.";
	const string CONST_news898 = "the Liberal Crime Squad allegedly violated the sacred ";
	const string CONST_news897 = "at the prison.";
	const string CONST_news896 = "  The Liberal Crime Squad attempted to rescue innocent people from the abusive Conservative conditions ";
	const string CONST_news895 = "the Liberal Crime Squad allegedly freed prisoners while in the facility.";
	const string CONST_news894 = "saving them from the highly corrupt Conservative justice system.";
	const string CONST_news893 = "  The Liberal Crime Squad attempted to rescue innocent people from the courthouse lockup, ";
	const string CONST_news892 = "the Liberal Crime Squad allegedly freed or attempted to free prisoners from the courthouse lockup.";
	const string CONST_news891 = "hoping to acquire the resources to overcome evil.";
	const string CONST_news890 = "  The Liberal Crime Squad demanded access to the bank vault, ";
	const string CONST_news889 = "the Liberal Crime Squad threatened innocent bystanders in order to rob the bank vault.";
	const string CONST_news888 = "showing the triumph of Liberal ideals over Conservative economics.";
	const string CONST_news887 = "  The Liberal Crime Squad opened the bank vault, ";
	const string CONST_news886 = "the Liberal Crime Squad opened the bank vault, which held more than $100,000 at the time.";
	const string CONST_news885 = "saving them from torture and brutality at the hands of Conservative police interrogators.";
	const string CONST_news884 = "  The Liberal Crime Squad attempted to rescue innocent people from the police lockup, ";
	const string CONST_news883 = "the Liberal Crime Squad allegedly freed or attempted to free prisoners from the police lockup.";
	const string CONST_news882 = "demonstrating the extreme vulnerability and danger of Nuclear Power Plants. ";
	const string CONST_news881 = "  The Liberal Crime Squad brought the reactor to the verge of a nuclear meltdown, ";
	const string CONST_news880 = "reactor.";
	const string CONST_news879 = "the Liberal Crime Squad nearly caused a catastrophic meltdown of the nuclear ";
	const string CONST_news878 = "demonstrating the extreme dangers of Nuclear Waste. ";
	const string CONST_news877 = "  The Liberal Crime Squad tampered with the state's water supply yesterday, ";
	const string CONST_news876 = "yesterday by tampering with equipment on the site.";
	const string CONST_news875 = "the Liberal Crime Squad contaminated the state's water supply";
	const string CONST_news874 = "The name of the officer has not been released pending notification of the officer's family.";
	const string CONST_news873 = "The names of the officers have not been released pending notification of their families.";
	const string CONST_news872 = "A passerby had allegedly spotted the suspect committing a car theft.  ";
	const string CONST_news871 = "appeared to be a corpse through an empty lot.  ";
	const string CONST_news870 = "A passerby allegedly called the authorities after seeing the suspect dragging what ";
	const string CONST_news869 = "The suspect was allegedly selling \"pot brownies\".  ";
	const string CONST_news868 = "The incident apparently occurred as a response to a public nudity complaint.  ";
	const string CONST_news867 = " attempting to perform an arrest.  ";
	const string CONST_news866 = "a police officer that was";
	const string CONST_news865 = " police officers that were";
	const string CONST_news864 = "killed ";
	const string CONST_news863 = "  A suspect, whose identity is unclear, ";
	const string CONST_news862 = "according to a spokesperson from the police department.";
	const string CONST_news861 = "A routine arrest went horribly wrong yesterday, ";
	const string CONST_news859 = " while they were attempting to perform an arrest.  ";
	const string CONST_news858 = "the police officer ";
	const string CONST_news857 = " officers ";
	const string CONST_news856 = "radical political group known as the Liberal Crime Squad, is believed to have killed ";
	const string CONST_news855 = "  A suspect, identified only as a member of the ";
	const string CONST_news853 = " killed in the line of duty yesterday, ";
	const string CONST_news852 = "A police officer was";
	const string CONST_news851 = " police officers were";
	const string CONST_news850 = "Several";
	const string CONST_news849 = "Two";
	const string CONST_news848 = "OF CULTURE";
	const string CONST_news847 = "THE DEATH";
	const string CONST_news846 = "NEW JOBS";
	const string CONST_news845 = "LOOKING UP";
	const string CONST_news844 = "Fall fashions are previewed in stores across the country.";
	const string CONST_news843 = "Fall fashions hit the stores across the country.";
	const string CONST_news842 = "THEY ARE HERE";
	const string CONST_news841 = "JUSTICE AMOK";
	const string CONST_news840 = "GM FOOD FAIRE";
	const string CONST_news839 = "Free speech advocates fight hard to let a white supremacist rally take place.";
	const string CONST_news838 = "HATE RALLY";
	const string CONST_news837 = "DODGED BULLET";
	const string CONST_news836 = "HOSTAGE SLAIN";
	const string CONST_news835 = "BASTARDS";
	const string CONST_news834 = "[JERKS]";
	const string CONST_news833 = "APE EXPLORERS";
	const string CONST_news832 = "OPEC cuts oil production sharply in response to a US foreign policy decision.";
	const string CONST_news831 = "OIL CRUNCH";
	const string CONST_news830 = ": A new book lauding Reagan and the greatest generation.";
	const string CONST_news829 = "REAGAN THE MAN";
	const string CONST_news828 = "SAVES LIVES";
	const string CONST_news827 = "ARMED CITIZEN";
	const string CONST_news826 = "END IN TEARS";
	const string CONST_news825 = "Our boys defend freedom once again, defeating an evil dictator.";
	const string CONST_news824 = "BIG VICTORY";
	const string CONST_news823 = "LET'S FRY 'EM";
	const string CONST_news822 = "Jerry Falwell explains the truth about Tinky Winky.  Again.";
	const string CONST_news821 = "KINKY WINKY";
	const string CONST_news820 = "AM IMPLOSION";
	const string CONST_news819 = "regularly visits prostitutes.";
	const string CONST_news818 = "regularly [donates to sperm banks].";
	const string CONST_news817 = "regularly visits [working women].";
	const string CONST_news816 = "This major CEO ";
	const string CONST_news815 = "AMERICAN CEO";
	const string CONST_news814 = "An enormous company files for bankruptcy, shattering the previous record.";
	const string CONST_news813 = "BELLY UP";
	const string CONST_news812 = "The Ohio River caught on fire again.";
	const string CONST_news811 = "RING OF FIRE";
	const string CONST_news810 = "A T-shirt in a store is found scrawled with a message from a sweatshop worker.";
	const string CONST_news809 = "CHILD'S PLEA";
	const string CONST_news808 = "IN CONTEMPT";
	const string CONST_news807 = "Over a hundred people become sick from genetically modified food.";
	const string CONST_news806 = "KILLER FOOD";
	const string CONST_news805 = "BOOK BANNED";
	const string CONST_news804 = "THE FBI FILES";
	const string CONST_news803 = "ON THE INSIDE";
	const string CONST_news802 = "A mutant animal has escaped from a lab and killed thirty people.";
	const string CONST_news801 = "HELL ON EARTH";
	const string CONST_news800 = "A nuclear power plant suffers a catastrophic meltdown.";
	const string CONST_news799 = "MELTDOWN";
	const string CONST_news798 = ": A new book further documenting the other side of Reagan.";
	const string CONST_news797 = "REAGAN FLAWED";
	const string CONST_news796 = "MASS SHOOTING";
	const string CONST_news795 = "NIGHTMARE";
	const string CONST_news794 = "Is the latest military invasion yet another quagmire?";
	const string CONST_news793 = "CASUALTIES MOUNT";
	const string CONST_news792 = "JUSTICE DEAD";
	const string CONST_news791 = "CRIME OF HATE";
	const string CONST_news790 = "CLINIC MURDER";
	const string CONST_news789 = "newspic.cpc";
	const string CONST_news788 = "newstops.cpc";
	const string CONST_news787 = "largecap.cpc";
	const string CONST_news786 = "SQUAD RAMPAGE";
	const string CONST_news785 = "LIBERAL CRIME";
	const string CONST_news784 = "LCS SORRY";
	const string CONST_news783 = "LCS RAMPAGE";
	const string CONST_news782 = "SQUAD STRIKES";
	const string CONST_news780 = "LCS STRIKES";
	const string CONST_news779 = "HEROIC STRIKE";
	const string CONST_news778 = "LCS HITS TV";
	const string CONST_news777 = "LCS HITS AM";
	const string CONST_news776 = "LCS HITS CORP";
	const string CONST_news775 = "POLLUTER HIT";
	const string CONST_news774 = "NO JUSTICE";
	const string CONST_news773 = "EVIL RESEARCH";
	const string CONST_news772 = "LCS VS CIA";
	const string CONST_news771 = "PRISON WAR";
	const string CONST_news770 = "LCS VS COPS";
	const string CONST_news769 = "MELTDOWN RISK";
	const string CONST_news768 = "CLASS WAR";
	const string CONST_news766 = "UNSTOPPABLE";
	const string CONST_news765 = "CCS RAMPAGE";
	const string CONST_news764 = "CCS STRIKES";
	const string CONST_news763 = "CRIME SQUAD";
	const string CONST_news762 = "LCS MARTYRS";
	const string CONST_news761 = "POLICE KILL";
	const string CONST_news760 = "TRAGIC END";
	const string CONST_news759 = "LCS SIEGE";
	const string CONST_news758 = "OFF COPS";
	const string CONST_news757 = "LCS FIGHTS";
	const string CONST_news756 = "POLICE SIEGE";
	const string CONST_news755 = "LCS ESCAPES";
	const string CONST_news754 = "POLICE KILLED";
	const string CONST_news753 = "RAIDS END CCS";
	const string CONST_news752 = "FBI HUNTS CCS";
	const string CONST_news751 = "ASSASSINATED";
	const string CONST_news750 = "MISSING";
	const string CONST_news748 = "RESCUED";
	const string CONST_news747 = "FOUND DEAD";
	const string CONST_news746 = "BELIEVED DEAD";
	const string CONST_news745 = "IMPEACHED";
	const string CONST_news744 = "훤袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴暠";
	const string CONST_news743 = "�   audience and viewers nationwide feel its pain.   �";
	const string CONST_news742 = "�   popular  afternoon  talk  show.    The  studio   �";
	const string CONST_news741 = "�     A  failed partial  birth abortion  goes on a   �";
	const string CONST_news740 = "�袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴�";
	const string CONST_news739 = "abort.cmv";
	const string CONST_news737 = "�   by impressive  advertising, America  tunes in.   �";
	const string CONST_news736 = "�   new anchor for  one of its news shows.  Guided   �";
	const string CONST_news735 = "�     A major Cable News channel has hired a slick   �";
	const string CONST_news733 = "anchor.cmv";
	const string CONST_news731 = "�   advertising  blitz, it's bound  to be popular.   �";
	const string CONST_news730 = "�   begins airing  this week.  With the nationwide   �";
	const string CONST_news729 = "�     A new show glamorizing the lives of the rich   �";
	const string CONST_news727 = "glamshow.cmv";
	const string CONST_news725 = "�   viewers  across  the  nation  were  listening.   �";
	const string CONST_news724 = "�   bright Liberal guest  finish a sentence.  Many   �";
	const string CONST_news723 = "�     A  Cable  News  anchor  accidentally  let  a   �";
	const string CONST_news721 = "newscast.cmv";
	const string CONST_news720 = " with ";
	const string CONST_news719 = "Tonight on a Cable News channel: ";
	const string CONST_news717 = "�   taped by  a passerby  and saturates  the news.   �";
	const string CONST_news716 = "�   Los Angeles again.  This time, the incident is   �";
	const string CONST_news715 = "�     The  police  have  beaten  a  black  man  in   �";
	const string CONST_news713 = "lacops.cmv";
	const string CONST_news712 = " while \"resisting capture\", according to a prison spokesperson.";
	const string CONST_news711 = "beaten to death";
	const string CONST_news710 = "[also harmed]";
	const string CONST_news709 = ".  The prisoner was ";
	const string CONST_news708 = " altar";
	const string CONST_news707 = "Satanic";
	const string CONST_news706 = "sacrificed the guard on a makeshift ";
	const string CONST_news705 = "performed deadly experiments on the guard unheard of since Dr. Mengele";
	const string CONST_news704 = "eaten the guard's liver with some fava beans and a nice chianti";
	const string CONST_news703 = "burnt the guard to a crisp using a lighter and some gasoline";
	const string CONST_news702 = "tricked another guard into shooting the guard dead";
	const string CONST_news701 = " off";
	const string CONST_news700 = "her";
	const string CONST_news699 = "taken the guard to the execution chamber and finished ";
	const string CONST_news698 = "thrown the guard out the top-storey window";
	const string CONST_news697 = "electrocuted the guard with high-voltage wires";
	const string CONST_news696 = "hit all 36 pressure points of death on the guard";
	const string CONST_news695 = "Crips";
	const string CONST_news694 = "poisoned the guard with drugs smuggled into the prison by the ";
	const string CONST_news693 = " own gun";
	const string CONST_news691 = "shot the guard with ";
	const string CONST_news690 = " cell";
	const string CONST_news688 = "smashed the guard's skull with the toilet seat from ";
	const string CONST_news687 = "chewed out the guard's throat";
	const string CONST_news686 = "strangled the guard to death with a knotted bed sheet";
	const string CONST_news685 = "slit the guard's throat with a shank";
	const string CONST_news684 = "killed the guard";
	const string CONST_news683 = "[harmed] the guard";
	const string CONST_news682 = " had already ";
	const string CONST_news681 = "the hostage, but ";
	const string CONST_news680 = "  The tower was breached in an attempt to reach ";
	const string CONST_news678 = "Imma kill all you b*tches, startin' with this m*th*f*ck*r here.";
	const string CONST_news677 = "[I will harm all police officers], startin' with this [one] here.";
	const string CONST_news676 = "Imma kill all you bitches, startin' with this mothafucker here.";
	const string CONST_news675 = "Why the f*ck am I talkin' to you?  I'd rather kill this pig.";
	const string CONST_news674 = "Why [am I] talkin' to you?  I'd rather [harm this police officer.]";
	const string CONST_news673 = "Why the fuck am I talkin' to you?  I'd rather kill this pig.";
	const string CONST_news672 = "F*ck a m*th*f*ck*n' bull.  I'm killin' this pig sh*t.";
	const string CONST_news671 = "[Too late.]  [I am going to harm this police officer.]";
	const string CONST_news670 = "Fuck a muthafuckin' bull.  I'm killin' this pig shit.";
	const string CONST_news669 = "Ah, f*ck this sh*t.  This punk b*tch is f*ckin' dead!";
	const string CONST_news668 = "Ah, [no way.]  This [police officer will be harmed!]";
	const string CONST_news667 = "Ah, fuck this shit.  This punk bitch is fuckin' dead!";
	const string CONST_news666 = " reportedly screamed into the receiver \"";
	const string CONST_news665 = " days, but talks were cut short when ";
	const string CONST_news664 = "attempted to negotiate by phone for ";
	const string CONST_news663 = "Authorities locked down the prison and ";
	const string CONST_news662 = " with the guard in a prison tower.  ";
	const string CONST_news661 = "herself";
	const string CONST_news660 = " and barricaded ";
	const string CONST_news659 = ", overpowered ";
	const string CONST_news658 = ", an inmate at ";
	const string CONST_news657 = "   Two weeks ago, convicted rapist ";
	const string CONST_news656 = "   Two weeks ago, convicted [reproduction fiend] ";
	const string CONST_news655 = " captor.";
	const string CONST_news653 = "death of both the prison guard being held hostage and ";
	const string CONST_news652 = " Correctional Facility ended tragically yesterday with the ";
	const string CONST_news651 = " - The hostage crisis at the ";
	const string CONST_news650 = "'s heroic actions.\"";
	const string CONST_news649 = " if not for ";
	const string CONST_news648 = "mass shooting";
	const string CONST_news647 = "[hurting spree]";
	const string CONST_news646 = "  The spokesperson for the police department said, \"We'd have a yet another ";
	const string CONST_news645 = "could hurt anyone else.&r";
	const string CONST_news644 = "she ";
	const string CONST_news643 = "before ";
	const string CONST_news642 = "firefight, killing the attacker ";
	const string CONST_news641 = "firefight, [putting the attacker to sleep] ";
	const string CONST_news640 = " became more agitated, the heroic citizen was forced to engage the shooter in a ";
	const string CONST_news639 = " attempted to talk down the shooter, but as ";
	const string CONST_news638 = "Mr. ";
	const string CONST_news637 = "Mrs. ";
	const string CONST_news636 = "Ms. ";
	const string CONST_news635 = "  Initially, ";
	const string CONST_news634 = " to take cover while others called the police.&r";
	const string CONST_news633 = "forcing ";
	const string CONST_news632 = "The citizen pulled a concealed handgun and fired once at the shooter, ";
	const string CONST_news631 = " sprung into action. ";
	const string CONST_news630 = " opened fire at the ";
	const string CONST_news629 = " After ";
	const string CONST_news628 = " was prevented by a bystander with a gun.";
	const string CONST_news626 = " - In a surprising turn, a ";
	const string CONST_news625 = "stated that the incident is under investigation.";
	const string CONST_news624 = " A spokesperson for the FCC ";
	const string CONST_news623 = "within the town. ";
	const string CONST_news622 = "in neighboring towns. ";
	const string CONST_news621 = "within the county. ";
	const string CONST_news620 = "from all over the state. ";
	const string CONST_news619 = "across the nation. ";
	const string CONST_news618 = "from irate listeners ";
	const string CONST_news617 = " complaints ";
	const string CONST_news616 = "some";
	const string CONST_news615 = "dozens of";
	const string CONST_news614 = "hundreds of";
	const string CONST_news613 = "several hundred";
	const string CONST_news612 = "thousands of";
	const string CONST_news611 = "the FCC received ";
	const string CONST_news610 = " later apologized, ";
	const string CONST_news609 = " on the air.  Although ";
	const string CONST_news608 = "masturbated";
	const string CONST_news607 = "[had fun]";
	const string CONST_news606 = "breastfed from a lactating woman";
	const string CONST_news605 = "[fed] from a [woman]";
	const string CONST_news604 = "breastfed from an exposed woman";
	const string CONST_news603 = "[fed] from [an indecent] woman";
	const string CONST_news602 = "screamed \"f*ck the police those g*dd*mn m*th*f*ck*rs.  I got a f*cking ticket this morning and I'm f*cking p*ss*d as sh*t.\"";
	const string CONST_news601 = "screamed \"[darn] the police those [big dumb jerks]. I got a [stupid] ticket this morning and I'm [so angry].\"";
	const string CONST_news599 = "encouraged listeners to call in and relieve themselves";
	const string CONST_news598 = "encouraged listeners to call in and take a piss";
	const string CONST_news597 = "encouraged listeners to call in and [urinate]";
	const string CONST_news596 = "had intercourse";
	const string CONST_news595 = "fucked";
	const string CONST_news594 = "[had consensual intercourse in the missionary position]";
	const string CONST_news593 = " reportedly ";
	const string CONST_news592 = "\", ";
	const string CONST_news591 = "'s ";
	const string CONST_news590 = "broadcast of the program \"";
	const string CONST_news589 = " has brought radio entertainment to a new low.  During yesterday's ";
	const string CONST_news588 = " - Infamous FM radio shock jock ";
	const string CONST_news587 = "of the tech industry but is also indicative of a full economic recover.&r";
	const string CONST_news586 = "analysts suggest that not only does the expansion speak to the health ";
	const string CONST_news585 = "futures of some of the companies in the tech sector.  On the whole, however, ";
	const string CONST_news584 = "although the dampened movement might be expected due to the uncertain ";
	const string CONST_news583 = "The markets reportedly responded to the announcement with mild interest, ";
	const string CONST_news582 = "this welcome news is bound to be a pleasant surprise to those in the unemployment lines.  ";
	const string CONST_news581 = "of large corporations to export jobs overseas these days, ";
	const string CONST_news580 = "light of the tendency ";
	const string CONST_news579 = "Given the state of the economy recently and in ";
	const string CONST_news578 = " increasing its payrolls by over ten thousand workers alone.  ";
	const string CONST_news577 = "tech giant ";
	const string CONST_news576 = "are expected in the first month, with ";
	const string CONST_news575 = "during the next quarter.  Over thirty thousand jobs ";
	const string CONST_news574 = "will be expanding their work forces considerably ";
	const string CONST_news573 = "at a joint news conference here that they ";
	const string CONST_news572 = " - Several major companies have announced ";
	const string CONST_news571 = "needs to take a breather on this one.  We don't see why there's such a rush to judgment here.  ";
	const string CONST_news570 = "before we urge any action.  Society really just ";
	const string CONST_news569 = "there's work left to be done.  We should study much more ";
	const string CONST_news568 = "Why is there contention on the pollution question?  It's because ";
	const string CONST_news567 = "All we've done is introduced a little clarity into the ongoing debate.  ";
	const string CONST_news566 = " these issues to their own advantage.  ";
	const string CONST_news565 = ".  You have to realize that ";
	const string CONST_news564 = "a spokesperson stated that, \"";
	const string CONST_news563 = "   When questioned about the science behind these results, ";
	const string CONST_news562 = " might actually ";
	const string CONST_news561 = "Among the most startling of the think tank's findings is that ";
	const string CONST_news560 = "and the latest science on the issue.  ";
	const string CONST_news559 = " recently released a wide-ranging report detailing recent trends ";
	const string CONST_news558 = " - Pollution might not be so bad after all.  The ";
	const string CONST_news557 = "completely strapped for cash.&r";
	const string CONST_news556 = "to the current economic doldrums that have left the state ";
	const string CONST_news555 = "has stated that the case will not be retried, due ";
	const string CONST_news554 = "   A spokesperson for the district attorney ";
	const string CONST_news552 = "Thank you for saving me from myself.  ";
	const string CONST_news551 = " confessed and was sentenced to life, saying \"";
	const string CONST_news550 = "covered in the victims' blood.  ";
	const string CONST_news549 = " was found with the murder weapon, ";
	const string CONST_news548 = "After an intensive manhunt, ";
	const string CONST_news547 = " slayings.  ";
	const string CONST_news546 = " was convicted of the now-infamous ";
	const string CONST_news545 = "   Ten years ago, ";
	const string CONST_news544 = " grants was not coerced in any way.&r";
	const string CONST_news543 = ", which even Justice ";
	const string CONST_news542 = ", despite the confession of ";
	const string CONST_news541 = " consultations with a Magic 8-Ball";
	const string CONST_news540 = " family";
	const string CONST_news539 = " close personal friendship with the ";
	const string CONST_news538 = " personal philosophy of liberty";
	const string CONST_news537 = " deserved another chance";
	const string CONST_news536 = " belief that ";
	const string CONST_news535 = " belief that the crimes were a vast right-wing conspiracy";
	const string CONST_news534 = " general feeling about police corruption";
	const string CONST_news533 = "ten-year-old eyewitness testimony";
	const string CONST_news531 = "made the decision based on ";
	const string CONST_news530 = " of the notoriously liberal circuit of appeals here ";
	const string CONST_news529 = "Justice ";
	const string CONST_news528 = " was overturned by a federal judge yesterday.  ";
	const string CONST_news527 = " - The conviction of confessed serial killer ";
	const string CONST_news525 = "but the GM industry operates at a higher ethical standard.  That goes without saying.";
	const string CONST_news524 = "No.  That's just ridiculous.  I mean, sure companies have put unsafe products out, ";
	const string CONST_news523 = ".  Would we stake the reputation of our company on unsafe products?  ";
	const string CONST_news522 = " is just a load of ";
	const string CONST_news521 = "Look, these products are safe.  That thing about the ";
	const string CONST_news520 = "One in particular said, \"";
	const string CONST_news519 = "in their dismissal of the criticism which often follows the industry.  ";
	const string CONST_news518 = "   Spokespeople for the GM corporations were universal ";
	const string CONST_news517 = "this amazing new product actually ";
	const string CONST_news516 = "According to the public relations representative speaking, ";
	const string CONST_news515 = "\", during an afternoon PowerPoint presentation.  ";
	const string CONST_news514 = ", presented their product, \"";
	const string CONST_news513 = "   One such corporation, ";
	const string CONST_news512 = "booths and gave talks to wide-eyed onlookers.";
	const string CONST_news511 = "to showcase its upcoming products.  Over thirty companies set up ";
	const string CONST_news510 = " - The genetic foods industry staged a major event here yesterday ";
	const string CONST_news508 = "this new age.";
	const string CONST_news507 = "for what we feel are the essential tools for combating terrorism in ";
	const string CONST_news506 = "The Head of the Agency will be sending a request to Congress ";
	const string CONST_news505 = "However, let me also say that there's more that needs to be done.  ";
	const string CONST_news504 = "civilization before they can destroy American families.  ";
	const string CONST_news503 = "providing us with the tools we need to neutralize these enemies of ";
	const string CONST_news502 = "that we are grateful to the Congress and this Administration for ";
	const string CONST_news501 = "I won't compromise our sources and methods, but let me just say ";
	const string CONST_news499 = "was to occur.";
	const string CONST_news498 = "terrorist organization allowed the plot to be foiled just days before it ";
	const string CONST_news497 = ".  However, intelligence garnered from deep within the mysterious ";
	const string CONST_news496 = " planned to ";
	const string CONST_news495 = "   According to a spokesperson for the agency, ";
	const string CONST_news494 = "would have occurred on American soil.";
	const string CONST_news493 = "Washington, DC - The CIA announced yesterday that it has averted a terror attack that ";
	const string CONST_news492 = "   The first phase of human trials is slated to begin in a few months.";
	const string CONST_news490 = "I think the media should be focusing on the enormous benefits of this drug.";
	const string CONST_news489 = "While we understand your concerns, any worries are entirely unfounded.  ";
	const string CONST_news488 = ".  We have a very experienced research team.  ";
	const string CONST_news487 = "a spokesperson for the research team stated that, \"It really isn't so bad as all that.  Chimpanzees are very resilient creatures.  ";
	const string CONST_news486 = "Fielding questions about the ethics of their experiments from reporters during a press conference yesterday, ";
	const string CONST_news485 = ".  ";
	const string CONST_news484 = "   Along with bonobos, chimpanzees are our closest cousins";
	const string CONST_news482 = "corrects erectile dysfunction in chimpanzees";
	const string CONST_news481 = "[helps chimpanzees reproduce]";
	const string CONST_news480 = ", the drug apparently ";
	const string CONST_news479 = "Anal";
	const string CONST_news478 = "Bum-Bum";
	const string CONST_news477 = "Called ";
	const string CONST_news476 = "here report that they have discovered an amazing new wonder drug.  ";
	const string CONST_news475 = " report that they have discovered an amazing new wonder drug. ";
	const string CONST_news474 = "from ";
	const string CONST_news473 = " - Researchers ";
	const string CONST_news472 = "the death penalty in this case.";
	const string CONST_news471 = "life imprisonment in this case.";
	const string CONST_news470 = "seeking ";
	const string CONST_news469 = "   The district attorney's office has already repeatedly said it will be ";
	const string CONST_news468 = ".  Sources say that the police got a break in the case when ";
	const string CONST_news467 = " dead and ";
	const string CONST_news466 = " [in a better place]";
	const string CONST_news465 = "only to turn up later";
	const string CONST_news464 = ".  Over twenty children in the past two years have gone missing, ";
	const string CONST_news463 = " was detained yesterday afternoon, reportedly in possession of ";
	const string CONST_news462 = "according to a spokesperson for the police department here.  ";
	const string CONST_news461 = "string of brutal child killings that has kept everyone in the area on edge, ";
	const string CONST_news460 = "The authorities have apprehended their primary suspect in the ";
	const string CONST_news459 = " - Perhaps parents can rest easier tonight.  ";
	const string CONST_news458 = ".\"";
	const string CONST_news457 = " choice, and I would only have a few seconds before they made it for me";
	const string CONST_news456 = "helluva";
	const string CONST_news455 = "[difficult]";
	const string CONST_news454 = " the other.  A ";
	const string CONST_news453 = "AIDS";
	const string CONST_news452 = "GRIDS";
	const string CONST_news451 = "Maybe lose an eye the one way, maybe catch ";
	const string CONST_news450 = "My shank's under the mattress.  Better to be brave and fight or chicken out and let them take it?  ";
	const string CONST_news449 = "with dark glares of bare lust, as football players might stare at a stupefied, drunken, helpless teenager.  ";
	const string CONST_news448 = "I was trapped with them now.  There were three, looking me over ";
	const string CONST_news447 = "coming to a halt with a deafening clang that said it all 컴 ";
	const string CONST_news446 = "The steel bars grated forward in their rails, ";
	const string CONST_news445 = "   Take this excerpt, \"";
	const string CONST_news444 = "_.&r";
	const string CONST_news443 = "Buttlord";
	const string CONST_news442 = "[Bum]lord";
	const string CONST_news441 = "_";
	const string CONST_news440 = "'s new tour-de-force, _";
	const string CONST_news439 = "Orange is the New Black";
	const string CONST_news438 = "have these works been as poignant as ";
	const string CONST_news437 = "prison theme lately in its offerings for mass consumption, rarely ";
	const string CONST_news436 = "Although popular culture has used, or perhaps overused, the ";
	const string CONST_news435 = "detail what goes on behind bars.  ";
	const string CONST_news434 = " - A former prisoner has written a book describing in horrifying ";
	const string CONST_news433 = " was disturbingly obsessed with guns and death.&r";
	const string CONST_news432 = "she";
	const string CONST_news431 = "reports indicate that the student kept a journal that showed ";
	const string CONST_news430 = "  Investigators are currently searching the student's belongings, and initial ";
	const string CONST_news429 = " shortly afterwards.&r";
	const string CONST_news428 = " committed suicide";
	const string CONST_news427 = " [feel deeply asleep]";
	const string CONST_news426 = " and wounded dozens more.  ";
	const string CONST_news424 = "[hurt some people].  ";
	const string CONST_news423 = "  When the police arrived, the student had already ";
	const string CONST_news422 = " as well.&r";
	const string CONST_news421 = "shot";
	const string CONST_news420 = "[unfortunately harmed]";
	const string CONST_news419 = ", they were ";
	const string CONST_news417 = "When other students tried to wrestle the weapons away from ";
	const string CONST_news416 = " students and teachers inside.  ";
	const string CONST_news415 = "spraying bullets at";
	const string CONST_news414 = "[scaring]";
	const string CONST_news413 = "classrooms, ";
	const string CONST_news412 = " while classes were in session, then systematically started breaking into ";
	const string CONST_news411 = "university ";
	const string CONST_news410 = "school ";
	const string CONST_news409 = " entered the ";
	const string CONST_news407 = " University";
	const string CONST_news406 = " High School";
	const string CONST_news405 = " Middle School";
	const string CONST_news404 = " Elementary School";
	const string CONST_news403 = " more than a dozen classmates and two teachers at ";
	const string CONST_news402 = "mow down";
	const string CONST_news401 = "[scare]";
	const string CONST_news400 = ", used a variety of guns to ";
	const string CONST_news398 = "university";
	const string CONST_news397 = "high school";
	const string CONST_news396 = "middle school";
	const string CONST_news395 = "elementary school";
	const string CONST_news394 = " at a local ";
	const string CONST_news393 = "shooting rampage";
	const string CONST_news391 = "A student has gone on a ";
	const string CONST_news390 = "to the FM band.";
	const string CONST_news389 = "pastures.  Of these, many said that they would be switching over ";
	const string CONST_news388 = "have decided to leave the program for saner ";
	const string CONST_news387 = "fully half of the host's most loyal supporters ";
	const string CONST_news386 = "According to a poll completed yesterday, ";
	const string CONST_news385 = "the damage might already be done.  ";
	const string CONST_news384 = " issued an apology later in the program, but ";
	const string CONST_news381 = " g*dd*mn mind";
	const string CONST_news380 = " [gosh darn] mind";
	const string CONST_news379 = " goddamn mind";
	const string CONST_news378 = "his";
	const string CONST_news377 = "lost ";
	const string CONST_news376 = " had ";
	const string CONST_news374 = "\", a former fan of the show, ";
	const string CONST_news373 = "liberal media establishment!";
	const string CONST_news372 = "current president!";
	const string CONST_news371 = "and the greatest living example of a reverse racist is the ";
	const string CONST_news368 = "'s monologue for the evening began the way that fans ";
	const string CONST_news366 = "\".";
	const string CONST_news364 = " went off for fifteen minutes in an inexplicable rant ";
	const string CONST_news363 = " - Well-known AM radio personality ";
	const string CONST_news361 = "the judge would be going on a Bible retreat for a few weeks to ";
	const string CONST_news360 = " could not be reached for comment, although an aid stated that ";
	const string CONST_news358 = " in exchange for their silence.";
	const string CONST_news357 = " reportedly offered ";
	const string CONST_news355 = "when police broke into the hotel room they saw ";
	const string CONST_news354 = "According to sources familiar with the particulars, ";
	const string CONST_news353 = " last week in a hotel during a police sting operation.  ";
	const string CONST_news352 = ", was found with ";
	const string CONST_news351 = ", who once ";
	const string CONST_news349 = " has resigned in disgrace after being caught with a prostitute.";
	const string CONST_news348 = " has resigned in disgrace after being caught with a [civil servant].";
	const string CONST_news347 = " - Conservative federal judge ";
	const string CONST_news345 = "?";
	const string CONST_news344 = "Mamma, why did they kill ";
	const string CONST_news343 = " dead?";
	const string CONST_news342 = "Mamma, is ";
	const string CONST_news340 = "many area children spontaneously broke into tears.  One child was ";
	const string CONST_news339 = "   When the decision to ban the book was announced yesterday, ";
	const string CONST_news338 = " as key evidence of the dark nature of the book.";
	const string CONST_news337 = "a child that ";
	const string CONST_news336 = "a child that said a magic spell at her parents";
	const string CONST_news335 = "a child that swore in class";
	const string CONST_news334 = "In their complaint, the groups cited an incident involving ";
	const string CONST_news332 = "some conservatives feel that the books ";
	const string CONST_news331 = "Although the series is adored by children worldwide, ";
	const string CONST_news329 = ". ";
	const string CONST_news328 = " author ";
	const string CONST_news327 = "_, is the third in an immensely popular series by ";
	const string CONST_news325 = "_and_the_";
	const string CONST_news322 = "   The book, ";
	const string CONST_news321 = "the city bowed to pressure from religious groups.";
	const string CONST_news320 = " - A children's story has been removed from libraries here after ";
	const string CONST_news318 = "You think about that before you continue slanging accusations";
	const string CONST_news317 = "these files deal with the one and not the other.  ";
	const string CONST_news316 = "It might be a bit presumptive to assume that ";
	const string CONST_news315 = "Well, you know, there's privacy, and there's privacy.  ";
	const string CONST_news313 = "  The FBI refused to comment initially, but when confronted with the information, ";
	const string CONST_news312 = "\"deal with the undesirables\", although this phrase is not clarified.  ";
	const string CONST_news311 = "  More disturbingly, the files make reference to a plan to ";
	const string CONST_news310 = "unions, working for liberal organizations 컴 even ";
	const string CONST_news309 = "The files contain information on which people have been attending demonstrations, organizing ";
	const string CONST_news308 = "This newspaper yesterday received a collection of files from a source in the Federal Bureau of Investigations.  ";
	const string CONST_news307 = "Washington, DC - The FBI might be keeping tabs on you.  ";
	const string CONST_news306 = "can be put to death in this country.";
	const string CONST_news305 = "tragedy, it will be that our nation is now evaluating the ease with which people ";
	const string CONST_news304 = "and more events are expected this evening.  If there is a bright side to be found from this ";
	const string CONST_news303 = "  Candlelight vigils were held throughout the country last night during the execution, ";
	const string CONST_news301 = "The family wants closure.  We don't have time for another trial";
	const string CONST_news300 = "End of story";
	const string CONST_news299 = "Assassin, serial killer, either way 컴 guilty.  ";
	const string CONST_news298 = "The convict is always referred to by three names.  ";
	const string CONST_news297 = "Let's not forget the convict is colored.  You know how their kind are";
	const string CONST_news295 = "spokesperson for the governor saying, ";
	const string CONST_news294 = "The state still went through with the execution, with a ";
	const string CONST_news293 = " was framed.  ";
	const string CONST_news292 = "an admission from a former prosecutor that ";
	const string CONST_news291 = "a battery of negative DNA tests.  ";
	const string CONST_news290 = "a confession from another convict.  ";
	const string CONST_news289 = "have been produced, including ";
	const string CONST_news288 = "Since then, numerous pieces of exculpatory evidence ";
	const string CONST_news287 = " of 13 serial murders.  ";
	const string CONST_news286 = " was convicted in ";
	const string CONST_news284 = " Correctional Facility.&r";
	const string CONST_news283 = " yesterday at the ";
	const string CONST_news282 = ":";
	const string CONST_news281 = " was pronounced dead at ";
	const string CONST_news280 = " - An innocent citizen has been put to death in the electric chair.  ";
	const string CONST_news279 = ", even though being gay is deviant, as we all know.";
	const string CONST_news278 = " is a known faggot";
	const string CONST_news277 = ", despite the fact that ";
	const string CONST_news276 = "aggravated nature of the offense";
	const string CONST_news275 = "prosecute this case as a hate crime, due to the ";
	const string CONST_news274 = "  Authorities have stated that they will vigorously ";
	const string CONST_news273 = "at which point they were taken into custody.  Nobody was seriously injured during the incident.";
	const string CONST_news272 = "The chase ended when ";
	const string CONST_news271 = " at the pursuing police cruisers.  ";
	const string CONST_news270 = "taking swipes";
	const string CONST_news269 = "urinating out the window";
	const string CONST_news268 = "pissing out the window";
	const string CONST_news267 = "[relieving themselves] out the window";
	const string CONST_news266 = "throwing beer bottles";
	const string CONST_news265 = "throwing [juice boxes]";
	const string CONST_news264 = "murderers swerving wildly, ";
	const string CONST_news263 = "  Witnesses of the freeway chase described the pickup of the alleged ";
	const string CONST_news262 = "have not yet been released.";
	const string CONST_news261 = "were apprehended after a high speed chase.  Their names ";
	const string CONST_news260 = "A police spokesperson reported that four suspects ";
	const string CONST_news259 = " here yesterday.  ";
	const string CONST_news258 = "a homosexual, was ";
	const string CONST_news257 = "a known homosexual, was ";
	const string CONST_news256 = "a known sexual deviant, was ";
	const string CONST_news255 = " children.&r";
	const string CONST_news254 = "five";
	const string CONST_news253 = "four";
	const string CONST_news252 = "three";
	const string CONST_news251 = "two";
	const string CONST_news250 = " and ";
	const string CONST_news249 = "wife";
	const string CONST_news248 = " is survived by ";
	const string CONST_news246 = "had been completed.&r";
	const string CONST_news245 = " surrendered without a struggle, reportedly saying that God's work ";
	const string CONST_news244 = " abortion doctors as opposed to arresting them.&r";
	const string CONST_news243 = " later admitted to being a rogue FBI vigilante, hunting down ";
	const string CONST_news242 = "called the police on a cellphone and they arrived shortly thereafter.  ";
	const string CONST_news241 = "verses of the Bible at the stunned onlookers.  Someone ";
	const string CONST_news240 = " remained at the scene after the shooting, screaming ";
	const string CONST_news239 = "  Witnesses report that ";
	const string CONST_news238 = ", is in custody.&r";
	const string CONST_news237 = "The suspected shooter, ";
	const string CONST_news236 = " times and died immediately in the parking lot.  ";
	const string CONST_news235 = " was hit ";
	const string CONST_news234 = "shots were fired from a nearby vehicle.  ";
	const string CONST_news233 = " car when, according to police reports, ";
	const string CONST_news232 = " was walking to ";
	const string CONST_news230 = "Dr. ";
	const string CONST_news229 = " Clinic yesterday.  ";
	const string CONST_news228 = "gunned down outside of the ";
	const string CONST_news227 = "A doctor that routinely performed abortions was ruthlessly ";
	const string CONST_news226 = "A doctor that routinely performed semi-legal abortions was ruthlessly ";
	const string CONST_news225 = "A doctor that routinely performed illegal abortions was ruthlessly ";
	const string CONST_news224 = "A doctor that routinely performed illegal abortion-murders was ruthlessly ";
	const string CONST_news222 = "~";
	const string CONST_news221 = "&r";
	const string CONST_news220 = "Fortunately, the CCS thugs were stopped by brave citizens.  ";
	const string CONST_news219 = "Everyone in the CCS group was arrested or killed.  ";
	const string CONST_news218 = "Fortunately, the LCS thugs were stopped by brave citizens.  ";
	const string CONST_news217 = "Everyone in the LCS group was arrested or killed.  ";
	const string CONST_news216 = "Unfortunately, the LCS group was defeated by the forces of evil.  ";
	const string CONST_news214 = "A Liberal Crime Squad operation went horribly wrong, and came to a tragic end.  ";
	const string CONST_news213 = "The Liberal Crime Squad has gone on a rampage, and they got what they deserved.  ";
	const string CONST_news211 = "The Liberal Crime Squad has struck again, albeit with a tragic end.  ";
	const string CONST_news209 = "to a spokesperson from the police department.  ";
	const string CONST_news208 = "went on a suicidal rampage yesterday, according ";
	const string CONST_news207 = "A group of thugs calling itself the Liberal Crime Squad ";
	const string CONST_news204 = "burst briefly onto the scene of political activism yesterday, according ";
	const string CONST_news203 = "A group calling itself the Liberal Crime Squad ";
	const string CONST_news201 = "The Conservative Crime Squad has gone on another rampage, and they got what they deserved.  ";
	const string CONST_news199 = "The Conservative Crime Squad has struck again, albeit with a tragic end.  ";
	const string CONST_news197 = "rampage yesterday, according to a spokesperson from the police department.  ";
	const string CONST_news196 = "calling themselves the Conservative Crime Squad went on a ";
	const string CONST_news195 = "M16-toting ";
	const string CONST_news194 = "A group of ";
	const string CONST_news190 = "A group of M16-wielding vigilantes calling themselves the Conservative Crime Squad ";
	const string CONST_news188 = "The Conservative Crime Squad has gone on another rampage.  ";
	const string CONST_news186 = "The Conservative Crime Squad has struck again.  ";
	const string CONST_news185 = "to a spokesperson from the police department.";
	const string CONST_news184 = "went on a rampage yesterday, according ";
	const string CONST_news183 = "A group of worthless M16-toting hicks calling itself the Conservative Crime Squad ";
	const string CONST_news180 = "burst onto the scene of political activism yesterday, according ";
	const string CONST_news179 = "A group of M16-wielding vigilantes calling itself the Conservative Crime Squad ";
	const string CONST_news177 = "A Liberal Crime Squad operation went horribly wrong.  ";
	const string CONST_news176 = "The Liberal Crime Squad has gone on a rampage.  ";
	const string CONST_news174 = "The Liberal Crime Squad has struck again.  ";
	const string CONST_news164 = ", the very symbol of economic inequality.  ";
	const string CONST_news163 = ", known for its Extreme Conservative Bias.  ";
	const string CONST_news162 = ", a building with enough square footage enough to house a hundred people if it weren't in Conservative Hands.  ";
	const string CONST_news161 = ", where evil and Conservatism coagulate in the hallways.  ";
	const string CONST_news160 = ", also known to be a Conservative storage facility for radioactive waste.  ";
	const string CONST_news159 = ", a factory whose Conservative smokestacks choke the city with deadly pollutants.  ";
	const string CONST_news158 = ", a Conservative sweatshop and human rights abuser.  ";
	const string CONST_news157 = ", pride of Conservative torturers and warmongers everywhere.  ";
	const string CONST_news156 = ", the Conservative headquarters of one of the biggest privacy violators in the world.  ";
	const string CONST_news155 = ", where innocent people are regularly beaten by Conservative guards.  ";
	const string CONST_news154 = ", site of numerous Conservative Injustices.  ";
	const string CONST_news153 = ", headquarters of one of the most oppressive and Conservative police forces in the country.  ";
	const string CONST_news152 = ", a dangerous Conservative genetic research lab.  ";
	const string CONST_news151 = ", a Conservative animal rights abuser.  ";
	const string CONST_news150 = ", a spawning ground of Wrong Conservative Ideas.  ";
	const string CONST_news149 = ", known for its rich and snooty residents.  ";
	const string CONST_news147 = "Richard Dawkins Food Bank.  ";
	const string CONST_news146 = "ACLU Branch Office.  ";
	const string CONST_news145 = "Greenpeace Offices.  ";
	const string CONST_news144 = "Network News Station.  ";
	const string CONST_news143 = "Public Radio Station.  ";
	const string CONST_news142 = "Tax Collection Agency.  ";
	const string CONST_news141 = "Welfare Assistance Agency.  ";
	const string CONST_news140 = "Whirled Peas Museum.  ";
	const string CONST_news138 = "Labor Union HQ.  ";
	const string CONST_news137 = "WikiLeaks HQ.  ";
	const string CONST_news136 = "Rehabilitation Center.  ";
	const string CONST_news135 = "Abortion Clinic.  ";
	const string CONST_news134 = "Seedy Back Alley(tm).  ";
	const string CONST_news133 = "Research Ethics Commission HQ.  ";
	const string CONST_news132 = "Animal Shelter.  ";
	const string CONST_news131 = "Lady Luck Strip Club.  ";
	const string CONST_news130 = "University Dormitory.  ";
	const string CONST_news129 = "notorious ";
	const string CONST_news128 = "at the ";
	const string CONST_news127 = "the notorious ";
	const string CONST_news126 = "at ";
	const string CONST_news121 = "'s";
	const string CONST_news120 = "in the ";
	const string CONST_news119 = "on the ";
	const string CONST_news118 = "in ";
	const string CONST_news115 = "on ";
	const string CONST_news113 = "Orange County";
	const string CONST_news111 = "Travel Agency";
	const string CONST_news109 = "Shopping Mall";
	const string CONST_news107 = "and";
	const string CONST_news106 = "  The events took place ";
	const string CONST_news105 = " w/ ";
	const string CONST_news104 = "Call Today";
	const string CONST_news1033 = ".  Police were seen searching the surrounding area yesterday.";
	const string CONST_news1032 = "'s last known location was the ";
	const string CONST_news1031 = "  According to sources, ";
	const string CONST_news1030 = "\"";
	const string CONST_news103 = " Years Experience";
	const string CONST_news1029 = "To the citizens, please contact the department if you have any additional information.";
	const string CONST_news1028 = "As the investigation is ongoing, I cannot be more specific at this time.  ";
	const string CONST_news1027 = " back home and bring the kidnappers to justice.  ";
	const string CONST_news1026 = "bring ";
	const string CONST_news1025 = "We have several leads and are confident that we will ";
	const string CONST_news1024 = " days ago, by a person or persons as yet undetermined.  ";
	const string CONST_news1023 = " was taken ";
	const string CONST_news1022 = "\"We now believe that ";
	const string CONST_news1021 = ", speaking on behalf of the police department, stated ";
	const string CONST_news1020 = "  ";
	const string CONST_news102 = "Liberal Defense Lawyer";
	const string CONST_news1019 = "according to a police spokesperson.";
	const string CONST_news1018 = " is now considered a kidnapping, ";
	const string CONST_news1017 = " - The disappearance of ";
	const string CONST_news1016 = "KIDNAPPED";
	const string CONST_news1015 = "SOMEONE";
	const string CONST_news1014 = "COP";
	const string CONST_news1013 = "JUDGE";
	const string CONST_news1012 = "SCIENTIST";
	const string CONST_news1011 = "NEWS ANCHOR";
	const string CONST_news1010 = "RADIO HOST";
	const string CONST_news1009 = "KIDNAPPING";
	const string CONST_news1008 = "LCS DENIES";
	const string CONST_news1006 = "This is clearly the work of conservative butchers enforcing the prohibition on a free press";
	const string CONST_news1005 = "working for this very paper. ";
	const string CONST_news1004 = "The murdered was a reporter ";
	const string CONST_news1003 = "The murdered were reporters ";
	const string CONST_news1002 = "Fortunately, firemen were able to respond before the fire could spread to other buildings";
	const string CONST_news1001 = "we are working closely with the Fire Department to track down the arsonist.  ";
	const string CONST_news1000 = "Scorch marks throughout the site indicate that this was no accident; ";
	const string CONST_news100 = "Only $";
	const string CONST_news099 = "Sedan 4D";
	const string CONST_news098 = "Lexus GS 300";
	const string CONST_news097 = "Vehicles&r";
	const string CONST_news096 = "Quality Pre-Owned";
	const string CONST_news095 = "Now $";
	const string CONST_news094 = "Special Purchase";
	const string CONST_news093 = "Fine Leather Chairs";
	const string CONST_news092 = "caseNEWSSTORY_CCS_NOBACKERS.txt";
	const string CONST_news091 = "caseNEWSSTORY_CCS_DEFEATED.txt";
	const string CONST_news090 = "adListB.txt";
	const string CONST_news089 = "adList.txt";
	const string CONST_news088 = "personalAdsLG.txt";
	const string CONST_news087 = "personalAds.txt";
	const string CONST_news086 = "ccs_noun.txt";
	const string CONST_news085 = "ccs_adjective_3.txt";
	const string CONST_news084 = "ccs_adjective_2.txt";
	const string CONST_news083 = "ccs_adjective.txt";
	const string CONST_news082 = "cable_city_2.txt";
	const string CONST_news081 = "cable_city.txt";
	const string CONST_news080 = "cable_name_2.txt";
	const string CONST_news079 = "cable_name.txt";
	const string CONST_news078 = "reagan_good_2.txt";
	const string CONST_news077 = "reagan_good.txt";
	const string CONST_news076 = "ceo_behaving_badly.txt";
	const string CONST_news075 = "reagan_bad_2.txt";
	const string CONST_news074 = "reagan_bad.txt";
	const string CONST_news073 = "public_place.txt";
	const string CONST_news072 = "fm_radio_name_2.txt";
	const string CONST_news071 = "fm_radio_name.txt";
	const string CONST_news070 = "tech_giant_name_2.txt";
	const string CONST_news069 = "tech_giant_name.txt";
	const string CONST_news068 = "distrust_liberals.txt";
	const string CONST_news067 = "i_like_polution.txt";
	const string CONST_news066 = "pollution_consumption_2.txt";
	const string CONST_news065 = "pollution_consumption.txt";
	const string CONST_news064 = "family_values_company_name_3.txt";
	const string CONST_news063 = "family_values_company_name_2.txt";
	const string CONST_news062 = "family_values_company_name.txt";
	const string CONST_news061 = "radio_host_lost_mind.txt";
	const string CONST_news060 = "radio_host_crazy_quote.txt";
	const string CONST_news059 = "judge_with_prostitute_full_free_speech.txt";
	const string CONST_news058 = "judge_with_prostitute_no_free_speech.txt";
	const string CONST_news057 = "judge_with_prostitute.txt";
	const string CONST_news056 = "brother_sister.txt";
	const string CONST_news055 = "older_younger.txt";
	const string CONST_news054 = "his_her.txt";
	const string CONST_news053 = "petty_violence.txt";
	const string CONST_news052 = "bullshit.txt";
	const string CONST_news051 = "bullshit_no_free_speech.txt";
	const string CONST_news050 = "gene_product_cost.txt";
	const string CONST_news049 = "gene_product_benefit.txt";
	const string CONST_news048 = "gene_product_name_2.txt";
	const string CONST_news047 = "gene_product_name.txt";
	const string CONST_news046 = "gene_corp_name_2.txt";
	const string CONST_news045 = "gene_corp_name.txt";
	const string CONST_news044 = "terrorist_plot_no_free_speech.txt";
	const string CONST_news043 = "terrorist_plot.txt";
	const string CONST_news042 = "terrorist_group.txt";
	const string CONST_news041 = "chimp_drug_horror.txt";
	const string CONST_news040 = "chimp_drug_impact.txt";
	const string CONST_news039 = "drug_name_2.txt";
	const string CONST_news038 = "drug_name.txt";
	const string CONST_news037 = "animal_research_country.txt";
	const string CONST_news036 = "break_in_murder_case.txt";
	const string CONST_news035 = "evidence_of_child_murder.txt";
	const string CONST_news034 = "mutilated_corpse.txt";
	const string CONST_news033 = "prison_book_title_2.txt";
	const string CONST_news032 = "prison_book_title.txt";
	const string CONST_news031 = "my_idol.txt";
	const string CONST_news030 = "bribe_officers.txt";
	const string CONST_news029 = "crazy_conservative_act.txt";
	const string CONST_news028 = "why_chase_ended.txt";
	const string CONST_news027 = "vigilante_murder.txt";
	const string CONST_news026 = "radio_name_2.txt";
	const string CONST_news025 = "radio_name.txt";
	const string CONST_news024 = "conservative_oppose_book.txt";
	const string CONST_news023 = "random_nationality.txt";
	const string CONST_news022 = "book_title_2.txt";
	const string CONST_news021 = "book_title.txt";
	const string CONST_news020 = "AMorPM.txt";
	const string CONST_news019 = "liberalCrime.txt";
	const string CONST_news002 = "";

	const string tag_CEO = "CEO";
	const string tag_CONSERVATIVE = "CONSERVATIVE";
	const string tag_D = "D";
	const string tag_Downtown = "Downtown";
	const string tag_National_Mall = "National Mall";
	const string tag_Arlington = "Arlington";
	const string tag_Manhattan = "Manhattan";
	const string tag_Manhattan_Island = "Manhattan Island";
	const string tag_Hollywood = "Hollywood";
	const string tag_Greater_Hollywood = "Greater Hollywood";
	const string tag_Long_Island = "Long Island";
	const string tag_B = "B";
	const string tag_Brooklyn_and_Queens = "Brooklyn and Queens";
	const string tag_Outskirts_and_Orange_County = "Outskirts and Orange County";
	const string tag_Outskirts = "Outskirts";
	const string tag_Travel = "Travel";
	const string tag_Shopping = "Shopping";
	const string tag_The = "The ";
	//	const string CONST_news859 = " while they were attempting to perform an arrest. ";
	//	const string CONST_news858 = "the police officer ";
	//	const string CONST_news857 = " officers ";
	//	const string CONST_news856 = "radical political group known as the Liberal Crime Squad, is believed to have killed ";
	//	const string CONST_news855 = " A suspect, identified only as a member of the ";
	//	const string CONST_news853 = " killed in the line of duty yesterday, ";
	//	const string CONST_news852 = "A police officer was";
	//	const string CONST_news851 = " police officers were";
	//	const string CONST_newsX10 = " The slogan, \"";
	//	const string CONST_newsX11 = " One uttered the words, \"";
	//	const string CONST_newsX12 = " As they left, they shouted, \"";
	//	const string CONST_newsX13 = " One of them was rumored to have cried out, \"";
	//	const string CONST_newsX14 = " Witnesses reported hearing the phrase, \"";
	//	const string CONST_newsX15 = "According to one person familiar with the case, \"";
	const string majorevent = "majorevent\\";
	const string mostlyendings = "mostlyendings\\";

	//nudityCarDrugOrBurial
//	const string CONST_news874 = "The name of the officer has not been released pending notification of the officer's family.";
//	const string CONST_news872 = "A passerby had allegedly spotted the suspect committing a car theft. ";
//	const string CONST_news871 = "appeared to be a corpse through an empty lot. ";
//	const string CONST_news870 = "A passerby allegedly called the authorities after seeing the suspect dragging what ";
//	const string CONST_news869 = "The suspect was allegedly selling \"pot brownies\". ";
//	const string CONST_news868 = "The incident apparently occurred as a response to a public nudity complaint. ";
//	const string CONST_news867 = " attempting to perform an arrest. ";
//	const string CONST_news866 = "a police officer that was";
//	const string CONST_news865 = " police officers that were";
//	const string CONST_news864 = "killed ";
//	const string CONST_news863 = " A suspect, whose identity is unclear, ";
//	const string CONST_news861 = "A routine arrest went horribly wrong yesterday, ";
	vector<string> CONST_Woman_744 = {
		CONST_news740, CONST_news741, CONST_news742, CONST_news743, CONST_news744
	};
	vector<string> CONST_Cable_744 = {
		CONST_news740, CONST_news735, CONST_news736, CONST_news737, CONST_news744
	};
	vector<string> CONST_CEO_744 = {
		CONST_news740, CONST_news729, CONST_news730, CONST_news731, CONST_news744
	};
	vector<string> CONST_Cable_744POS = {
		CONST_news740, CONST_news723, CONST_news724, CONST_news725, CONST_news744
	};
	vector<string> CONST_Police_744 = {
		CONST_news740, CONST_news715, CONST_news716, CONST_news717, CONST_news744
	};

	map<int, string> newsStoryHeadlines = {
		map<int, string>::value_type(VIEW_TAXES,	CONST_news768),
		map<int, string>::value_type(VIEW_SWEATSHOPS,	CONST_news768),
		map<int, string>::value_type(VIEW_CEOSALARY,	CONST_news768),
		map<int, string>::value_type(VIEW_NUCLEARPOWER,	CONST_news769),
		map<int, string>::value_type(VIEW_POLICEBEHAVIOR,	CONST_news770),
		map<int, string>::value_type(VIEW_DEATHPENALTY,	CONST_news771),
		map<int, string>::value_type(VIEW_INTELLIGENCE,	CONST_news772),
		map<int, string>::value_type(VIEW_ANIMALRESEARCH,	CONST_news773),
		map<int, string>::value_type(VIEW_GENETICS,	CONST_news773),
		map<int, string>::value_type(VIEW_FREESPEECH,	CONST_news774),
		map<int, string>::value_type(VIEW_GAY,	CONST_news774),
		map<int, string>::value_type(VIEW_JUSTICES,	CONST_news774),
		map<int, string>::value_type(VIEW_POLLUTION,	CONST_news775),
		map<int, string>::value_type(VIEW_CORPORATECULTURE,	CONST_news776),
		map<int, string>::value_type(VIEW_AMRADIO,	CONST_news777),
		map<int, string>::value_type(VIEW_CABLENEWS,	CONST_news778)
	};
	map<int, string> presidentStories = {
		map<int, string>::value_type(NEWSSTORY_PRESIDENT_IMPEACHED,  CONST_news745),
		map<int, string>::value_type(NEWSSTORY_PRESIDENT_BELIEVED_DEAD,  CONST_news746),
		map<int, string>::value_type(NEWSSTORY_PRESIDENT_FOUND_DEAD, CONST_news747),
		map<int, string>::value_type(NEWSSTORY_PRESIDENT_FOUND,  CONST_news748),
		map<int, string>::value_type(NEWSSTORY_PRESIDENT_KIDNAPPED,  CONST_news1016),
		map<int, string>::value_type(NEWSSTORY_PRESIDENT_MISSING,  CONST_news750),
		map<int, string>::value_type(NEWSSTORY_PRESIDENT_ASSASSINATED,  CONST_news751)
	};
	map<char, vector<Views> > siteViews = {
		map<SiteTypes, vector<Views> >::value_type(SITE_LABORATORY_COSMETICS,
			{
				VIEW_ANIMALRESEARCH,
				VIEW_WOMEN,
			}
			),
		map<SiteTypes, vector<Views> >::value_type(SITE_LABORATORY_GENETIC,
			{
				VIEW_ANIMALRESEARCH,
				VIEW_GENETICS,
			}
			),
		map<SiteTypes, vector<Views> >::value_type(SITE_GOVERNMENT_POLICESTATION,
			{
				VIEW_POLICEBEHAVIOR,
				VIEW_PRISONS,
				VIEW_DRUGS,
			}
			),
		map<SiteTypes, vector<Views> >::value_type(SITE_GOVERNMENT_COURTHOUSE,
			{
				VIEW_DEATHPENALTY,
				VIEW_JUSTICES,
				VIEW_FREESPEECH,
				VIEW_GAY,
				VIEW_WOMEN,
				VIEW_CIVILRIGHTS,
			}
			),
		map<SiteTypes, vector<Views> >::value_type(SITE_GOVERNMENT_PRISON,
			{
				VIEW_DEATHPENALTY,
				VIEW_DRUGS,
				VIEW_TORTURE,
				VIEW_PRISONS,
			}
			),
		map<SiteTypes, vector<Views> >::value_type(SITE_GOVERNMENT_ARMYBASE,
			{
				VIEW_TORTURE,
				VIEW_MILITARY,
			}
			),
		map<SiteTypes, vector<Views> >::value_type(SITE_GOVERNMENT_WHITE_HOUSE,
			{
			}
			),
		map<SiteTypes, vector<Views> >::value_type(SITE_GOVERNMENT_INTELLIGENCEHQ,
			{
				VIEW_INTELLIGENCE,
				VIEW_TORTURE,
				VIEW_PRISONS,
			}
			),
		map<SiteTypes, vector<Views> >::value_type(SITE_INDUSTRY_SWEATSHOP,
			{
				VIEW_SWEATSHOPS,
				VIEW_IMMIGRATION,
			}
			),
		map<SiteTypes, vector<Views> >::value_type(SITE_INDUSTRY_POLLUTER,
			{
				VIEW_SWEATSHOPS,
				VIEW_POLLUTION,
			}
			),
		map<SiteTypes, vector<Views> >::value_type(SITE_INDUSTRY_NUCLEAR,
			{
				VIEW_NUCLEARPOWER,
			}
			),
		map<SiteTypes, vector<Views> >::value_type(SITE_CORPORATE_HEADQUARTERS,
			{
				VIEW_TAXES,
				VIEW_CORPORATECULTURE,
				VIEW_WOMEN,
			}
			),
		map<SiteTypes, vector<Views> >::value_type(SITE_CORPORATE_HOUSE,
			{
				VIEW_TAXES,
				VIEW_CEOSALARY,
			}
			),
		map<SiteTypes, vector<Views> >::value_type(SITE_MEDIA_AMRADIO,
			{
				VIEW_AMRADIO,
				VIEW_FREESPEECH,
				VIEW_GAY,
				VIEW_WOMEN,
				VIEW_CIVILRIGHTS,
			}
			),
		map<SiteTypes, vector<Views> >::value_type(SITE_MEDIA_CABLENEWS,
			{
				VIEW_CABLENEWS,
				VIEW_FREESPEECH,
				VIEW_GAY,
				VIEW_WOMEN,
				VIEW_CIVILRIGHTS,
			}
			),
				map<SiteTypes, vector<Views> >::value_type(SITE_RESIDENTIAL_APARTMENT_UPSCALE,
					{
						VIEW_TAXES,
						VIEW_CEOSALARY,
						VIEW_GUNCONTROL,
					}
					),
				map<SiteTypes, vector<Views> >::value_type(SITE_BUSINESS_CIGARBAR,
					{
						VIEW_TAXES,
						VIEW_CEOSALARY,
						VIEW_WOMEN,
					}
					),
				map<SiteTypes, vector<Views> >::value_type(SITE_BUSINESS_BANK,
					{
						VIEW_TAXES,
						VIEW_CEOSALARY,
						VIEW_CORPORATECULTURE,
					}
					),
	};
	int okay_types[] = { NEWSSTORY_SQUAD_SITE, NEWSSTORY_SQUAD_ESCAPED, NEWSSTORY_SQUAD_FLEDATTACK,
		NEWSSTORY_SQUAD_DEFENDED, NEWSSTORY_SQUAD_BROKESIEGE, NEWSSTORY_SQUAD_KILLED_SIEGEATTACK,
		NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE, NEWSSTORY_SQUAD_KILLED_SITE, NEWSSTORY_WANTEDARREST,
		NEWSSTORY_GRAFFITIARREST, NEWSSTORY_CCS_SITE, NEWSSTORY_CCS_KILLED_SITE };
	extern unsigned char bigletters[27][5][7][4];
	extern unsigned char newstops[6][80][5][4];
	extern unsigned char newspic[20][78][18][4];
	map<short, string> positiveMajorEvents = {
		map<short, string>::value_type(VIEW_WOMEN,
		CONST_news790),

		map<short, string>::value_type(VIEW_GAY,
		CONST_news791),

		map<short, string>::value_type(VIEW_DEATHPENALTY,
		CONST_news792),

		map<short, string>::value_type(VIEW_GUNCONTROL,
		CONST_news796),

		map<short, string>::value_type(VIEW_PRISONS,
		CONST_news803),

		map<short, string>::value_type(VIEW_INTELLIGENCE,
		CONST_news804),

		map<short, string>::value_type(VIEW_FREESPEECH,
		CONST_news805),

		map<short, string>::value_type(VIEW_JUSTICES,
		CONST_news808),

		map<short, string>::value_type(VIEW_AMRADIO,
		CONST_news820),
	};
	struct TwoStringsAndAnInt {
		const string first;
		const string second;
		const int third;
		TwoStringsAndAnInt(string _first, string _second, int _third) : first(_first), second(_second), third(_third) {}
		TwoStringsAndAnInt() : first(""), second(""), third(-1) {}
	};
	map<short, TwoStringsAndAnInt> positiveMajorPictures = {
		map<short, TwoStringsAndAnInt>::value_type(VIEW_NUCLEARPOWER,
		TwoStringsAndAnInt(CONST_news799, CONST_news800, PICTURE_MELTDOWN)),

		map<short, TwoStringsAndAnInt>::value_type(VIEW_ANIMALRESEARCH,
		TwoStringsAndAnInt(CONST_news801, CONST_news802, PICTURE_MUTANT_BEAST)),

		map<short, TwoStringsAndAnInt>::value_type(VIEW_GENETICS,
		TwoStringsAndAnInt(CONST_news806, CONST_news807, PICTURE_GENETICS)),

		map<short, TwoStringsAndAnInt>::value_type(VIEW_SWEATSHOPS,
		TwoStringsAndAnInt(CONST_news809, CONST_news810, PICTURE_TSHIRT)),

		map<short, TwoStringsAndAnInt>::value_type(VIEW_POLLUTION,
		TwoStringsAndAnInt(CONST_news811, CONST_news812, PICTURE_RIVERFIRE)),

		map<short, TwoStringsAndAnInt>::value_type(VIEW_CORPORATECULTURE,
		TwoStringsAndAnInt(CONST_news813, CONST_news814, PICTURE_DOLLARS)),



	};
	map<short, string> negativeMajorEvents = {

		map<short, string>::value_type(VIEW_DEATHPENALTY,
			CONST_news823),

		map<short, string>::value_type(VIEW_ANIMALRESEARCH,
			CONST_news833),

		map<short, string>::value_type(VIEW_PRISONS,
			CONST_news836),

		map<short, string>::value_type(VIEW_INTELLIGENCE,
			CONST_news837),

		map<short, string>::value_type(VIEW_GENETICS,
			CONST_news840),

		map<short, string>::value_type(VIEW_JUSTICES,
			CONST_news841),

		map<short, string>::value_type(VIEW_POLLUTION,
			CONST_news845),

		map<short, string>::value_type(VIEW_CORPORATECULTURE,
			CONST_news846),
	};
	map<short, TwoStringsAndAnInt> negativeMajorPictures = {

		map<short, TwoStringsAndAnInt>::value_type(VIEW_GAY,
			TwoStringsAndAnInt(CONST_news821, CONST_news822, PICTURE_TINKYWINKY)
		),
		map<short, TwoStringsAndAnInt>::value_type(VIEW_NUCLEARPOWER,
			TwoStringsAndAnInt(CONST_news831, CONST_news832, PICTURE_OIL)
		),
		map<short, TwoStringsAndAnInt>::value_type(VIEW_FREESPEECH,
			TwoStringsAndAnInt(CONST_news838, CONST_news839, PICTURE_KKK)
		),



	};
	extern int month;
	extern short lawList[LAWNUM];

	map<int, vector<string> >accordingToLiberalGuardian = {

		map<Crimes, vector<string> >::value_type(CRIME_POLICE_LOCKUP,
			{ CONST_news884 + CONST_news885 , accordingToSourcesAtScene + CONST_news883 }
		),
		map<Crimes,  vector<string> >::value_type(CRIME_BANKVAULTROBBERY,
			{ CONST_news887 + CONST_news888 , accordingToSourcesAtScene + CONST_news886 }
		),
		map<Crimes,  vector<string> >::value_type(CRIME_BANKSTICKUP,
			{ CONST_news890 + CONST_news891 , accordingToSourcesAtScene + CONST_news889 }
		),
		map<Crimes,  vector<string> >::value_type(CRIME_COURTHOUSE_LOCKUP,
			{ CONST_news893 + CONST_news894 , accordingToSourcesAtScene + CONST_news892 }
		),
		map<Crimes,  vector<string> >::value_type(CRIME_PRISON_RELEASE,
			{ CONST_news896 + CONST_news897 , accordingToSourcesAtScene + CONST_news895 }
		),
		map<Crimes,  vector<string> >::value_type(CRIME_JURYTAMPERING,
			{ CONST_news900 + CONST_news901 , accordingToPoliceSources + CONST_news898 + CONST_news899 }
		),
		map<Crimes,  vector<string> >::value_type(CRIME_HACK_INTEL,
			{ CONST_news903 , accordingToPoliceSources + CONST_news902 }
		),
		map<Crimes,  vector<string> >::value_type(CRIME_ARMORY,
			{ CONST_news906 , CONST_news1031 + CONST_news905 }
		),
		map<Crimes,  vector<string> >::value_type(CRIME_HOUSE_PHOTOS,
			{ CONST_news908 , accordingToPoliceSources + CONST_news907 }
		),
		map<Crimes, vector<string> >::value_type(CRIME_CORP_FILES,
			{ CONST_news910 , accordingToPoliceSources + CONST_news909 }
		),
	};
	const vector<Crimes> noteworthyCrimes = {
		CRIME_COURTHOUSE_LOCKUP,
		CRIME_PRISON_RELEASE,
		CRIME_JURYTAMPERING,
		CRIME_HACK_INTEL,
		CRIME_ARMORY,
		CRIME_HOUSE_PHOTOS,
		CRIME_CORP_FILES
	};
	extern short lawList[LAWNUM];
	extern string slogan_str;
	extern short lawList[LAWNUM];
	extern string slogan_str;
	map<int, vector<string> >siegeMassacreStory = {

		map<SiegeTypes,  vector<string> >::value_type(SIEGE_POLICE,

			{
				(CONST_news984)+(CONST_news985),
				(CONST_news986)+(CONST_news987)
			}
		),
		map<SiegeTypes,  vector<string> >::value_type(SIEGE_HICKS,

			{
				(CONST_news984)+
				(CONST_news985)

			,

			(CONST_news986)+
			(CONST_news987)
			}),

		map<SiegeTypes,  vector<string> >::value_type(SIEGE_CORPORATE,

			{
				(CONST_news988)

				,

			(CONST_news989)+
			(CONST_news990)+
			(CONST_news991)+
			(CONST_news992)
			}),

		map<SiegeTypes,  vector<string> >::value_type(SIEGE_CCS,

			{
				(CONST_news993)+
				(CONST_news994)

			,

			(CONST_news995)+
			(CONST_news996)
			}),

		map<SiegeTypes,  vector<string> >::value_type(SIEGE_FIREMEN,
			{
				(CONST_news999)+
				(CONST_news1000)+
			(CONST_news1001)+
			(CONST_news1002)

			,

			(CONST_news1005)+
			(CONST_news1006)
			}),


	};
	extern short lawList[LAWNUM];
	extern char newscherrybusted;
	extern bool multipleCityMode;
	extern MusicClass music;
	extern char lcityname[CITY_NAMELEN];
	extern short lawList[LAWNUM];
	vector<file_and_text_collection> majorevent_text_file_collection = {
		/*majorevent.cpp*/
		customText(&liberalCrime, majorevent + CONST_news019),
		customText(&AMorPM, majorevent + CONST_news020),
		customText(&book_title, majorevent + CONST_news021),
		customText(&book_title_2, majorevent + CONST_news022),
		customText(&random_nationality, majorevent + CONST_news023),
		customText(&conservative_oppose_book, majorevent + CONST_news024),
		customText(&radio_name, majorevent + CONST_news025),
		customText(&radio_name_2, majorevent + CONST_news026),
		customText(&vigilante_murder, majorevent + CONST_news027),
		customText(&why_chase_ended, majorevent + CONST_news028),
		customText(&crazy_conservative_act, majorevent + CONST_news029),
		customText(&bribe_officers, majorevent + CONST_news030),
		customText(&my_idol, majorevent + CONST_news031),
		customText(&prison_book_title, majorevent + CONST_news032),
		customText(&prison_book_title_2, majorevent + CONST_news033),
		customText(&mutilated_corpse, majorevent + CONST_news034),
		customText(&evidence_of_child_murder, majorevent + CONST_news035),
		customText(&break_in_murder_case, majorevent + CONST_news036),
		customText(&animal_research_country, majorevent + CONST_news037),
		customText(&drug_name, majorevent + CONST_news038),
		customText(&drug_name_2, majorevent + CONST_news039),
		customText(&chimp_drug_impact, majorevent + CONST_news040),
		customText(&chimp_drug_horror, majorevent + CONST_news041),
		customText(&terrorist_group, majorevent + CONST_news042),
		customText(&terrorist_plot, majorevent + CONST_news043),
		customText(&terrorist_plot_no_free_speech, majorevent + CONST_news044),
		customText(&gene_corp_name, majorevent + CONST_news045),
		customText(&gene_corp_name_2, majorevent + CONST_news046),
		customText(&gene_product_name, majorevent + CONST_news047),
		customText(&gene_product_name_2, majorevent + CONST_news048),
		customText(&gene_product_benefit, majorevent + CONST_news049),
		customText(&gene_product_cost, majorevent + CONST_news050),
		customText(&bullshit_no_free_speech, majorevent + CONST_news051),
		customText(&bullshit, majorevent + CONST_news052),
		customText(&petty_violence, majorevent + CONST_news053),
		customText(&his_her, majorevent + CONST_news054),
		customText(&older_younger, majorevent + CONST_news055),
		customText(&brother_sister, majorevent + CONST_news056),
		customText(&judge_with_prostitute, majorevent + CONST_news057),
		customText(&judge_with_prostitute_no_free_speech, majorevent + CONST_news058),
		customText(&judge_with_prostitute_full_free_speech, majorevent + CONST_news059),
		customText(&radio_host_crazy_quote, majorevent + CONST_news060),
		customText(&radio_host_lost_mind, majorevent + CONST_news061),
		customText(&family_values_company_name, majorevent + CONST_news062),
		customText(&family_values_company_name_2, majorevent + CONST_news063),
		customText(&family_values_company_name_3, majorevent + CONST_news064),
		customText(&pollution_consumption, majorevent + CONST_news065),
		customText(&pollution_consumption_2, majorevent + CONST_news066),
		customText(&i_like_polution, majorevent + CONST_news067),
		customText(&distrust_liberals, majorevent + CONST_news068),
		customText(&tech_giant_name, majorevent + CONST_news069),
		customText(&tech_giant_name_2, majorevent + CONST_news070),
		customText(&fm_radio_name, majorevent + CONST_news071),
		customText(&fm_radio_name_2, majorevent + CONST_news072),
		customText(&public_place, majorevent + CONST_news073),
		customText(&reagan_bad, majorevent + CONST_news074),
		customText(&reagan_bad_2, majorevent + CONST_news075),
		customText(&ceo_behaving_badly, majorevent + CONST_news076),
		customText(&reagan_good, majorevent + CONST_news077),
		customText(&reagan_good_2, majorevent + CONST_news078),
		customText(&cable_name, majorevent + CONST_news079),
		customText(&cable_name_2, majorevent + CONST_news080),
		customText(&cable_city, majorevent + CONST_news081),
		customText(&cable_city_2, majorevent + CONST_news082),
		/*squadstory_text.cpp*/
		customText(&ccs_adjective, majorevent + CONST_news083),
		customText(&ccs_adjective_2, majorevent + CONST_news084),
		customText(&ccs_adjective_3, majorevent + CONST_news085),
		customText(&ccs_noun, majorevent + CONST_news086),
		customText(&personalAds, mostlyendings + CONST_news087),
		customText(&personalAdsLG, mostlyendings + CONST_news088),
		customText(&adList, mostlyendings + CONST_news089, AD_LENGTH),
		customText(&adListB, mostlyendings + CONST_news090, AD_LENGTH),
		customText(&caseNEWSSTORY_CCS_DEFEATED, mostlyendings + CONST_news091),
		customText(&caseNEWSSTORY_CCS_NOBACKERS, mostlyendings + CONST_news092),
	};
	extern char endgamestate;
	extern CCSexposure ccsexposure;
	extern short attitude[VIEWNUM];
	extern char endgamestate;
	extern short attitude[VIEWNUM];
	extern int year;
	extern char newscherrybusted;
	extern char oldPresidentName[POLITICIAN_NAMELEN];
#endif	//NEWS_CPP
#ifdef	POLITICS_CPP
// politics.cpp

#include "../creature/creatureEnums.h"
/* fills a string with a proper name */
	void generate_name(char *str, char gender = GENDER_NEUTRAL);
	string lastname(bool x = false);
	//#include "../common/commonactions.h"
	int randomissue(bool core_only = 0);
#include "../common/commondisplay.h"
	// for  void makedelimiter(int y=8,int x=0);
	//#include "../monthly/EndGameStatus.h"
	/* EndGameStatus - attempts to pass a constitutional amendment to help win the game */
	void tossjustices(char canseethings);
	/* EndGameStatus - attempts to pass a constitutional amendment to help win the game */
	void amendment_termlimits(char canseethings);
#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include <common\\getnames.h>
	map<short, string> conservatiseLaw;
	map<short, string> liberalizeLaw;
#include "../common/musicClass.h"
	// string establishPrisonReform;
	// string improvePrisonConditions;
	//extern string pressKeyToReflect;
	//extern string YEA;
	//extern string NAY;
	// extern string commaSpace;
#include "../customMaps.h"
	map<int, bool> stalinView = {
		map<int, bool>::value_type(VIEW_STALIN,  false), // Liberals and Stalinists don't get along
		map<int, bool>::value_type(VIEW_MOOD,  false), // Liberals and Stalinists don't get along
		map<int, bool>::value_type(VIEW_GAY,  false), // Stalinists discriminate against gay people
		map<int, bool>::value_type(VIEW_DEATHPENALTY,  false), // Stalinists execute lots of people
		map<int, bool>::value_type(VIEW_TAXES,  true), // Stalinists support communist income redistribution
		map<int, bool>::value_type(VIEW_NUCLEARPOWER,  false), // Stalinists believe the more nuclear, the better
		map<int, bool>::value_type(VIEW_ANIMALRESEARCH,  false), // Stalinists are in favor of unethical research
		map<int, bool>::value_type(VIEW_POLICEBEHAVIOR,  false), // Stalinists use police for brutal repression
		map<int, bool>::value_type(VIEW_TORTURE,  false), // Stalinists torture their enemies
		map<int, bool>::value_type(VIEW_INTELLIGENCE,  false), // Stalinists don't believe in privacy
		map<int, bool>::value_type(VIEW_FREESPEECH,  false), // Stalinists don't allow any dissent
		map<int, bool>::value_type(VIEW_GENETICS,  false), // Stalinists are in favor of unethical research
		map<int, bool>::value_type(VIEW_JUSTICES,  false), // Liberals and Stalinists don't get along
		map<int, bool>::value_type(VIEW_GUNCONTROL,  true), // Stalinists don't want any armed resistance
		map<int, bool>::value_type(VIEW_SWEATSHOPS,  true), // Stalinists say, Workers of the world unite!
		map<int, bool>::value_type(VIEW_POLLUTION,  false), // Stalinists don't care about pollution
		map<int, bool>::value_type(VIEW_CORPORATECULTURE,  true), // Stalinists hate rich people and corporations
		map<int, bool>::value_type(VIEW_CEOSALARY,  true), // Stalinists hate rich people and corporations
		map<int, bool>::value_type(VIEW_WOMEN,  false), // Stalinists discriminate against women
		map<int, bool>::value_type(VIEW_CIVILRIGHTS,  false), // Stalinists discriminate against ethnic groups
		map<int, bool>::value_type(VIEW_DRUGS,  false), // Stalinists only allow vodka
		map<int, bool>::value_type(VIEW_IMMIGRATION,  false), // Stalinists maintained tight border security at the Iron Curtain
		map<int, bool>::value_type(VIEW_MILITARY,  false), // Stalinists use the military for brutal repression
		map<int, bool>::value_type(VIEW_PRISONS,  false), // Stalinists annex Canada to fill it with gulags
		map<int, bool>::value_type(VIEW_AMRADIO,  true), // Stalinists agree that Conservatives are bad
		map<int, bool>::value_type(VIEW_CABLENEWS,  true), // Stalinists agree that Conservatives are bad
														   //map<int, bool>::value_type( VIEW_POLITICALVIOLENCE,  true), // the LCS and Stalinists both like using political violence
														   map<int, bool>::value_type(VIEW_LIBERALCRIMESQUAD,  false), // Liberals and Stalinists don't get along
														   map<int, bool>::value_type(VIEW_LIBERALCRIMESQUADPOS,  false), // Liberals and Stalinists don't get along
														   map<int, bool>::value_type(VIEW_CONSERVATIVECRIMESQUAD,  true), // Stalinists agree that Conservatives are bad
														   map<int, bool>::value_type(VIEWNUM,  false), // Liberals and Stalinists don't get along
	};
	map<int, bool> stalinLaw = {
		map<int, bool>::value_type(LAW_STALIN,  false), // Liberals and Stalinists don't get along
		map<int, bool>::value_type(LAW_MOOD,  false), // Liberals and Stalinists don't get along
		map<int, bool>::value_type(LAW_ABORTION,  true), // Stalinists agree that abortion is good, although technically they don't let women choose
		map<int, bool>::value_type(LAW_ANIMALRESEARCH,  false), // Stalinists are in favor of unethical research
		map<int, bool>::value_type(LAW_POLICEBEHAVIOR,  false), // Stalinists use police for brutal repression
		map<int, bool>::value_type(LAW_PRIVACY,  false), // Stalinists don't believe in privacy
		map<int, bool>::value_type(LAW_DEATHPENALTY,  false), // Stalinists execute lots of people
		map<int, bool>::value_type(LAW_NUCLEARPOWER,  false), // Stalinists believe the more nuclear, the better
		map<int, bool>::value_type(LAW_POLLUTION,  false), // Stalinists don't care about pollution
		map<int, bool>::value_type(LAW_LABOR,  true), // Stalinists say, Workers of the world unite!
		map<int, bool>::value_type(LAW_GAY,  false), // Stalinists discriminate against gay people
		map<int, bool>::value_type(LAW_CORPORATE,  true), // Stalinists hate rich people and corporations
		map<int, bool>::value_type(LAW_FREESPEECH,  false), // Stalinists don't allow any dissent
		map<int, bool>::value_type(LAW_FLAGBURNING,  true), // Stalinists regularly burn flags
		map<int, bool>::value_type(LAW_GUNCONTROL,  true), // Stalinists don't want any armed resistance
		map<int, bool>::value_type(LAW_TAX,  true), // Stalinists support communist income redistribution
		map<int, bool>::value_type(LAW_WOMEN,  false), // Stalinists discriminate against women
		map<int, bool>::value_type(LAW_CIVILRIGHTS,  false), // Stalinists discriminate against ethnic groups
		map<int, bool>::value_type(LAW_DRUGS,  false), // Stalinists only allow vodka
		map<int, bool>::value_type(LAW_IMMIGRATION,  false), // Stalinists maintained tight border security at the Iron Curtain
		map<int, bool>::value_type(LAW_ELECTIONS,  false), // Stalinists don't even have elections
		map<int, bool>::value_type(LAW_MILITARY,  false), // Stalinists use the military for brutal repression
		map<int, bool>::value_type(LAW_PRISONS,  false), // Stalinists annex Canada to fill it with gulags
		map<int, bool>::value_type(LAW_TORTURE,  false), // Stalinists torture their enemies
		map<int, bool>::value_type(LAWNUM,  false), // Liberals and Stalinists don't get along
	};
	map<int, int> lawReturnAttitude = {
		map<int, int>::value_type(LAW_ABORTION, VIEW_WOMEN), //XXX, There is no ``VIEW_ABORTION''!
		map<int, int>::value_type(LAW_ANIMALRESEARCH, VIEW_ANIMALRESEARCH),
		map<int, int>::value_type(LAW_POLICEBEHAVIOR, VIEW_POLICEBEHAVIOR),
		map<int, int>::value_type(LAW_PRIVACY, VIEW_INTELLIGENCE),
		map<int, int>::value_type(LAW_DEATHPENALTY, VIEW_DEATHPENALTY),
		map<int, int>::value_type(LAW_NUCLEARPOWER, VIEW_NUCLEARPOWER),
		map<int, int>::value_type(LAW_POLLUTION, VIEW_POLLUTION),
		map<int, int>::value_type(LAW_LABOR, VIEW_SWEATSHOPS),
		map<int, int>::value_type(LAW_GAY, VIEW_GAY),
		map<int, int>::value_type(LAW_FREESPEECH, VIEW_FREESPEECH),
		map<int, int>::value_type(LAW_TAX, VIEW_TAXES),
		map<int, int>::value_type(LAW_FLAGBURNING, VIEW_FREESPEECH),  // <-- I'm keeping this pure free speech instead of free speech
		map<int, int>::value_type(LAW_WOMEN, VIEW_WOMEN),             // plus political violence. Ideologically, there's no association
		map<int, int>::value_type(LAW_CIVILRIGHTS, VIEW_CIVILRIGHTS), // between flag burning and violence. - Jonathan S. Fox
		map<int, int>::value_type(LAW_DRUGS, VIEW_DRUGS),
		map<int, int>::value_type(LAW_IMMIGRATION, VIEW_IMMIGRATION), //XXX, VIEW_DRUGS?
		map<int, int>::value_type(LAW_MILITARY, VIEW_MILITARY),
		map<int, int>::value_type(LAW_TORTURE, VIEW_TORTURE),
		map<int, int>::value_type(LAW_GUNCONTROL, VIEW_GUNCONTROL),
		map<int, int>::value_type(LAW_PRISONS, VIEW_PRISONS),
	};
	extern short attitude[VIEWNUM];
	extern short public_interest[VIEWNUM];
	extern short background_liberal_influence[VIEWNUM];
	extern short presparty;
	extern short exec[EXECNUM];
	extern short attitude[VIEWNUM];
	extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	extern short exec[EXECNUM];
	extern short presparty;
	extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	extern short exec[EXECNUM];
	void addStringYear();
	extern short senate[SENATENUM];
	extern MusicClass music;
	extern bool termlimits;
	extern bool stalinmode;
	extern char disbanding;
	extern short lawList[LAWNUM];
	extern short senate[SENATENUM];
	extern short house[HOUSENUM];
	extern bool stalinmode;
	extern char disbanding;
	extern char disbanding;
	extern bool termlimits;
	extern bool stalinmode;
	extern char disbanding;
	extern short lawList[LAWNUM];
	extern short house[HOUSENUM];
	extern short presparty;
	extern bool stalinmode;
	extern char disbanding;
	extern short execterm;
	extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	extern Log gamelog;

	extern bool stalinmode;
	extern char disbanding;
	extern short presparty;
	extern bool stalinmode;
	extern char disbanding;
	extern short execterm;
	extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	extern short exec[EXECNUM];
	extern Log gamelog;
	extern MusicClass music;

	extern bool stalinmode;

	extern short lawList[LAWNUM];
	extern short public_interest[VIEWNUM];
	extern MusicClass music;
	extern short exec[EXECNUM];
	extern short lawList[LAWNUM];
	extern short senate[SENATENUM];
	extern short court[COURTNUM];
	extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
	enum BillStatus
	{
		BILL_SIGNED = -2,
		BILL_OVERRIDE_VETO = -1,
		BILL_PASSED_CONGRESS = 0,
		BILL_FAILED = 1
	};
	extern short lawList[LAWNUM];
	extern short house[HOUSENUM];
	extern short senate[SENATENUM];
	extern MusicClass music;
	extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	extern short house[HOUSENUM];
	extern short senate[SENATENUM];
	extern short exec[EXECNUM];
	extern short lawList[LAWNUM];

	extern short house[HOUSENUM];
	extern short senate[SENATENUM];
	void attemptAmendmentEnding(char canseethings, Alignment enforcedAlignment);
	extern bool notermlimit;           //These determine if ELAs can take place --kviiri
	extern bool nocourtpurge;

	extern short exec[EXECNUM];
	extern short lawList[LAWNUM];
	extern short court[COURTNUM];
	extern short wincondition;
	extern short exec[EXECNUM];
	extern short lawList[LAWNUM];
	extern short house[HOUSENUM];
	extern short senate[SENATENUM];
	extern short court[COURTNUM];
	const string pressKeyToReflect = "Press any key to reflect on what has happened.";
	const string YEA = " Yea";
	const string NAY = " Nay";
	const string establishPrisonReform = "Establish Prison Rehabilitation";
	const string improvePrisonConditions = "Improve Prison Conditions";
	const string CONST_politics112 = "pro-Human Rights";
	const string CONST_politics111 = "return attitude[]";
	const string CONST_politics110 = "    ";
	const string CONST_politics109 = "None of the items made it to the President's desk.";
	const string CONST_politics107 = "*** VETO ***";
	const string CONST_politics106 = "FORCED BY CONGRESS";
	const string CONST_politics105 = "Dead in Congress";
	const string CONST_politics104 = "President";
	const string CONST_politics103 = "Press any key to watch the President.                   ";
	const string CONST_politics102 = "VP";
	const string CONST_politics100 = "Senate";
	const string CONST_politics099 = "House";
	const string CONST_politics098 = "Press any key to watch the votes unfold.";
	const string CONST_politics097 = "Expand Prisoners' Rights";
	const string CONST_politics096 = "Mandate Prison Rehabilitation";
	const string CONST_politics095 = "To ";
	const string CONST_politics094 = "Joint Resolution ";
	const string CONST_politics093 = "Legislative Agenda ";
	const string CONST_politics092 = "Congress is acting on legislation!";
	const string CONST_politics091 = ", is appointed to the bench.";
	const string CONST_politics090 = "the Honorable ";
	const string CONST_politics089 = "Comrade ";
	const string CONST_politics088 = "After much debate and televised testimony, a new justice,";
	const string CONST_politics087 = "Press any key to see what happens.";
	const string CONST_politics086 = ", is stepping down.";
	const string CONST_politics085 = "Justice ";
	const string CONST_politics084 = "Changing the Guard!";
	const string CONST_politics083 = " for Status Quo";
	const string CONST_politics082 = " for Change";
	const string CONST_politics080 = "Press any key to watch the decisions unfold.";
	const string CONST_politics077 = "A Decision could ";
	const string CONST_politics076 = " vs. ";
	const string CONST_politics075 = "United States";
	const string CONST_politics074 = "Supreme Court Watch ";
	const string CONST_politics073 = "The Supreme court is handing down decisions!";
	const string CONST_politics072 = "A Recount was Necessary";
	const string CONST_politics071 = "% No";
	const string CONST_politics070 = "% Yes";
	const string CONST_politics069 = "Press any key to watch the elections unfold.";
	const string CONST_politics065 = "Proposition ";
	const string CONST_politics064 = "Important Propositions ";
	const string CONST_politics063 = "Press any key to continue the elections.   ";
	const string CONST_politics062 = " (After Recount)";
	const string CONST_politics061 = "Press any key to watch the election unfold.";
	const string CONST_politics060 = "Mrs. ";
	const string CONST_politics059 = "Mr. ";
	const string CONST_politics058 = "Representative ";
	const string CONST_politics057 = "Ret. General ";
	const string CONST_politics056 = "Senator ";
	const string CONST_politics055 = "Governor ";
	const string CONST_politics054 = "Vice President ";
	const string CONST_politics053 = "President ";
	const string CONST_politics052 = "After a long primary campaign, the people have rallied around two leaders...";
	const string CONST_politics051 = "After a long primary campaign, the people have rallied around three leaders...";
	const string CONST_politics050 = "Presidential General Election ";
	const string CONST_politics049 = "The Elections are being held today!";
	const string CONST_politics048 = "Press any key to continue the elections.    ";
	const string CONST_politics047 = "        ";
	const string CONST_politics046 = "+";
	const string CONST_politics045 = "   C+: ";
	const string CONST_politics043 = "   C: ";
	const string CONST_politics041 = "   m: ";
	const string CONST_politics039 = "   L: ";
	const string CONST_politics037 = "   L+: ";
	const string CONST_politics035 = "   S: ";
	const string CONST_politics034 = "Net change:";
	const string CONST_politics033 = "S ";
	const string CONST_politics032 = "L+";
	const string CONST_politics031 = "L ";
	const string CONST_politics030 = "m ";
	const string CONST_politics029 = "C ";
	const string CONST_politics028 = "C+";
	const string CONST_politics020 = "House Elections ";
	const string CONST_politics004 = "                    ";
	const string CONST_politics002 = "Senate Elections ";
	const string CONST_politics001 = "corporateSuffix.txt";
	const string mostlyendings = "mostlyendings\\";
	extern short attitude[VIEWNUM];
	extern int year;
#endif	//POLITICS_CPP
#ifdef	RECRUIT_CPP
// recruit.cpp
#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"

#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"
//#include "../creature/deprecatedCreatureD.h"

////
#include "../items/armortype.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../basemode/activate.h"
// for recruitFindDifficulty and recruitName
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
#include "../common/commondisplayCreature.h"
// for void printcreatureinfo(Creature *,unsigned char=255)
#include "../common/getnames.h"
// for getview
//#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
// for subordinatesleft
#include "../combat/fight.h"

#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include "../common/musicClass.h"

/* recruit struct constructor */

#include "../combat/fight.h"

	void talk(DeprecatedCreature &a, const int t);

	void makecreature(const int x, const short type);
	short getCurrentSite();
	void setCurrentSite(const short i);
	extern MusicClass music;
	extern short attitude[VIEWNUM];
	extern DeprecatedCreature encounter[ENCMAX];

	const string CONST_activate065 = "missingno";
	const string CONST_recruit013 = "Adventures in Liberal Recruitment";
	const string CONST_recruit012 = "Press enter or escape to call it a day.";
	const string CONST_recruit011 = " - ";
	const string CONST_recruit010 = " was able to get information on multiple people.";
	const string CONST_recruit007 = " managed to set up a meeting with ";
	const string CONST_recruit006A = " was unable to track down a ";
	const string CONST_recruit006B = ".";
	const string CONST_recruit005A = " asks around for a ";
	const string CONST_recruit005B = "...";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";

#endif	//RECRUIT_CPP
#ifdef	REVIEWMODE_CPP
// reviewmode.cpp

#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locationsEnums.h"
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
#include "../common/commondisplayCreature.h"
// for void printfunds(int,int,char*)
#include "../common/getnames.h"
// for std::string getactivity(ActivityST)
//#include "../common/equipment.h"
	void consolidateloot(vector<Item *>&);
	void equipmentbaseassign();
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
	/* tells how many total members a squad has (including dead members) */
	// for short reviewmodeenum_to_sortingchoiceenum(short)
	//#include "../common/translateid.h"
	int getsquad(int);
	int getpoolcreature(int);
	//#include "../monthly/lcsmonthly.h"
	void fundreport(char &clearformess);
	void printname(const int hiding, const int location, const int flag, const string name);
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
#include "../common/creaturePool.h"
	const int PAGELENGTH = 19;

	struct stringAndColor
	{
		string str;
		ColorSetup type;
		stringAndColor(const string& str_, const ColorSetup type_) : str(str_), type(type_) { }
		stringAndColor(const ColorSetup type_, const string& str_) : str(str_), type(type_) { }
	};
	void nukeAllEmptySquads(const vector<int> squadloc, const int mode);
	extern short mode;
	extern Deprecatedsquadst *activesquad;
	extern long cursquadid;
	extern short activesortingchoice[SORTINGCHOICENUM];
	extern vector<DeprecatedCreature *> pool;
	extern vector<Deprecatedsquadst *> squad;
	extern vector<DeprecatedCreature *> pool;
	extern vector<Deprecatedsquadst *> squad;
	extern Log gamelog;
	extern int stat_kills;
	extern short activesortingchoice[SORTINGCHOICENUM];
	extern vector<DeprecatedCreature *> pool;
	extern vector<Deprecatedsquadst *> squad;
	extern bool multipleCityMode;
	extern short activesortingchoice[SORTINGCHOICENUM];
	extern vector<DeprecatedCreature *> pool;
	extern vector<DeprecatedCreature *> pool;

	extern vector<DeprecatedCreature *> pool;
	void setColorBasedOnSiege(const int cursite, const int y, const bool p);
	int consolidateSiegeLoot();

	extern MusicClass music;
	extern Deprecatedsquadst *activesquad;
	extern vector<DeprecatedCreature *> pool;
	extern vector<Deprecatedsquadst *> squad;
	const string eightyBlankSpaces = "                                                                                ";
	const string CONST_reviewmode134 = "Press Z to Assemble a New Squad.  Press T to Assign New Bases to the Squadless.";
	const string CONST_reviewmode133 = "  Press U to Promote Liberals.";
	const string CONST_reviewmode132 = "Press a Letter to select a squad.  1-7 to view Liberal groups.";
	const string CONST_reviewmode131 = "Press Y to turn on some Music.";
	const string CONST_reviewmode130 = "Press Y to turn off the Music.";
	const string CONST_reviewmode129 = "Press V to Inspect Liberal finances.";
	const string CONST_reviewmode128 = "8 - Review and Move Equipment (";
	const string CONST_reviewmode127 = "7 - Away (";
	const string CONST_reviewmode126 = "6 - The Dead (";
	const string CONST_reviewmode125 = "5 - Sleepers (";
	const string CONST_reviewmode124 = "4 - Justice System (";
	const string CONST_reviewmode123 = "3 - Hospital (";
	const string CONST_reviewmode122 = "2 - Hostages (";
	const string CONST_reviewmode121 = "1 - Active Liberals (";
	const string CONST_reviewmode120 = "Acting Individually";
	const string CONST_reviewmode119 = "컴컴SQUAD NAME컴컴컴컴컴컴컴컴횸OCATION컴컴컴컴컴컴ACTIVITY컴컴컴컴컴컴컴컴컴컴�";
	const string CONST_reviewmode118 = "Review your Liberals and Assemble Squads";
	const string CONST_reviewmode117 = "Enlightened Liberals follow anyone. Seduced Liberals follow only their lover.";
	const string CONST_reviewmode116 = "Press a letter to promote a Liberal. You cannot promote Liberals in hiding.";
	const string CONST_reviewmode115 = "<LCS Leader>";
	const string CONST_reviewmode114 = "<Can't Lead More>";
	const string CONST_reviewmode113 = "<Refuses Promotion>";
	const string CONST_reviewmode112 = "CONTACT AFTER PROMOTION";
	const string CONST_reviewmode111 = "컴컴CODE NAME컴컴컴컴컴컴컴CURRENT CONTACT컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴";
	const string CONST_reviewmode110 = "Promote the Elite Liberals";
	const string CONST_reviewmode109 = "T to sort people.";
	const string CONST_reviewmode108 = ",. to view other Base pages.";
	const string CONST_reviewmode107 = "Liberals must be moved in squads to transfer between cities.";
	const string CONST_reviewmode106 = "Press a Letter to assign a Base.  Press a Number to select a Base.";
	const string CONST_reviewmode105 = " <Under Siege>";
	const string CONST_reviewmode104 = "NEW BASE";
	const string CONST_reviewmode103 = "컴컴CODE NAME컴컴컴컴컴컴CURRENT BASE컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�";
	const string CONST_reviewmode102 = "New Bases for Squadless Liberals";
	const string CONST_reviewmode101 = " with";
	const string CONST_reviewmode100 = "Choose squad member to replace ";
	const string CONST_reviewmode099 = "                                                                                ";
	const string CONST_reviewmode097 = " has gained wisdom.                                                             ";
	const string CONST_reviewmode096 = " grows colder.                                                                  ";
	const string CONST_reviewmode095 = " has lost heart.                                                                ";
	const string CONST_reviewmode094 = " feels sick to the stomach afterward and                                        ";
	const string CONST_reviewmode091 = " by ";
	const string CONST_reviewmode090 = " executes ";
	const string CONST_reviewmode089 = "  C - Confirm       Any other key to continue                                   ";
	const string CONST_reviewmode088 = "Killing your squad members is Not a Liberal Act.                                ";
	const string CONST_reviewmode087 = " kill this squad member?                               ";
	const string CONST_reviewmode086 = "Confirm you want to have ";
	const string CONST_reviewmode085 = " in court.";
	const string CONST_reviewmode084 = "to testify against ";
	const string CONST_reviewmode083 = "The Conservative traitor has ratted you out to the police, and sworn";
	const string CONST_reviewmode082 = "'s whereabouts.";
	const string CONST_reviewmode081 = "A Liberal friend tips you off on ";
	const string CONST_reviewmode078 = " has been released.                                                             ";
	const string CONST_reviewmode076 = "If the member has low heart they may go to the police.                          ";
	const string CONST_reviewmode075 = "Do you want to permanently release this squad member from the LCS?              ";
	const string CONST_reviewmode073 = "What is the new code name?                                                      ";
	const string CONST_reviewmode072 = "    UP/DOWN  - More Info";
	const string CONST_reviewmode071 = "Press any other key to continue the Struggle";
	const string CONST_reviewmode070 = "    LEFT/RIGHT - View Others";
	const string CONST_reviewmode069 = "N - Change Code Name      G - Fix Gender Label";
	const string CONST_reviewmode068 = "Press N to change this Automaton's Code Name";
	const string CONST_reviewmode067 = "         K - Kill member";
	const string CONST_reviewmode066 = "R - Remove member";
	const string CONST_reviewmode065 = "Profile of a Liberal";
	const string CONST_reviewmode064 = "Profile of an Automaton";
	const string CONST_reviewmode063 = " T to sort people.";
	const string CONST_reviewmode062 = "Reorder Liberals";
	const string CONST_reviewmode061 = "Place ";
	const string CONST_reviewmode060 = "Press a Letter to View Status.        Z - ";
	const string CONST_reviewmode059 = "<No Contact>";
	const string CONST_reviewmode058 = "Day";
	const string CONST_reviewmode057 = "Days";
	const string CONST_reviewmode054 = "Month";
	const string CONST_reviewmode053 = "Months";
	const string CONST_reviewmode052 = "Out in ";
	const string CONST_reviewmode051 = "컴컴컴�";
	const string CONST_reviewmode048 = "Life Sentence";
	const string CONST_reviewmode047 = " Life Sentences";
	const string CONST_reviewmode044 = "DEATH ROW: ";
	const string CONST_reviewmode041 = "SQUAD";
	const string CONST_reviewmode040 = "Away";
	const string CONST_reviewmode039 = "컴컴CODE NAME컴컴컴컴컴컴SKILL컴횴EALTH컴횸OCATION컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴";
	const string CONST_reviewmode038 = "The Liberal Crime Squad";
	const string CONST_reviewmode036 = "What shall we designate this Liberal squad?                                     ";
	const string CONST_reviewmode033 = "You cannot form a Squad with only Conservatives!                                ";
	const string CONST_reviewmode031 = "Temporary Squad";
	const string CONST_reviewmode028 = "Press a Letter to view Liberal details.                                         ";
	const string CONST_reviewmode026 = "                Squad Liberals must be able to move around.                     ";
	const string CONST_reviewmode023 = "           Liberals must be in the same location to form a Squad.               ";
	const string CONST_reviewmode021 = "9 - Dissolve the squad.";
	const string CONST_reviewmode020 = "Enter - I need no squad!";
	const string CONST_reviewmode019 = "Enter - The squad is ready.";
	const string CONST_reviewmode018 = "V - View a Liberal";
	const string CONST_reviewmode016 = "Press a Letter to add or remove a Liberal from the squad.";
	const string CONST_reviewmode015 = "AWAY";
	const string CONST_reviewmode012 = "컴컴CODE NAME컴컴컴컴컴컴SKILL컴횴EALTH컴컴컴컴컴횾ROFESSION컴컴컴컴컴컴컴컴컴컴";
	const string CONST_reviewmode011 = "Squad: ";
	const string CONST_reviewmode010 = "New Squad";
	const string CONST_reviewmode009 = "The squad is full.";
	const string CONST_reviewmode008 = "Assemble the squad!";
	const string CONST_reviewmode007 = "getsSick.txt";
	const string CONST_reviewmode006 = "methodOfExecution.txt";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";
	const string mostlyendings = "mostlyendings\\";
#endif	//REVIEWMODE_CPP
#ifdef	SAVELOAD_CPP
// saveload.cpp

#include "../creature/creature.h"
////

#include "../creature/deprecatedCreatureA.h"
#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../common/equipment.h"
//for void consolidateloot(vector<Item *> &loot);
#include "../common/translateid.h"
// for  getloottype
#include "titlescreen.h"
#include "../cursesAlternative.h"
#include "../common/creaturePool.h"

	Item* create_item(const std::string& inputXml);
	extern vector<DeprecatedCreature *> pool;
	extern Log gamelog;
	extern char newscherrybusted;
	extern vector<Location *> location;
	extern bool multipleCityMode;
	extern int stat_buys;
	extern int stat_burns;
	extern short presparty;
#include "../common/musicClass.h"
	extern MusicClass music;
	extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	extern int stat_kidnappings;
	extern int year;
	extern short mode;
	extern short exec[EXECNUM];
	extern char endgamestate;
	extern bool encounterwarnings;
	extern int stat_dead;
	extern int stat_kills;
	extern int stat_recruits;
	extern char oldPresidentName[POLITICIAN_NAMELEN];
	extern vector<Vehicle *> vehicle;
	extern unsigned long seed[RNG_SIZE];
	extern short wincondition;
	extern short fieldskillrate;
	extern int day;
	extern int month;
	extern int year;
	extern short execterm;
	extern short presparty;
	extern int amendnum;
	extern bool termlimits;
	extern bool deagle;
	extern bool m249;
	extern bool notermlimit;
	extern bool nocourtpurge;
	extern bool stalinmode;
	extern char ccs_kills;
	extern long curcreatureid;
	extern long cursquadid;
	extern short offended_corps;
	extern short offended_cia;
	extern short offended_amradio;
	extern short offended_cablenews;
	extern short offended_firemen;
	extern int police_heat;
	extern unsigned long attorneyseed[RNG_SIZE];
	extern char lcityname[CITY_NAMELEN];
	extern char slogan[SLOGAN_LEN];
	extern string slogan_str;
	extern short party_status;
	extern short attitude[VIEWNUM];
	extern short public_interest[VIEWNUM];
	extern short background_liberal_influence[VIEWNUM];
	extern short lawList[LAWNUM];
	extern short house[HOUSENUM];
	extern short senate[SENATENUM];
	extern short court[COURTNUM];
	extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
	extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	extern UniqueCreatures uniqueCreatures;
	extern vector<Deprecatedsquadst *> squad;
	extern vector<Deprecateddatest *> date;
	extern vector<Deprecatedrecruitst *> recruit;
	extern vector<Deprecatednewsstoryst *> newsstory;
	extern Deprecatedsquadst *activesquad;
	extern char homedir[MAX_PATH_SIZE];
	struct  saveLoadChunk {
		void * Buffer;
		size_t      ElementSize;
		size_t      ElementCount;
		saveLoadChunk(void * _Buffer, int _ElementSize, int _ElementCount) :Buffer(_Buffer), ElementSize(_ElementSize), ElementCount(_ElementCount) {}
	};
	extern class Ledger ledger;
	extern CCSexposure ccsexposure;
	extern bool NOVERBOSECOMMENTS;
	extern map<short, string> getLawString;
	extern map<short, string> skillEnumToString;
	extern map<short, string> getLawFlagString;
	extern map<short, map<short, string> > getLawFlagStringFull;
	// Store savefiles in plaintext, making it human readable and editable
	extern bool VERBOSESAVEFILE;
	// Don't save the game
	extern bool NOSAVE;
	//	extern int version;
	const string itemType = "Item type ";
	const string doesNotExistItem = " does not exist. Deleting item.";
	const string vehicleType = "Vehicle type ";
	const string doesNotExistVehicle = " does not exist. Deleting vehicle.";
	const string CONST_saveloadB081 = "# and are thereby ignored";
	const string CONST_saveload091 = "rb";
	const string CONST_saveload090 = "wb";
	const string CONST_saveload089 = ".verbose";
	const string CONST_saveload088 = ".";
	const string CONST_saveload084 = "# cursquadid";
	const string CONST_saveload083 = "# curcreatureid";
	const string CONST_saveload082 = "# Vehicle::curcarid";
	const string CONST_saveload081 = "# ";
	const string CONST_saveload080 = "# Crimes";
	const string CONST_saveload079 = "# Next Creature";
	const string CONST_saveload076 = "# Skills";
	const string CONST_saveload074 = "# Juice";
	const string CONST_saveload073 = "# Alignment";
	const string CONST_saveload072 = "# Birthday Day";
	const string CONST_saveload071 = "# Birthday Month";
	const string CONST_saveload070 = "# Age";
	const string CONST_saveload069 = "# Gender (Liberal)";
	const string CONST_saveload068 = "# Gender (Conservative)";
	const string CONST_saveload067 = "# Proper Name";
	const string CONST_saveload066 = "# Name";
	const string CONST_saveload064 = "# oldPresidentName";
	const string CONST_saveload063 = "# execname";
	const string CONST_saveload062 = "# exec";
	const string CONST_saveload061 = "# Supreme Court Names";
	const string CONST_saveload060 = "# Supreme Court";
	const string CONST_saveload059 = "# Senate";
	const string CONST_saveload058 = "# House";
	const string CONST_saveload056 = "# Law List";
	const string CONST_saveload055 = "# Concerning ";
	const string CONST_saveload054 = "# Attitude";
	const string CONST_saveload053 = "# Party Status";
	const string CONST_saveload052 = "# Slogan";
	const string CONST_saveload051 = "# Liberal Guardian Published";
	const string CONST_saveload050 = "# L City Name";
	const string CONST_saveload049 = "# attorneyseed";
	const string CONST_saveload048 = "# Offended Firemen";
	const string CONST_saveload047 = "# Offended Cablenews";
	const string CONST_saveload046 = "# Offended Amradio";
	const string CONST_saveload045 = "# Offended CIA";
	const string CONST_saveload044 = "# Offended Corps";
	const string CONST_saveload043 = "# Police Heat";
	const string CONST_saveload042 = "# ccs_kills";
	const string CONST_saveload041 = "# ccsexposure";
	const string CONST_saveload040 = "# endgamestate";
	const string CONST_saveload039 = "# stat_burns";
	const string CONST_saveload038 = "# stat_buys";
	const string CONST_saveload037 = "# stat_kidnappings";
	const string CONST_saveload036 = "# stat_kills";
	const string CONST_saveload035 = "# stat_dead";
	const string CONST_saveload034 = "# stat_recruits";
	const string CONST_saveload033 = "# stalinmode";
	const string CONST_saveload032 = "# nocourtpurge";
	const string CONST_saveload031 = "# notermlimit";
	const string CONST_saveload030 = "# m249";
	const string CONST_saveload029 = "# deagle";
	const string CONST_saveload028 = "# termlimits";
	const string CONST_saveload027 = "# multipleCityMode";
	const string CONST_saveload026 = "# amendnum";
	const string CONST_saveload025 = "# presparty";
	const string CONST_saveload024 = "# execterm";
	const string CONST_saveload023 = "# year";
	const string CONST_saveload022 = "# month";
	const string CONST_saveload021 = "# day";
	const string CONST_saveload020 = "# fieldskillrate";
	const string CONST_saveload019 = "# wincondition";
	const string CONST_saveload018 = "# mode";
	const string CONST_saveload017 = "# seed";
	const string CONST_saveload016 = "# LCS Funding level (max value 2147483647) can be negative";
	const string CONST_saveload015 = "# NOVERBOSECOMMENTS to remove them (almost) entirely";
	const string CONST_saveload014 = "# If these comments are more trouble than they're worth, add to the debug_defines.txt file";
	const string CONST_saveload013 = "# There will be quite a few comments generated automatically";
	const string CONST_saveload012 = "# Since the purpose of verbose savefiles is to make them human readable and editable,";
	const string CONST_saveload011 = "# All lines beginning with # are comments";
	const string CONST_saveload010 = "# remove NOVERBOSECOMMENTS to activate autocomments";
	const string CONST_saveload009 = "# Autocomments disabled";
	const string CONST_saveload008 = "Verbose File Could Not Be Opened";
	const string CONST_saveload004 = "export";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";
#endif	//SAVELOAD_CPP
#ifdef	SHOP_CPP
// shop.cpp

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
#include "../items/loottype.h"
#include "../items/itemPool.h"
#include "../items/loottypePool.h"
#include "../items/loot.h"
#include "../sitemode/shop.h"
//own header 
#include "../common/stringconversion.h"
//for string conversion
#include "../common/commondisplay.h"
// for void printfunds(int,int,char*)
#include "../common/equipment.h"
//for void equip(vector<Item *> &loot,int loc);
//#include "../common/commonactionsCreature.h"
#include "../common/translateid.h"
// for  int getweapontype
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../set_color_support.h"
#include "../common/musicClass.h"
#include <functional>
//extern string spaceDashSpace;
//extern string closeParenthesis;
//extern string undefined;
// extern string check_status_of_squad_liberal;
// extern string show_squad_liberal_status;
// extern string enter_done;
// extern string chooseALiberalTo;
// extern string singleSpace;
	Item* getNewLoot(const string& newLootType, int num = 1);
	// string paranthesisDollar;

	void consolidateLoot(const int l);
	string getLootTitle(const int base, const int l);
	int getFenceValueLocation(int l, int slot);
	int getLootNumber(const int base, const int l);
	int getLocationLootNumber(int l, int slot);
	bool getCanBeSoldLocation(int l, int slot);
	void decreateLocationLoot(int loc, int loot, int num);
#include "locations/locationsPool.h"
	void equipLoot(int l, int loc);
	void deleteLocationLoot(int loc, int loot);
	int whatIsThisItemInLocation(int loc, int l);
	bool noQuickFenceLocation(int loc, int l);
	extern short party_status;
	extern class Ledger ledger;
	extern short party_status;
	extern class Ledger ledger;
	extern vector<ArmorType *> armortype;
	extern vector<Location *> location;
	extern short party_status;
	extern class Ledger ledger;	


	extern class Ledger ledger;
	extern vector<WeaponType *> weapontype;
	extern short lawList[LAWNUM];
	extern vector<WeaponType *> weapontype;
	extern vector<ArmorType *> armortype;
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern class Ledger ledger;
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern vector<Location *> location;
	const string CONST_shopB061 = "option";
	const string CONST_shop062 = "$";
	const string CONST_shop061 = "Enter - ";
	const string CONST_shop060 = "B - Choose a buyer";
	const string CONST_shop059 = "S - Sell something";
	const string CONST_shop058 = "E - Look over Equipment";
	const string CONST_shop057 = "M - Buy a Mask                ($15)";
	const string CONST_shop056 = "Buyer: ";
	const string CONST_shop055 = " With a Random Mask";
	const string CONST_shop054 = "Z - Surprise ";
	const string CONST_shop053 = "Press a Letter to select a Mask";
	const string CONST_shop052 = "컴컴PRODUCT NAME컴컴컴컴컴컴컴컴컴컴컴?ESCRIPTION컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴";
	const string CONST_shop051 = " buy?";
	const string CONST_shop050 = "Which mask will ";
	const string CONST_shop049 = "SPEND.";
	const string CONST_shop048 = " to Liberal Funds.";
	const string CONST_shop047 = "You add $";
	const string CONST_shop046 = "Really sell all clothes? (Y)es to confirm.           ";
	const string CONST_shop045 = "Really sell all ammo? (Y)es to confirm.              ";
	const string CONST_shop044 = "Really sell all weapons? (Y)es to confirm.           ";
	const string CONST_shop043 = "Enter - Done pawning";
	const string CONST_shop042 = "L - Pawn all Loot";
	const string CONST_shop041 = "C - Pawn all Clothes";
	const string CONST_shop040 = "A - Pawn all Ammunition";
	const string CONST_shop039 = "W - Pawn all Weapons";
	const string CONST_shop038 = "F - Pawn Selectively";
	const string CONST_shop036 = " You can't sell damaged goods.";
	const string CONST_shop035 = "Press a letter to select an item to sell.";
	const string CONST_shop034 = " x";
	const string CONST_shop033 = "/";
	const string CONST_shop032 = "Estimated Liberal Amount: $";
	const string CONST_shop031 = "What will you sell?";
	const string CONST_shop029 = "Press a Letter to select an option";
	const string CONST_shop028 = "컴컴PRODUCT NAME컴컴컴컴컴컴컴컴컴컴컴?RICE컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴";
	const string CONST_shop026 = "What will ";

	const string tag_letter = "letter";
	const string tag_sleeperprice = "sleeperprice";
	const string tag_price = "price";
	const string tag_description = "description";
	const string tag_type = "type";
	const string tag_LOOT = "LOOT";
	const string tag_ARMOR = "ARMOR";
	const string tag_CLIP = "CLIP";
	const string tag_WEAPON = "WEAPON";
	const string tag_class = "class";
	const string tag_item = "item";
	const string tag_sell_masks = "sell_masks";
	const string tag_exit = "exit";
	const string tag_entry = "entry";
	const string tag_department = "department";
	const string tag_increase_prices_with_illegality = "increase_prices_with_illegality";
	const string tag_allow_selling = "allow_selling";
	const string tag_fullscreen = "fullscreen";
	const string tag_on = "on";
	const string tag_only_sell_legal_items = "only_sell_legal_items";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";
	extern MusicClass music;
	map<string, int> shopInitTags = {
	map<string, int>::value_type(tag_only_sell_legal_items, ENUM_tag_only_sell_legal_items),
	map<string, int>::value_type(tag_fullscreen, ENUM_tag_fullscreen),
	map<string, int>::value_type(tag_allow_selling, ENUM_tag_allow_selling),
	map<string, int>::value_type(tag_increase_prices_with_illegality, ENUM_tag_increase_prices_with_illegality),
	map<string, int>::value_type(tag_department, ENUM_tag_department),
	map<string, int>::value_type(tag_entry, ENUM_tag_entry),
	map<string, int>::value_type(tag_exit, ENUM_tag_exit),
	map<string, int>::value_type(tag_sell_masks, ENUM_tag_sell_masks),
	map<string, int>::value_type(tag_letter, ENUM_tag_letter),
	map<string, int>::value_type(tag_item, ENUM_tag_item),

	};
	map<string, int> shopItemTags = {
		map<string, int>::value_type(tag_class, ENUM_tag_class),
		map<string, int>::value_type(tag_type, ENUM_tag_type),
		map<string, int>::value_type(tag_description, ENUM_tag_description),
		map<string, int>::value_type(tag_price, ENUM_tag_price),
		map<string, int>::value_type(tag_sleeperprice, ENUM_tag_sleeperprice),
		map<string, int>::value_type(tag_letter, ENUM_tag_letter),

	};
#endif	//SHOP_CPP
#ifdef	SIEGE_CPP
// siege.cpp

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
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../basemode/baseactions.h"
// for orderparty
#include "../sitemode/sitedisplay.h"
//#include "../sitemode/advance.h"
	void creatureadvance();
	//#include "../sitemode/miscactions.h"
	void reloadparty(bool wasteful = false);
	//#include "../sitemode/sitemode.h"
	void mode_site(const short loc);
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
	// for void cleangonesquads();
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
// for void printfunds(int,int,char*)
#include "../common/translateid.h"
// for  int getsquad(int)
#include "../politics/politics.h"
//for  int publicmood(int l);
#include "../combat/fight.h"   
//for void autopromote(int loc);
#include "../combat/chase.h"
//for void evasiverun();
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"

	void emptyEncounter();
	void fillEncounter(CreatureTypes c, int numleft);
#include "../common/creaturePool.h"
	bool hasPrintingPress(int l);
	void deletePrintingPress(int loc);
	void deleteCompoundWalls(int loc);
	void deleteBusinessFront(int loc);
	void CCSCapturesSite(int loc);
	void endLocationSiege(int l);
	void deleteLocationLoot(int l);
	void deleteLocationVehicles(int loc);

	int baddieCount();
	int encounterSize();
	vector<NameAndAlignment> getEncounterNameAndAlignment();
	extern Log gamelog;
	extern short offended_firemen;
	extern short offended_amradio;
	extern short offended_cablenews;
	extern MusicClass music;
	extern vector<DeprecatedCreature *> pool;
	extern vector<Deprecatedsquadst *> squad;
	extern class Ledger ledger;
	short getCurrentSite();
	void setCurrentSite(const short i);
	extern int stat_dead;
	extern Log gamelog;
	extern MusicClass music;
	extern vector<DeprecatedCreature *> pool;
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";

	void printEscapeEngageInfo();
	void printEscapeEngageInfoFooter(const bool cameras, const bool traps);
	void logDefeat();
	void printConquerTextCCS(const int ccs_siege_kills, const int ccs_kills);
	void printConquerText(const bool police);
	
	extern Log gamelog;
	extern MusicClass music;
	extern short lawList[LAWNUM];
	extern vector<DeprecatedCreature *> pool;
	extern short lawList[LAWNUM];
	void dropHeatByFivePercent(int l);
	int getTimeUntilSiege(int l);
	void huntFasterIfSiteIncrediblyHot(int l);
	void updateLocationHeatProtection(int l);
	void letPlaceCoolOffUnlessCrime(int crimes, int l);
	void policeSiege(int l);
	void corporateSiege(int l);
	void CCSSiege(int l);
	void CIASiege(int l);
	void hicksSiege(int l);
	void firemanSiege(int l);
	bool hasCameras(int l);
	bool hasAGenerator(int l);
	bool hasBusinessFront(int l);
	bool siteHasAAGun(int l);
	void deleteAAGun(int l);

	extern Log gamelog;
	extern short offended_corps;
	extern vector<DeprecatedCreature *> pool;
	extern Log gamelog;

	extern vector<DeprecatedCreature *> pool;

	extern Log gamelog;

	extern MusicClass music;
	extern vector<DeprecatedCreature *> pool;


	extern Log gamelog;

	extern MusicClass music;

	extern Log gamelog;

	extern vector<DeprecatedCreature *> pool;

	extern Log gamelog;
	extern short offended_corps;

	extern MusicClass music;

	extern Log gamelog;
	extern vector<DeprecatedCreature *> pool;
	extern MusicClass music;
	extern Log gamelog;

	extern short lawList[LAWNUM];
	extern Log gamelog;
	extern vector<DeprecatedCreature *> pool;
	extern short offended_firemen;

	extern Log gamelog;
	extern char disbanding;
	extern short offended_corps;
	extern short offended_cia;
	extern char endgamestate;
	extern short offended_amradio;
	extern short offended_cablenews;
	extern short offended_firemen;
	extern MusicClass music;
	extern short lawList[LAWNUM];
	extern short attitude[VIEWNUM];
	extern vector<DeprecatedCreature *> pool;

	extern Log gamelog;
	extern char disbanding;
	extern short offended_firemen;
	extern short lawList[LAWNUM];
	extern vector<DeprecatedCreature *> pool;

	extern vector<DeprecatedCreature *> pool;
	extern Log gamelog;
	extern vector<DeprecatedCreature *> pool;
	extern Log gamelog;
	extern int stat_dead;
	extern short lawList[LAWNUM];
	extern vector<DeprecatedCreature *> pool;
	void deleteGeneratorLightsOff(int l);

	extern Log gamelog;
	extern int stat_dead;
	extern vector<DeprecatedCreature *> pool;

	extern Log gamelog;
	extern short lawList[LAWNUM];

	int printBestLCSMemberForNews(const string repname, const int l);
	extern Log gamelog;
	extern short lawList[LAWNUM];

	bool getLightsOff(int l);
	void setLightsOff(int l);
	bool hasBasicCompoundWalls(int l);

	extern Log gamelog;
	extern int stat_dead;
	extern short lawList[LAWNUM];

	void reduceCompoundStores(int loc, int amount);
	void emptyCompoundStores(int l);
	void setUnderAttack(int l);

	extern Log gamelog;
	extern char disbanding;
	extern int stat_dead;
	extern short lawList[LAWNUM];
	extern vector<DeprecatedCreature *> pool;
	void baseEveryoneLeftAtHomelessShelter(const int homes);
	void escalateSite(int l);
	void dumpLootAtLocation(int homes, vector<Item *>& loot);
	extern Log gamelog;
	extern Deprecatedsquadst *activesquad;
	extern MusicClass music;
	extern int police_heat;
	extern Log gamelog;
	extern MusicClass music;
	siegest getWholeSiege(int l);
	extern Deprecatednewsstoryst *sitestory;
	void cancelOutBleeding();
	int print_character_info(const int c, const int party_status);
	void countHeroes(int &partysize, int &partyalive);
	extern Log gamelog;
	extern short mode;
	extern char foughtthisround;
	extern MusicClass music;
	extern short party_status;
	extern Log gamelog;
	extern Deprecatednewsstoryst *sitestory;
	extern vector<Deprecatednewsstoryst *> newsstory;
	int print_character_info(const int c, const int party_status);
	int getEscapeEngageLocation();
	void deleteAllSquadsInActiveAreaExceptActive(const int loc);
	void formANewSquadIfThereAreNone();
	extern Log gamelog;
	extern int selectedsiege;
	extern MusicClass music;
	extern long cursquadid;
	extern Log gamelog;
	extern int selectedsiege;
	extern MusicClass music;
	extern long cursquadid;
	void juiceEntireCreaturePool(const long juice, const long cap);
	extern Log gamelog;
	extern MusicClass music;
	extern int ccs_siege_kills;
	extern char ccs_kills;

	extern vector<Deprecatednewsstoryst *> newsstory;
	extern Log gamelog;
	extern Deprecatedsquadst *activesquad;
	extern int selectedsiege;
	void printBrokenLawsFooter(const bool kidnapped, const int typenum);
	void printHarboringFugitive();
	void printBrokenLawsHeader(const char underAttack, const short escalation);
	void printBurnedFlag(const int flagLaw);
	void printHireIllegal(const bool lawStatus);
	void printReleaseKidnapped(const string kname, const int kidnapped);
	void printCCSRaidSafehouse();
	void printCorpSiegeWarning(const int sleeper, const string locationName);
	void corporateSiegePrint(const string lname);
	void printCCSCarbomb();
	void printCCSRaid(const string lname);
	void printEveryoneInjuredHeader();
	void printInjuredList(const vector<pair<string, int> > injuredList);
	void printKillList(const vector<pair<string, int> > killList);
	void printCCSSleeperWarning(const string lname);
	void printJetBombers();
	void printTankArrival(const bool tank_traps);
	void printSWATArrival();
	void printPoliceSiegeHeader(const string lname);
	void printPoliceSleeperWarning(const string locationName, const int siegeEscalationState);
	void printPoliceSiegeEmptyHeader(const string lname);
	void printCorpseRecoveredByPolice(const string corpse, const int y);
	void printKidnapRecoveredByPolice(const string kidnap, const int y);
	void printSpecificCrime(const Lawflags crime);
	void printMostSeriousCrime(const bool breakercount[LAWFLAGNUM]);
	void printWantedFor();
	void printRehab();
	void printEveryoneHereIsDead(const string lname);
	void printBusinessFrontTaken();
	void printCompoundDismantled();
	void printPrintingpressDismantled();
	void printMoneyConfiscated(const int confiscated);
	void printFundsIntact();
	void printLiberalsTakenToPolice(const int pcount);
	void printSingleLiberalTaken(const string pname, const string pcname);
	void printKidnapFreed();
	void printSingleKidnapFreed(const string kname);
	void printTheyConfiscateEverything(const int siege, const int escalationState);
	void printConquerTextCCS(const int ccs_siege_kills, const int ccs_kills);
	void printCorpseRecovery(const int y, const string name);
	void printKidnapRescue(const int y, const string name);
	void printFiremenSiegeEmpty(const string locationName);
	void printFiremenRaid2();
	void printFiremenRaid(const string loc);
	void printFiremenSiegeEmpty(const bool printingPress, const bool businessFront);
	void printCIASiegeWarning(const string locationName);
	void printCIASiege(const string locationName, const bool hasCameras, const bool hasAGenerator);
	void printRadioHicksSiege(const int l);
	void printCableHicksSiege(const int l);
	void printFiremenSiege(const bool sleeper, const int l);
	void printReporterEnteredCompound(const string repname);
	void printThePoliceCutLights(const bool clearformess);
	void printReporterDuringSiege(const string repname, const string name, const int segmentpower);
	void printShotBySniper(const string targname);
	void printMissedBySniper(const string targname);
	void printWasKilledInBombing(const string targname);
	void printNarrowlyAvoidsDeath(const string targname);
	void printNoOneIsHurt(const bool clearformess);
	void printCONST_siege199(const bool clearformess);
	void printCONST_siege198(const bool clearformess);
	void printCONST_siege197(const bool clearformess);
	void printCONST_siege196(const bool clearformess);
	void printCONST_siege195(const bool clearformess);
	void printCONST_siege194(const bool clearformess);
	void printCONST_siege193(const bool clearformess);
	void printCONST_siege192(const bool clearformess);
	void printCONST_siege191(const bool clearformess);
	void printCONST_siege190(const bool clearformess);
	void printCONST_siege189(const bool clearformess);
	void printConservativesRaidedUnoccupiedSafehouse(const string locname);
	void printCorpseRecovered(const string pname, const int y);
	void printLiberalRescued(const string pname, const int y);
	void printReflectOnYourConJudgement();
	void printSallyForthSiege();
	void printSallyForthFooter();
	void printYoureFree();
	void printSiegeIsBroken();
	void printSiegeOptions(const int partysize, const short party_status);
	void printLocationName(const string loc);
	void printTanksMoveToEntrance(const bool clearformess);
	void printEngineersRemoveTankTrap(const bool clearformess);
	void logADayPasses();
	void printYourLiberalsAreStarving(const bool clearformess);
	void printHasStarvedToDeath(const string pname, const bool clearformess);
	void printTheCopsAreComing(const bool clearformess);
	void printYouHaveEscaped();
	void printEscapeEngageInfo();
	void printEscapeEngageInfoFooter(const bool cameras, const bool traps);
	void logDefeat();
	void printConquerText(const bool police);
#endif	//SIEGE_CPP
#ifdef	SITEMAP_CPP
// sitemap.cpp

#include "../creature/newcreature.h"
#include "../locations/locations.h"
#include "../configfile.h"
// needed for something contained in sitemap.h
#include "../sitemode/sitemap.h"
		//own header
	void emptyEncounter();
	void delete_and_clear_groundloot();
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	map<int, int>  site_special_list = {
		map<int, int> ::value_type(SITE_INDUSTRY_NUCLEAR,           SPECIAL_NUCLEAR_ONOFF),
		map<int, int> ::value_type(SITE_GOVERNMENT_POLICESTATION,   SPECIAL_POLICESTATION_LOCKUP),
		map<int, int> ::value_type(SITE_GOVERNMENT_COURTHOUSE,      SPECIAL_COURTHOUSE_LOCKUP),
		map<int, int> ::value_type(SITE_GOVERNMENT_PRISON,          SPECIAL_PRISON_CONTROL),
		map<int, int> ::value_type(SITE_GOVERNMENT_INTELLIGENCEHQ,  SPECIAL_INTEL_SUPERCOMPUTER),
		map<int, int> ::value_type(SITE_CORPORATE_HEADQUARTERS,     SPECIAL_CORPORATE_FILES),
		map<int, int> ::value_type(SITE_CORPORATE_HOUSE,            SPECIAL_HOUSE_PHOTOS),
		map<int, int> ::value_type(SITE_GOVERNMENT_ARMYBASE,        SPECIAL_ARMORY),
		map<int, int> ::value_type(SITE_MEDIA_AMRADIO,              SPECIAL_RADIO_BROADCASTSTUDIO),
		map<int, int> ::value_type(SITE_MEDIA_CABLENEWS,            SPECIAL_NEWS_BROADCASTSTUDIO),
	};
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern int oldMapMode;
	//PREP
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern unsigned long seed[RNG_SIZE];
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	const string CONST_sitemapC043 = "Export";

	const string CONST_sitemapB042 = "mapCSV_ApartmentIndustrial2_Tiles.csv";
	const string CONST_sitemapB041 = "3";
	const string CONST_sitemapB040 = "csv";
	const string CONST_sitemap039 = "ApartmentIndustrial2";
	const string CONST_sitemap038 = "2";
	const string CONST_sitemap037 = "mapCSV_ApartmentIndustrial_Tiles.csv";
	const string CONST_sitemap036 = "ApartmentIndustrial";
	const string CONST_sitemap035 = "mapCSV_[NAMEHERE]_Specials.csv";
	const string CONST_sitemap034 = "mapCSV_[NAMEHERE]_Tiles.csv";
	const string CONST_sitemap033 = "../art";
	const string CONST_sitemap032 = "csvTilemap.lua";
	const string CONST_sitemap031 = "Deadly Alien Map Editor";
	const string CONST_sitemap030 = "GENERIC_UNSECURE";

	const string tag_WEIGHT = "WEIGHT";
	const string tag_Z = "Z";
	const string tag_FREQ = "FREQ";
	const string tag_ZEND = "ZEND";
	const string tag_ZSTART = "ZSTART";
	const string tag_Y = "Y";
	const string tag_YEND = "YEND";
	const string tag_YSTART = "YSTART";
	const string tag_X = "X";
	const string tag_XEND = "XEND";
	const string tag_XSTART = "XSTART";
	const string tag_STAIRS_RANDOM = "STAIRS_RANDOM";
	const string tag_STAIRS = "STAIRS";
	const string tag_HALLWAY_YAXIS = "HALLWAY_YAXIS";
	const string tag_ROOM = "ROOM";
	const string tag_SUBTRACT = "SUBTRACT";
	const string tag_ADD = "ADD";
	const string tag_NOTE = "NOTE";
	const string tag_LOOT = "LOOT";
	const string tag_UNIQUE = "UNIQUE";
	const string tag_SPECIAL = "SPECIAL";
	const string tag_SCRIPT = "SCRIPT";
	const string tag_TILE = "TILE";
	const string tag_USE = "USE";
	const string tag_NAME = "NAME";
	const string tag_SITEMAP = "SITEMAP";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";
#endif	//SITEMAP_CPP
#ifdef	SITEMODE_CPP
// sitemode.cpp

#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
//#include "cursesgraphics.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../basemode/baseactions.h"
// for orderparty
#include "../basemode/reviewmode.h"
#include "advance.h"
//#include "sitemode/mapspecials.h"
	void special_bouncer_assess_squad();
	void special_bouncer_greet_squad();
	void special_lab_cosmetics_cagedanimals();
	void special_readsign(int sign);
	void special_nuclear_onoff();
	void special_lab_genetic_cagedanimals();
	void special_policestation_lockup();
	void special_courthouse_lockup();
	void special_courthouse_jury();
	void special_prison_control(short prison_control_type);
	void special_intel_supercomputer();
	void special_sweatshop_equipment();
	void special_polluter_equipment();
	void special_house_photos();
	void special_corporate_files();
	void special_radio_broadcaststudio();
	void special_news_broadcaststudio();
	void special_graffiti();
	void special_armory();
	void special_display_case();
	void special_security_checkpoint();
	void special_security_metaldetectors();
	void special_security_secondvisit();
	void special_bank_teller();
	void special_bank_money();
	void special_bank_vault();
	void special_ccs_boss();
	void special_oval_office();
#include "stealth.h"
#include "miscactions.h"
	void reloadparty(bool wasteful = false);
#include "sitedisplay.h"
	//#include "sitemode/newencounter.h"
	void prepareencounter(short type, char sec);
	char addsiegeencounter(char type);
#include "../items/lootTypePoolItem.h"
//#include "../log/log.h"
	// for commondisplay.h
#include "../common/commondisplay.h"
// for printparty()
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
// for squadsize
#include "../common/translateid.h"
// for  id_getcar
//#include "common/equipment.h"
/* review squad equipment */
	void equip(vector<Item *> &loot, int loc);
	//#include "daily/daily.h"
	/* daily - returns true if the site type supports high security */
	char securityable(int type);
#include "../daily/siege.h"
	//for void conquertext();
#include "../combat/fight.h"
#include "../combat/fightCreature.h"  
//for void enemyattack();
#include "../combat/haulkidnap.h"
#include "../combat/haulkidnapCreature.h"
//for void kidnapattempt();
#include "../combat/chase.h"
//for void makechasers(long sitetype,long sitecrime);

	int getEncounterAnimalGloss(const int e);
	bool get_encounter_cantbluff_is_zero(const int e);
	bool get_encounter_cantbluff_is_two(const int e);
	bool get_encounter_cantbluff_is_one(const int e);
	bool isThereASiteAlarm();
	void setSiteAlarmOne();
	bool isThereNoActivesquad();
	void resetSiteAlarm();
//#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../set_color_support.h"
#include "../common/creaturePoolCreature.h"
#include "../locations/locationsPool.h"
#include "../common/creaturePool.h"
#include "../common/musicClass.h"
	extern bool encounterwarnings;
	extern bool mapshowing;
	extern char ccs_kills;
	extern char endgamestate;
	extern char foughtthisround;
	extern char showcarprefs;
	extern chaseseqst chaseseq;
	extern coordinatest loc_coord;
	extern Deprecatednewsstoryst *sitestory;
	extern Deprecatedsquadst *activesquad;
	extern int ccs_boss_kills;
	extern int sitecrime;
	//extern Log gamelog;
	extern MusicClass music;
	extern short fieldskillrate;
	extern short lawList[LAWNUM];
	extern short mode;
	extern short offended_amradio;
	extern short offended_cablenews;
	extern short party_status;
	extern short postalarmtimer;
	extern short sitealarmtimer;
	extern short sitealienate;
	extern short sitetype;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern UniqueCreatures uniqueCreatures;
	extern vector<Item *> groundloot;

	void emptyEncounter();
	void delete_and_clear_groundloot();
	bool isThereGroundLoot();

	void deleteVehicle(int carid);
	void deleteVehicles(vector<Vehicle *>& carid);
	enum INDEX_WITH_SPECIAL_MEANING {
		MULTIPLE_LIVING_MEMBERS = -2,
		NO_VALID_MEMBERS = -1,
	};
	vector<NameAndAlignment> getEncounterNameAndAlignment();
	char haveActiveSquadTalk(const int sp, const int tk);
	void printActiveSquadTalkOptions();
	bool activeSquadMemberIsAliveAndExists(const int sp);
	CantBluffAnimal encounterGetCantBluffAnimal(const int t);
	CreatureBio encounterGetCreatureBio(const int t);
	vector<NameAndAlignment> getEncounterNameAndAlignment();
	int checkForPeopleWhoCanRecruit();
	void addNewRecruit(int i, int e);
	int countactivesquadhostages();
	void assembleActiveSquad();
	/* base - review - assemble a squad */
	void criminalizeEncounterPrisonerEscape(const int e);
	void duplicateEncounterMember(const int e);
	void unpersonLastEncounterMember();
	void getRandomLoot(int cursite);
	Weapon* spawnNewWeapon(string newWeaponType);
	Armor* spawnNewArmor(string newArmorType);

	void giveActiveSquadThisLoot(Item* de);
	void putBackSpecials(const int olocx, const int olocy, const int olocz);
	void spawnCreatureCEO();

	void killActiveSquad();
	int getactivesquadCarID(const int p);
	void set_sitestory_type();
	int getactivesquadBase();


	char shouldWeBailOnBase();
	bool isActiveSquadAnonymous();
	void set_site_story_as_last_news_story();
	void setSiteStoryClaimedZero();
	void resetSiteGlobals();
	void setCurrentSite(const short i);
	void resetCCSSiegeGlobals();

	int getEncounterCarID(const int e);
	int getEncounterIsDriver(const int e);
	extern chaseseqst chaseseq;
	const string tag_WEAPON = "WEAPON";
	const string tag_WEAPON_FLAMETHROWER = "WEAPON_FLAMETHROWER";
	const string tag_LOOT = "LOOT";
	const string tag_LOOT_COMPUTER = "LOOT_COMPUTER";
	const string tag_LOOT_CHEAPJEWELERY = "LOOT_CHEAPJEWELERY";
	const string tag_LOOT_TRINKET = "LOOT_TRINKET";
	const string tag_LOOT_SILVERWARE = "LOOT_SILVERWARE";
	const string tag_LOOT_CELLPHONE = "LOOT_CELLPHONE";
	const string tag_ARMOR_CIVILLIANARMOR = "ARMOR_CIVILLIANARMOR";
	const string tag_ARMOR_SECURITYUNIFORM = "ARMOR_SECURITYUNIFORM";
	const string tag_ARMOR_ARMYARMOR = "ARMOR_ARMYARMOR";
	const string tag_ARMOR = "ARMOR";
	const string tag_ARMOR_HEAVYARMOR = "ARMOR_HEAVYARMOR";
	const string tag_ARMOR_CHEAPSUIT = "ARMOR_CHEAPSUIT";
	const string tag_ARMOR_WORKCLOTHES = "ARMOR_WORKCLOTHES";
	const string tag_ARMOR_CLOTHES = "ARMOR_CLOTHES";
	const string tag_ARMOR_TRENCHCOAT = "ARMOR_TRENCHCOAT";
	const string tag_WEAPON_AUTORIFLE_M16 = "WEAPON_AUTORIFLE_M16";
	const string tag_WEAPON_SMG_MP5 = "WEAPON_SMG_MP5";
	const string tag_WEAPON_CARBINE_M4 = "WEAPON_CARBINE_M4";
	const string tag_WEAPON_REVOLVER_38 = "WEAPON_REVOLVER_38";
	const string tag_WEAPON_REVOLVER_44 = "WEAPON_REVOLVER_44";
	const string tag_WEAPON_SEMIPISTOL_9MM = "WEAPON_SEMIPISTOL_9MM";
	const string tag_WEAPON_SEMIPISTOL_45 = "WEAPON_SEMIPISTOL_45";
	const string tag_LOOT_PDA = "LOOT_PDA";
	const string tag_LOOT_MICROPHONE = "LOOT_MICROPHONE";
	const string tag_LOOT_CABLENEWSFILES = "LOOT_CABLENEWSFILES";
	const string tag_LOOT_AMRADIOFILES = "LOOT_AMRADIOFILES";
	const string tag_LOOT_FAMILYPHOTO = "LOOT_FAMILYPHOTO";
	const string tag_LOOT_WATCH = "LOOT_WATCH";
	const string tag_ARMOR_BONDAGEGEAR = "ARMOR_BONDAGEGEAR";
	const string tag_ARMOR_EXPENSIVESUIT = "ARMOR_EXPENSIVESUIT";
	const string tag_ARMOR_EXPENSIVEDRESS = "ARMOR_EXPENSIVEDRESS";
	const string tag_LOOT_CORPFILES = "LOOT_CORPFILES";
	const string tag_LOOT_CHEMICAL = "LOOT_CHEMICAL";
	const string tag_LOOT_FINECLOTH = "LOOT_FINECLOTH";
	const string tag_ARMOR_BUNKERGEAR = "ARMOR_BUNKERGEAR";
	const string tag_LOOT_SECRETDOCUMENTS = "LOOT_SECRETDOCUMENTS";
	const string tag_WEAPON_SHANK = "WEAPON_SHANK";
	const string tag_ARMOR_PRISONER = "ARMOR_PRISONER";
	const string tag_LOOT_JUDGEFILES = "LOOT_JUDGEFILES";
	const string tag_LOOT_POLICERECORDS = "LOOT_POLICERECORDS";
	const string tag_ARMOR_POLICEARMOR = "ARMOR_POLICEARMOR";
	const string tag_ARMOR_SWATARMOR = "ARMOR_SWATARMOR";
	const string tag_ARMOR_POLICEUNIFORM = "ARMOR_POLICEUNIFORM";
	const string tag_ARMOR_DEATHSQUADUNIFORM = "ARMOR_DEATHSQUADUNIFORM";
	const string tag_WEAPON_SHOTGUN_PUMP = "WEAPON_SHOTGUN_PUMP";
	const string tag_WEAPON_NIGHTSTICK = "WEAPON_NIGHTSTICK";
	const string tag_LOOT_LABEQUIPMENT = "LOOT_LABEQUIPMENT";
	const string tag_LOOT_RESEARCHFILES = "LOOT_RESEARCHFILES";
	const string tag_LOOT_EXPENSIVEJEWELERY = "LOOT_EXPENSIVEJEWELERY";
	const string tag_ARMOR_BLACKROBE = "ARMOR_BLACKROBE";
	const string tag_ARMOR_LABCOAT = "ARMOR_LABCOAT";
	const string tag_ARMOR_BLACKDRESS = "ARMOR_BLACKDRESS";
	const string tag_ARMOR_BLACKSUIT = "ARMOR_BLACKSUIT";
	const string tag_WEAPON_SEMIRIFLE_AR15 = "WEAPON_SEMIRIFLE_AR15";
	const string tag_WEAPON_COMBATKNIFE = "WEAPON_COMBATKNIFE";
	const string tag_WEAPON_BASEBALLBAT = "WEAPON_BASEBALLBAT";
	const string tag_WEAPON_DAISHO = "WEAPON_DAISHO";
	const string tag_ARMOR_CLOWNSUIT = "ARMOR_CLOWNSUIT";
	const string tag_ARMOR_DONKEYSUIT = "ARMOR_DONKEYSUIT";
	const string tag_ARMOR_ELEPHANTSUIT = "ARMOR_ELEPHANTSUIT";
	const string tag_ARMOR_CHEAPDRESS = "ARMOR_CHEAPDRESS";
	const string tag_WEAPON_GUITAR = "WEAPON_GUITAR";
	const string tag_LOOT_DIRTYSOCK = "LOOT_DIRTYSOCK";
	const string tag_LOOT_KIDART = "LOOT_KIDART";
	const string tag_ARMOR_TOGA = "ARMOR_TOGA";
	const string tag_WEAPON_SPRAYCAN = "WEAPON_SPRAYCAN";
	const string tag_WEAPON_SYRINGE = "WEAPON_SYRINGE";
	const string tag_WEAPON_CHAIN = "WEAPON_CHAIN";
	const string tag_WEAPON_CROWBAR = "WEAPON_CROWBAR";
	//const string tag_X = "X";
	extern MusicClass music;
	extern bool mapshowing;
	extern bool encounterwarnings;

	extern Deprecatedsquadst *activesquad;

	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern Deprecatedsquadst *activesquad;
	extern char showcarprefs;
	const string rndWeps[] = { tag_WEAPON_SEMIPISTOL_9MM, tag_WEAPON_SEMIPISTOL_45, tag_WEAPON_REVOLVER_38, tag_WEAPON_REVOLVER_44,
	tag_WEAPON_SMG_MP5, tag_WEAPON_CARBINE_M4, tag_WEAPON_AUTORIFLE_M16 };
	const string rndArmors[] = { tag_ARMOR_CHEAPSUIT, tag_ARMOR_CLOTHES, tag_ARMOR_TRENCHCOAT, tag_ARMOR_WORKCLOTHES,
		tag_ARMOR_SECURITYUNIFORM, tag_ARMOR_CIVILLIANARMOR, tag_ARMOR_ARMYARMOR, tag_ARMOR_HEAVYARMOR };
	void printMap(const bool has_cameras);
	void printLocationSpecificWarning(const int lsite, const bool ccsRent);
	void printLocationNameAndAlarm(const string lname, const int postalarmtimer, const int locz);
	void printCONSERVATIVES_SUSPICIOUS();
	void printCONSERVATIVES_ALARMED();
	void printALIENATED_EVERYONE();
	void printALIENATED_MASSES();
	void printCONSERVATIVE_REINFORCEMENTS_INCOMING();
	void printSiegeName(const string sname, const int locz);
	bool isPrisoner(const string tkname);
	void printEnemyCar(const string cname, const int v);
	void printClearChaseScreen();
	void printEnemyCarPassenger(const string ename, const int vnum, const int pnum, const bool driver);
	void printReflectOnIneptitude();
	void printSneakOrRun(const bool evade);
	void printReorganize(const int libnum); 
	void printReleaseHostages(const bool hostages);
	void printReleaseOppressed();
	void printEquipAndFight(const bool enemy);
	void printEvade();
	void printUseOrGraffiti(const bool graffiti, const bool print_me);
	void printPlayerSiteOptions(const bool isThereASiteAlarm, const bool enemy, const int partysize, const int party_status, const bool talkers);
	void printShowEncounterWarning(const int numenc, const bool squadmoved);
	void printTheLandlordIsIn();
	void printTheLandlordIsOut();
	void printTheCEOIsIn();
	void printTheCEOIsOut();
	void printTheCEOHasFled();
	void printEmptyBench();
	void printFullBench();
	void printRestaurantTableFull();
	void printRestaurantTableHiding();
	void printCafeComputerEmpty();
	void printCafeComputerFull();
	void printTheCCSIsBroken();
	void logBailOnBase(const string aname, const string sitename);
	void printFoughtOffConservatives();
	void printSneakPast();
	void printYouFind(const string that_thing);
	void printFreeThem(const int followers);
	void printYouHaveEnemiesFirst();
	void printFreeThemWithoutYou(const int followers, const int actgot);
	void printIWontTalkToYou(const string tkname);
	void printCreatureEncounter(const int t, const int talign, const string tname, const string tage);
	void printToWhom();
	void printActiveSquadTalkOptionsHeader();
	void printMusicEnabled(const bool musice);
	void printEncounterWarnings(const bool ewarn);
	void printSitemodeOptions();
	void printSitemodeOptionsHeader();
	void printWhichWay();
	void printSquadSubduedHostagesFreed(const int hostages);
	void printItOpensWithAlarm();
	void printVaultIsImpenetrable();
	void printUnlockedButAlarmed(const bool locked);
	void printShakeHandle(const bool locked, const bool has_security);
	void printLockpickPrompt();
	void printLockSetOffAlarm();
	void printAlarmGoesOff();
#endif	//SITEMODE_CPP
#ifdef	SLEEPER_UPDATE_CPP
// sleeper_update.cpp

#include "../creature/creature.h"
#include "../locations/locations.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
//#include "sitemode/newencounter.h"
	void prepareencounter(short type, char sec);
#include "../items/lootTypePoolItem.h"
	//#include "common/commonactions.h"
	void change_public_opinion(int v, int power, char affect = 1, char cap = 100);
#include "../common/commonactionsCreature.h"
//#include "../log/log.h"
#include "../common/translateid.h"
	// for  int getloottype(int id);
//#include "../cursesAlternative.h"
//#include "../set_color_support.h"
#include "../common/creaturePoolCreature.h"
#include "../locations/locationsPool.h"
	extern short attitude[VIEWNUM];
	extern short lawList[LAWNUM];
	extern CCSexposure ccsexposure;
	extern short lawList[LAWNUM];
	extern class Ledger ledger;
	//extern Log gamelog;
	extern short lawList[LAWNUM];
	extern char disbanding;


	const string tag_LOOT = "LOOT";
	const string tag_LOOT_COMPUTER = "LOOT_COMPUTER";
	const string tag_LOOT_PDA = "LOOT_PDA";
	const string tag_LOOT_CELLPHONE = "LOOT_CELLPHONE";
	const string tag_LOOT_SECRETDOCUMENTS = "LOOT_SECRETDOCUMENTS";
	const string tag_ARMOR_BLACKSUIT = "ARMOR_BLACKSUIT";
	const string tag_ARMOR = "ARMOR";
	const string tag_WEAPON = "WEAPON";
	const string tag_WEAPON_CARBINE_M4 = "WEAPON_CARBINE_M4";
	const string tag_WEAPON_SHOTGUN_PUMP = "WEAPON_SHOTGUN_PUMP";
	const string tag_WEAPON_AUTORIFLE_M16 = "WEAPON_AUTORIFLE_M16";
	const string tag_WEAPON_SMG_MP5 = "WEAPON_SMG_MP5";
	const string tag_LOOT_SILVERWARE = "LOOT_SILVERWARE";
	const string tag_LOOT_CHEMICAL = "LOOT_CHEMICAL";
	const string tag_ARMOR_ARMYARMOR = "ARMOR_ARMYARMOR";
	const string tag_LOOT_POLICERECORDS = "LOOT_POLICERECORDS";
	const string tag_ARMOR_POLICEARMOR = "ARMOR_POLICEARMOR";
	const string tag_ARMOR_SWATARMOR = "ARMOR_SWATARMOR";
	const string tag_ARMOR_POLICEUNIFORM = "ARMOR_POLICEUNIFORM";
	const string tag_ARMOR_DEATHSQUADUNIFORM = "ARMOR_DEATHSQUADUNIFORM";
	const string tag_WEAPON_SEMIRIFLE_AR15 = "WEAPON_SEMIRIFLE_AR15";
	const string tag_WEAPON_SEMIPISTOL_45 = "WEAPON_SEMIPISTOL_45";
	const string tag_LOOT_MICROPHONE = "LOOT_MICROPHONE";
	const string tag_LOOT_CABLENEWSFILES = "LOOT_CABLENEWSFILES";
	const string tag_LOOT_AMRADIOFILES = "LOOT_AMRADIOFILES";
	const string tag_LOOT_FAMILYPHOTO = "LOOT_FAMILYPHOTO";
	const string tag_LOOT_CHEAPJEWELERY = "LOOT_CHEAPJEWELERY";
	const string tag_LOOT_WATCH = "LOOT_WATCH";
	const string tag_LOOT_TRINKET = "LOOT_TRINKET";
	const string tag_LOOT_CORPFILES = "LOOT_CORPFILES";
	const string tag_LOOT_FINECLOTH = "LOOT_FINECLOTH";
	const string tag_WEAPON_SHANK = "WEAPON_SHANK";
	const string tag_LOOT_JUDGEFILES = "LOOT_JUDGEFILES";
	const string tag_LOOT_LABEQUIPMENT = "LOOT_LABEQUIPMENT";
	const string tag_LOOT_RESEARCHFILES = "LOOT_RESEARCHFILES";
	const string tag_LOOT_EXPENSIVEJEWELERY = "LOOT_EXPENSIVEJEWELERY";
	const string tag_LOOT_DIRTYSOCK = "LOOT_DIRTYSOCK";
	const string tag_LOOT_KIDART = "LOOT_KIDART";
	const string tag_LOOT_CCS_BACKERLIST = "LOOT_CCS_BACKERLIST";
	const string tag_LOOT_PRISONFILES = "LOOT_PRISONFILES";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";


	map<CreatureTypes, vector<CreatureSkill> > skill_influence = {
		map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_CRITIC_ART,
			{ SKILL_WRITING, SKILL_ART }),
			map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_PAINTER,
				{ SKILL_ART }),
				map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_SCULPTOR,
					{ SKILL_ART }),
					map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_CRITIC_MUSIC,
						{ SKILL_WRITING, SKILL_MUSIC }),
						map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_MUSICIAN,
							{ SKILL_MUSIC }),
							map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_AUTHOR,
								{ SKILL_WRITING }),
								map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_JOURNALIST,
									{ SKILL_WRITING }),
									map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_JUDGE_CONSERVATIVE,
										{ SKILL_WRITING, SKILL_LAW }),
										map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_LAWYER,
											{ SKILL_LAW }),
											map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_SCIENTIST_LABTECH,
												{ SKILL_SCIENCE }),
												map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_SCIENTIST_EMINENT,
													{ SKILL_SCIENCE }),
													map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_CORPORATE_CEO,
														{ SKILL_BUSINESS }),
														map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_CORPORATE_MANAGER,
															{ SKILL_BUSINESS }),
															map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_PRIEST,
																{ SKILL_RELIGION }),
																map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_NUN,
																	{ SKILL_RELIGION }),
																	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_EDUCATOR,
																		{ SKILL_PSYCHOLOGY }),
	};
	map<CreatureTypes, int> super_sleepers_multiplier = {
		map<CreatureTypes, int> ::value_type(CREATURE_CORPORATE_CEO, 20),
		map<CreatureTypes, int> ::value_type(CREATURE_POLITICIAN, 20),
		map<CreatureTypes, int> ::value_type(CREATURE_SCIENTIST_EMINENT, 20),
		map<CreatureTypes, int> ::value_type(CREATURE_DEATHSQUAD, 6),
		map<CreatureTypes, int> ::value_type(CREATURE_EDUCATOR, 6),
		map<CreatureTypes, int> ::value_type(CREATURE_MILITARYOFFICER, 6),
		map<CreatureTypes, int> ::value_type(CREATURE_ACTOR, 4),
		map<CreatureTypes, int> ::value_type(CREATURE_GANGUNIT, 4),
		map<CreatureTypes, int> ::value_type(CREATURE_MILITARYPOLICE, 4),
		map<CreatureTypes, int> ::value_type(CREATURE_SEAL, 4),
	};

	map<CreatureTypes, vector<Views> > creature_influences_views = {

		/* Cultural leaders block - influences cultural issues */
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_PRIEST,
			{ VIEW_WOMEN,
			VIEW_CIVILRIGHTS,
			VIEW_GAY,
			VIEW_FREESPEECH,
			VIEW_DRUGS,
			VIEW_IMMIGRATION }
			),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_PAINTER,
			{ VIEW_WOMEN,
			VIEW_CIVILRIGHTS,
			VIEW_GAY,
			VIEW_FREESPEECH,
			VIEW_DRUGS,
			VIEW_IMMIGRATION }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SCULPTOR,
			{ VIEW_WOMEN,
			VIEW_CIVILRIGHTS,
			VIEW_GAY,
			VIEW_FREESPEECH,
			VIEW_DRUGS,
			VIEW_IMMIGRATION }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_AUTHOR,
			{ VIEW_WOMEN,
			VIEW_CIVILRIGHTS,
			VIEW_GAY,
			VIEW_FREESPEECH,
			VIEW_DRUGS,
			VIEW_IMMIGRATION }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_JOURNALIST,
			{ VIEW_WOMEN,
			VIEW_CIVILRIGHTS,
			VIEW_GAY,
			VIEW_FREESPEECH,
			VIEW_DRUGS,
			VIEW_IMMIGRATION }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_PSYCHOLOGIST,
			{ VIEW_WOMEN,
			VIEW_CIVILRIGHTS,
			VIEW_GAY,
			VIEW_FREESPEECH,
			VIEW_DRUGS,
			VIEW_IMMIGRATION }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_MUSICIAN,
			{ VIEW_WOMEN,
			VIEW_CIVILRIGHTS,
			VIEW_GAY,
			VIEW_FREESPEECH,
			VIEW_DRUGS,
			VIEW_IMMIGRATION }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_CRITIC_ART,
			{ VIEW_WOMEN,
			VIEW_CIVILRIGHTS,
			VIEW_GAY,
			VIEW_FREESPEECH,
			VIEW_DRUGS,
			VIEW_IMMIGRATION }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_CRITIC_MUSIC,
			{ VIEW_WOMEN,
			VIEW_CIVILRIGHTS,
			VIEW_GAY,
			VIEW_FREESPEECH,
			VIEW_DRUGS,
			VIEW_IMMIGRATION }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_ACTOR,
			{ VIEW_WOMEN,
			VIEW_CIVILRIGHTS,
			VIEW_GAY,
			VIEW_FREESPEECH,
			VIEW_DRUGS,
			VIEW_IMMIGRATION }
		),
		/* Legal block - influences an array of social issues */
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_JUDGE_CONSERVATIVE,
			{ VIEW_JUSTICES,
			VIEW_FREESPEECH,
			VIEW_INTELLIGENCE,
			VIEW_POLICEBEHAVIOR,
			VIEW_DEATHPENALTY,
			VIEW_GUNCONTROL,
			VIEW_DRUGS }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_LAWYER,
			{ VIEW_POLICEBEHAVIOR,
			VIEW_DEATHPENALTY,
			VIEW_GUNCONTROL,
			VIEW_DRUGS }
		),
		/* Scientists block */
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SCIENTIST_EMINENT,
			{ VIEW_POLLUTION,
			VIEW_NUCLEARPOWER,
			VIEW_ANIMALRESEARCH,
			VIEW_GENETICS }
		),


		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SCIENTIST_LABTECH,
			{ VIEW_NUCLEARPOWER,
			VIEW_ANIMALRESEARCH,
			VIEW_GENETICS }
		),
		/* Corporate block */
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_CORPORATE_CEO,
			{ VIEW_CEOSALARY,
			VIEW_WOMEN,
			VIEW_TAXES,
			VIEW_CORPORATECULTURE,
			VIEW_SWEATSHOPS,
			VIEW_POLLUTION,
			VIEW_CIVILRIGHTS }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_CORPORATE_MANAGER,
			{ VIEW_WOMEN,
			VIEW_TAXES,
			VIEW_CORPORATECULTURE,
			VIEW_SWEATSHOPS,
			VIEW_POLLUTION,
			VIEW_CIVILRIGHTS }
		),
		/* Law enforcement block */
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_DEATHSQUAD,
			{ VIEW_PRISONS,
			VIEW_DEATHPENALTY,
			VIEW_POLICEBEHAVIOR,
			VIEW_DRUGS,
			VIEW_TORTURE,
			VIEW_GUNCONTROL,
			VIEW_PRISONS }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SWAT,
			{ VIEW_POLICEBEHAVIOR,
			VIEW_DRUGS,
			VIEW_TORTURE,
			VIEW_GUNCONTROL,
			VIEW_PRISONS }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_COP,
			{ VIEW_POLICEBEHAVIOR,
			VIEW_DRUGS,
			VIEW_TORTURE,
			VIEW_GUNCONTROL,
			VIEW_PRISONS }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_GANGUNIT,
			{ VIEW_POLICEBEHAVIOR,
			VIEW_DRUGS,
			VIEW_TORTURE,
			VIEW_GUNCONTROL,
			VIEW_PRISONS }
		),
		/* Prison block */
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_EDUCATOR,
			{ VIEW_POLICEBEHAVIOR,
			VIEW_DEATHPENALTY,
			VIEW_DRUGS,
			VIEW_TORTURE,
			VIEW_PRISONS }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_PRISONGUARD,
			{ VIEW_POLICEBEHAVIOR,
			VIEW_DEATHPENALTY,
			VIEW_DRUGS,
			VIEW_TORTURE,
			VIEW_PRISONS }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_PRISONER,
			{ VIEW_POLICEBEHAVIOR,
			VIEW_DEATHPENALTY,
			VIEW_DRUGS,
			VIEW_TORTURE,
			VIEW_PRISONS }
		),
		/* Intelligence block */
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SECRET_SERVICE,
			{ VIEW_INTELLIGENCE }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_AGENT,
			{ VIEW_INTELLIGENCE,
			VIEW_TORTURE,
			VIEW_PRISONS,
			VIEW_FREESPEECH }
		),
		/* Military block */
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_MERC,
			{ VIEW_GUNCONTROL }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SOLDIER,
			{ VIEW_MILITARY,
			VIEW_TORTURE,
			VIEW_GAY,
			VIEW_WOMEN }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_VETERAN,
			{ VIEW_MILITARY,
			VIEW_TORTURE,
			VIEW_GAY,
			VIEW_WOMEN }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_MILITARYPOLICE,
			{ VIEW_MILITARY,
			VIEW_TORTURE,
			VIEW_GAY,
			VIEW_WOMEN }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_MILITARYOFFICER,
			{ VIEW_MILITARY,
			VIEW_TORTURE,
			VIEW_GAY,
			VIEW_WOMEN }
		),
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SEAL,
			{ VIEW_MILITARY,
			VIEW_TORTURE,
			VIEW_GAY,
			VIEW_WOMEN }
		),
		/* Sweatshop workers */
		map<CreatureTypes, vector<Views> > ::value_type(CREATURE_WORKER_SWEATSHOP,
			{ VIEW_IMMIGRATION,
			VIEW_SWEATSHOPS }
		),
};

void printCreatureLeaksIntelligence(const string crname);
void printCreatureLeaksPolice(const string crname);
void printCreatureLeaksCorp(const string crname);
void printCreatureLeaksPrison(const string crname);
void printCreatureLeaksCable(const string crname);
void printCreatureLeaksRadio(const string crname);
void printCreatureLeaksAnimalResearch(const string crname);
void printCreatureLeaksJudiciary(const string crname);
void printCreatureLeaksCCS(const string crname);
void printArrestedWhileEmbezzling(const string crname);
void printHasBeenCaughtSnooping(const string crname);
void printArrestedWhileStealing(const string crname);
void printSleeperDropOffPackage(const string crname);
void printxmlFail(const int numberofxmlfails);
void pressAnyKey();
#endif	//SLEEPER_UPDATE_CPP
#ifdef	STEALTH_CPP
// stealth.cpp

#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../sitemode/sitedisplay.h"
//#include "../log/log.h"
#include "../common/commonactionsCreature.h"
//#include "../cursesAlternative.h"
//#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../customMaps.h"
	short getCurrentSite();
	extern short fieldskillrate;
	/* checks if your liberal activity is noticed */

	/* checks if your liberal activity is noticed */
	char disguisesite(long type);

	vector<NameAndAlignment> getEncounterNameAndAlignment();
	bool isThereASiteAlarm();
	void setSiteAlarmOne();
	//extern Log gamelog;
	void conservatise(const int e);
	//extern Log gamelog;
	extern short mode;

	extern short sitealienate;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short lawList[LAWNUM];

	int get_stealth_difficulty(const int n);
	int get_disguise_difficulty(const int n);
	int get_encounter_time(const int n);
	vector<int> potentialEncounterNoticers();
	extern short fieldskillrate;
	//extern Log gamelog;
	extern short sitetype;

	extern coordinatest loc_coord;
	extern short sitealarmtimer;
	extern Deprecatedsquadst *activesquad;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];

	const string tag_ARMOR = "ARMOR";
	const string tag_ARMOR_BUNKERGEAR = "ARMOR_BUNKERGEAR";
	const string tag_ARMOR_SWATARMOR = "ARMOR_SWATARMOR";
	const string tag_ARMOR_DEATHSQUADUNIFORM = "ARMOR_DEATHSQUADUNIFORM";
	const string tag_ARMOR_POLICEARMOR = "ARMOR_POLICEARMOR";
	const string tag_ARMOR_POLICEUNIFORM = "ARMOR_POLICEUNIFORM";
	const string tag_ARMOR_EXPENSIVEDRESS = "ARMOR_EXPENSIVEDRESS";
	const string tag_ARMOR_EXPENSIVESUIT = "ARMOR_EXPENSIVESUIT";
	const string tag_ARMOR_SECURITYUNIFORM = "ARMOR_SECURITYUNIFORM";
	const string tag_ARMOR_CHEAPDRESS = "ARMOR_CHEAPDRESS";
	const string tag_ARMOR_CHEAPSUIT = "ARMOR_CHEAPSUIT";
	const string tag_ARMOR_SEALSUIT = "ARMOR_SEALSUIT";
	const string tag_ARMOR_ARMYARMOR = "ARMOR_ARMYARMOR";
	const string tag_ARMOR_MILITARY = "ARMOR_MILITARY";
	const string tag_ARMOR_SERVANTUNIFORM = "ARMOR_SERVANTUNIFORM";
	const string tag_ARMOR_HARDHAT = "ARMOR_HARDHAT";
	const string tag_ARMOR_CIVILLIANARMOR = "ARMOR_CIVILLIANARMOR";
	const string tag_ARMOR_LABCOAT = "ARMOR_LABCOAT";
	const string tag_ARMOR_WORKCLOTHES = "ARMOR_WORKCLOTHES";
	const string tag_ARMOR_BLACKDRESS = "ARMOR_BLACKDRESS";
	const string tag_ARMOR_BLACKSUIT = "ARMOR_BLACKSUIT";
	const string tag_ARMOR_OVERALLS = "ARMOR_OVERALLS";
	const string tag_ARMOR_PRISONER = "ARMOR_PRISONER";
	const string tag_ARMOR_PRISONGUARD = "ARMOR_PRISONGUARD";
	const string tag_ARMOR_BLACKROBE = "ARMOR_BLACKROBE";
	const string tag_ARMOR_HEAVYARMOR = "ARMOR_HEAVYARMOR";
	const string tag_ARMOR_WIFEBEATER = "ARMOR_WIFEBEATER";
	const string tag_WEAPON = "WEAPON";
	const string tag_WEAPON_CARBINE_M4 = "WEAPON_CARBINE_M4";
	const string tag_WEAPON_CHAIN = "WEAPON_CHAIN";
	const string tag_WEAPON_SHANK = "WEAPON_SHANK";
	const string tag_WEAPON_SHOTGUN_PUMP = "WEAPON_SHOTGUN_PUMP";
	const string tag_WEAPON_TORCH = "WEAPON_TORCH";
	const string tag_WEAPON_PITCHFORK = "WEAPON_PITCHFORK";
	const string tag_WEAPON_NIGHTSTICK = "WEAPON_NIGHTSTICK";
	const string tag_WEAPON_SMG_MP5 = "WEAPON_SMG_MP5";
	const string tag_WEAPON_FLAMETHROWER = "WEAPON_FLAMETHROWER";
	const string tag_WEAPON_AXE = "WEAPON_AXE";
	const string tag_WEAPON_SEMIRIFLE_AR15 = "WEAPON_SEMIRIFLE_AR15";
	const string tag_WEAPON_AUTORIFLE_M16 = "WEAPON_AUTORIFLE_M16";
	const string tag_WEAPON_SEMIPISTOL_45 = "WEAPON_SEMIPISTOL_45";
	const string tag_WEAPON_DESERT_EAGLE = "WEAPON_DESERT_EAGLE";
	const string tag_WEAPON_SEMIPISTOL_9MM = "WEAPON_SEMIPISTOL_9MM";
	const string tag_WEAPON_REVOLVER_38 = "WEAPON_REVOLVER_38";
	const string tag_WEAPON_REVOLVER_44 = "WEAPON_REVOLVER_44";
	const string tag_WEAPON_GAVEL = "WEAPON_GAVEL";
	const string tag_WEAPON_SYRINGE = "WEAPON_SYRINGE";
	const string tag_ARMOR_CLOTHES = "ARMOR_CLOTHES";
	const string tag_WEAPON_MP5_SMG = "WEAPON_MP5_SMG";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";

	map<short, map<string, int> > siegeDisguises = {
		map<SiegeTypes, map<string, int> >::value_type(SIEGE_CIA,
			{
				map<string, int>::value_type(tag_ARMOR_BLACKSUIT, 1),
				map<string, int>::value_type(tag_ARMOR_BLACKDRESS, 1)
			}
		),

		map<SiegeTypes, map<string, int> >::value_type(SIEGE_CORPORATE,
			{
				map<string, int>::value_type(tag_ARMOR_MILITARY,  1),
				map<string, int>::value_type(tag_ARMOR_ARMYARMOR,  1),
				map<string, int>::value_type(tag_ARMOR_SEALSUIT,  1),
			}
		),
		map<SiegeTypes, map<string, int> >::value_type(SIEGE_HICKS,
			{
				map<string, int>::value_type(tag_ARMOR_CLOTHES,  2),
				map<string, int>::value_type(tag_ARMOR_OVERALLS,  1),
				map<string, int>::value_type(tag_ARMOR_WIFEBEATER, 1),
			}
		),
		map<SiegeTypes, map<string, int> >::value_type(SIEGE_FIREMEN,
			{
				map<string, int>::value_type(tag_ARMOR_BUNKERGEAR, 1),
			}
	   ),
	};

	map<short, map<string, int> > siteDisguises = {

		map<SiteTypes, map<string, int> >::value_type(SITE_BUSINESS_CIGARBAR,{
		map<string, int>::value_type(tag_ARMOR_EXPENSIVESUIT,  1),
		map<string, int>::value_type(tag_ARMOR_CHEAPSUIT,  1),
		map<string, int>::value_type(tag_ARMOR_EXPENSIVEDRESS,  1),
		map<string, int>::value_type(tag_ARMOR_CHEAPDRESS,  1),
		map<string, int>::value_type(tag_ARMOR_BLACKSUIT,  1),
		map<string, int>::value_type(tag_ARMOR_BLACKDRESS,  1),
	}
	),
	map<SiteTypes, map<string, int> >::value_type(SITE_CORPORATE_HEADQUARTERS,{
		map<string, int>::value_type(tag_ARMOR_EXPENSIVESUIT,  1),
		map<string, int>::value_type(tag_ARMOR_CHEAPSUIT,  1),
		map<string, int>::value_type(tag_ARMOR_SECURITYUNIFORM,  1),
		map<string, int>::value_type(tag_ARMOR_EXPENSIVEDRESS,  1),
		map<string, int>::value_type(tag_ARMOR_CHEAPDRESS,  1),
	}
		),
	};
	map<short, map<string, int> > siteDisguisesRestricted = {

		map<SiteTypes, map<string, int> >::value_type(SITE_INDUSTRY_NUCLEAR,{
		map<string, int>::value_type(tag_ARMOR_LABCOAT,  1),
				map<string, int>::value_type(tag_ARMOR_SECURITYUNIFORM,  1),
				map<string, int>::value_type(tag_ARMOR_CIVILLIANARMOR,  1),
				map<string, int>::value_type(tag_ARMOR_HARDHAT,  1),

	}
	),
	map<SiteTypes, map<string, int> >::value_type(SITE_MEDIA_AMRADIO,{
		map<string, int>::value_type(tag_ARMOR_SECURITYUNIFORM,  1),
				map<string, int>::value_type(tag_ARMOR_EXPENSIVESUIT,  1),
				map<string, int>::value_type(tag_ARMOR_CHEAPSUIT,  1),
				map<string, int>::value_type(tag_ARMOR_EXPENSIVEDRESS,  1),
				map<string, int>::value_type(tag_ARMOR_CHEAPDRESS,  1),

	}
		),
	map<SiteTypes, map<string, int> >::value_type(SITE_MEDIA_CABLENEWS,{
		map<string, int>::value_type(tag_ARMOR_SECURITYUNIFORM,  1),
				map<string, int>::value_type(tag_ARMOR_EXPENSIVESUIT,  1),
				map<string, int>::value_type(tag_ARMOR_EXPENSIVEDRESS,  1),

	}
	),

	map<SiteTypes, map<string, int> >::value_type(SITE_GOVERNMENT_WHITE_HOUSE,{
		map<string, int>::value_type(tag_ARMOR_BLACKSUIT,  1),
				map<string, int>::value_type(tag_ARMOR_BLACKDRESS,  1),
				map<string, int>::value_type(tag_ARMOR_CHEAPSUIT,  1),
				map<string, int>::value_type(tag_ARMOR_CHEAPDRESS,  1),
				map<string, int>::value_type(tag_ARMOR_EXPENSIVESUIT,  1),
				map<string, int>::value_type(tag_ARMOR_EXPENSIVEDRESS,  1),
				map<string, int>::value_type(tag_ARMOR_MILITARY,  1),
				map<string, int>::value_type(tag_ARMOR_ARMYARMOR,  1),
				map<string, int>::value_type(tag_ARMOR_SEALSUIT,  1),

	}
	),
	map<SiteTypes, map<string, int> >::value_type(SITE_GOVERNMENT_ARMYBASE,{
		map<string, int>::value_type(tag_ARMOR_MILITARY,  1),
				map<string, int>::value_type(tag_ARMOR_ARMYARMOR,  1),
				map<string, int>::value_type(tag_ARMOR_SEALSUIT,  1),

	}
	),
	map<SiteTypes, map<string, int> >::value_type(SITE_GOVERNMENT_INTELLIGENCEHQ,{
		map<string, int>::value_type(tag_ARMOR_BLACKSUIT,  1),
				map<string, int>::value_type(tag_ARMOR_BLACKDRESS,  1),

	}
	),

	};

	void printShoutsForHelp(const string ename, const int ealign);
	bool isPrisoner(const string tkname);
	void printAlienation(const short sitealienate);
	void printFadesAway(const string aname, const int partysize);
	void printBlewStealthCheck(const string aname);
	void printActsNatural(const string aname, const int partysize);
	void printEnemyNameInAlarm(const string nname);
	void printLooksAtSquadSuspiciously();
	void printShoutsInAlarm();
	void printConservativeRaisesAlarm(const bool weapon, const int ntype, const int nalign);
	void pressAnyKey();
#endif	//STEALTH_CPP
#ifdef	STRINGCONVERSION_CPP
	// stringconversion.cpp

#include "../creature/creatureEnums.h"

	extern map<string, short> getCreatureEnumFromString;

	const string NONE = "NONE";
	const string tag_heavyweapons = "heavyweapons";
	const string tag_dodge = "dodge";
	const string tag_firstaid = "firstaid";
	const string tag_seduction = "seduction";
	const string tag_streetsense = "streetsense";
	const string tag_teaching = "teaching";
	const string tag_stealth = "stealth";
	const string tag_business = "business";
	const string tag_science = "science";
	const string tag_religion = "religion";
	const string tag_art = "art";
	const string tag_music = "music";
	const string tag_writing = "writing";
	const string tag_driving = "driving";
	const string tag_tailoring = "tailoring";
	const string tag_computers = "computers";
	const string tag_disguise = "disguise";
	const string tag_security = "security";
	const string tag_law = "law";
	const string tag_psychology = "psychology";
	const string tag_persuasion = "persuasion";
	const string tag_shotgun = "shotgun";
	const string tag_smg = "smg";
	const string tag_rifle = "rifle";
	const string tag_pistol = "pistol";
	const string tag_throwing = "throwing";
	const string tag_axe = "axe";
	const string tag_club = "club";
	const string tag_sword = "sword";
	const string tag_knife = "knife";
	const string tag_handtohand = "handtohand";
	const string tag_CLEAN = "CLEAN";
	const string tag_NASTY = "NASTY";
	const string tag_RANDOM = "RANDOM";
	const string tag_FEMALE_BIAS = "FEMALE BIAS";
	const string tag_FEMALE = "FEMALE";
	const string tag_MALE_BIAS = "MALE BIAS";
	const string tag_MALE = "MALE";
	const string tag_GENDER_WHITEMALEPATRIARCH = "GENDER_WHITEMALEPATRIARCH";
	const string tag_NEUTRAL = "NEUTRAL";
	const string tag_heart = "heart";
	const string tag_charisma = "charisma";
	const string tag_health = "health";
	const string tag_agility = "agility";
	const string tag_wisdom = "wisdom";
	const string tag_intelligence = "intelligence";
	const string tag_strength = "strength";
	const string tag_value = "value";
	const string tag_attribute = "attribute";
	const string tag_skill = "skill";
	const string tag_no = "no";
	const string tag_false = "false";
	const string tag_0 = "0";
	const string tag_off = "off";
	const string tag_on = "on";
	const string tag_yes = "yes";
	const string tag_1 = "1";
	const string tag_true = "true";

#endif	//STRINGCONVERSION_CPP
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

/*
daily.cpp
*/
/* active squad visits the arms dealer */
	void armsdealer(int loc);

#include "../combat/fight.h"
	// for void delenc(short e,char loot);
	//void delenc(Creature &tk);
	//void delenc(const int e, const int i);
#include "../combat/fightCreature.h"  
//for void capturecreature(Creature &t);
//#include "../cursesAlternative.h"
//#include "../set_color_support.h"
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

	short getCurrentSite();
	extern DeprecatedCreature encounter[ENCMAX];
	//extern string singleDot;
	void setSiteAlarmOne();
	void setEncounterZeroExistsFalse();
	void giveActiveSquadThisLoot(Item* de);

	extern Deprecatednewsstoryst *sitestory;
	extern int sitecrime;
	extern Deprecatedsquadst *activesquad;
	extern short sitealienate;

	extern string slogan_str;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short sitealarmtimer;
	void locationIsNowRented(int l, int rent);
	void basesquad(Deprecatedsquadst *st, long loc);
	//extern Log gamelog;
	extern char newscherrybusted;
	extern Deprecatedsquadst *activesquad;
	extern class Ledger ledger;
	//extern Log gamelog;
	//extern Log gamelog;
	int getCity(int l);
	void newDate(DeprecatedCreature &a, DeprecatedCreature &tk);
	//extern Log gamelog;
	extern short lawList[LAWNUM];
	void newRecruit(DeprecatedCreature *cr, int c);
	//extern Log gamelog;
	extern char newscherrybusted;
	extern short lawList[LAWNUM];
	vector<NameAndAlignment> getEncounterNameAndAlignment();
	int encounterWisdomRoll(const int e);
	//extern Log gamelog;
	extern Deprecatednewsstoryst *sitestory;
	extern short attitude[VIEWNUM];
	//extern Log gamelog;
	extern int sitecrime;
	extern short lawList[LAWNUM];
	extern Deprecatednewsstoryst *sitestory;
	extern Deprecatedsquadst *activesquad;
	extern short exec[EXECNUM];
	//extern Log gamelog;
	extern int sitecrime;
	extern short lawList[LAWNUM];
	extern Deprecatednewsstoryst *sitestory;
	extern Deprecatedsquadst *activesquad;
	extern short exec[EXECNUM];
	extern int sitecrime;
	//extern Log gamelog;
	extern short lawList[LAWNUM];
	extern Deprecatedsquadst *activesquad;
	int getDifficultyBasedOnEncounterWisdom(const int e);
	//extern Log gamelog;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short lawList[LAWNUM];
	extern coordinatest loc_coord;
	extern short siteonfire;
	extern short fieldskillrate;
	extern Deprecatednewsstoryst *sitestory;
	extern int sitecrime;
	extern coordinatest loc_coord;
	extern short fieldskillrate;

	extern short exec[EXECNUM];
	extern string slogan_str;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short lawList[LAWNUM];
	extern short attitude[VIEWNUM];

	extern short exec[EXECNUM];
	extern short siteonfire;
	extern Deprecatednewsstoryst *sitestory;
	extern string slogan_str;
	const int PICKUP_LINE_SIZE = 5;
	const int DOUBLE_LINE = 2;
	//extern Log gamelog;
	extern short lawList[LAWNUM];
	//extern Log gamelog;
	extern Deprecatedsquadst *activesquad;
	extern bool multipleCityMode;
	extern char ccs_kills;
	vector<vector<string> > no_free_speech_flirt;
	vector<vector<string> > pickupLines;
	vector<vector<string> > lovingly_talk_to_mutant;
	vector<vector<string> > normal_talk_to_mutant;
	vector<vector<string> > lovingly_talk_to_dog;
	vector<vector<string> > normal_talk_to_dog;

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
	bool isPrisoner(const string tkname);


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
				//SITE_GOVERNMENT_FIRESTATION,
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

	void printTalkAboutIssuesHeader(const string aname);
	void printTalkAboutIssuesWhenStupid(const int lw);
	void printTalkAboutIssuesTooLiberal(const int lw);
	void printTalkAboutIssuesNormal(const int lw, const int tkanimalgloss);
	void printTurnsAway();
	void printConservativeRespondsToStupid(const int tktype, const bool extraline);
	void printRespondantName(const string tkname, const bool extraline);
	void printConservativeCounter(const bool extraline, const int lw);
	void printRejectTalk(const bool extraline);
	void printMutantTalkAboutIssues(const string tkname, const int extraline);
	void printThatIsDisturbing(const string tkname, const bool extraline, const int special_case);
	void printUnableToSpeakAgree(const string tkname, const bool extraline);
	void printAgreesToComeByLater(const string tkname, const bool extraline, const bool another_extraline);
	void printSpecialRecruitment(const string aname, const string tkname, const string pitch, const string response);
	void printTalkOptionsDuringCombat(const bool hostages, const bool is_cantbluff_two, const bool cop);
	void printTalksToThem(const string aname, const int tkalign, const string tkname);

	void liberalizeEncounterIfThisType(const int type);

	void printTheSquadIsArrested();
	void printTheEnemyIsFooled();
	void printXeIsNotFooled(const string ename);
	void printITalkLikeAConservative(const string aname);
	void printEngraveElbereth(const string aname);
	void printDeathSquadBluff();
	void printLabCoatBluff();
	void printPoliceBluff();
	void printBunkerGearBluff();
	void printWeWerentBornYesterday(const string ename);
	void printSiegeBluff(const string aname, const int siegeType);
	void printEnemyIgnoresThreat(const string tkname);
	void printHowShouldWeRespond(const string aname, const int hostages);
	void printPloyWorksEnemyBacksOff();
	void printExecutionGunshot();
	void printExecutionBareHands();
	void printDiscardsBody(const string aname, const string pname);
	void printAnotherOneBacksOff(const string ename);
	void printThreatenEnemy(const string aname);
	void printHostageNegotiation(const string ename, const int etype, const int ealign, const int hostages);
	void printThreatenHostages(const string aname);
	void printReleaseHostagesHeader(const string ename);
	void printReleaseHostagesFooter(const int hostages);
	void printEnemyAllowsHostagesToDie(const string ename);
	void printLetUsGoAndTheyGoFree(const string aname, const int hostages);
	void printEnemyWatchesHostageDeath(const string ename);
	void printAcceptsPickupLine(const string aname, const string tkname, const vector<string> selected_flirt);
	void printRejectsPickupLine(const string tkname, const int tktype, const int agender_liberal, const vector<string> selected_flirt);
	void printSaysWhat(const string tkname);
	void printTurnsAway(const string tkname, const int tkalign);
	void printRejectPolicePickupLine(const string tkname, const bool extraline);
	void printPickupLine(const string aname, const vector<string> selected_flirt);
	void printNonHumanRejection(const string tkname, const int tktype, const bool extraline);
	void printAnimalDoesntUnderstand(const string tkname, const int tktype);
	void printWannaHearSomething(const string aname);
	void printLetMeSellYouAGun(const string tkname);
	void printNotHereDummy(const string tkname);
	void printWaitUntilItCoolsDown(const string tkname);
	void printIDontSellToCops(const string tkname);
	void printIDontSellToNaked(const string tkname);
	void printINeedAGun(const string aname);
	void printJesusItsYours(const string tkname);
	void printIWantYouToLeave(const string tkname);
	void printGiveMeTheLCSPrice(const string aname);
	void printThreatensWithAGun(const string aname, const string aweapon);
	void printRefuseRentDeal(const string aname);
	void printNotMyProblem(const string tkname);
	void printAcceptRentHeader(const string aname);
	void printAcceptRentFooter(const string tkname);
	void printRentingOptions(const bool cannotAfford);
	void printINeedThisMuchRent(const string tkname, const int rent);
	void printPutSomeDamnClothesOn(const string tkname);
	void printIWantToRent(const string aname);
	void printClearOutYourRoom(const string tkname);
	void printYourPossessionsAreRelocated();
	void printIWantToCancelRent(const string aname);
	void printTalkToPotentialLandlord(const bool is_naked);
	void printTalkToLandlord(const bool is_naked);
	void printTalkToGangMemberOrMerc(const bool is_naked);
	void printTalkToBankTeller(const bool is_naked);
	void printTalkToHeader(const string aname);
	void printTalkToMiddle(const int tkalign, const string tkname, const string tkbio);
	void printTalkToFooter(const bool is_naked, const bool can_date);
	void printBankerCooperates();
	void printTheVaultIsOpen();
	void printGuardsCloseIn();
	void printDemandVaultBeOpened(const string aname);
	void printBrandishWeapon(const string aname, const string aweapon);
	void printTellerComplies();
	void printTellerAlertsCops();
	void printIRobTheBank(const string aname);
	void printOptionsWithinBank(const bool is_naked);
	void pressAnyKey();
	int getkeyAlt();
	int pressSpecificKey(const int x, const int y);
	int pressSpecificKey(const int x, const int y, const int z);
#endif	// TALK_CPP
#ifdef	TITLESCREEN_CPP
// titlescreen.cpp
#include "../common/commondisplay.h"

#include "../title/titlescreen.h"
	void mode_base();
	//#include "../common/consolesupport.h"
// for addstr
#include "../common/getnames.h"
// for enter_name
#include "../title/highscore.h"
//for void viewhighscores
#include "../title/newgame.h"
//for void setup_newgame();
//#include "../title/saveload.h"
	bool file_exists(const std::string& filename);
	char load(const string& filename);
	void savegame(const string& filename);
	string title_screen::savefile_name;
	vector<string> title_screen::s_savefiles;
//#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
//#include "../set_color_support.h"
	/* end the game and clean up */
	void end_game(int err = EXIT_SUCCESS);
#include "../creature/creatureEnums.h"
#include "../customMaps.h"
	void automatedDataTests();
	extern short mode;
#include "../common/musicClass.h"
	extern MusicClass music;
	void printSaveHeader(const bool to_delete);
	void printSaveList(const int page, const vector<string> s_savefiles);
	void printSaveFooter(const bool to_delete);
	void printAreYouSure(const string s_savefiles);
	void printMusicFooter(const bool musicEnabled);

	void printTitleScreen();
	string printNewGameHeader();
	void pressAnyKey();
	int getkeyAlt(); 
	bool is_page_up(const int c);
	bool is_page_down(const int c);
#endif	//TITLESCREEN_CPP
#ifdef	VEHICLE_CPP
// vehicle.cpp

	const string vehicleSportsCar = "SPORTSCAR";
	const string CONST_vehicle007 = "Stolen ";

	const string tag_id = "id";
	const string tag_myear = "myear";
	const string tag_location = "location";
	const string tag_color = "color";
	const string tag_vtypeid = "vtypeid";
	const string tag_vtypeidname = "vtypeidname";
	const string tag_vehicle = "vehicle";

#endif	//VEHICLE_CPP
#ifdef	VEHICLETYPE_CPP
	//vehicletype.cpp

#include "../creature/creatureEnums.h"
#include "vehicletype.h"
#include "../common/stringconversion.h"
	extern int year;
	const string CONST_vehicletypeB061 = ": ";
	const string CONST_vehicletypeB060 = "::stealing: ";
	const string CONST_vehicletypeB055 = "::colors: ";
	const string CONST_vehicletypeB054 = "::year: ";
	const string CONST_vehicletypeB053 = "UNDEF";
	const string CONST_vehicletype063 = "Unknown element for vehicle type ";
	const string CONST_vehicletype062 = "::available_at_dealership: ";
	const string CONST_vehicletype061 = "Invalid boolean value for vehicle type ";
	const string CONST_vehicletype054 = "::colors::display_color: ";
	const string CONST_vehicletype051 = "::year::add_random_up_to_current_year: ";
	const string CONST_vehicletype049 = "::year::start_at_current_year: ";
	const string CONST_vehicletype047 = "LACKS IDNAME ";
	const string CONST_vehicletype046 = "UNDEFINED";

	const string tag_window = "window";
	const string tag_body = "body";
	const string tag_Translucent = "Translucent";
	const string tag_sleeperprice = "sleeperprice";
	const string tag_price = "price";
	const string tag_available_at_dealership = "available_at_dealership";
	const string tag_armor = "armor";
	const string tag_armor_midpoint = "armor_midpoint";
	const string tag_high_armor_max = "high_armor_max";
	const string tag_high_armor_min = "high_armor_min";
	const string tag_low_armor_max = "low_armor_max";
	const string tag_low_armor_min = "low_armor_min";
	const string tag_touch_alarm_chance = "touch_alarm_chance";
	const string tag_sense_alarm_chance = "sense_alarm_chance";
	const string tag_extra_heat = "extra_heat";
	const string tag_juice = "juice";
	const string tag_difficulty = "difficulty";
	const string tag_difficulty_to_find = "difficulty_to_find";
	const string tag_stealing = "stealing";
	const string tag_shortname = "shortname";
	const string tag_longname = "longname";
	const string tag_passenger = "passenger";
	const string tag_driver = "driver";
	const string tag_attackbonus = "attackbonus";
	const string tag_attack = "attack";
	const string tag_hardlimit = "hardlimit";
	const string tag_softlimit = "softlimit";
	const string tag_skillfactor = "skillfactor";
	const string tag_skill = "skill";
	const string tag_base = "base";
	const string tag_dodgebonus = "dodgebonus";
	const string tag_dodge = "dodge";
	const string tag_drivebonus = "drivebonus";
	const string tag_display_color = "display_color";
	const string tag_color = "color";
	const string tag_colors = "colors";
	const string tag_add = "add";
	const string tag_add_random = "add_random";
	const string tag_add_random_up_to_current_year = "add_random_up_to_current_year";
	const string tag_start_at_year = "start_at_year";
	const string tag_start_at_current_year = "start_at_current_year";
	const string tag_year = "year";
	const string tag_idname = "idname";
	const string tag_id = "id";

#endif	//VEHICLETYPE_CPP
#ifdef	WEAPON_CPP
// weapon.cpp

#include "../creature/creatureEnums.h"
#include "../items/itemtype.h"
#include "../items/item.h"
#include "../items/cliptype.h"
#include "../items/clip.h"
#include "../items/weapontype.h"
#include "../items/weapon.h"

#include "../common/translateid.h"
// for getweapontype

	extern vector<WeaponType *> weapontype;

	const string CONST_weaponB004 = ")";
	const string CONST_weapon003 = " (";

	const string tag_ammo = "ammo";
	const string tag_loaded_cliptype = "loaded_cliptype";
	const string tag_weapon = "weapon";

#endif	//WEAPON_CPP
#ifdef	WEAPONTYPE_CPP
	// weapontype.cpp
#include "../creature/creatureEnums.h"
#include "../items/itemtype.h"
#include "../items/cliptype.h"
#include "../items/weapontype.h"

#include "../common/stringconversion.h"

	extern int year;
	extern int year;
	extern short lawList[LAWNUM];

	const string CONST_weapontypeB091 = "striking";
	const string CONST_weapontype099 = "UNDEF";
	const string CONST_weapontype098 = "INVALID SUBTYPE";
	const string CONST_weapontype096 = "Unknown element for attack: ";
	const string CONST_weapontype095 = "Unknown element for attack::fire: ";
	const string CONST_weapontype094 = "Unknown element for attack::critical: ";
	const string CONST_weapontype093 = "Invalid severtype for attack::critical::severtype: ";
	const string CONST_weapontype092 = "Invalid boolean value for attack::damages_armor: ";
	const string CONST_weapontype091 = "Invalid severtype for attack::severtype: ";
	const string CONST_weapontype090 = "Invalid boolean value for attack::bleeding: ";
	const string CONST_weapontype089 = "Invalid boolean value for attack::shoots: ";
	const string CONST_weapontype088 = "Invalid boolean value for attack::burns: ";
	const string CONST_weapontype087 = "Invalid boolean value for attack::cuts: ";
	const string CONST_weapontype086 = "Invalid boolean value for attack::tears: ";
	const string CONST_weapontype085 = "Invalid boolean value for attack::bruises: ";
	const string CONST_weapontype084 = "Invalid skill name for attack::skill: ";
	const string CONST_weapontype083 = "Invalid boolean value for attack::always_describe_hit: ";
	const string CONST_weapontype082 = "Invalid boolean value for attack::thrown ";
	const string CONST_weapontype081 = "Invalid boolean value for attack::ranged ";
	const string CONST_weapontype080 = "assaults";
	const string CONST_weapontype078 = ": ";
	const string CONST_weapontype077 = "Unknown element for weapon type ";
	const string CONST_weapontype076 = "::suspicious: ";
	const string CONST_weapontype075 = "Invalid boolean value for weapon type ";
	const string CONST_weapontype074 = "::auto_break_locks: ";
	const string CONST_weapontype072 = "::graffiti: ";
	const string CONST_weapontype070 = "::instrument: ";
	const string CONST_weapontype068 = "::musical_attack: ";
	const string CONST_weapontype066 = "::threatening: ";
	const string CONST_weapontype064 = "::can_take_hostages: ";

	const string tag_chance_causes_debris = "chance_causes_debris";
	const string tag_chance = "chance";
	const string tag_fire = "fire";
	const string tag_severtype = "severtype";
	const string tag_fixed_damage = "fixed_damage";
	const string tag_random_damage = "random_damage";
	const string tag_hits_required = "hits_required";
	const string tag_critical = "critical";
	const string tag_no = "no";
	const string tag_no_DR_for_limbs_chance = "no_damage_reduction_for_limbs_chance";
	const string tag_armor = "armor";
	const string tag_armorpiercing = "armorpiercing";
	const string tag_damages_armor = "damages_armor";
	const string tag_bleeding = "bleeding";
	const string tag_shoots = "shoots";
	const string tag_burns = "burns";
	const string tag_cuts = "cuts";
	const string tag_tears = "tears";
	const string tag_bruises = "bruises";
	const string tag_strength = "strength";
	const string tag_strength_max = "strength_max";
	const string tag_strength_min = "strength_min";
	const string tag_successive_attacks_difficulty = "successive_attacks_difficulty";
	const string tag_number_attacks = "number_attacks";
	const string tag_accuracy_bonus = "accuracy_bonus";
	const string tag_skill = "skill";
	const string tag_hit_punctuation = "hit_punctuation";
	const string tag_always_describe_hit = "always_describe_hit";
	const string tag_hit_description = "hit_description";
	const string tag_attack = "attack";
	const string tag_attack_description = "attack_description";
	const string tag_ammotype = "ammotype";
	const string tag_ammo = "ammo";
	const string tag_can_backstab = "can_backstab";
	const string tag_thrown = "thrown";
	const string tag_ranged = "ranged";
	const string tag_priority = "priority";
	const string tag_size = "size";
	const string tag_suspicious = "suspicious";
	const string tag_auto_break_locks = "auto_break_locks";
	const string tag_bashstrengthmod = "bashstrengthmod";
	const string tag_legality = "legality";
	const string tag_graffiti = "graffiti";
	const string tag_instrument = "instrument";
	const string tag_music = "music";
	const string tag_musical_attack = "musical_attack";
	const string tag_protects_against_kidnapping = "protects_against_kidnapping";
	const string tag_can_threaten_hostages = "can_threaten_hostages";
	const string tag_threatening = "threatening";
	const string tag_can_take_hostages = "can_take_hostages";
	const string tag_shortname_future = "shortname_future";
	const string tag_shortname = "shortname";
	const string tag_shortname_future_sub_2 = "shortname_future_sub_2";
	const string tag_shortname_future_sub_1 = "shortname_future_sub_1";
	const string tag_shortname_sub_2 = "shortname_sub_2";
	const string tag_shortname_sub_1 = "shortname_sub_1";
	const string tag_name_future = "name_future";
	const string tag_name = "name";
	const string tag_name_future_sub_2 = "name_future_sub_2";
	const string tag_name_future_sub_1 = "name_future_sub_1";
	const string tag_name_sub_2 = "name_sub_2";
	const string tag_name_sub_1 = "name_sub_1";
#endif	//WEAPONTYPE_CPP
#endif // INCLUDES_H_INCLUDED