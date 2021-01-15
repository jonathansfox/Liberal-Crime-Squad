




/*
	File created by Chris Johnson.
	These were previously all in game.cpp.

	This file includes all the the enums, defines, and included headers required globally by all components.

	All code released under GNU GPL.
*/
#pragma once

#include "includes.h"
using namespace std;

#include "includesDeprecated.h"
#include "includesRandom.h"
/* This is declared again lower down, just needed here for this header. */
std::string tostring(long i);
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
#include "includesSDS.h"
//activate.cpp


#include "../creature/creature.h"
#include "../locations/locations.h"
#include "../items/armortype.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../creature/augmenttype.h"
#include "../common/translateid.h"
// for  int getsquad(int)
//#include "../common/commonactions.h"
void sorting_prompt(short listforsorting);
#include "../common/commonactionsCreature.h"
// for void sortliberals(std::vector<Creature *>&,short,bool)
#include "../common/commondisplay.h"
#include "../common/commondisplayCreature.h"
// for void printfunds(int,int,char*)
//#include "../common/getnames.h"
std::string gettitle(const int align, const int juice);
//#include "../common/help.h"
void HelpActivities(int);
//#include "../common/stringconversion.h"
string attribute_enum_to_string(int);
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
char getseigedFromLocation(int secondaryLocation);
void createTempSquadWithJustThisLiberal(DeprecatedCreature *cr, int cursquadid);
#include "../common/creaturePoolCreature.h"
#include "../common/musicClass.h"

extern bool ZEROMORAL;
extern int selectedsiege;
extern Log gamelog;
extern long cursquadid;
extern MusicClass music;
extern short lawList[LAWNUM];
extern short mode;
extern short activesortingchoice[SORTINGCHOICENUM];
extern vector<ArmorType *> armortype;
extern vector<RecruitData> recruitable_creatures;

const string ACTIVATE_UNINVOLVED_LIBERALS = "Activate Uninvolved Liberals";
const string CODENAME_SKILL_HEALTH_LOCATION_HEADER = "컴컴CODE NAME컴컴컴컴컴컴SKILL컴횴EALTH컴횸OCATION컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";

const string OTHER_CLASSES = "Other classes";
const string CLASSES_COST_SIXTY = "Classes cost $60 a day. Study what?";
const string PRESS_A_LETTER_TO_SELECT_PROFESSION = "Press a Letter to select a Profession";
const string TYPE_DIFFICULTY_HEADER = "컴컴TYPE컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴횯IFFICULTY TO ARRANGE MEETING컴";
const string TRY_TO_MEET_AND_RECRUIT = " try to meet and recruit today?";
const string WHAT_TYPE_OF_PERSON_WILL = "What type of person will ";
const string AGE_COLON = "Age: ";
const string HEART_COLON = "Heart: ";
const string STATUS_COLON = "Status:";
const string HAS_BEEN_BRUTALLY_MURDERED_BY = " has been brutally murdered by ";
const string HAS_BEEN_AUGMENTED_WITH = " has been augmented with ";
const string HAS_BEEN_HORRIBLY_DISFIGURED = " has been horribly disfigured";
const string PRESS_ANY_KEY = "Press any key to return";
const string ARE_YOU_SURE_Y_N = "Are you sure? (y/n)";
const string LONG_LINE_BUT_NOT_EIGHTY = "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴";
const string DESCRIPTION = "Description";
const string CHANCE_AT_SUCCESS_COLON = "Chance at Success: ";
const string SPACE_PLUS = " +";
const string EFFECT_COLON = "Effect: ";
const string AUGMENTATION_COLON = "Augmentation: ";
const string SUBJECT_COLON = "Subject: ";
const string SELECT_AUGMENTATION = "Select an Augmentation";
const string EIGHTY_LINE = "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴";
const string PRESS_A_LETTER_TO_SELECT_LIBERAL = "Press a Letter to select a Liberal";
const string NAME_HEALTH_HEART_HEADER = "컴컴NAME컴컴컴컴컴컴컴컴컴컴컴횴EALTH컴컴컴컴컴컴HEART컴컴컴컴AGE컴컴컴컴컴컴컴�";
const string SELECT_LIBERAL_TO_PERFORM_EXPERIMENTS_UPON = "Select a Liberal to perform experiments on";
const string PRESS_A_LETTER_TO_SELECT_CLOTHING_TYPE = "Press a Letter to select a Type of Clothing";
const string NAME_DIFFICULTY_COST_HEADER = "컴컴NAME컴컴컴컴컴컴컴컴컴컴컴컴컴컴횯IFFICULTY컴컴컴컴컴컴횮OST컴컴컴컴컴컴컴컴";
const string TRY_TO_MAKE_NOTE_HALF_COST_WITH_CLOTH = " try to make?   (Note: Half Cost if you have cloth)";
const string WHICH_WILL = "Which will ";
const string PRESS_A_LETTER_TO_SELECT_CONSERVATIVE = "Press a Letter to select a Conservative";
const string CONST_X_DAY = "Day";
const string CONST_X_DAYS = "Days";
const string DAYS_IN_CAPTIVITY = "DAYS IN CAPTIVITY";
const string BE_WATCHING_OVER = " be watching over?";
const string WHICH_HOSTAGE_WILL = "Which hostage will ";
const string SPACE_WILL_SPACE = " will ";
const string X_NOTHING = "X - Nothing for Now";
const string CONST_X_ENTER_CONFIRM = "Enter - Confirm Selection";
const string QUESTION_HELP = "? - Help";
const string E_EQUIP_THIS_LIBERAL = "E - Equip this Liberal";
const string Z_DIZPOSE_OF_BODIES = "Z - Dispose of bodies";
const string H_HEAL_LIBERALS = "H - Heal Liberals";
const string M_MOVE_TO_CLINIC = "M - Move to the Free Clinic";
const string L_LEARN_IN_UNIVERSITY = "L - Learn in the University District";
const string I_TEND_TO_HOSTAGE = "I - Tend to a Conservative hostage";
const string T_TEACHING_OTHER_LIBERALS = "T - Teaching Other Liberals";
const string BE_DOING_TODAY = " be doing today?";
const string TAKING_ACTION_COLON_WHAT_WILL = "Taking Action: What will ";
const string YESTERDAY_WHAT_NOW = " yesterday. What now?";
const string MADE_DOLLARS = " made $";
const string PRESS_A_LETTER_TO_ASSIGN_ACTIVITY_OR_NUMBER = "Press a Letter to Assign an Activity.  Press a Number to select an Activity.";
const string BULK_ACTIVITY_HEADER = "BULK ACTIVITY";
const string CODE_NAME_CURRENT_ACTIVITY_HEADER = "컴컴CODE NAME컴컴컴컴컴컴CURRENT ACTIVITY컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�";
const string Z_TO_ASSIGN_SIMPLE_TASKS = "Press Z to assign simple tasks in bulk.";
const string CONST_X_T_TO_SORT = " T to sort people.";
const string PRESS_A_LETTER_TO_ASSIGN_ACTIVITY = "Press a Letter to Assign an Activity.";
const string CONST_X_TITLE_ACTIVITY = "ACTIVITY";
const string MOSTLY_ENDINGS_FOLDER = "mostlyendings\\";

const string STANDARD_ACTIVITIES_AND_DATA_TXT = "standard_activities_and_data.txt";
const string BULK_ACTIVITY_STRING_TXT = "bulkActivityString.txt";
vector<ActivityAndString> data_lessons;
map<Activity, Data_Activity> data_activities;
map<char, vector<ActivityAndString> > activate_menu_items;

vector<CreatureTypes> ACTIVITY_TEACH_FIGHTING_DEFAULT;
// this first block are creatures with All Weapon Skills, Martial Arts, Dodge, and First Aid
vector<CreatureTypes> ACTIVITY_TEACH_COVERT_DEFAULT;
// this second block are creatures with Computers, Security, Stealth, Disguise, Tailoring, Seduction, Psychology, & Driving
vector<CreatureTypes> ACTIVITY_TEACH_POLITICS_DEFAULT;
// this third block are creatures with Writing, Persuasion, Law, Street Sense, Science, Religion, Business, Music, & Art
