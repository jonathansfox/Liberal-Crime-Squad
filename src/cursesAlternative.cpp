#define	CURSESALTERNATIVE_CPP
#include "includes.h"
#include "../common/commondisplay.h"
#include "../sitemode/sitedisplay.h"

const string CONST_cursesAlternative013 = "]";
const string CONST_cursesAlternative011 = "[";
const string CONST_cursesAlternative008 = " times";
const string CONST_cursesAlternative007 = " five times";
const string CONST_cursesAlternative006 = " four times";
const string CONST_cursesAlternative005 = " three times";
const string CONST_cursesAlternative004 = " twice";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";

const string CONST_sitedisplay102 = "                                                     ";
const string CONST_sitedisplay100 = "                                                                                ";
const string CONST_sitedisplay097 = "                           ";
const string CONST_sitedisplay095 = "LOOT!";
const string CONST_sitedisplay094 = "ENCTR";
const string CONST_sitedisplay093 = "enemy";
const string CONST_sitedisplay092 = "ENEMY";
const string CONST_sitedisplay091 = "SQUAD";
const string CONST_sitedisplay090 = "The Office of the President";
const string CONST_sitedisplay089 = "CCS Boss";
const string CONST_sitedisplay088 = "Oh Wow So Much Money";
const string CONST_sitedisplay087 = "Bank Teller";
const string CONST_sitedisplay086 = "Bank Vault";
const string CONST_sitedisplay085 = "Bench";
const string CONST_sitedisplay084 = "Computer";
const string CONST_sitedisplay083 = "Table";
const string CONST_sitedisplay082 = "Stairs Down";
const string CONST_sitedisplay081 = "Stairs Up";
const string CONST_sitedisplay080 = "Display Case";
const string CONST_sitedisplay079 = "Sign";
const string CONST_sitedisplay078 = "Landlord's Office";
const string CONST_sitedisplay077 = "News Broadcast Studio";
const string CONST_sitedisplay076 = "Radio Broadcast Room";
const string CONST_sitedisplay075 = "Safe";
const string CONST_sitedisplay074 = "CEO's Study";
const string CONST_sitedisplay073 = "Armory";
const string CONST_sitedisplay072 = "Factory Equipment";
const string CONST_sitedisplay071 = "Textile Equipment";
const string CONST_sitedisplay070 = "Supercomputer";
const string CONST_sitedisplay069 = "Prison Control Room";
const string CONST_sitedisplay068 = "Jury Room";
const string CONST_sitedisplay067 = "Courthouse Jail";
const string CONST_sitedisplay066 = "Police Detention Room";
const string CONST_sitedisplay065 = "Caged \"Animals\"";
const string CONST_sitedisplay064 = "Reactor Control Room";
const string CONST_sitedisplay063 = "Caged Animals";
const string CONST_sitedisplay058 = "ICE";
const string CONST_sitedisplay057 = "OFF";
const string CONST_sitedisplay056 = "AL";
const string CONST_sitedisplay055 = "OV";
const string CONST_sitedisplay054 = "BOSS!";
const string CONST_sitedisplay053 = "TELER";
const string CONST_sitedisplay052 = "VAULT";
const string CONST_sitedisplay051 = "CASE";
const string CONST_sitedisplay050 = "GUARD";
const string CONST_sitedisplay049 = "METAL";
const string CONST_sitedisplay048 = "BENCH";
const string CONST_sitedisplay047 = "CPU";
const string CONST_sitedisplay046 = "TABLE";
const string CONST_sitedisplay045 = "SIGN!";
const string CONST_sitedisplay044 = "RENT?";
const string CONST_sitedisplay043 = "STAGE";
const string CONST_sitedisplay042 = "MIC";
const string CONST_sitedisplay041 = "SAFE!";
const string CONST_sitedisplay040 = "ARMRY";
const string CONST_sitedisplay039 = "EQUIP";
const string CONST_sitedisplay038 = "INTEL";
const string CONST_sitedisplay037 = "CTROL";
const string CONST_sitedisplay036 = "JURY!";
const string CONST_sitedisplay035 = "CELLS";
const string CONST_sitedisplay034 = "CAGES";
const string CONST_sitedisplay033 = "POWER";
const string CONST_sitedisplay031 = "TRAP!";
const string CONST_sitedisplay030 = "~$~";
const string CONST_sitedisplay029 = "EXT";
const string CONST_sitedisplay022 = "LCS";
const string CONST_sitedisplay018 = "CCS";
const string CONST_sitedisplay014 = "GNG";
const string CONST_sitedisplay010 = "   ";
const string CONST_sitedisplay096 = "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ";
const string CONST_sitedisplay062 = "³                         ³";
const string CONST_sitedisplay061 = "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
const string CONST_sitedisplay060 = "ÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂ";
const string CONST_sitedisplay028 = "¼";
const string CONST_sitedisplay027 = "È";
const string CONST_sitedisplay026 = "»";
const string CONST_sitedisplay025 = "É";
const string CONST_sitedisplay024 = "Í";
const string CONST_sitedisplay023 = "º";
const string tag_ARMOR = "ARMOR";
const string tag_MONEY = "MONEY";
const string tag_CEO = "CEO";
const string CONST_consolesupportB011 = "from status line";
const string CONST_consolesupportB010 = "to status line";

const string CONST_consolesupport011 = "rb";
const string CONST_consolesupport012 = "wb";
const string CONST_consolesupport010 = "cleartype.dat";
const string CONST_consolesupport007 = "en_US.CP437";
const string CONST_consolesupport005 = "en_US.UTF-8";
const string CONST_consolesupport004 = "English_United States.437";
const string CONST_consolesupport003 = "fsl";
const string CONST_consolesupport002 = "tsl";
const string CONST_consolesupport001 = "hs";
const string CONST_consolesupport000 = "UTF-8";

//#include "../creature/newcreature.h"

#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"
//#include "../creature/deprecatedCreatureD.h"

////
#include "../common/getnames.h"

#include "../locations/locations.h"
#include "../pdcurses/curses.h"
#include "../log/log.h"

#include "../cursesAlternative.h"
#include "../customMaps.h"
#include <gui_constants.h>

Log gamelog; //The gamelog.
Log xmllog; // Log for xml errors or bad values.

void translategetch(int &c);
void translategetch_cap(int &c);
/* Refreshes the screen, empties the keyboard buffer, waits for a new key to be pressed, and returns the key pressed */
int getkey();
/* Variant of getkey() that doesn't make all letters lowercase */
int getkey_cap();
/* Empties the keyboard buffer, and returns most recent key pressed, if any */
int checkkey();
/* Variant of checkkey() that doesn't make all letters lowercase */
// UNUSED
int checkkey_cap();
#ifdef CH_USE_UNICODE
bool setup_unicode();
#endif
void set_title(char *c);
void init_console();
#include <common\\consolesupport.h>

void set_color(short f, short b, bool bright, bool blink = false);
#include "../set_color_support.h"
const ColorSetup RED_ON_WHITE = { COLOR_RED, COLOR_WHITE, 1 };
const ColorSetup BLUE_ON_WHITE = { COLOR_BLUE, COLOR_WHITE, 1 };
const ColorSetup WHITE_ON_BLUE = { COLOR_WHITE, COLOR_BLUE, 1 };
const ColorSetup BLACK_ON_BLACK = { COLOR_BLACK, COLOR_BLACK };
const ColorSetup BLACK_ON_BLACK_BRIGHT = { COLOR_BLACK, COLOR_BLACK, 1 };
const ColorSetup BLACK_ON_WHITE = { COLOR_BLACK, COLOR_WHITE };
const ColorSetup BLUE_ON_BLACK_BRIGHT = { COLOR_BLUE, COLOR_BLACK, 1 };
const ColorSetup CYAN_ON_BLACK = { COLOR_CYAN, COLOR_BLACK };
const ColorSetup CYAN_ON_BLACK_BRIGHT = { COLOR_CYAN, COLOR_BLACK, 1 };
const ColorSetup GREEN_ON_BLACK = { COLOR_GREEN, COLOR_BLACK };
const ColorSetup GREEN_ON_BLACK_BRIGHT = { COLOR_GREEN, COLOR_BLACK, 1 };
const ColorSetup MAGENTA_ON_BLACK = { COLOR_MAGENTA, COLOR_BLACK };
const ColorSetup MAGENTA_ON_BLACK_BRIGHT = { COLOR_MAGENTA, COLOR_BLACK, 1 };
const ColorSetup RED_ON_BLACK = { COLOR_RED, COLOR_BLACK };
const ColorSetup RED_ON_BLACK_BRIGHT = { COLOR_RED, COLOR_BLACK, 1 };
const ColorSetup RED_ON_BLUE_BRIGHT = { COLOR_RED, COLOR_BLUE, 1 };
const ColorSetup RED_ON_GREEN_BRIGHT = { COLOR_RED, COLOR_GREEN, 1 };
const ColorSetup RED_ON_RED = { COLOR_RED, COLOR_RED };
const ColorSetup RED_ON_RED_BRIGHT = { COLOR_RED, COLOR_RED, 1 };
const ColorSetup RED_ON_WHITE_BRIGHT = { COLOR_RED, COLOR_WHITE, 1 };
const ColorSetup BLUE_ON_WHITE_BRIGHT = { COLOR_BLUE, COLOR_WHITE, 1 };
const ColorSetup WHITE_ON_BLACK = { COLOR_WHITE, COLOR_BLACK };
const ColorSetup WHITE_ON_BLACK_BRIGHT = { COLOR_WHITE, COLOR_BLACK, 1 };
const ColorSetup WHITE_ON_RED_BRIGHT = { COLOR_WHITE, COLOR_RED, 1 };
const ColorSetup WHITE_ON_BLUE_BRIGHT = { COLOR_WHITE, COLOR_BLUE, 1 };
const ColorSetup WHITE_ON_WHITE = { COLOR_WHITE, COLOR_WHITE };
const ColorSetup WHITE_ON_WHITE_BRIGHT = { COLOR_WHITE, COLOR_WHITE, 1 };
const ColorSetup YELLOW_ON_BLACK = { COLOR_YELLOW, COLOR_BLACK };
const ColorSetup YELLOW_ON_BLACK_BRIGHT = { COLOR_YELLOW, COLOR_BLACK, 1 };
const ColorSetup YELLOW_ON_RED = { COLOR_YELLOW, COLOR_RED };
const ColorSetup YELLOW_ON_RED_BRIGHT = { COLOR_YELLOW, COLOR_RED, 1 };
const ColorSetup YELLOW_ON_RED_BRIGHT_BLINK = { COLOR_YELLOW, COLOR_RED, 1, 1 };
void printfunds(int y, int offsetx, const char* prefix, long funds);
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../locations/locationsPool.h"
void printchaseencounter();
bool isThereGroundLoot();
extern coordinatest loc_coord;
extern siteblockst levelmap[MAPX][MAPY][MAPZ];
vector<NameAndAlignment> getEncounterNameAndAlignment();
enum wallDirection {
	WALL_UP = 0,
	WALL_DOWN = 1,
	WALL_LEFT = 2,
	WALL_RIGHT = 3,
	CORNER_UL = 4,
	CORNER_UR = 5,
	CORNER_DL = 6,
	CORNER_DR = 7
};
extern coordinatest loc_coord;
extern siteblockst levelmap[MAPX][MAPY][MAPZ];

extern siteblockst levelmap[MAPX][MAPY][MAPZ];
extern siteblockst levelmap[MAPX][MAPY][MAPZ];
extern siteblockst levelmap[MAPX][MAPY][MAPZ];
map<SpecialBlocks, string> specialString = {
	map<SpecialBlocks, string>::value_type(SPECIAL_LAB_COSMETICS_CAGEDANIMALS, CONST_sitedisplay063),
	map<SpecialBlocks, string>::value_type(SPECIAL_NUCLEAR_ONOFF, CONST_sitedisplay064),
	map<SpecialBlocks, string>::value_type(SPECIAL_LAB_GENETIC_CAGEDANIMALS, CONST_sitedisplay065),
	map<SpecialBlocks, string>::value_type(SPECIAL_POLICESTATION_LOCKUP, CONST_sitedisplay066),
	map<SpecialBlocks, string>::value_type(SPECIAL_COURTHOUSE_LOCKUP, CONST_sitedisplay067),
	map<SpecialBlocks, string>::value_type(SPECIAL_COURTHOUSE_JURYROOM, CONST_sitedisplay068),
	map<SpecialBlocks, string>::value_type(SPECIAL_PRISON_CONTROL, CONST_sitedisplay069),
	map<SpecialBlocks, string>::value_type(SPECIAL_PRISON_CONTROL_LOW, CONST_sitedisplay069),
	map<SpecialBlocks, string>::value_type(SPECIAL_PRISON_CONTROL_MEDIUM, CONST_sitedisplay069),
	map<SpecialBlocks, string>::value_type(SPECIAL_PRISON_CONTROL_HIGH, CONST_sitedisplay069),
	map<SpecialBlocks, string>::value_type(SPECIAL_INTEL_SUPERCOMPUTER, CONST_sitedisplay070),
	map<SpecialBlocks, string>::value_type(SPECIAL_SWEATSHOP_EQUIPMENT, CONST_sitedisplay071),
	map<SpecialBlocks, string>::value_type(SPECIAL_POLLUTER_EQUIPMENT, CONST_sitedisplay072),
	map<SpecialBlocks, string>::value_type(SPECIAL_ARMORY, CONST_sitedisplay073),
	map<SpecialBlocks, string>::value_type(SPECIAL_HOUSE_CEO, CONST_sitedisplay074),
	map<SpecialBlocks, string>::value_type(SPECIAL_HOUSE_PHOTOS, CONST_sitedisplay075),
	map<SpecialBlocks, string>::value_type(SPECIAL_CORPORATE_FILES, CONST_sitedisplay075),
	map<SpecialBlocks, string>::value_type(SPECIAL_RADIO_BROADCASTSTUDIO, CONST_sitedisplay076),
	map<SpecialBlocks, string>::value_type(SPECIAL_NEWS_BROADCASTSTUDIO, CONST_sitedisplay077),
	map<SpecialBlocks, string>::value_type(SPECIAL_APARTMENT_LANDLORD, CONST_sitedisplay078),
	map<SpecialBlocks, string>::value_type(SPECIAL_SIGN_ONE, CONST_sitedisplay079),
	map<SpecialBlocks, string>::value_type(SPECIAL_SIGN_TWO, CONST_sitedisplay079),
	map<SpecialBlocks, string>::value_type(SPECIAL_SIGN_THREE, CONST_sitedisplay079),
	map<SpecialBlocks, string>::value_type(SPECIAL_DISPLAY_CASE, CONST_sitedisplay080),
	map<SpecialBlocks, string>::value_type(SPECIAL_STAIRS_UP, CONST_sitedisplay081),
	map<SpecialBlocks, string>::value_type(SPECIAL_STAIRS_DOWN, CONST_sitedisplay082),
	map<SpecialBlocks, string>::value_type(SPECIAL_RESTAURANT_TABLE, CONST_sitedisplay083),
	map<SpecialBlocks, string>::value_type(SPECIAL_CAFE_COMPUTER, CONST_sitedisplay084),
	map<SpecialBlocks, string>::value_type(SPECIAL_PARK_BENCH, CONST_sitedisplay085),
	map<SpecialBlocks, string>::value_type(SPECIAL_BANK_VAULT, CONST_sitedisplay086),
	map<SpecialBlocks, string>::value_type(SPECIAL_BANK_TELLER, CONST_sitedisplay087),
	map<SpecialBlocks, string>::value_type(SPECIAL_BANK_MONEY, CONST_sitedisplay088),
	map<SpecialBlocks, string>::value_type(SPECIAL_CCS_BOSS, CONST_sitedisplay089),
	map<SpecialBlocks, string>::value_type(SPECIAL_OVAL_OFFICE_NW, CONST_sitedisplay090),
	map<SpecialBlocks, string>::value_type(SPECIAL_OVAL_OFFICE_NE, CONST_sitedisplay090),
	map<SpecialBlocks, string>::value_type(SPECIAL_OVAL_OFFICE_SW, CONST_sitedisplay090),
	map<SpecialBlocks, string>::value_type(SPECIAL_OVAL_OFFICE_SE, CONST_sitedisplay090),
};
int encounterSize();
int squadAlive();
extern bool mapshowing;
extern coordinatest loc_coord;
extern siteblockst levelmap[MAPX][MAPY][MAPZ];
extern bool mapshowing;
extern short mode;
extern coordinatest loc_coord;
int monthday();
const char *_difficulty[] = { "Simple", "Very Easy", "Easy", "Below Average", "Average", "Above Average", "Hard", "Very Hard", "Extremely Difficult", "Nearly Impossible", "Impossible" };
//	extern string commaSpace;
extern int day;
extern int month;
extern int year;
extern unsigned char newstops[6][80][5][4];
extern unsigned char bigletters[27][5][7][4];
extern unsigned char newspic[20][78][18][4];
#define CH_BOX_DRAWINGS_LIGHT_VERTICAL 0xb3
#define CH_UPPER_HALF_BLOCK 0xdf
#define CH_LOWER_HALF_BLOCK 0xdc
#define CH_BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL 0xc5
#define CH_FULL_BLOCK 0xdb
#define CH_LIGHT_SHADE 0xb0
#define CH_MEDIUM_SHADE 0xb1
#define CH_DARK_SHADE 0xb2

std::pair<ColorSetup, int> ConfederateFlag[7][17] = {
{
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, 0x12a),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_UPPER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_WHITE_BRIGHT, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_WHITE_BRIGHT, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_UPPER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, 0x12a),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK)
},
{
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, 0x1de),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, 0x12a),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_UPPER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_WHITE_BRIGHT, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_WHITE_BRIGHT, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_UPPER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, 0x12a),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, 0x1dd),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK)
},
{
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, 0x1de),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, 0x12a),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_UPPER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_WHITE_BRIGHT, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_WHITE_BRIGHT, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_UPPER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, 0x12a),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, 0x1dd),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK)
},
{
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, 0x1de),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, 0x1dd),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, 0x12a),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, 0x1de),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, 0x1dd),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK)
},
{
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, 0x1de),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_UPPER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, 0x12a),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_WHITE_BRIGHT, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_UPPER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_WHITE_BRIGHT, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, 0x12a),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_UPPER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, 0x1dd),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK)
},
{
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, 0x1de),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_UPPER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, 0x12a),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_WHITE_BRIGHT, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_UPPER_HALF_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_UPPER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_WHITE_BRIGHT, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, 0x12a),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_UPPER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, 0x1dd),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK)
},
{
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_UPPER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, 0x12a),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_WHITE_BRIGHT, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_UPPER_HALF_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(RED_ON_RED, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_UPPER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_WHITE_BRIGHT, CH_FULL_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, 0x12a),
std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_UPPER_HALF_BLOCK)
}
};

std::pair<ColorSetup, int> AmericanFlag[7][18] = {
	{
		std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
		std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, '.'),
		std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
		std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, '.'),
		std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
		std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, '.'),
		std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
		std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, '.'),
		std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
		std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
		std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
		std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
		std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
		std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
		std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
		std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
		std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
		std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	},
{
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
},
{
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, ':'),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
},
{
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_BLUE_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
},
{
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
},
{
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
	std::pair<ColorSetup, int>(WHITE_ON_RED_BRIGHT, CH_LOWER_HALF_BLOCK),
},
{
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
	std::pair<ColorSetup, int>(RED_ON_BLACK, CH_UPPER_HALF_BLOCK),
},
};
extern bool fixcleartype;
extern class Ledger ledger;
//
// SIEGE

const string siege = "siege\\";
const string mostlyendings = "mostlyendings\\";

const string CONST_siege014 = "engageConservativesEscape.txt";
const string CONST_siege013 = "engageConservatives.txt";
const string CONST_siege012 = "nextSiegeAgain.txt";
const string CONST_siege011 = "nextSiege.txt";
const string CONST_siege010 = "word_replacing_liberal.txt";
const string CONST_siege009 = "insult_for_liberal.txt";
const string CONST_siege008 = "newspaper_last_name.txt";
const string CONST_siege007 = "newspaper_first_name.txt";
const string CONST_siege006 = "words_meaning_news.txt";
const string CONST_siege174 = "The printing press is dismantled and burned.";
const string CONST_siege188 = "!";
const string CONST_siege177 = ", an unoccupied safehouse.";
const string CONST_siege179 = " has been rescued.";
const string CONST_siege178 = "'s corpse has been recovered.";
const string CONST_siege167 = "Surrender yourselves!";
const string CONST_siege029 = "Materials relating to the business front have been taken.";
const string CONST_siege028 = "The compound is dismantled.";
const string CONST_siege026A = "Law enforcement has confiscated $";
const string CONST_siege026B = " in LCS funds.";
const string CONST_siege025 = "Fortunately, your funds remain intact.";
const string CONST_siege024 = " Liberals are taken to the police station.";
const string CONST_siege023 = "is taken to the police station.";
const string CONST_siege022 = ",";
const string CONST_siege021 = ", aka ";
const string CONST_siege020 = "The kidnap victims are rehabilitated and freed.";
const string CONST_siege019 = " is rehabilitated and freed.";
const string CONST_siege018 = " confiscate everything, including Squad weapons.";
const string CONST_siege017 = "The firemen";
const string CONST_siege016 = "The soldiers";
const string CONST_siege015 = "The police";
const string CONST_siege031 = " is slain.";
const string CONST_siege030 = "Everyone in the ";
const string CONST_siege074 = "You are wanted for harboring a fugitive from justice";
const string CONST_siege073 = "You are wanted for loitering";
const string CONST_siege072 = "You are wanted for indecent exposure";
const string CONST_siege071 = "You are wanted for disturbing the peace";
const string CONST_siege070 = "You are wanted for resisting arrest";
const string CONST_siege069 = "You are wanted for vandalism";
const string CONST_siege068 = "You are wanted for breaking and entering";
const string CONST_siege067 = "You are wanted for unlawful burial";
const string CONST_siege066 = "You are wanted for unlawful access of an information system";
const string CONST_siege065 = "You are wanted for interference with interstate commerce";
const string CONST_siege061 = "You are wanted for prostitution";
const string CONST_siege060 = "You are wanted for petty larceny";
const string CONST_siege059 = "You are wanted for credit card fraud";
const string CONST_siege058 = "You are wanted for grand theft auto";
const string CONST_siege057 = "You are wanted for misdemeanor assault";
const string CONST_siege056 = "You are wanted for assault with a deadly weapon";
const string CONST_siege055 = "You are wanted for extortion";
const string CONST_siege054 = "You are wanted for racketeering";
const string CONST_siege053 = "You are wanted for jury tampering";
const string CONST_siege052 = "You are wanted for aiding a prison escape";
const string CONST_siege051 = "You are wanted for escaping prison";
const string CONST_siege050 = "You are wanted for sale and distribution of a controlled substance";
const string CONST_siege049 = "You are wanted for sedition";
const string CONST_siege045 = "You are wanted for arson";
const string CONST_siege044 = "You are wanted for bank robbery";
const string CONST_siege043 = "You are wanted for kidnapping";
const string CONST_siege042 = "You are wanted for first degree murder";
const string CONST_siege041 = "You are wanted for terrorism";
const string CONST_siege040 = "You are wanted for treason";
const string CONST_siege075 = " and other crimes";
const string CONST_siege062 = "You are wanted for hiring an illegal alien";
const string CONST_siege048 = "You are wanted for flag burning";
const string CONST_siege047 = "You are wanted for felony flag burning";
const string CONST_siege046 = "You are wanted for Flag Murder";
const string CONST_siege039 = " unharmed!";
const string CONST_siege038 = " and the others";
const string CONST_siege037 = "Release ";
const string CONST_siege035 = "In the name of God, your campaign of terror ends here!";
const string CONST_siege034 = "You hear a blaring voice on a loudspeaker:";
const string CONST_siege033 = "You hear shouts:";
const string CONST_siegeB252 = "You are wanted for hiring an undocumented worker";
const string CONST_siegeB254 = "HIRING UNDOCUMENTED WORKERS";
const string CONST_siegeB253 = "FLAG BURNING";
const string CONST_siege109 = "LOITERING";
const string CONST_siege108 = "PUBLIC NUDITY";
const string CONST_siege107 = "DISTURBING THE PEACE";
const string CONST_siege106 = "RESISTING ARREST";
const string CONST_siege105 = "VANDALISM";
const string CONST_siege104 = "BREAKING AND ENTERING";
const string CONST_siege103 = "UNLAWFUL BURIAL";
const string CONST_siege102 = "HACKING";
const string CONST_siege101 = "ELECTRONIC SABOTAGE";
const string CONST_siege098 = "HIRING ILLEGAL ALIENS";
const string CONST_siege097 = "PROSTITUTION";
const string CONST_siege096 = "THEFT";
const string CONST_siege095 = "CREDIT CARD FRAUD";
const string CONST_siege094 = "GRAND THEFT AUTO";
const string CONST_siege093 = "ASSAULT";
const string CONST_siege092 = "ARMED ASSAULT";
const string CONST_siege091 = "EXTORTION";
const string CONST_siege090 = "RACKETEERING";
const string CONST_siege089 = "JURY TAMPERING";
const string CONST_siege088 = "RELEASING PRISONERS";
const string CONST_siege087 = "ESCAPING PRISON";
const string CONST_siege086 = "DRUG DEALING";
const string CONST_siege085 = "HARMFUL SPEECH";
const string CONST_siege084 = "FLAG MURDER";
const string CONST_siege083 = "ARSON";
const string CONST_siege082 = "BANK ROBBERY";
const string CONST_siege081 = "KIDNAPPING";
const string CONST_siege080 = "MURDER";
const string CONST_siege079 = "TERRORISM";
const string CONST_siege078 = "TREASON";
const string CONST_siege077 = "REHABILITATION";
const string CONST_siege076 = "WANTED FOR ";
const string CONST_siege116 = "Press Esc to ponder the situation...";
const string CONST_siege115 = "attack will be carried out by SEAL Team 6.";
const string CONST_siege114 = "Planes will bomb the compound during the siege, and the final ";
const string CONST_siege113 = "A tank will cover the entrance to the compound.";
const string CONST_siege112 = "The fighting force will be composed of national guard troops.";
const string CONST_siege111 = "an imminent police raid on ";
const string CONST_siege110 = "You have received advance warning from your sleepers regarding ";

const string CONST_siege124 = "The cops have raided the ";
const string CONST_siege122 = "You hear jet bombers streak overhead.";
const string CONST_siege121 = "An M1 Abrams Tank takes up position outside the compound.";
const string CONST_siege120 = "An M1 Abrams Tank is stopped by the tank traps.";
const string CONST_siege119 = "National Guard troops are replacing normal SWAT units.";
const string CONST_siege117 = "The police have surrounded the ";
const string CONST_siege133 = "the LCS";
const string CONST_siege132 = "are hiring mercenaries to attack ";
const string CONST_siege131 = " that the Corporations ";
const string CONST_siege130 = "an anonymous tip";
const string CONST_siege129 = "your sleeper CEO's warning";
const string CONST_siege128 = "You have received ";
const string CONST_siege134 = "Corporate mercenaries are raiding the ";
const string CONST_siege144 = "CCS members pour out of the truck and shoot in the front doors!";
const string CONST_siege143 = "INJURED: ";
const string CONST_siege142 = "KILLED: ";
const string CONST_siege141 = "CCS CAR BOMBING CASUALTY REPORT";
const string CONST_siege140 = "The truck plows into the building and explodes!";
const string CONST_siege138 = "A screeching truck pulls up to ";
const string CONST_siege137 = " is gearing up to attack ";
const string CONST_siege136 = "You have received a sleeper warning that the CCS ";
const string CONST_siege169 = "Come quietly and you will not be harmed.";
const string CONST_siege168 = "Unacceptable Speech has occurred at this location.";
const string CONST_siege166 = "You hear a screeching voice over the sound of fire engine sirens:";
const string CONST_siege165 = "Armored firemen swarm out, pilot lights burning.";
const string CONST_siege163 = "Screaming fire engines pull up to the ";

const string CONST_siege175 = "Materials relating to the business front have been destroyed.";
const string CONST_siege170 = "The Firemen have raided the ";
const string CONST_siege146 = "to launch an attack on ";
const string CONST_siege145 = "A sleeper agent has reported that the CIA is planning ";
const string CONST_siege153 = "They've shut off the lights!";
const string CONST_siege152 = "to shut off the lights!";
const string CONST_siege151 = "Through some form of high technology, they've managed ";
const string CONST_siege150 = "to shut off the lights and the cameras!";

const string CONST_siege147 = "Unmarked black vans are surrounding the ";
const string CONST_siege158 = "are storming the ";
const string CONST_siege154 = "Masses dissatisfied with your lack of respect for AM Radio ";
//	const string CONST_siege158 = "are storming the ";
const string CONST_siege157 = "Masses dissatisfied with your lack of respect for Cable News ";
const string CONST_siege162 = "the Firemen are planning to burn ";
const string CONST_siege161 = "Word in the underground is that ";
const string CONST_siege160 = "A sleeper Fireman has informed you that ";
const string CONST_siege176 = "Conservatives have raided the ";
const string CONST_siege202 = "Fortunately, no one is hurt.";
const string CONST_siege201 = " narrowly avoided death!";
const string CONST_siege200 = " was killed in the bombing!";
const string CONST_siege199 = "The lights fade and all is dark.";
const string CONST_siege198 = "The generator has been destroyed!";
const string CONST_siege197 = "There's nothing left but smoking wreckage...";
const string CONST_siege196 = "The anti-aircraft gun takes a direct hit!";
const string CONST_siege195 = "Explosions rock the compound!";
const string CONST_siege194 = "A skilled pilot gets through!";
const string CONST_siege193 = "It's all over the TV. Everyone in the Liberal Crime Squad gains 20 juice!";
const string CONST_siege192 = "Hit! One of the bombers slams into to the ground.";
const string CONST_siege191 = "You didn't shoot any down, but you've made them think twice!";
const string CONST_siege190 = "The thunder of the anti-aircraft gun shakes the compound!";
const string CONST_siege189 = "You hear planes streak overhead!";
const string CONST_siege187 = "A sniper nearly hits ";
const string CONST_siege185 = "A sniper takes out ";
const string CONST_siege224 = "'s words.";
const string CONST_siege223 = "Virtually everyone in America was moved by ";
const string CONST_siege222 = " later went on to win a Pulitzer for it.";
const string CONST_siege221 = "Even the Cable News and AM Radio spend days talking about it.";
const string CONST_siege220 = "The discussion was exciting and dynamic.";
const string CONST_siege219 = " represents the LCS well.";
const string CONST_siege218 = "'s verbal finesse leaves something to be desired.";
const string CONST_siege217 = " stutters nervously the whole time.";
const string CONST_siege216 = "But ";
const string CONST_siege215 = " falls asleep.";
const string CONST_siege214 = "But the interview is so boring that ";
const string CONST_siege213 = "Retarded";
const string CONST_siege212 = "Dumb";
const string CONST_siege211 = "and later used the material for a Broadway play called";
const string CONST_siege210 = " canceled the interview halfway through";
const string CONST_siege207 = "got into the compound somehow!";
const string CONST_siege206 = " from the ";
const string CONST_siege205 = "Elitist ";
const string CONST_siege204 = "The tank moves forward to your compound entrance.";
const string CONST_siege203 = "Army engineers have removed your tank traps.";
const string CONST_siege184 = "The police have cut the lights!";
const string CONST_siege183 = "The cops are coming!";
const string CONST_siege182 = " has starved to death.";
const string CONST_siege181 = "Your Liberals are starving!";
const string CONST_siege180 = "A day passes while under siege...";
const string CONST_siege227 = "Your Liberals split up and lay low for a few days.";
const string CONST_siege226 = "Press any key to split up and lay low for a few days";
const string CONST_siege225 = "You have escaped!";
const string CONST_siege242 = "The siege is broken!";
const string CONST_siege241 = "You're free!";
const string CONST_siege240 = "C - Reflect on your Conservative judgment.";
const string CONST_siege239 = "G - Surrender";
const string CONST_siege238 = "F - Fight!";
const string CONST_siege237 = "E - Equip";
const string CONST_siege236 = "D - Escape";

const string CONST_siege252 = "Press any key to Confront the Conservative Aggressors";
const string CONST_siege245 = "Your Liberals sally forth to confront the siege.";
const string CONST_siege243 = "UNDER SIEGE: ESCAPE OR ENGAGE";
vector<string> words_meaning_news;
vector<string> newspaper_first_name;
vector<string> newspaper_last_name;
vector<string> insult_for_liberal;
vector<string> word_replacing_liberal;
vector<string> engageConservativesEscape;
vector<string> engageConservatives;
vector<string> nextSiegeAgain;
vector<string> nextSiege;
vector<file_and_text_collection> siege_text_file_collection = {
	/*siege.cpp*/
	customText(&words_meaning_news, siege + CONST_siege006),
	customText(&newspaper_first_name, siege + CONST_siege007),
	customText(&newspaper_last_name, siege + CONST_siege008),
	customText(&insult_for_liberal, siege + CONST_siege009),
	customText(&word_replacing_liberal, siege + CONST_siege010),
	customText(&nextSiege, mostlyendings + CONST_siege011),
	customText(&nextSiegeAgain, mostlyendings + CONST_siege012),
	customText(&engageConservatives, mostlyendings + CONST_siege013),
	customText(&engageConservativesEscape, mostlyendings + CONST_siege014),
};

map<Lawflags, string> youAreWantedForThis = {

	//TREASON
	map<Lawflags, string>::value_type(LAWFLAG_TREASON, CONST_siege040),
	//TERRORISM
	map<Lawflags, string>::value_type(LAWFLAG_TERRORISM, CONST_siege041),
	//MURDERER
	map<Lawflags, string>::value_type(LAWFLAG_MURDER, CONST_siege042),
	//KIDNAPPER
	map<Lawflags, string>::value_type(LAWFLAG_KIDNAPPING, CONST_siege043),
	//BANK ROBBER
	map<Lawflags, string>::value_type(LAWFLAG_BANKROBBERY, CONST_siege044),
	//ARSONIST
	map<Lawflags, string>::value_type(LAWFLAG_ARSON, CONST_siege045),
	//SPEECH
	map<Lawflags, string>::value_type(LAWFLAG_SPEECH, CONST_siege049),
	//BROWNIES
	map<Lawflags, string>::value_type(LAWFLAG_BROWNIES, CONST_siege050),
	//ESCAPED
	map<Lawflags, string>::value_type(LAWFLAG_ESCAPED, CONST_siege051),
	//HELP ESCAPED
	map<Lawflags, string>::value_type(LAWFLAG_HELPESCAPE, CONST_siege052),
	//JURY
	map<Lawflags, string>::value_type(LAWFLAG_JURY, CONST_siege053),
	//RACKETEERING
	map<Lawflags, string>::value_type(LAWFLAG_RACKETEERING, CONST_siege054),
	//EXTORTION
	map<Lawflags, string>::value_type(LAWFLAG_EXTORTION, CONST_siege055),
	//ASSAULT
	map<Lawflags, string>::value_type(LAWFLAG_ARMEDASSAULT, CONST_siege056),
	//ASSAULT
	map<Lawflags, string>::value_type(LAWFLAG_ASSAULT, CONST_siege057),
	//CAR THEFT
	map<Lawflags, string>::value_type(LAWFLAG_CARTHEFT, CONST_siege058),
	//CC FRAUD
	map<Lawflags, string>::value_type(LAWFLAG_CCFRAUD, CONST_siege059),
	//THIEF
	map<Lawflags, string>::value_type(LAWFLAG_THEFT, CONST_siege060),
	//PROSTITUTION
	map<Lawflags, string>::value_type(LAWFLAG_PROSTITUTION, CONST_siege061),
	//COMMERCE
	map<Lawflags, string>::value_type(LAWFLAG_COMMERCE, CONST_siege065),
	//INFORMATION
	map<Lawflags, string>::value_type(LAWFLAG_INFORMATION, CONST_siege066),
	//UNLAWFUL BURIAL
	map<Lawflags, string>::value_type(LAWFLAG_BURIAL, CONST_siege067),
	//BREAKING
	map<Lawflags, string>::value_type(LAWFLAG_BREAKING, CONST_siege068),
	//VANDALISM
	map<Lawflags, string>::value_type(LAWFLAG_VANDALISM, CONST_siege069),
	//RESIST
	map<Lawflags, string>::value_type(LAWFLAG_RESIST, CONST_siege070),
	//DISTURBANCE
	map<Lawflags, string>::value_type(LAWFLAG_DISTURBANCE, CONST_siege071),
	//PUBLIC NUDITY
	map<Lawflags, string>::value_type(LAWFLAG_PUBLICNUDITY, CONST_siege072),
	//LOITERING
	map<Lawflags, string>::value_type(LAWFLAG_LOITERING, CONST_siege073),
};
map<int, string> mostSeriousCrime = {

	map<int, string>::value_type(LAWFLAG_TREASON,
	CONST_siege078),
	//TERRORISM
	map<int, string>::value_type(LAWFLAG_TERRORISM,
	CONST_siege079),
	//MURDERER
	map<int, string>::value_type(LAWFLAG_MURDER,
	CONST_siege080),
	//KIDNAPPER
	map<int, string>::value_type(LAWFLAG_KIDNAPPING,
	CONST_siege081),
	//BANK ROBBER
	map<int, string>::value_type(LAWFLAG_BANKROBBERY,
	CONST_siege082),
	//ARSONIST
	map<int, string>::value_type(LAWFLAG_BANKROBBERY,
	CONST_siege083),
};
map<int, string> mostSeriousCrime2 = {
	//SPEECH
	map<int, string>::value_type(LAWFLAG_SPEECH,
	CONST_siege085),
	//BROWNIES
	map<int, string>::value_type(LAWFLAG_BROWNIES,
	CONST_siege086),
	//ESCAPED
	map<int, string>::value_type(LAWFLAG_ESCAPED,
	CONST_siege087),
	//HELP ESCAPED
	map<int, string>::value_type(LAWFLAG_HELPESCAPE,
	CONST_siege088),
	//JURY
	map<int, string>::value_type(LAWFLAG_JURY,
	CONST_siege089),
	//RACKETEERING
	map<int, string>::value_type(LAWFLAG_RACKETEERING,
	CONST_siege090),
	//EXTORTION
	map<int, string>::value_type(LAWFLAG_EXTORTION,
	CONST_siege091),
	//ASSAULT
	map<int, string>::value_type(LAWFLAG_ARMEDASSAULT,
	CONST_siege092),
	//ASSAULT
	map<int, string>::value_type(LAWFLAG_ASSAULT,
	CONST_siege093),
	//CAR THEFT
	map<int, string>::value_type(LAWFLAG_CARTHEFT,
	CONST_siege094),
	//CC FRAUD
	map<int, string>::value_type(LAWFLAG_CCFRAUD,
	CONST_siege095),
	//THIEF
	map<int, string>::value_type(LAWFLAG_THEFT,
	CONST_siege096),
	//PROSTITUTION
	map<int, string>::value_type(LAWFLAG_PROSTITUTION,
	CONST_siege097)
};
map<int, string> mostSeriousCrime3 = {
	//COMMERCE
	map<int, string>::value_type(LAWFLAG_COMMERCE,
	CONST_siege101),
	//INFORMATION
	map<int, string>::value_type(LAWFLAG_INFORMATION,
	CONST_siege102),
	//UNLAWFUL BURIAL
	map<int, string>::value_type(LAWFLAG_BURIAL,
	CONST_siege103),
	//BREAKING
	map<int, string>::value_type(LAWFLAG_BREAKING,
	CONST_siege104),
	//VANDALISM
	map<int, string>::value_type(LAWFLAG_VANDALISM,
	CONST_siege105),
	//RESIST
	map<int, string>::value_type(LAWFLAG_RESIST,
	CONST_siege106),
	//DISTURBANCE
	map<int, string>::value_type(LAWFLAG_DISTURBANCE,
	CONST_siege107),
	//PUBLIC NUDITY
	map<int, string>::value_type(LAWFLAG_PUBLICNUDITY,
	CONST_siege108),
	//LOITERING
	map<int, string>::value_type(LAWFLAG_LOITERING,
	CONST_siege109),
};

const string CONST_siege255 = "* * * * *   VICTORY   * * * * *";
const string CONST_siege274 = "Press C to Continue Liberally.";
const string CONST_siege234 = "this filth until the Liberal Agenda is realized.";
const string CONST_siege233 = "Unfortunately, you will never truly be safe from ";
const string CONST_siege232 = "The Conservative automatons have been driven back.  ";
const string CONST_siege231 = "abandoning this safe house for a safer location.";
const string CONST_siege230 = "the time being.  While they are regrouping, you might consider ";
const string CONST_siege229 = "The Conservative automatons have been driven back ÄÄ for ";
const string CONST_siege248 = "You have been defeated.";
const string CONST_siege253 = "Your Liberals confront the Conservatives within the safehouse.";
const string CONST_siege251 = "Your traps will harass the enemy, but not the Squad.";
const string CONST_siege250 = "Your security cameras let you see units on the (M)ap.";
const string CONST_siege249 = "UNDER ATTACK: ESCAPE OR ENGAGE";

void printReporterEnteredCompound(const string repname) {
	set_color_easy(WHITE_ON_BLACK);
	eraseAlt();
	mvaddstrAlt(1, 1, CONST_siege205, gamelog);
	addstrAlt(repname, gamelog);
	addstrAlt(CONST_siege206, gamelog);
	addstrAlt(pickrandom(words_meaning_news), gamelog);
	addstrAlt(singleSpace);
	addstrAlt(pickrandom(newspaper_first_name), gamelog);
	addstrAlt(singleSpace, gamelog);
	addstrAlt(pickrandom(newspaper_last_name), gamelog);
	mvaddstrAlt(2, 1, CONST_siege207, gamelog);
	gamelog.newline();
}
void printThePoliceCutLights(const bool clearformess) {
	if (clearformess) eraseAlt();
	else makedelimiter();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege184, gamelog);
	gamelog.newline();
}

void printReporterDuringSiege(const string repname, const string name, const int segmentpower) {
	extern short lawList[LAWNUM];
	string line_one;
	string line_two = blankString;
	if (segmentpower < 15)
	{
		line_one = repname + CONST_siege210;
		line_two = CONST_siege211;
		if (LCSrandom(insult_for_liberal.size() + 1)) {
			mvaddstrAlt(10, 1, pickrandom(insult_for_liberal));
		}
		else {
			if (lawList[LAW_FREESPEECH] == -2) mvaddstrAlt(10, 1, CONST_siege212, gamelog);
			else mvaddstrAlt(10, 1, CONST_siege213, gamelog);
		}
		addstrAlt(singleSpace, gamelog);
		addstrAlt(pickrandom(word_replacing_liberal));
		addstrAlt(singleDot, gamelog);
	}
	else if (segmentpower < 20)
	{
		line_one = CONST_siege214 + name + CONST_siege215;
	}
	else if (segmentpower < 25)
	{
		line_one = CONST_siege216 + name + CONST_siege217;
	}
	else if (segmentpower < 30)
	{
		line_one = name + CONST_siege218;

	}
	else if (segmentpower < 45)
	{
		line_one = name + CONST_siege219;
	}
	else if (segmentpower < 60)
	{
		line_one = CONST_siege220;
		line_two = CONST_siege221;
	}
	else
	{
		line_one = repname + CONST_siege222;
		line_two = CONST_siege223 + name + CONST_siege224;
	}
	mvaddstrAlt(8, 1, line_one, gamelog);
	if (len(line_two) > 0) {
		mvaddstrAlt(9, 1, line_two, gamelog);
	}
	gamelog.newline();
}
void printShotBySniper(const string targname) {
	mvaddstrAlt(8, 1, CONST_siege185, gamelog);
	addstrAlt(targname, gamelog);
	addstrAlt(CONST_siege188, gamelog);
	gamelog.newline();
}
void printMissedBySniper(const string targname) {
	mvaddstrAlt(8, 1, CONST_siege187, gamelog);
	addstrAlt(targname, gamelog);
	addstrAlt(CONST_siege188, gamelog);
	gamelog.newline();
}

void printWasKilledInBombing(const string targname) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, targname, gamelog);
	addstrAlt(CONST_siege200, gamelog);
	gamelog.newline();
}
void printNarrowlyAvoidsDeath(const string targname) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, targname, gamelog);
	addstrAlt(CONST_siege201, gamelog);
	gamelog.newline();
}
void printNoOneIsHurt(const bool clearformess) {
	if (clearformess) eraseAlt();
	else makedelimiter();
	mvaddstrAlt(8, 1, CONST_siege202, gamelog);
	gamelog.newline();
}

void printCONST_siege199(const bool clearformess) {

	if (clearformess) eraseAlt();
	else makedelimiter();
	mvaddstrAlt(8, 1, CONST_siege199, gamelog);
	gamelog.newline();
}
void printCONST_siege198(const bool clearformess) {

	if (clearformess) eraseAlt();
	else makedelimiter();
	mvaddstrAlt(8, 1, CONST_siege198, gamelog);
	gamelog.newline();
}
void printCONST_siege197(const bool clearformess) {

	if (clearformess) eraseAlt();
	else makedelimiter();
	mvaddstrAlt(8, 1, CONST_siege197, gamelog);
	gamelog.newline();
}
void printCONST_siege196(const bool clearformess) {

	if (clearformess) eraseAlt();
	else makedelimiter();
	mvaddstrAlt(8, 1, CONST_siege196, gamelog);
	gamelog.newline();
}
void printCONST_siege195(const bool clearformess) {

	if (clearformess) eraseAlt();
	else makedelimiter();
	mvaddstrAlt(8, 1, CONST_siege195, gamelog);
	gamelog.newline();
}
void printCONST_siege194(const bool clearformess) {

	mvaddstrAlt(8, 1, CONST_siege194, gamelog);
	gamelog.newline();
}
void printCONST_siege193(const bool clearformess) {

	if (clearformess) eraseAlt();
	else makedelimiter();
	mvaddstrAlt(8, 1, CONST_siege193, gamelog);
}
void printCONST_siege192(const bool clearformess) {

	mvaddstrAlt(8, 1, CONST_siege192, gamelog);
	gamelog.newline();
}
void printCONST_siege191(const bool clearformess) {

	mvaddstrAlt(8, 1, CONST_siege191, gamelog);
}
void printCONST_siege190(const bool clearformess) {

	if (clearformess) eraseAlt();
	else makedelimiter();
	mvaddstrAlt(8, 1, CONST_siege190, gamelog);
	gamelog.newline();
}
void printCONST_siege189(const bool clearformess) {

	if (clearformess) eraseAlt();
	else makedelimiter();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege189, gamelog);
	gamelog.newline();
}
void printConservativesRaidedUnoccupiedSafehouse(const string locname) {
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege176, gamelog);
	addstrAlt(locname, gamelog);
	addstrAlt(CONST_siege177, gamelog);
	gamelog.newline();

}
void printCorpseRecovered(const string pname, const int y) {
	mvaddstrAlt(y + 9, 1, pname);
	addstrAlt(CONST_siege178, gamelog);
	gamelog.newline();

}
void printLiberalRescued(const string pname, const int y) {
	mvaddstrAlt(y + 9, 1, pname);
	addstrAlt(CONST_siege179, gamelog);
	gamelog.newline();

}
void printCCSRaidSafehouse() {
	eraseAlt();
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege144, gamelog);
	gamelog.nextMessage();
}

void printCorpSiegeWarning(const int sleeper, const string locationName) {
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege128, gamelog);
	if (sleeper)addstrAlt(CONST_siege129, gamelog);
	else addstrAlt(CONST_siege130, gamelog);
	addstrAlt(CONST_siege131, gamelog);
	mvaddstrAlt(9, 1, CONST_siege132, gamelog);
	if (sleeper)addstrAlt(locationName, gamelog);
	else addstrAlt(CONST_siege133, gamelog);
	addstrAlt(singleDot, gamelog);
	gamelog.nextMessage();
}
void corporateSiegePrint(const string lname) {
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege134, gamelog);
	addstrAlt(lname, gamelog);
	addstrAlt(CONST_siege188, gamelog);
	gamelog.nextMessage();
}
void printCCSCarbomb() {
	eraseAlt();
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege140, gamelog);
	gamelog.nextMessage();
}
void printCCSRaid(const string lname) {

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege138, gamelog);
	addstrAlt(lname, gamelog);
	addstrAlt(CONST_siege188, gamelog);
	gamelog.newline();
}
void printEveryoneInjuredHeader() {
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(0, 1, CONST_siege141);
	mvaddstrAlt(2, 1, CONST_siege142);
	mvaddstrAlt(6, 1, CONST_siege143);
}

void printInjuredList(const vector<pair<string, int> > injuredList) {
	int injured_y = 6;
	int injured_x = 10;
	for (pair<string, int> injured : injuredList)
	{


		int namelength = len(injured.first);

		if (injured_x + namelength > 78)
		{
			injured_y++;
			injured_x = 1;
			//Add limit for killed_y.
		}
		set_alignment_color(injured.second, false);
		mvaddstrAlt(injured_y, injured_x, injured.first);
		addstrAlt(commaSpace);
		injured_x += namelength + 2;


		//set_alignment_color(pool[i]->align,false);
		//addstrAlt(pool[i]->name);


	}
}
void printKillList(const vector<pair<string, int> > killList) {
	int killed_y = 2;
	int killed_x = 9;
	for (pair<string, int> injured : killList)
	{


		int namelength = len(injured.first);

		if (killed_x + namelength > 78)
		{
			killed_y++;
			killed_x = 1;
			//Add limit for killed_y.
		}
		set_alignment_color(injured.second, false);
		mvaddstrAlt(killed_y, killed_x, injured.first);
		addstrAlt(commaSpace);
		killed_x += namelength + 2;

	}
}
void printCCSSleeperWarning(const string lname) {
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege136, gamelog);
	mvaddstrAlt(9, 1, CONST_siege137, gamelog);
	addstrAlt(lname, gamelog);
	addstrAlt(singleDot, gamelog);
	gamelog.nextMessage();
}

void printJetBombers() {

	mvaddstrAlt(11, 1, CONST_siege122, gamelog);
	gamelog.nextMessage();
}
void printTankArrival(const bool tank_traps) {

	if (tank_traps)
		mvaddstrAlt(10, 1, CONST_siege120, gamelog);
	else mvaddstrAlt(10, 1, CONST_siege121, gamelog);
	gamelog.nextMessage();
}
void printSWATArrival() {
	mvaddstrAlt(9, 1, CONST_siege119, gamelog);
	gamelog.nextMessage();
}
void printPoliceSiegeHeader(const string lname) {

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege117, gamelog);
	addstrAlt(lname, gamelog);
	addstrAlt(CONST_siege188, gamelog);
	gamelog.newline();
}
void printPoliceSleeperWarning(const string locationName, const int siegeEscalationState) {
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege110, gamelog);
	mvaddstrAlt(9, 1, CONST_siege111, gamelog);
	addstrAlt(locationName);
	addstrAlt(singleDot, gamelog);
	gamelog.newline();
	if (siegeEscalationState >= 1)
	{
		mvaddstrAlt(11, 1, CONST_siege112, gamelog);
	}
	if (siegeEscalationState >= 2)
	{
		mvaddstrAlt(12, 1, CONST_siege113, gamelog);
	}
	if (siegeEscalationState >= 3)
	{
		mvaddstrAlt(13, 1, CONST_siege114, gamelog);
		mvaddstrAlt(14, 1, CONST_siege115, gamelog);
	}
	gamelog.nextMessage(); //Write out buffer to prepare for next message.
	mvaddstrAlt(15, 1, CONST_siege116);
}
void printPoliceSiegeEmptyHeader(const string lname) {

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege124, gamelog);
	addstrAlt(lname, gamelog);
	addstrAlt(CONST_siege177, gamelog);
	gamelog.newline();
}

void printCorpseRecoveredByPolice(const string corpse, const int y) {
	mvaddstrAlt(y + 9, 1, corpse, gamelog);
	addstrAlt(CONST_siege178, gamelog);
	gamelog.newline();
}
void printKidnapRecoveredByPolice(const string kidnap, const int y) {
	mvaddstrAlt(y + 9, 1, kidnap, gamelog);
	addstrAlt(CONST_siege179, gamelog);
	gamelog.newline();
}

void printSpecificCrime(const Lawflags crime) {
	mvaddstrAlt(4, 1, youAreWantedForThis[crime], gamelog);
}

void printBrokenLawsFooter(const bool kidnapped, const int typenum) {
	if (!kidnapped)
	{
		if (typenum > 1) addstrAlt(CONST_siege075, gamelog);
		addstrAlt(singleDot, gamelog);
	}
	gamelog.nextMessage();
}
void printHarboringFugitive() {
	mvaddstrAlt(4, 1, CONST_siege074, gamelog);
}
void printBrokenLawsHeader(const char underAttack, const short escalation) {
	int publicmood(const int old_l);
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	if (underAttack) mvaddstrAlt(1, 1, CONST_siege033, gamelog);
	else mvaddstrAlt(1, 1, CONST_siege034, gamelog);
	gamelog.newline();
	if (escalation >= 2 && publicmood(-1) < 20)
		mvaddstrAlt(3, 1, CONST_siege035, gamelog);
	else mvaddstrAlt(3, 1, CONST_siege167, gamelog);
	gamelog.newline();
}
void printBurnedFlag(const int flagLaw) {

	if (flagLaw == -2)mvaddstrAlt(4, 1, CONST_siege046, gamelog);
	else if (flagLaw == -1)mvaddstrAlt(4, 1, CONST_siege047, gamelog);
	else mvaddstrAlt(4, 1, CONST_siege048, gamelog);
}
void printHireIllegal(const bool lawStatus) {
	mvaddstrAlt(4, 1, (lawStatus ? CONST_siege062 : CONST_siegeB252), gamelog);
}
void printReleaseKidnapped(const string kname, const int kidnapped) {
	mvaddstrAlt(4, 1, CONST_siege037, gamelog);
	addstrAlt(kname, gamelog);
	if (kidnapped > 1) addstrAlt(CONST_siege038, gamelog);
	addstrAlt(CONST_siege039, gamelog);
}

void printMostSeriousCrime(const bool breakercount[LAWFLAGNUM]) {
	extern short lawList[LAWNUM];
	for (auto const& x : mostSeriousCrime)
	{
		if (breakercount[x.first]) {
			addstrAlt(x.second);
			return;
		}
	}

	if (breakercount[LAWFLAG_BURNFLAG]) {
		addstrAlt(lawList[LAW_FLAGBURNING] == -2 ? CONST_siege084 : CONST_siegeB253);
		return;
	}

	for (auto const& x : mostSeriousCrime2)
	{
		if (breakercount[x.first]) {
			addstrAlt(x.second);
			return;
		}
	}

	if (breakercount[LAWFLAG_HIREILLEGAL]) {
		addstrAlt(lawList[LAW_IMMIGRATION] < 1 ? CONST_siege098 : CONST_siegeB254);
		return;
	}

	for (auto const& x : mostSeriousCrime3)
	{
		if (breakercount[x.first]) {
			addstrAlt(x.second);
			return;
		}
	}
}
void printWantedFor() {
	set_color_easy(YELLOW_ON_BLACK_BRIGHT);

	addstrAlt(CONST_siege076);
}
void printRehab() {

	addstrAlt(CONST_siege077);
}
void printEveryoneHereIsDead(const string lname) {
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(1, 1, CONST_siege030, gamelog);
	addstrAlt(lname, gamelog);
	addstrAlt(CONST_siege031, gamelog);
	gamelog.newline();
}
void printBusinessFrontTaken() {
	mvaddstrAlt(12, 1, CONST_siege029, gamelog);
	gamelog.newline();
}
void printCompoundDismantled() {
	mvaddstrAlt(10, 1, CONST_siege028, gamelog);
	gamelog.newline();
}
void printPrintingpressDismantled() {
	mvaddstrAlt(10, 1, CONST_siege174, gamelog);
	gamelog.newline();
}
void printMoneyConfiscated(const int confiscated) {
	mvaddstrAlt(8, 1, CONST_siege026A + tostring(confiscated) + CONST_siege026B, gamelog);
	gamelog.newline();
}
void printFundsIntact() {
	mvaddstrAlt(8, 1, CONST_siege025, gamelog);
	gamelog.newline();
}
void printLiberalsTakenToPolice(const int pcount) {
	mvaddstrAlt(5, 1, pcount, gamelog);
	addstrAlt(CONST_siege024, gamelog);
	gamelog.newline();
}
void printSingleLiberalTaken(const string pname, const string pcname) {

	mvaddstrAlt(5, 1, pname, gamelog);
	if (pname == pcname)
	{
		addstrAlt(CONST_siege021, gamelog);
		addstrAlt(pcname, gamelog);
		addstrAlt(CONST_siege022, gamelog);
	}
	mvaddstrAlt(6, 1, CONST_siege023, gamelog);
	gamelog.newline();
}
void printKidnapFreed() {
	mvaddstrAlt(3, 1, CONST_siege020, gamelog);
	gamelog.newline();
}
void printSingleKidnapFreed(const string kname) {

	mvaddstrAlt(3, 1, kname);
	addstrAlt(CONST_siege019, gamelog);
	gamelog.newline();
}
void printTheyConfiscateEverything(const int siege, const int escalationState) {

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	if (siege == SIEGE_POLICE && escalationState == 0)
		mvaddstrAlt(1, 1, CONST_siege015, gamelog);
	else if (siege == SIEGE_POLICE && escalationState >= 1)
		mvaddstrAlt(1, 1, CONST_siege016, gamelog);
	else mvaddstrAlt(1, 1, CONST_siege017, gamelog);
	addstrAlt(CONST_siege018, gamelog);
	gamelog.newline();
}
void printCorpseRecovery(const int y, const string name) {
	mvaddstrAlt(y + 9, 1, name, gamelog);
	addstrAlt(CONST_siege178, gamelog);
	gamelog.newline();
}
void printKidnapRescue(const int y, const string name) {
	mvaddstrAlt(y + 9, 1, name, gamelog);
	addstrAlt(CONST_siege179, gamelog);
	gamelog.newline();
}
void printFiremenSiegeEmpty(const string locationName) {

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege170, gamelog);
	addstrAlt(locationName, gamelog);
	addstrAlt(CONST_siege177, gamelog);
	gamelog.newline();
}
void printFiremenRaid2() {

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(1, 1, CONST_siege166, gamelog);
	gamelog.newline();
	mvaddstrAlt(3, 1, CONST_siege167, gamelog);
	gamelog.newline();
	mvaddstrAlt(4, 1, CONST_siege168, gamelog);
	gamelog.newline();
	mvaddstrAlt(6, 1, CONST_siege169, gamelog);
	gamelog.nextMessage();
}
void printFiremenRaid(const string loc) {
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege163, gamelog);
	addstrAlt(loc, gamelog);
	addstrAlt(CONST_siege188, gamelog);
	gamelog.newline();
	mvaddstrAlt(9, 1, CONST_siege165, gamelog);
	gamelog.newline();
}
void printFiremenSiegeEmpty(const bool printingPress, const bool businessFront) {
	if (printingPress)
	{
		mvaddstrAlt(10, 1, CONST_siege174, gamelog);
		gamelog.newline();
	}
	if (businessFront)
	{
		mvaddstrAlt(12, 1, CONST_siege175, gamelog);
		gamelog.newline();
	}
}
void printCIASiegeWarning(const string locationName) {

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege145, gamelog);
	mvaddstrAlt(9, 1, CONST_siege146, gamelog);
	addstrAlt(locationName, gamelog);
	addstrAlt(singleDot, gamelog);
	gamelog.nextMessage();
}
void printCIASiege(const string locationName, const bool hasCameras, const bool hasAGenerator) {

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege147, gamelog);
	addstrAlt(locationName, gamelog);
	addstrAlt(CONST_siege188, gamelog);
	gamelog.newline();
	if (hasCameras)
	{
		mvaddstrAlt(9, 1, CONST_siege151, gamelog);
		mvaddstrAlt(10, 1, CONST_siege150, gamelog);
		gamelog.nextMessage();
	}
	else if (hasAGenerator)
	{
		mvaddstrAlt(9, 1, CONST_siege151, gamelog);
		mvaddstrAlt(10, 1, CONST_siege152, gamelog);
		gamelog.nextMessage();
	}
	else
	{
		mvaddstrAlt(9, 1, CONST_siege153, gamelog);
		gamelog.nextMessage();
	}
}
void printRadioHicksSiege(const int l) {
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege154, gamelog);
	mvaddstrAlt(9, 1, CONST_siege158, gamelog);
	addstrAlt(LocationsPool::getInstance().getLocationName(l), gamelog);
	addstrAlt(CONST_siege188, gamelog);
	gamelog.nextMessage();
}
void printCableHicksSiege(const int l) {

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege157, gamelog);
	mvaddstrAlt(9, 1, CONST_siege158, gamelog);
	addstrAlt(LocationsPool::getInstance().getLocationName(l), gamelog);
	addstrAlt(CONST_siege188, gamelog);
	gamelog.nextMessage();
}
void printFiremenSiege(const bool sleeper, const int l) {
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	if (sleeper) mvaddstrAlt(8, 1, CONST_siege160, gamelog);
	else mvaddstrAlt(8, 1, CONST_siege161, gamelog);
	mvaddstrAlt(9, 1, CONST_siege162, gamelog);
	addstrAlt(LocationsPool::getInstance().getLocationName(l), gamelog);
	addstrAlt(singleDot, gamelog);
	gamelog.nextMessage();
}



void printReflectOnYourConJudgement()
{
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(9, 1, CONST_siege240);
}

void printSallyForthSiege() {
	eraseAlt();
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(1, 26, CONST_siege243);
	set_color_easy(WHITE_ON_BLACK);
	int yLevel = 3;
	for (int i = 0; i < len(nextSiege); i++) {
		mvaddstrAlt(yLevel + i, 11, nextSiege[i]);
	}
	yLevel++;
	yLevel += len(nextSiege);
	for (int i = 0; i < len(nextSiegeAgain); i++) {
		mvaddstrAlt(yLevel + i, 11, nextSiegeAgain[i]);
	}
}
void printSallyForthFooter() {
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(23, 11, CONST_siege252);
	// Seperate logging text
	gamelog.log(CONST_siege245);
}
void printYoureFree() {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	clearmessagearea();
	mvaddstrAlt(16, 1, CONST_siege241, gamelog);
	gamelog.nextMessage();
}
void printSiegeIsBroken() {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	clearmessagearea();
	mvaddstrAlt(16, 1, CONST_siege242, gamelog);
	gamelog.nextMessage();
}
void printSiegeOptions(const int partysize, const short party_status) {
	if (partysize > 1)set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 40, change_squad_order);
	if (partysize > 0 && (party_status == -1 || partysize > 1))set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 40, check_status_of_squad_liberal);
	if (party_status != -1)set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(11, 40, show_squad_liberal_status);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(9, 1, CONST_siege236);
	mvaddstrAlt(10, 1, CONST_siege237);
	mvaddstrAlt(11, 1, CONST_siege238);
	mvaddstrAlt(12, 1, CONST_siege239);
}
void printLocationName(const string loc) {
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(0, 0, loc);
}


void printTanksMoveToEntrance(const bool clearformess) {
	if (!clearformess)
	{
		makedelimiter();
	}
	mvaddstrAlt(clearformess ? 9 : 8, 1, CONST_siege204, gamelog);
	gamelog.newline();
}
void printEngineersRemoveTankTrap(const bool clearformess) {
	if (clearformess) eraseAlt();
	else makedelimiter();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege203, gamelog);
	gamelog.newline();
}
void logADayPasses() {
	gamelog.record(CONST_siege180);
	gamelog.newline();
}
void printYourLiberalsAreStarving(const bool clearformess) {
	if (clearformess) eraseAlt();
	else makedelimiter();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege181, gamelog);
	gamelog.newline();
}
void printHasStarvedToDeath(const string pname, const bool clearformess) {
	if (clearformess) eraseAlt();
	else makedelimiter();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, pname, gamelog);
	addstrAlt(CONST_siege182, gamelog);
	gamelog.newline();
}
void printTheCopsAreComing(const bool clearformess) {
	if (clearformess) eraseAlt();
	else makedelimiter();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, CONST_siege183, gamelog);
	gamelog.newline();
}
void printYouHaveEscaped() {
	eraseAlt();
	set_color_easy(YELLOW_ON_BLACK_BRIGHT);
	mvaddstrAlt(1, 32, CONST_siege225, gamelog);
	gamelog.nextMessage();
	set_color_easy(WHITE_ON_BLACK);
	int yLevel = 3;
	for (int i = 0; i < len(engageConservativesEscape); i++) {
		mvaddstrAlt(yLevel + i, 11, engageConservativesEscape[i]);
	}
	yLevel += len(engageConservativesEscape);
	set_color_easy(YELLOW_ON_BLACK_BRIGHT);
	mvaddstrAlt(yLevel + 1, 11, CONST_siege226);
	// Seperate logging text
	gamelog.log(CONST_siege227);
}
void printEscapeEngageInfo() {
	eraseAlt();
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(1, 26, CONST_siege249);
	set_color_easy(WHITE_ON_BLACK);
	for (int i = 0; i < len(engageConservatives); i++) {
		mvaddstrAlt(3 + i, 11, engageConservatives[i]);
	}

}
void printEscapeEngageInfoFooter(const bool cameras, const bool traps) {
	int yLevel = 3 + len(engageConservatives);
	if (cameras)
	{
		mvaddstrAlt(yLevel, 16, CONST_siege250);
	}
	if (traps)
	{
		mvaddstrAlt(yLevel + 1, 16, CONST_siege251);
	}
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(23, 11, CONST_siege252);
	// Seperate logging text
	gamelog.log(CONST_siege253);

}
void logDefeat() {

	gamelog.log(CONST_siege248);
}
void printConquerText(const bool police) {

	eraseAlt();
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(1, 26, CONST_siege255, gamelog);
	gamelog.newline();
	if (police)
	{
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(3, 16, CONST_siege229, gamelog);
		mvaddstrAlt(4, 11, CONST_siege230, gamelog);
		mvaddstrAlt(5, 11, CONST_siege231, gamelog);
	}
	else
	{
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(3, 16, CONST_siege232, gamelog);
		mvaddstrAlt(4, 11, CONST_siege233, gamelog);
		mvaddstrAlt(5, 11, CONST_siege234, gamelog);
	}
	gamelog.nextMessage();
	mvaddstrAlt(7, 19, CONST_siege274);
}

const string CONST_siege273 = "+200 JUICE TO EVERYONE FOR ERADICATING THE CONSERVATIVE CRIME SQUAD";
const string CONST_siege272 = "revolution to attend to?";
const string CONST_siege271 = "The CCS has been completely destroyed.  Now wasn't there a ";
const string CONST_siege270 = "the last of the enemy's morale and confidence is shattered.";
const string CONST_siege269 = "With its Founder killed in the heart of their own base, ";
const string CONST_siege268 = "slips away.  ";
const string CONST_siege267 = "The CCS Founder lying dead at their feet, the squad ";
const string CONST_siege266 = "it is increasingly clear that this was the CCS's last safehouse.";
const string CONST_siege265 = "As your Liberals pick through the remains of the safehouse, ";
const string CONST_siege264 = "their final victory.  ";
const string CONST_siege263 = "Gunfire still ringing in their ears, the squad revels in ";
const string CONST_siege262 = "this will make a fine base for future Liberal operations.";
const string CONST_siege261 = "power has been severely weakened.  Once the safehouse cools off, ";
const string CONST_siege260 = "The CCS Founder wasn't here, but for now, their ";
const string CONST_siege258 = "The CCS Lieutenant lying dead at their feet, the squad ";
const string CONST_siege257 = "their victory.  ";
void printConquerTextCCS(const int ccs_siege_kills, const int ccs_kills) {

	eraseAlt();
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(1, 26, CONST_siege255, gamelog);
	gamelog.newline();
	if (ccs_kills < 3)
	{
		set_color_easy(WHITE_ON_BLACK);
		if (ccs_siege_kills > 10)
		{
			mvaddstrAlt(3, 16, CONST_siege263, gamelog);
			mvaddstrAlt(4, 11, CONST_siege257, gamelog);
		}
		else
		{
			mvaddstrAlt(3, 16, CONST_siege258, gamelog);
			mvaddstrAlt(4, 11, CONST_siege268);
		}
		addstrAlt(CONST_siege260, gamelog);
		mvaddstrAlt(5, 11, CONST_siege261, gamelog);
		mvaddstrAlt(6, 11, CONST_siege262, gamelog);
	}
	else
	{
		if (ccs_siege_kills > 10)
		{
			mvaddstrAlt(3, 16, CONST_siege263, gamelog);
			mvaddstrAlt(4, 11, CONST_siege264, gamelog);
			mvaddstrAlt(6, 16, CONST_siege265, gamelog);
			mvaddstrAlt(7, 11, CONST_siege266, gamelog);
		}
		else
		{
			mvaddstrAlt(3, 16, CONST_siege267, gamelog);
			mvaddstrAlt(4, 11, CONST_siege268, gamelog);
			mvaddstrAlt(6, 16, CONST_siege269, gamelog);
			mvaddstrAlt(7, 11, CONST_siege270, gamelog);
		}
		gamelog.newline();
		mvaddstrAlt(9, 16, CONST_siege271, gamelog);
		mvaddstrAlt(10, 16, CONST_siege272, gamelog);
		gamelog.newline();
		mvaddstrAlt(12, 5, CONST_siege273, gamelog);
	}
	gamelog.nextMessage();
	mvaddstrAlt(15, 19, CONST_siege274);
}
// end SIEGE
//
// SITEMODE
extern short lawList[LAWNUM];

const string CONST_sitemode179 = "-D";
const string CONST_sitemode178 = "                                                                                ";
const string CONST_sitemode177 = "C - Reflect on your Conservative ineptitude";
const string CONST_sitemode176 = "R - Reorganize";
const string CONST_sitemode175 = "R - Release hostage";
const string CONST_sitemode174 = "R - Release oppressed";
const string CONST_sitemode173 = "F - Fight!";
const string CONST_sitemode172 = "E - Equip";
const string CONST_sitemode171 = "V - Evade";
const string CONST_sitemode170 = "V - Run";
const string CONST_sitemode169 = "V - Sneak";
const string CONST_sitemode168 = "U - Use";
const string CONST_sitemode167 = "U - Graffiti";
const string CONST_sitemode166 = "T - Talk";
const string CONST_sitemode165 = "K - Kidnap";
const string CONST_sitemode164 = "L - Reload";
const string CONST_sitemode163 = "S - Wait";
const string CONST_sitemode162 = "M - Map";
const string CONST_sitemode161 = "N - Options";
const string CONST_sitemode160 = "G - Get Loot";
const string CONST_sitemodeXRL = "J - Reload Empty";
const string CONST_sitemode159 = "W,A,D,X - Move";
const string CONST_sitemode158 = ": CONSERVATIVES SUSPICIOUS";
const string CONST_sitemode157 = ": CONSERVATIVES ALARMED";
const string CONST_sitemode156 = ": ALIENATED EVERYONE";
const string CONST_sitemode155 = ": ALIENATED MASSES";
const string CONST_sitemode154 = ": CONSERVATIVE REINFORCEMENTS INCOMING";
const string CONST_sitemode153 = ": POLICE RESPONDING";
const string CONST_sitemode152 = ": DEATH SQUADS RESPONDING";
const string CONST_sitemode151 = ": CCS VIGILANTIES RESPONDING";
const string CONST_sitemode150 = ": GANG MEMBERS RESPONDING";
const string CONST_sitemode149 = ": ANGRY MOB RESPONDING";
const string CONST_sitemode148 = ": MERCENARIES RESPONDING";
const string CONST_sitemode147 = ": AGENTS RESPONDING";
const string CONST_sitemode146 = ": SECRET SERVICE RESPONDING";
const string CONST_sitemode145 = ": SOLDIERS AND TANKS RESPONDING";
const string CONST_sitemode144 = ", Level ";
const string CONST_sitemode143 = ": Escape or Engage";
//const string CONST_sitemode141 = "Prisoner";
const string CONST_sitemode140 = "There is a crowd of people passing by.";
const string CONST_sitemode139 = "There is a crowd of people up ahead.";
const string CONST_sitemode138 = "There is a group of people passing by.";
const string CONST_sitemode137 = "There is a group of people up ahead.";
const string CONST_sitemode136 = "There are a few people passing by.";
const string CONST_sitemode135 = "There are a few people up ahead.";
const string CONST_sitemode134 = "There is someone passing by.";
const string CONST_sitemode133 = "There is someone up ahead.";
const string CONST_sitemode132 = "The landlord is in.";
const string CONST_sitemode131 = "The landlord is out of the office.";
const string CONST_sitemode130 = "The CEO's study lies empty.";
const string CONST_sitemode129 = "The CEO is in his study.";
const string CONST_sitemode128 = "The CEO must have fled to a panic room.";
const string CONST_sitemode127 = "[Rats!] ";
const string CONST_sitemode126 = "Damn! ";
const string CONST_sitemode125 = "There are people sitting here.";
const string CONST_sitemode124 = "The bench is empty.";
const string CONST_sitemode123 = "The table is occupied.";
const string CONST_sitemode122 = "Some people are hiding under the table.";
const string CONST_sitemode121 = "The computer is occupied.";
const string CONST_sitemode120 = "The computer has been unplugged.";
const string CONST_sitemode119 = "the power of your Liberal Convictions!";
const string CONST_sitemode118 = "The Conservatives have shrunk back under ";
const string CONST_sitemode117 = "The CCS has been broken!";
const string CONST_sitemode116 = " has left ";
const string CONST_sitemode115 = "The squad sneaks past the conservatives!";
const string CONST_sitemode114 = "You find: ";
const string CONST_sitemode113 = " you, feeling safer getting out alone.";
const string CONST_sitemode112 = "One Liberal leaves";
const string CONST_sitemode111 = "The Liberal leaves";
const string CONST_sitemode110 = "Some leave";
const string CONST_sitemode109 = "They all leave";
const string CONST_sitemode108 = " from the Conservatives.";
const string CONST_sitemode107 = "an Oppressed Liberal";
const string CONST_sitemode106 = "some Oppressed Liberals";
const string CONST_sitemode105 = "You free ";
const string CONST_sitemode102 = "You have to deal with the enemies first.";
const string CONST_sitemode101 = " won't talk to you.";
const string CONST_sitemode100 = "To whom?";
const string CONST_sitemode099 = "Bluff";
const string CONST_sitemode098 = "Dating";
const string CONST_sitemode097 = "Issues";
const string CONST_sitemode096 = "Which Liberal will speak?";
const string CONST_sitemode095 = "[ ] M - Music";
const string CONST_sitemode094 = "[ ] E - Encounter warnings";
const string CONST_sitemode093 = "Site mode options";
const string CONST_sitemode092 = "Which way?  (W,A,D, and X to move, ENTER to abort)";
const string CONST_sitemode091 = "It opens easily. The alarm goes off!";
const string CONST_sitemode090 = "The alarm goes off!";
const string CONST_sitemode089 = "Force it open? (Yes or No)";
const string CONST_sitemode088 = "It's locked from the other side.";
const string CONST_sitemode087 = "locked.";
const string CONST_sitemode086 = "still ";
const string CONST_sitemode085 = "You shake the handle but it is ";
const string CONST_sitemode084 = "Your tampering sets off the alarm!";
const string CONST_sitemode083 = "Try to pick the lock? (Yes or No)";
const string CONST_sitemode082 = "You try the door, but it is locked.";
const string CONST_sitemode081 = "Try the door anyway? (Yes or No)";
const string CONST_sitemode080 = "EMERGENCY EXIT ONLY. ALARM WILL SOUND.";
const string CONST_sitemode079 = "This door appears to be wired up to an alarm.";
const string CONST_sitemode078 = "The vault door is impenetrable.";
const string CONST_sitemode077 = "too hot";
const string CONST_sitemode076 = "Your hostage is free.";
const string CONST_sitemode075 = "Your hostages are free.";
const string CONST_sitemode074 = "The police subdue and arrest the squad.";
const string tag_X = "X";
void printItOpensWithAlarm() {
	clearmessagearea(false);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode091, gamelog);
	gamelog.newline();
}
void printVaultIsImpenetrable() {

	clearmessagearea(false);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode078, gamelog);
	gamelog.newline();
}
void printUnlockedButAlarmed(const bool locked) {

	clearmessagearea(false);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	if (locked)
		mvaddstrAlt(16, 1, CONST_sitemode079, gamelog);
	else
		mvaddstrAlt(16, 1, CONST_sitemode080, gamelog);
	gamelog.newline();
	mvaddstrAlt(17, 1, CONST_sitemode081);
}
void printSquadSubduedHostagesFreed(const int hostages) {
	clearmessagearea();
	clearcommandarea();
	set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode074, gamelog);
	gamelog.newline();
	if (hostages > 0)
	{
		if (hostages > 1) {
			mvaddstrAlt(17, 1, CONST_sitemode075, gamelog);
		}
		else {
			mvaddstrAlt(17, 1, CONST_sitemode076, gamelog);
		}
	}
	gamelog.newline();
}
void printShakeHandle(const bool locked, const bool has_security) {
	clearmessagearea(false);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	if (locked)
	{

		mvaddstrAlt(16, 1, CONST_sitemode085, gamelog);
		if (has_security) addstrAlt(CONST_sitemode086, gamelog);
		addstrAlt(CONST_sitemode087, gamelog);
	}
	else mvaddstrAlt(16, 1, CONST_sitemode088, gamelog);
	gamelog.newline();
	mvaddstrAlt(17, 1, CONST_sitemode089);
}
void printLockpickPrompt() {
	clearmessagearea(false);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode082, gamelog);
	gamelog.newline();
	mvaddstrAlt(17, 1, CONST_sitemode083);
}
void printLockSetOffAlarm() {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(17, 1, CONST_sitemode084, gamelog);
	gamelog.newline();
}
void printAlarmGoesOff() {
	clearmessagearea(false);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode090, gamelog);
	gamelog.newline();
}
void printWhichWay() {
	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode092);
}
void printSitemodeOptions() {
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(10, 1, CONST_sitemode094);
	mvaddstrAlt(11, 1, CONST_sitemode095);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(24, 1, enter_done);
}
void printSitemodeOptionsHeader() {

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(0, 0, CONST_sitemode093);
}
void printMusicEnabled(const bool musice) {

	if (musice)
		mvaddstrAlt(11, 2, tag_X);
	else mvaddstrAlt(11, 2, singleSpace);
}
void printEncounterWarnings(const bool ewarn) {

	if (ewarn)
		mvaddstrAlt(10, 2, tag_X);
	else mvaddstrAlt(10, 2, singleSpace);
}
void printActiveSquadTalkOptionsHeader() {
	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, CONST_sitemode096);
	mvaddstrAlt(9, 50, CONST_sitemode097);
	mvaddstrAlt(9, 60, CONST_sitemode098);
	mvaddstrAlt(9, 70, CONST_sitemode099);
}
void printToWhom() {
	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, CONST_sitemode100);
}
void printCreatureEncounter(const int t, const int talign, const string tname, const string tage) {
	int y = 11 + (t%6);
	int x = 1 + (30 * (t/6));
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddcharAlt(y, x, t + 'A');
	addstrAlt(spaceDashSpace);
	switch (talign)
	{
	case ALIGN_CONSERVATIVE:
		set_color_easy(RED_ON_BLACK_BRIGHT);
		break;
	case ALIGN_LIBERAL:
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		break;
	case ALIGN_MODERATE:
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		break;
	}
	addstrAlt(tname);
	addstrAlt(tage);
}
void printIWontTalkToYou(const string tkname) {
	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, tkname);
	addstrAlt(CONST_sitemode101);
}
void printYouHaveEnemiesFirst() {

	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, CONST_sitemode102);
}
void printFreeThem(const int followers) {
	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode105, gamelog);
	if (followers > 1)addstrAlt(CONST_sitemode106, gamelog);
	else addstrAlt(CONST_sitemode107, gamelog);
	addstrAlt(CONST_sitemode108, gamelog);
	gamelog.newline();
}
void printFreeThemWithoutYou(const int followers, const int actgot) {

	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	if (actgot == 0 && followers > 1)mvaddstrAlt(16, 1, CONST_sitemode109, gamelog);
	else if (followers - actgot > 1)mvaddstrAlt(16, 1, CONST_sitemode110, gamelog);
	else if (actgot == 0)mvaddstrAlt(16, 1, CONST_sitemode111, gamelog);
	else mvaddstrAlt(16, 1, CONST_sitemode112, gamelog);
	addstrAlt(CONST_sitemode113, gamelog);
	gamelog.newline();
}
void printEnemyCar(const string cname, const int v) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(19, v * 20 + 1, cname);

}
void printClearChaseScreen() {
	for (int i = 19; i <= 24; i++) {
		mvaddstrAlt(i, 0, CONST_sitemode178); // 80 spaces
	}
}
void printYouFind(const string that_thing) {

	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(16, 1, CONST_sitemode114, gamelog);
	mvaddstrAlt(17, 1, that_thing, gamelog);
	gamelog.newline();
}
void printSneakPast() {
	clearmessagearea();
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode115, gamelog);
	gamelog.newline();
}
void printEnemyCarPassenger(const string ename, const int vnum, const int pnum, const bool driver) {
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(pnum + 20, vnum * 20 + 1, ename);
	if (driver) {
		addstrAlt(CONST_sitemode179);
	}
}
void printReflectOnIneptitude() {

	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(9, 1, CONST_sitemode177);
}
void printSiegeName(const string sname, const int locz) {

	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(0, 0, sname);
	addstrAlt(CONST_sitemode144);
	addstrAlt(locz + 1);
	addstrAlt(CONST_sitemode143);
}
void printCONSERVATIVES_SUSPICIOUS() {
	addstrAlt(CONST_sitemode158);
}
void printCONSERVATIVES_ALARMED() {
	addstrAlt(CONST_sitemode157);
}
void printALIENATED_EVERYONE() {
	addstrAlt(CONST_sitemode156);
}
void printALIENATED_MASSES() {
	addstrAlt(CONST_sitemode155);
}
void printCONSERVATIVE_REINFORCEMENTS_INCOMING() {
	addstrAlt(CONST_sitemode154);
}
void printLocationNameAndAlarm(const string lname, const int postalarmtimer, const int locz) {

	if (postalarmtimer > 80) set_color_easy(RED_ON_BLACK_BRIGHT);
	else if (postalarmtimer > 60) set_color_easy(YELLOW_ON_BLACK_BRIGHT);
	else set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(0, 0, lname);
	addstrAlt(CONST_sitemode144);
	addstrAlt(locz + 1);
}
void printLocationSpecificWarning(const int lsite, const bool ccsRent) {
	switch (lsite)
	{
	case SITE_GOVERNMENT_ARMYBASE:
		addstrAlt(CONST_sitemode145);
		break;
	case SITE_GOVERNMENT_WHITE_HOUSE:
		addstrAlt(CONST_sitemode146);
		break;
	case SITE_GOVERNMENT_INTELLIGENCEHQ:
		addstrAlt(CONST_sitemode147);
		break;
	case SITE_CORPORATE_HEADQUARTERS:
	case SITE_CORPORATE_HOUSE:
		addstrAlt(CONST_sitemode148);
		break;
	case SITE_MEDIA_AMRADIO:
	case SITE_MEDIA_CABLENEWS:
		addstrAlt(CONST_sitemode149);
		break;
	case SITE_BUSINESS_CRACKHOUSE:
		addstrAlt(CONST_sitemode150);
		break;
	case SITE_GOVERNMENT_POLICESTATION:
	default:
		if (ccsRent)
		{
			addstrAlt(CONST_sitemode151);
		}
		else if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)addstrAlt(CONST_sitemode152);
		else addstrAlt(CONST_sitemode153);
		break;
	}
}
void printFoughtOffConservatives() {
	clearmessagearea();
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode118, gamelog);
	mvaddstrAlt(17, 1, CONST_sitemode119, gamelog);
	gamelog.newline();
}
void logBailOnBase(const string aname, const string sitename) {

	gamelog.record(aname);
	gamelog.record(CONST_sitemode116);
	gamelog.record(sitename);
	gamelog.record(singleDot);
	gamelog.nextMessage();
}
void printCafeComputerEmpty() {

	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode120, gamelog);
	gamelog.newline();
}
void printCafeComputerFull() {

	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode121, gamelog);
	gamelog.newline();
}
void printTheCCSIsBroken() {
	clearmessagearea();
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode117, gamelog);
	gamelog.newline();
}
void printEmptyBench() {

	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode124, gamelog);
	gamelog.newline();
}
void printFullBench() {

	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode125, gamelog);
	gamelog.newline();

}
void printRestaurantTableFull() {

	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode123, gamelog);
	gamelog.newline();
}
void printRestaurantTableHiding() {

	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode122, gamelog);
	gamelog.newline();
}
void printTheCEOHasFled() {
	clearmessagearea(false);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	if (lawList[LAW_FREESPEECH] != ALIGN_ARCHCONSERVATIVE)
		mvaddstrAlt(16, 1, CONST_sitemode126, gamelog);
	else
		mvaddstrAlt(16, 1, CONST_sitemode127, gamelog);
	addstrAlt(CONST_sitemode128, gamelog);
	gamelog.newline();
}
void printTheCEOIsIn() {

	clearmessagearea(false);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode129, gamelog);
	gamelog.newline();
}
void printTheCEOIsOut() {

	clearmessagearea(false);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode130, gamelog);
	gamelog.newline();
}
void printTheLandlordIsOut() {
	clearmessagearea(false);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode131, gamelog);
	gamelog.newline();
}
void printTheLandlordIsIn() {
	clearmessagearea(false);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_sitemode132, gamelog);
	gamelog.newline();
}
void printShowEncounterWarning(const int numenc, const bool squadmoved) {

	clearmessagearea(false);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	string weMoved;
	string weDidntMove;
	if (numenc == 1)
	{
		weMoved = CONST_sitemode133;
		weDidntMove = CONST_sitemode134;
	}
	else if (numenc <= 3)
	{
		weMoved = CONST_sitemode135;
		weDidntMove = CONST_sitemode136;
	}
	else if (numenc <= 6)
	{
		weMoved = CONST_sitemode137;
		weDidntMove = CONST_sitemode138;
	}
	else
	{
		weMoved = CONST_sitemode139;
		weDidntMove = CONST_sitemode140;
	}
	if (squadmoved) {
		mvaddstrAlt(16, 1, weMoved, gamelog);
	}
	else {
		mvaddstrAlt(16, 1, weDidntMove, gamelog);
	}
	gamelog.newline();
}
void printPlayerSiteOptions(const bool isThereASiteAlarm, const bool enemy, const int partysize, const int party_status, const bool talkers) {

	if (!enemy || !isThereASiteAlarm)set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, CONST_sitemode159);
	if (partysize > 1)set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(11, 1, change_squad_order);
	if (partysize > 0 && (party_status == -1 || partysize > 1))set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, check_status_of_squad_liberal);
	if (party_status != -1)set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, show_squad_liberal_status);
	if (isThereGroundLoot() || (levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].flag&SITEBLOCK_LOOT))
		set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 17, CONST_sitemode160);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(10, 17, CONST_sitemode161);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(9, 32, CONST_sitemode162);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(10, 32, CONST_sitemode163);
	if (!enemy || !isThereASiteAlarm) set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 42, CONST_sitemode164);
	mvaddstrAlt(10, 1, CONST_sitemodeXRL);
	if (enemy) set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 42, CONST_sitemode165);
	if (talkers) set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(14, 17, CONST_sitemode166);
}
void printUseOrGraffiti(const bool graffiti, const bool print_me) {
	if (print_me) {
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
	}
	else {
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
	}
	if (graffiti)mvaddstrAlt(11, 42, CONST_sitemode167);
	else mvaddstrAlt(11, 42, CONST_sitemode168);
}
void printEvade() {

	set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 42, CONST_sitemode171);
}
void printEquipAndFight(const bool enemy) {

	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(9, 42, CONST_sitemode172);
	if (enemy)set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(14, 1, CONST_sitemode173);
}
void printReleaseOppressed() {
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(14, 32, CONST_sitemode174);
}
void printReleaseHostages(const bool hostages) {
	if (hostages) set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(14, 32, CONST_sitemode175);

}

#define CH_FULL_BLOCK 0xdb
#define CH_UPWARDS_ARROW 0x18
#define CH_DOWNWARDS_ARROW 0x19
#define CH_BLACK_SMILING_FACE 0x02
#define CH_YEN_SIGN 0x9d
#define CH_BOX_DRAWINGS_DOUBLE_VERTICAL 0xba
#define CH_BOX_DRAWINGS_DOUBLE_HORIZONTAL 0xcd
#define CH_WHITE_SMILING_FACE 0x01
void printMap(const bool has_cameras) {
	for (int x = 0; x < MAPX; x++)
	{
		for (int y = 0; y < MAPY; y++)
		{
			if (levelmap[x][y][loc_coord.locz].flag & SITEBLOCK_KNOWN)
			{
				if (x == loc_coord.locx && y == loc_coord.locy)
				{
					set_color_easy(GREEN_ON_BLACK_BRIGHT);
					mvaddchAlt(y + 1, x + 5, CH_WHITE_SMILING_FACE);
				}
				else
				{
					set_color_easy(WHITE_ON_BLACK);
					if (levelmap[x][y][loc_coord.locz].flag & SITEBLOCK_BLOCK)
					{
						set_color_easy(WHITE_ON_WHITE);
						mvaddchAlt(y + 1, x + 5, ' ');
					}
					else if (levelmap[x][y][loc_coord.locz].flag & SITEBLOCK_DOOR)
					{  // Pick color
						if (levelmap[x][y][loc_coord.locz].flag & SITEBLOCK_METAL)
							set_color_easy(WHITE_ON_WHITE_BRIGHT);
						else if (levelmap[x][y][loc_coord.locz].flag & SITEBLOCK_CLOCK
							&& levelmap[x][y][loc_coord.locz].flag & SITEBLOCK_LOCKED)
							set_color_easy(RED_ON_BLACK);
						else if (levelmap[x][y][loc_coord.locz].flag & SITEBLOCK_KLOCK
							&& levelmap[x][y][loc_coord.locz].flag & SITEBLOCK_LOCKED)
							set_color_easy(BLACK_ON_BLACK_BRIGHT);
						else set_color_easy(YELLOW_ON_BLACK);
						if ((levelmap[x + 1][y][loc_coord.locz].flag & SITEBLOCK_BLOCK) ||
							(levelmap[x - 1][y][loc_coord.locz].flag & SITEBLOCK_BLOCK))
							mvaddchAlt(y + 1, x + 5, CH_BOX_DRAWINGS_DOUBLE_HORIZONTAL);
						else mvaddchAlt(y + 1, x + 5, CH_BOX_DRAWINGS_DOUBLE_VERTICAL);
					}
					else if ((levelmap[x][y][loc_coord.locz].siegeflag & SIEGEFLAG_HEAVYUNIT) &&
						has_cameras)
					{
						set_color_easy(RED_ON_BLACK_BRIGHT);
						mvaddchAlt(y + 1, x + 5, CH_YEN_SIGN);
					}
					else if ((levelmap[x][y][loc_coord.locz].siegeflag & SIEGEFLAG_UNIT) &&
						has_cameras)
					{
						set_color_easy(RED_ON_BLACK_BRIGHT);
						mvaddchAlt(y + 1, x + 5, CH_BLACK_SMILING_FACE);
					}
					else if ((levelmap[x][y][loc_coord.locz].siegeflag & SIEGEFLAG_UNIT_DAMAGED) &&
						has_cameras)
					{
						set_color_easy(RED_ON_BLACK);
						mvaddchAlt(y + 1, x + 5, CH_BLACK_SMILING_FACE);
					}
					else if (levelmap[x][y][loc_coord.locz].special == SPECIAL_STAIRS_UP)
					{
						set_color_easy(YELLOW_ON_BLACK_BRIGHT);
						mvaddchAlt(y + 1, x + 5, CH_UPWARDS_ARROW);
					}
					else if (levelmap[x][y][loc_coord.locz].special == SPECIAL_STAIRS_DOWN)
					{
						set_color_easy(YELLOW_ON_BLACK_BRIGHT);
						mvaddchAlt(y + 1, x + 5, CH_DOWNWARDS_ARROW);
					}
					else if (levelmap[x][y][loc_coord.locz].special != -1)
					{
						set_color_easy(YELLOW_ON_BLACK_BRIGHT);
						mvaddchAlt(y + 1, x + 5, '!');
					}
					else if (levelmap[x][y][loc_coord.locz].siegeflag & SIEGEFLAG_TRAP)
					{
						set_color_easy(YELLOW_ON_BLACK_BRIGHT);
						mvaddchAlt(y + 1, x + 5, '!');
					}
					else if (levelmap[x][y][loc_coord.locz].flag & SITEBLOCK_LOOT)
					{
						set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
						mvaddchAlt(y + 1, x + 5, '$');
					}
					else mvaddchAlt(y + 1, x + 5, ' ');
				}
			}
			else
			{
				set_color_easy(BLACK_ON_BLACK_BRIGHT);
				mvaddchAlt(y + 1, x + 5, CH_FULL_BLOCK);
			}
		}
	}
}
void logNewLine() {
	gamelog.newline();
}
void printReorganize(const int libnum) {
	if (libnum > 6)set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(14, 32, CONST_sitemode176);
}
void printSneakOrRun(const bool evade) {

	set_color_easy(WHITE_ON_BLACK);
	if (!evade)
		mvaddstrAlt(12, 42, CONST_sitemode169);
	else
		mvaddstrAlt(12, 42, CONST_sitemode170);
}
//
// STEALTH
const string stealth = "stealth\\";
vector<string> blew_stealth_check;
const string CONST_stealth053 = "blew_stealth_check.txt";
vector<file_and_text_collection> stealth_text_file_collection = {
	customText(&blew_stealth_check, stealth + CONST_stealth053),
};
const string CONST_stealth075 = "and shouts for help!";
const string CONST_stealth074 = "and lets forth a piercing Conservative alarm cry!";
const string CONST_stealth073 = "and launches into angry Conservative barking!";
const string CONST_stealth072 = " looks at the Squad with Intolerance ";
const string CONST_stealth069 = " sees the Squad's Liberal Weapons ";
const string CONST_stealth068 = " looks at the Squad suspiciously.";
const string CONST_stealth067 = " shouts in alarm at the squad's Liberal Trespassing!";
const string CONST_stealth066 = " acts natural.";
const string CONST_stealth065 = "The squad";
const string CONST_stealth064 = " fades into the shadows.";
const string CONST_stealth062 = "holstered";
const string CONST_stealth061 = "                                                        ";
const string CONST_stealth060 = "We've alienated absolutely everyone here!               ";
const string CONST_stealth059 = "We've alienated the masses here!              ";
//const string CONST_stealth058 = "Prisoner";
const string CONST_stealth055 = " observes your Liberal activity ";


// TITLESCREEN

const int REAL_QUOTE_SIZE = 4;
const string pressMtoTurnOffMusic = "Press M to turn off the Music. Press H to view your Liberal High Score.";
const string pressMtoTurnOnMusic = "Press M to turn on some Music. Press H to view your Liberal High Score.";
const string pressToSelectSave = "Press a Letter to Select a Save File";
const string pressToDeleteSave = "Press a Letter to Delete a Save File";
const string vToSwitchXToQuit = ", V to switch, or X to quit";
const string areYouSureDelte = "Are you sure you want to delete ";
const string questionYSlashN = "? (y/n)";
const string newGame = "NEW GAME";
const string dotDat = ".dat";
const string deleteSave = "Delete a Save File";
const string chooseSave = "Choose a Save File";
const string titleScreenLine = "----Title-----------------------------------------------------------------------";
const string inWhatWorld = "In what world will you pursue your Liberal Agenda?";
const string enterNameForSave = "Enter a name for the save file.";
const string pleaseEnterName = "Please enter a name for the save file.";
const string prettyPlease = "Pretty please enter a name for the save file.";
const string justEnterName = "Just enter a [darn] name for the save file.";
const string inspiredByOubliette = "Inspired by the 1983 version of Oubliette";
const string copyrightTarn = "v3.9 Copyright (C) 2002-4, Tarn Adams";
const string bayTwelveProductions = "A Bay 12 Games Production";
const string lcsHyperlink = "http://bay12games.com/lcs/";
const string vChar = "v";
const string maintainedByOpenSource = " Maintained by the Open Source Community";
const string kingDrakeHyperlink = "https://github.com/King-Drake/Liberal-Crime-Squad";
const string lcsForumHyperlink = "http://www.bay12games.com/forum/index.php?board=3.0";
const string lcsWikiHyperlink = "http://lcs.wikidot.com/";
const string pressESCToQuit = "Press ESC now to quit. Quitting later causes your progress to be saved.";
const string pressAnyKeyToPursue = "Press any other key to pursue your Liberal Agenda!";
const string plusChar = "+";
const string liberalCrimeSquad = "Liberal Crime Squad";
const string titley = "titlescreen\\";

const string CONST_titlescreen003 = "real_quote.txt";
const int SAVE_FILE_NAMELEN = 21;
vector<vector<string> > real_quote;
vector<file_and_text_collection> title_screen_text_files = {
	customText(&real_quote, titley + CONST_titlescreen003, REAL_QUOTE_SIZE),
};

// SLEEPER_UPDATE

const string they_are_stashed = "They are stashed at the homeless shelter.";
const string hasBeenCaughtSnooping = " has been caught snooping around.";
const string isNowHomeless = "The Liberal is now homeless and jobless...";
const string hasLeakedIntelligence = " has leaked secret intelligence files.";
const string hasLeakedPolice = " has leaked secret police records.";
const string hasLeakedCorporate = " has leaked secret corporate documents.";
const string hasLeakedPrison = " has leaked internal prison records.";
const string hasLeakedCableNews = " has leaked proof of systemic Cable News bias.";
const string hasLeakedAMRadio = " has leaked proof of systemic AM Radio bias.";
const string hasLeakedAnimalResearch = " has leaked internal animal research reports.";
const string hasLeakedJudiciary = " has leaked proof of corruption in the judiciary.";
const string papersAreStashed = "The papers are stashed at the homeless shelter.";
const string hasLeakedCCS = " has leaked a list of the CCS's government backers.";
const string diskIsStashed = "The disk is stashed at the homeless shelter.";
const string arrestedWhileEmbezzling = " has been arrested while embezzling funds.";
const string arrestedWhileStealing = " has been arrested while stealing things.";
const string droppedOffPackage = " has dropped a package off at the homeless shelter.";
const string itemNotFound = "Items not found in XML files led to ";
const string lostStolenItem = " lost stolen items! ";
const string contactModAuthor = "Contact the mod author (or DevTeam if playing the vanilla game) at once!";
const string CONST_sleeper_update046 = "canseethings";
const string CONST_sleeper_update045 = "abstracted debate";
const string CONST_sleeper_update044 = "liberal power";
void printxmlFail(const int numberofxmlfails) {
	set_color_easy(RED_ON_BLUE_BRIGHT);
	mvaddstrAlt(8, 1, itemNotFound, xmllog);
	mvaddstrAlt(9, 1, tostring(numberofxmlfails), xmllog);
	addstrAlt(lostStolenItem, xmllog);
	set_color_easy(RED_ON_GREEN_BRIGHT);
	mvaddstrAlt(11, 1, contactModAuthor, xmllog);
	xmllog.nextMessage();

}
void printSleeperDropOffPackage(const string crname) {
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(6, 1, string_sleeper, gamelog);
	addstrAlt(crname, gamelog);
	addstrAlt(droppedOffPackage, gamelog);
	gamelog.nextMessage();

}
void printArrestedWhileStealing(const string crname) {
	eraseAlt();
	mvaddstrAlt(6, 1, string_sleeper, gamelog);
	addstrAlt(crname, gamelog);
	addstrAlt(arrestedWhileStealing, gamelog);
	gamelog.nextMessage();
}
void printArrestedWhileEmbezzling(const string crname) {
	eraseAlt();
	mvaddstrAlt(6, 1, string_sleeper, gamelog);
	addstrAlt(crname, gamelog);
	addstrAlt(arrestedWhileEmbezzling, gamelog);
	gamelog.nextMessage();

}
void printHasBeenCaughtSnooping(const string crname) {
	eraseAlt();
	mvaddstrAlt(6, 1, string_sleeper, gamelog);
	addstrAlt(crname, gamelog);
	addstrAlt(hasBeenCaughtSnooping, gamelog);
	gamelog.newline();
	mvaddstrAlt(8, 1, isNowHomeless, gamelog);
	gamelog.nextMessage();

}

void creatureLeaksIntel(const string crname, const string& leak, const string& stashed) {
	eraseAlt();
	mvaddstrAlt(6, 1, string_sleeper, gamelog);
	addstrAlt(crname, gamelog);
	addstrAlt(leak, gamelog);
	gamelog.newline();
	mvaddstrAlt(7, 1, stashed, gamelog);
	gamelog.nextMessage();
}

void printCreatureLeaksIntelligence(const string crname) {
	creatureLeaksIntel(crname, hasLeakedIntelligence, they_are_stashed);

}
void printCreatureLeaksPolice(const string crname) {
	creatureLeaksIntel(crname, hasLeakedPolice, they_are_stashed);

}
void printCreatureLeaksCorp(const string crname) {
	creatureLeaksIntel(crname, hasLeakedCorporate, they_are_stashed);

}
void printCreatureLeaksPrison(const string crname) {
	creatureLeaksIntel(crname, hasLeakedPrison, they_are_stashed);

}
void printCreatureLeaksCable(const string crname) {
	creatureLeaksIntel(crname, hasLeakedCableNews, papersAreStashed);

}
void printCreatureLeaksRadio(const string crname) {
	creatureLeaksIntel(crname, hasLeakedAMRadio, papersAreStashed);

}
void printCreatureLeaksAnimalResearch(const string crname) {
	creatureLeaksIntel(crname, hasLeakedAnimalResearch, they_are_stashed);

}
void printCreatureLeaksJudiciary(const string crname) {
	creatureLeaksIntel(crname, hasLeakedJudiciary, papersAreStashed);

}
void printCreatureLeaksCCS(const string crname) {
	creatureLeaksIntel(crname, hasLeakedCCS, diskIsStashed);

}

//TALK
// TALK

extern short exec[EXECNUM];
extern short siteonfire;
extern Deprecatednewsstoryst *sitestory;
extern string slogan_str;
const int PICKUP_LINE_SIZE = 5;
const int DOUBLE_LINE = 2;
extern Log gamelog;
extern short lawList[LAWNUM];
const string unnamed_String_Talk_cpp_122 = "The squad releases the hostage in the trade.";
const string while_naked = " while naked";
const string unnamed_String_Talk_cpp_001 = "A - Quietly pass the teller a robbery note";
const string unnamed_String_Talk_cpp_002 = "B - Threaten bystanders and demand access to the vault";
const string unnamed_String_Talk_cpp_003 = "C - On second thought, don't rob the bank";
const string unnamed_String_Talk_cpp_004 = " slips the teller a note: ";
const string unnamed_String_Talk_cpp_005 = "The bank teller reads the note, ";
const string unnamed_String_Talk_cpp_006 = "and dives for cover as the guards move in on the squad!";
const string unnamed_String_Talk_cpp_007 = "The bank teller reads the note, ";
const string unnamed_String_Talk_cpp_008 = "and slips several bricks of cash into the squad's bag.";
const string unnamed_String_Talk_cpp_009 = " brandishes the ";
const string unnamed_String_Talk_cpp_010 = "\"";
const string unnamed_String_Talk_cpp_011 = "OPEN THE VAULT, NOW!\"";
const string unnamed_String_Talk_cpp_012 = "The bank teller and dives for cover as ";
const string unnamed_String_Talk_cpp_013 = "guards move in on the squad!";
const string unnamed_String_Talk_cpp_014 = "The bank employees hesitantly cooperate!";
const string unnamed_String_Talk_cpp_015 = "The vault is open!";
const string unnamed_String_Talk_cpp_016 = " talks to ";
const string unnamed_String_Talk_cpp_017 = ":";
const string unnamed_String_Talk_cpp_018 = "A - Strike up a conversation about politics";
const string unnamed_String_Talk_cpp_019 = "B - Drop a pickup line";
const string unnamed_String_Talk_cpp_020 = "C - On second thought, don't say anything";
const string unnamed_String_Talk_cpp_021 = "D - Rent a room";
const string unnamed_String_Talk_cpp_022 = "D - Stop renting a room";
const string unnamed_String_Talk_cpp_023 = "D - Buy weapons";
const string unnamed_String_Talk_cpp_024 = "D - Rob the bank";
const string unnamed_String_Talk_cpp_025 = "\"I'd like cancel my room.\"";
const string unnamed_String_Talk_cpp_027 = "\"Alright.Please clear out your room.\"";
const string unnamed_String_Talk_cpp_028 = "<Your possessions at this location have been moved to the shelter.>";
const string unnamed_String_Talk_cpp_029 = "\"I'd like to rent a room.\"";
const string unnamed_String_Talk_cpp_030 = "\"Put some clothes on before I call the cops.\"";
const string unnamed_String_Talk_cpp_031 = "\"It'll be $";
const string unnamed_String_Talk_cpp_032 = " a month.";
const string unnamed_String_Talk_cpp_033 = "I'll need $";
const string unnamed_String_Talk_cpp_034 = " now as a security deposit.\"";
const string unnamed_String_Talk_cpp_035 = "A - Accept.";
const string unnamed_String_Talk_cpp_036 = "B - Decline.";
const string unnamed_String_Talk_cpp_037 = "C - Threaten the landlord.";
const string unnamed_String_Talk_cpp_038 = "\"I'll take it.\"";
const string unnamed_String_Talk_cpp_039 = "\"Rent is due by the third of every month.";
const string unnamed_String_Talk_cpp_040 = "We'll start next month.\"";
const string unnamed_String_Talk_cpp_041 = " <turns away>";
const string unnamed_String_Talk_cpp_042 = "\"Whoa, I was looking for something cheaper.\"";
const string unnamed_String_Talk_cpp_043 = "\"Not my problem...\"";
const string unnamed_String_Talk_cpp_044 = " <turns away>";
const string unnamed_String_Talk_cpp_045 = " brandishes the ";
const string unnamed_String_Talk_cpp_046 = "\"What's the price for the Liberal Crime Squad?\"";
const string unnamed_String_Talk_cpp_047 = "\"I think you'd better leave.\"";
const string unnamed_String_Talk_cpp_048 = " <crosses arms>";
const string unnamed_String_Talk_cpp_049 = "\"Jesus... it's yours...\"";
const string unnamed_String_Talk_cpp_050 = "\"Hey, I need a gun.\"";
const string unnamed_String_Talk_cpp_051 = "\"Jesus...\"";
const string unnamed_String_Talk_cpp_052 = "\"I don't sell guns, officer.\"";
const string unnamed_String_Talk_cpp_053 = "\"We can talk when things are calm.\"";
const string unnamed_String_Talk_cpp_054 = "\"What exactly do you need ? \"";
const string unnamed_String_Talk_cpp_055 = "\"Uhhh... not a good place for this.\"";
const string unnamed_String_Talk_cpp_056 = "\"Do you want to hear something disturbing ? \"";
const string unnamed_String_Talk_cpp_057 = " rumbles disinterestedly.";
const string unnamed_String_Talk_cpp_058 = " barks.";
const string unnamed_String_Talk_cpp_059 = " doesn't understand.";
const string unnamed_String_Talk_cpp_061 = "\"What ? \"";
const string unnamed_String_Talk_cpp_062 = "\"Now's not the time!\"";
const string unnamed_String_Talk_cpp_063 = "\"Leave me alone.\"";
const string unnamed_String_Talk_cpp_064 = "\"No.\"";
const string unnamed_String_Talk_cpp_065 = " <turns away>";

const string unnamed_String_Talk_cpp_066 = " shakes its turret a firm 'no'.";
const string unnamed_String_Talk_cpp_067 = " doesn't quite pick up on the subtext.";
const string unnamed_String_Talk_cpp_068 = "\"Dirty.You know that's illegal, officer.\"";
const string unnamed_String_Talk_cpp_069 = " and ";
const string unnamed_String_Talk_cpp_070 = " make plans for tonight";
const string unnamed_String_Talk_cpp_071 = ", and ";
const string unnamed_String_Talk_cpp_072 = " breaks for the exit";
const string unnamed_String_Talk_cpp_073 = ". ";
const string unnamed_String_Talk_cpp_074 = "\"I'm a happily married man, sweetie.\"";
const string unnamed_String_Talk_cpp_075 = "\"This ain't Brokeback Mountain, son.\"";
const string unnamed_String_Talk_cpp_076 = "\"[The police are not doing their job very well!]\"";
const string unnamed_String_Talk_cpp_077 = "\"The cops suck!\"";
const string unnamed_String_Talk_cpp_078 = "\"Industries that stop at nothing to become more profitable are polluting ";
const string unnamed_String_Talk_cpp_079 = "the environment in ways that hurt not only humans, but animals too.";
const string unnamed_String_Talk_cpp_080 = "the environment in ways that hurt not only animals, but people too.";
const string unnamed_String_Talk_cpp_082 = "\"Aaaahhh...\"";
const string unnamed_String_Talk_cpp_083 = "\"Oh, really ? \"";
const string unnamed_String_Talk_cpp_084 = "\"Yeah, really!\"";
const string unnamed_String_Talk_cpp_085 = "\"You got anything to smoke on you ? \"";
const string unnamed_String_Talk_cpp_086 = "*cough*";
const string unnamed_String_Talk_cpp_087 = "After more discussion, ";
const string unnamed_String_Talk_cpp_088 = " agrees to come by later tonight.";
const string unnamed_String_Talk_cpp_089 = "\"Ugh.Pfft.\"";
const string unnamed_String_Talk_cpp_090 = "\"Do you want me to arrest you ? \"";
const string unnamed_String_Talk_cpp_091 = "\"If you don't shut up, I'm going to shoot you.\"";
const string unnamed_String_Talk_cpp_092 = "\"Whatever.\"";
const string unnamed_String_Talk_cpp_093 = " <turns away>";
const string unnamed_String_Talk_cpp_113 = "BLAM!";
const string unnamed_String_Talk_cpp_114 = "CRUNCH!";
const string unnamed_String_Talk_cpp_115 = " drops ";
const string unnamed_String_Talk_cpp_116 = "'s body.";
const string unnamed_String_Talk_cpp_117 = "\"Fuck!";
const string unnamed_String_Talk_cpp_118 = "\"[No!] ";
const string unnamed_String_Talk_cpp_119 = "\"Back off and we'll let the hostages go.\"";
const string unnamed_String_Talk_cpp_120 = "\"Back off and the hostage goes free.\"";
const string unnamed_String_Talk_cpp_121 = "The squad releases all hostages in the trade.";
const string unnamed_String_Talk_cpp_100 = "\"Don't push the LCS!\"";
const string unnamed_String_Talk_cpp_101 = "\"Don't [play] with me!\"";
const string unnamed_String_Talk_cpp_102 = "\"Don't fuck with me!\"";
const string unnamed_String_Talk_cpp_103 = "\"Release your hostages, and nobody gets hurt.\"";
const string unnamed_String_Talk_cpp_104 = "\"Let the hostage go, and nobody gets hurt.\"";
const string unnamed_String_Talk_cpp_105 = "The ploy works! The Conservatives back off.";
const string unnamed_String_Talk_cpp_106 = "How should ";
const string unnamed_String_Talk_cpp_107 = " respond?";
const string unnamed_String_Talk_cpp_108 = "A - Execute a hostage";
const string unnamed_String_Talk_cpp_109 = "A - Execute the hostage";
const string unnamed_String_Talk_cpp_110 = "B - Offer to trade the hostages for freedom";
const string unnamed_String_Talk_cpp_111 = "B - Offer to trade the hostage for freedom";
const string unnamed_String_Talk_cpp_112 = "C - No reply";

const string unnamed_String_Talk_cpp_123 = " isn't interested in your pathetic threats.";
const string unnamed_String_Talk_cpp_124 = "pretends to be part of a police raid.";
const string unnamed_String_Talk_cpp_125 = "pretends to be a Secret Agent.";
const string unnamed_String_Talk_cpp_126 = "pretends to be Mountain ";
const string unnamed_String_Talk_cpp_127 = "like Patrick Swayze in Next of Kin.";
const string unnamed_String_Talk_cpp_128 = "squeals like Ned Beatty ";
const string unnamed_String_Talk_cpp_129 = "in Deliverance.";
const string unnamed_String_Talk_cpp_130 = "pretends to be a mercenary.";
const string unnamed_String_Talk_cpp_131 = "lights a match and throws it on the ground. ";
const string unnamed_String_Talk_cpp_132 = "The carpet smolders, then bursts into flame.";
const string unnamed_String_Talk_cpp_133 = "Perhaps that was a bad idea...";
const string unnamed_String_Talk_cpp_134 = "\"The situation is under control.\"";
const string unnamed_String_Talk_cpp_135 = "\"Fire!Evacuate immediately!\"";
const string unnamed_String_Talk_cpp_136 = "\"Everything's in check.\"";
const string unnamed_String_Talk_cpp_137 = "\"Make way, I'm a doctor!\"";
const string unnamed_String_Talk_cpp_138 = "\"Non - targets please leave the site.\"";
const string unnamed_String_Talk_cpp_139 = " engraves ";
const string unnamed_String_Talk_cpp_140 = "Elbereth";
const string unnamed_String_Talk_cpp_141 = " on the floor.";
const string unnamed_String_Talk_cpp_142 = " talks like a Conservative ";
const string unnamed_String_Talk_cpp_143 = "and pretends to belong here.";
const string unnamed_String_Talk_cpp_144 = "But ";
const string unnamed_String_Talk_cpp_145 = " weren't born yesterday.";
const string unnamed_String_Talk_cpp_146 = " is not fooled by that [act].";
const string unnamed_String_Talk_cpp_147 = " is not fooled by that crap.";
const string unnamed_String_Talk_cpp_148 = "The Enemy is fooled and departs.";
const string unnamed_String_Talk_cpp_149 = "The Squad is arrested.";
const string unnamed_String_Talk_cpp_094 = " talks to ";
const string unnamed_String_Talk_cpp_095 = ":";
const string unnamed_String_Talk_cpp_096 = "A - Intimidate";
const string unnamed_String_Talk_cpp_097 = "B - Threaten hostages";
const string unnamed_String_Talk_cpp_098 = "C - Bluff";
const string unnamed_String_Talk_cpp_099 = "D - Surrender to authorities";
const string respondsComma = " responds, ";
const string saysComma = " says, ";
const string CONST_talk034 = "agree_to_release_hostages.txt";
const string CONST_talk033 = "go_ahead_and_die.txt";
const string CONST_talk032 = "let_hostages_go.txt";
const string CONST_talk031 = "please_no_more.txt";
const string CONST_talk030 = "hostage_negotiation.txt";
const string CONST_talk029 = "who_cares_about_hostage.txt";
const string CONST_talk028 = "please_spare_hostage.txt";
const string CONST_talk027 = "threaten_hostage.txt";
const string CONST_talk026 = "backs_off.txt";
const string CONST_talk025 = "come_at_me_bro.txt";
const string CONST_talk024 = "teller_complies.txt";
const string CONST_talk023 = "teller_gestures.txt";
const string CONST_talk022 = "robbing_bank.txt";
const string CONST_talk021 = "that_is_not_disturbing.txt";
const string CONST_talk020 = "that_is_disturbing.txt";
const string CONST_talk019 = "mutant_rejection.txt";
const string CONST_talk018 = "dog_rejection.txt";
const string CONST_talk017 = "normal_talk_to_dog.txt";
const string CONST_talk016 = "lovingly_talk_to_dog.txt";
const string CONST_talk015 = "normal_talk_to_mutant.txt";
const string CONST_talk014 = "lovingly_talk_to_mutant.txt";
const string CONST_talk013 = "pickupLines.txt";
const string CONST_talk012 = "no_free_speech_flirt.txt";

const string talky = "talk\\";
const string talk_combat = "talk_combat\\";
const string unnamed_String_Talk_cpp_081 = "Prisoner";
extern vector<vector<string> > no_free_speech_flirt;
extern vector<vector<string> > pickupLines;
extern vector<vector<string> > lovingly_talk_to_mutant;
extern vector<vector<string> > normal_talk_to_mutant;
extern vector<vector<string> > lovingly_talk_to_dog;
extern vector<vector<string> > normal_talk_to_dog;

vector<string> dog_rejection;
vector<string> mutant_rejection;
vector<string> that_is_disturbing;
vector<string> that_is_not_disturbing;
vector<string> robbing_bank;
vector<string> teller_gestures;
vector<string> teller_complies;
//const int DOUBLE_LINE = 2;
vector<string> come_at_me_bro;
vector<string> backs_off;
vector<string> threaten_hostage;
vector<string> please_spare_hostage;
vector<string> who_cares_about_hostage;
vector<string> hostage_negotiation;
vector<string> please_no_more;
vector<string> let_hostages_go;
vector<string> go_ahead_and_die;
vector<string> agree_to_release_hostages;
vector<file_and_text_collection> talk_file_collection = {
	/*talk.cpp*/
	customText(&no_free_speech_flirt, talky + CONST_talk012, PICKUP_LINE_SIZE),
	customText(&pickupLines, talky + CONST_talk013, PICKUP_LINE_SIZE),
	customText(&lovingly_talk_to_mutant, talky + CONST_talk014, DOUBLE_LINE),
	customText(&normal_talk_to_mutant, talky + CONST_talk015, DOUBLE_LINE),
	customText(&lovingly_talk_to_dog, talky + CONST_talk016, DOUBLE_LINE),
	customText(&normal_talk_to_dog, talky + CONST_talk017, DOUBLE_LINE),
	customText(&dog_rejection, talky + CONST_talk018),
	customText(&mutant_rejection, talky + CONST_talk019),
	customText(&that_is_disturbing, talky + CONST_talk020),
	customText(&that_is_not_disturbing, talky + CONST_talk021),
	customText(&robbing_bank, talky + CONST_talk022),
	customText(&teller_gestures, talky + CONST_talk023),
	customText(&teller_complies, talky + CONST_talk024),
	//talk in combat
	customText(&come_at_me_bro, talk_combat + CONST_talk025),
	customText(&backs_off, talk_combat + CONST_talk026),
	customText(&threaten_hostage, talk_combat + CONST_talk027),
	customText(&please_spare_hostage, talk_combat + CONST_talk028),
	customText(&who_cares_about_hostage, talk_combat + CONST_talk029),
	customText(&hostage_negotiation, talk_combat + CONST_talk030),
	customText(&please_no_more, talk_combat + CONST_talk031),
	customText(&let_hostages_go, talk_combat + CONST_talk032),
	customText(&go_ahead_and_die, talk_combat + CONST_talk033),
	customText(&agree_to_release_hostages, talk_combat + CONST_talk034),
};
//string while_naked;
map<short, string> conservativeLegalArgument;
map<short, vector<string> > talkAboutTheIssues;
map<short, string> youAreStupidTalkAboutIssues;
map<short, string> issueTooLiberal;


short interface_pgup = '[';
short interface_pgdn = ']';
bool is_page_up(const int c) {
	return c == interface_pgup || c == KEY_UP || c == KEY_LEFT;
}
bool is_page_down(const int c) {
	return c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT;
}
inline int translateGraphicsChar(unsigned char c) { return c; }
inline short translateGraphicsColor(short c) { return c; }
/* Variants of addch and mvaddch that work on chars and use translateGraphicsChar(), fixing display of extended characters */
inline int addchar(char ch) { return addch(translateGraphicsChar(ch)); }
inline int mvaddchar(int y, int x, char ch) { return mvaddch(y, x, translateGraphicsChar(ch)); }
inline int addchar(char ch, Log &log) { log.record(ch); return addchar(ch); }
inline int mvaddchar(int y, int x, char ch, Log &log) { log.record(ch); return mvaddchar(y, x, ch); }
/* Redefining addstr() and mvaddstr() so they use addchar() and mvaddchar(), fixing display of extended characters */
#undef addstr
inline int addstr(const char* text) { int ret = ERR; for (int i = 0; i < len(text); i++) ret = addchar(text[i]); return ret; }
#undef mvaddstr
inline int mvaddstr(int y, int x, const char* text) { int ret = move(y, x); if (ret != ERR) ret = addstr(text); return ret; }
/* Various wrappers to addstr() and mvaddstr() which handle permutations of:
- Including or not including the gamelog for external message logging
- std::string or c-style char arrays */
inline int addstr(const char *text, Log &log) { log.record(text); return addstr(text); }
inline int mvaddstr(int y, int x, const char *text, Log &log) { log.record(text); return mvaddstr(y, x, text); }
inline int addstr(const std::string& text) { int ret = ERR; for (int i = 0; i < len(text); i++) ret = addchar(text[i]); return ret; }
inline int addstr(const std::string& text, Log &log) { log.record(text); return addstr(text); }
inline int mvaddstr(int y, int x, const std::string& text) { int ret = move(y, x); if (ret != ERR) ret = addstr(text); return ret; }
inline int mvaddstr(int y, int x, const std::string& text, Log &log) { log.record(text); return mvaddstr(y, x, text); }
/* These wrappers convert numbers to text */
inline int addstr(long num) { return addstr(tostring(num)); }
inline int addstr(long num, Log &log) { return addstr(tostring(num), log); }
inline int mvaddstr(int y, int x, long num) { return mvaddstr(y, x, tostring(num)); }
inline int mvaddstr(int y, int x, long num, Log &log) { return mvaddstr(y, x, tostring(num), log); }
void pressAnyKey() {
	getkeyAlt();
}
void    PDC_set_titleAlt(const char *ch) {
	PDC_set_title(ch);
}
int endwinAlt() {
	return endwin();
}
int     addchAlt(const int ch) {
	return addch(ch);
}
int addcharAlt(const char ch) {
	return addch(translateGraphicsChar(ch));
}
int addcharAlt(const char ch, Log &log) {
	log.record(ch); return addcharAlt(ch);
}
int mvaddcharAlt(int y, int x, char ch) { return mvaddch(y, x, translateGraphicsChar(ch)); }
int mvaddcharAlt(int y, int x, char ch, Log &log) { log.record(ch); return mvaddcharAlt(y, x, ch); }
int eraseAlt(void) {
	return erase();
}
void strcat(char* c, string s) {
	strcat(c, s.data());
}
void strcpy(char* c, string s) {
	strcpy(c, s.data());
}
int     mvaddchAlt(int x, int y, const int ch) {
	return mvaddch(x, y, ch);
}
int     mvgetnstrAlt(int x, int y, char *ch, int z) {
	return mvgetnstr(x, y, ch, z);
}
int moveAlt(const int x, const int y) { return move(x, y); }
int	mvaddstrAlt(const int x, const int y, const string z) { return mvaddstr(x, y, z.data()); }
int	mvaddstrAlt(const int x, const int y, const char* z) { return mvaddstr(x, y, z); }
//int		mvaddstrAlt(const int x, const int y, const char* z) { return mvaddstr(x, y, z); }
//int addstrAlt(const char* x, Log y) { return addstr(x,y); }
//int addstrAlt(const string x) { return addstr(x); }
int addstrAlt(const char *text) { return addstr(text); }
int addstrAlt(const char *text, Log &log) { log.record(text); return addstr(text); }
int addstrAlt(const string &text) { int ret = ERR; for (int i = 0; i < strlen(text.data()); i++) ret = addcharAlt(text[i]); return ret; }
int addstrAlt(const string &text, Log &log) { log.record(text); return addstr(text.data()); }
int addstrAlt(const long num) { return addstr(tostring(num).data()); }
int addstrAlt(const long num, Log &log) { return addstrAlt(tostring(num).data(), log); }
int	mvaddstrAlt(const int x, const  int y, const int z) { return mvaddstr(x, y, tostring(z).data()); }
int	mvaddstrAlt(const int x, const int y, const string z, Log &a) {
	a.record(z);
	return mvaddstr(x, y, z.data());
}
int		 mvaddstrAlt(const int x, const int y, const char* z, Log &a) {
	a.record(z);
	return mvaddstr(x, y, z);
}
int		 mvaddstrAlt(const int x, const int y, const  int z, Log &a) {
	a.record(tostring(z));
	return mvaddstr(x, y, tostring(z).data());
}
int		mvaddstr_const(const MOVE_CONSTANT movement, const char *string) {
	return mvaddstrAlt(movement.y, movement.x, string);
}
int move_const(const MOVE_CONSTANT movement) {
	return moveAlt(movement.y, movement.x);
}
int center_string(const char* str);
int center_string(const char* str) {
	return 39 - ((strlen(str) - 1) >> 1);
}
int move_center_string(const int x, const char* str) {
	str;
	return mvaddstrAlt(x, center_string(str), str);
}
void set_color_easy(const ColorSetup color) {
	set_color(color.letter, color.background, color.bright, color.blink);
}
string burstToString(const int bursthits) {
	switch (bursthits) {
	case 2: return CONST_cursesAlternative004;
	case 3: return CONST_cursesAlternative005;
	case 4: return CONST_cursesAlternative006;
	case 5: return  CONST_cursesAlternative007;
	default: return singleSpace + tostring(bursthits) + CONST_cursesAlternative008;
	}
}
string qualifiedFailure(const int droll, const string name, vector<string> stringCollection) {
	return name + qualifiedFailure(droll, stringCollection);
}
string qualifiedFailure(const int droll, vector<string> stringCollection) {
	if (stringCollection.size() == 0) {
		return blankString;
	}
	if (droll < stringCollection.size() && droll >= 0) {
		return stringCollection[droll];
	}
	else {
		return stringCollection[0];
	}
}
int     clearAlt(void) {
	return clear();
}
int     refreshAlt(void) {
	return refresh();
}
void displayDifficulty(int difficulty)
{
	switch (difficulty)
	{
	case 0:	set_color_easy(GREEN_ON_BLACK_BRIGHT); break;
	case 1: set_color_easy(CYAN_ON_BLACK_BRIGHT); break;
	case 2: set_color_easy(CYAN_ON_BLACK); break;
	case 3: set_color_easy(BLUE_ON_BLACK_BRIGHT); break;
	case 4: set_color_easy(WHITE_ON_BLACK_BRIGHT); break;
	case 5: set_color_easy(WHITE_ON_BLACK); break;
	case 6: set_color_easy(YELLOW_ON_BLACK_BRIGHT); break;
	case 7: set_color_easy(MAGENTA_ON_BLACK); break;
	case 8: set_color_easy(MAGENTA_ON_BLACK_BRIGHT); break;
	case 9: set_color_easy(RED_ON_BLACK);	break;
	default:set_color_easy(RED_ON_BLACK_BRIGHT);	break;
	}
	if (difficulty >= 0 && difficulty < 10) addstrAlt(_difficulty[difficulty]); else addstrAlt(_difficulty[10]);
}
// IsaacG Various functions that are the single time
// a given aspect of the curses library is used
/*
This function prints the cash the player has with optional prefix as
well as screen coordinates.
Please note that offsetx is the offset from the right of the screen, y is
the offset from the top as always.
*//*
This function prints the cash the player has with optional prefix as
well as screen coordinates.
Please note that offsetx is the offset from the right of the screen, y is
the offset from the top as always.
*/
void printfunds(int y, int offsetx, const char* prefix, long funds)
{
	char moneystr[50], prefixbuffer[50];
	if (prefix == NULL)
		strncpy(prefixbuffer, blankString.c_str(), 50);
	else strncpy(prefixbuffer, prefix, 50);
	strcpy(moneystr, tostring(funds).data());
	//Save screen coordinates for later.
	int begy, begx;
	getyx(stdscr, begy, begx);
	//Save color and brightness information for later.
	short colorpair, front, back;
	attr_t attrs;
	attr_get(&attrs, &colorpair, NULL);
	bool dim = (attrs & WA_DIM) != 0;
	pair_content(colorpair, &front, &back);
	//Move, set color, and write.
	mvaddstrAlt(y, 80 - strlen(moneystr) - strlen(prefixbuffer) - offsetx, prefixbuffer);
	addstrAlt(moneystr);
	//Recover old settings
	set_color(front, back, dim);
	moveAlt(begy, begx);
}
int mvaddstrCenter(int i, string str) {
	int x = 39 - ((len(str) - 1) >> 1);
	if (x < 0) x = 0;
	return mvaddstrAlt(i, x, str);
}
int mvaddstrCenter(int i, string str, Log &log) {
	int x = 39 - ((len(str) - 1) >> 1);
	if (x < 0) x = 0;
	return mvaddstrAlt(i, x, str, log);
}
void noechoAlt() {
	noecho();
}
//initialize curses color
void start_colorAlt() {
	start_color();
}
void curs_setAlt(int i) {
	curs_set(i);
}
//begin the game loop
void keypadAlt(bool i) {
	keypad(stdscr, i);
}
void raw_outputAlt(bool i) {
	raw_output(i);
}
void init_pairAlt(short x, short y, short z) {
	init_pair(x, y, z);
}
void initscrAlt() {
	initscr();
}
void set_colorAlt(short f, short b, bool bright, bool blink) {
	set_color(f, b, bright, blink);
}
int checkkeyAlt() {
	return checkkey();
}
void echoAlt() {
	echo();
}
int getkeyAlt() {
	return getkey();
}
/* Allow the player to enter a name with an optional default */
void enter_name(int y, int x, char *name, int len, const char* defname)
{
	refreshAlt();
	keypadAlt(FALSE);
	raw_outputAlt(FALSE);
	echoAlt();
	curs_setAlt(1);
	mvgetnstrAlt(y, x, name, len - 1); //-1 because 'len' is normally the full space available and we need one for a terminator.
	curs_setAlt(0);
	noechoAlt();
	raw_outputAlt(TRUE);
	keypadAlt(TRUE);
	if ((defname != NULL) && (strncmp(name, blankString.c_str(), len - 1) == 0)) strncpy(name, defname, len - 1);
	name[len - 1] = '\0';
}

// Removed from consolesupport.cpp
// These 4 variables to keep track of the current color are for
// this file only
short curForeground = COLOR_WHITE, curBackground = COLOR_BLACK;
bool isBright = false, isBlinking = false;
//sets current color to desired setting
void set_color(short f, short b, bool bright, bool blink)
{
	// keep track of current color
	curForeground = f, curBackground = b, isBright = bright, isBlinking = blink;
	//color swap required for PDcurses
	if (f == 7 && b == 0) f = 0, b = 0;
	else if (f == 0 && b == 0) f = 7, b = 0;
	chtype blinky = (blink ? A_BLINK : 0), brighty = (bright ? A_BOLD : 0);
	//pick color pair based on foreground and background
	attrset(brighty | blinky | COLOR_PAIR(f * 8 + b));
}
/* Refreshes the screen, empties the keyboard buffer, waits for a new key to be pressed, and returns the key pressed */
int getkey()
{
	refresh();
	nodelay(stdscr, TRUE);
	while (getch() != ERR);
	nodelay(stdscr, FALSE);
	int c = getch();
	translategetch(c);
	return c;
}

/* Variant of getkey() that doesn't make all letters lowercase */
int getkey_cap()
{
	refresh();
	nodelay(stdscr, TRUE);
	while (getch() != ERR);
	nodelay(stdscr, FALSE);
	int c = getch();
	translategetch_cap(c);
	return c;
}
int getkey_cap_alt() {
	return getkey_cap();
}
/* Empties the keyboard buffer, and returns most recent key pressed, if any */
int checkkey()
{
	int c = ERR, ret = ERR;
	nodelay(stdscr, TRUE);
	do
	{
		ret = c;
		c = getch();
		translategetch(c);
	} while (c != ERR);
	nodelay(stdscr, FALSE);
	return ret;
}
/* Variant of checkkey() that doesn't make all letters lowercase */
// UNUSED
int checkkey_cap()
{
	int c = ERR, ret = ERR;
	nodelay(stdscr, TRUE);
	do
	{
		ret = c;
		c = getch();
		translategetch_cap(c);
	} while (c != ERR);
	nodelay(stdscr, FALSE);
	return ret;
}
/*
This function prints the cash the player has with optional prefix as
well as screen coordinates.
Please note that offsetx is the offset from the right of the screen, y is
the offset from the top as always.
*/
void printfunds(int y, int offsetx, const char* prefix)
{
	printfunds(y, offsetx, prefix, ledger.get_funds());
}

int pressSpecificKey(const int x, const int y) {
	int c;
	do {
		c = getkeyAlt();

	} while (c != x && c != y);

	return c;
}
void pressSpecificKey(const int x, const int y, const int z, const int w) {
	int c;
	do {
		c = getkeyAlt();

	} while (c != x && c != y && c != z && c != w);
}
int pressSpecificKey(const int x, const int y, const int z, const int w, const int u) {
	int c;
	do {
		c = getkeyAlt();

	} while (c != x && c != y && c != z && c != w && c != u);
	return c;
}
int pressSpecificKey(const int x, const int y, const int z) {
	int c;
	do {
		c = getkeyAlt();

	} while (c != x && c != y && c != z);
	return c;
}
// prints a formatted name, used by promoteliberals
void printname(const int hiding, const int location, const int flag, const string name) {
	int bracketcolor = -1, namecolor, brightness;
	if (hiding)
		bracketcolor = COLOR_BLACK;
	// Determine bracket color, if any, based on location
	if (location != -1)
	{
		switch (LocationsPool::getInstance().getLocationType(location))
		{
		case SITE_GOVERNMENT_POLICESTATION:
		case SITE_GOVERNMENT_COURTHOUSE:
			if (!(flag & CREATUREFLAG_SLEEPER))
				bracketcolor = COLOR_YELLOW;
			break;
		case SITE_GOVERNMENT_PRISON:
			if (!(flag & CREATUREFLAG_SLEEPER))
				bracketcolor = COLOR_RED;
			break;
		default:
			break;
		}
	}
	// Determine name color, based on recruitment style
	if (flag & CREATUREFLAG_LOVESLAVE)
		namecolor = COLOR_MAGENTA;
	else if (flag & CREATUREFLAG_BRAINWASHED)
		namecolor = COLOR_YELLOW;
	else namecolor = COLOR_WHITE;
	// Determine name brightness, based on subordinates left
	/*if(subordinatesleft(cr))
	brightness=1;
	else*/
	brightness = 0;
	// add bracket (if used)
	if (bracketcolor != -1)
	{
		set_color(bracketcolor, COLOR_BLACK, 1);
		addstrAlt(CONST_cursesAlternative011);
	}
	if (flag & CREATUREFLAG_SLEEPER)
	{
		set_color_easy(BLUE_ON_BLACK_BRIGHT);
		addstrAlt(CONST_cursesAlternative011);
	}
	// add name
	set_color(namecolor, COLOR_BLACK, brightness);
	addstrAlt(name);
	// add close bracket (if used)
	if (flag & CREATUREFLAG_SLEEPER)
	{
		set_color_easy(BLUE_ON_BLACK_BRIGHT);
		addstrAlt(CONST_cursesAlternative013);
	}
	if (bracketcolor != -1)
	{
		set_color(bracketcolor, COLOR_BLACK, 1);
		addstrAlt(CONST_cursesAlternative013);
	}
	set_color_easy(WHITE_ON_BLACK);
}

// Imperfect but quick and dirty line of sight check
// Only works if the target point is at most two spaces
// away in any direction
bool LineOfSight(int x, int y, int z)
{
	if (levelmap[x][y][z].flag&SITEBLOCK_KNOWN) return true; // already explored
	if (DIFF(x, loc_coord.locx) > 2 || DIFF(y, loc_coord.locy) > 2) return false; // too far away
	if (DIFF(x, loc_coord.locx) <= 1 && DIFF(y, loc_coord.locy) <= 1) return true; // right next to us or right where we're standing
	int x1, x2, y1, y2;
	if (DIFF(x, loc_coord.locx) == 1) x1 = loc_coord.locx, x2 = x;
	else x1 = x2 = (x + loc_coord.locx) / 2; // difference is either 0 or 2
	if (DIFF(y, loc_coord.locy) == 1) y1 = loc_coord.locy, y2 = y;
	else y1 = y2 = (y + loc_coord.locy) / 2; // difference is either 0 or 2
											 // Check for obstructions
	if ((levelmap[x1][y2][z].flag&(SITEBLOCK_BLOCK | SITEBLOCK_DOOR | SITEBLOCK_EXIT)) &&
		(levelmap[x2][y1][z].flag&(SITEBLOCK_BLOCK | SITEBLOCK_DOOR | SITEBLOCK_EXIT)))
		return false; // Blocked on some axis
	return true;
}
/* prints the names of creatures you see */
void printencounter()
{
	set_color_easy(WHITE_ON_BLACK);
	for (int i = 19; i <= 24; i++)
		mvaddstrAlt(i, 0, CONST_sitedisplay102); // 53 spaces
	int px = 1, py = 19;
	for (NameAndAlignment n : getEncounterNameAndAlignment()) {

		if (n.exists)
		{
			if (!n.alive) set_color_easy(BLACK_ON_BLACK_BRIGHT);
			else if (n.align == 0) set_color_easy(WHITE_ON_BLACK_BRIGHT);
			else if (n.align == 1) set_color_easy(GREEN_ON_BLACK_BRIGHT);
			else set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(py, px, n.name);
		}
		px += 18;
		if (px > 37) px = 1, py++;
	}
}
void checkForDirectionalVisibility(bool(&visible)[8], const int x, const int y) {

	if (x > loc_coord.locx && x < MAPX) visible[WALL_LEFT] = true;
	if (x > 0 && x < loc_coord.locx) visible[WALL_RIGHT] = true;
	if (y > loc_coord.locy && y < MAPY) visible[WALL_UP] = true;
	if (y > 0 && y < loc_coord.locy) visible[WALL_DOWN] = true;
	if (y > loc_coord.locy && y<MAPY && x>loc_coord.locx && x < MAPX) visible[CORNER_UL] = true;
	if (y > loc_coord.locy && y < MAPY && x>0 && x < loc_coord.locx) visible[CORNER_UR] = true;
	if (y > 0 && y<loc_coord.locy && x>loc_coord.locx && x < MAPX) visible[CORNER_DL] = true;
	if (y > 0 && y < loc_coord.locy && x>0 && x < loc_coord.locx) visible[CORNER_DR] = true;
}
void checkForLOS(bool(&visible)[8], const int x, const int y, const int z) {


	if (!LineOfSight(x - 1, y, z)) visible[WALL_LEFT] = false;
	if (!LineOfSight(x + 1, y, z)) visible[WALL_RIGHT] = false;
	if (!LineOfSight(x, y - 1, z)) visible[WALL_UP] = false;
	if (!LineOfSight(x, y + 1, z)) visible[WALL_DOWN] = false;
	if (!LineOfSight(x - 1, y - 1, z)) visible[CORNER_UL] = false;
	if (!LineOfSight(x + 1, y - 1, z)) visible[CORNER_UR] = false;
	if (!LineOfSight(x - 1, y + 1, z)) visible[CORNER_DL] = false;
	if (!LineOfSight(x + 1, y + 1, z)) visible[CORNER_DR] = false;
}

int getSiteFlagForWall(const int x, const int y, const int z, const wallDirection wall) {


	switch (wall) {
	case WALL_UP:
		return levelmap[x][y - 1][z].flag;
		break;
	case WALL_DOWN:
		return levelmap[x][y + 1][z].flag;
		break;
	case WALL_LEFT:
		return levelmap[x - 1][y][z].flag;
		break;
	case WALL_RIGHT:
		return levelmap[x + 1][y][z].flag;
		break;
	case CORNER_UL:
		return levelmap[x - 1][y - 1][z].flag;
		break;
	case CORNER_UR:
		return levelmap[x + 1][y - 1][z].flag;
		break;
	case CORNER_DL:
		return levelmap[x - 1][y + 1][z].flag;
		break;
	case CORNER_DR:
		return levelmap[x + 1][y + 1][z].flag;
		break;
	}
	// ERROR
	return -1;
}
void checkForWallStatus(bool(&visible)[8], const int x, const int y, const int z, const int siteflag, const bool newstate) {
	for (int i = WALL_UP; i <= CORNER_DR; i++) {
		if (getSiteFlagForWall(x, y, z, (wallDirection)i) & siteflag) {
			visible[i] = newstate;
		}
	}
}

void checkForMemory(bool(&visible)[8], const int x, const int y, const int z) {
	checkForWallStatus(visible, x, y, z, (SITEBLOCK_KNOWN), true);
}
void checkForBlockage(bool(&visible)[8], const int x, const int y, const int z) {
	checkForWallStatus(visible, x, y, z, (SITEBLOCK_BLOCK | SITEBLOCK_DOOR), false);
}
void checkForBloodyWalls(bool(&bloody)[8], const int x, const int y, const int z) {
	checkForWallStatus(bloody, x, y, z, SITEBLOCK_BLOODY2, true);
}

void checkForOtherGraffiti(char(&graffiti)[4][4], char(&graffiticolor)[4], const int x, const int y, const int z) {
	for (int i = WALL_UP; i <= WALL_RIGHT; i++) {
		if (getSiteFlagForWall(x, y, z, (wallDirection)i) & SITEBLOCK_GRAFFITI_OTHER) {
			strcpy(graffiti[i], CONST_sitedisplay014.c_str());
			graffiticolor[i] = COLOR_BLACK;
		}
	}
}
void checkForCCSGraffiti(char(&graffiti)[4][4], char(&graffiticolor)[4], const int x, const int y, const int z) {
	for (int i = WALL_UP; i <= WALL_RIGHT; i++) {
		if (getSiteFlagForWall(x, y, z, (wallDirection)i) & SITEBLOCK_GRAFFITI_CCS) {
			strcpy(graffiti[i], CONST_sitedisplay018.c_str());
			graffiticolor[i] = COLOR_RED;
		}
	}

}
void checkForLCSGraffiti(char(&graffiti)[4][4], char(&graffiticolor)[4], const int x, const int y, const int z) {
	for (int i = WALL_UP; i <= WALL_RIGHT; i++) {
		if (getSiteFlagForWall(x, y, z, (wallDirection)i) & SITEBLOCK_GRAFFITI) {
			strcpy(graffiti[i], CONST_sitedisplay022.c_str());
			graffiticolor[i] = COLOR_GREEN;
		}
	}
}

void printwall(int x, int y, const int z, const int px, const int py)
{

	bool visible[8] = { false,false,false,false,false,false,false,false };
	bool bloody[8] = { false,false,false,false,false,false,false,false };
	char graffiti[4][4] = { "   ","   ","   ","   " };
	//	char graffiti[4][4] = { CONST_sitedisplay010.c_str(),CONST_sitedisplay010.c_str(),CONST_sitedisplay010.c_str(),CONST_sitedisplay010.c_str() };
	char graffiticolor[4] = { COLOR_BLACK,COLOR_BLACK,COLOR_BLACK,COLOR_BLACK };
	int type = levelmap[x][y][z].flag; // What are we drawing here? Wall/door? Locked/jammed? Metal/normal?
									   // Now follows a series of checks to determine the faces of the wall that should be
									   // displayed. Note the order of these checks is important:
									   //
									   // 1) You will see the wall if it's the upward face and you're above it (directional visibility)...
									   // 2) ...unless your line of sight is blocked (LOS)...
									   // 3) ...but line of sight and directional visibility is not important if you have already seen that
									   //          tile (memory)...
									   // 4) ...and regardless of any of the above, if there's a physical obstruction that would prevent you
									   //          from seeing it even if you were near it, like a wall, it should not be shown (blockages).
									   //
									   // The order of the remainder of the checks is not crucial.
									   // 1) Check for directional visibility
	checkForDirectionalVisibility(visible, x, y);
	// 2) Check LOS
	checkForLOS(visible, x, y, z);
	// 3) Check for memory
	checkForMemory(visible, x, y, z);
	// 4) Check for blockages
	checkForBlockage(visible, x, y, z);
	// Below not used for doors
	if (levelmap[x][y][z].flag & SITEBLOCK_BLOCK)
	{
		// Check for bloody walls
		checkForBloodyWalls(bloody, x, y, z);
		// Check for other graffiti
		checkForOtherGraffiti(graffiti, graffiticolor, x, y, z);
		// Check for CCS graffiti
		checkForCCSGraffiti(graffiti, graffiticolor, x, y, z);
		// Check for LCS graffiti
		checkForLCSGraffiti(graffiti, graffiticolor, x, y, z);
	}
	for (int dir = 4; dir < 8; dir++)
	{
		x = px, y = py;
		// Draw the corner
		if (visible[dir] && (type & SITEBLOCK_BLOCK))
		{
			bool blink = type & SITEBLOCK_METAL;
			// Position cursor in the correct corner
			//if(dir==CORNER_UL) // Nothing to do in this case
			if (dir == CORNER_UR) x += 4;
			if (dir == CORNER_DL) y += 2;
			if (dir == CORNER_DR) y += 2, x += 4;
			// Blood overrides gray base wall color
			if (bloody[dir]) set_color(COLOR_RED, COLOR_RED, 0);
			else set_color(COLOR_WHITE, COLOR_WHITE, 0, blink);
			// The corner's ready to draw now
			mvaddcharAlt(y, x, ' ');
		}
	}
	for (int dir = 0; dir < 4; dir++)
	{
		x = px, y = py;
		// Draw the wall/door
		if (visible[dir])
		{
			if (type & SITEBLOCK_BLOCK)
			{
				bool blink = type & SITEBLOCK_METAL;
				// Position cursor at the start of where the graffiti tag would go
				//if(dir==WALL_LEFT) // Nothing to do in this case
				if (dir == WALL_RIGHT) x += 4;
				if (dir == WALL_UP) x++;
				if (dir == WALL_DOWN) y += 2, x++;
				// Blood overrides graffiti overrides gray base wall color
				if (bloody[dir])
					set_color_easy(RED_ON_RED);
				else if (graffiti[dir][0] != ' ')
					set_color(graffiticolor[dir], COLOR_WHITE, 0, blink);
				else set_color(COLOR_WHITE, COLOR_WHITE, 0, blink);
				// Draw the chunk of wall where the graffiti would/will go
				for (int gchar = 0; gchar < 3; gchar++)
				{
					mvaddcharAlt(y, x, graffiti[dir][gchar]);
					if (dir == WALL_RIGHT || dir == WALL_LEFT) y++;
					else x++;
				}
				// For the long faces (top and bottom) of the wall, there is
				// additional space to either side of the 'tag' (or lack of tag)
				// that needs to be filled in with wall or blood color
				if (dir == WALL_UP || dir == WALL_DOWN)
				{
					if (bloody[dir]) set_color_easy(RED_ON_RED);
					else set_color(COLOR_WHITE, COLOR_WHITE, 0, blink);
					if (!visible[WALL_LEFT]) mvaddcharAlt(y, px, ' ');
					if (!visible[WALL_RIGHT]) mvaddcharAlt(y, px + 4, ' ');
				}
			}
			else if (type & SITEBLOCK_DOOR)
			{
				// Doors are, thankfully, much simpler, as they do not
				// support blood or graffiti
				// Position cursor at the start of face
				if (dir == WALL_DOWN) y += 2;
				if (dir == WALL_RIGHT) x += 4;
				// Pick color
				if (type & SITEBLOCK_METAL)
					set_color_easy(WHITE_ON_WHITE_BRIGHT);
				else if (type & SITEBLOCK_CLOCK && type & SITEBLOCK_LOCKED)
					set_color_easy(RED_ON_BLACK);
				else if (type & SITEBLOCK_KLOCK && type & SITEBLOCK_LOCKED)
					set_color_easy(BLACK_ON_BLACK_BRIGHT);
				else set_color_easy(YELLOW_ON_BLACK);
				// Draw face
				if (dir == WALL_RIGHT || dir == WALL_LEFT)
					for (int i = 0; i < 3; i++) mvaddstrAlt(y++, x, CONST_sitedisplay023.c_str());
				else for (int i = 0; i < 5; i++) mvaddstrAlt(y, x++, CONST_sitedisplay024.c_str());
				// Corners are possible if walls nearby are blown away, although this is rare
				if ((dir == WALL_LEFT && visible[WALL_UP]) || (dir == WALL_UP && visible[WALL_LEFT])) mvaddstrAlt(py, px, CONST_sitedisplay025.c_str());
				if ((dir == WALL_RIGHT && visible[WALL_UP]) || (dir == WALL_UP && visible[WALL_RIGHT])) mvaddstrAlt(py, px + 4, CONST_sitedisplay026.c_str());
				if ((dir == WALL_LEFT && visible[WALL_DOWN]) || (dir == WALL_DOWN && visible[WALL_LEFT])) mvaddstrAlt(py + 2, px, CONST_sitedisplay027.c_str());
				if ((dir == WALL_RIGHT && visible[WALL_DOWN]) || (dir == WALL_DOWN && visible[WALL_RIGHT])) mvaddstrAlt(py + 2, px + 4, CONST_sitedisplay028.c_str());
			}
		}
	}
}

void printdebris(const int px, const int py) {
	const int backcolor = COLOR_BLACK;
	const char blink = 0;

	set_color(COLOR_WHITE, backcolor, 1, blink);
	mvaddcharAlt(py + 0, px + 1, '.');
	mvaddcharAlt(py + 0, px + 4, '^');
	mvaddcharAlt(py + 1, px + 0, '=');
	mvaddcharAlt(py + 1, px + 3, '.');
	mvaddcharAlt(py + 1, px + 4, '|');
	mvaddcharAlt(py + 2, px + 1, '.');
	mvaddcharAlt(py + 2, px + 4, '\\');
}
void printfirepeak(const int px, const int py) {
	const int backcolor = COLOR_BLACK;
	const char blink = 0;

	set_color(COLOR_RED, backcolor, 1, blink);
	mvaddcharAlt(py + 0, px + 1, ':');
	mvaddcharAlt(py + 1, px + 0, '*');
	set_color(COLOR_YELLOW, backcolor, 1, blink);
	mvaddcharAlt(py + 0, px + 4, '$');
	mvaddcharAlt(py + 1, px + 3, ':');
	mvaddcharAlt(py + 1, px + 4, '%');
	mvaddcharAlt(py + 2, px + 1, ':');
	mvaddcharAlt(py + 2, px + 4, '*');
}
void printfirestart(const int px, const int py) {
	const int backcolor = COLOR_BLACK;
	const char blink = 0;

	set_color(COLOR_RED, backcolor, 1, blink);
	mvaddcharAlt(py + 0, px + 1, '.');
	set_color(COLOR_YELLOW, backcolor, 1, blink);
	mvaddcharAlt(py + 1, px + 3, '.');
	mvaddcharAlt(py + 2, px + 1, '.');
}
void printfireend(const int px, const int py) {
	const int backcolor = COLOR_BLACK;
	const char blink = 0;

	set_color(COLOR_RED, backcolor, 1, blink);
	mvaddcharAlt(py + 1, px + 0, '*');
	set_color(COLOR_YELLOW, backcolor, 1, blink);
	mvaddcharAlt(py + 0, px + 4, '~');
	mvaddcharAlt(py + 2, px + 4, '#');
	set_color(COLOR_WHITE, backcolor, 1, blink);
	mvaddcharAlt(py + 0, px + 1, '.');
	mvaddcharAlt(py + 1, px + 3, '.');
	mvaddcharAlt(py + 1, px + 4, '|');
	mvaddcharAlt(py + 2, px + 1, '.');
}

void printbloodyone(const int px, const int py) {
	const int backcolor = COLOR_BLACK;
	const char blink = 0;

	set_color(COLOR_RED, backcolor, 0, blink);
	mvaddcharAlt(py + 2, px + 1, '.');
	mvaddcharAlt(py + 1, px + 2, '.');
}
void printbloodytwo(const int px, const int py) {
	const int backcolor = COLOR_BLACK;
	const char blink = 0;

	set_color(COLOR_RED, backcolor, 0, blink);
	mvaddcharAlt(py + 1, px + 1, '%');
	mvaddcharAlt(py + 2, px + 1, '.');
	mvaddcharAlt(py + 1, px + 2, '.');
}
void printspecialtile(const short special, const int px, const int py) {
	const int backcolor = COLOR_BLACK;
	const char blink = 0;
	set_color(COLOR_YELLOW, backcolor, 1, blink);
	switch (special)
	{
	case SPECIAL_NUCLEAR_ONOFF:mvaddstrAlt(py, px, CONST_sitedisplay033); break;
	case SPECIAL_LAB_COSMETICS_CAGEDANIMALS:
	case SPECIAL_LAB_GENETIC_CAGEDANIMALS:mvaddstrAlt(py, px, CONST_sitedisplay034); break;
	case SPECIAL_POLICESTATION_LOCKUP:
	case SPECIAL_COURTHOUSE_LOCKUP:mvaddstrAlt(py, px, CONST_sitedisplay035); break;
	case SPECIAL_COURTHOUSE_JURYROOM:mvaddstrAlt(py, px, CONST_sitedisplay036); break;
	case SPECIAL_PRISON_CONTROL:
	case SPECIAL_PRISON_CONTROL_LOW:
	case SPECIAL_PRISON_CONTROL_MEDIUM:
	case SPECIAL_PRISON_CONTROL_HIGH:mvaddstrAlt(py, px, CONST_sitedisplay037); break;
	case SPECIAL_INTEL_SUPERCOMPUTER:mvaddstrAlt(py, px, CONST_sitedisplay038); break;
	case SPECIAL_SWEATSHOP_EQUIPMENT:
	case SPECIAL_POLLUTER_EQUIPMENT:mvaddstrAlt(py, px, CONST_sitedisplay039); break;
	case SPECIAL_ARMORY:mvaddstrAlt(py, px, CONST_sitedisplay040); break;
	case SPECIAL_HOUSE_CEO:mvaddstrAlt(py, px + 1, tag_CEO); break;
	case SPECIAL_HOUSE_PHOTOS:
	case SPECIAL_CORPORATE_FILES:mvaddstrAlt(py, px, CONST_sitedisplay041); break;
	case SPECIAL_RADIO_BROADCASTSTUDIO:mvaddstrAlt(py, px + 1, CONST_sitedisplay042); break;
	case SPECIAL_NEWS_BROADCASTSTUDIO:mvaddstrAlt(py, px, CONST_sitedisplay043); break;
	case SPECIAL_APARTMENT_LANDLORD:mvaddstrAlt(py, px, CONST_sitedisplay044); break;
	case SPECIAL_SIGN_ONE:
	case SPECIAL_SIGN_TWO:
	case SPECIAL_SIGN_THREE:mvaddstrAlt(py, px, CONST_sitedisplay045); break;
	case SPECIAL_STAIRS_UP:mvaddstrAlt(py, px + 1, "UP\x18"); break;
	case SPECIAL_STAIRS_DOWN:mvaddstrAlt(py, px + 1, "DN\x19"); break;
	case SPECIAL_RESTAURANT_TABLE:mvaddstrAlt(py, px, CONST_sitedisplay046); break;
	case SPECIAL_CAFE_COMPUTER:mvaddstrAlt(py, px + 1, CONST_sitedisplay047); break;
	case SPECIAL_PARK_BENCH:mvaddstrAlt(py, px, CONST_sitedisplay048); break;
	case SPECIAL_SECURITY_METALDETECTORS:mvaddstrAlt(py, px, CONST_sitedisplay049); break;
	case SPECIAL_SECURITY_CHECKPOINT:mvaddstrAlt(py, px, CONST_sitedisplay050); break;
	case SPECIAL_DISPLAY_CASE:mvaddstrAlt(py, px, CONST_sitedisplay051); break;
	case SPECIAL_BANK_VAULT:mvaddstrAlt(py, px, CONST_sitedisplay052); break;
	case SPECIAL_BANK_TELLER:mvaddstrAlt(py, px, CONST_sitedisplay053); break;
	case SPECIAL_BANK_MONEY:mvaddstrAlt(py, px, tag_MONEY); break;
	case SPECIAL_CCS_BOSS:mvaddstrAlt(py, px, CONST_sitedisplay054); break;
	case SPECIAL_OVAL_OFFICE_NW:mvaddstrAlt(py, px + 3, CONST_sitedisplay055); break;
	case SPECIAL_OVAL_OFFICE_NE:mvaddstrAlt(py, px, CONST_sitedisplay056); break;
	case SPECIAL_OVAL_OFFICE_SW:mvaddstrAlt(py, px + 2, CONST_sitedisplay057); break;
	case SPECIAL_OVAL_OFFICE_SE:mvaddstrAlt(py, px, CONST_sitedisplay058); break;
	}
}
void printemptysquare(const int flag, const int px, const int py) {
	char ch;
	if (flag & SITEBLOCK_RESTRICTED)
	{
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		ch = '+';
	}
	else if (flag & SITEBLOCK_GRASSY)
	{
		set_color_easy(GREEN_ON_BLACK);
		ch = '.';
	}
	else if (flag & SITEBLOCK_OUTDOOR)
	{
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		ch = ' ';
	}
	else
	{
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		ch = ' ';
	}
	for (int px2 = px; px2 < px + 5; px2++)
		for (int py2 = py; py2 < py + 3; py2++)
			mvaddcharAlt(py2, px2, ch);
}
void printsiteexit(const int px, const int py) {

	const int backcolor = COLOR_BLACK;
	const char blink = 0;
	set_color(COLOR_WHITE, backcolor, 0, blink);
	mvaddstrAlt(py + 1, px + 1, CONST_sitedisplay029);
}
void printsiteloot(const int px, const int py) {

	const int backcolor = COLOR_BLACK;
	const char blink = 0;
	set_color(COLOR_MAGENTA, backcolor, 1, blink);
	mvaddstrAlt(py, px + 1, CONST_sitedisplay030);
}
void printstatusofsquare(const int flag, const int px, const int py) {
	// These functions mostly overwrite one another in the event multiple are true
	// The big exception is the last two, and later on the other instances
	// Of strings being printed, rather than char based
	if (flag & SITEBLOCK_DEBRIS)
	{
		printdebris(px, py);
	}
	if (flag & SITEBLOCK_FIRE_START)
	{
		printfirestart(px, py);
	}
	if (flag & SITEBLOCK_FIRE_PEAK)
	{
		printfirepeak(px, py);
	}
	if (flag & SITEBLOCK_FIRE_END)
	{
		printfireend(px, py);
	}
	if (flag & SITEBLOCK_BLOODY)
	{
		printbloodyone(px, py);
	}
	if (flag & SITEBLOCK_BLOODY2)
	{
		printbloodytwo(px, py);
	}
	if (flag & SITEBLOCK_EXIT)
	{
		printsiteexit(px, py);
	}
	else if (flag & SITEBLOCK_LOOT)
	{
		printsiteloot(px, py);
	}
}
void printblock(int x, int y, int z, int px, int py)
{
	if (!LineOfSight(x, y, z))
	{
		set_color_easy(BLACK_ON_BLACK);
		for (x = px; x < px + 5; x++)
			for (y = py; y < py + 3; y++)
				mvaddcharAlt(y, x, ' ');
	}
	else {
		levelmap[x][y][z].flag |= SITEBLOCK_KNOWN;
		if (levelmap[x][y][z].flag & (SITEBLOCK_BLOCK | SITEBLOCK_DOOR))
		{
			printwall(x, y, z, px, py);
		}
		else {
			const int backcolor = COLOR_BLACK;
			const char blink = 0;
			printemptysquare(levelmap[x][y][z].flag, px, py);
			printstatusofsquare(levelmap[x][y][z].flag, px, py);

			if (levelmap[x][y][z].siegeflag & SIEGEFLAG_TRAP)
			{
				set_color(COLOR_YELLOW, backcolor, 1, blink);
				mvaddstrAlt(py + 1, px, CONST_sitedisplay031);
			}
			else if (levelmap[x][y][z].siegeflag & SIEGEFLAG_UNIT_DAMAGED)
			{
				set_color(COLOR_RED, backcolor, 0, blink);
				mvaddstrAlt(py + 2, px, CONST_sitedisplay093);
			}
			else if (levelmap[x][y][z].special != -1)
			{
				printspecialtile(levelmap[x][y][z].special, px, py);

			}
			if (levelmap[x][y][z].siegeflag & SIEGEFLAG_HEAVYUNIT)
			{
				set_color(COLOR_RED, backcolor, 1, blink);
				mvaddstrAlt(py + 2, px, tag_ARMOR);
			}
			else if (levelmap[x][y][z].siegeflag & SIEGEFLAG_UNIT)
			{
				set_color(COLOR_RED, backcolor, 1, blink);
				mvaddstrAlt(py + 2, px, CONST_sitedisplay092);
			}
		}
	}
}
// Prints the map graphics in the bottom right of the screen
void printsitemap(int x, int y, int z)
{
	mapshowing = true;
	// Build the frame
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(8, 53, CONST_sitedisplay060.c_str()); // 27 characters - top of map
	mvaddstrAlt(24, 53, CONST_sitedisplay061.c_str()); // 27 characters - bottom of map
	for (int yscreen = 9; yscreen < 24; yscreen++)
		mvaddstrAlt(yscreen, 53, CONST_sitedisplay062.c_str()); // 27 characters - the map itself
																// Do a preliminary Line of Sight iteration for better Line of Sight detection
	for (int xsite = x - 2; xsite < x + 3; xsite++)
		for (int ysite = y - 2; ysite < y + 3; ysite++)
			if (LineOfSight(xsite, ysite, z))
				levelmap[xsite][ysite][z].flag |= SITEBLOCK_KNOWN;
	// Display the map
	for (int xsite = x - 2, xscreen = 79 - 5 * 5; xsite < x + 3; xscreen += 5, xsite++)
		for (int ysite = y - 2, yscreen = 24 - 3 * 5; ysite < y + 3; yscreen += 3, ysite++)
			printblock(xsite, ysite, z, xscreen, yscreen);
	//PRINT SPECIAL
	string str;
	if (specialString.count(static_cast<SpecialBlocks>(levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special)) > 0) {
		str = specialString[static_cast<SpecialBlocks>(levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special)];
	}
	else {
		str = blankString;
	}

	if (levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special != -1)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(24, 67 - (len(str) >> 1), str);
	}
	//PRINT PARTY
	int partyalive = squadAlive();
	if (partyalive > 0) set_color_easy(GREEN_ON_BLACK_BRIGHT);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 64, CONST_sitedisplay091);
	int encsize = encounterSize();
	//PRINT ANY OPPOSING FORCE INFO
	if (encsize)
	{
		set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		if (levelmap[loc_coord.locx][loc_coord.locx][loc_coord.locz].siegeflag & SIEGEFLAG_HEAVYUNIT)
			mvaddstrAlt(17, 64, tag_ARMOR);
		else if (levelmap[loc_coord.locx][loc_coord.locx][loc_coord.locz].siegeflag & SIEGEFLAG_UNIT)
			mvaddstrAlt(17, 64, CONST_sitedisplay092);
		else if (levelmap[loc_coord.locx][loc_coord.locx][loc_coord.locz].siegeflag & SIEGEFLAG_UNIT_DAMAGED)
			mvaddstrAlt(17, 64, CONST_sitedisplay093);
		else mvaddstrAlt(17, 64, CONST_sitedisplay094);
		printencounter();
	}
	if (isThereGroundLoot())
	{
		set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
		mvaddstrAlt(15, 64, CONST_sitedisplay095);
		printencounter();
	}
}
void clearmaparea(bool lower, bool upper)
{
	if (upper) mapshowing = false;
	set_color_easy(WHITE_ON_BLACK);
	for (int y = 8; y < 25; y++)
	{
		if (!upper&&y < 15)continue;
		if (!lower&&y >= 15)continue;
		if (y == 8) mvaddstrAlt(y, 53, CONST_sitedisplay096);  // 27 characters
		else mvaddstrAlt(y, 53, CONST_sitedisplay097);  // 27 spaces
	}
}
/* blanks a part of the screen */
void clearcommandarea()
{
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	for (int y = 9; y < 16; y++)
		mvaddstrAlt(y, 0, CONST_sitedisplay102); // 53 spaces
	if (mode != GAMEMODE_SITE) clearmaparea(false, true);
}
void refreshmaparea()
{
	if (mode == GAMEMODE_SITE) printsitemap(loc_coord.locx, loc_coord.locy, loc_coord.locz);
	else clearmaparea(true, false);
}
void clearmessagearea(bool redrawmaparea)
{
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	if (redrawmaparea)
	{
		mvaddstrAlt(16, 0, CONST_sitedisplay100); // 80 spaces
		mvaddstrAlt(17, 0, CONST_sitedisplay100); // 80 spaces
		refreshmaparea();
		// Must reprint chasers when no map to the right
		if (mode == GAMEMODE_CHASECAR || mode == GAMEMODE_CHASEFOOT) printchaseencounter();
	}
	else
	{
		mvaddstrAlt(16, 0, CONST_sitedisplay102); // 53 spaces
		mvaddstrAlt(17, 0, CONST_sitedisplay102); // 53 spaces
	}
}
/* news - show major news story */
void preparepage(const Deprecatednewsstoryst ns, const bool liberalguardian)
{
	set_color_easy(WHITE_ON_WHITE);
	for (int x = 0; x < 80; x++)
		for (int y = 0; y < 25; y++)
			mvaddcharAlt(y, x, ' ');
	set_color_easy(WHITE_ON_BLACK);
	if (ns.page == 1 || (liberalguardian&&ns.guardianpage == 1))
	{
		//TOP
		int pap = LCSrandom(5);
		for (int x = 0; x < 80; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				if (liberalguardian)
				{
					set_color((newstops[5][x][y][1]),
						(newstops[5][x][y][2]),
						newstops[5][x][y][3]);
					mvaddcharAlt(y, x, newstops[5][x][y][0]);
				}
				else
				{
					set_color((newstops[pap][x][y][1]),
						(newstops[pap][x][y][2]),
						newstops[pap][x][y][3]);
					mvaddcharAlt(y, x, newstops[pap][x][y][0]);
				}
			}
		}
		if (!liberalguardian) // Liberal Guardian graphics don't support adding a date
		{
			//DATE
			set_color_easy(BLACK_ON_WHITE);
			int pday = day, pmonth = month, pyear = year;
			if (pday > monthday()) // Day counter has increased but end-of-month has not yet
			{ // been checked so it has to be accounted for here.
				pday = 1, pmonth++;
				if (pmonth > 12) pmonth = 1, pyear++;
			}
			mvaddstrAlt(3, 66 + (pday < 10), getmonth(pmonth, true));
			addstrAlt(singleSpace);
			addstrAlt(pday);
			addstrAlt(commaSpace);
			addstrAlt(pyear);
		}
	}
	else
	{
		//PAGE
		set_color_easy(BLACK_ON_WHITE);
		mvaddstrAlt(0, 76, liberalguardian ? ns.guardianpage : ns.page);
	}
}

void displaycenterednewsfont(const std::string& str, int y)
{
	int width = -1;
	for (int s = 0; s < len(str); s++)
	{
		if (str[s] >= 'A'&&str[s] <= 'Z')width += 6;
		else if (str[s] == '\'')width += 4;
		else width += 3;
	}
	int x = 39 - width / 2;
	for (int s = 0; s < len(str); s++)
	{
		if ((str[s] >= 'A'&&str[s] <= 'Z') || str[s] == '\'')
		{
			int p;
			if (str[s] >= 'A'&&str[s] <= 'Z') p = str[s] - 'A';
			else p = 26;
			int lim = 6;
			if (str[s] == '\'') lim = 4;
			if (s == len(str) - 1) lim--;
			for (int x2 = 0; x2 < lim; x2++) for (int y2 = 0; y2 < 7; y2++)
			{
				// Clean the square first.
				set_color_easy(BLACK_ON_BLACK);
				mvaddchAlt(y + y2, x + x2, ' ');
				if (x2 == 5)
				{
					set_color_easy(WHITE_ON_WHITE);
					mvaddchAlt(y + y2, x + x2, ' ');
				}
				else
				{
					set_color((bigletters[p][x2][y2][1]),
						(bigletters[p][x2][y2][2]),
						bigletters[p][x2][y2][3]);
					mvaddcharAlt(y + y2, x + x2, bigletters[p][x2][y2][0]);
				}
			}
			x += lim;
		}
		else
		{
			set_color_easy(WHITE_ON_WHITE);
			for (int x2 = 0; x2 < 3; x2++) for (int y2 = 0; y2 < 7; y2++)
			{
				mvaddcharAlt(y + y2, x + x2, ' ');
			}
			x += 3;
		}
	}
}

void displaynewspicture(int p, int y)
{
	for (int x2 = 0; x2 < 78; x2++)
		for (int y2 = 0; y2 < 15; y2++)
		{
			if (y + y2 > 24) break;
			set_color((newspic[p][x2][y2][1]),
				(newspic[p][x2][y2][2]),
				newspic[p][x2][y2][3]);
			moveAlt(y + y2, 1 + x2);
			addcharAlt(newspic[p][x2][y2][0]);
		}
}

void setColorForArmor(const Armor ar) {
	int fg = COLOR_WHITE;
	int bg = COLOR_BLACK;
	int in = 1;
	if (ar.is_bloody())
	{
		bg = COLOR_RED;  in = 1;
	}
	if (ar.get_quality() > ar.get_quality_levels())
	{
		fg = COLOR_BLACK;
	}
	else if (ar.is_damaged())
	{
		fg = COLOR_YELLOW; in = 1;
	}
	else if (ar.get_quality() > 1)
	{
		fg = COLOR_YELLOW; in = (bg == COLOR_RED);
	}
	if (fg == COLOR_WHITE && bg == COLOR_BLACK)
		in = 0;
	set_color(fg, bg, in);
}


void set_color_for_armor(const Armor armor) {
	int fg = COLOR_WHITE;
	int bg = COLOR_BLACK;
	int in = 1;
	if (armor.is_bloody())
	{
		bg = COLOR_RED;  in = 0;
	}
	if (armor.get_quality() > armor.get_quality_levels())
	{
		fg = COLOR_BLACK;
	}
	else if (armor.is_damaged())
	{
		fg = COLOR_YELLOW; in = 1;
	}
	else if (armor.get_quality() > 1)
	{
		fg = COLOR_YELLOW; in = (bg == COLOR_RED);
	}
	if (fg == COLOR_WHITE && bg == COLOR_BLACK)
		in = 0;
	set_color(fg, bg, in);
}


bool has_ignited(const int c) {

	// Ignition currently follows five steps
	//CH_BOX_DRAWINGS_LIGHT_VERTICAL
	//CH_DARK_SHADE
	//CH_MEDIUM_SHADE
	//CH_LIGHT_SHADE
	//' '
	// Any character other than these five indicate non-ignition
	// therfore, only these five should not be used in flag design
	return c == CH_BOX_DRAWINGS_LIGHT_VERTICAL ||
		c == CH_DARK_SHADE ||
		c == CH_MEDIUM_SHADE ||
		c == CH_LIGHT_SHADE  ||
		c == ' ';
}

void printFlagB() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 18; j++) {
			set_color_easy(AmericanFlag[i][j].first);
			mvaddchAlt(i + 10, j + 31, AmericanFlag[i][j].second);
		}
	}
}
void printFlag() {
	
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 17; j++) {
				set_color_easy(ConfederateFlag[i][j].first);
				mvaddchAlt(i + 10, j + 31, ConfederateFlag[i][j].second);
			}
		}
}
/* base - burn the flag */
void burnflag()
{
	const int FLAG_HEIGHT = 7;
	const int FLAG_WIDTH = 17;
	int flagparts = FLAG_HEIGHT * FLAG_WIDTH;
	std::pair<ColorSetup, int> flag[FLAG_WIDTH][FLAG_HEIGHT];
	for (int y = 0; y < FLAG_HEIGHT; y++) {
		for (int x = 0; x < FLAG_WIDTH; x++) {
			flag[x][y] = ConfederateFlag[y][x];
		}
	}
	int x1 = LCSrandom(FLAG_WIDTH);
	int y1 = LCSrandom(FLAG_HEIGHT);
	flag[x1][y1] = std::pair<ColorSetup, int>(YELLOW_ON_BLACK_BRIGHT, CH_DARK_SHADE);
	bool first = true;
	while (flagparts > 0)
	{
		if (!first) for (int x = 0; x < FLAG_WIDTH; x++) for (int y = 0; y < FLAG_HEIGHT; y++)
		{
			if (flag[x][y].second == CH_BOX_DRAWINGS_LIGHT_VERTICAL) { flag[x][y] = std::pair<ColorSetup, int>(flag[x][y].first, CH_DARK_SHADE); }
			else if (flag[x][y].second == CH_DARK_SHADE)
			{
				flag[x][y] = std::pair<ColorSetup, int>(RED_ON_BLACK, CH_MEDIUM_SHADE);
			}
			else if (flag[x][y].second == CH_MEDIUM_SHADE)
			{
				flag[x][y] = std::pair<ColorSetup, int>(BLACK_ON_BLACK_BRIGHT, CH_LIGHT_SHADE);
			}
			else if (flag[x][y].second == CH_LIGHT_SHADE)
			{
				flagparts--;
				flag[x][y] = std::pair<ColorSetup, int>(BLACK_ON_BLACK, ' ');
			}
		}
		else first = false;
		for (int x = 0; x < FLAG_WIDTH; x++) for (int y = 0; y < FLAG_HEIGHT; y++)
		{
			set_color_easy(flag[x][y].first);
			mvaddchAlt(y + 10, x + 31, flag[x][y].second);
		}

		pause_ms(10);

		bool gotnew = false;
		while (!gotnew&&flagparts > 3)
		{
			int x = LCSrandom(FLAG_WIDTH);
			int y = LCSrandom(FLAG_HEIGHT);

			if (!has_ignited(flag[x][y].second))
			{
				bool conf = false;
				if (x > 0)
				{
					if (has_ignited(flag[x - 1][y].second)) conf = true;
				}
				if (x < 17)
				{
					if (has_ignited(flag[x + 1][y].second)) conf = true;
				}
				if (y > 0)
				{
					if (has_ignited(flag[x][y - 1].second)) conf = true;
				}
				if (y < 6)
				{
					if (has_ignited(flag[x][y + 1].second)) conf = true;
				}
				if (conf)
				{
					flag[x][y] = std::pair<ColorSetup, int>(YELLOW_ON_BLACK_BRIGHT, CH_BOX_DRAWINGS_LIGHT_VERTICAL);
					gotnew = true;
				}
			}
		}
	}
}

/*
Copyright (c) 2002,2003,2004 by Tarn Adams                                            //
//
This file is part of Liberal Crime Squad.                                             //
//
Liberal Crime Squad is free software; you can redistribute it and/or modify     //
it under the terms of the GNU General Public License as published by            //
the Free Software Foundation; either version 2 of the License, or               //
(at your option) any later version.                                             //
//
Liberal Crime Squad is distributed in the hope that it will be useful,          //
but WITHOUT ANY WARRANTY; without even the implied warranty of                  //
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.   See the                  //
GNU General Public License for more details.                                    //
//
You should have received a copy of the GNU General Public License               //
along with Liberal Crime Squad; if not, write to the Free Software              //
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA   02111-1307   USA     //
*/
/*
This file was created by Chris Johnson (grundee@users.sourceforge.net)
by copying code from game.cpp.
To see descriptions of files and functions, see the list at
the bottom of includes.h in the top src folder.
*/
#define CONSOLE_SUPPORT // define this BEFORE including anything

void    PDC_set_titleAlt(const char *ch);
#if defined(USE_NCURSES)
#include <term.h>
#elif defined(USE_NCURSES_W)
#include <ncursesw/term.h>
#endif
//IN CASE FUNKY ARROW KEYS ARE SENT IN, TRANSLATE THEM BACK
void translategetch(int &c)
{
	//if(c==-63)c='7';
	//if(c==-62)c='8';
	//if(c==-61)c='9';
	//if(c==-60)c='4';
	//if(c==-59)c='5';
	//if(c==-58)c='6';
	//if(c==-57)c='1';
	//if(c==-56)c='2';
	//if(c==-55)c='3';
	if (c == -6 || c == 0x1FA) c = '0';
	if (c == -50 || c == 0x1CE) c = '.';
	if (c == -53 || c == 0x1CB) c = ENTER;
	if (c == -47 || c == 0x1D1) c = '+';
	if (c == -48 || c == 0x1D0) c = '-';
	if (c == -49 || c == 0x1CF) c = '*';
	if (c == -54 || c == 0x1CA) c = '/';
	/*
	if(c==2)c='2';
	if(c==3)c='8';
	if(c==4)c='4';
	if(c==5)c='6';
	*/
	// SPECIAL TRANSLATION for AZERTY keyboard
	if (interface_pgup == '.')
	{
		if (c == ';')c = '.';
		if (c == ':')c = '/';
		if (c == '&')c = '1';
		if (c == 0x82)c = '2';
		if (c == '\"')c = '3';
		if (c == '\'')c = '4';
		if (c == '(')c = '5';
		if (c == '-')c = '6';
		if (c == 0x8A)c = '7';
		if (c == '_')c = '8';
		if (c == 0x87)c = '9';
		if (c == 0x85)c = '0';
	}
	if (c >= 'A'&&c <= 'Z') { c += 'a' - 'A'; }
	/* Support Cursor Keys...*/
	//if(c==KEY_LEFT)c='a';
	//if(c==KEY_RIGHT)c='d';
	//if(c==KEY_UP)c='w';
	//if(c==KEY_DOWN)c='x';
}
void translategetch_cap(int &c)
{
	//if(c==-63)c='7';
	//if(c==-62)c='8';
	//if(c==-61)c='9';
	//if(c==-60)c='4';
	//if(c==-59)c='5';
	//if(c==-58)c='6';
	//if(c==-57)c='1';
	//if(c==-56)c='2';
	//if(c==-55)c='3';
	if (c == -6 || c == 0x1FA) c = '0';
	if (c == -50 || c == 0x1CE) c = '.';
	if (c == -53 || c == 0x1CB) c = ENTER;
	if (c == -47 || c == 0x1D1) c = '+';
	if (c == -48 || c == 0x1D0) c = '-';
	if (c == -49 || c == 0x1CF) c = '*';
	if (c == -54 || c == 0x1CA) c = '/';
	/*
	if(c==2)c='2';
	if(c==3)c='8';
	if(c==4)c='4';
	if(c==5)c='6';
	*/
}
#ifdef CH_USE_UNICODE
bool unicode_enabled = false;
bool setup_unicode() {
#ifdef WIN32
#ifdef PDC_WIDE
	unicode_enabled = true; // We're using a version of PDCurses with UTF-8 support (e.g. from pdc34dllu.zip)
#else
	unicode_enabled = false; // We're using a version of PDCurses without UTF-8 support (e.g. from pdc34dllw.zip)
#endif
#else
	// Is it a UTF-8 locale?
	unicode_enabled = !strcmp(nl_langinfo(CODESET), CONST_consolesupport000);
#endif
	return unicode_enabled;
}
int lookup_unicode_hack(int c) {
	for (int i = 0; i < len(unicode_hacks); i++)
		if (unicode_hacks[i].unicode_char == c)
			return unicode_hacks[i].hack_char;
	return '?';
}
#endif
#ifndef CH_USE_CP437
// This function's for both UTF-8 and the ASCII hack (only disabled in pure CP437 mode)
int addch_unicode(int c) {
#ifdef CH_USE_UNICODE
	// This part here is for Unicode only, not the ASCII hack
	wchar_t wch;
	cchar_t cch;
	if (unicode_enabled) {
		// We can do this because we've already verified
		// that __STDC_ISO_10646__ is set.
		wch = c;
		setcchar(&cch, &wch, 0, 0, NULL);
		return add_wch(&cch);
	}
	else {
		c = lookup_unicode_hack(c);
#endif
		// Now this code will run on both Unicode AND the ASCII hack
		if (c&A_REVERSE)
		{  // we need to reverse the colors
			c &= ~A_REVERSE; // unset A_REVERSE for the character, curses does it wrong
			set_color(curBackground, curForeground, isBlinking, isBright); // reverse colors
			int ret = addch(c); // add the character
			set_color(curBackground, curForeground, isBlinking, isBright); // reverse them back again
			return ret; // done
		} // don't need to reverse colors, just add the character
		else return addch(c);
#ifdef CH_USE_UNICODE
	}
#endif
}
#endif
void set_title(char *s)
{
#ifdef NCURSES
	if (tgetflag(CONST_consolesupport001))
	{ // terminal has status line support
		char buf[255] = { 0 };
		char *p = buf; // tgetstr modifies its second argument, let buf keep pointing to the beginning
		char *ok; // tgetstr's return value is apparently undocumented, except that it's NULL on errors
		ok = tgetstr(CONST_consolesupport002, &p); // CONST_consolesupportB010
		if (!ok) return;
		strcpy(p - 1, s); // tgetstr leaves us *after* the null, so skip back a bit
		p += len(s) - 1; // same here
		ok = tgetstr(CONST_consolesupport003, &p); // CONST_consolesupportB011
		if (!ok) return;
		putp(buf);
	}
#else // assume pdcurses
	PDC_set_titleAlt(s);
#endif
}
// Initialize the console, depending on the OS and language/code page settings
void init_console()
{
#ifdef WIN32
	// This has to be set to Code Page 437 in Windows regardless of Unicode, that's just how PDCurses works on Windows, even the UTF-8 version of PDCurses
	SetConsoleOutputCP(437); // use Code Page 437 (US English code page for DOS) for output, regardless of anything else
	SetConsoleCP(437); // use Code Page 437 (US English code page for DOS) for input, regardless of anything else
	setlocale(LC_ALL, CONST_consolesupport004.c_str());
	_setmbcp(_MB_CP_LOCALE); // use same code page as multibyte code page
#else // WIN32
#ifdef CH_USE_UNICODE
	setlocale(LC_ALL, CONST_consolesupport005.c_str()); // POSIX-compliant OSes DO support UTF-8/Unicode for setlocale, unlike Windows
#endif
#ifdef CH_USE_CP437
	setlocale(LC_ALL, CONST_consolesupport007.c_str());
#endif
#ifdef CH_USE_ASCII_HACK
	setlocale(LC_ALL, CONST_consolesupport007.c_str());
#endif
#endif // WIN32
#ifdef CH_USE_UNICODE
	setup_unicode();
#endif
}
#ifdef WIN32
BOOL FontSmoothingEnabled;
UINT TypeOfFontSmoothing;
void begin_cleartype_fix() // execute this function after loading settings from init.txt, but before the user is actively playing the game
{
	if (fixcleartype) // only do anything if fixcleartype was set in init.txt and we're running Windows XP or later
	{
		// first we get the font smoothing parameters from Windows so that the old settings are backed up
		SystemParametersInfo(SPI_GETFONTSMOOTHING, 0, &FontSmoothingEnabled, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
		SystemParametersInfo(SPI_GETFONTSMOOTHINGTYPE, 0, &TypeOfFontSmoothing, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
		// now we see if the game crashed or exited prematurely the last time, and load the font smoothing parameters from the file if
		//     that is the case, to ensure that the user's original font smoothing settings will be restored when they exit the game
		FILE *h;
		h = LCSOpenFile(CONST_consolesupport010.c_str(), CONST_consolesupport011.c_str(), LCSIO_PRE_HOME);
		if (h != NULL)
		{
			fread(&FontSmoothingEnabled, sizeof(BOOL), 1, h);
			fread(&TypeOfFontSmoothing, sizeof(UINT), 1, h);
			LCSCloseFile(h);
		}
		// now that we know for sure what the original settings were, and both the variables FontSmoothingEnabled and
		// TypeOfFontSmoothing are guaranteed to be the original settings prior to any modifications by this game, we can
		// back the original settings up to disk, in case the game crashes or is exited prematurely
		h = LCSOpenFile(CONST_consolesupport010.c_str(), CONST_consolesupport012.c_str(), LCSIO_PRE_HOME);
		if (h != NULL)
		{
			fwrite(&FontSmoothingEnabled, sizeof(BOOL), 1, h);
			fwrite(&TypeOfFontSmoothing, sizeof(UINT), 1, h);
			LCSCloseFile(h);
			// now that everything is safely backed up, we set the font smoothing parameters to be optimal for Liberal Crime Squad
			// ClearType messes things up and causes visual artifacts in Win32 Console Apps like this game so it's going to be off
			// but we'll have standard font smoothing on because it looks really good with Lucida Console, and doesn't affect raster fonts at all
			SystemParametersInfo(SPI_SETFONTSMOOTHING, TRUE, 0, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
			SystemParametersInfo(SPI_SETFONTSMOOTHINGTYPE, 0, (void*)FE_FONTSMOOTHINGSTANDARD, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
		}
	}
}
void end_cleartype_fix() // execute this function after the user is done playing the game, but before the program closes
{
	if (fixcleartype) // only do anything if fixcleartype was set in init.txt and we're running Windows XP or later
	{
		// restore the original settings the user had for font smoothing
		SystemParametersInfo(SPI_SETFONTSMOOTHINGTYPE, 0, (void*)TypeOfFontSmoothing, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
		SystemParametersInfo(SPI_SETFONTSMOOTHING, FontSmoothingEnabled, 0, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
		// now that the settings are safely restored, it's time to delete the temporary backup of the font smoothing settings
		LCSDeleteFile(CONST_consolesupport010.c_str(), LCSIO_PRE_HOME);
	}
}
#endif
// STEALTH_CPP
void printShoutsForHelp(const string ename, const int ealign) {
	clearmessagearea();
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, ename, gamelog);
	addstrAlt(CONST_stealth055, gamelog);
	if (ealign == ALIGN_CONSERVATIVE)
		mvaddstrAlt(17, 1, CONST_stealth074, gamelog);
	else mvaddstrAlt(17, 1, CONST_stealth075, gamelog);
	gamelog.newline();
}
void printAlienation(const short sitealienate) {

	set_color_easy(YELLOW_ON_BLACK_BRIGHT);
	if (sitealienate == 1)mvaddstrAlt(16, 1, CONST_stealth059, gamelog);
	else mvaddstrAlt(16, 1, CONST_stealth060, gamelog);
	gamelog.newline();
	mvaddstrAlt(17, 1, CONST_stealth061);
}
void printFadesAway(const string aname, const int partysize) {

	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	if (partysize > 1)
		mvaddstrAlt(16, 1, CONST_stealth065, gamelog);
	else
		mvaddstrAlt(16, 1, aname, gamelog);
	addstrAlt(CONST_stealth064, gamelog);
	gamelog.newline();
}
void printBlewStealthCheck(const string aname) {

	set_color_easy(YELLOW_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, aname, gamelog);
	addstrAlt(pickrandom(blew_stealth_check), gamelog);
	gamelog.newline();
}
void printActsNatural(const string aname, const int partysize) {

	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	if (partysize > 1)
		mvaddstrAlt(16, 1, CONST_stealth065, gamelog);
	else
		mvaddstrAlt(16, 1, aname, gamelog);
	addstrAlt(CONST_stealth066, gamelog);
	gamelog.newline();
}
void printEnemyNameInAlarm(const string nname) {
	clearmessagearea();
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, nname, gamelog);

}
void printLooksAtSquadSuspiciously() {
	addstrAlt(CONST_stealth068, gamelog);

}
void printShoutsInAlarm() {
	addstrAlt(CONST_stealth067, gamelog);

}
void printConservativeRaisesAlarm(const bool weapon, const int ntype, const int nalign) {
	if (weapon&&ntype != CREATURE_GUARDDOG)
	{
		addstrAlt(CONST_stealth069, gamelog);
		if (nalign == ALIGN_CONSERVATIVE)
			mvaddstrAlt(17, 1, CONST_stealth074, gamelog);
		else
			mvaddstrAlt(17, 1, CONST_stealth075, gamelog);

	}
	else
	{
		addstrAlt(CONST_stealth072, gamelog);
		if (nalign == ALIGN_CONSERVATIVE)
		{
			if (ntype == CREATURE_GUARDDOG)
				mvaddstrAlt(17, 1, CONST_stealth073, gamelog);
			else
				mvaddstrAlt(17, 1, CONST_stealth074, gamelog);
		}
		else
			mvaddstrAlt(17, 1, CONST_stealth075, gamelog);
	}
	gamelog.newline();
}
// STEALTH_CPP

// TALK_CPP
bool isPrisoner(const string tkname) {
	return strcmp(tkname.data(), unnamed_String_Talk_cpp_081.data()) == 0;
	//	const string unnamed_String_Talk_cpp_060 = "Prisoner";
}

void printTalkAboutIssuesHeader(const string aname) {
	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, aname, gamelog);
	addstrAlt(saysComma, gamelog);

}
void printTalkAboutIssuesWhenStupid(const int lw) {
	set_color_easy(GREEN_ON_BLACK_BRIGHT);

	if (lw == LAW_POLICEBEHAVIOR) {
		if (lawList[LAW_FREESPEECH] == ALIGN_ARCHCONSERVATIVE)
			mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_076, gamelog);
		else
			mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_077, gamelog);
	}
	else {
		mvaddstrAlt(10, 1, youAreStupidTalkAboutIssues[lw]);
	}
	gamelog.newline();
}
void printTalkAboutIssuesTooLiberal(const int lw) {
	set_color_easy(GREEN_ON_BLACK_BRIGHT);

	mvaddstrAlt(10, 1, issueTooLiberal[lw]);
	gamelog.newline();
}
void printTalkAboutIssuesNormal(const int lw, const int tkanimalgloss) {
	set_color_easy(GREEN_ON_BLACK_BRIGHT);

	if (lw == LAW_POLLUTION) {
		mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_078, gamelog);
		if (tkanimalgloss == ANIMALGLOSS_ANIMAL) { mvaddstrAlt(11, 1, unnamed_String_Talk_cpp_079, gamelog); }
		else { mvaddstrAlt(11, 1, unnamed_String_Talk_cpp_080, gamelog); }
	}
	else {
		mvaddstrAlt(10, 1, talkAboutTheIssues[lw][0], gamelog);
		mvaddstrAlt(11, 1, talkAboutTheIssues[lw][1], gamelog);
	}
	gamelog.newline();
}
void printTurnsAway() {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	addstrAlt(unnamed_String_Talk_cpp_093, gamelog);
	gamelog.newline();
}
void printConservativeRespondsToStupid(const int tktype, const bool extraline) {
	int y = 13 + (extraline ? 0 : 1);

	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	if (tktype == CREATURE_GANGUNIT)
		mvaddstrAlt(y, 1, unnamed_String_Talk_cpp_090, gamelog);
	else if (tktype == CREATURE_DEATHSQUAD)
		mvaddstrAlt(y, 1, unnamed_String_Talk_cpp_091, gamelog);
	else
	{
		mvaddstrAlt(y, 1, pickrandom(that_is_not_disturbing), gamelog);
	}
}
void printRespondantName(const string tkname, const bool extraline) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12 + (extraline ? 0 : 1), 1, tkname, gamelog);
	addstrAlt(respondsComma, gamelog);
}
void printConservativeCounter(const bool extraline, const int lw) {
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13 + (extraline ? 0 : 1), 1, conservativeLegalArgument[lw], gamelog);

}
void printRejectTalk(const bool extraline) {
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13 + (extraline ? 0 : 1), 1, unnamed_String_Talk_cpp_092, gamelog);

}
void printMutantTalkAboutIssues(const string tkname, const int extraline) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	int y = 12 + (extraline ? 0 : 1);
	mvaddstrAlt(y++, 1, tkname, gamelog);
	addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(y, 1, unnamed_String_Talk_cpp_089, gamelog);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	addstrAlt(unnamed_String_Talk_cpp_093, gamelog);
	gamelog.newline();
}

void printThatIsDisturbing(const string tkname, const bool extraline, const int special_case) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	int y = 12 + (extraline ? 0 : 1);
	mvaddstrAlt(y, 1, tkname, gamelog); addstrAlt(respondsComma, gamelog);
	y++;
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	switch (special_case)
	{
	case 0:
		mvaddstrAlt(y++, 1, unnamed_String_Talk_cpp_083, gamelog);
		pressAnyKey();
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		mvaddstrAlt(y, 1, unnamed_String_Talk_cpp_084, gamelog);
		break;
	case 1:
		mvaddstrAlt(y, 1, unnamed_String_Talk_cpp_085, gamelog);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		addstrAlt(unnamed_String_Talk_cpp_086, gamelog);
		break;
	default:
		mvaddstrAlt(y, 1, pickrandom(that_is_disturbing), gamelog);
		break;
	}
	gamelog.newline();
}
void printUnableToSpeakAgree(const string tkname, const bool extraline) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	int y = 12 + (extraline ? 0 : 1);
	mvaddstrAlt(y, 1, tkname, gamelog); addstrAlt(respondsComma, gamelog);
	y++;
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(y, 1, unnamed_String_Talk_cpp_082, gamelog);
	gamelog.newline();
}
void printAgreesToComeByLater(const string tkname, const bool extraline, const bool another_extraline) {

	int y = 14 + (extraline ? 0 : 1) + (another_extraline ? 1 : 0);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(y, 1, unnamed_String_Talk_cpp_087, gamelog);
	addstrAlt(tkname, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_088, gamelog);
	gamelog.newline();
}


void printSpecialRecruitment(const string aname, const string tkname, const string pitch, const string response) {
	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, aname, gamelog);
	addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(11, 1, pitch, gamelog);
	gamelog.newline();
	pressAnyKey();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, tkname, gamelog);
	addstrAlt(saysComma, gamelog);
	set_color_easy(YELLOW_ON_BLACK_BRIGHT);
	mvaddstrAlt(14, 1, response, gamelog);
	gamelog.newline();

}
void printTalkOptionsDuringCombat(const bool hostages, const bool is_cantbluff_two, const bool cop) {
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(11, 1, unnamed_String_Talk_cpp_096);
	if (!hostages)set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, unnamed_String_Talk_cpp_097);
	if (!is_cantbluff_two)set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_098);
	if (cop)set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(14, 1, unnamed_String_Talk_cpp_099);
	set_color_easy(WHITE_ON_BLACK);
	gamelog.newline();

}
void printTalksToThem(const string aname, const int tkalign, const string tkname) {

	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, aname, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_094, gamelog);
	switch (tkalign)
	{
	case ALIGN_CONSERVATIVE: set_color_easy(RED_ON_BLACK_BRIGHT); break;
	case ALIGN_LIBERAL: set_color_easy(GREEN_ON_BLACK_BRIGHT); break;
	case ALIGN_MODERATE: set_color_easy(WHITE_ON_BLACK_BRIGHT); break;
	}
	addstrAlt(tkname, gamelog);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	addstrAlt(unnamed_String_Talk_cpp_095, gamelog);
	gamelog.newline();
}
void printTheSquadIsArrested() {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(14, 1, unnamed_String_Talk_cpp_149, gamelog);
	gamelog.newline();
}

void printTheEnemyIsFooled() {

	clearmessagearea();
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_148, gamelog);
	gamelog.newline();
}
void printXeIsNotFooled(const string ename) {
	clearmessagearea();
	set_color_easy(RED_ON_BLACK_BRIGHT);

	mvaddstrAlt(16, 1, ename, gamelog);
	if (lawList[LAW_FREESPEECH] == ALIGN_ARCHCONSERVATIVE)
		addstrAlt(unnamed_String_Talk_cpp_146, gamelog);
	else addstrAlt(unnamed_String_Talk_cpp_147, gamelog);
	gamelog.newline();
}
void printITalkLikeAConservative(const string aname) {
	set_color_easy(GREEN_ON_BLACK_BRIGHT);

	mvaddstrAlt(16, 1, aname, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_142, gamelog);
	mvaddstrAlt(17, 1, unnamed_String_Talk_cpp_143, gamelog);
	gamelog.newline();
}
void printEngraveElbereth(const string aname) {
	set_color_easy(GREEN_ON_BLACK_BRIGHT);

	mvaddstrAlt(16, 1, aname, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_139, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	addstrAlt(unnamed_String_Talk_cpp_140, gamelog);     //Fanciful multicolor message
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	addstrAlt(unnamed_String_Talk_cpp_141, gamelog);
	gamelog.newline();
}
void printDeathSquadBluff() {
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_138, gamelog);
	gamelog.newline();
}

void printLabCoatBluff() {
	set_color_easy(GREEN_ON_BLACK_BRIGHT);

	mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_137, gamelog);
	gamelog.newline();
}
void printPoliceBluff() {
	set_color_easy(GREEN_ON_BLACK_BRIGHT);

	mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_134, gamelog);
	gamelog.newline();
}
void printBunkerGearBluff() {
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	if (siteonfire) mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_135, gamelog);
	else mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_136, gamelog);
	gamelog.newline();
}
void printWeWerentBornYesterday(const string ename) {
	clearmessagearea();
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_144, gamelog);
	addstrAlt(ename, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_145, gamelog);
	gamelog.newline();
}
void printSiegeBluff(const string aname, const int siegeType) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, aname, gamelog);
	addstrAlt(singleSpace, gamelog);
	switch (siegeType)
	{
	case SIEGE_POLICE:
		addstrAlt(unnamed_String_Talk_cpp_124, gamelog);
		break;
	case SIEGE_CIA:
		addstrAlt(unnamed_String_Talk_cpp_125, gamelog);
		break;
	case SIEGE_CCS:
	case SIEGE_HICKS:
		switch (LCSrandom(2))
		{
		case 0:
			addstrAlt(unnamed_String_Talk_cpp_126, gamelog);
			mvaddstrAlt(17, 1, unnamed_String_Talk_cpp_127, gamelog);
			break;
		case 1:
			addstrAlt(unnamed_String_Talk_cpp_128, gamelog);
			mvaddstrAlt(17, 1, unnamed_String_Talk_cpp_129, gamelog);
			break;
		}
		break;
	case SIEGE_CORPORATE:
		addstrAlt(unnamed_String_Talk_cpp_130, gamelog);
		break;
	case SIEGE_FIREMEN:
		addstrAlt(unnamed_String_Talk_cpp_131, gamelog);
		if ((!(levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].flag & SITEBLOCK_FIRE_END) ||
			!(levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].flag & SITEBLOCK_FIRE_PEAK) ||
			!(levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].flag & SITEBLOCK_FIRE_START) ||
			!(levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].flag & SITEBLOCK_DEBRIS)) && !LCSrandom(10))
		{
			levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].flag |= SITEBLOCK_FIRE_START;
			mvaddstrAlt(17, 1, unnamed_String_Talk_cpp_132, gamelog);
			gamelog.newline();
			mvaddstrAlt(18, 1, unnamed_String_Talk_cpp_133, gamelog);
		}
		break;
	}
}
void printEnemyIgnoresThreat(const string tkname) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	clearmessagearea();
	mvaddstrAlt(16, 1, tkname, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_123, gamelog);
	gamelog.newline();

}
void printHowShouldWeRespond(const string aname, const int hostages) {

	set_color_easy(WHITE_ON_BLACK);
	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	mvaddstrAlt(9, 1, unnamed_String_Talk_cpp_106);
	addstrAlt(aname);
	addstrAlt(unnamed_String_Talk_cpp_107);
	mvaddstrAlt(11, 1, hostages > 1 ? (unnamed_String_Talk_cpp_108) : (unnamed_String_Talk_cpp_109));
	mvaddstrAlt(12, 1, hostages > 1 ? (unnamed_String_Talk_cpp_110) : (unnamed_String_Talk_cpp_111));
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_112);
}
void printPloyWorksEnemyBacksOff() {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	clearmessagearea();
	mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_105, gamelog);
	gamelog.newline();
}
void printExecutionGunshot() {
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_113, gamelog);
	gamelog.newline();

}
void printExecutionBareHands() {
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, unnamed_String_Talk_cpp_114, gamelog);
	gamelog.newline();

}
void printDiscardsBody(const string aname, const string pname) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(17, 1, aname, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_115, gamelog);
	addstrAlt(pname, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_116, gamelog);
	gamelog.newline();
}
void printAnotherOneBacksOff(const string ename) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);

	clearmessagearea();
	mvaddstrAlt(16, 1, ename, gamelog);
	addstrAlt(singleSpace + pickrandom(backs_off), gamelog);
}
void printThreatenEnemy(const string aname) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, aname, gamelog);
	addstrAlt(colonSpace, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	switch (LCSrandom(4))
	{
	case 0:
	{   // Formatting the slogan so that it always has quotes around it and punctuation
		if (slogan_str[0] != '"') mvaddcharAlt(17, 1, '"');
		mvaddstrAlt(17, 1 + (slogan_str[0] != '"' ? 1 : 0), slogan_str, gamelog);
		const int last = len(slogan_str);
		if (last && slogan_str[last - 1] != '"' && slogan_str[last - 1] != '!' && slogan_str[last - 1] != '.' && slogan_str[last - 1] != '?')
			addcharAlt('!', gamelog);
		if (last && slogan_str[last - 1] != '"') addcharAlt('"', gamelog);
		if (!sitestory->claimed)
			sitestory->claimed = 1;
		break;
	}
	default:
		mvaddstrAlt(17, 1, pickrandom(come_at_me_bro), gamelog);
		break;
	}
}
void printHostageNegotiation(const string ename, const int etype, const int ealign, const int hostages) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	clearmessagearea();
	mvaddstrAlt(16, 1, ename, gamelog);
	addstrAlt(colonSpace, gamelog);
	if (ealign != ALIGN_CONSERVATIVE ||
		(etype == CREATURE_SECRET_SERVICE && exec[EXEC_PRESIDENT] > ALIGN_CONSERVATIVE))
	{
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		mvaddstrAlt(17, 1, pickrandom(please_spare_hostage), gamelog);
	}
	else
	{
		set_color_easy(RED_ON_BLACK_BRIGHT);
		if (((etype == CREATURE_DEATHSQUAD ||
			etype == CREATURE_AGENT ||
			etype == CREATURE_MERC ||
			etype == CREATURE_CCS_ARCHCONSERVATIVE ||
			etype == CREATURE_GANGUNIT))
			&& ealign == ALIGN_CONSERVATIVE)
		{
			mvaddstrAlt(17, 1, pickrandom(who_cares_about_hostage), gamelog);
		}
		else
		{
			string moreHostageQuestions;
			if (LCSrandom(5)) {
				moreHostageQuestions = (pickrandom(hostage_negotiation));
			}
			else {
				if (hostages > 1)
					moreHostageQuestions = (unnamed_String_Talk_cpp_103);
				else moreHostageQuestions = (unnamed_String_Talk_cpp_104);
			}
			mvaddstrAlt(17, 1, moreHostageQuestions, gamelog);
		}
	}
	gamelog.newline();
}
void printThreatenHostages(const string aname) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, aname + colonSpace, gamelog);
	{
		string anotherHostageThing;
		switch (LCSrandom(6))
		{
		case 0:anotherHostageThing = (unnamed_String_Talk_cpp_100);
			if (!sitestory->claimed)sitestory->claimed = 1; break;
		case 1:
			if (lawList[LAW_FREESPEECH] == -2)anotherHostageThing = (unnamed_String_Talk_cpp_101);
			else anotherHostageThing = (unnamed_String_Talk_cpp_102);
			break;
		default:
			anotherHostageThing = (pickrandom(threaten_hostage));
			break;
		}
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		mvaddstrAlt(17, 1, anotherHostageThing, gamelog);
	}
	gamelog.newline();
}
void printReleaseHostagesHeader(const string ename) {

	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, ename, gamelog);
	addstrAlt(colonSpace, gamelog);
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(17, 1, pickrandom(agree_to_release_hostages), gamelog);
	gamelog.newline();
}
void printReleaseHostagesFooter(const int hostages) {

	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, hostages > 1 ? unnamed_String_Talk_cpp_121 : unnamed_String_Talk_cpp_122, gamelog);
	gamelog.newline();
}
void printEnemyAllowsHostagesToDie(const string ename) {
	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, ename, gamelog);
	addstrAlt(colonSpace, gamelog);
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(17, 1, pickrandom(go_ahead_and_die), gamelog);
	gamelog.newline();
}
void printLetUsGoAndTheyGoFree(const string aname, const int hostages) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, aname, gamelog);
	addstrAlt(colonSpace, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	{
		string nameHostages;
		if (LCSrandom(5))
		{
			if (hostages > 1) nameHostages = (unnamed_String_Talk_cpp_119);
			else nameHostages = (unnamed_String_Talk_cpp_120);
		}
		else {
			nameHostages = (pickrandom(let_hostages_go));
		}
		mvaddstrAlt(17, 1, nameHostages, gamelog);
	}
	gamelog.newline();

}
void printEnemyWatchesHostageDeath(const string ename) {
	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, ename, gamelog);
	addstrAlt(colonSpace, gamelog);
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(17, 1, lawList[LAW_FREESPEECH] > ALIGN_ARCHCONSERVATIVE ? unnamed_String_Talk_cpp_117 : unnamed_String_Talk_cpp_118, gamelog);
	addstrAlt(pickrandom(please_no_more), gamelog);
	gamelog.newline();
}

void printAcceptsPickupLine(const string aname, const string tkname, const vector<string> selected_flirt) {
	const bool extraline = (selected_flirt[1] != blankString ? 1 : 0);
	int y = 12 + (extraline ? 1 : 0);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(y++, 1, tkname, gamelog); addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(y++, 1, selected_flirt[2], gamelog);
	gamelog.newline();
	pressAnyKey();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	++y;
	mvaddstrAlt(y++, 1, aname, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_069, gamelog);
	addstrAlt(tkname, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_070, gamelog);

	if (isPrisoner(tkname))
	{
		addstrAlt(unnamed_String_Talk_cpp_071, gamelog);
		mvaddstrAlt(y++, 1, tkname, gamelog);
		addstrAlt(unnamed_String_Talk_cpp_072, gamelog);
	}
	addstrAlt(unnamed_String_Talk_cpp_073, gamelog);
	gamelog.newline();
}
void printRejectsPickupLine(const string tkname, const int tktype, const int agender_liberal, const vector<string> selected_flirt) {

	const bool extraline = (selected_flirt[1] != blankString ? 1 : 0);
	int y = 12 + (extraline ? 1 : 0);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(y++, 1, tkname, gamelog);
	addstrAlt(respondsComma, gamelog);
	set_color_easy(RED_ON_BLACK_BRIGHT);
	if (tktype == CREATURE_CORPORATE_CEO)
	{
		if (agender_liberal != GENDER_MALE)
			mvaddstrAlt(y, 1, unnamed_String_Talk_cpp_074, gamelog);
		else mvaddstrAlt(y, 1, unnamed_String_Talk_cpp_075, gamelog);
	}
	else
	{
		mvaddstrAlt(y++, 1, selected_flirt[3], gamelog);
		if (selected_flirt[4] != blankString) {
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(y, 1, selected_flirt[4], gamelog);
		}
	}
	gamelog.newline();
}
void printSaysWhat(const string tkname) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tkname, gamelog);
	addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_061, gamelog);
	gamelog.newline();
}
void printTurnsAway(const string tkname, const int tkalign) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tkname, gamelog);
	addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	if (isPrisoner(tkname))
	{
		if (tkalign == ALIGN_LIBERAL)
			mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_062, gamelog);
		else mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_063, gamelog);
	}
	else mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_064, gamelog);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	addstrAlt(unnamed_String_Talk_cpp_065, gamelog);
	gamelog.newline();
}
void printRejectPolicePickupLine(const string tkname, const bool extraline) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12 + (extraline ? 1 : 0), 1, tkname, gamelog); addstrAlt(respondsComma, gamelog);
	set_color_easy(RED_ON_BLACK_BRIGHT);
	mvaddstrAlt(13 + (extraline ? 1 : 0), 1, unnamed_String_Talk_cpp_068, gamelog);
	gamelog.newline();
}
void printPickupLine(const string aname, const vector<string> selected_flirt) {

	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, aname, gamelog); addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, selected_flirt[0], gamelog);
	if (selected_flirt[1] != blankString) {
		mvaddstrAlt(11, 1, selected_flirt[1], gamelog);
	}
	gamelog.newline();
}
void printNonHumanRejection(const string tkname, const int tktype, const bool extraline) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12 + (extraline ? 1 : 0), 1, tkname, gamelog);
	switch (tktype)
	{
	case CREATURE_TANK:
		addstrAlt(unnamed_String_Talk_cpp_066, gamelog);
		break;
	case CREATURE_GUARDDOG:
		addstrAlt(saysComma, gamelog);
		set_color_easy(RED_ON_BLACK_BRIGHT);
		mvaddstrAlt(13 + (extraline ? 1 : 0), 1, pickrandom(dog_rejection), gamelog);
		break;
	case CREATURE_GENETIC:
		addstrAlt(saysComma, gamelog);
		set_color_easy(RED_ON_BLACK_BRIGHT);
		mvaddstrAlt(13 + (extraline ? 1 : 0), 1, pickrandom(mutant_rejection), gamelog);
		break;
	default:
		addstrAlt(unnamed_String_Talk_cpp_067, gamelog);
	}
	gamelog.newline();
}
void printAnimalDoesntUnderstand(const string tkname, const int tktype) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tkname, gamelog);
	switch (tktype)
	{
	case CREATURE_TANK: addstrAlt(unnamed_String_Talk_cpp_057, gamelog); break;
	case CREATURE_GUARDDOG: addstrAlt(unnamed_String_Talk_cpp_058, gamelog); break;
	default: addstrAlt(unnamed_String_Talk_cpp_059, gamelog); break;
	}
	gamelog.newline();
}
void printWannaHearSomething(const string aname) {
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, aname, gamelog); addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_056, gamelog);
	gamelog.newline();
}
void printLetMeSellYouAGun(const string tkname) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tkname, gamelog); addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_054, gamelog);
	gamelog.newline();
}
void printNotHereDummy(const string tkname) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tkname, gamelog); addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_055, gamelog);
	gamelog.newline();

}
void printWaitUntilItCoolsDown(const string tkname) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tkname, gamelog); addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_053, gamelog);
	gamelog.newline();

}
void printIDontSellToCops(const string tkname) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tkname, gamelog); addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_052, gamelog);
	gamelog.newline();
}
void printIDontSellToNaked(const string tkname) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tkname, gamelog); addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_051, gamelog);
	gamelog.newline();
}
void printINeedAGun(const string aname) {

	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, aname, gamelog); addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_050, gamelog);
	gamelog.newline();
}
void printJesusItsYours(const string tkname) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tkname, gamelog); addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_049, gamelog);
	gamelog.newline();
}
void printIWantYouToLeave(const string tkname) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tkname, gamelog); addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_047, gamelog);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	addstrAlt(unnamed_String_Talk_cpp_048, gamelog);
	gamelog.newline();
}
void printGiveMeTheLCSPrice(const string aname) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, aname, gamelog);
	addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_046, gamelog);
	gamelog.newline();
}
void printThreatensWithAGun(const string aname, const string aweapon) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, aname, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_045, gamelog);
	addstrAlt(aweapon, gamelog);
	addstrAlt(singleDot, gamelog);
	gamelog.newline();

}
void printRefuseRentDeal(const string aname) {

	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, aname, gamelog); addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_042, gamelog);
	gamelog.newline();
}
void printNotMyProblem(const string tkname) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tkname, gamelog); addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_043, gamelog);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	addstrAlt(unnamed_String_Talk_cpp_044, gamelog);
	gamelog.newline();
}
void printAcceptRentHeader(const string aname) {

	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, aname, gamelog); addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_038, gamelog);
	gamelog.newline();
}
void printAcceptRentFooter(const string tkname) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tkname, gamelog); addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_039, gamelog);
	gamelog.newline();
	mvaddstrAlt(14, 1, unnamed_String_Talk_cpp_040, gamelog);
	gamelog.newline();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	addstrAlt(unnamed_String_Talk_cpp_041);

}
void printRentingOptions(const bool cannotAfford) {

	if (cannotAfford) {
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
	}
	mvaddstrAlt(11, 1, unnamed_String_Talk_cpp_035);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(12, 1, unnamed_String_Talk_cpp_036);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_037);
}
void printINeedThisMuchRent(const string tkname, const int rent) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tkname, gamelog);
	addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_031, gamelog);
	addstrAlt(rent, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_032, gamelog);
	gamelog.newline();
	mvaddstrAlt(14, 1, unnamed_String_Talk_cpp_033, gamelog);
	addstrAlt(rent, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_034, gamelog);
	gamelog.newline();
}
void printPutSomeDamnClothesOn(const string tkname) {
	//const string unnamed_String_Talk_cpp_026 = "\"Put some clothes on before I call the cops.\"";
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tkname, gamelog);
	addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_030, gamelog);
	gamelog.newline();
}
void printIWantToRent(const string aname) {
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, aname, gamelog);
	addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_029, gamelog);
	gamelog.newline();
}
void printClearOutYourRoom(const string tkname) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, tkname, gamelog);
	addstrAlt(respondsComma, gamelog);
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_027, gamelog);
	gamelog.newline();
}
void printYourPossessionsAreRelocated() {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(15, 1, unnamed_String_Talk_cpp_028, gamelog);
	gamelog.newline();
}
void printIWantToCancelRent(const string aname) {

	clearcommandarea();
	clearmessagearea();
	clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, aname, gamelog);
	addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_025, gamelog);
	gamelog.newline();
}
void printTalkToPotentialLandlord(const bool is_naked) {
	mvaddstrAlt(14, 1, unnamed_String_Talk_cpp_021);
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
}
void printTalkToLandlord(const bool is_naked) {
	mvaddstrAlt(14, 1, unnamed_String_Talk_cpp_022);
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
}
void printTalkToGangMemberOrMerc(const bool is_naked) {
	mvaddstrAlt(14, 1, unnamed_String_Talk_cpp_023);
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
}
void printTalkToBankTeller(const bool is_naked) {
	mvaddstrAlt(14, 1, unnamed_String_Talk_cpp_024);
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
}
void printTalkToHeader(const string aname) {
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, aname);
	addstrAlt(unnamed_String_Talk_cpp_016);

}
void printTalkToMiddle(const int tkalign, const string tkname, const string tkbio) {
	switch (tkalign)
	{
	case ALIGN_CONSERVATIVE:
		set_color_easy(RED_ON_BLACK_BRIGHT);
		break;
	case ALIGN_LIBERAL:
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		break;
	case ALIGN_MODERATE:
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		break;
	}
	addstrAlt(tkname);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	addstrAlt(tkbio);
	addstrAlt(unnamed_String_Talk_cpp_017);
}
void printTalkToFooter(const bool is_naked, const bool can_date) {

	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(11, 1, unnamed_String_Talk_cpp_018);

	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
	if (can_date)set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(12, 1, unnamed_String_Talk_cpp_019);
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_020);
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);

}
void printBankerCooperates() {
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, unnamed_String_Talk_cpp_014, gamelog);
	gamelog.newline();
}
void printTheVaultIsOpen() {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_015, gamelog);
	gamelog.newline();

}
void printGuardsCloseIn() {
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, unnamed_String_Talk_cpp_012, gamelog);
	mvaddstrAlt(10, 1, unnamed_String_Talk_cpp_013, gamelog);
	gamelog.newline();
}
void printDemandVaultBeOpened(const string aname) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, aname, gamelog);
	addstrAlt(saysComma, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(11, 1, unnamed_String_Talk_cpp_010, gamelog);
	addstrAlt(slogan_str, gamelog);
	gamelog.record(singleSpace);
	mvaddstrAlt(12, 1, unnamed_String_Talk_cpp_011, gamelog);
	gamelog.newline();

}
void printBrandishWeapon(const string aname, const string aweapon) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);

	mvaddstrAlt(9, 1, aname, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_009, gamelog);
	addstrAlt(aweapon, gamelog);
	addstrAlt(singleDot, gamelog);
	gamelog.newline();
}
void printTellerComplies() {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(11, 1, unnamed_String_Talk_cpp_007, gamelog);
	addstrAlt(pickrandom(teller_complies), gamelog);
	mvaddstrAlt(12, 1, unnamed_String_Talk_cpp_008, gamelog);
	gamelog.newline();
}
void printTellerAlertsCops() {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(11, 1, unnamed_String_Talk_cpp_005, gamelog);
	addstrAlt(pickrandom(teller_gestures), gamelog);
	mvaddstrAlt(12, 1, unnamed_String_Talk_cpp_006, gamelog);
	gamelog.newline();
}
void printIRobTheBank(const string aname) {
	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 1, aname, gamelog);
	addstrAlt(unnamed_String_Talk_cpp_004, gamelog);
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 1, pickrandom(robbing_bank), gamelog);
	gamelog.newline();
}
void printOptionsWithinBank(const bool is_naked) {

	clearcommandarea(); clearmessagearea(); clearmaparea();
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(11, 1, unnamed_String_Talk_cpp_001);
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
	mvaddstrAlt(12, 1, unnamed_String_Talk_cpp_002);
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
	mvaddstrAlt(13, 1, unnamed_String_Talk_cpp_003);
	if (is_naked)addstrAlt(while_naked);
	addstrAlt(singleDot);
}


// end TALK_CPP


// TITLESCREEN_CPP
void printSaveHeader(const bool to_delete) {
	eraseAlt();
	set_color_easy(to_delete ? YELLOW_ON_RED : WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(0, 0, to_delete ? deleteSave : chooseSave);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(1, 0, titleScreenLine);
}
void printSaveList(const int page, const vector<string> s_savefiles) {
	int y = 2;
	for (int p = page * 19; p < s_savefiles.size() && p < page * 19 + 19; p++, y++)
	{
		mvaddchAlt(y, 0, y + 'A' - 2);
		addstrAlt(spaceDashSpace);
		const string &strtemp = s_savefiles[p];
		addstrAlt(strtemp.substr(0, strtemp.find(dotDat)));
	}
	mvaddstrAlt(y, 0, (char(y + 'A' - 2)) + spaceDashSpace + newGame);

}
void printSaveFooter(const bool to_delete) {
	mvaddstrAlt(22, 0, (to_delete ? pressToDeleteSave : pressToSelectSave) + vToSwitchXToQuit);
	mvaddstrAlt(23, 0, addpagestr());

}
void printAreYouSure(const string s_savefiles) {

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrCenter(10, areYouSureDelte + s_savefiles + questionYSlashN);
}
void printMusicFooter(const bool musicEnabled) {

	string str;
	if (musicEnabled) {
		(str = pressMtoTurnOffMusic);
	}
	else {
		(str = pressMtoTurnOnMusic);
	}
	mvaddstrCenter(22, str);
}

void printTitleScreen() {
	//title screen
	eraseAlt();
	set_color_easy(GREEN_ON_BLACK_BRIGHT);
	mvaddstrCenter(2, liberalCrimeSquad);
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrCenter(4, inspiredByOubliette);
	vector<string> quote = pickrandom(real_quote);
	mvaddstrCenter(6, quote[0]);
	mvaddstrCenter(7, quote[1]);
	mvaddstrCenter(8, quote[2]);
	mvaddstrCenter(9, quote[3]);
	mvaddstrCenter(11, copyrightTarn);
	mvaddstrCenter(12, bayTwelveProductions);
	mvaddstrCenter(13, lcsHyperlink);
	mvaddstrCenter(15, vChar + PACKAGE_VERSION_STR + maintainedByOpenSource);
	mvaddstrCenter(16, kingDrakeHyperlink);
	mvaddstrCenter(17, lcsForumHyperlink);
	mvaddstrCenter(18, lcsWikiHyperlink);
	mvaddstrCenter(20, pressESCToQuit);
	mvaddstrCenter(22, pressAnyKeyToPursue);
	mvaddstrAlt(24, 79, plusChar);
}

string printNewGameHeader() {
	char savefile_temp[SAVE_FILE_NAMELEN];
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(0, 0, inWhatWorld);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(1, 0, enterNameForSave);

	enter_name(2, 0, savefile_temp, SAVE_FILE_NAMELEN, NULL);
	bool justEnter = false;
	bool enterDamn = false;
	do {
		if (strcmp(savefile_temp, blankString.c_str()) == 0) {
			eraseAlt();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(0, 0, inWhatWorld);
			string enterTheName;
			if (enterDamn) {
				enterTheName = justEnterName;
			}
			else if (justEnter) {
				enterTheName = prettyPlease;
				enterDamn = true;
			}
			else {
				enterTheName = pleaseEnterName;
			}
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(1, 0, enterTheName);
			enter_name(2, 0, savefile_temp, SAVE_FILE_NAMELEN, blankString.c_str());
			justEnter = true;
		}
		else {
			justEnter = false;
		}
	} while (justEnter);
	return savefile_temp + dotDat;
}
// end TITLESCREEN_CPP