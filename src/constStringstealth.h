
const string tag_ARMOR = "ARMOR";
const string tag_ARMOR_BUNKERGEAR = "ARMOR_BUNKERGEAR";
const string tag_ARMOR_SWATARMOR = "ARMOR_SWATARMOR";
const string tag_ARMOR_DEATHSQUADUNIFORM = "ARMOR_DEATHSQUADUNIFORM";
const string tag_ARMOR_POLICEARMOR = "ARMOR_POLICEARMOR";
const string tag_ARMOR_POLICEUNIFORM = "ARMOR_POLICEUNIFORM";
const string tag_ARMOR_EXPENSIVEDRESS = "ARMOR_EXPENSIVEDRESS";
const string tag_ARMOR_EXPENSIVESUIT = "ARMOR_EXPENSIVESUIT";
const string tag_ARMOR_SECURITYUNIFORM = "ARMOR_SECURITYUNIFORM";
const string tag_ARMOR_CHEAPDRESS = "ARMOR_CHEAPDRESS";
const string tag_ARMOR_CHEAPSUIT = "ARMOR_CHEAPSUIT";
const string tag_ARMOR_SEALSUIT = "ARMOR_SEALSUIT";
const string tag_ARMOR_ARMYARMOR = "ARMOR_ARMYARMOR";
const string tag_ARMOR_MILITARY = "ARMOR_MILITARY";
const string tag_ARMOR_SERVANTUNIFORM = "ARMOR_SERVANTUNIFORM";
const string tag_ARMOR_HARDHAT = "ARMOR_HARDHAT";
const string tag_ARMOR_CIVILLIANARMOR = "ARMOR_CIVILLIANARMOR";
const string tag_ARMOR_LABCOAT = "ARMOR_LABCOAT";
const string tag_ARMOR_WORKCLOTHES = "ARMOR_WORKCLOTHES";
const string tag_ARMOR_BLACKDRESS = "ARMOR_BLACKDRESS";
const string tag_ARMOR_BLACKSUIT = "ARMOR_BLACKSUIT";
const string tag_ARMOR_OVERALLS = "ARMOR_OVERALLS";
const string tag_ARMOR_PRISONER = "ARMOR_PRISONER";
const string tag_ARMOR_PRISONGUARD = "ARMOR_PRISONGUARD";
const string tag_ARMOR_BLACKROBE = "ARMOR_BLACKROBE";
const string tag_ARMOR_HEAVYARMOR = "ARMOR_HEAVYARMOR";
const string tag_ARMOR_WIFEBEATER = "ARMOR_WIFEBEATER";
const string tag_WEAPON = "WEAPON";
const string tag_WEAPON_CARBINE_M4 = "WEAPON_CARBINE_M4";
const string tag_WEAPON_CHAIN = "WEAPON_CHAIN";
const string tag_WEAPON_SHANK = "WEAPON_SHANK";
const string tag_WEAPON_SHOTGUN_PUMP = "WEAPON_SHOTGUN_PUMP";
const string tag_WEAPON_TORCH = "WEAPON_TORCH";
const string tag_WEAPON_PITCHFORK = "WEAPON_PITCHFORK";
const string tag_WEAPON_NIGHTSTICK = "WEAPON_NIGHTSTICK";
const string tag_WEAPON_SMG_MP5 = "WEAPON_SMG_MP5";
const string tag_WEAPON_FLAMETHROWER = "WEAPON_FLAMETHROWER";
const string tag_WEAPON_AXE = "WEAPON_AXE";
const string tag_WEAPON_SEMIRIFLE_AR15 = "WEAPON_SEMIRIFLE_AR15";
const string tag_WEAPON_AUTORIFLE_M16 = "WEAPON_AUTORIFLE_M16";
const string tag_WEAPON_SEMIPISTOL_45 = "WEAPON_SEMIPISTOL_45";
const string tag_WEAPON_DESERT_EAGLE = "WEAPON_DESERT_EAGLE";
const string tag_WEAPON_SEMIPISTOL_9MM = "WEAPON_SEMIPISTOL_9MM";
const string tag_WEAPON_REVOLVER_38 = "WEAPON_REVOLVER_38";
const string tag_WEAPON_REVOLVER_44 = "WEAPON_REVOLVER_44";
const string tag_WEAPON_GAVEL = "WEAPON_GAVEL";
const string tag_WEAPON_SYRINGE = "WEAPON_SYRINGE";
const string tag_ARMOR_CLOTHES = "ARMOR_CLOTHES";
const string tag_WEAPON_MP5_SMG = "WEAPON_MP5_SMG";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";

map<short, map<string, int> > siegeDisguises = {
	map<SiegeTypes, map<string, int> >::value_type(SIEGE_CIA,
		{
			map<string, int>::value_type(tag_ARMOR_BLACKSUIT, 1),
			map<string, int>::value_type(tag_ARMOR_BLACKDRESS, 1)
		}
	),

	map<SiegeTypes, map<string, int> >::value_type(SIEGE_CORPORATE,
		{
			map<string, int>::value_type(tag_ARMOR_MILITARY,  1),
			map<string, int>::value_type(tag_ARMOR_ARMYARMOR,  1),
			map<string, int>::value_type(tag_ARMOR_SEALSUIT,  1),
		}
	),
	map<SiegeTypes, map<string, int> >::value_type(SIEGE_HICKS,
		{
			map<string, int>::value_type(tag_ARMOR_CLOTHES,  2),
			map<string, int>::value_type(tag_ARMOR_OVERALLS,  1),
			map<string, int>::value_type(tag_ARMOR_WIFEBEATER, 1),
		}
	),
	map<SiegeTypes, map<string, int> >::value_type(SIEGE_FIREMEN,
		{
			map<string, int>::value_type(tag_ARMOR_BUNKERGEAR, 1),
		}
   ),
};

map<short, map<string, int> > siteDisguises = {

	map<SiteTypes, map<string, int> >::value_type(SITE_BUSINESS_CIGARBAR,{
	map<string, int>::value_type(tag_ARMOR_EXPENSIVESUIT,  1),
	map<string, int>::value_type(tag_ARMOR_CHEAPSUIT,  1),
	map<string, int>::value_type(tag_ARMOR_EXPENSIVEDRESS,  1),
	map<string, int>::value_type(tag_ARMOR_CHEAPDRESS,  1),
	map<string, int>::value_type(tag_ARMOR_BLACKSUIT,  1),
	map<string, int>::value_type(tag_ARMOR_BLACKDRESS,  1),
}
),
map<SiteTypes, map<string, int> >::value_type(SITE_CORPORATE_HEADQUARTERS,{
	map<string, int>::value_type(tag_ARMOR_EXPENSIVESUIT,  1),
	map<string, int>::value_type(tag_ARMOR_CHEAPSUIT,  1),
	map<string, int>::value_type(tag_ARMOR_SECURITYUNIFORM,  1),
	map<string, int>::value_type(tag_ARMOR_EXPENSIVEDRESS,  1),
	map<string, int>::value_type(tag_ARMOR_CHEAPDRESS,  1),
}
	),
};
map<short, map<string, int> > siteDisguisesRestricted = {

	map<SiteTypes, map<string, int> >::value_type(SITE_INDUSTRY_NUCLEAR,{
	map<string, int>::value_type(tag_ARMOR_LABCOAT,  1),
			map<string, int>::value_type(tag_ARMOR_SECURITYUNIFORM,  1),
			map<string, int>::value_type(tag_ARMOR_CIVILLIANARMOR,  1),
			map<string, int>::value_type(tag_ARMOR_HARDHAT,  1),

}
),
map<SiteTypes, map<string, int> >::value_type(SITE_MEDIA_AMRADIO,{
	map<string, int>::value_type(tag_ARMOR_SECURITYUNIFORM,  1),
			map<string, int>::value_type(tag_ARMOR_EXPENSIVESUIT,  1),
			map<string, int>::value_type(tag_ARMOR_CHEAPSUIT,  1),
			map<string, int>::value_type(tag_ARMOR_EXPENSIVEDRESS,  1),
			map<string, int>::value_type(tag_ARMOR_CHEAPDRESS,  1),

}
	),
map<SiteTypes, map<string, int> >::value_type(SITE_MEDIA_CABLENEWS,{
	map<string, int>::value_type(tag_ARMOR_SECURITYUNIFORM,  1),
			map<string, int>::value_type(tag_ARMOR_EXPENSIVESUIT,  1),
			map<string, int>::value_type(tag_ARMOR_EXPENSIVEDRESS,  1),

}
),

map<SiteTypes, map<string, int> >::value_type(SITE_GOVERNMENT_WHITE_HOUSE,{
	map<string, int>::value_type(tag_ARMOR_BLACKSUIT,  1),
			map<string, int>::value_type(tag_ARMOR_BLACKDRESS,  1),
			map<string, int>::value_type(tag_ARMOR_CHEAPSUIT,  1),
			map<string, int>::value_type(tag_ARMOR_CHEAPDRESS,  1),
			map<string, int>::value_type(tag_ARMOR_EXPENSIVESUIT,  1),
			map<string, int>::value_type(tag_ARMOR_EXPENSIVEDRESS,  1),
			map<string, int>::value_type(tag_ARMOR_MILITARY,  1),
			map<string, int>::value_type(tag_ARMOR_ARMYARMOR,  1),
			map<string, int>::value_type(tag_ARMOR_SEALSUIT,  1),

}
),
map<SiteTypes, map<string, int> >::value_type(SITE_GOVERNMENT_ARMYBASE,{
	map<string, int>::value_type(tag_ARMOR_MILITARY,  1),
			map<string, int>::value_type(tag_ARMOR_ARMYARMOR,  1),
			map<string, int>::value_type(tag_ARMOR_SEALSUIT,  1),

}
),
map<SiteTypes, map<string, int> >::value_type(SITE_GOVERNMENT_INTELLIGENCEHQ,{
	map<string, int>::value_type(tag_ARMOR_BLACKSUIT,  1),
			map<string, int>::value_type(tag_ARMOR_BLACKDRESS,  1),

}
),

};