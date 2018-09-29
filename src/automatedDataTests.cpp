#include "includes.h"
#include "cursesAlternative.h"
using namespace std;
//extern map<short, string>  helpTopics;
//string_to_activity;
extern map<short, string>  conservativeLegalArgument;
//string_to_law;
extern map<short, string>  youAreStupidTalkAboutIssues;
//string_to_law;
extern map<short, string>  issueTooLiberal;
//string_to_law;
extern map<short, string>  issueEventString;
//string_to_view; [LCSrandom(VIEWNUM - 3)]
extern map<short, string>  conservatiseLaw;
//string_to_law;
extern map<short, string>  liberalizeLaw;
//string_to_law;
extern map<short, string>  discussIssues;
//string_to_view; LCSrandom(VIEWNUM);
extern map<short, string>  discussesIssues;
//string_to_view; LCSrandom(VIEWNUM);
extern map<short, vector<string> >  talkAboutTheIssues; // 0~1
//string_to_law;
extern map<short, vector<string> >  endgameLawStrings; // 0~7
//string_to_law;
void testCreature();
void automatedDataTests() {

	const string CONST_automatedDataTests013 = "TEST";
	const string CONST_automatedDataTests008 = "SUCCESS";
	clearAlt();
	for (int i = 0, k = 0; i < LAWNUM; i++) {
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		mvaddstrAlt(k++, 0, i);
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		mvaddstrAlt(k++, 0, conservativeLegalArgument[i]);
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		mvaddstrAlt(k++, 0, youAreStupidTalkAboutIssues[i]);
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		mvaddstrAlt(k++, 0, issueTooLiberal[i]);
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		mvaddstrAlt(k++, 0, conservatiseLaw[i]);
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		mvaddstrAlt(k++, 0, liberalizeLaw[i]);
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		for (int j = 0; j < 2; j++) {
			mvaddstrAlt(k++, 0, talkAboutTheIssues[i][j]); // 0~1
		}
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		for (int j = 0; j < 8; j++) {
			mvaddstrAlt(k++, 0, endgameLawStrings[i][j]); // 0~7
		}
		mvaddstrAlt(k++, 0, CONST_automatedDataTests008);
	}
	pressAnyKey();
	clearAlt();
	for (int i = 0, k = 0; i < VIEWNUM - 3; i++) {
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		mvaddstrAlt(k++, 0, i);
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		mvaddstrAlt(k++, 0, issueEventString[i]);
	}
	pressAnyKey();
	clearAlt();
	for (int i = 0, k = 0; i < VIEWNUM; i++) {
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		mvaddstrAlt(k++, 0, i);
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		mvaddstrAlt(k++, 0, discussIssues[i]);
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		mvaddstrAlt(k++, 0, discussesIssues[i]);
	}
	pressAnyKey();
	clearAlt();
	testCreature();

}


// This, this requires a lot of prepwork to test the makecreature(...) method
const string blankString = "";
#include "creature/creature.h"
#include "vehicle/vehicleType.h"
#include "vehicle/vehicle.h"

struct newGameArguments {
	const char recruits;
	const char base;
	const bool makelawyer;
	const bool gaylawyer;
	const bool sports_car;
	newGameArguments(char _recruits, char _base, bool _makelawyer, bool _gaylawyer, bool _sports_car) : recruits(_recruits), base(_base), makelawyer(_makelawyer), gaylawyer(_gaylawyer), sports_car(_sports_car) {}
};
void initiateNewgameLocations(DeprecatedCreature* newcr, const newGameArguments ngm);
void testCreature() {

	// This, this requires a lot of prepwork to test the makecreature(...) method
	extern bool multipleCityMode;
	multipleCityMode = false;
	void make_world(bool hasmaps);
	make_world(false);
	bool makelawyer = false;
	bool gaylawyer = false;
	bool sports_car = false;
	char recruits = 1;
	char base = 21;
	DeprecatedCreature *newcr = new DeprecatedCreature;
	void recruitment_activity(DeprecatedCreature &cr);
	recruitment_activity(*newcr);
	initiateNewgameLocations(newcr, newGameArguments(recruits, base, makelawyer, gaylawyer, sports_car));

	extern short lawList[LAWNUM];
	for (int i = 0; i < CREATURENUM; i++) {
		DeprecatedCreature cr;
		for (int j = -2; j < 3; j++) {
			lawList[LAW_GUNCONTROL] = j;
			makecreature(cr, i);
		}
		if (i % 20 == 0) {
			pressAnyKey();
			clearAlt();
		}
		mvaddstrAlt(i % 20, 0, cr.name);

	}
	mvaddstrAlt(21, 0, "TEST COMPLETE");

	mvaddstrAlt(22, 0, "Please Restart");
	// Player should restart at this point.
	pressAnyKey();
}