/*
Copyright (c) 2002,2003,2004 by Tarn Adams                                            //
                                                                                      //
This file is part of Liberal Crime Squad.                                             //
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
//TODO: Add logging for this file? --Addictgamer

#include <includes.h>
#include "creature/creature.h"

#include "common/commonactions.h"

//#include "common/stringconversion.h"
inline char* strcpy(char* dest, const std::string& src) { return strcpy(dest, src.c_str()); }
inline char* strcat(char* dest, const std::string& src) { return strcat(dest, src.c_str()); }
inline char* strcat(char* dest, long src) { return strcat(dest, tostring(src)); }

#include "common/consolesupport.h"
// for void set_color(short,short,bool)

#include "common/getnames.h"
#include "common/misc.h"

// cursesgraphics.h
#define CH_BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL 0xc5
#define CH_FULL_BLOCK 0xdb
#define CH_LIGHT_SHADE 0xb0
#define CH_MEDIUM_SHADE 0xb1
#define CH_DARK_SHADE 0xb2

// daily.h
int monthday();

#include <cursesAlternative.h>
#include <set_color_support.h>

#include "common/creaturePool.h"
#include "locations/locationsPool.h"

#include "cursesmovie.h"
extern CursesMoviest movie;

extern string singleSpace;

extern vector<newsstoryst *> newsstory;
extern short attitude[VIEWNUM];
extern char lcityname[CITY_NAMELEN];
extern short lawList[LAWNUM];
extern string commaSpace;
extern char slogan[SLOGAN_LEN];
extern unsigned char bigletters[27][5][7][4];
extern unsigned char newstops[6][80][5][4];
extern unsigned char newspic[20][78][18][4];
extern short public_interest[VIEWNUM];
extern short house[HOUSENUM];
extern short senate[SENATENUM];
extern char newscherrybusted;
extern char oldPresidentName[POLITICIAN_NAMELEN];
extern bool multipleCityMode;
#include "common/musicClass.h"
extern MusicClass music;
extern char endgamestate;
 string ampersandR;
 extern string spaceDashSpace;
 extern string singleDot;


string membersOfLCS;
string lcsSpokeseperson;
string policeSpokesperson;
string AND;
typedef map<short, string > shortAndString;
typedef map<short, vector<string>> shortAndTwoStrings;
shortAndTwoStrings newsStories;
shortAndString cityNames;
string accordingToSourcesAtScene;
string accordingToPoliceSources;
string ampersandC;


extern int day;
extern int month;
extern int year;

extern short presparty;
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
vector<vector<string>> adListB;
vector<vector<string>> adList;
const int AD_LENGTH = 4;
const string majorevent = "majorevent\\";
const string mostlyendings = "mostlyendings\\";
#include <customMaps.h>
vector<file_and_text_collection> majorevent_text_file_collection = {


	/*majorevent.cpp*/
	customText(&liberalCrime, majorevent + "liberalCrime.txt"),
	customText(&AMorPM, majorevent + "AMorPM.txt"),
	customText(&book_title, majorevent + "book_title.txt"),
	customText(&book_title_2, majorevent + "book_title_2.txt"),
	customText(&random_nationality, majorevent + "random_nationality.txt"),
	customText(&conservative_oppose_book, majorevent + "conservative_oppose_book.txt"),
	customText(&radio_name, majorevent + "radio_name.txt"),
	customText(&radio_name_2, majorevent + "radio_name_2.txt"),
	customText(&vigilante_murder, majorevent + "vigilante_murder.txt"),
	customText(&why_chase_ended, majorevent + "why_chase_ended.txt"),
	customText(&crazy_conservative_act, majorevent + "crazy_conservative_act.txt"),
	customText(&bribe_officers, majorevent + "bribe_officers.txt"),
	customText(&my_idol, majorevent + "my_idol.txt"),
	customText(&prison_book_title, majorevent + "prison_book_title.txt"),
	customText(&prison_book_title_2, majorevent + "prison_book_title_2.txt"),
	customText(&mutilated_corpse, majorevent + "mutilated_corpse.txt"),
	customText(&evidence_of_child_murder, majorevent + "evidence_of_child_murder.txt"),
	customText(&break_in_murder_case, majorevent + "break_in_murder_case.txt"),
	customText(&animal_research_country, majorevent + "animal_research_country.txt"),
	customText(&drug_name, majorevent + "drug_name.txt"),
	customText(&drug_name_2, majorevent + "drug_name_2.txt"),
	customText(&chimp_drug_impact, majorevent + "chimp_drug_impact.txt"),
	customText(&chimp_drug_horror, majorevent + "chimp_drug_horror.txt"),
	customText(&terrorist_group, majorevent + "terrorist_group.txt"),
	customText(&terrorist_plot, majorevent + "terrorist_plot.txt"),
	customText(&terrorist_plot_no_free_speech, majorevent + "terrorist_plot_no_free_speech.txt"),
	customText(&gene_corp_name, majorevent + "gene_corp_name.txt"),
	customText(&gene_corp_name_2, majorevent + "gene_corp_name_2.txt"),
	customText(&gene_product_name, majorevent + "gene_product_name.txt"),
	customText(&gene_product_name_2, majorevent + "gene_product_name_2.txt"),
	customText(&gene_product_benefit, majorevent + "gene_product_benefit.txt"),
	customText(&gene_product_cost, majorevent + "gene_product_cost.txt"),
	customText(&bullshit_no_free_speech, majorevent + "bullshit_no_free_speech.txt"),
	customText(&bullshit, majorevent + "bullshit.txt"),
	customText(&petty_violence, majorevent + "petty_violence.txt"),
	customText(&his_her, majorevent + "his_her.txt"),
	customText(&older_younger, majorevent + "older_younger.txt"),
	customText(&brother_sister, majorevent + "brother_sister.txt"),
	customText(&judge_with_prostitute, majorevent + "judge_with_prostitute.txt"),
	customText(&judge_with_prostitute_no_free_speech, majorevent + "judge_with_prostitute_no_free_speech.txt"),
	customText(&judge_with_prostitute_full_free_speech, majorevent + "judge_with_prostitute_full_free_speech.txt"),
	customText(&radio_host_crazy_quote, majorevent + "radio_host_crazy_quote.txt"),
	customText(&radio_host_lost_mind, majorevent + "radio_host_lost_mind.txt"),
	customText(&family_values_company_name, majorevent + "family_values_company_name.txt"),
	customText(&family_values_company_name_2, majorevent + "family_values_company_name_2.txt"),
	customText(&family_values_company_name_3, majorevent + "family_values_company_name_3.txt"),
	customText(&pollution_consumption, majorevent + "pollution_consumption.txt"),
	customText(&pollution_consumption_2, majorevent + "pollution_consumption_2.txt"),
	customText(&i_like_polution, majorevent + "i_like_polution.txt"),
	customText(&distrust_liberals, majorevent + "distrust_liberals.txt"),
	customText(&tech_giant_name, majorevent + "tech_giant_name.txt"),
	customText(&tech_giant_name_2, majorevent + "tech_giant_name_2.txt"),
	customText(&fm_radio_name, majorevent + "fm_radio_name.txt"),
	customText(&fm_radio_name_2, majorevent + "fm_radio_name_2.txt"),
	customText(&public_place, majorevent + "public_place.txt"),
	customText(&reagan_bad, majorevent + "reagan_bad.txt"),
	customText(&reagan_bad_2, majorevent + "reagan_bad_2.txt"),
	customText(&ceo_behaving_badly, majorevent + "ceo_behaving_badly.txt"),
	customText(&reagan_good, majorevent + "reagan_good.txt"),
	customText(&reagan_good_2, majorevent + "reagan_good_2.txt"),
	customText(&cable_name, majorevent + "cable_name.txt"),
	customText(&cable_name_2, majorevent + "cable_name_2.txt"),
	customText(&cable_city, majorevent + "cable_city.txt"),
	customText(&cable_city_2, majorevent + "cable_city_2.txt"),
	/*squadstory_text.cpp*/
	customText(&ccs_adjective, majorevent + "ccs_adjective.txt"),
	customText(&ccs_adjective_2, majorevent + "ccs_adjective_2.txt"),
	customText(&ccs_adjective_3, majorevent + "ccs_adjective_3.txt"),
	customText(&ccs_noun, majorevent + "ccs_noun.txt"),


	customText(&personalAds, mostlyendings + "personalAds.txt"),
	customText(&personalAdsLG, mostlyendings + "personalAdsLG.txt"),

	customText(&adList, mostlyendings + "adList.txt", AD_LENGTH),
	customText(&adListB, mostlyendings + "adListB.txt", AD_LENGTH),
	customText(&caseNEWSSTORY_CCS_DEFEATED, mostlyendings + "caseNEWSSTORY_CCS_DEFEATED.txt"),
	customText(&caseNEWSSTORY_CCS_NOBACKERS, mostlyendings + "caseNEWSSTORY_CCS_NOBACKERS.txt"),
};

newsstoryst* ccs_strikes_story()
{
	newsstoryst *ns = new newsstoryst;
	// Chance of CCS squad wipe
	if (LCSrandom(10))ns->type = NEWSSTORY_CCS_SITE;
	else ns->type = NEWSSTORY_CCS_KILLED_SITE;
	// Chance of positive CCS story
	ns->positive = true;
	do {
		ns->loc = LCSrandom(LocationsPool::getInstance().lenpool());
	} while (LocationsPool::getInstance().getRentingType(ns->loc) != -1);
	return ns;
}
newsstoryst* ccs_fbi_raid_story()
{
	newsstoryst* ns = new newsstoryst;
	ns->type = NEWSSTORY_CCS_DEFEATED;
	ns->priority = 8000;
	endgamestate = ENDGAME_CCS_DEFEATED;
	// arrest or kill ccs sleepers
	CreaturePool::getInstance().arrestOrKillCCSSleepers();
	LocationsPool::getInstance().hideCCSSafehouses();
	// go militarized police
	change_public_opinion(VIEW_POLICEBEHAVIOR, -20);
	return ns;
}

newsstoryst* ccs_exposure_story()
{
	newsstoryst* ns = new newsstoryst;
	ns->type = NEWSSTORY_CCS_NOBACKERS;
	ns->priority = 8000;
	ccsexposure = CCSEXPOSURE_NOBACKERS;
	// arrest seventeen representatives and eight senators
	int arrestsleft = 8;
	for (int i = 0; i < SENATENUM; i++)
	{
		if ((senate[i] == -2 || senate[i] == -1) && !LCSrandom(4))
		{
			senate[i] = ALIGN_ELITELIBERAL;
			arrestsleft--;
			if (arrestsleft <= 0) break;
		}
	}
	arrestsleft = 17;
	for (int i = 0; i < HOUSENUM; i++)
	{
		if ((house[i] == -2 || house[i] == -1) && !LCSrandom(4))
		{
			house[i] = ALIGN_ELITELIBERAL;
			arrestsleft--;
			if (arrestsleft <= 0) break;
		}
	}
	// change police regulation issue to be more liberal
	lawList[LAW_POLICEBEHAVIOR] += 2;
	if (lawList[LAW_POLICEBEHAVIOR] > ALIGN_ELITELIBERAL)
		lawList[LAW_POLICEBEHAVIOR] = ALIGN_ELITELIBERAL;
	change_public_opinion(VIEW_POLICEBEHAVIOR, 50);
	change_public_opinion(VIEW_CONSERVATIVECRIMESQUAD, 50);
	return ns;
}

void advance_ccs_defeat_storyline()
{
	switch (ccsexposure)
	{
	default:
	case CCSEXPOSURE_NONE:
	case CCSEXPOSURE_LCSGOTDATA:
		break;
	case CCSEXPOSURE_EXPOSED:
		newsstory.push_back(ccs_exposure_story());
		break;
	case CCSEXPOSURE_NOBACKERS:
		newsstory.push_back(ccs_fbi_raid_story());
		break;
	}
}
newsstoryst* new_major_event()
{
	newsstoryst *ns = new newsstoryst;
	ns->type = NEWSSTORY_MAJOREVENT;
	while (true)
	{
		ns->view = LCSrandom(VIEWNUM - 3);
		ns->positive = LCSrandom(2);
		// Skip issues that we have no news stories for
		if (ns->view == VIEW_IMMIGRATION)continue;
		if (ns->view == VIEW_DRUGS)continue;
		if (ns->view == VIEW_MILITARY)continue;
		if (ns->view == VIEW_CIVILRIGHTS)continue;
		if (ns->view == VIEW_TORTURE)continue;
		//if(ns->view==VIEW_POLITICALVIOLENCE)continue;
		// News stories that don't apply when the law is extreme -- covering
		// nuclear power when it's banned, police corruption when it doesn't
		// exist, out of control pollution when it's under control, etc.
		if (ns->positive) {
			if (ns->view == VIEW_WOMEN&&lawList[LAW_ABORTION] == -2)continue; // Abortion banned
			if (ns->view == VIEW_DEATHPENALTY&&lawList[LAW_DEATHPENALTY] == 2)continue; // Death penalty banned
			if (ns->view == VIEW_NUCLEARPOWER&&lawList[LAW_NUCLEARPOWER] == 2)continue; // Nuclear power banned
			if (ns->view == VIEW_ANIMALRESEARCH&&lawList[LAW_ANIMALRESEARCH] == 2)continue; // Animal research banned
			if (ns->view == VIEW_POLICEBEHAVIOR&&lawList[LAW_POLICEBEHAVIOR] == 2)continue; // Police corruption eliminated
			if (ns->view == VIEW_INTELLIGENCE&&lawList[LAW_PRIVACY] == 2)continue; // Privacy rights respected
			if (ns->view == VIEW_SWEATSHOPS&&lawList[LAW_LABOR] == 2)continue; // Sweatshops nonexistant
			if (ns->view == VIEW_POLLUTION&&lawList[LAW_POLLUTION] >= 1)continue; // Pollution under control
			if (ns->view == VIEW_CORPORATECULTURE&&lawList[LAW_CORPORATE] == 2)continue; // Regulation controls corporate corruption
			if (ns->view == VIEW_CEOSALARY&&lawList[LAW_CORPORATE] == 2)continue; // CEOs aren't rich
		}
		else {
			if (ns->view == VIEW_WOMEN&&lawList[LAW_ABORTION] < 2)continue; // Partial birth abortion banned
			if (ns->view == VIEW_AMRADIO&&lawList[LAW_FREESPEECH] == -2)continue; // AM Radio is censored to oblivion
			if (ns->view == VIEW_ANIMALRESEARCH&&lawList[LAW_ANIMALRESEARCH] == 2)continue; // Animal research banned
		}
		break;
	}
	if (ns->positive) change_public_opinion(ns->view, 20, 0);
	else change_public_opinion(ns->view, -20, 0);
	public_interest[ns->view] += 50;
	return ns;
}

void generate_random_event_news_stories()
{
	//Conservative Crime Squad Strikes!
	if (endgamestate < ENDGAME_CCS_DEFEATED &&
		LCSrandom(30) < endgamestate)
	{
		newsstory.push_back(ccs_strikes_story());
	}
	// The slow defeat of the conservative crime squad...
	if (endgamestate < ENDGAME_CCS_DEFEATED &&
		ccsexposure >= CCSEXPOSURE_EXPOSED &&
		!LCSrandom(60))
	{
		advance_ccs_defeat_storyline();
	}
	// Random major event news stories
	if (!LCSrandom(60)) {
		newsstory.push_back(new_major_event());
	}
}

void clean_up_empty_news_stories()
{
	// Delete stories that have no content or shouldn't be reported on
	for (int n = len(newsstory) - 1; n >= 0; n--)
	{
		// Squad site action stories without crimes
		if (newsstory[n]->type == NEWSSTORY_SQUAD_SITE&&
			!len(newsstory[n]->crime))
		{
			delete_and_remove(newsstory, n);
			continue;
		}
		// Police killed stories without police being killed
		if (newsstory[n]->type == NEWSSTORY_CARTHEFT ||
			newsstory[n]->type == NEWSSTORY_NUDITYARREST ||
			newsstory[n]->type == NEWSSTORY_WANTEDARREST ||
			newsstory[n]->type == NEWSSTORY_DRUGARREST ||
			newsstory[n]->type == NEWSSTORY_GRAFFITIARREST ||
			newsstory[n]->type == NEWSSTORY_BURIALARREST)
		{
			char conf = 0;
			for (int c = 0; c < len(newsstory[n]->crime); c++)
			{
				if (newsstory[n]->crime[c] == CRIME_KILLEDSOMEBODY)
				{
					conf = 1;
					break;
				}
			}
			if (!conf)
			{
				delete_and_remove(newsstory, n);
				continue;
			}
		}
		// Sieges that aren't police actions
		if ((newsstory[n]->type == NEWSSTORY_SQUAD_ESCAPED ||
			newsstory[n]->type == NEWSSTORY_SQUAD_FLEDATTACK ||
			newsstory[n]->type == NEWSSTORY_SQUAD_DEFENDED ||
			newsstory[n]->type == NEWSSTORY_SQUAD_BROKESIEGE ||
			newsstory[n]->type == NEWSSTORY_SQUAD_KILLED_SIEGEATTACK ||
			newsstory[n]->type == NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE) &&
			newsstory[n]->siegetype != SIEGE_POLICE)
		{
			delete_and_remove(newsstory, n);
			continue;
		}
	}
}
/* news - determines the priority of a news story */
void setpriority(newsstoryst &ns)
{
	// Priority is set differently based on the type of the news story
	switch (ns.type)
	{
		// Major events always muscle to the front page by having a very high priority
	case NEWSSTORY_MAJOREVENT:
		ns.priority = 30000;
		break;
		// LCS-related news stories are more important if they involve lots of headline-grabbing
		// crimes
	case NEWSSTORY_SQUAD_SITE:
	case NEWSSTORY_SQUAD_ESCAPED:
	case NEWSSTORY_SQUAD_FLEDATTACK:
	case NEWSSTORY_SQUAD_DEFENDED:
	case NEWSSTORY_SQUAD_BROKESIEGE:
	case NEWSSTORY_SQUAD_KILLED_SIEGEATTACK:
	case NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE:
	case NEWSSTORY_SQUAD_KILLED_SITE:
	case NEWSSTORY_CARTHEFT:
	case NEWSSTORY_NUDITYARREST:
	case NEWSSTORY_WANTEDARREST:
	case NEWSSTORY_DRUGARREST:
	case NEWSSTORY_GRAFFITIARREST:
	case NEWSSTORY_BURIALARREST:
	{
		ns.priority = 0;
		int crime[CRIMENUM];
		memset(crime, 0, CRIMENUM*sizeof(int));
		// Record all the crimes in this story
		for (int c = 0; c < len(ns.crime); c++)
			crime[ns.crime[c]]++;
		// Cap publicity for more than ten repeats of an action of some type
		if (crime[CRIME_STOLEGROUND] > 10) crime[CRIME_STOLEGROUND] = 10;
		if (crime[CRIME_BROKEDOWNDOOR] > 10) crime[CRIME_BROKEDOWNDOOR] = 10;
		if (crime[CRIME_ATTACKED_MISTAKE] > 10) crime[CRIME_ATTACKED_MISTAKE] = 10;
		if (crime[CRIME_ATTACKED] > 10) crime[CRIME_ATTACKED] = 10;
		if (crime[CRIME_BREAK_SWEATSHOP] > 10) crime[CRIME_BREAK_SWEATSHOP] = 10;
		if (crime[CRIME_BREAK_FACTORY] > 10) crime[CRIME_BREAK_FACTORY] = 10;
		if (crime[CRIME_FREE_RABBITS] > 10) crime[CRIME_FREE_RABBITS] = 10;
		if (crime[CRIME_FREE_BEASTS] > 10) crime[CRIME_FREE_BEASTS] = 10;
		if (crime[CRIME_TAGGING] > 10) crime[CRIME_TAGGING] = 10;
		// Increase news story priority based on the number of instances of
		// various crimes, scaled by a factor dependant on the crime
		// Unique site crimes
		ns.priority += crime[CRIME_BANKVAULTROBBERY] * 100;
		ns.priority += crime[CRIME_BANKSTICKUP] * 100;
		ns.priority += crime[CRIME_SHUTDOWNREACTOR] * 100;
		ns.priority += crime[CRIME_HACK_INTEL] * 100;
		ns.priority += crime[CRIME_ARMORY] * 100;
		ns.priority += crime[CRIME_HOUSE_PHOTOS] * 100;
		ns.priority += crime[CRIME_CORP_FILES] * 100;
		ns.priority += crime[CRIME_PRISON_RELEASE] * 50;
		ns.priority += crime[CRIME_JURYTAMPERING] * 30;
		ns.priority += crime[CRIME_POLICE_LOCKUP] * 30;
		ns.priority += crime[CRIME_COURTHOUSE_LOCKUP] * 30;
		ns.priority += crime[CRIME_BANKTELLERROBBERY] * 30;
		// Common site crimes
		ns.priority += crime[CRIME_KILLEDSOMEBODY] * 30;
		ns.priority += crime[CRIME_FREE_BEASTS] * 12;
		ns.priority += crime[CRIME_BREAK_SWEATSHOP] * 8;
		ns.priority += crime[CRIME_BREAK_FACTORY] * 8;
		ns.priority += crime[CRIME_FREE_RABBITS] * 8;
		ns.priority += crime[CRIME_ATTACKED_MISTAKE] * 7;
		ns.priority += crime[CRIME_ATTACKED] * 4;
		ns.priority += crime[CRIME_TAGGING] * 2;
		ns.priority += crime[CRIME_VANDALISM] * 2;
		//ns.priority+=crime[CRIME_STOLEGROUND      ];
		//ns.priority+=crime[CRIME_BROKEDOWNDOOR    ];
		// Set story's political and violence levels for determining whether
		// a story becomes positive or negative
		if (ns.claimed) ns.politics_level = 5;
		else ns.politics_level = 0;
		ns.politics_level += crime[CRIME_SHUTDOWNREACTOR] * 100;
		ns.politics_level += crime[CRIME_HACK_INTEL] * 100;
		ns.politics_level += crime[CRIME_HOUSE_PHOTOS] * 100;
		ns.politics_level += crime[CRIME_CORP_FILES] * 100;
		ns.politics_level += crime[CRIME_PRISON_RELEASE] * 50;
		ns.politics_level += crime[CRIME_POLICE_LOCKUP] * 30;
		ns.politics_level += crime[CRIME_COURTHOUSE_LOCKUP] * 30;
		ns.politics_level += crime[CRIME_FREE_BEASTS] * 10;
		ns.politics_level += crime[CRIME_BREAK_SWEATSHOP] * 10;
		ns.politics_level += crime[CRIME_BREAK_FACTORY] * 10;
		ns.politics_level += crime[CRIME_FREE_RABBITS] * 10;
		ns.politics_level += crime[CRIME_VANDALISM] * 5;
		ns.politics_level += crime[CRIME_TAGGING] * 3;
		ns.violence_level = 0;
		ns.violence_level += crime[CRIME_ARMORY] * 100;
		ns.violence_level += crime[CRIME_KILLEDSOMEBODY] * 20;
		ns.violence_level += crime[CRIME_ATTACKED_MISTAKE] * 12;
		ns.violence_level += crime[CRIME_ATTACKED] * 4;
		// Add additional priority based on the type of news story
		// and how high profile the LCS is
		switch (ns.type)
		{
		case NEWSSTORY_SQUAD_ESCAPED:
			ns.priority += 10 + attitude[VIEW_LIBERALCRIMESQUAD] / 3;
			break;
		case NEWSSTORY_SQUAD_FLEDATTACK:
			ns.priority += 15 + attitude[VIEW_LIBERALCRIMESQUAD] / 3;
			break;
		case NEWSSTORY_SQUAD_DEFENDED:
			ns.priority += 30 + attitude[VIEW_LIBERALCRIMESQUAD] / 3;
			break;
		case NEWSSTORY_SQUAD_BROKESIEGE:
			ns.priority += 45 + attitude[VIEW_LIBERALCRIMESQUAD] / 3;
			break;
		case NEWSSTORY_SQUAD_KILLED_SIEGEATTACK:
			ns.priority += 10 + attitude[VIEW_LIBERALCRIMESQUAD] / 3;
			break;
		case NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE:
			ns.priority += 15 + attitude[VIEW_LIBERALCRIMESQUAD] / 3;
			break;
		case NEWSSTORY_SQUAD_KILLED_SITE:
			ns.priority += 10 + attitude[VIEW_LIBERALCRIMESQUAD] / 3;
			break;
		default:
			// Suppress actions at CCS safehouses
			if (ns.loc != -1 &&
				LocationsPool::getInstance().getRentingType(ns.loc) == RENTING_CCS)
			{
				ns.priority = 0;
			}
			break;
		}
		// Double profile if the squad moved out in full battle colors
		if (ns.claimed == 2) ns.priority *= 2;
		// Modify notability by location
		if (ns.loc != -1)
		{
			switch (LocationsPool::getInstance().getLocationType(ns.loc))
			{
				// Not even reported
			case SITE_BUSINESS_CRACKHOUSE:
				if (ns.type == NEWSSTORY_SQUAD_KILLED_SITE ||
					ns.type == NEWSSTORY_SQUAD_SITE)
				{
					ns.priority = 0;
					break;
				}
				// Nobody cares
			case SITE_RESIDENTIAL_TENEMENT:
				ns.priority /= 8;
				break;
				// Normal priority
			case SITE_RESIDENTIAL_SHELTER:
			case SITE_INDUSTRY_WAREHOUSE:
			case SITE_RESIDENTIAL_BOMBSHELTER:
			case SITE_DOWNTOWN:
			case SITE_COMMERCIAL:
			case SITE_UDISTRICT:
			case SITE_OUTOFTOWN:
			case SITE_INDUSTRIAL:
			case SITE_RESIDENTIAL_APARTMENT:
			case SITE_RESIDENTIAL_APARTMENT_UPSCALE:
			case SITE_LABORATORY_COSMETICS:
			case SITE_LABORATORY_GENETIC:
			case SITE_HOSPITAL_CLINIC:
			case SITE_HOSPITAL_UNIVERSITY:
			case SITE_INDUSTRY_SWEATSHOP:
			case SITE_INDUSTRY_POLLUTER:
			case SITE_BUSINESS_PAWNSHOP:
			case SITE_BUSINESS_JUICEBAR:
			case SITE_BUSINESS_CIGARBAR:
			case SITE_BUSINESS_LATTESTAND:
			case SITE_BUSINESS_VEGANCOOP:
			case SITE_BUSINESS_INTERNETCAFE:
			case SITE_BUSINESS_DEPTSTORE:
			case SITE_BUSINESS_HALLOWEEN:
			case SITE_BUSINESS_BARANDGRILL:
			case SITE_BUSINESS_ARMSDEALER:
			case SITE_BUSINESS_CARDEALERSHIP:
			case SITE_OUTDOOR_PUBLICPARK:
			case SITE_OUTDOOR_BUNKER:
			default:
				break;
				// WOAH OMG
			case SITE_INDUSTRY_NUCLEAR:
			case SITE_GOVERNMENT_POLICESTATION:
			case SITE_GOVERNMENT_COURTHOUSE:
			case SITE_GOVERNMENT_PRISON:
			case SITE_GOVERNMENT_INTELLIGENCEHQ:
			case SITE_GOVERNMENT_ARMYBASE:
			case SITE_GOVERNMENT_FIRESTATION:
			case SITE_CORPORATE_HEADQUARTERS:
			case SITE_CORPORATE_HOUSE:
			case SITE_MEDIA_AMRADIO:
			case SITE_MEDIA_CABLENEWS:
			case SITE_BUSINESS_BANK:
			case SITE_GOVERNMENT_WHITE_HOUSE:
				ns.priority *= 2;
				break;
			}
		}
		// Cap news priority, in part so it can't displace major news stories
		if (ns.priority > 20000) ns.priority = 20000;
		break;
	}
	case NEWSSTORY_KIDNAPREPORT:
		// Kidnappings are higher priority if they're an archconservative
		ns.priority = 20;
		if (ns.cr->type == CREATURE_CORPORATE_CEO ||
			ns.cr->type == CREATURE_RADIOPERSONALITY ||
			ns.cr->type == CREATURE_NEWSANCHOR ||
			ns.cr->type == CREATURE_SCIENTIST_EMINENT ||
			ns.cr->type == CREATURE_JUDGE_CONSERVATIVE) ns.priority = 40;
		break;
	case NEWSSTORY_MASSACRE:
		// More people massacred, higher priority (I think; not verified ns.crime[1] is people present)
		ns.priority = 10 + ns.crime[1] * 5;
		break;
	case NEWSSTORY_CCS_SITE:
	case NEWSSTORY_CCS_KILLED_SITE:
		// CCS actions loosely simulate LCS actions; here it adds some
		// random site crimes to the story and increases the
		// priority accordingly
		ns.crime.push_back(CRIME_BROKEDOWNDOOR);
		ns.priority = 1;
		ns.politics_level += 20;
		if (ns.positive == 0)
		{
			ns.crime.push_back(CRIME_ATTACKED_MISTAKE);
			ns.priority += 7;
			ns.violence_level += 12;
		}
		ns.crime.push_back(CRIME_ATTACKED);
		ns.priority += 4 * (LCSrandom(10) + 1);
		ns.violence_level += LCSrandom(10) * 4;
		if (LCSrandom(endgamestate + 1))
		{
			ns.crime.push_back(CRIME_KILLEDSOMEBODY);
			ns.priority += LCSrandom(10) * 30;
			ns.violence_level += LCSrandom(10) * 20;
		}
		if (LCSrandom(endgamestate + 1))
		{
			ns.crime.push_back(CRIME_STOLEGROUND);
			ns.priority += LCSrandom(10);
		}
		if (!LCSrandom(endgamestate + 4))
		{
			ns.crime.push_back(CRIME_BREAK_FACTORY);
			ns.priority += LCSrandom(10) * 2;
			ns.politics_level += LCSrandom(10) * 10;
		}
		if (LCSrandom(2))
		{
			ns.crime.push_back(CRIME_CARCHASE);
		}
		break;
	case NEWSSTORY_CCS_DEFENDED:
	case NEWSSTORY_CCS_KILLED_SIEGEATTACK:
		ns.priority = 40 + attitude[VIEW_LIBERALCRIMESQUAD] / 3;
		break;
	}
}
void assign_page_numbers_to_newspaper_stories()
{
	for (int n = len(newsstory) - 1; n >= 0; n--)
	{
		setpriority(*newsstory[n]);
		// Suppress squad actions that aren't worth a story
		if (newsstory[n]->type == NEWSSTORY_SQUAD_SITE &&
			((newsstory[n]->priority < 50 &&
				newsstory[n]->claimed == 0) ||
				newsstory[n]->priority < 4))
		{
			delete_and_remove(newsstory, n);
			continue;
		}
		newsstory[n]->page = -1;
	}
	char acted;
	int curpage = 1, curguardianpage = 1;
	do
	{
		acted = 0;
		// Sort the major newspapers
		int maxn = -1, maxp = -1;
		for (int n = 0; n < len(newsstory); n++)
		{
			if (newsstory[n]->priority > maxp&&
				newsstory[n]->page == -1)
			{
				maxn = n;
				maxp = newsstory[n]->priority;
			}
		}
		if (maxn != -1)
		{
			if (newsstory[maxn]->priority < 30 && curpage == 1) curpage = 2;
			if (newsstory[maxn]->priority < 25 && curpage < 3) curpage = 3 + LCSrandom(2);
			if (newsstory[maxn]->priority < 20 && curpage < 5) curpage = 5 + LCSrandom(5);
			if (newsstory[maxn]->priority < 15 && curpage < 10) curpage = 10 + LCSrandom(10);
			if (newsstory[maxn]->priority < 10 && curpage < 20) curpage = 20 + LCSrandom(10);
			if (newsstory[maxn]->priority < 5 && curpage < 30) curpage = 30 + LCSrandom(20);
			newsstory[maxn]->page = curpage;
			newsstory[maxn]->guardianpage = curguardianpage;
			curpage++;
			curguardianpage++;
			acted = 1;
		}
	} while (acted);
}
/* news - show major news story */
void preparepage(newsstoryst& ns, bool liberalguardian)
{
	set_color_easy(WHITE_ON_WHITE);
	for (int x = 0; x<80; x++)
		for (int y = 0; y<25; y++)
			mvaddcharAlt(y, x, ' ');
	set_color_easy(WHITE_ON_BLACK);
	if (ns.page == 1 || (liberalguardian&&ns.guardianpage == 1))
	{
		//TOP
		int pap = LCSrandom(5);
		for (int x = 0; x<80; x++)
		{
			for (int y = 0; y<5; y++)
			{
				if (liberalguardian)
				{
					set_color((newstops[5][x][y][1]),
						(newstops[5][x][y][2]),
						newstops[5][x][y][3]);
					mvaddcharAlt(y, x, newstops[5][x][y][0]);
				}
				else
				{
					set_color((newstops[pap][x][y][1]),
						(newstops[pap][x][y][2]),
						newstops[pap][x][y][3]);
					mvaddcharAlt(y, x, newstops[pap][x][y][0]);
				}
			}
		}
		if (!liberalguardian) // Liberal Guardian graphics don't support adding a date
		{
			//DATE
			set_color_easy(BLACK_ON_WHITE);
			int pday = day, pmonth = month, pyear = year;
			if (pday>monthday()) // Day counter has increased but end-of-month has not yet
			{                   // been checked so it has to be accounted for here.
				pday = 1, pmonth++;
				if (pmonth>12) pmonth = 1, pyear++;
			}
			mvaddstrAlt(3, 66 + (pday<10), getmonth(pmonth, true));
			addstrAlt(singleSpace);
			addstrAlt(pday);
			addstrAlt(commaSpace);
			addstrAlt(pyear);
		}
	}
	else
	{
		//PAGE
		set_color_easy(BLACK_ON_WHITE);
		mvaddstrAlt(0, 76, liberalguardian ? ns.guardianpage : ns.page);
	}
}
/* news - draws the specified block of text to the screen */
void displaynewsstory(char *story, const short *storyx_s, const short *storyx_e, int y)
{
	vector<char *> text;
	vector<char> centered;
	int totalwidth;
	int curpos = 0;
	int addstrcur;
	char addstring[500];
	char content;
	int cury = y;
	int length;
	char endparagraph = 0;
	char iscentered = 0;
	int i = 0;
	while (curpos < len(story) && cury < 25)
	{
		content = 0;
		totalwidth = 0;
		addstrcur = 0;
		length = storyx_e[cury] - storyx_s[cury] + 1;
		if (length == 0) { cury++; if (endparagraph>0)endparagraph--; continue; }
		for (i = curpos; i < len(story); i++)
		{
			if (story[i] == '&'&&story[i + 1] != '&')
			{
				i++;
				if (story[i] == 'c')iscentered = 1;
				if (story[i] == 'r')
				{
					content = 1;
					i++;
					addstrcur += 1;
					addstring[addstrcur - 1] = ' ';
					addstring[addstrcur] = '\x0';
					endparagraph = 1;
					break;
				}
			}
			else
			{
				content = 1;
				if (story[i] == '&')i++;
				addstring[addstrcur] = story[i];
				addstring[addstrcur + 1] = '\x0';
				totalwidth++;
				if (totalwidth > length)
				{
					while (story[i] != ' ') i--, addstrcur--;
					while (story[i] == ' ') i++;
					addstring[addstrcur] = '\x0';
					break;
				}
				addstrcur++;
			}
		}
		if (i == len(story)) addstring[addstrcur] = '\x0';
		if (len(addstring) && content)
		{
			int words = 0;
			char silent = 1;
			vector<int> spacex;
			for (int s2 = 0; s2 < len(addstring); s2++)
			{
				if (addstring[s2] == ' ')
				{
					if (!silent)
					{
						silent = 1;
						words++;
						spacex.push_back(s2);
					}
				}
				else
				{
					if (silent)
					{
						words++;
						silent = 0;
					}
				}
			}
			while (!endparagraph&&words > 1 && len(addstring) < length&&!iscentered)
			{
				int csp = pickrandom(spacex);
				for (int x = 0; x<len(spacex); x++)
					if (spacex[x]>csp) spacex[x]++;
				int l = len(addstring);
				for (int s = l + 1; s > csp; s--)
					addstring[s] = addstring[s - 1];
			}
			char *news = new char[len(addstring) + 1];
			strcpy(news, addstring);
			text.push_back(news);
			centered.push_back(iscentered);
			cury++;
			if (endparagraph > 0)
				endparagraph--, iscentered = 0;
		}
		curpos = i;
	}
	set_color_easy(BLACK_ON_WHITE);
	for (int t = 0; t < len(text); t++)
	{
		if (y + t >= 25) break;
		if (text[t][len(text[t]) - 1] == ' ') // remove trailing space
			text[t][len(text[t]) - 1] = '\x0'; // (necessary for proper centering and to not overwrite borders around an ad)
		if (centered[t])
			moveAlt(y + t, ((storyx_s[y + t] + storyx_e[y + t] - len(text[t]) + 1) >> 1));
		else moveAlt(y + t, storyx_s[y + t]);
		addstrAlt(text[t]);
		delete[] text[t];
	}
	text.clear();
}

void displaysinglead(bool liberalguardian, char addplace[2][3], short* storyx_s, short* storyx_e, int& it2)
{
	int x, y;
	do x = LCSrandom(2), y = LCSrandom(3); while (addplace[x][y]);
	char choice = LCSrandom(6) + 1; // choose an ad from 1 to 6 that isn't already taken
	for (int x2 = 0; x2 < 2; x2++) for (int y2 = 0; y2 < 3; y2++) // loop thru ad places to see ads already up
		if (addplace[x2][y2] == choice) choice = LCSrandom(6) + 1, x2 = 0, y2 = -1; // choose again and restart loop if already taken
	addplace[x][y] = choice; // we got an ad chosen that isn't a duplicate
	int sx = 0, ex = 0, sy = 0, ey = 0;
	if (x == 0) sx = 0, ex = 23 + LCSrandom(4);
	if (x == 1) sx = 57 - LCSrandom(4), ex = 79;
	if (y == 0) sy = 2, ey = 9;
	if (y == 1) sy = 10, ey = 17;
	if (y == 2) sy = 18, ey = 24;
	int ch = '?';
	switch (LCSrandom(6))
	{
	case 0: ch = CH_LIGHT_SHADE; break;
	case 1: ch = CH_MEDIUM_SHADE; break;
	case 2: ch = CH_DARK_SHADE; break;
	case 3: ch = CH_FULL_BLOCK; break;
	case 4: ch = CH_BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL; break;
	case 5: ch = '*'; break;
	}
	for (y = sy; y <= ey; y++)
	{
		if (storyx_s[y] < ex&&ex < 43) storyx_s[y] = ex + 2;
		if (storyx_e[y] > sx&&sx>43) storyx_e[y] = sx - 2;
		if (ey == 9 && y == 9) continue;
		if (ey == 17 && y == 17) continue;
		for (x = sx; x <= ex; x++)
			if (y == sy || y == 8 || y == 16 || y == 24 || x == sx || x == ex)
				mvaddchAlt(y, x, ch);
	}
	//AD CONTENT
	{
		short storyx_s[25], storyx_e[25];
		for (it2 = 0; it2 < 25; it2++) storyx_s[it2] = 40, storyx_e[it2] = 40;
		for (it2 = sy + 1; it2 <= ey - 1; it2++) storyx_s[it2] = sx + 1, storyx_e[it2] = ex - 1;
		char ad[500];
		if (!liberalguardian)
		{ // regular newspaper (not Liberal Guardian)
			switch (choice) // should be 6 choices from 1 to 6
			{ // location[]->name?
			case 1:
			case 3:
			case 5:
			default:
				strcpy(ad, "");
				for (string str : pickrandom(adList)) {
					strcat(ad, str);
				}
				break;
			case 2:
				strcpy(ad, ampersandC + "Fine Leather Chairs" + ampersandR + ampersandR);
				strcat(ad, ampersandC + "Special Purchase" + ampersandR);
				strcat(ad, ampersandC + "Now $");
				strcat(ad, LCSrandom(201) + 400);
				strcat(ad, ampersandR);
				break;
			case 4:
				strcpy(ad, ampersandC + "Quality Pre-Owned" + ampersandR);
				strcat(ad, ampersandC + "Vehicles&r");
				strcat(ad, ampersandC);
				strcat(ad, year - LCSrandom(15));
				strcat(ad, singleSpace);
				//          strcat(ad,cartype);
				//TODO: leading zeros, etc.
				strcat(ad, "Lexus GS 300" + ampersandR);
				strcat(ad, ampersandC + "Sedan 4D" + ampersandR);
				strcat(ad, ampersandC + "Only $");
				strcat(ad, LCSrandom(16) + 15);
				strcat(ad, ampersandR);
				break;
			case 6:
			{
				strcpy(ad, ampersandC);
				strcat(ad, pickrandom(personalAds));
				char str[10];
				strcat(ad, ampersandR + ampersandR);
				strcat(ad, ampersandC);
				sexdesc(str);
				strcat(ad, str);
				strcat(ad, singleSpace);
				sexwho(str);
				strcat(ad, str);
				strcat(ad, singleSpace);
				sexseek(str);
				strcat(ad, str);
				strcat(ad, ampersandR);
				strcat(ad, ampersandC);
				sextype(str);
				strcat(ad, str);
				strcat(ad, " w/ ");
				sexwho(str);
				strcat(ad, str);
				strcat(ad, ampersandR);
				break;
			}
			}
		}
		else
		{ // Liberal Guardian Ads
			switch (choice)  // should be 6 choices from 1 to 6
			{
			case 1:
			case 3:
			case 4:
			case 5:
			default:
				strcpy(ad, "");
				for (string str : pickrandom(adListB)) {
					strcat(ad, str);
				}
				break;
			case 2:
				strcpy(ad, ampersandC + "Liberal Defense Lawyer" + ampersandR);
				strcat(ad, ampersandC);
				strcat(ad, LCSrandom(11) + 20);
				strcat(ad, " Years Experience" + ampersandR + ampersandR);
				strcat(ad, ampersandC + "Call Today" + ampersandR);
				break;
			case 6:
			{
				strcpy(ad, ampersandC);
				strcat(ad, pickrandom(personalAdsLG));
				char str[10];
				strcat(ad, ampersandR + ampersandR);
				strcat(ad, ampersandC);
				sexdesc(str);
				strcat(ad, str);
				strcat(ad, singleSpace);
				sexwho(str);
				strcat(ad, str);
				strcat(ad, singleSpace);
				sexseek(str);
				strcat(ad, str);
				strcat(ad, ampersandR);
				strcat(ad, ampersandC);
				sextype(str);
				strcat(ad, str);
				strcat(ad, " w/ ");
				sexwho(str);
				strcat(ad, str);
				strcat(ad, ampersandR);
				break;
			}
			}
		}
		displaynewsstory(ad, storyx_s, storyx_e, sy + 1);
	}
}

void displayads(newsstoryst& ns, bool liberalguardian, short* storyx_s, short* storyx_e, int& it2)
{
	int adnumber = 0;
	if (!liberalguardian)
	{
		if (ns.page >= 10)adnumber++;
		if (ns.page >= 20)adnumber += LCSrandom(2) + 1;
		if (ns.page >= 30)adnumber += LCSrandom(2) + 1;
		if (ns.page >= 40)adnumber += LCSrandom(2) + 1;
		if (ns.page >= 50)adnumber += LCSrandom(2) + 1;
	}
	else
	{
		if (ns.guardianpage >= 2)adnumber++;
		if (ns.guardianpage >= 3)adnumber += LCSrandom(2) + 1;
		if (ns.guardianpage >= 4)adnumber += LCSrandom(2) + 1;
		if (ns.guardianpage >= 5)adnumber += LCSrandom(2) + 1;
		if (ns.guardianpage >= 6)adnumber += LCSrandom(2) + 1;
	}
	char addplace[2][3] = { { 0,0,0 },{ 0,0,0 } };
	for (adnumber = (adnumber > 6 ? 6 : adnumber); adnumber > 0; adnumber--)
		displaysinglead(liberalguardian, addplace, storyx_s, storyx_e, it2);
}

void squadstory_text_location(newsstoryst& ns, bool liberalguardian, bool ccs, char* story)
{
	strcat(story, "  The events took place ");
	string placename = LocationsPool::getInstance().getLocationName(ns.loc);
	if (placename.substr(0, 4) == "The ")
		placename = placename.substr(4);
	int posand = placename.find('&');
	if (posand != (int)string::npos)
		placename = placename.substr(0, posand) + "and" + placename.substr(posand + 1);
	switch (LocationsPool::getInstance().getLocationType(ns.loc))
	{
	case SITE_CITY_SEATTLE:
	case SITE_CITY_LOS_ANGELES:
	case SITE_CITY_NEW_YORK:
	case SITE_CITY_CHICAGO:
	case SITE_CITY_DETROIT:
	case SITE_CITY_ATLANTA:
	case SITE_CITY_MIAMI:
	case SITE_CITY_WASHINGTON_DC:
		strcat(story, "in ");
		break;
	case SITE_DOWNTOWN:
	case SITE_COMMERCIAL:
	case SITE_UDISTRICT:
	case SITE_OUTOFTOWN:
	case SITE_INDUSTRIAL:
	case SITE_TRAVEL:
		if (placename == "Shopping")
		{
			placename = "Shopping Mall";
			strcat(story, "at the ");
		}
		else if (placename == "Travel")
		{
			placename = "Travel Agency";
			strcat(story, "at the ");
		}
		else if (placename == "Outskirts and Orange County")
		{
			placename = "Orange County";
			strcat(story, "in ");
		}
		else if (placename == "Brooklyn and Queens")
		{
			placename = "Long Island";
			strcat(story, "on ");
		}
		else if (placename == "Greater Hollywood")
		{
			placename = "Hollywood";
			strcat(story, "in ");
		}
		else if (placename == "Manhattan Island")
		{
			placename = "Manhattan";
			strcat(story, "in ");
		}
		else if (placename == "Arlington")
			strcat(story, "in ");
		else if (placename == "National Mall")
			strcat(story, "on the ");
		else if (placename != "Downtown")
			strcat(story, "in the ");
		break;
	case SITE_BUSINESS_PAWNSHOP:
		if (placename.find("'s") != string::npos)
		{
			strcat(story, "at ");
			if (liberalguardian&&!ccs)strcat(story, "the notorious ");
		}
		else
		{
			strcat(story, "at the ");
			if (liberalguardian&&!ccs)strcat(story, "notorious ");
		}
		break;
	case SITE_RESIDENTIAL_APARTMENT:
	case SITE_BUSINESS_CARDEALERSHIP:
	case SITE_BUSINESS_DEPTSTORE:
	case SITE_OUTDOOR_PUBLICPARK:
		strcat(story, "at ");
		if (liberalguardian&&!ccs)strcat(story, "the notorious ");
		break;
	default:
		strcat(story, "at the ");
		if (liberalguardian&&!ccs)strcat(story, "notorious ");
		break;
	}
	if (ccs)
	{
		switch (LocationsPool::getInstance().getLocationType(ns.loc))
		{
		case SITE_RESIDENTIAL_APARTMENT_UPSCALE:
			strcat(story, "University Dormitory.  "); break;
		case SITE_BUSINESS_CIGARBAR:
			strcat(story, "Lady Luck Strip Club.  "); break;
		case SITE_LABORATORY_COSMETICS:
			strcat(story, "Animal Shelter.  "); break;
		case SITE_LABORATORY_GENETIC:
			strcat(story, "Research Ethics Commission HQ.  "); break;
		case SITE_GOVERNMENT_POLICESTATION:
			strcat(story, "Seedy Back Alley(tm).  "); break;
		case SITE_GOVERNMENT_COURTHOUSE:
			strcat(story, "Abortion Clinic.  "); break;
		case SITE_GOVERNMENT_PRISON:
			strcat(story, "Rehabilitation Center.  "); break;
		case SITE_GOVERNMENT_INTELLIGENCEHQ:
			strcat(story, "WikiLeaks HQ.  "); break;
		case SITE_INDUSTRY_SWEATSHOP:
			strcat(story, "Labor Union HQ.  "); break;
		case SITE_INDUSTRY_POLLUTER:
			strcat(story, "Greenpeace Offices.  "); break;
		case SITE_INDUSTRY_NUCLEAR:
			strcat(story, "Whirled Peas Museum.  "); break;
		case SITE_CORPORATE_HEADQUARTERS:
			strcat(story, "Welfare Assistance Agency.  "); break;
		case SITE_CORPORATE_HOUSE:
			strcat(story, "Tax Collection Agency.  "); break;
		case SITE_MEDIA_AMRADIO:
			strcat(story, "Public Radio Station.  "); break;
		case SITE_MEDIA_CABLENEWS:
			strcat(story, "Network News Station.  "); break;
		case SITE_GOVERNMENT_ARMYBASE:
			strcat(story, "Greenpeace Offices.  "); break;
		case SITE_GOVERNMENT_FIRESTATION:
			strcat(story, "ACLU Branch Office.  "); break;
		case SITE_BUSINESS_BANK:
			strcat(story, "Richard Dawkins Food Bank.  "); break;
		default:
			strcat(story, placename.c_str());
			strcat(story, ".  "); break;
		}
	}
	else strcat(story, placename.c_str());
	if (liberalguardian&&!ccs)
	{
		switch (LocationsPool::getInstance().getLocationType(ns.loc))
		{
		case SITE_RESIDENTIAL_APARTMENT_UPSCALE:
			strcat(story, ", known for its rich and snooty residents.  "); break;
		case SITE_BUSINESS_CIGARBAR:
			strcat(story, ", a spawning ground of Wrong Conservative Ideas.  "); break;
		case SITE_LABORATORY_COSMETICS:
			strcat(story, ", a Conservative animal rights abuser.  "); break;
		case SITE_LABORATORY_GENETIC:
			strcat(story, ", a dangerous Conservative genetic research lab.  "); break;
		case SITE_GOVERNMENT_POLICESTATION:
			strcat(story, ", headquarters of one of the most oppressive and Conservative police forces in the country.  "); break;
		case SITE_GOVERNMENT_COURTHOUSE:
			strcat(story, ", site of numerous Conservative Injustices.  "); break;
		case SITE_GOVERNMENT_PRISON:
			strcat(story, ", where innocent people are regularly beaten by Conservative guards.  "); break;
		case SITE_GOVERNMENT_INTELLIGENCEHQ:
			strcat(story, ", the Conservative headquarters of one of the biggest privacy violators in the world.  "); break;
		case SITE_GOVERNMENT_ARMYBASE:
			strcat(story, ", pride of Conservative torturers and warmongers everywhere.  "); break;
		case SITE_INDUSTRY_SWEATSHOP:
			strcat(story, ", a Conservative sweatshop and human rights abuser.  "); break;
		case SITE_INDUSTRY_POLLUTER:
			strcat(story, ", a factory whose Conservative smokestacks choke the city with deadly pollutants.  "); break;
		case SITE_INDUSTRY_NUCLEAR:
			strcat(story, ", also known to be a Conservative storage facility for radioactive waste.  "); break;
		case SITE_CORPORATE_HEADQUARTERS:
			strcat(story, ", where evil and Conservatism coagulate in the hallways.  "); break;
		case SITE_CORPORATE_HOUSE:
			strcat(story, ", a building with enough square footage enough to house a hundred people if it weren't in Conservative Hands.  "); break;
		case SITE_MEDIA_AMRADIO:
		case SITE_MEDIA_CABLENEWS:
			strcat(story, ", known for its Extreme Conservative Bias.  "); break;
		case SITE_BUSINESS_BANK:
			strcat(story, ", the very symbol of economic inequality.  "); break;
		default:
			strcat(story, ".  "); break;
		}
	}
	else if (!ccs)
		strcat(story, ".  ");
}

void squadstory_text_opening(newsstoryst& ns, bool liberalguardian, bool ccs, char* story)
{
	if (ns.type == NEWSSTORY_SQUAD_SITE)
	{
		if (!newscherrybusted&&!liberalguardian)
		{
			if (ns.positive)
			{
				strcat(story, "A group calling itself the Liberal Crime Squad ");
				strcat(story, "burst onto the scene of political activism yesterday, according ");
				strcat(story, "to a spokesperson from the police department.");
				strcat(story, "&r");
			}
			else
			{
				strcat(story, "A group of thugs calling itself the Liberal Crime Squad ");
				strcat(story, "went on a rampage yesterday, according ");
				strcat(story, "to a spokesperson from the police department.");
			}
		}
		else
		{
			if (ns.positive)
			{
				strcat(story, "The Liberal Crime Squad has struck again.  ");
				strcat(story, "&r");
			}
			else
			{
				if (!liberalguardian)
					strcat(story, "The Liberal Crime Squad has gone on a rampage.  ");
				else
					strcat(story, "A Liberal Crime Squad operation went horribly wrong.  ");
				strcat(story, "&r");
			}
		}
	}
	else if (ns.type == NEWSSTORY_CCS_SITE)
	{
		if (newscherrybusted<2)
		{
			if (ns.positive&&!liberalguardian)
			{
				strcat(story, "A group of M16-wielding vigilantes calling itself the Conservative Crime Squad ");
				strcat(story, "burst onto the scene of political activism yesterday, according ");
				strcat(story, "to a spokesperson from the police department.");
				strcat(story, "&r");
			}
			else
			{
				strcat(story, "A group of worthless M16-toting hicks calling itself the Conservative Crime Squad ");
				strcat(story, "went on a rampage yesterday, according ");
				strcat(story, "to a spokesperson from the police department.");
			}
		}
		else
		{
			if (ns.positive&&!liberalguardian)
			{
				strcat(story, "The Conservative Crime Squad has struck again.  ");
				strcat(story, "&r");
			}
			else
			{
				strcat(story, "The Conservative Crime Squad has gone on another rampage.  ");
				strcat(story, "&r");
			}
		}
	}
	else if (ns.type == NEWSSTORY_CCS_KILLED_SITE)
	{
		if (newscherrybusted<2)
		{
			if (ns.positive&&!liberalguardian)
			{
				strcat(story, "A group of M16-wielding vigilantes calling themselves the Conservative Crime Squad ");
				strcat(story, "burst briefly onto the scene of political activism yesterday, according ");
				strcat(story, "to a spokesperson from the police department.  ");
				strcat(story, "&r");
			}
			else
			{
				strcat(story, "A group of ");
				strcat(story, pickrandom(ccs_adjective).c_str());
				strcat(story, pickrandom(ccs_adjective_2).c_str());
				strcat(story, "M16-toting ");
				strcat(story, pickrandom(ccs_noun).c_str());
				strcat(story, "calling themselves the Conservative Crime Squad went on a ");
				strcat(story, pickrandom(ccs_adjective_3).c_str());
				strcat(story, "rampage yesterday, according to a spokesperson from the police department.  ");
				strcat(story, "&r");
			}
		}
		else
		{
			if (ns.positive&&!liberalguardian)
			{
				strcat(story, "The Conservative Crime Squad has struck again, albeit with a tragic end.  ");
				strcat(story, "&r");
			}
			else
			{
				strcat(story, "The Conservative Crime Squad has gone on another rampage, and they got what they deserved.  ");
				strcat(story, "&r");
			}
		}
	}
	else
	{
		if (!newscherrybusted&&!liberalguardian)
		{
			if (ns.positive)
			{
				strcat(story, "A group calling itself the Liberal Crime Squad ");
				strcat(story, "burst briefly onto the scene of political activism yesterday, according ");
				strcat(story, "to a spokesperson from the police department.  ");
				strcat(story, "&r");
			}
			else
			{
				strcat(story, "A group of thugs calling itself the Liberal Crime Squad ");
				strcat(story, "went on a suicidal rampage yesterday, according ");
				strcat(story, "to a spokesperson from the police department.  ");
				strcat(story, "&r");
			}
		}
		else
		{
			if (ns.positive)
			{
				strcat(story, "The Liberal Crime Squad has struck again, albeit with a tragic end.  ");
				strcat(story, "&r");
			}
			else
			{
				if (!liberalguardian)
					strcat(story, "The Liberal Crime Squad has gone on a rampage, and they got what they deserved.  ");
				else
					strcat(story, "A Liberal Crime Squad operation went horribly wrong, and came to a tragic end.  ");//XXX: Rewrite me -- LK
				strcat(story, "&r");
			}
		}
	}
	squadstory_text_location(ns, liberalguardian, ccs, story);
	if (ns.type == NEWSSTORY_SQUAD_KILLED_SITE)
	{
		if (liberalguardian)strcat(story, "Unfortunately, the LCS group was defeated by the forces of evil.  ");
		else if (ns.positive)strcat(story, "Everyone in the LCS group was arrested or killed.  ");
		else strcat(story, "Fortunately, the LCS thugs were stopped by brave citizens.  ");
	}
	if (ns.type == NEWSSTORY_CCS_KILLED_SITE)
	{
		if (ns.positive&&!liberalguardian)strcat(story, "Everyone in the CCS group was arrested or killed.  ");
		else strcat(story, "Fortunately, the CCS thugs were stopped by brave citizens.  ");
	}
	strcat(story, "&r");
}

/* news - make some filler junk */
void generatefiller(char *story, int amount)
{  //TODO: Use text from filler.cpp
	strcat(story, ampersandR + cityname() + spaceDashSpace);
	for (int par = 0; amount > 0; amount--)
	{
		par++;
		for (int i = 0; i < LCSrandom(10) + 3; i++)strcat(story, "~");
		if (amount > 1)strcat(story, singleSpace);
		if (par >= 50 && !LCSrandom(5) && amount > 20)
		{
			par = 0;
			strcat(story, ampersandR + "  ");
		}
	}
	strcat(story, ampersandR);
}
void displaycenterednewsfont(const std::string& str, int y)
{
	int width = -1;
	int s;
	for (s = 0; s < len(str); s++)
	{
		if (str[s] >= 'A'&&str[s] <= 'Z')width += 6;
		else if (str[s] == '\'')width += 4;
		else width += 3;
	}
	int x = 39 - width / 2;
	for (s = 0; s < len(str); s++)
	{
		if ((str[s] >= 'A'&&str[s] <= 'Z') || str[s] == '\'')
		{
			int p;
			if (str[s] >= 'A'&&str[s] <= 'Z') p = str[s] - 'A';
			else p = 26;
			int lim = 6;
			if (str[s] == '\'') lim = 4;
			if (s == len(str) - 1) lim--;
			for (int x2 = 0; x2 < lim; x2++) for (int y2 = 0; y2 < 7; y2++)
			{
				moveAlt(y + y2, x + x2);
#ifdef NCURSES
				// Clean the square first.
				set_color(COLOR_BLACK, COLOR_BLACK, 0);
				addcharAlt(' ');
				moveAlt(y + y2, x + x2);
#endif
				if (x2 == 5)
				{
					set_color_easy(WHITE_ON_WHITE);
					addcharAlt(' ');
				}
				else
				{
					set_color((bigletters[p][x2][y2][1]),
						(bigletters[p][x2][y2][2]),
						bigletters[p][x2][y2][3]);
					addcharAlt(bigletters[p][x2][y2][0]);
				}
			}
			x += lim;
		}
		else
		{
			set_color_easy(WHITE_ON_WHITE);
			for (int x2 = 0; x2 < 3; x2++) for (int y2 = 0; y2 < 7; y2++)
			{
				moveAlt(y + y2, x + x2);
				addcharAlt(' ');
			}
			x += 3;
		}
	}
}
/* news - constructs non-LCS related event stories */
void constructeventstory(char *story, const short view, const char positive)
{
	strcpy(story, "");
	if (positive)
	{
		switch (view)
		{
		case VIEW_WOMEN:
		{
			//TODO IsaacG Migrate Strings?
			char str[200], str2[200], gen[50];
			strcpy(story, cityname());
			strcat(story, spaceDashSpace);
			if (lawList[LAW_ABORTION] == -2) strcat(story, "A doctor that routinely performed illegal abortion-murders was ruthlessly ");
			else if (lawList[LAW_ABORTION] == -1) strcat(story, "A doctor that routinely performed illegal abortions was ruthlessly ");
			else if (lawList[LAW_ABORTION] == 0) strcat(story, "A doctor that routinely performed semi-legal abortions was ruthlessly ");
			else strcat(story, "A doctor that routinely performed abortions was ruthlessly ");
			strcat(story, "gunned down outside of the ");
			strcpy(str, lastname(true).data());
			strcat(story, str);
			strcat(story, " Clinic yesterday.  ");
			strcat(story, "Dr. ");
			char dstr[200], dstr2[200];
			const char gn = (LCSrandom(2) ? GENDER_MALE : GENDER_FEMALE);
			generate_name(dstr, dstr2, gn);
			strcat(story, dstr);
			strcat(story, singleSpace);
			strcat(story, dstr2);
			strcpy(gen, (gn == GENDER_FEMALE ? "her" : "his"));
			strcat(story, " was walking to "); strcat(story, gen);//TODO: Add more variety, not just in the parking lot.
			strcat(story, " car when, according to police reports, ");
			strcat(story, "shots were fired from a nearby vehicle.  ");
			strcat(story, dstr2);
			strcat(story, " was hit ");
			strcat(story, LCSrandom(15) + 3);
			strcat(story, " times and died immediately in the parking lot.  ");
			strcat(story, "The suspected shooter, ");
			generate_name(str, str2);
			strcat(story, str);
			strcat(story, singleSpace);
			strcat(story, str2);
			strcat(story, ", is in custody.&r");
			strcat(story, "  Witnesses report that ");
			strcat(story, str2);
			strcat(story, " remained at the scene after the shooting, screaming ");
			strcat(story, "verses of the Bible at the stunned onlookers.  Someone ");
			strcat(story, "called the police on a cellphone and they arrived shortly thereafter.  ");
			strcat(story, str2);
			if (lawList[LAW_WOMEN] == -2)
			{
				strcat(story, " later admitted to being a rogue FBI vigilante, hunting down ");
				strcat(story, " abortion doctors as opposed to arresting them.&r");
			}
			else
			{
				strcat(story, " surrendered without a struggle, reportedly saying that God's work ");
				strcat(story, "had been completed.&r");
			}
			strcat(story, "  ");
			strcat(story, dstr2);
			strcat(story, " is survived by ");
			strcat(story, gen);
			strcat(story, singleSpace);
			char spouse = (LCSrandom(2) ? GENDER_MALE : GENDER_FEMALE);
			if (lawList[LAW_GAY] <= 1)
				spouse = (gn == GENDER_FEMALE ? GENDER_MALE : GENDER_FEMALE);
			strcat(story, (spouse == GENDER_FEMALE ? "wife" : "husband"));
			strcat(story, " and ");
			switch (LCSrandom(4))
			{
			case 0: strcat(story, "two"); break;
			case 1: strcat(story, "three"); break;
			case 2: strcat(story, "four"); break;
			case 3: strcat(story, "five"); break;
			}
			strcat(story, " children.&r");
			break;
		}
		case VIEW_GAY:
		{
			strcpy(story, cityname());
			strcat(story, spaceDashSpace);
			char dstr[200], dstr2[200];
			generate_name(dstr, dstr2);
			strcat(story, dstr);
			strcat(story, singleSpace);
			strcat(story, dstr2);
			strcat(story, commaSpace);
			if (lawList[LAW_GAY] == -2) strcat(story, "a known sexual deviant, was ");
			else if (lawList[LAW_GAY] == -1) strcat(story, "a known homosexual, was ");
			else strcat(story, "a homosexual, was ");
			strcat(story, pickrandom(vigilante_murder));
			strcat(story, " here yesterday.  ");
			strcat(story, "A police spokesperson reported that four suspects ");
			strcat(story, "were apprehended after a high speed chase.  Their names ");
			strcat(story, "have not yet been released.");
			strcat(story, ampersandR);
			strcat(story, "  Witnesses of the freeway chase described the pickup of the alleged ");
			strcat(story, "murderers swerving wildly, ");
			switch (LCSrandom(3))
			{
			case 0:
				if (lawList[LAW_FREESPEECH] == -2) strcat(story, "throwing [juice boxes]");
				else strcat(story, "throwing beer bottles");
				break;
			case 1:
				if (lawList[LAW_FREESPEECH] == -2) strcat(story, "[relieving themselves] out the window");
				else if (lawList[LAW_FREESPEECH] == 2) strcat(story, "pissing out the window");
				else strcat(story, "urinating out the window");
				break;
			case 2: strcat(story, "taking swipes"); break;
			}
			strcat(story, " at the pursuing police cruisers.  ");
			strcat(story, "The chase ended when ");
			strcat(story, pickrandom(why_chase_ended));
			strcat(story, singleSpace);
			strcat(story, "at which point they were taken into custody.  Nobody was seriously injured during the incident.");
			strcat(story, ampersandR);
			strcat(story, "  Authorities have stated that they will vigorously ");
			strcat(story, "prosecute this case as a hate crime, due to the ");
			strcat(story, "aggravated nature of the offense");
			if (lawList[LAW_GAY] == -2 && lawList[LAW_FREESPEECH] != -2)
			{
				strcat(story, ", despite the fact that ");
				strcat(story, dstr);
				strcat(story, singleSpace);
				strcat(story, dstr2);
				strcat(story, " is a known faggot");
			}
			else if (lawList[LAW_GAY] == -2)strcat(story, ", even though being gay is deviant, as we all know.");
			else strcat(story, singleDot);
			strcat(story, ampersandR);
			break;
		}
		case VIEW_DEATHPENALTY:
		{
			strcat(story, statename());
			strcat(story, " - An innocent citizen has been put to death in the electric chair.  ");
			char dstr[200], dstr2[200], dstr3[200];
			generate_long_name(dstr, dstr2, dstr3);
			strcat(story, dstr);
			strcat(story, singleSpace);
			strcat(story, dstr2);
			strcat(story, singleSpace);
			strcat(story, dstr3);
			strcat(story, " was pronounced dead at ");
			strcat(story, LCSrandom(12) + 1);
			strcat(story, ":");
			strcat(story, LCSrandom(60));
			strcat(story, pickrandom(AMorPM));
			strcat(story, " yesterday at the ");
			char jstr[200];
			strcpy(jstr, lastname(true).data());
			strcat(story, jstr);
			strcat(story, " Correctional Facility.&r");
			strcat(story, "  ");
			strcat(story, dstr3);
			strcat(story, " was convicted in ");
			strcat(story, year - LCSrandom(11) - 10);
			strcat(story, " of 13 serial murders.  ");
			strcat(story, "Since then, numerous pieces of exculpatory evidence ");
			strcat(story, "have been produced, including ");
			switch (LCSrandom(3))
			{
			case 0: strcat(story, "a confession from another convict.  "); break;
			case 1: strcat(story, "a battery of negative DNA tests.  "); break;
			case 2:
				strcat(story, "an admission from a former prosecutor that ");
				strcat(story, dstr3);
				strcat(story, " was framed.  ");
				break;
			}
			strcat(story, "The state still went through with the execution, with a ");
			strcat(story, "spokesperson for the governor saying, ");
			strcat(story, "\"");
			switch (LCSrandom(3))
			{
			case 0: strcat(story, "Let's not forget the convict is colored.  You know how their kind are"); break;
			case 1:
				strcat(story, "The convict is always referred to by three names.  ");
				strcat(story, "Assassin, serial killer, either way ฤฤ guilty.  ");
				strcat(story, "End of story");
				break;
			case 2: strcat(story, "The family wants closure.  We don't have time for another trial"); break;
			}
			strcat(story, ".\"");
			strcat(story, ampersandR);
			strcat(story, "  Candlelight vigils were held throughout the country last night during the execution, ");
			strcat(story, "and more events are expected this evening.  If there is a bright side to be found from this ");
			strcat(story, "tragedy, it will be that our nation is now evaluating the ease with which people ");
			strcat(story, "can be put to death in this country.");
			strcat(story, ampersandR);
			break;
		}
		case VIEW_INTELLIGENCE:
		{
			strcat(story, "Washington, DC - The FBI might be keeping tabs on you.  ");
			strcat(story, "This newspaper yesterday received a collection of files from a source in the Federal Bureau of Investigations.  ");
			strcat(story, "The files contain information on which people have been attending demonstrations, organizing ");
			strcat(story, "unions, working for liberal organizations ฤฤ even ");
			strcat(story, pickrandom(liberalCrime));
			strcat(story, ampersandR);
			strcat(story, "  More disturbingly, the files make reference to a plan to ");
			strcat(story, "\"deal with the undesirables\", although this phrase is not clarified.  ");
			strcat(story, ampersandR);
			strcat(story, "  The FBI refused to comment initially, but when confronted with the information, ");
			strcat(story, "a spokesperson stated, \"");
			strcat(story, "Well, you know, there's privacy, and there's privacy.  ");
			strcat(story, "It might be a bit presumptive to assume that ");
			strcat(story, "these files deal with the one and not the other.  ");
			strcat(story, "You think about that before you continue slanging accusations");
			strcat(story, ".\"");
			strcat(story, ampersandR);
			break;
		}
		case VIEW_FREESPEECH:
		{
			strcpy(story, cityname());
			strcat(story, " - A children's story has been removed from libraries here after ");
			strcat(story, "the city bowed to pressure from religious groups.");
			strcat(story, ampersandR);
			strcat(story, "   The book, ");
			strcat(story, "_");
			char dstr[200], nstr[200];
			generate_name(nstr, dstr);
			strcat(story, nstr);
			strcat(story, "_");
			strcat(story, dstr);
			strcat(story, "_and_the_");
			strcat(story, pickrandom(book_title));
			strcat(story, "_");
			strcat(story, pickrandom(book_title_2));
			strcat(story, "_, is the third in an immensely popular series by ");
			strcat(story, pickrandom(random_nationality));
			strcat(story, " author ");
			char c[2] = { 0,0 };
			c[0] = 'A' + LCSrandom(26);
			strcat(story, c);
			strcat(story, singleDot);
			c[0] = 'A' + LCSrandom(26);
			strcat(story, c);
			strcat(story, ". ");
			strcpy(dstr, lastname());
			strcat(story, dstr);
			strcat(story, ".  ");
			strcat(story, "Although the series is adored by children worldwide, ");
			strcat(story, "some conservatives feel that the books ");
			strcat(story, pickrandom(conservative_oppose_book));
			strcat(story, "  ");
			strcat(story, "In their complaint, the groups cited an incident involving ");
			switch (LCSrandom(3))
			{
			case 0: strcat(story, "a child that swore in class"); break;
			case 1: strcat(story, "a child that said a magic spell at her parents"); break;
			case 2: strcat(story, "a child that ");
				strcat(story, pickrandom(petty_violence));
				strcat(story, singleSpace);
				strcat(story, pickrandom(his_her));
				strcat(story, singleSpace);
				strcat(story, pickrandom(older_younger));
				strcat(story, singleSpace);
				strcat(story, pickrandom(brother_sister));
				break;
			}
			strcat(story, " as key evidence of the dark nature of the book.");
			strcat(story, ampersandR);
			strcat(story, "   When the decision to ban the book was announced yesterday, ");
			strcat(story, "many area children spontaneously broke into tears.  One child was ");
			strcat(story, "heard saying, \"");
			switch (LCSrandom(2))
			{
			case 0:
				strcat(story, "Mamma, is ");
				strcat(story, nstr);
				strcat(story, " dead?");
				break;
			case 1:
				strcat(story, "Mamma, why did they kill ");
				strcat(story, nstr);
				strcat(story, "?");
				break;
			}
			strcat(story, "\"");
			strcat(story, ampersandR);
			break;
		}
		case VIEW_JUSTICES:
		{
			strcpy(story, cityname());
			strcat(story, " - Conservative federal judge ");
			char dstr[200], dstr2[200];
			generate_name(dstr, dstr2, GENDER_WHITEMALEPATRIARCH);
			strcat(story, dstr);
			strcat(story, singleSpace);
			strcat(story, dstr2);
			if (lawList[LAW_FREESPEECH] == -2) strcat(story, " has resigned in disgrace after being caught with a [civil servant].");
			else strcat(story, " has resigned in disgrace after being caught with a prostitute.");
			strcat(story, ampersandR);
			strcat(story, "  ");
			strcat(story, dstr2);
			strcat(story, ", who once ");
			strcat(story, pickrandom(crazy_conservative_act));
			strcat(story, ", was found with ");
			char pstr[200], pstr2[200];
			generate_name(pstr, pstr2);
			strcat(story, pstr);
			strcat(story, singleSpace);
			strcat(story, pstr2);
			strcat(story, " last week in a hotel during a police sting operation.  ");
			strcat(story, "According to sources familiar with the particulars, ");
			strcat(story, "when police broke into the hotel room they saw ");
			if (lawList[LAW_FREESPEECH] == -2) {
				strcat(story, pickrandom(judge_with_prostitute_no_free_speech));
			}
			else if (lawList[LAW_FREESPEECH] == 2) {
				strcat(story, pickrandom(judge_with_prostitute_full_free_speech));
			}
			else {
				strcat(story, pickrandom(judge_with_prostitute));
			}
			strcat(story, "  ");
			strcat(story, pstr2);
			strcat(story, " reportedly offered ");
			strcat(story, pickrandom(bribe_officers));
			strcat(story, " in exchange for their silence.");
			strcat(story, ampersandR);
			strcat(story, "  ");
			strcat(story, dstr2);
			strcat(story, " could not be reached for comment, although an aid stated that ");
			strcat(story, "the judge would be going on a Bible retreat for a few weeks to ");
			strcat(story, "\"Make things right with the Almighty Father.\"  ");
			strcat(story, ampersandR);
			break;
		}
		case VIEW_AMRADIO:
		{
			strcpy(story, cityname());
			strcat(story, " - Well-known AM radio personality ");
			char dstr[200], dstr2[200];
			generate_name(dstr, dstr2, GENDER_WHITEMALEPATRIARCH);
			strcat(story, dstr);
			strcat(story, singleSpace);
			strcat(story, dstr2);
			strcat(story, " went off for fifteen minutes in an inexplicable rant ");
			strcat(story, "two nights ago during the syndicated radio program \"");
			strcat(story, pickrandom(radio_name));
			strcat(story, singleSpace);
			strcat(story, pickrandom(radio_name_2));
			strcat(story, "\".");
			strcat(story, ampersandR);
			strcat(story, "  ");
			strcat(story, dstr2);
			strcat(story, "'s monologue for the evening began the way that fans ");
			strcat(story, "had come to expect, with attacks on the \"liberal media establishment\" and ");
			strcat(story, "the \"elite liberal agenda\".  But when the radio icon said, \"");
			switch (LCSrandom(radio_host_crazy_quote.size()))
			{
			case 0:
				strcat(story, "and the greatest living example of a reverse racist is the ");
				if (presparty != CONSERVATIVE_PARTY) strcat(story, "current president!"); // Limbaugh
				else strcat(story, "liberal media establishment!");
				break;
			default:
				strcat(story, pickrandom(radio_host_crazy_quote));
				break;
			}
			strcat(story, "\", a former fan of the show, ");
			char nstr[200], nstr2[200];
			generate_name(nstr, nstr2);
			strcat(story, nstr);
			strcat(story, singleSpace);
			strcat(story, nstr2);
			strcat(story, ", knew that \"");
			strcat(story, pickrandom(my_idol));
			strcat(story, " had ");
			switch (LCSrandom(radio_host_lost_mind.size()))
			{
			case 0:
				strcat(story, "lost ");
				strcat(story, "his"); // the AM personality's a white male patriarch
				if (lawList[LAW_FREESPEECH] == 2)strcat(story, " goddamn mind");
				else if (lawList[LAW_FREESPEECH] == -2)strcat(story, " [gosh darn] mind");
				else strcat(story, " g*dd*mn mind");
				break;
			default:
				strcat(story, pickrandom(radio_host_lost_mind));
			}
			strcat(story, ".  After that, it just got worse and worse.\"");
			strcat(story, ampersandR);
			strcat(story, "  ");
			strcat(story, dstr2);
			strcat(story, " issued an apology later in the program, but ");
			strcat(story, "the damage might already be done.  ");
			strcat(story, "According to a poll completed yesterday, ");
			strcat(story, "fully half of the host's most loyal supporters ");                    // XXX How many of them switch should
			strcat(story, "have decided to leave the program for saner ");                        //     depend on [LAW_FREESPEECH]
			strcat(story, "pastures.  Of these, many said that they would be switching over ");
			strcat(story, "to the FM band.");
			strcat(story, ampersandR);
			break;
		}
		case VIEW_GUNCONTROL:
		{
			const int schtype = LCSrandom(4);
			strcpy(story, cityname());
			strcat(story, spaceDashSpace);
			strcat(story, "A student has gone on a ");
			if (lawList[LAW_FREESPEECH] == -2) strcat(story, "[hurting spree]");
			else strcat(story, "shooting rampage");
			strcat(story, " at a local ");
			switch (schtype)
			{
			case 0: strcat(story, "elementary school"); break;
			case 1: strcat(story, "middle school"); break;
			case 2: strcat(story, "high school"); break;
			case 3: strcat(story, "university"); break;
			}
			strcat(story, ".  ");
			char dstr[200], dstr2[200];
			const char dg = (LCSrandom(2) == 1 ? GENDER_MALE : GENDER_FEMALE);
			generate_name(dstr, dstr2, dg);
			strcat(story, dstr);
			strcat(story, singleSpace);
			strcat(story, dstr2);
			strcat(story, commaSpace);
			//6->11,10->15,14->19,18->23
			strcat(story, 6 + (schtype * 4) + LCSrandom(6)); //generate an age that would roughly correspond to the schtype
			strcat(story, ", used a variety of guns to ");
			if (lawList[LAW_FREESPEECH] == -2)strcat(story, "[scare]");
			else strcat(story, "mow down");
			strcat(story, " more than a dozen classmates and two teachers at ");
			char jstr[200];
			strcpy(jstr, lastname(true).data());
			strcat(story, jstr);
			switch (schtype)
			{
			case 0: strcat(story, " Elementary School"); break;
			case 1: strcat(story, " Middle School"); break;
			case 2: strcat(story, " High School"); break;
			case 3: strcat(story, " University"); break;
			}
			strcat(story, ".  ");
			strcat(story, dstr2);
			strcat(story, " entered the ");
			if (schtype != 3) strcat(story, "school ");
			else strcat(story, "university ");
			strcat(story, " while classes were in session, then systematically started breaking into ");
			strcat(story, "classrooms, ");
			if (lawList[LAW_FREESPEECH] == -2) strcat(story, "[scaring]");
			else strcat(story, "spraying bullets at");
			strcat(story, " students and teachers inside.  ");
			strcat(story, "When other students tried to wrestle the weapons away from ");
			strcat(story, (dg == GENDER_FEMALE ? "her" : "him"));
			strcat(story, ", they were ");
			if (lawList[LAW_FREESPEECH] == -2) strcat(story, "[unfortunately harmed]");
			else strcat(story, "shot");
			strcat(story, " as well.&r");
			strcat(story, "  When the police arrived, the student had already ");
			if (lawList[LAW_FREESPEECH] == -2) strcat(story, "[hurt some people].  ");
			else
			{
				strcat(story, "killed ");
				strcat(story, 2 + LCSrandom(30));
				strcat(story, " and wounded dozens more.  ");
			}
			strcat(story, dstr);
			if (lawList[LAW_FREESPEECH] == -2)strcat(story, " [feel deeply asleep]");
			else strcat(story, " committed suicide");
			strcat(story, " shortly afterwards.&r");
			strcat(story, "  Investigators are currently searching the student's belongings, and initial ");
			strcat(story, "reports indicate that the student kept a journal that showed ");
			strcat(story, (dg == GENDER_FEMALE ? "she" : "he"));
			strcat(story, " was disturbingly obsessed with guns and death.&r");
			break;
		}
		case VIEW_PRISONS:
		{
			strcpy(story, cityname());
			strcat(story, " - A former prisoner has written a book describing in horrifying ");
			strcat(story, "detail what goes on behind bars.  ");
			strcat(story, "Although popular culture has used, or perhaps overused, the ");
			strcat(story, "prison theme lately in its offerings for mass consumption, rarely ");
			strcat(story, "have these works been as poignant as ");
			char dstr[200], dstr2[200];
			generate_name(dstr, dstr2); // allow either gender (look up "Orange is the New Black" online to see why)
			strcat(story, dstr);
			strcat(story, singleSpace);
			strcat(story, dstr2);
			strcat(story, "'s new tour-de-force, _");
			strcat(story, pickrandom(prison_book_title));
			strcat(story, "_");
			if (!LCSrandom(prison_book_title_2.size())) {
				if (lawList[LAW_FREESPEECH] == -2) strcat(story, "[Bum]lord");
				else strcat(story, "Buttlord");
			}
			else {
				strcat(story, pickrandom(prison_book_title_2));
			}
			strcat(story, "_.&r");
			strcat(story, "   Take this excerpt, \"");//TODO: Add more excerpts, more variety.
			strcat(story, "The steel bars grated forward in their rails, ");
			strcat(story, "coming to a halt with a deafening clang that said it all ฤฤ ");
			strcat(story, "I was trapped with them now.  There were three, looking me over ");
			strcat(story, "with dark glares of bare lust, as football players might stare at a stupefied, drunken, helpless teenager.  ");
			strcat(story, "My shank's under the mattress.  Better to be brave and fight or chicken out and let them take it?  ");
			strcat(story, "Maybe lose an eye the one way, maybe catch ");
			if (lawList[LAW_GAY] == -2)strcat(story, "GRIDS");// Gay Related Immunodeficiency Syndrome, an obsoleted/politically incorrect name for "AIDS".
			else strcat(story, "AIDS");
			strcat(story, " the other.  A ");
			if (lawList[LAW_FREESPEECH] == -2)strcat(story, "[difficult]");
			else strcat(story, "helluva");
			strcat(story, " choice, and I would only have a few seconds before they made it for me");
			strcat(story, ".\"");
			strcat(story, ampersandR);
			break;
		}
		}
	}
	else
	{
		switch (view)
		{
		case VIEW_DEATHPENALTY:
		{
			strcpy(story, cityname());
			strcat(story, " - Perhaps parents can rest easier tonight.  ");
			strcat(story, "The authorities have apprehended their primary suspect in the ");
			strcat(story, "string of brutal child killings that has kept everyone in the area on edge, ");
			strcat(story, "according to a spokesperson for the police department here.  ");
			char dstr[200], dstr2[200], dstr3[200];
			generate_long_name(dstr, dstr2, dstr3);
			strcat(story, dstr);
			strcat(story, singleSpace);
			strcat(story, dstr2);
			strcat(story, singleSpace);
			strcat(story, dstr3);
			strcat(story, " was detained yesterday afternoon, reportedly in possession of ");
			strcat(story, pickrandom(evidence_of_child_murder));
			strcat(story, ".  Over twenty children in the past two years have gone missing, ");
			strcat(story, "only to turn up later");
			if (lawList[LAW_FREESPEECH] == -2)
				strcat(story, " [in a better place]");
			else
			{
				strcat(story, " dead and ");
				strcat(story, pickrandom(mutilated_corpse));
			}
			strcat(story, ".  Sources say that the police got a break in the case when ");
			strcat(story, pickrandom(break_in_murder_case));
			strcat(story, singleDot);
			strcat(story, ampersandR);
			strcat(story, "   The district attorney's office has already repeatedly said it will be ");
			strcat(story, "seeking ");
			if (lawList[LAW_DEATHPENALTY] == 2)
				strcat(story, "life imprisonment in this case.");
			else
				strcat(story, "the death penalty in this case.");
			strcat(story, ampersandR);
			break;
		}
		case VIEW_ANIMALRESEARCH:
		{
			strcpy(story, cityname());
			strcat(story, " - Researchers ");
			if (lawList[LAW_ANIMALRESEARCH] == 2)
			{
				strcat(story, "from ");
				strcat(story, pickrandom(animal_research_country));
				strcat(story, " report that they have discovered an amazing new wonder drug. ");
			}
			else
				strcat(story, "here report that they have discovered an amazing new wonder drug.  ");
			strcat(story, "Called ");
			if (LCSrandom(drug_name.size())) {
				strcat(story, pickrandom(drug_name));
			}
			else {
				if (lawList[LAW_FREESPEECH] == -2)strcat(story, "Bum-Bum");
				else strcat(story, "Anal"); break;
			}
			strcat(story, pickrandom(drug_name_2));
			strcat(story, ", the drug apparently ");
			if (LCSrandom(chimp_drug_impact.size())) {
				strcat(story, pickrandom(chimp_drug_impact));
			}
			else {
				if (lawList[LAW_FREESPEECH] == -2)strcat(story, "[helps chimpanzees reproduce]");
				else strcat(story, "corrects erectile dysfunction in chimpanzees"); break;
			}
			strcat(story, ".  ");
			strcat(story, ampersandR);
			strcat(story, "   Along with bonobos, chimpanzees are our closest cousins");
			strcat(story, ".  ");
			strcat(story, "Fielding questions about the ethics of their experiments from reporters during a press conference yesterday, ");
			strcat(story, "a spokesperson for the research team stated that, \"It really isn't so bad as all that.  Chimpanzees are very resilient creatures.  ");
			strcat(story, pickrandom(chimp_drug_horror));
			strcat(story, ".  We have a very experienced research team.  ");
			strcat(story, "While we understand your concerns, any worries are entirely unfounded.  ");
			strcat(story, "I think the media should be focusing on the enormous benefits of this drug.");
			strcat(story, "\"");
			strcat(story, ampersandR);
			strcat(story, "   The first phase of human trials is slated to begin in a few months.");
			strcat(story, ampersandR);
			break;
		}
		case VIEW_INTELLIGENCE:
		{
			strcat(story, "Washington, DC - The CIA announced yesterday that it has averted a terror attack that ");
			strcat(story, "would have occurred on American soil.");
			strcat(story, ampersandR);
			strcat(story, "   According to a spokesperson for the agency, ");
			strcat(story, pickrandom(terrorist_group));
			strcat(story, " planned to ");
			if (lawList[LAW_FREESPEECH] == -2)strcat(story, pickrandom(terrorist_plot_no_free_speech));
			else strcat(story, pickrandom(terrorist_plot));
			strcat(story, ".  However, intelligence garnered from deep within the mysterious ");
			strcat(story, "terrorist organization allowed the plot to be foiled just days before it ");
			strcat(story, "was to occur.");
			strcat(story, ampersandR);
			strcat(story, "   The spokesperson further stated, \"");
			strcat(story, "I won't compromise our sources and methods, but let me just say ");
			strcat(story, "that we are grateful to the Congress and this Administration for ");
			strcat(story, "providing us with the tools we need to neutralize these enemies of ");
			strcat(story, "civilization before they can destroy American families.  ");
			strcat(story, "However, let me also say that there's more that needs to be done.  ");
			strcat(story, "The Head of the Agency will be sending a request to Congress ");
			strcat(story, "for what we feel are the essential tools for combating terrorism in ");
			strcat(story, "this new age.");
			strcat(story, "\"");
			strcat(story, ampersandR);
			break;
		}
		case VIEW_GENETICS:
		{
			strcpy(story, cityname());
			strcat(story, " - The genetic foods industry staged a major event here yesterday ");
			strcat(story, "to showcase its upcoming products.  Over thirty companies set up ");
			strcat(story, "booths and gave talks to wide-eyed onlookers.");
			strcat(story, ampersandR);
			strcat(story, "   One such corporation, ");
			strcat(story, pickrandom(gene_corp_name));
			strcat(story, singleSpace);
			strcat(story, pickrandom(gene_corp_name_2));
			strcat(story, ", presented their product, \"");
			strcat(story, pickrandom(gene_product_name));
			strcat(story, singleSpace);
			strcat(story, pickrandom(gene_product_name_2));
			strcat(story, "\", during an afternoon PowerPoint presentation.  ");
			strcat(story, "According to the public relations representative speaking, ");
			strcat(story, "this amazing new product actually ");
			strcat(story, pickrandom(gene_product_benefit));
			strcat(story, singleDot);
			strcat(story, ampersandR);
			strcat(story, "   Spokespeople for the GM corporations were universal ");
			strcat(story, "in their dismissal of the criticism which often follows the industry.  ");
			strcat(story, "One in particular said, \"");
			strcat(story, "Look, these products are safe.  That thing about the ");
			strcat(story, pickrandom(gene_product_cost));
			strcat(story, " is just a load of ");
			if (lawList[LAW_FREESPEECH] == -2) {
				strcat(story, pickrandom(bullshit_no_free_speech));
			}
			else {
				strcat(story, pickrandom(bullshit));
			}
			strcat(story, ".  Would we stake the reputation of our company on unsafe products?  ");
			strcat(story, "No.  That's just ridiculous.  I mean, sure companies have put unsafe products out, ");
			strcat(story, "but the GM industry operates at a higher ethical standard.  That goes without saying.");
			strcat(story, "\"");
			strcat(story, ampersandR);
			break;
		}
		case VIEW_JUSTICES:
		{
			strcpy(story, cityname());
			strcat(story, " - The conviction of confessed serial killer ");
			char dstr[200], dstr2[200], dstr3[200];
			generate_long_name(dstr, dstr2, dstr3);
			strcat(story, dstr);
			strcat(story, singleSpace);
			strcat(story, dstr2);
			strcat(story, singleSpace);
			strcat(story, dstr3);
			strcat(story, " was overturned by a federal judge yesterday.  ");
			strcat(story, "Justice ");
			char jstr[200], jstr2[200];
			const char gn = (LCSrandom(2) == 1 ? GENDER_MALE : GENDER_FEMALE);
			generate_name(jstr, jstr2, gn);
			strcat(story, jstr);
			strcat(story, singleSpace);
			strcat(story, jstr2);
			strcat(story, " of the notoriously liberal circuit of appeals here ");
			strcat(story, "made the decision based on ");
			char gen[20];
			strcpy(gen, (gn == GENDER_FEMALE ? "her" : "his"));
			switch (LCSrandom(7))
			{
			case 0:strcat(story, "ten-year-old eyewitness testimony"); break;
			case 1:strcat(story, gen); strcat(story, " general feeling about police corruption"); break;
			case 2:strcat(story, gen); strcat(story, " belief that the crimes were a vast right-wing conspiracy"); break; // Clinton
			case 3:
				strcat(story, gen);
				strcat(story, " belief that ");
				strcat(story, dstr3);
				strcat(story, " deserved another chance");
				break;
			case 4:
				strcat(story, gen);
				strcat(story, " personal philosophy of liberty"); break;
			case 5:
				strcat(story, gen);
				strcat(story, " close personal friendship with the ");
				strcat(story, dstr3);      // I know Charles Manson.
				strcat(story, " family");  // Charles Manson was a friend of mine.
				break;                    // And you, sir, are no Charles Manson!
			case 6:strcat(story, gen); strcat(story, " consultations with a Magic 8-Ball"); break;
			}
			strcat(story, ", despite the confession of ");
			strcat(story, dstr3);
			strcat(story, ", which even Justice ");
			strcat(story, jstr2);
			strcat(story, " grants was not coerced in any way.&r");
			strcat(story, "   Ten years ago, ");
			strcat(story, dstr3);
			strcat(story, " was convicted of the now-infamous ");
			char sstr[200];
			strcpy(sstr, lastname());
			strcat(story, sstr);
			strcat(story, " slayings.  ");
			strcat(story, "After an intensive manhunt, ");
			strcat(story, dstr3);
			strcat(story, " was found with the murder weapon, ");
			strcat(story, "covered in the victims' blood.  ");
			strcat(story, dstr3);
			strcat(story, " confessed and was sentenced to life, saying \"");
			strcat(story, "Thank you for saving me from myself.  ");
			strcat(story, "If I were to be released, I would surely kill again.\"&r");
			strcat(story, "   A spokesperson for the district attorney ");
			strcat(story, "has stated that the case will not be retried, due ");
			strcat(story, "to the current economic doldrums that have left the state ");
			strcat(story, "completely strapped for cash.&r");
			break;
		}
		case VIEW_POLLUTION:
			strcpy(story, cityname());
			strcat(story, " - Pollution might not be so bad after all.  The ");
			strcat(story, pickrandom(family_values_company_name));
			strcat(story, singleSpace);
			strcat(story, pickrandom(family_values_company_name_2));
			strcat(story, singleSpace);
			strcat(story, pickrandom(family_values_company_name_3));
			strcat(story, " recently released a wide-ranging report detailing recent trends ");
			strcat(story, "and the latest science on the issue.  ");
			strcat(story, "Among the most startling of the think tank's findings is that ");
			strcat(story, pickrandom(pollution_consumption));
			strcat(story, " might actually ");
			strcat(story, pickrandom(pollution_consumption_2));
			strcat(story, singleDot);
			strcat(story, ampersandR);
			strcat(story, "   When questioned about the science behind these results, ");
			strcat(story, "a spokesperson stated that, \"");
			strcat(story, pickrandom(i_like_polution));
			strcat(story, ".  You have to realize that ");
			strcat(story, pickrandom(distrust_liberals));
			strcat(story, " these issues to their own advantage.  ");
			strcat(story, "All we've done is introduced a little clarity into the ongoing debate.  ");
			strcat(story, "Why is there contention on the pollution question?  It's because ");
			strcat(story, "there's work left to be done.  We should study much more ");
			strcat(story, "before we urge any action.  Society really just ");
			strcat(story, "needs to take a breather on this one.  We don't see why there's such a rush to judgment here.  ");
			strcat(story, ampersandR);
			break;
		case VIEW_CORPORATECULTURE:
			strcpy(story, cityname());
			strcat(story, " - Several major companies have announced ");
			strcat(story, "at a joint news conference here that they ");
			strcat(story, "will be expanding their work forces considerably ");
			strcat(story, "during the next quarter.  Over thirty thousand jobs ");
			strcat(story, "are expected in the first month, with ");
			strcat(story, "tech giant ");
			strcat(story, pickrandom(tech_giant_name));
			strcat(story, pickrandom(tech_giant_name_2));
			strcat(story, " increasing its payrolls by over ten thousand workers alone.  ");
			strcat(story, "Given the state of the economy recently and in ");
			strcat(story, "light of the tendency ");
			strcat(story, "of large corporations to export jobs overseas these days, ");
			strcat(story, "this welcome news is bound to be a pleasant surprise to those in the unemployment lines.  ");
			strcat(story, "The markets reportedly responded to the announcement with mild interest, ");
			strcat(story, "although the dampened movement might be expected due to the uncertain ");
			strcat(story, "futures of some of the companies in the tech sector.  On the whole, however, ");
			strcat(story, "analysts suggest that not only does the expansion speak to the health ");
			strcat(story, "of the tech industry but is also indicative of a full economic recover.&r");
			break;
		case VIEW_AMRADIO:
		{  //THIS ONE IS SHORTER BECAUSE OF DOUBLE HEADLINE
			strcpy(story, cityname());
			strcat(story, " - Infamous FM radio shock jock ");
			char dstr[200], dstr2[200];
			generate_name(dstr, dstr2, GENDER_WHITEMALEPATRIARCH);
			strcat(story, dstr);
			strcat(story, singleSpace);
			strcat(story, dstr2);
			strcat(story, " has brought radio entertainment to a new low.  During yesterday's ");
			strcat(story, "broadcast of the program \"");
			strcat(story, dstr);
			strcat(story, "'s ");
			strcat(story, pickrandom(fm_radio_name));
			strcat(story, singleSpace);
			strcat(story, pickrandom(fm_radio_name_2));
			strcat(story, "\", ");
			strcat(story, dstr2);
			strcat(story, " reportedly ");
			switch (LCSrandom(5))
				// IsaacG Migrate Strings?
			{
			case 0:
				if (lawList[LAW_FREESPEECH] == -2)strcat(story, "[had consensual intercourse in the missionary position]");
				else if (lawList[LAW_FREESPEECH] == 2)strcat(story, "fucked");
				else strcat(story, "had intercourse"); break;
			case 1:
				if (lawList[LAW_FREESPEECH] == -2)strcat(story, "encouraged listeners to call in and [urinate]");
				else if (lawList[LAW_FREESPEECH] == 2)strcat(story, "encouraged listeners to call in and take a piss");
				else strcat(story, "encouraged listeners to call in and relieve themselves"); break;
			case 2:
				if (lawList[LAW_FREESPEECH] == 2)strcat(story, "screamed \"fuck the police those goddamn motherfuckers.  I got a fucking ticket this morning and I'm fucking pissed as shit.\"");
				else if (lawList[LAW_FREESPEECH] == -2)strcat(story, "screamed \"[darn] the police those [big dumb jerks]. I got a [stupid] ticket this morning and I'm [so angry].\"");
				else strcat(story, "screamed \"f*ck the police those g*dd*mn m*th*f*ck*rs.  I got a f*cking ticket this morning and I'm f*cking p*ss*d as sh*t.\""); break;
			case 3:
				if (lawList[LAW_FREESPEECH] == -2 && lawList[LAW_WOMEN] == -2)strcat(story, "[fed] from [an indecent] woman");
				else if (lawList[LAW_FREESPEECH] != -2 && lawList[LAW_WOMEN] == -2)strcat(story, "breastfed from an exposed woman");
				else if (lawList[LAW_FREESPEECH] == -2 && lawList[LAW_WOMEN] != -2)strcat(story, "[fed] from a [woman]");
				else strcat(story, "breastfed from a lactating woman"); break;
			case 4:
				if (lawList[LAW_FREESPEECH] == -2)strcat(story, "[had fun]");
				else strcat(story, "masturbated"); break;
			}
			strcat(story, " on the air.  Although ");
			strcat(story, dstr2);
			strcat(story, " later apologized, ");
			strcat(story, "the FCC received ");
			if (lawList[LAW_FREESPEECH] == -2) strcat(story, "thousands of");
			else if (lawList[LAW_FREESPEECH] == -1) strcat(story, "several hundred");
			else if (lawList[LAW_FREESPEECH] == 0) strcat(story, "hundreds of");
			else if (lawList[LAW_FREESPEECH] == 1) strcat(story, "dozens of");
			else strcat(story, "some");
			strcat(story, " complaints ");
			strcat(story, "from irate listeners ");
			if (lawList[LAW_FREESPEECH] == -2) strcat(story, "across the nation. ");
			else if (lawList[LAW_FREESPEECH] == -1) strcat(story, "from all over the state. ");
			else if (lawList[LAW_FREESPEECH] == 0) strcat(story, "within the county. ");
			else if (lawList[LAW_FREESPEECH] == 1) strcat(story, "in neighboring towns. ");
			else strcat(story, "within the town. ");
			strcat(story, " A spokesperson for the FCC ");
			strcat(story, "stated that the incident is under investigation.");
			strcat(story, ampersandR);
			break;
		}
		case VIEW_GUNCONTROL:
		{
			strcpy(story, cityname());
			char jstr[200], jstr2[200], jstr3[200], jstr4[200], jstr5[200], tg2[10];
			const char jg1 = (LCSrandom(2) ? GENDER_MALE : GENDER_FEMALE);
			const char jg2 = (LCSrandom(2) ? GENDER_MALE : GENDER_FEMALE);
			generate_long_name(jstr, jstr2, jstr3, jg1);
			generate_name(jstr4, jstr5, jg2);
			strcat(story, " - In a surprising turn, a ");
			if (lawList[LAW_FREESPEECH] == -2) strcat(story, "[hurting spree]"); else strcat(story, "mass shooting");
			strcat(story, " was prevented by a bystander with a gun.");
			strcat(story, " After ");
			strcat(story, jstr);
			strcat(story, singleSpace);
			strcat(story, jstr2);
			strcat(story, " opened fire at the ");
			strcat(story, jstr3);
			strcat(story, singleSpace);
			strcat(story, pickrandom(public_place));
			strcat(story, commaSpace);
			strcat(story, jstr4);
			strcat(story, singleSpace);
			strcat(story, jstr5);
			strcat(story, " sprung into action. ");
			strcat(story, "The citizen pulled a concealed handgun and fired once at the shooter, ");
			strcat(story, "forcing ");
			strcat(story, jstr2);
			strcat(story, " to take cover while others called the police.&r");
			strcat(story, "  Initially, ");
			if (jg2 == GENDER_FEMALE)
			{
				if (LCSrandom(4) < lawList[LAW_WOMEN] + 2) // 0% chance at lawList[LAW_WOMEN]==-2, 100% chance at lawList[LAW_WOMEN]==2
					strcpy(tg2, "Ms. ");
				else
					strcpy(tg2, (LCSrandom(2) ? "Mrs. " : "Miss "));
			}
			else strcpy(tg2, "Mr. ");
			strcat(story, tg2);
			strcat(story, jstr5);
			strcat(story, " attempted to talk down the shooter, but as ");
			strcat(story, jstr2);
			strcat(story, " became more agitated, the heroic citizen was forced to engage the shooter in a ");
			if (lawList[LAW_FREESPEECH] == -2) strcat(story, "firefight, [putting the attacker to sleep] ");
			else strcat(story, "firefight, killing the attacker ");
			strcat(story, "before ");
			strcat(story, (jg1 == GENDER_FEMALE ? "she " : "he "));
			strcat(story, "could hurt anyone else.&r");
			strcat(story, "  The spokesperson for the police department said, \"We'd have a yet another ");
			if (lawList[LAW_FREESPEECH] == -2) strcat(story, "[hurting spree]");
			else strcat(story, "mass shooting");
			strcat(story, " if not for ");
			strcat(story, tg2);
			strcat(story, jstr5);
			strcat(story, "'s heroic actions.\"");
			break;
		}
		case VIEW_PRISONS:
		{
			strcpy(story, cityname());
			strcat(story, " - The hostage crisis at the ");
			char jstr[200];
			strcpy(jstr, lastname(true).data());
			strcat(story, jstr);
			strcat(story, " Correctional Facility ended tragically yesterday with the ");
			strcat(story, "death of both the prison guard being held hostage and ");
			const char ggn = (LCSrandom(2) == 1 ? GENDER_MALE : GENDER_FEMALE);
			strcat(story, (ggn == GENDER_FEMALE ? "her" : "his"));
			strcat(story, " captor.");
			strcat(story, ampersandR);
			if (lawList[LAW_FREESPEECH] == -2)strcat(story, "   Two weeks ago, convicted [reproduction fiend] ");
			else strcat(story, "   Two weeks ago, convicted rapist ");
			char dstr[200], dstr2[200];
			const char dgn = (LCSrandom(2) == 1 ? GENDER_MALE : GENDER_FEMALE);
			generate_name(dstr, dstr2, dgn);
			strcat(story, dstr);
			strcat(story, singleSpace);
			strcat(story, dstr2);
			strcat(story, ", an inmate at ");
			strcat(story, jstr);
			strcat(story, ", overpowered ");
			char gstr[200], gstr2[200];
			generate_name(gstr, gstr2, ggn);
			strcat(story, gstr);
			strcat(story, singleSpace);
			strcat(story, gstr2);
			strcat(story, " and barricaded ");
			strcat(story, (dgn == GENDER_FEMALE ? "herself" : "himself"));
			strcat(story, " with the guard in a prison tower.  ");
			strcat(story, "Authorities locked down the prison and ");
			strcat(story, "attempted to negotiate by phone for ");
			strcat(story, LCSrandom(18) + 5);
			strcat(story, " days, but talks were cut short when ");
			strcat(story, dstr2);
			strcat(story, " reportedly screamed into the receiver \"");
			switch (LCSrandom(4))
			{
				// IsaacG Migrate Strings?
			case 0:
				if (lawList[LAW_FREESPEECH] == 2)strcat(story, "Ah, fuck this shit.  This punk bitch is fuckin' dead!");
				else if (lawList[LAW_FREESPEECH] == -2)strcat(story, "Ah, [no way.]  This [police officer will be harmed!]");
				else strcat(story, "Ah, f*ck this sh*t.  This punk b*tch is f*ckin' dead!");
				break;
			case 1:
				if (lawList[LAW_FREESPEECH] == 2)strcat(story, "Fuck a muthafuckin' bull.  I'm killin' this pig shit.");
				else if (lawList[LAW_FREESPEECH] == -2)strcat(story, "[Too late.]  [I am going to harm this police officer.]");
				else strcat(story, "F*ck a m*th*f*ck*n' bull.  I'm killin' this pig sh*t.");
				break;
			case 2:
				if (lawList[LAW_FREESPEECH] == 2)strcat(story, "Why the fuck am I talkin' to you?  I'd rather kill this pig.");
				else if (lawList[LAW_FREESPEECH] == -2)strcat(story, "Why [am I] talkin' to you?  I'd rather [harm this police officer.]");
				else strcat(story, "Why the f*ck am I talkin' to you?  I'd rather kill this pig.");
				break;
			case 3:
				if (lawList[LAW_FREESPEECH] == 2)strcat(story, "Imma kill all you bitches, startin' with this mothafucker here.");
				else if (lawList[LAW_FREESPEECH] == -2)strcat(story, "[I will harm all police officers], startin' with this [one] here.");
				else strcat(story, "Imma kill all you b*tches, startin' with this m*th*f*ck*r here.");
				break;
			}
			strcat(story, "\"");
			strcat(story, "  The tower was breached in an attempt to reach ");
			strcat(story, "the hostage, but ");
			strcat(story, dstr2);
			strcat(story, " had already ");
			if (lawList[LAW_FREESPEECH] == -2)strcat(story, "[harmed] the guard");
			else if (lawList[LAW_FREESPEECH] == -1)strcat(story, "killed the guard");
			else switch (LCSrandom(15))
			{
			case 0:strcat(story, "slit the guard's throat with a shank"); break;
			case 1:strcat(story, "strangled the guard to death with a knotted bed sheet"); break;
			case 2:strcat(story, "chewed out the guard's throat"); break;
			case 3:strcat(story, "smashed the guard's skull with the toilet seat from ");
				strcat(story, (dgn == GENDER_FEMALE ? "her" : "his"));
				strcat(story, " cell"); break;
			case 4:strcat(story, "shot the guard with ");
				strcat(story, (ggn == GENDER_FEMALE ? "her" : "his"));
				strcat(story, " own gun"); break;
			case 5:strcat(story, "poisoned the guard with drugs smuggled into the prison by the ");
				strcat(story, (LCSrandom(2) ? "Crips" : "Bloods")); break;
			case 6:strcat(story, "hit all 36 pressure points of death on the guard"); break;
			case 7:strcat(story, "electrocuted the guard with high-voltage wires"); break;
			case 8:strcat(story, "thrown the guard out the top-storey window"); break;
			case 9:strcat(story, "taken the guard to the execution chamber and finished ");
				strcat(story, (ggn == GENDER_FEMALE ? "her" : "him"));
				strcat(story, " off"); break;
			case 10:strcat(story, "tricked another guard into shooting the guard dead"); break;
			case 11:strcat(story, "burnt the guard to a crisp using a lighter and some gasoline"); break;
			case 12:strcat(story, "eaten the guard's liver with some fava beans and a nice chianti"); break;
			case 13:strcat(story, "performed deadly experiments on the guard unheard of since Dr. Mengele"); break;
			case 14:strcat(story, "sacrificed the guard on a makeshift ");
				strcat(story, (LCSrandom(2) ? "Satanic" : "neo-pagan"));
				strcat(story, " altar"); break;
			}
			strcat(story, ".  The prisoner was ");
			if (lawList[LAW_FREESPEECH] == -2)strcat(story, "[also harmed]");
			else strcat(story, "beaten to death");
			strcat(story, " while \"resisting capture\", according to a prison spokesperson.");
			strcat(story, ampersandR);
			break;
		}
		}
	}
}
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
void run_television_news_stories()
{
	char del;
	for (int n = len(newsstory) - 1; n >= 0; n--)
	{
		del = 0;
		if (newsstory[n]->type == NEWSSTORY_MAJOREVENT)
		{
			if (newsstory[n]->positive)
			{
				switch (newsstory[n]->view)
				{
				case VIEW_POLICEBEHAVIOR:
					music.play(MUSIC_LACOPS);
					movie.loadmovie("lacops.cmv");
					movie.playmovie(0, 0);
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(19, 13, "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป");
					mvaddstrAlt(20, 13, "บ     The  police  have  beaten  a  black  man  in   บ");
					mvaddstrAlt(21, 13, "บ   Los Angeles again.  This time, the incident is   บ");
					mvaddstrAlt(22, 13, "บ   taped by  a passerby  and saturates  the news.   บ");
					mvaddstrAlt(23, 13, "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
					getkeyAlt();
					del = 1;
					break;
				case VIEW_CABLENEWS:
				{
					music.play(MUSIC_NEWSCAST);
					char str[80];
					strcpy(str, "Tonight on a Cable News channel: ");
					strcat(str, pickrandom(cable_name));
					strcat(str, singleSpace);
					strcat(str, pickrandom(cable_name_2));
					strcat(str, " with ");
					char bname[80];
					generate_name(bname, GENDER_WHITEMALEPATRIARCH);
					strcat(str, bname);
					eraseAlt();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrCenter(0, str);
					mvaddstrAlt(16, 20, bname);
					mvaddstrAlt(17, 20, pickrandom(cable_city).data());
					moveAlt(16, 41);
					generate_name(bname);
					addstrAlt(bname);
					mvaddstrAlt(17, 41, pickrandom(cable_city_2).data());
					movie.loadmovie("newscast.cmv");
					movie.playmovie(1, 1);
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(19, 13, "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป");
					mvaddstrAlt(20, 13, "บ     A  Cable  News  anchor  accidentally  let  a   บ");
					mvaddstrAlt(21, 13, "บ   bright Liberal guest  finish a sentence.  Many   บ");
					mvaddstrAlt(22, 13, "บ   viewers  across  the  nation  were  listening.   บ");
					mvaddstrAlt(23, 13, "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
					getkeyAlt();
					del = 1;
					break;
				}
				}
			}
			else
			{
				switch (newsstory[n]->view)
				{
				case VIEW_CEOSALARY:
					music.play(MUSIC_GLAMSHOW);
					movie.loadmovie("glamshow.cmv");
					movie.playmovie(0, 0);
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(19, 13, "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป");
					mvaddstrAlt(20, 13, "บ     A new show glamorizing the lives of the rich   บ");
					mvaddstrAlt(21, 13, "บ   begins airing  this week.  With the nationwide   บ");
					mvaddstrAlt(22, 13, "บ   advertising  blitz, it's bound  to be popular.   บ");
					mvaddstrAlt(23, 13, "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
					getkeyAlt();
					del = 1;
					break;
				case VIEW_CABLENEWS:
					music.play(MUSIC_ANCHOR);
					movie.loadmovie("anchor.cmv");
					movie.playmovie(0, 0);
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(19, 13, "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป");
					mvaddstrAlt(20, 13, "บ     A major Cable News channel has hired a slick   บ");
					mvaddstrAlt(21, 13, "บ   new anchor for  one of its news shows.  Guided   บ");
					mvaddstrAlt(22, 13, "บ   by impressive  advertising, America  tunes in.   บ");
					mvaddstrAlt(23, 13, "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
					getkeyAlt();
					del = 1;
					break;
				case VIEW_WOMEN:
					music.play(MUSIC_ABORT);
					eraseAlt();
					movie.loadmovie("abort.cmv");
					movie.playmovie(0, 0);
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(19, 13, "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป");
					mvaddstrAlt(20, 13, "บ     A  failed partial  birth abortion  goes on a   บ");
					mvaddstrAlt(21, 13, "บ   popular  afternoon  talk  show.    The  studio   บ");
					mvaddstrAlt(22, 13, "บ   audience and viewers nationwide feel its pain.   บ");
					mvaddstrAlt(23, 13, "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
					getkeyAlt();
					del = 1;
					break;
				}
			}
		}
		if (del) delete_and_remove(newsstory, n);
	}
}
string getLastNameForHeadline(char* fullName)
{
	int i = 0;
	int j = -1;
	char lastName[20];
	// Parse through full name to get the last name
	for (i = 0; fullName[i] != 0; i++)
	{
		// Start recording last name at the space between first and last
		if (fullName[i] == ' ')
		{
			j = 0;
		}
		// When recording last name, transcribe in uppercase
		else if (j >= 0)
		{
			lastName[j++] = toupper(fullName[i]);
		}
	}
	lastName[j] = 0; // To finish, NULL terminate the transcribed string
					 // Write to string
	string ret = lastName;
	return ret;
}
void displaystoryheader(newsstoryst& ns, bool liberalguardian, int& y, int header)
{
	switch (ns.type)
	{
	case NEWSSTORY_PRESIDENT_IMPEACHED:
		displaycenterednewsfont(getLastNameForHeadline(oldPresidentName), 5);
		displaycenterednewsfont("IMPEACHED", 13);
		break;
	case NEWSSTORY_PRESIDENT_BELIEVED_DEAD:
		displaycenterednewsfont(getLastNameForHeadline(oldPresidentName), 5);
		displaycenterednewsfont("BELIEVED DEAD", 13);
		break;
	case NEWSSTORY_PRESIDENT_FOUND_DEAD:
		displaycenterednewsfont(getLastNameForHeadline(oldPresidentName), 5);
		displaycenterednewsfont("FOUND DEAD", 13);
		break;
	case NEWSSTORY_PRESIDENT_FOUND:
		displaycenterednewsfont(getLastNameForHeadline(oldPresidentName), 5);
		displaycenterednewsfont("RESCUED", 13);
		break;
	case NEWSSTORY_PRESIDENT_KIDNAPPED:
		displaycenterednewsfont(getLastNameForHeadline(oldPresidentName), 5);
		displaycenterednewsfont("KIDNAPPED", 13);
		break;
	case NEWSSTORY_PRESIDENT_MISSING:
		displaycenterednewsfont(getLastNameForHeadline(oldPresidentName), 5);
		displaycenterednewsfont("MISSING", 13);
		break;
	case NEWSSTORY_PRESIDENT_ASSASSINATED:
		displaycenterednewsfont(getLastNameForHeadline(oldPresidentName), 5);
		displaycenterednewsfont("ASSASSINATED", 13);
		break;
	case NEWSSTORY_CCS_NOBACKERS:
		displaycenterednewsfont("FBI HUNTS CCS", 5);
		y = 13;
		break;
	case NEWSSTORY_CCS_DEFEATED:
		displaycenterednewsfont("RAIDS END CCS", 5);
		y = 13;
		break;
	case NEWSSTORY_NUDITYARREST:
	case NEWSSTORY_CARTHEFT:
	case NEWSSTORY_WANTEDARREST:
	case NEWSSTORY_DRUGARREST:
	case NEWSSTORY_GRAFFITIARREST:
	case NEWSSTORY_BURIALARREST:
		displaycenterednewsfont("POLICE KILLED", 5);
		y = 13;
		break;
	case NEWSSTORY_SQUAD_ESCAPED:
	case NEWSSTORY_SQUAD_FLEDATTACK:
		displaycenterednewsfont("LCS ESCAPES", 5);
		displaycenterednewsfont("POLICE SIEGE", 13);
		break;
	case NEWSSTORY_SQUAD_DEFENDED:
	case NEWSSTORY_SQUAD_BROKESIEGE:
		displaycenterednewsfont("LCS FIGHTS", 5);
		displaycenterednewsfont("OFF COPS", 13);
		break;
	case NEWSSTORY_SQUAD_KILLED_SIEGEATTACK:
	case NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE:
		if (!liberalguardian)
		{
			displaycenterednewsfont("LCS SIEGE", 5);
			displaycenterednewsfont("TRAGIC END", 13);
		}
		else
		{
			displaycenterednewsfont("POLICE KILL", 5);
			displaycenterednewsfont("LCS MARTYRS", 13);
		}
		break;
	case NEWSSTORY_CCS_SITE:
	case NEWSSTORY_CCS_KILLED_SITE:
		if (newscherrybusted<2)
		{
			displaycenterednewsfont("CONSERVATIVE", 5);
			displaycenterednewsfont("CRIME SQUAD", 13);
		}
		else
		{
			if (ns.positive)
				displaycenterednewsfont("CCS STRIKES", 5);//AGAIN?
			else
				displaycenterednewsfont("CCS RAMPAGE", 5);
			y = 13;
		}
		break;
	default:
		if (ns.positive)
		{
			if (newscherrybusted || liberalguardian)
			{
				if (!liberalguardian)
				{
					if (ns.priority>250)
					{
						y = 13;
						displaycenterednewsfont("UNSTOPPABLE", 5);
					}
					else
					{
						y = 13;
						displaycenterednewsfont("LCS STRIKES", 5);
					}
				}
				else
				{
					y = 13;
					if (ns.priority>150)
					{
						change_public_opinion(header, 5, 1); // Bonus for big story
						switch (header)
						{
						case VIEW_TAXES:
						case VIEW_SWEATSHOPS:
						case VIEW_CEOSALARY:
							displaycenterednewsfont("CLASS WAR", 5);
							break;
						case VIEW_NUCLEARPOWER:
							displaycenterednewsfont("MELTDOWN RISK", 5);
							break;
						case VIEW_POLICEBEHAVIOR:
							displaycenterednewsfont("LCS VS COPS", 5);
							break;
						case VIEW_DEATHPENALTY:
							displaycenterednewsfont("PRISON WAR", 5);
							break;
						case VIEW_INTELLIGENCE:
							displaycenterednewsfont("LCS VS CIA", 5);
							break;
						case VIEW_ANIMALRESEARCH:
						case VIEW_GENETICS:
							displaycenterednewsfont("EVIL RESEARCH", 5);
							break;
						case VIEW_FREESPEECH:
						case VIEW_GAY:
						case VIEW_JUSTICES:
							displaycenterednewsfont("NO JUSTICE", 5);
							break;
						case VIEW_POLLUTION:
							displaycenterednewsfont("POLLUTER HIT", 5);
							break;
						case VIEW_CORPORATECULTURE:
							displaycenterednewsfont("LCS HITS CORP", 5);
							break;
						case VIEW_AMRADIO:
							displaycenterednewsfont("LCS HITS AM", 5);
							break;
						case VIEW_CABLENEWS:
							displaycenterednewsfont("LCS HITS TV", 5);
							break;
						default:
							displaycenterednewsfont("HEROIC STRIKE", 5);
						}
					}
					else
					{
						displaycenterednewsfont("LCS STRIKES", 5);
					}
				}
			}
			else
			{
				displaycenterednewsfont("LIBERAL CRIME", 5);
				displaycenterednewsfont("SQUAD STRIKES", 13);
			}
		}
		else
		{
			if (newscherrybusted || liberalguardian)
			{
				if (!liberalguardian)
					displaycenterednewsfont("LCS RAMPAGE", 5);
				else
					displaycenterednewsfont("LCS SORRY", 5);
				y = 13;
			}
			else
			{
				displaycenterednewsfont("LIBERAL CRIME", 5);
				displaycenterednewsfont("SQUAD RAMPAGE", 13);
			}
		}
		break;
	}
}


void handle_public_opinion_impact(const newsstoryst &ns)
{
	// Check if this function is meant to handle public opinion impact
	// for this type of news story (primarily deals with squad/site actions)
	int okay_types[] = { NEWSSTORY_SQUAD_SITE, NEWSSTORY_SQUAD_ESCAPED, NEWSSTORY_SQUAD_FLEDATTACK,
		NEWSSTORY_SQUAD_DEFENDED, NEWSSTORY_SQUAD_BROKESIEGE, NEWSSTORY_SQUAD_KILLED_SIEGEATTACK,
		NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE, NEWSSTORY_SQUAD_KILLED_SITE, NEWSSTORY_WANTEDARREST,
		NEWSSTORY_GRAFFITIARREST, NEWSSTORY_CCS_SITE, NEWSSTORY_CCS_KILLED_SITE };
	int okay_type_num = len(okay_types);
	int i;
	for (i = 0; i < okay_type_num; i++)
	{
		if (okay_types[i] == ns.type)
			break;
	}
	if (i == okay_type_num) return; // No impact for this news story type
	int impact = ns.priority;
	// Magnitude of impact will be affected by which page of the newspaper the story appears on
	if (ns.page == 1) impact *= 5;
	else if (ns.page == 2) impact *= 3;
	else if (ns.page == 3) impact *= 2;
	int maxpower = 1;
	if (ns.page == 1) maxpower = 100;
	else if (ns.page < 5) maxpower = 100 - 10 * ns.page;
	else if (ns.page < 10) maxpower = 40;
	else if (ns.page < 20) maxpower = 20;
	else if (ns.page < 30) maxpower = 10;
	else if (ns.page < 40) maxpower = 5;
	else maxpower = 1;
	// Five times effectiveness with the Liberal Guardian
	if (ns.positive == 2)
		impact *= 5;
	// Cap power
	if (impact > maxpower)
		impact = maxpower;
	impact /= 10;
	impact++;
	// Account for squad responsible, rampages, and Liberal Guardian bias
	int impact_direction = ALIGN_LIBERAL;
	if (ns.type == NEWSSTORY_CCS_SITE || ns.type == NEWSSTORY_CCS_KILLED_SITE)
	{
		impact_direction = ALIGN_CONSERVATIVE;
		if (ns.positive)
			change_public_opinion(VIEW_CONSERVATIVECRIMESQUAD, impact, 0);
		else
			change_public_opinion(VIEW_CONSERVATIVECRIMESQUAD, -impact, 0);
	}
	else
	{
		change_public_opinion(VIEW_LIBERALCRIMESQUAD, 2 + impact);
		impact_direction = ALIGN_LIBERAL;
		if (ns.positive)
			change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, impact);
		else
			change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, -impact);
	}
	impact *= impact_direction;
	int squad_responsible = impact_direction;
	if (!ns.positive) impact /= 4;
	// Impact gun control issue
	change_public_opinion(VIEW_GUNCONTROL, abs(impact) / 10, 0, abs(impact) * 10);
	if (ns.loc == -1) return;
	// Location-specific issue impact
	std::vector<int> issues;
	switch (LocationsPool::getInstance().getLocationType(ns.loc))
	{
	case SITE_LABORATORY_COSMETICS:
		issues.push_back(VIEW_ANIMALRESEARCH);
		issues.push_back(VIEW_WOMEN);
		break;
	case SITE_LABORATORY_GENETIC:
		issues.push_back(VIEW_ANIMALRESEARCH);
		issues.push_back(VIEW_GENETICS);
		break;
	case SITE_GOVERNMENT_POLICESTATION:
		issues.push_back(VIEW_POLICEBEHAVIOR);
		issues.push_back(VIEW_PRISONS);
		issues.push_back(VIEW_DRUGS);
		break;
	case SITE_GOVERNMENT_COURTHOUSE:
		issues.push_back(VIEW_DEATHPENALTY);
		issues.push_back(VIEW_JUSTICES);
		issues.push_back(VIEW_FREESPEECH);
		issues.push_back(VIEW_GAY);
		issues.push_back(VIEW_WOMEN);
		issues.push_back(VIEW_CIVILRIGHTS);
		break;
	case SITE_GOVERNMENT_PRISON:
		issues.push_back(VIEW_DEATHPENALTY);
		issues.push_back(VIEW_DRUGS);
		issues.push_back(VIEW_TORTURE);
		issues.push_back(VIEW_PRISONS);
		break;
	case SITE_GOVERNMENT_ARMYBASE:
		issues.push_back(VIEW_TORTURE);
		issues.push_back(VIEW_MILITARY);
		break;
	case SITE_GOVERNMENT_WHITE_HOUSE:
		break;
	case SITE_GOVERNMENT_INTELLIGENCEHQ:
		issues.push_back(VIEW_INTELLIGENCE);
		issues.push_back(VIEW_TORTURE);
		issues.push_back(VIEW_PRISONS);
		break;
	case SITE_INDUSTRY_SWEATSHOP:
		issues.push_back(VIEW_SWEATSHOPS);
		issues.push_back(VIEW_IMMIGRATION);
		break;
	case SITE_INDUSTRY_POLLUTER:
		issues.push_back(VIEW_SWEATSHOPS);
		issues.push_back(VIEW_POLLUTION);
		break;
	case SITE_INDUSTRY_NUCLEAR:
		issues.push_back(VIEW_NUCLEARPOWER);
		break;
	case SITE_CORPORATE_HEADQUARTERS:
		issues.push_back(VIEW_TAXES);
		issues.push_back(VIEW_CORPORATECULTURE);
		issues.push_back(VIEW_WOMEN);
		break;
	case SITE_CORPORATE_HOUSE:
		issues.push_back(VIEW_TAXES);
		issues.push_back(VIEW_CEOSALARY);
		break;
	case SITE_MEDIA_AMRADIO:
		issues.push_back(VIEW_AMRADIO);
		issues.push_back(VIEW_FREESPEECH);
		issues.push_back(VIEW_GAY);
		issues.push_back(VIEW_WOMEN);
		issues.push_back(VIEW_CIVILRIGHTS);
		break;
	case SITE_MEDIA_CABLENEWS:
		issues.push_back(VIEW_CABLENEWS);
		issues.push_back(VIEW_FREESPEECH);
		issues.push_back(VIEW_GAY);
		issues.push_back(VIEW_WOMEN);
		issues.push_back(VIEW_CIVILRIGHTS);
		break;
	case SITE_RESIDENTIAL_APARTMENT_UPSCALE:
		issues.push_back(VIEW_TAXES);
		issues.push_back(VIEW_CEOSALARY);
		issues.push_back(VIEW_GUNCONTROL);
		break;
	case SITE_BUSINESS_CIGARBAR:
		issues.push_back(VIEW_TAXES);
		issues.push_back(VIEW_CEOSALARY);
		issues.push_back(VIEW_WOMEN);
		break;
	case SITE_BUSINESS_BANK:
		issues.push_back(VIEW_TAXES);
		issues.push_back(VIEW_CEOSALARY);
		issues.push_back(VIEW_CORPORATECULTURE);
		break;
	}
	for (i = 0; i < len(issues); i++)
		change_public_opinion(issues[i], impact, squad_responsible, impact * 10);
}

/* news - graphics */
void loadgraphics()
{
	int picnum, dimx, dimy;
	FILE *h;
	if ((h = LCSOpenFile("largecap.cpc", "rb", LCSIO_PRE_ART)) != NULL)
	{
		fread(&picnum, sizeof(int), 1, h);
		fread(&dimx, sizeof(int), 1, h);
		fread(&dimy, sizeof(int), 1, h);
		for (int p = 0; p < picnum; p++)
			for (int x = 0; x < dimx; x++)
				for (int y = 0; y < dimy; y++)
					fread(&bigletters[p][x][y][0], sizeof(char), 4, h);
		LCSCloseFile(h);
	}
	if ((h = LCSOpenFile("newstops.cpc", "rb", LCSIO_PRE_ART)) != NULL)
	{
		fread(&picnum, sizeof(int), 1, h);
		fread(&dimx, sizeof(int), 1, h);
		fread(&dimy, sizeof(int), 1, h);
		for (int p = 0; p < picnum; p++)
			for (int x = 0; x < dimx; x++)
				for (int y = 0; y < dimy; y++)
					fread(&newstops[p][x][y][0], sizeof(char), 4, h);
		LCSCloseFile(h);
	}
	if ((h = LCSOpenFile("newspic.cpc", "rb", LCSIO_PRE_ART)) != NULL)
	{
		fread(&picnum, sizeof(int), 1, h);
		fread(&dimx, sizeof(int), 1, h);
		fread(&dimy, sizeof(int), 1, h);
		for (int p = 0; p < picnum; p++)
			for (int x = 0; x < dimx; x++)
				for (int y = 0; y < dimy; y++)
					fread(&newspic[p][x][y][0], sizeof(char), 4, h);
		LCSCloseFile(h);
	}
}

void displaycenteredsmallnews(const std::string& str, int y)
{
	set_color_easy(BLACK_ON_WHITE);
	mvaddstrCenter(y, str);
}
void displaynewspicture(int p, int y)
{
	for (int x2 = 0; x2 < 78; x2++)
		for (int y2 = 0; y2 < 15; y2++)
		{
			if (y + y2 > 24) break;
			set_color((newspic[p][x2][y2][1]),
				(newspic[p][x2][y2][2]),
				newspic[p][x2][y2][3]);
			moveAlt(y + y2, 1 + x2);
			addcharAlt(newspic[p][x2][y2][0]);
		}
}


void displaymajoreventstory(newsstoryst& ns, char* story, const short* storyx_s, const short* storyx_e)
{
	if (ns.positive)
	{
		switch (ns.view)
		{
		case VIEW_WOMEN:
			displaycenterednewsfont("CLINIC MURDER", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
		case VIEW_GAY:
			displaycenterednewsfont("CRIME OF HATE", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
		case VIEW_DEATHPENALTY:
			displaycenterednewsfont("JUSTICE DEAD", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
			/*
			case VIEW_MILITARY:
			displaycenterednewsfont("CASUALTIES MOUNT",5);
			displaycenteredsmallnews("Is the latest military invasion yet another quagmire?",12);
			strcpy(story,"");
			generatefiller(story,200);
			displaynewsstory(story,storyx_s,storyx_e,13);
			break;
			*/
			/*
			case VIEW_POLITICALVIOLENCE:
			displaycenterednewsfont("NIGHTMARE",5);
			constructeventstory(story,ns.view,ns.positive);
			generatefiller(story,200);
			displaynewsstory(story,storyx_s,storyx_e,13);
			break;
			*/
		case VIEW_GUNCONTROL:
			displaycenterednewsfont("MASS SHOOTING", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
		case VIEW_TAXES:
		{
			displaycenterednewsfont("REAGAN FLAWED", 5);//XXX: "Reagan was wrong" or something?
			char str[80];
			strcpy(str, "");
			strcat(str, pickrandom(reagan_bad));
			strcat(str, singleSpace);
			strcat(str, pickrandom(reagan_bad_2));
			strcat(str, ": A new book further documenting the other side of Reagan.");
			displaycenteredsmallnews(str, 12);
			displaynewspicture(PICTURE_BOOK, 13);
			break;
		}
		case VIEW_NUCLEARPOWER:
			displaycenterednewsfont("MELTDOWN", 5);
			displaycenteredsmallnews("A nuclear power plant suffers a catastrophic meltdown.", 12);
			displaynewspicture(PICTURE_MELTDOWN, 13);
			break;
		case VIEW_ANIMALRESEARCH:
			displaycenterednewsfont("HELL ON EARTH", 5);
			displaycenteredsmallnews("A mutant animal has escaped from a lab and killed thirty people.", 12);
			displaynewspicture(PICTURE_MUTANT_BEAST, 13);
			break;
		case VIEW_PRISONS:
			displaycenterednewsfont("ON THE INSIDE", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
		case VIEW_INTELLIGENCE:
			displaycenterednewsfont("THE FBI FILES", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
		case VIEW_FREESPEECH:
			displaycenterednewsfont("BOOK BANNED", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
		case VIEW_GENETICS:
			displaycenterednewsfont("KILLER FOOD", 5);
			displaycenteredsmallnews("Over a hundred people become sick from genetically modified food.", 12);
			displaynewspicture(PICTURE_GENETICS, 13);
			break;
		case VIEW_JUSTICES:
			displaycenterednewsfont("IN CONTEMPT", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
		case VIEW_SWEATSHOPS:
			displaycenterednewsfont("CHILD'S PLEA", 5);
			displaycenteredsmallnews("A T-shirt in a store is found scrawled with a message from a sweatshop worker.", 12);
			displaynewspicture(PICTURE_TSHIRT, 13);
			break;
		case VIEW_POLLUTION:
			displaycenterednewsfont("RING OF FIRE", 5);
			displaycenteredsmallnews("The Ohio River caught on fire again.", 12);
			displaynewspicture(PICTURE_RIVERFIRE, 13);
			break;
		case VIEW_CORPORATECULTURE:
			displaycenterednewsfont("BELLY UP", 5);
			displaycenteredsmallnews("An enormous company files for bankruptcy, shattering the previous record.", 12);// random company name
			displaynewspicture(PICTURE_DOLLARS, 13);
			break;
		case VIEW_CEOSALARY:
		{
			displaycenterednewsfont("AMERICAN CEO", 5);
			char str[80];
			strcpy(str, "This major CEO ");
			switch (LCSrandom(ceo_behaving_badly.size()))
			{
				//TODO IsaacG Migrate Strings
			case 0:
				if (lawList[LAW_FREESPEECH] == -2 && lawList[LAW_WOMEN] != -2)strcat(str, "regularly visits [working women].");
				else if (lawList[LAW_FREESPEECH] == -2 && lawList[LAW_WOMEN] == -2)strcat(str, "regularly [donates to sperm banks].");
				else strcat(str, "regularly visits prostitutes.");
				break;
			default:
				strcat(str, pickrandom(ceo_behaving_badly));
			}
			displaycenteredsmallnews(str, 12);
			displaynewspicture(PICTURE_CEO, 13);
			break;
		}
		case VIEW_AMRADIO:
			displaycenterednewsfont("AM IMPLOSION", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
		}
	}
	else
	{
		switch (ns.view)
		{
		case VIEW_GAY:
			displaycenterednewsfont("KINKY WINKY", 5);
			displaycenteredsmallnews("Jerry Falwell explains the truth about Tinky Winky.  Again.", 12);
			displaynewspicture(PICTURE_TINKYWINKY, 13);
			break;
		case VIEW_DEATHPENALTY:
			displaycenterednewsfont("LET'S FRY 'EM", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
			/*
			case VIEW_MILITARY:
			displaycenterednewsfont("BIG VICTORY",5);
			displaycenteredsmallnews("Our boys defend freedom once again, defeating an evil dictator.",13);
			strcpy(story,"");
			generatefiller(story,200);
			displaynewsstory(story,storyx_s,storyx_e,15);
			break;
			*/
			/*
			case VIEW_POLITICALVIOLENCE:
			displaycenterednewsfont("END IN TEARS",5);
			constructeventstory(story,ns.view,ns.positive);
			generatefiller(story,200);
			displaynewsstory(story,storyx_s,storyx_e,13);
			break;
			*/
		case VIEW_GUNCONTROL:
			displaycenterednewsfont("ARMED CITIZEN", 5);
			displaycenterednewsfont("SAVES LIVES", 13);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 21);
			break;
		case VIEW_TAXES:
		{
			displaycenterednewsfont("REAGAN THE MAN", 5);
			char str[80];
			strcpy(str, "");
			strcat(str, pickrandom(reagan_good));
			strcat(str, singleSpace);
			strcat(str, pickrandom(reagan_good_2));
			strcat(str, ": A new book lauding Reagan and the greatest generation.");
			displaycenteredsmallnews(str, 12);
			displaynewspicture(PICTURE_BOOK, 13);
			break;
		}
		case VIEW_NUCLEARPOWER:
			displaycenterednewsfont("OIL CRUNCH", 5);
			displaycenteredsmallnews("OPEC cuts oil production sharply in response to a US foreign policy decision.", 12);
			displaynewspicture(PICTURE_OIL, 13);
			break;
		case VIEW_ANIMALRESEARCH:
			displaycenterednewsfont("APE EXPLORERS", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
		case VIEW_POLICEBEHAVIOR:
			if (lawList[LAW_FREESPEECH] == -2)displaycenterednewsfont("[JERKS]", 5);
			else displaycenterednewsfont("BASTARDS", 5);
			displaynewspicture(PICTURE_TERRORISTS, 13);
			break;
		case VIEW_PRISONS:
			displaycenterednewsfont("HOSTAGE SLAIN", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
		case VIEW_INTELLIGENCE:
			displaycenterednewsfont("DODGED BULLET", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
		case VIEW_FREESPEECH:
			displaycenterednewsfont("HATE RALLY", 5);
			displaycenteredsmallnews("Free speech advocates fight hard to let a white supremacist rally take place.", 12);
			displaynewspicture(PICTURE_KKK, 13);
			break;
		case VIEW_GENETICS:
			displaycenterednewsfont("GM FOOD FAIRE", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
		case VIEW_JUSTICES:
			displaycenterednewsfont("JUSTICE AMOK", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
		case VIEW_SWEATSHOPS:
			displaycenterednewsfont("THEY ARE HERE", 5);
			if (month >= 8 && month <= 11)displaycenteredsmallnews("Fall fashions hit the stores across the country.", 12);
			else displaycenteredsmallnews("Fall fashions are previewed in stores across the country.", 12);
			displaynewspicture(PICTURE_TSHIRT, 13);
			break;
		case VIEW_POLLUTION:
			displaycenterednewsfont("LOOKING UP", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
		case VIEW_CORPORATECULTURE:
			displaycenterednewsfont("NEW JOBS", 5);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 13);
			break;
		case VIEW_AMRADIO:
			displaycenterednewsfont("THE DEATH", 5);
			displaycenterednewsfont("OF CULTURE", 13);
			constructeventstory(story, ns.view, ns.positive);
			displaynewsstory(story, storyx_s, storyx_e, 21);
			break;
		}
	}
}
void displaystory(newsstoryst &ns, bool liberalguardian, int header)
{
	music.play(MUSIC_NEWSPAPER);
	int it2;
	preparepage(ns, liberalguardian);
	char story[5000];
	short storyx_s[25];
	short storyx_e[25];
	for (it2 = 0; it2 < 25; it2++) storyx_s[it2] = 1;
	for (it2 = 0; it2 < 25; it2++) storyx_e[it2] = 78;
	displayads(ns, liberalguardian, storyx_s, storyx_e, it2);
	const char *city;
	if (multipleCityMode && ns.loc != -1)
	{
		Location * ns_site = find_site_in_city(LocationsPool::getInstance().getLocationCity(ns.loc), -1);
		if (cityNames.count(ns_site->type) > 0) {
			city = cityNames[ns_site->type].data();
		}
		else {
			city = lcityname;
		}
	}
	else city = lcityname;
	switch (ns.type)
	{
	case NEWSSTORY_MAJOREVENT:
		displaymajoreventstory(ns, story, storyx_s, storyx_e);
		break;
	case NEWSSTORY_CCS_NOBACKERS:
	case NEWSSTORY_CCS_DEFEATED:
	case NEWSSTORY_SQUAD_SITE:
	case NEWSSTORY_SQUAD_ESCAPED:
	case NEWSSTORY_SQUAD_FLEDATTACK:
	case NEWSSTORY_SQUAD_DEFENDED:
	case NEWSSTORY_SQUAD_BROKESIEGE:
	case NEWSSTORY_SQUAD_KILLED_SIEGEATTACK:
	case NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE:
	case NEWSSTORY_SQUAD_KILLED_SITE:
	case NEWSSTORY_CCS_SITE:
	case NEWSSTORY_CCS_KILLED_SITE:
	case NEWSSTORY_CARTHEFT:
	case NEWSSTORY_NUDITYARREST:
	case NEWSSTORY_WANTEDARREST:
	case NEWSSTORY_DRUGARREST:
	case NEWSSTORY_GRAFFITIARREST:
	case NEWSSTORY_BURIALARREST:
	{
		int y = 2;
		if ((!liberalguardian&&ns.page == 1) || (liberalguardian&&ns.guardianpage == 1))
		{
			y = 21;
			displaystoryheader(ns, liberalguardian, y, header);
		}
		strcpy(story, city);
		strcat(story, spaceDashSpace);
		switch (ns.type)
		{
		case NEWSSTORY_CCS_NOBACKERS:
			for (string s : caseNEWSSTORY_CCS_NOBACKERS) {
				strcat(story, s);
			}
			break;
		case NEWSSTORY_CCS_DEFEATED:
			for (string s : caseNEWSSTORY_CCS_DEFEATED) {
				strcat(story, s);
			}
			break;
		case NEWSSTORY_WANTEDARREST:
		case NEWSSTORY_GRAFFITIARREST:
		{
			int crime[CRIMENUM];
			std::memset(crime, 0, sizeof(int)*CRIMENUM);
			for (int c = 0; c < len(ns.crime); c++)
				crime[ns.crime[c]]++;
			if (crime[CRIME_KILLEDSOMEBODY] > 1)
			{
				if (crime[CRIME_KILLEDSOMEBODY] == 2)
					strcat(story, "Two");
				else
					strcat(story, "Several");
				strcat(story, " police officers were");
			}
			else strcat(story, "A police officer was");
			strcat(story, " killed in the line of duty yesterday, ");
			strcat(story, "according to a spokesperson from the police department.");
			strcat(story, ampersandR);
			strcat(story, "  A suspect, identified only as a member of the ");
			strcat(story, "radical political group known as the Liberal Crime Squad, is believed to have killed ");
			if (crime[CRIME_KILLEDSOMEBODY] > 1)
			{
				strcat(story, crime[CRIME_KILLEDSOMEBODY]);
				strcat(story, " officers ");
			}
			else strcat(story, "the police officer ");
			strcat(story, " while they were attempting to perform an arrest.  ");
			strcat(story, "The names of the officers have not been released pending notification of their families.");
			strcat(story, ampersandR);
			break;
		}
		case NEWSSTORY_NUDITYARREST:
		case NEWSSTORY_CARTHEFT:
		case NEWSSTORY_DRUGARREST:
		case NEWSSTORY_BURIALARREST:
		{
			int crime[CRIMENUM];
			std::memset(crime, 0, sizeof(int)*CRIMENUM);
			for (int c = 0; c < len(ns.crime); c++)
				crime[ns.crime[c]]++;
			strcat(story, "A routine arrest went horribly wrong yesterday, ");
			strcat(story, "according to a spokesperson from the police department.");
			strcat(story, ampersandR);
			strcat(story, "  A suspect, whose identity is unclear, ");
			strcat(story, "killed ");
			if (crime[CRIME_KILLEDSOMEBODY] > 1)
			{
				strcat(story, crime[CRIME_KILLEDSOMEBODY]);
				strcat(story, " police officers that were");
			}
			else strcat(story, "a police officer that was");
			strcat(story, " attempting to perform an arrest.  ");
			if (ns.type == NEWSSTORY_NUDITYARREST)
				strcat(story, "The incident apparently occurred as a response to a public nudity complaint.  ");
			else if (ns.type == NEWSSTORY_DRUGARREST)
				strcat(story, "The suspect was allegedly selling \"pot brownies\".  ");
			else if (ns.type == NEWSSTORY_BURIALARREST)
			{
				strcat(story, "A passerby allegedly called the authorities after seeing the suspect dragging what ");
				strcat(story, "appeared to be a corpse through an empty lot.  ");
			}
			else
				strcat(story, "A passerby had allegedly spotted the suspect committing a car theft.  ");
			if (crime[CRIME_KILLEDSOMEBODY] > 1)
				strcat(story, "The names of the officers have not been released pending notification of their families.");
			else strcat(story, "The name of the officer has not been released pending notification of the officer's family.");
			strcat(story, ampersandR);
			break;
		}
		case NEWSSTORY_SQUAD_ESCAPED:
		case NEWSSTORY_SQUAD_FLEDATTACK:
		case NEWSSTORY_SQUAD_DEFENDED:
		case NEWSSTORY_SQUAD_BROKESIEGE:
		case NEWSSTORY_SQUAD_KILLED_SIEGEATTACK:
		case NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE:
			strcat(story, membersOfLCS);
			if (!liberalguardian) {
				strcat(story, newsStories[ns.type][0]);
				strcat(story, policeSpokesperson);
			}
			else
			{
				strcat(story, newsStories[ns.type][len(newsStories[ns.type]) - 1]);
				strcat(story, lcsSpokeseperson);
			}
			strcat(story, ampersandR);
			break;
		default:
		{
			bool ccs = 0;
			if (ns.type == NEWSSTORY_CCS_KILLED_SITE || ns.type == NEWSSTORY_CCS_SITE)ccs = 1;
			squadstory_text_opening(ns, liberalguardian, ccs, story);
			int crime[CRIMENUM];
			memset(crime, 0, sizeof(int)*CRIMENUM);
			int typesum = 0;
			for (int c = 0; c < len(ns.crime); c++)
			{
				// Count crimes of each type
				crime[ns.crime[c]]++;
				// Special crimes are described at the start or end of the article;
				// others should be recorded in the body
				if (ns.crime[c] == CRIME_HOUSE_PHOTOS) continue;
				if (ns.crime[c] == CRIME_CORP_FILES) continue;
				if (ns.crime[c] == CRIME_SHUTDOWNREACTOR) continue;
				if (ns.crime[c] == CRIME_BANKVAULTROBBERY) continue;
				if (ns.crime[c] == CRIME_BANKSTICKUP) continue;
				if (ns.crime[c] == CRIME_POLICE_LOCKUP) continue;
				if (ns.crime[c] == CRIME_COURTHOUSE_LOCKUP) continue;
				if (ns.crime[c] == CRIME_PRISON_RELEASE) continue;
				if (ns.crime[c] == CRIME_JURYTAMPERING) continue;
				if (ns.crime[c] == CRIME_HACK_INTEL) continue;
				if (ns.crime[c] == CRIME_ARMORY) continue;
				if (ns.crime[c] == CRIME_HOUSE_PHOTOS) continue;
				if (ns.crime[c] == CRIME_CORP_FILES) continue;
				if (ns.crime[c] == CRIME_CARCHASE) continue;
				if (ns.crime[c] == CRIME_CARCRASH) continue;
				if (ns.crime[c] == CRIME_FOOTCHASE) continue;
				//if(ns.crime[c]==CRIME_TAGGING) continue;
				if (crime[ns.crime[c]] == 1) typesum++;
			}
			if (crime[CRIME_SHUTDOWNREACTOR])
			{
				if (lawList[LAW_NUCLEARPOWER] == 2)
				{
					if (!liberalguardian)
					{
						strcat(story, accordingToSourcesAtScene);
						strcat(story, "the Liberal Crime Squad contaminated the state's water supply");
						strcat(story, "yesterday by tampering with equipment on the site.");
						strcat(story, ampersandR);
					}
					else
					{
						strcat(story, "  The Liberal Crime Squad tampered with the state's water supply yesterday, ");
						strcat(story, "demonstrating the extreme dangers of Nuclear Waste. ");
						strcat(story, ampersandR);
					}
				}
				else
				{
					if (!liberalguardian)
					{
						strcat(story, accordingToSourcesAtScene);
						strcat(story, "the Liberal Crime Squad nearly caused a catastrophic meltdown of the nuclear ");
						strcat(story, "reactor.");
						strcat(story, ampersandR);
					}
					else
					{
						strcat(story, "  The Liberal Crime Squad brought the reactor to the verge of a nuclear meltdown, ");
						strcat(story, "demonstrating the extreme vulnerability and danger of Nuclear Power Plants. ");
						strcat(story, ampersandR);
					}
				}
			}
			if (crime[CRIME_POLICE_LOCKUP])
			{
				if (!liberalguardian)
				{
					strcat(story, accordingToSourcesAtScene);
					strcat(story, "the Liberal Crime Squad allegedly freed or attempted to free prisoners from the police lockup.");
					strcat(story, ampersandR);
				}
				else
				{
					strcat(story, "  The Liberal Crime Squad attempted to rescue innocent people from the police lockup, ");
					strcat(story, "saving them from torture and brutality at the hands of Conservative police interrogators.");
					strcat(story, ampersandR);
				}
			}
			if (crime[CRIME_BANKVAULTROBBERY])
			{
				if (!liberalguardian)
				{
					strcat(story, accordingToSourcesAtScene);
					strcat(story, "the Liberal Crime Squad opened the bank vault, which held more than $100,000 at the time.");
					strcat(story, ampersandR);
				}
				else
				{
					strcat(story, "  The Liberal Crime Squad opened the bank vault, ");
					strcat(story, "showing the triumph of Liberal ideals over Conservative economics.");
					strcat(story, ampersandR);
				}
			}
			else if (crime[CRIME_BANKSTICKUP])
			{
				if (!liberalguardian)
				{
					strcat(story, accordingToSourcesAtScene);
					strcat(story, "the Liberal Crime Squad threatened innocent bystanders in order to rob the bank vault.");
					strcat(story, ampersandR);
				}
				else
				{
					strcat(story, "  The Liberal Crime Squad demanded access to the bank vault, ");
					strcat(story, "hoping to acquire the resources to overcome evil.");
					strcat(story, ampersandR);
				}
			}
			if (crime[CRIME_COURTHOUSE_LOCKUP])
			{
				if (!liberalguardian)
				{
					strcat(story, accordingToSourcesAtScene);
					strcat(story, "the Liberal Crime Squad allegedly freed or attempted to free prisoners from the courthouse lockup.");
					strcat(story, ampersandR);
				}
				else
				{
					strcat(story, "  The Liberal Crime Squad attempted to rescue innocent people from the courthouse lockup, ");
					strcat(story, "saving them from the highly corrupt Conservative justice system.");
					strcat(story, ampersandR);
				}
			}
			if (crime[CRIME_PRISON_RELEASE])
			{
				if (!liberalguardian)
				{
					strcat(story, accordingToSourcesAtScene);
					strcat(story, "the Liberal Crime Squad allegedly freed prisoners while in the facility.");
					strcat(story, ampersandR);
				}
				else
				{
					strcat(story, "  The Liberal Crime Squad attempted to rescue innocent people from the abusive Conservative conditions ");
					strcat(story, "at the prison.");
					strcat(story, ampersandR);
				}
			}
			if (crime[CRIME_JURYTAMPERING])
			{
				if (!liberalguardian)
				{
					strcat(story, accordingToPoliceSources);
					strcat(story, "the Liberal Crime Squad allegedly violated the sacred ");
					strcat(story, "trust and attempted to influence a jury.");
					strcat(story, ampersandR);
				}
				else
				{
					strcat(story, "  The Liberal Crime Squad has apologized over reports that the operation ");
					strcat(story, "may have interfered with jury deliberations.");
					strcat(story, ampersandR);
				}
			}
			if (crime[CRIME_HACK_INTEL])
			{
				if (!liberalguardian)
				{
					strcat(story, accordingToPoliceSources);
					strcat(story, "intelligence officials seemed very nervous about something.");
					strcat(story, ampersandR);
				}
				else
				{
					strcat(story, "  Liberal Crime Squad computer specialists worked to liberate information from CIA computers.");
					strcat(story, ampersandR);
				}
			}
			if (crime[CRIME_ARMORY])
			{
				if (!liberalguardian)
				{
					strcat(story, "  According to sources, ");
					strcat(story, "the Liberal Crime Squad attempted to break into the armory.");
					strcat(story, ampersandR);
				}
				else
				{
					strcat(story, "  Liberal Crime Squad infiltration specialists worked to liberate weapons from the oppressors.");
					strcat(story, ampersandR);
				}
			}
			if (crime[CRIME_HOUSE_PHOTOS])
			{
				if (!liberalguardian)
				{
					strcat(story, accordingToPoliceSources);
					strcat(story, "the owner of the house seemed very frantic about some missing property.");
					strcat(story, ampersandR);
				}
				else
				{
					strcat(story, "  The Liberal Crime Squad was attempting to uncover the CEO's Conservative corruption.");
					strcat(story, ampersandR);
				}
			}
			if (crime[CRIME_CORP_FILES])
			{
				if (!liberalguardian)
				{
					strcat(story, accordingToPoliceSources);
					strcat(story, "executives on the scene seemed very nervous about something.");
					strcat(story, ampersandR);
				}
				else
				{
					strcat(story, "  The Liberal Crime Squad was attempting to uncover the company's Conservative corruption.");
					strcat(story, ampersandR);
				}
			}
			if (liberalguardian&&!ccs)
			{
				if (crime[CRIME_ATTACKED_MISTAKE]) typesum--;
				if (crime[CRIME_KILLEDSOMEBODY]) typesum--;
			}
			if (typesum > 0)
			{
				if (typesum > 0)
				{
					if (!ccs)
					{
						if (!liberalguardian)
						{
							strcat(story, "  Further details are sketchy, but police sources suggest that the LCS ");
							strcat(story, "engaged in ");
						}
						else
						{
							strcat(story, "  The Liberal Crime Squad ");
						}
					}
					else
					{
						strcat(story, "  Further details are sketchy, but police sources suggest that the CCS ");
						strcat(story, "engaged in ");
					}
					if (crime[CRIME_ARSON])
					{
						if (!liberalguardian || ccs)
						{
							strcat(story, "arson");
						}
						else
						{
							strcat(story, "set fire to Conservative property");
						}
						if (typesum >= 3)strcat(story, commaSpace);
						else if (typesum == 2)strcat(story, AND);
						typesum--;
					}
					if (!liberalguardian || ccs)
					{
						if (crime[CRIME_KILLEDSOMEBODY])
						{
							strcat(story, "murder");
							if (typesum >= 3)strcat(story, commaSpace);
							else if (typesum == 2)strcat(story, AND);
							typesum--;
						}
						if (crime[CRIME_ATTACKED_MISTAKE])
						{
							strcat(story, "violence");
							if (typesum >= 3)strcat(story, commaSpace);
							else if (typesum == 2)strcat(story, AND);
							typesum--;
						}
						if (crime[CRIME_ATTACKED])
						{
							if (crime[CRIME_ATTACKED_MISTAKE])strcat(story, "more violence");
							else strcat(story, "violence");
							if (typesum >= 3)strcat(story, commaSpace);
							else if (typesum == 2)strcat(story, AND);
							typesum--;
						}
					}
					else
					{
						if (crime[CRIME_ATTACKED])
						{
							strcat(story, "engaged in combat with Conservative forces");
							if (typesum >= 3)strcat(story, commaSpace);
							else if (typesum == 2)strcat(story, AND);
							typesum--;
						}
					}
					if (crime[CRIME_STOLEGROUND] || crime[CRIME_BANKTELLERROBBERY])
					{
						if (!liberalguardian || ccs)
						{
							strcat(story, "theft");
						}
						else
						{
							strcat(story, "liberated enemy resources");
						}
						if (typesum >= 3)strcat(story, commaSpace);
						else if (typesum == 2)strcat(story, AND);
						typesum--;
					}
					if (crime[CRIME_FREE_RABBITS] || crime[CRIME_FREE_BEASTS])
					{
						if (!liberalguardian)
						{
							strcat(story, "tampering with lab animals");
						}
						else
						{
							strcat(story, "liberated abused animals");
						}
						if (typesum >= 3)strcat(story, commaSpace);
						else if (typesum == 2)strcat(story, AND);
						typesum--;
					}
					if (crime[CRIME_BREAK_SWEATSHOP] || crime[CRIME_BREAK_FACTORY] || crime[CRIME_VANDALISM])
					{
						if (!liberalguardian || ccs)
						{
							strcat(story, "destruction of private property");
						}
						else
						{
							strcat(story, "damaged enemy infrastructure");
						}
						if (typesum >= 3)strcat(story, commaSpace);
						else if (typesum == 2)strcat(story, AND);
						typesum--;
					}
					if (crime[CRIME_TAGGING])
					{
						if (!liberalguardian || ccs)
						{
							strcat(story, "vandalism");
						}
						else
						{
							strcat(story, "marked the site for Liberation");
						}
						if (typesum >= 3)strcat(story, commaSpace);
						else if (typesum == 2)strcat(story, AND);
						typesum--;
					}
					if (crime[CRIME_BROKEDOWNDOOR])
					{
						if (!liberalguardian || ccs)
						{
							strcat(story, "breaking and entering");
						}
						else
						{
							strcat(story, "broke down doors");
						}
						if (typesum >= 3)strcat(story, commaSpace);
						else if (typesum == 2)strcat(story, AND);
						typesum--;
					}
					if (crime[CRIME_UNLOCKEDDOOR])
					{
						if (!liberalguardian || ccs)
						{
							strcat(story, "unlawful entry");
						}
						else
						{
							strcat(story, "picked locks");
						}
						if (typesum >= 3)strcat(story, commaSpace);
						else if (typesum == 2)strcat(story, AND);
						typesum--;
					}
					strcat(story, singleDot);
				}
				strcat(story, ampersandR);
			}
			if (crime[CRIME_CARCHASE])
			{
				if (!liberalguardian || ccs)
				{
					strcat(story, "  It is known that there was a high-speed chase ");
					strcat(story, "following the incident.  ");
				}
				else
				{
					strcat(story, "  Conservative operatives engaged in a reckless ");
					strcat(story, "pursuit of the LCS.  ");
				}
				if (crime[CRIME_CARCRASH])
				{
					if (crime[CRIME_CARCRASH] > 1)
					{
						strcat(story, crime[CRIME_CARCRASH]);
						strcat(story, " vehicles crashed.  ");
					}
					else strcat(story, "One vehicle crashed.  ");
					if (!liberalguardian || ccs)
						strcat(story, "Details about injuries were not released.  ");//XXX: Why not turn them into martyrs?
				}
				if (crime[CRIME_FOOTCHASE])
				{
					if (!liberalguardian || ccs)
						strcat(story, "There was also a foot chase when the suspect or suspects bailed out after the high-speed pursuit.  ");
					else
						strcat(story, "The Liberal Crime Squad ended the dangerous high-speed chase in order to protect the public, and attempted to escape on foot.  ");
				}
				strcat(story, ampersandR);
			}
			if (!ccs)
			{
				if (!LCSrandom(8))
				{
					if (crime[CRIME_TAGGING])
					{
						strcat(story, "  The slogan, \"");
						strcat(story, slogan);
						strcat(story, "\" was found painted on the walls.");
					}
					else
					{
						switch (LCSrandom(3))
						{
						case 0:
							if (ns.type == NEWSSTORY_SQUAD_KILLED_SITE)
							{
								strcat(story, "  One uttered the words, \"");
								strcat(story, slogan);
								strcat(story, "\" before passing out.");
							}
							else
							{
								strcat(story, "  As they left, they shouted, \"");
								strcat(story, slogan);
								strcat(story, "\"");
							}
							break;
						case 1:
							strcat(story, "  One of them was rumored to have cried out, \"");
							strcat(story, slogan);
							strcat(story, "\"");
							break;
						case 2:
							strcat(story, "  Witnesses reported hearing the phrase, \"");
							strcat(story, slogan);
							strcat(story, "\"");
							break;
						}
					}
					strcat(story, ampersandR);
				}
			}
			break;
		}
		}
		generatefiller(story, 200);
		displaynewsstory(story, storyx_s, storyx_e, y);
		if (!newscherrybusted)newscherrybusted = 1;
		if (ns.type == NEWSSTORY_CCS_SITE ||
			ns.type == NEWSSTORY_CCS_KILLED_SITE)newscherrybusted = 2;
		break;
	}
	case NEWSSTORY_MASSACRE:
	{
		int y = 3;
		if (ns.page == 1)
		{
			y = 21;
			if (ns.crime[0] == SIEGE_CCS)
			{
				displaycenterednewsfont("CCS MASSACRE", 5);
			}
			else if (!liberalguardian)
			{
				displaycenterednewsfont("MYSTERIOUS", 5);
				displaycenterednewsfont("MASSACRE", 13);
			}
			else
			{
				displaycenterednewsfont("CONSERVATIVE", 5);
				displaycenterednewsfont("MASSACRE", 13);
			}
		}
		strcpy(story, city);
		strcat(story, spaceDashSpace);
		if (ns.crime[1] > 2)
		{
			strcat(story, ns.crime[1]);
			strcat(story, " bodies were "); //Gruesome pile, large pile.
		}
		else if (ns.crime[1] > 1)strcat(story, " Two bodies were ");
		else strcat(story, " A body was ");
		strcat(story, " found in the ");
		strcat(story, LocationsPool::getInstance().getLocationName(ns.loc));
		strcat(story, " yesterday.");
		if (!liberalguardian)
		{
			strcat(story, "  According to a spokesperson for ");
			strcat(story, "the police department, the matter is under investigation as a homicide.");
			strcat(story, ampersandR);
			strcat(story, "  Privately, sources in the department confide that there aren't any leads.  ");
			strcat(story, "According to one person familiar with the case, \"");
		}
		else
		{
			strcat(story, "  The police have opened an investigation into the massacre, but seem ");
			strcat(story, "unwilling to pursue the case with any serious effort.");
			strcat(story, ampersandR);
			strcat(story, "  The Liberal Crime Squad has claimed that the ");
			if (ns.crime[1] > 1)strcat(story, "victims were members ");
			else strcat(story, "victim was a member ");
			strcat(story, "of the LCS targeted simply due to their political beliefs.  ");
			strcat(story, "According to an LCS spokesperson, \"");
		}
		switch (ns.crime[0])
		{
		case SIEGE_CIA:
			if (!liberalguardian)
			{
				if (ns.crime[1] > 1)strcat(story, "The bodies had no faces or ");
				else strcat(story, "The body had no face or ");
				strcat(story, "fingerprints.  Like, it was all smooth.  ");
				if (lawList[LAW_FREESPEECH] == -2)strcat(story, "[Craziest] thing I've ever seen");
				else if (lawList[LAW_FREESPEECH] == 2)strcat(story, "Damnedest thing I've ever seen");
				else strcat(story, "D*mnd*st thing I've ever seen");
			}
			else
			{
				strcat(story, "We have strong evidence that this was an extra-judicial slaughter ");
				strcat(story, "carried out by the Central Intelligence Agency in retaliation for our ");
				strcat(story, "previous actions to uncover human rights abuses and corruption in the ");
				strcat(story, "intelligence community");
			}
			break;
		case SIEGE_POLICE:
		case SIEGE_HICKS:
			if (!liberalguardian)
			{
				strcat(story, "Burned...  stabbed with, maybe, pitchforks.  There may have ");
				strcat(story, "been bite marks.  Nothing recognizable left.  Complete carnage.");
			}
			else
			{
				strcat(story, "We have reason to believe that this brutal massacre was ");
				strcat(story, "inspired by the Conservative media's brainwashing propaganda");
			}
			break;
		case SIEGE_CORPORATE:
			if (!liberalguardian)
			{
				strcat(story, "It was execution style.  Professional.  We've got nothing");
			}
			else
			{
				strcat(story, "This massacre has the signature mark of a group of mercenaries ");
				strcat(story, "known to work with several corporations we've had confrontations ");
				strcat(story, "with in the past.  *When* the police can't figure this one out, they're ");
				strcat(story, "just covering it up");
			}
			break;
		case SIEGE_CCS:
			if (!liberalguardian)
			{
				strcat(story, "Look, it was a Conservative Crime Squad hit, that's all we know, ");
				strcat(story, "no names, no faces, not even where it happened really");
			}
			else
			{
				strcat(story, "This is the doing of the Conservative Crime Squad butchers.  ");
				strcat(story, "They have to be stopped before they kill again");
			}
			break;
		case SIEGE_FIREMEN:
			if (!liberalguardian)
			{
				if (ns.crime[1] > 1)strcat(story, "The recovered bodies were ");
				else strcat(story, "The recovered body was ");
				strcat(story, "burned unrecognizable.  ");
				strcat(story, "Scorch marks throughout the site indicate that this was no accident; ");
				strcat(story, "we are working closely with the Fire Department to track down the arsonist.  ");
				strcat(story, "Fortunately, firemen were able to respond before the fire could spread to other buildings");
			}
			else
			{
				if (ns.crime[1] > 1)strcat(story, "The murdered were reporters ");
				else strcat(story, "The murdered was a reporter ");
				strcat(story, "working for this very paper. ");
				strcat(story, "This is clearly the work of conservative butchers enforcing the prohibition on a free press");
			}
		}
		strcat(story, ".\"  ");
		strcat(story, ampersandR);
		generatefiller(story, 200);
		displaynewsstory(story, storyx_s, storyx_e, y);
		break;
	}
	case NEWSSTORY_KIDNAPREPORT:
	{
		int y = 2;
		if (ns.page == 1)
		{
			y = 21;
			if (liberalguardian)
			{
				displaycenterednewsfont("LCS DENIES", 5);
				displaycenterednewsfont("KIDNAPPING", 13); break;
			}
			else
			{
				switch (ns.cr->type)
				{
				case CREATURE_CORPORATE_CEO:
					displaycenterednewsfont("CEO", 5); break;
				case CREATURE_RADIOPERSONALITY:
					displaycenterednewsfont("RADIO HOST", 5); break;
				case CREATURE_NEWSANCHOR:
					displaycenterednewsfont("NEWS ANCHOR", 5); break;
				case CREATURE_SCIENTIST_EMINENT:
					displaycenterednewsfont("SCIENTIST", 5); break;
				case CREATURE_JUDGE_CONSERVATIVE:
					displaycenterednewsfont("JUDGE", 5); break;
				case CREATURE_COP:
				case CREATURE_GANGUNIT:
				case CREATURE_DEATHSQUAD:
					displaycenterednewsfont("COP", 5); break;
				default:
					displaycenterednewsfont("SOMEONE", 5);  break;
				}
				displaycenterednewsfont("KIDNAPPED", 13);
			}
		}
		strcpy(story, city);
		strcat(story, " - The disappearance of ");
		strcat(story, ns.cr->propername);
		strcat(story, " is now considered a kidnapping, ");
		strcat(story, "according to a police spokesperson.");
		strcat(story, ampersandR);
		char dstr[200], dstr2[200];
		strcat(story, "  ");
		generate_name(dstr, dstr2);
		strcat(story, dstr);
		strcat(story, singleSpace);
		strcat(story, dstr2);
		strcat(story, ", speaking on behalf of the police department, stated ");
		strcat(story, "\"We now believe that ");
		strcat(story, ns.cr->propername);
		strcat(story, " was taken ");
		strcat(story, ns.cr->joindays - 1);
		strcat(story, " days ago, by a person or persons as yet undetermined.  ");
		strcat(story, "We have several leads and are confident that we will ");
		strcat(story, "bring ");
		strcat(story, ns.cr->propername);
		strcat(story, " back home and bring the kidnappers to justice.  ");
		strcat(story, "As the investigation is ongoing, I cannot be more specific at this time.  ");
		strcat(story, "To the citizens, please contact the department if you have any additional information.");
		strcat(story, "\"");
		strcat(story, ampersandR);
		strcat(story, "  According to sources, ");
		strcat(story, ns.cr->propername);
		strcat(story, "'s last known location was the ");
		strcat(story, LocationsPool::getInstance().getLocationName(ns.cr->worklocation));
		strcat(story, ".  Police were seen searching the surrounding area yesterday.");
		strcat(story, ampersandR);
		generatefiller(story, 200);
		displaynewsstory(story, storyx_s, storyx_e, y);
		break;
	}
	}
	int c;
	do c = getkeyAlt(); while (c != 'x'&&c != ESC&&c != ENTER&&c != SPACEBAR);
}

void display_newspaper()
{
	int writers = CreaturePool::getInstance().liberal_guardian_writing_power();
	for (int n = 0; n < len(newsstory); n++)
	{
		bool liberalguardian = 0;
		int header = -1;
		if (writers&&newsstory[n]->type != NEWSSTORY_MAJOREVENT)
			liberalguardian = 1;
		switch (newsstory[n]->type)
		{
		case NEWSSTORY_SQUAD_SITE:
		case NEWSSTORY_SQUAD_KILLED_SITE:
			switch (LocationsPool::getInstance().getLocationType(newsstory[n]->loc))
			{
			case SITE_LABORATORY_COSMETICS:
				header = VIEW_ANIMALRESEARCH;
				break;
			case SITE_LABORATORY_GENETIC:
				header = VIEW_GENETICS;
				break;
			case SITE_GOVERNMENT_POLICESTATION:
				header = VIEW_POLICEBEHAVIOR;
				break;
			case SITE_GOVERNMENT_COURTHOUSE:
				header = VIEW_JUSTICES;
				break;
			case SITE_GOVERNMENT_PRISON:
				header = VIEW_DEATHPENALTY;
				break;
			case SITE_GOVERNMENT_INTELLIGENCEHQ:
				header = VIEW_INTELLIGENCE;
				break;
			case SITE_INDUSTRY_SWEATSHOP:
				header = VIEW_SWEATSHOPS;
				break;
			case SITE_INDUSTRY_POLLUTER:
				header = VIEW_POLLUTION;
				break;
			case SITE_INDUSTRY_NUCLEAR:
				header = VIEW_NUCLEARPOWER;
				break;
			case SITE_CORPORATE_HEADQUARTERS:
				header = VIEW_CORPORATECULTURE;
				break;
			case SITE_CORPORATE_HOUSE:
				header = VIEW_CEOSALARY;
				break;
			case SITE_MEDIA_AMRADIO:
				header = VIEW_AMRADIO;
				break;
			case SITE_MEDIA_CABLENEWS:
				header = VIEW_CABLENEWS;
				break;
			case SITE_RESIDENTIAL_APARTMENT_UPSCALE:
			case SITE_BUSINESS_CIGARBAR:
			case SITE_BUSINESS_BANK:
				header = VIEW_TAXES;
				break;
			}
			break;
		case NEWSSTORY_SQUAD_ESCAPED:
		case NEWSSTORY_SQUAD_FLEDATTACK:
		case NEWSSTORY_SQUAD_DEFENDED:
		case NEWSSTORY_SQUAD_BROKESIEGE:
		case NEWSSTORY_SQUAD_KILLED_SIEGEATTACK:
		case NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE:
			break;
		case NEWSSTORY_CCS_NOBACKERS:
		case NEWSSTORY_CCS_DEFEATED:
			break;
		}
		if (liberalguardian)
		{
			if (newsstory[n]->type == NEWSSTORY_CCS_SITE ||
				newsstory[n]->type == NEWSSTORY_CCS_KILLED_SITE)
			{
				newsstory[n]->positive = 0;
			}
			displaystory(*newsstory[n], liberalguardian, header);
			if (newsstory[n]->positive)newsstory[n]->positive += 1;
		}
		else displaystory(*newsstory[n], 0, -1);
	}
}

/* news - major newspaper reporting on lcs and other topics */
void majornewspaper(char &clearformess, char canseethings)
{
	clearformess = true;
	int n = 0;
	generate_random_event_news_stories();
	clean_up_empty_news_stories();
	if (canseethings) run_television_news_stories();
	assign_page_numbers_to_newspaper_stories();
	if (canseethings) display_newspaper();
	//DELETE STORIES
	for (n = 0; n < len(newsstory); n++)
		handle_public_opinion_impact(*newsstory[n]);
	delete_and_clear(newsstory);
}

