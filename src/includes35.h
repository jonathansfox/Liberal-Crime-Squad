




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

//int get_associated_attribute(int skill_type);

//#ifdef	ARMORTYPE_CPP

#include "bigListEnumTags.h"
// armortype.cpp

enum Bodyparts
{
	BODYPART_HEAD,
	BODYPART_BODY,
	BODYPART_ARM_RIGHT,
	BODYPART_ARM_LEFT,
	BODYPART_LEG_RIGHT,
	BODYPART_LEG_LEFT,
	BODYPARTNUM
};

#include "../creature/creatureEnums.h"
#include "../items/itemtype.h"
#include "../items/armortype.h"
#include "../common/stringconversion.h"
//for stringtobool

extern int year;
//#endif//ARMORTYPE_CPP
//#endif// INCLUDES_H_INCLUDED
