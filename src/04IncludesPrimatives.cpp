using namespace std;
#include <includes.h>
#include <queue>
#include <map>
#include <customMaps.h>
extern vector<Creature *> pool;
extern Log gamelog;
extern vector<Location *> location;
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
// IsaacG: This is the crown jewel of my additions to LCS
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
};

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

bool initialize_incomplete_txt();
bool initialize_incomplete_txt() {
	singleSpace = " ";
	respondsComma = " responds, ";
	saysComma = " says, ";
	while_naked = " while naked";
	colonSpace = ": ";
	pressLToViewHighScores = "Press 'L' to view the high score list.";
	ampersandC = "&c";
	commaSpace = ", ";
	// From chase.cpp
	carchase_obstacle_none = {
		"D - Try to lose them!",
		"E - Equip",
		"F - Fight!"
	};
	carchase_obstacle_fruit_stand = {
		"You are speeding toward a flimsy fruit stand!",
		"D - Swerve to avoid hitting anyone!",
		"F - Play it safe and plow through it!"
	};
	carchase_obstacle_truck_pulls_out = {
		"A truck pulls out in your path!",
		"D - Speed around it!",
		"F - Slow down!"
	};
	carchase_obstacle_cross_traffic = {
		"There's a red light with cross traffic ahead!",
		"D - Run the light anyway!",
		"F - Slow down and turn!"
	};
	carchase_obstacle_child = {
		"A kid runs into the street for his ball!",
		"D - Swerve around him!",
		"F - Slam the brakes!"
	};/*
	missedDriver = {
		// These are kept in an exact order, corresponds to rolling
		// somewhere from a 0 to an 18,
		// The method that uses this treats all out of bounds indices
		// as 0
		" misses completely!",
		" missed!",
		" just barely missed!",
		" can't seem to keep the vehicle in either the lane or the line of fire!",
		" swerves randomly!",
		" cuts off another driver and the shot is blocked!",
		" drops behind a hill in the road!",
		" changes lanes at the last second!",
		" accelerates suddenly and the shot goes short!",
		" fakes a left, and goes right instead!",
		" fakes a right, and goes left instead!",
		" fakes with the brakes while powering ahead!",
		" swerves to the other side of a truck!",
		" weaves through a row of taxis!",
		" dodges behind a hot dog cart!",
		" squeezes between some bridge supports for cover!",
		" squeals around a corner and behind a building!",
		" power slides through a narrow gap in the traffic!",
		" rolls the car onto two wheels to dodge the shot!"
	};
	missedPedestrian = {
		// These are kept in an exact order, corresponds to rolling
		// somewhere from a 0 to an 18,
		// The method that uses this treats all out of bounds indices
		// as 0
		" misses completely!",
		" missed!",
		" just barely missed!",
		" tumbles out of the way!",
		" jumps aside at the last moment!",
		" leaps for cover!",
		" ducks back behind cover!",
		" wisely stays behind cover!",
		" rolls away from the attack!",
		" nimbly dodges away from the line of fire!",
		" leaps over the attack!",
		" gracefully dives to avoid the attack!",
		" twists to avoid the attack!",
		" spins to the side!",
		" does the Matrix-dodge!",
		" avoids the attack with no difficulty at all!",
		" flexes slightly to avoid being hit!",
		" confidently allows the attack to miss!",
		" seems to avoid the attack with only an angry glare!"
	};
	handToHandStrike = {
		// These are kept in an exact order, corresponds to rolling
		// repeated successes of greater difficulty
		// This can be made arbitrarily long, it is purely
		// cosmetic
		"punches",
		"swings at",
		"grapples with",
		"kicks",
		"strikes at",
		"jump kicks",
		"gracefully strikes at"
	};*/
	personalAds =
	{
		// less explicit personals in regular newspaper than Liberal Guardian
		"Searching For Love",
		"Seeking Love",
		"Are You Lonely?",
		"Looking For Love",
		"Soulmate Wanted"
	};
	personalAdsLG = {
		// more explicit personals in Liberal Guardian than regular newspaper
		"Searching For Sex",
		"Seeking Sex",
		"Wanna Have Sex?",
		"Looking For Sex",
		"Sex Partner Wanted"
	};
	/* pick a descriptor acronym */
	sexdescAcronym = {
		"DTE",
		"ND",
		"NS",
		"VGL"//,
			 //"FOO"
	};
	/* what kind of person? */
	sexwhoAcronym = {
		"BB",
		"BBC",
		"BF",
		"BHM",
		"BiF",
		"BiM",
		"BBW",
		"BMW",
		"CD",
		"DWF",
		"DWM",
		"FTM",
		"GAM",
		"GBM",
		"GF",
		"GG",
		"GHM",
		"GWC",
		"GWF",
		"GWM",
		"MBC",
		"MBiC",
		"MHC",
		"MTF",
		"MWC",
		"SBF",
		"SBM",
		"SBiF",
		"SBiM",
		"SSBBW",
		"SWF",
		"SWM",
		"TG",
		"TS",
		"TV"//,
			//"BAR"
	};
	/* seeking acronym */
	sexseekAcronym = {
		"ISO",
		"LF"//,
			//"BAZ"
	};
	/* what type of sex? */
	sextypeAcronym = {
		"225",
		"ATM",
		"BDSM",
		"CBT",
		"BJ",
		"DP",
		"D/s",
		"GB",
		"HJ",
		"OTK",
		"PNP",
		"TT",
		"SWS",
		"W/S"//,
			 //"LOL"
	};
	vehicleParagraph = {
		"Press a letter to specify passengers for that Liberal vehicle",
		"Capitalize the letter to designate a driver.",
		"Press a number to remove that squad member from a vehicle.",
		"Note:  Vehicles in yellow have already been selected by another squad",
		"       Vehicles in red have been selected by both this squad and another",
		"       These cars may be used by both squads but not on the same day.",
		"Enter - Done"
	};
	caseBUSINESSFRONT_INSURANCE =
	{
		"Auto Insurance",
		"Auto Ins.",
		"Life Insurance",
		"Life Ins.",
		"Health Insurance",
		"Health Ins.",
		"Home Insurance",
		"Home Ins.",
		"Boat Insurance",
		"Boat Ins.",
		"Fire Insurance",
		"Fire Ins.",
		"Flood Insurance",
		"Flood Ins."
	};
	caseBUSINESSFRONT_TEMPAGENCY =
	{
		"Temp Agency",
		"Agency",
		"Manpower, LLC",
		"Manpower",
		"Staffing, Inc",
		"Staff",
		"Labor Ready",
		"Labor",
		"Employment",
		"Employ",
		"Services",
		"Services",
		"Solutions",
		"Solutns"
	};
	caseBUSINESSFRONT_RESTAURANT =
	{
		"Fried Chicken",
		"Chicken",
		"Hamburgers",
		"Burgers",
		"Steakhouse",
		"Steak",
		"Wok Buffet",
		"Wok",
		"Thai Cuisine",
		"Thai",
		"Pizzeria",
		"Pizza",
		"Fine Dining",
		"Diner"
	};
	caseBUSINESSFRONT_MISCELLANEOUS =
	{
		"Real Estate",
		"Realty",
		"Imported Goods",
		"Import",
		"Waste Disposal",
		"Disposal",
		"Liquor Shop",
		"Liquor",
		"Antiques",
		"Antique",
		"Repair, Inc",
		"Repair",
		"Pet Store",
		"Pets"
	};
	caseNEWSSTORY_CCS_DEFEATED = {
		"An elite FBI force conducted simultaneous ",
		"raids on several suspected Conservative Crime Squad safehouses in the early hours. Despite resistance from ",
		"CCS terrorists armed with automatic weapons and body armor, no FBI agents were killed in the raids, and all ",
		"three raids were successful. Seventeen suspects were killed in the fighting, and twenty-three are ",
		"now in custody.",
		"&r",
		"  The Conservative Crime Squad fell on hard times when the alternative newspaper Liberal Guardian published ",
		"1147 pages of documents showing extensive government support for the group. The ensuing scandal ",
		"led to the arrest of twenty-five members of Congress, as well as several leadership figures in the ",
		"Conservative Party's National Committee.",
		"&r",
		"  \"I want parents to rest easy tonight,\" FBI Chief ",
		"Roberta T. Malton said during a news conference to announce the raids.  \"You don't need the Liberal Crime Squad ",
		"to protect you. The Government can handle it.\"",
		"&r"
	};
	caseNEWSSTORY_CCS_NOBACKERS = {
		"The FBI investigation into the Conservative Crime Squad's government connections has led to the arrest of more than ",
		"a dozen elected officials and revealed extensive corruption in law enforcement.",
		"&r",
		"  \"The uphevals in the police force, and arrest of corrupt officials, are only the beginning,\" FBI Chief ",
		"Roberta T. Malton said during a news conference.  \"A major focus ",
		"of our efforts will be on the complete destruction of the Conservative Crime Squad. Within six months, we'll have their ",
		"entire leadership, dead or alive. I personally guarantee it.\"",
		"&r"
	};
	/* pick a random state, or give the name of the specified state */
	listOfStates = {
		"Alabama",
		"Alaska",
		"Arkansas",
		"Arizona",
		"California",
		"Colorado",
		"Connecticut",
		"Delaware",
		"Florida",
		"Georgia",
		"Hawaii",
		"Idaho",
		"Illinois",
		"Indiana",
		"Iowa",
		"Kansas",
		"Kentucky",
		"Louisiana",
		"Maine",
		"Maryland",
		"Massachusetts",
		"Michigan",
		"Minnesota",
		"Mississippi",
		"Missouri",
		"Montana",
		"Nebraska",
		"Nevada",
		"New Hampshire",
		"New Jersey",
		"New Mexico",
		"New York",
		"North Carolina",
		"North Dakota",
		"Ohio",
		"Oklahoma",
		"Oregon",
		"Pennsylvania",
		"Rhode Island",
		"South Carolina",
		"South Dakota",
		"Tennessee",
		"Texas",
		"Utah",
		"Vermont",
		"Virginia",
		"Washington",
		"West Virginia",
		"Wisconsin",
		"Wyoming"
		// "Hohoq"; // The Areas of My Expertise -- John Hodgman
	};
	nextSiege = {
		"     You are about to exit the compound to lift the Conservative",
		"siege on your safehouse.  The enemy is ready for you, and",
		"you will have to defeat them all or run away to survive this",
		"encounter."
	};
	nextSiegeAgain = {
		"Your Squad has filled out to six members if any were ",
		"available.  If you have a larger pool of Liberals, they",
		"will provide cover fire from the compound until needed."
	};
	engageConservatives = {
		"     You are about to engage Conservative forces in battle.",
		"You will find yourself in the Liberal safehouse, and it will",
		"be swarming with Conservative units.  The Liberal Crime",
		"Squad will be located far from the entrance to the safehouse.",
		"It is your task to bring your squad out to safety, or fight",
		"off the Conservatives within the perimeter.  Either way you",
		"choose, any equipment from the safehouse which isn't held by a",
		"Liberal will be scattered about the compound.  Save what",
		"you can.  You might notice your Squad has filled out to",
		"six members if any were available.  If you have a larger pool",
		"of Liberals, they will be traveling behind the Squad.",
		"There is a new button, (R)eorganize, which reflects this.",
		"Squad members in the back with firearms can provide cover",
		"fire.  If you have at least six people total, then six must",
		"be in the Squad.  If less than six, then they all must."
	};
	engageConservativesEscape = {
		"     The Conservatives thought that the Liberal Crime Squad was",
		"finished, but once again, Conservative Thinking has proven",
		"itself to be based on Unsound Notions.",
		"However, all is not well.  In your haste to escape you have",
		"lost everything that you've left behind.  You'll have",
		"to start from scratch in a new safe house.  Your",
		"funds remain under your control, fortunately.  Your flight has",
		"given you some time to regroup, but the Conservatives will",
		"doubtless be preparing another assault."
	};
	methodOfExecution = {
		"strangling to death.                                              ", // 66 characters (10+4+66=80)
		"beating to death.                                                 ", // 66 characters (10+4+66=80)
		"cold execution.                                                   " // 66 characters (10+4+66=80)
	};
	getsSick = {
		"throws up in a trash can.                                                       ",  // 80 characters
		"gets drunk, eventually falling asleep.                                          ",  // 80 characters
		"curls up in a ball, crying softly.                                              ",  // 80 characters
		"shoots up and collapses in a heap on the floor.                                 "  // 80 characters
	};
	corporateSuffix = {
		", Inc.",
		", L.L.C.",
		" Corp.",
		" Co.",
		", Ltd."
	};
	rejectedByCCS = {
		"\"Can I see... heh heh... some ID?\"",
		"\"Woah... you think you're coming in here?\"",
		"\"Check out this fool. Heh.\"",
		"\"Want some trouble, dumpster breath?\"",
		"\"You're gonna stir up the hornet's nest, fool.\"",
		"\"Come on, take a swing at me. Just try it.\"",
		"\"You really don't want to fuck with me.\"",
		"\"Hey girly, have you written your will?\"",
		"\"Oh, you're trouble. I *like* trouble.\"",
		"\"I'll bury you in those planters over there.\"",
		"\"Looking to check on the color of your blood?\""
	};
	rejectedBecauseNude = {
		"\"No shirt, no underpants, no service.\"",
		"\"Put some clothes on! That's disgusting.\"",
		"\"No! No, you can't come in naked! God!!\"",
		"\"No shoes, no shirt and you don't get service\""
	};
	rejectedBecauseUnderage = {
		"\"Hahaha, come back in a few years.\"",
		"\"Find some kiddy club.\"",
		"\"You don't look 18 to me.\"",
		"\"Go back to your treehouse.\"",
		"\"Where's your mother?\""
	};
	rejectedBecauseFemale = {
		"\"Move along ma'am, this club's for men.\"",
		"\"This 'ain't no sewing circle, ma'am.\"",
		"\"Sorry ma'am, this place is only for the men.\"",
		"\"Where's your husband?\""
	};
	rejectedBecauseFemaleish = {
		"\"You /really/ don't look like a man to me...\"",
		"\"Y'know... the \'other\' guys won't like you much.\"",
		"\"Uhh... can't let you in, ma'am. Sir. Whatever.\""
	};
	rejectedBecauseDresscode = {
		"\"Check the dress code.\"",
		"\"We have a dress code here.\"",
		"\"I can't let you in looking like that.\""
	};
	rejectedBecauseSmellFunny = {
		"\"God, you smell.\"",
		"\"Not letting you in. Because I said so.\"",
		"\"There's just something off about you.\"",
		"\"Take a shower.\"",
		"\"You'd just harass the others, wouldn't you?\""
	};
	rejectedBecauseBloodyClothes = {
		"\"Good God! What is wrong with your clothes?\"",
		"\"Absolutely not. Clean up a bit.\"",
		"\"This isn't a goth club, bloody clothes don't cut it here.\"",
		"\"Uh, maybe you should wash... replace... those clothes.\"",
		"\"Did you spill something on your clothes?\"",
		"\"Come back when you get the red wine out of your clothes.\""
	};
	rejectedBecauseDamagedClothes = {
		"\"Good God! What is wrong with your clothes?\"",
		"\"This isn't a goth club, ripped clothes don't cut it here.\""
	};
	rejectedBecauseSecondRateClothes = {
		"\"That looks like you sewed it yourself.\"",
		"\"If badly cut clothing is a hot new trend, I missed it.\""
	};
	rejectedBecauseWeapons = {
		"\"No weapons allowed.\"",
		"\"I can't let you in carrying that.\"",
		"\"I can't let you take that in.\"",
		"\"Come to me armed, and I'll tell you to take a hike.\"",
		"\"Real men fight with fists. And no, you can't come in.\""
	};
	rejectedBecauseGuestList = {
		"\"This club is by invitation only.\""
	};
	notRejected = {
		"\"Keep it civil and don't drink too much.\"",
		"\"Let me get the door for you.\"",
		"\"Ehh, alright, go on in.\"",
		"\"Come on in.\""
	};
	randomCrime = {
		"murder",
		"assault",
		"theft",
		"mugging",
		"burglary",
		"property destruction",
		"vandalism",
		"libel",
		"slander",
		"sodomy",
		"obstruction of justice",
		"breaking and entering",
		"public indecency",
		"arson",
		"resisting arrest",
		"tax evasion"
	};
	caseREJECTED_NUDE =
	{
		"\"Get out of here you nudist!!\"",
		"\"Back off, creep!\"",
		"\"Jesus!! Somebody call the cops!\"",
		"\"Are you sleepwalking?!\""
	};
	caseREJECTED_UNDERAGE =
	{
		"\"No admittance, youngster.\"",
		"\"You're too young to work here.\"",
		"\"Go play someplace else.\"",
		"\"Where's your mother?\""
	};
	caseREJECTED_DRESSCODE =
	{
		"\"Employees only.\""
	};
	caseREJECTED_SMELLFUNNY =
	{
		"\"You don't work here, do you?\"",
		"\"Hmm... can I see your badge?\"",
		"\"There's just something off about you.\"",
		"\"You must be new. You'll need your badge.\""
	};
	caseREJECTED_BLOODYCLOTHES =
	{
		"\"Good God! What is wrong with your clothes?\"",
		"\"Are you hurt?! The aid station is the other way!\"",
		"\"Your clothes, that's blood!\"",
		"\"Blood?! That's more than a little suspicious...\"",
		"\"Did you just butcher a cat?!\"",
		"\"Blood everywhere...?\""
	};
	caseREJECTED_DAMAGEDCLOTHES =
	{
		"\"Good God! What is wrong with your clothes?\"",
		"\"Is that a damaged halloween costume?\""
	};
	caseREJECTED_SECONDRATECLOTHES =
	{
		"\"That looks like you sewed it yourself.\"",
		"\"That's a poor excuse for a uniform. Who are you?\""
	};
	caseREJECTED_WEAPONS =
	{
		"\"Put that away!\"",
		"\"Hey, back off!\"",
		"\"Don't try anything!\"",
		"\"Are you here to make trouble?\"",
		"\"Stay back!\""
	};
	caseNOT_REJECTED =
	{
		"\"Move along.\"",
		"\"Have a nice day.\"",
		"\"Quiet day, today.\"",
		"\"Go on in.\""
	};
	stalinAmendment = {
		"     In recognition of the fact that the proletariat is being exploited",
		"by bourgeoisie faux-leftist liberal elites, WE THE PEOPLE HEREBY",
		"REPEAL THE CONSTITUTION.  The former United States are to be",
		"reorganized into the PEOPLE'S REPUBLIC OF AMERICA, with new",
		"boundaries to be determined by leading Stalinist philosophers.",
		"",
		"Josef Stalin is General Secretary and Premier, forever, even after death.",
		"",
		"The following Politburo Commissars are also chosen in perpetuity:",
		"People's Commissar for Foreign Affairs Vyacheslav Molotov",
		"and People's Commissar for Internal Affairs Lavrentiy Beria.",
		"",
		"In the event of the deaths of any of the aforementioned",
		"persons, though they shall still nominally hold these posts,",
		"actual decisions shall be made by Stalinist Party leaders,",
		"chosen by Stalinist Party loyalists.",
		"",
		"Anyone attempting to petition for redress of grievances will be sent",
		"to a gulag in newly annexed Canada or, if you're lucky, executed.",
		"",
		"Have a nice day."
	};
	archConservativeAmendment = {
		"     In recognition of the fact that society is degenerating under",
		"the pressure of the elite liberal threat, WE THE PEOPLE HEREBY",
		"REPEAL THE CONSTITUTION.  The former United States are to be",
		"reorganized into the CONFEDERATED STATES OF AMERICA, with new",
		"boundaries to be determined by leading theologians.",
		"",
		"Ronald Reagan is to be King, forever, even after death.",
		"",
		"The following Executive Officers are also chosen in perpetuity:",
		"Minister of Love Strom Thurmond, Minister of Peace Jesse Helms,",
		"and Minister of Truth Jerry Falwell.",
		"",
		"In the event of the deaths of any of the aforementioned",
		"persons, though they shall still nominally hold these posts,",
		"actual decisions shall be made by business representatives,",
		"chosen by respected business leaders.",
		"",
		"People may petition Jesus for a redress of grievances, as",
		"He will be the only one listening.",
		"",
		"Have a nice day."
	};
	amendmentPass = {
		"     In light of the Conservative nature of entrenched politicians,",
		"and the corrupting influence of incumbency on the democratic process,",
		"all members of the House of Representatives and Senate shall henceforth",
		"be limited to one term in office.  This shall be immediately enforced",
		"by holding elections to replace all members of Congress upon the",
		"ratification of this amendment."
	};
	evasionStrings = {
		" tumbles out of the way!",
		" jumps aside at the last moment!",
		" leaps for cover!",
		" ducks back behind cover!",
		" wisely stays behind cover!",
		" rolls away from the attack!",
		" nimbly dodges away from the line of fire!",
		" leaps over the attack!",
		" gracefully dives to avoid the attack!",
		" twists to avoid the attack!",
		" spins to the side!",
		" does the Matrix-dodge!", // You saying I can dodge bullets?
		" avoids the attack with no difficulty at all!",
		" flexes slightly to avoid being hit!",
		" confidently allows the attack to miss!",
		" seems to avoid the attack with only an angry glare!"//When you're ready, you won't have to.
	};
	evasionStringsAlt = {
		" can't seem to keep the vehicle in either the lane or the line of fire!",
		" swerves randomly!",
		" cuts off another driver and the shot is blocked!",
		" drops behind a hill in the road!",
		" changes lanes at the last second!",
		" accelerates suddenly and the shot goes short!",
		" fakes a left, and goes right instead!",
		" fakes a right, and goes left instead!",
		" fakes with the brakes while powering ahead!",
		" swerves to the other side of a truck!",
		" weaves through a row of taxis!",
		" dodges behind a hot dog cart!",
		" squeezes between some bridge supports for cover!",
		" squeals around a corner and behind a building!",
		" power slides through a narrow gap in the traffic!",
		" rolls the car onto two wheels to dodge the shot!"
	};
	disbandingMessage = {
		"Disbanding scatters the Liberal Crime Squad, sending all of its members",
		"into hiding, free to pursue their own lives.  You will be able to observe",
		"the political situation in brief, and wait until a resolution is reached.",
		"",
		"If at any time you determine that the Liberal Crime Squad will be needed",
		"again, you may return to the homeless shelter to restart the campaign.",
		"",
		"Do not make this decision lightly.  If you do need to return to action,",
		"only the most devoted of your former members will return."
	};

	// The (current) issue that the masses are most
	// concerned should be (slightly) more likely
	// to be the phrase. (Issue, not the CCS, etc.)
	issue_phrases =    //    -- LK
	{  /////////////////////////////////////////////////////////////////////////////////////////
	   // Liberal Phrase           // Conservative Equivalent  // Stalinist Equivalent        //
	   /////////////////////////////////////////////////////////////////////////////////////////
		"Corporate Accountability", // Deregulation             // Nationalized Industry       //
		"Free Speech",              // Child Safety             // Ideological Purity          //
		"Gay Marriage",             // Sanctity of Marriage     // Bourgeoisie Decadence       //
		"Abortion Rights",          // Right to Life            // Population Control          //
		"Separation Clause",        // Under God                // Opiate of the Masses        //
		"Racial Equality",          // Emmett Till              // Kulaks                      //
		"Gun Control",              // Second Amendment         // Firing Squad                //
		"Campaign Finance Reform",  // Freedom to Campaign      // People's Republic           //
		"Animal Rights",            // Animal Abuse             // Capitalist Pig-Dogs         //
		"Worker's Rights",          // Right to Work            // Canadian Gulags             //
		"Police Responsibility",    // Rodney King              // Secret Police               // /* XXX: "Civilian" Police (Note to self) -- LK */
		"Global Warming",           // Self-Regulation          // Five-Year Plan              //
		"Immigration Reform",       // Border Control           // Iron Curtain                // /* XXX: "Nicer" Term (Note to self) -- LK */
		"Human Rights",             // National Security        // Reeducation                 // /* XXX: 2+2 = 5? (Note to self) -- LK */
		"Woman's Suffrage",         // Traditional Gender Roles // Honey Trap                  //
		"Right To Privacy",         // Wiretapping              // Stasi                       //
		"Medical Marijuana",        // War on Drugs             // Vodka                       //
		"Flag Burning",             // Patriotism               // Hammer and Sickle           // /* XXX: Towards the beginning of 1984, at Winston's job. (Note to self) -- LK */
		"Life Imprisonment",        // Zero Tolerance           // Mass Grave                  //
		"Conflict Resolution",      // Preemptive Strike        // Mutual Assured Destruction  //
		"Radiation Poisoning",      // Nuclear Power            // Chernobyl                   //
		"Tax Bracket"               // Flat Tax                 // Proletariat                 //
	}; /////////////////////////////////////////////////////////////////////////////////////////
	adList = {
		{ "&cNo Fee&r",
		"&cConsignment Program&r&r",
		"&cCall for Details&r" },
		{ "&cParis Flea Market&r&r",
		"&cSale&r",
		"&c50% Off&r" },
		{ "&cSpa&r",
		"&cHealth, Beauty&r",
		"&cand Fitness&r&r",
		"&c7 Days a Week&r" },
		{ "&cDebuggers Needed&r&r",
		"&cIt Seems&r",
		"&cYou've Found&r",
		"&cA Bug!&r" }
	};
	adListB = {
		{ "&cWant Organic?&r&r",
		"&cVisit The Vegan&r",
		"&cCo-Op&r" },
		{ "&cAbortion Clinic&r&r",
		"&cWalk-in, No&r",
		"&cQuestions Asked&r",
		"&cOpen 24/7&r" },
		{ "&cMarijuana Dispensary&r&r",
		"&cNo ID Or Prescription Needed!&r",
		"&cPlease Pay In Cash.&r" },
		{ "&cGot Slack?&r&r",
		"&cVisit Your Local&r",
		"&cSubGenius Clench&r",
		"&cFor More Info&r" },
		{ "&cDebuggers Needed&r&r",
		"&cIt Seems&r",
		"&cYou've Found&r",
		"&cA Bug!&r" }
	};
	methodOfSorting = {
		"A - No sorting.",
		"B - Sort by name.",
		"C - Sort by location and name.",
		"D - Sort by squad or name."
	};
	getMonth = {
		"Jan." , "January",
		"Feb." , "February",
		"Mar." , "March",
		"Apr." , "April",
		"May", "May",
		"June", "June",
		"July", "July",
		"Aug." , "August",
		"Sep." , "September",
		"Oct." , "October",
		"Nov." , "November",
		"Dec." , "December",
		"Bug." , "Bugtober",
	};
	conservativePrison = {
		"Your kind are never released these days.",
		"Ain't no sunshine..."
	};
	stalinistPrison = {
		"You've been shipped off to a gulag in newly annexed Canada...",
		"Ain't no sunshine in this frozen tundra..."
	};
	reaganifiedCabinet =
	{ "Ronald Reagan",
		"Strom Thurmond",
		"Jesse Helms",
		"Jerry Falwell", };
	stalinizedCabinet =
	{ "Josef Stalin",
		"Josef Stalin",
		"Vyacheslav Molotov",
		"Lavrentiy Beria", };
	findingBugs = "Finding bugs";
	undefined = "UNDEFINED";
	NONE = "NONE";
	YEA = " Yea";
	NAY = " Nay";
	AND = " and ";
	counts_of = " counts of ";
	feels_sick_and = " feels sick to the stomach afterward and ";
	check_status_of_squad_liberal = "#   - Check the status of a squad Liberal";
	show_squad_liberal_status = "0 - Show the squad's Liberal status";
	change_squad_order = "O - Change the squad's Liberal order";
	string_sleeper = "Sleeper ";
	execution_in_three_months = "The execution is scheduled to occur three months from now.";
	major_news_take_it_up = "The major networks and publications take it up and run it for weeks.";
	they_are_stashed = "They are stashed at the homeless shelter.";
	they_ll_round_you_up = "They'll round up the last of you up eventually.  All is lost.";
	conservativesRemakeWorld = "The Conservatives have made the world in their image.";
	bound_to_rile_up = "This is bound to get the Corporations a little riled up.";
	establishPrisonReform = "Establish Prison Rehabilitation";
	improvePrisonConditions = "Improve Prison Conditions";
	stalinistsRemakeWorld = "The Stalinists have made the world in their image.";
	chooseALiberalTo = "Choose a Liberal squad member to ";
	youWentOnVacation = "You went on vacation when the country was on the verge of collapse.";
	youWentIntoHiding = "You went into hiding when the country was on the verge of collapse.";
	whileYouWereInPrison = "While you were on the inside, the country degenerated...";
	youDisappearedSafely = "You disappeared safely, but you hadn't done enough.";

	proposeConservative = "The Arch-Conservative Congress is proposing an ARCH-CONSERVATIVE AMENDMENT!";
	proposeStalinist = "The Stalinist Congress is proposing a STALINIST AMENDMENT!";

	tag_creature = "creature";
	tag_skill_experience = "skill_experience";
	tag_name = "name";
	tag_propername = "propername";
	tag_gender_conservative = "gender_conservative";
	tag_gender_liberal = "gender_liberal";
	tag_squadid = "squadid";
	tag_age = "age";
	tag_birthday_month = "birthday_month";
	tag_birthday_day = "birthday_day";
	tag_exists = "exists";
	tag_align = "align";
	tag_alive = "alive";
	tag_type_idname = "type_idname";
	tag_infiltration = "infiltration";
	tag_animalgloss = "animalgloss";
	tag_specialattack = "specialattack";
	tag_clinic = "clinic";
	tag_dating = "dating";
	tag_hiding = "hiding";
	tag_trainingtime = "trainingtime";
	tag_trainingsubject = "trainingsubject";
	tag_prisoner = "prisoner";
	tag_sentence = "sentence";
	tag_confessions = "confessions";
	tag_deathpenalty = "deathpenalty";
	tag_joindays = "joindays";
	tag_deathdays = "deathdays";
	tag_id = "id";
	tag_hireid = "hireid";
	tag_meetings = "meetings";
	tag_forceinc = "forceinc";
	tag_stunned = "stunned";
	tag_has_thrown_weapon = "has_thrown_weapon";
	tag_money = "money";
	tag_juice = "juice";
	tag_income = "income";
	tag_wound = "wound";
	tag_blood = "blood";
	tag_special = "special";
	tag_crimes_suspected = "crimes_suspected";
	tag_heat = "heat";
	tag_location = "location";
	tag_worklocation = "worklocation";
	tag_cantbluff = "cantbluff";
	tag_base = "base";
	tag_activity = "activity";
	tag_arg = "arg";
	tag_arg2 = "arg2";
	tag_carid = "carid";
	tag_is_driver = "is_driver";
	tag_pref_carid = "pref_carid";
	tag_pref_is_driver = "pref_is_driver";
	tag_flag = "flag";
	tag_dontname = "dontname";
	enter_done = "Enter - Done";
	beingFollowedBySwine = "being followed by Conservative swine!";
	lostThem = "It looks like you've lost them!";
	hereTheyCome = "Here they come!";
	spaceDashSpace = " - ";
	currentLocation = " (Current Location)";
	safeHouse = " (Safe House)";
	enemySafeHouse = " (Enemy Safe House)";
	closedDown = " (Closed Down)";
	highSecurity = " (High Security)";
	needCar = " (Need Car)";
	spaceParanthesisDollar = " ($";
	paranthesisDollar = "($";
	closeParenthesis = ")";
	underSiege = " (Under Siege)";
	percentSign = "%";
	secrecyLevel = "Secrecy: ";
	heatLevel = "Heat: ";
	travelDifCity = " - Travel to a Different City";
	tag_class = "class";
	tag_WEAPON = "WEAPON";
	tag_CLIP = "CLIP";
	tag_ARMOR = "ARMOR";
	tag_LOOT = "LOOT";
	tag_type = "type";
	tag_description = "description";
	tag_price = "price";
	tag_sleeperprice = "sleeperprice";
	tag_letter = "letter";
	smellsPanic = "The Squad smells Conservative panic.";
	tag_Sta = "Sta, ";
	tag_Libp = "Lib+, ";
	tag_Lib = "Lib, ";
	tag_Mod = "Mod, ";
	tag_Cons = "Cons, ";
	tag_Consp = "Cons+";

	moderateLC = "moderate";
	buggyString = "Buggy";


	isSeized = " is seized, ";

	selectA = "Press a Letter to select a ";
	selectAn = "Press a Letter to select an ";
	enterDash = "Enter - ";


	accordingToSourcesAtScene = "  According to sources that were at the scene, ";
	accordingToPoliceSources = "  According to police sources that were at the scene, ";
	ampersandR = "&r";
	singleDot = ".";

	membersOfLCS = "Members of the Liberal Crime Squad ";
	lcsSpokeseperson = "to a Liberal Crime Squad spokesperson.";
	policeSpokesperson = "to a spokesperson from the police department.";
	pressKeyToReflect = "Press any key to reflect on what has happened.";
	return true;
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
	pointerAndString(&ALLOWSTALIN, "ALLOWSTALIN")
};