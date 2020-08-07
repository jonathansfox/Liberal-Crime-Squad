




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
//#include "activityST.h"

int get_associated_attribute(int skill_type);

#include "includesDeprecatedB.h"
#ifdef	WEAPON_CPP
// weapon.cpp

#include "../creature/creatureEnums.h"
#include "../items/itemtype.h"
#include "../items/item.h"
#include "../items/cliptype.h"
#include "../items/clip.h"
#include "../items/weapontype.h"
#include "../items/weapon.h"

#include "../common/translateid.h"
// for getweapontype

extern vector<WeaponType *> weapontype;

const string CONST_CLOSE_PARENTHESIS = ")";
const string CONST_SPACE_OPEN_PARENTHESIS = " (";

const string tag_ammo = "ammo";
const string tag_loaded_cliptype = "loaded_cliptype";
const string tag_weapon = "weapon";

#endif	//WEAPON_CPP
#endif // INCLUDES_H_INCLUDED
