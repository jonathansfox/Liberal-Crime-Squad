#include <includes.h>
#include "creature/creature.h"
#include "common/creaturePool.h"
#include "common/creaturePoolCreature.h"

vector<Creature *> pool;
CreaturePool singletonPool;
void addCreature(Creature* cr)
{
	pool.push_back(cr);
}
void CreaturePool::moveEverythingFrom(int cursite, int hs)
{
	for (int p = 0; p < lenpool(); p++)
	{
		if (pool[p]->location == cursite)pool[p]->location = hs;
		if (pool[p]->base == cursite)pool[p]->base = hs;
	}
}
void CreaturePool::stop_riding_me(int id_)
{

	for (int p = 0; p<lenpool(); p++)
		if (pool[p]->carid == id_)
			pool[p]->carid = -1;
}
void CreaturePool::stopAllBleeding()
{

	for (int p = 0; p < lenpool(); p++)
		for (int w = 0; w < BODYPARTNUM; w++)
			pool[p]->wound[w] &= ~WOUND_BLEEDING;
}
bool CreaturePool::doesAnyoneLiveHere(int loc)
{

	for (int p = 0; p < lenpool(); p++) {
		if (pool[p]->base == loc) {
			return true;
		}
	}
	return false;
}
void CreaturePool::stop_preferring_me(int id_)
{

	for (int p = 0; p<lenpool(); p++)
		if (pool[p]->pref_carid == id_)
			pool[p]->pref_carid = -1;
}
void CreaturePool::clearAllBleedingAndEscapeFlags()
{

	for (int p = 0; p < lenpool(); p++)
	{

		pool[p]->flag &= ~CREATUREFLAG_JUSTESCAPED;
		for (int w = 0; w < BODYPARTNUM; w++)
		{

			pool[p]->wound[w] &= ~WOUND_BLEEDING;
		}
	}
}
extern string string_sleeper;
#include "cursesAlternative.h"
#include "log/log.h"
extern Log gamelog;
#include "common/consolesupport.h"
void CreaturePool::outSleepers(int cursite, int base)
{
	for (int p = 0; p < lenpool(); p++)
	{

		if (pool[p]->flag&CREATUREFLAG_SLEEPER &&
			pool[p]->location == cursite)
		{

			pool[p]->flag &= ~CREATUREFLAG_SLEEPER;
			eraseAlt();
			mvaddstrAlt(8, 1, string_sleeper, gamelog);



			addstrAlt(pool[p]->name, gamelog);
			addstrAlt(" has been outed by your bold attack!", gamelog);
			gamelog.newline();
			mvaddstrAlt(10, 1, "The Liberal is now at your command as a normal squad member.", gamelog);
			gamelog.newline();
			pool[p]->base = base;
			pool[p]->location = pool[p]->base;
			getkeyAlt();
		}
	}
}
#include "sitemode/advance.h"
void CreaturePool::advanceCreaturesAtLocation(int cursite)
{

	for (int p = 0; p < lenpool(); p++)
	{
		if (!pool[p]->alive) continue;
		if (pool[p]->squadid != -1) continue;
		if (pool[p]->location != cursite) continue;
		advancecreature(*pool[p]);
	}
}
#include "common/commonactionsCreature.h"
#include "combat/fightCreature.h"
void CreaturePool::arrestOrKillCCSSleepers()
{

	for (int p = 0; p < lenpool(); p++)
	{
		if (pool[p]->flag&CREATUREFLAG_SLEEPER)
		{
			if (pool[p]->type == CREATURE_CCS_VIGILANTE || pool[p]->type == CREATURE_CCS_ARCHCONSERVATIVE ||
				pool[p]->type == CREATURE_CCS_MOLOTOV || pool[p]->type == CREATURE_CCS_SNIPER)
			{
				pool[p]->flag &= ~CREATUREFLAG_SLEEPER;
				criminalize(*pool[p], LAWFLAG_RACKETEERING);
				capturecreature(*pool[p]);
			}
		}
	}
}
#include "locations/locationsPool.h"
int CreaturePool::liberal_guardian_writing_power()
{
	int power = 0;
	for (int i = 0; i < lenpool(); i++)
	{
		if (pool[i]->alive&&pool[i]->activity.type == ACTIVITY_WRITE_GUARDIAN)
		{
			if (pool[i]->location != -1 &&
				LocationsPool::getInstance().getCompoundWalls(pool[i]->location) & COMPOUND_PRINTINGPRESS)
			{
				pool[i]->train(SKILL_WRITING, LCSrandom(3)); // Experience gain
				power += pool[i]->skill_roll(SKILL_WRITING); // Record the writer on this topic
				criminalize(*pool[i], LAWFLAG_SPEECH); // Record possibly illegal speech activity
			}
			else pool[i]->activity.type = ACTIVITY_NONE;
		}
	}
	return power;
}
int CreaturePool::howManyLivingPeopleAreHere(int l)
{
	int numpres = 0;
	for (int p = 0; p < lenpool(); p++)
	{
		if (pool[p]->location != l) continue; // People not at this base don't count
		if (!pool[p]->alive) continue; // Dead people don't count
		numpres++;
	}
	return numpres;
}
int CreaturePool::countLiberals(int cursite)
{
	int libnum = 0;
	for (int p = 0; p < lenpool(); p++) {
		if (pool[p]->align == 1 &&
			pool[p]->alive&&
			pool[p]->location == cursite&&
			!(pool[p]->flag&CREATUREFLAG_SLEEPER)) {
			libnum++;
		}
	}
	return libnum;
}
bool CreaturePool::creaturePoolInitiated = false;
CreaturePool CreaturePool::getInstance() {
	if (!creaturePoolInitiated) {
		creaturePoolInitiated = true;
		singletonPool = CreaturePool();
	}
	return singletonPool;
}
void CreaturePool::delete_and_clear_pool() {
	delete_and_clear(pool);
}
void CreaturePool::setupDisband()
{

	for (int p = lenpool() - 1; p >= 0; p--)
	{
		if (!pool[p]->alive || pool[p]->flag&CREATUREFLAG_KIDNAPPED || pool[p]->flag&CREATUREFLAG_MISSING) delete_and_remove(pool, p);
		else if (!(pool[p]->flag&CREATUREFLAG_SLEEPER))
		{
			removesquadinfo(*pool[p]);
			pool[p]->hiding = -1;
		}
	}
}
bool CreaturePool::isThisCarWantedByAnotherSquad(long vehicleID, int squadID)
{

	for (int p = 0; p < lenpool(); p++)
	{
		if (pool[p]->squadid != -1 && pool[p]->alive&&
			pool[p]->pref_carid == vehicleID && pool[p]->squadid != squadID)
		{
			return true;
		}
	}
	return false;
}
string CreaturePool::getName(int p)
{
	return pool[p]->name;
}
void CreaturePool::moveAllSquadMembers(int l)
{
	int hs = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, l);
	//MOVE ALL ITEMS AND SQUAD MEMBERS
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (pool[p]->location == l) pool[p]->location = hs;
		if (pool[p]->base == l) pool[p]->base = hs;
	}
}
int CreaturePool::lenpool() {
	return len(pool);
}
void whoAreWaitingForRescue(vector<Creature *>& waiting_for_rescue, int cursite, short special) {
	for (int pl = 0; pl < len(pool); pl++)
	{
		if (pool[pl]->location == cursite&&
			!(pool[pl]->flag & CREATUREFLAG_SLEEPER) &&
			!(special == SPECIAL_PRISON_CONTROL_LOW&&!(pool[pl]->sentence>0 && !pool[pl]->deathpenalty)) && //Low is for normal time-limited sentences.
			!(special == SPECIAL_PRISON_CONTROL_MEDIUM&&!(pool[pl]->sentence < 0 && !pool[pl]->deathpenalty)) && //Medium is for life sentences.
			!(special == SPECIAL_PRISON_CONTROL_HIGH&&!pool[pl]->deathpenalty)) //High is for death sentences.
			waiting_for_rescue.push_back(pool[pl]);
	}
}
Creature* findSleeperCarSalesman(int loc) {


	for (int p = 0; p < len(pool); p++)
		if (pool[p]->alive && (pool[p]->flag & CREATUREFLAG_SLEEPER) &&
			pool[p]->type == CREATURE_CARSALESMAN&&LocationsPool::getInstance().getLocationCity(pool[p]->location) == LocationsPool::getInstance().getLocationCity(loc))
			return pool[p];

	return NULL;
}
typedef map<short, string > shortAndString;
shortAndString issueEventString;

extern Log gamelog;
#include "common/musicClass.h"
extern MusicClass music;
extern int stat_recruits;
extern string commaSpace;
#include "set_color_support.h"
#include "common/commondisplay.h"
#include "common/commondisplayCreature.h"
#include "common/ledgerEnums.h"
#include "common/ledger.h"
extern class Ledger ledger;
#include "common/getnames.h"
extern string singleDot;
static void getissueeventstring(char* str)
{
	strcat(str, issueEventString[LCSrandom(VIEWNUM - 3)].data());
}
/* daily - recruit - recruit meeting */
char completerecruitmeeting(recruitst &r, int p, char &clearformess)
{
	music.play(MUSIC_RECRUITING);
	clearformess = 1;
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(0, 0);
	if (pool[p]->meetings++ > 5 && LCSrandom(pool[p]->meetings - 5))
	{
		addstrAlt(pool[p]->name, gamelog);
		addstrAlt(" accidentally missed the meeting with ", gamelog);
		addstrAlt(r.recruit->name, gamelog);
		mvaddstrAlt(1, 0, "due to multiple booking of recruitment sessions.", gamelog);
		gamelog.newline();
		mvaddstrAlt(3, 0, "Get it together, ", gamelog);
		addstrAlt(pool[p]->name, gamelog);
		addstrAlt("!", gamelog);
		gamelog.nextMessage();
		getkeyAlt();
		return 1;
	}
	addstrAlt("Meeting with ", gamelog);
	addstrAlt(r.recruit->name, gamelog);
	addstrAlt(commaSpace, gamelog);
	addstrAlt(r.recruit->get_type_name(), gamelog);
	addstrAlt(commaSpace, gamelog);
	addstrAlt(LocationsPool::getInstance().getLocationName(r.recruit->location), gamelog);
	gamelog.newline();
	set_color_easy(WHITE_ON_BLACK);
	printfunds();
	printcreatureinfo(r.recruit);
	makedelimiter();
	mvaddstrAlt(10, 0, r.recruit->name);
	switch (r.eagerness())
	{
	case 1: addstrAlt(" will take a lot of persuading."); break;
	case 2: addstrAlt(" is interested in learning more."); break;
	case 3: addstrAlt(" feels something needs to be done."); break;
	default: if (r.eagerness() >= 4) addstrAlt(" is ready to fight for the Liberal Cause.");
			 else addstrAlt(" kind of regrets agreeing to this."); break;
	}
	mvaddstrAlt(11, 0, "How should ");
	addstrAlt(pool[p]->name);
	addstrAlt(" approach the situation?");
	moveAlt(13, 0);
	if (ledger.get_funds() < 50) set_color_easy(BLACK_ON_BLACK_BRIGHT);
	addstrAlt("A - Spend $50 on props and a book for them to keep afterward.");
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(14, 0, "B - Just casually chat with them and discuss politics.");
	moveAlt(15, 0);
	if (subordinatesleft(*pool[p]) && r.eagerness() >= 4)
	{
		addstrAlt("C - Offer to let ");
		addstrAlt(r.recruit->name);
		addstrAlt(" join the LCS as a full member.");
	}
	else if (!subordinatesleft(*pool[p]))
	{
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		addstrAlt("C - ");
		addstrAlt(pool[p]->name);
		addstrAlt(" needs more Juice to recruit.");
		set_color_easy(WHITE_ON_BLACK);
	}
	else
	{
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		addstrAlt("C - ");
		addstrAlt(r.recruit->name);
		addstrAlt(" isn't ready to join the LCS.");
		set_color_easy(WHITE_ON_BLACK);
	}
	mvaddstrAlt(16, 0, "D - Break off the meetings.");
	int y = 18;
	while (true)
	{
		int c = getkeyAlt();
		if (c == 'c' && subordinatesleft(*pool[p]) && r.eagerness() >= 4)
		{
			mvaddstrAlt(y, 0, pool[p]->name, gamelog);
			addstrAlt(" offers to let ", gamelog);
			addstrAlt(r.recruit->name, gamelog);
			addstrAlt(" join the Liberal Crime Squad.", gamelog);
			gamelog.newline();
			getkeyAlt();
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			moveAlt(y += 2, 0);
			addstrAlt(r.recruit->name, gamelog);
			addstrAlt(" accepts, and is eager to get started.", gamelog);
			gamelog.nextMessage();
			liberalize(*r.recruit, false);
			getkeyAlt();
			eraseAlt();
			sleeperize_prompt(*r.recruit, *pool[p], 6);
			r.recruit->hireid = pool[p]->id;
			pool[p]->train(SKILL_PERSUASION, 25);
			addCreature(r.recruit);
			r.recruit = NULL;
			stat_recruits++;
			return 1;
		}
		if (c == 'b' || (c == 'a' && ledger.get_funds() >= 50))
		{
			if (c == 'a')
				ledger.subtract_funds(50, EXPENSE_RECRUITMENT);
			pool[p]->train(SKILL_PERSUASION,
				max(12 - pool[p]->get_skill(SKILL_PERSUASION), 5));
			pool[p]->train(SKILL_SCIENCE,
				max(r.recruit->get_skill(SKILL_SCIENCE) - pool[p]->get_skill(SKILL_SCIENCE), 0));
			pool[p]->train(SKILL_RELIGION,
				max(r.recruit->get_skill(SKILL_RELIGION) - pool[p]->get_skill(SKILL_RELIGION), 0));
			pool[p]->train(SKILL_LAW,
				max(r.recruit->get_skill(SKILL_LAW) - pool[p]->get_skill(SKILL_LAW), 0));
			pool[p]->train(SKILL_BUSINESS,
				max(r.recruit->get_skill(SKILL_BUSINESS) - pool[p]->get_skill(SKILL_BUSINESS), 0));
			int lib_persuasiveness = pool[p]->get_skill(SKILL_BUSINESS) +
				pool[p]->get_skill(SKILL_SCIENCE) +
				pool[p]->get_skill(SKILL_RELIGION) +
				pool[p]->get_skill(SKILL_LAW) +
				pool[p]->get_attribute(ATTRIBUTE_INTELLIGENCE, true);
			int recruit_reluctance = 5 +
				r.recruit->get_skill(SKILL_BUSINESS) +
				r.recruit->get_skill(SKILL_SCIENCE) +
				r.recruit->get_skill(SKILL_RELIGION) +
				r.recruit->get_skill(SKILL_LAW) +
				r.recruit->get_attribute(ATTRIBUTE_WISDOM, true) +
				r.recruit->get_attribute(ATTRIBUTE_INTELLIGENCE, true);
			if (lib_persuasiveness > recruit_reluctance) recruit_reluctance = 0;
			else recruit_reluctance -= lib_persuasiveness;
			int difficulty = recruit_reluctance;
			char str[75];
			strcpy(str, "");
			if (c == 'a')
			{
				difficulty -= 5;
				mvaddstrAlt(y++, 0, pool[p]->name, gamelog);
				addstrAlt(" shares ", gamelog);
				getissueeventstring(str);
				addstrAlt(str, gamelog);
				addstrAlt(singleDot, gamelog);
				gamelog.newline();
				getkeyAlt();
			}
			else
			{
				mvaddstrAlt(y++, 0, pool[p]->name, gamelog);
				addstrAlt(" explains ", gamelog);
				addstrAlt(pool[p]->hisher(), gamelog);
				addstrAlt(" views on ", gamelog);
				addstrAlt(getview(LCSrandom(VIEWNUM - 3), true), gamelog);
				addstrAlt(singleDot, gamelog);
				gamelog.newline();
				getkeyAlt();
			}
			// Liberals with juice increase difficulty as if their Wisdom were increased by said juice
			if (r.recruit->juice >= 10)
			{
				if (r.recruit->juice < 50) //Activist
					difficulty += 1;
				else if (r.recruit->juice < 100) //Socialist Threat
					difficulty += static_cast<int>(2 + 0.1*r.recruit->get_attribute(ATTRIBUTE_WISDOM, false));
				else if (r.recruit->juice < 200) //Revolutionary
					difficulty += static_cast<int>(3 + 0.2*r.recruit->get_attribute(ATTRIBUTE_WISDOM, false));
				else if (r.recruit->juice < 500) //Urban Commando
					difficulty += static_cast<int>(4 + 0.3*r.recruit->get_attribute(ATTRIBUTE_WISDOM, false));
				else if (r.recruit->juice < 1000) //Liberal Guardian
					difficulty += static_cast<int>(5 + 0.4*r.recruit->get_attribute(ATTRIBUTE_WISDOM, false));
				else //Elite Liberal
					difficulty += static_cast<int>(6 + 0.5*r.recruit->get_attribute(ATTRIBUTE_WISDOM, false));
			}
			if (difficulty > 18) difficulty = 18; // difficulty above 18 is impossible, we don't want that
			if (pool[p]->skill_check(SKILL_PERSUASION, difficulty))
			{
				set_color_easy(CYAN_ON_BLACK_BRIGHT);
				if (r.level < 127) r.level++;
				if (r.eagerness1 < 127) r.eagerness1++;
				mvaddstrAlt(y++, 0, r.recruit->name, gamelog);
				addstrAlt(" found ", gamelog);
				addstrAlt(pool[p]->name, gamelog);
				addstrAlt("'s views to be insightful.", gamelog);
				gamelog.newline();
				mvaddstrAlt(y++, 0, "They'll definitely meet again tomorrow.", gamelog);
				gamelog.nextMessage();
			}
			else if (pool[p]->skill_check(SKILL_PERSUASION, difficulty)) // Second chance to not fail horribly
			{
				if (r.level < 127) r.level++;
				if (r.eagerness1 > -128) r.eagerness1--;
				mvaddstrAlt(y++, 0, r.recruit->name, gamelog);
				addstrAlt(" is skeptical about some of ", gamelog);
				addstrAlt(pool[p]->name, gamelog);
				addstrAlt("'s arguments.", gamelog);
				gamelog.newline();
				mvaddstrAlt(y++, 0, "They'll meet again tomorrow.", gamelog);
				gamelog.nextMessage();
			}
			else
			{
				set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
				moveAlt(y++, 0);
				if (r.recruit->talkreceptive() && r.recruit->align == ALIGN_LIBERAL)
				{
					addstrAlt(r.recruit->name, gamelog);
					addstrAlt(" isn't convinced ", gamelog);
					addstrAlt(pool[p]->name, gamelog);
					addstrAlt(" really understands the problem.", gamelog);
					gamelog.newline();
					mvaddstrAlt(y++, 0, "Maybe ", gamelog);
					addstrAlt(pool[p]->name, gamelog);
					addstrAlt(" needs more experience.", gamelog);
					gamelog.nextMessage();
				}
				else
				{
					addstrAlt(pool[p]->name, gamelog);
					addstrAlt(" comes off as slightly insane.", gamelog);
					gamelog.newline();
					mvaddstrAlt(y++, 0, "This whole thing was a mistake. There won't be another meeting.", gamelog);
					gamelog.nextMessage();
				}
				getkeyAlt();
				return 1;
			}
			getkeyAlt();
			return 0;
		}
		if (c == 'd') return 1;
	}
}
void findAllTendersToThisHostage(Creature* cr, vector<Creature *>& temppool) {

	//Find all tenders who are set to this hostage
	for (int p = 0; p < len(pool); p++)
	{
		if (!pool[p]->alive) continue;
		if (pool[p]->activity.type == ACTIVITY_HOSTAGETENDING&&pool[p]->activity.arg == cr->id)
		{
			//If they're in the same location as the hostage,
			//include them in the interrogation
			if (pool[p]->location == cr->location&&pool[p]->location != -1)
				temppool.push_back(pool[p]);
			//If they're someplace else, take them off the job
			else pool[p]->activity.type = ACTIVITY_NONE;
		}
	}
}
void hostageEscapes(Creature* cr, char clearformess) {
	for (int p = 0; p < len(pool); p++)
	{
		if (pool[p] == cr)
		{
			if (clearformess) eraseAlt();
			else makedelimiter();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 1, cr->name, gamelog);
			addstrAlt(" has escaped!", gamelog);
			gamelog.nextMessage();
			LocationsPool::getInstance().setTimeUntilSiege(cr->location, 3);
			getkeyAlt();
			//clear activities for tenders
			for (int i = 0; i < len(pool); i++)
			{
				if (!pool[i]->alive) continue;
				if (pool[i]->activity.type == ACTIVITY_HOSTAGETENDING&&pool[i]->activity.arg == cr->id)
					pool[i]->activity.type = ACTIVITY_NONE;
			}
			delete_and_remove(pool, p);
			break;
		}
	}
}
void setAllCreatureActivities(Activity cr, vector<Creature *>& temppool) {
	for (int p = 0; p < len(temppool); p++) {
		temppool[p]->activity.type = cr;
	}
}
Creature::~Creature()
{
	delete weapon;
	delete armor;
	delete_and_clear(clips);
	delete_and_clear(extra_throwing_weapons);
	if (prisoner)
	{
		int p;
		for (p = 0; p < len(pool); p++)
			if (prisoner == pool[p]) { delete_and_remove(pool, p); break; }
	}
	// Clean up hostage situation
	stop_hauling_me();
}
void Creature::stop_hauling_me()
{
	for (int p = 0; p < len(pool); p++) if (pool[p]->prisoner == this) pool[p]->prisoner = NULL;
}
bool Creature::enemy() const
{
	if (align == ALIGN_CONSERVATIVE)
		return true;
	else if (type == CREATURE_COP && align == ALIGN_MODERATE)
	{
		for (int i = 0; i < len(pool); i++)
			if (pool[i] == this)
				return false;
		return true;
	}
	else return false;
}

#include "common/translateid.h"
// for  int getpoolcreature(int)

void selectOnlySleepersThatCanWork(vector<Creature *>& temppool) {

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
}

#include "daily/siege.h"
extern char disbanding;
void determineMedicalSupportAtEachLocation(bool clearformess) {
	// Healing - determine medical support at each location
	int *healing = new int[LocationsPool::getInstance().lenpool()];
	int *healing2 = new int[LocationsPool::getInstance().lenpool()];
	for (int p = 0; p < LocationsPool::getInstance().lenpool(); p++)
	{
		// Clinic is equal to a skill 6 liberal
		if (LocationsPool::getInstance().getLocationType(p) == SITE_HOSPITAL_CLINIC) healing[p] = 6;
		// Hospital is equal to a skill 12 liberal
		else if (LocationsPool::getInstance().getLocationType(p) == SITE_HOSPITAL_UNIVERSITY) healing[p] = 12;
		else healing[p] = 0;
		healing2[p] = 0;
	}
	if (!disbanding) for (int p = 0; p<CreaturePool::getInstance().lenpool(); p++)
	{
		if (!pool[p]->alive) continue;
		if (pool[p]->hiding) continue;
		if (pool[p]->flag&CREATUREFLAG_SLEEPER) continue;
		// People will help heal even if they aren't specifically assigned to do so
		// Having a specific healing activity helps bookkeeping for the player, though
		// Only the highest medical skill is considered
		if (pool[p]->activity.type == ACTIVITY_HEAL || pool[p]->activity.type == ACTIVITY_NONE)
			if (pool[p]->location>-1 &&
				healing[pool[p]->location] < pool[p]->get_skill(SKILL_FIRSTAID))
			{
				healing[pool[p]->location] = pool[p]->get_skill(SKILL_FIRSTAID);
				pool[p]->activity.type = ACTIVITY_HEAL;
			}
	}
	// Don't let starving locations heal
	for (int p = 0; p < LocationsPool::getInstance().lenpool(); p++)
		if (LocationsPool::getInstance().getLocationType(p) != SITE_HOSPITAL_CLINIC && LocationsPool::getInstance().getLocationType(p) != SITE_HOSPITAL_UNIVERSITY)
			if (!fooddaysleft(p))
				if (LocationsPool::getInstance().isThereASiegeHere(p))
					healing[p] = 0;
	//HEAL NON-CLINIC PEOPLE AND TRAIN
	if (!disbanding) for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (!(pool[p]->alive)) continue;
		if (clinictime(*pool[p]))
		{
			// For people in LCS home treatment
			if (pool[p]->clinic == false)
			{
				int damage = 0; // Amount health degrades
								//int release=1;
				int transfer = 0;
				// Give experience to caretakers
				if (pool[p]->location > -1) healing2[pool[p]->location] += 100 - pool[p]->blood;
				// Cap blood at 100-injurylevel*20
				if (pool[p]->blood < 100 - (clinictime(*pool[p]) - 1) * 20)
				{
					// Add health
					if (pool[p]->location > -1)pool[p]->blood += 1 + healing[pool[p]->location] / 3;
					if (pool[p]->blood > 100 - (clinictime(*pool[p]) - 1) * 20)
						pool[p]->blood = 100 - (clinictime(*pool[p]) - 1) * 20;
					if (pool[p]->blood > 100)
						pool[p]->blood = 100;
				}
				if (pool[p]->alive&&pool[p]->blood < 0)
				{
					if (clearformess) eraseAlt();
					else makedelimiter();
					pool[p]->die();
					mvaddstrAlt(8, 1, pool[p]->name, gamelog);
					addstrAlt(" has died of injuries.", gamelog);
					gamelog.nextMessage();
				}
				for (int w = 0; w < BODYPARTNUM; w++)
				{
					// Limbs blown off
					if (pool[p]->wound[w] & WOUND_NASTYOFF)
					{
						// Chance to stabilize/amputate wound
						// Difficulty 12 (Will die if not treated)
						if (pool[p]->location > -1 && healing[pool[p]->location] + LCSrandom(10)>12)
							pool[p]->wound[w] = WOUND_CLEANOFF;
						// Else take bleed damage (4)
						else
						{
							damage += 4;
							//release=0;
							if (pool[p]->location > -1 && healing[pool[p]->location] + 9 <= 12)
								transfer = 1;
						}
					}
					// Bleeding wounds
					else if (pool[p]->wound[w] & WOUND_BLEEDING)
					{
						// Chance to stabilize wound
						// Difficulty 8 (1 in 10 of happening naturally)
						if (pool[p]->location > -1 && healing[pool[p]->location] + LCSrandom(10) > 8)
							// Toggle bleeding off
							pool[p]->wound[w] &= ~WOUND_BLEEDING;
						// Else take bleed damage (1)
						else
						{
							damage += 1;
							//release=0;
						}
					}
					// Non-bleeding wounds
					else
					{  // Erase wound if almost fully healed, but preserve loss of limbs.
						if (pool[p]->blood >= 95)
							pool[p]->wound[w] &= WOUND_CLEANOFF;
					}
				}
				// Critical hit wounds
				for (int i = SPECIALWOUND_RIGHTLUNG; i < SPECIALWOUNDNUM; ++i)
				{
					int healdiff = 14, permdamage = 0, bleed = 0, healed = 0;
					// Specific treatment information on wounds
					switch (i)
					{
					case SPECIALWOUND_HEART:
						healdiff = 16;
						bleed = 8;
					case SPECIALWOUND_RIGHTLUNG:
					case SPECIALWOUND_LEFTLUNG:
						permdamage = 1;
					case SPECIALWOUND_LIVER:
					case SPECIALWOUND_STOMACH:
					case SPECIALWOUND_RIGHTKIDNEY:
					case SPECIALWOUND_LEFTKIDNEY:
					case SPECIALWOUND_SPLEEN:
						healed = 1;
						bleed++;
						break;
					case SPECIALWOUND_RIBS:
						healed = RIBNUM;
						break;
					case SPECIALWOUND_NECK:
					case SPECIALWOUND_UPPERSPINE:
					case SPECIALWOUND_LOWERSPINE:
						healed = 2;
						break;
					}
					// If wounded
					if (pool[p]->special[i] != healed && (i == SPECIALWOUND_RIBS || pool[p]->special[i] != 1))
					{
						// Chance to stabilize wound
						if (pool[p]->location > -1 && healing[pool[p]->location] + LCSrandom(10) > healdiff)
						{
							// Remove wound
							pool[p]->special[i] = healed;
							if (permdamage)
							{
								// May take permanent health damage depending on
								// quality of care
								if (LCSrandom(20) > healing[pool[p]->location])
								{
									pool[p]->adjust_attribute(ATTRIBUTE_HEALTH, -1);
									if (pool[p]->get_attribute(ATTRIBUTE_HEALTH, false) <= 0)
									{
										pool[p]->set_attribute(ATTRIBUTE_HEALTH, 1);
									}
								}
							}
						}
						// Else take bleed damage
						else
						{
							damage += bleed;
							//release=0;
							if (healing[pool[p]->location] + 9 <= healdiff)
								transfer = 1;
						}
					}
				}
				// Apply damage
				pool[p]->blood -= damage;
				if (transfer&&pool[p]->location > -1 &&
					pool[p]->alive == 1 &&
					pool[p]->align == 1 &&
					LocationsPool::getInstance().getRentingType(pool[p]->location) != RENTING_NOCONTROL&&
					LocationsPool::getInstance().getLocationType(pool[p]->location) != SITE_HOSPITAL_UNIVERSITY)
				{
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8, 1, pool[p]->name, gamelog);
					addstrAlt("'s injuries require professional treatment.", gamelog);
					gamelog.nextMessage();
					pool[p]->activity.type = ACTIVITY_CLINIC;
					getkeyAlt();
				}
			}
		}
	}
	//Give experience to medics
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		//If present, qualified to heal, and doing so
		if (pool[p]->location >= 0 && pool[p]->activity.type == ACTIVITY_HEAL)
		{
			//Clear activity if their location doesn't have healing work to do
			if (healing2[pool[p]->location] == 0)
				pool[p]->activity.type = ACTIVITY_NONE;
			//Give experience based on work done and current skill
			else
				pool[p]->train(SKILL_FIRSTAID, max(0, healing2[pool[p]->location] / 5 - pool[p]->get_skill(SKILL_FIRSTAID) * 2));
		}
	}
	delete[] healing;
	delete[] healing2;
}

/* promote a subordinate to maintain chain of command when boss is lost */
bool promotesubordinates(Creature &cr, char &clearformess)
{
	int p;
	int newboss = -1;
	int bigboss = -2;
	if (cr.hireid == -1)bigboss = -1;//Special: Founder
	int maxjuice = 0; //Need more than 0 juice to get promoted
	int subordinates = 0;
	//Need REVOLUTIONARY (100+) juice to take over founder role
	if (cr.hireid == -1)maxjuice = 99;
	//Identify big boss and top subordinate
	for (p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (pool[p]->id == cr.id)continue;
		if (pool[p]->id == cr.hireid)bigboss = p;
		if (pool[p]->hireid == cr.id && pool[p]->alive && pool[p]->align == 1)
		{
			subordinates++;
			//Brainwashed people inelligible for promotion to founder
			if (bigboss == -1 && pool[p]->flag & CREATUREFLAG_BRAINWASHED)continue;
			//Loveslaves inelligible for promotion to anything unless juice is high
			//in which case they get over it and continue to serve as a normal member
			if (pool[p]->flag & CREATUREFLAG_LOVESLAVE)
			{
				if (pool[p]->juice < 100)continue;
				else pool[p]->flag &= ~CREATUREFLAG_LOVESLAVE;
			}
			// Highest juice liberal not a sleeper or subject to a life sentence gets promoted
			if (pool[p]->juice > maxjuice&&
				!(pool[p]->flag & CREATUREFLAG_SLEEPER) &&
				(pool[p]->location == -1 ||
					(LocationsPool::getInstance().getLocationType(pool[p]->location) != SITE_GOVERNMENT_PRISON || pool[p]->sentence >= 0)))
			{
				maxjuice = pool[p]->juice;
				newboss = p;
			}
		}
	}
	//No subordinates or none with sufficient juice to carry on
	if (subordinates == 0 || newboss == -1)
	{
		if (cr.hireid != -1)return 0;
		if (subordinates > 0) // Disintegration of the LCS
		{
			if (clearformess) eraseAlt();
			else makedelimiter();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 1, cr.name, gamelog);
			addstrAlt(" has died.", gamelog);
			gamelog.newline();
			getkeyAlt();
			mvaddstrAlt(10, 1, "There are none left with the courage and conviction to lead....", gamelog);
			gamelog.nextMessage();
			getkeyAlt();
		}
		return 0;
	}
	//Chain of command totally destroyed if dead person's boss also dead
	if (bigboss == -2 || (cr.hireid != -1 && bigboss != -1 && !pool[bigboss]->alive))return 0;
	//Promote the new boss
	pool[newboss]->hireid = cr.hireid;
	//Order secondary subordinates to follow the new boss
	if (subordinates > 1)
	{
		for (p = 0; p < CreaturePool::getInstance().lenpool(); p++)
		{
			if (pool[p]->hireid == cr.id && // recruited by old boss that died
				p != newboss &&             // not the new boss
				!(pool[p]->flag & CREATUREFLAG_LOVESLAVE)) // is not a love slave
			{
				pool[p]->hireid = pool[newboss]->id; // promote
			}
		}
	}
	if (clearformess) eraseAlt();
	else makedelimiter();
	if (bigboss != -1) // Normal promotion
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8, 1, pool[bigboss]->name, gamelog);
		addstrAlt(" has promoted ", gamelog);
		addstrAlt(pool[newboss]->name, gamelog);
		mvaddstrAlt(9, 1, "due to the death of ", gamelog);
		addstrAlt(cr.name, gamelog);
		addstrAlt(singleDot, gamelog);
		if (subordinates > 1)
		{
			gamelog.newline();
			mvaddstrAlt(11, 1, pool[newboss]->name, gamelog);
			addstrAlt(" will take over for ", gamelog);
			addstrAlt(cr.name, gamelog);
			addstrAlt(" in the command chain.", gamelog);
		}
		gamelog.nextMessage();
		getkeyAlt();
	}
	else // Founder level promotion
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8, 1, cr.name, gamelog);
		addstrAlt(" has died.", gamelog);
		gamelog.newline();
		getkeyAlt();
		mvaddstrAlt(10, 1, pool[newboss]->name, gamelog);
		addstrAlt(" is the new leader of the Liberal Crime Squad!", gamelog);
		gamelog.nextMessage();
		getkeyAlt();
		cr.hireid = -2; // Make dead founder not founder.
	}
	return 1;
}
enum DispersalTypes
{
	DISPERSAL_SAFE = -1,
	DISPERSAL_BOSSSAFE,
	DISPERSAL_NOCONTACT,
	DISPERSAL_BOSSINPRISON,
	DISPERSAL_HIDING,
	DISPERSAL_BOSSINHIDING,
	DISPERSAL_ABANDONLCS
};
#include "common/commonactions.h"
/* squad members with no chain of command lose contact */
void dispersalcheck(char &clearformess)
{
	int p = 0;
	//NUKE DISPERSED SQUAD MEMBERS WHOSE MASTERS ARE NOT AVAILABLE
	if (CreaturePool::getInstance().lenpool())
	{
		// *JDS* I'm documenting this algorithm carefully because it
		// took me awhile to figure out what exactly was going on here.
		//
		// dispersal_status tracks whether each person has a secure chain of command.
		//
		// if dispersal_status == NOCONTACT, no confirmation of contact has been made
		// if dispersal_status == BOSSSAFE, confirmation that THEY are safe is given,
		//    but it is still needed to check whether their subordinates
		//    can reach them.
		// if dispersal_status == SAFE, confirmation has been made that this squad
		//    member is safe, and their immediate subordinates have also
		//    checked.
		//
		// The way the algorithm works, everyone starts at dispersal_status = NOCONTACT.
		// Then we start at the top of the chain of command and walk
		// down it slowly, marking people BOSSSAFE and then SAFE as we sweep
		// down the chain. If someone is dead or in an unreachable state,
		// they block progression down the chain to their subordinates,
		// preventing everyone who requires contact with that person
		// from being marked safe. After everyone reachable has been
		// reached and marked safe, all remaining squad members are nuked.
		vector<int> dispersal_status;
		dispersal_status.resize(CreaturePool::getInstance().lenpool());
		bool promotion;
		do
		{
			promotion = 0;
			for (p = 0; p < CreaturePool::getInstance().lenpool(); p++)
			{
				// Default: members are marked dispersal_status = NOCONTACT
				//(no contact verified)
				dispersal_status[p] = DISPERSAL_NOCONTACT;
				// If member has no boss (founder level), mark
				// them dispersal_status = BOSSSAFE, using them as a starting point
				// at the top of the chain.
				if (pool[p]->hireid == -1)
				{
					if (!disbanding)
					{
						dispersal_status[p] = DISPERSAL_BOSSSAFE;
						if (pool[p]->hiding == -1)
							pool[p]->hiding = LCSrandom(10) + 5;
					}
					else dispersal_status[p] = DISPERSAL_BOSSINHIDING;
				}
				// If they're dead, mark them dispersal_status = SAFE, so they
				// don't ever have their subordinates checked
				// and aren't lost themselves (they're a corpse,
				// corpses don't lose contact)
				if (!pool[p]->alive&&!disbanding)
				{
					dispersal_status[p] = DISPERSAL_SAFE;
					//Attempt to promote their subordinates
					if (promotesubordinates(*pool[p], clearformess)) promotion = 1;
					if (pool[p]->location == -1 || LocationsPool::getInstance().getRentingType(pool[p]->location) == RENTING_NOCONTROL)
						delete_and_remove(pool, p--);
				}
			}
		} while (promotion);
		char changed;
		do // while(changed)
		{
			changed = 0;
			char inprison;
			// Go through the entire pool to locate people at dispersal_status = BOSSSAFE,
			// so we can verify that their subordinates can reach them.
			for (p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
			{
				if (!pool[p]->alive) continue;
				if (pool[p]->location != -1 &&
					LocationsPool::getInstance().getLocationType(pool[p]->location) == SITE_GOVERNMENT_PRISON&&
					!(pool[p]->flag & CREATUREFLAG_SLEEPER))
				{
					inprison = 1;
				}
				else inprison = 0;
				// If your boss is in hiding
				if (dispersal_status[p] == DISPERSAL_BOSSINHIDING)
				{
					dispersal_status[p] = DISPERSAL_HIDING;
					for (int p2 = CreaturePool::getInstance().lenpool() - 1; p2 >= 0; p2--)
					{
						if (pool[p2]->hireid == pool[p]->id && pool[p2]->alive)
						{
							dispersal_status[p2] = DISPERSAL_BOSSINHIDING; // Mark them as unreachable
							changed = 1; // Need another iteration
						}
					}
				}
				// If in prison or unreachable due to a member of the command structure
				// above being in prison
				else if ((dispersal_status[p] == DISPERSAL_BOSSSAFE&&inprison) || dispersal_status[p] == DISPERSAL_BOSSINPRISON)
				{
					int dispersalval = DISPERSAL_SAFE;
					if (pool[p]->flag&CREATUREFLAG_LOVESLAVE)
					{
						if ((dispersal_status[p] == DISPERSAL_BOSSINPRISON&&!inprison) ||
							(dispersal_status[p] == DISPERSAL_BOSSSAFE    && inprison))
						{
							pool[p]->juice--; // Love slaves bleed juice when not in prison with their lover
							if (pool[p]->juice < -50) dispersalval = DISPERSAL_ABANDONLCS;
						}
					}
					dispersal_status[p] = dispersalval; // Guaranteed contactable in prison
														// Find all subordinates
					for (int p2 = CreaturePool::getInstance().lenpool() - 1; p2 >= 0; p2--)
					{
						if (pool[p2]->hireid == pool[p]->id && pool[p2]->alive)
						{
							if (inprison) dispersal_status[p2] = DISPERSAL_BOSSINPRISON;
							else dispersal_status[p2] = DISPERSAL_BOSSSAFE;
							changed = 1; // Need another iteration
						}
					}
				}
				// Otherwise, if they're reachable
				else if (dispersal_status[p] == DISPERSAL_BOSSSAFE&&!inprison)
				{
					// Start looking through the pool again.
					for (int p2 = CreaturePool::getInstance().lenpool() - 1; p2 >= 0; p2--)
					{
						// Locate each of this person's subordinates.
						if (pool[p2]->hireid == pool[p]->id)
						{
							// Protect them from being dispersed -- their boss is
							// safe. Their own subordinates will then be considered
							// in the next loop iteration.
							dispersal_status[p2] = DISPERSAL_BOSSSAFE;
							// If they're hiding indefinitely and their boss isn't
							// hiding at all, then have them discreetly return in a
							// couple of weeks
							if (pool[p2]->hiding == -1 && !pool[p]->hiding)
								pool[p2]->hiding = LCSrandom(10) + 3;
							changed = 1; // Take note that another iteration is needed.
						}
					}
					// Now that we've dealt with this person's subordinates, mark
					// them so that we don't look at them again in this loop.
					dispersal_status[p] = DISPERSAL_SAFE;
				}
			}
		} while (changed); // If another iteration is needed, continue the loop.
						   // After checking through the entire command structure, proceed
						   // to nuke all squad members who are unable to make contact with
						   // the LCS.
		for (p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
		{
			if (dispersal_status[p] == DISPERSAL_NOCONTACT || dispersal_status[p] == DISPERSAL_HIDING || dispersal_status[p] == DISPERSAL_ABANDONLCS)
			{
				if (clearformess) eraseAlt();
				else makedelimiter();
				if (!disbanding)
				{
					if (!pool[p]->hiding&&dispersal_status[p] == DISPERSAL_HIDING)
					{
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(8, 1, pool[p]->name, gamelog);
						addstrAlt(" has lost touch with the Liberal Crime Squad.", gamelog);
						gamelog.nextMessage();
						getkeyAlt();
						set_color_easy(GREEN_ON_BLACK_BRIGHT);
						mvaddstrAlt(9, 1, "The Liberal has gone into hiding...", gamelog);
						gamelog.nextMessage();
						getkeyAlt();
					}
					else if (dispersal_status[p] == DISPERSAL_ABANDONLCS)
					{
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(8, 1, pool[p]->name, gamelog);
						addstrAlt(" has abandoned the LCS.", gamelog);
						gamelog.nextMessage();
						getkeyAlt();
					}
					else if (dispersal_status[p] == DISPERSAL_NOCONTACT)
					{
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(8, 1, pool[p]->name, gamelog);
						addstrAlt(" has lost touch with the Liberal Crime Squad.", gamelog);
						gamelog.nextMessage();
						getkeyAlt();
					}
				}
				removesquadinfo(*pool[p]);
				if (dispersal_status[p] == DISPERSAL_NOCONTACT || dispersal_status[p] == DISPERSAL_ABANDONLCS)
					delete_and_remove(pool, p);
				else
				{
					pool[p]->location = -1;
					if (!(pool[p]->flag & CREATUREFLAG_SLEEPER)) //Sleepers end up in shelter otherwise.
						pool[p]->base = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, pool[p]->location);
					pool[p]->activity.type = ACTIVITY_NONE;
					pool[p]->hiding = -1; // Hide indefinitely
				}
			}
		}
	}
	//MUST DO AN END OF GAME CHECK HERE BECAUSE OF DISPERSAL
	endcheck(END_DISPERSED);
	cleangonesquads();
}

