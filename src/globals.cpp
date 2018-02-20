
#include <includes.h>
#include "creature/creature.h"

#include "common/interval.h"
// needed for creaturetype

#include "vehicle/vehicletype.h"
#include "vehicle/vehicle.h"

#include "creature/creaturetype.h"

#include "creature/augmenttype.h"

#include "common/consolesupport.h"
// for end_cleartype_fix()
#include "title/titlescreen.h"
//for void mode_title();

///
/*
DEBUG DEFINES
*/
// inform player of activated debug codes
bool DISPLAYDEBUG = false;
// Don't save the game
bool NOSAVE = false;
// Enemies don't attack
bool NOENEMYATTACK = false;
// Laws start archconservative
bool SHITLAWS = false;
// Laws start elite liberal
bool PERFECTLAWS = false;
// Public opinion starts at 100% Liberal
bool REVOLUTIONNOW = false;
// Gives you bloody armor
bool GIVEBLOODYARMOR = false;
// Start with lots of money
bool HIGHFUNDS = false;
// Interrogation always enlightens
bool AUTOENLIGHTEN = false;
// Show polls when you can't see things
bool SHOWWAIT = false;
// Show die rolls, 100% accurate poll numbers
bool SHOWMECHANICS = false;
// Make the year 2100
bool THEFUTURE = false;
// Make the founder blind
bool BLIND = false;
// Make the founder unable to walk
bool NOWALK = false;
// Make the founder have no face
bool NOFACE = false;
// Make the founder have a severely injured spine
bool SPINE = false;
// Make the founder have severe internal damage
bool INTERNAL = false;
// Make age not matter for dating or prostitution
bool ZEROMORAL = false;
// Re-seed the Random Number Generator every time it's called
bool MORERANDOM = false;
// Allow experimental, incomplete Stalinist Comrade Squad mode to be chosen for new games
bool ALLOWSTALIN = false;
// Store savefiles in plaintext, making it human readable and editable
bool VERBOSESAVEFILE = false;
// NOVERBOSECOMMENTS only affect anything if VERBOSESAVEFILE is active
// Remove almost all automatically generated comments from verbose savefiles
bool NOVERBOSECOMMENTS = false;




unsigned char bigletters[27][5][7][4];
unsigned char newstops[6][80][5][4];
unsigned char newspic[20][78][18][4];
#include "common/musicClass.h"
MusicClass music;
char homedir[MAX_PATH_SIZE];
char artdir[MAX_PATH_SIZE];
bool multipleCityMode;
unsigned long seed[RNG_SIZE];
vector<ClipType *> cliptype;
vector<WeaponType *> weapontype;
vector<ArmorType *> armortype;

vector<CreatureType *> creaturetype;
vector<AugmentType *> augmenttype;
vector<VehicleType *> vehicletype;
long curcreatureid = 0;
vector<string> default_slogans;
vector<Item *> groundloot;
vector<Vehicle *> vehicle;
char showcarprefs = 1;
siteblockst levelmap[MAPX][MAPY][MAPZ];
chaseseqst chaseseq;
char slogan[SLOGAN_LEN];
vector<squadst *> squad;
squadst *activesquad = NULL;
long cursquadid = 0;
char disbanding = 0;
int disbandtime = 0;
char cantseereason;
short activesortingchoice[SORTINGCHOICENUM];
Creature encounter[ENCMAX];
short mode = GAMEMODE_TITLE;
short offended_corps = 0;
short offended_cia = 0;
short offended_amradio = 0;
short offended_cablenews = 0;
short offended_firemen = 0;
int police_heat = 0;
unsigned long attorneyseed[RNG_SIZE];
int selectedsiege = -1;
char lcityname[CITY_NAMELEN];
char newscherrybusted = 0;
int month = 1;
int year = THEFUTURE ? 2100 : 2009;
int amendnum = 28;
bool termlimits = false;
bool deagle = false;
bool m249 = false;
UniqueCreatures uniqueCreatures;
short attitude[VIEWNUM];
short public_interest[VIEWNUM];
short background_liberal_influence[VIEWNUM];
short lawList[LAWNUM];
short house[HOUSENUM];
short senate[SENATENUM];
short court[COURTNUM];
char courtname[COURTNUM][POLITICIAN_NAMELEN];
short exec[EXECNUM];
short execterm = 1;
char execname[EXECNUM][POLITICIAN_NAMELEN];
short presparty = CONSERVATIVE_PARTY;
char oldPresidentName[POLITICIAN_NAMELEN];
int stat_recruits = 0;
int stat_kidnappings = 0;
int stat_dead = 0;
int stat_kills = 0;
int stat_buys = 0;
int stat_burns = 0;
int ustat_recruits = 0;
int ustat_kidnappings = 0;
int ustat_dead = 0;
int ustat_kills = 0;
int ustat_funds = 0;
int ustat_spent = 0;
int ustat_buys = 0;
int ustat_burns = 0;
int locx;
int locy;
int locz;
short sitetype;
short sitealienate;
short sitealarm;
short sitealarmtimer;
short postalarmtimer;
short siteonfire;
int sitecrime;
short cursite;
bool mapshowing = false;
bool encounterwarnings = false;
char foughtthisround = 0;
short interface_pgup = '[';
short interface_pgdn = ']';
int day = 1;
short party_status = -1;
short wincondition = WINCONDITION_ELITE;
short fieldskillrate = FIELDSKILLRATE_FAST;
bool notermlimit;           //These determine if ELAs can take place --kviiri
bool nocourtpurge;
bool stalinmode;
char endgamestate = ENDGAME_NONE;
CCSexposure ccsexposure = CCSEXPOSURE_NONE;
char ccs_kills = 0;
int ccs_siege_kills = 0;
int ccs_boss_kills = 0;
vector<datest *> date;
vector<recruitst *> recruit;
vector<newsstoryst *> newsstory;
newsstoryst *sitestory = NULL;

int yourscore = -1;

title_screen *TitleScreen;

#include "common/creaturePool.h"
#include "locations/locationsPool.h"
#include "items/itemPool.h"
#include "items/lootTypePool.h"
void delete_and_clear_sitemaps();
int endwinAlt(void);
/* Free memory and exit the game */
void end_game(int err)
{
#ifdef WIN32
	end_cleartype_fix(); // won't do anything unless fixcleartype is true
#endif
	delete TitleScreen;
	LocationsPool::getInstance().delete_and_clear_pool();
	delete_and_clear(squad);
	delete_and_clear(weapontype);
	delete_and_clear(cliptype);
	delete_and_clear(armortype);
	LootTypePool::getInstance().delete_and_clear_pool();
	delete_and_clear(creaturetype);
	delete_and_clear(augmenttype);
	delete_and_clear(vehicletype);
	delete_and_clear(vehicle);
	CreaturePool::getInstance().delete_and_clear_pool();
	delete_and_clear_sitemaps();
	delete_and_clear(recruit);
	delete_and_clear(date);
	delete_and_clear(groundloot);
	music.quit(); // shut down music
	endwinAlt();
	exit(err);
}