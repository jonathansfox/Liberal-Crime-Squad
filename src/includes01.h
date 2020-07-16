




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
/* Pick a random element from a vector/deque/map/std::string/C++11 std::array/etc. (e.g. a random string from a vector of strings).
It works on any container class that implements the [] operator, size() function, and value_type typename.
This doesn't work if the vector/deque/map/std::string/C++11 std::array/etc. has zero elements. */
template <class Container> inline typename Container::value_type& pickrandom(const Container& x)
{
	return const_cast<typename Container::value_type&>(x[LCSrandom(len(x))]);
}
/* Pick a random element from an array (e.g. a random string from an array of strings).
This doesn't work if the array has zero elements. */
template <typename T, size_t N> inline T& pickrandom(const T(&x)[N])
{
	return const_cast<T&>(x[LCSrandom(len(x))]);
}
/* Pick a random element from a C-string.
Returns '\x0' (null character) for empty string. */
inline char& pickrandom(const char* x)
{
	return const_cast<char&>(x[LCSrandom(len(x))]);
}
/* Override for when it doesn't work with const in front of the char*
(compilers are weird about template function overrides) */
inline char& pickrandom(char* x)
{
	return x[LCSrandom(len(x))];
}

/* Deletes and removes all pointers in a container. */
template <class Container> inline void delete_and_clear(Container& c)
{
	while (len(c))
	{
		delete c.back();
		c.pop_back();
	}
}
/* Deletes and removes all pointers that 2 containers have in common. */
template <class Container> inline void delete_and_clear(Container& c1, Container& c2)
{
	for (int i1 = len(c1) - 1; i1 >= 0; i1--)
		for (int i2 = len(c2) - 1; i2 >= 0; i2--)
			if (c1[i1] == c2[i2]) delete_and_remove(c1, i1, c2, i2);
}

#define CH_USE_CP437



#ifndef NDEBUG
#define NDEBUG
#endif

/* This is declared again lower down, just needed here for this header. */
std::string tostring(long i);


enum bigListOfEnumTags {
	ENUM_tag_only_sell_legal_items,
	ENUM_tag_fullscreen,
	ENUM_tag_allow_selling,
	ENUM_tag_increase_prices_with_illegality,
	ENUM_tag_department,
	ENUM_tag_entry,
	ENUM_tag_exit,
	ENUM_tag_sell_masks,
	ENUM_tag_letter,
	ENUM_tag_item,

	ENUM_tag_class,
	ENUM_tag_type,
	ENUM_tag_description,
	ENUM_tag_price,
	ENUM_tag_sleeperprice,

	ENUM_tag_alignment,
	ENUM_tag_PUBLIC_MOOD,
	ENUM_tag_LIBERAL,
	ENUM_tag_MODERATE,
	ENUM_tag_CONSERVATIVE,
	ENUM_tag_age,
	ENUM_tag_DOGYEARS,
	ENUM_tag_CHILD,
	ENUM_tag_TEENAGER,
	ENUM_tag_YOUNGADULT,
	ENUM_tag_MATURE,
	ENUM_tag_GRADUATE,
	ENUM_tag_MIDDLEAGED,
	ENUM_tag_SENIOR,
	ENUM_tag_attribute_points,
	ENUM_tag_attributes,
	ENUM_tag_juice,
	ENUM_tag_gender,
	ENUM_tag_infiltration,
	ENUM_tag_money,
	ENUM_tag_skills,
	ENUM_tag_armor,
	ENUM_tag_weapon,
	ENUM_tag_encounter_name,
	ENUM_tag_type_name,

	ENUM_tag_shortname,
	ENUM_tag_shortname_future,
	ENUM_tag_name_sub_1,
	ENUM_tag_name_sub_2,
	ENUM_tag_name_future_sub_1,
	ENUM_tag_name_future_sub_2,
	ENUM_tag_shortname_sub_1,
	ENUM_tag_shortname_sub_2,
	ENUM_tag_shortname_future_sub_1,
	ENUM_tag_shortname_future_sub_2,
	ENUM_tag_can_take_hostages,
	ENUM_tag_threatening,
	ENUM_tag_can_threaten_hostages,
	ENUM_tag_protects_against_kidnapping,
	ENUM_tag_musical_attack,
	ENUM_tag_instrument,
	ENUM_tag_graffiti,
	ENUM_tag_legality,
	ENUM_tag_bashstrengthmod,
	ENUM_tag_auto_break_locks,
	ENUM_tag_suspicious,
	ENUM_tag_size,
	ENUM_tag_attack,

	ENUM_tag_priority,
	ENUM_tag_ranged,
	ENUM_tag_thrown,
	ENUM_tag_can_backstab,
	ENUM_tag_ammotype,
	ENUM_tag_attack_description,
	ENUM_tag_hit_description,
	ENUM_tag_always_describe_hit,
	ENUM_tag_hit_punctuation,
	ENUM_tag_skill,
	ENUM_tag_accuracy_bonus,
	ENUM_tag_number_attacks,
	ENUM_tag_successive_attacks_difficulty,
	ENUM_tag_strength_min,
	ENUM_tag_strength_max,
	ENUM_tag_random_damage,
	ENUM_tag_fixed_damage,
	ENUM_tag_bruises,
	ENUM_tag_tears,
	ENUM_tag_cuts,
	ENUM_tag_burns,
	ENUM_tag_shoots,
	ENUM_tag_bleeding,
	ENUM_tag_severtype,
	ENUM_tag_damages_armor,
	ENUM_tag_armorpiercing,
	ENUM_tag_no_DR_for_limbs_chance,
	ENUM_tag_critical,
	ENUM_tag_fire,

	ENUM_tag_name,
	ENUM_tag_attribute,
	ENUM_tag_effect,
	ENUM_tag_max_age,
	ENUM_tag_min_age,
	ENUM_tag_cost,
	ENUM_tag_difficulty,

	ENUM_tag_make_difficulty,
	ENUM_tag_make_price,
	ENUM_tag_deathsquad_legality,
	ENUM_tag_can_get_bloody,
	ENUM_tag_can_get_damaged,
	ENUM_tag_body_covering,
	ENUM_tag_interrogation,
	ENUM_tag_professionalism,
	ENUM_tag_conceal_weapon_size,
	ENUM_tag_stealth_value,
	ENUM_tag_mask,
	ENUM_tag_surprise,
	ENUM_tag_qualitylevels,
	ENUM_tag_durability,

	ENUM_tag_vtypeidname,
	ENUM_tag_vtypeid,
	ENUM_tag_color,
	ENUM_tag_heat,
	ENUM_tag_location,
	ENUM_tag_myear,
	ENUM_tag_id,

	ENUM_tag_year,
	ENUM_tag_start_at_current_year,
	ENUM_tag_start_at_year,
	ENUM_tag_add_random_up_to_current_year,
	ENUM_tag_add_random,
	ENUM_tag_add,
	ENUM_tag_colors,
	ENUM_tag_display_color,
	ENUM_tag_drivebonus,
	ENUM_tag_base,
	ENUM_tag_skillfactor,
	ENUM_tag_softlimit,
	ENUM_tag_hardlimit,
	ENUM_tag_dodgebonus,
	ENUM_tag_attackbonus,
	ENUM_tag_driver,
	ENUM_tag_passenger,
	ENUM_tag_longname,
	ENUM_tag_stealing,
	ENUM_tag_difficulty_to_find,
	ENUM_tag_extra_heat,
	ENUM_tag_sense_alarm_chance,
	ENUM_tag_touch_alarm_chance,
	ENUM_tag_low_armor_min,
	ENUM_tag_low_armor_max,
	ENUM_tag_high_armor_min,
	ENUM_tag_high_armor_max,
	ENUM_tag_armor_midpoint,
	ENUM_tag_available_at_dealership,
};

const string singleSpace = " ";
const string tag_heat = "heat";

#ifdef	VEHICLE_CPP
// vehicle.cpp

const string vehicleSportsCar = "SPORTSCAR";
const string CONST_STOLEN = "Stolen ";

const string tag_id = "id";
const string tag_myear = "myear";
const string tag_location = "location";
const string tag_color = "color";
const string tag_vtypeid = "vtypeid";
const string tag_vtypeidname = "vtypeidname";
const string tag_vehicle = "vehicle";

#endif	//VEHICLE_CPP
#endif // INCLUDES_H_INCLUDED
