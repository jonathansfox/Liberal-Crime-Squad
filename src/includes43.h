




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
//#ifdef	DATE_CPP
// date.cpp

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

extern class Ledger ledger;
extern int stat_kidnappings;
extern int stat_recruits;
extern Log gamelog;
extern MusicClass music;
extern short lawList[LAWNUM];
extern vector<DeprecatedCreature *> pool;

enum DateResults
{
	DATERESULT_MEETTOMORROW,
	DATERESULT_BREAKUP,
	DATERESULT_JOINED,
	DATERESULT_ARRESTED
};
int getpoolcreature(int id);
char completedate(Deprecateddatest &d, int p);
void removesquadinfo(DeprecatedCreature &cr);
char completevacation(Deprecateddatest &d, int p);
//#endif//DATE_CPP
//#endif// INCLUDES_H_INCLUDED
