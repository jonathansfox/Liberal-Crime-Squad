#include "includes.h"
#include "common\\customMaps.h"


special_wound_structure customWound(bodypartBreakType breakType_, string shot_, string burned_, string torn_, string cut_, string defaultString_, vector<SpecialWounds> specialWounds_, int maxBlood_) {
	special_wound_structure newWound;
	newWound.breakType = breakType_;
	newWound.shot = shot_;
	newWound.burned = burned_;
	newWound.torn = torn_;
	newWound.cut = cut_;
	newWound.defaultString = defaultString_;
	newWound.specialWounds = specialWounds_;
	newWound.maxBlood = maxBlood_;
	return newWound;
}


file_and_text_collection customText(vector<string>  *collection_, string fileName_) {
	file_and_text_collection newWound;
	newWound.collection = collection_;
	newWound.fileName = fileName_;
	newWound.superCollection = false;
	return newWound;
}
file_and_text_collection customText(vector<vector<string>>  *collection_, string fileName_, int dimensions_) {
	file_and_text_collection newWound;
	newWound.super_collection = collection_;
	newWound.fileName = fileName_;
	newWound.dimensions = dimensions_;
	newWound.superCollection = true;
	return newWound;
}