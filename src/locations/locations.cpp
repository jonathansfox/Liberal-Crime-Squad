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

#include <includes.h>
#include "creature/creature.h"

#include "common/creaturePool.h"
extern bool multipleCityMode;

extern string singleSpace;
extern string commaSpace;
extern short lawList[LAWNUM];
extern class Ledger ledger;

typedef map<short, string> shortAndString;
typedef map<short, vector<string>> shortAndTwoStrings;
// Finds a location with the corresponding type and returns
// its index in the location array
 vector<string> labor_camp_name;
 vector<string> labor_camp_name_2;
 vector<string> juice_name;
 vector<string> juice_name_2;
 vector<string> vegan_name;
 vector<string> vegan_name_2;
 vector<string> cafe_name;
 vector<string> cafe_name_2;
 vector<string> latte_name;
 vector<string> latte_name_2;


void Location::init()
{
	haveflag = 0;
	newrental = 0;
	heat = 0;
	heat_protection = 0;
	closed = 0;
	mapped = 0;
	highsecurity = 0;
	initOtherRNG(mapseed);
	changes.clear();
	compound_walls = 0;
	compound_stores = 0;
	front_business = -1;
}

 shortAndString getCityDescription;
string Location::city_description()
{
	if (getCityDescription.count(type)) {
		return getCityDescription[type];
	}
	else {
		return "";
	}
}
bool Location::can_be_fortified()
{
	if (!upgradable) return false;
	switch (type)
	{
	default:
		return !fortified();
	case SITE_OUTDOOR_BUNKER:
	case SITE_BUSINESS_BARANDGRILL:
		return false;
	}
}
bool Location::fortified()
{
	switch (type)
	{
	default:
		return compound_walls & COMPOUND_BASIC;
	case SITE_OUTDOOR_BUNKER:
		return true;
	}
}
bool Location::can_be_trapped()
{
	if (!upgradable) return false;
	return !trapped();
}
bool Location::can_install_tanktraps()
{
	if (!upgradable) return false;
	switch (type)
	{
	default:
		return !tank_traps();
	case SITE_BUSINESS_BARANDGRILL:
	case SITE_OUTDOOR_BUNKER:
	case SITE_RESIDENTIAL_BOMBSHELTER:
		return false;
	}
}
bool Location::tank_traps()
{
	switch (type)
	{
	default:
		return compound_walls & COMPOUND_TANKTRAPS;
	case SITE_OUTDOOR_BUNKER:
	case SITE_RESIDENTIAL_BOMBSHELTER:
		return true;
	}
}
bool Location::can_have_businessfront()
{
	if (!upgradable) return false;
	switch (type)
	{
	default:
		return !has_business_front();
	case SITE_BUSINESS_BARANDGRILL:
	case SITE_OUTDOOR_BUNKER:
	case SITE_RESIDENTIAL_BOMBSHELTER:
		return false;
	}
}
bool Location::has_business_front()
{
	return front_business != -1 ||
		type == SITE_BUSINESS_BARANDGRILL;
}
bool Location::bomb_resistant()
{
	return type == SITE_RESIDENTIAL_BOMBSHELTER;
}
bool Location::part_of_justice_system()
{
	return type == SITE_GOVERNMENT_POLICESTATION ||
		type == SITE_GOVERNMENT_COURTHOUSE ||
		type == SITE_GOVERNMENT_PRISON;
}

void Location::rename(const char* name_, const char* shortname_)
{
	strcpy(this->name, name_);
	strcpy(this->shortname, shortname_);
}
 shortAndTwoStrings getSiteName;
/* daily - seeds and names a site (will re-seed and rename if used after start) */
void initlocation(Location &loc)
{  // NOTE: make sure to keep code here matching code in updateworld_laws() in monthly.cpp for when names are changed
	loc.init();
	char str[80];
	switch (loc.type)
	{
	case SITE_CITY_SEATTLE:
	case SITE_CITY_LOS_ANGELES:
	case SITE_CITY_NEW_YORK:
	case SITE_CITY_CHICAGO:
	case SITE_CITY_DETROIT:
	case SITE_CITY_ATLANTA:
	case SITE_CITY_MIAMI:
	case SITE_CITY_WASHINGTON_DC:
	case SITE_DOWNTOWN:
	case SITE_UDISTRICT:
	case SITE_COMMERCIAL:
	case SITE_INDUSTRIAL:
	case SITE_OUTOFTOWN:
	case SITE_TRAVEL:
		loc.rename(getSiteName[loc.type][0].data(), getSiteName[loc.type][1].data());
		break;
	case SITE_GOVERNMENT_POLICESTATION:
		if (lawList[LAW_POLICEBEHAVIOR] == -2 && lawList[LAW_DEATHPENALTY] == -2) {
			loc.rename("Death Squad HQ", "Death Squad HQ");
		}
		else {
			loc.rename("Police Station", "Police Station");
		} break;
	case SITE_GOVERNMENT_COURTHOUSE:
		if (lawList[LAW_DEATHPENALTY] == -2) {
			loc.rename("Halls of Ultimate Judgment", "Judge Hall");
		}
		else {
			loc.rename("Courthouse", "Courthouse");
		} break;
	case SITE_GOVERNMENT_FIRESTATION:
		if (lawList[LAW_FREESPEECH] == -2) {
			loc.rename("Fireman HQ", "Fireman HQ");
			loc.hidden = false;
		}
		else {
			loc.rename("Fire Station", "Fire Station");
			loc.hidden = true;
		} break;
	case SITE_GOVERNMENT_PRISON:
		if (lawList[LAW_PRISONS] == -2)
		{
			strcpy(loc.name, pickrandom(labor_camp_name).data());
			strcat(loc.name, singleSpace.data());
			strcat(loc.name, pickrandom(labor_camp_name_2).data());
			strcat(loc.name, " Forced Labor Camp");
			strcpy(loc.shortname, "Joycamp");
		}
		else
		{
			strcpy(loc.name, lastname(true).data());
			strcat(loc.name, " Prison");
			strcpy(loc.shortname, "Prison");
		}
		break;
	case SITE_INDUSTRY_NUCLEAR:
		if (lawList[LAW_NUCLEARPOWER] == 2) {
			loc.rename("Nuclear Waste Center", "NWaste Center");
		}
		else {
			loc.rename("Nuclear Power Plant", "NPower Plant");
		} break;
	case SITE_GOVERNMENT_INTELLIGENCEHQ:
		if (lawList[LAW_PRIVACY] == -2 && lawList[LAW_POLICEBEHAVIOR] == -2) {
			loc.rename("Ministry of Love", "Miniluv");
		}
		else {
			loc.rename("Intelligence HQ", "Int. HQ");
		} break;
	case SITE_GOVERNMENT_ARMYBASE:
		if (lawList[LAW_MILITARY] == -2) {
			loc.rename("Ministry of Peace", "Minipax");
		}
		else {
			strcpy(loc.name, lastname(true).data());
			strcat(loc.name, " Army Base");
			strcpy(loc.shortname, "Army Base");
		} break;
	case SITE_GOVERNMENT_WHITE_HOUSE:
		loc.rename("White House", "White House");
		break;
	case SITE_CORPORATE_HEADQUARTERS:
		loc.rename("Corporate HQ", "Corp. HQ");
		break;
	case SITE_BUSINESS_BANK:
		loc.rename("American Bank Corp", "Bank");
		break;
	case SITE_BUSINESS_PAWNSHOP:
		strcpy(loc.name, lastname(true).data());
		if (lawList[LAW_GUNCONTROL] == ALIGN_ELITELIBERAL)
			strcat(loc.name, "'s Pawnshop");
		else
			strcat(loc.name, " Pawn & Gun");
		strcpy(loc.shortname, "Pawnshop");
		break;
	case SITE_CORPORATE_HOUSE:
		if (lawList[LAW_CORPORATE] == -2 && lawList[LAW_TAX] == -2)
			loc.rename("CEO Castle", "CEO Castle");
		else
			loc.rename("CEO Residence", "CEO House");
		break;
	case SITE_RESIDENTIAL_SHELTER:
		loc.rename("Homeless Shelter", "Shelter");
		break;
	case SITE_INDUSTRY_WAREHOUSE:
		do {
			strcpy(loc.name, "Abandoned ");
			/*lastname(loc.name,true);
			strcat(loc.name,singleSpace);*/
			switch (LCSrandom(10))
			{
			case 0:
				strcat(loc.name, "Meat Plant");
				strcpy(loc.shortname, "Meat Plant");
				break;
			case 1:
				strcat(loc.name, "Warehouse");
				strcpy(loc.shortname, "Warehouse");
				break;
			case 2:
				strcat(loc.name, "Paper Mill");
				strcpy(loc.shortname, "Paper Mill");
				break;
			case 3:
				strcat(loc.name, "Cement Factory");
				strcpy(loc.shortname, "Cement");
				break;
			case 4:
				strcat(loc.name, "Fertilizer Plant");
				strcpy(loc.shortname, "Fertilizer");
				break;
			case 5:
				strcat(loc.name, "Drill Factory");
				strcpy(loc.shortname, "Drill");
				break;
			case 6:
				strcat(loc.name, "Steel Plant");
				strcpy(loc.shortname, "Steel");
				break;
			case 7:
				strcat(loc.name, "Packing Plant");
				strcpy(loc.shortname, "Packing");
				break;
			case 8:
				strcat(loc.name, "Toy Factory");
				strcpy(loc.shortname, "Toy");
				break;
			case 9:
				strcat(loc.name, "Building Site");
				strcpy(loc.shortname, "Building");
				break;
			}
		} while (loc.duplicatelocation());
		break;
	case SITE_INDUSTRY_POLLUTER:
		switch (LCSrandom(5))
		{
		case 0:
			loc.rename("Aluminum Factory", "Alum Fact");
			break;
		case 1:
			loc.rename("Plastic Factory", "Plast Fact");
			break;
		case 2:
			loc.rename("Oil Refinery", "Refinery");
			break;
		case 3:
			loc.rename("Auto Plant", "Auto Plant");
			break;
		case 4:
			loc.rename("Chemical Factory", "Chem Fact");
			break;
		}
		break;
	case SITE_MEDIA_CABLENEWS:
		loc.rename("Cable News Station", "News Station");
		break;
	case SITE_MEDIA_AMRADIO:
		loc.rename("AM Radio Station", "Radio Station");
		break;
	case SITE_RESIDENTIAL_APARTMENT_UPSCALE:
		do {
			strcpy(loc.name, lastname(true).data());
			strcpy(loc.shortname, loc.name);
			strcat(loc.name, " Condominiums");
			strcat(loc.shortname, " Condos");
		} while (loc.duplicatelocation());
		break;
	case SITE_RESIDENTIAL_APARTMENT:
		do {
			strcpy(loc.name, lastname(true).data());
			strcpy(loc.shortname, loc.name);
			strcat(loc.name, " Apartments");
			strcat(loc.shortname, " Apts");
		} while (loc.duplicatelocation());
		break;
	case SITE_RESIDENTIAL_TENEMENT:
		do {
			do {
				strcpy(loc.name, lastname(true).data());
			} while (len(loc.name) > 7);
			strcat(loc.name, " St. Housing Projects");
			strcpy(loc.shortname, "Projects");
		} while (loc.duplicatelocation());
		break;
	case SITE_HOSPITAL_UNIVERSITY:
		loc.rename("The University Hospital", "U Hospital");
		break;
	case SITE_HOSPITAL_CLINIC:
		loc.rename("The Free Clinic", "Clinic");
		break;
	case SITE_LABORATORY_GENETIC:
		strcpy(loc.name, lastname(true).data());
		strcat(loc.name, " Genetics");
		strcpy(loc.shortname, "Genetics Lab");
		break;
	case SITE_LABORATORY_COSMETICS:
		strcpy(loc.name, lastname(true).data());
		strcat(loc.name, " Cosmetics");
		strcpy(loc.shortname, "Cosmetics Lab");
		break;
	case SITE_BUSINESS_CARDEALERSHIP:
		generate_name(loc.name, GENDER_WHITEMALEPATRIARCH);
		strcat(loc.name, "'s Used Cars");
		strcpy(loc.shortname, "Used Cars");
		break;
	case SITE_BUSINESS_DEPTSTORE:
		strcpy(loc.name, lastname(true).data());
		strcat(loc.name, "'s Department Store");
		strcpy(loc.shortname, "Dept. Store");
		break;
	case SITE_BUSINESS_HALLOWEEN:
		loc.rename("The Oubliette", "Oubliette");
		break;
	case SITE_INDUSTRY_SWEATSHOP:
		strcpy(loc.name, lastname(true).data());
		strcat(loc.name, " Garment Makers");
		strcpy(loc.shortname, "Sweatshop");
		break;
	case SITE_BUSINESS_CRACKHOUSE:
		do {
			strcpy(loc.name, lastname(true).data());
			strcat(loc.name, " St. ");
			if (lawList[LAW_DRUGS] == 2)
			{
				switch (LCSrandom(4))
				{
					//TODO IsaacG Migrate Strings
				case 0:
					strcat(loc.name, "Recreational Drugs Center");
					strcpy(loc.shortname, "Drugs Center");
					break;
				case 1:
					strcat(loc.name, "Coffee House");
					strcpy(loc.shortname, "Coffee House");
					break;
				case 2:
					strcat(loc.name, "Cannabis Lounge");
					strcpy(loc.shortname, "Cannabis Lounge");
					break;
				case 3:
					strcat(loc.name, "Marijuana Dispensary");
					strcpy(loc.shortname, "Dispensary");
					break;
				}
			}
			else
			{
				strcat(loc.name, "Crack House");
				strcpy(loc.shortname, "Crack House");
			}
		} while (loc.duplicatelocation());
		break; case SITE_BUSINESS_JUICEBAR:
			strcpy(loc.name, "");
			strcat(loc.name, pickrandom(juice_name).data());
			strcat(loc.name, singleSpace.data());
			strcat(loc.name, pickrandom(juice_name_2).data());
			strcat(loc.name, " Juice Bar");
			strcpy(loc.shortname, "Juice Bar");
			break;
		case SITE_BUSINESS_VEGANCOOP:
			strcpy(loc.name, "");
			strcat(loc.name, pickrandom(vegan_name).data());
			strcat(loc.name, singleSpace.data());
			strcat(loc.name, pickrandom(vegan_name_2).data());
			strcat(loc.name, " Vegan Co-op");
			strcpy(loc.shortname, "Vegan Co-op");
			break;
		case SITE_BUSINESS_INTERNETCAFE:
			strcpy(loc.name, "");
			strcat(loc.name, pickrandom(cafe_name).data());
			strcat(loc.name, singleSpace.data());
			strcat(loc.name, pickrandom(cafe_name_2).data());
			strcat(loc.name, " Internet Cafe");
			strcpy(loc.shortname, "Net Cafe");
			break;
		case SITE_BUSINESS_CIGARBAR:
			strcpy(loc.name, lastname(true).data());
			strcpy(loc.name, "The ");
			strcat(loc.name, str);
			strcat(loc.name, " Gentlemen's Club");
			strcpy(loc.shortname, "Cigar Bar");
			break;
		case SITE_BUSINESS_LATTESTAND:
			strcpy(loc.name, "");
			strcat(loc.name, pickrandom(latte_name).data());
			strcat(loc.name, singleSpace.data());
			strcat(loc.name, pickrandom(latte_name_2).data());
			strcat(loc.name, " Latte Stand");
			strcpy(loc.shortname, "Latte Stand");
			break;
		case SITE_OUTDOOR_PUBLICPARK:
			strcpy(loc.name, lastname(true).data());
			strcat(loc.name, " Park");
			strcpy(loc.shortname, "Park");
			break;
		case SITE_RESIDENTIAL_BOMBSHELTER:
			loc.rename("Fallout Shelter", "Bomb Shelter");
			break;
		case SITE_BUSINESS_BARANDGRILL:
			loc.rename("Desert Eagle Bar & Grill", "Bar & Grill");
			break;
		case SITE_OUTDOOR_BUNKER:
			loc.rename("Robert E. Lee Bunker", "Bunker");
			break;
		case SITE_BUSINESS_ARMSDEALER:
			loc.rename("Black Market", "Black Market");
			break;
	}
}
