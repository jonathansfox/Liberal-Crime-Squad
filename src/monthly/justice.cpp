#define	JUSTICE_CPP
#include "../includes.h"
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
 /* monthly - sentence a liberal */
 int calculateSentence(CreatureJustice g, const char lenient) {
	 int new_sentence = g.sentence;
	 if (!(new_sentence < 0))
	 {
		 new_sentence += (36 + LCSrandom(18))*g.crimes_suspected[LAWFLAG_KIDNAPPING];
		 new_sentence += (1 + LCSrandom(4))*g.crimes_suspected[LAWFLAG_THEFT];
		 //new_sentence+=(4+LCSrandom(12))*(!!g.crimes_suspected[LAWFLAG_GUNUSE])+ // Extra for first incident only
		 //            (2+LCSrandom(4)*g.crimes_suspected[LAWFLAG_GUNUSE]);      // Generally
		 //new_sentence+=(1+LCSrandom(4))*(!!g.crimes_suspected[LAWFLAG_GUNCARRY]);
		 new_sentence += (6 + LCSrandom(7))*g.crimes_suspected[LAWFLAG_CARTHEFT];
		 new_sentence += (1 + LCSrandom(13))*g.crimes_suspected[LAWFLAG_INFORMATION];
		 new_sentence += (1 + LCSrandom(13))*g.crimes_suspected[LAWFLAG_COMMERCE];
		 new_sentence += (6 + LCSrandom(25))*g.crimes_suspected[LAWFLAG_CCFRAUD];
		 new_sentence += (3 + LCSrandom(12))*g.crimes_suspected[LAWFLAG_BURIAL];
		 new_sentence += (1 + LCSrandom(6))*g.crimes_suspected[LAWFLAG_PROSTITUTION];
		 new_sentence += 1 * g.crimes_suspected[LAWFLAG_DISTURBANCE];
		 new_sentence += 1 * g.crimes_suspected[LAWFLAG_PUBLICNUDITY];
		 //new_sentence+=1*g.crimes_suspected[LAWFLAG_LOITERING];
		 new_sentence += 1 * g.crimes_suspected[LAWFLAG_HIREILLEGAL];
		 new_sentence += (12 + LCSrandom(100))*g.crimes_suspected[LAWFLAG_RACKETEERING];
		 // How illegal is marijuana?
		 if (lawList[LAW_DRUGS] == -2) new_sentence += (3 + LCSrandom(360))*g.crimes_suspected[LAWFLAG_BROWNIES]; //insanely illegal
		 else if (lawList[LAW_DRUGS] == -1) new_sentence += (3 + LCSrandom(120))*g.crimes_suspected[LAWFLAG_BROWNIES]; //very illegal
		 else if (lawList[LAW_DRUGS] == 0) new_sentence += (3 + LCSrandom(12))*g.crimes_suspected[LAWFLAG_BROWNIES]; //moderately illegal
																												   // else not illegal
		 new_sentence += 1 * g.crimes_suspected[LAWFLAG_BREAKING];
		 new_sentence += (60 + LCSrandom(181))*g.crimes_suspected[LAWFLAG_TERRORISM];
		 new_sentence += (30 + LCSrandom(61))*g.crimes_suspected[LAWFLAG_BANKROBBERY];
		 new_sentence += (30 + LCSrandom(61))*g.crimes_suspected[LAWFLAG_JURY];
		 new_sentence += (30 + LCSrandom(61))*g.crimes_suspected[LAWFLAG_HELPESCAPE];
		 new_sentence += (3 + LCSrandom(16))*g.crimes_suspected[LAWFLAG_ESCAPED];
		 new_sentence += (1 + LCSrandom(1))*g.crimes_suspected[LAWFLAG_RESIST];
		 new_sentence += (6 + LCSrandom(1))*g.crimes_suspected[LAWFLAG_EXTORTION];
		 new_sentence += (4 + LCSrandom(3))*g.crimes_suspected[LAWFLAG_SPEECH];
		 new_sentence += 1 * g.crimes_suspected[LAWFLAG_VANDALISM];
		 new_sentence += (12 + LCSrandom(12))*g.crimes_suspected[LAWFLAG_ARSON];
		 new_sentence += (12 + LCSrandom(1))*g.crimes_suspected[LAWFLAG_ARMEDASSAULT];
		 new_sentence += (3 + LCSrandom(1))*g.crimes_suspected[LAWFLAG_ASSAULT];
	 }
	 if (lawList[LAW_FLAGBURNING] == -2)
	 {
		 if (!LCSrandom(2)) new_sentence += (120 + LCSrandom(241))*g.crimes_suspected[LAWFLAG_BURNFLAG];
		 else if (g.crimes_suspected[LAWFLAG_BURNFLAG])new_sentence = -1 * g.crimes_suspected[LAWFLAG_BURNFLAG];
	 }
	 else if (lawList[LAW_FLAGBURNING] == -1) new_sentence += 36 * g.crimes_suspected[LAWFLAG_BURNFLAG];
	 else if (lawList[LAW_FLAGBURNING] == 0) new_sentence += 1 * g.crimes_suspected[LAWFLAG_BURNFLAG];
	 if ((LCSrandom(4) - g.crimes_suspected[LAWFLAG_MURDER]) > 0)
	 {
		 if (!(new_sentence < 0)) new_sentence += (120 + LCSrandom(241))*g.crimes_suspected[LAWFLAG_MURDER];
	 }
	 else
	 {
		 if (new_sentence < 0) new_sentence -= -1 * g.crimes_suspected[LAWFLAG_MURDER];
		 else if (g.crimes_suspected[LAWFLAG_MURDER])
			 new_sentence = -1 * g.crimes_suspected[LAWFLAG_MURDER];
	 }
	 if (new_sentence < 0) new_sentence -= 1 * g.crimes_suspected[LAWFLAG_TREASON];
	 else if (g.crimes_suspected[LAWFLAG_TREASON]) new_sentence = -1 * g.crimes_suspected[LAWFLAG_TREASON];
	 if (lenient&&new_sentence != -1) new_sentence /= 2;
	 if (lenient&&new_sentence == -1) new_sentence = 240 + LCSrandom(120);

	 return new_sentence;
 }

// string counts_of;
// string execution_in_three_months;
 /* monthly - sentence a liberal */
 void penalize(DeprecatedCreature &g, const char lenient)
 {
	 CreatureJustice g_crimes = g.getCreatureJustice();
	 set_color_easy(RED_ON_BLACK_BRIGHT);
	 mvaddstrAlt(3, 1, CONST_justice017, gamelog);
	 gamelog.newline();
	 pressAnyKey();
	 short oldsentence = g.getCreatureJustice().sentence;
	 char olddeathpenalty = g.getCreatureJustice().deathpenalty;
	 g.sentence = 0, g.deathpenalty = 0;
	 if (!lenient && ((g_crimes.crimes_suspected[LAWFLAG_MURDER]) || (g_crimes.crimes_suspected[LAWFLAG_TREASON]) ||
		 ((g_crimes.crimes_suspected[LAWFLAG_BURNFLAG]) && lawList[LAW_FLAGBURNING] == -2) ||
		 lawList[LAW_DEATHPENALTY] == -2))
	 {
		 if (lawList[LAW_DEATHPENALTY] == -2) g.deathpenalty = 1;
		 if (lawList[LAW_DEATHPENALTY] == -1) g.deathpenalty = LCSrandom(3);
		 if (lawList[LAW_DEATHPENALTY] == 0) g.deathpenalty = LCSrandom(2);
		 if (lawList[LAW_DEATHPENALTY] == 1) g.deathpenalty = !LCSrandom(5);
		 if (lawList[LAW_DEATHPENALTY] == 2) g.deathpenalty = 0;
	 }
	 g.cap_crimes_at_ten();
	 //CALC TIME
	 if (!g.getCreatureJustice().deathpenalty)
	 {
		 g.sentence = calculateSentence(g.getCreatureJustice(), lenient);
	 }
	 //LENIENCY AND CAPITAL PUNISHMENT DON'T MIX
	 else if (g.getCreatureJustice().deathpenalty&&lenient) g.deathpenalty = 0, g.sentence = -1;
	 //MENTION LENIENCY
	 if (lenient)
	 {
		 set_color_easy(WHITE_ON_BLACK);
		 mvaddstrAlt(5, 1, CONST_justice018, gamelog);
		 gamelog.newline();
		 pressAnyKey();
	 }
	 //MENTION SENTENCE
	 if (olddeathpenalty)
	 {
		 g.deathpenalty = 1;
		 g.sentence = 3;
		 set_color_easy(RED_ON_BLACK_BRIGHT);
		 mvaddstrAlt(7, 1, g.propername, gamelog);
		 addstrAlt(CONST_justice019, gamelog);
		 gamelog.newline();
		 pressAnyKey();
		 set_color_easy(WHITE_ON_BLACK);
		 mvaddstrAlt(9, 1, execution_in_three_months, gamelog);
		 pressAnyKey();
	 }
	 else if (g.getCreatureJustice().deathpenalty)
	 {
		 g.sentence = 3;
		 set_color_easy(YELLOW_ON_RED_BRIGHT);
		 mvaddstrAlt(7, 1, g.propername, gamelog);
		 addstrAlt(CONST_justice020, gamelog);
		 gamelog.newline();
		 pressAnyKey();
		 set_color_easy(WHITE_ON_BLACK);
		 mvaddstrAlt(9, 1, execution_in_three_months, gamelog);
		 pressAnyKey();
	 }
	 // Don't give a time-limited sentence if they already have a life sentence.
	 else if ((g.getCreatureJustice().sentence >= 0 && oldsentence < 0) ||
		 (g.getCreatureJustice().sentence == 0 && oldsentence > 0))
	 {
		 g.sentence = oldsentence;
		 set_color_easy(WHITE_ON_BLACK);
		 mvaddstrAlt(7, 1, g.propername, gamelog);
		 addstrAlt(CONST_justice021, gamelog);
		 mvaddstrAlt(8, 1, CONST_justice022, gamelog);
		 if (g.getCreatureJustice().sentence > 1 && lenient)
		 {
			 g.sentence--;
			 addstrAlt(CONST_justice141, gamelog);
		 }
		 else addstrAlt(singleDot, gamelog);
		 pressAnyKey();
	 }
	 else if (g.getCreatureJustice().sentence == 0)
	 {
		 set_color_easy(WHITE_ON_BLACK);
		 mvaddstrAlt(7, 1, g.propername, gamelog);
		 addstrAlt(CONST_justice024, gamelog);
		 pressAnyKey();
	 }
	 else
	 {
		 if (g.getCreatureJustice().sentence >= 36)g.sentence -= g.sentence % 12;
		 set_color_easy(WHITE_ON_BLACK);
		 mvaddstrAlt(7, 1, g.propername, gamelog);
		 addstrAlt(CONST_justice025, gamelog);
		 if (g.getCreatureJustice().sentence > 1200) g.sentence /= -1200;
		 if (g.getCreatureJustice().sentence <= -1)
		 {
			 if (g.getCreatureJustice().sentence < -1)
			 {
				 addstrAlt(-(g.getCreatureJustice().sentence), gamelog);
				 addstrAlt(CONST_justice026, gamelog);
				 gamelog.newline();
				 // Don't bother saying this if the convicted already has one or
				 // more life sentences. Makes the 'consecutively' and 'concurrently'
				 // statements later easier to tack on.
				 if (oldsentence >= 0)
				 {
					 addstrAlt(singleDot, gamelog);
					 pressAnyKey();
					 mvaddstrAlt(9, 1, CONST_justice027, gamelog);
					 addstrAlt(g.propername, gamelog);
				 }
			 }
			 else addstrAlt(CONST_justice028, gamelog);
		 }
		 else if (g.getCreatureJustice().sentence >= 36)
		 {
			 addstrAlt(g.getCreatureJustice().sentence / 12, gamelog);
			 addstrAlt(CONST_justice029, gamelog);
		 }
		 else
		 {
			 addstrAlt(g.getCreatureJustice().sentence, gamelog);
			 addstrAlt(CONST_justice030, gamelog);
			 if (g.getCreatureJustice().sentence > 1)addstrAlt(CONST_justice031, gamelog);
			 addstrAlt(CONST_justice032, gamelog);
		 }
		 // Mash together compatible sentences.
		 if ((g.getCreatureJustice().sentence > 0 && oldsentence > 0) ||
			 (g.getCreatureJustice().sentence < 0 && oldsentence < 0))
		 {
			 addstrAlt(CONST_justice033, gamelog);
			 moveAlt(8, 1);
			 if (lenient)
			 {
				 if (abs(oldsentence) > abs(g.getCreatureJustice().sentence))
					 g.sentence = oldsentence;
				 addstrAlt(CONST_justice034, gamelog);
			 }
			 else
			 {
				 g.sentence += oldsentence;
				 addstrAlt(CONST_justice035, gamelog);
			 }
		 }
		 addstrAlt(singleDot, gamelog);
		 //dejuice boss
		 dejuiceBoss(g);
		 pressAnyKey();
	 }
	 gamelog.nextMessage();
 }
 /* monthly - move a liberal to jail */
 void imprison(DeprecatedCreature &g)
 {
	 g.location = find_site_index_in_city(SITE_GOVERNMENT_PRISON, LocationsPool::getInstance().get_specific_integer(INT_GETLOCATIONCITY,g.location));
 }
 string commaAndPunctuation(const int typenum) {
	 if (typenum > 1) return commaSpace;
	 if (typenum == 1) return AND;
	 if (typenum == 0) return singleDot;
	 else return blankString;
 }
 void printSingleCrime(const CreatureJustice g, const Lawflags law_flag, const int typenum, const string crime_string, const bool mention_multiple_counts) {

	 if (mention_multiple_counts && g.crimes_suspected[law_flag] > 1)
	 {
		 addstrAlt(g.crimes_suspected[law_flag], gamelog);
		 addstrAlt(counts_of, gamelog);
	 }
	 addstrAlt(crime_string, gamelog);
	 addstrAlt(commaAndPunctuation(typenum), gamelog);
	 pressAnyKey();
 }
 int listAllCrimes(CreatureJustice g) {


	 int typenum = 0;
	 for (int i = 0; i < LAWFLAGNUM; i++) {
		 if (g.crimes_suspected[i])
		 {
			 typenum++;
		 }
	 }
	 int x = 2;
	 int y = 5;
	 if ((x++) >= 2) { x = 0; moveAlt(++y, 1); }

	 for (std::pair<Lawflags, string> element : crimeBlockOne) {

		 if (g.crimes_suspected[element.first]) {
			 printSingleCrime(g, element.first, typenum, element.second, crimeMultipleCounts[element.first]);
			 if ((x++) >= 2) { x = 0; moveAlt(++y, 1); }
		 }
	 }

	 if (g.crimes_suspected[LAWFLAG_BURNFLAG] && lawList[LAW_FLAGBURNING] <= 0)
	 {
		 string crime;
		 if (lawList[LAW_FLAGBURNING] == -2)
			 crime = (CONST_justice047);
		 else if (lawList[LAW_FLAGBURNING] == -1)
			 crime = (CONST_justice048);
		 else if (lawList[LAW_FLAGBURNING] == 0)
			 crime = (CONST_justice049);
		 // otherwise, not a crime
		 printSingleCrime(g, LAWFLAG_BURNFLAG, typenum, crime, true);
		 if ((x++) >= 2) { x = 0; moveAlt(++y, 1); }
	 }

	 for (std::pair<Lawflags, string> element : crimeBlockTwo) {

		 if (g.crimes_suspected[element.first]) {
			 typenum--;
			 printSingleCrime(g, element.first, typenum, element.second, crimeMultipleCounts[element.first]);
			 if ((x++) >= 2) { x = 0; moveAlt(++y, 1); }
		 }
	 }

	 if (g.crimes_suspected[LAWFLAG_HIREILLEGAL])
	 {
		 if (g.crimes_suspected[LAWFLAG_HIREILLEGAL] > 1)
		 {
			 addstrAlt(g.crimes_suspected[LAWFLAG_HIREILLEGAL], gamelog);
			 addstrAlt(counts_of, gamelog);
			 addstrAlt((lawList[LAW_IMMIGRATION] < 1 ? CONST_justice063 : CONST_justiceB173), gamelog);
		 }
		 else addstrAlt((lawList[LAW_IMMIGRATION] < 1 ? CONST_justice064 : CONST_justiceB174), gamelog);
		 x = 2;
		 typenum--;
		 addstrAlt(commaAndPunctuation(typenum), gamelog);
		 pressAnyKey();
		 if ((x++) >= 2) { x = 0; moveAlt(++y, 1); }
	 }

	 for (std::pair<Lawflags, string> element : crimeBlockThree) {

		 if (g.crimes_suspected[element.first]) {
			 typenum--;
			 printSingleCrime(g, element.first, typenum, element.second, crimeMultipleCounts[element.first]);
			 if ((x++) >= 2) { x = 0; moveAlt(++y, 1); }
		 }
	 }

	 return y;

 }
 int get_sentence(CreatureJustice g, DeprecatedCreature &sleeperLawyer, const LegalDefense defense, const bool sleeperjudge) {
	 set_color_easy(GREEN_ON_BLACK_BRIGHT);
	 mvaddstrAlt(3, 1, CONST_justice138, gamelog);
	 gamelog.newline();
	 pressAnyKey();
	 int new_sentence = g.sentence;
	 if (g.sentence == 0)
	 {
		 set_color_easy(GREEN_ON_BLACK_BRIGHT);
		 mvaddstrAlt(5, 1, g.name, gamelog);
		 addstrAlt(CONST_justice139, gamelog);
	 }
	 else
	 {
		 set_color_easy(WHITE_ON_BLACK);
		 mvaddstrAlt(5, 1, g.name, gamelog);
		 addstrAlt(CONST_justice140, gamelog);
		 if (!g.deathpenalty && g.sentence > 1 && (LCSrandom(2) || sleeperjudge))
		 {
			 new_sentence--;
			 addstrAlt(CONST_justice141, gamelog);
		 }
		 else addstrAlt(singleDot, gamelog);
		 if (g.deathpenalty)
		 {
			 new_sentence = 3;
			 mvaddstrAlt(7, 1, execution_in_three_months, gamelog);
		 }
	 }
	 return new_sentence;
 }
 bool hung_jury(DeprecatedCreature &g, const bool sleeperjudge, const int scarefactor) {
	 bool keeplawflags = false;
	 set_color_easy(YELLOW_ON_BLACK_BRIGHT);
	 mvaddstrAlt(3, 1, CONST_justice132, gamelog);
	 gamelog.newline();
	 pressAnyKey();
	 //RE-TRY
	 if (LCSrandom(2) || scarefactor >= 10 || g.getCreatureConfessions())
	 {
		 set_color_easy(WHITE_ON_BLACK);
		 mvaddstrAlt(5, 1, CONST_justice133, gamelog);
		 gamelog.newline();
		 pressAnyKey();
		 g.location = find_site_index_in_same_city(SITE_GOVERNMENT_COURTHOUSE, g.location);
		 keeplawflags = true;
	 }
	 //NO RE-TRY
	 else
	 {
		 set_color_easy(WHITE_ON_BLACK);
		 mvaddstrAlt(5, 1, CONST_justice134, gamelog);
		 gamelog.newline();
		 if (g.getCreatureJustice().sentence == 0)
		 {
			 set_color_easy(GREEN_ON_BLACK_BRIGHT);
			 mvaddstrAlt(7, 1, g.getNameAndAlignment().name, gamelog);
			 addstrAlt(CONST_justice139, gamelog);
		 }
		 else
		 {
			 set_color_easy(WHITE_ON_BLACK);
			 mvaddstrAlt(7, 1, g.getNameAndAlignment().name, gamelog);
			 addstrAlt(CONST_justice140, gamelog);
			 if (!g.getCreatureJustice().deathpenalty && g.getCreatureJustice().sentence > 1 && (LCSrandom(2) || sleeperjudge))
			 {
				 g.sentence--;
				 addstrAlt(CONST_justice141, gamelog);
			 }
			 else addstrAlt(singleDot, gamelog);
			 if (g.getCreatureJustice().deathpenalty)
			 {
				 g.sentence = 3;
				 mvaddstrAlt(9, 1, execution_in_three_months, gamelog);
			 }
		 }
		 gamelog.nextMessage();
		 pressAnyKey();
	 }
	 return keeplawflags;
 }
 void printdefensepower(const int defensepower) {

	 if (defensepower <= 5) { addstrAlt(CONST_justice109, gamelog); }
	 else if (defensepower <= 15) { addstrAlt(CONST_justice110, gamelog); }
	 else if (defensepower <= 25) { addstrAlt(CONST_justice111, gamelog); }
	 else if (defensepower <= 50) { addstrAlt(CONST_justice112, gamelog); }
	 else if (defensepower <= 75) { addstrAlt(CONST_justice113, gamelog); }
	 else /*if (defensepower <= 100)*/ { addstrAlt(CONST_justice114, gamelog); }
 }
 void printstrongdefensepower(const int prosecution) {


	 if (prosecution < 100) { addstrAlt(CONST_justice115, gamelog); }
	 else { addstrAlt(CONST_justice116, gamelog); }

 }
 void printultimatedefensepower(const int prosecution, const string attorneyname) {
	 if (prosecution < 100)
	 {
		 addstrAlt(attorneyname, gamelog);
		 addstrAlt(CONST_justice117, gamelog);
		 mvaddstrAlt(10, 1, CONST_justice118, gamelog);
	 }
	 else
	 {
		 addstrAlt(attorneyname, gamelog);
		 addstrAlt(CONST_justice119, gamelog);
	 }
 }
 int get_defensepower(DeprecatedCreature &g, DeprecatedCreature &sleeperLawyer, const char attorneyname[200], const LegalDefense defense, const int prosecution) {
	 DeprecatedCreature *sleeperlawyer = &sleeperLawyer;
	 int defensepower = 0;
	 if (defense == COURT_ATTORNEY || defense == ACE_ATTORNEY || defense == SLEEPER_ATTORNEY)
	 {


		 if (defense == COURT_ATTORNEY) defensepower = LCSrandom(71);    // Court-appointed attorney
		 else if (defense == ACE_ATTORNEY) defensepower = LCSrandom(71) + 80; // Ace Liberal attorney
		 else if (defense == SLEEPER_ATTORNEY)
		 {
			 // Sleeper attorney
			 defensepower = LCSrandom(71) + sleeperlawyer->get_skill(SKILL_LAW) * 2
				 + sleeperlawyer->get_skill(SKILL_PERSUASION) * 2;
			 sleeperlawyer->train(SKILL_LAW, prosecution / 4);
			 sleeperlawyer->train(SKILL_PERSUASION, prosecution / 4);
		 }
		 if (defensepower <= 100) { printdefensepower(defensepower); }
		 else if (defensepower <= 145) { printstrongdefensepower(prosecution); }
		 else
		 {
			 printultimatedefensepower(prosecution, attorneyname);
		 }
		 if (defense == SLEEPER_ATTORNEY && defensepower > 145 && prosecution < 100) {
			 addjuice(*sleeperlawyer, 10, 500); // Bow please
		 }
		 gamelog.newline();

	 }
	 if (defense == SELF_REPRESENT)
	 {
		 // *JDS* LEGAL SELF-REPRESENTATION: To succeed here, you really need to have two skills be
		 // high: persuasion and law, with law being 1.5 times as influential. You can't have
		 // just one or just the other. Even if you're a very persuasive person, the court will eat
		 // you alive if you can't sound intelligent when talking about the relevant charges, and you
		 // won't be able to fool the jury into letting you go if you aren't persuasive, as no
		 // matter how encyclopedic your legal knowledge is, it's all in the pitch.
		 //
		 // If either your persuasion or your law roll is too low, you'll end up getting a negative
		 // result that will drag down your defense. So try not to suck in either area.
		 defensepower = 5 * (g.skill_roll(SKILL_PERSUASION) - 3) +
			 10 * (g.skill_roll(SKILL_LAW) - 3);
		 g.train(SKILL_PERSUASION, 50);
		 g.train(SKILL_LAW, 50);
		 addstrAlt(g.getNameAndAlignment().name, gamelog);
		 if (defensepower <= 0)
		 {
			 addstrAlt(CONST_justice120, gamelog);
			 gamelog.newline();
			 addjuice(g, -10, -50); // You should be ashamed
		 }
		 else if (defensepower <= 25) addstrAlt(CONST_justice121, gamelog);
		 else if (defensepower <= 50) addstrAlt(CONST_justice122, gamelog);
		 else if (defensepower <= 75) addstrAlt(CONST_justice123, gamelog);
		 else if (defensepower <= 100) addstrAlt(CONST_justice124, gamelog);
		 else if (defensepower <= 150) addstrAlt(CONST_justice125, gamelog);
		 else
		 {
			 addstrAlt(CONST_justice126, gamelog);
			 addjuice(g, 50, 1000); // That shit is legend
		 }
		 gamelog.newline();
	 }
	 return defensepower;
 }
 bool pleadInnocent(DeprecatedCreature &g, DeprecatedCreature &sleeperLawyer, const char attorneyname[200], const LegalDefense defense, const bool sleeperjudge, const int scarefactor) {

	 DeprecatedCreature *sleeperlawyer = &sleeperLawyer;
	 int prosecution = 0;
	 eraseAlt();
	 set_color_easy(WHITE_ON_BLACK_BRIGHT);
	 mvaddstrAlt(1, 1, g.getNameAndAlignment().name, gamelog);
	 addstrAlt(CONST_justice090);
	 //TRIAL MESSAGE
	 set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(3, 1, CONST_justice091, gamelog);
	 gamelog.newline();
	 pressAnyKey();
	 //JURY MAKEUP MESSAGE
	 set_color_easy(WHITE_ON_BLACK);
	 moveAlt(5, 1);
	 int jury = LCSrandom(61) - (60 * publicmood(-1)) / 100; // Political leanings of the population determine your jury
	 if (sleeperjudge) jury -= 20;
	 if (defense == ACE_ATTORNEY) // Hired $5000 ace attorney
	 {
		 if (LCSrandom(10))
		 {
			 addstrAlt(attorneyname, gamelog);
			 addstrAlt(CONST_justice092, gamelog);
			 addstrAlt(g.getNameAndAlignment().name, gamelog);
			 addstrAlt(CONST_justice093, gamelog);
			 gamelog.newline();
			 if (jury > 0) jury = 0;
			 jury -= 30;
		 }
		 else
		 {
			 set_color_easy(RED_ON_BLACK_BRIGHT);
			 addstrAlt(attorneyname, gamelog);
			 addstrAlt(CONST_justice094, gamelog);
			 gamelog.newline();
			 jury = 0;
			 prosecution += 100; // DUN DUN DUN!!
		 }
	 }
	 else if (jury <= -29)
	 {
		 set_color_easy(GREEN_ON_BLACK_BRIGHT);
		 switch (LCSrandom(liberal_jury.size() + 1))
		 {
		 case 0:addstrAlt(g.getNameAndAlignment().name); addstrAlt(CONST_justice095, gamelog); break;
		 default:addstrAlt(pickrandom(liberal_jury), gamelog); break;
		 }
		 gamelog.newline();
	 }
	 else if (jury <= -15) addstrAlt(CONST_justice096, gamelog);
	 else if (jury < 15) addstrAlt(CONST_justice097, gamelog);
	 else if (jury < 29) addstrAlt(CONST_justice098, gamelog);
	 else
	 {
		 set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		 addstrAlt(pickrandom(conservative_jury), gamelog);
	 }
	 gamelog.newline();
	 // Debug jury bias
	 if (SHOWMECHANICS)
	 {
		 addstrAlt(CONST_justice127);
		 if (jury >= 0) addcharAlt('+');
		 addstrAlt(jury);
		 addstrAlt(CONST_justice108);
	 }
	 pressAnyKey();
	 //PROSECUTION MESSAGE
	 // *JDS* The bigger your record, the stronger the evidence
	 prosecution += 40 + LCSrandom(101) + scarefactor + (20 * g.getCreatureConfessions());
	 if (sleeperjudge) prosecution >>= 1;
	 if (defense == ACE_ATTORNEY) prosecution -= 60;
	 set_color_easy(WHITE_ON_BLACK);
	 moveAlt(7, 1);

	 {
		 if (prosecution <= 50) addstrAlt(CONST_justice101, gamelog);
		 else if (prosecution <= 75) addstrAlt(CONST_justice102, gamelog);
		 else if (prosecution <= 125) addstrAlt(CONST_justice103, gamelog);
		 else if (prosecution <= 175) addstrAlt(CONST_justice104, gamelog);
		 else addstrAlt(CONST_justice105, gamelog);
		 gamelog.newline();
	 }
	 // Debug prosecution power
	 if (SHOWMECHANICS)
	 {
		 addstrAlt(CONST_justice106);
		 addstrAlt(prosecution / 2);
		 addstrAlt(CONST_justice107);
		 addstrAlt(prosecution);
		 addstrAlt(CONST_justice108);
	 }
	 pressAnyKey();
	 jury += LCSrandom(prosecution / 2 + 1) + prosecution / 2;
	 //DEFENSE MESSAGE
	 set_color_easy(WHITE_ON_BLACK);
	 moveAlt(9, 1);
	 int defensepower = get_defensepower(g, sleeperLawyer, attorneyname, defense, prosecution);

	 // Debug defense power
	 if (SHOWMECHANICS)
	 {
		 addstrAlt(CONST_justice127);
		 addstrAlt(defensepower);
		 addstrAlt(CONST_justice128);
		 addstrAlt(jury + 1);
		 addstrAlt(CONST_justice129);
	 }
	 pressAnyKey();
	 //DELIBERATION MESSAGE
	 set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(12, 1, CONST_justice130, gamelog);
	 gamelog.newline();
	 pressAnyKey();
	 //JURY RETURN MESSAGE
	 eraseAlt();
	 set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(1, 1, CONST_justice131, gamelog);
	 gamelog.newline();
	 pressAnyKey();
	 bool keeplawflags = false;
	 //HUNG JURY
	 if (defensepower == jury)
	 {
		 keeplawflags = hung_jury(g, sleeperjudge, scarefactor);
	 }
	 //ACQUITTAL!
	 else if (defensepower > jury)
	 {
		 g.sentence = (g.getCreatureJustice(), sleeperLawyer, defense, sleeperjudge);

		 gamelog.nextMessage();
		 // Juice sleeper
		 if (defense == SLEEPER_ATTORNEY) addjuice(*sleeperlawyer, 10, 100);
		 // Juice for self-defense
		 if (defense == SELF_REPRESENT) addjuice(g, 10, 100);
		 pressAnyKey();
	 }
	 //LENIENCE
	 else
	 {
		 // De-Juice sleeper
		 if (defense == SLEEPER_ATTORNEY) addjuice(*sleeperlawyer, -5, 0);
		 // Juice for getting convicted of something :)
		 addjuice(g, 25, 200);
		 // Check for lenience; sleeper judge will always be merciful
		 if (defensepower / 3 >= jury / 4 || sleeperjudge) penalize(g, 1);
		 else penalize(g, 0);
	 }

	 return keeplawflags;
 }
 void pleadGuilty(DeprecatedCreature &g, const bool sleeperjudge) {
	 
	 eraseAlt();
	 set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(1, 1, CONST_justice143, gamelog);
	 gamelog.nextMessage();
	 pressAnyKey();
	 // Check for lenience; sleeper judge will always be merciful
	 if (sleeperjudge || LCSrandom(2)) penalize(g, 1);
	 else penalize(g, 0);

 }
 /* monthly - hold trial on a liberal */
 void trial(DeprecatedCreature &g)
 {
	 CreatureJustice g_crimes = g.getCreatureJustice();
	 music.play(MUSIC_TRIAL);
	 // If their old base is no longer under LCS control, wander back to the
	 // homeless shelter instead.
	 if (LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE,g.base) < 0) g.base = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, g.location);
	 g.location = g.base;
	 eraseAlt();
	 set_color_easy(WHITE_ON_BLACK_BRIGHT);
	 mvaddstrAlt(1, 1, g.getNameAndAlignment().name, gamelog);
	 addstrAlt(CONST_justice090, gamelog);
	 gamelog.newline();
	 pressAnyKey();
	 set_color_easy(WHITE_ON_BLACK);
	 if (!iscriminal(g.getCreatureJustice())) criminalize(g, LAWFLAG_LOITERING);
	 int scarefactor = 0;
	 for (int i = 0; i < LAWFLAGNUM; i++) if (g_crimes.crimes_suspected[i])
	 {
		 scarefactor += scare_factor(i, g_crimes.crimes_suspected[i]);
	 }
	 //CHECK FOR SLEEPERS
	 DeprecatedCreature *sleeperjudge = getSleeperJudge(g);
	 DeprecatedCreature *sleeperlawyer = getSleeperLawyer(g);

	 //STATE CHARGES
	 set_color_easy(WHITE_ON_BLACK);
	 if (sleeperjudge)
	 {
		 mvaddstrAlt(3, 1, string_sleeper, gamelog);
		 addstrAlt(sleeperjudge->getNameAndAlignment().name, gamelog);
		 addstrAlt(CONST_justice037, gamelog);
		 g.confessions = 0; //Made sleeper judge prevent these lunatics from testifying
	 }
	 else mvaddstrAlt(3, 1, CONST_justice038, gamelog);
	 gamelog.newline();
	 set_color_easy(RED_ON_BLACK_BRIGHT);
	 mvaddstrAlt(5, 1, CONST_justice039, gamelog);
	 addstrAlt(g.propername, gamelog);
	 addstrAlt(CONST_justice040, gamelog);
	 int y = listAllCrimes(g.getCreatureJustice());
	 gamelog.newline();
	 if (g.getCreatureConfessions())
	 {
		 if (g.getCreatureConfessions() > 1)
		 {
			 mvaddstrAlt(y += 2, 1, g.getCreatureConfessions(), gamelog);
			 addstrAlt(CONST_justice076, gamelog);
		 }
		 else mvaddstrAlt(y += 2, 1, CONST_justice077, gamelog);
		 addstrAlt(g.getNameAndAlignment().name, gamelog);
		 addstrAlt(singleDot, gamelog);
		 gamelog.newline();
		 pressAnyKey();
	 }
	 //CHOOSE DEFENSE
	 set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(y + 2, 1, CONST_justice078);
	 char attorneyname[200];
	 unsigned long oldseed[RNG_SIZE];
	 copyRNG(oldseed, seed);
	 copyRNG(seed, attorneyseed);
	 generate_name(attorneyname);
	 copyRNG(seed, oldseed);
	 y += 4;
	 mvaddstrAlt(y++, 1, CONST_justice079);
	 mvaddstrAlt(y++, 1, CONST_justice080);
	 mvaddstrAlt(y++, 1, CONST_justice081);
	 if (ledger.get_funds() < 5000) set_color_easy(BLACK_ON_BLACK_BRIGHT);
	 mvaddstrAlt(y++, 1, CONST_justice082);
	 addstrAlt(attorneyname);
	 addstrAlt(singleDot);
	 if (sleeperlawyer)
	 {
		 set_color_easy(WHITE_ON_BLACK);
		 mvaddstrAlt(y++, 1, CONST_justice083);
		 addstrAlt(sleeperlawyer->getNameAndAlignment().name);
		 addstrAlt(CONST_justice084);
	 }
	 if (ledger.get_funds() < 5000) set_color_easy(WHITE_ON_BLACK);
	 //SAV - added in display of skills and relevant attributes to help
	 // decide when to defend self.
	 mvaddstrAlt(++y, 5, CONST_justice085);
	 addstrAlt(g.get_attribute(ATTRIBUTE_HEART, true));
	 mvaddstrAlt(y, 25, CONST_justice086);
	 addstrAlt(g.get_skill(SKILL_PERSUASION));
	 mvaddstrAlt(++y, 5, CONST_justice087);
	 addstrAlt(g.get_attribute(ATTRIBUTE_CHARISMA, true));
	 mvaddstrAlt(y++, 25, CONST_justice088);
	 addstrAlt(g.get_skill(SKILL_LAW));
	 mvaddstrAlt(y++, 5, CONST_justice089);
	 addstrAlt(g.get_attribute(ATTRIBUTE_INTELLIGENCE, true));
	 // End SAV's adds
	 LegalDefense defense = UNDECIDED;
	 while (defense == UNDECIDED) {
		 int c = pressSpecificKey('a', 'b', 'c', 'd', 'e');

		 if (c == 'a') { defense = COURT_ATTORNEY; }
		 else
			 if (c == 'b') { defense = SELF_REPRESENT; }
			 else
				 if (c == 'c') { defense = PLEAD_GUILTY; }
				 else
					 if (c == 'd'&&ledger.get_funds() >= 5000)
					 {
						 ledger.subtract_funds(5000, EXPENSE_LEGAL);
						 defense = ACE_ATTORNEY;

					 }
					 else
						 if (c == 'e'&&sleeperlawyer)
						 {
							 defense = SLEEPER_ATTORNEY;
							 strcpy(attorneyname, sleeperlawyer->getNameAndAlignment().name.data());

						 }
	 }
	 //TRIAL
	 bool keeplawflags = false;
	 if (defense != PLEAD_GUILTY) { keeplawflags = pleadInnocent(g, *sleeperlawyer, attorneyname, defense, sleeperjudge, scarefactor); }
	 //GUILTY PLEA
	 // How about CONST_justice142 (Nolo contendere) -- LK
	 // I would imagine this would disregard the strength of the defense. -- LK
	 else { pleadGuilty(g, sleeperjudge); }

	 //CLEAN UP LAW FLAGS
	 if (!keeplawflags) {
		 g.clear_criminal_record();
	 } 
	 //This is redundant if !keeplawflags
	 g.heat = 0;


	 g.confessions = 0;
	 //PLACE PRISONER
	 if (g.getCreatureJustice().sentence != 0) imprison(g);
	 else
	 {
		 Armor clothes(getarmortype(tag_ARMOR_CLOTHES));
		 g.give_armor(clothes, NULL);
	 }
 }
 void reeducation(DeprecatedCreature &g)
 {
	 eraseAlt();
	 set_color_easy(WHITE_ON_BLACK_BRIGHT);
	 mvaddstrAlt(8, 1, g.getNameAndAlignment().name, gamelog);
	 addstrAlt(pickrandom(reeducation_experiences), gamelog);
	 gamelog.newline();
	 pressAnyKey();
	 moveAlt(10, 1);
	 if (!g.attribute_check(ATTRIBUTE_HEART, DIFFICULTY_FORMIDABLE))
	 {
		 if (g.juice > 0 && LCSrandom(2))
		 {
			 addstrAlt(g.getNameAndAlignment().name, gamelog);
			 addstrAlt(CONST_justice144, gamelog);
			 addjuice(g, -50, 0);
		 }
		 else if (LCSrandom(15) > g.get_attribute(ATTRIBUTE_WISDOM, true)
			 || g.get_attribute(ATTRIBUTE_WISDOM, true) < g.get_attribute(ATTRIBUTE_HEART, true))
		 {
			 addstrAlt(g.getNameAndAlignment().name, gamelog);
			 addstrAlt(CONST_justice145, gamelog);
			 g.adjust_attribute(ATTRIBUTE_WISDOM, +1);
		 }
		 else if (g.align == ALIGN_LIBERAL && g.flag & CREATUREFLAG_LOVESLAVE && LCSrandom(4))
		 {
			 addstrAlt(g.getNameAndAlignment().name, gamelog);
			 addstrAlt(CONST_justice146, gamelog);
			 addstrAlt(pool[g.hireid]->getNameAndAlignment().name, gamelog);
			 addstrAlt(singleDot, gamelog);
		 }
		 else
		 {
			 addstrAlt(g.getNameAndAlignment().name, gamelog);
			 addstrAlt(CONST_justice147, gamelog);
			 //Rat out contact
			 int contact = getpoolcreature(g.hireid);
			 if (contact >= 0)
			 {
				 criminalize(*pool[contact], LAWFLAG_RACKETEERING);
				 pool[contact]->another_confession();
			 }
			 g.die();
			 g.location = -1;
		 }
	 }
	 else
	 {
		 addstrAlt(g.getNameAndAlignment().name, gamelog);
		 addstrAlt(CONST_justice148, gamelog);
	 }
	 gamelog.nextMessage();
	 pressAnyKey();
	 eraseAlt();
	 return;
 }
 void laborcamp(DeprecatedCreature &g)
 {
	 int escaped = 0;
	 const char *experience;
	 // Escape attempt!
	 if (g.hireid == -1 && !LCSrandom(3))
	 {
		 escaped = 2;
		 experience = CONST_justice149.c_str();
	 }
	 else if (g.skill_check(SKILL_DISGUISE, DIFFICULTY_HEROIC) && !LCSrandom(10))
	 {
		 escaped = 1;
		 experience = CONST_justice150.c_str();
		 g.give_armor(getarmortype(tag_ARMOR_WORKCLOTHES), NULL);
	 }
	 else if (g.skill_check(SKILL_SECURITY, DIFFICULTY_CHALLENGING) && g.skill_check(SKILL_STEALTH, DIFFICULTY_HARD) && !LCSrandom(10))
	 {
		 escaped = 1;
		 experience = CONST_justice151.c_str();
	 }
	 else if (g.skill_check(SKILL_SCIENCE, DIFFICULTY_HARD) && !LCSrandom(10))
	 {
		 escaped = 1;
		 experience = CONST_justice152.c_str();
	 }
	 if (!escaped)experience = (singleSpace + pickrandom(labor_camp_experiences)).data();
	 eraseAlt();
	 set_color_easy(WHITE_ON_BLACK_BRIGHT);
	 mvaddstrAlt(8, 1, g.getNameAndAlignment().name, gamelog);
	 addstrAlt(experience, gamelog);
	 gamelog.newline();
	 pressAnyKey();
	 moveAlt(10, 1);
	 if (escaped)
	 {
		 int prison = g.location;
		 addstrAlt(g.getNameAndAlignment().name, gamelog);
		 addstrAlt(CONST_justice164, gamelog);
		 addjuice(g, 50, 1000);
		 criminalize(g, LAWFLAG_ESCAPED);
		 g.location = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, g.location);
		 if (escaped == 2)
		 {
			 int num_escaped = otherPrisonersEscapeWithMe(g, prison);
			 if (num_escaped == 1)
			 {
				 gamelog.nextMessage();
				 mvaddstrAlt(11, 1, CONST_justice165, gamelog);
			 }
			 else if (num_escaped > 1)
			 {
				 gamelog.nextMessage();
				 mvaddstrAlt(11, 1, CONST_justice166, gamelog);
			 }
		 }
	 }
	 else if (!LCSrandom(4))
	 {
		 if (g.get_attribute(ATTRIBUTE_HEALTH, true) > 1)
		 {
			 addstrAlt(g.getNameAndAlignment().name, gamelog);
			 addstrAlt(CONST_justice156, gamelog);
			 addjuice(g, -40, 0);
			 addjuice(g, -10, -50);
		 }
		 else
		 {
			 addstrAlt(g.getNameAndAlignment().name, gamelog);
			 addstrAlt(CONST_justice157, gamelog);
			 g.die();
			 g.location = -1;
		 }
	 }
	 else
	 {
		 addstrAlt(g.getNameAndAlignment().name, gamelog);
		 addstrAlt(CONST_justice158, gamelog);
	 }
	 gamelog.nextMessage();
	 pressAnyKey();
	 eraseAlt();
	 return;
 }
 void prisonscene(DeprecatedCreature &g)
 {
	 int escaped = 0;
	 int effect = 0;
	 const char *experience;
	 if (g.juice + int(g.hireid == -1) * 300 > 500)
	 {
		 // Escape attempt!
		 if (g.hireid == -1 && !LCSrandom(10))
		 {
			 escaped = 2;
			 experience = CONST_justice159.c_str();
		 }
		 else if (g.skill_check(SKILL_COMPUTERS, DIFFICULTY_HARD) && !LCSrandom(5))
		 {
			 escaped = 2;
			 experience = CONST_justice160.c_str();
		 }
		 else if (g.skill_check(SKILL_DISGUISE, DIFFICULTY_HARD) && !LCSrandom(5))
		 {
			 escaped = 1;
			 experience = CONST_justice161.c_str();
			 g.give_armor(getarmortype(tag_ARMOR_CLOTHES), NULL);
		 }
		 else if (g.skill_check(SKILL_SECURITY, DIFFICULTY_CHALLENGING) && g.skill_check(SKILL_STEALTH, DIFFICULTY_CHALLENGING) && !LCSrandom(5))
		 {
			 escaped = 1;
			 experience = CONST_justice162.c_str();
		 }
		 else if (g.skill_check(SKILL_SCIENCE, DIFFICULTY_AVERAGE) && g.skill_check(SKILL_HANDTOHAND, DIFFICULTY_EASY) && !LCSrandom(5))
		 {
			 escaped = 1;
			 experience = CONST_justice163.c_str();
		 }
	 }
	 if (escaped == 0)
	 {
		 if (g.attribute_check(ATTRIBUTE_HEART, DIFFICULTY_HARD)) {
			 effect = 1;
			 if (LCSrandom(2) > 0) experience = (singleSpace + pickrandom(good_experiences)).data();
			 else experience = (singleSpace + pickrandom(general_experiences)).data();
		 }
		 else if (g.attribute_check(ATTRIBUTE_HEART, DIFFICULTY_CHALLENGING)) {
			 effect = 0;
			 experience = (singleSpace + pickrandom(general_experiences)).data();
		 }
		 else {
			 effect = -1;
			 if (LCSrandom(2) > 0) experience = (singleSpace + pickrandom(bad_experiences)).data();
			 else experience = (singleSpace + pickrandom(general_experiences)).data();
		 }
	 }
	 eraseAlt();
	 set_color_easy(WHITE_ON_BLACK_BRIGHT);
	 mvaddstrAlt(8, 1, g.getNameAndAlignment().name, gamelog);
	 addstrAlt(experience, gamelog);
	 gamelog.newline();
	 pressAnyKey();
	 moveAlt(10, 1);
	 if (escaped)
	 {
		 int prison = g.location;
		 addstrAlt(g.getNameAndAlignment().name, gamelog);
		 addstrAlt(CONST_justice164, gamelog);
		 addjuice(g, 50, 1000);
		 criminalize(g, LAWFLAG_ESCAPED);
		 g.location = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, g.location);
		 if (escaped == 2)
		 {
			 int num_escaped = 0;
			 for (int p = 0; p < CreaturePool::getInstance().lenpool(); p++)
			 {
				 if (pool[p]->location == prison && !(pool[p]->flag & CREATUREFLAG_SLEEPER))
				 {
					 criminalize(*pool[p], LAWFLAG_ESCAPED);
					 pool[p]->location = g.location;
					 num_escaped++;
				 }
			 }
			 if (num_escaped == 1)
			 {
				 gamelog.nextMessage();
				 mvaddstrAlt(11, 1, CONST_justice165, gamelog);
			 }
			 else if (num_escaped > 1)
			 {
				 gamelog.nextMessage();
				 mvaddstrAlt(11, 1, CONST_justice166, gamelog);
			 }
		 }
	 }
	 else if (effect > 0)
	 {
		 addstrAlt(g.getNameAndAlignment().name, gamelog);
		 addstrAlt(CONST_justice167, gamelog);
		 addjuice(g, 20, 1000);
	 }
	 else if (effect < 0)
	 {
		 addstrAlt(g.getNameAndAlignment().name, gamelog);
		 addstrAlt(CONST_justice168, gamelog);
		 addjuice(g, -20, -30);
	 }
	 else
	 {
		 addstrAlt(g.getNameAndAlignment().name, gamelog);
		 addstrAlt(CONST_justice169, gamelog);
	 }
	 gamelog.nextMessage();
	 pressAnyKey();
	 eraseAlt();
	 return;
 }
 /* monthly - advances a liberal's prison time or executes them */
 //RETURNS IF SCREEN WAS ERASED
 char prison(DeprecatedCreature &g)
 {
	 char showed = 0;
	 // People not on death row or about to be released can have a scene in prison
	 if (!g.getCreatureJustice().deathpenalty && g.getCreatureJustice().sentence != 1)
	 {
		 if (lawList[LAW_PRISONS] == 2)
		 {
			 //Liberal therapy.
			 if (!LCSrandom(5)) reeducation(g);
		 }
		 else if (lawList[LAW_PRISONS] == -2)
		 {
			 //Labor camp.
			 if (!LCSrandom(5)) laborcamp(g);
		 }
		 else
		 {
			 //Normal prison.
			 if (!LCSrandom(5)) prisonscene(g);
		 }
	 }
	 if (g.getCreatureJustice().sentence > 0)
	 {
		 //COMMUTE DEATH IN RIGHT CLIMATE
		 if (g.getCreatureJustice().deathpenalty&&lawList[LAW_DEATHPENALTY] == 2)
		 {
			 eraseAlt();
			 set_color_easy(WHITE_ON_BLACK);
			 mvaddstrAlt(8, 1, g.getNameAndAlignment().name, gamelog);
			 addstrAlt(CONST_justice170, gamelog);
			 mvaddstrAlt(9, 1, CONST_justice171, gamelog);
			 gamelog.nextMessage();
			 pressAnyKey();
			 g.sentence = -1;
			 g.deathpenalty = 0;
			 return 1;
		 }
		 //ADVANCE SENTENCE
		 g.sentence--;
		 if (g.getCreatureJustice().sentence == 0)
		 {
			 //EXECUTE
			 if (g.getCreatureJustice().deathpenalty)
			 {
				 eraseAlt();
				 set_color_easy(RED_ON_BLACK_BRIGHT);
				 mvaddstrAlt(8, 1, CONST_justice172, gamelog);
				 gamelog.newline();
				 mvaddstrAlt(9, 1, CONST_justice173, gamelog);
				 addstrAlt(g.getNameAndAlignment().name, gamelog);
				 gamelog.record(singleSpace); //Log this for formatting purposes.
				 mvaddstrAlt(10, 1, CONST_justice174, gamelog);
				 if (lawList[LAW_DEATHPENALTY] == -2)
					 addstrAlt(pickrandom(cruel_and_unusual_execution_methods), gamelog);
				 else if (lawList[LAW_DEATHPENALTY] == -1 || lawList[LAW_DEATHPENALTY] == 0)
					 addstrAlt(pickrandom(standard_execution_methods), gamelog);
				 else
					 addstrAlt(pickrandom(supposedly_painless_execution_method), gamelog);
				 addstrAlt(singleDot, gamelog);
				 pressAnyKey();
				 //dejuice boss
				 int boss = getpoolcreature(g.hireid);
				 if (boss != -1)
				 {
					 gamelog.newline();
					 set_color_easy(WHITE_ON_BLACK);
					 mvaddstrAlt(12, 1, pool[boss]->getNameAndAlignment().name, gamelog);
					 addstrAlt(CONST_justice175, gamelog);
					 gamelog.newline();
					 mvaddstrAlt(14, 1, CONST_justice176, gamelog);
					 pressAnyKey();
					 addjuice(*pool[boss], -50, -50);
				 }
				 gamelog.nextMessage();
				 g.die();
				 stat_dead++;
				 showed = 1;
			 }
			 //SET FREE
			 else
			 {
				 eraseAlt();
				 set_color_easy(WHITE_ON_BLACK);
				 mvaddstrAlt(8, 1, g.getNameAndAlignment().name, gamelog);
				 addstrAlt(CONST_justice177, gamelog);
				 gamelog.newline();
				 mvaddstrAlt(9, 1, CONST_justice178, gamelog);
				 gamelog.nextMessage();
				 pressAnyKey();
				 Armor clothes(getarmortype(tag_ARMOR_CLOTHES));
				 g.give_armor(clothes, NULL);
				 // If their old base is no longer under LCS control, wander back to the
				 // homeless shelter instead.
				 if (LocationsPool::getInstance().get_specific_integer(INT_GETRENTINGTYPE,g.base) < 0) g.base = find_site_index_in_same_city(SITE_RESIDENTIAL_SHELTER, g.location);
				 g.location = g.base;
				 showed = 1;
			 }
		 }
		 //NOTIFY OF IMPENDING THINGS
		 else if (g.getCreatureJustice().sentence == 1)
		 {
			 if (g.getCreatureJustice().deathpenalty)
			 {
				 eraseAlt();
				 set_color_easy(YELLOW_ON_BLACK_BRIGHT);
				 mvaddstrAlt(8, 1, g.getNameAndAlignment().name, gamelog);
				 addstrAlt(CONST_justice179, gamelog);
				 gamelog.nextMessage();
				 pressAnyKey();
				 showed = 1;
			 }
			 else
			 {
				 eraseAlt();
				 set_color_easy(WHITE_ON_BLACK_BRIGHT);
				 mvaddstrAlt(8, 1, g.getNameAndAlignment().name, gamelog);
				 addstrAlt(CONST_justice180, gamelog);
				 gamelog.nextMessage();
				 pressAnyKey();
				 showed = 1;
			 }
		 }
		 else
		 {
			 if (g.getCreatureJustice().deathpenalty)
			 {
				 eraseAlt();
				 set_color_easy(YELLOW_ON_BLACK_BRIGHT);
				 mvaddstrAlt(8, 1, g.getNameAndAlignment().name, gamelog);
				 addstrAlt(CONST_justice181, gamelog);
				 addstrAlt(g.getCreatureJustice().sentence, gamelog);
				 addstrAlt(CONST_justice182, gamelog);
				 gamelog.nextMessage();
				 pressAnyKey();
				 showed = 1;
			 }
		 }
	 }
	 return showed;
 }
