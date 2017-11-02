
#include <includes.h>

#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>

extern vector<Creature *> pool;
extern Log gamelog;
extern vector<Location *> location;
//PACKAGE_VERSION must be defined here or the game won't compile on Windows! Don't remove it!!!
// -- yetisyny
 char* PACKAGE_VERSION = "4.12.4";

special_wound_structure customWound(bodypartBreakType breakType_, string shot_, string burned_, string torn_, string cut_, string defaultString_, vector<SpecialWounds> specialWounds_, int maxBlood_) {
	special_wound_structure newWound;
	newWound.breakType = breakType_;
	newWound.shot = shot_;
	newWound.burned = burned_;
	newWound.torn = torn_;
	newWound.cut = cut_;
	newWound.defaultString = defaultString_;
	newWound.specialWounds = specialWounds_;
	newWound.maxBlood = maxBlood_;
	return newWound;
}
file_and_text_collection customText(vector<string>  *collection_, string fileName_) {
	file_and_text_collection newWound;
	newWound.collection = collection_;
	newWound.fileName = fileName_;
	newWound.superCollection = false;
	return newWound;
}
file_and_text_collection customText(vector<vector<string>>  *collection_, string fileName_, int dimensions_) {
	file_and_text_collection newWound;
	newWound.super_collection = collection_;
	newWound.fileName = fileName_;
	newWound.dimensions = dimensions_;
	newWound.superCollection = true;
	return newWound;
}
typedef map<short, string > shortAndString;
typedef map<string, short> stringAndShort;
typedef map<string, string> stringAndString;
typedef map<short, vector<string>> shortAndTwoStrings;
typedef map<short, shortAndString > shortAndShortAndString;

struct stringAndColor
{
	string str;
	ColorSetup type;
	stringAndColor(string str_, ColorSetup type_) : str(str_), type(type_) { }
	stringAndColor(ColorSetup type_, string str_) : str(str_), type(type_) { }
};



int getLawFromFlag(int type);
int getLawFromFlag(int type) {
	return 0;
	if (type == LAWFLAG_BURNFLAG) {
		return LAW_FLAGBURNING;
	}
	else if (type == LAWFLAG_HIREILLEGAL) {
		return LAW_IMMIGRATION;
	}
}
// from activities.cpp
string study_string1 = "attend classes in the University District";
string study_string2 = "at a cost of $60 a day.";

extern ActivityToData data_activities;
extern ViewAndStrings pollingData;
extern ActivityAndSkill trainingActivity;
extern vector<ActivityAndString> data_lessons;
extern vector<activityData> hackingActivities;
extern charToVector activate_menu_items;
extern vector<recruitData> recruitable_creatures;
extern shortAndString trainingActivitySorting;
extern shortAndString incomeTypes;
extern shortAndString expenseTypes;
extern shortAndString siteReadMap;
extern shortAndString buildThisSite;
extern stringAndShort getSpecial;
extern stringAndShort getUnique;
extern stringAndString getLootString;
extern shortAndString reviewStrings;
extern shortAndString reviewStringsSecondLine;
extern vector<stringAndColor> liberalListAndColor;
extern shortAndString issueEventString;
extern shortAndString conservatiseLaw;
extern shortAndString liberalizeLaw;
extern shortAndString discussIssues;
extern shortAndString discussesIssues;
extern shortAndString getCityDescription;
extern shortAndTwoStrings getSiteName;
extern shortAndTwoStrings endgameLawStrings;
extern shortAndString getActivityString;
extern shortAndTwoStrings getViewString;
extern shortAndString getLawString;
extern shortAndString getLawFlagString;
extern shortAndShortAndString getLawFlagStringFull;
extern vector<int> state_biases;
extern shortAndString enumToCreature;
extern stringAndShort getSkillEnumFromString;
extern stringAndShort getAttributeEnumFromString;
extern stringAndShort getCreatureEnumFromString;
extern stringAndShort getBaseEnumFromString;
extern stringAndShort getSpecialWoundEnumFromString;
extern shortAndString conservativeLegalArgument;
extern shortAndString youAreStupidTalkAboutIssues;
extern shortAndString issueTooLiberal;
extern shortAndTwoStrings talkAboutTheIssues;
extern shortAndString tankBodyParts;
extern shortAndString animalBodyParts;
extern shortAndString humanBodyParts;
extern shortAndString supportsLiberalLaw;
extern shortAndString winnerOfElection;
extern shortAndTwoStrings newsStories;
extern shortAndString cityNames;
extern vector<char> supremeChars;
extern vector<char> courtChars;
extern shortAndTwoStrings carchaseObstacles;
extern shortAndString skillEnumToString;
extern shortAndString attEnumToString;
extern shortAndString getAlignString;
extern shortAndString musicList;
bool initialize_more_incomplete_txt();
bool initialize_more_incomplete_txt() {

	// this is the string data for activities. they write up to three lines of text about the activity
	// the ones with a skill on the end (e.g. ACTIVITY_SELL_ART, ACTIVITY_SELL_MUSIC) pick one of the three lines of text based on the skill in question
	data_activities =
	{
		ActivityToData::value_type(ACTIVITY_COMMUNITYSERVICE, data_activity('a', true, "help the elderly, local library, anything", "that is Liberal.")),
		ActivityToData::value_type(ACTIVITY_TROUBLE, data_activity('a', true, "create public disturbances. ")),
		ActivityToData::value_type(ACTIVITY_GRAFFITI, data_activity('a', true, "spray political graffiti. Art and Heart will", "enhance the liberal effect.")),
		ActivityToData::value_type(ACTIVITY_POLLS, data_activity('a', true, "search the internet for public opinion polls.", "Polls will give an idea on how the liberal agenda is going. Computers", "and intelligence will provide better results.")),
		ActivityToData::value_type(ACTIVITY_DOS_ATTACKS, data_activity('a', true, "harass Conservative websites. Computer skill", "will give greater effect.")),
		ActivityToData::value_type(ACTIVITY_HACKING, data_activity('a', true, "harass websites and hack private networks.", "Computer skill and intelligence will give more frequent results.", "Multiple hackers will increase chances of both success and detection.")),
		ActivityToData::value_type(ACTIVITY_WRITE_LETTERS, data_activity('a', true, "write letters to newspapers about current events.")),
		ActivityToData::value_type(ACTIVITY_WRITE_GUARDIAN, data_activity('a', true, "write articles for the LCS's newspaper.")),
		ActivityToData::value_type(ACTIVITY_DONATIONS, data_activity('b', true, "walk around and ask for donations to the LCS.", "Based on persuasion, public's view on the cause, and how well dressed the", "activist is.")),
		ActivityToData::value_type(ACTIVITY_SELL_TSHIRTS, data_activity('b', true, "tie-dye T-shirts and sell them on the street.", "will embroider shirts and sell them on the street.", "will print and distribute shirts with Liberal slogans.", SKILL_TAILORING)),
		ActivityToData::value_type(ACTIVITY_SELL_ART, data_activity('b', true, "sketch people and sell portraits back to them.", "will make pretty paintings and sell them on the streets.", "will create and sell paintings embracing the Liberal agenda.", SKILL_ART)),
		ActivityToData::value_type(ACTIVITY_SELL_MUSIC, data_activity('b', true, "go out into the streets and drum on buckets,", "or play guitar if one is equipped.")),
		ActivityToData::value_type(ACTIVITY_SELL_DRUGS, data_activity('c', true, "bake and sell special adult brownies that open", "magical shimmering doorways to the adamantium pits.")),
		ActivityToData::value_type(ACTIVITY_PROSTITUTION, data_activity('c', true, "trade sex for money.")),
		ActivityToData::value_type(ACTIVITY_CCFRAUD, data_activity('c', true, "commit credit card fraud online.")),
		ActivityToData::value_type(ACTIVITY_DOS_RACKET, data_activity('c', true, "demand money in exchange for not bringing down", "major websites.")),
		ActivityToData::value_type(ACTIVITY_RECRUITING, data_activity('d', true, "try to find someone to join the LCS.")),
		ActivityToData::value_type(ACTIVITY_STEALCARS, data_activity('d', true, "try to find and steal a car.")),
		ActivityToData::value_type(ACTIVITY_MAKE_ARMOR, data_activity('d', true, "make clothing.")), // did not have any strings listed
		ActivityToData::value_type(ACTIVITY_REPAIR_ARMOR, data_activity('d', true, "repair clothing.")), // did not have any strings listed
		ActivityToData::value_type(ACTIVITY_WHEELCHAIR, data_activity('d', true, "try to find a wheelchair.")), // did not have any strings listed
		ActivityToData::value_type(ACTIVITY_AUGMENT, data_activity('d', true, "will augment another Liberal to make them", "physically superior.")),
		ActivityToData::value_type(ACTIVITY_HEAL, data_activity('h', true, "attempt first aid.")), // did not have any strings listed
		ActivityToData::value_type(ACTIVITY_HOSTAGETENDING, data_activity('i', true, "tend to hostages.")), // did not have any strings listed
		ActivityToData::value_type(ACTIVITY_CLINIC, data_activity('m', true, "go to the clinic.")), // did not have any strings listed
		ActivityToData::value_type(ACTIVITY_BURY, data_activity('z', true, "bury dead bodies.")), // did not have any strings listed
		ActivityToData::value_type(ACTIVITY_TEACH_POLITICS, data_activity('t', false, "Skills Trained: Writing, Persuasion, Law, Street Sense, Science,", "Religion, Business, Music, Art", "Classes cost up to $20/day to conduct. All Liberals able will attend.")),
		ActivityToData::value_type(ACTIVITY_TEACH_COVERT, data_activity('t', false, "Skills Trained: Computers, Security, Stealth, Disguise, Tailoring,", "Seduction, Psychology, Driving", "Classes cost up to $60/day to conduct. All Liberals able will attend.")),
		ActivityToData::value_type(ACTIVITY_TEACH_FIGHTING, data_activity('t', false, "Skills Trained: All Weapon Skills, Martial Arts, Dodge, First Aid", "", "Classes cost up to $100/day to conduct. All Liberals able will attend.")),
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
	pollingData = {
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
	trainingActivity = {
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
	 data_lessons = {
		ActivityAndString(ACTIVITY_STUDY_DEBATING,	"Public Policy"),
		ActivityAndString(ACTIVITY_STUDY_BUSINESS,	"Economics"),
		ActivityAndString(ACTIVITY_STUDY_PSYCHOLOGY,	"Psychology"),
		ActivityAndString(ACTIVITY_STUDY_LAW,	"Criminal Law"),
		ActivityAndString(ACTIVITY_STUDY_SCIENCE,	"Physics"),
		ActivityAndString(ACTIVITY_STUDY_DRIVING,	"Drivers Ed"),
		ActivityAndString(ACTIVITY_STUDY_FIRST_AID,	"First Aid"),
		ActivityAndString(ACTIVITY_STUDY_ART,	"Painting"),
		ActivityAndString(ACTIVITY_STUDY_DISGUISE,	"Theatre"),
		ActivityAndString(ACTIVITY_STUDY_MARTIAL_ARTS,"Kung Fu"),
		ActivityAndString(ACTIVITY_STUDY_GYMNASTICS,	"Gymnastics"),
		ActivityAndString(ACTIVITY_STUDY_WRITING,	"Writing"),
		ActivityAndString(ACTIVITY_STUDY_TEACHING,	"Education"),
		ActivityAndString(ACTIVITY_STUDY_MUSIC,	"Music"),
		ActivityAndString(ACTIVITY_STUDY_LOCKSMITHING,"Locksmithing")
	};
	 hackingActivities = {
		activityData("revealed huge political bias in INS processes.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_IMMIGRATION,2,0,75), ChangeOfOpinion(VIEW_FREESPEECH,2,0,75) }), vector<string>({})),
		//Scambaiting, except you're baiting a CEO
		activityData("published emails revealing CEO tax evasion.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_CEOSALARY,2,0,75),	ChangeOfOpinion(VIEW_TAXES,2,0,75) }), vector<string>({})),
		activityData("spread videos of racist police brutality.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_POLICEBEHAVIOR,2,0,75),	ChangeOfOpinion(VIEW_CIVILRIGHTS,2,0,75) }), vector<string>({})),
		// *JDS* Penetrated government networks; don't get any loot, but do scare the info community
		activityData("caused a scare by breaking into a CIA network.", DIFFICULTY_IMPOSSIBLE, 25, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_INTELLIGENCE,10,0,75) }), vector<string>({})),
		activityData("broke into military networks leaving LCS slogans.", DIFFICULTY_IMPOSSIBLE, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_LIBERALCRIMESQUAD,5,0,75) }), vector<string>({})),
		activityData("subverted a Conservative family forum.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_GAY,2,0,75),	ChangeOfOpinion(VIEW_WOMEN,2,0,75) }), vector<string>({})),
		activityData("sabotaged a genetics research company's network.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_GENETICS,2,0,75) }), vector<string>({})),
		activityData("discovered evidence of judicial corruption.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({}), vector<string>({ tag_LOOT_JUDGEFILES })),
		activityData("uncovered information on dangerous research.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({}), vector<string>({ tag_LOOT_RESEARCHFILES })),
		activityData("pilfered files from a Corporate server.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({}), vector<string>({ tag_LOOT_CORPFILES })),
		activityData("intercepted internal media emails.", DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({}), vector<string>({ tag_LOOT_CABLENEWSFILES,tag_LOOT_AMRADIOFILES }))
	};
	activate_menu_items =
	{
		charToVector::value_type('a',vector<ActivityAndString>({ ActivityAndString(1, ACTIVITY_COMMUNITYSERVICE, "Community Service"),
		ActivityAndString(2, ACTIVITY_TROUBLE,	"Liberal Disobedience"),
			ActivityAndString(3, ACTIVITY_GRAFFITI,	"Graffiti"),
			ActivityAndString(4, ACTIVITY_POLLS,	"Search Opinion Polls"),
			//ActivityAndString(ACTIVITY_DOS_ATTACKS, "Harass Websites"),
			ActivityAndString(5, ACTIVITY_HACKING,	"Hacking"),
			ActivityAndString(6, ACTIVITY_WRITE_LETTERS,	"Write to Newspapers"),
			ActivityAndString(7, ACTIVITY_WRITE_GUARDIAN,	"Write for The Liberal Guardian", ACTIVITIY_MENU_CHECK_PRESS) })), // 
		charToVector::value_type('b',vector<ActivityAndString>({ ActivityAndString(1, ACTIVITY_DONATIONS,	"Solicit Donations"),
			ActivityAndString(2, ACTIVITY_SELL_TSHIRTS,	"Sell Tie-Dyed T-Shirts", "Sell Embroidered Shirts", "Sell Liberal T-Shirts", SKILL_TAILORING),
			ActivityAndString(3, ACTIVITY_SELL_ART,	"Sell Portrait Sketches", "Sell Paintings", "Sell Liberal Art", SKILL_ART),
			ActivityAndString(4, ACTIVITY_SELL_MUSIC,	"Play Street Music", "Play Street Music", "Play Liberal Music", SKILL_MUSIC) })),
		charToVector::value_type('c',vector<ActivityAndString>({ ActivityAndString(1, ACTIVITY_SELL_DRUGS,	"Sell Brownies"),
			ActivityAndString(2, ACTIVITY_PROSTITUTION,	"Prostitution", ACTIVITIY_MENU_CHECK_AGE),
			//	ActivityAndString(ACTIVITY_DOS_RACKET, "Electronic Protection Racket"),
			ActivityAndString(3, ACTIVITY_CCFRAUD,	"Steal Credit Card Numbers") })),
		charToVector::value_type('d',vector<ActivityAndString>({ ActivityAndString(1, ACTIVITY_RECRUITING,	"Recruiting"),
			ActivityAndString(2, ACTIVITY_MAKE_ARMOR,	"Make Clothing"),
			ActivityAndString(3, ACTIVITY_REPAIR_ARMOR,	"Repair Clothing"),
			ActivityAndString(4, ACTIVITY_STEALCARS,	"Steal a Car", ACTIVITIY_MENU_CHECK_CAN_WALK),
			ActivityAndString(5, ACTIVITY_WHEELCHAIR,	"Procure a Wheelchair", ACTIVITIY_MENU_CHECK_WHEELCHAIR),
			ActivityAndString(6, ACTIVITY_AUGMENT, "Augment a Liberal", ACTIVITIY_MENU_CHECK_CAN_AUGMENT) })),
		charToVector::value_type('t',vector<ActivityAndString>({ ActivityAndString(0,  ACTIVITY_NONE,	"Teach Liberals About What?"),
			ActivityAndString(1, ACTIVITY_TEACH_POLITICS,	"Political Activism"),
			ActivityAndString(2, ACTIVITY_TEACH_COVERT,	"Infiltration"),
			ActivityAndString(3, ACTIVITY_TEACH_FIGHTING,	"Urban Warfare") }))
	};

	 recruitable_creatures = {
		recruitData(CREATURE_VETERAN, "Army Veteran", 4),
		recruitData(CREATURE_ATHLETE, "Athlete", 4),
		recruitData(CREATURE_COLLEGESTUDENT, "College Student", 1),
		recruitData(CREATURE_PROGRAMMER, "Computer Programmer", 4),
		recruitData(CREATURE_DANCER, "Dancer", 4),
		recruitData(CREATURE_DOCTOR, "Doctor", 4),
		recruitData(CREATURE_FASHIONDESIGNER, "Fashion Designer", 6),
		recruitData(CREATURE_GANGMEMBER, "Gang Member", 2),
		recruitData(CREATURE_HIPPIE, "Hippie", 1),
		recruitData(CREATURE_JOURNALIST, "Journalist", 4),
		recruitData(CREATURE_JUDGE_LIBERAL, "Judge", 6),
		recruitData(CREATURE_LAWYER, "Lawyer", 4),
		recruitData(CREATURE_LOCKSMITH, "Locksmith", 6),
		recruitData(CREATURE_MARTIALARTIST, "Martial Artist", 4),
		recruitData(CREATURE_MUSICIAN, "Musician", 4),
		recruitData(CREATURE_MUTANT, "Mutant", 4),
		recruitData(CREATURE_PROSTITUTE, "Prostitute", 2),
		recruitData(CREATURE_PSYCHOLOGIST, "Psychologist", 4),
		recruitData(CREATURE_TAXIDRIVER, "Taxi Driver", 4),
		recruitData(CREATURE_TEACHER, "Teacher", 4)
	};
	trainingActivitySorting = {
		shortAndString::value_type(SORTINGCHOICE_LIBERALS, "active Liberals."),
		shortAndString::value_type(SORTINGCHOICE_HOSTAGES, "hostages."),
		shortAndString::value_type(SORTINGCHOICE_CLINIC, "Liberals in hospital."),
		shortAndString::value_type(SORTINGCHOICE_JUSTICE, "oppressed Liberals."),
		shortAndString::value_type(SORTINGCHOICE_SLEEPERS, "sleepers."),
		shortAndString::value_type(SORTINGCHOICE_DEAD, "dead people."),
		shortAndString::value_type(SORTINGCHOICE_AWAY, "people away."),
		shortAndString::value_type(SORTINGCHOICE_ACTIVATE, "Liberal activity."),
		shortAndString::value_type(SORTINGCHOICE_ACTIVATESLEEPERS, "sleeper activity."),
		shortAndString::value_type(SORTINGCHOICE_ASSEMBLESQUAD, "available Liberals."),
		shortAndString::value_type(SORTINGCHOICE_BASEASSIGN, "squadless members."),
		shortAndString::value_type(SORTINGCHOICENUM,"ERROR: INVALID VALUE FOR SORTINGCHOICE!")
	};
	incomeTypes = {
		shortAndString::value_type(INCOME_BROWNIES,"Brownies"),
		shortAndString::value_type(INCOME_CARS,"Car Sales"),
		shortAndString::value_type(INCOME_CCFRAUD,"Credit Card Fraud"),
		shortAndString::value_type(INCOME_DONATIONS,"Donations"),
		shortAndString::value_type(INCOME_SKETCHES,"Drawing Sales"),
		shortAndString::value_type(INCOME_EMBEZZLEMENT,"Embezzlement"),
		shortAndString::value_type(INCOME_EXTORTION,"Extortion"),
		shortAndString::value_type(INCOME_HUSTLING,"Hustling"),
		shortAndString::value_type(INCOME_PAWN,"Pawning Goods"),
		shortAndString::value_type(INCOME_PROSTITUTION,"Prostitution"),
		shortAndString::value_type(INCOME_BUSKING,"Street Music"),
		shortAndString::value_type(INCOME_THIEVERY,"Thievery"),
		shortAndString::value_type(INCOME_TSHIRTS,"T-Shirt Sales"),
		shortAndString::value_type(INCOMETYPENUM,"Other Income")
	};
	expenseTypes = {
		shortAndString::value_type(EXPENSE_TROUBLEMAKING, "Activism"),
		shortAndString::value_type(EXPENSE_CONFISCATED, "Confiscated"),
		shortAndString::value_type(EXPENSE_DATING, "Dating"),
		shortAndString::value_type(EXPENSE_SKETCHES, "Drawing Materials"),
		shortAndString::value_type(EXPENSE_FOOD, "Groceries"),
		shortAndString::value_type(EXPENSE_HOSTAGE, "Hostage Tending"),
		shortAndString::value_type(EXPENSE_LEGAL, "Legal Fees"),
		shortAndString::value_type(EXPENSE_MANUFACTURE, "Manufacturing"),
		shortAndString::value_type(EXPENSE_CARS, "New Cars"),
		shortAndString::value_type(EXPENSE_SHOPPING, "Purchasing Goods"),
		shortAndString::value_type(EXPENSE_RECRUITMENT, "Recruitment"),
		shortAndString::value_type(EXPENSE_RENT, "Rent"),
		shortAndString::value_type(EXPENSE_COMPOUND, "Safehouse Investments"),
		shortAndString::value_type(EXPENSE_TRAINING, "Training"),
		shortAndString::value_type(EXPENSE_TRAVEL, "Travel"),
		shortAndString::value_type(EXPENSE_TSHIRTS, "T-Shirt Materials"),
		shortAndString::value_type(EXPENSETYPENUM, "Other Expenses")
	};
	siteReadMap = {
		shortAndString::value_type(SITE_RESIDENTIAL_TENEMENT, "ApartmentIndustrial"),
		shortAndString::value_type(SITE_RESIDENTIAL_APARTMENT, "ApartmentUniversity"),
		shortAndString::value_type(SITE_RESIDENTIAL_APARTMENT_UPSCALE, "ApartmentDowntown"),
		shortAndString::value_type(SITE_INDUSTRY_WAREHOUSE, "Warehouse"),
		shortAndString::value_type(SITE_RESIDENTIAL_SHELTER, "HomelessShelter"),
		shortAndString::value_type(SITE_BUSINESS_CRACKHOUSE, "CrackHouse"),
		shortAndString::value_type(SITE_BUSINESS_BARANDGRILL, "BarAndGrill"),
		shortAndString::value_type(SITE_RESIDENTIAL_BOMBSHELTER, "BombShelter"),
		shortAndString::value_type(SITE_OUTDOOR_BUNKER, "Bunker"),
		shortAndString::value_type(SITE_LABORATORY_COSMETICS, "CosmeticsLab"),
		shortAndString::value_type(SITE_LABORATORY_GENETIC, "GeneticsLab"),
		shortAndString::value_type(SITE_GOVERNMENT_POLICESTATION, "PoliceStation"),
		shortAndString::value_type(SITE_GOVERNMENT_COURTHOUSE, "Courthouse"),
		shortAndString::value_type(SITE_GOVERNMENT_PRISON, "Prison"),
		shortAndString::value_type(SITE_GOVERNMENT_INTELLIGENCEHQ, "IntelligenceHQ"),
		shortAndString::value_type(SITE_GOVERNMENT_ARMYBASE, "ArmyBase"),
		shortAndString::value_type(SITE_GOVERNMENT_FIRESTATION, "FireStation"),
		shortAndString::value_type(SITE_INDUSTRY_SWEATSHOP, "Sweatshop"),
		shortAndString::value_type(SITE_INDUSTRY_POLLUTER, "Factory"),
		shortAndString::value_type(SITE_CORPORATE_HEADQUARTERS, "CorporateHQ"),
		shortAndString::value_type(SITE_CORPORATE_HOUSE, "CEOHouse"),
		shortAndString::value_type(SITE_MEDIA_AMRADIO, "RadioStation"),
		shortAndString::value_type(SITE_MEDIA_CABLENEWS, "CableNews"),
		shortAndString::value_type(SITE_BUSINESS_JUICEBAR, "JuiceBar"),
		shortAndString::value_type(SITE_BUSINESS_INTERNETCAFE, "InternetCafe"),
		shortAndString::value_type(SITE_BUSINESS_CIGARBAR, "CigarBar"),
		shortAndString::value_type(SITE_BUSINESS_LATTESTAND, "LatteStand"),
		shortAndString::value_type(SITE_BUSINESS_VEGANCOOP, "VeganCoOp"),
		shortAndString::value_type(SITE_OUTDOOR_PUBLICPARK, "Park"),
		shortAndString::value_type(SITE_BUSINESS_BANK, "Bank"),
		shortAndString::value_type(SITE_INDUSTRY_NUCLEAR, "NuclearPlant"),
		shortAndString::value_type(SITE_GOVERNMENT_WHITE_HOUSE, "WhiteHouse")
	};
	buildThisSite = {
		shortAndString::value_type(SITE_RESIDENTIAL_TENEMENT,"RESIDENTIAL_APARTMENT"),
		shortAndString::value_type(SITE_RESIDENTIAL_APARTMENT,"RESIDENTIAL_APARTMENT"),
		shortAndString::value_type(SITE_RESIDENTIAL_APARTMENT_UPSCALE,"RESIDENTIAL_APARTMENT"),
		shortAndString::value_type(SITE_INDUSTRY_WAREHOUSE,"GENERIC_UNSECURE"),
		shortAndString::value_type(SITE_RESIDENTIAL_SHELTER,"GENERIC_UNSECURE"),
		shortAndString::value_type(SITE_BUSINESS_CRACKHOUSE,"GENERIC_UNSECURE"),
		shortAndString::value_type(SITE_BUSINESS_BANK,"GENERIC_LOBBY"),
		shortAndString::value_type(SITE_BUSINESS_BARANDGRILL,"GENERIC_LOBBY"),
		shortAndString::value_type(SITE_RESIDENTIAL_BOMBSHELTER,"GENERIC_LOBBY"),
		shortAndString::value_type(SITE_OUTDOOR_BUNKER,"GENERIC_LOBBY"),
		shortAndString::value_type(SITE_GOVERNMENT_FIRESTATION,"GENERIC_LOBBY"),
		shortAndString::value_type(SITE_LABORATORY_COSMETICS,"LABORATORY_COSMETICS"),
		shortAndString::value_type(SITE_LABORATORY_GENETIC,"LABORATORY_GENETICS"),
		shortAndString::value_type(SITE_GOVERNMENT_POLICESTATION,"GOVERNMENT_POLICESTATION"),
		shortAndString::value_type(SITE_GOVERNMENT_COURTHOUSE,"GOVERNMENT_COURTHOUSE"),
		shortAndString::value_type(SITE_GOVERNMENT_PRISON,"GOVERNMENT_PRISON"),
		shortAndString::value_type(SITE_GOVERNMENT_INTELLIGENCEHQ,"GOVERNMENT_INTELLIGENCEHQ"),
		shortAndString::value_type(SITE_GOVERNMENT_WHITE_HOUSE,"GOVERNMENT_WHITE_HOUSE"),
		shortAndString::value_type(SITE_GOVERNMENT_ARMYBASE,"GOVERNMENT_ARMYBASE"),
		shortAndString::value_type(SITE_INDUSTRY_SWEATSHOP,"INDUSTRY_SWEATSHOP"),
		shortAndString::value_type(SITE_INDUSTRY_POLLUTER,"INDUSTRY_POLLUTER"),
		shortAndString::value_type(SITE_INDUSTRY_NUCLEAR,"INDUSTRY_NUCLEAR"),
		shortAndString::value_type(SITE_CORPORATE_HEADQUARTERS,"CORPORATE_HEADQUARTERS"),
		shortAndString::value_type(SITE_CORPORATE_HOUSE,"CORPORATE_HOUSE"),
		shortAndString::value_type(SITE_MEDIA_AMRADIO,"MEDIA_AMRADIO"),
		shortAndString::value_type(SITE_MEDIA_CABLENEWS,"MEDIA_CABLENEWS"),
		shortAndString::value_type(SITE_BUSINESS_JUICEBAR,"BUSINESS_CAFE"),
		shortAndString::value_type(SITE_BUSINESS_INTERNETCAFE,"BUSINESS_INTERNETCAFE"),
		shortAndString::value_type(SITE_BUSINESS_CIGARBAR,"BUSINESS_RESTRICTEDCAFE"),
		shortAndString::value_type(SITE_BUSINESS_LATTESTAND,"OUTDOOR_LATTESTAND"),
		shortAndString::value_type(SITE_BUSINESS_VEGANCOOP,"GENERIC_ONEROOM"),
		shortAndString::value_type(SITE_OUTDOOR_PUBLICPARK,"OUTDOOR_PUBLICPARK"),
	};
	getSpecial = {
		stringAndShort::value_type("LAB_COSMETICS_CAGEDANIMALS", SPECIAL_LAB_COSMETICS_CAGEDANIMALS),
		stringAndShort::value_type("LAB_GENETIC_CAGEDANIMALS", SPECIAL_LAB_GENETIC_CAGEDANIMALS),
		stringAndShort::value_type("POLICESTATION_LOCKUP", SPECIAL_POLICESTATION_LOCKUP),
		stringAndShort::value_type("COURTHOUSE_LOCKUP", SPECIAL_COURTHOUSE_LOCKUP),
		stringAndShort::value_type("COURTHOUSE_JURYROOM", SPECIAL_COURTHOUSE_JURYROOM),
		stringAndShort::value_type("PRISON_CONTROL", SPECIAL_PRISON_CONTROL),
		stringAndShort::value_type("PRISON_CONTROL_LOW", SPECIAL_PRISON_CONTROL_LOW),
		stringAndShort::value_type("PRISON_CONTROL_MEDIUM", SPECIAL_PRISON_CONTROL_MEDIUM),
		stringAndShort::value_type("PRISON_CONTROL_HIGH", SPECIAL_PRISON_CONTROL_HIGH),
		stringAndShort::value_type("INTEL_SUPERCOMPUTER", SPECIAL_INTEL_SUPERCOMPUTER),
		stringAndShort::value_type("SWEATSHOP_EQUIPMENT", SPECIAL_SWEATSHOP_EQUIPMENT),
		stringAndShort::value_type("POLLUTER_EQUIPMENT", SPECIAL_POLLUTER_EQUIPMENT),
		stringAndShort::value_type("NUCLEAR_ONOFF", SPECIAL_NUCLEAR_ONOFF),
		stringAndShort::value_type("HOUSE_PHOTOS", SPECIAL_HOUSE_PHOTOS),
		stringAndShort::value_type("ARMYBASE_ARMORY", SPECIAL_ARMORY),
		stringAndShort::value_type("HOUSE_CEO", SPECIAL_HOUSE_CEO),
		stringAndShort::value_type("CORPORATE_FILES", SPECIAL_CORPORATE_FILES),
		stringAndShort::value_type("RADIO_BROADCASTSTUDIO", SPECIAL_RADIO_BROADCASTSTUDIO),
		stringAndShort::value_type("NEWS_BROADCASTSTUDIO", SPECIAL_NEWS_BROADCASTSTUDIO),
		stringAndShort::value_type("APARTMENT_LANDLORD", SPECIAL_APARTMENT_LANDLORD),
		stringAndShort::value_type("APARTMENT_SIGN", SPECIAL_SIGN_ONE),
		stringAndShort::value_type("RESTAURANT_TABLE", SPECIAL_RESTAURANT_TABLE),
		stringAndShort::value_type("CAFE_COMPUTER", SPECIAL_CAFE_COMPUTER),
		stringAndShort::value_type("PARK_BENCH", SPECIAL_PARK_BENCH),
		stringAndShort::value_type("STAIRS_UP", SPECIAL_STAIRS_UP),
		stringAndShort::value_type("STAIRS_DOWN", SPECIAL_STAIRS_DOWN),
		stringAndShort::value_type("CLUB_BOUNCER", SPECIAL_CLUB_BOUNCER),
		stringAndShort::value_type("CLUB_BOUNCER_SECONDVISIT", SPECIAL_CLUB_BOUNCER_SECONDVISIT)
	};
	getUnique = {
		stringAndShort::value_type("LAB_COSMETICS_CAGEDANIMALS", SPECIAL_LAB_COSMETICS_CAGEDANIMALS),
		stringAndShort::value_type("LAB_GENETIC_CAGEDANIMALS", SPECIAL_LAB_GENETIC_CAGEDANIMALS),
		stringAndShort::value_type("POLICESTATION_LOCKUP", SPECIAL_POLICESTATION_LOCKUP),
		stringAndShort::value_type("COURTHOUSE_LOCKUP", SPECIAL_COURTHOUSE_LOCKUP),
		stringAndShort::value_type("COURTHOUSE_JURYROOM", SPECIAL_COURTHOUSE_JURYROOM),
		stringAndShort::value_type("PRISON_CONTROL", SPECIAL_PRISON_CONTROL),
		stringAndShort::value_type("PRISON_CONTROL_LOW", SPECIAL_PRISON_CONTROL_LOW),
		stringAndShort::value_type("PRISON_CONTROL_MEDIUM", SPECIAL_PRISON_CONTROL_MEDIUM),
		stringAndShort::value_type("PRISON_CONTROL_HIGH", SPECIAL_PRISON_CONTROL_HIGH),
		stringAndShort::value_type("INTEL_SUPERCOMPUTER", SPECIAL_INTEL_SUPERCOMPUTER),
		stringAndShort::value_type("SWEATSHOP_EQUIPMENT", SPECIAL_SWEATSHOP_EQUIPMENT),
		stringAndShort::value_type("POLLUTER_EQUIPMENT", SPECIAL_POLLUTER_EQUIPMENT),
		stringAndShort::value_type("NUCLEAR_ONOFF", SPECIAL_NUCLEAR_ONOFF),
		stringAndShort::value_type("HOUSE_PHOTOS", SPECIAL_HOUSE_PHOTOS),
		stringAndShort::value_type("ARMYBASE_ARMORY", SPECIAL_ARMORY),
		stringAndShort::value_type("HOUSE_CEO", SPECIAL_HOUSE_CEO),
		stringAndShort::value_type("CORPORATE_FILES", SPECIAL_CORPORATE_FILES),
		stringAndShort::value_type("RADIO_BROADCASTSTUDIO", SPECIAL_RADIO_BROADCASTSTUDIO),
		stringAndShort::value_type("NEWS_BROADCASTSTUDIO", SPECIAL_NEWS_BROADCASTSTUDIO),
		stringAndShort::value_type("APARTMENT_LANDLORD", SPECIAL_APARTMENT_LANDLORD),
		stringAndShort::value_type("APARTMENT_SIGN", SPECIAL_SIGN_ONE),
		stringAndShort::value_type("RESTAURANT_TABLE", SPECIAL_RESTAURANT_TABLE),
		stringAndShort::value_type("CAFE_COMPUTER", SPECIAL_CAFE_COMPUTER),
		stringAndShort::value_type("PARK_BENCH", SPECIAL_PARK_BENCH),
		stringAndShort::value_type("STAIRS_UP", SPECIAL_STAIRS_UP),
		stringAndShort::value_type("STAIRS_DOWN", SPECIAL_STAIRS_DOWN),
		stringAndShort::value_type("CLUB_BOUNCER", SPECIAL_CLUB_BOUNCER),
		stringAndShort::value_type("CLUB_BOUNCER_SECONDVISIT", SPECIAL_CLUB_BOUNCER_SECONDVISIT)
	};
	getLootString = {
		stringAndString::value_type("FINECLOTH",tag_LOOT_FINECLOTH),
		stringAndString::value_type("CHEMICAL",tag_LOOT_CHEMICAL),
		stringAndString::value_type("PDA",tag_LOOT_PDA),
		stringAndString::value_type("LABEQUIPMENT",tag_LOOT_LABEQUIPMENT),
		stringAndString::value_type("LAPTOP",tag_LOOT_COMPUTER),
		stringAndString::value_type("CHEAPJEWELERY",tag_LOOT_CHEAPJEWELERY),
		stringAndString::value_type("SECRETDOCUMENTS",tag_LOOT_SECRETDOCUMENTS),
		stringAndString::value_type("CEOPHOTOS",tag_LOOT_CEOPHOTOS),
		stringAndString::value_type("INTHQDISK",tag_LOOT_INTHQDISK),
		stringAndString::value_type("CORPFILES",tag_LOOT_CORPFILES),
		stringAndString::value_type("JUDGEFILES",tag_LOOT_JUDGEFILES),
		stringAndString::value_type("RESEARCHFILES",tag_LOOT_RESEARCHFILES),
		stringAndString::value_type("PRISONFILES",tag_LOOT_PRISONFILES),
		stringAndString::value_type("CABLENEWSFILES",tag_LOOT_CABLENEWSFILES),
		stringAndString::value_type("AMRADIOFILES",tag_LOOT_AMRADIOFILES),
		stringAndString::value_type("POLICERECORDS",tag_LOOT_POLICERECORDS),
		stringAndString::value_type("FINEJEWELERY",tag_LOOT_EXPENSIVEJEWELERY),
		stringAndString::value_type("CELLPHONE",tag_LOOT_CELLPHONE),
		stringAndString::value_type("MICROPHONE",tag_LOOT_MICROPHONE),
		stringAndString::value_type("WATCH",tag_LOOT_WATCH),
		stringAndString::value_type("SILVERWARE",tag_LOOT_SILVERWARE),
		stringAndString::value_type("TRINKET",tag_LOOT_TRINKET)
	};
	reviewStrings = {
		shortAndString::value_type(REVIEWMODE_LIBERALS, "Active Liberals"),
		shortAndString::value_type(REVIEWMODE_HOSTAGES,	"Conservative Automatons in Captivity"),
		shortAndString::value_type(REVIEWMODE_CLINIC,	"Liberals in CLINICS"),
		shortAndString::value_type(REVIEWMODE_JUSTICE,	"Liberals and the Justice System"),
		shortAndString::value_type(REVIEWMODE_SLEEPERS,	"Sleepers"),
		shortAndString::value_type(REVIEWMODE_DEAD,	"Liberal Martyrs and Dead Bodies"),
		shortAndString::value_type(REVIEWMODE_AWAY,	"Liberals that are Away")
	};
	reviewStringsSecondLine = {
		shortAndString::value_type(REVIEWMODE_LIBERALS, "SQUAD / ACTIVITY"),
		shortAndString::value_type(REVIEWMODE_HOSTAGES,	"DAYS IN CAPTIVITY"),
		shortAndString::value_type(REVIEWMODE_CLINIC,	"MONTHS LEFT"),
		shortAndString::value_type(REVIEWMODE_JUSTICE,	"PROGNOSIS"),
		shortAndString::value_type(REVIEWMODE_SLEEPERS,	"PROFESSION"),
		shortAndString::value_type(REVIEWMODE_DEAD,	"DAYS SINCE PASSING"),
		shortAndString::value_type(REVIEWMODE_AWAY,	"DAYS UNTIL RETURN")
	};
	 liberalListAndColor = {
		stringAndColor(WHITE_ON_BLACK,	"Recruited/"),
		stringAndColor(MAGENTA_ON_BLACK,	"Seduced"),
		stringAndColor(WHITE_ON_BLACK,	"/"),
		stringAndColor(YELLOW_ON_BLACK,	"Enlightened"),
		stringAndColor(YELLOW_ON_BLACK_BRIGHT,	"   ["),
		stringAndColor(WHITE_ON_BLACK,	"Arrested"),
		stringAndColor(YELLOW_ON_BLACK_BRIGHT,	"]"),
		stringAndColor(RED_ON_BLACK_BRIGHT,	" ["),
		stringAndColor(WHITE_ON_BLACK,	"In Jail"),
		stringAndColor(RED_ON_BLACK_BRIGHT,	"]"),
		stringAndColor(BLACK_ON_BLACK_BRIGHT,	" ["),
		stringAndColor(WHITE_ON_BLACK,	"In Hiding"),
		stringAndColor(BLACK_ON_BLACK_BRIGHT,	"]"),
		stringAndColor(BLUE_ON_BLACK_BRIGHT,	" ["),
		stringAndColor(WHITE_ON_BLACK,	"Sleeper"),
		stringAndColor(BLUE_ON_BLACK_BRIGHT,	"]")
	};
	issueEventString = {
		shortAndString::value_type(VIEW_DRUGS, "a collection of studies on the health effects of marijuana"),
		shortAndString::value_type(VIEW_MILITARY, "a book on the history of military atrocities"),
		shortAndString::value_type(VIEW_IMMIGRATION, "a reality TV episode on the lives of immigrants"),
		shortAndString::value_type(VIEW_CIVILRIGHTS, "a documentary on the civil rights struggle"),
		shortAndString::value_type(VIEW_WOMEN, "a documentary on the women's rights struggle"),
		shortAndString::value_type(VIEW_GAY, "a documentary on the gay rights struggle"),
		shortAndString::value_type(VIEW_DEATHPENALTY, "a research paper on abuses of the death penalty"),
		shortAndString::value_type(VIEW_TAXES, "an economic paper on the flaws of trickle-down"),
		shortAndString::value_type(VIEW_NUCLEARPOWER, "a video tour of the Chernobyl dead zone"),
		shortAndString::value_type(VIEW_ANIMALRESEARCH, "a documentary on animal research"),
		shortAndString::value_type(VIEW_POLICEBEHAVIOR, "a hand-recorded video of police brutality"),
		shortAndString::value_type(VIEW_TORTURE, "a government inquiry into military interrogations"),
		shortAndString::value_type(VIEW_PRISONS, "a documentary on the prisoners' suffering"),
		shortAndString::value_type(VIEW_INTELLIGENCE, "a documentary on privacy rights"),
		shortAndString::value_type(VIEW_FREESPEECH, "a collection of banned books"),
		shortAndString::value_type(VIEW_GENETICS, "a video about genetic engineering accidents"),
		shortAndString::value_type(VIEW_JUSTICES, "a Liberal policy paper inquiring into judicial decisions"),
		shortAndString::value_type(VIEW_GUNCONTROL, "a book profiling school shootings"),
		shortAndString::value_type(VIEW_SWEATSHOPS, "a hand-recorded video of unregulated sweatshops"),
		shortAndString::value_type(VIEW_POLLUTION, "a leaked government paper on environmental conditions"),
		shortAndString::value_type(VIEW_CORPORATECULTURE, "a documentary on life under corporate culture"),
		shortAndString::value_type(VIEW_CEOSALARY, "a Liberal think-tank survey of top CEO salaries"),
		shortAndString::value_type(VIEW_AMRADIO, "a collection of Conservative radio host rants"),
		shortAndString::value_type(VIEW_CABLENEWS, "a collection of leaked Conservative cable news memos")
		//shortAndString::value_type( VIEW_POLITICALVIOLENCE,"a documentary about progress made by direct action"),
	};
	conservatiseLaw = {
		shortAndString::value_type(LAW_ABORTION,	"Protect the Unborn Child"),
		shortAndString::value_type(LAW_ANIMALRESEARCH,	"Help Scientists Cure Diseases"), // was "Expand Animal Research"
		shortAndString::value_type(LAW_POLICEBEHAVIOR,	"Help Police Fight Crime"), // was "Stop Harassment of Police Officers"
		shortAndString::value_type(LAW_PRIVACY,	"Promote Transparency and Accountability"), // was "Allow Corporations Access to Information"
		shortAndString::value_type(LAW_DEATHPENALTY,	"Deter Criminals via Capital Punishment"), // "Expand Capital Punishment"
		shortAndString::value_type(LAW_NUCLEARPOWER,	"Promote Alternative Energy Sources"), // was "Expand Nuclear Power"
		shortAndString::value_type(LAW_POLLUTION,	"Support American Manufacturing"), // was "Reward Industry"
		shortAndString::value_type(LAW_LABOR,	"Fight Corrupt Union Thugs"), // was "End Undue Union Influence"
		shortAndString::value_type(LAW_GAY,	"Support the Sanctity of Marriage"),
		shortAndString::value_type(LAW_CORPORATE,	"Help Small Businesses Expand"), // was "Reward Small Businesses"
		shortAndString::value_type(LAW_FREESPEECH,	"Limit Hate Speech"), // was "Limit Hurtful Speech"
		shortAndString::value_type(LAW_TAX,	"Cut Job-Killing Taxes"), // was "Stimulate Economic Growth"
		shortAndString::value_type(LAW_FLAGBURNING,	"Protect the Symbol of Our Nation"),
		shortAndString::value_type(LAW_GUNCONTROL,	"Protect our Second Amendment Rights"), // was "Assert our Second Amendment Rights"
		shortAndString::value_type(LAW_WOMEN,	"Preserve Traditional Gender Roles"),
		shortAndString::value_type(LAW_CIVILRIGHTS,	"Fight Reverse Discrimination"),
		shortAndString::value_type(LAW_DRUGS,	"Fight Drug Trafficking"), // was "Strengthen the War On Drugs"
		shortAndString::value_type(LAW_IMMIGRATION,	"Protect our Borders"),
		shortAndString::value_type(LAW_ELECTIONS,	"Limit Regulation of Political Speech"), // was "Limit Campaign Finance Reforms"
		shortAndString::value_type(LAW_MILITARY,	"Support our Troops in Defending America"), // was "Strengthen our National Defense"
		shortAndString::value_type(LAW_TORTURE,	"Enhance Interrogations to Fight Terrorism"), // was "Permit Strong Tactics in Interrogations"
		shortAndString::value_type(LAW_PRISONS,	"Enhance Prison Security") // was "Limit Prisoners' Rights"
	};
	liberalizeLaw = {
		shortAndString::value_type(LAW_ABORTION, "Strengthen Reproductive Freedom"), // was "Strengthen Abortion Rights"
		shortAndString::value_type(LAW_ANIMALRESEARCH, "Limit Animal Cruelty"),
		shortAndString::value_type(LAW_POLICEBEHAVIOR,	"Curtail Police Misconduct"),
		shortAndString::value_type(LAW_PRIVACY,	"Enhance Privacy Protection"),
		shortAndString::value_type(LAW_DEATHPENALTY,	"Stop Barbaric Executions"), // was "Limit the Death Penalty"
		shortAndString::value_type(LAW_NUCLEARPOWER,	"Prevent Nuclear Meltdowns"), // was "Limit Nuclear Power"
		shortAndString::value_type(LAW_POLLUTION,	"Protect our Environment"), // was "Punish Polluters"
		shortAndString::value_type(LAW_LABOR,	"Protect Workers' Rights"), // was "Enhance Labor Standards"
		shortAndString::value_type(LAW_GAY,	"Fight Homophobic Bigotry in our Laws"), // was "Expand Homosexual Rights"
		shortAndString::value_type(LAW_CORPORATE,	"Stop Corporate Criminals"),
		shortAndString::value_type(LAW_FREESPEECH,	"Protect Free Speech"),
		shortAndString::value_type(LAW_TAX,	"Fight Income Inequality"), // was "Punish the Wealthy"
		shortAndString::value_type(LAW_FLAGBURNING,	"Limit Prohibitions on Flag Burning"),
		shortAndString::value_type(LAW_GUNCONTROL,	"Prevent Mass Shootings"), // was "Prevent Gun Violence"
		shortAndString::value_type(LAW_WOMEN,	"Promote Gender Equality"), // was "Expand Women's Rights"
		shortAndString::value_type(LAW_CIVILRIGHTS,	"Promote Racial Equality"), // was "Expand Civil Rights"
		shortAndString::value_type(LAW_DRUGS,	"Repeal Oppressive Drug Laws"), // was "Limit Oppressive Drug Laws"
		shortAndString::value_type(LAW_IMMIGRATION,	"Protect Immigrant Rights"),
		shortAndString::value_type(LAW_ELECTIONS,	"Fight Political Corruption"),
		shortAndString::value_type(LAW_MILITARY,	"Shrink the Military-Industrial Complex"), // was "Limit Military Spending"
		shortAndString::value_type(LAW_TORTURE,	"Protect Human Rights from Torture") // was "Ban Torture Techniques"
	};
	discussIssues = {
		shortAndString::value_type(VIEW_GAY, "discuss homosexual rights."),
		shortAndString::value_type(VIEW_DEATHPENALTY, "examine the death penalty."),
		shortAndString::value_type(VIEW_TAXES, "discuss the tax code."),
		shortAndString::value_type(VIEW_NUCLEARPOWER , "run down nuclear power."),
		shortAndString::value_type(VIEW_ANIMALRESEARCH , "discuss the horrors of animal research."),
		shortAndString::value_type(VIEW_POLICEBEHAVIOR , "go over cases of police brutality."),
		shortAndString::value_type(VIEW_TORTURE, "discuss prisoner abuse and torture."),
		shortAndString::value_type(VIEW_PRISONS, "discuss the prison system's flaws."),
		shortAndString::value_type(VIEW_INTELLIGENCE , "debate privacy law."),
		shortAndString::value_type(VIEW_FREESPEECH , "talk about free speech."),
		shortAndString::value_type(VIEW_GENETICS , "discuss the implications of genetic research."),
		shortAndString::value_type(VIEW_JUSTICES , "talk about the record of a Conservative judge."),
		shortAndString::value_type(VIEW_GUNCONTROL , "talk about gun control."),
		shortAndString::value_type(VIEW_SWEATSHOPS , "bring details about sweatshops to light."),
		shortAndString::value_type(VIEW_POLLUTION, "do a show on industrial pollution."),
		shortAndString::value_type(VIEW_CORPORATECULTURE , "joke about corporate culture."),
		shortAndString::value_type(VIEW_CEOSALARY, "give examples of CEO excesses."),
		shortAndString::value_type(VIEW_WOMEN, "discuss abortion."),// "Performs an abortion live on the air." // Get [LAWFLAG_SPEECH], [LAWFLAG_MURDER], [LAWFLAG_DISTURBANCE] -- LK case VIEW_CIVILRIGHTS, "debates affirmative action."),
		shortAndString::value_type(VIEW_DRUGS, "have a frank talk about drugs."),
		shortAndString::value_type(VIEW_IMMIGRATION, "examine the issue of immigration."),
		shortAndString::value_type(VIEW_MILITARY, "talk about militarism in modern culture."),
		shortAndString::value_type(VIEW_AMRADIO, "discuss other AM radio shows."),
		shortAndString::value_type(VIEW_CABLENEWS, "talk about Cable News."),
		shortAndString::value_type(VIEW_LIBERALCRIMESQUAD, "let people know about the Liberal Crime Squad."),
		shortAndString::value_type(VIEW_LIBERALCRIMESQUADPOS, "extol the virtues of the Liberal Crime Squad."),
		shortAndString::value_type(VIEW_CONSERVATIVECRIMESQUAD , "demonize the Conservative Crime Squad.")
	};
	discussesIssues = {
		shortAndString::value_type(VIEW_GAY, "discusses homosexual rights."),
		shortAndString::value_type(VIEW_DEATHPENALTY, "examines the death penalty."),
		shortAndString::value_type(VIEW_TAXES, "discusses the tax code."),
		shortAndString::value_type(VIEW_NUCLEARPOWER , "runs down nuclear power."),
		shortAndString::value_type(VIEW_ANIMALRESEARCH , "discusses the horrors of animal research."),
		shortAndString::value_type(VIEW_POLICEBEHAVIOR , "goes over cases of police brutality."),
		shortAndString::value_type(VIEW_TORTURE, "discusses prisoner abuse and torture."),
		shortAndString::value_type(VIEW_PRISONS, "discusses the prison system's flaws."),
		shortAndString::value_type(VIEW_INTELLIGENCE , "debates privacy law."),
		shortAndString::value_type(VIEW_FREESPEECH , "talks about free speech."),
		shortAndString::value_type(VIEW_GENETICS , "discusses the implications of genetic research."),
		shortAndString::value_type(VIEW_JUSTICES , "talks about the record of a Conservative judge."),
		shortAndString::value_type(VIEW_GUNCONTROL , "talks about gun control."),
		shortAndString::value_type(VIEW_SWEATSHOPS , "brings details about sweatshops to light."),
		shortAndString::value_type(VIEW_POLLUTION, "does a show on industrial pollution."),
		shortAndString::value_type(VIEW_CORPORATECULTURE , "jokes about corporate culture."),
		shortAndString::value_type(VIEW_CEOSALARY, "gives examples of CEO excesses."),
		shortAndString::value_type(VIEW_WOMEN, "discusses abortion."),// "Performs an abortion live on the air." // Get [LAWFLAG_SPEECH], [LAWFLAG_MURDER], [LAWFLAG_DISTURBANCE] -- LK case VIEW_CIVILRIGHTS, "debates affirmative action."),
		shortAndString::value_type(VIEW_DRUGS, "has a frank talk about drugs."),
		shortAndString::value_type(VIEW_IMMIGRATION, "examines the issue of immigration."),
		shortAndString::value_type(VIEW_MILITARY, "talks about militarism in modern culture."),
		shortAndString::value_type(VIEW_AMRADIO, "discusses other AM radio shows."),
		shortAndString::value_type(VIEW_CABLENEWS, "talks about Cable News."),
		shortAndString::value_type(VIEW_LIBERALCRIMESQUAD, "lets people know about the Liberal Crime Squad."),
		shortAndString::value_type(VIEW_LIBERALCRIMESQUADPOS, "extols the virtues of the Liberal Crime Squad."),
		shortAndString::value_type(VIEW_CONSERVATIVECRIMESQUAD , "demonizes the Conservative Crime Squad.")
	};

	getCityDescription = {
		shortAndString::value_type(SITE_CITY_SEATTLE, "Birthplace of the LCS."),
		shortAndString::value_type(SITE_CITY_LOS_ANGELES, "Hollywood and Trade."),
		shortAndString::value_type(SITE_CITY_NEW_YORK, "Wall Street and Big Media."),
		shortAndString::value_type(SITE_CITY_WASHINGTON_DC, "The Nation's Capital."),
		shortAndString::value_type(SITE_CITY_CHICAGO, "Mafia Headquarters."),
		shortAndString::value_type(SITE_CITY_DETROIT, "Murder Capital of America."),
		shortAndString::value_type(SITE_CITY_ATLANTA, "The Pride of the South."),
		shortAndString::value_type(SITE_CITY_MIAMI, "A Tropical Paradise.")
	};
	getSiteName = {
		shortAndTwoStrings::value_type(SITE_CITY_SEATTLE,{ "Seattle", "SEA" }),
		shortAndTwoStrings::value_type(SITE_CITY_LOS_ANGELES,{ "Los Angeles", "LA" }),
		shortAndTwoStrings::value_type(SITE_CITY_NEW_YORK,{ "New York", "NYC" }),
		shortAndTwoStrings::value_type(SITE_CITY_CHICAGO,{ "Chicago", "CHI" }),
		shortAndTwoStrings::value_type(SITE_CITY_DETROIT,{ "Detroit", "DET" }),
		shortAndTwoStrings::value_type(SITE_CITY_ATLANTA,{ "Atlanta", "ATL" }),
		shortAndTwoStrings::value_type(SITE_CITY_MIAMI,{ "Miami", "MI" }),
		shortAndTwoStrings::value_type(SITE_CITY_WASHINGTON_DC,{ "Washington, DC", "DC" }),
		shortAndTwoStrings::value_type(SITE_DOWNTOWN,{ "Downtown", "Downtown" }),
		shortAndTwoStrings::value_type(SITE_UDISTRICT,{ "University District", "U-District" }),
		shortAndTwoStrings::value_type(SITE_COMMERCIAL,{ "Shopping", "Shopping" }),
		shortAndTwoStrings::value_type(SITE_INDUSTRIAL,{ "Industrial District", "I-District" }),
		shortAndTwoStrings::value_type(SITE_OUTOFTOWN,{ "City Outskirts", "Outskirts" }),
		shortAndTwoStrings::value_type(SITE_TRAVEL,{ "Travel", "Travel" }),
	};
	endgameLawStrings =
	{
		shortAndTwoStrings::value_type(LAW_WOMEN,{
			"Women are usually drafted into the armed forces to fight in place of men.",
			"Women are considered property, and rape has been legalized.",
			"Women are second-class citizens.",
			"Non-discrimination laws do not apply to gender.",
			"Women are nominally equal under law, but this is not enforced.",
			"Women have substantial recourse against discrimination.",
			"Gender equality is universally respected.",
			"Binary gender identities no longer exist, and gender segregation has ended."
		}) ,
		shortAndTwoStrings::value_type(LAW_CIVILRIGHTS,{
			"Entire ethnic groups are branded \"enemies of the state\".",
			"Slavery has been reintroduced, along with an apartheid system.",
			"Civil rights laws have been repealed, ostensibly to promote \"states' rights\".",
			"Racial discrimination is prohibited in name only.",
			"Pervasive racial inequality exists, although overt discrimination is illegal.",
			"Affirmative action is in place to counteract racial discrimination.",
			"Racial equality is guaranteed and vigorously enforced.",
			"The very idea of \"race\" has been universally discarded as pseudoscience."
		}) ,
		shortAndTwoStrings::value_type(LAW_DRUGS,{
			"Vodka is the only legal recreational drug in the People's Republic of America.",
			"Talking about recreational drugs is punishable by death.",
			"Violent criminals are released to make room for drug offenders.",
			"Prisons are filled with the targets of a war on drugs.",
			"Recreational drugs are prohibited unless medically prescribed.",
			"Marijuana is regulated and taxed, but harder drugs are illegal.",
			"Recreational drugs all are regulated and taxed like alcohol and tobacco.",
			"The government distributes free recreational drugs to anyone who wants them."
		}) ,
		shortAndTwoStrings::value_type(LAW_IMMIGRATION,{
			"All Americans must carry around an internal passport, or be shot on sight.",
			"Private border militiamen shoot suspected foreigners on sight.",
			"Immigration is illegal, and noncitizens are shipped to Mexico at gunpoint.",
			"The National Guard has been deployed to the borders to slow immigration.",
			"Great expense is taken to slow immigration, without success.",
			"The government works to accommodate potential immigrants but deports criminals.",
			"Immigration is unregulated, and new immigrants are welcomed warmly.",
			"There are open borders, and no distinctions between citizens and non-citizens."
		}) ,
		shortAndTwoStrings::value_type(LAW_ELECTIONS,{
			"Only Stalinist Party members may run in elections, and they all run unopposed.",
			"Instead of elections, political offices are auctioned off to the highest bidder.",
			"Virtually no ethics restrictions exist on political officeholders.",
			"Elections are mostly unregulated, but basic ethics restrictions are in place.",
			"Moderate campaign finance reform is implemented.",
			"Election financing is transparent and well-regulated.",
			"Election expenses are publicly funded, and voting is by ranked list.",
			"There is proportional representation, and over a dozen major political parties."
		}) ,
		shortAndTwoStrings::value_type(LAW_MILITARY,{
			"The military promotes Stalinism throughout the world by using force.",
			"The massive military kills dissenters at home and conquers poor nations abroad.",
			"Out-of-control military spending funds several ongoing wars around the world.",
			"Massive investment is put into the military, which always seems to be at war.",
			"Military spending is growing each year to fund overseas military adventures.",
			"The military is not a major priority, and mostly does peacekeeping missions.",
			"The military has been weakened significantly, as there is little need for it.",
			"The military has been abolished, and the entire world is at peace."
		}) ,
		shortAndTwoStrings::value_type(LAW_TORTURE,{
			"The Internal Affairs Commissariat constantly invents new methods of torture.",
			"The new Inquisition tortures heretics, blasphemers, and non-Christians to death.",
			"Military and intelligence interrogators regularly engage in torture.",
			"The line between standard interrogation and torture is severely blurred.",
			"Torture allegations still occasionally crop up, despite an official ban.",
			"The government strongly enforces a ban on torture.",
			"The nation is a respected international leader on Moral Interrogation Practices.",
			"Terrorism ended after the government formally apologized to terrorist leaders."
		}) ,
		shortAndTwoStrings::value_type(LAW_PRISONS,{
			"The former nation of Canada has been annexed and filled with Stalinist gulags.",
			"Prisoners must fight to the death in corporate-sponsored gladiatorial bouts.",
			"Prisoners are often subject to torture and slave labor.",
			"Prisoners suffer from horrible conditions and lack of basic rights.",
			"Prisoners receive basic rights and services, but reports of abuse are common.",
			"The prisons are regulated to protect prisoners' rights and safety.",
			"The prisons are targeted at rehabilitation, rather than punishment.",
			"Instead of prison, criminals voluntarily attend free support groups."
		}) ,
		shortAndTwoStrings::value_type(LAW_TAX,{
			"Having any money whatsoever is punishable by 20 years in a gulag.",
			"There are no taxes, yet most people have no money.",
			"The tax code is a nightmare designed to maintain class structure.",
			"A flat tax is in effect, and there is no capital gains or inheritance tax.",
			"Taxes are moderate, but the code is full of loopholes.",
			"The wealthy are heavily taxed under a progressive taxation system.",
			"Rich people are virtually unheard of, due to taxation.",
			"Money no longer exists, everything is free, and everyone enjoys lives of luxury."
		}) ,
		shortAndTwoStrings::value_type(LAW_ABORTION,{
			"Mandatory abortions are carried out for population control.",
			"Abortion, contraception, and consensual sex are all capital offenses.",
			"Abortion is a felony equal to murder, not allowed under any circumstance.",
			"Abortion is prohibited except in shortAndTwoStrings::value_type(s of rape, incest, or health of the mother.",
			"Abortion is limited to the first trimester, and is very expensive.",
			"Abortion is legal, but taxpayer funding of abortion is prohibited.",
			"The right to an abortion is strongly protected, and subsidized for poor women.",
			"Free abortions are easily available at any time during pregnancy."
		}) ,
		shortAndTwoStrings::value_type(LAW_ANIMALRESEARCH,{
			"All forms of human experimentation on \"class enemies\" are encouraged.",
			"All forms of human experimentation on the poor are encouraged.",
			"Animals are property that can be experimented upon freely.",
			"Animal testing is self-regulated by the scientific community.",
			"Animal research is regulated with a system of licenses and certificates.",
			"Animal research is strictly regulated by purpose and suffering caused.",
			"Animals are people, too, and have full citizenship rights.",
			"All species of life have equal rights as people, even bacteria."
		}) ,
		shortAndTwoStrings::value_type(LAW_POLICEBEHAVIOR,{
			"Everyone lives in constant fear of the Stalinist Party's Secret Police.",
			"Privatized police get bonuses on their paychecks for every person they kill.",
			"Law enforcement is given free reign.",
			"Even the worst police misconduct only earns slap-on-the-wrist punishments.",
			"Law enforcement is regulated to prevent extreme misconduct.",
			"Law enforcement has heavy oversight and freedom-of-information requirements.",
			"All law enforcement positions are subject to election and recall.",
			"With no police, criminals follow the honor system and turn themselves in."
		}) ,
		shortAndTwoStrings::value_type(LAW_PRIVACY,{
			"Citizens have to spy on each other and report to the Stalinist Party.",
			"Very detailed reports on each citizen are easily accessible to corporations.",
			"Any corporation requesting private information is granted unrestricted access.",
			"Privacy laws are full of loopholes and security backdoors are in everything.",
			"Basic safeguards for medical and financial privacy are in place but ineffective.",
			"All areas of privacy are protected with strong, effective safeguards.",
			"Individual privacy is sacred, and state-of-the-art safeguards are mandatory.",
			"All large organizations are prohibited from keeping any data about anyone."
		}) ,
		shortAndTwoStrings::value_type(LAW_DEATHPENALTY,{
			"Class enemies receive mandatory death sentences.",
			"Poor and minority criminals receive mandatory death sentences.",
			"People can be put to death for minor offenses.",
			"The death penalty is actively enforced in many states.",
			"The death penalty is in effect but under scrutiny.",
			"The death penalty is only permitted in extreme shortAndTwoStrings::value_type(s.",
			"The death penalty is considered barbaric and never practiced.",
			"The death penalty, like all other harsh punishments, has been abolished."
		}) ,
		shortAndTwoStrings::value_type(LAW_NUCLEARPOWER,{
			"Nuclear power plants routinely have meltdowns but keep getting built.",
			"Nuclear power plants are ubiquitous and cancer rates are astronomical.",
			"Nuclear power is wildly proliferating with no controls or regulation at all.",
			"Nuclear power is a preferred energy source and the industry self-regulates.",
			"Nuclear power is often an energy source and only moderately regulated.",
			"Nuclear power is intensely regulated and rarely used anymore.",
			"Nuclear power is illegal and the leftover nuclear waste is being cleaned up.",
			"A global ban on nuclear power and nuclear weapons is enforced by UN inspectors."
		}) ,
		shortAndTwoStrings::value_type(LAW_POLLUTION,{
			"State-run industries pollute so much, the workers all have cancer.",
			"Deformed children are the norm in the vast industrial wastelands.",
			"Industry may pollute as much as they like.",
			"Industry voluntarily regulates pollution.",
			"Industry is subject to moderate pollution regulations.",
			"Industry is subject to strict pollution regulations.",
			"Industry is subject to zero-tolerance pollution regulations.",
			"Pollution is unheard of, and nature has reclaimed much of the land."
		}) ,
		shortAndTwoStrings::value_type(LAW_LABOR,{
			"The state has nationalized all industries and assigns everyone jobs.",
			"People are bred in pens to be farmed out to corporations like beasts.",
			"There is no weekend, children are forced to work, and workers can't afford food.",
			"Working conditions are deplorable and there is no minimum wage.",
			"Workers are underpaid, have lousy benefits, and get fired if they complain.",
			"Workers are fairly compensated, have good benefits, and are difficult to fire.",
			"There are universal workers' rights and a high guaranteed minimum income.",
			"Wage slavery has been abolished, and robots have been built to do all the work."
		}) ,
		shortAndTwoStrings::value_type(LAW_GAY,{
			"Homosexuals are executed regularly for their \"bourgeoisie decadence\".",
			"Homosexuals are executed regularly for \"promoting the Gay Agenda\".",
			"Homosexuals are routinely persecuted with no recourse.",
			"Homosexuals are not tolerated.",
			"Homosexuals are grudgingly tolerated but have few equal rights.",
			"Homosexuals have many rights shared by heterosexuals.",
			"Homosexuals have equal rights that are vigorously protected.",
			"All sexual orientations are accepted, and most people are polyamorous."
		}) ,
		shortAndTwoStrings::value_type(LAW_CORPORATE,{
			"All forms of private enterprise are punishable by death.",
			"Corporations under the King run the country in a feudal system.",
			"Corporations essentially run the country in a feudal system.",
			"Corporate culture is corrupt and there is a great disparity in wages.",
			"Corporations are moderately regulated, although wages are still unfair.",
			"Corporations are stiffly regulated, and executive compensation is reasonable.",
			"Corporations are subject to intense regulation, and there is a maximum wage law.",
			"Corporations have been abolished, along with the rest of capitalism."
		}) ,
		shortAndTwoStrings::value_type(LAW_FREESPEECH,{
			"Counterrevolutionary speech is a capital crime.",
			"Even *THINKING* about saying something unacceptable is a capital crime.",
			"Armored squads are tasked with suppressing unacceptable speech.",
			"People who express unpopular opinions are often harassed and mistreated.",
			"Free speech is legal, with minor exceptions, and is usually tolerated.",
			"Free speech is legally protected and publicly encouraged.",
			"Free speech is strongly protected and universally supported.",
			"Free speech is sacrosanct and diverse points of view are celebrated."
		}) ,
		shortAndTwoStrings::value_type(LAW_FLAGBURNING,{
			"Flags of the old American regime are burnt primarily as fuel.",
			"Images or words describing flag burning are punished by death.",
			"Burning the flag is a serious crime on par with murder.",
			"Burning the flag is a felony and vigorously prosecuted.",
			"Flag-burning is a misdemeanor, but not a serious crime.",
			"Flag-burning is technically legal but stigmatized as unpatriotic.",
			"The right of flag-burning is upheld even by its critics.",
			"Flag-burning is traditionally done on July 4th to celebrate freedom."
		}) ,
		shortAndTwoStrings::value_type(LAW_GUNCONTROL,{
			"Anyone owning a gun is executed by firing squad.",
			"Gangs of young children carrying AK-47s roam the streets.",
			"Machine guns, tanks, and missiles can be bought and sold freely.",
			"Military weapons are banned, but similar-looking guns are available.",
			"A comprehensive ban on military-style weapons is in effect.",
			"Most guns cannot be sold to anyone outside of law enforcement.",
			"It is illegal to buy or sell a gun, or carry one in public.",//XXX, { Should guns be legal in private, too? -- LK
			"All gun manufacturers have been shut down and all existing guns destroyed." //They are illegal in private under Elite Liberal victory conditions - yetisyny
		})
	};
	getActivityString = {
		shortAndString::value_type(ACTIVITY_RECRUITING,	"Recruiting"),
		shortAndString::value_type(ACTIVITY_REPAIR_ARMOR,	"Repairing Clothing"),
		shortAndString::value_type(ACTIVITY_WHEELCHAIR,	"Procuring a Wheelchair"),
		shortAndString::value_type(ACTIVITY_STEALCARS,	"Stealing a Car"),
		shortAndString::value_type(ACTIVITY_POLLS,	"Gathering Opinion Info"),
		shortAndString::value_type(ACTIVITY_TROUBLE,	"Causing Trouble"),
		shortAndString::value_type(ACTIVITY_PROSTITUTION,	"Prostituting"),
		shortAndString::value_type(ACTIVITY_COMMUNITYSERVICE,	"Volunteering"),
		shortAndString::value_type(ACTIVITY_GRAFFITI,	"Making Graffiti"),
		shortAndString::value_type(ACTIVITY_CCFRAUD,	"Credit Card Fraud"),
		shortAndString::value_type(ACTIVITY_DOS_RACKET,	"Extorting Websites"),
		shortAndString::value_type(ACTIVITY_DOS_ATTACKS,	"Attacking Websites"),
		shortAndString::value_type(ACTIVITY_HACKING,	"Hacking Networks"),
		shortAndString::value_type(ACTIVITY_SELL_TSHIRTS,	"Selling T-Shirts"),
		shortAndString::value_type(ACTIVITY_SELL_ART,	"Selling Art"),
		shortAndString::value_type(ACTIVITY_TEACH_POLITICS,	"Teaching Politics"),
		shortAndString::value_type(ACTIVITY_TEACH_FIGHTING,	"Teaching Fighting"),
		shortAndString::value_type(ACTIVITY_TEACH_COVERT,	"Teaching Covert Ops"),
		shortAndString::value_type(ACTIVITY_SELL_MUSIC,	"Selling Music"),
		shortAndString::value_type(ACTIVITY_BURY,	"Disposing of Bodies"),
		shortAndString::value_type(ACTIVITY_DONATIONS,	"Soliciting Donations"),
		shortAndString::value_type(ACTIVITY_SELL_DRUGS,	"Selling Brownies"),
		shortAndString::value_type(ACTIVITY_HEAL,	"Tending to Injuries"),
		shortAndString::value_type(ACTIVITY_NONE,	"Laying Low"),
		shortAndString::value_type(ACTIVITY_WRITE_LETTERS,	"Writing letters"),
		shortAndString::value_type(ACTIVITY_WRITE_GUARDIAN,	"Writing news"),
		shortAndString::value_type(ACTIVITY_CLINIC,	"Going to Free CLINIC"),
		shortAndString::value_type(ACTIVITY_STUDY_DEBATING,"Attending Classes"),
		shortAndString::value_type(ACTIVITY_STUDY_MARTIAL_ARTS,"Attending Classes"),
		shortAndString::value_type(ACTIVITY_STUDY_DRIVING,"Attending Classes"),
		shortAndString::value_type(ACTIVITY_STUDY_PSYCHOLOGY,"Attending Classes"),
		shortAndString::value_type(ACTIVITY_STUDY_FIRST_AID,"Attending Classes"),
		shortAndString::value_type(ACTIVITY_STUDY_LAW,"Attending Classes"),
		shortAndString::value_type(ACTIVITY_STUDY_DISGUISE,"Attending Classes"),
		shortAndString::value_type(ACTIVITY_STUDY_SCIENCE,"Attending Classes"),
		shortAndString::value_type(ACTIVITY_STUDY_BUSINESS,"Attending Classes"),
		//shortAndString::value_type( ACTIVITY_STUDY_COOKING,"Attending Classes"),
		shortAndString::value_type(ACTIVITY_STUDY_GYMNASTICS,"Attending Classes"),
		shortAndString::value_type(ACTIVITY_STUDY_ART,"Attending Classes"),
		shortAndString::value_type(ACTIVITY_STUDY_MUSIC,"Attending Classes"),
		shortAndString::value_type(ACTIVITY_STUDY_TEACHING,"Attending Classes"),
		shortAndString::value_type(ACTIVITY_STUDY_WRITING,"Attending Classes"),
		shortAndString::value_type(ACTIVITY_STUDY_LOCKSMITHING,"Attending Classes"),
		shortAndString::value_type(ACTIVITY_STUDY_COMPUTERS,	"Attending Classes"),
		shortAndString::value_type(ACTIVITY_SLEEPER_LIBERAL,	"Promoting Liberalism"),
		shortAndString::value_type(ACTIVITY_SLEEPER_CONSERVATIVE,	"Spouting Conservatism"),
		shortAndString::value_type(ACTIVITY_SLEEPER_SPY,	"Snooping Around"),
		shortAndString::value_type(ACTIVITY_SLEEPER_RECRUIT,	"Recruiting Sleepers"),
		shortAndString::value_type(ACTIVITY_SLEEPER_JOINLCS,	"Quitting Job"),
		shortAndString::value_type(ACTIVITY_SLEEPER_SCANDAL,	"Creating a Scandal"),
		shortAndString::value_type(ACTIVITY_SLEEPER_EMBEZZLE,	"Embezzling Funds"),
		shortAndString::value_type(ACTIVITY_SLEEPER_STEAL,	"Stealing Equipment"),
		shortAndString::value_type(ACTIVITY_AUGMENT,	"Augmenting Liberal"),
	};
	getViewString = {
		shortAndTwoStrings::value_type(VIEW_STALIN,{ "Stalinism", "Stalinism" }) ,
		shortAndTwoStrings::value_type(VIEW_MOOD,{ "public mood", "Public Mood" }) ,
		shortAndTwoStrings::value_type(VIEW_GAY,{ "LGBTQ rights", "LGBTQ Rights" }) ,
		shortAndTwoStrings::value_type(VIEW_DEATHPENALTY,{ "the death penalty", "Barbaric Executions" }) ,
		shortAndTwoStrings::value_type(VIEW_TAXES,{ "taxes", "The Tax Structure" }) ,
		shortAndTwoStrings::value_type(VIEW_NUCLEARPOWER,{ "nuclear power", "Nuclear Meltdowns" }) ,
		shortAndTwoStrings::value_type(VIEW_ANIMALRESEARCH,{ "animal cruelty", "Animal Cruelty" }) ,
		shortAndTwoStrings::value_type(VIEW_POLICEBEHAVIOR,{ "cops", "Police Misconduct" }) ,
		shortAndTwoStrings::value_type(VIEW_TORTURE,{ "torture", "Torture" }) ,
		shortAndTwoStrings::value_type(VIEW_PRISONS,{ "the prison system", "The Prison System" }) ,
		shortAndTwoStrings::value_type(VIEW_INTELLIGENCE,{ "privacy", "Privacy Rights" }) ,
		shortAndTwoStrings::value_type(VIEW_FREESPEECH,{ "free speech", "Freedom of Speech" }) ,
		shortAndTwoStrings::value_type(VIEW_GENETICS,{ "genetic research", "Dangerous GMOs" }) ,
		shortAndTwoStrings::value_type(VIEW_JUSTICES,{ "judges", "The Judiciary" }) ,
		shortAndTwoStrings::value_type(VIEW_GUNCONTROL,{ "gun control", "Mass Shootings" }) ,
		shortAndTwoStrings::value_type(VIEW_SWEATSHOPS,{ "labor unions", "Workers' Rights" }) ,
		shortAndTwoStrings::value_type(VIEW_POLLUTION,{ "pollution", "Pollution" }) ,
		shortAndTwoStrings::value_type(VIEW_CORPORATECULTURE,{ "corporations", "Corporate Corruption" }) ,
		shortAndTwoStrings::value_type(VIEW_CEOSALARY,{ "CEO compensation", "CEO Compensation" }) ,
		shortAndTwoStrings::value_type(VIEW_WOMEN,{ "women's rights", "Gender Equality" }) ,
		shortAndTwoStrings::value_type(VIEW_CIVILRIGHTS,{ "civil rights", "Racial Equality" }) ,
		shortAndTwoStrings::value_type(VIEW_DRUGS,{ "drugs", "Oppressive Drug Laws" }) ,
		shortAndTwoStrings::value_type(VIEW_IMMIGRATION,{ "immigration", "Immigrant Rights" }) ,
		shortAndTwoStrings::value_type(VIEW_MILITARY,{ "the military", "Military Spending" }) ,
		shortAndTwoStrings::value_type(VIEW_AMRADIO,{ "AM radio", "AM Radio Propaganda" }) ,
		shortAndTwoStrings::value_type(VIEW_CABLENEWS,{ "cable news", "Cable \"News\" Lies" }) ,
		//shortAndTwoStrings::value_type( VIEW_POLITICALVIOLENCE, { "political violence", "The Need For Action" } ) ,
		shortAndTwoStrings::value_type(VIEW_LIBERALCRIMESQUAD,{ "the LCS", "Who We Are" }) ,
		shortAndTwoStrings::value_type(VIEW_LIBERALCRIMESQUADPOS,{ "the LCS", "Why We Rock" }) ,
		shortAndTwoStrings::value_type(VIEW_CONSERVATIVECRIMESQUAD,{ "the CCS", "The CCS Terrorists" })
	};
	getLawString = {
		shortAndString::value_type(LAW_ABORTION, "Abortion Rights"),
		shortAndString::value_type(LAW_ANIMALRESEARCH, "Animal Rights"), // a.k.a. "Animal Research"
		shortAndString::value_type(LAW_POLICEBEHAVIOR, "Police Regulation"), // a.k.a. "Police Behavior"
		shortAndString::value_type(LAW_PRIVACY, "Privacy Rights"), // a.k.a. "Privacy"
		shortAndString::value_type(LAW_DEATHPENALTY, "Death Penalty"), // a.k.a. "Capital Punishment"
		shortAndString::value_type(LAW_NUCLEARPOWER, "Nuclear Power"),
		shortAndString::value_type(LAW_POLLUTION, "Pollution"),
		shortAndString::value_type(LAW_LABOR, "Labor Laws"), // a.k.a. "Workers' Rights"
		shortAndString::value_type(LAW_GAY, "Gay Rights"), // a.k.a. "Homosexual Rights"
		shortAndString::value_type(LAW_CORPORATE, "Corporate Law"), // a.k.a. "Corporate Ethics"
		shortAndString::value_type(LAW_FREESPEECH, "Free Speech"), // a.k.a. "Freedom of Speech"
		shortAndString::value_type(LAW_FLAGBURNING, "Flag Burning"),
		shortAndString::value_type(LAW_GUNCONTROL, "Gun Control"),
		shortAndString::value_type(LAW_TAX, "Tax Structure"), // a.k.a. "Tax Law"
		shortAndString::value_type(LAW_WOMEN, "Women's Rights"),
		shortAndString::value_type(LAW_CIVILRIGHTS, "Civil Rights"),
		shortAndString::value_type(LAW_DRUGS, "Drug Laws"), // a.k.a. "Drug Law"
		shortAndString::value_type(LAW_IMMIGRATION, "Immigration"),
		shortAndString::value_type(LAW_ELECTIONS, "Election Reform"),
		shortAndString::value_type(LAW_MILITARY, "Military Spending"),
		shortAndString::value_type(LAW_PRISONS, "Prison Regulation"),
		shortAndString::value_type(LAW_TORTURE, "Human Rights")
	};
	getLawFlagString = {
		shortAndString::value_type(LAWFLAG_TREASON,  "Treason"),
		shortAndString::value_type(LAWFLAG_TERRORISM,  "Terrorism"),
		shortAndString::value_type(LAWFLAG_MURDER,  "Murder"),
		shortAndString::value_type(LAWFLAG_KIDNAPPING,  "Kidnapping"),
		shortAndString::value_type(LAWFLAG_BANKROBBERY,  "Bank robbery"),
		shortAndString::value_type(LAWFLAG_ARSON,  "Arson"),
		shortAndString::value_type(LAWFLAG_SPEECH,  "Harmful speech"),
		shortAndString::value_type(LAWFLAG_BROWNIES,  "Drug dealing"),
		shortAndString::value_type(LAWFLAG_ESCAPED,  "Escaping prison"),
		shortAndString::value_type(LAWFLAG_HELPESCAPE,  "Releasing prisoners"),
		shortAndString::value_type(LAWFLAG_JURY,  "Jury tampering"),
		shortAndString::value_type(LAWFLAG_RACKETEERING,  "Racketeering"),
		shortAndString::value_type(LAWFLAG_EXTORTION,  "Extortion"),
		shortAndString::value_type(LAWFLAG_ARMEDASSAULT,  "Armed assault"),
		shortAndString::value_type(LAWFLAG_ASSAULT,  "Assault"),
		shortAndString::value_type(LAWFLAG_CARTHEFT,  "Grand theft auto"),
		shortAndString::value_type(LAWFLAG_CCFRAUD,  "Credit card fraud"),
		shortAndString::value_type(LAWFLAG_THEFT,  "Theft"),
		shortAndString::value_type(LAWFLAG_PROSTITUTION,  "Prostitution"),
		//shortAndString::value_type( LAWFLAG_GUNUSE,  "Firing illegal weapons"),
		//shortAndString::value_type( LAWFLAG_GUNCARRY,  "Carrying illegal weapons"),
		shortAndString::value_type(LAWFLAG_COMMERCE,  "Electronic sabotage"),
		shortAndString::value_type(LAWFLAG_INFORMATION,  "Hacking"),
		shortAndString::value_type(LAWFLAG_BURIAL,  "Unlawful burial"),
		shortAndString::value_type(LAWFLAG_BREAKING,  "Breaking and entering"),
		shortAndString::value_type(LAWFLAG_VANDALISM,  "Vandalism"),
		shortAndString::value_type(LAWFLAG_RESIST,  "Resisting arrest"),
		shortAndString::value_type(LAWFLAG_DISTURBANCE,  "Disturbing the peace"),
		shortAndString::value_type(LAWFLAG_PUBLICNUDITY,  "Public nudity"),
		shortAndString::value_type(LAWFLAG_LOITERING,  "Loitering")
	};
	getLawFlagStringFull = {
		shortAndShortAndString::value_type(LAWFLAG_BURNFLAG,
		{
			shortAndString::value_type(ALIGN_ARCHCONSERVATIVE ,	"Flag Murder"),
			shortAndString::value_type(ALIGN_CONSERVATIVE,"Flag burning"),
			shortAndString::value_type(ALIGN_MODERATE,"Flag burning"),
			shortAndString::value_type(ALIGN_LIBERAL,"Flag burning"),
			shortAndString::value_type(ALIGN_ELITELIBERAL,"Flag burning"),
			shortAndString::value_type(ALIGN_STALINIST ,"Flag burning")
		}
			),
		shortAndShortAndString::value_type(LAWFLAG_HIREILLEGAL,{
			shortAndString::value_type(ALIGN_ARCHCONSERVATIVE,"Hiring illegal aliens"),
			shortAndString::value_type(ALIGN_CONSERVATIVE,"Hiring illegal aliens"),
			shortAndString::value_type(ALIGN_MODERATE,"Hiring illegal aliens"),
			shortAndString::value_type(ALIGN_LIBERAL,"Hiring undocumented workers"),
			shortAndString::value_type(ALIGN_ELITELIBERAL,"Hiring undocumented workers")
		}
			)
	};
	 state_biases = {
		-3,// Alabama
		-4,// Alaska
		-1,// Arkansas
		-2,// Arizona
		+4,// California
		0,                     // Colorado
		+3,// Connecticut
		+3,// Delaware
		0,                     // Florida
		-2,// Georgia
		+4,// Hawaii
		-5,// Idaho
		+4,// Illinois
		-1,// Indiana
		+1,// Iowa
		-3,// Kansas
		-3,// Kentucky
		-1,// Louisiana
		+2,// Maine
		+3,// Maryland
		+6,// Massachusetts
		+2,// Michigan
		+2,// Minnesota
		-4,// Mississippi
		-1,// Missouri
		-2,// Montana
		-3,// Nebraska
		0,                     // Nevada
		+1,// New Hampshire
		+3,// New Jersey
		+1,// New Mexico
		+5,// New York
		-1,// North Carolina
		-3,// North Dakota
		0,                    // Ohio
		-4,// Oklahoma
		+3,// Oregon
		+2,// Pennsylvania
		+4,// Rhode Island
		-5,// South Carolina
		-3,// South Dakota
		-2,// Tennessee
		-4,// Texas
		-6,// Utah
		+5,// Vermont
		0,                    // Virginia
		+3,// Washington
		-2,// West Virginia
		+2,// Wisconsin
		-5// Wyoming
	};
	enumToCreature = {
		shortAndString::value_type(CREATURE_BOUNCER,	"CREATURE_BOUNCER"),
		shortAndString::value_type(CREATURE_SECURITYGUARD,	"CREATURE_SECURITYGUARD"),
		shortAndString::value_type(CREATURE_SCIENTIST_LABTECH,	"CREATURE_SCIENTIST_LABTECH"),
		shortAndString::value_type(CREATURE_SCIENTIST_EMINENT,	"CREATURE_SCIENTIST_EMINENT"),
		shortAndString::value_type(CREATURE_CORPORATE_MANAGER,	"CREATURE_CORPORATE_MANAGER"),
		shortAndString::value_type(CREATURE_CORPORATE_CEO,	"CREATURE_CORPORATE_CEO"),
		shortAndString::value_type(CREATURE_WORKER_SERVANT,	"CREATURE_WORKER_SERVANT"),
		shortAndString::value_type(CREATURE_WORKER_JANITOR,	"CREATURE_WORKER_JANITOR"),
		shortAndString::value_type(CREATURE_WORKER_SWEATSHOP,	"CREATURE_WORKER_SWEATSHOP"),
		shortAndString::value_type(CREATURE_WORKER_FACTORY_NONUNION,	"CREATURE_WORKER_FACTORY_NONUNION"),
		shortAndString::value_type(CREATURE_WORKER_FACTORY_CHILD,	"CREATURE_WORKER_FACTORY_CHILD"),
		shortAndString::value_type(CREATURE_WORKER_SECRETARY,	"CREATURE_WORKER_SECRETARY"),
		shortAndString::value_type(CREATURE_WORKER_FACTORY_UNION,	"CREATURE_WORKER_FACTORY_UNION"),
		shortAndString::value_type(CREATURE_LANDLORD,	"CREATURE_LANDLORD"),
		shortAndString::value_type(CREATURE_TEENAGER,	"CREATURE_TEENAGER"),
		shortAndString::value_type(CREATURE_COP,	"CREATURE_COP"),
		shortAndString::value_type(CREATURE_SWAT,	"CREATURE_SWAT"),
		shortAndString::value_type(CREATURE_DEATHSQUAD,	"CREATURE_DEATHSQUAD"),
		shortAndString::value_type(CREATURE_FIREFIGHTER,	"CREATURE_FIREFIGHTER"),
		shortAndString::value_type(CREATURE_EDUCATOR,	"CREATURE_EDUCATOR"),
		shortAndString::value_type(CREATURE_GANGUNIT,	"CREATURE_GANGUNIT"),
		shortAndString::value_type(CREATURE_JUDGE_LIBERAL,	"CREATURE_JUDGE_LIBERAL"),
		shortAndString::value_type(CREATURE_JUDGE_CONSERVATIVE,	"CREATURE_JUDGE_CONSERVATIVE"),
		shortAndString::value_type(CREATURE_AGENT,	"CREATURE_AGENT"),
		shortAndString::value_type(CREATURE_RADIOPERSONALITY,	"CREATURE_RADIOPERSONALITY"),
		shortAndString::value_type(CREATURE_NEWSANCHOR,	"CREATURE_NEWSANCHOR"),
		shortAndString::value_type(CREATURE_GENETIC,	"CREATURE_GENETIC"),
		shortAndString::value_type(CREATURE_GUARDDOG,	"CREATURE_GUARDDOG"),
		shortAndString::value_type(CREATURE_PRISONER,	"CREATURE_PRISONER"),
		shortAndString::value_type(CREATURE_JUROR,	"CREATURE_JUROR"),
		shortAndString::value_type(CREATURE_LAWYER,	"CREATURE_LAWYER"),
		shortAndString::value_type(CREATURE_SEWERWORKER,	"CREATURE_SEWERWORKER"),
		shortAndString::value_type(CREATURE_COLLEGESTUDENT,	"CREATURE_COLLEGESTUDENT"),
		shortAndString::value_type(CREATURE_MUSICIAN,	"CREATURE_MUSICIAN"),
		shortAndString::value_type(CREATURE_MATHEMATICIAN,	"CREATURE_MATHEMATICIAN"),
		shortAndString::value_type(CREATURE_TEACHER,	"CREATURE_TEACHER"),
		shortAndString::value_type(CREATURE_HSDROPOUT,	"CREATURE_HSDROPOUT"),
		shortAndString::value_type(CREATURE_BUM,	"CREATURE_BUM"),
		shortAndString::value_type(CREATURE_GANGMEMBER,	"CREATURE_GANGMEMBER"),
		shortAndString::value_type(CREATURE_CRACKHEAD,	"CREATURE_CRACKHEAD"),
		shortAndString::value_type(CREATURE_PRIEST,	"CREATURE_PRIEST"),
		shortAndString::value_type(CREATURE_ENGINEER,	"CREATURE_ENGINEER"),
		shortAndString::value_type(CREATURE_FASTFOODWORKER,	"CREATURE_FASTFOODWORKER"),
		shortAndString::value_type(CREATURE_BAKER,	"CREATURE_BAKER"),
		shortAndString::value_type(CREATURE_BARISTA,	"CREATURE_BARISTA"),
		shortAndString::value_type(CREATURE_BARTENDER,	"CREATURE_BARTENDER"),
		shortAndString::value_type(CREATURE_TELEMARKETER,	"CREATURE_TELEMARKETER"),
		shortAndString::value_type(CREATURE_CARSALESMAN,	"CREATURE_CARSALESMAN"),
		shortAndString::value_type(CREATURE_OFFICEWORKER,	"CREATURE_OFFICEWORKER"),
		shortAndString::value_type(CREATURE_FOOTBALLCOACH,	"CREATURE_FOOTBALLCOACH"),
		shortAndString::value_type(CREATURE_PROSTITUTE,	"CREATURE_PROSTITUTE"),
		shortAndString::value_type(CREATURE_MAILMAN,	"CREATURE_MAILMAN"),
		shortAndString::value_type(CREATURE_GARBAGEMAN,	"CREATURE_GARBAGEMAN"),
		shortAndString::value_type(CREATURE_PLUMBER,	"CREATURE_PLUMBER"),
		shortAndString::value_type(CREATURE_CHEF,	"CREATURE_CHEF"),
		shortAndString::value_type(CREATURE_CONSTRUCTIONWORKER,	"CREATURE_CONSTRUCTIONWORKER"),
		shortAndString::value_type(CREATURE_AMATEURMAGICIAN,	"CREATURE_AMATEURMAGICIAN"),
		shortAndString::value_type(CREATURE_TANK,	"CREATURE_TANK"),
		shortAndString::value_type(CREATURE_MERC,	"CREATURE_MERC"),
		shortAndString::value_type(CREATURE_HICK,	"CREATURE_HICK"),
		shortAndString::value_type(CREATURE_SOLDIER,	"CREATURE_SOLDIER"),
		shortAndString::value_type(CREATURE_VETERAN,	"CREATURE_VETERAN"),
		shortAndString::value_type(CREATURE_HARDENED_VETERAN,	"CREATURE_HARDENED_VETERAN"),
		shortAndString::value_type(CREATURE_PRISONGUARD,	"CREATURE_PRISONGUARD"),
		shortAndString::value_type(CREATURE_HIPPIE,	"CREATURE_HIPPIE"),
		shortAndString::value_type(CREATURE_CRITIC_ART,	"CREATURE_CRITIC_ART"),
		shortAndString::value_type(CREATURE_CRITIC_MUSIC,	"CREATURE_CRITIC_MUSIC"),
		shortAndString::value_type(CREATURE_SOCIALITE,	"CREATURE_SOCIALITE"),
		shortAndString::value_type(CREATURE_PROGRAMMER,	"CREATURE_PROGRAMMER"),
		shortAndString::value_type(CREATURE_RETIREE,	"CREATURE_RETIREE"),
		shortAndString::value_type(CREATURE_PAINTER,	"CREATURE_PAINTER"),
		shortAndString::value_type(CREATURE_SCULPTOR,	"CREATURE_SCULPTOR"),
		shortAndString::value_type(CREATURE_AUTHOR,	"CREATURE_AUTHOR"),
		shortAndString::value_type(CREATURE_JOURNALIST,	"CREATURE_JOURNALIST"),
		shortAndString::value_type(CREATURE_DANCER,	"CREATURE_DANCER"),
		shortAndString::value_type(CREATURE_PHOTOGRAPHER,	"CREATURE_PHOTOGRAPHER"),
		shortAndString::value_type(CREATURE_CAMERAMAN,	"CREATURE_CAMERAMAN"),
		shortAndString::value_type(CREATURE_HAIRSTYLIST,	"CREATURE_HAIRSTYLIST"),
		shortAndString::value_type(CREATURE_FASHIONDESIGNER,	"CREATURE_FASHIONDESIGNER"),
		shortAndString::value_type(CREATURE_CLERK,	"CREATURE_CLERK"),
		shortAndString::value_type(CREATURE_THIEF,	"CREATURE_THIEF"),
		shortAndString::value_type(CREATURE_ACTOR,	"CREATURE_ACTOR"),
		shortAndString::value_type(CREATURE_YOGAINSTRUCTOR,	"CREATURE_YOGAINSTRUCTOR"),
		shortAndString::value_type(CREATURE_MARTIALARTIST,	"CREATURE_MARTIALARTIST"),
		shortAndString::value_type(CREATURE_ATHLETE,	"CREATURE_ATHLETE"),
		shortAndString::value_type(CREATURE_BIKER,	"CREATURE_BIKER"),
		shortAndString::value_type(CREATURE_TRUCKER,	"CREATURE_TRUCKER"),
		shortAndString::value_type(CREATURE_TAXIDRIVER,	"CREATURE_TAXIDRIVER"),
		shortAndString::value_type(CREATURE_NUN,	"CREATURE_NUN"),
		shortAndString::value_type(CREATURE_MUTANT,	"CREATURE_MUTANT"),
		shortAndString::value_type(CREATURE_DOCTOR,	"CREATURE_DOCTOR"),
		shortAndString::value_type(CREATURE_NURSE,	"CREATURE_NURSE"),
		shortAndString::value_type(CREATURE_CCS_VIGILANTE,	"CREATURE_CCS_VIGILANTE"),
		shortAndString::value_type(CREATURE_CCS_ARCHCONSERVATIVE,	"CREATURE_CCS_ARCHCONSERVATIVE"),
		shortAndString::value_type(CREATURE_POLITICALACTIVIST,	"CREATURE_POLITICALACTIVIST"),
		shortAndString::value_type(CREATURE_CCS_MOLOTOV,	"CREATURE_CCS_MOLOTOV"),
		shortAndString::value_type(CREATURE_CCS_SNIPER,	"CREATURE_CCS_SNIPER"),
		shortAndString::value_type(CREATURE_PSYCHOLOGIST,	"CREATURE_PSYCHOLOGIST"),
		shortAndString::value_type(CREATURE_LOCKSMITH,	"CREATURE_LOCKSMITH"),
		shortAndString::value_type(CREATURE_MILITARYPOLICE,	"CREATURE_MILITARYPOLICE"),
		shortAndString::value_type(CREATURE_SEAL,	"CREATURE_SEAL"),
		shortAndString::value_type(CREATURE_MILITARYOFFICER,	"CREATURE_MILITARYOFFICER"),
		shortAndString::value_type(CREATURE_BANK_TELLER,	"CREATURE_BANK_TELLER"),
		shortAndString::value_type(CREATURE_BANK_MANAGER,	"CREATURE_BANK_MANAGER"),
		shortAndString::value_type(CREATURE_SECRET_SERVICE,	"CREATURE_SECRET_SERVICE"),
		shortAndString::value_type(CREATURE_POLITICIAN,	"CREATURE_POLITICIAN")
	};
	getSkillEnumFromString = {
		stringAndShort::value_type("SKILL_ART", SKILL_ART),
		stringAndShort::value_type("SKILL_AXE", SKILL_AXE),
		stringAndShort::value_type("SKILL_BUSINESS", SKILL_BUSINESS),
		stringAndShort::value_type("SKILL_CLUB", SKILL_CLUB),
		stringAndShort::value_type("SKILL_COMPUTERS", SKILL_COMPUTERS),
		stringAndShort::value_type("SKILL_DISGUISE", SKILL_DISGUISE),
		stringAndShort::value_type("SKILL_DODGE", SKILL_DODGE),
		stringAndShort::value_type("SKILL_DRIVING", SKILL_DRIVING),
		stringAndShort::value_type("SKILL_FIRSTAID", SKILL_FIRSTAID),
		stringAndShort::value_type("SKILL_HEAVYWEAPONS", SKILL_HEAVYWEAPONS),
		stringAndShort::value_type("SKILL_KNIFE", SKILL_KNIFE),
		stringAndShort::value_type("SKILL_LAW", SKILL_LAW),
		stringAndShort::value_type("SKILL_HANDTOHAND", SKILL_HANDTOHAND),
		stringAndShort::value_type("SKILL_MUSIC", SKILL_MUSIC),
		stringAndShort::value_type("SKILL_PERSUASION", SKILL_PERSUASION),
		stringAndShort::value_type("SKILL_PISTOL", SKILL_PISTOL),
		stringAndShort::value_type("SKILL_PSYCHOLOGY", SKILL_PSYCHOLOGY),
		stringAndShort::value_type("SKILL_RELIGION", SKILL_RELIGION),
		stringAndShort::value_type("SKILL_RIFLE", SKILL_RIFLE),
		stringAndShort::value_type("SKILL_SCIENCE", SKILL_SCIENCE),
		stringAndShort::value_type("SKILL_SECURITY", SKILL_SECURITY),
		stringAndShort::value_type("SKILL_SEDUCTION", SKILL_SEDUCTION),
		stringAndShort::value_type("SKILL_SHOTGUN", SKILL_SHOTGUN),
		stringAndShort::value_type("SKILL_SMG", SKILL_SMG),
		stringAndShort::value_type("SKILL_STEALTH", SKILL_STEALTH),
		stringAndShort::value_type("SKILL_STREETSENSE", SKILL_STREETSENSE),
		stringAndShort::value_type("SKILL_SWORD", SKILL_SWORD),
		stringAndShort::value_type("SKILL_TAILORING", SKILL_TAILORING),
		stringAndShort::value_type("SKILL_TEACHING", SKILL_TEACHING),
		stringAndShort::value_type("SKILL_THROWING", SKILL_THROWING),
		stringAndShort::value_type("SKILL_WRITING", SKILL_WRITING)
	};
	getAttributeEnumFromString = {
		stringAndShort::value_type("ATTRIBUTE_HEART", ATTRIBUTE_HEART),
		stringAndShort::value_type("ATTRIBUTE_WISDOM", ATTRIBUTE_WISDOM),
		stringAndShort::value_type("ATTRIBUTE_INTELLIGENCE", ATTRIBUTE_INTELLIGENCE),
		stringAndShort::value_type("ATTRIBUTE_AGILITY", ATTRIBUTE_AGILITY),
		stringAndShort::value_type("ATTRIBUTE_STRENGTH", ATTRIBUTE_STRENGTH),
		stringAndShort::value_type("ATTRIBUTE_HEALTH", ATTRIBUTE_HEALTH),
		stringAndShort::value_type("ATTRIBUTE_CHARISMA", ATTRIBUTE_CHARISMA)
	};
	getCreatureEnumFromString = {
		stringAndShort::value_type("CREATURE_BOUNCER", CREATURE_BOUNCER),
		stringAndShort::value_type("CREATURE_SECURITYGUARD", CREATURE_SECURITYGUARD),
		stringAndShort::value_type("CREATURE_SCIENTIST_LABTECH", CREATURE_SCIENTIST_LABTECH),
		stringAndShort::value_type("CREATURE_SCIENTIST_EMINENT", CREATURE_SCIENTIST_EMINENT),
		stringAndShort::value_type("CREATURE_CORPORATE_MANAGER", CREATURE_CORPORATE_MANAGER),
		stringAndShort::value_type("CREATURE_CORPORATE_CEO", CREATURE_CORPORATE_CEO),
		stringAndShort::value_type("CREATURE_WORKER_SERVANT", CREATURE_WORKER_SERVANT),
		stringAndShort::value_type("CREATURE_WORKER_JANITOR", CREATURE_WORKER_JANITOR),
		stringAndShort::value_type("CREATURE_WORKER_SWEATSHOP", CREATURE_WORKER_SWEATSHOP),
		stringAndShort::value_type("CREATURE_WORKER_FACTORY_NONUNION", CREATURE_WORKER_FACTORY_NONUNION),
		stringAndShort::value_type("CREATURE_WORKER_FACTORY_CHILD", CREATURE_WORKER_FACTORY_CHILD),
		stringAndShort::value_type("CREATURE_WORKER_SECRETARY", CREATURE_WORKER_SECRETARY),
		stringAndShort::value_type("CREATURE_WORKER_FACTORY_UNION", CREATURE_WORKER_FACTORY_UNION),
		stringAndShort::value_type("CREATURE_LANDLORD", CREATURE_LANDLORD),
		stringAndShort::value_type("CREATURE_TEENAGER", CREATURE_TEENAGER),
		stringAndShort::value_type("CREATURE_COP", CREATURE_COP),
		stringAndShort::value_type("CREATURE_SWAT", CREATURE_SWAT),
		stringAndShort::value_type("CREATURE_DEATHSQUAD", CREATURE_DEATHSQUAD),
		stringAndShort::value_type("CREATURE_FIREFIGHTER", CREATURE_FIREFIGHTER),
		stringAndShort::value_type("CREATURE_EDUCATOR", CREATURE_EDUCATOR),
		stringAndShort::value_type("CREATURE_GANGUNIT", CREATURE_GANGUNIT),
		stringAndShort::value_type("CREATURE_JUDGE_LIBERAL", CREATURE_JUDGE_LIBERAL),
		stringAndShort::value_type("CREATURE_JUDGE_CONSERVATIVE", CREATURE_JUDGE_CONSERVATIVE),
		stringAndShort::value_type("CREATURE_AGENT", CREATURE_AGENT),
		stringAndShort::value_type("CREATURE_RADIOPERSONALITY", CREATURE_RADIOPERSONALITY),
		stringAndShort::value_type("CREATURE_NEWSANCHOR", CREATURE_NEWSANCHOR),
		stringAndShort::value_type("CREATURE_GENETIC", CREATURE_GENETIC),
		stringAndShort::value_type("CREATURE_GUARDDOG", CREATURE_GUARDDOG),
		stringAndShort::value_type("CREATURE_PRISONER", CREATURE_PRISONER),
		stringAndShort::value_type("CREATURE_JUROR", CREATURE_JUROR),
		stringAndShort::value_type("CREATURE_LAWYER", CREATURE_LAWYER),
		stringAndShort::value_type("CREATURE_SEWERWORKER", CREATURE_SEWERWORKER),
		stringAndShort::value_type("CREATURE_COLLEGESTUDENT", CREATURE_COLLEGESTUDENT),
		stringAndShort::value_type("CREATURE_MUSICIAN", CREATURE_MUSICIAN),
		stringAndShort::value_type("CREATURE_MATHEMATICIAN", CREATURE_MATHEMATICIAN),
		stringAndShort::value_type("CREATURE_TEACHER", CREATURE_TEACHER),
		stringAndShort::value_type("CREATURE_HSDROPOUT", CREATURE_HSDROPOUT),
		stringAndShort::value_type("CREATURE_BUM", CREATURE_BUM),
		stringAndShort::value_type("CREATURE_GANGMEMBER", CREATURE_GANGMEMBER),
		stringAndShort::value_type("CREATURE_CRACKHEAD", CREATURE_CRACKHEAD),
		stringAndShort::value_type("CREATURE_PRIEST", CREATURE_PRIEST),
		stringAndShort::value_type("CREATURE_ENGINEER", CREATURE_ENGINEER),
		stringAndShort::value_type("CREATURE_FASTFOODWORKER", CREATURE_FASTFOODWORKER),
		stringAndShort::value_type("CREATURE_BAKER", CREATURE_BAKER),
		stringAndShort::value_type("CREATURE_BARISTA", CREATURE_BARISTA),
		stringAndShort::value_type("CREATURE_BARTENDER", CREATURE_BARTENDER),
		stringAndShort::value_type("CREATURE_TELEMARKETER", CREATURE_TELEMARKETER),
		stringAndShort::value_type("CREATURE_CARSALESMAN", CREATURE_CARSALESMAN),
		stringAndShort::value_type("CREATURE_OFFICEWORKER", CREATURE_OFFICEWORKER),
		stringAndShort::value_type("CREATURE_FOOTBALLCOACH", CREATURE_FOOTBALLCOACH),
		stringAndShort::value_type("CREATURE_PROSTITUTE", CREATURE_PROSTITUTE),
		stringAndShort::value_type("CREATURE_MAILMAN", CREATURE_MAILMAN),
		stringAndShort::value_type("CREATURE_GARBAGEMAN", CREATURE_GARBAGEMAN),
		stringAndShort::value_type("CREATURE_PLUMBER", CREATURE_PLUMBER),
		stringAndShort::value_type("CREATURE_CHEF", CREATURE_CHEF),
		stringAndShort::value_type("CREATURE_CONSTRUCTIONWORKER", CREATURE_CONSTRUCTIONWORKER),
		stringAndShort::value_type("CREATURE_AMATEURMAGICIAN", CREATURE_AMATEURMAGICIAN),
		stringAndShort::value_type("CREATURE_TANK", CREATURE_TANK),
		stringAndShort::value_type("CREATURE_MERC", CREATURE_MERC),
		stringAndShort::value_type("CREATURE_HICK", CREATURE_HICK),
		stringAndShort::value_type("CREATURE_SOLDIER", CREATURE_SOLDIER),
		stringAndShort::value_type("CREATURE_VETERAN", CREATURE_VETERAN),
		stringAndShort::value_type("CREATURE_HARDENED_VETERAN", CREATURE_HARDENED_VETERAN),
		stringAndShort::value_type("CREATURE_PRISONGUARD", CREATURE_PRISONGUARD),
		stringAndShort::value_type("CREATURE_HIPPIE", CREATURE_HIPPIE),
		stringAndShort::value_type("CREATURE_CRITIC_ART", CREATURE_CRITIC_ART),
		stringAndShort::value_type("CREATURE_CRITIC_MUSIC", CREATURE_CRITIC_MUSIC),
		stringAndShort::value_type("CREATURE_SOCIALITE", CREATURE_SOCIALITE),
		stringAndShort::value_type("CREATURE_PROGRAMMER", CREATURE_PROGRAMMER),
		stringAndShort::value_type("CREATURE_RETIREE", CREATURE_RETIREE),
		stringAndShort::value_type("CREATURE_PAINTER", CREATURE_PAINTER),
		stringAndShort::value_type("CREATURE_SCULPTOR", CREATURE_SCULPTOR),
		stringAndShort::value_type("CREATURE_AUTHOR", CREATURE_AUTHOR),
		stringAndShort::value_type("CREATURE_JOURNALIST", CREATURE_JOURNALIST),
		stringAndShort::value_type("CREATURE_DANCER", CREATURE_DANCER),
		stringAndShort::value_type("CREATURE_PHOTOGRAPHER", CREATURE_PHOTOGRAPHER),
		stringAndShort::value_type("CREATURE_CAMERAMAN", CREATURE_CAMERAMAN),
		stringAndShort::value_type("CREATURE_HAIRSTYLIST", CREATURE_HAIRSTYLIST),
		stringAndShort::value_type("CREATURE_FASHIONDESIGNER", CREATURE_FASHIONDESIGNER),
		stringAndShort::value_type("CREATURE_CLERK", CREATURE_CLERK),
		stringAndShort::value_type("CREATURE_THIEF", CREATURE_THIEF),
		stringAndShort::value_type("CREATURE_ACTOR", CREATURE_ACTOR),
		stringAndShort::value_type("CREATURE_YOGAINSTRUCTOR", CREATURE_YOGAINSTRUCTOR),
		stringAndShort::value_type("CREATURE_MARTIALARTIST", CREATURE_MARTIALARTIST),
		stringAndShort::value_type("CREATURE_ATHLETE", CREATURE_ATHLETE),
		stringAndShort::value_type("CREATURE_BIKER", CREATURE_BIKER),
		stringAndShort::value_type("CREATURE_TRUCKER", CREATURE_TRUCKER),
		stringAndShort::value_type("CREATURE_TAXIDRIVER", CREATURE_TAXIDRIVER),
		stringAndShort::value_type("CREATURE_NUN", CREATURE_NUN),
		stringAndShort::value_type("CREATURE_MUTANT", CREATURE_MUTANT),
		stringAndShort::value_type("CREATURE_DOCTOR", CREATURE_DOCTOR),
		stringAndShort::value_type("CREATURE_NURSE", CREATURE_NURSE),
		stringAndShort::value_type("CREATURE_CCS_VIGILANTE", CREATURE_CCS_VIGILANTE),
		stringAndShort::value_type("CREATURE_CCS_ARCHCONSERVATIVE", CREATURE_CCS_ARCHCONSERVATIVE),
		stringAndShort::value_type("CREATURE_POLITICALACTIVIST", CREATURE_POLITICALACTIVIST),
		stringAndShort::value_type("CREATURE_CCS_MOLOTOV", CREATURE_CCS_MOLOTOV),
		stringAndShort::value_type("CREATURE_CCS_SNIPER", CREATURE_CCS_SNIPER),
		stringAndShort::value_type("CREATURE_PSYCHOLOGIST", CREATURE_PSYCHOLOGIST),
		stringAndShort::value_type("CREATURE_LOCKSMITH", CREATURE_LOCKSMITH),
		stringAndShort::value_type("CREATURE_MILITARYPOLICE", CREATURE_MILITARYPOLICE),
		stringAndShort::value_type("CREATURE_SEAL", CREATURE_SEAL),
		stringAndShort::value_type("CREATURE_MILITARYOFFICER", CREATURE_MILITARYOFFICER),
		stringAndShort::value_type("CREATURE_BANK_TELLER", CREATURE_BANK_TELLER),
		stringAndShort::value_type("CREATURE_BANK_MANAGER", CREATURE_BANK_MANAGER),
		stringAndShort::value_type("CREATURE_SECRET_SERVICE", CREATURE_SECRET_SERVICE),
		stringAndShort::value_type("CREATURE_POLITICIAN", CREATURE_POLITICIAN)
	};
	getBaseEnumFromString = {
		stringAndShort::value_type("SITE_RESIDENTIAL_SHELTER", SITE_RESIDENTIAL_SHELTER),
		stringAndShort::value_type("SITE_RESIDENTIAL_TENEMENT", SITE_RESIDENTIAL_TENEMENT),
		stringAndShort::value_type("SITE_RESIDENTIAL_APARTMENT", SITE_RESIDENTIAL_APARTMENT),
		stringAndShort::value_type("SITE_RESIDENTIAL_APARTMENT_UPSCALE", SITE_RESIDENTIAL_APARTMENT_UPSCALE),
		stringAndShort::value_type("SITE_RESIDENTIAL_BOMBSHELTER", SITE_RESIDENTIAL_BOMBSHELTER),
		stringAndShort::value_type("SITE_LABORATORY_COSMETICS", SITE_LABORATORY_COSMETICS),
		stringAndShort::value_type("SITE_LABORATORY_GENETIC", SITE_LABORATORY_GENETIC),
		stringAndShort::value_type("SITE_GOVERNMENT_POLICESTATION", SITE_GOVERNMENT_POLICESTATION),
		stringAndShort::value_type("SITE_GOVERNMENT_COURTHOUSE", SITE_GOVERNMENT_COURTHOUSE),
		stringAndShort::value_type("SITE_GOVERNMENT_PRISON", SITE_GOVERNMENT_PRISON),
		stringAndShort::value_type("SITE_GOVERNMENT_INTELLIGENCEHQ", SITE_GOVERNMENT_INTELLIGENCEHQ),
		stringAndShort::value_type("SITE_GOVERNMENT_FIRESTATION", SITE_GOVERNMENT_FIRESTATION),
		stringAndShort::value_type("SITE_INDUSTRY_SWEATSHOP", SITE_INDUSTRY_SWEATSHOP),
		stringAndShort::value_type("SITE_INDUSTRY_POLLUTER", SITE_INDUSTRY_POLLUTER),
		stringAndShort::value_type("SITE_INDUSTRY_NUCLEAR", SITE_INDUSTRY_NUCLEAR),
		stringAndShort::value_type("SITE_INDUSTRY_WAREHOUSE", SITE_INDUSTRY_WAREHOUSE),
		stringAndShort::value_type("SITE_CORPORATE_HEADQUARTERS", SITE_CORPORATE_HEADQUARTERS),
		stringAndShort::value_type("SITE_CORPORATE_HOUSE", SITE_CORPORATE_HOUSE),
		stringAndShort::value_type("SITE_MEDIA_AMRADIO", SITE_MEDIA_AMRADIO),
		stringAndShort::value_type("SITE_MEDIA_CABLENEWS", SITE_MEDIA_CABLENEWS),
		stringAndShort::value_type("SITE_BUSINESS_CRACKHOUSE", SITE_BUSINESS_CRACKHOUSE),
		stringAndShort::value_type("SITE_BUSINESS_JUICEBAR", SITE_BUSINESS_JUICEBAR),
		stringAndShort::value_type("SITE_BUSINESS_CIGARBAR", SITE_BUSINESS_CIGARBAR),
		stringAndShort::value_type("SITE_BUSINESS_LATTESTAND", SITE_BUSINESS_LATTESTAND),
		stringAndShort::value_type("SITE_BUSINESS_VEGANCOOP", SITE_BUSINESS_VEGANCOOP),
		stringAndShort::value_type("SITE_BUSINESS_INTERNETCAFE", SITE_BUSINESS_INTERNETCAFE),
		stringAndShort::value_type("SITE_BUSINESS_BARANDGRILL", SITE_BUSINESS_BARANDGRILL),
		stringAndShort::value_type("SITE_OUTDOOR_PUBLICPARK", SITE_OUTDOOR_PUBLICPARK),
		stringAndShort::value_type("SITE_OUTDOOR_BUNKER", SITE_OUTDOOR_BUNKER),
		stringAndShort::value_type("SITE_GOVERNMENT_ARMYBASE", SITE_GOVERNMENT_ARMYBASE),
		stringAndShort::value_type("SITE_BUSINESS_BANK", SITE_BUSINESS_BANK),
		stringAndShort::value_type("SITE_GOVERNMENT_LIBERAL_PARTY_HQ", SITE_GOVERNMENT_LIBERAL_PARTY_HQ),
		stringAndShort::value_type("SITE_GOVERNMENT_WHITE_HOUSE", SITE_GOVERNMENT_WHITE_HOUSE)
	};
	getSpecialWoundEnumFromString = {
		stringAndShort::value_type("SPECIALWOUND_TEETH", SPECIALWOUND_TEETH),
		stringAndShort::value_type("SPECIALWOUND_RIGHTEYE", SPECIALWOUND_RIGHTEYE),
		stringAndShort::value_type("SPECIALWOUND_LEFTEYE", SPECIALWOUND_LEFTEYE),
		stringAndShort::value_type("SPECIALWOUND_NOSE", SPECIALWOUND_NOSE),
		stringAndShort::value_type("SPECIALWOUND_TONGUE", SPECIALWOUND_TONGUE),
		stringAndShort::value_type("SPECIALWOUND_RIGHTLUNG", SPECIALWOUND_RIGHTLUNG),
		stringAndShort::value_type("SPECIALWOUND_LEFTLUNG", SPECIALWOUND_LEFTLUNG),
		stringAndShort::value_type("SPECIALWOUND_HEART", SPECIALWOUND_HEART),
		stringAndShort::value_type("SPECIALWOUND_LIVER", SPECIALWOUND_LIVER),
		stringAndShort::value_type("SPECIALWOUND_STOMACH", SPECIALWOUND_STOMACH),
		stringAndShort::value_type("SPECIALWOUND_RIGHTKIDNEY", SPECIALWOUND_RIGHTKIDNEY),
		stringAndShort::value_type("SPECIALWOUND_LEFTKIDNEY", SPECIALWOUND_LEFTKIDNEY),
		stringAndShort::value_type("SPECIALWOUND_SPLEEN", SPECIALWOUND_SPLEEN),
		stringAndShort::value_type("SPECIALWOUND_RIBS", SPECIALWOUND_RIBS),
		stringAndShort::value_type("SPECIALWOUND_NECK", SPECIALWOUND_NECK),
		stringAndShort::value_type("SPECIALWOUND_UPPERSPINE", SPECIALWOUND_UPPERSPINE),
		stringAndShort::value_type("SPECIALWOUND_LOWERSPINE", SPECIALWOUND_LOWERSPINE)
	};
	conservativeLegalArgument = {
		shortAndString::value_type(LAW_ABORTION,     "\"Abortion is murder.\""),
		shortAndString::value_type(LAW_ANIMALRESEARCH,"\"Don't pretend animals are human.\""),
		shortAndString::value_type(LAW_POLICEBEHAVIOR,"\"Only criminals have reason to fear police.\""),
		shortAndString::value_type(LAW_PRIVACY,      "\"National security is important.\""),
		shortAndString::value_type(LAW_DEATHPENALTY, "\"Some people deserve to die.\""),
		shortAndString::value_type(LAW_NUCLEARPOWER, "\"Nuclear power is clean.\""),
		shortAndString::value_type(LAW_POLLUTION,    "\"It's not that bad.\""),
		shortAndString::value_type(LAW_LABOR,        "\"Trust the free market, it hasn't failed us yet.\""),
		shortAndString::value_type(LAW_GAY,          "\"Homosexuality is a sin.\""),
		shortAndString::value_type(LAW_CORPORATE,    "\"Corporations are part of capitalism.\""),
		shortAndString::value_type(LAW_FREESPEECH,   "\"Don't be offensive and you'll be fine.\""),
		shortAndString::value_type(LAW_FLAGBURNING,  "\"That flag is the sacred symbol of our country.\""),
		shortAndString::value_type(LAW_TAX,          "\"I want to pay lower taxes.\""),
		shortAndString::value_type(LAW_GUNCONTROL,   "\"Without guns, we're slaves to the Government.\""),
		shortAndString::value_type(LAW_WOMEN,        "\"Why don't you go burn a bra or something?\""),
		shortAndString::value_type(LAW_CIVILRIGHTS,  "\"Reverse discrimination is still discrimination.\""),
		shortAndString::value_type(LAW_DRUGS,        "\"Drugs are a terrible influence on society.\""),
		shortAndString::value_type(LAW_IMMIGRATION,  "\"Immigration undermines our economy and culture.\""),
		shortAndString::value_type(LAW_ELECTIONS,    "\"Unregulated campaigning is a matter of free speech.\""),
		shortAndString::value_type(LAW_MILITARY,     "\"The military protects us and enables our way of life.\""),
		shortAndString::value_type(LAW_TORTURE,      "\"The terrorists would do worse to us.\""),
		shortAndString::value_type(LAW_PRISONS,      "\"Criminals deserve what they get in prison.\"")
	};
	youAreStupidTalkAboutIssues = {
		shortAndString::value_type(LAW_ABORTION,      "\"Conservatives make women turn to coat hangers.\""),
		shortAndString::value_type(LAW_ANIMALRESEARCH,"\"Richard Gere put a gerbil in his butt!\""),
		shortAndString::value_type(LAW_PRIVACY,       "\"The government, like, knows things about you.\""),
		shortAndString::value_type(LAW_DEATHPENALTY,  "\"They executed this one dude, and like, his head caught on fire.\""),
		shortAndString::value_type(LAW_NUCLEARPOWER,  "\"Have you seen Godzilla?  Nuclear power is bad, yo.\""),
		shortAndString::value_type(LAW_POLLUTION,     "\"You wanna look like the Toxic Avenger?  Oppose pollution!\""),
		shortAndString::value_type(LAW_LABOR,         "\"Bad people wanna make babies work and stuff.\""),
		shortAndString::value_type(LAW_GAY,           "\"Lots of people don't like homosexuals.\""),
		shortAndString::value_type(LAW_CORPORATE,     "\"The corporations are putting you down, dude.\""),
		shortAndString::value_type(LAW_FREESPEECH,    "\"Better watch what you say.  They've got ears everywhere.\""),
		shortAndString::value_type(LAW_FLAGBURNING,   "\"The flag is stupid.\""),
		shortAndString::value_type(LAW_TAX,           "\"Rich people, like, have money, man.\""),
		shortAndString::value_type(LAW_GUNCONTROL,    "\"People like, think they need lots of guns.\""),
		shortAndString::value_type(LAW_WOMEN,         "\"We need more women!\""),
		shortAndString::value_type(LAW_CIVILRIGHTS,   "\"Conservatives are all racists!\""),
		shortAndString::value_type(LAW_DRUGS,         "\"Dude, the government won't let you do drugs.\""),
		shortAndString::value_type(LAW_IMMIGRATION,   "\"They're all trying to keep people out of the country.\""),
		shortAndString::value_type(LAW_ELECTIONS,     "\"The politicians are just tools of the corporations!\""),
		shortAndString::value_type(LAW_MILITARY,      "\"Patriots are idiots! Give peace a chance!\""),
		shortAndString::value_type(LAW_TORTURE,       "\"Torture is bad!\""),
		shortAndString::value_type(LAW_PRISONS,       "\"Prisoners don't have freedom!\"")
	};
	issueTooLiberal = {
		shortAndString::value_type(LAW_ABORTION,      "\"Conservatives don't like abortion.\""),
		shortAndString::value_type(LAW_ANIMALRESEARCH,"\"Animals are denied the right to vote.\""),
		shortAndString::value_type(LAW_POLICEBEHAVIOR,"\"The police are still out there.\""),
		shortAndString::value_type(LAW_PRIVACY,       "\"The government runs intelligence agencies.\""),
		shortAndString::value_type(LAW_DEATHPENALTY,  "\"You can go to prison for life for serious crimes.\""),
		shortAndString::value_type(LAW_NUCLEARPOWER,  "\"Some people support legalizing nuclear power.\""),
		shortAndString::value_type(LAW_POLLUTION,     "\"We're still polluting a little bit.\""),
		shortAndString::value_type(LAW_LABOR,         "\"Corporate bosses don't always give in to unions.\""),
		shortAndString::value_type(LAW_GAY,           "\"Not everybody likes gay people.\""),
		shortAndString::value_type(LAW_CORPORATE,     "\"There are corporations.\""),
		shortAndString::value_type(LAW_FREESPEECH,    "\"People get mad if you swear a lot in public.\""),
		shortAndString::value_type(LAW_FLAGBURNING,   "\"The flag code says you shouldn't make it into clothing.\""),
		shortAndString::value_type(LAW_TAX,           "\"There's still inequality in this country.\""),
		shortAndString::value_type(LAW_GUNCONTROL,    "\"We need to repeal the second amendment.\""),
		shortAndString::value_type(LAW_WOMEN,         "\"Some people are sexist.\""),
		shortAndString::value_type(LAW_CIVILRIGHTS,   "\"I knew some people that were pretty racist.\""),
		shortAndString::value_type(LAW_DRUGS,         "\"Drugs are expensive.\""),
		shortAndString::value_type(LAW_IMMIGRATION,   "\"All the immigrants, not everybody likes them.\""),
		shortAndString::value_type(LAW_ELECTIONS,     "\"Some of these politicians rub me the wrong way.\""),
		shortAndString::value_type(LAW_MILITARY,      "\"We still have a military.\""),
		shortAndString::value_type(LAW_TORTURE,       "\"Some conservatives support torture.\""),
		shortAndString::value_type(LAW_PRISONS,       "\"Prisons still exist.\"")
	};
	talkAboutTheIssues =
	{
		shortAndTwoStrings::value_type(LAW_ABORTION,{ "\"The government is systematically trying to rob women of the right ",	"to control their own destinies.\"" }),
		shortAndTwoStrings::value_type(LAW_ANIMALRESEARCH,{ "\"Animals are routinely subjected to inhumane treatment in labs in this",	"country.\"" }),
		shortAndTwoStrings::value_type(LAW_POLICEBEHAVIOR,{ "\"The police regularly torture minority suspects during interrogations.\"", "" }),
		shortAndTwoStrings::value_type(LAW_PRIVACY,{ "\"Files are being kept on innocent citizens whose only crime is to ",	"speak out against a system that is trying to farm them like beasts.\"" }),
		shortAndTwoStrings::value_type(LAW_DEATHPENALTY,{ "\"Over thirty innocent people have been executed over the past decade.\"","" }),
		shortAndTwoStrings::value_type(LAW_NUCLEARPOWER,{ "\"Radioactive waste is being stored all over the country, and it poses ",	"a serious threat to many families, even in this neighborhood.\"" }),
		shortAndTwoStrings::value_type(LAW_LABOR,{ "\"Have you noticed how people are working more and more hours for less and ",	"less money?  It's all part of a plan to keep you enslaved, man.\"" }),
		shortAndTwoStrings::value_type(LAW_GAY,{ "\"Homosexuals are people like anyone else, and yet they are treated in this ",	"country as if they are deviants fit only for cheap entertainment.\"" }),
		shortAndTwoStrings::value_type(LAW_CORPORATE,{ "\"Corporate executives use giant corporations as a means to become parasites ",	"that suck wealth out of this country and put it into their pockets.\"" }),
		shortAndTwoStrings::value_type(LAW_FREESPEECH,{ "\"Protests and demonstrations are regularly and often brutally suppressed in ",	"this country.  People have to watch what they write -- even what they read.\"" }),
		shortAndTwoStrings::value_type(LAW_FLAGBURNING,{ "\"Burning a piece of cloth is actually stigmatized in this country. ",	"You can love freedom and still hate what our government stands for.\"" }),
		shortAndTwoStrings::value_type(LAW_TAX,{ "\"The tax code has been designed to perpetuate an unjust class ",	"structure that is keeping you oppressed.\"" }),
		shortAndTwoStrings::value_type(LAW_GUNCONTROL,{ "\"We live in such a backwards country right now that people think it's ",	"a right to walk around with the power to murder at any moment.\"" }),
		shortAndTwoStrings::value_type(LAW_WOMEN,{ "\"Sexism is still pervasive, in subtle ways, and women make much less ",	"than they deserve for their labor.\"" }),
		shortAndTwoStrings::value_type(LAW_CIVILRIGHTS,{ "\"Despite our progress, this society is still strangled by its continuing ",	"legacy of racial discrimination and inequality.\"" }),
		shortAndTwoStrings::value_type(LAW_DRUGS,{ "\"The government's drug policy is a mess.  We need to stop filling ",	"prisons with drug users, and only intervene when people really need help.\"" }),
		shortAndTwoStrings::value_type(LAW_IMMIGRATION,{ "\"Millions of people are doing jobs most folks don't even want, and ",	"saving their families from poverty, but we just try to kick them out.\"" }),
		shortAndTwoStrings::value_type(LAW_ELECTIONS,{ "\"Political favors are bought and sold for campaign contributions, ",	"and the voting system enforces two party dominance.\"" }),
		shortAndTwoStrings::value_type(LAW_MILITARY,{ "\"Take a breath and think about the world we live in, that we're spending ",	"hundreds of billions on new ways to kill people.  This has to stop!\"" }),
		shortAndTwoStrings::value_type(LAW_TORTURE,{ "\"In the name of the war on terror, we've sacrificed our soul by letting ",	"the government torture and abuse human beings on our behalf.\"" }),
		shortAndTwoStrings::value_type(LAW_PRISONS,{ "\"The prison system doesn't help criminals by providing rehabilitation, so ",	"when they get released, they mostly become criminals again.\"" })
	};
	tankBodyParts = {
		shortAndString::value_type(BODYPART_HEAD, "turret"),
		shortAndString::value_type(BODYPART_BODY, "front"),
		shortAndString::value_type(BODYPART_ARM_RIGHT, "right side"),
		shortAndString::value_type(BODYPART_ARM_LEFT, "left side"),
		shortAndString::value_type(BODYPART_LEG_RIGHT, "right tread"),
		shortAndString::value_type(BODYPART_LEG_LEFT, "left tread")
	};
	animalBodyParts = {
		shortAndString::value_type(BODYPART_HEAD, "head"),
		shortAndString::value_type(BODYPART_BODY, "body"),
		shortAndString::value_type(BODYPART_ARM_RIGHT, "right front leg"),
		shortAndString::value_type(BODYPART_ARM_LEFT, "left front leg"),
		shortAndString::value_type(BODYPART_LEG_RIGHT, "right rear leg"),
		shortAndString::value_type(BODYPART_LEG_LEFT, "left rear leg")
	};
	humanBodyParts = {
		shortAndString::value_type(BODYPART_HEAD, "head"),
		shortAndString::value_type(BODYPART_BODY, "body"),
		shortAndString::value_type(BODYPART_ARM_RIGHT, "right arm"),
		shortAndString::value_type(BODYPART_ARM_LEFT, "left arm"),
		shortAndString::value_type(BODYPART_LEG_RIGHT, "right leg"),
		shortAndString::value_type(BODYPART_LEG_LEFT, "left leg")
	};
	supportsLiberalLaw = {
		shortAndString::value_type(VIEW_GAY, "were in favor of equal rights for homosexuals"),
		shortAndString::value_type(VIEW_DEATHPENALTY, "opposed the death penalty"),
		shortAndString::value_type(VIEW_TAXES, "were against cutting taxes"),
		shortAndString::value_type(VIEW_NUCLEARPOWER, "were terrified of nuclear power"),
		shortAndString::value_type(VIEW_ANIMALRESEARCH, "deplored animal research"),
		shortAndString::value_type(VIEW_POLICEBEHAVIOR, "were critical of the police"),
		shortAndString::value_type(VIEW_TORTURE, "wanted stronger measures to prevent torture"),
		shortAndString::value_type(VIEW_INTELLIGENCE, "thought the intelligence community invades privacy"),
		shortAndString::value_type(VIEW_FREESPEECH, "believed in unfettered free speech"),
		shortAndString::value_type(VIEW_GENETICS, "abhorred genetically altered food products"),
		shortAndString::value_type(VIEW_JUSTICES, "were for the appointment of Liberal justices"),
		shortAndString::value_type(VIEW_SWEATSHOPS, "would boycott companies that used sweatshops"),
		shortAndString::value_type(VIEW_POLLUTION, "thought industry should lower pollution"),
		shortAndString::value_type(VIEW_CORPORATECULTURE, "were disgusted by corporate malfeasance"),
		shortAndString::value_type(VIEW_CEOSALARY, "believed that CEO salaries are too great"),
		shortAndString::value_type(VIEW_WOMEN, "favored doing more for gender equality"),
		shortAndString::value_type(VIEW_CIVILRIGHTS, "felt more work was needed for racial equality"),
		shortAndString::value_type(VIEW_GUNCONTROL, "are concerned about gun violence"),
		shortAndString::value_type(VIEW_MILITARY, "opposed increasing military spending"),
		shortAndString::value_type(VIEW_LIBERALCRIMESQUAD, "respected the power of the Liberal Crime Squad"),
		shortAndString::value_type(VIEW_LIBERALCRIMESQUADPOS, "of these held the Liberal Crime Squad in high regard"),
		shortAndString::value_type(VIEW_CONSERVATIVECRIMESQUAD, "held the Conservative Crime Squad in contempt"),
		shortAndString::value_type(VIEW_PRISONS, "wanted to end prisoner abuse and torture"),
		shortAndString::value_type(VIEW_AMRADIO, "do not like AM radio"),
		shortAndString::value_type(VIEW_CABLENEWS, "have a negative opinion of cable news programs"),
		//shortAndString::value_type( VIEW_POLITICALVIOLENCE, "thought political violence was justified")
	};
	winnerOfElection = {
		shortAndString::value_type(ALIGN_ARCHCONSERVATIVE, "The $$ U.S.A. Flag Eagle $$ Conservative Tea Party claims victory!"),
		shortAndString::value_type(ALIGN_CONSERVATIVE, "The Conservative Party claims victory!"),
		shortAndString::value_type(ALIGN_MODERATE, "The next two years promise to be more of the same."),
		shortAndString::value_type(ALIGN_LIBERAL, "The Liberal Party claims victory!"),
		shortAndString::value_type(ALIGN_ELITELIBERAL, "The Progressive Elite Social Liberal Green Party claims victory!"),
		shortAndString::value_type(ALIGN_STALINIST, "The Stalinist Party claims victory!")
	};
	newsStories = {
		shortAndTwoStrings::value_type(NEWSSTORY_SQUAD_ESCAPED,
		{ "escaped from a police siege yesterday, according " }),
		shortAndTwoStrings::value_type(NEWSSTORY_SQUAD_FLEDATTACK,
		{ "escaped from police officers during a raid yesterday, according " }),
		shortAndTwoStrings::value_type(NEWSSTORY_SQUAD_DEFENDED,
		{ "fought off a police raid yesterday, according " }),
		shortAndTwoStrings::value_type(NEWSSTORY_SQUAD_BROKESIEGE,
		{ "violently broke a police siege yesterday, according " }),
		shortAndTwoStrings::value_type(NEWSSTORY_SQUAD_KILLED_SIEGEATTACK,
		{ "were slain during a police raid yesterday, according ",
			"were murdered during a police raid yesterday, according " }),
		shortAndTwoStrings::value_type(NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE,
		{ "were slain trying to escape from a police siege yesterday, according ",
			"were murdered trying to escape from a police siege yesterday, according " })
	};
	cityNames = {
		shortAndString::value_type(SITE_CITY_SEATTLE,  "Seattle, WA"),
		shortAndString::value_type(SITE_CITY_NEW_YORK,  "New York, NY"),
		shortAndString::value_type(SITE_CITY_LOS_ANGELES,  "Los Angeles, CA"),
		shortAndString::value_type(SITE_CITY_CHICAGO,  "Chicago, IL"),
		shortAndString::value_type(SITE_CITY_DETROIT,  "Detroit, MI"),
		shortAndString::value_type(SITE_CITY_ATLANTA,  "Atlanta, GA"),
		shortAndString::value_type(SITE_CITY_MIAMI,  "Miami, FL"),
		shortAndString::value_type(SITE_CITY_WASHINGTON_DC,  "Washington, DC"),
	};
	 supremeChars = {
		'S',
		'U',
		'P',
		'R',
		'E',
		'M',
		'E'
	};
	 courtChars = {
		'C',
		'O',
		'U',
		'R',
		'T'
	};
	carchaseObstacles = {
		shortAndTwoStrings::value_type(CARCHASE_OBSTACLE_FRUITSTAND,
		//LIMIT :------------------------------------:
		{ "You are speeding toward a flimsy fruit stand!",
			"D - Swerve to avoid hitting anyone!",
			"F - Play it safe and plow through it!" }),
		shortAndTwoStrings::value_type(CARCHASE_OBSTACLE_TRUCKPULLSOUT,
			//LIMIT :------------------------------------:
		{ "A truck pulls out in your path!",
			"D - Speed around it!",
			"F - Slow down!" }),
		shortAndTwoStrings::value_type(CARCHASE_OBSTACLE_CROSSTRAFFIC,
			//LIMIT :------------------------------------:
		{ "There's a red light with cross traffic ahead!",
			"D - Run the light anyway!",
			"F - Slow down and turn!" }),
		shortAndTwoStrings::value_type(CARCHASE_OBSTACLE_CHILD,
			//LIMIT :------------------------------------:
		{ "A kid runs into the street for his ball!",
			"D - Swerve around him!",
			"F - Slam the brakes!" })
	};
	skillEnumToString = {
		shortAndString::value_type(SKILL_HANDTOHAND,      "Martial Arts"),
		shortAndString::value_type(SKILL_KNIFE,           "Knife"),
		shortAndString::value_type(SKILL_SWORD,           "Sword"),
		shortAndString::value_type(SKILL_THROWING,        "Throwing"),
		shortAndString::value_type(SKILL_CLUB,            "Club"),
		shortAndString::value_type(SKILL_AXE,             "Axe"),
		shortAndString::value_type(SKILL_PISTOL,          "Pistol"),
		shortAndString::value_type(SKILL_RIFLE,           "Rifle"),
		shortAndString::value_type(SKILL_HEAVYWEAPONS,    "Heavy Weapons"),
		shortAndString::value_type(SKILL_SHOTGUN,         "Shotgun"),
		shortAndString::value_type(SKILL_SMG,             "SMG"),
		shortAndString::value_type(SKILL_PERSUASION,      "Persuasion"),
		shortAndString::value_type(SKILL_PSYCHOLOGY,      "Psychology"),
		shortAndString::value_type(SKILL_SECURITY,        "Security"),
		shortAndString::value_type(SKILL_DISGUISE,        "Disguise"),
		shortAndString::value_type(SKILL_COMPUTERS,       "Computers"),
		shortAndString::value_type(SKILL_LAW,             "Law"),
		shortAndString::value_type(SKILL_TAILORING,       "Tailoring"),
		shortAndString::value_type(SKILL_DRIVING,         "Driving"),
		shortAndString::value_type(SKILL_WRITING,         "Writing"),
		shortAndString::value_type(SKILL_MUSIC,           "Music"),
		shortAndString::value_type(SKILL_ART,             "Art"),
		shortAndString::value_type(SKILL_RELIGION,        "Religion"),
		shortAndString::value_type(SKILL_SCIENCE,         "Science"),
		shortAndString::value_type(SKILL_BUSINESS,        "Business"),
		shortAndString::value_type(SKILL_STEALTH,         "Stealth"),
		shortAndString::value_type(SKILL_TEACHING,        "Teaching"),
		shortAndString::value_type(SKILL_STREETSENSE,     "Street Sense"),
		shortAndString::value_type(SKILL_SEDUCTION,       "Seduction"),
		shortAndString::value_type(SKILL_FIRSTAID,        "First Aid"),
		shortAndString::value_type(SKILL_DODGE,           "Dodge")
	};
	attEnumToString = {
		shortAndString::value_type(ATTRIBUTE_STRENGTH,       "STR"),
		shortAndString::value_type(ATTRIBUTE_AGILITY,        "AGI"),
		shortAndString::value_type(ATTRIBUTE_WISDOM,         "WIS"),
		shortAndString::value_type(ATTRIBUTE_INTELLIGENCE,   "INT"),
		shortAndString::value_type(ATTRIBUTE_HEART,          "HRT"),
		shortAndString::value_type(ATTRIBUTE_HEALTH,         "HLTH"),
		shortAndString::value_type(ATTRIBUTE_CHARISMA,       "CHA")
	};
	getAlignString = {
		shortAndString::value_type(ALIGN_ARCHCONSERVATIVE,  "Arch-Conservative"),
		shortAndString::value_type(ALIGN_CONSERVATIVE,  "Conservative"),
		shortAndString::value_type(ALIGN_MODERATE,  "Moderate"),
		shortAndString::value_type(ALIGN_LIBERAL,  "Liberal"),
		shortAndString::value_type(ALIGN_ELITELIBERAL,  "Elite Liberal"),
		shortAndString::value_type(ALIGN_STALINIST,  "Stalinist")
	};
	 musicList = {
		// titlemode.ogg or .mid - Also sprach Zarathustra, introduction by Richard Strauss
		shortAndString::value_type(MUSIC_TITLEMODE, "titlemode"), // load title mode music
																  // newgame.ogg or .mid- The Liberty Bell March by John Philip Sousa
		shortAndString::value_type(MUSIC_NEWGAME, "newgame"), // load new game music
															  // basemode.ogg or .mid - The Stars and Stripes Forever by John Philip Sousa
		shortAndString::value_type(MUSIC_BASEMODE, "basemode"), // load regular base mode music
																// siege.ogg or .mid- The Planets, 1st Movement "Mars" by Gustav Holst
		shortAndString::value_type(MUSIC_SIEGE, "siege"), // load base mode while under siege music
														  // activate.ogg or .mid - Piano Sonata #11, 3rd Movement "Rondo Alla Turca" by Wolfgang Amadeus Mozart
		shortAndString::value_type(MUSIC_ACTIVATE, "activate"), // load activate Liberals music
																// sleepers.ogg or .mid - Toccata and Fugue in D Minor, BWV 565 by Johann Sebastian Bach
		shortAndString::value_type(MUSIC_SLEEPERS, "sleepers"), // load activate Sleepers music
																// stopevil.ogg or .mid - Hungarian Dance #5 by Johannes Brahms (based on the csardas "Bartfai emlek" by Bela Keler)
		shortAndString::value_type(MUSIC_STOPEVIL, "stopevil"), // load go forth to stop evil music
																// reviewmode.ogg or .mid - Symphony #94, 2nd Movement "Surprise Symphony" by Joseph Haydn
		shortAndString::value_type(MUSIC_REVIEWMODE, "reviewmode"), // load review mode music
																	// liberalagenda.ogg or .mid - Beautiful Dreamer by Stephen Foster
		shortAndString::value_type(MUSIC_LIBERALAGENDA, "liberalagenda"), // load status of the Liberal agenda music
																		  // disbanded.ogg or .mid - La Cucaracha, a traditional Mexican folk song originally from Spain
		shortAndString::value_type(MUSIC_DISBANDED, "disbanded"), // load disbanded music
																  // finances.ogg or .mid - Minuet in G Major by Christian Petzold (falsely attributed to Johann Sebastian Bach until 1970)
		shortAndString::value_type(MUSIC_FINANCES, "finances"), // load finance report music
																// cartheft.ogg or .mid - The Ride of the Valkyries by Richard Wanger
		shortAndString::value_type(MUSIC_CARTHEFT, "cartheft"), // load car theft music
																// elections.ogg or .mid - Habanera from Carmen by Georges Bizet
		shortAndString::value_type(MUSIC_ELECTIONS, "elections"), // load elections music
																  // shopping.ogg or .mid - The Entertainer by Scott Joplin
		shortAndString::value_type(MUSIC_SHOPPING, "shopping"), // load shopping music
																// sitemode.ogg or .mid - Dance of the Sugar Plum Fairy by Pyotr Ilyich Tchaikovsky
		shortAndString::value_type(MUSIC_SITEMODE, "sitemode"), // load site mode music
																// suspicious.ogg or .mid - Hall of the Mountain King by Edvard Grieg
		shortAndString::value_type(MUSIC_SUSPICIOUS, "suspicious"), // load suspicious music
																	// alarmed.ogg or .mid - 5th Symphony, 1st Movement by Ludwig van Beethoven
		shortAndString::value_type(MUSIC_ALARMED, "alarmed"), // load alarmed music
															  // heavycombat.ogg or .mid - 6th Symphony "Pastorale", 4th Movement by Ludwig van Beethoven
		shortAndString::value_type(MUSIC_HEAVYCOMBAT, "heavycombat"), // load massive Conservative response music
																	  // defense.ogg or .mid - Danse Macabre by Camille Saint-Saens
		shortAndString::value_type(MUSIC_DEFENSE, "defense"), // load escaping/engaging a siege music
															  // conquer.ogg or .mid - Infernal Galop / Can-Can from Orpheus in the Underworld by Jacques Offenbach
		shortAndString::value_type(MUSIC_CONQUER, "conquer"), // load success in conquering a siege or safehouse or the CCS music
															  // carchase.ogg or .mid - The William Tell Overture by Gioacchino Antonio Rossini
		shortAndString::value_type(MUSIC_CARCHASE, "carchase"), // load car chase music
																// footchase.ogg or .mid - The Maple Leaf Rag by Scott Joplin
		shortAndString::value_type(MUSIC_FOOTCHASE, "footchase"), // load foot chase music
																  // interrogation.ogg or .mid - Night on Bald Mountain by Modest Mussorgsky
		shortAndString::value_type(MUSIC_INTERROGATION, "interrogation"), // load interrogation music
																		  // trial.ogg or .mid - Hungarian Rhapsody #2 by Franz Liszt
		shortAndString::value_type(MUSIC_TRIAL, "trial"), // load trial music
														  // recruiting.ogg or .mid - Dance of the Hours by Amilcare Ponchielli
		shortAndString::value_type(MUSIC_RECRUITING, "recruiting"), // load recruiting music
																	// dating.ogg or .mid - The Blue Danube Waltz by Johann Strauss Jr.
		shortAndString::value_type(MUSIC_DATING, "dating"), // load dating music
															// newspaper.ogg or .mid - Eine Kleine Nachtmusik, 1st Movement by Wolfgang Amadeus Mozart
		shortAndString::value_type(MUSIC_NEWSPAPER, "newspaper"), // load newspaper music
																  // lacops.ogg or .mid - The Flight of the Bumblebee by Nikolai Rimsky-Korsakov
		shortAndString::value_type(MUSIC_LACOPS, "lacops"), // load LA cops beating black man and getting caught on video music
															// newscast.ogg or .mid - La Marseillaise, The French National Anthem by Claude Joseph Rouget de Lisle
		shortAndString::value_type(MUSIC_NEWSCAST, "newscast"), // load newscast where smart liberal guest gets some words in edgewise music
																// glamshow.ogg or .mid - Das Deutschlandlied, The German National Anthem by Joseph Haydn
		shortAndString::value_type(MUSIC_GLAMSHOW, "glamshow"), // load glamorous TV show about lifestyles of the rich and famous music
																// anchor.ogg or .mid - I Am the Very Model of a Modern Major-General by Sir Arthur Seymour Sullivan
		shortAndString::value_type(MUSIC_ANCHOR, "anchor"), // load handsome charismatic new Conservative cable news anchor music
															// abort.ogg or .mid - Tarantella Napoletana, a traditional Italian folk song from Naples
		shortAndString::value_type(MUSIC_ABORT, "abort"), // load failed partial birth abortion on trashy daytime talk show music
														  // victory.ogg or .mid - The Star-Spangled Banner, The U.S. National Anthem by John Stafford Smith
		shortAndString::value_type(MUSIC_VICTORY, "victory"), // load victory music
															  // defeat.ogg or .mid - Piano Sonata #2, 3rd Movement "Funeral March" by Frederic Francois Chopin
		shortAndString::value_type(MUSIC_DEFEAT, "defeat"), // load defeat music
															// reagainified.ogg or .mid - Dixie, The Confederate National Anthem by Daniel Decatur Emmett
		shortAndString::value_type(MUSIC_REAGANIFIED, "reaganified"), // load Reaganified music
																	  // stalinized.ogg or .mid - The Soviet (and now Russian) National Anthem by Alexander Vasilyevich Alexandrov
		shortAndString::value_type(MUSIC_STALINIZED, "stalinized") // load Stalinized music
	};
	return true;
}
