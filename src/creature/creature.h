


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
	//static int roll_check(int skill);
	int seethroughdisguise;
	int seethroughstealth;
	bool istalkreceptive;
	bool iskidnap_resistant;
	bool isreports_to_police;

public:
	const NameAndAlignment getNameAndAlignment() const { return NameAndAlignment(CreatureBools(exists, alive, enemy()), CreatureInts(align, type, blood), name); }
	const CreatureHealth getCreatureHealth()  const { return CreatureHealth(getNameAndAlignment(), animalgloss, wound, special); }
	const CreatureJustice getCreatureJustice()  const { return CreatureJustice(propername, name, get_type_name(), deathpenalty, location, sentence, crimes_suspected, juice, align); }
	const CreatureBio getCreatureBio() const { return CreatureBio(birthday_month, birthday_day, age, gender_conservative, gender_liberal); }
	const CreatureInventory getCreatureInventory() const { return CreatureInventory(get_weapon_string(0), get_armor_string(true));  }
	const CreatureCar getCreatureCar() const { return CreatureCar(pref_carid, carid, pref_is_driver, is_driver); }
	const ListOfCreatureSkills getListOfCreatureSkills() const {
		int skill_attribute[SKILLNUM];
		for (int i = 0; i < SKILLNUM; i++) {
			skill_attribute[i] = skill_cap(i);
		}
		return ListOfCreatureSkills(skills, skill_experience, skill_attribute);
	};

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

	DeprecatedCreature* prisoner;

	DeprecatedCreature() { creatureinit(); }
	DeprecatedCreature(const DeprecatedCreature& org) { copy(org); }
	DeprecatedCreature& operator=(const DeprecatedCreature& rhs);
	~DeprecatedCreature();
	explicit DeprecatedCreature(const std::string& inputXml);

	/* are the characters close enough in age to date? */
	bool can_date(const int aage, const char aanimalgloss) const;

	bool exists;
	bool alive;
	bool enemy() const;

	int align;
	int type;
	int blood;

	char name[CREATURE_NAMELEN];



	void set_attribute(int attribute, int amount) { attributes[attribute] = MIN(amount, MAXATTRIBUTE); }
	void adjust_attribute(int attribute, int amount) { set_attribute(attribute, attributes[attribute] + amount); }
	void set_skill(int skill, int amount) { skills[skill] = MIN(amount, MAXATTRIBUTE); }

	void die();
	void train(int trainedskill, int experience, int upto = MAXATTRIBUTE);
	void skill_up();

	bool reload(bool wasteful);
	bool ready_another_throwing_weapon();

	void stop_hauling_me();
	void creatureinit();

	int get_disguise_difficulty() const;
	int	get_stealth_difficulty() const;
	int get_true_attribute(int attribute) const;
	int get_attribute(int attribute, bool use_juice) const;
	int attribute_roll(int attribute) const;
	bool attribute_check(int attribute, int difficulty) const;
	int get_skill(int skill) const { return MIN(skills[skill], MAXATTRIBUTE); }
	int skill_roll(int skill) const;
	bool skill_check(int skill, int difficulty) const;
	int get_weapon_skill() const;
	int get_skill_ip(int skill) const { return skill_experience[skill]; }
	std::string get_type_name() const; // this function is implemented inline in creaturetype.h (can't do it here since CreatureType has to be defined after DeprecatedCreature)
	
	bool is_armed() const { return weapon; }
	bool is_naked() const { return !armor; }
	bool will_do_ranged_attack(bool force_ranged, bool force_melee) const; //force_melee is likely unnecessary. -XML
	bool can_reload() const;
	bool will_reload(bool force_ranged, bool force_melee) const;
	int count_clips() const;
	int count_weapons() const;
	bool weapon_is_concealed() const { return is_armed() && get_armor().conceals_weaponsize(weapon->get_size()); }
	string get_weapon_string(int subtype) const;
	string get_armor_string(bool fullname) const { return get_armor().equip_title(fullname); }
	string showXml() const;
	bool is_active_liberal() const;
	bool is_imprisoned() const;
	bool is_lcs_sleeper() const;
	bool canwalk() const;
	//int attval(int a,char usejuice=1);
	/* are they interested in talking about the issues? */
	bool talkreceptive() const;
	/* rolls up a proper name for a creature */
	void namecreature();
	/* can turn the tables on datenapping */
	bool kidnap_resistant() const;
	bool reports_to_police() const;
	/* returns the creature's maximum level in the given skill */
	int skill_cap(int skill) const { return get_attribute(get_associated_attribute((CreatureSkill)skill), true); }
	const char* heshe(bool capitalize = false) const;
	const char* hisher(bool capitalize = false) const;
	const char* himher(bool capitalize = false) const;

	bool dontname;
	char propername[CREATURE_NAMELEN];
	char gender_conservative;
	char gender_liberal;

	std::string type_idname;
	float infiltration;
	char animalgloss;
	char forceinc;
	bool has_thrown_weapon;

	int age;
	int birthday_month;
	int birthday_day;
	
	int sentence;
	char confessions;
	char deathpenalty;

	int squadid;//REMEMBER, THIS IS ID NUMBER, NOT ARRAY INDEX
	int specialattack;
	int clinic;
	int dating;
	int hiding;
	int trainingtime;
	int trainingsubject;
	int joindays;
	int deathdays;
	int id;
	int hireid;
	int meetings;
	int stunned;
	int money;
	int juice;
	int income;
	int heat;
	int location;
	int worklocation;
	int base;
	int flag;

	int pref_carid;
	int carid;
	char cantbluff;
	char is_driver;
	char pref_is_driver;

	unsigned char wound[BODYPARTNUM];
	char special[SPECIALWOUNDNUM];

	int crimes_suspected[LAWFLAGNUM];
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
string get_age_string(const CreatureBio bio, const char animalgloss);
/* rolls up a creature's stats and equipment */
void makecreature(DeprecatedCreature &cr, short type);
/* ensures that the creature's work location is appropriate to its type */
int verifyworklocation(const int type, const int worklocation);
/* turns a creature into a conservative */
void conservatise(DeprecatedCreature &cr);
/* turns a creature into a liberal */
void liberalize(DeprecatedCreature &cr, bool rename = true);
/* gives a cover name to CCS members */
void nameCCSMember(DeprecatedCreature &cr);
//end of ripped part


#endif