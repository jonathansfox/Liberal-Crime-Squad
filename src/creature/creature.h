


#ifndef CREATURE_H
#define CREATURE_H0

#include "newcreature.h"

class DeprecatedCreature
{
private:
	class Augmentation augmentations[AUGMENTATIONNUM];
	static Weapon& weapon_none();
	static Armor& armor_none();
	Weapon* weapon;
	Armor* armor;

	void copy(const DeprecatedCreature& org);
	int attributes[ATTNUM];
	int skills[SKILLNUM];
	int skill_experience[SKILLNUM];
	static int roll_check(int skill);
	int seethroughdisguise;
	int seethroughstealth;
	bool istalkreceptive;
	bool iskidnap_resistant;
	bool isreports_to_police;

public:
	NameAndAlignment getNameAndAlignment() { return NameAndAlignment(CreatureBools(exists, alive, enemy()), CreatureInts(align, type, blood), name); }
	Augmentation & get_augmentation(int aug_num) { return augmentations[aug_num]; }
	deque<Weapon*> extra_throwing_weapons;
	deque<Clip*> clips;
	Weapon& get_weapon() const { return is_armed() ? *weapon : weapon_none(); }
	Armor& get_armor() const { return is_naked() ? armor_none() : *armor; }
	bool take_clips(Item& clip, int number);
	bool take_clips(Clip& clip, int number);
	bool take_clips(const ClipType& ct, int number);
	void give_weapon(Weapon& w, vector<Item*>* lootpile);
	void give_weapon(const WeaponType& wt, vector<Item*>* lootpile);
	void drop_weapon(vector<Item*>* lootpile);
	void drop_weapons_and_clips(vector<Item*>* lootpile);
	void give_armor(Armor& a, vector<Item*>* lootpile);
	void give_armor(const int at, vector<Item*>* lootpile);
	void strip(vector<Item*>* lootpile);
	ActivityST activity;

	int get_disguise_difficulty();
	int	get_stealth_difficulty();
	void set_attribute(int attribute, int amount) { attributes[attribute] = MIN(amount, MAXATTRIBUTE); }
	int get_true_attribute(int attribute) const;
	int get_attribute(int attribute, bool use_juice) const;
	void adjust_attribute(int attribute, int amount) { set_attribute(attribute, attributes[attribute] + amount); }
	int attribute_roll(int attribute) const;
	bool attribute_check(int attribute, int difficulty) const;
	void set_skill(int skill, int amount) { skills[skill] = MIN(amount, MAXATTRIBUTE); }
	int get_skill(int skill) const { return MIN(skills[skill], MAXATTRIBUTE); }
	int skill_roll(int skill) const;
	bool skill_check(int skill, int difficulty) const;
	int get_weapon_skill() const;
	char name[CREATURE_NAMELEN];
	char propername[CREATURE_NAMELEN];
	char gender_conservative;
	char gender_liberal;
	int squadid;//REMEMBER, THIS IS ID NUMBER, NOT ARRAY INDEX
	int age;
	int birthday_month;
	int birthday_day;
	bool exists;
	int align;
	bool alive;
	void die();
	int type;
	std::string type_idname;
	float infiltration;
	char animalgloss;
	int specialattack;
	int clinic;
	int dating;
	int hiding;
	int trainingtime;
	int trainingsubject;
	DeprecatedCreature* prisoner;
	int sentence;
	char confessions;
	char deathpenalty;
	int joindays;
	int deathdays;
	int id;
	int hireid;
	int meetings;
	char forceinc;
	void train(int trainedskill, int experience, int upto = MAXATTRIBUTE);
	void skill_up();
	int get_skill_ip(int skill) const { return skill_experience[skill]; }
	std::string get_type_name() const; // this function is implemented inline in creaturetype.h (can't do it here since CreatureType has to be defined after DeprecatedCreature)
	bool enemy() const;
	int stunned;
	bool has_thrown_weapon;
	bool is_armed() const { return weapon; }
	bool is_naked() const { return !armor; }
	bool will_do_ranged_attack(bool force_ranged, bool force_melee) const; //force_melee is likely unnecessary. -XML
	bool can_reload() const;
	bool will_reload(bool force_ranged, bool force_melee) const;
	bool reload(bool wasteful);
	bool ready_another_throwing_weapon();
	int count_clips() const;
	int count_weapons() const;
	bool weapon_is_concealed() const { return is_armed() && get_armor().conceals_weaponsize(weapon->get_size()); }
	string get_weapon_string(int subtype) const;
	string get_armor_string(bool fullname) const { return get_armor().equip_title(fullname); }
	int money;
	int juice;
	int income;
	unsigned char wound[BODYPARTNUM];
	int blood;
	char special[SPECIALWOUNDNUM];
	//int crimes_committed[LAWFLAGNUM];
	int crimes_suspected[LAWFLAGNUM];
	//int crimes_convicted[LAWFLAGNUM];
	int heat;
	int location;
	int worklocation;
	char cantbluff;
	int base;
	int carid;
	char is_driver;
	int pref_carid;
	char pref_is_driver;
	int flag;
	void stop_hauling_me();
	void creatureinit();
	DeprecatedCreature() { creatureinit(); }
	DeprecatedCreature(const DeprecatedCreature& org) { copy(org); }
	DeprecatedCreature& operator=(const DeprecatedCreature& rhs);
	~DeprecatedCreature();
	explicit DeprecatedCreature(const std::string& inputXml);
	string showXml() const;
	bool is_active_liberal() const;
	bool is_imprisoned() const;
	bool is_lcs_sleeper() const;
	bool canwalk() const;
	//int attval(int a,char usejuice=1);
	/* are they interested in talking about the issues? */
	bool talkreceptive() const;
	/* are the characters close enough in age to date? */
	bool can_date(const DeprecatedCreature &a) const;
	/* rolls up a proper name for a creature */
	void namecreature();
	bool dontname;
	/* can turn the tables on datenapping */
	bool kidnap_resistant() const;
	bool reports_to_police() const;
	/* returns the creature's maximum level in the given skill */
	int skill_cap(int skill, bool use_juice) const { return get_attribute(get_associated_attribute((CreatureSkill)skill), use_juice); }
	const char* heshe(bool capitalize = false) const;
	const char* hisher(bool capitalize = false) const;
	const char* himher(bool capitalize = false) const;
};

// this data struct is for activities, it relates to their info text and a couple of other things to avoid needing big switches in the code
struct Data_Activity
{
	bool show_name;
	char key;
	CreatureSkill skill;
	string line;
	string line2;
	string line3;
	Data_Activity(char _key, bool _show_name, string _line0, string _line1 = blankString, string _line2 = blankString, CreatureSkill _skill = SKILLNUM) : key(_key), show_name(_show_name), skill(_skill), line(_line0), line2(_line1), line3(_line2) {}
	Data_Activity() : Data_Activity('x', false, blankString) {}
	string lineAttempt(int row, DeprecatedCreature *cr)
	{
		if (skill == SKILLNUM) {
			string output = row == 0 ? line : row == 1 ? line2 : line3;
			return output;
		}
		else
		{
			if (row > 0) return blankString;
			if (cr->get_skill(skill) >= 8) return line3;
			if (cr->get_skill(skill) >= 4) return line2;
			return line;
		}
	}
};

enum UniqueCreatureData
{
	UNIQUECREATURE_ALIVE,
	UNIQUECREATURE_DEAD,
	UNIQUECREATURE_LIBERAL
};
class UniqueCreatures
{
private:
	DeprecatedCreature CEO_;
	int CEO_ID;
	DeprecatedCreature Pres_;
	int Pres_ID;
public:
	int CEO_state;
	int Pres_state;
	UniqueCreatures() : CEO_ID(-1), Pres_ID(-1) { }
	explicit UniqueCreatures(const std::string& inputXml);
	string showXml() const;
	void newCEO();
	void newPresident();
	DeprecatedCreature& CEO() { if (CEO_ID == -1) newCEO(); return CEO_; }
	DeprecatedCreature& President() { if (Pres_ID == -1) newPresident(); return Pres_; }
	void initialize() { newCEO(); newPresident(); }
};


// brutally ripped from includes.h --Schmel924
//From here up to void nameCCSMember(DeprecatedCreature &cr);
/*
implementations should be in creature.cpp
*/
// Add an age estimate to a person's name
void add_age(DeprecatedCreature& person);
/* rolls up a creature's stats and equipment */
void makecreature(DeprecatedCreature &cr, short type);
/* ensures that the creature's work location is appropriate to its type */
bool verifyworklocation(DeprecatedCreature &cr, char test_location = -1, char test_type = -1);
/* turns a creature into a conservative */
void conservatise(DeprecatedCreature &cr);
/* turns a creature into a liberal */
void liberalize(DeprecatedCreature &cr, bool rename = true);
/* gives a cover name to CCS members */
void nameCCSMember(DeprecatedCreature &cr);
//end of ripped part


#endif