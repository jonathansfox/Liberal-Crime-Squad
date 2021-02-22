




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

#include "includesDeprecated.h"
#include "includesRandom.h"
//#include "vehicle/vehicletype.h"
//#include "vehicle/vehicle.h"


//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

//int get_associated_attribute(int skill_type);

//#include "includesDeprecatedB.h"
//#ifdef	SIEGE_CPP
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
