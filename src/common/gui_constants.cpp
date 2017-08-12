

#include <includes.h>
#include <externs.h>
#include "common\\gui_constants.h"
int		mvaddstr_const(MOVE_CONSTANT movement, const char *string) {
	return mvaddstr(movement.y, movement.x, string);
}
int move_const(MOVE_CONSTANT movement){
	return move(movement.y, movement.x);
}
int center_string(const char* str);
int center_string(const char* str) {
	return 39 - ((len(str) - 1) >> 1);
}
int move_center_string(int x, const char* str) {
	return mvaddstr(x, center_string(str), str);
}

#include "common\\set_color_support.h"

void set_color_easy(ColorSetup color) {
	set_color(color.letter, color.background, color.bright, color.blink);
}
string burstToString(int bursthits) {
	switch (bursthits) {
			case 2: return " twice";
			case 3: return " three times";
			case 4: return " four times";
			case 5: return  " five times";
			default: return " " + tostring(bursthits) + " times";
	}
}
string qualifiedFailure(int droll, string name, vector<string> stringCollection) {
	return name + qualifiedFailure(droll, stringCollection);
}

string qualifiedFailure(int droll, vector<string> stringCollection) {
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