




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

/* Deletes a specified pointer and sets it to NULL. */
template <typename T> inline void delete_and_nullify(T*& o)
{
	delete o;
	o = NULL;
}

enum AnimalGlosses
{
	ANIMALGLOSS_NONE,//IMPORTANT THAT THIS BE HERE AT ZERO
	ANIMALGLOSS_TANK,
	ANIMALGLOSS_ANIMAL,
	ANIMALGLOSSNUM
};

enum Laws
{
	LAW_STALIN = -2, // not a real law: this is -2 and is actually calculated based on views >=0 and <VIEWNUM-3
	LAW_MOOD, // not a real law: this is -1 and is likewise calculated based on views >=0 and <VIEWNUM-3
	LAW_ABORTION, // law #0, the first one that is actually in the law[] array
	LAW_ANIMALRESEARCH,
	LAW_POLICEBEHAVIOR,
	LAW_PRIVACY,
	LAW_DEATHPENALTY,
	LAW_NUCLEARPOWER,
	LAW_POLLUTION,
	LAW_LABOR,
	LAW_GAY,
	LAW_CORPORATE,
	LAW_FREESPEECH,
	LAW_FLAGBURNING,
	LAW_GUNCONTROL,
	LAW_TAX,
	LAW_WOMEN,
	LAW_CIVILRIGHTS,
	LAW_DRUGS,
	LAW_IMMIGRATION,
	LAW_ELECTIONS,
	LAW_MILITARY,
	LAW_PRISONS,
	LAW_TORTURE,
	LAWNUM
};

enum Execs
{
	EXEC_PRESIDENT,
	EXEC_VP,
	EXEC_STATE,
	EXEC_ATTORNEY,
	EXECNUM
};

#include "includesRandom.h"
/* This is declared again lower down, just needed here for this header. */
std::string tostring(long i);

//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

//int get_associated_attribute(int skill_type);


#include "includesSDS.h"
#include "includesSDS2.h"
string showXmlSkill(int skill_, int value_);
string showXmlAttribute(int attribute_, int value_);
string skill_enum_to_string(int skill_type);
// creature.cpp

#include "../creature/creature.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../sitemode/stealth.h"
// for hasdisguise
string attribute_enum_to_string(int attribute);
#include "../common/translateid.h"
/* politics -- promotes the Vice President to President, and replaces VP */
void promoteVP();
//only use here. --Schmel924
#include "../combat/chaseCreature.h"
//for Vehicle* getChaseVehicle(const Creature &c);
		//hmm --Schmel924
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include "../set_color_support.h"


char hasdisguise(const DeprecatedCreature &cr);

extern Log gamelog;
extern bool SHOWMECHANICS;
extern bool ZEROMORAL;
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern char oldPresidentName[POLITICIAN_NAMELEN];
extern short exec[EXECNUM];
extern long curcreatureid;
extern UniqueCreatures uniqueCreatures;

//#endif//CREATURE_CPP
//#endif// INCLUDES_H_INCLUDED
