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

#include "vehicle/vehicletype.h"
#include "vehicle/vehicle.h"

#include "sitemode/stealth.h"
#include "sitemode/sitedisplay.h"

#include "items/money.h"

#include "log/log.h"
// for gamelog

#include "common/consolesupport.h"
// for void set_color(short,short,bool)      

#include "common/translateid.h"
// for  int id_getcar(int)

#include "common/stringconversion.h"
//for addstr

#include "common/commondisplay.h"
// for addstr (with log)

#include "common/commonactions.h"
#include "common/commonactionsCreature.h"
// for int squadsize(const squadst *);

#include "common/equipment.h"
//for void equip(vector<Item *>&,int)

#include "combat/fight.h"       
#include "combat/fightCreature.h"    
//own header

#include "combat/chase.h"
#include "combat/chaseCreature.h"
//for Vehicle* getChaseVehicle(const Creature &c);

//#include "combat/haulkidnap.h"
#include "combat/haulkidnapCreature.h"
// for void freehostage(Creature &cr,char situation);


#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
extern vector<Creature *> pool;
extern Log gamelog;
extern vector<Location *> location;
#include "locations/locationsPool.h"
extern short mode;
extern short sitetype;
extern char foughtthisround;
extern int stat_dead;
extern int stat_kills;
extern int ccs_siege_kills;
extern int ccs_boss_kills;
bool goodguyattack = false;
extern string tag_ARMOR;
 vector<string> escape_running;
 vector<string> escape_crawling;
 vector<string> judge_debate;
 vector<string> conservative_politician_debate;
 vector<string> other_politician_debate;
 vector<string> conservative_ceo_debate;
 vector<string> other_ceo_debate;
 vector<string> media_debate;
 vector<string> military_debate;
 vector<string> police_debate;
 vector<string> scientist_debate;
 vector<string> cry_alarm;
 vector<string> bleeding_to_death;
 vector<string> stunned_text;
 vector<string> paralyzed_text;
 vector<string> paralyzed_tank;
 vector<string> bleeding_animal;
 vector<vector<string>> double_line_death;
 vector<string> body_falls_apart;

 extern string singleSpace;
 extern short sitealarm;
 extern squadst *activesquad;
 extern Creature encounter[ENCMAX];
 extern newsstoryst *sitestory;
 extern int sitecrime;
 extern short cursite;
 extern int locx;
extern int locy;
 extern int locz;
 extern siteblockst levelmap[MAPX][MAPY][MAPZ];
 extern vector<Item *> groundloot;
 extern short sitealarmtimer;
 extern string singleDot;
 extern string commaSpace;
 extern short lawList[LAWNUM];
 extern vector<ArmorType *> armortype;
 extern char slogan[SLOGAN_LEN];

  vector<string> evasionStringsAlt;
  vector<string> evasionStrings;

#include "common/creaturePool.h"

/* attack handling for an individual creature and its target */
// returns a boolean representing whether it was the intended target or "actual"
// so bool actual does not need to be passed by reference
bool attack(Creature &a, Creature &t, const char mistake, const bool force_melee = false);
std::string burstHitString(int bursthits);
std::string burstHitString(int bursthits) {
	switch (bursthits)
	{
	case 1: return "";
	case 2: return " twice";
	case 3: return " three times";
	case 4: return " four times";
	case 5: return " five times";
	default: return singleSpace + tostring(bursthits) + " times";
	}
}
/* attack handling for each side as a whole */
void youattack()
{
	foughtthisround = 1;
	const short wasalarm = sitealarm;
	goodguyattack = true;
	for (int p = 0; p < 6; p++)
	{
		if (activesquad->squad[p] == NULL) continue;
		if (!activesquad->squad[p]->alive) continue;
		vector<int> super_enemies;
		vector<int> dangerous_enemies;
		vector<int> enemies;
		vector<int> non_enemies;
		for (int e = 0; e < ENCMAX; e++)
		{
			if (encounter[e].alive&&encounter[e].exists)
			{
				if (encounter[e].enemy())
				{
					if (encounter[e].animalgloss == ANIMALGLOSS_TANK&&
						encounter[e].stunned == 0)
						super_enemies.push_back(e);
					else if ((encounter[e].is_armed() ||
						(encounter[e].type == CREATURE_COP&&encounter[e].align == ALIGN_MODERATE) ||
						encounter[e].type == CREATURE_SCIENTIST_EMINENT ||
						encounter[e].type == CREATURE_JUDGE_LIBERAL ||
						encounter[e].type == CREATURE_JUDGE_CONSERVATIVE ||
						encounter[e].type == CREATURE_CORPORATE_CEO ||
						encounter[e].type == CREATURE_POLITICIAN ||
						encounter[e].type == CREATURE_RADIOPERSONALITY ||
						encounter[e].type == CREATURE_NEWSANCHOR ||
						encounter[e].type == CREATURE_MILITARYOFFICER ||
						encounter[e].specialattack != -1) &&
						encounter[e].blood >= 40 &&
						encounter[e].stunned == 0)
						dangerous_enemies.push_back(e);
					else enemies.push_back(e);
				}
				else non_enemies.push_back(e);
			}
		}
		if (!(len(super_enemies) + len(dangerous_enemies) + len(enemies))) return;
		int target;
		// If there are "super enemies", shoot at one of them unless we're using a persuasion-based attack
		if (len(super_enemies) &&
			((activesquad->squad[p]->type != CREATURE_SCIENTIST_EMINENT&&
				activesquad->squad[p]->type != CREATURE_JUDGE_LIBERAL&&
				activesquad->squad[p]->type != CREATURE_JUDGE_CONSERVATIVE&&
				activesquad->squad[p]->type != CREATURE_CORPORATE_CEO&&
				activesquad->squad[p]->type != CREATURE_POLITICIAN&&
				activesquad->squad[p]->type != CREATURE_RADIOPERSONALITY&&
				activesquad->squad[p]->type != CREATURE_NEWSANCHOR&&
				activesquad->squad[p]->type != CREATURE_MILITARYOFFICER&&
				!activesquad->squad[p]->get_weapon().has_musical_attack()) ||
				(!activesquad->squad[p]->get_weapon().has_musical_attack() &&
					activesquad->squad[p]->is_armed())))
			target = pickrandom(super_enemies);
		// Else, if there are "dangerous enemies", shoot at one of them
		else if (len(dangerous_enemies))
			target = pickrandom(dangerous_enemies);
		// Else, if there are regular enemies, shoot at one of them
		else if (len(enemies)) target = pickrandom(enemies);
		// Else, we skipped a "super enemy" because it we're using a persuasion-based attack but it's the only enemy left so we have to pick it
		else target = pickrandom(super_enemies);
		char mistake = 0;

		// Mistaken attack
		/*
		Mistakenly attacking innocents: if skill is 8 or higher, there is no chance of mistakenly hitting innocents (except when used as a human shield).
		If skill is 7 or lower, the odds are based on skill, with a maximum of 10% chance at skill = 0;
		Melee weapons only require a skill of 4.
		If skill is 3 or lower, the odds are based on skill, with a maximum of 5% chance at skill = 0;
		*/
		if (len(non_enemies) && activesquad->squad[p]->get_weapon_skill() < (4 + (activesquad->squad[p]->get_weapon().is_ranged() * 4)) &&
			!LCSrandom(10 + 2 * (5 + 5 * activesquad->squad[p]->get_weapon().is_ranged()) * activesquad->squad[p]->get_weapon_skill()))
			// Mistaken attack
		{
			target = pickrandom(non_enemies);
			mistake = 1;
		}
		bool actual;
		const short beforeblood = encounter[target].blood;
		if (encounter[target].align == 1) mistake = 1;
		actual = attack(*activesquad->squad[p], encounter[target], mistake);
		if (actual)
		{
			if (mistake)
			{
				alienationcheck(mistake);
				sitestory->crime.push_back(CRIME_ATTACKED_MISTAKE);
				sitecrime += 10;
			}
			else
			{
				sitecrime += 3;
				addjuice(*(activesquad->squad[p]), 1, 200);
			}
			sitestory->crime.push_back(CRIME_ATTACKED);
			// Charge with assault if first strike
			if (sitealarm && (!wasalarm || (beforeblood > encounter[target].blood && beforeblood == 100)))
			{
				if (!activesquad->squad[p]->is_armed())
					criminalize(*activesquad->squad[p], LAWFLAG_ASSAULT);
				else criminalize(*activesquad->squad[p], LAWFLAG_ARMEDASSAULT);
			}
		}
		if (!encounter[target].alive)
		{
			delenc(target, 1);
			if (!mistake)
			{
				for (int p = 0; p < 6; p++)
				{
					if (activesquad->squad[p] == NULL) continue;
					if (!activesquad->squad[p]->alive) continue;
					addjuice(*(activesquad->squad[p]), 5, 500);
				}
			}
		}
	}
	for (int e = 0; e < ENCMAX; e++)
	{
		if (encounter[e].exists && encounter[e].alive && encounter[e].enemy())
		{
			sitealarm = 1;
			break;
		}
	}
	//COVER FIRE
	if (LocationsPool::getInstance().isThereASiegeHere(cursite))
	{
		for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
		{
			if (!pool[p]->alive) continue;
			if (pool[p]->align != 1) continue;
			if (pool[p]->squadid != -1) continue;
			if (pool[p]->location != cursite) continue;
			// Juice check to engage in cover fire
			// 10% chance for every 10 juice, starting at
			// 10% chance for 0 juice -- caps out at 100%
			// chance to fire at 90 juice
			//if(LCSrandom(10)-pool[p]->juice/10>0)continue;
			if (pool[p]->get_weapon().get_attack(true, false, false))
			{
				char conf = 0;
				if (pool[p]->get_weapon().get_ammoamount()>0) conf = 1;
				if (pool[p]->get_weapon().get_attack(true, false, false)->uses_ammo)
					if (pool[p]->can_reload()) conf = 1;
				if (conf)
				{
					vector<int> goodtarg, badtarg;
					for (int e = 0; e < ENCMAX; e++)
					{
						if (encounter[e].alive&&encounter[e].exists)
						{
							if (encounter[e].enemy())goodtarg.push_back(e);
							else badtarg.push_back(e);
						}
					}
					if (!len(goodtarg)) return;
					int target = pickrandom(goodtarg);
					char mistake = 0;
					// Mistaken attack
					/*
					Mistakenly attacking innocents: if skill is 8 or higher, there is no chance of mistakenly hitting innocents (except when used as a human shield).
					If skill is 7 or lower, the odds are based on skill, with a maximum of 10% chance at skill = 0;
					Melee weapons only require a skill of 4.
					If skill is 3 or lower, the odds are based on skill, with a maximum of 5% chance at skill = 0;
					*/
					if(len(badtarg) && pool[p]->get_weapon_skill() < ( 4 + (pool[p]->get_weapon().is_ranged() * 4) ) &&
						!LCSrandom(10 + 2 * (5 + 5 * pool[p]->get_weapon().is_ranged()) * pool[p]->get_weapon_skill()))
					{
						target = pickrandom(badtarg);
						mistake = 1;
					}
					bool actual;
					actual = attack(*pool[p], encounter[target], mistake);
					if (actual)
					{
						if (mistake)
						{
							alienationcheck(mistake);
							sitestory->crime.push_back(CRIME_ATTACKED_MISTAKE);
							sitecrime += 10;
						}
						if (!pool[p]->is_armed())
							criminalize(*pool[p], LAWFLAG_ASSAULT);
						else criminalize(*pool[p], LAWFLAG_ARMEDASSAULT);
					}
					if (!encounter[target].alive) delenc(target, 1);
				}
			}
		}
	}
}
void enemyattack()
{
	foughtthisround = 1;
	goodguyattack = false;
	bool armed = false;
	for (int i = 0; i < 6; i++)
	{
		if (activesquad->squad[i] == NULL) break;
		if (activesquad->squad[i]->is_armed()) armed = true;
	}
	if (NOENEMYATTACK) {
		return;
	}
	int e2, e;
	char printed;
	for (e = 0; e < ENCMAX; e++)
	{
		if (!encounter[e].exists) continue;
		if (!encounter[e].alive) continue;
		if (sitealarm == 1 && encounter[e].type == CREATURE_BOUNCER&&encounter[e].align != ALIGN_LIBERAL)
			conservatise(encounter[e]);
		if (encounter[e].enemy()) encounter[e].cantbluff = 2;
		if (mode != GAMEMODE_CHASECAR)
		{
			// Encountered creature will flee if:
			// (a) Non-Conservative, and not recently converted via music or some other mechanism
			// (b) Conservative, no juice, unarmed, non-tank/animal, enemy is armed, and fails a morale check based in part on injury level
			// (c) Conservative, and lost more than 55% blood
			// (d) There's a fire, they are not firefighters, and they fail a random check
			// Encountered creatures will never flee if they are tanks, animals, or so hurt they can't move
			char fire = 0;
			if (mode == GAMEMODE_SITE)
			{
				if (levelmap[locx][locy][locz].flag & SITEBLOCK_FIRE_START ||
					levelmap[locx][locy][locz].flag & SITEBLOCK_FIRE_END)
					fire = 1;
				else if (levelmap[locx][locy][locz].flag & SITEBLOCK_FIRE_PEAK)
					fire = 2;
			}
			if (((!encounter[e].enemy() ||
				(encounter[e].juice == 0 && !encounter[e].is_armed() && armed&&encounter[e].blood<signed(70 + LCSrandom(61))))
				&& !(encounter[e].flag & CREATUREFLAG_CONVERTED)) || (encounter[e].blood < 45 && encounter[e].juice < 200)
				|| ((fire*LCSrandom(5) >= 3) && !(encounter[e].type == CREATURE_FIREFIGHTER)))
			{
				if (encounter[e].animalgloss == ANIMALGLOSS_NONE)
				{
					if (!incapacitated(encounter[e], 0, printed))
					{
						if (printed)
						{
							printparty();
							if (mode == GAMEMODE_CHASECAR ||
								mode == GAMEMODE_CHASEFOOT) printchaseencounter();
							else printencounter();
							getkeyAlt();
						}
						clearmessagearea();
						mvaddstrAlt(16,  1, encounter[e].name, gamelog);
						if ((encounter[e].wound[BODYPART_LEG_RIGHT] & WOUND_NASTYOFF) ||
							(encounter[e].wound[BODYPART_LEG_RIGHT] & WOUND_CLEANOFF) ||
							(encounter[e].wound[BODYPART_LEG_LEFT] & WOUND_NASTYOFF) ||
							(encounter[e].wound[BODYPART_LEG_LEFT] & WOUND_CLEANOFF) ||
							(encounter[e].blood < 45))
							addstrAlt(pickrandom(escape_crawling), gamelog);
						else addstrAlt(pickrandom(escape_running), gamelog);
						gamelog.newline();
						delenc(e, 0);
						e--;
						printparty();
						if (mode == GAMEMODE_CHASECAR ||
							mode == GAMEMODE_CHASEFOOT) printchaseencounter();
						else printencounter();
						getkeyAlt();
					}
					continue;
				}
			}
		}
		vector<int> goodtarg, badtarg;
		if (encounter[e].enemy())
		{
			for (int p = 0; p < 6; p++) {
				if (activesquad->squad[p] != NULL) {
					if (activesquad->squad[p]->alive) { goodtarg.push_back(p); }
				}
			}
		}
		else
		{
			for (e2 = 0; e2 < ENCMAX; e2++)
			{
				if (!encounter[e2].exists) continue;
				if (!encounter[e2].alive) continue;
				if (encounter[e2].align != -1) continue;
				goodtarg.push_back(e2);
			}
		}
		for (e2 = 0; e2 < ENCMAX; e2++)
		{
			if (!encounter[e2].exists) continue;
			if (!encounter[e2].alive) continue;
			if (encounter[e2].enemy()) continue;
			badtarg.push_back(e2);
		}
		if (!len(goodtarg)) return;
		int target = pickrandom(goodtarg);
		char canmistake = 1;
		int encnum = 0;
		for (e2 = 0; e2 < ENCMAX; e2++) if (encounter[e2].exists) encnum++;
		if ((encounter[e].type == CREATURE_SCIENTIST_EMINENT ||
			encounter[e].type == CREATURE_JUDGE_LIBERAL ||
			encounter[e].type == CREATURE_JUDGE_CONSERVATIVE ||
			encounter[e].type == CREATURE_CORPORATE_CEO ||
			encounter[e].type == CREATURE_POLITICIAN ||
			encounter[e].type == CREATURE_RADIOPERSONALITY ||
			encounter[e].type == CREATURE_NEWSANCHOR ||
			encounter[e].type == CREATURE_MILITARYOFFICER) && encnum < ENCMAX) canmistake = 0;
		bool actual;
		if (canmistake)
		{
			if (encounter[e].enemy())
			{
				if (activesquad->squad[target]->prisoner != NULL && !LCSrandom(2))
				{
					// Mistaken attack
					actual = attack(encounter[e], *activesquad->squad[target]->prisoner, 1);
					if (!activesquad->squad[target]->prisoner->alive)
					{
						if (activesquad->squad[target]->prisoner->squadid == -1)
						{
							clearmessagearea();
							set_color_easy(WHITE_ON_BLACK_BRIGHT);
							mvaddstrAlt(16,  1, activesquad->squad[target]->name, gamelog);
							addstrAlt(" drops ", gamelog);
							addstrAlt(activesquad->squad[target]->prisoner->name, gamelog);
							addstrAlt("'s body.", gamelog);
							gamelog.newline();
							const int prisonerType = activesquad->squad[target]->prisoner->type;
							if (prisonerType == CREATURE_CORPORATE_CEO ||
								prisonerType == CREATURE_POLITICIAN ||
								prisonerType == CREATURE_RADIOPERSONALITY ||
								prisonerType == CREATURE_NEWSANCHOR ||
								prisonerType == CREATURE_SCIENTIST_EMINENT ||
								prisonerType == CREATURE_JUDGE_CONSERVATIVE ||
								prisonerType == CREATURE_MILITARYOFFICER) sitecrime += 30;
							makeloot(*activesquad->squad[target]->prisoner, groundloot);
							getkeyAlt();
							delete_and_nullify(activesquad->squad[target]->prisoner);
						}
					}
					continue;
				}
			}
			// Mistaken attack
			/*
			Mistakenly attacking innocents: if skill is 8 or higher, there is no chance of mistakenly hitting innocents (except when used as a human shield).
			If skill is 7 or lower, the odds are based on skill, with a maximum of 20% chance at skill = 0;
			Melee weapons only require a skill of 4.
			If skill is 3 or lower, the odds are based on skill, with a maximum of 10% chance at skill = 0;
			*/
			if(len(badtarg) && encounter[e].get_weapon_skill() < (4 + (encounter[e].get_weapon().is_ranged() * 4)) &&
				!LCSrandom(10 + 2 * (5 + 5 * encounter[e].get_weapon().is_ranged()) * encounter[e].get_weapon_skill()))
			{
				target = pickrandom(badtarg);
				if (encounter[target].flag & CREATUREFLAG_CONVERTED)
					actual = attack(encounter[e], encounter[target], 0);
				// Mistaken Attack
				else actual = attack(encounter[e], encounter[target], 1);
				if (!encounter[target].alive) delenc(target, 1);
				continue;
			}
		}
		if (encounter[e].enemy())
			actual = attack(encounter[e], *activesquad->squad[target], 0);
		else actual = attack(encounter[e], encounter[target], 0);
	}
}
std::string bodypartName(Bodyparts w, AnimalGlosses t);
string specialWoundPossibilityBody(
	Creature &target,
	const char breakdam,
	const char pokedam,
	const char damtype
	);
string specialWoundPossibilityHead(
	Creature &target,
	const char breakdam,
	const char heavydam,
	const char damtype
	);
/* attack handling for an individual creature and its target */
bool attack(Creature &a, Creature &t, const char mistake, const bool force_melee)
{
	//char newActual = 0;
	bool actual = false;
	char str[200];
	clearmessagearea(true);  // erase the whole length and redraw map if applicable, since previous combat messages can be wider than 53 chars.
	if (goodguyattack) set_color_easy(GREEN_ON_BLACK_BRIGHT);
	else set_color_easy(RED_ON_BLACK_BRIGHT);
	//INCAPACITATED
	char incaprint;
	a.forceinc = 0;
	if (incapacitated(a, 0, incaprint))
	{
		if (incaprint)
		{
			printparty();
			if (mode == GAMEMODE_CHASECAR ||
				mode == GAMEMODE_CHASEFOOT) printchaseencounter();
			else printencounter();
			getkeyAlt();
		}
		a.forceinc = 1;
		return actual;
	}
	//SPECIAL ATTACK!
	int encnum = 0;
	for (int e = 0; e < ENCMAX; e++) if (encounter[e].exists) encnum++;

	bool specialAttackIsPossible = (!force_melee &&
		(((a.type == CREATURE_COP&&a.align == ALIGN_MODERATE&&a.enemy()) ||
			a.type == CREATURE_SCIENTIST_EMINENT ||
			a.type == CREATURE_JUDGE_LIBERAL ||
			a.type == CREATURE_JUDGE_CONSERVATIVE ||
			(a.type == CREATURE_CORPORATE_CEO&&LCSrandom(2)) ||
			a.type == CREATURE_POLITICIAN ||
			a.type == CREATURE_RADIOPERSONALITY ||
			a.type == CREATURE_NEWSANCHOR ||
			a.type == CREATURE_MILITARYOFFICER ||
			a.get_weapon().has_musical_attack()) &&
			(a.get_weapon().has_musical_attack() || !a.is_armed() || a.align != 1)));

	if (specialAttackIsPossible)
	{
		if (a.align == 1 || encnum < ENCMAX)
		{
			specialattack(a, t);
			return actual;
		}
	}
	//RELOAD
	if ((a.will_reload(mode == GAMEMODE_CHASECAR, force_melee)
		|| (a.has_thrown_weapon && len(a.extra_throwing_weapons)))
		&& !force_melee)
	{
		if (a.will_reload(mode == GAMEMODE_CHASECAR, force_melee))
		{
			a.reload(false);
			strcpy(str, a.name);
			strcat(str, " reloads.");
		}
		else if (a.has_thrown_weapon && len(a.extra_throwing_weapons))
		{
			a.ready_another_throwing_weapon();
			strcpy(str, a.name);
			strcat(str, " readies another ");
			strcat(str, a.get_weapon().get_name());
			strcat(str, singleDot);
		}
		mvaddstrAlt(16,  1, str, gamelog);
		gamelog.newline();
		printparty();
		if (mode == GAMEMODE_CHASECAR
			|| mode == GAMEMODE_CHASEFOOT) printchaseencounter();
		else printencounter();
		getkeyAlt();
		return actual;
	}
	else if (a.has_thrown_weapon) a.has_thrown_weapon = false;
	const attackst* attack_used = NULL;
	attack_used = a.get_weapon().get_attack(mode == GAMEMODE_CHASECAR,          //Force ranged if in a car.
		force_melee,
		(force_melee || !a.can_reload())); //No reload if force melee or unable to reload.
	if (attack_used == NULL) //No attack possible.
		return actual;            //Then bail, they can't fight
	bool melee = true;
	if (attack_used->ranged) melee = false;
	bool sneak_attack = false;
	strcpy(str, a.name);
	strcat(str, singleSpace);
	if (mistake) strcat(str, "MISTAKENLY ");
	if (!a.is_armed())
	{
		if (!a.animalgloss) //Move into WEAPON_NONE -XML
		{
			if (!LCSrandom(a.get_skill(SKILL_HANDTOHAND) + 1))
				strcat(str, "punches");
			else if (!LCSrandom(a.get_skill(SKILL_HANDTOHAND)))
				strcat(str, "swings at");
			else if (!LCSrandom(a.get_skill(SKILL_HANDTOHAND) - 1))
				strcat(str, "grapples with");
			else if (!LCSrandom(a.get_skill(SKILL_HANDTOHAND) - 2))
				strcat(str, "kicks");
			else if (!LCSrandom(a.get_skill(SKILL_HANDTOHAND) - 3))
				strcat(str, "strikes at");
			else if (!LCSrandom(a.get_skill(SKILL_HANDTOHAND) - 4))
				strcat(str, "jump kicks");
			else strcat(str, "gracefully strikes at");
		}
		else
		{
			if (a.specialattack == ATTACK_CANNON)
			{
				strcat(str, "fires a 120mm shell at");
				melee = false;
			}
			else if (a.specialattack == ATTACK_FLAME) strcat(str, "breathes fire at");
			else if (a.specialattack == ATTACK_SUCK) strcat(str, "stabs");
			else strcat(str, "bites");
		}
	}
	else
	{
		if (attack_used->can_backstab && a.align == ALIGN_LIBERAL && !mistake)
		{
			if (t.cantbluff < 1 && sitealarm < 1)
			{
				sneak_attack = true;
				strcat(str, "sneaks up on");
				if (sitealarmtimer > 10 || sitealarmtimer < 0) sitealarmtimer = 10;
				t.cantbluff = 2;
			}
		}
		if (!sneak_attack)
		{
			strcat(str, attack_used->attack_description);
			sitealarm = 1;
		}
	}
	strcat(str, singleSpace);
	strcat(str, t.name);
	mvaddstrAlt(16,  1, str, gamelog);
	strcpy(str, "");
	if (a.is_armed() && !attack_used->thrown)
	{
		strcat(str, " with a ");
		strcat(str, a.get_weapon().get_name(1));
	}
	strcat(str, "!");
	addstrAlt(str, gamelog);
	gamelog.newline();
	getkeyAlt();
	if (goodguyattack) set_color_easy(GREEN_ON_BLACK_BRIGHT);
	else set_color_easy(RED_ON_BLACK_BRIGHT);
	strcpy(str, a.heshe(true)); // capitalize=true. Shorten the string so it doesn't spill over as much; we already said attacker's name on the previous line anyways.
	int bonus = 0; // Accuracy bonus or penalty that does NOT affect damage or counterattack chance
				   //SKILL EFFECTS
	const int wsk = (attack_used->skill);
	Creature* driver = getChaseDriver(t);
	Vehicle* vehicle = getChaseVehicle(t);
	Creature* adriver = getChaseDriver(a);
	Vehicle* avehicle = getChaseVehicle(a);
	// Basic roll
	int aroll = a.skill_roll(wsk);
	// In a car chase, the driver provides the defence roll instead of the victim.
	int droll = 0;
	if (mode != GAMEMODE_CHASECAR)
	{
		droll = t.skill_roll(SKILL_DODGE) / 2;
	}
	else
	{
		if (driver != NULL && vehicle != NULL)
		{  // without a vehicle or driver, you get a zero roll.
			droll = driver->skill_roll(PSEUDOSKILL_DODGEDRIVE);
		}
		if (adriver != NULL && avehicle != NULL)
		{
			bonus += avehicle->attackbonus(adriver->id == a.id);  // Attack bonus depends on attacker's car and whether attacker is distracted by driving.
		}
		else // shouldn't happen
		{
			bonus -= 10; // You're on the wrong side of a drive-by shooting?!
		}
	}
	if (sneak_attack)
	{
		droll = t.attribute_roll(ATTRIBUTE_WISDOM) / 2;
		aroll += a.skill_roll(SKILL_STEALTH);
		a.train(wsk, 10);
	}
	else
	{
		if (driver != NULL)
			driver->train(SKILL_DRIVING, aroll / 2);
		else
			t.train(SKILL_DODGE, aroll * 2);
		a.train(wsk, droll * 2 + 5);
	}
	// Hostages interfere with attack
	if (t.prisoner != NULL) bonus -= LCSrandom(10);
	if (a.prisoner != NULL) aroll -= LCSrandom(10);
	//Injured people suck at attacking, are like fish in a barrel to attackers
	if (mode == GAMEMODE_CHASEFOOT)
	{
		// If in a foot chase, double the debilitating effect of injuries
		healthmodroll(aroll, a);
		healthmodroll(droll, t);
		healthmodroll(droll, t);
	}
	else if (mode == GAMEMODE_CHASECAR)
	{
		// In a car chase, the driver is applying dodge rolls even for crippled people.
		healthmodroll(aroll, a);
		if (driver != NULL)
		{// if there is no driver, we already rolled a zero, so don't worry about further penalties.
			healthmodroll(droll, *driver);
		}
	}
	else
	{
		// Any other case (site fight) normal penalties.
		healthmodroll(aroll, a);
		healthmodroll(droll, t);
	}
	// Prevent negative rolls
	if (aroll < 0) aroll = 0;
	if (droll < 0) droll = 0;
	// Weapon accuracy bonuses and penalties
	bonus += attack_used->accuracy_bonus;
	//USE BULLETS
	int bursthits = 0; // Tracks number of hits.
	int thrownweapons = 0; // Used by thrown weapons to remove the weapons at the end of the turn if needed
	if (!a.is_armed()) //Move into WEAPON_NONE -XML
	{
		// Martial arts multi-strikes
		bursthits = 1 + LCSrandom(a.get_skill(SKILL_HANDTOHAND) / 3 + 1);
		if (bursthits > 5) bursthits = 5;
		if (a.animalgloss) bursthits = 1; // Whoops, must be human to use martial arts fanciness
	}
	else
	{
		if (mode == GAMEMODE_SITE && LCSrandom(100) < attack_used->fire.chance_causes_debris)
		{// TODO - In a car chase, debris should make driving harder for one round, or require a drive skill check to avoid damage
			sitechangest change(locx, locy, locz, SITEBLOCK_DEBRIS);
			location[cursite]->changes.push_back(change);
		}
		if (mode == GAMEMODE_SITE && LCSrandom(100) < attack_used->fire.chance)
		{// TODO - In a car chase, apply vehicle damage, with drive skill check to partially mitigate
		 // Fire!
			if (!(levelmap[locx][locy][locz].flag & SITEBLOCK_FIRE_END) ||
				!(levelmap[locx][locy][locz].flag & SITEBLOCK_FIRE_PEAK) ||
				!(levelmap[locx][locy][locz].flag & SITEBLOCK_FIRE_START) ||
				!(levelmap[locx][locy][locz].flag & SITEBLOCK_DEBRIS))
			{
				levelmap[locx][locy][locz].flag |= SITEBLOCK_FIRE_START;
				sitecrime += 3;
				addjuice(a, 5, 500);
				criminalizeparty(LAWFLAG_ARSON);
				sitestory->crime.push_back(CRIME_ARSON);
			}
		}
		int num_attacks = attack_used->number_attacks;
		
		if (sneak_attack) {
			num_attacks = 1;
			bursthits = 1;
		}
		if (attack_used->thrown)
		{
			thrownweapons = num_attacks;
			if (thrownweapons > a.count_weapons()) {
				thrownweapons = a.count_weapons();
				num_attacks = thrownweapons;
			}
		}else
		if (attack_used->uses_ammo) {
			if (a.get_weapon().get_ammoamount() < num_attacks) {
				num_attacks = a.get_weapon().get_ammoamount();
			}
			a.get_weapon().decrease_ammo(num_attacks);
		}
		if (!sneak_attack) {
			for (int i = 0; i < num_attacks; i++)
			{
				// Each shot in a burst is increasingly less likely to hit
				if (aroll + bonus - i*attack_used->successive_attacks_difficulty > droll)
					bursthits++;
			}
		}
	}
	//HIT!
	if (aroll + bonus > droll)
	{
		if (sneak_attack) strcat(str, " stabs ");
		else strcat(str, " hits ");
		strcat(str, t.name);
		strcat(str, "'s ");
		int w;
		bool canhit = false;
		for (w = 0; w < BODYPARTNUM; w++)
		{
			if (!(t.wound[w] & WOUND_CLEANOFF) && !(t.wound[w] & WOUND_NASTYOFF))
			{
				canhit = true;
				break;
			}
		}
		do
		{
			int offset = 0;
			if (aroll > droll + 5)
				offset = 4;  // NICE SHOT; MORE LIKELY TO HIT BODY/HEAD
			if (aroll > droll + 10 &&
				(!(t.wound[BODYPART_HEAD] & (WOUND_CLEANOFF | WOUND_NASTYOFF)) ||
					!(t.wound[BODYPART_BODY] & (WOUND_CLEANOFF | WOUND_NASTYOFF))))
				offset = 8;  // NO LIMB HITS HERE YOU AWESOME PERSON
			if (sneak_attack)
				offset = 10; // Backstab! 2/3 body, 1/3 head
			if (aroll > droll + 15 &&
				!(t.wound[BODYPART_HEAD] & (WOUND_CLEANOFF | WOUND_NASTYOFF)))
				offset = 12; // BOOM AUTOMATIC HEADSHOT MOTHA******
							 //Weighted location roll:
							 //200% chance to hit body
							 //50% chance to hit head
			w = offset + LCSrandom(13 - offset);
			switch (w)
			{
			case 12:w = BODYPART_HEAD; break;
			case 11:
			case 10:
			case 9:
			case 8:w = BODYPART_BODY; break;
			case 7:
			case 3:w = BODYPART_ARM_RIGHT; break;
			case 6:
			case 2:w = BODYPART_ARM_LEFT; break;
			case 5:
			case 1:w = BODYPART_LEG_RIGHT; break;
			case 4:
			case 0:w = BODYPART_LEG_LEFT; break;
			}
		} while (((t.wound[w] & WOUND_CLEANOFF) || (t.wound[w] & WOUND_NASTYOFF)) && canhit == true);
		strcat(str, bodypartName((Bodyparts)w, (AnimalGlosses)t.animalgloss));
		// show multiple hits
		if (bursthits > 1 && a.is_armed()) // Only show if not melee
		{
			strcat(str, commaSpace);
			if (!a.is_armed()) //Move into WEAPON_NONE? -XML
				strcat(str, "striking");
			else strcat(str, attack_used->hit_description);
			strcat(str, burstHitString(bursthits));
		}
		else if (attack_used->always_describe_hit)
		{
			strcat(str, commaSpace);
			strcat(str, attack_used->hit_description);
		}
		char damtype = 0;
		int damamount = 0;
		char strengthmin = 1;
		char strengthmax = 1;
		int severtype = -1;
		char damagearmor = 0;
		char armorpiercing = 0;
		int extraarmor = 0;
		if (!a.is_armed())
		{
			strengthmin = 5;
			strengthmax = 10;
			while (bursthits) //Put into WEAPON_NONE -XML
			{
				damamount += LCSrandom(5 + a.get_skill(SKILL_HANDTOHAND)) + 1 + a.get_skill(SKILL_HANDTOHAND);
				bursthits--;
			}
			if (!a.animalgloss) damtype |= WOUND_BRUISED;
			else
			{
				if (a.specialattack == ATTACK_CANNON)
				{
					damamount = LCSrandom(5000) + 5000;
					armorpiercing = 20;
					damtype |= WOUND_BURNED;
					damtype |= WOUND_TORN;
					damtype |= WOUND_SHOT;
					damtype |= WOUND_BLEEDING;
					strengthmin = 0;
					strengthmax = 0;
				}
				else if (a.specialattack == ATTACK_FLAME) damtype |= WOUND_BURNED;
				else if (a.specialattack == ATTACK_SUCK) damtype |= WOUND_CUT;
				else damtype |= WOUND_TORN;
				severtype = WOUND_NASTYOFF;
			}
		}
		else
		{
			if (attack_used->bruises) damtype |= WOUND_BRUISED;
			if (attack_used->cuts) damtype |= WOUND_CUT;
			if (attack_used->burns) damtype |= WOUND_BURNED;
			if (attack_used->tears) damtype |= WOUND_TORN;
			if (attack_used->shoots) damtype |= WOUND_SHOT;
			if (attack_used->bleeding) damtype |= WOUND_BLEEDING;
			strengthmin = attack_used->strength_min;
			strengthmax = attack_used->strength_max;
			severtype = attack_used->severtype;
			int random = attack_used->random_damage;
			int fixed = attack_used->fixed_damage;
			if (sneak_attack) fixed += 100;
			if (bursthits >= attack_used->critical.hits_required
				&& LCSrandom(100) < attack_used->critical.chance)
			{
				if (attack_used->critical.random_damage_defined)
					random = attack_used->critical.random_damage;
				if (attack_used->critical.fixed_damage_defined)
					fixed = attack_used->critical.fixed_damage;
				if (attack_used->critical.severtype_defined)
					severtype = attack_used->critical.severtype;
			}
			while (bursthits > 0)
			{
				damamount += LCSrandom(random) + fixed;
				bursthits--;
			}
			damagearmor = attack_used->damages_armor;
			armorpiercing = attack_used->armorpiercing;
		}
		// Coarse combat lethality reduction.
		//damamount/=2;
		if (t.squadid != -1 && t.hireid == -1) // Plot Armor: if the founder is hit, inflict
			damamount /= 2;                // 1/2 damage, because founders are cool
		int mod = 0;
		if (strengthmax > strengthmin)
		{
			// Melee attacks: Maximum strength bonus, minimum
			// strength to deliver full damage
			int strength = a.attribute_roll(ATTRIBUTE_STRENGTH);
			if (strength > strengthmax) strength = (strengthmax + strength) / 2;
			mod += strength - strengthmin;
			armorpiercing += (strength - strengthmin) / 4;
		}
		//SKILL BONUS FOR GOOD ROLL
		mod += aroll - droll;
		//DO THE HEALTH MOD ON THE WOUND
		mod -= t.attribute_roll(ATTRIBUTE_HEALTH);
		//Health and poor accuracy will only avoid critical hits, not stop low-damage attacks
		if (mod < 0) mod = 0;
		// In a car chase, the vehicle itself provides bonus armor
		int vehicleHitLocation = 0;
		if (mode == GAMEMODE_CHASECAR && vehicle != NULL)
		{
			vehicleHitLocation = vehicle->gethitlocation(w);
			extraarmor = vehicle->armorbonus(vehicleHitLocation);
			// TODO damage vehicle itself
		}
		int cardmg = damamount;
		damagemod(t, damtype, damamount, w, armorpiercing, mod, extraarmor);
		// Report vehicle protection effect
		if (mode == GAMEMODE_CHASECAR && vehicle != NULL && extraarmor > 0)
		{
			strcat(str, " through ");
			// Could the vehicle have bounced that round on its own?
			if (damamount == 0)
			{
				Creature testDummy; // Spawn nude test dummy to see if body armor was needed to prevent damage
				damagemod(testDummy, damtype, cardmg, w, armorpiercing, mod, extraarmor);
				if (cardmg < 2) //fudge factor of 1 armor level due to randomness
				{
					strcpy(str, "The attack bounces off ");
				}
			}
			strcat(str, "the " + vehicle->shortname() + "'s ");
			strcat(str, vehicle->getpartname(vehicleHitLocation));
		}
		// Temporary debug output for the damage roll
		if (SHOWMECHANICS)
		{
			char str[200];
			clearmessagearea();
			mvaddstr_f(16, 1, "(ATK %d, DEF %d, DAMMOD %d, DAMAGE %d, AP %d)", aroll, droll, mod, damamount, armorpiercing);
			getkeyAlt();
		}
		// Bullets caught by armor should bruise instead of poke holes.
		if (damamount < 4 && damtype & WOUND_SHOT)
		{
			damtype &= ~(WOUND_SHOT | WOUND_BLEEDING);
			damtype |= WOUND_BRUISED;
		}
		if (damamount > 0)
		{
			Creature *target = 0;
			if (t.squadid != -1 && t.hireid == -1 && //if the founder is hit...
				(damamount > t.blood || damamount >= 10) && //and lethal or potentially crippling damage is done...
				(w == BODYPART_HEAD || w == BODYPART_BODY)) //to a critical bodypart...
			{
				//Oh Noes!!!! Find a liberal to jump in front of the bullet!!!
				for (int i = 0; i < 6; i++)
				{
					if (activesquad->squad[i] == NULL) break;
					if (activesquad->squad[i] == &t) break;
					if (activesquad->squad[i]->get_attribute(ATTRIBUTE_HEART, true)>8 &&
						activesquad->squad[i]->get_attribute(ATTRIBUTE_AGILITY, true) > 4)
					{
						target = activesquad->squad[i];
						clearmessagearea();
						set_color_easy(GREEN_ON_BLACK_BRIGHT);
						mvaddstrAlt(16,  1, target->name, gamelog);
						if (!t.alive) addstrAlt(" misguidedly", gamelog);
						else addstrAlt(" heroically", gamelog);
						addstrAlt(" shields ", gamelog);
						addstrAlt(t.name, gamelog);
						if (!t.alive) addstrAlt("'s corpse", gamelog);
						addstrAlt("!", gamelog);
						gamelog.newline();
						addjuice(*target, 10, 1000);//Instant juice!! Way to take the bullet!!
						getkeyAlt();
						break;
					}
				}
			}
			if (!target) target = &t;//If nobody jumps in front of the attack,
			target->wound[w] |= damtype;
			int severamount = 100;
			switch (w)
			{
			case BODYPART_HEAD:severamount = 100; break;
			case BODYPART_BODY:severamount = 1000; break;
			case BODYPART_ARM_RIGHT:severamount = 200; break;
			case BODYPART_ARM_LEFT:severamount = 200; break;
			case BODYPART_LEG_RIGHT:severamount = 400; break;
			case BODYPART_LEG_LEFT:severamount = 400; break;
			}
			if (severtype != -1 && damamount >= severamount)
				target->wound[w] |= (char)severtype;
			if (w != BODYPART_HEAD && w != BODYPART_BODY && target->blood - damamount <= 0 &&
				target->blood > 0)
			{
				do
				{
					if (LCSrandom(100) < attack_used->no_damage_reduction_for_limbs_chance)
						break;
					else damamount >>= 1;
				} while (target->blood - damamount <= 0);
			}
			if (damagearmor) armordamage(target->get_armor(), w, damamount);
			target->blood -= damamount;
			levelmap[locx][locy][locz].flag |= SITEBLOCK_BLOODY;
			if ((target->wound[BODYPART_HEAD] & WOUND_CLEANOFF) ||
				(target->wound[BODYPART_BODY] & WOUND_CLEANOFF) ||
				(target->wound[BODYPART_HEAD] & WOUND_NASTYOFF) ||
				(target->wound[BODYPART_BODY] & WOUND_NASTYOFF) ||
				target->blood <= 0)
			{
				if ((w == BODYPART_HEAD && target->wound[BODYPART_HEAD] & WOUND_NASTYOFF) ||
					(w == BODYPART_BODY && target->wound[BODYPART_BODY] & WOUND_NASTYOFF))
					bloodblast(&target->get_armor());
				const char alreadydead = !target->alive;
				if (!alreadydead)
				{
					target->die();
					if (t.align == -a.align)
						addjuice(a, 5 + t.juice / 20, 1000); // Instant juice
					else addjuice(a, -(5 + t.juice / 20), -50);
					if (target->squadid != -1)
					{
						if (target->align == 1) stat_dead++;
					}
					else if (target->enemy() && (t.animalgloss != ANIMALGLOSS_ANIMAL || lawList[LAW_ANIMALRESEARCH] == 2))
					{
						stat_kills++;
						if (LocationsPool::getInstance().isThereASiegeHere(cursite)) location[cursite]->siege.kills++;
						if (LocationsPool::getInstance().isThereASiegeHere(cursite) && t.animalgloss == ANIMALGLOSS_TANK) location[cursite]->siege.tanks--;
						if (LocationsPool::getInstance().getRentingType(cursite) == RENTING_CCS)
						{
							if (target->type == CREATURE_CCS_ARCHCONSERVATIVE) ccs_boss_kills++;
							ccs_siege_kills++;
						}
					}
					if (target->squadid == -1 &&
						(target->animalgloss != ANIMALGLOSS_ANIMAL || lawList[LAW_ANIMALRESEARCH] == 2) &&
						!sneak_attack)
					{
						sitecrime += 10;
						sitestory->crime.push_back(CRIME_KILLEDSOMEBODY);
						if (a.squadid != -1) criminalizeparty(LAWFLAG_MURDER);
					}
				}
				string hit_punctuation = attack_used->hit_punctuation;
				if (w == BODYPART_HEAD && target->wound[w] & WOUND_CLEANOFF)
					(hit_punctuation = " CUTTING IT OFF!");
				else if (w == BODYPART_BODY && target->wound[w] & WOUND_CLEANOFF)
					(hit_punctuation = " CUTTING IT IN HALF!");
				else if (w == BODYPART_HEAD && target->wound[w] & WOUND_NASTYOFF)
					(hit_punctuation = " BLOWING IT APART!");
				else if (w == BODYPART_BODY && target->wound[w] & WOUND_NASTYOFF)
					(hit_punctuation = " BLOWING IT IN HALF!");
				strcat(str, hit_punctuation);
				//set_color_easy(WHITE_ON_BLACK_BRIGHT);
				if (goodguyattack) set_color_easy(GREEN_ON_BLACK_BRIGHT);
				else set_color_easy(RED_ON_BLACK_BRIGHT);
				mvaddstrAlt(17, 1, str, gamelog);
				gamelog.newline();
				getkeyAlt();
				if (!alreadydead)
				{
					severloot(t, groundloot);
					clearmessagearea();
					adddeathmessage(*target);
					getkeyAlt();
					if (target->prisoner != NULL) freehostage(t, 1);
				}
			}
			else
			{
				string hit_punctuation = attack_used->hit_punctuation;
				if (target->wound[w] & WOUND_CLEANOFF) (hit_punctuation = " CUTTING IT OFF!");
				else if (target->wound[w] & WOUND_NASTYOFF) (hit_punctuation = " BLOWING IT OFF!");
				strcat(str, hit_punctuation);
				if (target->wound[w] & WOUND_NASTYOFF) bloodblast(&target->get_armor());
				if (goodguyattack) set_color_easy(GREEN_ON_BLACK_BRIGHT);
				else set_color_easy(RED_ON_BLACK_BRIGHT);
				//set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(17, 1, str, gamelog);
				gamelog.newline();
				printparty();
				if (mode == GAMEMODE_CHASECAR ||
					mode == GAMEMODE_CHASEFOOT) printchaseencounter();
				else printencounter();
				getkeyAlt();
				//SPECIAL WOUNDS
				if (!(target->wound[w] & (WOUND_CLEANOFF | WOUND_NASTYOFF)) &&
					!target->animalgloss)
				{
					char heavydam = 0, breakdam = 0, pokedam = 0;
					if (damamount >= 12) //JDS -- 2x damage needed
					{
						if (damtype & WOUND_SHOT || damtype & WOUND_BURNED || damtype & WOUND_TORN || damtype & WOUND_CUT) heavydam = 1;
					}
					if (damamount >= 10) //JDS -- 2x damage needed
					{
						if (damtype & WOUND_SHOT || damtype & WOUND_TORN || damtype & WOUND_CUT) pokedam = 1;
					}
					if ((damtype & WOUND_BRUISED || damtype & WOUND_SHOT || damtype & WOUND_TORN || damtype & WOUND_CUT) && damamount >= 50) {
						breakdam = 1;
					}
					if (w == BODYPART_HEAD)
					{
						string damageDescription = specialWoundPossibilityHead(
							*target,
							breakdam,
							heavydam,
							damtype
							);
						if (len(damageDescription) > 0) {
							clearmessagearea();
							if (goodguyattack) set_color_easy(GREEN_ON_BLACK_BRIGHT);
							else set_color_easy(RED_ON_BLACK_BRIGHT);
							mvaddstrAlt(16,  1, damageDescription, gamelog);
							gamelog.newline();
							getkeyAlt();
						}
					}
					if (w == BODYPART_BODY)
					{
						string damageDescription = specialWoundPossibilityBody(
							*target,
							breakdam,
							pokedam,
							damtype
							);
						if (len(damageDescription) > 0) {
							clearmessagearea();
							//set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
							if (goodguyattack) set_color_easy(GREEN_ON_BLACK_BRIGHT);
							else set_color_easy(RED_ON_BLACK_BRIGHT);
							mvaddstrAlt(16,  1, damageDescription, gamelog);
							gamelog.newline();
							getkeyAlt();
						}
					}
					severloot(*target, groundloot);
				}
				//set_color_easy(WHITE_ON_BLACK_BRIGHT);
			}
		}
		else
		{
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			strcat(str, " to no effect.");
			mvaddstrAlt(17,  1, str, gamelog);
			gamelog.newline();
			printparty();
			if (mode == GAMEMODE_CHASECAR ||
				mode == GAMEMODE_CHASEFOOT) printchaseencounter();
			else printencounter();
			getkeyAlt();
		}
	}
	else
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		if (melee && aroll < droll - 10 && t.blood>70 && t.animalgloss == ANIMALGLOSS_NONE
			&& t.is_armed() && t.get_weapon().get_attack(false, true, true) != NULL)
		{
			strcpy(str, t.name);
			strcat(str, " knocks the blow aside and counters!");
			mvaddstrAlt(17,  1, str, gamelog);
			gamelog.newline();
			getkeyAlt();
			goodguyattack = !goodguyattack;
			bool actual_dummy;
			actual_dummy = attack(t, a, 0, true);
			goodguyattack = !goodguyattack;
		}//TODO if missed person, but vehicle is large, it might damage the car. 
		else
		{
			if (sneak_attack)
			{
				strcpy(str, t.name);
				strcat(str, singleSpace + pickrandom(cry_alarm));
				sitealarm = 1;
			}
			else
			{
				if (mode == GAMEMODE_CHASECAR)
				{
					strcpy(str, driver->name);
					if (droll == 1) {
						strcpy(str, a.name); strcat(str, " missed!");
					}
					else if (droll == 2) {
						strcpy(str, a.name); strcat(str, " just barely missed!");
					}
					else if (droll > 18 || droll < 1) {
						strcpy(str, a.name); strcat(str, " misses completely!");  // You failed to hit someone who probably rolled a zero.  You should feel bad.
					}
					else {
						strcat(str, evasionStringsAlt[droll - 3]);
					}
				}
				else {
					strcpy(str, t.name);
					if (droll == 1) {
						strcpy(str, a.name); strcat(str, " missed!");
					}
					else if (droll == 2) {
						strcpy(str, a.name); strcat(str, " just barely missed!");
					}
					else if (droll > 18 || droll < 1) {
						strcpy(str, a.name); strcat(str, " misses completely!");  // You failed to hit someone who probably rolled a zero.  You should feel bad.
					}
					else {
						strcat(str, evasionStrings[droll - 3]);
					}
				}
			}
			mvaddstrAlt(17,  1, str, gamelog);
			gamelog.newline();
			printparty();
			if (mode == GAMEMODE_CHASECAR ||
				mode == GAMEMODE_CHASEFOOT) printchaseencounter();
			else printencounter();
			getkeyAlt();
		}
	}
	for (; thrownweapons > 0; thrownweapons--)
	{
		if (a.has_thrown_weapon)
			a.ready_another_throwing_weapon();
		a.drop_weapon(NULL);
	}
	// This is the only point in the function where the boolean actual
	// has its value reassigned
	// All other return statements in this function return the value "false"
	actual = true;
	return actual;
}
string specialWoundPossibilityBody(
	Creature &t,
	const char breakdam,
	const char pokedam,
	const char damtype	) 
{
	Creature* target = &t;
	string damageDescription = "";
	switch (LCSrandom(11))
	{
	case 0:
		if (target->special[SPECIALWOUND_UPPERSPINE] && breakdam)
		{
			damageDescription += (target->name);
			if (damtype & WOUND_SHOT) damageDescription += ("'s upper spine is shattered!");
			else (damageDescription += "'s upper spine is broken!");
			target->special[SPECIALWOUND_UPPERSPINE] = 0;
			if (target->blood > 20) target->blood = 20;
		}
		break;
	case 1:
		if (target->special[SPECIALWOUND_LOWERSPINE] && breakdam)
		{
			damageDescription += (target->name);
			if (damtype & WOUND_SHOT)damageDescription += "'s lower spine is shattered!";
			else damageDescription += ("'s lower spine is broken!");
			target->special[SPECIALWOUND_LOWERSPINE] = 0;
			if (target->blood > 20) target->blood = 20;
		}
		break;
	case 2:
		if (target->special[SPECIALWOUND_RIGHTLUNG] && pokedam)
		{
			damageDescription += (target->name);
			if (damtype & WOUND_SHOT)damageDescription += ("'s right lung is blasted!");
			else if (damtype & WOUND_TORN)damageDescription += ("'s right lung is torn!");
			else damageDescription += ("'s right lung is punctured!");
			target->special[SPECIALWOUND_RIGHTLUNG] = 0;
			if (target->blood > 20) target->blood = 20;
		}
		break;
	case 3:
		if (target->special[SPECIALWOUND_LEFTLUNG] && pokedam)
		{
			damageDescription += (target->name);
			if (damtype & WOUND_SHOT)damageDescription += ("'s left lung is blasted!");
			else if (damtype & WOUND_TORN)damageDescription += ("'s left lung is torn!");
			else damageDescription += ("'s left lung is punctured!");
			target->special[SPECIALWOUND_LEFTLUNG] = 0;
			if (target->blood > 20) target->blood = 20;
		}
		break;
	case 4:
		if (target->special[SPECIALWOUND_HEART] && pokedam)
		{
			damageDescription += (target->name);
			if (damtype & WOUND_SHOT)damageDescription += ("'s heart is blasted!");
			else if (damtype & WOUND_TORN)damageDescription += ("'s heart is torn!");
			else damageDescription += ("'s heart is punctured!");
			target->special[SPECIALWOUND_HEART] = 0;
			if (target->blood > 3) target->blood = 3;
		}
		break;
	case 5:
		if (target->special[SPECIALWOUND_LIVER] && pokedam)
		{
			damageDescription += (target->name);
			if (damtype & WOUND_SHOT)damageDescription += ("'s liver is blasted!");
			else if (damtype & WOUND_TORN)damageDescription += ("'s liver is torn!");
			else damageDescription += ("'s liver is punctured!");
			target->special[SPECIALWOUND_LIVER] = 0;
			if (target->blood > 50) target->blood = 50;
		}
		break;
	case 6:
		if (target->special[SPECIALWOUND_STOMACH] && pokedam)
		{
			damageDescription += (target->name);
			if (damtype & WOUND_SHOT)damageDescription += ("'s stomach is blasted!");
			else if (damtype & WOUND_TORN)damageDescription += ("'s stomach is torn!");
			else damageDescription += ("'s stomach is punctured!");
			target->special[SPECIALWOUND_STOMACH] = 0;
			if (target->blood > 50) target->blood = 50;
		}
		break;
	case 7:
		if (target->special[SPECIALWOUND_RIGHTKIDNEY] && pokedam)
		{
			damageDescription += (target->name);
			if (damtype & WOUND_SHOT)damageDescription += ("'s right kidney is blasted!");
			else if (damtype & WOUND_TORN)damageDescription += ("'s right kidney is torn!");
			else damageDescription += ("'s right kidney is punctured!");
			target->special[SPECIALWOUND_RIGHTKIDNEY] = 0;
			if (target->blood > 50) target->blood = 50;
		}
		break;
	case 8:
		if (target->special[SPECIALWOUND_LEFTKIDNEY] && pokedam)
		{
			damageDescription += (target->name);
			if (damtype & WOUND_SHOT)damageDescription += ("'s left kidney is blasted!");
			else if (damtype & WOUND_TORN)damageDescription += ("'s left kidney is torn!");
			else damageDescription += ("'s left kidney is punctured!");
			target->special[SPECIALWOUND_LEFTKIDNEY] = 0;
			if (target->blood > 50) target->blood = 50;
		}
		break;
	case 9:
		if (target->special[SPECIALWOUND_SPLEEN] && pokedam)
		{
			damageDescription += (target->name);
			if (damtype & WOUND_SHOT)damageDescription += ("'s spleen is blasted!");
			else if (damtype & WOUND_TORN)damageDescription += ("'s spleen is torn!");
			else damageDescription += ("'s spleen is punctured!");
			target->special[SPECIALWOUND_SPLEEN] = 0;
			if (target->blood > 50) target->blood = 50;
		}
		break;
	case 10:
		if (target->special[SPECIALWOUND_RIBS] > 0 && breakdam)
		{
			int ribminus = LCSrandom(RIBNUM) + 1;
			if (ribminus > target->special[SPECIALWOUND_RIBS]) ribminus = target->special[SPECIALWOUND_RIBS];
			if (ribminus > 1)
			{
				if (ribminus == target->special[SPECIALWOUND_RIBS])
					damageDescription += ("All ");
				damageDescription += (target->name);
				damageDescription += (" of ");
				damageDescription += (target->name);
				damageDescription += ("'s ribs are ");
			}
			else if (target->special[SPECIALWOUND_RIBS] > 1)
			{
				damageDescription += ("One of ");
				damageDescription += (target->name);
				damageDescription += ("'s rib is ");
			}
			else
			{
				damageDescription += (target->name);
				damageDescription += ("'s last unbroken rib is ");
			}
			if (damtype & WOUND_SHOT)damageDescription += ("shot apart!");
			else damageDescription += ("broken!");
			target->special[SPECIALWOUND_RIBS] -= ribminus;
		}
		break;
	}
	return damageDescription;
}
string specialWoundPossibilityHead(
	Creature &t,
	const char breakdam,
	//char pokedam,
	const char heavydam,
	const char damtype
	) {
	Creature* target = &t;
	string damageDescription = "";
	switch (LCSrandom(7))
	{
	case 0:
		if ((target->special[SPECIALWOUND_RIGHTEYE] ||
			target->special[SPECIALWOUND_LEFTEYE] ||
			target->special[SPECIALWOUND_NOSE]) && heavydam)
		{
			damageDescription += (target->name);
			if (damtype & WOUND_SHOT)damageDescription += ("'s face is blasted off!");
			else if (damtype & WOUND_BURNED)damageDescription += ("'s face is burned away!");
			else if (damtype & WOUND_TORN)damageDescription += ("'s face is torn off!");
			else if (damtype & WOUND_CUT)damageDescription += ("'s face is cut away!");
			else damageDescription += ("'s face is removed!");
			target->special[SPECIALWOUND_RIGHTEYE] = 0;
			target->special[SPECIALWOUND_LEFTEYE] = 0;
			target->special[SPECIALWOUND_NOSE] = 0;
			if (target->blood > 20)target->blood = 20;
		}
		break;
	case 1:
		if (target->special[SPECIALWOUND_TEETH] > 0)
		{
			int teethminus = LCSrandom(TOOTHNUM) + 1;
			if (teethminus > target->special[SPECIALWOUND_TEETH])
				teethminus = target->special[SPECIALWOUND_TEETH];
			if (teethminus > 1)
			{
				if (teethminus == target->special[SPECIALWOUND_TEETH])
					damageDescription += ("All ");
				damageDescription += (teethminus);
				damageDescription += (" of ");
				damageDescription += (target->name);
				damageDescription += ("'s teeth are ");
			}
			else if (target->special[SPECIALWOUND_TEETH] > 1)
			{
				damageDescription += ("One of ");
				damageDescription += (target->name);
				damageDescription += ("'s teeth is ");
			}
			else
			{
				damageDescription += (target->name);
				damageDescription += ("'s last tooth is ");
			}
			if (damtype & WOUND_SHOT)damageDescription += ("shot out!");
			else if (damtype & WOUND_BURNED)damageDescription += ("burned away!");
			else if (damtype & WOUND_TORN)damageDescription += ("gouged out!");
			else if (damtype & WOUND_CUT)damageDescription += ("cut out!");
			else damageDescription += ("knocked out!");
			target->special[SPECIALWOUND_TEETH] -= teethminus;
		}
		break;
	case 2:
		if (target->special[SPECIALWOUND_RIGHTEYE] && heavydam)
		{
			damageDescription += (target->name);
			if (damtype & WOUND_SHOT)damageDescription += ("'s right eye is blasted out!");
			else if (damtype & WOUND_BURNED)damageDescription += ("'s right eye is burned away!");
			else if (damtype & WOUND_TORN)damageDescription += ("'s right eye is torn out!");
			else if (damtype & WOUND_CUT)damageDescription += ("'s right eye is poked out!");
			else damageDescription += ("'s right eye is removed!");
			target->special[SPECIALWOUND_RIGHTEYE] = 0;
			if (target->blood > 50)target->blood = 50;
		}
		break;
	case 3:
		if (target->special[SPECIALWOUND_LEFTEYE] && heavydam)
		{
			damageDescription += (target->name);
			if (damtype & WOUND_SHOT)damageDescription += ("'s left eye is blasted out!");
			else if (damtype & WOUND_BURNED)damageDescription += ("'s left eye is burned away!");
			else if (damtype & WOUND_TORN)damageDescription += ("'s left eye is torn out!");
			else if (damtype & WOUND_CUT)damageDescription += ("'s left eye is poked out!");
			else damageDescription += ("'s left eye is removed!");
			target->special[SPECIALWOUND_LEFTEYE] = 0;
			if (target->blood > 50)target->blood = 50;
		}
		break;
	case 4:
		if (target->special[SPECIALWOUND_TONGUE] && heavydam)
		{
			damageDescription += (target->name);
			if (damtype & WOUND_SHOT)damageDescription += ("'s tongue is blasted off!");
			else if (damtype & WOUND_BURNED)damageDescription += ("'s tongue is burned away!");
			else if (damtype & WOUND_TORN)damageDescription += ("'s tongue is torn out!");
			else if (damtype & WOUND_CUT)damageDescription += ("'s tongue is cut off!");
			else damageDescription += ("'s tongue is removed!");
			target->special[SPECIALWOUND_TONGUE] = 0;
			if (target->blood > 50)target->blood = 50;
		}
		break;
	case 5:
		if (target->special[SPECIALWOUND_NOSE] && heavydam)
		{
			damageDescription += (target->name);
			if (damtype & WOUND_SHOT)damageDescription += ("'s nose is blasted off!");
			else if (damtype & WOUND_BURNED)damageDescription += ("'s nose is burned away!");
			else if (damtype & WOUND_TORN)damageDescription += ("'s nose is torn off!");
			else if (damtype & WOUND_CUT)damageDescription += ("'s nose is cut off!");
			else damageDescription += ("'s nose is removed!");
			target->special[SPECIALWOUND_NOSE] = 0;
			if (target->blood > 50)target->blood = 50;
		}
		break;
	case 6:
		if (target->special[SPECIALWOUND_NECK] && breakdam)
		{
			damageDescription += (target->name);
			if (damtype & WOUND_SHOT)damageDescription += ("'s neck bones are shattered!");
			else damageDescription += ("'s neck is broken!");
			target->special[SPECIALWOUND_NECK] = 0;
			if (target->blood > 20)target->blood = 20;
		}
		break;
	}
	return damageDescription;
}
typedef map<short, string > shortAndString;
 shortAndString tankBodyParts;
 shortAndString animalBodyParts;
 shortAndString humanBodyParts;
std::string bodypartName(Bodyparts w, AnimalGlosses t) {
	if (t == ANIMALGLOSS_TANK) {
		if (tankBodyParts.count(w) > 0)
			return tankBodyParts[w];
	}
	else if (t == ANIMALGLOSS_ANIMAL) {// FIXME: What about Six-legged Pigs?
		if (animalBodyParts.count(w) > 0)
			return animalBodyParts[w];
	}
	else {
		if (humanBodyParts.count(w) > 0)
			return humanBodyParts[w];
	}
	return "NULL BODYPART";
}
/* modifies a combat roll based on the creature's critical injuries */
void healthmodroll(int &aroll, Creature &a)
{
	if (a.special[SPECIALWOUND_RIGHTEYE] != 1) aroll -= LCSrandom(2);
	if (a.special[SPECIALWOUND_LEFTEYE] != 1) aroll -= LCSrandom(2);
	if (a.special[SPECIALWOUND_RIGHTEYE] != 1 &&
		a.special[SPECIALWOUND_LEFTEYE] != 1) aroll -= LCSrandom(20);
	if (a.special[SPECIALWOUND_RIGHTLUNG] != 1) aroll -= LCSrandom(8);
	if (a.special[SPECIALWOUND_LEFTLUNG] != 1) aroll -= LCSrandom(8);
	if (a.special[SPECIALWOUND_HEART] != 1) aroll -= LCSrandom(10);
	if (a.special[SPECIALWOUND_LIVER] != 1) aroll -= LCSrandom(5);
	if (a.special[SPECIALWOUND_STOMACH] != 1) aroll -= LCSrandom(5);
	if (a.special[SPECIALWOUND_RIGHTKIDNEY] != 1) aroll -= LCSrandom(5);
	if (a.special[SPECIALWOUND_LEFTKIDNEY] != 1) aroll -= LCSrandom(5);
	if (a.special[SPECIALWOUND_SPLEEN] != 1) aroll -= LCSrandom(4);
	if (a.special[SPECIALWOUND_LOWERSPINE] != 1) aroll -= LCSrandom(100);
	if (a.special[SPECIALWOUND_UPPERSPINE] != 1) aroll -= LCSrandom(200);
	if (a.special[SPECIALWOUND_NECK] != 1) aroll -= LCSrandom(300);
	if (a.special[SPECIALWOUND_RIBS] < RIBNUM) aroll -= LCSrandom(5);
	if (a.special[SPECIALWOUND_RIBS] < RIBNUM / 2) aroll -= LCSrandom(5);
	if (a.special[SPECIALWOUND_RIBS] == 0) aroll -= LCSrandom(5);
}
/* adjusts attack damage based on armor, other factors */
void damagemod(Creature &t, const char &damtype, int &damamount,
	const char hitlocation, const char armorpenetration, int mod, const int extraarmor)
{
	int armor = t.get_armor().get_armor(hitlocation);
	if (t.animalgloss == ANIMALGLOSS_TANK)
	{
		if (damtype != WOUND_BURNED) armor = 15;
		else armor = 10;
	}
	//if(t.get_armor().get_quality()>1)
	armor -= t.get_armor().get_quality() - 1;
	if (t.get_armor().is_damaged())
		armor -= 1;
	if (armor < 0) armor = 0; // Possible from second-rate clothes
	armor += extraarmor; // Add vehicle armor 
	const int mod2 = armor + LCSrandom(armor + 1) - armorpenetration;
	if (mod2 > 0) mod -= mod2 * 2;
	if (mod > 10) mod = 10; // Cap damage multiplier (every 5 points adds 1x damage)
	if (mod <= -20) damamount >>= 8;  //Cars plus heavy armor can be really tough.
	else if (mod <= -14) damamount >>= 7;
	else if (mod <= -8) damamount >>= 6;
	else if (mod <= -6) damamount >>= 5;
	else if (mod <= -4) damamount >>= 4;
	else if (mod <= -3) damamount >>= 3;
	else if (mod <= -2) damamount >>= 2;
	else if (mod <= -1) damamount >>= 1;
	else if (mod >= 0) damamount = (int)((float)damamount * (1.0f + 0.2f*mod));
	// Firefighter's bunker gear reduces fire damage by 3/4
	if ((damtype & WOUND_BURNED) && t.get_armor().has_fireprotection())
	{
		// Damaged gear isn't as effective as undamaged gear
		if (t.get_armor().is_damaged())
			damamount >>= 1; // Only half as much damage reduction
		else
			damamount >>= 2; // Full damage reduction
	}
	if (damamount < 0)damamount = 0;
}
using std::string;
void specialattack(Creature &a, Creature &t)
{
	int resist = 0;
	char str[200];
	clearmessagearea();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	strcpy(str, a.name);
	strcat(str, singleSpace);
	int attack = 0;
	if (a.align != 1)
		attack = a.attribute_roll(ATTRIBUTE_WISDOM) + t.get_attribute(ATTRIBUTE_WISDOM, false);
	else if (a.align == 1)
		attack = a.attribute_roll(ATTRIBUTE_HEART) + t.get_attribute(ATTRIBUTE_HEART, false);
	switch (a.type)
	{
	case CREATURE_JUDGE_CONSERVATIVE:
	case CREATURE_JUDGE_LIBERAL:
		strcat(str, pickrandom(judge_debate));
		strcat(str, singleSpace);
		strcat(str, t.name);
		strcat(str, "!");
		if (t.align == 1)
			resist = t.skill_roll(SKILL_LAW) +
			t.attribute_roll(ATTRIBUTE_HEART);
		else
			resist = t.skill_roll(SKILL_LAW) +
			t.attribute_roll(ATTRIBUTE_WISDOM);
		attack += a.skill_roll(SKILL_LAW);
		break;
	case CREATURE_SCIENTIST_EMINENT:
		switch (LCSrandom(scientist_debate.size() + 1))
		{
		case 0:if (a.align == ALIGN_CONSERVATIVE)strcat(str, "explains the benefits of research to");
			   else strcat(str, "explains ethical research to"); break;
		default:
			strcat(str, pickrandom(scientist_debate)); break;
		}
		strcat(str, singleSpace);
		strcat(str, t.name);
		strcat(str, "!");
		if (t.align == 1)
			resist = t.skill_roll(SKILL_SCIENCE) +
			t.attribute_roll(ATTRIBUTE_HEART);
		else
			resist = t.skill_roll(SKILL_SCIENCE) +
			t.attribute_roll(ATTRIBUTE_WISDOM);
		attack += a.skill_roll(SKILL_SCIENCE);
		break;
	case CREATURE_POLITICIAN:
		if (a.align == -1)
			strcat(str, pickrandom(conservative_politician_debate));
		else
			strcat(str, pickrandom(other_politician_debate));
		strcat(str, singleSpace);
		strcat(str, t.name);
		strcat(str, "!");
		if (t.align == 1)
			resist = t.skill_roll(SKILL_LAW) +
			t.attribute_roll(ATTRIBUTE_HEART);
		else
			resist = t.skill_roll(SKILL_LAW) +
			t.attribute_roll(ATTRIBUTE_WISDOM);
		attack += a.skill_roll(SKILL_LAW);
		break;
	case CREATURE_CORPORATE_CEO:
		if (a.align == -1)
			strcat(str, pickrandom(conservative_ceo_debate));
		else
			strcat(str, pickrandom(other_ceo_debate));
		strcat(str, singleSpace);
		strcat(str, t.name);
		strcat(str, "!");
		if (t.align == 1)
			resist = t.skill_roll(SKILL_BUSINESS) +
			t.attribute_roll(ATTRIBUTE_HEART);
		else
			resist = t.skill_roll(SKILL_BUSINESS) +
			t.attribute_roll(ATTRIBUTE_WISDOM);
		attack += a.skill_roll(SKILL_BUSINESS);
		break;
	case CREATURE_RADIOPERSONALITY:
	case CREATURE_NEWSANCHOR:
		strcat(str, pickrandom(media_debate));
		strcat(str, singleSpace);
		strcat(str, t.name);
		strcat(str, "!");
		if (t.align == 1)
			resist = t.attribute_roll(ATTRIBUTE_HEART);
		else
			resist = t.attribute_roll(ATTRIBUTE_WISDOM);
		attack += a.attribute_roll(ATTRIBUTE_CHARISMA);
		break;
	case CREATURE_MILITARYOFFICER:
		strcat(str, pickrandom(military_debate));
		strcat(str, singleSpace);
		strcat(str, t.name);
		strcat(str, "!");
		if (t.align == 1)
			resist = t.attribute_roll(ATTRIBUTE_HEART);
		else
			resist = t.attribute_roll(ATTRIBUTE_WISDOM);
		attack += a.attribute_roll(ATTRIBUTE_CHARISMA);
		break;
	case CREATURE_COP:
		if (a.enemy())
		{
			strcat(str, pickrandom(police_debate));
			strcat(str, singleSpace);
			strcat(str, t.name);
			strcat(str, "!");
			resist = t.attribute_roll(ATTRIBUTE_HEART);
			attack += a.skill_roll(SKILL_PERSUASION);
			break;
		}
		//No break. If the cop is a liberal it will do a musical attack instead.
	default:
		if (a.get_weapon().has_musical_attack() || a.type == CREATURE_COP)
		{
			switch (LCSrandom(5))
			{
				//TODO IsaacG Migrate Strings
			case 0:strcat(str, "plays a song for"); break;
			case 1:strcat(str, "sings to"); break;
			case 2:if (a.get_weapon().has_musical_attack())
			{
				strcat(str, "strums the ");
				strcat(str, a.get_weapon().get_name());
			}
				   else // let's use a small enough instrument for anyone to carry in their pocket
					   strcat(str, "blows a harmonica");
				strcat(str, " at"); break;
			case 3:if (a.align == 1)strcat(str, "plays protest songs at");
				   else strcat(str, "plays country songs at");
				   break;
			case 4:strcat(str, "rocks out at"); break;
			}
			strcat(str, singleSpace);
			strcat(str, t.name);
			strcat(str, "!");
			attack = a.skill_roll(SKILL_MUSIC);
			if (t.align == 1)
				resist = t.attribute_roll(ATTRIBUTE_HEART);
			else resist = t.attribute_roll(ATTRIBUTE_WISDOM);
			if (resist > 0)
				a.train(SKILL_MUSIC, LCSrandom(resist) + 1);
			else a.train(SKILL_MUSIC, 1);
		}
		break;
	}
	mvaddstrAlt(16,  1, str, gamelog);
	gamelog.newline();
	if ((t.animalgloss == ANIMALGLOSS_TANK || (t.animalgloss == ANIMALGLOSS_ANIMAL&&lawList[LAW_ANIMALRESEARCH] != 2))
		|| (a.enemy() && t.flag & CREATUREFLAG_BRAINWASHED))
	{
		mvaddstrAlt(17,  1, t.name + (string) " is immune to the attack!", gamelog);
	}
	else if (a.align == t.align)
	{
		mvaddstrAlt(17,  1, t.name + (string)  " already agrees with " + a.name + singleDot);
	}
	else if (attack > resist)
	{
		t.stunned += (attack - resist) / 4;
		if (a.enemy())
		{
			if (t.juice > 100)
			{
				mvaddstrAlt(17,  1, t.name + (string)  " loses juice!", gamelog);
				addjuice(t, -50, 100);
			}
			else if (LCSrandom(15) > t.get_attribute(ATTRIBUTE_WISDOM, true) || t.get_attribute(ATTRIBUTE_WISDOM, true) < t.get_attribute(ATTRIBUTE_HEART, true))
			{
				mvaddstrAlt(17,  1, t.name + (string) " is tainted with Wisdom!", gamelog);
				t.adjust_attribute(ATTRIBUTE_WISDOM, +1);
			}
			else if (t.align == ALIGN_LIBERAL && t.flag & CREATUREFLAG_LOVESLAVE)
			{
				mvaddstrAlt(17,  1, t.name + (string)  " can't bear to leave!", gamelog);
			}
			else
			{
				if (a.align == -1)
				{
					mvaddstrAlt(17,  1, t.name + (string)  " is turned Conservative", gamelog);
					t.stunned = 0;
					if (t.prisoner != NULL)
						freehostage(t, 0);
					addstrAlt("!", gamelog);
				}
				else
				{
					mvaddstrAlt(17,  1, t.name + (string) " doesn't want to fight anymore", gamelog);
					t.stunned = 0;
					if (t.prisoner != NULL)
						freehostage(t, 0);
					addstrAlt("!", gamelog);
				}
				for (int e = 0; e < ENCMAX; e++)
				{
					if (encounter[e].exists == 0)
					{
						encounter[e] = t;
						encounter[e].exists = 1;
						if (a.align == -1)conservatise(encounter[e]);
						encounter[e].cantbluff = 2;
						encounter[e].squadid = -1;
						break;
					}
				}
				bool flipstart = 0;
				for (int p = 0; p < 6; p++)
				{
					if (activesquad->squad[p] == &t)
					{
						activesquad->squad[p]->die();
						activesquad->squad[p]->location = -1;
						activesquad->squad[p] = NULL;
						flipstart = 1;
					}
					if (flipstart&&p < 5) activesquad->squad[p] = activesquad->squad[p + 1];
				}
				if (flipstart) activesquad->squad[5] = NULL;
			}
		}
		else
		{
			if (t.juice >= 100)
			{
				mvaddstrAlt(17,  1, t.name + (string)  " seems less badass!", gamelog);
				addjuice(t, -50, 99);
			}
			else if (!t.attribute_check(ATTRIBUTE_HEART, DIFFICULTY_AVERAGE) ||
				t.get_attribute(ATTRIBUTE_HEART, true) < t.get_attribute(ATTRIBUTE_WISDOM, true))
			{
				mvaddstrAlt(17,  1, t.name + (string) "'s Heart swells!", gamelog);
				t.adjust_attribute(ATTRIBUTE_HEART, +1);
			}
			else
			{
				mvaddstrAlt(17,  1, t.name + (string) " has turned Liberal!", gamelog);
				t.stunned = 0;
				liberalize(t);
				t.infiltration /= 2;
				t.flag |= CREATUREFLAG_CONVERTED;
				t.cantbluff = 0;
			}
		}
	}
	else
	{
		mvaddstrAlt(17,  1, t.name + (string)  " remains strong.", gamelog);
	}
	gamelog.newline();
	printparty();
	if (mode == GAMEMODE_CHASECAR ||
		mode == GAMEMODE_CHASEFOOT) printchaseencounter();
	else printencounter();
	getkeyAlt();
	return;
}
/* destroys armor, masks, drops weapons based on severe damage */
void severloot(Creature &cr, vector<Item *> &loot)
{
	int armok = 2;
	if ((cr.wound[BODYPART_ARM_RIGHT] & WOUND_NASTYOFF) ||
		(cr.wound[BODYPART_ARM_RIGHT] & WOUND_CLEANOFF)) armok--;
	if ((cr.wound[BODYPART_ARM_LEFT] & WOUND_NASTYOFF) ||
		(cr.wound[BODYPART_ARM_LEFT] & WOUND_CLEANOFF)) armok--;
	if (cr.special[SPECIALWOUND_NECK] != 1) armok = 0;
	if (cr.special[SPECIALWOUND_UPPERSPINE] != 1) armok = 0;
	if (cr.is_armed() && armok == 0)
	{
		clearmessagearea();
		set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, "The ", gamelog);
		addstrAlt(cr.get_weapon().get_name(1), gamelog);
		addstrAlt(" slips from", gamelog);
		mvaddstrAlt(17,  1, cr.name, gamelog);
		addstrAlt("'s grasp.", gamelog);
		gamelog.newline();
		getkeyAlt();
		if (mode == GAMEMODE_SITE) cr.drop_weapons_and_clips(&loot);
		else cr.drop_weapons_and_clips(NULL);
	}
	if ((((cr.wound[BODYPART_BODY] & WOUND_CLEANOFF) ||
		(cr.wound[BODYPART_BODY] & WOUND_NASTYOFF)) &&
		cr.get_armor().covers(BODYPART_BODY)) ||
		((cr.wound[BODYPART_HEAD] & WOUND_NASTYOFF) &&
			cr.get_armor().is_mask()))
	{
		clearmessagearea();
		set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		mvaddstrAlt(16,  1, cr.name, gamelog);
		addstrAlt("'s ", gamelog);
		addstrAlt(cr.get_armor().get_name(), gamelog);
		addstrAlt(" has been destroyed.", gamelog);
		gamelog.newline();
		getkeyAlt();
		cr.strip(NULL);
	}
}
/* damages the selected armor if it covers the body part specified */
void armordamage(Armor &armor, const int bp, const int damamount)
{
	if (armor.covers(bp) && LCSrandom(armor.get_durability()) < damamount)
	{
		if (armor.is_damaged())
		{
			armor.decrease_quality(LCSrandom(armor.get_durability()) < LCSrandom(damamount) / armor.get_quality() ? 1 : 0);
		}
		else
		{
			armor.set_damaged(true);
		}
	}
}
/* blood explosions */
void bloodblast(Armor* armor)
{
	//GENERAL
	if (armor != NULL)
		armor->set_bloody(true);
	if (mode != GAMEMODE_SITE)
		return;
	levelmap[locx][locy][locz].flag |= SITEBLOCK_BLOODY2;
	//HIT EVERYTHING
	for (int p = 0; p < 6; p++)
	{
		if (activesquad->squad[p] == NULL) continue;
		if (!LCSrandom(2))
			activesquad->squad[p]->get_armor().set_bloody(true);
	}
	for (int e = 0; e < ENCMAX; e++)
	{
		if (!encounter[e].exists) continue;
		if (!LCSrandom(2))
			encounter[e].get_armor().set_bloody(true);
	}
	//REFRESH THE SCREEN
	printsitemap(locx, locy, locz);
	refreshAlt();
}
// TODO convert this to Linked List?
/* kills the specified creature from the encounter, dropping loot */
void delenc(const short e, const char loot)
{
	//MAKE GROUND LOOT
	if ((mode == GAMEMODE_SITE) && loot) makeloot(encounter[e], groundloot);
	//BURY IT
	for (int en = e; en < ENCMAX; en++)
	{
		if (!encounter[en].exists) break;
		if (en < ENCMAX - 1) encounter[en] = encounter[en + 1];
	}
	encounter[ENCMAX - 1].exists = 0;
}
/* generates the loot dropped by a creature when it dies */
void makeloot(Creature &cr, vector<Item *> &loot)
{
	cr.drop_weapons_and_clips(&loot);
	cr.strip(&loot);
	if (cr.money>0 && mode == GAMEMODE_SITE)
	{
		loot.push_back(new Money(cr.money));
		cr.money = 0;
	}
}
/* abandoned liberal is captured by conservatives */
void capturecreature(Creature &t)
{
	t.activity.type = ACTIVITY_NONE;
	t.drop_weapons_and_clips(NULL);
	//t.strip(NULL);
	Armor clothes = Armor(*armortype[getarmortype(tag_ARMOR_CLOTHES)]);
	t.give_armor(clothes, NULL);
	freehostage(t, 2); // situation 2 = no message; this may want to be changed to 0 or 1
	if (t.prisoner)
	{
		if (t.prisoner->squadid == -1)
			delete t.prisoner;
		t.prisoner = NULL; // Stop hauling people
	}
	if (t.flag & CREATUREFLAG_JUSTESCAPED)
	{
		t.location = cursite;
		if (sitetype == SITE_GOVERNMENT_PRISON ||
			sitetype == SITE_GOVERNMENT_COURTHOUSE)
		{
			Armor prisoner = Armor(*armortype[getarmortype(tag_ARMOR_PRISONER)]);
			t.give_armor(prisoner, NULL);
		}
		if (sitetype == SITE_GOVERNMENT_PRISON)
		{
			// Clear criminal record?
			t.heat = 0;
			for (int i = 0; i < LAWFLAGNUM; i++)
				t.crimes_suspected[i] = 0;
		}
	}
	else
		t.location = find_site_index_in_same_city(SITE_GOVERNMENT_POLICESTATION, cursite);
	t.squadid = -1;
}
/* checks if the creature can fight and prints flavor text if they can't */
char incapacitated(Creature &a, const char noncombat, char &printed)
{
	printed = 0;
	switch (a.animalgloss) {
	case ANIMALGLOSS_TANK:
	{
		if (a.blood <= 20 || (a.blood <= 50 && (LCSrandom(2) || a.forceinc)))
		{
			a.forceinc = 0;
			if (noncombat)
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, "The ", gamelog);
				addstrAlt(a.name, gamelog);
				addstrAlt(singleSpace + pickrandom(paralyzed_tank));
				gamelog.newline();
				printed = 1;
			}
			return 1;
		}
		return 0;
	}
	case ANIMALGLOSS_ANIMAL:
	{
		if (a.blood <= 20 || (a.blood <= 50 && (LCSrandom(2) || a.forceinc)))
		{
			a.forceinc = 0;
			if (noncombat)
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, "The ", gamelog);
				addstrAlt(a.name);
				switch (LCSrandom(3))
				{
				case 0: if (lawList[LAW_FREESPEECH] == -2) addstrAlt(" [makes a stinky].", gamelog);
						else addstrAlt(" soils the floor.", gamelog); break;
				default:
					addstrAlt(singleSpace + pickrandom(bleeding_animal), gamelog); break;
				}
				gamelog.newline();
				printed = 1;
			}
			return 1;
		}
		return 0;
	}
	default:
		if (a.blood <= 20 || (a.blood <= 50 && (LCSrandom(2) || a.forceinc)))
		{
			a.forceinc = 0;
			if (noncombat)
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, a.name);
				switch (LCSrandom(54))
				{
					//TODO IsaacG Complete Migration of Strings
				case 0: if (lawList[LAW_FREESPEECH] == -2) addstrAlt(" [makes a stinky].");
						else addstrAlt(" soils the floor."); break;
				case 1: if (mode != GAMEMODE_CHASECAR) addstrAlt(" stumbles against a wall.");
						else addstrAlt(" leans against the door."); break;
				case 2: if (a.special[SPECIALWOUND_RIGHTEYE] && a.special[SPECIALWOUND_LEFTEYE])
					addstrAlt(" stares off into space.");
						else if (a.special[SPECIALWOUND_RIGHTEYE] || a.special[SPECIALWOUND_LEFTEYE])
							addstrAlt(" stares into space with one empty eye.");
						else addstrAlt(" stares out with hollow sockets."); break;
				case 3: if (lawList[LAW_FREESPEECH] == -2) addstrAlt(" [makes a mess], moaning.");
						else addstrAlt(" pisses on the floor, moaning."); break;
				case 4: if (a.special[SPECIALWOUND_TEETH] > 1) addstrAlt("'s teeth start chattering.");
						else if (a.special[SPECIALWOUND_TEETH] == 1) addstrAlt("'s tooth starts chattering.");
						else addstrAlt("'s gums start chattering."); break;
				case 5: if (a.age < 20 && !a.animalgloss) addstrAlt(" cries \"Mommy!\"");
						else switch (a.type) {
						case CREATURE_GENETIC:
							addstrAlt(" murmurs \"What about my offspring?\""); break;
						case CREATURE_GUARDDOG:
							addstrAlt(" murmurs \"What about my puppies?\""); break;
						default:
							addstrAlt(" murmurs \"What about my children?\""); break;
						} break;
				case 6: if (lawList[LAW_FREESPEECH] == -2)addstrAlt(" [makes a mess].");
						else addstrAlt(" vomits up a clot of blood."); break;
				case 7: if (lawList[LAW_FREESPEECH] == -2)addstrAlt(" [makes a mess].");
						else addstrAlt(" spits up a cluster of bloody bubbles."); break;
				default: addstrAlt(pickrandom(bleeding_to_death));
				}
				printed = 1;
			}
			return 1;
		}
		if (a.stunned)
		{
			if (noncombat)
			{
				a.stunned--;
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, a.name, gamelog);
				addstrAlt(singleSpace + pickrandom(stunned_text));
				gamelog.newline();
				printed = 1;
			}
			return 1;
		}
		if (a.special[SPECIALWOUND_NECK] == 2 || a.special[SPECIALWOUND_UPPERSPINE] == 2)
		{
			if (!noncombat)
			{
				clearmessagearea();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(16,  1, a.name, gamelog);
				addstrAlt(singleSpace + pickrandom(paralyzed_text));
				gamelog.newline();
				printed = 1;
			}
			return 1;
		}
		return 0;
	}
}
/* describes a character's death */
void adddeathmessage(Creature &cr)
{
	set_color_easy(YELLOW_ON_BLACK_BRIGHT);
	char str[200];
	char secondLine[200];
	bool hasSecondLine = false;
	strcpy(str, cr.name);
	if ((cr.wound[BODYPART_HEAD] & WOUND_CLEANOFF) ||
		(cr.wound[BODYPART_HEAD] & WOUND_NASTYOFF))
	{
		hasSecondLine = true;
		switch (LCSrandom(4))
		{
			//TODO IsaacG Complete Migration of Strings
		case 0:
			strcat(str, " reaches once where there ");
			if (mode != GAMEMODE_CHASECAR)
				strcpy(secondLine, "is no head, and falls.");
			else strcpy(secondLine, "is no head, and slumps over.");
			break;
		case 1:
			if (mode != GAMEMODE_CHASECAR)
				strcat(str, " stands headless for a ");
			else strcat(str, " sits headless for a ");
			strcpy(secondLine, "moment then crumples over.");
			break;
		case 2:
			strcat(str, " squirts ");
			if (lawList[LAW_FREESPEECH] == -2)strcat(str, "[red water]");
			else strcat(str, "blood");
			strcat(str, " out of the ");
			if (mode != GAMEMODE_CHASECAR)
				strcpy(secondLine, "neck and runs down the hall.");
			else strcpy(secondLine, "neck and falls to the side.");
			break;
		case 3:
			strcat(str, " sucks a last breath through ");
			strcpy(secondLine, "the neck hole, then is quiet.");
			break;
		}
	}
	else if ((cr.wound[BODYPART_BODY] & WOUND_CLEANOFF) ||
		(cr.wound[BODYPART_BODY] & WOUND_NASTYOFF))
	{
		strcat(str, singleSpace + pickrandom(body_falls_apart));
	}
	else
	{
		hasSecondLine = true;
		switch (LCSrandom(11))
		{
		case 0:
			strcat(str, " sweats profusely, murmurs ");
			if (lawList[LAW_FREESPEECH] == -2)strcpy(secondLine, "something [good] about Jesus, and dies.");
			else strcpy(secondLine, "something about Jesus, and dies.");
			break;
		case 1:
			strcat(str, " gasps a last breath and ");
			if (lawList[LAW_FREESPEECH] == -2) strcpy(secondLine, "[makes a mess].");
			else strcpy(secondLine, "soils the floor.");
			break;
		case 2:
			strcat(str, " speaks these final words: ");
			switch (cr.align)
			{
			case ALIGN_LIBERAL:
			case ALIGN_ELITELIBERAL:
				strcpy(secondLine, slogan); break;
			case ALIGN_MODERATE:
				strcpy(secondLine, "\"A plague on both your houses...\""); break;
			default:
				strcpy(secondLine, "\"Better dead than liberal...\""); break;
			}
			break;
		default:
			vector<string> death = pickrandom(double_line_death);
			strcat(str, singleSpace + death[0]);
			strcpy(secondLine, death[1]);
			break;
		}
	}
	mvaddstrAlt(16, 1, str, gamelog);
	if (hasSecondLine) {
		mvaddstrAlt(17,  1, secondLine, gamelog);
	}
	gamelog.newline();
}
/* pushes people into the current squad (used in a siege) */
void autopromote(const int loc)
{
	if (!activesquad) return;
	const int partysize = squadsize(activesquad), partyalive = squadalive(activesquad);
	int libnum = 0;
	if (partyalive == 6) return;
	for (int pl = 0; pl < CreaturePool::getInstance().lenpool(); pl++)
	{
		if (pool[pl]->location != loc) continue;
		if (pool[pl]->alive&&pool[pl]->align == 1) libnum++;
	}
	if (partysize == libnum) return;
	char conf;
	for (int p = 0; p < 6; p++)
	{
		conf = 0;
		if (activesquad->squad[p] == NULL) conf = 1;
		else if (!activesquad->squad[p]->alive) conf = 1;
		if (conf)
		{
			for (int pl = 0; pl < CreaturePool::getInstance().lenpool(); pl++)
			{
				if (pool[pl]->location != loc) continue;
				if (pool[pl]->alive&&pool[pl]->squadid == -1 &&
					pool[pl]->align == 1)
				{
					if (activesquad->squad[p] != NULL) activesquad->squad[p]->squadid = -1;
					activesquad->squad[p] = pool[pl];
					activesquad->squad[p]->squadid = activesquad->id;
					break;
				}
			}
		}
	}
}
