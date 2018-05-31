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

#include "../includes.h"
const string blankString = "";


const string tag_value = "value";

const string tag_attribute = "attribute";


const string tag_skill = "skill";

#include "../creature/creature.h"
#include "../locations/locations.h"

#include "../locations/locationsPool.h"
void fillEncounter(CreatureTypes c, int numleft);
void emptyEncounter();
/* rolls up a random creature type according to the passed weighting array */
int getrandomcreaturetype(int cr[CREATURENUM])
{
	int sum = 0;
	for (int c = 0; c < CREATURENUM; c++)sum += cr[c];
	if (sum > 0)
	{
		int roll = LCSrandom(sum);
		int sel = 0;
		while (roll >= 0) { roll -= cr[sel]; sel++; }
		return sel - 1;
	}
	else return -1;
}
void addPoliceOrMilitary(int creaturearray[CREATURENUM]) {
	extern short siteonfire;
	extern short sitetype;
	extern short lawList[LAWNUM];
	switch (sitetype)
	{
	case SITE_GOVERNMENT_ARMYBASE:
		creaturearray[CREATURE_SOLDIER] = 1000;
		creaturearray[CREATURE_MILITARYPOLICE] = 300;
		creaturearray[CREATURE_MILITARYOFFICER] = 150;
		creaturearray[CREATURE_SEAL] = 150;
		creaturearray[CREATURE_GUARDDOG] = 100;
		creaturearray[CREATURE_TANK] = 100;
		break;
	case SITE_GOVERNMENT_WHITE_HOUSE:
		creaturearray[CREATURE_SECRET_SERVICE] = 1000;
		creaturearray[CREATURE_MILITARYOFFICER] = 100;
		break;
	case SITE_GOVERNMENT_INTELLIGENCEHQ:
		creaturearray[CREATURE_AGENT] = 1000;
		creaturearray[CREATURE_MILITARYOFFICER] = 100;
		creaturearray[CREATURE_GUARDDOG] = 50;
		break;
	case SITE_CORPORATE_HEADQUARTERS:
	case SITE_CORPORATE_HOUSE:
		creaturearray[CREATURE_MERC] = 1000;
		break;
	case SITE_MEDIA_AMRADIO:
	case SITE_MEDIA_CABLENEWS:
		creaturearray[CREATURE_HICK] = 1000;
		break;
	case SITE_GOVERNMENT_POLICESTATION:
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] = 1000;
		else creaturearray[CREATURE_SWAT] = 1000;
		break;
	default:
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] = 1000;
		else if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] = 1000;
		else creaturearray[CREATURE_COP] = 1000;
		break;
	}
	if (siteonfire && lawList[LAW_FREESPEECH] != -2)creaturearray[CREATURE_FIREFIGHTER] = 1000;
}

map<int, vector<int> > locationsSpawners = {
	map<int, vector<int> >::value_type(SITE_BUSINESS_JUICEBAR,{
		CREATURE_TEENAGER, 10,
		CREATURE_JUDGE_LIBERAL, 1,
		CREATURE_COLLEGESTUDENT, 10,
		CREATURE_MUSICIAN, 2,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_TEACHER, 1,
		CREATURE_HSDROPOUT, 1,
		CREATURE_ENGINEER, 1,
		CREATURE_FASTFOODWORKER, 1,
		CREATURE_BAKER, 1,
		CREATURE_BARISTA, 1,
		CREATURE_BARTENDER, 1,
		CREATURE_TELEMARKETER, 1,
		CREATURE_CARSALESMAN, 1,
		CREATURE_OFFICEWORKER, 1,
		CREATURE_MAILMAN, 1,
		CREATURE_CHEF, 1,
		CREATURE_NURSE, 1,
		CREATURE_AMATEURMAGICIAN, 1,
		CREATURE_HIPPIE, 6,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_SOCIALITE, 2,
		CREATURE_PROGRAMMER, 1,
		CREATURE_RETIREE, 1,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_CAMERAMAN, 1,
		CREATURE_HAIRSTYLIST, 1,
		CREATURE_FASHIONDESIGNER, 1,
		CREATURE_CLERK, 1,
		CREATURE_THIEF, 1,
		CREATURE_ACTOR, 1,
		CREATURE_YOGAINSTRUCTOR, 1,
		CREATURE_MARTIALARTIST, 1,
		CREATURE_ATHLETE, 1,
		CREATURE_LOCKSMITH, 1
	}),
	map<int, vector<int> >::value_type(SITE_BUSINESS_CIGARBAR,{ 
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_CORPORATE_MANAGER, 30,
		CREATURE_COP, 5,
		CREATURE_JUDGE_CONSERVATIVE, 1,
		CREATURE_RADIOPERSONALITY, 1,
		CREATURE_NEWSANCHOR, 1,
		CREATURE_MILITARYOFFICER, 1,
		CREATURE_LAWYER, 15,
		CREATURE_DOCTOR, 10,
		CREATURE_PSYCHOLOGIST, 1,
		CREATURE_MUSICIAN, 1,
		CREATURE_ENGINEER, 10,
		CREATURE_BARTENDER, 10,
		CREATURE_FOOTBALLCOACH, 1,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_SOCIALITE, 2,
		CREATURE_RETIREE, 1,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_FASHIONDESIGNER, 1,
		CREATURE_THIEF, 1,
		CREATURE_ACTOR, 1,
		CREATURE_ATHLETE, 1,
		CREATURE_FIREFIGHTER, 1,
		CREATURE_LOCKSMITH, 1, }),
	map<int, vector<int> >::value_type(SITE_BUSINESS_CRACKHOUSE,{
		CREATURE_TEENAGER, 100,
		CREATURE_MUSICIAN, 1,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_HSDROPOUT, 30,
		CREATURE_BUM, 200,
		CREATURE_GANGMEMBER, 200,
		CREATURE_CRACKHEAD, 200,
		CREATURE_PROSTITUTE, 200,
		CREATURE_BIKER, 5,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_THIEF, 3,
		CREATURE_ACTOR, 1,
		CREATURE_JOURNALIST, 2}
		),
	map<int, vector<int> >::value_type(SITE_GOVERNMENT_WHITE_HOUSE,{
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_WORKER_JANITOR, 2,
		CREATURE_WORKER_SECRETARY, 2,
		CREATURE_TEENAGER, 1,
		CREATURE_JUDGE_LIBERAL, 1,
		CREATURE_JUDGE_CONSERVATIVE, 1,
		CREATURE_AGENT, 2,
		CREATURE_MILITARYOFFICER, 3,
		CREATURE_LAWYER, 3,
		CREATURE_DOCTOR, 1,
		CREATURE_COLLEGESTUDENT, 1,
		CREATURE_TEACHER, 1,
		CREATURE_OFFICEWORKER, 5,
		CREATURE_FOOTBALLCOACH, 1,
		CREATURE_CHEF, 1,
		CREATURE_VETERAN, 1,
		CREATURE_JOURNALIST, 2,
		CREATURE_SOCIALITE, 1,
		CREATURE_PHOTOGRAPHER, 2,
		CREATURE_CAMERAMAN, 1,
		CREATURE_HAIRSTYLIST, 1,
		CREATURE_CLERK, 5,
		CREATURE_ACTOR, 1,
		CREATURE_ATHLETE, 1}
		),
	map<int, vector<int> >::value_type(SITE_OUTDOOR_PUBLICPARK, {
		CREATURE_SECURITYGUARD, 5,
		CREATURE_SCIENTIST_LABTECH, 10,
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_CORPORATE_MANAGER, 10,
		CREATURE_WORKER_JANITOR, 5,
		CREATURE_WORKER_SECRETARY, 15,
		CREATURE_TEENAGER, 5,
		CREATURE_COP, 5,
		CREATURE_JUDGE_LIBERAL, 1,
		CREATURE_JUDGE_CONSERVATIVE, 1,
		CREATURE_AGENT, 1,
		CREATURE_RADIOPERSONALITY, 1,
		CREATURE_NEWSANCHOR, 1,
		CREATURE_MILITARYOFFICER, 1,
		CREATURE_LAWYER, 5,
		CREATURE_DOCTOR, 5,
		CREATURE_PSYCHOLOGIST, 1,
		CREATURE_NURSE, 5,
		CREATURE_SEWERWORKER, 1,
		CREATURE_COLLEGESTUDENT, 30,
		CREATURE_MUSICIAN, 5,
		CREATURE_MATHEMATICIAN, 5,
		CREATURE_TEACHER, 5,
		CREATURE_HSDROPOUT, 1,
		CREATURE_BUM, 1,
		CREATURE_GANGMEMBER, 1,
		CREATURE_CRACKHEAD, 1,
		CREATURE_PRIEST, 1,
		CREATURE_ENGINEER, 5,
		CREATURE_FASTFOODWORKER, 5,
		CREATURE_BAKER, 1,
		CREATURE_BARISTA, 10,
		CREATURE_BARTENDER, 1,
		CREATURE_TELEMARKETER, 5,
		CREATURE_CARSALESMAN, 3,
		CREATURE_OFFICEWORKER, 10,
		CREATURE_FOOTBALLCOACH, 1,
		CREATURE_PROSTITUTE, 1,
		CREATURE_MAILMAN, 1,
		CREATURE_GARBAGEMAN, 1,
		CREATURE_PLUMBER, 1,
		CREATURE_CHEF, 1,
		CREATURE_CONSTRUCTIONWORKER, 3,
		CREATURE_AMATEURMAGICIAN, 1,
		CREATURE_MERC, 1,
		CREATURE_SOLDIER, 1,
		CREATURE_VETERAN, 3,
		CREATURE_HIPPIE, 1,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_SOCIALITE, 1,
		CREATURE_BIKER, 1,
		CREATURE_TRUCKER, 1,
		CREATURE_TAXIDRIVER, 1,
		CREATURE_PROGRAMMER, 5,
		CREATURE_RETIREE, 3,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_CAMERAMAN, 1,
		CREATURE_HAIRSTYLIST, 1,
		CREATURE_FASHIONDESIGNER, 1,
		CREATURE_CLERK, 1,
		CREATURE_THIEF, 1,
		CREATURE_ACTOR, 1,
		CREATURE_YOGAINSTRUCTOR, 1,
		CREATURE_MARTIALARTIST, 1,
		CREATURE_ATHLETE, 1,
		CREATURE_FIREFIGHTER, 1,
		CREATURE_LOCKSMITH, 1 }
		),
	map<int, vector<int> >::value_type(SITE_BUSINESS_LATTESTAND, {
		CREATURE_SECURITYGUARD, 5,
		CREATURE_SCIENTIST_LABTECH, 10,
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_CORPORATE_MANAGER, 10,
		CREATURE_WORKER_JANITOR, 5,
		CREATURE_WORKER_SECRETARY, 15,
		CREATURE_TEENAGER, 5,
		CREATURE_COP, 5,
		CREATURE_JUDGE_LIBERAL, 1,
		CREATURE_JUDGE_CONSERVATIVE, 1,
		CREATURE_AGENT, 1,
		CREATURE_RADIOPERSONALITY, 1,
		CREATURE_NEWSANCHOR, 1,
		CREATURE_MILITARYOFFICER, 1,
		CREATURE_LAWYER, 5,
		CREATURE_DOCTOR, 5,
		CREATURE_PSYCHOLOGIST, 1,
		CREATURE_NURSE, 5,
		CREATURE_SEWERWORKER, 1,
		CREATURE_COLLEGESTUDENT, 30,
		CREATURE_MUSICIAN, 5,
		CREATURE_MATHEMATICIAN, 5,
		CREATURE_TEACHER, 5,
		CREATURE_HSDROPOUT, 1,
		CREATURE_BUM, 1,
		CREATURE_GANGMEMBER, 1,
		CREATURE_CRACKHEAD, 1,
		CREATURE_PRIEST, 1,
		CREATURE_ENGINEER, 5,
		CREATURE_FASTFOODWORKER, 5,
		CREATURE_BAKER, 1,
		CREATURE_BARISTA, 10,
		CREATURE_BARTENDER, 1,
		CREATURE_TELEMARKETER, 5,
		CREATURE_CARSALESMAN, 3,
		CREATURE_OFFICEWORKER, 10,
		CREATURE_FOOTBALLCOACH, 1,
		CREATURE_PROSTITUTE, 1,
		CREATURE_MAILMAN, 1,
		CREATURE_GARBAGEMAN, 1,
		CREATURE_PLUMBER, 1,
		CREATURE_CHEF, 1,
		CREATURE_CONSTRUCTIONWORKER, 3,
		CREATURE_AMATEURMAGICIAN, 1,
		CREATURE_MERC, 1,
		CREATURE_SOLDIER, 1,
		CREATURE_VETERAN, 3,
		CREATURE_HIPPIE, 1,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_SOCIALITE, 1,
		CREATURE_BIKER, 1,
		CREATURE_TRUCKER, 1,
		CREATURE_TAXIDRIVER, 1,
		CREATURE_PROGRAMMER, 5,
		CREATURE_RETIREE, 3,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_CAMERAMAN, 1,
		CREATURE_HAIRSTYLIST, 1,
		CREATURE_FASHIONDESIGNER, 1,
		CREATURE_CLERK, 1,
		CREATURE_THIEF, 1,
		CREATURE_ACTOR, 1,
		CREATURE_YOGAINSTRUCTOR, 1,
		CREATURE_MARTIALARTIST, 1,
		CREATURE_ATHLETE, 1,
		CREATURE_FIREFIGHTER, 1,
		CREATURE_LOCKSMITH, 1 }
		),
	map<int, vector<int> >::value_type(SITE_BUSINESS_VEGANCOOP, {
		CREATURE_TEENAGER, 5,
		CREATURE_JUDGE_LIBERAL, 1,
		CREATURE_COLLEGESTUDENT, 50,
		CREATURE_MUSICIAN, 20,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_TEACHER, 1,
		CREATURE_HSDROPOUT, 10,
		CREATURE_BUM, 1,
		CREATURE_HIPPIE, 50,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_RETIREE, 1,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_YOGAINSTRUCTOR, 2 }
		),
	map<int, vector<int> >::value_type(SITE_BUSINESS_INTERNETCAFE, {
		CREATURE_SCIENTIST_LABTECH, 5,
		CREATURE_CORPORATE_MANAGER, 3,
		CREATURE_TEENAGER, 15,
		CREATURE_LAWYER, 3,
		CREATURE_COLLEGESTUDENT, 25,
		CREATURE_MUSICIAN, 2,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_TEACHER, 5,
		CREATURE_ENGINEER, 15,
		CREATURE_DOCTOR, 1,
		CREATURE_BARISTA, 10,
		CREATURE_CARSALESMAN, 3,
		CREATURE_OFFICEWORKER, 15,
		CREATURE_WORKER_SECRETARY, 5,
		CREATURE_HIPPIE, 1,
		CREATURE_PROGRAMMER, 15,
		CREATURE_RETIREE, 5,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_CAMERAMAN, 1,
		CREATURE_CLERK, 1,
		CREATURE_LOCKSMITH, 1 }
		),
	map<int, vector<int> >::value_type(SITE_RESIDENTIAL_SHELTER, {
		CREATURE_WORKER_JANITOR, 5,
		CREATURE_TEENAGER, 20,
		CREATURE_MUSICIAN, 3,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_BUM, 200,
		CREATURE_GANGMEMBER, 5,
		CREATURE_CRACKHEAD, 50,
		CREATURE_PROSTITUTE, 10,
		CREATURE_AMATEURMAGICIAN, 1,
		CREATURE_HIPPIE, 1,
		CREATURE_NURSE, 5,
		CREATURE_BIKER, 1,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_THIEF, 5,
		CREATURE_ACTOR, 1, }
		),
	map<int, vector<int> >::value_type(SITE_RESIDENTIAL_TENEMENT, {
		CREATURE_SECURITYGUARD, 1,
		CREATURE_SCIENTIST_LABTECH, 1,
		CREATURE_WORKER_JANITOR, 3,
		CREATURE_WORKER_SECRETARY, 2,
		CREATURE_TEENAGER, 5,
		CREATURE_SEWERWORKER, 1,
		CREATURE_COLLEGESTUDENT, 1,
		CREATURE_MUSICIAN, 1,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_TEACHER, 1,
		CREATURE_HSDROPOUT, 3,
		CREATURE_BUM, 3,
		CREATURE_GANGMEMBER, 3,
		CREATURE_CRACKHEAD, 3,
		CREATURE_FASTFOODWORKER, 1,
		CREATURE_BARISTA, 1,
		CREATURE_BARTENDER, 1,
		CREATURE_TELEMARKETER, 1,
		CREATURE_CARSALESMAN, 1,
		CREATURE_OFFICEWORKER, 1,
		CREATURE_PROSTITUTE, 3,
		CREATURE_MAILMAN, 1,
		CREATURE_GARBAGEMAN, 1,
		CREATURE_CONSTRUCTIONWORKER, 1,
		CREATURE_AMATEURMAGICIAN, 1,
		CREATURE_HICK, 1,
		CREATURE_SOLDIER, 1,
		CREATURE_VETERAN, 2,
		CREATURE_HIPPIE, 1,
		CREATURE_BIKER, 1,
		CREATURE_TAXIDRIVER, 1,
		CREATURE_RETIREE, 1,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_HAIRSTYLIST, 1,
		CREATURE_CLERK, 1,
		CREATURE_THIEF, 1,
		CREATURE_ACTOR, 1,
		CREATURE_FIREFIGHTER, 1,
		CREATURE_LOCKSMITH, 1 }
		),
	map<int, vector<int> >::value_type(SITE_RESIDENTIAL_APARTMENT, {

		CREATURE_SECURITYGUARD, 1,
		CREATURE_SCIENTIST_LABTECH, 1,
		CREATURE_CORPORATE_MANAGER, 1,
		CREATURE_WORKER_JANITOR, 1,
		CREATURE_WORKER_SECRETARY, 1,
		CREATURE_TEENAGER, 3,
		CREATURE_COP, 1,
		CREATURE_LAWYER, 1,
		CREATURE_SEWERWORKER, 1,
		CREATURE_COLLEGESTUDENT, 1,
		CREATURE_MUSICIAN, 1,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_TEACHER, 1,
		CREATURE_PRIEST, 1,
		CREATURE_ENGINEER, 1,
		CREATURE_FASTFOODWORKER, 1,
		CREATURE_BAKER, 1,
		CREATURE_BARISTA, 1,
		CREATURE_BARTENDER, 1,
		CREATURE_TELEMARKETER, 1,
		CREATURE_CARSALESMAN, 1,
		CREATURE_OFFICEWORKER, 1,
		CREATURE_FOOTBALLCOACH, 1,
		CREATURE_MAILMAN, 1,
		CREATURE_DOCTOR, 1,
		CREATURE_PSYCHOLOGIST, 1,
		CREATURE_NURSE, 1,
		CREATURE_GARBAGEMAN, 1,
		CREATURE_PLUMBER, 1,
		CREATURE_CHEF, 1,
		CREATURE_CONSTRUCTIONWORKER, 1,
		CREATURE_AMATEURMAGICIAN, 1,
		CREATURE_SOLDIER, 1,
		CREATURE_VETERAN, 2,
		CREATURE_HIPPIE, 1,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_TAXIDRIVER, 1,
		CREATURE_PROGRAMMER, 1,
		CREATURE_RETIREE, 1,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_CAMERAMAN, 1,
		CREATURE_HAIRSTYLIST, 1,
		CREATURE_CLERK, 1,
		CREATURE_THIEF, 1,
		CREATURE_ACTOR, 1,
		CREATURE_YOGAINSTRUCTOR, 1,
		CREATURE_MARTIALARTIST, 1,
		CREATURE_ATHLETE, 1,
		CREATURE_FIREFIGHTER, 1,
		CREATURE_LOCKSMITH, 1 }
		),
	map<int, vector<int> >::value_type(SITE_RESIDENTIAL_APARTMENT_UPSCALE, {
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_CORPORATE_MANAGER, 5,
		CREATURE_WORKER_JANITOR, 5,
		CREATURE_WORKER_SECRETARY, 1,
		CREATURE_TEENAGER, 3,
		CREATURE_JUDGE_LIBERAL, 1,
		CREATURE_JUDGE_CONSERVATIVE, 1,
		CREATURE_RADIOPERSONALITY, 1,
		CREATURE_NEWSANCHOR, 1,
		CREATURE_LAWYER, 5,
		CREATURE_DOCTOR, 5,
		CREATURE_PSYCHOLOGIST, 1,
		CREATURE_NURSE, 1,
		CREATURE_COLLEGESTUDENT, 1,
		CREATURE_MUSICIAN, 1,
		CREATURE_PROSTITUTE, 3,
		CREATURE_MAILMAN, 1,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_SOCIALITE, 2,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_FASHIONDESIGNER, 1,
		CREATURE_THIEF, 1,
		CREATURE_ACTOR, 1,
		CREATURE_ATHLETE, 1,
		CREATURE_LOCKSMITH, 1 }
		),
	map<int, vector<int> >::value_type(SITE_LABORATORY_COSMETICS, {
		CREATURE_SCIENTIST_LABTECH, 10,
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_CORPORATE_MANAGER, 1,
		CREATURE_WORKER_JANITOR, 10,
		CREATURE_WORKER_SECRETARY, 10,
		CREATURE_OFFICEWORKER, 10 }
		),
	map<int, vector<int> >::value_type(SITE_INDUSTRY_NUCLEAR, {
		CREATURE_SCIENTIST_LABTECH, 10,
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_CORPORATE_MANAGER, 1,
		CREATURE_WORKER_JANITOR, 10,
		CREATURE_WORKER_SECRETARY, 10,
		CREATURE_OFFICEWORKER, 10 }
		),
	map<int, vector<int> >::value_type(SITE_LABORATORY_GENETIC, {
		CREATURE_SCIENTIST_LABTECH, 10,
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_CORPORATE_MANAGER, 1,
		CREATURE_DOCTOR, 1,
		CREATURE_WORKER_JANITOR, 10,
		CREATURE_WORKER_SECRETARY, 10,
		CREATURE_OFFICEWORKER, 10 }
		),
	map<int, vector<int> >::value_type(SITE_GOVERNMENT_POLICESTATION, {
		CREATURE_SCIENTIST_LABTECH, 1,
		CREATURE_CORPORATE_MANAGER, 1,
		CREATURE_WORKER_JANITOR, 50,
		CREATURE_WORKER_SECRETARY, 1,
		CREATURE_TEENAGER, 5,
		CREATURE_JUDGE_LIBERAL, 1,
		CREATURE_JUDGE_CONSERVATIVE, 1,
		CREATURE_AGENT, 1,
		CREATURE_RADIOPERSONALITY, 1,
		CREATURE_NEWSANCHOR, 1,
		CREATURE_MILITARYOFFICER, 1,
		CREATURE_LAWYER, 1,
		CREATURE_DOCTOR, 1,
		CREATURE_PSYCHOLOGIST, 1,
		CREATURE_NURSE, 1,
		CREATURE_SEWERWORKER, 1,
		CREATURE_COLLEGESTUDENT, 1,
		CREATURE_MUSICIAN, 1,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_TEACHER, 1,
		CREATURE_HSDROPOUT, 10,
		CREATURE_BUM, 10,
		CREATURE_GANGMEMBER, 10,
		CREATURE_CRACKHEAD, 10,
		CREATURE_PRIEST, 5,
		CREATURE_ENGINEER, 1,
		CREATURE_FASTFOODWORKER, 1,
		CREATURE_BAKER, 1,
		CREATURE_BARISTA, 1,
		CREATURE_BARTENDER, 1,
		CREATURE_TELEMARKETER, 1,
		CREATURE_CARSALESMAN, 1,
		CREATURE_OFFICEWORKER, 1,
		CREATURE_FOOTBALLCOACH, 1,
		CREATURE_PROSTITUTE, 10,
		CREATURE_MAILMAN, 1,
		CREATURE_GARBAGEMAN, 1,
		CREATURE_PLUMBER, 1,
		CREATURE_CHEF, 1,
		CREATURE_CONSTRUCTIONWORKER, 1,
		CREATURE_AMATEURMAGICIAN, 1,
		CREATURE_HICK, 1,
		CREATURE_SOLDIER, 1,
		CREATURE_VETERAN, 2,
		CREATURE_HIPPIE, 1,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_SOCIALITE, 1,
		CREATURE_BIKER, 5,
		CREATURE_TRUCKER, 1,
		CREATURE_TAXIDRIVER, 1,
		CREATURE_PROGRAMMER, 1,
		CREATURE_NUN, 1,
		CREATURE_RETIREE, 1,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_CAMERAMAN, 1,
		CREATURE_HAIRSTYLIST, 1,
		CREATURE_FASHIONDESIGNER, 1,
		CREATURE_CLERK, 1,
		CREATURE_THIEF, 10,
		CREATURE_ACTOR, 1,
		CREATURE_YOGAINSTRUCTOR, 1,
		CREATURE_MARTIALARTIST, 1,
		CREATURE_ATHLETE, 1,
		//CREATURE_FIREFIGHTER]+=1,
		CREATURE_LOCKSMITH, 5 }       //Forensic locksmiths
		),
	map<int, vector<int> >::value_type(SITE_GOVERNMENT_COURTHOUSE, {
		CREATURE_SCIENTIST_LABTECH, 1,
		CREATURE_SCIENTIST_EMINENT, 1,
		CREATURE_CORPORATE_MANAGER, 1,
		CREATURE_WORKER_JANITOR, 50,
		CREATURE_WORKER_SECRETARY, 50,
		CREATURE_TEENAGER, 1,
		CREATURE_JUDGE_LIBERAL, 20,
		CREATURE_JUDGE_CONSERVATIVE, 20,
		CREATURE_AGENT, 1,
		CREATURE_RADIOPERSONALITY, 1,
		CREATURE_NEWSANCHOR, 1,
		CREATURE_MILITARYOFFICER, 1,
		CREATURE_LAWYER, 200,
		CREATURE_PSYCHOLOGIST, 20,
		CREATURE_SEWERWORKER, 1,
		CREATURE_COLLEGESTUDENT, 1,
		CREATURE_MUSICIAN, 1,
		CREATURE_MATHEMATICIAN, 1,
		CREATURE_TEACHER, 1,
		CREATURE_HSDROPOUT, 1,
		CREATURE_BUM, 1,
		CREATURE_GANGMEMBER, 1,
		CREATURE_CRACKHEAD, 1,
		CREATURE_PRIEST, 1,
		CREATURE_ENGINEER, 1,
		CREATURE_FASTFOODWORKER, 1,
		CREATURE_BAKER, 1,
		CREATURE_BARISTA, 1,
		CREATURE_BARTENDER, 1,
		CREATURE_TELEMARKETER, 1,
		CREATURE_CARSALESMAN, 2,
		CREATURE_OFFICEWORKER, 50,
		CREATURE_FOOTBALLCOACH, 1,
		CREATURE_PROSTITUTE, 1,
		CREATURE_MAILMAN, 1,
		CREATURE_GARBAGEMAN, 1,
		CREATURE_PLUMBER, 1,
		CREATURE_CHEF, 1,
		CREATURE_CONSTRUCTIONWORKER, 1,
		CREATURE_AMATEURMAGICIAN, 1,
		CREATURE_HICK, 1,
		CREATURE_SOLDIER, 1,
		CREATURE_VETERAN, 2,
		CREATURE_HIPPIE, 1,
		CREATURE_CRITIC_ART, 1,
		CREATURE_CRITIC_MUSIC, 1,
		CREATURE_AUTHOR, 1,
		CREATURE_JOURNALIST, 1,
		CREATURE_SOCIALITE, 1,
		CREATURE_BIKER, 1,
		CREATURE_TRUCKER, 1,
		CREATURE_TAXIDRIVER, 1,
		CREATURE_PROGRAMMER, 1,
		CREATURE_NUN, 1,
		CREATURE_RETIREE, 1,
		CREATURE_PAINTER, 1,
		CREATURE_SCULPTOR, 1,
		CREATURE_DANCER, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_CAMERAMAN, 1,
		CREATURE_HAIRSTYLIST, 1,
		CREATURE_FASHIONDESIGNER, 1,
		CREATURE_CLERK, 1,
		CREATURE_THIEF, 3,
		CREATURE_ACTOR, 1,
		CREATURE_YOGAINSTRUCTOR, 1,
		CREATURE_MARTIALARTIST, 1,
		CREATURE_ATHLETE, 1,
		//CREATURE_FIREFIGHTER]+=1,
		CREATURE_LOCKSMITH, 5 }
		),
	map<int, vector<int> >::value_type(SITE_GOVERNMENT_FIRESTATION, {
		CREATURE_WORKER_JANITOR, 5,
		CREATURE_WORKER_SECRETARY, 2,
		CREATURE_NURSE, 2,
		CREATURE_PRIEST, 5,
		CREATURE_JOURNALIST, 1,
		CREATURE_PHOTOGRAPHER, 1,
		CREATURE_FIREFIGHTER, 100 }
		),
	map<int, vector<int> >::value_type(SITE_GOVERNMENT_INTELLIGENCEHQ, {
		CREATURE_WORKER_JANITOR, 50,
		CREATURE_WORKER_SECRETARY, 50,
		CREATURE_GUARDDOG, 50,
		CREATURE_MATHEMATICIAN, 5,
		CREATURE_PROGRAMMER, 5,
		CREATURE_MILITARYOFFICER, 5 }


		),
	map<int, vector<int> >::value_type(SITE_GOVERNMENT_ARMYBASE, {
		CREATURE_SOLDIER, 750,
		CREATURE_GUARDDOG, 20,
		CREATURE_MILITARYPOLICE, 100,
		CREATURE_MILITARYOFFICER, 20,
		CREATURE_SEAL, 20 }


		),
	map<int, vector<int> >::value_type(SITE_INDUSTRY_SWEATSHOP, {
		CREATURE_CORPORATE_MANAGER, 5,
		CREATURE_WORKER_SWEATSHOP, 800 }

		),
	map<int, vector<int> >::value_type(SITE_INDUSTRY_POLLUTER, {
		CREATURE_CORPORATE_MANAGER, 1,
		CREATURE_WORKER_JANITOR, 10,
		CREATURE_WORKER_SECRETARY, 10 }
		),
	map<int, vector<int> >::value_type(SITE_CORPORATE_HEADQUARTERS, {

		CREATURE_CORPORATE_MANAGER, 20,
		CREATURE_WORKER_JANITOR, 20,
		CREATURE_WORKER_SECRETARY, 40,
		CREATURE_JUDGE_CONSERVATIVE, 1,
		CREATURE_LAWYER, 20,
		CREATURE_PRIEST, 1,
		CREATURE_OFFICEWORKER, 80,
		CREATURE_PROSTITUTE, 1 }


		),
	map<int, vector<int> >::value_type(SITE_CORPORATE_HOUSE, {
		CREATURE_WORKER_SERVANT, 30,
		CREATURE_WORKER_SECRETARY, 5,
		CREATURE_TEENAGER, 5,
		CREATURE_GENETIC, 1,
		CREATURE_LAWYER, 5,
		CREATURE_PRIEST, 1,
		CREATURE_PROSTITUTE, 1 }

		),
	map<int, vector<int> >::value_type(SITE_MEDIA_AMRADIO, {
		CREATURE_CORPORATE_MANAGER, 2,
		CREATURE_WORKER_JANITOR, 10,
		CREATURE_WORKER_SECRETARY, 10,
		CREATURE_RADIOPERSONALITY, 2,
		CREATURE_ENGINEER, 20,
		CREATURE_OFFICEWORKER, 40 }


		),
	map<int, vector<int> >::value_type(SITE_MEDIA_CABLENEWS, {
		CREATURE_CORPORATE_MANAGER, 5,
		CREATURE_WORKER_JANITOR, 20,
		CREATURE_WORKER_SECRETARY, 20,
		CREATURE_NEWSANCHOR, 2,
		CREATURE_ENGINEER, 40,
		CREATURE_OFFICEWORKER, 40,
		CREATURE_PHOTOGRAPHER, 5,
		CREATURE_CAMERAMAN, 5 }

		)
};
void addCCS(int creaturearray[CREATURENUM]) {
	creaturearray[CREATURE_CCS_VIGILANTE] += 50;
	//creaturearray[CREATURE_CCS_ARCHCONSERVATIVE]+=endgamestate;
	creaturearray[CREATURE_PROSTITUTE] += 5;
	creaturearray[CREATURE_CRACKHEAD] += 5;
	creaturearray[CREATURE_PRIEST] += 5;
	creaturearray[CREATURE_RADIOPERSONALITY] += 1;

}
void addCrackhouse(int creaturearray[CREATURENUM]) {
	extern char endgamestate;
	extern short lawList[LAWNUM];

	if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_POLLUTION] == -2 &&
		lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 50;
	if (endgamestate<ENDGAME_CCS_DEFEATED && endgamestate>ENDGAME_NONE)
		creaturearray[CREATURE_CCS_VIGILANTE] += 5;
}
void addCigarbar(int creaturearray[CREATURENUM], const char sec) {
	extern char endgamestate;
	extern short sitealarm;
	extern short lawList[LAWNUM];
	if (sec || sitealarm == 1)creaturearray[CREATURE_BOUNCER] += 100;
	else creaturearray[CREATURE_BOUNCER] += 10;
	if (sec)creaturearray[CREATURE_GUARDDOG] += 25;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] += 2;
	if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] += 2;
	if (endgamestate<ENDGAME_CCS_DEFEATED && endgamestate>ENDGAME_NONE)
		creaturearray[CREATURE_CCS_VIGILANTE] += 5;

}
void addWhitehouse(int creaturearray[CREATURENUM], const char sec) {

	extern char endgamestate;
	extern short exec[EXECNUM];


	if (sec)creaturearray[CREATURE_SECRET_SERVICE] += 100;
	else creaturearray[CREATURE_SECRET_SERVICE] += 5;
	if (endgamestate<ENDGAME_CCS_DEFEATED && endgamestate>ENDGAME_NONE && exec[EXEC_PRESIDENT] < ALIGN_CONSERVATIVE)
		creaturearray[CREATURE_CCS_ARCHCONSERVATIVE] += 1;
}
void addLatteStandOrPark(int creaturearray[CREATURENUM]) {
	extern short lawList[LAWNUM];
	extern char endgamestate;



	if (lawList[LAW_LABOR] < 2)creaturearray[CREATURE_WORKER_FACTORY_NONUNION] += 5;
	if (lawList[LAW_LABOR] >= 0)creaturearray[CREATURE_WORKER_FACTORY_UNION] += 5;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] += 2;
	if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] += 2;
	if (endgamestate<ENDGAME_CCS_DEFEATED && endgamestate>ENDGAME_NONE)
		creaturearray[CREATURE_CCS_VIGILANTE] += endgamestate * 4;
	if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 1;
	if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 1;
	if (lawList[LAW_POLLUTION] == -2 &&
		lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] += 1;
	else creaturearray[CREATURE_PRISONGUARD] += 1;
}
void addVeganCoop(int creaturearray[CREATURENUM]) {
	extern short lawList[LAWNUM];



	if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 1;
	if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 1;
	if (lawList[LAW_POLLUTION] == -2 &&
		lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
}

void addShelter(int creaturearray[CREATURENUM]) {
	extern short lawList[LAWNUM];



	if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_POLLUTION] == -2 &&
		lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 50;
}
void addTenement(int creaturearray[CREATURENUM]) {
	extern short lawList[LAWNUM];



	if (lawList[LAW_LABOR] < 2)creaturearray[CREATURE_WORKER_FACTORY_NONUNION] += 1;
	if (lawList[LAW_LABOR] >= 0)creaturearray[CREATURE_WORKER_FACTORY_UNION] += 1;
	if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_POLLUTION] == -2 &&
		lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 5;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] += 1;
	else creaturearray[CREATURE_PRISONGUARD] += 1;
}
void addApartment(int creaturearray[CREATURENUM]) {
	extern short lawList[LAWNUM];


	if (lawList[LAW_LABOR] < 2)creaturearray[CREATURE_WORKER_FACTORY_NONUNION] = 1;
	if (lawList[LAW_LABOR] >= 0)creaturearray[CREATURE_WORKER_FACTORY_UNION] = 1;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] += 1;
	if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] += 1;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] += 1;
	else creaturearray[CREATURE_PRISONGUARD] += 1;
}
void addBank(int creaturearray[CREATURENUM], const char sec) {
	extern short mode;
	extern int locx;
	extern int locy;
	extern int locz;
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	extern short lawList[LAWNUM];
	if (mode == GAMEMODE_SITE && !(levelmap[locx][locy][locz].flag & SITEBLOCK_RESTRICTED))
	{
		creaturearray[CREATURE_BANK_MANAGER] = 20;
		creaturearray[CREATURE_SCIENTIST_LABTECH] = 1;
		creaturearray[CREATURE_WORKER_JANITOR] = 1;
		creaturearray[CREATURE_WORKER_SECRETARY] = 1;
		creaturearray[CREATURE_TEENAGER] = 3;
		creaturearray[CREATURE_COP] += 1;
		creaturearray[CREATURE_LAWYER] = 1;
		creaturearray[CREATURE_SEWERWORKER] = 1;
		creaturearray[CREATURE_COLLEGESTUDENT] = 1;
		creaturearray[CREATURE_MUSICIAN] = 1;
		creaturearray[CREATURE_MATHEMATICIAN] = 1;
		creaturearray[CREATURE_TEACHER] = 1;
		creaturearray[CREATURE_PRIEST] = 1;
		creaturearray[CREATURE_ENGINEER] = 1;
		creaturearray[CREATURE_FASTFOODWORKER] = 1;
		creaturearray[CREATURE_BAKER] = 1;
		creaturearray[CREATURE_BARISTA] = 1;
		creaturearray[CREATURE_BARTENDER] = 1;
		creaturearray[CREATURE_TELEMARKETER] = 1;
		creaturearray[CREATURE_CARSALESMAN] = 1;
		creaturearray[CREATURE_OFFICEWORKER] = 1;
		creaturearray[CREATURE_FOOTBALLCOACH] = 1;
		creaturearray[CREATURE_MAILMAN] = 1;
		creaturearray[CREATURE_DOCTOR] = 1;
		creaturearray[CREATURE_PSYCHOLOGIST] += 1;
		creaturearray[CREATURE_NURSE] = 1;
		creaturearray[CREATURE_GARBAGEMAN] = 1;
		creaturearray[CREATURE_PLUMBER] = 1;
		creaturearray[CREATURE_CHEF] = 1;
		creaturearray[CREATURE_CONSTRUCTIONWORKER] = 1;
		creaturearray[CREATURE_AMATEURMAGICIAN] = 1;
		creaturearray[CREATURE_SOLDIER] = 1;
		creaturearray[CREATURE_VETERAN] = 2;
		creaturearray[CREATURE_HIPPIE] = 1;
		creaturearray[CREATURE_CRITIC_ART] = 1;
		creaturearray[CREATURE_CRITIC_MUSIC] = 1;
		creaturearray[CREATURE_AUTHOR] = 1;
		creaturearray[CREATURE_JOURNALIST] = 1;
		creaturearray[CREATURE_TAXIDRIVER] = 1;
		creaturearray[CREATURE_PROGRAMMER] = 1;
		creaturearray[CREATURE_RETIREE] = 1;
		creaturearray[CREATURE_PAINTER] = 1;
		creaturearray[CREATURE_SCULPTOR] = 1;
		creaturearray[CREATURE_DANCER] = 1;
		creaturearray[CREATURE_PHOTOGRAPHER] = 1;
		creaturearray[CREATURE_CAMERAMAN] = 1;
		creaturearray[CREATURE_HAIRSTYLIST] = 1;
		creaturearray[CREATURE_CLERK] = 1;
		creaturearray[CREATURE_THIEF] = 1;
		creaturearray[CREATURE_ACTOR] = 1;
		creaturearray[CREATURE_YOGAINSTRUCTOR] = 1;
		creaturearray[CREATURE_MARTIALARTIST] += 1;
		creaturearray[CREATURE_ATHLETE] = 1;
		creaturearray[CREATURE_FIREFIGHTER] += 1;
		creaturearray[CREATURE_LOCKSMITH] += 1;


		if (sec) creaturearray[CREATURE_MERC] = 100;
		else creaturearray[CREATURE_SECURITYGUARD] = 50;
		if (lawList[LAW_LABOR] < 2)creaturearray[CREATURE_WORKER_FACTORY_NONUNION] = 1;
		if (lawList[LAW_LABOR] >= 0)creaturearray[CREATURE_WORKER_FACTORY_UNION] = 1;
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] += 1;
		if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] += 1;
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] += 1;
		else creaturearray[CREATURE_PRISONGUARD] += 1;
	}
	else
	{
		creaturearray[CREATURE_BANK_MANAGER] = 200;
		creaturearray[CREATURE_THIEF] = 1;


		if (sec) creaturearray[CREATURE_MERC] = 2000;
		else creaturearray[CREATURE_SECURITYGUARD] = 1000;
	}
}
void addUpscaleApartment(int creaturearray[CREATURENUM], const char sec) {
	extern short mode;
	extern int locx;
	extern int locy;
	extern int locz;
	extern short lawList[LAWNUM];
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];



	if (mode == GAMEMODE_SITE && !(levelmap[locx][locy][locz].flag & SITEBLOCK_RESTRICTED))
	{
		if (sec)creaturearray[CREATURE_SECURITYGUARD] += 100;
		else creaturearray[CREATURE_SECURITYGUARD] += 10;
		if (sec)creaturearray[CREATURE_GUARDDOG] += 50;
	}
	else if (mode == GAMEMODE_SITE && sec)
	{
		//inside someone's room when security is high. Might meet a policeman.
		if (lawList[LAW_DEATHPENALTY] == -2 && lawList[LAW_POLICEBEHAVIOR] == -2)
			creaturearray[CREATURE_DEATHSQUAD] += 5;
		if (lawList[LAW_POLICEBEHAVIOR] <= -1)
			creaturearray[CREATURE_GANGUNIT] += 10;
		creaturearray[CREATURE_COP] += 15;
	}
}
void addLaboratoryCosmetics(int creaturearray[CREATURENUM], const char sec) {


	if (sec)creaturearray[CREATURE_SECURITYGUARD] += 100;
	else creaturearray[CREATURE_SECURITYGUARD] += 3;
}
void addIndustryNuclear(int creaturearray[CREATURENUM], const char sec) {


	if (sec)creaturearray[CREATURE_SECURITYGUARD] += 100;
	else creaturearray[CREATURE_SECURITYGUARD] += 10;
}
void addLaboratoryGenetic(int creaturearray[CREATURENUM], const char sec) {



	if (sec)creaturearray[CREATURE_GUARDDOG] += 25;
	if (sec)creaturearray[CREATURE_SECURITYGUARD] += 100;
	else creaturearray[CREATURE_SECURITYGUARD] += 3;
}
void addPoliceStation(int creaturearray[CREATURENUM], const char sec) {
	extern short lawList[LAWNUM];
	


	if (lawList[LAW_LABOR] < 2)creaturearray[CREATURE_WORKER_FACTORY_NONUNION] = 1;
	if (lawList[LAW_LABOR] >= 0)creaturearray[CREATURE_WORKER_FACTORY_UNION] = 1;
	if (sec)creaturearray[CREATURE_COP] += 1000;
	else creaturearray[CREATURE_COP] += 500;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] += 400;
	if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] += 400;
	if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_POLLUTION] == -2 &&
		lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 5;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] = 1;
	else creaturearray[CREATURE_PRISONGUARD] = 1;
}
void addCourthouse(int creaturearray[CREATURENUM], const char sec) {

	extern short lawList[LAWNUM];


	if (sec)creaturearray[CREATURE_COP] = 2000;
	else creaturearray[CREATURE_COP] = 200;
	if (lawList[LAW_LABOR] < 2)creaturearray[CREATURE_WORKER_FACTORY_NONUNION] = 1;
	if (lawList[LAW_LABOR] >= 0)creaturearray[CREATURE_WORKER_FACTORY_UNION] = 1;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] = 80;
	if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] = 80;
	if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 1;
	if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 1;
	if (lawList[LAW_POLLUTION] == -2 &&
		lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
	if (lawList[LAW_DEATHPENALTY] == -2 &&
		lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] = 1;
	else creaturearray[CREATURE_PRISONGUARD] = 1;
}
void addFirestation(int creaturearray[CREATURENUM], const char sec) {


	extern short lawList[LAWNUM];

	if (sec)
	{
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] += 50;
		else if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] += 50;
		else creaturearray[CREATURE_COP] += 50;
	}
}
void addPrison(int creaturearray[CREATURENUM], const char sec) {
	extern int locx;
	extern int locy;
	extern int locz;
	extern short lawList[LAWNUM];
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];

	if (levelmap[locx][locy][locz].flag & SITEBLOCK_RESTRICTED)
		creaturearray[CREATURE_PRISONER] = 8; // prisoners only in restricted areas
	if (sec)
	{
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] += 3;
		else creaturearray[CREATURE_PRISONGUARD] += 3;
	}
	else
	{
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] += 2;
		else creaturearray[CREATURE_PRISONGUARD] += 2;
	}
}
void addIntelligence(int creaturearray[CREATURENUM], const char sec) {


	if (sec)creaturearray[CREATURE_AGENT] += 1000;
	else creaturearray[CREATURE_AGENT] += 100;
	if (sec)creaturearray[CREATURE_GUARDDOG] += 450;

}
void addArmyBase(int creaturearray[CREATURENUM], const char sec) {

	if (sec)creaturearray[CREATURE_GUARDDOG] += 230;
	if (sec)creaturearray[CREATURE_MILITARYPOLICE] += 100;
}
void addSweatShop(int creaturearray[CREATURENUM], const char sec) {


	if (sec)creaturearray[CREATURE_SECURITYGUARD] += 1000;
	else creaturearray[CREATURE_SECURITYGUARD] += 100;
}
void addIndustryPolluter(int creaturearray[CREATURENUM], const char sec) {
	extern short lawList[LAWNUM];
	if (sec)creaturearray[CREATURE_SECURITYGUARD] += 100;

	if (lawList[LAW_LABOR] == -2)
	{
		creaturearray[CREATURE_WORKER_FACTORY_NONUNION] += 20;
		creaturearray[CREATURE_WORKER_FACTORY_CHILD] += 140;
	}
	else if (lawList[LAW_LABOR] == -1)
	{
		creaturearray[CREATURE_WORKER_FACTORY_NONUNION] += 160;
		creaturearray[CREATURE_WORKER_FACTORY_CHILD] += 1;
	}
	else if (lawList[LAW_LABOR] == 0)
	{
		creaturearray[CREATURE_WORKER_FACTORY_NONUNION] += 80;
		creaturearray[CREATURE_WORKER_FACTORY_UNION] += 80;
	}
	else if (lawList[LAW_LABOR] == 1)
	{
		creaturearray[CREATURE_WORKER_FACTORY_NONUNION] = 50;
		creaturearray[CREATURE_WORKER_FACTORY_UNION] = 110;
	}
	else creaturearray[CREATURE_WORKER_FACTORY_UNION] = 160;
}
void addCorpHQ(int creaturearray[CREATURENUM], const char sec) {

	if (sec)creaturearray[CREATURE_GUARDDOG] += 100;
	if (sec)creaturearray[CREATURE_SECURITYGUARD] = 400;
	else creaturearray[CREATURE_SECURITYGUARD] = 40;
}
void addCorpHouse(int creaturearray[CREATURENUM], const char sec) {



	if (sec)creaturearray[CREATURE_MERC] = 100;
	if (sec)creaturearray[CREATURE_GUARDDOG] = 50;
	else creaturearray[CREATURE_GUARDDOG] = 5;
}
void addMediaAMRadio(int creaturearray[CREATURENUM], const char sec) {


	if (sec)creaturearray[CREATURE_SECURITYGUARD] = 100;
	else creaturearray[CREATURE_SECURITYGUARD] = 10;
}
void addMediaCablenews(int creaturearray[CREATURENUM], const char sec) {

	if (sec)creaturearray[CREATURE_SECURITYGUARD] = 100;
	else creaturearray[CREATURE_SECURITYGUARD] = 10;

}
/* generates a new random encounter */
void prepareencounter(short type, char sec)
{
	extern short mode;
	extern int locx;
	extern int locy;
	extern int locz;
	extern short postalarmtimer;
	extern short cursite;
	extern Creature encounter[ENCMAX];
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	int encslot = 0;
	emptyEncounter();
	int creaturearray[CREATURENUM];
	memset(creaturearray, 0, CREATURENUM*sizeof(int));
	if (postalarmtimer > 80)
	{
		addPoliceOrMilitary(creaturearray);
	}
	if (LocationsPool::getInstance().getRentingType(cursite) == RENTING_CCS)
	{
		addCCS(creaturearray);
		for (int n = 0; n < LCSrandom(6) + 1; n++)
		{
			makecreature(encounter[encslot], getrandomcreaturetype(creaturearray));
			conservatise(encounter[encslot]);
			encslot++;
		}
	}
	else
	{
		if (type != SITE_BUSINESS_BANK && type != SITE_GOVERNMENT_PRISON) {
			for (int i = 0; i < len(locationsSpawners[type]); i += 2) {
				creaturearray[locationsSpawners[type][i]] += locationsSpawners[type][i + 1];
			}
		}
		int encnum = 6;
		const int variableEncnum = mode == GAMEMODE_SITE && !(levelmap[locx][locy][locz].flag & SITEBLOCK_RESTRICTED) ? 4 : 1;
		switch (type)
		{
		case SITE_BUSINESS_CRACKHOUSE:
		{
			addCrackhouse(creaturearray);
			break;
		}
		case SITE_BUSINESS_JUICEBAR:
		{
			break;
		}
		case SITE_BUSINESS_CIGARBAR:
		{
			addCigarbar(creaturearray, sec);
			break;
		}
		case SITE_GOVERNMENT_WHITE_HOUSE:
		{
			addWhitehouse(creaturearray, sec);
			break;
		}
		case SITE_OUTDOOR_PUBLICPARK:
		case SITE_BUSINESS_LATTESTAND:
		{
			addLatteStandOrPark(creaturearray);
			break;
		}
		case SITE_BUSINESS_VEGANCOOP:
		{
			addVeganCoop(creaturearray);
			break;
		}
		case SITE_BUSINESS_INTERNETCAFE:
		{
			break;
		}
		default:
		case SITE_RESIDENTIAL_SHELTER:
		{
			addShelter(creaturearray);
			break;
		}
		case SITE_RESIDENTIAL_TENEMENT:
		{
			addTenement(creaturearray);
			encnum = variableEncnum;
			break;
		}
		case SITE_RESIDENTIAL_APARTMENT:
		{
			addApartment(creaturearray);
			encnum = variableEncnum;
			break;
		}
		case SITE_BUSINESS_BANK:
		{
			addBank(creaturearray, sec);
			encnum = variableEncnum;
			break;
		}
		case SITE_RESIDENTIAL_APARTMENT_UPSCALE:
		{
			addUpscaleApartment(creaturearray, sec);
			encnum = variableEncnum;
			break;
		}
		case SITE_LABORATORY_COSMETICS:
		{
			addLaboratoryCosmetics(creaturearray, sec);
			break;
		}
		case SITE_INDUSTRY_NUCLEAR:
		{
			addIndustryNuclear(creaturearray, sec);
			break;
		}
		case SITE_LABORATORY_GENETIC:
		{
			addLaboratoryGenetic(creaturearray, sec);
			break;
		}
		case SITE_GOVERNMENT_POLICESTATION:
		{
			addPoliceStation(creaturearray, sec);
			break;
		}
		case SITE_GOVERNMENT_COURTHOUSE:
		{
			addCourthouse(creaturearray, sec);
			break;
		}
		case SITE_GOVERNMENT_FIRESTATION:
		{
			addFirestation(creaturearray, sec);
			break;
		}
		case SITE_GOVERNMENT_PRISON:
		{
			addPrison(creaturearray, sec);
			break;
		}
		case SITE_GOVERNMENT_INTELLIGENCEHQ:
		{
			addIntelligence(creaturearray, sec);
			break;
		}
		case SITE_GOVERNMENT_ARMYBASE:
		{
			addArmyBase(creaturearray, sec);
			break;
		}
		case SITE_INDUSTRY_SWEATSHOP:
		{
			addSweatShop(creaturearray, sec);
			break;
		}
		case SITE_INDUSTRY_POLLUTER:
		{
			addIndustryPolluter(creaturearray, sec);
			break;
		}
		case SITE_CORPORATE_HEADQUARTERS:
		{
			addCorpHQ(creaturearray, sec);
			break;
		}
		case SITE_CORPORATE_HOUSE:
		{
			addCorpHouse(creaturearray, sec);
			break;
		}
		case SITE_MEDIA_AMRADIO:
		{
			addMediaAMRadio(creaturearray, sec);
			break;
		}
		case SITE_MEDIA_CABLENEWS:
		{
			addMediaCablenews(creaturearray, sec);
			break;
		}
		}

		for (int n = 0; n < LCSrandom(encnum) + 1; n++)
		{
			makecreature(encounter[encslot], getrandomcreaturetype(creaturearray));
			encslot++;
		}
	}
}
/* generates a new siege encounter */
char addsiegeencounter(char type)
{
	extern short sitetype;
	extern short cursite;
	extern short lawList[LAWNUM];
	extern Creature encounter[ENCMAX];
	int num;
	int freeslots = 0;
	for (int e = 0; e < ENCMAX; e++)
	{
		if (!encounter[e].exists)freeslots++;
	}
	switch (type)
	{
	case SIEGEFLAG_UNIT:
	case SIEGEFLAG_UNIT_DAMAGED:
	{
		if (freeslots < 6)return 0;
		num = LCSrandom(3) + 4;
		if (LocationsPool::getInstance().isThereASiegeHere(cursite))
		{
			switch (LocationsPool::getInstance().getSiegeType(cursite))
			{
			case SIEGE_POLICE:
				if (LocationsPool::getInstance().getSiegeEscalationState(cursite) == 0)
					fillEncounter(CREATURE_SWAT, num);
				else
				{
					if (LocationsPool::getInstance().getSiegeEscalationState(cursite) < 3) fillEncounter(CREATURE_SOLDIER, num);
					else fillEncounter(CREATURE_SEAL, num);
				}
				break;
			case SIEGE_CIA:
				fillEncounter(CREATURE_AGENT, num);
				break;
			case SIEGE_HICKS:
				fillEncounter(CREATURE_HICK, num);
				break;
			case SIEGE_CORPORATE:
				fillEncounter(CREATURE_MERC, num);
				break;
			case SIEGE_CCS:
				for (int e = 0; e < ENCMAX && num > 0; e++) {
					if (!encounter[e].exists) {
						if (!LCSrandom(12))
							makecreature(encounter[e], CREATURE_CCS_ARCHCONSERVATIVE);
						else if (!LCSrandom(11))
							makecreature(encounter[e], CREATURE_CCS_MOLOTOV);
						else if (!LCSrandom(10))
							makecreature(encounter[e], CREATURE_CCS_SNIPER);
						else makecreature(encounter[e], CREATURE_CCS_VIGILANTE);
						num--;
					}
				}
				break;
			case SIEGE_FIREMEN:
				fillEncounter(CREATURE_FIREFIGHTER, num);
				break;
			}
		}
		else
		{
			switch (sitetype)
			{
			case SITE_GOVERNMENT_ARMYBASE:
				if (!encounter[0].exists && !LCSrandom(2)) {
					makecreature(encounter[0], CREATURE_TANK);
					num--;
				}
				fillEncounter(CREATURE_SOLDIER, num);
				break;
			case SITE_GOVERNMENT_INTELLIGENCEHQ:
				fillEncounter(CREATURE_AGENT, num);
				break;
			case SITE_CORPORATE_HEADQUARTERS:
			case SITE_CORPORATE_HOUSE:
				fillEncounter(CREATURE_MERC, num);
				break;
			case SITE_MEDIA_AMRADIO:
			case SITE_MEDIA_CABLENEWS:
				fillEncounter(CREATURE_HICK, num);
				break;
			case SITE_GOVERNMENT_POLICESTATION:
				if (lawList[LAW_DEATHPENALTY] == -2 &&
					lawList[LAW_POLICEBEHAVIOR] == -2)fillEncounter(CREATURE_DEATHSQUAD, num);
				else fillEncounter(CREATURE_SWAT, num);
				break;
			case SITE_BUSINESS_CRACKHOUSE:
				// TODO this causes all encountered creatures to become conservative, not just the gangmembers
				fillEncounter(CREATURE_GANGMEMBER, num);
				for (int e = 0; e < ENCMAX; e++) {
					if (encounter[e].exists)
						encounter[e].align = ALIGN_CONSERVATIVE;
				}
				break;
			default:
				if (LocationsPool::getInstance().getRentingType(cursite) == RENTING_CCS)
				{
					for (int e = 0; e < ENCMAX && num > 0; e++) {
						if (!LCSrandom(11))
							makecreature(encounter[e], CREATURE_CCS_MOLOTOV);
						else if (!LCSrandom(10))
							makecreature(encounter[e], CREATURE_CCS_SNIPER);
						else makecreature(encounter[e], CREATURE_CCS_VIGILANTE);
						num--;
					}
				}
				else if (lawList[LAW_DEATHPENALTY] == -2 &&
					lawList[LAW_POLICEBEHAVIOR] == -2)fillEncounter(CREATURE_DEATHSQUAD, num);
				else fillEncounter(CREATURE_SWAT, num);
				break;
			}
		}
		// TODO this causes all encountered creatures to be damaged, not just the newly generated ones
		if (type == SIEGEFLAG_UNIT_DAMAGED)
			for (int e = 0; e < ENCMAX; e++) {
				if (encounter[e].exists)
					encounter[e].blood = LCSrandom(75) + 1;
			}
		break;
	}
	case SIEGEFLAG_HEAVYUNIT:
	{
		if (freeslots < 1)return 0;
		num = 1;
		fillEncounter(CREATURE_TANK, num);
		break;
	}
	}
	return 1;
}
