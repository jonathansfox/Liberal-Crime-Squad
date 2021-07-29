




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


const int BIT1 = (1 << 0);
const int BIT2 = (1 << 1);
const int BIT3 = (1 << 2);
const int BIT4 = (1 << 3);
const int BIT5 = (1 << 4);
const int BIT6 = (1 << 5);
const int BIT7 = (1 << 6);
const int BIT8 = (1 << 7);
const int BIT9 = (1 << 8);

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

//#define CH_USE_CP437




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



enum AnimalGlosses
{
	ANIMALGLOSS_NONE,//IMPORTANT THAT THIS BE HERE AT ZERO
	ANIMALGLOSS_TANK,
	ANIMALGLOSS_ANIMAL,
	ANIMALGLOSSNUM
};




enum CarChaseObstacles
{
	CARCHASE_OBSTACLE_FRUITSTAND,
	CARCHASE_OBSTACLE_TRUCKPULLSOUT,
	CARCHASE_OBSTACLE_CROSSTRAFFIC,
	CARCHASE_OBSTACLE_CHILD,
	CARCHASE_OBSTACLENUM
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
void havingSleepers(char& clearformess, char canseethings, int(&libpower)[VIEWNUM]);

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

const int SQUAD_NAMELEN = 40;


/*
   Declarations for every function grouped by folder and file.
   Created by jonathansfox.
*/

/* This is declared again lower down, just needed here for this header. */
std::string tostring(long i);

//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

//int get_associated_attribute(int skill_type);


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


//#ifdef	MAPSPECIALS_CPP
// mapspecials.cpp

#include "../creature/creature.h"
////

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

void addjuice(DeprecatedCreature& cr, long juice, long cap);

#include "../common/translateid.h"
// for  int getloottype(int id);
void enemyattack();
#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
char run_broadcast(bool tv_broadcast);
#include "../common/creaturePool.h"
#include "../common/creaturePoolHeader.h"
void setEncounterZeroExistsFalse();
extern bool deagle;
extern bool m249;
extern CCSexposure ccsexposure;
extern char endgamestate;
extern coordinatest loc_coord;
extern DeprecatedCreature encounter[ENCMAX];
extern Deprecatednewsstoryst *sitestory;
extern Deprecatedsquadst *activesquad;
extern int sitecrime;
extern Log gamelog;
extern short lawList[LAWNUM];
extern short mode;
extern short postalarmtimer;
extern short sitealarmtimer;
extern short sitealienate;
extern short sitetype;
extern siteblockst levelmap[MAPX][MAPY][MAPZ];
extern vector<ClipType *> cliptype;
extern vector<WeaponType *> weapontype;
void giveActiveSquadMoney(const int money);
void spawnPresident();

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
void make_creature_without_encounter_array(const int x, const short type);
void emptyEncounter();
void fillEncounter(CreatureTypes c, int numleft);
#include "../customMaps.h"
#include "../items/lootTypePoolItem.h"
//#endif//MAPSPECIALS_CPP
//#endif// INCLUDES_H_INCLUDED
