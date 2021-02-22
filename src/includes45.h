




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
//#include "includesDeprecatedB.h"
//#ifdef	ACTIVITIES_CPP
// activities.cpp

#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../items/armortype.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../basemode/activate.h"
// for armor_makedifficulty
#include "../items/loottype.h"
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
#include "../common/commondisplayCreature.h"
// for addstr
#include "../common/translateid.h"
// for  int getsquad(int)
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
// for void criminalize(Creature &,short);
#include "../common/getnames.h"
// for std::string getview(short, bool)
#include "../politics/politics.h"
//for int publicmood(int l);
#include "../combat/chase.h"
#include "../combat/chaseCreature.h"
//for void makechasers(long sitetype,long sitecrime);
#include "../combat/fightCreature.h"  

#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
#include "../items/lootTypePoolItem.h"
#include "../common/creaturePool.h"


void doActivitySolicitDonations(vector<DeprecatedCreature *> &solicit, char &clearformess);
void doActivitySellTshirts(vector<DeprecatedCreature *> &tshirts, char &clearformess);
void doActivitySellArt(vector<DeprecatedCreature *> &art, char &clearformess);
void doActivitySellMusic(vector<DeprecatedCreature *> &music, char &clearformess);
void doActivitySellBrownies(vector<DeprecatedCreature *> &brownies, char &clearformess);
void doActivityHacking(vector<DeprecatedCreature *> &hack, char &clearformess);
void doActivityGraffiti(vector<DeprecatedCreature *> &graffiti, char &clearformess);
void doActivityProstitution(vector<DeprecatedCreature *> &prostitutes, char &clearformess);
void doActivityLearn(vector<DeprecatedCreature *> &students, char &clearformess);
void doActivityTrouble(vector<DeprecatedCreature *> &trouble, char &clearformess);
void doActivityTeach(vector<DeprecatedCreature *> &teachers, char &clearformess);
void doActivityBury(vector<DeprecatedCreature *> &bury, char &clearformess);

void addLootToLoc(int loc, Item* it);
char tryFindCloth(int cursite);
string wasUnableToFind(const string old);
string considerLeaving(const bool sensealarm, const bool alarmon, const string name);
extern bool SHOWMECHANICS;
extern char endgamestate;
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern char newscherrybusted;
extern chaseseqst chaseseq;
extern class Ledger ledger;
extern Deprecatednewsstoryst *sitestory;
extern Log gamelog;
extern MusicClass music;
extern short attitude[VIEWNUM];
extern short background_liberal_influence[VIEWNUM];
extern short exec[EXECNUM];
extern short fieldskillrate;
extern short interface_pgdn;
extern short interface_pgup;
extern short lawList[LAWNUM];
extern short mode;
extern short public_interest[VIEWNUM];
extern vector<ArmorType *> armortype;
extern vector<DeprecatedCreature *> pool;
extern vector<Deprecatednewsstoryst *> newsstory;
extern vector<Deprecatedsquadst *> squad;
static const char SURVEY_PAGE_SIZE = 14;
string gimmeASprayCan(DeprecatedCreature* graffiti);
Vehicle* getVehicleOfThisType(int cartype);
void buyMeASprayCan(DeprecatedCreature* graffiti);
void newVehicle(Vehicle *startcar);

enum CarHotwireMethod {
	UNDETERMINED,
	ATTEMPT_HOTWIRE,
	USE_KEYS
};

//#endif//ACTIVITIES_CPP
//#endif// INCLUDES_H_INCLUDED
