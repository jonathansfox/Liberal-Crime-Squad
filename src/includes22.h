




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

enum EndTypes
{
	END_BUT_NOT_END = -2,
	END_OTHER = -1,
	END_WON,
	END_HICKS,
	END_CIA,
	END_POLICE,
	END_CORP,
	END_REAGAN,
	END_DEAD,
	END_PRISON,
	END_EXECUTED,
	END_DATING,
	END_HIDING,
	END_DISBANDLOSS,
	END_DISPERSED,
	END_CCS,
	END_FIREMEN,
	END_STALIN,
	ENDNUM
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
//#ifdef	ENDGAME_CPP
// endgame.cpp

#include "../creature/creatureEnums.h"
/* fills a string with a proper name */
void generate_name(char *str, char gender = GENDER_NEUTRAL);
#include "../basemode/liberalagenda.h"
// for liberalagenda
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
extern short attitude[];
extern short court[];
extern short exec[];
extern short house[];
extern short lawList[];
extern short senate[];


/* displays the high score board */
void viewhighscores(int musicoverride = MUSIC_OFF);
/* saves a new high score */
void savehighscore(char endtype);

fullName generate_long_name(char gender = GENDER_NEUTRAL);
//#endif//ENDGAME_CPP
//#endif// INCLUDES_H_INCLUDED
