




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
#include "includesSDS2.h"
//#include "includesDeprecatedB.h"
const string CHOOSE_A_LIBERAL_TO = "Choose a Liberal squad member to ";
//#ifdef	LOCATIONSPOOL_CPP
// locationsPool.cpp

#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../items/armortype.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../common/commondisplay.h"
// for void printfunds(int,int,char*)
#include "../common/stringconversion.h"
//for string attribute_enum_to_string(int)
#include "../common/getnames.h"
// for cityname
#include "../common/translateid.h"
// for  getarmortype
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../set_color_support.h"
#include "locationsPool.h"
#include "../common/creaturePoolCreature.h"
#include "../items/money.h"
#include "../recruits.h"
/* creates your founder */
struct newGameArguments {
	const char recruits;
	const char base;
	const bool makelawyer;
	const bool gaylawyer;
	const bool sports_car;
	newGameArguments(char _recruits, char _base, bool _makelawyer, bool _gaylawyer, bool _sports_car) : recruits(_recruits), base(_base), makelawyer(_makelawyer), gaylawyer(_gaylawyer), sports_car(_sports_car) {}
};
Vehicle* newSportsCar();
void newVehicle(Vehicle *startcar);
#include "../common/equipment.h"
#include "../common/creaturePool.h"
void initlocation(Location &loc);
//#include "sitemode/sitemode.h"
void initsite(Location &loc);
#include "../common/commonactionsCreature.h"

#include "../items/lootTypePoolItem.h"
map<short, string> getActivityString;

vector<SiteTypes> classicDowntown = {
	SITE_RESIDENTIAL_APARTMENT_UPSCALE,
	SITE_GOVERNMENT_POLICESTATION,
	SITE_GOVERNMENT_COURTHOUSE,
	SITE_BUSINESS_BANK,
	SITE_GOVERNMENT_FIRESTATION,
	SITE_MEDIA_AMRADIO,
	SITE_MEDIA_CABLENEWS,
	SITE_BUSINESS_CIGARBAR,
	SITE_BUSINESS_LATTESTAND,
};
vector<SiteTypes> classicCommercial = {

	SITE_BUSINESS_DEPTSTORE,
	SITE_BUSINESS_PAWNSHOP,
	SITE_BUSINESS_HALLOWEEN,
	SITE_BUSINESS_CARDEALERSHIP,
};
vector<SiteTypes> classicUptown = {

	SITE_RESIDENTIAL_APARTMENT,
	SITE_HOSPITAL_UNIVERSITY,
	SITE_HOSPITAL_CLINIC,
	SITE_LABORATORY_GENETIC,
	SITE_LABORATORY_COSMETICS,
	SITE_BUSINESS_VEGANCOOP,
	SITE_BUSINESS_JUICEBAR,
	SITE_BUSINESS_INTERNETCAFE,
	SITE_OUTDOOR_PUBLICPARK,
};
vector<SiteTypes> classicOutOfTown = {

	SITE_GOVERNMENT_PRISON,
	SITE_GOVERNMENT_INTELLIGENCEHQ,
	SITE_INDUSTRY_NUCLEAR,
	SITE_CORPORATE_HEADQUARTERS,
	SITE_CORPORATE_HOUSE,
	SITE_GOVERNMENT_ARMYBASE,
};



vector<SiteTypes> seattleDowntown = {

	SITE_RESIDENTIAL_APARTMENT_UPSCALE,
	SITE_GOVERNMENT_POLICESTATION,
	SITE_GOVERNMENT_COURTHOUSE,
	SITE_BUSINESS_BANK,
	SITE_GOVERNMENT_FIRESTATION,
	SITE_MEDIA_AMRADIO,
	SITE_BUSINESS_CIGARBAR,
	SITE_BUSINESS_LATTESTAND,
	SITE_BUSINESS_DEPTSTORE,
};

vector<SiteTypes> seattleUptown = {

	SITE_RESIDENTIAL_APARTMENT,
	SITE_HOSPITAL_UNIVERSITY,
	SITE_HOSPITAL_CLINIC,
	SITE_LABORATORY_GENETIC,
	SITE_LABORATORY_COSMETICS,
	SITE_BUSINESS_VEGANCOOP,
	SITE_BUSINESS_JUICEBAR,
	SITE_BUSINESS_INTERNETCAFE,
	SITE_OUTDOOR_PUBLICPARK,
	SITE_BUSINESS_HALLOWEEN,
};
vector<SiteTypes> seattleOutOfTown = {

	SITE_GOVERNMENT_PRISON,
	SITE_GOVERNMENT_INTELLIGENCEHQ,
	SITE_CORPORATE_HEADQUARTERS,
	SITE_GOVERNMENT_ARMYBASE,
};

vector<SiteTypes> newYorkManhattan = {

	SITE_RESIDENTIAL_APARTMENT_UPSCALE,
	SITE_GOVERNMENT_POLICESTATION,
	SITE_GOVERNMENT_COURTHOUSE,
	SITE_BUSINESS_BANK,
	SITE_CORPORATE_HEADQUARTERS,
	SITE_MEDIA_AMRADIO,
	SITE_MEDIA_CABLENEWS,
	SITE_BUSINESS_CIGARBAR,
	SITE_OUTDOOR_PUBLICPARK,
	SITE_BUSINESS_DEPTSTORE,
	SITE_GOVERNMENT_PRISON,
};

vector<SiteTypes> newYorkLongIsland = {
	SITE_RESIDENTIAL_APARTMENT,
	SITE_GOVERNMENT_FIRESTATION,
	SITE_HOSPITAL_UNIVERSITY,
	SITE_HOSPITAL_CLINIC,
	SITE_BUSINESS_JUICEBAR,
	SITE_BUSINESS_INTERNETCAFE,
	SITE_INDUSTRY_POLLUTER,
	SITE_LABORATORY_GENETIC,
	SITE_GOVERNMENT_ARMYBASE,
};


vector<SiteTypes> losAngelesDowntown = {



	SITE_RESIDENTIAL_APARTMENT,
	SITE_GOVERNMENT_POLICESTATION,
	SITE_GOVERNMENT_COURTHOUSE,
	SITE_BUSINESS_BANK,
	SITE_GOVERNMENT_FIRESTATION,
	SITE_CORPORATE_HEADQUARTERS,
	SITE_HOSPITAL_UNIVERSITY,
	SITE_BUSINESS_DEPTSTORE,

};


vector<SiteTypes> hollyWoodUptown = {


	SITE_RESIDENTIAL_APARTMENT_UPSCALE,
	SITE_BUSINESS_VEGANCOOP,
	SITE_BUSINESS_HALLOWEEN,
	SITE_BUSINESS_CIGARBAR,
	SITE_MEDIA_AMRADIO,
	SITE_OUTDOOR_PUBLICPARK,
	SITE_CORPORATE_HOUSE,


};


vector<SiteTypes> seaportArea = {


	SITE_RESIDENTIAL_TENEMENT,
	SITE_HOSPITAL_CLINIC,
	SITE_LABORATORY_GENETIC,
	SITE_LABORATORY_COSMETICS,
	SITE_INDUSTRY_POLLUTER,
	SITE_BUSINESS_PAWNSHOP,
	SITE_INDUSTRY_SWEATSHOP,
	SITE_BUSINESS_CARDEALERSHIP,


};

vector<SiteTypes> washingtonDCDowntown = {

	SITE_GOVERNMENT_POLICESTATION,
	SITE_GOVERNMENT_FIRESTATION,
	SITE_GOVERNMENT_COURTHOUSE,
	SITE_BUSINESS_BANK,
	SITE_BUSINESS_CARDEALERSHIP,
	SITE_HOSPITAL_CLINIC,
	SITE_HOSPITAL_UNIVERSITY,
	SITE_BUSINESS_DEPTSTORE,

};
#include "../daily/daily.h"
enum cityLocationTagEnums {
	ENUM_tag_Downtown,
	ENUM_tag_University_District,
	ENUM_tag_u_District,
	ENUM_tag_Industrial_District,
	ENUM_tag_i_District,
	ENUM_tag_Shopping,
	ENUM_tag_Outskirts,
	ENUM_tag_Seaport_Area,
	ENUM_tag_Seaport,
	ENUM_tag_Outskirts_amp_Orange_County,
	ENUM_tag_City_Outskirts,
	ENUM_tag_Arlington,
	ENUM_tag_Hollywood,
	ENUM_tag_Greater_Hollywood,
	ENUM_tag_Manhattan,
	ENUM_tag_Manhattan_Island,
	ENUM_tag_Brooklyn_ampersand_Queens,
	ENUM_tag_Long_Island,
	ENUM_tag_The_Bronx
};

// Check if the player wants to move all items to a new location,
// using Shift + a number key.
const char upnums[] = "!@#$%^&*(";
#include "../daily/siege.h"
void addStringYear();
#include "../common/commonactions.h"
#include "../common/musicClass.h"
#include "../customMaps.h"
enum BusinessFronts
{
	BUSINESSFRONT_INSURANCE,
	BUSINESSFRONT_TEMPAGENCY,
	BUSINESSFRONT_RESTAURANT,
	BUSINESSFRONT_MISCELLANEOUS,
	BUSINESSFRONTNUM
};
// Gives you bloody armor
extern bool GIVEBLOODYARMOR;
// Start with lots of money
extern bool HIGHFUNDS;

extern long cursquadid;
extern vector<ClipType *> cliptype;
extern vector<ArmorType *> armortype;

extern bool multipleCityMode;
extern char endgamestate;
extern class Ledger ledger;
extern Deprecatedsquadst *activesquad;
extern int day;
extern int month;
extern int selectedsiege;
extern int stat_kidnappings;
extern int year;
extern MusicClass music;
extern short background_liberal_influence[VIEWNUM];
extern short lawList[LAWNUM];
extern vector<Deprecatedsquadst *> squad;
extern vector<WeaponType *> weapontype;

/* monthly - lets the player choose a special edition for the guardian */
int choosespecialedition(char &clearformess);
/* monthly - guardian - prints liberal guardian special editions */
void printnews(short l, short newspaper);
#include "../items/itemPool.h"
#include "../items/lootTypePool.h"
void giveActiveSquadThisLoot(Item* de);
const string needCar = " (Need Car)";
const string underSiege = " (Under Siege)";
const string secrecyLevel = "Secrecy: ";
const string heatLevel = "Heat: ";
const string travelDifCity = " - Travel to a Different City";
const string currentLocation = " (Current Location)";
const string safeHouse = " (Safe House)";
const string enemySafeHouse = " (Enemy Safe House)";
const string PARENTHESIS_CLOSED_DOWN = " (Closed Down)";
const string highSecurity = " (High Security)";
const string theLCS = "The Liberal Crime Squad";
const string CONST_POSSESSIONS_GO_TO_THE_SHELTER = ".  Possessions go to the shelter.";
const string CONST_EVICTION_NOTICE = "EVICTION NOTICE: ";
const string CONST_SLEEPER_AGENT = "sleeper agent";
const string CONST_AS_A = " as a ";
const string CONST_STAY_AT = "Stay at ";
const string ARROW_RIGHT = "-> ";
const string CONST_REGULAR_MEMBER = "regular member";
const string CONST_COME_TO = "Come to ";
const string TWO_SPACES = "   ";
const string CONST_BEST_SERVE_THE_LIBERAL_CAUSE = " best serve the Liberal cause?";
const string CONST_IN_WHAT_CAPACITY_WILL = "In what capacity will ";
const string CONST_MALL = "Mall";
const string CONST_X_NEW_YORK = ", New York";
const string CONST_CALIFORNIA = ", California";
const string CONST_VIRGINIA = ", Virginia";
const string CONST_OUTSKIRTS = " Outskirts";

const string CONST_NY = ", NY";
const string CONST_CA = ", CA";
const string CONST_VA = ", VA";
const string CONST_REPORTING_BUGS_TO_THE_DEV_TEAM = "Reporting Bugs to the Dev Team";
const string CONST_GOING_TO = "Going to ";
const string CONST_MAKING = "Making ";
const string CONST_A_BUG = "a bug";
const string CONST_TENDING_TO = "Tending to ";
const string CONST_HOW_MANY = "     How many?          ";
const string CONST_Z_STASH_THINGS_AT = "Z - Stash things at ";
const string CONST_Y_GET_THINGS_FROM = "Y - Get things from ";
const string CONST_CURSORS_INCREASE_OR_DECREASE_AMMO_ALLOCATION = "Cursors - Increase or decrease ammo allocation";
const string CONST_S_LIBERALLY_STRIP_A_SQUAD_MEMBER = "S - Liberally Strip a Squad member";
const string CONST_PRESS_A_NUMBER_TO_DROP_THAT_SQUAD_MEMBER_S_CONSERVATIVE_WEAPON = "Press a number to drop that Squad member's Conservative weapon";
const string CONST_PRESS_A_LETTER_TO_EQUIP_A_LIBERAL_ITEM = "Press a letter to equip a Liberal item";
const string CONST_X = " x";
const string CONST_EQUIP_THE_SQUAD = "Equip the Squad";

const string CONST_RECEIVE_IT = "receive it.";
const string CONST_DROP_A_CLIP = "drop a clip.";
const string CONST_RECEIVE_A_CLIP = "receive a clip.";
const string NOT_ERROR_BUT_CONTINUE = "For simplicity this function returns an error message, prompting 'continue;', this is not an error, but it needs to use 'continue;' anyway";
const string CONST_CAN_T_CARRY_ANY_MORE_AMMO = "Can't carry any more ammo.";
const string CONST_THAT_AMMO_DOESN_T_FIT = "That ammo doesn't fit.";
const string CONST_CAN_T_CARRY_AMMO_WITHOUT_A_GUN = "Can't carry ammo without a gun.";
const string CONST_NO_AMMO_AVAILABLE = "No ammo available!";
const string CONST_NO_AMMO_REQUIRED = "No ammo required!";
const string CONST_NO_SPARE_CLIPS = "No spare clips!";
const string CONST_NO_AMMO_TO_DROP = "No ammo to drop!";

const string CONST_STRIP_DOWN = "strip down.";

const string CONST_YOU_CAN_T_EQUIP_THAT = "You can't equip that.";
const string CONST_PRESS_A_LETTER_TO_SELECT_AN_ITEM = "Press a letter to select an item.";
const string CONST_X_X = "x";
const string CONST_SLASH = "/";
const string CONST_SELECT_OBJECTS = "Select Objects";
const string CONST_TO_VIEW_OTHER_BASE_PAGES = ",. to view other base pages.";
const string CONST_SHIFT_AND_A_NUMBER_WILL_MOVE_ALL_ITEMS = "  Shift and a Number will move ALL items!";
const string CONST_T_TO_SORT_BY_TYPE = "T to sort by type.";
const string CONST_T_TO_SORT_BY_LOCATION = "T to sort by location.";
const string CONST_PRESS_A_LETTER_TO_ASSIGN_A_BASE_PRESS_A_NUMBER_TO_SELECT_A_BASE = "Press a Letter to assign a base.  Press a Number to select a base.";
const string CONST_NEW_LOCATION = "NEW LOCATION";
const string CONST_ITEM_CURRENT_LOCATION = "컴컴ITEM컴컴컴컴컴컴컴컴CURRENT LOCATION컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�";
const string CONST_MOVING_EQUIPMENT = "Moving Equipment";
const string CONST_EATING = " Eating";
const string CONST_S = "s";
const string CONST_DAILY_RATION = " Daily Ration";
const string CONST_NOT_ENOUGH_FOOD = "Not Enough Food";
const string CONST_OF_FOOD_LEFT = " of Food Left";
const string CONST_X_SPACE_DAY = " Day";
const string CONST_GENERATOR = "GENERATOR";
const string CONST_LIGHTS_OUT = "LIGHTS OUT";
const string CONST_TANK_TRAPS = "TANK TRAPS";
const string CONST_AA_GUN = "AA GUN";
const string CONST_BOOBY_TRAPS = "BOOBY TRAPS";
const string CONST_CAMERAS_ON = "CAMERAS ON";
const string CONST_CAMERAS_OFF = "CAMERAS OFF";
const string CONST_BUSINESS_FRONT = "BUSINESS FRONT";
const string CONST_PRINTING_PRESS = "PRINTING PRESS";
const string CONST_FORTIFIED_COMPOUND = "FORTIFIED COMPOUND";
const string CONST_THIS_LOCATION_HAS_INSUFFICIENT_FOOD_STORES = "This location has insufficient food stores.";
const string CONST_THIS_LOCATION_HAS_FOOD_FOR_ONLY_A_FEW_DAYS = "This location has food for only a few days.";
const string CONST_YOU_ARE_NOT_UNDER_SIEGE_YET = "You are not under siege...  yet.";
const string CONST_FIREMEN_ARE_RAIDING_THIS_LOCATION = "Firemen are raiding this location!";
const string CONST_THE_CCS_IS_RAIDING_THIS_LOCATION = "The CCS is raiding this location!";
const string CONST_THE_CORPORATIONS_ARE_RAIDING_THIS_LOCATION = "The Corporations are raiding this location!";
const string CONST_THE_MASSES_ARE_STORMING_THIS_LOCATION = "The masses are storming this location!";
const string CONST_THE_CIA_IS_RAIDING_THIS_LOCATION = "The CIA is raiding this location!";
const string CONST_THE_POLICE_ARE_RAIDING_THIS_LOCATION = "The police are raiding this location!";
const string CONST_THE_POLICE_HAVE_SURROUNDED_THIS_LOCATION = "The police have surrounded this location.";
const string CONST_ACTING_INDIVIDUALLY = "Acting Individually";
const string CONST_2_PRESS_Z_TO_ASSEMBLE_A_NEW_SQUAD = "2) Press Z to Assemble a New Squad";
const string CONST_1_R_REVIEW_ASSETS_AND_FORM_SQUADS = "1) R - Review Assets and Form Squads";
const string CONST_TO_FORM_A_NEW_SQUAD = "To form a new squad:";
const string CONST_NO_SQUAD_SELECTED = "No Squad Selected";
const string CONST_ENTER_BACK_ONE_STEP = "Enter - Back one step.";
const string CONST_ENTER_THE_SQUAD_IS_NOT_YET_LIBERAL_ENOUGH = "Enter - The squad is not yet Liberal enough.";
const string CONST_WHERE_WILL_THE_SQUAD_GO = "Where will the Squad go?";
const string MOSTLY_ENDINGS_FOLDER = "mostlyendings\\";
const string CONST_CASEBUSINESSFRONT_MISCELLANEOUS_TXT = "caseBUSINESSFRONT_MISCELLANEOUS.txt";
const string CONST_CASEBUSINESSFRONT_RESTAURANT_TXT = "caseBUSINESSFRONT_RESTAURANT.txt";
const string CONST_CASEBUSINESSFRONT_TEMPAGENCY_TXT = "caseBUSINESSFRONT_TEMPAGENCY.txt";
const string CONST_CASEBUSINESSFRONT_INSURANCE_TXT = "caseBUSINESSFRONT_INSURANCE.txt";
const string CONST_R_STOCKPILE_20_DAILY_RATIONS_OF_FOOD_150 = "R - Stockpile 20 daily rations of food ($150)";
const string CONST_F_SETUP_A_BUSINESS_FRONT_TO_WARD_OFF_SUSPICION_3000 = "F - Setup a Business Front to ward off suspicion ($3000)";
const string CONST_P_BUY_A_PRINTING_PRESS_TO_START_YOUR_OWN_NEWSPAPER_3000 = "P - Buy a Printing Press to start your own newspaper ($3000)";
const string CONST_A_INSTALL_AND_CONCEAL_AN_ILLEGAL_ANTI_AIRCRAFT_GUN_ON_THE_ROOF_200_000 = "A - Install and conceal an illegal Anti-Aircraft gun on the roof ($200,000)";
const string CONST_A_INSTALL_A_PERFECTLY_LEGAL_ANTI_AIRCRAFT_GUN_ON_THE_ROOF_35_000 = "A - Install a perfectly legal Anti-Aircraft gun on the roof ($35,000)";
const string CONST_G_BUY_A_GENERATOR_FOR_EMERGENCY_ELECTRICITY_3000 = "G - Buy a Generator for emergency electricity ($3000)";
const string CONST_T_RING_THE_COMPOUND_WITH_TANK_TRAPS_3000 = "T - Ring the Compound with Tank Traps ($3000)";
const string CONST_B_PLACE_BOOBY_TRAPS_THROUGHOUT_THE_COMPOUND_3000 = "B - Place Booby Traps throughout the Compound ($3000)";
const string CONST_C_PLACE_SECURITY_CAMERAS_AROUND_THE_COMPOUND_2000 = "C - Place Security Cameras around the Compound ($2000)";
const string CONST_W_FORTIFY_THE_COMPOUND_FOR_A_SIEGE_2000 = "W - Fortify the Compound for a Siege ($2000)";
const string CONST_W_FORTIFY_THE_BOMB_SHELTER_ENTRANCES_2000 = "W - Fortify the Bomb Shelter Entrances ($2000)";
const string CONST_W_REPAIR_THE_BUNKER_FORTIFICATIONS_2000 = "W - Repair the Bunker Fortifications ($2000)";
const string CONST_X_IF_YOU_DO_NOT_ENTER_ANYTHING_THEIR_REAL_NAME_WILL_BE_USED = "If you do not enter anything, their real name will be used.";
const string CONST_X_IN_ITS_PRESENCE = " in its presence?";
const string CONST_X_WHAT_NAME_WILL_YOU_USE_FOR_THIS_ = "What name will you use for this ";
const string CONST_THE_EDUCATION_OF = "The Education of ";
const string CONST_TEMPORARY_SQUAD = "Temporary Squad";
const string tag_WEAPON_SPRAYCAN = "WEAPON_SPRAYCAN";

const string tag_LOOT = "LOOT";
const string tag_LOOT_SECRETDOCUMENTS = "LOOT_SECRETDOCUMENTS";
const string tag_LOOT_INTHQDISK = "LOOT_INTHQDISK";
const string tag_The_Bronx = "The Bronx";
const string tag_Long_Island = "Long Island";
const string tag_Brooklyn_ampersand_Queens = "Brooklyn & Queens";
const string tag_B = "B";
const string tag_Manhattan = "Manhattan";
const string tag_The = "The ";
const string tag_Manhattan_Island = "Manhattan Island";
const string tag_Greater_Hollywood = "Greater Hollywood";
const string tag_Hollywood = "Hollywood";
const string tag_Arlington = "Arlington";
const string tag_City_Outskirts = "City Outskirts";
const string tag_Seaport_Area = "Seaport Area";
const string tag_Shopping = "Shopping";
const string tag_Seaport = "Seaport";
const string tag_Outskirts_amp_Orange_County = "Outskirts & Orange County";
const string tag_Outskirts = "Outskirts";
const string tag_University_District = "University District";
const string tag_i_District = "I-District";
const string tag_Industrial_District = "Industrial District";
const string tag_u_District = "U-District";
const string tag_D = "D";
const string tag_Downtown = "Downtown";
const string tag_National_Mall = "National Mall";
const string tag_ARMOR = "ARMOR";
const string tag_ARMOR_CLOTHES = "ARMOR_CLOTHES";
const string tag_CLIP = "CLIP";
const string tag_CLIP_9 = "CLIP_9";
const string tag_WEAPON = "WEAPON";
const string tag_WEAPON_SEMIPISTOL_9MM = "WEAPON_SEMIPISTOL_9MM";
const string tag_WEAPON_SMG_MP5 = "WEAPON_SMG_MP5";
const string tag_WEAPON_AUTORIFLE_AK47 = "WEAPON_AUTORIFLE_AK47";
map <string, int> cityLocationTags = {
map<string, int>::value_type(tag_Downtown, ENUM_tag_Downtown),
map<string, int>::value_type(tag_University_District, ENUM_tag_University_District),
map<string, int>::value_type(tag_u_District, ENUM_tag_u_District),
map<string, int>::value_type(tag_Industrial_District, ENUM_tag_Industrial_District),
map<string, int>::value_type(tag_i_District, ENUM_tag_i_District),
map<string, int>::value_type(tag_Shopping, ENUM_tag_Shopping),
map<string, int>::value_type(tag_Outskirts, ENUM_tag_Outskirts),
map<string, int>::value_type(tag_Seaport_Area, ENUM_tag_Seaport_Area),
map<string, int>::value_type(tag_Seaport, ENUM_tag_Seaport),
map<string, int>::value_type(tag_Outskirts_amp_Orange_County, ENUM_tag_Outskirts_amp_Orange_County),
map<string, int>::value_type(tag_City_Outskirts, ENUM_tag_City_Outskirts),
map<string, int>::value_type(tag_Arlington, ENUM_tag_Arlington),
map<string, int>::value_type(tag_Hollywood, ENUM_tag_Hollywood),
map<string, int>::value_type(tag_Greater_Hollywood, ENUM_tag_Greater_Hollywood),
map<string, int>::value_type(tag_Manhattan, ENUM_tag_Manhattan),
map<string, int>::value_type(tag_Manhattan_Island, ENUM_tag_Manhattan_Island),
map<string, int>::value_type(tag_Brooklyn_ampersand_Queens, ENUM_tag_Brooklyn_ampersand_Queens),
map<string, int>::value_type(tag_Long_Island, ENUM_tag_Long_Island),
map<string, int>::value_type(tag_The_Bronx, ENUM_tag_The_Bronx)
};
