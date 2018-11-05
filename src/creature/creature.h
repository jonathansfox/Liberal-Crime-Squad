


#ifndef CREATURE_H
#define CREATURE_H0

#include "newcreature.h"
struct Deprecatedrecruitst;
class AttackInfliction {
public:
	AttackInfliction(const bool, const int, const int, const attackst);
	const bool sneak_attack;
	const int aroll;
	const int droll;
	const attackst attack_used;
};
class AttackSeverity {
public:
	AttackSeverity::AttackSeverity(const int, const int, const int, const int);
	const int damamount;
	const int damagearmor;
	const int severtype;
	const int hit_location;

};
enum UnlockAttempt {
	UNLOCKED,
	LOUD_FAILURE,
	NEVERMIND
};
struct Deprecatedsquadst;

struct damageDetails {
	const int mod;
	const int hit_location;
	const int extraarmor;
	const char armorpiercing;
	damageDetails(int _mod, int _hit_location, int _extraarmor, char _armorpiercing) : mod(_mod), hit_location(_hit_location), extraarmor(_extraarmor), armorpiercing(_armorpiercing) {};
};

struct Deprecateddatest;

enum LOOP_CONTINUATION {
	RETURN_ZERO,
	RETURN_ONE,
	REPEAT
};
class DeprecatedCreature
{
public:
	const NameAndAlignment getNameAndAlignment() const { return NameAndAlignment(CreatureBools(exists, alive, enemy()), CreatureInts(align, type, blood), name); }
	const CreatureHealth getCreatureHealth()  const { return CreatureHealth(getNameAndAlignment(), animalgloss, wound, special); }
	const CreatureJustice getCreatureJustice()  const { return CreatureJustice(PartialCreatureJustice(deathpenalty, location, sentence, juice, align), propername, name, get_type_name(), crimes_suspected); }
	const CreatureBio getCreatureBio() const { return CreatureBio(birthday_month, birthday_day, age, gender_conservative, gender_liberal); }
	const CreatureInventory getCreatureInventory() const { return CreatureInventory(get_weapon_string(0), get_armor_string(true));  }
	const CreatureCar getCreatureCar() const { return CreatureCar(pref_carid, carid, pref_is_driver, is_driver); }
	const CantBluffAnimal getCantBluffAnimal() const { return CantBluffAnimal(cantbluff, animalgloss); }
	const ListOfCreatureSkills getListOfCreatureSkills() const {
		int skill_attribute[SKILLNUM];
		for (int i = 0; i < SKILLNUM; i++) {
			skill_attribute[i] = skill_cap(i);
		}
		return ListOfCreatureSkills(skills, skill_experience, skill_attribute);
	};
	const CreatureAttributeList getCreatureAttributeList() const {
		int attribute_list[ATTNUM];
		int attribute_juice_list[ATTNUM];
		for (int i = 0; i < ATTNUM; i++) {
			attribute_list[i] = get_attribute(i, false);
			attribute_juice_list[i] = get_attribute(i, true);
		}
		return CreatureAttributeList(attribute_list, attribute_juice_list);
	}

	DeprecatedCreature() { creatureinit(); }
	DeprecatedCreature(const DeprecatedCreature& org) { copy(org); }
	DeprecatedCreature& operator=(const DeprecatedCreature& rhs);
	~DeprecatedCreature();
	explicit DeprecatedCreature(const std::string& inputXml);

	/* are the characters close enough in age to date? */
	bool can_date(const int aage, const char aanimalgloss) const;

	bool enemy() const;

	void criminalize(short);

	/* full screen character sheet */
	void printliberalstats();
	void printCreatureSkills();
	void printCreatureAttributes();
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
	vector<DeprecatedCreature *> getLiberalsSharingLocation();
	bool promotesubordinates(const char clearformess);
	vector<DeprecatedCreature *> getHostagesSharingLocation();
	/* common - sends somebody to the hospital */
	void hospitalize(int loc);
	void activate_sleeper();
	Activity getDefaultActivityFundraising();
	Activity getDefaultActivityActivism();
	void activate();
	LOOP_CONTINUATION iterateActivate(const int hostagecount, int &state, const char havedead);
	Activity getDefaultActivityIllegalFundraising();
	int getKeyInActivate(const int hostagecount, int &state, const char havedead, const char sieged, const char oldstate);
	void select_tendhostage();
	void selectOneOfStandardActivities(const char c, const char choiceChar);
	void select_makeclothing();
	void selectStandardActivityA(const char choiceChar);
	void selectStandardActivityB(const char choiceChar);
	void selectStandardActivityC(const char choiceChar);
	void set_activity_augment();
	void set_activity_make_clothing();
	void set_activity_recruit();
	void selectStandardActivityD(const char choiceChar);
	void recruitSelect();
	void listclasses();
	void updateclasschoice(char choice);
	void damagemod(const char &damtype, int &damamount, int mod) const;
	void select_augmentation();
	// Police accost your liberal!
	void attemptarrest(const char* str, const  int clearformess);
	// While galavanting in public, your liberals may be ambushed by police
	int checkforarrest(const char* string, const int clearformess);
	/* common - determines how long a creature's injuries will take to heal */
	int clinictime();
	int countHostagesSharingLocation() const;
	int countDeadSharingLocation() const;

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

	void clear_criminal_record_but_not_heat() {

		for (int i = 0; i < LAWFLAGNUM; i++)
			crimes_suspected[i] = 0;
	}
	void clear_criminal_record() {

		// Clear criminal record?
		heat = 0;
		for (int i = 0; i < LAWFLAGNUM; i++)
			crimes_suspected[i] = 0;
	}

	void criminalize_without_heat(const int crime) {
		crimes_suspected[crime]++;
	}
	int driveskill(int v);
	void clear_no_longer_crimes() {
		extern short lawList[LAWNUM];
		if (lawList[LAW_FLAGBURNING] > 0)crimes_suspected[LAWFLAG_BURNFLAG] = 0;
		if (lawList[LAW_DRUGS] > 0)crimes_suspected[LAWFLAG_BROWNIES] = 0;
		if (lawList[LAW_IMMIGRATION] == 2)flag &= ~CREATUREFLAG_ILLEGALALIEN;
		if (lawList[LAW_FREESPEECH] > -2)crimes_suspected[LAWFLAG_SPEECH] = 0;
	}
	void cap_crimes_at_ten() {

		for (int l = 0; l < LAWFLAGNUM; l++) {
			if (crimes_suspected[l] > 10) {

				crimes_suspected[l] = 10;
			}
		}
	}

	void apply_special_wound(const int wound, const int flag) {
		special[wound] |= flag;
	}

	void lose_blood(const int loss) {
		blood -= loss;
	}

	void lose_all_blood() {
		blood = 0;
	}

	void set_blood(const int _blood) {
		blood = _blood;
	}
	void set_special_wound(const int wound, const int value) {
		special[wound] = value;
	}
	void un_alive() {
		alive = 0; // Kill for the purposes of disbanding all contacts below
	}
	void apply_wound(const int _wound, const int flag) {
		wound[_wound] |= flag;
	}

	void another_confession() {
		confessions++;
	}
	char getCreatureConfessions() const {
		return confessions;
	}
	void rename(const string _name) {
		strcpy(name, _name.data());
	}
	void new_name() {
		void enter_name(int y, int x, char *name, int len, const char* defname);
		enter_name(24, 0, name, CREATURE_NAMELEN, propername);
	}
	void new_name_four() {
		void enter_name(int y, int x, char *name, int len, const char* defname);
		enter_name(4, 0, name, CREATURE_NAMELEN, propername);
	}
	void new_name_two() {
		void enter_name(int y, int x, char *name, int len, const char* defname);
		enter_name(2, 0, name, CREATURE_NAMELEN, propername);
	}
	void set_age(const int a) {
		age = a;
	}
	void age_up() {
		age++;
	}
	void set_date_of_birth(const int _birth_day, const int _birth_month, const int birth_year) {

		extern int year;
		extern int day;
		extern int month;

		birthday_day = _birth_day;
		birthday_month = _birth_month;
		age = year - birth_year;
		// Don't count this year in founder's age if starting before birthday
		if (month < getCreatureBio().birthday_month ||
			(month == getCreatureBio().birthday_month && day < getCreatureBio().birthday_day))
		{
			age--;
		}
	}

<<<<<<< HEAD
	void createTempSquadWithJustThisLiberal(int cursquadid);
	/* names the new hostage and stashes them in your base */
	void kidnaptransfer(); 
	void makeIntoHostage();
=======
	Clip* take_one_clip() {

		Clip* new_clip = clips.back()->split(1);
		if (clips.back()->empty())
			clips.pop_back();
		return new_clip;
	}
	Augmentation & get_augmentation(int aug_num) { return augmentations[aug_num]; }
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
	void makeloot(vector<Item *> &loot);
>>>>>>> acaa55987f7b177b662bdb7f42ebb6850475784a

	// Prompt to convert a new recruit into a sleeper
	void sleeperize_prompt(DeprecatedCreature &recruiter, int y);
	void buyMeASprayCan();
	string gimmeASprayCan();
	void set_money(const int _money) {
		money = _money;
	}
	void no_money() {
		money = 0;
	}
	void make_cantbluff_two() {
		cantbluff = 2;
	}
	void make_cantbluff_zero() {
		cantbluff = 0;
	}
	void make_cantbluff_one() {
		cantbluff = 1;
	}
	bool is_cantbluff_two() const {
		return cantbluff == 2;
	}
	bool is_cantbluff_zero() const {
		return cantbluff == 0;
	}
	bool is_holding_body() const {
		if (prisoner) {
			return true;
		}
		else {
			return false;
		}
	}
	void discard_body() {
		prisoner = NULL;
	}
	bool is_stunned() const {
		return stunned;
	}
	void decrement_stunned() {
		stunned--;
	}
	void increase_stunned(const int e) {
		stunned += e;
	}
	void stop_being_stunned() {
		stunned = 0;
	}
	void stop_existing() {
		exists = false;
	}
	void make_existing() {
		exists = true;
	}
<<<<<<< HEAD

	// public
	string get_name_next_throwing_weapon() const {
		return extra_throwing_weapons[0]->get_shortname(0);
	}
	bool has_extra_throwing_weapons() const {
		return len(extra_throwing_weapons) > 0;
	}
	bool has_clips() const {
		return len(clips) > 0;
	}
	int activity_type() const {
		return activity.type;
	}
	void set_activity(const int c) {
		activity.type = c;
	}
	int activity_arg() const {
		return activity.arg;
	}
	int get_prisoner_type()const {
		if (prisoner)
			return prisoner->type;
		else
			return -1;
	}
	string get_prisoner_name()const {
		if (prisoner)
			return prisoner->name;
		else
			return "";
	}
	int get_prisoner_align() const {
		//if (prisoner)
			return prisoner->align;
		//else
		//	return -3;
	}
	bool is_prisoner_alive() const {
		return prisoner->alive;
	}
	bool is_prisoner_enemy()const {
		return prisoner->enemy();
	}
	void delete_and_nullify_prisoner() {

		delete_and_nullify(prisoner);
	}
	void make_prisoner_ground_loot() {
		prisoner->makeloot();
	}
	void advance_prisoner() {
		prisoner->advancecreature();
	}
	void mark_prisoner_as_kidnapped() {
		prisoner->flag |= CREATUREFLAG_KIDNAPPED;
	}
	bool is_prisoner_non_LCS() const {
		return prisoner->squadid == -1;
	}
	void deal_with_prisoner() {
		//If this is an LCS member or corpse being hauled (marked as in the squad)
		if (prisoner->squadid != -1)
		{
			//Take them out of the squad  TODO: These two lines appear to be interchangeable, but it is unclear if they are
			prisoner->removesquadinfo();
			//RESTORE POOL MEMBER
			//prisoner->squadid = -1;
			//Set base and current location to squad's safehouse
			//MUST LOCATE THE MEMBER
			prisoner->location = base;
			prisoner->base = base;
		}
		else //A kidnapped conservative
		{
			//Convert them into a prisoner
			//CONVERT KIDNAP VICTIM
			prisoner->kidnaptransfer();
			delete prisoner;
		}
		discard_body();

	}
	void drop_prisoner() {
		prisoner->freehostage(1);
	}
	void prisoner_dies() {
		prisoner->removesquadinfo();
		prisoner->die();
		prisoner->location = -1;
	}
	int prisoner_usegment_power() const {
		int usegmentpower = 0;
		usegmentpower += prisoner->get_attribute(ATTRIBUTE_INTELLIGENCE, true);
		usegmentpower += prisoner->get_attribute(ATTRIBUTE_HEART, true);
		usegmentpower += prisoner->get_attribute(ATTRIBUTE_CHARISMA, true);
		usegmentpower += prisoner->get_skill(SKILL_PERSUASION);
		return usegmentpower;
	}
	void make_prisoner_cantbluff_two() {
		prisoner->make_cantbluff_two();
	}
	void make_prisoner(DeprecatedCreature *cr) {
		prisoner = cr;
	}
	void make_new_prisoner(DeprecatedCreature &cr) {

=======

	// public
	string get_name_next_throwing_weapon() const {
		return extra_throwing_weapons[0]->get_shortname(0);
	}
	bool has_extra_throwing_weapons() const {
		return len(extra_throwing_weapons) > 0;
	}
	bool has_clips() const {
		return len(clips) > 0;
	}
	int activity_type() const {
		return activity.type;
	}
	void set_activity(const int c) {
		activity.type = c;
	}
	int activity_arg() const {
		return activity.arg;
	}
	int get_prisoner_type()const {
		if (prisoner)
			return prisoner->type;
		else
			return -1;
	}
	string get_prisoner_name()const {
		if (prisoner)
			return prisoner->name;
		else
			return "";
	}
	int get_prisoner_align() const {
		//if (prisoner)
			return prisoner->align;
		//else
		//	return -3;
	}
	bool is_prisoner_alive() const {
		return prisoner->alive;
	}
	bool is_prisoner_enemy()const {
		return prisoner->enemy();
	}
	void delete_and_nullify_prisoner() {

		delete_and_nullify(prisoner);
	}
	void make_prisoner_ground_loot() {
		void makeloot(DeprecatedCreature &cr);
		makeloot(*prisoner);
	}
	void advance_prisoner() {
		void advancecreature(DeprecatedCreature &cr);
		advancecreature(*prisoner);
	}
	void mark_prisoner_as_kidnapped() {
		prisoner->flag |= CREATUREFLAG_KIDNAPPED;
	}
	bool is_prisoner_non_LCS() const {
		return prisoner->squadid == -1;
	}
	void deal_with_prisoner() {
		void removesquadinfo(DeprecatedCreature &cr);
		void kidnaptransfer(DeprecatedCreature &cr);
		//If this is an LCS member or corpse being hauled (marked as in the squad)
		if (prisoner->squadid != -1)
		{
			//Take them out of the squad  TODO: These two lines appear to be interchangeable, but it is unclear if they are
			removesquadinfo(*prisoner);
			//RESTORE POOL MEMBER
			//prisoner->squadid = -1;
			//Set base and current location to squad's safehouse
			//MUST LOCATE THE MEMBER
			prisoner->location = base;
			prisoner->base = base;
		}
		else //A kidnapped conservative
		{
			//Convert them into a prisoner
			//CONVERT KIDNAP VICTIM
			kidnaptransfer(*prisoner);
			delete prisoner;
		}
		discard_body();

	}
	void drop_prisoner() {
		void freehostage(DeprecatedCreature &cr, char situation);
		freehostage(*prisoner, 1);
	}
	void prisoner_dies() {

		void removesquadinfo(DeprecatedCreature &cr);
		removesquadinfo(*prisoner);
		prisoner->die();
		prisoner->location = -1;
	}
	int prisoner_usegment_power() const {
		int usegmentpower = 0;
		usegmentpower += prisoner->get_attribute(ATTRIBUTE_INTELLIGENCE, true);
		usegmentpower += prisoner->get_attribute(ATTRIBUTE_HEART, true);
		usegmentpower += prisoner->get_attribute(ATTRIBUTE_CHARISMA, true);
		usegmentpower += prisoner->get_skill(SKILL_PERSUASION);
		return usegmentpower;
	}
	void make_prisoner_cantbluff_two() {
		prisoner->make_cantbluff_two();
	}
	void make_prisoner(DeprecatedCreature *cr) {
		prisoner = cr;
	}
	void make_new_prisoner(DeprecatedCreature &cr) {

>>>>>>> acaa55987f7b177b662bdb7f42ebb6850475784a
		prisoner = new DeprecatedCreature;
		*prisoner = cr;
	}
	void delete_prisoner() {
		delete prisoner;
	}
	char human_shield_attacked(DeprecatedCreature &cr) {
<<<<<<< HEAD
		return cr.attack(*prisoner, 1);
	}

	/* attack handling for an individual creature and its target*/
	bool attack(DeprecatedCreature &t, const char mistake, const bool force_melee = false);
	string unsuccessfulHit(DeprecatedCreature &t, const int droll);

	/* modifies a combat roll based on the creature's critical injuries*/
	void healthmodroll(int &aroll);
	int driverAttackBonus();
	DeprecatedCreature* getChaseDriver() const;
	bool attemptIncapacitated();
	string getSpecialAttackString(DeprecatedCreature &t, int &resist, int &attack);
	void makespecialattack(DeprecatedCreature &t);
	bool attemptReload(const bool force_melee);
	bool attemptSpecialAttack(DeprecatedCreature &t, const bool force_melee);
	/* destroys armor, masks, drops weapons based on severe damage*/
	void severloot();

	string printSpecialWounds(const int w, const int damamount, const int damtype);
	string specialWoundPossibilityBody(
		const char breakdam,
		const char pokedam,
		const char damtype);
	string specialWoundPossibilityHead(
		const char breakdam,
		//char pokedam,
		const char heavydam,
		const char damtype);
	int determineBodypartHit(const int aroll, const int droll, const bool sneak_attack);
	void getwheelchair(const char clearformess);

	/* armor repair */
	void repairarmor(const  char clearformess);
	/* armor manufacture */
	void makearmor(const char clearformess);
	/* search for polls */
	void survey();
	/* steal a car */
	bool stealcar();

	void inflictDamage(const int numhits, DeprecatedCreature &t, const AttackInfliction attackI);
	void directlyUseWeapon(int &num_attacks, int &thrownweapons, int &bursthits, const attackst attack_used);
	string showMultipleHits(const int bursthits, const attackst attack_used);
	string initiateCombat(const bool sneak_attack, const attackst attack_used) const;
	string firstStrike(const DeprecatedCreature t, const char mistake, const bool sneak_attack, const attackst attack_used);
	void inflictNonZeroDamage(AttackInfliction attackI,
		const string inputStr,
		const AttackSeverity attackS,
		const int damtype,
		DeprecatedCreature &t);
	DeprecatedCreature* takeBulletForLeader(const int damamount, const int w);
	Deprecatedrecruitst deprecatedrecruitst(int id);
	Activity getDefaultActivityTeaching();

	bool attempt_find_keys(const bool keys_in_car, const int key_location, const int key_search_total, int& y);
	bool foot_chase();
	void makeArmorIfFundsAllowIt(const char clearformess);
	bool enterCar(const bool sensealarm, bool &alarmon, string carname, const bool touchalarm, char &windowdamage);
	bool startCar(const string carname, const bool alarmon, const bool sensealarm);
	bool carselect(short &cartype);
	void addCreature();

	/* describes a character's death*/
	void adddeathmessage();
	void removeCreatureFromSquad(int oldsqid);
	void makeloot();
	void freehostage(char situation);
	void capturedByConservatives();
	bool attemptKidnap(DeprecatedCreature &t, const bool amateur);
	void advancecreature();

	/* checks if the creature can fight and prints flavor text if they can't*/
	char incapacitated(const char noncombat, char &printed);
	char talkAboutIssues(DeprecatedCreature &tk);
	void newRecruit(int a);
	char doYouComeHereOften(DeprecatedCreature &tk);
	char wannaHearSomethingDisturbing(DeprecatedCreature &tk);
	char heyINeedAGun(DeprecatedCreature &tk);
	char heyIWantToRentARoom(DeprecatedCreature &tk);
	char heyIWantToCancelMyRoom(DeprecatedCreature &tk);
	char talkToGeneric(DeprecatedCreature &tk);
	char talkToBankTeller(DeprecatedCreature &tk);
	char talk(const int t);
	char talkInCombat(DeprecatedCreature &tk);
	void pressKeyBInCombat(DeprecatedCreature &tk, const int hostages, const int weaponhostage);
	void pressKeyAInCombat();
	char heyMisterMonster();
	char heyMisterDog();
	void pressKeyCInCombat();
	void pressedKeyBWithHostage(const int hostages, const int e);
	void executeHostage(const int hostages, const int e);
	void sleepereffect(char canseethings, int(&libpower)[VIEWNUM]);
	void sleeper_recruit(char canseethings, int(&libpower)[VIEWNUM]);
	void sleeper_scandal(char canseethings, int(&libpower)[VIEWNUM]);
	void sleeper_steal(char canseethings, int(&libpower)[VIEWNUM]); 
	void stashRandomStolenItem(int &numberofxmlfails);
	void removesquadinfo();
	void sleeper_embezzle(char canseethings, int(&libpower)[VIEWNUM]);
	void sleeper_spy(char canseethings, int(&libpower)[VIEWNUM]);
	void creatureLeaksIntel(const string& leak, const string& stashed);
	void sleeper_influence(char canseethings, int(&libpower)[VIEWNUM]);
	void maskselect();
	void recruitment_activity();
	void printcreatureinfo(unsigned char knowledge = 255);
	void printWounds();
	void set_color_for_disguise();
	char hasdisguise() const;
	void initiateNewgameLocations(const newGameArguments ngm);
	void giveMeAssaultRifle();
	bool print_default_founder_window();
	void set_default_values();
	void set_attributes_zero();
	void make_blind();
	void remove_spine();
	void remove_face();
	void make_paraplegic();
	void severe_internal_damage();
	char weaponcheck(bool metaldetect = false) const;
	void lootTheBody(int base);
	char prison();
	void laborcamp();
	void reeducation();
	void pleadGuilty(const bool sleeperjudge);
	int otherPrisonersEscapeWithMe(int prison);
	DeprecatedCreature * getSleeperJudge();
	DeprecatedCreature * getSleeperLawyer();
	bool pleadInnocent(DeprecatedCreature &sleeperLawyer, const char attorneyname[200], const LegalDefense defense, const bool sleeperjudge, const int scarefactor);
	int get_defensepower(DeprecatedCreature &sleeperLawyer, const char attorneyname[200], const LegalDefense defense, const int prosecution);
	bool hung_jury(const bool sleeperjudge, const int scarefactor);
	void imprison();
	void penalize(const char lenient);
	void dejuiceBoss();
	void trial();
	void prisonscene();
	/* rolls up a creature's stats and equipment */
	void makecreature(const short type);
	/* turns a creature into a conservative */
	void conservatise();
	/* turns a creature into a liberal */
	void liberalize(bool rename = true);



	/* gives a cover name to CCS members */
	void nameCCSMember();
	void armCreature();
	int subordinatesleft() const;
	int maxsubordinates() const;
	void add_juice(long juice, long cap);
=======
		bool attack(DeprecatedCreature &a, DeprecatedCreature &t, const char mistake, const bool force_melee = false);
		return attack(cr, *prisoner, 1);
	}
>>>>>>> acaa55987f7b177b662bdb7f42ebb6850475784a
	int type;
	void delenc(int i);
	void tendhostage(char &clearformess);
	bool dontname;
	char propername[CREATURE_NAMELEN];
	char gender_conservative;
	char gender_liberal;

	std::string type_idname;
	float infiltration;
	char forceinc;
	bool has_thrown_weapon;

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

	int income;

	int juice;
	int heat;
	int location;
	int worklocation;
	int base;
	int flag;

	int pref_carid;
	int carid;
	char is_driver;
	char pref_is_driver;

	// private, [in progress]
	ActivityST activity;


	int align;
	int blood;
	char animalgloss;

	unsigned char wound[BODYPARTNUM];
	char special[SPECIALWOUNDNUM];
	// private, except in haulkidnap.cpp
	DeprecatedCreature * prisoner;

	// private, except in justice.cpp
	int sentence;
	char confessions;
	char deathpenalty;

	// private, except in saveload.cpp
	char name[CREATURE_NAMELEN];
	int crimes_suspected[LAWFLAGNUM];

	int age;
	int birthday_month;
	int birthday_day;

	////
	int scheduleddates() const;
	int loveslaves() const;
	int scheduledmeetings() const;
	int loveslavesleft() const;

	// The various static member functions of DeprecatedCreature are former global functions.
	// 

	static void chase_giveup();
	void updateDamageExcludingCar(char &damtype, int &damamount, const damageDetails ddetails) const;
	static void singleSquadMemberAttack(const int p, const bool wasalarm);
	// one turn of player-side attack
	static void youattack();
	static LOOP_CONTINUATION singleEnemyAttack(const int e, const bool armed);
	static void bloodyUpEncounterArmor();
	static void kidnapattempt();
	static void printparty();
	static void DeprecatedCreature::monthlyRunTheSystem();
	static void DeprecatedCreature::doActivitySolicitDonations(vector<DeprecatedCreature *> &solicit, const char clearformess);
	static void doActivitySellMusic(vector<DeprecatedCreature *> &music, const char clearformess);
	static void doActivityProstitution(vector<DeprecatedCreature *> &prostitutes, const char clearformess);
	static void doActivityGraffiti(vector<DeprecatedCreature *> &graffiti, const char clearformess);
	static void doActivityTrouble(vector<DeprecatedCreature *> &trouble, const char clearformess);
	static void activitiesForIndividuals(char &clearformess);
	static int dateresult(int aroll, int troll, Deprecateddatest &d, int e, int p, int y);
	static char completedate(Deprecateddatest &d, int p);
	static void surrenderToAuthorities(const int loc);
	static char squadhasitem(Deprecatedsquadst &sq, const string& type);
	static LOOP_CONTINUATION increment_footchase();
	static void evasivedrive();
	static void crashfriendlycar(int v);
	static bool drivingupdate(short &obstacle);
	static char checkActiveSquadForRejection(const char autoadmit, const bool metaldetect);
	static char sizeUpSquadForEntry(const bool autoadmit);
	static UnlockAttempt bash();
	static void pressedKeyU(const int enemy);
	static void partyIsAliveOnSite(const int enemy,
		const int talkers,
		const int freeable);
	static void checkForHostageScream(char &hostcheck);
	static bool chasesequence();
	//// Used throughout
	static void equip(vector<Item *> &loot, int loc);
//	int maxsubordinates() const;
//	void armCreature(const int type);
	// Used in Shop (and probably CreatureType)
	void give_weapon(Weapon& w, vector<Item*>* lootpile);
	bool take_clips(Clip& clip, int number);
	void give_armor(Armor& a, vector<Item*>* lootpile);

	// Used in CreatureType
	bool take_clips(const ClipType& ct, int number);
	void give_weapon(const WeaponType& wt, vector<Item*>* lootpile);
	void give_armor(const int at, vector<Item*>* lootpile);
private:
<<<<<<< HEAD
	static string transferClipBaseSquad(const bool decreaseammo, const bool increaseammo, int& slot, int& page, const int e, vector<Item *> &loot);
	static void disarmSquadmember(vector<Item *> &loot, const int p);
	static void completelyStripSquadMember(vector<Item *> &loot, int d);
	/* blood explosions */
	static void bloodblast(Armor* armor);

	void DeprecatedCreature::addCreatureVehiclesToCollection(vector<Vehicle *> &veh);
	Vehicle* getChaseVehicle() const;


	void apply_augmentation(DeprecatedCreature *victim, AugmentType *selected_aug);
	int driveskill(Vehicle &v);
	Clip* take_one_clip() {

		Clip* new_clip = clips.back()->split(1);
		if (clips.back()->empty())
			clips.pop_back();
		return new_clip;
	}
	Augmentation & get_augmentation(int aug_num) { return augmentations[aug_num]; }
	Weapon& get_weapon() const { return is_armed() ? *weapon : weapon_none(); }
	Armor& get_armor() const { return is_naked() ? armor_none() : *armor; }
	bool take_clips(Item& clip, int number);
	void drop_weapon(vector<Item*>* lootpile);
	void drop_weapons_and_clips(vector<Item*>* lootpile);
	void strip(vector<Item*>* lootpile);
	void makeloot(vector<Item *> &loot);
	int armor_makedifficulty(ArmorType& type);
	int armor_makedifficulty(Armor& type);
	void findArmorToRepair(Armor* armor, Item* pile, int &pileindex, vector<Item* > *pilelist);
	bool chasesequence(Vehicle &v);

	void giveDefaultWeapon();
	void armBouncer();
	void armCREATURE_SCIENTIST_LABTECH();
	void armCREATURE_JUDGE_CONSERVATIVE();
	void armCREATURE_SCIENTIST_EMINENT();
	void armCREATURE_CORPORATE_CEO();
	void armCREATURE_WORKER_FACTORY_NONUNION();
	void armCREATURE_WORKER_SWEATSHOP();
	void armCREATURE_LAWYER();
	void armCREATURE_DOCTOR();
	void armCREATURE_PSYCHOLOGIST();
	void armCREATURE_NURSE();
	void armCREATURE_WORKER_FACTORY_UNION();
	void armCREATURE_TANK();
	void armCREATURE_HICK();
	void armCREATURE_COP();
	void armCREATURE_FIREFIGHTER();
	void armCREATURE_CCS_MOLOTOV();
	void armCREATURE_CCS_SNIPER();
	void armCREATURE_CCS_VIGILANTE();
	void armCREATURE_CCS_ARCHCONSERVATIVE();
	void armCREATURE_PRISONGUARD();
	void armCREATURE_EDUCATOR();
	void armCREATURE_GENETIC(int(&attcap)[ATTNUM]);
	void armCREATURE_GUARDDOG();
	void armCREATURE_PRISONER();
	void armCREATURE_BUM();
	void armCREATURE_MUTANT();
	void armCREATURE_GANGMEMBER();
	void armCREATURE_CRACKHEAD(int(&attcap)[ATTNUM]);
	void armCREATURE_FASTFOODWORKER();
	void armCREATURE_FOOTBALLCOACH();
	void armCREATURE_PROSTITUTE();
	void armCREATURE_HIPPIE();
	void armCREATURE_SOCIALITE();
	void armCREATURE_THIEF();
	void armCREATURE_MILITARYOFFICER();
	void armSpecificCreature(int(&attcap)[ATTNUM]);
//	void makecreature(short type);
//	void liberalize(bool rename);
	////

	// Determines the number of love slaves a creature has
	//int loveslaves(
	/* Determines the number of loveslaves a creature may recruit,
	based on their max and the number they already command */
	//int loveslavesleft(
	// Determines the number of recruitment meetings a creature has scheduled
	//int scheduledmeetings(
	// Determines the number of dates a creature has scheduled
	//int scheduleddates(
	//
	void printliberalstats_d();
	void printliberalstats_f();

	void newDate(DeprecatedCreature &tk);
	bool incapacitatedTank(const char noncombat, char &printed);
	bool incapacitatedPerson(const char noncombat, char &printed);
	bool incapacitatedAnimal(const char noncombat, char &printed);
	void creaturePossiblyLosesHeartOrGainsWisdom(int &y);
	string creatureIsHurtAndMightDie();
	void illTellYouWhatIKnow(DeprecatedCreature *a, const int forceroll, int &y);
	void show_interrogation_sidebar(DeprecatedCreature * a);
	vector<DeprecatedCreature *> findAllTendersToThisHostage();

	DeprecatedCreature * getAttackAndLeadInterrogator(int &attack, const vector<DeprecatedCreature *> temppool);
	void hostageEscapes(const char clearformess);
	vector<string> printCreatureInterrogationStatus(const bool restrain);
	void attemptExecution();
	void printInterrogationMenu(bool techniques[6], DeprecatedCreature * a);
	char feelTheDrugUse(DeprecatedCreature *doctor);
	void getCreatureWorkplaceMaps(int &y, const string aname);
	bool attemptSway(DeprecatedCreature *a, const int attack, map<long, struct Float_Zero>(&rapport), char& turned, int& y);
	void attemptSuicide(const bool restrain, int &y);
	void interrogaterNotOutsmarted(DeprecatedCreature *a, const bool props, map<long, struct Float_Zero>(&rapport), int& y);
	bool attemptToOutsmartCaptor(DeprecatedCreature *a, const bool drugs, int& y);
	void captiveGetsBeaten(DeprecatedCreature* a, int &y, const vector<DeprecatedCreature *> temppool, const bool(&techniques)[6], map<long, struct Float_Zero>(&rapport));
	void hostageDies(DeprecatedCreature *a, int &y);
	void creatureConversion(DeprecatedCreature* a, int &y);
	void criminalize_me(const int crime, const bool grant_heat) {
		int lawflagheat(int lawflag);
		crimes_suspected[crime]++;
		if (grant_heat) {
			heat += lawflagheat(crime);

		}
	}
=======

>>>>>>> acaa55987f7b177b662bdb7f42ebb6850475784a
	deque<Clip*> clips;
	deque<Weapon*> extra_throwing_weapons;

	bool alive;

	bool exists;
	int stunned;

	char cantbluff;

	int money;

	class Augmentation augmentations[AUGMENTATIONNUM];
	static Weapon& weapon_none();
	static Armor& armor_none();
	Weapon* weapon;
	Armor* armor;

	void copy(const DeprecatedCreature& org);
	int attributes[ATTNUM];
	int skills[SKILLNUM];
	int skill_experience[SKILLNUM];
	int seethroughdisguise;
	int seethroughstealth;
	bool istalkreceptive;
	bool iskidnap_resistant;
	bool isreports_to_police;

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


// Add an age estimate to a person's name
string get_age_string(const CreatureBio bio, const char animalgloss);
/* ensures that the creature's work location is appropriate to its type */
int verifyworklocation(const int type, const int worklocation);

struct Deprecatedrecruitst
{
	long recruiter_id;
	DeprecatedCreature* recruit;
	//short timeleft;
	//char level;
	char eagerness1;
	//, task;
	//Deprecatedrecruitst();
	Deprecatedrecruitst(DeprecatedCreature * cr, int id);
	~Deprecatedrecruitst();
	char eagerness();
};

struct Deprecateddatest
{
	long mac_id;
	vector<DeprecatedCreature *> date;
	short timeleft;
	int city;
	Deprecateddatest() : timeleft(0) { }
	~Deprecateddatest() { delete_and_clear(date); }
};

struct Deprecatedsquadst
{
	char name[SQUAD_NAMELEN];
	DeprecatedCreature *squad[6];
	ActivityST activity;
	int id;
	vector<Item *> loot;

	char stance; // Squad's site action stance: high profile, low profile, etc.

	Deprecatedsquadst()
	{
		for (int p = 0; p < 6; p++) squad[p] = NULL;
		strcpy(name, blankString.c_str());
		activity.type = ACTIVITY_NONE, id = -1, stance = SQUADSTANCE_STANDARD;
	}
	~Deprecatedsquadst() { delete_and_clear(loot); }
	/* tells how many total members a squad has (including dead members) */
	int squadsize() {
		int squadsize(const Deprecatedsquadst *st);
		return squadsize(this);
	}
	/* tells how many members a squad has who are alive */
	int squadalive() {
		int squadalive(const Deprecatedsquadst *st);
		return squadalive(this);
	}
};

int activesquadSize();
int activesquadAlive();

#endif