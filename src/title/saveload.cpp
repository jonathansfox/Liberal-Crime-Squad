
#include "../includes.h"
const string CONST_saveloadB081 = "# and are thereby ignored";
const string CONST_saveload091 = "rb";
const string CONST_saveload090 = "wb";
const string CONST_saveload089 = ".verbose";
const string CONST_saveload088 = ".";
const string CONST_saveload084 = "# cursquadid";
const string CONST_saveload083 = "# curcreatureid";
const string CONST_saveload082 = "# Vehicle::curcarid";
const string CONST_saveload081 = "# ";
const string CONST_saveload080 = "# Crimes";
const string CONST_saveload079 = "# Next Creature";
const string CONST_saveload076 = "# Skills";
const string CONST_saveload074 = "# Juice";
const string CONST_saveload073 = "# Alignment";
const string CONST_saveload072 = "# Birthday Day";
const string CONST_saveload071 = "# Birthday Month";
const string CONST_saveload070 = "# Age";
const string CONST_saveload069 = "# Gender (Liberal)";
const string CONST_saveload068 = "# Gender (Conservative)";
const string CONST_saveload067 = "# Proper Name";
const string CONST_saveload066 = "# Name";
const string CONST_saveload064 = "# oldPresidentName";
const string CONST_saveload063 = "# execname";
const string CONST_saveload062 = "# exec";
const string CONST_saveload061 = "# Supreme Court Names";
const string CONST_saveload060 = "# Supreme Court";
const string CONST_saveload059 = "# Senate";
const string CONST_saveload058 = "# House";
const string CONST_saveload056 = "# Law List";
const string CONST_saveload055 = "# Concerning ";
const string CONST_saveload054 = "# Attitude";
const string CONST_saveload053 = "# Party Status";
const string CONST_saveload052 = "# Slogan";
const string CONST_saveload051 = "# Liberal Guardian Published";
const string CONST_saveload050 = "# L City Name";
const string CONST_saveload049 = "# attorneyseed";
const string CONST_saveload048 = "# Offended Firemen";
const string CONST_saveload047 = "# Offended Cablenews";
const string CONST_saveload046 = "# Offended Amradio";
const string CONST_saveload045 = "# Offended CIA";
const string CONST_saveload044 = "# Offended Corps";
const string CONST_saveload043 = "# Police Heat";
const string CONST_saveload042 = "# ccs_kills";
const string CONST_saveload041 = "# ccsexposure";
const string CONST_saveload040 = "# endgamestate";
const string CONST_saveload039 = "# stat_burns";
const string CONST_saveload038 = "# stat_buys";
const string CONST_saveload037 = "# stat_kidnappings";
const string CONST_saveload036 = "# stat_kills";
const string CONST_saveload035 = "# stat_dead";
const string CONST_saveload034 = "# stat_recruits";
const string CONST_saveload033 = "# stalinmode";
const string CONST_saveload032 = "# nocourtpurge";
const string CONST_saveload031 = "# notermlimit";
const string CONST_saveload030 = "# m249";
const string CONST_saveload029 = "# deagle";
const string CONST_saveload028 = "# termlimits";
const string CONST_saveload027 = "# multipleCityMode";
const string CONST_saveload026 = "# amendnum";
const string CONST_saveload025 = "# presparty";
const string CONST_saveload024 = "# execterm";
const string CONST_saveload023 = "# year";
const string CONST_saveload022 = "# month";
const string CONST_saveload021 = "# day";
const string CONST_saveload020 = "# fieldskillrate";
const string CONST_saveload019 = "# wincondition";
const string CONST_saveload018 = "# mode";
const string CONST_saveload017 = "# seed";
const string CONST_saveload016 = "# LCS Funding level (max value 2147483647) can be negative";
const string CONST_saveload015 = "# NOVERBOSECOMMENTS to remove them (almost) entirely";
const string CONST_saveload014 = "# If these comments are more trouble than they're worth, add to the debug_defines.txt file";
const string CONST_saveload013 = "# There will be quite a few comments generated automatically";
const string CONST_saveload012 = "# Since the purpose of verbose savefiles is to make them human readable and editable,";
const string CONST_saveload011 = "# All lines beginning with # are comments";
const string CONST_saveload010 = "# remove NOVERBOSECOMMENTS to activate autocomments";
const string CONST_saveload009 = "# Autocomments disabled";
const string CONST_saveload008 = "Verbose File Could Not Be Opened";
const string CONST_saveload004 = "export";
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

const string blankString = "";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
#include "../creature/creature.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../common/equipment.h"
//for void consolidateloot(vector<Item *> &loot);
#include "../common/translateid.h"
// for  getloottype
#include "titlescreen.h"
#include "../cursesAlternative.h"
#include "../common/creaturePool.h"
string itemType;
string doesNotExistItem;
string vehicleType;
string doesNotExistVehicle;
string couldNotLoad;
Item* create_item(const std::string& inputXml);
extern vector<Creature *> pool;
extern Log gamelog;
extern char newscherrybusted;
extern vector<Location *> location;
extern bool multipleCityMode;
extern int stat_buys;
extern int stat_burns;
extern short presparty;
#include "../common/musicClass.h"
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
extern char homedir[MAX_PATH_SIZE];
// TODO: It would be really cool to be able to CONST_saveload004 characters.
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
void writeVerbose(string filename) {
	string filepath = homedir;
	int position = filename.find(CONST_saveload088);
	filename.erase(position);
	filename += CONST_saveload089;
	filepath.append(filename);
	//FILE *h;
	//h = LCSOpenFile((filename).c_str(), CONST_saveload090, LCSIO_PRE_HOME);
	//LCSCloseFile(h);
	ofstream outClientFile(filename, ios::out);
	if (!outClientFile) {
		cerr << CONST_saveload008 << endl;
	}
	else {
		if (NOVERBOSECOMMENTS) {
			outClientFile << CONST_saveload009 << endl;
			outClientFile << CONST_saveload010 << endl;
		}
		else {
			outClientFile << CONST_saveload011 << endl << CONST_saveloadB081 << endl;
			outClientFile << CONST_saveload012 << endl;
			outClientFile << CONST_saveload013 << endl;
			outClientFile << CONST_saveload014 << endl;
			outClientFile << CONST_saveload015 << endl;
			outClientFile << CONST_saveload016 << endl;
		}
		outClientFile << ledger.get_funds() << endl;
		/*
		outClientFile << CONST_saveload017 << endl;
		outClientFile <<  seed[0] << endl;
		outClientFile <<  seed[1] << endl;
		outClientFile <<  seed[2] << endl;
		outClientFile <<  seed[3] << endl;
		outClientFile << CONST_saveload018 << endl;
		outClientFile <<  mode << endl;
		outClientFile << CONST_saveload019 << endl;
		outClientFile <<  wincondition << endl;
		outClientFile << CONST_saveload020 << endl;
		outClientFile <<  fieldskillrate << endl;
		*/
		outClientFile << CONST_saveload021 << endl;
		outClientFile << day << endl;
		outClientFile << CONST_saveload022 << endl;
		outClientFile << month << endl;
		outClientFile << CONST_saveload023 << endl;
		outClientFile << year << endl;
		outClientFile << CONST_saveload024 << endl;
		outClientFile << execterm << endl;
		outClientFile << CONST_saveload025 << endl;
		outClientFile << presparty << endl;
		outClientFile << CONST_saveload026 << endl;
		outClientFile << amendnum << endl;
		outClientFile << CONST_saveload027 << endl;
		outClientFile << multipleCityMode << endl;
		outClientFile << CONST_saveload028 << endl;
		outClientFile << termlimits << endl;
		outClientFile << CONST_saveload029 << endl;
		outClientFile << deagle << endl;
		outClientFile << CONST_saveload030 << endl;
		outClientFile << m249 << endl;
		outClientFile << CONST_saveload031 << endl;
		outClientFile << notermlimit << endl;
		outClientFile << CONST_saveload032 << endl;
		outClientFile << nocourtpurge << endl;
		outClientFile << CONST_saveload033 << endl;
		outClientFile << stalinmode << endl;
		outClientFile << CONST_saveload034 << endl;
		outClientFile << stat_recruits << endl;
		outClientFile << CONST_saveload035 << endl;
		outClientFile << stat_dead << endl;
		outClientFile << CONST_saveload036 << endl;
		outClientFile << stat_kills << endl;
		outClientFile << CONST_saveload037 << endl;
		outClientFile << stat_kidnappings << endl;
		outClientFile << CONST_saveload038 << endl;
		outClientFile << stat_buys << endl;
		outClientFile << CONST_saveload039 << endl;
		outClientFile << stat_burns << endl;
		/*
		outClientFile << CONST_saveload040 << endl;
		outClientFile <<  endgamestate << endl;
		outClientFile << CONST_saveload041 << endl;
		outClientFile <<  ccsexposure << endl;
		outClientFile << CONST_saveload042 << endl;
		outClientFile <<  ccs_kills << endl;
		*/
		outClientFile << CONST_saveload043 << endl;
		outClientFile << police_heat << endl;
		outClientFile << CONST_saveload044 << endl;
		outClientFile << offended_corps << endl;
		outClientFile << CONST_saveload045 << endl;
		outClientFile << offended_cia << endl;
		outClientFile << CONST_saveload046 << endl;
		outClientFile << offended_amradio << endl;
		outClientFile << CONST_saveload047 << endl;
		outClientFile << offended_cablenews << endl;
		outClientFile << CONST_saveload048 << endl;
		outClientFile << offended_firemen << endl;
		/*
		outClientFile << CONST_saveload049 << endl;
		outClientFile <<  attorneyseed[0] << endl;
		outClientFile <<  attorneyseed[1] << endl;
		outClientFile <<  attorneyseed[2] << endl;
		outClientFile <<  attorneyseed[3] << endl;
		*/
		outClientFile << CONST_saveload050 << endl;
		outClientFile << lcityname << endl;
		/*
		outClientFile << CONST_saveload051 << endl;
		outClientFile <<  newscherrybusted << endl;
		*/
		outClientFile << CONST_saveload052 << endl;
		outClientFile << slogan << endl;
		outClientFile << CONST_saveload053 << endl;
		outClientFile << party_status << endl;
		outClientFile << CONST_saveload054 << endl;
		for (int i = 0; i < len(attitude); i++) {
			//outClientFile << CONST_saveload055 + getview(i, false) << endl;
			outClientFile << attitude[i] << endl;
		}
		extern map<short, string> getLawString;
		outClientFile << CONST_saveload056 << endl;
		for (int i = 0; i < len(lawList); i++) {
			if (!NOVERBOSECOMMENTS)
				outClientFile << CONST_saveload081 + getLawString[i] << endl;
			outClientFile << lawList[i] << endl;
		}
		outClientFile << CONST_saveload058 << endl;
		for (int i = 0; i < len(house); i++) {
			outClientFile << house[i] << endl;
		}
		outClientFile << CONST_saveload059 << endl;
		for (int i = 0; i < len(senate); i++) {
			outClientFile << senate[i] << endl;
		}
		outClientFile << CONST_saveload060 << endl;
		for (int i = 0; i < len(court); i++) {
			outClientFile << court[i] << endl;
		}
		outClientFile << CONST_saveload061 << endl;
		for (int i = 0; i < len(courtname); i++) {
			outClientFile << courtname[i] << endl;
		}
		outClientFile << CONST_saveload062 << endl;
		for (int i = 0; i < len(exec); i++) {
			outClientFile << exec[i] << endl;
		}
		outClientFile << CONST_saveload063 << endl;
		for (int i = 0; i < len(execname); i++) {
			outClientFile << execname[i] << endl;
		}
		/*
		outClientFile << CONST_saveload064 << endl;
		outClientFile << oldPresidentName << endl;
		*/
		for (int pl = 0; pl < CreaturePool::getInstance().lenpool(); pl++)
		{
			outClientFile << CONST_saveload079 << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << CONST_saveload066 << endl;
			outClientFile << pool[pl]->name << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << CONST_saveload067 << endl;
			outClientFile << pool[pl]->propername << endl;
			/*
			if (!NOVERBOSECOMMENTS)
			outClientFile << CONST_saveload068 << endl;
			outClientFile <<  pool[pl]->gender_conservative << endl;
			if (!NOVERBOSECOMMENTS)
			outClientFile << CONST_saveload069 << endl;
			outClientFile <<  pool[pl]->gender_liberal << endl;
			*/
			if (!NOVERBOSECOMMENTS)
				outClientFile << CONST_saveload070 << endl;
			outClientFile << pool[pl]->age << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << CONST_saveload071 << endl;
			outClientFile << pool[pl]->birthday_month << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << CONST_saveload072 << endl;
			outClientFile << pool[pl]->birthday_day << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << CONST_saveload073 << endl;
			outClientFile << pool[pl]->align << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << CONST_saveload074 << endl;
			outClientFile << pool[pl]->juice << endl;
			for (int i = 0; i < ATTNUM; i++) {
				//if (!NOVERBOSECOMMENTS)
				//outClientFile << CONST_saveload081 + attribute_enum_to_string(i) << endl;
				outClientFile << pool[pl]->get_true_attribute(i) << endl;
			}
			extern map<short, string> skillEnumToString;
			outClientFile << CONST_saveload076 << endl;
			for (int i = 0; i < SKILLNUM; i++) {
				if (!NOVERBOSECOMMENTS)
					outClientFile << CONST_saveload081 + skillEnumToString[i] << endl;
				outClientFile << pool[pl]->get_skill(i) << endl;
			}
			/*
			for (int i = 0; i < AUGMENTATIONNUM; i++) {
			outClientFile <<  pool[pl]->get_augmentation(i) << endl;
			}
			for (int i = 0; i < BODYPARTNUM; i++) {//Bad, relies on their order in the xml file. -XML
			if (!NOVERBOSECOMMENTS)
			outClientFile << CONST_saveload079 << endl;
			outClientFile <<  pool[pl]->wound[i] << endl;
			}
			for (int i = 0; i < SPECIALWOUNDNUM; i++) { //Bad, relies on their order in the xml file. -XML
			if (!NOVERBOSECOMMENTS)
			outClientFile << CONST_saveload079 << endl;
			outClientFile <<  pool[pl]->special[i] << endl;
			}
			*/
			extern map<short, string> getLawFlagString;
			extern map<short, map<short, string> > getLawFlagStringFull;
			outClientFile << CONST_saveload080 << endl;
			for (int i = 0; i < LAWFLAGNUM; i++) {//Bad, relies on their order in the xml file. -XML
												  // 6
												  // 20
				if (!NOVERBOSECOMMENTS)
					outClientFile << CONST_saveload081 << ((i == 6 || i == 20) ? getLawFlagStringFull[i][0] : getLawFlagString[i]) << endl;
				outClientFile << pool[pl]->crimes_suspected[i] << endl;
			}
		}
		/*
		outClientFile << CONST_saveload082 << endl;
		outClientFile << Vehicle::curcarid << endl;
		outClientFile << CONST_saveload083 << endl;
		outClientFile << curcreatureid << endl;
		outClientFile << CONST_saveload084 << endl;
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
	for (int pl = 0; pl < CreaturePool::getInstance().lenpool(); pl++)
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
void readVerbose(string filename) {
	string filepath = homedir;
	int position = filename.find(CONST_saveload088);
	filename.erase(position);
	filename += CONST_saveload089;
	FILE *h;
	h = LCSOpenFile((filename).c_str(), CONST_saveload091.c_str(), LCSIO_PRE_HOME);
	if (h != NULL) {
		LCSCloseFile(h);
		ifstream txtFile;
		char currentLine[2048];
		txtFile.open(filepath + filename);
		vector<string> types;
		while (!txtFile.eof()) {
			txtFile.getline(currentLine, 2048, '\n');
			bool notComment = (currentLine[0] != '#');
			if (notComment) {
				types.push_back(currentLine);
			}
		}
		txtFile.close();
		useData(types);
	}
}
void deleteVerbose(const string& filename) {
	string verboseFilename = filename;
	int position = verboseFilename.find(CONST_saveload088);
	verboseFilename.erase(position);
	verboseFilename += CONST_saveload089;
	LCSDeleteFile(verboseFilename.c_str(), LCSIO_PRE_HOME);
}
void savegame(const string& filename)
{
	if (NOSAVE) {
		return;
	}
	bool dummy_b;
	int dummy;
	FILE *h;
	int l;
	h = LCSOpenFile(filename.c_str(), CONST_saveload090.c_str(), LCSIO_PRE_HOME);
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
		dummy = CreaturePool::getInstance().lenpool();
		fwrite(&dummy, sizeof(int), 1, h);
		for (int pl = 0; pl < CreaturePool::getInstance().lenpool(); pl++)
		{
			std::string creatureStr = pool[pl]->showXml();
			int creatureSize = len(creatureStr);
			fwrite(&creatureSize, sizeof(int), 1, h);
			fwrite(creatureStr.c_str(), creatureSize, 1, h);
			// extra InterrogationST data if applicable
			if (pool[pl]->align == -1 && pool[pl]->alive)
			{
				InterrogationST* &intr = pool[pl]->activity.intr();
				fwrite(intr->techniques, sizeof(bool[6]), 1, h);
				fwrite(&intr->druguse, sizeof(int), 1, h);
				//deep write rapport map
				int size = len(intr->rapport);
				fwrite(&size, sizeof(int), 1, h);
				for (map<long, Float_Zero>::iterator i = intr->rapport.begin(); i != intr->rapport.end(); i++)
				{
					fwrite(&i->first, sizeof(long), 1, h);
					fwrite(&i->second, sizeof(Float_Zero), 1, h);
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
			fwrite(&squad[sq]->activity, sizeof(ActivityST), 1, h);
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
			writeVerbose(filename);
		}
		else {
			deleteVerbose(filename);
		}
	}
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
	h = LCSOpenFile(filename.c_str(), CONST_saveload091.c_str(), LCSIO_PRE_HOME);
	if (h != NULL)
	{
		fread(&loadversion, sizeof(int), 1, h);
		//NUKE INVALID SAVE GAMES
		if (loadversion < lowestloadversion)
		{
			LCSCloseFile(h);
			title_screen::getInstance().reset();
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
				if (location[l]->loot[l2]->whatIsThis() == THIS_IS_LOOT)
					del = (getloottype(location[l]->loot[l2]->get_itemtypename()) == -1);
				else if (location[l]->loot[l2]->whatIsThis() == THIS_IS_CLIP)
					del = (getcliptype(location[l]->loot[l2]->get_itemtypename()) == -1);
				else if (location[l]->loot[l2]->whatIsThis() == THIS_IS_WEAPON)
					del = (getweapontype(location[l]->loot[l2]->get_itemtypename()) == -1);
				else if (location[l]->loot[l2]->whatIsThis() == THIS_IS_ARMOR)
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
		for (int pl = 0; pl < CreaturePool::getInstance().lenpool(); pl++)
		{
			int creatureSize;
			fread(&creatureSize, sizeof(int), 1, h);
			vector<char> vec = vector<char>(creatureSize + 1);
			fread(&vec[0], creatureSize, 1, h);
			vec[creatureSize] = '\0';
			pool[pl] = new Creature(&vec[0]);
			// extra InterrogationST data if applicable
			if (pool[pl]->align == -1 && pool[pl]->alive)
			{
				InterrogationST* &intr = pool[pl]->activity.intr();
				intr = new InterrogationST;
				fread(intr->techniques, sizeof(bool[6]), 1, h);
				fread(&intr->druguse, sizeof(int), 1, h);
				intr->rapport.clear();
				int size;
				fread(&size, sizeof(int), 1, h);
				for (int i = 0; i < size; i++)
				{
					long id;
					Float_Zero value;
					fread(&id, sizeof(long), 1, h);
					fread(&value, sizeof(Float_Zero), 1, h);
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
			fread(&squad[sq]->activity, sizeof(ActivityST), 1, h);
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
					for (int pl = 0; pl < CreaturePool::getInstance().lenpool(); pl++)
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
				if (squad[sq]->loot[l2]->whatIsThis() == THIS_IS_LOOT)
					del = (getloottype(squad[sq]->loot[l2]->get_itemtypename()) == -1);
				else if (squad[sq]->loot[l2]->whatIsThis() == THIS_IS_CLIP)
					del = (getcliptype(squad[sq]->loot[l2]->get_itemtypename()) == -1);
				else if (squad[sq]->loot[l2]->whatIsThis() == THIS_IS_WEAPON)
					del = (getweapontype(squad[sq]->loot[l2]->get_itemtypename()) == -1);
				else if (squad[sq]->loot[l2]->whatIsThis() == THIS_IS_ARMOR)
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
			
			long recruiter_id;
			short timeleft;
			char level;
			char eagerness1;
			char task;
			fread(&recruiter_id, sizeof(long), 1, h);
			fread(&timeleft, sizeof(short), 1, h);
			fread(&level, sizeof(char), 1, h);
			fread(&eagerness1, sizeof(char), 1, h);
			fread(&task, sizeof(char), 1, h);
			int creatureSize;
			fread(&creatureSize, sizeof(int), 1, h);
			vector<char> vec = vector<char>(creatureSize + 1);
			fread(&vec[0], creatureSize, 1, h);
			vec[creatureSize] = '\0';
			recruit[rt] = new recruitst(new Creature(&vec[0]), recruiter_id);
			recruit[rt]->timeleft = timeleft;
			recruit[rt]->level = level;
			recruit[rt]->eagerness1 = eagerness1;
			recruit[rt]->task = task;
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
				for (int pl = 0; pl < CreaturePool::getInstance().lenpool(); pl++)
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
			readVerbose(filename);
		
		return 1;
	}
	return 0;
}