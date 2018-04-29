#include "../includes.h"
const string CONST_haulkidnap035 = " hauls ";
const string CONST_haulkidnap034 = " is left to be captured.";
const string CONST_haulkidnap033 = "Nobody can carry Martyr ";
const string CONST_haulkidnap032 = " can no longer handle ";
const string CONST_haulkidnap031 = "                                  ";
const string CONST_haulkidnap030 = "The hostage shouts for help!      ";
const string CONST_haulkidnap029 = "release their hostage.";
const string CONST_haulkidnap027 = "No hostages are being held.       ";
const string CONST_haulkidnap026 = "                                                     ";
const string CONST_haulkidnap025 = "All of the targets are too dangerous.                ";
const string CONST_haulkidnap024 = "Kidnap whom?";
const string CONST_haulkidnap023 = "do the job.";
const string CONST_haulkidnap021 = "No one can do the job.            ";
const string CONST_haulkidnap020 = " is captured.";
const string CONST_haulkidnap019 = " is recaptured.";
const string CONST_haulkidnap018 = "A hostage escapes!";
const string CONST_haulkidnap017 = " is captured";
const string CONST_haulkidnap016 = " is recaptured";
const string CONST_haulkidnap015 = " and a hostage is freed";
const string CONST_haulkidnap012 = "and says, ";
const string CONST_haulkidnap011 = " the ";
const string CONST_haulkidnap010 = " shows ";
const string CONST_haulkidnap009 = " writhes away!";
const string CONST_haulkidnap008 = "but ";
const string CONST_haulkidnap007 = " grabs at ";
const string CONST_haulkidnap006 = " is struggling and screaming!";
const string CONST_haulkidnap005 = "!";
const string CONST_haulkidnap004 = " snatches ";
const string CONST_haulkidnapX01 = "\"[Please], be cool.\"";
const string CONST_haulkidnapX02 = "\"Bitch, be cool.\"";
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
//TODO: This file probably shouldn't have any nextMessage calls in it.
//That will depend on the chase and fight code, I think...And the code that
//handles the squad moving around the site. For now, this'll do. I must remember
//to come back here and finish the job.

const string blankString = "";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
#include "../creature/creature.h"
#include "../sitemode/advance.h"
// for creatureadvance
#include "../sitemode/stealth.h"
#include "../sitemode/sitedisplay.h"
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
// for printparty
//#include "../common/commonactions.h"
void criminalizeparty(short crime);
//#include "../common/commonactionsCreature.h"
void removesquadinfo(Creature &cr);
#include "../combat/fight.h"
#include "../combat/fightCreature.h"  
//for void enemyattack();
#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include "../common/creaturePoolCreature.h"
extern Log gamelog;
extern string chooseALiberalTo;
extern string AND;
extern string spaceDashSpace;
extern string singleDot;
extern int stat_kidnappings;
extern short mode;
extern squadst *activesquad;
extern short party_status;
extern Creature encounter[ENCMAX];
extern short lawList[LAWNUM];
extern short sitealarm;
extern short sitealarmtimer;
extern int sitecrime;
extern short offended_amradio;
extern short offended_cablenews;
extern string singleSpace;
/* roll on the kidnap attempt and show the results */
bool kidnap(Creature &a, Creature &t, bool &amateur)
{
	if (!a.get_weapon().can_take_hostages())
	{
		amateur = 1;
		//BASIC ROLL
		int aroll = a.skill_roll(SKILL_HANDTOHAND);
		int droll = t.attribute_check(ATTRIBUTE_AGILITY, true);
		a.train(SKILL_HANDTOHAND, droll);
		clearmessagearea();
		//HIT!
		if (aroll > droll)
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(16, 1, a.name, gamelog);
			addstrAlt(CONST_haulkidnap004, gamelog);
			addstrAlt(t.name, gamelog);
			addstrAlt(CONST_haulkidnap005, gamelog);
			gamelog.newline(); //New line.
			a.prisoner = new Creature;
			*a.prisoner = t;
	 	pressAnyKey();
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(17, 1, t.name, gamelog);
			addstrAlt(CONST_haulkidnap006, gamelog);
			gamelog.newline(); //New line.
	 	pressAnyKey();
			gamelog.newline();
			return 1;
		}
		else
		{
			set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
			mvaddstrAlt(16, 1, a.name, gamelog);
			addstrAlt(CONST_haulkidnap007, gamelog);
			addstrAlt(t.name, gamelog);
			gamelog.newline(); //New line.
			mvaddstrAlt(17, 1, CONST_haulkidnap008, gamelog);
			addstrAlt(t.name, gamelog);
			addstrAlt(CONST_haulkidnap009, gamelog);
			gamelog.newline(); //New line.
	 	pressAnyKey();
			gamelog.newline();
			return 0;
		}
	}
	else
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, a.name, gamelog);
		addstrAlt(CONST_haulkidnap010, gamelog);
		addstrAlt(t.name, gamelog);
		addstrAlt(CONST_haulkidnap011, gamelog);
		addstrAlt(a.get_weapon().get_name(2), gamelog);
		addstrAlt(singleSpace, gamelog);
		mvaddstrAlt(17, 1, CONST_haulkidnap012, gamelog);
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		if (lawList[LAW_FREESPEECH] == -2)addstrAlt(CONST_haulkidnapX01, gamelog);
		else addstrAlt(CONST_haulkidnapX02, gamelog);
		a.prisoner = new Creature;
		*a.prisoner = t;
 	pressAnyKey();
		gamelog.newline();
		return 1;
	}
}
/* hostage freed due to host unable to haul */
void freehostage(Creature &cr, char situation)
{
	if (cr.prisoner == NULL)return;
	if (cr.prisoner->alive)
	{
		if (situation == 0)
		{
			if (cr.prisoner->squadid == -1)addstrAlt(CONST_haulkidnap015, gamelog);
			else
			{
				addstrAlt(AND, gamelog);
				addstrAlt(cr.prisoner->name, gamelog);
				if (cr.prisoner->flag & CREATUREFLAG_JUSTESCAPED)addstrAlt(CONST_haulkidnap016, gamelog);
				else addstrAlt(CONST_haulkidnap017, gamelog);
			}
			gamelog.newline(); //New line.
		}
		else if (situation == 1)
		{
			clearmessagearea();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			if (cr.prisoner->squadid == -1)mvaddstrAlt(16, 1, CONST_haulkidnap018, gamelog);
			else
			{
				mvaddstrAlt(16, 1, cr.prisoner->name, gamelog);
				if (cr.prisoner->flag & CREATUREFLAG_JUSTESCAPED)addstrAlt(CONST_haulkidnap019, gamelog);
				else addstrAlt(CONST_haulkidnap020, gamelog);
			}
			gamelog.newline(); //New line.
		}
		else if (situation == 2)
		{
			//Don't print anything.
		}
		if (cr.prisoner->squadid == -1)
		{
			for (int e = 0; e < ENCMAX; e++)
			{
				if (encounter[e].exists == 0)
				{
					encounter[e] = *cr.prisoner;
					encounter[e].exists = 1;
					conservatise(encounter[e]);
					break;
				}
			}
			delete cr.prisoner;
		}
		else capturecreature(*cr.prisoner);
	}
	else
	{
		if (cr.prisoner->squadid != -1)
		{
			removesquadinfo(*cr.prisoner);
			cr.prisoner->die();
			cr.prisoner->location = -1;
		}
	}
	cr.prisoner = NULL;
	if (situation == 1)
	{
		printparty();
		if (mode == GAMEMODE_CHASECAR ||
			mode == GAMEMODE_CHASEFOOT) printchaseencounter();
		else printencounter();
 	pressAnyKey();
	}
}
/* prompt after you've said you want to kidnap someone */
void kidnapattempt()
{
	short kidnapper = -1;
	party_status = -1;
	int available = 0;
	char availslot[6] = { 0,0,0,0,0,0 };
	for (int p = 0; p < 6; p++)
		if (activesquad->squad[p] != NULL)
			if (activesquad->squad[p]->alive&&activesquad->squad[p]->prisoner == NULL)
			{
				available++;
				availslot[p] = 1;
			}
	if (!available)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, CONST_haulkidnap021);
		mvaddstrAlt(17,  1, CONST_haulkidnap031);
 	pressAnyKey();
		return;
	}
	do
	{
		printparty();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8,  20, chooseALiberalTo + CONST_haulkidnap023);
		int c = getkeyAlt();
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) return;
		if (c >= '1'&&c <= '6')
			if (availslot[c - '1'])
				kidnapper = c - '1';
	} while (kidnapper < 0);
	vector<int> target;
	for (int e = 0; e < ENCMAX; e++)
		if (encounter[e].exists&&encounter[e].alive&&encounter[e].align == -1 &&
			(encounter[e].animalgloss == ANIMALGLOSS_NONE || lawList[LAW_ANIMALRESEARCH] == 2) &&
			(!encounter[e].get_weapon().protects_against_kidnapping() ||
				encounter[e].blood <= 20) && encounter[e].animalgloss != ANIMALGLOSS_TANK)
			target.push_back(e);
	if (len(target))
	{
		int t = target[0];
		if (len(target) > 1)
		{
			clearcommandarea();
			clearmessagearea();
			clearmaparea();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(9,  1, CONST_haulkidnap024);
			int x = 1, y = 11;
			for (int t2 = 0; t2 < len(target); t2++)
			{
				mvaddcharAlt(y++, x, t2 + 'A');
				addstrAlt(spaceDashSpace);
				addstrAlt(encounter[target[t2]].name);
				if (y == 17) y = 11, x += 30;
			}
			do
			{
				int c = getkeyAlt();
				if (c >= 'a'&&c < ('a' + ENCMAX))
				{
					t = c - 'a';
					if (t >= len(target)) t = -1;
					else t = target[t];
				}
				if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) return;
			} while (t < 0);
		}
		bool amateur = 0;
		if (kidnap(*activesquad->squad[kidnapper], encounter[t], amateur))
		{
			delenc(t, 0);
			int time = 20 + LCSrandom(10);
			if (time < 1) time = 1;
			if (sitealarmtimer > time || sitealarmtimer == -1) sitealarmtimer = time;
		}
		else sitealarm = 1;
		if (amateur)
		{
			bool present = 0;
			for (int e = 0; e < ENCMAX; e++)
				if (encounter[e].exists&&encounter[e].alive) { present = 1; break; }
			if (present)
			{
				alienationcheck(1);
				if (!sitealarm)sitealarm = 1;
				sitecrime += 5;
				criminalizeparty(LAWFLAG_KIDNAPPING);
				if (activesquad->squad[kidnapper]->prisoner != NULL)
				{
					if (activesquad->squad[kidnapper]->prisoner->type == CREATURE_RADIOPERSONALITY) offended_amradio = 1;
					if (activesquad->squad[kidnapper]->prisoner->type == CREATURE_NEWSANCHOR) offended_cablenews = 1;
				}
				else
				{
					if (encounter[t].type == CREATURE_RADIOPERSONALITY) offended_amradio = 1;
					if (encounter[t].type == CREATURE_NEWSANCHOR) offended_cablenews = 1;
				}
			}
		}
		if (sitealarm) enemyattack();
		creatureadvance();
	}
	else
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, CONST_haulkidnap025);
		mvaddstrAlt(17,  1, CONST_haulkidnap026);
 	pressAnyKey();
	}
}
/* prompt after you've said you want to release someone */
void releasehostage()
{
	short kidnapper = -1;
	party_status = -1;
	int available = 0;
	char availslot[6] = { 0,0,0,0,0,0 };
	for (int p = 0; p < 6; p++)
		if (activesquad->squad[p] != NULL)
			if (activesquad->squad[p]->alive&&activesquad->squad[p]->prisoner != NULL&&activesquad->squad[p]->prisoner->align != ALIGN_LIBERAL)
				available++, availslot[p] = 1;
	if (!available)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, CONST_haulkidnap027);
		mvaddstrAlt(17,  1, CONST_haulkidnap031);
 	pressAnyKey();
		return;
	}
	do
	{
		printparty();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8,  20, chooseALiberalTo + CONST_haulkidnap029);
		int c = getkeyAlt();
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) return;
		if (c >= '1'&&c <= '6')
			if (availslot[c - '1'])
				kidnapper = c - '1';
	} while (kidnapper < 0);
	activesquad->squad[kidnapper]->prisoner->cantbluff = 2;
	freehostage(*(activesquad->squad[kidnapper]), 2);
	if (!sitealarm)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, CONST_haulkidnap030, gamelog);
		gamelog.nextMessage(); //Next message.
		mvaddstrAlt(17,  1, CONST_haulkidnap031);
 	pressAnyKey();
		sitealarm = 1;
		alienationcheck(1);
	}
}
/* haul dead/paralyzed */
void squadgrab_immobile(char dead)
{
	int p, hostslots = 0; //DRAGGING PEOPLE OUT IF POSSIBLE
	for (p = 0; p < 6; p++)
	{
		if (activesquad->squad[p] != NULL)
		{
			if (activesquad->squad[p]->alive &&
				(activesquad->squad[p]->canwalk() ||
					(activesquad->squad[p]->flag & CREATUREFLAG_WHEELCHAIR)) &&
				activesquad->squad[p]->prisoner == NULL)
				hostslots++;
			else if ((!activesquad->squad[p]->alive ||
				(!activesquad->squad[p]->canwalk() &&
					!(activesquad->squad[p]->flag & CREATUREFLAG_WHEELCHAIR))) &&
				activesquad->squad[p]->prisoner != NULL)
			{
				clearmessagearea();
				set_color_easy(YELLOW_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, activesquad->squad[p]->name, gamelog);
				addstrAlt(CONST_haulkidnap032, gamelog);
				addstrAlt(activesquad->squad[p]->prisoner->name, gamelog);
				addstrAlt(singleDot, gamelog);
				gamelog.newline(); //New line.
		 	pressAnyKey();
				freehostage(*activesquad->squad[p]->prisoner, 1);
			}
		}
	}
	for (p = 5; p >= 0; p--)
	{
		if (activesquad->squad[p] != NULL)
		{
			if ((!activesquad->squad[p]->alive&&dead) ||
				(activesquad->squad[p]->alive&&
					!(activesquad->squad[p]->flag & CREATUREFLAG_WHEELCHAIR) &&
					!activesquad->squad[p]->canwalk() && !dead))
			{
				if (hostslots == 0)
				{
					if (!activesquad->squad[p]->alive)
					{
						clearmessagearea();
						set_color_easy(YELLOW_ON_BLACK_BRIGHT);
						mvaddstrAlt(16,  1, CONST_haulkidnap033, gamelog);
						addstrAlt(activesquad->squad[p]->name, gamelog);
						addstrAlt(singleDot, gamelog);
						gamelog.newline();
						//DROP LOOT
						makeloot(*activesquad->squad[p]);
						activesquad->squad[p]->die();
						activesquad->squad[p]->location = -1;
					}
					else
					{
						clearmessagearea();
						set_color_easy(YELLOW_ON_BLACK_BRIGHT);
						mvaddstrAlt(16,  1, activesquad->squad[p]->name, gamelog);
						addstrAlt(CONST_haulkidnap034, gamelog);
						gamelog.newline(); //New line.
						capturecreature(*activesquad->squad[p]);
					}
				}
				else
				{
					for (int p2 = 0; p2 < 6; p2++)
					{
						if (p2 == p) continue;
						if (activesquad->squad[p2] != NULL)
						{
							if (activesquad->squad[p2]->alive &&
								(activesquad->squad[p2]->canwalk() ||
									(activesquad->squad[p2]->flag & CREATUREFLAG_WHEELCHAIR)) &&
								activesquad->squad[p2]->prisoner == NULL)
							{
								activesquad->squad[p2]->prisoner = activesquad->squad[p];
								clearmessagearea();
								set_color_easy(YELLOW_ON_BLACK_BRIGHT);
								mvaddstrAlt(16,  1, activesquad->squad[p2]->name, gamelog);
								addstrAlt(CONST_haulkidnap035, gamelog);
								addstrAlt(activesquad->squad[p]->name, gamelog);
								addstrAlt(singleDot, gamelog);
								gamelog.newline(); //New line.
								break;
							}
						}
					}
					hostslots--;
				}
				//SHUFFLE SQUAD
				bool flipstart = 0;
				for (int pt = 0; pt < 6; pt++)
				{
					if (pt == p - 1) continue;
					if (pt == p) flipstart = 1;
					if (flipstart&&pt < 5) activesquad->squad[pt] = activesquad->squad[pt + 1];
				}
				if (flipstart) activesquad->squad[5] = NULL;
				printparty();
		 	pressAnyKey();
			}
		}
	}
}