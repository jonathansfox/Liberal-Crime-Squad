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

#include "common/ledgerEnums.h"
#include "common/ledger.h"

#include "log/log.h"
// for commondisplay.h
#include "common/commondisplay.h"
#include "common/commondisplayCreature.h"
// for  addstr

#include "common/commonactionsCreature.h"
// for int loveslavesleft(const Creature&)

#include "common/getnames.h"
// for void enter_name(int,int,char *,int,const char *=NULL)

//#include "common/translateid.h"
int getarmortype(const string &idname);



#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <set_color_support.h>
extern vector<Creature *> pool;
#include "common/creaturePoolCreature.h"
extern Log gamelog;
#include "locations/locationsPool.h"
#include "common/musicClass.h"
extern MusicClass music;
extern int stat_recruits;
extern int stat_kidnappings;
extern string singleDot;
 vector<string> date_fail;

 const string datey = "date\\";
 vector<file_and_text_collection> date_text_file_collection = {

	 /*date.cpp*/
	 customText(&date_fail, datey + "date_fail.txt"),
 };

 extern short lawList[LAWNUM];
 extern string commaSpace;
 extern string singleSpace;
 extern class Ledger ledger;
 extern vector<ArmorType *> armortype;
enum DateResults
{
   DATERESULT_MEETTOMORROW,
   DATERESULT_BREAKUP,
   DATERESULT_JOINED,
   DATERESULT_ARRESTED
};
extern string AND;
// Handles the result of a date or vacation
static int dateresult(int aroll, int troll, datest &d, int e, int p, int y)
{
	music.play(MUSIC_DATING);
	std::string s = "";
	if (aroll > troll)
	{
		set_color_easy(CYAN_ON_BLACK_BRIGHT);
		moveAlt(y, 0); y++;
		addstrAlt(d.date[e]->name, gamelog);
		addstrAlt(" is quite taken with ", gamelog);
		addstrAlt(pool[p]->name, gamelog);
		addstrAlt("'s unique life philosophy...", gamelog);
		gamelog.newline();
		getkeyAlt();
		if (loveslavesleft(*pool[p]) <= 0)
		{
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			mvaddstrAlt(y++,  0, "But ", gamelog);
			addstrAlt(pool[p]->name, gamelog);
			addstrAlt(" is already dating ", gamelog);
			int num_relationships = loveslaves(*pool[p]);
			if (pool[p]->flag&CREATUREFLAG_LOVESLAVE) num_relationships++;
			if (num_relationships == 1) addstrAlt("someone!", gamelog);
			else addstrAlt(tostring(num_relationships) + " people!", gamelog);
			gamelog.newline();
			mvaddstrAlt(y++,  0, pool[p]->name, gamelog);
			addstrAlt(" isn't seductive enough to juggle ", gamelog);
			if (num_relationships == 1) addstrAlt("another", gamelog);
			else addstrAlt("yet another", gamelog);
			addstrAlt(" relationship.", gamelog);
			gamelog.newline();
			getkeyAlt();
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(y++,  0, "It was fun though. They agree to part ways amicably.", gamelog);
			gamelog.nextMessage();
			getkeyAlt();
			delete_and_remove(d.date, e);
			return DATERESULT_BREAKUP;
		}
		if (LCSrandom((aroll - troll) / 2) > d.date[e]->get_attribute(ATTRIBUTE_WISDOM, true))
		{
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			moveAlt(y, 0); y++;
			addstrAlt("In fact, ", gamelog);
			addstrAlt(d.date[e]->name, gamelog);
			addstrAlt(" is ", gamelog);
			addstrAlt(pool[p]->name, gamelog);
			addstrAlt("'s totally unconditional love-slave!", gamelog);
			gamelog.nextMessage();
			//Get map of their workplace
			LocationsPool::getInstance().setLocationMappedAndUnhidden(d.date[e]->worklocation);
			getkeyAlt();
			d.date[e]->flag |= CREATUREFLAG_LOVESLAVE;
			d.date[e]->hireid = pool[p]->id;
			eraseAlt();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(0,  0, "The Self-Nullifying Infatuation of ");
			addstrAlt(d.date[e]->propername);
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(2,  0, "What name will you use for this ");
			addstrAlt(d.date[e]->get_type_name());
			addstrAlt(" in its presence?");
			mvaddstrAlt(3,  0, "If you do not enter anything, their real name will be used.");
			enter_name(4, 0, d.date[e]->name, CREATURE_NAMELEN, d.date[e]->propername);
			sleeperize_prompt(*d.date[e], *pool[p], 8);
			addCreature(d.date[e]);
			stat_recruits++;
			d.date.erase(d.date.begin() + e);
			return DATERESULT_JOINED;
		}
		else
		{
			if (d.date[e]->align == ALIGN_CONSERVATIVE && d.date[e]->get_attribute(ATTRIBUTE_WISDOM, false) > 3)
			{
				set_color_easy(GREEN_ON_BLACK_BRIGHT);
				y++;
				mvaddstrAlt(y++,  0, s + pool[p]->name + " is slowly warming " + d.date[e]->name + "'s frozen Conservative heart.", gamelog);
				gamelog.newline();
				moveAlt(y++, 0);
				d.date[e]->adjust_attribute(ATTRIBUTE_WISDOM, -1);
				d.date[e]->adjust_attribute(ATTRIBUTE_HEART, +1);
			}
			else if (d.date[e]->get_attribute(ATTRIBUTE_WISDOM, false) > 3)
			{
				d.date[e]->adjust_attribute(ATTRIBUTE_WISDOM, -1);
			}
			//Possibly date reveals map of location
			else if (LocationsPool::getInstance().isLocationMapped(d.date[e]->worklocation) == 0 && !LCSrandom(d.date[e]->get_attribute(ATTRIBUTE_WISDOM, false)))
			{
				y++;
				mvaddstrAlt(y++,  0, s + d.date[e]->name + " turns the topic of discussion to the "
					+ LocationsPool::getInstance().getLocationName(d.date[e]->worklocation) + singleDot, gamelog);
				gamelog.newline();
				moveAlt(y++, 0);
				if (!(LocationsPool::getInstance().getLocationType(d.date[e]->worklocation) <= SITE_RESIDENTIAL_SHELTER))
				{
					addstrAlt(pool[p]->name, gamelog);
					addstrAlt(" was able to create a map of the site with this information.", gamelog);
					gamelog.newline();
					y++;
				}
				else
				{
					addstrAlt(pool[p]->name, gamelog);
					addstrAlt(" knows all about that already.", gamelog);
					gamelog.newline();
					y++;
				}
				LocationsPool::getInstance().setLocationMappedAndUnhidden(d.date[e]->worklocation);
			}
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(y++,  0, "They'll meet again tomorrow.", gamelog);
			gamelog.nextMessage();
			getkeyAlt();
			return DATERESULT_MEETTOMORROW;
		}
	}
	else if (aroll == troll)
	{
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(y++,  0, d.date[e]->name, gamelog);
		addstrAlt(" seemed to have fun, but left early", gamelog);
		moveAlt(y++, 0);
		switch (LCSrandom(7))
		{
		case 0: addstrAlt(s + " to wash " + d.date[e]->hisher() + " hair.", gamelog); break;
		case 1: addstrAlt(" due to an allergy attack.", gamelog); break;
		case 2: addstrAlt(" due to an early meeting tomorrow.", gamelog); break;
		case 3: addstrAlt(s + " to catch " + d.date[e]->hisher() + " favourite TV show.", gamelog); break;
		case 4:
			addstrAlt(s + " to take care of " + d.date[e]->hisher() + " pet", gamelog);
			switch (LCSrandom(3 + (lawList[LAW_ANIMALRESEARCH] == -2)))
			{
			case 0: addstrAlt(" cat.", gamelog); break;
			case 1: addstrAlt(" dog.", gamelog); break;
			case 2: addstrAlt(" fish.", gamelog); break;
			case 3: addstrAlt(" six-legged pig.", gamelog); break;
			}
			break;
		case 5: addstrAlt(" to go to a birthday party.", gamelog); break;
		case 6: addstrAlt(s + " to recharge " + d.date[e]->hisher() + " cell phone.", gamelog); break;
		}
		mvaddstrAlt(y++,  0, "They'll meet again tomorrow.", gamelog);
		gamelog.nextMessage();
		getkeyAlt();
		return DATERESULT_MEETTOMORROW;
	}
	else
	{
		//WISDOM POSSIBLE INCREASE
		if (d.date[e]->align == -1 && aroll < troll / 2)
		{
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(y++,  0, "Talking with ", gamelog);
			addstrAlt(d.date[e]->name, gamelog);
			addstrAlt(" actually curses ", gamelog);
			addstrAlt(pool[p]->name, gamelog);
			addstrAlt("'s mind with wisdom!!!", gamelog);
			gamelog.newline();
			pool[p]->adjust_attribute(ATTRIBUTE_WISDOM, +1);
			if (d.date[e]->get_skill(SKILL_RELIGION) > pool[p]->get_skill(SKILL_RELIGION))
				pool[p]->train(SKILL_RELIGION, 20 * (d.date[e]->get_skill(SKILL_RELIGION) - pool[p]->get_skill(SKILL_RELIGION)));
			if (d.date[e]->get_skill(SKILL_SCIENCE) > pool[p]->get_skill(SKILL_SCIENCE))
				pool[p]->train(SKILL_SCIENCE, 20 * (d.date[e]->get_skill(SKILL_SCIENCE) - pool[p]->get_skill(SKILL_SCIENCE)));
			if (d.date[e]->get_skill(SKILL_BUSINESS) > pool[p]->get_skill(SKILL_BUSINESS))
				pool[p]->train(SKILL_BUSINESS, 20 * (d.date[e]->get_skill(SKILL_BUSINESS) - pool[p]->get_skill(SKILL_BUSINESS)));
			getkeyAlt();
		}
		//BREAK UP
		// If your squad member is wanted by the police, a conservative who breaks up with
		// them has a 1 in 50 chance of ratting them out, unless the person being dated is law
		// enforcement, prison guard, or agent, in which case there is a 1 in 4 chance. -Fox
		if ((iscriminal(*pool[p])) &&
			(!LCSrandom(50) || (LCSrandom(2) && (d.date[e]->kidnap_resistant()))))
		{
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(y++,  0, d.date[e]->name, gamelog);
			addstrAlt(" was leaking information to the police the whole time!", gamelog);
			getkeyAlt();
			moveAlt(y++, 0);
			// 3/4 chance of being arrested if less than 50 juice,
			// 1/2 chance of being arrested if more than 50 juice
			if ((pool[p]->juice < 50 && LCSrandom(2)) || LCSrandom(2))
			{
				// Find the police station
				long ps = find_site_index_in_same_city(SITE_GOVERNMENT_POLICESTATION, pool[p]->location);
				set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
				addstrAlt(pool[p]->name, gamelog);
				addstrAlt(" has been arrested.", gamelog);
				gamelog.nextMessage();
				removesquadinfo(*pool[p]);
				pool[p]->carid = -1;
				pool[p]->location = ps;
				pool[p]->drop_weapons_and_clips(NULL);
				pool[p]->activity.type = ACTIVITY_NONE;
				getkeyAlt();
				delete_and_remove(d.date, e);
				return DATERESULT_ARRESTED;
			}
			else
			{
				set_color_easy(GREEN_ON_BLACK_BRIGHT);
				addstrAlt("But ", gamelog);
				addstrAlt(pool[p]->name, gamelog);
				addstrAlt(" escapes the police ambush!", gamelog);
				gamelog.nextMessage();
			}
		}
		else
		{
			int ls = loveslaves(*pool[p]);
			if (ls > 0 && LCSrandom(2))
			{
				set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
				mvaddstrAlt(y++,  0, s + "The date starts well, but goes horribly wrong when " + d.date[e]->name, gamelog);
				mvaddstrAlt(y++,  0, s + "notices " + pool[p]->name + "'s ", gamelog);
				switch (ls)
				{
				case 5:
					addstrAlt("awe-inspiring ", gamelog);
					break;
				case 4:
					addstrAlt("intricate ", gamelog);
					break;
				case 3:
					addstrAlt("complicated ", gamelog);
					break;
				case 2:
					addstrAlt("detailed ", gamelog);
					break;
				case 1:
					break;
				default:
					addstrAlt("mind-bending ", gamelog);
				}
				addstrAlt(s + "schedule for keeping " + d.date[e]->himher(), gamelog);
				addstrAlt(s + " from meeting ", gamelog);
				moveAlt(y++, 0);
				int lsfound = 0;
				for (int q = 0; q < (int)pool.size(); q++)
				{
					if (pool[q]->hireid == pool[p]->id && pool[q]->alive && pool[q]->flag & CREATUREFLAG_LOVESLAVE)
					{
						lsfound++;
						if (lsfound == 1)
						{
							addstrAlt(pool[q]->name, gamelog);
						}
						else if (lsfound < ls)
						{
							addstrAlt(s + commaSpace + pool[q]->name, gamelog);
						}
						else
						{
							addstrAlt(s + AND + pool[q]->name, gamelog);
						}
					}
				}
				addstrAlt(singleDot, gamelog);
				gamelog.newline();
				moveAlt(y++, 0);
			}
			else
			{
				set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
				mvaddstrAlt(y++,  0, d.date[e]->name, gamelog);
				addstrAlt(" can sense that things just aren't working out.", gamelog);
				gamelog.newline();
				moveAlt(y++, 0);
			}
			addstrAlt("This relationship is over.", gamelog);
			gamelog.nextMessage();
		}
		getkeyAlt();
		delete_and_remove(d.date, e);
		return DATERESULT_BREAKUP;
	}
}
/* daily - date - dater p gets back from vacation */
char completevacation(datest &d, int p, char &clearformess)
{
	music.play(MUSIC_DATING);
	int e = 0;
	clearformess = 1;
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(0,  0, pool[p]->name, gamelog);
	addstrAlt(" is back from vacation.", gamelog);
	gamelog.nextMessage();
	// Temporarily make the date Conservative so that high-juice liberals aren't trivial to seduce
	int datealignment = d.date[e]->align;
	d.date[e]->align = -1;
	short aroll = pool[p]->skill_roll(SKILL_SEDUCTION) * 2;
	short troll = d.date[e]->attribute_roll(ATTRIBUTE_WISDOM);
	// Attribute roll over; reset date's alignment to what it should be
	d.date[e]->align = datealignment;
	pool[p]->train(SKILL_SEDUCTION, LCSrandom(11) + 15);
	int thingsincommon = 0;
	for (int s = 0; s < SKILLNUM; s++)
		if (d.date[e]->get_skill(s) >= 1 && pool[p]->get_skill(s) >= 1)
			//Has a skill that is at least half the same skill of the other person on the date.
			if (d.date[e]->get_skill(s) <= pool[p]->get_skill(s) * 2)
				thingsincommon++;
	aroll += thingsincommon * 3;
	pool[p]->train(SKILL_SCIENCE,
		max(d.date[e]->get_skill(SKILL_SCIENCE) - pool[p]->get_skill(SKILL_SCIENCE), 0));
	pool[p]->train(SKILL_RELIGION,
		max(d.date[e]->get_skill(SKILL_RELIGION) - pool[p]->get_skill(SKILL_RELIGION), 0));
	pool[p]->train(SKILL_BUSINESS,
		max(d.date[e]->get_skill(SKILL_BUSINESS) - pool[p]->get_skill(SKILL_BUSINESS), 0));
	if (d.date[e]->skill_roll(SKILL_BUSINESS))
	{
		troll += d.date[e]->skill_roll(SKILL_BUSINESS);
		aroll += pool[p]->skill_roll(SKILL_BUSINESS);
	}
	if (d.date[e]->skill_roll(SKILL_RELIGION))
	{
		troll += d.date[e]->skill_roll(SKILL_RELIGION);
		aroll += pool[p]->skill_roll(SKILL_RELIGION);
	}
	if (d.date[e]->skill_roll(SKILL_SCIENCE))
	{
		troll += d.date[e]->skill_roll(SKILL_SCIENCE);
		aroll += pool[p]->skill_roll(SKILL_SCIENCE);
	}
	switch (dateresult(aroll, troll, d, e, p, 2))
	{
	default:
	case DATERESULT_MEETTOMORROW:return 0;
	case DATERESULT_BREAKUP:     return 1;
	case DATERESULT_JOINED:      return 1;
	case DATERESULT_ARRESTED:    return 1;
	}
}
extern string pressKeyToReflect;
/* daily - date - dater p goes on some dates */
char completedate(datest &d, int p, char &clearformess)
{
	music.play(MUSIC_DATING);
	int e;
	clearformess = 1;
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(0,  0, pool[p]->name, gamelog);
	addstrAlt(" has ", gamelog);
	if (len(d.date) == 1)
	{
		if (pool[p]->clinic) addstrAlt("a \"hot\" date with ", gamelog);
		else addstrAlt("a hot date with ", gamelog);
	}
	else addstrAlt("dates to manage with ", gamelog);
	for (e = 0; e < len(d.date); e++)
	{
		addstrAlt(d.date[e]->name, gamelog);
		if (e <= len(d.date) - 3) addstrAlt(commaSpace, gamelog);
		else if (e == len(d.date) - 2) addstrAlt(AND, gamelog);
		else
		{
			if (pool[p]->clinic>0)
			{
				addstrAlt(" at ", gamelog);
				addstrAlt(LocationsPool::getInstance().getLocationName(pool[p]->location), gamelog);
			}
			addstrAlt(singleDot, gamelog);
		}
	}
	gamelog.newline();
	getkeyAlt();
	if (len(d.date) > 1 && !LCSrandom(len(d.date) > 2 ? 4 : 6))
	{
		switch (LCSrandom(3))
		{
		case 0:
			moveAlt(2, 0);
			if (len(d.date) > 2) addstrAlt("Unfortunately, they all know each other and had been discussing", gamelog);
			else addstrAlt("Unfortunately, they know each other and had been discussing", gamelog);
			mvaddstrAlt(3,  0, pool[p]->name, gamelog);
			addstrAlt(".  An ambush was set for the lying dog...", gamelog);
			gamelog.newline();
			getkeyAlt();
			break;
		case 1:
			moveAlt(2, 0);
			if (len(d.date) > 2) addstrAlt("Unfortunately, they all turn up at the same time.", gamelog);
			else addstrAlt("Unfortunately, they turn up at the same time.", gamelog);
			gamelog.newline();
			mvaddstrAlt(3,  0, "Ruh roh...", gamelog);
			gamelog.newline();
			getkeyAlt();
			break;
		default:
			mvaddstrAlt(2,  0, pool[p]->name, gamelog);
			if (len(d.date) > 2)
				addstr_fl(gamelog, " realizes %s has committed to eating %d meals at once.", pool[p]->heshe(), len(d.date));
			else
			{
				addstrAlt(" mixes up the names of ", gamelog);
				addstrAlt(d.date[0]->name, gamelog);
				addstrAlt(AND, gamelog);
				addstrAlt(d.date[1]->name, gamelog);
				gamelog.newline();
			}
			mvaddstrAlt(3,  0, "Things go downhill fast.", gamelog);
			gamelog.newline();
			getkeyAlt();
			break;
		}
		mvaddstrAlt(5,  0, pool[p]->name, gamelog);
		addstrAlt(singleSpace, gamelog);
		addstrAlt(pickrandom(date_fail), gamelog);
		addjuice(*pool[p], -5, -50);
		gamelog.nextMessage();
		getkeyAlt();
		return 1;
	}
	for (e = len(d.date) - 1; e >= 0; e--)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0,  0, "Seeing ");
		addstrAlt(d.date[e]->name, gamelog);
		addstrAlt(commaSpace, gamelog);
		addstrAlt(d.date[e]->get_type_name(), gamelog);
		addstrAlt(commaSpace, gamelog);
		addstrAlt(LocationsPool::getInstance().getLocationNameWithGetnameMethod(d.date[e]->worklocation,false, true), gamelog);
		gamelog.newline();
		set_color_easy(WHITE_ON_BLACK);
		printfunds();
		//Others come to dates unarmed and wearing normal
		//clothing
		vector<Item*> temp;
		d.date[e]->drop_weapons_and_clips(&temp);
		Armor atmp(*armortype[getarmortype(tag_ARMOR_CLOTHES)]);
		d.date[e]->give_armor(atmp, &temp);
		printcreatureinfo(d.date[e]);
		makedelimiter();
		while (len(temp))
		{
			if (temp.back()->is_weapon())
				d.date[e]->give_weapon(*(static_cast<Weapon*>(temp.back())), NULL); //casts -XML
			else if (temp.back()->is_armor())
				d.date[e]->give_armor(*(static_cast<Armor*>(temp.back())), NULL);
			else if (temp.back()->is_clip())
				d.date[e]->take_clips(*(static_cast<Clip*>(temp.back())), temp.back()->get_number());
			delete_and_remove(temp, len(temp) - 1);
		}
		mvaddstrAlt(10,  0, "How should ");
		addstrAlt(pool[p]->name);
		addstrAlt(" approach the situation?");
		if (ledger.get_funds() >= 100 && !pool[p]->clinic)set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(11,  0, "A - Spend a hundred bucks tonight to get the ball rolling.");
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(12,  0, "B - Try to get through the evening without spending a penny.");
		if (!pool[p]->clinic&&pool[p]->blood == 100)set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		moveAlt(13, 0);
		if (pool[p]->blood == 100) addstrAlt("C - Spend a week on a cheap vacation (stands up any other dates).");
		else addstrAlt("C - Spend a week on a cheap vacation (must be uninjured).");
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(14,  0, "D - Break it off.");
		if (d.date[e]->align == -1 && !pool[p]->clinic)
		{
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(15,  0, "E - Just kidnap the Conservative bitch.");
		}
		int thingsincommon = 0;
		for (int s = 0; s < SKILLNUM; s++)
			if (d.date[e]->get_skill(s) >= 1 && pool[p]->get_skill(s) >= 1)
				//Has a skill that is at least half the same skill of the other person on the date.
				if (d.date[e]->get_skill(s) <= pool[p]->get_skill(s) * 2)
					thingsincommon++;
		while (true)
		{
			int c = getkeyAlt();
			short aroll = pool[p]->skill_roll(SKILL_SEDUCTION);
			short troll = d.date[e]->attribute_roll(ATTRIBUTE_WISDOM);
			if (d.date[e]->align == ALIGN_CONSERVATIVE)
				troll += troll*(d.date[e]->juice / 100);
			// Even liberals and moderates shouldn't be TOO easy to seduce! -- SlatersQuest
			else if (d.date[e]->align == ALIGN_MODERATE)
				troll += troll*(d.date[e]->juice / 150);
			else troll += troll*(d.date[e]->juice / 200);
			char test = 0;
			aroll += thingsincommon * 3;
			if (c == 'a'&&ledger.get_funds() >= 100 && !pool[p]->clinic)
			{
				ledger.subtract_funds(100, EXPENSE_DATING);
				aroll += LCSrandom(10);
				test = true;
			}
			else if (c == 'b') test = true;
			if (test)
			{
				pool[p]->train(SKILL_SEDUCTION, LCSrandom(4) + 5);
				pool[p]->train(SKILL_SCIENCE,
					max(d.date[e]->get_skill(SKILL_SCIENCE) - pool[p]->get_skill(SKILL_SCIENCE), 0));
				pool[p]->train(SKILL_RELIGION,
					max(d.date[e]->get_skill(SKILL_RELIGION) - pool[p]->get_skill(SKILL_RELIGION), 0));
				pool[p]->train(SKILL_BUSINESS,
					max(d.date[e]->get_skill(SKILL_BUSINESS) - pool[p]->get_skill(SKILL_BUSINESS), 0));
				if (d.date[e]->get_skill(SKILL_BUSINESS))
				{
					troll += d.date[e]->skill_roll(SKILL_BUSINESS);
					aroll += pool[p]->skill_roll(SKILL_BUSINESS);
				}
				if (d.date[e]->get_skill(SKILL_RELIGION))
				{
					troll += d.date[e]->skill_roll(SKILL_RELIGION);
					aroll += pool[p]->skill_roll(SKILL_RELIGION);
				}
				if (d.date[e]->get_skill(SKILL_SCIENCE))
				{
					troll += d.date[e]->skill_roll(SKILL_SCIENCE);
					aroll += pool[p]->skill_roll(SKILL_SCIENCE);
				}
				int y = 17;
				if (dateresult(aroll, troll, d, e, p, y) == DATERESULT_ARRESTED) return 1;
				break;
			}
			if (c == 'c'&&!pool[p]->clinic&&pool[p]->blood == 100)
			{
				for (int e2 = len(d.date) - 1; e2 >= 0; e2--)
				{
					if (e2 == e) continue;
					delete_and_remove(d.date, e2);
					e = 0;
				}
				d.timeleft = 7;
				pool[p]->train(SKILL_SEDUCTION, LCSrandom(40) + 15);
				pool[p]->train(SKILL_SCIENCE,
					max((d.date[e]->get_skill(SKILL_SCIENCE) - pool[p]->get_skill(SKILL_SCIENCE)) * 4, 0));
				pool[p]->train(SKILL_RELIGION,
					max((d.date[e]->get_skill(SKILL_RELIGION) - pool[p]->get_skill(SKILL_RELIGION)) * 4, 0));
				pool[p]->train(SKILL_BUSINESS,
					max((d.date[e]->get_skill(SKILL_BUSINESS) - pool[p]->get_skill(SKILL_BUSINESS)) * 4, 0));
				return 0;
			}
			if (c == 'd')
			{
				delete_and_remove(d.date, e);
				break;
			}
			if (c == 'e'&&d.date[e]->align == -1 && !pool[p]->clinic)
			{
				set_color_easy(YELLOW_ON_BLACK_BRIGHT);
				int bonus = 0;
				mvaddstrAlt(17,  0, pool[p]->name, gamelog);
				if (pool[p]->get_weapon().is_ranged())
				{
					addstrAlt(" comes back from the bathroom toting the ", gamelog);
					addstrAlt(pool[p]->get_weapon().get_name(1), gamelog);
					mvaddstrAlt(18,  0, "and threatens to blow the Conservative's brains out!", gamelog);
					gamelog.newline();
					bonus = 5;
				}
				else if (pool[p]->is_armed())
				{
					addstrAlt(" grabs the Conservative from behind, holding the ", gamelog);
					addstrAlt(pool[p]->get_weapon().get_name(1), gamelog);
					mvaddstrAlt(18,  0, "to the corporate slave's throat!", gamelog);
					gamelog.newline();
					if (pool[p]->get_weapon().can_take_hostages())
						bonus = 5;
					else bonus = -1; // Conservative emboldened by the fact that you're trying
				}                 // to kidnap them with a gavel or some shit like that
				else
				{
					addstrAlt(" seizes the Conservative swine from behind and warns it", gamelog);
					moveAlt(18, 0);
					if (lawList[LAW_FREESPEECH] != -2)
						addstrAlt("not to fuck around!", gamelog);
					else
						addstrAlt("not to [resist]!", gamelog);
					gamelog.newline();
					bonus += pool[p]->get_skill(SKILL_HANDTOHAND) - 1;
				}
				getkeyAlt();
				// Kidnap probably succeeds if the conservative isn't very dangerous,
				// but fails 15 times as often if the conservative is tough stuff.
				if ((!d.date[e]->kidnap_resistant() &&
					LCSrandom(15)) ||
					LCSrandom(2 + bonus))
				{
					set_color_easy(GREEN_ON_BLACK_BRIGHT);
					mvaddstrAlt(20,  0, d.date[e]->name, gamelog);
					if (bonus)
					{
						addstrAlt(" doesn't resist.", gamelog);
						gamelog.newline();
					}
					else
					{
						addstrAlt(" struggles and yells for help, but nobody comes.", gamelog);
						gamelog.newline();
					}
					getkeyAlt();
					mvaddstrAlt(22,  0, pool[p]->name, gamelog);
					addstrAlt(" kidnaps the Conservative!", gamelog);
					gamelog.nextMessage();
					getkeyAlt();
					d.date[e]->namecreature();
					strcpy(d.date[e]->propername, d.date[e]->name);
					d.date[e]->location = pool[p]->location;
					d.date[e]->base = pool[p]->base;
					d.date[e]->flag |= CREATUREFLAG_MISSING;
					//Kidnapped wearing normal clothes and no weapon
					d.date[e]->drop_weapons_and_clips(NULL);
					Armor clothes(*armortype[getarmortype(tag_ARMOR_CLOTHES)]);
					d.date[e]->give_armor(clothes, NULL);
					//Create interrogation data
					d.date[e]->activity.intr() = new interrogation;
					eraseAlt();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(0,  0, "The Education of ");
					addstrAlt(d.date[e]->propername);
					set_color_easy(WHITE_ON_BLACK);
					mvaddstrAlt(2,  0, "What name will you use for this ");
					addstrAlt(d.date[e]->get_type_name());
					addstrAlt(" in its presence?");
					mvaddstrAlt(3,  0, "If you do not enter anything, their real name will be used.");
					enter_name(4, 0, d.date[e]->name, CREATURE_NAMELEN, d.date[e]->propername);
					addCreature(d.date[e]);
					stat_kidnappings++;
					d.date.erase(d.date.begin() + e);
					break;
				}
				else
				{
					int y = 20;
					if (LCSrandom(2))
					{
						set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
						mvaddstrAlt(y++,  0, d.date[e]->name, gamelog);
						addstrAlt(" manages to get away on the way back to the safehouse!", gamelog);
						gamelog.newline();
						getkeyAlt();
						mvaddstrAlt((++y)++,  0, pool[p]->name, gamelog);
						addstrAlt(" has failed to kidnap the Conservative.", gamelog);
						gamelog.nextMessage();
						// Charge with kidnapping
						criminalize(*pool[p], LAWFLAG_KIDNAPPING);
						getkeyAlt();
						delete_and_remove(d.date, e);
						break;
					}
					else
					{
						set_color_easy(RED_ON_BLACK_BRIGHT);
						mvaddstrAlt(y++,  0, d.date[e]->name, gamelog);
						addstrAlt("'s fist is the last thing ", gamelog);
						addstrAlt(pool[p]->name, gamelog);
						addstrAlt(" remembers seeing!", gamelog);
						gamelog.newline();
						getkeyAlt();
						mvaddstrAlt((++y)++,  0, "The Liberal wakes up in the police station...", gamelog);
						gamelog.nextMessage();
						// Find the police station
						int ps = find_site_index_in_same_city(SITE_GOVERNMENT_POLICESTATION, pool[p]->location); 
						// Arrest the Liberal
						removesquadinfo(*pool[p]);
						pool[p]->carid = -1;
						pool[p]->location = ps;
						pool[p]->drop_weapons_and_clips(NULL);
						pool[p]->activity.type = ACTIVITY_NONE;
						// Charge with kidnapping
						criminalize(*pool[p], LAWFLAG_KIDNAPPING);
						getkeyAlt();
						delete_and_remove(d.date, e);
						return 1;
					}
				}
			}
		}
	}
	if (len(d.date))
	{
		d.timeleft = 0;
		return 0;
	}
	else return 1;
}
