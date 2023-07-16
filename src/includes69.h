




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
//#include "includesDeprecated.h"
const int BIT1 = (1 << 0);
const int BIT2 = (1 << 1);
const int BIT3 = (1 << 2);
const int BIT4 = (1 << 3);
const int BIT5 = (1 << 4);
const int BIT6 = (1 << 5);
const int BIT7 = (1 << 6);
const int BIT8 = (1 << 7);
const int BIT9 = (1 << 8);

class Log;

/* Deletes and removes all pointers in a container. */
template <class Container> inline void delete_and_clear(Container& c)
{
	while (len(c))
	{
		delete c.back();
		c.pop_back();
	}
}
const int ENTER = 10;
const int ESC = 27;
const int SPACEBAR = 32;
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

enum ReviewModes
{
	REVIEWMODE_LIBERALS,
	REVIEWMODE_HOSTAGES,
	REVIEWMODE_CLINIC,
	REVIEWMODE_JUSTICE,
	REVIEWMODE_SLEEPERS,
	REVIEWMODE_DEAD,
	REVIEWMODE_AWAY,
	REVIEWMODENUM
};

enum ActiveSortingChoices
{
	SORTINGCHOICE_LIBERALS, //They're prefixed SORTINGCHOICE because they're used as
	SORTINGCHOICE_HOSTAGES, //array indices for the array activesortingchoice.
	SORTINGCHOICE_CLINIC,   //activesortingchoice holds the chosen way to sort the lists.
	SORTINGCHOICE_JUSTICE,
	SORTINGCHOICE_SLEEPERS,
	SORTINGCHOICE_DEAD,
	SORTINGCHOICE_AWAY,
	SORTINGCHOICE_ACTIVATE,
	SORTINGCHOICE_ACTIVATESLEEPERS,
	SORTINGCHOICE_ASSEMBLESQUAD,
	SORTINGCHOICE_BASEASSIGN,
	SORTINGCHOICENUM
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
//activate.cpp


#include "../creature/creature.h"
#include "../locations/locations.h"
#include "../items/armortype.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../creature/augmenttype.h"
#include "../common/translateid.h"
// for  int getsquad(int)
void sorting_prompt(short listforsorting);

/* common - gives juice to a given creature */
void addjuice(DeprecatedCreature& cr, long juice, long cap);
/* common - determines how long a creature's injuries will take to heal */
int clinictime(DeprecatedCreature& g);
void sortliberals(std::vector<DeprecatedCreature*>& liberals, short sortingchoice, bool dosortnone = false);

#include "../common/commondisplay.h"
/* character info at top of screen */
void printcreatureinfo(DeprecatedCreature* cr, unsigned char knowledge = 255);
/* prints a character's general health description (One Leg, Liberal, NearDETH...) */
void printhealthstat(CreatureHealth g, int y, int x, char smll);
/* prints a character's health description for each bodypart (Head, Body...) */
void printwoundstat(CreatureHealth cr, int y, int x);
std::string gettitle(const int align, const int juice);
void HelpActivities(int);
string attribute_enum_to_string(int);
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
char getseigedFromLocation(int secondaryLocation);
void createTempSquadWithJustThisLiberal(DeprecatedCreature *cr, int cursquadid);
#include "../common/creaturePoolCreature.h"
#include "../common/musicClass.h"

extern bool ZEROMORAL;
extern int selectedsiege;
extern Log gamelog;
extern long cursquadid;
extern MusicClass music;
extern short lawList[LAWNUM];
extern short mode;
extern short activesortingchoice[SORTINGCHOICENUM];
extern vector<ArmorType *> armortype;
extern vector<RecruitData> recruitable_creatures;
extern class Ledger ledger;

void removesquadinfo(DeprecatedCreature& cr);
void cleangonesquads();

vector<ActivityAndString> data_lessons;
map<Activity, Data_Activity> data_activities;
map<char, vector<ActivityAndString> > activate_menu_items;

vector<CreatureTypes> ACTIVITY_TEACH_FIGHTING_DEFAULT;
// this first block are creatures with All Weapon Skills, Martial Arts, Dodge, and First Aid
vector<CreatureTypes> ACTIVITY_TEACH_COVERT_DEFAULT;
// this second block are creatures with Computers, Security, Stealth, Disguise, Tailoring, Seduction, Psychology, & Driving
vector<CreatureTypes> ACTIVITY_TEACH_POLITICS_DEFAULT;
// this third block are creatures with Writing, Persuasion, Law, Street Sense, Science, Religion, Business, Music, & Art
