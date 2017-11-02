/*
File created by Chris Johnson.
These were previously all in game.cpp.
This file includes all the the enums, defines, and included headers required globally by all components.
All code released under GNU GPL.
*/
#ifndef INCLUDES_H_INCLUDED
#define INCLUDES_H_INCLUDED
///
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
//PACKAGE_VERSION must be defined here or the game won't compile on Windows! Don't remove it!!!
// -- yetisyny
extern char* PACKAGE_VERSION;
const int version = 40124;
const int lowestloadversion = 40100;
const int lowestloadscoreversion = 31203;
#include "common.h" /* include this prior to checking if WIN32 is defined */
#include "lcsio.h"
#include "compat.h"
#include "cursesmovie.h"
#include "cursesgraphics.h"
#include "politics/law.h"
#include "politics/alignment.h"
#ifndef NDEBUG
#define NDEBUG
#endif
#define TAB 9
#define ENTER 10
#define ESC 27
#define SPACEBAR 32
class Log;


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
#define ENCMAX 18
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
class MusicClass
{
private:
	bool enabled;
#ifndef DONT_INCLUDE_SDL
	bool songsinitialized;
	bool oggsupport;
	int musicmode, previous;
	Mix_Music* songs[MUSIC_OFF];
	/* helper function for initsongs() ... implemented in misc.cpp */
	void loadsong(int i, const char* filename);
#endif // DONT_INCLUDE_SDL
public:
#ifndef DONT_INCLUDE_SDL
	MusicClass() : enabled(true), songsinitialized(false), oggsupport(true), musicmode(MUSIC_OFF), previous(MUSIC_OFF) { }
#else
	MusicClass() : enabled(true) { }
#endif // DONT_INCLUDE_SDL
	/* find out if music's enabled or disabled */
	bool isEnabled() { return enabled; }
	/* enable or disable music */
	void enableIf(bool e)
	{
		enabled = e;
#ifndef DONT_INCLUDE_SDL
		Mix_VolumeMusic(enabled*(MIX_MAX_VOLUME / 2)); // half volume if music enabled, muted if music disabled
#endif // DONT_INCLUDE_SDL
	}
	/* initialize SDL, SDL_mixer, and songs ... implemented in misc.cpp */
	void init();
	/* shut down SDL, SDL_mixer, and songs ... implemented in misc.cpp */
	void quit();
	/* play music specified by a MusicMode ... implemented in misc.cpp */
	void play(int _musicmode);
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

#define SLOGAN_LEN 80
struct highscorest
{
	char valid, endtype, slogan[SLOGAN_LEN];
	int month, year, stat_recruits, stat_kidnappings, stat_dead, stat_kills, stat_funds, stat_spent, stat_buys, stat_burns;
};
#define SCORENUM 5
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
#define HOUSENUM 435
// just over half of house (50%+1) - to pass bills
#define HOUSEMAJORITY 218
// 3/5 of house - has no significance other than in seeing if you won game
#define HOUSECOMFYMAJORITY 261
// 2/3 of house - to override veto or pass constitutional amendment
#define HOUSESUPERMAJORITY 290
// full senate (100%) - for looping thru full senate
#define SENATENUM 100
// just over half of senate(50%+1) - to bass bills
#define SENATEMAJORITY 51
// 3/5 of senate - to break filibuster in real world, but in game, has no significance other than seeing if you won
#define SENATECOMFYMAJORITY 60
// 2/3 of senate - to override veto or pass constitutional amendment
#define SENATESUPERMAJORITY 67
// full court (100%) - for looping thru full court
#define COURTNUM 9
// just over half of court (50%+1) - to make majority rulings
#define COURTMAJORITY 5
// 2/3 of court - has no significance other than seeing if you won game
#define COURTSUPERMAJORITY 6
// all states (100%) - for looping thru all states
#define STATENUM 50
// 3/4 of states (75%) - needed to pass constitutional amendments
#define STATESUPERMAJORITY 38
#define POLITICIAN_NAMELEN 80
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

#define SQUAD_NAMELEN 40
#define ARMORFLAG_DAMAGED BIT1
#define ARMORFLAG_BLOODY BIT2
/*******************************************************************************
*
*                             Logging Stuff
*                             Folder: "log"
*
*******************************************************************************/
//TODO: Make NEWLINEMODE_LOGFILES_DEFAULT, NEWLINEMODE_GAMELOG, and OVERWRITE_GAMELOG set by the cfg.
//Whether or not it should autonewline logfiles by default.
#define NEWLINEMODE_LOGFILES_DEFAULT 1
//Whether or not it should autonewline the gamelog.
#define NEWLINEMODE_GAMELOG 2
//Whether or not it should overwrite the gamelog every time the game starts.
#define OVERWRITE_GAMELOG false
//The filepath of the gamelog.
//TODO: Make this be set via the cfg.
#define GAMELOG_FILEPATH "gamelog.txt"
#include "log/log.h"

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
enum IncomeType         // the below names are used in fundreport() in lcsmonthly.cpp
{                       // new types added without updating fundreport() will show as "Other Income"
	INCOME_BROWNIES,     // "Brownies"
	INCOME_CARS,         // "Car Sales"
	INCOME_CCFRAUD,      // "Credit Card Fraud"
	INCOME_DONATIONS,    // "Donations"
	INCOME_SKETCHES,     // "Drawing Sales"
	INCOME_EMBEZZLEMENT, // "Embezzlement"
	INCOME_EXTORTION,    // "Extortion"
	INCOME_HUSTLING,     // "Hustling"
	INCOME_PAWN,         // "Pawning Goods"
	INCOME_PROSTITUTION, // "Prostitution"
	INCOME_BUSKING,      // "Street Music"
	INCOME_THIEVERY,     // "Thievery"
	INCOME_TSHIRTS,      // "T-Shirt Sales"
	INCOMETYPENUM        // # of types of income
};
enum ExpenseType          // the below names are used in fundreport() in lcsmonthly.cpp
{                         // new types added without updating fundreport() will show as "Other Expenses"
	EXPENSE_TROUBLEMAKING, // "Activism"
	EXPENSE_CONFISCATED,   // "Confiscated"
	EXPENSE_DATING,        // "Dating"
	EXPENSE_SKETCHES,      // "Drawing Materials"
	EXPENSE_FOOD,          // "Groceries"
	EXPENSE_HOSTAGE,       // "Hostage Tending"
	EXPENSE_LEGAL,         // "Legal Fees"
	EXPENSE_MANUFACTURE,   // "Manufacturing"
	EXPENSE_CARS,          // "New Cars"
	EXPENSE_SHOPPING,      // "Purchasing Goods"
	EXPENSE_RECRUITMENT,   // "Recruitment"
	EXPENSE_RENT,          // "Rent"
	EXPENSE_COMPOUND,      // "Safehouse Investments"
	EXPENSE_TRAINING,      // "Training"
	EXPENSE_TRAVEL,        // "Travel"
	EXPENSE_TSHIRTS,       // "T-Shirt Materials"
	EXPENSETYPENUM         // # of types of expenses
};

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
class Ledger
{
private:
	int funds;
public:
	int income[INCOMETYPENUM], expense[EXPENSETYPENUM], total_income, total_expense, dailyIncome[INCOMETYPENUM], dailyExpense[EXPENSETYPENUM];
	Ledger() : funds(7), total_income(0), total_expense(0)
	{
		for (int i = 0; i<INCOMETYPENUM; i++) income[i] = 0, dailyIncome[i] = 0;
		for (int e = 0; e<EXPENSETYPENUM; e++) expense[e] = 0, dailyExpense[e] = 0;
	}
	int get_funds() { return funds; }
	void force_funds(int amount) { funds = amount; }
	void add_funds(int amount, int incometype)
	{
		funds += amount,
			income[incometype] += amount,
			dailyIncome[incometype] += amount,
			total_income += amount;
	}
	void subtract_funds(int amount, int expensetype)
	{
		funds -= amount,
			expense[expensetype] += amount,
			dailyExpense[expensetype] += amount,
			total_expense += amount;
	}
	void resetMonthlyAmounts()
	{
		for (int i = 0; i<INCOMETYPENUM; i++) income[i] = 0;
		for (int e = 0; e<EXPENSETYPENUM; e++) expense[e] = 0;
	}
	void resetDailyAmounts()
	{
		for (int i = 0; i<INCOMETYPENUM; i++) dailyIncome[i] = 0;
		for (int e = 0; e<EXPENSETYPENUM; e++) dailyExpense[e] = 0;
	}
};
class Interval
{
public:
	int min, max;
	Interval() : min(0), max(0) { }
	Interval(int value) : min(value), max(value) { }
	Interval(int low, int high) : min(low), max(high) { }
	void set_interval(int low, int high) { min = low, max = high; }
	// Sets the interval according to a string that is either a number or two
	// number separated by a dash. Returns false and does not change the
	// interval if the given string is not a valid interval.
	bool set_interval(const string& interval); // implemented in misc.cpp
	int roll() const { return LCSrandom(max - min + 1) + min; }
private:
	// Checks if a string is a number. Assumes non-numeric characters other
	// than dashes have already been checked for.
	bool valid(const string& v)
	{
		return len(v) &&                       // Blank string is invalid.
			(len(v) != 1 || v[0] != '-') &&        // Just a dash is invalid.
			v.find('-', 1) == string::npos;
	} // A dash after the first char is invalid.
};
/*
Declarations for every function grouped by folder and file.
Created by jonathansfox.
*/
/* This is declared again lower down, just needed here for this header. */
std::string tostring(long i);
/* end the game and clean up */
void end_game(int err = EXIT_SUCCESS);

#include "items/itemtype.h"
#include "items/cliptype.h"
#include "items/weapontype.h"
#include "items/armortype.h"
#include "items/loottype.h"
#include "items/item.h"
#include "items/clip.h"
#include "items/weapon.h"
#include "items/armor.h"
#include "items/loot.h"
#include "items/money.h"
#include "creature/creature.h"
#include "creature/creaturetype.h"
#include "creature/augmentation.h"
#include "creature/augmenttype.h"
#include "vehicle/vehicletype.h"
#include "vehicle/vehicle.h"
#include "locations/locations.h"
#include "configfile.h"
#include "sitemode/sitemap.h"
struct squadst
{
	char name[SQUAD_NAMELEN];
	Creature *squad[6];
	activityst activity;
	int id;
	vector<Item *> loot;
	char stance; // Squad's site action stance: high profile, low profile, etc.
	squadst()
	{
		for (int p = 0; p<6; p++) squad[p] = NULL;
		strcpy(name, "");
		activity.type = ACTIVITY_NONE, id = -1, stance = SQUADSTANCE_STANDARD;
	}
	~squadst() { delete_and_clear(loot); }
};
struct recruitst
{
	long recruiter_id;
	Creature* recruit;
	short timeleft;
	char level, eagerness1, task;
	recruitst();
	~recruitst();
	char eagerness();
};
struct chaseseqst
{
	long location;
	vector<Vehicle *> friendcar, enemycar;
	char canpullover;
	void clean() { delete_and_clear(enemycar); friendcar.clear(); }
};

/*******************************************************************************
*
*                                Common Stuff
*                                Folder: "common"
*
*******************************************************************************/
/*
commondisplay.cpp
*/
void set_color(short f, short b, bool bright, bool blink = false);
#include "common\\commondisplay.h"
/*
commonactions.cpp
*/
#include "common\\commonactions.h"
/*
consolesupport.cpp
*/
#include "common\\consolesupport.h"
/*
getnames.cpp
*/
#include "common\\getnames.h"
/*
translateid.cpp
*/
#include "common\\translateid.h"
/*
equipment.cpp
*/
#include "common\\equipment.h"
/*
stringconversion.cpp
*/
#include "common\\stringconversion.h"
/*
creature.cpp
*/
#include "common\\creature.h"
/*******************************************************************************
*
*                             Title Screen and New Game
*                             Folder: "title"
*
*******************************************************************************/
/*
highscore.cpp
*/
#include "title\\highscore.h"
/*******************************************************************************
*
*                        The Main Game Screen: Base Mode
*                        Folder: "basemode"
*
*******************************************************************************/
/*
activate_sleepers.cpp
*/
#include "basemode\\activate_sleepers.h"
/*
activate.cpp
*/
#include "basemode\\activate.h"
/*
reviewmode.cpp
*/
#include "basemode\\reviewmode.h"
/*******************************************************************************
*
*                             Fighting Evil: Site Mode
*                             Folder: "sitemode"
*
*******************************************************************************/
/*
sitemode.cpp
*/
#include "sitemode\\sitemode.h"
/*
newencounter.cpp
*/
#include "sitemode\\newencounter.h"
/*
talk.cpp
*/
/* bluff, date, issues */
char talk(Creature &a, int t);
/*
stealth.cpp
*/
#include "sitemode\\stealth.h"
/*
advance.cpp
*/
/* handles end of round stuff for everyone */
void creatureadvance();
/* handles end of round stuff for one creature */
void advancecreature(Creature &cr);
/*******************************************************************************
*
*                        Combat and Chase Sequences
*                        Folder: "combat"
*
*******************************************************************************/
/*
fight.cpp
*/
#include "combat\\fight.h"
/*
chase.cpp
*/
#include "combat\\chase.h"
/*
haulkidnap.cpp
*/
#include "combat\\haulkidnap.h"
/*******************************************************************************
*
*              End of Day Events
*              Folder: "daily"
*
*******************************************************************************/
/*
daily.cpp
*/
#include "daily\\daily.h"
/*
activities.cpp
*/
#include "daily\\activities.h"
/*
date.cpp
*/

struct datest
{
	long mac_id;
	vector<Creature *> date;
	short timeleft;
	int city;
	datest() : timeleft(0) { }
	~datest() { delete_and_clear(date); }
};
/* daily - date - dater p gets back from vacation */
char completevacation(datest &d, int p, char &clearformess);
/* daily - date - dater p goes on some dates */
char completedate(datest &d, int p, char &clearformess);
/*
recruit.cpp
*/
/* automatic finding recruits from the activity screen */
char recruitment_activity(Creature &cr, char &clearformess);
/* daily - recruit - recruit meeting*/
char completerecruitmeeting(recruitst &d, int p, char &clearformess);
/*
siege.cpp
*/
#include "daily\\siege.h"
/*******************************************************************************
*
*                             End of Day News Stories
*                             Folder: "news"
*
*******************************************************************************/
struct newsstoryst
{
	short type, view;
	char claimed;
	short politics_level, violence_level;
	Creature *cr;
	vector<int> crime;
	long loc, priority, page, guardianpage;
	char positive;
	short siegetype;
	newsstoryst() : claimed(1), politics_level(0), violence_level(0), cr(NULL), loc(-1) { }
};
/* news - determines the priority of a news story */
void setpriority(newsstoryst &ns);
/* news - show major news story */
void displaystory(newsstoryst &ns, bool liberalguardian, int header);
/* news - graphics */
void loadgraphics();
void displaycenterednewsfont(const std::string& str, int y);
void displaycenteredsmallnews(const std::string& str, int y);
void displaynewspicture(int p, int y);
/* news - constructs non-LCS related event stories */
void constructeventstory(char *story, short view, char positive);
/* news - draws the specified block of text to the screen */
//void displaynewsstory(char *story, short *storyx_s, short *storyx_e, int y);
/* news - shows animated news stories */
void run_television_news_stories();
/* news - make some filler junk */
void generatefiller(char *story, int amount);
/* news - major newspaper reporting on lcs and other topics */
void majornewspaper(char &clearformess, char canseethings);
/*******************************************************************************
*
*                             End of Month Events
*                             Folder: "monthly"
*
*******************************************************************************/
/*
monthly.cpp
*/
#include "monthly\\monthly.h"
/*
lcsmonthly.cpp
*/
#include "monthly\\lcsmonthly.h"
/*
sleeper_update.cpp
*/
#include "monthly\\sleeper_update.h"
/*
justice.cpp
*/
#include "monthly\\justice.h"
/*******************************************************************************
*
*                             Fighting Evil: Site Mode
*                             Folder: "sitemode"
*
*******************************************************************************/
/*
sitedisplay.cpp
*/
/* prints the 'map graphics' on the bottom right */
void printsitemap(int x, int y, int z);
void printblock(int x, int y, int z, int px, int py);
/* prints the names of creatures you see */
void printencounter();
/* prints the names of creatures you see in car chases */
void printchaseencounter();
/* blanks a part of the screen */
void clearcommandarea();
void clearmessagearea(bool redrawmaparea = true);
void clearmaparea(bool lower = true, bool upper = true);
/*
miscactions.cpp
*/
/* unlock attempt */
char unlock(short type, char &actual);
/* bash attempt */
char bash(short type, char &actual);
/* computer hack attempt */
char hack(short type, char &actual);
/* run a radio broadcast */
char radio_broadcast();
/* run a tv broadcast */
char news_broadcast();
/* rescues people held at the activeparty's current location */
void partyrescue(short special);
/* everybody reload! */
void reloadparty(bool wasteful = false);
/*
mapspecials.cpp
*/
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
/*******************************************************************************
*
*                             Politics Stuff
*                             Folder: "politics"
*
*******************************************************************************/
/*
politics.cpp
*/
/* politics - calculate presidential approval */
int presidentapproval();
/* politics -- gets the leaning of an issue voter for an election */
int getswingvoter(bool stalin);
/* politics -- gets the leaning of a partyline voter for an election */
int getsimplevoter(int leaning);
/* politics -- promotes the Vice President to President, and replaces VP */
void promoteVP();
/* politics -- appoints a figure to an executive office, based on the President's alignment */
void fillCabinetPost(int position);
/* politics - causes the people to vote (presidential, congressional, propositions) */
void elections(char clearformess, char canseethings);
void elections_senate(int senmod, char canseethings);
void elections_house(char canseethings);
/* politics - causes the supreme court to hand down decisions */
void supremecourt(char clearformess, char canseethings);
/* politics - causes congress to act on legislation */
void congress(char clearformess, char canseethings);
// letter of amnesty to the LCS from the President (you win)
void amnesty();
/* politics - checks if the game is won */
char wincheck();
/* politics - checks the prevailing attitude on a specific law, or overall */
int publicmood(int l);
/* returns true if Stalinists agree with Elite Liberals on a view/law, false if they strongly disagree with libs  *
* the input bool islaw, if true, returns Stalinist opinion on laws, if false, returns Stalinist opinion on views */
bool stalinview(short view, bool islaw);
/*******************************************************************************
*
*                             End of Month Events
*                             Folder: "monthly"
*
*******************************************************************************/
/*
endgame.cpp
*/
/* endgame - attempts to pass a constitutional amendment to help win the game */
void tossjustices(char canseethings);
/* endgame - attempts to pass a constitutional amendment to help win the game */
void amendment_termlimits(char canseethings);
/* endgame - attempts to pass a constitutional amendment to lose the game */
void reaganify(char canseethings);
/* endgame - attempts to pass a constitutional amendment to lose the game */
void stalinize(char canseethings);
/* endgame - checks if a constitutional amendment is ratified */
char ratify(int level, int view, int lawview, char congress, char canseethings);
/* endgame - header for announcing constitutional amendments */
void amendmentheading();
/*******************************************************************************
*
*                                Common Stuff
*                                Folder: "common"
*
*******************************************************************************/
/*
misc.cpp
*/
/* pick a descriptor acronym */
void sexdesc(char *str);
/* what kind of person? */
void sexwho(char *str);
/* seeking acronym */
void sexseek(char *str);
/* what type of sex? */
void sextype(char *str);
/* generate a vanity plate for the squad. */
//void vanity(char *str);
/* return a letter, number, or one of either. */
void chooseLetterOrNumber(char *str, int type);
/* generate a non-vanity plate for the squad. */
void plate(char *str);
/* name of a state (random state, by default) */
const char* statename(int state = -1);
/* endgame - converts an integer into a roman numeral for amendments */
std::string romannumeral(int amendnum);
/* code for bool Interval::set_interval(const string& interval); is also in misc.cpp */
#include "common\\help.h"
#include "common\\consolesupport.h"
/*******************************************************************************
*
*                             Title Screen and New Game
*                             Folder: "title"
*
*******************************************************************************/
/*
titlescreen.cpp
*/
void mode_title();
/*
initfile.cpp
*/
/* Handles a init.txt line */
void setconfigoption(std::string name, std::string value);
/* Loads and parses init.txt */
void loadinitfile();
/*
newgame.cpp
*/
/* new game options screen */
void setup_newgame();
/* creates your founder */
void makecharacter();
/*
saveload.cpp
*/
/* saves the game to save.dat */
void savegame(const std::string& filename);
/* loads the game from save.dat */
char load(const std::string& filename);
/* deletes save.dat (used on endgame and for invalid save version) */
void reset();
/* check if file exists */
bool file_exists(const std::string& filename);
/*******************************************************************************
*
*                        The Main Game Screen: Base Mode
*                        Folder: "basemode"
*
*******************************************************************************/
/*
basemode.cpp
*/
void mode_base();
/*
baseactions.cpp
*/
/* base - burn the flag */
void burnflag();
/* base - new slogan */
void getslogan();
/* base - reorder party */
void orderparty();
/* base - go forth to stop evil */
void stopevil();
/* base - invest in this location */
void investlocation();
/* base - assign a vehicle to this squad */
void setvehicles();
/*
liberalagenda.cpp
*/
/* base - liberal agenda */
bool liberalagenda(signed char won);
/* base - liberal agenda - disband */
bool confirmdisband();
/*******************************************************************************
*
*              End of Day Events
*              Folder: "daily"
*
*******************************************************************************/
/*
shopsnstuff.cpp
*/
/* active squad visits the hospital */
void hospital(int loc);
/* active squad visits the pawn shop */
void pawnshop(int loc);
/* active squad visits the car dealership */
void dealership(int loc);
/* active squad visits the arms dealer */
void armsdealer(int loc);
/* active squad visits the department store */
void deptstore(int loc);
/* active squad visits the oubliette */
void halloweenstore(int loc);
/* choose buyer */
void choose_buyer(short &buyer);

#include "news/news.h"
#include "sitemode/shop.h"


extern short house[HOUSENUM];
extern short senate[SENATENUM];
extern short court[COURTNUM];
extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
extern short execterm;
//extern char execname[EXECNUM][POLITICIAN_NAMELEN];
//extern PoliticalParties presparty;
//extern char oldPresidentName[POLITICIAN_NAMELEN];
extern class Ledger ledger;
extern newsstoryst *sitestory;
extern vector<Item *> groundloot;
extern siteblockst levelmap[MAPX][MAPY][MAPZ];
extern Creature encounter[ENCMAX];
extern int locx;
extern int locy;
extern int locz;
extern short sitealarm;
extern short sitealarmtimer;
extern short siteonfire;
extern int sitecrime;
extern short cursite;
extern squadst *activesquad;
extern short lawList[LAWNUM];
//extern MusicClass music;
extern short interface_pgup;
extern short interface_pgdn;
extern short public_interest[VIEWNUM];
//extern short mode;
extern int selectedsiege;
extern vector<squadst *> squad;
extern long cursquadid;
extern short activesortingchoice[SORTINGCHOICENUM];
extern vector<ArmorType *> armortype;
extern vector<AugmentType *> augmenttype;
extern string savefile_name;
//extern char homedir[MAX_PATH_SIZE];
//extern char artdir[MAX_PATH_SIZE];
extern CursesMoviest movie;
extern unsigned char bigletters[27][5][7][4];
extern unsigned char newstops[6][80][5][4];
extern unsigned char newspic[20][78][18][4];
extern vector<configSiteMap *> sitemaps; // stores site map info read in from config file
//extern bool multipleCityMode;
extern int oldMapMode;
extern unsigned long seed[RNG_SIZE];
extern bool autosave;
#ifdef WIN32
extern bool fixcleartype;
#endif
extern int day;
extern short background_liberal_influence[VIEWNUM];
//extern char endgamestate;
extern char ccsexposure;
extern char ccs_kills;
//extern int ccs_siege_kills;
//extern int ccs_boss_kills;
extern char loaded;
extern short wincondition;
extern bool notermlimit;
extern bool nocourtpurge;
extern bool stalinmode;
extern short offended_corps;
extern short offended_cia;
extern short offended_amradio;
extern short offended_cablenews;
extern short offended_firemen;
extern int police_heat;
extern unsigned long attorneyseed[RNG_SIZE];
extern char lcityname[CITY_NAMELEN];
extern int month;
//extern int year;
extern int amendnum;
extern bool termlimits;
extern bool deagle;
extern bool m249;
extern UniqueCreatures uniqueCreatures;
extern short party_status;
extern vector<newsstoryst *> newsstory;
extern long curcreatureid;
extern chaseseqst chaseseq;
extern char disbanding;
extern int disbandtime;
extern char cantseereason;
extern vector<ClipType *> cliptype;
extern vector<WeaponType *> weapontype;
//extern vector<LootType *> loottype;
extern vector<CreatureType *> creaturetype;
extern vector<VehicleType *> vehicletype;
extern vector<Vehicle *> vehicle;
extern char showcarprefs;
extern highscorest score[SCORENUM];
extern int yourscore;
//The game log. All events and stuff are output here.
//NO debugging out. Make a debugging log for that.
extern Log xmllog;

extern char slogan[SLOGAN_LEN];
extern short attitude[VIEWNUM];
extern short fieldskillrate;

std::string tostring(long i);
inline const char* toCstring(long i) { return tostring(i).c_str(); }
/* Tries to determine boolean value of a string. Returns 1 for true, 0 for false
and -1 if unable to determine. */
int stringtobool(std::string boolstr);
/* These strcpy, strncpy, and strcat wrappers handle std:strings */
inline char* strcpy(char* dest, const std::string& src) { return strcpy(dest, src.c_str()); }
inline char* strncpy(char* dest, const std::string& src, size_t maxlen) { return strncpy(dest, src.c_str(), maxlen); }
inline char* strcat(char* dest, const std::string& src) { return strcat(dest, src.c_str()); }
/* These strcpy and strcat wrappers handle numbers */
inline char* strcpy(char* dest, long src) { return strcpy(dest, tostring(src)); }
inline char* strcat(char* dest, long src) { return strcat(dest, tostring(src)); }
/* This wrapper allows atoi to handle std::strings */
inline int atoi(const std::string& str) { return atoi(str.c_str()); }
/* This wrapper allows atof to handle std::strings */
inline double atof(const std::string& str) { return atof(str.c_str()); }
short creaturetype_string_to_enum(const std::string& ctname);
int augment_string_to_enum(const std::string& augmentname);
string attribute_enum_to_string(int attribute);
int attribute_string_to_enum(const std::string& attribute);
int skill_string_to_enum(std::string skillname);
int gender_string_to_enum(const std::string& gender);
int severtype_string_to_enum(const std::string& severtype);


extern vector<datest *> date;
extern vector<recruitst *> recruit;

extern short sitealienate;
extern string singleSpace;
extern string singleDot;
extern string commaSpace;
#endif // INCLUDES_H_INCLUDED