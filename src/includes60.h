




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

enum GameModes
{
	GAMEMODE_TITLE,
	GAMEMODE_BASE,
	GAMEMODE_SITE,
	GAMEMODE_CHASECAR,
	GAMEMODE_CHASEFOOT
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

enum SortingChoices
{
	SORTING_NONE,
	SORTING_NAME,
	SORTING_LOCATION_AND_NAME,
	SORTING_SQUAD_OR_NAME,
	SORTINGNUM
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
// commonactions.cpp

#include "../creature/creature.h"
////

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locationsEnums.h"

#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../common/translateid.h"
// for  int getsquad(int)
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
// for makedelimeter
#include "../title/highscore.h"       
//for void savehighscore(char endtype)
#include "../politics/politics.h"
//for int publicmood(int l)
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/creaturePool.h"
/* end the game and clean up */
void end_game(int err = EXIT_SUCCESS);
//extern string singleSpace;
//extern string spaceDashSpace;
//extern string singleDot;

short getCurrentSite();
extern short mode;
extern Deprecatedsquadst *activesquad;
extern vector<Deprecatedsquadst *> squad;
extern short activesortingchoice[SORTINGCHOICENUM];
extern class Ledger ledger;
extern Log gamelog;

//#endif//COMMONACTIONS_CPP
//#endif// INCLUDES_H_INCLUDED
