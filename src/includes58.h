




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

enum Views
{
	VIEW_STALIN = -2, // this one is -2 and is actually calculated based on views >=0 and <VIEWNUM-3
	VIEW_MOOD, // this one is -1 and is likewise calculated based on views >=0 and <VIEWNUM-3
	VIEW_GAY, // view #0, the first one that is actually in the attitude[] array
	VIEW_DEATHPENALTY,
	VIEW_TAXES,
	VIEW_NUCLEARPOWER,
	VIEW_ANIMALRESEARCH,
	VIEW_POLICEBEHAVIOR,
	VIEW_TORTURE,
	VIEW_INTELLIGENCE,
	VIEW_FREESPEECH,
	VIEW_GENETICS,
	VIEW_JUSTICES,
	VIEW_GUNCONTROL,
	VIEW_SWEATSHOPS,
	VIEW_POLLUTION,
	VIEW_CORPORATECULTURE,
	VIEW_CEOSALARY,
	VIEW_WOMEN,//XXX: VIEW_ABORTION DOES NOT EXIST
	VIEW_CIVILRIGHTS,
	VIEW_DRUGS,
	VIEW_IMMIGRATION,
	VIEW_MILITARY,
	VIEW_PRISONS,
	//*JDS* I'm using VIEWNUM-5 in a random generator that rolls a
	//random issue, not including the media/politicalviolence ones, and this will
	//break if these stop being the last 4 issues; do a search
	//for VIEWNUM-5 to change it if it needs to be changed.
	VIEW_AMRADIO,
	VIEW_CABLENEWS,
	//THESE THREE MUST BE LAST FOR VIEWNUM-3 TO WORK IN PLACES
	VIEW_LIBERALCRIMESQUAD,
	VIEW_LIBERALCRIMESQUADPOS,
	//THIS ONE MUST BE LAST. randomissue RELIES ON IT BEING LAST TO IGNORE IT IF
	//CCS IS DEAD.
	VIEW_CONSERVATIVECRIMESQUAD,
	VIEWNUM
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
// creaturePool.cpp


#include "../creature/creature.h"

#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../common/creaturePool.h"
#include "../common/creaturePoolCreature.h"
#include "../cursesAlternative.h"
#include "../log/log.h"
#include "../sitemode/advance.h"
/* handles end of round stuff for one creature */
void advancecreature(DeprecatedCreature &cr);

//#include "../common/commonactionsCreature.h"
// Prompt to convert a new recruit into a sleeper
void sleeperize_prompt(DeprecatedCreature& converted, DeprecatedCreature& recruiter, int y);
// Determines the number of love slaves a creature has
int loveslaves(const DeprecatedCreature& cr);
/* Determines the number of subordinates a creature may command */
int maxsubordinates(const DeprecatedCreature& cr);
/* common - removes the liberal from all squads */
void removesquadinfo(DeprecatedCreature& cr);
/* common - applies a crime to a person */
void criminalize(DeprecatedCreature& cr, short crime);
/* Determines the number of subordinates a creature may recruit,
based on their max and the number they already command */
int subordinatesleft(const DeprecatedCreature& cr);
void addjuice(DeprecatedCreature& cr, long juice, long cap);
/* common - determines how long a creature's injuries will take to heal */
int clinictime(DeprecatedCreature &g);

#include "../combat/fightCreature.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
#include "../set_color_support.h"
#include "../common/commondisplay.h"
/* character info at top of screen */
void printcreatureinfo(DeprecatedCreature* cr, unsigned char knowledge = 255);
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../common/getnames.h"
#include "../common/translateid.h"
// for  int getpoolcreature(int)
#include "../daily/siege.h"
#include "../common/commonactions.h"

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


/* common - test for possible game over */
char endcheck(char cause = END_OTHER);
enum LOOP_CONTINUATION {
	RETURN_ZERO,
	RETURN_ONE,
	REPEAT
};



enum DispersalTypes
{
	DISPERSAL_SAFE = -1,
	DISPERSAL_BOSSSAFE,
	DISPERSAL_NOCONTACT,
	DISPERSAL_BOSSINPRISON,
	DISPERSAL_HIDING,
	DISPERSAL_BOSSINHIDING,
	DISPERSAL_ABANDONLCS
};
extern Log gamelog;
extern char disbanding;
extern int stat_recruits;
extern class Ledger ledger;
extern vector<Deprecatedsquadst *> squad;
extern MusicClass music;
extern short lawList[LAWNUM];

void trial(DeprecatedCreature &g);
char prison(DeprecatedCreature &g);


/* displays the high score board */
void viewhighscores(int musicoverride = MUSIC_OFF);
/* saves a new high score */
void savehighscore(char endtype);

void sleepereffect(DeprecatedCreature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM]);

void end_game(int err = EXIT_SUCCESS);
short getCurrentSite();
