/*
Copyright (c) 2002,2003,2004 by Tarn Adams                                          //
                                                                                    //
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
/*
        This file was created by Chris Johnson (grundee@users.sourceforge.net)
        by copying code from game.cpp.
        To see descriptions of files and functions, see the list at
        the bottom of includes.h in the top src folder.
*/

#include <includes.h>
#include "creature/creatureEnums.h"
/* fills a string with a proper name */
void generate_name(char *str, char gender = GENDER_NEUTRAL);

#include "basemode/liberalagenda.h"
// for liberalagenda

#include "common/consolesupport.h"
// for void set_color(short,short,bool)

//#include "log/log.h"
// for commondisplay.h
#include "common/commondisplay.h"
// for void printfunds(int,int,char*)

#include "common/misc.h"
// for char* statename(int)
         //shouldn't be in getnames? --Schmel924
// for romannumeral (int)
         //only usage here --Schmel924


#include "title/titlescreen.h"
// for void reset;

#include "title/highscore.h"
// for void savehighscore(char endtype);

//#include "monthly/endgame.h"
//own header
        //does not compile without --Schmel924

#include "politics/politics.h"
//for publicmood


#include <cursesAlternative.h>
#include <gui_constants.h>
#include <set_color_support.h>
/* end the game and clean up */
void end_game(int err = EXIT_SUCCESS);

#include "common/musicClass.h"
extern MusicClass music;
 string pressKeyToReflect;
 string they_ll_round_you_up;
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern short exec[EXECNUM];
extern short court[COURTNUM];
extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
extern int amendnum;
extern bool termlimits;
extern vector<string> finalCabinet;
extern short lawList[LAWNUM];
extern char cantseereason;
extern short house[HOUSENUM];
extern short senate[SENATENUM];
extern short attitude[VIEWNUM];
vector<int> state_biases;

vector<string> reaganifiedCabinet;
vector<string> stalinizedCabinet;
string proposeConservative;
string proposeStalinist;
vector<string> archConservativeAmendment;
vector<string> stalinAmendment;
string YEA;
string NAY;
string youWentOnVacation;
string youWentIntoHiding;
string whileYouWereInPrison;
string youDisappearedSafely;
vector<string> conservativePrison;
vector<string> stalinistPrison;
/* endgame - checks if a constitutional amendment is ratified */
char ratify(int level, int lawview, int view, char congress, char canseethings)
{
	if (canseethings)
	{
		music.play(MUSIC_ELECTIONS);
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0, 0, "The Ratification Process:");
	}
	//THE STATE VOTE WILL BE BASED ON VIEW OF LAW
	int mood = publicmood(lawview);
	//OR OF A PARTICULAR ISSUE
	if (view >= 0) mood = attitude[view];
	//CONGRESS
	bool ratified = false;
	int y = 0;
	if (congress)
	{
		ratified = true;
		if (canseethings)
		{
			mvaddstrAlt(0, 62, "House");
			mvaddstrAlt(0, 70, "Senate");
			mvaddstrAlt(24, 0, "Press any key to watch the Congressional votes unfold.     ");
			getkeyAlt();
		}
		bool yeswin_h = false, yeswin_s = false;
		int yesvotes_h = 0, yesvotes_s = 0, vote, s = 0;
		for (int l = 0; l < HOUSENUM; l++)
		{
			vote = house[l];
			if (vote >= -1 && vote <= 1) vote += LCSrandom(3) - 1;
			if (level == vote) yesvotes_h++;
			if (l == HOUSENUM - 1) if (yesvotes_h >= HOUSESUPERMAJORITY) yeswin_h = true;
			if (canseethings)
			{
				if (l == HOUSENUM - 1 && yeswin_h) set_color_easy(WHITE_ON_BLACK_BRIGHT);
				else if (l == HOUSENUM - 1) set_color_easy(BLACK_ON_BLACK_BRIGHT);
				else set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(2, 62, yesvotes_h);
				addstrAlt(YEA);
				if (l == HOUSENUM - 1 && !yeswin_h) set_color_easy(WHITE_ON_BLACK_BRIGHT);
				else if (l == HOUSENUM - 1) set_color_easy(BLACK_ON_BLACK_BRIGHT);
				else set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(3, 62, l + 1 - yesvotes_h);
				addstrAlt(NAY);
			}
			if (l % 4 == 0 && s < SENATENUM)
			{
				vote = senate[s++];
				if (vote >= -1 && vote <= 1) vote += LCSrandom(3) - 1;
				if (level == vote) yesvotes_s++;
			}
			if (l == HOUSENUM - 1 && yesvotes_s >= SENATESUPERMAJORITY) yeswin_s = true;
			if (canseethings)
			{
				if (l == HOUSENUM - 1 && yeswin_s) set_color_easy(WHITE_ON_BLACK_BRIGHT);
				else if (l == HOUSENUM - 1) set_color_easy(BLACK_ON_BLACK_BRIGHT);
				else set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(2, 70, yesvotes_s);
				addstrAlt(YEA);
				if (l == HOUSENUM - 1 && !yeswin_s) set_color_easy(WHITE_ON_BLACK_BRIGHT);
				else if (l == HOUSENUM - 1) set_color_easy(BLACK_ON_BLACK_BRIGHT);
				else set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(3, 70, s - yesvotes_s);
				addstrAlt(NAY);
				if (l % 5 == 0) pause_ms(10);
			}
		}
		if (!yeswin_h || !yeswin_s) ratified = false;
		y += 4;
	}
	else ratified = true;
	if (level == 3) level = -2; // special case for Stalinists: do this after Congress but before the states
								//STATES
	if (ratified)
	{
		ratified = false;
		int yesstate = 0;
		if (canseethings)
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			for (int s = 0; s < 50; s++)
			{
				if (s < 17) moveAlt(5 + s, 0);
				else if (s < 34) moveAlt(5 + s - 17, 27);
				else mvaddstrAlt(5 + s - 34, 54, statename(s));
			}
			mvaddstrAlt(24, 0, "Press any key to watch the State votes unfold.              ");
			getkeyAlt();
		}
		int vote, smood;
		for (int s = 0; s < STATENUM; s++)
		{
			smood = mood;
			// State biases.
			int multiplier = 5 + LCSrandom(3);
			smood += state_biases[s] * multiplier;
			vote = -2;
			if (LCSrandom(100) < smood)vote++;
			if (LCSrandom(100) < smood)vote++;
			if (LCSrandom(100) < smood)vote++;
			if (LCSrandom(100) < smood)vote++;
			if (vote == 1 && !LCSrandom(2)) vote = 2;
			if (vote == -1 && !LCSrandom(2)) vote = -2;
			if (canseethings)
			{
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				if (s < 17) moveAlt(5 + s, 22);
				else if (s < 34) moveAlt(5 + s - 17, 49);
				else moveAlt(5 + s - 34, 76);
			}
			if (vote == level)
			{
				yesstate++;
				if (canseethings) addstrAlt("Yea");
			}
			else if (canseethings) addstrAlt("Nay");
			if (canseethings)
			{
				if (s == STATENUM - 1 && yesstate >= STATESUPERMAJORITY) set_color_easy(WHITE_ON_BLACK_BRIGHT);
				else if (s == STATENUM - 1) set_color_easy(BLACK_ON_BLACK_BRIGHT);
				else set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(23, 50, yesstate);
				addstrAlt(YEA);
				if (s == STATENUM - 1 && yesstate < STATESUPERMAJORITY) set_color_easy(WHITE_ON_BLACK_BRIGHT);
				else if (s == STATENUM - 1) set_color_easy(BLACK_ON_BLACK_BRIGHT);
				else set_color_easy(WHITE_ON_BLACK);
				mvaddstrAlt(23, 60, s + 1 - yesstate);
				addstrAlt(NAY);
				pause_ms(50);
			}
		}
		if (yesstate >= STATESUPERMAJORITY) ratified = true;
	}
	if (canseethings)
	{
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		moveAlt(23, 0);
		if (ratified) addstrAlt("AMENDMENT ADOPTED.");
		else addstrAlt("AMENDMENT REJECTED.");
	}
	return ratified;
}
/* endgame - header for announcing constitutional amendments */
void amendmentheading()
{
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	mvaddstrAlt(0, 0, "Proposed Amendment ");
	addstrAlt(romannumeral(amendnum));
	addstrAlt(" to the United States Constitution:");
}

/*
    TODO: I'm not sure if anything in here should be logged. Perhaps only the notification
       that the country has become arch-conservative... --Addictgamer
*/
/* endgame - attempts to pass a constitutional amendment to help win the game */
void tossjustices(char canseethings)
{
	int j;
	if (canseethings)
	{
		music.play(MUSIC_ELECTIONS);
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(12,  6, "The Elite Liberal Congress is proposing an ELITE LIBERAL AMENDMENT!");
		getkeyAlt();
	}
	//STATE THE AMENDMENT
	if (canseethings)
	{
		int tossnum = 0;
		for (j = 0; j < COURTNUM; j++) if (court[j] != ALIGN_ELITELIBERAL) tossnum++;
		amendmentheading();
		mvaddstrAlt(2,  5, "The following former citizen");
		if (tossnum != 1)addstrAlt("s are");
		else addstrAlt(" is");
		addstrAlt(" branded Arch-Conservative:");
		int y = 4;
		for (j = 0; j < COURTNUM; j++) if (court[j] != ALIGN_ELITELIBERAL)
		{
			mvaddstrAlt(y++,  0, courtname[j]);
		}
		mvaddstrAlt(y + 1,  5, "In particular, the aforementioned former citizen");
		if (tossnum != 1)addstrAlt("s");
		addstrAlt(" may");
		mvaddstrAlt(y + 2,  0, "not serve on the Supreme Court.  Said former citizen");
		if (tossnum != 1)addstrAlt("s");
		addstrAlt(" will");
		mvaddstrAlt(y + 3,  0, "be deported to ");
		if (tossnum != 1)addstrAlt("Conservative countries");
		else addstrAlt("a Conservative country");
		addstrAlt(" of the President's");
		mvaddstrAlt(y + 4,  0, "choosing to be replaced by ");
		if (tossnum != 1)addstrAlt("Proper Justices");
		else addstrAlt("a Proper Justice");
		addstrAlt(", also of");
		mvaddstrAlt(y + 5,  0, "the President's choosing with the advice and consent of");
		mvaddstrAlt(y + 6,  0, "the Senate.");
		mvaddstrAlt(24,  0, "Press 'C' to watch the ratification process unfold.");
		while (getkeyAlt() != 'c');
	}
	if (ratify(2, -1, -1, 1, canseethings))
	{
		//BLAST JUSTICES
		for (int j = 0; j < COURTNUM; j++) if (court[j] != ALIGN_ELITELIBERAL)
		{
			do generate_name(courtname[j]); while (len(courtname[j]) > 20);
			court[j] = ALIGN_ELITELIBERAL;
		}
		amendnum++;
	}
	if (canseethings)
	{
		mvaddstrAlt(24,  0, pressKeyToReflect);
		getkeyAlt();
	}
}
 vector<string> amendmentPass;
/* endgame - attempts to pass a constitutional amendment to help win the game */
void amendment_termlimits(char canseethings)
{
	if (termlimits)return; // Durr~! Don't pass this amendment if it's already passed!
	if (canseethings)
	{
		music.play(MUSIC_ELECTIONS);
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(12,  6, "A National Convention has proposed an ELITE LIBERAL AMENDMENT!");
		getkeyAlt();
	}
	//STATE THE AMENDMENT
	if (canseethings)
	{
		amendmentheading();
		{
			int i = 2;
			for (string s : amendmentPass) {
				mvaddstrAlt(i,  0, s);
				i++;
			}
		}
		mvaddstrAlt(24,  0, "Press 'C' to watch the ratification process unfold.");
		while (getkeyAlt() != 'c');
	}
	if (ratify(2, -1, -1, 0, canseethings))
	{
		termlimits = true;
		if (canseethings)
		{
			mvaddstrAlt(24,  0, "Press any key to hold new elections!                           ");
			getkeyAlt();
		}
		elections_senate(0, canseethings);
		elections_senate(1, canseethings);
		elections_senate(2, canseethings);
		elections_house(canseethings);
		amendnum++;
	}
	else if (canseethings)
	{
		mvaddstrAlt(24,  0, pressKeyToReflect);
		getkeyAlt();
	}
}
 string conservativesRemakeWorld;
 string stalinistsRemakeWorld;
void badEndRemakeWorld(string str, string str2, string str3, EndTypes end);
void badEndRemakeWorld(string str, string str2, string str3, EndTypes end) {
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	eraseAlt();
	mvaddstrAlt(12,  10, str);
	getkeyAlt();
	set_color_easy(WHITE_ON_BLACK);
	eraseAlt();
	mvaddstrAlt(12,  12, str2);
	getkeyAlt();
	set_color_easy(BLACK_ON_BLACK_BRIGHT);
	eraseAlt();
	mvaddstrAlt(12,  14, str3);
	getkeyAlt();
	savehighscore(end);
}
/* endgame - attempts to pass a constitutional amendment to lose the game */
void attemptAmendmentEnding(char canseethings, Alignment enforcedAlignment)
{
	vector<string> output;
	MusicModes endMusic;
	vector<string> finalCabinet;
	vector<int> ratificationNumbers;
	string proposedAmendment;
	if (enforcedAlignment == ALIGN_ARCHCONSERVATIVE) {
		proposedAmendment = proposeConservative;
		output = archConservativeAmendment;
		endMusic = MUSIC_REAGANIFIED;
		finalCabinet = reaganifiedCabinet;
		ratificationNumbers = {
			-2,-1,-1,1
		};
	}
	else if (enforcedAlignment == ALIGN_STALINIST) {
		proposedAmendment = proposeStalinist;
		output = stalinAmendment;
		endMusic = MUSIC_STALINIZED;
		finalCabinet = stalinizedCabinet;
		ratificationNumbers = {
			3,-2,-2,1
		};
	}
	else {
		addstrAlt("INVALID ALIGNMENT FOR AMENDMENT");
		return;
	}
	move_center_string(12, proposedAmendment.data());
	if (canseethings)
	{
		music.play(MUSIC_ELECTIONS);
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		eraseAlt();
		getkeyAlt();
		//STATE THE AMENDMENT
		amendmentheading();
		{
			int i = 2;
			for (string s : output) {
				mvaddstrAlt(i,  0, s);
				i++;
			}
		}
		mvaddstrAlt(24,  0, "Press 'C' to watch the ratification process unfold.");
		while (getkeyAlt() != 'c');
	}
	if (ratify(ratificationNumbers[0], ratificationNumbers[1], ratificationNumbers[2], ratificationNumbers[3], canseethings))
	{
		music.play(endMusic);
		if (canseethings)
		{
			mvaddstrAlt(24,  0, "Press any key to reflect on what has happened ONE LAST TIME.");
			getkeyAlt();
		}
		amendnum = 1; // Constitution repealed...
		if (canseethings)
		{
			strcpy(execname[EXEC_PRESIDENT], finalCabinet[0].data());
			strcpy(execname[EXEC_VP], finalCabinet[1].data());
			strcpy(execname[EXEC_STATE], finalCabinet[2].data());
			strcpy(execname[EXEC_ATTORNEY], finalCabinet[3].data());
			for (int e = 0; e < EXECNUM; e++) exec[e] = enforcedAlignment;
			if (enforcedAlignment == ALIGN_ARCHCONSERVATIVE) {
				for (int l = 0; l < LAWNUM; l++) lawList[l] = enforcedAlignment;
				liberalagenda(-1);
				savehighscore(END_REAGAN);
			}
			else if (enforcedAlignment == ALIGN_STALINIST) {
				for (int l = 0; l < LAWNUM; l++) lawList[l] = stalinview(l, true) ? ALIGN_ELITELIBERAL : ALIGN_ARCHCONSERVATIVE;
				liberalagenda(-2);
				savehighscore(END_STALIN);
			}
		}
		else
		{
			string endingOne;
			string endingTwo;
			string endingThree;
			EndTypes ending;
			vector<string> inPrison;
			switch (cantseereason)
			{
			case 1:
				//DATING AND 
				endingOne = youWentOnVacation;
				if (enforcedAlignment == ALIGN_ARCHCONSERVATIVE) {
					endingTwo = conservativesRemakeWorld;
				}
				else if (enforcedAlignment == ALIGN_STALINIST) {
					endingTwo = stalinistsRemakeWorld;
				}
				endingThree = they_ll_round_you_up;
				ending = END_DATING;
				break;
			case 2:
				//HIDING AND 
				endingOne = youWentIntoHiding;
				if (enforcedAlignment == ALIGN_ARCHCONSERVATIVE) {
					endingTwo = conservativesRemakeWorld;
				}
				else if (enforcedAlignment == ALIGN_STALINIST) {
					endingTwo = stalinistsRemakeWorld;
				}
				endingThree = they_ll_round_you_up;
				ending = END_HIDING;
				break;
			case 3:
				//IF YOU ARE ALL IN PRISON, 
				endingOne = whileYouWereInPrison;
				if (enforcedAlignment == ALIGN_ARCHCONSERVATIVE) {
					vector<string> inPrison = conservativePrison;
				}
				else if (enforcedAlignment == ALIGN_STALINIST) {
					vector<string> inPrison = stalinistPrison;
				}
				endingTwo = inPrison[0];
				endingThree = inPrison[1];
				ending = END_PRISON;
				break;
			case 4:
				//DISBANDED AND 
				endingOne = youDisappearedSafely;
				if (enforcedAlignment == ALIGN_ARCHCONSERVATIVE) {
					endingTwo = conservativesRemakeWorld;
				}
				else if (enforcedAlignment == ALIGN_STALINIST) {
					endingTwo = stalinistsRemakeWorld;
				}
				endingThree = they_ll_round_you_up;
				ending = END_DISBANDLOSS;
				break;
			}
			badEndRemakeWorld(endingOne, endingTwo, endingThree, ending);
		}
		title_screen::getInstance().reset();
		viewhighscores(endMusic);
		end_game();
	}
	else
	{
		if (canseethings)
		{
			mvaddstrAlt(24,  0, "Press any key to breathe a sigh of relief.                   ");
			getkeyAlt();
		}
	}
}
 