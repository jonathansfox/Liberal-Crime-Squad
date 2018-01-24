/*
Copyright (c) 2002,2003,2004 by Tarn Adams                                          //
                                                                                    //
This file is part of Liberal Crime Squad.                                           //
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

#include "common/ledger.h"

#include "vehicle/vehicle.h"

#include "title/saveload.h"

#include "common/stringconversion.h"

#include "items/loottype.h"
// for loot class definition

#include "items/loot.h"

#include "items/money.h"

#include "common/getnames.h"
// for getview()

#include "common/equipment.h"
//for void consolidateloot(vector<Item *> &loot);

#include "common/translateid.h"
// for  getloottype

#include "log/log.h"
// for commondisplay.h
#include "common/commondisplay.h"
// for addstr

#include "title/saveload.h"
//own header
        //does not compile without --Schmel924



#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>

string itemType;
string doesNotExistItem;
string vehicleType;
string doesNotExistVehicle;
string couldNotLoad;

string itemClassClip;
string itemClassWeapon;
string itemClassArmor;
string itemClassLoot;
string itemClassMoney;

extern vector<Creature *> pool;
extern Log gamelog;
extern char newscherrybusted;
extern vector<Location *> location;
extern bool multipleCityMode;
extern int stat_buys;
extern int stat_burns;
extern short presparty;
extern MusicClass music;
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern int stat_kidnappings;
extern int year;
extern short mode;
extern short exec[EXECNUM];
extern char endgamestate;
extern bool encounterwarnings;
extern int stat_dead;
extern int stat_kills;
extern int stat_recruits;
extern char oldPresidentName[POLITICIAN_NAMELEN];


extern vector<Vehicle *> vehicle;
extern unsigned long seed[RNG_SIZE];
extern short wincondition;
extern short fieldskillrate;
extern int day;
extern int month;
extern int year;
extern short execterm;
extern short presparty;
extern int amendnum;
extern bool termlimits;
extern bool deagle;
extern bool m249;
extern bool notermlimit;
extern bool nocourtpurge;
extern bool stalinmode;
extern char ccs_kills;
extern long curcreatureid;
extern long cursquadid;
extern short offended_corps;
extern short offended_cia;
extern short offended_amradio;
extern short offended_cablenews;
extern short offended_firemen;
extern int police_heat;
extern unsigned long attorneyseed[RNG_SIZE];
extern char lcityname[CITY_NAMELEN];
extern char slogan[SLOGAN_LEN];
extern class Ledger ledger;
extern short party_status;
extern short attitude[VIEWNUM];
extern short public_interest[VIEWNUM];
extern short background_liberal_influence[VIEWNUM];
extern short lawList[LAWNUM];
extern short house[HOUSENUM];
extern short senate[SENATENUM];
extern short court[COURTNUM];
extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
extern char execname[EXECNUM][POLITICIAN_NAMELEN];

extern UniqueCreatures uniqueCreatures;
extern vector<squadst *> squad;
extern vector<datest *> date;
extern vector<recruitst *> recruit;
extern vector<newsstoryst *> newsstory;
extern squadst *activesquad;

// TODO: It would be really cool to be able to "export" characters.
/* handles saving */
bool file_exists(const std::string& filename)
{
	struct stat buf;
	if (stat(filename.c_str(), &buf) != -1)
	{
		return false;
	}
	return true;
}
struct  saveLoadChunk {
	void * Buffer;
	size_t      ElementSize;
	size_t      ElementCount;
	saveLoadChunk(void * _Buffer, int _ElementSize, int _ElementCount) :Buffer(_Buffer), ElementSize(_ElementSize), ElementCount(_ElementCount) {}
};
vector<saveLoadChunk> firstChunk =
{
	saveLoadChunk(seed, sizeof(unsigned long), RNG_SIZE),
	saveLoadChunk(&mode, sizeof(short), 1),
	saveLoadChunk(&wincondition, sizeof(short), 1),
	saveLoadChunk(&fieldskillrate, sizeof(short), 1),
	saveLoadChunk(&day, sizeof(int), 1),
	saveLoadChunk(&month, sizeof(int), 1),
	saveLoadChunk(&year, sizeof(int), 1),
	saveLoadChunk(&execterm, sizeof(short), 1),
	saveLoadChunk(&presparty, sizeof(short), 1),
	saveLoadChunk(&amendnum, sizeof(int), 1),
	saveLoadChunk(&multipleCityMode, sizeof(bool), 1),
	saveLoadChunk(&termlimits, sizeof(bool), 1),
	saveLoadChunk(&deagle, sizeof(bool), 1),
	saveLoadChunk(&m249, sizeof(bool), 1),
	saveLoadChunk(&notermlimit, sizeof(bool), 1),
	saveLoadChunk(&nocourtpurge, sizeof(bool), 1),
	saveLoadChunk(&stalinmode, sizeof(bool), 1),
	saveLoadChunk(&stat_recruits, sizeof(int), 1),
	saveLoadChunk(&stat_dead, sizeof(int), 1),
	saveLoadChunk(&stat_kills, sizeof(int), 1),
	saveLoadChunk(&stat_kidnappings, sizeof(int), 1),
	saveLoadChunk(&stat_buys, sizeof(int), 1),
	saveLoadChunk(&stat_burns, sizeof(int), 1),
	saveLoadChunk(&endgamestate, sizeof(char), 1),
	saveLoadChunk(&ccsexposure, sizeof(char), 1),
	saveLoadChunk(&ccs_kills, sizeof(char), 1),
	saveLoadChunk(&Vehicle::curcarid, sizeof(long), 1),
	saveLoadChunk(&curcreatureid, sizeof(long), 1),
	saveLoadChunk(&cursquadid, sizeof(long), 1),
	saveLoadChunk(&police_heat, sizeof(int), 1),
	saveLoadChunk(&offended_corps, sizeof(short), 1),
	saveLoadChunk(&offended_cia, sizeof(short), 1),
	saveLoadChunk(&offended_amradio, sizeof(short), 1),
	saveLoadChunk(&offended_cablenews, sizeof(short), 1),
	saveLoadChunk(&offended_firemen, sizeof(short), 1),
	saveLoadChunk(attorneyseed, sizeof(unsigned long), RNG_SIZE),
	saveLoadChunk(lcityname, sizeof(char), CITY_NAMELEN),
	saveLoadChunk(&newscherrybusted, sizeof(char), 1),
	saveLoadChunk(slogan, sizeof(char), SLOGAN_LEN),
	saveLoadChunk(&ledger, sizeof(class Ledger), 1),
	saveLoadChunk(&party_status, sizeof(short), 1),
	saveLoadChunk(attitude, sizeof(short), VIEWNUM),
	saveLoadChunk(lawList, sizeof(short), LAWNUM),
	saveLoadChunk(house, sizeof(short), HOUSENUM),
	saveLoadChunk(senate, sizeof(short), SENATENUM),
	saveLoadChunk(court, sizeof(short), COURTNUM),
	saveLoadChunk(courtname, sizeof(char)*POLITICIAN_NAMELEN, COURTNUM),
	saveLoadChunk(exec, sizeof(char), EXECNUM),
	saveLoadChunk(execname, sizeof(char)*POLITICIAN_NAMELEN, EXECNUM),
	saveLoadChunk(oldPresidentName, sizeof(char), POLITICIAN_NAMELEN)
};

void readVerbose(string str);
void writeVerbose(string str);
void deleteVerbose(string str);
void savegame(const string& filename)
{
	if (NOSAVE) {
		return;
	}
	bool dummy_b;
	int dummy;
	FILE *h;
	int l;
	h = LCSOpenFile(filename.c_str(), "wb", LCSIO_PRE_HOME);
	if (h != NULL)
	{
		int lversion = version;
		fwrite(&lversion, sizeof(int), 1, h);

		for (saveLoadChunk s : firstChunk) {
			fwrite(s.Buffer, s.ElementSize, s.ElementCount, h);
		}
		//LOCATIONS
		dummy = len(location);
		fwrite(&dummy, sizeof(int), 1, h);
		for (l = 0; l < len(location); l++)
		{
			consolidateloot(location[l]->loot); // consolidate loot before saving
			dummy = len(location[l]->loot);
			fwrite(&dummy, sizeof(int), 1, h);
			for (int l2 = 0; l2 < len(location[l]->loot); l2++)
			{
				std::string itemStr = location[l]->loot[l2]->showXml();
				int itemSize = len(itemStr);
				fwrite(&itemSize, sizeof(int), 1, h);
				fwrite(itemStr.c_str(), itemSize, 1, h);
			}
			dummy = len(location[l]->changes);
			fwrite(&dummy, sizeof(int), 1, h);
			for (int l2 = 0; l2 < len(location[l]->changes); l2++)
				fwrite(&location[l]->changes[l2], sizeof(sitechangest), 1, h);
			fwrite(location[l]->name, sizeof(char), LOCATION_NAMELEN, h);
			fwrite(location[l]->shortname, sizeof(char), LOCATION_SHORTNAMELEN, h);
			fwrite(&location[l]->type, sizeof(char), 1, h);
			fwrite(&location[l]->city, sizeof(int), 1, h);
			fwrite(&location[l]->area, sizeof(int), 1, h);
			fwrite(&location[l]->parent, sizeof(int), 1, h);
			fwrite(&location[l]->id, sizeof(int), 1, h); // NOT USED, kept for backwards compatibility
			fwrite(&location[l]->renting, sizeof(int), 1, h);
			fwrite(&location[l]->newrental, sizeof(char), 1, h);
			fwrite(&location[l]->needcar, sizeof(char), 1, h);
			fwrite(&location[l]->closed, sizeof(int), 1, h);
			fwrite(&location[l]->hidden, sizeof(bool), 1, h);
			fwrite(&location[l]->mapped, sizeof(bool), 1, h);
			fwrite(&location[l]->upgradable, sizeof(bool), 1, h);
			fwrite(&location[l]->highsecurity, sizeof(int), 1, h);
			fwrite(&location[l]->siege, sizeof(siegest), 1, h);
			fwrite(&location[l]->heat, sizeof(int), 1, h);
			fwrite(&location[l]->heat_protection, sizeof(int), 1, h);
			fwrite(&location[l]->compound_walls, sizeof(int), 1, h);
			fwrite(&location[l]->compound_stores, sizeof(int), 1, h);
			fwrite(&location[l]->front_business, sizeof(char), 1, h);
			fwrite(location[l]->front_name, sizeof(char), LOCATION_NAMELEN, h);
			fwrite(location[l]->front_shortname, sizeof(char), LOCATION_SHORTNAMELEN, h);
			fwrite(&location[l]->haveflag, sizeof(bool), 1, h);
			fwrite(location[l]->mapseed, sizeof(unsigned long), RNG_SIZE, h);
		}
		
		//VEHICLES
		dummy = len(vehicle);
		fwrite(&dummy, sizeof(int), 1, h);
		for (l = 0; l < len(vehicle); l++)
		{
			std::string vehicleStr = vehicle[l]->showXml();
			int vehicleSize = len(vehicleStr);
			fwrite(&vehicleSize, sizeof(int), 1, h);
			fwrite(vehicleStr.c_str(), vehicleSize, 1, h);
		}
		//POOL
		dummy = len(pool);
		fwrite(&dummy, sizeof(int), 1, h);
		for (int pl = 0; pl < len(pool); pl++)
		{
			std::string creatureStr = pool[pl]->showXml();
			int creatureSize = len(creatureStr);
			fwrite(&creatureSize, sizeof(int), 1, h);
			fwrite(creatureStr.c_str(), creatureSize, 1, h);
			// extra interrogation data if applicable
			if (pool[pl]->align == -1 && pool[pl]->alive)
			{
				interrogation* &intr = pool[pl]->activity.intr();
				fwrite(intr->techniques, sizeof(bool[6]), 1, h);
				fwrite(&intr->druguse, sizeof(int), 1, h);
				//deep write rapport map
				int size = len(intr->rapport);
				fwrite(&size, sizeof(int), 1, h);
				for (map<long, float_zero>::iterator i = intr->rapport.begin(); i != intr->rapport.end(); i++)
				{
					fwrite(&i->first, sizeof(long), 1, h);
					fwrite(&i->second, sizeof(float_zero), 1, h);
				}
			}
		}
		//Unique Creatures
		{
			std::string uniquecreaturesStr = uniqueCreatures.showXml();
			int uniquecreaturesSize = len(uniquecreaturesStr);
			fwrite(&uniquecreaturesSize, sizeof(int), 1, h);
			fwrite(uniquecreaturesStr.c_str(), uniquecreaturesSize, 1, h);
		}
		//SQUADS
		dummy = len(squad);
		fwrite(&dummy, sizeof(int), 1, h);
		for (int sq = 0; sq < len(squad); sq++)
		{
			fwrite(squad[sq]->name, sizeof(char), SQUAD_NAMELEN, h);
			fwrite(&squad[sq]->activity, sizeof(activityst), 1, h);
			fwrite(&squad[sq]->id, sizeof(int), 1, h);
			for (int pos = 0; pos < 6; pos++)
			{
				dummy_b = squad[sq]->squad[pos];
				fwrite(&dummy_b, sizeof(bool), 1, h);
				if (dummy_b)
					fwrite(&squad[sq]->squad[pos]->id, sizeof(int), 1, h);
			}
			consolidateloot(squad[sq]->loot); // consolidate loot before saving
			dummy = len(squad[sq]->loot);
			fwrite(&dummy, sizeof(int), 1, h);
			for (int l2 = 0; l2 < len(squad[sq]->loot); l2++)
			{
				std::string itemStr = squad[sq]->loot[l2]->showXml();
				int itemSize = len(itemStr);
				fwrite(&itemSize, sizeof(int), 1, h);
				fwrite(itemStr.c_str(), itemSize, 1, h);
			}
		}
		dummy_b = activesquad;
		fwrite(&dummy_b, sizeof(bool), 1, h);
		if (dummy_b)
			fwrite(&activesquad->id, sizeof(int), 1, h);
		//DATES
		dummy = len(date);
		fwrite(&dummy, sizeof(int), 1, h);
		for (int dt = 0; dt < len(date); dt++)
		{
			fwrite(&date[dt]->mac_id, sizeof(long), 1, h);
			fwrite(&date[dt]->timeleft, sizeof(short), 1, h);
			fwrite(&date[dt]->city, sizeof(int), 1, h);
			dummy = len(date[dt]->date);
			fwrite(&dummy, sizeof(int), 1, h);
			for (int dt2 = 0; dt2 < len(date[dt]->date); dt2++)
			{
				std::string creatureStr = date[dt]->date[dt2]->showXml();
				int creatureSize = len(creatureStr);
				fwrite(&creatureSize, sizeof(int), 1, h);
				fwrite(creatureStr.c_str(), creatureSize, 1, h);
			}
		}
		//RECRUITS
		dummy = len(recruit);
		fwrite(&dummy, sizeof(int), 1, h);
		for (int rt = 0; rt < len(recruit); rt++)
		{
			fwrite(&recruit[rt]->recruiter_id, sizeof(long), 1, h);
			fwrite(&recruit[rt]->timeleft, sizeof(short), 1, h);
			fwrite(&recruit[rt]->level, sizeof(char), 1, h);
			fwrite(&recruit[rt]->eagerness1, sizeof(char), 1, h);
			fwrite(&recruit[rt]->task, sizeof(char), 1, h);
			std::string creatureStr = recruit[rt]->recruit->showXml();
			int creatureSize = len(creatureStr);
			fwrite(&creatureSize, sizeof(int), 1, h);
			fwrite(creatureStr.c_str(), creatureSize, 1, h);
		}
		//NEWS STORIES
		dummy = len(newsstory);
		fwrite(&dummy, sizeof(int), 1, h);
		for (int ns = 0; ns < len(newsstory); ns++)
		{
			fwrite(&newsstory[ns]->type, sizeof(short), 1, h);
			fwrite(&newsstory[ns]->view, sizeof(short), 1, h);
			fwrite(&newsstory[ns]->loc, sizeof(long), 1, h);
			fwrite(&newsstory[ns]->priority, sizeof(long), 1, h);
			fwrite(&newsstory[ns]->page, sizeof(long), 1, h);
			fwrite(&newsstory[ns]->positive, sizeof(char), 1, h);
			fwrite(&newsstory[ns]->siegetype, sizeof(short), 1, h);
			dummy_b = newsstory[ns]->cr;
			fwrite(&dummy_b, sizeof(bool), 1, h);
			if (dummy_b)
				fwrite(&newsstory[ns]->cr->id, sizeof(long), 1, h);
			dummy = len(newsstory[ns]->crime);
			fwrite(&dummy, sizeof(int), 1, h);
			for (int dt2 = 0; dt2 < len(newsstory[ns]->crime); dt2++)
				fwrite(&newsstory[ns]->crime[dt2], sizeof(int), 1, h);
		}
		// Liberal Media
		fwrite(public_interest, sizeof(public_interest), 1, h);
		fwrite(background_liberal_influence, sizeof(background_liberal_influence), 1, h);
		// Site mode options
		fwrite(&encounterwarnings, sizeof(bool), 1, h);
		bool musicenabled = music.isEnabled();
		fwrite(&musicenabled, sizeof(bool), 1, h);
		LCSCloseFile(h);
		if (VERBOSESAVEFILE) {
			writeVerbose(filename.c_str());
		}
		else {
			deleteVerbose(filename.c_str());
		}
	}
}

/* Used by load() to create items of the correct class. */
Item* create_item(const std::string& inputXml)
{
	Item* it = NULL;
	CMarkup xml;
	xml.SetDoc(inputXml);
	xml.FindElem();
	string itemclass = xml.GetTagName();
	if (itemclass == itemClassClip)
		it = new Clip(inputXml);
	else if (itemclass == itemClassWeapon)
		it = new Weapon(inputXml);
	else if (itemclass == itemClassArmor)
		it = new Armor(inputXml);
	else if (itemclass == itemClassLoot)
		it = new Loot(inputXml);
	else if (itemclass == itemClassMoney)
		it = new Money(inputXml);
	return it;
}
/* loads the game from save.dat */
char load(const string& filename)
{
	//LOAD FILE
	int loadversion;
	bool dummy_b;
	int dummy;
	long dummy_l;
	FILE *h;
	int l;
	h = LCSOpenFile(filename.c_str(), "rb", LCSIO_PRE_HOME);
	if (h != NULL)
	{
		fread(&loadversion, sizeof(int), 1, h);
		//NUKE INVALID SAVE GAMES
		if (loadversion < lowestloadversion)
		{
			LCSCloseFile(h);
			reset();
			return 0;
		}
		for (saveLoadChunk s : firstChunk) {
			fread(s.Buffer, s.ElementSize, s.ElementCount, h);
		}
		//LOCATIONS
		fread(&dummy, sizeof(int), 1, h);
		location.resize(dummy);
		for (l = 0; l < len(location); l++)
		{
			location[l] = new Location;
			fread(&dummy, sizeof(int), 1, h);
			location[l]->loot.resize(dummy);
			for (int l2 = 0; l2 < len(location[l]->loot); l2++)
			{
				int itemSize;
				fread(&itemSize, sizeof(int), 1, h);
				vector<char> vec = vector<char>(itemSize + 1);
				fread(&vec[0], itemSize, 1, h);
				vec[itemSize] = '\0';
				Item* it = create_item(&vec[0]);
				if (it != NULL)
					location[l]->loot[l2] = it;
			}
			//Remove items of unknown type.
			for (int l2 = len(location[l]->loot) - 1; l2 >= 0; l2--)
			{
				bool del = false;
				if (location[l]->loot[l2]->is_loot())
					del = (getloottype(location[l]->loot[l2]->get_itemtypename()) == -1);
				else if (location[l]->loot[l2]->is_clip())
					del = (getcliptype(location[l]->loot[l2]->get_itemtypename()) == -1);
				else if (location[l]->loot[l2]->is_weapon())
					del = (getweapontype(location[l]->loot[l2]->get_itemtypename()) == -1);
				else if (location[l]->loot[l2]->is_armor())
					del = (getarmortype(location[l]->loot[l2]->get_itemtypename()) == -1);
				if (del)
				{
					addstrAlt(itemType);
					addstrAlt(location[l]->loot[l2]->get_itemtypename());
					addstrAlt(doesNotExistItem);
					delete_and_remove(location[l]->loot, l2);
				}
			}


			consolidateloot(location[l]->loot); // consolidate loot after loading
			fread(&dummy, sizeof(int), 1, h);
			location[l]->changes.resize(dummy);
			for (int l2 = 0; l2 < len(location[l]->changes); l2++)
				fread(&location[l]->changes[l2], sizeof(sitechangest), 1, h);
			fread(location[l]->name, sizeof(char), LOCATION_NAMELEN, h);
			fread(location[l]->shortname, sizeof(char), LOCATION_SHORTNAMELEN, h);
			fread(&location[l]->type, sizeof(char), 1, h);
			fread(&location[l]->city, sizeof(int), 1, h);
			fread(&location[l]->area, sizeof(int), 1, h);
			fread(&location[l]->parent, sizeof(int), 1, h);
			fread(&location[l]->id, sizeof(int), 1, h); // NOT USED, kept for backwards compatibility
			fread(&location[l]->renting, sizeof(int), 1, h);
			fread(&location[l]->newrental, sizeof(char), 1, h);
			fread(&location[l]->needcar, sizeof(char), 1, h);
			fread(&location[l]->closed, sizeof(int), 1, h);
			fread(&location[l]->hidden, sizeof(bool), 1, h);
			fread(&location[l]->mapped, sizeof(bool), 1, h);
			fread(&location[l]->upgradable, sizeof(bool), 1, h);
			fread(&location[l]->highsecurity, sizeof(int), 1, h);
			fread(&location[l]->siege, sizeof(siegest), 1, h);
			fread(&location[l]->heat, sizeof(int), 1, h);
			fread(&location[l]->heat_protection, sizeof(int), 1, h);
			fread(&location[l]->compound_walls, sizeof(int), 1, h);
			fread(&location[l]->compound_stores, sizeof(int), 1, h);
			fread(&location[l]->front_business, sizeof(char), 1, h);
			fread(location[l]->front_name, sizeof(char), LOCATION_NAMELEN, h);
			fread(location[l]->front_shortname, sizeof(char), LOCATION_SHORTNAMELEN, h);
			fread(&location[l]->haveflag, sizeof(bool), 1, h);
			fread(location[l]->mapseed, sizeof(unsigned long), RNG_SIZE, h);
		}
		//VEHICLES
		fread(&dummy, sizeof(int), 1, h);
		vehicle.resize(dummy);
		for (l = 0; l < len(vehicle); l++)
		{
			int vehicleSize;
			fread(&vehicleSize, sizeof(int), 1, h);
			vector<char> vec = vector<char>(vehicleSize + 1);
			fread(&vec[0], vehicleSize, 1, h);
			vec[vehicleSize] = '\0';
			vehicle[l] = new Vehicle(&vec[0]);
		}
		//POOL
		fread(&dummy, sizeof(int), 1, h);
		pool.resize(dummy);
		for (int pl = 0; pl < len(pool); pl++)
		{
			int creatureSize;
			fread(&creatureSize, sizeof(int), 1, h);
			vector<char> vec = vector<char>(creatureSize + 1);
			fread(&vec[0], creatureSize, 1, h);
			vec[creatureSize] = '\0';
			pool[pl] = new Creature(&vec[0]);
			// extra interrogation data if applicable
			if (pool[pl]->align == -1 && pool[pl]->alive)
			{
				interrogation* &intr = pool[pl]->activity.intr();
				intr = new interrogation;
				fread(intr->techniques, sizeof(bool[6]), 1, h);
				fread(&intr->druguse, sizeof(int), 1, h);
				intr->rapport.clear();
				int size;
				fread(&size, sizeof(int), 1, h);
				for (int i = 0; i < size; i++)
				{
					long id;
					float_zero value;
					fread(&id, sizeof(long), 1, h);
					fread(&value, sizeof(float_zero), 1, h);
					intr->rapport[id] = value;
				}
			}
		}
		//Unique Creatures
		{
			int uniquecreaturesSize;
			fread(&uniquecreaturesSize, sizeof(int), 1, h);
			vector<char> vec = vector<char>(uniquecreaturesSize + 1);
			fread(&vec[0], uniquecreaturesSize, 1, h);
			vec[uniquecreaturesSize] = '\0';
			uniqueCreatures = UniqueCreatures(&vec[0]);
		}
		//SQUADS
		fread(&dummy, sizeof(int), 1, h);
		squad.resize(dummy);
		for (int sq = 0; sq < len(squad); sq++)
		{
			squad[sq] = new squadst;
			fread(squad[sq]->name, sizeof(char), SQUAD_NAMELEN, h);
			fread(&squad[sq]->activity, sizeof(activityst), 1, h);
			fread(&squad[sq]->id, sizeof(int), 1, h);
			for (int pos = 0; pos < 6; pos++)
			{
				//REBUILD SQUAD FROM POOL
				squad[sq]->squad[pos] = NULL;
				fread(&dummy_b, sizeof(bool), 1, h);
				if (dummy_b)
				{
					int dummy_i;
					fread(&dummy_i, sizeof(int), 1, h);
					for (int pl = 0; pl < len(pool); pl++)
						if (pool[pl]->id == dummy_i)
							squad[sq]->squad[pos] = pool[pl];
				}
			}
			fread(&dummy, sizeof(int), 1, h);
			squad[sq]->loot.resize(dummy);
			for (int l2 = 0; l2 < len(squad[sq]->loot); l2++)
			{
				int itemSize;
				fread(&itemSize, sizeof(int), 1, h);
				vector<char> vec = vector<char>(itemSize + 1);
				fread(&vec[0], itemSize, 1, h);
				vec[itemSize] = '\0';
				Item* it = create_item(&vec[0]);
				squad[sq]->loot[l2] = it;
			}
			//Remove items of unknown type.
			for (int l2 = len(squad[sq]->loot) - 1; l2 >= 0; l2--)
			{
				bool del = false;
				if (squad[sq]->loot[l2]->is_loot())
					del = (getloottype(squad[sq]->loot[l2]->get_itemtypename()) == -1);
				else if (squad[sq]->loot[l2]->is_clip())
					del = (getcliptype(squad[sq]->loot[l2]->get_itemtypename()) == -1);
				else if (squad[sq]->loot[l2]->is_weapon())
					del = (getweapontype(squad[sq]->loot[l2]->get_itemtypename()) == -1);
				else if (squad[sq]->loot[l2]->is_armor())
					del = (getarmortype(squad[sq]->loot[l2]->get_itemtypename()) == -1);
				if (del)
				{
					addstrAlt(itemType);
					addstrAlt(squad[sq]->loot[l2]->get_itemtypename());
					addstrAlt(doesNotExistItem);
					delete_and_remove(squad[sq]->loot, l2);
				}
			}

			consolidateloot(squad[sq]->loot); // consolidate loot after loading
		}
		activesquad = NULL;
		fread(&dummy_b, sizeof(bool), 1, h);
		if (dummy_b)
		{
			int dummy_i;
			fread(&dummy_i, sizeof(int), 1, h);
			for (int sq = 0; sq < len(squad); sq++)
				if (squad[sq]->id == dummy_i)
				{
					activesquad = squad[sq];
					break;
				}
		}
		//DATES
		fread(&dummy, sizeof(int), 1, h);
		date.resize(dummy);
		for (int dt = 0; dt < len(date); dt++)
		{
			date[dt] = new datest;
			fread(&date[dt]->mac_id, sizeof(long), 1, h);
			fread(&date[dt]->timeleft, sizeof(short), 1, h);
			fread(&date[dt]->city, sizeof(int), 1, h);
			fread(&dummy, sizeof(int), 1, h);
			date[dt]->date.resize(dummy);
			for (int dt2 = 0; dt2 < len(date[dt]->date); dt2++)
			{
				int creatureSize;
				fread(&creatureSize, sizeof(int), 1, h);
				vector<char> vec = vector<char>(creatureSize + 1);
				fread(&vec[0], creatureSize, 1, h);
				vec[creatureSize] = '\0';
				date[dt]->date[dt2] = new Creature(&vec[0]);
			}
		}
		//RECRUITS
		fread(&dummy, sizeof(int), 1, h);
		recruit.resize(dummy);
		for (int rt = 0; rt < len(recruit); rt++)
		{
			recruit[rt] = new recruitst;
			fread(&recruit[rt]->recruiter_id, sizeof(long), 1, h);
			fread(&recruit[rt]->timeleft, sizeof(short), 1, h);
			fread(&recruit[rt]->level, sizeof(char), 1, h);
			fread(&recruit[rt]->eagerness1, sizeof(char), 1, h);
			fread(&recruit[rt]->task, sizeof(char), 1, h);
			int creatureSize;
			fread(&creatureSize, sizeof(int), 1, h);
			vector<char> vec = vector<char>(creatureSize + 1);
			fread(&vec[0], creatureSize, 1, h);
			vec[creatureSize] = '\0';
			recruit[rt]->recruit = new Creature(&vec[0]);
		}
		//NEWS STORIES
		fread(&dummy, sizeof(int), 1, h);
		newsstory.resize(dummy);
		for (int ns = 0; ns < len(newsstory); ns++)
		{
			newsstory[ns] = new newsstoryst;
			fread(&newsstory[ns]->type, sizeof(short), 1, h);
			fread(&newsstory[ns]->view, sizeof(short), 1, h);
			fread(&newsstory[ns]->loc, sizeof(long), 1, h);
			fread(&newsstory[ns]->priority, sizeof(long), 1, h);
			fread(&newsstory[ns]->page, sizeof(long), 1, h);
			fread(&newsstory[ns]->positive, sizeof(char), 1, h);
			fread(&newsstory[ns]->siegetype, sizeof(short), 1, h);
			newsstory[ns]->cr = NULL;
			fread(&dummy_b, sizeof(bool), 1, h);
			if (dummy_b)
			{
				fread(&dummy_l, sizeof(long), 1, h);
				for (int pl = 0; pl < len(pool); pl++)
					if (pool[pl]->id == dummy_l)
					{
						newsstory[ns]->cr = pool[pl];
						break;
					}
			}
			fread(&dummy, sizeof(int), 1, h);
			newsstory[ns]->crime.resize(dummy);
			for (int dt2 = 0; dt2 < len(newsstory[ns]->crime); dt2++)
				fread(&newsstory[ns]->crime[dt2], sizeof(int), 1, h);
		}
		// Liberal Media
		fread(public_interest, sizeof(public_interest), 1, h);
		fread(background_liberal_influence, sizeof(background_liberal_influence), 1, h);
		// Site mode options
		fread(&encounterwarnings, sizeof(bool), 1, h);
		LCSCloseFile(h);
		// Check that vehicles are of existing types.
		for (int v = 0; v < len(vehicle); v++)
		{
			if (getvehicletype(vehicle[v]->vtypeidname()) == -1)
			{ //Remove vehicle of non-existing type.
				addstrAlt(vehicleType + vehicle[v]->vtypeidname() + doesNotExistVehicle);
				delete_and_remove(vehicle, v--);
			}
		}

			readVerbose(filename.c_str());
		
		return 1;
	}
	gamelog.log(couldNotLoad);
	return 0;
}
/* deletes save.dat (used on endgame and for invalid save version) */
void reset()
{
	for (string filename : LCSSaveFiles()) {
		if (file_exists(filename)) LCSDeleteFile(filename.c_str(), LCSIO_PRE_HOME);
	}
}
extern char homedir[MAX_PATH_SIZE];
void useData(vector<string> types);
void readVerbose(string filename) {

	string filepath = homedir;
	int position = filename.find(".");
	filename.erase(position);
	filename += ".verbose";
	FILE *h;
	h = LCSOpenFile((filename).c_str(), "rb", LCSIO_PRE_HOME);
	if (h != NULL) {
		LCSCloseFile(h);
		
		ifstream txtFile;
		char currentLine[2048];
		txtFile.open(filepath + filename);
		vector<string> types;
		while (!txtFile.eof()) {
			txtFile.getline(currentLine, 2048, '\n');
			bool notComment = (currentLine[0] && currentLine[0] != '#');
			if (notComment) {
				types.push_back(currentLine);
			}
		}
		txtFile.close();
		useData(types);
		
	}
}
void deleteVerbose(string filename) {

	int position = filename.find(".");
	filename.erase(position);
	filename += ".verbose";

	LCSDeleteFile(filename.c_str(), LCSIO_PRE_HOME);
}

typedef map<short, string > shortAndString;

string convertToString(void *, int, int);
void writeVerbose(string filename) {

	string filepath = homedir;
	int position = filename.find(".");
	filename.erase(position);
	filename += ".verbose";
	filepath.append(filename);
	//FILE *h;
	//h = LCSOpenFile((filename).c_str(), "wb", LCSIO_PRE_HOME);

	//LCSCloseFile(h);


	ofstream outClientFile(filename, ios::out);
	if (!outClientFile) {
		cerr << "Verbose File Could Not Be Opened" << endl;
	}
	else {
		if (NOVERBOSECOMMENTS) {
			outClientFile << "# Autocomments disabled" << endl;
			outClientFile << "# remove NOVERBOSECOMMENTS to activate autocomments" << endl;
		}
		else {
			outClientFile << "# All lines beginning with # are comments" << endl << "# and are thereby ignored" << endl;
			outClientFile << "# Since the purpose of verbose savefiles is to make them human readable and editable," << endl;
			outClientFile << "# There will be quite a few comments generated automatically" << endl;
			outClientFile << "# If these comments are more trouble than they're worth, add to the debug_defines.txt file" << endl;
			outClientFile << "# NOVERBOSECOMMENTS to remove them (almost) entirely" << endl;
			outClientFile << "# LCS Funding level (max value 2147483647) can be negative" << endl;
		}
		outClientFile << ledger.get_funds() << endl;

		/*
		outClientFile << "# seed" << endl;
		outClientFile <<  seed[0] << endl;
		outClientFile <<  seed[1] << endl;
		outClientFile <<  seed[2] << endl;
		outClientFile <<  seed[3] << endl;
		outClientFile << "# mode" << endl;
		outClientFile <<  mode << endl;
		outClientFile << "# wincondition" << endl;
		outClientFile <<  wincondition << endl;
		outClientFile << "# fieldskillrate" << endl;
		outClientFile <<  fieldskillrate << endl;
		*/
		outClientFile << "# day" << endl;
		outClientFile <<  day << endl;
		outClientFile << "# month" << endl;
		outClientFile <<  month << endl;
		outClientFile << "# year" << endl;
		outClientFile <<  year << endl;
		outClientFile << "# execterm" << endl;
		outClientFile <<  execterm << endl;
		outClientFile << "# presparty" << endl;
		outClientFile <<  presparty << endl;
		outClientFile << "# amendnum" << endl;
		outClientFile <<  amendnum << endl;
		outClientFile << "# multipleCityMode" << endl;
		outClientFile <<  multipleCityMode << endl;
		outClientFile << "# termlimits" << endl;
		outClientFile <<  termlimits << endl;
		outClientFile << "# deagle" << endl;
		outClientFile <<  deagle << endl;
		outClientFile << "# m249" << endl;
		outClientFile <<  m249 << endl;
		outClientFile << "# notermlimit" << endl;
		outClientFile <<  notermlimit << endl;
		outClientFile << "# nocourtpurge" << endl;
		outClientFile <<  nocourtpurge << endl;
		outClientFile << "# stalinmode" << endl;
		outClientFile <<  stalinmode << endl;
		outClientFile << "# stat_recruits" << endl;
		outClientFile <<  stat_recruits << endl;
		outClientFile << "# stat_dead" << endl;
		outClientFile <<  stat_dead << endl;
		outClientFile << "# stat_kills" << endl;
		outClientFile <<  stat_kills << endl;
		outClientFile << "# stat_kidnappings" << endl;
		outClientFile <<  stat_kidnappings << endl;
		outClientFile << "# stat_buys" << endl;
		outClientFile <<  stat_buys << endl;
		outClientFile << "# stat_burns" << endl;
		outClientFile <<  stat_burns << endl;
		/*
		outClientFile << "# endgamestate" << endl;
		outClientFile <<  endgamestate << endl;
		outClientFile << "# ccsexposure" << endl;
		outClientFile <<  ccsexposure << endl;
		outClientFile << "# ccs_kills" << endl;
		outClientFile <<  ccs_kills << endl;
		*/
		outClientFile << "# Police Heat" << endl;
		outClientFile <<  police_heat << endl;
		outClientFile << "# Offended Corps" << endl;
		outClientFile <<  offended_corps << endl;
		outClientFile << "# Offended CIA" << endl;
		outClientFile <<  offended_cia << endl;
		outClientFile << "# Offended Amradio" << endl;
		outClientFile <<  offended_amradio << endl;
		outClientFile << "# Offended Cablenews" << endl;
		outClientFile <<  offended_cablenews << endl;
		outClientFile << "# Offended Firemen" << endl;
		outClientFile <<  offended_firemen << endl;
		/*
		outClientFile << "# attorneyseed" << endl;
		outClientFile <<  attorneyseed[0] << endl;
		outClientFile <<  attorneyseed[1] << endl;
		outClientFile <<  attorneyseed[2] << endl;
		outClientFile <<  attorneyseed[3] << endl;
		*/
		outClientFile << "# L City Name" << endl;
		outClientFile << lcityname << endl;
		/*
		outClientFile << "# Liberal Guardian Published" << endl;
		outClientFile <<  newscherrybusted << endl;
		*/
		outClientFile << "# Slogan" << endl;
		outClientFile << slogan << endl;

		outClientFile << "# Party Status" << endl;
		outClientFile <<  party_status << endl;
		outClientFile << "# Attitude" << endl;
		for (int i = 0; i < len(attitude); i++) {
			outClientFile << "# Concerning " + getview(i, false) << endl;

			outClientFile <<  attitude[i] << endl;
		}
		extern shortAndString getLawString;
		outClientFile << "# Law List" << endl;
		for (int i = 0; i < len(lawList); i++) {
			if (!NOVERBOSECOMMENTS)
				outClientFile << "# " + getLawString[i] << endl;
			outClientFile <<  lawList[i] << endl;
		}

		outClientFile << "# House" << endl;
		for (int i = 0; i < len(house); i++){
			outClientFile <<  house[i] << endl;
		}

		outClientFile << "# Senate" << endl;
			for (int i = 0; i < len(senate); i++) {
				outClientFile <<  senate[i] << endl;
			}

		outClientFile << "# Supreme Court" << endl;
		for (int i = 0; i < len(court); i++) {
			outClientFile <<  court[i] << endl;
		}

		outClientFile << "# Supreme Court Names" << endl;
		for (int i = 0; i < len(courtname); i++) {
			outClientFile << courtname[i] << endl;
		}

		outClientFile << "# exec" << endl;
		for (int i = 0; i < len(exec); i++) {
			outClientFile <<  exec[i] << endl;
		}

		outClientFile << "# execname" << endl;
		for (int i = 0; i < len(execname); i++) {
			outClientFile << execname[i] << endl;
		}
		/*
		outClientFile << "# oldPresidentName" << endl;
		outClientFile << oldPresidentName << endl;
		*/
		for (int pl = 0; pl < len(pool); pl++)
		{
			outClientFile << "# Next Creature" << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << "# Name" << endl;
			outClientFile << pool[pl]->name << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << "# Proper Name" << endl;
			outClientFile << pool[pl]->propername << endl;
			/*
			if (!NOVERBOSECOMMENTS)
				outClientFile << "# Gender (Conservative)" << endl;
			outClientFile <<  pool[pl]->gender_conservative << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << "# Gender (Liberal)" << endl;
			outClientFile <<  pool[pl]->gender_liberal << endl;
			*/
			if (!NOVERBOSECOMMENTS)
				outClientFile << "# Age" << endl;
			outClientFile <<  pool[pl]->age << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << "# Birthday Month" << endl;
			outClientFile <<  pool[pl]->birthday_month << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << "# Birthday Day" << endl;
			outClientFile <<  pool[pl]->birthday_day << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << "# Alignment" << endl;
			outClientFile <<  pool[pl]->align << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << "# Juice" << endl;
			outClientFile <<  pool[pl]->juice << endl;
			for (int i = 0; i < ATTNUM; i++) {
				if (!NOVERBOSECOMMENTS)
					outClientFile << "# " + attribute_enum_to_string(i) << endl;
				outClientFile <<  pool[pl]->get_attribute(i, false) << endl;

			}
			extern shortAndString skillEnumToString;
			outClientFile << "# Skills" << endl;
			for (int i = 0; i < SKILLNUM; i++) {
				if (!NOVERBOSECOMMENTS)
					outClientFile << "# " + skillEnumToString[i] << endl;
				outClientFile <<  pool[pl]->get_skill(i) << endl;

			}
			/*
			for (int i = 0; i < AUGMENTATIONNUM; i++) {
			outClientFile <<  pool[pl]->get_augmentation(i) << endl;

			}

			for (int i = 0; i < BODYPARTNUM; i++) {//Bad, relies on their order in the xml file. -XML
			if (!NOVERBOSECOMMENTS)
			outClientFile << "# Next Creature" << endl;
			outClientFile <<  pool[pl]->wound[i] << endl;
			}
			for (int i = 0; i < SPECIALWOUNDNUM; i++) { //Bad, relies on their order in the xml file. -XML
			if (!NOVERBOSECOMMENTS)
			outClientFile << "# Next Creature" << endl;
			outClientFile <<  pool[pl]->special[i] << endl;
			}
			*/
			extern shortAndString getLawFlagString;
			typedef map<short, shortAndString > shortAndShortAndString;
			extern shortAndShortAndString getLawFlagStringFull;
			outClientFile << "# Crimes" << endl;
			for (int i = 0; i < LAWFLAGNUM; i++) {//Bad, relies on their order in the xml file. -XML
												  // 6
												  // 20
				if (!NOVERBOSECOMMENTS)
					outClientFile << "# " << ( (i == 6 || i == 20) ? getLawFlagStringFull[i][0] : getLawFlagString[i]) << endl;
				outClientFile <<  pool[pl]->crimes_suspected[i] << endl;
			}

		}

		/*
		outClientFile << "# Vehicle::curcarid" << endl;
		outClientFile << Vehicle::curcarid << endl;
		outClientFile << "# curcreatureid" << endl;
		outClientFile << curcreatureid << endl;
		outClientFile << "# cursquadid" << endl;
		outClientFile << cursquadid << endl;
		*/

	}
	outClientFile.close();
}


void useData(vector<string> types) {
	//TODO
	int maxJindex = len(types);
	maxJindex--;
	int jindex = 0;
	ledger.force_funds(atoi(types[jindex].data()));
	jindex++;

	if (jindex > maxJindex) {
		return;
	}
	/*
	seed[0] = atoi(types[jindex].data());
	jindex++;

	seed[1] = atoi(types[jindex].data());
	jindex++;

	seed[2] = atoi(types[jindex].data());
	jindex++;

	seed[3] = atoi(types[jindex].data());
	jindex++;


	mode = atoi(types[jindex].data());
	jindex++;


	wincondition = atoi(types[jindex].data());
	jindex++;


	fieldskillrate = atoi(types[jindex].data());
	jindex++;
	*/

	day = atoi(types[jindex].data());
	jindex++;


	month = atoi(types[jindex].data());
	jindex++;


	year = atoi(types[jindex].data());
	jindex++;


	execterm = atoi(types[jindex].data());
	jindex++;


	presparty = atoi(types[jindex].data());
	jindex++;


	amendnum = atoi(types[jindex].data());
	jindex++;


	multipleCityMode = atoi(types[jindex].data());
	jindex++;


	termlimits = atoi(types[jindex].data());
	jindex++;


	deagle = atoi(types[jindex].data());
	jindex++;


	m249 = atoi(types[jindex].data());
	jindex++;


	notermlimit = atoi(types[jindex].data());
	jindex++;


	nocourtpurge = atoi(types[jindex].data());
	jindex++;


	stalinmode = atoi(types[jindex].data());
	jindex++;


	stat_recruits = atoi(types[jindex].data());
	jindex++;


	stat_dead = atoi(types[jindex].data());
	jindex++;


	stat_kills = atoi(types[jindex].data());
	jindex++;


	stat_kidnappings = atoi(types[jindex].data());
	jindex++;


	stat_buys = atoi(types[jindex].data());
	jindex++;


	stat_burns = atoi(types[jindex].data());
	jindex++;
	/*

	endgamestate = atoi(types[jindex].data());
	jindex++;


	ccsexposure = atoi(types[jindex].data());
	jindex++;


	ccs_kills = atoi(types[jindex].data());
	jindex++;
	*/

	police_heat = atoi(types[jindex].data());
	jindex++;


	offended_corps = atoi(types[jindex].data());
	jindex++;


	offended_cia = atoi(types[jindex].data());
	jindex++;


	offended_amradio = atoi(types[jindex].data());
	jindex++;


	offended_cablenews = atoi(types[jindex].data());
	jindex++;


	offended_firemen = atoi(types[jindex].data());
	jindex++;

	/*
	attorneyseed[0] = atoi(types[jindex].data());
	jindex++;

	attorneyseed[1] = atoi(types[jindex].data());
	jindex++;

	attorneyseed[2] = atoi(types[jindex].data());
	jindex++;

	attorneyseed[3] = atoi(types[jindex].data());
	jindex++;
	*/
	strcpy(lcityname, types[jindex].data());
	jindex++;
	/*
	newscherrybusted = atoi(types[jindex].data());
	jindex++;
	*/
	if (jindex > maxJindex) {
		return;
	}

	strcpy(slogan, types[jindex].data());
	jindex++;

	party_status = atoi(types[jindex].data());
	jindex++;
	
	for (int i = 0; i < len(attitude); i++) {


		attitude[i] = atoi(types[jindex].data());
		jindex++;

	}

	for (int i = 0; i < len(lawList); i++) {


		lawList[i] = atoi(types[jindex].data());
		jindex++;

	}


	for (int i = 0; i < len(house); i++) {
		house[i] = atoi(types[jindex].data());
		jindex++;

	}


	for (int i = 0; i < len(senate); i++) {
		senate[i] = atoi(types[jindex].data());
		jindex++;

	}


	for (int i = 0; i < len(court); i++) {
		court[i] = atoi(types[jindex].data());
		jindex++;

	}


	for (int i = 0; i < len(courtname); i++) {
		strcpy(courtname[i], types[jindex].data());
		jindex++;
	}


	for (int i = 0; i < len(exec); i++) {
		exec[i] = atoi(types[jindex].data());
		jindex++;

	}


	for (int i = 0; i < len(execname); i++) {
		strcpy(execname[i], types[jindex].data());
		jindex++;
	}

	/*
	strcpy(oldPresidentName, types[jindex].data());
	jindex++;
	*/
	if (jindex > maxJindex) {
		return;
	}

	for (int pl = 0; pl < len(pool); pl++)
	{


		strcpy(pool[pl]->name, types[jindex].data());
		jindex++;

		strcpy(pool[pl]->propername, types[jindex].data());
		jindex++;
		/*
		pool[pl]->gender_conservative = atoi(types[jindex].data());
		jindex++;



		pool[pl]->gender_liberal = atoi(types[jindex].data());
		jindex++;

		*/

		pool[pl]->age = atoi(types[jindex].data());
		jindex++;



		pool[pl]->birthday_month = atoi(types[jindex].data());
		jindex++;



		pool[pl]->birthday_day = atoi(types[jindex].data());
		jindex++;



		pool[pl]->align = atoi(types[jindex].data());
		jindex++;



		pool[pl]->juice = atoi(types[jindex].data());
		jindex++;

		for (int i = 0; i < ATTNUM; i++) {


			pool[pl]->set_attribute(i, atoi(types[jindex].data()));
			jindex++;


		}
		for (int i = 0; i < SKILLNUM; i++) {


			pool[pl]->set_skill(i, atoi(types[jindex].data()));
			jindex++;


		}
		/*
		for (int i = 0; i < AUGMENTATIONNUM; i++) {
		pool[pl]->get_augmentation(i = atoi(types[jindex].data());
		jindex++;


		}

		for (int i = 0; i < BODYPARTNUM; i++) {//Bad, relies on their order in the xml file. -XML


		pool[pl]->wound[i] = atoi(types[jindex].data());
		jindex++;

		}
		for (int i = 0; i < SPECIALWOUNDNUM; i++) { //Bad, relies on their order in the xml file. -XML


		pool[pl]->special[i] = atoi(types[jindex].data());
		jindex++;

		}
		*/
		for (int i = 0; i < LAWFLAGNUM; i++) {
			pool[pl]->crimes_suspected[i] = atoi(types[jindex].data());
			jindex++;

		}

		if (jindex > maxJindex) {
			return;
		}
	}


}