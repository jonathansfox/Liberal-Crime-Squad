#define	TITLESCREEN_CPP
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
// Note: this file is encoded in the PC-8 / Code Page 437 / OEM-US character set
// (The same character set used by Liberal Crime Squad when it is running)
// Certain special characters won't display correctly unless your text editor is
// set to use that character set, such as this e with an accent: ‚
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
// select CONST_titlescreen001, choose CONST_titlescreenB004,
// then choose CONST_titlescreen002.
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

void title_screen::choose_savefile_name()
{
	savefile_name = printNewGameHeader();
	setup_newgame();
	makecharacter();
}

void title_screen::selectAndLoadSaveFile() {
	s_savefiles = move(LCSSaveFiles());
	char loaded = s_savefiles.size() > 0;
	if (!loaded)
	{
		choose_savefile_name();
	}
	else {
		bool to_delete = false;
		int page = 0;
		// IsaacG This almost has to be redone
		while (!len(savefile_name))
		{
			printSaveHeader(to_delete);
			printSaveList(page, s_savefiles);
			printSaveFooter(to_delete);

			int c = getkeyAlt();
			//PAGE UP
			if (is_page_up(c) && page > 0)page--;
			//PAGE DOWN
			if (is_page_down(c) && (page + 1) * 19 < s_savefiles.size())page++;
			if (c >= 'a'&&c <= 's')
			{
				const int p = page * 19 + c - 'a';
				if (p < s_savefiles.size()) {
					if (!to_delete) {
						savefile_name = s_savefiles[p];
					}
					else {
						printAreYouSure(s_savefiles[p]);
						c = getkeyAlt();
						if (c == 'y')
						{
							LCSDeleteFile(s_savefiles[p].c_str(), LCSIO_PRE_HOME);
							s_savefiles = move(LCSSaveFiles());
						}
						continue;
					}
				}
				else if (p == s_savefiles.size()) {
					choose_savefile_name();
				}
			}
			else if (c == 'v') to_delete = !to_delete;
			if (c == ESC || c == 'x') end_game();
		}
		load(savefile_name);
	}
}
title_screen title_screen::s_title_singleton;
bool title_screen::titleInitiated = false;
title_screen title_screen::getInstance()
{
	if (!titleInitiated) {
		titleInitiated = true;
		s_title_singleton = title_screen();
	}
	return s_title_singleton;
}

// public
void title_screen::mode_title()
{
	printTitleScreen();
	int c = 0;
	do {
		if (c == 'h') {
			viewhighscores();
			pressAnyKey();
			printTitleScreen();
		}
		if (c == 'm') music.enableIf(!music.isEnabled());
		if (c == 'd') {
			automatedDataTests();
			printTitleScreen();
		}
		printMusicFooter(music.isEnabled());
		if (c == ESC || c == 'x') end_game();
		c = getkeyAlt();
	} while (c == 'm' || c == 'h' || c == 'x' || c == ESC || c == 'd');
	selectAndLoadSaveFile();
	mode = GAMEMODE_BASE;
	// Main Loop
	mode_base();
	savegame(savefile_name);
}
bool title_screen::autosave = true;
void title_screen::reset()
{
	//LCSDeleteFile(savefile_name.c_str(), LCSIO_PRE_HOME);
	LCSDeleteFile(savefile_name.c_str(), LCSIO_PRE_HOME);

	//deleteVerbose(savefile_name);
}
void title_screen::setautosaveoption(bool shouldautosave) {
	autosave = shouldautosave;
}
void title_screen::autosavegame() {
	if (autosave) {
		savegame(savefile_name);
	}
}