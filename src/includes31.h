




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
#ifdef	LOOTTYPE_CPP
// loottype.cpp

const string CONST_CLOTH = "::cloth: ";
const string CONST_INVALID_BOOLEAN_VALUE_FOR_LOOT_TYPE = "Invalid boolean value for loot type ";
const string CONST_NO_QUICK_FENCING = "::no_quick_fencing: ";
const string CONST_STACKABLE = "::stackable: ";

const string tag_cloth = "cloth";
const string tag_no = "no";
const string tag_no_quick_fencing = "no_quick_fencing";
const string tag_stackable = "stackable";
#endif	//LOOTTYPE_CPP
#endif // INCLUDES_H_INCLUDED
