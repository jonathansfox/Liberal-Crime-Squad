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

#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
extern MusicClass music;
extern int ustat_recruits;
extern int ustat_kidnappings;
extern int ustat_dead;
extern int ustat_kills;
extern int ustat_funds;
extern int ustat_spent;
extern int ustat_buys;
extern int ustat_burns;
extern int stat_buys;
extern int stat_burns;
extern int stat_kidnappings;
extern int year;
extern int stat_dead;
extern int stat_kills;
extern int stat_recruits;
/* displays the high score board */
void viewhighscores(int musicoverride)
{
	if (musicoverride != MUSIC_OFF) music.play(musicoverride);
	int s;
	loadhighscores();
	short validsum = 0;
	for (s = 0; s < SCORENUM; s++)
	{
		if (score[s].valid)validsum++;
	}
	eraseAlt();
	set_color(COLOR_WHITE, COLOR_BLACK, 1);
	moveZeroZero();
	if (!validsum)
	{
		addstrAlt("No valid scores, press any button to return.");
		return;
	}
	addstrAlt("The Liberal ELITE");
	int y = 2;
	for (s = 0; s < SCORENUM; s++)
	{
		if (score[s].valid)
		{
			if (yourscore == s&&score[s].endtype == END_WON)set_color(COLOR_GREEN, COLOR_BLACK, 1);
			else if (yourscore == s)set_color(COLOR_RED, COLOR_BLACK, 1);
			else set_color(COLOR_WHITE, COLOR_BLACK, 1);
			moveAlt(y, 0);
			addstrAlt(score[s].slogan);
			if (yourscore == s&&score[s].endtype == END_WON)set_color(COLOR_GREEN, COLOR_BLACK, 0);
			else if (yourscore == s)set_color(COLOR_RED, COLOR_BLACK, 0);
			else set_color(COLOR_WHITE, COLOR_BLACK, 0);
			moveAlt(y + 1, 0);
			switch (score[s].endtype)
			{
			case END_WON:
				addstrAlt("The Liberal Crime Squad liberalized the country in ");
				if (yourscore == s&&musicoverride == MUSIC_OFF) music.play(MUSIC_VICTORY);
				break;
			case END_POLICE:
				addstrAlt("The Liberal Crime Squad was brought to justice in ");
				if (yourscore == s&&musicoverride == MUSIC_OFF) music.play(MUSIC_DEFEAT);
				break;
			case END_CIA:
				addstrAlt("The Liberal Crime Squad was blotted out in ");
				if (yourscore == s&&musicoverride == MUSIC_OFF) music.play(MUSIC_DEFEAT);
				break;
			case END_HICKS:
				addstrAlt("The Liberal Crime Squad was mobbed in ");
				if (yourscore == s&&musicoverride == MUSIC_OFF) music.play(MUSIC_DEFEAT);
				break;
			case END_CORP:
				addstrAlt("The Liberal Crime Squad was downsized in ");
				if (yourscore == s&&musicoverride == MUSIC_OFF) music.play(MUSIC_DEFEAT);
				break;
			case END_DEAD:
				addstrAlt("The Liberal Crime Squad was KIA in ");
				if (yourscore == s&&musicoverride == MUSIC_OFF) music.play(MUSIC_DEFEAT);
				break;
			case END_REAGAN:
				addstrAlt("The country was Reaganified in ");
				if (yourscore == s&&musicoverride == MUSIC_OFF) music.play(MUSIC_REAGANIFIED);
				break;
			case END_PRISON:
				addstrAlt("The Liberal Crime Squad died in prison in ");
				if (yourscore == s&&musicoverride == MUSIC_OFF) music.play(MUSIC_DEFEAT);
				break;
			case END_EXECUTED:
				addstrAlt("The Liberal Crime Squad was executed in ");
				if (yourscore == s&&musicoverride == MUSIC_OFF) music.play(MUSIC_DEFEAT);
				break;
			case END_DATING:
				addstrAlt("The Liberal Crime Squad was on vacation in ");
				if (yourscore == s&&musicoverride == MUSIC_OFF) music.play(MUSIC_DEFEAT);
				break;
			case END_HIDING:
				addstrAlt("The Liberal Crime Squad was in permanent hiding in ");
				if (yourscore == s&&musicoverride == MUSIC_OFF) music.play(MUSIC_DEFEAT);
				break;
			case END_DISBANDLOSS:
				addstrAlt("The Liberal Crime Squad was hunted down in ");
				if (yourscore == s&&musicoverride == MUSIC_OFF) music.play(MUSIC_DEFEAT);
				break;
			case END_DISPERSED:
				addstrAlt("The Liberal Crime Squad was scattered in ");
				if (yourscore == s&&musicoverride == MUSIC_OFF) music.play(MUSIC_DEFEAT);
				break;
			case END_CCS:
				addstrAlt("The Liberal Crime Squad was out-Crime Squadded in ");
				if (yourscore == s&&musicoverride == MUSIC_OFF) music.play(MUSIC_DEFEAT);
				break;
			case END_FIREMEN:
				addstrAlt("The Liberal Crime Squad was burned in ");
				if (yourscore == s&&musicoverride == MUSIC_OFF) music.play(MUSIC_DEFEAT);
				break;
			case END_STALIN:
				addstrAlt("The country was Stalinized in ");
				if (yourscore == s&&musicoverride == MUSIC_OFF) music.play(MUSIC_STALINIZED);
				break;
			}
			addstrAlt(getmonth(score[s].month));
			addstrAlt(singleSpace);
			addstrAlt(score[s].year);
			addstrAlt(". ");
			moveAlt(y + 2, 0);
			addstrAlt("Recruits: ");
			addstrAlt(score[s].stat_recruits);
			moveAlt(y + 3, 0);
			addstrAlt("Martyrs: ");
			addstrAlt(score[s].stat_dead);
			moveAlt(y + 2, 20);
			addstrAlt("Kills: ");
			addstrAlt(score[s].stat_kills);
			moveAlt(y + 3, 20);
			addstrAlt("Kidnappings: ");
			addstrAlt(score[s].stat_kidnappings);
			moveAlt(y + 2, 40);
			addstrAlt("$ Taxed: ");
			addstrAlt(score[s].stat_funds);
			moveAlt(y + 3, 40);
			addstrAlt("$ Spent: ");
			addstrAlt(score[s].stat_spent);
			moveAlt(y + 2, 60);
			addstrAlt("Flags Bought: ");
			addstrAlt(score[s].stat_buys);
			moveAlt(y + 3, 60);
			addstrAlt("Flags Burned: ");
			addstrAlt(score[s].stat_burns);
			y += 4;
		}
	}
	set_color(COLOR_GREEN, COLOR_BLACK, 1);
	//UNIVERSAL STATS
	moveAlt(22, 0);
	addstrAlt("Universal Liberal Statistics:");
	moveAlt(23, 0);
	addstrAlt("Recruits: ");
	addstrAlt(ustat_recruits);
	moveAlt(24, 0);
	addstrAlt("Martyrs: ");
	addstrAlt(ustat_dead);
	moveAlt(23, 20);
	addstrAlt("Kills: ");
	addstrAlt(ustat_kills);
	moveAlt(24, 20);
	addstrAlt("Kidnappings: ");
	addstrAlt(ustat_kidnappings);
	moveAlt(23, 40);
	addstrAlt("$ Taxed: ");
	addstrAlt(ustat_funds);
	moveAlt(24, 40);
	addstrAlt("$ Spent: ");
	addstrAlt(ustat_spent);
	moveAlt(23, 60);
	addstrAlt("Flags Bought: ");
	addstrAlt(ustat_buys);
	moveAlt(24, 60);
	addstrAlt("Flags Burned: ");
	addstrAlt(ustat_burns);
	//getkey();
}
struct  saveLoadChunk {
	void * Buffer;
	size_t      ElementSize;
	size_t      ElementCount;
	saveLoadChunk(void * _Buffer, int _ElementSize, int _ElementCount) :Buffer(_Buffer), ElementSize(_ElementSize), ElementCount(_ElementCount) {}
};
vector<saveLoadChunk> highScoreSaveLoad = {
	saveLoadChunk(&ustat_recruits, sizeof(int), 1),
	saveLoadChunk(&ustat_dead, sizeof(int), 1),
	saveLoadChunk(&ustat_kills, sizeof(int), 1),
	saveLoadChunk(&ustat_kidnappings, sizeof(int), 1),
	saveLoadChunk(&ustat_funds, sizeof(int), 1),
	saveLoadChunk(&ustat_spent, sizeof(int), 1),
	saveLoadChunk(&ustat_buys, sizeof(int), 1),
	saveLoadChunk(&ustat_burns, sizeof(int), 1),
	saveLoadChunk(score, sizeof(highscorest), SCORENUM)
};
/* loads the high scores file */
void loadhighscores()
{
	for (int s = 0; s < SCORENUM; s++)score[s].valid = 0;
	//LOAD FILE
	int loadversion;
	FILE *h = LCSOpenFile("score.dat", "rb", LCSIO_PRE_HOME);
	if (h != NULL)
	{
		fread(&loadversion, sizeof(int), 1, h);
		if (loadversion < lowestloadscoreversion)
		{
			LCSCloseFile(h);
			return;
		}
		for (saveLoadChunk s : highScoreSaveLoad) {
			fread(s.Buffer, s.ElementSize, s.ElementCount, h);
		}
		LCSCloseFile(h);
	}
}
/* saves a new high score */
void savehighscore(char endtype)
{
	loadhighscores();
	//MERGE THE STATS
	ustat_recruits += stat_recruits;
	ustat_dead += stat_dead;
	ustat_kills += stat_kills;
	ustat_kidnappings += stat_kidnappings;
	ustat_funds += ledger.total_income;
	ustat_spent += ledger.total_expense;
	ustat_buys += stat_buys;
	ustat_burns += stat_burns;
	//PLACE THIS HIGH SCORE BY DATE IF NECESSARY
	yourscore = -1;
	for (int s = 0; s<SCORENUM; s++)
	{
		if ((endtype == END_WON&&score[s].endtype == END_WON&&
			year == score[s].year&&month == score[s].month&&
			ledger.total_expense + ledger.total_expense>score[s].stat_spent + score[s].stat_funds) ||
			(endtype == END_WON&&score[s].endtype == END_WON
				&& (year < score[s].year ||
					(year == score[s].year && month<score[s].month))) ||
			(endtype == END_WON&&score[s].endtype != END_WON) ||
			(endtype != END_WON&&score[s].endtype != END_WON&&
				ledger.total_expense + ledger.total_income>score[s].stat_spent + score[s].stat_funds) ||
			score[s].valid == 0)
		{
			for (int s2 = SCORENUM - 1; s2 >= s + 1; s2--)
			{
				score[s2] = score[s2 - 1];
			}
			strcpy(score[s].slogan, slogan);
			score[s].month = month;
			score[s].year = year;
			score[s].stat_recruits = stat_recruits;
			score[s].stat_dead = stat_dead;
			score[s].stat_kills = stat_kills;
			score[s].stat_kidnappings = stat_kidnappings;
			score[s].stat_funds = ledger.total_income;
			score[s].stat_spent = ledger.total_expense;
			score[s].stat_buys = stat_buys;
			score[s].stat_burns = stat_burns;
			score[s].valid = 1;
			score[s].endtype = endtype;
			yourscore = s;
			break;
		}
	}
	FILE *h = LCSOpenFile("score.dat", "wb", LCSIO_PRE_HOME);
	if (h != NULL)
	{
		int lversion = version;
		fwrite(&lversion, sizeof(int), 1, h);
		for (saveLoadChunk s : highScoreSaveLoad) {
			fwrite(s.Buffer, s.ElementSize, s.ElementCount, h);
		}
		LCSCloseFile(h);
	}
}