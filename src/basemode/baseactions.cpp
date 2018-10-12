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
////

//#include "../creature/deprecatedCreatureA.h"
//#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
//#include "../cursesgraphics.h"

#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
//#include "../common/getnames.h"
void enter_name(int, int, char*, int, const char*);
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
extern string spaceDashSpace;
 string chooseALiberalTo;
 string string_sleeper;
 vector<string> vehicleParagraph;
 const string mostlyendings = "mostlyendings\\";
 vector<file_and_text_collection> baseactions_text_file_collection = {
	 customText(&vehicleParagraph, mostlyendings + CONST_baseactions004),
 };
/* base - burn the flag */

// string enter_done;
// string chooseALiberalTo;
// string string_sleeper;
// vector<string> vehicleParagraph;
 
 /* base - new slogan */
 void getslogan()
 {
	 const string CONST_baseactions006 = "                                                                                          ";
	 const string CONST_baseactions005 = "What is your new slogan?";
	 extern char slogan[SLOGAN_LEN];
	 extern string slogan_str;
	 extern vector<string> default_slogans;
	 set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(16, 0, CONST_baseactions005);
	 mvaddstrAlt(17, 0, CONST_baseactions006); // 80 spaces
	 enter_name(17, 0, slogan, SLOGAN_LEN, pickrandom(default_slogans).c_str());
	 slogan_str = slogan;
 }
 /* base - reorder party */
 void orderparty()
 {
	 const string CONST_baseactions009 = " in Spot ";
	 const string CONST_baseactions008 = "Choose squad member to replace ";
	 const string CONST_baseactions007 = "Choose squad member to move";
	 extern short party_status;
	 extern Deprecatedsquadst *activesquad;
	 party_status = -1;
	 int partysize = activesquadSize();
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
		 str += activesquad->squad[oldPos - '1']->getNameAndAlignment().name;
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
 void printCars(const int page) {
	 extern Deprecatedsquadst *activesquad;
	 int x = 1, y = 10;
	 string str;
	 for (int l = page * 18; l < lenVehiclePool() && l < page * 18 + 18; l++)
	 {
		 bool this_squad = false;
		 for (int p = 0; p < 6; p++)
		 {
			 if (activesquad->squad[p] == NULL) continue;
			 if (activesquad->squad[p]->getCreatureHealth().alive&&
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
		 str += spaceDashSpace;
		 str += getCarFullname(l);
		 mvaddstrAlt(y, x, str);
		 x += 26;
		 if (x > 53) x = 1, y++;
	 }
 }
 int getkey_cap_alt();
 /* base - assign a vehicle to this squad */
 const string CONST_baseactions012 = "be a passenger.";
 const string CONST_baseactions011 = "drive it.";
 const string CONST_baseactions010 = "Choosing the Right Liberal Vehicle";
 void setvehicles()
 {
	 extern Deprecatedsquadst *activesquad;
	 extern short interface_pgup;
	 extern short interface_pgdn;
	 if (!activesquad) return;
	 int page = 0;
	 while (true)
	 {
		 eraseAlt();
		 set_color_easy(WHITE_ON_BLACK_BRIGHT);
		 mvaddstrAlt(0, 0, CONST_baseactions010);
		 printparty();
		 printCars(page);
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
		 int c = getkey_cap_alt();
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
		 if ((c == interface_pgup || c == KEY_UP || c == KEY_LEFT) && page > 0) page--;
		 //PAGE DOWN
		 if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page + 1) * 18 < lenVehiclePool()) page++;
		 if (c == 'x' || c == 'X' || c == ENTER || c == ESC || c == SPACEBAR) return;
	 }
 }

