




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

enum GameModes
{
	GAMEMODE_TITLE,
	GAMEMODE_BASE,
	GAMEMODE_SITE,
	GAMEMODE_CHASECAR,
	GAMEMODE_CHASEFOOT
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
#include "includesRandom.h"

//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

//int get_associated_attribute(int skill_type);

//#ifdef	SIEGE_CPP
// siege.cpp

#include "../creature/creature.h"
////

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
void creatureadvance();
void reloadparty(bool wasteful = false);
void mode_site(const short loc);
#include "../common/commonactions.h"

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


/* common - test for possible game over */
char endcheck(char cause = END_OTHER);
/* common - tests if the person is a wanted criminal */
bool iscriminal(CreatureJustice cr);
/* common - removes the liberal from all squads */
void removesquadinfo(DeprecatedCreature& cr);
void addjuice(DeprecatedCreature& cr, long juice, long cap);
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
#include "../customMaps.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"

int getkeyAlt();
int eraseAlt(void);
void pressAnyKey();
int pressSpecificKey(const int x, const int y);

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
//int encounterSize();
vector<NameAndAlignment> getEncounterNameAndAlignment();
short getCurrentSite();
void setCurrentSite(const short i);

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

void deleteGeneratorLightsOff(int l);


int printBestLCSMemberForNews(const string repname, const int l);

bool getLightsOff(int l);
void setLightsOff(int l);
bool hasBasicCompoundWalls(int l);


void reduceCompoundStores(int loc, int amount);
void emptyCompoundStores(int l);
void setUnderAttack(int l);

void baseEveryoneLeftAtHomelessShelter(const int homes);
void escalateSite(int l);
void dumpLootAtLocation(int homes, vector<Item *>& loot);
siegest getWholeSiege(int l);
void cancelOutBleeding();
void countHeroes(int &partysize, int &partyalive);
int getEscapeEngageLocation();
void deleteAllSquadsInActiveAreaExceptActive(const int loc);
void formANewSquadIfThereAreNone();


void juiceEntireCreaturePool(const long juice, const long cap);

extern char ccs_kills;
extern char disbanding;
extern char endgamestate;
//extern char foughtthisround;
extern class Ledger ledger;
extern Deprecatednewsstoryst *sitestory;
extern Deprecatedsquadst *activesquad;
extern int ccs_siege_kills;
extern int police_heat;
extern int selectedsiege;
extern int stat_dead;
extern Log gamelog;
extern long cursquadid;
extern MusicClass music;
extern short attitude[VIEWNUM];
extern short lawList[LAWNUM];
extern short mode;
extern short offended_amradio;
extern short offended_cablenews;
extern short offended_cia;
extern short offended_corps;
extern short offended_firemen;
extern short party_status;
extern vector<DeprecatedCreature *> pool;
extern vector<Deprecatednewsstoryst *> newsstory;
extern vector<Deprecatedsquadst *> squad;

//#endif//SIEGE_CPP
//#endif// INCLUDES_H_INCLUDED
