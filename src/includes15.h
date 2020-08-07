




/*
	File created by Chris Johnson.
	These were previously all in game.cpp.

	This file includes all the the enums, defines, and included headers required globally by all components.

	All code released under GNU GPL.
*/
#ifndef INCLUDES_H_INCLUDED
#define INCLUDES_H_INCLUDED0
constexpr auto __USE_MINGW_ANSI_STDIO = 0;
#include <windows.h>
#include <io.h> //needed for unlink()
#include <direct.h>
#include <ciso646> // alternate keywords included in the ISO C++ standard
// but not directly supported by Microsoft Visual Studio C++
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <time.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sstream>
#include <deque>
#include <queue>
#include <math.h>
#include <cstring>
#include "cmarkup/Markup.h" //For XML.
#include <locale.h>

#include <mbctype.h>




#include <string.h>

using namespace std;

#include "includesDeprecated.h"
//#include "vehicle/vehicletype.h"
//#include "vehicle/vehicle.h"


//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

int get_associated_attribute(int skill_type);


#ifdef	ADVANCE_CPP

// advance.cpp

#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"

#include "sitedisplay.h"

#include "../log/log.h"

//#include "common/commondisplay.h"
void printparty();

#include "../common/commonactions.h"
// for void criminalizeparty(short crime)

#include "../combat/fight.h"
#include "../combat/fightCreature.h"  

//#include "combat/haulkidnap.h"
void squadgrab_immobile(char dead);
//#include "combat/haulkidnapCreature.h"

#include "../cursesAlternative.h"
#include "../set_color_support.h"

#include "../locations/locationsPool.h"
#include "../common/creaturePool.h"

void addLocationChange(int cursite, sitechangest change);
void squadgrab_immobile(char dead);
//// #include "combat/haulkidnapCreature.h"
void freehostage(DeprecatedCreature &cr, char situation);
void advancecreature(const int e);
bool isThereASiteAlarm();
void setSiteAlarmOne();
void resetSiteAlarm();

extern coordinatest loc_coord;
extern Deprecatednewsstoryst *sitestory;
extern Deprecatedsquadst *activesquad;
extern int ccs_boss_kills;
extern int ccs_siege_kills;
extern int sitecrime;
extern int stat_dead;
extern int stat_kills;
extern Log gamelog;
extern short lawList[LAWNUM];
extern short mode;
extern short postalarmtimer;
extern short sitealarmtimer;
extern short siteonfire;
extern siteblockst levelmap[MAPX][MAPY][MAPZ];


vector<NameAndAlignment> getEncounterNameAndAlignment();
short getCurrentSite();
const string smellsPanic = "The Squad smells Conservative panic.";
const string ABLE_TO_SLOW_BLEEDING = " was able to slow the bleeding of";
const string sWounds = "'s wounds.";
const string isBurned = " is burned!";
const string drops = " drops ";
const string sBody = "'s body.";
const string tag_value = "value";

const string tag_attribute = "attribute";


const string tag_skill = "skill";

#endif	 //ADVANCE_CPP
#endif // INCLUDES_H_INCLUDED
