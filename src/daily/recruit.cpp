#include "../includes.h"
const string CONST_recruit013 = "Adventures in Liberal Recruitment";
const string CONST_recruit012 = "Press enter or escape to call it a day.";
const string CONST_recruit011 = " - ";
const string CONST_recruit010 = " was able to get information on multiple people.";
const string CONST_recruit007 = " managed to set up a meeting with ";
const string CONST_recruit006A = " was unable to track down a ";
const string CONST_recruit006B = ".";
const string CONST_recruit005A = " asks around for a ";
const string CONST_recruit005B = "...";
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

const string blankString = "";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"

#include "../creature/deprecatedCreatureB.h"
//#include "../creature/deprecatedCreatureC.h"
//#include "../creature/deprecatedCreatureD.h"

////
#include "../items/armortype.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../basemode/activate.h"
// for recruitFindDifficulty and recruitName
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
#include "../common/commondisplayCreature.h"
// for void printcreatureinfo(Creature *,unsigned char=255)
#include "../common/getnames.h"
// for getview
//#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
// for subordinatesleft
#include "../combat/fight.h"

#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include "../common/musicClass.h"

/* recruit struct constructor */

#include "../combat/fight.h"

/*const string CONST_recruit013 = "Adventures in Liberal Recruitment";
const string CONST_recruit012 = "Press enter or escape to call it a day.";
const string CONST_recruit011 = "%c - ";
const string CONST_recruit010 = "%s was able to get information on multiple people.";
const string CONST_recruit007 = "%s managed to set up a meeting with ";
const string CONST_recruit006 = "%s was unable to track down a %s.";
const string CONST_recruit005 = "%s asks around for a %s...";
*/
char talk(DeprecatedCreature &a, const int t);

Deprecatedrecruitst::Deprecatedrecruitst(DeprecatedCreature *cr, int id) {
	extern short attitude[VIEWNUM];
	recruit = cr;
	recruiter_id = id;
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
Deprecatedrecruitst::~Deprecatedrecruitst()
{
	delete recruit;
}
char Deprecatedrecruitst::eagerness()
{
	char eagerness_temp = eagerness1;
	//Moderates are decidedly less interested
	if (recruit->align == 0) eagerness_temp -= 2;
	//Conservatives are extremely uninterested
	if (recruit->align == -1) eagerness_temp -= 4;
	return eagerness_temp;
}
//extern string singleDot;
void makecreature(const int x, const short type);
/* recruiting */
vector<RecruitData> recruitable_creatures;
// Return the difficulty of tracking this character type down, for the
// purpose of the activation menu. 0 is trivial, 10 is impossible.
int recruitFindDifficulty(int creatureType)
{
	for (int i = 0; i < len(recruitable_creatures); i++)
		if (recruitable_creatures[i].type == creatureType)
			return recruitable_creatures[i].difficulty;
	return 10; // No RecruitData; assume impossible to recruit
}
string recruitName(int creatureType) {

	const string CONST_activate065 = "missingno";
	for (int i = 0; i < len(recruitable_creatures); i++)
		if (recruitable_creatures[i].type == creatureType)
			return recruitable_creatures[i].name;
	return CONST_activate065;
}
const string singleDot = ".";
void recruitment_activity(DeprecatedCreature &cr)
{
	extern MusicClass music;
	extern short cursite;
	extern DeprecatedCreature encounter[ENCMAX];
	int ocursite = cursite;
	cursite = cr.location;
	int type = cr.activity.arg;
	int difficulty = recruitFindDifficulty(type);
	string name = recruitName(type);
	if (type >= 0)
	{
		music.play(MUSIC_RECRUITING);
		cr.train(SKILL_STREETSENSE, 5);
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0, 0, CONST_recruit013);
		printcreatureinfo(&cr);
		makedelimiter();
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(10, 0, cr.name + CONST_recruit005A + name + CONST_recruit005B);
		pressAnyKey();
		int recruitCount = 0;
		if (difficulty < 10)
			// Generate recruitment candidates
			for (recruitCount = 0; recruitCount < 5; recruitCount++)
			{
				if (recruitCount == 0 || cr.skill_roll(SKILL_STREETSENSE) >(difficulty + recruitCount * 2))
				{
					makecreature(recruitCount, type);
					encounter[recruitCount].namecreature();
				}
				else break;
			}
		if (recruitCount == 0) {
			mvaddstrAlt(11, 0, cr.name + CONST_recruit006A + name + CONST_recruit006B);
			pressAnyKey();
			cursite = ocursite;
			return;
		}
		else if (recruitCount == 1) {
			mvaddstrAlt(11, 0, cr.name + CONST_recruit007);
			set_alignment_color(encounter[0].align);
			addstrAlt(encounter[0].name);
			add_age(encounter[0]);
			set_color_easy(WHITE_ON_BLACK);
			addstrAlt(singleDot);
			pressAnyKey();
			eraseAlt();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(0, 0, CONST_recruit013);
			printcreatureinfo(&encounter[0]);
			makedelimiter();
			talk(cr, 0);
		}
		else {
			while (true)
			{
				eraseAlt();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(0, 0, CONST_recruit013);
				printcreatureinfo(&cr);
				makedelimiter();
				set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(10, 0, cr.name + CONST_recruit010);
				for (int i = 0; i < recruitCount; i++) {
					set_color_easy(WHITE_ON_BLACK);
					mvaddstrAlt(12 + i, 0, char('a' + i) + CONST_recruit011);
					set_alignment_color(encounter[i].align);
					addstrAlt(encounter[i].name);
					add_age(encounter[i]);
				}
				set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(12 + recruitCount + 1, 0, CONST_recruit012);
				int c = getkeyAlt();
				if (c == ENTER || c == ESC) break;
				c -= 'a';
				if (c >= 0 && c < ENCMAX - 1 && encounter[c].exists)
				{
					int id = encounter[c].id;
					eraseAlt();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(0, 0, CONST_recruit013);
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
}
