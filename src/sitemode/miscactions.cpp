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

//#include "sitemode/sitedisplay.h"
void clearmessagearea(bool redrawmaparea = true);

#include "log/log.h"

//#include "common/commondisplay.h"
void printparty();

#include "common/commonactions.h"
#include "common/commonactionsCreature.h"
// for void criminalizeparty

//#include "daily/daily.h"
char securityable(int type);
   

#include <cursesAlternative.h>
#include <set_color_support.h>
#include "locations/locationsPool.h"
extern Log gamelog;
 vector<string> was_abused;
 extern short cursite;
 extern squadst *activesquad;
 extern string singleSpace;
void fillEncounter(CreatureTypes c, int numleft);
extern string singleDot;
extern short fieldskillrate;
typedef map<short, string > shortAndString;
shortAndString discussIssues;
shortAndString discussesIssues;

extern short sitealarmtimer;
extern short sitealarm;
extern Creature encounter[ENCMAX];
extern short sitealienate;

char unlock(short type, char &actual)
{
	int p;
	int difficulty = 0;
	switch (type)
	{
	case UNLOCK_DOOR:
		if (securityable(LocationsPool::getInstance().getLocationType(cursite)) == 1)
			difficulty = DIFFICULTY_CHALLENGING;
		else if (securityable(LocationsPool::getInstance().getLocationType(cursite)) > 1)
			difficulty = DIFFICULTY_HARD;
		else
			difficulty = DIFFICULTY_EASY;
		break;
	case UNLOCK_CAGE:       difficulty = DIFFICULTY_VERYEASY; break;
	case UNLOCK_CAGE_HARD:  difficulty = DIFFICULTY_AVERAGE; break;
	case UNLOCK_CELL:       difficulty = DIFFICULTY_FORMIDABLE; break;
	case UNLOCK_ARMORY:     difficulty = DIFFICULTY_HEROIC; break;
	case UNLOCK_SAFE:       difficulty = DIFFICULTY_HEROIC; break;
	case UNLOCK_VAULT:      difficulty = DIFFICULTY_HEROIC; break;
	}
	int maxattack = -1;
	for (p = 0; p<6; p++)
	{
		if (activesquad->squad[p] != NULL)
		{
			if (activesquad->squad[p]->alive)
			{
				if (activesquad->squad[p]->get_skill(SKILL_SECURITY)>maxattack)
				{
					maxattack = activesquad->squad[p]->get_skill(SKILL_SECURITY);
				}
			}
		}
	}
	vector<int> goodp;
	for (p = 0; p < 6; p++)
	{
		if (activesquad->squad[p] != NULL)
		{
			if (activesquad->squad[p]->alive)
			{
				if (activesquad->squad[p]->get_skill(SKILL_SECURITY) == maxattack)
				{
					goodp.push_back(p);
				}
			}
		}
	}
	if (len(goodp))
	{
		int p = pickrandom(goodp);
		//lock pick succeeded.
		if (activesquad->squad[p]->skill_check(SKILL_SECURITY, difficulty))
		{
			//skill goes up in proportion to the chance of you failing.
			if (maxattack <= difficulty)
			{
				switch (fieldskillrate)
				{
				case FIELDSKILLRATE_FAST:
					activesquad->squad[p]->train(SKILL_SECURITY, 10 * difficulty); break;
				case FIELDSKILLRATE_CLASSIC:
					activesquad->squad[p]->train(SKILL_SECURITY, 1 + (difficulty - maxattack)); break;
				case FIELDSKILLRATE_HARD:
					activesquad->squad[p]->train(SKILL_SECURITY, 0); break;
				}
			}
			clearmessagearea(false);
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(16,  1, activesquad->squad[p]->name, gamelog);
			addstrAlt(singleSpace, gamelog);
			switch (type)
			{
			case UNLOCK_DOOR:addstrAlt("unlocks the door", gamelog); break;
			case UNLOCK_CAGE_HARD:
			case UNLOCK_CAGE:addstrAlt("unlocks the cage", gamelog); break;
			case UNLOCK_SAFE:addstrAlt("cracks the safe", gamelog); break;
			case UNLOCK_ARMORY:addstrAlt("opens the armory", gamelog); break;
			case UNLOCK_CELL:addstrAlt("unlocks the cell", gamelog); break;
			case UNLOCK_VAULT:addstrAlt("cracks the combo locks", gamelog); break;
			}
			addstrAlt("!", gamelog);
			gamelog.newline();
			for (int j = 0; j < 6; j++) //If people witness a successful unlock, they learn a little bit.
			{
				if (j == p) continue;
				if (activesquad->squad[j] != NULL&&
					activesquad->squad[j]->alive&&
					activesquad->squad[j]->get_skill(SKILL_SECURITY) < difficulty)
				{
					if (activesquad->squad[j]->alive)
					{
						switch (fieldskillrate)
						{
						case FIELDSKILLRATE_FAST:
							activesquad->squad[j]->train(SKILL_SECURITY, 5 * difficulty); break;
						case FIELDSKILLRATE_CLASSIC:
							activesquad->squad[j]->train(SKILL_SECURITY, difficulty - activesquad->squad[j]->get_skill(SKILL_SECURITY)); break;
						case FIELDSKILLRATE_HARD:
							activesquad->squad[j]->train(SKILL_SECURITY, 0); break;
						}
					}
				}
			}
			getkeyAlt();
			actual = 1;
			return 1;
		}
		else
		{
			clearmessagearea(false);
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			int i;
			//gain some experience for failing only if you could have succeeded.
			for (i = 0; i < 3; i++)
			{
				if (activesquad->squad[p]->skill_check(SKILL_SECURITY, difficulty))
				{
					switch (fieldskillrate)
					{
					case FIELDSKILLRATE_FAST:
						activesquad->squad[p]->train(SKILL_SECURITY, 50); break;
					case FIELDSKILLRATE_CLASSIC:
						activesquad->squad[p]->train(SKILL_SECURITY, 10); break;
					case FIELDSKILLRATE_HARD:
						activesquad->squad[p]->train(SKILL_SECURITY, 10); break;
					}
					mvaddstrAlt(16, 1, activesquad->squad[p]->name, gamelog);
					addstrAlt(" is close, but can't quite get the lock open.", gamelog);
					gamelog.newline();
					break;
				}
			}
			if (i == 3)
			{
				mvaddstrAlt(16, 1, activesquad->squad[p]->name, gamelog);
				addstrAlt(" can't figure the lock out.", gamelog);
				gamelog.newline();
			}
			getkeyAlt();
			actual = 1;
			return 0;
		}
	}
	else
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "You can't find anyone to do the job.", gamelog);
		gamelog.newline();
		getkeyAlt();
	}
	actual = 0;
	return 0;
}
/* bash attempt */
char bash(short type, char &actual)
{
	int difficulty = 0, p = 0;
	bool crowable = false;
	switch (type)
	{
	case BASH_DOOR:
		if (!securityable(LocationsPool::getInstance().getLocationType(cursite)))
		{
			difficulty = DIFFICULTY_EASY; // Run down dump
			crowable = true;
		}
		else if (LocationsPool::getInstance().getLocationType(cursite) != SITE_GOVERNMENT_PRISON&&
			LocationsPool::getInstance().getLocationType(cursite) != SITE_GOVERNMENT_INTELLIGENCEHQ)
		{
			difficulty = DIFFICULTY_CHALLENGING; // Respectable place
			crowable = true;
		}
		else
		{
			difficulty = DIFFICULTY_FORMIDABLE; // Very high security
			crowable = false;
		}
		break;
	}
	if (crowable)
	{
		//if(!squadhasitem(*activesquad,ITEM_WEAPON,WEAPON_CROWBAR))
		//{
		crowable = false;
		for (int p = 0; p < 6; p++)
		{
			if (activesquad->squad[p] != NULL)
			{
				if (activesquad->squad[p]->get_weapon().auto_breaks_locks())
					crowable = true;
			}
		}
		if (!crowable) //didn't find in hands of any squad member
		{
			for (int l = 0; l < len(activesquad->loot); l++)
			{
				if (activesquad->loot[l]->is_weapon())
				{
					Weapon *w = static_cast<Weapon*>(activesquad->loot[l]); //cast -XML
					if (w->auto_breaks_locks())
						crowable = true;
				}
			}
		}
		//}
	}
	int maxattack = 0, maxp = 0;
	if (!crowable)
	{
		for (p = 0; p<6; p++)
		{
			if (activesquad->squad[p] != NULL)
			{
				if (activesquad->squad[p]->alive)
				{
					if (activesquad->squad[p]->get_attribute(ATTRIBUTE_STRENGTH, true)*
						activesquad->squad[p]->get_weapon().get_bashstrengthmod()>maxattack)
					{
						maxattack = static_cast<int>(activesquad->squad[p]->get_attribute(ATTRIBUTE_STRENGTH, true)*
							activesquad->squad[p]->get_weapon().get_bashstrengthmod());
						maxp = p;
					}
				}
			}
		}
	}
	difficulty = static_cast<int>(difficulty / activesquad->squad[maxp]->get_weapon().get_bashstrengthmod());
	if (crowable || activesquad->squad[maxp]->attribute_check(ATTRIBUTE_STRENGTH, difficulty))
	{
		clearmessagearea(false);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, activesquad->squad[maxp]->name, gamelog);
		addstrAlt(singleSpace, gamelog);
		switch (type)
		{
		case BASH_DOOR:
			if (crowable) addstrAlt("uses a crowbar on the door", gamelog);
			else if (activesquad->squad[maxp]->get_weapon().get_bashstrengthmod() > 1)
				addstrAlt("smashes in the door", gamelog);
			else if (activesquad->squad[maxp]->flag&CREATUREFLAG_WHEELCHAIR)
				addstrAlt("rams open the door", gamelog);
			else addstrAlt("kicks in the door", gamelog);
			break;
		}
		addstrAlt("!", gamelog);
		gamelog.newline();
		getkeyAlt();
		int timer = 5;
		if (crowable) timer = 20;
		if (sitealarmtimer<0 || sitealarmtimer>timer)
			sitealarmtimer = timer;
		else sitealarmtimer = 0;
		//Bashing doors in secure areas sets off alarms
		if ((LocationsPool::getInstance().getLocationType(cursite) == SITE_GOVERNMENT_PRISON ||
			LocationsPool::getInstance().getLocationType(cursite) == SITE_GOVERNMENT_INTELLIGENCEHQ) &&
			sitealarm == 0)
		{
			sitealarm = 1;
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(17,  1, "Alarms go off!", gamelog);
			gamelog.newline();
			getkeyAlt();
		}
		actual = 1;
		return 1;
	}
	else
	{
		clearmessagearea(false);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, activesquad->squad[maxp]->name, gamelog);
		switch (type)
		{
		case BASH_DOOR:
			if (activesquad->squad[maxp]->flag&CREATUREFLAG_WHEELCHAIR)
				addstrAlt(" rams into the door", gamelog);
			else addstrAlt(" kicks the door", gamelog);
			break;
		}
		addstrAlt("!", gamelog);
		gamelog.newline();
		getkeyAlt();
		if (sitealarmtimer < 0) sitealarmtimer = 25;
		else if (sitealarmtimer>10) sitealarmtimer -= 10;
		else sitealarmtimer = 0;
		actual = 1;
		return 0;
	}
}
/* computer hack attempt */
char hack(short type, char &actual)
{
	int difficulty = 0;
	int p;
	switch (type)
	{
	case HACK_SUPERCOMPUTER:difficulty = DIFFICULTY_HEROIC; break;
	case HACK_VAULT:difficulty = DIFFICULTY_CHALLENGING; break;
	}
	int maxattack = 0, maxblindattack = -3, hacker = -1, blind = -1;
	for (p = 0; p < 6; p++) if (activesquad->squad[p] != NULL)
		if (activesquad->squad[p]->alive && activesquad->squad[p]->get_skill(SKILL_COMPUTERS))
		{
			int roll = activesquad->squad[p]->skill_roll(SKILL_COMPUTERS);
			if (!activesquad->squad[p]->special[SPECIALWOUND_RIGHTEYE] &&
				!activesquad->squad[p]->special[SPECIALWOUND_LEFTEYE])
			{  // we got a blind person here
				roll -= 3; // blindness handicaps you by 3, highest roll you can get is 15 instead of 18
				if (roll > maxblindattack) maxblindattack = roll, blind = p; // best blind hacker so far
			}
			else
			{  // we got someone who can see here
				if (roll > maxattack) maxattack = roll, hacker = p; // best hacker with eyeballs so far
			}
		}
	if (blind > -1 && (hacker == -1 || (maxblindattack > maxattack&&maxblindattack > 0)))
		hacker = blind, maxattack = maxblindattack, blind = true; // the best hacker is a blind person
	else if (blind > -1 && hacker == -1 && maxblindattack <= 0)
		blind = true; // we only have a blind hacker, and their roll with the handicap is 0 or less
	else blind = false; // either our hacker has eyeballs or there is no hacker at all
	if (hacker > -1)
	{
		activesquad->squad[hacker]->train(SKILL_COMPUTERS, difficulty);
		if (maxattack > difficulty)
		{
			clearmessagearea();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(16,  1, activesquad->squad[hacker]->name, gamelog);
			if (!blind) addstrAlt(" has", gamelog);
			switch (type)
			{
			case HACK_SUPERCOMPUTER:addstrAlt(" burned a disk of top secret files", gamelog); break;
			case HACK_VAULT:addstrAlt(" disabled the second layer of security", gamelog); break;
			}
			if (blind)
				addstrAlt(" despite being blind", gamelog);
			addstrAlt("!", gamelog);
			gamelog.newline();
			getkeyAlt();
			actual = 1;
			return 1;
		}
		else
		{
			clearmessagearea();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(16,  1, activesquad->squad[hacker]->name, gamelog);
			addstrAlt(" couldn't", gamelog);
			if (blind) addstrAlt(" see how to", gamelog);
			switch (type)
			{
			case HACK_SUPERCOMPUTER:addstrAlt(" bypass the supercomputer security.", gamelog); break;
			case HACK_VAULT:addstrAlt(" bypass the vault's electronic lock.", gamelog); break;
			}
			gamelog.newline();
			getkeyAlt();
			actual = 1;
			return 0;
		}
	}
	else
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "You can't find anyone to do the job.", gamelog);
		gamelog.newline();
		if (blind)
		{  // your only hacker was blind and had a skill roll, after the handicap, of 0 or less
			getkeyAlt();
			mvaddstrAlt(17,  1, "Including the BLIND HACKER you brought.", gamelog);
			gamelog.newline();
		}
		getkeyAlt();
	}
	actual = 0;
	return 0;
}
/* run a broadcast */
char run_broadcast(bool tv_broadcase)
{
	sitealarm = 1;
	int enemy = 0;
	for (int e = 0; e < ENCMAX; e++)
	{
		if (encounter[e].exists&&encounter[e].alive)
		{
			if (encounter[e].align == -1)enemy++;
		}
	}
	if (enemy > 0)
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "The Conservatives in the room hurry the Squad, so ", gamelog);
		mvaddstrAlt(17,  1, "the broadcast never happens.", gamelog);
		gamelog.newline();
		getkeyAlt();
		return 0;
	}
	criminalizeparty(LAWFLAG_DISTURBANCE);
	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	if (tv_broadcase) {
		mvaddstrAlt(16, 1, "The Squad steps in front of the cameras and ", gamelog);
	}
	else {
		mvaddstrAlt(16, 1, "The Squad takes control of the microphone and ", gamelog);
	}
	int viewhit = LCSrandom(VIEWNUM);
	if (discussesIssues.count(viewhit)) {
		mvaddstrAlt(17, 1, discussesIssues[viewhit], gamelog);
	}
	else {
		mvaddstrAlt(17, 1, discussesIssues[VIEW_LIBERALCRIMESQUADPOS], gamelog);
	}
	gamelog.newline();
	getkeyAlt();
	int segmentpower = 0, partysize = squadalive(activesquad);
	for (int p = 0; p < 6; p++)
	{
		if (activesquad->squad[p] != NULL)
		{
			if (!activesquad->squad[p]->alive)continue;
			segmentpower += activesquad->squad[p]->get_attribute(ATTRIBUTE_INTELLIGENCE, true);
			segmentpower += activesquad->squad[p]->get_attribute(ATTRIBUTE_HEART, true);
			segmentpower += activesquad->squad[p]->get_attribute(ATTRIBUTE_CHARISMA, true);
			segmentpower += activesquad->squad[p]->get_skill(SKILL_MUSIC);
			segmentpower += activesquad->squad[p]->get_skill(SKILL_RELIGION);
			segmentpower += activesquad->squad[p]->get_skill(SKILL_SCIENCE);
			segmentpower += activesquad->squad[p]->get_skill(SKILL_BUSINESS);
			segmentpower += activesquad->squad[p]->get_skill(SKILL_PERSUASION);
			activesquad->squad[p]->train(SKILL_PERSUASION, 50);
		}
	}
	// LCS colors enhance the broadcast significantly
	if (tv_broadcase) {
		if (activesquad->stance == SQUADSTANCE_BATTLECOLORS)
			segmentpower = (segmentpower * 3) / 2;
	}
	int segmentbonus = segmentpower / 4;
	if (partysize > 1)segmentpower /= partysize;
	segmentpower += segmentbonus;
	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	if (tv_broadcase) {
		if (segmentpower < 25)mvaddstrAlt(16, 1, "The Squad looks completely insane.", gamelog);
		else if (segmentpower < 35)mvaddstrAlt(16, 1, "The show really sucks.", gamelog);
		else if (segmentpower < 45)mvaddstrAlt(16, 1, "It is a very boring hour.", gamelog);
		else if (segmentpower < 55)mvaddstrAlt(16, 1, "It is mediocre TV.", gamelog);
		else if (segmentpower < 70)mvaddstrAlt(16, 1, "The show was all right.", gamelog);
		else if (segmentpower < 85)mvaddstrAlt(16, 1, "The Squad put on a good show.", gamelog);
		else if (segmentpower < 100)mvaddstrAlt(16, 1, "It was thought-provoking, even humorous.", gamelog);
		else mvaddstrAlt(16, 1, "It was the best hour of Cable TV EVER.", gamelog);
	}
	else {
		if (segmentpower < 25)mvaddstrAlt(16, 1, "The Squad sounds wholly insane.", gamelog);
		else if (segmentpower < 35)mvaddstrAlt(16, 1, "The show really sucks.", gamelog);
		else if (segmentpower < 45)mvaddstrAlt(16, 1, "It is a very boring hour.", gamelog);
		else if (segmentpower < 55)mvaddstrAlt(16, 1, "It is mediocre radio.", gamelog);
		else if (segmentpower < 70)mvaddstrAlt(16, 1, "The show was all right.", gamelog);
		else if (segmentpower < 85)mvaddstrAlt(16, 1, "The Squad put on a good show.", gamelog);
		else if (segmentpower < 100)mvaddstrAlt(16, 1, "It was thought-provoking, even humorous.", gamelog);
		else mvaddstrAlt(16, 1, "It was the best hour of AM radio EVER.", gamelog);
	}
	gamelog.newline();
	getkeyAlt();
	//CHECK PUBLIC OPINION
	change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
	if (tv_broadcase) {
		change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, (segmentpower - 50) / 10);
		if (viewhit != VIEW_LIBERALCRIMESQUAD)change_public_opinion(viewhit, (segmentpower - 50) / 5, 1);
		else change_public_opinion(viewhit, segmentpower / 10);
	}
	else {
		change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, (segmentpower - 50) / 2);
		if (viewhit != VIEW_LIBERALCRIMESQUAD)change_public_opinion(viewhit, (segmentpower - 50) / 2, 1);
		else change_public_opinion(viewhit, segmentpower / 2);
	}
	//PRISONER PARTS
	for (int p = 0; p < 6; p++)
	{
		if (activesquad->squad[p] != NULL)
		{
			if (activesquad->squad[p]->prisoner != NULL && activesquad->squad[p]->prisoner->alive)
			{
				if (((activesquad->squad[p]->prisoner->type == CREATURE_NEWSANCHOR) && tv_broadcase) || ((activesquad->squad[p]->prisoner->type == CREATURE_RADIOPERSONALITY) && !tv_broadcase))
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16,  1, "The hostage ", gamelog);
					addstrAlt(activesquad->squad[p]->prisoner->name, gamelog);
					addstrAlt(" is forced on to ", gamelog);
					viewhit = LCSrandom(VIEWNUM);
					if (discussIssues.count(viewhit)) {
						mvaddstrAlt(17, 1, discussIssues[viewhit], gamelog);
					}
					else {
						mvaddstrAlt(17, 1, discussIssues[VIEW_LIBERALCRIMESQUADPOS], gamelog);
					}
					gamelog.newline();
					int usegmentpower = 10; //FAME BONUS
					usegmentpower += activesquad->squad[p]->prisoner->get_attribute(ATTRIBUTE_INTELLIGENCE, true);
					usegmentpower += activesquad->squad[p]->prisoner->get_attribute(ATTRIBUTE_HEART, true);
					usegmentpower += activesquad->squad[p]->prisoner->get_attribute(ATTRIBUTE_CHARISMA, true);
					usegmentpower += activesquad->squad[p]->prisoner->get_skill(SKILL_PERSUASION);
					if (tv_broadcase) {
						if (viewhit != VIEW_LIBERALCRIMESQUAD)change_public_opinion(viewhit, (usegmentpower - 10) / 2);
						else change_public_opinion(viewhit, usegmentpower / 2, 1);
					}
					else {
						if (viewhit != VIEW_LIBERALCRIMESQUAD)change_public_opinion(viewhit, (usegmentpower - 10) / 2, 1, 80);
						else change_public_opinion(viewhit, usegmentpower / 2);
					}
					segmentpower += usegmentpower;
					getkeyAlt();
				}
				else
				{
					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16,  1, activesquad->squad[p]->prisoner->name, gamelog);
					addstrAlt(", the hostage, is kept off-air.", gamelog);
					gamelog.newline();
					getkeyAlt();
				}
			}
		}
	}
	if (sitealienate >= 1 && segmentpower >= 40)
	{
		sitealienate = 0;
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "Moderates at the station appreciated the show.", gamelog);
		gamelog.newline();
		mvaddstrAlt(17,  1, "They no longer feel alienated.", gamelog);
		gamelog.newline();
		getkeyAlt();
	}
	//POST-SECURITY BLITZ IF IT SUCKED
	if (((segmentpower < 85 && segmentpower >= 25) && tv_broadcase) || ((segmentpower < 90) && !tv_broadcase))
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "Security is waiting for the Squad ", gamelog);
		mvaddstrAlt(17,  1, "after the show!", gamelog);
		gamelog.newline();
		getkeyAlt();
		int numleft = LCSrandom(8) + 2;
		fillEncounter(CREATURE_SECURITYGUARD, numleft);
	}
	else
	{
		clearmessagearea();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		if (tv_broadcase) {
			mvaddstrAlt(16, 1, "The show was so ", gamelog);
			if (segmentpower < 50)
				addstrAlt("hilarious", gamelog);
			else
				addstrAlt("entertaining", gamelog);
			addstrAlt(" that security watched it ", gamelog);
		}
		else {
			mvaddstrAlt(16, 1, "The show was so good that security listened to it ", gamelog);
		}
		mvaddstrAlt(17,  1, "at their desks.  The Squad might yet escape.", gamelog);
		gamelog.newline();
		getkeyAlt();
	}
	return 1;
}
#include "common/creaturePoolCreature.h"
/* rescues people held at the activeparty's current location */
void partyrescue(short special)
{
	int freeslots = 0;
	for (int p = 0; p < 6; p++)
	{
		if (activesquad->squad[p] == NULL)freeslots++;
	}
	int hostslots = 0;
	for (int p = 0; p < 6; p++)
	{
		if (activesquad->squad[p] != NULL)
		{
			if (activesquad->squad[p]->alive&&activesquad->squad[p]->prisoner == NULL)
			{
				hostslots++;
			}
		}
	}
	vector<Creature*> waiting_for_rescue;
	
	whoAreWaitingForRescue(waiting_for_rescue, cursite, special);

	for (int pl = 0; pl < len(waiting_for_rescue); pl++)
	{
		if (LCSrandom(2) && freeslots)
		{
			for (int p = 0; p < 6; p++)
			{
				if (activesquad->squad[p] == NULL)
				{
					activesquad->squad[p] = waiting_for_rescue[pl];
					activesquad->squad[p]->squadid = activesquad->id;
					criminalize(*activesquad->squad[p], LAWFLAG_ESCAPED);
					activesquad->squad[p]->flag |= CREATUREFLAG_JUSTESCAPED;
					break;
				}
			}
			hostslots++;
			freeslots--;
			clearmessagearea();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(16,  1, "You've rescued ", gamelog);
			addstrAlt(waiting_for_rescue[pl]->name, gamelog);
			addstrAlt(" from the Conservatives.", gamelog);
			gamelog.newline();
			printparty();
			getkeyAlt();
			waiting_for_rescue[pl]->location = -1;
			waiting_for_rescue[pl]->base = activesquad->squad[0]->base;
			waiting_for_rescue.erase(waiting_for_rescue.begin() + pl);
			--pl;
		}
	}
	for (int pl = 0; pl < len(waiting_for_rescue); pl++)
	{
		if (hostslots)
		{
			for (int p = 0; p < 6; p++)
			{
				if (activesquad->squad[p] != NULL)
				{
					if (activesquad->squad[p]->alive&&activesquad->squad[p]->prisoner == NULL)
					{
						activesquad->squad[p]->prisoner = waiting_for_rescue[pl];
						waiting_for_rescue[pl]->squadid = activesquad->id;
						criminalize(*waiting_for_rescue[pl], LAWFLAG_ESCAPED);
						waiting_for_rescue[pl]->flag |= CREATUREFLAG_JUSTESCAPED;
						clearmessagearea();
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(16,  1, "You've rescued ", gamelog);
						addstrAlt(waiting_for_rescue[pl]->name, gamelog);
						addstrAlt(" from the Conservatives.", gamelog);
						gamelog.newline();
						getkeyAlt();
						clearmessagearea();
						mvaddstrAlt(16,  1, waiting_for_rescue[pl]->name, gamelog);
						addstrAlt(singleSpace, gamelog);
						addstrAlt(pickrandom(was_abused), gamelog);
						mvaddstrAlt(17,  1, "so ", gamelog);
						addstrAlt(activesquad->squad[p]->name, gamelog);
						addstrAlt(" will have to haul a Liberal.", gamelog);
						gamelog.newline();
						waiting_for_rescue[pl]->location = -1;
						waiting_for_rescue[pl]->base = activesquad->squad[p]->base;
						printparty();
						getkeyAlt();
						waiting_for_rescue.erase(waiting_for_rescue.begin() + pl);
						--pl;
						break;
					}
				}
			}
			hostslots--;
		}
		if (!hostslots)break;
	}
	if (len(waiting_for_rescue) == 1)
	{
		clearmessagearea();
		set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "There's nobody left to carry ", gamelog);
		addstrAlt(waiting_for_rescue[0]->name, gamelog);
		addstrAlt(singleDot, gamelog);
		gamelog.newline();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(17,  1, "You'll have to come back later.", gamelog);
		gamelog.newline();
		getkeyAlt();
	}
	else if (len(waiting_for_rescue) > 1)
	{
		clearmessagearea();
		set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "There's nobody left to carry the others.", gamelog);
		gamelog.newline();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(17,  1, "You'll have to come back later.", gamelog);
		gamelog.newline();
		getkeyAlt();
	}
}
/* everybody reload! */
void reloadparty(bool wasteful)
{
	for (int p = 0; p < 6; p++)
	{
		if (activesquad->squad[p] == NULL)continue;
		if (!activesquad->squad[p]->alive)continue;
		if (activesquad->squad[p]->has_thrown_weapon)
		{
			activesquad->squad[p]->ready_another_throwing_weapon();
		}
		else if (activesquad->squad[p]->can_reload())
		{
			activesquad->squad[p]->reload(wasteful);
		}
	}
}