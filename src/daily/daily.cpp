#include "../includes.h"
const string CONST_daily024 = " regains contact with the LCS.";
const string CONST_daily023 = "CREATURE_POLITICALACTIVIST";
const string CONST_daily022 = "CREATURE_TEENAGER";
const string CONST_daily021 = ". The Liberal will be missed.";
const string CONST_daily020 = " has passed away at the age of ";
const string CONST_daily019 = " surfs the Net for recent opinion polls.";
const string CONST_daily018 = "Why is the squad here?   (S)afe House, to cause (T)rouble, or (B)oth?";
const string CONST_daily017 = " has arrived at ";
const string CONST_daily016 = " looks around ";
const string CONST_daily013 = " arrives in ";
const string CONST_daily012 = "%s spent $%d on tickets to go to %s.";
const string CONST_daily011 = "%s couldn't afford tickets to go to %s.";
const string CONST_daily010 = "travel location";
const string CONST_daily009 = " didn't have a car to get to ";
const string CONST_daily008 = " couldn't use the ";
const string CONST_daily007 = " was too hot to risk.";
const string CONST_daily006 = " decided ";
const string CONST_daily005 = " instead of ";
const string CONST_daily004 = " acted with ";
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

const string blankString = "";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../creature/creature.h"
////

//#include "../creature/deprecatedCreatureA.h"

#include "../creature/deprecatedCreatureC.h"

//#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
//#include "../news/news.h"
void majornewspaper(char canseethings);
//#include "../sitemode/sitemode.h"
void mode_site(const short loc);
#include "../log/log.h"
// for commondisplay.h
#include "../common/commondisplay.h"
// for makedelimeter
#include "../common/getnames.h"
// for std::string getactivity(ActivityST)
#include "../common/translateid.h"
// for  int getsquad(int)
#include "../common/commonactions.h"
#include "../common/commonactionsCreature.h"
/* tells how many total members a squad has (including dead members) */
// for void basesquad(squadst *,long)
#include "../daily/daily.h"
/* squad members with no chain of command lose contact */
void dispersalcheck(const char clearformess);

#include "../daily/activities.h"
//for void repairarmor(Creature &cr,char &clearformess); and stealcar
#include "../daily/siege.h"        
//for sigeturn and siegecheck
//#include "../daily/recruit.h"
char completerecruitmeeting(Deprecatedrecruitst &d, const int p);
//#include "../daily/date.h"
char completevacation(Deprecateddatest &d, int p);
char completedate(Deprecateddatest &d, int p);
#include "../combat/chaseCreature.h"
//for int driveskill(Creature &cr,Vehicle &v);
//hmm --Schmel924
#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include "../title/titlescreen.h"
#include "../locations/locationsPool.h"
#include "../common/creaturePool.h"




/*
shopsnstuff.cpp
*/

const string CONST_shopsnstuff008 = "oubliette.xml";
const string CONST_shopsnstuff007 = "deptstore.xml";
const string CONST_shopsnstuff006 = "P - Repaint car, replace plates and tags ($500)";
const string CONST_shopsnstuff005 = "pawnshop.xml";
const string CONST_shopsnstuff004 = "armsdealer.xml";

#include "../sitemode/shop.h"
#include "../common/musicClass.h"
extern string closeParenthesis;
extern string undefined;
extern string check_status_of_squad_liberal;
extern string show_squad_liberal_status;
extern string enter_done;
extern string chooseALiberalTo;
extern string spaceParanthesisDollar;
string toSpend;
string chooseAColor;
string theseColorsAreCon;
string thisColor;
string notEnoughMoney;
string chooseVehicle;
string thisVehicle;
string weDontNeedCar;
string enterLeave;
string b_chooseBuyer;
string s_sellCar;
string s_sellThe;
string g_getCar;
string f_fixWounds;
/* active squad visits the hospital */
/* active squad visits the hospital */

/* common - moves all squad members and their cars to a new location */
void locatesquad(Deprecatedsquadst *st, long loc);
/* common - assigns a new base to all members of a squad */
void basesquad(Deprecatedsquadst *st, long loc);

void locateActiveSquad(const int loc);

void hospital(int loc)
{
	extern Deprecatedsquadst *activesquad;
	extern MusicClass music;
	extern short party_status;
	music.play(MUSIC_SHOPPING);

	locateActiveSquad(loc);

	int partysize = activesquadSize();
	while (true)
	{
		eraseAlt();
		locheader();
		DeprecatedCreature::printparty();
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(10, 1, f_fixWounds);
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(12, 1, enterLeave);
		if (partysize > 0 && (party_status == -1 || partysize > 1)) set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(13, 1, check_status_of_squad_liberal);
		if (party_status != -1) set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(14, 1, show_squad_liberal_status);
		int c = getkeyAlt();
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) break;
		if (c == '0') party_status = -1;
		if (c >= '1'&&c <= '6'&&activesquad != NULL)
			if (activesquad->squad[c - '1'] != NULL)
			{
				if (party_status == c - '1')fullstatus(party_status);
				else party_status = c - '1';
			}
		if (c == 'f')
		{
			for (int p = 5; p >= 0; p--)
			{
				if (activesquad->squad[p] == NULL)continue;
				activesquad->squad[p]->hospitalize(loc);
			}
			break;
		}
	}
}
/* active squad visits the arms dealer */
void armsdealer(int loc)
{
	extern Deprecatedsquadst *activesquad;
	extern MusicClass music;
	extern char artdir[MAX_PATH_SIZE];
	music.play(MUSIC_SHOPPING);
	locatesquad(activesquad, loc);
	CMarkup xml; // -XML
	xml.Load(string(artdir) + CONST_shopsnstuff004);
	Shop armsdealer(xml.GetDoc());
	armsdealer.enter(*activesquad);
}
/* active squad visits the pawn shop */
void pawnshop(int loc)
{
	extern Deprecatedsquadst *activesquad;
	extern MusicClass music;
	extern char artdir[MAX_PATH_SIZE];
	music.play(MUSIC_SHOPPING);
	locatesquad(activesquad, loc);
	CMarkup xml; // -XML
	xml.Load(string(artdir) + CONST_shopsnstuff005);
	Shop pawnshop(xml.GetDoc());
	pawnshop.enter(*activesquad);
}
/* choose buyer */
void choose_buyer(short &buyer)
{
	extern short party_status;
	party_status = -1;
	int partysize = activesquadSize();
	if (partysize <= 1) return;
	while (true)
	{
		DeprecatedCreature::printparty();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8, 20, chooseALiberalTo + toSpend);
		int c = getkeyAlt();
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) return;
		if (c >= '1'&&c <= partysize + '1' - 1)
		{
			buyer = c - '1';
			return;
		}
	}
}
int lenVehicleType();
string vehicleTypelongname(const int p);
Vehicle* getVehicleFromTypeYear(const int carchoice, const int colorchoice, const int year);
int getVehicleTypePrice(const int carchoice);
int getVehicleTypeSleeperPrice(const int carchoice);
vector<string> getVehicleTypeColor(const int carchoice);
bool vehicletypeavailableatshop(const int i);
DeprecatedCreature* findSleeperCarSalesman(int loc);
/* active squad visits the car dealership */
void dealership(int loc)
{
	extern string spaceParanthesisDollar;
	extern Deprecatedsquadst *activesquad;
	extern MusicClass music;
	extern int year;
	extern short party_status;
	extern class Ledger ledger;
	extern vector<Vehicle *> vehicle;
	music.play(MUSIC_SHOPPING);
	short buyer = 0;
	locateActiveSquad(loc);
	int partysize = activesquadSize();
	while (true)
	{
		eraseAlt();
		locheader();
		DeprecatedCreature::printparty();
		DeprecatedCreature *sleepercarsalesman = findSleeperCarSalesman(loc);
		Vehicle* car_to_sell = 0;
		int price = 0;
		for (int v = len(vehicle) - 1; v >= 0; v--)
			if (vehicle[v]->id() == activesquad->squad[buyer]->carid)
				car_to_sell = vehicle[v];
		if (!car_to_sell) set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(10, 1, g_getCar);
		if (car_to_sell)
		{
			price = static_cast<int>(0.8*car_to_sell->price());
			if (car_to_sell->get_heat())
				price /= 10;
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(11, 1, s_sellThe + car_to_sell->fullname() + spaceParanthesisDollar + tostring(price) + closeParenthesis);
		}
		else
		{
			set_color_easy(BLACK_ON_BLACK_BRIGHT);
			mvaddstrAlt(11, 1, s_sellCar);
		}
		if (partysize >= 2)set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(16, 1, b_chooseBuyer);
		set_color_easy(WHITE_ON_BLACK);
		mvaddstrAlt(16, 40, enterLeave);
		if (party_status != -1)set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(15, 1, show_squad_liberal_status);
		if (partysize > 0 && (party_status == -1 || partysize > 1))set_color_easy(WHITE_ON_BLACK);
		else set_color_easy(BLACK_ON_BLACK_BRIGHT);
		mvaddstrAlt(15, 40, check_status_of_squad_liberal);
		int c = getkeyAlt();
		// Leave
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR)break;
		//Sell the car
		if (c == 's' && car_to_sell)
		{
			ledger.add_funds(price, INCOME_CARS);
			for (int v = len(vehicle) - 1; v >= 0; v--)
				if (vehicle[v] == car_to_sell)
				{
					delete_and_remove(vehicle, v);
					break;
				}
		}
		// Get a car
		if (c == 'g' && !car_to_sell)
		{
			int carchoice;
			vector<int> availablevehicle;
			vector<string> vehicleoption;
			for (int i = 0; i < lenVehicleType(); i++)
				if (vehicletypeavailableatshop(i))
				{
					availablevehicle.push_back(i);
					vehicleoption.push_back(vehicleTypelongname(i) + spaceParanthesisDollar +
						tostring(sleepercarsalesman ? getVehicleTypeSleeperPrice(i) : getVehicleTypePrice(i)) + closeParenthesis);
				}
			while (true)
			{
				carchoice = choiceprompt(chooseVehicle, blankString, vehicleoption, thisVehicle,
					true, weDontNeedCar);
				if (carchoice != -1 && (sleepercarsalesman ? getVehicleTypeSleeperPrice(availablevehicle[carchoice]) :
					getVehicleTypePrice(availablevehicle[carchoice])) > ledger.get_funds())
				{
					set_color_easy(RED_ON_BLACK);
					mvaddstrAlt(1, 1, notEnoughMoney);
					pressAnyKey();
				}
				else break;
			}
			if (carchoice == -1) continue;
			//Picked a car, pick color
			int colorchoice;
			//if(len(vehicletype[availablevehicle[choice]]->color())>1) //Allow to back out if you don't like single colour? -XML
			//{
			colorchoice = choiceprompt(chooseAColor, blankString, getVehicleTypeColor(availablevehicle[carchoice]),
				thisColor, true, theseColorsAreCon);
			//}
			//else
			//   colorchoice = 0;
			if (colorchoice == -1) continue;
			Vehicle *v = getVehicleFromTypeYear(availablevehicle[carchoice], colorchoice, year);
			activesquad->squad[buyer]->pref_carid = v->id();
			vehicle.push_back(v);
			ledger.subtract_funds((sleepercarsalesman ? v->sleeperprice() : v->price()), EXPENSE_CARS);
		}
		// Reduce heat
		/*if(c=='p' && car_to_sell && car_to_sell->heat>1 && ledger.get_funds()>=500)
		{
		funds-=500;
		moneylost_goods+=500;
		car_to_sell->heat=1;
		}*/
		if (c == 'b')choose_buyer(buyer);
		if (c == '0')party_status = -1;
		if (c >= '1'&&c <= '6'&&activesquad != NULL)
			if (activesquad->squad[c - '1'] != NULL)
			{
				if (party_status == c - '1')fullstatus(party_status);
				else party_status = c - '1';
			}
	}
}
/* active squad visits the department store */
void deptstore(int loc)
{
	extern Deprecatedsquadst *activesquad;
	extern MusicClass music;
	extern char artdir[MAX_PATH_SIZE];
	music.play(MUSIC_SHOPPING);
	locatesquad(activesquad, loc);
	CMarkup xml; // -XML
	xml.Load(string(artdir) + CONST_shopsnstuff007);
	Shop deptstore(xml.GetDoc());
	deptstore.enter(*activesquad);
}
/* active squad visits the oubliette */
void halloweenstore(int loc)
{
	extern Deprecatedsquadst *activesquad;
	extern MusicClass music;
	extern char artdir[MAX_PATH_SIZE];
	music.play(MUSIC_SHOPPING);
	locatesquad(activesquad, loc);
	CMarkup xml;
	xml.Load(string(artdir) + CONST_shopsnstuff008);
	Shop oubliette(xml.GetDoc());
	oubliette.enter(*activesquad);
}


void determineMedicalSupportAtEachLocation(bool clearformess);

void ageThings(const char clearformess) {
	const string CONST_daily024 = " regains contact with the LCS.";
	const string CONST_daily023 = "CREATURE_POLITICALACTIVIST";
	const string CONST_daily022 = "CREATURE_TEENAGER";
	const string CONST_daily021 = ". The Liberal will be missed.";
	const string CONST_daily020 = " has passed away at the age of ";
	extern int day;
	extern int month;
	extern Log gamelog;
	extern vector<DeprecatedCreature *> pool;
	extern vector<Deprecatednewsstoryst *> newsstory;
	day++;
	int pday = day, pmonth = month; // Find out if it's next month already.
	if (pday > monthday()) // Day counter has increased but end-of-month has not yet been
		pday = 1, pmonth = (pmonth % 12) + 1; // checked so it has to be accounted for here.
	for (int p = 0; p < len(pool); p++)
	{
		pool[p]->stop_being_stunned(); // For lack of a better place, make stunning expire here
							  // Increment number of days since joined/kidnapped
		pool[p]->joindays++;
		// Increment number of days been dead if dead
		if (!pool[p]->getNameAndAlignment().alive)
		{
			pool[p]->deathdays++;
			continue;
		}
		// animals, tanks don't have age effects at the moment
		//TODO: Start aging effects for animals at age 12, take into account if they are genetic monsters or not.
		if (!pool[p]->animalgloss)
		{
			if (pool[p]->getCreatureBio().age > 60)
			{
				int decrement = 0;
				while (pool[p]->getCreatureBio().age - decrement > 60)
				{
					if (LCSrandom(365 * 10) == 0)
					{
						pool[p]->adjust_attribute(ATTRIBUTE_HEALTH, -1);
						if (pool[p]->get_attribute(ATTRIBUTE_HEALTH, false) <= 0 &&
							pool[p]->get_attribute(ATTRIBUTE_HEALTH, true) <= 1)
						{
							pool[p]->die();
							if (clearformess) eraseAlt();
							else makedelimiter();
							set_color_easy(WHITE_ON_BLACK_BRIGHT);
							mvaddstrAlt(8, 1, pool[p]->getNameAndAlignment().name, gamelog);
							addstrAlt(CONST_daily020, gamelog);
							addstrAlt(pool[p]->getCreatureBio().age, gamelog);
							addstrAlt(CONST_daily021, gamelog);
							gamelog.nextMessage();
							pressAnyKey();
							break;
						}
					}
					decrement += 10;
				}
				if (!pool[p]->getNameAndAlignment().alive)continue;
			}
			if (pmonth == pool[p]->getCreatureBio().birthday_month&&
				pday == pool[p]->getCreatureBio().birthday_day)
			{
				pool[p]->age_up();
				switch (pool[p]->getCreatureBio().age)
				{
				case 13:
					pool[p]->type = CREATURE_TEENAGER; // aww, all grown up
					pool[p]->type_idname = CONST_daily022;
					break;
				case 18:
					pool[p]->type = CREATURE_POLITICALACTIVIST; // ok seriously this time
					pool[p]->type_idname = CONST_daily023;
					break;
				}
			}
		}
		// Heal over time
		if (pool[p]->blood < 100) pool[p]->blood++;
		// Updating for in hiding
		if (pool[p]->hiding > 0)
		{
			if ((--pool[p]->hiding) == 0)
			{
				if (LocationsPool::getInstance().isThereASiegeHere(pool[p]->base))
					pool[p]->hiding = 1;
				else
				{
					pool[p]->location = pool[p]->base;
					if (clearformess) eraseAlt();
					else makedelimiter();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8, 1, pool[p]->getNameAndAlignment().name, gamelog);
					addstrAlt(CONST_daily024, gamelog);
					gamelog.nextMessage();
					pressAnyKey();
				}
			}
		}
		// Check if news reports kidnapping
		if ((pool[p]->flag&CREATUREFLAG_MISSING) &&
			!(pool[p]->flag&CREATUREFLAG_KIDNAPPED))
		{
			if (LCSrandom(14) + 5 < pool[p]->joindays)
			{
				pool[p]->flag |= CREATUREFLAG_KIDNAPPED;
				Deprecatednewsstoryst *ns = new Deprecatednewsstoryst;
				ns->type = NEWSSTORY_KIDNAPREPORT;
				ns->loc = pool[p]->location;
				ns->cr = pool[p];
				newsstory.push_back(ns);
			}
		}
		// Gain skill levels for anything where you have enough experience
		pool[p]->skill_up();
	}
}
void meetWithPotentialRecruits(char &clearformess) {
	extern char disbanding;
	extern vector<Deprecatedrecruitst *> recruit;
	extern vector<DeprecatedCreature *> pool;
	for (int i = len(pool) - 1; i >= 0; i--)
		pool[i]->meetings = 0;
	if (!disbanding) for (int r = len(recruit) - 1; r >= 0; r--)
	{
		int p = getpoolcreature(recruit[r]->recruiter_id);
		// Stand up recruits if 1) recruiter does not exist, 2) recruiter was not able to return to a safehouse today
		// or 3) recruiter is dead.
		if (p != -1 && ((pool[p]->location != -1 && LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE,pool[p]->location) != RENTING_NOCONTROL && pool[p]->getNameAndAlignment().alive&&
			LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONCITY,pool[p]->location) == LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONCITY,recruit[r]->recruit->location))))
		{
			//MEET WITH RECRUIT
			//TERMINATE NULL RECRUIT MEETINGS
			if (LocationsPool::getInstance().isThereASiegeHere(pool[p]->location))
			{
				delete_and_remove(recruit, r);
				continue;
			}
			//DO MEETING
			else {
				clearformess = 1;
				if (completerecruitmeeting(*recruit[r], p))
				{
					delete_and_remove(recruit, r);
					continue;
				}
			}
		}
		else
		{
			delete_and_remove(recruit, r);
			continue;
		}
	}
}
// Determines the number of recruitment meetings a creature has scheduled
int DeprecatedCreature::scheduledmeetings() const
{
	extern vector<Deprecatedrecruitst *> recruit;
	int meetings = 0;
	for (int p = len(recruit) - 1; p >= 0; p--)
		// If meeting is with this creature
		if (recruit[p]->recruiter_id == id) meetings++;
	return meetings;
}
void doRent(const char clearformess) {
	extern char disbanding;
	extern int day;
	extern class Ledger ledger;
	if (day == 3 && !disbanding)
		for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
			if (LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE,l) > 0 &&
				!LocationsPool::getInstance().isNewRental(l))
			{  // if rent >= 1000000 this means you get should kicked out automatically
				if (ledger.get_funds() >= LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE,l) && LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE,l) < 1000000)
					ledger.subtract_funds(LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE,l), EXPENSE_RENT);
				//EVICTED!!!!!!!!!
				else
				{
					if (clearformess) eraseAlt();
					else makedelimiter();
					LocationsPool::getInstance().evictLCSFrom(l);
				}
			}
}


void DeprecatedCreature::activitiesForIndividuals(char &clearformess) {
	const string CONST_daily019 = " surfs the Net for recent opinion polls.";
	extern Log gamelog;
	extern vector<DeprecatedCreature *> pool;
	for (int p = 0; p < len(pool); p++)
	{
		pool[p]->income = 0;
		if (!pool[p]->getNameAndAlignment().alive) continue;
		if (pool[p]->clinic) continue;
		if (pool[p]->dating) continue;
		if (pool[p]->hiding) continue;
		if (pool[p]->location == -1)
		{
			//Had a crash bug on the siege check. Location was -1, probably set by 'partyrescue' and not reset during to messy violent chase.
			//This may prevent crashes.
			pool[p]->location = pool[p]->base;
		}
		//CLEAR ACTIONS FOR PEOPLE UNDER SIEGE
		if (LocationsPool::getInstance().isThereASiegeHere(pool[p]->location))
		{
			switch (pool[p]->activity_type())
			{
			case ACTIVITY_HOSTAGETENDING:
			case ACTIVITY_TEACH_POLITICS:
			case ACTIVITY_TEACH_FIGHTING:
			case ACTIVITY_TEACH_COVERT:
			case ACTIVITY_HEAL:
			case ACTIVITY_REPAIR_ARMOR:
				break;
			default:
				pool[p]->set_activity(ACTIVITY_NONE);
				break;
			}
		}
		switch (pool[p]->activity_type())
		{
		case ACTIVITY_REPAIR_ARMOR:
			pool[p]->repairarmor(clearformess);
			break;
		case ACTIVITY_MAKE_ARMOR:
			pool[p]->makearmor(clearformess);
			// Uncomment this to have people stop making armor after the first day
			//pool[p]->activity.type=ACTIVITY_NONE;
			break;
		case ACTIVITY_WHEELCHAIR:
			pool[p]->getwheelchair(clearformess);
			if (pool[p]->flag & CREATUREFLAG_WHEELCHAIR)pool[p]->set_activity(ACTIVITY_NONE);
			break;
		case ACTIVITY_RECRUITING:
			clearformess = 1;
			pool[p]->recruitment_activity();
			break;
		case ACTIVITY_STEALCARS:
			clearformess = 1;
			if (pool[p]->stealcar())
				pool[p]->set_activity(ACTIVITY_NONE);
			else if (pool[p]->location != -1 && LocationsPool::getInstance().getLocationType(pool[p]->location) == SITE_GOVERNMENT_POLICESTATION)
				pool[p]->criminalize( LAWFLAG_CARTHEFT);
			break;
		case ACTIVITY_POLLS:
			if (clearformess) eraseAlt();
			else makedelimiter();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 1, pool[p]->getNameAndAlignment().name, gamelog);
			addstrAlt(CONST_daily019, gamelog);
			gamelog.nextMessage();
			pressAnyKey();
			pool[p]->train(SKILL_COMPUTERS, max(3 - pool[p]->get_skill(SKILL_COMPUTERS), 1));
			pool[p]->survey();
			//pool[p]->activity.type=ACTIVITY_NONE;  No reason for this not to repeat.  -AM-
			clearformess = 1;
			break;
		case ACTIVITY_VISIT:
			pool[p]->set_activity(ACTIVITY_NONE);
			break;
		case ACTIVITY_NONE:
			if (pool[p]->align == 1 && !pool[p]->is_imprisoned() && (pool[p]->get_armor().is_bloody() || pool[p]->get_armor().is_damaged()))
				pool[p]->repairarmor(clearformess);
			break;
		}
	}
}
void tendAllHostages(char &clearformess) {
	extern vector<DeprecatedCreature *> pool;
	for (int p = len(pool) - 1; p >= 0; p--)
	{
		if (!pool[p]->getNameAndAlignment().alive) continue;
		if (pool[p]->align != 1){
			pool[p]->tendhostage(clearformess); // assigned clearformess true if any hostages exists (and don't escape)
		}
	}
}
void squadOverrideIndividual(const int sq, const char clearformess) {
	const string CONST_daily005 = " instead of ";
	const string CONST_daily004 = " acted with ";
	extern Log gamelog;
	extern vector<Deprecatedsquadst *> squad;
	const string singleDot = ".";

	for (int p = 0; p < 6; p++)
	{
		if (squad[sq]->squad[p])
		{
			if (squad[sq]->squad[p]->activity_type() != ACTIVITY_NONE &&
				squad[sq]->squad[p]->activity_type() != ACTIVITY_VISIT)
			{
				if (clearformess) eraseAlt();
				else makedelimiter();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8, 1, squad[sq]->squad[p]->getNameAndAlignment().name, gamelog);
				addstrAlt(CONST_daily004, gamelog);
				addstrAlt(squad[sq]->name, gamelog);
				addstrAlt(CONST_daily005, gamelog);
				addstrAlt(getactivity(squad[sq]->squad[p]->activity), gamelog);
				addstrAlt(singleDot, gamelog);
				gamelog.newline();
				pressAnyKey();
			}
			squad[sq]->squad[p]->set_activity(ACTIVITY_VISIT);
			squad[sq]->squad[p]->activity.arg = squad[sq]->activity.arg;
		}
	}

}
string getVehicleFullname(int i);
void cullUnavailableCars(vector<long> &wantcar, vector<long> &caridused, const int sq, const char clearformess) {
	const string singleDot = ".";
	const string CONST_daily008 = " couldn't use the ";
	extern Log gamelog;
	extern vector<Deprecatedsquadst *> squad;
	if (len(wantcar)) {
		for (int c = len(wantcar) - 1; c >= 0; c--) {
			for (int c2 = 0; c2 < len(caridused); c2++) {
				if (wantcar[c] == caridused[c2])
				{
					long v = id_getcar(caridused[c2]);
					if (v != -1)
					{
						if (clearformess) eraseAlt();
						else makedelimiter();
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(8, 1, squad[sq]->name, gamelog);
						addstrAlt(CONST_daily008, gamelog);
						addstrAlt(getVehicleFullname(v), gamelog);
						addstrAlt(singleDot, gamelog);
						gamelog.nextMessage();
						pressAnyKey();
					}
					wantcar.erase(wantcar.begin() + c);
					break;
				}
			}
		}
	}
}
void carUpSquad(const int sq, vector<long> &caridused, const char clearformess) {
	extern Log gamelog;
	extern vector<Deprecatedsquadst *> squad;
	//CAR UP AS NECESSARY
	vector<long> wantcar;
	for (int p = 0; p < 6; p++) if (squad[sq]->squad[p])
	{
		long wid = squad[sq]->squad[p]->pref_carid;
		if (wid == -1) continue;
		int w;
		for (w = 0; w < len(wantcar); w++)
			if (wantcar[w] == wid) break;
		if (w == len(wantcar)) wantcar.push_back(wid);
	}
	//CULL UNAVAILABLE CARS
	cullUnavailableCars(wantcar, caridused, sq, clearformess);
	//ASSIGN AVAILABLE CARS
	if (len(wantcar))
	{
		for (int w = 0; w < len(wantcar); w++)
		{
			vector<int> driver, passenger;
			long currentPassenger = wantcar[w];
			caridused.push_back(currentPassenger);
			//FILL CAR WITH DESIGNATED DRIVERS AND PASSENGERS
			for (int p = 0; p < 6; p++)
				if (squad[sq]->squad[p])
					if (squad[sq]->squad[p]->pref_carid == currentPassenger)
					{
						squad[sq]->squad[p]->carid = currentPassenger;
						squad[sq]->squad[p]->is_driver = squad[sq]->squad[p]->pref_is_driver&&
							squad[sq]->squad[p]->canwalk();
						if (squad[sq]->squad[p]->is_driver) driver.push_back(p);
						else passenger.push_back(p);
					}
			//NO DRIVER?
			if (!len(driver))
			{
				//MAKE BEST DRIVING PASSENGER INTO A DRIVER
				if (len(passenger))
				{
					int max = 0;
					for (int p = 0; p < len(passenger); p++)
					{
						int v = id_getcar(squad[sq]->squad[passenger[p]]->carid);
						if (v >= 0)
							if (squad[sq]->squad[passenger[p]]->driveskill(v) > max&&
								squad[sq]->squad[passenger[p]]->canwalk())
								max = squad[sq]->squad[passenger[p]]->driveskill(v);
					}
					vector<int> goodp;
					for (int p = 0; p < len(passenger); p++)
					{
						int v = id_getcar(squad[sq]->squad[passenger[p]]->carid);
						if (v >= 0)
							if (squad[sq]->squad[passenger[p]]->driveskill(v) == max &&
								squad[sq]->squad[passenger[p]]->canwalk())
								goodp.push_back(passenger[p]);
					}
					if (len(goodp))
					{
						int p = pickrandom(goodp);
						squad[sq]->squad[p]->is_driver = 1;
					}
				}
			}
			//TOO MANY DRIVERS?
			else if (len(driver) > 1)
			{
				//TOSS ALL BUT THE BEST
				int max = 0;
				for (int p = 0; p < len(driver); p++)
				{
					long v = id_getcar(squad[sq]->squad[driver[p]]->carid);
					if (v >= 0)
						if (squad[sq]->squad[driver[p]]->driveskill(v) > max)
							max = squad[sq]->squad[driver[p]]->driveskill(v);
				}
				vector<int> goodp;
				for (int p = 0; p < len(driver); p++)
				{
					long v = id_getcar(squad[sq]->squad[driver[p]]->carid);
					if (v >= 0)
						if (squad[sq]->squad[driver[p]]->driveskill(v) == max)
							goodp.push_back(p);
				}
				if (len(goodp))
				{
					int p = pickrandom(goodp);
					for (int p2 = 0; p2 < len(driver); p2++)
					{
						if (p2 == p) continue;
						squad[sq]->squad[driver[p2]]->is_driver = 0;
					}
				}
			}
		}
		//PUT PEOPLE WITHOUT CARS INTO RANDOM CARS
		//THESE PEOPLE WILL NOT DRIVE
		for (int p = 0; p < 6; p++)
			if (squad[sq]->squad[p])
				if (squad[sq]->squad[p]->carid == -1)
				{
					squad[sq]->squad[p]->carid = pickrandom(wantcar);
					squad[sq]->squad[p]->is_driver = 0;
				}
	}
}
void turnSquadAway(const int sq) {
	const string CONST_daily007 = " was too hot to risk.";
	const string CONST_daily006 = " decided ";
	extern Log gamelog;
	extern vector<Deprecatedsquadst *> squad;
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(8, 1, squad[sq]->name, gamelog);
	addstrAlt(CONST_daily006, gamelog);
	addstrAlt(LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg), gamelog);
	addstrAlt(CONST_daily007, gamelog);
	gamelog.nextMessage();
	pressAnyKey();
	//ON TO THE NEXT SQUAD
	squad[sq]->activity.type = ACTIVITY_NONE;
}
void giveDriverExperience(const int sq) {
	extern short fieldskillrate;
	extern vector<Deprecatedsquadst *> squad;

	for (int i = 0; i < 6; i++)
		if (squad[sq]->squad[i] && squad[sq]->squad[i]->carid != -1 && squad[sq]->squad[i]->is_driver)
		{
			switch (fieldskillrate)
			{
			case FIELDSKILLRATE_FAST:
				squad[sq]->squad[i]->train(SKILL_DRIVING, 5); break;
			case FIELDSKILLRATE_CLASSIC:
				squad[sq]->squad[i]->train(SKILL_DRIVING, 5); break;
			case FIELDSKILLRATE_HARD:
				squad[sq]->squad[i]->train(SKILL_DRIVING, max(0, 5 - squad[sq]->squad[i]->get_skill(SKILL_DRIVING))); break;
			}
		}
}
void squadDepart(const int sq, const char clearformess) {
	const string singleDot = ".";
	const string CONST_daily018 = "Why is the squad here?   (S)afe House, to cause (T)rouble, or (B)oth?";
	const string CONST_daily017 = " has arrived at ";
	const string CONST_daily016 = " looks around ";
	const string CONST_daily013 = " arrives in ";
	extern char showcarprefs;
	extern Deprecatedsquadst *activesquad;
	extern Log gamelog;
	extern vector<Deprecatedsquadst *> squad;
	extern vector<Deprecatednewsstoryst *> newsstory;
	switch (LocationsPool::getInstance().getLocationType(squad[sq]->activity.arg))
	{
	case SITE_CITY_NEW_YORK:
	case SITE_CITY_SEATTLE:
	case SITE_CITY_LOS_ANGELES:
	case SITE_CITY_CHICAGO:
	case SITE_CITY_DETROIT:
	case SITE_CITY_ATLANTA:
	case SITE_CITY_MIAMI:
	case SITE_CITY_WASHINGTON_DC:
		if (clearformess) eraseAlt();
		else makedelimiter();
		mvaddstrAlt(8, 1, squad[sq]->name, gamelog);
		addstrAlt(CONST_daily013, gamelog);
		addstrAlt(LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg), gamelog);
		addstrAlt(singleDot, gamelog);
		gamelog.nextMessage();
		pressAnyKey();
		{
			int l = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, squad[sq]->activity.arg); //int l = find_homeless_shelter(squad[sq]->activity.arg);
																									 // Base at new city's homeless shelter
			basesquad(squad[sq], l);
			locatesquad(squad[sq], l);
		}
		break;
	case SITE_BUSINESS_DEPTSTORE:
	case SITE_BUSINESS_HALLOWEEN:
	case SITE_BUSINESS_PAWNSHOP:
	case SITE_BUSINESS_CARDEALERSHIP:
	case SITE_BUSINESS_ARMSDEALER:
		if (clearformess) eraseAlt();
		else makedelimiter();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8, 1, squad[sq]->name, gamelog);
		addstrAlt(CONST_daily017, gamelog);
		addstrAlt(LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg), gamelog);
		addstrAlt(singleDot, gamelog);
		gamelog.nextMessage();
		pressAnyKey();
		activesquad = squad[sq];
		showcarprefs = -1;
		switch (LocationsPool::getInstance().getLocationType(squad[sq]->activity.arg))
		{
		case SITE_BUSINESS_DEPTSTORE:
			deptstore(squad[sq]->activity.arg);
			break;
		case SITE_BUSINESS_HALLOWEEN:
			halloweenstore(squad[sq]->activity.arg);
			break;
		case SITE_BUSINESS_PAWNSHOP:
			pawnshop(squad[sq]->activity.arg);
			break;
		case SITE_BUSINESS_CARDEALERSHIP:
			dealership(squad[sq]->activity.arg);
			break;
		case SITE_BUSINESS_ARMSDEALER:
			armsdealer(squad[sq]->activity.arg);
			break;
		}
		showcarprefs = 0;
		if (activesquad->squad[0] != NULL)
			locatesquad(activesquad, activesquad->squad[0]->base);
		break;
	case SITE_HOSPITAL_UNIVERSITY:
	case SITE_HOSPITAL_CLINIC:
		if (clearformess) eraseAlt();
		else makedelimiter();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(8, 1, squad[sq]->name, gamelog);
		addstrAlt(CONST_daily017, gamelog);
		addstrAlt(LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg), gamelog);
		addstrAlt(singleDot, gamelog);
		gamelog.nextMessage();
		pressAnyKey();
		activesquad = squad[sq];
		hospital(squad[sq]->activity.arg);
		if (activesquad->squad[0] != NULL)
			locatesquad(activesquad, activesquad->squad[0]->base);
		break;
	default:
		if (clearformess) eraseAlt();
		else makedelimiter();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		if (squad[sq]->squad[0]->base == squad[sq]->activity.arg)
		{
			mvaddstrAlt(8, 1, squad[sq]->name, gamelog);
			addstrAlt(CONST_daily016, gamelog);
			addstrAlt(LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg), gamelog);
			addstrAlt(singleDot, gamelog);
			gamelog.nextMessage();
		}
		else
		{
			mvaddstrAlt(8, 1, squad[sq]->name, gamelog);
			addstrAlt(CONST_daily017, gamelog);
			addstrAlt(LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg), gamelog);
			addstrAlt(singleDot, gamelog);
			gamelog.nextMessage();
		}
		pressAnyKey();
		if (clearformess) eraseAlt();
		else makedelimiter();
		int c = 't';
		if (LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE,squad[sq]->activity.arg) >= 0 &&
			LocationsPool::getInstance().getLocationType(squad[sq]->activity.arg) == SITE_INDUSTRY_WAREHOUSE)
			c = 's';
		else if (LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE,squad[sq]->activity.arg) >= 0 &&
			squad[sq]->squad[0]->base != squad[sq]->activity.arg)
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(8, 1, CONST_daily018);
			c = pressSpecificKey('s', 'b', 't');
		}
		if (c == 's' || c == 'b') basesquad(squad[sq], squad[sq]->activity.arg);
		if (c == 't' || c == 'b')
		{
			activesquad = squad[sq];
			Deprecatednewsstoryst *ns = new Deprecatednewsstoryst;
			ns->type = NEWSSTORY_SQUAD_SITE;
			ns->positive = 1;
			ns->loc = squad[sq]->activity.arg;
			newsstory.push_back(ns);
			mode_site(squad[sq]->activity.arg);
		}
		if (squad[sq]->squad[0])
			locatesquad(squad[sq], squad[sq]->squad[0]->base);
		break;
	}
}
void advanceSquads(char &clearformess) {
	const string CONST_daily012A = " spent $";
	const string CONST_daily012B = " on tickets to go to ";
	const string CONST_daily012C = ".";
	const string CONST_daily011A = " couldn't afford tickets to go to %";
	const string CONST_daily011B = ".";
	const string CONST_daily010 = "travel location";
	const string CONST_daily009 = " didn't have a car to get to ";
	extern Deprecatedsquadst *activesquad;
	extern Log gamelog;
	extern vector<Deprecatedsquadst *> squad;
	extern class Ledger ledger;
	const string singleDot = ".";
	vector<long> caridused;
	//ADVANCE SQUADS
	Deprecatedsquadst *oactivesquad = activesquad;
	for (int sq = 0; sq < len(squad); sq++)
	{
		//MAKE SURE MEMBERS DON'T ACT IF SQUAD DOES
		if (squad[sq]->activity.type != ACTIVITY_NONE) {
			squadOverrideIndividual(sq, clearformess);
		}
		if (squad[sq]->activity.type == ACTIVITY_VISIT)
		{
			//TURN AWAY SQUADS FROM RECENTLY CLOSED OR SIEGED SITES
			if (LocationsPool::getInstance().get_specific_integer(INT_ISTHISSITECLOSED,squad[sq]->activity.arg) ||
				LocationsPool::getInstance().isThereASiegeHere(squad[sq]->activity.arg))
			{
				if (clearformess) eraseAlt();
				else makedelimiter();
				turnSquadAway(sq);
				continue;
			}
			carUpSquad(sq, caridused, clearformess);
			//IF NEED CAR AND DON'T HAVE ONE...
			//NOTE: SQUADS DON'T TAKE FREE CARS
			if (LocationsPool::getInstance().doesThisPlaceNeedACar(squad[sq]->activity.arg) && squad[sq]->squad[0])
				if (squad[sq]->squad[0]->carid == -1)
				{
					if (clearformess) eraseAlt();
					else makedelimiter();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8, 1, squad[sq]->name, gamelog);
					addstrAlt(CONST_daily009, gamelog);
					addstrAlt(LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg), gamelog);
					addstrAlt(singleDot, gamelog);
					gamelog.nextMessage();
					pressAnyKey();
					//ON TO THE NEXT SQUAD
					squad[sq]->activity.type = ACTIVITY_NONE;
					continue;
				}
			// Give drivers experience if they actually travel
			if (squad[sq]->activity.arg != squad[sq]->squad[0]->base) {
				giveDriverExperience(sq);
			}
			//GO PLACES
			// Identify the CONST_daily010 -- top level in multi-city play,
			// a particular district in one-city play
			int travelLocation = -1;
			for (int i = 0; i < LocationsPool::getInstance().lenpool(); i++)
				if (LocationsPool::getInstance().getLocationType(i) == SITE_TRAVEL)
				{
					travelLocation = i;
					break;
				}
			// Verify travellers can afford the cost, and charge them
			bool canDepart = true;
			if (LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONPARENT,squad[sq]->activity.arg) == travelLocation)
			{
				if (clearformess) eraseAlt();
				else makedelimiter();
				int price;
				for (price = 0; price < 6; price++) if (!squad[sq]->squad[price]) break;
				price *= 100;
				if (ledger.get_funds() < price)
				{
					mvaddstrAlt(8, 1, squad[sq]->name + CONST_daily011A + LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg) + CONST_daily011B, gamelog);
					canDepart = false;
				}
				else
				{
					ledger.subtract_funds(price, EXPENSE_TRAVEL);
					mvaddstrAlt(8, 1, squad[sq]->name + CONST_daily012A + tostring(price) + CONST_daily012B + LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg) + CONST_daily012C, gamelog);
				}
				pressAnyKey();
			}
			if (canDepart) {
				squadDepart(sq, clearformess);
				clearformess = 1;
			}
			squad[sq]->activity.type = ACTIVITY_NONE;
		}
	}


	activesquad = oactivesquad;
}
void moveSquadlessToBaseIfNotSiege() {
	extern vector<DeprecatedCreature *> pool;
	for (int p = 0; p < len(pool); p++)
	{
		if (!pool[p]->getNameAndAlignment().alive || !pool[p]->is_active_liberal() || pool[p]->squadid != -1)
			continue;
		// Prevent moving people to a sieged location,
		// but don't evacuate people already under siege. - wisq
		if (pool[p]->location != pool[p]->base &&
			LocationsPool::getInstance().isThereASiegeHere(pool[p]->base))
		{
			pool[p]->base = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, pool[p]->location); //find_homeless_shelter(*pool[p]);pool[p]->base = find_homeless_shelter(*pool[p]);
		}
		pool[p]->location = pool[p]->base;
	}

}
void doDates(char &clearformess);
void clearCarStates();
void advanceday(char &clearformess, char canseethings)
{
	extern char showcarprefs;
	extern char disbanding;
	extern class Ledger ledger;
	//
	showcarprefs = 0;
	//int w = 0;
	//int l2;
	//*JDS* Save the game to save.dat each day. :)
	if (!disbanding) {
		title_screen::getInstance().autosavegame();
	}
	ledger.resetDailyAmounts();
	//CLEAR CAR STATES
	clearCarStates();
	// Move squadless Liberals to their bases if not under siege
	if (!disbanding) {
		moveSquadlessToBaseIfNotSiege();
		advanceSquads(clearformess);  //MIGHT assign clearformess true
		tendAllHostages(clearformess); // assigns clearformess true if any hostages exists (and don't escape) checks clearformess iff hostage(s) escape
		DeprecatedCreature::activitiesForIndividuals(clearformess);  //MIGHT assign clearformess true
	}
	// CANNOT change clearformess
	funds_and_trouble(clearformess);
	determineMedicalSupportAtEachLocation(clearformess);
	//DISPERSAL CHECK
	dispersalcheck(clearformess);
	//DO RENT
	doRent(clearformess);

	//MEET WITH POTENTIAL RECRUITS
	meetWithPotentialRecruits(clearformess); //MIGHT assign clearformess true
	//DO DATES
	if (!disbanding) {
		doDates(clearformess); //MIGHT assign clearformess true
	}

	// CANNOT change clearformess
	//AGE THINGS
	ageThings(clearformess);

	//DO REPORTING BY MAJOR NEWSPAPERS
	clearformess = true; // ALWAYS assigns clearformess true
	majornewspaper(canseethings);
	//CLEAN UP GONE SQUADS
	cleangonesquads();
	//SIEGE?
	siegeturn();
	siegecheck(canseethings);
	//CLEAN GONE SQUADS AGAIN
	cleangonesquads();
	showcarprefs = 1;
}
/* daily - returns true if the site type supports high security */
char securityable(int type)
{
	switch (type)
	{
	case SITE_BUSINESS_CIGARBAR:
	case SITE_RESIDENTIAL_APARTMENT_UPSCALE:
	case SITE_LABORATORY_COSMETICS:
	case SITE_LABORATORY_GENETIC:
	case SITE_GOVERNMENT_FIRESTATION:
	case SITE_INDUSTRY_SWEATSHOP:
	case SITE_INDUSTRY_POLLUTER:
	case SITE_CORPORATE_HEADQUARTERS:
	case SITE_MEDIA_AMRADIO:
	case SITE_MEDIA_CABLENEWS:
		return 1;
		//These places have better quality locks.
	case SITE_BUSINESS_BANK:
	case SITE_INDUSTRY_NUCLEAR:
	case SITE_GOVERNMENT_POLICESTATION:
	case SITE_GOVERNMENT_COURTHOUSE:
	case SITE_GOVERNMENT_PRISON:
	case SITE_GOVERNMENT_INTELLIGENCEHQ:
	case SITE_GOVERNMENT_ARMYBASE:
	case SITE_CORPORATE_HOUSE:
	case SITE_GOVERNMENT_WHITE_HOUSE:
		return 2;
	}
	return 0;
}

