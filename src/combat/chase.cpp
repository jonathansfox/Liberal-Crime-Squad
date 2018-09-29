#include "../includes.h"
const string CONST_chase015 = "carchase_obstacle_child.txt";
const string CONST_chase014 = "carchase_obstacle_cross_traffic.txt";
const string CONST_chase013 = "carchase_obstacle_truck_pulls_out.txt";
const string CONST_chase012 = "carchase_obstacle_fruit_stand.txt";
const string CONST_chase011 = "carchase_obstacle_none.txt";
const string CONST_chase010 = "die_in_car.txt";
const string CONST_chase009 = "car_crash_fatalities.txt";
const string CONST_chase008 = "car_crash_modes.txt";
const string CONST_chase007 = "car_plows_through.txt";
const string CONST_chase006 = "car_speed.txt";

const string CONST_chase048 = " is still on your tail!";
const string CONST_chase079 = "C - Reflect on your lack of skill.";
const string CONST_chase076 = "F - Fight!";
const string CONST_chase075 = "E - Equip";
const string CONST_chase074 = "D - Try to lose them!";

const string tag_POLICECAR = "POLICECAR";
const string tag_The = "The ";
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

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
//#include "basemode/baseactions.h"
void orderparty();
//#include "sitemode/advance.h"
void creatureadvance();
#include "../sitemode/sitedisplay.h"
//#include "sitemode/miscactions.h"
void reloadparty(bool wasteful = false);
#include "../log/log.h"
// for gamelog
#include "../common/translateid.h"
// for  int id_getcar(int)
#include "../common/commondisplay.h"
// for addstr (with log)
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
/* tells how many total members a squad has (including dead members) */
int squadsize(const Deprecatedsquadst *st);
/* tells how many members a squad has who are alive */
int squadalive(const Deprecatedsquadst *st);
// for int squadsize(const squadst *);
//#include "common/equipment.h"
void equip(vector<Item *> &loot, int loc);
#include "fight.h"
#include "fightCreature.h"  
// for void youattack();
#include "haulkidnapCreature.h"
// for  void kidnaptransfer(Creature &cr);
#include "../cursesAlternative.h"
#include "../customMaps.h"
#include "../set_color_support.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
#include "../common/creaturePool.h"
extern string change_squad_order;
extern string check_status_of_squad_liberal;
extern string show_squad_liberal_status;
extern string singleSpace;
extern string singleDot;
enum LOOP_CONTINUATION {
	RETURN_ZERO,
	RETURN_ONE,
	REPEAT
};
const string mostlyendings = "mostlyendings\\";
vector<NameAndAlignment> getEncounterNameAndAlignment();
void makecreature(const int x, const short type);
void fillEncounter(CreatureTypes c, int numleft) {
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();
	for (int e = 0; e < ENCMAX; e++)
	{
		if (!encounter[e].exists)
		{
			makecreature(e, c);
			numleft--;
		}
		if (numleft == 0)break;
	}
}
void emptyEncounter();
void emptyEncounter() {
	extern DeprecatedCreature encounter[ENCMAX];
	for (int e = 0; e < ENCMAX; e++)encounter[e].exists = 0;
}
vector<string> car_speed;
vector<string> car_plows_through;
vector<string> car_crash_modes;
vector<string> car_crash_fatalities;
vector<string> die_in_car;
vector<string> carchase_obstacle_none;
vector<string> carchase_obstacle_fruit_stand;
vector<string> carchase_obstacle_truck_pulls_out;
vector<string> carchase_obstacle_cross_traffic;
vector<string> carchase_obstacle_child;
const string chase = "chase\\";
vector<file_and_text_collection> chase_text_file_collection = {
	/*chase.cpp*/
	customText(&car_speed, chase + CONST_chase006),
	customText(&car_plows_through, chase + CONST_chase007),
	customText(&car_crash_modes, chase + CONST_chase008),
	customText(&car_crash_fatalities, chase + CONST_chase009),
	customText(&die_in_car, chase + CONST_chase010),
	customText(&carchase_obstacle_none, mostlyendings + CONST_chase011),
	customText(&carchase_obstacle_fruit_stand, mostlyendings + CONST_chase012),
	customText(&carchase_obstacle_truck_pulls_out, mostlyendings + CONST_chase013),
	customText(&carchase_obstacle_cross_traffic, mostlyendings + CONST_chase014),
	customText(&carchase_obstacle_child, mostlyendings + CONST_chase015),
};
map<short, vector<string> > carchaseObstacles;
string beingFollowedBySwine;
string lostThem;
string hereTheyCome;
string isSeized;
const int DRIVING_RANDOMNESS = 13;
void deleteVehicles(vector<Vehicle *>& carid);
void chase_giveup()
{
	const string CONST_chase020 = " is free.";
	const string CONST_chase019 = "s are free.";
	const string CONST_chase018 = "Your hostage";
	const string CONST_chase017 = "You pull over and are arrested.";
	const string CONST_chase016 = "You stop and are arrested.";
	extern chaseseqst chaseseq;
	extern short mode;
	extern Deprecatedsquadst *activesquad;
	extern Log gamelog;
	int ps = find_site_index_in_same_city(SITE_GOVERNMENT_POLICESTATION, chaseseq.location);
	deleteVehicles(chaseseq.friendcar);
	int hostagefreed = 0;
	for (int p = 0; p < 6; p++)
	{
		if (!activesquad->squad[p]) continue;
		activesquad->squad[p]->squadid = -1;
		activesquad->squad[p]->carid = -1;
		activesquad->squad[p]->location = ps;
		activesquad->squad[p]->drop_weapons_and_clips(NULL);
		activesquad->squad[p]->activity.type = ACTIVITY_NONE;
		if (activesquad->squad[p]->prisoner)
		{
			if (activesquad->squad[p]->prisoner->squadid == -1) hostagefreed++;
			freehostage(*activesquad->squad[p], 2);
		}
		activesquad->squad[p] = NULL;
	}
	CreaturePool::getInstance().stopAllBleeding();
	clearmessagearea();
	clearcommandarea();
	set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
	moveAlt(16, 1);
	if (mode != GAMEMODE_CHASECAR)addstrAlt(CONST_chase016, gamelog);
	else addstrAlt(CONST_chase017, gamelog);
	gamelog.newline(); //New line.
	if (hostagefreed)
	{
		mvaddstrAlt(17, 1, CONST_chase018, gamelog);
		if (hostagefreed > 1)
			addstrAlt(CONST_chase019, gamelog);
		else addstrAlt(CONST_chase020, gamelog);
		gamelog.newline(); //New line.
	}
	pressAnyKey();
}
void printSemiRandomEscape(const int yourworst) {
	extern Log gamelog;
	const string CONST_chase024 = "You scale a small building and leap between rooftops!";
	const string CONST_chase023 = "You climb a fence in record time!";
	const string CONST_chase022 = "You run as fast as you can!";
	const string CONST_chase021 = "You suddenly dart into an alley!";

	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	string output;
	switch (LCSrandom(yourworst / 5))
	{
	default:
		output = CONST_chase021;
		break;
	case 1:
		output = CONST_chase022;
		break;
	case 2:
		output = CONST_chase023;
		break;
	case 3:
		output = CONST_chase024;
		break;
	}
	mvaddstrAlt(16, 1, output, gamelog);
	gamelog.newline(); //New line.
	pressAnyKey();
}
void tankPlowsThrough(const int e) {
	extern Log gamelog;
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();
	clearmessagearea();
	set_color_easy(YELLOW_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, encounter[e].name, gamelog);
	addstrAlt(singleSpace, gamelog);
	addstrAlt(pickrandom(car_plows_through), gamelog);
	pressAnyKey();
}
string isCapturedByCop(const int p) {
	extern short lawList[LAWNUM];
	extern Deprecatedsquadst *activesquad;

	const string CONST_chase031 = "thrown to the ground, and tazed repeatedly!";
	const string CONST_chase030 = "thrown to the ground, and tazed to death!";
	const string CONST_chase029 = "pushed to the ground, and handcuffed!";
	string output = activesquad->squad[p]->name + isSeized;
	if (lawList[LAW_POLICEBEHAVIOR] >= ALIGN_LIBERAL)
	{
		output += CONST_chase029;
	}
	else
	{
		if (activesquad->squad[p]->blood <= 10)
		{
			output += CONST_chase030;
		}
		else
		{
			output += CONST_chase031;
		}
		activesquad->squad[p]->blood -= 10;
	}
	return output;
}
string isSummaryExecuted(const int p) {

	extern Deprecatedsquadst *activesquad;

	const string CONST_chase032 = "thrown to the ground, and shot in the head!";

	string output = activesquad->squad[p]->name + isSeized;

	output += isSeized;
	output += CONST_chase032;
	activesquad->squad[p]->blood = 0;

	return output;
}
string isCrushedByTank(const int p) {

	extern Deprecatedsquadst *activesquad;

	const string CONST_chase033 = " crushed beneath the tank's treads!";

	string output = activesquad->squad[p]->name + CONST_chase033;

	activesquad->squad[p]->blood = 0;

	return output;
}
string isCapturedByOther(const int p) {

	extern short lawList[LAWNUM];
	extern Deprecatedsquadst *activesquad;

	const string CONST_chase035 = "thrown to the ground, and beaten senseless!";
	const string CONST_chase034 = "thrown to the ground, and beaten to death!";

	string output = activesquad->squad[p]->name + isSeized;

	output += isSeized;
	if (activesquad->squad[p]->blood <= 60)
	{
		output += CONST_chase034;
	}
	else
	{
		output += CONST_chase035;
	}
	activesquad->squad[p]->blood -= 60;

	return output;
}
const string CONST_chase028 = " breaks away!";
const string CONST_chase026 = " can't keep up!";
const string CONST_chase025 = " tips into a pool. The tank is trapped!";
void evasiverun()
{
	extern Deprecatedsquadst *activesquad;
	extern Log gamelog;
	extern DeprecatedCreature encounter[ENCMAX];
	extern short lawList[LAWNUM];
	vector<int> yourspeed;
	yourspeed.resize(6);
	int yourworst = 10000, yourbest = 0, wheelchair = 0, notwheelchair = 0, theirbest = 0, theirworst = 10000;
	for (int p = 0; p < 6; p++)
	{
		if (activesquad->squad[p] == NULL) continue;
		if (activesquad->squad[p]->alive)
		{
			if (activesquad->squad[p]->flag & CREATUREFLAG_WHEELCHAIR)
			{
				yourspeed[p] = 0;
				wheelchair++;
			}
			else
			{
				yourspeed[p] = activesquad->squad[p]->attribute_roll(ATTRIBUTE_AGILITY) +
					activesquad->squad[p]->attribute_roll(ATTRIBUTE_HEALTH);
				//healthmodroll(yourspeed[p],*activesquad->squad[p]);
				notwheelchair++;
			}
			if (yourworst > yourspeed[p]) yourworst = yourspeed[p];
			if (yourbest < yourspeed[p]) yourbest = yourspeed[p];
		}
	}
	if (yourworst > 14)
	{
		yourworst += LCSrandom(5);
		printSemiRandomEscape(yourworst);
	}
	for (int e = 0; e < ENCMAX; e++)
	{
		if (!encounter[e].exists) continue;
		int chaser = encounter[e].attribute_roll(ATTRIBUTE_AGILITY) +
			encounter[e].attribute_roll(ATTRIBUTE_HEALTH);
		//healthmodroll(chaser,encounter[e]);
		if (theirbest < chaser) theirbest = chaser;
		if (theirworst > chaser) theirworst = chaser;
		if (encounter[e].type == CREATURE_TANK && LCSrandom(10))
		{
			tankPlowsThrough(e);
		}
		else if (chaser < yourworst)
		{
			clearmessagearea();
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			mvaddstrAlt(16, 1, encounter[e].name, gamelog);
			if (encounter[e].type == CREATURE_TANK)
			{
				addstrAlt(CONST_chase025, gamelog);
				gamelog.newline(); //New line.
			}
			else
			{
				addstrAlt(CONST_chase026, gamelog);
				gamelog.newline(); //Another new line.
			}
			delenc(e--, 0);
			printchaseencounter();
			pressAnyKey();
		}
		else
		{
			clearmessagearea();
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			mvaddstrAlt(16, 1, encounter[e].name, gamelog);
			addstrAlt(CONST_chase048, gamelog);
			gamelog.newline(); //New line.
			pressAnyKey();
		}
	}
	//This last loop can be used to have fast people in
	//your squad escape one by one just as the enemy
	//falls behind one by one
	int othersleft = 0;
	for (int p = 5; p >= 0; p--)
	{
		if (!encounter[0].exists) break;
		if (activesquad->squad[p] == NULL) continue;
		if (activesquad->squad[p]->alive)
		{
			if (yourspeed[p] > theirbest)
			{
				if (p == 0 && othersleft == 0) break;
				clearmessagearea();
				set_color_easy(CYAN_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 1, activesquad->squad[p]->name, gamelog);
				addstrAlt(CONST_chase028, gamelog);
				gamelog.newline(); //New line.
				pressAnyKey();
				//Unload hauled hostage or body when they get back to the safehouse
				if (activesquad->squad[p]->prisoner != NULL)
				{
					//If this is an LCS member or corpse being hauled (marked as in the squad)
					if (activesquad->squad[p]->prisoner->squadid != -1)
					{
						//Take them out of the squad
						removesquadinfo(*activesquad->squad[p]->prisoner);
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
				removesquadinfo(*activesquad->squad[p]);
				printparty();
			}
			else if (yourspeed[p] < theirbest - 10)
			{
				clearmessagearea();
				set_color_easy(CYAN_ON_BLACK_BRIGHT);
				string squadmemberSubdued;
				switch (encounter[0].type)
				{
				case CREATURE_COP:
					squadmemberSubdued = isCapturedByCop(p);
					break;
				case CREATURE_DEATHSQUAD:
					squadmemberSubdued = isSummaryExecuted(p);
					break;
				case CREATURE_TANK:
					squadmemberSubdued = isCrushedByTank(p);
					break;
				default:
					squadmemberSubdued = isCapturedByOther(p);
					break;
				}
				mvaddstrAlt(16, 1, squadmemberSubdued, gamelog);
				gamelog.newline(); //New line.
				if (activesquad->squad[p]->blood <= 0)
					activesquad->squad[p]->die();
				capturecreature(*activesquad->squad[p]);
				for (int i = p + 1, j = p; i < 6; i++, j++)
					activesquad->squad[j] = activesquad->squad[i];
				activesquad->squad[5] = NULL;
				// Death squads don't mess around, and don't fall behind when executing your people
				// Tanks don't stop either.
				if (encounter[0].type != CREATURE_DEATHSQUAD &&
					encounter[0].type != CREATURE_TANK)delenc(0, 0);
				printparty();
				printchaseencounter();
				pressAnyKey();
			}
			else othersleft++;
		}
	}
}
void printDrivingSituation(const int partysize) {
	extern chaseseqst chaseseq;
	extern short party_status;
	const string CONST_chase040 = "G - Give Up";

	//PRINT DRIVING SITUATION AND INSTRUCTIONS
	if (partysize > 1) set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 40, change_squad_order);
	if (partysize > 0 && (party_status == -1 || partysize > 1))set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 40, check_status_of_squad_liberal);
	if (party_status != -1)set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(11, 40, show_squad_liberal_status);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(9, 1, CONST_chase074);
	mvaddstrAlt(10, 1, CONST_chase075);
	mvaddstrAlt(11, 1, CONST_chase076);
	if (chaseseq.canpullover)
	{
		mvaddstrAlt(12, 1, CONST_chase040);
	}
}
void destroyAllCarsOfParty() {
	extern chaseseqst chaseseq;
	extern Deprecatedsquadst *activesquad;

	//DESTROY ALL CARS BROUGHT ALONG WITH PARTY
	deleteVehicles(chaseseq.friendcar);
	for (int p = 0; p < 6; p++)
	{
		if (activesquad->squad[p] == NULL)continue;
		activesquad->squad[p]->die();
		activesquad->squad[p]->location = -1;
		activesquad->squad[p] = NULL;
	}
	endcheck(END_BUT_NOT_END); // play the right music in case we're dead
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(9, 1, CONST_chase079);
}
int encounterSize();
int baddieCount(const bool in_car);
int baddieCount();
LOOP_CONTINUATION increment_footchase() {
	extern chaseseqst chaseseq;
	extern char foughtthisround;
	extern Deprecatedsquadst *activesquad;
	extern short party_status;
	extern Deprecatednewsstoryst *sitestory;
	extern Log gamelog;
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();
	int partysize = squadsize(activesquad), partyalive = squadalive(activesquad);
	int encsize = encounterSize();
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(0, 0, LocationsPool::getInstance().getLocationName(chaseseq.location));
	//PRINT PARTY
	if (partyalive == 0) party_status = -1;
	printparty();
	if (partyalive > 0)
	{
		printDrivingSituation(partysize);
	}
	else
	{
		destroyAllCarsOfParty();
	}
	//PRINT ENEMIES
	printchaseencounter();
	// check if we fought the previous loop; if so, add a blank gamelog line
	if (foughtthisround)gamelog.newline();
	foughtthisround = 0;
	int c = getkeyAlt();
	if (partyalive == 0 && c == 'c')
	{
		if (!endcheck())
		{
			return RETURN_ZERO;
		}
	}
	if (partyalive > 0)
	{
		switch (c) {
		case 'g':
			if (chaseseq.canpullover)
			{
				chase_giveup();
				return RETURN_ZERO;
			}
			break;

		case 'd':
			if (encounter[0].exists&&
				encounter[0].type == CREATURE_COP)
			{
				sitestory->crime.push_back(CRIME_FOOTCHASE);
				criminalizeparty(LAWFLAG_RESIST);
			}
			evasiverun();
			enemyattack();
			creatureadvance();
			break;

		case 'o':
			if (partysize > 1) orderparty();
			break;

		case '0':
			party_status = -1;
			break;
		case 'f':
			if (encounter[0].exists&&
				encounter[0].type == CREATURE_COP)
			{
				sitestory->crime.push_back(CRIME_FOOTCHASE);
				criminalizeparty(LAWFLAG_RESIST);
			}
			youattack();
			enemyattack();
			creatureadvance();
			break;

		case 'e':

			equip(activesquad->loot, -1);
			break;
		default:
			if (c >= '1'&&c <= '6')
			{
				if (activesquad->squad[c - '1'] != NULL)
				{
					if (party_status == c - '1') fullstatus(party_status);
					else party_status = c - '1';
				}
			}
			break;

		}


		//HAVE YOU LOST ALL OF THEM?
		//THEN LEAVE
		partysize = squadsize(activesquad), partyalive = squadalive(activesquad);
		int baddiecount = baddieCount();
		if (partyalive > 0 && baddiecount == 0)
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			clearmessagearea();
			mvaddstrAlt(16, 1, lostThem, gamelog);
			gamelog.newline(); //New line.
			pressAnyKey();
			CreaturePool::getInstance().stopAllBleeding();
			return RETURN_ONE;
		}
	}
	return REPEAT;
}
bool footchase()
{
	const string CONST_chase036 = "As you exit the site, you notice that you are ";
	extern chaseseqst chaseseq;
	extern MusicClass music;
	extern short mode;
	extern Log gamelog;
	extern DeprecatedCreature encounter[ENCMAX];
	//NOTE: THIS FUNCTION RETURNS 1 IF ANYBODY ESCAPES
	//IT SHOULD NOT DELETE SQUADS OR CREATURES
	//SQUADS MAY BE FICTITIOUS AND BOTH WILL BE DELETED LATER ANYWAY
	reloadparty();
	//NUKE ALL CARS
	delete_and_clear(chaseseq.enemycar);
	//BAIL IF NO CHASERS
	int chasenum = 0;
	for (int e = 0; e < ENCMAX; e++)
	{
		if (encounter[e].exists) chasenum++;
		encounter[e].carid = -1;
	}
	if (chasenum == 0) return 1;
	mode = GAMEMODE_CHASEFOOT;
	music.play(MUSIC_FOOTCHASE);
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(0, 0, CONST_chase036, gamelog);
	moveAlt(1, 0);
	gamelog.newline(); //New line.
	addstrAlt(beingFollowedBySwine, gamelog);
	gamelog.newline(); //New line.
	pressAnyKey();
	while (true) {
		LOOP_CONTINUATION x = increment_footchase();
		if (x == RETURN_ZERO) {
			mode = GAMEMODE_BASE;
			//Make sure all possible exits of the chase have the nextMessage() call
			//to ensure that the gamelog is split properly into blocks.
			gamelog.nextMessage();
			return 0;
		}
		else if (x == RETURN_ONE) {
			mode = GAMEMODE_BASE;
			//Make sure all possible exits of the chase have the nextMessage() call
			//to ensure that the gamelog is split properly into blocks.
			gamelog.nextMessage();
			return 1;
		}
	}
}
int driveskill(DeprecatedCreature &cr, int v);
int driveskill(DeprecatedCreature &cr, Vehicle &v)
{
	int driveskill = cr.skill_roll(PSEUDOSKILL_ESCAPEDRIVE);
	healthmodroll(driveskill, cr);
	if (driveskill < 0) driveskill = 0;
	driveskill *= static_cast<int>(cr.blood / 50.0);
	return driveskill;
}
const string CONST_chase047 = " brakes hard and nearly crashes!";
const string CONST_chase046 = " backs off for safety.";
const string CONST_chase045 = " skids out!";
const string CONST_chase044 = " falls behind!";
const string CONST_chase043 = "You make obscene gestures at the pursuers!";
const string CONST_chase042 = "You boldly weave through oncoming traffic!";
void evasivedrive()
{
	extern chaseseqst chaseseq;
	extern Deprecatedsquadst *activesquad;
	extern short fieldskillrate;
	extern Log gamelog;
	extern DeprecatedCreature encounter[ENCMAX];
	vector<long> yourrolls, theirrolls, theirrolls_id, theirrolls_drv;
	long yourworst = 10000;
	for (int p = 0; p < 6; p++)
	{
		if (activesquad->squad[p] == NULL) continue;
		if (activesquad->squad[p]->alive&&
			activesquad->squad[p]->is_driver)
		{
			int v = id_getcar(activesquad->squad[p]->carid);
			yourrolls.push_back(driveskill(*activesquad->squad[p], v) + LCSrandom(DRIVING_RANDOMNESS));
			switch (fieldskillrate)
			{
			case FIELDSKILLRATE_FAST:
				activesquad->squad[p]->train(SKILL_DRIVING, LCSrandom(20)); break;
			case FIELDSKILLRATE_CLASSIC:
				activesquad->squad[p]->train(SKILL_DRIVING, LCSrandom(20)); break;
			case FIELDSKILLRATE_HARD:
				activesquad->squad[p]->train(SKILL_DRIVING, LCSrandom(max(1, 20 - activesquad->squad[p]->get_skill(SKILL_DRIVING)))); break;
			}
			if (yourworst > yourrolls.back()) yourworst = yourrolls.back();
		}
	}
	if (!len(yourrolls)) yourrolls.push_back(0); //error -- and for this you get a 0
	for (int e = 0; e < ENCMAX; e++)
	{
		if (encounter[e].carid != -1 &&
			encounter[e].enemy() &&
			encounter[e].alive&&
			encounter[e].exists&&
			encounter[e].is_driver)
		{
			for (int v = 0; v < len(chaseseq.enemycar); v++)
			{
				if (chaseseq.enemycar[v]->id() == encounter[e].carid)
				{
					theirrolls.push_back(driveskill(encounter[e], *chaseseq.enemycar[v]) + LCSrandom(DRIVING_RANDOMNESS));
					theirrolls_id.push_back(encounter[e].carid);
					theirrolls_drv.push_back(encounter[e].id);
				}
			}
		}
		else if (encounter[e].carid == -1) encounter[e].exists = false;
	}
	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(16, 1);
	switch (LCSrandom(car_speed.size() + 1))
	{
	case 0:
		if (yourworst > 15)
			addstrAlt(CONST_chase042, gamelog);
		else
			addstrAlt(CONST_chase043, gamelog);
		gamelog.newline(); //new line.
		break;
	default:
		addstrAlt(pickrandom(car_speed), gamelog);
		gamelog.newline(); //new line.
		break;
	}
	pressAnyKey();
	for (int i = 0; i < len(theirrolls); i++)
	{
		int cnt = pickrandom(yourrolls);
		if (theirrolls[i] < cnt)
		{
			clearmessagearea();
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			moveAlt(16, 1);
			for (int e = 0; e < ENCMAX; e++)
			{
				if (encounter[e].id == theirrolls_drv[i])
				{
					addstrAlt(encounter[e].name, gamelog);
					break;
				}
			}
			switch (LCSrandom(cnt / 5))
			{
			default:
				addstrAlt(CONST_chase044, gamelog);
				gamelog.newline(); //New line.
				break;
			case 1:
				addstrAlt(CONST_chase045, gamelog);
				gamelog.newline(); //New line.
				break;
			case 2:
				addstrAlt(CONST_chase046, gamelog);
				gamelog.newline(); //New line.
				break;
			case 3:
				addstrAlt(CONST_chase047, gamelog);
				gamelog.newline(); //New line.
				break;
			}
			for (int e = 0; e < ENCMAX; e++)
			{
				if (encounter[e].carid == theirrolls_id[i])
				{
					for (int e2 = e; e2 < ENCMAX - 1; e2++) encounter[e2] = encounter[e2 + 1];
					encounter[ENCMAX - 1].exists = 0;
					encounter[ENCMAX - 1].carid = -1;
					e--;
				}
			}
			for (int v = 0; v < len(chaseseq.enemycar); v++)
			{
				if (chaseseq.enemycar[v]->id() == theirrolls_id[i])
				{
					delete_and_remove(chaseseq.enemycar, v);
					break;
				}
			}
			printchaseencounter();
			pressAnyKey();
		}
		else
		{
			clearmessagearea();
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			moveAlt(16, 1);
			for (int e = 0; e < ENCMAX; e++)
			{
				if (encounter[e].id == theirrolls_drv[i])
				{
					addstrAlt(encounter[e].name, gamelog);
					break;
				}
			}
			addstrAlt(CONST_chase048, gamelog);
			gamelog.newline(); //Blarg. Newline.
			pressAnyKey();
		}
	}
}
const string CONST_chase058 = " crawls free of the car, shivering with pain.";
const string CONST_chase057 = " gasps in pain, but lives, for now.";
const string CONST_chase056 = " feet.";
const string CONST_chase055 = " wheelchair.";
const string CONST_chase054 = " and struggles to ";
const string CONST_chase053 = "car frame";
const string CONST_chase052 = " grips the ";
const string CONST_chase051 = " seat, out cold, and dies.";
const string CONST_chase050 = " slumps in ";
const string CONST_chase049 = "Your ";
void crashfriendlycar(int v)
{
	extern int stat_dead;
	extern chaseseqst chaseseq;
	extern Deprecatedsquadst *activesquad;
	extern Log gamelog;
	//CRASH CAR
	clearmessagearea();
	set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_chase049, gamelog);
	addstrAlt(chaseseq.friendcar[v]->fullname(), gamelog);
	addstrAlt(pickrandom(car_crash_modes), gamelog);
	gamelog.newline(); //New line it.
	printparty();
	pressAnyKey();
	int victimsum = 0;
	for (int p = 0; p < 6; p++)
	{
		if (!activesquad->squad[p]) continue;
		if (activesquad->squad[p]->carid == chaseseq.friendcar[v]->id())
		{
			// Inflict injuries on Liberals
			for (int w = 0; w < BODYPARTNUM; w++)
				// If limb is intact
				if (!(activesquad->squad[p]->wound[w] & (WOUND_CLEANOFF | WOUND_NASTYOFF)))
				{
					// Inflict injuries
					if (LCSrandom(2))
					{
						activesquad->squad[p]->wound[w] |= (WOUND_TORN | WOUND_BLEEDING);
						activesquad->squad[p]->blood -= 1 + LCSrandom(25);
					}
					if (!LCSrandom(3))
					{
						activesquad->squad[p]->wound[w] |= (WOUND_CUT | WOUND_BLEEDING);
						activesquad->squad[p]->blood -= 1 + LCSrandom(25);
					}
					if (LCSrandom(2) || activesquad->squad[p]->wound[w] == 0)
					{
						activesquad->squad[p]->wound[w] |= WOUND_BRUISED;
						activesquad->squad[p]->blood -= 1 + LCSrandom(10);
					}
				}
			// Kill off hostages
			if (activesquad->squad[p]->prisoner)
			{
				// Instant death
				if (activesquad->squad[p]->prisoner->alive)
				{
					clearmessagearea();
					set_color_easy(RED_ON_BLACK_BRIGHT);
					mvaddstrAlt(16, 1, activesquad->squad[p]->prisoner->name, gamelog);
					addstrAlt(pickrandom(car_crash_fatalities), gamelog);
					gamelog.newline(); //New line.
					printparty();
					pressAnyKey();
				}
				activesquad->squad[p]->prisoner->die();
				activesquad->squad[p]->prisoner->location = -1;
				victimsum++;
				// Record death if living Liberal is hauled
				if (activesquad->squad[p]->prisoner->squadid != -1)
				{
					if (activesquad->squad[p]->prisoner->alive&&
						activesquad->squad[p]->prisoner->align == 1)stat_dead++;
					activesquad->squad[p]->prisoner->die();
					activesquad->squad[p]->prisoner->location = -1;
				}
				// Otherwise just kill them off and be done with it
				else delete activesquad->squad[p]->prisoner;
				activesquad->squad[p]->prisoner = NULL;
			}
			// Handle squad member death
			if (activesquad->squad[p]->blood <= 0)
			{
				// Inform the player
				clearmessagearea();
				set_color_easy(RED_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 1, activesquad->squad[p]->name, gamelog);
				switch (LCSrandom(die_in_car.size() + 1))
				{
					//TODO IsaacG Migrate Strings
				case 0:addstrAlt(CONST_chase050, gamelog);
					addstrAlt(activesquad->squad[p]->hisher(), gamelog);
					addstrAlt(CONST_chase051, gamelog); break;
				default:
					addstrAlt(pickrandom(die_in_car), gamelog);
					break;
				}
				gamelog.newline(); //New line.
				printparty();
				pressAnyKey();
				// Mark as dead
				activesquad->squad[p]->die();
				activesquad->squad[p]->location = -1;
				victimsum++;
				// Account for deaths for high score
				if (activesquad->squad[p]->align == ALIGN_LIBERAL)stat_dead++;
				// Remove dead Liberal from squad
				activesquad->squad[p] = NULL;
			}
			else
			{
				// Inform the player of character survival
				clearmessagearea();
				set_color_easy(YELLOW_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 1, activesquad->squad[p]->name, gamelog);
				switch (LCSrandom(3))
				{
				case 0:
					addstrAlt(CONST_chase052, gamelog);
					if (activesquad->squad[p]->is_armed())
						addstrAlt(activesquad->squad[p]->get_weapon().get_shortname(), gamelog);
					else addstrAlt(CONST_chase053, gamelog);
					addstrAlt(CONST_chase054, gamelog);
					addstrAlt(activesquad->squad[p]->hisher(), gamelog);
					if (activesquad->squad[p]->flag & CREATUREFLAG_WHEELCHAIR)
						addstrAlt(CONST_chase055, gamelog);
					else addstrAlt(CONST_chase056, gamelog);
					break;
				case 1:
					addstrAlt(CONST_chase057, gamelog);
					break;
				case 2:addstrAlt(CONST_chase058, gamelog);
					activesquad->squad[p]->drop_weapon(NULL);
					break;
				}
				gamelog.newline(); //New line.
				printparty();
				pressAnyKey();
			}
		}
	}
	//CONSOLIDATE SQUAD
	for (int i = 0; i < 5; i++)
	{
		bool flipstart = 0;
		for (int pt = 0; pt < 6; pt++)
		{
			if (activesquad->squad[pt] == NULL && !flipstart)flipstart = 1;
			if (flipstart&&pt < 5)activesquad->squad[pt] = activesquad->squad[pt + 1];
		}
		if (flipstart)activesquad->squad[5] = NULL;
	}
	//GET RID OF CARS
	deleteVehicles(chaseseq.friendcar);
	for (int p = 0; p < 6; p++)
	{
		if (!activesquad->squad[p]) continue;
		activesquad->squad[p]->carid = -1;
	}
}
void crashenemycar(int v)
{
	const string CONST_chase063 = " hits a parked car and flips over.";
	const string CONST_chase062 = "The person inside is squashed into a cube.";
	const string CONST_chase061 = "Everyone inside is peeled off against the pavement.";
	const string CONST_chase060 = " spins out and crashes.";
	const string CONST_chase059 = " slams into a building.";
	extern chaseseqst chaseseq;
	extern Log gamelog;
	extern DeprecatedCreature encounter[ENCMAX];
	int victimsum = 0;
	for (int p = ENCMAX - 1; p >= 0; p--)
	{
		if (!encounter[p].exists) continue;
		if (encounter[p].carid == chaseseq.enemycar[v]->id())
		{
			victimsum++;
			delenc(p, 0);
		}
	}
	//CRASH CAR
	clearmessagearea();
	set_color_easy(CYAN_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, tag_The, gamelog);
	addstrAlt(chaseseq.enemycar[v]->fullname(), gamelog);
	switch (LCSrandom(3))
	{
	case 0:addstrAlt(CONST_chase059, gamelog); break;
	case 1:
		addstrAlt(CONST_chase060, gamelog);
		moveAlt(17, 1);
		if (victimsum > 1)addstrAlt(CONST_chase061, gamelog);
		else if (victimsum == 1)addstrAlt(CONST_chase062, gamelog);
		break;
	case 2:addstrAlt(CONST_chase063, gamelog); break;
	}
	gamelog.newline(); //New line.
	delete_and_remove(chaseseq.enemycar, v);
	printchaseencounter();
	pressAnyKey();
}
bool drivingupdate(short &obstacle)
{
	const string CONST_chase064 = " takes over the wheel.";
	extern chaseseqst chaseseq;
	extern Deprecatedsquadst *activesquad;
	extern Deprecatednewsstoryst *sitestory;
	extern Log gamelog;
	extern DeprecatedCreature encounter[ENCMAX];
	//CHECK TO SEE WHICH CARS ARE BEING DRIVEN
	vector<int> passenger;
	int driver;
	for (int v = len(chaseseq.friendcar) - 1; v >= 0; v--)
	{
		passenger.clear();
		driver = -1;
		for (int p = 0; p < 6; p++)
		{
			if (activesquad->squad[p] == NULL) continue;
			if (activesquad->squad[p]->carid == chaseseq.friendcar[v]->id())
			{
				if (activesquad->squad[p]->is_driver)
				{
					if (activesquad->squad[p]->canwalk()) driver = p;
					else activesquad->squad[p]->is_driver = 0;
				}
				passenger.push_back(p);
			}
		}
		if (len(passenger) && driver == -1)
		{
			//MAKE BEST DRIVING PASSENGER INTO A DRIVER
			vector<int> goodp;
			int max = 0;
			for (int p = 0; p < len(passenger); p++)
				if (driveskill(*activesquad->squad[passenger[p]], *chaseseq.friendcar[v]) > max&&activesquad->squad[passenger[p]]->canwalk())
					max = driveskill(*activesquad->squad[passenger[p]], *chaseseq.friendcar[v]);
			for (int p = 0; p < len(passenger); p++)
				if (driveskill(*activesquad->squad[passenger[p]], *chaseseq.friendcar[v]) == max && activesquad->squad[passenger[p]]->canwalk())
					goodp.push_back(passenger[p]);
			if (len(goodp))
			{
				int p = pickrandom(goodp);
				activesquad->squad[p]->is_driver = 1;
				driver = p;
				clearmessagearea();
				set_color_easy(YELLOW_ON_BLACK_BRIGHT);
				mvaddstrAlt(16, 1, activesquad->squad[p]->name, gamelog);
				addstrAlt(CONST_chase064, gamelog);
				gamelog.newline(); //New line.
				printparty();
				pressAnyKey();
			}
		}
		if (driver == -1)
		{
			crashfriendlycar(v);
			sitestory->crime.push_back(CRIME_CARCHASE);
			return 1;
		}
	}
	for (int v = len(chaseseq.enemycar) - 1; v >= 0; v--)
	{
		passenger.clear();
		driver = -1;
		for (int p = 0; p < ENCMAX; p++)
		{
			if (!encounter[p].exists) continue;
			if (encounter[p].carid == chaseseq.enemycar[v]->id())
			{
				if (encounter[p].is_driver)
				{
					if (encounter[p].canwalk()) driver = p;
					else encounter[p].is_driver = 0;
				}
				passenger.push_back(p);
			}
		}
		// Enemies don't take over the wheel when driver incapacitated
		if (driver == -1)
		{
			crashenemycar(v);
			sitestory->crime.push_back(CRIME_CARCHASE);
		}
	}
	//SET UP NEXT OBSTACLE
	if (!LCSrandom(3)) obstacle = LCSrandom(CARCHASE_OBSTACLENUM);
	else obstacle = -1;
	return 0;
}
bool dodgedrive()
{
	const string CONST_chase065 = "You swerve to avoid the obstacle!";
	extern chaseseqst chaseseq;
	extern Deprecatedsquadst *activesquad;
	extern Deprecatednewsstoryst *sitestory;
	extern Log gamelog;
	extern DeprecatedCreature encounter[ENCMAX];
	clearmessagearea();
	set_color_easy(YELLOW_ON_BLACK_BRIGHT);
	mvaddstrAlt(16, 1, CONST_chase065, gamelog);
	gamelog.newline(); //New line.
	pressAnyKey();
	int driver;
	for (int v = len(chaseseq.friendcar) - 1; v >= 0; v--)
	{
		driver = -1;
		for (int p = 0; p < 6; p++)
		{
			if (!activesquad->squad[p]) continue;
			if (activesquad->squad[p]->carid == chaseseq.friendcar[v]->id())
			{
				if (activesquad->squad[p]->is_driver)
				{
					driver = p;
					break;
				}
			}
		}
		if (driver != -1)
		{
			if (!activesquad->squad[driver]->skill_check(PSEUDOSKILL_ESCAPEDRIVE, DIFFICULTY_EASY))
			{
				crashfriendlycar(v);
				sitestory->crime.push_back(CRIME_CARCHASE);
				return 1;
			}
		}
	}
	for (int v = len(chaseseq.enemycar) - 1; v >= 0; v--)
	{
		driver = -1;
		for (int p = 0; p < ENCMAX; p++)
		{
			if (!encounter[p].exists) continue;
			if (encounter[p].carid == chaseseq.enemycar[v]->id())
			{
				if (encounter[p].is_driver)
				{
					driver = p;
					break;
				}
			}
		}
		if (driver != -1)
			if (!encounter[driver].skill_check(PSEUDOSKILL_ESCAPEDRIVE, DIFFICULTY_EASY))
			{
				crashenemycar(v);
				sitestory->crime.push_back(CRIME_CARCHASE);
			}
	}
	return 0;
}
bool obstacledrive(short obstacle, char choice)
{
	const string CONST_chase072 = "Both sides refrain from endangering the child...";
	const string CONST_chase071 = "The Conservative bastards unleash a hail of gunfire!";
	const string CONST_chase070 = "You slow down and carefully avoid the kid.";
	const string CONST_chase069 = "The fruit seller is squashed!";
	const string CONST_chase068 = "Fruit smashes all over the windshield!";
	const string CONST_chase067 = "You slow down, and carefully evade the truck.";
	const string CONST_chase066 = "You slow down, and turn the corner.";
	extern Log gamelog;
	switch (obstacle)
	{
	case CARCHASE_OBSTACLE_CROSSTRAFFIC:
		if (choice == 0)
		{
			if (dodgedrive()) return 1;
		}
		else if (choice == 1)
		{
			clearmessagearea();
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			mvaddstrAlt(16, 1, CONST_chase066, gamelog);
			gamelog.newline(); //New line.
			pressAnyKey();
			if (!LCSrandom(3))
			{
				set_color_easy(YELLOW_ON_BLACK_BRIGHT);
				mvaddstrAlt(17, 1, hereTheyCome, gamelog);
				gamelog.newline(); //New line.
				pressAnyKey();
				enemyattack();
				youattack();
			}
		}
		break;
	case CARCHASE_OBSTACLE_TRUCKPULLSOUT:
		if (choice == 0)
		{
			if (dodgedrive()) return 1;
		}
		else if (choice == 1)
		{
			clearmessagearea();
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			mvaddstrAlt(16, 1, CONST_chase067, gamelog);
			gamelog.newline(); //New line.
			pressAnyKey();
			if (!LCSrandom(3))
			{
				set_color_easy(YELLOW_ON_BLACK_BRIGHT);
				mvaddstrAlt(17, 1, hereTheyCome, gamelog);
				gamelog.newline(); //New line.
				pressAnyKey();
				enemyattack();
				youattack();
			}
		}
		break;
	case CARCHASE_OBSTACLE_FRUITSTAND:
		if (choice == 0)
		{
			if (dodgedrive()) return 1;
		}
		else if (choice == 1)
		{
			clearmessagearea();
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			mvaddstrAlt(16, 1, CONST_chase068, gamelog);
			gamelog.newline(); //New line.
			pressAnyKey();
			if (!LCSrandom(5))
			{
				set_color_easy(RED_ON_BLACK_BRIGHT);
				mvaddstrAlt(17, 1, CONST_chase069, gamelog);
				gamelog.newline(); //All this logging and lining...
				pressAnyKey();
				criminalizeparty(LAWFLAG_MURDER);
			}
		}
		break;
	case CARCHASE_OBSTACLE_CHILD:
		if (choice == 0)
		{
			if (dodgedrive()) return 1;
		}
		else if (choice == 1)
		{
			clearmessagearea();
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			mvaddstrAlt(16, 1, CONST_chase070, gamelog);
			gamelog.newline(); //New line.
			pressAnyKey();
			if (!LCSrandom(3))
			{
				set_color_easy(RED_ON_BLACK_BRIGHT);
				mvaddstrAlt(17, 1, CONST_chase071, gamelog);
				gamelog.newline(); //New line.
				pressAnyKey();
				enemyattack();
				youattack();
			}
			else
			{
				set_color_easy(GREEN_ON_BLACK_BRIGHT);
				mvaddstrAlt(17, 1, CONST_chase072, gamelog);
				gamelog.newline(); //New line.
				pressAnyKey();
			}
		}
		break;
	}
	return 0;
}
void printSituationAndInstructions(const short obstacle) {
	extern Log gamelog;
	extern chaseseqst chaseseq;
	extern short party_status;
	extern Deprecatedsquadst *activesquad;
	int partysize = squadsize(activesquad);

	const string CONST_chase078 = "P - Pull over";
	const string CONST_chase077 = "B - Bail out and run!";
	//PRINT DRIVING SITUATION AND INSTRUCTIONS
	if (partysize > 1)set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(9, 40, change_squad_order);
	if (partysize > 0 && (party_status == -1 || partysize > 1))set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(10, 40, check_status_of_squad_liberal);
	if (party_status != -1)set_color_easy(WHITE_ON_BLACK);
	else set_color_easy(BLACK_ON_BLACK_BRIGHT);
	mvaddstrAlt(11, 40, show_squad_liberal_status);
	if (obstacle == -1)
	{
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(9, 1, CONST_chase074);
		mvaddstrAlt(10, 1, CONST_chase075);
		mvaddstrAlt(11, 1, CONST_chase076);
	}
	else
	{
		set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
		mvaddstrAlt(9, 1, carchaseObstacles[obstacle][0]);
		gamelog.newline();
		mvaddstrAlt(10, 1, carchaseObstacles[obstacle][1]);
		mvaddstrAlt(11, 1, carchaseObstacles[obstacle][2]);
	}
	mvaddstrAlt(12, 1, CONST_chase077);
	if (chaseseq.canpullover)
	{
		mvaddstrAlt(13, 1, CONST_chase078);
	}
}
void destroyAllCarsAndDetermineMusic() {
	extern chaseseqst chaseseq;
	extern Deprecatedsquadst *activesquad;
	//DESTROY ALL CARS BROUGHT ALONG WITH PARTY
	deleteVehicles(chaseseq.friendcar);
	for (int p = 0; p < 6; p++)
	{
		if (activesquad->squad[p] == NULL) continue;
		activesquad->squad[p]->die();
		activesquad->squad[p]->location = -1;
		activesquad->squad[p] = NULL;
	}
	endcheck(END_BUT_NOT_END); // play the right music in case we're dead
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(9, 1, CONST_chase079);
}
LOOP_CONTINUATION chaseWithPartyAlive(const int c, short &obstacle) {


	extern short mode;
	extern chaseseqst chaseseq;
	extern Deprecatedsquadst *activesquad;
	extern short party_status;
	extern Deprecatednewsstoryst *sitestory;
	extern Log gamelog;
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();


	int partysize = squadsize(activesquad);
	int partyalive = squadalive(activesquad);

	if (c == 'o'&&partysize > 1)orderparty();
	if (c == '0')party_status = -1;
	if (c >= '1'&&c <= '6')
	{
		if (activesquad->squad[c - '1'] != NULL)
		{
			if (party_status == c - '1') fullstatus(party_status);
			else party_status = c - '1';
		}
	}
	if (c == 'b')
	{
		deleteVehicles(chaseseq.friendcar);
		for (int p = 0; p < 6; p++)
		{
			if (activesquad->squad[p] == NULL) continue;
			activesquad->squad[p]->carid = -1;
		}
		return footchase() ? RETURN_ONE : RETURN_ZERO;
	}
	else if (c == 'p')
	{
		if (chaseseq.canpullover)
		{
			chase_giveup();
			return RETURN_ZERO;
		}
	}
	else if (obstacle == -1)
	{
		if (c == 'd')
		{
			if (encounter[0].exists&&
				encounter[0].type == CREATURE_COP)
			{
				if (chaseseq.location) sitestory->crime.push_back(CRIME_CARCHASE);
				criminalizeparty(LAWFLAG_RESIST);
			}
			evasivedrive();
			enemyattack();
			youattack();
			creatureadvance();
			if (drivingupdate(obstacle))
			{
				partysize = squadsize(activesquad), partyalive = squadalive(activesquad);
				if (partyalive > 0) return footchase() ? RETURN_ONE : RETURN_ZERO;
			}
		}
		if (c == 'f')
		{
			if (encounter[0].exists&&
				encounter[0].type == CREATURE_COP)
			{
				if (chaseseq.location) sitestory->crime.push_back(CRIME_CARCHASE);
				criminalizeparty(LAWFLAG_RESIST);
			}
			youattack();
			enemyattack();
			creatureadvance();
			if (drivingupdate(obstacle))
			{
				partysize = squadsize(activesquad), partyalive = squadalive(activesquad);
				if (partyalive > 0) return footchase() ? RETURN_ONE : RETURN_ZERO;
			}
		}
		if (c == 'e') equip(activesquad->loot, -1);
	}
	else
	{
		switch (obstacle)
		{
		case CARCHASE_OBSTACLE_CHILD:
		case CARCHASE_OBSTACLE_CROSSTRAFFIC:
		case CARCHASE_OBSTACLE_TRUCKPULLSOUT:
		case CARCHASE_OBSTACLE_FRUITSTAND:
			if (c == 'd')
			{
				if (obstacledrive(obstacle, 0))
				{
					partysize = squadsize(activesquad), partyalive = squadalive(activesquad);
					if (partyalive > 0) return footchase() ? RETURN_ONE : RETURN_ZERO;
				}
				creatureadvance();
				drivingupdate(obstacle);
			}
			if (c == 'f')
			{
				if (obstacledrive(obstacle, 1))
				{
					partysize = squadsize(activesquad), partyalive = squadalive(activesquad);
					if (partyalive > 0) return footchase() ? RETURN_ONE : RETURN_ZERO;
				}
				creatureadvance();
				if (drivingupdate(obstacle))
				{
					partysize = squadsize(activesquad), partyalive = squadalive(activesquad);
					if (partyalive > 0) return footchase() ? RETURN_ONE : RETURN_ZERO;
				}
			}
			break;
		}
	}
	//HAVE YOU LOST ALL OF THEM?
	//THEN LEAVE
	partysize = squadsize(activesquad), partyalive = squadalive(activesquad);
	int baddiecount = baddieCount(true);
	if (partyalive > 0 && baddiecount == 0)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		clearmessagearea();
		mvaddstrAlt(16, 1, lostThem, gamelog);
		gamelog.newline(); //New line.
		pressAnyKey();
		CreaturePool::getInstance().stopAllBleeding();
		return RETURN_ONE;
	}
	return REPEAT;
}
LOOP_CONTINUATION increment_chasesequence(short& obstacle) {

	extern chaseseqst chaseseq;
	extern Deprecatedsquadst *activesquad;
	extern short party_status;

	int partyalive = squadalive(activesquad);

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(0, 0, LocationsPool::getInstance().getLocationName(chaseseq.location));
	//PRINT PARTY
	if (partyalive == 0) party_status = -1;
	printparty();
	if (partyalive > 0)
	{
		printSituationAndInstructions(obstacle);
	}
	else
	{
		destroyAllCarsAndDetermineMusic();
	}
	//PRINT ENEMIES
	printchaseencounter();
	int c = getkeyAlt();
	if (partyalive == 0 && c == 'c')
	{
		if (!endcheck())
		{
			return RETURN_ZERO;
		}
	}
	else if (partyalive > 0) {
		return chaseWithPartyAlive(c, obstacle);
	}

	return REPEAT;

}
void addCreatueVehiclesToCollection(DeprecatedCreature *cr[6], vector<Vehicle *> &veh);
bool chasesequence()
{
	const string CONST_chase073 = "As you pull away from the site, you notice that you are ";
	extern MusicClass music;
	extern short mode;
	extern chaseseqst chaseseq;
	extern Deprecatedsquadst *activesquad;
	extern Log gamelog;
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();
	int chasenum = 0;
	reloadparty();
	//NOTE: THIS FUNCTION RETURNS 1 IF ANYBODY ESCAPES
	//IT CAN DELETE CREATURES AND VEHICLES, BUT SHOULD NOT DELETE SQUADS
	//AS SQUADS MAY BE FICTITIOUS AND WILL BE DELETED LATER ANYWAY
	//BAIL IF NO CHASERS
	for (int e = 0; e < ENCMAX; e++) if (encounter[e].exists) chasenum++;
	if (!chasenum)
	{
		gamelog.newline();
		return 1;
	}
	chaseseq.friendcar.clear();
	addCreatueVehiclesToCollection(activesquad->squad, chaseseq.friendcar);
	mode = GAMEMODE_CHASECAR;
	music.play(MUSIC_CARCHASE);
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(0, 0, CONST_chase073, gamelog);
	mvaddstrAlt(1, 0, beingFollowedBySwine, gamelog);
	gamelog.newline(); //New line.
	pressAnyKey();
	if (LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONPARENT,chaseseq.location) != -1)
		chaseseq.location = LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONPARENT,chaseseq.location);
	short obstacle = -1;
	while (true) {
		LOOP_CONTINUATION x = increment_chasesequence(obstacle);
		if (x == RETURN_ZERO) {
			mode = GAMEMODE_BASE;
			//Make sure all possible exits of the chase have the nextMessage() call
			//to ensure that the gamelog is split properly into blocks.
			gamelog.nextMessage();
			return 0;
		}
		else if (x == RETURN_ONE) {
			mode = GAMEMODE_BASE;
			//Make sure all possible exits of the chase have the nextMessage() call
			//to ensure that the gamelog is split properly into blocks.
			gamelog.nextMessage();
			return 1;
		}
	}
}
Vehicle* getChaseVehicle(const DeprecatedCreature &c)
{
	extern short mode;
	extern chaseseqst chaseseq;
	Vehicle* found = NULL;
	if (mode == GAMEMODE_CHASECAR && c.carid != -1)
	{
		for (int v2 = 0; v2 < len(chaseseq.friendcar); v2++)
			if (chaseseq.friendcar[v2]->id() == c.carid)
			{
				found = chaseseq.friendcar[v2];
				break;
			}
		for (int v2 = 0; v2 < len(chaseseq.enemycar); v2++)
			if (chaseseq.enemycar[v2]->id() == c.carid)
			{
				found = chaseseq.enemycar[v2];
				break;
			}
	}
	return found;
}
DeprecatedCreature* getChaseDriver(const DeprecatedCreature &c)
{
	extern short mode;
	extern Deprecatedsquadst *activesquad;
	extern DeprecatedCreature encounter[ENCMAX];
	DeprecatedCreature* found = NULL;
	if (mode == GAMEMODE_CHASECAR && c.carid != -1)
	{
		int v = c.carid;
		// Check to see if the car we are in is being driven by an LCS member
		for (int p = 0; p < 6; p++)
		{
			if (activesquad->squad[p] == NULL) continue;
			if (activesquad->squad[p]->carid == v
				&& activesquad->squad[p]->is_driver)
			{
				found = activesquad->squad[p];
			}
		}
		// Check to see if the car we are in is being driven by an encounter creature.
		for (int p = 0; p < ENCMAX; p++)
		{
			if (!encounter[p].exists) continue;
			if (encounter[p].carid == v
				&& encounter[p].is_driver)
			{
				found = &encounter[p];
			}
		}
	}
	//gamelog.newline();
	return found;
}
void conservatise(const int e);
Vehicle* getVehicleOfThisType(int cartype);
const string CONST_chase094 = "STATIONWAGON";
const string CONST_chase093 = "PICKUP";
const string CONST_chase092 = "JEEP";
const string CONST_chase091 = "SUV";
const string CONST_chase090 = "AGENTCAR";
const string CONST_chase088 = "HMMWV";
void makechasers(long type, const long sitecriminality)
{
	extern char endgamestate;
	extern chaseseqst chaseseq;
	extern DeprecatedCreature encounter[ENCMAX];
	extern short lawList[LAWNUM];
	// 
	long sitecrime_chasers;
	if (sitecriminality > 10) {
		sitecrime_chasers = 0;
		long sitecrime_log = sitecriminality;
		while (sitecrime_log > 10) {
			sitecrime_log /= 2;
			sitecrime_chasers += 10;
		}
		sitecrime_chasers += sitecrime_log;
	}
	else {
		sitecrime_chasers = sitecriminality;
	}
	emptyEncounter();
	if (!sitecrime_chasers) return;
	//short encslot = 0;
	string cartype; //Temporary (transitionally) solution. -XML
	long pnum;
	chaseseq.canpullover = 0;
	// 50% of CCS harassing your teams once they reach the
	// CONST_chase086 stage (but not for activities, which are
	// law enforcement response specific)
	int crime_ratio;
	CreatureTypes chasing_enemy;
	int min_enemies;
	int max_enemies;
	if (type != -1 && (endgamestate == ENDGAME_CCS_SIEGES || endgamestate == ENDGAME_CCS_ATTACKS) && LCSrandom(2))
	{
		cartype = CONST_chase091; //A CCS property, not a vehicle property. Temporary solution -XML
		crime_ratio = 5;
		min_enemies = 1;
		max_enemies = 12;
		chasing_enemy = CREATURE_CCS_VIGILANTE;
	}
	else
	{
		switch (type)
		{
		case SITE_GOVERNMENT_ARMYBASE:
			cartype = CONST_chase088; //Site property? Temporary solution. -XML
			crime_ratio = 5;
			min_enemies = 3;
			max_enemies = 6;
			chasing_enemy = CREATURE_SOLDIER;
			break;
		case SITE_GOVERNMENT_WHITE_HOUSE:
			cartype = CONST_chase090; //Site property? Temporary solution. -XML
			crime_ratio = 5;
			min_enemies = 1;
			max_enemies = 6;
			chasing_enemy = CREATURE_SECRET_SERVICE;
			break;
		case SITE_GOVERNMENT_INTELLIGENCEHQ:
			cartype = CONST_chase090; //Site property? Temporary solution. -XML
			crime_ratio = 5;
			min_enemies = 1;
			max_enemies = 6;
			chasing_enemy = CREATURE_AGENT;
			break;
		case SITE_CORPORATE_HEADQUARTERS:
		case SITE_CORPORATE_HOUSE:
			if (LCSrandom(2))cartype = CONST_chase091; //Site property? Temporary solution. -XML
			else cartype = CONST_chase092; //Site property? Temporary solution. -XML
			crime_ratio = 5;
			min_enemies = 1;
			max_enemies = 6;
			chasing_enemy = CREATURE_MERC;
			break;
		case SITE_MEDIA_AMRADIO:
		case SITE_MEDIA_CABLENEWS:
			cartype = CONST_chase093; //Site property? Temporary solution. -XML
			crime_ratio = 3;
			min_enemies = 1;
			max_enemies = 18;
			chasing_enemy = CREATURE_HICK;
			break;
		case SITE_BUSINESS_CRACKHOUSE:
			cartype = CONST_chase094; //Site property? Temporary solution. -XML
			crime_ratio = 3;
			min_enemies = 1;
			max_enemies = 18;
			chasing_enemy = CREATURE_GANGMEMBER;
			break;
		default:
			chaseseq.canpullover = 1;
			cartype = tag_POLICECAR; //Police property? Temporary solution. -XML
			crime_ratio = 5;
			min_enemies = 1;
			max_enemies = 6;
			if (lawList[LAW_DEATHPENALTY] == -2 &&
				lawList[LAW_POLICEBEHAVIOR] == -2) {
				chasing_enemy = CREATURE_DEATHSQUAD;
				chaseseq.canpullover = 0;
			}
			else if (lawList[LAW_POLICEBEHAVIOR] <= -1)
			{
				chasing_enemy = CREATURE_GANGUNIT;
			}
			else
			{
				chasing_enemy = CREATURE_COP;
			}
			break;
		}
	}
	pnum = LCSrandom((sitecrime_chasers / crime_ratio) + 1) + min_enemies;
	if (pnum > max_enemies) pnum = max_enemies;
	for (int n = 0; n < pnum; n++) {
		makecreature(n, chasing_enemy);
	}
	for (int n = 0; n < pnum; n++) conservatise(n);
	//ASSIGN CARS TO CREATURES
	int carnum;
	if (pnum <= 2) carnum = 1;
	else if (pnum <= 3) carnum = LCSrandom(2) + 1;
	else if (pnum <= 5) carnum = LCSrandom(2) + 2;
	else if (pnum <= 7) carnum = LCSrandom(2) + 3;
	else carnum = 4;
	for (int c = 0; c < carnum; c++)
	{
		Vehicle *v = getVehicleOfThisType(getvehicletype(cartype)); //If car type is unknown, due to change in xml file, the game will crash here. -XML
		chaseseq.enemycar.push_back(v);
		for (int n = 0; n < pnum; n++)
			if (encounter[n].carid == -1)
			{
				encounter[n].carid = v->id();
				encounter[n].is_driver = 1;
				break;
			}
	}
	long load[4] = { 0,0,0,0 };
	for (int n = 0; n < pnum; n++)
		if (encounter[n].carid == -1)
		{
			int v;
			do
			{
				v = LCSrandom(len(chaseseq.enemycar));
				encounter[n].carid = chaseseq.enemycar[v]->id();
				encounter[n].is_driver = 0;
			} while (load[v] >= 4);
			load[v]++;
		}
}
void removeCreatureFromSquad(DeprecatedCreature &cr, int oldsqid);

/* the next two functions force a chase sequence with a specific liberal */
bool footchase(DeprecatedCreature &cr)
{
	extern Deprecatedsquadst *activesquad;
	extern short party_status;
	extern long cursquadid;
	long oldsqid = cr.squadid;
	DeprecatedCreature *crp = &cr;
	Deprecatedsquadst *sq = new Deprecatedsquadst;
	sq->squad[0] = &cr;
	sq->squad[0]->squadid = cursquadid; cursquadid++;
	cr.squadid = sq->squad[0]->squadid;
	cr.carid = -1;
	Deprecatedsquadst *oact = activesquad;
	short ops = party_status;
	activesquad = sq;
	party_status = 0;
	bool escaped = footchase();
	party_status = ops;
	delete sq;
	if (escaped) cr.squadid = oldsqid;
	else if (oldsqid != -1)
	{
		removeCreatureFromSquad(*crp, oldsqid);
	}
	activesquad = oact;
	return escaped;
}
bool chasesequence(DeprecatedCreature &cr, Vehicle &v)
{
	extern Deprecatedsquadst *activesquad;
	extern short party_status;
	extern long cursquadid;
	extern Log gamelog;
	long oldsqid = cr.squadid;
	Deprecatedsquadst *sq = new Deprecatedsquadst;
	sq->squad[0] = &cr;
	sq->squad[0]->squadid = cursquadid;
	sq->id = cursquadid; cursquadid++;
	cr.carid = v.id();
	cr.is_driver = 1;
	Deprecatedsquadst *oact = activesquad;
	short ops = party_status;
	activesquad = sq;
	party_status = 0;
	bool ret = chasesequence();
	party_status = ops;
	delete sq;
	if (ret)
	{
		cr.squadid = oldsqid;
		cr.carid = -1;
	}
	else if (oldsqid != -1)
	{
		removeCreatureFromSquad(cr, oldsqid);
	}
	activesquad = oact;
	gamelog.nextMessage(); //Next message.
	return ret;
}
