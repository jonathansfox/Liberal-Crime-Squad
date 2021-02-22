




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
//#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
//#include "activityST.h"

//int get_associated_attribute(int skill_type);
#include "includesSDS.h"
//#include "includesDeprecatedB.h"
//#ifdef	LCSMONTHLY_CPP
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
map<short, string> expenseTypes;
map<short, string> incomeTypes;
void constructLootIndices(vector<bool> &havetype, vector<int> &loottypeindex, const vector<string> dox);

extern CCSexposure ccsexposure;
extern char disbanding;
extern class Ledger ledger;
extern Log gamelog;
extern MusicClass music;
extern short lawList[LAWNUM];
extern short offended_amradio;
extern short offended_cablenews;
extern short offended_cia;
extern short offended_corps;
extern short offended_firemen;

//#endif//LCSMONTHLY_CPP
//#endif// INCLUDES_H_INCLUDED
