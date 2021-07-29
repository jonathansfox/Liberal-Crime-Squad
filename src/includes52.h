




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
const int RNG_SIZE = 4; // needed for locations.h
/* This is declared again lower down, just needed here for this header. */
std::string tostring(long i);

//int get_associated_attribute(int skill_type);

#include "includesSDS.h"
// configfile.cpp

#include "../items/itemtype.h"
#include "../items/item.h"
// needed for locations
#include "../locations/locations.h"
#include "../configfile.h"
//own header
#include "../cursesAlternative.h"
//extern string singleSpace;


extern char artdir[MAX_PATH_SIZE];
extern siteblockst levelmap[MAPX][MAPY][MAPZ];

map<int, SpecialBlocks> mapCBSpecial = {
	map<int, SpecialBlocks>::value_type(0,  SPECIAL_NONE),
	map<int, SpecialBlocks>::value_type(1,  SPECIAL_LAB_COSMETICS_CAGEDANIMALS),
	map<int, SpecialBlocks>::value_type(2,  SPECIAL_LAB_GENETIC_CAGEDANIMALS),
	map<int, SpecialBlocks>::value_type(3,  SPECIAL_POLICESTATION_LOCKUP),
	map<int, SpecialBlocks>::value_type(4,  SPECIAL_COURTHOUSE_LOCKUP),
	map<int, SpecialBlocks>::value_type(5,  SPECIAL_COURTHOUSE_JURYROOM),
	map<int, SpecialBlocks>::value_type(6,  SPECIAL_PRISON_CONTROL),
	map<int, SpecialBlocks>::value_type(7,  SPECIAL_PRISON_CONTROL_LOW),
	map<int, SpecialBlocks>::value_type(8,  SPECIAL_PRISON_CONTROL_MEDIUM),
	map<int, SpecialBlocks>::value_type(9,  SPECIAL_PRISON_CONTROL_HIGH),
	map<int, SpecialBlocks>::value_type(10,  SPECIAL_INTEL_SUPERCOMPUTER),
	map<int, SpecialBlocks>::value_type(11,  SPECIAL_SWEATSHOP_EQUIPMENT),
	map<int, SpecialBlocks>::value_type(12,  SPECIAL_POLLUTER_EQUIPMENT),
	map<int, SpecialBlocks>::value_type(13,  SPECIAL_NUCLEAR_ONOFF),
	map<int, SpecialBlocks>::value_type(14,  SPECIAL_HOUSE_PHOTOS),
	map<int, SpecialBlocks>::value_type(15,  SPECIAL_HOUSE_CEO),
	map<int, SpecialBlocks>::value_type(16,  SPECIAL_CORPORATE_FILES),
	map<int, SpecialBlocks>::value_type(17,  SPECIAL_RADIO_BROADCASTSTUDIO),
	map<int, SpecialBlocks>::value_type(18,  SPECIAL_NEWS_BROADCASTSTUDIO),
	map<int, SpecialBlocks>::value_type(19,  SPECIAL_APARTMENT_LANDLORD),
	map<int, SpecialBlocks>::value_type(20,  SPECIAL_SIGN_ONE),
	map<int, SpecialBlocks>::value_type(21,  SPECIAL_RESTAURANT_TABLE),
	map<int, SpecialBlocks>::value_type(22,  SPECIAL_CAFE_COMPUTER),
	map<int, SpecialBlocks>::value_type(23,  SPECIAL_PARK_BENCH),
	map<int, SpecialBlocks>::value_type(24,  SPECIAL_STAIRS_UP),
	map<int, SpecialBlocks>::value_type(25,  SPECIAL_STAIRS_DOWN),
	map<int, SpecialBlocks>::value_type(26,  SPECIAL_CLUB_BOUNCER),
	map<int, SpecialBlocks>::value_type(27,  SPECIAL_CLUB_BOUNCER_SECONDVISIT),
	map<int, SpecialBlocks>::value_type(28,  SPECIAL_ARMORY),
	map<int, SpecialBlocks>::value_type(29,  SPECIAL_DISPLAY_CASE),
	map<int, SpecialBlocks>::value_type(30,  SPECIAL_SIGN_TWO),
	map<int, SpecialBlocks>::value_type(31,  SPECIAL_SIGN_THREE),
	map<int, SpecialBlocks>::value_type(32,  SPECIAL_SECURITY_CHECKPOINT),
	map<int, SpecialBlocks>::value_type(33,  SPECIAL_SECURITY_METALDETECTORS),
	map<int, SpecialBlocks>::value_type(34,  SPECIAL_SECURITY_SECONDVISIT),
	map<int, SpecialBlocks>::value_type(35,  SPECIAL_BANK_VAULT),
	map<int, SpecialBlocks>::value_type(36,  SPECIAL_BANK_TELLER),
	map<int, SpecialBlocks>::value_type(37,  SPECIAL_BANK_MONEY),
	map<int, SpecialBlocks>::value_type(38,  SPECIAL_CCS_BOSS),
	map<int, SpecialBlocks>::value_type(39,  SPECIAL_OVAL_OFFICE_NW),
	map<int, SpecialBlocks>::value_type(40,  SPECIAL_OVAL_OFFICE_NE),
	map<int, SpecialBlocks>::value_type(41,  SPECIAL_OVAL_OFFICE_SW),
	map<int, SpecialBlocks>::value_type(42,  SPECIAL_OVAL_OFFICE_SE),
};
//#endif//CONFIGFILE_CPP
//#endif// INCLUDES_H_INCLUDED
