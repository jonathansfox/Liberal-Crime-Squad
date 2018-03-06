/*
Copyright (c) 2002,2003,2004 by Tarn Adams                                            //
                                                                                      //
This file is part of Liberal Crime Squad.                                             //
                                                                                    //
    Liberal Crime Squad is free software; you can redistribute it and/or modify     //
    it under the terms of the GNU General Public License as published by            //
    the Free Software Foundation; either version 2 of the License, or               //
    (at your option) any later version.                                             //
                                                                                    //
    Liberal Crime Squad is distributed in the hope that it will be useful,          //
    but WITHOUT ANY WARRANTY; without even the implied warranty of                  //
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.   See the                  //
    GNU General Public License for more details.                                    //
                                                                                    //
    You should have received a copy of the GNU General Public License               //
    along with Liberal Crime Squad; if not, write to the Free Software              //
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA   02111-1307   USA     //
*/
/*
        This file was created by Chris Johnson (grundee@users.sourceforge.net)
        by copying code from game.cpp.
        To see descriptions of files and functions, see the list at
        the bottom of includes.h in the top src folder.
*/

#include <includes.h>
#include "creature/creature.h"

#include "vehicle/vehicletype.h"
#include "vehicle/vehicle.h"

#include "sitemode/stealth.h"
// for hasdisguise

//#include "common/stringconversion.h"
string attribute_enum_to_string(int attribute);

#include "common/translateid.h"
// for  int getweapontype(int )

//#include "politics/politics.h"
/* politics -- promotes the Vice President to President, and replaces VP */
void promoteVP();
        //only use here. --Schmel924

#include "combat/chaseCreature.h"
//for Vehicle* getChaseVehicle(const Creature &c);
        //hmm --Schmel924


#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <set_color_support.h>

extern Log gamelog;
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern char oldPresidentName[POLITICIAN_NAMELEN];
 vector<string> ccs_covername_shotgun;
 vector<string> ccs_covername_other;


 const string creature = "creature\\";
 vector<file_and_text_collection> creature_text_file_collection = {


	 /*creature.cpp*/
	 customText(&ccs_covername_shotgun, creature + "ccs_covername_shotgun.txt"),
	 customText(&ccs_covername_other, creature + "ccs_covername_other.txt"),
 };

extern short exec[EXECNUM];
typedef map<short, string > shortAndString;
extern long curcreatureid;
extern UniqueCreatures uniqueCreatures;
extern string commaSpace;

extern vector<ArmorType *> armortype;
extern vector<WeaponType *> weapontype;

Creature& Creature::operator=(const Creature& rhs)
{
	if (this != &rhs)
	{
		delete weapon;
		delete armor;
		delete_and_clear(clips);
		delete_and_clear(extra_throwing_weapons);
		copy(rhs);
	}
	return *this;
}

int Creature::get_disguise_difficulty() {
	return seethroughdisguise;
}
int	Creature::get_stealth_difficulty() {
	return seethroughstealth;
}

void Creature::copy(const Creature& org)
{
	for (int i = 0; i < ATTNUM; i++)
		attributes[i] = org.attributes[i];
	for (int i = 0; i < SKILLNUM; i++)
	{
		skills[i] = org.skills[i];
		skill_experience[i] = org.skill_experience[i];
	}
	for (int i = 0; i < BODYPARTNUM; i++)
		wound[i] = org.wound[i];
	for (int i = 0; i < SPECIALWOUNDNUM; i++)
		special[i] = org.special[i];
	for (int i = 0; i < LAWFLAGNUM; i++)
		crimes_suspected[i] = org.crimes_suspected[i];
	if (org.weapon) weapon = new Weapon(*org.weapon);
	else weapon = NULL;
	if (org.armor) armor = new Armor(*org.armor);
	else armor = NULL;
	for (int i = 0; i < len(org.extra_throwing_weapons); i++)
		extra_throwing_weapons.push_back(new Weapon(*org.extra_throwing_weapons[i]));
	for (int i = 0; i < len(org.clips); i++)
		clips.push_back(new Clip(*org.clips[i]));
	strcpy(name, org.name);
	strcpy(propername, org.propername);
	gender_conservative = org.gender_conservative;
	gender_liberal = org.gender_liberal;
	squadid = org.squadid;
	age = org.age;
	birthday_month = org.birthday_month;
	birthday_day = org.birthday_day;
	exists = org.exists;
	align = org.align;
	alive = org.alive;
	type = org.type;
	type_idname = org.type_idname;
	infiltration = org.infiltration;
	animalgloss = org.animalgloss;
	specialattack = org.specialattack;
	clinic = org.clinic;
	dating = org.dating;
	hiding = org.hiding;
	trainingtime = org.trainingtime;
	trainingsubject = org.trainingsubject;
	sentence = org.sentence;
	confessions = org.confessions;
	deathpenalty = org.deathpenalty;
	joindays = org.joindays;
	deathdays = org.deathdays;
	id = org.id;
	hireid = org.hireid;
	meetings = org.meetings;
	forceinc = org.forceinc;
	stunned = org.stunned;
	has_thrown_weapon = org.has_thrown_weapon;
	money = org.money;
	juice = org.juice;
	income = org.income;
	blood = org.blood;
	heat = org.heat;
	location = org.location;
	worklocation = org.worklocation;
	cantbluff = org.cantbluff;
	base = org.base;
	activity = org.activity;
	carid = org.carid;
	is_driver = org.is_driver;
	pref_carid = org.pref_carid;
	pref_is_driver = org.pref_is_driver;
	flag = org.flag;
	dontname = org.dontname;
	prisoner = NULL; //Not copying prisoner.
	seethroughdisguise = org.seethroughdisguise;
	seethroughstealth = org.seethroughstealth;
	istalkreceptive = org.istalkreceptive;
	iskidnap_resistant = org.iskidnap_resistant;
	isreports_to_police = org.isreports_to_police;
}

bool Creature::kidnap_resistant() const
{
	return iskidnap_resistant;
}
bool Creature::reports_to_police() const
{
	return isreports_to_police;
}
bool Creature::is_lcs_sleeper() const
{
	return(alive && align == ALIGN_LIBERAL && clinic == 0 &&
		dating == 0 && hiding == 0 && (flag & CREATUREFLAG_SLEEPER));
}
bool Creature::canwalk() const
{
	if (!alive) return false;
	if ((wound[BODYPART_LEG_RIGHT] & (WOUND_NASTYOFF | WOUND_CLEANOFF))
		&& (wound[BODYPART_LEG_LEFT] & (WOUND_NASTYOFF | WOUND_CLEANOFF))) return false;
	if (special[SPECIALWOUND_NECK] != 1 ||
		special[SPECIALWOUND_UPPERSPINE] != 1 ||
		special[SPECIALWOUND_LOWERSPINE] != 1) return false;
	return true;
}
void Creature::creatureinit()
{
	dontname = false;
	hireid = -1;
	worklocation = 0;
	juice = 0;
	flag = 0;
	age = 18 + LCSrandom(40);
	gender_liberal = gender_conservative = LCSrandom(2) + 1;
	birthday_month = LCSrandom(12) + 1;
	switch (birthday_month)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		birthday_day = LCSrandom(30) + 1;
		break;
	case 2:
		birthday_day = LCSrandom(28) + 1;  //TODO Allow birthday to be leap year
		break;
	default:
		birthday_day = LCSrandom(31) + 1;
		break;
	}
	carid = -1;
	is_driver = 0;
	pref_carid = -1;
	pref_is_driver = 0;
	id = curcreatureid++;
	joindays = 0;
	deathdays = 0;
	squadid = -1;
	cantbluff = 0;
	location = 0;
	base = 0;
	activity.type = ACTIVITY_NONE;
	for (int i = 0; i < LAWFLAGNUM; i++)
		crimes_suspected[i] = 0;
	heat = 0;
	confessions = 0;
	clinic = 0;
	dating = 0;
	hiding = 0;
	trainingtime = 0;
	trainingsubject = -1;
	specialattack = -1;
	animalgloss = ANIMALGLOSS_NONE;
	prisoner = NULL;
	alive = true;
	blood = 100;
	stunned = 0;
	for (int w = 0; w < BODYPARTNUM; w++)wound[w] = 0;
	weapon = NULL;
	has_thrown_weapon = false;
	armor = NULL;//new Armor(*armortype[getarmortype(tag_ARMOR_CLOTHES)]); //Causes crash for global uniqueCreature -XML
	for (int a = 0; a < ATTNUM; a++)
	{
		//attributes[a].set_type(a);
		attributes[a] = 1;
	}
	int attnum = 32;
	while (attnum > 0)
	{
		int a = LCSrandom(ATTNUM);
		if (attributes[a] < 10)
		{
			attributes[a]++;
			attnum--;
		}
	}
	for (int s = 0; s < SKILLNUM; s++)
	{
		//skills[s].set_type(s);
		skills[s] = 0;
		skill_experience[s] = 0;
	}
	special[SPECIALWOUND_TEETH] = TOOTHNUM;
	special[SPECIALWOUND_RIGHTEYE] = 1;
	special[SPECIALWOUND_LEFTEYE] = 1;
	special[SPECIALWOUND_NOSE] = 1;
	special[SPECIALWOUND_TONGUE] = 1;
	special[SPECIALWOUND_RIGHTLUNG] = 1;
	special[SPECIALWOUND_LEFTLUNG] = 1;
	special[SPECIALWOUND_HEART] = 1;
	special[SPECIALWOUND_LIVER] = 1;
	special[SPECIALWOUND_STOMACH] = 1;
	special[SPECIALWOUND_RIGHTKIDNEY] = 1;
	special[SPECIALWOUND_LEFTKIDNEY] = 1;
	special[SPECIALWOUND_SPLEEN] = 1;
	special[SPECIALWOUND_RIBS] = RIBNUM;
	special[SPECIALWOUND_NECK] = 1;
	special[SPECIALWOUND_UPPERSPINE] = 1;
	special[SPECIALWOUND_LOWERSPINE] = 1;
	seethroughstealth = 3;
	seethroughdisguise = 3;
	istalkreceptive = 0;
	iskidnap_resistant = 0;
	isreports_to_police = 0;
	forceinc = 0;
	sentence = 0;
	deathpenalty = 0;
	money = 0;
	income = 0;
	exists = true;
	vector<int> randomAlignments = { Alignment::ALIGN_CONSERVATIVE, Alignment::ALIGN_MODERATE, Alignment::ALIGN_LIBERAL };
	align = pickrandom(randomAlignments);
	infiltration = 0.0f;
	type = CREATURE_WORKER_JANITOR;
	type_idname = "CREATURE_WORKER_JANITOR";
	meetings = 0;
	strcpy(name, "Scruffy");
	strcpy(propername, "Scruffy");
}
extern string tag_type;

string tag_creature;
string tag_skill_experience;
string tag_name;
string tag_propername;
string tag_gender_conservative;
string tag_gender_liberal;
string tag_squadid;
string tag_age;
string tag_birthday_month;
string tag_birthday_day;
string tag_exists;
string tag_align;
string tag_alive;
string tag_type;
string tag_type_idname;
string tag_infiltration;
string tag_animalgloss;
string tag_specialattack;
string tag_clinic;
string tag_dating;
string tag_hiding;
string tag_trainingtime;
string tag_trainingsubject;
string tag_prisoner;
string tag_sentence;
string tag_confessions;
string tag_deathpenalty;
string tag_joindays;
string tag_deathdays;
string tag_id;
string tag_hireid;
string tag_meetings;
string tag_forceinc;
string tag_stunned;
string tag_has_thrown_weapon;
string tag_money;
string tag_juice;
string tag_income;
string tag_wound;
string tag_blood;
string tag_special;
string tag_crimes_suspected;
string tag_heat;
string tag_location;
string tag_worklocation;
string tag_cantbluff;
string tag_base;
string tag_activity;
string tag_arg;
string tag_arg2;
string tag_carid;
string tag_is_driver;
string tag_pref_carid;
string tag_pref_is_driver;
string tag_flag;
string tag_dontname;
Creature::Creature(const std::string& inputXml)
	: weapon(NULL), armor(NULL), prisoner(NULL)
{
	XML_and_Char_Pointer creature_XML_Chars = {
		XML_and_Char_Pointer::value_type(tag_gender_conservative, &gender_conservative),
		XML_and_Char_Pointer::value_type(tag_gender_liberal, &gender_liberal),
		XML_and_Char_Pointer::value_type(tag_animalgloss, &animalgloss),
		XML_and_Char_Pointer::value_type(tag_confessions, &confessions),
		XML_and_Char_Pointer::value_type(tag_deathpenalty, &deathpenalty),
		XML_and_Char_Pointer::value_type(tag_forceinc, &forceinc),
		XML_and_Char_Pointer::value_type(tag_cantbluff, &cantbluff),
		XML_and_Char_Pointer::value_type(tag_is_driver, &is_driver),
		XML_and_Char_Pointer::value_type(tag_pref_is_driver, &pref_is_driver),
	};
	XML_and_Integer_Pointer creature_XML_Integers = {

		XML_and_Integer_Pointer::value_type(tag_flag, &flag),
		XML_and_Integer_Pointer::value_type("seethroughdisguise", &seethroughdisguise),
		XML_and_Integer_Pointer::value_type("seethroughstealth", &seethroughstealth),
		XML_and_Integer_Pointer::value_type(tag_pref_carid, &pref_carid),
		XML_and_Integer_Pointer::value_type(tag_base, &base),
		XML_and_Integer_Pointer::value_type(tag_carid, &carid),
		XML_and_Integer_Pointer::value_type(tag_stunned, &stunned),
		XML_and_Integer_Pointer::value_type(tag_money, &money),
		XML_and_Integer_Pointer::value_type(tag_juice, &juice),
		XML_and_Integer_Pointer::value_type(tag_income, &income),
		XML_and_Integer_Pointer::value_type(tag_blood, &blood),
		XML_and_Integer_Pointer::value_type(tag_heat, &heat),
		XML_and_Integer_Pointer::value_type(tag_location, &location),
		XML_and_Integer_Pointer::value_type(tag_worklocation, &worklocation),
		XML_and_Integer_Pointer::value_type(tag_squadid, &squadid),
		XML_and_Integer_Pointer::value_type(tag_age, &age),
		XML_and_Integer_Pointer::value_type(tag_birthday_month, &birthday_month),
		XML_and_Integer_Pointer::value_type(tag_birthday_day, &birthday_day),
		XML_and_Integer_Pointer::value_type(tag_align, &align),
		XML_and_Integer_Pointer::value_type(tag_type, &type),
		XML_and_Integer_Pointer::value_type(tag_specialattack, &specialattack),
		XML_and_Integer_Pointer::value_type(tag_clinic, &clinic),
		XML_and_Integer_Pointer::value_type(tag_dating, &dating),
		XML_and_Integer_Pointer::value_type(tag_hiding, &hiding),
		XML_and_Integer_Pointer::value_type(tag_trainingtime, &trainingtime),
		XML_and_Integer_Pointer::value_type(tag_trainingsubject, &trainingsubject),
		XML_and_Integer_Pointer::value_type(tag_sentence, &sentence),
		XML_and_Integer_Pointer::value_type(tag_joindays, &joindays),
		XML_and_Integer_Pointer::value_type(tag_deathdays, &deathdays),
		XML_and_Integer_Pointer::value_type(tag_id, &id),
		XML_and_Integer_Pointer::value_type(tag_hireid, &hireid),
		XML_and_Integer_Pointer::value_type(tag_meetings, &meetings),
	};

	XML_and_Bool_Pointer creature_XML_Bools = {

		XML_and_Bool_Pointer::value_type(tag_alive, &alive),
		XML_and_Bool_Pointer::value_type(tag_exists, &exists),
		XML_and_Bool_Pointer::value_type(tag_has_thrown_weapon, &has_thrown_weapon),
		XML_and_Bool_Pointer::value_type(tag_dontname, &dontname),
		XML_and_Bool_Pointer::value_type("talkreceptive", &istalkreceptive),
		XML_and_Bool_Pointer::value_type("kidnap_resistant", &iskidnap_resistant),
		XML_and_Bool_Pointer::value_type("reports_to_police", &isreports_to_police),
	};
	CMarkup xml;
	xml.SetDoc(inputXml);
	xml.FindElem();
	xml.IntoElem();
	int attributesi = 0, skillsi = 0, skill_experiencei = 0, woundi = 0, speciali = 0, crimesi = 0, augi = 0;
	while (xml.FindElem())
	{
		std::string tag = xml.GetTagName();
		if (creature_XML_Integers.count(tag)) {
			*creature_XML_Integers[tag] = atoi(xml.GetData().c_str());
		}else if (creature_XML_Chars.count(tag)) {
			*creature_XML_Chars[tag] = atoi(xml.GetData().c_str());
		}else if (creature_XML_Bools.count(tag)) {
			*creature_XML_Bools[tag] = atoi(xml.GetData().c_str());
		}
		else if (tag == "attribute" && attributesi < ATTNUM)
			attributes[attributesi++] = get_XML_value(xml.GetSubDoc());
		else if (tag == "skill" && skillsi < SKILLNUM)
			skills[skillsi++] = get_XML_value(xml.GetSubDoc());
		else if (tag == tag_skill_experience && skill_experiencei < SKILLNUM)
			skill_experience[skill_experiencei++] = atoi(xml.GetData().c_str());
		else if (tag == "weapon")
		{
			Weapon w(xml.GetSubDoc());
			if (getweapontype(w.get_itemtypename()) != -1) //Check weapon is a valid type.
				give_weapon(w, NULL);
		}
		else if (tag == "armor")
		{
			armor = new Armor(xml.GetSubDoc());
			if (getarmortype(armor->get_itemtypename()) == -1) //Check armor is a valid type.
				delete_and_nullify(armor);
		}
		else if (tag == "augmentation")
			augmentations[augi++] = Augmentation(xml.GetSubDoc());
		else if (tag == tag_name)
			strcpy(name, xml.GetData().c_str());
		else if (tag == tag_propername)
			strcpy(propername, xml.GetData().c_str());
		else if (tag == tag_type_idname)
			type_idname = xml.GetData();
		else if (tag == tag_infiltration)
			infiltration = atof(xml.GetData().c_str());
		else if (tag == tag_prisoner)
		{
			xml.IntoElem();
			prisoner = new Creature(xml.GetSubDoc());
			xml.OutOfElem();
		}
		else if (tag == "clip")
		{
			Clip* c = new Clip(xml.GetSubDoc());
			if (getcliptype(c->get_itemtypename()) != -1)
				clips.push_back(c);
			else
				delete c;
		}
		else if (tag == tag_activity)
		{
			xml.IntoElem();
			while (xml.FindElem())
			{
				tag = xml.GetTagName();
				if (tag == tag_type)
					activity.type = atoi(xml.GetData().c_str());
				else if (tag == tag_arg)
					activity.arg = atoi(xml.GetData().c_str());
				else if (tag == tag_arg2)
					activity.arg2 = atoi(xml.GetData().c_str());
			}
			xml.OutOfElem();
		}
		else if (tag == tag_wound && woundi < BODYPARTNUM)
			wound[woundi++] = atoi(xml.GetData().c_str());
		else if (tag == tag_special && speciali < SPECIALWOUNDNUM)
			special[speciali++] = atoi(xml.GetData().c_str());
		else if (tag == tag_crimes_suspected && crimesi < LAWFLAGNUM)
			crimes_suspected[crimesi++] = atoi(xml.GetData().c_str());

	}
}
extern string closeParenthesis;
string Creature::showXml() const
{
	CMarkup xml;
	xml.AddElem(tag_creature);
	xml.IntoElem();
	for (int i = 0; i < ATTNUM; i++)
		xml.AddSubDoc(showXmlAttribute(i, attributes[i]));
	for (int i = 0; i < SKILLNUM; i++)
		xml.AddSubDoc(showXmlSkill(i, skills[i]));
	for (int i = 0; i < SKILLNUM; i++)
		xml.AddElem(tag_skill_experience, skill_experience[i]); //Bad, relies on their order in the xml file. -XML 
	if (weapon) xml.AddSubDoc(weapon->showXml());
	if (armor) xml.AddSubDoc(armor->showXml());
	for (const auto &aug : augmentations)
		xml.AddSubDoc(aug.showXml());
	xml.AddElem(tag_name, name);
	xml.AddElem(tag_propername, propername);
	xml.AddElem(tag_gender_conservative, gender_conservative);
	xml.AddElem(tag_gender_liberal, gender_liberal);
	xml.AddElem(tag_squadid, squadid);
	xml.AddElem(tag_age, age);
	xml.AddElem(tag_birthday_month, birthday_month);
	xml.AddElem(tag_birthday_day, birthday_day);
	xml.AddElem(tag_exists, exists);
	xml.AddElem(tag_align, align);
	xml.AddElem(tag_alive, alive);
	xml.AddElem(tag_type, type);
	xml.AddElem(tag_type_idname, type_idname);
	char buf[256];
	snprintf(buf, 255, "%f", infiltration);
	xml.AddElem(tag_infiltration, buf);
	xml.AddElem(tag_animalgloss, animalgloss);
	xml.AddElem(tag_specialattack, specialattack);
	xml.AddElem(tag_clinic, clinic);
	xml.AddElem(tag_dating, dating);
	xml.AddElem(tag_hiding, hiding);
	xml.AddElem(tag_trainingtime, trainingtime);
	xml.AddElem(tag_trainingsubject, trainingsubject);
	if (prisoner) //Should never be true when saving.
	{
		xml.AddElem(tag_prisoner);
		xml.IntoElem();
		xml.AddSubDoc(prisoner->showXml());
		xml.OutOfElem();
	}
	xml.AddElem(tag_sentence, sentence);
	xml.AddElem(tag_confessions, confessions);
	xml.AddElem(tag_deathpenalty, deathpenalty);
	xml.AddElem(tag_joindays, joindays);
	xml.AddElem(tag_deathdays, deathdays);
	xml.AddElem(tag_id, id);
	xml.AddElem(tag_hireid, hireid);
	xml.AddElem(tag_meetings, meetings);
	xml.AddElem(tag_forceinc, forceinc);
	xml.AddElem(tag_stunned, stunned);
	for (int i = 0; i < len(extra_throwing_weapons); i++)
		xml.AddSubDoc(extra_throwing_weapons[i]->showXml());
	for (int i = 0; i < len(clips); i++)
		xml.AddSubDoc(clips[i]->showXml());
	xml.AddElem(tag_has_thrown_weapon, has_thrown_weapon);
	xml.AddElem(tag_money, money);
	xml.AddElem(tag_juice, juice);
	xml.AddElem(tag_income, income);
	for (int i = 0; i < BODYPARTNUM; i++) //Bad, relies on their order in the xml file. -XML
		xml.AddElem(tag_wound, wound[i]);
	xml.AddElem(tag_blood, blood);
	for (int i = 0; i < SPECIALWOUNDNUM; i++) //Bad, relies on their order in the xml file. -XML
		xml.AddElem(tag_special, special[i]);
	for (int i = 0; i < LAWFLAGNUM; i++) //Bad, relies on their order in the xml file. -XML
		xml.AddElem(tag_crimes_suspected, crimes_suspected[i]);
	xml.AddElem(tag_heat, heat);
	xml.AddElem(tag_location, location);
	xml.AddElem(tag_worklocation, worklocation);
	xml.AddElem(tag_cantbluff, cantbluff);
	xml.AddElem(tag_base, base);
	xml.AddElem(tag_activity);
	xml.IntoElem();
	xml.AddElem(tag_type, activity.type);
	xml.AddElem(tag_arg, activity.arg);
	xml.AddElem(tag_arg2, activity.arg2);
	xml.OutOfElem();
	xml.AddElem(tag_carid, carid);
	xml.AddElem(tag_is_driver, is_driver);
	xml.AddElem(tag_pref_carid, pref_carid);
	xml.AddElem(tag_pref_is_driver, pref_is_driver);
	xml.AddElem(tag_flag, flag);
	xml.AddElem(tag_dontname, dontname);
	xml.AddElem("seethroughdisguise", seethroughdisguise);
	xml.AddElem("seethroughstealth", seethroughdisguise);
	xml.AddElem( "talkreceptive",		istalkreceptive);
	xml.AddElem( "kidnap_resistant",		iskidnap_resistant );
	xml.AddElem("reports_to_police", isreports_to_police);
	return xml.GetDoc();
}
int Creature::get_attribute(int attribute, bool usejuice) const
{
	int ret = attributes[attribute];
	// Special modifications to attributes based on age
	switch (attribute)
	{
	case ATTRIBUTE_STRENGTH:
		if (age < 11)ret >>= 1;     // Strength is lowest at the beginning and end of life
		else if (age < 16)ret -= 1;
		else if (age > 70)ret -= 6;
		else if (age>52)ret -= 3;
		else if (age > 35)ret -= 1;
		break;
	case ATTRIBUTE_AGILITY:
		if (age > 70)ret -= 6;      // Agility is weakened with age
		else if (age > 52)ret -= 3;
		else if (age > 35)ret -= 1;
		break;
	case ATTRIBUTE_HEALTH:
		if (age < 11)ret -= 2;
		else if (age < 16)ret -= 1; // Physical immaturity weakens health
									// Aging actually damages base health and eventually kills, so no aging effects here
		break;
	case ATTRIBUTE_CHARISMA:
		if (age < 11)ret += 2;      // Lots of folks like kids
		else if (age < 16)ret -= 1; // Teenagers have communication difficulties and image issues
		else if (age > 70)ret += 3; // Authority and experience in life then enhance Charisma with age
		else if (age>52)ret += 2;
		else if (age > 35)ret += 1;
		break;
	case ATTRIBUTE_INTELLIGENCE:
		if (age < 11)ret -= 3;      // Experience enhances Intelligence with age
		else if (age < 16)ret -= 1;
		else if (age > 70)ret += 3;
		else if (age>52)ret += 2;
		else if (age>35)ret += 1;
		break;
	case ATTRIBUTE_WISDOM:
		if (age < 11)ret -= 2;      // Experience grants Wisdom with age
		else if (age < 16)ret -= 1;
		else if (age > 70)ret += 2;
		else if (age>52)ret += 1;
		break;
	case ATTRIBUTE_HEART:
		if (age < 11)ret += 2;      // Experience saps Heart with age due to cynicism
		else if (age < 16)ret += 1; // No wonder it's typically the young who are most Liberal...
		else if (age > 70)ret -= 2;
		else if (age>52)ret -= 1;
		break;
	}
	// Physical stats want to know: Are you paralyzed?
	if (attribute == ATTRIBUTE_STRENGTH ||
		attribute == ATTRIBUTE_AGILITY ||
		attribute == ATTRIBUTE_HEALTH)
	{
		if (special[SPECIALWOUND_NECK] != 1 ||
			special[SPECIALWOUND_UPPERSPINE] != 1)
			ret = 1;
		else if (special[SPECIALWOUND_LOWERSPINE] != 1)ret >>= 2;
	}
	// Agility wants to know: Do you have legs?
	if (attribute == ATTRIBUTE_AGILITY)
	{
		int legok = 2;
		if ((wound[BODYPART_LEG_RIGHT] & WOUND_NASTYOFF) ||
			(wound[BODYPART_LEG_RIGHT] & WOUND_CLEANOFF))legok--;
		if ((wound[BODYPART_LEG_LEFT] & WOUND_NASTYOFF) ||
			(wound[BODYPART_LEG_LEFT] & WOUND_CLEANOFF))legok--;
		if (legok == 0)ret >>= 2;
		else if (legok == 1)ret >>= 1;
	}
	// Charisma wants to know: How fucked up does your face look?
	if (attribute == ATTRIBUTE_CHARISMA)
	{
		long disfigs = 0;
		if (special[SPECIALWOUND_TEETH] < TOOTHNUM)disfigs++;
		if (special[SPECIALWOUND_TEETH] < TOOTHNUM / 2)disfigs++;
		if (special[SPECIALWOUND_TEETH] == 0)disfigs++;
		if (special[SPECIALWOUND_RIGHTEYE] == 0)disfigs += 2;
		if (special[SPECIALWOUND_LEFTEYE] == 0)disfigs += 2;
		if (special[SPECIALWOUND_TONGUE] == 0)disfigs += 3;
		if (special[SPECIALWOUND_NOSE] == 0)disfigs += 3;
		ret -= disfigs;
	}
	// Finish now if not using juice to avoid bounds check.
	if (!usejuice)return ret;
	// Never use juice to increase stats for the opposite ideology!
	if (attribute == ATTRIBUTE_WISDOM && align != ALIGN_CONSERVATIVE)usejuice = false;
	if (attribute == ATTRIBUTE_HEART  && align != ALIGN_LIBERAL)usejuice = false;
	// Effects of juice on the character's attributes
	if (usejuice)
	{
		if (juice <= -50)ret = 1; // Damn worthless
		else if (juice <= -10)ret = static_cast<int>(ret*0.6); // Society's dregs
		else if (juice < 0)ret = static_cast<int>(ret*0.8);    // Punk
		else if (juice >= 10)
		{
			if (juice < 50)ret += 1; // Activist
			else if (juice < 100)ret = static_cast<int>(ret*1.1 + 2); // Socialist Threat
			else if (juice < 200)ret = static_cast<int>(ret*1.2 + 3); // Revolutionary
			else if (juice < 500)ret = static_cast<int>(ret*1.3 + 4); // Urban Guerrilla
			else if (juice < 1000)ret = static_cast<int>(ret*1.4 + 5); // Liberal Guardian
			else ret = static_cast<int>(ret*1.5 + 6); // Elite Liberal
		}
		// Debilitations for temporary injuries in attributes based
		// on physical appearance or performance, because people who
		// are bleeding all over are less strong, agile, and charismatic
		// it is also hard to think when you are in severe pain
		if (attribute == ATTRIBUTE_STRENGTH ||
			attribute == ATTRIBUTE_AGILITY ||
			attribute == ATTRIBUTE_CHARISMA ||
			attribute == ATTRIBUTE_INTELLIGENCE)
		{
			//         if(blood<=20)ret>>=2;
			//         else if(blood<=50){ret>>=1;}
			//         else if(blood<=75){ret*=3;ret>>=2;}
			ret = (int)((0.5 + (float)ret)*(float)blood / 100.0);
		}
	}
	// Bounds check attributes
	if (ret < 1) ret = 1;
	if (ret > MAXATTRIBUTE) ret = MAXATTRIBUTE;
	return ret;
}
int Creature::roll_check(int skill)
{
	// This die rolling system (and the associated difficulty
	// ratings) is adapted from EABA, which uses a system of
	// rolling a number of six-sided dice equal to the ability
	// score divided by three. The top three dice are used,
	// the rest discarded. Finally, any additional points that
	// didn't divide evenly into creating a die contribute to
	// odd-shaped dice that don't exist in the real world. This
	// system gives diminishing returns for high skill levels.
	// EABA actually just adds the remainder to the die total,
	// but there are some statistical problems with that system.
	// It is not possible to roll above an 18 using this system.
	// It is possible to roll below a 3, if you don't have at
	// least 9 skill.
	int dice = skill / 3;
	int total = 0;
	int roll[3] = { 0,0,0 };
	for (int i = 0; i < dice + 1; i++)
	{
		int newroll = 0;
		// Roll d6 for every three skill
		if (i < dice)
			newroll = LCSrandom(6) + 1;
		// Partial dice for the remainder -- d3 for +1, d5 for +2
		else if (skill % 3)
			newroll = LCSrandom((skill % 3) * 2 + 1) + 1;
		// Keep the top three dice
		if (i < 3)
			roll[i] = newroll;
		else
			for (int j = 0; j<3; j++)
				if (newroll>roll[j])
				{
					int temp = roll[j];
					roll[j] = newroll;
					newroll = temp;
				}
	}
	for (int i = 0; i < 3; i++)
		total += roll[i];
	return total;
}
int Creature::attribute_roll(int attribute) const
{
	int return_value = roll_check(get_attribute(attribute, true));
	if (SHOWMECHANICS) {
		mvaddstrAlt(8, 1, " AttributeRoll(");
		addstrAlt(attribute_enum_to_string(attribute));
		addstrAlt(", Attribute Level ");
		addstrAlt(get_attribute(attribute, true));
		addstrAlt(", Outcome of ");
		addstrAlt(return_value);
		addstrAlt(closeParenthesis);
		getkeyAlt();
	}
	// Roll on the attribute value
	return return_value;
}
bool Creature::attribute_check(int attribute, int difficulty) const
{
	if (SHOWMECHANICS) {
		mvaddstrAlt(8, 1, " AttributeCheck(");
		addstrAlt(attribute_enum_to_string(attribute));
		if (difficulty < 21)
		{
			addstrAlt(", Difficulty ");
			addstrAlt(difficulty);
		}
		else addstrAlt(", IMPOSSIBLE");
		addstrAlt(closeParenthesis);
		getkeyAlt();
	}
	return(attribute_roll(attribute) >= difficulty);
}
int Creature::skill_roll(int skill) const
{
	int pseudoskill = 0;
	// Handle Pseudoskills
	if (skill < 0)
	{
		switch (skill)
		{
		default:
			set_color_easy(YELLOW_ON_RED_BRIGHT);
			addstrAlt("-=ILLEGAL SKILL ROLL=-", gamelog);
			getkeyAlt();
			break;
		case PSEUDOSKILL_ESCAPEDRIVE:
		case PSEUDOSKILL_DODGEDRIVE:
			pseudoskill = skill;   // Remember the details.
			skill = SKILL_DRIVING; // Base skill is driving.
			break;
		}
	}
	// Take skill strength
	int skill_value = skills[skill];
	// plus the skill's associate attribute
	int attribute_value = get_attribute(get_associated_attribute(skill), true);
	int adjusted_attribute_value;
	switch (skill)
	{
		// most attributes get halved when applied to skills, capped by relative skill level...
	default:
		adjusted_attribute_value = min(attribute_value / 2, skill_value + 3);
		break;
		// ...and some may be so specialized that they ignore attributes, instead counting skill double
	case SKILL_SECURITY:
		adjusted_attribute_value = skill_value;
		break;
	}
	Vehicle* v = getChaseVehicle(*this);
	switch (pseudoskill)
	{
	case PSEUDOSKILL_ESCAPEDRIVE:
		if (v != NULL)
		{
			skill_value = v->modifieddriveskill(skill_value + adjusted_attribute_value); // combine values and modify by vehicle stats
			adjusted_attribute_value = 0;
		}
		else
		{
			skill_value = adjusted_attribute_value = 0; // Can't drive without a car
		}
		break;
	case PSEUDOSKILL_DODGEDRIVE:
		if (v != NULL)
		{
			skill_value = v->modifieddodgeskill(skill_value + adjusted_attribute_value); // combine values and modify by vehicle stats
			adjusted_attribute_value = 0;
		}
		else
		{
			skill_value = adjusted_attribute_value = 0; // Can't drive without a car
		}
		break;
	}
	// add the adjusted attribute and skill to get the adjusted skill total
	// that will be rolled on
	int return_value = roll_check(skill_value + adjusted_attribute_value);
	// Special skill handling
	switch (skill)
	{
		// Skills that cannot be used if zero skill:
	case SKILL_PSYCHOLOGY:
	case SKILL_LAW:
	case SKILL_SECURITY:
	case SKILL_COMPUTERS:
	case SKILL_MUSIC:
	case SKILL_ART:
	case SKILL_RELIGION:
	case SKILL_SCIENCE:
	case SKILL_BUSINESS:
	case SKILL_TEACHING:
	case SKILL_FIRSTAID:
		if (skills[skill] == 0)
		{
			return_value = 0; // Automatic failure
			break;
		}
		break;
		// Skills that should depend on clothing:
	case SKILL_STEALTH:
	{
		double stealth = (double)get_armor().get_stealth_value();
		for (int i = 1; i < get_armor().get_quality(); i++) stealth *= 0.8;
		if (get_armor().is_damaged()) stealth *= 0.5;
		return_value *= static_cast<int>(stealth);
		return_value /= 2;
		// Shredded clothes get you no stealth.
		if (get_armor().get_quality() > get_armor().get_quality_levels())
			return_value = 0;
	}
	break;
	case SKILL_SEDUCTION:
	case SKILL_PERSUASION:
		break;
		// Unique disguise handling
	case SKILL_DISGUISE:
	{
		// Check for appropriate uniform
		char uniformed = hasdisguise(*this);
		// Ununiformed disguise checks automatically fail
		if (!uniformed) { return_value = 0; break; }
		// reduce effectiveness for 'partial' uniforms (police uniforms when trespassing)
		else { if (uniformed == 2) return_value >>= 1; }
		// Bloody, damaged clothing hurts disguise check
		if (get_armor().is_bloody()) { return_value >>= 1; }
		if (get_armor().is_damaged()) { return_value >>= 1; }
		// Carrying corpses or having hostages is very bad for disguise
		if (prisoner != NULL) { return_value >>= 2; break; }
	}
	}
	if (SHOWMECHANICS) {
		mvaddstrAlt(8, 1, " SkillRoll(");
		addstrAlt(skill_enum_to_string(skill));
		addstrAlt(", Skill Value ");
		addstrAlt(skills[skill]);
		addstrAlt(commaSpace);
		if (return_value == 0)
			addstrAlt("automatic failure");
		else
		{
			addstrAlt("Adjusted Attribute Value ");
			addstrAlt(adjusted_attribute_value);
			addstrAlt(", Outcome of ");
			addstrAlt(return_value);
		}
		addstrAlt(closeParenthesis);
		getkeyAlt();
	}
	return return_value;
}
bool Creature::skill_check(int skill, int difficulty) const
{
	if (SHOWMECHANICS) {
		mvaddstrAlt(8, 1, " SkillCheck(");
		addstrAlt(skill_enum_to_string(skill));
		if (difficulty < 21)
		{
			addstrAlt(", Difficulty ");
			addstrAlt(difficulty);
		}
		else addstrAlt(", IMPOSSIBLE");
		addstrAlt(closeParenthesis);
		getkeyAlt();
	}
	return(skill_roll(skill) >= difficulty);
}

void Creature::train(int trainedskill, int experience, int upto)
{
	// Do we allow animals to gain skills? Right now, yes
	//if(animalgloss==ANIMALGLOSS_ANIMAL)return;
	// Don't give experience if already maxed out or requested to give none
	if (skill_cap(trainedskill, true) <= skills[trainedskill] || upto <= skills[trainedskill] || experience == 0) { return; }
	else {
		// Skill gain scaled by ability in the area
		skill_experience[trainedskill] += max(1, static_cast<int>(experience * skill_cap(trainedskill, false) / 6.0));
		int abovenextlevel;
		// only allow gaining experience on the new level if it doesn't put us over a level limit
		if (skills[trainedskill] >= (upto - 1) ||
			skills[trainedskill] >= (skill_cap(trainedskill, true) - 1))
		{
			abovenextlevel = 0;
		}
		else
		{
			abovenextlevel = 50 + 5 * (1 + skills[trainedskill]);
		} // enough skill points to get halfway through the next skill level
		skill_experience[trainedskill] = min(skill_experience[trainedskill], 100 + 10 * skills[trainedskill] + abovenextlevel);
	}
}
void Creature::skill_up()
{
	for (int s = 0; s < SKILLNUM; s++)
	{
		while (skill_experience[s] >= 100 + 10 * skills[s]&&
			skills[s] < skill_cap(s, true))
		{
			skill_experience[s] -= 100 + 10 * skills[s];
			skills[s]++;
		}
		if (skills[s] == skill_cap(s, true))
			skill_experience[s] = 0;
	}
}

/* turns a creature into a conservative */
void conservatise(Creature &cr)
{
	if (cr.align == ALIGN_LIBERAL && cr.juice>0)cr.juice = 0;
	cr.align = ALIGN_CONSERVATIVE;
	switch (cr.type)
	{
	case CREATURE_WORKER_FACTORY_UNION:
		strcpy(cr.name, "Ex-Union Worker");
		break;
	case CREATURE_JUDGE_LIBERAL:
		strcpy(cr.name, "Jaded Liberal Judge");
		break;
	}
}
/* turns a creature into a liberal */
void liberalize(Creature &cr, bool rename)
{
	if (cr.align == ALIGN_CONSERVATIVE && cr.juice > 0)cr.juice = 0;
	cr.align = ALIGN_LIBERAL;
	if (cr.id == uniqueCreatures.CEO().id)
		uniqueCreatures.newCEO();
	if (rename)
		switch (cr.type)
		{
		case CREATURE_WORKER_FACTORY_NONUNION:
			strcpy(cr.name, "New Union Worker");
			break;
			//    case CREATURE_JUDGE_CONSERVATIVE:
			//       strcpy(cr.name,"Enlightened Judge");
			//       break;
		}
}
/* gives a CCS member a cover name */
void nameCCSMember(Creature &cr)
{
	if (cr.get_armor().get_itemtypename() == tag_ARMOR_CIVILLIANARMOR)
		strcpy(cr.name, "Elite Security");
	else if (cr.get_armor().get_itemtypename() == tag_ARMOR_ARMYARMOR)
		strcpy(cr.name, "Soldier");
	else if (cr.get_armor().get_itemtypename() == tag_ARMOR_HEAVYARMOR)
		strcpy(cr.name, "CCS Heavy");
	else if (cr.get_weapon().get_itemtypename() == tag_WEAPON_SHOTGUN_PUMP || LCSrandom(2))
		strcpy(cr.name, pickrandom(ccs_covername_shotgun).data());
	else
		strcpy(cr.name, pickrandom(ccs_covername_other).data());
}
/* are they interested in talking about the issues? */
bool Creature::talkreceptive() const
{
	return !enemy() && istalkreceptive;
}
/* are the characters close enough in age to date? */
bool Creature::can_date(const Creature &a) const
{
	if (!ZEROMORAL) {
		// Assume age appropriate for animals, tanks, etc.
		// (use other restrictions for these, like humorous rejections)
		if (animalgloss || a.animalgloss) return true;
		// Prohibit anyone 10 or younger
		if (age < 11 || a.age < 11) return false;
		// Allow 11-15 year olds only if the other partner is
		// within 4 years age difference
		if (age < 16 || a.age < 16) return abs(age - a.age) < 5;
	}
	// Allow anyone 16 or older
	return true;
}
void Creature::die()
{
	alive = 0, blood = 0;
	if (id == uniqueCreatures.CEO().id)
		uniqueCreatures.newCEO();
	if (id == uniqueCreatures.President().id)
	{
		strcpy(oldPresidentName, execname[EXEC_PRESIDENT]);
		promoteVP();
		uniqueCreatures.newPresident();
	}
}
void UniqueCreatures::newCEO()
{
	makecreature(CEO_, CREATURE_CORPORATE_CEO);
	CEO_ID = CEO_.id, CEO_state = UNIQUECREATURE_ALIVE;
}
void UniqueCreatures::newPresident()
{
	makecreature(Pres_, CREATURE_POLITICIAN);
	Pres_ID = Pres_.id, Pres_state = UNIQUECREATURE_ALIVE, Pres_.dontname = true;
	//Turn into President (not just random pol)
	std::string pres_name = execname[EXEC_PRESIDENT];
	strcpy(Pres_.name, (((string) "President ") + pres_name.substr(pres_name.find(' ') + 1)).c_str());
	strcpy(Pres_.propername, execname[EXEC_PRESIDENT]);
	switch (exec[EXEC_PRESIDENT])
	{ // we don't do anything for ALIGN_ARCHCONSERVATIVE or ALIGN_CONSERVATIVE so having them here is unnecessary
	case ALIGN_MODERATE:
		Pres_.align = ALIGN_MODERATE;
		Pres_.set_attribute(ATTRIBUTE_WISDOM, Pres_.get_attribute(ATTRIBUTE_WISDOM, false) / 2);
		Pres_.set_attribute(ATTRIBUTE_HEART, Pres_.get_attribute(ATTRIBUTE_WISDOM, false));
		break;
	case ALIGN_LIBERAL:
	case ALIGN_ELITELIBERAL:
		Pres_.align = ALIGN_LIBERAL;
		Pres_.set_attribute(ATTRIBUTE_HEART, Pres_.get_attribute(ATTRIBUTE_WISDOM, false));
		Pres_.set_attribute(ATTRIBUTE_WISDOM, 1);
		break;
	}
}
UniqueCreatures::UniqueCreatures(const std::string& inputXml)
{
	CMarkup xml;
	xml.SetDoc(inputXml);
	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem())
	{
		std::string tag = xml.GetTagName();
		if (tag == "CEO" || tag == "Pres")
		{
			xml.IntoElem();
			xml.FindElem();
			if (tag == "CEO")
				CEO_ = Creature(xml.GetSubDoc());
			else
				Pres_ = Creature(xml.GetSubDoc());
			xml.OutOfElem();
		}
		else if (tag == "CEO_ID")
			CEO_ID = atoi(xml.GetData().c_str());
		else if (tag == "CEO_state")
			CEO_state = atoi(xml.GetData().c_str());
		else if (tag == "Pres_ID")
			Pres_ID = atoi(xml.GetData().c_str());
		else if (tag == "Pres_state")
			Pres_state = atoi(xml.GetData().c_str());
	}
}
string UniqueCreatures::showXml() const
{
	CMarkup xml;
	xml.AddElem("uniquecreatures");
	xml.IntoElem();
	xml.AddElem("CEO_ID", CEO_ID);
	xml.AddElem("CEO_state", CEO_state);
	xml.AddElem("CEO");
	xml.AddChildSubDoc(CEO_.showXml());
	xml.AddElem("Pres_ID", CEO_ID);
	xml.AddElem("Pres_state", CEO_state);
	xml.AddElem("Pres");
	xml.AddChildSubDoc(Pres_.showXml());
	return xml.GetDoc();
}
const char* Creature::heshe(bool capitalize) const
{  // subject pronoun (nominative case)
	switch (gender_liberal)
	{
	case GENDER_MALE: return capitalize ? "He" : "he";
	case GENDER_FEMALE: return capitalize ? "She" : "she";
	default: return capitalize ? "Xe" : "xe"; // Elite Liberal gender-neutral pronoun... it is pronounced "zee" rhyming with "heANDshe"
											  // see http://homepage.ntlworld.com/jonathan.deboynepollard/FGA/sex-neutral-pronouns.html (great reference on this)
											  // or http://en.wiktionary.org/wiki/xe or http://en.wikipedia.org/wiki/Gender-specific_and_gender-neutral_pronouns#Summary (wiki references)
											  // or http://genderneutralpronoun.wordpress.com/about/alice/xe/ (examples of it being used in text)
											  // full conjugation of "xe"/"xyr"/"xem" (the "x"es are pronounced like "z"s):
											  // subject prononoun (nominative case):          xe      (pronounced "zee" rhyming with "heANDshe")
											  // pronominal adjective (possessive determiner): xyr     (pronounced "zur" rhyming with "her")
											  // object pronoun (oblique case);                xem     (pronounced "zem" rhyming with "them")
											  // possessive pronoun:                           xyrs    (pronounced "zurz" rhyming with "hers")
											  // reflexive pronoun:                            xemself (pronounced "zemself" rhyming with "themself")
											  // public schools in Vancouver, British Columbia in Canada officially use these pronouns:
											  // http://news.nationalpost.com/2014/06/17/vancouver-school-boards-genderless-pronouns-not-likely-to-stick-if-history-is-any-indication/
	}
}
const char* Creature::hisher(bool capitalize) const
{  // pronominal adjective (possessive determiner)
	switch (gender_liberal)
	{
	case GENDER_MALE: return capitalize ? "His" : "his";
	case GENDER_FEMALE: return capitalize ? "Her" : "her";
	default: return capitalize ? "Xyr" : "xyr"; // Elite Liberal gender-neutral pronoun... it is pronounced "zur" rhyming with "her"
												// see http://homepage.ntlworld.com/jonathan.deboynepollard/FGA/sex-neutral-pronouns.html (great reference on this)
												// or http://en.wiktionary.org/wiki/xyr or http://en.wikipedia.org/wiki/Gender-specific_and_gender-neutral_pronouns#Summary (wiki references)
												// or http://genderneutralpronoun.wordpress.com/about/alice/xe/ (examples of it being used in text)
												// the possessive pronoun is based on this pronominal adjective in all standard third-person pronouns (so "xyrs" is correct):
												// his -> his, her -> hers, their -> theirs, and likewise xyr -> xyrs... just add "s" at the end if it doesn't already have an "s" at the end
	}
}
const char* Creature::himher(bool capitalize) const
{  // object pronoun (oblique case)
	switch (gender_liberal)
	{
	case GENDER_MALE: return capitalize ? "Him" : "him";
	case GENDER_FEMALE: return capitalize ? "Her" : "her";
	default: return capitalize ? "Xem" : "xem"; // Elite Liberal gender-neutral pronoun... it is pronounced "zem" rhyming with "them"
												// see http://homepage.ntlworld.com/jonathan.deboynepollard/FGA/sex-neutral-pronouns.html (great reference on this)
												// or http://en.wiktionary.org/wiki/xem or http://en.wikipedia.org/wiki/Gender-specific_and_gender-neutral_pronouns#Summary (wiki references)
												// or http://genderneutralpronoun.wordpress.com/about/alice/xe/ (examples of it being used in text)
												// the reflexive pronoun is based on this object pronoun in all standard third-person pronouns (so "xemself" is correct):
												// him -> himself, her -> herself, them -> themselves, it -> itself, one -> oneself, and likewise xem -> xemself... just add "self" unless plural in which case add "selves"
												// some people mistakenly use xyrself instead of xemself but this is wrong as it doesn't follow the pattern used by ALL standard third-person pronouns,
												// instead following the first-and-second-person pronoun pattern (my -> myself, your -> yourself/yourselves, our -> ourselves, thy -> thyself, and likewise xyr -> xyrself)
	}
}
Weapon& Creature::weapon_none()
{
	static Weapon unarmed(*weapontype[getweapontype(tag_WEAPON_NONE)]);
	return unarmed;
}
Armor& Creature::armor_none()
{
	static Armor naked(*armortype[getarmortype(tag_ARMOR_NONE)]);
	return naked;
}
bool Creature::will_do_ranged_attack(bool force_ranged, bool force_melee) const
{
	if (weapon) //Is the creature armed?
	{
		bool reload_allowed = can_reload();
		return weapon->get_attack(force_ranged, force_melee, reload_allowed) //Any attacks possible under circumstances?
			&& weapon->get_attack(force_ranged, force_melee, reload_allowed)->ranged //Is the attacked ranged?
			&& (!weapon->get_attack(force_ranged, force_melee, reload_allowed)->uses_ammo //Does it not use ammo
				|| weapon->get_ammoamount() != 0);                                      //or does it have ammo?
	}
	else return false;
}
bool Creature::can_reload() const
{
	//return len(clips); //Can not be sure creature only has appropriate clips.
	for (int i = 0; i < len(clips); i++)
		if (get_weapon().acceptable_ammo(*clips[i])) return true;
	return false;
}
bool Creature::will_reload(bool force_ranged, bool force_melee) const
{
	return get_weapon().uses_ammo()      //Does it use ammo?
		&& !get_weapon().get_ammoamount() //Is it out of ammo?
		&& can_reload()                  //Is reloading possible?
		&& get_weapon().get_attack(force_ranged, force_melee, false) //Is there an appropriate attack for the situation?
		&& get_weapon().get_attack(force_ranged, force_melee, false)->uses_ammo; //Does the attack need ammo?
}
bool Creature::reload(bool wasteful)
{
	if (get_weapon().uses_ammo() && len(clips)
		&& (wasteful || get_weapon().get_ammoamount() == 0))
	{
		bool r = weapon->reload(*clips.front());
		if (clips.front()->empty())
			delete_and_remove(clips, 0);
		return r;
	}
	else return false;
}
bool Creature::ready_another_throwing_weapon()
{
	bool r = false;
	if (len(extra_throwing_weapons))
	{
		weapon = extra_throwing_weapons.front()->split(1);
		if (extra_throwing_weapons.front()->empty())
			delete_and_remove(extra_throwing_weapons, 0);
		r = true;
	}
	has_thrown_weapon = false;
	return r;
}
int Creature::count_clips() const
{
	int sum = 0;
	for (int i = 0; i < len(clips); i++)
		sum += clips[i]->get_number();
	return sum;
}
bool Creature::take_clips(Item& clip, int number)
{
	if (clip.is_clip())
		return take_clips(static_cast<Clip&>(clip), number); //cast -XML
	else return false;
}
bool Creature::take_clips(Clip& clip, int number)
{
	if (number + count_clips() >= 9) number = 9 - count_clips();
	if (number > clip.get_number()) number = clip.get_number();
	if (number > 0 && get_weapon().acceptable_ammo(clip))
	{
		Clip* c = clip.split(number);
		clips.push_back(c);
		return true;
	}
	else return false;
}
bool Creature::take_clips(const ClipType& ct, int number)
{
	Clip c(ct, number);
	return take_clips(c, number);
}
void Creature::give_weapon(Weapon& w, vector<Item*>* lootpile)
{
	if (weapon&&!w.empty())
	{
		if (weapon->is_throwable() && weapon->is_same_type(w))
		{
			int take_number = 10 - count_weapons();
			if (take_number > 0)
				extra_throwing_weapons.push_back(w.split(1));
		}
		else
		{
			if (!lootpile)
			{
				delete weapon;
				delete_and_clear(extra_throwing_weapons);
			}
			else
			{
				lootpile->push_back(weapon);
				while (len(extra_throwing_weapons))
				{
					lootpile->push_back(extra_throwing_weapons.back());
					extra_throwing_weapons.pop_back();
				}
			}
			weapon = w.split(1);
			if (!lootpile)
			{
				for (int i = len(clips) - 1; i >= 0; i--)
				{
					if (!weapon->acceptable_ammo(*clips[i]))
						delete_and_remove(clips, i);
				}
			}
			else
			{
				for (int i = len(clips) - 1; i >= 0; i--)
				{
					if (!weapon->acceptable_ammo(*clips[i]))
					{
						lootpile->push_back(clips[i]);
						clips.erase(clips.begin() + i);
					}
				}
			}
		}
	}
	else if (!w.empty())
	{
		drop_weapons_and_clips(lootpile);
		weapon = w.split(1);
	}
}
void Creature::give_weapon(const WeaponType& wt, vector<Item*>* lootpile)
{
	Weapon w(wt);
	give_weapon(w, lootpile);
}
void Creature::drop_weapons_and_clips(vector<Item*>* lootpile)
{
	has_thrown_weapon = false;
	if (weapon)
	{
		if (lootpile) lootpile->push_back(weapon);
		else delete weapon;
		weapon = NULL;
	}
	while (len(extra_throwing_weapons))
	{
		if (lootpile) lootpile->push_back(extra_throwing_weapons.back());
		else delete extra_throwing_weapons.back();
		extra_throwing_weapons.pop_back();
	}
	while (len(clips))
	{
		if (lootpile) lootpile->push_back(clips.back());
		else delete clips.back();
		clips.pop_back();
	}
}
void Creature::drop_weapon(vector<Item*>* lootpile)
{
	if (len(extra_throwing_weapons))
		has_thrown_weapon = true;
	if (weapon)
	{
		if (lootpile) lootpile->push_back(weapon);
		else delete weapon;
		weapon = NULL;
	}
}
int Creature::count_weapons() const
{
	int sum = 0;
	if (weapon) sum++;
	for (int i = 0; i < len(extra_throwing_weapons); i++)
		sum += extra_throwing_weapons[i]->get_number();
	return sum;
}
void Creature::give_armor(Armor& a, vector<Item*>* lootpile)
{
	if (!a.empty())
	{
		strip(lootpile);
		armor = a.split(1);
	}
}
void Creature::give_armor(const ArmorType& at, vector<Item*>* lootpile)
{
	Armor a(at);
	give_armor(a, lootpile);
}
void Creature::strip(vector<Item*>* lootpile)
{
	if (armor)
	{
		if (!lootpile) delete armor;
		else lootpile->push_back(armor);
		armor = NULL;
	}
}
int Creature::get_weapon_skill() const {
	int wsk = SKILL_HANDTOHAND;
	if (get_weapon().has_musical_attack())
		wsk = SKILL_MUSIC;
	else if (has_thrown_weapon && len(extra_throwing_weapons))
		wsk = extra_throwing_weapons[0]->get_attack(false, false, false)->skill;
	else wsk = get_weapon().get_attack(false, false, false)->skill;
	return get_skill(wsk);
}
string Creature::get_weapon_string(int subtype) const
{
	string r;
	if (is_armed())
	{
		r = weapon->get_name(subtype);
		if (weapon->uses_ammo())
			r += " (" + tostring(weapon->get_ammoamount()) + "/" + tostring(count_clips()) + closeParenthesis;
		else if (weapon->is_throwable())
			r += " (1/" + tostring(count_weapons() - 1) + closeParenthesis; // -1 so not to count weapon in hands.
	}
	else if (len(extra_throwing_weapons))
	{
		r = extra_throwing_weapons[0]->get_name(subtype);
		r += " (0/" + tostring(count_weapons()) + closeParenthesis;
	}
	else r = "None";
	return r;
}

int get_XML_value(const std::string& inputXml) {
	int value;
	CMarkup xml;
	xml.SetDoc(inputXml);
	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem())
	{
		std::string tag = xml.GetTagName();
		if (tag == "value")
			value = min(atoi(xml.GetData().data()), MAXATTRIBUTE);
	}
	return value;

}
// Add an age estimate to a person's name
void add_age(Creature& person)
{
	// Who knows how old the purple gorilla/tank/flaming bunny/dog is?
	if (person.animalgloss != ANIMALGLOSS_NONE)
	{
		addstrAlt(" (?)");
		return;
	}
	// For humans, estimate their age and gender
	addstrAlt(" (");
	// Almost precise estimates of child and teen ages
	if (person.age<20)
	{
		// Inaccuracy in estimating age should be the same every
		// time a character is queried. I'm using the day of the
		// month the character was born on to determine this.
		addstrAlt(person.age + person.birthday_day % 3 - 1);
		addstrAlt("?");
	}
	// More rough estimates of everyone else
	else
	{
		if (person.age<30)
			addstrAlt("20s");
		else if (person.age<40)
			addstrAlt("30s");
		else if (person.age<50)
			addstrAlt("40s");
		else if (person.age<60)
			addstrAlt("50s");
		else if (person.age<70)
			addstrAlt("60s");
		else if (person.age<80)
			addstrAlt("70s");
		else if (person.age<90)
			addstrAlt("80s");
		else
			addstrAlt("Very Old");
	}
	// Assess their gender Liberally but allow ambiguity since you don't know them well enough yet
	if (person.gender_liberal == GENDER_MALE)
		addstrAlt(", Male");
	else if (person.gender_liberal == GENDER_FEMALE)
		addstrAlt(", Female");
	else
		addstrAlt(", Ambiguous");
	// Note if there's some conflict with Conservative society's perceptions
	if (person.gender_liberal != person.gender_conservative && person.gender_liberal != GENDER_NEUTRAL)
		addstrAlt("?");
	addstrAlt(closeParenthesis);
}
/* rolls up a proper name for a creature */
void Creature::namecreature()
{
	if (!dontname)
	{
		generate_name(name, gender_liberal);
		strcpy(propername, name);
		dontname = true;
	}
}