




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
//#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
//#include "activityST.h"

//int get_associated_attribute(int skill_type);

//#include "includesDeprecatedB.h"
//#ifdef	ENDGAME_CPP
// endgame.cpp

#include "../creature/creatureEnums.h"
/* fills a string with a proper name */
void generate_name(char *str, char gender = GENDER_NEUTRAL);
#include "../basemode/liberalagenda.h"
// for liberalagenda
//#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
// for void printfunds(int,int,char*)
#include "../common/misc.h"
// for char* statename(int)
		 //shouldn't be in getnames? --Schmel924
// for romannumeral (int)
		 //only usage here --Schmel924
#include "../title/titlescreen.h"
// for void reset;
#include "../title/highscore.h"
// for void savehighscore(char endtype);
//#include "../monthly/EndGameStatus.h"
//own header
		//does not compile without --Schmel924
#include "../politics/politics.h"
//for publicmood
#include "../cursesAlternative.h"
#include <gui_constants.h>
#include "../set_color_support.h"
/* end the game and clean up */
void end_game(int err = EXIT_SUCCESS);
#include "../common/musicClass.h"
vector<int> state_biases;

#include "../customMaps.h"
struct fullName {
	string first;
	string middle;
	string last;

};
extern bool termlimits;
extern char cantseereason;
extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern int amendnum;
extern MusicClass music;
extern short attitude[VIEWNUM];
extern short court[COURTNUM];
extern short exec[EXECNUM];
extern short house[HOUSENUM];
extern short lawList[LAWNUM];
extern short senate[SENATENUM];

fullName generate_long_name(char gender = GENDER_NEUTRAL);
//#endif//ENDGAME_CPP
//#endif// INCLUDES_H_INCLUDED
