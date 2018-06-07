#include "../includes.h"
/*
This file is part of Liberal Crime Squad.                                           //
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

const string blankString = "";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
#include "../creature/creature.h"
//#include "../common/commonactions.h"
void sorting_prompt(short listforsorting);
#include "../common/commonactionsCreature.h"
// for void sortliberals(std::vector<Creature *>&,short,bool)
//#include "../common/consolesupport.h"
// for void set_color(short,short,bool)
#include "../common/commondisplay.h"
//#include "../common/commondisplayCreature.h"
void printcreatureinfo(Creature *cr, unsigned char knowledge = 255);
//#include "../common/getnames.h"
string getactivity(ActivityST &act);
#include "../cursesAlternative.h"
#include "../cursesAlternativeConstants.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
#include "../common/creaturePoolCreature.h"
extern string spaceDashSpace;
extern string percentSign;
void activate_sleeper(Creature *cr)
{
	const string CONST_activate_sleepers023 = " will steal equipment and send it to the Shelter.";
	const string CONST_activate_sleepers022 = " will embezzle money for the LCS.";
	const string CONST_activate_sleepers021 = " will snoop around for secrets and enemy plans.";
	const string CONST_activate_sleepers020 = " will try to recruit additional sleeper agents.";
	const string CONST_activate_sleepers019 = " will build support for Liberal causes.";
	const string CONST_activate_sleepers018 = " will stay out of trouble.";
	const string CONST_activate_sleepers017 = "3 - Steal Equipment";
	const string CONST_activate_sleepers016 = "2 - Embezzle Funds";
	const string CONST_activate_sleepers015 = "1 - Uncover Secrets";
	const string CONST_activate_sleepers014 = "3 - [Need More Juice to Recruit]";
	const string CONST_activate_sleepers013 = "3 - [Enlightened Can't Recruit]";
	const string CONST_activate_sleepers012 = "3 - Expand Sleeper Network";
	const string CONST_activate_sleepers011 = "2 - Advocate Liberalism";
	const string CONST_activate_sleepers010 = "1 - Lay Low";
	const string CONST_activate_sleepers009 = "Enter - Confirm Selection";
	const string CONST_activate_sleepers008 = "C - Join the Active LCS";
	const string CONST_activate_sleepers007 = "B - Espionage";
	const string CONST_activate_sleepers006 = "A - Communication and Advocacy";
	const string CONST_activate_sleepers005 = " focus on?";
	const string CONST_activate_sleepers004 = "Taking Undercover Action:   What will ";
	int state = 0, choice = 0;
	while (true)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK);
		printfunds();
		mvaddstrAlt(0, 0, CONST_activate_sleepers004);
		addstrAlt(cr->name);
		addstrAlt(CONST_activate_sleepers005);
		printcreatureinfo(cr);
		makedelimiter();
		set_color_easy(state == 'a' ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
		mvaddstrAlt(10, 1, CONST_activate_sleepers006);
		set_color_easy(state == 'b' ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
		mvaddstrAlt(11, 1, CONST_activate_sleepers007);
		set_color_easy(state == 'c' ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
		mvaddstrAlt(12, 1, CONST_activate_sleepers008);
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(20, 40, CONST_activate_sleepers009);
		switch (state)
		{
		case 'a':
			set_color_easy(cr->activity.type == ACTIVITY_NONE ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
			mvaddstrAlt(10, 40, CONST_activate_sleepers010);
			set_color_easy(cr->activity.type == ACTIVITY_SLEEPER_LIBERAL ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
			mvaddstrAlt(11, 40, CONST_activate_sleepers011);
			if (subordinatesleft(*cr))
			{
				set_color_easy(cr->activity.type == ACTIVITY_SLEEPER_RECRUIT ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
				mvaddstrAlt(12, 40, CONST_activate_sleepers012);
			}
			else
			{
				set_color_easy(BLACK_ON_BLACK_BRIGHT);
				if (cr->flag & CREATUREFLAG_BRAINWASHED)
					mvaddstrAlt(12, 40, CONST_activate_sleepers013);
				else mvaddstrAlt(12, 40, CONST_activate_sleepers014);
			}
			break;
		case 'b':
			set_color_easy(cr->activity.type == ACTIVITY_SLEEPER_SPY ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
			mvaddstrAlt(10, 40, CONST_activate_sleepers015);
			set_color_easy(cr->activity.type == ACTIVITY_SLEEPER_EMBEZZLE ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
			mvaddstrAlt(11, 40, CONST_activate_sleepers016);
			set_color_easy(cr->activity.type == ACTIVITY_SLEEPER_STEAL ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
			mvaddstrAlt(12, 40, CONST_activate_sleepers017);
			break;
		}
		set_color_easy(WHITE_ON_BLACK);
		switch (cr->activity.type)
		{
		case ACTIVITY_NONE:
			mvaddstrAlt(22, 3, cr->name);
			addstrAlt(CONST_activate_sleepers018);
			break;
		case ACTIVITY_SLEEPER_LIBERAL:
			mvaddstrAlt(22, 3, cr->name);
			addstrAlt(CONST_activate_sleepers019);
			break;
		case ACTIVITY_SLEEPER_RECRUIT:
			if (subordinatesleft(*cr))
			{
				mvaddstrAlt(22, 3, cr->name);
				addstrAlt(CONST_activate_sleepers020);
			}
			break;
		case ACTIVITY_SLEEPER_SPY:
			mvaddstrAlt(22, 3, cr->name);
			addstrAlt(CONST_activate_sleepers021);
			break;
		case ACTIVITY_SLEEPER_EMBEZZLE:
			mvaddstrAlt(22, 3, cr->name);
			addstrAlt(CONST_activate_sleepers022);
			break;
		case ACTIVITY_SLEEPER_STEAL:
			mvaddstrAlt(22, 3, cr->name);
			addstrAlt(CONST_activate_sleepers023);
			break;
		}
		int c = getkeyAlt();
		if (c >= 'a'&&c <= 'z') state = c;
		if ((c >= 'a'&&c <= 'z') || (c >= '1'&&c <= '9'))
		{
			choice = c;
			switch (state)
			{
			case 'a':
				switch (choice)
				{
				default:
				case '1':cr->activity.type = ACTIVITY_NONE; break;
				case '2':cr->activity.type = ACTIVITY_SLEEPER_LIBERAL; break;
				case '3':
					if (subordinatesleft(*cr))
						cr->activity.type = ACTIVITY_SLEEPER_RECRUIT; break;
				}
				break;
			case 'b':
				switch (choice)
				{
				default:
				case '1':cr->activity.type = ACTIVITY_SLEEPER_SPY; break;
				case '2':cr->activity.type = ACTIVITY_SLEEPER_EMBEZZLE; break;
				case '3':cr->activity.type = ACTIVITY_SLEEPER_STEAL; break;
				}
				break;
			}
		}
		if (state == 'c')
		{
			//ActivityST oact=cr->activity;
			cr->activity.type = ACTIVITY_SLEEPER_JOINLCS;
		}
		if (c == 'x')
		{
			cr->activity.type = ACTIVITY_NONE;
			break;
		}
		else
			if (c == ENTER || c == ESC || c == SPACEBAR) break;
	}
}
/* base - activate sleepers */
void activate_sleepers()
{
	const string CONST_activate_sleepers031 = " T to sort people.";
	const string CONST_activate_sleepers030 = "Press a Letter to Assign an Activity.";
	const string CONST_activate_sleepers029 = "Effectiveness: ";
	const string CONST_activate_sleepers028 = "ACTIVITY";
	const string CONST_activate_sleepers027 = "SITE";
	const string CONST_activate_sleepers026 = "JOB";
	const string CONST_activate_sleepers025 = "CODE NAME";
	const string CONST_activate_sleepers024 = "Activate Sleeper Agents";
	extern MusicClass music;
	extern short interface_pgup;
	extern short interface_pgdn;
	extern short activesortingchoice[SORTINGCHOICENUM];
	vector<Creature *> temppool;
	selectOnlySleepersThatCanWork(temppool);
	if (!len(temppool)) return;
	sortliberals(temppool, activesortingchoice[SORTINGCHOICE_ACTIVATESLEEPERS]);
	int page = 0;
	while (true)
	{
		music.play(MUSIC_SLEEPERS);
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK);
		printfunds();
		mvaddstrAlt(0, 0, CONST_activate_sleepers024);
		makedelimiter(1);
		mvaddstrAlt(1, 4, CONST_activate_sleepers025);
		mvaddstrAlt(1, 25, CONST_activate_sleepers026);
		mvaddstrAlt(1, 42, CONST_activate_sleepers027);
		mvaddstrAlt(1, 57, CONST_activate_sleepers028);
		int y = 2;
		for (int p = page * 9; p < len(temppool) && p < page * 9 + 9; p++, y += 2)
		{
			set_color_easy(WHITE_ON_BLACK);
			mvaddcharAlt(y, 0, (y - 2) / 2 + 'A'); addstrAlt(spaceDashSpace);
			addstrAlt(temppool[p]->name);
			mvaddstrAlt(y, 25, temppool[p]->get_type_name());
			mvaddstrAlt(y + 1, 6, CONST_activate_sleepers029);
			if (temppool[p]->infiltration > 0.8f)
				set_color_easy(RED_ON_BLACK_BRIGHT);
			else if (temppool[p]->infiltration > 0.6f)
				set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
			else if (temppool[p]->infiltration > 0.4f)
				set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			else if (temppool[p]->infiltration > 0.2f)
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
			else if (temppool[p]->infiltration > 0.1f)
				set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(GREEN_ON_BLACK);
			addstrAlt(static_cast<long>(temppool[p]->infiltration * 100 + 0.5)); // gets rounded to nearest integer
			addstrAlt(percentSign);
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(y, 42, LocationsPool::getInstance().getLocationNameWithGetnameMethod(temppool[p]->worklocation, true, true));
			// Let's add some color here...
			set_activity_color(temppool[p]->activity.type);
			mvaddstrAlt(y, 57, getactivity(temppool[p]->activity));
		}
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(22, 0, CONST_activate_sleepers030);
		mvaddstrAlt(23, 0, addpagestr() + CONST_activate_sleepers031);
		set_color_easy(WHITE_ON_BLACK);
		int c = getkeyAlt();
		//PAGE UP
		if ((c == interface_pgup || c == KEY_UP || c == KEY_LEFT) && page > 0) page--;
		//PAGE DOWN
		if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page + 1) * 9 < len(temppool)) page++;
		if (c >= 'a'&&c <= 's')
		{
			int p = page * 9 + (int)(c - 'a');
			if (p < len(temppool))
				activate_sleeper(temppool[p]);
		}
		if (c == 't')
		{
			sorting_prompt(SORTINGCHOICE_ACTIVATESLEEPERS);
			sortliberals(temppool, activesortingchoice[SORTINGCHOICE_ACTIVATESLEEPERS], true);
		}
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) break;
	}
}