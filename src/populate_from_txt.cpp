
#include <externs.h>

bool populate_from_txt(vector<string> & types, string fileName);

bool populate_from_txt(vector< vector<string> >& types, string fileName, int dimension);

// From chase.cpp
vector<string> carchase_obstacle_none = {
	"D - Try to lose them!",
	"E - Equip",
	"F - Fight!"
};
vector<string> carchase_obstacle_fruit_stand = {
	"You are speeding toward a flimsy fruit stand!",
	"D - Swerve to avoid hitting anyone!",
	"F - Play it safe and plow through it!"
};
vector<string> carchase_obstacle_truck_pulls_out = {
	"A truck pulls out in your path!",
	"D - Speed around it!",
	"F - Slow down!"
};
vector<string> carchase_obstacle_cross_traffic = {
	"There's a red light with cross traffic ahead!",
	"D - Run the light anyway!",
	"F - Slow down and turn!"
};
vector<string> carchase_obstacle_child = {
	"A kid runs into the street for his ball!",
	"D - Swerve around him!",
	"F - Slam the brakes!"
};

vector<vector<string>> pickupLines;
vector<vector<string>> no_free_speech_flirt;
vector<vector<string>> lovingly_talk_to_mutant;
vector<vector<string>> normal_talk_to_mutant;
vector<vector<string>> lovingly_talk_to_dog;
vector<vector<string>> normal_talk_to_dog;
vector<vector<string>> real_quote;
vector<string> escape_running;
vector<string> escape_crawling;
vector<string> judge_debate;
vector<string> conservative_ceo_debate;
vector<string> other_ceo_debate;
vector<string> conservative_politician_debate;
vector<string> other_politician_debate;
vector<string> media_debate;
vector<string> military_debate;
vector<string> police_debate;
vector<string> scientist_debate;
vector<string> dog_rejection;
vector<string> mutant_rejection;
vector<string> that_is_disturbing;
vector<string> that_is_not_disturbing;

vector<string> execution;
vector<string> feels_sick;
vector<string> low_heart_torture_props;
vector<string> screaming;
vector<string> beat_with_props;
vector<string> words_meaning_screaming;
vector<string> words_to_scream;
vector<string> prays;
vector<string> prays_on_drugs;
vector<string> use_props;
vector<string> resist_drugs;
vector<string> cry_alarm;

vector<string> bleeding_to_death;
vector<string> stunned_text;
vector<string> paralyzed_text;
vector<string> paralyzed_tank;
vector<string> bleeding_animal;
vector<vector<string>> double_line_death;
vector<string> body_falls_apart;

vector<string> robbing_bank;
vector<string> teller_gestures;
vector<string> teller_complies;

vector<string> default_slogans;

vector<string> come_at_me_bro;
vector<string> backs_off;
vector<string> threaten_hostage;
vector<string> please_spare_hostage;
vector<string> who_cares_about_hostage;
vector<string> hostage_negotiation;
vector<string> please_no_more;
vector<string> let_hostages_go;
vector<string> go_ahead_and_die;
vector<string> agree_to_release_hostages;

vector<string> partial_conversion;
vector<string> broods_over_death;
vector<string> self_wounding;


vector<vector<string>> fall_in_love;
vector<vector<string>> bad_trip;
vector<string> good_trip;
vector<vector<string>> good_trip_companion;
vector<string> smarter_than_you_one_line;
vector<vector<string>> smarter_than_you;
vector<string> develops_hatred_one_line;
vector<vector<string>> develops_hatred;
vector<string> interrogater_shows_compassion_one_line;
vector<vector<string>> interrogater_shows_compassion;
vector<vector<string>> cling_to_interrogater;
vector<string> clinging_one_line;
vector<vector<string>> cling_to_religion;
vector<string> cling_to_religion_one_line;
vector<vector<string>> discuss;
vector<string> vanilla_recruit;
vector<vector<string>> cling_to_business;
vector<string> cling_to_business_one_line;
vector<vector<string>> cling_to_science;
vector<string> cling_to_science_one_line;

vector<string> city_names;
vector<string> male_first_names;
vector<string> female_first_names;
vector<string> gender_neutral_first_names;
vector<string> great_white_male_patriarch_first_names;

vector<string> regular_last_names;
vector<string> archconservative_last_names;

vector<string> quality_0;
vector<string> quality_20;
vector<string> quality_35;
vector<string> quality_50;
vector<string> words_meaning_hacked;
vector<string> enemy_website;
vector<string> win_hand_to_hand;
vector<string> lose_hand_to_hand;
vector<string> car_wont_start;
vector<string> gets_nervous;
vector<string> cant_hotwire_car;
vector<string> almost_hotwire_car;

vector<string> car_speed;
vector<string> car_plows_through;
vector<string> car_crash_modes;
vector<string> car_crash_fatalities;
vector<string> die_in_car;

vector<string> ccs_covername_shotgun;
vector<string> ccs_covername_other;
vector<string> words_meaning_hick;
vector<string> genetic_monster;

vector<string> date_fail;

vector<string> liberal_jury;
vector<string> conservative_jury;
vector<string> cruel_and_unusual_execution_methods;
vector<string> standard_execution_methods;
vector<string> supposedly_painless_execution_method;
vector<string> reeducation_experiences;
vector<string> labor_camp_experiences;
vector<string> good_experiences;
vector<string> bad_experiences;
vector<string> general_experiences;

vector<string> words_meaning_news;
vector<string> newspaper_first_name;
vector<string> newspaper_last_name;
vector<string> insult_for_liberal;
vector<string> word_replacing_liberal;

vector<string> blew_stealth_check;


vector<string> labor_camp_name;
vector<string> labor_camp_name_2;
vector<string> juice_name;
vector<string> juice_name_2;
vector<string> vegan_name;
vector<string> vegan_name_2;
vector<string> cafe_name;
vector<string> cafe_name_2;
vector<string> latte_name;
vector<string> latte_name_2;

vector<string> was_abused;

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

vector<string> cant_find_keys;
vector<string> cant_find_keys_no_free_speech;

vector<string> ccs_adjective;
vector<string> ccs_adjective_2;
vector<string> ccs_adjective_3;
vector<string> ccs_noun;

vector<string> founderQuestions;

bool initialize_txt();
bool initialize_txt() {
	bool loaded = true;
	loaded &= populate_from_txt(default_slogans, "default_slogans.txt");
	//IsaacG
	// the number five (5) here indicates how many lines a "pickup line" is
	// 2 lines for the initial pickup,
	// 1 line for accepting the proposal,
	// and 2 lines for rejecting
	// 
	/*talk.cpp*/
	string talk = "talk\\";
	loaded &= populate_from_txt(pickupLines, talk + "pickupLines.txt", 5);
	loaded &= populate_from_txt(no_free_speech_flirt, talk + "no_free_speech_flirt.txt", 5);
	loaded &= populate_from_txt(lovingly_talk_to_mutant, talk + "lovingly_talk_to_mutant.txt", 2);
	loaded &= populate_from_txt(normal_talk_to_mutant, talk + "normal_talk_to_mutant.txt", 2);
	loaded &= populate_from_txt(lovingly_talk_to_dog, talk + "lovingly_talk_to_dog.txt", 2);
	loaded &= populate_from_txt(normal_talk_to_dog, talk + "normal_talk_to_dog.txt", 2);
	loaded &= populate_from_txt(dog_rejection, talk + "dog_rejection.txt");
	loaded &= populate_from_txt(mutant_rejection, talk + "mutant_rejection.txt");
	loaded &= populate_from_txt(that_is_disturbing, talk + "that_is_disturbing.txt");
	loaded &= populate_from_txt(that_is_not_disturbing, talk + "that_is_not_disturbing.txt");

	loaded &= populate_from_txt(robbing_bank, talk + "robbing_bank.txt");
	loaded &= populate_from_txt(teller_gestures, talk + "teller_gestures.txt");
	loaded &= populate_from_txt(teller_complies, talk + "teller_complies.txt");
	//talk in combat
	string talk_combat = "talk_combat\\";
	loaded &= populate_from_txt(come_at_me_bro, talk_combat + "come_at_me_bro.txt");
	loaded &= populate_from_txt(backs_off, talk_combat + "backs_off.txt");
	loaded &= populate_from_txt(threaten_hostage, talk_combat + "threaten_hostage.txt");
	loaded &= populate_from_txt(please_spare_hostage, talk_combat + "please_spare_hostage.txt");
	loaded &= populate_from_txt(who_cares_about_hostage, talk_combat + "who_cares_about_hostage.txt");
	loaded &= populate_from_txt(hostage_negotiation, talk_combat + "hostage_negotiation.txt");
	loaded &= populate_from_txt(please_no_more, talk_combat + "please_no_more.txt");
	loaded &= populate_from_txt(let_hostages_go, talk_combat + "let_hostages_go.txt");
	loaded &= populate_from_txt(go_ahead_and_die, talk_combat + "go_ahead_and_die.txt");
	loaded &= populate_from_txt(agree_to_release_hostages, talk_combat + "agree_to_release_hostages.txt");

	/*titlescreen.cpp*/
	string title = "titlescreen\\";
	loaded &= populate_from_txt(real_quote, title + "real_quote.txt", 4);



	/*fight.cpp*/
	string fight = "fight\\";
	loaded &= populate_from_txt(escape_running, fight + "escape_running.txt");
	loaded &= populate_from_txt(escape_crawling, fight + "escape_crawling.txt");
	loaded &= populate_from_txt(judge_debate, fight + "judge_debate.txt");
	loaded &= populate_from_txt(conservative_ceo_debate, fight + "conservative_ceo_debate.txt");
	loaded &= populate_from_txt(other_ceo_debate, fight + "other_ceo_debate.txt");
	loaded &= populate_from_txt(conservative_politician_debate, fight + "conservative_politician_debate.txt");
	loaded &= populate_from_txt(other_politician_debate, fight + "other_politician_debate.txt");
	loaded &= populate_from_txt(media_debate, fight + "media_debate.txt");
	loaded &= populate_from_txt(military_debate, fight + "military_debate.txt");
	loaded &= populate_from_txt(police_debate, fight + "police_debate.txt");
	loaded &= populate_from_txt(scientist_debate, fight + "scientist_debate.txt");
	loaded &= populate_from_txt(cry_alarm, fight + "cry_alarm.txt");

	loaded &= populate_from_txt(bleeding_to_death, fight + "bleeding_to_death.txt");
	loaded &= populate_from_txt(stunned_text, fight + "stunned_text.txt");
	loaded &= populate_from_txt(paralyzed_text, fight + "paralyzed_text.txt");
	loaded &= populate_from_txt(paralyzed_tank, fight + "paralyzed_tank.txt");
	loaded &= populate_from_txt(bleeding_animal, fight + "bleeding_animal.txt");
	loaded &= populate_from_txt(double_line_death, fight + "double_line_death.txt", 2);
	loaded &= populate_from_txt(body_falls_apart, fight + "body_falls_apart.txt");

	/*interrogation.cpp*/
	string interrogate = "interrogation\\";
	loaded &= populate_from_txt(execution, interrogate + "execution.txt");
	loaded &= populate_from_txt(feels_sick, interrogate + "feels_sick.txt");
	loaded &= populate_from_txt(low_heart_torture_props, interrogate + "low_heart_torture_props.txt");
	loaded &= populate_from_txt(screaming, interrogate + "screaming.txt");
	loaded &= populate_from_txt(beat_with_props, interrogate + "beat_with_props.txt");
	loaded &= populate_from_txt(words_meaning_screaming, interrogate + "words_meaning_screaming.txt");
	loaded &= populate_from_txt(words_to_scream, interrogate + "words_to_scream.txt");
	loaded &= populate_from_txt(prays, interrogate + "prays.txt");
	loaded &= populate_from_txt(prays_on_drugs, interrogate + "prays_on_drugs.txt");
	loaded &= populate_from_txt(use_props, interrogate + "use_props.txt");
	loaded &= populate_from_txt(resist_drugs, interrogate + "resist_drugs.txt");

	loaded &= populate_from_txt(partial_conversion, interrogate + "partial_conversion.txt");
	loaded &= populate_from_txt(broods_over_death, interrogate + "broods_over_death.txt");
	loaded &= populate_from_txt(self_wounding, interrogate + "self_wounding.txt");
	loaded &= populate_from_txt(good_trip, interrogate + "good_trip.txt");
	loaded &= populate_from_txt(smarter_than_you_one_line, interrogate + "smarter_than_you_one_line.txt");
	loaded &= populate_from_txt(develops_hatred_one_line, interrogate + "develops_hatred_one_line.txt");
	loaded &= populate_from_txt(interrogater_shows_compassion_one_line, interrogate + "interrogater_shows_compassion_one_line.txt");
	loaded &= populate_from_txt(clinging_one_line, interrogate + "clinging_one_line.txt");
	loaded &= populate_from_txt(cling_to_religion_one_line, interrogate + "cling_to_religion_one_line.txt");
	loaded &= populate_from_txt(vanilla_recruit, interrogate + "vanilla_recruit.txt");
	loaded &= populate_from_txt(cling_to_business_one_line, interrogate + "cling_to_business_one_line.txt");
	loaded &= populate_from_txt(cling_to_science_one_line, interrogate + "cling_to_science_one_line.txt");
	loaded &= populate_from_txt(fall_in_love, interrogate + "fall_in_love.txt", 2);
	loaded &= populate_from_txt(bad_trip, interrogate + "bad_trip.txt", 2);
	loaded &= populate_from_txt(good_trip_companion, interrogate + "good_trip_companion.txt", 2);
	loaded &= populate_from_txt(smarter_than_you, interrogate + "smarter_than_you.txt", 2);
	loaded &= populate_from_txt(develops_hatred, interrogate + "develops_hatred.txt", 2);
	loaded &= populate_from_txt(interrogater_shows_compassion, interrogate + "interrogater_shows_compassion.txt", 2);
	loaded &= populate_from_txt(cling_to_interrogater, interrogate + "cling_to_interrogater.txt", 2);
	loaded &= populate_from_txt(cling_to_religion, interrogate + "cling_to_religion.txt", 2);
	loaded &= populate_from_txt(discuss, interrogate + "discuss.txt", 2);
	loaded &= populate_from_txt(cling_to_business, interrogate + "cling_to_business.txt", 2);
	loaded &= populate_from_txt(cling_to_science, interrogate + "cling_to_science.txt", 2);

	string names = "names\\";
	/*getnames.cpp*/
	loaded &= populate_from_txt(city_names, names + "city_names.txt");

	/*creaturenames.cpp*/
	loaded &= populate_from_txt(male_first_names, names + "male_first_names.txt");
	loaded &= populate_from_txt(female_first_names, names + "female_first_names.txt");
	loaded &= populate_from_txt(gender_neutral_first_names, names + "gender_neutral_first_names.txt");
	loaded &= populate_from_txt(great_white_male_patriarch_first_names, names + "great_white_male_patriarch_first_names.txt");
	loaded &= populate_from_txt(regular_last_names, names + "regular_last_names.txt");
	loaded &= populate_from_txt(archconservative_last_names, names + "archconservative_last_names.txt");

	string activities = "activities\\";
	/*activities.cpp*/
	loaded &= populate_from_txt(quality_0, activities + "quality_0.txt");
	loaded &= populate_from_txt(quality_20, activities + "quality_20.txt");
	loaded &= populate_from_txt(quality_35, activities + "quality_35.txt");
	loaded &= populate_from_txt(quality_50, activities + "quality_50.txt");
	loaded &= populate_from_txt(words_meaning_hacked, activities + "words_meaning_hacked.txt");
	loaded &= populate_from_txt(enemy_website, activities + "enemy_website.txt");
	loaded &= populate_from_txt(win_hand_to_hand, activities + "win_hand_to_hand.txt");
	loaded &= populate_from_txt(lose_hand_to_hand, activities + "lose_hand_to_hand.txt");
	loaded &= populate_from_txt(car_wont_start, activities + "car_wont_start.txt");
	loaded &= populate_from_txt(gets_nervous, activities + "gets_nervous.txt");
	loaded &= populate_from_txt(cant_hotwire_car, activities + "cant_hotwire_car.txt");
	loaded &= populate_from_txt(almost_hotwire_car, activities + "almost_hotwire_car.txt");
	loaded &= populate_from_txt(cant_find_keys, activities + "cant_find_keys.txt");
	loaded &= populate_from_txt(cant_find_keys_no_free_speech, activities + "cant_find_keys_no_free_speech.txt");
	/*miscactions.cpp*/
	loaded &= populate_from_txt(was_abused, activities + "was_abused.txt");

	string chase = "chase\\";
	/*chase.cpp*/
	loaded &= populate_from_txt(car_speed, chase + "car_speed.txt");
	loaded &= populate_from_txt(car_plows_through, chase + "car_plows_through.txt");
	loaded &= populate_from_txt(car_crash_modes, chase + "car_crash_modes.txt");
	loaded &= populate_from_txt(car_crash_fatalities, chase + "car_crash_fatalities.txt");
	loaded &= populate_from_txt(die_in_car, chase + "die_in_car.txt");

	string creature = "creature\\";
	/*creature.cpp*/
	loaded &= populate_from_txt(ccs_covername_shotgun, creature + "ccs_covername_shotgun.txt");
	loaded &= populate_from_txt(ccs_covername_other, creature + "ccs_covername_other.txt");

	/*creaturetypes.cpp*/
	loaded &= populate_from_txt(words_meaning_hick, creature + "words_meaning_hick.txt");
	loaded &= populate_from_txt(genetic_monster, creature + "genetic_monster.txt");

	string date = "date\\";
	/*date.cpp*/
	loaded &= populate_from_txt(date_fail, date + "date_fail.txt");

	string justice = "justice\\";
	/*justice.cpp*/
	loaded &= populate_from_txt(liberal_jury, justice + "liberal_jury.txt");
	loaded &= populate_from_txt(conservative_jury, justice + "conservative_jury.txt");
	loaded &= populate_from_txt(cruel_and_unusual_execution_methods, justice + "cruel_and_unusual_execution_methods.txt");
	loaded &= populate_from_txt(standard_execution_methods, justice + "standard_execution_methods.txt");
	loaded &= populate_from_txt(supposedly_painless_execution_method, justice + "supposedly_painless_execution_method.txt");
	loaded &= populate_from_txt(reeducation_experiences, justice + "reeducation_experiences.txt");
	loaded &= populate_from_txt(labor_camp_experiences, justice + "labor_camp_experiences.txt");
	loaded &= populate_from_txt(good_experiences, justice + "good_experiences.txt");
	loaded &= populate_from_txt(bad_experiences, justice + "bad_experiences.txt");
	loaded &= populate_from_txt(general_experiences, justice + "general_experiences.txt");

	string siege = "siege\\";
	/*siege.cpp*/
	loaded &= populate_from_txt(words_meaning_news, siege + "words_meaning_news.txt");
	loaded &= populate_from_txt(newspaper_first_name, siege + "newspaper_first_name.txt");
	loaded &= populate_from_txt(newspaper_last_name, siege + "newspaper_last_name.txt");
	loaded &= populate_from_txt(insult_for_liberal, siege + "insult_for_liberal.txt");
	loaded &= populate_from_txt(word_replacing_liberal, siege + "word_replacing_liberal.txt");

	string stealth = "stealth\\";
	loaded &= populate_from_txt(blew_stealth_check, stealth + "blew_stealth_check.txt");

	/*locations.cpp*/
	string locations = "locations\\";
	loaded &= populate_from_txt(labor_camp_name, locations + "labor_camp_name.txt");
	loaded &= populate_from_txt(labor_camp_name_2, locations + "labor_camp_name_2.txt");
	loaded &= populate_from_txt(juice_name, locations + "juice_name.txt");
	loaded &= populate_from_txt(juice_name_2, locations + "juice_name_2.txt");
	loaded &= populate_from_txt(vegan_name, locations + "vegan_name.txt");
	loaded &= populate_from_txt(vegan_name_2, locations + "vegan_name_2.txt");
	loaded &= populate_from_txt(cafe_name, locations + "cafe_name.txt");
	loaded &= populate_from_txt(cafe_name_2, locations + "cafe_name_2.txt");
	loaded &= populate_from_txt(latte_name, locations + "latte_name.txt");
	loaded &= populate_from_txt(latte_name_2, locations + "latte_name_2.txt");

	/*majorevent.cpp*/
	string majorevent = "majorevent\\";

	loaded &= populate_from_txt(liberalCrime, majorevent + "liberalCrime.txt");
	loaded &= populate_from_txt(AMorPM, majorevent + "AMorPM.txt");
	loaded &= populate_from_txt(book_title, majorevent + "book_title.txt");
	loaded &= populate_from_txt(book_title_2, majorevent + "book_title_2.txt");
	loaded &= populate_from_txt(random_nationality, majorevent + "random_nationality.txt");
	loaded &= populate_from_txt(conservative_oppose_book, majorevent + "conservative_oppose_book.txt");
	loaded &= populate_from_txt(radio_name, majorevent + "radio_name.txt");
	loaded &= populate_from_txt(radio_name_2, majorevent + "radio_name_2.txt");
	loaded &= populate_from_txt(vigilante_murder, majorevent + "vigilante_murder.txt");
	loaded &= populate_from_txt(why_chase_ended, majorevent + "why_chase_ended.txt");
	loaded &= populate_from_txt(crazy_conservative_act, majorevent + "crazy_conservative_act.txt");
	loaded &= populate_from_txt(bribe_officers, majorevent + "bribe_officers.txt");
	loaded &= populate_from_txt(my_idol, majorevent + "my_idol.txt");
	loaded &= populate_from_txt(prison_book_title, majorevent + "prison_book_title.txt");
	loaded &= populate_from_txt(prison_book_title_2, majorevent + "prison_book_title_2.txt");
	loaded &= populate_from_txt(mutilated_corpse, majorevent + "mutilated_corpse.txt");
	loaded &= populate_from_txt(evidence_of_child_murder, majorevent + "evidence_of_child_murder.txt");
	loaded &= populate_from_txt(break_in_murder_case, majorevent + "break_in_murder_case.txt");
	loaded &= populate_from_txt(animal_research_country, majorevent + "animal_research_country.txt");
	loaded &= populate_from_txt(drug_name, majorevent + "drug_name.txt");
	loaded &= populate_from_txt(drug_name_2, majorevent + "drug_name_2.txt");
	loaded &= populate_from_txt(chimp_drug_impact, majorevent + "chimp_drug_impact.txt");
	loaded &= populate_from_txt(chimp_drug_horror, majorevent + "chimp_drug_horror.txt");
	loaded &= populate_from_txt(terrorist_group, majorevent + "terrorist_group.txt");
	loaded &= populate_from_txt(terrorist_plot, majorevent + "terrorist_plot.txt");
	loaded &= populate_from_txt(terrorist_plot_no_free_speech, majorevent + "terrorist_plot_no_free_speech.txt");
	loaded &= populate_from_txt(gene_corp_name, majorevent + "gene_corp_name.txt");
	loaded &= populate_from_txt(gene_corp_name_2, majorevent + "gene_corp_name_2.txt");
	loaded &= populate_from_txt(gene_product_name, majorevent + "gene_product_name.txt");
	loaded &= populate_from_txt(gene_product_name_2, majorevent + "gene_product_name_2.txt");
	loaded &= populate_from_txt(gene_product_benefit, majorevent + "gene_product_benefit.txt");
	loaded &= populate_from_txt(gene_product_cost, majorevent + "gene_product_cost.txt");
	loaded &= populate_from_txt(bullshit_no_free_speech, majorevent + "bullshit_no_free_speech.txt");
	loaded &= populate_from_txt(bullshit, majorevent + "bullshit.txt");
	loaded &= populate_from_txt(petty_violence, majorevent + "petty_violence.txt");
	loaded &= populate_from_txt(his_her, majorevent + "his_her.txt");
	loaded &= populate_from_txt(older_younger, majorevent + "older_younger.txt");
	loaded &= populate_from_txt(brother_sister, majorevent + "brother_sister.txt");
	loaded &= populate_from_txt(judge_with_prostitute, majorevent + "judge_with_prostitute.txt");
	loaded &= populate_from_txt(judge_with_prostitute_no_free_speech, majorevent + "judge_with_prostitute_no_free_speech.txt");
	loaded &= populate_from_txt(judge_with_prostitute_full_free_speech, majorevent + "judge_with_prostitute_full_free_speech.txt");
	loaded &= populate_from_txt(radio_host_crazy_quote, majorevent + "radio_host_crazy_quote.txt");
	loaded &= populate_from_txt(radio_host_lost_mind, majorevent + "radio_host_lost_mind.txt");
	loaded &= populate_from_txt(family_values_company_name, majorevent + "family_values_company_name.txt");
	loaded &= populate_from_txt(family_values_company_name_2, majorevent + "family_values_company_name_2.txt");
	loaded &= populate_from_txt(family_values_company_name_3, majorevent + "family_values_company_name_3.txt");
	loaded &= populate_from_txt(pollution_consumption, majorevent + "pollution_consumption.txt");
	loaded &= populate_from_txt(pollution_consumption_2, majorevent + "pollution_consumption_2.txt");
	loaded &= populate_from_txt(i_like_polution, majorevent + "i_like_polution.txt");
	loaded &= populate_from_txt(distrust_liberals, majorevent + "distrust_liberals.txt");
	loaded &= populate_from_txt(tech_giant_name, majorevent + "tech_giant_name.txt");
	loaded &= populate_from_txt(tech_giant_name_2, majorevent + "tech_giant_name_2.txt");
	loaded &= populate_from_txt(fm_radio_name, majorevent + "fm_radio_name.txt");
	loaded &= populate_from_txt(fm_radio_name_2, majorevent + "fm_radio_name_2.txt");
	loaded &= populate_from_txt(public_place, majorevent + "public_place.txt");
	loaded &= populate_from_txt(reagan_bad, majorevent + "reagan_bad.txt");
	loaded &= populate_from_txt(reagan_bad_2, majorevent + "reagan_bad_2.txt");
	loaded &= populate_from_txt(ceo_behaving_badly, majorevent + "ceo_behaving_badly.txt");
	loaded &= populate_from_txt(reagan_good, majorevent + "reagan_good.txt");
	loaded &= populate_from_txt(reagan_good_2, majorevent + "reagan_good_2.txt");
	loaded &= populate_from_txt(cable_name, majorevent + "cable_name.txt");
	loaded &= populate_from_txt(cable_name_2, majorevent + "cable_name_2.txt");
	loaded &= populate_from_txt(cable_city, majorevent + "cable_city.txt");
	loaded &= populate_from_txt(cable_city_2, majorevent + "cable_city_2.txt");

	/*squadstory_text.cpp*/
	
	loaded &= populate_from_txt(ccs_adjective, majorevent + "ccs_adjective.txt");
	loaded &= populate_from_txt(ccs_adjective_2, majorevent + "ccs_adjective_2.txt");
	loaded &= populate_from_txt(ccs_adjective_3, majorevent + "ccs_adjective_3.txt");
	loaded &= populate_from_txt(ccs_noun, majorevent + "ccs_noun.txt");

	/*newgame.cpp*/
	loaded &= populate_from_txt(founderQuestions, "newgame\\founderQuestions.txt");

	return loaded;
}

// populate_from_text extracts plaintext and puts it in a two dimensional vector of strings.
// returns true if file loads, false if not.
static const int line_length = 2048;
bool populate_from_txt(vector< vector<string> >& types, string fileName, int dimension)
{

	ifstream txtFile;
	char currentLine[line_length];
	txtFile.open(string(artdir) + fileName);
	if (txtFile.fail()) {
		cout << "Failed to load " + fileName + "!" << endl;
		getkey();
		return false;
	}
	//cout << endl;
	while (!txtFile.eof()) {
		txtFile.getline(currentLine, line_length, '\n');
		/*if (!currentLine[0]) {
		cout << "blank" << endl;
		}
		if (currentLine[0] == '\n') {
		cout << "newLine" << endl;
		}*/
		bool notComment = (currentLine[0] && currentLine[0] != '#');
		if (notComment) {
			vector<string> line;
			line.push_back(currentLine);
			//cout << currentLine << endl;
			//types[whichPickup][whichLine] = string(currentLine);

			for (int i = 0; i < dimension - 1 && !txtFile.eof(); i++) {
				// whether the line is not a comment, and is also the line whose contents are optional
				// Testing until obtain proper data from file
				txtFile.getline(currentLine, line_length, '\n');
				line.push_back(currentLine);
				//cout << currentLine << endl;
				//types[whichPickup][whichLine] = string(currentLine);
				if (currentLine[0] == '#') {
					cout << "Comment Found" << endl << currentLine << endl;
					getkey();

				}

			}
			types.push_back(line);
		}
	}
	return true;
}

bool populate_from_txt(vector<string> & types, string fileName)
{

	ifstream txtFile;
	char currentLine[line_length];
	txtFile.open(string(artdir) + fileName);
	if (txtFile.fail()) {
		cout << "Failed to load " + fileName + "!" << endl;
		getkey();
		return false;
	}
	cout << endl;
	while (!txtFile.eof()) {
		txtFile.getline(currentLine, line_length, '\n');
		/*if (!currentLine[0]) {
		cout << "blank" << endl;
		}
		if (currentLine[0] == '\n') {
		cout << "newLine" << endl;
		}*/
		bool notComment = (currentLine[0] && currentLine[0] != '#');
		if (notComment) {
			types.push_back(currentLine);
		}
	}
	return true;
}


