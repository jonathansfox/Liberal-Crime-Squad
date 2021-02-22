




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

#include "includesSDS.h"
#include "includesSDS2.h"
//#include "includesDeprecatedB.h"
//#ifdef	CREATURENAMES_CPP
// creaturenames.cpp

//#endif//CREATURENAMES_CPP
//#ifdef	GLOBALS_CPP
// globals.cpp

#include "creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"

#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../items/armortype.h"
#include "common/interval.h"
// needed for creaturetype
#include "vehicle/vehicletype.h"
#include "vehicle/vehicle.h"
#include "creature/creaturetype.h"
#include "creature/augmenttype.h"
//#include "common/consolesupport.h"
// for end_cleartype_fix()
#include "common/musicClass.h"
#include "common/creaturePool.h"
#include "locations/locationsPool.h"
#include "items/itemPool.h"
#include "items/lootTypePool.h"
void delete_and_clear_sitemaps();
void delete_and_clear_groundloot();
int endwinAlt(void);
void delete_and_clear_vehicle_types();
void delete_and_clear_date_pool();
void delete_and_clear_weapon_type();
#include <common\\consolesupport.h>
#include "items/loottype.h"
#include "log/log.h"
#include "cursesAlternative.h"
#include "common/ledgerEnums.h"
#include "common/ledger.h"
#include "items/money.h"
#include "common/creaturePoolCreature.h"

extern class Ledger ledger;
extern DeprecatedCreature encounter[ENCMAX];
extern Deprecatednewsstoryst *sitestory;
extern Deprecatedsquadst *activesquad;
extern Log gamelog;
extern Log xmllog;
extern short mode;
extern vector<DeprecatedCreature *> pool;
extern vector<Deprecatedsquadst *> squad;
extern vector<LootType *> loottype;
extern vector<VehicleType *> vehicletype;
extern vector<WeaponType *> weapontype;

int driveskill(DeprecatedCreature &cr, Vehicle &v);
int getloottype(const string &idname);
int getweapontype(const string &idname);
int subordinatesleft(const DeprecatedCreature& cr);
Item* getNewLoot(const string& newLootType, int num = 1);
void addCreature(DeprecatedCreature* cr);
void addjuice(DeprecatedCreature &cr, long juice, long cap);
void assemblesquad(Deprecatedsquadst *cursquad);
void consolidateloot(vector<Item *> &loot);
void criminalize(DeprecatedCreature &cr, short crime);
void fullstatus(const int party_status);
void makeloot(DeprecatedCreature &cr);
void printReporterDuringSiege(const string repname, const string name, const int segmentpower);
void removesquadinfo(DeprecatedCreature &cr);
Deprecatednewsstoryst* lastNewsStory();
bool populate_masks_from_xml(vector<ArmorType*>& masks, const string& file, Log& log);


//#endif//GLOBALS_CPP
//#endif// INCLUDES_H_INCLUDED
