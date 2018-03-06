#include <includes.h>
#include "creature/creature.h"

#include "common/ledgerEnums.h"
#include "common/ledger.h"

#include "vehicle/vehicletype.h"
#include "vehicle/vehicle.h"

#include "common/commondisplay.h"
// for void printfunds(int,int,char*)

#include "common/stringconversion.h"
//for string attribute_enum_to_string(int)

#include "common/getnames.h"
// for cityname

#include "common/translateid.h"
// for  getarmortype

#include <cursesAlternative.h>
#include <cursesAlternativeConstants.h>
#include <constant_strings.h>
#include <set_color_support.h>

#include "locations/locationsPool.h"
#include "common/creaturePoolCreature.h"
#include "items/money.h"

enum recruits
{
	RECRUITS_GANG,
	RECRUITS_NONE
};
vector<Location *> location;
void initiateNewgameLocations(char base, char recruits, Vehicle * startcar, bool makelawyer, bool gaylawyer, Creature * newcr) {
	squadst *newsq = new squadst;
	extern long cursquadid;
	newsq->id = 0; cursquadid++;
	newsq->squad[0] = newcr;
	newcr->squadid = 0;
	extern string theLCS;
	strcpy(newsq->name, theLCS);
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern vector<squadst *> squad;
	extern class Ledger ledger;
	extern vector<ArmorType *> armortype;
	for (int l = 0; l < len(location); l++)
	{
		if (location[l]->type == base)
		{
			newcr->base = l;
			newcr->location = l;
			if (startcar) startcar->set_location(l);
			switch (base)
			{
			case SITE_RESIDENTIAL_APARTMENT_UPSCALE:location[l]->renting = 500; break;
			case SITE_RESIDENTIAL_APARTMENT:location[l]->renting = 200; break;
			case SITE_RESIDENTIAL_TENEMENT:location[l]->renting = 100; break;
			case SITE_BUSINESS_CRACKHOUSE:
				location[l]->renting = RENTING_PERMANENT;
				location[l]->compound_stores += 100;
				break;
			}
			location[l]->newrental = 1;
			switch (recruits)
			{
			case RECRUITS_GANG:
				for (int i = 0; i < 4; i++)
				{
					Creature* recruit = new Creature;
					makecreature(*recruit, CREATURE_GANGMEMBER);
					if (recruit->get_weapon().get_itemtypename() == tag_WEAPON_AUTORIFLE_AK47 ||
						recruit->get_weapon().get_itemtypename() == tag_WEAPON_SMG_MP5 ||
						!recruit->is_armed())
					{
						Weapon w(*weapontype[getweapontype(tag_WEAPON_SEMIPISTOL_9MM)]);
						recruit->give_weapon(w, NULL);
						Clip c(*cliptype[getcliptype(tag_CLIP_9)], 4);
						recruit->take_clips(c, 4);
						recruit->reload(false);
					}
					recruit->align = ALIGN_LIBERAL;
					recruit->set_attribute(ATTRIBUTE_HEART,
						recruit->get_attribute(ATTRIBUTE_HEART, false) +
						recruit->get_attribute(ATTRIBUTE_WISDOM, false) / 2);
					recruit->set_attribute(ATTRIBUTE_WISDOM,
						recruit->get_attribute(ATTRIBUTE_WISDOM, false) / 2);
					recruit->namecreature();
					strcpy(recruit->name, recruit->propername);
					recruit->location = l;
					recruit->base = l;
					recruit->hireid = newcr->id;
					newsq->squad[i + 1] = recruit;
					recruit->squadid = newsq->id;
					addCreature(recruit);
				}
				break;
			}
			if (GIVEBLOODYARMOR) {
				Armor *newa = new Armor(*armortype[getarmortype(tag_ARMOR_CLOTHES)]);
				newa->set_bloody(true);
				location[l]->loot.push_back(newa);
			}
			if (HIGHFUNDS) {
				ledger.force_funds(100000);
			}
			break;
		}
	}
	extern squadst *activesquad;
	//newcr->juice=0;
	squad.push_back(newsq);
	activesquad = newsq;
	if (makelawyer)
	{
		Creature* lawyer = new Creature;
		makecreature(*lawyer, CREATURE_LAWYER);
		// Make sure lawyer is of the appropriate gender for dating the main character;
		// opposite sex by default, same sex if the option was chosen that mentions
		// homosexuality
		if (gaylawyer)
		{
			lawyer->gender_conservative = lawyer->gender_liberal = newcr->gender_conservative;
			// neutral founder gets neutral partner
		}
		else
		{
			if (newcr->gender_conservative == GENDER_MALE)
				lawyer->gender_liberal = lawyer->gender_conservative = GENDER_FEMALE;
			if (newcr->gender_conservative == GENDER_FEMALE)
				lawyer->gender_liberal = lawyer->gender_conservative = GENDER_MALE;
			// neutral founder gets random partner
		}
		// Ensure the lawyer has good heart/wisdom stats
		if (lawyer->get_attribute(ATTRIBUTE_HEART, false) < newcr->get_attribute(ATTRIBUTE_HEART, false) - 2)
			lawyer->adjust_attribute(ATTRIBUTE_HEART, -2);
		lawyer->set_attribute(ATTRIBUTE_WISDOM, 1);
		lawyer->namecreature();
		lawyer->flag |= CREATUREFLAG_SLEEPER;
		lawyer->flag |= CREATUREFLAG_LOVESLAVE;
		lawyer->align = ALIGN_LIBERAL;
		lawyer->infiltration = 0.3f;
		lawyer->age = 28;
		location[lawyer->worklocation]->mapped = 1;
		lawyer->hireid = newcr->id;
		addCreature(lawyer);
		lawyer->location = lawyer->base = lawyer->worklocation;
	}
}
bool LocationsPool::locationPoolInitiated = false;
LocationsPool lPool;
LocationsPool LocationsPool::getInstance()
{
	if (!locationPoolInitiated) {
		lPool = LocationsPool();
		locationPoolInitiated = true;
	}
	return lPool;
}

int LocationsPool::lenpool()
{
	return len(location);
}
int LocationsPool::getLocationCity(int cursite) {
	return location[cursite]->city;
}
void LocationsPool::hideCCSSafehouses()
{

	// hide ccs safehouses
	for (int l = 0; l < lenpool(); l++)
	{
		if (getRentingType(l) == RENTING_CCS)
		{
			location[l]->renting = RENTING_NOCONTROL;
			location[l]->hidden = true;
		}
	}
}
void LocationsPool::addHeat(int cursite, int heat)
{
	location[cursite]->heat += heat;
}
#include "common/equipment.h"
void LocationsPool::findAllLootTypes(vector<bool>& havetype, vector<int>& loottypeindex, const vector<string> dox)
{

	//FIND ALL LOOT TYPES
	for (int loc = 0; loc < LocationsPool::getInstance().lenpool(); loc++)

	{
		if (LocationsPool::getInstance().getRentingType(loc) == RENTING_NOCONTROL) continue;
		consolidateloot(location[loc]->loot);
		for (int l = 0; l < len(location[loc]->loot); l++)

		{
			if (!location[loc]->loot[l]->is_loot()) continue;
			if (!binary_search(dox.begin(), dox.end(), location[loc]->loot[l]->get_itemtypename())) continue;
			if (!havetype[getloottype(location[loc]->loot[l]->get_itemtypename())])

			{
				loottypeindex.push_back(getloottype(location[loc]->loot[l]->get_itemtypename()));
				havetype[getloottype(location[loc]->loot[l]->get_itemtypename())] = true;



			}
		}
	}
}
bool LocationsPool::isLocationMapped(int cursite)
{
	return location[cursite]->mapped;
}
bool LocationsPool::isLocationHidden(int cursite)
{
	return location[cursite]->hidden;
}
void LocationsPool::setLocationMappedAndUnhidden(int cursite)
{
	location[cursite]->mapped = 1;
	location[cursite]->hidden = 0;
}
string LocationsPool::getLocationNameWithGetnameMethod(int cursite, bool a) {
	return getLocationNameWithGetnameMethod(cursite, a, false);
}
string LocationsPool::getLocationNameWithGetnameMethod(int cursite, bool a, bool b)
{
	return location[cursite]->getname(a, b);
}
int LocationsPool::getCompoundWalls(int cursite)
{
	return location[cursite]->compound_walls;
}
void LocationsPool::setTimeUntilSiege(int cursite, int time)
{
	location[cursite]->siege.timeuntillocated = time;
}
bool LocationsPool::isNewRental(int cursite)
{
	return location[cursite]->newrental;
}
#include "common/creaturePool.h"
void LocationsPool::evictLCSFrom(int l)
{

	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, "EVICTION NOTICE: ");
	addstrAlt(LocationsPool::getInstance().getLocationName(l));
	addstrAlt(".  Possessions go to the shelter.");
	getkeyAlt();
	location[l]->renting = RENTING_NOCONTROL;
	CreaturePool::getInstance().moveAllSquadMembers(l);
	int hs = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, l);
	location[hs]->getloot(location[l]->loot);
	location[l]->compound_walls = 0;
	location[l]->compound_stores = 0;
	location[l]->front_business = -1;
}
bool LocationsPool::isThisSiteClosed(int cursite)
{
	return location[cursite]->closed;
}
bool LocationsPool::doesThisPlaceNeedACar(int cursite)
{
	return location[cursite]->needcar;
}
int LocationsPool::findTravelLocation()
{
	int travelLocation = -1;
	for (int i = 0; i < len(location); i++) {
		if (location[i]->type == SITE_TRAVEL)
		{
			travelLocation = i;
			break;
		}
	}
	return travelLocation;
}
int LocationsPool::getLocationParent(int cursite)
{
	return location[cursite]->parent;
}
int LocationsPool::deleteSpecialItem(int slot, vector<int> loottypeindex)
{
	//DELETE THE ITEM
	for (int loc = 0; loc < LocationsPool::getInstance().lenpool(); loc++)

	{
		if (LocationsPool::getInstance().getRentingType(loc) == RENTING_NOCONTROL) continue;
		for (int l = 0; l < len(location[loc]->loot); l++)

		{
			if (!location[loc]->loot[l]->is_loot()) continue;
			if (getloottype(location[loc]->loot[l]->get_itemtypename()) == loottypeindex[slot])

			{
				location[loc]->loot[l]->decrease_number(1);
				if (location[loc]->loot[l]->empty())
					delete_and_remove(location[loc]->loot, l);
				return loottypeindex[slot];



			}
		}
	}
	return -1;
}
void LocationsPool::getAssetValues(long & weaponValue, long & armorValue, long & clipValue, long & lootValue)
{
	for (int j = 0; j < LocationsPool::getInstance().lenpool(); j++)
		for (int i = 0; i < len(location[j]->loot); i++)

		{
			Item* item = location[j]->loot[i];
			if (item->is_weapon()) weaponValue += item->get_fencevalue()*item->get_number();
			if (item->is_armor()) armorValue += item->get_fencevalue()*item->get_number();
			if (item->is_clip()) clipValue += item->get_fencevalue()*item->get_number();
			if (item->is_loot()) lootValue += item->get_fencevalue()*item->get_number();

		}
}
bool LocationsPool::canBeFortified(int cursite)
{
	return location[cursite]->can_be_fortified();
}
/* daily - seeds and names a site (will re-seed and rename if used after start) */
void initlocation(Location &loc);
void LocationsPool::initLocation(int cursite)
{
	initlocation(*location[cursite]);
}
void LocationsPool::equipLoc(int loc, int y)
{
	equip(location[loc]->loot, y);
}
void LocationsPool::delete_and_clear_pool()
{
	delete_and_clear(location);
}

bool LocationsPool::isThereASiegeHere(int cursite)
{
	return location[cursite]->siege.siege;
}

bool LocationsPool::isThisPlaceHighSecurity(int cursite)
{
	return location[cursite]->highsecurity;
}

void LocationsPool::isThereASiegeHere(int cursite, bool newCondition)
{
	location[cursite]->siege.siege = newCondition;
}

void LocationsPool::isThisPlaceHighSecurity(int cursite, int newCondition)
{
	location[cursite]->highsecurity = newCondition;
}

char LocationsPool::getLocationType(int cursite)
{
	return location[cursite]->type;
}

char LocationsPool::getSiegeType(int cursite)
{
	return location[cursite]->siege.siegetype;
}

char LocationsPool::getSiegeEscalationState(int cursite)
{
	return location[cursite]->siege.escalationstate;
}

char LocationsPool::getRentingType(int cursite)
{
	return location[cursite]->renting;
}
//#include "sitemode/sitemode.h"
void initsite(Location &loc);
void LocationsPool::initSite(int loc)
{
	initsite(*location[loc]);
}

void LocationsPool::eraseAndReplaceGraffiti(int cursite, int locx, int locy, int locz)
{

	// Erase any previous semi-permanent graffiti here
	for (int i = 0; i < len(location[cursite]->changes); i++)
	{
		if ((location[cursite]->changes[i].x == locx) &&
			(location[cursite]->changes[i].y == locy) &&
			(location[cursite]->changes[i].z == locz) &&
			((location[cursite]->changes[i].flag == SITEBLOCK_GRAFFITI) ||
				(location[cursite]->changes[i].flag == SITEBLOCK_GRAFFITI_CCS) ||
				(location[cursite]->changes[i].flag == SITEBLOCK_GRAFFITI_OTHER)))
		{
			location[cursite]->changes.erase(location[cursite]->changes.begin() + i);
			break;
		}
	}
	// Add new semi-permanent graffiti
	struct sitechangest change(locx, locy, locz, SITEBLOCK_GRAFFITI);
	location[cursite]->changes.push_back(change);
}

string LocationsPool::getLocationName(int cursite)
{
	return location[cursite]->getname();
}
#include "common/commonactionsCreature.h"
extern squadst *activesquad;
extern vector<squadst *> squad;
/* common - purges empty squads from existence */
void cleangonesquads()
{
	for (int sq = len(squad) - 1; sq >= 0; sq--)
	{  //NUKE SQUAD IF IT IS GONE
		bool hasmembers = false;
		for (int p = 0; p < 6; p++)
			if (squad[sq]->squad[p] != NULL)
			{  // Let's do a bit of housekeeping here
			   // And see if we can't gracefully eliminate that
			   // pesky dead liberal in my squad bug
				if (squad[sq]->squad[p]->alive == false)
				{
					removesquadinfo(*squad[sq]->squad[p]);
					p = -1; // restart this for loop
				}
				else hasmembers = true;
			}
		if (!hasmembers)
		{  //SQUAD LOOT WILL BE DESTROYED
			if (activesquad == squad[sq]) activesquad = NULL;
			delete_and_remove(squad, sq);
		}
		//OTHERWISE YOU CAN TAKE ITS MONEY (and other gear)
		else location[squad[sq]->squad[0]->base]->getloot(squad[sq]->loot);
	}
}
//#include "pdcurses/curses.h"
extern string singleDot;
extern short interface_pgup;
extern short interface_pgdn;
// Prompt to turn new recruit into a sleeper
void sleeperize_prompt(Creature &converted, Creature &recruiter, int y)
{
	bool selection = false;
	while (true)
	{
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(y, 0, "In what capacity will ");
		addstrAlt(converted.name);
		addstrAlt(" best serve the Liberal cause?");
		set_color_easy(selection ? WHITE_ON_BLACK : WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(y + 2, 0, selection ? "   " : "-> ");
		addstrAlt("Come to ");
		addstrAlt(location[recruiter.location]->getname(-1, true));
		addstrAlt(" as a ");
		set_color_easy(selection ? GREEN_ON_BLACK : GREEN_ON_BLACK_BRIGHT);
		addstrAlt("regular member");
		set_color_easy(selection ? WHITE_ON_BLACK : WHITE_ON_BLACK_BRIGHT);
		addstrAlt(singleDot);
		set_color_easy(selection ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
		mvaddstrAlt(y + 3, 0, selection ? "-> " : "   ");
		addstrAlt("Stay at ");
		addstrAlt(location[converted.worklocation]->getname(-1, true));
		addstrAlt(" as a ");
		set_color_easy(selection ? CYAN_ON_BLACK_BRIGHT : CYAN_ON_BLACK);
		addstrAlt("sleeper agent");
		set_color_easy(selection ? WHITE_ON_BLACK_BRIGHT : WHITE_ON_BLACK);
		addstrAlt(singleDot);
		int c = getkeyAlt();
		if ((c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) && selection)
		{
			converted.flag |= CREATUREFLAG_SLEEPER;
			converted.location = converted.worklocation;
			location[converted.worklocation]->mapped = 1;
			location[converted.worklocation]->hidden = 0;
			converted.base = converted.worklocation;
			liberalize(converted, false);
			break;
		}
		else if ((c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) && !selection)
		{
			converted.location = recruiter.location;
			converted.base = recruiter.base;
			liberalize(converted, false);
			break;
		}
		else if (c == interface_pgup || c == KEY_UP || c == KEY_LEFT ||
			c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) selection = !selection;
	}
}


extern bool multipleCityMode;

Location* find_site_in_city(int site_type, int city)
{
	int i = find_site_index_in_city(site_type, city);
	if (i != -1) return location[i];
	else return NULL;
}
int find_site_index_in_city(int site_type, int city)
{
	for (int i = 0; i<len(location); i++)
		if (location[i]->type == site_type && (!multipleCityMode || city == -1 || location[i]->city == city))
			return i;
	return -1;
}
int find_site_index_in_same_city(int site_type, int site_index)
{
	int city = -1;
	if (site_index >= 0) city = location[site_index]->city;
	return find_site_index_in_city(site_type, city);
}

void make_classic_world(bool hasmaps)
{
	Location* city = NULL;
	Location* district = NULL;
	Location* site = NULL;
	//int id = 0;
	if (city) district = city->addchild(SITE_DOWNTOWN);
	else location.push_back(district = new Location(SITE_DOWNTOWN));
	// = id++;
	district->area = 0;
	district->mapped = hasmaps; // for some reason this property isn't inherited by downtown locations so it's manually added for each one, need to debug why this happens
	site = district->addchild(SITE_RESIDENTIAL_APARTMENT_UPSCALE);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_GOVERNMENT_POLICESTATION);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_GOVERNMENT_COURTHOUSE);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_BUSINESS_BANK);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_GOVERNMENT_FIRESTATION);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_MEDIA_AMRADIO);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_MEDIA_CABLENEWS);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_BUSINESS_CIGARBAR);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_BUSINESS_LATTESTAND);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_BUSINESS_BARANDGRILL);
	// = id++;
	site->renting = RENTING_CCS;
	site->hidden = true;
	site->mapped = false;
	if (city) district = city->addchild(SITE_COMMERCIAL);
	else location.push_back(district = new Location(SITE_COMMERCIAL));
	// = id++;
	district->area = 0;
	site = district->addchild(SITE_BUSINESS_DEPTSTORE);
	// = id++;
	site = district->addchild(SITE_BUSINESS_PAWNSHOP);
	// = id++;
	site = district->addchild(SITE_BUSINESS_HALLOWEEN);
	// = id++;
	site = district->addchild(SITE_BUSINESS_CARDEALERSHIP);
	// = id++;
	if (city) district = city->addchild(SITE_UDISTRICT);
	else location.push_back(district = new Location(SITE_UDISTRICT));
	// = id++;
	district->area = 0;
	site = district->addchild(SITE_RESIDENTIAL_APARTMENT);
	// = id++;
	site = district->addchild(SITE_HOSPITAL_UNIVERSITY);
	// = id++;
	site = district->addchild(SITE_HOSPITAL_CLINIC);
	// = id++;
	site = district->addchild(SITE_LABORATORY_GENETIC);
	// = id++;
	site = district->addchild(SITE_LABORATORY_COSMETICS);
	// = id++;
	site = district->addchild(SITE_BUSINESS_VEGANCOOP);
	// = id++;
	site = district->addchild(SITE_BUSINESS_JUICEBAR);
	// = id++;
	site = district->addchild(SITE_BUSINESS_INTERNETCAFE);
	// = id++;
	site = district->addchild(SITE_OUTDOOR_PUBLICPARK);
	// = id++;
	if (city) district = city->addchild(SITE_INDUSTRIAL);
	else location.push_back(district = new Location(SITE_INDUSTRIAL));
	// = id++;
	district->area = 0;
	site = district->addchild(SITE_RESIDENTIAL_SHELTER);
	// = id++;
	site->renting = RENTING_PERMANENT;
	site = district->addchild(SITE_INDUSTRY_WAREHOUSE);
	// = id++;
	site->renting = RENTING_PERMANENT;
	site->upgradable = true;
	site = district->addchild(SITE_RESIDENTIAL_TENEMENT);
	// = id++;
	site = district->addchild(SITE_INDUSTRY_POLLUTER);
	// = id++;
	site = district->addchild(SITE_INDUSTRY_SWEATSHOP);
	// = id++;
	site = district->addchild(SITE_BUSINESS_CRACKHOUSE);
	// = id++;
	site->upgradable = true;
	site = district->addchild(SITE_RESIDENTIAL_BOMBSHELTER);
	// = id++;
	site->renting = RENTING_CCS;
	site->hidden = true;
	if (city) district = city->addchild(SITE_OUTOFTOWN);
	else location.push_back(district = new Location(SITE_OUTOFTOWN));
	// = id++;
	district->area = 1;
	site = district->addchild(SITE_GOVERNMENT_PRISON);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_INTELLIGENCEHQ);
	// = id++;
	site = district->addchild(SITE_INDUSTRY_NUCLEAR);
	// = id++;
	site = district->addchild(SITE_CORPORATE_HEADQUARTERS);
	// = id++;
	site = district->addchild(SITE_CORPORATE_HOUSE);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_ARMYBASE);
	// = id++;
	site = district->addchild(SITE_OUTDOOR_BUNKER);
	// = id++;
	site->renting = RENTING_CCS;
	site->hidden = true;
	if (city) district = city->addchild(SITE_TRAVEL);
	else location.push_back(district = new Location(SITE_TRAVEL));
	// = id++;
	district->area = 1;
	site = district->addchild(SITE_GOVERNMENT_WHITE_HOUSE);
	// = id++;
}
void make_world(bool hasmaps)
{
	if (!multipleCityMode)
	{
		make_classic_world(hasmaps);
		return;
	}
	//MAKE LOCATIONS
	Location* city = NULL;
	Location* district = NULL;
	Location* site = NULL;
	//int id = 0;
	// Seattle
	location.push_back(city = new Location(SITE_CITY_SEATTLE));
	// = id++;
	if (city) district = city->addchild(SITE_DOWNTOWN);
	else location.push_back(district = new Location(SITE_DOWNTOWN));
	// = id++;
	district->area = 0;
	district->mapped = hasmaps; // for some reason this property isn't inherited by downtown locations so it's manually added for each one, need to debug why this happens
	site = district->addchild(SITE_RESIDENTIAL_APARTMENT_UPSCALE);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_GOVERNMENT_POLICESTATION);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_GOVERNMENT_COURTHOUSE);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_BUSINESS_BANK);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_GOVERNMENT_FIRESTATION);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_MEDIA_AMRADIO);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_BUSINESS_CIGARBAR);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_BUSINESS_LATTESTAND);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_BUSINESS_DEPTSTORE);
	// = id++;
	site->mapped = hasmaps;
	site = district->addchild(SITE_BUSINESS_BARANDGRILL);
	// = id++;
	site->renting = RENTING_CCS;
	site->hidden = true;
	site->mapped = false;
	if (city) district = city->addchild(SITE_UDISTRICT);
	else location.push_back(district = new Location(SITE_UDISTRICT));
	// = id++;
	district->area = 0;
	site = district->addchild(SITE_RESIDENTIAL_APARTMENT);
	// = id++;
	site = district->addchild(SITE_HOSPITAL_UNIVERSITY);
	// = id++;
	site = district->addchild(SITE_HOSPITAL_CLINIC);
	// = id++;
	site = district->addchild(SITE_LABORATORY_GENETIC);
	// = id++;
	site = district->addchild(SITE_LABORATORY_COSMETICS);
	// = id++;
	site = district->addchild(SITE_BUSINESS_VEGANCOOP);
	// = id++;
	site = district->addchild(SITE_BUSINESS_JUICEBAR);
	// = id++;
	site = district->addchild(SITE_BUSINESS_INTERNETCAFE);
	// = id++;
	site = district->addchild(SITE_OUTDOOR_PUBLICPARK);
	// = id++;
	site = district->addchild(SITE_BUSINESS_HALLOWEEN);
	// = id++;
	if (city) district = city->addchild(SITE_INDUSTRIAL);
	else location.push_back(district = new Location(SITE_INDUSTRIAL));
	// = id++;
	district->area = 0;
	site = district->addchild(SITE_RESIDENTIAL_SHELTER);
	// = id++;
	site->renting = RENTING_PERMANENT;
	site = district->addchild(SITE_INDUSTRY_WAREHOUSE);
	// = id++;
	site->renting = RENTING_PERMANENT;
	site->upgradable = true;
	site = district->addchild(SITE_RESIDENTIAL_TENEMENT);
	// = id++;
	site = district->addchild(SITE_INDUSTRY_POLLUTER);
	// = id++;
	site = district->addchild(SITE_INDUSTRY_SWEATSHOP);
	// = id++;
	site = district->addchild(SITE_BUSINESS_CRACKHOUSE);
	// = id++;
	site->upgradable = true;
	site = district->addchild(SITE_BUSINESS_PAWNSHOP);
	// = id++;
	site = district->addchild(SITE_BUSINESS_CARDEALERSHIP);
	// = id++;
	if (city) district = city->addchild(SITE_OUTOFTOWN);
	else location.push_back(district = new Location(SITE_OUTOFTOWN));
	// = id++;
	district->area = 1;
	site = district->addchild(SITE_GOVERNMENT_PRISON);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_INTELLIGENCEHQ);
	// = id++;
	//site = district->addchild(SITE_INDUSTRY_NUCLEAR); 
	//// = id++;
	site = district->addchild(SITE_CORPORATE_HEADQUARTERS);
	// = id++;
	//site = district->addchild(SITE_CORPORATE_HOUSE); 
	//// = id++;
	site = district->addchild(SITE_GOVERNMENT_ARMYBASE);
	// = id++;
	// New York City
	location.push_back(city = new Location(SITE_CITY_NEW_YORK));
	// = id++;
	if (city) district = city->addchild(SITE_DOWNTOWN);
	else location.push_back(district = new Location(SITE_DOWNTOWN));
	// = id++;
	district->area = 0;
	strcpy(district->name, "Manhattan Island");
	strcpy(district->shortname, "Manhattan");
	//district->mapped = hasmaps;
	site = district->addchild(SITE_RESIDENTIAL_APARTMENT_UPSCALE);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_POLICESTATION);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_COURTHOUSE);
	// = id++;
	site = district->addchild(SITE_BUSINESS_BANK);
	// = id++;
	site = district->addchild(SITE_CORPORATE_HEADQUARTERS);
	// = id++;
	site = district->addchild(SITE_MEDIA_AMRADIO);
	// = id++;
	site = district->addchild(SITE_MEDIA_CABLENEWS);
	// = id++;
	site = district->addchild(SITE_BUSINESS_CIGARBAR);
	// = id++;
	//site = district->addchild(SITE_CORPORATE_HOUSE); 
	//// = id++;
	//site = district->addchild(SITE_GOVERNMENT_INTELLIGENCEHQ); 
	//// = id++;
	site = district->addchild(SITE_OUTDOOR_PUBLICPARK);
	// = id++;
	site = district->addchild(SITE_BUSINESS_DEPTSTORE);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_PRISON);
	// = id++;
	if (city) district = city->addchild(SITE_UDISTRICT);
	else location.push_back(district = new Location(SITE_UDISTRICT));
	// = id++;
	district->area = 0;
	strcpy(district->name, "Brooklyn & Queens");
	strcpy(district->shortname, "Long Island");
	site = district->addchild(SITE_INDUSTRY_WAREHOUSE);
	// = id++;
	site->renting = RENTING_PERMANENT;
	site->upgradable = true;
	site = district->addchild(SITE_RESIDENTIAL_APARTMENT);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_FIRESTATION);
	// = id++;
	site = district->addchild(SITE_HOSPITAL_UNIVERSITY);
	// = id++;
	site = district->addchild(SITE_HOSPITAL_CLINIC);
	// = id++;
	site = district->addchild(SITE_BUSINESS_JUICEBAR);
	// = id++;
	site = district->addchild(SITE_BUSINESS_INTERNETCAFE);
	// = id++;
	site = district->addchild(SITE_INDUSTRY_POLLUTER);
	// = id++;
	site = district->addchild(SITE_LABORATORY_GENETIC);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_ARMYBASE);
	// = id++;
	site = district->addchild(SITE_RESIDENTIAL_BOMBSHELTER);
	// = id++;
	site->renting = RENTING_CCS;
	site->hidden = true;
	if (city) district = city->addchild(SITE_INDUSTRIAL);
	else location.push_back(district = new Location(SITE_INDUSTRIAL));
	// = id++;
	district->area = 0;
	strcpy(district->name, "The Bronx");
	strcpy(district->shortname, "The Bronx");
	site = district->addchild(SITE_RESIDENTIAL_SHELTER);
	// = id++;
	site->renting = RENTING_PERMANENT;
	site = district->addchild(SITE_RESIDENTIAL_TENEMENT);
	// = id++;
	site = district->addchild(SITE_INDUSTRY_POLLUTER);
	// = id++;
	site = district->addchild(SITE_INDUSTRY_SWEATSHOP);
	// = id++;
	site = district->addchild(SITE_LABORATORY_COSMETICS);
	// = id++;
	site = district->addchild(SITE_BUSINESS_VEGANCOOP);
	// = id++;
	site = district->addchild(SITE_BUSINESS_PAWNSHOP);
	// = id++;
	site = district->addchild(SITE_BUSINESS_CARDEALERSHIP);
	// = id++;
	site = district->addchild(SITE_BUSINESS_CRACKHOUSE);
	// = id++;
	site->upgradable = true;
	site = district->addchild(SITE_OUTDOOR_PUBLICPARK);
	// = id++;
	if (city) district = city->addchild(SITE_OUTOFTOWN);
	else location.push_back(district = new Location(SITE_OUTOFTOWN));
	// = id++;
	district->area = 1;
	site = district->addchild(SITE_INDUSTRY_NUCLEAR);
	// = id++;
	// Los Angeles
	location.push_back(city = new Location(SITE_CITY_LOS_ANGELES));
	// = id++;
	if (city) district = city->addchild(SITE_DOWNTOWN);
	else location.push_back(district = new Location(SITE_DOWNTOWN));
	// = id++;
	district->area = 0;
	//district->mapped = hasmaps;
	site = district->addchild(SITE_RESIDENTIAL_SHELTER);
	// = id++;
	site->renting = RENTING_PERMANENT;
	site = district->addchild(SITE_RESIDENTIAL_APARTMENT);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_POLICESTATION);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_COURTHOUSE);
	// = id++;
	site = district->addchild(SITE_BUSINESS_BANK);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_FIRESTATION);
	// = id++;
	site = district->addchild(SITE_CORPORATE_HEADQUARTERS);
	// = id++;
	site = district->addchild(SITE_HOSPITAL_UNIVERSITY);
	// = id++;
	site = district->addchild(SITE_BUSINESS_DEPTSTORE);
	// = id++;
	if (city) district = city->addchild(SITE_UDISTRICT);
	else location.push_back(district = new Location(SITE_UDISTRICT));
	// = id++;
	district->area = 0;
	strcpy(district->name, "Greater Hollywood");
	strcpy(district->shortname, "Hollywood");
	site = district->addchild(SITE_RESIDENTIAL_APARTMENT_UPSCALE);
	// = id++;
	site = district->addchild(SITE_BUSINESS_VEGANCOOP);
	// = id++;
	site = district->addchild(SITE_BUSINESS_HALLOWEEN);
	// = id++;
	site = district->addchild(SITE_BUSINESS_CIGARBAR);
	// = id++;
	//site = district->addchild(SITE_MEDIA_CABLENEWS); 
	//// = id++;
	site = district->addchild(SITE_MEDIA_AMRADIO);
	// = id++;
	site = district->addchild(SITE_OUTDOOR_PUBLICPARK);
	// = id++;
	site = district->addchild(SITE_CORPORATE_HOUSE);
	// = id++;
	if (city) district = city->addchild(SITE_INDUSTRIAL);
	else location.push_back(district = new Location(SITE_INDUSTRIAL));
	// = id++;
	district->area = 0;
	strcpy(district->name, "Seaport Area");
	strcpy(district->shortname, "Seaport");
	site = district->addchild(SITE_INDUSTRY_WAREHOUSE);
	// = id++;
	site->renting = RENTING_PERMANENT;
	site->upgradable = true;
	site = district->addchild(SITE_RESIDENTIAL_TENEMENT);
	// = id++;
	site = district->addchild(SITE_HOSPITAL_CLINIC);
	// = id++;
	site = district->addchild(SITE_LABORATORY_GENETIC);
	// = id++;
	site = district->addchild(SITE_LABORATORY_COSMETICS);
	// = id++;
	site = district->addchild(SITE_INDUSTRY_POLLUTER);
	// = id++;
	site = district->addchild(SITE_BUSINESS_PAWNSHOP);
	// = id++;
	site = district->addchild(SITE_INDUSTRY_SWEATSHOP);
	// = id++;
	site = district->addchild(SITE_BUSINESS_CARDEALERSHIP);
	// = id++;
	site = district->addchild(SITE_BUSINESS_CRACKHOUSE);
	// = id++;
	site->upgradable = true;
	if (city) district = city->addchild(SITE_OUTOFTOWN);
	else location.push_back(district = new Location(SITE_OUTOFTOWN));
	// = id++;
	district->area = 1;
	strcpy(district->name, "Outskirts & Orange County");
	site = district->addchild(SITE_GOVERNMENT_PRISON);
	// = id++;
	//site = district->addchild(SITE_GOVERNMENT_INTELLIGENCEHQ); 
	// = id++;
	site = district->addchild(SITE_INDUSTRY_NUCLEAR);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_ARMYBASE);
	// = id++;
	site = district->addchild(SITE_OUTDOOR_BUNKER);
	// = id++;
	site->renting = RENTING_CCS;
	site->hidden = true;
	// Washington, DC
	location.push_back(city = new Location(SITE_CITY_WASHINGTON_DC));
	// = id++;
	if (city) district = city->addchild(SITE_DOWNTOWN);
	else location.push_back(district = new Location(SITE_DOWNTOWN));
	// = id++;
	district->area = 0;
	strcpy(district->name, "Downtown");
	//district->mapped = hasmaps;
	site = district->addchild(SITE_GOVERNMENT_POLICESTATION);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_FIRESTATION);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_COURTHOUSE);
	// = id++;
	site = district->addchild(SITE_BUSINESS_BANK);
	// = id++;
	site = district->addchild(SITE_BUSINESS_CARDEALERSHIP);
	// = id++;
	site = district->addchild(SITE_HOSPITAL_CLINIC);
	// = id++;
	site = district->addchild(SITE_HOSPITAL_UNIVERSITY);
	// = id++;
	site = district->addchild(SITE_BUSINESS_DEPTSTORE);
	// = id++;
	site = district->addchild(SITE_RESIDENTIAL_SHELTER);
	// = id++;
	site->renting = RENTING_PERMANENT;
	if (city) district = city->addchild(SITE_UDISTRICT);
	else location.push_back(district = new Location(SITE_UDISTRICT));
	// = id++;
	district->area = 0;
	strcpy(district->name, "National Mall");
	strcpy(district->shortname, "Mall");
	site = district->addchild(SITE_OUTDOOR_PUBLICPARK);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_WHITE_HOUSE);
	// = id++;
	if (city) district = city->addchild(SITE_OUTOFTOWN);
	else location.push_back(district = new Location(SITE_OUTOFTOWN));
	// = id++;
	district->area = 1;
	strcpy(district->name, "Arlington");
	site = district->addchild(SITE_GOVERNMENT_PRISON);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_INTELLIGENCEHQ);
	// = id++;
	site = district->addchild(SITE_GOVERNMENT_ARMYBASE);
	// = id++;
	//location.push_back(city = new Location(SITE_CITY_CHICAGO));
	//// = id++;
	//location.push_back(city = new Location(SITE_CITY_DETROIT));
	//// = id++;
	//location.push_back(city = new Location(SITE_CITY_ATLANTA));
	//// = id++;
	//location.push_back(city = new Location(SITE_CITY_MIAMI));
	//// = id++;
}


// Finds a location with the corresponding type and returns
// its index in the location array
int findlocation(int type, int city = -1)
{
	if (!multipleCityMode) city = -1;
	for (int i = 0; i < len(location); i++)
		if (location[i]->type == type && (location[i]->city == city || city == -1)) return i;
	return -1;
}
// Locations - Construct a new location with the specified parameters
#include "daily/daily.h"
Location::Location(char type_, int parent_)
	: type(type_), city(-1), parent(parent_), renting(RENTING_NOCONTROL), needcar(false), hidden(false), upgradable(false)
{
	if (this->parent != -1)
	{
		this->needcar = location[this->parent]->needcar;
		this->mapped = location[this->parent]->mapped;
		this->area = location[this->parent]->area;
		this->city = location[this->parent]->city;
	}
	if (this->city < 0 && multipleCityMode)
		this->city = this->type;
	initlocation(*this);
}
Location* Location::addchild(char type_)
{
	Location *newloc = new Location(type_, findlocation(this->type, this->city));
	location.push_back(newloc);
	return newloc;
}
/* Settings for shortname_ (true is 1 and false is 0, by the way):
* -1: entire name is long, no matter what
*  0: first part of place name is long, and if there's a city at the end it's short
*  1: first part of the name is short unless the place itself is a city in which case it's long, and if there's a city at the end it's short
*  2: entire name is short, no matter what */
extern string singleSpace;
extern string commaSpace;
string Location::getname(signed char shortname_, bool include_city)
{
	string str;
	if (!multipleCityMode) include_city = false;
	if ((shortname_ >= 1 && type != city) || shortname_ >= 2) {
		if (this->front_business != -1)
			str = this->front_shortname;
		else
			str = this->shortname;
	}
	else {
		if (this->front_business != -1)
			str = this->front_name;
		else
			str = this->name;
	}
	if (include_city&&type != city) {
		string cityname = location[findlocation(city, city)]->getname(shortname_ + 2);
		if (str == "Downtown")
			return str + singleSpace + cityname;
		if (str == "University District" || str == "U-District" || str == "Industrial District" || str == "I-District" ||
			str == "Shopping" || str == "Outskirts" || str == "Seaport Area" || str == "Seaport" || str == "Outskirts & Orange County")
			return cityname + singleSpace + str;
		if (str == "City Outskirts")
			return cityname + " Outskirts";
		if (str == "Arlington")
			return str + (shortname_ < 0 ? ", Virginia" : ", VA");
		if (str == "Hollywood" || str == "Greater Hollywood")
			return str + (shortname_ < 0 ? ", California" : ", CA");
		if (str == "Manhattan" || str == "Manhattan Island" || str == "Brooklyn & Queens" || str == "Long Island" || str == "The Bronx")
			return str + (shortname_ < 0 ? ", New York" : ", NY");
		str += commaSpace + cityname;
	}
	return str;
}
bool Location::duplicatelocation()
{
	for (int l = 0; l < len(location); l++)
	{
		if (location[l] == this)
			continue;
		if (type != SITE_RESIDENTIAL_SHELTER&&!strcmp(location[l]->name, this->name))
			return true;
		if (location[l]->front_business != -1 && this->front_business != -1 &&
			!strcmp(location[l]->front_shortname, this->front_shortname))
			return true;
	}
	return 0;
}
extern short lawList[LAWNUM];
void Location::update_heat_protection()
{
	int l;
	for (l = 0; l < len(location); l++)
	{
		if (location[l] == this)
			break;
	}
	if (l == len(location))
	{
		heat_protection = 0;
		return;
	}
	int numpres = CreaturePool::getInstance().howManyLivingPeopleAreHere(l);
	heat_protection = 0;
	// Determine how effective your current safehouse
	// is at keeping the police confused
	switch (location[l]->type)
	{
	case SITE_INDUSTRY_WAREHOUSE:
		if (location[l]->front_business != -1)
			heat_protection += 12; // Business front -- high protection
		else
			heat_protection += 0; // Abandoned warehouse -- no protection
		break;
	case SITE_RESIDENTIAL_SHELTER:
		heat_protection += 0; // Homeless shelter -- no protection
		break;
	case SITE_RESIDENTIAL_TENEMENT:
		heat_protection += 4; // Lower class housing -- low protection
		break;
	case SITE_RESIDENTIAL_APARTMENT:
		heat_protection += 8; // Middle class housing -- medium protection
		break;
	case SITE_RESIDENTIAL_BOMBSHELTER:
	case SITE_OUTDOOR_BUNKER:
	case SITE_BUSINESS_BARANDGRILL:
	case SITE_RESIDENTIAL_APARTMENT_UPSCALE:
		heat_protection += 12; // Upper class housing -- high protection
		break;
	}
	if (lawList[LAW_FLAGBURNING] == -2 && location[l]->haveflag) heat_protection += 6; // More protection if the flag is sacred
	else if (lawList[LAW_FLAGBURNING] != -2 && location[l]->haveflag) heat_protection += 2; // Some if the flag isn't
	else if (lawList[LAW_FLAGBURNING] == -2 && !(location[l]->haveflag)) heat_protection -= 2; // Lose some if it is and you have no flag
	else {} // None if it isn't and you have no flag
	if (heat_protection < 0) heat_protection = 0;
	heat_protection *= 5;
	if (heat_protection > 95) heat_protection = 95;
}
typedef map<short, string > shortAndString;
shortAndString getActivityString;
extern vector<ArmorType *> armortype;

std::string getactivity(activityst &act)
{
	if (getActivityString.count(act.type)) {
		return getActivityString[act.type];
	}
	else
		switch (act.type)
		{
		case ACTIVITY_HOSTAGETENDING:
		{
			std::string str = "Tending to ";
			int pl = getpoolcreature(act.arg);
			if (pl != -1) return str + CreaturePool::getInstance().getName(pl);
			else return str + "a bug";
		}
		case ACTIVITY_MAKE_ARMOR:
			return "Making " + armortype[act.arg]->get_shortname();
		case ACTIVITY_VISIT:
			return "Going to " + location[act.arg]->getname(!location[act.arg]->is_city());
		default:
			return "Reporting Bugs to the Dev Team";
		}
}
/* daily - manages too hot timer and when a site map should be re-seeded and renamed */
void advancelocations()
{
	//ADVANCE LOCATIONS
	for (int l = 0; l < len(location); l++)
	{
		if (location[l]->closed > 0)
		{
			location[l]->closed--;
			if (location[l]->closed == 0)
			{  //Clean up graffiti, patch up walls, restore fire damage
				location[l]->changes.clear();
				//If high security is supported, chance to throw guards everywhere
				if (securityable(location[l]->type) && LCSrandom(2))
					location[l]->highsecurity = 60;
				//Else remodel the location, invalidate maps
				else initlocation(*location[l]);
			}
		}
		else if (location[l]->highsecurity > 0)
		{  // Bank will remain on high security much longer
			if (location[l]->type != SITE_BUSINESS_BANK)
				location[l]->highsecurity--;
			else if (!LCSrandom(5))
				location[l]->highsecurity--;
		}
	}
}


bool Creature::is_imprisoned() const
{
	return(alive && clinic == 0 && dating == 0 && hiding == 0 &&
		!(flag & CREATUREFLAG_SLEEPER) &&
		::location[this->location]->part_of_justice_system());
}
bool Creature::is_active_liberal() const
{
	return(alive && align == ALIGN_LIBERAL && clinic == 0 && dating == 0 &&
		hiding == 0 && !(flag & CREATUREFLAG_SLEEPER) &&
		!::location[this->location]->part_of_justice_system());
}

/* prompt user to enter an amount of items to equip, move, or sell */
long prompt_amount(long min, long max)
{
	printparty();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 15, "     How many?          ");
	char str[100];
	enter_name(8, 30, str, 100, toCstring(max));
	int amount = atoi(str);
	amount = std::max((long)amount, min);
	amount = std::min((long)amount, max);
	return amount;
}
extern string spaceDashSpace;
extern string enter_done;
extern string chooseALiberalTo;
/* review squad equipment */
void equip(vector<Item *> &loot, int loc)
{
	if (activesquad == NULL) return;
	consolidateloot(loot);
	if (loc != -1) consolidateloot(location[loc]->loot);
	int page = 0;
	const char *errmsg = NULL;
	while (true)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(0, 0, "Equip the Squad");
		printparty();
		if (errmsg) {
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 20, errmsg);
			set_color_easy(WHITE_ON_BLACK);
			errmsg = NULL;
		}
		int x = 1, y = 10;
		char str[200];
		//char str2[200];
		for (int l = page * 18; l < len(loot) && l < page * 18 + 18; l++)
		{
			string s = loot[l]->equip_title();
			if (loot[l]->get_number() > 1)
				s += " x" + tostring(loot[l]->get_number());
			str[0] = l - page * 18 + 'A';
			str[1] = '\x0';
			strcat(str, spaceDashSpace);
			strcat(str, s);
			mvaddstrAlt(y, x, str);
			x += 26;
			if (x > 53) x = 1, y++;
		}
		//PAGE UP
		if (page > 0)
		{
			mvaddstrAlt(17, 1, addprevpagestr());
		}
		//PAGE DOWN
		if ((page + 1) * 18 < len(loot))
		{
			mvaddstrAlt(17, 53, addnextpagestr());
		}
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(19, 1, "Press a letter to equip a Liberal item");
		mvaddstrAlt(20, 1, "Press a number to drop that Squad member's Conservative weapon");
		mvaddstrAlt(21, 1, "S - Liberally Strip a Squad member");
		mvaddstrAlt(22, 1, "Cursors - Increase or decrease ammo allocation");
		if (loc != -1)
		{
			if (len(location[loc]->loot)) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(23, 1, "Y - Get things from ");
			addstrAlt(location[loc]->getname(true));
			if (len(loot)) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(23, 40, "Z - Stash things at ");
			addstrAlt(location[loc]->getname(true));
		}
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(24, 1, enter_done);
		int c = getkeyAlt();
		bool increaseammo = (c == KEY_UP), decreaseammo = (c == KEY_DOWN);
		if ((c >= 'a'&&c <= 'r') || increaseammo || decreaseammo)
		{
			int slot = c - 'a' + page * 18;
			if (increaseammo || decreaseammo) slot = -999;
			else
			{
				if (slot < 0 || slot >= len(loot)) continue; // Out of range.
				else if (!loot[slot]->is_weapon()
					&& !loot[slot]->is_armor()
					&& !loot[slot]->is_clip())
				{
					errmsg = "You can't equip that.";
					continue;
				}
			}
			bool choice = true;
			if (activesquad->squad[0])
			{
				choice = false;
				for (int c = 1; c < 6; c++)
					if (activesquad->squad[c]) //are these slots always filled in order?
					{
						choice = true;
						break;
					}
			}
			int c = '1';
			if (choice)
			{
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				moveAlt(8, 20);
				if (increaseammo)
					addstrAlt(chooseALiberalTo + "receive a clip.");
				else if (decreaseammo)
					addstrAlt(chooseALiberalTo + "drop a clip.");
				else addstrAlt(chooseALiberalTo + "receive it.");
				c = getkeyAlt();
			}
			if (c >= '1'&&c <= '6')
			{
				// TODO Relocate this to a new file
				// to allow removal of creature.h
				Creature *squaddie = activesquad->squad[c - '1'];
				if (squaddie)
				{
					if (decreaseammo)
					{
						if (len(squaddie->clips))
						{
							loot.push_back(squaddie->clips.back()->split(1));
							if (squaddie->clips.back()->empty())
								squaddie->clips.pop_back();
						}
						else if (!squaddie->get_weapon().uses_ammo())
						{
							errmsg = "No ammo to drop!";
							continue;
						}
						else
						{
							errmsg = "No spare clips!";
							continue;
						}
						consolidateloot(loot);
						continue;
					}
					if (increaseammo)
					{
						if (!squaddie->get_weapon().uses_ammo())
						{
							errmsg = "No ammo required!";
							continue;
						}
						slot = -1;
						for (int sl = 0; sl < len(loot); sl++)
						{
							if (loot[sl]->is_clip() && squaddie->get_weapon().acceptable_ammo(*loot[sl]))
							{
								slot = sl;
								break;
							}
							else if (loot[sl]->is_weapon() && loot[sl]->is_same_type(squaddie->get_weapon())) //For throwing weapons. -XML
							{
								Weapon* w = static_cast<Weapon*>(loot[sl]); //cast -XML
								if (w->is_throwable())
								{
									slot = sl;
									break;
								}
							}
						}
						if (slot == -1)
						{
							errmsg = "No ammo available!";
							continue;
						}
					}
					int armok = 2;
					if ((squaddie->wound[BODYPART_ARM_RIGHT] & WOUND_NASTYOFF) ||
						(squaddie->wound[BODYPART_ARM_RIGHT] & WOUND_CLEANOFF)) armok--;
					if ((squaddie->wound[BODYPART_ARM_LEFT] & WOUND_NASTYOFF) ||
						(squaddie->wound[BODYPART_ARM_LEFT] & WOUND_CLEANOFF)) armok--;
					if (squaddie->special[SPECIALWOUND_NECK] != 1) armok = 0;
					if (squaddie->special[SPECIALWOUND_UPPERSPINE] != 1) armok = 0;
					if (loot[slot]->is_weapon() && armok)
					{
						Weapon* w = static_cast<Weapon*>(loot[slot]); //cast -XML
						squaddie->give_weapon(*w, &loot);
						if (loot[slot]->empty()) delete_and_remove(loot, slot);
						if (page * 18 >= len(loot) && page != 0) page--;
					}
					else if (loot[slot]->is_armor())
					{
						Armor* a = static_cast<Armor*>(loot[slot]); //cast -XML
						squaddie->give_armor(*a, &loot);
						if (loot[slot]->empty()) delete_and_remove(loot, slot);
						if (page * 18 >= len(loot) && page != 0) page--;
					}
					else if (loot[slot]->is_clip() && armok)
					{
						int space = 9 - squaddie->count_clips();
						if (!squaddie->get_weapon().uses_ammo())
						{
							errmsg = "Can't carry ammo without a gun."; continue;
						}
						else if (!squaddie->get_weapon().acceptable_ammo(*loot[slot]))
						{
							errmsg = "That ammo doesn't fit."; continue;
						}
						else if (space < 1)
						{
							errmsg = "Can't carry any more ammo."; continue;
						}
						else
						{
							int amount = 1;
							if (loot[slot]->get_number()>1 && !increaseammo)
								amount = prompt_amount(0, min((int)loot[slot]->get_number(), space));
							squaddie->take_clips(*loot[slot], amount);
							if (loot[slot]->empty()) delete_and_remove(loot, slot);
							if (page * 18 >= len(loot) && page != 0) page--;
						}
					}
					consolidateloot(loot);
				}
			}
		}
		if (c == 's')
		{
			bool choice = true;
			if (activesquad->squad[0])
			{
				choice = false;
				for (int c = 1; c < 6; c++)
					if (activesquad->squad[c])
					{
						choice = true; break;
					}
			}
			int c = '1';
			if (choice)
			{
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8, 20, chooseALiberalTo + "strip down.");
				c = getkeyAlt();
			}
			if (c >= '1'&&c <= '6')
				if (activesquad->squad[c - '1'])
				{
					activesquad->squad[c - '1']->strip(&loot);
					consolidateloot(loot);
				}
		}
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) return;
		if (loc != -1)
		{
			if (c == 'y'&&len(location[loc]->loot)) moveloot(loot, location[loc]->loot);
			if (c == 'z'&&len(loot)) moveloot(location[loc]->loot, loot);
		}
		if (c >= '1'&&c <= '6')
		{
			int p = c - '1';
			if (activesquad->squad[p] != NULL)
			{
				activesquad->squad[p]->drop_weapons_and_clips(&loot);
				consolidateloot(loot);
			}
		}
		//PAGE UP
		if ((c == interface_pgup || c == KEY_UP || c == KEY_LEFT) && page>0) page--;
		//PAGE DOWN
		if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page + 1) * 18<len(loot)) page++;
	}
}
/* lets you pick stuff to stash/retrieve from one location to another */
void moveloot(vector<Item *> &dest, vector<Item *> &source)
{
	int page = 0;
	vector<int> selected(len(source), 0);
	while (true)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(0, 0, "Select Objects");
		printparty();
		int x = 1, y = 10;
		char str[200];
		for (int l = page * 18; l < len(source) && l < page * 18 + 18; l++)
		{
			if (selected[l]) set_color_easy(GREEN_ON_BLACK_BRIGHT);
			else set_color_easy(WHITE_ON_BLACK);
			string s = source[l]->equip_title();
			if (source[l]->get_number() > 1)
			{
				s += singleSpace;
				if (selected[l] > 0) s += tostring(selected[l]) + "/";
				else s += "x";
				s += tostring(source[l]->get_number());
			}
			str[0] = l - page * 18 + 'A';
			str[1] = '\x0';
			strcat(str, spaceDashSpace);
			strcat(str, s);
			mvaddstrAlt(y, x, str);
			x += 26;
			if (x > 53) x = 1, y++;
		}
		//PAGE UP
		set_color_easy(WHITE_ON_BLACK);
		if (page > 0)
		{
			mvaddstrAlt(17, 1, addprevpagestr());
		}
		//PAGE DOWN
		if ((page + 1) * 18 < len(source))
		{
			mvaddstrAlt(17, 53, addnextpagestr());
		}
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(23, 1, "Press a letter to select an item.");
		mvaddstrAlt(24, 1, enter_done);
		int c = getkeyAlt();
		if (c >= 'a'&&c <= 'r')
		{
			int slot = c - 'a' + page * 18;
			if (slot >= 0 && slot < len(source))
			{
				if (selected[slot]) selected[slot] = 0;
				else if (source[slot]->get_number()>1)
					selected[slot] = prompt_amount(0, source[slot]->get_number());
				else selected[slot] = 1;
			}
		}
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) break;
		//PAGE UP
		if ((c == interface_pgup || c == KEY_UP || c == KEY_LEFT) && page>0) page--;
		//PAGE DOWN
		if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page + 1) * 18<len(source)) page++;
	}
	for (int l = len(source) - 1; l >= 0; l--) if (selected[l] > 0)
	{
		if (source[l]->get_number() <= selected[l])
		{
			dest.push_back(source[l]);
			source.erase(source.begin() + l);
		}
		else
		{
			Item* newit = source[l]->split(selected[l]);
			dest.push_back(newit);
		}
	}
	// Avoid stuff jumping around the next time you equip.
	consolidateloot(dest);
}
/* equipment - assign new bases to the equipment */
void equipmentbaseassign()
{
	int p = 0, l = 0, page_loot = 0, page_loc = 0, selectedbase = 0;
	bool sortbytype = false;
	vector<Item *> temploot;
	map<Item *, Location *> temploot2;
	for (l = 0; l < len(location); l++) for (int l2 = 0; l2 < len(location[l]->loot); l2++)
		if (!location[l]->siege.siege)
		{
			temploot.push_back(location[l]->loot[l2]);
			temploot2[location[l]->loot[l2]] = location[l];
		}
	if (!len(temploot)) return;
	vector<int> temploc;
	for (l = 0; l < len(location); l++) if (location[l]->renting >= 0 && !location[l]->siege.siege)
		temploc.push_back(l);
	if (!len(temploc)) return;
	while (true)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK);
		printfunds();
		mvaddstrAlt(0, 0, "Moving Equipment");
		mvaddstrAlt(1, 0, "컴컴ITEM컴컴컴컴컴컴컴컴횮URRENT LOCATION컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�");
		mvaddstrAlt(1, 51, "NEW LOCATION");
		int y = 2;
		for (p = page_loot * 19; p < len(temploot) && p < page_loot * 19 + 19; p++, y++)
		{
			set_color_easy(WHITE_ON_BLACK);
			moveAlt(y, 0);
			addcharAlt(y + 'A' - 2); addstrAlt(spaceDashSpace);
			addstrAlt(temploot[p]->equip_title());
			mvaddstrAlt(y, 25, temploot2[temploot[p]]->getname(true, true));
		}
		y = 2;
		for (p = page_loc * 9; p < len(temploc) && p < page_loc * 9 + 9; p++, y++)
		{
			if (p == selectedbase)set_color_easy(WHITE_ON_BLACK_BRIGHT);
			else set_color_easy(WHITE_ON_BLACK);
			moveAlt(y, 51);
			addcharAlt(y + '1' - 2); addstrAlt(spaceDashSpace);
			addstrAlt(location[temploc[p]]->getname(true, true));
		}
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(22, 0, "Press a Letter to assign a base.  Press a Number to select a base.");
		moveAlt(23, 0);
		if (sortbytype) addstrAlt("T to sort by location.");
		else addstrAlt("T to sort by type.");
		addstrAlt("  Shift and a Number will move ALL items!");
		moveAlt(24, 0); // location for either viewing other base pages or loot pages
		if (len(temploc) > 9)
		{
			addstrAlt(",. to view other base pages.");
			moveAlt(24, 34); // we have base pages, so different location for viewing other loot pages
		}
		if (len(temploot) > 19)
			addstrAlt(addpagestr());
		int c = getkeyAlt();
		//PAGE UP (items)
		if ((c == interface_pgup || c == KEY_UP || c == KEY_LEFT) && page_loot>0) page_loot--;
		//PAGE DOWN (items)
		if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page_loot + 1) * 19<len(temploot)) page_loot++;
		//PAGE UP (locations)
		if (c == ','&&page_loc > 0) page_loc--;
		//PAGE DOWN (locations)
		if (c == '.' && (page_loc + 1) * 9 < len(temploc)) page_loc++;
		//Toggle sorting method
		if (c == 't')
		{
			sortbytype = !sortbytype;
			if (sortbytype) sort(temploot.begin(), temploot.end(), Item::sort_compare);
			else
			{  //Sort by location
				temploot.clear();
				for (l = 0; l < len(location); l++) for (int l2 = 0; l2 < len(location[l]->loot); l2++)
					if (!location[l]->siege.siege) temploot.push_back(location[l]->loot[l2]);
			}
		}
		if (c >= 'a'&&c <= 's')
		{
			int p = page_loot * 19 + c - 'a';
			if (p < len(temploot))
				// Search through the old base's stuff for this item
				for (int l2 = 0; l2 < len(temploot2[temploot[p]]->loot); l2++)
					// Remove it from that inventory and move it to the new one
					if (temploot2[temploot[p]]->loot[l2] == temploot[p])
					{
						temploot2[temploot[p]]->loot.erase(temploot2[temploot[p]]->loot.begin() + l2);
						location[temploc[selectedbase]]->loot.push_back(temploot[p]);
						temploot2[temploot[p]] = location[temploc[selectedbase]];
					}
		}
		if (c >= '1'&&c <= '9')
		{
			int p = page_loc * 9 + c - '1';
			if (p < len(temploc)) selectedbase = p;
		}
		// Check if the player wants to move all items to a new location,
		// using Shift + a number key.
		const char upnums[] = "!@#$%^&*(";
		for (int upnumi = 0; upnumi < len(upnums); upnumi++)
		{
			if (c == upnums[upnumi])
			{
				// Set base location
				int basechoice = page_loc * 9 + upnumi;
				if (basechoice < len(temploc))
				{
					selectedbase = basechoice;
					// Search through the old base's stuff for this item
					for (int p = 0; p < len(temploot); p++)
						// Search through the old base's stuff for this item
						for (int l2 = 0; l2 < len(temploot2[temploot[p]]->loot); l2++)
							// Remove it from that inventory and move it to the new one
							if (temploot2[temploot[p]]->loot[l2] == temploot[p])
							{
								temploot2[temploot[p]]->loot.erase(temploot2[temploot[p]]->loot.begin() + l2);
								location[temploc[selectedbase]]->loot.push_back(temploot[p]);
								temploot2[temploot[p]] = location[temploc[selectedbase]];
							}
				}
			}
		}
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) break;
	}
}
/* combines multiple items of the same type into stacks */
void consolidateloot(vector<Item *> &loot)
{
	int l, l2;
	//PUT THINGS TOGETHER
	for (l = len(loot) - 1; l >= 1; l--) for (l2 = l - 1; l2 >= 0; l2--)
	{
		loot[l2]->merge(*loot[l]);
		if (loot[l]->empty())
		{
			delete_and_remove(loot, l); break;
		}
	}
	sort(loot.begin(), loot.end(), Item::sort_compare);
}
/* check if the squad has a certain weapon */
char squadhasitem(squadst &sq, const string& type)
{
	if (getweapontype(type) == -1) return 0;
	for (int p = 0; p < 6; p++) if (sq.squad[p])
		if (sq.squad[p]->get_weapon().get_itemtypename() == type) return 1;
	for (int l = 0; l < len(sq.loot); l++)
	{
		if (sq.loot[l]->get_itemtypename() != type) continue;
		if (sq.loot[l]->is_weapon() && sq.loot[l]->get_itemtypename() == type) return 1;
	}
	return 0;
}
#include "daily/siege.h"
/* location info at top of screen */
void printlocation(long loc)
{
	if (location[loc]->siege.siege)
	{
		if (!location[loc]->siege.underattack)
		{
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			mvaddstrAlt(2, 1, "The police have surrounded this location.");
		}
		else
		{
			set_color_easy(RED_ON_BLACK_BRIGHT);
			switch (location[loc]->siege.siegetype)
			{
			case SIEGE_POLICE:
				mvaddstrAlt(2, 1, "The police are raiding this location!"); break;
			case SIEGE_CIA:
				mvaddstrAlt(2, 1, "The CIA is raiding this location!"); break;
			case SIEGE_HICKS:
				mvaddstrAlt(2, 1, "The masses are storming this location!"); break;
			case SIEGE_CORPORATE:
				mvaddstrAlt(2, 1, "The Corporations are raiding this location!"); break;
			case SIEGE_CCS:
				mvaddstrAlt(2, 1, "The CCS is raiding this location!"); break;
			case SIEGE_FIREMEN:
				mvaddstrAlt(2, 1, "Firemen are raiding this location!"); break;
			}
		}
	}
	else
	{
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(2, 1, "You are not under siege...  yet.");
	}
	if (location[loc]->can_be_upgraded())
	{
		if (numbereating(loc)>0)
		{
			if (fooddaysleft(loc))
			{
				if (fooddaysleft(loc)<4)
				{
					if (!location[loc]->siege.siege)set_color_easy(WHITE_ON_BLACK);
					else set_color_easy(YELLOW_ON_BLACK_BRIGHT);
					mvaddstrAlt(3, 1, "This location has food for only a few days.");
				}
			}
			else
			{
				if (!location[loc]->siege.siege)set_color_easy(WHITE_ON_BLACK);
				else set_color_easy(RED_ON_BLACK_BRIGHT);
				mvaddstrAlt(3, 1, "This location has insufficient food stores.");
			}
		}
		if (location[loc]->compound_walls & COMPOUND_BASIC)
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(4, 1, "FORTIFIED COMPOUND");
		}
		if (location[loc]->compound_walls & COMPOUND_PRINTINGPRESS)
		{
			set_color_easy(BLUE_ON_BLACK_BRIGHT);
			mvaddstrAlt(4, 31, "PRINTING PRESS");
		}
		if (location[loc]->front_business != -1)
		{
			set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
			mvaddstrAlt(4, 54, "BUSINESS FRONT");
		}
		if (location[loc]->compound_walls & COMPOUND_CAMERAS)
		{
			if (location[loc]->siege.siege&&location[loc]->siege.cameras_off)
			{
				set_color_easy(RED_ON_BLACK);
				mvaddstrAlt(5, 1, "CAMERAS OFF");
			}
			else
			{
				set_color_easy(GREEN_ON_BLACK_BRIGHT);
				mvaddstrAlt(5, 1, "CAMERAS ON");
			}
		}
		if (location[loc]->compound_walls & COMPOUND_TRAPS)
		{
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(5, 16, "BOOBY TRAPS");
		}
		if (location[loc]->compound_walls & COMPOUND_AAGUN)
		{
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			mvaddstrAlt(5, 33, "AA GUN");
		}
		if (location[loc]->compound_walls & COMPOUND_TANKTRAPS)
		{
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			mvaddstrAlt(5, 46, "TANK TRAPS");
		}
		if (location[loc]->siege.siege&&location[loc]->siege.lights_off)
		{
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(5, 60, "LIGHTS OUT");
		}
		else if (location[loc]->compound_walls & COMPOUND_GENERATOR)
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(5, 61, "GENERATOR");
		}
		int eaters = numbereating(loc), days = fooddaysleft(loc);
		if (eaters>0)
		{
			if (days >= 1)
			{
				set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(6, 50, days);
				addstrAlt(" Day");
				if (days != 1)addcharAlt('s');
				addstrAlt(" of Food Left");
			}
			else if (days == 0)
			{
				set_color_easy(RED_ON_BLACK);
				mvaddstrAlt(6, 50, "Not Enough Food");
			}
		}
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(6, 1, location[loc]->compound_stores);
		addstrAlt(" Daily Ration");
		if (location[loc]->compound_stores != 1)addstrAlt("s");
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(6, 30, eaters);
		addstrAlt(" Eating");
	}
}
extern int selectedsiege;
extern int day;
extern int month;
extern int year;
/* location and squad header */
void locheader()
{
	if (activesquad != NULL && activesquad->squad[0]->location != -1)
	{
		if (location[activesquad->squad[0]->location]->siege.siege)
		{
			if (location[activesquad->squad[0]->location]->siege.underattack)set_color_easy(RED_ON_BLACK_BRIGHT);
			else set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		}
		else set_color_easy(WHITE_ON_BLACK);
	}
	else if (selectedsiege != -1)
	{
		if (location[selectedsiege]->siege.siege)
		{
			if (location[selectedsiege]->siege.underattack)set_color_easy(RED_ON_BLACK_BRIGHT);
			else set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		}
		else set_color_easy(WHITE_ON_BLACK);
	}
	else set_color_easy(WHITE_ON_BLACK);
	moveAlt(0, 0);
	if (activesquad != NULL && activesquad->squad[0]->location != -1)
	{
		addstrAlt(location[activesquad->squad[0]->location]->getname(false, true));
		addstrAlt(commaSpace);
	}
	else
	{
		if (selectedsiege == -1)
		{
			addstrAlt("No Squad Selected");
			addstrAlt(commaSpace);
		}
		else
		{
			addstrAlt(location[selectedsiege]->getname(false, true));
			addstrAlt(commaSpace);
		}
	}
	addstrAlt(getmonth(month, true));
	addstrAlt(singleSpace);
	addstrAlt(day);
	addstrAlt(commaSpace);
	addstrAlt(year);
	if (activesquad == NULL && selectedsiege == -1)
	{
		set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(3, 6, "To form a new squad:");
		mvaddstrAlt(4, 6, "1) R - Review Assets and Form Squads");
		mvaddstrAlt(5, 6, "2) Press Z to Assemble a New Squad");
		set_color_easy(WHITE_ON_BLACK);
	}
	printfunds();
	if (activesquad != NULL)
	{
		string str = getactivity(activesquad->activity);
		set_activity_color(activesquad->activity.type);
		if (activesquad->activity.type == ACTIVITY_NONE)
		{
			bool haveact = false, multipleact = false;
			for (int p = 0; p<6; p++)
			{
				if (activesquad->squad[p] == NULL) continue;
				const string str2 = getactivity(activesquad->squad[p]->activity);
				set_activity_color(activesquad->squad[p]->activity.type);
				if (haveact&&str != str2) multipleact = true;
				str = str2, haveact = true;
			}
			if (multipleact)
			{
				str = "Acting Individually";
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
			}
		}
		mvaddstrAlt(0, 41, str);
	}
}
#include "common/commonactions.h"
#include "common/musicClass.h"
extern MusicClass music;
extern Ledger ledger;
string closeParenthesis;
string spaceParanthesisDollar;
string needCar;
string travelDifCity;
string secrecyLevel;
string percentSign;
string heatLevel;
string underSiege;
string currentLocation;
string highSecurity;
string closedDown;
string enemySafeHouse;
string safeHouse;
/* base - go forth to stop evil */
void stopevil()
{
	int l = 0, p = 0;
	if (!activesquad) return;
	bool havecar = false;
	for (p = 0; p < 6; p++) if (activesquad->squad[p]) if (activesquad->squad[p]->pref_carid != -1)
	{
		havecar = true;
		break;
	}
	Location* squad_location = location[activesquad->squad[0]->location];
	int page = 0, loc = -1;
	// Start at the city level, rather than the absolute top
	if (multipleCityMode) {
		for (l = 0; l < len(location); l++) {
			if (location[l]->type == squad_location->city) {
				loc = l;
				break;
			}
		}
	}
	vector<long> temploc;
	// 1. LCS safe houses
	for (l = 0; l < len(location); l++)
		if (location[l]->parent == loc && location[l]->renting >= 0 && !location[l]->hidden)
			temploc.push_back(l);
	// 2. CCS safe houses
	for (l = 0; l < len(location); l++)
		if (location[l]->parent == loc && location[l]->renting == RENTING_CCS && !location[l]->hidden)
			temploc.push_back(l);
	// 3. Other sites
	for (l = 0; l < len(location); l++)
		if (location[l]->parent == loc && location[l]->renting == RENTING_NOCONTROL && !location[l]->hidden)
			temploc.push_back(l);
	// Determine cost of tickets for travel
	int ticketprice = 100 * squadsize(activesquad);
	while (true)
	{
		music.play(MUSIC_STOPEVIL);
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(0, 0, "Where will the Squad go?");
		printparty();
		if (loc != -1)
		{
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(8, 0, location[loc]->getname(-1, true));
		}
		temploc.clear();
		for (l = 0; l < len(location); l++)
			if (location[l]->parent == loc&&location[l]->renting >= 0 && !location[l]->hidden)temploc.push_back(l);
		for (l = 0; l < len(location); l++)
			if (location[l]->parent == loc&&location[l]->renting == RENTING_CCS&&!location[l]->hidden)temploc.push_back(l);
		for (l = 0; l < len(location); l++)
			if (location[l]->parent == loc&&location[l]->renting == RENTING_NOCONTROL&&!location[l]->hidden)temploc.push_back(l);
		int y = 10;
		for (p = page * 11; p < len(temploc) && p < page * 11 + 11; p++)
		{
			if (p == -1) break;
			Location* this_location = location[temploc[p]];
			set_color_easy(WHITE_ON_BLACK);
			mvaddcharAlt(y, 0, y - 10 + 'A');
			addstrAlt(spaceDashSpace);
			addstrAlt(location[temploc[p]]->getname());
			bool show_safehouse_info = false;
			if (this_location == squad_location) {
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				addstrAlt(currentLocation);
				show_safehouse_info = true;
			}
			else if (this_location->renting >= 0) {
				set_color_easy(GREEN_ON_BLACK_BRIGHT);
				addstrAlt(safeHouse);
				show_safehouse_info = true;
			}
			else if (this_location->renting == RENTING_CCS) {
				set_color_easy(RED_ON_BLACK_BRIGHT);
				addstrAlt(enemySafeHouse);
			}
			else if (this_location->closed) {
				set_color_easy(RED_ON_BLACK_BRIGHT);
				addstrAlt(closedDown);
			}
			else if (this_location->highsecurity) {
				set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
				addstrAlt(highSecurity);
			}
			else if (multipleCityMode && this_location->type == squad_location->city) {
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				addstrAlt(currentLocation);
			}
			else if (this_location->area != squad_location->area && !havecar) {
				set_color_easy(YELLOW_ON_BLACK_BRIGHT);
				addstrAlt(needCar);
			}
			else if (this_location->type == SITE_TRAVEL) {
				if (ledger.get_funds() < ticketprice)
					set_color_easy(RED_ON_BLACK_BRIGHT);
				else
					set_color_easy(GREEN_ON_BLACK_BRIGHT);
				addstrAlt(spaceParanthesisDollar + tostring(ticketprice) + closeParenthesis);
			}
			if (this_location->siege.siege > 0) {
				set_color_easy(RED_ON_BLACK);
				addstrAlt(underSiege);
			}
			if (show_safehouse_info)
			{
				this_location->update_heat_protection();
				set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(y, 54, heatLevel);
				if (this_location->heat > this_location->heat_protection)
					set_color_easy(YELLOW_ON_BLACK_BRIGHT);
				else set_color_easy(BLACK_ON_BLACK_BRIGHT);
				addstrAlt(this_location->heat);
				addstrAlt(percentSign);
				set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(y, 66, secrecyLevel);
				if (this_location->heat > this_location->heat_protection)
					set_color_easy(YELLOW_ON_BLACK_BRIGHT);
				else set_color_easy(BLACK_ON_BLACK_BRIGHT);
				addstrAlt(this_location->heat_protection);
				addstrAlt(percentSign);
			}
			if (multipleCityMode && this_location->city == this_location->type)
			{
				set_color_easy(BLACK_ON_BLACK_BRIGHT);
				mvaddstrAlt(y, 50, this_location->city_description());
			}
			y++;
		}
		if (multipleCityMode && loc != -1 && LocationsPool::getInstance().getLocationType(loc) == location[loc]->city)
		{
			set_color_easy(WHITE_ON_BLACK);
			mvaddcharAlt(y + 1, 0, y - 10 + 'A');
			addstrAlt(travelDifCity);
			if (!havecar) {
				set_color_easy(YELLOW_ON_BLACK_BRIGHT);
				addstrAlt(needCar);
			}
			else {
				if (ledger.get_funds() < ticketprice)
					set_color_easy(RED_ON_BLACK_BRIGHT);
				else set_color_easy(GREEN_ON_BLACK_BRIGHT);
				addstrAlt(spaceParanthesisDollar + tostring(ticketprice) + closeParenthesis);
			}
			temploc.push_back(-1);
		}
		set_color_easy(WHITE_ON_BLACK);
		//PAGE UP
		if (page > 0)
		{
			mvaddstrAlt(10, 60, addprevpagestr());
		}
		//PAGE DOWN
		if ((page + 1) * 11 < len(temploc))
		{
			mvaddstrAlt(20, 60, addnextpagestr());
		}
		set_color_easy(WHITE_ON_BLACK);
		if ((loc == -1) || (multipleCityMode && LocationsPool::getInstance().getLocationType(loc) == squad_location->city)) mvaddstrAlt(24, 1, "Enter - The squad is not yet Liberal enough.");
		else mvaddstrAlt(24, 1, "Enter - Back one step.");
		int c = getkeyAlt();
		//PAGE UP
		if ((c == interface_pgup || c == KEY_UP || c == KEY_LEFT) && page>0) page--;
		//PAGE DOWN
		if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page + 1) * 11<len(temploc)) page++;
		if (c >= 'a'&&c <= 'k')
		{
			int sq = page * 11 + c - 'a';
			if (sq < len(temploc) && sq >= 0)
			{
				int oldloc = loc;
				loc = temploc[sq];
				if ((loc == -1 || (multipleCityMode && location[loc]->city != squad_location->city)) && !havecar)
					loc = oldloc;
				int subcount = 0;
				for (l = 0; l < len(location); l++)
					if (location[l]->parent == loc)
						subcount++;
				if (subcount == 0 || (multipleCityMode && loc >= 0 && location[loc]->city != squad_location->city))
				{
					if (!location[loc]->closed &&
						((location[loc]->area == squad_location->area&&location[loc]->city == squad_location->city) || havecar))
					{
						activesquad->activity.type = ACTIVITY_VISIT;
						activesquad->activity.arg = loc;
						return;
					}
					else loc = oldloc;
				}
			}
		}
		/*if(c=='z')
		{
		activesquad->stance++;
		if(activesquad->stance>SQUADSTANCE_STANDARD)
		activesquad->stance=0;
		}*/
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR)
		{
			if (loc != -1 && (location[loc]->city != LocationsPool::getInstance().getLocationType(loc) || location[loc]->city != squad_location->city))
				loc = location[loc]->parent;
			else
			{
				activesquad->activity.type = ACTIVITY_NONE; // Clear squad activity
				break;
			}
		}
	}
}


vector<string> caseBUSINESSFRONT_INSURANCE;
vector<string> caseBUSINESSFRONT_TEMPAGENCY;
vector<string> caseBUSINESSFRONT_RESTAURANT;
vector<string> caseBUSINESSFRONT_MISCELLANEOUS;
const string mostlyendings = "mostlyendings\\";
#include <customMaps.h>
vector<file_and_text_collection> locationspool_text_file_collection = {
	customText(&caseBUSINESSFRONT_INSURANCE, mostlyendings + "caseBUSINESSFRONT_INSURANCE.txt"),
	customText(&caseBUSINESSFRONT_TEMPAGENCY, mostlyendings + "caseBUSINESSFRONT_TEMPAGENCY.txt"),
	customText(&caseBUSINESSFRONT_RESTAURANT, mostlyendings + "caseBUSINESSFRONT_RESTAURANT.txt"),
	customText(&caseBUSINESSFRONT_MISCELLANEOUS, mostlyendings + "caseBUSINESSFRONT_MISCELLANEOUS.txt"),
};
/* base - invest in this location */
void investlocation()
{
	int loc = selectedsiege;
	while (true)
	{
		eraseAlt();
		locheader();
		printlocation(loc);
		if (LocationsPool::getInstance().canBeFortified(loc))
		{
			if (ledger.get_funds() >= 2000) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			if (LocationsPool::getInstance().getLocationType(loc) == SITE_OUTDOOR_BUNKER)
				mvaddstrAlt(8, 1, "W - Repair the Bunker Fortifications ($2000)");
			else if (LocationsPool::getInstance().getLocationType(loc) == SITE_RESIDENTIAL_BOMBSHELTER)
				mvaddstrAlt(8, 1, "W - Fortify the Bomb Shelter Entrances ($2000)");
			else
				mvaddstrAlt(8, 1, "W - Fortify the Compound for a Siege ($2000)");
		}
		if (!(LocationsPool::getInstance().getCompoundWalls(loc) & COMPOUND_CAMERAS))
		{
			if (ledger.get_funds() >= 2000) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(9, 1, "C - Place Security Cameras around the Compound ($2000)");
		}
		if (location[loc]->can_be_trapped())
		{
			if (ledger.get_funds() >= 3000) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(10, 1, "B - Place Booby Traps throughout the Compound ($3000)");
		}
		if (location[loc]->can_install_tanktraps())
		{
			if (ledger.get_funds() >= 3000) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(11, 1, "T - Ring the Compound with Tank Traps ($3000)");
		}
		if (!(location[loc]->compound_walls & COMPOUND_GENERATOR))
		{
			if (ledger.get_funds() >= 3000) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(12, 1, "G - Buy a Generator for emergency electricity ($3000)");
		}
		if (!(location[loc]->compound_walls & COMPOUND_AAGUN))
		{
			if (lawList[LAW_GUNCONTROL] == ALIGN_ARCHCONSERVATIVE)
			{
				if (ledger.get_funds() >= 35000) set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(13, 1, "A - Install a perfectly legal Anti-Aircraft gun on the roof ($35,000)");
			}
			else
			{
				if (ledger.get_funds() >= 200000) set_color_easy(WHITE_ON_BLACK);
				else set_color_easy(BLACK_ON_BLACK_BRIGHT);
				mvaddstrAlt(13, 1, "A - Install and conceal an illegal Anti-Aircraft gun on the roof ($200,000)");
			}
		}
		if (!(location[loc]->compound_walls & COMPOUND_PRINTINGPRESS))
		{
			if (ledger.get_funds() >= 3000) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(14, 1, "P - Buy a Printing Press to start your own newspaper ($3000)");
		}
		if (location[loc]->can_have_businessfront())
		{
			if (ledger.get_funds() >= 3000) set_color_easy(WHITE_ON_BLACK);
			else set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(15, 1, "F - Setup a Business Front to ward off suspicion ($3000)");
		}
		if (ledger.get_funds() >= 150) set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, "R - Stockpile 20 daily rations of food ($150)");
		mvaddstrAlt(17, 1, enter_done);
		int c = getkeyAlt();
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) break;
		if (c == 'w')
		{
			if (location[loc]->can_be_fortified() && ledger.get_funds() >= 2000)
			{
				ledger.subtract_funds(2000, EXPENSE_COMPOUND);
				location[loc]->compound_walls |= COMPOUND_BASIC;
			}
		}
		if (c == 'c')
		{
			if (!(LocationsPool::getInstance().getCompoundWalls(loc) & COMPOUND_CAMERAS) && ledger.get_funds() >= 2000)
			{
				ledger.subtract_funds(2000, EXPENSE_COMPOUND);
				location[loc]->compound_walls |= COMPOUND_CAMERAS;
			}
		}
		if (c == 'b')
		{
			if (location[loc]->can_be_trapped() && ledger.get_funds() >= 3000)
			{
				ledger.subtract_funds(3000, EXPENSE_COMPOUND);
				location[loc]->compound_walls |= COMPOUND_TRAPS;
			}
		}
		if (c == 't')
		{
			if (location[loc]->can_install_tanktraps() && ledger.get_funds() >= 3000)
			{
				ledger.subtract_funds(3000, EXPENSE_COMPOUND);
				location[loc]->compound_walls |= COMPOUND_TANKTRAPS;
			}
		}
		if (c == 'g')
		{
			if (!(LocationsPool::getInstance().getCompoundWalls(loc) & COMPOUND_GENERATOR) && ledger.get_funds() >= 3000)
			{
				ledger.subtract_funds(3000, EXPENSE_COMPOUND);
				location[loc]->compound_walls |= COMPOUND_GENERATOR;
			}
		}
		if (c == 'a')
		{
			int aagunPrice = 200000;
			if (lawList[LAW_GUNCONTROL] == ALIGN_ARCHCONSERVATIVE)
				aagunPrice = 35000;
			if (!(location[loc]->compound_walls & COMPOUND_AAGUN) && ledger.get_funds() >= aagunPrice)
			{
				ledger.subtract_funds(aagunPrice, EXPENSE_COMPOUND);
				location[loc]->compound_walls |= COMPOUND_AAGUN;
			}
		}
		if (c == 'p')
		{
			if (!(LocationsPool::getInstance().getCompoundWalls(loc) & COMPOUND_PRINTINGPRESS) && ledger.get_funds() >= 3000)
			{
				ledger.subtract_funds(3000, EXPENSE_COMPOUND);
				location[loc]->compound_walls |= COMPOUND_PRINTINGPRESS;
			}
		}
		if (c == 'r')
		{
			if (ledger.get_funds() >= 150)
			{
				ledger.subtract_funds(150, EXPENSE_COMPOUND);
				location[loc]->compound_stores += 20;
			}
		}
		if (c == 'f')
		{
			if (location[loc]->can_have_businessfront() && ledger.get_funds() >= 3000)
			{
				ledger.subtract_funds(3000, EXPENSE_COMPOUND);
				do
				{
					location[loc]->front_business = LCSrandom(BUSINESSFRONTNUM);
					strcpy(location[loc]->front_name, lastname(true));
					strcat(location[loc]->front_name, singleSpace);
					int selection;
					switch (location[loc]->front_business)
					{
					case BUSINESSFRONT_INSURANCE:
						selection = LCSrandom(len(caseBUSINESSFRONT_INSURANCE) / 2);
						strcat(location[loc]->front_name, caseBUSINESSFRONT_INSURANCE[selection * 2]);
						strcpy(location[loc]->front_shortname, caseBUSINESSFRONT_INSURANCE[selection * 2 + 1]);
						break;
					case BUSINESSFRONT_TEMPAGENCY:
						selection = LCSrandom(len(caseBUSINESSFRONT_TEMPAGENCY) / 2);
						strcat(location[loc]->front_name, caseBUSINESSFRONT_TEMPAGENCY[selection * 2]);
						strcpy(location[loc]->front_shortname, caseBUSINESSFRONT_TEMPAGENCY[selection * 2 + 1]);
						break;
					case BUSINESSFRONT_RESTAURANT:
						selection = LCSrandom(len(caseBUSINESSFRONT_RESTAURANT) / 2);
						strcat(location[loc]->front_name, caseBUSINESSFRONT_RESTAURANT[selection * 2]);
						strcpy(location[loc]->front_shortname, caseBUSINESSFRONT_RESTAURANT[selection * 2 + 1]);
						break;
					case BUSINESSFRONT_MISCELLANEOUS:
						selection = LCSrandom(len(caseBUSINESSFRONT_MISCELLANEOUS) / 2);
						strcat(location[loc]->front_name, caseBUSINESSFRONT_MISCELLANEOUS[selection * 2]);
						strcpy(location[loc]->front_shortname, caseBUSINESSFRONT_MISCELLANEOUS[selection * 2 + 1]);
						break;
					}
				} while (location[loc]->duplicatelocation());
			}
		}
	}
}

extern int stat_kidnappings;
/* names the new hostage and stashes them in your base */
void kidnaptransfer(Creature &cr)
{
	Creature *newcr = new Creature;
	*newcr = cr;
	newcr->namecreature();
	newcr->location = activesquad->squad[0]->base;
	newcr->base = activesquad->squad[0]->base;
	newcr->flag |= CREATUREFLAG_MISSING;
	//disarm them and stash their weapon back at the base
	newcr->drop_weapons_and_clips(&(location[newcr->location]->loot));
	//Create interrogation data
	newcr->activity.intr() = new interrogation;
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(0, 0, "The Education of ");
	addstrAlt(newcr->propername);
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(2, 0, "What name will you use for this ");
	addstrAlt(newcr->get_type_name());
	addstrAlt(" in its presence?");
	mvaddstrAlt(3, 0, "If you do not enter anything, their real name will be used.");
	enter_name(4, 0, newcr->name, CREATURE_NAMELEN, newcr->propername);
	addCreature(newcr);
	stat_kidnappings++;
}
/* transfer all loot from some source (such as a squad or another location) to a location, and deal with money properly */
void Location::getloot(vector<Item *>& loot)
{
	for (int l = len(loot) - 1; l >= 0; l--)
		if (loot[l]->is_money())
		{
			Money* m = static_cast<Money*>(loot[l]); //cast -XML
			ledger.add_funds(m->get_amount(), INCOME_THIEVERY);
			delete loot[l];
		}
		else
		{  // Empty squad inventory into base inventory
			this->loot.push_back(loot[l]);
		}
	loot.clear();
}
