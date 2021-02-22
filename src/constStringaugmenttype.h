
const string LACKS_IDNAME_LOWERCASE = " lacks idname.";
const string AUGMENT_TYPE_SPACE = "Augment type ";
const string LACKS_IDNAME = "LACKS IDNAME ";

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