
#include <includes.h>
#include "creature/creatureEnums.h"


std::string tostring(long i)
{
   std::ostringstream os;
   os << i;
   return os.str();
}
using std::transform;
int stringtobool(string boolstr)
{
	transform(boolstr.begin(), boolstr.end(), boolstr.begin(), ::tolower);
	if (boolstr == "true" || boolstr == "1" || boolstr == "on" || boolstr == "yes") return 1;
	else if (boolstr == "false" || boolstr == "0" || boolstr == "off" || boolstr == "no") return 0;
	else return -1;
}
typedef map< string, short > stringAndShort;
extern stringAndShort getCreatureEnumFromString;
short creaturetype_string_to_enum(const string& ctname)
{
	if (getCreatureEnumFromString.count(ctname) > 0) {
		return getCreatureEnumFromString[ctname];
	}
	else
		return -1;
}
string showXmlSkill(int skill_, int value_) {

	CMarkup xml;
	xml.AddElem("skill");
	xml.IntoElem();
	xml.AddElem("value", min(value_, MAXATTRIBUTE));
	return xml.GetDoc();
}
string showXmlAttribute(int attribute_, int value_) {

	CMarkup xml;
	xml.AddElem("attribute");
	xml.IntoElem();
	xml.AddElem("value", min(value_, MAXATTRIBUTE));
	return xml.GetDoc();
}
typedef map< short, string > shortAndString;
shortAndString skillEnumToString;
shortAndString attEnumToString;
string skill_enum_to_string(int skill_type) {

	if (skillEnumToString.count(skill_type)) {
		return skillEnumToString[skill_type];
	}
	else
		return "";
}
string attribute_enum_to_string(int attribute)
{
	if (attEnumToString.count(attribute)) {
		return attEnumToString[attribute];
	}
	else
		return "";
	/*
	if (attribute == ATTRIBUTE_STRENGTH)
		return "strength";
	else if (attribute == ATTRIBUTE_INTELLIGENCE)
		return "intelligence";
	else if (attribute == ATTRIBUTE_WISDOM)
		return "wisdom";
	else if (attribute == ATTRIBUTE_AGILITY)
		return "agility";
	else if (attribute == ATTRIBUTE_HEALTH)
		return "health";
	else if (attribute == ATTRIBUTE_CHARISMA)
		return "charisma";
	else if (attribute == ATTRIBUTE_HEART)
		return "heart";
	else
		return "";*/
}
int attribute_string_to_enum(const string& attribute)
{
	if (attribute == "strength")
		return ATTRIBUTE_STRENGTH;
	else if (attribute == "intelligence")
		return ATTRIBUTE_INTELLIGENCE;
	else if (attribute == "wisdom")
		return ATTRIBUTE_WISDOM;
	else if (attribute == "agility")
		return ATTRIBUTE_AGILITY;
	else if (attribute == "health")
		return ATTRIBUTE_HEALTH;
	else if (attribute == "charisma")
		return ATTRIBUTE_CHARISMA;
	else if (attribute == "heart")
		return ATTRIBUTE_HEART;
	else
		return -1;
}

int gender_string_to_enum(const string& gender)
{
	if (gender == "NEUTRAL")
		return GENDER_NEUTRAL;
	else if (gender == "MALE")
		return GENDER_MALE;
	else if (gender == "FEMALE")
		return GENDER_FEMALE;
	else if (gender == "GENDER_WHITEMALEPATRIARCH")
		return GENDER_WHITEMALEPATRIARCH;
	else if (gender == "MALE BIAS")
		return GENDER_MALE_BIAS;
	else if (gender == "FEMALE BIAS")
		return GENDER_FEMALE_BIAS;
	else if (gender == "RANDOM")
		return GENDER_RANDOM;
	else
		return -1;
}
 string NONE;
int severtype_string_to_enum(const string& severtype)
{
	if (severtype == "NASTY")
		return WOUND_NASTYOFF;
	else if (severtype == "CLEAN")
		return WOUND_CLEANOFF;
	else if (severtype == NONE)
		return 0;
	else
		return -1;
}
int skill_string_to_enum(string skillname)
{
	transform(skillname.begin(), skillname.end(), skillname.begin(), ::tolower);
	if (skillname == "handtohand")
		return SKILL_HANDTOHAND;
	else if (skillname == "knife")
		return SKILL_KNIFE;
	else if (skillname == "sword")
		return SKILL_SWORD;
	else if (skillname == "club")
		return SKILL_CLUB;
	else if (skillname == "axe")
		return SKILL_AXE;
	else if (skillname == "throwing")
		return SKILL_THROWING;
	else if (skillname == "pistol")
		return SKILL_PISTOL;
	else if (skillname == "rifle")
		return SKILL_RIFLE;
	else if (skillname == "smg")
		return SKILL_SMG;
	else if (skillname == "shotgun")
		return SKILL_SHOTGUN;
	else if (skillname == "persuasion")
		return SKILL_PERSUASION;
	else if (skillname == "psychology")
		return SKILL_PSYCHOLOGY;
	else if (skillname == "law")
		return SKILL_LAW;
	else if (skillname == "security")
		return SKILL_SECURITY;
	else if (skillname == "disguise")
		return SKILL_DISGUISE;
	else if (skillname == "computers")
		return SKILL_COMPUTERS;
	else if (skillname == "tailoring")
		return SKILL_TAILORING;
	else if (skillname == "driving")
		return SKILL_DRIVING;
	else if (skillname == "writing")
		return SKILL_WRITING;
	else if (skillname == "music")
		return SKILL_MUSIC;
	else if (skillname == "art")
		return SKILL_ART;
	else if (skillname == "religion")
		return SKILL_RELIGION;
	else if (skillname == "science")
		return SKILL_SCIENCE;
	else if (skillname == "business")
		return SKILL_BUSINESS;
	else if (skillname == "stealth")
		return SKILL_STEALTH;
	else if (skillname == "teaching")
		return SKILL_TEACHING;
	else if (skillname == "streetsense")
		return SKILL_STREETSENSE;
	else if (skillname == "seduction")
		return SKILL_SEDUCTION;
	else if (skillname == "firstaid")
		return SKILL_FIRSTAID;
	else if (skillname == "dodge")
		return SKILL_DODGE;
	else if (skillname == "heavyweapons")
		return SKILL_HEAVYWEAPONS;
	else
		return -1;
}

int get_associated_attribute(int skill_type)
{
	// Initialize associated attribute
	switch (skill_type)
	{
	case SKILL_CLUB:
	case SKILL_AXE:
	case SKILL_HEAVYWEAPONS:
		return ATTRIBUTE_STRENGTH;
	case SKILL_HANDTOHAND:
	case SKILL_KNIFE:
	case SKILL_SWORD:
	case SKILL_PISTOL:
	case SKILL_RIFLE:
	case SKILL_SMG:
	case SKILL_SHOTGUN:
	case SKILL_DRIVING:
	case SKILL_STEALTH:
	case SKILL_THROWING:
	case SKILL_DODGE:
		return ATTRIBUTE_AGILITY;
	case SKILL_DISGUISE:
	case SKILL_SEDUCTION:
	case SKILL_PERSUASION:
		return ATTRIBUTE_CHARISMA;
	case SKILL_ART:
	case SKILL_MUSIC:
		return ATTRIBUTE_HEART;
	case SKILL_RELIGION:
	case SKILL_BUSINESS:
	case SKILL_WRITING:
	case SKILL_PSYCHOLOGY:
	case SKILL_SECURITY:
	case SKILL_TAILORING:
	case SKILL_TEACHING:
	case SKILL_FIRSTAID:
	case SKILL_SCIENCE:
	case SKILL_LAW:
	case SKILL_COMPUTERS:
	case SKILL_STREETSENSE:
	default:
		return ATTRIBUTE_INTELLIGENCE;
	}
}