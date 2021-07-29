




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
//#ifdef	JUSTICE_CPP
// justice.cpp

#include "../creature/creature.h"
#include "../locations/locations.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../log/log.h"
int scare_factor(int lawflag, int crimenumber);
/* common - tests if the person is a wanted criminal */
bool iscriminal(CreatureJustice cr);
/* common - applies a crime to a person */
void criminalize(DeprecatedCreature& cr, short crime);
// for  bool iscriminal(Creature &)
void addjuice(DeprecatedCreature& cr, long juice, long cap);

#include "../common/translateid.h"
// for  int getarmortype
#include "../politics/politics.h"
//for publicmood
#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include "../common/creaturePoolCreature.h"
vector<string> liberal_jury;
vector<string> conservative_jury;
vector<string> cruel_and_unusual_execution_methods;
vector<string> standard_execution_methods;
vector<string> supposedly_painless_execution_method;
vector<string> reeducation_experiences;
vector<string> labor_camp_experiences;
vector<string> good_experiences;
vector<string> bad_experiences;
vector<string> general_experiences;
#include "../customMaps.h"


#include "../common/musicClass.h"

extern bool SHOWMECHANICS;
extern MusicClass music;
extern class Ledger ledger;
extern unsigned long attorneyseed[RNG_SIZE];
extern unsigned long seed[RNG_SIZE];
extern Log gamelog;
extern int stat_dead;
extern short lawList[LAWNUM];
extern vector<DeprecatedCreature *> pool;

#include "../common/creaturePool.h"
#include "../locations/locationsPool.h"


map<Lawflags, bool> crimeMultipleCounts = {
	map<Lawflags, bool>::value_type(LAWFLAG_TREASON,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_TERRORISM,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_MURDER,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_KIDNAPPING,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_BANKROBBERY,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_ARSON,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_SPEECH,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_BROWNIES,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_ESCAPED,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_HELPESCAPE,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_JURY,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_RACKETEERING, false),
	map<Lawflags, bool>::value_type(LAWFLAG_EXTORTION,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_ARMEDASSAULT,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_ASSAULT,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_CARTHEFT,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_CCFRAUD,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_THEFT,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_PROSTITUTION,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_COMMERCE,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_INFORMATION,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_BURIAL,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_BREAKING,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_VANDALISM,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_RESIST, false),
	map<Lawflags, bool>::value_type(LAWFLAG_DISTURBANCE,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_PUBLICNUDITY,  true),
	map<Lawflags, bool>::value_type(LAWFLAG_LOITERING, false),
};
enum LegalDefense {
	UNDECIDED = -1,
	COURT_ATTORNEY = 0,
	SELF_REPRESENT = 1,
	PLEAD_GUILTY = 2,
	ACE_ATTORNEY = 3,
	SLEEPER_ATTORNEY = 4
};

//#endif//JUSTICE_CPP
//#endif// INCLUDES_H_INCLUDED
