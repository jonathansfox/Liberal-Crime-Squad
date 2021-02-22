
const string paranthesisDollar = "($";
const string CLOSE_PARENTHESIS = ")";
const string undefined = "UNDEFINED";
const string tag_letter = "letter";
const string tag_sleeperprice = "sleeperprice";
const string tag_price = "price";
const string tag_description = "description";
const string tag_type = "type";
const string tag_LOOT = "LOOT";
const string tag_ARMOR = "ARMOR";
const string tag_CLIP = "CLIP";
const string tag_WEAPON = "WEAPON";
const string tag_class = "class";
const string tag_item = "item";
const string tag_sell_masks = "sell_masks";
const string tag_exit = "exit";
const string tag_entry = "entry";
const string tag_department = "department";
const string tag_increase_prices_with_illegality = "increase_prices_with_illegality";
const string tag_allow_selling = "allow_selling";
const string tag_fullscreen = "fullscreen";
const string tag_on = "on";
const string tag_only_sell_legal_items = "only_sell_legal_items";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
map<string, int> shopInitTags = {
map<string, int>::value_type(tag_only_sell_legal_items, ENUM_tag_only_sell_legal_items),
map<string, int>::value_type(tag_fullscreen, ENUM_tag_fullscreen),
map<string, int>::value_type(tag_allow_selling, ENUM_tag_allow_selling),
map<string, int>::value_type(tag_increase_prices_with_illegality, ENUM_tag_increase_prices_with_illegality),
map<string, int>::value_type(tag_department, ENUM_tag_department),
map<string, int>::value_type(tag_entry, ENUM_tag_entry),
map<string, int>::value_type(tag_exit, ENUM_tag_exit),
map<string, int>::value_type(tag_sell_masks, ENUM_tag_sell_masks),
map<string, int>::value_type(tag_letter, ENUM_tag_letter),
map<string, int>::value_type(tag_item, ENUM_tag_item),

};
map<string, int> shopItemTags = {
	map<string, int>::value_type(tag_class, ENUM_tag_class),
	map<string, int>::value_type(tag_type, ENUM_tag_type),
	map<string, int>::value_type(tag_description, ENUM_tag_description),
	map<string, int>::value_type(tag_price, ENUM_tag_price),
	map<string, int>::value_type(tag_sleeperprice, ENUM_tag_sleeperprice),
	map<string, int>::value_type(tag_letter, ENUM_tag_letter),

};