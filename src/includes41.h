




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

#include "includesDeprecatedB.h"
#ifdef	RECRUIT_CPP
// recruit.cpp
#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"

#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"
//#include "../creature/deprecatedCreatureD.h"

////
#include "../items/armortype.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../basemode/activate.h"
// for recruitFindDifficulty and recruitName
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
#include "../common/commondisplayCreature.h"
// for void printcreatureinfo(Creature *,unsigned char=255)
#include "../common/getnames.h"
// for getview
//#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
// for subordinatesleft
#include "../combat/fight.h"

#include "../common/musicClass.h"

/* recruit struct constructor */

#include "../combat/fight.h"

int getkeyAlt();

void pressAnyKey();

void talk(DeprecatedCreature &a, const int t);

void make_creature_without_encounter_array(const int x, const short type);
short getCurrentSite();
void setCurrentSite(const short i);
extern MusicClass music;
extern short attitude[VIEWNUM];
extern DeprecatedCreature encounter[ENCMAX];

const string MISSING_NO = "missingno";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
void printFoundMultipleRecruits(const string crname);
void printPressEnterToCallItADay(const int recruitCount);
void printAdventuresInRecruitment();
void printSingleRecruit(const int i, const int align, const string name, const string age_string);
void printAskAroundForARecruit(const string recruiter, const string recruit_type);
void printSetupAMeeting(const string crname, const int align, const string rname, const string age_string);
void printWasUnableToTrackDown(const string crname, const string type);
#endif	//RECRUIT_CPP
#endif // INCLUDES_H_INCLUDED
