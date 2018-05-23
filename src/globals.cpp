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
#include "../locations/locations.h"
#include "../items/armortype.h"
#include "common/interval.h"
// needed for creaturetype
#include "vehicle/vehicletype.h"
#include "vehicle/vehicle.h"
#include "creature/creaturetype.h"
#include "creature/augmenttype.h"
#include "common/consolesupport.h"
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
char slogan[SLOGAN_LEN];
vector<squadst *> squad;
squadst *activesquad = NULL;
long cursquadid = 0;
char disbanding = 0;
int disbandtime = 0;
char cantseereason;
short activesortingchoice[SORTINGCHOICENUM];
Creature encounter[ENCMAX];
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
int locx;
int locy;
int locz;
short sitetype;
short sitealienate;
short sitealarm;
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
vector<recruitst *> recruit;
newsstoryst *sitestory = NULL;
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
int driveskill(Creature &cr, Vehicle &v);
int driveskill(Creature &cr, int v) {
	return driveskill(cr, *vehicle[v]);
}

/* transforms a squad id number into the index of that squad in the global vector */
int getsquad(int id)
{
	for (int i = 0; i<len(squad); i++) if (squad[i]->id == id) return i;
	return -1;
}
/* transforms a car id number into the index of that car in the global vector */
int id_getcar(int id)
{
	for (int i = 0; i<len(vehicle); i++) if (vehicle[i]->id() == id) return i;
	return -1;
}

/* transforms a clip type id into the index of that clip type in the global vector */
int getcliptype(int id)
{
	for (int i = 0; i<len(cliptype); i++) if (cliptype[i]->get_id() == id) return i;
	return -1;
}
/* transforms a clip type name into the index of that clip type in the global vector */
int getcliptype(const string &idname)
{
	for (int i = 0; i<len(cliptype); i++) if (cliptype[i]->get_idname() == idname) return i;
	return -1;
}

/* transforms a armor type id into the index of that armor type in the global vector */
int getarmortype(int id)
{
	for (int i = 0; i<len(armortype); i++) if (armortype[i]->get_id() == id) return i;
	return -1;
}
/* transforms a armor type name into the index of that armor type in the global vector */
int getarmortype(const string &idname)
{
	for (int i = 0; i<len(armortype); i++) if (armortype[i]->get_idname() == idname) return i;
	return -1;
}
/* transforms a CreatureTypes value into a pointer to that creature type */
const CreatureType* getcreaturetype(short crtype)
{
	for (int i = 0; i<len(creaturetype); i++) if (crtype == creaturetype[i]->get_type()) return creaturetype[i];
	return NULL;
}
/* transforms a creature type name into a pointer to that creature type  */
const CreatureType* getcreaturetype(const std::string& crtype)
{
	for (int i = 0; i<len(creaturetype); i++) if (crtype == creaturetype[i]->get_idname()) return creaturetype[i];
	return NULL;
}

/* common - moves all squad members and their cars to a new location */
void locatesquad(squadst *st, long loc)
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

void addCreatueVehiclesToCollection(Creature *cr[6], vector<Vehicle *> &veh) {
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

extern vector<LootType *> loottype;
extern vector<WeaponType *> weapontype;
extern vector<VehicleType *> vehicletype;
bool populate_masks_from_xml(vector<ArmorType*>& masks, const string& file, Log& log);
bool mainSeven(bool xml_loaded_ok) {
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

void newRecruit(Creature *newcr, int a) {

	recruitst *newrst = new recruitst(newcr, a);
	recruit.push_back(newrst);
}

const string tag_WEAPON_FLAMETHROWER = "WEAPON_FLAMETHROWER";
const string tag_WEAPON_DESERT_EAGLE = "WEAPON_DESERT_EAGLE";
int getweapontype(const string &idname);
Weapon* spawnNewWeapon(string newWeaponType) {
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
extern class Ledger ledger;
void selectAugmentType(vector<AugmentType *> &aug_type, char aug_c, int age) {
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
