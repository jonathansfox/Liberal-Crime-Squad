




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
//#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
//#include "activityST.h"

//int get_associated_attribute(int skill_type);

//#include "includesDeprecatedB.h"
#ifdef	LCSIO_CPP
// lcsio.cpp

#include <tinydir.h>
extern char homedir[MAX_PATH_SIZE];
extern char artdir[MAX_PATH_SIZE];
const string NEWSPIC_CPC = "newspic.cpc";
const string CONST_DAT = ".dat";
const string CONST_lcsio013 = ".";
const string CONST_LCS = ".lcs/";
const string CONST_lcsio011 = "/";
const string DOT_SLASH = "./";
const string CONST_HOME = "HOME";
const string CONST_X_PARENT_ART_FOLDER = "../art/";
const string CONST_X_ART_FOLDER = "./art/";
const string CONST_USR_GAMES_LCS_ART = "/usr/games/lcs/art/";
const string CONST_USR_GAMES_SHARE_LCS_ART = "/usr/games/share/lcs/art/";
const string CONST_USR_SHARE_LCS_ART = "/usr/share/lcs/art/";
const string CONST_USR_LOCAL_SHARE_LCS_ART = "/usr/local/share/lcs/art/";
const string CONST_LCS_ART = "/lcs/art/";
const string CONST_SCORE = "score";

#endif	//LCSIO_CPP
#endif // INCLUDES_H_INCLUDED
