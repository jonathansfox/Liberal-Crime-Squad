




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
//

//#include "vehicle/vehicletype.h"
//#include "vehicle/vehicle.h"


//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

//int get_associated_attribute(int skill_type);

//#include "includesDeprecatedB.h"
//#ifdef	SLEEPER_UPDATE_CPP
// sleeper_update.cpp

#include "../creature/creature.h"
#include "../locations/locations.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
//#include "sitemode/newencounter.h"
void prepareencounter(short type, char sec);
#include "../items/lootTypePoolItem.h"
//#include "common/commonactions.h"
void change_public_opinion(int v, int power, char affect = 1, char cap = 100);
#include "../common/commonactionsCreature.h"
//#include "../log/log.h"
#include "../common/translateid.h"
	// for  int getloottype(int id);
#include "../common/creaturePoolCreature.h"
#include "../locations/locationsPool.h"

extern short attitude[VIEWNUM];
extern CCSexposure ccsexposure;
extern class Ledger ledger;
extern short lawList[LAWNUM];
extern char disbanding;


map<CreatureTypes, vector<CreatureSkill> > skill_influence = {
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_CRITIC_ART,
		{ SKILL_WRITING, SKILL_ART }
	),
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_PAINTER,
		{ SKILL_ART }
	),
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_SCULPTOR,
		{ SKILL_ART }
	),
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_CRITIC_MUSIC,
		{ SKILL_WRITING, SKILL_MUSIC }
	),
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_MUSICIAN,
		{ SKILL_MUSIC }
	),
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_AUTHOR,
		{ SKILL_WRITING }
	),
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_JOURNALIST,
		{ SKILL_WRITING }
	),
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_JUDGE_CONSERVATIVE,
		{ SKILL_WRITING, SKILL_LAW }
	),
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_LAWYER,
		{ SKILL_LAW }
	),
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_SCIENTIST_LABTECH,
		{ SKILL_SCIENCE }
	),
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_SCIENTIST_EMINENT,
		{ SKILL_SCIENCE }
	),
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_CORPORATE_CEO,
		{ SKILL_BUSINESS }
	),
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_CORPORATE_MANAGER,
		{ SKILL_BUSINESS }
	),
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_PRIEST,
		{ SKILL_RELIGION }
	),
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_NUN,
		{ SKILL_RELIGION }
	),
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_EDUCATOR,
		{ SKILL_PSYCHOLOGY }
	),
};
map<CreatureTypes, int> super_sleepers_multiplier = {
	map<CreatureTypes, int> ::value_type(CREATURE_CORPORATE_CEO, 20),
	map<CreatureTypes, int> ::value_type(CREATURE_POLITICIAN, 20),
	map<CreatureTypes, int> ::value_type(CREATURE_SCIENTIST_EMINENT, 20),
	map<CreatureTypes, int> ::value_type(CREATURE_DEATHSQUAD, 6),
	map<CreatureTypes, int> ::value_type(CREATURE_EDUCATOR, 6),
	map<CreatureTypes, int> ::value_type(CREATURE_MILITARYOFFICER, 6),
	map<CreatureTypes, int> ::value_type(CREATURE_ACTOR, 4),
	map<CreatureTypes, int> ::value_type(CREATURE_GANGUNIT, 4),
	map<CreatureTypes, int> ::value_type(CREATURE_MILITARYPOLICE, 4),
	map<CreatureTypes, int> ::value_type(CREATURE_SEAL, 4),
};

map<CreatureTypes, vector<Views> > creature_influences_views = {

	/* Cultural leaders block - influences cultural issues */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_PRIEST,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
		),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_PAINTER,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SCULPTOR,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_AUTHOR,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_JOURNALIST,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_PSYCHOLOGIST,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_MUSICIAN,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_CRITIC_ART,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_CRITIC_MUSIC,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_ACTOR,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	/* Legal block - influences an array of social issues */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_JUDGE_CONSERVATIVE,
		{ VIEW_JUSTICES,
		VIEW_FREESPEECH,
		VIEW_INTELLIGENCE,
		VIEW_POLICEBEHAVIOR,
		VIEW_DEATHPENALTY,
		VIEW_GUNCONTROL,
		VIEW_DRUGS }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_LAWYER,
		{ VIEW_POLICEBEHAVIOR,
		VIEW_DEATHPENALTY,
		VIEW_GUNCONTROL,
		VIEW_DRUGS }
	),
	/* Scientists block */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SCIENTIST_EMINENT,
		{ VIEW_POLLUTION,
		VIEW_NUCLEARPOWER,
		VIEW_ANIMALRESEARCH,
		VIEW_GENETICS }
	),


	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SCIENTIST_LABTECH,
		{ VIEW_NUCLEARPOWER,
		VIEW_ANIMALRESEARCH,
		VIEW_GENETICS }
	),
	/* Corporate block */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_CORPORATE_CEO,
		{ VIEW_CEOSALARY,
		VIEW_WOMEN,
		VIEW_TAXES,
		VIEW_CORPORATECULTURE,
		VIEW_SWEATSHOPS,
		VIEW_POLLUTION,
		VIEW_CIVILRIGHTS }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_CORPORATE_MANAGER,
		{ VIEW_WOMEN,
		VIEW_TAXES,
		VIEW_CORPORATECULTURE,
		VIEW_SWEATSHOPS,
		VIEW_POLLUTION,
		VIEW_CIVILRIGHTS }
	),
	/* Law enforcement block */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_DEATHSQUAD,
		{ VIEW_PRISONS,
		VIEW_DEATHPENALTY,
		VIEW_POLICEBEHAVIOR,
		VIEW_DRUGS,
		VIEW_TORTURE,
		VIEW_GUNCONTROL,
		VIEW_PRISONS }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SWAT,
		{ VIEW_POLICEBEHAVIOR,
		VIEW_DRUGS,
		VIEW_TORTURE,
		VIEW_GUNCONTROL,
		VIEW_PRISONS }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_COP,
		{ VIEW_POLICEBEHAVIOR,
		VIEW_DRUGS,
		VIEW_TORTURE,
		VIEW_GUNCONTROL,
		VIEW_PRISONS }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_GANGUNIT,
		{ VIEW_POLICEBEHAVIOR,
		VIEW_DRUGS,
		VIEW_TORTURE,
		VIEW_GUNCONTROL,
		VIEW_PRISONS }
	),
	/* Prison block */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_EDUCATOR,
		{ VIEW_POLICEBEHAVIOR,
		VIEW_DEATHPENALTY,
		VIEW_DRUGS,
		VIEW_TORTURE,
		VIEW_PRISONS }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_PRISONGUARD,
		{ VIEW_POLICEBEHAVIOR,
		VIEW_DEATHPENALTY,
		VIEW_DRUGS,
		VIEW_TORTURE,
		VIEW_PRISONS }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_PRISONER,
		{ VIEW_POLICEBEHAVIOR,
		VIEW_DEATHPENALTY,
		VIEW_DRUGS,
		VIEW_TORTURE,
		VIEW_PRISONS }
	),
	/* Intelligence block */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SECRET_SERVICE,
		{ VIEW_INTELLIGENCE }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_AGENT,
		{ VIEW_INTELLIGENCE,
		VIEW_TORTURE,
		VIEW_PRISONS,
		VIEW_FREESPEECH }
	),
	/* Military block */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_MERC,
		{ VIEW_GUNCONTROL }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SOLDIER,
		{ VIEW_MILITARY,
		VIEW_TORTURE,
		VIEW_GAY,
		VIEW_WOMEN }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_VETERAN,
		{ VIEW_MILITARY,
		VIEW_TORTURE,
		VIEW_GAY,
		VIEW_WOMEN }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_MILITARYPOLICE,
		{ VIEW_MILITARY,
		VIEW_TORTURE,
		VIEW_GAY,
		VIEW_WOMEN }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_MILITARYOFFICER,
		{ VIEW_MILITARY,
		VIEW_TORTURE,
		VIEW_GAY,
		VIEW_WOMEN }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SEAL,
		{ VIEW_MILITARY,
		VIEW_TORTURE,
		VIEW_GAY,
		VIEW_WOMEN }
	),
	/* Sweatshop workers */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_WORKER_SWEATSHOP,
		{ VIEW_IMMIGRATION,
		VIEW_SWEATSHOPS }
	),
};

void printCreatureLeaksIntelligence(const string crname);
void printCreatureLeaksPolice(const string crname);
void printCreatureLeaksCorp(const string crname);
void printCreatureLeaksPrison(const string crname);
void printCreatureLeaksCable(const string crname);
void printCreatureLeaksRadio(const string crname);
void printCreatureLeaksAnimalResearch(const string crname);
void printCreatureLeaksJudiciary(const string crname);
void printCreatureLeaksCCS(const string crname);
void printArrestedWhileEmbezzling(const string crname);
void printHasBeenCaughtSnooping(const string crname);
void printArrestedWhileStealing(const string crname);
void printSleeperDropOffPackage(const string crname);
void printxmlFail(const int numberofxmlfails);
void pressAnyKey();
//#endif//SLEEPER_UPDATE_CPP
//#endif// INCLUDES_H_INCLUDED
