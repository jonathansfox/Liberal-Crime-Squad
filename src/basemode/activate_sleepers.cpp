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

#include <includes.h>

#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
extern vector<Creature *> pool;
extern vector<Location *> location;
extern MusicClass music;
extern string spaceDashSpace;
extern string percentSign;
/* base - activate sleepers */
void activate_sleepers()
{
	vector<Creature *> temppool;
	// Comb the pool of Liberals for sleeper agents
	for (int p = 0; p < len(pool); p++)
	{
		// Select only sleepers that can work
		if (pool[p]->alive == true &&
			pool[p]->flag & CREATUREFLAG_SLEEPER&&
			pool[p]->align == ALIGN_LIBERAL&&
			pool[p]->hiding == false &&
			pool[p]->clinic == false &&
			pool[p]->dating == false)
		{
			temppool.push_back(pool[p]);
		}
	}
	if (!len(temppool)) return;
	sortliberals(temppool, activesortingchoice[SORTINGCHOICE_ACTIVATESLEEPERS]);
	int page = 0;
	while (true)
	{
		music.play(MUSIC_SLEEPERS);
		eraseAlt();
		set_color(COLOR_WHITE, COLOR_BLACK, 0);
		printfunds();
		moveZeroZero();
		addstrAlt("Activate Sleeper Agents");
		makedelimiter(1);
		moveAlt(1, 4);
		addstrAlt("CODE NAME");
		moveAlt(1, 25);
		addstrAlt("JOB");
		moveAlt(1, 42);
		addstrAlt("SITE");
		moveAlt(1, 57);
		addstrAlt("ACTIVITY");
		int y = 2;
		for (int p = page * 9; p < len(temppool) && p < page * 9 + 9; p++, y += 2)
		{
			set_color(COLOR_WHITE, COLOR_BLACK, 0);
			mvaddcharAlt(y, 0, (y - 2) / 2 + 'A'); addstrAlt(spaceDashSpace);
			addstrAlt(temppool[p]->name);
			moveAlt(y, 25);
			addstrAlt(temppool[p]->get_type_name());
			moveAlt(y + 1, 6);
			addstrAlt("Effectiveness: ");
			if (temppool[p]->infiltration > 0.8f)
				set_color(COLOR_RED, COLOR_BLACK, 1);
			else if (temppool[p]->infiltration > 0.6f)
				set_color(COLOR_MAGENTA, COLOR_BLACK, 1);
			else if (temppool[p]->infiltration > 0.4f)
				set_color(COLOR_YELLOW, COLOR_BLACK, 1);
			else if (temppool[p]->infiltration > 0.2f)
				set_color(COLOR_WHITE, COLOR_BLACK, 1);
			else if (temppool[p]->infiltration > 0.1f)
				set_color(COLOR_WHITE, COLOR_BLACK, 0);
			else set_color(COLOR_GREEN, COLOR_BLACK, 0);
			addstrAlt(static_cast<long>(temppool[p]->infiltration * 100 + 0.5)); // gets rounded to nearest integer
			addstrAlt(percentSign);
			set_color(COLOR_WHITE, COLOR_BLACK, 0);
			mvaddstrAlt(y, 42, location[temppool[p]->worklocation]->getname(true, true));
			moveAlt(y, 57);
			// Let's add some color here...
			set_activity_color(temppool[p]->activity.type);
			addstrAlt(getactivity(temppool[p]->activity));
		}
		set_color(COLOR_WHITE, COLOR_BLACK, 0);
		moveAlt(22, 0);
		addstrAlt("Press a Letter to Assign an Activity.");
		moveAlt(23, 0);
		addpagestr();
		addstrAlt(" T to sort people.");
		set_color(COLOR_WHITE, COLOR_BLACK, 0);
		int c = getkey();
		//PAGE UP
		if ((c == interface_pgup || c == KEY_UP || c == KEY_LEFT) && page>0) page--;
		//PAGE DOWN
		if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page + 1) * 9<len(temppool)) page++;
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
void activate_sleeper(Creature *cr)
{
	int state = 0, choice = 0;
	while (true)
	{
		eraseAlt();
		set_color(COLOR_WHITE, COLOR_BLACK, 0);
		printfunds();
		moveZeroZero();
		addstrAlt("Taking Undercover Action:   What will ");
		addstrAlt(cr->name);
		addstrAlt(" focus on?");
		printcreatureinfo(cr);
		makedelimiter();
		set_color(COLOR_WHITE, COLOR_BLACK, state == 'a');
		moveAlt(10, 1);
		addstrAlt("A - Communication and Advocacy");
		set_color(COLOR_WHITE, COLOR_BLACK, state == 'b');
		moveAlt(11, 1);
		addstrAlt("B - Espionage");
		set_color(COLOR_WHITE, COLOR_BLACK, state == 'c');
		moveAlt(12, 1);
		addstrAlt("C - Join the Active LCS");
		set_color(COLOR_WHITE, COLOR_BLACK, 0);
		moveAlt(20, 40);
		addstrAlt("Enter - Confirm Selection");
		switch (state)
		{
		case 'a':
			set_color(COLOR_WHITE, COLOR_BLACK, cr->activity.type == ACTIVITY_NONE);
			moveAlt(10, 40);
			addstrAlt("1 - Lay Low");
			set_color(COLOR_WHITE, COLOR_BLACK, cr->activity.type == ACTIVITY_SLEEPER_LIBERAL);
			moveAlt(11, 40);
			addstrAlt("2 - Advocate Liberalism");
			moveAlt(12, 40);
			if (subordinatesleft(*cr))
			{
				set_color(COLOR_WHITE, COLOR_BLACK, cr->activity.type == ACTIVITY_SLEEPER_RECRUIT);
				addstrAlt("3 - Expand Sleeper Network");
			}
			else
			{
				set_color(COLOR_BLACK, COLOR_BLACK, 1);
				if (cr->flag & CREATUREFLAG_BRAINWASHED)
					addstrAlt("3 - [Enlightened Can't Recruit]");
				else addstrAlt("3 - [Need More Juice to Recruit]");
			}
			break;
		case 'b':
			set_color(COLOR_WHITE, COLOR_BLACK, cr->activity.type == ACTIVITY_SLEEPER_SPY);
			moveAlt(10, 40);
			addstrAlt("1 - Uncover Secrets");
			set_color(COLOR_WHITE, COLOR_BLACK, cr->activity.type == ACTIVITY_SLEEPER_EMBEZZLE);
			moveAlt(11, 40);
			addstrAlt("2 - Embezzle Funds");
			set_color(COLOR_WHITE, COLOR_BLACK, cr->activity.type == ACTIVITY_SLEEPER_STEAL);
			moveAlt(12, 40);
			addstrAlt("3 - Steal Equipment");
			break;
		}
		set_color(COLOR_WHITE, COLOR_BLACK, 0);
		switch (cr->activity.type)
		{
		case ACTIVITY_NONE:
			moveAlt(22, 3);
			addstrAlt(cr->name);
			addstrAlt(" will stay out of trouble.");
			break;
		case ACTIVITY_SLEEPER_LIBERAL:
			moveAlt(22, 3);
			addstrAlt(cr->name);
			addstrAlt(" will build support for Liberal causes.");
			break;
		case ACTIVITY_SLEEPER_RECRUIT:
			if (subordinatesleft(*cr))
			{
				moveAlt(22, 3);
				addstrAlt(cr->name);
				addstrAlt(" will try to recruit additional sleeper agents.");
			}
			break;
		case ACTIVITY_SLEEPER_SPY:
			moveAlt(22, 3);
			addstrAlt(cr->name);
			addstrAlt(" will snoop around for secrets and enemy plans.");
			break;
		case ACTIVITY_SLEEPER_EMBEZZLE:
			moveAlt(22, 3);
			addstrAlt(cr->name);
			addstrAlt(" will embezzle money for the LCS.");
			break;
		case ACTIVITY_SLEEPER_STEAL:
			moveAlt(22, 3);
			addstrAlt(cr->name);
			addstrAlt(" will steal equipment and send it to the Shelter.");
			break;
		}
		int c = getkey();
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
			//activityst oact=cr->activity;
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
