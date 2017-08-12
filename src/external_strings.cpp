

#include <includes.h>
#include <externs.h>
#include "common\\customMaps.h"
// from activities.cpp
char *study_string1 = " will attend classes in the University District";
char *study_string2 = "  at a cost of $60 a day.";

// this is the string data for activities. they write up to three lines of text about the activity
// the ones with a skill on the end (e.g. ACTIVITY_SELL_ART, ACTIVITY_SELL_MUSIC) pick one of the three lines of text based on the skill in question
ActivityToData data_activities =
{

	ActivityToData::value_type(ACTIVITY_COMMUNITYSERVICE, data_activity('a', true, " help the elderly, local library, anything", "  that is Liberal.")),
	ActivityToData::value_type(ACTIVITY_TROUBLE, data_activity('a', true, " create public disturbances. ")),
	ActivityToData::value_type(ACTIVITY_GRAFFITI, data_activity('a', true, " spray political graffiti. Art and Heart will", "  enhance the liberal effect.")),
	ActivityToData::value_type(ACTIVITY_POLLS, data_activity('a', true, " search the internet for public opinion polls.", "  Polls will give an idea on how the liberal agenda is going. Computers", "  and intelligence will provide better results.")),
	ActivityToData::value_type(ACTIVITY_DOS_ATTACKS, data_activity('a', true, " harass Conservative websites. Computer skill", "  will give greater effect.")),
	ActivityToData::value_type(ACTIVITY_HACKING, data_activity('a', true, " harass websites and hack private networks.", "  Computer skill and intelligence will give more frequent results.", "  Multiple hackers will increase chances of both success and detection.")),
	ActivityToData::value_type(ACTIVITY_WRITE_LETTERS, data_activity('a', true, " write letters to newspapers about current events.")),
	ActivityToData::value_type(ACTIVITY_WRITE_GUARDIAN, data_activity('a', true, " write articles for the LCS's newspaper.")),
	ActivityToData::value_type(ACTIVITY_DONATIONS, data_activity('b', true, " walk around and ask for donations to the LCS.", "  Based on persuasion, public's view on the cause, and how well dressed the", "  activist is.")),
	ActivityToData::value_type(ACTIVITY_SELL_TSHIRTS, data_activity('b', true, " tie-dye T-shirts and sell them on the street.", " will embroider shirts and sell them on the street.", " will print and distribute shirts with Liberal slogans.", SKILL_TAILORING)),
	ActivityToData::value_type(ACTIVITY_SELL_ART, data_activity('b', true, " sketch people and sell portraits back to them.", " will make pretty paintings and sell them on the streets.", " will create and sell paintings embracing the Liberal agenda.", SKILL_ART)),
	ActivityToData::value_type(ACTIVITY_SELL_MUSIC, data_activity('b', true, " go out into the streets and drum on buckets,", "  or play guitar if one is equipped.")),
	ActivityToData::value_type(ACTIVITY_SELL_DRUGS, data_activity('c', true, " bake and sell special adult brownies that open", "  magical shimmering doorways to the adamantium pits.")),
	ActivityToData::value_type(ACTIVITY_PROSTITUTION, data_activity('c', true, " trade sex for money.")),
	ActivityToData::value_type(ACTIVITY_CCFRAUD, data_activity('c', true, " commit credit card fraud online.")),
	ActivityToData::value_type(ACTIVITY_DOS_RACKET, data_activity('c', true, " demand money in exchange for not bringing down", "major websites.")),
	ActivityToData::value_type(ACTIVITY_RECRUITING, data_activity('d', true, " try to find someone to join the LCS.")),
	ActivityToData::value_type(ACTIVITY_STEALCARS, data_activity('d', true, " try to find and steal a car.")),
	ActivityToData::value_type(ACTIVITY_MAKE_ARMOR, data_activity('d', true, "")), // did not have any strings listed
	ActivityToData::value_type(ACTIVITY_REPAIR_ARMOR, data_activity('d', true, "")), // did not have any strings listed
	ActivityToData::value_type(ACTIVITY_WHEELCHAIR, data_activity('d', true, "")), // did not have any strings listed
	ActivityToData::value_type(ACTIVITY_AUGMENT, data_activity('d', true, " will augment another Liberal to make them", "physically superior.")),
	ActivityToData::value_type(ACTIVITY_HEAL, data_activity('h', true, "")), // did not have any strings listed
	ActivityToData::value_type(ACTIVITY_HOSTAGETENDING, data_activity('i', true, "")), // did not have any strings listed
	ActivityToData::value_type(ACTIVITY_CLINIC, data_activity('m', true, "")), // did not have any strings listed
	ActivityToData::value_type(ACTIVITY_BURY, data_activity('z', true, "")), // did not have any strings listed
	ActivityToData::value_type(ACTIVITY_TEACH_POLITICS, data_activity('t', false, "  Skills Trained: Writing, Persuasion, Law, Street Sense, Science,", "    Religion, Business, Music, Art", "  Classes cost up to $20/day to conduct. All Liberals able will attend.")),
	ActivityToData::value_type(ACTIVITY_TEACH_COVERT, data_activity('t', false, "  Skills Trained: Computers, Security, Stealth, Disguise, Tailoring,", "    Seduction, Psychology, Driving", "  Classes cost up to $60/day to conduct. All Liberals able will attend.")),
	ActivityToData::value_type(ACTIVITY_TEACH_FIGHTING, data_activity('t', false, "  Skills Trained: All Weapon Skills, Martial Arts, Dodge, First Aid", "", "  Classes cost up to $100/day to conduct. All Liberals able will attend.")),
	ActivityToData::value_type(ACTIVITY_STUDY_DEBATING, data_activity('l', true, study_string1, study_string2)),
	ActivityToData::value_type(ACTIVITY_STUDY_MARTIAL_ARTS, data_activity('l', true, study_string1, study_string2)),
	ActivityToData::value_type(ACTIVITY_STUDY_DRIVING, data_activity('l', true, study_string1, study_string2)),
	ActivityToData::value_type(ACTIVITY_STUDY_PSYCHOLOGY, data_activity('l', true, study_string1, study_string2)),
	ActivityToData::value_type(ACTIVITY_STUDY_FIRST_AID, data_activity('l', true, study_string1, study_string2)),
	ActivityToData::value_type(ACTIVITY_STUDY_LAW, data_activity('l', true, study_string1, study_string2)),
	ActivityToData::value_type(ACTIVITY_STUDY_DISGUISE, data_activity('l', true, study_string1, study_string2)),
	ActivityToData::value_type(ACTIVITY_STUDY_SCIENCE, data_activity('l', true, study_string1, study_string2)),
	ActivityToData::value_type(ACTIVITY_STUDY_BUSINESS, data_activity('l', true, study_string1, study_string2)),
	// ActivityToData::value_type(ACTIVITY_STUDY_COOKING, data_activity'l', true,study_string1, study_string2)),
	ActivityToData::value_type(ACTIVITY_STUDY_GYMNASTICS, data_activity('l', true, study_string1, study_string2)),
	ActivityToData::value_type(ACTIVITY_STUDY_WRITING, data_activity('l', true, study_string1, study_string2)),
	ActivityToData::value_type(ACTIVITY_STUDY_ART, data_activity('l', true, study_string1, study_string2)),
	ActivityToData::value_type(ACTIVITY_STUDY_MUSIC, data_activity('l', true, study_string1, study_string2)),
	ActivityToData::value_type(ACTIVITY_STUDY_TEACHING, data_activity('l', true, study_string1, study_string2)),
	ActivityToData::value_type(ACTIVITY_STUDY_LOCKSMITHING, data_activity('l', true, study_string1, study_string2)),
	ActivityToData::value_type(ACTIVITY_NONE, data_activity('x', false, ""))
};
ViewAndStrings pollingData = {
	ViewAndStrings::value_type(VIEW_GAY,  stringConnectedToView("protecting gay rights.", "protecting the traditional family.")),
	ViewAndStrings::value_type(VIEW_DEATHPENALTY, stringConnectedToView("the unjust death penalty.", "protecting the death penalty.", "restoring the death penalty.")),
	ViewAndStrings::value_type(VIEW_TAXES, stringConnectedToView("the oppressive tax structure.", "the excessive tax burden.")),
	ViewAndStrings::value_type(VIEW_NUCLEARPOWER, stringConnectedToView("the dangers of nuclear power.", "threats to nuclear power.", "legalizing nuclear power.")),
	ViewAndStrings::value_type(VIEW_ANIMALRESEARCH, stringConnectedToView("brutal animal research practices.","excessive regulation of animal research.")),
	ViewAndStrings::value_type(VIEW_POLICEBEHAVIOR, stringConnectedToView("preventing police brutality.","expanding police powers.")),
	ViewAndStrings::value_type(VIEW_INTELLIGENCE, stringConnectedToView("civil liberties and personal privacy.","national security and intelligence.")),
	ViewAndStrings::value_type(VIEW_FREESPEECH, stringConnectedToView("protecting free speech.","ending hate speech.")),
	ViewAndStrings::value_type(VIEW_GENETICS, stringConnectedToView("the dangers of genetic engineering.","excessive regulation of genetic research.")),
	ViewAndStrings::value_type(VIEW_JUSTICES, stringConnectedToView("appointing proper Liberal justices.","appointing proper Conservative justices.")),
	ViewAndStrings::value_type(VIEW_SWEATSHOPS, stringConnectedToView("threats to labor rights.","corrupt union thugs.")),
	ViewAndStrings::value_type(VIEW_POLLUTION, stringConnectedToView("threats to the environment.","excessive regulation of industry.")),
	ViewAndStrings::value_type(VIEW_CORPORATECULTURE, stringConnectedToView("corporate corruption.","excessive regulation of corporations.")),
	ViewAndStrings::value_type(VIEW_CEOSALARY, stringConnectedToView("severe income inequality.","resisting communist wage limits.")),
	ViewAndStrings::value_type(VIEW_PRISONS, stringConnectedToView("stopping the prisoners' suffering.","putting the prisoners in line.")),
	ViewAndStrings::value_type(VIEW_IMMIGRATION, stringConnectedToView("immigrant rights.", "illegal immigration.", "uncontrolled immigration.", "uncontrolled immigration.")),
	ViewAndStrings::value_type(VIEW_DRUGS, stringConnectedToView("drug rights.","drug abuse.")),
	ViewAndStrings::value_type(VIEW_WOMEN, stringConnectedToView("women's equality.","women.")),
	ViewAndStrings::value_type(VIEW_CIVILRIGHTS, stringConnectedToView("civil rights.","troublemaking minorities.")),
	ViewAndStrings::value_type(VIEW_GUNCONTROL, stringConnectedToView("gun violence.","protecting the Second Amendment.")),
	ViewAndStrings::value_type(VIEW_MILITARY, stringConnectedToView("military imperialism.","defending the nation.")),
	ViewAndStrings::value_type(VIEW_CONSERVATIVECRIMESQUAD, stringConnectedToView("the Conservative Crime Squad.","the CCS terrorists.")),
	ViewAndStrings::value_type(VIEW_TORTURE, stringConnectedToView("ending the use of torture.","enhancing interrogations."))
};
ActivityAndSkill trainingActivity = {
	ActivityAndSkill::value_type(ACTIVITY_STUDY_DEBATING,SKILL_PERSUASION),
	ActivityAndSkill::value_type(ACTIVITY_STUDY_MARTIAL_ARTS, SKILL_HANDTOHAND),
	ActivityAndSkill::value_type(ACTIVITY_STUDY_DRIVING, SKILL_DRIVING),
	ActivityAndSkill::value_type(ACTIVITY_STUDY_PSYCHOLOGY, SKILL_PSYCHOLOGY),
	ActivityAndSkill::value_type(ACTIVITY_STUDY_FIRST_AID, SKILL_FIRSTAID),
	ActivityAndSkill::value_type(ACTIVITY_STUDY_LAW, SKILL_LAW),
	ActivityAndSkill::value_type(ACTIVITY_STUDY_DISGUISE, SKILL_DISGUISE),
	ActivityAndSkill::value_type(ACTIVITY_STUDY_SCIENCE, SKILL_SCIENCE),
	ActivityAndSkill::value_type(ACTIVITY_STUDY_BUSINESS, SKILL_BUSINESS),
	ActivityAndSkill::value_type(ACTIVITY_STUDY_GYMNASTICS, SKILL_DODGE),
	ActivityAndSkill::value_type(ACTIVITY_STUDY_LOCKSMITHING, SKILL_SECURITY),
	ActivityAndSkill::value_type(ACTIVITY_STUDY_MUSIC, SKILL_MUSIC),
	ActivityAndSkill::value_type(ACTIVITY_STUDY_ART, SKILL_ART),
	ActivityAndSkill::value_type(ACTIVITY_STUDY_TEACHING, SKILL_TEACHING),
	ActivityAndSkill::value_type(ACTIVITY_STUDY_WRITING, SKILL_WRITING),
	ActivityAndSkill::value_type(ACTIVITY_STUDY_COMPUTERS, SKILL_COMPUTERS)
	//ActivityAndSkill::value_type(ACTIVITY_STUDY_COOKING,SKILL_COOKING)
};
// This is the lesson data for the University. Keep data_lesson_num matching the number of classes on offer. The code handles the rest.
vector<ActivityAndString> data_lessons = {
	ActivityAndString(ACTIVITY_STUDY_DEBATING,	"Public Policy"),
	ActivityAndString(ACTIVITY_STUDY_BUSINESS,	"Economics"),
	ActivityAndString(ACTIVITY_STUDY_PSYCHOLOGY,	"Psychology"),
	ActivityAndString(ACTIVITY_STUDY_LAW,			"Criminal Law"),
	ActivityAndString(ACTIVITY_STUDY_SCIENCE,		"Physics"),
	ActivityAndString(ACTIVITY_STUDY_DRIVING,		"Drivers Ed"),
	ActivityAndString(ACTIVITY_STUDY_FIRST_AID,	"First Aid"),
	ActivityAndString(ACTIVITY_STUDY_ART,			"Painting"),
	ActivityAndString(ACTIVITY_STUDY_DISGUISE,	"Theatre"),
	ActivityAndString(ACTIVITY_STUDY_MARTIAL_ARTS,"Kung Fu"),
	ActivityAndString(ACTIVITY_STUDY_GYMNASTICS,	"Gymnastics"),
	ActivityAndString(ACTIVITY_STUDY_WRITING,		"Writing"),
	ActivityAndString(ACTIVITY_STUDY_TEACHING,	"Education"),
	ActivityAndString(ACTIVITY_STUDY_MUSIC,		"Music"),
	ActivityAndString(ACTIVITY_STUDY_LOCKSMITHING,"Locksmithing")
};
vector<activityData> hackingActivities = {
	activityData("revealed huge political bias in INS processes.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_IMMIGRATION,2,0,75), ChangeOfOpinion(VIEW_FREESPEECH,2,0,75) }), vector<string>({})),
	//Scambaiting, except you're baiting a CEO
	activityData("published emails revealing CEO tax evasion.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_CEOSALARY,2,0,75),	ChangeOfOpinion(VIEW_TAXES,2,0,75) }), vector<string>({})),
	activityData("spread videos of racist police brutality.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_POLICEBEHAVIOR,2,0,75),	ChangeOfOpinion(VIEW_CIVILRIGHTS,2,0,75) }), vector<string>({})),
	// *JDS* Penetrated government networks; don't get any loot, but do scare the info community
	activityData("caused a scare by breaking into a CIA network.", DIFFICULTY_IMPOSSIBLE, 25, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_INTELLIGENCE,10,0,75) }), vector<string>({})),
	activityData("broke into military networks leaving LCS slogans.", DIFFICULTY_IMPOSSIBLE, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_LIBERALCRIMESQUAD,5,0,75) }), vector<string>({})),
	activityData("subverted a Conservative family forum.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_GAY,2,0,75),	ChangeOfOpinion(VIEW_WOMEN,2,0,75) }), vector<string>({})),
	activityData("sabotaged a genetics research company's network.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_GENETICS,2,0,75) }), vector<string>({})),
	activityData("discovered evidence of judicial corruption.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({}), vector<string>({ "LOOT_JUDGEFILES" })),
	activityData("uncovered information on dangerous research.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({}), vector<string>({ "LOOT_RESEARCHFILES" })),
	activityData("pilfered files from a Corporate server.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({}), vector<string>({ "LOOT_CORPFILES" })),
	activityData("intercepted internal media emails.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({}), vector<string>({ "LOOT_CABLENEWSFILES","LOOT_AMRADIOFILES" }))
};

charToVector activate_menu_items =
{
	charToVector::value_type('a',vector<ActivityAndString>({ ActivityAndString(1, ACTIVITY_COMMUNITYSERVICE, "Community Service"),
	ActivityAndString(2, ACTIVITY_TROUBLE,			"Liberal Disobedience"),
		ActivityAndString(3, ACTIVITY_GRAFFITI,			"Graffiti"),
		ActivityAndString(4, ACTIVITY_POLLS,			"Search Opinion Polls"),
		//ActivityAndString(ACTIVITY_DOS_ATTACKS, "Harass Websites"),
		ActivityAndString(5, ACTIVITY_HACKING,			"Hacking"),
		ActivityAndString(6, ACTIVITY_WRITE_LETTERS,	"Write to Newspapers"),
		ActivityAndString(7, ACTIVITY_WRITE_GUARDIAN,	"Write for The Liberal Guardian", ACTIVITIY_MENU_CHECK_PRESS) })), // 
	charToVector::value_type('b',vector<ActivityAndString>({ ActivityAndString(1, ACTIVITY_DONATIONS,		"Solicit Donations"),
		ActivityAndString(2, ACTIVITY_SELL_TSHIRTS,		"Sell Tie-Dyed T-Shirts", "Sell Embroidered Shirts", "Sell Liberal T-Shirts", SKILL_TAILORING),
		ActivityAndString(3, ACTIVITY_SELL_ART,			"Sell Portrait Sketches", "Sell Paintings", "Sell Liberal Art", SKILL_ART),
		ActivityAndString(4, ACTIVITY_SELL_MUSIC,		"Play Street Music", "Play Street Music", "Play Liberal Music", SKILL_MUSIC) })),
	charToVector::value_type('c',vector<ActivityAndString>({ ActivityAndString(1, ACTIVITY_SELL_DRUGS,		"Sell Brownies"),
		ActivityAndString(2, ACTIVITY_PROSTITUTION,		"Prostitution", ACTIVITIY_MENU_CHECK_AGE),
		//	ActivityAndString(ACTIVITY_DOS_RACKET, "Electronic Protection Racket"),
		ActivityAndString(3, ACTIVITY_CCFRAUD,			"Steal Credit Card Numbers") })),
	charToVector::value_type('d',vector<ActivityAndString>({ ActivityAndString(1, ACTIVITY_RECRUITING,		"Recruiting"),
		ActivityAndString(2, ACTIVITY_MAKE_ARMOR,		"Make Clothing"),
		ActivityAndString(3, ACTIVITY_REPAIR_ARMOR,		"Repair Clothing"),
		ActivityAndString(4, ACTIVITY_STEALCARS,		"Steal a Car", ACTIVITIY_MENU_CHECK_CAN_WALK),
		ActivityAndString(5, ACTIVITY_WHEELCHAIR,		"Procure a Wheelchair", ACTIVITIY_MENU_CHECK_WHEELCHAIR),
		ActivityAndString(6, ACTIVITY_AUGMENT, "Augment a Liberal", ACTIVITIY_MENU_CHECK_CAN_AUGMENT) })),
	charToVector::value_type('t',vector<ActivityAndString>({ ActivityAndString(0,  ACTIVITY_NONE,				"Teach Liberals About What?"),
		ActivityAndString(1, ACTIVITY_TEACH_POLITICS,	"Political Activism"),
		ActivityAndString(2, ACTIVITY_TEACH_COVERT,		"Infiltration"),
		ActivityAndString(3, ACTIVITY_TEACH_FIGHTING,	"Urban Warfare") }))
};
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
vector<string> missedDriver = {
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
vector<string> missedPedestrian = {
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

vector<string> handToHandStrike = {
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
};

StringPairs tankBodyCollection = {
	StringPairs::value_type(BODYPART_HEAD, "turret"),
	StringPairs::value_type(BODYPART_BODY, "front"),
	StringPairs::value_type(BODYPART_ARM_RIGHT, "right side"),
	StringPairs::value_type(BODYPART_ARM_LEFT, "left side"),
	StringPairs::value_type(BODYPART_LEG_RIGHT, "right tread"),
	StringPairs::value_type(BODYPART_LEG_LEFT, "left tread")
};
StringPairs animalBodyCollection = {
	StringPairs::value_type(BODYPART_HEAD, "head"),
	StringPairs::value_type(BODYPART_BODY, "body"),
	StringPairs::value_type(BODYPART_ARM_RIGHT, "right front leg"),
	StringPairs::value_type(BODYPART_ARM_LEFT, "left front leg"),
	StringPairs::value_type(BODYPART_LEG_RIGHT, "right rear leg"),
	StringPairs::value_type(BODYPART_LEG_LEFT, "left rear leg")
};
StringPairs humanBodyCollection = {
	StringPairs::value_type(BODYPART_HEAD, "head"),
	StringPairs::value_type(BODYPART_BODY, "body"),
	StringPairs::value_type(BODYPART_ARM_RIGHT, "right arm"),
	StringPairs::value_type(BODYPART_ARM_LEFT, "left arm"),
	StringPairs::value_type(BODYPART_LEG_RIGHT, "right leg"),
	StringPairs::value_type(BODYPART_LEG_LEFT, "left leg")
};

vector<special_wound_structure> head_special_wound = {
	customWound(HEAVY, "'s face is blasted off!", "'s face is burned away!", "'s face is torn off!", "'s face is cut away!", "'s face is removed!",{ SPECIALWOUND_RIGHTEYE, SPECIALWOUND_LEFTEYE,  SPECIALWOUND_NOSE }, 20),
	customWound(HEAVY, "'s right eye is blasted out!", "'s right eye is burned away!", "'s right eye is torn out!", "'s right eye is poked out!", "'s right eye is removed!",{ SPECIALWOUND_RIGHTEYE }, 50),
	customWound(HEAVY, "'s left eye is blasted out!", "'s left eye is burned away!", "'s left eye is torn out!", "'s left eye is poked out!", "'s left eye is removed!",{ SPECIALWOUND_LEFTEYE }, 50),


	customWound(HEAVY, "'s tongue is blasted off!", "'s tongue is burned away!", "'s tongue is torn out!", "'s tongue is cut off!", "'s tongue is removed!",{ SPECIALWOUND_TONGUE }, 50),
	customWound(HEAVY, "'s nose is blasted off!", "'s nose is burned away!", "'s nose is torn off!", "'s nose is cut off!", "'s nose is removed!",{ SPECIALWOUND_NOSE }, 50),
	customWound(BREAK, "'s neck bones are shattered!", "", "", "", "'s neck is broken!",{ SPECIALWOUND_NECK }, 20),

	// teeth are dealt with in a custom manner
	// as a result, the specialwoundteeth customwound is effectively empty
	customWound(ANY, "", "", "", "", "",{ SPECIALWOUND_TEETH }, 0)

};
vector<special_wound_structure> body_special_wound = {

	customWound(BREAK, "'s upper spine is shattered!", "", "", "", "'s upper spine is broken!",{ SPECIALWOUND_UPPERSPINE }, 20),
	customWound(BREAK, "'s lower spine is shattered!", "", "", "", "'s lower spine is broken!",{ SPECIALWOUND_LOWERSPINE }, 20),
	customWound(POKE, "'s right lung is blasted!", "", "'s right lung is torn!", "", "'s right lung is punctured!",{ SPECIALWOUND_RIGHTLUNG }, 20),
	customWound(POKE, "'s left lung is blasted!", "", "'s left lung is torn!", "", "'s left lung is punctured!",{ SPECIALWOUND_LEFTLUNG }, 20),
	customWound(POKE, "'s heart is blasted!", "", "'s heart is torn!", "", "'s heart is punctured!",{ SPECIALWOUND_HEART }, 3),
	customWound(POKE, "'s liver is blasted!", "", "'s liver is torn!", "", "'s liver is punctured!",{ SPECIALWOUND_LIVER }, 50),
	customWound(POKE, "'s stomach is blasted!", "", "'s stomach is torn!", "", "'s stomach is punctured!",{ SPECIALWOUND_STOMACH }, 50),
	customWound(POKE, "'s right kidney is blasted!", "", "'s right kidney is torn!", "", "'s right kidney is punctured!",{ SPECIALWOUND_RIGHTKIDNEY }, 50),
	customWound(POKE, "'s left kidney is blasted!", "", "'s left kidney is torn!", "", "'s left kidney is punctured!",{ SPECIALWOUND_LEFTKIDNEY }, 50),
	customWound(POKE, "'s spleen is blasted!", "", "'s spleen is torn!", "", "'s spleen is punctured!",{ SPECIALWOUND_SPLEEN }, 50),

	// ribs are dealt with in a custom manner
	// as a result, the specialwoundribs customwound is effectively empty

	customWound(BREAK, "", "", "", "", "",{ SPECIALWOUND_RIBS }, 0)
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
void displayDifficulty(int difficulty)
{
	const char *_difficulty[] = { "Simple", "Very Easy", "Easy", "Below Average", "Average", "Above Average", "Hard", "Very Hard", "Extremely Difficult", "Nearly Impossible", "Impossible" };

	switch (difficulty)
	{
	case 0:	set_color(COLOR_GREEN, COLOR_BLACK, 1); break;
	case 1: set_color(COLOR_CYAN, COLOR_BLACK, 1); break;
	case 2: set_color(COLOR_CYAN, COLOR_BLACK, 0); break;
	case 3: set_color(COLOR_BLUE, COLOR_BLACK, 1); break;
	case 4: set_color(COLOR_WHITE, COLOR_BLACK, 1); break;
	case 5: set_color(COLOR_WHITE, COLOR_BLACK, 0); break;
	case 6: set_color(COLOR_YELLOW, COLOR_BLACK, 1); break;
	case 7: set_color(COLOR_MAGENTA, COLOR_BLACK, 0); break;
	case 8: set_color(COLOR_MAGENTA, COLOR_BLACK, 1); break;
	case 9: set_color(COLOR_RED, COLOR_BLACK, 0);	break;
	default:set_color(COLOR_RED, COLOR_BLACK, 1);	break;
	}
	if (difficulty >= 0 && difficulty < 10) addstr(_difficulty[difficulty]); else addstr(_difficulty[10]);
}


vector<recruitData> recruitable_creatures = {
	recruitData(CREATURE_VETERAN, (char*)"Army Veteran", 4),
	recruitData(CREATURE_ATHLETE, (char*)"Athlete", 4),
	recruitData(CREATURE_COLLEGESTUDENT, (char*)"College Student", 1),
	recruitData(CREATURE_PROGRAMMER, (char*)"Computer Programmer", 4),
	recruitData(CREATURE_DANCER, (char*)"Dancer", 4),
	recruitData(CREATURE_DOCTOR, (char*)"Doctor", 4),
	recruitData(CREATURE_FASHIONDESIGNER, (char*)"Fashion Designer", 6),
	recruitData(CREATURE_GANGMEMBER, (char*)"Gang Member", 2),
	recruitData(CREATURE_HIPPIE, (char*)"Hippie", 1),
	recruitData(CREATURE_JOURNALIST, (char*)"Journalist", 4),
	recruitData(CREATURE_JUDGE_LIBERAL, (char*)"Judge", 6),
	recruitData(CREATURE_LAWYER, (char*)"Lawyer", 4),
	recruitData(CREATURE_LOCKSMITH, (char*)"Locksmith", 6),
	recruitData(CREATURE_MARTIALARTIST, (char*)"Martial Artist", 4),
	recruitData(CREATURE_MUSICIAN, (char*)"Musician", 4),
	recruitData(CREATURE_MUTANT, (char*)"Mutant", 4),
	recruitData(CREATURE_PROSTITUTE, (char*)"Prostitute", 2),
	recruitData(CREATURE_PSYCHOLOGIST, (char*)"Psychologist", 4),
	recruitData(CREATURE_TAXIDRIVER, (char*)"Taxi Driver", 4),
	recruitData(CREATURE_TEACHER, (char*)"Teacher", 4)
};