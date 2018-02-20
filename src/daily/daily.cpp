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

#include "common/ledgerEnums.h"
#include "common/ledger.h"

#include "vehicle/vehicletype.h"
#include "vehicle/vehicle.h"

//#include "news/news.h"
void majornewspaper(char &clearformess, char canseethings);

//#include "sitemode/sitemode.h"
void mode_site(short loc);

#include "common/consolesupport.h"
// for void set_color(short,short,bool)

#include "log/log.h"
// for commondisplay.h
#include "common/commondisplay.h"
// for makedelimeter

#include "common/getnames.h"
// for std::string getactivity(activityst)

#include "common/translateid.h"
// for  int getsquad(int)

#include "common/commonactions.h"
#include "common/commonactionsCreature.h"
// for void basesquad(squadst *,long)

#include "title/saveload.h"
// for void savegame(const string& filename);

#include "daily/daily.h"
//own header

#include "daily/shopsnstuff.h"
//for void halloweenstore(int loc);

#include "daily/activities.h"
//for void repairarmor(Creature &cr,char &clearformess);

#include "daily/siege.h"        
//for fooddaysleft

#include "daily/recruit.h"
//for char completerecruitmeeting(recruitst &d,int p,char &clearformess);

#include "daily/date.h"
//for char completevacation(datest &d,int p,char &clearformess);

#include "combat/chase.h"
#include "combat/chaseCreature.h"
//for int driveskill(Creature &cr,Vehicle &v);
        //hmm --Schmel924


#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>

#include "title/titlescreen.h"

extern title_screen *TitleScreen;

extern vector<Creature *> pool;
extern Log gamelog;
#include "locations/locationsPool.h"
extern int year;
extern string singleDot;
extern char showcarprefs;
extern char disbanding;
extern class Ledger ledger;
extern squadst *activesquad;
extern vector<squadst *> squad;

extern vector<Vehicle *> vehicle;
extern short fieldskillrate;
extern vector<newsstoryst *> newsstory;
extern int day;
extern vector<recruitst *> recruit;
extern vector<datest *> date;
extern int month;
void autosavegame();

#include "common/creaturePool.h"
void determineMedicalSupportAtEachLocation(bool clearformess);
void advanceday(char &clearformess, char canseethings)
{
	int p;
	showcarprefs = 0;
	int w = 0;
	//int l2;
	//*JDS* Save the game to save.dat each day. :)
	if (!disbanding) TitleScreen->autosavegame();
	ledger.resetDailyAmounts();
	//CLEAR CAR STATES
	vector<long> caridused;
	for (p = 0; p < CreaturePool::getInstance().lenpool(); p++) pool[p]->carid = -1;
	// Move squadless Liberals to their bases if not under siege
	if (!disbanding) for (p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		if (!pool[p]->alive || !pool[p]->is_active_liberal() || pool[p]->squadid != -1)
			continue;
		// Prevent moving people to a sieged location,
		// but don't evacuate people already under siege. - wisq
		if (pool[p]->location != pool[p]->base &&
			LocationsPool::getInstance().isThereASiegeHere(pool[p]->base))
		{
			pool[p]->base = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, pool[p]->location); //find_homeless_shelter(*pool[p]);
		}
		pool[p]->location = pool[p]->base;
	}
	//ADVANCE SQUADS
	squadst *oactivesquad = activesquad;
	if (!disbanding) for (int sq = 0; sq < len(squad); sq++)
	{
		//MAKE SURE MEMBERS DON'T ACT IF SQUAD DOES
		if (squad[sq]->activity.type != ACTIVITY_NONE)
		{
			for (int p = 0; p < 6; p++)
			{
				if (squad[sq]->squad[p])
				{
					if (squad[sq]->squad[p]->activity.type != ACTIVITY_NONE&&
						squad[sq]->squad[p]->activity.type != ACTIVITY_VISIT)
					{
						if (clearformess) eraseAlt();
						else makedelimiter();
						set_color_easy(WHITE_ON_BLACK_BRIGHT);
						mvaddstrAlt(8,  1, squad[sq]->squad[p]->name, gamelog);
						addstrAlt(" acted with ", gamelog);
						addstrAlt(squad[sq]->name, gamelog);
						addstrAlt(" instead of ", gamelog);
						addstrAlt(getactivity(squad[sq]->squad[p]->activity), gamelog);
						addstrAlt(singleDot, gamelog);
						gamelog.newline();
						getkeyAlt();
					}
					squad[sq]->squad[p]->activity.type = ACTIVITY_VISIT;
					squad[sq]->squad[p]->activity.arg = squad[sq]->activity.arg;
				}
			}
		}
		if (squad[sq]->activity.type == ACTIVITY_VISIT)
		{
			//TURN AWAY SQUADS FROM RECENTLY CLOSED OR SIEGED SITES
			if (LocationsPool::getInstance().isThisSiteClosed(squad[sq]->activity.arg) ||
				LocationsPool::getInstance().isThereASiegeHere(squad[sq]->activity.arg))
			{
				if (clearformess) eraseAlt();
				else makedelimiter();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8,  1, squad[sq]->name, gamelog);
				addstrAlt(" decided ", gamelog);
				addstrAlt(LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg), gamelog);
				addstrAlt(" was too hot to risk.", gamelog);
				gamelog.nextMessage();
				getkeyAlt();
				//ON TO THE NEXT SQUAD
				squad[sq]->activity.type = ACTIVITY_NONE;
				continue;
			}
			//CAR UP AS NECESSARY
			vector<long> wantcar;
			for (p = 0; p < 6; p++) if (squad[sq]->squad[p])
			{
				long wid = squad[sq]->squad[p]->pref_carid;
				if (wid == -1) continue;
				for (w = 0; w < len(wantcar); w++)
					if (wantcar[w] == wid) break;
				if (w == len(wantcar)) wantcar.push_back(wid);
			}
			//CULL UNAVAILABLE CARS
			if (len(wantcar))
				for (int c = len(wantcar) - 1; c >= 0; c--)
					for (int c2 = 0; c2 < len(caridused); c2++)
						if (wantcar[c] == caridused[c2])
						{
							long v = id_getcar(caridused[c2]);
							if (v != -1)
							{
								if (clearformess) eraseAlt();
								else makedelimiter();
								set_color_easy(WHITE_ON_BLACK_BRIGHT);
								mvaddstrAlt(8,  1, squad[sq]->name, gamelog);
								addstrAlt(" couldn't use the ", gamelog);
								addstrAlt(vehicle[v]->fullname(), gamelog);
								addstrAlt(singleDot, gamelog);
								gamelog.nextMessage();
								getkeyAlt();
							}
							wantcar.erase(wantcar.begin() + c);
							break;
						}
			//ASSIGN AVAILABLE CARS
			if (len(wantcar))
			{
				vector<int> driver, passenger;
				for (w = 0; w < len(wantcar); w++)
				{
					driver.clear();
					passenger.clear();
					caridused.push_back(wantcar[w]);
					//FILL CAR WITH DESIGNATED DRIVERS AND PASSENGERS
					for (p = 0; p < 6; p++)
						if (squad[sq]->squad[p])
							if (squad[sq]->squad[p]->pref_carid == wantcar[w])
							{
								squad[sq]->squad[p]->carid = wantcar[w];
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
							for (p = 0; p<len(passenger); p++)
							{
								long v = id_getcar(squad[sq]->squad[passenger[p]]->carid);
								if (v >= 0)
									if (driveskill(*squad[sq]->squad[passenger[p]], *vehicle[v])>max&&
										squad[sq]->squad[passenger[p]]->canwalk())
										max = driveskill(*squad[sq]->squad[passenger[p]], *vehicle[v]);
							}
							vector<int> goodp;
							for (p = 0; p < len(passenger); p++)
							{
								long v = id_getcar(squad[sq]->squad[passenger[p]]->carid);
								if (v >= 0)
									if (driveskill(*squad[sq]->squad[passenger[p]], *vehicle[v]) == max&&
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
						for (p = 0; p<len(driver); p++)
						{
							long v = id_getcar(squad[sq]->squad[driver[p]]->carid);
							if (v >= 0)
								if (driveskill(*squad[sq]->squad[driver[p]], *vehicle[v])>max)
									max = driveskill(*squad[sq]->squad[driver[p]], *vehicle[v]);
						}
						vector<int> goodp;
						for (p = 0; p < len(driver); p++)
						{
							long v = id_getcar(squad[sq]->squad[driver[p]]->carid);
							if (v >= 0)
								if (driveskill(*squad[sq]->squad[driver[p]], *vehicle[v]) == max)
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
			//IF NEED CAR AND DON'T HAVE ONE...
			//NOTE: SQUADS DON'T TAKE FREE CARS
			if (LocationsPool::getInstance().doesThisPlaceNeedACar(squad[sq]->activity.arg)&&squad[sq]->squad[0])
				if (squad[sq]->squad[0]->carid == -1)
				{
					if (clearformess) eraseAlt();
					else makedelimiter();
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8,  1, squad[sq]->name, gamelog);
					addstrAlt(" didn't have a car to get to ", gamelog);
					addstrAlt(LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg), gamelog);
					addstrAlt(singleDot, gamelog);
					gamelog.nextMessage();
					getkeyAlt();
					//ON TO THE NEXT SQUAD
					squad[sq]->activity.type = ACTIVITY_NONE;
					continue;
				}
			// Give drivers experience if they actually travel
			if (squad[sq]->activity.arg != squad[sq]->squad[0]->base)
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
			//GO PLACES
			// Identify the "travel location" -- top level in multi-city play,
			// a particular district in one-city play
			int travelLocation = LocationsPool::getInstance().findTravelLocation();
			// Verify travellers can afford the cost, and charge them
			bool canDepart = true;
			if (LocationsPool::getInstance().getLocationParent(squad[sq]->activity.arg) == travelLocation)
			{
				if (clearformess) eraseAlt();
				else makedelimiter();
				int price;
				for (price = 0; price < 6; price++) if (!squad[sq]->squad[price]) break;
				price *= 100;
				if (ledger.get_funds() < price)
				{
					mvaddstr_fl(8, 1, gamelog, "%s couldn't afford tickets to go to %s.", squad[sq]->name, LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg));
					canDepart = false;
				}
				else
				{
					ledger.subtract_funds(price, EXPENSE_TRAVEL);
					mvaddstr_fl(8, 1, gamelog, "%s spent $%d on tickets to go to %s.", squad[sq]->name, price, LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg));
				}
				getkeyAlt();
			}
			if (canDepart) switch (LocationsPool::getInstance().getLocationType(squad[sq]->activity.arg))
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
				mvaddstrAlt(8,  1, squad[sq]->name, gamelog);
				addstrAlt(" arrives in ", gamelog);
				addstrAlt(LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg), gamelog);
				addstrAlt(singleDot, gamelog);
				gamelog.nextMessage();
				getkeyAlt();
				{
					int l = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, squad[sq]->activity.arg);
					// Base at new city's homeless shelter
					basesquad(squad[sq], l);
					locatesquad(squad[sq], l);
				}
				clearformess = 1;
				break;
			case SITE_BUSINESS_DEPTSTORE:
			case SITE_BUSINESS_HALLOWEEN:
			case SITE_BUSINESS_PAWNSHOP:
			case SITE_BUSINESS_CARDEALERSHIP:
			case SITE_BUSINESS_ARMSDEALER:
				if (clearformess) eraseAlt();
				else makedelimiter();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8,  1, squad[sq]->name, gamelog);
				addstrAlt(" has arrived at ", gamelog);
				addstrAlt(LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg), gamelog);
				addstrAlt(singleDot, gamelog);
				gamelog.nextMessage();
				getkeyAlt();
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
				clearformess = 1;
				break;
			case SITE_HOSPITAL_UNIVERSITY:
			case SITE_HOSPITAL_CLINIC:
				if (clearformess) eraseAlt();
				else makedelimiter();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(8,  1, squad[sq]->name, gamelog);
				addstrAlt(" has arrived at ", gamelog);
				addstrAlt(LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg), gamelog);
				addstrAlt(singleDot, gamelog);
				gamelog.nextMessage();
				getkeyAlt();
				activesquad = squad[sq];
				hospital(squad[sq]->activity.arg);
				if (activesquad->squad[0] != NULL)
					locatesquad(activesquad, activesquad->squad[0]->base);
				clearformess = 1;
				break;
			default:
				if (clearformess) eraseAlt();
				else makedelimiter();
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				if (squad[sq]->squad[0]->base == squad[sq]->activity.arg)
				{
					mvaddstrAlt(8, 1, squad[sq]->name, gamelog);
					addstrAlt(" looks around ", gamelog);
					addstrAlt(LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg), gamelog);
					addstrAlt(singleDot, gamelog);
					gamelog.nextMessage();
				}
				else
				{
					mvaddstrAlt(8, 1, squad[sq]->name, gamelog);
					addstrAlt(" has arrived at ", gamelog);
					addstrAlt(LocationsPool::getInstance().getLocationName(squad[sq]->activity.arg), gamelog);
					addstrAlt(singleDot, gamelog);
					gamelog.nextMessage();
				}
				getkeyAlt();
				if (clearformess) eraseAlt();
				else makedelimiter();
				int c = 't';
				if (LocationsPool::getInstance().getRentingType(squad[sq]->activity.arg) >= 0 &&
					LocationsPool::getInstance().getLocationType(squad[sq]->activity.arg) == SITE_INDUSTRY_WAREHOUSE)
					c = 's';
				else if (LocationsPool::getInstance().getRentingType(squad[sq]->activity.arg) >= 0 &&
					squad[sq]->squad[0]->base != squad[sq]->activity.arg)
				{
					set_color_easy(WHITE_ON_BLACK_BRIGHT);
					mvaddstrAlt(8,  1, "Why is the squad here?   (S)afe House, to cause (T)rouble, or (B)oth?");
					do c = getkeyAlt(); while (c != 's'&&c != 'b'&&c != 't');
				}
				if (c == 's' || c == 'b') basesquad(squad[sq], squad[sq]->activity.arg);
				if (c == 't' || c == 'b')
				{
					activesquad = squad[sq];
					newsstoryst *ns = new newsstoryst;
					ns->type = NEWSSTORY_SQUAD_SITE;
					ns->positive = 1;
					ns->loc = squad[sq]->activity.arg;
					newsstory.push_back(ns);
					mode_site(squad[sq]->activity.arg);
				}
				if (squad[sq]->squad[0])
					locatesquad(squad[sq], squad[sq]->squad[0]->base);
				clearformess = 1;
				break;
			}
			squad[sq]->activity.type = ACTIVITY_NONE;
		}
	}
	activesquad = oactivesquad;
	//HOSTAGES
	if (!disbanding) for (p = CreaturePool::getInstance().lenpool() - 1; p >= 0; p--)
	{
		if (!pool[p]->alive) continue;
		if (pool[p]->align != 1)
			tendhostage(pool[p], clearformess);
	}
	//ACTIVITIES FOR INDIVIDUALS
	if (!disbanding) for (p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		pool[p]->income = 0;
		if (!pool[p]->alive) continue;
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
			switch (pool[p]->activity.type)
			{
			case ACTIVITY_HOSTAGETENDING:
			case ACTIVITY_TEACH_POLITICS:
			case ACTIVITY_TEACH_FIGHTING:
			case ACTIVITY_TEACH_COVERT:
			case ACTIVITY_HEAL:
			case ACTIVITY_REPAIR_ARMOR:
				break;
			default:
				pool[p]->activity.type = ACTIVITY_NONE;
				break;
			}
		}
		switch (pool[p]->activity.type)
		{
		case ACTIVITY_REPAIR_ARMOR:
			repairarmor(*pool[p], clearformess);
			break;
		case ACTIVITY_MAKE_ARMOR:
			makearmor(*pool[p], clearformess);
			// Uncomment this to have people stop making armor after the first day
			//pool[p]->activity.type=ACTIVITY_NONE;
			break;
		case ACTIVITY_WHEELCHAIR:
			getwheelchair(*pool[p], clearformess);
			if (pool[p]->flag & CREATUREFLAG_WHEELCHAIR)pool[p]->activity.type = ACTIVITY_NONE;
			break;
		case ACTIVITY_RECRUITING:
			recruitment_activity(*pool[p], clearformess);
			break;
		case ACTIVITY_STEALCARS:
			if (stealcar(*pool[p], clearformess))
				pool[p]->activity.type = ACTIVITY_NONE;
			else if (pool[p]->location != -1 && LocationsPool::getInstance().getLocationType(pool[p]->location) == SITE_GOVERNMENT_POLICESTATION)
				criminalize(*pool[p], LAWFLAG_CARTHEFT);
			break;
		case ACTIVITY_POLLS:
			if (clearformess) eraseAlt();
			else makedelimiter();
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(8,  1, pool[p]->name, gamelog);
			addstrAlt(" surfs the Net for recent opinion polls.", gamelog);
			gamelog.nextMessage();
			getkeyAlt();
			pool[p]->train(SKILL_COMPUTERS, max(3 - pool[p]->get_skill(SKILL_COMPUTERS), 1));
			survey(pool[p]);
			//pool[p]->activity.type=ACTIVITY_NONE;  No reason for this not to repeat.  -AM-
			clearformess = 1;
			break;
		case ACTIVITY_VISIT:
			pool[p]->activity.type = ACTIVITY_NONE;
			break;
		case ACTIVITY_NONE:
			if (pool[p]->align == 1 && !pool[p]->is_imprisoned() && (pool[p]->get_armor().is_bloody() || pool[p]->get_armor().is_damaged()))
				repairarmor(*pool[p], clearformess);
			break;
		}
	}
	funds_and_trouble(clearformess);
	determineMedicalSupportAtEachLocation(clearformess);
	//DISPERSAL CHECK
	dispersalcheck(clearformess);
	//DO RENT
	if (day == 3 && !disbanding)
		for (int l = 0; l < LocationsPool::getInstance().lenpool(); l++)
			if (LocationsPool::getInstance().getRentingType(l)>0 &&
				!LocationsPool::getInstance().isNewRental(l))
			{  // if rent >= 1000000 this means you get should kicked out automatically
				if (ledger.get_funds() >= LocationsPool::getInstance().getRentingType(l) && LocationsPool::getInstance().getRentingType(l) < 1000000)
					ledger.subtract_funds(LocationsPool::getInstance().getRentingType(l), EXPENSE_RENT);
				//EVICTED!!!!!!!!!
				else
				{
					if (clearformess) eraseAlt();
					else makedelimiter();
					LocationsPool::getInstance().evictLCSFrom(l);
				}
			}
	//MEET WITH POTENTIAL RECRUITS
	for (int i = CreaturePool::getInstance().lenpool() - 1; i >= 0; i--)
		pool[i]->meetings = 0;
	if (!disbanding) for (int r = len(recruit) - 1; r >= 0; r--)
	{
		int p = getpoolcreature(recruit[r]->recruiter_id);
		// Stand up recruits if 1) recruiter does not exist, 2) recruiter was not able to return to a safehouse today
		// or 3) recruiter is dead.
		if (p != -1 && ((pool[p]->location != -1 && LocationsPool::getInstance().getRentingType(pool[p]->location) != RENTING_NOCONTROL&&pool[p]->alive&&
			LocationsPool::getInstance().getLocationCity(pool[p]->location) == LocationsPool::getInstance().getLocationCity(recruit[r]->recruit->location)) || recruit[r]->timeleft > 0))
		{
			//MEET WITH RECRUIT
			//TERMINATE NULL RECRUIT MEETINGS
			if (LocationsPool::getInstance().getLocationCity(pool[p]->location))
			{
				delete_and_remove(recruit, r);
				continue;
			}
			//DO MEETING
			else if (completerecruitmeeting(*recruit[r], p, clearformess))
			{
				delete_and_remove(recruit, r);
				continue;
			}
		}
		else
		{
			delete_and_remove(recruit, r);
			continue;
		}
	}
	//DO DATES
	if (!disbanding) for (int d = len(date) - 1; d >= 0; d--)
	{
		int p = getpoolcreature(date[d]->mac_id);
		// Stand up dates if 1) dater does not exist, or 2) dater was not able to return to a safehouse today (and is not in the hospital)
		if (p != -1 && ((pool[p]->location != -1 &&
			(LocationsPool::getInstance().getRentingType(pool[p]->location) != RENTING_NOCONTROL ||
				LocationsPool::getInstance().getLocationType(pool[p]->location) == SITE_HOSPITAL_CLINIC ||
				LocationsPool::getInstance().getLocationType(pool[p]->location) == SITE_HOSPITAL_UNIVERSITY) &&
			LocationsPool::getInstance().getLocationCity(pool[p]->location) == date[d]->city) ||
			date[d]->timeleft))
		{
			//VACATION
			if (date[d]->timeleft > 0)
			{
				pool[p]->dating = --date[d]->timeleft;
				if (date[d]->timeleft == 0)
				{
					int hs = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, date[d]->city);
					if (LocationsPool::getInstance().isThereASiegeHere(pool[p]->base))
						pool[p]->base = hs;
					pool[p]->location = pool[p]->base;
					if (completevacation(*date[d], p, clearformess))
					{
						delete_and_remove(date, d);
						continue;
					}
				}
			}
			//DO A DATE
			else
			{
				//TERMINATE NULL DATES
				if (LocationsPool::getInstance().isThereASiegeHere(pool[p]->location))
				{
					delete_and_remove(date, d);
					continue;
				}
				//DO DATE
				else if (completedate(*date[d], p, clearformess))
				{
					delete_and_remove(date, d);
					continue;
				}
				else
				{
					pool[p]->dating = date[d]->timeleft;
					if (pool[p]->dating > 0)
					{
						//NOW KICK THE DATER OUT OF THE SQUAD AND LOCATION
						removesquadinfo(*pool[p]);
						pool[p]->location = -1;
					}
				}
			}
		}
		else
		{
			delete_and_remove(date, d);
			continue;
		}
	}
	//AGE THINGS
	day++;
	int pday = day, pmonth = month; // Find out if it's next month already.
	if (pday > monthday()) // Day counter has increased but end-of-month has not yet been
		pday = 1, pmonth = (pmonth % 12) + 1; // checked so it has to be accounted for here.
	for (p = 0; p < CreaturePool::getInstance().lenpool(); p++)
	{
		pool[p]->stunned = 0; // For lack of a better place, make stunning expire here
							  // Increment number of days since joined/kidnapped
		pool[p]->joindays++;
		// Increment number of days been dead if dead
		if (!pool[p]->alive)
		{
			pool[p]->deathdays++;
			continue;
		}
		// animals, tanks don't have age effects at the moment
		//TODO: Start aging effects for animals at age 12, take into account if they are genetic monsters or not.
		if (!pool[p]->animalgloss)
		{
			if (pool[p]->age>60)
			{
				int decrement = 0;
				while (pool[p]->age - decrement > 60)
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
							mvaddstrAlt(8,  1, pool[p]->name, gamelog);
							addstrAlt(" has passed away at the age of ", gamelog);
							addstrAlt(pool[p]->age, gamelog);
							addstrAlt(". The Liberal will be missed.", gamelog);
							gamelog.nextMessage();
							getkeyAlt();
							break;
						}
					}
					decrement += 10;
				}
				if (!pool[p]->alive)continue;
			}
			if (pmonth == pool[p]->birthday_month&&
				pday == pool[p]->birthday_day)
			{
				pool[p]->age++;
				switch (pool[p]->age)
				{
				case 13:
					pool[p]->type = CREATURE_TEENAGER; // aww, all grown up
					pool[p]->type_idname = "CREATURE_TEENAGER";
					break;
				case 18:
					pool[p]->type = CREATURE_POLITICALACTIVIST; // ok seriously this time
					pool[p]->type_idname = "CREATURE_POLITICALACTIVIST";
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
					mvaddstrAlt(8,  1, pool[p]->name, gamelog);
					addstrAlt(" regains contact with the LCS.", gamelog);
					gamelog.nextMessage();
					getkeyAlt();
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
				newsstoryst *ns = new newsstoryst;
				ns->type = NEWSSTORY_KIDNAPREPORT;
				ns->loc = pool[p]->location;
				ns->cr = pool[p];
				newsstory.push_back(ns);
			}
		}
		// Gain skill levels for anything where you have enough experience
		pool[p]->skill_up();
	}
	//DO REPORTING BY MAJOR NEWSPAPERS
	majornewspaper(clearformess, canseethings);
	//CLEAN UP GONE SQUADS
	cleangonesquads();
	//SIEGE?
	siegeturn(clearformess);
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
/* daily - returns the number of days in the current month */
int monthday()
{
	switch (month)
	{
	case 2: return 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); // February
	case 4: // April
	case 6: // June
	case 9: // September
	case 11: return 30; // November
	default: return 31; // January, March, May, July, August, October, & December
	}
}
