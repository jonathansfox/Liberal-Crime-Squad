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
	for (int i = 0; i < LAWNUM; i++) {
		int k = 0;
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
		pressAnyKey();
		clearAlt();
	}
	for (int i = 0; i < VIEWNUM - 3; i++) {
		int k = 0;
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		mvaddstrAlt(k++, 0, i);
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		mvaddstrAlt(k++, 0, issueEventString[i]);
		pressAnyKey();
		clearAlt();
	}
	for (int i = 0; i < VIEWNUM; i++) {
		int k = 0;
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		mvaddstrAlt(k++, 0, i);
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		mvaddstrAlt(k++, 0, discussIssues[i]);
		mvaddstrAlt(k++, 0, CONST_automatedDataTests013);
		mvaddstrAlt(k++, 0, discussesIssues[i]);
		pressAnyKey();
		clearAlt();
	}
	testCreature();

}


// This, this requires a lot of prepwork to test the makecreature(...) method
const string blankString = "";
#include "creature/creature.h"
#include "vehicle/vehicleType.h"
#include "vehicle/vehicle.h"
void testCreature() {

	// This, this requires a lot of prepwork to test the makecreature(...) method
	extern bool multipleCityMode;
	multipleCityMode = false;
	void make_world(bool hasmaps);
	make_world(false);
	bool hasmaps = false;
	bool makelawyer = false;
	bool gaylawyer = false;
	Vehicle * startcar = NULL;
	char recruits = 1;
	char base = 21;
	Creature *newcr = new Creature;
	void initiateNewgameLocations(char base, char recruits, Vehicle * startcar, bool makelawyer, bool gaylawyer, Creature * newcr);
	initiateNewgameLocations(base, recruits, startcar, makelawyer, gaylawyer, newcr);

	extern short lawList[LAWNUM];
	for (int i = 0; i < CREATURENUM; i++) {
		Creature cr;
		for (int j = -2; j < 3; j++) {
			lawList[LAW_GUNCONTROL] = j;
			makecreature(cr, i);
		}
		if (i % 20 == 0) {
			clearAlt();
		}
		mvaddstrAlt(i % 20, 0, cr.name);
		pressAnyKey();

	}
	mvaddstrAlt(21, 0, "TEST COMPLETE");
	// Player should restart at this point.
	pressAnyKey();
}