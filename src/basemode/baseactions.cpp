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

#include <includes.h>
#include "creature/creature.h"
//#include "pdcurses/curses.h"
#include "cursesgraphics.h"

#include "common/ledgerEnums.h"
#include "common/ledger.h"

#include "vehicle/vehicletype.h"
#include "vehicle/vehicle.h"

#include "basemode/baseactions.h"


#include "common/consolesupport.h"
// for void set_color(short,short,bool)

#include "common/getnames.h"
// for std::string getactivity(activityst)
     //void enter_name(int,int,char*,int,char*)

#include "common/commonactions.h"
// for int squadsize(const squadst)

//#include "log/log.h"
// for commondisplay.h
#include "common/commondisplay.h"
// for void printparty(void)

#include "common/stringconversion.h"
//for char* strcat(char*, const std::string&)



#include <cursesAlternative.h>
#include <cursesAlternativeConstants.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
#include "locations/locationsPool.h"
extern bool multipleCityMode;
//extern MusicClass music;
string enter_done;
string spaceDashSpace;

 extern char slogan[SLOGAN_LEN];
 extern short party_status;
 extern squadst *activesquad;
 extern class Ledger ledger;
 extern short interface_pgup;
 extern short interface_pgdn;
 extern int selectedsiege;
 extern short lawList[LAWNUM];
 extern string singleSpace;
 extern vector<Vehicle *> vehicle;

#include "common/creaturePool.h"

/* base - burn the flag */
void burnflag()
{
	int flagparts = 126, flag[18][7][4], x, y;
	for (y = 0; y < 7; y++) if (y < 6) for (x = 0; x < 18; x++)
	{
		if (x < 9 && y < 4)
		{
			switch (y)
			{
			case 0: flag[x][y][0] = (x % 2 ? '.' : ':'); break;
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
	else for (x = 0; x < 18; x++)
	{
		flag[x][y][0] = CH_UPPER_HALF_BLOCK;
		flag[x][y][1] = COLOR_RED;
		flag[x][y][2] = COLOR_BLACK;
		flag[x][y][3] = 0;
	}
	x = LCSrandom(18), y = LCSrandom(7);
	flag[x][y][0] = CH_DARK_SHADE;
	flag[x][y][1] = COLOR_YELLOW;
	flag[x][y][2] = COLOR_BLACK;
	flag[x][y][3] = 1;
	bool first = true;
	while (flagparts > 0)
	{
		if (!first) for (x = 0; x < 18; x++) for (y = 0; y < 7; y++)
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
		for (x = 0; x < 18; x++) for (y = 0; y < 7; y++)
		{
			set_color(short(flag[x][y][1]), short(flag[x][y][2]), bool(flag[x][y][3]));
			mvaddchAlt(y + 10, x + 31, flag[x][y][0]);
		}
		pause_ms(10);
		bool gotnew = false;
		while (!gotnew&&flagparts > 3)
		{
			x = LCSrandom(18), y = LCSrandom(7);
			bool conf = false;
			if (flag[x][y][0] == ':' || flag[x][y][0] == '.' || flag[x][y][0] == CH_UPPER_HALF_BLOCK || flag[x][y][0] == CH_LOWER_HALF_BLOCK)
			{
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
extern vector<string> default_slogans;
void getslogan()
{
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(16, 0, "What is your new slogan?");
	mvaddstrAlt(17, 0, "                                                                                          "); // 80 spaces
	enter_name(17, 0, slogan, SLOGAN_LEN, pickrandom(default_slogans).data());
}
/* base - reorder party */
void orderparty()
{
	party_status = -1;
	int partysize = squadsize(activesquad);
	if (partysize <= 1) return;
	while (true)
	{
		printparty();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8, 26, "Choose squad member to move");
		int oldPos = getkeyAlt();
		if (oldPos<'1' || oldPos>partysize + '1' - 1) return; // User chose index out of range, exit
		makedelimiter();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		std::string str = "Choose squad member to replace ";
		str += activesquad->squad[oldPos - '1']->name;
		str += " in Spot ";
		str += (char)oldPos;
		mvaddstrCenter(8, str);
		int newPos = getkeyAlt();
		if (newPos<'1' || newPos>partysize + '1' - 1) return; // User chose index out of range, exit
		swap(activesquad->squad[oldPos - '1'], activesquad->squad[newPos - '1']);
	}
}

string chooseALiberalTo;
 string string_sleeper;
 vector<string> vehicleParagraph;
/* base - assign a vehicle to this squad */
void setvehicles()
{
	int p, l;
	if (!activesquad) return;
	int page = 0;
	while (true)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0,  0, "Choosing the Right Liberal Vehicle");
		printparty();
		int x = 1, y = 10;
		char str[200];
		for (l = page * 18; l < len(vehicle) && l < page * 18 + 18; l++)
		{
			bool this_squad = false;
			for (p = 0; p < 6; p++)
			{
				if (activesquad->squad[p] == NULL) continue;
				if (activesquad->squad[p]->alive&&
					activesquad->squad[p]->pref_carid == vehicle[l]->id())
				{
					this_squad = true;
					break;
				}
			}
			bool another_squad = CreaturePool::getInstance().isThisCarWantedByAnotherSquad(vehicle[l]->id(), activesquad->id);
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
			strcat(str, spaceDashSpace);
			strcat(str, vehicle[l]->fullname(true));
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
		if ((page + 1) * 18 < len(vehicle))
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
			if (slot >= 0 && slot < len(vehicle))
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
					mvaddstrAlt(8, 20, chooseALiberalTo + "drive it.");
					c = getkeyAlt();
				}
				if (c >= '1'&&c <= '6')
				{
					if (activesquad->squad[c - '1'] != NULL)
					{
						activesquad->squad[c - '1']->pref_carid = vehicle[slot]->id();
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
			if (slot >= 0 && slot < len(vehicle))
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
					mvaddstrAlt(8, 20, chooseALiberalTo + "be a passenger.");
					c = getkeyAlt();
				}
				if (c >= '1'&&c <= '6')
				{
					if (activesquad->squad[c - '1'])
					{
						activesquad->squad[c - '1']->pref_carid = vehicle[slot]->id();
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
		if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page + 1) * 18<len(vehicle)) page++;
		if (c == 'x' || c == 'X' || c == ENTER || c == ESC || c == SPACEBAR) return;
	}
}
