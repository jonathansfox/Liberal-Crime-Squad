




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

/* Deletes a specified pointer and sets it to NULL. */
template <typename T> inline void delete_and_nullify(T*& o)
{
	delete o;
	o = NULL;
}

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


//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

//int get_associated_attribute(int skill_type);


std::string getactivity(ActivityST& act);
// reviewmode.cpp

#include "../creature/creature.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locationsEnums.h"
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
/* full screen character sheet, just skills */
void printliberalskills(CreatureJustice cr, ListOfCreatureSkills cr_2);
/* full screen character sheet */
void printliberalstats(DeprecatedCreature& cr);
/* Full screen character sheet, crime sheet */
void printliberalcrimes(CreatureJustice cr);
/* prints a character's general health description (One Leg, Liberal, NearDETH...) */
void printhealthstat(CreatureHealth g, int y, int x, char smll);
// for void printfunds(int,int,char*)
#include "../common/getnames.h"
// for std::string getactivity(ActivityST)
void consolidateloot(vector<Item *>&);
void equipmentbaseassign();
#include "../common/commonactions.h"
/* common - applies a crime to a person */
void criminalize(DeprecatedCreature& cr, short crime);
/* common - tests if the person is a wanted criminal */
bool iscriminal(CreatureJustice cr);
/* common - removes the liberal from all squads */
void removesquadinfo(DeprecatedCreature& cr);
/* Determines the number of subordinates a creature may recruit,
based on their max and the number they already command */
int subordinatesleft(const DeprecatedCreature& cr);
void sortliberals(std::vector<DeprecatedCreature*>& liberals, short sortingchoice, bool dosortnone = false);
/* tells how many total members a squad has (including dead members) */
// for short reviewmodeenum_to_sortingchoiceenum(short)
int getsquad(int);
int getpoolcreature(int);
void fundreport(char &clearformess);
void printname(const int hiding, const int location, const int flag, const string name);
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
#include "../common/creaturePool.h"

void nukeAllEmptySquads(const vector<int> squadloc, const int mode);

const int PAGELENGTH = 19;

extern short mode;
extern short activesortingchoice[SORTINGCHOICENUM];
extern Deprecatedsquadst *activesquad;
extern long cursquadid;
extern MusicClass music;
extern vector<DeprecatedCreature *> pool;
extern vector<Deprecatedsquadst *> squad;
extern int stat_kills;
extern bool multipleCityMode;
//	extern Log gamelog;

int consolidateSiegeLoot();

//#endif//REVIEWMODE_CPP
//#endif// INCLUDES_H_INCLUDED
