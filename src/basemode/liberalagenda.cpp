// Note: this file is encoded in the PC-8 / Code Page 437 / OEM-US character set
// (The same character set used by Liberal Crime Squad when it is running)
// Certain special characters won't display correctly unless your text editor is
// set to use that character set, such as this e with an accent: 
// In Windows Notepad with the Terminal font, OEM/DOS encoding it should work fine.
// You can set this in Notepad by going to Format->Font and choosing the Terminal font,
// then choosing OEM/DOS in the Script dropdown box.
// In Notepad++ go to the Encoding menu, Character sets, Western European, OEM-US... easy!
// In Code::Blocks's editor go to Settings->Editor->the Other Settings tab and
// then pick WINDOWS-437 from the dropdown box and then choose the radio button
// to make this the default encoding and disable auto-detection of the encoding.
// Then close the file and reopen it (since Code::Blocks detects the encoding
// when it opens the file and it can't be changed after that; what we changed was
// how it detects encoding for files it opens in the future, not files already open).
// In Microsoft Visual C++, right-click the file in the Solution Explorer,
// select "Open With...", choose "C++ Source Code Editor (with encoding)",
// then choose "OEM United States - Codepage 437".
// In MS-DOS Editor (included with Windows as EDIT.COM in your system32 directory),
// the codepage will be correct already since it's running in a console window just
// like Liberal Crime Squad. Well OK, the encoding might be wrong, but then it's wrong
// in Liberal Crime Squad TOO, and to fix it, go to Control Panel, Regional and Language Settings,
// Advanced tab, and choose English (United States) from the dropdown box as the encoding
// for non-Unicode applications, then press OK.
// If you have a Linux or other UNIX-based system you are obviously smart enough
// to figure out for yourself how to open a file in OEM-US PC-8 codepage 437 in
// your favorite text editor. If you're on Mac OS X, well that's UNIX-based, figure
// it out for yourself.

#include <includes.h>
#include "creature/creatureEnums.h"

//#include "common/commondisplay.h"
void set_alignment_color(short alignment, bool extended_range = false);

//#include "common/getnames.h"
string getlaw(int l);

//#include "common/commonactions.h"
void cleangonesquads();


#include <cursesAlternative.h>
#include <cursesAlternativeConstants.h>
#include <customMaps.h>
#include <set_color_support.h>
#include "common/musicClass.h"
extern MusicClass music;
extern int year;
extern short exec[EXECNUM];
extern char execname[EXECNUM][POLITICIAN_NAMELEN];
extern string tag_Sta;
extern string tag_Libp;
extern string tag_Lib;
extern string tag_Mod;
extern string tag_Cons;
extern string tag_Consp;

extern short interface_pgup;
extern short interface_pgdn;
extern short lawList[LAWNUM];
extern short house[HOUSENUM];
extern short senate[SENATENUM];
extern short court[COURTNUM];
extern bool stalinmode;
extern short execterm;
extern char courtname[COURTNUM][POLITICIAN_NAMELEN];
extern short wincondition;
extern int disbandtime;

 vector<string> supremeChars;
 vector<string> courtChars;
string pressLToViewHighScores;
typedef map<short, vector<string>> shortAndTwoStrings;
shortAndTwoStrings endgameLawStrings;

#include "common/creaturePool.h"

enum Pages
{
	PAGE_LEADERS,
	PAGE_ISSUES_A,
	PAGE_ISSUES_B,
	//PAGE_POLLS_A,
	//PAGE_POLLS_B
	PAGENUM
};
vector<string> disbandingMessage;
vector<string> issue_phrases;

const string mostlyendings = "mostlyendings\\";
vector<file_and_text_collection> liberl_agenda_text_file_collection = {
	customText(&disbandingMessage, mostlyendings + "disbandingMessage.txt"),
	customText(&issue_phrases, mostlyendings + "issue_phrases.txt"),
	customText(&supremeChars, mostlyendings + "supremeChars.txt"),
	customText(&courtChars, mostlyendings + "courtChars.txt"),
};


/* base - liberal agenda - disband */
bool confirmdisband()
{
	string word = pickrandom(issue_phrases);
	for (int pos = 0; pos < len(word);)
	{
		eraseAlt();
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0, 0, "Are you sure you want to disband?");
		set_color_easy(WHITE_ON_BLACK);
		for (int i = 0; i < len(disbandingMessage); i++) {
			mvaddstrAlt(i + 2, 0, disbandingMessage[i]);
		}
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(13, 0, "Type this Liberal phrase to confirm (press a wrong letter to rethink it):");
		for (int x = 0; x < len(word); x++)
		{
			if (x == pos) set_color_easy(GREEN_ON_BLACK);
			else if (x < pos) set_color_easy(GREEN_ON_BLACK_BRIGHT);
			else set_color_easy(WHITE_ON_BLACK);
			mvaddcharAlt(15, x, word[x]);
		}
		if (getkeyAlt() == ::tolower(word[pos]))
		{
			pos++;
			if (word[pos] == ' ' || word[pos] == '\'' || word[pos] == '-') pos++;
		}
		else return false;
	}
	//SET UP THE DISBAND
	CreaturePool::getInstance().setupDisband();
	cleangonesquads();
	disbandtime = year;
	return true;
}

/* base - liberal agenda */
bool liberalagenda(signed char won)
{
	int page = 0, y;
	while (true)
	{
		eraseAlt();
		if (won == 1)
		{
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			mvaddstrAlt(0,  0, "The Triumph of the Liberal Agenda");
			music.play(MUSIC_VICTORY);
		}
		else if (won == -1 || won == -2)
		{
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(0,  0, "The Abject Failure of the Liberal Agenda");
			if (won == -1) music.play(MUSIC_REAGANIFIED);
			if (won == -2) music.play(MUSIC_STALINIZED);
		}
		else
		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(0,  0, "The Status of the Liberal Agenda");
			music.play(MUSIC_LIBERALAGENDA);
		}
		if (page < 0) page = PAGENUM - 1;
		if (page >= PAGENUM) page = 0;
		switch (page)
		{
		case PAGE_LEADERS:
		{
			mvaddstrAlt(1,  0, "ษอออออออออออออออออปฤฤฤฤฤฤฤฤฤฤยฤฤฤฤฤฤฤฤฤฤฟ");
			mvaddstrAlt(2,  0, "บ GENERAL SUMMARY บ ISSUES A ณ ISSUES B ณ");
			mvaddstrAlt(3,  0, "ผ                 ศออออออออออฯออออออออออฯอออออออออออออออออออออออออออออออออออออออ");
			signed char align = exec[EXEC_PRESIDENT];
			set_alignment_color(align, true);
			moveAlt(5, 0);
			if (won == -1) addstrAlt("King: ");
			else if (won == -2) addstrAlt("General Secretary: ");
			else
			{
				addstrAlt("President ");
				if (execterm == 1)addstrAlt("(1st Term):");
				else addstrAlt("(2nd Term):");
			}
			if (won == -2) moveAlt(5, 30);
			else mvaddstrAlt(5,  25, execname[EXEC_PRESIDENT]);
			align = exec[EXEC_VP];
			set_alignment_color(align, true);
			moveAlt(6, 0);
			if (won == -1) addstrAlt("Minister of Love: ");
			else if (won == -2) addstrAlt("Premier: ");
			else addstrAlt("Vice President: ");
			if (won == -2) moveAlt(6, 30);
			else mvaddstrAlt(6,  25, execname[EXEC_VP]);
			align = exec[EXEC_STATE];
			set_alignment_color(align, true);
			moveAlt(7, 0);
			if (won == -1) addstrAlt("Minister of Peace: ");
			else if (won == -2) addstrAlt("Foreign Affairs Commissar: ");
			else addstrAlt("Secretary of State: ");
			if (won == -2) moveAlt(7, 30);
			else mvaddstrAlt(7,  25, execname[EXEC_STATE]);
			align = exec[EXEC_ATTORNEY];
			set_alignment_color(align, true);
			moveAlt(8, 0);
			if (won == -1) addstrAlt("Minister of Truth: ");
			else if (won == -2) addstrAlt("Internal Affairs Commissar: ");
			else addstrAlt("Attorney General: ");
			if (won == -2) moveAlt(8, 30);
			else mvaddstrAlt(8,  25, execname[EXEC_ATTORNEY]);
			if (won == -1)
			{
				set_color_easy(RED_ON_BLACK_BRIGHT);
				mvaddstrAlt(10,  0, "The Congress consists of CEOs and televangelists.");
			}
			else if (won == -2)
			{
				set_color_easy(RED_ON_BLACK_BRIGHT);
				mvaddstrAlt(10,  0, "The Congress consists of Stalinist Party loyalists.");
			}
			else
			{
				int housemake[6] = { 0,0,0,0,0,0 };
				for (int h = 0; h < HOUSENUM; h++) housemake[house[h] + 2]++;
				if (housemake[5] + min(housemake[0], housemake[4]) >= HOUSEMAJORITY) align = ALIGN_STALINIST; // Stalinists have a majority (perhaps with help from extremists on both sides)
				else if (housemake[0] >= HOUSEMAJORITY) align = ALIGN_ARCHCONSERVATIVE; // Arch-Conservatives have a majority
				else if (housemake[4] >= HOUSEMAJORITY) align = ALIGN_ELITELIBERAL; // Elite Liberals have a majority
				else if (housemake[0] + housemake[1] >= HOUSEMAJORITY) align = ALIGN_CONSERVATIVE; // Conservatives plus Arch-Conservatives have a majority
				else if (housemake[3] + housemake[4] >= HOUSEMAJORITY) align = ALIGN_LIBERAL; // Liberals plus Elite Liberals have a majority
				else align = ALIGN_MODERATE; // nobody has a majority
				set_alignment_color(align, true);
				mvaddstrAlt(10, 0, "House: ");
				if (stalinmode) addstrAlt(tostring(housemake[5]) + tag_Sta);
				addstrAlt(tostring(housemake[4]) + tag_Libp);
				addstrAlt(tostring(housemake[3]) + tag_Lib);
				addstrAlt(tostring(housemake[2]) + tag_Mod);
				addstrAlt(tostring(housemake[1]) + tag_Cons);
				addstrAlt(tostring(housemake[0]) + tag_Consp);
				int senatemake[6] = { 0,0,0,0,0,0 };
				for (int s = 0; s < SENATENUM; s++) senatemake[senate[s] + 2]++;
				senatemake[exec[EXEC_VP] + 2]++; // Vice President is tie-breaking vote in the Senate
				if (senatemake[5] + min(senatemake[0], senatemake[4]) >= SENATEMAJORITY) align = ALIGN_STALINIST; // Stalinists have a majority (perhaps with help from extremists on both sides)
				else if (senatemake[0] >= SENATEMAJORITY) align = ALIGN_ARCHCONSERVATIVE; // Arch-Conservatives have a majority
				else if (senatemake[4] >= SENATEMAJORITY) align = ALIGN_ELITELIBERAL; // Elite Liberals have a majority
				else if (senatemake[0] + senatemake[1] >= SENATEMAJORITY) align = ALIGN_CONSERVATIVE; // Conservatives plus Arch-Conservatives have a majority
				else if (senatemake[3] + senatemake[4] >= SENATEMAJORITY) align = ALIGN_LIBERAL; // Liberals plus Elite Liberals have a majority
				else align = ALIGN_MODERATE; // nobody has a majority
				set_alignment_color(align, true);
				senatemake[exec[EXEC_VP] + 2]--; // Vice President isn't actually a Senator though
				mvaddstrAlt(11, 0, "Senate: ");
				if (stalinmode) addstrAlt(tostring(senatemake[5]) + tag_Sta);
				addstrAlt(tostring(senatemake[4]) + tag_Libp);
				addstrAlt(tostring(senatemake[3]) + tag_Lib);
				addstrAlt(tostring(senatemake[2]) + tag_Mod);
				addstrAlt(tostring(senatemake[1]) + tag_Cons);
				addstrAlt(tostring(senatemake[0]) + tag_Consp);
			}
			if (won == -1 || won == -2) set_color_easy(RED_ON_BLACK_BRIGHT);
			else if (won == 1) set_color_easy(GREEN_ON_BLACK_BRIGHT);
			else
			{
				int courtmake[6] = { 0,0,0,0,0,0 };
				for (int s = 0; s < COURTNUM; s++) courtmake[court[s] + 2]++;
				if (courtmake[5] + min(courtmake[0], courtmake[4]) >= COURTMAJORITY) align = ALIGN_STALINIST; // Stalinists have a majority (perhaps with help from extremists on both sides)
				else if (courtmake[0] >= COURTMAJORITY) align = ALIGN_ARCHCONSERVATIVE; // Arch-Conservatives have a majority
				else if (courtmake[4] >= COURTMAJORITY) align = ALIGN_ELITELIBERAL; // Elite Liberals have a majority
				else if (courtmake[0] + courtmake[1] >= COURTMAJORITY) align = ALIGN_CONSERVATIVE; // Conservatives plus Arch-Conservatives have a majority
				else if (courtmake[3] + courtmake[4] >= COURTMAJORITY) align = ALIGN_LIBERAL; // Liberals plus Elite Liberals have a majority
				else align = ALIGN_MODERATE; // nobody has a majority
				set_alignment_color(align, true);
			}
			for (int i = 0; i < len(supremeChars); i++) {
				mvaddstrAlt(5 + i, 56, supremeChars[i]);
			}
			for (int i = 0; i < len(courtChars); i++) {
				mvaddstrAlt(6 + i, 58, courtChars[i]);
			}
			if (won == -1)
			{
				mvaddstrAlt(7, 65, "Replaced");
				mvaddstrAlt(8, 63, "By Corporate");
				mvaddstrAlt(9, 62, "Ethics Officers");
			}
			else if (won == -2)
			{
				mvaddstrAlt(7, 63, "Replaced By");
				mvaddstrAlt(8, 62, "Stalinist Show");
				mvaddstrAlt(9, 63, "Trial Judges");
			}
			else
			{
				y = 4;
				for (int c = 0; c < COURTNUM; c++, y++)
				{
					set_alignment_color(court[c], true);
					mvaddstrAlt(y, 60, courtname[c]);
				}
			}
			for (int l = 0; l < LAWNUM; l++)
			{
				if (won == -1 || won == -2)
					set_alignment_color(ALIGN_ARCHCONSERVATIVE, true);
				else if (won == 1 && wincondition == WINCONDITION_ELITE)
					set_alignment_color(ALIGN_ELITELIBERAL, true);
				else set_color_easy(BLACK_ON_BLACK_BRIGHT);
				mvaddstrAlt(14 + l / 3, l % 3 * 26, "\x11ฤฤฤฤฤ\x10");
				if (won == -1 || won == -2)
					set_alignment_color(ALIGN_ARCHCONSERVATIVE, true);
				else set_alignment_color(lawList[l], true);
				addstrAlt(getlaw(l));
				mvaddcharAlt(14 + l / 3, l % 3 * 26 + 3 - lawList[l], 'O');
			}
			break;
		}
		case PAGE_ISSUES_A:
		case PAGE_ISSUES_B:
		{
			if (page == PAGE_ISSUES_A)
			{
				mvaddstrAlt(1,  0, "ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤษออออออออออปฤฤฤฤฤฤฤฤฤฤฟ");
				mvaddstrAlt(2,  0, "ณ GENERAL SUMMARY บ ISSUES A บ ISSUES B ณ");
				mvaddstrAlt(3,  0, "ฯอออออออออออออออออผ          ศออออออออออฯอออออออออออออออออออออออออออออออออออออออ");
			}
			else
			{
				mvaddstrAlt(1,  0, "ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤยฤฤฤฤฤฤฤฤฤฤษออออออออออป");
				mvaddstrAlt(2,  0, "ณ GENERAL SUMMARY ณ ISSUES A บ ISSUES B บ");
				mvaddstrAlt(3,  0, "ฯอออออออออออออออออฯออออออออออผ          ศอออออออออออออออออออออออออออออออออออออออ");
			}
			int y = 4, startinglaw = 0;
			if (page == PAGE_ISSUES_B) startinglaw = 18;
			for (int l = startinglaw; l < startinglaw + 18 && l < LAWNUM; l++, y++)
			{
				if (won == -1 || won == -2)
					set_alignment_color(ALIGN_ARCHCONSERVATIVE, true);
				else set_alignment_color(lawList[l], true);
				moveAlt(y, 0);
				if (won == -2)addstrAlt(endgameLawStrings[l][0]);
				else if (won == -1)addstrAlt(endgameLawStrings[l][1]);
				else if (lawList[l] == ALIGN_ARCHCONSERVATIVE)
					addstrAlt(endgameLawStrings[l][2]);
				else if (lawList[l] == -1)addstrAlt(endgameLawStrings[l][3]);
				else if (lawList[l] == 0)addstrAlt(endgameLawStrings[l][4]);
				else if (lawList[l] == 1)addstrAlt(endgameLawStrings[l][5]);
				else if (won != 1 || wincondition != WINCONDITION_ELITE)addstrAlt(endgameLawStrings[l][6]);
				else addstrAlt(endgameLawStrings[l][7]);
			}
			break;
		}
		}
		if (won == 1)
		{
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			if (wincondition == WINCONDITION_EASY)
				mvaddstrAlt(23, 0, "The country has achieved Liberal status!");
			else mvaddstrAlt(23, 0, "The country has achieved Elite Liberal status!");
			mvaddstrAlt(24, 0, pressLToViewHighScores);
			int c = getkeyAlt();
			if (c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) page++;
			else if (c == interface_pgup || c == KEY_UP || c == KEY_LEFT) page--;
			else if (c == 'l') break;
		}
		else if (won == -1)
		{
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(23, 0, "The country has been Reaganified.");
			mvaddstrAlt(24, 0, pressLToViewHighScores);
			int c = getkeyAlt();
			if (c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) page++;
			else if (c == interface_pgup || c == KEY_UP || c == KEY_LEFT) page--;
			else if (c == 'l') break;
		}
		else if (won == -2)
		{
			set_color_easy(RED_ON_BLACK_BRIGHT);
			mvaddstrAlt(23, 0, "The country has been Stalinized.");
			mvaddstrAlt(24, 0, pressLToViewHighScores);
			int c = getkeyAlt();
			if (c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) page++;
			else if (c == interface_pgup || c == KEY_UP || c == KEY_LEFT) page--;
			else if (c == 'l') break;
		}
		else
		{
			moveAlt(23, 0);
			if (stalinmode)
			{
				set_color_easy(RED_ON_BLACK_BRIGHT);
				addstrAlt("Stalinist  ");
			}
			set_color_easy(GREEN_ON_BLACK_BRIGHT);
			addstrAlt("Elite Liberal  ");
			if (!stalinmode)
			{
				set_color_easy(WHITE_ON_BLACK);
				addstrAlt("-  ");
			}
			set_color_easy(CYAN_ON_BLACK_BRIGHT);
			addstrAlt("Liberal  ");
			if (!stalinmode)
			{
				set_color_easy(WHITE_ON_BLACK);
				addstrAlt("-  ");
			}
			set_color_easy(YELLOW_ON_BLACK_BRIGHT);
			addstrAlt("moderate  ");
			if (!stalinmode)
			{
				set_color_easy(WHITE_ON_BLACK);
				addstrAlt("-  ");
			}
			set_color_easy(MAGENTA_ON_BLACK_BRIGHT);
			addstrAlt("Conservative  ");
			if (!stalinmode)
			{
				set_color_easy(WHITE_ON_BLACK);
				addstrAlt("-  ");
			}
			set_color_easy(RED_ON_BLACK_BRIGHT);
			addstrAlt("Arch-Conservative");
			set_color_easy(WHITE_ON_BLACK);
			//mvaddstrAlt(23,0,"Once these are Green, the country will have achieved Elite Liberal status.");
			mvaddstrAlt(24, 0, "Press D to disband and wait. Use cursors for other pages. Any other key to exit.");
			int c = getkeyAlt();
			if (c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) page++;
			else if (c == interface_pgup || c == KEY_UP || c == KEY_LEFT) page--;
			else if (c == 'd') return confirmdisband();
			else break;
		}
	}
	return false;
}
