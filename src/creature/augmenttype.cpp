
#include "../includes.h"
const string CONST_augmenttypeB014 = " lacks idname.";
const string CONST_augmenttype013 = "Augment type ";
const string CONST_augmenttype012 = "LACKS IDNAME ";

const string tag_difficulty = "difficulty";
const string tag_cost = "cost";
const string tag_min_age = "min_age";
const string tag_max_age = "max_age";
const string tag_description = "description";
const string tag_effect = "effect";
const string tag_attribute = "attribute";
const string tag_type = "type";
const string tag_name = "name";
const string tag_idname = "idname";
const string tag_id = "id";
const string blankString = "";
#include "augmentation.h"
#include "augmenttype.h"
//own header
#include "../log/log.h"
// for log
#include "../common/stringconversion.h"
int AugmentType::number_of_augmenttypes = 0;


// #include "../includes.h"
/*
const string CONST_augmenttypeB014 = " lacks idname.";
const string CONST_augmenttype013 = "Augment type ";
const string CONST_augmenttype012 = "LACKS IDNAME ";

const string tag_difficulty = "difficulty";
const string tag_cost = "cost";
const string tag_min_age = "min_age";
const string tag_max_age = "max_age";
const string tag_idname = "idname";
const string tag_id = "id";
*/
//int AugmentType::number_of_augmenttypes = 0;


map<string, int> augmentTags = {
	map<string, int>::value_type(tag_name, ENUM_tag_name),
	map<string, int>::value_type(tag_type, ENUM_tag_type),
	map<string, int>::value_type(tag_attribute, ENUM_tag_attribute),
	map<string, int>::value_type(tag_effect, ENUM_tag_effect),
	map<string, int>::value_type(tag_description, ENUM_tag_description),
	map<string, int>::value_type(tag_max_age, ENUM_tag_max_age),
	map<string, int>::value_type(tag_min_age, ENUM_tag_min_age),
	map<string, int>::value_type(tag_cost, ENUM_tag_cost),
	map<string, int>::value_type(tag_difficulty, ENUM_tag_difficulty),
};

AugmentType::AugmentType(const std::string& xmlstring) : max_age_(-1), min_age_(-1), cost_(0), difficulty_(5)
{
	extern Log xmllog;
	id_ = number_of_augmenttypes++;
	CMarkup xml;
	xml.SetDoc(xmlstring);
	xml.FindElem();
	idname_ = xml.GetAttrib(tag_idname);
	if (!len(idname_))
	{
		idname_ = CONST_augmenttype012 + tostring(id_);
		xmllog.log(CONST_augmenttype013 + tostring(id_) + CONST_augmenttypeB014);
	}
	xml.IntoElem();
	while (xml.FindElem())
	{
		std::string element = xml.GetTagName();
		if (augmentTags.count(element)) {
			switch (augmentTags[element]) {
			case ENUM_tag_name:
				name_ = xml.GetData();
				break;
			case ENUM_tag_type:
				type_ = augment_string_to_enum(xml.GetData());
				break;
			case ENUM_tag_attribute:
				attribute_ = attribute_string_to_enum(xml.GetData());
				break;
			case ENUM_tag_effect:
				effect_ = atoi(xml.GetData().c_str());
				break;
			case ENUM_tag_description:
				description_ = xml.GetData();
				break;
			case ENUM_tag_max_age:
				max_age_ = atoi(xml.GetData().c_str());
				break;
			case ENUM_tag_min_age:
				min_age_ = atoi(xml.GetData().c_str());
				break;
			case ENUM_tag_cost:
				cost_ = atoi(xml.GetData().c_str());
				break;
			case ENUM_tag_difficulty:
				difficulty_ = atoi(xml.GetData().c_str());
				break;
			}
		}
	}
}
void AugmentType::make_augment(Augmentation& au)
{
	au.name = get_name();
	au.type = get_type();
	au.attribute = get_attribute();
	au.effect = get_effect();
}
