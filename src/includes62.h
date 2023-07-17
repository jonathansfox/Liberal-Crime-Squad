




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
#include "cmarkup/Markup.h" //For XML.
using namespace std;

#include "includesLen.h"
#include <iostream>
#include "includesDeprecated.h"

enum AnimalGlosses
{
	ANIMALGLOSS_NONE,//IMPORTANT THAT THIS BE HERE AT ZERO
	ANIMALGLOSS_TANK,
	ANIMALGLOSS_ANIMAL,
	ANIMALGLOSSNUM
};

enum GameModes
{
	GAMEMODE_TITLE,
	GAMEMODE_BASE,
	GAMEMODE_SITE,
	GAMEMODE_CHASECAR,
	GAMEMODE_CHASEFOOT
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

enum Crimes
{
	CRIME_STOLEGROUND,
	CRIME_UNLOCKEDDOOR,
	CRIME_BROKEDOWNDOOR,
	CRIME_ATTACKED_MISTAKE,
	CRIME_ATTACKED,
	CRIME_CARCHASE,
	CRIME_CARCRASH,
	CRIME_FOOTCHASE,
	CRIME_KILLEDSOMEBODY,
	CRIME_SHUTDOWNREACTOR,
	CRIME_POLICE_LOCKUP,
	CRIME_COURTHOUSE_LOCKUP,
	CRIME_PRISON_RELEASE,
	CRIME_JURYTAMPERING,
	CRIME_HACK_INTEL,
	CRIME_BREAK_SWEATSHOP,
	CRIME_BREAK_FACTORY,
	CRIME_HOUSE_PHOTOS,
	CRIME_CORP_FILES,
	CRIME_FREE_RABBITS,
	CRIME_FREE_BEASTS,
	CRIME_ARSON,
	CRIME_TAGGING,
	CRIME_ARMORY,
	CRIME_VANDALISM,
	CRIME_BANKVAULTROBBERY,
	CRIME_BANKTELLERROBBERY,
	CRIME_BANKSTICKUP,
	CRIMENUM
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

// fight.cpp
#include "../creature/creature.h"
////

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../sitemode/stealth.h"
#include "../sitemode/sitedisplay.h"
#include "../items/money.h"
#include "../log/log.h"

int getarmortype(const string &idname);
void printparty();
#include "../common/commonactions.h"
/* common - applies a crime to a person */
void criminalize(DeprecatedCreature& cr, short crime);
void addjuice(DeprecatedCreature& cr, long juice, long cap);

Vehicle* getChaseVehicle(const DeprecatedCreature &c);
DeprecatedCreature* getChaseDriver(const DeprecatedCreature &c);
void freehostage(DeprecatedCreature &cr, char situation);
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/creaturePool.h"
extern bool NOENEMYATTACK;
extern char foughtthisround;
extern coordinatest loc_coord;
extern DeprecatedCreature encounter[ENCMAX];
extern Deprecatednewsstoryst *sitestory;
extern Deprecatedsquadst *activesquad;
extern int ccs_boss_kills;
extern int ccs_siege_kills;
extern int sitecrime;
extern int stat_dead;
extern int stat_kills;
extern Log gamelog;
extern short lawList[LAWNUM];
extern short mode;
extern short sitealarmtimer;
extern short sitetype;
extern siteblockst levelmap[MAPX][MAPY][MAPZ];
extern string slogan_str;
extern vector<DeprecatedCreature *> pool;

short  getCurrentSite();
void addLocationChange(int cursite, sitechangest change);



vector<Item *> groundloot;


vector<NameAndAlignment> getEncounterNameAndAlignment();
void delenc(const short e, const char loot);
string specialWoundPossibilityBody(
	DeprecatedCreature &target,
	const char breakdam,
	const char pokedam,
	const char damtype
);
string specialWoundPossibilityHead(
	DeprecatedCreature &target,
	const char breakdam,
	const char heavydam,
	const char damtype
);
map<short, string> tankBodyParts;
map<short, string> animalBodyParts;
map<short, string> humanBodyParts;
std::string burstHitString(int bursthits);
void bloodyUpEncounterArmor();
/* attack handling for an individual creature and its target */
// returns a boolean representing whether it was the intended target or CONST_ACTUAL
// so bool actual does not need to be passed by reference
bool attack(DeprecatedCreature &a, DeprecatedCreature &t, const char mistake);

void setSiteAlarmOne();
string howGracefulAttack(int handToHand);
string dismemberingWound(const int w, const int wound);
int bodypartSeverAmount(const int w);

class AttackInfliction {
public:
	AttackInfliction(const bool, const int, const int, const attackst);
	const bool sneak_attack;
	const int aroll;
	const int droll;
	const attackst attack_used;
};
AttackInfliction::AttackInfliction(const bool _sneak_attack, const int _aroll, const int _droll, const attackst _attack_used) : sneak_attack(_sneak_attack), aroll(_aroll < 0 ? 0 : _aroll),
	droll(_droll < 0 ? 0 : _droll),
	attack_used(_attack_used) {


}
class AttackSeverity {
public:
	AttackSeverity::AttackSeverity(const int, const int, const int, const int);
	const int damamount;
	const int damagearmor;
	const int severtype;
	const int hit_location;

};
AttackSeverity::AttackSeverity(const int _damamount, const int _damagearmor, const int _severtype, const int w) : damamount(_damamount),
damagearmor(_damagearmor),
severtype(_severtype),
hit_location(w)
{


}

struct damageDetails {
	const int mod;
	const int hit_location;
	const int extraarmor;
	const char armorpiercing;
	damageDetails(int _mod, int _hit_location, int _extraarmor, char _armorpiercing) : mod(_mod), hit_location(_hit_location), extraarmor(_extraarmor), armorpiercing(_armorpiercing) {};
};
bool attackPoolEncounter(const int p, const int t, const char mistake);
void addLocationChange(int cursite, sitechangest change);
bool isThereASiteAlarm();
vector<NameAndAlignment> getEncounterNameAndAlignment();
enum LOOP_CONTINUATION {
	RETURN_ZERO,
	RETURN_ONE,
	REPEAT
};
void conservatise(const int e);
//#endif//FIGHT_CPP
//#endif// INCLUDES_H_INCLUDED
