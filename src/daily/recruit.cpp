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

#include <includes.h>
#include "creature/creature.h"

#include "common/ledgerEnums.h"
#include "common/ledger.h"

#include "basemode/activate.h"
// for recruitFindDifficulty and recruitName

#include "common/consolesupport.h"
// for void set_color(short,short,bool)

#include "log/log.h"
// for commondisplay.h
#include "common/commondisplay.h"
#include "common/commondisplayCreature.h"
// for void printcreatureinfo(Creature *,unsigned char=255)

#include "common/getnames.h"
// for getview

//#include "common/commonactions.h"
#include "common/commonactionsCreature.h"
// for subordinatesleft

#include "combat/fight.h"
//for void delenc(short e,char loot);

char talk(Creature &a, const int t);


#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
#include "common/musicClass.h"
extern MusicClass music;
extern short cursite;
extern short attitude[VIEWNUM];
extern Creature encounter[ENCMAX];
extern class Ledger ledger;
/* recruit struct constructor */
recruitst::recruitst() : timeleft(0), level(0), eagerness1(0), task(0)
{
	//Has heard of the LCS
	if ((int)LCSrandom(100) < attitude[VIEW_LIBERALCRIMESQUAD])
	{
		//Likes the LCS
		if ((int)LCSrandom(100) < attitude[VIEW_LIBERALCRIMESQUADPOS])
			eagerness1 = 3;
		//Doesn't like the LCS
		else eagerness1 = 0;
	}
	else eagerness1 = 2;
}
recruitst::~recruitst()
{
	delete recruit;
}
char recruitst::eagerness()
{
	char eagerness_temp = eagerness1;
	//Moderates are decidedly less interested
	if (recruit->align == 0) eagerness_temp -= 2;
	//Conservatives are extremely uninterested
	if (recruit->align == -1) eagerness_temp -= 4;
	return eagerness_temp;
}
extern string singleDot;
/* recruiting */
char recruitment_activity(Creature &cr, char &clearformess)
{
	clearformess = 1;
	int ocursite = cursite;
	cursite = cr.location;
	int type = cr.activity.arg;
	int difficulty = recruitFindDifficulty(type);
	char* name = recruitName(type);
	if (type >= 0)
	{
		music.play(MUSIC_RECRUITING);
		cr.train(SKILL_STREETSENSE, 5);
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0,  0, "Adventures in Liberal Recruitment");
		printcreatureinfo(&cr);
		makedelimiter();
		set_color_easy(WHITE_ON_BLACK);
		mvaddstr_f(10, 0, "%s asks around for a %s...", cr.name, name);
		getkeyAlt();
		int recruitCount = 0;
		if (difficulty < 10)
			// Generate recruitment candidates
			for (recruitCount = 0; recruitCount<5; recruitCount++)
			{
				if (recruitCount == 0 || cr.skill_roll(SKILL_STREETSENSE)>(difficulty + recruitCount * 2))
				{
					makecreature(encounter[recruitCount], type);
					encounter[recruitCount].namecreature();
				}
				else break;
			}
		if (recruitCount == 0) {
			mvaddstr_f(11, 0, "%s was unable to track down a %s.", cr.name, name);
			getkeyAlt();
			cursite = ocursite;
			return 0;
		}
		else if (recruitCount == 1) {
			mvaddstr_f(11, 0, "%s managed to set up a meeting with ", cr.name);
			set_alignment_color(encounter[0].align);
			addstrAlt(encounter[0].name);
			add_age(encounter[0]);
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt(singleDot);
			getkeyAlt();
			eraseAlt();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(0,  0, "Adventures in Liberal Recruitment");
			printcreatureinfo(&encounter[0]);
			makedelimiter();
			talk(cr, 0);
		}
		else {
			while (true)
			{
				eraseAlt();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(0,  0, "Adventures in Liberal Recruitment");
				printcreatureinfo(&cr);
				makedelimiter();
				set_color_easy(WHITE_ON_BLACK);
				mvaddstr_f(10, 0, "%s was able to get information on multiple people.", cr.name);
				for (int i = 0; i < recruitCount; i++) {
					set_color_easy(WHITE_ON_BLACK);
					mvaddstr_f(12 + i, 0, "%c - ", 'a' + i);
					set_alignment_color(encounter[i].align);
					addstrAlt(encounter[i].name);
					add_age(encounter[i]);
				}
				set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(12 + recruitCount + 1, 0, "Press enter or escape to call it a day.");
				int c = getkeyAlt();
				if (c == ENTER || c == ESC) break;
				c -= 'a';
				if (c >= 0 && c < ENCMAX - 1 && encounter[c].exists)
				{
					int id = encounter[c].id;
					eraseAlt();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(0,  0, "Adventures in Liberal Recruitment");
					printcreatureinfo(&encounter[c]);
					makedelimiter();
					talk(cr, c);
					if (encounter[c].id == id) delenc(c, 0);
					recruitCount--;
					if (recruitCount <= 0) break;
				}
			}
		}
	}
	cursite = ocursite;
	return 1;
}
