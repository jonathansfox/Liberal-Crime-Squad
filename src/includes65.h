




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

#include "includesDeprecated.h"
#include "includesRandom.h"
/* This is declared again lower down, just needed here for this header. */
std::string tostring(long i);
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


// liberalagenda.cpp

#include "../creature/creatureEnums.h"
//#include "../common/commondisplay.h"
void set_alignment_color(short alignment, bool extended_range = false);
//#include "../common/getnames.h"
string getlaw(int l);
//#include "../common/commonactions.h"
void cleangonesquads();
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../common/musicClass.h"
vector<string> supremeChars;
vector<string> courtChars;
map<short, vector<string> > endgameLawStrings;
#include "../common/creaturePool.h"
enum Pages
{
	PAGE_LEADERS,
	PAGE_ISSUES_A,
	PAGE_ISSUES_B,
	PAGENUM
};
vector<string> disbandingMessage;
vector<string> issue_phrases;

extern bool stalinmode;
extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern int disbandtime;
extern int year;
extern MusicClass music;
extern short court[COURTNUM];
extern short exec[EXECNUM];
extern short execterm;
extern short house[HOUSENUM];
extern short lawList[LAWNUM];
extern short senate[SENATENUM];
extern short wincondition;

//#endif//LIBERALAGENDA_CPP
//#endif// INCLUDES_H_INCLUDED
