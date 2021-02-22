




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
string showXmlSkill(int skill_, int value_);
string showXmlAttribute(int attribute_, int value_);
//#include "includesDeprecatedB.h"
string skill_enum_to_string(int skill_type);
// creature.cpp

#include "../creature/creature.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../sitemode/stealth.h"
// for hasdisguise
//#include "../common/stringconversion.h"
string attribute_enum_to_string(int attribute);
#include "../common/translateid.h"
// for  int getweapontype(int )
//#include "../politics/politics.h"
/* politics -- promotes the Vice President to President, and replaces VP */
void promoteVP();
//only use here. --Schmel924
#include "../combat/chaseCreature.h"
//for Vehicle* getChaseVehicle(const Creature &c);
		//hmm --Schmel924
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include "../set_color_support.h"


char hasdisguise(const DeprecatedCreature &cr);

extern Log gamelog;
extern bool SHOWMECHANICS;
extern bool ZEROMORAL;
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern char oldPresidentName[POLITICIAN_NAMELEN];
extern short exec[EXECNUM];
extern long curcreatureid;
extern UniqueCreatures uniqueCreatures;

//#endif//CREATURE_CPP
//#endif// INCLUDES_H_INCLUDED
