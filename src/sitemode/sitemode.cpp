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

#include "vehicle/vehicle.h"

#include "basemode/baseactions.h"
// for orderparty

#include "basemode/reviewmode.h"

#include "sitemode/advance.h"

#include "sitemode/mapspecials.h"

#include "sitemode/stealth.h"

#include "sitemode/miscactions.h"

#include "sitemode/sitedisplay.h"

#include "sitemode/newencounter.h"

#include "sitemode/sitemode.h"
// own header

#include "items/loottype.h"

#include "items/loot.h"

#include "common/consolesupport.h"
// for void set_color(short,short,bool)

#include "log/log.h"
// for commondisplay.h
#include "common/commondisplay.h"
// for addchar

#include "common/commonactions.h"
// for squadsize

#include "common/translateid.h"
// for  id_getcar

#include "common/equipment.h"
//for void equip(vector<Item *>&,int)

#include "daily/daily.h"
//for char securityable(int type);

#include "daily/siege.h"
//for void conquertext();

#include "combat/fight.h"
//for void enemyattack();

#include "combat/haulkidnap.h"
//for void kidnapattempt();

#include "combat/chase.h"
//for void makechasers(long sitetype,long sitecrime);

char talk(Creature &a, const int t);

#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
extern vector<Creature *> pool;
extern Log gamelog;
extern vector<Location *> location;
extern vector<LootType *> loottype;
extern MusicClass music;
extern short mode;
extern short postalarmtimer;
extern char endgamestate;
extern short sitetype;
extern char foughtthisround;
extern bool mapshowing;
extern bool encounterwarnings;
extern int ccs_siege_kills;
extern int ccs_boss_kills;
extern int stat_recruits;
extern string closeParenthesis;
extern string undefined;
extern string tag_class;
extern string tag_WEAPON;
extern string tag_CLIP;
extern string tag_ARMOR;
extern string tag_LOOT;
extern string tag_type;
extern string tag_description;
extern string tag_price;
extern string tag_sleeperprice;
extern string tag_letter;
extern string check_status_of_squad_liberal;
extern string show_squad_liberal_status;
extern string enter_done;
extern string chooseALiberalTo;
extern string spaceDashSpace;
extern string singleDot;
extern string change_squad_order;
extern string spaceParanthesisDollar;
extern string string_sleeper;
typedef map<short, string> shortAndString;
void emptyEncounter();
extern squadst *activesquad;
extern short sitealarmtimer;
extern short siteonfire;
extern short cursite;
extern short sitealarm;
extern int sitecrime;
extern squadst *activesquad;
extern siteblockst levelmap[MAPX][MAPY][MAPZ];
extern int locx;
extern int locy;
extern int locz;
extern Creature encounter[ENCMAX];
extern short party_status;
extern vector<Item *> groundloot;
//extern vector<Location *> location;
extern vector<Vehicle *> vehicle;
extern chaseseqst chaseseq;
extern short sitealienate;
extern vector<newsstoryst *> newsstory;
extern newsstoryst *sitestory;
extern char showcarprefs;
extern short lawList[LAWNUM];
extern short sitealienate;
extern short offended_corps;
extern short offended_cia;
extern short offended_amradio;
extern short offended_cablenews;
extern short offended_firemen;
extern vector<ClipType *> cliptype;
extern vector<WeaponType *> weapontype;
extern vector<ArmorType *> armortype;
extern vector<LootType *> loottype;
extern string singleSpace;
extern short fieldskillrate;
extern char ccs_kills;
extern UniqueCreatures uniqueCreatures;

void fight_subdued()
{
	int p;
	//int ps=find_police_station(chaseseq.location);
	delete_and_clear(chaseseq.friendcar, vehicle);
	int hostagefreed = 0;
	int stolen = 0;
	// Police assess stolen goods in inventory
	for (int l = 0; l < len(activesquad->loot); l++)
		if (activesquad->loot[l]->is_loot())
			stolen++;
	for (p = 0; p < 6; p++)
	{
		if (!activesquad->squad[p]) continue;
		activesquad->squad[p]->crimes_suspected[LAWFLAG_THEFT] += stolen;
		capturecreature(*(activesquad->squad[p]));
		activesquad->squad[p] = NULL;
	}
	for (p = 0; p < len(pool); p++)
		for (int w = 0; w < BODYPARTNUM; w++)
			pool[p]->wound[w] &= ~WOUND_BLEEDING;
	clearmessagearea();
	clearcommandarea();
	set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
	mvaddstrAlt(16,  1, "The police subdue and arrest the squad.", gamelog);
	gamelog.newline();
	if (hostagefreed > 0)
	{
		if (hostagefreed > 1) {
			mvaddstrAlt(17, 1, "Your hostages are free.", gamelog);
		}
		else {
			mvaddstrAlt(17, 1, "Your hostage is free.", gamelog);
		}
	}
	gamelog.newline();
	getkey();
}
void mode_site(short loc)
{
	sitetype = location[loc]->type;
	cursite = loc;
	sitealarm = 0;
	sitealarmtimer = -1;
	postalarmtimer = 0;
	siteonfire = 0;
	sitealienate = 0;
	sitecrime = 0;
	initsite(*location[loc]);
	sitestory = newsstory[len(newsstory) - 1];
	mode = GAMEMODE_SITE;
	if (!location[loc]->siege.siege)
	{
		music.play(MUSIC_SITEMODE);
		ccs_siege_kills = 0;
		ccs_boss_kills = 0;
		//Low profile site action?
		if (activesquad->stance == SQUADSTANCE_ANONYMOUS)
			sitestory->claimed = 0;
		//Start at entrance to map
		locx = MAPX >> 1;
		locy = 1;
		locz = 0;
		// Second floor start of White House
		if (location[loc]->type == SITE_GOVERNMENT_WHITE_HOUSE && levelmap[locx][locy][locz].flag & SITEBLOCK_BLOCK)
			locz++;
		//check for sleeper infiltration or map knowledge
		for (int p = 0; p < len(pool); p++)
			if (pool[p]->base == loc || location[loc]->mapped)
			{

				//make entire site known
				for (int x = 0; x < MAPX; x++)
					for (int y = 0; y < MAPY; y++)
						for (int z = 0; z < MAPZ; z++)
							levelmap[x][y][z].flag |= SITEBLOCK_KNOWN;
				break;
			}

	}
	else
	{
		music.play(MUSIC_DEFENSE);
		sitealarm = 1;
		location[loc]->siege.attacktime = 0;
		location[loc]->siege.kills = 0;
		location[loc]->siege.tanks = 0;
		//PLACE YOU
		//int maxy=0;
		for (int x = 0; x < MAPX; x++)
			for (int y = 0; y < MAPY; y++)
			{

				for (int z = 0; z < MAPZ; z++)
				{

					if (!(location[loc]->siege.lights_off))levelmap[x][y][z].flag |= SITEBLOCK_KNOWN;
					levelmap[x][y][z].flag &= ~SITEBLOCK_LOCKED;
					levelmap[x][y][z].flag &= ~SITEBLOCK_LOOT;
				}

				//if(!(levelmap[x][y][0].flag & (SITEBLOCK_BLOCK|SITEBLOCK_DOOR)))maxy=y;
			}

		//Cops have tanks; firemen have fire.
		if (location[loc]->siege.siegetype == SIEGE_FIREMEN)
		{

			int firesstarted = 0, firex, firey;
			do
			{

				firex = LCSrandom(MAPX), firey = LCSrandom(MAPY);
				firesstarted++;
				levelmap[firex][firey][0].flag |= SITEBLOCK_FIRE_START;
			} while (!(levelmap[firex][firey][0].flag&(SITEBLOCK_BLOCK | SITEBLOCK_DOOR | SITEBLOCK_EXIT)) &&
				firesstarted < 4);
		}

		do
		{

			// Some bugs with degenerate spawn outside the map are occurring
			// Unknown why, but hard-coding limits to spawn location should help
			//locx=LCSrandom(MAPX);
			//locy=maxy-LCSrandom(3);
			locx = MAPX / 2 + LCSrandom(25) - 12;
			locy = 15 - LCSrandom(3);
			//if(locy<3) locy=3;
			locz = 0;
		} while (levelmap[locx][locy][locz].flag&(SITEBLOCK_BLOCK | SITEBLOCK_DOOR |
			SITEBLOCK_FIRE_START | SITEBLOCK_FIRE_PEAK | SITEBLOCK_FIRE_END));
		//PLACE LOOT
		int lootnum = len(location[loc]->loot);
		if (lootnum>10) lootnum = 10;
		int lx, ly, lz;
		for (int l = 0; l < lootnum; l++)
		{

			do lx = LCSrandom(MAPX), ly = LCSrandom(MAPY), lz = 0;
			while (levelmap[lx][ly][lz].flag&(SITEBLOCK_BLOCK | SITEBLOCK_DOOR | SITEBLOCK_EXIT));
			levelmap[lx][ly][lz].flag |= SITEBLOCK_LOOT;
		}

		//PLACE TRAPS
		if (location[loc]->compound_walls&COMPOUND_TRAPS)
		{

			int trapnum = 30;
			for (int t = 0; t < trapnum; t++)
			{

				do lx = LCSrandom(MAPX), ly = LCSrandom(MAPY), lz = 0;
				while (levelmap[lx][ly][lz].flag&(SITEBLOCK_BLOCK | SITEBLOCK_DOOR | SITEBLOCK_EXIT | SITEBLOCK_LOOT));
				levelmap[lx][ly][lz].siegeflag |= SIEGEFLAG_TRAP;
			}
		}


		//PLACE UNITS
		int unitnum = 6;
		int count = 50000;
		for (int t = 0; t < unitnum; t++)
		{

			do
			{

				lx = LCSrandom(11) + (MAPX / 2) - 5;
				ly = LCSrandom(8);
				lz = 0;
				count--;
				if (count == 0) break;
			} while ((levelmap[lx][ly][lz].flag&(SITEBLOCK_BLOCK | SITEBLOCK_DOOR | SITEBLOCK_EXIT)) ||
				(levelmap[lx][ly][lz].siegeflag&(SIEGEFLAG_UNIT | SIEGEFLAG_HEAVYUNIT | SIEGEFLAG_TRAP)));
			levelmap[lx][ly][lz].siegeflag |= SIEGEFLAG_UNIT;
		}

		if (!(location[loc]->compound_walls & COMPOUND_TANKTRAPS) &&
			location[loc]->siege.siegetype == SIEGE_POLICE&&
			location[loc]->siege.escalationstate >= 2)
		{

			levelmap[MAPX / 2][1][0].siegeflag |= SIEGEFLAG_HEAVYUNIT;
			location[loc]->siege.tanks = 1;
		}

	}
	mode_site();
}
void mode_site() {

	int p, u, x;
	if (activesquad == NULL)return;
	reloadparty();
	showcarprefs = -1;
	char bail_on_base = 1;
	if (cursite == activesquad->squad[0]->base)bail_on_base = 0;
	knowmap(locx, locy, locz);
	char hostcheck = 0;
	int encounter_timer = 0;
	while (true)
	{
		int partysize = squadsize(activesquad), partyalive = squadalive(activesquad), hostages = 0, encsize = 0, freeable = 0, enemy = 0, majorenemy = 0, talkers = 0;
		for (p = 0; p < 6; p++)
			if (activesquad->squad[p] != NULL)
				if (activesquad->squad[p]->prisoner&&activesquad->squad[p]->prisoner->align != ALIGN_LIBERAL)
					hostages++;
		for (int e = 0; e < ENCMAX; e++)
		{

			if (encounter[e].exists)
			{

				encsize++;
				if (encounter[e].enemy())enemy++;
				if (encounter[e].type == CREATURE_WORKER_SERVANT ||
					encounter[e].type == CREATURE_WORKER_FACTORY_CHILD ||
					encounter[e].type == CREATURE_WORKER_SWEATSHOP ||
					(strcmp(encounter[e].name, "Prisoner") == 0 && encounter[e].align == 1))freeable++;
				else if ((encounter[e].cantbluff != 1 || sitealarm) && !(encounter[e].align == 1 && sitealarm&&enemy))talkers++;
				if (encounter[e].type == CREATURE_CORPORATE_CEO ||
					encounter[e].type == CREATURE_RADIOPERSONALITY ||
					encounter[e].type == CREATURE_NEWSANCHOR ||
					encounter[e].type == CREATURE_SCIENTIST_EMINENT ||
					encounter[e].type == CREATURE_JUDGE_CONSERVATIVE)majorenemy++;
			}
		}


		//If in combat, do a second check
		if (talkers&&sitealarm&&enemy)
		{

			talkers = 0;
			for (int e = 0; e < ENCMAX; e++)
				if (encounter[e].exists)
					if (encounter[e].enemy() && (encounter[e].cantbluff == 0 || encounter[e].animalgloss == ANIMALGLOSS_ANIMAL)) talkers++;
		}

		int libnum = 0;
		for (p = 0; p < len(pool); p++)
			if (pool[p]->align == 1 &&
				pool[p]->alive&&
				pool[p]->location == cursite&&
				!(pool[p]->flag&CREATUREFLAG_SLEEPER)) libnum++;
		// Let the squad stop stressing out over the encounter if there are no enemies this round
		if (!enemy) encounter_timer = 0;
		eraseAlt();

		if (location[cursite]->siege.siege)
		{

			music.play(MUSIC_DEFENSE);
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(0,  0, location[cursite]->getname(-1, true));
			addstrAlt(", Level ");
			addstrAlt(locz + 1);
			addstrAlt(": Escape or Engage");
		}

		else
		{

			if (postalarmtimer > 80) set_color_easy(RED_ON_BLACK_BRIGHT);
			else if (postalarmtimer > 60) set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			else set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(0,  0, location[cursite]->getname(-1, true));
			addstrAlt(", Level ");
			addstrAlt(locz + 1);
			if (postalarmtimer > 80)
			{

				switch (location[cursite]->type)
				{

				case SITE_GOVERNMENT_ARMYBASE:
					addstrAlt(": SOLDIERS AND TANKS RESPONDING");
					break;
				case SITE_GOVERNMENT_WHITE_HOUSE:
					addstrAlt(": SECRET SERVICE RESPONDING");
					break;
				case SITE_GOVERNMENT_INTELLIGENCEHQ:
					addstrAlt(": AGENTS RESPONDING");
					break;
				case SITE_CORPORATE_HEADQUARTERS:
				case SITE_CORPORATE_HOUSE:
					addstrAlt(": MERCENARIES RESPONDING");
					break;
				case SITE_MEDIA_AMRADIO:
				case SITE_MEDIA_CABLENEWS:
					addstrAlt(": ANGRY MOB RESPONDING");
					break;
				case SITE_BUSINESS_CRACKHOUSE:
					addstrAlt(": GANG MEMBERS RESPONDING");
					break;
				case SITE_GOVERNMENT_POLICESTATION:
				default:
					if (location[cursite]->renting == RENTING_CCS)
					{

						addstrAlt(": CCS VIGILANTIES RESPONDING");
					}

					else if (lawList[LAW_DEATHPENALTY] == -2 &&
						lawList[LAW_POLICEBEHAVIOR] == -2)addstrAlt(": DEATH SQUADS RESPONDING");
					else addstrAlt(": POLICE RESPONDING");
					break;
				}

				music.play(MUSIC_HEAVYCOMBAT);
			}

			else if (postalarmtimer > 60) { addstrAlt(": CONSERVATIVE REINFORCEMENTS INCOMING"); music.play(MUSIC_ALARMED); }
			else if (sitealienate == 1) { addstrAlt(": ALIENATED MASSES"); music.play(MUSIC_ALARMED); }
			else if (sitealienate == 2) { addstrAlt(": ALIENATED EVERYONE"); music.play(MUSIC_ALARMED); }
			else if (sitealarm) { addstrAlt(": CONSERVATIVES ALARMED"); music.play(MUSIC_ALARMED); }
			else if (sitealarmtimer == 0) { addstrAlt(": CONSERVATIVES SUSPICIOUS"); music.play(MUSIC_SUSPICIOUS); }
			else music.play(MUSIC_SITEMODE);
		}

		//PRINT PARTY
		if (partyalive == 0)party_status = -1;
		printparty();
		//PRINT SITE INSTRUCTIONS
		if (partyalive > 0)
		{

			if (!enemy || !sitealarm)set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(9,  1, "W,A,D,X - Move");
			if (partysize > 1)set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(11,  1, change_squad_order);

			if (partysize > 0 && (party_status == -1 || partysize > 1))set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(12,  1, check_status_of_squad_liberal);

			if (party_status != -1)set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(13,  1, show_squad_liberal_status);

			if (len(groundloot) || (levelmap[locx][locy][locz].flag&SITEBLOCK_LOOT))
				set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(9,  17, "G - Get Loot");
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(10,  17, "N - Options");
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(9,  32, "M - Map");
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(10,  32, "S - Wait");
			if (!enemy || !sitealarm) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(10,  42, "L - Reload");
			if (enemy) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(13,  42, "K - Kidnap");
			if (talkers) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(14,  17, "T - Talk");
			bool graffiti = 0;
			if (levelmap[locx][locy][locz].special != -1 &&
				levelmap[locx][locy][locz].special != SPECIAL_CLUB_BOUNCER_SECONDVISIT)set_color_easy(WHITE_ON_BLACK);
			else if (!(levelmap[locx][locy][locz].flag & (SITEBLOCK_GRAFFITI | SITEBLOCK_BLOODY2)))
			{

				if ((levelmap[locx + 1][locy][locz].flag & SITEBLOCK_BLOCK) ||
					(levelmap[locx - 1][locy][locz].flag & SITEBLOCK_BLOCK) ||
					(levelmap[locx][locy + 1][locz].flag & SITEBLOCK_BLOCK) ||
					(levelmap[locx][locy - 1][locz].flag & SITEBLOCK_BLOCK))
				{

					int i;
					for (i = 0; i < 6; i++)
					{

						if (!activesquad->squad[i]) i = 6;
						else if (activesquad->squad[i]->get_weapon().can_graffiti())
						{

							set_color_easy(WHITE_ON_BLACK);
							graffiti = 1;
							break;
						}
					}


					if (i == 6) set_color_easy(BLACK_ON_BLACK_BRIGHT);
				}

				else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			}

			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			if (graffiti)mvaddstrAlt(11, 42, "U - Graffiti");
			else mvaddstrAlt(11, 42, "U - Use");
			if (enemy&&sitealarm)
			{

				bool evade = false;
				set_color_easy(WHITE_ON_BLACK);
				for (int e = 0; e < ENCMAX; e++)
				{

					if (encounter[e].exists &&
						encounter[e].alive  &&
						encounter[e].cantbluff == 2)
					{

						// You can't sneak past this person; they already know you're there
						evade = true;
						break;
					}
				}


				if (!evade)
					mvaddstrAlt(12, 42, "V - Sneak");
				else
					mvaddstrAlt(12, 42, "V - Run");
			}

			else
			{

				set_color_easy(BLACK_ON_BLACK_BRIGHT);
				addstrAlt("V - Evade");
			}

			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(9,  42, "E - Equip");
			if (enemy)set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(14,  1, "F - Fight!");
			if (!location[cursite]->siege.siege)
			{

				if (freeable && (!enemy || !sitealarm))
				{

					set_color_easy(WHITE_ON_BLACK);
					mvaddstrAlt(14,  32, "R - Release oppressed");
				}

				else
				{

					if (hostages) set_color_easy(WHITE_ON_BLACK);
					else set_color_easy(BLACK_ON_BLACK_BRIGHT);
					mvaddstrAlt(14,  32, "R - Release hostage");
				}
			}


			else
			{

				if (libnum > 6)set_color_easy(WHITE_ON_BLACK);
				else set_color_easy(BLACK_ON_BLACK_BRIGHT);
				mvaddstrAlt(14,  32, "R - Reorganize");
			}
		}


		else
		{

			//DESTROY ALL CARS BROUGHT ALONG WITH PARTY
			if (!location[cursite]->siege.siege)
			{

				for (int p = 0; p < 6; p++)
				{

					if (!activesquad->squad[p]) continue;
					if (activesquad->squad[p]->carid != -1)
						delete_and_remove(vehicle, id_getcar(activesquad->squad[p]->carid));
				}
			}


			for (int p = 0; p < 6; p++)
			{

				if (!activesquad->squad[p]) continue;
				activesquad->squad[p]->die();
				activesquad->squad[p]->location = -1;
				activesquad->squad[p] = NULL;
			}

			endcheck(-2); // play the right music in case we're dead
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(9,  1, "C - Reflect on your Conservative ineptitude");
		}

		//PRINT SITE MAP
		printsitemap(locx, locy, locz);
		//CHECK IF YOU HAVE A SQUIRMING AMATEUR HOSTAGE
		//hostcheck SHOULD ONLY BE 1 WHEN A NEWENC IS CREATED
		if (hostcheck)
		{

			char havehostage = 0;
			//Check your whole squad
			for (int p = 0; p < 6; p++)
			{

				if (activesquad->squad[p] != NULL)
				{

					//If they're unarmed and dragging someone
					if (activesquad->squad[p]->prisoner != NULL&&
						!activesquad->squad[p]->get_weapon().can_threaten_hostages())
					{

						//And that someone is not an LCS member
						if (activesquad->squad[p]->prisoner->squadid == -1)
						{

							//They scream for help -- flag them kidnapped, cause alarm
							activesquad->squad[p]->prisoner->flag |= CREATUREFLAG_KIDNAPPED;
							if (activesquad->squad[p]->type == CREATURE_RADIOPERSONALITY)offended_amradio = 1;
							if (activesquad->squad[p]->type == CREATURE_NEWSANCHOR)offended_cablenews = 1;
							havehostage = 1;
						}
					}
				}
			}




			if (havehostage)
			{

				alienationcheck(1);
				sitecrime += 5;
				criminalizeparty(LAWFLAG_KIDNAPPING);
			}

			hostcheck = 0;
			clearmessagearea();
		}

		// check if we fought the previous loop; if so, add a blank gamelog line
		if (foughtthisround)gamelog.newline();
		foughtthisround = 0;
		int c;
		if (levelmap[locx][locy][locz].special == SPECIAL_CLUB_BOUNCER)
		{

			if (location[cursite]->renting == RENTING_PERMANENT)
			{

				levelmap[locx][locy][locz].special = SPECIAL_NONE;
				c = getkey();
			}

			else
				c = 's';
		}


		else c = getkey();
		if (partyalive == 0 && c == 'c')
		{

			//END OF GAME CHECK
			if (!endcheck())
			{

				if (location[cursite]->siege.siege)
				{

					if (location[cursite]->siege.underattack)sitestory->type = NEWSSTORY_SQUAD_KILLED_SIEGEATTACK;
					else sitestory->type = NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE;
				}

				else
					if (!location[cursite]->siege.siege)
					{

						sitestory->type = NEWSSTORY_SQUAD_KILLED_SITE;
						resolvesite();
					}

				mode = GAMEMODE_BASE;
				showcarprefs = 0;
				return;
			}
		}


		if (partyalive > 0)
		{

			int olocx = locx, olocy = locy, olocz = locz;
			char override = 0;
			if (c == 'v'&&enemy&&sitealarm)
			{

				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, "Which way?  (W,A,D, and X to move, ENTER to abort)");
				while (true)
				{

					int c2 = getkey();
					if (c2 == 'w' || c2 == 'a' || c2 == 'd' || c2 == 'x' ||
						c2 == KEY_LEFT || c2 == KEY_RIGHT || c2 == KEY_UP || c2 == KEY_DOWN)
					{



						c = c2;
						override = 1;
						break;
					}

					if (c2 == ENTER || c2 == ESC || c2 == SPACEBAR)break;
				}
			}


			if ((c == 'w' || c == KEY_UP) && locy>0 && (!enemy || !sitealarm || override))

			{
				if (!(levelmap[locx][locy - 1][locz].flag & SITEBLOCK_BLOCK))locy--;

			}
			if ((c == 'a' || c == KEY_LEFT) && locx>0 && (!enemy || !sitealarm || override))

			{
				if (!(levelmap[locx - 1][locy][locz].flag & SITEBLOCK_BLOCK))locx--;

			}
			if ((c == 'd' || c == KEY_RIGHT) && locx<MAPX - 1 && (!enemy || !sitealarm || override))

			{
				if (!(levelmap[locx + 1][locy][locz].flag & SITEBLOCK_BLOCK))locx++;

			}
			if ((c == 'x' || c == KEY_DOWN) && locy<MAPY - 1 && (!enemy || !sitealarm || override))

			{
				if (!(levelmap[locx][locy + 1][locz].flag & SITEBLOCK_BLOCK))locy++;

			}
			if (c == 'k'&&enemy)
			{

				kidnapattempt();
			}

			if (c == 'u')
			{

				if (levelmap[locx][locy][locz].special != -1)
				{

					switch (levelmap[locx][locy][locz].special)
					{

					case SPECIAL_LAB_COSMETICS_CAGEDANIMALS:special_lab_cosmetics_cagedanimals(); break;
					case SPECIAL_NUCLEAR_ONOFF:special_nuclear_onoff(); break;
					case SPECIAL_LAB_GENETIC_CAGEDANIMALS:special_lab_genetic_cagedanimals(); break;
					case SPECIAL_POLICESTATION_LOCKUP:special_policestation_lockup(); break;
					case SPECIAL_COURTHOUSE_LOCKUP:special_courthouse_lockup(); break;
					case SPECIAL_COURTHOUSE_JURYROOM:special_courthouse_jury(); break;
					case SPECIAL_PRISON_CONTROL:
					case SPECIAL_PRISON_CONTROL_LOW:
					case SPECIAL_PRISON_CONTROL_MEDIUM:
					case SPECIAL_PRISON_CONTROL_HIGH:
						special_prison_control(levelmap[locx][locy][locz].special); break;
					case SPECIAL_INTEL_SUPERCOMPUTER:special_intel_supercomputer(); break;
					case SPECIAL_SWEATSHOP_EQUIPMENT:special_sweatshop_equipment(); break;
					case SPECIAL_POLLUTER_EQUIPMENT:special_polluter_equipment(); break;
					case SPECIAL_HOUSE_PHOTOS:special_house_photos(); break;
					case SPECIAL_ARMORY:special_armory(); break;
					case SPECIAL_CORPORATE_FILES:special_corporate_files(); break;
					case SPECIAL_RADIO_BROADCASTSTUDIO:special_radio_broadcaststudio(); break;
					case SPECIAL_NEWS_BROADCASTSTUDIO:special_news_broadcaststudio(); break;
					case SPECIAL_SIGN_ONE:special_readsign(SPECIAL_SIGN_ONE); break;
					case SPECIAL_SIGN_TWO:special_readsign(SPECIAL_SIGN_TWO); break;
					case SPECIAL_SIGN_THREE:special_readsign(SPECIAL_SIGN_THREE); break;
					case SPECIAL_STAIRS_UP:locz++; break;
					case SPECIAL_STAIRS_DOWN:locz--; break;
					case SPECIAL_DISPLAY_CASE:special_display_case(); break;
					case SPECIAL_SECURITY_CHECKPOINT:special_security_checkpoint(); break;
					case SPECIAL_SECURITY_METALDETECTORS:special_security_metaldetectors(); break;
					case SPECIAL_SECURITY_SECONDVISIT:special_security_secondvisit(); break;
					case SPECIAL_BANK_VAULT:special_bank_vault(); break;
					case SPECIAL_BANK_TELLER:special_bank_teller(); break;
					case SPECIAL_BANK_MONEY:special_bank_money(); break;
					case SPECIAL_CCS_BOSS:special_ccs_boss(); break;
					case SPECIAL_OVAL_OFFICE_NW:
					case SPECIAL_OVAL_OFFICE_NE:
					case SPECIAL_OVAL_OFFICE_SW:
					case SPECIAL_OVAL_OFFICE_SE:special_oval_office(); break;
					}
				}


				else if (!(levelmap[locx][locy][locz].flag & (SITEBLOCK_GRAFFITI | SITEBLOCK_BLOODY2)) &&
					((levelmap[locx + 1][locy][locz].flag & SITEBLOCK_BLOCK) ||
						(levelmap[locx - 1][locy][locz].flag & SITEBLOCK_BLOCK) ||
						(levelmap[locx][locy + 1][locz].flag & SITEBLOCK_BLOCK) ||
						(levelmap[locx][locy - 1][locz].flag & SITEBLOCK_BLOCK)))
				{

					int spray = 0;
					for (int i = 0; i < 6; i++)
					{

						if (!activesquad->squad[i])break;
						if (activesquad->squad[i]->get_weapon().can_graffiti())
						{

							spray = 1;
							break;
						}
					}


					if (spray)
					{

						special_graffiti();
						if (enemy&&sitealarm)
						{

							enemyattack();
						}
					}
				}
			}




			if (c == 't'&&talkers)
			{

				int forcesp = -1;
				int forcetk = -1;
				for (int p = 0; p < 6; p++)
				{

					if (activesquad->squad[p] != NULL)
					{

						if (activesquad->squad[p]->alive)
						{

							if (forcesp == -1)forcesp = p;
							else forcesp = -2;
						}
					}
				}



				for (int e = 0; e < ENCMAX; e++)
				{

					if (encounter[e].exists&&encounter[e].alive&&
						!(encounter[e].type == CREATURE_WORKER_SERVANT ||
							encounter[e].type == CREATURE_WORKER_SWEATSHOP))
					{

						if (encounter[e].cantbluff != 1 || sitealarm)
						{

							if (forcetk == -1)forcetk = e;
							else forcetk = -2;
						}
					}
				}



				if (forcetk != -1 && forcesp != -1)
				{

					int tk = -1, sp = -1;
					if (forcesp == -2)
					{

						clearcommandarea();
						clearmessagearea();
						clearmaparea();
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(9,  1, "Which Liberal will speak?");
						mvaddstrAlt(9,  50, "Issues");
						mvaddstrAlt(9,  60, "Dating");
						mvaddstrAlt(9,  70, "Bluff");
						int y = 11;
						for (int p = 0; p < 6; p++)
						{

							if (activesquad->squad[p] != NULL)
							{

								if (activesquad->squad[p]->alive)
								{
									mvaddcharAlt(y, 1, p + '1');
									addstrAlt(spaceDashSpace);




									addstrAlt(activesquad->squad[p]->name);
									mvaddstrAlt(y,  50, activesquad->squad[p]->get_attribute(ATTRIBUTE_CHARISMA, true) / 2 +
										activesquad->squad[p]->get_skill(SKILL_PERSUASION));
									mvaddstrAlt(y,  60, activesquad->squad[p]->get_attribute(ATTRIBUTE_CHARISMA, true) / 2 +
										activesquad->squad[p]->get_skill(SKILL_SEDUCTION));
									mvaddstrAlt(y++,  70, activesquad->squad[p]->get_attribute(ATTRIBUTE_CHARISMA, true) / 2 +
										activesquad->squad[p]->get_skill(SKILL_DISGUISE));
								}
							}
						}



						while (true)
						{

							int c = getkey();
							if (c >= '1'&&c <= '6')
							{
								sp = c - '1';


								if (activesquad->squad[sp] != NULL) if (activesquad->squad[sp]->alive) break;
							}

							if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) { sp = -1; break; }
						}
					}


					else sp = forcesp;
					if (sp != -1)
					{

						if (forcetk == -2)
						{

							while (true)
							{

								clearcommandarea();
								clearmessagearea();
								clearmaparea();
								set_color_easy(WHITE_ON_BLACK_BRIGHT);
								mvaddstrAlt(9,  1, "To whom?");
								int x = 1, y = 11;
								for (int t = 0; t < ENCMAX; t++)
								{

									if (encounter[t].exists)
									{

										if (encounter[t].cantbluff != 1)
										{

											set_color_easy(WHITE_ON_BLACK_BRIGHT);
											mvaddcharAlt(y, x, t + 'A');
											addstrAlt(spaceDashSpace);



											switch (encounter[t].align)
											{

											case ALIGN_CONSERVATIVE:
												set_color_easy(RED_ON_BLACK_BRIGHT);
												break;

											case ALIGN_LIBERAL:
												set_color_easy(GREEN_ON_BLACK_BRIGHT);
												break;

											case ALIGN_MODERATE:
												set_color_easy(WHITE_ON_BLACK_BRIGHT);
												break;
											}


											addstrAlt(encounter[t].name);
											add_age(encounter[t]);
											y++;

											if (y == 17)
											{
												y = 11;
												x += 30;
											}
										}
										else
										{
											y++;







											if (y == 17)
											{
												y = 11;
												x += 30;
											}
										}
									}
								}







								int c = getkey();
								if (c >= 'a'&&c <= 'z')
								{
									tk = c - 'a';


									if (tk < ENCMAX)
									{

										if (encounter[tk].exists)
										{

											if (encounter[tk].alive&&
												!(encounter[tk].type == CREATURE_WORKER_SERVANT ||
													encounter[tk].type == CREATURE_WORKER_SWEATSHOP))
											{

												if (encounter[tk].cantbluff == 1 &&
													(!sitealarm || encounter[tk].animalgloss == ANIMALGLOSS_ANIMAL))
												{

													clearcommandarea();
													clearmessagearea();
													clearmaparea();
													set_color_easy(WHITE_ON_BLACK_BRIGHT);
													mvaddstrAlt(9,  1, encounter[tk].name);
													addstrAlt(" won't talk to you.");
													getkey();
												}

												else if (!encounter[tk].enemy() && sitealarm&&enemy)
												{

													clearcommandarea();
													clearmessagearea();
													clearmaparea();
													set_color_easy(WHITE_ON_BLACK_BRIGHT);
													mvaddstrAlt(9,  1, "You have to deal with the enemies first.");
													getkey();
												}

												else break;
											}
										}
									}
								}




								if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) { tk = -1; break; }
							}
						}


						else tk = forcetk;
						if (tk != -1)
						{

							if (talk(*activesquad->squad[sp], tk))
							{

								if (enemy&&sitealarm)enemyattack();
								else if (enemy)disguisecheck(encounter_timer);
								creatureadvance();
								encounter_timer++;
							}
						}
					}
				}
			}





			if (c == 'l' && (!enemy || !sitealarm))
			{

				reloadparty(true);
				printparty();
				refreshAlt();

				creatureadvance();
				encounter_timer++;
			}

			if (c == 'o'&&partysize > 1)orderparty();
			if (c == '0')party_status = -1;
			if (c == 'm')
			{

				for (int x = 0; x < MAPX; x++)
				{

					for (int y = 0; y < MAPY; y++)
					{

						if (levelmap[x][y][locz].flag & SITEBLOCK_KNOWN)
						{

							if (x == locx&&y == locy)
							{

								set_color_easy(GREEN_ON_BLACK_BRIGHT);
								mvaddchAlt(y + 1, x + 5, CH_WHITE_SMILING_FACE);
							}

							else
							{

								set_color_easy(WHITE_ON_BLACK);
								if (levelmap[x][y][locz].flag & SITEBLOCK_BLOCK)
								{

									set_color_easy(WHITE_ON_WHITE);
									mvaddchAlt(y + 1, x + 5, ' ');
								}


								else if (levelmap[x][y][locz].flag & SITEBLOCK_DOOR)
								{  // Pick color
									if (levelmap[x][y][locz].flag & SITEBLOCK_METAL)
										set_color(COLOR_WHITE, COLOR_WHITE, 1);
									else if (levelmap[x][y][locz].flag & SITEBLOCK_CLOCK
										&& levelmap[x][y][locz].flag & SITEBLOCK_LOCKED)
										set_color_easy(RED_ON_BLACK);
									else if (levelmap[x][y][locz].flag & SITEBLOCK_KLOCK
										&& levelmap[x][y][locz].flag & SITEBLOCK_LOCKED)
										set_color_easy(BLACK_ON_BLACK_BRIGHT);
									else set_color(COLOR_YELLOW, COLOR_BLACK, 0);
									if ((levelmap[x + 1][y][locz].flag & SITEBLOCK_BLOCK) ||
										(levelmap[x - 1][y][locz].flag & SITEBLOCK_BLOCK))
										mvaddchAlt(y + 1, x + 5, CH_BOX_DRAWINGS_DOUBLE_HORIZONTAL);
									else mvaddchAlt(y + 1, x + 5, CH_BOX_DRAWINGS_DOUBLE_VERTICAL);
								}

								else if ((levelmap[x][y][locz].siegeflag & SIEGEFLAG_HEAVYUNIT) &&
									(location[cursite]->compound_walls & COMPOUND_CAMERAS) && !location[cursite]->siege.cameras_off)
								{

									set_color_easy(RED_ON_BLACK_BRIGHT);
									mvaddchAlt(y + 1, x + 5, CH_YEN_SIGN);
								}

								else if ((levelmap[x][y][locz].siegeflag & SIEGEFLAG_UNIT) &&
									(location[cursite]->compound_walls & COMPOUND_CAMERAS) && !location[cursite]->siege.cameras_off)
								{

									set_color_easy(RED_ON_BLACK_BRIGHT);
									mvaddchAlt(y + 1, x + 5, CH_BLACK_SMILING_FACE);
								}

								else if ((levelmap[x][y][locz].siegeflag & SIEGEFLAG_UNIT_DAMAGED) &&
									(location[cursite]->compound_walls & COMPOUND_CAMERAS) && !location[cursite]->siege.cameras_off)
								{

									set_color_easy(RED_ON_BLACK);
									mvaddchAlt(y + 1, x + 5, CH_BLACK_SMILING_FACE);
								}

								else if (levelmap[x][y][locz].special == SPECIAL_STAIRS_UP)
								{

									set_color_easy(YELLOW_ON_BLACK_BRIGHT);
									mvaddchAlt(y + 1, x + 5, CH_UPWARDS_ARROW);
								}

								else if (levelmap[x][y][locz].special == SPECIAL_STAIRS_DOWN)
								{

									set_color_easy(YELLOW_ON_BLACK_BRIGHT);
									mvaddchAlt(y + 1, x + 5, CH_DOWNWARDS_ARROW);
								}

								else if (levelmap[x][y][locz].special != -1)
								{

									set_color_easy(YELLOW_ON_BLACK_BRIGHT);
									mvaddchAlt(y + 1, x + 5, '!');
								}


								else if (levelmap[x][y][locz].siegeflag & SIEGEFLAG_TRAP)
								{

									set_color_easy(YELLOW_ON_BLACK_BRIGHT);
									mvaddchAlt(y + 1, x + 5, '!');
								}


								else if (levelmap[x][y][locz].flag & SITEBLOCK_LOOT)
								{

									set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
									mvaddchAlt(y + 1, x + 5, '$');
								}
								else mvaddchAlt(y + 1, x + 5, ' ');
							}
						}





						else
						{

							set_color_easy(BLACK_ON_BLACK_BRIGHT);
							mvaddchAlt(y + 1, x + 5, CH_FULL_BLOCK);
						}
					}
				}



				getkey();
			}

			if (enemy&&c == 'f')
			{










				// Don't subdue squad if someone is still in good condition.
				bool cannotsubdue = false;
				for (int j = 0; j < 6 && !cannotsubdue; j++)
				{

					if (activesquad->squad[j] &&
						activesquad->squad[j]->alive &&
						activesquad->squad[j]->blood > 40)
					{
						cannotsubdue = true;
					}
				}
				// Cops can subdue and arrest the squad.

				bool subdue = false;
				for (int i = 0; i < ENCMAX && (!cannotsubdue && !subdue); i++)
				{
					if (encounter[i].exists&&
						encounter[i].blood>60 &&
						(encounter[i].type == CREATURE_COP))
					{
						subdue = true;
					}
				}






				if (subdue)
					fight_subdued();
				else
				{

					youattack();
					enemyattack();
					creatureadvance();
					encounter_timer++;
				}
			}


			if (c == 'r'&&location[cursite]->siege.siege&&libnum > 6)
			{

				assemblesquad(activesquad);
				autopromote(cursite);
			}

			else if (freeable && (!enemy || !sitealarm) && c == 'r'&&!location[cursite]->siege.siege)
			{

				short followers = 0, actgot = 0;
				if (enemy)sitealarm = 1;
				bool flipstart, freed;
				do
				{


					flipstart = 0, freed = 0;
					for (int e = 0; e < ENCMAX; e++)
					{

						if (!encounter[e].exists)break;
						if ((encounter[e].type == CREATURE_WORKER_SERVANT ||
							encounter[e].type == CREATURE_WORKER_FACTORY_CHILD ||
							encounter[e].type == CREATURE_WORKER_SWEATSHOP ||
							(strcmp(encounter[e].name, "Prisoner") == 0 && encounter[e].align == 1)) && !flipstart)
						{

							if (strcmp(encounter[e].name, "Prisoner") == 0)
							{

								sitealarm = 1; /* alarm for prisoner escape */
								criminalize(encounter[e], LAWFLAG_ESCAPED);
							}

							followers++, flipstart = 1, freed = 1;
							if (partysize < 6)
							{

								int i;
								// Check for people who can recruit followers
								for (i = 0; i < 6; i++)
									if (activesquad->squad[i] != NULL)
										if (subordinatesleft(*activesquad->squad[i]))
											break;
								// If someone can, add this person as a newly recruited Liberal!
								if (i != 6)
								{

									Creature *newcr = new Creature;
									*newcr = encounter[e];
									newcr->namecreature();
									newcr->location = activesquad->squad[i]->location;
									newcr->base = activesquad->squad[i]->base;
									newcr->hireid = activesquad->squad[i]->id;
									pool.push_back(newcr);
									stat_recruits++;
									for (int p = 0; p < 6; p++)
									{

										if (activesquad->squad[p] == NULL)
										{

											activesquad->squad[p] = newcr;
											newcr->squadid = activesquad->id;
											break;
										}
									}


									actgot++, partysize++;
								}
							}
						}



						if (flipstart)
							if (e < ENCMAX - 1)encounter[e] = encounter[e + 1];
					}

					if (flipstart)encounter[ENCMAX - 1].exists = 0;
					if (freed)
					{

						int time = 20 + LCSrandom(10);
						if (time < 1)time = 1;
						if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
					}

				} while (freed);
				if (followers > 0)
				{

					clearmessagearea();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(16,  1, "You free ", gamelog);
					if (followers > 1)addstrAlt("some Oppressed Liberals", gamelog);
					else addstrAlt("an Oppressed Liberal", gamelog);
					addstrAlt(" from the Conservatives.", gamelog);
					gamelog.newline();
					if (actgot < followers)
					{

						getkey();
						clearmessagearea();
						set_color_easy(WHITE_ON_BLACK_BRIGHT);

						if (actgot == 0 && followers>1)mvaddstrAlt(16, 1, "They all leave", gamelog);
						else if (followers - actgot > 1)mvaddstrAlt(16, 1, "Some leave", gamelog);
						else if (actgot == 0)mvaddstrAlt(16, 1, "The Liberal leaves", gamelog);
						else mvaddstrAlt(16, 1, "One Liberal leaves", gamelog);
						addstrAlt(" you, feeling safer getting out alone.", gamelog);
						gamelog.newline();
					}

					getkey();
				}
			}


			else if (c == 'r'&&hostages)
				releasehostage();
			if (c >= '1'&&c <= '6')
				if (activesquad->squad[c - '1'] != NULL)
				{

					if (party_status == c - '1')fullstatus(party_status);
					else party_status = c - '1';
				}

			if (c == 'e')
			{

				mapshowing = false;
				equip(activesquad->loot, -1);
				if (enemy&&sitealarm)enemyattack();
				else if (enemy)disguisecheck(encounter_timer);
				creatureadvance();
				encounter_timer++;
				mapshowing = true;
			}

			if (c == 'g' && (len(groundloot) || (levelmap[locx][locy][locz].flag&SITEBLOCK_LOOT)))
			{

				bool tookground = 0;
				if (levelmap[locx][locy][locz].flag&SITEBLOCK_LOOT)
				{

					levelmap[locx][locy][locz].flag &= ~SITEBLOCK_LOOT;
					if (location[cursite]->siege.siege)
					{

						//GRAB SOME OF THE BASE LOOT
						int lcount = 1; //1 FROM THE ONE DELETED ABOVE
						for (int x = 0; x < MAPX; x++)
							for (int y = 0; y < MAPY; y++)
								for (int z = 0; z < MAPZ; z++)
									if (levelmap[x][y][z].flag&SITEBLOCK_LOOT)
										lcount++;
						int lplus = len(location[cursite]->loot) / lcount;
						if (lcount == 1) lplus = len(location[cursite]->loot);
						Item *it;
						int b;
						for (; lplus > 0; lplus--)
						{

							b = LCSrandom(len(location[cursite]->loot));
							it = location[cursite]->loot[b];
							activesquad->loot.push_back(it);
							location[cursite]->loot.erase(location[cursite]->loot.begin() + b);
						}
					}


					else
					{

						int time = 20 + LCSrandom(10);
						if (time < 1)time = 1;
						if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
						Item *item;
						string newLootType, newWeaponType, newArmorType;

						switch (sitetype)
						{

						case SITE_RESIDENTIAL_TENEMENT:
							if (!LCSrandom(25))
							{

								string rndWeps[] = { tag_WEAPON_BASEBALLBAT, tag_WEAPON_CROWBAR, tag_WEAPON_SHANK,
									tag_WEAPON_SYRINGE, tag_WEAPON_CHAIN, tag_WEAPON_GUITAR,tag_WEAPON_SPRAYCAN };
								newWeaponType = pickrandom(rndWeps);
							}

							else if (!LCSrandom(20))
							{

								string rndArmors[] = { tag_ARMOR_CHEAPDRESS, tag_ARMOR_CHEAPSUIT, tag_ARMOR_CLOTHES, tag_ARMOR_TRENCHCOAT,
									tag_ARMOR_WORKCLOTHES, tag_ARMOR_TOGA, tag_ARMOR_PRISONER };
								newArmorType = pickrandom(rndArmors);
							}

							else if (!LCSrandom(3))newLootType = tag_LOOT_KIDART;
							else if (!LCSrandom(2))newLootType = tag_LOOT_DIRTYSOCK;
							else newLootType = tag_LOOT_FAMILYPHOTO;
							break;
						case SITE_BUSINESS_BANK:
							if (!LCSrandom(4))newLootType = tag_LOOT_WATCH;
							else if (!LCSrandom(3))newLootType = tag_LOOT_CELLPHONE;
							else if (!LCSrandom(2))newLootType = tag_LOOT_PDA;
							else newLootType = tag_LOOT_COMPUTER;
							break;
						case SITE_RESIDENTIAL_APARTMENT:
							if (!LCSrandom(25))
							{

								string rndWeps[] = { tag_WEAPON_BASEBALLBAT, tag_WEAPON_REVOLVER_38,
									tag_WEAPON_REVOLVER_44, tag_WEAPON_NIGHTSTICK, tag_WEAPON_GUITAR };
								newWeaponType = pickrandom(rndWeps);
							}

							else if (!LCSrandom(20))
							{

								string rndArmors[] = { tag_ARMOR_CHEAPDRESS, tag_ARMOR_CHEAPSUIT, tag_ARMOR_CLOTHES, tag_ARMOR_TRENCHCOAT,
									tag_ARMOR_WORKCLOTHES, tag_ARMOR_CLOWNSUIT, tag_ARMOR_ELEPHANTSUIT, tag_ARMOR_DONKEYSUIT };
								newArmorType = pickrandom(rndArmors);
							}

							else if (!LCSrandom(5))newLootType = tag_LOOT_CELLPHONE;
							else if (!LCSrandom(4))newLootType = tag_LOOT_SILVERWARE;
							else if (!LCSrandom(3))newLootType = tag_LOOT_TRINKET;
							else if (!LCSrandom(2))newLootType = tag_LOOT_CHEAPJEWELERY;
							else newLootType = tag_LOOT_COMPUTER;
							break;
						case SITE_RESIDENTIAL_APARTMENT_UPSCALE:
							if (!LCSrandom(30))
							{

								string rndWeps[] = { tag_WEAPON_BASEBALLBAT, tag_WEAPON_COMBATKNIFE, tag_WEAPON_DAISHO, tag_WEAPON_SHOTGUN_PUMP,
									tag_WEAPON_REVOLVER_44, tag_WEAPON_SEMIPISTOL_45, tag_WEAPON_SEMIRIFLE_AR15, tag_WEAPON_AUTORIFLE_M16 };
								//make sure the number of types matches the random range...
								newWeaponType = rndWeps[LCSrandom(6 - lawList[LAW_GUNCONTROL])];
							}

							else if (!LCSrandom(20))
							{

								string rndArmors[] = { tag_ARMOR_EXPENSIVEDRESS, tag_ARMOR_BLACKDRESS, tag_ARMOR_EXPENSIVESUIT, tag_ARMOR_BLACKSUIT,
									tag_ARMOR_BONDAGEGEAR, tag_ARMOR_CIVILLIANARMOR, tag_ARMOR_BLACKROBE, tag_ARMOR_LABCOAT };
								newArmorType = pickrandom(rndArmors);
							}

							else if (!LCSrandom(10))newLootType = tag_LOOT_EXPENSIVEJEWELERY;
							else if (!LCSrandom(5))newLootType = tag_LOOT_CELLPHONE;
							else if (!LCSrandom(4))newLootType = tag_LOOT_SILVERWARE;
							else if (!LCSrandom(3))newLootType = tag_LOOT_PDA;
							else if (!LCSrandom(2))newLootType = tag_LOOT_CHEAPJEWELERY;
							else newLootType = tag_LOOT_COMPUTER;
							break;
						case SITE_LABORATORY_COSMETICS:
						case SITE_INDUSTRY_NUCLEAR:
						case SITE_LABORATORY_GENETIC:
							if (!LCSrandom(20))newLootType = tag_LOOT_RESEARCHFILES;
							else if (!LCSrandom(2))newLootType = tag_LOOT_LABEQUIPMENT;
							else if (!LCSrandom(2))newLootType = tag_LOOT_COMPUTER;
							else if (!LCSrandom(5))newLootType = tag_LOOT_PDA;
							else if (!LCSrandom(5))newLootType = tag_LOOT_CHEMICAL;
							else newLootType = tag_LOOT_COMPUTER;
							break;
						case SITE_GOVERNMENT_POLICESTATION:
							if (!LCSrandom(25))
							{

								string rndWeps[] = { tag_WEAPON_NIGHTSTICK, tag_WEAPON_NIGHTSTICK, tag_WEAPON_SHOTGUN_PUMP, tag_WEAPON_SEMIPISTOL_9MM,
									tag_WEAPON_SMG_MP5, tag_WEAPON_CARBINE_M4, tag_WEAPON_AUTORIFLE_M16, tag_WEAPON_AUTORIFLE_M16 };
								//make sure the number of types matches the random range...
								newWeaponType = rndWeps[LCSrandom(4) + 2 - lawList[LAW_GUNCONTROL]];
							}

							else if (!LCSrandom(25))
							{

								string rndArmors[] = { tag_ARMOR_POLICEUNIFORM, tag_ARMOR_POLICEUNIFORM, tag_ARMOR_POLICEARMOR, tag_ARMOR_POLICEUNIFORM,
									tag_ARMOR_SWATARMOR, tag_ARMOR_POLICEUNIFORM, tag_ARMOR_POLICEARMOR, tag_ARMOR_DEATHSQUADUNIFORM };
								//make sure the number of types matches the random range...
								newArmorType = rndArmors[LCSrandom(4) + 2 - lawList[LAW_GUNCONTROL]];
							}

							else if (!LCSrandom(20))newLootType = tag_LOOT_POLICERECORDS;
							else if (!LCSrandom(3))newLootType = tag_LOOT_CELLPHONE;
							else if (!LCSrandom(2))newLootType = tag_LOOT_PDA;
							else newLootType = tag_LOOT_COMPUTER;
							break;
						case SITE_GOVERNMENT_COURTHOUSE:
							if (!LCSrandom(20))newLootType = tag_LOOT_JUDGEFILES;
							else if (!LCSrandom(3))newLootType = tag_LOOT_CELLPHONE;
							else if (!LCSrandom(2))newLootType = tag_LOOT_PDA;
							else newLootType = tag_LOOT_COMPUTER;
							break;
						case SITE_GOVERNMENT_PRISON:
							if (!LCSrandom(5))
								newArmorType = tag_ARMOR_PRISONER;
							else newWeaponType = tag_WEAPON_SHANK;
							break;
						case SITE_GOVERNMENT_WHITE_HOUSE:
							if (!LCSrandom(20))newLootType = tag_LOOT_SECRETDOCUMENTS;
							else if (!LCSrandom(3))newLootType = tag_LOOT_CELLPHONE;
							else if (!LCSrandom(2))newLootType = tag_LOOT_PDA;
							else newLootType = tag_LOOT_COMPUTER;
							break;
						case SITE_GOVERNMENT_ARMYBASE:
							if (!LCSrandom(3))
							{

								string rndWeps[] = { tag_WEAPON_SEMIPISTOL_9MM, tag_WEAPON_CARBINE_M4, tag_WEAPON_AUTORIFLE_M16 };
								newWeaponType = pickrandom(rndWeps);
							}

							else if (!LCSrandom(2))
							{

								string rndArmors[] = { tag_ARMOR_ARMYARMOR };
								newArmorType = pickrandom(rndArmors);
							}

							else if (!LCSrandom(20))newLootType = tag_LOOT_SECRETDOCUMENTS;
							else if (!LCSrandom(3))newLootType = tag_LOOT_CELLPHONE;
							else if (!LCSrandom(2))newLootType = tag_LOOT_WATCH;
							else newLootType = tag_LOOT_TRINKET;
							break;
						case SITE_GOVERNMENT_INTELLIGENCEHQ:
							if (!LCSrandom(24))
							{

								string rndWeps[] = { tag_WEAPON_FLAMETHROWER, tag_WEAPON_SEMIPISTOL_45,
									tag_WEAPON_SMG_MP5, tag_WEAPON_CARBINE_M4, tag_WEAPON_AUTORIFLE_M16 };
								newWeaponType = pickrandom(rndWeps);
							}

							else if (!LCSrandom(30))
							{

								string rndArmors[] = { tag_ARMOR_HEAVYARMOR };
								newArmorType = pickrandom(rndArmors);
							}

							else if (!LCSrandom(20))newLootType = tag_LOOT_SECRETDOCUMENTS;
							else if (!LCSrandom(3))newLootType = tag_LOOT_CELLPHONE;
							else if (!LCSrandom(2))newLootType = tag_LOOT_PDA;
							else newLootType = tag_LOOT_COMPUTER;
							break;
						case SITE_GOVERNMENT_FIRESTATION:
							if (!LCSrandom(25)) newArmorType = tag_ARMOR_BUNKERGEAR;
							else if (LCSrandom(2))newLootType = tag_LOOT_TRINKET;
							else newLootType = tag_LOOT_COMPUTER;
							break;
						case SITE_INDUSTRY_SWEATSHOP:
							newLootType = tag_LOOT_FINECLOTH;
							break;
						case SITE_INDUSTRY_POLLUTER:
							newLootType = tag_LOOT_CHEMICAL;
							break;
						case SITE_CORPORATE_HEADQUARTERS:
							if (!LCSrandom(50))newLootType = tag_LOOT_CORPFILES;
							else if (!LCSrandom(3))newLootType = tag_LOOT_CELLPHONE;
							else if (!LCSrandom(2))newLootType = tag_LOOT_PDA;
							else newLootType = tag_LOOT_COMPUTER;
							break;
						case SITE_CORPORATE_HOUSE:
							if (!LCSrandom(50))
							{

								string rndArmors[] = { tag_ARMOR_EXPENSIVEDRESS, tag_ARMOR_EXPENSIVESUIT, tag_ARMOR_EXPENSIVESUIT,
									tag_ARMOR_EXPENSIVESUIT, tag_ARMOR_BONDAGEGEAR };
								newArmorType = pickrandom(rndArmors);
							}

							if (!LCSrandom(8))newLootType = tag_LOOT_TRINKET;
							else if (!LCSrandom(7))newLootType = tag_LOOT_WATCH;
							else if (!LCSrandom(6))newLootType = tag_LOOT_PDA;
							else if (!LCSrandom(5))newLootType = tag_LOOT_CELLPHONE;
							else if (!LCSrandom(4))newLootType = tag_LOOT_SILVERWARE;
							else if (!LCSrandom(3))newLootType = tag_LOOT_CHEAPJEWELERY;
							else if (!LCSrandom(2))newLootType = tag_LOOT_FAMILYPHOTO;
							else newLootType = tag_LOOT_COMPUTER;
							break;
						case SITE_MEDIA_AMRADIO:
							if (!LCSrandom(20))newLootType = tag_LOOT_AMRADIOFILES;
							else if (!LCSrandom(4))newLootType = tag_LOOT_MICROPHONE;
							else if (!LCSrandom(3))newLootType = tag_LOOT_PDA;
							else if (!LCSrandom(2))newLootType = tag_LOOT_CELLPHONE;
							else newLootType = tag_LOOT_COMPUTER;
							break;
						case SITE_MEDIA_CABLENEWS:
							if (!LCSrandom(20))newLootType = tag_LOOT_CABLENEWSFILES;
							else if (!LCSrandom(4))newLootType = tag_LOOT_MICROPHONE;
							else if (!LCSrandom(3))newLootType = tag_LOOT_PDA;
							else if (!LCSrandom(2))newLootType = tag_LOOT_CELLPHONE;
							else newLootType = tag_LOOT_COMPUTER;
							break;
						case SITE_BUSINESS_BARANDGRILL:
						case SITE_OUTDOOR_BUNKER:
						case SITE_RESIDENTIAL_BOMBSHELTER:
							//storming a CCS stronghold. Logically you ought to get all the leftover stuff if you win...
							string rndWeps[] = { tag_WEAPON_SEMIPISTOL_9MM, tag_WEAPON_SEMIPISTOL_45, tag_WEAPON_REVOLVER_38, tag_WEAPON_REVOLVER_44,
								tag_WEAPON_SMG_MP5, tag_WEAPON_CARBINE_M4, tag_WEAPON_AUTORIFLE_M16 };
							string rndArmors[] = { tag_ARMOR_CHEAPSUIT, tag_ARMOR_CLOTHES, tag_ARMOR_TRENCHCOAT, tag_ARMOR_WORKCLOTHES,
								tag_ARMOR_SECURITYUNIFORM, tag_ARMOR_CIVILLIANARMOR, tag_ARMOR_ARMYARMOR, tag_ARMOR_HEAVYARMOR };
							switch (LCSrandom(3))
							{

							case 0:
								newWeaponType = pickrandom(rndWeps);
								break;
							case 1:
								newArmorType = pickrandom(rndArmors);
								break;
							default:
								if (!LCSrandom(5))newLootType = tag_LOOT_CELLPHONE;
								else if (!LCSrandom(4))newLootType = tag_LOOT_SILVERWARE;
								else if (!LCSrandom(3))newLootType = tag_LOOT_TRINKET;
								else if (!LCSrandom(2))newLootType = tag_LOOT_CHEAPJEWELERY;
								else newLootType = tag_LOOT_COMPUTER;
								break;
							}

							break;
						}

						item = NULL;
						if (len(newLootType))
						{

							item = new Loot(*loottype[getloottype(newLootType)]);
							activesquad->loot.push_back(item);
						}

						if (len(newArmorType))
						{

							int quality = 1;
							if (!LCSrandom(3))
								quality = 2;
							Armor *a = new Armor(*armortype[getarmortype(newArmorType)], quality);
							if (!LCSrandom(3))
								a->set_damaged(true);
							item = a;
							activesquad->loot.push_back(item);
						}

						if (len(newWeaponType))
						{

							Weapon *w = new Weapon(*weapontype[getweapontype(newWeaponType)]);
							if (w->uses_ammo())
							{

								if (LCSrandom(2) || //50% chance of being loaded...
													//except for the most exotic weapons, which are always loaded.
									w->get_itemtypename() == tag_WEAPON_DESERT_EAGLE ||
									w->get_itemtypename() == tag_WEAPON_FLAMETHROWER) //Make weapon property? -XML
								{

									vector<int> cti;
									for (int ct = 0; ct < len(cliptype); ct++)
										if (w->acceptable_ammo(*cliptype[ct]))
											cti.push_back(ct);
									Clip c(*cliptype[pickrandom(cti)]);
									w->reload(c);
								}
							}


							item = w;
							activesquad->loot.push_back(item);
						}

						if (item)
						{

							string s = item->equip_title();
							clearmessagearea();
							set_color_easy(WHITE_ON_BLACK);
							mvaddstrAlt(16,  1, "You find: ", gamelog);
							mvaddstrAlt(17,  1, s, gamelog);
							gamelog.newline();
							getkey(); //wait for key press before clearing.
						}
					}


					tookground = 1;
				}

				//MAKE GROUND LOOT INTO MISSION LOOT
				for (int l = 0; l < len(groundloot); l++)
					activesquad->loot.push_back(groundloot[l]);
				groundloot.clear();
				if (enemy&&sitealarm)enemyattack();
				else if (enemy)disguisecheck(encounter_timer);
				if (tookground)
				{

					//int maxsleightofhand=0;
					int beststealer = 0;
					juiceparty(1, 200);
					alienationcheck(0);
					noticecheck(-1);
					sitecrime++;
					sitestory->crime.push_back(CRIME_STOLEGROUND);
					if (enemy)
						criminalize(*(activesquad->squad[beststealer]), LAWFLAG_THEFT);
				}

				creatureadvance();
				encounter_timer++;
			}

			if (c == 'n')
			{

				mapshowing = false;
				eraseAlt();

				set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(0,  0, "Site mode options");
				printparty();
				set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(10,  1, "[ ] E - Encounter warnings");
				mvaddstrAlt(11,  1, "[ ] M - Music");
				set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(24,  1, enter_done);

				int c = 0;
				while (true)
				{

					if (c == 'e') encounterwarnings = !encounterwarnings;
					if (c == 'm') music.enableIf(!music.isEnabled());
					if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR)break;
					if (encounterwarnings)
						mvaddstrAlt(10, 2, "X");

					else mvaddstrAlt(10, 2, singleSpace);
					if (music.isEnabled())
						mvaddstrAlt(11, 2, "X");

					else mvaddstrAlt(11, 2, singleSpace);
					c = getkey();
				}

				mapshowing = true;
			}

			int cbase = -1;
			if (activesquad->squad[0] != NULL)
				cbase = activesquad->squad[0]->base;
			if (locx != olocx || locy != olocy || locz != olocz || c == 's')
			{

				//NEED TO GO BACK TO OLD LOCATION IN CASE COMBAT
				//REFRESHES THE SCREEN
				long nlocx = locx, nlocy = locy, nlocz = locz;
				locx = olocx, locy = olocy, locz = olocz;
				//ENEMIES SHOULD GET FREE SHOTS NOW
				if (enemy&&sitealarm)
				{

					//bool snuck_away = true;
					int e;
					// Try to sneak past
					for (e = 0; e < ENCMAX; e++)
					{

						if (encounter[e].exists &&
							encounter[e].alive  &&
							encounter[e].cantbluff == 2)
						{

							// You can't sneak past this person; they already know you're there
							break;
						}
					}


					// If you can sneak past all enemies
					if (e == ENCMAX)
					{

						int breakout = false;
						for (e = 0; e < ENCMAX; e++)
						{

							if (!encounter[e].exists)continue;
							for (int i = 0; i < 6; i++)
							{

								if (activesquad->squad[i])
								{

									int roll = activesquad->squad[i]->skill_roll(SKILL_STEALTH);
									if (roll + 1 == DIFFICULTY_HARD && fieldskillrate == FIELDSKILLRATE_HARD)
										activesquad->squad[i]->train(SKILL_STEALTH, 10);
									if (roll < DIFFICULTY_HARD)
									{

										breakout = true;
										break;
									}
								}
							}



							if (breakout) break;
						}
					}


					// If snuck past everyone
					if (e == ENCMAX)
					{

						for (int i = 0; i < 6; i++)
						{

							if (activesquad->squad[i] != NULL)
							{

								switch (fieldskillrate)
								{

								case FIELDSKILLRATE_FAST:
									activesquad->squad[i]->train(SKILL_STEALTH, 40); break;
								case FIELDSKILLRATE_CLASSIC:
									activesquad->squad[i]->train(SKILL_STEALTH, 10); break;
								case FIELDSKILLRATE_HARD:
									activesquad->squad[i]->train(SKILL_STEALTH, 0); break;
								}
							}
						}



						clearmessagearea();
						set_color_easy(CYAN_ON_BLACK_BRIGHT);
						mvaddstrAlt(16,  1, "The squad sneaks past the conservatives!", gamelog);
						gamelog.newline();
						getkey();
					}

					else
						enemyattack();
				}

				else if (enemy)disguisecheck(encounter_timer);
				creatureadvance();
				encounter_timer++;
				partyalive = squadalive(activesquad);




				if (partyalive == 0) {}
				else {


					//AFTER DEATH CHECK CAN MOVE BACK TO NEW LOCATION
					locx = nlocx, locy = nlocy, locz = nlocz;
					//CHECK FOR EXIT
					if ((levelmap[locx][locy][locz].flag & SITEBLOCK_EXIT) ||
						(cbase == cursite&&!location[cursite]->siege.siege&&
							bail_on_base))
					{

						// Seperate logging message.
						gamelog.record(activesquad->name);
						gamelog.record(" has left ");
						if (location[cursite]->front_business != -1)
							gamelog.record(location[cursite]->front_name);
						else
							gamelog.record(location[cursite]->name);
						gamelog.record(singleDot);
						gamelog.nextMessage();
						//RESET MODE PRIOR TO CHASE
						showcarprefs = 0;
						//CHASE SEQUENCE OR FOOT CHASE
						chaseseq.clean();
						chaseseq.location = cursite;
						long level = sitecrime;
						if (sitealarm == 0)level = 0;
						if (LCSrandom(3) && level < 4)level = 0;
						if (LCSrandom(2) && level < 8)level = 0;
						if (postalarmtimer < 10 + (int)LCSrandom(20))level = 0;
						else if (postalarmtimer < 20 + (int)LCSrandom(20) && LCSrandom(3))level = 0;
						else if (postalarmtimer < 40 + (int)LCSrandom(20) && !LCSrandom(3))level = 0;
						if (location[cursite]->siege.siege)level = 1000;
						//MAKE SURE YOU ARE GUILTY OF SOMETHING
						bool guilty = 0;
						for (p = 0; p < 6; p++)
							if (activesquad->squad[p] != NULL)
								if (iscriminal(*activesquad->squad[p]))guilty = 1;
						if (!guilty)level = 0;
						makechasers(sitetype, level);
						bool havecar = 0;
						for (p = 0; p < 6; p++)
						{

							if (activesquad->squad[p] != NULL)
							{

								if (activesquad->squad[p]->carid != -1)
								{

									havecar = 1;
									for (int i = 0; i < 6; i++)
									{

										if (activesquad->squad[i] != NULL&&
											activesquad->squad[i]->carid == -1)
										{

											activesquad->squad[i]->carid = activesquad->squad[p]->carid;
										}
									}


									break;
								}
							}
						}



						bool gotout;
						if (havecar)gotout = chasesequence();
						else gotout = footchase();
						//If you survived
						if (gotout)
						{

							//Check for hauled prisoners/corpses
							for (p = 0; p < 6; p++)
							{

								if (activesquad->squad[p] == NULL)continue;
								if (activesquad->squad[p]->prisoner != NULL)
								{

									//If this is an LCS member or corpse being hauled (marked as in the squad)
									if (activesquad->squad[p]->prisoner->squadid != -1)
									{

										//Take them out of the squad
										activesquad->squad[p]->prisoner->squadid = -1;
										//Set base and current location to squad's safehouse
										activesquad->squad[p]->prisoner->location = activesquad->squad[p]->base;
										activesquad->squad[p]->prisoner->base = activesquad->squad[p]->base;
									}

									else //A kidnapped conservative
									{

										//Convert them into a prisoner
										kidnaptransfer(*activesquad->squad[p]->prisoner);
										delete activesquad->squad[p]->prisoner;
									}

									activesquad->squad[p]->prisoner = NULL;
								}
							}


							//Clear all bleeding and prison escape flags
							for (p = 0; p < len(pool); p++)
							{

								pool[p]->flag &= ~CREATUREFLAG_JUSTESCAPED;
								for (int w = 0; w < BODYPARTNUM; w++)
								{

									pool[p]->wound[w] &= ~WOUND_BLEEDING;
								}
							}


							//END SITE MODE
							if (location[cursite]->siege.siege)
							{

								//Special handling for escaping siege
								escapesiege(0);
							}

							else
							{

								resolvesite();
							}
						}


						//You didn't survive -- handle squad death (unless that ended the game)
						else if (!endcheck())
						{

							if (location[cursite]->siege.siege)
							{

								//Report on squad killed during siege
								if (location[cursite]->siege.underattack)sitestory->type = NEWSSTORY_SQUAD_KILLED_SIEGEATTACK;
								else sitestory->type = NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE;
								location[cursite]->siege.siege = 0;
							}

							else
							{

								//Or report on your failed raid
								sitestory->type = NEWSSTORY_SQUAD_KILLED_SITE;
								//Would juice the party here, but you're all dead, so...
								resolvesite();
							}
						}


						sitealarm = 0;
						mode = GAMEMODE_BASE;
						return;
					}

					//SEE IF THERE IS AN ENCOUNTER
					char newenc = 0;
					// 10% chance of encounter normally (100% if waiting)
					// 20% chance of encounter after massive response
					// 0% chance of encounter during sieges
					if (!location[cursite]->siege.siege)
					{

						if (postalarmtimer > 80) { if (!LCSrandom(5)) newenc = 1; }
						else if (!LCSrandom(10) || c == 's') newenc = 1;
					}

					for (int e = 0; e < ENCMAX; e++) if (encounter[e].exists) newenc = 0;
					// Handle special tiles that activate when you step on them
					// (rather than those that must be manually activated)
					long makespecial = -1;
					switch (levelmap[locx][locy][locz].special)
					{

					case SPECIAL_SECURITY_CHECKPOINT:
					case SPECIAL_SECURITY_METALDETECTORS:
					case SPECIAL_SECURITY_SECONDVISIT:
					case SPECIAL_CLUB_BOUNCER:
					case SPECIAL_CLUB_BOUNCER_SECONDVISIT:
					case SPECIAL_APARTMENT_LANDLORD:
					case SPECIAL_HOUSE_CEO:
					case SPECIAL_RESTAURANT_TABLE:
					case SPECIAL_CAFE_COMPUTER:
					case SPECIAL_PARK_BENCH:
					case SPECIAL_BANK_TELLER:
					case SPECIAL_CCS_BOSS:
					case SPECIAL_OVAL_OFFICE_NW:
					case SPECIAL_OVAL_OFFICE_NE:
					case SPECIAL_OVAL_OFFICE_SW:
					case SPECIAL_OVAL_OFFICE_SE:
						makespecial = levelmap[locx][locy][locz].special;
						newenc = 1;
						break;
					}

					//DO DOORS
					if (levelmap[locx][locy][locz].flag & SITEBLOCK_DOOR)
					{

						open_door(levelmap[olocx][olocy][olocz].flag&SITEBLOCK_RESTRICTED);
						locx = olocx, locy = olocy, locz = olocz;
						if (encsize > 0) newenc = 0;
					}

					//BAIL UPON VICTORY (version 2 -- defeated CCS safehouse)
					if (ccs_boss_kills >= 1 &&
						!location[cursite]->siege.siege &&
						location[cursite]->renting == RENTING_CCS)
					{

						music.play(MUSIC_CONQUER);
						//DEAL WITH PRISONERS AND STOP BLEEDING
						for (p = 0; p < 6; p++)
						{

							if (activesquad->squad[p] == NULL)continue;
							if (activesquad->squad[p]->prisoner != NULL)
							{

								if (activesquad->squad[p]->prisoner->squadid != -1)
								{

									//RESTORE POOL MEMBER
									activesquad->squad[p]->prisoner->squadid = -1;
									//MUST LOCATE THE MEMBER
									activesquad->squad[p]->prisoner->location = activesquad->squad[p]->base;
									activesquad->squad[p]->prisoner->base = activesquad->squad[p]->base;
								}
								else
								{



									//CONVERT KIDNAP VICTIM
									kidnaptransfer(*activesquad->squad[p]->prisoner);
									delete activesquad->squad[p]->prisoner;
								}

								activesquad->squad[p]->prisoner = NULL;
							}
						}


						for (p = 0; p < len(pool); p++)
						{

							pool[p]->flag &= ~CREATUREFLAG_JUSTESCAPED;
							for (int w = 0; w < BODYPARTNUM; w++)
							{

								pool[p]->wound[w] &= ~WOUND_BLEEDING;
							}
						}


						//INFORM
						clearmessagearea();
						set_color_easy(GREEN_ON_BLACK_BRIGHT);
						mvaddstrAlt(16,  1, "The CCS has been broken!", gamelog);
						gamelog.newline();
						getkey();
						location[cursite]->renting = RENTING_PERMANENT;
						location[cursite]->closed = 0;
						location[cursite]->heat = 100;
						// CCS Safehouse killed?
						if (location[cursite]->type == SITE_RESIDENTIAL_BOMBSHELTER ||
							location[cursite]->type == SITE_BUSINESS_BARANDGRILL ||
							location[cursite]->type == SITE_OUTDOOR_BUNKER)
						{

							ccs_kills++;
							if (ccs_kills < 3) endgamestate--;
							else endgamestate = ENDGAME_CCS_DEFEATED;
						}

						conquertextccs();
						//RESET MODE
						mode = GAMEMODE_BASE;
						showcarprefs = 0;
						return;
					}

					if (location[cursite]->siege.siege) // *JDS* police response added
					{

						if (locx != olocx || locy != olocy || locz != olocz)
							emptyEncounter();

						//MOVE SIEGE UNITS AROUND
						//MOVE UNITS
						vector<int> unitx, unity, unitz;
						for (x = 0; x < MAPX; x++) for (int y = 0; y < MAPY; y++) for (int z = 0; z < MAPZ; z++)
							if (levelmap[x][y][z].siegeflag&SIEGEFLAG_UNIT)
								unitx.push_back(x), unity.push_back(y), unitz.push_back(z);
						int sx = 0, sy = 0, sz = 0;
						for (u = 0; u < len(unitx); u++)
						{

							// don't leave tile if player is here
							if (unitx[u] == locx&&unity[u] == locy&&unitz[u] == locz) continue;
							// move into player's tile if possible
							if ((((unitx[u] == locx - 1 || unitx[u] == locx + 1) &&
								unity[u] == locy) ||
								((unity[u] == locy - 1 || unity[u] == locy + 1) &&
									unitx[u] == locx))
								&& unitz[u] == locz)
							{

								levelmap[unitx[u]][unity[u]][unitz[u]].siegeflag &= ~SIEGEFLAG_UNIT;
								//Get torched
								if (levelmap[locx][locy][locz].flag & SITEBLOCK_FIRE_PEAK)
									levelmap[locx][locy][locz].siegeflag |= SIEGEFLAG_UNIT_DAMAGED;
								//BLOW TRAPS
								if (levelmap[locx][locy][locz].siegeflag & SIEGEFLAG_TRAP)
								{

									levelmap[locx][locy][locz].siegeflag &= ~SIEGEFLAG_TRAP;
									levelmap[locx][locy][locz].siegeflag |= SIEGEFLAG_UNIT_DAMAGED;
								}

								else levelmap[locx][locy][locz].siegeflag |= SIEGEFLAG_UNIT;
								continue;
							}

							sz = 0;
							switch (LCSrandom(4))
							{

							case 0: sx = -1, sy = 0; break;
							case 1: sx = 1, sy = 0; break;
							case 2: sx = 0, sy = 1; break;
							case 3: sx = 0, sy = -1; break;
							}

							sx += unitx[u], sy += unity[u], sz += unitz[u];
							if (sx >= 0 && sx < MAPX&&sy >= 0 && sy < MAPY&&sz >= 0 && sz < MAPZ)
								if (!(levelmap[sx][sy][sz].flag&SITEBLOCK_BLOCK))
								{

									if ((levelmap[sx][sy][sz].flag&SITEBLOCK_DOOR))
										levelmap[sx][sy][sz].flag &= ~(SITEBLOCK_DOOR | SITEBLOCK_LOCKED | SITEBLOCK_KLOCK | SITEBLOCK_CLOCK);
									else

									{  //BLOCK PASSAGE
										if (!(levelmap[sx][sy][sz].siegeflag&(SIEGEFLAG_UNIT | SIEGEFLAG_HEAVYUNIT)))
										{

											levelmap[unitx[u]][unity[u]][unitz[u]].siegeflag &= ~SIEGEFLAG_UNIT;
											//BLOW TRAPS
											if (levelmap[sx][sy][sz].siegeflag&SIEGEFLAG_TRAP)
											{

												levelmap[sx][sy][sz].siegeflag &= ~SIEGEFLAG_TRAP;
												levelmap[sx][sy][sz].siegeflag |= SIEGEFLAG_UNIT_DAMAGED;
											}

											else levelmap[sx][sy][sz].siegeflag |= SIEGEFLAG_UNIT;
										}
									}
								}
						}




						unitx.clear(), unity.clear(), unitz.clear();
						/*

						//MOVE HEAVY UNITS
						for(x=0;x<MAPX;x++) for(int y=0;y<MAPY;y++) for(int z=0;z<MAPZ;z++)
						if(levelmap[x][y][z].siegeflag&SIEGEFLAG_HEAVYUNIT)
						unitx.push_back(x),unity.push_back(y),unitz.push_back(z);
						for(u=0;u<len(unitx);u++)
						{

						sz=0;
						switch(LCSrandom(4))
						{

						case 0: sx=-1,sy=0; break;
						case 1: sx=1,sy=0; break;
						case 2: sx=0,sy=1; break;
						case 3: sx=0,sy=-1; break;
						}

						sx+=unitx[u],sy+=unity[u],sz+=unitz[u];
						if(sx>=0&&sx<MAPX&&sy>=0&&sy<MAPY&&sz>=0&&sz<MAPZ)
						{

						if(!(levelmap[sx][sy][sz].flag&SITEBLOCK_BLOCK))
						{

						if((levelmap[sx][sy][sz].flag&SITEBLOCK_DOOR))
						levelmap[sx][sy][sz].flag&=~(SITEBLOCK_DOOR|SITEBLOCK_LOCKED|SITEBLOCK_KLOCK|SITEBLOCK_CLOCK);
						else
						{  //BLOCK PASSAGE
						if(!(levelmap[sx][sy][sz].siegeflag&(SIEGEFLAG_UNIT|SIEGEFLAG_HEAVYUNIT)))
						{

						levelmap[unitx[u]][unity[u]][unitz[u]].siegeflag&=~SIEGEFLAG_HEAVYUNIT;
						levelmap[sx][sy][sz].siegeflag|=SIEGEFLAG_HEAVYUNIT;
						//BLOW (DIFFUSE) TRAPS
						levelmap[sx][sy][sz].siegeflag&=~SIEGEFLAG_TRAP;
						}
						}
						}



						else if(sy>=3&&sx>0&&sx<MAPX-1&&sy<MAPY-1) //BREAK WALLS
						{

						sitechangest change(sx,sy,sz,SITEBLOCK_DEBRIS);
						location[cursite]->changes.push_back(change);
						levelmap[sx][sy][sz].flag&=~SITEBLOCK_BLOCK;
						levelmap[sx][sy][sz].flag|=SITEBLOCK_DEBRIS;
						}
						}
						}



						unitx.clear(),unity.clear(),unitz.clear();
						// End Heavy Units
						*/

						for (u = 0; u < len(unitx); u++)
						{

							sz = 0;
							switch (LCSrandom(4))
							{

							case 0: sx = -1, sy = 0; break;
							case 1: sx = 1, sy = 0; break;
							case 2: sx = 0, sy = 1; break;
							case 3: sx = 0, sy = -1; break;
							}

							sx += unitx[u], sy += unity[u], sz += unitz[u];
							if (sx >= 0 && sx < MAPX&&sy >= 0 && sy < MAPY&&sz >= 0 && sz < MAPZ)
								if (!(levelmap[sx][sy][sz].flag&SITEBLOCK_BLOCK) && (levelmap[sx][sy][sz].flag&SITEBLOCK_DOOR))
									levelmap[sx][sy][sz].flag &= ~(SITEBLOCK_DOOR | SITEBLOCK_LOCKED | SITEBLOCK_KLOCK | SITEBLOCK_CLOCK);
						}

						unitx.clear(), unity.clear(), unitz.clear();
						//NEW WAVES
						//IF THERE AREN'T ENOUGH UNITS AROUND
						//AND THEY HAVEN'T BEEN SCARED OFF
						//MORE WAVES WILL ATTACK
						//AND IT GETS WORSE AND WORSE
						//but not as bad as it used to get,
						//since the extra waves are small
						location[cursite]->siege.attacktime++;
						if ((location[cursite]->siege.attacktime >= 100 + LCSrandom(10) &&
							(locz != 0 || locx<(MAPX / 2 - 3) || locx>(MAPX / 2 + 3) ||
								locy>5)))
						{

							location[cursite]->siege.attacktime = 0;
							int existingUnits = 0;
							for (int x = 0; x < MAPX; x++) for (int y = 0; y < MAPY; y++) for (int z = 0; z < MAPZ; z++)
								if (levelmap[x][y][z].siegeflag&(SIEGEFLAG_UNIT | SIEGEFLAG_HEAVYUNIT))
									existingUnits++;
							//PLACE UNITS
							int lx, ly, lz, unitnum = 7 - existingUnits, count = 10000;
							if (unitnum < 0)unitnum = 0;
							for (int t = 0; t < unitnum; t++)
							{

								count = 10000;
								do
								{


									lx = LCSrandom(7) + (MAPX / 2) - 3, ly = LCSrandom(5), lz = 0, count--;
									if (count == 0) break;
								} while ((levelmap[lx][ly][lz].flag & (SITEBLOCK_BLOCK | SITEBLOCK_DOOR | SITEBLOCK_EXIT)) ||
									(levelmap[lx][ly][lz].siegeflag & (SIEGEFLAG_UNIT | SIEGEFLAG_HEAVYUNIT | SIEGEFLAG_TRAP)));
								levelmap[lx][ly][lz].siegeflag |= SIEGEFLAG_UNIT;
							}

							if (!(location[cursite]->compound_walls&COMPOUND_TANKTRAPS) &&
								location[cursite]->siege.siegetype == SIEGE_POLICE&&
								location[cursite]->siege.escalationstate >= 2)
							{

								count = 10000;
								int hunitnum = 1;
								for (int t = 0; t < hunitnum; t++)
								{
									do
									{



										lx = LCSrandom(7) + (MAPX / 2) - 3, ly = LCSrandom(5), lz = 0, count--;
										if (count == 0) break;
									} while ((levelmap[lx][ly][lz].flag&(SITEBLOCK_BLOCK | SITEBLOCK_DOOR | SITEBLOCK_EXIT)) ||
										(levelmap[lx][ly][lz].siegeflag&(SIEGEFLAG_UNIT | SIEGEFLAG_HEAVYUNIT | SIEGEFLAG_TRAP)));
									levelmap[lx][ly][lz].siegeflag |= SIEGEFLAG_HEAVYUNIT;
									location[cursite]->siege.tanks++;
								}
							}
						}



						//CHECK FOR SIEGE UNITS
						//INCLUDING DAMAGED ONES
						if (levelmap[locx][locy][locz].siegeflag&SIEGEFLAG_UNIT)
						{

							if (addsiegeencounter(SIEGEFLAG_UNIT))
								levelmap[locx][locy][locz].siegeflag &= ~SIEGEFLAG_UNIT;
						}

						if (levelmap[locx][locy][locz].siegeflag&SIEGEFLAG_HEAVYUNIT)
						{

							if (addsiegeencounter(SIEGEFLAG_HEAVYUNIT))
								levelmap[locx][locy][locz].siegeflag &= ~SIEGEFLAG_HEAVYUNIT;
						}

						if (levelmap[locx][locy][locz].siegeflag&SIEGEFLAG_UNIT_DAMAGED)
						{

							if (addsiegeencounter(SIEGEFLAG_UNIT_DAMAGED))
								levelmap[locx][locy][locz].siegeflag &= ~SIEGEFLAG_UNIT_DAMAGED;
						}

						//BAIL UPON VICTORY
						if (location[cursite]->siege.kills >= 10 &&
							location[cursite]->siege.tanks < 1 &&
							location[cursite]->siege.siege)
						{

							music.play(MUSIC_CONQUER);
							if (location[cursite]->siege.underattack)sitestory->type = NEWSSTORY_SQUAD_DEFENDED;
							else sitestory->type = NEWSSTORY_SQUAD_BROKESIEGE;
							if (location[cursite]->siege.siegetype == SIEGE_CCS)
							{

								// CCS DOES NOT capture the warehouse -- reverse earlier assumption of your defeat!
								if (location[cursite]->type == SITE_INDUSTRY_WAREHOUSE || SITE_BUSINESS_CRACKHOUSE)
									location[cursite]->renting = RENTING_PERMANENT;
								else if (location[cursite]->type == SITE_RESIDENTIAL_TENEMENT)
									location[cursite]->renting = 200;
								else if (location[cursite]->type == SITE_RESIDENTIAL_APARTMENT)
									location[cursite]->renting = 650;
								else if (location[cursite]->type == SITE_RESIDENTIAL_APARTMENT_UPSCALE)
									location[cursite]->renting = 1500;
							}

							//DEAL WITH PRISONERS AND STOP BLEEDING
							for (p = 0; p < 6; p++)
							{

								if (activesquad->squad[p] == NULL)continue;
								if (activesquad->squad[p]->prisoner != NULL)
								{

									if (activesquad->squad[p]->prisoner->squadid != -1)
									{

										//RESTORE POOL MEMBER
										activesquad->squad[p]->prisoner->squadid = -1;
										//MUST LOCATE THE MEMBER
										activesquad->squad[p]->prisoner->location = activesquad->squad[p]->base;
										activesquad->squad[p]->prisoner->base = activesquad->squad[p]->base;
									}
									else
									{



										//CONVERT KIDNAP VICTIM
										kidnaptransfer(*activesquad->squad[p]->prisoner);
										delete activesquad->squad[p]->prisoner;
									}

									activesquad->squad[p]->prisoner = NULL;
								}
							}


							for (p = 0; p < len(pool); p++)
							{

								pool[p]->flag &= ~CREATUREFLAG_JUSTESCAPED;
								for (int w = 0; w < BODYPARTNUM; w++)
									pool[p]->wound[w] &= ~WOUND_BLEEDING;
							}

							//INFORM
							clearmessagearea();
							set_color_easy(GREEN_ON_BLACK_BRIGHT);
							mvaddstrAlt(16,  1, "The Conservatives have shrunk back under ", gamelog);
							mvaddstrAlt(17,  1, "the power of your Liberal Convictions!", gamelog);
							gamelog.newline();
							getkey();
							conquertext();
							escapesiege(1);
							//RESET MODE
							mode = GAMEMODE_BASE;
							showcarprefs = 0;
							return;
						}
					}


					if (!location[cursite]->siege.siege&&newenc)
					{

						switch (makespecial)
						{

						case SPECIAL_CAFE_COMPUTER:
							if (sitealarm || sitealienate)
							{

								clearmessagearea();
								set_color_easy(WHITE_ON_BLACK_BRIGHT);
								mvaddstrAlt(16,  1, "The computer has been unplugged.", gamelog);
								gamelog.newline();
								levelmap[locx][locy][locz].special = -1;
								getkey();
							}

							else
							{

								clearmessagearea();
								set_color_easy(WHITE_ON_BLACK_BRIGHT);
								mvaddstrAlt(16,  1, "The computer is occupied.", gamelog);
								gamelog.newline();
								levelmap[locx][locy][locz].special = -1;
								getkey();
								prepareencounter(sitetype, 0);
								emptyEncounter();
							}


							break;
						case SPECIAL_RESTAURANT_TABLE:
							if (sitealarm || sitealienate)
							{

								clearmessagearea();
								set_color_easy(WHITE_ON_BLACK_BRIGHT);
								mvaddstrAlt(16,  1, "Some people are hiding under the table.", gamelog);
								gamelog.newline();
								levelmap[locx][locy][locz].special = -1;
								getkey();
								prepareencounter(sitetype, 0);
							}

							else
							{

								clearmessagearea();
								set_color_easy(WHITE_ON_BLACK_BRIGHT);
								mvaddstrAlt(16,  1, "The table is occupied.", gamelog);
								gamelog.newline();
								levelmap[locx][locy][locz].special = -1;
								getkey();
								prepareencounter(sitetype, 0);
							}

							break;
						case SPECIAL_PARK_BENCH:
							if (sitealarm || sitealienate)
							{

								clearmessagearea();
								set_color_easy(WHITE_ON_BLACK_BRIGHT);
								mvaddstrAlt(16,  1, "The bench is empty.", gamelog);
								gamelog.newline();
								levelmap[locx][locy][locz].special = -1;
								getkey();
							}

							else
							{

								clearmessagearea();
								set_color_easy(WHITE_ON_BLACK_BRIGHT);
								mvaddstrAlt(16,  1, "There are people sitting here.", gamelog);
								gamelog.newline();
								levelmap[locx][locy][locz].special = -1;
								getkey();
								prepareencounter(sitetype, 0);
							}

							break;
						case SPECIAL_SECURITY_CHECKPOINT:
							special_security_checkpoint();
							break;
						case SPECIAL_SECURITY_METALDETECTORS:
							special_security_metaldetectors();
							break;
						case SPECIAL_SECURITY_SECONDVISIT:
							special_security_secondvisit();
							break;
						case SPECIAL_CLUB_BOUNCER:
							special_bouncer_assess_squad();
							break;
						case SPECIAL_CLUB_BOUNCER_SECONDVISIT:
							special_bouncer_greet_squad();
							break;
						case SPECIAL_HOUSE_CEO:
							if ((sitealarm || sitealienate || location[cursite]->siege.siege) &&
								uniqueCreatures.CEO_state == UNIQUECREATURE_ALIVE)
							{

								clearmessagearea(false);
								set_color_easy(WHITE_ON_BLACK_BRIGHT);

								if (lawList[LAW_FREESPEECH] != ALIGN_ARCHCONSERVATIVE)
									mvaddstrAlt(16, 1, "Damn! ", gamelog);
								else

									mvaddstrAlt(16, 1, "[Rats!] ", gamelog);
								addstrAlt("The CEO must have fled to a panic room.", gamelog);
								gamelog.newline();
								levelmap[locx][locy][locz].special = -1;
								getkey();
							}

							else
							{

								switch (uniqueCreatures.CEO_state)
								{

								case UNIQUECREATURE_ALIVE:
									clearmessagearea(false);
									set_color_easy(WHITE_ON_BLACK_BRIGHT);
									mvaddstrAlt(16,  1, "The CEO is in his study.", gamelog);
									gamelog.newline();
									levelmap[locx][locy][locz].special = -1;
									getkey();
									emptyEncounter();

									encounter[0] = uniqueCreatures.CEO();
									encounter[0].exists = true;
									break;
								case UNIQUECREATURE_DEAD:
								case UNIQUECREATURE_LIBERAL:
									clearmessagearea(false);
									set_color_easy(WHITE_ON_BLACK_BRIGHT);
									mvaddstrAlt(16,  1, "The CEO's study lies empty.", gamelog);
									gamelog.newline();
									levelmap[locx][locy][locz].special = -1;
									getkey();
									break;
								}
							}


							break;
						case SPECIAL_APARTMENT_LANDLORD:
							if (sitealarm || sitealienate ||
								location[cursite]->siege.siege)
							{

								clearmessagearea(false);
								set_color_easy(WHITE_ON_BLACK_BRIGHT);
								mvaddstrAlt(16,  1, "The landlord is out of the office.", gamelog);
								gamelog.newline();
								levelmap[locx][locy][locz].special = -1;
								getkey();
							}

							else
							{

								clearmessagearea(false);
								set_color_easy(WHITE_ON_BLACK_BRIGHT);
								mvaddstrAlt(16,  1, "The landlord is in.", gamelog);
								gamelog.newline();
								levelmap[locx][locy][locz].special = -1;
								getkey();
								emptyEncounter();

								makecreature(encounter[0], CREATURE_LANDLORD);
							}

							break;
						case SPECIAL_BANK_TELLER:
							special_bank_teller();
							break;
						case SPECIAL_CCS_BOSS:
							special_ccs_boss();
							break;
						case SPECIAL_OVAL_OFFICE_NW:
						case SPECIAL_OVAL_OFFICE_NE:
						case SPECIAL_OVAL_OFFICE_SW:
						case SPECIAL_OVAL_OFFICE_SE:
							special_oval_office();
							break;
						default:
							bool squadmoved = (olocx != locx || olocy != locy || olocz != locz);
							if (squadmoved &&
								(location[cursite]->type == SITE_RESIDENTIAL_APARTMENT ||
									location[cursite]->type == SITE_RESIDENTIAL_TENEMENT ||
									location[cursite]->type == SITE_RESIDENTIAL_APARTMENT_UPSCALE))
							{

								if (LCSrandom(3))break; // Rarely encounter someone in apartments.
							}

							prepareencounter(sitetype, location[cursite]->highsecurity);
							int numenc = 0;
							// TODO This is bizarre
							// the for loop breaks if it finds an empty encounter
							for (int e = 0; e < ENCMAX; e++)
							{

								if (encounter[e].exists) numenc++;
								else break;
							}

							if (encounterwarnings&&numenc > 0)
							{  // show an encounter warning, based on whether the squad moved or not and the size of the encounter
								clearmessagearea(false);
								set_color_easy(WHITE_ON_BLACK_BRIGHT);
								string weMoved;
								string weDidntMove;

								if (numenc == 1)
								{

									weMoved = "There is someone up ahead.";
									weDidntMove = "There is someone passing by.";
								}

								else if (numenc <= 3)
								{

									weMoved = "There are a few people up ahead.";
									weDidntMove = "There are a few people passing by.";
								}

								else if (numenc <= 6)
								{

									weMoved = "There is a group of people up ahead.";
									weDidntMove = "There is a group of people passing by.";
								}
								else
								{



									weMoved = "There is a crowd of people up ahead.";
									weDidntMove = "There is a crowd of people passing by.";
								}
								if (squadmoved) {
									mvaddstrAlt(16, 1, weMoved, gamelog);
								}
								else {
									mvaddstrAlt(16, 1, weDidntMove, gamelog);
								}

								gamelog.newline();
								getkey();
							}

							break;
						}

						hostcheck = 1;
					}

					if (!location[cursite]->siege.siege)
						if ((locx != olocx || locy != olocy || locz != olocz) && !newenc)
							//PUT BACK SPECIALS
							for (int e = 0; e < ENCMAX; e++)
								if (encounter[e].exists)
								{

									if (!encounter[e].cantbluff&&encounter[e].type == CREATURE_LANDLORD)
										levelmap[olocx][olocy][olocz].special = SPECIAL_APARTMENT_LANDLORD;
									if (!encounter[e].cantbluff&&encounter[e].type == CREATURE_BANK_TELLER)
										levelmap[olocx][olocy][olocz].special = SPECIAL_BANK_TELLER;
									encounter[e].exists = 0;
								}

					if (locx != olocx || locy != olocy || locz != olocz)
					{

						//NUKE GROUND LOOT
						delete_and_clear(groundloot);
						//MOVE BLOOD
						if (levelmap[olocx][olocy][olocz].flag&SITEBLOCK_BLOODY2)
							levelmap[locx][locy][locz].flag |= SITEBLOCK_BLOODY;
					}

					knowmap(locx, locy, locz);
				}
			}
		}


	}
}
/* site - determines spin on site news story, "too hot" timer */
void resolvesite()
{
	if (sitealienate) sitestory->positive = 0;
	//removed the 'alarmed' requirement for high security buildings, on the principle that even if they didn't see you, they will presumably
	//notice later on that all their stuff has been stolen or whatever.
	if (/*sitealarm==1&&*/sitecrime > 5 + LCSrandom(95))//was 100 but that meant I could still steal everything from a building every day without anyone caring...
	{
		if (location[cursite]->renting == RENTING_NOCONTROL)
		{

			// Capture a warehouse or crack den?
			if (location[cursite]->type == SITE_INDUSTRY_WAREHOUSE ||
				location[cursite]->type == SITE_BUSINESS_CRACKHOUSE)
			{

				location[cursite]->renting = RENTING_PERMANENT; // Capture safehouse for the glory of the LCS!
				location[cursite]->closed = 0;
				location[cursite]->heat = 100;
			}

			else location[cursite]->closed = sitecrime / 10; // Close down site
		}

		// Out sleepers
		if (location[cursite]->renting == RENTING_CCS)
		{

			for (int p = 0; p < len(pool); p++)
			{

				if (pool[p]->flag&CREATUREFLAG_SLEEPER &&
					pool[p]->location == cursite)
				{

					pool[p]->flag &= ~CREATUREFLAG_SLEEPER;
					eraseAlt();
					mvaddstrAlt(8,  1, string_sleeper, gamelog);



					addstrAlt(pool[p]->name, gamelog);
					addstrAlt(" has been outed by your bold attack!", gamelog);
					gamelog.newline();
					mvaddstrAlt(10,  1, "The Liberal is now at your command as a normal squad member.", gamelog);
					gamelog.newline();
					pool[p]->base = activesquad->squad[0]->base;
					pool[p]->location = pool[p]->base;
					getkey();
				}
			}
		}



	}
	else if (sitecrime > 10 && (location[cursite]->renting == RENTING_NOCONTROL || location[cursite]->renting > 500))
	{
		if (location[cursite]->type != SITE_RESIDENTIAL_BOMBSHELTER&&
			location[cursite]->type != SITE_BUSINESS_BARANDGRILL&&
			location[cursite]->type != SITE_OUTDOOR_BUNKER&&
			location[cursite]->type != SITE_INDUSTRY_WAREHOUSE&&
			location[cursite]->type != SITE_BUSINESS_CRACKHOUSE)
		{

			if (securityable(location[cursite]->type))
				location[cursite]->highsecurity = sitecrime;
			else location[cursite]->closed = 7;
		}

	}
}
/* behavior when the player bumps into a door in sitemode */
void open_door(bool restricted)
{
	bool locked = levelmap[locx][locy][locz].flag&SITEBLOCK_LOCKED,
		alarmed = levelmap[locx][locy][locz].flag&SITEBLOCK_ALARMED,
		vault_door = levelmap[locx][locy][locz].flag&SITEBLOCK_METAL,
		//   known_locked=levelmap[locx][locy][locz].flag&SITEBLOCK_KLOCK,
		cant_unlock = levelmap[locx][locy][locz].flag&SITEBLOCK_CLOCK;
	if (vault_door)
	{
		// Vault door, not usable by bumping
		clearmessagearea(false);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "The vault door is impenetrable.", gamelog);
		gamelog.newline();
		getkey();
		return;
	}
	bool has_security = false;
	for (int i = 0; i < 6; i++)
	{
		if (activesquad->squad[i] &&
			activesquad->squad[i]->get_skill(SKILL_SECURITY) != 0)
		{
			has_security = true;
			break;
		}
	}
	if (alarmed)
	{
		// Unlocked but alarmed door, clearly marked as such
		clearmessagearea(false);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		if (locked)
			mvaddstrAlt(16, 1, "This door appears to be wired up to an alarm.", gamelog);
		else
			mvaddstrAlt(16, 1, "EMERGENCY EXIT ONLY. ALARM WILL SOUND.", gamelog);
		gamelog.newline();
		mvaddstrAlt(17,  1, "Try the door anyway? (Yes or No)");
		while (true)
		{
			int c = getkey();
			if (c == 'y') break;
			else if (c == 'n') return;
		}
	}
	if (locked && !cant_unlock && has_security)
	{
		levelmap[locx][locy][locz].flag |= SITEBLOCK_KLOCK;
		while (true)
		{
			clearmessagearea(false);
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(16,  1, "You try the door, but it is locked.", gamelog);
			gamelog.newline();
			mvaddstrAlt(17,  1, "Try to pick the lock? (Yes or No)");
			int c = getkey();
			clearmessagearea(false);
			if (c == 'y')
			{
				char actual; // 1 if an actual attempt was made, 0 otherwise
							 // If the unlock was successful
				if (unlock(UNLOCK_DOOR, actual))
				{
					// Unlock the door
					levelmap[locx][locy][locz].flag &= ~(SITEBLOCK_LOCKED | SITEBLOCK_ALARMED);
					sitestory->crime.push_back(CRIME_UNLOCKEDDOOR);
					if (sitealarmtimer < 0 || sitealarmtimer>50) sitealarmtimer = 50;
					//criminalizeparty(LAWFLAG_BREAKING);
				}
				// Else perma-lock it if an attempt was made
				else if (actual)
				{
					levelmap[locx][locy][locz].flag |= SITEBLOCK_CLOCK;
					if (levelmap[locx][locy][locz].flag&SITEBLOCK_ALARMED)
					{
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(17,  1, "Your tampering sets off the alarm!", gamelog);
						gamelog.newline();
						sitealarm = 1;
						getkey();
					}
				}
				// Check for people noticing you fiddling with the lock
				if (actual)
				{
					alienationcheck(0);
					noticecheck(-1);
				}
				return;
			}
			else if (c == 'n') return;
		}
	}
	else if (locked || (!restricted && alarmed))
	{
		while (true)
		{
			clearmessagearea(false);
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			if (locked)
			{
				mvaddstrAlt(16, 1, "You shake the handle but it is ", gamelog);
				if (has_security) addstrAlt("still ", gamelog);
				addstrAlt("locked.", gamelog);
			}
			else mvaddstrAlt(16, 1, "It's locked from the other side.", gamelog);
			gamelog.newline();
			mvaddstrAlt(17,  1, "Force it open? (Yes or No)");
			int c = getkey();
			if (c == 'y')
			{
				char actual;
				if (bash(BASH_DOOR, actual))
				{
					levelmap[locx][locy][locz].flag &= ~SITEBLOCK_DOOR;
					int time = 0;
					if (sitealarmtimer > time || sitealarmtimer == -1)sitealarmtimer = time;
					if (levelmap[locx][locy][locz].flag&SITEBLOCK_ALARMED)
					{
						clearmessagearea(false);
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(16,  1, "The alarm goes off!", gamelog);
						gamelog.newline();
						sitealarm = 1;
						getkey();
					}
					sitecrime++;
					sitestory->crime.push_back(CRIME_BROKEDOWNDOOR);
					criminalizeparty(LAWFLAG_BREAKING);
				}
				if (actual)
				{
					alienationcheck(1);
					noticecheck(-1, DIFFICULTY_HEROIC);
				}
				break;
			}
			else if (c == 'n')break;
		}
	}
	else
	{
		levelmap[locx][locy][locz].flag &= ~SITEBLOCK_DOOR;
		if (alarmed)
		{
			// Opened an unlocked but clearly marked emergency exit door
			clearmessagearea(false);
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(16,  1, "It opens easily. The alarm goes off!", gamelog);
			gamelog.newline();
			sitealarm = 1;
			getkey();
		}
	}
}
