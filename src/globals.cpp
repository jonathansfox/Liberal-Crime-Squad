#include "includes.h"
const string CONST_globals013 = "augmentations.xml";
const string CONST_globals012 = "creatures.xml";
const string CONST_globals011 = "loot.xml";
const string CONST_globals010 = "masks.xml";
const string CONST_globals009 = "armors.xml";
const string CONST_globals008 = "weapons.xml";
const string CONST_globals007 = "clips.xml";
const string CONST_globals006 = "vehicles.xml";
const string CONST_globals005 = "xmllog";
const string CONST_globals004 = "default_slogans.txt";
const string blankString = "";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
#include "creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"

#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../items/armortype.h"
#include "common/interval.h"
// needed for creaturetype
#include "vehicle/vehicletype.h"
#include "vehicle/vehicle.h"
#include "creature/creaturetype.h"
#include "creature/augmenttype.h"
//#include "common/consolesupport.h"
// for end_cleartype_fix()
///
/*
DEBUG DEFINES
*/
// inform player of activated debug codes
bool DISPLAYDEBUG = false;
// Don't save the game
bool NOSAVE = false;
// Enemies don't attack
bool NOENEMYATTACK = false;
// Laws start archconservative
bool SHITLAWS = false;
// Laws start elite liberal
bool PERFECTLAWS = false;
// Public opinion starts at 100% Liberal
bool REVOLUTIONNOW = false;
// Gives you bloody armor
bool GIVEBLOODYARMOR = false;
// Start with lots of money
bool HIGHFUNDS = false;
// Interrogation always enlightens
bool AUTOENLIGHTEN = false;
// Show polls when you can't see things
bool SHOWWAIT = false;
// Show die rolls, 100% accurate poll numbers
bool SHOWMECHANICS = false;
// Make the year 2100
bool THEFUTURE = false;
// Make the founder blind
bool BLIND = false;
// Make the founder unable to walk
bool NOWALK = false;
// Make the founder have no face
bool NOFACE = false;
// Make the founder have a severely injured spine
bool SPINE = false;
// Make the founder have severe internal damage
bool INTERNAL = false;
// Make age not matter for dating or prostitution
bool ZEROMORAL = false;
// Re-seed the Random Number Generator every time it's called
bool MORERANDOM = false;
// Allow experimental, incomplete Stalinist Comrade Squad mode to be chosen for new games
bool ALLOWSTALIN = false;
// Store savefiles in plaintext, making it human readable and editable
bool VERBOSESAVEFILE = false;
// NOVERBOSECOMMENTS only affect anything if VERBOSESAVEFILE is active
// Remove almost all automatically generated comments from verbose savefiles
vector<WeaponType *> weapontype;
bool NOVERBOSECOMMENTS = false;
unsigned char bigletters[27][5][7][4];
unsigned char newstops[6][80][5][4];
unsigned char newspic[20][78][18][4];
#include "common/musicClass.h"
MusicClass music;
char homedir[MAX_PATH_SIZE];
char artdir[MAX_PATH_SIZE];
bool multipleCityMode;
unsigned long seed[RNG_SIZE];
vector<ClipType *> cliptype;
vector<ArmorType *> armortype;
vector<CreatureType *> creaturetype;
vector<AugmentType *> augmenttype;

long curcreatureid = 0;
vector<string> default_slogans;
#include "customMaps.h"
vector<file_and_text_collection> globals_text_file_collection = {
	customText(&default_slogans, CONST_globals004),
};
vector<Vehicle *> vehicle;
void newVehicle(Vehicle *startcar) {
	vehicle.push_back(startcar);
}
char showcarprefs = 1;
siteblockst levelmap[MAPX][MAPY][MAPZ];
chaseseqst chaseseq;
const string CONST_game012 = "We need a slogan!";
string slogan_str = CONST_game012;
char slogan[SLOGAN_LEN] = "We need a slogan!";
vector<Deprecatedsquadst *> squad;
Deprecatedsquadst *activesquad = NULL;
long cursquadid = 0;
char disbanding = 0;
int disbandtime = 0;
char cantseereason;
short activesortingchoice[SORTINGCHOICENUM];
DeprecatedCreature encounter[ENCMAX];
short mode = GAMEMODE_TITLE;
short offended_corps = 0;
short offended_cia = 0;
short offended_amradio = 0;
short offended_cablenews = 0;
short offended_firemen = 0;
int police_heat = 0;
unsigned long attorneyseed[RNG_SIZE];
int selectedsiege = -1;
char lcityname[CITY_NAMELEN];
char newscherrybusted = 0;
int month = 1;
int year = THEFUTURE ? 2100 : 2009;
int amendnum = 28;
bool termlimits = false;
bool deagle = false;
bool m249 = false;
UniqueCreatures uniqueCreatures;
short attitude[VIEWNUM];
short public_interest[VIEWNUM];
short background_liberal_influence[VIEWNUM];
short lawList[LAWNUM];
short house[HOUSENUM];
short senate[SENATENUM];
short court[COURTNUM];
char courtname[COURTNUM][POLITICIAN_NAMELEN];
short exec[EXECNUM];
short execterm = 1;
char execname[EXECNUM][POLITICIAN_NAMELEN];
short presparty = CONSERVATIVE_PARTY;
char oldPresidentName[POLITICIAN_NAMELEN];
int stat_recruits = 0;
int stat_kidnappings = 0;
int stat_dead = 0;
int stat_kills = 0;
int stat_buys = 0;
int stat_burns = 0;
int ustat_recruits = 0;
int ustat_kidnappings = 0;
int ustat_dead = 0;
int ustat_kills = 0;
int ustat_funds = 0;
int ustat_spent = 0;
int ustat_buys = 0;
int ustat_burns = 0;
coordinatest loc_coord;
short sitetype;
short sitealienate;
short sitealarmtimer;
short postalarmtimer;
short siteonfire;
int sitecrime;
short cursite;
bool mapshowing = false;
bool encounterwarnings = false;
char foughtthisround = 0;
short interface_pgup = '[';
short interface_pgdn = ']';
int day = 1;
short party_status = -1;
short wincondition = WINCONDITION_ELITE;
short fieldskillrate = FIELDSKILLRATE_FAST;
bool notermlimit;           //These determine if ELAs can take place --kviiri
bool nocourtpurge;
bool stalinmode;
char endgamestate = ENDGAME_NONE;
CCSexposure ccsexposure = CCSEXPOSURE_NONE;
char ccs_kills = 0;
int ccs_siege_kills = 0;
int ccs_boss_kills = 0;
vector<Deprecatedrecruitst *> recruit;
Deprecatednewsstoryst *sitestory = NULL;
int yourscore = -1;
#include "common/creaturePool.h"
#include "locations/locationsPool.h"
#include "items/itemPool.h"
#include "items/lootTypePool.h"
void delete_and_clear_sitemaps();
void delete_and_clear_groundloot();
int endwinAlt(void);
void delete_and_clear_vehicle_types();
void delete_and_clear_date_pool();
void delete_and_clear_weapon_type();
#include <common\\consolesupport.h>
/* Free memory and exit the game */ // This function closes the entire program, and can be called anywhere
void end_game(int err)
{
#ifdef WIN32
	end_cleartype_fix(); // won't do anything unless fixcleartype is true
#endif
	// title_screen::getInstance().delete_screen();
	LocationsPool::getInstance().delete_and_clear_pool();
	delete_and_clear(squad);
	delete_and_clear_weapon_type();
	delete_and_clear(cliptype);
	delete_and_clear(armortype);
	LootTypePool::getInstance().delete_and_clear_pool();
	delete_and_clear(creaturetype);
	delete_and_clear(augmenttype);
	delete_and_clear_vehicle_types();
	delete_and_clear(vehicle);
	CreaturePool::getInstance().delete_and_clear_pool();
	delete_and_clear_sitemaps();
	delete_and_clear(recruit);
	delete_and_clear_date_pool();
	delete_and_clear_groundloot();
	music.quit(); // shut down music
	endwinAlt();
	exit(err);
}
#include "items/loottype.h"
#include "log/log.h"
#include "cursesAlternative.h"
extern string failedToLoad;
extern string exclamationPoint;
template<class Type>
bool populate_from_xml(vector<Type*>& types, const string& file, Log& log)
{
	CMarkup xml;
	if (!xml.Load(string(artdir) + file))
	{ // File is missing or not valid XML.
		addstrAlt(failedToLoad + file + exclamationPoint, log);
		pressAnyKey();
		// Will cause abort here or else if file is missing all unrecognized types
		// loaded from a saved game will be deleted. Also, you probably don't want
		// to play with a whole category of things missing anyway. If the file
		// does not have valid xml, then behaviour is kind of undefined so it's
		// best to abort then too.
		return false;
	}
	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem()) types.push_back(new Type(xml.GetSubDoc()));
	return true;
}
string getVehicleShortname(int i) {
	return vehicle[i]->shortname();
}
string getVehicleFullname(int i) {
	return vehicle[i]->fullname();
}
int driveskill(DeprecatedCreature &cr, Vehicle &v);
int driveskill(DeprecatedCreature &cr, int v) {
	return driveskill(cr, *vehicle[v]);
}

/* transforms a squad id number into the index of that squad in the global vector */
int getsquad(int id)
{
	for (int i = 0; i < len(squad); i++) if (squad[i]->id == id) return i;
	return -1;
}
/* transforms a car id number into the index of that car in the global vector */
int id_getcar(int id)
{
	for (int i = 0; i < len(vehicle); i++) if (vehicle[i]->id() == id) return i;
	return -1;
}

/* transforms a clip type id into the index of that clip type in the global vector */
int getcliptype(int id)
{
	for (int i = 0; i < len(cliptype); i++) if (cliptype[i]->get_id() == id) return i;
	return -1;
}
/* transforms a clip type name into the index of that clip type in the global vector */
int getcliptype(const string &idname)
{
	for (int i = 0; i < len(cliptype); i++) if (cliptype[i]->get_idname() == idname) return i;
	return -1;
}

/* transforms a armor type id into the index of that armor type in the global vector */
int getarmortype(int id)
{
	for (int i = 0; i < len(armortype); i++) if (armortype[i]->get_id() == id) return i;
	return -1;
}
/* transforms a armor type name into the index of that armor type in the global vector */
int getarmortype(const string &idname)
{
	for (int i = 0; i < len(armortype); i++) if (armortype[i]->get_idname() == idname) return i;
	return -1;
}
/* transforms a CreatureTypes value into a pointer to that creature type */
const CreatureType* getcreaturetype(short crtype)
{
	for (int i = 0; i < len(creaturetype); i++) if (crtype == creaturetype[i]->get_type()) return creaturetype[i];
	return NULL;
}
/* transforms a creature type name into a pointer to that creature type  */
const CreatureType* getcreaturetype(const std::string& crtype)
{
	for (int i = 0; i < len(creaturetype); i++) if (crtype == creaturetype[i]->get_idname()) return creaturetype[i];
	return NULL;
}

/* common - moves all squad members and their cars to a new location */
void locatesquad(Deprecatedsquadst *st, long loc)
{
	for (int p = 0; p < 6; p++) if (st->squad[p] != NULL)
	{
		st->squad[p]->location = loc;
		if (st->squad[p]->carid != -1)
		{
			long v = id_getcar(st->squad[p]->carid);
			if (v != -1) vehicle[v]->set_location(loc);
		}
	}
}

int lenVehiclePool() {
	return len(vehicle);
}

int getCarID(const int l) {
	return vehicle[l]->id();
}

string getCarFullname(const int l) {
	return vehicle[l]->fullname(true);
}

void deleteLocationVehicles(int loc) {
	for (int v = len(vehicle) - 1; v >= 0; v--)
		if (vehicle[v]->get_location() == loc)
			delete_and_remove(vehicle, v);
}

void deleteVehicle(int carid) {
	delete_and_remove(vehicle, carid);
}

void deleteVehicles(vector<Vehicle *>& carid) {
	delete_and_clear(carid, vehicle);
}

void addCreatueVehiclesToCollection(DeprecatedCreature *cr[6], vector<Vehicle *> &veh) {
	for (int p = 0; p < 6; p++)
	{
		if (cr[p] == NULL) continue;
		if (cr[p]->carid != -1)
		{
			int v = id_getcar(cr[p]->carid);
			if (v != -1)
			{
				int v2;
				for (v2 = 0; v2 < len(veh); v2++) {
					if (veh[v2]->id() == vehicle[v]->id()) {
						break;
					}
				}
				if (v2 == len(veh)) veh.push_back(vehicle[v]);
			}
		}
	}
}

bool populate_masks_from_xml(vector<ArmorType*>& masks, const string& file, Log& log);
bool mainSeven(bool xml_loaded_ok) {
	extern vector<LootType *> loottype;
	extern vector<WeaponType *> weapontype;
	extern vector<VehicleType *> vehicletype;
	extern Log xmllog;
	xmllog.initialize(CONST_globals005, true, 1);
	xml_loaded_ok &= populate_from_xml(vehicletype, CONST_globals006, xmllog);
	xml_loaded_ok &= populate_from_xml(cliptype, CONST_globals007, xmllog);
	xml_loaded_ok &= populate_from_xml(weapontype, CONST_globals008, xmllog);
	xml_loaded_ok &= populate_from_xml(armortype, CONST_globals009, xmllog);
	xml_loaded_ok &= populate_masks_from_xml(armortype, CONST_globals010, xmllog);
	xml_loaded_ok &= populate_from_xml(loottype, CONST_globals011, xmllog);
	xml_loaded_ok &= populate_from_xml(creaturetype, CONST_globals012, xmllog);
	xml_loaded_ok &= populate_from_xml(augmenttype, CONST_globals013, xmllog);
	return xml_loaded_ok;
}

void newRecruit(DeprecatedCreature *newcr, int a) {

	Deprecatedrecruitst *newrst = new Deprecatedrecruitst(newcr, a);
	recruit.push_back(newrst);
}

const string tag_WEAPON_FLAMETHROWER = "WEAPON_FLAMETHROWER";
const string tag_WEAPON_DESERT_EAGLE = "WEAPON_DESERT_EAGLE";
int getweapontype(const string &idname);
Weapon* spawnNewWeapon(string newWeaponType) {
	extern vector<WeaponType *> weapontype;
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
	return w;
}

Armor* spawnNewArmor(string newArmorType) {

	int quality = 1;
	if (!LCSrandom(3))
		quality = 2;
	Armor *a = new Armor(getarmortype(newArmorType), quality);
	if (!LCSrandom(3))
		a->set_damaged(true);

	return a;
}
#include "common/ledgerEnums.h"
#include "common/ledger.h"
void selectAugmentType(vector<AugmentType *> &aug_type, char aug_c, int age) {
	extern class Ledger ledger;
	for (int x = 0; x < augmenttype.size(); x++)
	{
		if (augmenttype[x]->get_type() == aug_c - 'a' &&
			(augmenttype[x]->get_max_age() == -1 || age <= augmenttype[x]->get_max_age()) &&
			(augmenttype[x]->get_min_age() == -1 || age >= augmenttype[x]->get_min_age()) &&
			augmenttype[x]->get_cost() <= ledger.get_funds())
			//TODO: Make it so that if you don't have money, it just grays it out, not just not show it
			aug_type.push_back(augmenttype[x]);
	}
}

void removeCreatureFromSquad(DeprecatedCreature &cr, int oldsqid) {
	activesquad = squad[getsquad(oldsqid)];
	for (int i = 0; i < 6; i++)
	{
		if (activesquad->squad[i]) if (activesquad->squad[i] == &cr)
		{
			for (int j = i + 1; j < 6; j++, i++) activesquad->squad[i] = activesquad->squad[j];
			activesquad->squad[5] = NULL;
			break;
		}
	}
}
void setEncounterZeroExistsFalse() {
	encounter[0].exists = false;
}
vector<NameAndAlignment> getEncounterNameAndAlignment() {
	vector<NameAndAlignment> nameList;
	for (int e = 0; e < ENCMAX; e++) {
		nameList.push_back(encounter[e].getNameAndAlignment());
	}
	return nameList;
}
int encounterSize() {
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();
	int encsize = 0;
	for (int e = 0; e < ENCMAX; e++) if (encounter[e].exists) encsize++;
	return encsize;
}
int baddieCount() {
	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();
	int baddiecount = 0;
	for (int e = 0; e < ENCMAX; e++) if (encounter[e].enemy && encounter[e].alive&&encounter[e].exists) baddiecount++;
	return baddiecount;
}
int baddieCount(const bool in_car) {
	int baddiecount = 0;

	for (int e = 0; e < ENCMAX; e++)
	{
		if (encounter[e].carid != -1 &&
			encounter[e].enemy() &&
			encounter[e].alive&&
			encounter[e].exists)baddiecount++;
	}
	return baddiecount;
}
void damage_creature(const int e) {

	encounter[e].blood = LCSrandom(75) + 1;
}
void conservatise(const int e) {
	conservatise(encounter[e]);
}

void spawnPresident() {
	encounter[2] = uniqueCreatures.President();
}
void liberalizeEncounterIfThisType(const int type) {

	for (int i = 0; i < ENCMAX; i++)
		if (encounter[i].type == type)
			encounter[i].align = ALIGN_LIBERAL;
}
int squadAlive() {
	int partyalive = 0;
	for (int p = 0; p < 6; p++)
		if (activesquad->squad[p]) if (activesquad->squad[p]->alive == 1) partyalive++;
	return partyalive;
}
void addCrimeToSiteStory(const int crime) {

	sitestory->crime.push_back(crime);
}
#include "items/money.h"
void giveActiveSquadThisLoot(Item* de) {
	activesquad->loot.push_back(de);
}

void giveActiveSquadMoney(const int money) {

	giveActiveSquadThisLoot(new Money(money));
}
Item* getNewLoot(const string& newLootType, int num = 1);
void giveActiveSquadLoot(const string loot) {

	giveActiveSquadThisLoot(getNewLoot(loot));
}
void claimSiteStory() {
	sitestory->claimed = 2;
}
void claimSiteStoryOne() {
	if (!sitestory->claimed)
		sitestory->claimed = 1;
}
void addjuice(DeprecatedCreature &cr, long juice, long cap);
void juiceActiveSquad(const long juice, const long cap) {

	for (int i = 0; i < 6; i++)
	{
		if (activesquad->squad[i])
			addjuice(*(activesquad->squad[i]), juice, cap);
	}
}
void juiceEntireCreaturePool(const long juice, const long cap) {
	extern vector<DeprecatedCreature *> pool;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++) addjuice(*pool[p], juice, cap);
}
int getEscapeEngageLocation() {
	int loc = -1;
	if (selectedsiege != -1) loc = selectedsiege;
	if (activesquad != NULL) loc = activesquad->squad[0]->location;
	return loc;
}
void deleteAllSquadsInActiveAreaExceptActive(const int loc) {
	for (int sq = len(squad) - 1; sq >= 0; sq--)
		if (squad[sq] != activesquad && squad[sq]->squad[0])
			if (squad[sq]->squad[0]->location == loc)
			{
				if (activesquad)
				{
					for (int p = 0; p < 6; p++)
					{
						if (!squad[sq]->squad[p]) continue;
						squad[sq]->squad[p]->squadid = -1;
					}
					delete_and_remove(squad, sq);
				}
				else activesquad = squad[sq];
			}
}
void formANewSquadIfThereAreNone() {
	const string CONST_siege254 = " Defense";
	extern vector<DeprecatedCreature *> pool;
	if (!activesquad)
	{
		squad.push_back(new Deprecatedsquadst);
		squad.back()->id = cursquadid++;
		strcpy(squad.back()->name, LocationsPool::getInstance().getLocationNameWithGetnameMethod(selectedsiege, true).c_str());
		strcat(squad.back()->name, CONST_siege254.c_str());
		int i = 0;
		for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++) if (pool[p]->location == selectedsiege && pool[p]->alive&&pool[p]->align == 1)
		{
			squad.back()->squad[i] = pool[p];
			pool[p]->squadid = squad.back()->id;
			if (++i >= 6) break;
		}
		activesquad = squad.back();
	}
}
void countHeroes(int &partysize, int &partyalive) {
	extern vector<DeprecatedCreature *> pool;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++) if (pool[p]->align == 1 && pool[p]->location == cursite && !(pool[p]->flag&CREATUREFLAG_SLEEPER))
	{
		partysize++;
		if (pool[p]->alive) partyalive++;
	}
}
void cancelOutBleeding() {
	extern vector<DeprecatedCreature *> pool;
	for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++) for (int w = 0; w < BODYPARTNUM; w++) pool[p]->wound[w] &= ~WOUND_BLEEDING;
}
int print_character_info(const int c, const int party_status) {
	void fullstatus(const int party_status);
	if (c >= '1'&&c <= '6') if (activesquad->squad[c - '1'] != NULL)
	{
		if (party_status == c - '1')fullstatus(party_status);
		else return c - '1';
	}
	return party_status;
}
void baseEveryoneLeftAtHomelessShelter(const int homes) {
	void removesquadinfo(DeprecatedCreature &cr);
	extern vector<DeprecatedCreature *> pool;

	for (int p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
	{
		if (pool[p]->location != cursite) continue;
		if (!pool[p]->alive)
		{
			delete_and_remove(pool, p);
			continue;
		}
		//BASE EVERYONE LEFT AT HOMELESS SHELTER
		removesquadinfo(*pool[p]);
		pool[p]->hiding = LCSrandom(3) + 2;
		if (pool[p]->align == 1) // not a hostage
			pool[p]->location = -1;
		else // hostages don't go into hiding, just shove em into the homeless shelter
			pool[p]->location = homes;
		pool[p]->base = homes;
	}
}
int printBestLCSMemberForNews(const string repname, const int l) {
	void printReporterDuringSiege(const string repname, const string name, const int segmentpower);
	const string CONST_siege209 = "The interview is wide-ranging, covering a variety of topics.";
	const string CONST_siege208 = " decides to give an interview.";
	extern vector<DeprecatedCreature *> pool;
	extern Log gamelog;
	int best = 0;
	for (int p = 0, bestvalue = -1000; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (!pool[p]->alive || pool[p]->align != 1 || pool[p]->location != l) continue;
		int sum = pool[p]->get_attribute(ATTRIBUTE_INTELLIGENCE, true)
			+ pool[p]->get_attribute(ATTRIBUTE_HEART, true)
			+ pool[p]->get_skill(SKILL_PERSUASION)
			+ pool[p]->juice;
		if (sum > bestvalue) best = p, bestvalue = sum;
	}
	mvaddstrAlt(4, 1, pool[best]->name, gamelog);

	addstrAlt(CONST_siege208, gamelog);
	gamelog.newline();
	pressAnyKey();
	mvaddstrAlt(6, 1, CONST_siege209, gamelog);
	gamelog.newline();
	pressAnyKey();
	int segmentpower = pool[best]->attribute_roll(ATTRIBUTE_INTELLIGENCE)
		+ pool[best]->attribute_roll(ATTRIBUTE_HEART)
		+ pool[best]->skill_roll(SKILL_PERSUASION)
		+ pool[best]->skill_roll(SKILL_PERSUASION)
		+ pool[best]->skill_roll(SKILL_PERSUASION);

	printReporterDuringSiege(repname, pool[best]->name, segmentpower);
	return segmentpower;
}
void set_site_story_as_last_news_story() {
	Deprecatednewsstoryst* lastNewsStory();
	extern Deprecatednewsstoryst *sitestory;
	sitestory = lastNewsStory();

}
void setSiteStoryClaimedZero() {
	extern Deprecatednewsstoryst *sitestory;
	sitestory->claimed = 0;
}
bool isActiveSquadAnonymous() {
	return activesquad->stance == SQUADSTANCE_ANONYMOUS;
}
char shouldWeBailOnBase() {
	char bail_on_base = 1;
	if (cursite == activesquad->squad[0]->base)bail_on_base = 0;
	return bail_on_base;
}
void set_sitestory_type() {
	void resolvesite();
	if (LocationsPool::getInstance().isThereASiegeHere(cursite))
	{
		if (LocationsPool::getInstance().isThisUnderAttack(cursite))sitestory->type = NEWSSTORY_SQUAD_KILLED_SIEGEATTACK;
		else { sitestory->type = NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE; }
	}
	else
		if (!LocationsPool::getInstance().isThereASiegeHere(cursite))
		{
			sitestory->type = NEWSSTORY_SQUAD_KILLED_SITE;
			resolvesite();
		}
}
int activesquadSize() {
	int squadsize(const Deprecatedsquadst *st);
	return squadsize(activesquad);
}
int activesquadAlive() {
	int squadalive(const Deprecatedsquadst *st);
	return squadalive(activesquad);
}
int getactivesquadBase() {
	int cbase = -1;
	if (activesquad->squad[0] != NULL)
	{
		cbase = activesquad->squad[0]->base;
	}
	return cbase;
}
int getactivesquadCarID(const int p) {
	if (!activesquad->squad[p]) {
		return activesquad->squad[p]->carid;
	}
	else {
		return -1;
	}
}
void killActiveSquad() {
	for (int p = 0; p < 6; p++)
	{
		if (!activesquad->squad[p]) continue;
		activesquad->squad[p]->die();
		activesquad->squad[p]->location = -1;
		activesquad->squad[p] = NULL;
	}
}
void conservatiseEncslot(const int encslot) {
	conservatise(encounter[encslot]);
}

vector<int> potentialEncounterNoticers() {
	vector<int> noticer;
	for (int e = 0; e < ENCMAX; e++)
	{
		if (encounter[e].type == CREATURE_PRISONER)continue;
		if (encounter[e].exists&&encounter[e].alive&&
			encounter[e].enemy())
		{
			noticer.push_back(e);
		}
	}
	return noticer;
}
int get_stealth_difficulty(const int n) {
	return encounter[n].get_stealth_difficulty();
}
int get_disguise_difficulty(const int n) {
	return encounter[n].get_disguise_difficulty();
}

int get_encounter_time(const int n) {
	int time;
	time = 20 + LCSrandom(10) - encounter[n].get_attribute(ATTRIBUTE_INTELLIGENCE, true)
		- encounter[n].get_attribute(ATTRIBUTE_WISDOM, true);
	return time;
}


void clearCarStates() {
	extern vector<DeprecatedCreature *> pool;
	for (int p = 0; p < len(pool); p++) pool[p]->carid = -1;
}

void removeItemFromSquad(const int loottypeindex) {
	extern vector<Deprecatedsquadst *> squad;
	int getloottype(const string &idname);
	for (int sq = 0; sq < len(squad); sq++)
	{
		for (int l = 0; l < len(squad[sq]->loot); l++)
		{
			if (!(squad[sq]->loot[l]->whatIsThis() == THIS_IS_LOOT)) continue;
			if (getloottype(squad[sq]->loot[l]->get_itemtypename()) == loottypeindex)
			{
				squad[sq]->loot[l]->decrease_number(1);
				if (squad[sq]->loot[l]->empty())
					delete_and_remove(squad[sq]->loot, l);
				return;// loottypeindex;
			}
		}
	}
}

void constructLootIndices(vector<bool> &havetype, vector<int> &loottypeindex, const vector<string> dox) {
	extern vector<Deprecatedsquadst *> squad;
	void consolidateloot(vector<Item *> &loot);
	int getloottype(const string &idname);
	for (int sq = 0; sq < len(squad); sq++)
	{
		consolidateloot(squad[sq]->loot);
		for (int l = 0; l < len(squad[sq]->loot); l++)
		{
			if (!(squad[sq]->loot[l]->whatIsThis() == THIS_IS_LOOT)) continue;
			if (!binary_search(dox.begin(), dox.end(), squad[sq]->loot[l]->get_itemtypename())) continue;
			if (!havetype[getloottype(squad[sq]->loot[l]->get_itemtypename())])
			{
				loottypeindex.push_back(getloottype(squad[sq]->loot[l]->get_itemtypename()));
				havetype[getloottype(squad[sq]->loot[l]->get_itemtypename())] = true;
			}
		}
	}
}

