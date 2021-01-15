




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

#include "includesSDS.h"
string skill_enum_to_string(int skill_type);
// commondisplay.cpp
#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locationsEnums.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../sitemode/stealth.h"
#include "../common/getnames.h"
// for getmonth
#include "../common/translateid.h"
// for  int getcar(int)
#include "../common/commonactionsCreature.h"
// for void sortliberals(std::vector<Creature *>&,short,bool)
#include "../daily/siege.h"
// for statebrokenlaws(cr);
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"

std::string gettitle(const int align, const int juice);
bool isThereNoActivesquad();
bool isThereASiteAlarm();
void makedelimiter(int y = 8, int x = 0);
void printcreatureinfo(DeprecatedCreature *cr, unsigned char knowledge = 255);
void set_color_for_armor(const Armor armor);
void setColorForArmor(const Armor ar);
void statebrokenlaws(CreatureJustice cr, const int flag);

extern bool mapshowing;
extern char showcarprefs;
extern Deprecatedsquadst *activesquad;
extern int day;
extern int month;
extern int year;
extern short mode;
extern short party_status;
extern short sitealarmtimer;




const string CONST_X_SINGLE_COMMA = ",";
const string CONST_SpaceOpenParenthesis = " (";
const string NAME_COLON = "Name: ";
const string CODE_NAME_COLON = "Code name: ";
const string CONST_X_COLON_SPACE = ": ";
const string POINT_DOUBLE_ZERO = ".00";
const string NINETY_NINE_PLUS = "99+";
const string DOUBLE_ZERO = "00";
const string CONST_X_DOT = ".";
const string NOW_MAX = "NOW   MAX";
const string CONST_X_SKILL = "SKILL";
const string ON_FOOT = "On \"Foot\"";
const string CONST_X_ON_FOOT = "On Foot";
const string WHEEL_CHAIR = "Wheelchair";
const string CONST_X_DASH_D = "-D";
const string FIFTY_OR_SO_SPACES = "                                                                                ";
const string WEAPON_COLON = "Weapon: ";
const string CONST_X_CUT = "Cut";
const string BRUISED = "Bruised";
const string CONST_X_SHOT = "Shot";
const string CONST_X_LIBERAL = "Liberal";
const string CONST_X_ANIMAL = "Animal";
const string SEVERED = "Severed";
const string RIPPED_OFF = "Ripped off";
const string LEFT_LEG_COLON = "Left Leg:";
const string RIGHT_LEG_COLON = "Right Leg:";
const string LEFT_ARM_COLON = "Left Arm:";
const string RIGHT_ARM_COLON = "Right Arm:";
const string BODY_COLON = "Body:";
const string HEAD_COLON = "Head:";
const string CLOTHES_COLON = "Clothes: ";
const string MISSING_TEETH = "Missing Teeth";
const string NO_TEETH = "No Teeth";
const string NO_TONGUE = "No Tongue";



const string tag_0 = "0";
const string CONST_X_LONG_LINE = "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴";
const string SEVENTY_NINE_LINE = "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컫컴컴컴컴컴컴컴컴컴컴컴컴컫";
const string CONST_X_MODERATE = "Moderate";
const string CONST_X_CONSERVATIVE = "Conservative";
const string CONSRVTV = "Consrvtv";
const string LIGHTLY_WOUNDED = "Lightly Wounded";
const string LTWOUND = "LtWound";
const string WOUNDED = "Wounded";
const string BADLY_WOUNDED = "Badly Wounded";
const string BADWOUND = "BadWound";
const string NEAR_DEATH = "Near Death";
const string NEAR_DETH = "NearDETH";
const string DECEASED = "Deceased";
const string ONE_LEG = "One Leg";
const string ONE_ARM = "One Arm";
const string ONE_ARM_ONE_LEG = "One Arm, One Leg";
const string ONEARMONELEG = "1Arm1Leg";
const string CONST_X_NO_LEGS = "No Legs";
const string CONST_X_NO_ARMS = "No Arms";
const string ONELIMB = "One Limb";
const string NOLIMBS = "No Limbs";
const string MISSING_EYE = "Missing Eye";
const string ONE_EYE = "One Eye";
const string MISSING_NOSE = "Missing Nose";
const string NOSEGONE = "NoseGone";
const string FACE_MUTILATED = "Face Mutilated";
const string FACEMUTL = "FaceMutl";
const string CONST_X_BLIND = "Blind";

const string MISTEETH = "MisTeeth";
const string NOTONGUE = "NoTongue";
const string FACE_GONE = "Face Gone";
const string FACEGONE = "FaceGone";
const string PARAPLEGIC = "Paraplegic";
const string PARAPLEG = "Parapleg";
const string QUADRAPLEGIC = "Quadraplegic";
const string QUADPLEG = "Quadpleg";
const string NECK_BROKEN = "Neck Broken";
const string NCKBROKE = "NckBroke";
const string QUESTION_MARK = "?";
const string CHAR_COLON = "Char:   ";
const string STR_COLON = "Str:    ";
const string AGI_COLON = "Agi:    ";
const string HLTH_COLON = "Hlth:   ";
const string WIS_COLON = "Wis:    ";
const string INT_COLON = "Int:    ";
const string HRT_COLON = "Hrt:    ";
const string AN_ANGRY_HANGIN_JUDGE = "an angry Hangin' Judge";
const string A_FRIGHTENED_EMINENT_SCIENTIST = "a frightened Eminent Scientist";
const string A_SMARMY_NEWS_ANCHOR = "a smarmy News Anchor";
const string A_CRYING_RADIO_PERSON = "a crying Radio Personality";
const string A_SQUIRMING_CEO = "a squirming CEO";
const string A_CURSING_POLITICIAN = "a cursing Politician";
const string CONST_X_BRN = "Brn";
const string CONST_X_TRN = "Trn";
const string CONST_X_BRS = "Brs";
const string CONST_X_SHT = "Sht";
const string CLEAN_SEVER = "Clean sever";
const string TOP_SKILLS_COLON = "Top Skills:";
const string SEVEN_QUESTION_MARKS = "???????";

const string TRANS_COLON = "Trans: ";

const string COMMA_HOLDING = ", holding ";
const string ONE_PARENTHESIS = " (1)";
const string X_X_PARENTHESIS = " (XX)";
const string CONST_X_SLASH = "/";
const string CONST_X_H = "+H";
const string CODENAME_SKILL_WEAPON_ARMOR_HEALTH_HEADER = "#횮ODE NAME컴컴컴컴컴컴SKILL컴훇EAPON컴컴컴컴횫RMOR컴컴컴컴컴HEALTH컴훂RANSPORT�";
const string CONST_X_BURNED = "Burned";
const string CONST_X_TORN = "Torn";
const string SCHEDULED_DATES = "Scheduled Dates:    ";
const string LETTER_S = "s";
const string ROMANTIC_INTEREST = " Romantic Interest";
const string SCHEDULED_MEETINGS = "Scheduled Meetings: ";
const string CANT_RECRUIT = "Can't Recruit";
const string ENLIGHTENED = "Enlightened ";
const string SPACE_MAX = " Max";
const string RECRUITS_SLASH = " Recruits / ";
const string CAR_COLON = "Car: ";
const string JUICE_COLON = "Juice: ";
const string ASTERISK = "*";
const string COMMA_GENDERQUEER = ", Genderqueer";
const string COMMA_FEMALE = ", Female";
const string COMMA_MALE = ", Male";
const string AGE_SPACE = " (Age ";
const string BORN_SPACE = "Born ";
//juiceuntillevelup


const string ONE_THOUSAND = "1000";
const string FIVE_HUNDRED = "500";
const string TWO_HUNDRED = "200";
const string ONE_HUNDRED = "100";
const string CONST_X_NUM_50 = "50";
const string CONST_X_NUM_10 = "10";
const string NEXT_COLON = "Next:  ";
//printcreatureattributes


const string CHARISMA_COLON = "Charisma: ";
const string STRENGTH_COLON = "Strength: ";
const string AGILITY_COLON = "Agility: ";
const string HEALTH_COLON = "Health: ";
const string WISDOM_COLON = "Wisdom: ";
const string INTELLIGENCE_COLON = "Intelligence: ";
const string HEART_COLON = "Heart: ";
//printliberalcrimes

const string CONST_X_NUM = "NUM";
const string CONST_X_CRIME = "CRIME";
const string MONTHS_IN_PRISON = " months in prison.";
const string SENTENCED_TO_SPACE = "Sentenced to ";
const string SERVING_SPACE = "Serving ";
const string SENTENCED_TO_LIFE_IN_PRISON = "Sentenced to life in prison";
const string SERVING_LIFE_IN_PRISON = "Serving life in prison";
const string SENTENCED_TO_DEATH = "Sentenced to DEATH";
const string ON_DEATH_ROW = "On DEATH ROW";
//fullstatus

const string WHAT_IS_NEW_CODENAME = "What is the new code name?                                                      ";
const string UP_DOWN_MORE_INFO = "    UP/DOWN  - More Info";
const string PRESS_KEY_TO_CONTINUE_STRUGGLE = "Press any other key to continue the Struggle";
const string LEFT_RIGHT_OTHER_LIBERALS = "    LEFT/RIGHT - Other Liberals";
const string N_CHANGE_CODENAME_G_FIX_GENDER_LABEL = "N - Change Code Name      G - Fix Gender Label";
const string PROFILE_OF_A_LIBERAL = "Profile of a Liberal";

map<int, map<bool, ColorSetup> > alignmentColors = {
	// Liberal activism
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_ARCHCONSERVATIVE,{ map<bool, ColorSetup>::value_type(true, RED_ON_BLACK_BRIGHT) }),
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_CONSERVATIVE,{ map<bool, ColorSetup>::value_type(true, MAGENTA_ON_BLACK_BRIGHT), map<bool, ColorSetup>::value_type(false, RED_ON_BLACK_BRIGHT) }),
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_MODERATE,{ map<bool, ColorSetup>::value_type(true, YELLOW_ON_BLACK_BRIGHT) }),
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_LIBERAL,{ map<bool, ColorSetup>::value_type(true, CYAN_ON_BLACK_BRIGHT), map<bool, ColorSetup>::value_type(false, GREEN_ON_BLACK_BRIGHT) }),
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_ELITELIBERAL,{ map<bool, ColorSetup>::value_type(true, GREEN_ON_BLACK_BRIGHT) }),
	map<int,  map<bool, ColorSetup> >::value_type(ALIGN_STALINIST,{ map<bool, ColorSetup>::value_type(true, RED_ON_BLACK_BRIGHT) }),
};
map<int, ColorSetup> activityColors = {
	// Liberal activism
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_LIBERAL, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_TROUBLE, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_GRAFFITI, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_DOS_ATTACKS, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_HACKING, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_WRITE_LETTERS, GREEN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_WRITE_GUARDIAN, GREEN_ON_BLACK_BRIGHT),
	// Recruitment
	map<int, ColorSetup>::value_type(ACTIVITY_RECRUITING, GREEN_ON_BLACK),
	// Less exciting liberal activities
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_SPY, BLUE_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_COMMUNITYSERVICE, BLUE_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_POLLS, BLUE_ON_BLACK_BRIGHT),
	// Stealing things
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_STEAL, CYAN_ON_BLACK),
	map<int, ColorSetup>::value_type(ACTIVITY_WHEELCHAIR, CYAN_ON_BLACK),
	map<int, ColorSetup>::value_type(ACTIVITY_STEALCARS, CYAN_ON_BLACK),
	// Illegal fundraising
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_EMBEZZLE, RED_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_SELL_DRUGS, RED_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_PROSTITUTION, RED_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_CCFRAUD, RED_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_DOS_RACKET, RED_ON_BLACK_BRIGHT),
	// Legal fundraising
	map<int, ColorSetup>::value_type(ACTIVITY_DONATIONS, CYAN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_SELL_TSHIRTS, CYAN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_SELL_ART, CYAN_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_SELL_MUSIC, CYAN_ON_BLACK_BRIGHT),
	// Clothing/garment stuff
	map<int, ColorSetup>::value_type(ACTIVITY_REPAIR_ARMOR, CYAN_ON_BLACK),
	map<int, ColorSetup>::value_type(ACTIVITY_MAKE_ARMOR, CYAN_ON_BLACK),
	// Teaching
	map<int, ColorSetup>::value_type(ACTIVITY_TEACH_POLITICS, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_TEACH_FIGHTING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_TEACH_COVERT, MAGENTA_ON_BLACK_BRIGHT),
	//and studying
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_DEBATING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_MARTIAL_ARTS, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_DRIVING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_PSYCHOLOGY, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_FIRST_AID, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_LAW, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_DISGUISE, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_SCIENCE, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_BUSINESS, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_GYMNASTICS, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_ART, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_MUSIC, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_TEACHING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_WRITING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_LOCKSMITHING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_COMPUTERS, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_FENCING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_WEAVING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_RELIGION, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_CLUB, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_STREETSENSE, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_THROWING, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_STEALTH, MAGENTA_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_STUDY_SEDUCTION, MAGENTA_ON_BLACK_BRIGHT),
	// Interrogating
	map<int, ColorSetup>::value_type(ACTIVITY_HOSTAGETENDING, YELLOW_ON_BLACK_BRIGHT),
	// Dealing with your injuries
	map<int, ColorSetup>::value_type(ACTIVITY_CLINIC, RED_ON_BLACK),
	// Doing something Conservative
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_CONSERVATIVE, RED_ON_BLACK_BRIGHT),
	// Dealing with the dead
	map<int, ColorSetup>::value_type(ACTIVITY_BURY, BLACK_ON_BLACK_BRIGHT),
	// Nothing terribly important
	map<int, ColorSetup>::value_type(ACTIVITY_HEAL, WHITE_ON_BLACK),// Identical to none in practice
	map<int, ColorSetup>::value_type(ACTIVITY_NONE, WHITE_ON_BLACK),
	map<int, ColorSetup>::value_type(ACTIVITYNUM, WHITE_ON_BLACK),
	// Going somewhere
	map<int, ColorSetup>::value_type(ACTIVITY_VISIT, YELLOW_ON_BLACK_BRIGHT),
	// Quitting being a sleeper to join the LCS
	map<int, ColorSetup>::value_type(ACTIVITY_SLEEPER_JOINLCS, RED_ON_BLACK_BRIGHT),
	map<int, ColorSetup>::value_type(ACTIVITY_AUGMENT, BLUE_ON_BLACK_BRIGHT),
};
/* checks if a creature's weapon is suspicious or illegal */
char weaponcheck(const DeprecatedCreature &cr, bool metaldetect = false);
/* checks if a creature's uniform is appropriate to the location */
char hasdisguise(const DeprecatedCreature &cr);
string getVehicleShortname(int i);
map<int, string> prisoner_description = {
	map<int, string>::value_type(CREATURE_POLITICIAN, A_CURSING_POLITICIAN),
	map<int, string>::value_type(CREATURE_CORPORATE_CEO, A_SQUIRMING_CEO),
	map<int, string>::value_type(CREATURE_RADIOPERSONALITY, A_CRYING_RADIO_PERSON),
	map<int, string>::value_type(CREATURE_NEWSANCHOR, A_SMARMY_NEWS_ANCHOR),
	map<int, string>::value_type(CREATURE_SCIENTIST_EMINENT, A_FRIGHTENED_EMINENT_SCIENTIST),
	map<int, string>::value_type(CREATURE_JUDGE_CONSERVATIVE, AN_ANGRY_HANGIN_JUDGE),
};
vector<string> printSpecialWounds(const char special[SPECIALWOUNDNUM]);
