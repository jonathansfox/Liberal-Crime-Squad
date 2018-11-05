#include "../includes.h"

const string tag_ARMOR = "ARMOR";
const string tag_ARMOR_PRISONER = "ARMOR_PRISONER";
const string blankString = "";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
#include "vehicle/vehicleType.h"///
#include "vehicle/vehicle.h"///
#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../common/creaturePool.h"
#include "../common/creaturePoolCreature.h"
vector<DeprecatedCreature *> pool;
CreaturePool singletonPool;
void DeprecatedCreature::addCreature()
{
	pool.push_back(this);
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
	for (int p = 0; p < lenpool(); p++)
		if (pool[p]->carid == id_)
			pool[p]->carid = -1;
}
void CreaturePool::stopAllBleeding()
{
	for (int p = 0; p < lenpool(); p++)
		for (int w = 0; w < BODYPARTNUM; w++)
			pool[p]->wound[w] &= ~WOUND_BLEEDING;
}
const bool CreaturePool::doesAnyoneLiveHere(int loc)
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
	for (int p = 0; p < lenpool(); p++)
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
#include "../cursesAlternative.h"
#include "../log/log.h"
//#include "../common/consolesupport.h"
void CreaturePool::outSleepers(int cursite, int base)
{
	const string CONST_creaturePool007 = "The Liberal is now at your command as a normal squad member.";
	const string CONST_creaturePool006 = " has been outed by your bold attack!";
	extern Log gamelog;
	for (int p = 0; p < lenpool(); p++)
	{
		if (pool[p]->flag&CREATUREFLAG_SLEEPER &&
			pool[p]->location == cursite)
		{
			pool[p]->flag &= ~CREATUREFLAG_SLEEPER;
			eraseAlt();
			mvaddstrAlt(8, 1, string_sleeper, gamelog);
			addstrAlt(pool[p]->getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_creaturePool006, gamelog);
			gamelog.newline();
			mvaddstrAlt(10, 1, CONST_creaturePool007, gamelog);
			gamelog.newline();
			pool[p]->base = base;
			pool[p]->location = pool[p]->base;
			pressAnyKey();
		}
	}
}
#include "../sitemode/advance.h"
/* handles end of round stuff for one creature */
void CreaturePool::advanceCreaturesAtLocation(int cursite)
{
	for (int p = 0; p < lenpool(); p++)
	{
		if (!pool[p]->getNameAndAlignment().alive) continue;
		if (pool[p]->squadid != -1) continue;
		if (pool[p]->location != cursite) continue;
		pool[p]->advancecreature();
	}
}
#include "../common/commonactionsCreature.h"
#include "../combat/fightCreature.h"
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
				pool[p]->criminalize( LAWFLAG_RACKETEERING);
				pool[p]->capturedByConservatives();
				
			}
		}
	}
}
#include "../locations/locationsPool.h"
const int CreaturePool::liberal_guardian_writing_power()
{
	int power = 0;
	for (int i = 0; i < lenpool(); i++)
	{
		if (pool[i]->getNameAndAlignment().alive&&pool[i]->activity_type() == ACTIVITY_WRITE_GUARDIAN)
		{
			if (pool[i]->location != -1 &&
				LocationsPool::getInstance().get_specific_integer(INT_GETCOMPOUNDWALLS,pool[i]->location) & COMPOUND_PRINTINGPRESS)
			{
				pool[i]->train(SKILL_WRITING, LCSrandom(3)); // Experience gain
				power += pool[i]->skill_roll(SKILL_WRITING); // Record the writer on this topic
				pool[i]->criminalize( LAWFLAG_SPEECH); // Record possibly illegal speech activity
			}
			else pool[i]->set_activity(ACTIVITY_NONE);
		}
	}
	return power;
}
const int CreaturePool::howManyLivingPeopleAreHere(int l)
{
	int numpres = 0;
	for (int p = 0; p < lenpool(); p++)
	{
		if (pool[p]->location != l) continue; // People not at this base don't count
		if (!pool[p]->getNameAndAlignment().alive) continue; // Dead people don't count
		numpres++;
	}
	return numpres;
}
const int CreaturePool::countLiberals(int cursite)
{
	int libnum = 0;
	for (int p = 0; p < lenpool(); p++) {
		if (pool[p]->align == 1 &&
			pool[p]->getNameAndAlignment().alive&&
			pool[p]->location == cursite &&
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
		if (!pool[p]->getNameAndAlignment().alive || pool[p]->flag&CREATUREFLAG_KIDNAPPED || pool[p]->flag&CREATUREFLAG_MISSING) delete_and_remove(pool, p);
		else if (!(pool[p]->flag&CREATUREFLAG_SLEEPER))
		{
			pool[p]->removesquadinfo();
			pool[p]->hiding = -1;
		}
	}
}
const bool CreaturePool::isThisCarWantedByAnotherSquad(long vehicleID, int squadID)
{
	for (int p = 0; p < lenpool(); p++)
	{
		if (pool[p]->squadid != -1 && pool[p]->getNameAndAlignment().alive&&
			pool[p]->pref_carid == vehicleID && pool[p]->squadid != squadID)
		{
			return true;
		}
	}
	return false;
}
const string CreaturePool::getName(int p)
{
	return pool[p]->getNameAndAlignment().name;
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
const int CreaturePool::lenpool() const {
	return len(pool);
}
void whoAreWaitingForRescue(vector<DeprecatedCreature *>& waiting_for_rescue, int cursite, short special) {
	for (int pl = 0; pl < len(pool); pl++)
	{
		if (pool[pl]->location == cursite &&
			!(pool[pl]->flag & CREATUREFLAG_SLEEPER) &&
			!(special == SPECIAL_PRISON_CONTROL_LOW && !(pool[pl]->getCreatureJustice().sentence > 0 && !pool[pl]->getCreatureJustice().deathpenalty)) && //Low is for normal time-limited sentences.
			!(special == SPECIAL_PRISON_CONTROL_MEDIUM && !(pool[pl]->getCreatureJustice().sentence < 0 && !pool[pl]->getCreatureJustice().deathpenalty)) && //Medium is for life sentences.
			!(special == SPECIAL_PRISON_CONTROL_HIGH && !pool[pl]->getCreatureJustice().deathpenalty)) //High is for death sentences.
			waiting_for_rescue.push_back(pool[pl]);
	}
}
DeprecatedCreature* findSleeperCarSalesman(int loc) {
	for (int p = 0; p < len(pool); p++)
		if (pool[p]->getNameAndAlignment().alive && (pool[p]->flag & CREATUREFLAG_SLEEPER) &&
			pool[p]->type == CREATURE_CARSALESMAN && LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONCITY,pool[p]->location) == LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONCITY,loc))
			return pool[p];
	return NULL;
}
map<short, string> issueEventString;
#include "../common/musicClass.h"
extern string commaSpace;
#include "../set_color_support.h"
#include "../common/commondisplay.h"
#include "../common/commondisplayCreature.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../common/getnames.h"
extern string singleDot;
static void getissueeventstring(char* str)
{
	strcat(str, issueEventString[LCSrandom(VIEWNUM - 3)].data());
}

const string CONST_creaturePool046 = "This whole thing was a mistake. There won't be another meeting.";
const string CONST_creaturePool045 = " comes off as slightly insane.";
const string CONST_creaturePool044 = " needs more experience.";
const string CONST_creaturePool043 = "Maybe ";
const string CONST_creaturePool042 = " really understands the problem.";
const string CONST_creaturePool041 = " isn't convinced ";
const string CONST_creaturePool040 = "They'll meet again tomorrow.";
const string CONST_creaturePool039 = "'s arguments.";
const string CONST_creaturePool038 = " is skeptical about some of ";
const string CONST_creaturePool037 = "They'll definitely meet again tomorrow.";
const string CONST_creaturePool036 = "'s views to be insightful.";
const string CONST_creaturePool035 = " found ";
const string CONST_creaturePool034 = " views on ";
const string CONST_creaturePool033 = " explains ";
const string CONST_creaturePool032 = " shares ";
const string CONST_creaturePool031 = " accepts, and is eager to get started.";
const string CONST_creaturePool030 = " join the Liberal Crime Squad.";
const string CONST_creaturePool029 = " offers to let ";

LOOP_CONTINUATION increment_completerecruitmeeting(const int p, Deprecatedrecruitst &r, int &y) {
	extern Log gamelog;
	extern int stat_recruits;
	extern class Ledger ledger;

	int c = getkeyAlt();
	if (c == 'c' && pool[p]->subordinatesleft() && r.eagerness() >= 4)
	{
		mvaddstrAlt(y, 0, pool[p]->getNameAndAlignment().name, gamelog);
		addstrAlt(CONST_creaturePool029, gamelog);
		addstrAlt(r.recruit->getNameAndAlignment().name, gamelog);
		addstrAlt(CONST_creaturePool030, gamelog);
		gamelog.newline();
		pressAnyKey();
		set_color_easy(GREEN_ON_BLACK_BRIGHT);
		moveAlt(y += 2, 0);
		addstrAlt(r.recruit->getNameAndAlignment().name, gamelog);
		addstrAlt(CONST_creaturePool031, gamelog);
		gamelog.nextMessage();
		r.recruit->liberalize(false);
		pressAnyKey();
		eraseAlt();
		r.recruit->sleeperize_prompt(*pool[p], 6);
		r.recruit->hireid = pool[p]->id;
		pool[p]->train(SKILL_PERSUASION, 25);
		r.recruit->addCreature();
		r.recruit = NULL;
		stat_recruits++;
		return RETURN_ONE;
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
		strcpy(str, blankString.c_str());
		if (c == 'a')
		{
			difficulty -= 5;
			mvaddstrAlt(y++, 0, pool[p]->getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_creaturePool032, gamelog);
			getissueeventstring(str);
			addstrAlt(str, gamelog);
			addstrAlt(singleDot, gamelog);
			gamelog.newline();
			pressAnyKey();
		}
		else
		{
			mvaddstrAlt(y++, 0, pool[p]->getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_creaturePool033, gamelog);
			addstrAlt(pool[p]->hisher(), gamelog);
			addstrAlt(CONST_creaturePool034, gamelog);
			addstrAlt(getview(LCSrandom(VIEWNUM - 3), true), gamelog);
			addstrAlt(singleDot, gamelog);
			gamelog.newline();
			pressAnyKey();
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
			//if (r.level < 127) r.level++;
			if (r.eagerness1 < 127) r.eagerness1++;
			mvaddstrAlt(y++, 0, r.recruit->getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_creaturePool035, gamelog);
			addstrAlt(pool[p]->getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_creaturePool036, gamelog);
			gamelog.newline();
			mvaddstrAlt(y++, 0, CONST_creaturePool037, gamelog);
			gamelog.nextMessage();
		}
		else if (pool[p]->skill_check(SKILL_PERSUASION, difficulty)) // Second chance to not fail horribly
		{
			//if (r.level < 127) r.level++;
			if (r.eagerness1 > -128) r.eagerness1--;
			mvaddstrAlt(y++, 0, r.recruit->getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_creaturePool038, gamelog);
			addstrAlt(pool[p]->getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_creaturePool039, gamelog);
			gamelog.newline();
			mvaddstrAlt(y++, 0, CONST_creaturePool040, gamelog);
			gamelog.nextMessage();
		}
		else
		{
			set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
			moveAlt(y++, 0);
			if (r.recruit->talkreceptive() && r.recruit->align == ALIGN_LIBERAL)
			{
				addstrAlt(r.recruit->getNameAndAlignment().name, gamelog);
				addstrAlt(CONST_creaturePool041, gamelog);
				addstrAlt(pool[p]->getNameAndAlignment().name, gamelog);
				addstrAlt(CONST_creaturePool042, gamelog);
				gamelog.newline();
				mvaddstrAlt(y++, 0, CONST_creaturePool043, gamelog);
				addstrAlt(pool[p]->getNameAndAlignment().name, gamelog);
				addstrAlt(CONST_creaturePool044, gamelog);
				gamelog.nextMessage();
			}
			else
			{
				addstrAlt(pool[p]->getNameAndAlignment().name, gamelog);
				addstrAlt(CONST_creaturePool045, gamelog);
				gamelog.newline();
				mvaddstrAlt(y++, 0, CONST_creaturePool046, gamelog);
				gamelog.nextMessage();
			}
			pressAnyKey();
			return RETURN_ONE;
		}
		pressAnyKey();
		return RETURN_ZERO;
	}
	if (c == 'd') return RETURN_ONE;
	return REPEAT;
}
const string CONST_creaturePool028 = "D - Break off the meetings.";
const string CONST_creaturePool027 = " isn't ready to join the LCS.";
const string CONST_creaturePool026 = "C - ";
const string CONST_creaturePool025 = " needs more Juice to recruit.";
const string CONST_creaturePool023 = " join the LCS as a full member.";
const string CONST_creaturePool022 = "C - Offer to let ";
const string CONST_creaturePool021 = "B - Just casually chat with them and discuss politics.";
const string CONST_creaturePool020 = "A - Spend $50 on props and a book for them to keep afterward.";
const string CONST_creaturePool019 = " approach the situation?";
const string CONST_creaturePool018 = "How should ";
const string CONST_creaturePool017 = " kind of regrets agreeing to this.";
const string CONST_creaturePool016 = " is ready to fight for the Liberal Cause.";
const string CONST_creaturePool015 = " feels something needs to be done.";
const string CONST_creaturePool014 = " is interested in learning more.";
const string CONST_creaturePool013 = " will take a lot of persuading.";
const string CONST_creaturePool012 = "Meeting with ";
void printrecruitmeeting(Deprecatedrecruitst &r, const int p) {

	extern Log gamelog;
	extern class Ledger ledger;

	addstrAlt(CONST_creaturePool012, gamelog);
	addstrAlt(r.recruit->getNameAndAlignment().name, gamelog);
	addstrAlt(commaSpace, gamelog);
	addstrAlt(r.recruit->get_type_name(), gamelog);
	addstrAlt(commaSpace, gamelog);
	addstrAlt(LocationsPool::getInstance().getLocationName(r.recruit->location), gamelog);
	gamelog.newline();
	set_color_easy(WHITE_ON_BLACK);
	printfunds();
	r.recruit->printcreatureinfo();
	makedelimiter();
	mvaddstrAlt(10, 0, r.recruit->getNameAndAlignment().name);
	switch (r.eagerness())
	{
	case 1: addstrAlt(CONST_creaturePool013); break;
	case 2: addstrAlt(CONST_creaturePool014); break;
	case 3: addstrAlt(CONST_creaturePool015); break;
	default: if (r.eagerness() >= 4) addstrAlt(CONST_creaturePool016);
			 else addstrAlt(CONST_creaturePool017); break;
	}
	mvaddstrAlt(11, 0, CONST_creaturePool018);
	addstrAlt(pool[p]->getNameAndAlignment().name);
	addstrAlt(CONST_creaturePool019);
	moveAlt(13, 0);
	if (ledger.get_funds() < 50) set_color_easy(BLACK_ON_BLACK_BRIGHT);
	addstrAlt(CONST_creaturePool020);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(14, 0, CONST_creaturePool021);
	moveAlt(15, 0);
	if (pool[p]->subordinatesleft() && r.eagerness() >= 4)
	{
		addstrAlt(CONST_creaturePool022);
		addstrAlt(r.recruit->getNameAndAlignment().name);
		addstrAlt(CONST_creaturePool023);
	}
	else if (!pool[p]->subordinatesleft())
	{
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		addstrAlt(CONST_creaturePool026);
		addstrAlt(pool[p]->getNameAndAlignment().name);
		addstrAlt(CONST_creaturePool025);
		set_color_easy(WHITE_ON_BLACK);
	}
	else
	{
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		addstrAlt(CONST_creaturePool026);
		addstrAlt(r.recruit->getNameAndAlignment().name);
		addstrAlt(CONST_creaturePool027);
		set_color_easy(WHITE_ON_BLACK);
	}
	mvaddstrAlt(16, 0, CONST_creaturePool028);
}
/* daily - recruit - recruit meeting */
char completerecruitmeeting(Deprecatedrecruitst &r, const int p)
{
	const string CONST_creaturePool011 = "!";
	const string CONST_creaturePool010 = "Get it together, ";
	const string CONST_creaturePool009 = "due to multiple booking of recruitment sessions.";
	const string CONST_creaturePool008 = " accidentally missed the meeting with ";

	extern MusicClass music;
	extern Log gamelog;
	music.play(MUSIC_RECRUITING);
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	moveAlt(0, 0);
	if (pool[p]->meetings++ > 5 && LCSrandom(pool[p]->meetings - 5))
	{
		addstrAlt(pool[p]->getNameAndAlignment().name, gamelog);
		addstrAlt(CONST_creaturePool008, gamelog);
		addstrAlt(r.recruit->getNameAndAlignment().name, gamelog);
		mvaddstrAlt(1, 0, CONST_creaturePool009, gamelog);
		gamelog.newline();
		mvaddstrAlt(3, 0, CONST_creaturePool010, gamelog);
		addstrAlt(pool[p]->getNameAndAlignment().name, gamelog);
		addstrAlt(CONST_creaturePool011, gamelog);
		gamelog.nextMessage();
		pressAnyKey();
		return 1;
	}
	printrecruitmeeting(r, p);
	int y = 18;
	while (true)
	{
		LOOP_CONTINUATION next_loop = increment_completerecruitmeeting(p, r, y);
		if (next_loop != REPEAT) {
			if (next_loop == RETURN_ONE) {
				return 1;
			}
			else if (next_loop == RETURN_ZERO) {
				return 0;
			}
		}
	}
}
vector<DeprecatedCreature *> DeprecatedCreature::findAllTendersToThisHostage() {
	vector<DeprecatedCreature *> temppool;
	//Find all tenders who are set to this hostage
	for (int p = 0; p < len(pool); p++)
	{
		if (!pool[p]->getNameAndAlignment().alive) continue;
		if (pool[p]->activity_type() == ACTIVITY_HOSTAGETENDING && pool[p]->activity_arg() == id)
		{
			//If they're in the same location as the hostage,
			//include them in the InterrogationST
			if (pool[p]->location == location&&pool[p]->location != -1)
				temppool.push_back(pool[p]);
			//If they're someplace else, take them off the job
			else pool[p]->set_activity(ACTIVITY_NONE);
		}
	}
	return temppool;
}
void DeprecatedCreature::hostageEscapes(const char clearformess) {
	const string CONST_creaturePool047 = " has escaped!";
	extern Log gamelog;
	for (int p = 0; p < len(pool); p++)
	{
		if (pool[p] == this)
		{
			if (clearformess) eraseAlt();
			else makedelimiter();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 1, getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_creaturePool047, gamelog);
			gamelog.nextMessage();
			LocationsPool::getInstance().setTimeUntilSiege(location, 3);
			pressAnyKey();
			//clear activities for tenders
			for (int i = 0; i < len(pool); i++)
			{
				if (!pool[i]->getNameAndAlignment().alive) continue;
				if (pool[i]->activity_type() == ACTIVITY_HOSTAGETENDING && pool[i]->activity_arg() == id)
					pool[i]->set_activity(ACTIVITY_NONE);
			}
			delete_and_remove(pool, p);
			break;
		}
	}
}
void setAllCreatureActivities(Activity cr, vector<DeprecatedCreature *>& temppool) {
	for (int p = 0; p < len(temppool); p++) {
		temppool[p]->set_activity(cr);
	}
}
DeprecatedCreature::~DeprecatedCreature()
{
	delete weapon;
	delete armor;
	delete_and_clear(clips);
	delete_and_clear(extra_throwing_weapons);
	if (prisoner)
	{
		for (int p = 0; p < len(pool); p++)
			if (prisoner == pool[p]) { delete_and_remove(pool, p); break; }
	}
	// Clean up hostage situation
	stop_hauling_me();
}
void DeprecatedCreature::stop_hauling_me()
{
	for (int p = 0; p < len(pool); p++) if (pool[p]->prisoner == this) pool[p]->prisoner = NULL;
}
bool DeprecatedCreature::enemy() const
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
#include "../common/translateid.h"
// for  int getpoolcreature(int)
vector<DeprecatedCreature *> selectOnlySleepersThatCanWork() {
	vector<DeprecatedCreature *> temppool;
	// Comb the pool of Liberals for sleeper agents
	for (int p = 0; p < len(pool); p++)
	{
		// Select only sleepers that can work
		if (pool[p]->getNameAndAlignment().alive == true &&
			pool[p]->flag & CREATUREFLAG_SLEEPER&&
			pool[p]->align == ALIGN_LIBERAL &&
			pool[p]->hiding == false &&
			pool[p]->clinic == false &&
			pool[p]->dating == false)
		{
			temppool.push_back(pool[p]);
		}
	}
	return temppool;
}
#include "../daily/siege.h"
void determineMedicalSupportAtEachLocation(const bool clearformess) {
	const string CONST_creaturePool049 = "'s injuries require professional treatment.";
	const string CONST_creaturePool048 = " has died of injuries.";
	extern Log gamelog;
	extern char disbanding;
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
	if (!disbanding) for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (!pool[p]->getNameAndAlignment().alive) continue;
		if (pool[p]->hiding) continue;
		if (pool[p]->flag&CREATUREFLAG_SLEEPER) continue;
		// People will help heal even if they aren't specifically assigned to do so
		// Having a specific healing activity helps bookkeeping for the player, though
		// Only the highest medical skill is considered
		if (pool[p]->activity_type() == ACTIVITY_HEAL || pool[p]->activity_type() == ACTIVITY_NONE)
			if (pool[p]->location > -1 &&
				healing[pool[p]->location] < pool[p]->get_skill(SKILL_FIRSTAID))
			{
				healing[pool[p]->location] = pool[p]->get_skill(SKILL_FIRSTAID);
				pool[p]->set_activity(ACTIVITY_HEAL);
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
		if (!(pool[p]->getNameAndAlignment().alive)) continue;
		if (pool[p]->clinictime())
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
				if (pool[p]->blood < 100 - (pool[p]->clinictime() - 1) * 20)
				{
					// Add health
					if (pool[p]->location > -1)pool[p]->blood += 1 + healing[pool[p]->location] / 3;
					if (pool[p]->blood > 100 - (pool[p]->clinictime() - 1) * 20)
						pool[p]->blood = 100 - (pool[p]->clinictime() - 1) * 20;
					if (pool[p]->blood > 100)
						pool[p]->blood = 100;
				}
				if (pool[p]->getNameAndAlignment().alive&&pool[p]->blood < 0)
				{
					if (clearformess) eraseAlt();
					else makedelimiter();
					pool[p]->die();
					mvaddstrAlt(8, 1, pool[p]->getNameAndAlignment().name, gamelog);
					addstrAlt(CONST_creaturePool048, gamelog);
					gamelog.nextMessage();
				}
				for (int w = 0; w < BODYPARTNUM; w++)
				{
					// Limbs blown off
					if (pool[p]->wound[w] & WOUND_NASTYOFF)
					{
						// Chance to stabilize/amputate wound
						// Difficulty 12 (Will die if not treated)
						if (pool[p]->location > -1 && healing[pool[p]->location] + LCSrandom(10) > 12)
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
					pool[p]->getNameAndAlignment().alive == 1 &&
					pool[p]->align == 1 &&
					LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE,pool[p]->location) != RENTING_NOCONTROL &&
					LocationsPool::getInstance().getLocationType(pool[p]->location) != SITE_HOSPITAL_UNIVERSITY)
				{
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8, 1, pool[p]->getNameAndAlignment().name, gamelog);
					addstrAlt(CONST_creaturePool049, gamelog);
					gamelog.nextMessage();
					pool[p]->set_activity(ACTIVITY_CLINIC);
					pressAnyKey();
				}
			}
		}
	}
	//Give experience to medics
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		//If present, qualified to heal, and doing so
		if (pool[p]->location >= 0 && pool[p]->activity_type() == ACTIVITY_HEAL)
		{
			//Clear activity if their location doesn't have healing work to do
			if (healing2[pool[p]->location] == 0)
				pool[p]->set_activity(ACTIVITY_NONE);
			//Give experience based on work done and current skill
			else
				pool[p]->train(SKILL_FIRSTAID, max(0, healing2[pool[p]->location] / 5 - pool[p]->get_skill(SKILL_FIRSTAID) * 2));
		}
	}
	delete[] healing;
	delete[] healing2;
}
/* promote a subordinate to maintain chain of command when boss is lost */
bool DeprecatedCreature::promotesubordinates(const char clearformess)
{
	const string CONST_creaturePool057 = " is the new leader of the Liberal Crime Squad!";
	const string CONST_creaturePool056 = " has died.";
	const string CONST_creaturePool055 = " in the command chain.";
	const string CONST_creaturePool054 = " will take over for ";
	const string CONST_creaturePool053 = "due to the death of ";
	const string CONST_creaturePool052 = " has promoted ";
	const string CONST_creaturePool051 = "There are none left with the courage and conviction to lead....";
	extern Log gamelog;
	int newboss = -1;
	int bigboss = -2;
	if (hireid == -1)bigboss = -1;//Special: Founder
	int maxjuice = 0; //Need more than 0 juice to get promoted
	int subordinates = 0;
	//Need REVOLUTIONARY (100+) juice to take over founder role
	if (hireid == -1)maxjuice = 99;
	//Identify big boss and top subordinate
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (pool[p]->id == id)continue;
		if (pool[p]->id == hireid)bigboss = p;
		if (pool[p]->hireid == id && pool[p]->getNameAndAlignment().alive && pool[p]->align == 1)
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
			if (pool[p]->juice > maxjuice &&
				!(pool[p]->flag & CREATUREFLAG_SLEEPER) &&
				(pool[p]->location == -1 ||
				(LocationsPool::getInstance().getLocationType(pool[p]->location) != SITE_GOVERNMENT_PRISON || pool[p]->getCreatureJustice().sentence >= 0)))
			{
				maxjuice = pool[p]->juice;
				newboss = p;
			}
		}
	}
	//No subordinates or none with sufficient juice to carry on
	if (subordinates == 0 || newboss == -1)
	{
		if (hireid != -1)return 0;
		if (subordinates > 0) // Disintegration of the LCS
		{
			if (clearformess) eraseAlt();
			else makedelimiter();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 1, getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_creaturePool056, gamelog);
			gamelog.newline();
			pressAnyKey();
			mvaddstrAlt(10, 1, CONST_creaturePool051, gamelog);
			gamelog.nextMessage();
			pressAnyKey();
		}
		return 0;
	}
	//Chain of command totally destroyed if dead person's boss also dead
	if (bigboss == -2 || (hireid != -1 && bigboss != -1 && !pool[bigboss]->getNameAndAlignment().alive))return 0;
	//Promote the new boss
	pool[newboss]->hireid = hireid;
	//Order secondary subordinates to follow the new boss
	if (subordinates > 1)
	{
		for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
		{
			if (pool[p]->hireid == id && // recruited by old boss that died
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
		mvaddstrAlt(8, 1, pool[bigboss]->getNameAndAlignment().name, gamelog);
		addstrAlt(CONST_creaturePool052, gamelog);
		addstrAlt(pool[newboss]->getNameAndAlignment().name, gamelog);
		mvaddstrAlt(9, 1, CONST_creaturePool053, gamelog);
		addstrAlt(getNameAndAlignment().name, gamelog);
		addstrAlt(singleDot, gamelog);
		if (subordinates > 1)
		{
			gamelog.newline();
			mvaddstrAlt(11, 1, pool[newboss]->getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_creaturePool054, gamelog);
			addstrAlt(getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_creaturePool055, gamelog);
		}
		gamelog.nextMessage();
		pressAnyKey();
	}
	else // Founder level promotion
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8, 1, getNameAndAlignment().name, gamelog);
		addstrAlt(CONST_creaturePool056, gamelog);
		gamelog.newline();
		pressAnyKey();
		mvaddstrAlt(10, 1, pool[newboss]->getNameAndAlignment().name, gamelog);
		addstrAlt(CONST_creaturePool057, gamelog);
		gamelog.nextMessage();
		pressAnyKey();
		hireid = -2; // Make dead founder not founder.
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
#include "../common/commonactions.h"
/* squad members with no chain of command lose contact */
void dispersalcheck(const char clearformess)
{
	const string CONST_creaturePool061 = " has lost touch with the Liberal Crime Squad.";
	const string CONST_creaturePool060 = " has abandoned the LCS.";
	const string CONST_creaturePool059 = "The Liberal has gone into hiding...";
	extern Log gamelog;
	extern char disbanding;

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
			for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
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
				if (!pool[p]->getNameAndAlignment().alive && !disbanding)
				{
					dispersal_status[p] = DISPERSAL_SAFE;
					//Attempt to promote their subordinates
					if (pool[p]->promotesubordinates(clearformess)) promotion = 1;
					if (pool[p]->location == -1 || LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE,pool[p]->location) == RENTING_NOCONTROL)
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
			for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
			{
				if (!pool[p]->getNameAndAlignment().alive) continue;
				if (pool[p]->location != -1 &&
					LocationsPool::getInstance().getLocationType(pool[p]->location) == SITE_GOVERNMENT_PRISON &&
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
						if (pool[p2]->hireid == pool[p]->id && pool[p2]->getNameAndAlignment().alive)
						{
							dispersal_status[p2] = DISPERSAL_BOSSINHIDING; // Mark them as unreachable
							changed = 1; // Need another iteration
						}
					}
				}
				// If in prison or unreachable due to a member of the command structure
				// above being in prison
				else if ((dispersal_status[p] == DISPERSAL_BOSSSAFE && inprison) || dispersal_status[p] == DISPERSAL_BOSSINPRISON)
				{
					int dispersalval = DISPERSAL_SAFE;
					if (pool[p]->flag&CREATUREFLAG_LOVESLAVE)
					{
						if ((dispersal_status[p] == DISPERSAL_BOSSINPRISON && !inprison) ||
							(dispersal_status[p] == DISPERSAL_BOSSSAFE && inprison))
						{
							pool[p]->juice--; // Love slaves bleed juice when not in prison with their lover
							if (pool[p]->juice < -50) dispersalval = DISPERSAL_ABANDONLCS;
						}
					}
					dispersal_status[p] = dispersalval; // Guaranteed contactable in prison
														// Find all subordinates
					for (int p2 = CreaturePool::getInstance().lenpool() - 1; p2 >= 0; p2--)
					{
						if (pool[p2]->hireid == pool[p]->id && pool[p2]->getNameAndAlignment().alive)
						{
							if (inprison) dispersal_status[p2] = DISPERSAL_BOSSINPRISON;
							else dispersal_status[p2] = DISPERSAL_BOSSSAFE;
							changed = 1; // Need another iteration
						}
					}
				}
				// Otherwise, if they're reachable
				else if (dispersal_status[p] == DISPERSAL_BOSSSAFE && !inprison)
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
		for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
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
						mvaddstrAlt(8, 1, pool[p]->getNameAndAlignment().name, gamelog);
						addstrAlt(CONST_creaturePool061, gamelog);
						gamelog.nextMessage();
						pressAnyKey();
						set_color_easy(GREEN_ON_BLACK_BRIGHT);
						mvaddstrAlt(9, 1, CONST_creaturePool059, gamelog);
						gamelog.nextMessage();
						pressAnyKey();
					}
					else if (dispersal_status[p] == DISPERSAL_ABANDONLCS)
					{
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(8, 1, pool[p]->getNameAndAlignment().name, gamelog);
						addstrAlt(CONST_creaturePool060, gamelog);
						gamelog.nextMessage();
						pressAnyKey();
					}
					else if (dispersal_status[p] == DISPERSAL_NOCONTACT)
					{
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(8, 1, pool[p]->getNameAndAlignment().name, gamelog);
						addstrAlt(CONST_creaturePool061, gamelog);
						gamelog.nextMessage();
						pressAnyKey();
					}
				}
				pool[p]->removesquadinfo();
				if (dispersal_status[p] == DISPERSAL_NOCONTACT || dispersal_status[p] == DISPERSAL_ABANDONLCS)
					delete_and_remove(pool, p);
				else
				{
					pool[p]->location = -1;
					if (!(pool[p]->flag & CREATUREFLAG_SLEEPER)) //Sleepers end up in shelter otherwise.
						pool[p]->base = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, pool[p]->location);
					pool[p]->set_activity(ACTIVITY_NONE);
					pool[p]->hiding = -1; // Hide indefinitely
				}
			}
		}
	}
	//MUST DO AN END OF GAME CHECK HERE BECAUSE OF DISPERSAL
	endcheck(END_DISPERSED);
	cleangonesquads();
}
extern vector<Deprecatedsquadst *> squad;
vector<DeprecatedCreature *> activatable_liberals()
{
	vector<DeprecatedCreature *> temppool;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (pool[p]->is_active_liberal())
		{
			if (pool[p]->squadid != -1)
			{
				int sq = getsquad(pool[p]->squadid);
				if (sq != -1) if (squad[sq]->activity.type != ACTIVITY_NONE) continue;
			}
			temppool.push_back(pool[p]);
		}
	}
	return temppool;
}
vector<DeprecatedCreature *> DeprecatedCreature::getLiberalsSharingLocation() {
	vector<DeprecatedCreature *> temppool;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++) {
		if (pool[p] == this) continue;
		if (pool[p]->is_active_liberal() && (pool[p]->location == location))
		{
			temppool.push_back(pool[p]);
		}
	}
	return temppool;
}
vector<DeprecatedCreature *> DeprecatedCreature::getHostagesSharingLocation() {
	vector<DeprecatedCreature *> temppool;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (pool[p]->align != 1 &&
			pool[p]->getNameAndAlignment().alive&&
			pool[p]->location == location)
		{
			temppool.push_back(pool[p]);
		}
	}
	return temppool;
}
int DeprecatedCreature::countHostagesSharingLocation() const {
	int hostagecount = 0;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (pool[p]->getNameAndAlignment().alive&&pool[p]->align != 1 && pool[p]->location == location) hostagecount++;
	}
	return hostagecount;
}
int DeprecatedCreature::countDeadSharingLocation()const {
	int havedead = 0;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (!pool[p]->getNameAndAlignment().alive && pool[p]->location == location) havedead++;
	}
	return havedead;
}
string getSleeperBouncerName(short cursite) {
	string output = blankString;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (pool[p]->base == cursite && pool[p]->type == CREATURE_BOUNCER)
		{
			output = pool[p]->getNameAndAlignment().name;
			break;
		}
	}
	return output;
}
string getSleeperSecurityName(short cursite, int type) {
	string name = blankString;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (pool[p]->base == cursite)
		{
			if (pool[p]->type == type)
			{
				name = pool[p]->getNameAndAlignment().name;
				break;
			}
		}
	}
	return name;
}
char doWeHaveASleeperHere(short cursite) {
	char autoadmit = 0;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (pool[p]->base == cursite)
		{
			autoadmit = 1;
		}
	}
	return autoadmit;
}
string getSleeperBankerName(short cursite) {
	string output = blankString;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (pool[p]->type == CREATURE_BANK_MANAGER &&
			pool[p]->flag & CREATUREFLAG_SLEEPER &&
			pool[p]->base == cursite)
		{
			output = pool[p]->getNameAndAlignment().name;
			break;
		}
	}
	return output;
}
string haveSleeperBankerCrackSafe(short cursite, int base) {
	string output = blankString;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (pool[p]->base == cursite && pool[p]->type == CREATURE_BANK_MANAGER)
		{
			output = pool[p]->getNameAndAlignment().name;
			pool[p]->location = pool[p]->base = base;
			pool[p]->flag &= ~CREATUREFLAG_SLEEPER;
			pool[p]->set_activity(ACTIVITY_NONE);
			pool[p]->criminalize_without_heat(LAWFLAG_BANKROBBERY);
			break;
		}
	}
	return output;
}
//#include "../monthly/justice.h"
void DeprecatedCreature::monthlyRunTheSystem() {
	const string CONST_creaturePool069 = " is moved to the courthouse for trial.";
	const string CONST_creaturePool068 = "The traitor will testify in court, and safehouses may be compromised.";
	const string CONST_creaturePool067 = " has broken under the pressure and ratted you out!";
	const string CONST_creaturePool066 = "deportation.";
	const string CONST_creaturePool065 = "execution.";
	const string CONST_creaturePool064 = " has been shipped out to the INS to face ";
	const string CONST_creaturePool063 = "'s mind with Conservatism!";
	const string CONST_creaturePool062 = "Cops re-polluted ";
	extern Log gamelog;
	extern short lawList[LAWNUM];
	for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
	{
		if (!pool[p]->getNameAndAlignment().alive) continue;
		if (pool[p]->flag & CREATUREFLAG_SLEEPER) continue;
		if (pool[p]->location == -1) continue;
		if (LocationsPool::getInstance().getLocationType(pool[p]->location) == SITE_GOVERNMENT_POLICESTATION)
		{
			eraseAlt();
			if (pool[p]->flag & CREATUREFLAG_MISSING)
			{
				set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
				mvaddstrAlt(8, 1, CONST_creaturePool062, gamelog);
				addstrAlt(pool[p]->getNameAndAlignment().name, gamelog);
				addstrAlt(CONST_creaturePool063, gamelog);
				gamelog.nextMessage();
				pressAnyKey();
				pool[p]->removesquadinfo();
				delete_and_remove(pool, p);
				continue;
			}
			else if (pool[p]->flag & CREATUREFLAG_ILLEGALALIEN && lawList[LAW_IMMIGRATION] != 2)
			{
				set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
				mvaddstrAlt(8, 1, pool[p]->getNameAndAlignment().name, gamelog);
				addstrAlt(CONST_creaturePool064, gamelog);
				if (lawList[LAW_IMMIGRATION] == -2 && lawList[LAW_DEATHPENALTY] == -2)
					addstrAlt(CONST_creaturePool065, gamelog);
				else addstrAlt(CONST_creaturePool066, gamelog);
				gamelog.newline();
				pressAnyKey();
				pool[p]->removesquadinfo();
				delete_and_remove(pool, p);
				continue;
			}
			else
			{
				//TRY TO GET RACKETEERING CHARGE
				int copstrength = 100;
				if (lawList[LAW_POLICEBEHAVIOR] == -2) copstrength = 200;
				if (lawList[LAW_POLICEBEHAVIOR] == -1) copstrength = 150;
				if (lawList[LAW_POLICEBEHAVIOR] == 1) copstrength = 75;
				if (lawList[LAW_POLICEBEHAVIOR] == 2) copstrength = 50;
				copstrength = (copstrength*pool[p]->heat) / 4;
				if (copstrength > 200)copstrength = 200;
				//Confession check
				if (LCSrandom(copstrength) > pool[p]->juice + pool[p]->get_attribute(ATTRIBUTE_HEART, true) * 5 -
					pool[p]->get_attribute(ATTRIBUTE_WISDOM, true) * 5 + pool[p]->get_skill(SKILL_PSYCHOLOGY) * 5
					/*+ pool[p]->get_skill(SKILL_SURVIVAL)*5*/ && pool[p]->hireid != -1)
				{
					int p2 = getpoolcreature(pool[p]->hireid);
					if (pool[p2]->getNameAndAlignment().alive && (pool[p2]->location == -1 || LocationsPool::getInstance().getLocationType(pool[p2]->location) != SITE_GOVERNMENT_PRISON))
					{  //Charge the boss with racketeering!
						pool[p2]->criminalize( LAWFLAG_RACKETEERING);
						//Rack up testimonies against the boss in court!
						pool[p2]->another_confession();
					}
					//Issue a raid on this guy's base!
					if (pool[p]->base >= 0)LocationsPool::getInstance().addHeat(pool[p]->base, 300);
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8, 1, pool[p]->getNameAndAlignment().name, gamelog);
					addstrAlt(CONST_creaturePool067, gamelog);
					gamelog.newline();
					pressAnyKey();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(9, 1, CONST_creaturePool068, gamelog);
					gamelog.nextMessage();
					pressAnyKey();
					pool[p]->removesquadinfo();
					delete_and_remove(pool, p);
					continue; //no trial for this person; skip to next person

				}
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8, 1, pool[p]->getNameAndAlignment().name, gamelog);
				addstrAlt(CONST_creaturePool069, gamelog);
				gamelog.nextMessage();
				pressAnyKey();
				pool[p]->location = find_site_index_in_same_city(SITE_GOVERNMENT_COURTHOUSE, pool[p]->location);
				Armor prisoner(getarmortype(tag_ARMOR_PRISONER));
				pool[p]->give_armor(prisoner, NULL);
			}
		}
		else if (LocationsPool::getInstance().getLocationType(pool[p]->location) == SITE_GOVERNMENT_COURTHOUSE)
		{
			pool[p]->trial();
		}
		else if (LocationsPool::getInstance().getLocationType(pool[p]->location) == SITE_GOVERNMENT_PRISON)
		{
			pool[p]->prison();
		}
	}
}
void monthlyRunExecutions() {
	for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
	{
		if (pool[p]->location == -1) continue;
		if (LocationsPool::getInstance().getLocationType(pool[p]->location) == SITE_GOVERNMENT_PRISON && !pool[p]->getNameAndAlignment().alive)
		{
			pool[p]->removesquadinfo();
			pool[p]->die();
			pool[p]->location = -1;
		}
	}
}
void monthlyRunHealClinicPeople() {
	const string CONST_creaturePool071 = " has left ";
	const string CONST_creaturePool070 = " has been transferred to ";
	extern Log gamelog;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (!(pool[p]->getNameAndAlignment().alive)) continue;
		if (pool[p]->clinic > 0)
		{
			pool[p]->clinic--;
			for (int w = 0; w < BODYPARTNUM; w++)
			{
				if ((pool[p]->wound[w] & WOUND_NASTYOFF) || (pool[p]->wound[w] & WOUND_CLEANOFF))
					pool[p]->wound[w] = (char)WOUND_CLEANOFF;
				else pool[p]->wound[w] = 0;
			}
			int healthdamage = 0;
			if (pool[p]->special[SPECIALWOUND_RIGHTLUNG] != 1)
			{
				pool[p]->special[SPECIALWOUND_RIGHTLUNG] = 1;
				if (LCSrandom(2)) healthdamage++;
			}
			if (pool[p]->special[SPECIALWOUND_LEFTLUNG] != 1)
			{
				pool[p]->special[SPECIALWOUND_LEFTLUNG] = 1;
				if (LCSrandom(2)) healthdamage++;
			}
			if (pool[p]->special[SPECIALWOUND_HEART] != 1)
			{
				pool[p]->special[SPECIALWOUND_HEART] = 1;
				if (LCSrandom(3)) healthdamage++;
			}
			pool[p]->special[SPECIALWOUND_LIVER] = 1;
			pool[p]->special[SPECIALWOUND_STOMACH] = 1;
			pool[p]->special[SPECIALWOUND_RIGHTKIDNEY] = 1;
			pool[p]->special[SPECIALWOUND_LEFTKIDNEY] = 1;
			pool[p]->special[SPECIALWOUND_SPLEEN] = 1;
			pool[p]->special[SPECIALWOUND_RIBS] = RIBNUM;
			if (!pool[p]->special[SPECIALWOUND_NECK])
				pool[p]->special[SPECIALWOUND_NECK] = 2;
			if (!pool[p]->special[SPECIALWOUND_UPPERSPINE])
				pool[p]->special[SPECIALWOUND_UPPERSPINE] = 2;
			if (!pool[p]->special[SPECIALWOUND_LOWERSPINE])
				pool[p]->special[SPECIALWOUND_LOWERSPINE] = 2;
			// Inflict permanent health damage
			pool[p]->set_attribute(ATTRIBUTE_HEALTH, pool[p]->get_attribute(ATTRIBUTE_HEALTH, 0) - healthdamage);
			if (pool[p]->get_attribute(ATTRIBUTE_HEALTH, 0) <= 0)
				pool[p]->set_attribute(ATTRIBUTE_HEALTH, 1);
			if (pool[p]->blood <= 20 && pool[p]->clinic <= 2)pool[p]->blood = 50;
			if (pool[p]->blood <= 50 && pool[p]->clinic <= 1)pool[p]->blood = 75;
			// If at clinic and in critical condition, transfer to university hospital
			if (pool[p]->clinic > 2 &&
				pool[p]->location > -1 &&
				LocationsPool::getInstance().getLocationType(pool[p]->location) == SITE_HOSPITAL_CLINIC)
			{
				int hospital = find_site_index_in_same_city(SITE_HOSPITAL_UNIVERSITY, pool[p]->location);
				if (hospital != -1)
				{
					pool[p]->location = hospital;
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8, 1, pool[p]->getNameAndAlignment().name, gamelog);
					addstrAlt(CONST_creaturePool070, gamelog);
					addstrAlt(LocationsPool::getInstance().getLocationName(hospital), gamelog);
					addstrAlt(singleDot, gamelog);
					gamelog.nextMessage();
					pressAnyKey();
				}
			}
			// End treatment
			if (pool[p]->clinic == 0)
			{
				pool[p]->blood = 100;
				eraseAlt();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8, 1, pool[p]->getNameAndAlignment().name, gamelog);
				addstrAlt(CONST_creaturePool071, gamelog);
				addstrAlt(LocationsPool::getInstance().getLocationName(pool[p]->location), gamelog);
				addstrAlt(singleDot, gamelog);
				gamelog.nextMessage();
				int hs = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, pool[p]->location);
				if (hs == -1) hs = 0; //TODO: Error unable to find location
				if (LocationsPool::getInstance().isThereASiegeHere(pool[p]->base) ||
					LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE,pool[p]->base) == RENTING_NOCONTROL)
					pool[p]->base = hs;
				pool[p]->location = pool[p]->base;
				pressAnyKey();
			}
		}
	}
}
//#include "../monthly/sleeper_update.h"
void havingSleepers(char canseethings, int(&libpower)[VIEWNUM]) {
	for (int pl = CreaturePool::getInstance().lenpool() - 1; pl > 0; pl--) {
		if (pool[pl]->getNameAndAlignment().alive && (pool[pl]->flag & CREATUREFLAG_SLEEPER)) {
			pool[pl]->sleepereffect(canseethings, libpower);
		}
	}
}
void giveSeductionExperienceToLoveSlaves() {
	for (int s = 0; s < CreaturePool::getInstance().lenpool(); s++)
	{
		pool[s]->train(SKILL_SEDUCTION, pool[s]->loveslaves() * 5);
		if (pool[s]->flag & CREATUREFLAG_LOVESLAVE)
			pool[s]->train(SKILL_SEDUCTION, 5);
	}
}

void DeprecatedCreature::dejuiceBoss() {
	int boss = getpoolcreature(hireid);
	if (boss != -1 && pool[boss]->juice > 50)
	{
		int juice = this->juice / 10;
		if (juice < 5) juice = 5;
		pool[boss]->add_juice(-juice, 0);
	}
}

DeprecatedCreature * DeprecatedCreature::getSleeperJudge() {
	DeprecatedCreature * sleeperjudge = NULL;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
		if (pool[p]->getNameAndAlignment().alive && (pool[p]->flag&CREATUREFLAG_SLEEPER) && LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONCITY,pool[p]->location) == LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONCITY,location))
		{
			if (pool[p]->type == CREATURE_JUDGE_CONSERVATIVE || pool[p]->type == CREATURE_JUDGE_LIBERAL)
				if (pool[p]->infiltration * 100 >= LCSrandom(100)) sleeperjudge = pool[p];
		}
	return sleeperjudge;
}
DeprecatedCreature * DeprecatedCreature::getSleeperLawyer() {
	int maxsleeperskill = 0;
	DeprecatedCreature * sleeperlawyer = NULL;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
		if (pool[p]->getNameAndAlignment().alive && (pool[p]->flag&CREATUREFLAG_SLEEPER) && LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONCITY,pool[p]->location) == LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONCITY,location))
		{
			if (pool[p]->type == CREATURE_LAWYER)
				if (pool[p]->get_skill(SKILL_LAW) + pool[p]->get_skill(SKILL_PERSUASION) >= maxsleeperskill)
				{
					sleeperlawyer = pool[p];
					maxsleeperskill = pool[p]->get_skill(SKILL_LAW) + sleeperlawyer->get_skill(SKILL_PERSUASION);
				}
		}
	return sleeperlawyer;
}

int DeprecatedCreature::otherPrisonersEscapeWithMe(int prison) {
	int num_escaped = 0;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (pool[p]->location == prison && !(pool[p]->flag & CREATUREFLAG_SLEEPER))
		{
			pool[p]->criminalize( LAWFLAG_ESCAPED);
			pool[p]->location = location;
			num_escaped++;
		}
	}
	return num_escaped;
}

/* transforms a creature id number into the index of that person in the pool */
int getpoolcreature(int id)
{
	for (int i = 0; i < CreaturePool::getInstance().lenpool(); i++) if (pool[i]->id == id) return i;
	return -1;
}

void savehighscore(char endtype);
void viewhighscores(int musicoverride = MUSIC_OFF);
void end_game(int err = EXIT_SUCCESS);
short getCurrentSite();
/* common - test for possible game over */
char endcheck(char cause)
{
	extern MusicClass music;
	bool dead = true;
	for (int p = 0; p < CreaturePool::getInstance().lenpool() && dead; p++)
		if (pool[p]->getNameAndAlignment().alive&&pool[p]->align == 1 &&
			!(pool[p]->flag&CREATUREFLAG_SLEEPER&&pool[p]->hireid != -1)) // Allow sleepers to lead LCS without losing
			dead = false;
	if (dead) // Did we just lose the game?
	{  // Game Over
		if (cause == END_BUT_NOT_END)
		{  // just checking for game over ahead of time but going back to the code for more stuff
			music.play(MUSIC_DEFEAT); // we were defeated, so play the right music
			return true; // go back to code, it has more text to display before we REALLY end the game
		}
		// OK if we didn't return yet it's REALLY Game Over, right now, but we need to find out why
		if (cause == END_OTHER)
		{  // got killed, possibly in a siege but maybe not, find out the reason we lost
			if (LocationsPool::getInstance().isThereASiegeHere(getCurrentSite()))
			{
				switch (LocationsPool::getInstance().getSiegeType(getCurrentSite()))
				{
				case SIEGE_POLICE: savehighscore(END_POLICE); break;
				case SIEGE_CIA: savehighscore(END_CIA); break;
				case SIEGE_HICKS: savehighscore(END_HICKS); break;
				case SIEGE_CORPORATE: savehighscore(END_CORP); break;
				case SIEGE_CCS: savehighscore(END_CCS); break;
				case SIEGE_FIREMEN: savehighscore(END_FIREMEN); break;
				}
			}
			else savehighscore(END_DEAD);
		}
		else savehighscore(cause); // the reason we lost was specified in the function call
								   // You just lost the game!
		viewhighscores();
		end_game();
		return true;
	}
	return false; // Hey, we're still alive! We get to keep playing!
}
/* common - applies a crime to everyone in a location, or the entire LCS */
void criminalizepool(short crime, long exclude, short loc)
{
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (p == exclude) continue;
		if (loc != -1 && pool[p]->location != loc) continue;
		pool[p]->criminalize( crime);
	}
}

// Determines the number of love slaves a creature has
int DeprecatedCreature::loveslaves() const
{
	int loveslaves = 0;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
		// If subordinate and a love slave
		if (pool[p]->hireid == id && pool[p]->getNameAndAlignment().alive && pool[p]->flag & CREATUREFLAG_LOVESLAVE)
			loveslaves++;
	return loveslaves;
}
/* The following boolean functions will return true if first is supposed to be
before second in the list. */
bool sort_none(const DeprecatedCreature* first, const DeprecatedCreature* second) //This will sort sorted back to unsorted.
{
	for (int j = 0; j < CreaturePool::getInstance().lenpool(); j++)
		if (pool[j] == first) return true;
		else if (pool[j] == second) return false;
		return false;
}

