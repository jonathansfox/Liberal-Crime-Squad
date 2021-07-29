




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

#include "includesRandom.h"


//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

//int get_associated_attribute(int skill_type);

#include "includesSDS.h"
#include "includesSDS2.h"


// haulkidnap.cpp

#include "../creature/creature.h"
////


#include "../creature/deprecatedCreatureD.h"

////
#include "../sitemode/advance.h"
// for creatureadvance
#include "../sitemode/stealth.h"
#include "../sitemode/sitedisplay.h"
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
// for printparty
void criminalizeparty(short crime);
void removesquadinfo(DeprecatedCreature &cr);
/* roll on the kidnap attempt and show the results */
#include "set_color_support.h"
#include "cursesAlternative.h"

void conservatise(const int cr);

void capturecreature(DeprecatedCreature &t);
vector<NameAndAlignment> getEncounterNameAndAlignment();

bool isThereASiteAlarm();
void setSiteAlarmOne();

extern short offended_amradio;
extern short offended_cablenews;
extern int sitecrime;
extern short party_status;

extern short sitealarmtimer;
extern Deprecatedsquadst *activesquad;
extern DeprecatedCreature encounter[ENCMAX];
extern short lawList[LAWNUM];

extern short mode;
extern Log gamelog;

void enemyattack();
void delenc(const short e, const char loot);
void makeloot(DeprecatedCreature &cr);
//#endif//HAULKIDNAP_CPP
//#endif// INCLUDES_H_INCLUDED
