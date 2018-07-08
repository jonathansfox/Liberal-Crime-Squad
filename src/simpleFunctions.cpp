// Functions removed from elsewhere that require no #include
// except for enumerators and standard libraries
// Most of these can be simplified through use of maps and other data structured
// Which will assist in future additions or changes

#include "includes.h"
#include "creature/creatureEnums.h"
#include "locations/locationsEnums.h"

void addCrackhouse(int creaturearray[CREATURENUM]) {
	extern char endgamestate;
	extern short lawList[LAWNUM];

	if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_POLLUTION] == -2 &&
		lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 50;
	if (endgamestate<ENDGAME_CCS_DEFEATED && endgamestate>ENDGAME_NONE)
		creaturearray[CREATURE_CCS_VIGILANTE] += 5;
}
void addCigarbar(int creaturearray[CREATURENUM], const char sec) {
	extern char endgamestate;
	extern short sitealarm;
	extern short lawList[LAWNUM];
	if (sec || sitealarm == 1)creaturearray[CREATURE_BOUNCER] += 100;
	else creaturearray[CREATURE_BOUNCER] += 10;
	if (sec)creaturearray[CREATURE_GUARDDOG] += 25;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] += 2;
	if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] += 2;
	if (endgamestate<ENDGAME_CCS_DEFEATED && endgamestate>ENDGAME_NONE)
		creaturearray[CREATURE_CCS_VIGILANTE] += 5;

}
void addWhitehouse(int creaturearray[CREATURENUM], const char sec) {

	extern char endgamestate;
	extern short exec[EXECNUM];


	if (sec)creaturearray[CREATURE_SECRET_SERVICE] += 100;
	else creaturearray[CREATURE_SECRET_SERVICE] += 5;
	if (endgamestate<ENDGAME_CCS_DEFEATED && endgamestate>ENDGAME_NONE && exec[EXEC_PRESIDENT] < ALIGN_CONSERVATIVE)
		creaturearray[CREATURE_CCS_ARCHCONSERVATIVE] += 1;
}
void addLatteStandOrPark(int creaturearray[CREATURENUM]) {
	extern short lawList[LAWNUM];
	extern char endgamestate;



	if (lawList[LAW_LABOR] < 2)creaturearray[CREATURE_WORKER_FACTORY_NONUNION] += 5;
	if (lawList[LAW_LABOR] >= 0)creaturearray[CREATURE_WORKER_FACTORY_UNION] += 5;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] += 2;
	if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] += 2;
	if (endgamestate<ENDGAME_CCS_DEFEATED && endgamestate>ENDGAME_NONE)
		creaturearray[CREATURE_CCS_VIGILANTE] += endgamestate * 4;
	if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 1;
	if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 1;
	if (lawList[LAW_POLLUTION] == -2 &&
		lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] += 1;
	else creaturearray[CREATURE_PRISONGUARD] += 1;
}
void addVeganCoop(int creaturearray[CREATURENUM]) {
	extern short lawList[LAWNUM];



	if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 1;
	if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 1;
	if (lawList[LAW_POLLUTION] == -2 &&
		lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
}

void addShelter(int creaturearray[CREATURENUM]) {
	extern short lawList[LAWNUM];



	if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_POLLUTION] == -2 &&
		lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 50;
}
void addTenement(int creaturearray[CREATURENUM]) {
	extern short lawList[LAWNUM];



	if (lawList[LAW_LABOR] < 2)creaturearray[CREATURE_WORKER_FACTORY_NONUNION] += 1;
	if (lawList[LAW_LABOR] >= 0)creaturearray[CREATURE_WORKER_FACTORY_UNION] += 1;
	if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_POLLUTION] == -2 &&
		lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 5;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] += 1;
	else creaturearray[CREATURE_PRISONGUARD] += 1;
}
void addApartment(int creaturearray[CREATURENUM]) {
	extern short lawList[LAWNUM];


	if (lawList[LAW_LABOR] < 2)creaturearray[CREATURE_WORKER_FACTORY_NONUNION] = 1;
	if (lawList[LAW_LABOR] >= 0)creaturearray[CREATURE_WORKER_FACTORY_UNION] = 1;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] += 1;
	if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] += 1;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] += 1;
	else creaturearray[CREATURE_PRISONGUARD] += 1;
}

void addIntelligence(int creaturearray[CREATURENUM], const char sec) {


	if (sec)creaturearray[CREATURE_AGENT] += 1000;
	else creaturearray[CREATURE_AGENT] += 100;
	if (sec)creaturearray[CREATURE_GUARDDOG] += 450;

}
void addArmyBase(int creaturearray[CREATURENUM], const char sec) {

	if (sec)creaturearray[CREATURE_GUARDDOG] += 230;
	if (sec)creaturearray[CREATURE_MILITARYPOLICE] += 100;
}
void addSweatShop(int creaturearray[CREATURENUM], const char sec) {


	if (sec)creaturearray[CREATURE_SECURITYGUARD] += 1000;
	else creaturearray[CREATURE_SECURITYGUARD] += 100;
}
void addIndustryPolluter(int creaturearray[CREATURENUM], const char sec) {
	extern short lawList[LAWNUM];
	if (sec)creaturearray[CREATURE_SECURITYGUARD] += 100;

	if (lawList[LAW_LABOR] == -2)
	{
		creaturearray[CREATURE_WORKER_FACTORY_NONUNION] += 20;
		creaturearray[CREATURE_WORKER_FACTORY_CHILD] += 140;
	}
	else if (lawList[LAW_LABOR] == -1)
	{
		creaturearray[CREATURE_WORKER_FACTORY_NONUNION] += 160;
		creaturearray[CREATURE_WORKER_FACTORY_CHILD] += 1;
	}
	else if (lawList[LAW_LABOR] == 0)
	{
		creaturearray[CREATURE_WORKER_FACTORY_NONUNION] += 80;
		creaturearray[CREATURE_WORKER_FACTORY_UNION] += 80;
	}
	else if (lawList[LAW_LABOR] == 1)
	{
		creaturearray[CREATURE_WORKER_FACTORY_NONUNION] = 50;
		creaturearray[CREATURE_WORKER_FACTORY_UNION] = 110;
	}
	else creaturearray[CREATURE_WORKER_FACTORY_UNION] = 160;
}
void addCorpHQ(int creaturearray[CREATURENUM], const char sec) {

	if (sec)creaturearray[CREATURE_GUARDDOG] += 100;
	if (sec)creaturearray[CREATURE_SECURITYGUARD] = 400;
	else creaturearray[CREATURE_SECURITYGUARD] = 40;
}
void addCorpHouse(int creaturearray[CREATURENUM], const char sec) {



	if (sec)creaturearray[CREATURE_MERC] = 100;
	if (sec)creaturearray[CREATURE_GUARDDOG] = 50;
	else creaturearray[CREATURE_GUARDDOG] = 5;
}
void addMediaAMRadio(int creaturearray[CREATURENUM], const char sec) {


	if (sec)creaturearray[CREATURE_SECURITYGUARD] = 100;
	else creaturearray[CREATURE_SECURITYGUARD] = 10;
}
void addMediaCablenews(int creaturearray[CREATURENUM], const char sec) {

	if (sec)creaturearray[CREATURE_SECURITYGUARD] = 100;
	else creaturearray[CREATURE_SECURITYGUARD] = 10;

}

void addLaboratoryCosmetics(int creaturearray[CREATURENUM], const char sec) {


	if (sec)creaturearray[CREATURE_SECURITYGUARD] += 100;
	else creaturearray[CREATURE_SECURITYGUARD] += 3;
}
void addIndustryNuclear(int creaturearray[CREATURENUM], const char sec) {


	if (sec)creaturearray[CREATURE_SECURITYGUARD] += 100;
	else creaturearray[CREATURE_SECURITYGUARD] += 10;
}
void addLaboratoryGenetic(int creaturearray[CREATURENUM], const char sec) {



	if (sec)creaturearray[CREATURE_GUARDDOG] += 25;
	if (sec)creaturearray[CREATURE_SECURITYGUARD] += 100;
	else creaturearray[CREATURE_SECURITYGUARD] += 3;
}
void addPoliceStation(int creaturearray[CREATURENUM], const char sec) {
	extern short lawList[LAWNUM];



	if (lawList[LAW_LABOR] < 2)creaturearray[CREATURE_WORKER_FACTORY_NONUNION] = 1;
	if (lawList[LAW_LABOR] >= 0)creaturearray[CREATURE_WORKER_FACTORY_UNION] = 1;
	if (sec)creaturearray[CREATURE_COP] += 1000;
	else creaturearray[CREATURE_COP] += 500;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] += 400;
	if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] += 400;
	if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_POLLUTION] == -2 &&
		lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 5;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] = 1;
	else creaturearray[CREATURE_PRISONGUARD] = 1;
}
void addCourthouse(int creaturearray[CREATURENUM], const char sec) {

	extern short lawList[LAWNUM];


	if (sec)creaturearray[CREATURE_COP] = 2000;
	else creaturearray[CREATURE_COP] = 200;
	if (lawList[LAW_LABOR] < 2)creaturearray[CREATURE_WORKER_FACTORY_NONUNION] = 1;
	if (lawList[LAW_LABOR] >= 0)creaturearray[CREATURE_WORKER_FACTORY_UNION] = 1;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] = 80;
	if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] = 80;
	if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 1;
	if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 1;
	if (lawList[LAW_POLLUTION] == -2 &&
		lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] = 1;
	else creaturearray[CREATURE_PRISONGUARD] = 1;
}
void addFirestation(int creaturearray[CREATURENUM], const char sec) {


	extern short lawList[LAWNUM];

	if (sec)
	{
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] += 50;
		else if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] += 50;
		else creaturearray[CREATURE_COP] += 50;
	}
}

/* prints a short blurb showing how to page forward */
string addnextpagestr()
{
	const string CONST_commondisplay223 = "PGDN";
	const string CONST_commondisplay222 = ":";
	const string CONST_commondisplay221 = "]";
	const string CONST_commondisplay22Z = " - Next";
	string output;
	extern short interface_pgup;
	if (interface_pgup == '[')
		output = CONST_commondisplay221;
	else if (interface_pgup == '.')
		output = CONST_commondisplay222;
	else output = CONST_commondisplay223;
	return output + CONST_commondisplay22Z;
}
/* prints a short blurb showing how to page back */
string addprevpagestr()
{
	const string CONST_commondisplay226 = "PGUP";
	const string CONST_commondisplay225 = ";";
	const string CONST_commondisplay224 = "[";
	const string CONST_commondisplay22Y = " - Previous";
	string output;
	extern short interface_pgup;
	if (interface_pgup == '[')
		output = CONST_commondisplay224;
	else if (interface_pgup == '.')
		output = CONST_commondisplay225;
	else output = CONST_commondisplay226;
	return output + CONST_commondisplay22Y;
}
/* prints a long blurb showing how to page forward and back */
string addpagestr()
{
	const string CONST_commondisplay229 = "PGUP/PGDN";
	const string CONST_commondisplay228 = "; and :";
	const string CONST_commondisplay227 = "[]";
	const string CONST_commondisplay22X = " to view other Liberal pages.";
	string output;
	extern short interface_pgup;
	if (interface_pgup == '[')
		output = CONST_commondisplay227;
	else if (interface_pgup == '.')
		output = CONST_commondisplay228;
	else output = CONST_commondisplay229;
	return output + CONST_commondisplay22X;
}

/* daily - returns the number of days in the current month */
int monthday()
{
	extern int month;
	extern int year;
	switch (month)
	{
	case 2: return 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); // February
	case 4: // April
	case 6: // June
	case 9: // September
	case 11: return 30; // November
	default: return 31; // January, March, May, July, August, October, & December
	}
}


bool populateEncounter(const int type, int creaturearray[CREATURENUM], const char sec) {
	switch (type)
	{
	case SITE_BUSINESS_CRACKHOUSE:
	{
		addCrackhouse(creaturearray);
		break;
	}
	case SITE_BUSINESS_JUICEBAR:
	{
		break;
	}
	case SITE_BUSINESS_CIGARBAR:
	{
		addCigarbar(creaturearray, sec);
		break;
	}
	case SITE_GOVERNMENT_WHITE_HOUSE:
	{
		addWhitehouse(creaturearray, sec);
		break;
	}
	case SITE_OUTDOOR_PUBLICPARK:
	case SITE_BUSINESS_LATTESTAND:
	{
		addLatteStandOrPark(creaturearray);
		break;
	}
	case SITE_BUSINESS_VEGANCOOP:
	{
		addVeganCoop(creaturearray);
		break;
	}
	case SITE_BUSINESS_INTERNETCAFE:
	{
		break;
	}
	default:
	case SITE_RESIDENTIAL_SHELTER:
	{
		addShelter(creaturearray);
		break;
	}
	case SITE_RESIDENTIAL_TENEMENT:
	{
		addTenement(creaturearray);
		return true;
	}
	case SITE_RESIDENTIAL_APARTMENT:
	{
		addApartment(creaturearray);
		return true;
	}

	case SITE_LABORATORY_COSMETICS:
	{
		addLaboratoryCosmetics(creaturearray, sec);
		break;
	}
	case SITE_INDUSTRY_NUCLEAR:
	{
		addIndustryNuclear(creaturearray, sec);
		break;
	}
	case SITE_LABORATORY_GENETIC:
	{
		addLaboratoryGenetic(creaturearray, sec);
		break;
	}
	case SITE_GOVERNMENT_POLICESTATION:
	{
		addPoliceStation(creaturearray, sec);
		break;
	}
	case SITE_GOVERNMENT_COURTHOUSE:
	{
		addCourthouse(creaturearray, sec);
		break;
	}
	case SITE_GOVERNMENT_FIRESTATION:
	{
		addFirestation(creaturearray, sec);
		break;
	}

	case SITE_GOVERNMENT_INTELLIGENCEHQ:
	{
		addIntelligence(creaturearray, sec);
		break;
	}
	case SITE_GOVERNMENT_ARMYBASE:
	{
		addArmyBase(creaturearray, sec);
		break;
	}
	case SITE_INDUSTRY_SWEATSHOP:
	{
		addSweatShop(creaturearray, sec);
		break;
	}
	case SITE_INDUSTRY_POLLUTER:
	{
		addIndustryPolluter(creaturearray, sec);
		break;
	}
	case SITE_CORPORATE_HEADQUARTERS:
	{
		addCorpHQ(creaturearray, sec);
		break;
	}
	case SITE_CORPORATE_HOUSE:
	{
		addCorpHouse(creaturearray, sec);
		break;
	}
	case SITE_MEDIA_AMRADIO:
	{
		addMediaAMRadio(creaturearray, sec);
		break;
	}
	case SITE_MEDIA_CABLENEWS:
	{
		addMediaCablenews(creaturearray, sec);
		break;
	}
	}
	return false;

}

int bodypartSeverAmount(const int w) {
	int severamount = 100;
	switch (w)
	{
	case BODYPART_HEAD:severamount = 100; break;
	case BODYPART_BODY:severamount = 1000; break;
	case BODYPART_ARM_RIGHT:severamount = 200; break;
	case BODYPART_ARM_LEFT:severamount = 200; break;
	case BODYPART_LEG_RIGHT:severamount = 400; break;
	case BODYPART_LEG_LEFT:severamount = 400; break;
	}
	return severamount;
}
std::string burstHitString(int bursthits) {
	if (bursthits < 1) {
		bursthits = 1;
	}
	const vector<string> numberTimesHit =
	{
		"",
		" twice",
		" three",
		" four",
		" five",
	};
	const string singleSpace = " ";
	const string CONST_fight035 = " times";
	string output;
	if (bursthits > 5) {
		output += singleSpace + tostring(bursthits);
	}
	else {
		output += numberTimesHit[bursthits - 1];
	}
	if (bursthits > 2) {
		output += CONST_fight035;
	}
	return output;
}
map<int, bool> stalinView = {
	map<int, bool>::value_type(VIEW_STALIN,  false), // Liberals and Stalinists don't get along
		map<int, bool>::value_type(VIEW_MOOD,  false), // Liberals and Stalinists don't get along
		map<int, bool>::value_type(VIEW_GAY,  false), // Stalinists discriminate against gay people
		map<int, bool>::value_type(VIEW_DEATHPENALTY,  false), // Stalinists execute lots of people
		map<int, bool>::value_type(VIEW_TAXES,  true), // Stalinists support communist income redistribution
		map<int, bool>::value_type(VIEW_NUCLEARPOWER,  false), // Stalinists believe the more nuclear, the better
		map<int, bool>::value_type(VIEW_ANIMALRESEARCH,  false), // Stalinists are in favor of unethical research
		map<int, bool>::value_type(VIEW_POLICEBEHAVIOR,  false), // Stalinists use police for brutal repression
		map<int, bool>::value_type(VIEW_TORTURE,  false), // Stalinists torture their enemies
		map<int, bool>::value_type(VIEW_INTELLIGENCE,  false), // Stalinists don't believe in privacy
		map<int, bool>::value_type(VIEW_FREESPEECH,  false), // Stalinists don't allow any dissent
		map<int, bool>::value_type(VIEW_GENETICS,  false), // Stalinists are in favor of unethical research
		map<int, bool>::value_type(VIEW_JUSTICES,  false), // Liberals and Stalinists don't get along
		map<int, bool>::value_type(VIEW_GUNCONTROL,  true), // Stalinists don't want any armed resistance
		map<int, bool>::value_type(VIEW_SWEATSHOPS,  true), // Stalinists say, Workers of the world unite!
		map<int, bool>::value_type(VIEW_POLLUTION,  false), // Stalinists don't care about pollution
		map<int, bool>::value_type(VIEW_CORPORATECULTURE,  true), // Stalinists hate rich people and corporations
		map<int, bool>::value_type(VIEW_CEOSALARY,  true), // Stalinists hate rich people and corporations
		map<int, bool>::value_type(VIEW_WOMEN,  false), // Stalinists discriminate against women
		map<int, bool>::value_type(VIEW_CIVILRIGHTS,  false), // Stalinists discriminate against ethnic groups
		map<int, bool>::value_type(VIEW_DRUGS,  false), // Stalinists only allow vodka
		map<int, bool>::value_type(VIEW_IMMIGRATION,  false), // Stalinists maintained tight border security at the Iron Curtain
		map<int, bool>::value_type(VIEW_MILITARY,  false), // Stalinists use the military for brutal repression
		map<int, bool>::value_type(VIEW_PRISONS,  false), // Stalinists annex Canada to fill it with gulags
		map<int, bool>::value_type(VIEW_AMRADIO,  true), // Stalinists agree that Conservatives are bad
		map<int, bool>::value_type(VIEW_CABLENEWS,  true), // Stalinists agree that Conservatives are bad
															   //map<int, bool>::value_type( VIEW_POLITICALVIOLENCE,  true), // the LCS and Stalinists both like using political violence
		map<int, bool>::value_type(VIEW_LIBERALCRIMESQUAD,  false), // Liberals and Stalinists don't get along
		map<int, bool>::value_type(VIEW_LIBERALCRIMESQUADPOS,  false), // Liberals and Stalinists don't get along
		map<int, bool>::value_type(VIEW_CONSERVATIVECRIMESQUAD,  true), // Stalinists agree that Conservatives are bad
		map<int, bool>::value_type(VIEWNUM,  false), // Liberals and Stalinists don't get along
};
map<int, bool> stalinLaw = {
	map<int, bool>::value_type(LAW_STALIN,  false), // Liberals and Stalinists don't get along
	map<int, bool>::value_type(LAW_MOOD,  false), // Liberals and Stalinists don't get along
	map<int, bool>::value_type(LAW_ABORTION,  true), // Stalinists agree that abortion is good, although technically they don't let women choose
	map<int, bool>::value_type(LAW_ANIMALRESEARCH,  false), // Stalinists are in favor of unethical research
	map<int, bool>::value_type(LAW_POLICEBEHAVIOR,  false), // Stalinists use police for brutal repression
	map<int, bool>::value_type(LAW_PRIVACY,  false), // Stalinists don't believe in privacy
	map<int, bool>::value_type(LAW_DEATHPENALTY,  false), // Stalinists execute lots of people
	map<int, bool>::value_type(LAW_NUCLEARPOWER,  false), // Stalinists believe the more nuclear, the better
	map<int, bool>::value_type(LAW_POLLUTION,  false), // Stalinists don't care about pollution
	map<int, bool>::value_type(LAW_LABOR,  true), // Stalinists say, Workers of the world unite!
	map<int, bool>::value_type(LAW_GAY,  false), // Stalinists discriminate against gay people
	map<int, bool>::value_type(LAW_CORPORATE,  true), // Stalinists hate rich people and corporations
	map<int, bool>::value_type(LAW_FREESPEECH,  false), // Stalinists don't allow any dissent
	map<int, bool>::value_type(LAW_FLAGBURNING,  true), // Stalinists regularly burn flags
	map<int, bool>::value_type(LAW_GUNCONTROL,  true), // Stalinists don't want any armed resistance
	map<int, bool>::value_type(LAW_TAX,  true), // Stalinists support communist income redistribution
	map<int, bool>::value_type(LAW_WOMEN,  false), // Stalinists discriminate against women
	map<int, bool>::value_type(LAW_CIVILRIGHTS,  false), // Stalinists discriminate against ethnic groups
	map<int, bool>::value_type(LAW_DRUGS,  false), // Stalinists only allow vodka
	map<int, bool>::value_type(LAW_IMMIGRATION,  false), // Stalinists maintained tight border security at the Iron Curtain
	map<int, bool>::value_type(LAW_ELECTIONS,  false), // Stalinists don't even have elections
	map<int, bool>::value_type(LAW_MILITARY,  false), // Stalinists use the military for brutal repression
	map<int, bool>::value_type(LAW_PRISONS,  false), // Stalinists annex Canada to fill it with gulags
	map<int, bool>::value_type(LAW_TORTURE,  false), // Stalinists torture their enemies
	map<int, bool>::value_type(LAWNUM,  false), // Liberals and Stalinists don't get along
};
/* returns true if Stalinists agree with Elite Liberals on a view/law, false if they strongly disagree with libs  *
* the input bool islaw, if true, returns Stalinist opinion on laws, if false, returns Stalinist opinion on views */
bool stalinview(short view, bool islaw)
{
	if (islaw)
	{
		if (stalinLaw.count(view)) {
			return stalinLaw[view];
		}
		else
			return false; // if the law doesn't exist, assume false
	}
	else
	{
		if (stalinView.count(view)) {
			return stalinView[view];
		}
		else
			return false; // if the view doesn't exist, assume false
	}
}
map<int, int> lawReturnAttitude = {
	map<int, int>::value_type(LAW_ABORTION, VIEW_WOMEN), //XXX, There is no ``VIEW_ABORTION''!
	map<int, int>::value_type(LAW_ANIMALRESEARCH, VIEW_ANIMALRESEARCH),
	map<int, int>::value_type(LAW_POLICEBEHAVIOR, VIEW_POLICEBEHAVIOR),
	map<int, int>::value_type(LAW_PRIVACY, VIEW_INTELLIGENCE),
	map<int, int>::value_type(LAW_DEATHPENALTY, VIEW_DEATHPENALTY),
	map<int, int>::value_type(LAW_NUCLEARPOWER, VIEW_NUCLEARPOWER),
	map<int, int>::value_type(LAW_POLLUTION, VIEW_POLLUTION),
	map<int, int>::value_type(LAW_LABOR, VIEW_SWEATSHOPS),
	map<int, int>::value_type(LAW_GAY, VIEW_GAY),
	map<int, int>::value_type(LAW_FREESPEECH, VIEW_FREESPEECH),
	map<int, int>::value_type(LAW_TAX, VIEW_TAXES),
	map<int, int>::value_type(LAW_FLAGBURNING, VIEW_FREESPEECH),  // <-- I'm keeping this pure free speech instead of free speech
	map<int, int>::value_type(LAW_WOMEN, VIEW_WOMEN),             // plus political violence. Ideologically, there's no association
	map<int, int>::value_type(LAW_CIVILRIGHTS, VIEW_CIVILRIGHTS), // between flag burning and violence. - Jonathan S. Fox
	map<int, int>::value_type(LAW_DRUGS, VIEW_DRUGS),
	map<int, int>::value_type(LAW_IMMIGRATION, VIEW_IMMIGRATION), //XXX, VIEW_DRUGS?
	map<int, int>::value_type(LAW_MILITARY, VIEW_MILITARY),
	map<int, int>::value_type(LAW_TORTURE, VIEW_TORTURE),
	map<int, int>::value_type(LAW_GUNCONTROL, VIEW_GUNCONTROL),
	map<int, int>::value_type(LAW_PRISONS, VIEW_PRISONS),
};
/* politics - checks the prevailing attitude on a specific law, or overall */
int publicmood(int l)
{
	if (lawReturnAttitude.count(l)) {
		return lawReturnAttitude[l];
	}
	else {
		extern short attitude[VIEWNUM];
		switch (l)
		{  // All laws should be affected by exactly one issue if there is a direct
		   // correlation between that law and an issue. For example, police behavior
		   // as a law should depend only upon police behavior as an issue. This keeps
		   // the game logical to the player and ensures that the public opinion polls
		   // displayed in-game accurately predict how people will vote in specific
		   // issues. For a handful of laws, we might not have a directly correlating
		   // issue; for example, as of this writing, there is no issue asking people's
		   // opinions on torture. In this case, we can use the nearest issue, or we
		   // can mix two closely related ones. As a general principle, try to avoid
		   // getting too complicated here; this is under-the-hood stuff the player
		   // will never appreciate, so it should be kept as simple and transparent as
		   // possible so as to avoid creating unexpected results that will only confuse
		   // players, like people refusing to further regulate nuclear power because
		   // one of the other issues besides nuclear power is conservative, even when
		   // the nuclear power issue is 100% Liberal. - Jonathan S. Fox
		case LAW_CORPORATE: return (attitude[VIEW_CORPORATECULTURE] + attitude[VIEW_CEOSALARY]) / 2; // <-- We'll be merging these two views here because there is no CEO salary law.
							// The issue is there for flavor, and falls under the same umbrella of
							 // corporate regulation. - Jonathan S. Fox
		case LAW_STALIN:
			l = 0;
			for (int v = 0; v < VIEWNUM - 3; v++)
				if (stalinview(v, false)) l += 100 - attitude[v];
				else l += attitude[v];
				return l / (VIEWNUM - 3);
		case LAW_ELECTIONS:
		case LAW_MOOD:
		default: //eg. -1
			l = 0;
			for (int v = 0; v < VIEWNUM - 3; v++) l += attitude[v];
			return l / (VIEWNUM - 3);
		}
	}
}
/* common - shifts public opinion on an issue */
void change_public_opinion(int v, int power, char affect, char cap)
{
	extern short attitude[VIEWNUM];
	extern short public_interest[VIEWNUM];
	extern short background_liberal_influence[VIEWNUM];
	// First note this in the liberal influence -- mostly for the
	// sake of the nice visual intelligence report entry
	if (v < VIEWNUM - 5)
	{
		background_liberal_influence[v] += power * 10;
	}
	if (v == VIEW_LIBERALCRIMESQUAD)affect = 0;
	if (v == VIEW_LIBERALCRIMESQUADPOS)affect = 0;
	if (v == VIEW_LIBERALCRIMESQUADPOS)
	{
		int mood = publicmood(-1);
		if (cap > mood + 40)cap = mood + 40;
	}
	int effpower = power;
	// Affect is whether the LCS is publicly known to be behind
	// the circumstances creating the public opinion change
	if (affect == 1)
	{
		// Aff is the % of people who know/care about the LCS
		int aff = attitude[VIEW_LIBERALCRIMESQUAD];
		// Rawpower is the amount of the action proportional
		// to the people who, not having heard of the LCS,
		// do not allow the LCS' reputation to affect their
		// opinions
		int rawpower = (int)((float)power * (float)(100 - aff) / 100.0f);
		// Affected power is the remainder of the action besides
		// rawpower, the amount of the people who know of the LCS
		// and have it alter their opinion
		int affectedpower = power - rawpower;
		if (affectedpower > 0)
		{
			// Dist is a combination of the relative popularity of the LCS
			// to the issue and the absolute popularity of the LCS. Very
			// popular LCS on a very unpopular issue is very influential.
			// Very unpopular LCS on a very popular issue has the ability
			// to actually have a reverse effect.
			int dist = attitude[VIEW_LIBERALCRIMESQUADPOS] - attitude[v] +
				attitude[VIEW_LIBERALCRIMESQUADPOS] - 50;
			// Affected power is then scaled by dist -- if the LCS is
			// equally popular as the issue, it's equally powerful as
			// the rawpower. For every 10% up or down past there, it's
			// 10% more or less powerful.
			affectedpower = (int)(((float)affectedpower*(100.0 + (float)dist)) / 100.0f);
		}
		// Effpower is then the sum of the rawpower (people who don't know
		// about the LCS) and the affectedpower (people who do know
		// about the LCS and had their judgment swayed by their opinion
		// of it).
		effpower = rawpower + affectedpower;
	}
	else if (affect == -1)
	{
		// Simplifed algorithm for affect by CCS respect
		effpower = power * (100 - attitude[VIEW_CONSERVATIVECRIMESQUAD]) / 100;
	}
	if (v == VIEW_LIBERALCRIMESQUAD)
	{
		//Only half the country will ever hear about the LCS at one time,
		//and people will only grudgingly lose fear of it
		if (effpower < -5)effpower = -5;
		if (effpower > 50)effpower = 50;
	}
	else if (v == VIEW_LIBERALCRIMESQUADPOS)
	{
		//Only 50% of the country can be swayed at once in their views
		//of the LCS negatively, 5% positively
		if (effpower < -50)effpower = -50;
		if (effpower > 5)effpower = 5;
	}
	//Scale the magnitude of the effect based on how much
	//people are paying attention to the issue
	effpower = (int)(effpower*(1 + (float)public_interest[v] / 50));
	//Then affect public interest
	if (public_interest[v] < cap || (v == VIEW_LIBERALCRIMESQUADPOS && public_interest[v] < 100))
		public_interest[v] += abs(effpower);
	if (effpower > 0)
	{
		//Some things will never persuade the last x% of the population.
		//If there's a cap on how many people will be impressed, this
		//is where that's handled.
		if (attitude[v] + effpower > cap)
		{
			if (attitude[v] > cap)effpower = 0;
			else effpower = cap - attitude[v];
		}
	}
	//Finally, apply the effect.
	attitude[v] += effpower;
	if (attitude[v] < 0)attitude[v] = 0;
	if (attitude[v] > 100)attitude[v] = 100;
}

std::string getlaw(int l)
{
	extern map<short, string> getLawString;
	const string CONST_getnames043 = "Software Bugs";
	if (getLawString.count(l)) {
		return getLawString[l];
	}
	else {
		return CONST_getnames043;
	}
}
std::string cityname()
{
	extern vector<string> city_names;
	return pickrandom(city_names);
}

int getLawFromFlag(int type) {
	if (type == LAWFLAG_BURNFLAG) {
		return LAW_FLAGBURNING;
	}
	else if (type == LAWFLAG_HIREILLEGAL) {
		return LAW_IMMIGRATION;
	}
	return 0;
}
std::string getlawflag(int type)
{
	extern string findingBugs;
	extern map<short, string> getLawFlagString;
	extern map<short, map<short, string> > getLawFlagStringFull;
	extern short lawList[LAWNUM];
	if (getLawFlagStringFull.count(type)) {
		return getLawFlagStringFull[type][lawList[getLawFromFlag(type)]];
	}
	else
		if (getLawFlagString.count(type)) {
			return getLawFlagString[type];
		}
		else {
			return findingBugs;
		}
}

/* returns true if the entire site is not open to public */
char disguisesite(long type)
{
	switch (type)
	{
	case SITE_LABORATORY_COSMETICS:
	case SITE_LABORATORY_GENETIC:
	case SITE_GOVERNMENT_PRISON:
	case SITE_GOVERNMENT_INTELLIGENCEHQ:
	case SITE_INDUSTRY_SWEATSHOP:
	case SITE_INDUSTRY_POLLUTER:
	case SITE_CORPORATE_HEADQUARTERS:
	case SITE_CORPORATE_HOUSE:
	case SITE_BUSINESS_CIGARBAR:
		return 1;
	}
	return 0;
}

/* common - random issue by public interest */
int randomissue(bool core_only)
{
	extern char newscherrybusted;
	extern char endgamestate;
	extern short public_interest[VIEWNUM];
	int interest_array[VIEWNUM], total_interest = 0;
	int numviews = core_only ? VIEWNUM - 5 : ((endgamestate >= ENDGAME_CCS_DEFEATED || newscherrybusted < 2) ? VIEWNUM - 1 : VIEWNUM);
	for (int i = 0; i < numviews; i++)
	{
		interest_array[i] = public_interest[i] + total_interest + 25;
		total_interest += public_interest[i] + 25;
	}
	int roll = LCSrandom(total_interest);
	for (int i = 0; i < numviews; i++) if (roll < interest_array[i]) return i;
	return VIEW_MOOD;
}


/* politics -- gets the leaning of an issue voter for an election */
int getswingvoter(bool stalin)
{
	extern short attitude[VIEWNUM];
	// Take a random voter, calculate how liberal or conservative they are
	// If stalin parameter is true, it calculates how libertarian or Stalinist they are instead
	int bias = publicmood(-1 - stalin) - LCSrandom(100), vote = -2;
	if (bias > 25)bias = 25;
	if (bias < -25)bias = -25;
	// Each issue they roll for their opinion on a 50-point subset of the
	// spectrum, determined by bias -- high liberal/libertarian bias only rolls on the
	// liberal/libertarian end of the spectrum, high conservative/Stalinist bias only rolls on
	// the conservative/Stalinist end of the spectrum
	for (int i = 0; i < 4; i++)
	{
		int issue = randomissue(true);
		if (25 + LCSrandom(50) - bias < ((stalin&&stalinview(issue, false)) ? 100 - attitude[issue] : attitude[issue])) vote++;
	}
	return vote;
}
/* politics - calculate presidential approval */
int presidentapproval()
{
	extern short presparty;
	extern short exec[EXECNUM];
	//Calculate Presidential approval rating
	int approval = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (i % 2 == 0 && LCSrandom(2)) approval++;    // Partyline supporter (~25%)
		else if (i % 2 == 1 && LCSrandom(2)) continue; // Partyline opponent  (~25%)
		else                                    // Swing issue voter   (~50%) (should be more than in the real election)
		{
			// Get their leanings as an issue voter
			int vote = getswingvoter(exec[EXEC_PRESIDENT] == ALIGN_STALINIST);
			// If their views are close to the President's views, they should
			// approve, but might not if their party leaning conflicts with
			// the president's
			// Moderate president from the Conservative party is only supported
			// by moderates and Conservatives
			// Moderate president from the Liberal party is only supported
			// by moderates and Liberals
			int presalign = exec[EXEC_PRESIDENT] == ALIGN_STALINIST ? ALIGN_ARCHCONSERVATIVE : exec[EXEC_PRESIDENT];
			if (abs(presalign - vote) <= 1 && (presparty != LIBERAL_PARTY ? vote <= 0 : vote >= 0)) approval++;
		}
	}
	return approval;
}
/* politics -- gets the leaning of a partyline voter for an election */
int getsimplevoter(int leaning)
{
	extern short attitude[VIEWNUM];
	// no need for this to deal with Stalinism, this function deliberately only deals with the liberal vs. conservative spectrum
	int vote = leaning - 1;
	for (int i = 0; i < 2; i++) if (LCSrandom(100) < attitude[randomissue(true)]) vote++;
	return vote;
}

const char* statename(int i)
{
	extern vector<string> listOfStates;
	if (i < 0 || i >= len(listOfStates)) i = LCSrandom(len(listOfStates));
	return listOfStates[i].data();
}
/* EndGameStatus - converts an integer into a roman numeral for amendments */
string romannumeral(int amendnum)
{
	string roman = "";
	while (amendnum >= 1000)
	{
		amendnum -= 1000;
		(roman += 'M');
	}
	if (amendnum >= 900)
	{
		amendnum -= 900;
		(roman += 'C');
		(roman += 'M');
	}
	if (amendnum >= 500)
	{
		amendnum -= 500;
		(roman += 'D');
	}
	if (amendnum >= 400)
	{
		amendnum -= 400;
		(roman += 'C');
		(roman += 'D');
	}
	while (amendnum >= 100)
	{
		amendnum -= 100;
		(roman += 'C');
	}
	if (amendnum >= 90)
	{
		amendnum -= 90;
		(roman += 'X');
		(roman += 'C');
	}
	if (amendnum >= 50)
	{
		amendnum -= 50;
		(roman += 'L');
	}
	if (amendnum >= 40)
	{
		amendnum -= 40;
		(roman += 'X');
		(roman += 'L');
	}
	while (amendnum >= 10)
	{
		amendnum -= 10;
		(roman += 'X');
	}
	if (amendnum >= 9)
	{
		amendnum -= 9;
		(roman += 'I');
		(roman += 'X');
	}
	if (amendnum >= 5)
	{
		amendnum -= 5;
		(roman += 'V');
	}
	if (amendnum >= 4)
	{
		amendnum -= 4;
		(roman += 'I');
		(roman += 'V');
	}
	while (amendnum >= 1)
	{
		amendnum -= 1;
		(roman += 'I');
	}
	return roman;
}
const string singleSpace = " ";
const string blankString = "";

//extern string closeParenthesis;
//extern string singleSpace;
void generate_name(char *first, char *last, char gender);
void firstname(char *str, char gender);
string lastname(bool archconservative);

/* fills a string with a proper name */
void generate_name(char *str, char gender)
{
	char first[80];
	char last[80];
	generate_name(first, last, gender);
	strcpy(str, first);
	strcat(str, singleSpace.data());
	strcat(str, last);
}
string generate_name(char gender) {
	char str[200];
	generate_name(str, gender);
	return str;
}
/* get a first and last name for the same person */
void generate_name(char *first, char *last, char gender)
{
	do {
		firstname(first, gender);
		strcpy(last, lastname(gender == GENDER_WHITEMALEPATRIARCH).data());
	} while (strcmp(first, last) == 0);
}
/* get a first, middle, and last name for the same person */
void generate_long_name(char *first, char *middle, char *last, char gender)
{
	// pick either male or female so we can have 75% chance of first and middle names having matching genders
	if (gender == GENDER_NEUTRAL)
		gender = (LCSrandom(2) ? GENDER_MALE : GENDER_FEMALE);
	do {
		firstname(first, gender);
		if (LCSrandom(2)) // middle name is a first name
			firstname(middle, (gender == GENDER_WHITEMALEPATRIARCH || LCSrandom(2) ? gender : GENDER_NEUTRAL)); // 25% chance for middle name of other gender unless white male patriarch
		else // middle name is a last name
			strcpy(middle, lastname(gender == GENDER_WHITEMALEPATRIARCH).data());
		strcpy(last, lastname(gender == GENDER_WHITEMALEPATRIARCH).data());
	} while (strcmp(first, middle) == 0 && strcmp(first, last) == 0 && strcmp(middle, last) == 0);
}
/* gets a random first name */
void firstname(char *str, char gender)
{
	extern vector<string> male_first_names;
	extern vector<string> female_first_names;
	extern vector<string> gender_neutral_first_names;
	extern vector<string> great_white_male_patriarch_first_names;
	const string CONST_creaturenames009 = "Errol";
	strcpy(str, blankString.c_str());
	int roll, nametable;
	// If we don't care if the name is male or female, pick one randomly
	// This ensures gender balance in the names chosen
	if (gender == GENDER_NEUTRAL)
		gender = (LCSrandom(2) ? GENDER_MALE : GENDER_FEMALE);
	// For white male Arch-Conservative politicians
	if (gender == GENDER_WHITEMALEPATRIARCH)
		nametable = GENDER_WHITEMALEPATRIARCH;
	// Assign a name from the available names for each gender
	if (gender == GENDER_MALE)
	{
		// Roll on the number of gender-specific names,
		// plus the number of gender-neutral names
		roll = LCSrandom(len(male_first_names) +
			len(gender_neutral_first_names));
		// Decide whether to use a gender-specific name
		// or a gender-neutral name
		if (roll >= len(gender_neutral_first_names))
			nametable = GENDER_MALE;
		else
			nametable = GENDER_NEUTRAL;
	}
	else if (gender == GENDER_FEMALE)
	{
		// (Same here, just use the number of female names instead)
		roll = LCSrandom(len(female_first_names) +
			len(gender_neutral_first_names));
		if (roll >= len(gender_neutral_first_names))
			nametable = GENDER_FEMALE;
		else
			nametable = GENDER_NEUTRAL;
	}
	if (nametable == GENDER_MALE) {
		//string.data() returns the char* representation of the string
		strcat(str, pickrandom(male_first_names).data());
	}
	else if (nametable == GENDER_FEMALE) {
		strcat(str, pickrandom(female_first_names).data());
	}
	else if (nametable == GENDER_NEUTRAL) {
		strcat(str, pickrandom(gender_neutral_first_names).data());
	}
	else if (nametable == GENDER_WHITEMALEPATRIARCH) {
		strcat(str, pickrandom(great_white_male_patriarch_first_names).data());
	}
	else
		strcat(str, CONST_creaturenames009.c_str());
}
string lastname(bool archconservative)
//{{{ Last Name
{
	extern vector<string> regular_last_names;
	extern vector<string> archconservative_last_names;
	char str[80];
	strcpy(str, blankString.c_str());
	// For non-Arch-Conservatives, pick from ALL last names
	if (!archconservative)
	{
		// Roll on the number of non-Arch-Conservative last names,
		// plus the number of regular last names
		int roll = LCSrandom(len(regular_last_names) +
			len(archconservative_last_names));
		// Decide whether to use an Arch-Conservative last name
		// or a regular last name
		archconservative = (roll >= len(regular_last_names));
	}
	// Now the archconservative variable might be true even if the function wasn't called that way,
	// but if it WAS called that way it's definitely true... this way non-Arch-Conservatives get
	// random last names out of all the last names, while Arch-Conservatives are limited to their own
	// last names
	if (archconservative)
		strcat(str, pickrandom(archconservative_last_names).data());
	else
		strcat(str, pickrandom(regular_last_names).data());
	return str;
}


vector<int> maleOrFemale = {
	GENDER_MALE,
	GENDER_FEMALE
};
/* fills a string with a proper name */
void generate_name(char *str, char gender = GENDER_NEUTRAL);
/* get a first and last name for the same person */
void generate_name(char *first, char *last, char gender = GENDER_NEUTRAL);

string lastname(bool archconservative = false);
const char* statename(int state = -1);
void generate_long_name(char *first, char *middle, char *last, char gender = GENDER_NEUTRAL);

const string CONST_news700 = "her";
const string CONST_news378 = "his";
const string CONST_news647 = "[hurting spree]";

string constructVIEW_WOMEN()
{
	const string CONST_news284 = " Correctional Facility.&r";
	const string CONST_news283 = " yesterday at the ";
	const string CONST_news282 = ":";
	const string CONST_news281 = " was pronounced dead at ";
	const string CONST_news280 = " - An innocent citizen has been put to death in the electric chair. ";
	const string CONST_news279 = ", even though being gay is deviant, as we all know.";
	const string CONST_news278 = " is a known faggot";
	const string CONST_news277 = ", despite the fact that ";
	const string CONST_news276 = "aggravated nature of the offense";
	const string CONST_news275 = "prosecute this case as a hate crime, due to the ";
	const string CONST_news274 = " Authorities have stated that they will vigorously ";
	const string CONST_news273 = "at which point they were taken into custody. Nobody was seriously injured during the incident.";
	const string CONST_news272 = "The chase ended when ";
	const string CONST_news271 = " at the pursuing police cruisers. ";
	const string CONST_news270 = "taking swipes";
	const string CONST_news269 = "urinating out the window";
	const string CONST_news268 = "pissing out the window";
	const string CONST_news267 = "[relieving themselves] out the window";
	const string CONST_news266 = "throwing beer bottles";
	const string CONST_news265 = "throwing [juice boxes]";
	const string CONST_news264 = "murderers swerving wildly, ";
	const string CONST_news263 = " Witnesses of the freeway chase described the pickup of the alleged ";
	const string CONST_news262 = "have not yet been released.";
	const string CONST_news261 = "were apprehended after a high speed chase. Their names ";
	const string CONST_news260 = "A police spokesperson reported that four suspects ";
	const string CONST_news259 = " here yesterday. ";
	const string CONST_news258 = "a homosexual, was ";
	const string CONST_news257 = "a known homosexual, was ";
	const string CONST_news256 = "a known sexual deviant, was ";
	const string CONST_news255 = " children.&r";
	const string CONST_news250 = " and ";
	const string CONST_news249 = "wife";
	const string CONST_news248 = " is survived by ";
	const string CONST_news246 = "had been completed.&r";
	const string CONST_news245 = " surrendered without a struggle, reportedly saying that God's work ";
	const string CONST_news244 = " abortion doctors as opposed to arresting them.&r";
	const string CONST_news243 = " later admitted to being a rogue FBI vigilante, hunting down ";
	const string CONST_news242 = "called the police on a cellphone and they arrived shortly thereafter. ";
	const string CONST_news241 = "verses of the Bible at the stunned onlookers. Someone ";
	const string CONST_news240 = " remained at the scene after the shooting, screaming ";
	const string CONST_news239 = " Witnesses report that ";
	const string CONST_news238 = ", is in custody.&r";
	const string CONST_news237 = "The suspected shooter, ";
	const string CONST_news236 = " times and died immediately in the parking lot. ";
	const string CONST_news235 = " was hit ";
	const string CONST_news234 = "shots were fired from a nearby vehicle. ";
	const string CONST_news233 = " car when, according to police reports, ";
	const string CONST_news232 = " was walking to ";
	const string CONST_news230 = "Dr. ";
	const string CONST_news229 = " Clinic yesterday. ";
	const string CONST_news228 = "gunned down outside of the ";
	const string CONST_news227 = "A doctor that routinely performed abortions was ruthlessly ";
	const string CONST_news226 = "A doctor that routinely performed semi-legal abortions was ruthlessly ";
	const string CONST_news225 = "A doctor that routinely performed illegal abortions was ruthlessly ";
	const string CONST_news224 = "A doctor that routinely performed illegal abortion-murders was ruthlessly ";

	const string CONST_newsB925 = "husband";


	extern string commaSpace;
	extern int year;
	extern short presparty;
	extern short lawList[LAWNUM];

	extern string spaceDashSpace;
	extern string ampersandR;
	extern string singleDot;

	string story;
	//TODO IsaacG Migrate Strings?
	char str[200];
	story = cityname();
	story += spaceDashSpace;

	if (lawList[LAW_ABORTION] == -2) story += CONST_news224;
	else if (lawList[LAW_ABORTION] == -1) story += CONST_news225;
	else if (lawList[LAW_ABORTION] == 0) story += CONST_news226;
	else story += CONST_news227 \
		+ CONST_news228;
	strcpy(str, lastname(true).data());
	story += str \
		+ CONST_news229 \
		+ CONST_news230;

	char dstr[200], dstr2[200];
	const char gn = pickrandom(maleOrFemale);

	generate_name(dstr, dstr2, gn);

	story += dstr \
		+ singleSpace \
		+ dstr2;
	char gen[200];
	strcpy(gen, (gn == GENDER_FEMALE ? CONST_news700 : CONST_news378).data());

	story += CONST_news232 \
		+ gen;//TODO() Add more variety, not just in the parking lot.
	story += CONST_news233 \
		+ CONST_news234 \
		+ dstr2 \
		+ CONST_news235 \
		+ tostring(LCSrandom(15) + 3) \
		+ CONST_news236 \
		+ CONST_news237;

	char str2[200];
	generate_name(str, str2);

	story += str \
		+ singleSpace \
		+ str2 \
		+ CONST_news238 \
		+ CONST_news239 \
		+ str2 \
		+ CONST_news240 \
		+ CONST_news241 \
		+ CONST_news242 \
		+ str2;

	if (lawList[LAW_WOMEN] == -2)
	{
		story += CONST_news243 \
			+ CONST_news244;
	}
	else
	{
		story += CONST_news245 \
			+ CONST_news246;
	}

	story += singleSpace \
		+ dstr2 \
		+ CONST_news248 \
		+ gen \
		+ singleSpace;

	char spouse = pickrandom(maleOrFemale);
	if (lawList[LAW_GAY] <= 1)
		spouse = (gn == GENDER_FEMALE ? GENDER_MALE : GENDER_FEMALE);

	story += (spouse == GENDER_FEMALE ? CONST_news249 : CONST_newsB925) \
		+ CONST_news250;

	vector<string> two_to_five = {
	"two",
		"three",
		"four",
		"five"
	};
	story += pickrandom(two_to_five) \
		+ CONST_news255;

	return story;
}
string constructVIEW_GAY()
{
	const string CONST_news279 = ", even though being gay is deviant, as we all know.";
	const string CONST_news278 = " is a known faggot";
	const string CONST_news277 = ", despite the fact that ";
	const string CONST_news276 = "aggravated nature of the offense";
	const string CONST_news275 = "prosecute this case as a hate crime, due to the ";
	const string CONST_news274 = " Authorities have stated that they will vigorously ";
	const string CONST_news273 = "at which point they were taken into custody. Nobody was seriously injured during the incident.";
	const string CONST_news272 = "The chase ended when ";
	const string CONST_news271 = " at the pursuing police cruisers. ";
	const string CONST_news270 = "taking swipes";
	const string CONST_news269 = "urinating out the window";
	const string CONST_news268 = "pissing out the window";
	const string CONST_news267 = "[relieving themselves] out the window";
	const string CONST_news266 = "throwing beer bottles";
	const string CONST_news265 = "throwing [juice boxes]";
	const string CONST_news264 = "murderers swerving wildly, ";
	const string CONST_news263 = " Witnesses of the freeway chase described the pickup of the alleged ";
	const string CONST_news262 = "have not yet been released.";
	const string CONST_news261 = "were apprehended after a high speed chase. Their names ";
	const string CONST_news260 = "A police spokesperson reported that four suspects ";
	const string CONST_news259 = " here yesterday. ";
	const string CONST_news258 = "a homosexual, was ";
	const string CONST_news257 = "a known homosexual, was ";
	const string CONST_news256 = "a known sexual deviant, was ";


	extern string commaSpace;
	extern int year;
	extern short presparty;
	extern short lawList[LAWNUM];
	extern vector<string> vigilante_murder;
	extern vector<string> why_chase_ended;

	extern string spaceDashSpace;
	extern string ampersandR;
	extern string singleDot;

	string story;
	story = cityname();
	story += spaceDashSpace;

	char dstr[200], dstr2[200];
	generate_name(dstr, dstr2);

	story += dstr \
		+ singleSpace \
		+ dstr2 \
		+ commaSpace;

	if (lawList[LAW_GAY] == -2) story += CONST_news256;
	else if (lawList[LAW_GAY] == -1) story += CONST_news257;
	else story += CONST_news258 \
		+ pickrandom(vigilante_murder) \
		+ CONST_news259 \
		+ CONST_news260 \
		+ CONST_news261 \
		+ CONST_news262 \
		+ ampersandR \
		+ CONST_news263 \
		+ CONST_news264;

	switch (LCSrandom(3))
	{
	case 0:
		if (lawList[LAW_FREESPEECH] == -2) story += CONST_news265;
		else story += CONST_news266;
		break;
	case 1:
		if (lawList[LAW_FREESPEECH] == -2) story += CONST_news267;
		else if (lawList[LAW_FREESPEECH] == 2) story += CONST_news268;
		else story += CONST_news269;
		break;
	case 2: story += CONST_news270; break;
	}

	story += CONST_news271 \
		+ CONST_news272 \
		+ pickrandom(why_chase_ended) \
		+ " " \
		+ CONST_news273 \
		+ ampersandR \
		+ CONST_news274 \
		+ CONST_news275 \
		+ CONST_news276;

	if (lawList[LAW_GAY] == -2 && lawList[LAW_FREESPEECH] != -2)
	{
		story += CONST_news277 \
			+ dstr \
			+ singleSpace \
			+ dstr2 \
			+ CONST_news278;
	}
	else if (lawList[LAW_GAY] == -2)story += CONST_news279;
	else story += singleDot \
		+ ampersandR;

	return story;
}
string constructVIEW_FREESPEECH()
{
	const string CONST_news441 = "_";

	const string CONST_news345 = "?";
	const string CONST_news344 = "Mamma, why did they kill ";
	const string CONST_news343 = " dead?";
	const string CONST_news342 = "Mamma, is ";
	const string CONST_news340 = "many area children spontaneously broke into tears. One child was ";
	const string CONST_news339 = " When the decision to ban the book was announced yesterday, ";
	const string CONST_news338 = " as key evidence of the dark nature of the book.";
	const string CONST_news337 = "a child that ";
	const string CONST_news336 = "a child that said a magic spell at her parents";
	const string CONST_news335 = "a child that swore in class";
	const string CONST_news334 = "In their complaint, the groups cited an incident involving ";
	const string CONST_news332 = "some conservatives feel that the books ";
	const string CONST_news331 = "Although the series is adored by children worldwide, ";
	const string CONST_news329 = ". ";
	const string CONST_news328 = " author ";
	const string CONST_news327 = "_, is the third in an immensely popular series by ";
	const string CONST_news325 = "_and_the_";
	const string CONST_news322 = " The book, ";
	const string CONST_news321 = "the city bowed to pressure from religious groups.";
	const string CONST_news320 = " - A children's story has been removed from libraries here after ";

	const string CONST_newsX02 = "heard saying, \"";

	const string CONST_news1030 = "\"";

	const string CONST_news485 = ". ";


	extern string commaSpace;
	extern int year;
	extern short presparty;
	extern short lawList[LAWNUM];
	extern vector<string> vigilante_murder;
	extern vector<string> why_chase_ended;
	extern vector<string> book_title;
	extern vector<string> book_title_2;
	extern vector<string> random_nationality;
	extern vector<string> conservative_oppose_book;

	extern string spaceDashSpace;
	extern string ampersandR;
	extern string singleDot;
	extern vector<string> petty_violence;
	extern vector<string> his_her;
	extern vector<string> older_younger;
	extern vector<string> brother_sister;

	string story;
	story = cityname();
	story += CONST_news320 \
		+ CONST_news321 \
		+ ampersandR \
		+ CONST_news322 \
		+ CONST_news441;

	char dstr[200], nstr[200];

	generate_name(nstr, dstr);

	story += nstr \
		+ CONST_news441 \
		+ dstr \
		+ CONST_news325 \
		+ pickrandom(book_title) \
		+ CONST_news441 \
		+ pickrandom(book_title_2) \
		+ CONST_news327 \
		+ pickrandom(random_nationality) \
		+ CONST_news328;

	char c[2] = { 0,0 };

	c[0] = 'A' + LCSrandom(26);

	story += c \
		+ singleDot;

	c[0] = 'A' + LCSrandom(26);

	story += c \
		+ CONST_news329;

	strcpy(dstr, lastname().data());

	story += dstr \
		+ CONST_news485 \
		+ CONST_news331 \
		+ CONST_news332 \
		+ pickrandom(conservative_oppose_book) \
		+ singleSpace \
		+ CONST_news334;

	switch (LCSrandom(3))
	{
	case 0: story += CONST_news335; break;
	case 1: story += CONST_news336; break;
	case 2: story += CONST_news337 \
		+ pickrandom(petty_violence) \
		+ singleSpace \
		+ pickrandom(his_her) \
		+ singleSpace \
		+ pickrandom(older_younger) \
		+ singleSpace \
		+ pickrandom(brother_sister);
		break;
	}

	story += CONST_news338 \
		+ ampersandR \
		+ CONST_news339 \
		+ CONST_news340 \
		+ CONST_newsX02;

	switch (LCSrandom(2))
	{
	case 0:
		story += CONST_news342 \
			+ nstr \
			+ CONST_news343;
		break;
	case 1:
		story += CONST_news344 \
			+ nstr \
			+ CONST_news345;
		break;
	}

	story += CONST_news1030 \
		+ ampersandR;

	return story;
}
const string CONST_news1030 = "\"";
string constructVIEW_DEATHPENALTY()
{
	const string CONST_news458 = ".\"";

	const string CONST_news306 = "can be put to death in this country.";
	const string CONST_news305 = "tragedy, it will be that our nation is now evaluating the ease with which people ";
	const string CONST_news304 = "and more events are expected this evening. If there is a bright side to be found from this ";
	const string CONST_news303 = " Candlelight vigils were held throughout the country last night during the execution, ";
	const string CONST_news301 = "The family wants closure. We don't have time for another trial";
	const string CONST_news300 = "End of story";
	const string CONST_news299 = "Assassin, serial killer, either way ÄÄ guilty. ";
	const string CONST_news298 = "The convict is always referred to by three names. ";
	const string CONST_news297 = "Let's not forget the convict is colored. You know how their kind are";
	const string CONST_news295 = "spokesperson for the governor saying, ";
	const string CONST_news294 = "The state still went through with the execution, with a ";
	const string CONST_news293 = " was framed. ";
	const string CONST_news292 = "an admission from a former prosecutor that ";
	const string CONST_news291 = "a battery of negative DNA tests. ";
	const string CONST_news290 = "a confession from another convict. ";
	const string CONST_news289 = "have been produced, including ";
	const string CONST_news288 = "Since then, numerous pieces of exculpatory evidence ";
	const string CONST_news287 = " of 13 serial murders. ";
	const string CONST_news286 = " was convicted in ";
	const string CONST_news284 = " Correctional Facility.&r";
	const string CONST_news283 = " yesterday at the ";
	const string CONST_news282 = ":";
	const string CONST_news281 = " was pronounced dead at ";
	const string CONST_news280 = " - An innocent citizen has been put to death in the electric chair. ";



	extern string commaSpace;
	extern int year;
	extern short presparty;
	extern short lawList[LAWNUM];

	extern string spaceDashSpace;
	extern string ampersandR;
	extern string singleDot;

	extern vector<string> judge_with_prostitute;
	extern vector<string> judge_with_prostitute_no_free_speech;
	extern vector<string> judge_with_prostitute_full_free_speech;

	extern vector<string> AMorPM;
	string story;

	story += statename() \
		+ CONST_news280;

	char dstr[200], dstr2[200], dstr3[200];

	generate_long_name(dstr, dstr2, dstr3);

	story += dstr \
		+ singleSpace \
		+ dstr2 \
		+ singleSpace \
		+ dstr3 \
		+ CONST_news281 \
		+ tostring(LCSrandom(12) + 1) \
		+ CONST_news282 \
		+ tostring(LCSrandom(60)) \
		+ pickrandom(AMorPM) \
		+ CONST_news283;

	char jstr[200];

	strcpy(jstr, lastname(true).data());

	story += jstr \
		+ CONST_news284 \
		+ singleSpace \
		+ dstr3 \
		+ CONST_news286 \
		+ tostring(year - LCSrandom(11) - 10) \
		+ CONST_news287 \
		+ CONST_news288 \
		+ CONST_news289;

	switch (LCSrandom(3))
	{
	case 0: story += CONST_news290;
		break;
	case 1: story += CONST_news291;
		break;
	case 2:
		story += CONST_news292 \
			+ dstr3 \
			+ CONST_news293;
		break;
	}

	story += CONST_news294 \
		+ CONST_news295 \
		+ CONST_news1030;

	switch (LCSrandom(3))
	{
	case 0: story += CONST_news297;
		break;
	case 1:
		story += CONST_news298 \
			+ CONST_news299 \
			+ CONST_news300;
		break;
	case 2: story += CONST_news301;
		break;
	}

	story += CONST_news458 \
		+ ampersandR \
		+ CONST_news303 \
		+ CONST_news304 \
		+ CONST_news305 \
		+ CONST_news306 \
		+ ampersandR;

	return story;
}
string constructVIEW_INTELLIGENCE()
{
	const string CONST_news458 = ".\"";

	const string CONST_news318 = "You think about that before you continue slanging accusations";
	const string CONST_news317 = "these files deal with the one and not the other. ";
	const string CONST_news316 = "It might be a bit presumptive to assume that ";
	const string CONST_news315 = "Well, you know, there's privacy, and there's privacy. ";
	const string CONST_news313 = " The FBI refused to comment initially, but when confronted with the information, ";
	const string CONST_news312 = "\"deal with the undesirables\", although this phrase is not clarified. ";
	const string CONST_news311 = " More disturbingly, the files make reference to a plan to ";
	const string CONST_news310 = "unions, working for liberal organizations ÄÄ even ";
	const string CONST_news309 = "The files contain information on which people have been attending demonstrations, organizing ";
	const string CONST_news308 = "This newspaper yesterday received a collection of files from a source in the Federal Bureau of Investigations. ";
	const string CONST_news307 = "Washington, DC - The FBI might be keeping tabs on you. ";

	const string CONST_newsX01 = "a spokesperson stated, \"";

	const string CONST_news1030 = "\"";

	const string CONST_news485 = ". ";


	extern string commaSpace;
	extern int year;
	extern short presparty;
	extern short lawList[LAWNUM];

	extern string spaceDashSpace;
	extern string ampersandR;
	extern string singleDot;

	extern vector<string> liberalCrime;

	string story;
	story += CONST_news307 \
		+ CONST_news308 \
		+ CONST_news309 \
		+ CONST_news310 \
		+ pickrandom(liberalCrime) \
		+ ampersandR \
		+ CONST_news311 \
		+ CONST_news312 \
		+ ampersandR \
		+ CONST_news313 \
		+ CONST_newsX01 \
		+ CONST_news315 \
		+ CONST_news316 \
		+ CONST_news317 \
		+ CONST_news318 \
		+ CONST_news458 \
		+ ampersandR;
	return story;
}

string constructVIEW_JUSTICES()
{
	extern string ampersandR;

	const string CONST_news361 = "the judge would be going on a Bible retreat for a few weeks to ";
	const string CONST_news360 = " could not be reached for comment, although an aid stated that ";
	const string CONST_news358 = " in exchange for their silence.";
	const string CONST_news357 = " reportedly offered ";
	const string CONST_news355 = "when police broke into the hotel room they saw ";
	const string CONST_news354 = "According to sources familiar with the particulars, ";
	const string CONST_news353 = " last week in a hotel during a police sting operation. ";
	const string CONST_news352 = ", was found with ";
	const string CONST_news351 = ", who once ";
	const string CONST_news349 = " has resigned in disgrace after being caught with a prostitute.";
	const string CONST_news348 = " has resigned in disgrace after being caught with a [civil servant].";
	const string CONST_news347 = " - Conservative federal judge ";


	const string CONST_newsB928 = "\"Make things right with the Almighty Father.\"";

	extern string commaSpace;
	extern int year;
	extern short presparty;
	extern short lawList[LAWNUM];

	extern vector<string> judge_with_prostitute;
	extern vector<string> judge_with_prostitute_no_free_speech;
	extern vector<string> judge_with_prostitute_full_free_speech;
	extern vector<string> crazy_conservative_act;

	extern vector<string> bribe_officers;

	string story;
	story = cityname();
	story += CONST_news347;

	char dstr[200], dstr2[200];

	generate_name(dstr, dstr2, GENDER_WHITEMALEPATRIARCH);

	story += dstr \
		+ singleSpace \
		+ dstr2;

	if (lawList[LAW_FREESPEECH] == -2) story += CONST_news348;
	else story += CONST_news349 \
		+ ampersandR \
		+ singleSpace \
		+ dstr2 \
		+ CONST_news351 \
		+ pickrandom(crazy_conservative_act) \
		+ CONST_news352;

	char pstr[200], pstr2[200];
	generate_name(pstr, pstr2);

	story += pstr \
		+ singleSpace \
		+ pstr2 \
		+ CONST_news353 \
		+ CONST_news354 \
		+ CONST_news355;

	if (lawList[LAW_FREESPEECH] == -2) {
		story += pickrandom(judge_with_prostitute_no_free_speech);
	}
	else if (lawList[LAW_FREESPEECH] == 2) {
		story += pickrandom(judge_with_prostitute_full_free_speech);
	}
	else {
		story += pickrandom(judge_with_prostitute);
	}

	story += singleSpace \
		+ pstr2 \
		+ CONST_news357 \
		+ pickrandom(bribe_officers) \
		+ CONST_news358 \
		+ ampersandR \
		+ singleSpace \
		+ dstr2 \
		+ CONST_news360 \
		+ CONST_news361 \
		+ CONST_newsB928 \
		+ ampersandR;

	return story;
}
string constructVIEW_AMRADIO()
{
	const string CONST_news390 = "to the FM band.";
	const string CONST_news389 = "pastures. Of these, many said that they would be switching over ";
	const string CONST_news388 = "have decided to leave the program for saner ";
	const string CONST_news387 = "fully half of the host's most loyal supporters ";
	const string CONST_news386 = "According to a poll completed yesterday, ";
	const string CONST_news385 = "the damage might already be done. ";
	const string CONST_news384 = " issued an apology later in the program, but ";
	const string CONST_news381 = " g*dd*mn mind";
	const string CONST_news380 = " [gosh darn] mind";
	const string CONST_news379 = " goddamn mind";
	const string CONST_news377 = "lost ";
	const string CONST_news376 = " had ";
	const string CONST_news374 = "\", a former fan of the show, ";
	const string CONST_news373 = "liberal media establishment!";
	const string CONST_news372 = "current president!";
	const string CONST_news371 = "and the greatest living example of a reverse racist is the ";
	const string CONST_news368 = "'s monologue for the evening began the way that fans ";
	const string CONST_news366 = "\".";
	const string CONST_news364 = " went off for fifteen minutes in an inexplicable rant ";
	const string CONST_news363 = " - Well-known AM radio personality ";

	const string CONST_newsX03 = "two nights ago during the syndicated radio program \"";
	const string CONST_newsX04 = "had come to expect, with attacks on the \"liberal media establishment\"";
	const string CONST_newsX05 = "the \"elite liberal agenda\". But when the radio icon said, \"";
	const string CONST_newsX06 = ", knew that \"";
	const string CONST_newsX07 = ". After that, it just got worse and worse.\"";


	extern string commaSpace;
	extern int year;
	extern short presparty;
	extern short lawList[LAWNUM];

	extern vector<string> radio_name;
	extern vector<string> radio_name_2;

	extern string spaceDashSpace;
	extern string ampersandR;
	extern string singleDot;

	extern vector<string> radio_host_crazy_quote;
	extern vector<string> radio_host_lost_mind;

	extern vector<string> my_idol;
	string story;
	story = cityname();
	story += CONST_news363;

	char dstr[200], dstr2[200];
	generate_name(dstr, dstr2, GENDER_WHITEMALEPATRIARCH);

	story += dstr \
		+ singleSpace \
		+ dstr2 \
		+ CONST_news364 \
		+ CONST_newsX03 \
		+ pickrandom(radio_name) \
		+ singleSpace \
		+ pickrandom(radio_name_2) \
		+ CONST_news366 \
		+ ampersandR \
		+ singleSpace \
		+ dstr2 \
		+ CONST_news368 \
		+ CONST_newsX04 \
		+ CONST_newsX05;

	switch (LCSrandom(radio_host_crazy_quote.size()))
	{
	case 0:
		story += CONST_news371;
		if (presparty != CONSERVATIVE_PARTY) story += CONST_news372; // Limbaugh
		else story += CONST_news373;
		break;
	default:
		story += pickrandom(radio_host_crazy_quote);
		break;
	}

	story += CONST_news374;

	char nstr[200], nstr2[200];
	generate_name(nstr, nstr2);

	story += nstr \
		+ singleSpace \
		+ nstr2 \
		+ CONST_newsX06 \
		+ pickrandom(my_idol) \
		+ CONST_news376;

	switch (LCSrandom(radio_host_lost_mind.size()))
	{
	case 0:
		story += CONST_news377 \
			+ CONST_news378; // the AM personality's a white male patriarch
		if (lawList[LAW_FREESPEECH] == 2)story += CONST_news379;
		else if (lawList[LAW_FREESPEECH] == -2)story += CONST_news380;
		else story += CONST_news381;
		break;
	default:
		story += pickrandom(radio_host_lost_mind);
	}

	story += CONST_newsX07 \
		+ ampersandR \
		+ singleSpace \
		+ dstr2 \
		+ CONST_news384 \
		+ CONST_news385 \
		+ CONST_news386 \
		+ CONST_news387; // XXX How many of them switch should
	story += CONST_news388; // depend on [LAW_FREESPEECH]
	story += CONST_news389 \
		+ CONST_news390 \
		+ ampersandR;

	return story;
}
string constructVIEW_GUNCONTROL()
{
	const string CONST_news433 = " was disturbingly obsessed with guns and death.&r";
	const string CONST_news432 = "she";
	const string CONST_news431 = "reports indicate that the student kept a journal that showed ";
	const string CONST_news430 = " Investigators are currently searching the student's belongings, and initial ";
	const string CONST_news429 = " shortly afterwards.&r";
	const string CONST_news428 = " committed suicide";
	const string CONST_news427 = " [feel deeply asleep]";
	const string CONST_news426 = " and wounded dozens more. ";
	const string CONST_news424 = "[hurt some people]. ";
	const string CONST_news423 = " When the police arrived, the student had already ";
	const string CONST_news422 = " as well.&r";
	const string CONST_news421 = "shot";
	const string CONST_news420 = "[unfortunately harmed]";
	const string CONST_news419 = ", they were ";
	const string CONST_news417 = "When other students tried to wrestle the weapons away from ";
	const string CONST_news416 = " students and teachers inside. ";
	const string CONST_news415 = "spraying bullets at";
	const string CONST_news414 = "[scaring]";
	const string CONST_news413 = "classrooms, ";
	const string CONST_news412 = " while classes were in session, then systematically started breaking into ";
	const string CONST_news411 = "university ";
	const string CONST_news410 = "school ";
	const string CONST_news409 = " entered the ";
	const string CONST_news407 = " University";
	const string CONST_news406 = " High School";
	const string CONST_news405 = " Middle School";
	const string CONST_news404 = " Elementary School";
	const string CONST_news403 = " more than a dozen classmates and two teachers at ";
	const string CONST_news402 = "mow down";
	const string CONST_news401 = "[scare]";
	const string CONST_news400 = ", used a variety of guns to ";
	const string CONST_news398 = "university";
	const string CONST_news397 = "high school";
	const string CONST_news396 = "middle school";
	const string CONST_news395 = "elementary school";
	const string CONST_news394 = " at a local ";
	const string CONST_news393 = "shooting rampage";
	const string CONST_news391 = "A student has gone on a ";

	const string CONST_news485 = ". ";

	const string CONST_newsB943 = "him";
	const string CONST_news864 = "killed ";
	const string CONST_newsB935 = "he";

	extern string commaSpace;
	extern int year;
	extern short presparty;
	extern short lawList[LAWNUM];

	extern string spaceDashSpace;
	extern string ampersandR;
	extern string singleDot;

	string story;
	const int schtype = LCSrandom(4);

	story = cityname();

	story += spaceDashSpace \
		+ CONST_news391;

	if (lawList[LAW_FREESPEECH] == -2) story += CONST_news647;
	else story += CONST_news393 \
		+ CONST_news394;

	switch (schtype)
	{
	case 0: story += CONST_news395; return story;
	case 1: story += CONST_news396; return story;
	case 2: story += CONST_news397; return story;
	case 3: story += CONST_news398; return story;
	}

	story += CONST_news485;

	char dstr[200], dstr2[200];
	const char dg = pickrandom(maleOrFemale);
	generate_name(dstr, dstr2, dg);

	story += dstr \
		+ singleSpace \
		+ dstr2 \
		+ commaSpace;
	//6->11,10->15,14->19,18->23
	story += 6 + (schtype * 4) + LCSrandom(6); //generate an age that would roughly correspond to the schtype
	story += CONST_news400;

	if (lawList[LAW_FREESPEECH] == -2)story += CONST_news401;
	else story += CONST_news402 \
		+ CONST_news403;

	char jstr[200];

	strcpy(jstr, lastname(true).data());
	story += jstr;

	switch (schtype)
	{
	case 0: story += CONST_news404; return story;
	case 1: story += CONST_news405; return story;
	case 2: story += CONST_news406; return story;
	case 3: story += CONST_news407; return story;
	}

	story += CONST_news485 \
		+ dstr2 \
		+ CONST_news409;

	if (schtype != 3) story += CONST_news410;
	else story += CONST_news411 \
		+ CONST_news412 \
		+ CONST_news413;

	if (lawList[LAW_FREESPEECH] == -2) story += CONST_news414;
	else story += CONST_news415 \
		+ CONST_news416 \
		+ CONST_news417 \
		+ (dg == GENDER_FEMALE ? CONST_news700 : CONST_newsB943) \
		+ CONST_news419;

	if (lawList[LAW_FREESPEECH] == -2) story += CONST_news420;
	else story += CONST_news421 \
		+ CONST_news422 \
		+ CONST_news423;

	if (lawList[LAW_FREESPEECH] == -2) story += CONST_news424;
	else
	{
		story += CONST_news864 \
			+ tostring(2 + LCSrandom(30)) \
			+ CONST_news426;
	}

	story += dstr;

	if (lawList[LAW_FREESPEECH] == -2)story += CONST_news427;
	else story += CONST_news428 \
		+ CONST_news429 \
		+ CONST_news430 \
		+ CONST_news431 \
		+ (dg == GENDER_FEMALE ? CONST_news432 : CONST_newsB935) \
		+ CONST_news433;

	return story;
}
string constructVIEW_PRISONS()
{
	const string CONST_news458 = ".\"";
	const string CONST_news457 = " choice, and I would only have a few seconds before they made it for me";
	const string CONST_news456 = "helluva";
	const string CONST_news455 = "[difficult]";
	const string CONST_news454 = " the other. A ";
	const string CONST_news453 = "AIDS";
	const string CONST_news452 = "GRIDS";
	const string CONST_news451 = "Maybe lose an eye the one way, maybe catch ";
	const string CONST_news450 = "My shank's under the mattress. Better to be brave and fight or chicken out and let them take it? ";
	const string CONST_news449 = "with dark glares of bare lust, as football players might stare at a stupefied, drunken, helpless teenager. ";
	const string CONST_news448 = "I was trapped with them now. There were three, looking me over ";
	const string CONST_news447 = "coming to a halt with a deafening clang that said it all ÄÄ ";
	const string CONST_news446 = "The steel bars grated forward in their rails, ";
	const string CONST_news445 = " Take this excerpt, \"";
	const string CONST_news444 = "_.&r";
	const string CONST_news443 = "Buttlord";
	const string CONST_news442 = "[Bum]lord";
	const string CONST_news441 = "_";
	const string CONST_news440 = "'s new tour-de-force, _";
	const string CONST_news438 = "have these works been as poignant as ";
	const string CONST_news437 = "prison theme lately in its offerings for mass consumption, rarely ";
	const string CONST_news436 = "Although popular culture has used, or perhaps overused, the ";
	const string CONST_news435 = "detail what goes on behind bars. ";
	const string CONST_news434 = " - A former prisoner has written a book describing in horrifying ";


	extern string commaSpace;
	extern int year;
	extern short presparty;
	extern short lawList[LAWNUM];
	extern vector<string> prison_book_title;
	extern vector<string> prison_book_title_2;
	extern string spaceDashSpace;
	extern string ampersandR;
	extern string singleDot;

	string story;
	story = cityname();
	story += CONST_news434 \
		+ CONST_news435 \
		+ CONST_news436 \
		+ CONST_news437 \
		+ CONST_news438;
	char dstr[200], dstr2[200];
	generate_name(dstr, dstr2); // allow either gender (look up 'Orange is the New Black' online to see why)
	story += dstr \
		+ singleSpace \
		+ dstr2 \
		+ CONST_news440 \
		+ pickrandom(prison_book_title) \
		+ CONST_news441;
	if (!LCSrandom(prison_book_title_2.size())) {
		string story;
		if (lawList[LAW_FREESPEECH] == -2) story += CONST_news442;
		else story += CONST_news443;
	}
	else {
		string story;
		story += pickrandom(prison_book_title_2);
	}
	story += CONST_news444 \
		+ CONST_news445;//TODO() Add more excerpts, more variety.
	story += CONST_news446 \
		+ CONST_news447 \
		+ CONST_news448 \
		+ CONST_news449 \
		+ CONST_news450 \
		+ CONST_news451;
	if (lawList[LAW_GAY] == -2)story += CONST_news452;// Gay Related Immunodeficiency Syndrome, an obsoleted/politically incorrect name for AIDS.
	else story += CONST_news453 \
		+ CONST_news454;
	if (lawList[LAW_FREESPEECH] == -2)story += CONST_news455;
	else story += CONST_news456 \
		+ CONST_news457 \
		+ CONST_news458 \
		+ ampersandR;
	return story;
}

string constructPositiveEventStory(const short view) {

	string story = blankString;

	switch (view)
	{
	case VIEW_WOMEN:
	{
		story += constructVIEW_WOMEN();
		break;
	}
	case VIEW_GAY:
	{
		story += constructVIEW_GAY();
		break;
	}
	case VIEW_FREESPEECH:
	{
		story += constructVIEW_FREESPEECH();
		break;
	}
	case VIEW_DEATHPENALTY:
	{
		story += constructVIEW_DEATHPENALTY();

		break;
	}
	case VIEW_INTELLIGENCE:
	{
		story += constructVIEW_INTELLIGENCE();
		break;
	}

	case VIEW_JUSTICES:
	{
		story += constructVIEW_JUSTICES();
		break;
	}
	case VIEW_AMRADIO:
	{
		story += constructVIEW_AMRADIO();
		break;
	}
	case VIEW_GUNCONTROL:
	{
		story += constructVIEW_GUNCONTROL();
		break;
	}
	case VIEW_PRISONS:
	{
		story += constructVIEW_PRISONS();
		break;
	}
	}
	return story;
}



string constructNegativeVIEW_ANIMALRESEARCH()
{

	extern vector<string> animal_research_country;
	extern vector<string> drug_name;
	extern vector<string> drug_name_2;
	extern vector<string> chimp_drug_impact;
	extern vector<string> chimp_drug_horror;


	const string CONST_news492 = " The first phase of human trials is slated to begin in a few months.";
	const string CONST_news490 = "I think the media should be focusing on the enormous benefits of this drug.";
	const string CONST_news489 = "While we understand your concerns, any worries are entirely unfounded. ";
	const string CONST_news488 = ". We have a very experienced research team. ";
	const string CONST_news487 = "a spokesperson for the research team stated that, \"It really isn't so bad as all that. Chimpanzees are very resilient creatures. ";
	const string CONST_news486 = "Fielding questions about the ethics of their experiments from reporters during a press conference yesterday, ";
	const string CONST_news485 = ". ";
	const string CONST_news484 = " Along with bonobos, chimpanzees are our closest cousins";
	const string CONST_news482 = "corrects erectile dysfunction in chimpanzees";
	const string CONST_news481 = "[helps chimpanzees reproduce]";
	const string CONST_news480 = ", the drug apparently ";
	const string CONST_news479 = "Anal";
	const string CONST_news478 = "Bum-Bum";
	const string CONST_news477 = "Called ";
	const string CONST_news476 = "here report that they have discovered an amazing new wonder drug. ";
	const string CONST_news475 = " report that they have discovered an amazing new wonder drug. ";
	const string CONST_news474 = "from ";
	const string CONST_news473 = " - Researchers ";

	extern string singleDot;
	extern short lawList[LAWNUM];
	extern string ampersandR;
	string story = cityname()\
		+ CONST_news473;
	if (lawList[LAW_ANIMALRESEARCH] == 2)
	{
		story += CONST_news474;
		story += pickrandom(animal_research_country);
		story += CONST_news475;
	}
	else {
		story += CONST_news476;
	}
	story += CONST_news477;
	if (LCSrandom(drug_name.size())) {
		story += pickrandom(drug_name);
	}
	else {
		if (lawList[LAW_FREESPEECH] == -2)story += CONST_news478;
		else story += CONST_news479;
	}
	story += pickrandom(drug_name_2)\
		+ CONST_news480;
	if (LCSrandom(chimp_drug_impact.size())) {
		story += pickrandom(chimp_drug_impact);
	}
	else {
		if (lawList[LAW_FREESPEECH] == -2)story += CONST_news481;
		else story += CONST_news482;
	}
	story += CONST_news485 \
		+ ampersandR \
		+ CONST_news484 \
		+ CONST_news485 \
		+ CONST_news486 \
		+ CONST_news487\
		+ pickrandom(chimp_drug_horror)\
		+ CONST_news488\
		+ CONST_news489\
		+ CONST_news490\
		+ CONST_news1030\
		+ ampersandR\
		+ CONST_news492\
		+ ampersandR;
	return story;
}
string constructNegativeVIEW_POLLUTION() {


	extern vector<string> family_values_company_name;
	extern vector<string> family_values_company_name_2;
	extern vector<string> family_values_company_name_3;
	extern vector<string> pollution_consumption;
	extern vector<string> pollution_consumption_2;
	extern vector<string> i_like_polution;
	extern vector<string> distrust_liberals;

	const string CONST_news571 = "needs to take a breather on this one. We don't see why there's such a rush to judgment here. ";
	const string CONST_news570 = "before we urge any action. Society really just ";
	const string CONST_news569 = "there's work left to be done. We should study much more ";
	const string CONST_news568 = "Why is there contention on the pollution question? It's because ";
	const string CONST_news567 = "All we've done is introduced a little clarity into the ongoing debate. ";
	const string CONST_news566 = " these issues to their own advantage. ";
	const string CONST_news565 = ". You have to realize that ";
	const string CONST_news564 = "a spokesperson stated that, \"";
	const string CONST_news563 = " When questioned about the science behind these results, ";
	const string CONST_news562 = " might actually ";
	const string CONST_news561 = "Among the most startling of the think tank's findings is that ";
	const string CONST_news560 = "and the latest science on the issue. ";
	const string CONST_news559 = " recently released a wide-ranging report detailing recent trends ";
	const string CONST_news558 = " - Pollution might not be so bad after all. The ";

	extern string singleDot;
	extern short lawList[LAWNUM];
	extern string ampersandR;
	string story = cityname()\
		+ CONST_news558\
		+ pickrandom(family_values_company_name)\
		+ singleSpace\
		+ pickrandom(family_values_company_name_2)\
		+ singleSpace\
		+ pickrandom(family_values_company_name_3)\
		+ CONST_news559\
		+ CONST_news560\
		+ CONST_news561\
		+ pickrandom(pollution_consumption)\
		+ CONST_news562\
		+ pickrandom(pollution_consumption_2)\
		+ singleDot\
		+ ampersandR\
		+ CONST_news563\
		+ CONST_news564\
		+ pickrandom(i_like_polution)\
		+ CONST_news565\
		+ pickrandom(distrust_liberals)\
		+ CONST_news566\
		+ CONST_news567\
		+ CONST_news568\
		+ CONST_news569\
		+ CONST_news570\
		+ CONST_news571\
		+ ampersandR;
	return story;
}
string constructNegativeVIEW_CORPORATECULTURE() {


	extern vector<string> tech_giant_name;
	extern vector<string> tech_giant_name_2;


	const string CONST_news587 = "of the tech industry but is also indicative of a full economic recover.&r";
	const string CONST_news586 = "analysts suggest that not only does the expansion speak to the health ";
	const string CONST_news585 = "futures of some of the companies in the tech sector. On the whole, however, ";
	const string CONST_news584 = "although the dampened movement might be expected due to the uncertain ";
	const string CONST_news583 = "The markets reportedly responded to the announcement with mild interest, ";
	const string CONST_news582 = "this welcome news is bound to be a pleasant surprise to those in the unemployment lines. ";
	const string CONST_news581 = "of large corporations to export jobs overseas these days, ";
	const string CONST_news580 = "light of the tendency ";
	const string CONST_news579 = "Given the state of the economy recently and in ";
	const string CONST_news578 = " increasing its payrolls by over ten thousand workers alone. ";
	const string CONST_news577 = "tech giant ";
	const string CONST_news576 = "are expected in the first month, with ";
	const string CONST_news575 = "during the next quarter. Over thirty thousand jobs ";
	const string CONST_news574 = "will be expanding their work forces considerably ";
	const string CONST_news573 = "at a joint news conference here that they ";
	const string CONST_news572 = " - Several major companies have announced ";

	extern string singleDot;
	extern short lawList[LAWNUM];
	extern string ampersandR;
	string story = cityname()\
		+ CONST_news572\
		+ CONST_news573\
		+ CONST_news574\
		+ CONST_news575\
		+ CONST_news576\
		+ CONST_news577\
		+ pickrandom(tech_giant_name)\
		+ pickrandom(tech_giant_name_2)\
		+ CONST_news578\
		+ CONST_news579\
		+ CONST_news580\
		+ CONST_news581\
		+ CONST_news582\
		+ CONST_news583\
		+ CONST_news584\
		+ CONST_news585\
		+ CONST_news586\
		+ CONST_news587;
	return story;
}
string constructNegativeVIEW_GENETICS()
{


	extern vector<string> gene_corp_name;
	extern vector<string> gene_corp_name_2;
	extern vector<string> gene_product_name;
	extern vector<string> gene_product_name_2;
	extern vector<string> gene_product_benefit;
	extern vector<string> gene_product_cost;
	extern vector<string> bullshit_no_free_speech;
	extern vector<string> bullshit;

	const string CONST_news525 = "but the GM industry operates at a higher ethical standard. That goes without saying.";
	const string CONST_news524 = "No. That's just ridiculous. I mean, sure companies have put unsafe products out, ";
	const string CONST_news523 = ". Would we stake the reputation of our company on unsafe products? ";
	const string CONST_news522 = " is just a load of ";
	const string CONST_news521 = "Look, these products are safe. That thing about the ";
	const string CONST_news520 = "One in particular said, \"";
	const string CONST_news519 = "in their dismissal of the criticism which often follows the industry. ";
	const string CONST_news518 = " Spokespeople for the GM corporations were universal ";
	const string CONST_news517 = "this amazing new product actually ";
	const string CONST_news516 = "According to the public relations representative speaking, ";
	const string CONST_news515 = "\", during an afternoon PowerPoint presentation. ";
	const string CONST_news514 = ", presented their product, \"";
	const string CONST_news513 = " One such corporation, ";
	const string CONST_news512 = "booths and gave talks to wide-eyed onlookers.";
	const string CONST_news511 = "to showcase its upcoming products. Over thirty companies set up ";
	const string CONST_news510 = " - The genetic foods industry staged a major event here yesterday ";

	extern string singleDot;
	extern short lawList[LAWNUM];
	extern string ampersandR;
	string story = cityname()\
		+ CONST_news510\
		+ CONST_news511\
		+ CONST_news512\
		+ ampersandR\
		+ CONST_news513\
		+ pickrandom(gene_corp_name)\
		+ singleSpace\
		+ pickrandom(gene_corp_name_2)\
		+ CONST_news514\
		+ pickrandom(gene_product_name)\
		+ singleSpace\
		+ pickrandom(gene_product_name_2)\
		+ CONST_news515\
		+ CONST_news516\
		+ CONST_news517\
		+ pickrandom(gene_product_benefit)\
		+ singleDot\
		+ ampersandR\
		+ CONST_news518\
		+ CONST_news519\
		+ CONST_news520\
		+ CONST_news521\
		+ pickrandom(gene_product_cost)\
		+ CONST_news522;
	if (lawList[LAW_FREESPEECH] == -2) {
		story += pickrandom(bullshit_no_free_speech);
	}
	else {
		story += pickrandom(bullshit);
	}
	story += CONST_news523\
		+ CONST_news524\
		+ CONST_news525\
		+ CONST_news1030\
		+ ampersandR;
	return story;
}

string constructNegativeVIEW_DEATHPENALTY()
{

	extern vector<string> evidence_of_child_murder;
	extern vector<string> break_in_murder_case;
	extern vector<string> mutilated_corpse;

	const string CONST_news472 = "the death penalty in this case.";
	const string CONST_news471 = "life imprisonment in this case.";
	const string CONST_news470 = "seeking ";
	const string CONST_news469 = " The district attorney's office has already repeatedly said it will be ";
	const string CONST_news468 = ". Sources say that the police got a break in the case when ";
	const string CONST_news467 = " dead and ";
	const string CONST_news466 = " [in a better place]";
	const string CONST_news465 = "only to turn up later";
	const string CONST_news464 = ". Over twenty children in the past two years have gone missing, ";
	const string CONST_news463 = " was detained yesterday afternoon, reportedly in possession of ";
	const string CONST_news462 = "according to a spokesperson for the police department here. ";
	const string CONST_news461 = "string of brutal child killings that has kept everyone in the area on edge, ";
	const string CONST_news460 = "The authorities have apprehended their primary suspect in the ";
	const string CONST_news459 = " - Perhaps parents can rest easier tonight. ";
	extern string singleDot;
	extern short lawList[LAWNUM];
	extern string ampersandR;
	char dstr[200], dstr2[200], dstr3[200];
	generate_long_name(dstr, dstr2, dstr3);
	string story = cityname()\
		+ CONST_news459\
		+ CONST_news460\
		+ CONST_news461\
		+ CONST_news462\
		+ dstr\
		+ singleSpace\
		+ dstr2\
		+ singleSpace\
		+ dstr3\
		+ CONST_news463\
		+ pickrandom(evidence_of_child_murder)\
		+ CONST_news464\
		+ CONST_news465;
	if (lawList[LAW_FREESPEECH] == -2)
		story += CONST_news466;
	else
	{
		story += CONST_news467;
		story += pickrandom(mutilated_corpse);
	}
	story += CONST_news468\
		+ pickrandom(break_in_murder_case)\
		+ singleDot\
		+ ampersandR\
		+ CONST_news469\
		+ CONST_news470;
	if (lawList[LAW_DEATHPENALTY] == 2)
		story += CONST_news471;
	else
		story += CONST_news472;
	story += ampersandR;
	return story;
}

string constructNegativeVIEW_INTELLIGENCE()
{

	const string CONST_newsX08 = " The spokesperson further stated, \"";

	extern string commaSpace;


	extern vector<string> terrorist_group;
	extern vector<string> terrorist_plot;
	extern vector<string> terrorist_plot_no_free_speech;


	const string CONST_news508 = "this new age.";
	const string CONST_news507 = "for what we feel are the essential tools for combating terrorism in ";
	const string CONST_news506 = "The Head of the Agency will be sending a request to Congress ";
	const string CONST_news505 = "However, let me also say that there's more that needs to be done. ";
	const string CONST_news504 = "civilization before they can destroy American families. ";
	const string CONST_news503 = "providing us with the tools we need to neutralize these enemies of ";
	const string CONST_news502 = "that we are grateful to the Congress and this Administration for ";
	const string CONST_news501 = "I won't compromise our sources and methods, but let me just say ";
	const string CONST_news499 = "was to occur.";
	const string CONST_news498 = "terrorist organization allowed the plot to be foiled just days before it ";
	const string CONST_news497 = ". However, intelligence garnered from deep within the mysterious ";
	const string CONST_news496 = " planned to ";
	const string CONST_news495 = " According to a spokesperson for the agency, ";
	const string CONST_news494 = "would have occurred on American soil.";
	const string CONST_news493 = "Washington, DC - The CIA announced yesterday that it has averted a terror attack that ";

	extern string singleDot;
	extern short lawList[LAWNUM];
	extern string ampersandR;
	string story;
	story += CONST_news493\
		+ CONST_news494\
		+ ampersandR\
		+ CONST_news495\
		+ pickrandom(terrorist_group)\
		+ CONST_news496;
	if (lawList[LAW_FREESPEECH] == -2)story += pickrandom(terrorist_plot_no_free_speech);
	else story += pickrandom(terrorist_plot);
	story += CONST_news497\
		+ CONST_news498\
		+ CONST_news499\
		+ ampersandR\
		+ CONST_newsX08\
		+ CONST_news501\
		+ CONST_news502\
		+ CONST_news503\
		+ CONST_news504\
		+ CONST_news505\
		+ CONST_news506\
		+ CONST_news507\
		+ CONST_news508\
		+ CONST_news1030\
		+ ampersandR;
	return story;
}

string constructNegativeVIEW_JUSTICES()
{


	const string CONST_newsB937 = "If I were to be released, I would surely kill again.\"";

	const string CONST_news557 = "completely strapped for cash.&r";
	const string CONST_news556 = "to the current economic doldrums that have left the state ";
	const string CONST_news555 = "has stated that the case will not be retried, due ";
	const string CONST_news554 = " A spokesperson for the district attorney ";
	const string CONST_news552 = "Thank you for saving me from myself. ";
	const string CONST_news551 = " confessed and was sentenced to life, saying \"";
	const string CONST_news550 = "covered in the victims' blood. ";
	const string CONST_news549 = " was found with the murder weapon, ";
	const string CONST_news548 = "After an intensive manhunt, ";
	const string CONST_news547 = " slayings. ";
	const string CONST_news546 = " was convicted of the now-infamous ";
	const string CONST_news545 = " Ten years ago, ";
	const string CONST_news544 = " grants was not coerced in any way.&r";
	const string CONST_news543 = ", which even Justice ";
	const string CONST_news542 = ", despite the confession of ";
	const string CONST_news541 = " consultations with a Magic 8-Ball";
	const string CONST_news540 = " family";
	const string CONST_news539 = " close personal friendship with the ";
	const string CONST_news538 = " personal philosophy of liberty";
	const string CONST_news537 = " deserved another chance";
	const string CONST_news536 = " belief that ";
	const string CONST_news535 = " belief that the crimes were a vast right-wing conspiracy";
	const string CONST_news534 = " general feeling about police corruption";
	const string CONST_news533 = "ten-year-old eyewitness testimony";
	const string CONST_news531 = "made the decision based on ";
	const string CONST_news530 = " of the notoriously liberal circuit of appeals here ";
	const string CONST_news529 = "Justice ";
	const string CONST_news528 = " was overturned by a federal judge yesterday. ";
	const string CONST_news527 = " - The conviction of confessed serial killer ";

	extern string singleDot;
	extern short lawList[LAWNUM];
	extern string ampersandR;
	char dstr[200], dstr2[200], dstr3[200];
	generate_long_name(dstr, dstr2, dstr3);
	char jstr[200], jstr2[200];
	const char gn = pickrandom(maleOrFemale);
	generate_name(jstr, jstr2, gn);
	string story = cityname()\
		+ CONST_news527\
		+ dstr\
		+ singleSpace\
		+ dstr2\
		+ singleSpace\
		+ dstr3\
		+ CONST_news528\
		+ CONST_news529\
		+ jstr\
		+ singleSpace\
		+ jstr2\
		+ CONST_news530\
		+ CONST_news531;
	char gen[20];
	strcpy(gen, (gn == GENDER_FEMALE ? CONST_news700 : CONST_news378).data());
	switch (LCSrandom(7))
	{
	case 0:story += CONST_news533; break;
	case 1:story += gen; story += CONST_news534; break;
	case 2:story += gen; story += CONST_news535; break; // Clinton
	case 3:
		story += gen;
		story += CONST_news536;
		story += dstr3;
		story += CONST_news537;
		break;
	case 4:
		story += gen;
		story += CONST_news538; break;
	case 5:
		story += gen;
		story += CONST_news539;
		story += dstr3; // I know Charles Manson.
		story += CONST_news540; // Charles Manson was a friend of mine.
		break; // And you, sir, are no Charles Manson!
	case 6:story += gen; story += CONST_news541; break;
	}
	char sstr[200];
	strcpy(sstr, lastname().data());
	story += CONST_news542\
		+ dstr3\
		+ CONST_news543\
		+ jstr2\
		+ CONST_news544\
		+ CONST_news545\
		+ dstr3\
		+ CONST_news546\
		+ sstr\
		+ CONST_news547\
		+ CONST_news548\
		+ dstr3\
		+ CONST_news549\
		+ CONST_news550\
		+ dstr3\
		+ CONST_news551\
		+ CONST_news552\
		+ CONST_newsB937\
		+ CONST_news554\
		+ CONST_news555\
		+ CONST_news556\
		+ CONST_news557;
	return story;
}

string constructNegativeVIEW_AMRADIO()
{ //THIS ONE IS SHORTER BECAUSE OF DOUBLE HEADLINE

	const string CONST_newsX09 = "screamed \"fuck the police those goddamn motherfuckers. I got a fucking ticket this morning and I'm fucking pissed as shit.\"";

	extern vector<string> fm_radio_name;
	extern vector<string> fm_radio_name_2;


	const string CONST_news625 = "stated that the incident is under investigation.";
	const string CONST_news624 = " A spokesperson for the FCC ";
	const string CONST_news623 = "within the town. ";
	const string CONST_news622 = "in neighboring towns. ";
	const string CONST_news621 = "within the county. ";
	const string CONST_news620 = "from all over the state. ";
	const string CONST_news619 = "across the nation. ";
	const string CONST_news618 = "from irate listeners ";
	const string CONST_news617 = " complaints ";
	const string CONST_news616 = "some";
	const string CONST_news615 = "dozens of";
	const string CONST_news614 = "hundreds of";
	const string CONST_news613 = "several hundred";
	const string CONST_news612 = "thousands of";
	const string CONST_news611 = "the FCC received ";
	const string CONST_news610 = " later apologized, ";
	const string CONST_news609 = " on the air. Although ";
	const string CONST_news608 = "masturbated";
	const string CONST_news607 = "[had fun]";
	const string CONST_news606 = "breastfed from a lactating woman";
	const string CONST_news605 = "[fed] from a [woman]";
	const string CONST_news604 = "breastfed from an exposed woman";
	const string CONST_news603 = "[fed] from [an indecent] woman";
	const string CONST_news602 = "screamed \"f*ck the police those g*dd*mn m*th*f*ck*rs. I got a f*cking ticket this morning and I'm f*cking p*ss*d as sh*t.\"";
	const string CONST_news601 = "screamed \"[darn] the police those [big dumb jerks]. I got a [stupid] ticket this morning and I'm [so angry].\"";
	const string CONST_news599 = "encouraged listeners to call in and relieve themselves";
	const string CONST_news598 = "encouraged listeners to call in and take a piss";
	const string CONST_news597 = "encouraged listeners to call in and [urinate]";
	const string CONST_news596 = "had intercourse";
	const string CONST_news595 = "fucked";
	const string CONST_news594 = "[had consensual intercourse in the missionary position]";
	const string CONST_news593 = " reportedly ";
	const string CONST_news592 = "\", ";
	const string CONST_news591 = "'s ";
	const string CONST_news590 = "broadcast of the program \"";
	const string CONST_news589 = " has brought radio entertainment to a new low. During yesterday's ";
	const string CONST_news588 = " - Infamous FM radio shock jock ";

	extern string singleDot;
	extern short lawList[LAWNUM];
	extern string ampersandR;
	char dstr[200], dstr2[200];
	generate_name(dstr, dstr2, GENDER_WHITEMALEPATRIARCH);
	string story = cityname()\
		+ CONST_news588\
		+ dstr\
		+ singleSpace\
		+ dstr2\
		+ CONST_news589\
		+ CONST_news590\
		+ dstr\
		+ CONST_news591\
		+ pickrandom(fm_radio_name)\
		+ singleSpace\
		+ pickrandom(fm_radio_name_2)\
		+ CONST_news592\
		+ dstr2\
		+ CONST_news593;
	switch (LCSrandom(5))
	{
	case 0:
		if (lawList[LAW_FREESPEECH] == -2)story += CONST_news594;
		else if (lawList[LAW_FREESPEECH] == 2)story += CONST_news595;
		else story += CONST_news596; break;
	case 1:
		if (lawList[LAW_FREESPEECH] == -2)story += CONST_news597;
		else if (lawList[LAW_FREESPEECH] == 2)story += CONST_news598;
		else story += CONST_news599; break;
	case 2:
		if (lawList[LAW_FREESPEECH] == 2)story += CONST_newsX09;
		else if (lawList[LAW_FREESPEECH] == -2)story += CONST_news601;
		else story += CONST_news602; break;
	case 3:
		if (lawList[LAW_FREESPEECH] == -2 && lawList[LAW_WOMEN] == -2)story += CONST_news603;
		else if (lawList[LAW_FREESPEECH] != -2 && lawList[LAW_WOMEN] == -2)story += CONST_news604;
		else if (lawList[LAW_FREESPEECH] == -2 && lawList[LAW_WOMEN] != -2)story += CONST_news605;
		else story += CONST_news606; break;
	case 4:
		if (lawList[LAW_FREESPEECH] == -2)story += CONST_news607;
		else story += CONST_news608; break;
	}
	story += CONST_news609\
		+ dstr2\
		+ CONST_news610\
		+ CONST_news611;
	if (lawList[LAW_FREESPEECH] == -2) story += CONST_news612;
	else if (lawList[LAW_FREESPEECH] == -1) story += CONST_news613;
	else if (lawList[LAW_FREESPEECH] == 0) story += CONST_news614;
	else if (lawList[LAW_FREESPEECH] == 1) story += CONST_news615;
	else story += CONST_news616;
	story += CONST_news617;
	story += CONST_news618;
	if (lawList[LAW_FREESPEECH] == -2) story += CONST_news619;
	else if (lawList[LAW_FREESPEECH] == -1) story += CONST_news620;
	else if (lawList[LAW_FREESPEECH] == 0) story += CONST_news621;
	else if (lawList[LAW_FREESPEECH] == 1) story += CONST_news622;
	else story += CONST_news623;
	story += CONST_news624;
	story += CONST_news625;
	story += ampersandR;
	return story;
}
string constructNegativeVIEW_GUNCONTROL()
{
	extern vector<string> public_place;
	extern string commaSpace;

	const string CONST_newsB940 = "he ";
	const string CONST_newsB939 = "Miss ";
	const string CONST_news638 = "Mr. ";
	const string CONST_news637 = "Mrs. ";
	const string CONST_news636 = "Ms. ";

	const string CONST_news650 = "'s heroic actions.\"";
	const string CONST_news649 = " if not for ";
	const string CONST_news648 = "mass shooting";
	const string CONST_news646 = " The spokesperson for the police department said, \"We'd have a yet another ";
	const string CONST_news645 = "could hurt anyone else.&r";
	const string CONST_news644 = "she ";
	const string CONST_news643 = "before ";
	const string CONST_news642 = "firefight, killing the attacker ";
	const string CONST_news641 = "firefight, [putting the attacker to sleep] ";
	const string CONST_news640 = " became more agitated, the heroic citizen was forced to engage the shooter in a ";
	const string CONST_news639 = " attempted to talk down the shooter, but as ";
	const string CONST_news635 = " Initially, ";
	const string CONST_news634 = " to take cover while others called the police.&r";
	const string CONST_news633 = "forcing ";
	const string CONST_news632 = "The citizen pulled a concealed handgun and fired once at the shooter, ";
	const string CONST_news631 = " sprung into action. ";
	const string CONST_news630 = " opened fire at the ";
	const string CONST_news629 = " After ";
	const string CONST_news628 = " was prevented by a bystander with a gun.";
	const string CONST_news626 = " - In a surprising turn, a ";

	extern string singleDot;
	extern short lawList[LAWNUM];
	extern string ampersandR;
	string story = cityname();
	char jstr[200], jstr2[200], jstr3[200], jstr4[200], jstr5[200], tg2[10];
	const char jg1 = pickrandom(maleOrFemale);
	const char jg2 = pickrandom(maleOrFemale);
	generate_long_name(jstr, jstr2, jstr3, jg1);
	generate_name(jstr4, jstr5, jg2);
	story += CONST_news626;
	if (lawList[LAW_FREESPEECH] == -2) story += CONST_news647; else story += CONST_news648;
	story += CONST_news628\
		+ CONST_news629\
		+ jstr\
		+ singleSpace\
		+ jstr2\
		+ CONST_news630\
		+ jstr3\
		+ singleSpace\
		+ pickrandom(public_place)\
		+ commaSpace\
		+ jstr4\
		+ singleSpace\
		+ jstr5\
		+ CONST_news631\
		+ CONST_news632\
		+ CONST_news633\
		+ jstr2\
		+ CONST_news634\
		+ CONST_news635;
	if (jg2 == GENDER_FEMALE)
	{
		if (LCSrandom(4) < lawList[LAW_WOMEN] + 2) // 0% chance at lawList[LAW_WOMEN]==-2, 100% chance at lawList[LAW_WOMEN]==2
			strcpy(tg2, CONST_news636.data());
		else
			strcpy(tg2, (LCSrandom(2) ? CONST_news637 : CONST_newsB939).data());
	}
	else strcpy(tg2, CONST_news638.data());
	story += tg2;
	story += jstr5;
	story += CONST_news639;
	story += jstr2;
	story += CONST_news640;
	if (lawList[LAW_FREESPEECH] == -2) story += CONST_news641;
	else story += CONST_news642;
	story += CONST_news643;
	story += (jg1 == GENDER_FEMALE ? CONST_news644 : CONST_newsB940);
	story += CONST_news645;
	story += CONST_news646;
	if (lawList[LAW_FREESPEECH] == -2) story += CONST_news647;
	else story += CONST_news648;
	story += CONST_news649;
	story += tg2;
	story += jstr5;
	story += CONST_news650;
	return story;
}
string threatenToKillPolice() {
	const string CONST_news678 = "Imma kill all you b*tches, startin' with this m*th*f*ck*r here.";
	const string CONST_news677 = "[I will harm all police officers], startin' with this [one] here.";
	const string CONST_news676 = "Imma kill all you bitches, startin' with this mothafucker here.";
	const string CONST_news675 = "Why the f*ck am I talkin' to you? I'd rather kill this pig.";
	const string CONST_news674 = "Why [am I] talkin' to you? I'd rather [harm this police officer.]";
	const string CONST_news673 = "Why the fuck am I talkin' to you? I'd rather kill this pig.";
	const string CONST_news672 = "F*ck a m*th*f*ck*n' bull. I'm killin' this pig sh*t.";
	const string CONST_news671 = "[Too late.] [I am going to harm this police officer.]";
	const string CONST_news670 = "Fuck a muthafuckin' bull. I'm killin' this pig shit.";
	const string CONST_news669 = "Ah, f*ck this sh*t. This punk b*tch is f*ckin' dead!";
	const string CONST_news668 = "Ah, [no way.] This [police officer will be harmed!]";
	const string CONST_news667 = "Ah, fuck this shit. This punk bitch is fuckin' dead!";
	string story;
	extern short lawList[LAWNUM];
	switch (LCSrandom(4))
	{
	case 0:
		if (lawList[LAW_FREESPEECH] == 2)story += CONST_news667;
		else if (lawList[LAW_FREESPEECH] == -2)story += CONST_news668;
		else story += CONST_news669;
		break;
	case 1:
		if (lawList[LAW_FREESPEECH] == 2)story += CONST_news670;
		else if (lawList[LAW_FREESPEECH] == -2)story += CONST_news671;
		else story += CONST_news672;
		break;
	case 2:
		if (lawList[LAW_FREESPEECH] == 2)story += CONST_news673;
		else if (lawList[LAW_FREESPEECH] == -2)story += CONST_news674;
		else story += CONST_news675;
		break;
	case 3:
		if (lawList[LAW_FREESPEECH] == 2)story += CONST_news676;
		else if (lawList[LAW_FREESPEECH] == -2)story += CONST_news677;
		else story += CONST_news678;
		break;
	}
	return story;
}
string viciousGuardKilling(const char ggn, const char dgn) {
	string story;
	extern short lawList[LAWNUM];
	const string CONST_news684 = "killed the guard";
	const string CONST_news683 = "[harmed] the guard";

	const string CONST_newsB944 = "neo-pagan";
	const string CONST_newsB943 = "him";
	const string CONST_newsB942 = "Bloods";

	const string CONST_news708 = " altar";
	const string CONST_news707 = "Satanic";
	const string CONST_news706 = "sacrificed the guard on a makeshift ";

	const string CONST_news701 = " off";
	const string CONST_news699 = "taken the guard to the execution chamber and finished ";
	const string CONST_news695 = "Crips";
	const string CONST_news694 = "poisoned the guard with drugs smuggled into the prison by the ";
	const string CONST_news693 = " own gun";
	const string CONST_news691 = "shot the guard with ";
	const string CONST_news690 = " cell";
	const string CONST_news688 = "smashed the guard's skull with the toilet seat from ";

	vector<string> vicious_killing_of_guard = {
		"slit the guard's throat with a shank",
		"strangled the guard to death with a knotted bed sheet",
		"chewed out the guard's throat",
		"hit all 36 pressure points of death on the guard",
		"electrocuted the guard with high-voltage wires",
		"thrown the guard out the top-storey window",
		"tricked another guard into shooting the guard dead",
		"burnt the guard to a crisp using a lighter and some gasoline",
		"eaten the guard's liver with some fava beans and a nice chianti",
		"performed deadly experiments on the guard unheard of since Dr. Mengele"
	};
	if (lawList[LAW_FREESPEECH] == -2) story += CONST_news683;
	else if (lawList[LAW_FREESPEECH] == -1) story += CONST_news684;
	else switch (LCSrandom(15))
	{
	default:
		story += pickrandom(vicious_killing_of_guard);
		break;
	case 10: story += CONST_news688;
		story += (dgn == GENDER_FEMALE ? CONST_news700 : CONST_news378);
		story += CONST_news690; break;
	case 11: story += CONST_news691;
		story += (ggn == GENDER_FEMALE ? CONST_news700 : CONST_news378);
		story += CONST_news693; break;
	case 12: story += CONST_news694;
		story += (LCSrandom(2) ? CONST_news695 : CONST_newsB942); break;
	case 13: story += CONST_news699;
		story += (ggn == GENDER_FEMALE ? CONST_news700 : CONST_newsB943);
		story += CONST_news701; break;
	case 14: story += CONST_news706;
		story += (LCSrandom(2) ? CONST_news707 : CONST_newsB944);
		story += CONST_news708; break;
	}
	return story;
}
string constructNegativeVIEW_PRISONS()
{
	const string CONST_newsB941 = "himself";

	const string CONST_news712 = " while \"resisting capture\", according to a prison spokesperson.";
	const string CONST_news711 = "beaten to death";
	const string CONST_news710 = "[also harmed]";
	const string CONST_news709 = ". The prisoner was ";
	const string CONST_news682 = " had already ";
	const string CONST_news681 = "the hostage, but ";
	const string CONST_news680 = " The tower was breached in an attempt to reach ";
	const string CONST_news666 = " reportedly screamed into the receiver \"";
	const string CONST_news665 = " days, but talks were cut short when ";
	const string CONST_news664 = "attempted to negotiate by phone for ";
	const string CONST_news663 = "Authorities locked down the prison and ";
	const string CONST_news662 = " with the guard in a prison tower. ";
	const string CONST_news661 = "herself";
	const string CONST_news660 = " and barricaded ";
	const string CONST_news659 = ", overpowered ";
	const string CONST_news658 = ", an inmate at ";
	const string CONST_news657 = " Two weeks ago, convicted rapist ";
	const string CONST_news656 = " Two weeks ago, convicted [reproduction fiend] ";
	const string CONST_news655 = " captor.";
	const string CONST_news653 = "death of both the prison guard being held hostage and ";
	const string CONST_news652 = " Correctional Facility ended tragically yesterday with the ";
	const string CONST_news651 = " - The hostage crisis at the ";

	extern string singleDot;
	extern short lawList[LAWNUM];
	extern string ampersandR;
	string story = cityname();
	story += CONST_news651;
	char jstr[200];
	strcpy(jstr, lastname(true).data());
	story += jstr;
	story += CONST_news652;
	story += CONST_news653;
	const char ggn = pickrandom(maleOrFemale);
	story += (ggn == GENDER_FEMALE ? CONST_news700 : CONST_news378);
	story += CONST_news655;
	story += ampersandR;
	if (lawList[LAW_FREESPEECH] == -2)story += CONST_news656;
	else story += CONST_news657;
	char dstr[200], dstr2[200];
	const char dgn = pickrandom(maleOrFemale);
	generate_name(dstr, dstr2, dgn);
	char gstr[200], gstr2[200];
	generate_name(gstr, gstr2, ggn);
	story += dstr\
		+ singleSpace\
		+ dstr2\
		+ CONST_news658\
		+ jstr\
		+ CONST_news659\
	 + gstr\
	 + singleSpace\
	 + gstr2\
	 + CONST_news660\
	 + (dgn == GENDER_FEMALE ? CONST_news661 : CONST_newsB941)\
	 + CONST_news662\
	 + CONST_news663\
	 + CONST_news664\
	 + tostring(LCSrandom(18) + 5)\
	 + CONST_news665\
	 + dstr2\
	 + CONST_news666\
	 + threatenToKillPolice()\
	 + CONST_news1030\
		+ CONST_news680\
		+ CONST_news681\
		+ dstr2\
		+ CONST_news682\
	 + viciousGuardKilling(ggn, dgn)\
	 + CONST_news709;
	if (lawList[LAW_FREESPEECH] == -2) story += CONST_news710;
	else  story += CONST_news711;
	story += CONST_news712;
	story += ampersandR;
	return story;
}


string constructNegativeEventStory(const short view) {
	string story = blankString;
	switch (view)
	{
	case VIEW_ANIMALRESEARCH:
	{
		story = constructNegativeVIEW_ANIMALRESEARCH();
		break;
	}
	case VIEW_POLLUTION: {
		story = constructNegativeVIEW_POLLUTION();
		break; 
	}
	case VIEW_CORPORATECULTURE: {
		story = constructNegativeVIEW_CORPORATECULTURE();
		break;
	}
	case VIEW_GENETICS:
	{
		story = constructNegativeVIEW_GENETICS();
		break;
	}

	case VIEW_DEATHPENALTY:
	{
		story = constructNegativeVIEW_DEATHPENALTY();
		break;
	}

	case VIEW_INTELLIGENCE:
	{
		story = constructNegativeVIEW_INTELLIGENCE();
		break;
	}

	case VIEW_JUSTICES:
	{
		story = constructNegativeVIEW_JUSTICES();
		break;
	}

	case VIEW_AMRADIO:
	{ 
		story = constructNegativeVIEW_AMRADIO();
		break;
	}
	case VIEW_GUNCONTROL:
	{
		story = constructNegativeVIEW_GUNCONTROL();
		break;
	}
	case VIEW_PRISONS:
	{
		story = constructNegativeVIEW_PRISONS();
		break;
	}
	}
	return story;
}

/* news - constructs non-LCS related event stories */
string constructeventstory(const short view, const char positive)
{
	if (positive) {
		return constructPositiveEventStory(view);
	}
	else
	{
		return constructNegativeEventStory(view);
	}
}



string wasUnableToFind(const string old) {
	const string CONST_activities149 = " but did find a ";
	const string CONST_activities148 = " was unable to find a ";
	return CONST_activities148 + old + CONST_activities149;
}

string considerLeaving(const bool sensealarm, const bool alarmon, const string name) {
	const string singleDot = ".";
	const string CONST_activities186 = "Enter - Call it a day.";

	const string CONST_activities168 = "Enter - Yes, the Viper has deterred ";
	const string CONST_activities167 = " is deterred.";
	const string CONST_activities166 = "Enter - The Viper?   ";

	if (!sensealarm) return CONST_activities186;
	else
	{
		if (!alarmon)
		{
			return (CONST_activities166)+(name)+(CONST_activities167);
		}
		else
		{
			return (CONST_activities168)+(name)+(singleDot);
		}
	}
}

string getDespairString(const bool drugs, const bool restrain, const bool religion) {

	const string CONST_interrogation133 = " wonders about death.";
	const string CONST_interrogation132 = " wonders about apples.";
	const string CONST_interrogation131 = " cries helplessly.";
	const string CONST_interrogation130 = " barks helplessly.";
	const string CONST_interrogation129 = " curls up in the corner and doesn't move.";
	const string CONST_interrogation128 = " goes limp in the restraints.";
	const string CONST_interrogation127 = "mommy.";
	const string CONST_interrogation126 = "God's mercy.";
	const string CONST_interrogation125 = "John Lennon's mercy.";
	const string CONST_interrogation124 = " screams helplessly for ";

	string output;
	switch (LCSrandom(4))
	{
	case 0: output = CONST_interrogation124;
		if (drugs) output = CONST_interrogation125;
		else if (religion) output = CONST_interrogation126;
		else  output = CONST_interrogation127;
		break;
	case 1:
		if (restrain)  output = CONST_interrogation128;
		else  output = CONST_interrogation129; break;
	case 2:
		if (drugs && !LCSrandom(5))  output = CONST_interrogation130;
		else  output = CONST_interrogation131; break;
	case 3:
		if (drugs && !LCSrandom(3))  output = CONST_interrogation132;
		else  output = CONST_interrogation133;
		break;
	}
	return output;
}

string victimPrays(const bool onDrugs) {
	extern vector<string> prays;
	extern vector<string> prays_on_drugs;
	if (!onDrugs)
	{
		return pickrandom(prays);
	}
	else
	{
		return pickrandom(prays_on_drugs);
	}
}

string getFallsInLove(const string name, const bool restrain) {
	extern vector<vector<string> > fall_in_love;
	const string singleDot = ".";
	string output;

	const string CONST_interrogation143 = "talks about hugging ";
	const string CONST_interrogation142 = " stammers and ";

	const string CONST_interrogationB150 = "hugs ";

	switch (LCSrandom(fall_in_love.size() + 1))
	{
	case 0:
		output = CONST_interrogation142;
		output += restrain ? CONST_interrogation143 : CONST_interrogationB150;
		output += name;
		output += singleDot;
		break;
	default:
		int which_love = LCSrandom(fall_in_love.size());
		output = fall_in_love[which_love][0];
		output += name;
		output += fall_in_love[which_love][1];
		break;
	}
	return output;
}

string getBadTrip(const string name, const bool restrain, const bool rapport) {
	extern vector<vector<string> > bad_trip;
	const string singleDot = ".";

	const string CONST_interrogation148 = " begs for the nightmare to end.";
	const string CONST_interrogation147 = " curls up and";
	const string CONST_interrogation146 = " to stop looking like Hitler.";
	const string CONST_interrogation145 = " screams for ";
	const string CONST_interrogation144 = " begs Hitler to stay and kill ";

	string output;
	switch (LCSrandom(bad_trip.size() + 2))
	{
	case 0:
		if (rapport)
		{
			output = CONST_interrogation144;
			output += name;
			output += singleDot;
		}
		else
		{
			output = CONST_interrogation145;
			output += name;
			output += CONST_interrogation146;
		}
		break;
	case 1:
		if (!restrain) output = CONST_interrogation147;
		output = CONST_interrogation148;
		break;
	default:
		int which_trip = LCSrandom(bad_trip.size());
		output = (bad_trip[which_trip][0]);
		output += name;
		output += (bad_trip[which_trip][1]);
		break;
	}
	return output;
}
string outPsychologyCaptor(const string name) {
	extern vector<string> smarter_than_you_one_line;
	extern vector<vector<string> > smarter_than_you;
	string output;
	int which_smarter = LCSrandom(smarter_than_you.size() + smarter_than_you_one_line.size());
	if (which_smarter < smarter_than_you.size()) {
		output = smarter_than_you[which_smarter][0];
		output += name;
		output += smarter_than_you[which_smarter][1];
	}
	else {
		output = pickrandom(smarter_than_you_one_line);
	}
	return output;

}

string triedConvertingTheAbused(const string name) {
	extern vector<string> develops_hatred_one_line;
	extern vector<vector<string> > develops_hatred;
	string output;
	int which_hatred = LCSrandom(develops_hatred.size() + develops_hatred_one_line.size());
	if (which_hatred < develops_hatred.size())
	{
		output = develops_hatred[which_hatred][0];
		output += name;
		output += develops_hatred[which_hatred][1];
	}
	else {
		output = pickrandom(develops_hatred_one_line);
	}

	return output;
}

string feelsBadForAbused(const string name) {
	extern vector<string> interrogater_shows_compassion_one_line;
	extern vector<vector<string> > interrogater_shows_compassion;

	string output;
	int which_compassion = LCSrandom(interrogater_shows_compassion.size() + interrogater_shows_compassion_one_line.size());
	if (which_compassion < interrogater_shows_compassion.size()) {
		output = interrogater_shows_compassion[which_compassion][0];
		output += name;
		output += interrogater_shows_compassion[which_compassion][1];
	}
	else {
		output = pickrandom(interrogater_shows_compassion_one_line);
	}
	return output;
}

string stockholmSyndrome(const string name) {
	extern vector<vector<string> > cling_to_interrogater;
	extern vector<string> clinging_one_line;

	string output;
	int which_cling = LCSrandom(cling_to_interrogater.size() + clinging_one_line.size());
	if (which_cling < cling_to_interrogater.size()) {
		output = cling_to_interrogater[which_cling][0];
		output += name;
		output += cling_to_interrogater[which_cling][1];
	}
	else {
		output = pickrandom(clinging_one_line);
	}
	return output;
}

string failToBreakReligion(const string a, const string cr) {
	extern vector<vector<string> > cling_to_religion;
	extern vector<string> cling_to_religion_one_line;

	string output;
	int which_cling = LCSrandom(cling_to_religion.size() + cling_to_religion_one_line.size());
	if (which_cling < cling_to_religion.size()) {
		output = a;
		output += cling_to_religion[which_cling][0];
		output += cr;
		output += cling_to_religion[which_cling][1];
	}
	else {
		output = cr;
		output += pickrandom(cling_to_religion_one_line);
	}
	return output;
}

string failedToBreakBusiness(const string a, const string cr) {
	extern vector<vector<string> > cling_to_business;
	extern vector<string> cling_to_business_one_line;

	string output;
	int which_cling = LCSrandom(cling_to_business.size() + cling_to_business_one_line.size());
	if (which_cling < cling_to_business.size()) {
		output + cr;
		output += cling_to_business[which_cling][0];
		output += a;
		output += cling_to_business[which_cling][1];
	}
	else {
		output + cr;
		output += pickrandom(cling_to_business_one_line);
	}
	return output;
}

string failedToBreakScience(const string a, const string cr) {
	extern vector<vector<string> > cling_to_science;
	extern vector<string> cling_to_science_one_line;
	string output;
	int which_cling = LCSrandom(cling_to_science.size() + cling_to_science_one_line.size());
	if (which_cling < cling_to_science.size()) {
		output + cr;
		output += cling_to_science[which_cling][0];
		output += a;
		output += cling_to_science[which_cling][1];
	}
	else {
		output + cr;
		output += pickrandom(cling_to_science_one_line);
	}
	return output;
}


string howGracefulAttack(int handToHand) {

	const string CONST_fight126 = "gracefully strikes at";
	const string CONST_fight125 = "jump kicks";
	const string CONST_fight124 = "strikes at";
	const string CONST_fight123 = "kicks";
	const string CONST_fight122 = "grapples with";
	const string CONST_fight121 = "swings at";
	const string CONST_fight120 = "punches";

	if (!LCSrandom(handToHand + 1))
		return CONST_fight120;
	else if (!LCSrandom(handToHand))
		return CONST_fight121;
	else if (!LCSrandom(handToHand - 1))
		return CONST_fight122;
	else if (!LCSrandom(handToHand - 2))
		return CONST_fight123;
	else if (!LCSrandom(handToHand - 3))
		return CONST_fight124;
	else if (!LCSrandom(handToHand - 4))
		return CONST_fight125;
	else return CONST_fight126;
}

string dismemberingWound(const int w, const int wound) {

	const string CONST_fight152 = " BLOWING IT OFF!";
	const string CONST_fight151 = " CUTTING IT OFF!";
	const string CONST_fight150 = " BLOWING IT IN HALF!";
	const string CONST_fight149 = " BLOWING IT APART!";
	const string CONST_fight148 = " CUTTING IT IN HALF!";

	string output = blankString;

	if (w == BODYPART_HEAD && wound & WOUND_CLEANOFF) {
		output = CONST_fight151;
	}
	else if (w == BODYPART_BODY && wound & WOUND_CLEANOFF) {
		output = CONST_fight148;
	}
	else if (w == BODYPART_HEAD && wound & WOUND_NASTYOFF) {
		output = CONST_fight149;
	}
	else if (w == BODYPART_BODY && wound & WOUND_NASTYOFF) {
		output = CONST_fight150;
	}
	else if (wound & WOUND_CLEANOFF) {
		output = CONST_fight151;
	}
	else if (wound & WOUND_NASTYOFF) {
		output = CONST_fight152;
	}

	return output;
}
