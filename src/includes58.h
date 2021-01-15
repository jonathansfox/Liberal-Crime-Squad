




/*
	File created by Chris Johnson.
	These were previously all in game.cpp.

	This file includes all the the enums, defines, and included headers required globally by all components.

	All code released under GNU GPL.
*/
#pragma once

#include "includes.h"
using namespace std;

#include "includesDeprecated.h"
#include "includesRandom.h"
//#include "vehicle/vehicletype.h"
//#include "vehicle/vehicle.h"


//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

//int get_associated_attribute(int skill_type);

#include "includesSDS.h"
#include "includesSDS2.h"
// creaturePool.cpp


#include "../creature/creature.h"

#include "../creature/deprecatedCreatureB.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../common/creaturePool.h"
#include "../common/creaturePoolCreature.h"
#include "../cursesAlternative.h"
#include "../log/log.h"
#include "../sitemode/advance.h"
/* handles end of round stuff for one creature */
void advancecreature(DeprecatedCreature &cr);
#include "../common/commonactionsCreature.h"
#include "../combat/fightCreature.h"
#include "../locations/locationsPool.h"
#include "../common/musicClass.h"
#include "../set_color_support.h"
#include "../common/commondisplay.h"
#include "../common/commondisplayCreature.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../common/getnames.h"
#include "../common/translateid.h"
// for  int getpoolcreature(int)
#include "../daily/siege.h"
#include "../common/commonactions.h"

const string tag_ARMOR = "ARMOR";
const string tag_ARMOR_PRISONER = "ARMOR_PRISONER";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";

const string THE_LIBERAL_IS_NOW_A_NORMAL_SQUAD_MEMBER = "The Liberal is now at your command as a normal squad member.";
const string HAS_BEEN_OUTED_BY_YOUR_ATTACK = " has been outed by your bold attack!";
const string THIS_WHOLE_THING_WAS_A_MISTAKE = "This whole thing was a mistake. There won't be another meeting.";
const string COMESOFF_AS_INSANE = " comes off as slightly insane.";
const string NEEDS_MORE_EXPERIENCE = " needs more experience.";
const string CONST_X_MAYBE_ = "Maybe ";
const string REALLY_UNDERSTANDS_PROBLEM = " really understands the problem.";
const string ISNT_CONVINCED = " isn't convinced ";
const string THEYLL_MEET_AGAIN_TOMORROW = "They'll meet again tomorrow.";
const string S_ARGUMENTS = "'s arguments.";
const string IS_SKEPTICAL_ABOUT = " is skeptical about some of ";
const string THEYLL_MEET_AGAIN = "They'll definitely meet again tomorrow.";
const string S_VIEWS_INSIGHTFUL = "'s views to be insightful.";
const string FOUND_SPACE = " found ";
const string VIEWS_ON = " views on ";
const string EXPLAINS_SPACE = " explains ";
const string SHARES_SPACE = " shares ";
const string ACCEPTS_AND_IS_EAGER = " accepts, and is eager to get started.";
const string JOIN_THE_LIBERAL_CRIME_SQUAD = " join the Liberal Crime Squad.";
const string OFFERS_TO_LET = " offers to let ";
const string D_BREAK_OFF_MEETINGS = "D - Break off the meetings.";
const string ISNT_READY_TO_JOIN = " isn't ready to join the LCS.";
const string CONST_X_C_DASH = "C - ";
const string NEEDS_MORE_JUICE_TO_RECRUIT = " needs more Juice to recruit.";
const string JOIN_THE_LCS = " join the LCS as a full member.";
const string C_OFFER_TO_LET = "C - Offer to let ";
const string B_CASUALLY_CHAT = "B - Just casually chat with them and discuss politics.";
const string A_SPEND_FIFTY_DOLLARS = "A - Spend $50 on props and a book for them to keep afterward.";
const string APPROACH_THE_SITUATION = " approach the situation?";
const string HOW_SHOULD_SPACE = "How should ";
const string KIND_OF_REGRETS_AGREEING = " kind of regrets agreeing to this.";
const string IS_READY_TO_FIGHT = " is ready to fight for the Liberal Cause.";
const string FEELS_SOMETHING_MUST_BE_DONE = " feels something needs to be done.";
const string IS_INTERESTED_IN_LEARNING_MORE = " is interested in learning more.";
const string WILL_TAKE_A_LOT_OF_PERSUADING = " will take a lot of persuading.";
const string MEETING_WITH_SPACE = "Meeting with ";
const string EXCLAMATION_POINT = "!";
const string GET_IT_TOGETHER_COMMA = "Get it together, ";
const string DUE_TO_MULTIPLE_BOOKING_OR_RECRUITMENT = "due to multiple booking of recruitment sessions.";
const string ACCIDENTALLY_MISSED_THE_MEETING_WITH = " accidentally missed the meeting with ";
const string HAS_ESCAPED = " has escaped!";
const string S_INJURIES_REQUIRE_PROFESSIONAL = "'s injuries require professional treatment.";
const string HAS_DIED_OF_INJURIES = " has died of injuries.";
const string HAS_LOST_TOUCH_WITH_LCS = " has lost touch with the Liberal Crime Squad.";
const string HAS_ABANDONED_THE_LCS = " has abandoned the LCS.";
const string THE_LIBERAL_HAS_GONE_INTO_HIDING = "The Liberal has gone into hiding...";
const string HAS_LEFT = " has left ";
const string HAS_BEEN_TRANSFERRED_TO = " has been transferred to ";

const string IS_MOVED_TO_THE_COURTHOUSE = " is moved to the courthouse for trial.";
const string THE_TRAITOR_WILL_TESTIFY = "The traitor will testify in court, and safehouses may be compromised.";
const string HAS_BROKEN_AND_RATTED_YOU_OUT = " has broken under the pressure and ratted you out!";
const string DEPORTATION = "deportation.";
const string EXECUTION = "execution.";
const string HAS_BEEN_SHIPPED_OUT_TO_THE_INS = " has been shipped out to the INS to face ";
const string S_MIND_WITH_CONSERVATISM = "'s mind with Conservatism!";
const string COPS_RE_POLLUTED = "Cops re-polluted ";
const string IS_THE_NEW_LEADER_OF_LCS = " is the new leader of the Liberal Crime Squad!";
const string HAS_DIED = " has died.";
const string IN_THE_COMMAND_CHAIN = " in the command chain.";
const string WILL_TAKE_OVER_FOR = " will take over for ";
const string DUE_TO_THE_DEATH_OF = "due to the death of ";
const string HAS_PROMOTED = " has promoted ";
const string THERE_ARE_NONE_WHO_CAN_LEAD = "There are none left with the courage and conviction to lead....";

enum LOOP_CONTINUATION {
	RETURN_ZERO,
	RETURN_ONE,
	REPEAT
};



enum DispersalTypes
{
	DISPERSAL_SAFE = -1,
	DISPERSAL_BOSSSAFE,
	DISPERSAL_NOCONTACT,
	DISPERSAL_BOSSINPRISON,
	DISPERSAL_HIDING,
	DISPERSAL_BOSSINHIDING,
	DISPERSAL_ABANDONLCS
};
extern Log gamelog;
extern char disbanding;
extern int stat_recruits;
extern class Ledger ledger;
extern vector<Deprecatedsquadst *> squad;
extern MusicClass music;
extern short lawList[LAWNUM];

//#include "../monthly/justice.h"
void trial(DeprecatedCreature &g);
char prison(DeprecatedCreature &g);
//#include "../monthly/sleeper_update.h"
void sleepereffect(DeprecatedCreature &cr, char &clearformess, char canseethings, int(&libpower)[VIEWNUM]);
void savehighscore(char endtype);
void viewhighscores(int musicoverride = MUSIC_OFF);
void end_game(int err = EXIT_SUCCESS);
short getCurrentSite();
