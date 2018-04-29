#include "includes.h"
const string CONST_externallyStoredText022 = "NOVERBOSECOMMENTS";
const string CONST_externallyStoredText021 = "VERBOSESAVEFILE";
const string CONST_externallyStoredText020 = "ALLOWSTALIN";
const string CONST_externallyStoredText019 = "MORERANDOM";
const string CONST_externallyStoredText018 = "ZEROMORAL";
const string CONST_externallyStoredText017 = "INTERNAL";
const string CONST_externallyStoredText016 = "SPINE";
const string CONST_externallyStoredText015 = "NOFACE";
const string CONST_externallyStoredText014 = "NOWALK";
const string CONST_externallyStoredText013 = "BLIND";
const string CONST_externallyStoredText012 = "THEFUTURE";
const string CONST_externallyStoredText011 = "SHOWMECHANICS";
const string CONST_externallyStoredText010 = "SHOWWAIT";
const string CONST_externallyStoredText009 = "AUTOENLIGHTEN";
const string CONST_externallyStoredText008 = "HIGHFUNDS";
const string CONST_externallyStoredText007 = "GIVEBLOODYARMOR";
const string CONST_externallyStoredText006 = "REVOLUTIONNOW";
const string CONST_externallyStoredText005 = "PERFECTLAWS";
const string CONST_externallyStoredText004 = "SHITLAWS";
const string CONST_externallyStoredText003 = "NOENEMYATTACK";
const string CONST_externallyStoredText002 = "NOSAVE";
const string CONST_externallyStoredText001 = "DISPLAYDEBUG";
using namespace std;

#include "../creature/creatureEnums.h"
#include <queue>
#include <map>
const string blankString = "";
#include "../customMaps.h"
extern Log gamelog;
struct pointerAndString {
	bool *super_collection;
	string fileName;
	pointerAndString(bool *super_, const string& file_) : fileName(file_), super_collection(super_) {}
};
vector<pointerAndString> debug_defines = {
	pointerAndString(&DISPLAYDEBUG, CONST_externallyStoredText001),
	pointerAndString(&NOSAVE, CONST_externallyStoredText002),
	pointerAndString(&NOENEMYATTACK, CONST_externallyStoredText003),
	pointerAndString(&SHITLAWS, CONST_externallyStoredText004),
	pointerAndString(&PERFECTLAWS, CONST_externallyStoredText005),
	pointerAndString(&REVOLUTIONNOW, CONST_externallyStoredText006),
	pointerAndString(&GIVEBLOODYARMOR, CONST_externallyStoredText007),
	pointerAndString(&HIGHFUNDS, CONST_externallyStoredText008),
	pointerAndString(&AUTOENLIGHTEN, CONST_externallyStoredText009),
	pointerAndString(&SHOWWAIT, CONST_externallyStoredText010),
	pointerAndString(&SHOWMECHANICS, CONST_externallyStoredText011),
	pointerAndString(&THEFUTURE, CONST_externallyStoredText012),
	pointerAndString(&BLIND, CONST_externallyStoredText013),
	pointerAndString(&NOWALK, CONST_externallyStoredText014),
	pointerAndString(&NOFACE, CONST_externallyStoredText015),
	pointerAndString(&SPINE, CONST_externallyStoredText016),
	pointerAndString(&INTERNAL, CONST_externallyStoredText017),
	pointerAndString(&ZEROMORAL, CONST_externallyStoredText018),
	pointerAndString(&MORERANDOM, CONST_externallyStoredText019),
	pointerAndString(&ALLOWSTALIN, CONST_externallyStoredText020),
	pointerAndString(&VERBOSESAVEFILE, CONST_externallyStoredText021),
	pointerAndString(&NOVERBOSECOMMENTS, CONST_externallyStoredText022)
};