




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

#include "includesLen.h"
#include <iostream>
#include "includesDeprecated.h"
#include "includesRandom.h"

//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

//int get_associated_attribute(int skill_type);

// baseactions.cpp


#include "../creature/creature.h"

#include "../creature/deprecatedCreatureD.h"

#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
void enter_name(int, int, char*, int, const char*);
#include "../common/commondisplay.h"
// for void printparty(void)
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/creaturePool.h"

int getkey_cap_alt();
int lenVehiclePool();
int getCarID(const int l);
string getCarFullname(const int l);

extern char slogan[SLOGAN_LEN];
extern Deprecatedsquadst *activesquad;
extern string slogan_str;
extern vector<string> default_slogans;
extern short party_status;


//#endif//BASEACTIONS_CPP
//#endif// INCLUDES_H_INCLUDED
