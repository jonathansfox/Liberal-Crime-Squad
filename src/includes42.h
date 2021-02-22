




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
//#ifdef	INTERROGATION_CPP
// interrogation.cpp

#include "../creature/creature.h"
#include "../locations/locationsEnums.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../log/log.h"
#include "../common/commondisplayCreature.h"
// for void printhealthstat(Creature &,int,int,char);
#include "../common/getnames.h"
// for std::string getview(short ,bool );
#include "../common/commonactionsCreature.h"
// for  void sleeperize_prompt(Creature &,Creature &,int);
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../common/creaturePoolCreature.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"

extern Log gamelog;
// Interrogation always enlightens
extern bool AUTOENLIGHTEN;
extern MusicClass music;
extern int stat_recruits;
extern int stat_kills;
extern class Ledger ledger;
extern short lawList[LAWNUM];


enum InterrogationTechnqiues
{
	TECHNIQUE_TALK,
	TECHNIQUE_RESTRAIN,
	TECHNIQUE_BEAT,
	TECHNIQUE_PROPS,
	TECHNIQUE_DRUGS,
	TECHNIQUE_KILL
};

//#endif//INTERROGATION_CPP
//#endif// INCLUDES_H_INCLUDED
