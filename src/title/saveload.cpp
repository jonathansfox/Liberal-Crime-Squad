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

#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
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
	if (itemclass == "clip")
		it = new Clip(inputXml);
	else if (itemclass == "weapon")
		it = new Weapon(inputXml);
	else if (itemclass == "armor")
		it = new Armor(inputXml);
	else if (itemclass == "loot")
		it = new Loot(inputXml);
	else if (itemclass == "money")
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
					addstrAlt("Item type ");
					addstrAlt(location[l]->loot[l2]->get_itemtypename());
					addstrAlt(" does not exist. Deleting item.");
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
					addstrAlt("Item type ");
					addstrAlt(squad[sq]->loot[l2]->get_itemtypename());
					addstrAlt(" does not exist. Deleting item.");
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
				addstrAlt("Vehicle type " + vehicle[v]->vtypeidname() + " does not exist. Deleting vehicle.");
				delete_and_remove(vehicle, v--);
			}
		}
		return 1;
	}
	gamelog.log("Could not load");
	return 0;
}
/* deletes save.dat (used on endgame and for invalid save version) */
void reset()
{
	for (string filename : LCSSaveFiles()) {
		if (file_exists(filename)) LCSDeleteFile(filename.c_str(), LCSIO_PRE_HOME);
	}
}