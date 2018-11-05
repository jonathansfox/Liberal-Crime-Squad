#include "includes.h"
const string CONST_cursesAlternative013 = "]";
const string CONST_cursesAlternative011 = "[";
const string CONST_cursesAlternative008 = " times";
const string CONST_cursesAlternative007 = " five times";
const string CONST_cursesAlternative006 = " four times";
const string CONST_cursesAlternative005 = " three times";
const string CONST_cursesAlternative004 = " twice";

const string blankString = "";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
//#include "../creature/newcreature.h"

#include "vehicle/vehicleType.h"///
#include "vehicle/vehicle.h"///
#include "../creature/creature.h"
////

#include "../creature/deprecatedCreatureC.h"

////
#include "../common/getnames.h"

#include "../locations/locations.h"
#include "../pdcurses/curses.h"
#include "../log/log.h"
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include <gui_constants.h>


short interface_pgup = '[';
short interface_pgdn = ']';
bool is_page_up(const int c) {
	return c == interface_pgup || c == KEY_UP || c == KEY_LEFT;
}
bool is_page_down(const int c) {
	return c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT;
}
void translategetch(int &c);
void translategetch_cap(int &c);
/* Refreshes the screen, empties the keyboard buffer, waits for a new key to be pressed, and returns the key pressed */
int getkey();
/* Variant of getkeyAlt() that doesn't make all letters lowercase */
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
extern string singleSpace;
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
void displayDifficulty(int difficulty)
{
	const pair<ColorSetup, string> _difficulties[] = { 
		make_pair(GREEN_ON_BLACK_BRIGHT, "Simple"),
		make_pair(CYAN_ON_BLACK_BRIGHT, "Very Easy"),
		make_pair(CYAN_ON_BLACK, "Easy"),
		make_pair(BLUE_ON_BLACK_BRIGHT, "Below Average"),
		make_pair(WHITE_ON_BLACK_BRIGHT, "Average"),
		make_pair(WHITE_ON_BLACK, "Above Average"),
		make_pair(YELLOW_ON_BLACK_BRIGHT, "Hard"),
		make_pair(MAGENTA_ON_BLACK, "Very Hard"),
		make_pair(MAGENTA_ON_BLACK_BRIGHT, "Extremely Difficult"),
		make_pair(RED_ON_BLACK, "Nearly Impossible"),
		make_pair(RED_ON_BLACK_BRIGHT, "Impossible") 
	};
	if (difficulty >= 0 && difficulty < 10) {
		set_color_easy(_difficulties[difficulty].first);
		addstrAlt(_difficulties[difficulty].second);
	}
	else {
		set_color_easy(_difficulties[10].first);
		addstrAlt(_difficulties[10].second);
	}
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
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
void printfunds(int y, int offsetx, const char* prefix)
{
	extern class Ledger ledger;
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
#include "../locations/locationsPool.h"
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
//const string blankString = "";
const string tag_MONEY = "MONEY";
const string tag_CEO = "CEO";
void printchaseencounter();
bool isThereGroundLoot();
// Imperfect but quick and dirty line of sight check
// Only works if the target point is at most two spaces
// away in any direction
bool LineOfSight(int x, int y, int z)
{
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
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
vector<NameAndAlignment> getEncounterNameAndAlignment();
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
void checkForDirectionalVisibility(bool(&visible)[8], const int x, const int y) {

	extern coordinatest loc_coord;
	//extern siteblockst levelmap[MAPX][MAPY][MAPZ];

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

	//extern siteblockst levelmap[MAPX][MAPY][MAPZ];


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

	extern siteblockst levelmap[MAPX][MAPY][MAPZ];

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

	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
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
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
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
// Prints the map graphics in the bottom right of the screen
void printsitemap(int x, int y, int z)
{
	extern bool mapshowing;
	extern coordinatest loc_coord;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
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

	if (levelmap[loc_coord.locx][loc_coord.locy][loc_coord.locz].special != SPECIAL_NONE)
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
	extern bool mapshowing;
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
	extern short mode;
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	for (int y = 9; y < 16; y++)
		mvaddstrAlt(y, 0, CONST_sitedisplay102); // 53 spaces
	if (mode != GAMEMODE_SITE) clearmaparea(false, true);
}
void refreshmaparea()
{
	extern short mode;
	extern coordinatest loc_coord;
	if (mode == GAMEMODE_SITE) printsitemap(loc_coord.locx, loc_coord.locy, loc_coord.locz);
	else clearmaparea(true, false);
}
void clearmessagearea(bool redrawmaparea)
{
	extern short mode;
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
int monthday();
/* news - show major news story */
void preparepage(const Deprecatednewsstoryst ns, const bool liberalguardian)
{
	extern string commaSpace;
	extern int day;
	extern int month;
	extern int year;
	extern unsigned char newstops[6][80][5][4];
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
	extern unsigned char bigletters[27][5][7][4];
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
	extern unsigned char newspic[20][78][18][4];
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

#define CH_BOX_DRAWINGS_LIGHT_VERTICAL 0xb3
#define CH_UPPER_HALF_BLOCK 0xdf
#define CH_LOWER_HALF_BLOCK 0xdc
#define CH_BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL 0xc5
#define CH_FULL_BLOCK 0xdb
#define CH_LIGHT_SHADE 0xb0
#define CH_MEDIUM_SHADE 0xb1
#define CH_DARK_SHADE 0xb2
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

void printFlag() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 18; j++) {
			set_color_easy(AmericanFlag[i][j].first);
			mvaddchAlt(i + 10, j + 31, AmericanFlag[i][j].second);
		}
	}
}
/* base - burn the flag */
void burnflag()
{
	int flagparts = 126;
	std::pair<ColorSetup, int> flag[18][7];
	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 18; x++) {
			flag[x][y] = AmericanFlag[y][x];
		}
	}
	int x1 = LCSrandom(18);
	int y1 = LCSrandom(7);
	flag[x1][y1] = std::pair<ColorSetup, int>(YELLOW_ON_BLACK_BRIGHT, CH_DARK_SHADE);
	bool first = true;
	while (flagparts > 0)
	{
		if (!first) for (int x = 0; x < 18; x++) for (int y = 0; y < 7; y++)
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
		for (int x = 0; x < 18; x++) for (int y = 0; y < 7; y++)
		{
			set_color_easy(flag[x][y].first);
			mvaddchAlt(y + 10, x + 31, flag[x][y].second);
		}

		pause_ms(10);

		bool gotnew = false;
		while (!gotnew&&flagparts > 3)
		{
			int x = LCSrandom(18);
			int y = LCSrandom(7);

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
	extern bool fixcleartype;
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
	extern bool fixcleartype;
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