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

#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
extern vector<Location *> location;
extern int year;
extern short mode;
extern bool mapshowing;
extern string closeParenthesis;
extern string tag_ARMOR;
// Sets the text color to the thematic color for the given alignment
// extended_range forces colors to be set on a 5 point scale instead
// of just basic liberal-moderate-conservative
void set_alignment_color(short alignment, bool extended_range)
{
	switch (alignment)
	{
	case ALIGN_ARCHCONSERVATIVE:
		set_color(COLOR_RED, COLOR_BLACK, 1);
		break;
	case ALIGN_CONSERVATIVE:
		if (extended_range)
			set_color(COLOR_MAGENTA, COLOR_BLACK, 1);
		else set_color(COLOR_RED, COLOR_BLACK, 1);
		break;
	case ALIGN_MODERATE:
		set_color(COLOR_YELLOW, COLOR_BLACK, 1);
		break;
	case ALIGN_LIBERAL:
		if (extended_range)
			set_color(COLOR_CYAN, COLOR_BLACK, 1);
		else set_color(COLOR_GREEN, COLOR_BLACK, 1);
		break;
	case ALIGN_ELITELIBERAL:
		set_color(COLOR_GREEN, COLOR_BLACK, 1);
		break;
	case ALIGN_STALINIST:
		set_color(COLOR_RED, COLOR_BLACK, 1);
		break;
	default: // This should not happen! Set a strange color to indicate an error!
		set_color(COLOR_YELLOW, COLOR_RED, 1, 1); // blinking yellow on red background
		break;
	}
}
// Sets the text color per activity type
void set_activity_color(long activity_type)
{
	switch (activity_type)
	{
		// Liberal actvism
	case ACTIVITY_SLEEPER_LIBERAL:
	case ACTIVITY_TROUBLE:
	case ACTIVITY_GRAFFITI:
	case ACTIVITY_DOS_ATTACKS:
	case ACTIVITY_HACKING:
	case ACTIVITY_WRITE_LETTERS:
	case ACTIVITY_WRITE_GUARDIAN:
		set_color(COLOR_GREEN, COLOR_BLACK, 1);
		break;
		// Recruitment
	case ACTIVITY_RECRUITING:
		set_color(COLOR_GREEN, COLOR_BLACK, 0);
		break;
		// Less exciting liberal activities
	case ACTIVITY_SLEEPER_SPY:
	case ACTIVITY_COMMUNITYSERVICE:
	case ACTIVITY_POLLS:
		set_color(COLOR_BLUE, COLOR_BLACK, 1);
		break;
		// Stealing things
	case ACTIVITY_SLEEPER_STEAL:
	case ACTIVITY_WHEELCHAIR:
	case ACTIVITY_STEALCARS:
		set_color(COLOR_CYAN, COLOR_BLACK, 0);
		break;
		// Illegal fundraising
	case ACTIVITY_SLEEPER_EMBEZZLE:
	case ACTIVITY_SELL_DRUGS:
	case ACTIVITY_PROSTITUTION:
	case ACTIVITY_CCFRAUD:
	case ACTIVITY_DOS_RACKET:
		set_color(COLOR_RED, COLOR_BLACK, 1);
		break;
		// Legal fundraising
	case ACTIVITY_DONATIONS:
	case ACTIVITY_SELL_TSHIRTS:
	case ACTIVITY_SELL_ART:
	case ACTIVITY_SELL_MUSIC:
		set_color(COLOR_CYAN, COLOR_BLACK, 1);
		break;
		// Clothing/garment stuff
	case ACTIVITY_REPAIR_ARMOR:
	case ACTIVITY_MAKE_ARMOR:
		set_color(COLOR_CYAN, COLOR_BLACK, 0);
		break;
		// Teaching
	case ACTIVITY_TEACH_POLITICS:
	case ACTIVITY_TEACH_FIGHTING:
	case ACTIVITY_TEACH_COVERT:
		//and studying
	case ACTIVITY_STUDY_DEBATING:
	case ACTIVITY_STUDY_MARTIAL_ARTS:
	case ACTIVITY_STUDY_DRIVING:
	case ACTIVITY_STUDY_PSYCHOLOGY:
	case ACTIVITY_STUDY_FIRST_AID:
	case ACTIVITY_STUDY_LAW:
	case ACTIVITY_STUDY_DISGUISE:
	case ACTIVITY_STUDY_SCIENCE:
	case ACTIVITY_STUDY_BUSINESS:
		//case ACTIVITY_STUDY_COOKING:
	case ACTIVITY_STUDY_GYMNASTICS:
	case ACTIVITY_STUDY_ART:
	case ACTIVITY_STUDY_MUSIC:
	case ACTIVITY_STUDY_TEACHING:
	case ACTIVITY_STUDY_WRITING:
	case ACTIVITY_STUDY_LOCKSMITHING:
	case ACTIVITY_STUDY_COMPUTERS:
		set_color(COLOR_MAGENTA, COLOR_BLACK, 1);
		break;
		// Interrogating
	case ACTIVITY_HOSTAGETENDING:
		set_color(COLOR_YELLOW, COLOR_BLACK, 1);
		break;
		// Dealing with your injuries
	case ACTIVITY_CLINIC:
		set_color(COLOR_RED, COLOR_BLACK, 0);
		break;
		// Doing something Conservative
	case ACTIVITY_SLEEPER_CONSERVATIVE:
		set_color(COLOR_RED, COLOR_BLACK, 1);
		break;
		// Dealing with the dead
	case ACTIVITY_BURY:
		set_color(COLOR_BLACK, COLOR_BLACK, 1);
		break;
		// Nothing terribly important
	case ACTIVITY_HEAL: // Identical to none in practice
	case ACTIVITY_NONE:
		set_color(COLOR_WHITE, COLOR_BLACK, 0);
		break;
		// Going somewhere
	case ACTIVITY_VISIT:
		set_color(COLOR_YELLOW, COLOR_BLACK, 1);
		break;
		// Quitting being a sleeper to join the LCS
	case ACTIVITY_SLEEPER_JOINLCS:
		set_color(COLOR_RED, COLOR_BLACK, 1);
		break;
	case ACTIVITY_AUGMENT:
		set_color(COLOR_BLUE, COLOR_BLACK, 1);
		break;
	default: // This should not happen! Set a strange color to indicate an error!
		set_color(COLOR_YELLOW, COLOR_RED, 1); // yellow on red background
		break;
	}
}
/* location and squad header */
void locheader()
{
	if (activesquad != NULL && activesquad->squad[0]->location != -1)
	{
		if (location[activesquad->squad[0]->location]->siege.siege)
		{
			if (location[activesquad->squad[0]->location]->siege.underattack)set_color(COLOR_RED, COLOR_BLACK, 1);
			else set_color(COLOR_YELLOW, COLOR_BLACK, 1);
		}
		else set_color(COLOR_WHITE, COLOR_BLACK, 0);
	}
	else if (selectedsiege != -1)
	{
		if (location[selectedsiege]->siege.siege)
		{
			if (location[selectedsiege]->siege.underattack)set_color(COLOR_RED, COLOR_BLACK, 1);
			else set_color(COLOR_YELLOW, COLOR_BLACK, 1);
		}
		else set_color(COLOR_WHITE, COLOR_BLACK, 0);
	}
	else set_color(COLOR_WHITE, COLOR_BLACK, 0);
	moveZeroZero();
	if (activesquad != NULL && activesquad->squad[0]->location != -1)
	{
		addstrAlt(location[activesquad->squad[0]->location]->getname(false, true));
		addstrAlt(commaSpace);
	}
	else
	{
		if (selectedsiege == -1)
		{
			addstrAlt("No Squad Selected");
			addstrAlt(commaSpace);
		}
		else
		{
			addstrAlt(location[selectedsiege]->getname(false, true));
			addstrAlt(commaSpace);
		}
	}
	addstrAlt(getmonth(month, true));
	addstrAlt(singleSpace);
	addstrAlt(day);
	addstrAlt(commaSpace);
	addstrAlt(year);
	if (activesquad == NULL && selectedsiege == -1)
	{
		set_color(COLOR_BLACK, COLOR_BLACK, 1);
		moveAlt(3, 6);
		addstrAlt("To form a new squad:");
		moveAlt(4, 6);
		addstrAlt("1) R - Review Assets and Form Squads");
		moveAlt(5, 6);
		addstrAlt("2) Press Z to Assemble a New Squad");
		set_color(COLOR_WHITE, COLOR_BLACK, 0);
	}
	printfunds();
	if (activesquad != NULL)
	{
		string str = getactivity(activesquad->activity);
		set_activity_color(activesquad->activity.type);
		if (activesquad->activity.type == ACTIVITY_NONE)
		{
			bool haveact = false, multipleact = false;
			for (int p = 0; p<6; p++)
			{
				if (activesquad->squad[p] == NULL) continue;
				const string str2 = getactivity(activesquad->squad[p]->activity);
				set_activity_color(activesquad->squad[p]->activity.type);
				if (haveact&&str != str2) multipleact = true;
				str = str2, haveact = true;
			}
			if (multipleact)
			{
				str = "Acting Individually";
				set_color(COLOR_WHITE, COLOR_BLACK, 1);
			}
		}
		mvaddstrAlt(0, 41, str);
	}
}
/* party info at top of screen */
void printparty()
{
	Creature *party[6] = { NULL,NULL,NULL,NULL,NULL,NULL };
	if (activesquad != NULL)
		for (int p = 0; p<6; p++)party[p] = activesquad->squad[p];
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
	for (int i = 2; i<8; i++)
	{
		moveAlt(i, 0);
		addstrAlt("                                                                                "); // 80 spaces
	}
	if (party_status != -1 && party[party_status] == NULL)party_status = -1;
	if (party_status != -1)
	{
		printcreatureinfo(party[party_status]);
		set_color(COLOR_WHITE, COLOR_BLACK, 1);
		moveAlt(1, 0);
		addstrAlt(party_status + 1);
	}
	else
	{
		char str[200];
		moveAlt(1, 0);
		addstrAlt("#ÄCODE NAMEÄÄÄÄÄÄÄÄÄÄÄÄSKILLÄÄÄWEAPONÄÄÄÄÄÄÄÄÄARMORÄÄÄÄÄÄÄÄÄÄHEALTHÄÄÄTRANSPORTÄ"); // 80 characters
		for (int p = 0; p<6; p++)
		{
			set_color(COLOR_WHITE, COLOR_BLACK, 0);
			moveAlt(p + 2, 0);
			addstrAlt("                                                                                "); // 80 spaces
			mvaddcharAlt(p + 2, 0, '1' + p);
			if (party[p] != NULL)
			{
				if (party[p]->prisoner != NULL)set_color(COLOR_MAGENTA, COLOR_BLACK, 1);
				else set_color(COLOR_WHITE, COLOR_BLACK, 0);
				moveAlt(p + 2, 2);
				addstrAlt(party[p]->name);
				if (party[p]->prisoner != NULL)addstrAlt("+H");
				int skill = 0;
				char bright = 0;
				for (int sk = 0; sk<SKILLNUM; sk++)
				{
					skill += (int)party[p]->get_skill(sk);
					if (party[p]->get_skill_ip(sk) >= 100 + (10 * party[p]->get_skill(sk)) &&
						party[p]->get_skill(sk)<party[p]->skill_cap(sk, true))bright = 1;
				}
				set_color(COLOR_WHITE, COLOR_BLACK, bright);
				moveAlt(p + 2, 23);
				addstrAlt(skill);
				addstrAlt("/");
				addstrAlt(party[p]->get_weapon_skill());
				moveAlt(p + 2, 31);
				if (mode != GAMEMODE_SITE)set_color(COLOR_WHITE, COLOR_BLACK, 0);
				else switch (weaponcheck(*party[p]))
				{
				case -1:
				case 0:set_color(COLOR_GREEN, COLOR_BLACK, 1); break;
				case 1:set_color(COLOR_YELLOW, COLOR_BLACK, 1); break;
				case 2:set_color(COLOR_RED, COLOR_BLACK, 1); break;
				}
				if (party[p]->has_thrown_weapon && len(party[p]->extra_throwing_weapons))
					addstrAlt(party[p]->extra_throwing_weapons[0]->get_shortname(0));
				else addstrAlt(party[p]->get_weapon().get_shortname(0));
				//set_color(COLOR_WHITE,COLOR_BLACK,0);
				if (party[p]->get_weapon().get_ammoamount()>0)
				{
					//set_color(COLOR_WHITE,COLOR_BLACK,0);
					addstrAlt(" (");
					addstrAlt(party[p]->get_weapon().get_ammoamount());
					addstrAlt(closeParenthesis);
				}
				else if (party[p]->get_weapon().uses_ammo())
				{
					set_color(COLOR_BLACK, COLOR_BLACK, 1);
					if (len(party[p]->clips))
					{
						addstrAlt(" (");
						addstrAlt(party[p]->count_clips());
						addstrAlt(closeParenthesis);
					}
					else
						addstrAlt(" (XX)");
				}
				else if (party[p]->get_weapon().is_throwable() && !party[p]->has_thrown_weapon)
					addstrAlt(" (1)");
				else if (party[p]->has_thrown_weapon && len(party[p]->extra_throwing_weapons))
				{
					set_color(COLOR_BLACK, COLOR_BLACK, 1);
					addstrAlt(" (");
					addstrAlt(party[p]->count_weapons() - party[p]->is_armed());
					addstrAlt(closeParenthesis);
				}
				if (mode != GAMEMODE_SITE)
				{
					int fg = COLOR_WHITE;
					int bg = COLOR_BLACK;
					int in = 1;
					if (party[p]->get_armor().is_bloody())
					{
						bg = COLOR_RED;  in = 1;
					}
					if (party[p]->get_armor().get_quality() > party[p]->get_armor().get_quality_levels())
					{
						fg = COLOR_BLACK;
					}
					else if (party[p]->get_armor().is_damaged())
					{
						fg = COLOR_YELLOW; in = 1;
					}
					else if (party[p]->get_armor().get_quality() >1)
					{
						fg = COLOR_YELLOW; in = (bg == COLOR_RED);
					}
					if (fg == COLOR_WHITE && bg == COLOR_BLACK)
						in = 0;
					set_color(fg, bg, in);
				}
				else
				{
					switch (hasdisguise(*party[p]))
					{
					case 1:set_color(COLOR_GREEN, COLOR_BLACK, 1); break;
					case 2:set_color(COLOR_YELLOW, COLOR_BLACK, 1); break;
					default:
						if (party[p]->get_armor().get_stealth_value() > 1)
							set_color(COLOR_BLACK, COLOR_BLACK, 1);
						else set_color(COLOR_RED, COLOR_BLACK, 1);
						break;
					}
					if (sitealarmtimer >= 0 || sitealarm == 1)
						if (party[p]->get_armor().get_stealth_value() > 1)
							set_color(COLOR_BLACK, COLOR_BLACK, 1);
				}
				mvaddstrAlt(p + 2, 46, party[p]->get_armor().get_shortname());
				printhealthstat(*party[p], p + 2, 61, TRUE);
				set_color(COLOR_WHITE, COLOR_BLACK, 0);
				moveAlt(p + 2, 70);
				long v = -1;
				if (showcarprefs == 1)v = id_getcar(party[p]->pref_carid);
				else v = id_getcar(party[p]->carid);
				if (v != -1 && showcarprefs != -1)
				{
					strcpy(str, vehicle[v]->shortname());
					if (showcarprefs == 1 ? party[p]->pref_is_driver : party[p]->is_driver)strcat(str, "-D");
				}
				else
				{
					int legok = 2;
					if ((party[p]->wound[BODYPART_LEG_RIGHT] & WOUND_NASTYOFF) ||
						(party[p]->wound[BODYPART_LEG_RIGHT] & WOUND_CLEANOFF))legok--;
					if ((party[p]->wound[BODYPART_LEG_LEFT] & WOUND_NASTYOFF) ||
						(party[p]->wound[BODYPART_LEG_LEFT] & WOUND_CLEANOFF))legok--;
					if (party[p]->flag & CREATUREFLAG_WHEELCHAIR)strcpy(str, "Wheelchair");
					else if (legok >= 1)strcpy(str, "On Foot");
					else strcpy(str, "On \"Foot\"");
				}
				addstrAlt(str);
			}
		}
	}
	makedelimiter();
}
/* location info at top of screen */
void printlocation(long loc)
{
	if (location[loc]->siege.siege)
	{
		if (!location[loc]->siege.underattack)
		{
			set_color(COLOR_YELLOW, COLOR_BLACK, 1);
			mvaddstrAlt(2, 1, "The police have surrounded this location.");
		}
		else
		{
			set_color(COLOR_RED, COLOR_BLACK, 1);
			switch (location[loc]->siege.siegetype)
			{
			case SIEGE_POLICE:
				mvaddstrAlt(2, 1, "The police are raiding this location!"); break;
			case SIEGE_CIA:
				mvaddstrAlt(2, 1, "The CIA is raiding this location!"); break;
			case SIEGE_HICKS:
				mvaddstrAlt(2, 1, "The masses are storming this location!"); break;
			case SIEGE_CORPORATE:
				mvaddstrAlt(2, 1, "The Corporations are raiding this location!"); break;
			case SIEGE_CCS:
				mvaddstrAlt(2, 1, "The CCS is raiding this location!"); break;
			case SIEGE_FIREMEN:
				mvaddstrAlt(2, 1, "Firemen are raiding this location!"); break;
			}
		}
	}
	else
	{
		set_color(COLOR_WHITE, COLOR_BLACK, 0);
		mvaddstrAlt(2, 1, "You are not under siege...  yet.");
	}
	if (location[loc]->can_be_upgraded())
	{
		if (numbereating(loc)>0)
		{
			if (fooddaysleft(loc))
			{
				if (fooddaysleft(loc)<4)
				{
					if (!location[loc]->siege.siege)set_color(COLOR_WHITE, COLOR_BLACK, 0);
					else set_color(COLOR_YELLOW, COLOR_BLACK, 1);
					mvaddstrAlt(3, 1, "This location has food for only a few days.");
				}
			}
			else
			{
				if (!location[loc]->siege.siege)set_color(COLOR_WHITE, COLOR_BLACK, 0);
				else set_color(COLOR_RED, COLOR_BLACK, 1);
				mvaddstrAlt(3, 1, "This location has insufficient food stores.");
			}
		}
		if (location[loc]->compound_walls & COMPOUND_BASIC)
		{
			set_color(COLOR_WHITE, COLOR_BLACK, 1);
			mvaddstrAlt(4, 1, "FORTIFIED COMPOUND");
		}
		if (location[loc]->compound_walls & COMPOUND_PRINTINGPRESS)
		{
			set_color(COLOR_BLUE, COLOR_BLACK, 1);
			mvaddstrAlt(4, 31, "PRINTING PRESS");
		}
		if (location[loc]->front_business != -1)
		{
			set_color(COLOR_MAGENTA, COLOR_BLACK, 1);
			mvaddstrAlt(4, 54, "BUSINESS FRONT");
		}
		if (location[loc]->compound_walls & COMPOUND_CAMERAS)
		{
			if (location[loc]->siege.siege&&location[loc]->siege.cameras_off)
			{
				set_color(COLOR_RED, COLOR_BLACK, 0);
				mvaddstrAlt(5, 1, "CAMERAS OFF");
			}
			else
			{
				set_color(COLOR_GREEN, COLOR_BLACK, 1);
				mvaddstrAlt(5, 1, "CAMERAS ON");
			}
		}
		if (location[loc]->compound_walls & COMPOUND_TRAPS)
		{
			set_color(COLOR_RED, COLOR_BLACK, 1);
			mvaddstrAlt(5, 16, "BOOBY TRAPS");
		}
		if (location[loc]->compound_walls & COMPOUND_AAGUN)
		{
			set_color(COLOR_CYAN, COLOR_BLACK, 1);
			mvaddstrAlt(5, 33, "AA GUN");
		}
		if (location[loc]->compound_walls & COMPOUND_TANKTRAPS)
		{
			set_color(COLOR_YELLOW, COLOR_BLACK, 1);
			mvaddstrAlt(5, 46, "TANK TRAPS");
		}
		if (location[loc]->siege.siege&&location[loc]->siege.lights_off)
		{
			set_color(COLOR_WHITE, COLOR_BLACK, 0);
			mvaddstrAlt(5, 60, "LIGHTS OUT");
		}
		else if (location[loc]->compound_walls & COMPOUND_GENERATOR)
		{
			set_color(COLOR_WHITE, COLOR_BLACK, 1);
			mvaddstrAlt(5, 61, "GENERATOR");
		}
		int eaters = numbereating(loc), days = fooddaysleft(loc);
		if (eaters>0)
		{
			if (days >= 1)
			{
				set_color(COLOR_WHITE, COLOR_BLACK, 0);
				mvaddstrAlt(6, 50, days);
				addstrAlt(" Day");
				if (days != 1)addcharAlt('s');
				addstrAlt(" of Food Left");
			}
			else if (days == 0)
			{
				set_color(COLOR_RED, COLOR_BLACK, 0);
				mvaddstrAlt(6, 50, "Not Enough Food");
			}
		}
		set_color(COLOR_WHITE, COLOR_BLACK, 0);
		mvaddstrAlt(6, 1, location[loc]->compound_stores);
		addstrAlt(" Daily Ration");
		if (location[loc]->compound_stores != 1)addstrAlt("s");
		set_color(COLOR_WHITE, COLOR_BLACK, 0);
		mvaddstrAlt(6, 30, eaters);
		addstrAlt(" Eating");
	}
}
/* character info at top of screen */
void printcreatureinfo(Creature *cr, unsigned char knowledge)
{
	char str[200];
	makedelimiter(1);
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
	mvaddstrAlt(1, 2, cr->name);
	addstrAlt(commaSpace);
	addstrAlt(gettitle(*cr));
	if (cr->prisoner != NULL)
	{
		addstrAlt(", holding ");
		switch (cr->prisoner->type)
		{
		case CREATURE_POLITICIAN:addstrAlt("a cursing Politician"); break;
		case CREATURE_CORPORATE_CEO:addstrAlt("a squirming CEO"); break;
		case CREATURE_RADIOPERSONALITY:addstrAlt("a crying Radio Personality"); break;
		case CREATURE_NEWSANCHOR:addstrAlt("a smarmy News Anchor"); break;
		case CREATURE_SCIENTIST_EMINENT:addstrAlt("a frightened Eminent Scientist"); break;
		case CREATURE_JUDGE_CONSERVATIVE:addstrAlt("an angry Hangin' Judge"); break;
		default:
			addstrAlt(cr->prisoner->name);
			break;
		}
	}
	mvaddstrAlt(2, 0, "Hrt:    ");
	if (knowledge>0)
		addstrAlt(cr->get_attribute(ATTRIBUTE_HEART, true));
	else addstrAlt("?");
	mvaddstrAlt(3, 0, "Int:    ");
	if (knowledge>0)
		addstrAlt(cr->get_attribute(ATTRIBUTE_INTELLIGENCE, true));
	else addstrAlt("?");
	mvaddstrAlt(4, 0, "Wis:    ");
	if (knowledge>0)
		addstrAlt(cr->get_attribute(ATTRIBUTE_WISDOM, true));
	else addstrAlt("?");
	mvaddstrAlt(5, 0, "Hlth:   ");
	if (knowledge>1)
		addstrAlt(cr->get_attribute(ATTRIBUTE_HEALTH, true));
	else addstrAlt("?");
	mvaddstrAlt(2, 11, "Agi:    ");
	if (knowledge>1)
		addstrAlt(cr->get_attribute(ATTRIBUTE_AGILITY, true));
	else addstrAlt("?");
	mvaddstrAlt(3, 11, "Str:    ");
	if (knowledge>1)
		addstrAlt(cr->get_attribute(ATTRIBUTE_STRENGTH, true));
	else addstrAlt("?");
	mvaddstrAlt(4, 11, "Char:   ");
	if (knowledge>0)
		addstrAlt(cr->get_attribute(ATTRIBUTE_CHARISMA, true));
	else addstrAlt("?");
	mvaddstrAlt(5, 11, "Trans: ");
	long v = -1;
	if (showcarprefs == 1)v = id_getcar(cr->pref_carid);
	else v = id_getcar(cr->carid);
	if (v != -1 && showcarprefs != -1)
	{
		strcpy(str, vehicle[v]->shortname());
		char d;
		if (showcarprefs == 1)d = cr->pref_is_driver;
		else d = cr->is_driver;
		if (d)strcat(str, "-D");
	}
	else
	{
		int legok = 2;
		if ((cr->wound[BODYPART_LEG_RIGHT] & WOUND_NASTYOFF) ||
			(cr->wound[BODYPART_LEG_RIGHT] & WOUND_CLEANOFF))legok--;
		if ((cr->wound[BODYPART_LEG_LEFT] & WOUND_NASTYOFF) ||
			(cr->wound[BODYPART_LEG_LEFT] & WOUND_CLEANOFF))legok--;
		if (cr->flag & CREATUREFLAG_WHEELCHAIR)strcpy(str, "Wheelchair");
		else if (legok >= 1)strcpy(str, "On Foot");
		else strcpy(str, "On \"Foot\"");
	}
	addstrAlt(str);
	moveAlt(6, 0);
	if (mode != GAMEMODE_SITE) set_color(COLOR_WHITE, COLOR_BLACK, 0);
	else switch (weaponcheck(*cr))
	{
	case -1:
	case 0:set_color(COLOR_GREEN, COLOR_BLACK, 1); break;
	case 1:set_color(COLOR_YELLOW, COLOR_BLACK, 1); break;
	case 2:set_color(COLOR_RED, COLOR_BLACK, 1); break;
	}
	addstrAlt("Weapon: ");
	addstrAlt(cr->get_weapon_string(1));
	moveAlt(7, 0);
	if (mode != GAMEMODE_SITE)
	{
		int fg = COLOR_WHITE;
		int bg = COLOR_BLACK;
		int in = 1;
		if (cr->get_armor().is_bloody())
		{
			bg = COLOR_RED;  in = 0;
		}
		if (cr->get_armor().get_quality() > cr->get_armor().get_quality_levels())
		{
			fg = COLOR_BLACK;
		}
		else if (cr->get_armor().is_damaged())
		{
			fg = COLOR_YELLOW; in = 1;
		}
		else if (cr->get_armor().get_quality() >1)
		{
			fg = COLOR_YELLOW; in = (bg == COLOR_RED);
		}
		if (fg == COLOR_WHITE && bg == COLOR_BLACK)
			in = 0;
		set_color(fg, bg, in);
	}
	else
	{
		switch (hasdisguise(*cr))
		{
		case 1:set_color(COLOR_GREEN, COLOR_BLACK, 1); break;
		case 2:set_color(COLOR_YELLOW, COLOR_BLACK, 1); break;
		default:
			if (cr->get_armor().get_stealth_value() > 1)
				set_color(COLOR_BLACK, COLOR_BLACK, 1);
			else set_color(COLOR_RED, COLOR_BLACK, 1);
		}
		if (sitealarmtimer >= 0 || sitealarm == 1)
			if (cr->get_armor().get_stealth_value() > 1)
				set_color(COLOR_BLACK, COLOR_BLACK, 1);
	}
	addstrAlt("Clothes: ");
	addstrAlt(cr->get_armor_string(false));
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
	char used[SKILLNUM];
	memset(used, 0, sizeof(char)*SKILLNUM);
	int snum = 5;
	char printed = 1;
	while (snum>0 && printed)
	{
		printed = 0;
		int max = 0;
		long maxs = -1;
		for (int s = 0; s<SKILLNUM; s++)
		{
			if ((cr->get_skill(s) * 10000 + cr->get_skill_ip(s))>max && !used[s])
			{
				max = (cr->get_skill(s) * 10000 + cr->get_skill_ip(s));
				maxs = s;
			}
		}
		if (maxs != -1)
		{
			used[maxs] = 1;
			printed = 1;
			// Maxed skills are cyan
			if (cr->skill_cap(maxs, true) != 0 && cr->get_skill(maxs) >= cr->skill_cap(maxs, true))set_color(COLOR_CYAN, COLOR_BLACK, 1);
			// About to level up skills are white
			else if (cr->get_skill_ip(maxs) >= 100 + (10 * cr->get_skill(maxs)) &&
				cr->get_skill(maxs)<cr->skill_cap(maxs, true))set_color(COLOR_WHITE, COLOR_BLACK, 1);
			// <1 skills are dark gray
			else if (cr->get_skill(maxs)<1)set_color(COLOR_BLACK, COLOR_BLACK, 1);
			// >=1 skills are light gray
			else set_color(COLOR_WHITE, COLOR_BLACK, 0);
			moveAlt(3 + 5 - snum, 31);
			if (knowledge>5 - snum)
				addstrAlt(Skill::get_name(maxs));
			else addstrAlt("???????");
			addstrAlt(": ");
			if (knowledge>7 - snum)
				addstrAlt(cr->get_skill(maxs));
			else addcharAlt('?');
			if (snum == 5 && printed)
			{
				set_color(COLOR_WHITE, COLOR_BLACK, 0);
				moveAlt(2, 31);
				addstrAlt("Top Skills:");
			}
		}
		snum--;
	}
	int woundsum = 0;
	for (int w = 0; w<BODYPARTNUM; w++)
		if (cr->wound[w] != 0)woundsum++;
	printhealthstat(*cr, 1, 49, FALSE);
	if (woundsum>0)
	{
		for (int w = 0; w<BODYPARTNUM; w++)
		{
			if (cr->wound[w] & WOUND_BLEEDING)set_color(COLOR_RED, COLOR_BLACK, 1);
			else set_color(COLOR_WHITE, COLOR_BLACK, 0);
			moveAlt(2 + w, 49);
			switch (w)
			{
			case BODYPART_HEAD:addstrAlt("Head:"); break;
			case BODYPART_BODY:addstrAlt("Body:"); break;
			case BODYPART_ARM_RIGHT:addstrAlt("Right Arm:"); break;
			case BODYPART_ARM_LEFT:addstrAlt("Left Arm:"); break;
			case BODYPART_LEG_RIGHT:addstrAlt("Right Leg:"); break;
			case BODYPART_LEG_LEFT:addstrAlt("Left Leg:"); break;
			}
			moveAlt(2 + w, 61);
			if (cr->wound[w] & WOUND_NASTYOFF)addstrAlt("Ripped off");
			else if (cr->wound[w] & WOUND_CLEANOFF)addstrAlt("Clean sever");
			else
			{
				int sum = 0;
				if (cr->wound[w] & WOUND_SHOT)sum++;
				if (cr->wound[w] & WOUND_CUT)sum++;
				if (cr->wound[w] & WOUND_BRUISED)sum++;
				if (cr->wound[w] & WOUND_BURNED)sum++;
				if (cr->wound[w] & WOUND_TORN)sum++;
				if (sum == 0)
				{
					set_color(COLOR_GREEN, COLOR_BLACK, 1);
					if (cr->animalgloss == ANIMALGLOSS_ANIMAL)
						addstrAlt("Animal");
					else addstrAlt("Liberal");
				}
				if (cr->wound[w] & WOUND_SHOT) { addstrAlt("Sht"); sum--; if (sum>0)addstrAlt(","); }
				if (cr->wound[w] & WOUND_BRUISED) { addstrAlt("Brs"); sum--; if (sum>0)addstrAlt(","); }
				if (cr->wound[w] & WOUND_CUT) { addstrAlt("Cut"); sum--; if (sum>0)addstrAlt(","); }
				if (cr->wound[w] & WOUND_TORN) { addstrAlt("Trn"); sum--; if (sum>0)addstrAlt(","); }
				if (cr->wound[w] & WOUND_BURNED) { addstrAlt("Brn"); sum--; if (sum>0)addstrAlt(","); }
			}
		}
		set_color(COLOR_WHITE, COLOR_BLACK, 0);
	}
}
/* full character sheet (with surrounding interface) */
void fullstatus(int p)
{
	if (activesquad == NULL)return;
	const int pagenum = 3;
	int page = 0;
	while (true)
	{
		eraseAlt();
		set_color(COLOR_GREEN, COLOR_BLACK, 1);
		moveZeroZero();
		addstrAlt("Profile of a Liberal");
		if (page == 0) printliberalstats(*activesquad->squad[p]);
		else if (page == 1) printliberalskills(*activesquad->squad[p]);
		else if (page == 2) printliberalcrimes(*activesquad->squad[p]);
		moveAlt(23, 0);
		addstrAlt("N - Change Code Name      G - Fix Gender Label");
		if (activesquad->squad[1] != NULL)
			addstrAlt("    LEFT/RIGHT - Other Liberals");
		moveAlt(24, 0);
		addstrAlt("Press any other key to continue the Struggle");
		addstrAlt("    UP/DOWN  - More Info");
		int c = getkey();
		if (activesquad->squad[1] != NULL && ((c == KEY_LEFT) || (c == KEY_RIGHT)))
		{
			int sx = (c == KEY_LEFT) ? -1 : 1;
			do p = (p + 6 + sx) % 6; while (activesquad->squad[p] == NULL);
		}
		else if (c == KEY_DOWN)
		{
			page++;
			page %= pagenum;
		}
		else if (c == KEY_UP)
		{
			page--;
			if (page<0) page = pagenum - 1;
			page %= pagenum;
		}
		else if (c == 'n')
		{
			set_color(COLOR_WHITE, COLOR_BLACK, 0);
			mvaddstrAlt(23, 0, "What is the new code name?                                                      "); // 80 characters
			mvaddstrAlt(24, 0, "                                                                                "); // 80 spaces
			enter_name(24, 0, activesquad->squad[p]->name, CREATURE_NAMELEN, activesquad->squad[p]->propername);
		}
		else if (c == 'g')
		{
			activesquad->squad[p]->gender_liberal++;
			if (activesquad->squad[p]->gender_liberal>2)
				activesquad->squad[p]->gender_liberal = 0;
		}
		else break;
	}
}
/* Full screen character sheet, skills only edition */
void printliberalskills(Creature &cr)
{
	// Add name
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
	moveAlt(2, 0);
	if (strcmp(cr.propername, cr.name) != 0)
		addstrAlt("Code name: ");
	else addstrAlt("Name: ");
	set_color(COLOR_WHITE, COLOR_BLACK, 1);
	addstrAlt(cr.name);
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
	addstrAlt(commaSpace);
	addstrAlt(gettitle(cr));
	addstrAlt(" (");
	addstrAlt(cr.get_type_name());
	addstrAlt(closeParenthesis);
	// Add all skills
	for (int s = 0; s<SKILLNUM; s++)
	{
		if (s % 3 == 0 && s<9)
		{
			set_color(COLOR_WHITE, COLOR_BLACK, 0);
			moveAlt(4, 27 * (s / 3));
			addstrAlt("SKILL");
			moveAlt(4, 15 + 27 * (s / 3));
			addstrAlt("NOW   MAX");
		}
		// Maxed skills are cyan
		if (cr.skill_cap(s, true) != 0 && cr.get_skill(s) >= cr.skill_cap(s, true))set_color(COLOR_CYAN, COLOR_BLACK, 1);
		// About to level up skills are white
		else if (cr.get_skill_ip(s) >= 100 + (10 * cr.get_skill(s)) &&
			cr.get_skill(s)<cr.skill_cap(s, true))set_color(COLOR_WHITE, COLOR_BLACK, 1);
		// <1 skills are dark gray
		else if (cr.get_skill(s)<1)set_color(COLOR_BLACK, COLOR_BLACK, 1);
		// >=1 skills are light gray
		else set_color(COLOR_WHITE, COLOR_BLACK, 0);
		moveAlt(5 + s / 3, 27 * (s % 3));
		addstrAlt(Skill::get_name(s));
		addstrAlt(": ");
		moveAlt(5 + s / 3, 14 + 27 * (s % 3));
		addstr_f("%2d.", cr.get_skill(s));
		if (cr.get_skill_ip(s)<100 + (10 * cr.get_skill(s)))
		{
			if ((cr.get_skill_ip(s) * 100) / (100 + (10 * cr.get_skill(s))) != 0)
			{
				if ((cr.get_skill_ip(s) * 100) / (100 + (10 * cr.get_skill(s)))<10)
					addstrAlt("0");
				addstrAlt((cr.get_skill_ip(s) * 100) / (100 + (10 * cr.get_skill(s))));
			}
			else addstrAlt("00");
		}
		else addstrAlt("99+");
		if (cr.skill_cap(s, true) == 0 || cr.get_skill(s)<cr.skill_cap(s, true))
			set_color(COLOR_BLACK, COLOR_BLACK, 1);
		moveAlt(5 + s / 3, 20 + 27 * (s % 3));
		addstr_f("%2d.00", cr.skill_cap(s, true));
	}
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
}
/* full screen character sheet */
void printliberalstats(Creature &cr)
{
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
	// Add name
	moveAlt(2, 0);
	addstrAlt("Name: ");
	set_color(COLOR_WHITE, COLOR_BLACK, 1);
	addstrAlt(cr.name);
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
	if (strcmp(cr.propername, cr.name) != 0)
	{
		//The names do not match, print real name as well
		addstrAlt(" (");
		addstrAlt(cr.propername);
		addstrAlt(closeParenthesis);
	}
	addstrAlt(commaSpace);
	addstrAlt(gettitle(cr));
	addstrAlt(" (");
	addstrAlt(cr.get_type_name());
	addstrAlt(closeParenthesis);
	moveAlt(3, 0);
	// Add birthdate
	addstrAlt("Born ");
	addstrAlt(getmonth(cr.birthday_month));
	addstrAlt(singleSpace);
	addstrAlt(cr.birthday_day);
	addstrAlt(commaSpace);
	if (cr.birthday_month < month ||
		(cr.birthday_month == month && cr.birthday_day <= day))
		addstrAlt(year - cr.age);
	else addstrAlt(year - 1 - cr.age);
	// Add age
	addstrAlt(" (Age ");
	addstrAlt(cr.age);
	// Assess their gender in an Elite Liberal way
	if (cr.gender_liberal == GENDER_MALE)
		addstrAlt(", Male");
	else if (cr.gender_liberal == GENDER_FEMALE)
		addstrAlt(", Female");
	else addstrAlt(", Genderqueer");
	// DON'T Note if there's some conflict with Conservative society's perceptions
	//if(cr.gender_liberal != cr.gender_conservative && cr.gender_liberal != GENDER_NEUTRAL)
	//   addstrAlt("*");
	addstrAlt(closeParenthesis);
	moveAlt(3, 46);
	statebrokenlaws(cr);
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
	// Add juice
	moveAlt(10, 16);
	addstrAlt("Juice: ");
	addstrAlt(cr.juice);
	if (cr.juice<1000)
	{
		moveAlt(11, 16); addstrAlt("Next:  ");
		if (cr.juice<0)addstrAlt("0");
		else if (cr.juice<10)addstrAlt("10");
		else if (cr.juice<50)addstrAlt("50");
		else if (cr.juice<100)addstrAlt("100");
		else if (cr.juice<200)addstrAlt("200");
		else if (cr.juice<500)addstrAlt("500");
		else addstrAlt("1000");
	}
	// Add attributes
	moveAlt(5, 0); addstrAlt("Heart: ");
	addstrAlt(cr.get_attribute(ATTRIBUTE_HEART, true));
	moveAlt(6, 0); addstrAlt("Intelligence: ");
	addstrAlt(cr.get_attribute(ATTRIBUTE_INTELLIGENCE, true));
	moveAlt(7, 0); addstrAlt("Wisdom: ");
	addstrAlt(cr.get_attribute(ATTRIBUTE_WISDOM, true));
	moveAlt(8, 0); addstrAlt("Health: ");
	addstrAlt(cr.get_attribute(ATTRIBUTE_HEALTH, true));
	moveAlt(9, 0); addstrAlt("Agility: ");
	addstrAlt(cr.get_attribute(ATTRIBUTE_AGILITY, true));
	moveAlt(10, 0); addstrAlt("Strength: ");
	addstrAlt(cr.get_attribute(ATTRIBUTE_STRENGTH, true));
	moveAlt(11, 0); addstrAlt("Charisma: ");
	addstrAlt(cr.get_attribute(ATTRIBUTE_CHARISMA, true));
	// Add highest skills
	char used[SKILLNUM];
	memset(used, 0, sizeof(char)*SKILLNUM);
	int skills_max = 16;
	char printed = 1;
	moveAlt(5, 28);
	addstrAlt("SKILL");
	moveAlt(5, 43);
	addstrAlt("NOW   MAX");
	for (int skills_shown = 0; skills_shown<skills_max&&printed; skills_shown++)
	{
		printed = 0;
		int max = 0;
		long maxs = -1;
		for (int s = 0; s<SKILLNUM; s++)
		{
			if ((cr.get_skill(s) * 10000 + cr.get_skill_ip(s))>max && !used[s])
			{
				max = (cr.get_skill(s) * 10000 + cr.get_skill_ip(s));
				maxs = s;
			}
		}
		if (maxs != -1)
		{
			used[maxs] = 1;
			printed = 1;
			// Maxed skills are cyan
			if (cr.skill_cap(maxs, true) != 0 && cr.get_skill(maxs) >= cr.skill_cap(maxs, true))set_color(COLOR_CYAN, COLOR_BLACK, 1);
			// About to level up skills are white
			else if (cr.get_skill_ip(maxs) >= 100 + (10 * cr.get_skill(maxs)) &&
				cr.get_skill(maxs)<cr.skill_cap(maxs, true))set_color(COLOR_WHITE, COLOR_BLACK, 1);
			// <1 skills are dark gray
			else if (cr.get_skill(maxs)<1)set_color(COLOR_BLACK, COLOR_BLACK, 1);
			// >=1 skills are light gray
			else set_color(COLOR_WHITE, COLOR_BLACK, 0);
			moveAlt(6 + skills_shown, 28);
			addstrAlt(Skill::get_name(maxs));
			addstrAlt(": ");
			moveAlt(6 + skills_shown, 42);
			addstr_f("%2d.", cr.get_skill(maxs));
			if (cr.get_skill_ip(maxs)<100 + (10 * cr.get_skill(maxs)))
			{
				if ((cr.get_skill_ip(maxs) * 100) / (100 + (10 * cr.get_skill(maxs))) != 0)
				{
					if ((cr.get_skill_ip(maxs) * 100) / (100 + (10 * cr.get_skill(maxs)))<10)
						addcharAlt('0');
					addstrAlt((cr.get_skill_ip(maxs) * 100) / (100 + (10 * cr.get_skill(maxs))));
				}
				else addstrAlt("00");
			}
			else addstrAlt("99+");
			if (cr.skill_cap(maxs, true) == 0 || cr.get_skill(maxs)<cr.skill_cap(maxs, true))
				set_color(COLOR_BLACK, COLOR_BLACK, 1);
			moveAlt(6 + skills_shown, 48);
			addstr_f("%2d.00", cr.skill_cap(maxs, true));
		}
	}
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
	// Add weapon
	moveAlt(13, 0);
	addstrAlt("Weapon: ");
	addstrAlt(cr.get_weapon_string(0));
	// Add clothing
	moveAlt(14, 0);
	addstrAlt("Clothes: ");
	addstrAlt(cr.get_armor_string(true));
	// Add vehicle
	moveAlt(15, 0);
	addstrAlt("Car: ");
	long v = -1;
	if (showcarprefs == 1)v = id_getcar(cr.pref_carid);
	else v = id_getcar(cr.carid);
	if (v != -1 && showcarprefs != -1)
	{
		addstrAlt(vehicle[v]->shortname());
		char d;
		if (showcarprefs == 1)d = cr.pref_is_driver;
		else d = cr.is_driver;
		if (d)addstrAlt("-D");
	}
	else
	{
		int legok = 2;
		if ((cr.wound[BODYPART_LEG_RIGHT] & WOUND_NASTYOFF) ||
			(cr.wound[BODYPART_LEG_RIGHT] & WOUND_CLEANOFF))legok--;
		if ((cr.wound[BODYPART_LEG_LEFT] & WOUND_NASTYOFF) ||
			(cr.wound[BODYPART_LEG_LEFT] & WOUND_CLEANOFF))legok--;
		if (cr.flag & CREATUREFLAG_WHEELCHAIR)addstrAlt("Wheelchair");
		else if (legok >= 1)addstrAlt("On Foot");
		else addstrAlt("On \"Foot\"");
	}
	// Add recruit stats
	if (cr.flag != CREATUREFLAG_BRAINWASHED)
	{
		moveAlt(18, 55);
		addstrAlt(maxsubordinates(cr) - subordinatesleft(cr));
		addstrAlt(" Recruits / ");
		addstrAlt(maxsubordinates(cr));
		addstrAlt(" Max");
	}
	else
	{
		moveAlt(18, 55);
		addstrAlt("Enlightened ");
		addstrAlt("Can't Recruit");
	}
	// Any meetings with potential recruits scheduled?
	if (scheduledmeetings(cr))
	{
		moveAlt(20, 55);
		addstrAlt("Scheduled Meetings: ");
		addstrAlt(scheduledmeetings(cr));
	}
	// Add seduction stats
	moveAlt(19, 55);
	int lovers = loveslaves(cr);
	if (cr.flag & CREATUREFLAG_LOVESLAVE)
		lovers++;
	if (lovers)
	{
		addstrAlt(lovers);
		addstrAlt(" Romantic Interest");
		if (lovers>1)addstrAlt("s");
	}
	// Any dates with potential love interests scheduled?
	if (scheduleddates(cr))
	{
		moveAlt(21, 55);
		addstrAlt("Scheduled Dates:    ");
		addstrAlt(scheduleddates(cr));
	}
	printwoundstat(cr, 5, 55);
	//SPECIAL WOUNDS
	set_color(COLOR_RED, COLOR_BLACK, 0);
	int y = 17;
	int x = 0;
	if (cr.special[SPECIALWOUND_HEART] != 1)
	{
		moveAlt(y++, x);
		addstrAlt("Heart Punctured");
	}
	if (cr.special[SPECIALWOUND_RIGHTLUNG] != 1)
	{
		moveAlt(y++, x);
		addstrAlt("R. Lung Collapsed");
	}
	if (cr.special[SPECIALWOUND_LEFTLUNG] != 1)
	{
		moveAlt(y++, x);
		addstrAlt("L. Lung Collapsed");
	}
	if (cr.special[SPECIALWOUND_NECK] != 1)
	{
		moveAlt(y++, x);
		addstrAlt("Broken Neck");
	}
	if (cr.special[SPECIALWOUND_UPPERSPINE] != 1)
	{
		moveAlt(y++, x);
		addstrAlt("Broken Up Spine");
	}
	if (cr.special[SPECIALWOUND_LOWERSPINE] != 1)
	{
		moveAlt(y++, x);
		addstrAlt("Broken Lw Spine");
	}
	if (cr.special[SPECIALWOUND_RIGHTEYE] != 1)
	{
		moveAlt(y++, x);
		addstrAlt("No Right Eye");
	}
	if (cr.special[SPECIALWOUND_LEFTEYE] != 1)
	{
		moveAlt(y++, x);
		addstrAlt("No Left Eye");
	}
	if (cr.special[SPECIALWOUND_NOSE] != 1)
	{
		moveAlt(y++, x);
		addstrAlt("No Nose");
	}
	if (cr.special[SPECIALWOUND_TONGUE] != 1)
	{
		moveAlt(y++, x);
		addstrAlt("No Tongue");
	}
	if (cr.special[SPECIALWOUND_TEETH] != TOOTHNUM)
	{
		moveAlt(y++, x);
		if (cr.special[SPECIALWOUND_TEETH] == 0)addstrAlt("No Teeth");
		else if (cr.special[SPECIALWOUND_TEETH] == TOOTHNUM - 1)addstrAlt("Missing a Tooth");
		else if (cr.special[SPECIALWOUND_TEETH]<TOOTHNUM)addstrAlt("Missing Teeth");
	}
	if (cr.special[SPECIALWOUND_LIVER] != 1)
	{
		moveAlt(y++, x);
		addstrAlt("Liver Damaged");
	}
	if (cr.special[SPECIALWOUND_RIGHTKIDNEY] != 1)
	{
		moveAlt(y++, x);
		addstrAlt("R. Kidney Damaged");
	}
	if (cr.special[SPECIALWOUND_LEFTKIDNEY] != 1)
	{
		moveAlt(y++, x);
		addstrAlt("L. Kidney Damaged");
	}
	if (cr.special[SPECIALWOUND_STOMACH] != 1)
	{
		moveAlt(y++, x);
		addstrAlt("Stomach Injured");
	}
	if (cr.special[SPECIALWOUND_SPLEEN] != 1)
	{
		moveAlt(y++, x);
		addstrAlt("Busted Spleen");
	}
	if (cr.special[SPECIALWOUND_RIBS] != RIBNUM)
	{
		moveAlt(y++, x);
		if (cr.special[SPECIALWOUND_RIBS] == 0)addstrAlt("All Ribs Broken");
		else if (cr.special[SPECIALWOUND_RIBS] == RIBNUM - 1)addstrAlt("Broken Rib");
		else if (cr.special[SPECIALWOUND_RIBS]<RIBNUM)addstrAlt("Broken Ribs");
	}
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
	for (int i = 0, y = 12; i<AUGMENTATIONNUM; i++, y++)
	{
		if (cr.get_augmentation(i).type == -1) continue;
		mvaddstrAlt(y, 55, Augmentation::get_name(i));
		addstrAlt(": ");
		addstrAlt(cr.get_augmentation(i).name);
	}
}
/* Full screen character sheet, crime sheet */
void printliberalcrimes(Creature &cr)
{
	// Add name
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
	if (strcmp(cr.propername, cr.name) != 0)
		mvaddstrAlt(2, 0, "Code name: ");
	else mvaddstrAlt(2, 0, "Name: ");
	set_color(COLOR_WHITE, COLOR_BLACK, 1);
	addstrAlt(cr.name);
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
	addstrAlt(commaSpace);
	addstrAlt(gettitle(cr));
	addstrAlt(" (");
	addstrAlt(cr.get_type_name());
	addstrAlt(closeParenthesis);
	// Show outstanding convictions in addition to untried crimes
	if (cr.deathpenalty)
	{
		set_color(COLOR_RED, COLOR_BLACK, 1);
		if (location[cr.location]->type == SITE_GOVERNMENT_PRISON)
			mvaddstrAlt(3, 0, "On DEATH ROW");
		else mvaddstrAlt(3, 0, "Sentenced to DEATH");
	}
	else if (cr.sentence<0)
	{
		set_color(COLOR_RED, COLOR_BLACK, 1);
		if (location[cr.location]->type == SITE_GOVERNMENT_PRISON)
			mvaddstrAlt(3, 0, "Serving life in prison");
		else mvaddstrAlt(3, 0, "Sentenced to life in prison");
	}
	else if (cr.sentence>0)
	{
		set_color(COLOR_YELLOW, COLOR_BLACK, 1);
		if (location[cr.location]->type == SITE_GOVERNMENT_PRISON)
			mvaddstrAlt(3, 0, "Serving ");
		else mvaddstrAlt(3, 0, "Sentenced to ");
		addstrAlt(cr.sentence);
		addstrAlt(" months in prison.");
	}
	// Add all crimes
	for (int i = 0; i < LAWFLAGNUM; i++)
	{
		if (i % 2 == 0 && i<4)
		{
			set_color(COLOR_WHITE, COLOR_BLACK, 0);
			mvaddstrAlt(4, 40 * (i / 2), "CRIME");
			mvaddstrAlt(4, 30 + 40 * (i / 2), "NUM");
		}
		// Commited crimes are yellow
		if (cr.crimes_suspected[i] > 0)
			set_color(COLOR_YELLOW, COLOR_BLACK, 1);
		else set_color(COLOR_BLACK, COLOR_BLACK, 1);
		mvaddstrAlt(5 + i / 2, 40 * (i % 2), getlawflag(i) + ": ");
		mvaddstr_f(5 + i / 2, 30 + 40 * (i % 2), "%2d", cr.crimes_suspected[i]);
	}
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
}
/* draws a horizontal line across the screen */
void makedelimiter(int y, int x)
{
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
	if (mode == GAMEMODE_SITE&&y == 8 && x == 0 && mapshowing) // special case: there is a map on the right in site mode
		mvaddstrAlt(y, x, "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂ"); // 80 characters
	else // normal delimiter
		mvaddstrAlt(y, x, "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ"); // 80 characters
}
void printwoundstat(Creature &cr, int y, int x)
{
	// Add wound status
	for (int w = 0; w<BODYPARTNUM; w++)
	{
		if (cr.wound[w] & WOUND_BLEEDING)set_color(COLOR_RED, COLOR_BLACK, 1);
		else set_color(COLOR_WHITE, COLOR_BLACK, 0);
		moveAlt(y + w, x);
		switch (w)
		{
		case BODYPART_HEAD:addstrAlt("Head:"); break;
		case BODYPART_BODY:addstrAlt("Body:"); break;
		case BODYPART_ARM_RIGHT:addstrAlt("Right Arm:"); break;
		case BODYPART_ARM_LEFT:addstrAlt("Left Arm:"); break;
		case BODYPART_LEG_RIGHT:addstrAlt("Right Leg:"); break;
		case BODYPART_LEG_LEFT:addstrAlt("Left Leg:"); break;
		}
		moveAlt(y + w, x + 11);
		if (cr.wound[w] & WOUND_NASTYOFF)addstrAlt("Ripped off");
		else if (cr.wound[w] & WOUND_CLEANOFF)addstrAlt("Severed");
		else
		{
			int sum = 0;
			if (cr.wound[w] & WOUND_SHOT)sum++;
			if (cr.wound[w] & WOUND_CUT)sum++;
			if (cr.wound[w] & WOUND_BRUISED)sum++;
			if (cr.wound[w] & WOUND_BURNED)sum++;
			if (cr.wound[w] & WOUND_TORN)sum++;
			if (sum == 0)
			{
				set_color(COLOR_GREEN, COLOR_BLACK, 1);
				if (cr.animalgloss == ANIMALGLOSS_ANIMAL)
					addstrAlt("Animal");
				else addstrAlt("Liberal");
			}
			if (cr.wound[w] & WOUND_SHOT) { addstrAlt("Shot"); sum--; if (sum>0)addstrAlt(","); }
			if (cr.wound[w] & WOUND_BRUISED) { addstrAlt("Bruised"); sum--; if (sum>0)addstrAlt(","); }
			if (cr.wound[w] & WOUND_CUT) { addstrAlt("Cut"); sum--; if (sum>0)addstrAlt(","); }
			if (cr.wound[w] & WOUND_TORN) { addstrAlt("Torn"); sum--; if (sum>0)addstrAlt(","); }
			if (cr.wound[w] & WOUND_BURNED) { addstrAlt("Burned"); sum--; if (sum>0)addstrAlt(","); }
		}
	}
}
/* prints a character's health description (One Leg, Liberal, NearDETH...) */
void printhealthstat(Creature &g, int y, int x, char smll)
{
	short woundsum = 0;
	bool bleeding = false;
	for (int w = 0; w<BODYPARTNUM; w++)
	{
		if (g.wound[w] != 0)woundsum++;
		if (g.wound[w] & WOUND_BLEEDING)bleeding = true;
	}
	int armok = 2, legok = 2;
	if ((g.wound[BODYPART_ARM_RIGHT] & WOUND_NASTYOFF) ||
		(g.wound[BODYPART_ARM_RIGHT] & WOUND_CLEANOFF))armok--;
	if ((g.wound[BODYPART_ARM_LEFT] & WOUND_NASTYOFF) ||
		(g.wound[BODYPART_ARM_LEFT] & WOUND_CLEANOFF))armok--;
	if ((g.wound[BODYPART_LEG_RIGHT] & WOUND_NASTYOFF) ||
		(g.wound[BODYPART_LEG_RIGHT] & WOUND_CLEANOFF))legok--;
	if ((g.wound[BODYPART_LEG_LEFT] & WOUND_NASTYOFF) ||
		(g.wound[BODYPART_LEG_LEFT] & WOUND_CLEANOFF))legok--;
	moveAlt(y, x);
	if (bleeding)set_color(COLOR_RED, COLOR_BLACK, 1);
	else set_color(COLOR_WHITE, COLOR_BLACK, 1);
	if (!g.alive)
	{
		set_color(COLOR_BLACK, COLOR_BLACK, 1);
		addstrAlt("Deceased");
	}
	else if (g.blood <= 20)
	{
		if (smll)addstrAlt("NearDETH");
		else addstrAlt("Near Death");
	}
	else if (g.blood <= 50)
	{
		if (smll)addstrAlt("BadWound");
		else addstrAlt("Badly Wounded");
	}
	else if (g.blood <= 75)
	{
		addstrAlt("Wounded");
	}
	else if (g.blood<100)
	{
		if (smll)addstrAlt("LtWound");
		else addstrAlt("Lightly Wounded");
	}
	else if (g.special[SPECIALWOUND_NECK] == 2)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		if (smll)addstrAlt("NckBroke");
		else addstrAlt("Neck Broken");
	}
	else if (g.special[SPECIALWOUND_UPPERSPINE] == 2)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		if (smll)addstrAlt("Quadpleg");
		else addstrAlt("Quadraplegic");
	}
	else if (g.special[SPECIALWOUND_LOWERSPINE] == 2)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		if (smll)addstrAlt("Parapleg");
		else addstrAlt("Paraplegic");
	}
	else if (g.special[SPECIALWOUND_RIGHTEYE] == 0 &&
		g.special[SPECIALWOUND_LEFTEYE] == 0 &&
		g.special[SPECIALWOUND_NOSE] == 0)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		if (smll)addstrAlt("FaceGone");
		else addstrAlt("Face Gone");
	}
	else if (legok == 0 && armok == 0)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		addstrAlt("No Limbs");
	}
	else if ((legok == 1 && armok == 0) || (armok == 1 && legok == 0))
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		addstrAlt("One Limb");
	}
	else if (legok == 2 && armok == 0)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		addstrAlt("No Arms");
	}
	else if (legok == 0 && armok == 2)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		addstrAlt("No Legs");
	}
	else if (legok == 1 && armok == 1)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		if (smll)addstrAlt("1Arm1Leg");
		else addstrAlt("One Arm, One Leg");
	}
	else if (armok == 1)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		addstrAlt("One Arm");
	}
	else if (legok == 1)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		addstrAlt("One Leg");
	}
	else if (g.special[SPECIALWOUND_RIGHTEYE] == 0 &&
		g.special[SPECIALWOUND_LEFTEYE] == 0)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		addstrAlt("Blind");
	}
	else if ((g.special[SPECIALWOUND_RIGHTEYE] == 0 ||
		g.special[SPECIALWOUND_LEFTEYE] == 0) &&
		g.special[SPECIALWOUND_NOSE] == 0)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		if (smll)addstrAlt("FaceMutl");
		else addstrAlt("Face Mutilated");
	}
	else if (g.special[SPECIALWOUND_NOSE] == 0)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		if (smll)addstrAlt("NoseGone");
		else addstrAlt("Missing Nose");
	}
	else if (g.special[SPECIALWOUND_RIGHTEYE] == 0 ||
		g.special[SPECIALWOUND_LEFTEYE] == 0)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		if (smll)addstrAlt("One Eye");
		else addstrAlt("Missing Eye");
	}
	else if (g.special[SPECIALWOUND_TONGUE] == 0)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		if (smll)addstrAlt("NoTongue");
		else addstrAlt("No Tongue");
	}
	else if (g.special[SPECIALWOUND_TEETH] == 0)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		addstrAlt("No Teeth");
	}
	else if (g.special[SPECIALWOUND_TEETH]<TOOTHNUM)
	{
		if (!bleeding)set_color(COLOR_GREEN, COLOR_BLACK, 0);
		if (smll)addstrAlt("MisTeeth");
		else addstrAlt("Missing Teeth");
	}
	else
	{
		if (g.align == -1)
		{
			set_color(COLOR_RED, COLOR_BLACK, 1);
			if (smll)addstrAlt("Consrvtv");
			else addstrAlt("Conservative");
		}
		else if (g.align == 0)
		{
			set_color(COLOR_WHITE, COLOR_BLACK, 1);
			addstrAlt("Moderate");
		}
		else
		{
			set_color(COLOR_GREEN, COLOR_BLACK, 1);
			if (g.animalgloss == ANIMALGLOSS_ANIMAL)
				addstrAlt("Animal");
			else addstrAlt("Liberal");
		}
	}
}
/*
This function prints the cash the player has with optional prefix as
well as screen coordinates.
Please note that offsetx is the offset from the right of the screen, y is
the offset from the top as always.
*/
void printfunds(int y, int offsetx, const char* prefix, long funds);
void printfunds(int y, int offsetx, const char* prefix)
{
	printfunds(y, offsetx, prefix, ledger.get_funds());
}
/* prints a short blurb showing how to page forward */
void addnextpagestr()
{
	if (interface_pgup == '[')
		addstrAlt("] - Next");
	else if (interface_pgup == '.')
		addstrAlt(": - Next");
	else addstrAlt("PGDN - Next");
}
/* prints a short blurb showing how to page back */
void addprevpagestr()
{
	if (interface_pgup == '[')
		addstrAlt("[ - Previous");
	else if (interface_pgup == '.')
		addstrAlt("; - Previous");
	else addstrAlt("PGUP - Previous");
}
/* prints a long blurb showing how to page forward and back */
void addpagestr()
{
	if (interface_pgup == '[')
		addstrAlt("[] to view other Liberal pages.");
	else if (interface_pgup == '.')
		addstrAlt("; and : to view other Liberal pages.");
	else addstrAlt("PGUP/PGDN to view other Liberal pages.");
}
static char sbuf[81]; // used by addstr_f(), mvaddstr_f(), addstr_fl(), and mvaddstr_fl()
#define FORMAT_OUTPUT  va_list args; \
                       va_start(args,format); \
                       vsnprintf(sbuf,81,format,args); \
                       va_end(args);
					  /*	addstr with formatted output	*/
int addstr_f(const char * format, ...)
{
	FORMAT_OUTPUT
		return addstrAlt(sbuf);
}
/*	mvaddstr with formatted output	*/
int mvaddstr_f(int y, int x, const char * format, ...)
{
	FORMAT_OUTPUT
		return mvaddstrAlt(y, x, sbuf);
}
/*	addstr with formatted output and logging	*/
int addstr_fl(Log &log, const char * format, ...)
{
	FORMAT_OUTPUT
		return addstrAlt(sbuf, log);
}
/*	mvaddstr with formatted output and logging	*/
int mvaddstr_fl(int y, int x, Log &log, const char * format, ...)
{
	FORMAT_OUTPUT
		return mvaddstrAlt(y, x, sbuf, log);
}
