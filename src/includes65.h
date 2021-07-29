




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



enum WinConditions
{
	WINCONDITION_ELITE,
	WINCONDITION_EASY
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

//int get_associated_attribute(int skill_type);


// liberalagenda.cpp

#include "../creature/creatureEnums.h"
void set_alignment_color(short alignment, bool extended_range = false);
string getlaw(int l);
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
