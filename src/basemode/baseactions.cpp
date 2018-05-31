#include "../includes.h"
const string CONST_baseactions004 = "vehicleParagraph.txt";
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

const string blankString = "";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
#include "../creature/creature.h"
//#include "../cursesgraphics.h"
#define CH_BOX_DRAWINGS_LIGHT_VERTICAL 0xb3
#define CH_UPPER_HALF_BLOCK 0xdf
#define CH_LOWER_HALF_BLOCK 0xdc
#define CH_BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL 0xc5
#define CH_FULL_BLOCK 0xdb
#define CH_LIGHT_SHADE 0xb0
#define CH_MEDIUM_SHADE 0xb1
#define CH_DARK_SHADE 0xb2
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../common/consolesupport.h"
//#include "../common/getnames.h"
void enter_name(int, int, char*, int, const char*);
//#include "../common/commonactionsCreature.h"
int squadsize(const squadst *st);
#include "../common/commondisplay.h"
// for void printparty(void)
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/creaturePool.h"
extern string singleSpace;
string enter_done;
string spaceDashSpace;
 string chooseALiberalTo;
 string string_sleeper;
 vector<string> vehicleParagraph;
 const string mostlyendings = "mostlyendings\\";
 vector<file_and_text_collection> baseactions_text_file_collection = {
	 customText(&vehicleParagraph, mostlyendings + CONST_baseactions004),
 };
/* base - burn the flag */
void burnflag()
{
	int flagparts = 126, flag[18][7][4];
	for (int y = 0; y < 7; y++) if (y < 6) for (int x = 0; x < 18; x++)
	{
		if (x < 9 && y < 4)
		{
			switch (y)
			{
			case 0: flag[x][y][0] = ((x % 2) ? '.' : ':'); break;
			default: flag[x][y][0] = ':'; break;
			case 3: flag[x][y][0] = CH_LOWER_HALF_BLOCK; break;
			}
			flag[x][y][2] = COLOR_BLUE;
		}
		else
		{
			flag[x][y][0] = CH_LOWER_HALF_BLOCK;
			flag[x][y][2] = COLOR_RED;
		}
		flag[x][y][1] = COLOR_WHITE;
		flag[x][y][3] = 1;
	}
	else for (int x = 0; x < 18; x++)
	{
		flag[x][y][0] = CH_UPPER_HALF_BLOCK;
		flag[x][y][1] = COLOR_RED;
		flag[x][y][2] = COLOR_BLACK;
		flag[x][y][3] = 0;
	}
	int x1 = LCSrandom(18);
	int y1 = LCSrandom(7);
	flag[x1][y1][0] = CH_DARK_SHADE;
	flag[x1][y1][1] = COLOR_YELLOW;
	flag[x1][y1][2] = COLOR_BLACK;
	flag[x1][y1][3] = 1;
	bool first = true;
	while (flagparts > 0)
	{
		if (!first) for (int x = 0; x < 18; x++) for (int y = 0; y < 7; y++)
		{
			if (flag[x][y][0] == CH_BOX_DRAWINGS_LIGHT_VERTICAL)flag[x][y][0] = CH_DARK_SHADE;
			else if (flag[x][y][0] == CH_DARK_SHADE)
			{
				flag[x][y][0] = CH_MEDIUM_SHADE;
				flag[x][y][1] = COLOR_RED;
				flag[x][y][2] = COLOR_BLACK;
				flag[x][y][3] = 0;
			}
			else if (flag[x][y][0] == CH_MEDIUM_SHADE)
			{
				flag[x][y][0] = CH_LIGHT_SHADE;
				flag[x][y][1] = COLOR_BLACK;
				flag[x][y][2] = COLOR_BLACK;
				flag[x][y][3] = 1;
			}
			else if (flag[x][y][0] == CH_LIGHT_SHADE)
			{
				flagparts--;
				flag[x][y][0] = ' ';
				flag[x][y][1] = COLOR_BLACK;
				flag[x][y][2] = COLOR_BLACK;
				flag[x][y][3] = 0;
			}
		}
		else first = false;
		for (int x = 0; x < 18; x++) for (int y = 0; y < 7; y++)
		{
			set_color(short(flag[x][y][1]), short(flag[x][y][2]), bool(flag[x][y][3]));
			mvaddchAlt(y + 10, x + 31, flag[x][y][0]);
		}
		pause_ms(10);
		bool gotnew = false;
		while (!gotnew&&flagparts > 3)
		{
			int x = LCSrandom(18);
			int y = LCSrandom(7);
			
			if (flag[x][y][0] == ':' || flag[x][y][0] == '.' || flag[x][y][0] == CH_UPPER_HALF_BLOCK || flag[x][y][0] == CH_LOWER_HALF_BLOCK)
			{
				bool conf = false;
				if (x > 0)
				{
					if (flag[x - 1][y][0] != ':'&&
						flag[x - 1][y][0] != '.'&&
						flag[x - 1][y][0] != CH_UPPER_HALF_BLOCK&&
						flag[x - 1][y][0] != CH_LOWER_HALF_BLOCK) conf = true;
				}
				if (x < 17)
				{
					if (flag[x + 1][y][0] != ':'&&
						flag[x + 1][y][0] != '.'&&
						flag[x + 1][y][0] != CH_UPPER_HALF_BLOCK&&
						flag[x + 1][y][0] != CH_LOWER_HALF_BLOCK) conf = true;
				}
				if (y > 0)
				{
					if (flag[x][y - 1][0] != ':'&&
						flag[x][y - 1][0] != '.'&&
						flag[x][y - 1][0] != CH_UPPER_HALF_BLOCK&&
						flag[x][y - 1][0] != CH_LOWER_HALF_BLOCK) conf = true;
				}
				if (y < 6)
				{
					if (flag[x][y + 1][0] != ':'&&
						flag[x][y + 1][0] != '.'&&
						flag[x][y + 1][0] != CH_UPPER_HALF_BLOCK&&
						flag[x][y + 1][0] != CH_LOWER_HALF_BLOCK) conf = true;
				}
				if (conf)
				{
					flag[x][y][0] = CH_BOX_DRAWINGS_LIGHT_VERTICAL;
					flag[x][y][1] = COLOR_YELLOW;
					flag[x][y][2] = COLOR_BLACK;
					flag[x][y][3] = 1;
					gotnew = true;
				}
			}
		}
	}
}
/* base - new slogan */
void getslogan()
{
	const string CONST_baseactions006 = "                                                                                          ";
	const string CONST_baseactions005 = "What is your new slogan?";
	extern char slogan[SLOGAN_LEN];
	extern vector<string> default_slogans;
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(16, 0, CONST_baseactions005);
	mvaddstrAlt(17, 0, CONST_baseactions006); // 80 spaces
	enter_name(17, 0, slogan, SLOGAN_LEN, pickrandom(default_slogans).c_str());
}
/* base - reorder party */
void orderparty()
{
	const string CONST_baseactions009 = " in Spot ";
	const string CONST_baseactions008 = "Choose squad member to replace ";
	const string CONST_baseactions007 = "Choose squad member to move";
	extern short party_status;
	extern squadst *activesquad;
	party_status = -1;
	int partysize = squadsize(activesquad);
	if (partysize <= 1) return;
	while (true)
	{
		printparty();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8, 26, CONST_baseactions007);
		int oldPos = getkeyAlt();
		if (oldPos<'1' || oldPos>partysize + '1' - 1) return; // User chose index out of range, exit
		makedelimiter();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		std::string str = CONST_baseactions008;
		str += activesquad->squad[oldPos - '1']->name;
		str += CONST_baseactions009;
		str += (char)oldPos;
		mvaddstrCenter(8, str);
		int newPos = getkeyAlt();
		if (newPos<'1' || newPos>partysize + '1' - 1) return; // User chose index out of range, exit
		swap(activesquad->squad[oldPos - '1'], activesquad->squad[newPos - '1']);
	}
}
int lenVehiclePool();
int getCarID(const int l);
string getCarFullname(const int l);
/* base - assign a vehicle to this squad */
void setvehicles()
{
	const string CONST_baseactions012 = "be a passenger.";
	const string CONST_baseactions011 = "drive it.";
	const string CONST_baseactions010 = "Choosing the Right Liberal Vehicle";
	extern squadst *activesquad;
	extern short interface_pgup;
	extern short interface_pgdn;
	if (!activesquad) return;
	int page = 0;
	while (true)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0,  0, CONST_baseactions010);
		printparty();
		int x = 1, y = 10;
		char str[200];
		for (int l = page * 18; l < lenVehiclePool() && l < page * 18 + 18; l++)
		{
			bool this_squad = false;
			for (int p = 0; p < 6; p++)
			{
				if (activesquad->squad[p] == NULL) continue;
				if (activesquad->squad[p]->alive&&
					activesquad->squad[p]->pref_carid == getCarID(l))
				{
					this_squad = true;
					break;
				}
			}
			bool another_squad = CreaturePool::getInstance().isThisCarWantedByAnotherSquad(getCarID(l), activesquad->id);
			if (this_squad&&another_squad)
				set_color_easy(RED_ON_BLACK_BRIGHT);
			else if (another_squad)
				set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			else if (this_squad)
				set_color_easy(GREEN_ON_BLACK_BRIGHT);
			else
				set_color_easy(WHITE_ON_BLACK);
			str[0] = l - page * 18 + 'A';
			str[1] = '\x0';
			strcat(str, spaceDashSpace.c_str());
			strcat(str, getCarFullname(l).c_str());
			mvaddstrAlt(y, x, str);
			x += 26;
			if (x > 53) x = 1, y++;
		}
		set_color_easy(WHITE_ON_BLACK);
		//PAGE UP
		if (page > 0)
		{
			mvaddstrAlt(17, 1, addprevpagestr());
		}
		//PAGE DOWN
		if ((page + 1) * 18 < lenVehiclePool())
		{
			mvaddstrAlt(17, 53, addnextpagestr());
		}
		for (int i = 0; i < len(vehicleParagraph); i++) {
			mvaddstrAlt(18 + i, 1, vehicleParagraph[i]);
		}
		// TODO this is the only instance in entire program using getkey_cap()
		int c = getkey_cap();
		if (c >= 'A'&&c <= 'R')
		{
			int slot = c - 'A' + page * 18;
			if (slot >= 0 && slot < lenVehiclePool())
			{
				bool choice = true;
				if (activesquad->squad[0])
				{
					choice = false;
					for (int c = 1; c < 6; c++)
					{
						if (activesquad->squad[c]) //are these slots always filled in order?
						{
							choice = true;
							break;
						}
					}
				}
				int c = '1';
				if (choice)
				{
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8, 20, chooseALiberalTo + CONST_baseactions011);
					c = getkeyAlt();
				}
				if (c >= '1'&&c <= '6')
				{
					if (activesquad->squad[c - '1'] != NULL)
					{
						activesquad->squad[c - '1']->pref_carid = getCarID(slot);
						if (activesquad->squad[c - '1']->canwalk())
							activesquad->squad[c - '1']->pref_is_driver = 1;
						else activesquad->squad[c - '1']->pref_is_driver = 0;
					}
				}
			}
		}
		if (c >= 'a'&&c <= 'r')
		{
			int slot = c - 'a' + page * 18;
			if (slot >= 0 && slot < lenVehiclePool())
			{
				bool choice = true;
				if (activesquad->squad[0])
				{
					choice = false;
					for (int c = 1; c < 6; c++)
					{
						if (activesquad->squad[c]) //are these slots always filled in order?
						{
							choice = true;
							break;
						}
					}
				}
				int c = '1';
				if (choice)
				{
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8, 20, chooseALiberalTo + CONST_baseactions012);
					c = getkeyAlt();
				}
				if (c >= '1'&&c <= '6')
				{
					if (activesquad->squad[c - '1'])
					{
						activesquad->squad[c - '1']->pref_carid = getCarID(slot);
						activesquad->squad[c - '1']->pref_is_driver = 0;
					}
				}
			}
		}
		//SAV - adding way to remove people from vehicles.
		if (c >= '1'&&c <= '6')
		{
			// 1. Is there someone there?
			if (activesquad->squad[c - '1'])
			{
				// 2. Are they in a vehicle? Someday we'll want to enforce car capacity
				int vin = activesquad->squad[c - '1']->pref_carid;
				if (vin > -1)
				{
					activesquad->squad[c - '1']->pref_carid = -1;
					activesquad->squad[c - '1']->pref_is_driver = 0;
				}
			}
		}
		//SAV - End add
		//PAGE UP
		if ((c == interface_pgup || c == KEY_UP || c == KEY_LEFT) && page>0) page--;
		//PAGE DOWN
		if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page + 1) * 18<lenVehiclePool()) page++;
		if (c == 'x' || c == 'X' || c == ENTER || c == ESC || c == SPACEBAR) return;
	}
}