using namespace std;

#include <includes.h>
#include "creature/creatureEnums.h"

#include <queue>
#include <map>
#include <customMaps.h>
extern Log gamelog;

struct pointerAndString {
	bool *super_collection;
	string fileName;
	pointerAndString(bool *super_, string file_) : fileName(file_), super_collection(super_) {}

};
vector<pointerAndString> debug_defines = {
	pointerAndString(&DISPLAYDEBUG, "DISPLAYDEBUG"),
	pointerAndString(&NOSAVE, "NOSAVE"),
	pointerAndString(&NOENEMYATTACK, "NOENEMYATTACK"),
	pointerAndString(&SHITLAWS, "SHITLAWS"),
	pointerAndString(&PERFECTLAWS, "PERFECTLAWS"),
	pointerAndString(&REVOLUTIONNOW, "REVOLUTIONNOW"),
	pointerAndString(&GIVEBLOODYARMOR, "GIVEBLOODYARMOR"),
	pointerAndString(&HIGHFUNDS, "HIGHFUNDS"),
	pointerAndString(&AUTOENLIGHTEN, "AUTOENLIGHTEN"),
	pointerAndString(&SHOWWAIT, "SHOWWAIT"),
	pointerAndString(&SHOWMECHANICS, "SHOWMECHANICS"),
	pointerAndString(&THEFUTURE, "THEFUTURE"),
	pointerAndString(&BLIND, "BLIND"),
	pointerAndString(&NOWALK, "NOWALK"),
	pointerAndString(&NOFACE, "NOFACE"),
	pointerAndString(&SPINE, "SPINE"),
	pointerAndString(&INTERNAL, "INTERNAL"),
	pointerAndString(&ZEROMORAL, "ZEROMORAL"),
	pointerAndString(&MORERANDOM, "MORERANDOM"),
	pointerAndString(&ALLOWSTALIN, "ALLOWSTALIN"),
	pointerAndString(&VERBOSESAVEFILE, "VERBOSESAVEFILE"),
	pointerAndString(&NOVERBOSECOMMENTS, "NOVERBOSECOMMENTS")
};