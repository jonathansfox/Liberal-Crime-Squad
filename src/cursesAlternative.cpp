
#include <includes.h>

#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
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
int		mvaddstrAlt(const int x, const int y, const string z) { return mvaddstr(x, y, z.data()); }
int		mvaddstrAlt(const int x, const int y, const char* z) { return mvaddstr(x, y, z); }
//int		mvaddstrAlt(const int x, const int y, const char* z) { return mvaddstr(x, y, z); }
//int addstrAlt(const char* x, Log y) { return addstr(x,y); }
//int addstrAlt(const string x) { return addstr(x); }
int addstrAlt(const char *text) { return addstr(text); }
int addstrAlt(const char *text, Log &log) { log.record(text); return addstr(text); }
int addstrAlt(const string &text) { int ret = ERR; for (int i = 0; i<strlen(text.data()); i++) ret = addcharAlt(text[i]); return ret; }
int addstrAlt(const string &text, Log &log){ log.record(text); return addstr(text.data()); }
int addstrAlt(const long num) { return addstr(tostring(num).data()); }
int addstrAlt(const long num, Log &log) { return addstrAlt(tostring(num).data(), log); }
int		 mvaddstrAlt(const int x, const  int y, const int z) { return mvaddstr(x, y, tostring(z).data()); }
int		 mvaddstrAlt(const int x, const int y, const string z, Log &a) {
	a.record(z);
	return mvaddstr(x, y, z.data());
}
int		 mvaddstrAlt(const int x, const int y, const char* z, Log &a) {
	a.record( z);
	return mvaddstr(x, y, z);
}
int		 mvaddstrAlt(const int x, const int y, const  int z, Log &a){
	a.record(tostring(z));
	return mvaddstr(x, y, tostring(z).data());
}
//#include "includesAlt06Primatives.h"
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
	case 2: return " twice";
	case 3: return " three times";
	case 4: return " four times";
	case 5: return  " five times";
	default: return singleSpace + tostring(bursthits) + " times";
	}
}
string qualifiedFailure(const int droll, const string name, vector<string> stringCollection) {
	return name + qualifiedFailure(droll, stringCollection);
}
string qualifiedFailure(const int droll, vector<string> stringCollection) {
	if (stringCollection.size() == 0) {
		return "";
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
const ColorSetup 	BLACK_ON_BLACK = { COLOR_BLACK, COLOR_BLACK };
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
const ColorSetup WHITE_ON_WHITE = { COLOR_WHITE, COLOR_WHITE };
const ColorSetup WHITE_ON_WHITE_BRIGHT = { COLOR_WHITE, COLOR_WHITE, 1 };
const ColorSetup YELLOW_ON_BLACK = { COLOR_YELLOW, COLOR_BLACK };
const ColorSetup YELLOW_ON_BLACK_BRIGHT = { COLOR_YELLOW, COLOR_BLACK, 1 };
const ColorSetup YELLOW_ON_RED = { COLOR_YELLOW, COLOR_RED };
const ColorSetup YELLOW_ON_RED_BRIGHT = { COLOR_YELLOW, COLOR_RED, 1 };
const ColorSetup YELLOW_ON_RED_BRIGHT_BLINK = { COLOR_YELLOW, COLOR_RED, 1, 1 };
void displayDifficulty(int difficulty)
{
	const char *_difficulty[] = { "Simple", "Very Easy", "Easy", "Below Average", "Average", "Above Average", "Hard", "Very Hard", "Extremely Difficult", "Nearly Impossible", "Impossible" };
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
	/*
	switch (difficulty)
	{
	case 0:	set_color(COLOR_GREEN, COLOR_BLACK, 1); break;
	case 1: set_color(COLOR_CYAN, COLOR_BLACK, 1); break;
	case 2: set_color(COLOR_CYAN, COLOR_BLACK, 0); break;
	case 3: set_color(COLOR_BLUE, COLOR_BLACK, 1); break;
	case 4: set_color(COLOR_WHITE, COLOR_BLACK, 1); break;
	case 5: set_color(COLOR_WHITE, COLOR_BLACK, 0); break;
	case 6: set_color(COLOR_YELLOW, COLOR_BLACK, 1); break;
	case 7: set_color(COLOR_MAGENTA, COLOR_BLACK, 0); break;
	case 8: set_color(COLOR_MAGENTA, COLOR_BLACK, 1); break;
	case 9: set_color(COLOR_RED, COLOR_BLACK, 0);	break;
	default:set_color(COLOR_RED, COLOR_BLACK, 1);	break;
	}*/
	if (difficulty >= 0 && difficulty < 10) addstrAlt(_difficulty[difficulty]); else addstrAlt(_difficulty[10]);
}
// IsaacG Various functions that are the single time
// a given aspect of the curses library is used
/*
This function prints the cash the player has with optional prefix as
well as screen coordinates.
Please note that offsetx is the offset from the right of the screen, y is
the offset from the top as always.
*/
void printfunds(int y, int offsetx, const char* prefix, long funds);
void printfunds(int y, int offsetx, const char* prefix, long funds)
{
	char moneystr[50], prefixbuffer[50];
	if (prefix == NULL)
		strncpy(prefixbuffer, "", 50);
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
	moveAlt(y, 80 - strlen(moneystr) - strlen(prefixbuffer) - offsetx);
	addstrAlt(prefixbuffer);
	addstrAlt(moneystr);
	//Recover old settings
	moveAlt(begy, begx);
	set_color(front, back, dim);
}
int     moveSixteenOne() {
	return moveAlt(16, 1);
}
int     moveSeventeenOne() {
	return moveAlt(17, 1);
}
int     moveZeroZero() {
	return moveAlt(0, 0);
}
int     moveOneZero() {
	return moveAlt(1, 0);
}