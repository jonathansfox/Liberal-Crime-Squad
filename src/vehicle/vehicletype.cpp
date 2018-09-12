
#include "../includes.h"
const string CONST_vehicletypeB061 = ": ";
const string CONST_vehicletypeB060 = "::stealing: ";
const string CONST_vehicletypeB055 = "::colors: ";
const string CONST_vehicletypeB054 = "::year: ";
const string CONST_vehicletypeB053 = "UNDEF";
const string CONST_vehicletype063 = "Unknown element for vehicle type ";
const string CONST_vehicletype062 = "::available_at_dealership: ";
const string CONST_vehicletype061 = "Invalid boolean value for vehicle type ";
const string CONST_vehicletype054 = "::colors::display_color: ";
const string CONST_vehicletype051 = "::year::add_random_up_to_current_year: ";
const string CONST_vehicletype049 = "::year::start_at_current_year: ";
const string CONST_vehicletype047 = "LACKS IDNAME ";
const string CONST_vehicletype046 = "UNDEFINED";

const string tag_window = "window";
const string tag_body = "body";
const string tag_Translucent = "Translucent";
const string tag_sleeperprice = "sleeperprice";
const string tag_price = "price";
const string tag_available_at_dealership = "available_at_dealership";
const string tag_armor = "armor";
const string tag_armor_midpoint = "armor_midpoint";
const string tag_high_armor_max = "high_armor_max";
const string tag_high_armor_min = "high_armor_min";
const string tag_low_armor_max = "low_armor_max";
const string tag_low_armor_min = "low_armor_min";
const string tag_touch_alarm_chance = "touch_alarm_chance";
const string tag_sense_alarm_chance = "sense_alarm_chance";
const string tag_extra_heat = "extra_heat";
const string tag_juice = "juice";
const string tag_difficulty = "difficulty";
const string tag_difficulty_to_find = "difficulty_to_find";
const string tag_stealing = "stealing";
const string tag_shortname = "shortname";
const string tag_longname = "longname";
const string tag_passenger = "passenger";
const string tag_driver = "driver";
const string tag_attackbonus = "attackbonus";
const string tag_attack = "attack";
const string tag_hardlimit = "hardlimit";
const string tag_softlimit = "softlimit";
const string tag_skillfactor = "skillfactor";
const string tag_skill = "skill";
const string tag_base = "base";
const string tag_dodgebonus = "dodgebonus";
const string tag_dodge = "dodge";
const string tag_drivebonus = "drivebonus";
const string tag_display_color = "display_color";
const string tag_color = "color";
const string tag_colors = "colors";
const string tag_add = "add";
const string tag_add_random = "add_random";
const string tag_add_random_up_to_current_year = "add_random_up_to_current_year";
const string tag_start_at_year = "start_at_year";
const string tag_start_at_current_year = "start_at_current_year";
const string tag_year = "year";
const string blankString = "";
const string tag_idname = "idname";
const string tag_id = "id";
#include "../creature/creatureEnums.h"
#include "vehicletype.h"
#include "../common/stringconversion.h"
//for atoi
int VehicleType::number_of_vehicletypes = 0;

map<string, int> vehicleTypeTagList = {
	map<string, int>::value_type(tag_year, ENUM_tag_year),
	map<string, int>::value_type(tag_start_at_current_year, ENUM_tag_start_at_current_year),
	map<string, int>::value_type(tag_start_at_year, ENUM_tag_start_at_year),
	map<string, int>::value_type(tag_add_random_up_to_current_year, ENUM_tag_add_random_up_to_current_year),
	map<string, int>::value_type(tag_add_random, ENUM_tag_add_random),
	map<string, int>::value_type(tag_add, ENUM_tag_add),
	map<string, int>::value_type(tag_colors, ENUM_tag_colors),
	map<string, int>::value_type(tag_color, ENUM_tag_color),
	map<string, int>::value_type(tag_display_color, ENUM_tag_display_color),
	map<string, int>::value_type(tag_drivebonus, ENUM_tag_drivebonus),
	map<string, int>::value_type(tag_base, ENUM_tag_base),
	map<string, int>::value_type(tag_skillfactor, ENUM_tag_skillfactor),
	map<string, int>::value_type(tag_softlimit, ENUM_tag_softlimit),
	map<string, int>::value_type(tag_hardlimit, ENUM_tag_hardlimit),
	map<string, int>::value_type(tag_dodgebonus, ENUM_tag_dodgebonus),
	map<string, int>::value_type(tag_base, ENUM_tag_base),
	map<string, int>::value_type(tag_skillfactor, ENUM_tag_skillfactor),
	map<string, int>::value_type(tag_softlimit, ENUM_tag_softlimit),
	map<string, int>::value_type(tag_hardlimit, ENUM_tag_hardlimit),
	map<string, int>::value_type(tag_attackbonus, ENUM_tag_attackbonus),
	map<string, int>::value_type(tag_driver, ENUM_tag_driver),
	map<string, int>::value_type(tag_passenger, ENUM_tag_passenger),
	map<string, int>::value_type(tag_longname, ENUM_tag_longname),
	map<string, int>::value_type(tag_shortname, ENUM_tag_shortname),
	map<string, int>::value_type(tag_stealing, ENUM_tag_stealing),
	map<string, int>::value_type(tag_difficulty_to_find, ENUM_tag_difficulty_to_find),
	map<string, int>::value_type(tag_juice, ENUM_tag_juice),
	map<string, int>::value_type(tag_extra_heat, ENUM_tag_extra_heat),
	map<string, int>::value_type(tag_sense_alarm_chance, ENUM_tag_sense_alarm_chance),
	map<string, int>::value_type(tag_touch_alarm_chance, ENUM_tag_touch_alarm_chance),
	map<string, int>::value_type(tag_armor, ENUM_tag_armor),
	map<string, int>::value_type(tag_low_armor_min, ENUM_tag_low_armor_min),
	map<string, int>::value_type(tag_low_armor_max, ENUM_tag_low_armor_max),
	map<string, int>::value_type(tag_high_armor_min, ENUM_tag_high_armor_min),
	map<string, int>::value_type(tag_high_armor_max, ENUM_tag_high_armor_max),
	map<string, int>::value_type(tag_armor_midpoint, ENUM_tag_armor_midpoint),
	map<string, int>::value_type(tag_available_at_dealership, ENUM_tag_available_at_dealership),
	map<string, int>::value_type(tag_price, ENUM_tag_price),
	map<string, int>::value_type(tag_sleeperprice, ENUM_tag_sleeperprice),
};
VehicleType::VehicleType(MCD_STR xmlstring)
	: /*idname_(CONST_vehicletype046), id_(-1),*/ year_startcurrent_(true), year_start_(0), //Default values
	year_randomuptocurrent_(false), year_addrandom_(0), year_add_(0), displaycolor_(true),
	longname_(CONST_vehicletype046), shortname_(CONST_vehicletypeB053),
	drivebonus_(0), drivebonus_factor_(1), drivebonus_limit1_(8), drivebonus_limit2_(99),
	dodgebonus_(0), dodgebonus_factor_(1), dodgebonus_limit1_(8), dodgebonus_limit2_(99),
	attackbonus_driver_(-2), attackbonus_passenger_(0),
	armormidpoint_(50), lowarmormin_(4), lowarmormax_(6), higharmormin_(0), higharmormax_(2),
	steal_difficultytofind_(1), steal_juice_(0), steal_extraheat_(0),
	sensealarmchance_(0), touchalarmchance_(0), availableatshop_(true), price_(1234), sleeperprice_(1111)
{
	id_ = number_of_vehicletypes++;
	CMarkup xmlfile;
	xmlfile.SetDoc(xmlstring);
	xmlfile.FindElem();
	idname_ = xmlfile.GetAttrib(tag_idname);
	if (idname_ == blankString)
		idname_ = CONST_vehicletype047 + tostring(id_);
	xmlfile.IntoElem();
	while (xmlfile.FindElem()) //Loop over all the elements inside the vehicletype element.
	{
		std::string element = xmlfile.GetTagName();
		if (vehicleTypeTagList.count(element)) {
			switch (vehicleTypeTagList[element]) {

			case ENUM_tag_year:
				xmlfile.IntoElem();
				while (xmlfile.FindElem())
				{
					switch (vehicleTypeTagList[xmlfile.GetTagName()]) {
					case ENUM_tag_start_at_current_year:
						if (!stringtobool(xmlfile.GetData()))
							year_startcurrent_ = false;
						else
							year_startcurrent_ = true;
						break;
					case ENUM_tag_start_at_year:
						year_start_ = atoi(xmlfile.GetData());
					case ENUM_tag_add_random_up_to_current_year:
					{
						if (!stringtobool(xmlfile.GetData()))
							year_randomuptocurrent_ = true;
						else
							year_randomuptocurrent_ = false;
						break;
					}
					case ENUM_tag_add_random:
						year_addrandom_ = atoi(xmlfile.GetData());
						break;
					case ENUM_tag_add:
						year_add_ = atoi(xmlfile.GetData());
						break;
					}
				}
				xmlfile.OutOfElem();
				break;
			case ENUM_tag_colors:
				xmlfile.IntoElem();
				//std::string color;
				while (xmlfile.FindElem())
				{
					switch (vehicleTypeTagList[xmlfile.GetTagName()]) {

					case ENUM_tag_color:
						color_.push_back(xmlfile.GetData());

						break;
					case ENUM_tag_display_color:
						if (!stringtobool(xmlfile.GetData()))
							displaycolor_ = false;
						else
							displaycolor_ = true;
						break;
					}

				}
				xmlfile.OutOfElem();
				break;
			case ENUM_tag_drivebonus:
				xmlfile.IntoElem();
				while (xmlfile.FindElem())
				{
					switch (vehicleTypeTagList[xmlfile.GetTagName()]) {

					case ENUM_tag_base:
						drivebonus_ = atoi(xmlfile.GetData());
						break;
					case ENUM_tag_skillfactor:
						drivebonus_factor_ = atof(xmlfile.GetData());
						break;
					case ENUM_tag_softlimit:
						drivebonus_limit1_ = atoi(xmlfile.GetData());
						break;
					case ENUM_tag_hardlimit:
						drivebonus_limit2_ = atoi(xmlfile.GetData());
						break;
					}
				}
				xmlfile.OutOfElem();
				break;
			case ENUM_tag_dodgebonus:
				xmlfile.IntoElem();
				while (xmlfile.FindElem())
				{
					switch (vehicleTypeTagList[xmlfile.GetTagName()]) {

					case ENUM_tag_base:
						dodgebonus_ = atoi(xmlfile.GetData());
						break;
					case ENUM_tag_skillfactor:
						dodgebonus_factor_ = atof(xmlfile.GetData());
						break;
					case ENUM_tag_softlimit:
						dodgebonus_limit1_ = atoi(xmlfile.GetData());
						break;
					case ENUM_tag_hardlimit:
						dodgebonus_limit2_ = atoi(xmlfile.GetData());
						break;
					}

				}
				xmlfile.OutOfElem();
				break;
			case ENUM_tag_attackbonus:
				xmlfile.IntoElem();
				while (xmlfile.FindElem())
				{
					switch (vehicleTypeTagList[xmlfile.GetTagName()]) {

					case ENUM_tag_driver:
						attackbonus_driver_ = atoi(xmlfile.GetData());
						break;
					case ENUM_tag_passenger:
						attackbonus_passenger_ = atoi(xmlfile.GetData());
						break;
					}
				}
				xmlfile.OutOfElem();
				break;
			case ENUM_tag_longname:
				longname_ = xmlfile.GetData();
				break;
			case ENUM_tag_shortname:
				shortname_ = xmlfile.GetData();
				if (len(shortname_) > 7)
					shortname_.resize(7); //Only seven characters allowed for shortname_.
				break;
			case ENUM_tag_stealing:
				xmlfile.IntoElem();
				while (xmlfile.FindElem())
				{
					switch (vehicleTypeTagList[xmlfile.GetTagName()]) {

					case ENUM_tag_difficulty_to_find:
						steal_difficultytofind_ = atoi(xmlfile.GetData());
						break;
					case ENUM_tag_juice:
						steal_juice_ = atoi(xmlfile.GetData());
						break;
					case ENUM_tag_extra_heat:
						steal_extraheat_ = atoi(xmlfile.GetData());
						break;
					case ENUM_tag_sense_alarm_chance:
						sensealarmchance_ = atoi(xmlfile.GetData());
						break;
					case ENUM_tag_touch_alarm_chance:
						touchalarmchance_ = atoi(xmlfile.GetData());
						break;
					}
				}
				xmlfile.OutOfElem();
				break;
			case ENUM_tag_armor:
				xmlfile.IntoElem();
				while (xmlfile.FindElem())
				{
					switch (vehicleTypeTagList[xmlfile.GetTagName()]) {

					case ENUM_tag_low_armor_min:
						lowarmormin_ = atoi(xmlfile.GetData());
						break;
					case ENUM_tag_low_armor_max:
						lowarmormax_ = atoi(xmlfile.GetData());
						break;
					case ENUM_tag_high_armor_min:
						higharmormin_ = atoi(xmlfile.GetData());
						break;
					case ENUM_tag_high_armor_max:
						higharmormax_ = atoi(xmlfile.GetData());
						break;
					case ENUM_tag_armor_midpoint:
						armormidpoint_ = atoi(xmlfile.GetData());
						break;
					}
				}
				xmlfile.OutOfElem();
				break;
			case ENUM_tag_available_at_dealership:
				if (!stringtobool(xmlfile.GetData()))
					availableatshop_ = false;
				else
					availableatshop_ = true;
				break;
			case ENUM_tag_price:
				price_ = atoi(xmlfile.GetData());
				break;
			case ENUM_tag_sleeperprice:
				sleeperprice_ = atoi(xmlfile.GetData());
				break;
			}
		}

	}
	if (len(color_) == 0)
		color_.push_back(tag_Translucent); //Default.
										   //xmlfile.OutOfElem();
}
int VehicleType::makeyear() const
{
	extern int year;
	int myear = 0;
	if (year_startcurrent_)
		myear = year;
	else
		myear = year_start_;
	if (year_randomuptocurrent_)
		myear += LCSrandom(year - year_start_ + 1);
	if (year_addrandom_ > 0)
		myear += LCSrandom(year_addrandom_);
	else if (year_addrandom_ < 0)
		myear -= LCSrandom(-year_addrandom_);
	myear += year_add_;
	return myear;
}
int VehicleType::gethitlocation(int bodypart)
{
	switch (bodypart)
	{
	case BODYPART_HEAD:
		return CARPART_WINDOW;
	case BODYPART_BODY:
	case BODYPART_ARM_RIGHT:
	case BODYPART_ARM_LEFT:
		return (LCSrandom(100) < armormidpoint_) ? CARPART_BODY : CARPART_WINDOW;
	case BODYPART_LEG_RIGHT:
	case BODYPART_LEG_LEFT:
		return CARPART_BODY;
	default:
		return CARPART_WINDOW;
	}
}
string VehicleType::getpartname(int location)
{
	return location == CARPART_WINDOW ? tag_window : tag_body;
}
int VehicleType::armorbonus(int location)
{
	switch (location)
	{
	case CARPART_BODY:
		return LCSrandom(lowarmormax_ - lowarmormin_ + 1) + lowarmormin_;
	case CARPART_WINDOW:
		return LCSrandom(higharmormax_ - higharmormin_ + 1) + higharmormin_;
	default:
		return 0;
	}
}
int VehicleType::modifieddriveskill(int skillLevel)
{
	int score = (int)floor((skillLevel + drivebonus_)*drivebonus_factor_);
	if (score < drivebonus_limit1_)
		return score;
	if (score > drivebonus_limit1_)
		score = (score + drivebonus_limit1_) / 2; // half credit after limit1
	return (score > drivebonus_limit2_) ? drivebonus_limit2_ : score;
}
int VehicleType::modifieddodgeskill(int skillLevel)
{
	int score = (int)floor((skillLevel + dodgebonus_)*dodgebonus_factor_);
	if (score < dodgebonus_limit1_)
		return score;
	if (score > dodgebonus_limit1_)
		score = (score + dodgebonus_limit1_) / 2; // half credit after limit1
	return (score > dodgebonus_limit2_) ? dodgebonus_limit2_ : score;
}
const string& VehicleType::idname() const { return idname_; }
long VehicleType::id() const { return id_; }
const vector<string>& VehicleType::color() const { return color_; }
bool VehicleType::displayscolor() const { return displaycolor_; }
const string& VehicleType::longname() const { return longname_; }
const string& VehicleType::shortname() const { return shortname_; }
int VehicleType::attackbonus(bool isDriving) const { return isDriving ? attackbonus_driver_ : attackbonus_passenger_; }
int VehicleType::steal_difficultytofind() const { return steal_difficultytofind_; }
int VehicleType::steal_juice() const { return steal_juice_; }
int VehicleType::steal_extraheat() const { return steal_extraheat_; }
int VehicleType::sensealarmchance() const { return sensealarmchance_; }
int VehicleType::touchalarmchance() const { return touchalarmchance_; }
bool VehicleType::availableatshop() const { return availableatshop_; }
int VehicleType::price() const { return price_; }
int VehicleType::sleeperprice() const { return sleeperprice_; }

