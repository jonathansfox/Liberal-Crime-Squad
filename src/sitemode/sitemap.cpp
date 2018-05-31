
#include "../includes.h"
const string CONST_sitemapC043 = "Export";

const string CONST_sitemapB042 = "mapCSV_ApartmentIndustrial2_Tiles.csv";
const string CONST_sitemapB041 = "3";
const string CONST_sitemapB040 = "csv";
const string CONST_sitemap039 = "ApartmentIndustrial2";
const string CONST_sitemap038 = "2";
const string CONST_sitemap037 = "mapCSV_ApartmentIndustrial_Tiles.csv";
const string CONST_sitemap036 = "ApartmentIndustrial";
const string CONST_sitemap035 = "mapCSV_[NAMEHERE]_Specials.csv";
const string CONST_sitemap034 = "mapCSV_[NAMEHERE]_Tiles.csv";
const string CONST_sitemap033 = "../art";
const string CONST_sitemap032 = "csvTilemap.lua";
const string CONST_sitemap031 = "Deadly Alien Map Editor";
const string CONST_sitemap030 = "GENERIC_UNSECURE";

const string tag_WEIGHT = "WEIGHT";
const string tag_Z = "Z";
const string tag_FREQ = "FREQ";
const string tag_ZEND = "ZEND";
const string tag_ZSTART = "ZSTART";
const string tag_Y = "Y";
const string tag_YEND = "YEND";
const string tag_YSTART = "YSTART";
const string tag_X = "X";
const string tag_XEND = "XEND";
const string tag_XSTART = "XSTART";
const string tag_STAIRS_RANDOM = "STAIRS_RANDOM";
const string tag_STAIRS = "STAIRS";
const string tag_HALLWAY_YAXIS = "HALLWAY_YAXIS";
const string tag_ROOM = "ROOM";
const string tag_SUBTRACT = "SUBTRACT";
const string tag_ADD = "ADD";
const string tag_NOTE = "NOTE";
const string tag_LOOT = "LOOT";
const string tag_UNIQUE = "UNIQUE";
const string tag_SPECIAL = "SPECIAL";
const string tag_SCRIPT = "SCRIPT";
const string tag_TILE = "TILE";
const string tag_USE = "USE";
const string tag_NAME = "NAME";
const string tag_SITEMAP = "SITEMAP";
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
#include "../locations/locations.h"
#include "../configfile.h"
// needed for something contained in sitemap.h
#include "../sitemode/sitemap.h"
        //own header
void emptyEncounter();
void delete_and_clear_groundloot();
map<short, string> siteReadMap;
map<short, string> buildThisSite;
 vector<configSiteMap *> sitemaps;
 map<string, short> getUnique;
 map<string, string> getLootString;
 map<string, short> getSpecial;
 void delete_and_clear_sitemaps() {
	 delete_and_clear(sitemaps);
 }
 // Constructs the new object, returns a pointer to it
 configurable* createObject(const std::string& objectType)
 {
	 configurable* object = 0;
	 if (objectType == tag_SITEMAP)
		 sitemaps.push_back(static_cast<configSiteMap*>(object = new configSiteMap));
	 return object;
 }
 /* recursive dungeon-generating algorithm */
 void generateroom(int rx, int ry, int dx, int dy, int z)
 {
	 extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	 for (int x = rx; x < rx + dx; x++)
		 for (int y = ry; y < ry + dy; y++)
			 levelmap[x][y][z].flag &= ~SITEBLOCK_BLOCK;
	 if ((dx <= 3 || dy <= 3) && !LCSrandom(2))return;
	 if (dx <= 2 && dy <= 2)return;
	 //LAY DOWN WALL AND ITERATE
	 if ((!LCSrandom(2) || dy <= 2) && dx>2)
	 {
		 int wx = rx + LCSrandom(dx - 2) + 1;
		 for (int wy = 0; wy < dy; wy++)levelmap[wx][ry + wy][z].flag |= SITEBLOCK_BLOCK;
		 int rny = LCSrandom(dy);
		 levelmap[wx][ry + rny][z].flag &= ~SITEBLOCK_BLOCK;
		 levelmap[wx][ry + rny][z].flag |= SITEBLOCK_DOOR;
		 if (!LCSrandom(3))levelmap[wx][ry + rny][z].flag |= SITEBLOCK_LOCKED;
		 generateroom(rx, ry, wx - rx, dy, z);
		 generateroom(wx + 1, ry, rx + dx - wx - 1, dy, z);
	 }
	 else
	 {
		 int wy = ry + LCSrandom(dy - 2) + 1;
		 for (int wx = 0; wx < dx; wx++)levelmap[rx + wx][wy][z].flag |= SITEBLOCK_BLOCK;
		 int rnx = LCSrandom(dx);
		 levelmap[rx + rnx][wy][z].flag &= ~SITEBLOCK_BLOCK;
		 levelmap[rx + rnx][wy][z].flag |= SITEBLOCK_DOOR;
		 if (!LCSrandom(3))levelmap[rx + rnx][wy][z].flag |= SITEBLOCK_LOCKED;
		 generateroom(rx, ry, dx, wy - ry, z);
		 generateroom(rx, wy + 1, dx, ry + dy - wy - 1, z);
	 }
 }
 /////////////
 /////////////
 ///////////// NEW SITEMAP BASED ON CONFIG FILE CODE:
 /////////////
 /////////////
 // Builds a site based on the name provided
 void build_site(const std::string& name)
 {
	 for (int i = 0; i < len(sitemaps); i++)
		 if (*sitemaps[i] == name)
		 {
			 sitemaps[i]->build();
			 return;
		 }
	 // Backup: use a generic
	 build_site(CONST_sitemap030);
 }
 void addSemiPermanentChanges(Location &loc) {
	 extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	 /*******************************************************
	 * Add semi-permanent changes inflicted by LCS and others
	 *******************************************************/
	 // Some sites need a minimum amount of graffiti
	 int graffitiquota = 0;
	 if (loc.type == SITE_OUTDOOR_PUBLICPARK)graffitiquota = 5;
	 if (loc.type == SITE_BUSINESS_CRACKHOUSE)graffitiquota = 30;
	 if (loc.type == SITE_RESIDENTIAL_TENEMENT)graffitiquota = 10;
	 for (int i = 0; i < len(loc.changes); i++)
	 {
		 int x = loc.changes[i].x, y = loc.changes[i].y, z = loc.changes[i].z;
		 switch (loc.changes[i].flag)
		 {
		 case SITEBLOCK_GRAFFITI_OTHER: // Other tags
		 case SITEBLOCK_GRAFFITI_CCS: // CCS tags
		 case SITEBLOCK_GRAFFITI: // LCS tags
			 graffitiquota--;
			 break;
		 case SITEBLOCK_DEBRIS: // Smashed walls, ash
			 levelmap[x][y][z].flag &= ~SITEBLOCK_BLOCK;
			 levelmap[x][y][z].flag &= ~SITEBLOCK_DOOR;
			 break;
		 }
		 levelmap[x][y][z].flag |= loc.changes[i].flag;
	 }
	 // If there isn't enough graffiti for this site type, add some
	 while (graffitiquota > 0)
	 {
		 int x = LCSrandom(MAPX - 2) + 1, y = LCSrandom(MAPY - 2) + 1, z = 0;
		 if (loc.type == SITE_RESIDENTIAL_TENEMENT)z = LCSrandom(6);
		 if (!(levelmap[x][y][z].flag & SITEBLOCK_BLOCK) &&
			 (!(levelmap[x][y][z].flag & SITEBLOCK_RESTRICTED) || loc.type == SITE_BUSINESS_CRACKHOUSE) &&
			 !(levelmap[x][y][z].flag & SITEBLOCK_EXIT) &&
			 !(levelmap[x][y][z].flag & SITEBLOCK_GRAFFITI) &&
			 !(levelmap[x][y][z].flag & SITEBLOCK_GRAFFITI_OTHER) &&
			 !(levelmap[x][y][z].flag & SITEBLOCK_GRAFFITI_CCS))
			 if (levelmap[x + 1][y][z].flag & SITEBLOCK_BLOCK ||
				 levelmap[x - 1][y][z].flag & SITEBLOCK_BLOCK ||
				 levelmap[x][y + 1][z].flag & SITEBLOCK_BLOCK ||
				 levelmap[x][y - 1][z].flag & SITEBLOCK_BLOCK)
			 {
				 sitechangest change(x, y, z, SITEBLOCK_GRAFFITI_OTHER);
				 loc.changes.push_back(change);
				 levelmap[x][y][z].flag |= SITEBLOCK_GRAFFITI_OTHER;
				 graffitiquota--;
			 }
	 }
 }
 void addLootToLocation(Location &loc) {
	 extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	 for (int x = 2; x < MAPX - 2; x++)
		 for (int y = 2; y < MAPY - 2; y++)
			 for (int z = 0; z < MAPZ; z++)
				 if (!(levelmap[x][y][0].flag & SITEBLOCK_DOOR) &&
					 !(levelmap[x][y][0].flag & SITEBLOCK_BLOCK) &&
					 (levelmap[x][y][0].flag & SITEBLOCK_RESTRICTED) &&
					 !LCSrandom(10))
					 switch (loc.type)
					 {
					 case SITE_BUSINESS_BANK:
					 case SITE_RESIDENTIAL_SHELTER:
					 case SITE_BUSINESS_CRACKHOUSE:
					 case SITE_BUSINESS_JUICEBAR:
					 case SITE_BUSINESS_CIGARBAR:
					 case SITE_BUSINESS_LATTESTAND:
					 case SITE_BUSINESS_VEGANCOOP:
					 case SITE_BUSINESS_INTERNETCAFE:
					 case SITE_INDUSTRY_WAREHOUSE:
					 case SITE_BUSINESS_BARANDGRILL:
					 case SITE_OUTDOOR_BUNKER:
					 case SITE_RESIDENTIAL_BOMBSHELTER:               break;
					 default: levelmap[x][y][z].flag |= SITEBLOCK_LOOT; break;
					 }
 }
void clearOutRestrictions(Location &loc) {
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	 //Clear out restrictions
	 char acted;
	 do
	 {
		 acted = 0;
		 for (int x = 2; x < MAPX - 2; x++)
			 for (int y = 2; y < MAPY - 2; y++)
				 for (int z = 0; z < MAPZ; z++)
				 {  //Un-restrict blocks if they have neighboring
					//unrestricted blocks
					 if (!(levelmap[x][y][z].flag & SITEBLOCK_DOOR) &&
						 !(levelmap[x][y][z].flag & SITEBLOCK_BLOCK) &&
						 (levelmap[x][y][z].flag & SITEBLOCK_RESTRICTED))
					 {
						 if ((!(levelmap[x - 1][y][z].flag & SITEBLOCK_RESTRICTED) &&
							 !(levelmap[x - 1][y][z].flag & SITEBLOCK_BLOCK)) ||
							 (!(levelmap[x + 1][y][z].flag & SITEBLOCK_RESTRICTED) &&
								 !(levelmap[x + 1][y][z].flag & SITEBLOCK_BLOCK)) ||
								 (!(levelmap[x][y - 1][z].flag & SITEBLOCK_RESTRICTED) &&
									 !(levelmap[x][y - 1][z].flag & SITEBLOCK_BLOCK)) ||
									 (!(levelmap[x][y + 1][z].flag & SITEBLOCK_RESTRICTED) &&
										 !(levelmap[x][y + 1][z].flag & SITEBLOCK_BLOCK)))
						 {
							 levelmap[x][y][z].flag &= ~SITEBLOCK_RESTRICTED;
							 acted = 1;
							 continue;
						 }
					 }
					 //Un-restrict and unlock doors if they lead between two
					 //unrestricted sections. If they lead between one
					 //unrestricted section and a restricted section, lock
					 //them instead.
					 else if ((levelmap[x][y][z].flag & SITEBLOCK_DOOR) &&
						 !(levelmap[x][y][z].flag & SITEBLOCK_BLOCK) &&
						 (levelmap[x][y][z].flag & SITEBLOCK_RESTRICTED))
					 {  //Unrestricted on two opposite sides?
						 if (((!(levelmap[x - 1][y][z].flag & SITEBLOCK_RESTRICTED) && !(levelmap[x - 1][y][z].flag & SITEBLOCK_BLOCK)) &&
							 (!(levelmap[x + 1][y][z].flag & SITEBLOCK_RESTRICTED) && !(levelmap[x + 1][y][z].flag & SITEBLOCK_BLOCK))) ||
							 ((!(levelmap[x][y - 1][z].flag & SITEBLOCK_RESTRICTED) && !(levelmap[x][y - 1][z].flag & SITEBLOCK_BLOCK)) &&
							 (!(levelmap[x][y + 1][z].flag & SITEBLOCK_RESTRICTED) && !(levelmap[x][y + 1][z].flag & SITEBLOCK_BLOCK))))
						 {  //Unlock and unrestrict
							 levelmap[x][y][z].flag &= ~SITEBLOCK_LOCKED;
							 levelmap[x][y][z].flag &= ~SITEBLOCK_RESTRICTED;
							 acted = 1;
							 continue;
						 }
						 //Unrestricted on at least one side and I'm not locked?
						 else if ((!(levelmap[x - 1][y][z].flag & SITEBLOCK_RESTRICTED) ||
							 !(levelmap[x + 1][y][z].flag & SITEBLOCK_RESTRICTED) ||
							 !(levelmap[x][y - 1][z].flag & SITEBLOCK_RESTRICTED) ||
							 !(levelmap[x][y + 1][z].flag & SITEBLOCK_RESTRICTED)) &&
							 !(levelmap[x][y][z].flag   & SITEBLOCK_LOCKED))
						 {  //Lock doors leading to restricted areas
							 levelmap[x][y][z].flag |= SITEBLOCK_LOCKED;
							 acted = 1;
							 continue;
						 }
					 }
				 }
	 } while (acted);
 }
void useOldMapMode(Location &loc) {
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	  //ADD RESTRICTIONS
	   //bool restricted=0;
		switch (loc.type)
		{
		case SITE_LABORATORY_COSMETICS:
		case SITE_LABORATORY_GENETIC:
		case SITE_GOVERNMENT_POLICESTATION:
		case SITE_GOVERNMENT_COURTHOUSE:
		case SITE_GOVERNMENT_PRISON:
		case SITE_GOVERNMENT_INTELLIGENCEHQ:
		case SITE_GOVERNMENT_ARMYBASE:
		case SITE_GOVERNMENT_WHITE_HOUSE:
		case SITE_MEDIA_AMRADIO:
		case SITE_MEDIA_CABLENEWS:
			//restricted=1;
			for (int x = 2; x < MAPX - 2; x++)
				for (int y = 2; y < MAPY - 2; y++)
					for (int z = 0; z < MAPZ; z++)
						levelmap[x][y][z].flag |= SITEBLOCK_RESTRICTED;
			break;
		}
		
}
void useOldMapModeP2(Location &loc) {
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	//ADD ACCESSORIES
	for (int x = 2; x < MAPX - 2; x++)
		for (int y = 2; y < MAPY - 2; y++)
			for (int z = 0; z < MAPZ; z++)
			{
				if (!(levelmap[x][y][0].flag & SITEBLOCK_DOOR) &&
					!(levelmap[x][y][0].flag & SITEBLOCK_BLOCK) &&
					!LCSrandom(10))
				{
					switch (loc.type)
					{
					case SITE_BUSINESS_BANK: // the valuables are in the vault
					case SITE_RESIDENTIAL_SHELTER:
					case SITE_BUSINESS_CRACKHOUSE:
					case SITE_BUSINESS_JUICEBAR:
					case SITE_BUSINESS_CIGARBAR:
					case SITE_BUSINESS_LATTESTAND:
					case SITE_BUSINESS_VEGANCOOP:
					case SITE_BUSINESS_INTERNETCAFE:
					case SITE_INDUSTRY_WAREHOUSE:
						//seem to be weird things happening with loot in CCS bases - would the CCS call the police on you for stealing?
						//and shouldn't you be able to loot everything from there anyway once you've won?
						//removing the loot.
					case SITE_BUSINESS_BARANDGRILL:
					case SITE_OUTDOOR_BUNKER:
					case SITE_RESIDENTIAL_BOMBSHELTER:               break;
					default: levelmap[x][y][z].flag |= SITEBLOCK_LOOT; break;
					}
				}
				if (!(levelmap[x][y][0].flag&SITEBLOCK_DOOR) &&
					!(levelmap[x][y][0].flag&SITEBLOCK_BLOCK) &&
					!(levelmap[x][y][0].flag&SITEBLOCK_LOOT) &&
					(levelmap[x][y][0].flag&SITEBLOCK_RESTRICTED) &&
					loc.type == SITE_LABORATORY_COSMETICS && !LCSrandom(10))
					levelmap[x][y][z].special = SPECIAL_LAB_COSMETICS_CAGEDANIMALS;
				if (!(levelmap[x][y][0].flag&SITEBLOCK_DOOR) &&
					!(levelmap[x][y][0].flag&SITEBLOCK_BLOCK) &&
					!(levelmap[x][y][0].flag&SITEBLOCK_LOOT) &&
					(levelmap[x][y][0].flag&SITEBLOCK_RESTRICTED) &&
					loc.type == SITE_LABORATORY_GENETIC && !LCSrandom(10))
					levelmap[x][y][z].special = SPECIAL_LAB_GENETIC_CAGEDANIMALS;
				if (levelmap[x][y][0].flag == 0 &&
					loc.type == SITE_INDUSTRY_SWEATSHOP && !LCSrandom(10))
					levelmap[x][y][z].special = SPECIAL_SWEATSHOP_EQUIPMENT;
				if (levelmap[x][y][0].flag == 0 &&
					loc.type == SITE_INDUSTRY_POLLUTER && !LCSrandom(10))
					levelmap[x][y][z].special = SPECIAL_POLLUTER_EQUIPMENT;
				if (levelmap[x][y][0].flag == 0 &&
					(loc.type == SITE_BUSINESS_JUICEBAR ||
						loc.type == SITE_BUSINESS_CIGARBAR ||
						loc.type == SITE_BUSINESS_LATTESTAND ||
						loc.type == SITE_BUSINESS_INTERNETCAFE) &&
					!LCSrandom(10))
					levelmap[x][y][z].special = SPECIAL_RESTAURANT_TABLE;
				if (levelmap[x][y][z].flag == 0 && loc.type == SITE_BUSINESS_INTERNETCAFE &&
					!LCSrandom(10))
					levelmap[x][y][z].special = SPECIAL_CAFE_COMPUTER;
			}
	int freex, freey, freez = 0;
	//ADD FIRST SPECIAL
	int count = 100000;
	do
	{
		freex = LCSrandom(MAPX - 4) + 2, freey = LCSrandom(MAPY - 4) + 2;
		if (freex >= (MAPX >> 1) - 2 && freex <= (MAPX >> 1) + 2)freey = LCSrandom(MAPY - 6) + 4;
		count--;
	} while ((levelmap[freex][freey][freez].flag & SITEBLOCK_DOOR ||
		levelmap[freex][freey][freez].flag & SITEBLOCK_BLOCK ||
		levelmap[freex][freey][freez].flag & SITEBLOCK_LOOT ||
		levelmap[freex][freey][freez].special != -1) && count > 0);
	map<int, int>  site_special_list = {
		map<int, int> ::value_type(SITE_INDUSTRY_NUCLEAR,           SPECIAL_NUCLEAR_ONOFF),
		map<int, int> ::value_type(SITE_GOVERNMENT_POLICESTATION,   SPECIAL_POLICESTATION_LOCKUP),
		map<int, int> ::value_type(SITE_GOVERNMENT_COURTHOUSE,      SPECIAL_COURTHOUSE_LOCKUP),
		map<int, int> ::value_type(SITE_GOVERNMENT_PRISON,          SPECIAL_PRISON_CONTROL),
		map<int, int> ::value_type(SITE_GOVERNMENT_INTELLIGENCEHQ,  SPECIAL_INTEL_SUPERCOMPUTER),
		map<int, int> ::value_type(SITE_CORPORATE_HEADQUARTERS,     SPECIAL_CORPORATE_FILES),
		map<int, int> ::value_type(SITE_CORPORATE_HOUSE,            SPECIAL_HOUSE_PHOTOS),
		map<int, int> ::value_type(SITE_GOVERNMENT_ARMYBASE,        SPECIAL_ARMORY),
		map<int, int> ::value_type(SITE_MEDIA_AMRADIO,              SPECIAL_RADIO_BROADCASTSTUDIO),
		map<int, int> ::value_type(SITE_MEDIA_CABLENEWS,            SPECIAL_NEWS_BROADCASTSTUDIO),
	};
	if (site_special_list.count(loc.type)) {
		levelmap[freex][freey][freez].special = site_special_list[loc.type];
	}
	count = 100000;
	//ADD SECOND SPECIAL
	do
	{
		freex = LCSrandom(MAPX - 4) + 2, freey = LCSrandom(MAPY - 4) + 2;
		if (freex >= (MAPX >> 1) - 2 && freex <= (MAPX >> 1) + 2)freey = LCSrandom(MAPY - 6) + 4;
		count--;
	} while ((levelmap[freex][freey][freez].flag & SITEBLOCK_DOOR ||
		levelmap[freex][freey][freez].flag & SITEBLOCK_BLOCK ||
		levelmap[freex][freey][freez].flag & SITEBLOCK_LOOT ||
		levelmap[freex][freey][freez].special != -1) && count > 0);
	switch (loc.type)
	{
	case SITE_GOVERNMENT_COURTHOUSE: levelmap[freex][freey][freez].special = SPECIAL_COURTHOUSE_JURYROOM; break;
	}

}
void clearBlockedStairwells(Location &loc) {
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	//CLEAR BLOCKED STAIRWELLS
	for (int x = 0; x < MAPX; x++)
		for (int y = 0; y < MAPY; y++)
			for (int z = 0; z < MAPZ; z++)
				if (levelmap[x][y][z].flag & SITEBLOCK_BLOCK && levelmap[x][y][z].special == SPECIAL_STAIRS_DOWN)
				{
					levelmap[x][y][z].flag &= ~SITEBLOCK_BLOCK;
				}
}
void deleteNonDoors(Location &loc) {
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	//DELETE NON-DOORS
	for (int x = 0; x < MAPX; x++)
		for (int y = 0; y < MAPY; y++)
			for (int z = 0; z < MAPZ; z++)
				if (levelmap[x][y][z].flag & SITEBLOCK_DOOR)
				{
					char block = BIT1 | BIT2 | BIT3 | BIT4;
					if (x > 0)if (!(levelmap[x - 1][y][z].flag&SITEBLOCK_BLOCK))block &= ~BIT2;
					if (x < MAPX - 1)if (!(levelmap[x + 1][y][z].flag&SITEBLOCK_BLOCK))block &= ~BIT3;
					if (y > 0)if (!(levelmap[x][y - 1][z].flag&SITEBLOCK_BLOCK))block &= ~BIT1;
					if (y < MAPY - 1)if (!(levelmap[x][y + 1][z].flag&SITEBLOCK_BLOCK))block &= ~BIT4;
					if ((block & BIT1) && (block & BIT4))continue;
					if ((block & BIT2) && (block & BIT3))continue;
					levelmap[x][y][z].flag &= ~SITEBLOCK_DOOR;
					levelmap[x][y][z].flag &= ~SITEBLOCK_LOCKED;
				}
}
void clearBlockedDoorways(Location &loc) {
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	//CLEAR AWAY BLOCKED DOORWAYS
	for (int x = 0; x < MAPX; x++)
		for (int y = 0; y < MAPY; y++)
			for (int z = 0; z < MAPZ; z++)
				if (levelmap[x][y][z].flag & SITEBLOCK_DOOR)
				{  // Check what sides are blocked around the door
					char block = BIT1 | BIT2 | BIT3 | BIT4;
					char opennum = 0;
					if (x > 0)if (!(levelmap[x - 1][y][z].flag&SITEBLOCK_BLOCK)) { block &= ~BIT2; opennum++; }
					if (x < MAPX - 1)if (!(levelmap[x + 1][y][z].flag&SITEBLOCK_BLOCK)) { block &= ~BIT3; opennum++; }
					if (y > 0)if (!(levelmap[x][y - 1][z].flag&SITEBLOCK_BLOCK)) { block &= ~BIT1; opennum++; }
					if (y < MAPY - 1)if (!(levelmap[x][y + 1][z].flag&SITEBLOCK_BLOCK)) { block &= ~BIT4; opennum++; }
					//if(opennum>=2)continue;
					// Blast open everything around a totally blocked door
					// (door will later be deleted)
					if (block == (BIT1 | BIT2 | BIT3 | BIT4))
					{
						if (x > 0)levelmap[x - 1][y][z].flag &= ~SITEBLOCK_BLOCK;
						if (x < MAPX - 1)levelmap[x + 1][y][z].flag &= ~SITEBLOCK_BLOCK;
						if (y > 0)levelmap[x][y - 1][z].flag &= ~SITEBLOCK_BLOCK;
						if (y < MAPY - 1)levelmap[x][y + 1][z].flag &= ~SITEBLOCK_BLOCK;
					}
					// Open up past doors that lead to walls
					if (!(block&BIT1))
					{
						if (y < MAPY - 1)
						{
							int y1 = y + 1;
							do
							{
								levelmap[x][y1][z].flag &= ~SITEBLOCK_BLOCK;
								levelmap[x][y1][z].flag &= ~SITEBLOCK_DOOR;
								y1++;
							} while (!(levelmap[x + 1][y1][z].flag & (SITEBLOCK_BLOCK | SITEBLOCK_DOOR)) &&
								!(levelmap[x - 1][y1][z].flag & (SITEBLOCK_BLOCK | SITEBLOCK_DOOR)));
						}
						else levelmap[x][y][z].flag |= SITEBLOCK_BLOCK;
					}
					else if (!(block&BIT4))
					{
						if (y > 0)
						{
							int y1 = y - 1;
							do
							{
								levelmap[x][y1][z].flag &= ~SITEBLOCK_BLOCK;
								levelmap[x][y1][z].flag &= ~SITEBLOCK_DOOR;
								y1--;
							} while (!(levelmap[x + 1][y1][z].flag & (SITEBLOCK_BLOCK | SITEBLOCK_DOOR)) &&
								!(levelmap[x - 1][y1][z].flag & (SITEBLOCK_BLOCK | SITEBLOCK_DOOR)));
						}
						else levelmap[x][y][z].flag |= SITEBLOCK_BLOCK;
					}
					else if (!(block&BIT2))
					{
						if (x < MAPX - 1)
						{
							int x1 = x + 1;
							do
							{
								levelmap[x1][y][z].flag &= ~SITEBLOCK_BLOCK;
								levelmap[x1][y][z].flag &= ~SITEBLOCK_DOOR;
								x1++;
							} while (!(levelmap[x1][y + 1][z].flag & (SITEBLOCK_BLOCK | SITEBLOCK_DOOR)) &&
								!(levelmap[x1][y - 1][z].flag & (SITEBLOCK_BLOCK | SITEBLOCK_DOOR)));
						}
						else levelmap[x][y][z].flag |= SITEBLOCK_BLOCK;
					}
					else if (!(block&BIT3))
					{
						if (x > 0)
						{
							int x1 = x - 1;
							do
							{
								levelmap[x1][y][z].flag &= ~SITEBLOCK_BLOCK;
								levelmap[x1][y][z].flag &= ~SITEBLOCK_DOOR;
								x1--;
							} while (!(levelmap[x1][y + 1][z].flag & (SITEBLOCK_BLOCK | SITEBLOCK_DOOR)) &&
								!(levelmap[x1][y - 1][z].flag & (SITEBLOCK_BLOCK | SITEBLOCK_DOOR)));
						}
						else levelmap[x][y][z].flag |= SITEBLOCK_BLOCK;
					}
				}
}
void generateRandomMap(Location &loc) {
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	// Last resort -- generate random map
	levelmap[MAPX >> 1][0][0].flag = SITEBLOCK_EXIT;
	levelmap[(MAPX >> 1) + 1][0][0].flag = SITEBLOCK_EXIT;
	levelmap[(MAPX >> 1) + 1][1][0].flag = SITEBLOCK_EXIT;
	levelmap[(MAPX >> 1) - 1][0][0].flag = SITEBLOCK_EXIT;
	levelmap[(MAPX >> 1) - 1][1][0].flag = SITEBLOCK_EXIT;
	levelmap[MAPX >> 1][1][0].flag = 0;
	levelmap[MAPX >> 1][2][0].flag = SITEBLOCK_DOOR;
	if (loc.type == SITE_RESIDENTIAL_APARTMENT_UPSCALE ||
		loc.type == SITE_RESIDENTIAL_APARTMENT ||
		loc.type == SITE_RESIDENTIAL_TENEMENT)
	{
		levelmap[MAPX >> 1][1][0].special = SPECIAL_SIGN_ONE;
		short height;
		int floors = LCSrandom(6) + 1;
		for (int z = 0; z < floors; z++)
		{
			for (int y = 3; y < MAPY - 3; y++)
			{
				levelmap[MAPX >> 1][y][z].flag = 0;
				if (y % 4 == 0)
				{
					height = y + LCSrandom(3) - 1;
					levelmap[(MAPX >> 1) - 1][height][z].flag = SITEBLOCK_DOOR;
					generateroom((MAPX >> 1) - 8, y - 1, 7, 3, z);
					height = y + LCSrandom(3) - 1;
					levelmap[(MAPX >> 1) + 1][height][z].flag = SITEBLOCK_DOOR;
					generateroom((MAPX >> 1) + 2, y - 1, 7, 3, z);
					if (y == 4 && z == 0)
					{
						levelmap[(MAPX >> 1) + 2][height][z].flag = 0;
						levelmap[(MAPX >> 1) + 2][height][z].special = SPECIAL_APARTMENT_LANDLORD;
					}
				}
			}
			int swap = (z % 2) * 2 - 1;
			if (z > 0)levelmap[(MAPX >> 1) + 1 * swap][MAPY - 4][z].flag = 0, levelmap[(MAPX >> 1) + 1 * swap][MAPY - 4][z].special = SPECIAL_STAIRS_DOWN;
			if (z < floors - 1)levelmap[(MAPX >> 1) - 1 * swap][MAPY - 4][z].flag = 0, levelmap[(MAPX >> 1) - 1 * swap][MAPY - 4][z].special = SPECIAL_STAIRS_UP;
		}
	}
	else
	{
		switch (loc.type)
		{
		case SITE_BUSINESS_LATTESTAND:
			for (int x = (MAPX >> 1) - 4; x <= (MAPX >> 1) + 4; x++)
				for (int y = 0; y < 7; y++)
					levelmap[x][y][0].flag = (x == (MAPX >> 1) - 4 || x == (MAPX >> 1) + 4 || y == 0 || y == 6 ? SITEBLOCK_EXIT : 0), levelmap[x][y][0].special = -1, levelmap[x][y][0].siegeflag = 0;
			break;
		case SITE_BUSINESS_JUICEBAR:
		case SITE_BUSINESS_CIGARBAR:
		case SITE_BUSINESS_VEGANCOOP:
		case SITE_BUSINESS_INTERNETCAFE:
			for (int x = (MAPX >> 1) - 4; x <= (MAPX >> 1) + 4; x++)
				for (int y = 3; y < 10; y++)
					levelmap[x][y][0].flag = 0, levelmap[x][y][0].special = -1, levelmap[x][y][0].siegeflag = 0;
			break;
		case SITE_BUSINESS_CRACKHOUSE:
		{
			int dx = LCSrandom(5) * 2 + 19, dy = LCSrandom(3) * 2 + 7, rx = (MAPX >> 1) - (dx >> 1), ry = 3;
			generateroom(rx, ry, dx, dy, 0);
			break;
		}
		default:
		{
			int dx = LCSrandom(5) * 2 + 35, dy = LCSrandom(3) * 2 + 15, rx = (MAPX >> 1) - (dx >> 1), ry = 3;
			generateroom(rx, ry, dx, dy, 0);
			break;
		}
		}
	}
	// End of old build code. SAV
}
/* re-create site from seed before squad arrives */
void initsite(Location &loc)
{
	extern squadst *activesquad;
	extern int oldMapMode;
	//PREP
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern unsigned long seed[RNG_SIZE];
	if (activesquad == NULL)return;
	emptyEncounter();
	for (int p = 0; p < 6; p++)
		if (activesquad->squad[p] != NULL)
			activesquad->squad[p]->forceinc = 0;
	delete_and_clear_groundloot();
	
	//MAKE MAP
	unsigned long oldseed[RNG_SIZE];
	copyRNG(oldseed, seed);
	copyRNG(seed, loc.mapseed);
	// A short guide to how the new maps work...
	//
	//   Edit maps using DAME, the CONST_sitemap031. You can find a maps.dam file
	// to open with DAME in the /dev directory. You can find DAME here (try search engine if link
	// is out of date):
	//   http://dambots.com/dame-editor/
	//
	//   Open up the maps.dam file in DAME. On one side, in the layers listing, you'll see the existing
	// maps. Use the check boxes to hide and show maps. You can create new maps by copying the old ones;
	// right click a top-level group (like NuclearPlant) and select Duplicate. Rename the new map based
	// on the conventions described below.
	//   Editing using the Paint tool ('B') is easy; click the tile you want in the tiles panel, then click
	// the map view to paint with that tile. You may need to experiment a bit to figure out what the
	// specials icons represent, but I've tried to make it pretty self-explanatory. Box-drawing to fill
	// large areas is possible, but a little clunky -- use the Tile Matrix tool ('M') and fill the entire
	// matrix with the tile you want to use by dragging tiles from the tiles panel. You can then box-drag
	// to fill large areas.
	//   When you're done editing, save maps.dam and use File->Export to create the map source files the
	// game can run. In the Export Project dialog, use CONST_sitemap032 for the LUA exporter. CSV dir should
	// be CONST_sitemap033 and File Extension should be CONST_sitemapB040. These are probably the defaults. Press CONST_sitemapC043 and
	// it will automagically build the map source files. You're done -- run the game and visit that
	// location to view the results in-game. You don't even need to make a new game.
	//   To remove a map from the game and go back to the old map generation modes, just delete the .csv
	// files. You may also want to clean up the maps.dam file, removing any old maps you don't want, since
	// it'll try to generate them again next time you export.
	//
	//   Map naming conventions:
	// CONST_sitemap034 - Tile map
	// CONST_sitemap035 - Special locations (vault, equipment, lockup, etc.)
	//   [NAMEHERE] is the name in quotes below, and it's what the maps are called in the DAME layer list.
	// For example, for the industrial apartment, the DAME name is CONST_sitemap036, and the
	// exported file name is CONST_sitemap037. DAME should add the prefix and suffix
	// to the exported files automatically.
	//
	//   Additional Notes:
	// 1. All maps MUST have both a tile map and a special map, even if the special map is blank. This
	// goes for both first floor maps and otherwise.
	// 2. For multi-floor maps, add up stairs to the special map, then create a new set of maps for
	// each additional floor, appending CONST_sitemap038 to the location name for the second floor, CONST_sitemapB041 for
	// third floor, and so on. For example, a second floor to the industrial apartments would have the
	// name CONST_sitemap039 in DAME, and export as CONST_sitemapB042.
	//
	// With love,
	//   Fox
	// Try to load from a map file
	bool loaded = false;
	if (siteReadMap.count(loc.type)) {
		loaded = readMap(siteReadMap[loc.type]);
	}
	else {
	}
	if (!loaded)
	{
		for (int x = 0; x < MAPX; x++)
			for (int y = 0; y < MAPY; y++)
				for (int z = 0; z < MAPZ; z++)
				{
					levelmap[x][y][z].flag = SITEBLOCK_BLOCK;
					levelmap[x][y][z].special = -1;
					levelmap[x][y][z].siegeflag = 0;
				}
	}
	if (loaded)
	{
		if (loc.renting == RENTING_PERMANENT && loc.type != SITE_RESIDENTIAL_APARTMENT &&
			loc.type != SITE_RESIDENTIAL_APARTMENT_UPSCALE && loc.type != SITE_RESIDENTIAL_TENEMENT)
		{
			for (int x = 0; x < MAPX; x++)
				for (int y = 0; y < MAPY; y++)
					for (int z = 0; z < MAPZ; z++)
					{  // Clear high security, locked doors, alarms, and site specials
					   // from LCS non-apartment safehouses
						levelmap[x][y][z].flag &= ~SITEBLOCK_LOCKED;
						levelmap[x][y][z].flag &= ~SITEBLOCK_RESTRICTED;
						levelmap[x][y][z].flag &= ~SITEBLOCK_ALARMED;
						levelmap[x][y][z].special = -1;
					}
		}
	}
	else if (!oldMapMode) // Try to load from the sitemaps
	{
		if (buildThisSite.count(loc.type)) {
			build_site(buildThisSite[loc.type]);
		}
	}
	else {
		generateRandomMap(loc);
	}
	clearBlockedDoorways(loc);
	deleteNonDoors(loc);
	clearBlockedStairwells(loc);
	if (oldMapMode) {
		useOldMapMode(loc);
		copyRNG(seed, oldseed);
		useOldMapModeP2(loc);
	}
	// SAV - End more old map stuff.
	clearOutRestrictions(loc);
	//ADD LOOT
	copyRNG(seed, oldseed);
	addLootToLocation(loc);
	addSemiPermanentChanges(loc);
}
configSiteMap::~configSiteMap()
{
	delete_and_clear(commands);
}
void configSiteMap::configure(const std::string& command, const std::string& value)
{
	if (command == tag_NAME)name = value;
	else if (command == tag_USE)parent = value;
	else if (command == tag_TILE)
	{
		current_command = new configSiteTile(value);
		commands.push_back(current_command);
	}
	else if (command == tag_SCRIPT)
	{
		current_command = new configSiteScript(value);
		commands.push_back(current_command);
	}
	else if (command == tag_SPECIAL)
	{
		current_command = new configSiteSpecial(value);
		commands.push_back(current_command);
	}
	else if (command == tag_UNIQUE)
	{
		current_command = new configSiteUnique(value);
		commands.push_back(current_command);
	}
	else if (command == tag_LOOT)
	{
		current_command = new configSiteLoot(value);
		commands.push_back(current_command);
	}
	else current_command->configure(command, value);
}
void configSiteMap::build()
{
	if (len(parent)) build_site(parent);
	for (int step = 0; step < len(commands); step++) commands[step]->build();
}
map<string, short> site_tile_list;
configSiteTile::configSiteTile(const std::string& value)
	: xstart(0), xend(0), ystart(0), yend(0), zstart(0), zend(0), addtype(0)
{
	if (site_tile_list.count(value)) {
		tile = site_tile_list[value];
	}
}
void configSiteTile::configure(const std::string& command, const std::string& value)
{
	if (command == tag_XSTART)xstart = atoi(value.c_str()) + (MAPX >> 1);
	else if (command == tag_XEND)xend = atoi(value.c_str()) + (MAPX >> 1);
	else if (command == tag_X)xstart = xend = atoi(value.c_str()) + (MAPX >> 1);
	else if (command == tag_YSTART)ystart = atoi(value.c_str());
	else if (command == tag_YEND)yend = atoi(value.c_str());
	else if (command == tag_Y)ystart = yend = atoi(value.c_str());
	else if (command == tag_ZSTART)zstart = atoi(value.c_str());
	else if (command == tag_ZEND)zend = atoi(value.c_str());
	else if (command == tag_Z)zstart = zend = atoi(value.c_str());
	else if (command == tag_NOTE)
	{
		if (value == tag_ADD)addtype = SITEMAP_ADDTYPE_OR;
		else if (value == tag_SUBTRACT)addtype = SITEMAP_ADDTYPE_ANDNOT;
	}
}
void configSiteTile::build()
{
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	for (int x = xstart; x <= xend; x++)
		for (int y = ystart; y <= yend; y++)
			for (int z = zstart; z <= zend; z++)
				if (addtype == SITEMAP_ADDTYPE_OR)levelmap[x][y][z].flag |= tile;
				else if (addtype == SITEMAP_ADDTYPE_ANDNOT)levelmap[x][y][z].flag &= ~tile;
				else levelmap[x][y][z].flag = tile;
}
configSiteScript::configSiteScript(const std::string& value)
	: xstart(0), xend(0), ystart(0), yend(0), zstart(0), zend(0)
{
	if (value == tag_ROOM)script = SITEMAPSCRIPT_ROOM;
	else if (value == tag_HALLWAY_YAXIS)script = SITEMAPSCRIPT_HALLWAY_YAXIS;
	else if (value == tag_STAIRS)script = SITEMAPSCRIPT_STAIRS;
	else if (value == tag_STAIRS_RANDOM)script = SITEMAPSCRIPT_STAIRS_RANDOM;
}
void configSiteScript::configure(const std::string& command, const std::string& value)
{
	if (command == tag_XSTART)xstart = atoi(value.c_str()) + (MAPX >> 1);
	else if (command == tag_XEND)xend = atoi(value.c_str()) + (MAPX >> 1);
	else if (command == tag_YSTART)ystart = atoi(value.c_str());
	else if (command == tag_YEND)yend = atoi(value.c_str());
	else if (command == tag_ZSTART)zstart = atoi(value.c_str());
	else if (command == tag_ZEND)zend = atoi(value.c_str());
}
void configSiteScript::build()
{
	if (script == SITEMAPSCRIPT_ROOM)
		for (int z = zstart; z <= zend; z++)
			generateroom(xstart, ystart, xend - xstart, yend - ystart, z);
	else if (script == SITEMAPSCRIPT_HALLWAY_YAXIS)
		for (int z = zstart; z <= zend; z++)
			generatehallway_y(xstart, ystart, xend - xstart, yend - ystart, z);
	else if (script == SITEMAPSCRIPT_STAIRS)
		generatestairs(xstart, ystart, zstart, xend - xstart, yend - ystart, zend - zstart);
	else if (script == SITEMAPSCRIPT_STAIRS_RANDOM)
		generatestairsrandom(xstart, ystart, zstart, xend - xstart, yend - ystart, zend - zstart);
}
const int ROOMDIMENSION = 3;
/* recursive dungeon-generating algorithm */
void configSiteScript::generateroom(int rx, int ry, int dx, int dy, int z)
{
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	for (int x = rx; x < rx + dx; x++)
		for (int y = ry; y < ry + dy; y++)
			levelmap[x][y][z].flag &= ~SITEBLOCK_BLOCK;
	// Chance to stop iterating for large rooms
	if ((dx <= (ROOMDIMENSION + 1) || dy <= (ROOMDIMENSION + 1)) &&
		dx < dy * 2 && dy<dx * 2 && !LCSrandom(2))return;
	// Very likely to stop iterating for small rooms
	if (dx <= ROOMDIMENSION&&dy <= ROOMDIMENSION)return;
	// Guaranteed to stop iterating for hallways
	if (dx <= 1 || dy <= 1)return;
	//LAY DOWN WALL AND ITERATE
	if ((!LCSrandom(2) || dy <= ROOMDIMENSION) && dx>ROOMDIMENSION)
	{
		int wx = rx + LCSrandom(dx - ROOMDIMENSION) + 1;
		for (int wy = 0; wy < dy; wy++)levelmap[wx][ry + wy][z].flag |= SITEBLOCK_BLOCK;
		int rny = LCSrandom(dy);
		levelmap[wx][ry + rny][z].flag &= ~SITEBLOCK_BLOCK;
		levelmap[wx][ry + rny][z].flag |= SITEBLOCK_DOOR;
		if (!LCSrandom(3))levelmap[wx][ry + rny][z].flag |= SITEBLOCK_LOCKED;
		generateroom(rx, ry, wx - rx, dy, z);
		generateroom(wx + 1, ry, rx + dx - wx - 1, dy, z);
	}
	else
	{
		int wy = ry + LCSrandom(dy - ROOMDIMENSION) + 1;
		for (int wx = 0; wx < dx; wx++)levelmap[rx + wx][wy][z].flag |= SITEBLOCK_BLOCK;
		int rnx = LCSrandom(dx);
		levelmap[rx + rnx][wy][z].flag &= ~SITEBLOCK_BLOCK;
		levelmap[rx + rnx][wy][z].flag |= SITEBLOCK_DOOR;
		if (!LCSrandom(3))levelmap[rx + rnx][wy][z].flag |= SITEBLOCK_LOCKED;
		generateroom(rx, ry, dx, wy - ry, z);
		generateroom(rx, wy + 1, dx, ry + dy - wy - 1, z);
	}
}
/* generates a hallway with rooms on either side */
void configSiteScript::generatehallway_y(int rx, int ry, int dx, int dy, int z)
{
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	for (int y = ry; y < ry + dy; y++)
	{  // Clear hallway
		levelmap[rx][y][z].flag = 0;
		// Every four tiles
		if (y % 4 == 0)
		{
			// Pick a door location for the left
			char door_y = y + LCSrandom(3) - 1;
			// Create the left door
			levelmap[rx - 1][(int)door_y][z].flag &= ~SITEBLOCK_BLOCK;
			levelmap[rx - 1][(int)door_y][z].flag |= SITEBLOCK_DOOR;
			// Construct apartment on the left
			generateroom(rx - dx - 1, y - 1, dx, 3, z);
			// Pick a door location for the right
			door_y = y + LCSrandom(3) - 1;
			// Create the right door
			levelmap[rx + 1][(int)door_y][z].flag &= ~SITEBLOCK_BLOCK;
			levelmap[rx + 1][(int)door_y][z].flag |= SITEBLOCK_DOOR;
			// Construct apartment on the right
			generateroom(rx + 2, y - 1, dx, 3, z);
		}
	}
}
/* generates a stairwell, must have (dx or dy) and dz at least 1 */
void configSiteScript::generatestairs(int rx, int ry, int rz, int dx, int dy, int dz)
{
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	for (int z = rz; z <= rz + dz; z++)
	{
		if (z > rz) // If not bottom floor, add down stairs
		{
			if (z % 2) // Causes stairwell to swap sides every other floor
			{  // Purge all tiles other than restriction, add stairs
				levelmap[rx + dx][ry + dy][z].flag &= SITEBLOCK_RESTRICTED;
				levelmap[rx + dx][ry + dy][z].special = SPECIAL_STAIRS_DOWN;
			}
			else
			{
				levelmap[rx][ry][z].flag &= SITEBLOCK_RESTRICTED;
				levelmap[rx][ry][z].special = SPECIAL_STAIRS_DOWN;
			}
		}
		if (z < rz + dz) // If not top floor, add up stairs
		{
			if (!(z % 2))
			{  // Purge all tiles other than restriction, add stairs
				levelmap[rx + dx][ry + dy][z].flag &= SITEBLOCK_RESTRICTED;
				levelmap[rx + dx][ry + dy][z].special = SPECIAL_STAIRS_UP;
			}
			else
			{
				levelmap[rx][ry][z].flag &= SITEBLOCK_RESTRICTED;
				levelmap[rx][ry][z].special = SPECIAL_STAIRS_UP;
			}
		}
	}
}
void configSiteScript::generatestairsrandom(int rx, int ry, int rz, int dx, int dy, int dz)
{
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	int x, y, z;
	vector< std::pair<int, int> > secure, secure_above, unsecure, unsecure_above;
	// Look through bottom level for secure and unsecure tiles.
	for (int xi = xstart; xi <= xend; xi++)
		for (int yi = ystart; yi <= yend; yi++)
			if (!(levelmap[xi][yi][0].flag & (SITEBLOCK_DOOR | SITEBLOCK_BLOCK | SITEBLOCK_EXIT | SITEBLOCK_OUTDOOR)) &&
				levelmap[xi][yi][0].special == SPECIAL_NONE)
			{
				if (levelmap[xi][yi][0].flag & SITEBLOCK_RESTRICTED)
					secure.push_back(std::make_pair(xi, yi));
				else unsecure.push_back(std::make_pair(xi, yi));
			}
	for (int zi = zstart + 1; zi <= zend; zi++)
	{
		// Look through level above for secure and unsecure tiles.
		for (int xi = xstart; xi <= xend; xi++)
			for (int yi = ystart; yi <= yend; yi++)
				if (!(levelmap[xi][yi][zi].flag & (SITEBLOCK_DOOR | SITEBLOCK_BLOCK | SITEBLOCK_EXIT | SITEBLOCK_OUTDOOR)) &&
					levelmap[xi][yi][zi].special == SPECIAL_NONE)
				{
					if (levelmap[xi][yi][zi].flag & SITEBLOCK_RESTRICTED)
						secure_above.push_back(std::make_pair(xi, yi));
					else unsecure_above.push_back(std::make_pair(xi, yi));
				}
		// Stairs in secure areas should only lead into secure areas.
		// Removing secure tiles without secure tiles above them.
		//int i, j;
		for (int i = len(unsecure) - 1; i >= 0; i--)
		{
			int j;
			for (j = 0; j<len(secure_above); j++)
			{
				if (secure_above[j] == secure[i]) break;
				else if ((secure_above[j].first == secure[i].first&&secure_above[j].second>secure[i].second)
					|| (secure_above[j].first > secure[i].first))
				{
					secure.erase(secure.begin() + i); break;
				}
			}
			if (j == len(secure_above)) secure.erase(secure.begin() + i);
		}
		// Stairs in unsecure areas should only lead into unsecure areas.
		// Removing unsecure tiles without unsecure tiles above them.
		for (int i = len(unsecure) - 1; i >= 0; i--)
		{
			int j;
			for (j = 0; j<len(unsecure_above); j++)
			{
				if (unsecure_above[j] == unsecure[i]) break;
				else if ((unsecure_above[j].first == unsecure[i].first&&unsecure_above[j].second>unsecure[i].second)
					|| (unsecure_above[j].first > unsecure[i].first))
				{
					unsecure.erase(unsecure.begin() + i); break;
				}
			}
			if (j == len(unsecure_above)) unsecure.erase(unsecure.begin() + i);
		}
		// Place stairs in secure area if possible, otherwise unsecure area.
		if (len(secure))
		{
			std::pair<int, int> &choice = pickrandom(secure);
			x = choice.first, y = choice.second, z = zi - 1;
			// The tile receiving the stairs down will not eligible for stairs
			// up later.
			for (int j = 0; j < len(secure_above); j++)
				if (secure_above[j].first == x&&secure_above[j].second == y)
				{
					secure_above.erase(secure_above.begin() + j); break;
				}
		}
		else if (len(unsecure))
		{
			std::pair<int, int> &choice = pickrandom(unsecure);
			x = choice.first, y = choice.second, z = zi - 1;
			// The tile receiving the stairs down will not eligible for stairs
			// up later.
			for (int j = 0; j < len(unsecure_above); j++)
				if (unsecure_above[j].first == x&&unsecure_above[j].second == y)
				{
					unsecure_above.erase(unsecure_above.begin() + j); break;
				}
		}
		else continue; //Nowhere to place stairs.
		levelmap[x][y][z].special = SPECIAL_STAIRS_UP, levelmap[x][y][z + 1].special = SPECIAL_STAIRS_DOWN;
		// Move up on level for next iteration.
		secure = secure_above;
		secure_above.clear();
		unsecure = unsecure_above;
		unsecure_above.clear();
	}
}
configSiteSpecial::configSiteSpecial(const std::string& value)
	: xstart(0), xend(0), ystart(0), yend(0), zstart(0), zend(0), freq(1)
{
	if (getSpecial.count(value)) {
		special = getSpecial[value];
	}
}
void configSiteSpecial::configure(const std::string& command, const std::string& value)
{
	if (command == tag_XSTART)xstart = atoi(value.c_str()) + (MAPX >> 1);
	else if (command == tag_XEND)xend = atoi(value.c_str()) + (MAPX >> 1);
	else if (command == tag_X)xstart = xend = atoi(value.c_str()) + (MAPX >> 1);
	else if (command == tag_YSTART)ystart = atoi(value.c_str());
	else if (command == tag_YEND)yend = atoi(value.c_str());
	else if (command == tag_Y)ystart = yend = atoi(value.c_str());
	else if (command == tag_ZSTART)zstart = atoi(value.c_str());
	else if (command == tag_ZEND)zend = atoi(value.c_str());
	else if (command == tag_Z)zstart = zend = atoi(value.c_str());
	else if (command == tag_FREQ)freq = atoi(value.c_str());
}
void configSiteSpecial::build()
{
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	for (int x = xstart; x <= xend; x++)
		for (int y = ystart; y <= yend; y++)
			for (int z = zstart; z <= zend; z++)
				if (!LCSrandom(freq))levelmap[x][y][z].special = special;
}
configSiteUnique::configSiteUnique(const std::string& value)
	: xstart((MAPX >> 1) - 5), xend((MAPX >> 1) + 5), ystart(10), yend(20), zstart(0), zend(0)
{
	if (getUnique.count(value)) {
		unique = getUnique[value];
	}
}
void configSiteUnique::configure(const std::string& command, const std::string& value)
{
	if (command == tag_Z)zstart = zend = atoi(value.c_str());
}
struct coordinates
{
	coordinates(int x1, int y1, int z1) : x(x1), y(y1), z(z1) { }
	int x, y, z;
};
void configSiteUnique::build()
{
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	//int count=0;
	vector<coordinates> secure, unsecure;
	//Clear out restrictions
	char acted;
	do
	{
		acted = 0;
		for (int x = 2; x < MAPX - 2; x++)
			for (int y = 2; y < MAPY - 2; y++)
				for (int z = 0; z < MAPZ; z++)
				{
					//Un-restrict blocks if they have neighboring
					//unrestricted blocks
					if (!(levelmap[x][y][z].flag & SITEBLOCK_DOOR) &&
						!(levelmap[x][y][z].flag & SITEBLOCK_BLOCK) &&
						(levelmap[x][y][z].flag & SITEBLOCK_RESTRICTED))
					{
						if ((!(levelmap[x - 1][y][z].flag & SITEBLOCK_RESTRICTED) &&
							!(levelmap[x - 1][y][z].flag & SITEBLOCK_BLOCK)) ||
							(!(levelmap[x + 1][y][z].flag & SITEBLOCK_RESTRICTED) &&
								!(levelmap[x + 1][y][z].flag & SITEBLOCK_BLOCK)) ||
							(!(levelmap[x][y - 1][z].flag & SITEBLOCK_RESTRICTED) &&
								!(levelmap[x][y - 1][z].flag & SITEBLOCK_BLOCK)) ||
							(!(levelmap[x][y + 1][z].flag & SITEBLOCK_RESTRICTED) &&
								!(levelmap[x][y + 1][z].flag & SITEBLOCK_BLOCK)))
						{
							levelmap[x][y][z].flag &= ~SITEBLOCK_RESTRICTED;
							acted = 1;
							continue;
						}
					}
					//Un-restrict and unlock doors if they lead between two
					//unrestricted sections. If they lead between one
					//unrestricted section and a restricted section, lock
					//them instead.
					else if ((levelmap[x][y][z].flag & SITEBLOCK_DOOR) &&
						!(levelmap[x][y][z].flag & SITEBLOCK_BLOCK) &&
						(levelmap[x][y][z].flag & SITEBLOCK_RESTRICTED))
					{  //Unrestricted on two opposite sides?
						if ((!(levelmap[x - 1][y][z].flag & SITEBLOCK_RESTRICTED) &&
							!(levelmap[x + 1][y][z].flag & SITEBLOCK_RESTRICTED)) ||
							(!(levelmap[x][y - 1][z].flag & SITEBLOCK_RESTRICTED) &&
								!(levelmap[x][y + 1][z].flag & SITEBLOCK_RESTRICTED)))
						{
							//Unlock and unrestrict
							levelmap[x][y][z].flag &= ~SITEBLOCK_LOCKED;
							levelmap[x][y][z].flag &= ~SITEBLOCK_RESTRICTED;
							acted = 1;
							continue;
						}
						//Unrestricted on at least one side and I'm not locked?
						else if ((!(levelmap[x - 1][y][z].flag & SITEBLOCK_RESTRICTED) ||
							!(levelmap[x + 1][y][z].flag & SITEBLOCK_RESTRICTED) ||
							!(levelmap[x][y - 1][z].flag & SITEBLOCK_RESTRICTED) ||
							!(levelmap[x][y + 1][z].flag & SITEBLOCK_RESTRICTED)) &&
							!(levelmap[x][y][z].flag & SITEBLOCK_LOCKED))
						{  //Lock doors leading to restricted areas
							levelmap[x][y][z].flag |= SITEBLOCK_LOCKED;
							acted = 1;
							continue;
						}
					}
				}
	} while (acted);
	// Place unique
	for (int x = xstart; x <= xend; x++)
		for (int y = ystart; y <= yend; y++)
			for (int z = zstart; z <= zend; z++)
				if (!(levelmap[x][y][z].flag & (SITEBLOCK_DOOR | SITEBLOCK_BLOCK | SITEBLOCK_EXIT | SITEBLOCK_OUTDOOR)) &&
					levelmap[x][y][z].special == SPECIAL_NONE)
				{
					if (levelmap[x][y][z].flag & SITEBLOCK_RESTRICTED)
						secure.push_back(coordinates(x, y, z));
					else unsecure.push_back(coordinates(x, y, z));
				}

	if (len(secure))
	{
		coordinates &choice = pickrandom(secure);
		levelmap[choice.x][choice.y][choice.z].special = unique;
	}
	else if (len(unsecure))
	{
		coordinates &choice = pickrandom(unsecure);
		levelmap[choice.x][choice.y][choice.z].special = unique;
	}
}
// Adds a loot type during map creation
configSiteLoot::configSiteLoot(const std::string& value)
	: weight(0)
{
	if (getLootString.count(value)) {
		loot = getLootString[value];
	}
}
void configSiteLoot::configure(const std::string& command, const std::string& value)
{
	if (command == tag_WEIGHT)weight = atoi(value.c_str());
}
void configSiteLoot::build()
{
	// currently no-op until loot system is revised
}