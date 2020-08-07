




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

#ifdef CURSES_ALTERNATIVE
#include "../common/commondisplay.h"
#include "../sitemode/sitedisplay.h"

const string CONST_cursesAlternative013 = "]";
const string CONST_cursesAlternative011 = "[";
const string SPACE_TIMES = " times";
const string FIVE_TIMES = " five times";
const string FOUR_TIMES = " four times";
const string THREE_TIMES = " three times";
const string CONST_cursesAlternative004 = " twice";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";

const string CONST_sitedisplay102 = "                                                     ";
const string CONST_sitedisplay100 = "                                                                                ";
const string CONST_sitedisplay097 = "                           ";
const string CONST_sitedisplay095 = "LOOT!";
const string CONST_ENCTR = "ENCTR";
const string CONST_sitedisplay093 = "enemy";
const string CONST_ENEMY = "ENEMY";
const string CONST_sitedisplay091 = "SQUAD";
const string CONST_THE_OFFICE_OF_THE_PRESIDENT = "The Office of the President";
const string CONST_CCS_BOSS = "CCS Boss";
const string CONST_OH_WOW_SO_MUCH_MONEY = "Oh Wow So Much Money";
const string CONST_BANK_TELLER = "Bank Teller";
const string CONST_BANK_VAULT = "Bank Vault";
const string CONST_sitedisplay085 = "Bench";
const string CONST_COMPUTER = "Computer";
const string CONST_sitedisplay083 = "Table";
const string CONST_sitedisplay082 = "Stairs Down";
const string CONST_sitedisplay081 = "Stairs Up";
const string CONST_DISPLAY_CASE = "Display Case";
const string CONST_sitedisplay079 = "Sign";
const string CONST_LANDLORD_S_OFFICE = "Landlord's Office";
const string CONST_NEWS_BROADCAST_STUDIO = "News Broadcast Studio";
const string CONST_RADIO_BROADCAST_ROOM = "Radio Broadcast Room";
const string CONST_sitedisplay075 = "Safe";
const string CONST_CEO_S_STUDY = "CEO's Study";
const string CONST_ARMORY = "Armory";
const string CONST_FACTORY_EQUIPMENT = "Factory Equipment";
const string CONST_TEXTILE_EQUIPMENT = "Textile Equipment";
const string CONST_SUPERCOMPUTER = "Supercomputer";
const string CONST_sitedisplay069 = "Prison Control Room";
const string CONST_JURY_ROOM = "Jury Room";
const string CONST_COURTHOUSE_JAIL = "Courthouse Jail";
const string CONST_POLICE_DETENTION_ROOM = "Police Detention Room";
const string CONST_sitedisplay065 = "Caged \"Animals\"";
const string CONST_REACTOR_CONTROL_ROOM = "Reactor Control Room";
const string CONST_CAGED_ANIMALS = "Caged Animals";
const string CONST_ICE = "ICE";
const string CONST_sitedisplay057 = "OFF";
const string CONST_AL = "AL";
const string CONST_OV = "OV";
const string CONST_BOSS = "BOSS!";
const string CONST_TELER = "TELER";
const string CONST_VAULT = "VAULT";
const string CONST_CASE = "CASE";
const string CONST_GUARD = "GUARD";
const string CONST_METAL = "METAL";
const string CONST_BENCH = "BENCH";
const string CONST_CPU = "CPU";
const string CONST_TABLE = "TABLE";
const string CONST_SIGN = "SIGN!";
const string CONST_sitedisplay044 = "RENT?";
const string CONST_STAGE = "STAGE";
const string CONST_MIC = "MIC";
const string CONST_SAFE = "SAFE!";
const string CONST_ARMRY = "ARMRY";
const string CONST_EQUIP = "EQUIP";
const string CONST_INTEL = "INTEL";
const string CONST_CTROL = "CTROL";
const string CONST_JURY = "JURY!";
const string CONST_CELLS = "CELLS";
const string CONST_CAGES = "CAGES";
const string CONST_POWER = "POWER";
const string CONST_TRAP = "TRAP!";
const string CONST_sitedisplay030 = "~$~";
const string CONST_EXT = "EXT";
const string CONST_sitedisplay022 = "LCS";
const string CONST_CCS = "CCS";
const string CONST_GNG = "GNG";
const string CONST_sitedisplay010 = "   ";
const string CONST_sitedisplay096 = "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ";
const string CONST_sitedisplay062 = "³                         ³";
const string CONST_sitedisplay061 = "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
const string CONST_sitedisplay060 = "ÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂ";
const string CONST_sitedisplay028 = "¼";
const string CONST_sitedisplay027 = "È";
const string CONST_sitedisplay026 = "»";
const string CONST_sitedisplay025 = "É";
const string CONST_sitedisplay024 = "Í";
const string CONST_sitedisplay023 = "º";
const string tag_ARMOR = "ARMOR";
const string tag_MONEY = "MONEY";
const string tag_CEO = "CEO";
const string FROM_STATUS_LINE = "from status line";
const string TO_STATUS_LINE = "to status line";

const string CONST_consolesupport011 = "rb";
const string CONST_consolesupport012 = "wb";
const string CLEARTYPE_DAT = "cleartype.dat";
const string EN_US_CP437 = "en_US.CP437";
const string EN_US_UTF_8 = "en_US.UTF-8";
const string ENGLISH_UNITED_437 = "English_United States.437";
const string CONST_consolesupport003 = "fsl";
const string CONST_consolesupport002 = "tsl";
const string CONST_consolesupport001 = "hs";
const string CONST_consolesupport000 = "UTF-8";

//#include "../creature/newcreature.h"

#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"
//#include "../creature/deprecatedCreatureD.h"

////
#include "../common/getnames.h"

#include "../locations/locations.h"
#include "../pdcurses/curses.h"
#include "../log/log.h"

#include "../cursesAlternative.h"
#include "../customMaps.h"

#endif
#endif // INCLUDES_H_INCLUDED
