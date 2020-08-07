




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

#ifdef	EXTERNALLYSTOREDTEXT_CPP
// externallyStoredText.cpp

const string CONST_NOVERBOSECOMMENTS = "NOVERBOSECOMMENTS";
const string CONST_VERBOSESAVEFILE = "VERBOSESAVEFILE";
const string CONST_ALLOWSTALIN = "ALLOWSTALIN";
const string CONST_MORERANDOM = "MORERANDOM";
const string CONST_ZEROMORAL = "ZEROMORAL";
const string CONST_INTERNAL = "INTERNAL";
const string CONST_SPINE = "SPINE";
const string CONST_NOFACE = "NOFACE";
const string CONST_NOWALK = "NOWALK";
const string CONST_BLIND = "BLIND";
const string CONST_THEFUTURE = "THEFUTURE";
const string CONST_SHOWMECHANICS = "SHOWMECHANICS";
const string CONST_SHOWWAIT = "SHOWWAIT";
const string CONST_AUTOENLIGHTEN = "AUTOENLIGHTEN";
const string CONST_HIGHFUNDS = "HIGHFUNDS";
const string CONST_GIVEBLOODYARMOR = "GIVEBLOODYARMOR";
const string CONST_REVOLUTIONNOW = "REVOLUTIONNOW";
const string CONST_PERFECTLAWS = "PERFECTLAWS";
const string CONST_SHITLAWS = "SHITLAWS";
const string CONST_NOENEMYATTACK = "NOENEMYATTACK";
const string CONST_NOSAVE = "NOSAVE";
const string CONST_DISPLAYDEBUG = "DISPLAYDEBUG";

#include "../creature/creatureEnums.h"
#include <queue>
#include <map>
#include "../customMaps.h"
struct pointerAndString {
	bool *super_collection;
	string fileName;
	pointerAndString(bool *super_, const string& file_) : fileName(file_), super_collection(super_) {}
};

/*
DEBUG DEFINES
*/
// inform player of ACTIVATED debug codes
extern bool DISPLAYDEBUG;
// Don't save the game
extern bool NOSAVE;
// Enemies don't attack
extern bool NOENEMYATTACK;
// Laws start archconservative
extern bool SHITLAWS;
// Laws start elite liberal
extern bool PERFECTLAWS;
// Public opinion starts at 100% Liberal
extern bool REVOLUTIONNOW;
// Gives you bloody armor
extern bool GIVEBLOODYARMOR;
// Start with lots of money
extern bool HIGHFUNDS;
// Interrogation always enlightens
extern bool AUTOENLIGHTEN;
// Show polls when you can't see things
extern bool SHOWWAIT;
// Show die rolls, 100% accurate poll numbers
extern bool SHOWMECHANICS;
// Make the year 2100
extern bool THEFUTURE;
// Make the founder blind
extern bool BLIND;
// Make the founder unable to walk
extern bool NOWALK;
// Make the founder have no face
extern bool NOFACE;
// Make the founder have a severely injured spine
extern bool SPINE;
// Make the founder have severe internal damage
extern bool INTERNAL;
// Make age not matter for dating or prostitution
extern bool ZEROMORAL;
// Re-seed the Random Number Generator every time it's called
extern bool MORERANDOM;
// Allow experimental, incomplete Stalinist Comrade Squad mode to be chosen for new games
extern bool ALLOWSTALIN;
// Store savefiles in plaintext, making it human readable and editable
extern bool VERBOSESAVEFILE;
// NOVERBOSECOMMENTS only affect anything if VERBOSESAVEFILE is active
// Remove almost all automatically generated comments from verbose savefiles
extern bool NOVERBOSECOMMENTS;

vector<pointerAndString> debug_defines = {
	pointerAndString(&DISPLAYDEBUG, CONST_DISPLAYDEBUG),
	pointerAndString(&NOSAVE, CONST_NOSAVE),
	pointerAndString(&NOENEMYATTACK, CONST_NOENEMYATTACK),
	pointerAndString(&SHITLAWS, CONST_SHITLAWS),
	pointerAndString(&PERFECTLAWS, CONST_PERFECTLAWS),
	pointerAndString(&REVOLUTIONNOW, CONST_REVOLUTIONNOW),
	pointerAndString(&GIVEBLOODYARMOR, CONST_GIVEBLOODYARMOR),
	pointerAndString(&HIGHFUNDS, CONST_HIGHFUNDS),
	pointerAndString(&AUTOENLIGHTEN, CONST_AUTOENLIGHTEN),
	pointerAndString(&SHOWWAIT, CONST_SHOWWAIT),
	pointerAndString(&SHOWMECHANICS, CONST_SHOWMECHANICS),
	pointerAndString(&THEFUTURE, CONST_THEFUTURE),
	pointerAndString(&BLIND, CONST_BLIND),
	pointerAndString(&NOWALK, CONST_NOWALK),
	pointerAndString(&NOFACE, CONST_NOFACE),
	pointerAndString(&SPINE, CONST_SPINE),
	pointerAndString(&INTERNAL, CONST_INTERNAL),
	pointerAndString(&ZEROMORAL, CONST_ZEROMORAL),
	pointerAndString(&MORERANDOM, CONST_MORERANDOM),
	pointerAndString(&ALLOWSTALIN, CONST_ALLOWSTALIN),
	pointerAndString(&VERBOSESAVEFILE, CONST_VERBOSESAVEFILE),
	pointerAndString(&NOVERBOSECOMMENTS, CONST_NOVERBOSECOMMENTS)
};
#endif	//EXTERNALLYSTOREDTEXT_CPP
#endif // INCLUDES_H_INCLUDED
