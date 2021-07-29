




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



//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

//int get_associated_attribute(int skill_type);

#include "includesSDS.h"
//activate_sleepers.cpp
#include "../creature/creature.h"
void sorting_prompt(short listforsorting);

/* Determines the number of subordinates a creature may recruit,
based on their max and the number they already command */
int subordinatesleft(const DeprecatedCreature& cr);
void sortliberals(std::vector<DeprecatedCreature*>& liberals, short sortingchoice, bool dosortnone = false);

#include "../common/commondisplay.h"
void printcreatureinfo(DeprecatedCreature *cr, unsigned char knowledge = 255);
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
#include "../common/creaturePoolCreature.h"
//extern string spaceDashSpace;
//extern string percentSign;


//	extern string percentSign;
extern MusicClass music;
extern short activesortingchoice[SORTINGCHOICENUM];
//// #include "../common/commonactions.h"
void sorting_prompt(short listforsorting);

//#endif//ACTIVATE_SLEEPERS_CPP
//#endif// INCLUDES_H_INCLUDED
