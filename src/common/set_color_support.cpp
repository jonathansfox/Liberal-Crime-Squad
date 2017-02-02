#include "curses.h"
#include <externs.h>
#include "common\\set_color_support.h"

void set_color_easy(ColorSetup color) {
		switch (color) {
		case BLACK_ON_BLACK:
			set_color(COLOR_BLACK, COLOR_BLACK, 0);
			break;
		case		BLACK_ON_BLACK_BRIGHT:
			set_color(COLOR_BLACK, COLOR_BLACK, 1);
			break;
		case		BLACK_ON_WHITE:
			set_color(COLOR_BLACK, COLOR_WHITE, 0);
			break;
		case		BLUE_ON_BLACK_BRIGHT:
			set_color(COLOR_BLUE, COLOR_BLACK, 1);
			break;
		case		CYAN_ON_BLACK:
			set_color(COLOR_CYAN, COLOR_BLACK, 0);
			break;
		case		CYAN_ON_BLACK_BRIGHT:
			set_color(COLOR_CYAN, COLOR_BLACK, 1);
			break;
		case		GREEN_ON_BLACK:
			set_color(COLOR_GREEN, COLOR_BLACK, 0);
			break;
		case		GREEN_ON_BLACK_BRIGHT:
			set_color(COLOR_GREEN, COLOR_BLACK, 1);
			break;
		case		MAGENTA_ON_BLACK:
			set_color(COLOR_MAGENTA, COLOR_BLACK, 0);
			break;
		case		MAGENTA_ON_BLACK_BRIGHT:
			set_color(COLOR_MAGENTA, COLOR_BLACK, 1);
			break;
		case		RED_ON_BLACK:
			set_color(COLOR_RED, COLOR_BLACK, 0);
			break;
		case		RED_ON_BLACK_BRIGHT:
			set_color(COLOR_RED, COLOR_BLACK, 1);
			break;
		case		RED_ON_BLUE_BRIGHT:
			set_color(COLOR_RED, COLOR_BLUE, 1);
			break;
		case			RED_ON_GREEN_BRIGHT:
			set_color(COLOR_RED, COLOR_GREEN, 1);
			break;
		case			RED_ON_RED:
			set_color(COLOR_RED, COLOR_RED, 0);
			break;
		case		WHITE_ON_BLACK:
			set_color(COLOR_WHITE, COLOR_BLACK, 0);
			break;
		case		WHITE_ON_BLACK_BRIGHT:
			set_color(COLOR_WHITE, COLOR_BLACK, 1);
			break;
		case		WHITE_ON_RED_BRIGHT:
			set_color(COLOR_WHITE, COLOR_RED, 1);
			break;
		case		WHITE_ON_WHITE:
			set_color(COLOR_WHITE, COLOR_WHITE, 0);
			break;
		case		WHITE_ON_WHITE_BRIGHT:
			set_color(COLOR_WHITE, COLOR_WHITE, 1);
			break;
		case		YELLOW_ON_BLACK:
			set_color(COLOR_YELLOW, COLOR_BLACK, 0);
			break;
		case		YELLOW_ON_BLACK_BRIGHT:
			set_color(COLOR_YELLOW, COLOR_BLACK, 1);
			break;
		case		YELLOW_ON_RED:
			set_color(COLOR_YELLOW, COLOR_RED, 1);
			break;
		case		YELLOW_ON_RED_BRIGHT_BLINK:
			set_color(COLOR_YELLOW, COLOR_RED, 1, 1);
			break;
		}
}