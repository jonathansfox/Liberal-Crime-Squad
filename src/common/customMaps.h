#pragma once
#include <map>
typedef std::map< int, string > StringPairs;
enum bodypartBreakType {
	HEAVY, POKE, BREAK, ANY
};

typedef struct  {
	bodypartBreakType breakType;
	string shot;
	string burned;
	string torn;
	string cut;
	string defaultString;
	vector<SpecialWounds> specialWounds;
	int maxBlood;
} special_wound_structure;

special_wound_structure customWound(bodypartBreakType, string, string, string, string, string, vector<SpecialWounds>, int);


typedef struct {
	vector<vector<string>> *super_collection;
	vector<string> *collection;
	int dimensions;
	string fileName;
	bool superCollection;
} file_and_text_collection;

file_and_text_collection customText(vector<string>  *, string );
file_and_text_collection customText(vector<vector<string>> *, string , int );

struct stringConnectedToView {
	const string aboveFifty;
	const string belowFifty;
	const string belowFiftyLiberalLaw;
	const string belowFiftyEliteLiberalLaw;
	stringConnectedToView() : stringConnectedToView("","") {}
	stringConnectedToView(string aboveFifty_, string belowFifty_) : aboveFifty(aboveFifty_), belowFifty(belowFifty_), belowFiftyLiberalLaw(belowFifty_), belowFiftyEliteLiberalLaw(belowFifty_) {}
	stringConnectedToView(string aboveFifty_, string belowFifty_, string belowFiftyEliteLiberalLaw_) : aboveFifty(aboveFifty_), belowFifty(belowFifty_), belowFiftyLiberalLaw(belowFifty_), belowFiftyEliteLiberalLaw(belowFiftyEliteLiberalLaw_) {}
	stringConnectedToView(string aboveFifty_, string belowFifty_, string belowFiftyEliteLiberalLaw_, string belowFiftyLiberalLaw_) : aboveFifty(aboveFifty_), belowFifty(belowFifty_), belowFiftyLiberalLaw(belowFiftyLiberalLaw_), belowFiftyEliteLiberalLaw(belowFiftyEliteLiberalLaw_) {}
};

enum activityMenuChecks // these codes are used to add special checks to what you're allowed to pick in activity menus
{
	ACTIVITIY_MENU_CHECK_NONE,
	ACTIVITIY_MENU_CHECK_PRESS,
	ACTIVITIY_MENU_CHECK_AGE,
	ACTIVITIY_MENU_CHECK_CAN_WALK,
	ACTIVITIY_MENU_CHECK_WHEELCHAIR,
	ACTIVITIY_MENU_CHECK_CAN_AUGMENT
};
// this data struct is for activities, it relates to their info text and a couple of other things to avoid needing big switches in the code
	struct data_activity
	{
		bool show_name;
		char key;
		CreatureSkill skill;
		string line;
		string line2;
		string line3;

		data_activity(char _key, bool _show_name, string _line0, string _line1 = "", string _line2 = "", CreatureSkill _skill = SKILLNUM) : key(_key), show_name(_show_name), skill(_skill), line(_line0), line2(_line1), line3(_line2) {}
		data_activity() : data_activity('x', false, "") {}


		string lineAttempt(int row, Creature *cr)
		{
			if (skill == SKILLNUM) {
				string output = row == 0 ? line : row == 1? line2: line3;
				return output;
			}
			else
			{
				if (row > 0) return "";
				if (cr->get_skill(skill) >= 8) return line3;
				if (cr->get_skill(skill) >= 4) return line2;
				return line;
			}
		}
	};
	typedef std::map<Activity, data_activity> ActivityToData;
typedef std::map< Views, stringConnectedToView > ViewAndStrings;
typedef std::map< Activity, CreatureSkill> ActivityAndSkill;
//typedef std::map< Activity, string> ActivityToString;
struct ActivityAndString {
	int i;
	Activity activity;
	string str;
	string str2;
	string str3;
	activityMenuChecks check;
	CreatureSkill skill;
	ActivityAndString(Activity activity_, string str_) : i(0), activity(activity_), str(str_), skill(SKILLNUM) {}
	ActivityAndString(int i_, Activity activity_, string str_) : i(i_), activity(activity_), str(str_), skill(SKILLNUM){}
	ActivityAndString(int i_, Activity activity_, string str_, activityMenuChecks check_) : i(i_), activity(activity_), str(str_), skill(SKILLNUM), check(check_) {}
	ActivityAndString(int i_, Activity activity_, string str_, string str2_, string str3_, CreatureSkill skill_) : i(i_), activity(activity_), str(str_), str2(str2_), str3(str3_), skill(skill_) {}
	
};
typedef std::map<char, vector<ActivityAndString>> charToVector;
struct ChangeOfOpinion
{
	Views view;
	int x, y, z;
	ChangeOfOpinion(Views view_, int x_, int y_, int z_) : view(view_), x(x_), y(y_), z(z_) { }
};
struct activityData
{
	const char* msgString;
	CheckDifficulty difficulty;
	int juiceval;
	Lawflags crime;
	vector<ChangeOfOpinion> opinion;
	vector<string> lootType;
	activityData(const char* msgString_, CheckDifficulty difficulty_, int juiceval_, Lawflags crime_, vector<ChangeOfOpinion> opinion_, vector<string> lootType_) : msgString(msgString_), difficulty(difficulty_), juiceval(juiceval_), crime(crime_), opinion(opinion_), lootType(lootType_) { }
};

struct recruitData
{
	CreatureTypes type;
	char* name;
	int difficulty;
	recruitData(CreatureTypes type_, char* name_, int difficulty_) : type(type_), name(name_), difficulty(difficulty_) { }
};

void displayDifficulty(int difficulty);