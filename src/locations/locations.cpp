#define	LOCATIONS_CPP
#include "../includes.h"
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
 map<short, string> getCityDescription;
 string Location::city_description()
 {
	 if (getCityDescription.count(type)) {
		 return getCityDescription[type];
	 }
	 else {
		 return blankString;
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
 void Location::rename(const string name_, const string shortname_)
 {
	 strcpy(this->name, name_.data());
	 strcpy(this->shortname, shortname_.data());
 }
 void renameWarehouse(Location &loc) {
	 do {
		 strcpy(loc.name, CONST_locations041);
		 /*lastname(loc.name,true);
		 strcat(loc.name,singleSpace);*/
		 switch (LCSrandom(10))
		 {
		 case 0:
			 strcat(loc.name, CONST_locations043);
			 strcpy(loc.shortname, CONST_locations043);
			 break;
		 case 1:
			 strcat(loc.name, CONST_locations045);
			 strcpy(loc.shortname, CONST_locations045);
			 break;
		 case 2:
			 strcat(loc.name, CONST_locations047);
			 strcpy(loc.shortname, CONST_locations047);
			 break;
		 case 3:
			 strcat(loc.name, CONST_locations048);
			 strcpy(loc.shortname, CONST_locations049);
			 break;
		 case 4:
			 strcat(loc.name, CONST_locations050);
			 strcpy(loc.shortname, CONST_locations051);
			 break;
		 case 5:
			 strcat(loc.name, CONST_locations052);
			 strcpy(loc.shortname, CONST_locations053);
			 break;
		 case 6:
			 strcat(loc.name, CONST_locations054);
			 strcpy(loc.shortname, CONST_locations055);
			 break;
		 case 7:
			 strcat(loc.name, CONST_locations056);
			 strcpy(loc.shortname, CONST_locations057);
			 break;
		 case 8:
			 strcat(loc.name, CONST_locations058);
			 strcpy(loc.shortname, CONST_locations059);
			 break;
		 case 9:
			 strcat(loc.name, CONST_locations060);
			 strcpy(loc.shortname, CONST_locations061);
			 break;
		 }
	 } while (loc.duplicatelocation());
 }
 void renamePrison(Location &loc) {
	 if (lawList[LAW_PRISONS] == -2)
	 {
		 strcpy(loc.name, pickrandom(labor_camp_name));
		 strcat(loc.name, singleSpace);
		 strcat(loc.name, pickrandom(labor_camp_name_2));
		 strcat(loc.name, CONST_locations021);
		 strcpy(loc.shortname, CONST_locations022);
	 }
	 else
	 {
		 strcpy(loc.name, lastname(true));
		 strcat(loc.name, CONST_locations023);
		 strcpy(loc.shortname, CONST_locations024);
	 }
 }
 void renamePoluter(Location &loc) {
	 switch (LCSrandom(5))
	 {
	 case 0:
		 loc.rename(CONST_locations062, CONST_locationsB119);
		 break;
	 case 1:
		 loc.rename(CONST_locations063, CONST_locationsB120);
		 break;
	 case 2:
		 loc.rename(CONST_locations064, CONST_locationsB121);
		 break;
	 case 3:
		 loc.rename(CONST_locations065, CONST_locations065);
		 break;
	 case 4:
		 loc.rename(CONST_locations066, CONST_locationsB122);
		 break;
	 }
 }
 void renamePoliceStation(Location &loc) {
	 if (lawList[LAW_POLICEBEHAVIOR] == -2 && lawList[LAW_DEATHPENALTY] == -2) {
		 loc.rename(CONST_locations015, CONST_locations015);
	 }
	 else {
		 loc.rename(CONST_locations016, CONST_locations016);
	 }
 }
 void renameCourthouse(Location &loc) {
	 if (lawList[LAW_DEATHPENALTY] == -2) {
		 loc.rename(CONST_locations017, CONST_locationsB109);
	 }
	 else {
		 loc.rename(CONST_locations018, CONST_locations018);
	 }
 }
 void renameFireStation(Location &loc) {

	 if (lawList[LAW_FREESPEECH] == -2) {
		 loc.rename(CONST_locations019, CONST_locations019);
		 loc.hidden = false;
	 }
	 else {
		 loc.rename(CONST_locations020, CONST_locations020);
		 loc.hidden = true;
	 }
 }
 void renameNuclear(Location &loc) {
	 if (lawList[LAW_NUCLEARPOWER] == 2) {
		 loc.rename(CONST_locations025, CONST_locationsB110);
	 }
	 else {
		 loc.rename(CONST_locations026, CONST_locationsB111);
	 }
 }
 void renameIntelligenceHQ(Location &loc) {

	 if (lawList[LAW_PRIVACY] == -2 && lawList[LAW_POLICEBEHAVIOR] == -2) {
		 loc.rename(CONST_locations027, CONST_locationsB112);
	 }
	 else {
		 loc.rename(CONST_locations028, CONST_locationsB113);
	 }
 }
 void renameArmyBase(Location &loc) {
	 if (lawList[LAW_MILITARY] == -2) {
		 loc.rename(CONST_locations029, CONST_locationsB114);
	 }
	 else {
		 strcpy(loc.name, lastname(true));
		 strcat(loc.name, CONST_locations030);
		 strcpy(loc.shortname, CONST_locations031);
	 }
 }
 void renamePawnShop(Location &loc) {

	 strcpy(loc.name, lastname(true));
	 if (lawList[LAW_GUNCONTROL] == ALIGN_ELITELIBERAL)
		 strcat(loc.name, CONST_locations035);
	 else
		 strcat(loc.name, CONST_locations036);
	 strcpy(loc.shortname, CONST_locations037);
 }
 void renameCorporateHouse(Location &loc) {

	 if (lawList[LAW_CORPORATE] == -2 && lawList[LAW_TAX] == -2)
		 loc.rename(CONST_locations038, CONST_locations038);
	 else
		 loc.rename(CONST_locations039, CONST_locationsB117);
 }

 void renameCrackhouse(Location &loc) {
	 do {
		 strcpy(loc.name, lastname(true));
		 strcat(loc.name, CONST_locations088);
		 if (lawList[LAW_DRUGS] == 2)
		 {
			 switch (LCSrandom(4))
			 {
				 //TODO IsaacG Migrate Strings
			 case 0:
				 strcat(loc.name, CONST_locations089);
				 strcpy(loc.shortname, CONST_locations090);
				 break;
			 case 1:
				 strcat(loc.name, CONST_locations092);
				 strcpy(loc.shortname, CONST_locations092);
				 break;
			 case 2:
				 strcat(loc.name, CONST_locations094);
				 strcpy(loc.shortname, CONST_locations094);
				 break;
			 case 3:
				 strcat(loc.name, CONST_locations095);
				 strcpy(loc.shortname, CONST_locations096);
				 break;
			 }
		 }
		 else
		 {
			 strcat(loc.name, CONST_locations098);
			 strcpy(loc.shortname, CONST_locations098);
		 }
	 } while (loc.duplicatelocation());
 }

 void renameApartment(Location &loc) {

	 do {
		 strcpy(loc.name, lastname(true));
		 strcpy(loc.shortname, loc.name);
		 strcat(loc.name, CONST_locations071);
		 strcat(loc.shortname, CONST_locations072);
	 } while (loc.duplicatelocation());

 }

 void renameUpscaleApt(Location &loc) {

	 do {
		 strcpy(loc.name, lastname(true));
		 strcpy(loc.shortname, loc.name);
		 strcat(loc.name, CONST_locations069);
		 strcat(loc.shortname, CONST_locations070);
	 } while (loc.duplicatelocation());

 }

 void renameTenet(Location &loc) {

	 do {
		 do {
			 strcpy(loc.name, lastname(true));
		 } while (len(loc.name) > 7);
		 strcat(loc.name, CONST_locations073);
		 strcpy(loc.shortname, CONST_locations074);
	 } while (loc.duplicatelocation());

 }
 void returnToDefaultName(Location &loc) {
	 switch (loc.type)
	 {
	 case SITE_GOVERNMENT_WHITE_HOUSE:
		 loc.rename(CONST_locations032, CONST_locations032);
		 break;
	 case SITE_CORPORATE_HEADQUARTERS:
		 loc.rename(CONST_locations033, CONST_locationsB115);
		 break;
	 case SITE_BUSINESS_BANK:
		 loc.rename(CONST_locations034, CONST_locationsB116);
		 break;
	 case SITE_RESIDENTIAL_SHELTER:
		 loc.rename(CONST_locations040, CONST_locationsB118);
		 break;
	 case SITE_MEDIA_CABLENEWS:
		 loc.rename(CONST_locations067, CONST_locationsB123);
		 break;
	 case SITE_MEDIA_AMRADIO:
		 loc.rename(CONST_locations068, CONST_locationsB124);
		 break;
	 case SITE_HOSPITAL_UNIVERSITY:
		 loc.rename(CONST_locations075, CONST_locationsB125);
		 break;
	 case SITE_HOSPITAL_CLINIC:
		 loc.rename(CONST_locations076, CONST_locationsB126);
		 break;
	 case SITE_RESIDENTIAL_BOMBSHELTER:
		 loc.rename(CONST_locations111, CONST_locationsB128);
		 break;
	 case SITE_BUSINESS_BARANDGRILL:
		 loc.rename(CONST_locations112, CONST_locationsB129);
		 break;
	 case SITE_OUTDOOR_BUNKER:
		 loc.rename(CONST_locations113, CONST_locationsB130);
		 break;
	 case SITE_BUSINESS_ARMSDEALER:
		 loc.rename(CONST_locations114, CONST_locations114);
		 break;
	 case SITE_BUSINESS_HALLOWEEN:
		 loc.rename(CONST_locations085, CONST_locationsB127);
		 break;
	 }
 }
 void renameSITE_LABORATORY_GENETIC(char* name, char* shortname) {

	 strcpy(name, lastname(true));
	 strcat(name, CONST_locations077);
	 strcpy(shortname, CONST_locations078);
 }
 void renameSITE_LABORATORY_COSMETICS(char* name, char* shortname) {

	 strcpy(name, lastname(true));
	 strcat(name, CONST_locations079);
	 strcpy(shortname, CONST_locations080);
 }
 void renameSITE_BUSINESS_CARDEALERSHIP(char* name, char* shortname) {

	 generate_name(name, GENDER_WHITEMALEPATRIARCH);
	 strcat(name, CONST_locations081);
	 strcpy(shortname, CONST_locations082);
 }
 void renameSITE_BUSINESS_DEPTSTORE(char* name, char* shortname) {

	 strcpy(name, lastname(true));
	 strcat(name, CONST_locations083);
	 strcpy(shortname, CONST_locations084);
 }
 void renameSITE_INDUSTRY_SWEATSHOP(char* name, char* shortname) {

	 strcpy(name, lastname(true));
	 strcat(name, CONST_locations086);
	 strcpy(shortname, CONST_locations087);
 }
 void renameSITE_BUSINESS_JUICEBAR(char* name, char* shortname) {

	 strcpy(name, blankString);
	 strcat(name, pickrandom(juice_name));
	 strcat(name, singleSpace);
	 strcat(name, pickrandom(juice_name_2));
	 strcat(name, CONST_locations099);
	 strcpy(shortname, CONST_locations100);
 }
 void renameSITE_BUSINESS_VEGANCOOP(char* name, char* shortname) {

	 strcpy(name, blankString);
	 strcat(name, pickrandom(vegan_name));
	 strcat(name, singleSpace);
	 strcat(name, pickrandom(vegan_name_2));
	 strcat(name, CONST_locations101);
	 strcpy(shortname, CONST_locations102);
 }
 void renameSITE_BUSINESS_INTERNETCAFE(char* name, char* shortname) {

	 strcpy(name, blankString);
	 strcat(name, pickrandom(cafe_name));
	 strcat(name, singleSpace);
	 strcat(name, pickrandom(cafe_name_2));
	 strcat(name, CONST_locations103);
	 strcpy(shortname, CONST_locations104);
 }
 void rename(char* name, char* shortname) {

 }
 void renameSITE_BUSINESS_CIGARBAR(char* name, char* shortname) {

	 strcpy(name, tag_The);
	 strcat(name, lastname(true));
	 strcat(name, CONST_locations105);
	 strcpy(shortname, CONST_locations106);
 }
 void renameSITE_BUSINESS_LATTESTAND(char* name, char* shortname) {

	 strcpy(name, blankString);
	 strcat(name, pickrandom(latte_name));
	 strcat(name, singleSpace);
	 strcat(name, pickrandom(latte_name_2));
	 strcat(name, CONST_locations107);
	 strcpy(shortname, CONST_locations108);
 }
 void renameSITE_OUTDOOR_PUBLICPARK(char* name, char* shortname) {

	 strcpy(name, lastname(true));
	 strcat(name, CONST_locations109);
	 strcpy(shortname, CONST_locations110);
 }
 map<short, vector<string> > getSiteName;
 /* daily - seeds and names a site (will re-seed and rename if used after start) */
 void initlocation(Location &loc)
 {  // NOTE: make sure to keep code here matching code in updateworld_laws() in monthly.cpp for when names are changed
	 loc.init();
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
		 loc.rename(getSiteName[loc.type][0], getSiteName[loc.type][1]);
		 break;
	 case SITE_GOVERNMENT_WHITE_HOUSE:
	 case SITE_CORPORATE_HEADQUARTERS:
	 case SITE_BUSINESS_BANK:
	 case SITE_RESIDENTIAL_SHELTER:
	 case SITE_MEDIA_CABLENEWS:
	 case SITE_MEDIA_AMRADIO:
	 case SITE_HOSPITAL_UNIVERSITY:
	 case SITE_HOSPITAL_CLINIC:
	 case SITE_RESIDENTIAL_BOMBSHELTER:
	 case SITE_BUSINESS_BARANDGRILL:
	 case SITE_OUTDOOR_BUNKER:
	 case SITE_BUSINESS_ARMSDEALER:
	 case SITE_BUSINESS_HALLOWEEN:
		 returnToDefaultName(loc);
		 break;
	 case SITE_GOVERNMENT_POLICESTATION:
		 renamePoliceStation(loc);
		 break;
	 case SITE_GOVERNMENT_COURTHOUSE:
		 renameCourthouse(loc);
		 break;
	 case SITE_GOVERNMENT_FIRESTATION:
		 renameFireStation(loc);
		 break;
	 case SITE_GOVERNMENT_PRISON:
		 renamePrison(loc);
		 break;
	 case SITE_INDUSTRY_NUCLEAR:
		 renameNuclear(loc);
		 break;
	 case SITE_GOVERNMENT_INTELLIGENCEHQ:
		 renameIntelligenceHQ(loc);
		 break;
	 case SITE_GOVERNMENT_ARMYBASE:
		 renameArmyBase(loc);
		 break;
	 case SITE_BUSINESS_PAWNSHOP:
		 renamePawnShop(loc);
		 break;
	 case SITE_CORPORATE_HOUSE:
		 renameCorporateHouse(loc);
		 break;
	 case SITE_INDUSTRY_WAREHOUSE:
		 renameWarehouse(loc);
		 break;
	 case SITE_INDUSTRY_POLLUTER:
		 renamePoluter(loc);
		 break;
	 case SITE_RESIDENTIAL_APARTMENT_UPSCALE:
		 renameUpscaleApt(loc);
		 break;
	 case SITE_RESIDENTIAL_APARTMENT:
		 renameApartment(loc);
		 break;
	 case SITE_RESIDENTIAL_TENEMENT:
		 renameTenet(loc);
		 break;
	 case SITE_BUSINESS_CRACKHOUSE:
		 renameCrackhouse(loc);
		 break;
	 case SITE_LABORATORY_GENETIC:
		 renameSITE_LABORATORY_GENETIC(loc.name, loc.shortname);
		 break;
	 case SITE_LABORATORY_COSMETICS:
		 renameSITE_LABORATORY_COSMETICS(loc.name, loc.shortname);
		 break;
	 case SITE_BUSINESS_CARDEALERSHIP:
		 renameSITE_BUSINESS_CARDEALERSHIP(loc.name, loc.shortname);
		 break;
	 case SITE_BUSINESS_DEPTSTORE:
		 renameSITE_BUSINESS_DEPTSTORE(loc.name, loc.shortname);
		 break;
	 case SITE_INDUSTRY_SWEATSHOP:
		 renameSITE_INDUSTRY_SWEATSHOP(loc.name, loc.shortname);
		 break;
	 case SITE_BUSINESS_JUICEBAR:
		 renameSITE_BUSINESS_JUICEBAR(loc.name, loc.shortname);
		 break;
	 case SITE_BUSINESS_VEGANCOOP:
		 renameSITE_BUSINESS_VEGANCOOP(loc.name, loc.shortname);
		 break;
	 case SITE_BUSINESS_INTERNETCAFE:
		 renameSITE_BUSINESS_INTERNETCAFE(loc.name, loc.shortname);
		 break;
	 case SITE_BUSINESS_CIGARBAR:
		 renameSITE_BUSINESS_CIGARBAR(loc.name, loc.shortname);
		 break;
	 case SITE_BUSINESS_LATTESTAND:
		 renameSITE_BUSINESS_LATTESTAND(loc.name, loc.shortname);
		 break;
	 case SITE_OUTDOOR_PUBLICPARK:
		 renameSITE_OUTDOOR_PUBLICPARK(loc.name, loc.shortname);
		 break;
	 }
 }
 