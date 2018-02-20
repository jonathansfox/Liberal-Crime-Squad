using namespace std;

#include <includes.h>
#include "creature/creatureEnums.h"

#include <queue>
#include <map>
#include <customMaps.h>
extern Log gamelog;
extern vector<vector<string>> pickupLines;
extern vector<vector<string>> no_free_speech_flirt;
extern vector<vector<string>> lovingly_talk_to_mutant;
extern vector<vector<string>> normal_talk_to_mutant;
extern vector<vector<string>> lovingly_talk_to_dog;
extern vector<vector<string>> normal_talk_to_dog;
extern vector<vector<string>> real_quote;
extern vector<string> escape_running;
extern vector<string> escape_crawling;
extern vector<string> judge_debate;
extern vector<string> conservative_ceo_debate;
extern vector<string> other_ceo_debate;
extern vector<string> conservative_politician_debate;
extern vector<string> other_politician_debate;
extern vector<string> media_debate;
extern vector<string> military_debate;
extern vector<string> police_debate;
extern vector<string> scientist_debate;
extern vector<string> dog_rejection;
extern vector<string> mutant_rejection;
extern vector<string> that_is_disturbing;
extern vector<string> that_is_not_disturbing;
extern vector<string> execution;
extern vector<string> feels_sick;
extern vector<string> low_heart_torture_props;
extern vector<string> screaming;
extern vector<string> beat_with_props;
extern vector<string> words_meaning_screaming;
extern vector<string> words_to_scream;
extern vector<string> prays;
extern vector<string> prays_on_drugs;
extern vector<string> use_props;
extern vector<string> resist_drugs;
extern vector<string> cry_alarm;
extern vector<string> bleeding_to_death;
extern vector<string> stunned_text;
extern vector<string> paralyzed_text;
extern vector<string> paralyzed_tank;
extern vector<string> bleeding_animal;
extern vector<vector<string>> double_line_death;
extern vector<string> body_falls_apart;
extern vector<string> robbing_bank;
extern vector<string> teller_gestures;
extern vector<string> teller_complies;
extern vector<string> default_slogans;
extern vector<string> come_at_me_bro;
extern vector<string> backs_off;
extern vector<string> threaten_hostage;
extern vector<string> please_spare_hostage;
extern vector<string> who_cares_about_hostage;
extern vector<string> hostage_negotiation;
extern vector<string> please_no_more;
extern vector<string> let_hostages_go;
extern vector<string> go_ahead_and_die;
extern vector<string> agree_to_release_hostages;
extern vector<string> partial_conversion;
extern vector<string> broods_over_death;
extern vector<string> self_wounding;
extern vector<vector<string>> fall_in_love;
extern vector<vector<string>> bad_trip;
extern vector<string> good_trip;
extern vector<vector<string>> good_trip_companion;
extern vector<string> smarter_than_you_one_line;
extern vector<vector<string>> smarter_than_you;
extern vector<string> develops_hatred_one_line;
extern vector<vector<string>> develops_hatred;
extern vector<string> interrogater_shows_compassion_one_line;
extern vector<vector<string>> interrogater_shows_compassion;
extern vector<vector<string>> cling_to_interrogater;
extern vector<string> clinging_one_line;
extern vector<vector<string>> cling_to_religion;
extern vector<string> cling_to_religion_one_line;
extern vector<vector<string>> discuss;
extern vector<string> vanilla_recruit;
extern vector<vector<string>> cling_to_business;
extern vector<string> cling_to_business_one_line;
extern vector<vector<string>> cling_to_science;
extern vector<string> cling_to_science_one_line;
extern vector<string> city_names;
extern vector<string> male_first_names;
extern vector<string> female_first_names;
extern vector<string> gender_neutral_first_names;
extern vector<string> great_white_male_patriarch_first_names;
extern vector<string> regular_last_names;
extern vector<string> archconservative_last_names;
extern vector<string> quality_0;
extern vector<string> quality_20;
extern vector<string> quality_35;
extern vector<string> quality_50;
extern vector<string> words_meaning_hacked;
extern vector<string> enemy_website;
extern vector<string> win_hand_to_hand;
extern vector<string> lose_hand_to_hand;
extern vector<string> car_wont_start;
extern vector<string> gets_nervous;
extern vector<string> cant_hotwire_car;
extern vector<string> almost_hotwire_car;
extern vector<string> car_speed;
extern vector<string> car_plows_through;
extern vector<string> car_crash_modes;
extern vector<string> car_crash_fatalities;
extern vector<string> die_in_car;
extern vector<string> ccs_covername_shotgun;
extern vector<string> ccs_covername_other;
extern vector<string> words_meaning_hick;
extern vector<string> genetic_monster;
extern vector<string> date_fail;
extern vector<string> liberal_jury;
extern vector<string> conservative_jury;
extern vector<string> cruel_and_unusual_execution_methods;
extern vector<string> standard_execution_methods;
extern vector<string> supposedly_painless_execution_method;
extern vector<string> reeducation_experiences;
extern vector<string> labor_camp_experiences;
extern vector<string> good_experiences;
extern vector<string> bad_experiences;
extern vector<string> general_experiences;
extern vector<string> words_meaning_news;
extern vector<string> newspaper_first_name;
extern vector<string> newspaper_last_name;
extern vector<string> insult_for_liberal;
extern vector<string> word_replacing_liberal;
extern vector<string> blew_stealth_check;
extern vector<string> labor_camp_name;
extern vector<string> labor_camp_name_2;
extern vector<string> juice_name;
extern vector<string> juice_name_2;
extern vector<string> vegan_name;
extern vector<string> vegan_name_2;
extern vector<string> cafe_name;
extern vector<string> cafe_name_2;
extern vector<string> latte_name;
extern vector<string> latte_name_2;
extern vector<string> was_abused;
extern vector<string> liberalCrime;
extern vector<string> AMorPM;
extern vector<string> book_title;
extern vector<string> book_title_2;
extern vector<string> random_nationality;
extern vector<string> conservative_oppose_book;
extern vector<string> radio_name;
extern vector<string> radio_name_2;
extern vector<string> vigilante_murder;
extern vector<string> why_chase_ended;
extern vector<string> crazy_conservative_act;
extern vector<string> bribe_officers;
extern vector<string> my_idol;
extern vector<string> prison_book_title;
extern vector<string> prison_book_title_2;
extern vector<string> mutilated_corpse;
extern vector<string> evidence_of_child_murder;
extern vector<string> break_in_murder_case;
extern vector<string> animal_research_country;
extern vector<string> drug_name;
extern vector<string> drug_name_2;
extern vector<string> chimp_drug_impact;
extern vector<string> chimp_drug_horror;
extern vector<string> terrorist_group;
extern vector<string> terrorist_plot;
extern vector<string> terrorist_plot_no_free_speech;
extern vector<string> gene_corp_name;
extern vector<string> gene_corp_name_2;
extern vector<string> gene_product_name;
extern vector<string> gene_product_name_2;
extern vector<string> gene_product_benefit;
extern vector<string> gene_product_cost;
extern vector<string> bullshit_no_free_speech;
extern vector<string> bullshit;
extern vector<string> petty_violence;
extern vector<string> his_her;
extern vector<string> older_younger;
extern vector<string> brother_sister;
extern vector<string> judge_with_prostitute;
extern vector<string> judge_with_prostitute_no_free_speech;
extern vector<string> judge_with_prostitute_full_free_speech;
extern vector<string> radio_host_crazy_quote;
extern vector<string> radio_host_lost_mind;
extern vector<string> family_values_company_name;
extern vector<string> family_values_company_name_2;
extern vector<string> family_values_company_name_3;
extern vector<string> pollution_consumption;
extern vector<string> pollution_consumption_2;
extern vector<string> i_like_polution;
extern vector<string> distrust_liberals;
extern vector<string> tech_giant_name;
extern vector<string> tech_giant_name_2;
extern vector<string> fm_radio_name;
extern vector<string> fm_radio_name_2;
extern vector<string> public_place;
extern vector<string> reagan_bad;
extern vector<string> reagan_bad_2;
extern vector<string> ceo_behaving_badly;
extern vector<string> reagan_good;
extern vector<string> reagan_good_2;
extern vector<string> cable_name;
extern vector<string> cable_name_2;
extern vector<string> cable_city;
extern vector<string> cable_city_2;
extern vector<string> cant_find_keys;
extern vector<string> cant_find_keys_no_free_speech;
extern vector<string> ccs_adjective;
extern vector<string> ccs_adjective_2;
extern vector<string> ccs_adjective_3;
extern vector<string> ccs_noun;
extern vector<string> founderQuestions;

extern vector<string> carchase_obstacle_none;
extern vector<string> carchase_obstacle_fruit_stand;
extern vector<string> carchase_obstacle_truck_pulls_out;
extern vector<string> carchase_obstacle_cross_traffic;
extern vector<string> carchase_obstacle_child;
//extern vector<string> missedDriver;
//extern vector<string> missedPedestrian;
//extern vector<string> handToHandStrike;
extern vector<string> personalAds;
extern vector<string> personalAdsLG;
extern vector<string> sexdescAcronym;
extern vector<string> sexwhoAcronym;
extern vector<string> sexseekAcronym;
extern vector<string> sextypeAcronym;
extern vector<string> vehicleParagraph;
extern vector<string> caseBUSINESSFRONT_INSURANCE;
extern vector<string> caseBUSINESSFRONT_TEMPAGENCY;
extern vector<string> caseBUSINESSFRONT_RESTAURANT;
extern vector<string> caseBUSINESSFRONT_MISCELLANEOUS;
extern vector<string> caseNEWSSTORY_CCS_DEFEATED;
extern vector<string> caseNEWSSTORY_CCS_NOBACKERS;
extern vector<string> listOfStates;
extern vector<string> nextSiege;
extern vector<string> nextSiegeAgain;
extern vector<string> engageConservatives;
extern vector<string> engageConservativesEscape;
extern vector<string> methodOfExecution;
extern vector<string> getsSick;
extern vector<string> corporateSuffix;
extern vector<string> rejectedByCCS;
extern vector<string> rejectedBecauseNude;
extern vector<string> rejectedBecauseUnderage;
extern vector<string> rejectedBecauseFemale;
extern vector<string> rejectedBecauseFemaleish;
extern vector<string> rejectedBecauseDresscode;
extern vector<string> rejectedBecauseSmellFunny;
extern vector<string> rejectedBecauseBloodyClothes;
extern vector<string> rejectedBecauseDamagedClothes;
extern vector<string> rejectedBecauseSecondRateClothes;
extern vector<string> rejectedBecauseWeapons;
extern vector<string> rejectedBecauseGuestList;
extern vector<string> notRejected;
extern vector<string> randomCrime;
extern vector<string> caseREJECTED_NUDE;
extern vector<string> caseREJECTED_UNDERAGE;
extern vector<string> caseREJECTED_DRESSCODE;
extern vector<string> caseREJECTED_SMELLFUNNY;
extern vector<string> caseREJECTED_BLOODYCLOTHES;
extern vector<string> caseREJECTED_DAMAGEDCLOTHES;
extern vector<string> caseREJECTED_SECONDRATECLOTHES;
extern vector<string> caseREJECTED_WEAPONS;
extern vector<string> caseNOT_REJECTED;
extern vector<string> stalinAmendment;
extern vector<string> archConservativeAmendment;
extern vector<string> amendmentPass;
extern vector<string> evasionStrings;
extern vector<string> evasionStringsAlt;
extern vector<string> disbandingMessage;
extern vector<string> issue_phrases;
extern vector<vector<string>> adList;
extern vector<vector<string>> adListB;
extern vector<string> methodOfSorting;
extern vector<string> getMonth;
extern vector<string> conservativePrison;
extern vector<string> stalinistPrison;
extern vector<string> reaganifiedCabinet;
extern vector<string> stalinizedCabinet;

extern vector<string> bulkActivityString;
extern vector<string> standard_activities_and_data;

extern vector<string> supremeChars;
extern vector<string> courtChars;
//IsaacG
// the number five (5) here indicates how many lines a "pickup line" is
// 2 lines for the initial pickup,
// 1 line for accepting the proposal,
// and 2 lines for rejecting
// 
const int PICKUP_LINE_SIZE = 5;
const int DOUBLE_LINE = 2;
const int REAL_QUOTE_SIZE = 4;
const string talky = "talk\\";
const string talk_combat = "talk_combat\\";
const string titley = "titlescreen\\";
const string fighty = "fight\\";
const string interrogate = "interrogation\\";
const string names = "names\\";
const string activities = "activities\\";
const string chase = "chase\\";
const string creature = "creature\\";
const string datey = "date\\";
const string justice = "justice\\";
const string siege = "siege\\";
const string stealth = "stealth\\";
const string locations = "locations\\";
const string majorevent = "majorevent\\";
const string mostlyendings = "mostlyendings\\";
// IsaacG: This is the crown jewel of my additions to LCS

vector<string> allText;
vector<string> helpTopicUnprocessed;


 vector<string> conservativeLegalArgumentUnprocessed;
 vector<string> youAreStupidTalkAboutIssuesUnprocessed;
 vector<string> issueTooLiberalUnprocessed;
 vector<string> issueEventStringUnprocessed;
 vector<string> conservatiseLawUnprocessed;
 vector<string> liberalizeLawUnprocessed;
 vector<string> discussIssuesUnprocessed;
 vector<string> discussesIssuesUnprocessed;
 vector<string> talkAboutTheIssuesUnprocessed;
 vector<string> endgameLawStringsUnprocessed;
 vector<string> state_biases_Unprocessed;

vector<file_and_text_collection> text_file_collection = {
	customText(&default_slogans, "default_slogans.txt"),
	/*titlescreen.cpp*/
	customText(&real_quote, titley + "real_quote.txt", REAL_QUOTE_SIZE),
	/*talk.cpp*/
	customText(&pickupLines, talky + "pickupLines.txt", PICKUP_LINE_SIZE),
	customText(&no_free_speech_flirt, talky + "no_free_speech_flirt.txt", PICKUP_LINE_SIZE),
	customText(&lovingly_talk_to_mutant, talky + "lovingly_talk_to_mutant.txt", DOUBLE_LINE),
	customText(&normal_talk_to_mutant, talky + "normal_talk_to_mutant.txt", DOUBLE_LINE),
	customText(&lovingly_talk_to_dog, talky + "lovingly_talk_to_dog.txt", DOUBLE_LINE),
	customText(&normal_talk_to_dog, talky + "normal_talk_to_dog.txt", DOUBLE_LINE),
	customText(&dog_rejection, talky + "dog_rejection.txt"),
	customText(&mutant_rejection, talky + "mutant_rejection.txt"),
	customText(&that_is_disturbing, talky + "that_is_disturbing.txt"),
	customText(&that_is_not_disturbing, talky + "that_is_not_disturbing.txt"),
	customText(&robbing_bank, talky + "robbing_bank.txt"),
	customText(&teller_gestures, talky + "teller_gestures.txt"),
	customText(&teller_complies, talky + "teller_complies.txt"),
	//talk in combat
	customText(&come_at_me_bro, talk_combat + "come_at_me_bro.txt"),
	customText(&backs_off, talk_combat + "backs_off.txt"),
	customText(&threaten_hostage, talk_combat + "threaten_hostage.txt"),
	customText(&please_spare_hostage, talk_combat + "please_spare_hostage.txt"),
	customText(&who_cares_about_hostage, talk_combat + "who_cares_about_hostage.txt"),
	customText(&hostage_negotiation, talk_combat + "hostage_negotiation.txt"),
	customText(&please_no_more, talk_combat + "please_no_more.txt"),
	customText(&let_hostages_go, talk_combat + "let_hostages_go.txt"),
	customText(&go_ahead_and_die, talk_combat + "go_ahead_and_die.txt"),
	customText(&agree_to_release_hostages, talk_combat + "agree_to_release_hostages.txt"),
	/*fight.cpp*/
	customText(&escape_running, fighty + "escape_running.txt"),
	customText(&escape_crawling, fighty + "escape_crawling.txt"),
	customText(&judge_debate, fighty + "judge_debate.txt"),
	customText(&conservative_ceo_debate, fighty + "conservative_ceo_debate.txt"),
	customText(&other_ceo_debate, fighty + "other_ceo_debate.txt"),
	customText(&conservative_politician_debate, fighty + "conservative_politician_debate.txt"),
	customText(&other_politician_debate, fighty + "other_politician_debate.txt"),
	customText(&media_debate, fighty + "media_debate.txt"),
	customText(&military_debate, fighty + "military_debate.txt"),
	customText(&police_debate, fighty + "police_debate.txt"),
	customText(&scientist_debate, fighty + "scientist_debate.txt"),
	customText(&cry_alarm, fighty + "cry_alarm.txt"),
	customText(&bleeding_to_death, fighty + "bleeding_to_death.txt"),
	customText(&stunned_text, fighty + "stunned_text.txt"),
	customText(&paralyzed_text, fighty + "paralyzed_text.txt"),
	customText(&paralyzed_tank, fighty + "paralyzed_tank.txt"),
	customText(&bleeding_animal, fighty + "bleeding_animal.txt"),
	customText(&double_line_death, fighty + "double_line_death.txt", DOUBLE_LINE),
	customText(&body_falls_apart, fighty + "body_falls_apart.txt"),
	/*interrogation.cpp*/
	customText(&execution, interrogate + "execution.txt"),
	customText(&feels_sick, interrogate + "feels_sick.txt"),
	customText(&low_heart_torture_props, interrogate + "low_heart_torture_props.txt"),
	customText(&screaming, interrogate + "screaming.txt"),
	customText(&beat_with_props, interrogate + "beat_with_props.txt"),
	customText(&words_meaning_screaming, interrogate + "words_meaning_screaming.txt"),
	customText(&words_to_scream, interrogate + "words_to_scream.txt"),
	customText(&prays, interrogate + "prays.txt"),
	customText(&prays_on_drugs, interrogate + "prays_on_drugs.txt"),
	customText(&use_props, interrogate + "use_props.txt"),
	customText(&resist_drugs, interrogate + "resist_drugs.txt"),
	customText(&partial_conversion, interrogate + "partial_conversion.txt"),
	customText(&broods_over_death, interrogate + "broods_over_death.txt"),
	customText(&self_wounding, interrogate + "self_wounding.txt"),
	customText(&good_trip, interrogate + "good_trip.txt"),
	customText(&smarter_than_you_one_line, interrogate + "smarter_than_you_one_line.txt"),
	customText(&develops_hatred_one_line, interrogate + "develops_hatred_one_line.txt"),
	customText(&interrogater_shows_compassion_one_line, interrogate + "interrogater_shows_compassion_one_line.txt"),
	customText(&clinging_one_line, interrogate + "clinging_one_line.txt"),
	customText(&cling_to_religion_one_line, interrogate + "cling_to_religion_one_line.txt"),
	customText(&vanilla_recruit, interrogate + "vanilla_recruit.txt"),
	customText(&cling_to_business_one_line, interrogate + "cling_to_business_one_line.txt"),
	customText(&cling_to_science_one_line, interrogate + "cling_to_science_one_line.txt"),
	customText(&fall_in_love, interrogate + "fall_in_love.txt", DOUBLE_LINE),
	customText(&bad_trip, interrogate + "bad_trip.txt", DOUBLE_LINE),
	customText(&good_trip_companion, interrogate + "good_trip_companion.txt", DOUBLE_LINE),
	customText(&smarter_than_you, interrogate + "smarter_than_you.txt", DOUBLE_LINE),
	customText(&develops_hatred, interrogate + "develops_hatred.txt", DOUBLE_LINE),
	customText(&interrogater_shows_compassion, interrogate + "interrogater_shows_compassion.txt", DOUBLE_LINE),
	customText(&cling_to_interrogater, interrogate + "cling_to_interrogater.txt", DOUBLE_LINE),
	customText(&cling_to_religion, interrogate + "cling_to_religion.txt", DOUBLE_LINE),
	customText(&discuss, interrogate + "discuss.txt", DOUBLE_LINE),
	customText(&cling_to_business, interrogate + "cling_to_business.txt", DOUBLE_LINE),
	customText(&cling_to_science, interrogate + "cling_to_science.txt", DOUBLE_LINE),
	/*getnames.cpp*/
	customText(&city_names, names + "city_names.txt"),
	/*creaturenames.cpp*/
	customText(&male_first_names, names + "male_first_names.txt"),
	customText(&female_first_names, names + "female_first_names.txt"),
	customText(&gender_neutral_first_names, names + "gender_neutral_first_names.txt"),
	customText(&great_white_male_patriarch_first_names, names + "great_white_male_patriarch_first_names.txt"),
	customText(&regular_last_names, names + "regular_last_names.txt"),
	customText(&archconservative_last_names, names + "archconservative_last_names.txt"),
	/*activities.cpp*/
	customText(&quality_0, activities + "quality_0.txt"),
	customText(&quality_20, activities + "quality_20.txt"),
	customText(&quality_35, activities + "quality_35.txt"),
	customText(&quality_50, activities + "quality_50.txt"),
	customText(&words_meaning_hacked, activities + "words_meaning_hacked.txt"),
	customText(&enemy_website, activities + "enemy_website.txt"),
	customText(&win_hand_to_hand, activities + "win_hand_to_hand.txt"),
	customText(&lose_hand_to_hand, activities + "lose_hand_to_hand.txt"),
	customText(&car_wont_start, activities + "car_wont_start.txt"),
	customText(&gets_nervous, activities + "gets_nervous.txt"),
	customText(&cant_hotwire_car, activities + "cant_hotwire_car.txt"),
	customText(&almost_hotwire_car, activities + "almost_hotwire_car.txt"),
	customText(&cant_find_keys, activities + "cant_find_keys.txt"),
	customText(&cant_find_keys_no_free_speech, activities + "cant_find_keys_no_free_speech.txt"),
	/*miscactions.cpp*/
	customText(&was_abused, activities + "was_abused.txt"),
	/*chase.cpp*/
	customText(&car_speed, chase + "car_speed.txt"),
	customText(&car_plows_through, chase + "car_plows_through.txt"),
	customText(&car_crash_modes, chase + "car_crash_modes.txt"),
	customText(&car_crash_fatalities, chase + "car_crash_fatalities.txt"),
	customText(&die_in_car, chase + "die_in_car.txt"),
	/*creature.cpp*/
	customText(&ccs_covername_shotgun, creature + "ccs_covername_shotgun.txt"),
	customText(&ccs_covername_other, creature + "ccs_covername_other.txt"),
	/*creaturetypes.cpp*/
	customText(&words_meaning_hick, creature + "words_meaning_hick.txt"),
	customText(&genetic_monster, creature + "genetic_monster.txt"),
	/*date.cpp*/
	customText(&date_fail, datey + "date_fail.txt"),
	/*justice.cpp*/
	customText(&liberal_jury, justice + "liberal_jury.txt"),
	customText(&conservative_jury, justice + "conservative_jury.txt"),
	customText(&cruel_and_unusual_execution_methods, justice + "cruel_and_unusual_execution_methods.txt"),
	customText(&standard_execution_methods, justice + "standard_execution_methods.txt"),
	customText(&supposedly_painless_execution_method, justice + "supposedly_painless_execution_method.txt"),
	customText(&reeducation_experiences, justice + "reeducation_experiences.txt"),
	customText(&labor_camp_experiences, justice + "labor_camp_experiences.txt"),
	customText(&good_experiences, justice + "good_experiences.txt"),
	customText(&bad_experiences, justice + "bad_experiences.txt"),
	customText(&general_experiences, justice + "general_experiences.txt"),
	/*siege.cpp*/
	customText(&words_meaning_news, siege + "words_meaning_news.txt"),
	customText(&newspaper_first_name, siege + "newspaper_first_name.txt"),
	customText(&newspaper_last_name, siege + "newspaper_last_name.txt"),
	customText(&insult_for_liberal, siege + "insult_for_liberal.txt"),
	customText(&word_replacing_liberal, siege + "word_replacing_liberal.txt"),
	customText(&blew_stealth_check, stealth + "blew_stealth_check.txt"),
	/*locations.cpp*/
	customText(&labor_camp_name, locations + "labor_camp_name.txt"),
	customText(&labor_camp_name_2, locations + "labor_camp_name_2.txt"),
	customText(&juice_name, locations + "juice_name.txt"),
	customText(&juice_name_2, locations + "juice_name_2.txt"),
	customText(&vegan_name, locations + "vegan_name.txt"),
	customText(&vegan_name_2, locations + "vegan_name_2.txt"),
	customText(&cafe_name, locations + "cafe_name.txt"),
	customText(&cafe_name_2, locations + "cafe_name_2.txt"),
	customText(&latte_name, locations + "latte_name.txt"),
	customText(&latte_name_2, locations + "latte_name_2.txt"),
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
	/*newgame.cpp*/
	customText(&founderQuestions, "newgame\\founderQuestions.txt"),
	/*transferred via algorithm*/
	customText(&carchase_obstacle_none, mostlyendings + "carchase_obstacle_none.txt"),
	customText(&carchase_obstacle_fruit_stand, mostlyendings + "carchase_obstacle_fruit_stand.txt"),
	customText(&carchase_obstacle_truck_pulls_out, mostlyendings + "carchase_obstacle_truck_pulls_out.txt"),
	customText(&carchase_obstacle_cross_traffic, mostlyendings + "carchase_obstacle_cross_traffic.txt"),
	customText(&carchase_obstacle_child, mostlyendings + "carchase_obstacle_child.txt"),
	customText(&sexdescAcronym, mostlyendings + "sexdescAcronym.txt"),
	customText(&sexwhoAcronym, mostlyendings + "sexwhoAcronym.txt"),
	customText(&sexseekAcronym, mostlyendings + "sexseekAcronym.txt"),
	customText(&sextypeAcronym, mostlyendings + "sextypeAcronym.txt"),
	customText(&vehicleParagraph, mostlyendings + "vehicleParagraph.txt"),
	customText(&caseBUSINESSFRONT_INSURANCE, mostlyendings + "caseBUSINESSFRONT_INSURANCE.txt"),
	customText(&caseBUSINESSFRONT_TEMPAGENCY, mostlyendings + "caseBUSINESSFRONT_TEMPAGENCY.txt"),
	customText(&caseBUSINESSFRONT_RESTAURANT, mostlyendings + "caseBUSINESSFRONT_RESTAURANT.txt"),
	customText(&caseBUSINESSFRONT_MISCELLANEOUS, mostlyendings + "caseBUSINESSFRONT_MISCELLANEOUS.txt"),
	customText(&caseNEWSSTORY_CCS_DEFEATED, mostlyendings + "caseNEWSSTORY_CCS_DEFEATED.txt"),
	customText(&caseNEWSSTORY_CCS_NOBACKERS, mostlyendings + "caseNEWSSTORY_CCS_NOBACKERS.txt"),
	customText(&listOfStates, mostlyendings + "listOfStates.txt"),
	customText(&nextSiege, mostlyendings + "nextSiege.txt"),
	customText(&nextSiegeAgain, mostlyendings + "nextSiegeAgain.txt"),
	customText(&engageConservatives, mostlyendings + "engageConservatives.txt"),
	customText(&engageConservativesEscape, mostlyendings + "engageConservativesEscape.txt"),
	customText(&methodOfExecution, mostlyendings + "methodOfExecution.txt"),
	customText(&getsSick, mostlyendings + "getsSick.txt"),
	customText(&corporateSuffix, mostlyendings + "corporateSuffix.txt"),
	customText(&rejectedBecauseNude, mostlyendings + "rejectedBecauseNude.txt"),
	customText(&rejectedBecauseUnderage, mostlyendings + "rejectedBecauseUnderage.txt"),
	customText(&rejectedBecauseFemale, mostlyendings + "rejectedBecauseFemale.txt"),
	customText(&rejectedBecauseFemaleish, mostlyendings + "rejectedBecauseFemaleish.txt"),
	customText(&rejectedBecauseDresscode, mostlyendings + "rejectedBecauseDresscode.txt"),
	customText(&rejectedBecauseSmellFunny, mostlyendings + "rejectedBecauseSmellFunny.txt"),
	customText(&rejectedBecauseBloodyClothes, mostlyendings + "rejectedBecauseBloodyClothes.txt"),
	customText(&rejectedBecauseDamagedClothes, mostlyendings + "rejectedBecauseDamagedClothes.txt"),
	customText(&rejectedBecauseSecondRateClothes, mostlyendings + "rejectedBecauseSecondRateClothes.txt"),
	customText(&rejectedBecauseWeapons, mostlyendings + "rejectedBecauseWeapons.txt"),
	customText(&rejectedBecauseGuestList, mostlyendings + "rejectedBecauseGuestList.txt"),
	customText(&rejectedByCCS, mostlyendings + "rejectedByCCS.txt"),
	customText(&notRejected, mostlyendings + "notRejected.txt"),
	customText(&randomCrime, mostlyendings + "randomCrime.txt"),
	customText(&caseREJECTED_NUDE, mostlyendings + "caseREJECTED_NUDE.txt"),
	customText(&caseREJECTED_UNDERAGE, mostlyendings + "caseREJECTED_UNDERAGE.txt"),
	customText(&caseREJECTED_DRESSCODE, mostlyendings + "caseREJECTED_DRESSCODE.txt"),
	customText(&caseREJECTED_SMELLFUNNY, mostlyendings + "caseREJECTED_SMELLFUNNY.txt"),
	customText(&caseREJECTED_BLOODYCLOTHES, mostlyendings + "caseREJECTED_BLOODYCLOTHES.txt"),
	customText(&caseREJECTED_DAMAGEDCLOTHES, mostlyendings + "caseREJECTED_DAMAGEDCLOTHES.txt"),
	customText(&caseREJECTED_SECONDRATECLOTHES, mostlyendings + "caseREJECTED_SECONDRATECLOTHES.txt"),
	customText(&caseREJECTED_WEAPONS, mostlyendings + "caseREJECTED_WEAPONS.txt"),
	customText(&caseNOT_REJECTED, mostlyendings + "caseNOT_REJECTED.txt"),
	customText(&stalinAmendment, mostlyendings + "stalinAmendment.txt"),
	customText(&archConservativeAmendment, mostlyendings + "archConservativeAmendment.txt"),
	customText(&amendmentPass, mostlyendings + "amendmentPass.txt"),
	customText(&evasionStrings, mostlyendings + "evasionStrings.txt"),
	customText(&evasionStringsAlt, mostlyendings + "evasionStringsAlt.txt"),
	customText(&disbandingMessage, mostlyendings + "disbandingMessage.txt"),
	customText(&issue_phrases, mostlyendings + "issue_phrases.txt"),
	customText(&methodOfSorting, mostlyendings + "methodOfSorting.txt"),
	customText(&getMonth, mostlyendings + "getMonth.txt"),
	customText(&conservativePrison, mostlyendings + "conservativePrison.txt"),
	customText(&stalinistPrison, mostlyendings + "stalinistPrison.txt"),
	customText(&reaganifiedCabinet, mostlyendings + "reaganifiedCabinet.txt"),
	customText(&stalinizedCabinet, mostlyendings + "stalinizedCabinet.txt"),
	customText(&adList, mostlyendings + "adList.txt", 4),
	customText(&adListB, mostlyendings + "adListB.txt", 4),
	customText(&bulkActivityString, mostlyendings + "bulkActivityString.txt"),
	customText(&standard_activities_and_data, mostlyendings + "standard_activities_and_data.txt"),
	customText(&supremeChars, mostlyendings + "supremeChars.txt"),
	customText(&courtChars, mostlyendings + "courtChars.txt"),
	customText(&allText, "allText.txt"),
	customText(&helpTopicUnprocessed, "helpTopics.txt"),
	customText(&conservativeLegalArgumentUnprocessed, talky + "conservativeLegalArgument.txt"),
	customText(&youAreStupidTalkAboutIssuesUnprocessed, talky + "youAreStupidTalkAboutIssues.txt"),
	customText(&issueTooLiberalUnprocessed, talky + "issueTooLiberal.txt"),
	customText(&issueEventStringUnprocessed, talky + "issueEventString.txt"),
	customText(&conservatiseLawUnprocessed, talky + "conservatiseLaw.txt"),
	customText(&liberalizeLawUnprocessed, talky + "liberalizeLaw.txt"),
	customText(&discussIssuesUnprocessed, talky + "discussIssues.txt"),
	customText(&discussesIssuesUnprocessed, talky + "discussesIssues.txt"),
	customText(&talkAboutTheIssuesUnprocessed, talky + "talkAboutTheIssues.txt"),
	customText(&endgameLawStringsUnprocessed, talky + "endgameLawStrings.txt"),
	customText(&state_biases_Unprocessed, mostlyendings + "state_biases.txt"),
};


extern string findingBugs;
extern string undefined;
extern string NONE;
extern string YEA;
extern string NAY;
extern string AND;
extern string counts_of;
extern string feels_sick_and;
extern string check_status_of_squad_liberal;
extern string show_squad_liberal_status;
extern string change_squad_order;
extern string string_sleeper;
extern string execution_in_three_months;
extern string major_news_take_it_up;
extern string they_are_stashed;
extern string they_ll_round_you_up;
extern string conservativesRemakeWorld;
extern string bound_to_rile_up;
extern string establishPrisonReform;
extern string improvePrisonConditions;
extern string stalinistsRemakeWorld;
extern string chooseALiberalTo;
extern string youWentOnVacation;
extern string youWentIntoHiding;
extern string whileYouWereInPrison;
extern string youDisappearedSafely;

extern string proposeConservative;
extern string proposeStalinist;

extern string tag_creature;
extern string tag_skill_experience;
extern string tag_name;
extern string tag_propername;
extern string tag_gender_conservative;
extern string tag_gender_liberal;
extern string tag_squadid;
extern string tag_age;
extern string tag_birthday_month;
extern string tag_birthday_day;
extern string tag_exists;
extern string tag_align;
extern string tag_alive;
extern string tag_type_idname;
extern string tag_infiltration;
extern string tag_animalgloss;
extern string tag_specialattack;
extern string tag_clinic;
extern string tag_dating;
extern string tag_hiding;
extern string tag_trainingtime;
extern string tag_trainingsubject;
extern string tag_prisoner;
extern string tag_sentence;
extern string tag_confessions;
extern string tag_deathpenalty;
extern string tag_joindays;
extern string tag_deathdays;
extern string tag_id;
extern string tag_hireid;
extern string tag_meetings;
extern string tag_forceinc;
extern string tag_stunned;
extern string tag_has_thrown_weapon;
extern string tag_money;
extern string tag_juice;
extern string tag_income;
extern string tag_wound;
extern string tag_blood;
extern string tag_special;
extern string tag_crimes_suspected;
extern string tag_heat;
extern string tag_location;
extern string tag_worklocation;
extern string tag_cantbluff;
extern string tag_base;
extern string tag_activity;
extern string tag_arg;
extern string tag_arg2;
extern string tag_carid;
extern string tag_is_driver;
extern string tag_pref_carid;
extern string tag_pref_is_driver;
extern string tag_flag;
extern string tag_dontname;
extern string enter_done;
extern string beingFollowedBySwine;
extern string lostThem;
extern string hereTheyCome;
extern string spaceDashSpace;
extern string currentLocation;
extern string safeHouse;
extern string enemySafeHouse;
extern string closedDown;
extern string highSecurity;
extern string needCar;
extern string spaceParanthesisDollar;
extern string paranthesisDollar;
extern string closeParenthesis;
extern string underSiege;
extern string percentSign;
extern string secrecyLevel;
extern string heatLevel;
extern string travelDifCity;
extern string tag_class;
extern string tag_WEAPON;
extern string tag_CLIP;
extern string tag_ARMOR;
extern string tag_LOOT;
extern string tag_type;
extern string tag_description;
extern string tag_price;
extern string tag_sleeperprice;
extern string tag_letter;
extern string smellsPanic;
extern string tag_Sta;
extern string tag_Libp;
extern string tag_Lib;
extern string tag_Mod;
extern string tag_Cons;
extern string tag_Consp;

extern string moderateLC;
extern string buggyString;


extern string isSeized;

extern string selectA;
extern string selectAn;
extern string enterDash;


extern string accordingToSourcesAtScene;
extern string accordingToPoliceSources;
extern string ampersandR;
extern string singleDot;

extern string membersOfLCS;
extern string lcsSpokeseperson;
extern string policeSpokesperson;
extern string pressKeyToReflect;

 
extern string pressLToViewHighScores;
extern string ampersandC;
extern string saysComma;
extern string while_naked;
extern string respondsComma;
extern string colonSpace;

string singleSpace;
string commaSpace;

extern string theLCS;
extern string notASkill;
extern string notAnAttribute;

extern string vehicleSportsCar;

extern string aNewConEra;
extern string theYearIs;
extern string conservativePresident;
extern string endsSecondTerm;
extern string highSeventiesApprovePres;
extern string conMajorityHouse;
extern string senateConMajority;
extern string beginningOfNew;
extern string conEra;
extern string thePresident;
extern string hasAskedCongressBeQuick;
extern string rubberStampArchCon;
extern string theLeftSeems;
extern string powerlessToStop;
extern string inThisDarkTime;
extern string whatIsYourName;
extern string pressEnterToBeRealName;

extern string invalidTag;
extern string theDocSaid;
extern string aBoy;
extern string aGirl;
extern string intersex;
extern string myParents;
extern string insistedOtherwise;
extern string they;
extern string namedMe;

extern string error;

extern string theFounder;
extern string firstName;
extern string pressAtoReconsider;
extern string lastName;
extern string pressBtoBeReborn;
extern string sexIs;
extern string male;
extern string female;
extern string itsComplicated;
extern string pressCtoChangeSex;
extern string history;
extern string letMeChoose;
extern string letFateDecide;
extern string pressDtoToggle;
extern string city;
extern string pressEtoRelocate;
extern string pressAnyKey;
extern string allOptions;

extern string unSelected;
extern string isSelected;
extern string pressAnyOtherKey;

extern string notCreature;
extern string notValidMap;
extern string notSpecialWound;
extern string newGameAdvanced;
extern string a_classicMode;
extern string b_weDidntStartIt;
extern string c_nightmareMode;
extern string d_nationalLCS;
extern string e_marathonMode;
extern string f_stalinistMode;
extern string newGameYourAgenda;
extern string a_noComprimise;
extern string b_democrat;
extern string newGameFieldLearn;
extern string affectsTheseSkills;
extern string a_fastSkills;
extern string b_classic;
extern string c_hardMode;


extern string deleteSave;
extern string chooseSave;
extern string titleScreenLine;
extern string newGame;
extern string pressToSelectSave;
extern string pressToDeleteSave;
extern string vToSwitchXToQuit;

extern string areYouSureDelte;
extern string questionYSlashN;
extern string pressMtoTurnOffMusic;
extern string pressMtoTurnOnMusic;

extern string inWhatWorld;
extern string enterNameForSave;
extern string pleaseEnterName;
extern string prettyPlease;
extern string justEnterName;

extern string liberalCrimeSquad;
extern string inspiredByOubliette;
extern string copyrightTarn;
extern string bayTwelveProductions;
extern string lcsHyperlink;
extern string vChar;
extern string maintainedByOpenSource;
extern string kingDrakeHyperlink;
extern string lcsForumHyperlink;
extern string lcsWikiHyperlink;
extern string pressESCToQuit;
extern string pressAnyKeyToPursue;
extern string plusChar;

extern string dotDat;

extern string itemType;
extern string doesNotExistItem;
extern string vehicleType;
extern string doesNotExistVehicle;
extern string couldNotLoad;

extern string itemClassClip;
extern string itemClassWeapon;
extern string itemClassArmor;
extern string itemClassLoot;
extern string itemClassMoney;

extern string failedToLoadSitemaps;
extern string debugCode;
extern string activated;
extern string failedToLoad;
extern string exclamationPoint;
extern string defaultMissingForMask;
extern string defaultUnknownForMask;

extern string ableToStopBleed;
extern string sWounds;
extern string isBurned;
extern string drops;
extern string sBody;


extern string hasBeenCaughtSnooping;
extern string isNowHomeless;
extern string hasLeakedIntelligence;
extern string hasLeakedPolice;
extern string hasLeakedCorporate;
extern string hasLeakedPrison;
extern string hasLeakedCableNews;
extern string hasLeakedAMRadio;
extern string hasLeakedAnimalResearch;
extern string hasLeakedJudiciary;
extern string papersAreStashed;
extern string hasLeakedCCS;
extern string diskIsStashed;

extern string arrestedWhileEmbezzling;
extern string arrestedWhileStealing;

extern string droppedOffPackage;
extern string itemNotFound;
extern string lostStolenItem;
extern string contactModAuthor;

extern string hasRecruited;
extern string looksForwardToServing;

extern string toSpend;
extern string chooseAColor;
extern string theseColorsAreCon;
extern string thisColor;
extern string notEnoughMoney;
extern string chooseVehicle;
extern string thisVehicle;
extern string weDontNeedCar;

extern string enterLeave;
extern string b_chooseBuyer;
extern string s_sellCar;
extern string s_sellThe;
extern string g_getCar;
extern string f_fixWounds;

extern string univer;
extern string numRecruit;
extern string numMartyr;
extern string numKills;
extern string numKidnap;
extern string cashTaxed;
extern string cashSpent;
extern string flagsBought;
extern string flagsBurned;
extern string noValid;
extern string heLiElite;
extern string heLiLiber;
extern string heLiBrought;
extern string heLiBlot;
extern string heLiMob;
extern string heLiDownsized;
extern string heLiKIA;
extern string hecoReag;
extern string heLiDie;
extern string heLiExec;
extern string heLiVaca;
extern string heLiHide;
extern string heLiHunted;
extern string heLiScattered;
extern string heLiOutCrime;
extern string heLiBurned;
extern string hecoStalinized;
extern string dotSpace;

extern string unnamed_String_Talk_cpp_000;
extern string unnamed_String_Talk_cpp_001;
extern string unnamed_String_Talk_cpp_002;
extern string unnamed_String_Talk_cpp_003;
extern string unnamed_String_Talk_cpp_004;
extern string unnamed_String_Talk_cpp_005;
extern string unnamed_String_Talk_cpp_006;
extern string unnamed_String_Talk_cpp_007;
extern string unnamed_String_Talk_cpp_008;
extern string unnamed_String_Talk_cpp_009;
extern string unnamed_String_Talk_cpp_010;
extern string unnamed_String_Talk_cpp_011;
extern string unnamed_String_Talk_cpp_012;
extern string unnamed_String_Talk_cpp_013;
extern string unnamed_String_Talk_cpp_014;
extern string unnamed_String_Talk_cpp_015;
extern string unnamed_String_Talk_cpp_016;
extern string unnamed_String_Talk_cpp_017;
extern string unnamed_String_Talk_cpp_018;
extern string unnamed_String_Talk_cpp_019;
extern string unnamed_String_Talk_cpp_020;
extern string unnamed_String_Talk_cpp_021;
extern string unnamed_String_Talk_cpp_022;
extern string unnamed_String_Talk_cpp_023;
extern string unnamed_String_Talk_cpp_024;
extern string unnamed_String_Talk_cpp_025;
extern string unnamed_String_Talk_cpp_026;
extern string unnamed_String_Talk_cpp_027;
extern string unnamed_String_Talk_cpp_028;
extern string unnamed_String_Talk_cpp_029;
extern string unnamed_String_Talk_cpp_030;
extern string unnamed_String_Talk_cpp_031;
extern string unnamed_String_Talk_cpp_032;
extern string unnamed_String_Talk_cpp_033;
extern string unnamed_String_Talk_cpp_034;
extern string unnamed_String_Talk_cpp_035;
extern string unnamed_String_Talk_cpp_036;
extern string unnamed_String_Talk_cpp_037;
extern string unnamed_String_Talk_cpp_038;
extern string unnamed_String_Talk_cpp_039;
extern string unnamed_String_Talk_cpp_040;
extern string unnamed_String_Talk_cpp_041;
extern string unnamed_String_Talk_cpp_042;
extern string unnamed_String_Talk_cpp_043;
extern string unnamed_String_Talk_cpp_044;
extern string unnamed_String_Talk_cpp_045;
extern string unnamed_String_Talk_cpp_046;
extern string unnamed_String_Talk_cpp_047;
extern string unnamed_String_Talk_cpp_048;
extern string unnamed_String_Talk_cpp_049;
extern string unnamed_String_Talk_cpp_050;
extern string unnamed_String_Talk_cpp_051;
extern string unnamed_String_Talk_cpp_052;
extern string unnamed_String_Talk_cpp_053;
extern string unnamed_String_Talk_cpp_054;
extern string unnamed_String_Talk_cpp_055;
extern string unnamed_String_Talk_cpp_056;
extern string unnamed_String_Talk_cpp_057;
extern string unnamed_String_Talk_cpp_058;
extern string unnamed_String_Talk_cpp_059;
extern string unnamed_String_Talk_cpp_060;
extern string unnamed_String_Talk_cpp_061;
extern string unnamed_String_Talk_cpp_062;
extern string unnamed_String_Talk_cpp_063;
extern string unnamed_String_Talk_cpp_064;
extern string unnamed_String_Talk_cpp_065;
extern string unnamed_String_Talk_cpp_066;
extern string unnamed_String_Talk_cpp_067;
extern string unnamed_String_Talk_cpp_068;
extern string unnamed_String_Talk_cpp_069;
extern string unnamed_String_Talk_cpp_070;
extern string unnamed_String_Talk_cpp_071;
extern string unnamed_String_Talk_cpp_072;
extern string unnamed_String_Talk_cpp_073;
extern string unnamed_String_Talk_cpp_074;
extern string unnamed_String_Talk_cpp_075;
extern string unnamed_String_Talk_cpp_076;
extern string unnamed_String_Talk_cpp_077;
extern string unnamed_String_Talk_cpp_078;
extern string unnamed_String_Talk_cpp_079;
extern string unnamed_String_Talk_cpp_080;
extern string unnamed_String_Talk_cpp_081;
extern string unnamed_String_Talk_cpp_082;
extern string unnamed_String_Talk_cpp_083;
extern string unnamed_String_Talk_cpp_084;
extern string unnamed_String_Talk_cpp_085;
extern string unnamed_String_Talk_cpp_086;
extern string unnamed_String_Talk_cpp_087;
extern string unnamed_String_Talk_cpp_088;
extern string unnamed_String_Talk_cpp_089;
extern string unnamed_String_Talk_cpp_090;
extern string unnamed_String_Talk_cpp_091;
extern string unnamed_String_Talk_cpp_092;
extern string unnamed_String_Talk_cpp_093;
extern string unnamed_String_Talk_cpp_094;
extern string unnamed_String_Talk_cpp_095;
extern string unnamed_String_Talk_cpp_096;
extern string unnamed_String_Talk_cpp_097;
extern string unnamed_String_Talk_cpp_098;
extern string unnamed_String_Talk_cpp_099;
extern string unnamed_String_Talk_cpp_100;
extern string unnamed_String_Talk_cpp_101;
extern string unnamed_String_Talk_cpp_102;
extern string unnamed_String_Talk_cpp_103;
extern string unnamed_String_Talk_cpp_104;
extern string unnamed_String_Talk_cpp_105;
extern string unnamed_String_Talk_cpp_106;
extern string unnamed_String_Talk_cpp_107;
extern string unnamed_String_Talk_cpp_108;
extern string unnamed_String_Talk_cpp_109;
extern string unnamed_String_Talk_cpp_110;
extern string unnamed_String_Talk_cpp_111;
extern string unnamed_String_Talk_cpp_112;
extern string unnamed_String_Talk_cpp_113;
extern string unnamed_String_Talk_cpp_114;
extern string unnamed_String_Talk_cpp_115;
extern string unnamed_String_Talk_cpp_116;
extern string unnamed_String_Talk_cpp_117;
extern string unnamed_String_Talk_cpp_118;
extern string unnamed_String_Talk_cpp_119;
extern string unnamed_String_Talk_cpp_120;
extern string unnamed_String_Talk_cpp_121;
extern string unnamed_String_Talk_cpp_122;
extern string unnamed_String_Talk_cpp_123;
extern string unnamed_String_Talk_cpp_124;
extern string unnamed_String_Talk_cpp_125;
extern string unnamed_String_Talk_cpp_126;
extern string unnamed_String_Talk_cpp_127;
extern string unnamed_String_Talk_cpp_128;
extern string unnamed_String_Talk_cpp_129;
extern string unnamed_String_Talk_cpp_130;
extern string unnamed_String_Talk_cpp_131;
extern string unnamed_String_Talk_cpp_132;
extern string unnamed_String_Talk_cpp_133;
extern string unnamed_String_Talk_cpp_134;
extern string unnamed_String_Talk_cpp_135;
extern string unnamed_String_Talk_cpp_136;
extern string unnamed_String_Talk_cpp_137;
extern string unnamed_String_Talk_cpp_138;
extern string unnamed_String_Talk_cpp_139;
extern string unnamed_String_Talk_cpp_140;
extern string unnamed_String_Talk_cpp_141;
extern string unnamed_String_Talk_cpp_142;
extern string unnamed_String_Talk_cpp_143;
extern string unnamed_String_Talk_cpp_144;
extern string unnamed_String_Talk_cpp_145;
extern string unnamed_String_Talk_cpp_146;
extern string unnamed_String_Talk_cpp_147;
extern string unnamed_String_Talk_cpp_148;
extern string unnamed_String_Talk_cpp_149;

extern string liberalHelpOn;
extern string pressAnyKeyToReturn;

string study_string1;
string study_string2;

vector<string*> allTextString = {
	&respondsComma,
	&saysComma,
	&while_naked,
	&colonSpace,
	&pressLToViewHighScores,
	&ampersandC,
	&commaSpace,
	&findingBugs,
	&undefined,
	&NONE,
	&YEA,
	&NAY,
	&AND,
	&counts_of,
	&feels_sick_and,
	&show_squad_liberal_status,
	&change_squad_order,
	&string_sleeper,
	&execution_in_three_months,
	&major_news_take_it_up,
	&they_are_stashed,
	&they_ll_round_you_up,
	&conservativesRemakeWorld,
	&bound_to_rile_up,
	&establishPrisonReform,
	&improvePrisonConditions,
	&stalinistsRemakeWorld,
	&chooseALiberalTo,
	&youWentOnVacation,
	&youWentIntoHiding,
	&whileYouWereInPrison,
	&youDisappearedSafely,
	&proposeConservative,
	&proposeStalinist,
	&tag_creature,
	&tag_skill_experience,
	&tag_name,
	&tag_propername,
	&tag_gender_conservative,
	&tag_gender_liberal,
	&tag_squadid,
	&tag_age,
	&tag_birthday_month,
	&tag_birthday_day,
	&tag_exists,
	&tag_align,
	&tag_alive,
	&tag_type_idname,
	&tag_infiltration,
	&tag_animalgloss,
	&tag_specialattack,
	&tag_clinic,
	&tag_dating,
	&tag_hiding,
	&tag_trainingtime,
	&tag_trainingsubject,
	&tag_prisoner,
	&tag_sentence,
	&tag_confessions,
	&tag_deathpenalty,
	&tag_joindays,
	&tag_deathdays,
	&tag_id,
	&tag_hireid,
	&tag_meetings,
	&tag_forceinc,
	&tag_stunned,
	&tag_has_thrown_weapon,
	&tag_money,
	&tag_juice,
	&tag_income,
	&tag_wound,
	&tag_blood,
	&tag_special,
	&tag_crimes_suspected,
	&tag_heat,
	&tag_location,
	&tag_worklocation,
	&tag_cantbluff,
	&tag_base,
	&tag_activity,
	&tag_arg,
	&tag_arg2,
	&tag_carid,
	&tag_is_driver,
	&tag_pref_carid,
	&tag_pref_is_driver,
	&tag_flag,
	&tag_dontname,
	&enter_done,
	&beingFollowedBySwine,
	&lostThem,
	&hereTheyCome,
	&spaceDashSpace,
	&currentLocation,
	&safeHouse,
	&enemySafeHouse,
	&closedDown,
	&highSecurity,
	&needCar,
	&spaceParanthesisDollar,
	&paranthesisDollar,
	&closeParenthesis,
	&underSiege,
	&percentSign,
	&secrecyLevel,
	&heatLevel,
	&travelDifCity,
	&tag_class,
	&tag_WEAPON,
	&tag_CLIP,
	&tag_ARMOR,
	&tag_LOOT,
	&tag_type,
	&tag_description,
	&tag_price,
	&tag_sleeperprice,
	&tag_letter,
	&smellsPanic,
	&tag_Sta,
	&tag_Libp,
	&tag_Lib,
	&tag_Mod,
	&tag_Cons,
	&tag_Consp,
	&moderateLC,
	&buggyString,
	&isSeized,
	&selectA,
	&selectAn,
	&enterDash,
	&accordingToSourcesAtScene,
	&accordingToPoliceSources,
	&ampersandR,
	&singleDot,
	&membersOfLCS,
	&lcsSpokeseperson,
	&policeSpokesperson,
	&pressKeyToReflect,
	&theLCS,
	&notASkill,
	&notAnAttribute,
	&vehicleSportsCar,
	&aNewConEra,
	&theYearIs,
	&conservativePresident,
	&endsSecondTerm,
	&highSeventiesApprovePres,
	&conMajorityHouse,
	&senateConMajority,
	&beginningOfNew,
	&conEra,
	&thePresident,
	&hasAskedCongressBeQuick,
	&rubberStampArchCon,
	&theLeftSeems,
	&powerlessToStop,
	&inThisDarkTime,
	&whatIsYourName,
	&pressEnterToBeRealName,
	&invalidTag,
	&theDocSaid,
	&aBoy,
	&aGirl,
	&intersex,
	&myParents,
	&insistedOtherwise,
	&they,
	&namedMe,
	&error,
	&theFounder,
	&firstName,
	&pressAtoReconsider,
	&lastName,
	&pressBtoBeReborn,
	&sexIs,
	&male,
	&female,
	&itsComplicated,
	&pressCtoChangeSex,
	&history,
	&letMeChoose,
	&letFateDecide,
	&pressDtoToggle,
	&city,
	&pressEtoRelocate,
	&pressAnyKey,
	&allOptions,
	&unSelected,
	&isSelected,
	&pressAnyOtherKey,
	&notCreature,
	&notValidMap,
	&notSpecialWound,
	&newGameAdvanced,
	&a_classicMode,
	&b_weDidntStartIt,
	&c_nightmareMode,
	&d_nationalLCS,
	&e_marathonMode,
	&f_stalinistMode,
	&newGameYourAgenda,
	&a_noComprimise,
	&b_democrat,
	&newGameFieldLearn,
	&affectsTheseSkills,
	&a_fastSkills,
	&b_classic,
	&c_hardMode,
	&deleteSave,
	&chooseSave,
	&titleScreenLine,
	&newGame,
	&pressToSelectSave,
	&pressToDeleteSave,
	&vToSwitchXToQuit,
	&areYouSureDelte,
	&questionYSlashN,
	&pressMtoTurnOffMusic,
	&pressMtoTurnOnMusic,
	&inWhatWorld,
	&enterNameForSave,
	&pleaseEnterName,
	&prettyPlease,
	&justEnterName,
	&liberalCrimeSquad,
	&inspiredByOubliette,
	&copyrightTarn,
	&bayTwelveProductions,
	&lcsHyperlink,
	&vChar,
	&maintainedByOpenSource,
	&kingDrakeHyperlink,
	&lcsForumHyperlink,
	&lcsWikiHyperlink,
	&pressESCToQuit,
	&pressAnyKeyToPursue,
	&plusChar,
	&dotDat,
	&itemType,
	&doesNotExistItem,
	&vehicleType,
	&doesNotExistVehicle,
	&couldNotLoad,
	&itemClassClip,
	&itemClassWeapon,
	&itemClassArmor,
	&itemClassLoot,
	&itemClassMoney,
	&failedToLoadSitemaps,
	&debugCode,
	&activated,
	&failedToLoad,
	&exclamationPoint,
	&defaultMissingForMask,
	&defaultUnknownForMask,
	&ableToStopBleed,
	&sWounds,
	&isBurned,
	&drops,
	&sBody,
	&hasBeenCaughtSnooping,
	&isNowHomeless,
	&hasLeakedIntelligence,
	&hasLeakedPolice,
	&hasLeakedCorporate,
	&hasLeakedPrison,
	&hasLeakedCableNews,
	&hasLeakedAMRadio,
	&hasLeakedAnimalResearch,
	&hasLeakedJudiciary,
	&papersAreStashed,
	&hasLeakedCCS,
	&diskIsStashed,
	&arrestedWhileEmbezzling,
	&arrestedWhileStealing,
	&droppedOffPackage,
	&itemNotFound,
	&lostStolenItem,
	&contactModAuthor,
	&hasRecruited,
	&looksForwardToServing,
	&toSpend,
	&chooseAColor,
	&theseColorsAreCon,
	&thisColor,
	&notEnoughMoney,
	&chooseVehicle,
	&thisVehicle,
	&weDontNeedCar,
	&enterLeave,
	&b_chooseBuyer,
	&s_sellCar,
	&s_sellThe,
	&g_getCar,
	&f_fixWounds,
	&univer,
	&numRecruit,
	&numMartyr,
	&numKills,
	&numKidnap,
	&cashTaxed,
	&cashSpent,
	&flagsBought,
	&flagsBurned,
	&noValid,
	&heLiElite,
	&heLiLiber,
	&heLiBrought,
	&heLiBlot,
	&heLiMob,
	&heLiDownsized,
	&heLiKIA,
	&hecoReag,
	&heLiDie,
	&heLiExec,
	&heLiVaca,
	&heLiHide,
	&heLiHunted,
	&heLiScattered,
	&heLiOutCrime,
	&heLiBurned,
	&hecoStalinized,
	&dotSpace,
	&unnamed_String_Talk_cpp_000,
	&unnamed_String_Talk_cpp_001,
	&unnamed_String_Talk_cpp_002,
	&unnamed_String_Talk_cpp_003,
	&unnamed_String_Talk_cpp_004,
	&unnamed_String_Talk_cpp_005,
	&unnamed_String_Talk_cpp_006,
	&unnamed_String_Talk_cpp_007,
	&unnamed_String_Talk_cpp_008,
	&unnamed_String_Talk_cpp_009,
	&unnamed_String_Talk_cpp_010,
	&unnamed_String_Talk_cpp_011,
	&unnamed_String_Talk_cpp_012,
	&unnamed_String_Talk_cpp_013,
	&unnamed_String_Talk_cpp_014,
	&unnamed_String_Talk_cpp_015,
	&unnamed_String_Talk_cpp_016,
	&unnamed_String_Talk_cpp_017,
	&unnamed_String_Talk_cpp_018,
	&unnamed_String_Talk_cpp_019,
	&unnamed_String_Talk_cpp_020,
	&unnamed_String_Talk_cpp_021,
	&unnamed_String_Talk_cpp_022,
	&unnamed_String_Talk_cpp_023,
	&unnamed_String_Talk_cpp_024,
	&unnamed_String_Talk_cpp_025,
	&unnamed_String_Talk_cpp_026,
	&unnamed_String_Talk_cpp_027,
	&unnamed_String_Talk_cpp_028,
	&unnamed_String_Talk_cpp_029,
	&unnamed_String_Talk_cpp_030,
	&unnamed_String_Talk_cpp_031,
	&unnamed_String_Talk_cpp_032,
	&unnamed_String_Talk_cpp_033,
	&unnamed_String_Talk_cpp_034,
	&unnamed_String_Talk_cpp_035,
	&unnamed_String_Talk_cpp_036,
	&unnamed_String_Talk_cpp_037,
	&unnamed_String_Talk_cpp_038,
	&unnamed_String_Talk_cpp_039,
	&unnamed_String_Talk_cpp_040,
	&unnamed_String_Talk_cpp_041,
	&unnamed_String_Talk_cpp_042,
	&unnamed_String_Talk_cpp_043,
	&unnamed_String_Talk_cpp_044,
	&unnamed_String_Talk_cpp_045,
	&unnamed_String_Talk_cpp_046,
	&unnamed_String_Talk_cpp_047,
	&unnamed_String_Talk_cpp_048,
	&unnamed_String_Talk_cpp_049,
	&unnamed_String_Talk_cpp_050,
	&unnamed_String_Talk_cpp_051,
	&unnamed_String_Talk_cpp_052,
	&unnamed_String_Talk_cpp_053,
	&unnamed_String_Talk_cpp_054,
	&unnamed_String_Talk_cpp_055,
	&unnamed_String_Talk_cpp_056,
	&unnamed_String_Talk_cpp_057,
	&unnamed_String_Talk_cpp_058,
	&unnamed_String_Talk_cpp_059,
	&unnamed_String_Talk_cpp_060,
	&unnamed_String_Talk_cpp_061,
	&unnamed_String_Talk_cpp_062,
	&unnamed_String_Talk_cpp_063,
	&unnamed_String_Talk_cpp_064,
	&unnamed_String_Talk_cpp_065,
	&unnamed_String_Talk_cpp_066,
	&unnamed_String_Talk_cpp_067,
	&unnamed_String_Talk_cpp_068,
	&unnamed_String_Talk_cpp_069,
	&unnamed_String_Talk_cpp_070,
	&unnamed_String_Talk_cpp_071,
	&unnamed_String_Talk_cpp_072,
	&unnamed_String_Talk_cpp_073,
	&unnamed_String_Talk_cpp_074,
	&unnamed_String_Talk_cpp_075,
	&unnamed_String_Talk_cpp_076,
	&unnamed_String_Talk_cpp_077,
	&unnamed_String_Talk_cpp_078,
	&unnamed_String_Talk_cpp_079,
	&unnamed_String_Talk_cpp_080,
	&unnamed_String_Talk_cpp_081,
	&unnamed_String_Talk_cpp_082,
	&unnamed_String_Talk_cpp_083,
	&unnamed_String_Talk_cpp_084,
	&unnamed_String_Talk_cpp_085,
	&unnamed_String_Talk_cpp_086,
	&unnamed_String_Talk_cpp_087,
	&unnamed_String_Talk_cpp_088,
	&unnamed_String_Talk_cpp_089,
	&unnamed_String_Talk_cpp_090,
	&unnamed_String_Talk_cpp_091,
	&unnamed_String_Talk_cpp_092,
	&unnamed_String_Talk_cpp_093,
	&unnamed_String_Talk_cpp_094,
	&unnamed_String_Talk_cpp_095,
	&unnamed_String_Talk_cpp_096,
	&unnamed_String_Talk_cpp_097,
	&unnamed_String_Talk_cpp_098,
	&unnamed_String_Talk_cpp_099,
	&unnamed_String_Talk_cpp_100,
	&unnamed_String_Talk_cpp_101,
	&unnamed_String_Talk_cpp_102,
	&unnamed_String_Talk_cpp_103,
	&unnamed_String_Talk_cpp_104,
	&unnamed_String_Talk_cpp_105,
	&unnamed_String_Talk_cpp_106,
	&unnamed_String_Talk_cpp_107,
	&unnamed_String_Talk_cpp_108,
	&unnamed_String_Talk_cpp_109,
	&unnamed_String_Talk_cpp_110,
	&unnamed_String_Talk_cpp_111,
	&unnamed_String_Talk_cpp_112,
	&unnamed_String_Talk_cpp_113,
	&unnamed_String_Talk_cpp_114,
	&unnamed_String_Talk_cpp_115,
	&unnamed_String_Talk_cpp_116,
	&unnamed_String_Talk_cpp_117,
	&unnamed_String_Talk_cpp_118,
	&unnamed_String_Talk_cpp_119,
	&unnamed_String_Talk_cpp_120,
	&unnamed_String_Talk_cpp_121,
	&unnamed_String_Talk_cpp_122,
	&unnamed_String_Talk_cpp_123,
	&unnamed_String_Talk_cpp_124,
	&unnamed_String_Talk_cpp_125,
	&unnamed_String_Talk_cpp_126,
	&unnamed_String_Talk_cpp_127,
	&unnamed_String_Talk_cpp_128,
	&unnamed_String_Talk_cpp_129,
	&unnamed_String_Talk_cpp_130,
	&unnamed_String_Talk_cpp_131,
	&unnamed_String_Talk_cpp_132,
	&unnamed_String_Talk_cpp_133,
	&unnamed_String_Talk_cpp_134,
	&unnamed_String_Talk_cpp_135,
	&unnamed_String_Talk_cpp_136,
	&unnamed_String_Talk_cpp_137,
	&unnamed_String_Talk_cpp_138,
	&unnamed_String_Talk_cpp_139,
	&unnamed_String_Talk_cpp_140,
	&unnamed_String_Talk_cpp_141,
	&unnamed_String_Talk_cpp_142,
	&unnamed_String_Talk_cpp_143,
	&unnamed_String_Talk_cpp_144,
	&unnamed_String_Talk_cpp_145,
	&unnamed_String_Talk_cpp_146,
	&unnamed_String_Talk_cpp_147,
	&unnamed_String_Talk_cpp_148,
	&unnamed_String_Talk_cpp_149,
	&liberalHelpOn,
	&pressAnyKeyToReturn,
		&study_string1,
		&study_string2,
};
bool initialize_incomplete_txt();
bool initialize_incomplete_txt() {
	int i = 0;
	singleSpace = " "; allText[i++];
	check_status_of_squad_liberal = "# " + allText[i++];
	for (string* str : allTextString) {
		*str = allText[i++];
	}
	return i == len(allText);
}

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