




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

//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

//int get_associated_attribute(int skill_type);


#include "includesSDS.h"
// basemode.cpp
#include "../creature/creature.h"
////


#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"

#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
bool liberalagenda(signed char won);
#include "../basemode/baseactions.h"
void activate_sleepers();
void activate();
void review();
#include "../common/translateid.h"
// for  int getsquad(int)
#include "../common/getnames.h"
// for std::string getmonth(int)
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
//for int mvaddstr(int, int, const char*)
#include "../common/commonactions.h"

void equip(vector<Item *> &loot, int loc);
bool stalinview(short view, bool islaw);
void passmonth(char &clearformess, char canseethings);
#include "../daily/daily.h"
//for int monthday();
#include "../daily/siege.h"
//for giveup()
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../common/musicClass.h"
#include "../common/creaturePool.h"
#include "../locations/locationsPool.h"
enum CantSeeReason
{
	CANTSEE_DATING = 1,
	CANTSEE_HIDING = 2,
	CANTSEE_OTHER = 3,
	CANTSEE_DISBANDING = 4
};
bool isPartOfJusticeSystem(int cursite);
bool isThisSafehouse(int loc);
extern bool stalinmode;
extern char cantseereason;
extern char disbanding;
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern class Ledger ledger;
extern Deprecatedsquadst *activesquad;
extern int day;
extern int disbandtime;
extern int month;
extern int selectedsiege;
extern int stat_burns;
extern int stat_buys;
extern int year;
extern Log gamelog;
extern MusicClass music;
extern short attitude[VIEWNUM];
extern short court[COURTNUM];
extern short exec[EXECNUM];
extern short execterm;
extern short house[HOUSENUM];
extern short lawList[LAWNUM];
extern short party_status;
extern short senate[SENATENUM];
extern string slogan_str;
extern vector<DeprecatedCreature *> pool;
extern vector<Deprecatedsquadst *> squad;
int countSafeHouses();
int lenVehiclePool();
Location* getLocation();
void addStringYear();
void burnFlagAtLocation(int l);
void equipLoot(int l, int loc);
void printFlag();

//#endif//BASEMODE_CPP
//#endif// INCLUDES_H_INCLUDED
