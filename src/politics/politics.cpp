#include "../includes.h"
const string CONST_politics112 = "pro-Human Rights";
const string CONST_politics111 = "return attitude[]";
const string CONST_politics110 = "    ";
const string CONST_politics109 = "None of the items made it to the President's desk.";
const string CONST_politics107 = "*** VETO ***";
const string CONST_politics106 = "FORCED BY CONGRESS";
const string CONST_politics105 = "Dead in Congress";
const string CONST_politics104 = "President";
const string CONST_politics103 = "Press any key to watch the President.                   ";
const string CONST_politics102 = "VP";
const string CONST_politics100 = "Senate";
const string CONST_politics099 = "House";
const string CONST_politics098 = "Press any key to watch the votes unfold.";
const string CONST_politics097 = "Expand Prisoners' Rights";
const string CONST_politics096 = "Mandate Prison Rehabilitation";
const string CONST_politics095 = "To ";
const string CONST_politics094 = "Joint Resolution ";
const string CONST_politics093 = "Legislative Agenda ";
const string CONST_politics092 = "Congress is acting on legislation!";
const string CONST_politics091 = ", is appointed to the bench.";
const string CONST_politics090 = "the Honorable ";
const string CONST_politics089 = "Comrade ";
const string CONST_politics088 = "After much debate and televised testimony, a new justice,";
const string CONST_politics087 = "Press any key to see what happens.";
const string CONST_politics086 = ", is stepping down.";
const string CONST_politics085 = "Justice ";
const string CONST_politics084 = "Changing the Guard!";
const string CONST_politics083 = " for Status Quo";
const string CONST_politics082 = " for Change";
const string CONST_politics080 = "Press any key to watch the decisions unfold.";
const string CONST_politics077 = "A Decision could ";
const string CONST_politics076 = " vs. ";
const string CONST_politics075 = "United States";
const string CONST_politics074 = "Supreme Court Watch ";
const string CONST_politics073 = "The Supreme court is handing down decisions!";
const string CONST_politics072 = "A Recount was Necessary";
const string CONST_politics071 = "% No";
const string CONST_politics070 = "% Yes";
const string CONST_politics069 = "Press any key to watch the elections unfold.";
const string CONST_politics065 = "Proposition ";
const string CONST_politics064 = "Important Propositions ";
const string CONST_politics063 = "Press any key to continue the elections.   ";
const string CONST_politics062 = " (After Recount)";
const string CONST_politics061 = "Press any key to watch the election unfold.";
const string CONST_politics060 = "Mrs. ";
const string CONST_politics059 = "Mr. ";
const string CONST_politics058 = "Representative ";
const string CONST_politics057 = "Ret. General ";
const string CONST_politics056 = "Senator ";
const string CONST_politics055 = "Governor ";
const string CONST_politics054 = "Vice President ";
const string CONST_politics053 = "President ";
const string CONST_politics052 = "After a long primary campaign, the people have rallied around two leaders...";
const string CONST_politics051 = "After a long primary campaign, the people have rallied around three leaders...";
const string CONST_politics050 = "Presidential General Election ";
const string CONST_politics049 = "The Elections are being held today!";
const string CONST_politics048 = "Press any key to continue the elections.    ";
const string CONST_politics047 = "        ";
const string CONST_politics046 = "+";
const string CONST_politics045 = "   C+: ";
const string CONST_politics043 = "   C: ";
const string CONST_politics041 = "   m: ";
const string CONST_politics039 = "   L: ";
const string CONST_politics037 = "   L+: ";
const string CONST_politics035 = "   S: ";
const string CONST_politics034 = "Net change:";
const string CONST_politics033 = "S ";
const string CONST_politics032 = "L+";
const string CONST_politics031 = "L ";
const string CONST_politics030 = "m ";
const string CONST_politics029 = "C ";
const string CONST_politics028 = "C+";
const string CONST_politics020 = "House Elections ";
const string CONST_politics004 = "                    ";
const string CONST_politics002 = "Senate Elections ";
const string CONST_politics001 = "corporateSuffix.txt";
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
#include "../creature/creatureEnums.h"
/* fills a string with a proper name */
void generate_name(char *str, char gender = GENDER_NEUTRAL);
string lastname(bool x = false);
//#include "../common/commonactions.h"
int randomissue(bool core_only = 0);
#include "../common/commondisplay.h"
// for  void makedelimiter(int y=8,int x=0);
//#include "../monthly/EndGameStatus.h"
/* EndGameStatus - attempts to pass a constitutional amendment to help win the game */
void tossjustices(char canseethings);
/* EndGameStatus - attempts to pass a constitutional amendment to help win the game */
void amendment_termlimits(char canseethings);
#include "../cursesAlternative.h"
#include "../set_color_support.h"
#include <common\\getnames.h>
map<short, string> conservatiseLaw;
map<short, string> liberalizeLaw;
#include "../common/musicClass.h"
 string establishPrisonReform;
 string improvePrisonConditions;
extern string pressKeyToReflect;
extern string YEA;
extern string NAY;
vector<string> corporateSuffix;
 map<short, string> winnerOfElection;
 const string mostlyendings = "mostlyendings\\";
 extern string commaSpace;
#include "../customMaps.h"
 vector<file_and_text_collection> politics_text_file_collection = {
	 customText(&corporateSuffix, mostlyendings + CONST_politics001),
 };

 map<int, bool> stalinView = {
	 map<int, bool>::value_type(VIEW_STALIN,  false), // Liberals and Stalinists don't get along
	 map<int, bool>::value_type(VIEW_MOOD,  false), // Liberals and Stalinists don't get along
	 map<int, bool>::value_type(VIEW_GAY,  false), // Stalinists discriminate against gay people
	 map<int, bool>::value_type(VIEW_DEATHPENALTY,  false), // Stalinists execute lots of people
	 map<int, bool>::value_type(VIEW_TAXES,  true), // Stalinists support communist income redistribution
	 map<int, bool>::value_type(VIEW_NUCLEARPOWER,  false), // Stalinists believe the more nuclear, the better
	 map<int, bool>::value_type(VIEW_ANIMALRESEARCH,  false), // Stalinists are in favor of unethical research
	 map<int, bool>::value_type(VIEW_POLICEBEHAVIOR,  false), // Stalinists use police for brutal repression
	 map<int, bool>::value_type(VIEW_TORTURE,  false), // Stalinists torture their enemies
	 map<int, bool>::value_type(VIEW_INTELLIGENCE,  false), // Stalinists don't believe in privacy
	 map<int, bool>::value_type(VIEW_FREESPEECH,  false), // Stalinists don't allow any dissent
	 map<int, bool>::value_type(VIEW_GENETICS,  false), // Stalinists are in favor of unethical research
	 map<int, bool>::value_type(VIEW_JUSTICES,  false), // Liberals and Stalinists don't get along
	 map<int, bool>::value_type(VIEW_GUNCONTROL,  true), // Stalinists don't want any armed resistance
	 map<int, bool>::value_type(VIEW_SWEATSHOPS,  true), // Stalinists say, Workers of the world unite!
	 map<int, bool>::value_type(VIEW_POLLUTION,  false), // Stalinists don't care about pollution
	 map<int, bool>::value_type(VIEW_CORPORATECULTURE,  true), // Stalinists hate rich people and corporations
	 map<int, bool>::value_type(VIEW_CEOSALARY,  true), // Stalinists hate rich people and corporations
	 map<int, bool>::value_type(VIEW_WOMEN,  false), // Stalinists discriminate against women
	 map<int, bool>::value_type(VIEW_CIVILRIGHTS,  false), // Stalinists discriminate against ethnic groups
	 map<int, bool>::value_type(VIEW_DRUGS,  false), // Stalinists only allow vodka
	 map<int, bool>::value_type(VIEW_IMMIGRATION,  false), // Stalinists maintained tight border security at the Iron Curtain
	 map<int, bool>::value_type(VIEW_MILITARY,  false), // Stalinists use the military for brutal repression
	 map<int, bool>::value_type(VIEW_PRISONS,  false), // Stalinists annex Canada to fill it with gulags
	 map<int, bool>::value_type(VIEW_AMRADIO,  true), // Stalinists agree that Conservatives are bad
	 map<int, bool>::value_type(VIEW_CABLENEWS,  true), // Stalinists agree that Conservatives are bad
														//map<int, bool>::value_type( VIEW_POLITICALVIOLENCE,  true), // the LCS and Stalinists both like using political violence
														map<int, bool>::value_type(VIEW_LIBERALCRIMESQUAD,  false), // Liberals and Stalinists don't get along
														map<int, bool>::value_type(VIEW_LIBERALCRIMESQUADPOS,  false), // Liberals and Stalinists don't get along
														map<int, bool>::value_type(VIEW_CONSERVATIVECRIMESQUAD,  true), // Stalinists agree that Conservatives are bad
														map<int, bool>::value_type(VIEWNUM,  false), // Liberals and Stalinists don't get along
 };
 map<int, bool> stalinLaw = {
	 map<int, bool>::value_type(LAW_STALIN,  false), // Liberals and Stalinists don't get along
	 map<int, bool>::value_type(LAW_MOOD,  false), // Liberals and Stalinists don't get along
	 map<int, bool>::value_type(LAW_ABORTION,  true), // Stalinists agree that abortion is good, although technically they don't let women choose
	 map<int, bool>::value_type(LAW_ANIMALRESEARCH,  false), // Stalinists are in favor of unethical research
	 map<int, bool>::value_type(LAW_POLICEBEHAVIOR,  false), // Stalinists use police for brutal repression
	 map<int, bool>::value_type(LAW_PRIVACY,  false), // Stalinists don't believe in privacy
	 map<int, bool>::value_type(LAW_DEATHPENALTY,  false), // Stalinists execute lots of people
	 map<int, bool>::value_type(LAW_NUCLEARPOWER,  false), // Stalinists believe the more nuclear, the better
	 map<int, bool>::value_type(LAW_POLLUTION,  false), // Stalinists don't care about pollution
	 map<int, bool>::value_type(LAW_LABOR,  true), // Stalinists say, Workers of the world unite!
	 map<int, bool>::value_type(LAW_GAY,  false), // Stalinists discriminate against gay people
	 map<int, bool>::value_type(LAW_CORPORATE,  true), // Stalinists hate rich people and corporations
	 map<int, bool>::value_type(LAW_FREESPEECH,  false), // Stalinists don't allow any dissent
	 map<int, bool>::value_type(LAW_FLAGBURNING,  true), // Stalinists regularly burn flags
	 map<int, bool>::value_type(LAW_GUNCONTROL,  true), // Stalinists don't want any armed resistance
	 map<int, bool>::value_type(LAW_TAX,  true), // Stalinists support communist income redistribution
	 map<int, bool>::value_type(LAW_WOMEN,  false), // Stalinists discriminate against women
	 map<int, bool>::value_type(LAW_CIVILRIGHTS,  false), // Stalinists discriminate against ethnic groups
	 map<int, bool>::value_type(LAW_DRUGS,  false), // Stalinists only allow vodka
	 map<int, bool>::value_type(LAW_IMMIGRATION,  false), // Stalinists maintained tight border security at the Iron Curtain
	 map<int, bool>::value_type(LAW_ELECTIONS,  false), // Stalinists don't even have elections
	 map<int, bool>::value_type(LAW_MILITARY,  false), // Stalinists use the military for brutal repression
	 map<int, bool>::value_type(LAW_PRISONS,  false), // Stalinists annex Canada to fill it with gulags
	 map<int, bool>::value_type(LAW_TORTURE,  false), // Stalinists torture their enemies
	 map<int, bool>::value_type(LAWNUM,  false), // Liberals and Stalinists don't get along
 };
 /* returns true if Stalinists agree with Elite Liberals on a view/law, false if they strongly disagree with libs  *
 * the input bool islaw, if true, returns Stalinist opinion on laws, if false, returns Stalinist opinion on views */
 bool stalinview(short view, bool islaw)
 {
	 if (islaw)
	 {
		 if (stalinLaw.count(view)) {
			 return stalinLaw[view];
		 }
		 else
			 return false; // if the law doesn't exist, assume false
	 }
	 else
	 {
		 if (stalinView.count(view)) {
			 return stalinView[view];
		 }
		 else
			 return false; // if the view doesn't exist, assume false
	 }
 }
 map<int, int> lawReturnAttitude = {
	 map<int, int>::value_type(LAW_ABORTION, VIEW_WOMEN), //XXX, There is no ``VIEW_ABORTION''!
	 map<int, int>::value_type(LAW_ANIMALRESEARCH, VIEW_ANIMALRESEARCH),
	 map<int, int>::value_type(LAW_POLICEBEHAVIOR, VIEW_POLICEBEHAVIOR),
	 map<int, int>::value_type(LAW_PRIVACY, VIEW_INTELLIGENCE),
	 map<int, int>::value_type(LAW_DEATHPENALTY, VIEW_DEATHPENALTY),
	 map<int, int>::value_type(LAW_NUCLEARPOWER, VIEW_NUCLEARPOWER),
	 map<int, int>::value_type(LAW_POLLUTION, VIEW_POLLUTION),
	 map<int, int>::value_type(LAW_LABOR, VIEW_SWEATSHOPS),
	 map<int, int>::value_type(LAW_GAY, VIEW_GAY),
	 map<int, int>::value_type(LAW_FREESPEECH, VIEW_FREESPEECH),
	 map<int, int>::value_type(LAW_TAX, VIEW_TAXES),
	 map<int, int>::value_type(LAW_FLAGBURNING, VIEW_FREESPEECH),  // <-- I'm keeping this pure free speech instead of free speech
	 map<int, int>::value_type(LAW_WOMEN, VIEW_WOMEN),             // plus political violence. Ideologically, there's no association
	 map<int, int>::value_type(LAW_CIVILRIGHTS, VIEW_CIVILRIGHTS), // between flag burning and violence. - Jonathan S. Fox
	 map<int, int>::value_type(LAW_DRUGS, VIEW_DRUGS),
	 map<int, int>::value_type(LAW_IMMIGRATION, VIEW_IMMIGRATION), //XXX, VIEW_DRUGS?
	 map<int, int>::value_type(LAW_MILITARY, VIEW_MILITARY),
	 map<int, int>::value_type(LAW_TORTURE, VIEW_TORTURE),
	 map<int, int>::value_type(LAW_GUNCONTROL, VIEW_GUNCONTROL),
	 map<int, int>::value_type(LAW_PRISONS, VIEW_PRISONS),
 };
 /* politics - checks the prevailing attitude on a specific law, or overall */
 int publicmood(const int old_l)
 {
	 int l = old_l;
	 if (lawReturnAttitude.count(l)) {
		 return lawReturnAttitude[l];
	 }
	 else {
		 extern short attitude[VIEWNUM];
		 switch (l)
		 {  // All laws should be affected by exactly one issue if there is a direct
			// correlation between that law and an issue. For example, police behavior
			// as a law should depend only upon police behavior as an issue. This keeps
			// the game logical to the player and ensures that the public opinion polls
			// displayed in-game accurately predict how people will vote in specific
			// issues. For a handful of laws, we might not have a directly correlating
			// issue; for example, as of this writing, there is no issue asking people's
			// opinions on torture. In this case, we can use the nearest issue, or we
			// can mix two closely related ones. As a general principle, try to avoid
			// getting too complicated here; this is under-the-hood stuff the player
			// will never appreciate, so it should be kept as simple and transparent as
			// possible so as to avoid creating unexpected results that will only confuse
			// players, like people refusing to further regulate nuclear power because
			// one of the other issues besides nuclear power is conservative, even when
			// the nuclear power issue is 100% Liberal. - Jonathan S. Fox
		 case LAW_CORPORATE: return (attitude[VIEW_CORPORATECULTURE] + attitude[VIEW_CEOSALARY]) / 2; // <-- We'll be merging these two views here because there is no CEO salary law.
																									  // The issue is there for flavor, and falls under the same umbrella of
																									  // corporate regulation. - Jonathan S. Fox
		 case LAW_STALIN:
			 l = 0;
			 for (int v = 0; v < VIEWNUM - 3; v++)
				 if (stalinview(v, false)) l += 100 - attitude[v];
				 else l += attitude[v];
				 return l / (VIEWNUM - 3);
		 case LAW_ELECTIONS:
		 case LAW_MOOD:
		 default: //eg. -1
			 l = 0;
			 for (int v = 0; v < VIEWNUM - 3; v++) l += attitude[v];
			 return l / (VIEWNUM - 3);
		 }
	 }
 }
 /* common - shifts public opinion on an issue */
 void change_public_opinion(int v, int power, char affect, char cap)
 {
	 extern short attitude[VIEWNUM];
	 extern short public_interest[VIEWNUM];
	 extern short background_liberal_influence[VIEWNUM];
	 // First note this in the liberal influence -- mostly for the
	 // sake of the nice visual intelligence report entry
	 if (v < VIEWNUM - 5)
	 {
		 background_liberal_influence[v] += power * 10;
	 }
	 if (v == VIEW_LIBERALCRIMESQUAD)affect = 0;
	 if (v == VIEW_LIBERALCRIMESQUADPOS)affect = 0;
	 if (v == VIEW_LIBERALCRIMESQUADPOS)
	 {
		 int mood = publicmood(-1);
		 if (cap > mood + 40)cap = mood + 40;
	 }
	 int effpower = power;
	 // Affect is whether the LCS is publicly known to be behind
	 // the circumstances creating the public opinion change
	 if (affect == 1)
	 {
		 // Aff is the % of people who know/care about the LCS
		 int aff = attitude[VIEW_LIBERALCRIMESQUAD];
		 // Rawpower is the amount of the action proportional
		 // to the people who, not having heard of the LCS,
		 // do not allow the LCS' reputation to affect their
		 // opinions
		 int rawpower = (int)((float)power * (float)(100 - aff) / 100.0f);
		 // Affected power is the remainder of the action besides
		 // rawpower, the amount of the people who know of the LCS
		 // and have it alter their opinion
		 int affectedpower = power - rawpower;
		 if (affectedpower > 0)
		 {
			 // Dist is a combination of the relative popularity of the LCS
			 // to the issue and the absolute popularity of the LCS. Very
			 // popular LCS on a very unpopular issue is very influential.
			 // Very unpopular LCS on a very popular issue has the ability
			 // to actually have a reverse effect.
			 int dist = attitude[VIEW_LIBERALCRIMESQUADPOS] - attitude[v] +
				 attitude[VIEW_LIBERALCRIMESQUADPOS] - 50;
			 // Affected power is then scaled by dist -- if the LCS is
			 // equally popular as the issue, it's equally powerful as
			 // the rawpower. For every 10% up or down past there, it's
			 // 10% more or less powerful.
			 affectedpower = (int)(((float)affectedpower*(100.0 + (float)dist)) / 100.0f);
		 }
		 // Effpower is then the sum of the rawpower (people who don't know
		 // about the LCS) and the affectedpower (people who do know
		 // about the LCS and had their judgment swayed by their opinion
		 // of it).
		 effpower = rawpower + affectedpower;
	 }
	 else if (affect == -1)
	 {
		 // Simplifed algorithm for affect by CCS respect
		 effpower = power * (100 - attitude[VIEW_CONSERVATIVECRIMESQUAD]) / 100;
	 }
	 if (v == VIEW_LIBERALCRIMESQUAD)
	 {
		 //Only half the country will ever hear about the LCS at one time,
		 //and people will only grudgingly lose fear of it
		 if (effpower < -5)effpower = -5;
		 if (effpower > 50)effpower = 50;
	 }
	 else if (v == VIEW_LIBERALCRIMESQUADPOS)
	 {
		 //Only 50% of the country can be swayed at once in their views
		 //of the LCS negatively, 5% positively
		 if (effpower < -50)effpower = -50;
		 if (effpower > 5)effpower = 5;
	 }
	 //Scale the magnitude of the effect based on how much
	 //people are paying attention to the issue
	 effpower = (int)(effpower*(1 + (float)public_interest[v] / 50));
	 //Then affect public interest
	 if (public_interest[v] < cap || (v == VIEW_LIBERALCRIMESQUADPOS && public_interest[v] < 100))
		 public_interest[v] += abs(effpower);
	 if (effpower > 0)
	 {
		 //Some things will never persuade the last x% of the population.
		 //If there's a cap on how many people will be impressed, this
		 //is where that's handled.
		 if (attitude[v] + effpower > cap)
		 {
			 if (attitude[v] > cap)effpower = 0;
			 else effpower = cap - attitude[v];
		 }
	 }
	 //Finally, apply the effect.
	 attitude[v] += effpower;
	 if (attitude[v] < 0)attitude[v] = 0;
	 if (attitude[v] > 100)attitude[v] = 100;
 }



 /* politics -- gets the leaning of an issue voter for an election */
 int getswingvoter(bool stalin)
 {
	 extern short attitude[VIEWNUM];
	 // Take a random voter, calculate how liberal or conservative they are
	 // If stalin parameter is true, it calculates how libertarian or Stalinist they are instead
	 int bias = publicmood(-1 - stalin) - LCSrandom(100), vote = -2;
	 if (bias > 25)bias = 25;
	 if (bias < -25)bias = -25;
	 // Each issue they roll for their opinion on a 50-point subset of the
	 // spectrum, determined by bias -- high liberal/libertarian bias only rolls on the
	 // liberal/libertarian end of the spectrum, high conservative/Stalinist bias only rolls on
	 // the conservative/Stalinist end of the spectrum
	 for (int i = 0; i < 4; i++)
	 {
		 int issue = randomissue(true);
		 if (25 + LCSrandom(50) - bias < ((stalin&&stalinview(issue, false)) ? 100 - attitude[issue] : attitude[issue])) vote++;
	 }
	 return vote;
 }
 /* politics - calculate presidential approval */
 int presidentapproval()
 {
	 extern short presparty;
	 extern short exec[EXECNUM];
	 //Calculate Presidential approval rating
	 int approval = 0;
	 for (int i = 0; i < 1000; i++)
	 {
		 if (i % 2 == 0 && LCSrandom(2)) approval++;    // Partyline supporter (~25%)
		 else if (i % 2 == 1 && LCSrandom(2)) continue; // Partyline opponent  (~25%)
		 else                                    // Swing issue voter   (~50%) (should be more than in the real election)
		 {
			 // Get their leanings as an issue voter
			 int vote = getswingvoter(exec[EXEC_PRESIDENT] == ALIGN_STALINIST);
			 // If their views are close to the President's views, they should
			 // approve, but might not if their party leaning conflicts with
			 // the president's
			 // Moderate president from the Conservative party is only supported
			 // by moderates and Conservatives
			 // Moderate president from the Liberal party is only supported
			 // by moderates and Liberals
			 int presalign = exec[EXEC_PRESIDENT] == ALIGN_STALINIST ? ALIGN_ARCHCONSERVATIVE : exec[EXEC_PRESIDENT];
			 if (abs(presalign - vote) <= 1 && (presparty != LIBERAL_PARTY ? vote <= 0 : vote >= 0)) approval++;
		 }
	 }
	 return approval;
 }
 /* politics -- gets the leaning of a partyline voter for an election */
 int getsimplevoter(int leaning)
 {
	 extern short attitude[VIEWNUM];
	 // no need for this to deal with Stalinism, this function deliberately only deals with the liberal vs. conservative spectrum
	 int vote = leaning - 1;
	 for (int i = 0; i < 2; i++) if (LCSrandom(100) < attitude[randomissue(true)]) vote++;
	 return vote;
 }

 /* politics -- appoints a figure to an executive office, based on the President's alignment */
 void fillCabinetPost(int position)
 {
	 extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	 extern short exec[EXECNUM];
	 // Set alignment
	 if (exec[EXEC_PRESIDENT] == ALIGN_ARCHCONSERVATIVE) exec[position] = ALIGN_ARCHCONSERVATIVE;
	 else if (exec[EXEC_PRESIDENT] == ALIGN_ELITELIBERAL) exec[position] = ALIGN_ELITELIBERAL;
	 else if (exec[EXEC_PRESIDENT] == ALIGN_STALINIST) exec[position] = ALIGN_STALINIST;
	 else exec[position] = exec[EXEC_PRESIDENT] + LCSrandom(3) - 1;
	 // Set name
	 if (exec[position] == ALIGN_ARCHCONSERVATIVE) generate_name(execname[position], GENDER_WHITEMALEPATRIARCH);
	 else if (exec[position] == ALIGN_CONSERVATIVE) generate_name(execname[position], GENDER_MALE);
	 else generate_name(execname[position]);
 }
 /* politics -- promotes the Vice President to President, and replaces VP */
 void promoteVP()
 {
	 extern short presparty;
	 extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	 extern short exec[EXECNUM];
	 exec[EXEC_PRESIDENT] = exec[EXEC_VP]; // VP takes over as President
	 strcpy(execname[EXEC_PRESIDENT], execname[EXEC_VP]);
	 switch (exec[EXEC_PRESIDENT])
	 { // make sure presparty is set correctly (if old President was moderate they could've been in Liberal OR Conservative Party,
	 case ALIGN_ARCHCONSERVATIVE: // and new President might have a political alignment incompatible with that party)
	 case ALIGN_CONSERVATIVE:
		 presparty = CONSERVATIVE_PARTY; break; // Conservatives and Arch-Conservatives align with the Conservative Party
	 case ALIGN_MODERATE:
		 break; // same party as previous President (either Liberal Party or Conservative Party)
	 case ALIGN_LIBERAL:
	 case ALIGN_ELITELIBERAL:
		 presparty = LIBERAL_PARTY; break; // Liberals and Elite Liberals align with the Liberal Party
	 case ALIGN_STALINIST:
		 presparty = STALINIST_PARTY; break; // Stalinists align with the Stalinist Party
	 }
	 fillCabinetPost(EXEC_VP); // the vacant VP slot needs to be filled
	 if (abs(exec[EXEC_PRESIDENT]) > 1)
	 {  // new President has extreme views... make sure all cabinet members agree with new President
		 if (exec[EXEC_PRESIDENT] != exec[EXEC_STATE]) fillCabinetPost(EXEC_STATE);
		 if (exec[EXEC_PRESIDENT] != exec[EXEC_ATTORNEY]) fillCabinetPost(EXEC_ATTORNEY);
	 }
	 else
	 {  // new President has fairly moderate views, but anyone who differs too much from them must be replaced
		 if (abs(exec[EXEC_PRESIDENT] - exec[EXEC_STATE]) > 1) fillCabinetPost(EXEC_STATE);
		 if (abs(exec[EXEC_PRESIDENT] - exec[EXEC_ATTORNEY]) > 1) fillCabinetPost(EXEC_ATTORNEY);
	 }
 }
 void printSenateElectionsHeader() {
	 extern MusicClass music;
	 extern int year;
	 music.play(MUSIC_ELECTIONS);
	 eraseAlt();
	 set_color_easy(WHITE_ON_BLACK_BRIGHT);
	 mvaddstrAlt(0, 0, CONST_politics002);
	 addstrAlt(year);
 }
 void printPressAnyKeyElections() {
	 set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(23, 0, CONST_politics069);
	 pressAnyKey();
 }
 void printSenateStatus(const int change[]) {
	 extern bool stalinmode;
	 extern char disbanding;

	 set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(20, 0, CONST_politics034);
	 if (stalinmode)
	 {
		 addstrAlt(CONST_politics035);
		 if (change[5] > 0) addstrAlt(CONST_politics046);
		 addstrAlt(change[5]);
	 }
	 addstrAlt(CONST_politics037);
	 if (change[4] > 0) addstrAlt(CONST_politics046);
	 addstrAlt(change[4]);
	 addstrAlt(CONST_politics039);
	 if (change[3] > 0) addstrAlt(CONST_politics046);
	 addstrAlt(change[3]);
	 addstrAlt(CONST_politics041);
	 if (change[2] > 0) addstrAlt(CONST_politics046);
	 addstrAlt(change[2]);
	 addstrAlt(CONST_politics043);
	 if (change[1] > 0) addstrAlt(CONST_politics046);
	 addstrAlt(change[1]);
	 addstrAlt(CONST_politics045);
	 if (change[0] > 0) addstrAlt(CONST_politics046);
	 addstrAlt(change[0]);
	 addstrAlt(CONST_politics047);
	 if (!disbanding) pause_ms(30);
 }
 void printSenateWinner(const int change[]) {
	 const int mood = publicmood(LAW_MOOD);
	 moveAlt(21, 0);
	 signed char winner;
	 if (change[5] > 0 && change[5] > change[0] + change[1] && change[5] > change[3] + change[4]) // Stalinist increased and Stalinist gain is more than C or L side gain/loss
		 winner = ALIGN_STALINIST;
	 else if (change[0] + change[1] > change[3] + change[4]) // C side gain/loss is more than L side gain/loss
	 {
		 if (change[1] < 0 && mood < 25) winner = ALIGN_ARCHCONSERVATIVE;
		 else winner = ALIGN_CONSERVATIVE;
	 }
	 else if (change[3] + change[4] > change[0] + change[1]) // L side gain/loss is more than C side gain/loss
	 {
		 if (change[3] < 0 && mood>75) winner = ALIGN_ELITELIBERAL;
		 else winner = ALIGN_LIBERAL;
	 }
	 else if (change[0] > 0 && change[4] <= 0 && change[5] <= 0) // C+ increased and L+ and Stalinist both same or decreased
	 {
		 if (mood < 25) winner = ALIGN_ARCHCONSERVATIVE;
		 else winner = ALIGN_CONSERVATIVE;
	 }
	 else if (change[4] > 0 && change[0] <= 0 && change[5] <= 0) // L+ increased and C+ and Stalinist both same or decreased
	 {
		 if (mood > 75) winner = ALIGN_ELITELIBERAL;
		 else winner = ALIGN_LIBERAL;
	 }
	 else if (change[5] > 0 && change[0] <= 0 && change[4] <= 0) // Stalinist increased and C+ and L+ both same or decreased
		 winner = ALIGN_STALINIST;
	 else winner = ALIGN_MODERATE; // nobody won
	 addstrAlt(winnerOfElection[winner]);
	 mvaddstrAlt(22, 0, CONST_politics048);
	 pressAnyKey();
 }
 void printSingleSenator(const int s, const int x, const int y) {
	 extern short senate[SENATENUM];
	 set_alignment_color(senate[s], true);
	 mvaddstrAlt(y, x, CONST_politics004);
	 mvaddstrAlt(y, x, getalign(senate[s], false));
 }
 void elections_senate(int senmod, char canseethings)
 {
	 extern MusicClass music;
	 extern int year;
	 extern bool termlimits;
	 extern bool stalinmode;
	 extern char disbanding;
	 extern short lawList[LAWNUM];
	 extern short senate[SENATENUM];
	 const int mood = publicmood(LAW_MOOD);
	 const int stalinmood = publicmood(LAW_STALIN);
	 if (canseethings)
	 {
		 printSenateElectionsHeader();
	 }
	 {
		 int x = 0;
		 int y = 2;
		 for (int s = 0; s < SENATENUM; s++)
		 {
			 if (senmod != -1 && s % 3 != senmod)continue;
			 if (canseethings)
			 {
				 set_alignment_color(senate[s], true);
				 mvaddstrAlt(y, x, getalign(senate[s], false));
			 }
			 x += 20;
			 if (x > 70) x = 0, y++;
		 }
	 }
	 if (canseethings)
	 {
		 printPressAnyKeyElections();
	 }
	 int vote, change[6] = { 0,0,0,0,0,0 };
	 {
		 int x = 0;
		 int y = 2;
		 for (int s = 0; s < SENATENUM; s++)
		 {
			 if (senmod != -1 && s % 3 != senmod) continue;
			 vote = -2;
			 for (int i = 0; i < 4; i++) if (mood > LCSrandom(100)) vote++;
			 if (stalinmode&&stalinmood < LCSrandom(100) && stalinmood < LCSrandom(100) && stalinmood < LCSrandom(100) && stalinmood < LCSrandom(100)) vote = 3;
			 change[senate[s] + 2]--;
			 if (termlimits) senate[s] = vote;
			 else
			 {
				 int vote2;
				 bool first = true;
				 do {
					 vote2 = -2;
					 for (int i = 0; i < 4; i++) if (mood > LCSrandom(100)) vote2++;
					 if (stalinmode&&stalinmood < LCSrandom(100) && stalinmood < LCSrandom(100) && stalinmood < LCSrandom(100) && stalinmood < LCSrandom(100)) vote2 = 3;
					 if (first) switch (lawList[LAW_ELECTIONS])
					 {
					 case -2: if (LCSrandom(3)) vote2 = senate[s]; break; // 2/3 chance of incumbent winning no matter what (huge   advantage)
					 case -1: if (LCSrandom(2)) vote2 = senate[s]; break; // 1/2 chance of incumbent winning no matter what (big    advantage)
					 case  0: if (!LCSrandom(3)) vote2 = senate[s]; break; // 1/3 chance of incumbent winning no matter what (medium advantage)
					 case  1: if (!LCSrandom(5)) vote2 = senate[s]; break; // 1/5 chance of incumbent winning no matter what (small  advantage)
					 case  2: if (!LCSrandom(8)) vote2 = senate[s]; break; // 1/8 chance of incumbent winning no matter what (tiny   advantage)
					 }
					 first = false;
				 } while (vote2 != senate[s] && vote2 != vote);
				 senate[s] = vote2;
			 }
			 change[senate[s] + 2]++;
			 if (canseethings)
			 {
				 printSingleSenator(s, x, y);
			 }
			 x += 20;
			 if (x > 70) x = 0, y++;
			 if (canseethings)
			 {
				 printSenateStatus(change);
			 }
		 }
	 }
	 if (canseethings)
	 {
		 printSenateWinner(change);
	 }
 }
 void printSingleHouseMember(const int h, const int y, const int x) {
	 extern short house[HOUSENUM];
	 moveAlt(y, x);
	 switch (house[h]) {
	 case -2:
		 set_color_easy(RED_ON_BLACK_BRIGHT);
		 addstrAlt(CONST_politics028);
		 break;

	 case -1:
		 set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
		 addstrAlt(CONST_politics029);
		 break;

	 case 0:
		 set_color_easy(YELLOW_ON_BLACK_BRIGHT);
		 addstrAlt(CONST_politics030);
		 break;

	 case 1:
		 set_color_easy(CYAN_ON_BLACK_BRIGHT);
		 addstrAlt(CONST_politics031);
		 break;

	 case 2:
		 set_color_easy(GREEN_ON_BLACK_BRIGHT);
		 addstrAlt(CONST_politics032);
		 break;

	 default:
		 set_color_easy(RED_ON_BLACK_BRIGHT);
		 addstrAlt(CONST_politics033);
		 break;
	 }
 }
 void printHouseMembership() {
	 int x = 0;
	 int y = 2;
	 for (int h = 0; h < HOUSENUM; h++)
	 {

		 printSingleHouseMember(h, y, x);

		 x += 3;
		 if (x > 78) x = 0, y++;
	 }
 }
 void printHouseChanges(const int x, const int y, const int h, const int change[]) {
	 extern bool stalinmode;
	 extern char disbanding;
	 printSingleHouseMember(h, y, x);
	 set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(20, 0, CONST_politics034);
	 if (stalinmode)
	 {
		 addstrAlt(CONST_politics035);
		 if (change[5] > 0) addstrAlt(CONST_politics046);
		 addstrAlt(change[5]);
	 }
	 addstrAlt(CONST_politics037);
	 if (change[4] > 0) addstrAlt(CONST_politics046);
	 addstrAlt(change[4]);
	 addstrAlt(CONST_politics039);
	 if (change[3] > 0) addstrAlt(CONST_politics046);
	 addstrAlt(change[3]);
	 addstrAlt(CONST_politics041);
	 if (change[2] > 0) addstrAlt(CONST_politics046);
	 addstrAlt(change[2]);
	 addstrAlt(CONST_politics043);
	 if (change[1] > 0) addstrAlt(CONST_politics046);
	 addstrAlt(change[1]);
	 addstrAlt(CONST_politics045);
	 if (change[0] > 0) addstrAlt(CONST_politics046);
	 addstrAlt(change[0]);
	 addstrAlt(CONST_politics047);
	 if (!disbanding) pause_ms(5);
 }
 void printWinnerOfElection(const int change[]) {
	 const int mood = publicmood(LAW_MOOD);
	 extern char disbanding;
	 moveAlt(21, 0);
	 signed char winner;
	 if (change[5] > 0 && change[5] > change[0] + change[1] && change[5] > change[3] + change[4]) // Stalinist increased and Stalinist gain is more than C or L side gain/loss
		 winner = ALIGN_STALINIST;
	 else if (change[0] + change[1] > change[3] + change[4]) // C side gain/loss is more than L side gain/loss
	 {
		 if (change[1] < 0 && mood < 25) winner = ALIGN_ARCHCONSERVATIVE;
		 else winner = ALIGN_CONSERVATIVE;
	 }
	 else if (change[3] + change[4] > change[0] + change[1]) // L side gain/loss is more than C side gain/loss
	 {
		 if (change[3] < 0 && mood>75) winner = ALIGN_ELITELIBERAL;
		 else winner = ALIGN_LIBERAL;
	 }
	 else if (change[0] > 0 && change[4] <= 0 && change[5] <= 0) // C+ increased and L+ and Stalinist both same or decreased
	 {
		 if (mood < 25) winner = ALIGN_ARCHCONSERVATIVE;
		 else winner = ALIGN_CONSERVATIVE;
	 }
	 else if (change[4] > 0 && change[0] <= 0 && change[5] <= 0) // L+ increased and C+ and Stalinist both same or decreased
	 {
		 if (mood > 75) winner = ALIGN_ELITELIBERAL;
		 else winner = ALIGN_LIBERAL;
	 }
	 else if (change[5] > 0 && change[0] <= 0 && change[4] <= 0) // Stalinist increased and C+ and L+ both same or decreased
		 winner = ALIGN_STALINIST;
	 else winner = ALIGN_MODERATE; // nobody won
	 addstrAlt(winnerOfElection[winner]);
	 if (!disbanding)
	 {
		 mvaddstrAlt(22, 0, CONST_politics048);
		 pressAnyKey();
	 }
	 else pause_ms(800);
 }
 void printHouseElectionsHeader() {
	 extern MusicClass music;
	 extern int year;
	 music.play(MUSIC_ELECTIONS);
	 eraseAlt();
	 set_color_easy(WHITE_ON_BLACK_BRIGHT);
	 mvaddstrAlt(0, 0, CONST_politics020);
	 addstrAlt(year);
	 printHouseMembership();
	 set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(23, 0, CONST_politics069);
	 pressAnyKey();
 }
 void elections_house(const char canseethings)
 {
	 extern bool termlimits;
	 extern bool stalinmode;
	 extern char disbanding;
	 extern short lawList[LAWNUM];
	 extern short house[HOUSENUM];
	 const int mood = publicmood(LAW_MOOD);
	 const int stalinmood = publicmood(LAW_STALIN);
	 if (canseethings)
	 {
		 printHouseElectionsHeader();
	 }
	 int change[6] = { 0,0,0,0,0,0 };
	 {
		 int x = 0;
		 int y = 2;
		 for (int h = 0; h < HOUSENUM; h++)
		 {
			 int vote = -2;
			 for (int i = 0; i < 4; i++) if (mood > LCSrandom(100)) vote++;
			 if (stalinmode&&stalinmood < LCSrandom(100) && stalinmood < LCSrandom(100) && stalinmood < LCSrandom(100) && stalinmood < LCSrandom(100)) vote = 3;
			 change[house[h] + 2]--;
			 if (termlimits) house[h] = vote;
			 else
			 {
				 int vote2;
				 bool first = true;
				 do {
					 vote2 = -2;
					 for (int i = 0; i < 4; i++) if (mood > LCSrandom(100)) vote2++;
					 if (stalinmode&&stalinmood < LCSrandom(100) && stalinmood < LCSrandom(100) && stalinmood < LCSrandom(100) && stalinmood < LCSrandom(100)) vote2 = 3;
					 if (first) switch (lawList[LAW_ELECTIONS])
					 {
					 case -2: if (LCSrandom(3)) vote2 = house[h]; break; // 2/3 chance of incumbent winning no matter what (huge   advantage)
					 case -1: if (LCSrandom(2)) vote2 = house[h]; break; // 1/2 chance of incumbent winning no matter what (big    advantage)
					 case  0: if (!LCSrandom(3)) vote2 = house[h]; break; // 1/3 chance of incumbent winning no matter what (medium advantage)
					 case  1: if (!LCSrandom(5)) vote2 = house[h]; break; // 1/5 chance of incumbent winning no matter what (small  advantage)
					 case  2: if (!LCSrandom(8)) vote2 = house[h]; break; // 1/8 chance of incumbent winning no matter what (tiny   advantage)
					 }
					 first = false;
				 } while (vote2 != house[h] && vote2 != vote);
				 house[h] = vote2;
			 }
			 change[house[h] + 2]++;
			 if (canseethings)
			 {
				 printHouseChanges(x, y, h, change);
			 }

			 x += 3;
			 if (x > 78) x = 0, y++;
		 }
	 }
	 if (canseethings)
	 {
		 printWinnerOfElection(change);
	 }
 }
 bool voteOnBill(const char canseethings, const int mood, const int propdir, const int p) {
	 bool yeswin = false;
	 bool recount = false;
	 for (int l = 0, yesvotes = 0; l < 1000; l++)
	 {
		 if (LCSrandom(100) < mood ? propdir == 1 : propdir == -1) yesvotes++;
		 if (l == 999)
		 {
			 if (yesvotes > 500) yeswin = true;
			 else if (yesvotes == 500) yeswin = (LCSrandom(100) < mood ? propdir == 1 : propdir == -1), recount = true;
		 }
		 if (canseethings && (l % 10 == 9))
		 {
			 if ((l != 999 && yesvotes > l / 2) || (l == 999 && yeswin)) set_color_easy(WHITE_ON_BLACK_BRIGHT);
			 else if (yesvotes < l / 2 || l == 999) set_color_easy(BLACK_ON_BLACK_BRIGHT);
			 else set_color_easy(WHITE_ON_BLACK);
			 mvaddstrAlt(p * 3 + 2, 70, yesvotes / 10);
			 addcharAlt('.');
			 addstrAlt(yesvotes % 10);
			 addstrAlt(CONST_politics070);
			 if ((l != 999 && yesvotes < l / 2) || (l == 999 && !yeswin)) set_color_easy(WHITE_ON_BLACK_BRIGHT);
			 else if (yesvotes > l / 2 || l == 999) set_color_easy(BLACK_ON_BLACK_BRIGHT);
			 else set_color_easy(WHITE_ON_BLACK);
			 mvaddstrAlt(p * 3 + 3, 70, (l + 1 - yesvotes) / 10);
			 addcharAlt('.');
			 addstrAlt((l + 1 - yesvotes) % 10);
			 addstrAlt(CONST_politics071);
			 pause_ms(10);
		 }
	 }
	 if (canseethings&&recount)
	 {
		 set_color_easy(WHITE_ON_BLACK_BRIGHT);
		 mvaddstrAlt(p * 3 + 3, 0, CONST_politics072);
	 }
	 return yeswin;
 }
 void printCandiadates(const char candidate[3][POLITICIAN_NAMELEN + 1]) {
	 extern short presparty;
	 extern bool stalinmode;
	 extern char disbanding;
	 extern short execterm;
	 extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	 extern Log gamelog;

	 for (int c = 0; c < 2 + stalinmode; c++)
	 {
		 // Pick color by political orientation
		 set_alignment_color(candidate[c][0], true);
		 moveAlt(8 - ((c + 1) % 3) * 2, 0);
		 // Choose title -- president or vice president special titles, otherwise
		 // pick based on historically likely titles (eg, governor most likely...)
		 if (c == presparty && execterm == 1) addstrAlt(CONST_politics053);
		 else if (c == presparty && !strcmp(candidate[c] + 1, execname[EXEC_VP])) addstrAlt(CONST_politics054);
		 else if (LCSrandom(2)) addstrAlt(CONST_politics055);
		 else if (LCSrandom(2)) addstrAlt(CONST_politics056);
		 else if (LCSrandom(2)) addstrAlt(CONST_politics057);
		 else if (LCSrandom(2)) addstrAlt(CONST_politics058);
		 else if (LCSrandom(2)) addstrAlt(CONST_politics059);
		 else addstrAlt(CONST_politics060);
		 addstrAlt(candidate[c] + 1);
		 addstrAlt(commaSpace + getalign(candidate[c][0], false));
	 }
	 if (!disbanding)
	 {
		 set_color_easy(WHITE_ON_BLACK);
		 mvaddstrAlt(8 + stalinmode * 2, 0, CONST_politics061);
		 pressAnyKey();
	 }
	 else pause_ms(200);
 }
 int singleVote(const int l, const char liberalCandiadate, const char conservativeCandiadate) {
	 extern bool stalinmode;
	 extern char disbanding;
	 int partyVote;
	 if (l % 2 == 0 && LCSrandom(5))
	 {  // Partyline Liberals (~40%) - except when stalin mode is enabled they can go Stalinist sometimes
		 if (!stalinmode || getswingvoter(true) != -2 || getswingvoter(false) == 2) // if we aren't in stalin mode or they don't agree with Stalinism or they are an Elite Liberal
			 partyVote = LIBERAL_PARTY;                                        // go with Liberal Party affiliation (Good Loyal Liberal!)
		 else partyVote = STALINIST_PARTY;                                    // otherwise, this Liberal's gone Stalinist and betrayed Liberalism (TRAITOR!)
	 }
	 else if (l % 2 == 1 && LCSrandom(5))
	 {  // Partyline Conservatives (~40%) - except when stalin mode is enabled they can go Stalinist sometimes
		 if (!stalinmode || getswingvoter(true) != -2 || getswingvoter(false) == -2) // if we aren't in stalin mode or they don't agree with Stalinism or they are an Arch-Conservative
			 partyVote = CONSERVATIVE_PARTY;                                    // go with Conservative Party affiliation (Good Loyal Conservative!)
		 else partyVote = STALINIST_PARTY;                                     // otherwise, this Conservative's gone Stalinist and betrayed Conservatism (TRAITOR!)
	 }
	 else // Swing Issue Voters (~20%)
	 {
		 // Get the leanings of an issue voter
		 int vote = getswingvoter(false);
		 // If they agree with the Stalinist candidate and Stalinist mode is enabled,
		 // cast a vote for the Stalinist candidate
		 if (stalinmode&&getswingvoter(true) == -2)
			 partyVote = STALINIST_PARTY;
		 // If they are to the left or equal to the liberal candidate,
		 // and they disagree with the other candidate(s), cast a
		 // vote for the liberal candidate.
		 else if (vote >= liberalCandiadate && vote != conservativeCandiadate)
			 partyVote = LIBERAL_PARTY;
		 // If they are to the right or equal to the conservative candidate,
		 // and they disagree with the other candidate(s), cast a vote
		 // for the conservative candidate.
		 else if (vote <= conservativeCandiadate && vote != liberalCandiadate)
			 partyVote = CONSERVATIVE_PARTY;
		 // If they disagree with all the candidates, vote randomly.
		 else partyVote = LCSrandom(2 + stalinmode);
	 }
	 return partyVote;
 }
 void presidentialElection(const char canseethings) {

	 extern short presparty;
	 extern bool stalinmode;
	 extern char disbanding;
	 extern short execterm;
	 extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	 extern short exec[EXECNUM];
	 extern Log gamelog;
	 // IsaacG This is goddamn disgusting.  a candiadate is a single char representing alignment followed by a char* of their name
	 char candidate[3][POLITICIAN_NAMELEN + 1];
	 int votes[3] = { 0,0,0 };
	 //Primaries
	 int approvepres = 0, approveveep = 0;              // presidential & vice-presidential approval within own party
	 int libvotes[3] = { 0,0,0 }, consvotes[3] = { 0,0,0 }; // liberal & conservative parties' candidates votes received
															// run primaries for 100 voters
	 for (int i = 0; i < 100; i++)
	 {
		 int voters[2] = { getsimplevoter(1),getsimplevoter(1) }; // liberal & conservative party voter both decide
		 if (presparty != STALINIST_PARTY) // Stalinist Party doesn't do primaries
		 {
			 // Incumbent can win primary automatically if their approval in their party is over 50%,
			 // so we need to know what their inter-party approval rating is.
			 // check if this voter supports the president (1/2 chance if closely aligned)
			 if (voters[presparty] == exec[EXEC_PRESIDENT] + presparty * 2 || (abs(exec[EXEC_PRESIDENT] + presparty * 2 - voters[presparty]) == 1 && !LCSrandom(2))) approvepres++;
			 // check if this voter supports the vice-president (1/3 chance if closely aligned)
			 if (voters[presparty] == exec[EXEC_VP] + presparty * 2 || (abs(exec[EXEC_VP] + presparty * 2 - voters[presparty]) == 1 && !LCSrandom(3))) approveveep++;
		 }
		 consvotes[voters[CONSERVATIVE_PARTY]]++, libvotes[voters[LIBERAL_PARTY]]++; // count ballots
	 }
	 // determine conservative winner
	 if (consvotes[0] > consvotes[1] && consvotes[0] > consvotes[2]) candidate[CONSERVATIVE_PARTY][0] = ALIGN_ARCHCONSERVATIVE;
	 else if (consvotes[1] > consvotes[2]) candidate[CONSERVATIVE_PARTY][0] = ALIGN_CONSERVATIVE;
	 else candidate[CONSERVATIVE_PARTY][0] = ALIGN_MODERATE;
	 // determine liberal winner
	 if (libvotes[0] > libvotes[1] && libvotes[0] > libvotes[2]) candidate[LIBERAL_PARTY][0] = ALIGN_MODERATE;
	 else if (libvotes[1] > libvotes[2]) candidate[LIBERAL_PARTY][0] = ALIGN_LIBERAL;
	 else candidate[LIBERAL_PARTY][0] = ALIGN_ELITELIBERAL;
	 // Stalinist winner is always Stalinist
	 candidate[STALINIST_PARTY][0] = ALIGN_STALINIST;
	 // approval within own party of Stalinist pres and VP is 100%, since all Stalinist party members have the same political views
	 if (presparty == STALINIST_PARTY) approvepres = 100, approveveep = 100;
	 // name the candidates
	 if (candidate[CONSERVATIVE_PARTY][0] == -2) generate_name(candidate[CONSERVATIVE_PARTY] + 1, GENDER_WHITEMALEPATRIARCH);
	 else if (candidate[CONSERVATIVE_PARTY][0] == -1) generate_name(candidate[CONSERVATIVE_PARTY] + 1, GENDER_MALE);
	 else generate_name(candidate[CONSERVATIVE_PARTY] + 1);
	 generate_name(candidate[LIBERAL_PARTY] + 1);
	 generate_name(candidate[STALINIST_PARTY] + 1);
	 // Special Incumbency Rules: If the incumbent president or vice president
	 // has approval of over 50% in their party, they win their primary
	 // automatically. Even if they don't have over 50%, if their alignment wins
	 // using the normal primary process, they are the chosen candidate for
	 // that alignment (this last bit only applies to President; unpopular VP
	 // candidates just don't run, and if their alignment wins it will be
	 // someone else).
	 if (execterm == 1) // President running for re-election
	 {
		 if (approvepres >= 50) candidate[presparty][0] = exec[EXEC_PRESIDENT];
		 if (candidate[presparty][0] == exec[EXEC_PRESIDENT]) strcpy(candidate[presparty] + 1, execname[EXEC_PRESIDENT]);
		 else execterm = 2; // Boom! Incumbent president was defeated in their
	 }                   // own party. New candidate works with a clean slate.
	 else if (approveveep >= 50 &&                                              // Vice-President running for President
		 (presparty != LIBERAL_PARTY || exec[EXEC_VP] != ALIGN_CONSERVATIVE) && // We don't want conservative liberals
		 (presparty != CONSERVATIVE_PARTY || exec[EXEC_VP] != ALIGN_LIBERAL))   // or liberal conservatives.
	 {
		 if (approvepres >= 50)
		 {
			 candidate[presparty][0] = exec[EXEC_VP];
			 strcpy(candidate[presparty] + 1, execname[EXEC_VP]);
		 }
	 }
	 //Print candidates
	 if (canseethings)
	 {
		 printCandiadates(candidate);
	 }
	 int winner = -1;
	 bool recount = false;
	 for (int l = 0; l < 1000; l++) // 1000 Voters!
	 {
		 votes[singleVote(l, candidate[LIBERAL_PARTY][0], candidate[CONSERVATIVE_PARTY][0])]++;
		 if (l % 5 == 4)
		 {
			 int maxvote = 0;
			 for (int c = 0; c < 2 + stalinmode; c++) if (votes[c] > maxvote) maxvote = votes[c];
			 vector<int> eligible;
			 for (int c = 0; c < 2 + stalinmode; c++) if (votes[c] == maxvote) eligible.push_back(c);
			 recount = len(eligible) > 1;
			 winner = pickrandom(eligible);
			 if (canseethings)
			 {
				 for (int c = 0; c < 2 + stalinmode; c++)
				 {
					 if (c == winner) set_color_easy(WHITE_ON_BLACK_BRIGHT);
					 else set_color_easy(BLACK_ON_BLACK_BRIGHT);
					 moveAlt(8 - ((c + 1) % 3) * 2, 45);
					 addstrAlt(votes[c] / 10);
					 addcharAlt('.');
					 addstrAlt(votes[c] % 10);
					 addcharAlt('%');
					 if (c == winner && recount&&l == 999) addstrAlt(CONST_politics062);
				 }
				 if (!disbanding) pause_ms(40);
				 else pause_ms(20);
			 }
		 }
	 }
	 if (canseethings)
	 {
		 set_color_easy(WHITE_ON_BLACK);
		 mvaddstrAlt(8 + stalinmode * 2, 0, CONST_politics063);
		 pressAnyKey();
	 }
	 //else if(disbanding) pause_ms(800);
	 //CONSTRUCT EXECUTIVE BRANCH
	 if (winner == presparty && execterm == 1) execterm = 2;
	 else
	 {
		 presparty = winner, execterm = 1, exec[EXEC_PRESIDENT] = candidate[winner][0];
		 strcpy(execname[EXEC_PRESIDENT], candidate[winner] + 1);
		 for (int e = EXEC_PRESIDENT + 1; e < EXECNUM; e++) fillCabinetPost(e);
	 }
 }
 /* politics - causes the people to vote (presidential, congressional, propositions) */
 void elections(char clearformess, char canseethings)
 {
	 extern MusicClass music;
	 extern int year;
	 extern short presparty;
	 extern bool stalinmode;
	 extern char disbanding;
	 extern short execterm;
	 extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	 extern short exec[EXECNUM];
	 extern short lawList[LAWNUM];
	 extern short public_interest[VIEWNUM];
	 if (canseethings)
	 {
		 music.play(MUSIC_ELECTIONS);
		 if (clearformess) eraseAlt();
		 else makedelimiter();
		 set_color_easy(WHITE_ON_BLACK_BRIGHT);
		 mvaddstrAlt(8, 1, CONST_politics049);
		 pressAnyKey();
	 }
	 //PRESIDENTIAL
	 if (year % 4 == 0)
	 {
		 if (canseethings)
		 {
			 eraseAlt();
			 set_color_easy(WHITE_ON_BLACK_BRIGHT);
			 mvaddstrAlt(0, 0, CONST_politics050);
			 addstrAlt(year);
			 set_color_easy(WHITE_ON_BLACK);
			 moveAlt(2, 0);
			 if (stalinmode) addstrAlt(CONST_politics051);
			 else addstrAlt(CONST_politics052);
		 }
		 presidentialElection(canseethings);
	 }
	 if (year % 2 == 0)
	 {
		 elections_senate((year % 6) / 2, canseethings); //SENATE
		 elections_house(canseethings); //HOUSE
	 }
	 //PROPOSITIONS
	 if (canseethings)
	 {
		 eraseAlt();
		 set_color_easy(WHITE_ON_BLACK_BRIGHT);
		 mvaddstrAlt(0, 0, CONST_politics064);
		 addstrAlt(year);
	 }
	 vector<int> prop, propdir, canlaw;
	 int pnum = LCSrandom(4) + 4; // this expression for pnum has a maximum value of 7, important later on
	 char lawtaken[LAWNUM];
	 memset(lawtaken, 0, LAWNUM * sizeof(char));
	 int lawpriority[LAWNUM];
	 memset(lawpriority, 0, LAWNUM * sizeof(int));
	 char lawdir[LAWNUM];
	 memset(lawdir, 0, LAWNUM * sizeof(char));
	 //DETERMINE PROPS
	 for (int l = 0; l < LAWNUM; l++)
	 {
		 int pmood = publicmood(l);
		 int pvote = -2;
		 for (int i = 0; i < 4; i++) if (LCSrandom(100) < pmood) pvote++;
		 if (lawList[l] < pvote) lawdir[l] = 1;
		 if (lawList[l] >= pvote) lawdir[l] = -1;
		 if (lawList[l] == -2) lawdir[l] = 1;
		 if (lawList[l] == 2) lawdir[l] = -1;
		 pvote = (lawList[l] + 2) * 25; //CALC PRIORITY
		 lawpriority[l] = abs(pvote - pmood) + LCSrandom(10) + public_interest[l];
	 }
	 prop.resize(pnum);
	 propdir.resize(pnum);
	 int propnums[7] = { 0,0,0,0,0,0,0 }; // 7 is maximum value for pnum
	 if (canseethings)
	 {
		 for (int p = 0; p < pnum; p++)
		 {
			 int propnum = 0;
			 do
			 {  // this loop prevents duplicate proposition numbers from occurring
				 switch (p)
				 { // 7 entries, as 7 is maximum value for pnum
				 case 0: propnum = 2 * (17 - LCSrandom(2) * 6)*(19 - LCSrandom(2) * 6); break;
				 case 1: propnum = 7 * (17 - LCSrandom(2) * 6)*(19 - LCSrandom(2) * 6); break;
				 case 2: propnum = 3 * (17 - LCSrandom(2) * 6)*(19 - LCSrandom(2) * 6); break;
				 case 3: propnum = 5 * (17 - LCSrandom(2) * 6)*(2 - LCSrandom(2) * 1); break;
				 case 4: propnum = 11 * (17 - LCSrandom(2) * 6)*(2 - LCSrandom(2) * 1); break;
				 case 5: propnum = 13 * (17 - LCSrandom(2) * 6)*(2 - LCSrandom(2) * 1); break;
				 case 6: propnum = 17 * (17 - LCSrandom(2) * 6)*(2 - LCSrandom(2) * 1); break;
				 }
			 } while (find(propnums, propnums + p, propnum) != propnums + p); // redo loop if we already used this proposition number, end loop if it's unused
			 propnums[p] = propnum; // put the proposition number we chose into the array, so we don't choose it again for a later proposition
		 }
		 sort(propnums, propnums + pnum);
	 }
	 for (int p = 0; p < pnum; p++)
	 {
		 int maxprior = 0;
		 for (int l = 0; l < LAWNUM; l++) if (lawpriority[l] > maxprior && !lawtaken[l]) maxprior = lawpriority[l];
		 canlaw.clear();
		 for (int l = 0; l < LAWNUM; l++) if (lawpriority[l] == maxprior && !lawtaken[l]) canlaw.push_back(l);
		 prop[p] = pickrandom(canlaw);
		 lawtaken[prop[p]] = 1;
		 propdir[p] = lawdir[prop[p]];
		 if (canseethings)
		 {
			 set_color_easy(WHITE_ON_BLACK_BRIGHT);
			 mvaddstrAlt(p * 3 + 2, 0, CONST_politics065 + tostring(propnums[p]) + ':');
			 mvaddstrAlt(p * 3 + 2, 18, CONST_politics095);
			 set_alignment_color(propdir[p]);
			 if (propdir[p] == 1) {
				 if (prop[p] == LAW_PRISONS) {
					 if (lawList[LAW_PRISONS] == 1) addstrAlt(establishPrisonReform);
					 else addstrAlt(improvePrisonConditions);
				 }
				 else {
					 addstrAlt(liberalizeLaw[prop[p]]);
				 }
			 }
			 else {
				 addstrAlt(conservatiseLaw[prop[p]]);
			 }
			 set_color_easy(WHITE_ON_BLACK);
		 }
	 }
	 if (canseethings)
	 {
		 set_color_easy(WHITE_ON_BLACK);
		 mvaddstrAlt(23, 0, CONST_politics069);
		 pressAnyKey();
	 }
	 for (int p = 0; p < pnum; p++)
	 {
		 bool yeswin = voteOnBill(canseethings, publicmood(prop[p]), propdir[p], p);
		 if (yeswin) lawList[prop[p]] += propdir[p];
	 }
	 if (canseethings)
	 {
		 set_color_easy(WHITE_ON_BLACK);
		 mvaddstrAlt(23, 0, pressKeyToReflect);
		 pressAnyKey();
	 }
 }
 /* politics - causes the supreme court to hand down decisions */
 void supremecourt(char clearformess, char canseethings)
 {
	 extern MusicClass music;
	 extern int year;
	 extern short exec[EXECNUM];
	 extern short lawList[LAWNUM];
	 extern short senate[SENATENUM];
	 extern short court[COURTNUM];
	 extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
	 if (canseethings)
	 {
		 music.play(MUSIC_ELECTIONS);
		 if (clearformess) eraseAlt();
		 else makedelimiter();
		 set_color_easy(WHITE_ON_BLACK_BRIGHT);
		 mvaddstrAlt(8, 1, CONST_politics073);
		 pressAnyKey();
	 }
	 //CHANGE THINGS AND REPORT
	 if (canseethings)
	 {
		 eraseAlt();
		 set_color_easy(WHITE_ON_BLACK_BRIGHT);
		 mvaddstrAlt(0, 0, CONST_politics074);
		 addstrAlt(year);
		 set_color_easy(WHITE_ON_BLACK);
	 }
	 vector<int> scase, scasedir;
	 int cnum = LCSrandom(5) + 2, bias = 0;
	 char lawtaken[LAWNUM];
	 memset(lawtaken, 0, LAWNUM * sizeof(char));
	 scase.resize(cnum);
	 scasedir.resize(cnum);
	 for (int c = 0; c < cnum; c++)
	 {
		 do
		 {
			 scase[c] = LCSrandom(LAWNUM);
		 } while (lawtaken[scase[c]]);
		 lawtaken[scase[c]] = 1;
		 //Constitutional bias -- free speech, flag burning issues, supreme court
		 //is extra liberal, gun control, supreme court is extra conservative
		 if (scase[c] == LAW_FREESPEECH || scase[c] == LAW_FLAGBURNING)bias = 1;
		 else if (scase[c] == LAW_GUNCONTROL)bias = -1;
		 else bias = 0;
		 if (lawList[scase[c]] == 2)scasedir[c] = -1;
		 else if (lawList[scase[c]] == -2)scasedir[c] = 1;
		 else
		 {
			 if (bias)scasedir[c] = bias;
			 else if (!LCSrandom(2))scasedir[c] = 1;
			 else scasedir[c] = -1;
		 }
		 if (canseethings)
		 {

			 string name1, name2;
			 if (!LCSrandom(5)) (name1 = CONST_politics075);
			 else name1 = lastname();
			 if ((scase[c] == LAW_LABOR || scase[c] == LAW_CORPORATE ||
				 scase[c] == LAW_ANIMALRESEARCH || scase[c] == LAW_POLLUTION) &&
				 !LCSrandom(5))
			 {
				 name2 = lastname(true) + pickrandom(corporateSuffix);
			 }
			 else {
				 name2 = lastname();
			 }
			 mvaddstrAlt(c * 3 + 2, 0, name1 + CONST_politics076 + name2);
			 mvaddstrAlt(c * 3 + 3, 0, CONST_politics077);
			 set_alignment_color(scasedir[c]);
			 if (scasedir[c] == 1) {
				 if (scase[c] == LAW_PRISONS) {
					 if (lawList[LAW_PRISONS] == 1) addstrAlt(establishPrisonReform);
					 else addstrAlt(improvePrisonConditions);
				 }
				 else {
					 addstrAlt(liberalizeLaw[scase[c]]);
				 }
			 }
			 else {
				 addstrAlt(conservatiseLaw[scase[c]]);
			 }
			 set_color_easy(WHITE_ON_BLACK);
			 refreshAlt();
		 }
	 }
	 if (canseethings)
	 {
		 set_color_easy(WHITE_ON_BLACK);
		 mvaddstrAlt(23, 0, CONST_politics080);
		 pressAnyKey();
	 }
	 for (int c = 0; c < cnum; c++)
	 {
		 char yeswin = 0;
		 int yesvotes = 0;
		 //Constitutional bias -- free speech, flag burning issues, supreme court
		 //is extra liberal, gun control, supreme court is extra conservative
		 //"All court justices will vote according to alignment and bias and do not consult
		 //popular opinion...---Servant Corps"
		 if (scase[c] == LAW_FREESPEECH || scase[c] == LAW_FLAGBURNING) bias = 1;
		 else if (scase[c] == LAW_GUNCONTROL) bias = -1;
		 else bias = 0;
		 for (int l = 0; l < COURTNUM; l++)
		 {
			 int vote = court[l];
			 if (vote == ALIGN_STALINIST)
			 {
				 if (stalinview(scase[c], true)) vote = ALIGN_ELITELIBERAL;
				 else vote = ALIGN_ARCHCONSERVATIVE;
			 }
			 if (vote >= -1 && vote <= 1) vote += bias;
			 if (lawList[scase[c]] > vote && scasedir[c] == -1) yesvotes++;
			 if (lawList[scase[c]] < vote && scasedir[c] == 1) yesvotes++;
			 if (l == COURTNUM - 1 && yesvotes >= COURTMAJORITY) yeswin = 1;
			 if (canseethings)
			 {
				 if (l == COURTNUM - 1 && yeswin)set_color_easy(WHITE_ON_BLACK_BRIGHT);
				 else if (l == COURTNUM - 1)set_color_easy(BLACK_ON_BLACK_BRIGHT);
				 else set_color_easy(WHITE_ON_BLACK);
				 mvaddstrAlt(c * 3 + 2, 63, yesvotes);
				 addstrAlt(CONST_politics082);
				 if (l == COURTNUM - 1 && !yeswin)set_color_easy(WHITE_ON_BLACK_BRIGHT);
				 else if (l == COURTNUM - 1)set_color_easy(BLACK_ON_BLACK_BRIGHT);
				 else set_color_easy(WHITE_ON_BLACK);
				 mvaddstrAlt(c * 3 + 3, 63, l + 1 - yesvotes);
				 addstrAlt(CONST_politics083);
				 pause_ms(60);
			 }
		 }
		 if (yeswin) lawList[scase[c]] += scasedir[c];
	 }
	 if (canseethings)
	 {
		 set_color_easy(WHITE_ON_BLACK);
		 mvaddstrAlt(23, 0, pressKeyToReflect);
		 pressAnyKey();
	 }
	 //CHANGE A JUSTICE 40% OF THE TIME
	 if (LCSrandom(10) >= 6)
	 {
		 if (canseethings)
		 {
			 eraseAlt();
			 set_color_easy(WHITE_ON_BLACK_BRIGHT);
			 mvaddstrAlt(0, 0, CONST_politics084);
		 }
		 int j = LCSrandom(COURTNUM);
		 if (canseethings)
		 {
			 set_color_easy(WHITE_ON_BLACK_BRIGHT);
			 mvaddstrAlt(2, 0, CONST_politics085);
			 addstrAlt(courtname[j]);
			 addstrAlt(commaSpace);
			 addstrAlt(getalign(court[j], false));
			 addstrAlt(CONST_politics086);
			 set_color_easy(WHITE_ON_BLACK);
			 mvaddstrAlt(7, 0, CONST_politics087);
			 pressAnyKey();
		 }
		 float president = (exec[EXEC_PRESIDENT] == ALIGN_STALINIST ? (float)-3 : (float)exec[EXEC_PRESIDENT]);
		 float sen = 0;
		 for (int s = 0; s < 100; s++) sen += (senate[s] == ALIGN_STALINIST ? (float)-3 : (float)senate[s]);
		 sen /= 100.0f;
		 float consensus = (president + sen)*.5f;
		 if (consensus < -2.1f) court[j] = ALIGN_STALINIST;
		 else if (consensus < -1.5f) court[j] = ALIGN_ARCHCONSERVATIVE;
		 else if (consensus < -.5f) court[j] = ALIGN_CONSERVATIVE;
		 else if (consensus < .5f) court[j] = ALIGN_MODERATE;
		 else if (consensus < 1.5f) court[j] = ALIGN_LIBERAL;
		 else court[j] = ALIGN_ELITELIBERAL;
		 do
		 {
			 if (court[j] == ALIGN_ARCHCONSERVATIVE)
				 generate_name(courtname[j], GENDER_WHITEMALEPATRIARCH);
			 else generate_name(courtname[j]);
		 } while (len(courtname[j]) > 20);
		 if (canseethings)
		 {
			 mvaddstrAlt(4, 0, CONST_politics088);
			 moveAlt(5, 0);
			 if (court[j] == ALIGN_STALINIST) addstrAlt(CONST_politics089);
			 else addstrAlt(CONST_politics090);
			 addstrAlt(courtname[j]);
			 addstrAlt(commaSpace);
			 addstrAlt(getalign(court[j], false));
			 addstrAlt(CONST_politics091);
			 set_color_easy(WHITE_ON_BLACK);
			 mvaddstrAlt(7, 0, pressKeyToReflect);
			 pressAnyKey();
		 }
	 }
 }
 enum BillStatus
 {
	 BILL_SIGNED = -2,
	 BILL_OVERRIDE_VETO = -1,
	 BILL_PASSED_CONGRESS = 0,
	 BILL_FAILED = 1
 };
 //Some politicians listen to public opinion, but no politician will radically deviate from their alignment.
 //More extreme politicians are less likely to deviate from their views. Moderates always consult public opinion.
 char determine_politician_vote(char alignment, int law)
 {
	 char vote = alignment;
	 int mood = publicmood(law);
	 if (vote == ALIGN_STALINIST)
	 {
		 // Stalinist -- Will not accept public opinion
		 if (stalinview(law, true)) vote = ALIGN_ELITELIBERAL;
		 else vote = ALIGN_ARCHCONSERVATIVE;
	 }
	 else if (vote == -2 || vote == 2)
	 {
		 // Extremist -- Damn public opinion, I'm doing what I think is right
	 }
	 else if (vote == -1 || vote == 1)
	 {
		 // Partisan -- Listens to public opinion, but won't accept opposing views
		 vote = -2;
		 for (int i = 0; i < 4; i++)if (LCSrandom(100) < mood)vote++;
		 if (abs(vote - alignment) > 1)vote = 0;
	 }
	 else if (vote == 0)
	 {
		 // Moderate -- Listens to public opinion, but won't accept either extreme
		 vote = -2;
		 for (int i = 0; i < 4; i++)if (LCSrandom(100) < mood)vote++;
		 if (abs(vote) > 1)vote = vote / 2;
	 }
	 return vote;
 }
 void determineBills(const char canseethings, vector<int> &bill, vector<int> &billdir) {
	 extern int year;
	 extern short lawList[LAWNUM];
	 extern short house[HOUSENUM];
	 extern short senate[SENATENUM];

	 char lawtaken[LAWNUM];
	 memset(lawtaken, 0, LAWNUM * sizeof(char));
	 int lawpriority[LAWNUM];
	 memset(lawpriority, 0, LAWNUM * sizeof(int));
	 char lawdir[LAWNUM];
	 memset(lawdir, 0, LAWNUM * sizeof(char));

	 for (int l = 0; l < LAWNUM; l++)
	 {
		 int pup = 0;
		 int pdown = 0;
		 int pprior = 0;
		 // Consult House
		 for (int cl = 0; cl < HOUSENUM; cl++)
		 {
			 short housealign = house[cl];
			 if (housealign == ALIGN_STALINIST)
			 {
				 if (stalinview(l, true)) housealign = ALIGN_ELITELIBERAL;
				 else housealign = ALIGN_ARCHCONSERVATIVE;
			 }
			 if (lawList[l] < housealign)pup++;
			 else if (lawList[l] > housealign)pdown++;
			 pprior += abs(housealign - lawList[l]);
		 }
		 // Consult Senate
		 for (int sl = 0; sl < SENATENUM; sl++)
		 {
			 short senatealign = senate[sl];
			 if (senatealign == ALIGN_STALINIST)
			 {
				 if (stalinview(l, true)) senatealign = ALIGN_ELITELIBERAL;
				 else senatealign = ALIGN_ARCHCONSERVATIVE;
			 }
			 if (lawList[l] < senatealign)pup += 4;
			 else if (lawList[l] > senatealign)pdown += 4;
			 pprior += abs(senatealign - lawList[l]) * 4;
		 }
		 // Consult Public Opinion
		 int mood = publicmood(l);
		 int public_position = -2;
		 for (int i = 0; i < 4; i++)if (10 + 20 * i < mood)public_position++;
		 if (lawList[l] < public_position)pup += 600;
		 if (lawList[l] > public_position)pdown += 600;
		 pprior += abs(public_position - lawList[l]) * 600;
		 if (pup > pdown) lawdir[l] = 1;
		 else if (pup == pdown) lawdir[l] = LCSrandom(2) * 2 - 1;
		 else lawdir[l] = -1;
		 if (lawList[l] == -2) lawdir[l] = 1;
		 if (lawList[l] == 2) lawdir[l] = -1;
		 //CALC PRIORITY
		 lawpriority[l] = pprior;
	 }
	 vector<int> canlaw;
	 for (int c = 0; c < bill.size(); c++)
	 {
		 int maxprior = 0;
		 for (int l = 0; l < LAWNUM; l++)
			 if (lawpriority[l] > maxprior && !lawtaken[l])maxprior = lawpriority[l];
		 canlaw.clear();
		 for (int l = 0; l < LAWNUM; l++)
			 if (lawpriority[l] == maxprior && !lawtaken[l])
				 canlaw.push_back(l);
		 bill[c] = pickrandom(canlaw);
		 lawtaken[bill[c]] = 1;
		 billdir[c] = lawdir[bill[c]];
		 if (canseethings)
		 {
			 set_color_easy(WHITE_ON_BLACK_BRIGHT);
			 mvaddstrAlt(c * 3 + 2, 0, CONST_politics094);
			 addstrAlt(year);
			 addcharAlt('-');
			 addstrAlt(c + 1);
			 mvaddstrAlt(c * 3 + 3, 0, CONST_politics095);
			 if (billdir[c] == 1)set_color_easy(GREEN_ON_BLACK_BRIGHT);
			 else set_color_easy(RED_ON_BLACK_BRIGHT);
			 set_alignment_color(billdir[c]);
			 if (billdir[c] == 1) {
				 if (bill[c] == LAW_PRISONS) {
					 if (lawList[LAW_PRISONS] == 1) addstrAlt(establishPrisonReform);
					 else addstrAlt(improvePrisonConditions);
				 }
				 else {
					 addstrAlt(liberalizeLaw[bill[c]]);
				 }
			 }
			 else {
				 addstrAlt(conservatiseLaw[bill[c]]);
			 }
			 set_color_easy(WHITE_ON_BLACK);
			 refreshAlt();
		 }
	 }
 }
 void displayCongressHeader(const char clearformess) {
	 extern MusicClass music;
	 extern int year;
	 music.play(MUSIC_ELECTIONS);
	 if (clearformess) eraseAlt();
	 else makedelimiter();
	 set_color_easy(WHITE_ON_BLACK_BRIGHT);
	 mvaddstrAlt(8, 1, CONST_politics092);
	 pressAnyKey();
	 //CHANGE THINGS AND REPORT
	 eraseAlt();
	 set_color_easy(WHITE_ON_BLACK_BRIGHT);
	 mvaddstrAlt(0, 0, CONST_politics093);
	 addstrAlt(year);
 }
 void displayCongressHeaderPartTwo() {
	 set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(23, 0, CONST_politics098);
	 pressAnyKey();
	 mvaddstrAlt(0, 62, CONST_politics099);
	 mvaddstrAlt(0, 70, CONST_politics100);
 }
 void displayHouseVotes(const int l, const int yesvotes_h, const char yeswin_h, const int c) {
	 if (l == HOUSENUM - 1 && yeswin_h) set_color_easy(WHITE_ON_BLACK_BRIGHT);
	 else if (l == HOUSENUM - 1) set_color_easy(BLACK_ON_BLACK_BRIGHT);
	 else set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(c * 3 + 2, 62, yesvotes_h);
	 addstrAlt(YEA);
	 if (l == HOUSENUM - 1 && !yeswin_h) set_color_easy(WHITE_ON_BLACK_BRIGHT);
	 else if (l == HOUSENUM - 1) set_color_easy(BLACK_ON_BLACK_BRIGHT);
	 else set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(c * 3 + 3, 62, l + 1 - yesvotes_h);
	 addstrAlt(NAY);
 }
 void displaySenateVotes(const int l, const int yesvotes_s, const char yeswin_s, const int c, const int s) {

	 if (l == HOUSENUM - 1 && yeswin_s) set_color_easy(WHITE_ON_BLACK_BRIGHT);
	 else if (l == HOUSENUM - 1) set_color_easy(BLACK_ON_BLACK_BRIGHT);
	 else set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(c * 3 + 2, 70, yesvotes_s);
	 addstrAlt(YEA);
	 if (l == HOUSENUM - 1 && yesvotes_s == SENATEMAJORITY - 1 && yeswin_s)
	 {
		 set_color_easy(WHITE_ON_BLACK_BRIGHT);
		 mvaddstrAlt(c * 3 + 2, 78, CONST_politics102);
	 }
	 if (l == HOUSENUM - 1 && !yeswin_s) set_color_easy(WHITE_ON_BLACK_BRIGHT);
	 else if (l == HOUSENUM - 1) set_color_easy(BLACK_ON_BLACK_BRIGHT);
	 else set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(c * 3 + 3, 70, (s - yesvotes_s));
	 addstrAlt(NAY);
	 if (l == HOUSENUM - 1 && yesvotes_s == SENATEMAJORITY - 1 && !yeswin_s)
	 {
		 set_color_easy(WHITE_ON_BLACK_BRIGHT);
		 mvaddstrAlt(c * 3 + 3, 78, CONST_politics102);
	 }
	 if (l % 5 == 0) pause_ms(5);
 }
 void printWatchPresident() {
	 set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(23, 0, CONST_politics103);
	 pressAnyKey();
	 mvaddstrAlt(0, 35, CONST_politics104);
	 pause_ms(500);
 }
 void printBillResults(const BillStatus bill, const int c) {
	 extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	 moveAlt(c * 3 + 2, 35);
	 if (bill == BILL_SIGNED)
	 {
		 set_color_easy(WHITE_ON_BLACK_BRIGHT);
		 addstrAlt(execname[EXEC_PRESIDENT]);
	 }
	 else if (bill == BILL_FAILED)
	 {
		 set_color_easy(BLACK_ON_BLACK_BRIGHT);
		 addstrAlt(CONST_politics105);
	 }
	 else if (bill == BILL_OVERRIDE_VETO)
	 {
		 set_color_easy(WHITE_ON_BLACK_BRIGHT);
		 addstrAlt(CONST_politics106);
	 }
	 else
	 {
		 set_color_easy(RED_ON_BLACK_BRIGHT);
		 addstrAlt(CONST_politics107);
	 }
	 pause_ms(500);
 }
 void printReflectOnBill() {
	 set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(23, 0, pressKeyToReflect + CONST_politics110);
	 pressAnyKey();
 }
 void printDeadInCongress() {
	 set_color_easy(WHITE_ON_BLACK);
	 mvaddstrAlt(23, 0, CONST_politics109);
	 mvaddstrAlt(24, 0, pressKeyToReflect + CONST_politics110);
	 pressAnyKey();
 }
 void attemptAmendmentEnding(char canseethings, Alignment enforcedAlignment);
 /* politics - causes congress to act on legislation */
 void congress(char clearformess, char canseethings)
 {
	 extern MusicClass music;
	 extern int year;
	 extern bool notermlimit;           //These determine if ELAs can take place --kviiri
	 extern bool nocourtpurge;
	 extern char execname[EXECNUM][POLITICIAN_NAMELEN];
	 extern short exec[EXECNUM];
	 extern short lawList[LAWNUM];
	 extern short house[HOUSENUM];
	 extern short senate[SENATENUM];
	 extern short court[COURTNUM];
	 if (canseethings)
	 {
		 displayCongressHeader(clearformess);
	 }
	 vector<int> bill, billdir, killbill;
	 int cnum = LCSrandom(3) + 1;
	 bill.resize(cnum);
	 billdir.resize(cnum);
	 killbill.resize(cnum);
	 for (int c = 0; c < killbill.size(); c++)
	 {
		 killbill[c] = BILL_PASSED_CONGRESS;
	 }
	 //DETERMINE BILLS
	 determineBills(canseethings, bill, billdir);

	 if (canseethings)
	 {
		 displayCongressHeaderPartTwo();
	 }
	 for (int c = 0; c < cnum; c++)
	 {
		 char yeswin_h = 0, yeswin_s = 0;
		 int yesvotes_h = 0, yesvotes_s = 0;
		 int s = 0;
		 for (int l = 0; l < HOUSENUM; l++)
		 {
			 int vote = determine_politician_vote(house[l], bill[c]);
			 if (lawList[bill[c]] > vote&&billdir[c] == -1) yesvotes_h++;
			 if (lawList[bill[c]] < vote&&billdir[c] == 1) yesvotes_h++;
			 if (l == HOUSENUM - 1)
			 {
				 if (yesvotes_h >= HOUSEMAJORITY) yeswin_h = 1;
				 if (yesvotes_h >= HOUSESUPERMAJORITY) killbill[c] = BILL_OVERRIDE_VETO;
			 }
			 if (canseethings)
			 {
				 displayHouseVotes(l, yesvotes_h, yeswin_h, c);
			 }
			 if (l % 4 == 0 && s < SENATENUM)
			 {
				 vote = determine_politician_vote(senate[s++], bill[c]);
				 if (lawList[bill[c]] > vote&&billdir[c] == -1) yesvotes_s++;
				 if (lawList[bill[c]] < vote&&billdir[c] == 1) yesvotes_s++;
			 }
			 if (l == HOUSENUM - 1)
			 {
				 if (yesvotes_s >= SENATEMAJORITY) yeswin_s = 1;
				 if (yesvotes_s < SENATESUPERMAJORITY&&killbill[c] == BILL_OVERRIDE_VETO) killbill[c] = BILL_PASSED_CONGRESS;
				 if (yesvotes_s == SENATEMAJORITY - 1)
				 {  //TIE BREAKER
					 int vote;
					 if ((exec[EXEC_VP] >= -1 && exec[EXEC_VP] <= 1) ||
						 (exec[EXEC_PRESIDENT] >= -1 && exec[EXEC_PRESIDENT] <= 1))
						 vote = (exec[EXEC_PRESIDENT] + // only consult Cabinet and random number generator if alignment between -1 and 1
							 exec[EXEC_VP] +        // for President and/or Vice President
							 exec[EXEC_STATE] +
							 exec[EXEC_ATTORNEY] + LCSrandom(9) - 4) / 4;
					 else
					 {
						 vote = exec[EXEC_VP];
						 if (vote == ALIGN_STALINIST)
						 {
							 if (stalinview(bill[c], true)) vote = ALIGN_ELITELIBERAL;
							 else vote = ALIGN_ARCHCONSERVATIVE;
						 }
					 }
					 if (lawList[bill[c]] > vote&&billdir[c] == -1) yeswin_s = 1;
					 if (lawList[bill[c]] < vote&&billdir[c] == 1) yeswin_s = 1;
					 //ASSURED SIGNING BY PRESIDENT IF VP VOTED YES
					 if (yeswin_s) killbill[c] = BILL_SIGNED;
				 }
			 }
			 if (canseethings)
			 {
				 displaySenateVotes(l, yesvotes_s, yeswin_s, c, s);
			 }
		 }
		 if (!yeswin_h || !yeswin_s) killbill[c] = BILL_FAILED;
	 }
	 int havebill = 0;
	 for (int c = 0; c < cnum; c++) if (killbill[c] != BILL_FAILED) havebill++;
	 if (havebill)
	 {
		 if (canseethings)
		 {
			 printWatchPresident();
		 }
		 for (int c = 0; c < len(bill); c++)
		 {
			 if (killbill[c] != BILL_FAILED)
			 {
				 int vote;
				 if (exec[EXEC_PRESIDENT] >= -1 && exec[EXEC_PRESIDENT] <= 1)
					 vote = (exec[EXEC_PRESIDENT] + // only consult Cabinet and random number generator if alignment between -1 and 1
						 exec[EXEC_VP] +        // for President
						 exec[EXEC_STATE] +
						 exec[EXEC_ATTORNEY] + LCSrandom(9) - 4) / 4;
				 else
				 {
					 vote = exec[EXEC_PRESIDENT];
					 if (vote == ALIGN_STALINIST)
					 {
						 if (stalinview(bill[c], true)) vote = ALIGN_ELITELIBERAL;
						 else vote = ALIGN_ARCHCONSERVATIVE;
					 }
				 }
				 if ((lawList[bill[c]] > vote&&billdir[c] == -1) || (lawList[bill[c]] < vote&&billdir[c] == 1)) killbill[c] = BILL_SIGNED;
			 }
			 if (canseethings)
			 {
				 printBillResults(static_cast<BillStatus> (killbill[c]), c);
			 }
			 if (killbill[c] == BILL_SIGNED || killbill[c] == BILL_OVERRIDE_VETO) lawList[bill[c]] += billdir[c];
		 }
		 if (canseethings)
		 {
			 printReflectOnBill();
		 }
	 }
	 else if (canseethings)
	 {
		 printDeadInCongress();
	 }
	 //CONGRESS CONSTITUTION CHANGES
	 int housemake[6] = { 0,0,0,0,0,0 };
	 for (int h = 0; h < HOUSENUM; h++) housemake[house[h] + 2]++;
	 int senatemake[6] = { 0,0,0,0,0,0 };
	 for (int s = 0; s < SENATENUM; s++) senatemake[senate[s] + 2]++;
	 // Throw out non-L+ Justices?
	 bool tossj = false;
	 for (int j = 0; j < COURTNUM; j++) if (court[j] != ALIGN_ELITELIBERAL) tossj = true;
	 if (housemake[4] + housemake[3] / 2 >= HOUSESUPERMAJORITY && senatemake[4] + senatemake[3] / 2 >= SENATESUPERMAJORITY && tossj && !nocourtpurge)
		 tossjustices(canseethings);
	 // Purge Congress, implement term limits, and hold new elections?
	 if ((housemake[4] + housemake[3] / 2 < HOUSESUPERMAJORITY || senatemake[4] + senatemake[3] / 2 < SENATESUPERMAJORITY) && publicmood(-1) > 80 && !notermlimit)
		 amendment_termlimits(canseethings);
	 // LET ARCH-CONSERVATIVES REPEAL THE CONSTITUTION AND LOSE THE GAME?
	 if (housemake[0] >= HOUSESUPERMAJORITY && senatemake[0] >= SENATESUPERMAJORITY)
		 attemptAmendmentEnding(canseethings, ALIGN_ARCHCONSERVATIVE);
	 // LET STALINISTS REPEAL THE CONSTITUTION AND LOSE THE GAME?
	 if (housemake[5] >= HOUSESUPERMAJORITY && senatemake[5] >= SENATESUPERMAJORITY)
		 attemptAmendmentEnding(canseethings, ALIGN_STALINIST);
 }
 /* politics - checks if the game is won */
 char wincheck()
 {
	 extern short wincondition;
	 extern short exec[EXECNUM];
	 extern short lawList[LAWNUM];
	 extern short house[HOUSENUM];
	 extern short senate[SENATENUM];
	 extern short court[COURTNUM];
	 for (int e = 0; e < EXECNUM; e++) if (exec[e] < ALIGN_ELITELIBERAL) return 0;
	 if (wincondition == WINCONDITION_ELITE) for (int l = 0; l < LAWNUM; l++) if (lawList[l] < ALIGN_ELITELIBERAL) return 0;
	 else
	 {
		 int liberalLaws = 0, eliteLaws = 0;
		 for (int l = 0; l < LAWNUM; l++)
		 {
			 if (lawList[l] < ALIGN_LIBERAL) return 0;
			 if (lawList[l] == ALIGN_LIBERAL) liberalLaws++;
			 else eliteLaws++;
		 }
		 if (eliteLaws < liberalLaws) return 0;
	 }
	 int housemake[6] = { 0,0,0,0,0,0 };
	 for (int h = 0; h < HOUSENUM; h++) housemake[house[h] + 2]++;
	 if (housemake[4] + housemake[3] / 2 < ((wincondition == WINCONDITION_ELITE) ? HOUSESUPERMAJORITY : HOUSECOMFYMAJORITY)) return 0; // Elite Libs plus half of Libs >= 3/5 for easy, 2/3 for elite
	 if (housemake[4] < ((wincondition == WINCONDITION_ELITE) ? HOUSECOMFYMAJORITY : HOUSEMAJORITY)) return 0; // Elite Libs themselves >= 1/2 for easy, 3/5 for elite
	 int senatemake[6] = { 0,0,0,0,0,0 };
	 for (int s = 0; s < SENATENUM; s++) senatemake[senate[s] + 2]++;
	 if (senatemake[4] + senatemake[3] / 2 < ((wincondition == WINCONDITION_ELITE) ? SENATESUPERMAJORITY : SENATECOMFYMAJORITY)) return 0; // Elite Libs plus half of Libs >= 3/5 for easy, 2/3 for elite
	 if (wincondition != WINCONDITION_ELITE) senatemake[exec[EXEC_VP] + 2]++; // VP counts as Senator only for breaking ties (so counts for 1/2 fraction but not higher fractions)
	 if (senatemake[4] < ((wincondition == WINCONDITION_ELITE) ? SENATECOMFYMAJORITY : SENATEMAJORITY)) return 0; // Elite Libs themselves >= 1/2 for easy, 3/5 for elite
	 int elibjudge = 0, libjudge = 0;
	 for (int c = 0; c < COURTNUM; c++)
	 {
		 if (court[c] == ALIGN_ELITELIBERAL) elibjudge++;
		 if (court[c] == ALIGN_LIBERAL) libjudge++;
	 }
	 if (elibjudge < COURTMAJORITY && (wincondition == WINCONDITION_ELITE || elibjudge + libjudge / 2 < COURTSUPERMAJORITY)) return 0;
	 return 1;
 }

