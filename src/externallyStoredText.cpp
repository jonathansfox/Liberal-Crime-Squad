



#include <iostream>
#include <vector>
using namespace std;


const string CONST_NOVERBOSECOMMENTS = "NOVERBOSECOMMENTS";
const string CONST_VERBOSESAVEFILE = "VERBOSESAVEFILE";
const string CONST_ALLOWSTALIN = "ALLOWSTALIN";
const string CONST_MORERANDOM = "MORERANDOM";
const string CONST_ZEROMORAL = "ZEROMORAL";
const string CONST_INTERNAL = "INTERNAL";
const string CONST_SPINE = "SPINE";
const string CONST_NOFACE = "NOFACE";
const string CONST_NOWALK = "NOWALK";
const string CONST_BLIND = "BLIND";
const string CONST_THEFUTURE = "THEFUTURE";
const string CONST_SHOWMECHANICS = "SHOWMECHANICS";
const string CONST_SHOWWAIT = "SHOWWAIT";
const string CONST_AUTOENLIGHTEN = "AUTOENLIGHTEN";
const string CONST_HIGHFUNDS = "HIGHFUNDS";
const string CONST_GIVEBLOODYARMOR = "GIVEBLOODYARMOR";
const string CONST_REVOLUTIONNOW = "REVOLUTIONNOW";
const string CONST_PERFECTLAWS = "PERFECTLAWS";
const string CONST_SHITLAWS = "SHITLAWS";
const string CONST_NOENEMYATTACK = "NOENEMYATTACK";
const string CONST_NOSAVE = "NOSAVE";
const string CONST_DISPLAYDEBUG = "DISPLAYDEBUG";

struct pointerAndString {
	bool* super_collection;
	string fileName;
	pointerAndString(bool* super_, const string& file_) : fileName(file_), super_collection(super_) {}
};

/*
DEBUG DEFINES
*/
// inform player of ACTIVATED debug codes
extern bool DISPLAYDEBUG;
// Don't save the game
extern bool NOSAVE;
// Enemies don't attack
extern bool NOENEMYATTACK;
// Laws start archconservative
extern bool SHITLAWS;
// Laws start elite liberal
extern bool PERFECTLAWS;
// Public opinion starts at 100% Liberal
extern bool REVOLUTIONNOW;
// Gives you bloody armor
extern bool GIVEBLOODYARMOR;
// Start with lots of money
extern bool HIGHFUNDS;
// Interrogation always enlightens
extern bool AUTOENLIGHTEN;
// Show polls when you can't see things
extern bool SHOWWAIT;
// Show die rolls, 100% accurate poll numbers
extern bool SHOWMECHANICS;
// Make the year 2100
extern bool THEFUTURE;
// Make the founder blind
extern bool BLIND;
// Make the founder unable to walk
extern bool NOWALK;
// Make the founder have no face
extern bool NOFACE;
// Make the founder have a severely injured spine
extern bool SPINE;
// Make the founder have severe internal damage
extern bool INTERNAL;
// Make age not matter for dating or prostitution
extern bool ZEROMORAL;
// Re-seed the Random Number Generator every time it's called
extern bool MORERANDOM;
// Allow experimental, incomplete Stalinist Comrade Squad mode to be chosen for new games
extern bool ALLOWSTALIN;
// Store savefiles in plaintext, making it human readable and editable
extern bool VERBOSESAVEFILE;
// NOVERBOSECOMMENTS only affect anything if VERBOSESAVEFILE is active
// Remove almost all automatically generated comments from verbose savefiles
extern bool NOVERBOSECOMMENTS;

vector<pointerAndString> debug_defines = {
	pointerAndString(&DISPLAYDEBUG, CONST_DISPLAYDEBUG),
	pointerAndString(&NOSAVE, CONST_NOSAVE),
	pointerAndString(&NOENEMYATTACK, CONST_NOENEMYATTACK),
	pointerAndString(&SHITLAWS, CONST_SHITLAWS),
	pointerAndString(&PERFECTLAWS, CONST_PERFECTLAWS),
	pointerAndString(&REVOLUTIONNOW, CONST_REVOLUTIONNOW),
	pointerAndString(&GIVEBLOODYARMOR, CONST_GIVEBLOODYARMOR),
	pointerAndString(&HIGHFUNDS, CONST_HIGHFUNDS),
	pointerAndString(&AUTOENLIGHTEN, CONST_AUTOENLIGHTEN),
	pointerAndString(&SHOWWAIT, CONST_SHOWWAIT),
	pointerAndString(&SHOWMECHANICS, CONST_SHOWMECHANICS),
	pointerAndString(&THEFUTURE, CONST_THEFUTURE),
	pointerAndString(&BLIND, CONST_BLIND),
	pointerAndString(&NOWALK, CONST_NOWALK),
	pointerAndString(&NOFACE, CONST_NOFACE),
	pointerAndString(&SPINE, CONST_SPINE),
	pointerAndString(&INTERNAL, CONST_INTERNAL),
	pointerAndString(&ZEROMORAL, CONST_ZEROMORAL),
	pointerAndString(&MORERANDOM, CONST_MORERANDOM),
	pointerAndString(&ALLOWSTALIN, CONST_ALLOWSTALIN),
	pointerAndString(&VERBOSESAVEFILE, CONST_VERBOSESAVEFILE),
	pointerAndString(&NOVERBOSECOMMENTS, CONST_NOVERBOSECOMMENTS)
};
