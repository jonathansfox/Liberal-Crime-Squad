




/*
	File created by Chris Johnson.
	These were previously all in game.cpp.

	This file includes all the the enums, defines, and included headers required globally by all components.

	All code released under GNU GPL.
*/
#include <windows.h>
#include <vector>
#include <map>
#include <deque>
#include "cmarkup/Markup.h"
using namespace std;

#include "includesLen.h"
#include <iostream>
#include "includesDeprecated.h"

enum EndGameStatus
{
	ENDGAME_NONE,
	ENDGAME_CCS_APPEARANCE,
	ENDGAME_CCS_ATTACKS,
	ENDGAME_CCS_SIEGES,
	ENDGAME_CCS_DEFEATED,
	ENDGAME_MARTIALLAW,
	ENDGAMENUM
};

enum CCSexposure
{
	CCSEXPOSURE_NONE,
	CCSEXPOSURE_LCSGOTDATA,
	CCSEXPOSURE_EXPOSED,
	CCSEXPOSURE_NOBACKERS,
	CCSEXPOSURENUM
};

enum Views
{
	VIEW_STALIN = -2, // this one is -2 and is actually calculated based on views >=0 and <VIEWNUM-3
	VIEW_MOOD, // this one is -1 and is likewise calculated based on views >=0 and <VIEWNUM-3
	VIEW_GAY, // view #0, the first one that is actually in the attitude[] array
	VIEW_DEATHPENALTY,
	VIEW_TAXES,
	VIEW_NUCLEARPOWER,
	VIEW_ANIMALRESEARCH,
	VIEW_POLICEBEHAVIOR,
	VIEW_TORTURE,
	VIEW_INTELLIGENCE,
	VIEW_FREESPEECH,
	VIEW_GENETICS,
	VIEW_JUSTICES,
	VIEW_GUNCONTROL,
	VIEW_SWEATSHOPS,
	VIEW_POLLUTION,
	VIEW_CORPORATECULTURE,
	VIEW_CEOSALARY,
	VIEW_WOMEN,//XXX: VIEW_ABORTION DOES NOT EXIST
	VIEW_CIVILRIGHTS,
	VIEW_DRUGS,
	VIEW_IMMIGRATION,
	VIEW_MILITARY,
	VIEW_PRISONS,
	//*JDS* I'm using VIEWNUM-5 in a random generator that rolls a
	//random issue, not including the media/politicalviolence ones, and this will
	//break if these stop being the last 4 issues; do a search
	//for VIEWNUM-5 to change it if it needs to be changed.
	VIEW_AMRADIO,
	VIEW_CABLENEWS,
	//THESE THREE MUST BE LAST FOR VIEWNUM-3 TO WORK IN PLACES
	VIEW_LIBERALCRIMESQUAD,
	VIEW_LIBERALCRIMESQUADPOS,
	//THIS ONE MUST BE LAST. randomissue RELIES ON IT BEING LAST TO IGNORE IT IF
	//CCS IS DEAD.
	VIEW_CONSERVATIVECRIMESQUAD,
	VIEWNUM
};


enum Laws
{
	LAW_STALIN = -2, // not a real law: this is -2 and is actually calculated based on views >=0 and <VIEWNUM-3
	LAW_MOOD, // not a real law: this is -1 and is likewise calculated based on views >=0 and <VIEWNUM-3
	LAW_ABORTION, // law #0, the first one that is actually in the law[] array
	LAW_ANIMALRESEARCH,
	LAW_POLICEBEHAVIOR,
	LAW_PRIVACY,
	LAW_DEATHPENALTY,
	LAW_NUCLEARPOWER,
	LAW_POLLUTION,
	LAW_LABOR,
	LAW_GAY,
	LAW_CORPORATE,
	LAW_FREESPEECH,
	LAW_FLAGBURNING,
	LAW_GUNCONTROL,
	LAW_TAX,
	LAW_WOMEN,
	LAW_CIVILRIGHTS,
	LAW_DRUGS,
	LAW_IMMIGRATION,
	LAW_ELECTIONS,
	LAW_MILITARY,
	LAW_PRISONS,
	LAW_TORTURE,
	LAWNUM
};

enum Crimes
{
	CRIME_STOLEGROUND,
	CRIME_UNLOCKEDDOOR,
	CRIME_BROKEDOWNDOOR,
	CRIME_ATTACKED_MISTAKE,
	CRIME_ATTACKED,
	CRIME_CARCHASE,
	CRIME_CARCRASH,
	CRIME_FOOTCHASE,
	CRIME_KILLEDSOMEBODY,
	CRIME_SHUTDOWNREACTOR,
	CRIME_POLICE_LOCKUP,
	CRIME_COURTHOUSE_LOCKUP,
	CRIME_PRISON_RELEASE,
	CRIME_JURYTAMPERING,
	CRIME_HACK_INTEL,
	CRIME_BREAK_SWEATSHOP,
	CRIME_BREAK_FACTORY,
	CRIME_HOUSE_PHOTOS,
	CRIME_CORP_FILES,
	CRIME_FREE_RABBITS,
	CRIME_FREE_BEASTS,
	CRIME_ARSON,
	CRIME_TAGGING,
	CRIME_ARMORY,
	CRIME_VANDALISM,
	CRIME_BANKVAULTROBBERY,
	CRIME_BANKTELLERROBBERY,
	CRIME_BANKSTICKUP,
	CRIMENUM
};

enum NewsStories
{
	NEWSSTORY_MAJOREVENT,
	NEWSSTORY_SQUAD_SITE,
	NEWSSTORY_SQUAD_ESCAPED,
	NEWSSTORY_SQUAD_FLEDATTACK,
	NEWSSTORY_SQUAD_DEFENDED,
	NEWSSTORY_SQUAD_BROKESIEGE,
	NEWSSTORY_SQUAD_KILLED_SIEGEATTACK,
	NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE,
	NEWSSTORY_SQUAD_KILLED_SITE,
	NEWSSTORY_CCS_SITE,
	NEWSSTORY_CCS_DEFENDED,
	NEWSSTORY_CCS_KILLED_SIEGEATTACK,
	NEWSSTORY_CCS_KILLED_SITE,
	NEWSSTORY_CARTHEFT,
	NEWSSTORY_MASSACRE,
	NEWSSTORY_KIDNAPREPORT,
	NEWSSTORY_NUDITYARREST,
	NEWSSTORY_WANTEDARREST,
	NEWSSTORY_DRUGARREST,
	NEWSSTORY_GRAFFITIARREST,
	NEWSSTORY_BURIALARREST,
	NEWSSTORY_RAID_CORPSESFOUND,
	NEWSSTORY_RAID_GUNSFOUND,
	NEWSSTORY_HOSTAGE_RESCUED,
	NEWSSTORY_HOSTAGE_ESCAPES,
	NEWSSTORY_CCS_NOBACKERS,
	NEWSSTORY_CCS_DEFEATED,
	NEWSSTORY_PRESIDENT_IMPEACHED,
	NEWSSTORY_PRESIDENT_BELIEVED_DEAD,
	NEWSSTORY_PRESIDENT_FOUND_DEAD,
	NEWSSTORY_PRESIDENT_FOUND,
	NEWSSTORY_PRESIDENT_KIDNAPPED,
	NEWSSTORY_PRESIDENT_MISSING,
	NEWSSTORY_PRESIDENT_ASSASSINATED,
	NEWSSTORYNUM
};
#include "includesRandom.h"
/* This is declared again lower down, just needed here for this header. */
std::string tostring(long i);

//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

//int get_associated_attribute(int skill_type);
#include "includesSDS.h"
#include "includesSDS2.h"
//#ifdef	NEWS_CPP
// news.cpp

#include "../creature/creature.h"
////

#include "../creature/deprecatedCreatureC.h"

////
#include "../locations/locations.h"
#include "../common/commonactions.h"
inline char* strcpy(char* dest, const std::string& src) { return strcpy(dest, src.c_str()); }
inline char* strcat(char* dest, const std::string& src) { return strcat(dest, src.c_str()); }
inline char* strcat(char* dest, long src) { return strcat(dest, tostring(src)); }
#include "../common/getnames.h"
#include "../common/misc.h"
// from cursesgraphics.h
#define CH_BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL 0xc5
#define CH_FULL_BLOCK 0xdb
#define CH_LIGHT_SHADE 0xb0
#define CH_MEDIUM_SHADE 0xb1
#define CH_DARK_SHADE 0xb2
// from daily.h
int monthday();
#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include "../common/creaturePool.h"
#include "../locations/locationsPool.h"
#include "../cursesmovie.h"
vector<Deprecatednewsstoryst *> newsstory;
Deprecatednewsstoryst* lastNewsStory() {
	return newsstory[len(newsstory) - 1];
}
#include "../common/musicClass.h"

extern bool multipleCityMode;
extern CCSexposure ccsexposure;
extern char endgamestate;
extern char lcityname[CITY_NAMELEN];
extern char newscherrybusted;
extern char oldPresidentName[POLITICIAN_NAMELEN];
extern CursesMoviest movie;
extern int month;
extern int year;
extern MusicClass music;
extern short attitude[VIEWNUM];
extern short house[HOUSENUM];
extern short lawList[LAWNUM];
extern short public_interest[VIEWNUM];
extern short senate[SENATENUM];
extern string slogan_str;
extern unsigned char bigletters[27][5][7][4];
extern unsigned char newspic[20][78][18][4];
extern unsigned char newstops[6][80][5][4];


map<short, vector<string> > newsStories;
map<short, string> cityNames;
vector<string> liberalCrime;
vector<string> AMorPM;
vector<string> book_title;
vector<string> book_title_2;
vector<string> random_nationality;
vector<string> conservative_oppose_book;
vector<string> radio_name;
vector<string> radio_name_2;
vector<string> vigilante_murder;
vector<string> why_chase_ended;
vector<string> crazy_conservative_act;
vector<string> bribe_officers;
vector<string> my_idol;
vector<string> prison_book_title;
vector<string> prison_book_title_2;
vector<string> mutilated_corpse;
vector<string> evidence_of_child_murder;
vector<string> break_in_murder_case;
vector<string> animal_research_country;
vector<string> drug_name;
vector<string> drug_name_2;
vector<string> chimp_drug_impact;
vector<string> chimp_drug_horror;
vector<string> terrorist_group;
vector<string> terrorist_plot;
vector<string> terrorist_plot_no_free_speech;
vector<string> gene_corp_name;
vector<string> gene_corp_name_2;
vector<string> gene_product_name;
vector<string> gene_product_name_2;
vector<string> gene_product_benefit;
vector<string> gene_product_cost;
vector<string> bullshit_no_free_speech;
vector<string> bullshit;
vector<string> petty_violence;
vector<string> his_her;
vector<string> older_younger;
vector<string> brother_sister;
vector<string> judge_with_prostitute;
vector<string> judge_with_prostitute_no_free_speech;
vector<string> judge_with_prostitute_full_free_speech;
vector<string> radio_host_crazy_quote;
vector<string> radio_host_lost_mind;
vector<string> family_values_company_name;
vector<string> family_values_company_name_2;
vector<string> family_values_company_name_3;
vector<string> pollution_consumption;
vector<string> pollution_consumption_2;
vector<string> i_like_polution;
vector<string> distrust_liberals;
vector<string> tech_giant_name;
vector<string> tech_giant_name_2;
vector<string> fm_radio_name;
vector<string> fm_radio_name_2;
vector<string> public_place;
vector<string> reagan_bad;
vector<string> reagan_bad_2;
vector<string> ceo_behaving_badly;
vector<string> reagan_good;
vector<string> reagan_good_2;
vector<string> cable_name;
vector<string> cable_name_2;
vector<string> cable_city;
vector<string> cable_city_2;
vector<string> ccs_adjective;
vector<string> ccs_adjective_2;
vector<string> ccs_adjective_3;
vector<string> ccs_noun;
vector<string> personalAds;
vector<string> personalAdsLG;
vector<string> caseNEWSSTORY_CCS_DEFEATED;
vector<string> caseNEWSSTORY_CCS_NOBACKERS;
vector<vector<string> > adListB;
vector<vector<string> > adList;
const int AD_LENGTH = 4;
#include "../customMaps.h"

void displaynewspicture(int p, int y);
void displaycenterednewsfont(const std::string& str, int y);
void preparepage(const Deprecatednewsstoryst ns, const bool liberalguardian);

const vector<int> randombox = {
	CH_LIGHT_SHADE,
	CH_MEDIUM_SHADE,
	CH_DARK_SHADE,
	CH_FULL_BLOCK,
	CH_BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL,
	'*'
};
string sexdesc();
string sexwho();
string sexseek();
string sextype();

string constructeventstory(const short view, const char positive);

const int PICTURE_MUTANT_BEAST = 0;
const int PICTURE_CEO = 1;
const int PICTURE_BOOK = 2;
const int PICTURE_MELTDOWN = 3;
const int PICTURE_GENETICS = 4;
const int PICTURE_RIVERFIRE = 5;
const int PICTURE_DOLLARS = 6;
const int PICTURE_TINKYWINKY = 7;
const int PICTURE_OIL = 8;
const int PICTURE_TERRORISTS = 9;
const int PICTURE_KKK = 10;
const int PICTURE_TSHIRT = 11;

//#endif//NEWS_CPP
//#endif// INCLUDES_H_INCLUDED
