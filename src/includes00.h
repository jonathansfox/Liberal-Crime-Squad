




/*
	File created by Chris Johnson.
	These were previously all in game.cpp.

	This file includes all the the enums, defines, and included headers required globally by all components.

	All code released under GNU GPL.
*/
#pragma once

#include "includes.h"

using namespace std;


long LCSrandom(long max);
/* Determine size of vectors and any other container that implements the size() function.
This basically includes all types of containers except for the C++11 std::forward_list. */
template <class Container> inline long len(const Container& x)
{
	return x.size();
}
/* Determine array size in pickrandom() and various functions throughout the code.
Only works on actual arrays, not on vectors or other containers. */
template <typename T, size_t N> inline long len(const T(&x)[N])
{
	return N;
}
/* Override of the prior function for null-terminated C-strings as char arrays.
This override allows pickrandom() to pick a random character from a C-string we have as a char array. */
template <size_t N> inline long len(const char(&x)[N])
{
	return strlen(x);
}
/* Override of the prior function for null-terminated C-strings as char pointers.
This override allows pickrandom() to pick a random character from a C-string we have as a char pointer. */
inline long len(const char* x)
{
	return strlen(x);
}
/* Override for when it doesn't work with const in front of the char*
(compilers are weird about template function overrides) */
inline long len(char* x)
{
	return strlen(x);
}

#define CH_USE_CP437



#include "bigListEnumTags.h"

//#ifdef	VEHICLETYPE_CPP
//vehicletype.cpp

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

#include "vehicletype.h"
#include "../common/stringconversion.h"
extern int year;
const string CONST_STEALING = "::stealing: ";
const string CONST_COLORS = "::colors: ";
const string CONST_UNDEF = "UNDEF";
const string CONST_UNKNOWN_ELEMENT_FOR_VEHICLE_TYPE = "Unknown element for vehicle type ";
const string CONST_AVAILABLE_AT_DEALERSHIP = "::available_at_dealership: ";
const string CONST_INVALID_BOOLEAN_VALUE_FOR_VEHICLE_TYPE = "Invalid boolean value for vehicle type ";
const string CONST_COLORS_DISPLAY_COLOR = "::colors::display_color: ";
const string CONST_YEAR_ADD_RANDOM_UP_TO_CURRENT_YEAR = "::year::add_random_up_to_current_year: ";
const string CONST_YEAR_START_AT_CURRENT_YEAR = "::year::start_at_current_year: ";
const string CONST_LACKS_IDNAME = "LACKS IDNAME ";
const string CONST_UNDEFINED = "UNDEFINED";

const string tag_window = "window";
const string tag_body = "body";
const string tag_Translucent = "Translucent";
const string tag_sleeperprice = "sleeperprice";
const string tag_price = "price";
const string tag_available_at_dealership = "available_at_dealership";
const string tag_armor = "armor";
const string tag_armor_midpoint = "armor_midpoint";
const string tag_high_armor_max = "high_armor_max";
const string tag_high_armor_min = "high_armor_min";
const string tag_low_armor_max = "low_armor_max";
const string tag_low_armor_min = "low_armor_min";
const string tag_touch_alarm_chance = "touch_alarm_chance";
const string tag_sense_alarm_chance = "sense_alarm_chance";
const string tag_extra_heat = "extra_heat";
const string tag_juice = "juice";
const string tag_difficulty = "difficulty";
const string tag_difficulty_to_find = "difficulty_to_find";
const string tag_stealing = "stealing";
const string tag_shortname = "shortname";
const string tag_longname = "longname";
const string tag_passenger = "passenger";
const string tag_driver = "driver";
const string tag_attackbonus = "attackbonus";
const string tag_attack = "attack";
const string tag_hardlimit = "hardlimit";
const string tag_softlimit = "softlimit";
const string tag_skillfactor = "skillfactor";
const string tag_skill = "skill";
const string tag_base = "base";
const string tag_dodgebonus = "dodgebonus";
const string tag_dodge = "dodge";
const string tag_drivebonus = "drivebonus";
const string tag_display_color = "display_color";
const string tag_color = "color";
const string tag_colors = "colors";
const string tag_add = "add";
const string tag_add_random = "add_random";
const string tag_add_random_up_to_current_year = "add_random_up_to_current_year";
const string tag_start_at_year = "start_at_year";
const string tag_start_at_current_year = "start_at_current_year";
const string tag_year = "year";
const string tag_idname = "idname";
const string tag_id = "id";

//#endif//VEHICLETYPE_CPP
//#endif// INCLUDES_H_INCLUDED
