




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


enum CarChaseObstacles
{
	CARCHASE_OBSTACLE_FRUITSTAND,
	CARCHASE_OBSTACLE_TRUCKPULLSOUT,
	CARCHASE_OBSTACLE_CROSSTRAFFIC,
	CARCHASE_OBSTACLE_CHILD,
	CARCHASE_OBSTACLENUM
};

enum MusicModes
{
	MUSIC_TITLEMODE,
	MUSIC_NEWGAME,
	MUSIC_BASEMODE,
	MUSIC_SIEGE,
	MUSIC_ACTIVATE,
	MUSIC_SLEEPERS,
	MUSIC_STOPEVIL,
	MUSIC_REVIEWMODE,
	MUSIC_LIBERALAGENDA,
	MUSIC_DISBANDED,
	MUSIC_FINANCES,
	MUSIC_CARTHEFT,
	MUSIC_ELECTIONS,
	MUSIC_SHOPPING,
	MUSIC_SITEMODE,
	MUSIC_SUSPICIOUS,
	MUSIC_ALARMED,
	MUSIC_HEAVYCOMBAT,
	MUSIC_DEFENSE,
	MUSIC_CONQUER,
	MUSIC_CARCHASE,
	MUSIC_FOOTCHASE,
	MUSIC_INTERROGATION,
	MUSIC_TRIAL,
	MUSIC_RECRUITING,
	MUSIC_DATING,
	MUSIC_NEWSPAPER,
	MUSIC_LACOPS,
	MUSIC_NEWSCAST,
	MUSIC_GLAMSHOW,
	MUSIC_ANCHOR,
	MUSIC_ABORT,
	MUSIC_VICTORY,
	MUSIC_DEFEAT,
	MUSIC_REAGANIFIED,
	MUSIC_STALINIZED,
	MUSIC_OFF, // this one must come immediately after the ones corresponding to music files (this one is to have silence)
	MUSIC_PREVIOUS, // this one must come after MUSIC_OFF (this one is to play the previous song)
	MUSIC_CURRENT, // this one must come after MUSIC_OFF (this one continues playing the current song)
	MUSIC_RANDOM // this one must come after MUSIC_OFF (this one plays a random song)
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

enum NewsStories
{
	NEWSSTORY_MAJOREVENT,
	NEWSSTORY_SQUAD_SITE,
	NEWSSTORY_SQUAD_ESCAPED,
	NEWSSTORY_SQUAD_FLEDATTACK,
	NEWSSTORY_SQUAD_DEFENDED,
	NEWSSTORY_SQUAD_BROKESIEGE,
	NEWSSTORY_SQUAD_KILLED_SIEGEATTACK,
	NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE,
	NEWSSTORY_SQUAD_KILLED_SITE,
	NEWSSTORY_CCS_SITE,
	NEWSSTORY_CCS_DEFENDED,
	NEWSSTORY_CCS_KILLED_SIEGEATTACK,
	NEWSSTORY_CCS_KILLED_SITE,
	NEWSSTORY_CARTHEFT,
	NEWSSTORY_MASSACRE,
	NEWSSTORY_KIDNAPREPORT,
	NEWSSTORY_NUDITYARREST,
	NEWSSTORY_WANTEDARREST,
	NEWSSTORY_DRUGARREST,
	NEWSSTORY_GRAFFITIARREST,
	NEWSSTORY_BURIALARREST,
	NEWSSTORY_RAID_CORPSESFOUND,
	NEWSSTORY_RAID_GUNSFOUND,
	NEWSSTORY_HOSTAGE_RESCUED,
	NEWSSTORY_HOSTAGE_ESCAPES,
	NEWSSTORY_CCS_NOBACKERS,
	NEWSSTORY_CCS_DEFEATED,
	NEWSSTORY_PRESIDENT_IMPEACHED,
	NEWSSTORY_PRESIDENT_BELIEVED_DEAD,
	NEWSSTORY_PRESIDENT_FOUND_DEAD,
	NEWSSTORY_PRESIDENT_FOUND,
	NEWSSTORY_PRESIDENT_KIDNAPPED,
	NEWSSTORY_PRESIDENT_MISSING,
	NEWSSTORY_PRESIDENT_ASSASSINATED,
	NEWSSTORYNUM
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

const int RNG_SIZE = 4;  // needed for locations.h

//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

//int get_associated_attribute(int skill_type);

enum Bouncer_Reject_Reason
{
	REJECTED_CCS,
	REJECTED_NUDE,
	REJECTED_WEAPONS,
	REJECTED_UNDERAGE,
	REJECTED_FEMALEISH,
	REJECTED_FEMALE,
	REJECTED_BLOODYCLOTHES,
	REJECTED_DAMAGEDCLOTHES,
	REJECTED_CROSSDRESSING,
	REJECTED_GUESTLIST,
	REJECTED_DRESSCODE,
	REJECTED_SECONDRATECLOTHES,
	REJECTED_SMELLFUNNY,
	NOT_REJECTED
};


//#ifdef	EXTERNALLYSTOREDDATA_CPP
// externallyStoredData.cpp

const string SINGLE_SPACE = " ";

#include "../creature/creature.h"
#include "../locations/locations.h"
#include "../common/ledgerEnums.h"
#include "../customMaps.h"

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


struct ChangeOfOpinion
{
	Views view;
	int x, y, z;
	ChangeOfOpinion(Views view_, int x_, int y_, int z_) : view(view_), x(x_), y(y_), z(z_) { }
};

struct activityData
{
	const char* msgString;
	CheckDifficulty difficulty;
	int juiceval;
	Lawflags crime;
	vector<ChangeOfOpinion> opinion;
	vector<string> lootType;
	activityData(const char* msgString_, CheckDifficulty difficulty_, int juiceval_, Lawflags crime_, vector<ChangeOfOpinion> opinion_, vector<string> lootType_) : msgString(msgString_), difficulty(difficulty_), juiceval(juiceval_), crime(crime_), opinion(opinion_), lootType(lootType_) { }
};
#include "../set_color_support.h"
file_and_text_collection customText(vector<string>  *collection_, string fileName_) {
	file_and_text_collection newWound;
	newWound.collection = collection_;
	newWound.fileName = fileName_;
	newWound.superCollection = false;
	return newWound;
}
file_and_text_collection customText(string fileName_) {
	file_and_text_collection newWound;
	vector<string> vsr;
	vsr.push_back(SINGLE_SPACE);
	newWound.collection = &vsr;
	newWound.fileName = fileName_;
	newWound.superCollection = false;
	return newWound;
}
file_and_text_collection customText(vector<vector<string> >  *collection_, string fileName_, int dimensions_) {
	file_and_text_collection newWound;
	newWound.super_collection = collection_;
	newWound.fileName = fileName_;
	newWound.dimensions = dimensions_;
	newWound.superCollection = true;
	return newWound;
}
file_and_text_collection customText(string fileName_, int dimensions_) {
	file_and_text_collection newWound;
	newWound.fileName = fileName_;
	newWound.dimensions = dimensions_;
	newWound.superCollection = true;
	return newWound;
}
struct stringAndColor
{
	string str;
	ColorSetup type;
	stringAndColor(string str_, ColorSetup type_) : str(str_), type(type_) { }
	stringAndColor(ColorSetup type_, string str_) : str(str_), type(type_) { }
};
int getLawFromFlag(int type);

extern  map<Activity, Data_Activity> data_activities;
extern map< Activity, CreatureSkill> trainingActivity;
extern map< Views, stringConnectedToView > pollingData;
extern map<char, vector<ActivityAndString> > activate_menu_items;
extern map<int, vector<string> > caseRejectionReasons;
extern map<int, vector<string> > rejectionReasons;
extern map<short, map<short, string> > getLawFlagStringFull;
extern map<short, string> animalBodyParts;
extern map<short, string> attEnumToString;
extern map<short, string> buildThisSite;
extern map<short, string> cityNames;
extern map<short, string> conservatiseLaw;
extern map<short, string> conservativeLegalArgument;
extern map<short, string> discussesIssues;
extern map<short, string> discussIssues;
extern map<short, string> enumToCreature;
extern map<short, string> expenseTypes;
extern map<short, string> getActivityString;
extern map<short, string> getAlignString;
extern map<short, string> getCityDescription;
extern map<short, string> getLawFlagString;
extern map<short, string> getLawString;
extern map<short, string> humanBodyParts;
extern map<short, string> incomeTypes;
extern map<short, string> issueEventString;
extern map<short, string> issueTooLiberal;
extern map<short, string> liberalizeLaw;
extern map<short, string> musicList;
extern map<short, string> reviewStrings;
extern map<short, string> reviewStringsSecondLine;
extern map<short, string> siteReadMap;
extern map<short, string> skillEnumToString;
extern map<short, string> supportsLiberalLaw;
extern map<short, string> tankBodyParts;
extern map<short, string> trainingActivitySorting;
extern map<short, string> winnerOfElection;
extern map<short, string> youAreStupidTalkAboutIssues;
extern map<short, vector<string> > carchaseObstacles;
extern map<short, vector<string> > endgameLawStrings;
extern map<short, vector<string> > getSiteName;
extern map<short, vector<string> > getViewString;
extern map<short, vector<string> > helpTopics;
extern map<short, vector<string> > newsStories;
extern map<short, vector<string> > talkAboutTheIssues;
extern map<string, short> getAttributeEnumFromString;
extern map<string, short> getBaseEnumFromString;
extern map<string, short> getCreatureEnumFromString;
extern map<string, short> getSkillEnumFromString;
extern map<string, short> getSpecial;
extern map<string, short> getSpecialWoundEnumFromString;
extern map<string, short> getUnique;
extern map<string, short> site_tile_list;
extern map<string, string> getLootString;
extern vector<ActivityAndString> data_lessons;
extern vector<activityData> hackingActivities;
extern vector<CreatureTypes> ACTIVITY_TEACH_COVERT_DEFAULT;
extern vector<CreatureTypes> ACTIVITY_TEACH_FIGHTING_DEFAULT;
extern vector<CreatureTypes> ACTIVITY_TEACH_POLITICS_DEFAULT;
extern vector<int> state_biases;
extern vector<RecruitData> recruitable_creatures;
extern vector<string> theGreatUnknown;
extern vector<stringAndColor> liberalListAndColor;

bool initialize_more_incomplete_txt();
//#endif//EXTERNALLYSTOREDDATA_CPP
//#endif// INCLUDES_H_INCLUDED
