
#include "../includes03.h"
#include "../includesDeprecatedB.h"
#include <fstream>
using std::ios;
using std::endl;
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

// TODO: It would be really cool to be able to CONST_EXPORT characters.
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
vector<saveLoadChunk> newFirstChunk =
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
	saveLoadChunk(courtname, sizeof(char) * POLITICIAN_NAMELEN, COURTNUM),
	saveLoadChunk(exec, sizeof(short), EXECNUM),
	saveLoadChunk(execname, sizeof(char) * POLITICIAN_NAMELEN, EXECNUM),
	saveLoadChunk(oldPresidentName, sizeof(char), POLITICIAN_NAMELEN)
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
	saveLoadChunk(courtname, sizeof(char) * POLITICIAN_NAMELEN, COURTNUM),
	saveLoadChunk(exec, sizeof(char), EXECNUM),
	saveLoadChunk(execname, sizeof(char) * POLITICIAN_NAMELEN, EXECNUM),
	saveLoadChunk(oldPresidentName, sizeof(char), POLITICIAN_NAMELEN)
};
void writeVerbose(string filename) {
	// NOVERBOSECOMMENTS only affect anything if VERBOSESAVEFILE is active
	// Remove almost all automatically generated comments from verbose savefiles
	string filepath = homedir;
	int position = filename.find(SINGLE_DOT);
	filename.erase(position);
	filename += CONST_VERBOSE;
	filepath.append(filename);
	//FILE *h;
	//h = LCSOpenFile((filename).c_str(), CONST_CPP_IO_WB, LCSIO_PRE_HOME);
	//LCSCloseFile(h);
	std::ofstream outClientFile(filename, ios::out);
	if (!outClientFile) {
		std::cerr << CONST_VERBOSE_FILE_COULD_NOT_BE_OPENED << endl;
	}
	else {
		if (NOVERBOSECOMMENTS) {
			outClientFile << CONST_AUTOCOMMENTS_DISABLED << endl;
			outClientFile << CONST_REMOVE_NOVERBOSECOMMENTS_TO_ACTIVATE_AUTOCOMMENTS << endl;
		}
		else {
			outClientFile << CONST_ALL_LINES_BEGINNING_WITH_ARE_COMMENTS << endl << CONST_AND_ARE_THEREBY_IGNORED << endl;
			outClientFile << CONST_SINCE_THE_PURPOSE_OF_VERBOSE_SAVEFILES_IS_TO_MAKE_THEM_HUMAN_READABLE_AND_EDITABLE << endl;
			outClientFile << CONST_THERE_WILL_BE_QUITE_A_FEW_COMMENTS_GENERATED_AUTOMATICALLY << endl;
			outClientFile << CONST_IF_THESE_COMMENTS_ARE_MORE_TROUBLE_THAN_THEY_RE_WORTH_ADD_TO_THE_DEBUG_DEFINES_TXT_FILE << endl;
			outClientFile << CONST_NOVERBOSECOMMENTS_TO_REMOVE_THEM_ALMOST_ENTIRELY << endl;
			outClientFile << CONST_LCS_FUNDING_LEVEL_MAX_VALUE_2147483647_CAN_BE_NEGATIVE << endl;
		}
		outClientFile << ledger.get_funds() << endl;
		/*
		outClientFile << CONST_SEED << endl;
		outClientFile <<  seed[0] << endl;
		outClientFile <<  seed[1] << endl;
		outClientFile <<  seed[2] << endl;
		outClientFile <<  seed[3] << endl;
		outClientFile << CONST_MODE << endl;
		outClientFile <<  mode << endl;
		outClientFile << CONST_WINCONDITION << endl;
		outClientFile <<  wincondition << endl;
		outClientFile << CONST_FIELDSKILLRATE << endl;
		outClientFile <<  fieldskillrate << endl;
		*/
		outClientFile << CONST_HASH_DAY << endl;
		outClientFile << day << endl;
		outClientFile << CONST_HASH_MONTH << endl;
		outClientFile << month << endl;
		outClientFile << CONST_YEAR << endl;
		outClientFile << year << endl;
		outClientFile << CONST_EXECTERM << endl;
		outClientFile << execterm << endl;
		outClientFile << CONST_PRESPARTY << endl;
		outClientFile << presparty << endl;
		outClientFile << CONST_AMENDNUM << endl;
		outClientFile << amendnum << endl;
		outClientFile << CONST_MULTIPLECITYMODE << endl;
		outClientFile << multipleCityMode << endl;
		outClientFile << CONST_TERMLIMITS << endl;
		outClientFile << termlimits << endl;
		outClientFile << CONST_DEAGLE << endl;
		outClientFile << deagle << endl;
		outClientFile << CONST_M249 << endl;
		outClientFile << m249 << endl;
		outClientFile << CONST_NOTERMLIMIT << endl;
		outClientFile << notermlimit << endl;
		outClientFile << CONST_NOCOURTPURGE << endl;
		outClientFile << nocourtpurge << endl;
		outClientFile << CONST_STALINMODE << endl;
		outClientFile << stalinmode << endl;
		outClientFile << CONST_STAT_RECRUITS << endl;
		outClientFile << stat_recruits << endl;
		outClientFile << CONST_STAT_DEAD << endl;
		outClientFile << stat_dead << endl;
		outClientFile << CONST_STAT_KILLS << endl;
		outClientFile << stat_kills << endl;
		outClientFile << CONST_STAT_KIDNAPPINGS << endl;
		outClientFile << stat_kidnappings << endl;
		outClientFile << CONST_STAT_BUYS << endl;
		outClientFile << stat_buys << endl;
		outClientFile << CONST_STAT_BURNS << endl;
		outClientFile << stat_burns << endl;
		/*
		outClientFile << CONST_ENDGAMESTATE << endl;
		outClientFile <<  endgamestate << endl;
		outClientFile << CONST_CCSEXPOSURE << endl;
		outClientFile <<  ccsexposure << endl;
		outClientFile << CONST_CCS_KILLS << endl;
		outClientFile <<  ccs_kills << endl;
		*/
		outClientFile << CONST_POLICE_HEAT << endl;
		outClientFile << police_heat << endl;
		outClientFile << CONST_OFFENDED_CORPS << endl;
		outClientFile << offended_corps << endl;
		outClientFile << CONST_OFFENDED_CIA << endl;
		outClientFile << offended_cia << endl;
		outClientFile << CONST_OFFENDED_AMRADIO << endl;
		outClientFile << offended_amradio << endl;
		outClientFile << CONST_OFFENDED_CABLENEWS << endl;
		outClientFile << offended_cablenews << endl;
		outClientFile << CONST_OFFENDED_FIREMEN << endl;
		outClientFile << offended_firemen << endl;
		/*
		outClientFile << CONST_ATTORNEYSEED << endl;
		outClientFile <<  attorneyseed[0] << endl;
		outClientFile <<  attorneyseed[1] << endl;
		outClientFile <<  attorneyseed[2] << endl;
		outClientFile <<  attorneyseed[3] << endl;
		*/
		outClientFile << CONST_L_CITY_NAME << endl;
		outClientFile << lcityname << endl;
		/*
		outClientFile << CONST_LIBERAL_GUARDIAN_PUBLISHED << endl;
		outClientFile <<  newscherrybusted << endl;
		*/
		outClientFile << CONST_SLOGAN << endl;
		outClientFile << slogan << endl;
		outClientFile << CONST_PARTY_STATUS << endl;
		outClientFile << party_status << endl;
		outClientFile << CONST_ATTITUDE << endl;
		for (int i = 0; i < len(attitude); i++) {
			//outClientFile << CONST_CONCERNING + getview(i, false) << endl;
			outClientFile << attitude[i] << endl;
		}
		outClientFile << CONST_LAW_LIST << endl;
		for (int i = 0; i < len(lawList); i++) {
			if (!NOVERBOSECOMMENTS)
				outClientFile << CONST_HASH_SPACE + getLawString[i] << endl;
			outClientFile << lawList[i] << endl;
		}
		outClientFile << CONST_HASH_HOUSE << endl;
		for (int i = 0; i < len(house); i++) {
			outClientFile << house[i] << endl;
		}
		outClientFile << CONST_HASH_SENATE << endl;
		for (int i = 0; i < len(senate); i++) {
			outClientFile << senate[i] << endl;
		}
		outClientFile << CONST_SUPREME_COURT << endl;
		for (int i = 0; i < len(court); i++) {
			outClientFile << court[i] << endl;
		}
		outClientFile << CONST_SUPREME_COURT_NAMES << endl;
		for (int i = 0; i < len(courtname); i++) {
			outClientFile << courtname[i] << endl;
		}
		outClientFile << CONST_EXEC << endl;
		for (int i = 0; i < len(exec); i++) {
			outClientFile << exec[i] << endl;
		}
		outClientFile << CONST_EXECNAME << endl;
		for (int i = 0; i < len(execname); i++) {
			outClientFile << execname[i] << endl;
		}
		/*
		outClientFile << CONST_OLDPRESIDENTNAME << endl;
		outClientFile << oldPresidentName << endl;
		*/
		for (int pl = 0; pl < CreaturePool::getInstance().lenpool(); pl++)
		{
			outClientFile << CONST_NEXT_CREATURE << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << CONST_NAME << endl;
			outClientFile << pool[pl]->name << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << CONST_PROPER_NAME << endl;
			outClientFile << pool[pl]->propername << endl;
			/*
			if (!NOVERBOSECOMMENTS)
			outClientFile << CONST_GENDER_CONSERVATIVE << endl;
			outClientFile <<  pool[pl]->gender_conservative << endl;
			if (!NOVERBOSECOMMENTS)
			outClientFile << CONST_GENDER_LIBERAL << endl;
			outClientFile <<  pool[pl]->gender_liberal << endl;
			*/
			if (!NOVERBOSECOMMENTS)
				outClientFile << CONST_AGE << endl;
			outClientFile << pool[pl]->age << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << CONST_BIRTHDAY_MONTH << endl;
			outClientFile << pool[pl]->birthday_month << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << CONST_BIRTHDAY_DAY << endl;
			outClientFile << pool[pl]->birthday_day << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << CONST_ALIGNMENT << endl;
			outClientFile << pool[pl]->align << endl;
			if (!NOVERBOSECOMMENTS)
				outClientFile << CONST_JUICE << endl;
			outClientFile << pool[pl]->juice << endl;
			for (int i = 0; i < ATTNUM; i++) {
				//if (!NOVERBOSECOMMENTS)
				//outClientFile << CONST_HASH_SPACE + attribute_enum_to_string(i) << endl;
				outClientFile << pool[pl]->get_true_attribute(i) << endl;
			}
			outClientFile << CONST_SKILLS << endl;
			for (int i = 0; i < SKILLNUM; i++) {
				if (!NOVERBOSECOMMENTS)
					outClientFile << CONST_HASH_SPACE + skillEnumToString[i] << endl;
				outClientFile << pool[pl]->get_skill(i) << endl;
			}
			/*
			for (int i = 0; i < AUGMENTATIONNUM; i++) {
			outClientFile <<  pool[pl]->get_augmentation(i) << endl;
			}
			for (int i = 0; i < BODYPARTNUM; i++) {//Bad, relies on their order in the xml file. -XML
			if (!NOVERBOSECOMMENTS)
			outClientFile << CONST_NEXT_CREATURE << endl;
			outClientFile <<  pool[pl]->wound[i] << endl;
			}
			for (int i = 0; i < SPECIALWOUNDNUM; i++) { //Bad, relies on their order in the xml file. -XML
			if (!NOVERBOSECOMMENTS)
			outClientFile << CONST_NEXT_CREATURE << endl;
			outClientFile <<  pool[pl]->special[i] << endl;
			}
			*/
			outClientFile << CONST_CRIMES << endl;
			for (int i = 0; i < LAWFLAGNUM; i++) {//Bad, relies on their order in the xml file. -XML
												  // 6
												  // 20
				if (!NOVERBOSECOMMENTS)
					outClientFile << CONST_HASH_SPACE << ((i == 6 || i == 20) ? getLawFlagStringFull[i][0] : getLawFlagString[i]) << endl;
				outClientFile << pool[pl]->crimes_suspected[i] << endl;
			}
		}
		/*
		outClientFile << CONST_VEHICLE_CURCARID << endl;
		outClientFile << Vehicle::curcarid << endl;
		outClientFile << CONST_CURCREATUREID << endl;
		outClientFile << curcreatureid << endl;
		outClientFile << CONST_CURSQUADID << endl;
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
	slogan_str = slogan;
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
	int position = filename.find(SINGLE_DOT);
	filename.erase(position);
	filename += CONST_VERBOSE;
	FILE* h;
	h = LCSOpenFile((filename).c_str(), CONST_CPP_IO_RB.c_str(), LCSIO_PRE_HOME);
	if (h != NULL) {
		LCSCloseFile(h);
		std::ifstream txtFile;
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
	int position = verboseFilename.find(SINGLE_DOT);
	verboseFilename.erase(position);
	verboseFilename += CONST_VERBOSE;
	LCSDeleteFile(verboseFilename.c_str(), LCSIO_PRE_HOME);
}
void savegame(const string& filename)
{
	if (NOSAVE) {
		return;
	}
	bool dummy_b;
	int dummy;
	FILE* h;
	h = LCSOpenFile(filename.c_str(), CONST_CPP_IO_WB.c_str(), LCSIO_PRE_HOME);
	if (h != NULL)
	{
		int lversion = version;
		fwrite(&lversion, sizeof(int), 1, h);
		for (saveLoadChunk s : newFirstChunk) {
			fwrite(s.Buffer, s.ElementSize, s.ElementCount, h);
		}

		//LOCATIONS
		dummy = len(location);
		fwrite(&dummy, sizeof(int), 1, h);
		for (int l = 0; l < len(location); l++)
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
			int unused = 0;
			fwrite(location[l]->name, sizeof(char), LOCATION_NAMELEN, h);
			fwrite(location[l]->shortname, sizeof(char), LOCATION_SHORTNAMELEN, h);
			fwrite(&location[l]->type, sizeof(char), 1, h);
			fwrite(&location[l]->city, sizeof(int), 1, h);
			fwrite(&location[l]->area, sizeof(int), 1, h);
			fwrite(&location[l]->parent, sizeof(int), 1, h);
			fwrite(&unused, sizeof(int), 1, h); // NOT USED, kept for backwards compatibility
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
		for (int l = 0; l < len(vehicle); l++)
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
			if (pool[pl]->align == -1 && pool[pl]->getNameAndAlignment().alive)
			{
				InterrogationST*& intr = pool[pl]->activity.intr();
				fwrite(intr->techniques, sizeof(bool[6]), 1, h);
				fwrite(&intr->druguse, sizeof(int), 1, h);
				//deep write rapport map
				int size = len(intr->rapport);
				fwrite(&size, sizeof(int), 1, h);
				// Pointer Arithmetic
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
			short unused = 0;
			char unused_c = 0;
			char Unused_var_task = 0;
			fwrite(&recruit[rt]->recruiter_id, sizeof(long), 1, h);
			fwrite(&unused, sizeof(short), 1, h); // Unused, kept for backwards compatibility
			fwrite(&unused_c, sizeof(char), 1, h); // Unused, kept for backwards compatibility
			fwrite(&recruit[rt]->eagerness1, sizeof(char), 1, h);
			fwrite(&Unused_var_task, sizeof(char), 1, h); // Unused, kept for backwards compatibility
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
	FILE* h;
	h = LCSOpenFile(filename.c_str(), CONST_CPP_IO_RB.c_str(), LCSIO_PRE_HOME);
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
		if (loadversion < 41253) {
			for (saveLoadChunk s : firstChunk) {
				fread(s.Buffer, s.ElementSize, s.ElementCount, h);
			}
			
		}
		else {
			for (saveLoadChunk s : newFirstChunk) {
				fread(s.Buffer, s.ElementSize, s.ElementCount, h);
			}
		}
		//LOCATIONS
		fread(&dummy, sizeof(int), 1, h);
		location.resize(dummy);
		for (int l = 0; l < len(location); l++)
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
					printInvalidItem(location[l]->loot[l2]->get_itemtypename());
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
			int unused;
			fread(&unused, sizeof(int), 1, h); // NOT USED, kept for backwards compatibility
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
		for (int l = 0; l < len(vehicle); l++)
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
			pool[pl] = new DeprecatedCreature(&vec[0]);
			// extra InterrogationST data if applicable
			if (pool[pl]->align == -1 && pool[pl]->getNameAndAlignment().alive)
			{
				InterrogationST*& intr = pool[pl]->activity.intr();
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
			squad[sq] = new Deprecatedsquadst;
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
					printInvalidItem(squad[sq]->loot[l2]->get_itemtypename());
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
			date[dt] = new Deprecateddatest;
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
				date[dt]->date[dt2] = new DeprecatedCreature(&vec[0]);
			}
		}
		//RECRUITS
		fread(&dummy, sizeof(int), 1, h);
		recruit.resize(dummy);
		for (int rt = 0; rt < len(recruit); rt++)
		{

			long recruiter_id;
			short Unused_var_timeleft; // Unused, kept for backwards compatibility
			char Unused_var_level; // Unused, kept for backwards compatibility
			char eagerness1;
			char Unused_var_task; // Unused, kept for backwards compatibility
			fread(&recruiter_id, sizeof(long), 1, h);
			fread(&Unused_var_timeleft, sizeof(short), 1, h); // Unused, kept for backwards compatibility
			fread(&Unused_var_level, sizeof(char), 1, h); // Unused, kept for backwards compatibility
			fread(&eagerness1, sizeof(char), 1, h);
			fread(&Unused_var_task, sizeof(char), 1, h); // Unused, kept for backwards compatibility
			int creatureSize;
			fread(&creatureSize, sizeof(int), 1, h);
			vector<char> vec = vector<char>(creatureSize + 1);
			fread(&vec[0], creatureSize, 1, h);
			vec[creatureSize] = '\0';
			recruit[rt] = new Deprecatedrecruitst(new DeprecatedCreature(&vec[0]), recruiter_id);
			//recruit[rt]->timeleft = timeleft; 
			//recruit[rt]->level = level;
			recruit[rt]->eagerness1 = eagerness1;
			//recruit[rt]->task = task;
		}
		//NEWS STORIES
		fread(&dummy, sizeof(int), 1, h);
		newsstory.resize(dummy);
		for (int ns = 0; ns < len(newsstory); ns++)
		{
			newsstory[ns] = new Deprecatednewsstoryst;
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
				printInvalidVehicle(vehicle[v]->vtypeidname());
				delete_and_remove(vehicle, v--);
			}
		}
		slogan_str = slogan;
		readVerbose(filename);

		return 1;
	}
	return 0;
}