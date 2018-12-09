#define	EXTERNALLYSTOREDDATA_CPP
#include "includes.h"

bool initialize_more_incomplete_txt() {
	// this is the string data for activities. they write up to three lines of text about the activity
	// the ones with a skill on the end (e.g. ACTIVITY_SELL_ART, ACTIVITY_SELL_MUSIC) pick one of the three lines of text based on the skill in question
	data_activities =
	{
		 map<Activity, Data_Activity>::value_type(ACTIVITY_COMMUNITYSERVICE, Data_Activity('a', true, CONST_externallyStoredData207, CONST_externallyStoredDataB1001)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_TROUBLE, Data_Activity('a', true, CONST_externallyStoredData208)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_GRAFFITI, Data_Activity('a', true, CONST_externallyStoredData209, CONST_externallyStoredDataB1002)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_POLLS, Data_Activity('a', true, CONST_externallyStoredData210, CONST_externallyStoredDataB1003, CONST_externallyStoredDataC1076)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_DOS_ATTACKS, Data_Activity('a', true, CONST_externallyStoredData211, CONST_externallyStoredDataB1004)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_HACKING, Data_Activity('a', true, CONST_externallyStoredData212, CONST_externallyStoredDataB1005, CONST_externallyStoredDataC1077)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_WRITE_LETTERS, Data_Activity('a', true, CONST_externallyStoredData213)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_WRITE_GUARDIAN, Data_Activity('a', true, CONST_externallyStoredData214)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_DONATIONS, Data_Activity('b', true, CONST_externallyStoredData215, CONST_externallyStoredDataB1006, CONST_externallyStoredDataC1078)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_SELL_TSHIRTS, Data_Activity('b', true, CONST_externallyStoredData216, CONST_externallyStoredDataB1007, CONST_externallyStoredDataC1079, SKILL_TAILORING)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_SELL_ART, Data_Activity('b', true, CONST_externallyStoredData217, CONST_externallyStoredDataB1008, CONST_externallyStoredDataC1080, SKILL_ART)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_SELL_MUSIC, Data_Activity('b', true, CONST_externallyStoredData218, CONST_externallyStoredDataB1009)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_SELL_DRUGS, Data_Activity('c', true, CONST_externallyStoredData219, CONST_externallyStoredDataB1010)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_PROSTITUTION, Data_Activity('c', true, CONST_externallyStoredData220)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_CCFRAUD, Data_Activity('c', true, CONST_externallyStoredData221)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_DOS_RACKET, Data_Activity('c', true, CONST_externallyStoredData222, CONST_externallyStoredDataB1011)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_RECRUITING, Data_Activity('d', true, CONST_externallyStoredData223)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STEALCARS, Data_Activity('d', true, CONST_externallyStoredData224)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_MAKE_ARMOR, Data_Activity('d', true, CONST_externallyStoredData225)), // did not have any strings listed
		 map<Activity, Data_Activity>::value_type(ACTIVITY_REPAIR_ARMOR, Data_Activity('d', true, CONST_externallyStoredData226)), // did not have any strings listed
		 map<Activity, Data_Activity>::value_type(ACTIVITY_WHEELCHAIR, Data_Activity('d', true, CONST_externallyStoredData227)), // did not have any strings listed
		 map<Activity, Data_Activity>::value_type(ACTIVITY_AUGMENT, Data_Activity('d', true, CONST_externallyStoredData228, CONST_externallyStoredDataB1012)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_HEAL, Data_Activity('h', true, CONST_externallyStoredData229)), // did not have any strings listed
		 map<Activity, Data_Activity>::value_type(ACTIVITY_HOSTAGETENDING, Data_Activity('i', true, CONST_externallyStoredData230)), // did not have any strings listed
		 map<Activity, Data_Activity>::value_type(ACTIVITY_CLINIC, Data_Activity('m', true, CONST_externallyStoredData231)), // did not have any strings listed
		 map<Activity, Data_Activity>::value_type(ACTIVITY_BURY, Data_Activity('z', true, CONST_externallyStoredData232)), // did not have any strings listed
		 map<Activity, Data_Activity>::value_type(ACTIVITY_TEACH_POLITICS, Data_Activity('t', false, CONST_externallyStoredData233, CONST_externallyStoredDataB1013, CONST_externallyStoredDataC1081)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_TEACH_COVERT, Data_Activity('t', false, CONST_externallyStoredData234, CONST_externallyStoredDataB1014, CONST_externallyStoredDataC1082)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_TEACH_FIGHTING, Data_Activity('t', false, CONST_externallyStoredData235, blankString, CONST_externallyStoredDataB1015)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_DEBATING, Data_Activity('l', true, study_string1, study_string2)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_MARTIAL_ARTS, Data_Activity('l', true, study_string1, study_string2)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_DRIVING, Data_Activity('l', true, study_string1, study_string2)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_PSYCHOLOGY, Data_Activity('l', true, study_string1, study_string2)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_FIRST_AID, Data_Activity('l', true, study_string1, study_string2)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_LAW, Data_Activity('l', true, study_string1, study_string2)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_DISGUISE, Data_Activity('l', true, study_string1, study_string2)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_SCIENCE, Data_Activity('l', true, study_string1, study_string2)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_BUSINESS, Data_Activity('l', true, study_string1, study_string2)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_GYMNASTICS, Data_Activity('l', true, study_string1, study_string2)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_WRITING, Data_Activity('l', true, study_string1, study_string2)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_ART, Data_Activity('l', true, study_string1, study_string2)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_MUSIC, Data_Activity('l', true, study_string1, study_string2)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_TEACHING, Data_Activity('l', true, study_string1, study_string2)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_LOCKSMITHING, Data_Activity('l', true, study_string1, study_string2)),
		 map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_COMPUTERS, Data_Activity('l', true, study_string1, study_string2)),
		 //  map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_COOKING, Data_Activity'l', true,study_string1, study_string2)),
		  map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_FENCING, Data_Activity('l', true, study_string1, study_string2)),
		  map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_WEAVING, Data_Activity('l', true, study_string1, study_string2)),
		  map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_RELIGION, Data_Activity('l', true, study_string1, study_string2)),
		  //  map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_MAGIC, Data_Activity'l', true,study_string1, study_string2)),
		   map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_CLUB, Data_Activity('l', true, study_string1, study_string2)),
		   map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_STREETSENSE, Data_Activity('l', true, study_string1, study_string2)),
		   map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_THROWING, Data_Activity('l', true, study_string1, study_string2)),
		   map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_STEALTH, Data_Activity('l', true, study_string1, study_string2)),
		   map<Activity, Data_Activity>::value_type(ACTIVITY_STUDY_SEDUCTION, Data_Activity('l', true, study_string1, study_string2)),
		   map<Activity, Data_Activity>::value_type(ACTIVITY_NONE, Data_Activity('x', false, blankString))
	};
	pollingData = {
		map< Views, stringConnectedToView >::value_type(VIEW_GAY,  stringConnectedToView(CONST_externallyStoredData236, CONST_externallyStoredDataB1016)),
		map< Views, stringConnectedToView >::value_type(VIEW_DEATHPENALTY, stringConnectedToView(CONST_externallyStoredData237, CONST_externallyStoredDataB1017, CONST_externallyStoredDataC1083)),
		map< Views, stringConnectedToView >::value_type(VIEW_TAXES, stringConnectedToView(CONST_externallyStoredData238, CONST_externallyStoredDataB1018)),
		map< Views, stringConnectedToView >::value_type(VIEW_NUCLEARPOWER, stringConnectedToView(CONST_externallyStoredData239, CONST_externallyStoredDataB1019, CONST_externallyStoredDataC1084)),
		map< Views, stringConnectedToView >::value_type(VIEW_ANIMALRESEARCH, stringConnectedToView(CONST_externallyStoredData240,CONST_externallyStoredDataB1020)),
		map< Views, stringConnectedToView >::value_type(VIEW_POLICEBEHAVIOR, stringConnectedToView(CONST_externallyStoredData241,CONST_externallyStoredDataB1021)),
		map< Views, stringConnectedToView >::value_type(VIEW_INTELLIGENCE, stringConnectedToView(CONST_externallyStoredData242,CONST_externallyStoredDataB1022)),
		map< Views, stringConnectedToView >::value_type(VIEW_FREESPEECH, stringConnectedToView(CONST_externallyStoredData243,CONST_externallyStoredDataB1023)),
		map< Views, stringConnectedToView >::value_type(VIEW_GENETICS, stringConnectedToView(CONST_externallyStoredData244,CONST_externallyStoredDataB1024)),
		map< Views, stringConnectedToView >::value_type(VIEW_JUSTICES, stringConnectedToView(CONST_externallyStoredData245,CONST_externallyStoredDataB1025)),
		map< Views, stringConnectedToView >::value_type(VIEW_SWEATSHOPS, stringConnectedToView(CONST_externallyStoredData246,CONST_externallyStoredDataB1026)),
		map< Views, stringConnectedToView >::value_type(VIEW_POLLUTION, stringConnectedToView(CONST_externallyStoredData247,CONST_externallyStoredDataB1027)),
		map< Views, stringConnectedToView >::value_type(VIEW_CORPORATECULTURE, stringConnectedToView(CONST_externallyStoredData248,CONST_externallyStoredDataB1028)),
		map< Views, stringConnectedToView >::value_type(VIEW_CEOSALARY, stringConnectedToView(CONST_externallyStoredData249,CONST_externallyStoredDataB1029)),
		map< Views, stringConnectedToView >::value_type(VIEW_PRISONS, stringConnectedToView(CONST_externallyStoredData250,CONST_externallyStoredDataB1030)),
		map< Views, stringConnectedToView >::value_type(VIEW_IMMIGRATION, stringConnectedToView(CONST_externallyStoredData251, CONST_externallyStoredDataB1031, CONST_externallyStoredDataC1085, CONST_externallyStoredDataC1085)),
		map< Views, stringConnectedToView >::value_type(VIEW_DRUGS, stringConnectedToView(CONST_externallyStoredData252,CONST_externallyStoredDataB1032)),
		map< Views, stringConnectedToView >::value_type(VIEW_WOMEN, stringConnectedToView(CONST_externallyStoredData253,CONST_externallyStoredDataB1033)),
		map< Views, stringConnectedToView >::value_type(VIEW_CIVILRIGHTS, stringConnectedToView(CONST_externallyStoredData254,CONST_externallyStoredDataB1034)),
		map< Views, stringConnectedToView >::value_type(VIEW_GUNCONTROL, stringConnectedToView(CONST_externallyStoredData255,CONST_externallyStoredDataB1035)),
		map< Views, stringConnectedToView >::value_type(VIEW_MILITARY, stringConnectedToView(CONST_externallyStoredData256,CONST_externallyStoredDataB1036)),
		map< Views, stringConnectedToView >::value_type(VIEW_CONSERVATIVECRIMESQUAD, stringConnectedToView(CONST_externallyStoredData257,CONST_externallyStoredDataB1037)),
		map< Views, stringConnectedToView >::value_type(VIEW_TORTURE, stringConnectedToView(CONST_externallyStoredData258,CONST_externallyStoredDataB1038))
	};
	trainingActivity = {
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_DEBATING,SKILL_PERSUASION),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_MARTIAL_ARTS, SKILL_HANDTOHAND),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_DRIVING, SKILL_DRIVING),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_PSYCHOLOGY, SKILL_PSYCHOLOGY),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_FIRST_AID, SKILL_FIRSTAID),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_LAW, SKILL_LAW),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_DISGUISE, SKILL_DISGUISE),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_SCIENCE, SKILL_SCIENCE),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_BUSINESS, SKILL_BUSINESS),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_GYMNASTICS, SKILL_DODGE),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_LOCKSMITHING, SKILL_SECURITY),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_MUSIC, SKILL_MUSIC),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_ART, SKILL_ART),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_TEACHING, SKILL_TEACHING),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_WRITING, SKILL_WRITING),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_COMPUTERS, SKILL_COMPUTERS),
		//map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_COOKING,SKILL_COOKING),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_FENCING, SKILL_SWORD),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_WEAVING, SKILL_TAILORING),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_RELIGION, SKILL_RELIGION),
		//map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_MAGIC,SKILL_MAGIC),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_CLUB, SKILL_CLUB),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_STREETSENSE, SKILL_STREETSENSE),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_THROWING, SKILL_THROWING),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_STEALTH, SKILL_STEALTH),
		map< Activity, CreatureSkill>::value_type(ACTIVITY_STUDY_SEDUCTION, SKILL_SEDUCTION)
	};
	// This is the lesson data for the University.
	data_lessons = {
	   ActivityAndString(ACTIVITY_STUDY_DEBATING,	CONST_externallyStoredData259),
	   ActivityAndString(ACTIVITY_STUDY_BUSINESS,	CONST_externallyStoredData260),
	   ActivityAndString(ACTIVITY_STUDY_PSYCHOLOGY,	CONST_externallyStoredData1107),
	   ActivityAndString(ACTIVITY_STUDY_LAW,	CONST_externallyStoredData262),
	   ActivityAndString(ACTIVITY_STUDY_SCIENCE,	CONST_externallyStoredData263),
	   ActivityAndString(ACTIVITY_STUDY_DRIVING,	CONST_externallyStoredData264),
	   ActivityAndString(ACTIVITY_STUDY_FIRST_AID,	CONST_externallyStoredData1124),
	   ActivityAndString(ACTIVITY_STUDY_ART,	CONST_externallyStoredData266),
	   ActivityAndString(ACTIVITY_STUDY_DISGUISE,	CONST_externallyStoredData267),
	   ActivityAndString(ACTIVITY_STUDY_MARTIAL_ARTS,CONST_externallyStoredData268),
	   ActivityAndString(ACTIVITY_STUDY_GYMNASTICS,	CONST_externallyStoredData269),
	   ActivityAndString(ACTIVITY_STUDY_WRITING,	CONST_externallyStoredData1114),
	   ActivityAndString(ACTIVITY_STUDY_TEACHING,	CONST_externallyStoredData271),
	   ActivityAndString(ACTIVITY_STUDY_MUSIC,	CONST_externallyStoredData1115),
	   ActivityAndString(ACTIVITY_STUDY_LOCKSMITHING,CONST_externallyStoredData273),
	   // Terra Vitae
	   ActivityAndString(ACTIVITY_STUDY_COMPUTERS, CONST_externallyStoredData274),
	   ActivityAndString(ACTIVITY_STUDY_FENCING, CONST_externallyStoredData275),
	   ActivityAndString(ACTIVITY_STUDY_WEAVING, CONST_externallyStoredData276),
	   ActivityAndString(ACTIVITY_STUDY_RELIGION, CONST_externallyStoredData1117),
	   //, ActivityAndString(ACTIVITY_STUDY_MAGIC, CONST_externallyStoredData278)
	   // new for 4.12.6
	   ActivityAndString(ACTIVITY_STUDY_CLUB,	CONST_externallyStoredData279),
	   ActivityAndString(ACTIVITY_STUDY_STREETSENSE,	CONST_externallyStoredData280),
	   ActivityAndString(ACTIVITY_STUDY_THROWING,	CONST_externallyStoredData281),
	   ActivityAndString(ACTIVITY_STUDY_STEALTH,	CONST_externallyStoredData1120),
	   ActivityAndString(ACTIVITY_STUDY_SEDUCTION,CONST_externallyStoredData283)
	};
	hackingActivities = {
	   activityData(CONST_externallyStoredData284.c_str(), DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_IMMIGRATION,2,0,75), ChangeOfOpinion(VIEW_FREESPEECH,2,0,75) }), vector<string>({})),
	   //Scambaiting, except you're baiting a CEO
	   activityData(CONST_externallyStoredData285.c_str(), DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_CEOSALARY,2,0,75),	ChangeOfOpinion(VIEW_TAXES,2,0,75) }), vector<string>({})),
	   activityData(CONST_externallyStoredData286.c_str(), DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_POLICEBEHAVIOR,2,0,75),	ChangeOfOpinion(VIEW_CIVILRIGHTS,2,0,75) }), vector<string>({})),
	   // *JDS* Penetrated government networks; don't get any loot, but do scare the info community
	   activityData(CONST_externallyStoredData287.c_str(), DIFFICULTY_IMPOSSIBLE, 25, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_INTELLIGENCE,10,0,75) }), vector<string>({})),
	   activityData(CONST_externallyStoredData288.c_str(), DIFFICULTY_IMPOSSIBLE, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_LIBERALCRIMESQUAD,5,0,75) }), vector<string>({})),
	   activityData(CONST_externallyStoredData289.c_str(), DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_GAY,2,0,75),	ChangeOfOpinion(VIEW_WOMEN,2,0,75) }), vector<string>({})),
	   activityData(CONST_externallyStoredData290.c_str(), DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({ ChangeOfOpinion(VIEW_GENETICS,2,0,75) }), vector<string>({})),
	   activityData(CONST_externallyStoredData291.c_str(), DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({}), vector<string>({ tag_LOOT_JUDGEFILES })),
	   activityData(CONST_externallyStoredData292.c_str(), DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({}), vector<string>({ tag_LOOT_RESEARCHFILES })),
	   activityData(CONST_externallyStoredData293.c_str(), DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({}), vector<string>({ tag_LOOT_CORPFILES })),
	   activityData(CONST_externallyStoredData294.c_str(), DIFFICULTY_SUPERHEROIC, 10, LAWFLAG_INFORMATION, vector<ChangeOfOpinion>({}), vector<string>({ tag_LOOT_CABLENEWSFILES,tag_LOOT_AMRADIOFILES }))
	};
	activate_menu_items =
	{
		map<char, vector<ActivityAndString> >::value_type('a',vector<ActivityAndString>({ ActivityAndString(1, ACTIVITY_COMMUNITYSERVICE, CONST_externallyStoredData295),
		ActivityAndString(2, ACTIVITY_TROUBLE,	CONST_externallyStoredData296),
			ActivityAndString(3, ACTIVITY_GRAFFITI,	CONST_externallyStoredData297),
			ActivityAndString(4, ACTIVITY_POLLS,	CONST_externallyStoredData298),
			//ActivityAndString(ACTIVITY_DOS_ATTACKS, CONST_externallyStoredData299),
			ActivityAndString(5, ACTIVITY_HACKING,	CONST_externallyStoredData702),
			ActivityAndString(6, ACTIVITY_WRITE_LETTERS,	CONST_externallyStoredData301),
			ActivityAndString(7, ACTIVITY_WRITE_GUARDIAN,	CONST_externallyStoredData302, ACTIVITIY_MENU_CHECK_PRESS) })), // 
		map<char, vector<ActivityAndString> >::value_type('b',vector<ActivityAndString>({ ActivityAndString(1, ACTIVITY_DONATIONS,	CONST_externallyStoredData303),
			ActivityAndString(2, ACTIVITY_SELL_TSHIRTS,	CONST_externallyStoredData304, CONST_externallyStoredDataB1039, CONST_externallyStoredDataC1086, SKILL_TAILORING),
			ActivityAndString(3, ACTIVITY_SELL_ART,	CONST_externallyStoredData305, CONST_externallyStoredDataB1040, CONST_externallyStoredDataC1087, SKILL_ART),
			ActivityAndString(4, ACTIVITY_SELL_MUSIC,	CONST_externallyStoredData306, CONST_externallyStoredData306, CONST_externallyStoredDataB1041, SKILL_MUSIC) })),
		map<char, vector<ActivityAndString> >::value_type('c',vector<ActivityAndString>({ ActivityAndString(1, ACTIVITY_SELL_DRUGS,	CONST_externallyStoredData307),
			ActivityAndString(2, ACTIVITY_PROSTITUTION,	CONST_externallyStoredData698, ACTIVITIY_MENU_CHECK_AGE),
			//	ActivityAndString(ACTIVITY_DOS_RACKET, CONST_externallyStoredData309),
			ActivityAndString(3, ACTIVITY_CCFRAUD,	CONST_externallyStoredData310) })),
		map<char, vector<ActivityAndString> >::value_type('d',vector<ActivityAndString>({ ActivityAndString(1, ACTIVITY_RECRUITING,	CONST_externallyStoredData566),
			ActivityAndString(2, ACTIVITY_MAKE_ARMOR,	CONST_externallyStoredData312),
			ActivityAndString(3, ACTIVITY_REPAIR_ARMOR,	CONST_externallyStoredData313),
			ActivityAndString(4, ACTIVITY_STEALCARS,	CONST_externallyStoredData314, ACTIVITIY_MENU_CHECK_CAN_WALK),
			ActivityAndString(5, ACTIVITY_WHEELCHAIR,	CONST_externallyStoredData315, ACTIVITIY_MENU_CHECK_WHEELCHAIR),
			ActivityAndString(6, ACTIVITY_AUGMENT, CONST_externallyStoredData316, ACTIVITIY_MENU_CHECK_CAN_AUGMENT) })),
		map<char, vector<ActivityAndString> >::value_type('t',vector<ActivityAndString>({ ActivityAndString(0,  ACTIVITY_NONE,	CONST_externallyStoredData317),
			ActivityAndString(1, ACTIVITY_TEACH_POLITICS,	CONST_externallyStoredData318),
			ActivityAndString(2, ACTIVITY_TEACH_COVERT,	CONST_externallyStoredData319),
			ActivityAndString(3, ACTIVITY_TEACH_FIGHTING,	CONST_externallyStoredData320) }))
	};
	recruitable_creatures = {
	   RecruitData(CREATURE_VETERAN, CONST_externallyStoredData321, 4),
	   RecruitData(CREATURE_ATHLETE, CONST_externallyStoredData322, 4),
	   RecruitData(CREATURE_COLLEGESTUDENT, CONST_externallyStoredData323, 1),
	   RecruitData(CREATURE_PROGRAMMER, CONST_externallyStoredData324, 4),
	   RecruitData(CREATURE_DANCER, CONST_externallyStoredData325, 4),
	   RecruitData(CREATURE_DOCTOR, CONST_externallyStoredData326, 4),
	   RecruitData(CREATURE_FASHIONDESIGNER, CONST_externallyStoredData327, 6),
	   RecruitData(CREATURE_GANGMEMBER, CONST_externallyStoredData328, 2),
	   RecruitData(CREATURE_HIPPIE, CONST_externallyStoredData329, 1),
	   RecruitData(CREATURE_JOURNALIST, CONST_externallyStoredData330, 4),
	   RecruitData(CREATURE_JUDGE_LIBERAL, CONST_externallyStoredData331, 6),
	   RecruitData(CREATURE_LAWYER, CONST_externallyStoredData332.c_str(), 4),
	   RecruitData(CREATURE_LOCKSMITH, CONST_externallyStoredData333.c_str(), 6),
	   RecruitData(CREATURE_MARTIALARTIST, CONST_externallyStoredData334.c_str(), 4),
	   RecruitData(CREATURE_MUSICIAN, CONST_externallyStoredData335.c_str(), 4),
	   RecruitData(CREATURE_MUTANT, CONST_externallyStoredData336.c_str(), 4),
	   RecruitData(CREATURE_PROSTITUTE, CONST_externallyStoredData337.c_str(), 2),
	   RecruitData(CREATURE_PSYCHOLOGIST, CONST_externallyStoredData338.c_str(), 4),
	   RecruitData(CREATURE_TAXIDRIVER, CONST_externallyStoredData339.c_str(), 4),
	   RecruitData(CREATURE_TEACHER, CONST_externallyStoredData340.c_str(), 4)
	};
	trainingActivitySorting = {
		map<short, string>::value_type(SORTINGCHOICE_LIBERALS, CONST_externallyStoredData341),
		map<short, string>::value_type(SORTINGCHOICE_HOSTAGES, CONST_externallyStoredData342),
		map<short, string>::value_type(SORTINGCHOICE_CLINIC, CONST_externallyStoredData343),
		map<short, string>::value_type(SORTINGCHOICE_JUSTICE, CONST_externallyStoredData344),
		map<short, string>::value_type(SORTINGCHOICE_SLEEPERS, CONST_externallyStoredData345),
		map<short, string>::value_type(SORTINGCHOICE_DEAD, CONST_externallyStoredData346),
		map<short, string>::value_type(SORTINGCHOICE_AWAY, CONST_externallyStoredData347),
		map<short, string>::value_type(SORTINGCHOICE_ACTIVATE, CONST_externallyStoredData348),
		map<short, string>::value_type(SORTINGCHOICE_ACTIVATESLEEPERS, CONST_externallyStoredData349),
		map<short, string>::value_type(SORTINGCHOICE_ASSEMBLESQUAD, CONST_externallyStoredData350),
		map<short, string>::value_type(SORTINGCHOICE_BASEASSIGN, CONST_externallyStoredData351),
		map<short, string>::value_type(SORTINGCHOICENUM,CONST_externallyStoredData352)
	};
	incomeTypes = {
		map<short, string>::value_type(INCOME_BROWNIES,CONST_externallyStoredData353),
		map<short, string>::value_type(INCOME_CARS,CONST_externallyStoredData354),
		map<short, string>::value_type(INCOME_CCFRAUD,CONST_externallyStoredData575),
		map<short, string>::value_type(INCOME_DONATIONS,CONST_externallyStoredData356),
		map<short, string>::value_type(INCOME_SKETCHES,CONST_externallyStoredData357),
		map<short, string>::value_type(INCOME_EMBEZZLEMENT,CONST_externallyStoredData358),
		map<short, string>::value_type(INCOME_EXTORTION,CONST_externallyStoredData692),
		map<short, string>::value_type(INCOME_HUSTLING,CONST_externallyStoredData360),
		map<short, string>::value_type(INCOME_PAWN,CONST_externallyStoredData361),
		map<short, string>::value_type(INCOME_PROSTITUTION,CONST_externallyStoredData698),
		map<short, string>::value_type(INCOME_BUSKING,CONST_externallyStoredData363),
		map<short, string>::value_type(INCOME_THIEVERY,CONST_externallyStoredData364),
		map<short, string>::value_type(INCOME_TSHIRTS,CONST_externallyStoredData365),
		map<short, string>::value_type(INCOMETYPENUM,CONST_externallyStoredData366)
	};
	expenseTypes = {
		map<short, string>::value_type(EXPENSE_TROUBLEMAKING, CONST_externallyStoredData367),
		map<short, string>::value_type(EXPENSE_CONFISCATED, CONST_externallyStoredData368),
		map<short, string>::value_type(EXPENSE_DATING, CONST_externallyStoredData369),
		map<short, string>::value_type(EXPENSE_SKETCHES, CONST_externallyStoredData370),
		map<short, string>::value_type(EXPENSE_FOOD, CONST_externallyStoredData371),
		map<short, string>::value_type(EXPENSE_HOSTAGE, CONST_externallyStoredData372),
		map<short, string>::value_type(EXPENSE_LEGAL, CONST_externallyStoredData373),
		map<short, string>::value_type(EXPENSE_MANUFACTURE, CONST_externallyStoredData374),
		map<short, string>::value_type(EXPENSE_CARS, CONST_externallyStoredData375),
		map<short, string>::value_type(EXPENSE_SHOPPING, CONST_externallyStoredData376),
		map<short, string>::value_type(EXPENSE_RECRUITMENT, CONST_externallyStoredData377),
		map<short, string>::value_type(EXPENSE_RENT, CONST_externallyStoredData378),
		map<short, string>::value_type(EXPENSE_COMPOUND, CONST_externallyStoredData379),
		map<short, string>::value_type(EXPENSE_TRAINING, CONST_externallyStoredData380),
		map<short, string>::value_type(EXPENSE_TRAVEL, tag_Travel),
		map<short, string>::value_type(EXPENSE_TSHIRTS, CONST_externallyStoredData381),
		map<short, string>::value_type(EXPENSETYPENUM, CONST_externallyStoredData382)
	};
	siteReadMap = {
		map<short, string>::value_type(SITE_RESIDENTIAL_TENEMENT, CONST_externallyStoredData383),
		map<short, string>::value_type(SITE_RESIDENTIAL_APARTMENT, CONST_externallyStoredData384),
		map<short, string>::value_type(SITE_RESIDENTIAL_APARTMENT_UPSCALE, CONST_externallyStoredData385),
		map<short, string>::value_type(SITE_INDUSTRY_WAREHOUSE, CONST_externallyStoredData386),
		map<short, string>::value_type(SITE_RESIDENTIAL_SHELTER, CONST_externallyStoredData387),
		map<short, string>::value_type(SITE_BUSINESS_CRACKHOUSE, CONST_externallyStoredData388),
		map<short, string>::value_type(SITE_BUSINESS_BARANDGRILL, CONST_externallyStoredData389),
		map<short, string>::value_type(SITE_RESIDENTIAL_BOMBSHELTER, CONST_externallyStoredData390),
		map<short, string>::value_type(SITE_OUTDOOR_BUNKER, CONST_externallyStoredData391),
		map<short, string>::value_type(SITE_LABORATORY_COSMETICS, CONST_externallyStoredData392),
		map<short, string>::value_type(SITE_LABORATORY_GENETIC, CONST_externallyStoredData393),
		map<short, string>::value_type(SITE_GOVERNMENT_POLICESTATION, CONST_externallyStoredData394),
		map<short, string>::value_type(SITE_GOVERNMENT_COURTHOUSE, CONST_externallyStoredData395),
		map<short, string>::value_type(SITE_GOVERNMENT_PRISON, CONST_externallyStoredData396),
		map<short, string>::value_type(SITE_GOVERNMENT_INTELLIGENCEHQ, CONST_externallyStoredData397),
		map<short, string>::value_type(SITE_GOVERNMENT_ARMYBASE, CONST_externallyStoredData398),
		map<short, string>::value_type(SITE_GOVERNMENT_FIRESTATION, CONST_externallyStoredData399),
		map<short, string>::value_type(SITE_INDUSTRY_SWEATSHOP, CONST_externallyStoredData400),
		map<short, string>::value_type(SITE_INDUSTRY_POLLUTER, CONST_externallyStoredData401),
		map<short, string>::value_type(SITE_CORPORATE_HEADQUARTERS, CONST_externallyStoredData402),
		map<short, string>::value_type(SITE_CORPORATE_HOUSE, CONST_externallyStoredData403),
		map<short, string>::value_type(SITE_MEDIA_AMRADIO, CONST_externallyStoredData404),
		map<short, string>::value_type(SITE_MEDIA_CABLENEWS, CONST_externallyStoredData405),
		map<short, string>::value_type(SITE_BUSINESS_JUICEBAR, CONST_externallyStoredData406),
		map<short, string>::value_type(SITE_BUSINESS_INTERNETCAFE, CONST_externallyStoredData407),
		map<short, string>::value_type(SITE_BUSINESS_CIGARBAR, CONST_externallyStoredData408),
		map<short, string>::value_type(SITE_BUSINESS_LATTESTAND, CONST_externallyStoredData409),
		map<short, string>::value_type(SITE_BUSINESS_VEGANCOOP, CONST_externallyStoredData410),
		map<short, string>::value_type(SITE_OUTDOOR_PUBLICPARK, CONST_externallyStoredData411),
		map<short, string>::value_type(SITE_BUSINESS_BANK, CONST_externallyStoredData412),
		map<short, string>::value_type(SITE_INDUSTRY_NUCLEAR, CONST_externallyStoredData413),
		map<short, string>::value_type(SITE_GOVERNMENT_WHITE_HOUSE, CONST_externallyStoredData414)
	};
	buildThisSite = {
		map<short, string>::value_type(SITE_RESIDENTIAL_TENEMENT,CONST_externallyStoredData417),
		map<short, string>::value_type(SITE_RESIDENTIAL_APARTMENT,CONST_externallyStoredData417),
		map<short, string>::value_type(SITE_RESIDENTIAL_APARTMENT_UPSCALE,CONST_externallyStoredData417),
		map<short, string>::value_type(SITE_INDUSTRY_WAREHOUSE,CONST_externallyStoredData420),
		map<short, string>::value_type(SITE_RESIDENTIAL_SHELTER,CONST_externallyStoredData420),
		map<short, string>::value_type(SITE_BUSINESS_CRACKHOUSE,CONST_externallyStoredData420),
		map<short, string>::value_type(SITE_BUSINESS_BANK,CONST_externallyStoredData425),
		map<short, string>::value_type(SITE_BUSINESS_BARANDGRILL,CONST_externallyStoredData425),
		map<short, string>::value_type(SITE_RESIDENTIAL_BOMBSHELTER,CONST_externallyStoredData425),
		map<short, string>::value_type(SITE_OUTDOOR_BUNKER,CONST_externallyStoredData425),
		map<short, string>::value_type(SITE_GOVERNMENT_FIRESTATION,CONST_externallyStoredData425),
		map<short, string>::value_type(SITE_LABORATORY_COSMETICS,CONST_externallyStoredData426),
		map<short, string>::value_type(SITE_LABORATORY_GENETIC,CONST_externallyStoredData427),
		map<short, string>::value_type(SITE_GOVERNMENT_POLICESTATION,CONST_externallyStoredData428),
		map<short, string>::value_type(SITE_GOVERNMENT_COURTHOUSE,CONST_externallyStoredData429),
		map<short, string>::value_type(SITE_GOVERNMENT_PRISON,CONST_externallyStoredData430),
		map<short, string>::value_type(SITE_GOVERNMENT_INTELLIGENCEHQ,CONST_externallyStoredData431),
		map<short, string>::value_type(SITE_GOVERNMENT_WHITE_HOUSE,CONST_externallyStoredData432),
		map<short, string>::value_type(SITE_GOVERNMENT_ARMYBASE,CONST_externallyStoredData433),
		map<short, string>::value_type(SITE_INDUSTRY_SWEATSHOP,CONST_externallyStoredData434),
		map<short, string>::value_type(SITE_INDUSTRY_POLLUTER,CONST_externallyStoredData435),
		map<short, string>::value_type(SITE_INDUSTRY_NUCLEAR,CONST_externallyStoredData436),
		map<short, string>::value_type(SITE_CORPORATE_HEADQUARTERS,CONST_externallyStoredData437),
		map<short, string>::value_type(SITE_CORPORATE_HOUSE,CONST_externallyStoredData438),
		map<short, string>::value_type(SITE_MEDIA_AMRADIO,CONST_externallyStoredData439),
		map<short, string>::value_type(SITE_MEDIA_CABLENEWS,CONST_externallyStoredData440),
		map<short, string>::value_type(SITE_BUSINESS_JUICEBAR,CONST_externallyStoredData441),
		map<short, string>::value_type(SITE_BUSINESS_INTERNETCAFE,CONST_externallyStoredData442),
		map<short, string>::value_type(SITE_BUSINESS_CIGARBAR,CONST_externallyStoredData443),
		map<short, string>::value_type(SITE_BUSINESS_LATTESTAND,CONST_externallyStoredData444),
		map<short, string>::value_type(SITE_BUSINESS_VEGANCOOP,CONST_externallyStoredData445),
		map<short, string>::value_type(SITE_OUTDOOR_PUBLICPARK,CONST_externallyStoredData446),
	};
	getSpecial = {
		map<string, short>::value_type(CONST_externallyStoredData475, SPECIAL_LAB_COSMETICS_CAGEDANIMALS),
		map<string, short>::value_type(CONST_externallyStoredData476, SPECIAL_LAB_GENETIC_CAGEDANIMALS),
		map<string, short>::value_type(CONST_externallyStoredData477, SPECIAL_POLICESTATION_LOCKUP),
		map<string, short>::value_type(CONST_externallyStoredData478, SPECIAL_COURTHOUSE_LOCKUP),
		map<string, short>::value_type(CONST_externallyStoredData479, SPECIAL_COURTHOUSE_JURYROOM),
		map<string, short>::value_type(CONST_externallyStoredData480, SPECIAL_PRISON_CONTROL),
		map<string, short>::value_type(CONST_externallyStoredData481, SPECIAL_PRISON_CONTROL_LOW),
		map<string, short>::value_type(CONST_externallyStoredData482, SPECIAL_PRISON_CONTROL_MEDIUM),
		map<string, short>::value_type(CONST_externallyStoredData483, SPECIAL_PRISON_CONTROL_HIGH),
		map<string, short>::value_type(CONST_externallyStoredData484, SPECIAL_INTEL_SUPERCOMPUTER),
		map<string, short>::value_type(CONST_externallyStoredData485, SPECIAL_SWEATSHOP_EQUIPMENT),
		map<string, short>::value_type(CONST_externallyStoredData486, SPECIAL_POLLUTER_EQUIPMENT),
		map<string, short>::value_type(CONST_externallyStoredData487, SPECIAL_NUCLEAR_ONOFF),
		map<string, short>::value_type(CONST_externallyStoredData488, SPECIAL_HOUSE_PHOTOS),
		map<string, short>::value_type(CONST_externallyStoredData489, SPECIAL_ARMORY),
		map<string, short>::value_type(CONST_externallyStoredData490, SPECIAL_HOUSE_CEO),
		map<string, short>::value_type(CONST_externallyStoredData491, SPECIAL_CORPORATE_FILES),
		map<string, short>::value_type(CONST_externallyStoredData492, SPECIAL_RADIO_BROADCASTSTUDIO),
		map<string, short>::value_type(CONST_externallyStoredData493, SPECIAL_NEWS_BROADCASTSTUDIO),
		map<string, short>::value_type(CONST_externallyStoredData494, SPECIAL_APARTMENT_LANDLORD),
		map<string, short>::value_type(CONST_externallyStoredData495, SPECIAL_SIGN_ONE),
		map<string, short>::value_type(CONST_externallyStoredData496, SPECIAL_RESTAURANT_TABLE),
		map<string, short>::value_type(CONST_externallyStoredData497, SPECIAL_CAFE_COMPUTER),
		map<string, short>::value_type(CONST_externallyStoredData498, SPECIAL_PARK_BENCH),
		map<string, short>::value_type(CONST_externallyStoredData499, SPECIAL_STAIRS_UP),
		map<string, short>::value_type(CONST_externallyStoredData500, SPECIAL_STAIRS_DOWN),
		map<string, short>::value_type(CONST_externallyStoredData501, SPECIAL_CLUB_BOUNCER),
		map<string, short>::value_type(CONST_externallyStoredData502, SPECIAL_CLUB_BOUNCER_SECONDVISIT)
	};
	getUnique = {
		map<string, short>::value_type(CONST_externallyStoredData475, SPECIAL_LAB_COSMETICS_CAGEDANIMALS),
		map<string, short>::value_type(CONST_externallyStoredData476, SPECIAL_LAB_GENETIC_CAGEDANIMALS),
		map<string, short>::value_type(CONST_externallyStoredData477, SPECIAL_POLICESTATION_LOCKUP),
		map<string, short>::value_type(CONST_externallyStoredData478, SPECIAL_COURTHOUSE_LOCKUP),
		map<string, short>::value_type(CONST_externallyStoredData479, SPECIAL_COURTHOUSE_JURYROOM),
		map<string, short>::value_type(CONST_externallyStoredData480, SPECIAL_PRISON_CONTROL),
		map<string, short>::value_type(CONST_externallyStoredData481, SPECIAL_PRISON_CONTROL_LOW),
		map<string, short>::value_type(CONST_externallyStoredData482, SPECIAL_PRISON_CONTROL_MEDIUM),
		map<string, short>::value_type(CONST_externallyStoredData483, SPECIAL_PRISON_CONTROL_HIGH),
		map<string, short>::value_type(CONST_externallyStoredData484, SPECIAL_INTEL_SUPERCOMPUTER),
		map<string, short>::value_type(CONST_externallyStoredData485, SPECIAL_SWEATSHOP_EQUIPMENT),
		map<string, short>::value_type(CONST_externallyStoredData486, SPECIAL_POLLUTER_EQUIPMENT),
		map<string, short>::value_type(CONST_externallyStoredData487, SPECIAL_NUCLEAR_ONOFF),
		map<string, short>::value_type(CONST_externallyStoredData488, SPECIAL_HOUSE_PHOTOS),
		map<string, short>::value_type(CONST_externallyStoredData489, SPECIAL_ARMORY),
		map<string, short>::value_type(CONST_externallyStoredData490, SPECIAL_HOUSE_CEO),
		map<string, short>::value_type(CONST_externallyStoredData491, SPECIAL_CORPORATE_FILES),
		map<string, short>::value_type(CONST_externallyStoredData492, SPECIAL_RADIO_BROADCASTSTUDIO),
		map<string, short>::value_type(CONST_externallyStoredData493, SPECIAL_NEWS_BROADCASTSTUDIO),
		map<string, short>::value_type(CONST_externallyStoredData494, SPECIAL_APARTMENT_LANDLORD),
		map<string, short>::value_type(CONST_externallyStoredData495, SPECIAL_SIGN_ONE),
		map<string, short>::value_type(CONST_externallyStoredData496, SPECIAL_RESTAURANT_TABLE),
		map<string, short>::value_type(CONST_externallyStoredData497, SPECIAL_CAFE_COMPUTER),
		map<string, short>::value_type(CONST_externallyStoredData498, SPECIAL_PARK_BENCH),
		map<string, short>::value_type(CONST_externallyStoredData499, SPECIAL_STAIRS_UP),
		map<string, short>::value_type(CONST_externallyStoredData500, SPECIAL_STAIRS_DOWN),
		map<string, short>::value_type(CONST_externallyStoredData501, SPECIAL_CLUB_BOUNCER),
		map<string, short>::value_type(CONST_externallyStoredData502, SPECIAL_CLUB_BOUNCER_SECONDVISIT)
	};
	getLootString = {
		map<string, string>::value_type(CONST_externallyStoredData503,tag_LOOT_FINECLOTH),
		map<string, string>::value_type(CONST_externallyStoredData504,tag_LOOT_CHEMICAL),
		map<string, string>::value_type(CONST_externallyStoredData505,tag_LOOT_PDA),
		map<string, string>::value_type(CONST_externallyStoredData506,tag_LOOT_LABEQUIPMENT),
		map<string, string>::value_type(CONST_externallyStoredData507,tag_LOOT_COMPUTER),
		map<string, string>::value_type(CONST_externallyStoredData508,tag_LOOT_CHEAPJEWELERY),
		map<string, string>::value_type(CONST_externallyStoredData509,tag_LOOT_SECRETDOCUMENTS),
		map<string, string>::value_type(CONST_externallyStoredData510,tag_LOOT_CEOPHOTOS),
		map<string, string>::value_type(CONST_externallyStoredData511,tag_LOOT_INTHQDISK),
		map<string, string>::value_type(CONST_externallyStoredData512,tag_LOOT_CORPFILES),
		map<string, string>::value_type(CONST_externallyStoredData513,tag_LOOT_JUDGEFILES),
		map<string, string>::value_type(CONST_externallyStoredData514,tag_LOOT_RESEARCHFILES),
		map<string, string>::value_type(CONST_externallyStoredData515,tag_LOOT_PRISONFILES),
		map<string, string>::value_type(CONST_externallyStoredData516,tag_LOOT_CABLENEWSFILES),
		map<string, string>::value_type(CONST_externallyStoredData517,tag_LOOT_AMRADIOFILES),
		map<string, string>::value_type(CONST_externallyStoredData518,tag_LOOT_POLICERECORDS),
		map<string, string>::value_type(CONST_externallyStoredData519,tag_LOOT_EXPENSIVEJEWELERY),
		map<string, string>::value_type(CONST_externallyStoredData520,tag_LOOT_CELLPHONE),
		map<string, string>::value_type(CONST_externallyStoredData521,tag_LOOT_MICROPHONE),
		map<string, string>::value_type(CONST_externallyStoredData522,tag_LOOT_WATCH),
		map<string, string>::value_type(CONST_externallyStoredData523,tag_LOOT_SILVERWARE),
		map<string, string>::value_type(CONST_externallyStoredData524,tag_LOOT_TRINKET)
	};
	reviewStrings = {
		map<short, string>::value_type(REVIEWMODE_LIBERALS, CONST_externallyStoredData525),
		map<short, string>::value_type(REVIEWMODE_HOSTAGES,	CONST_externallyStoredData526),
		map<short, string>::value_type(REVIEWMODE_CLINIC,	CONST_externallyStoredData527),
		map<short, string>::value_type(REVIEWMODE_JUSTICE,	CONST_externallyStoredData528),
		map<short, string>::value_type(REVIEWMODE_SLEEPERS,	CONST_externallyStoredData529),
		map<short, string>::value_type(REVIEWMODE_DEAD,	CONST_externallyStoredData530),
		map<short, string>::value_type(REVIEWMODE_AWAY,	CONST_externallyStoredData531)
	};
	reviewStringsSecondLine = {
		map<short, string>::value_type(REVIEWMODE_LIBERALS, CONST_externallyStoredData532),
		map<short, string>::value_type(REVIEWMODE_HOSTAGES,	CONST_externallyStoredData533),
		map<short, string>::value_type(REVIEWMODE_CLINIC,	CONST_externallyStoredData534),
		map<short, string>::value_type(REVIEWMODE_JUSTICE,	CONST_externallyStoredData535),
		map<short, string>::value_type(REVIEWMODE_SLEEPERS,	CONST_externallyStoredData536),
		map<short, string>::value_type(REVIEWMODE_DEAD,	CONST_externallyStoredData537),
		map<short, string>::value_type(REVIEWMODE_AWAY,	CONST_externallyStoredData538)
	};
	liberalListAndColor = {
	   stringAndColor(WHITE_ON_BLACK,	CONST_externallyStoredData539),
	   stringAndColor(MAGENTA_ON_BLACK,	CONST_externallyStoredData540),
	   stringAndColor(WHITE_ON_BLACK,	CONST_externallyStoredData541),
	   stringAndColor(YELLOW_ON_BLACK,	CONST_externallyStoredData542),
	   stringAndColor(YELLOW_ON_BLACK_BRIGHT,	CONST_externallyStoredData543),
	   stringAndColor(WHITE_ON_BLACK,	CONST_externallyStoredData544),
	   stringAndColor(YELLOW_ON_BLACK_BRIGHT,	CONST_externallyStoredData554),
	   stringAndColor(RED_ON_BLACK_BRIGHT,	CONST_externallyStoredData552),
	   stringAndColor(WHITE_ON_BLACK,	CONST_externallyStoredData547),
	   stringAndColor(RED_ON_BLACK_BRIGHT,	CONST_externallyStoredData554),
	   stringAndColor(BLACK_ON_BLACK_BRIGHT,	CONST_externallyStoredData552),
	   stringAndColor(WHITE_ON_BLACK,	CONST_externallyStoredData550),
	   stringAndColor(BLACK_ON_BLACK_BRIGHT,	CONST_externallyStoredData554),
	   stringAndColor(BLUE_ON_BLACK_BRIGHT,	CONST_externallyStoredData552),
	   stringAndColor(WHITE_ON_BLACK,	CONST_externallyStoredData553),
	   stringAndColor(BLUE_ON_BLACK_BRIGHT,	CONST_externallyStoredData554)
	};
	getCityDescription = {
		map<short, string>::value_type(SITE_CITY_SEATTLE, CONST_externallyStoredData555),
		map<short, string>::value_type(SITE_CITY_LOS_ANGELES, CONST_externallyStoredData556),
		map<short, string>::value_type(SITE_CITY_NEW_YORK, CONST_externallyStoredData557),
		map<short, string>::value_type(SITE_CITY_WASHINGTON_DC, CONST_externallyStoredData558),
		map<short, string>::value_type(SITE_CITY_CHICAGO, CONST_externallyStoredData559),
		map<short, string>::value_type(SITE_CITY_DETROIT, CONST_externallyStoredData560),
		map<short, string>::value_type(SITE_CITY_ATLANTA, CONST_externallyStoredData561),
		map<short, string>::value_type(SITE_CITY_MIAMI, CONST_externallyStoredData562)
	};
	getSiteName = {
		map<short, vector<string> >::value_type(SITE_CITY_SEATTLE,{ tag_Seattle, tag_SEA }),
		map<short, vector<string> >::value_type(SITE_CITY_LOS_ANGELES,{ CONST_externallyStoredData563, tag_LA }),
		map<short, vector<string> >::value_type(SITE_CITY_NEW_YORK,{ CONST_externallyStoredData564, tag_NYC }),
		map<short, vector<string> >::value_type(SITE_CITY_CHICAGO,{ tag_Chicago, tag_CHI }),
		map<short, vector<string> >::value_type(SITE_CITY_DETROIT,{ tag_Detroit, tag_DET }),
		map<short, vector<string> >::value_type(SITE_CITY_ATLANTA,{ tag_Atlanta, tag_ATL }),
		map<short, vector<string> >::value_type(SITE_CITY_MIAMI,{ tag_Miami, tag_MI }),
		map<short, vector<string> >::value_type(SITE_CITY_WASHINGTON_DC,{ CONST_externallyStoredData1082, tag_DC }),
		map<short, vector<string> >::value_type(SITE_DOWNTOWN,{ tag_Downtown, tag_Downtown }),
		map<short, vector<string> >::value_type(SITE_UDISTRICT,{ tag_University_District, tag_u_District }),
		map<short, vector<string> >::value_type(SITE_COMMERCIAL,{ tag_Shopping, tag_Shopping }),
		map<short, vector<string> >::value_type(SITE_INDUSTRIAL,{ tag_Industrial_District, tag_i_District }),
		map<short, vector<string> >::value_type(SITE_OUTOFTOWN,{ tag_City_Outskirts, tag_Outskirts }),
		map<short, vector<string> >::value_type(SITE_TRAVEL,{ tag_Travel, tag_Travel }),
	};
	getActivityString = {
		map<short, string>::value_type(ACTIVITY_RECRUITING,	CONST_externallyStoredData566),
		map<short, string>::value_type(ACTIVITY_REPAIR_ARMOR,	CONST_externallyStoredData567),
		map<short, string>::value_type(ACTIVITY_WHEELCHAIR,	CONST_externallyStoredData568),
		map<short, string>::value_type(ACTIVITY_STEALCARS,	CONST_externallyStoredData569),
		map<short, string>::value_type(ACTIVITY_POLLS,	CONST_externallyStoredData570),
		map<short, string>::value_type(ACTIVITY_TROUBLE,	CONST_externallyStoredData571),
		map<short, string>::value_type(ACTIVITY_PROSTITUTION,	CONST_externallyStoredData572),
		map<short, string>::value_type(ACTIVITY_COMMUNITYSERVICE,	CONST_externallyStoredData573),
		map<short, string>::value_type(ACTIVITY_GRAFFITI,	CONST_externallyStoredData574),
		map<short, string>::value_type(ACTIVITY_CCFRAUD,	CONST_externallyStoredData575),
		map<short, string>::value_type(ACTIVITY_DOS_RACKET,	CONST_externallyStoredData576),
		map<short, string>::value_type(ACTIVITY_DOS_ATTACKS,	CONST_externallyStoredData577),
		map<short, string>::value_type(ACTIVITY_HACKING,	CONST_externallyStoredData578),
		map<short, string>::value_type(ACTIVITY_SELL_TSHIRTS,	CONST_externallyStoredData579),
		map<short, string>::value_type(ACTIVITY_SELL_ART,	CONST_externallyStoredData580),
		map<short, string>::value_type(ACTIVITY_TEACH_POLITICS,	CONST_externallyStoredData581),
		map<short, string>::value_type(ACTIVITY_TEACH_FIGHTING,	CONST_externallyStoredData582),
		map<short, string>::value_type(ACTIVITY_TEACH_COVERT,	CONST_externallyStoredData583),
		map<short, string>::value_type(ACTIVITY_SELL_MUSIC,	CONST_externallyStoredData584),
		map<short, string>::value_type(ACTIVITY_BURY,	CONST_externallyStoredData585),
		map<short, string>::value_type(ACTIVITY_DONATIONS,	CONST_externallyStoredData586),
		map<short, string>::value_type(ACTIVITY_SELL_DRUGS,	CONST_externallyStoredData587),
		map<short, string>::value_type(ACTIVITY_HEAL,	CONST_externallyStoredData588),
		map<short, string>::value_type(ACTIVITY_NONE,	CONST_externallyStoredData589),
		map<short, string>::value_type(ACTIVITY_WRITE_LETTERS,	CONST_externallyStoredData590),
		map<short, string>::value_type(ACTIVITY_WRITE_GUARDIAN,	CONST_externallyStoredData591),
		map<short, string>::value_type(ACTIVITY_CLINIC,	CONST_externallyStoredData592),
		map<short, string>::value_type(ACTIVITY_STUDY_DEBATING,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_MARTIAL_ARTS,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_DRIVING,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_PSYCHOLOGY,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_FIRST_AID,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_LAW,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_DISGUISE,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_SCIENCE,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_BUSINESS,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_GYMNASTICS,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_ART,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_MUSIC,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_TEACHING,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_WRITING,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_LOCKSMITHING,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_COMPUTERS,	CONST_externallyStoredData618),
		//map<short, string>::value_type( ACTIVITY_STUDY_COOKING,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_FENCING,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_WEAVING,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_RELIGION,	CONST_externallyStoredData618),
		//map<short, string>::value_type(ACTIVITY_STUDY_MAGIC,	CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_CLUB,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_STREETSENSE,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_THROWING,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_STEALTH,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_STUDY_SEDUCTION,CONST_externallyStoredData618),
		map<short, string>::value_type(ACTIVITY_SLEEPER_LIBERAL,	CONST_externallyStoredData619),
		map<short, string>::value_type(ACTIVITY_SLEEPER_CONSERVATIVE,	CONST_externallyStoredData620),
		map<short, string>::value_type(ACTIVITY_SLEEPER_SPY,	CONST_externallyStoredData621),
		map<short, string>::value_type(ACTIVITY_SLEEPER_RECRUIT,	CONST_externallyStoredData622),
		map<short, string>::value_type(ACTIVITY_SLEEPER_JOINLCS,	CONST_externallyStoredData623),
		map<short, string>::value_type(ACTIVITY_SLEEPER_SCANDAL,	CONST_externallyStoredData624),
		map<short, string>::value_type(ACTIVITY_SLEEPER_EMBEZZLE,	CONST_externallyStoredData625),
		map<short, string>::value_type(ACTIVITY_SLEEPER_STEAL,	CONST_externallyStoredData626),
		map<short, string>::value_type(ACTIVITY_AUGMENT,	CONST_externallyStoredData627),
	};
	getViewString = {
		map<short, vector<string> >::value_type(VIEW_STALIN,{ CONST_externallyStoredData628, CONST_externallyStoredData628 }) ,
		map<short, vector<string> >::value_type(VIEW_MOOD,{ CONST_externallyStoredData629, CONST_externallyStoredDataB1042 }) ,
		map<short, vector<string> >::value_type(VIEW_GAY,{ CONST_externallyStoredData630, CONST_externallyStoredDataB1043 }) ,
		map<short, vector<string> >::value_type(VIEW_DEATHPENALTY,{ CONST_externallyStoredData631, CONST_externallyStoredDataB1044 }) ,
		map<short, vector<string> >::value_type(VIEW_TAXES,{ CONST_externallyStoredData632, CONST_externallyStoredDataB1045 }) ,
		map<short, vector<string> >::value_type(VIEW_NUCLEARPOWER,{ CONST_externallyStoredData633, CONST_externallyStoredDataB1046 }) ,
		map<short, vector<string> >::value_type(VIEW_ANIMALRESEARCH,{ CONST_externallyStoredData634, CONST_externallyStoredDataB1047 }) ,
		map<short, vector<string> >::value_type(VIEW_POLICEBEHAVIOR,{ CONST_externallyStoredData635, CONST_externallyStoredDataB1048 }) ,
		map<short, vector<string> >::value_type(VIEW_TORTURE,{ CONST_externallyStoredData636, CONST_externallyStoredDataB1049 }) ,
		map<short, vector<string> >::value_type(VIEW_PRISONS,{ CONST_externallyStoredData637, CONST_externallyStoredDataB1050 }) ,
		map<short, vector<string> >::value_type(VIEW_INTELLIGENCE,{ CONST_externallyStoredData638, CONST_externallyStoredData661 }) ,
		map<short, vector<string> >::value_type(VIEW_FREESPEECH,{ CONST_externallyStoredData639, CONST_externallyStoredDataB1075 }) ,
		map<short, vector<string> >::value_type(VIEW_GENETICS,{ CONST_externallyStoredData640, CONST_externallyStoredDataB1052 }) ,
		map<short, vector<string> >::value_type(VIEW_JUSTICES,{ CONST_externallyStoredData641, CONST_externallyStoredDataB1053 }) ,
		map<short, vector<string> >::value_type(VIEW_GUNCONTROL,{ CONST_externallyStoredData642, CONST_externallyStoredDataB1054 }) ,
		map<short, vector<string> >::value_type(VIEW_SWEATSHOPS,{ CONST_externallyStoredData643, CONST_externallyStoredDataB1072 }) ,
		map<short, vector<string> >::value_type(VIEW_POLLUTION,{ CONST_externallyStoredData644, CONST_externallyStoredData664 }) ,
		map<short, vector<string> >::value_type(VIEW_CORPORATECULTURE,{ CONST_externallyStoredData645, CONST_externallyStoredDataB1056 }) ,
		map<short, vector<string> >::value_type(VIEW_CEOSALARY,{ CONST_externallyStoredData646, CONST_externallyStoredDataB1057 }) ,
		map<short, vector<string> >::value_type(VIEW_WOMEN,{ CONST_externallyStoredData647, CONST_externallyStoredDataB1058 }) ,
		map<short, vector<string> >::value_type(VIEW_CIVILRIGHTS,{ CONST_externallyStoredData648, CONST_externallyStoredDataB1059 }) ,
		map<short, vector<string> >::value_type(VIEW_DRUGS,{ CONST_externallyStoredData649, CONST_externallyStoredDataB1060 }) ,
		map<short, vector<string> >::value_type(VIEW_IMMIGRATION,{ CONST_externallyStoredData650, CONST_externallyStoredDataB1061 }) ,
		map<short, vector<string> >::value_type(VIEW_MILITARY,{ CONST_externallyStoredData651, CONST_externallyStoredData677 }) ,
		map<short, vector<string> >::value_type(VIEW_AMRADIO,{ CONST_externallyStoredData652, CONST_externallyStoredDataB1062 }) ,
		map<short, vector<string> >::value_type(VIEW_CABLENEWS,{ CONST_externallyStoredData653, CONST_externallyStoredDataB1063 }) ,
		//map<short, vector<string> >::value_type( VIEW_POLITICALVIOLENCE, { CONST_externallyStoredData654, CONST_externallyStoredDataB1064 } ) ,
		map<short, vector<string> >::value_type(VIEW_LIBERALCRIMESQUAD,{ CONST_externallyStoredData656, CONST_externallyStoredDataB1065 }) ,
		map<short, vector<string> >::value_type(VIEW_LIBERALCRIMESQUADPOS,{ CONST_externallyStoredData656, CONST_externallyStoredDataB1066 }) ,
		map<short, vector<string> >::value_type(VIEW_CONSERVATIVECRIMESQUAD,{ CONST_externallyStoredData657, CONST_externallyStoredDataB1067 })
	};
	getLawString = {
		map<short, string>::value_type(LAW_ABORTION, CONST_externallyStoredData658),
		map<short, string>::value_type(LAW_ANIMALRESEARCH, CONST_externallyStoredData659), // a.k.a. CONST_externallyStoredDataB1068
		map<short, string>::value_type(LAW_POLICEBEHAVIOR, CONST_externallyStoredData660), // a.k.a. CONST_externallyStoredDataB1069
		map<short, string>::value_type(LAW_PRIVACY, CONST_externallyStoredData661), // a.k.a. CONST_externallyStoredDataB1070
		map<short, string>::value_type(LAW_DEATHPENALTY, CONST_externallyStoredData662), // a.k.a. CONST_externallyStoredDataB1071
		map<short, string>::value_type(LAW_NUCLEARPOWER, CONST_externallyStoredData663),
		map<short, string>::value_type(LAW_POLLUTION, CONST_externallyStoredData664),
		map<short, string>::value_type(LAW_LABOR, CONST_externallyStoredData665), // a.k.a. CONST_externallyStoredDataB1072
		map<short, string>::value_type(LAW_GAY, CONST_externallyStoredData666), // a.k.a. CONST_externallyStoredDataB1073
		map<short, string>::value_type(LAW_CORPORATE, CONST_externallyStoredData667), // a.k.a. CONST_externallyStoredDataB1074
		map<short, string>::value_type(LAW_FREESPEECH, CONST_externallyStoredData668), // a.k.a. CONST_externallyStoredDataB1075
		map<short, string>::value_type(LAW_FLAGBURNING, CONST_externallyStoredData669),
		map<short, string>::value_type(LAW_GUNCONTROL, CONST_externallyStoredData670),
		map<short, string>::value_type(LAW_TAX, CONST_externallyStoredData671), // a.k.a. CONST_externallyStoredDataB1076
		map<short, string>::value_type(LAW_WOMEN, CONST_externallyStoredData672),
		map<short, string>::value_type(LAW_CIVILRIGHTS, CONST_externallyStoredData673),
		map<short, string>::value_type(LAW_DRUGS, CONST_externallyStoredData674), // a.k.a. CONST_externallyStoredDataB1077
		map<short, string>::value_type(LAW_IMMIGRATION, CONST_externallyStoredData675),
		map<short, string>::value_type(LAW_ELECTIONS, CONST_externallyStoredData676),
		map<short, string>::value_type(LAW_MILITARY, CONST_externallyStoredData677),
		map<short, string>::value_type(LAW_PRISONS, CONST_externallyStoredData678),
		map<short, string>::value_type(LAW_TORTURE, CONST_externallyStoredData679)
	};
	getLawFlagString = {
		map<short, string>::value_type(LAWFLAG_TREASON,  CONST_externallyStoredData680),
		map<short, string>::value_type(LAWFLAG_TERRORISM,  CONST_externallyStoredData681),
		map<short, string>::value_type(LAWFLAG_MURDER,  CONST_externallyStoredData682),
		map<short, string>::value_type(LAWFLAG_KIDNAPPING,  CONST_externallyStoredData683),
		map<short, string>::value_type(LAWFLAG_BANKROBBERY,  CONST_externallyStoredData684),
		map<short, string>::value_type(LAWFLAG_ARSON,  CONST_externallyStoredData685),
		map<short, string>::value_type(LAWFLAG_SPEECH,  CONST_externallyStoredData686),
		map<short, string>::value_type(LAWFLAG_BROWNIES,  CONST_externallyStoredData687),
		map<short, string>::value_type(LAWFLAG_ESCAPED,  CONST_externallyStoredData688),
		map<short, string>::value_type(LAWFLAG_HELPESCAPE,  CONST_externallyStoredData689),
		map<short, string>::value_type(LAWFLAG_JURY,  CONST_externallyStoredData690),
		map<short, string>::value_type(LAWFLAG_RACKETEERING,  CONST_externallyStoredData691),
		map<short, string>::value_type(LAWFLAG_EXTORTION,  CONST_externallyStoredData692),
		map<short, string>::value_type(LAWFLAG_ARMEDASSAULT,  CONST_externallyStoredData693),
		map<short, string>::value_type(LAWFLAG_ASSAULT,  CONST_externallyStoredData694),
		map<short, string>::value_type(LAWFLAG_CARTHEFT,  CONST_externallyStoredData695),
		map<short, string>::value_type(LAWFLAG_CCFRAUD,  CONST_externallyStoredData696),
		map<short, string>::value_type(LAWFLAG_THEFT,  CONST_externallyStoredData697),
		map<short, string>::value_type(LAWFLAG_PROSTITUTION,  CONST_externallyStoredData698),
		//map<short, string>::value_type( LAWFLAG_GUNUSE,  CONST_externallyStoredData699),
		//map<short, string>::value_type( LAWFLAG_GUNCARRY,  CONST_externallyStoredData700),
		map<short, string>::value_type(LAWFLAG_COMMERCE,  CONST_externallyStoredData701),
		map<short, string>::value_type(LAWFLAG_INFORMATION,  CONST_externallyStoredData702),
		map<short, string>::value_type(LAWFLAG_BURIAL,  CONST_externallyStoredData703),
		map<short, string>::value_type(LAWFLAG_BREAKING,  CONST_externallyStoredData704),
		map<short, string>::value_type(LAWFLAG_VANDALISM,  CONST_externallyStoredData705),
		map<short, string>::value_type(LAWFLAG_RESIST,  CONST_externallyStoredData706),
		map<short, string>::value_type(LAWFLAG_DISTURBANCE,  CONST_externallyStoredData707),
		map<short, string>::value_type(LAWFLAG_PUBLICNUDITY,  CONST_externallyStoredData708),
		map<short, string>::value_type(LAWFLAG_LOITERING,  CONST_externallyStoredData709)
	};
	getLawFlagStringFull = {
		map<short, map<short, string> >::value_type(LAWFLAG_BURNFLAG,
		{
			map<short, string>::value_type(ALIGN_ARCHCONSERVATIVE ,	CONST_externallyStoredData710),
			map<short, string>::value_type(ALIGN_CONSERVATIVE,CONST_externallyStoredData715),
			map<short, string>::value_type(ALIGN_MODERATE,CONST_externallyStoredData715),
			map<short, string>::value_type(ALIGN_LIBERAL,CONST_externallyStoredData715),
			map<short, string>::value_type(ALIGN_ELITELIBERAL,CONST_externallyStoredData715),
			map<short, string>::value_type(ALIGN_STALINIST ,CONST_externallyStoredData715)
		}
			),
		map<short, map<short, string> >::value_type(LAWFLAG_HIREILLEGAL,{
			map<short, string>::value_type(ALIGN_ARCHCONSERVATIVE,CONST_externallyStoredData718),
			map<short, string>::value_type(ALIGN_CONSERVATIVE,CONST_externallyStoredData718),
			map<short, string>::value_type(ALIGN_MODERATE,CONST_externallyStoredData718),
			map<short, string>::value_type(ALIGN_LIBERAL,CONST_externallyStoredData720),
			map<short, string>::value_type(ALIGN_ELITELIBERAL,CONST_externallyStoredData720)
		}
			)
	};
	enumToCreature = {
		map<short, string>::value_type(CREATURE_BOUNCER,	CONST_externallyStoredData865),
		map<short, string>::value_type(CREATURE_SECURITYGUARD,	CONST_externallyStoredData866),
		map<short, string>::value_type(CREATURE_SCIENTIST_LABTECH,	CONST_externallyStoredData867),
		map<short, string>::value_type(CREATURE_SCIENTIST_EMINENT,	CONST_externallyStoredData868),
		map<short, string>::value_type(CREATURE_CORPORATE_MANAGER,	CONST_externallyStoredData869),
		map<short, string>::value_type(CREATURE_CORPORATE_CEO,	CONST_externallyStoredData870),
		map<short, string>::value_type(CREATURE_WORKER_SERVANT,	CONST_externallyStoredData871),
		map<short, string>::value_type(CREATURE_WORKER_JANITOR,	CONST_externallyStoredData872),
		map<short, string>::value_type(CREATURE_WORKER_SWEATSHOP,	CONST_externallyStoredData873),
		map<short, string>::value_type(CREATURE_WORKER_FACTORY_NONUNION,	CONST_externallyStoredData874),
		map<short, string>::value_type(CREATURE_WORKER_FACTORY_CHILD,	CONST_externallyStoredData875),
		map<short, string>::value_type(CREATURE_WORKER_SECRETARY,	CONST_externallyStoredData876),
		map<short, string>::value_type(CREATURE_WORKER_FACTORY_UNION,	CONST_externallyStoredData877),
		map<short, string>::value_type(CREATURE_LANDLORD,	CONST_externallyStoredData878),
		map<short, string>::value_type(CREATURE_TEENAGER,	CONST_externallyStoredData879),
		map<short, string>::value_type(CREATURE_COP,	CONST_externallyStoredData880),
		map<short, string>::value_type(CREATURE_SWAT,	CONST_externallyStoredData881),
		map<short, string>::value_type(CREATURE_DEATHSQUAD,	CONST_externallyStoredData882),
		map<short, string>::value_type(CREATURE_FIREFIGHTER,	CONST_externallyStoredData883),
		map<short, string>::value_type(CREATURE_EDUCATOR,	CONST_externallyStoredData884),
		map<short, string>::value_type(CREATURE_GANGUNIT,	CONST_externallyStoredData885),
		map<short, string>::value_type(CREATURE_JUDGE_LIBERAL,	CONST_externallyStoredData886),
		map<short, string>::value_type(CREATURE_JUDGE_CONSERVATIVE,	CONST_externallyStoredData887),
		map<short, string>::value_type(CREATURE_AGENT,	CONST_externallyStoredData888),
		map<short, string>::value_type(CREATURE_RADIOPERSONALITY,	CONST_externallyStoredData889),
		map<short, string>::value_type(CREATURE_NEWSANCHOR,	CONST_externallyStoredData890),
		map<short, string>::value_type(CREATURE_GENETIC,	CONST_externallyStoredData891),
		map<short, string>::value_type(CREATURE_GUARDDOG,	CONST_externallyStoredData892),
		map<short, string>::value_type(CREATURE_PRISONER,	CONST_externallyStoredData893),
		map<short, string>::value_type(CREATURE_JUROR,	CONST_externallyStoredData894),
		map<short, string>::value_type(CREATURE_LAWYER,	CONST_externallyStoredData895),
		map<short, string>::value_type(CREATURE_SEWERWORKER,	CONST_externallyStoredData896),
		map<short, string>::value_type(CREATURE_COLLEGESTUDENT,	CONST_externallyStoredData897),
		map<short, string>::value_type(CREATURE_MUSICIAN,	CONST_externallyStoredData898),
		map<short, string>::value_type(CREATURE_MATHEMATICIAN,	CONST_externallyStoredData899),
		map<short, string>::value_type(CREATURE_TEACHER,	CONST_externallyStoredData900),
		map<short, string>::value_type(CREATURE_HSDROPOUT,	CONST_externallyStoredData901),
		map<short, string>::value_type(CREATURE_BUM,	CONST_externallyStoredData902),
		map<short, string>::value_type(CREATURE_GANGMEMBER,	CONST_externallyStoredData903),
		map<short, string>::value_type(CREATURE_CRACKHEAD,	CONST_externallyStoredData904),
		map<short, string>::value_type(CREATURE_PRIEST,	CONST_externallyStoredData905),
		map<short, string>::value_type(CREATURE_ENGINEER,	CONST_externallyStoredData906),
		map<short, string>::value_type(CREATURE_FASTFOODWORKER,	CONST_externallyStoredData907),
		map<short, string>::value_type(CREATURE_BAKER,	CONST_externallyStoredData908),
		map<short, string>::value_type(CREATURE_BARISTA,	CONST_externallyStoredData909),
		map<short, string>::value_type(CREATURE_BARTENDER,	CONST_externallyStoredData910),
		map<short, string>::value_type(CREATURE_TELEMARKETER,	CONST_externallyStoredData911),
		map<short, string>::value_type(CREATURE_CARSALESMAN,	CONST_externallyStoredData912),
		map<short, string>::value_type(CREATURE_OFFICEWORKER,	CONST_externallyStoredData913),
		map<short, string>::value_type(CREATURE_FOOTBALLCOACH,	CONST_externallyStoredData914),
		map<short, string>::value_type(CREATURE_PROSTITUTE,	CONST_externallyStoredData915),
		map<short, string>::value_type(CREATURE_MAILMAN,	CONST_externallyStoredData916),
		map<short, string>::value_type(CREATURE_GARBAGEMAN,	CONST_externallyStoredData917),
		map<short, string>::value_type(CREATURE_PLUMBER,	CONST_externallyStoredData918),
		map<short, string>::value_type(CREATURE_CHEF,	CONST_externallyStoredData919),
		map<short, string>::value_type(CREATURE_CONSTRUCTIONWORKER,	CONST_externallyStoredData920),
		map<short, string>::value_type(CREATURE_AMATEURMAGICIAN,	CONST_externallyStoredData921),
		map<short, string>::value_type(CREATURE_TANK,	CONST_externallyStoredData922),
		map<short, string>::value_type(CREATURE_MERC,	CONST_externallyStoredData923),
		map<short, string>::value_type(CREATURE_HICK,	CONST_externallyStoredData924),
		map<short, string>::value_type(CREATURE_SOLDIER,	CONST_externallyStoredData925),
		map<short, string>::value_type(CREATURE_VETERAN,	CONST_externallyStoredData926),
		map<short, string>::value_type(CREATURE_HARDENED_VETERAN,	CONST_externallyStoredData927),
		map<short, string>::value_type(CREATURE_PRISONGUARD,	CONST_externallyStoredData928),
		map<short, string>::value_type(CREATURE_HIPPIE,	CONST_externallyStoredData929),
		map<short, string>::value_type(CREATURE_CRITIC_ART,	CONST_externallyStoredData930),
		map<short, string>::value_type(CREATURE_CRITIC_MUSIC,	CONST_externallyStoredData931),
		map<short, string>::value_type(CREATURE_SOCIALITE,	CONST_externallyStoredData932),
		map<short, string>::value_type(CREATURE_PROGRAMMER,	CONST_externallyStoredData933),
		map<short, string>::value_type(CREATURE_RETIREE,	CONST_externallyStoredData934),
		map<short, string>::value_type(CREATURE_PAINTER,	CONST_externallyStoredData935),
		map<short, string>::value_type(CREATURE_SCULPTOR,	CONST_externallyStoredData936),
		map<short, string>::value_type(CREATURE_AUTHOR,	CONST_externallyStoredData937),
		map<short, string>::value_type(CREATURE_JOURNALIST,	CONST_externallyStoredData938),
		map<short, string>::value_type(CREATURE_DANCER,	CONST_externallyStoredData939),
		map<short, string>::value_type(CREATURE_PHOTOGRAPHER,	CONST_externallyStoredData940),
		map<short, string>::value_type(CREATURE_CAMERAMAN,	CONST_externallyStoredData941),
		map<short, string>::value_type(CREATURE_HAIRSTYLIST,	CONST_externallyStoredData942),
		map<short, string>::value_type(CREATURE_FASHIONDESIGNER,	CONST_externallyStoredData943),
		map<short, string>::value_type(CREATURE_CLERK,	CONST_externallyStoredData944),
		map<short, string>::value_type(CREATURE_THIEF,	CONST_externallyStoredData945),
		map<short, string>::value_type(CREATURE_ACTOR,	CONST_externallyStoredData946),
		map<short, string>::value_type(CREATURE_YOGAINSTRUCTOR,	CONST_externallyStoredData947),
		map<short, string>::value_type(CREATURE_MARTIALARTIST,	CONST_externallyStoredData948),
		map<short, string>::value_type(CREATURE_ATHLETE,	CONST_externallyStoredData949),
		map<short, string>::value_type(CREATURE_BIKER,	CONST_externallyStoredData950),
		map<short, string>::value_type(CREATURE_TRUCKER,	CONST_externallyStoredData951),
		map<short, string>::value_type(CREATURE_TAXIDRIVER,	CONST_externallyStoredData952),
		map<short, string>::value_type(CREATURE_NUN,	CONST_externallyStoredData953),
		map<short, string>::value_type(CREATURE_MUTANT,	CONST_externallyStoredData954),
		map<short, string>::value_type(CREATURE_DOCTOR,	CONST_externallyStoredData955),
		map<short, string>::value_type(CREATURE_NURSE,	CONST_externallyStoredData956),
		map<short, string>::value_type(CREATURE_CCS_VIGILANTE,	CONST_externallyStoredData957),
		map<short, string>::value_type(CREATURE_CCS_ARCHCONSERVATIVE,	CONST_externallyStoredData958),
		map<short, string>::value_type(CREATURE_POLITICALACTIVIST,	CONST_externallyStoredData959),
		map<short, string>::value_type(CREATURE_CCS_MOLOTOV,	CONST_externallyStoredData960),
		map<short, string>::value_type(CREATURE_CCS_SNIPER,	CONST_externallyStoredData961),
		map<short, string>::value_type(CREATURE_PSYCHOLOGIST,	CONST_externallyStoredData962),
		map<short, string>::value_type(CREATURE_LOCKSMITH,	CONST_externallyStoredData963),
		map<short, string>::value_type(CREATURE_MILITARYPOLICE,	CONST_externallyStoredData964),
		map<short, string>::value_type(CREATURE_SEAL,	CONST_externallyStoredData965),
		map<short, string>::value_type(CREATURE_MILITARYOFFICER,	CONST_externallyStoredData966),
		map<short, string>::value_type(CREATURE_BANK_TELLER,	CONST_externallyStoredData967),
		map<short, string>::value_type(CREATURE_BANK_MANAGER,	CONST_externallyStoredData968),
		map<short, string>::value_type(CREATURE_SECRET_SERVICE,	CONST_externallyStoredData969),
		map<short, string>::value_type(CREATURE_POLITICIAN,	CONST_externallyStoredData970)
	};
	getSkillEnumFromString = {
		map<string, short>::value_type(CONST_externallyStoredData827, SKILL_ART),
		map<string, short>::value_type(CONST_externallyStoredData828, SKILL_AXE),
		map<string, short>::value_type(CONST_externallyStoredData829, SKILL_BUSINESS),
		map<string, short>::value_type(CONST_externallyStoredData830, SKILL_CLUB),
		map<string, short>::value_type(CONST_externallyStoredData831, SKILL_COMPUTERS),
		map<string, short>::value_type(CONST_externallyStoredData832, SKILL_DISGUISE),
		map<string, short>::value_type(CONST_externallyStoredData833, SKILL_DODGE),
		map<string, short>::value_type(CONST_externallyStoredData834, SKILL_DRIVING),
		map<string, short>::value_type(CONST_externallyStoredData835, SKILL_FIRSTAID),
		map<string, short>::value_type(CONST_externallyStoredData836, SKILL_HEAVYWEAPONS),
		map<string, short>::value_type(CONST_externallyStoredData837, SKILL_KNIFE),
		map<string, short>::value_type(CONST_externallyStoredData838, SKILL_LAW),
		map<string, short>::value_type(CONST_externallyStoredData839, SKILL_HANDTOHAND),
		map<string, short>::value_type(CONST_externallyStoredData840, SKILL_MUSIC),
		map<string, short>::value_type(CONST_externallyStoredData841, SKILL_PERSUASION),
		map<string, short>::value_type(CONST_externallyStoredData842, SKILL_PISTOL),
		map<string, short>::value_type(CONST_externallyStoredData843, SKILL_PSYCHOLOGY),
		map<string, short>::value_type(CONST_externallyStoredData844, SKILL_RELIGION),
		map<string, short>::value_type(CONST_externallyStoredData845, SKILL_RIFLE),
		map<string, short>::value_type(CONST_externallyStoredData846, SKILL_SCIENCE),
		map<string, short>::value_type(CONST_externallyStoredData847, SKILL_SECURITY),
		map<string, short>::value_type(CONST_externallyStoredData848, SKILL_SEDUCTION),
		map<string, short>::value_type(CONST_externallyStoredData849, SKILL_SHOTGUN),
		map<string, short>::value_type(CONST_externallyStoredData850, SKILL_SMG),
		map<string, short>::value_type(CONST_externallyStoredData851, SKILL_STEALTH),
		map<string, short>::value_type(CONST_externallyStoredData852, SKILL_STREETSENSE),
		map<string, short>::value_type(CONST_externallyStoredData853, SKILL_SWORD),
		map<string, short>::value_type(CONST_externallyStoredData854, SKILL_TAILORING),
		map<string, short>::value_type(CONST_externallyStoredData855, SKILL_TEACHING),
		map<string, short>::value_type(CONST_externallyStoredData856, SKILL_THROWING),
		map<string, short>::value_type(CONST_externallyStoredData857, SKILL_WRITING)
	};
	getAttributeEnumFromString = {
		map<string, short>::value_type(CONST_externallyStoredData858, ATTRIBUTE_HEART),
		map<string, short>::value_type(CONST_externallyStoredData859, ATTRIBUTE_WISDOM),
		map<string, short>::value_type(CONST_externallyStoredData860, ATTRIBUTE_INTELLIGENCE),
		map<string, short>::value_type(CONST_externallyStoredData861, ATTRIBUTE_AGILITY),
		map<string, short>::value_type(CONST_externallyStoredData862, ATTRIBUTE_STRENGTH),
		map<string, short>::value_type(CONST_externallyStoredData863, ATTRIBUTE_HEALTH),
		map<string, short>::value_type(CONST_externallyStoredData864, ATTRIBUTE_CHARISMA)
	};
	getCreatureEnumFromString = {
		map<string, short>::value_type(CONST_externallyStoredData865, CREATURE_BOUNCER),
		map<string, short>::value_type(CONST_externallyStoredData866, CREATURE_SECURITYGUARD),
		map<string, short>::value_type(CONST_externallyStoredData867, CREATURE_SCIENTIST_LABTECH),
		map<string, short>::value_type(CONST_externallyStoredData868, CREATURE_SCIENTIST_EMINENT),
		map<string, short>::value_type(CONST_externallyStoredData869, CREATURE_CORPORATE_MANAGER),
		map<string, short>::value_type(CONST_externallyStoredData870, CREATURE_CORPORATE_CEO),
		map<string, short>::value_type(CONST_externallyStoredData871, CREATURE_WORKER_SERVANT),
		map<string, short>::value_type(CONST_externallyStoredData872, CREATURE_WORKER_JANITOR),
		map<string, short>::value_type(CONST_externallyStoredData873, CREATURE_WORKER_SWEATSHOP),
		map<string, short>::value_type(CONST_externallyStoredData874, CREATURE_WORKER_FACTORY_NONUNION),
		map<string, short>::value_type(CONST_externallyStoredData875, CREATURE_WORKER_FACTORY_CHILD),
		map<string, short>::value_type(CONST_externallyStoredData876, CREATURE_WORKER_SECRETARY),
		map<string, short>::value_type(CONST_externallyStoredData877, CREATURE_WORKER_FACTORY_UNION),
		map<string, short>::value_type(CONST_externallyStoredData878, CREATURE_LANDLORD),
		map<string, short>::value_type(CONST_externallyStoredData879, CREATURE_TEENAGER),
		map<string, short>::value_type(CONST_externallyStoredData880, CREATURE_COP),
		map<string, short>::value_type(CONST_externallyStoredData881, CREATURE_SWAT),
		map<string, short>::value_type(CONST_externallyStoredData882, CREATURE_DEATHSQUAD),
		map<string, short>::value_type(CONST_externallyStoredData883, CREATURE_FIREFIGHTER),
		map<string, short>::value_type(CONST_externallyStoredData884, CREATURE_EDUCATOR),
		map<string, short>::value_type(CONST_externallyStoredData885, CREATURE_GANGUNIT),
		map<string, short>::value_type(CONST_externallyStoredData886, CREATURE_JUDGE_LIBERAL),
		map<string, short>::value_type(CONST_externallyStoredData887, CREATURE_JUDGE_CONSERVATIVE),
		map<string, short>::value_type(CONST_externallyStoredData888, CREATURE_AGENT),
		map<string, short>::value_type(CONST_externallyStoredData889, CREATURE_RADIOPERSONALITY),
		map<string, short>::value_type(CONST_externallyStoredData890, CREATURE_NEWSANCHOR),
		map<string, short>::value_type(CONST_externallyStoredData891, CREATURE_GENETIC),
		map<string, short>::value_type(CONST_externallyStoredData892, CREATURE_GUARDDOG),
		map<string, short>::value_type(CONST_externallyStoredData893, CREATURE_PRISONER),
		map<string, short>::value_type(CONST_externallyStoredData894, CREATURE_JUROR),
		map<string, short>::value_type(CONST_externallyStoredData895, CREATURE_LAWYER),
		map<string, short>::value_type(CONST_externallyStoredData896, CREATURE_SEWERWORKER),
		map<string, short>::value_type(CONST_externallyStoredData897, CREATURE_COLLEGESTUDENT),
		map<string, short>::value_type(CONST_externallyStoredData898, CREATURE_MUSICIAN),
		map<string, short>::value_type(CONST_externallyStoredData899, CREATURE_MATHEMATICIAN),
		map<string, short>::value_type(CONST_externallyStoredData900, CREATURE_TEACHER),
		map<string, short>::value_type(CONST_externallyStoredData901, CREATURE_HSDROPOUT),
		map<string, short>::value_type(CONST_externallyStoredData902, CREATURE_BUM),
		map<string, short>::value_type(CONST_externallyStoredData903, CREATURE_GANGMEMBER),
		map<string, short>::value_type(CONST_externallyStoredData904, CREATURE_CRACKHEAD),
		map<string, short>::value_type(CONST_externallyStoredData905, CREATURE_PRIEST),
		map<string, short>::value_type(CONST_externallyStoredData906, CREATURE_ENGINEER),
		map<string, short>::value_type(CONST_externallyStoredData907, CREATURE_FASTFOODWORKER),
		map<string, short>::value_type(CONST_externallyStoredData908, CREATURE_BAKER),
		map<string, short>::value_type(CONST_externallyStoredData909, CREATURE_BARISTA),
		map<string, short>::value_type(CONST_externallyStoredData910, CREATURE_BARTENDER),
		map<string, short>::value_type(CONST_externallyStoredData911, CREATURE_TELEMARKETER),
		map<string, short>::value_type(CONST_externallyStoredData912, CREATURE_CARSALESMAN),
		map<string, short>::value_type(CONST_externallyStoredData913, CREATURE_OFFICEWORKER),
		map<string, short>::value_type(CONST_externallyStoredData914, CREATURE_FOOTBALLCOACH),
		map<string, short>::value_type(CONST_externallyStoredData915, CREATURE_PROSTITUTE),
		map<string, short>::value_type(CONST_externallyStoredData916, CREATURE_MAILMAN),
		map<string, short>::value_type(CONST_externallyStoredData917, CREATURE_GARBAGEMAN),
		map<string, short>::value_type(CONST_externallyStoredData918, CREATURE_PLUMBER),
		map<string, short>::value_type(CONST_externallyStoredData919, CREATURE_CHEF),
		map<string, short>::value_type(CONST_externallyStoredData920, CREATURE_CONSTRUCTIONWORKER),
		map<string, short>::value_type(CONST_externallyStoredData921, CREATURE_AMATEURMAGICIAN),
		map<string, short>::value_type(CONST_externallyStoredData922, CREATURE_TANK),
		map<string, short>::value_type(CONST_externallyStoredData923, CREATURE_MERC),
		map<string, short>::value_type(CONST_externallyStoredData924, CREATURE_HICK),
		map<string, short>::value_type(CONST_externallyStoredData925, CREATURE_SOLDIER),
		map<string, short>::value_type(CONST_externallyStoredData926, CREATURE_VETERAN),
		map<string, short>::value_type(CONST_externallyStoredData927, CREATURE_HARDENED_VETERAN),
		map<string, short>::value_type(CONST_externallyStoredData928, CREATURE_PRISONGUARD),
		map<string, short>::value_type(CONST_externallyStoredData929, CREATURE_HIPPIE),
		map<string, short>::value_type(CONST_externallyStoredData930, CREATURE_CRITIC_ART),
		map<string, short>::value_type(CONST_externallyStoredData931, CREATURE_CRITIC_MUSIC),
		map<string, short>::value_type(CONST_externallyStoredData932, CREATURE_SOCIALITE),
		map<string, short>::value_type(CONST_externallyStoredData933, CREATURE_PROGRAMMER),
		map<string, short>::value_type(CONST_externallyStoredData934, CREATURE_RETIREE),
		map<string, short>::value_type(CONST_externallyStoredData935, CREATURE_PAINTER),
		map<string, short>::value_type(CONST_externallyStoredData936, CREATURE_SCULPTOR),
		map<string, short>::value_type(CONST_externallyStoredData937, CREATURE_AUTHOR),
		map<string, short>::value_type(CONST_externallyStoredData938, CREATURE_JOURNALIST),
		map<string, short>::value_type(CONST_externallyStoredData939, CREATURE_DANCER),
		map<string, short>::value_type(CONST_externallyStoredData940, CREATURE_PHOTOGRAPHER),
		map<string, short>::value_type(CONST_externallyStoredData941, CREATURE_CAMERAMAN),
		map<string, short>::value_type(CONST_externallyStoredData942, CREATURE_HAIRSTYLIST),
		map<string, short>::value_type(CONST_externallyStoredData943, CREATURE_FASHIONDESIGNER),
		map<string, short>::value_type(CONST_externallyStoredData944, CREATURE_CLERK),
		map<string, short>::value_type(CONST_externallyStoredData945, CREATURE_THIEF),
		map<string, short>::value_type(CONST_externallyStoredData946, CREATURE_ACTOR),
		map<string, short>::value_type(CONST_externallyStoredData947, CREATURE_YOGAINSTRUCTOR),
		map<string, short>::value_type(CONST_externallyStoredData948, CREATURE_MARTIALARTIST),
		map<string, short>::value_type(CONST_externallyStoredData949, CREATURE_ATHLETE),
		map<string, short>::value_type(CONST_externallyStoredData950, CREATURE_BIKER),
		map<string, short>::value_type(CONST_externallyStoredData951, CREATURE_TRUCKER),
		map<string, short>::value_type(CONST_externallyStoredData952, CREATURE_TAXIDRIVER),
		map<string, short>::value_type(CONST_externallyStoredData953, CREATURE_NUN),
		map<string, short>::value_type(CONST_externallyStoredData954, CREATURE_MUTANT),
		map<string, short>::value_type(CONST_externallyStoredData955, CREATURE_DOCTOR),
		map<string, short>::value_type(CONST_externallyStoredData956, CREATURE_NURSE),
		map<string, short>::value_type(CONST_externallyStoredData957, CREATURE_CCS_VIGILANTE),
		map<string, short>::value_type(CONST_externallyStoredData958, CREATURE_CCS_ARCHCONSERVATIVE),
		map<string, short>::value_type(CONST_externallyStoredData959, CREATURE_POLITICALACTIVIST),
		map<string, short>::value_type(CONST_externallyStoredData960, CREATURE_CCS_MOLOTOV),
		map<string, short>::value_type(CONST_externallyStoredData961, CREATURE_CCS_SNIPER),
		map<string, short>::value_type(CONST_externallyStoredData962, CREATURE_PSYCHOLOGIST),
		map<string, short>::value_type(CONST_externallyStoredData963, CREATURE_LOCKSMITH),
		map<string, short>::value_type(CONST_externallyStoredData964, CREATURE_MILITARYPOLICE),
		map<string, short>::value_type(CONST_externallyStoredData965, CREATURE_SEAL),
		map<string, short>::value_type(CONST_externallyStoredData966, CREATURE_MILITARYOFFICER),
		map<string, short>::value_type(CONST_externallyStoredData967, CREATURE_BANK_TELLER),
		map<string, short>::value_type(CONST_externallyStoredData968, CREATURE_BANK_MANAGER),
		map<string, short>::value_type(CONST_externallyStoredData969, CREATURE_SECRET_SERVICE),
		map<string, short>::value_type(CONST_externallyStoredData970, CREATURE_POLITICIAN)
	};
	getBaseEnumFromString = {
		map<string, short>::value_type(CONST_externallyStoredData971, SITE_RESIDENTIAL_SHELTER),
		map<string, short>::value_type(CONST_externallyStoredData972, SITE_RESIDENTIAL_TENEMENT),
		map<string, short>::value_type(CONST_externallyStoredData973, SITE_RESIDENTIAL_APARTMENT),
		map<string, short>::value_type(CONST_externallyStoredData974, SITE_RESIDENTIAL_APARTMENT_UPSCALE),
		map<string, short>::value_type(CONST_externallyStoredData975, SITE_RESIDENTIAL_BOMBSHELTER),
		map<string, short>::value_type(CONST_externallyStoredData976, SITE_LABORATORY_COSMETICS),
		map<string, short>::value_type(CONST_externallyStoredData977, SITE_LABORATORY_GENETIC),
		map<string, short>::value_type(CONST_externallyStoredData978, SITE_GOVERNMENT_POLICESTATION),
		map<string, short>::value_type(CONST_externallyStoredData979, SITE_GOVERNMENT_COURTHOUSE),
		map<string, short>::value_type(CONST_externallyStoredData980, SITE_GOVERNMENT_PRISON),
		map<string, short>::value_type(CONST_externallyStoredData981, SITE_GOVERNMENT_INTELLIGENCEHQ),
		map<string, short>::value_type(CONST_externallyStoredData982, SITE_GOVERNMENT_FIRESTATION),
		map<string, short>::value_type(CONST_externallyStoredData983, SITE_INDUSTRY_SWEATSHOP),
		map<string, short>::value_type(CONST_externallyStoredData984, SITE_INDUSTRY_POLLUTER),
		map<string, short>::value_type(CONST_externallyStoredData985, SITE_INDUSTRY_NUCLEAR),
		map<string, short>::value_type(CONST_externallyStoredData986, SITE_INDUSTRY_WAREHOUSE),
		map<string, short>::value_type(CONST_externallyStoredData987, SITE_CORPORATE_HEADQUARTERS),
		map<string, short>::value_type(CONST_externallyStoredData988, SITE_CORPORATE_HOUSE),
		map<string, short>::value_type(CONST_externallyStoredData989, SITE_MEDIA_AMRADIO),
		map<string, short>::value_type(CONST_externallyStoredData990, SITE_MEDIA_CABLENEWS),
		map<string, short>::value_type(CONST_externallyStoredData991, SITE_BUSINESS_CRACKHOUSE),
		map<string, short>::value_type(CONST_externallyStoredData992, SITE_BUSINESS_JUICEBAR),
		map<string, short>::value_type(CONST_externallyStoredData993, SITE_BUSINESS_CIGARBAR),
		map<string, short>::value_type(CONST_externallyStoredData994, SITE_BUSINESS_LATTESTAND),
		map<string, short>::value_type(CONST_externallyStoredData995, SITE_BUSINESS_VEGANCOOP),
		map<string, short>::value_type(CONST_externallyStoredData996, SITE_BUSINESS_INTERNETCAFE),
		map<string, short>::value_type(CONST_externallyStoredData997, SITE_BUSINESS_BARANDGRILL),
		map<string, short>::value_type(CONST_externallyStoredData998, SITE_OUTDOOR_PUBLICPARK),
		map<string, short>::value_type(CONST_externallyStoredData999, SITE_OUTDOOR_BUNKER),
		map<string, short>::value_type(CONST_externallyStoredData1000, SITE_GOVERNMENT_ARMYBASE),
		map<string, short>::value_type(CONST_externallyStoredData1001, SITE_BUSINESS_BANK),
		map<string, short>::value_type(CONST_externallyStoredData1002, SITE_GOVERNMENT_LIBERAL_PARTY_HQ),
		map<string, short>::value_type(CONST_externallyStoredData1003, SITE_GOVERNMENT_WHITE_HOUSE)
	};
	getSpecialWoundEnumFromString = {
		map<string, short>::value_type(CONST_externallyStoredData1004, SPECIALWOUND_TEETH),
		map<string, short>::value_type(CONST_externallyStoredData1005, SPECIALWOUND_RIGHTEYE),
		map<string, short>::value_type(CONST_externallyStoredData1006, SPECIALWOUND_LEFTEYE),
		map<string, short>::value_type(CONST_externallyStoredData1007, SPECIALWOUND_NOSE),
		map<string, short>::value_type(CONST_externallyStoredData1008, SPECIALWOUND_TONGUE),
		map<string, short>::value_type(CONST_externallyStoredData1009, SPECIALWOUND_RIGHTLUNG),
		map<string, short>::value_type(CONST_externallyStoredData1010, SPECIALWOUND_LEFTLUNG),
		map<string, short>::value_type(CONST_externallyStoredData1011, SPECIALWOUND_HEART),
		map<string, short>::value_type(CONST_externallyStoredData1012, SPECIALWOUND_LIVER),
		map<string, short>::value_type(CONST_externallyStoredData1013, SPECIALWOUND_STOMACH),
		map<string, short>::value_type(CONST_externallyStoredData1014, SPECIALWOUND_RIGHTKIDNEY),
		map<string, short>::value_type(CONST_externallyStoredData1015, SPECIALWOUND_LEFTKIDNEY),
		map<string, short>::value_type(CONST_externallyStoredData1016, SPECIALWOUND_SPLEEN),
		map<string, short>::value_type(CONST_externallyStoredData1017, SPECIALWOUND_RIBS),
		map<string, short>::value_type(CONST_externallyStoredData1018, SPECIALWOUND_NECK),
		map<string, short>::value_type(CONST_externallyStoredData1019, SPECIALWOUND_UPPERSPINE),
		map<string, short>::value_type(CONST_externallyStoredData1020, SPECIALWOUND_LOWERSPINE)
	};
	tankBodyParts = {
		map<short, string>::value_type(BODYPART_HEAD, CONST_externallyStoredData1021),
		map<short, string>::value_type(BODYPART_BODY, CONST_externallyStoredData1022),
		map<short, string>::value_type(BODYPART_ARM_RIGHT, CONST_externallyStoredData1023),
		map<short, string>::value_type(BODYPART_ARM_LEFT, CONST_externallyStoredData1024),
		map<short, string>::value_type(BODYPART_LEG_RIGHT, CONST_externallyStoredData1025),
		map<short, string>::value_type(BODYPART_LEG_LEFT, CONST_externallyStoredData1026)
	};
	animalBodyParts = {
		map<short, string>::value_type(BODYPART_HEAD, tag_head),
		map<short, string>::value_type(BODYPART_BODY, tag_body),
		map<short, string>::value_type(BODYPART_ARM_RIGHT, CONST_externallyStoredData1027),
		map<short, string>::value_type(BODYPART_ARM_LEFT, CONST_externallyStoredData1028),
		map<short, string>::value_type(BODYPART_LEG_RIGHT, CONST_externallyStoredData1029),
		map<short, string>::value_type(BODYPART_LEG_LEFT, CONST_externallyStoredData1030)
	};
	humanBodyParts = {
		map<short, string>::value_type(BODYPART_HEAD, tag_head),
		map<short, string>::value_type(BODYPART_BODY, tag_body),
		map<short, string>::value_type(BODYPART_ARM_RIGHT, CONST_externallyStoredData1031),
		map<short, string>::value_type(BODYPART_ARM_LEFT, CONST_externallyStoredData1032),
		map<short, string>::value_type(BODYPART_LEG_RIGHT, CONST_externallyStoredData1033),
		map<short, string>::value_type(BODYPART_LEG_LEFT, CONST_externallyStoredData1034)
	};
	supportsLiberalLaw = {
		map<short, string>::value_type(VIEW_GAY, CONST_externallyStoredData1035),
		map<short, string>::value_type(VIEW_DEATHPENALTY, CONST_externallyStoredData1036),
		map<short, string>::value_type(VIEW_TAXES, CONST_externallyStoredData1037),
		map<short, string>::value_type(VIEW_NUCLEARPOWER, CONST_externallyStoredData1038),
		map<short, string>::value_type(VIEW_ANIMALRESEARCH, CONST_externallyStoredData1039),
		map<short, string>::value_type(VIEW_POLICEBEHAVIOR, CONST_externallyStoredData1040),
		map<short, string>::value_type(VIEW_TORTURE, CONST_externallyStoredData1041),
		map<short, string>::value_type(VIEW_INTELLIGENCE, CONST_externallyStoredData1042),
		map<short, string>::value_type(VIEW_FREESPEECH, CONST_externallyStoredData1043),
		map<short, string>::value_type(VIEW_GENETICS, CONST_externallyStoredData1044),
		map<short, string>::value_type(VIEW_JUSTICES, CONST_externallyStoredData1045),
		map<short, string>::value_type(VIEW_SWEATSHOPS, CONST_externallyStoredData1046),
		map<short, string>::value_type(VIEW_POLLUTION, CONST_externallyStoredData1047),
		map<short, string>::value_type(VIEW_CORPORATECULTURE, CONST_externallyStoredData1048),
		map<short, string>::value_type(VIEW_CEOSALARY, CONST_externallyStoredData1049),
		map<short, string>::value_type(VIEW_WOMEN, CONST_externallyStoredData1050),
		map<short, string>::value_type(VIEW_CIVILRIGHTS, CONST_externallyStoredData1051),
		map<short, string>::value_type(VIEW_GUNCONTROL, CONST_externallyStoredData1052),
		map<short, string>::value_type(VIEW_MILITARY, CONST_externallyStoredData1053),
		map<short, string>::value_type(VIEW_LIBERALCRIMESQUAD, CONST_externallyStoredData1054),
		map<short, string>::value_type(VIEW_LIBERALCRIMESQUADPOS, CONST_externallyStoredData1055),
		map<short, string>::value_type(VIEW_CONSERVATIVECRIMESQUAD, CONST_externallyStoredData1056),
		map<short, string>::value_type(VIEW_PRISONS, CONST_externallyStoredData1057),
		map<short, string>::value_type(VIEW_AMRADIO, CONST_externallyStoredData1058),
		map<short, string>::value_type(VIEW_CABLENEWS, CONST_externallyStoredData1059),
		//map<short, string>::value_type( VIEW_POLITICALVIOLENCE, CONST_externallyStoredData1060)
	};
	winnerOfElection = {
		map<short, string>::value_type(ALIGN_ARCHCONSERVATIVE, CONST_externallyStoredData1061),
		map<short, string>::value_type(ALIGN_CONSERVATIVE, CONST_externallyStoredData1062),
		map<short, string>::value_type(ALIGN_MODERATE, CONST_externallyStoredData1063),
		map<short, string>::value_type(ALIGN_LIBERAL, CONST_externallyStoredData1064),
		map<short, string>::value_type(ALIGN_ELITELIBERAL, CONST_externallyStoredData1065),
		map<short, string>::value_type(ALIGN_STALINIST, CONST_externallyStoredData1066)
	};
	newsStories = {
		map<short, vector<string> >::value_type(NEWSSTORY_SQUAD_ESCAPED,
		{ CONST_externallyStoredData1067 }),
		map<short, vector<string> >::value_type(NEWSSTORY_SQUAD_FLEDATTACK,
		{ CONST_externallyStoredData1068 }),
		map<short, vector<string> >::value_type(NEWSSTORY_SQUAD_DEFENDED,
		{ CONST_externallyStoredData1069 }),
		map<short, vector<string> >::value_type(NEWSSTORY_SQUAD_BROKESIEGE,
		{ CONST_externallyStoredData1070 }),
		map<short, vector<string> >::value_type(NEWSSTORY_SQUAD_KILLED_SIEGEATTACK,
		{ CONST_externallyStoredData1071,
			CONST_externallyStoredData1072 }),
		map<short, vector<string> >::value_type(NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE,
		{ CONST_externallyStoredData1073,
			CONST_externallyStoredData1074 })
	};
	cityNames = {
		map<short, string>::value_type(SITE_CITY_SEATTLE,  CONST_externallyStoredData1075),
		map<short, string>::value_type(SITE_CITY_NEW_YORK,  CONST_externallyStoredData1076),
		map<short, string>::value_type(SITE_CITY_LOS_ANGELES,  CONST_externallyStoredData1077),
		map<short, string>::value_type(SITE_CITY_CHICAGO,  CONST_externallyStoredData1078),
		map<short, string>::value_type(SITE_CITY_DETROIT,  CONST_externallyStoredData1079),
		map<short, string>::value_type(SITE_CITY_ATLANTA,  CONST_externallyStoredData1080),
		map<short, string>::value_type(SITE_CITY_MIAMI,  CONST_externallyStoredData1081),
		map<short, string>::value_type(SITE_CITY_WASHINGTON_DC,  CONST_externallyStoredData1082),
	};
	carchaseObstacles = {
		map<short, vector<string> >::value_type(CARCHASE_OBSTACLE_FRUITSTAND,
		//LIMIT :------------------------------------:
		{ CONST_externallyStoredData1083,
			CONST_externallyStoredData1084,
			CONST_externallyStoredData1085 }),
		map<short, vector<string> >::value_type(CARCHASE_OBSTACLE_TRUCKPULLSOUT,
		//LIMIT :------------------------------------:
	{ CONST_externallyStoredData1086,
		CONST_externallyStoredData1087,
		CONST_externallyStoredData1088 }),
	map<short, vector<string> >::value_type(CARCHASE_OBSTACLE_CROSSTRAFFIC,
	//LIMIT :------------------------------------:
{ CONST_externallyStoredData1089,
	CONST_externallyStoredData1090,
	CONST_externallyStoredData1091 }),
map<short, vector<string> >::value_type(CARCHASE_OBSTACLE_CHILD,
//LIMIT :------------------------------------:
{ CONST_externallyStoredData1092,
	CONST_externallyStoredData1093,
	CONST_externallyStoredData1094 })
	};
	skillEnumToString = {
		map<short, string>::value_type(SKILL_HANDTOHAND,      CONST_externallyStoredData1095),
		map<short, string>::value_type(SKILL_KNIFE,           CONST_externallyStoredData1096),
		map<short, string>::value_type(SKILL_SWORD,           CONST_externallyStoredData1097),
		map<short, string>::value_type(SKILL_THROWING,        CONST_externallyStoredData1098),
		map<short, string>::value_type(SKILL_CLUB,            CONST_externallyStoredData1099),
		map<short, string>::value_type(SKILL_AXE,             CONST_externallyStoredData1100),
		map<short, string>::value_type(SKILL_PISTOL,          CONST_externallyStoredData1101),
		map<short, string>::value_type(SKILL_RIFLE,           CONST_externallyStoredData1102),
		map<short, string>::value_type(SKILL_HEAVYWEAPONS,    CONST_externallyStoredData1103),
		map<short, string>::value_type(SKILL_SHOTGUN,         CONST_externallyStoredData1104),
		map<short, string>::value_type(SKILL_SMG,             CONST_externallyStoredData1105),
		map<short, string>::value_type(SKILL_PERSUASION,      CONST_externallyStoredData1106),
		map<short, string>::value_type(SKILL_PSYCHOLOGY,      CONST_externallyStoredData1107),
		map<short, string>::value_type(SKILL_SECURITY,        CONST_externallyStoredData1108),
		map<short, string>::value_type(SKILL_DISGUISE,        CONST_externallyStoredData1109),
		map<short, string>::value_type(SKILL_COMPUTERS,       CONST_externallyStoredData1110),
		map<short, string>::value_type(SKILL_LAW,             CONST_externallyStoredData1111),
		map<short, string>::value_type(SKILL_TAILORING,       CONST_externallyStoredData1112),
		map<short, string>::value_type(SKILL_DRIVING,         CONST_externallyStoredData1113),
		map<short, string>::value_type(SKILL_WRITING,         CONST_externallyStoredData1114),
		map<short, string>::value_type(SKILL_MUSIC,           CONST_externallyStoredData1115),
		map<short, string>::value_type(SKILL_ART,             CONST_externallyStoredData1116),
		map<short, string>::value_type(SKILL_RELIGION,        CONST_externallyStoredData1117),
		map<short, string>::value_type(SKILL_SCIENCE,         CONST_externallyStoredData1118),
		map<short, string>::value_type(SKILL_BUSINESS,        CONST_externallyStoredData1119),
		map<short, string>::value_type(SKILL_STEALTH,         CONST_externallyStoredData1120),
		map<short, string>::value_type(SKILL_TEACHING,        CONST_externallyStoredData1121),
		map<short, string>::value_type(SKILL_STREETSENSE,     CONST_externallyStoredData1122),
		map<short, string>::value_type(SKILL_SEDUCTION,       CONST_externallyStoredData1123),
		map<short, string>::value_type(SKILL_FIRSTAID,        CONST_externallyStoredData1124),
		map<short, string>::value_type(SKILL_DODGE,           CONST_externallyStoredData1125)
	};
	attEnumToString = {
		map<short, string>::value_type(ATTRIBUTE_STRENGTH,       CONST_externallyStoredData1126),
		map<short, string>::value_type(ATTRIBUTE_AGILITY,        CONST_externallyStoredData1127),
		map<short, string>::value_type(ATTRIBUTE_WISDOM,         CONST_externallyStoredData1128),
		map<short, string>::value_type(ATTRIBUTE_INTELLIGENCE,   CONST_externallyStoredData1129),
		map<short, string>::value_type(ATTRIBUTE_HEART,          CONST_externallyStoredData1130),
		map<short, string>::value_type(ATTRIBUTE_HEALTH,         CONST_externallyStoredData1131),
		map<short, string>::value_type(ATTRIBUTE_CHARISMA,       CONST_externallyStoredData1132)
	};
	getAlignString = {
		map<short, string>::value_type(ALIGN_ARCHCONSERVATIVE,  CONST_externallyStoredData1133),
		map<short, string>::value_type(ALIGN_CONSERVATIVE,  CONST_externallyStoredData1134),
		map<short, string>::value_type(ALIGN_MODERATE,  CONST_externallyStoredData1135),
		map<short, string>::value_type(ALIGN_LIBERAL,  CONST_externallyStoredData1136),
		map<short, string>::value_type(ALIGN_ELITELIBERAL,  CONST_externallyStoredData1137),
		map<short, string>::value_type(ALIGN_STALINIST,  CONST_externallyStoredData1138)
	};
	musicList = {
		// titlemode.ogg or .mid - Also sprach Zarathustra, introduction by Richard Strauss
		map<short, string>::value_type(MUSIC_TITLEMODE, CONST_externallyStoredData1139), // load title mode music
																  // newgame.ogg or .mid- The Liberty Bell March by John Philip Sousa
		map<short, string>::value_type(MUSIC_NEWGAME, CONST_externallyStoredData1140), // load new game music
															  // basemode.ogg or .mid - The Stars and Stripes Forever by John Philip Sousa
		map<short, string>::value_type(MUSIC_BASEMODE, CONST_externallyStoredData1141), // load regular base mode music
																// siege.ogg or .mid- The Planets, 1st Movement CONST_externallyStoredData1142 by Gustav Holst
		map<short, string>::value_type(MUSIC_SIEGE, CONST_externallyStoredData1143), // load base mode while under siege music
														  // activate.ogg or .mid - Piano Sonata #11, 3rd Movement "Rondo Alla Turca" by Wolfgang Amadeus Mozart
		map<short, string>::value_type(MUSIC_ACTIVATE, CONST_externallyStoredData1144), // load activate Liberals music
																// sleepers.ogg or .mid - Toccata and Fugue in D Minor, BWV 565 by Johann Sebastian Bach
		map<short, string>::value_type(MUSIC_SLEEPERS, CONST_externallyStoredData1145), // load activate Sleepers music
																// stopevil.ogg or .mid - Hungarian Dance #5 by Johannes Brahms (based on the csardas "Bartfai emlek" by Bela Keler)
		map<short, string>::value_type(MUSIC_STOPEVIL, CONST_externallyStoredData1146), // load go forth to stop evil music
																// reviewmode.ogg or .mid - Symphony #94, 2nd Movement "Surprise Symphony" by Joseph Haydn
		map<short, string>::value_type(MUSIC_REVIEWMODE, CONST_externallyStoredData1147), // load review mode music
																	// liberalagenda.ogg or .mid - Beautiful Dreamer by Stephen Foster
		map<short, string>::value_type(MUSIC_LIBERALAGENDA, CONST_externallyStoredData1148), // load status of the Liberal agenda music
																		  // disbanded.ogg or .mid - La Cucaracha, a traditional Mexican folk song originally from Spain
		map<short, string>::value_type(MUSIC_DISBANDED, CONST_externallyStoredData1149), // load disbanded music
																  // finances.ogg or .mid - Minuet in G Major by Christian Petzold (falsely attributed to Johann Sebastian Bach until 1970)
		map<short, string>::value_type(MUSIC_FINANCES, CONST_externallyStoredData1150), // load finance report music
																// cartheft.ogg or .mid - The Ride of the Valkyries by Richard Wanger
		map<short, string>::value_type(MUSIC_CARTHEFT, CONST_externallyStoredData1151), // load car theft music
																// elections.ogg or .mid - Habanera from Carmen by Georges Bizet
		map<short, string>::value_type(MUSIC_ELECTIONS, CONST_externallyStoredData1152), // load elections music
																  // shopping.ogg or .mid - The Entertainer by Scott Joplin
		map<short, string>::value_type(MUSIC_SHOPPING, CONST_externallyStoredData1153), // load shopping music
																// sitemode.ogg or .mid - Dance of the Sugar Plum Fairy by Pyotr Ilyich Tchaikovsky
		map<short, string>::value_type(MUSIC_SITEMODE, CONST_externallyStoredData1154), // load site mode music
																// suspicious.ogg or .mid - Hall of the Mountain King by Edvard Grieg
		map<short, string>::value_type(MUSIC_SUSPICIOUS, tag_suspicious), // load suspicious music
																	// alarmed.ogg or .mid - 5th Symphony, 1st Movement by Ludwig van Beethoven
		map<short, string>::value_type(MUSIC_ALARMED, CONST_externallyStoredData1155), // load alarmed music
															  // heavycombat.ogg or .mid - 6th Symphony CONST_externallyStoredData1156, 4th Movement by Ludwig van Beethoven
		map<short, string>::value_type(MUSIC_HEAVYCOMBAT, CONST_externallyStoredData1157), // load massive Conservative response music
																	  // defense.ogg or .mid - Danse Macabre by Camille Saint-Saens
		map<short, string>::value_type(MUSIC_DEFENSE, CONST_externallyStoredData1158), // load escaping/engaging a siege music
															  // conquer.ogg or .mid - Infernal Galop / Can-Can from Orpheus in the Underworld by Jacques Offenbach
		map<short, string>::value_type(MUSIC_CONQUER, CONST_externallyStoredData1159), // load success in conquering a siege or safehouse or the CCS music
															  // carchase.ogg or .mid - The William Tell Overture by Gioacchino Antonio Rossini
		map<short, string>::value_type(MUSIC_CARCHASE, CONST_externallyStoredData1160), // load car chase music
																// footchase.ogg or .mid - The Maple Leaf Rag by Scott Joplin
		map<short, string>::value_type(MUSIC_FOOTCHASE, CONST_externallyStoredData1161), // load foot chase music
																  // InterrogationST.ogg or .mid - Night on Bald Mountain by Modest Mussorgsky
		map<short, string>::value_type(MUSIC_INTERROGATION, tag_interrogation), // load InterrogationST music
																		  // trial.ogg or .mid - Hungarian Rhapsody #2 by Franz Liszt
		map<short, string>::value_type(MUSIC_TRIAL, CONST_externallyStoredData1162), // load trial music
														  // recruiting.ogg or .mid - Dance of the Hours by Amilcare Ponchielli
		map<short, string>::value_type(MUSIC_RECRUITING, CONST_externallyStoredData1163), // load recruiting music
																	// dating.ogg or .mid - The Blue Danube Waltz by Johann Strauss Jr.
		map<short, string>::value_type(MUSIC_DATING, tag_dating), // load dating music
															// newspaper.ogg or .mid - Eine Kleine Nachtmusik, 1st Movement by Wolfgang Amadeus Mozart
		map<short, string>::value_type(MUSIC_NEWSPAPER, CONST_externallyStoredData1164), // load newspaper music
																  // lacops.ogg or .mid - The Flight of the Bumblebee by Nikolai Rimsky-Korsakov
		map<short, string>::value_type(MUSIC_LACOPS, CONST_externallyStoredData1165), // load LA cops beating black man and getting caught on video music
															// newscast.ogg or .mid - La Marseillaise, The French National Anthem by Claude Joseph Rouget de Lisle
		map<short, string>::value_type(MUSIC_NEWSCAST, CONST_externallyStoredData1166), // load newscast where smart liberal guest gets some words in edgewise music
																// glamshow.ogg or .mid - Das Deutschlandlied, The German National Anthem by Joseph Haydn
		map<short, string>::value_type(MUSIC_GLAMSHOW, CONST_externallyStoredData1167), // load glamorous TV show about lifestyles of the rich and famous music
																// anchor.ogg or .mid - I Am the Very Model of a Modern Major-General by Sir Arthur Seymour Sullivan
		map<short, string>::value_type(MUSIC_ANCHOR, CONST_externallyStoredData1168), // load handsome charismatic new Conservative cable news anchor music
															// abort.ogg or .mid - Tarantella Napoletana, a traditional Italian folk song from Naples
		map<short, string>::value_type(MUSIC_ABORT, CONST_externallyStoredData1169), // load failed partial birth abortion on trashy daytime talk show music
														  // victory.ogg or .mid - The Star-Spangled Banner, The U.S. National Anthem by John Stafford Smith
		map<short, string>::value_type(MUSIC_VICTORY, CONST_externallyStoredData1170), // load victory music
															  // defeat.ogg or .mid - Piano Sonata #2, 3rd Movement "Funeral March" by Frederic Francois Chopin
		map<short, string>::value_type(MUSIC_DEFEAT, CONST_externallyStoredData1171), // load defeat music
															// reagainified.ogg or .mid - Dixie, The Confederate National Anthem by Daniel Decatur Emmett
		map<short, string>::value_type(MUSIC_REAGANIFIED, CONST_externallyStoredData1172), // load Reaganified music
																	  // stalinized.ogg or .mid - The Soviet (and now Russian) National Anthem by Alexander Vasilyevich Alexandrov
		map<short, string>::value_type(MUSIC_STALINIZED, CONST_externallyStoredData1173) // load Stalinized music
	};
	ACTIVITY_TEACH_FIGHTING_DEFAULT =
		// this first block are creatures with All Weapon Skills, Martial Arts, Dodge, and First Aid
	{ CREATURE_ATHLETE,
		CREATURE_BOUNCER,
		CREATURE_COP,
		CREATURE_CCS_ARCHCONSERVATIVE,
		CREATURE_CCS_MOLOTOV,
		CREATURE_CCS_SNIPER,
		CREATURE_CCS_VIGILANTE,
		CREATURE_DEATHSQUAD,
		CREATURE_DOCTOR,
		CREATURE_FIREFIGHTER,
		CREATURE_GANGMEMBER,
		CREATURE_GANGUNIT,
		CREATURE_GUARDDOG,
		CREATURE_GENETIC,
		CREATURE_HARDENED_VETERAN,
		CREATURE_HICK,
		CREATURE_MARTIALARTIST,
		CREATURE_MERC,
		CREATURE_MILITARYOFFICER,
		CREATURE_MILITARYPOLICE,
		CREATURE_MUTANT,
		CREATURE_NURSE,
		CREATURE_PRISONGUARD,
		CREATURE_SEAL,
		CREATURE_SECURITYGUARD,
		CREATURE_SOLDIER,
		CREATURE_SWAT,
		CREATURE_TANK,
		CREATURE_VETERAN };
	ACTIVITY_TEACH_COVERT_DEFAULT =
		// this second block are creatures with Computers, Security, Stealth, Disguise, Tailoring, Seduction, Psychology, & Driving
	{ CREATURE_ACTOR,
		CREATURE_AGENT,
		CREATURE_AMATEURMAGICIAN,
		CREATURE_BIKER,
		CREATURE_BUM,
		CREATURE_CONSTRUCTIONWORKER,
		CREATURE_CRACKHEAD,
		CREATURE_EDUCATOR,
		CREATURE_FASHIONDESIGNER,
		CREATURE_GARBAGEMAN,
		CREATURE_HSDROPOUT,
		CREATURE_LOCKSMITH,
		CREATURE_MAILMAN,
		CREATURE_PLUMBER,
		CREATURE_PRISONER,
		CREATURE_PROGRAMMER,
		CREATURE_PROSTITUTE,
		CREATURE_PSYCHOLOGIST,
		CREATURE_SECRET_SERVICE,
		CREATURE_SEWERWORKER,
		CREATURE_TAXIDRIVER,
		CREATURE_THIEF,
		CREATURE_TRUCKER,
		CREATURE_WORKER_FACTORY_CHILD,
		CREATURE_WORKER_SERVANT,
		CREATURE_WORKER_SWEATSHOP };
	ACTIVITY_TEACH_POLITICS_DEFAULT =
		// this third block are creatures with Writing, Persuasion, Law, Street Sense, Science, Religion, Business, Music, & Art
	{ CREATURE_AUTHOR,
		CREATURE_BANK_MANAGER,
		CREATURE_BANK_TELLER,
		CREATURE_CAMERAMAN,
		CREATURE_CARSALESMAN,
		CREATURE_CHEF,
		CREATURE_CLERK,
		CREATURE_COLLEGESTUDENT,
		CREATURE_CORPORATE_CEO,
		CREATURE_CORPORATE_MANAGER,
		CREATURE_CRITIC_ART,
		CREATURE_CRITIC_MUSIC,
		CREATURE_DANCER,
		CREATURE_ENGINEER,
		CREATURE_FASTFOODWORKER,
		CREATURE_BAKER,
		CREATURE_BARISTA,
		CREATURE_BARTENDER,
		CREATURE_FOOTBALLCOACH,
		CREATURE_HAIRSTYLIST,
		CREATURE_HIPPIE,
		CREATURE_JOURNALIST,
		CREATURE_JUDGE_CONSERVATIVE,
		CREATURE_JUDGE_LIBERAL,
		CREATURE_JUROR,
		CREATURE_LANDLORD,
		CREATURE_LAWYER,
		CREATURE_MATHEMATICIAN,
		CREATURE_MUSICIAN,
		CREATURE_NEWSANCHOR,
		CREATURE_NUN,
		CREATURE_OFFICEWORKER,
		CREATURE_PAINTER,
		CREATURE_PHOTOGRAPHER,
		CREATURE_POLITICALACTIVIST,
		CREATURE_POLITICIAN,
		CREATURE_PRIEST,
		CREATURE_RADIOPERSONALITY,
		CREATURE_RETIREE,
		CREATURE_SCIENTIST_EMINENT,
		CREATURE_SCIENTIST_LABTECH,
		CREATURE_SCULPTOR,
		CREATURE_SOCIALITE,
		CREATURE_TEACHER,
		CREATURE_TEENAGER,
		CREATURE_TELEMARKETER,
		CREATURE_WORKER_FACTORY_NONUNION,
		CREATURE_WORKER_FACTORY_UNION,
		CREATURE_WORKER_JANITOR,
		CREATURE_WORKER_SECRETARY,
		CREATURE_YOGAINSTRUCTOR };
	processTheUnprocessed(helpTopicUnprocessed, helpTopics, string_to_activity);
	processTheUnprocessed(conservativeLegalArgumentUnprocessed, conservativeLegalArgument, string_to_law);
	processTheUnprocessed(youAreStupidTalkAboutIssuesUnprocessed, youAreStupidTalkAboutIssues, string_to_law);
	processTheUnprocessed(issueTooLiberalUnprocessed, issueTooLiberal, string_to_law);
	processTheUnprocessed(issueEventStringUnprocessed, issueEventString, string_to_view);
	processTheUnprocessed(conservatiseLawUnprocessed, conservatiseLaw, string_to_law);
	processTheUnprocessed(liberalizeLawUnprocessed, liberalizeLaw, string_to_law);
	processTheUnprocessed(discussIssuesUnprocessed, discussIssues, string_to_view);
	processTheUnprocessed(discussesIssuesUnprocessed, discussesIssues, string_to_view);
	processTheUnprocessed(talkAboutTheIssuesUnprocessed, talkAboutTheIssues, string_to_law);
	processTheUnprocessed(endgameLawStringsUnprocessed, endgameLawStrings, string_to_law);
	for (string str : state_biases_Unprocessed) {
		state_biases.push_back(atoi(str.data()));
	}
	site_tile_list = {
		map<string, short>::value_type(CONST_externallyStoredData1174, SITEBLOCK_EXIT),
		map<string, short>::value_type(CONST_externallyStoredData1175, SITEBLOCK_BLOCK),
		map<string, short>::value_type(CONST_externallyStoredData1176, SITEBLOCK_DOOR),
		map<string, short>::value_type(CONST_externallyStoredData1177, SITEBLOCK_KNOWN),
		map<string, short>::value_type(tag_LOOT, SITEBLOCK_LOOT),
		map<string, short>::value_type(CONST_externallyStoredData1178, SITEBLOCK_LOCKED),
		map<string, short>::value_type(CONST_externallyStoredData1179, SITEBLOCK_KLOCK),
		map<string, short>::value_type(CONST_externallyStoredData1180, SITEBLOCK_CLOCK),
		map<string, short>::value_type(CONST_externallyStoredData1181, SITEBLOCK_RESTRICTED),
		map<string, short>::value_type(CONST_externallyStoredData1182, SITEBLOCK_BLOODY),
		map<string, short>::value_type(CONST_externallyStoredData1183, SITEBLOCK_BLOODY2),
		map<string, short>::value_type(CONST_externallyStoredData1184, SITEBLOCK_GRASSY),
		map<string, short>::value_type(CONST_externallyStoredData1185, SITEBLOCK_OUTDOOR),
		map<string, short>::value_type(CONST_externallyStoredData1186, SITEBLOCK_DEBRIS),
		map<string, short>::value_type(CONST_externallyStoredData1187, SITEBLOCK_GRAFFITI),
		map<string, short>::value_type(CONST_externallyStoredData1188, SITEBLOCK_GRAFFITI_CCS),
		map<string, short>::value_type(CONST_externallyStoredData1189, SITEBLOCK_GRAFFITI_OTHER),
		map<string, short>::value_type(CONST_externallyStoredData1190, SITEBLOCK_FIRE_START),
		map<string, short>::value_type(CONST_externallyStoredData1191, SITEBLOCK_FIRE_PEAK),
		map<string, short>::value_type(CONST_externallyStoredData1192, SITEBLOCK_FIRE_END),
		map<string, short>::value_type(CONST_externallyStoredData1193, 0),
	};
	rejectionReasons = {
		map<int, vector<string> >::value_type(REJECTED_CCS, rejectedByCCS),
	   map<int, vector<string> >::value_type(REJECTED_NUDE, rejectedBecauseNude),
	   map<int, vector<string> >::value_type(REJECTED_UNDERAGE, rejectedBecauseUnderage),
	   map<int, vector<string> >::value_type(REJECTED_FEMALE, rejectedBecauseFemale),
	   map<int, vector<string> >::value_type(REJECTED_FEMALEISH, rejectedBecauseFemaleish),
	   map<int, vector<string> >::value_type(REJECTED_DRESSCODE, rejectedBecauseDresscode),
	   map<int, vector<string> >::value_type(REJECTED_BLOODYCLOTHES, rejectedBecauseBloodyClothes),
	   map<int, vector<string> >::value_type(REJECTED_DAMAGEDCLOTHES, rejectedBecauseDamagedClothes),
	   map<int, vector<string> >::value_type(REJECTED_SECONDRATECLOTHES, rejectedBecauseSecondRateClothes),
	   map<int, vector<string> >::value_type(REJECTED_WEAPONS, rejectedBecauseWeapons),
	   map<int, vector<string> >::value_type(REJECTED_GUESTLIST, rejectedBecauseGuestList),
	};
	caseRejectionReasons = {
		map<int, vector<string> >::value_type(REJECTED_UNDERAGE, caseREJECTED_UNDERAGE),
	   map<int, vector<string> >::value_type(REJECTED_DRESSCODE, caseREJECTED_DRESSCODE),
	   map<int, vector<string> >::value_type(REJECTED_SMELLFUNNY, caseREJECTED_SMELLFUNNY),
	   map<int, vector<string> >::value_type(REJECTED_BLOODYCLOTHES, caseREJECTED_BLOODYCLOTHES),
	   map<int, vector<string> >::value_type(REJECTED_DAMAGEDCLOTHES, caseREJECTED_DAMAGEDCLOTHES),
	   map<int, vector<string> >::value_type(REJECTED_SECONDRATECLOTHES, caseREJECTED_SECONDRATECLOTHES),
	};
	return true;
}


void processTheUnprocessed(vector<string> &unprocessed, map<short, vector<string> > &processed, map<string, short> string_to_short) {
	int nextHelp = -2;
	vector<string> nextHelpStrings;
	for (string str : unprocessed) {
		if (string_to_short.count(str)) {
			if (nextHelp != -2) {
				processed.insert_or_assign(nextHelp, nextHelpStrings);
			}
			nextHelp = string_to_short[str];
			nextHelpStrings.clear();
		}
		else {
			nextHelpStrings.push_back(str);
		}
	}
	processed.insert_or_assign(nextHelp, nextHelpStrings);
}
void processTheUnprocessed(vector<string> &unprocessed, map<short, string> &processed, map<string, short> string_to_short) {
	int nextHelp = -2;
	string nextHelpString;
	for (string str : unprocessed) {
		if (string_to_short.count(str)) {
			if (nextHelp != -2) {
				processed.insert_or_assign(nextHelp, nextHelpString);
			}
			nextHelp = string_to_short[str];
			//nextHelpStrings.clear();
		}
		else {
			nextHelpString = str;
		}
	}
	processed.insert_or_assign(nextHelp, nextHelpString);
}
