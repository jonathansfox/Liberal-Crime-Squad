
#include "../includes.h"
const string CONST_creaturetypeB086 = ": ";
const string CONST_creaturetypeB080 = " lacks idname.";
const string CONST_creaturetypeB078 = ", ";
const string CONST_creaturetypeB075 = " in ";
const string CONST_creaturetype074 = "Fireman";
const string CONST_creaturetype073 = "Car Salesman";
const string CONST_creaturetype072 = "Migrant Worker";
const string CONST_creaturetype071 = "Custodian";
const string CONST_creaturetype070 = "Slave";
const string CONST_creaturetype069 = "type_name not defined for ";
const string CONST_creaturetype068 = "Unknown element for ";
const string CONST_creaturetype067 = "Invalid armor type for ";
const string CONST_creaturetype066 = "Unknown skill for ";
const string CONST_creaturetype065 = "Invalid gender for ";
const string CONST_creaturetype064 = "Unknown attribute in ";
const string CONST_creaturetype063 = "Invalid alignment for ";
const string CONST_creaturetype062 = "Creature type ";
const string CONST_creaturetype061 = "LACKS IDNAME ";
const string CONST_creaturetype060 = "Invalid clip type for ";
const string CONST_creaturetype059 = "can not be used by ";
const string CONST_creaturetype058 = "In ";
const string CONST_creaturetype057 = "Invalid weapon type for ";
const string CONST_creaturetype056 = "Unknown element for weapon in ";
const string CONST_creaturetype055 = "Invalid interval for ";

const string tag_ARMOR = "ARMOR";
const string tag_ARMOR_NONE = "ARMOR_NONE";
const string tag_CLIP_45 = "CLIP_45";
const string tag_CLIP = "CLIP";
const string tag_WEAPON = "WEAPON";
const string tag_WEAPON_SEMIPISTOL_45 = "WEAPON_SEMIPISTOL_45";
const string tag_CLIP_9 = "CLIP_9";
const string tag_WEAPON_SEMIPISTOL_9MM = "WEAPON_SEMIPISTOL_9MM";
const string tag_CLIP_38 = "CLIP_38";
const string tag_WEAPON_REVOLVER_38 = "WEAPON_REVOLVER_38";
const string tag_WEAPON_NONE = "WEAPON_NONE";
const string tag_CIVILIAN = "CIVILIAN";
const string tag_type = "type";
const string tag_type_name = "type_name";
const string tag_encounter_name = "encounter_name";
const string tag_creature = "creature";
const string tag_weapon = "weapon";
const string tag_armor = "armor";
const string tag_skills = "skills";
const string tag_skill = "skill";
const string tag_money = "money";
const string tag_infiltration = "infiltration";
const string tag_gender = "gender";
const string tag_juice = "juice";
const string tag_attributes = "attributes";
const string tag_attribute = "attribute";
const string tag_attribute_points = "attribute_points";
const string tag_SENIOR = "SENIOR";
const string tag_MI = "MI";
const string tag_MIDDLEAGED = "MIDDLEAGED";
const string tag_GRADUATE = "GRADUATE";
const string tag_MATURE = "MATURE";
const string tag_Y = "Y";
const string tag_YOUNGADULT = "YOUNGADULT";
const string tag_TEENAGER = "TEENAGER";
const string tag_CHILD = "CHILD";
const string tag_CHI = "CHI";
const string tag_D = "D";
const string tag_DOGYEARS = "DOGYEARS";
const string tag_age = "age";
const string tag_CONSERVATIVE = "CONSERVATIVE";
const string tag_MODERATE = "MODERATE";
const string tag_LIBERAL = "LIBERAL";
const string tag_PUBLIC_MOOD = "PUBLIC MOOD";
const string tag_align = "align";
const string tag_alignment = "alignment";
const string tag_idname = "idname";
const string tag_id = "id";
const string tag_APPROPRIATE = "APPROPRIATE";
const string tag_number_clips = "number_clips";
const string tag_clip = "clip";
const string tag_cliptype = "cliptype";
const string tag_number_weapons = "number_weapons";
const string blankString = "";
const string tag_value = "value";
#include "vehicle/vehicleType.h"///
#include "vehicle/vehicle.h"///
#include "../creature/creature.h"
#include "../locations/locationsEnums.h"
#include "../common/interval.h"
#include "creaturetype.h"
//own header
#include "../log/log.h"
// for LOG
#include "../common/translateid.h"
// for  int getweapontype(int)
#include "../common/stringconversion.h"
//for creaturetype_string_to_enum
#include "../politics/politics.h"
//for int publicmood(int l);

//const string CONST_creaturetype064 = "Unknown attribute in ";
//const string CONST_creaturetype063 = "Invalid alignment for ";
//const string CONST_creaturetype062 = "Creature type ";
//const string CONST_creaturetype061 = "LACKS IDNAME ";
//const string CONST_creaturetype060 = "Invalid clip type for ";
//const string CONST_creaturetype059 = "can not be used by ";
//const string CONST_creaturetype058 = "In ";
//const string CONST_creaturetype057 = "Invalid weapon type for ";
//const string CONST_creaturetype056 = "Unknown element for weapon in ";
//const string CONST_creaturetype055 = "Invalid interval for ";

//const string tag_CLIP_45 = "CLIP_45";
//const string tag_CLIP = "CLIP";
//const string tag_CLIP_9 = "CLIP_9";
//const string tag_CLIP_38 = "CLIP_38";
//const string tag_CIVILIAN = "CIVILIAN";
//const string tag_type_name = "type_name";
//const string tag_encounter_name = "encounter_name";
//const string tag_skills = "skills";
//const string tag_attributes = "attributes";
//const string tag_attribute_points = "attribute_points";
//const string tag_SENIOR = "SENIOR";
//const string tag_MI = "MI";
//const string tag_MIDDLEAGED = "MIDDLEAGED";
//const string tag_GRADUATE = "GRADUATE";
//const string tag_MATURE = "MATURE";
//const string tag_YOUNGADULT = "YOUNGADULT";
//const string tag_TEENAGER = "TEENAGER";
//const string tag_CHILD = "CHILD";
//const string tag_CHI = "CHI";
//const string tag_DOGYEARS = "DOGYEARS";
//const string tag_CONSERVATIVE = "CONSERVATIVE";
//const string tag_MODERATE = "MODERATE";
//const string tag_LIBERAL = "LIBERAL";
//const string tag_PUBLIC_MOOD = "PUBLIC MOOD";
//const string tag_alignment = "alignment";
//const string tag_APPROPRIATE = "APPROPRIATE";
//const string tag_number_clips = "number_clips";
//const string tag_cliptype = "cliptype";
//const string tag_number_weapons = "number_weapons";
//#include "../common/interval.h"
//#include "../creature/creaturetype.h"

const string tag_CLIP_BUCKSHOT = "CLIP_BUCKSHOT";
const string tag_CLIP_SMG = "CLIP_SMG";
const string tag_CLIP_ASSAULT = "CLIP_ASSAULT";
const string tag_WEAPON_AUTORIFLE_AK47 = "WEAPON_AUTORIFLE_AK47";
const string tag_CLIP_44 = "CLIP_44";
const string tag_WEAPON_AXE = "WEAPON_AXE";
const string tag_CLIP_GASOLINE = "CLIP_GASOLINE";
const string tag_WEAPON_TORCH = "WEAPON_TORCH";
const string tag_WEAPON_PITCHFORK = "WEAPON_PITCHFORK";
const string tag_WEAPON_GAVEL = "WEAPON_GAVEL";

const string CONST_creaturetypes049 = "Giant Mosquito";
const string CONST_creaturetypes048 = "Flaming Rabbit";
const string CONST_creaturetypes047 = "Pet ";
const string CONST_creaturetypes046 = "CCS Team Leader";
const string CONST_creaturetypes045 = "Firefighter";
const string CONST_creaturetypes044 = "Fireman";
const string CONST_creaturetypes043 = "Police Negotiator";
const string CONST_creaturetypes042 = "CEO ";
const string CONST_creaturetypes041 = "Enforcer";
const string CONST_creaturetypes040 = "genetic_monster.txt";
const string CONST_creaturetypes039 = "words_meaning_hick.txt";
const string CONST_creaturetypesX01 = "CCS Lieutenant";
const string CONST_creaturetypesX02 = "CCS Founder";

Weapon& DeprecatedCreature::weapon_none()
{
	extern vector<WeaponType *> weapontype;
	static Weapon unarmed(*weapontype[getweapontype(tag_WEAPON_NONE)]);
	return unarmed;
}
// This would normally be inlined inside the DeprecatedCreature class in creature.h, but the DeprecatedCreature class
// has to be before creaturetype
std::string DeprecatedCreature::get_type_name() const { return getcreaturetype(type_idname)->get_type_name(); }
// Assign a value to an Interval from a string or log error.
void assign_interval(Interval& i, const std::string& value,
	const std::string& owner, const std::string& element)
{
	extern Log xmllog;
	if (!i.set_interval(value))
		xmllog.log(CONST_creaturetype055 + element + CONST_creaturetypeB075 + owner + CONST_creaturetypeB086 + value);
}
int CreatureType::s_number_of_creaturetypes = 0;
CreatureType::WeaponsAndClips::WeaponsAndClips(const std::string& weapon, int weapons, const std::string& clip, int clips)
	: weapon_type_str(weapon), number_weapons(weapons),
	cliptype(clip), number_clips(clips)
{
}

map<string, int> creatureTypeTags = {
	map<string, int>::value_type(tag_alignment, ENUM_tag_alignment),
	map<string, int>::value_type(tag_PUBLIC_MOOD, ENUM_tag_PUBLIC_MOOD),
	map<string, int>::value_type(tag_LIBERAL, ENUM_tag_LIBERAL),
	map<string, int>::value_type(tag_MODERATE, ENUM_tag_MODERATE),
	map<string, int>::value_type(tag_CONSERVATIVE, ENUM_tag_CONSERVATIVE),
	map<string, int>::value_type(tag_age, ENUM_tag_age),
	map<string, int>::value_type(tag_DOGYEARS, ENUM_tag_DOGYEARS),
	map<string, int>::value_type(tag_CHILD, ENUM_tag_CHILD),
	map<string, int>::value_type(tag_TEENAGER, ENUM_tag_TEENAGER),
	map<string, int>::value_type(tag_YOUNGADULT, ENUM_tag_YOUNGADULT),
	map<string, int>::value_type(tag_MATURE, ENUM_tag_MATURE),
	map<string, int>::value_type(tag_GRADUATE, ENUM_tag_GRADUATE),
	map<string, int>::value_type(tag_MIDDLEAGED, ENUM_tag_MIDDLEAGED),
	map<string, int>::value_type(tag_SENIOR, ENUM_tag_SENIOR),
	map<string, int>::value_type(tag_attribute_points, ENUM_tag_attribute_points),
	map<string, int>::value_type(tag_attributes, ENUM_tag_attributes),
	map<string, int>::value_type(tag_juice, ENUM_tag_juice),
	map<string, int>::value_type(tag_gender, ENUM_tag_gender),
	map<string, int>::value_type(tag_infiltration, ENUM_tag_infiltration),
	map<string, int>::value_type(tag_money, ENUM_tag_money),
	map<string, int>::value_type(tag_skills, ENUM_tag_skills),
	map<string, int>::value_type(tag_armor, ENUM_tag_armor),
	map<string, int>::value_type(tag_weapon, ENUM_tag_weapon),
	map<string, int>::value_type(tag_encounter_name, ENUM_tag_encounter_name),
	map<string, int>::value_type(tag_type_name, ENUM_tag_type_name),

};

string undefined;
CreatureType::CreatureType(const std::string& xmlstring)
	: age_(18, 57), alignment_public_mood_(true),
	attribute_points_(40),
	gender_liberal_(GENDER_RANDOM), gender_conservative_(GENDER_RANDOM),
	infiltration_(0), juice_(0), money_(20, 40)
{
	const string singleDot = ".";
	extern string NONE;
	extern Log xmllog;
	for (int i = 0; i < ATTNUM; i++)
		attributes_[i].set_interval(1, 10);
	id_ = s_number_of_creaturetypes++;
	CMarkup xml;
	xml.SetDoc(xmlstring);
	xml.FindElem();
	idname_ = xml.GetAttrib(tag_idname);
	if (!len(idname_))
	{
		idname_ = CONST_creaturetype061 + tostring(id_);
		xmllog.log(CONST_creaturetype062 + tostring(id_) + CONST_creaturetypeB080);
	}
	type_ = creaturetype_string_to_enum(idname_);
	xml.IntoElem();
	// Loop over all the elements inside the creaturetype element.
	while (xml.FindElem())
	{
		std::string element = xml.GetTagName();
		if (creatureTypeTags.count(element)) {
			std::string age_alignment_or_whatever;
			int gender;
			switch (creatureTypeTags[element]) {
			case ENUM_tag_alignment:


				age_alignment_or_whatever = xml.GetData();
				switch (creatureTypeTags[age_alignment_or_whatever]) {

				case ENUM_tag_PUBLIC_MOOD:
					alignment_public_mood_ = true;
					break;
				case ENUM_tag_LIBERAL:
					alignment_ = ALIGN_LIBERAL;
					alignment_public_mood_ = false;
					break;
				case ENUM_tag_MODERATE:
					alignment_ = ALIGN_MODERATE;
					alignment_public_mood_ = false;
					break;
				case ENUM_tag_CONSERVATIVE:
					alignment_ = ALIGN_CONSERVATIVE;
					alignment_public_mood_ = false;
					break;
				default:
					xmllog.log(CONST_creaturetype063 + idname_ + CONST_creaturetypeB086 + age_alignment_or_whatever);
					break;
				}
				break;
			case ENUM_tag_age:
				age_alignment_or_whatever = xml.GetData();
				switch (creatureTypeTags[age_alignment_or_whatever]) {
				case ENUM_tag_DOGYEARS:
					age_.set_interval(2, 6);
					break;
				case ENUM_tag_CHILD:
					age_.set_interval(7, 10);
					break;
				case ENUM_tag_TEENAGER:
					age_.set_interval(14, 17);
					break;
				case ENUM_tag_YOUNGADULT:
					age_.set_interval(18, 35);
					break;
				case ENUM_tag_MATURE:
					age_.set_interval(20, 59);
					break;
				case ENUM_tag_GRADUATE:
					age_.set_interval(26, 59);
					break;
				case ENUM_tag_MIDDLEAGED:
					age_.set_interval(35, 59);
					break;
				case ENUM_tag_SENIOR:
					age_.set_interval(65, 94);
					break;
				default:
					assign_interval(age_, age_alignment_or_whatever, idname_, element);
					break;
				}
			case ENUM_tag_attribute_points:
				assign_interval(attribute_points_, xml.GetData(), idname_, element);
				break;
			case ENUM_tag_attributes:
				while (xml.FindChildElem())
				{
					int attribute = attribute_string_to_enum(xml.GetChildTagName());
					if (attribute != -1)
						assign_interval(attributes_[attribute], xml.GetChildData(), idname_, element);
					else
						xmllog.log(CONST_creaturetype064 + idname_ + CONST_creaturetypeB086 + xml.GetTagName());
				}
				break;
			case ENUM_tag_juice:
				assign_interval(juice_, xml.GetData(), idname_, element);
				break;
			case ENUM_tag_gender:
				gender = gender_string_to_enum(xml.GetData());
				if (gender != -1 && gender != GENDER_WHITEMALEPATRIARCH)
					gender_liberal_ = gender_conservative_ = gender;
				else
					xmllog.log(CONST_creaturetype065 + idname_ + CONST_creaturetypeB086 + xml.GetData());
				break;
			case ENUM_tag_infiltration:
				assign_interval(infiltration_, xml.GetData(), idname_, element);
				break;
			case ENUM_tag_money:
				assign_interval(money_, xml.GetData(), idname_, element);
				break;
			case ENUM_tag_skills:
				while (xml.FindChildElem())
				{
					int skill = skill_string_to_enum(xml.GetChildTagName());
					if (skill != -1)
						assign_interval(skills_[skill], xml.GetChildData(), idname_, element);
					else
						xmllog.log(CONST_creaturetype066 + idname_ + CONST_creaturetypeB086 + xml.GetChildTagName());
				}
				break;
			case ENUM_tag_armor:
				if (getarmortype(xml.GetData()) != -1)
					armortypes_.push_back(xml.GetData());
				else
					xmllog.log(CONST_creaturetype067 + idname_ + CONST_creaturetypeB086 + xml.GetData());
				break;
			case ENUM_tag_weapon:
				//xml.SavePos(tag_creature);
				weapons_and_clips_.push_back(WeaponsAndClips(xml, idname_));
				//xml.RestorePos(tag_creature);
				break;
			case ENUM_tag_encounter_name:
				encounter_name_ = xml.GetData();
				break;
			case ENUM_tag_type_name:
				type_name_ = xml.GetData();
				break;
			}
		}
		else {
			xmllog.log(CONST_creaturetype068 + idname_ + CONST_creaturetypeB086 + element);
		}
		if (!len(type_name_))
		{
			xmllog.log(CONST_creaturetype069 + idname_ + singleDot);
			type_name_ = undefined;
		}
		// If no weapon type has been given then use WEAPON_NONE.
		if (!len(weapons_and_clips_))
			weapons_and_clips_.push_back(WeaponsAndClips(tag_WEAPON_NONE, 1, NONE, 0));
		// If no armor type has been given then use ARMOR_NONE.
		if (!len(armortypes_))
			armortypes_.push_back(tag_ARMOR_NONE);
	}
}
void CreatureType::make_creature(DeprecatedCreature& cr) const
{
	cr.type_idname = idname_;
	cr.align = get_alignment();
	cr.set_age(age_.roll());
	cr.juice = juice_.roll();
	cr.gender_liberal = cr.gender_conservative = roll_gender();
	cr.infiltration = roll_infiltration();
	cr.set_money(money_.roll());
	cr.rename(get_encounter_name());
	for (int i = 0; i < SKILLNUM; i++) cr.set_skill(i, skills_[i].roll());
	give_armor(cr);
	give_weapon(cr);
}
Alignment CreatureType::get_alignment() const
{
	if (alignment_public_mood_)
	{
		int mood = publicmood(-1);
		int a = ALIGN_CONSERVATIVE;
		if (LCSrandom(100) < mood) a++;
		if (LCSrandom(100) < mood) a++;
		return (Alignment)a;
	}
	else return alignment_;
}
int CreatureType::roll_gender() const
{
	extern short lawList[LAWNUM];
	switch (gender_liberal_)
	{
	case GENDER_NEUTRAL: return GENDER_NEUTRAL;
	case GENDER_MALE:    return GENDER_MALE;
	case GENDER_FEMALE:  return GENDER_FEMALE;
	case GENDER_MALE_BIAS:
		if (lawList[LAW_WOMEN] == -2 ||
			(lawList[LAW_WOMEN] == -1 && LCSrandom(25)) ||
			(lawList[LAW_WOMEN] == 0 && LCSrandom(10)) ||
			(lawList[LAW_WOMEN] == 1 && LCSrandom(4)))
			return GENDER_MALE;
	case GENDER_FEMALE_BIAS:
		if (lawList[LAW_WOMEN] == -2 ||
			(lawList[LAW_WOMEN] == -1 && LCSrandom(25)) ||
			(lawList[LAW_WOMEN] == 0 && LCSrandom(10)) ||
			(lawList[LAW_WOMEN] == 1 && LCSrandom(4)))
			return GENDER_FEMALE;
	}
	return LCSrandom(2) + 1; // Male or female.
}
float CreatureType::roll_infiltration() const
{
	return infiltration_.roll() / 100.0f;
}
std::string CreatureType::get_encounter_name() const
{
	if (len(encounter_name_))
		return encounter_name_;
	else return get_type_name();
}
std::string CreatureType::get_type_name() const
{
	extern short lawList[LAWNUM];
	switch (type_) // Hardcoded special cases.
	{
	case CREATURE_WORKER_SERVANT:
		if (lawList[LAW_LABOR] == -2 && lawList[LAW_CORPORATE] == -2) return CONST_creaturetype070;
		break;
	case CREATURE_WORKER_JANITOR:
		if (lawList[LAW_LABOR] == 2) return CONST_creaturetype071;
		break;
	case CREATURE_WORKER_SWEATSHOP:
		if (lawList[LAW_LABOR] == 2 && lawList[LAW_IMMIGRATION] == 2) return CONST_creaturetype072;
		break;
	case CREATURE_CARSALESMAN:
		if (lawList[LAW_WOMEN] == -2) return CONST_creaturetype073;
		break;
	case CREATURE_FIREFIGHTER:
		if (lawList[LAW_FREESPEECH] == -2) return CONST_creaturetype074;
		break;
	}
	return type_name_;
}
void CreatureType::give_weapon(DeprecatedCreature& cr) const
{
	extern string NONE;
	extern vector<WeaponType *> weapontype;
	extern vector<ClipType *> cliptype;
	const WeaponsAndClips& wc = pickrandom(weapons_and_clips_);
	if (wc.weapon_type_str == tag_CIVILIAN)
		give_weapon_civilian(cr);
	else if (wc.weapon_type_str != tag_WEAPON_NONE)
	{
		Weapon w(*weapontype[getweapontype(wc.weapon_type_str)], wc.number_weapons.roll());
		w.set_number(min(w.get_number(), 10L));
		while (!w.empty()) cr.give_weapon(w, NULL);
		if (wc.cliptype != NONE)
		{
			int n = wc.number_clips.roll();
			cr.take_clips(*cliptype[getcliptype(wc.cliptype)], n);
			cr.reload(false);
		}
	}
}
void CreatureType::give_weapon_civilian(DeprecatedCreature& cr) const
{
	extern vector<WeaponType *> weapontype;
	extern short lawList[LAWNUM];
	extern vector<ClipType *> cliptype;
	if (lawList[LAW_GUNCONTROL] == -1 && !LCSrandom(30))
	{
		cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_38)], NULL);
		cr.take_clips(*cliptype[getcliptype(tag_CLIP_38)], 4);
		cr.reload(false);
	}
	else if (lawList[LAW_GUNCONTROL] == -2)
	{
		if (!LCSrandom(10))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIPISTOL_9MM)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_9)], 4);
			cr.reload(false);
		}
		else if (!LCSrandom(9))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIPISTOL_45)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_45)], 4);
			cr.reload(false);
		}
	}
}
void CreatureType::give_armor(DeprecatedCreature& cr) const
{
	const std::string str = pickrandom(armortypes_);
	if (str != tag_ARMOR_NONE)
		cr.give_armor(getarmortype(str), NULL);
}

vector<CreatureTypes> armAsCivilian = {
	// Curiously, CREATURE_CRACKHEAD has a chance to be armed with a shank, regardless of whether they are granted a civilian weapon
	CREATURE_CRACKHEAD, CREATURE_MUTANT, CREATURE_BUM, CREATURE_WORKER_FACTORY_UNION, CREATURE_WORKER_FACTORY_NONUNION, CREATURE_SCIENTIST_EMINENT, CREATURE_SCIENTIST_LABTECH
};

map<short, vector<CreatureTypes> > replaceTheseCreatures = {
	// The original code has a 1/10 chance to replace with CREATURE_THIEF
	// Otherwise, random selection between the other five.
	// This code changes this to a 1/11 chance to replace with CREATURE_THIEF
	// Which is close enough.
	map<CreatureTypes, vector<CreatureTypes> >::value_type(CREATURE_PRISONER,{ CREATURE_THIEF, CREATURE_GANGMEMBER, CREATURE_PROSTITUTE, CREATURE_CRACKHEAD, CREATURE_TEENAGER, CREATURE_HSDROPOUT, CREATURE_GANGMEMBER, CREATURE_PROSTITUTE, CREATURE_CRACKHEAD, CREATURE_TEENAGER, CREATURE_HSDROPOUT })

};
vector<CreatureTypes> doNotArmInThisFunction = {
	CREATURE_JUDGE_LIBERAL,
	CREATURE_POLITICIAN,
	CREATURE_CORPORATE_MANAGER,
	CREATURE_WORKER_SERVANT,
	CREATURE_WORKER_JANITOR,
	CREATURE_WORKER_SECRETARY,
	CREATURE_LANDLORD,
	CREATURE_BANK_TELLER,
	CREATURE_BANK_MANAGER,
	CREATURE_TEENAGER,
	CREATURE_SOLDIER,
	CREATURE_VETERAN,
	CREATURE_HARDENED_VETERAN,
	CREATURE_SWAT,
	CREATURE_DEATHSQUAD,
	CREATURE_GANGUNIT,
	CREATURE_AGENT,
	CREATURE_SECRET_SERVICE,
	CREATURE_RADIOPERSONALITY,
	CREATURE_NEWSANCHOR,
	CREATURE_JUROR,
	CREATURE_WORKER_FACTORY_CHILD,
	CREATURE_SEWERWORKER,
	CREATURE_COLLEGESTUDENT,
	CREATURE_MUSICIAN,
	CREATURE_MATHEMATICIAN,
	CREATURE_TEACHER,
	CREATURE_HSDROPOUT,
	CREATURE_PRIEST,
	CREATURE_ENGINEER,
	CREATURE_TELEMARKETER,
	CREATURE_CARSALESMAN,
	CREATURE_OFFICEWORKER,
	CREATURE_MAILMAN,
	CREATURE_GARBAGEMAN,
	CREATURE_PLUMBER,
	CREATURE_CHEF,
	CREATURE_CONSTRUCTIONWORKER,
	CREATURE_AMATEURMAGICIAN,
	CREATURE_AUTHOR,
	CREATURE_JOURNALIST,
	CREATURE_CRITIC_ART,
	CREATURE_CRITIC_MUSIC,
	CREATURE_BIKER,
	CREATURE_TRUCKER,
	CREATURE_TAXIDRIVER,
	CREATURE_PROGRAMMER,
	CREATURE_NUN,
	CREATURE_RETIREE,
	CREATURE_PAINTER,
	CREATURE_SCULPTOR,
	CREATURE_DANCER,
	CREATURE_PHOTOGRAPHER,
	CREATURE_CAMERAMAN,
	CREATURE_HAIRSTYLIST,
	CREATURE_FASHIONDESIGNER,
	CREATURE_CLERK,
	CREATURE_ACTOR,
	CREATURE_YOGAINSTRUCTOR,
	CREATURE_MARTIALARTIST,
	CREATURE_ATHLETE,
	CREATURE_LOCKSMITH,
	CREATURE_MILITARYPOLICE,
	CREATURE_SEAL,
	// These are not used in the switch statement anymore, but appear in the defaultWeapons collection
	//CREATURE_SECURITY_GUARD
	//CRREATURE_MERC
};
struct weaponLayout {
	string weaponTag;
	string clipTag;
	int ammunition;
	weaponLayout(string whichSkill_, string experience_, int maxLevel_) :weaponTag(whichSkill_), clipTag(experience_), ammunition(maxLevel_) {}
	weaponLayout(string whichSkill_) :weaponTag(whichSkill_), clipTag(""), ammunition(0) {}
	weaponLayout() : weaponLayout(tag_WEAPON_NONE) {}
};
struct fullWeaponLayout {
	weaponLayout cplus;
	weaponLayout c;
	weaponLayout moderate;
	weaponLayout l;
	weaponLayout lplus;
	fullWeaponLayout() : cplus(weaponLayout()), c(weaponLayout()), moderate(weaponLayout()), l(weaponLayout()), lplus(weaponLayout()) {}
	fullWeaponLayout(weaponLayout cplus_, weaponLayout c_, weaponLayout moderate_, weaponLayout l_, weaponLayout lplus_) : cplus(cplus_), c(c_), moderate(moderate_), l(l_), lplus(lplus_) {}

};

const string tag_WEAPON_FLAMETHROWER = "WEAPON_FLAMETHROWER";
const string tag_LOOT_COMPUTER = "LOOT_COMPUTER";
const string tag_LOOT_CHEAPJEWELERY = "LOOT_CHEAPJEWELERY";
const string tag_LOOT_TRINKET = "LOOT_TRINKET";
const string tag_LOOT_SILVERWARE = "LOOT_SILVERWARE";
const string tag_LOOT_CELLPHONE = "LOOT_CELLPHONE";
const string tag_ARMOR_CIVILLIANARMOR = "ARMOR_CIVILLIANARMOR";
const string tag_ARMOR_SECURITYUNIFORM = "ARMOR_SECURITYUNIFORM";
const string tag_ARMOR_ARMYARMOR = "ARMOR_ARMYARMOR";
//const string tag_ARMOR = "ARMOR";
const string tag_ARMOR_HEAVYARMOR = "ARMOR_HEAVYARMOR";
const string tag_ARMOR_CHEAPSUIT = "ARMOR_CHEAPSUIT";
const string tag_ARMOR_WORKCLOTHES = "ARMOR_WORKCLOTHES";
const string tag_ARMOR_CLOTHES = "ARMOR_CLOTHES";
const string tag_ARMOR_TRENCHCOAT = "ARMOR_TRENCHCOAT";
const string tag_WEAPON_AUTORIFLE_M16 = "WEAPON_AUTORIFLE_M16";
const string tag_WEAPON_SMG_MP5 = "WEAPON_SMG_MP5";
const string tag_WEAPON_CARBINE_M4 = "WEAPON_CARBINE_M4";
//const string tag_WEAPON_REVOLVER_38 = "WEAPON_REVOLVER_38";
const string tag_WEAPON_REVOLVER_44 = "WEAPON_REVOLVER_44";
//const string tag_WEAPON_SEMIPISTOL_9MM = "WEAPON_SEMIPISTOL_9MM";
//const string tag_WEAPON_SEMIPISTOL_45 = "WEAPON_SEMIPISTOL_45";
const string tag_LOOT_PDA = "LOOT_PDA";
const string tag_LOOT_MICROPHONE = "LOOT_MICROPHONE";
const string tag_LOOT_CABLENEWSFILES = "LOOT_CABLENEWSFILES";
const string tag_LOOT_AMRADIOFILES = "LOOT_AMRADIOFILES";
const string tag_LOOT_FAMILYPHOTO = "LOOT_FAMILYPHOTO";
const string tag_LOOT_WATCH = "LOOT_WATCH";
const string tag_ARMOR_BONDAGEGEAR = "ARMOR_BONDAGEGEAR";
const string tag_ARMOR_EXPENSIVESUIT = "ARMOR_EXPENSIVESUIT";
const string tag_ARMOR_EXPENSIVEDRESS = "ARMOR_EXPENSIVEDRESS";
const string tag_LOOT_CORPFILES = "LOOT_CORPFILES";
const string tag_LOOT_CHEMICAL = "LOOT_CHEMICAL";
const string tag_LOOT_FINECLOTH = "LOOT_FINECLOTH";
const string tag_ARMOR_BUNKERGEAR = "ARMOR_BUNKERGEAR";
const string tag_LOOT_SECRETDOCUMENTS = "LOOT_SECRETDOCUMENTS";
const string tag_WEAPON_SHANK = "WEAPON_SHANK";
const string tag_ARMOR_PRISONER = "ARMOR_PRISONER";
const string tag_LOOT_JUDGEFILES = "LOOT_JUDGEFILES";
const string tag_LOOT_POLICERECORDS = "LOOT_POLICERECORDS";
const string tag_ARMOR_POLICEARMOR = "ARMOR_POLICEARMOR";
const string tag_ARMOR_SWATARMOR = "ARMOR_SWATARMOR";
const string tag_ARMOR_POLICEUNIFORM = "ARMOR_POLICEUNIFORM";
const string tag_ARMOR_DEATHSQUADUNIFORM = "ARMOR_DEATHSQUADUNIFORM";
const string tag_WEAPON_SHOTGUN_PUMP = "WEAPON_SHOTGUN_PUMP";
const string tag_WEAPON_NIGHTSTICK = "WEAPON_NIGHTSTICK";
const string tag_LOOT_LABEQUIPMENT = "LOOT_LABEQUIPMENT";
const string tag_LOOT_RESEARCHFILES = "LOOT_RESEARCHFILES";
const string tag_LOOT_EXPENSIVEJEWELERY = "LOOT_EXPENSIVEJEWELERY";
const string tag_ARMOR_BLACKROBE = "ARMOR_BLACKROBE";
const string tag_ARMOR_LABCOAT = "ARMOR_LABCOAT";
const string tag_ARMOR_BLACKDRESS = "ARMOR_BLACKDRESS";
const string tag_ARMOR_BLACKSUIT = "ARMOR_BLACKSUIT";
const string tag_WEAPON_SEMIRIFLE_AR15 = "WEAPON_SEMIRIFLE_AR15";
const string tag_WEAPON_COMBATKNIFE = "WEAPON_COMBATKNIFE";
const string tag_WEAPON_BASEBALLBAT = "WEAPON_BASEBALLBAT";
const string tag_WEAPON_DAISHO = "WEAPON_DAISHO";
const string tag_ARMOR_CLOWNSUIT = "ARMOR_CLOWNSUIT";
const string tag_ARMOR_DONKEYSUIT = "ARMOR_DONKEYSUIT";
const string tag_ARMOR_ELEPHANTSUIT = "ARMOR_ELEPHANTSUIT";
const string tag_ARMOR_CHEAPDRESS = "ARMOR_CHEAPDRESS";
const string tag_WEAPON_GUITAR = "WEAPON_GUITAR";
const string tag_LOOT_DIRTYSOCK = "LOOT_DIRTYSOCK";
const string tag_LOOT_KIDART = "LOOT_KIDART";
const string tag_ARMOR_TOGA = "ARMOR_TOGA";
const string tag_WEAPON_SYRINGE = "WEAPON_SYRINGE";
const string tag_WEAPON_CHAIN = "WEAPON_CHAIN";
const string tag_WEAPON_CROWBAR = "WEAPON_CROWBAR";

map<const short, const fullWeaponLayout> defaultWeapons = {
	map<const short, const fullWeaponLayout>::value_type(CREATURE_BOUNCER, fullWeaponLayout(weaponLayout(tag_WEAPON_SMG_MP5, tag_CLIP_SMG, 4), weaponLayout(tag_WEAPON_REVOLVER_44, tag_CLIP_44, 4), weaponLayout(tag_WEAPON_REVOLVER_38, tag_CLIP_38, 4), weaponLayout(tag_WEAPON_NIGHTSTICK), weaponLayout(tag_WEAPON_NIGHTSTICK))),
	map<const short, const fullWeaponLayout>::value_type(CREATURE_SECURITYGUARD, fullWeaponLayout(weaponLayout(tag_WEAPON_SMG_MP5, tag_CLIP_SMG, 4), weaponLayout(tag_WEAPON_NIGHTSTICK), weaponLayout(tag_WEAPON_NIGHTSTICK), weaponLayout(tag_WEAPON_NIGHTSTICK), weaponLayout(tag_WEAPON_REVOLVER_38, tag_CLIP_38, 4))),
	map<const short, const fullWeaponLayout>::value_type(CREATURE_MERC, fullWeaponLayout(weaponLayout(tag_WEAPON_AUTORIFLE_M16, tag_CLIP_ASSAULT, 7), weaponLayout(tag_WEAPON_AUTORIFLE_M16, tag_CLIP_ASSAULT, 7), weaponLayout(tag_WEAPON_AUTORIFLE_M16, tag_CLIP_ASSAULT, 7), weaponLayout(tag_WEAPON_SEMIRIFLE_AR15, tag_CLIP_ASSAULT, 7), weaponLayout(tag_WEAPON_SEMIRIFLE_AR15, tag_CLIP_ASSAULT, 7))),

};

#define AGE_TEENAGER    14+LCSrandom(4)  /* HS dropout, teenager, some fast food workers */
#define AGE_YOUNGADULT  18+LCSrandom(18) /* young lads and ladies */

weaponLayout getWeaponLayout(const short type) {
	extern short lawList[LAWNUM];
	switch (lawList[LAW_GUNCONTROL]) {
	case -2:
		return defaultWeapons[type].cplus;
	case -1:
		return defaultWeapons[type].c;
	case 0:
		return defaultWeapons[type].moderate;
	case 1:
		return defaultWeapons[type].l;
	case 2:
		return defaultWeapons[type].lplus;
	}
	return weaponLayout(tag_WEAPON_NONE);
}

void DeprecatedCreature::giveDefaultWeapon() {
	extern vector<WeaponType *> weapontype;
	extern vector<ClipType *> cliptype;
	if (defaultWeapons.count(type) >= 1) {
		weaponLayout layout = getWeaponLayout(type);
		give_weapon(*weapontype[getweapontype(layout.weaponTag)], NULL);
		if (layout.ammunition >= 1) {
			take_clips(*cliptype[getcliptype(layout.clipTag)], layout.ammunition);
		}
		reload(false);
	}
}
#include "locations/locationsPool.h"
#include "sitemode/stealth.h"
short getCurrentSite();
void DeprecatedCreature::armBouncer() {
	extern short mode;
	extern short sitetype;
	if (mode == GAMEMODE_SITE && LocationsPool::getInstance().get_specific_integer(INT_ISTHISPLACEHIGHSECURITY, getCurrentSite()))
	{
		rename(CONST_creaturetypes041);
		set_skill(SKILL_CLUB, LCSrandom(3) + 3);
	}
	if (disguisesite(sitetype))
	{
		align = ALIGN_CONSERVATIVE;
		infiltration = 0.1f*LCSrandom(4);
	}
	else align = ALIGN_MODERATE;
}

void DeprecatedCreature::armCREATURE_SCIENTIST_LABTECH() {
	extern vector<WeaponType *> weapontype;
	if (!is_armed() && !LCSrandom(2))
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SYRINGE)], NULL);
}
void DeprecatedCreature::armCREATURE_JUDGE_CONSERVATIVE() {
	extern vector<WeaponType *> weapontype;
	extern vector<ClipType *> cliptype;
	extern short lawList[LAWNUM];
	if (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(3))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_44)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_44)], 4);
	}
	else if (!LCSrandom(2))
		give_weapon(*weapontype[getweapontype(tag_WEAPON_GAVEL)], NULL);
	reload(false);
}
void DeprecatedCreature::armCREATURE_SCIENTIST_EMINENT() {
	extern vector<WeaponType *> weapontype;
	if (!is_armed() && !LCSrandom(2))
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SYRINGE)], NULL);
}
struct fullName {
	string first;
	string middle;
	string last;

};
fullName generate_long_name(char gender = GENDER_NEUTRAL);
void DeprecatedCreature::armCREATURE_CORPORATE_CEO() {
	fullName fn = generate_long_name(GENDER_WHITEMALEPATRIARCH);
	strcpy(propername, (fn.first + " " + fn.last).data());
	rename(CONST_creaturetypes042 + propername);
	dontname = true;
}
void DeprecatedCreature::armCREATURE_WORKER_FACTORY_NONUNION() {
	extern vector<WeaponType *> weapontype;
	if (!is_armed())
		give_weapon(*weapontype[getweapontype(tag_WEAPON_CHAIN)], NULL);
	if (align == ALIGN_LIBERAL) align = LCSrandom(2) - 1;
}
void DeprecatedCreature::armCREATURE_WORKER_SWEATSHOP() {
	flag |= CREATUREFLAG_ILLEGALALIEN;
}
void DeprecatedCreature::armCREATURE_LAWYER() {
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern short lawList[LAWNUM];
	if (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(3))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_38)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_38)], 1);
		reload(false);
	}
}
void DeprecatedCreature::armCREATURE_DOCTOR() {
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern short lawList[LAWNUM];
	if (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(3))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_38)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_38)], 1);
		reload(false);
	}
}
void DeprecatedCreature::armCREATURE_PSYCHOLOGIST() {
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern short lawList[LAWNUM];
	if (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(3))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_38)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_38)], 1);
		reload(false);
	}
	if (gender_liberal == GENDER_MALE || LCSrandom(2))
		give_armor(getarmortype(tag_ARMOR_CHEAPSUIT), NULL);
	else
		give_armor(getarmortype(tag_ARMOR_CHEAPDRESS), NULL);
}
void DeprecatedCreature::armCREATURE_NURSE() {
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern short lawList[LAWNUM];
	if (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(3))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_38)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_38)], 1);
		reload(false);
	}
}
void DeprecatedCreature::armCREATURE_WORKER_FACTORY_UNION() {
	extern vector<WeaponType *> weapontype;
	if (!is_armed())
		give_weapon(*weapontype[getweapontype(tag_WEAPON_CHAIN)], NULL);
}
void DeprecatedCreature::armCREATURE_TANK() {
	animalgloss = ANIMALGLOSS_TANK;
	specialattack = ATTACK_CANNON;
}

vector<string> words_meaning_hick;
vector<string> genetic_monster;

void DeprecatedCreature::armCREATURE_HICK() {
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern short lawList[LAWNUM];
	rename(pickrandom(words_meaning_hick));
	if ((lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(2)) || !LCSrandom(10))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SHOTGUN_PUMP)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_BUCKSHOT)], 4);
	}
	else
		give_weapon(*weapontype[getweapontype(LCSrandom(2) ? tag_WEAPON_TORCH : tag_WEAPON_PITCHFORK)], NULL);
	reload(false);
}
void DeprecatedCreature::armCREATURE_COP() {
	extern vector<ClipType *> cliptype;
	extern short lawList[LAWNUM];
	extern vector<WeaponType *> weapontype;
	if (lawList[LAW_POLICEBEHAVIOR] == 2 && align == ALIGN_LIBERAL && !LCSrandom(3)) // Peace Officer
	{
		align = ALIGN_MODERATE;
		rename(CONST_creaturetypes043);
		set_skill(SKILL_PERSUASION, LCSrandom(4) + 1);
		set_skill(SKILL_PISTOL, LCSrandom(3) + 1);
		set_attribute(ATTRIBUTE_HEART, 4);
	}
	else
	{
		if (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(3))
		{
			give_weapon(*weapontype[getweapontype(tag_WEAPON_SMG_MP5)], NULL);
			take_clips(*cliptype[getcliptype(tag_CLIP_SMG)], 4);
		}
		else if (!LCSrandom(3))
		{
			give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIPISTOL_9MM)], NULL);
			take_clips(*cliptype[getcliptype(tag_CLIP_9)], 4);
		}
		else if (!LCSrandom(2))
		{
			give_weapon(*weapontype[getweapontype(tag_WEAPON_SHOTGUN_PUMP)], NULL);
			take_clips(*cliptype[getcliptype(tag_CLIP_BUCKSHOT)], 4);
		}
		else
			give_weapon(*weapontype[getweapontype(tag_WEAPON_NIGHTSTICK)], NULL);
		reload(false);
		align = ALIGN_CONSERVATIVE;
		set_skill(SKILL_PISTOL, LCSrandom(4) + 1);
		set_skill(SKILL_SHOTGUN, LCSrandom(3) + 1);
		set_skill(SKILL_CLUB, LCSrandom(2) + 1);
		set_skill(SKILL_HANDTOHAND, LCSrandom(2) + 1);
		set_attribute(ATTRIBUTE_WISDOM, 4);
	}
}
bool isThereASiteAlarm();
void DeprecatedCreature::armCREATURE_FIREFIGHTER() {

	extern vector<WeaponType *> weapontype;
	extern vector<ClipType *> cliptype;
	extern short lawList[LAWNUM];
	if (lawList[LAW_FREESPEECH] == -2)
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_FLAMETHROWER)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_GASOLINE)], 4);
		reload(false);
		set_skill(SKILL_HEAVYWEAPONS, LCSrandom(3) + 2);
		rename(CONST_creaturetypes044);
		align = ALIGN_CONSERVATIVE;
	}
	else
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_AXE)], NULL);
		set_skill(SKILL_AXE, LCSrandom(3) + 2);
		rename(CONST_creaturetypes045);
	}
	if (isThereASiteAlarm()) // Respond to emergencies in bunker gear
		give_armor(getarmortype(tag_ARMOR_BUNKERGEAR), NULL);
}
void DeprecatedCreature::armCREATURE_CCS_MOLOTOV() {
	extern short mode;

	if (mode == GAMEMODE_SITE)
		nameCCSMember();
}
void DeprecatedCreature::armCREATURE_CCS_SNIPER() {
	extern short mode;

	if (mode == GAMEMODE_SITE)
		nameCCSMember();
}
void DeprecatedCreature::armCREATURE_CCS_VIGILANTE() {
	extern short mode;

	extern char endgamestate;
	extern vector<WeaponType *> weapontype;
	extern vector<ClipType *> cliptype;
	give_armor(getarmortype(tag_ARMOR_CLOTHES), NULL);
	switch (LCSrandom(5) + endgamestate)
	{
	case 0:
	case 1:
		break;
	case 2:
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIPISTOL_9MM)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_9)], 7);
	}
	break;
	case 3:
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_44)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_44)], 7);
	}
	break;
	case 4:
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SHOTGUN_PUMP)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_BUCKSHOT)], 7);
	}
	break;
	case 5:
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIRIFLE_AR15)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_ASSAULT)], 7);
		give_armor(getarmortype(tag_ARMOR_CIVILLIANARMOR), NULL);
	}
	break;
	case 6:
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIRIFLE_AR15)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_ASSAULT)], 7);
		give_armor(getarmortype(tag_ARMOR_ARMYARMOR), NULL);
	}
	break;
	default:
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_AUTORIFLE_M16)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_ASSAULT)], 7);
		give_armor(getarmortype(tag_ARMOR_ARMYARMOR), NULL);
	}
	break;
	}
	reload(false);
	if (mode == GAMEMODE_SITE)
		nameCCSMember();
}
void DeprecatedCreature::armCREATURE_CCS_ARCHCONSERVATIVE() {
	extern short mode;
	extern short sitetype;
	extern char ccs_kills;

	extern char endgamestate;
	rename((LocationsPool::getInstance().isThereASiegeHere(getCurrentSite()) ? CONST_creaturetypes046 : (ccs_kills < 2 ? CONST_creaturetypesX01 : CONST_creaturetypesX02)));
}
void DeprecatedCreature::armCREATURE_PRISONGUARD() {
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern short lawList[LAWNUM];
	if (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(3))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SMG_MP5)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_SMG)], 4);
	}
	else if (!LCSrandom(3))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SHOTGUN_PUMP)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_BUCKSHOT)], 4);
	}
	else
		give_weapon(*weapontype[getweapontype(tag_WEAPON_NIGHTSTICK)], NULL);
	reload(false);
}
void DeprecatedCreature::armCREATURE_EDUCATOR() {
	extern vector<ClipType *> cliptype;
	extern vector<WeaponType *> weapontype;
	extern short lawList[LAWNUM];
	if (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(3))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SMG_MP5)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_SMG)], 4);
	}
	else if (!LCSrandom(3))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIPISTOL_9MM)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_9)], 4);
	}
	else
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SYRINGE)], NULL);
	reload(false);
}
void DeprecatedCreature::armCREATURE_GENETIC(int(&attcap)[ATTNUM]) {
	extern short mode;
	extern short sitetype;
	extern char ccs_kills;

	extern char endgamestate;
	extern short lawList[LAWNUM];
	if (LocationsPool::getInstance().getLocationType(getCurrentSite()) == SITE_CORPORATE_HOUSE)
	{
		rename( CONST_creaturetypes047);
		attcap[ATTRIBUTE_CHARISMA] = 10;
	}
	else
		rename( blankString);
	switch (LCSrandom(11))
	{
	case 0:
		rename(getNameAndAlignment().name + CONST_creaturetypes048);
		specialattack = ATTACK_FLAME;
		break;
	case 1:
		rename(getNameAndAlignment().name + CONST_creaturetypes049);
		specialattack = ATTACK_SUCK;
		break;
	default:
		rename(getNameAndAlignment().name + pickrandom(genetic_monster));
		break;
	}
	animalgloss = ANIMALGLOSS_ANIMAL;
	if (lawList[LAW_ANIMALRESEARCH] != 2)no_money();
}
void DeprecatedCreature::armCREATURE_GUARDDOG() {
	extern short lawList[LAWNUM];
	animalgloss = ANIMALGLOSS_ANIMAL;
	if (lawList[LAW_ANIMALRESEARCH] != 2)no_money();
}

void DeprecatedCreature::armCREATURE_BUM() {
	extern vector<WeaponType *> weapontype;
	if (!is_armed() && !LCSrandom(5))
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SHANK)], NULL);
	if (align == ALIGN_CONSERVATIVE)align = LCSrandom(2);
}
void DeprecatedCreature::armCREATURE_MUTANT() {
	extern vector<WeaponType *> weapontype;
	if (!is_armed() && !LCSrandom(5))
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SHANK)], NULL);
}
void DeprecatedCreature::armCREATURE_GANGMEMBER() {
	extern vector<WeaponType *> weapontype;
	extern short mode;
	extern short sitetype;
	extern char ccs_kills;

	extern char endgamestate;
	extern short lawList[LAWNUM];
	extern vector<ClipType *> cliptype;
	if (!LCSrandom(20) || (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(5)))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_AUTORIFLE_AK47)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_ASSAULT)], 3);
	}
	else if (!LCSrandom(16) || (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(5)))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SMG_MP5)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_SMG)], 4);
	}
	else if (!LCSrandom(15))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIPISTOL_45)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_45)], 4);
	}
	else if (!LCSrandom(10))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SHOTGUN_PUMP)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_BUCKSHOT)], 4);
	}
	else if (!LCSrandom(4))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIPISTOL_9MM)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_9)], 4);
	}
	else if (!LCSrandom(2))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_38)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_38)], 4);
	}
	else
		give_weapon(*weapontype[getweapontype(tag_WEAPON_COMBATKNIFE)], NULL);
	reload(false);
	// We'll make the crack house a bit dicey
	if (LocationsPool::getInstance().getLocationType(getCurrentSite()) == SITE_BUSINESS_CRACKHOUSE)align = ALIGN_CONSERVATIVE;
	if (!LCSrandom(2))switch (LCSrandom(3))
	{
	case 0://crimes_committed[LAWFLAG_BROWNIES]++;
		criminalize_without_heat(LAWFLAG_BROWNIES);
		break;
	case 1://crimes_committed[LAWFLAG_ASSAULT]++;
		criminalize_without_heat(LAWFLAG_ASSAULT);
		break;
	case 2://crimes_committed[LAWFLAG_MURDER]++;
		criminalize_without_heat(LAWFLAG_MURDER);
		break;
	}
}
void DeprecatedCreature::armCREATURE_CRACKHEAD(int(&attcap)[ATTNUM]) {
	extern vector<WeaponType *> weapontype;
	if (!LCSrandom(5))
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SHANK)], NULL);
	if (align == ALIGN_CONSERVATIVE)align = LCSrandom(2);
	attcap[ATTRIBUTE_HEALTH] = 1 + LCSrandom(5);
}
void DeprecatedCreature::armCREATURE_FASTFOODWORKER() {
	set_age((LCSrandom(2) ? AGE_TEENAGER : AGE_YOUNGADULT));
}
void DeprecatedCreature::armCREATURE_FOOTBALLCOACH() {
	if (LCSrandom(2))
	{
		set_attribute(ATTRIBUTE_HEALTH, 5);
		set_attribute(ATTRIBUTE_AGILITY, 5);
		set_attribute(ATTRIBUTE_STRENGTH, 5);
	}
}
void DeprecatedCreature::armCREATURE_PROSTITUTE() {
	if (LCSrandom(7))gender_conservative = gender_liberal = GENDER_FEMALE;
	else if (!LCSrandom(3))gender_liberal = GENDER_FEMALE;
	if (align == ALIGN_CONSERVATIVE)align = LCSrandom(2);
	if (!LCSrandom(3)) { criminalize_without_heat(LAWFLAG_PROSTITUTION); }
}
void DeprecatedCreature::armCREATURE_HIPPIE() {
	if (!LCSrandom(10)) {
		criminalize_without_heat(LAWFLAG_BROWNIES);
	}
}
void DeprecatedCreature::armCREATURE_SOCIALITE() {
	give_armor(getarmortype(gender_liberal == GENDER_FEMALE ? tag_ARMOR_EXPENSIVEDRESS : tag_ARMOR_EXPENSIVESUIT), NULL);
}
void DeprecatedCreature::armCREATURE_THIEF() {
	switch (LCSrandom(5))
	{
	case 0:
		rename( getcreaturetype(CREATURE_SOCIALITE)->get_encounter_name());
		break;
	case 1:
		rename( getcreaturetype(CREATURE_CLERK)->get_encounter_name());
		break;
	case 2:
		rename( getcreaturetype(CREATURE_OFFICEWORKER)->get_encounter_name());
		break;
	case 3:
		rename( getcreaturetype(CREATURE_CRITIC_ART)->get_encounter_name());
		break;
	case 4:
		rename( getcreaturetype(CREATURE_CRITIC_MUSIC)->get_encounter_name());
		break;
	}
	if (!LCSrandom(10)) { criminalize_without_heat(LCSrandom(2) ? LAWFLAG_BREAKING : LAWFLAG_THEFT); }
}
void DeprecatedCreature::armCREATURE_MILITARYOFFICER() {
	extern vector<WeaponType *> weapontype;
	extern vector<ClipType *> cliptype;
	if (LCSrandom(4))
	{
		give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIPISTOL_9MM)], NULL);
		take_clips(*cliptype[getcliptype(tag_CLIP_9)], 4);
		reload(false);
	}
}
void DeprecatedCreature::armCREATURE_PRISONER() {
	const CreatureType* crtype = getcreaturetype(type);

	drop_weapons_and_clips(NULL);
	crtype->give_weapon(*this);
	strip(NULL);
	crtype->give_armor(*this);
	set_money(crtype->money_.roll());
	juice = crtype->juice_.roll();
	gender_liberal = gender_conservative = crtype->roll_gender();
	rename(crtype->get_encounter_name());
	if (align == ALIGN_CONSERVATIVE)
		align = LCSrandom(2);
}
// IsaacG Very few of the nested functions require anything other than &cr and type.  A rewrite that only uses those two parameters is desirable.
void DeprecatedCreature::armSpecificCreature(int(&attcap)[ATTNUM]) {
	switch (type)
	{
	case CREATURE_BOUNCER:
		armBouncer();
		break;
	case CREATURE_SCIENTIST_LABTECH:
		armCREATURE_SCIENTIST_LABTECH();
		break;
	case CREATURE_JUDGE_CONSERVATIVE:
		armCREATURE_JUDGE_CONSERVATIVE();
		break;
	case CREATURE_SCIENTIST_EMINENT:
		armCREATURE_SCIENTIST_EMINENT();
		break;
	case CREATURE_CORPORATE_CEO:
		armCREATURE_CORPORATE_CEO();
		break;
	case CREATURE_WORKER_FACTORY_NONUNION:
		armCREATURE_WORKER_FACTORY_NONUNION();
		break;
	case CREATURE_WORKER_SWEATSHOP:
		armCREATURE_WORKER_SWEATSHOP();
		break;
	case CREATURE_LAWYER:
		armCREATURE_LAWYER();
		break;
	case CREATURE_DOCTOR:
		armCREATURE_DOCTOR();
		break;
	case CREATURE_PSYCHOLOGIST:
		armCREATURE_PSYCHOLOGIST();
		break;
	case CREATURE_NURSE:
		armCREATURE_NURSE();
		break;
	case CREATURE_WORKER_FACTORY_UNION:
		armCREATURE_WORKER_FACTORY_UNION();
		break;
	case CREATURE_TANK:
		armCREATURE_TANK();
		break;
	case CREATURE_HICK:
		armCREATURE_HICK();
		break;
	case CREATURE_COP:
		armCREATURE_COP();
		break;
	case CREATURE_FIREFIGHTER:
		armCREATURE_FIREFIGHTER();
		break;
	case CREATURE_CCS_MOLOTOV:
		armCREATURE_CCS_MOLOTOV();
		break;
	case CREATURE_CCS_SNIPER:
		armCREATURE_CCS_SNIPER();
		break;
	case CREATURE_CCS_VIGILANTE:
		armCREATURE_CCS_VIGILANTE();
		break;
	case CREATURE_CCS_ARCHCONSERVATIVE:
		armCREATURE_CCS_ARCHCONSERVATIVE();
		break;
	case CREATURE_PRISONGUARD:
		armCREATURE_PRISONGUARD();
		break;
	case CREATURE_EDUCATOR:
		armCREATURE_EDUCATOR();
		break;
	case CREATURE_GENETIC:
		armCREATURE_GENETIC( attcap);
		break;
	case CREATURE_GUARDDOG:
		armCREATURE_GUARDDOG();
		break;
	case CREATURE_PRISONER:
		armCREATURE_PRISONER();
		break;
	case CREATURE_BUM:
		armCREATURE_BUM();
		break;
	case CREATURE_MUTANT:
		armCREATURE_MUTANT();
		break;
	case CREATURE_GANGMEMBER:
		armCREATURE_GANGMEMBER();
		break;
	case CREATURE_CRACKHEAD:
		armCREATURE_CRACKHEAD( attcap);
		break;
	case CREATURE_FASTFOODWORKER:
		armCREATURE_FASTFOODWORKER();
		break;
	case CREATURE_FOOTBALLCOACH:
		armCREATURE_FOOTBALLCOACH();
		break;
	case CREATURE_PROSTITUTE:
		armCREATURE_PROSTITUTE();
		break;
	case CREATURE_HIPPIE:
		armCREATURE_HIPPIE();
		break;
	case CREATURE_SOCIALITE:
		armCREATURE_SOCIALITE();
		break;
	case CREATURE_THIEF:
		armCREATURE_THIEF();
		break;
	case CREATURE_MILITARYOFFICER:
		armCREATURE_MILITARYOFFICER();
		break;
	}


}
void DeprecatedCreature::makecreature(const short type) {
	int verifyworklocation(const int type, const int worklocation);
	if (type == -1) {
		return;
	}
	extern short sitealienate;
	short getCurrentSite();
	drop_weapons_and_clips(NULL); // Get rid of any old equipment from old encounters.
	strip(NULL);                  //
	creatureinit();
	make_existing();
	squadid = -1;
	this->type = type;
	infiltration = 0;
	location = getCurrentSite();
	worklocation = verifyworklocation(type, location);

	armCreature();

	if (align == ALIGN_LIBERAL) infiltration = 0.15f + (LCSrandom(10) - 5)*0.01f;
	else if (align == ALIGN_MODERATE) infiltration = 0.25f + (LCSrandom(10) - 5)*0.01f;
	else infiltration += 0.35f*(1 - infiltration) + (LCSrandom(10) - 5)*0.01f;
	if (infiltration < 0) infiltration = 0;
	if (infiltration > 1) infiltration = 1;
	int randomskills = LCSrandom(4) + 4;
	if (getCreatureBio().age > 20) randomskills += static_cast<int>(randomskills*((getCreatureBio().age - 20.0) / 20.0));
	else randomskills -= (20 - getCreatureBio().age) / 2;
	vector<int> possible;
	for (int s = 0; s < SKILLNUM; s++)possible.push_back(s);
	//RANDOM STARTING SKILLS
	while (randomskills > 0 && len(possible))
	{
		int i = LCSrandom(len(possible));
		int randomskill = possible[i];
		// 95% chance of not allowing some skills for anybody...
		if (LCSrandom(20))
		{
			if (randomskill == SKILL_HEAVYWEAPONS) continue;
			if (randomskill == SKILL_SMG) continue;
			if (randomskill == SKILL_SWORD) continue;
			if (randomskill == SKILL_RIFLE) continue;
			if (randomskill == SKILL_AXE) continue;
			if (randomskill == SKILL_CLUB) continue;
			if (randomskill == SKILL_PSYCHOLOGY) continue;
		}
		// 90% chance of not allowing some skills, other than
		//   for conservatives
		if (LCSrandom(10) && align != ALIGN_CONSERVATIVE)
		{
			if (randomskill == SKILL_SHOTGUN) continue;
			if (randomskill == SKILL_PISTOL) continue;
		}
		if (skill_cap(randomskill) > get_skill(randomskill))
		{
			set_skill(randomskill, get_skill(randomskill) + 1);
			randomskills--;
			while (randomskills&&LCSrandom(2))
			{
				if (skill_cap(randomskill) > get_skill(randomskill) &&
					get_skill(randomskill) < 4)
				{
					set_skill(randomskill, get_skill(randomskill) + 1);
					randomskills--;
				}
				else
				{
					possible.erase(possible.begin() + i);
					break;
				}
			}
		}
		else possible.erase(possible.begin() + i);
	}
	//ALIENATION
	if ((sitealienate >= 1 && align == ALIGN_MODERATE) || (sitealienate == 2 && align == ALIGN_LIBERAL))conservatise();

}
const string CONST_creature108 = "New Union Worker";
void DeprecatedCreature::liberalize(bool rename) {

	extern UniqueCreatures uniqueCreatures;
	if (align == ALIGN_CONSERVATIVE && juice > 0)juice = 0;
	align = ALIGN_LIBERAL;
	if (id == uniqueCreatures.CEO().id)
		uniqueCreatures.newCEO();
	if (rename)
		switch (type)
		{
		case CREATURE_WORKER_FACTORY_NONUNION:
			this->rename(CONST_creature108);
			break;
			//    case CREATURE_JUDGE_CONSERVATIVE:
			//       strcpy(name,CONST_creature109.c_str());
			//       break;
		}
}
void DeprecatedCreature::armCreature() {
	////

	const CreatureType* crtype = getcreaturetype(type);
	crtype->make_creature(*this);
	int attnum = crtype->attribute_points_.roll();
	int attcap[ATTNUM];
	for (int i = 0; i < ATTNUM; i++)
	{
		set_attribute(i, crtype->attributes_[i].min);
		attcap[i] = crtype->attributes_[i].max;
	}
	bool skipThisCreature = false;
	for (CreatureTypes crt : doNotArmInThisFunction) {
		if (crt == type) {
			skipThisCreature = true;
			break;
		}
	}
	for (CreatureTypes crt : armAsCivilian) {
		if (crt == type) {
			crtype->give_weapon_civilian(*this);
			break;
		}
	}
	if (replaceTheseCreatures.count(type) >= 1) {
		CreatureTypes replacement = pickrandom(replaceTheseCreatures[type]);
		makecreature(replacement);
	}
	giveDefaultWeapon();
	if (!skipThisCreature)
		armSpecificCreature(attcap);

	vector<int> possible;
	for (int a = 0; a < ATTNUM; a++)
	{
		attnum -= min(4, get_attribute(a, false));
		possible.push_back(a);
	}
	while (attnum > 0 && len(possible))
	{
		int i = LCSrandom(len(possible));
		int a = possible[i];
		if (a == ATTRIBUTE_WISDOM && align == ALIGN_LIBERAL && LCSrandom(4)) a = ATTRIBUTE_HEART;
		if (a == ATTRIBUTE_HEART && align == ALIGN_CONSERVATIVE && LCSrandom(4)) a = ATTRIBUTE_WISDOM;
		if (get_attribute(a, false) < attcap[a])
		{
			adjust_attribute(a, +1);
			attnum--;
		}
		else possible.erase(possible.begin() + i);
	}

	possible.clear();
}
#include "customMaps.h"
const string creature = "creature\\";
vector<file_and_text_collection> creaturetypes_text_file_collection = {
	/*creaturetypes.cpp*/
	customText(&words_meaning_hick, creature + CONST_creaturetypes039),
	customText(&genetic_monster, creature + CONST_creaturetypes040),
};


const string singleDot = ".";
CreatureType::WeaponsAndClips::WeaponsAndClips(CMarkup& xml, const string& owner)
	: number_weapons(1),
	cliptype(tag_APPROPRIATE), number_clips(4)
{
	extern string NONE;
	extern vector<WeaponType *> weapontype;
	extern Log xmllog;
	weapon_type_str = xml.GetData();
	// Read in values.
	if (!len(weapontype))
	{
		while (xml.FindChildElem())
		{
			std::string element = xml.GetChildTagName();
			if (element == tag_type) weapon_type_str = xml.GetChildData();
			else if (element == tag_number_weapons)
				assign_interval(number_weapons, xml.GetChildData(), owner, element);
			else if (element == tag_cliptype) cliptype = xml.GetChildData();
			else if (element == tag_number_clips)
				assign_interval(number_clips, xml.GetChildData(), owner, element);
			else xmllog.log(CONST_creaturetype056 + owner + CONST_creaturetypeB086 + element);
		}
	}
	// Check values.
	if (weapon_type_str != tag_CIVILIAN)
	{
		if (getweapontype(weapon_type_str) == -1)
		{
			xmllog.log(CONST_creaturetype057 + owner + CONST_creaturetypeB086 + weapon_type_str);
			weapon_type_str = tag_WEAPON_NONE;
			cliptype = NONE;
		}
		else
		{
			const vector<attackst*>& attacks = weapontype[getweapontype(weapon_type_str)]->get_attacks();
			// Find a usable clip type for the weapon.
			if (cliptype == tag_APPROPRIATE)
			{
				cliptype = NONE;
				for (int i = 0; i < len(attacks); i++)
				{
					if (attacks[i]->uses_ammo)
					{
						cliptype = attacks[i]->ammotype;
						break;
					}
				}
			}
			// Check clip is usable by the weapon.
			else if (getcliptype(cliptype) != -1) //Must be a clip type too.
			{
				int i;
				for (i = 0; i < len(attacks) && cliptype != attacks[i]->ammotype; i++);
				if (i == len(attacks))
				{
					xmllog.log(CONST_creaturetype058 + owner + CONST_creaturetypeB078 + cliptype +
						CONST_creaturetype059 + weapon_type_str + singleDot);
					cliptype = NONE;
				}
			}
			// Undefined clip type.
			else
			{
				xmllog.log(CONST_creaturetype060 + owner + CONST_creaturetypeB086 + cliptype);
				cliptype = NONE;
			}
		}
	}
}