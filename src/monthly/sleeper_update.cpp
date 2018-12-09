#define	SLEEPER_UPDATE_CPP
#include "../includes.h"
/*
This file is part of Liberal Crime Squad.                                           //
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
/* monthly - sleeper behavior */
Log gamelog; //The gamelog.
Log xmllog; // Log for xml errors or bad values.


map<CreatureTypes, vector<CreatureSkill> > skill_influence = {
	map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_CRITIC_ART,
		{ SKILL_WRITING, SKILL_ART }),
		map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_PAINTER,
			{ SKILL_ART }),
			map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_SCULPTOR,
				{ SKILL_ART }),
				map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_CRITIC_MUSIC,
					{ SKILL_WRITING, SKILL_MUSIC }),
					map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_MUSICIAN,
						{ SKILL_MUSIC }),
						map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_AUTHOR,
							{ SKILL_WRITING }),
							map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_JOURNALIST,
								{ SKILL_WRITING }),
								map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_JUDGE_CONSERVATIVE,
									{ SKILL_WRITING, SKILL_LAW }),
									map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_LAWYER,
										{ SKILL_LAW }),
										map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_SCIENTIST_LABTECH,
											{ SKILL_SCIENCE }),
											map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_SCIENTIST_EMINENT,
												{ SKILL_SCIENCE }),
												map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_CORPORATE_CEO,
													{ SKILL_BUSINESS }),
													map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_CORPORATE_MANAGER,
														{ SKILL_BUSINESS }),
														map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_PRIEST,
															{ SKILL_RELIGION }),
															map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_NUN,
																{ SKILL_RELIGION }),
																map<CreatureTypes, vector<CreatureSkill> > ::value_type(CREATURE_EDUCATOR,
																	{ SKILL_PSYCHOLOGY }),
};
map<CreatureTypes, int> super_sleepers_multiplier = {
	map<CreatureTypes, int> ::value_type(CREATURE_CORPORATE_CEO, 20),
	map<CreatureTypes, int> ::value_type(CREATURE_POLITICIAN, 20),
	map<CreatureTypes, int> ::value_type(CREATURE_SCIENTIST_EMINENT, 20),
	map<CreatureTypes, int> ::value_type(CREATURE_DEATHSQUAD, 6),
	map<CreatureTypes, int> ::value_type(CREATURE_EDUCATOR, 6),
	map<CreatureTypes, int> ::value_type(CREATURE_MILITARYOFFICER, 6),
	map<CreatureTypes, int> ::value_type(CREATURE_ACTOR, 4),
	map<CreatureTypes, int> ::value_type(CREATURE_GANGUNIT, 4),
	map<CreatureTypes, int> ::value_type(CREATURE_MILITARYPOLICE, 4),
	map<CreatureTypes, int> ::value_type(CREATURE_SEAL, 4),
};

map<CreatureTypes, vector<Views> > creature_influences_views = {

	/* Cultural leaders block - influences cultural issues */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_PRIEST,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
		),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_PAINTER,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SCULPTOR,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_AUTHOR,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_JOURNALIST,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_PSYCHOLOGIST,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_MUSICIAN,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_CRITIC_ART,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_CRITIC_MUSIC,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_ACTOR,
		{ VIEW_WOMEN,
		VIEW_CIVILRIGHTS,
		VIEW_GAY,
		VIEW_FREESPEECH,
		VIEW_DRUGS,
		VIEW_IMMIGRATION }
	),
	/* Legal block - influences an array of social issues */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_JUDGE_CONSERVATIVE,
		{ VIEW_JUSTICES,
		VIEW_FREESPEECH,
		VIEW_INTELLIGENCE,
		VIEW_POLICEBEHAVIOR,
		VIEW_DEATHPENALTY,
		VIEW_GUNCONTROL,
		VIEW_DRUGS }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_LAWYER,
		{ VIEW_POLICEBEHAVIOR,
		VIEW_DEATHPENALTY,
		VIEW_GUNCONTROL,
		VIEW_DRUGS }
	),
	/* Scientists block */
	map<CreatureTypes, vector<Views> > ::value_type ( CREATURE_SCIENTIST_EMINENT,
		{ VIEW_POLLUTION,
		VIEW_NUCLEARPOWER,
		VIEW_ANIMALRESEARCH,
		VIEW_GENETICS }
	),


	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SCIENTIST_LABTECH,
		{ VIEW_NUCLEARPOWER,
		VIEW_ANIMALRESEARCH,
		VIEW_GENETICS }
	),
	/* Corporate block */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_CORPORATE_CEO,
		{ VIEW_CEOSALARY,
		VIEW_WOMEN,
		VIEW_TAXES,
		VIEW_CORPORATECULTURE,
		VIEW_SWEATSHOPS,
		VIEW_POLLUTION,
		VIEW_CIVILRIGHTS }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_CORPORATE_MANAGER,
		{ VIEW_WOMEN,
		VIEW_TAXES,
		VIEW_CORPORATECULTURE,
		VIEW_SWEATSHOPS,
		VIEW_POLLUTION,
		VIEW_CIVILRIGHTS }
	),
	/* Law enforcement block */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_DEATHSQUAD,
		{ VIEW_PRISONS,
		VIEW_DEATHPENALTY,
		VIEW_POLICEBEHAVIOR,
		VIEW_DRUGS,
		VIEW_TORTURE,
		VIEW_GUNCONTROL,
		VIEW_PRISONS }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SWAT,
		{ VIEW_POLICEBEHAVIOR,
		VIEW_DRUGS,
		VIEW_TORTURE,
		VIEW_GUNCONTROL,
		VIEW_PRISONS }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_COP,
		{ VIEW_POLICEBEHAVIOR,
		VIEW_DRUGS,
		VIEW_TORTURE,
		VIEW_GUNCONTROL,
		VIEW_PRISONS }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_GANGUNIT,
		{ VIEW_POLICEBEHAVIOR,
		VIEW_DRUGS,
		VIEW_TORTURE,
		VIEW_GUNCONTROL,
		VIEW_PRISONS }
	),
	/* Prison block */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_EDUCATOR,
		{ VIEW_POLICEBEHAVIOR,
		VIEW_DEATHPENALTY,
		VIEW_DRUGS,
		VIEW_TORTURE,
		VIEW_PRISONS }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_PRISONGUARD,
		{ VIEW_POLICEBEHAVIOR,
		VIEW_DEATHPENALTY,
		VIEW_DRUGS,
		VIEW_TORTURE,
		VIEW_PRISONS }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_PRISONER,
		{ VIEW_POLICEBEHAVIOR,
		VIEW_DEATHPENALTY,
		VIEW_DRUGS,
		VIEW_TORTURE,
		VIEW_PRISONS }
	),
	/* Intelligence block */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SECRET_SERVICE,
		{ VIEW_INTELLIGENCE }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_AGENT,
		{ VIEW_INTELLIGENCE,
		VIEW_TORTURE,
		VIEW_PRISONS,
		VIEW_FREESPEECH }
	),
	/* Military block */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_MERC,
		{ VIEW_GUNCONTROL }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SOLDIER,
		{ VIEW_MILITARY,
		VIEW_TORTURE,
		VIEW_GAY,
		VIEW_WOMEN }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_VETERAN,
		{ VIEW_MILITARY,
		VIEW_TORTURE,
		VIEW_GAY,
		VIEW_WOMEN }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_MILITARYPOLICE,
		{ VIEW_MILITARY,
		VIEW_TORTURE,
		VIEW_GAY,
		VIEW_WOMEN }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_MILITARYOFFICER,
		{ VIEW_MILITARY,
		VIEW_TORTURE,
		VIEW_GAY,
		VIEW_WOMEN }
	),
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_SEAL,
		{ VIEW_MILITARY,
		VIEW_TORTURE,
		VIEW_GAY,
		VIEW_WOMEN }
	),
	/* Sweatshop workers */
	map<CreatureTypes, vector<Views> > ::value_type(CREATURE_WORKER_SWEATSHOP,
		{ VIEW_IMMIGRATION,
		VIEW_SWEATSHOPS }
	),
};

/*********************************
**
**   SLEEPERS INFLUENCING
**     PUBLIC OPINION
**
**********************************/
void sleeper_influence(DeprecatedCreature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM])
{
	int power = (cr.get_attribute(ATTRIBUTE_CHARISMA, true) +
		cr.get_attribute(ATTRIBUTE_HEART, true) +
		cr.get_attribute(ATTRIBUTE_INTELLIGENCE, true) +
		cr.get_skill(SKILL_PERSUASION));
	// Profession specific skills
	if (skill_influence.count(static_cast<CreatureTypes>(cr.type)) >= 1) {
		for (CreatureSkill sk : skill_influence[static_cast<CreatureTypes>(cr.type)]) {
			power += cr.get_skill(sk);
		}
	}
	if (super_sleepers_multiplier.count(static_cast<CreatureTypes>(cr.type)) >= 1) {
		power *= super_sleepers_multiplier[static_cast<CreatureTypes>(cr.type)];
	}
	else {
		power *= 2;
	}
	power = static_cast<int>(power*cr.infiltration);
	if (creature_influences_views.count(static_cast<CreatureTypes>(cr.type)) >= 1) {
		for (Views sk : creature_influences_views[static_cast<CreatureTypes>(cr.type)]) {
			libpower[sk] += power;
		}
	}
	else {
		switch (cr.type)
		{
			/* Radio Personalities and News Anchors subvert Conservative news stations by
			reducing their audience and twisting views on the issues. As their respective
			media establishments become marginalized, so does their influence. */
		case CREATURE_RADIOPERSONALITY:
			change_public_opinion(VIEW_AMRADIO, 1);
			for (int i = 0; i < VIEWNUM - 3; i++)
			{
				libpower[i] += power * (100 - attitude[VIEW_AMRADIO]) / 100;
			}
			break;
		case CREATURE_NEWSANCHOR:
			change_public_opinion(VIEW_CABLENEWS, 1);
			for (int i = 0; i < VIEWNUM - 3; i++)
			{
				libpower[i] += power * (100 - attitude[VIEW_CABLENEWS]) / 100;
			}
			break;
			/* No influence at all block - for people were liberal anyway, or have no way of doing any good */
		case CREATURE_WORKER_FACTORY_CHILD:
		case CREATURE_GENETIC:
		case CREATURE_GUARDDOG:
		case CREATURE_BUM:
		case CREATURE_CRACKHEAD:
		case CREATURE_TANK:
		case CREATURE_HIPPIE: // too liberal to be a proper sleeper
		case CREATURE_WORKER_FACTORY_UNION: // same
		case CREATURE_JUDGE_LIBERAL: // more again
		case CREATURE_MUTANT:
			break;
			/* Miscellaneous block -- includes everyone else */
		case CREATURE_POLITICIAN:
		{
			int a = LCSrandom(VIEWNUM - 5);
			int b = LCSrandom(VIEWNUM - 5);
			while (b == a)b = LCSrandom(VIEWNUM - 5);
			int c = LCSrandom(VIEWNUM - 5);
			while (c == a || c == b)c = LCSrandom(VIEWNUM - 5);
			libpower[a] += power;
			libpower[b] += power;
			libpower[c] += power;
		}
		break;
		case CREATURE_FIREFIGHTER:
			if (lawList[LAW_FREESPEECH] == -2)
			{
				libpower[VIEW_FREESPEECH] += power;
				break;
			}
		default: // Affect a random issue
			pickrandom(libpower) += power;
			break;
		}
	}
}
/*********************************
**
**   SLEEPERS SNOOPING AROUND
**
**********************************/
void creatureLeaksIntel(DeprecatedCreature cr, const string& leak, const string& stashed) {
	eraseAlt();
	mvaddstrAlt(6, 1, string_sleeper, gamelog);
	addstrAlt(cr.getNameAndAlignment().name, gamelog);
	addstrAlt(leak, gamelog);
	gamelog.newline();
	mvaddstrAlt(7, 1, stashed, gamelog);
	gamelog.nextMessage();
}
void sleeper_spy(DeprecatedCreature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM])
{
	int homes = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, cr.location);
	if (LCSrandom(100) > 100 * cr.infiltration)
	{
		cr.juice -= 1;
		if (cr.juice < -2)
		{
			eraseAlt();
			mvaddstrAlt(6, 1, string_sleeper, gamelog);
			addstrAlt(cr.getNameAndAlignment().name, gamelog);
			addstrAlt(hasBeenCaughtSnooping, gamelog);
			gamelog.newline();
			mvaddstrAlt(8, 1, isNowHomeless, gamelog);
			gamelog.nextMessage();
			pressAnyKey();
			removesquadinfo(cr);
			cr.location = homes;
			cr.base = homes;
			cr.drop_weapons_and_clips(NULL);
			cr.set_activity(ACTIVITY_NONE);
			cr.flag &= ~CREATUREFLAG_SLEEPER;
		}
		return;
	}
	// Improves juice, as confidence improves
	if (cr.juice < 100)
	{
		cr.juice += 10;
		if (cr.juice > 100) cr.juice = 100;
	}
	LocationsPool::getInstance().setLocationMappedAndUnhidden(cr.base);
	bool pause = false;
	switch (cr.type)
	{
	case CREATURE_SECRET_SERVICE:
	case CREATURE_AGENT:
	case CREATURE_POLITICIAN:
		// Agents can leak intelligence files to you
		if (!LocationsPool::getInstance().isThereASiegeHere(homes) && canseethings)
		{
			if (LCSrandom(lawList[LAW_PRIVACY] + 3)) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_SECRETDOCUMENTS, homes);
			creatureLeaksIntel(cr, hasLeakedIntelligence, they_are_stashed);
			pause = true;
		}
		break;
	case CREATURE_DEATHSQUAD:
	case CREATURE_SWAT:
	case CREATURE_COP:
	case CREATURE_GANGUNIT:
		// Cops can leak police files to you
		if (!LocationsPool::getInstance().isThereASiegeHere(homes) && canseethings)
		{
			if (LCSrandom(lawList[LAW_POLICEBEHAVIOR] + 3)) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_POLICERECORDS, homes);
			creatureLeaksIntel(cr, hasLeakedPolice, they_are_stashed);
			pause = true;
		}
		break;
	case CREATURE_CORPORATE_MANAGER:
	case CREATURE_CORPORATE_CEO:
		// Can leak corporate files to you
		if (!LocationsPool::getInstance().isThereASiegeHere(homes) && canseethings)
		{
			if (LCSrandom(lawList[LAW_CORPORATE] + 3) && cr.type != CREATURE_CORPORATE_CEO) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_CORPFILES, homes);
			creatureLeaksIntel(cr, hasLeakedCorporate, they_are_stashed);
			pause = true;
		}
		break;
	case CREATURE_EDUCATOR:
	case CREATURE_PRISONGUARD:
		if (!LocationsPool::getInstance().isThereASiegeHere(homes) && canseethings)
		{
			if (LCSrandom(lawList[LAW_POLICEBEHAVIOR] + 3)) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_PRISONFILES, homes);
			creatureLeaksIntel(cr, hasLeakedPrison, they_are_stashed);
			pause = true;
		}
		break;
	case CREATURE_NEWSANCHOR:
		if (!LocationsPool::getInstance().isThereASiegeHere(homes) && canseethings)
		{
			// More likely to leak these documents the more restrictive
			// free speech is -- because the more free the society, the
			// less any particular action the media takes seems scandalous
			if (LCSrandom(lawList[LAW_FREESPEECH] + 3)) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_CABLENEWSFILES, homes);
			creatureLeaksIntel(cr, hasLeakedCableNews, papersAreStashed);
			pause = true;
		}
		break;
	case CREATURE_RADIOPERSONALITY:
		if (!LocationsPool::getInstance().isThereASiegeHere(homes) && canseethings)
		{
			// More likely to leak these documents the more restrictive
			// free speech is -- because the more free the society, the
			// less any particular action the media takes seems scandalous
			if (LCSrandom(lawList[LAW_FREESPEECH] + 3)) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_AMRADIOFILES, homes);
			creatureLeaksIntel(cr, hasLeakedAMRadio, papersAreStashed);
			pause = true;
		}
		break;
	case CREATURE_SCIENTIST_LABTECH:
	case CREATURE_SCIENTIST_EMINENT:
		if (!LocationsPool::getInstance().isThereASiegeHere(homes) && canseethings)
		{
			if (LCSrandom(lawList[LAW_ANIMALRESEARCH] + 3)) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_RESEARCHFILES, homes);
			creatureLeaksIntel(cr, hasLeakedAnimalResearch, they_are_stashed);
			pause = true;
		}
		break;
	case CREATURE_JUDGE_CONSERVATIVE:
		if (!LocationsPool::getInstance().isThereASiegeHere(homes) && canseethings)
		{
			if (LCSrandom(5)) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_JUDGEFILES, homes);
			creatureLeaksIntel(cr, hasLeakedJudiciary, papersAreStashed);
			pause = true;
		}
		break;
	case CREATURE_CCS_ARCHCONSERVATIVE:
		if (!LocationsPool::getInstance().isThereASiegeHere(homes) && canseethings)
		{
			if (ccsexposure >= CCSEXPOSURE_LCSGOTDATA) break;
			LocationsPool::getInstance().stashThisLootHere(tag_LOOT_CCS_BACKERLIST, homes);
			creatureLeaksIntel(cr, hasLeakedCCS, diskIsStashed);
			pause = true;
			ccsexposure = CCSEXPOSURE_LCSGOTDATA;
		}
		break;
	}
	if (pause) getkeyAlt();
}
/*********************************
**
**   SLEEPERS EMBEZZLING FUNDS
**
**********************************/
void sleeper_embezzle(DeprecatedCreature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM])
{
	if (LCSrandom(100) > 100 * cr.infiltration)
	{
		cr.juice -= 1;
		if (cr.juice < -2)
		{
			eraseAlt();
			mvaddstrAlt(6, 1, string_sleeper, gamelog);
			addstrAlt(cr.getNameAndAlignment().name, gamelog);
			addstrAlt(arrestedWhileEmbezzling, gamelog);
			gamelog.nextMessage();
			pressAnyKey();
			cr.criminalize_me(LAWFLAG_COMMERCE);
			removesquadinfo(cr);
			cr.location = find_site_index_in_same_city(SITE_GOVERNMENT_POLICESTATION, cr.location);
			cr.drop_weapons_and_clips(NULL);
			cr.set_activity(ACTIVITY_NONE);
			cr.flag &= ~CREATUREFLAG_SLEEPER;
		}
		return;
	}
	// Improves juice, as confidence improves
	if (cr.juice < 100)
	{
		cr.juice += 10;
		if (cr.juice > 100) cr.juice = 100;
	}
	int income;
	switch (cr.type)
	{
	case CREATURE_CORPORATE_CEO:
		income = static_cast<int>(50000 * cr.infiltration);
		break;
	case CREATURE_SCIENTIST_EMINENT:
	case CREATURE_CORPORATE_MANAGER:
	case CREATURE_BANK_MANAGER:
	case CREATURE_POLITICIAN:
		income = static_cast<int>(5000 * cr.infiltration);
		break;
	default:
		income = static_cast<int>(500 * cr.infiltration);
		break;
	}
	ledger.add_funds(income, INCOME_EMBEZZLEMENT);
}
struct stringAndInt
{
	string str;
	int integer;
	stringAndInt(const string& str_, int integer_) : str(str_), integer(integer_) {}
	stringAndInt(int integer_, const string& str_) : str(str_), integer(integer_) {}
};
string randomString(vector<stringAndInt>);
string randomString(vector<stringAndInt> outputList) {
	for (stringAndInt s : outputList) {
		if (!LCSrandom(s.integer)) {
			return s.str;
		}
	}
	return outputList[len(outputList) - 1].str;
}
void stashRandomStolenItem(DeprecatedCreature &cr, int &numberofxmlfails) {
	string item;
	int shelter = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, cr.location);


	bool loot = false;
	bool armor = false;
	bool weapon = false;
	switch (LocationsPool::getInstance().getLocationType(cr.location)) //Temporary (transitionally) solution until sites are done. -XML
	{
	case SITE_RESIDENTIAL_TENEMENT:
		item = randomString({ stringAndInt(3, tag_LOOT_KIDART),
			stringAndInt(2, tag_LOOT_DIRTYSOCK),
			stringAndInt(1, tag_LOOT_FAMILYPHOTO) });
		loot = true;
		break;
	case SITE_RESIDENTIAL_APARTMENT:
		item = randomString({ stringAndInt(5, tag_LOOT_CELLPHONE),
			stringAndInt(4, tag_LOOT_SILVERWARE),
			stringAndInt(3, tag_LOOT_TRINKET),
			stringAndInt(2, tag_LOOT_CHEAPJEWELERY),
			stringAndInt(1,  tag_LOOT_COMPUTER) });
		loot = true;
		break;
	case SITE_RESIDENTIAL_APARTMENT_UPSCALE:
		item = randomString({ stringAndInt(10, tag_LOOT_EXPENSIVEJEWELERY),
			stringAndInt(5, tag_LOOT_CELLPHONE),
			stringAndInt(4, tag_LOOT_SILVERWARE),
			stringAndInt(3, tag_LOOT_PDA),
			stringAndInt(2, tag_LOOT_CHEAPJEWELERY),
			stringAndInt(1,  tag_LOOT_COMPUTER) });
		loot = true;
		break;
	case SITE_LABORATORY_COSMETICS:
	case SITE_INDUSTRY_NUCLEAR:
	case SITE_LABORATORY_GENETIC:
		item = randomString({ stringAndInt(5, tag_LOOT_RESEARCHFILES),
			stringAndInt(2, tag_LOOT_LABEQUIPMENT),
			stringAndInt(2, tag_LOOT_COMPUTER),
			stringAndInt(5, tag_LOOT_PDA),
			stringAndInt(5, tag_LOOT_CHEMICAL),
			stringAndInt(1,  tag_LOOT_COMPUTER) });
		loot = true;
		break;
	case SITE_GOVERNMENT_COURTHOUSE:
		item = randomString({ stringAndInt(5, tag_LOOT_JUDGEFILES),
			stringAndInt(3, tag_LOOT_CELLPHONE),
			stringAndInt(2, tag_LOOT_PDA),
			stringAndInt(1,  tag_LOOT_COMPUTER) });
		loot = true;
		break;
	case SITE_GOVERNMENT_PRISON:
		item = randomString({ stringAndInt(1, tag_WEAPON_SHANK) });
		weapon = true;
		break;
	case SITE_BUSINESS_BANK:
	case SITE_GOVERNMENT_FIRESTATION:
		item = randomString({ stringAndInt(2, tag_LOOT_TRINKET),
			stringAndInt(1,  tag_LOOT_COMPUTER) });
		loot = true;
		break;
	case SITE_INDUSTRY_SWEATSHOP:
		item = randomString({ stringAndInt(1, tag_LOOT_FINECLOTH) });
		loot = true;
		break;
	case SITE_INDUSTRY_POLLUTER:
		item = randomString({ stringAndInt(1, tag_LOOT_CHEMICAL) });
		loot = true;
		break;
	case SITE_CORPORATE_HEADQUARTERS:
		item = randomString({ stringAndInt(5, tag_LOOT_CORPFILES),
			stringAndInt(3, tag_LOOT_CELLPHONE),
			stringAndInt(2, tag_LOOT_PDA),
			stringAndInt(1,  tag_LOOT_COMPUTER) });
		loot = true;
		break;
	case SITE_CORPORATE_HOUSE:
		item = randomString({ stringAndInt(8, tag_LOOT_TRINKET),
			stringAndInt(7, tag_LOOT_WATCH),
			stringAndInt(6, tag_LOOT_PDA),
			stringAndInt(5, tag_LOOT_CELLPHONE),
			stringAndInt(4, tag_LOOT_SILVERWARE),
			stringAndInt(3, tag_LOOT_CHEAPJEWELERY),
			stringAndInt(2, tag_LOOT_FAMILYPHOTO),
			stringAndInt(1,  tag_LOOT_COMPUTER) });
		loot = true;
		break;
	case SITE_MEDIA_AMRADIO:
		item = randomString({ stringAndInt(5, tag_LOOT_AMRADIOFILES),
			stringAndInt(4, tag_LOOT_MICROPHONE),
			stringAndInt(3, tag_LOOT_PDA),
			stringAndInt(2, tag_LOOT_CELLPHONE),
			stringAndInt(1,  tag_LOOT_COMPUTER) });
		loot = true;
		break;
	case SITE_MEDIA_CABLENEWS:
		item = randomString({ stringAndInt(5, tag_LOOT_CABLENEWSFILES),
			stringAndInt(4, tag_LOOT_MICROPHONE),
			stringAndInt(3, tag_LOOT_PDA),
			stringAndInt(2, tag_LOOT_CELLPHONE),
			stringAndInt(1,  tag_LOOT_COMPUTER) });
		loot = true;
		break;
	case SITE_GOVERNMENT_POLICESTATION:
		if (!LCSrandom(3))
		{
			item = randomString({ stringAndInt(4, tag_WEAPON_SMG_MP5),
				stringAndInt(3, tag_WEAPON_SEMIPISTOL_45),
				stringAndInt(2, tag_WEAPON_SHOTGUN_PUMP),
				stringAndInt(1,  tag_WEAPON_SEMIRIFLE_AR15) });
			weapon = true;
		}
		else if (!LCSrandom(2))
		{
			if (lawList[LAW_POLICEBEHAVIOR] == -2 && lawList[LAW_DEATHPENALTY] == -2 && !LCSrandom(4))item = tag_ARMOR_DEATHSQUADUNIFORM;
			else item = randomString({ stringAndInt(3, tag_ARMOR_POLICEUNIFORM),
				stringAndInt(2, tag_ARMOR_SWATARMOR),
				stringAndInt(1,  tag_ARMOR_POLICEARMOR) });
			armor = true;
		}
		else
		{
			item = randomString({ stringAndInt(5, tag_LOOT_POLICERECORDS),
				stringAndInt(3, tag_LOOT_CELLPHONE),
				stringAndInt(2, tag_LOOT_PDA),
				stringAndInt(1,  tag_LOOT_COMPUTER) });
			loot = true;
		}
		break;
	case SITE_GOVERNMENT_ARMYBASE:
		if (!LCSrandom(3))
		{
			item = randomString({
				stringAndInt(3,  tag_WEAPON_CARBINE_M4),
				stringAndInt(1, tag_WEAPON_AUTORIFLE_M16) });
			weapon = true;
		}
		else if (!LCSrandom(2))
		{
			item = randomString({ stringAndInt(1, tag_ARMOR_ARMYARMOR) });
			armor = true;
		}
		else
		{
			item = randomString({ stringAndInt(5, tag_LOOT_SECRETDOCUMENTS),
				stringAndInt(3, tag_LOOT_CELLPHONE),
				stringAndInt(2, tag_LOOT_CHEMICAL),
				stringAndInt(1,  tag_LOOT_SILVERWARE) });
			loot = true;
		}
		break;
	case SITE_GOVERNMENT_WHITE_HOUSE:
	case SITE_GOVERNMENT_INTELLIGENCEHQ:
		if (!LCSrandom(3))
		{
			item = randomString({ stringAndInt(4, tag_WEAPON_SMG_MP5),
				stringAndInt(3, tag_WEAPON_AUTORIFLE_M16),
				stringAndInt(2, tag_WEAPON_SHOTGUN_PUMP),
				stringAndInt(1,  tag_WEAPON_CARBINE_M4) });
			weapon = true;
		}
		else if (!LCSrandom(2))
		{
			item = randomString({ stringAndInt(1, tag_ARMOR_BLACKSUIT) });
			armor = true;
		}
		else
		{
			item = randomString({ stringAndInt(5, tag_LOOT_SECRETDOCUMENTS),
				stringAndInt(3, tag_LOOT_CELLPHONE),
				stringAndInt(2, tag_LOOT_PDA),
				stringAndInt(1,  tag_LOOT_COMPUTER) });
			loot = true;
		}
		break;
	default:
		// xmlfail
		item = "";
		break;
	}
	if (loot) {
		int itemindex = getloottype(item);
		if (itemindex > -1) { LocationsPool::getInstance().stashThisLootHere(item, shelter); }
		else { numberofxmlfails++; }
	}
	else if (armor) {
		int itemindex = getarmortype(item);
		if (itemindex > -1) {
			LocationsPool::getInstance().stashThisArmorHere(itemindex, shelter);
		}
		else { numberofxmlfails++; }
	}
	else if (weapon) {
		int itemindex = getweapontype(item);
		if (itemindex > -1) { LocationsPool::getInstance().stashThisWeaponHere(itemindex, shelter); }
		else { numberofxmlfails++; }
	}
	else {
		numberofxmlfails++;
	}
}
/*********************************
**
**   SLEEPERS STEALING THINGS
**
**********************************/
void printArrestedWhileStealing(string crname) {
	eraseAlt();
	mvaddstrAlt(6, 1, string_sleeper, gamelog);
	addstrAlt(crname, gamelog);
	addstrAlt(arrestedWhileStealing, gamelog);
	gamelog.nextMessage();
	pressAnyKey();
}
void sleeper_steal(DeprecatedCreature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM])
{
	if (LCSrandom(100) > 100 * cr.infiltration)
	{
		cr.juice -= 1;
		if (cr.juice < -2)
		{
			printArrestedWhileStealing(cr.getNameAndAlignment().name);

			cr.criminalize_me(LAWFLAG_THEFT);
			removesquadinfo(cr);
			cr.location = find_site_index_in_same_city(SITE_GOVERNMENT_POLICESTATION, cr.location);
			cr.drop_weapons_and_clips(NULL);
			cr.set_activity(ACTIVITY_NONE);
			cr.flag &= ~CREATUREFLAG_SLEEPER;
		}
		return;
	}
	// Improves juice, as confidence improves
	if (cr.juice < 100)
	{
		cr.juice += 10;
		if (cr.juice > 100)cr.juice = 100;
	}
	cr.infiltration -= LCSrandom(10)*0.01f - 0.02f; //No effectiveness drop before? -Niel
													//Item *item;

	int numberofxmlfails = 0; // Tell them how many fails
	for (int number_of_items = LCSrandom(10) + 1; number_of_items > 0; number_of_items--)
	{
		stashRandomStolenItem(cr, numberofxmlfails);
	}
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(6, 1, string_sleeper, gamelog);
	addstrAlt(cr.getNameAndAlignment().name, gamelog);
	addstrAlt(droppedOffPackage, gamelog);
	gamelog.nextMessage();
	if (numberofxmlfails > 0) {
		set_color_easy(RED_ON_BLUE_BRIGHT);
		mvaddstrAlt(8, 1, itemNotFound, xmllog);
		mvaddstrAlt(9, 1, tostring(numberofxmlfails), xmllog);
		addstrAlt(lostStolenItem, xmllog);
		set_color_easy(RED_ON_GREEN_BRIGHT);
		mvaddstrAlt(11, 1, contactModAuthor, xmllog);
		xmllog.nextMessage();
	}
	pressAnyKey();
}
/*********************************
**
**   SLEEPERS CREATING SCANDALS
**
**********************************/
void sleeper_scandal(DeprecatedCreature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM])
{
	// Add content here!
	return;
}
/*********************************
**
**   SLEEPERS RECRUITING
**
**********************************/
vector<NameAndAlignment> getEncounterNameAndAlignment();
void incrementStatRecruits();
int getEncounterWorkLocation(const int e);
void sleeperSuccessfullyRecruits(const string name, const int id, const float infiltration, const int e);
void sleeper_recruit(DeprecatedCreature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM])
{

	vector<NameAndAlignment> encounter = getEncounterNameAndAlignment();

	if (subordinatesleft(cr))
	{
		prepareencounter(LocationsPool::getInstance().getLocationType(cr.worklocation), 0);
		for (int e = 0; e < ENCMAX; e++)
		{
			if (encounter[e].exists == false)
				break;
			if (getEncounterWorkLocation(e) == cr.worklocation || !LCSrandom(5))
			{
				if (encounter[e].align != 1 && LCSrandom(5))continue;
				sleeperSuccessfullyRecruits(cr.getNameAndAlignment().name, cr.id, cr.infiltration, e);
				gamelog.nextMessage();
				pressAnyKey();
				if (!subordinatesleft(cr))cr.set_activity(ACTIVITY_NONE);
				incrementStatRecruits();
				break;
			}
		}
	}
	return;
}
/**********************************************************************
** *JDS*
** ----- The sleeper system has been completely reworked.
** - Sleepers no longer directly influence the issues. They now affect
** the broad CONST_sleeper_update044 stats across many issues, which are used
** as a kind of monthly liberal roll akin to AM Radio and Cable News.
** - Each sleeper can affect one or more issue, throwing their power
** into the CONST_sleeper_update045 on that issue.
** - After all of the sleepers have contributed to the liberal power
** stats, a roll is made on each issue to see whether the liberals
** make background progress on those issues.
** - Several sleepers have special abilities. Lawyers and Judges, as
** always, can aid your people in the legal system. Police officers,
** corporate managers, CEOs, and agents can all now leak secret
** documents of the appropriate types, and they will make a check
** each month. This will only happen if the homeless shelter is not
** under siege, and CONST_sleeper_update046 is enabled (eg, you're not in prison
** or disbanded or some other situation where your sleeper can't get
** in touch with anyone in your squad).
** - News Anchors and Radio Personalities remain the two most powerful
** sleepers.
**********************************************************************/
void sleepereffect(DeprecatedCreature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM])
{
	if (disbanding)cr.set_activity(ACTIVITY_SLEEPER_LIBERAL);
	int infiltrate = 1;
	switch (cr.activity_type())
	{
	case ACTIVITY_SLEEPER_LIBERAL:
		sleeper_influence(cr, clearformess, canseethings, libpower);
		cr.infiltration -= 0.02f;
		break;
	case ACTIVITY_SLEEPER_EMBEZZLE:
		sleeper_embezzle(cr, clearformess, canseethings, libpower);
		break;
	case ACTIVITY_SLEEPER_STEAL:
		sleeper_steal(cr, clearformess, canseethings, libpower);
		infiltrate = 0;
		break;
	case ACTIVITY_SLEEPER_RECRUIT:
		sleeper_recruit(cr, clearformess, canseethings, libpower);
		break;
	case ACTIVITY_SLEEPER_SPY:
		sleeper_spy(cr, clearformess, canseethings, libpower);
		break;
	case ACTIVITY_SLEEPER_SCANDAL:
		sleeper_scandal(cr, clearformess, canseethings, libpower);
		break;
	case ACTIVITY_NONE:
	case ACTIVITY_SLEEPER_JOINLCS:
	default:
		break;
	}
	if (infiltrate) cr.infiltration += LCSrandom(8)*0.01f - 0.02f;
	if (cr.infiltration >= 1)
		cr.infiltration = 1;
	if (cr.infiltration <= 0)
		cr.infiltration = 0;
}
