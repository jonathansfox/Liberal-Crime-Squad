




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

#include "includesLen.h"
#include <iostream>
#include "includesDeprecated.h"
/* This is declared again lower down, just needed here for this header. */
std::string tostring(long i);

//#ifdef	WEAPON_CPP
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


//#endif//WEAPON_CPP
//#endif// INCLUDES_H_INCLUDED
