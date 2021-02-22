




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
std::string getactivity(ActivityST& act);
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
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
#include "../common/creaturePool.h"

void nukeAllEmptySquads(const vector<int> squadloc, const int mode);

const int PAGELENGTH = 19;

extern short mode;
extern short activesortingchoice[SORTINGCHOICENUM];
extern Deprecatedsquadst *activesquad;
extern long cursquadid;
extern MusicClass music;
extern vector<DeprecatedCreature *> pool;
extern vector<Deprecatedsquadst *> squad;
extern int stat_kills;
extern bool multipleCityMode;
//	extern Log gamelog;

int consolidateSiegeLoot();

//#endif//REVIEWMODE_CPP
//#endif// INCLUDES_H_INCLUDED
