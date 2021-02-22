




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

#include "includesDeprecated.h"
#include "includesRandom.h"
//#include "vehicle/vehicletype.h"
//#include "vehicle/vehicle.h"


//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

//int get_associated_attribute(int skill_type);

//#include "includesDeprecatedB.h"

#include "bigListEnumTags.h"
// creaturetype.cpp

#include "../creature/creature.h"
#include "../locations/locationsEnums.h"
#include "../common/interval.h"
#include "creaturetype.h"
//own header
#include "../log/log.h"
// for LOG
#include "../common/translateid.h"
// for  int getweapontype(int)
#include "../common/stringconversion.h"
//for creaturetype_string_to_enum
#include "../politics/politics.h"
//for int publicmood(int l);

vector<CreatureTypes> armAsCivilian = {
	// Curiously, CREATURE_CRACKHEAD has a chance to be armed with a shank, regardless of whether they are granted a civilian weapon
	CREATURE_CRACKHEAD, CREATURE_MUTANT, CREATURE_BUM, CREATURE_WORKER_FACTORY_UNION, CREATURE_WORKER_FACTORY_NONUNION, CREATURE_SCIENTIST_EMINENT, CREATURE_SCIENTIST_LABTECH
};

map<short, vector<CreatureTypes> > replaceTheseCreatures = {
	// The original code has a 1/10 chance to replace with CREATURE_THIEF
	// Otherwise, random selection between the other five.
	// This code changes this to a 1/11 chance to replace with CREATURE_THIEF
	// Which is close enough.
	map<CreatureTypes, vector<CreatureTypes> >::value_type(CREATURE_PRISONER,{ CREATURE_THIEF, CREATURE_GANGMEMBER, CREATURE_PROSTITUTE, CREATURE_CRACKHEAD, CREATURE_TEENAGER, CREATURE_HSDROPOUT, CREATURE_GANGMEMBER, CREATURE_PROSTITUTE, CREATURE_CRACKHEAD, CREATURE_TEENAGER, CREATURE_HSDROPOUT })

};
vector<CreatureTypes> doNotArmInThisFunction = {
	CREATURE_JUDGE_LIBERAL,
	CREATURE_POLITICIAN,
	CREATURE_CORPORATE_MANAGER,
	CREATURE_WORKER_SERVANT,
	CREATURE_WORKER_JANITOR,
	CREATURE_WORKER_SECRETARY,
	CREATURE_LANDLORD,
	CREATURE_BANK_TELLER,
	CREATURE_BANK_MANAGER,
	CREATURE_TEENAGER,
	CREATURE_SOLDIER,
	CREATURE_VETERAN,
	CREATURE_HARDENED_VETERAN,
	CREATURE_SWAT,
	CREATURE_DEATHSQUAD,
	CREATURE_GANGUNIT,
	CREATURE_AGENT,
	CREATURE_SECRET_SERVICE,
	CREATURE_RADIOPERSONALITY,
	CREATURE_NEWSANCHOR,
	CREATURE_JUROR,
	CREATURE_WORKER_FACTORY_CHILD,
	CREATURE_SEWERWORKER,
	CREATURE_COLLEGESTUDENT,
	CREATURE_MUSICIAN,
	CREATURE_MATHEMATICIAN,
	CREATURE_TEACHER,
	CREATURE_HSDROPOUT,
	CREATURE_PRIEST,
	CREATURE_ENGINEER,
	CREATURE_TELEMARKETER,
	CREATURE_CARSALESMAN,
	CREATURE_OFFICEWORKER,
	CREATURE_MAILMAN,
	CREATURE_GARBAGEMAN,
	CREATURE_PLUMBER,
	CREATURE_CHEF,
	CREATURE_CONSTRUCTIONWORKER,
	CREATURE_AMATEURMAGICIAN,
	CREATURE_AUTHOR,
	CREATURE_JOURNALIST,
	CREATURE_CRITIC_ART,
	CREATURE_CRITIC_MUSIC,
	CREATURE_BIKER,
	CREATURE_TRUCKER,
	CREATURE_TAXIDRIVER,
	CREATURE_PROGRAMMER,
	CREATURE_NUN,
	CREATURE_RETIREE,
	CREATURE_PAINTER,
	CREATURE_SCULPTOR,
	CREATURE_DANCER,
	CREATURE_PHOTOGRAPHER,
	CREATURE_CAMERAMAN,
	CREATURE_HAIRSTYLIST,
	CREATURE_FASHIONDESIGNER,
	CREATURE_CLERK,
	CREATURE_ACTOR,
	CREATURE_YOGAINSTRUCTOR,
	CREATURE_MARTIALARTIST,
	CREATURE_ATHLETE,
	CREATURE_LOCKSMITH,
	CREATURE_MILITARYPOLICE,
	CREATURE_SEAL,
	// These are not used in the switch statement anymore, but appear in the defaultWeapons collection
	//CREATURE_SECURITY_GUARD
	//CRREATURE_MERC
};
#define AGE_TEENAGER    14+LCSrandom(4)  /* HS dropout, teenager, some fast food workers */
#define AGE_YOUNGADULT  18+LCSrandom(18) /* young lads and ladies */
#include "locations/locationsPool.h"
#include "sitemode/stealth.h"
short getCurrentSite();
struct fullName {
	string first;
	string middle;
	string last;

};
fullName generate_long_name(char gender = GENDER_NEUTRAL);
#include "customMaps.h"
bool isThereASiteAlarm();
extern char ccs_kills;
extern char endgamestate;
extern Log xmllog;
extern short lawList[LAWNUM];
extern short mode;
extern short sitealienate;
extern short sitetype;
extern vector<ClipType *> cliptype;
extern vector<WeaponType *> weapontype;

//#endif//CREATURETYPE_CPP
//#endif// INCLUDES_H_INCLUDED
