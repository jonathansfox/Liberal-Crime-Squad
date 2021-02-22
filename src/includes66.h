




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
#include "cmarkup/Markup.h" //For XML.
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


//#include "includesDeprecatedB.h"
#include "includesSDS.h"
// basemode.cpp
#include "../creature/creature.h"
////


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
enum CantSeeReason
{
	CANTSEE_DATING = 1,
	CANTSEE_HIDING = 2,
	CANTSEE_OTHER = 3,
	CANTSEE_DISBANDING = 4
};
bool isPartOfJusticeSystem(int cursite);
bool isThisSafehouse(int loc);
extern bool stalinmode;
extern char cantseereason;
extern char disbanding;
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern class Ledger ledger;
extern Deprecatedsquadst *activesquad;
extern int day;
extern int disbandtime;
extern int month;
extern int selectedsiege;
extern int stat_burns;
extern int stat_buys;
extern int year;
extern Log gamelog;
extern MusicClass music;
extern short attitude[VIEWNUM];
extern short court[COURTNUM];
extern short exec[EXECNUM];
extern short execterm;
extern short house[HOUSENUM];
extern short lawList[LAWNUM];
extern short party_status;
extern short senate[SENATENUM];
extern string slogan_str;
extern vector<DeprecatedCreature *> pool;
extern vector<Deprecatedsquadst *> squad;
int countSafeHouses();
int lenVehiclePool();
Location* getLocation();
void addStringYear();
void burnFlagAtLocation(int l);
void equipLoot(int l, int loc);
void printFlag();

//#endif//BASEMODE_CPP
//#endif// INCLUDES_H_INCLUDED
