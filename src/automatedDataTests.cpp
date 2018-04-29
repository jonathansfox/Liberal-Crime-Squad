#include "includes.h"
const string CONST_automatedDataTests013 = "TEST";
const string CONST_automatedDataTests008 = "SUCCESS";

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
void automatedDataTests() {
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
}