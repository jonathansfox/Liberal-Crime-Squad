/*
    File created by Chris Johnson.
    These were previously all in game.cpp.

    This file includes all the the enums, defines, and included headers required globally by all components.

    All code released under GNU GPL.
*/
#ifndef INCLUDES_H_INCLUDED
#define INCLUDES_H_INCLUDED0
#define __USE_MINGW_ANSI_STDIO 0
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

extern char* PACKAGE_VERSION;

const int version = 41207;
const int lowestloadversion=40100;
const int lowestloadscoreversion=31203;

#include "common.h" /* include this prior to checking if WIN32 is defined */

#include "lcsio.h"
#include "compat.h"
#include "cursesgraphics.h"



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

enum BashTypes
{
   BASH_DOOR,
   BASHNUM
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

enum endgame
{
   ENDGAME_NONE,
   ENDGAME_CCS_APPEARANCE,
   ENDGAME_CCS_ATTACKS,
   ENDGAME_CCS_SIEGES,
   ENDGAME_CCS_DEFEATED,
   ENDGAME_MARTIALLAW,
   ENDGAMENUM
};

enum ccsexposure
{
   CCSEXPOSURE_NONE,
   CCSEXPOSURE_LCSGOTDATA,
   CCSEXPOSURE_EXPOSED,
   CCSEXPOSURE_NOBACKERS,
   CCSEXPOSURENUM
};
// IsaacG FOR THE LOVE OF GOD RENAME THIS VARIABLE
extern char ccsexposure;

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
 * each law will be associated with a "heat" value,
 * indicating how much that particular crime draws
 * police attention to the wanted person, and to the
 * LCS as a whole. This is a global array, available
 * at runtime and indexed to the lawflag enum, so that
 * code can dynamically look up these heat values as
 * needed at runtime.
 */


enum BusinessFronts
{
   BUSINESSFRONT_INSURANCE,
   BUSINESSFRONT_TEMPAGENCY,
   BUSINESSFRONT_RESTAURANT,
   BUSINESSFRONT_MISCELLANEOUS,
   BUSINESSFRONTNUM
};

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
   VIEW_STALIN=-2, // this one is -2 and is actually calculated based on views >=0 and <VIEWNUM-3
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
   LAW_STALIN=-2, // not a real law: this is -2 and is actually calculated based on views >=0 and <VIEWNUM-3
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

enum RecruitTasks
{
   TASK_NONE,
   TASK_COMMUNITYSERVICE,
   TASK_ACTIVISM,
   TASK_CRIMES,
   TASK_BUYWEAPON,
   TASK_ARRESTED,
   TASKNUM
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

enum ReportTypes
{
   REPORT_NEWS,
   REPORT_OPINION,
   REPORT_ATTACK,
   REPORTNUM
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

enum TalkModes
{
   TALKMODE_START,
   TALKMODE_RENTING,
   TALKMODE_ISSUES,
   TALKMODENUM
};

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


#include "common/musicClass.h"

//#include "vehicle/vehicletype.h"
//#include "vehicle/vehicle.h"


//just a float that is initialized to 0
struct float_zero
{
	float_zero() : n(0.0f) { }
	operator float&() { return n; }
	float n;
};
//Interrogation information for the interrogation system, to be
//dynamically created on capture and deleted when interrogation ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
struct interrogation
{
	interrogation() : druguse(0) { techniques[0] = 1, techniques[1] = 1, techniques[2] = 0, techniques[3] = 0, techniques[4] = 0, techniques[5] = 0; }
	bool techniques[6]; //yesterday's interrogation plan
	int druguse; //total days of drug use
				 //Maps individual characters to the rapport built with them
	map<long, struct float_zero> rapport;
};

struct activityst
{
	activityst() : type(0), arg(0), arg2(0) { }
	int type;
	long arg, arg2;
	// return a reference to arg, with arg typecast as a pointer to an object of type interrogation,
	// allowing us to easily access and modify the interrogation data without typecasting outside this function
	interrogation* &intr() { interrogation** i = reinterpret_cast<interrogation**>(&arg); return *i; }
};

#include "creature/creature.h"

#endif // INCLUDES_H_INCLUDED
