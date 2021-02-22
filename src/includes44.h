




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
/* This is declared again lower down, just needed here for this header. */
std::string tostring(long i);
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

#include "includesSDS.h"
#include "includesSDS2.h"
//#include "includesDeprecatedB.h"

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


#include "../sitemode/shop.h"
#include "../common/musicClass.h"


bool carselect(DeprecatedCreature &cr, short &cartype);
bool stealcar(DeprecatedCreature &cr, char &clearformess);
bool vehicletypeavailableatshop(const int i);
DeprecatedCreature* findSleeperCarSalesman(int loc);
extern char artdir[MAX_PATH_SIZE];
extern char disbanding;
extern char showcarprefs;
extern class Ledger ledger;
extern Deprecatedsquadst *activesquad;
extern int day;
extern int month;
extern int year;
extern Log gamelog;
extern MusicClass music;
extern short fieldskillrate;
extern short party_status;
extern vector<DeprecatedCreature *> pool;
extern vector<Deprecatednewsstoryst *> newsstory;
extern vector<Deprecatedrecruitst *> recruit;
extern vector<Deprecatedsquadst *> squad;
extern vector<Vehicle *> vehicle;
int driveskill(DeprecatedCreature &cr, int v);
int getVehicleTypePrice(const int carchoice);
int getVehicleTypeSleeperPrice(const int carchoice);
int lenVehicleType();
string getVehicleFullname(int i);
string vehicleTypelongname(const int p);
vector<string> getVehicleTypeColor(const int carchoice);
Vehicle* getVehicleFromTypeYear(const int carchoice, const int colorchoice, const int year);
void basesquad(Deprecatedsquadst *st, long loc);
void clearCarStates();
void determineMedicalSupportAtEachLocation(bool clearformess);
void doDates(char &clearformess);
void getwheelchair(DeprecatedCreature &cr, char &clearformess);
void locateActiveSquad(const int loc);
void locatesquad(Deprecatedsquadst *st, long loc);
void makearmor(DeprecatedCreature &cr, char &clearformess);
void repairarmor(DeprecatedCreature &cr, char &clearformess);
void survey(DeprecatedCreature *cr);
void tendhostage(DeprecatedCreature *cr, char &clearformess);
//#endif//DAILY_CPP
//#endif// INCLUDES_H_INCLUDED
