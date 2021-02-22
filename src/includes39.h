




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
const int RNG_SIZE = 4;  // needed for locations.h
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

#include "includesDeprecatedB.h"
//#ifdef	EXTERNALLYSTOREDDATA_CPP
// externallyStoredData.cpp

const string SINGLE_SPACE = " ";

#include "../creature/creature.h"
#include "../locations/locations.h"
#include "../common/ledgerEnums.h"
#include "../customMaps.h"
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
