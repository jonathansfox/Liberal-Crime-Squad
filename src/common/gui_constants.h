#pragma once
struct MOVE_CONSTANT {
	int y;
	int x;
};
const MOVE_CONSTANT top_fight_window = { 16, 1 };
const MOVE_CONSTANT top_fight_window_line_two = { 17, 1 };
const MOVE_CONSTANT top_left_corner = { 0, 0 };
const MOVE_CONSTANT top_left_corner_line_two = { 1, 0 };
const MOVE_CONSTANT bottom_right_corner = { 24, 79 };
int     move_const(MOVE_CONSTANT);
int		mvaddstr_const(MOVE_CONSTANT, const char *);
int move_center_string(int, const char*);
string burstToString(int);
string qualifiedFailure(int, string, vector<string>);
string qualifiedFailure(int, vector<string>);