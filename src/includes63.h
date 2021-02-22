




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
#include "includesSDS.h"
#include "includesSDS2.h"

// chase.cpp

#include "../creature/creature.h"
////


#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
//#include "basemode/baseactions.h"
void orderparty();
//#include "sitemode/advance.h"
void creatureadvance();
#include "../sitemode/sitedisplay.h"
//#include "sitemode/miscactions.h"
void reloadparty(bool wasteful = false);
#include "../log/log.h"
// for gamelog
#include "../common/translateid.h"
// for  int id_getcar(int)
#include "../common/commondisplay.h"
// for addstr (with log)
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
//#include "common/equipment.h"
void equip(vector<Item *> &loot, int loc);
#include "fight.h"
#include "fightCreature.h"  
// for void youattack();
#include "haulkidnapCreature.h"
// for  void kidnaptransfer(Creature &cr);
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
#include "../common/creaturePool.h"
extern char endgamestate;
//extern char foughtthisround;
extern chaseseqst chaseseq;
extern DeprecatedCreature encounter[ENCMAX];
extern Deprecatednewsstoryst* sitestory;
extern Deprecatedsquadst* activesquad;
extern int stat_dead;
extern Log gamelog;
extern long cursquadid;
extern MusicClass music;
extern short fieldskillrate;
extern short lawList[LAWNUM];
extern short mode;
extern short party_status;
void make_creature_without_encounter_array(const int x, const short type);
enum LOOP_CONTINUATION {
	RETURN_ZERO,
	RETURN_ONE,
	REPEAT
};
vector<NameAndAlignment> getEncounterNameAndAlignment();

const int DRIVING_RANDOMNESS = 13;
int baddieCount();
int baddieCount(const bool in_car);
int driveskill(DeprecatedCreature &cr, int v);
int encounterSize();
int getEncounterCarID(const int p);
Vehicle* getVehicleOfThisType(int cartype);
void addCreatueVehiclesToCollection(DeprecatedCreature *cr[6], vector<Vehicle *> &veh);
void conservatise(const int e);
void deleteVehicles(vector<Vehicle *>& carid);
void removeCreatureFromSquad(DeprecatedCreature &cr, int oldsqid);


void emptyEncounter();

//#endif//CHASE_CPP
//#endif// INCLUDES_H_INCLUDED
