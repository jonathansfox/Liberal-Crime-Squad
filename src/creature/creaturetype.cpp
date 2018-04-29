
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
#include "../creature/creature.h"
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
extern Log xmllog;
extern vector<WeaponType *> weapontype;
extern vector<ArmorType *> armortype;
extern vector<ClipType *> cliptype;
extern short lawList[LAWNUM];
 string singleDot;
 // This would normally be inlined inside the Creature class in creature.h, but the Creature class
 // has to be before creaturetype
 std::string Creature::get_type_name() const { return getcreaturetype(type_idname)->get_type_name(); }
// Assign a value to an Interval from a string or log error.
void assign_interval(Interval& i, const std::string& value,
	const std::string& owner, const std::string& element)
{
	if (!i.set_interval(value))
		xmllog.log(CONST_creaturetype055 + element + CONST_creaturetypeB075 + owner + CONST_creaturetypeB086 + value);
}
int CreatureType::s_number_of_creaturetypes = 0;
CreatureType::WeaponsAndClips::WeaponsAndClips(const std::string& weapon, int weapons, const std::string& clip, int clips)
	: weapontype(weapon), number_weapons(weapons),
	cliptype(clip), number_clips(clips)
{
}
extern string NONE;
CreatureType::WeaponsAndClips::WeaponsAndClips(CMarkup& xml, const string& owner)
	: number_weapons(1),
	cliptype(tag_APPROPRIATE), number_clips(4)
{ // The main position of the CMarkup object is expected not to be changed here.
	weapontype = xml.GetData();
	// Read in values.
	if (!len(weapontype))
	{
		while (xml.FindChildElem())
		{
			std::string element = xml.GetChildTagName();
			if (element == tag_type) weapontype = xml.GetChildData();
			else if (element == tag_number_weapons)
				assign_interval(number_weapons, xml.GetChildData(), owner, element);
			else if (element == tag_cliptype) cliptype = xml.GetChildData();
			else if (element == tag_number_clips)
				assign_interval(number_clips, xml.GetChildData(), owner, element);
			else xmllog.log(CONST_creaturetype056 + owner + CONST_creaturetypeB086 + element);
		}
	}
	// Check values.
	if (weapontype != tag_CIVILIAN)
	{
		if (getweapontype(weapontype) == -1)
		{
			xmllog.log(CONST_creaturetype057 + owner + CONST_creaturetypeB086 + weapontype);
			weapontype = tag_WEAPON_NONE;
			cliptype = NONE;
		}
		else
		{
			const vector<attackst*>& attacks = ::weapontype[getweapontype(weapontype)]->get_attacks();
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
						CONST_creaturetype059 + weapontype + singleDot);
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
 string undefined;
CreatureType::CreatureType(const std::string& xmlstring)
	: age_(18, 57), alignment_public_mood_(true),
	attribute_points_(40),
	gender_liberal_(GENDER_RANDOM), gender_conservative_(GENDER_RANDOM),
	infiltration_(0), juice_(0), money_(20, 40)
{
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
		if (element == tag_alignment)
		{
			std::string alignment = xml.GetData();
			if (alignment == tag_PUBLIC_MOOD)
				alignment_public_mood_ = true;
			else if (alignment == tag_LIBERAL)
			{
				alignment_ = ALIGN_LIBERAL;
				alignment_public_mood_ = false;
			}
			else if (alignment == tag_MODERATE)
			{
				alignment_ = ALIGN_MODERATE;
				alignment_public_mood_ = false;
			}
			else if (alignment == tag_CONSERVATIVE)
			{
				alignment_ = ALIGN_CONSERVATIVE;
				alignment_public_mood_ = false;
			}
			else
				xmllog.log(CONST_creaturetype063 + idname_ + CONST_creaturetypeB086 + alignment);
		}
		else if (element == tag_age)
		{
			std::string age = xml.GetData();
			if (age == tag_DOGYEARS)
				age_.set_interval(2, 6);
			else if (age == tag_CHILD)
				age_.set_interval(7, 10);
			else if (age == tag_TEENAGER)
				age_.set_interval(14, 17);
			else if (age == tag_YOUNGADULT)
				age_.set_interval(18, 35);
			else if (age == tag_MATURE)
				age_.set_interval(20, 59);
			else if (age == tag_GRADUATE)
				age_.set_interval(26, 59);
			else if (age == tag_MIDDLEAGED)
				age_.set_interval(35, 59);
			else if (age == tag_SENIOR)
				age_.set_interval(65, 94);
			else
				assign_interval(age_, age, idname_, element);
		}
		else if (element == tag_attribute_points)
			assign_interval(attribute_points_, xml.GetData(), idname_, element);
		else if (element == tag_attributes)
		{
			while (xml.FindChildElem())
			{
				int attribute = attribute_string_to_enum(xml.GetChildTagName());
				if (attribute != -1)
					assign_interval(attributes_[attribute], xml.GetChildData(), idname_, element);
				else
					xmllog.log(CONST_creaturetype064 + idname_ + CONST_creaturetypeB086 + xml.GetTagName());
			}
		}
		else if (element == tag_juice)
			assign_interval(juice_, xml.GetData(), idname_, element);
		else if (element == tag_gender)
		{
			int gender = gender_string_to_enum(xml.GetData());
			if (gender != -1 && gender != GENDER_WHITEMALEPATRIARCH)
				gender_liberal_ = gender_conservative_ = gender;
			else
				xmllog.log(CONST_creaturetype065 + idname_ + CONST_creaturetypeB086 + xml.GetData());
		}
		else if (element == tag_infiltration)
			assign_interval(infiltration_, xml.GetData(), idname_, element);
		else if (element == tag_money)
			assign_interval(money_, xml.GetData(), idname_, element);
		else if (element == tag_skills)
		{
			while (xml.FindChildElem())
			{
				int skill = skill_string_to_enum(xml.GetChildTagName());
				if (skill != -1)
					assign_interval(skills_[skill], xml.GetChildData(), idname_, element);
				else
					xmllog.log(CONST_creaturetype066 + idname_ + CONST_creaturetypeB086 + xml.GetChildTagName());
			}
		}
		else if (element == tag_armor)
		{
			if (getarmortype(xml.GetData()) != -1)
				armortypes_.push_back(xml.GetData());
			else
				xmllog.log(CONST_creaturetype067 + idname_ + CONST_creaturetypeB086 + xml.GetData());
		}
		else if (element == tag_weapon)
		{
			//xml.SavePos(tag_creature);
			weapons_and_clips_.push_back(WeaponsAndClips(xml, idname_));
			//xml.RestorePos(tag_creature);
		}
		else if (element == tag_encounter_name)
			encounter_name_ = xml.GetData();
		else if (element == tag_type_name)
			type_name_ = xml.GetData();
		else
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
void CreatureType::make_creature(Creature& cr) const
{
	cr.type_idname = idname_;
	cr.align = get_alignment();
	cr.age = age_.roll();
	cr.juice = juice_.roll();
	cr.gender_liberal = cr.gender_conservative = roll_gender();
	cr.infiltration = roll_infiltration();
	cr.money = money_.roll();
	strcpy(cr.name, get_encounter_name());
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
		return (Alignment) a;
	}
	else return alignment_;
}
int CreatureType::roll_gender() const
{
	int gender = LCSrandom(2) + 1; // Male or female.
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
	return gender;
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
void CreatureType::give_weapon(Creature& cr) const
{
	const WeaponsAndClips& wc = pickrandom(weapons_and_clips_);
	if (wc.weapontype == tag_CIVILIAN)
		give_weapon_civilian(cr);
	else if (wc.weapontype != tag_WEAPON_NONE)
	{
		Weapon w(*weapontype[getweapontype(wc.weapontype)], wc.number_weapons.roll());
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
void CreatureType::give_weapon_civilian(Creature& cr) const
{
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
void CreatureType::give_armor(Creature& cr) const
{
	const std::string str = pickrandom(armortypes_);
	if (str != tag_ARMOR_NONE)
		cr.give_armor(*armortype[getarmortype(str)], NULL);
}