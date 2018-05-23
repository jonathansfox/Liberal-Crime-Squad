
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
extern Log xmllog;
extern vector<WeaponType *> weapontype;
Weapon& Creature::weapon_none()
{
	static Weapon unarmed(*weapontype[getweapontype(tag_WEAPON_NONE)]);
	return unarmed;
}
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
		cr.give_armor(getarmortype(str), NULL);
}

const string tag_ARMOR_EXPENSIVEDRESS = "ARMOR_EXPENSIVEDRESS";
const string tag_ARMOR_EXPENSIVESUIT = "ARMOR_EXPENSIVESUIT";
const string tag_WEAPON_SHANK = "WEAPON_SHANK";
const string tag_WEAPON_COMBATKNIFE = "WEAPON_COMBATKNIFE";
const string tag_CLIP_BUCKSHOT = "CLIP_BUCKSHOT";
const string tag_WEAPON_SHOTGUN_PUMP = "WEAPON_SHOTGUN_PUMP";
const string tag_CLIP_SMG = "CLIP_SMG";
const string tag_WEAPON_SMG_MP5 = "WEAPON_SMG_MP5";
const string tag_CLIP_ASSAULT = "CLIP_ASSAULT";
const string tag_WEAPON_AUTORIFLE_AK47 = "WEAPON_AUTORIFLE_AK47";
const string tag_WEAPON_SYRINGE = "WEAPON_SYRINGE";
const string tag_WEAPON_NIGHTSTICK = "WEAPON_NIGHTSTICK";
const string tag_ARMOR_ARMYARMOR = "ARMOR_ARMYARMOR";
const string tag_WEAPON_AUTORIFLE_M16 = "WEAPON_AUTORIFLE_M16";
const string tag_WEAPON_SEMIRIFLE_AR15 = "WEAPON_SEMIRIFLE_AR15";
const string tag_ARMOR_CIVILLIANARMOR = "ARMOR_CIVILLIANARMOR";
const string tag_CLIP_44 = "CLIP_44";
const string tag_WEAPON_REVOLVER_44 = "WEAPON_REVOLVER_44";
const string tag_ARMOR_CLOTHES = "ARMOR_CLOTHES";
const string tag_ARMOR_BUNKERGEAR = "ARMOR_BUNKERGEAR";
const string tag_WEAPON_AXE = "WEAPON_AXE";
const string tag_CLIP_GASOLINE = "CLIP_GASOLINE";
const string tag_WEAPON_FLAMETHROWER = "WEAPON_FLAMETHROWER";
const string tag_WEAPON_TORCH = "WEAPON_TORCH";
const string tag_WEAPON_PITCHFORK = "WEAPON_PITCHFORK";
const string tag_WEAPON_CHAIN = "WEAPON_CHAIN";
const string tag_ARMOR_CHEAPDRESS = "ARMOR_CHEAPDRESS";
const string tag_ARMOR_CHEAPSUIT = "ARMOR_CHEAPSUIT";
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

//#define AGE_CHILD       7+LCSrandom(4)   /* child laborer */
/* Age macros for characters */
//#define AGE_DOGYEARS    2+LCSrandom(5)   /* for the animals */
//#define AGE_MATURE      20+LCSrandom(40) /* most folks */
//#define AGE_GRADUATE    26+LCSrandom(34) /* most folks, with 6-8 years college */
//#define AGE_MIDDLEAGED  35+LCSrandom(25) /* for the more experienced types */
//#define AGE_SENIOR      65+LCSrandom(30) /* ah, social security */
/* Gender macros 
#define GIVE_GENDER_MALE                                       \
   if(lawList[LAW_WOMEN]==-2 ||                              \
   (lawList[LAW_WOMEN]==-1 && LCSrandom(25)) ||           \
   (lawList[LAW_WOMEN]==0 && LCSrandom(10)) ||            \
   (lawList[LAW_WOMEN]==1 && LCSrandom(4))) {             \
   cr.gender_conservative=cr.gender_liberal=GENDER_MALE; \
         }
#define GIVE_GENDER_FEMALE                                     \
   if(lawList[LAW_WOMEN]==-2 ||                              \
   (lawList[LAW_WOMEN]==-1 && LCSrandom(25)) ||           \
   (lawList[LAW_WOMEN]==0 && LCSrandom(10)) ||            \
   (lawList[LAW_WOMEN]==1 && LCSrandom(4))) {             \
   cr.gender_conservative=cr.gender_liberal=GENDER_FEMALE; \
   }
*/
#define AGE_TEENAGER    14+LCSrandom(4)  /* HS dropout, teenager, some fast food workers */
#define AGE_YOUNGADULT  18+LCSrandom(18) /* young lads and ladies */
extern bool multipleCityMode;
extern short sitealienate;
extern short mode;
extern short cursite;
extern short sitetype;
extern char ccs_kills;
extern short sitealarm;
extern char endgamestate;
vector<string> words_meaning_hick;
vector<string> genetic_monster;
#include "../customMaps.h"
#include "../locations/locationsPool.h"
const string creature = "creature\\";
vector<file_and_text_collection> creaturetypes_text_file_collection = {
	/*creaturetypes.cpp*/
	customText(&words_meaning_hick, creature + CONST_creaturetypes039),
	customText(&genetic_monster, creature + CONST_creaturetypes040),
};
char disguisesite(long type);
void armCreature(Creature &cr, short type) {
	const CreatureType* crtype = getcreaturetype(type);
	crtype->make_creature(cr);
	int attnum = crtype->attribute_points_.roll();
	int attcap[ATTNUM];
	for (int i = 0; i < ATTNUM; i++)
	{
		cr.set_attribute(i, crtype->attributes_[i].min);
		attcap[i] = crtype->attributes_[i].max;
	}
	switch (type)
	{
	case CREATURE_BOUNCER:
		if (mode == GAMEMODE_SITE && LocationsPool::getInstance().isThisPlaceHighSecurity(cursite))
		{
			strcpy(cr.name, CONST_creaturetypes041.c_str());
			cr.set_skill(SKILL_CLUB, LCSrandom(3) + 3);
		}
		if (lawList[LAW_GUNCONTROL] == -2)
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SMG_MP5)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_SMG)], 4);
		}
		else if (lawList[LAW_GUNCONTROL] == -1)
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_44)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_44)], 4);
		}
		else if (lawList[LAW_GUNCONTROL] == 0)
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_38)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_38)], 4);
		}
		else
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_NIGHTSTICK)], NULL);
		cr.reload(false);
		if (disguisesite(sitetype))
		{
			cr.align = ALIGN_CONSERVATIVE;
			cr.infiltration = 0.1f*LCSrandom(4);
		}
		else cr.align = ALIGN_MODERATE;
		break;
	case CREATURE_SECURITYGUARD:
		if (lawList[LAW_GUNCONTROL] == -2)
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SMG_MP5)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_SMG)], 4);
		}
		else if (lawList[LAW_GUNCONTROL] != 2)
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_38)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_38)], 4);
		}
		else
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_NIGHTSTICK)], NULL);
		cr.reload(false);
		break;
	case CREATURE_SCIENTIST_LABTECH:
		crtype->give_weapon_civilian(cr);
		if (!cr.is_armed() && !LCSrandom(2))
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SYRINGE)], NULL);
		break;
	case CREATURE_JUDGE_CONSERVATIVE:
		if (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(3))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_44)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_44)], 4);
		}
		else if (!LCSrandom(2))
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_GAVEL)], NULL);
		cr.reload(false);
		break;
	case CREATURE_SCIENTIST_EMINENT:
		crtype->give_weapon_civilian(cr);
		if (!cr.is_armed() && !LCSrandom(2))
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SYRINGE)], NULL);
		break;
	case CREATURE_CORPORATE_CEO:
		generate_name(cr.propername, GENDER_WHITEMALEPATRIARCH);
		strcpy(cr.name, CONST_creaturetypes042.c_str());
		strcat(cr.name, cr.propername);
		cr.dontname = true;
		break;
	case CREATURE_WORKER_FACTORY_NONUNION:
		crtype->give_weapon_civilian(cr);
		if (!cr.is_armed())
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_CHAIN)], NULL);
		if (cr.align == ALIGN_LIBERAL) cr.align = LCSrandom(2) - 1;
		break;
	case CREATURE_WORKER_SWEATSHOP:
		cr.flag |= CREATUREFLAG_ILLEGALALIEN;
		break;
	case CREATURE_LAWYER:
		if (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(3))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_38)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_38)], 1);
			cr.reload(false);
		}
		break;
	case CREATURE_DOCTOR:
		if (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(3))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_38)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_38)], 1);
			cr.reload(false);
		}
		break;
	case CREATURE_PSYCHOLOGIST:
		if (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(3))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_38)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_38)], 1);
			cr.reload(false);
		}
		if (cr.gender_liberal == GENDER_MALE || LCSrandom(2))
			cr.give_armor(getarmortype(tag_ARMOR_CHEAPSUIT), NULL);
		else
			cr.give_armor(getarmortype(tag_ARMOR_CHEAPDRESS), NULL);
		break;
	case CREATURE_NURSE:
		if (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(3))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_38)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_38)], 1);
			cr.reload(false);
		}
		break;
	case CREATURE_WORKER_FACTORY_UNION:
		crtype->give_weapon_civilian(cr);
		if (!cr.is_armed())
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_CHAIN)], NULL);
		break;
	case CREATURE_TANK:
		cr.animalgloss = ANIMALGLOSS_TANK;
		cr.specialattack = ATTACK_CANNON;
		break;
	case CREATURE_MERC:
		cr.give_weapon(*weapontype[getweapontype(lawList[LAW_GUNCONTROL] < 1 ? tag_WEAPON_AUTORIFLE_M16 : tag_WEAPON_SEMIRIFLE_AR15)], NULL);
		cr.take_clips(*cliptype[getcliptype(tag_CLIP_ASSAULT)], 7);
		cr.reload(false);
		break;
	case CREATURE_HICK:
		strcpy(cr.name, pickrandom(words_meaning_hick).data());
		if ((lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(2)) || !LCSrandom(10))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SHOTGUN_PUMP)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_BUCKSHOT)], 4);
		}
		else
			cr.give_weapon(*weapontype[getweapontype(LCSrandom(2) ? tag_WEAPON_TORCH : tag_WEAPON_PITCHFORK)], NULL);
		cr.reload(false);
		break;
	case CREATURE_COP:
		if (lawList[LAW_POLICEBEHAVIOR] == 2 && cr.align == ALIGN_LIBERAL && !LCSrandom(3)) // Peace Officer
		{
			cr.align = ALIGN_MODERATE;
			strcpy(cr.name, CONST_creaturetypes043.c_str());
			cr.set_skill(SKILL_PERSUASION, LCSrandom(4) + 1);
			cr.set_skill(SKILL_PISTOL, LCSrandom(3) + 1);
			cr.set_attribute(ATTRIBUTE_HEART, 4);
		}
		else
		{
			if (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(3))
			{
				cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SMG_MP5)], NULL);
				cr.take_clips(*cliptype[getcliptype(tag_CLIP_SMG)], 4);
			}
			else if (!LCSrandom(3))
			{
				cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIPISTOL_9MM)], NULL);
				cr.take_clips(*cliptype[getcliptype(tag_CLIP_9)], 4);
			}
			else if (!LCSrandom(2))
			{
				cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SHOTGUN_PUMP)], NULL);
				cr.take_clips(*cliptype[getcliptype(tag_CLIP_BUCKSHOT)], 4);
			}
			else
				cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_NIGHTSTICK)], NULL);
			cr.reload(false);
			cr.align = ALIGN_CONSERVATIVE;
			cr.set_skill(SKILL_PISTOL, LCSrandom(4) + 1);
			cr.set_skill(SKILL_SHOTGUN, LCSrandom(3) + 1);
			cr.set_skill(SKILL_CLUB, LCSrandom(2) + 1);
			cr.set_skill(SKILL_HANDTOHAND, LCSrandom(2) + 1);
			cr.set_attribute(ATTRIBUTE_WISDOM, 4);
		}
		break;
	case CREATURE_FIREFIGHTER:
		if (lawList[LAW_FREESPEECH] == -2)
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_FLAMETHROWER)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_GASOLINE)], 4);
			cr.reload(false);
			cr.set_skill(SKILL_HEAVYWEAPONS, LCSrandom(3) + 2);
			strcpy(cr.name, CONST_creaturetypes044.c_str());
			cr.align = ALIGN_CONSERVATIVE;
		}
		else
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_AXE)], NULL);
			cr.set_skill(SKILL_AXE, LCSrandom(3) + 2);
			strcpy(cr.name, CONST_creaturetypes045.c_str());
		}
		if (sitealarm) // Respond to emergencies in bunker gear
			cr.give_armor(getarmortype(tag_ARMOR_BUNKERGEAR), NULL);
		break;
	case CREATURE_CCS_MOLOTOV:
		if (mode == GAMEMODE_SITE/* && sitealarm>0*/)
			nameCCSMember(cr);
		break;
	case CREATURE_CCS_SNIPER:
		if (mode == GAMEMODE_SITE/* && sitealarm>0*/)
			nameCCSMember(cr);
		break;
	case CREATURE_CCS_VIGILANTE:
		cr.give_armor(getarmortype(tag_ARMOR_CLOTHES), NULL);
		switch (LCSrandom(5) + endgamestate)
		{
		case 0:
		case 1:
			break;
		case 2:
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIPISTOL_9MM)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_9)], 7);
			break;
		}
		case 3:
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_44)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_44)], 7);
			break;
		}
		case 4:
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SHOTGUN_PUMP)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_BUCKSHOT)], 7);
			break;
		}
		case 5:
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIRIFLE_AR15)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_ASSAULT)], 7);
			cr.give_armor(getarmortype(tag_ARMOR_CIVILLIANARMOR), NULL);
			break;
		}
		case 6:
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIRIFLE_AR15)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_ASSAULT)], 7);
			cr.give_armor(getarmortype(tag_ARMOR_ARMYARMOR), NULL);
			break;
		}
		default:
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_AUTORIFLE_M16)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_ASSAULT)], 7);
			cr.give_armor(getarmortype(tag_ARMOR_ARMYARMOR), NULL);
			break;
		}
		}
		cr.reload(false);
		if (mode == GAMEMODE_SITE/* && sitealarm>0*/)
			nameCCSMember(cr);
		break;
	case CREATURE_CCS_ARCHCONSERVATIVE:
		strcpy(cr.name, (LocationsPool::getInstance().isThereASiegeHere(cursite) ? CONST_creaturetypes046.c_str() : (ccs_kills < 2 ? CONST_creaturetypesX01.c_str() : CONST_creaturetypesX02.c_str())));
		break;
	case CREATURE_PRISONGUARD:
		if (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(3))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SMG_MP5)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_SMG)], 4);
		}
		else if (!LCSrandom(3))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SHOTGUN_PUMP)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_BUCKSHOT)], 4);
		}
		else
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_NIGHTSTICK)], NULL);
		cr.reload(false);
		break;
	case CREATURE_EDUCATOR:
		if (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(3))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SMG_MP5)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_SMG)], 4);
		}
		else if (!LCSrandom(3))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIPISTOL_9MM)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_9)], 4);
		}
		else
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SYRINGE)], NULL);
		cr.reload(false);
		break;
	case CREATURE_GENETIC:
		if (LocationsPool::getInstance().getLocationType(cursite) == SITE_CORPORATE_HOUSE)
		{
			strcpy(cr.name, CONST_creaturetypes047.c_str());
			attcap[ATTRIBUTE_CHARISMA] = 10;
		}
		else
			strcpy(cr.name, blankString.c_str());
		switch (LCSrandom(11))
		{
		case 0:strcat(cr.name, CONST_creaturetypes048.c_str());
			cr.specialattack = ATTACK_FLAME; break;
		case 1:strcat(cr.name, CONST_creaturetypes049.c_str());
			cr.specialattack = ATTACK_SUCK; break;
		default:
			strcat(cr.name, pickrandom(genetic_monster).data());
			break;
		}
		cr.animalgloss = ANIMALGLOSS_ANIMAL;
		if (lawList[LAW_ANIMALRESEARCH] != 2)cr.money = 0;
		break;
	case CREATURE_GUARDDOG:
		cr.animalgloss = ANIMALGLOSS_ANIMAL;
		if (lawList[LAW_ANIMALRESEARCH] != 2)cr.money = 0;
		break;
	case CREATURE_PRISONER:
		// Prisoners should not be prisoners after recruiting them,
		// they should be some brand of criminal
		if (!LCSrandom(10))
		{
			// Thief
			makecreature(cr, CREATURE_THIEF);
		}
		else switch (LCSrandom(5))
		{
		case 0:
			// Gang member
			makecreature(cr, CREATURE_GANGMEMBER);
			break;
		case 1:
			// Prostitute
			makecreature(cr, CREATURE_PROSTITUTE);
			break;
		case 2:
			// Crack head
			makecreature(cr, CREATURE_CRACKHEAD);
			break;
		case 3:
			// Teenager
			makecreature(cr, CREATURE_TEENAGER);
			break;
		case 4:
			// HS Dropout
			makecreature(cr, CREATURE_HSDROPOUT);
			break;
		}
		cr.drop_weapons_and_clips(NULL);
		crtype->give_weapon(cr);
		cr.strip(NULL);
		crtype->give_armor(cr);
		cr.money = crtype->money_.roll();
		cr.juice = crtype->juice_.roll();
		cr.gender_liberal = cr.gender_conservative = crtype->roll_gender();
		strcpy(cr.name, crtype->get_encounter_name().c_str());
		if (cr.align == ALIGN_CONSERVATIVE)
			cr.align = LCSrandom(2);
		break;
	case CREATURE_BUM:
		crtype->give_weapon_civilian(cr);
		if (!cr.is_armed() && !LCSrandom(5))
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SHANK)], NULL);
		if (cr.align == ALIGN_CONSERVATIVE)cr.align = LCSrandom(2);
		break;
	case CREATURE_MUTANT:
		crtype->give_weapon_civilian(cr);
		if (!cr.is_armed() && !LCSrandom(5))
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SHANK)], NULL);
		break;
	case CREATURE_GANGMEMBER:
		if (!LCSrandom(20) || (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(5)))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_AUTORIFLE_AK47)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_ASSAULT)], 3);
		}
		else if (!LCSrandom(16) || (lawList[LAW_GUNCONTROL] == -2 && !LCSrandom(5)))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SMG_MP5)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_SMG)], 4);
		}
		else if (!LCSrandom(15))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIPISTOL_45)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_45)], 4);
		}
		else if (!LCSrandom(10))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SHOTGUN_PUMP)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_BUCKSHOT)], 4);
		}
		else if (!LCSrandom(4))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIPISTOL_9MM)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_9)], 4);
		}
		else if (!LCSrandom(2))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_REVOLVER_38)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_38)], 4);
		}
		else
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_COMBATKNIFE)], NULL);
		cr.reload(false);
		// We'll make the crack house a bit dicey
		if (LocationsPool::getInstance().getLocationType(cursite) == SITE_BUSINESS_CRACKHOUSE)cr.align = ALIGN_CONSERVATIVE;
		if (!LCSrandom(2))switch (LCSrandom(3))
		{
		case 0://cr.crimes_committed[LAWFLAG_BROWNIES]++;
			cr.crimes_suspected[LAWFLAG_BROWNIES]++; break;
		case 1://cr.crimes_committed[LAWFLAG_ASSAULT]++;
			cr.crimes_suspected[LAWFLAG_ASSAULT]++; break;
		case 2://cr.crimes_committed[LAWFLAG_MURDER]++;
			cr.crimes_suspected[LAWFLAG_MURDER]++; break;
		}
		break;
	case CREATURE_CRACKHEAD:
		crtype->give_weapon_civilian(cr);
		if (!LCSrandom(5))
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SHANK)], NULL);
		if (cr.align == ALIGN_CONSERVATIVE)cr.align = LCSrandom(2);
		attcap[ATTRIBUTE_HEALTH] = 1 + LCSrandom(5);
		break;
	case CREATURE_FASTFOODWORKER:
		cr.age = (LCSrandom(2) ? AGE_TEENAGER : AGE_YOUNGADULT);
		break;
	case CREATURE_FOOTBALLCOACH:
		if (LCSrandom(2))
		{
			cr.set_attribute(ATTRIBUTE_HEALTH, 5);
			cr.set_attribute(ATTRIBUTE_AGILITY, 5);
			cr.set_attribute(ATTRIBUTE_STRENGTH, 5);
		}
		break;
	case CREATURE_PROSTITUTE:
		if (LCSrandom(7))cr.gender_conservative = cr.gender_liberal = GENDER_FEMALE;
		else if (!LCSrandom(3))cr.gender_liberal = GENDER_FEMALE;
		if (cr.align == ALIGN_CONSERVATIVE)cr.align = LCSrandom(2);
		if (!LCSrandom(3))cr.crimes_suspected[LAWFLAG_PROSTITUTION]++;
		break;
	case CREATURE_HIPPIE:
		if (!LCSrandom(10))
			cr.crimes_suspected[LAWFLAG_BROWNIES]++;
		break;
	case CREATURE_SOCIALITE:
		cr.give_armor(getarmortype(cr.gender_liberal == GENDER_FEMALE ? tag_ARMOR_EXPENSIVEDRESS : tag_ARMOR_EXPENSIVESUIT), NULL);
		break;
	case CREATURE_THIEF:
		switch (LCSrandom(5))
		{
		case 0:strcpy(cr.name, getcreaturetype(CREATURE_SOCIALITE)->get_encounter_name().c_str()); break;
		case 1:strcpy(cr.name, getcreaturetype(CREATURE_CLERK)->get_encounter_name().c_str()); break;
		case 2:strcpy(cr.name, getcreaturetype(CREATURE_OFFICEWORKER)->get_encounter_name().c_str()); break;
		case 3:strcpy(cr.name, getcreaturetype(CREATURE_CRITIC_ART)->get_encounter_name().c_str()); break;
		case 4:strcpy(cr.name, getcreaturetype(CREATURE_CRITIC_MUSIC)->get_encounter_name().c_str()); break;
		}
		if (!LCSrandom(10))cr.crimes_suspected[(LCSrandom(2) ? LAWFLAG_BREAKING : LAWFLAG_THEFT)]++;
		break;
	case CREATURE_MILITARYOFFICER:
		if (LCSrandom(4))
		{
			cr.give_weapon(*weapontype[getweapontype(tag_WEAPON_SEMIPISTOL_9MM)], NULL);
			cr.take_clips(*cliptype[getcliptype(tag_CLIP_9)], 4);
			cr.reload(false);
		}
		break;
	case CREATURE_JUDGE_LIBERAL:
	case CREATURE_POLITICIAN:
	case CREATURE_CORPORATE_MANAGER:
	case CREATURE_WORKER_SERVANT:
	case CREATURE_WORKER_JANITOR:
	case CREATURE_WORKER_SECRETARY:
	case CREATURE_LANDLORD:
	case CREATURE_BANK_TELLER:
	case CREATURE_BANK_MANAGER:
	case CREATURE_TEENAGER:
	case CREATURE_SOLDIER:
	case CREATURE_VETERAN:
	case CREATURE_HARDENED_VETERAN:
	case CREATURE_SWAT:
	case CREATURE_DEATHSQUAD:
	case CREATURE_GANGUNIT:
	case CREATURE_AGENT:
	case CREATURE_SECRET_SERVICE:
	case CREATURE_RADIOPERSONALITY:
	case CREATURE_NEWSANCHOR:
	case CREATURE_JUROR:
	case CREATURE_WORKER_FACTORY_CHILD:
	case CREATURE_SEWERWORKER:
	case CREATURE_COLLEGESTUDENT:
	case CREATURE_MUSICIAN:
	case CREATURE_MATHEMATICIAN:
	case CREATURE_TEACHER:
	case CREATURE_HSDROPOUT:
	case CREATURE_PRIEST:
	case CREATURE_ENGINEER:
	case CREATURE_TELEMARKETER:
	case CREATURE_CARSALESMAN:
	case CREATURE_OFFICEWORKER:
	case CREATURE_MAILMAN:
	case CREATURE_GARBAGEMAN:
	case CREATURE_PLUMBER:
	case CREATURE_CHEF:
	case CREATURE_CONSTRUCTIONWORKER:
	case CREATURE_AMATEURMAGICIAN:
	case CREATURE_AUTHOR:
	case CREATURE_JOURNALIST:
	case CREATURE_CRITIC_ART:
	case CREATURE_CRITIC_MUSIC:
	case CREATURE_BIKER:
	case CREATURE_TRUCKER:
	case CREATURE_TAXIDRIVER:
	case CREATURE_PROGRAMMER:
	case CREATURE_NUN:
	case CREATURE_RETIREE:
	case CREATURE_PAINTER:
	case CREATURE_SCULPTOR:
	case CREATURE_DANCER:
	case CREATURE_PHOTOGRAPHER:
	case CREATURE_CAMERAMAN:
	case CREATURE_HAIRSTYLIST:
	case CREATURE_FASHIONDESIGNER:
	case CREATURE_CLERK:
	case CREATURE_ACTOR:
	case CREATURE_YOGAINSTRUCTOR:
	case CREATURE_MARTIALARTIST:
	case CREATURE_ATHLETE:
	case CREATURE_LOCKSMITH:
	case CREATURE_MILITARYPOLICE:
	case CREATURE_SEAL:
		break;
	}


	vector<int> possible;
	for (int a = 0; a < ATTNUM; a++)
	{
		attnum -= min(4, cr.get_attribute(a, false));
		possible.push_back(a);
	}
	while (attnum > 0 && len(possible))
	{
		int i = LCSrandom(len(possible));
		int a = possible[i];
		if (a == ATTRIBUTE_WISDOM && cr.align == ALIGN_LIBERAL && LCSrandom(4)) a = ATTRIBUTE_HEART;
		if (a == ATTRIBUTE_HEART && cr.align == ALIGN_CONSERVATIVE && LCSrandom(4)) a = ATTRIBUTE_WISDOM;
		if (cr.get_attribute(a, false) < attcap[a])
		{
			cr.adjust_attribute(a, +1);
			attnum--;
		}
		else possible.erase(possible.begin() + i);
	}

	possible.clear();
}


/* rolls up a creature's stats and equipment */
void makecreature(Creature &cr, short type)
{
	cr.drop_weapons_and_clips(NULL); // Get rid of any old equipment from old encounters.
	cr.strip(NULL);                  //
	cr.creatureinit();
	cr.exists = 1;
	cr.squadid = -1;
	cr.type = type;
	cr.infiltration = 0;
	cr.location = cursite;
	cr.worklocation = cursite;
	verifyworklocation(cr);

	armCreature(cr, type);

	if (cr.align == ALIGN_LIBERAL) cr.infiltration = 0.15f + (LCSrandom(10) - 5)*0.01f;
	else if (cr.align == ALIGN_MODERATE) cr.infiltration = 0.25f + (LCSrandom(10) - 5)*0.01f;
	else cr.infiltration += 0.35f*(1 - cr.infiltration) + (LCSrandom(10) - 5)*0.01f;
	if (cr.infiltration < 0) cr.infiltration = 0;
	if (cr.infiltration > 1) cr.infiltration = 1;
	int randomskills = LCSrandom(4) + 4;
	if (cr.age > 20) randomskills += static_cast<int>(randomskills*((cr.age - 20.0) / 20.0));
	else randomskills -= (20 - cr.age) / 2;
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
		if (LCSrandom(10) && cr.align != ALIGN_CONSERVATIVE)
		{
			if (randomskill == SKILL_SHOTGUN) continue;
			if (randomskill == SKILL_PISTOL) continue;
		}
		if (cr.skill_cap(randomskill, true) > cr.get_skill(randomskill))
		{
			cr.set_skill(randomskill, cr.get_skill(randomskill) + 1);
			randomskills--;
			while (randomskills&&LCSrandom(2))
			{
				if (cr.skill_cap(randomskill, true) > cr.get_skill(randomskill) &&
					cr.get_skill(randomskill) < 4)
				{
					cr.set_skill(randomskill, cr.get_skill(randomskill) + 1);
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
	if ((sitealienate >= 1 && cr.align == ALIGN_MODERATE) || (sitealienate == 2 && cr.align == ALIGN_LIBERAL))conservatise(cr);
}
/* ensures that the creature's work location is appropriate to its type */
bool verifyworklocation(Creature &cr, char test_location, char test_type)
{
	int okaysite[SITENUM];
	memset(okaysite, 0, SITENUM * sizeof(int));
	// If the caller sets test_type, they're just
	// asking if the chosen creature type is appropriate
	// to the location they provided, not actually setting
	// the creature work location -- this is useful
	// for things like stealth
	short type = (test_type != -1 ? test_type : cr.type);
	// TODO this can be extracted to a table
	switch (type)
	{
	case CREATURE_BOUNCER:
		okaysite[SITE_BUSINESS_CIGARBAR] = 1;
		break;
	case CREATURE_POLITICIAN:
		okaysite[SITE_GOVERNMENT_WHITE_HOUSE] = 1;
		break;
	case CREATURE_CORPORATE_CEO:
		okaysite[SITE_CORPORATE_HEADQUARTERS] = 1;
		break;
	case CREATURE_SECURITYGUARD:
		okaysite[SITE_RESIDENTIAL_APARTMENT_UPSCALE] = 1;
		okaysite[SITE_LABORATORY_COSMETICS] = 1;
		okaysite[SITE_LABORATORY_GENETIC] = 1;
		okaysite[SITE_GOVERNMENT_COURTHOUSE] = 1;
		okaysite[SITE_GOVERNMENT_INTELLIGENCEHQ] = 1;
		okaysite[SITE_INDUSTRY_SWEATSHOP] = 1;
		okaysite[SITE_INDUSTRY_POLLUTER] = 1;
		okaysite[SITE_INDUSTRY_NUCLEAR] = 1;
		okaysite[SITE_CORPORATE_HEADQUARTERS] = 1;
		okaysite[SITE_CORPORATE_HOUSE] = 1;
		okaysite[SITE_MEDIA_AMRADIO] = 1;
		okaysite[SITE_MEDIA_CABLENEWS] = 1;
		okaysite[SITE_BUSINESS_CIGARBAR] = 1;
		okaysite[SITE_BUSINESS_BANK] = 1;
		//okaysite[SITE_GOVERNMENT_FIRESTATION]=1;
		break;
	case CREATURE_BANK_MANAGER:
	case CREATURE_BANK_TELLER:
		okaysite[SITE_BUSINESS_BANK] = 1;
		break;
	case CREATURE_SCIENTIST_LABTECH:
		okaysite[SITE_LABORATORY_COSMETICS] = 1;
		okaysite[SITE_LABORATORY_GENETIC] = 1;
		okaysite[SITE_INDUSTRY_NUCLEAR] = 1;
		break;
	case CREATURE_SCIENTIST_EMINENT:
		okaysite[SITE_LABORATORY_COSMETICS] = 1;
		okaysite[SITE_LABORATORY_GENETIC] = 1;
		okaysite[SITE_INDUSTRY_NUCLEAR] = 1;
		break;
	case CREATURE_CORPORATE_MANAGER:
		okaysite[SITE_LABORATORY_COSMETICS] = 1;
		okaysite[SITE_LABORATORY_GENETIC] = 1;
		okaysite[SITE_INDUSTRY_SWEATSHOP] = 1;
		okaysite[SITE_INDUSTRY_POLLUTER] = 1;
		okaysite[SITE_INDUSTRY_NUCLEAR] = 1;
		okaysite[SITE_CORPORATE_HEADQUARTERS] = 1;
		okaysite[SITE_MEDIA_AMRADIO] = 1;
		okaysite[SITE_MEDIA_CABLENEWS] = 1;
		break;
	case CREATURE_WORKER_SERVANT:
		okaysite[SITE_CORPORATE_HOUSE] = 1;
		break;
	case CREATURE_WORKER_JANITOR:
		okaysite[SITE_RESIDENTIAL_TENEMENT] = 1;
		okaysite[SITE_RESIDENTIAL_APARTMENT] = 1;
		okaysite[SITE_RESIDENTIAL_APARTMENT_UPSCALE] = 1;
		okaysite[SITE_LABORATORY_COSMETICS] = 1;
		okaysite[SITE_LABORATORY_GENETIC] = 1;
		okaysite[SITE_HOSPITAL_CLINIC] = 1;
		okaysite[SITE_HOSPITAL_UNIVERSITY] = 1;
		okaysite[SITE_GOVERNMENT_POLICESTATION] = 1;
		okaysite[SITE_GOVERNMENT_COURTHOUSE] = 1;
		okaysite[SITE_GOVERNMENT_PRISON] = 1;
		okaysite[SITE_GOVERNMENT_INTELLIGENCEHQ] = 1;
		okaysite[SITE_INDUSTRY_POLLUTER] = 1;
		okaysite[SITE_INDUSTRY_NUCLEAR] = 1;
		okaysite[SITE_CORPORATE_HEADQUARTERS] = 1;
		okaysite[SITE_MEDIA_AMRADIO] = 1;
		okaysite[SITE_MEDIA_CABLENEWS] = 1;
		okaysite[SITE_BUSINESS_PAWNSHOP] = 1;
		okaysite[SITE_BUSINESS_CRACKHOUSE] = 1;
		okaysite[SITE_BUSINESS_JUICEBAR] = 1;
		okaysite[SITE_BUSINESS_CIGARBAR] = 1;
		okaysite[SITE_BUSINESS_LATTESTAND] = 1;
		okaysite[SITE_BUSINESS_VEGANCOOP] = 1;
		okaysite[SITE_BUSINESS_INTERNETCAFE] = 1;
		okaysite[SITE_BUSINESS_DEPTSTORE] = 1;
		okaysite[SITE_BUSINESS_HALLOWEEN] = 1;
		okaysite[SITE_GOVERNMENT_FIRESTATION] = 1;
		break;
	case CREATURE_WORKER_SWEATSHOP:
		okaysite[SITE_INDUSTRY_SWEATSHOP] = 1;
		break;
	case CREATURE_WORKER_FACTORY_NONUNION:
		okaysite[SITE_INDUSTRY_POLLUTER] = 1;
		break;
	case CREATURE_WORKER_FACTORY_CHILD:
		okaysite[SITE_INDUSTRY_POLLUTER] = 1;
		break;
	case CREATURE_WORKER_SECRETARY:
		okaysite[SITE_LABORATORY_COSMETICS] = 1;
		okaysite[SITE_LABORATORY_GENETIC] = 1;
		okaysite[SITE_HOSPITAL_CLINIC] = 1;
		okaysite[SITE_HOSPITAL_UNIVERSITY] = 1;
		okaysite[SITE_GOVERNMENT_POLICESTATION] = 1;
		okaysite[SITE_GOVERNMENT_COURTHOUSE] = 1;
		okaysite[SITE_GOVERNMENT_INTELLIGENCEHQ] = 1;
		okaysite[SITE_INDUSTRY_POLLUTER] = 1;
		okaysite[SITE_INDUSTRY_NUCLEAR] = 1;
		okaysite[SITE_CORPORATE_HEADQUARTERS] = 1;
		okaysite[SITE_CORPORATE_HOUSE] = 1;
		okaysite[SITE_MEDIA_AMRADIO] = 1;
		okaysite[SITE_MEDIA_CABLENEWS] = 1;
		okaysite[SITE_GOVERNMENT_FIRESTATION] = 1;
		okaysite[SITE_GOVERNMENT_WHITE_HOUSE] = 1;
		break;
	case CREATURE_WORKER_FACTORY_UNION:
		okaysite[SITE_INDUSTRY_POLLUTER] = 1;
		break;
	case CREATURE_LANDLORD:
		okaysite[SITE_RESIDENTIAL_TENEMENT] = 1;
		okaysite[SITE_RESIDENTIAL_APARTMENT] = 1;
		okaysite[SITE_RESIDENTIAL_APARTMENT_UPSCALE] = 1;
		break;
	case CREATURE_TEENAGER:
		okaysite[SITE_RESIDENTIAL_TENEMENT] = 1;
		okaysite[SITE_RESIDENTIAL_APARTMENT] = 1;
		okaysite[SITE_RESIDENTIAL_APARTMENT_UPSCALE] = 1;
		okaysite[SITE_RESIDENTIAL_SHELTER] = 1;
		okaysite[SITE_CORPORATE_HOUSE] = 1;
		break;
	case CREATURE_COP:
		okaysite[SITE_GOVERNMENT_POLICESTATION] = 1;
		break;
	case CREATURE_DEATHSQUAD:
		okaysite[SITE_GOVERNMENT_POLICESTATION] = 1;
		break;
	case CREATURE_FIREFIGHTER:
		okaysite[SITE_GOVERNMENT_FIRESTATION] = 1;
		break;
	case CREATURE_GANGUNIT:
		okaysite[SITE_GOVERNMENT_POLICESTATION] = 1;
		break;
	case CREATURE_SWAT:
		okaysite[SITE_GOVERNMENT_POLICESTATION] = 1;
		break;
	case CREATURE_JUDGE_LIBERAL:
		okaysite[SITE_GOVERNMENT_COURTHOUSE] = 1;
		break;
	case CREATURE_JUDGE_CONSERVATIVE:
		okaysite[SITE_GOVERNMENT_COURTHOUSE] = 1;
		break;
	case CREATURE_SECRET_SERVICE:
		okaysite[SITE_GOVERNMENT_WHITE_HOUSE] = 1;
		break;
	case CREATURE_AGENT:
		okaysite[SITE_GOVERNMENT_INTELLIGENCEHQ] = 1;
		break;
	case CREATURE_RADIOPERSONALITY:
		okaysite[SITE_MEDIA_AMRADIO] = 1;
		break;
	case CREATURE_NEWSANCHOR:
		okaysite[SITE_MEDIA_CABLENEWS] = 1;
		break;
	case CREATURE_GENETIC:
		okaysite[SITE_LABORATORY_GENETIC] = 1;
		break;
	case CREATURE_GUARDDOG:
		okaysite[SITE_GOVERNMENT_PRISON] = 1;
		okaysite[SITE_GOVERNMENT_INTELLIGENCEHQ] = 1;
		okaysite[SITE_CORPORATE_HOUSE] = 1;
		okaysite[SITE_GOVERNMENT_ARMYBASE] = 1;
		break;
	case CREATURE_PRISONER:
		okaysite[SITE_RESIDENTIAL_TENEMENT] = 1;
		okaysite[SITE_RESIDENTIAL_SHELTER] = 1;
		break;
	case CREATURE_JUROR:
		okaysite[SITE_RESIDENTIAL_APARTMENT] = 1;
		okaysite[SITE_RESIDENTIAL_TENEMENT] = 1;
		okaysite[SITE_RESIDENTIAL_SHELTER] = 1;
		break;
	case CREATURE_LAWYER:
		okaysite[SITE_GOVERNMENT_COURTHOUSE] = 1;
		okaysite[SITE_GOVERNMENT_WHITE_HOUSE] = 1;
		break;
	case CREATURE_DOCTOR:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		break;
	case CREATURE_PSYCHOLOGIST:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		break;
	case CREATURE_NURSE:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_CCS_ARCHCONSERVATIVE:
	case CREATURE_CCS_MOLOTOV:
	case CREATURE_CCS_SNIPER:
	case CREATURE_CCS_VIGILANTE:
		if (ccs_kills == 2)okaysite[SITE_OUTDOOR_BUNKER] = 1;
		if (ccs_kills == 1)okaysite[SITE_RESIDENTIAL_BOMBSHELTER] = 1;
		if (ccs_kills == 0)okaysite[SITE_BUSINESS_BARANDGRILL] = 1;
		break;
	case CREATURE_SEWERWORKER:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_COLLEGESTUDENT:
		okaysite[SITE_UDISTRICT] = 1;
		break;
	case CREATURE_MUSICIAN:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_MATHEMATICIAN:
		okaysite[SITE_UDISTRICT] = 1;
		break;
	case CREATURE_TEACHER:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_HSDROPOUT:
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_BUM:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		okaysite[SITE_RESIDENTIAL_SHELTER] = 1;
		break;
	case CREATURE_GANGMEMBER:
		okaysite[SITE_BUSINESS_CRACKHOUSE] = 1;
		break;
	case CREATURE_CRACKHEAD:
		okaysite[SITE_BUSINESS_CRACKHOUSE] = 1;
		break;
	case CREATURE_PRIEST:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_ENGINEER:
		okaysite[SITE_MEDIA_AMRADIO] = 1;
		okaysite[SITE_MEDIA_CABLENEWS] = 1;
		okaysite[SITE_INDUSTRY_NUCLEAR] = 1;
		break;
	case CREATURE_FASTFOODWORKER:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_BAKER:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_BARISTA:
		okaysite[SITE_BUSINESS_LATTESTAND] = 1;
		okaysite[SITE_BUSINESS_INTERNETCAFE] = 1;
		break;
	case CREATURE_BARTENDER:
		okaysite[SITE_BUSINESS_CIGARBAR] = 1;
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_TELEMARKETER:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_CARSALESMAN:
		okaysite[SITE_BUSINESS_CARDEALERSHIP] = 1;
		break;
	case CREATURE_OFFICEWORKER:
		okaysite[SITE_LABORATORY_COSMETICS] = 1;
		okaysite[SITE_LABORATORY_GENETIC] = 1;
		okaysite[SITE_HOSPITAL_CLINIC] = 1;
		okaysite[SITE_HOSPITAL_UNIVERSITY] = 1;
		okaysite[SITE_GOVERNMENT_COURTHOUSE] = 1;
		okaysite[SITE_CORPORATE_HEADQUARTERS] = 1;
		okaysite[SITE_MEDIA_AMRADIO] = 1;
		okaysite[SITE_MEDIA_CABLENEWS] = 1;
		okaysite[SITE_BUSINESS_DEPTSTORE] = 1;
		okaysite[SITE_GOVERNMENT_WHITE_HOUSE] = 1;
		break;
	case CREATURE_FOOTBALLCOACH:
		okaysite[SITE_UDISTRICT] = 1;
		break;
	case CREATURE_PROSTITUTE:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_MAILMAN:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_GARBAGEMAN:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_PLUMBER:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_CHEF:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		okaysite[SITE_BUSINESS_CIGARBAR] = 1;
		break;
	case CREATURE_CONSTRUCTIONWORKER:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_AMATEURMAGICIAN:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_TANK:
		okaysite[SITE_GOVERNMENT_ARMYBASE] = 1;
		break;
	case CREATURE_MERC:
		okaysite[SITE_CORPORATE_HEADQUARTERS] = 1;
		okaysite[SITE_CORPORATE_HOUSE] = 1;
		okaysite[SITE_INDUSTRY_NUCLEAR] = 1;
		okaysite[SITE_LABORATORY_GENETIC] = 1;
		okaysite[SITE_BUSINESS_BANK] = 1;
		break;
	case CREATURE_HICK:
		okaysite[SITE_MEDIA_AMRADIO] = 1;
		okaysite[SITE_MEDIA_CABLENEWS] = 1;
		okaysite[SITE_OUTOFTOWN] = 1;
		break;
	case CREATURE_VETERAN:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_HARDENED_VETERAN:
	case CREATURE_SOLDIER:
	case CREATURE_MILITARYPOLICE:
	case CREATURE_MILITARYOFFICER:
	case CREATURE_SEAL:
		okaysite[SITE_GOVERNMENT_ARMYBASE] = 1;
		break;
	case CREATURE_EDUCATOR:
	case CREATURE_PRISONGUARD:
		okaysite[SITE_GOVERNMENT_PRISON] = 1;
		break;
	case CREATURE_HIPPIE:
		okaysite[SITE_BUSINESS_VEGANCOOP] = 1;
		break;
	case CREATURE_CRITIC_ART:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		okaysite[SITE_MEDIA_CABLENEWS] = 1;
		break;
	case CREATURE_CRITIC_MUSIC:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		okaysite[SITE_MEDIA_AMRADIO] = 1;
		break;
	case CREATURE_SOCIALITE:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_PROGRAMMER:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		okaysite[SITE_GOVERNMENT_INTELLIGENCEHQ] = 1;
		okaysite[SITE_CORPORATE_HEADQUARTERS] = 1;
		break;
	case CREATURE_RETIREE:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_PAINTER:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_SCULPTOR:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_AUTHOR:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_JOURNALIST:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_DANCER:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_PHOTOGRAPHER:
		okaysite[SITE_MEDIA_CABLENEWS] = 1;
		break;
	case CREATURE_CAMERAMAN:
		okaysite[SITE_MEDIA_CABLENEWS] = 1;
		break;
	case CREATURE_HAIRSTYLIST:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_FASHIONDESIGNER:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_CLERK:
		okaysite[SITE_BUSINESS_JUICEBAR] = 1;
		okaysite[SITE_BUSINESS_LATTESTAND] = 1;
		okaysite[SITE_BUSINESS_INTERNETCAFE] = 1;
		okaysite[SITE_BUSINESS_DEPTSTORE] = 1;
		okaysite[SITE_BUSINESS_HALLOWEEN] = 1;
		break;
	case CREATURE_THIEF:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_ACTOR:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_YOGAINSTRUCTOR:
		okaysite[SITE_BUSINESS_VEGANCOOP] = 1;
		break;
	case CREATURE_MARTIALARTIST:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_ATHLETE:
		okaysite[SITE_UDISTRICT] = 1;
		break;
	case CREATURE_BIKER:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_TRUCKER:
		okaysite[SITE_OUTOFTOWN] = 1;
		break;
	case CREATURE_TAXIDRIVER:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_NUN:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	case CREATURE_LOCKSMITH:
		okaysite[SITE_DOWNTOWN] = 1;
		okaysite[SITE_UDISTRICT] = 1;
		okaysite[SITE_INDUSTRIAL] = 1;
		break;
	default:
		okaysite[SITE_RESIDENTIAL_SHELTER] = 1;
		break;
	}
	// Quick exit if only checking if a certain type works
	if (test_type != -1) return okaysite[(int)test_location];
	char swap = 0;
	if (cr.worklocation == -1) swap = 1;
	else if (!okaysite[(int)LocationsPool::getInstance().getLocationType((int)cr.worklocation)]) swap = 1;
	if (swap)
	{
		//int city = location[cr.location]->city;
		//PICK A TYPE OF WORK LOCATION
		//cr.worklocation=choose_one(okaysite,SITENUM,0);
		//FIND ONE OF THESE
		vector<int> goodlist;
		//find_site_index_in_city(cr.worklocation, location[cr.location]->city);
		for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
			//if(location[l]->type==cr.worklocation && (!multipleCityMode || location[l]->city == cr.location))
			if (okaysite[(int)LocationsPool::getInstance().getLocationType(l)] && (!multipleCityMode || LocationsPool::getInstance().getLocationCity(l) == LocationsPool::getInstance().getLocationCity(cr.location)))
				goodlist.push_back(l);
		// Sadler - This line sometimes causes a memory fault
		//               Only thing I can think of is if loop above didn't
		//               find any locations of type == to cr.worklocation
		//               My hunch is that some locations, such as the 1st four
		//               are special and cannot be used here..
		//
		//   TODO There was a bug in the makecharacter() code where the
		//   SITE_OUTOFTOWN was not set properly. This was fixed but the bug here
		//   is still occurring, normally at the Latte Bar Downtown ;
		if (!len(goodlist)) cr.worklocation = 0;
		else cr.worklocation = pickrandom(goodlist);
	}
	return false;
}