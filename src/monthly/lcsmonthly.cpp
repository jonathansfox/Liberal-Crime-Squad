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

#include "items/itemPool.h"
#include "items/lootTypePool.h"

#include "log/log.h"
// for commondisplay.h
#include "common/commondisplay.h"
// for addpage and delimiter

//#include "common/equipment.h"
void consolidateloot(vector<Item *> &loot);

//#include "common/translateid.h"
int getloottype(const string &idname);

#include "common/commonactions.h"
// for void change_public_opinion(int,int,char =1,char=100);



#include <cursesAlternative.h>
#include <cursesAlternativeConstants.h>
#include <constant_strings.h>
#include <set_color_support.h>
extern Log gamelog;
#include "locations/locationsPool.h"
#include "common/musicClass.h"
extern MusicClass music;
extern string spaceDashSpace;
extern string closeParenthesis;
extern vector<squadst *> squad;
extern class Ledger ledger;
extern short interface_pgup;
extern short interface_pgdn;
extern char disbanding;
extern short offended_firemen;
extern short lawList[LAWNUM];
extern short offended_corps;
extern short offended_cia;
extern short offended_amradio;
extern short offended_cablenews;
typedef map<short, string > shortAndString;
 string bound_to_rile_up;
 string major_news_take_it_up;
  shortAndString expenseTypes;
  shortAndString incomeTypes;
//TODO: Log the monthly report? --Addictgamer
/* monthly - reports the guardian's power to the player */
void guardianupdate(char size, int power)
{
	music.play(MUSIC_NEWSPAPER);

	eraseAlt();
	set_color_easy(WHITE_ON_BLACK);
	moveAlt(5, 2);
	if (size)

	{
		addstrAlt("The monthly Liberal Guardian newspaper", gamelog);

	}
	else

	{
		addstrAlt("The monthly Liberal Guardian online newsletter", gamelog);

	}
	addstrAlt(" is published.", gamelog);
	gamelog.newline();
	moveAlt(7, 2);
	if (power < 0)

	{
		addstrAlt("The only readers are Conservatives, who seem to think it's funny.", gamelog);

	}
	else if (power == 0)

	{
		addstrAlt("Unfortunately, nobody seems interested.", gamelog);

	}
	else if (power < 5)

	{
		addstrAlt("Very few people seem to be interested.", gamelog);

	}
	else if (power < 50)

	{
		addstrAlt("A fair number of people are reading it.", gamelog);

	}
	else if (power < 100)

	{
		addstrAlt("Many people are reading it.", gamelog);

	}
	else if (power < 250)

	{
		addstrAlt("The response is very strong. People are changing their minds.", gamelog);

	}
	else

	{
		addstrAlt("The response is electric. Everyone is talking about this month's ", gamelog);
		mvaddstrAlt(8,  2, "Liberal Guardian.", gamelog);

	}
	gamelog.nextMessage();
	getkeyAlt();
	return;
}
/* monthly - lets the player choose a special edition for the guardian */
int choosespecialedition(char &clearformess)
{
	//Temporary, maybe put special edition definition into an xml file. -XML

	static const string document_types[] =
	{  // This list MUST be in alphabetical order for binary_search() to work right
		tag_LOOT_AMRADIOFILES,
		tag_LOOT_CABLENEWSFILES,
		tag_LOOT_CCS_BACKERLIST,
		tag_LOOT_CEOLOVELETTERS,
		tag_LOOT_CEOPHOTOS,
		tag_LOOT_CEOTAXPAPERS,
		tag_LOOT_CORPFILES,
		tag_LOOT_INTHQDISK,
		tag_LOOT_JUDGEFILES,
		tag_LOOT_POLICERECORDS,
		tag_LOOT_PRISONFILES,
		tag_LOOT_RESEARCHFILES,
		tag_LOOT_SECRETDOCUMENTS
	};
	static const vector<string> dox(document_types, document_types + len(document_types));
	int page = 0;
	//char havetype[LOOTNUM];
	//for(int l=0;l<LOOTNUM;l++)havetype[l]=0;
	vector<bool> havetype(LootTypePool::getInstance().lenpool(), false);
	vector<int> loottypeindex;
	LocationsPool::getInstance().findAllLootTypes(havetype, loottypeindex, dox);
	for (int sq = 0; sq < len(squad); sq++)

	{
		consolidateloot(squad[sq]->loot);
		for (int l = 0; l < len(squad[sq]->loot); l++)

		{
			if (!squad[sq]->loot[l]->is_loot()) continue;
			if (!binary_search(dox.begin(), dox.end(), squad[sq]->loot[l]->get_itemtypename())) continue;
			if (!havetype[getloottype(squad[sq]->loot[l]->get_itemtypename())])

			{
				loottypeindex.push_back(getloottype(squad[sq]->loot[l]->get_itemtypename()));
				havetype[getloottype(squad[sq]->loot[l]->get_itemtypename())] = true;



			}
		}
	}
	if (!len(loottypeindex)) return -1;
	clearformess = 1;
	//PICK ONE
	while (true)

	{
		music.play(MUSIC_NEWSPAPER);

		eraseAlt();
		set_color_easy(WHITE_ON_BLACK);

		mvaddstrAlt(0,  0, "Do you want to run a special edition?");
		int x = 1, y = 10;
		char str[200];
		for (int l = page * 18; l < len(loottypeindex) && l < page * 18 + 18; l++)

		{
			str[0] = l - page * 18 + 'A';
			str[1] = '\x0';
			strcat(str, spaceDashSpace.c_str());
			strcat(str, LootTypePool::getInstance().getIdName(loottypeindex[l]).c_str());


			mvaddstrAlt(y,  x, str);
			x += 26;
			if (x > 53) x = 1, y++;

		}
		//PAGE UP
		if (page > 0)


		{
			mvaddstrAlt(17, 1, addprevpagestr());

		}
		//PAGE DOWN
		if ((page + 1) * 18 < LootTypePool::getInstance().lenpool())

		{
			mvaddstrAlt(17, 53,addnextpagestr());

		}
		mvaddstrAlt(24,  1, "Enter - Not in this month's Liberal Guardian");
		int c = getkeyAlt();
		if (c >= 'a'&&c <= 'r')

		{
			int slot = c - 'a' + page * 18;
			if (slot >= 0 && slot < len(loottypeindex))

			{
				// remove item from location
				int output = LocationsPool::getInstance().deleteSpecialItem(slot, loottypeindex);
				if (output != -1) {
					return output;
				}
				// if not in location, remove item from squad
				for (int sq = 0; sq < len(squad); sq++)

				{
					for (int l = 0; l < len(squad[sq]->loot); l++)

					{
						if (!squad[sq]->loot[l]->is_loot()) continue;
						if (getloottype(squad[sq]->loot[l]->get_itemtypename()) == loottypeindex[slot])

						{
							squad[sq]->loot[l]->decrease_number(1);
							if (squad[sq]->loot[l]->empty())
								delete_and_remove(squad[sq]->loot, l);
							return loottypeindex[slot];



						}
					}
				}
				//WHOOPS!
				return loottypeindex[slot];


			}
		}
		if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) return -1;
		//PAGE UP
		if ((c == interface_pgup || c == KEY_UP || c == KEY_LEFT) && page>0) page--;
		//PAGE DOWN
		if ((c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) && (page + 1) * 18<LootTypePool::getInstance().lenpool()) page++;

	}
	return -1;
}
/* monthly - guardian - prints liberal guardian special editions */
void printnews(short li, short newspaper)
{
	//// TODO Move to XML
	music.play(MUSIC_NEWSPAPER);
	if (lawList[LAW_FREESPEECH] == -2)offended_firemen = 1;
	string lootIDName = LootTypePool::getInstance().getIdName(li);
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK_BRIGHT);
	if (lootIDName == tag_LOOT_CEOPHOTOS) // Tmp -XML


	{
		mvaddstrAlt(6,  1, "The Liberal Guardian runs a story featuring photos of a major CEO ", gamelog);
		moveAlt(7, 1);
		change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
		change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);
		switch (LCSrandom(10))

		{
		case 0:
			addstrAlt("engaging in lewd behavior with animals.", gamelog);
			change_public_opinion(VIEW_ANIMALRESEARCH, 15);

			break;
		case 1:addstrAlt("digging up graves and sleeping with the dead.", gamelog); break;
		case 2:
			addstrAlt("participating in a murder.", gamelog);
			change_public_opinion(VIEW_POLICEBEHAVIOR, 15);
			change_public_opinion(VIEW_JUSTICES, 10);

			break;
		case 3:addstrAlt("engaging in heavy bondage.  A cucumber was involved in some way.", gamelog); break;
		case 4:addstrAlt("tongue-kissing an infamous dictator.", gamelog); break;
		case 5:
			addstrAlt("making out with an FDA official overseeing the CEO's products.", gamelog);
			change_public_opinion(VIEW_GENETICS, 10);
			change_public_opinion(VIEW_POLLUTION, 10);

			break;
		case 6:addstrAlt("castrating himself.", gamelog); break;
		case 7:addstrAlt("waving a Nazi flag at a supremacist rally.", gamelog); break;
		case 8:
			addstrAlt("torturing an employee with a hot iron.", gamelog);
			change_public_opinion(VIEW_SWEATSHOPS, 10);

			break;
		case 9:addstrAlt("playing with feces and urine.", gamelog); break;

		}
		gamelog.newline();
		mvaddstrAlt(9,  1, major_news_take_it_up, gamelog);
		gamelog.newline();
		mvaddstrAlt(10,  1, bound_to_rile_up, gamelog);
		gamelog.nextMessage();
		change_public_opinion(VIEW_CEOSALARY, 50);
		change_public_opinion(VIEW_CORPORATECULTURE, 50);
		offended_corps = 1;

	}
	else if (lootIDName == tag_LOOT_CEOLOVELETTERS)

	{
		mvaddstrAlt(6,  1, "The Liberal Guardian runs a story featuring love letters from a major CEO ", gamelog);
		moveAlt(7, 1);
		change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
		change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);
		switch (LCSrandom(8))

		{
		case 0:
			addstrAlt("addressed to his pet dog.  Yikes.", gamelog);
			change_public_opinion(VIEW_ANIMALRESEARCH, 15);

			break;
		case 1:
			addstrAlt("to the judge that acquit him in a corruption trial.", gamelog);
			change_public_opinion(VIEW_JUSTICES, 15);

			break;
		case 2:
			addstrAlt("to an illicit gay lover.", gamelog);
			change_public_opinion(VIEW_GAY, 15);

			break;
		case 3:addstrAlt("to himself.  They're very steamy.", gamelog); break;
		case 4:
			addstrAlt("implying that he has enslaved his houseservants.", gamelog);
			change_public_opinion(VIEW_SWEATSHOPS, 10);

			break;
		case 5:
			addstrAlt("to the FDA official overseeing the CEO's products.", gamelog);
			change_public_opinion(VIEW_GENETICS, 10);
			change_public_opinion(VIEW_POLLUTION, 10);

			break;
		case 6:addstrAlt("that seem to touch on every fetish known to man.", gamelog); break;
		case 7:addstrAlt("promising someone company profits in exchange for sexual favors.", gamelog); break;

		}
		gamelog.newline();
		mvaddstrAlt(9,  1, major_news_take_it_up, gamelog);
		gamelog.newline();
		mvaddstrAlt(10,  1, bound_to_rile_up, gamelog);
		gamelog.nextMessage();
		change_public_opinion(VIEW_CEOSALARY, 50);
		change_public_opinion(VIEW_CORPORATECULTURE, 50);
		offended_corps = 1;

	}
	else if (lootIDName == tag_LOOT_CEOTAXPAPERS)

	{
		mvaddstrAlt(6,  1, "The Liberal Guardian runs a story featuring a major CEO's tax papers ", gamelog);
		moveAlt(7, 1);
		change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
		change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);
		switch (LCSrandom(1))

		{
		default:
			addstrAlt("showing that he has engaged in consistent tax evasion.", gamelog);
			change_public_opinion(VIEW_TAXES, 25);


			break;
		}
		gamelog.newline();
		mvaddstrAlt(9,  1, major_news_take_it_up, gamelog);
		gamelog.newline();
		mvaddstrAlt(10,  1, bound_to_rile_up, gamelog);
		gamelog.nextMessage();
		change_public_opinion(VIEW_CEOSALARY, 50);
		change_public_opinion(VIEW_CORPORATECULTURE, 50);
		offended_corps = 1;

	}
	else if (lootIDName == tag_LOOT_CORPFILES)

	{
		mvaddstrAlt(6,  1, "The Liberal Guardian runs a story featuring Corporate files ", gamelog);
		moveAlt(7, 1);
		change_public_opinion(VIEW_LIBERALCRIMESQUAD, newspaper * 10);
		change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, newspaper * 10);
		switch (LCSrandom(5))

		{
		case 0:
			addstrAlt("describing a genetic monster created in a lab.", gamelog);
			change_public_opinion(VIEW_GENETICS, 50);

			break;
		case 1:
			addstrAlt("with a list of gay employees entitled \"Homo-workers\".", gamelog);
			change_public_opinion(VIEW_GAY, 50);

			break;
		case 2:
			addstrAlt("containing a memo: \"Terminate the pregnancy, I terminate you.\"", gamelog);
			change_public_opinion(VIEW_WOMEN, 50);

			break;
		case 3:
			addstrAlt("cheerfully describing foreign corporate sweatshops.", gamelog);
			change_public_opinion(VIEW_SWEATSHOPS, 50);

			break;
		case 4:
			addstrAlt("describing an intricate tax scheme.", gamelog);
			change_public_opinion(VIEW_TAXES, 50);


			break;
		}
		gamelog.newline();
		mvaddstrAlt(9,  1, major_news_take_it_up, gamelog);
		gamelog.newline();
		mvaddstrAlt(10,  1, bound_to_rile_up, gamelog);
		gamelog.nextMessage();
		change_public_opinion(VIEW_CEOSALARY, 50);
		change_public_opinion(VIEW_CORPORATECULTURE, 50);
		offended_corps = 1;

	}
	else if (lootIDName == tag_LOOT_CCS_BACKERLIST)

	{
		mvaddstrAlt(5,  1, "The Liberal Guardian runs more than one thousand pages of documents about ", gamelog);
		gamelog.newline();
		mvaddstrAlt(6,  1, "the CCS organization, also revealing in extreme detail the names and ", gamelog);
		gamelog.newline();
		mvaddstrAlt(7,  1, "responsibilities of Conservative Crime Squad sympathizers and supporters", gamelog);
		gamelog.newline();
		mvaddstrAlt(8,  1, "in the state and federal governments. Sections precisely document the", gamelog);
		gamelog.newline();
		mvaddstrAlt(9,  1, "extensive planning to create an extra-judicial death squad that would be", gamelog);
		gamelog.newline();
		mvaddstrAlt(10,  1, "above prosecution, and could hunt down law-abiding Liberals and act", gamelog);
		gamelog.newline();
		mvaddstrAlt(11,  1, "as a foil when no other enemies were present to direct public energy", gamelog);
		gamelog.newline();
		mvaddstrAlt(12,  1, "against.", gamelog);
		mvaddstrAlt(14,  1, "The scandal reaches into the heart of the Conservative leadership in the", gamelog);
		gamelog.newline();
		mvaddstrAlt(15,  1, "country, and the full ramifications of this revelation may not be felt", gamelog);
		gamelog.newline();

		mvaddstrAlt(16,  1, "for months. One thing is clear, however, from the immediate public reaction", gamelog);
		gamelog.newline();

		mvaddstrAlt(17,  1, "toward the revelations, and the speed with which even AM Radio and Cable", gamelog);
		gamelog.newline();
		mvaddstrAlt(18,  1, "News denounce the CCS.", gamelog);
		gamelog.newline();
		mvaddstrAlt(20,  1, "This is the beginning of the end for the Conservative Crime Squad.", gamelog);
		gamelog.nextMessage();
		change_public_opinion(VIEW_INTELLIGENCE, 50);
		change_public_opinion(VIEW_CONSERVATIVECRIMESQUAD, 100);
		ccsexposure = CCSEXPOSURE_EXPOSED;

	}
	else if (lootIDName == tag_LOOT_INTHQDISK
		|| lootIDName == tag_LOOT_SECRETDOCUMENTS)

	{
		mvaddstrAlt(6,  1, "The Liberal Guardian runs a story featuring CIA and other intelligence files ", gamelog);
		moveAlt(7, 1);
		change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
		change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);
		switch (LCSrandom(6))

		{
		case 0:addstrAlt("documenting the overthrow of a government.", gamelog); break;
		case 1:
			addstrAlt("documenting the planned assassination of a Liberal federal judge.", gamelog);
			change_public_opinion(VIEW_JUSTICES, 50);

			break;
		case 2:addstrAlt("containing private information on innocent citizens.", gamelog); break;
		case 3:
			addstrAlt("documenting \"harmful speech\" made by innocent citizens.", gamelog);
			change_public_opinion(VIEW_FREESPEECH, 50);

			break;
		case 4:
			addstrAlt("used to keep tabs on gay citizens.", gamelog);
			change_public_opinion(VIEW_GAY, 50);

			break;
		case 5:
			addstrAlt("documenting the infiltration of a pro-choice group.", gamelog);
			change_public_opinion(VIEW_WOMEN, 50);


			break;
		}
		gamelog.newline();
		mvaddstrAlt(9,  1, major_news_take_it_up, gamelog);
		gamelog.newline();
		mvaddstrAlt(10,  1, "This is bound to get the Government a little riled up.", gamelog);
		gamelog.nextMessage();
		change_public_opinion(VIEW_INTELLIGENCE, 50);
		offended_cia = 1;

	}
	else if (lootIDName == tag_LOOT_POLICERECORDS)

	{
		mvaddstrAlt(6,  1, "The Liberal Guardian runs a story featuring police records ", gamelog);
		moveAlt(7, 1);
		change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
		change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);
		switch (LCSrandom(6))

		{
		case 0:
			addstrAlt("documenting human rights abuses by the force.", gamelog);
			change_public_opinion(VIEW_TORTURE, 15);

			break;
		case 1:
			addstrAlt("documenting a police torture case.", gamelog);
			change_public_opinion(VIEW_TORTURE, 50);

			break;
		case 2:
			addstrAlt("documenting a systematic invasion of privacy by the force.", gamelog);
			change_public_opinion(VIEW_INTELLIGENCE, 15);

			break;
		case 3:
			addstrAlt("documenting a forced confession.", gamelog);

			break;
		case 4:
			addstrAlt("documenting widespread corruption in the force.", gamelog);

			break;
		case 5:
			addstrAlt("documenting gladiatorial matches held between prisoners by guards.", gamelog);
			change_public_opinion(VIEW_DEATHPENALTY, 50);
			change_public_opinion(VIEW_PRISONS, 20);


			break;
		}
		moveAlt(9, 1);
		gamelog.newline();

		addstrAlt(major_news_take_it_up, gamelog);
		gamelog.nextMessage();
		change_public_opinion(VIEW_POLICEBEHAVIOR, 50);

	}
	else if (lootIDName == tag_LOOT_JUDGEFILES)

	{
		mvaddstrAlt(6,  1, "The Liberal Guardian runs a story with evidence of a Conservative judge ", gamelog);
		moveAlt(7, 1);
		change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
		change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);
		switch (LCSrandom(2))

		{
		case 0:addstrAlt("taking bribes to acquit murderers.", gamelog); break;
		case 1:addstrAlt("promising Conservative rulings in exchange for appointments.", gamelog); break;

		}
		gamelog.newline();
		mvaddstrAlt(8,  1, major_news_take_it_up, gamelog);
		gamelog.nextMessage();
		change_public_opinion(VIEW_JUSTICES, 50);

	}
	else if (lootIDName == tag_LOOT_RESEARCHFILES)

	{
		mvaddstrAlt(6,  1, "The Liberal Guardian runs a story featuring research papers ", gamelog);
		moveAlt(7, 1);
		change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
		change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);
		switch (LCSrandom(4))

		{
		case 0:addstrAlt("documenting horrific animal rights abuses.", gamelog);
			change_public_opinion(VIEW_ANIMALRESEARCH, 50); break;
		case 1:addstrAlt("studying the effects of torture on cats.", gamelog);
			change_public_opinion(VIEW_ANIMALRESEARCH, 50); break;
		case 2:addstrAlt("covering up the accidental creation of a genetic monster.", gamelog);
			change_public_opinion(VIEW_GENETICS, 50); break;
		case 3:addstrAlt("showing human test subjects dying under genetic research.", gamelog);
			change_public_opinion(VIEW_GENETICS, 50); break;

		}
		gamelog.newline();
		mvaddstrAlt(9,  1, major_news_take_it_up, gamelog);
		gamelog.nextMessage();

	}
	else if (lootIDName == tag_LOOT_PRISONFILES)

	{
		mvaddstrAlt(6,  1, "The Liberal Guardian runs a story featuring prison documents ", gamelog);
		moveAlt(7, 1);
		change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
		change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);
		change_public_opinion(VIEW_PRISONS, 50);
		switch (LCSrandom(4))

		{
		case 0:addstrAlt("documenting human rights abuses by prison guards.", gamelog); break;
		case 1:
			addstrAlt("documenting a prison torture case.", gamelog);
			change_public_opinion(VIEW_TORTURE, 50);

			break;
		case 2:addstrAlt("documenting widespread corruption among prison employees.", gamelog); break;
		case 3:
			addstrAlt("documenting gladiatorial matches held between prisoners by guards.", gamelog);

		}
		gamelog.newline();
		mvaddstrAlt(9,  1, major_news_take_it_up, gamelog);
		gamelog.nextMessage();
		change_public_opinion(VIEW_DEATHPENALTY, 50);

	}
	else if (lootIDName == tag_LOOT_CABLENEWSFILES)

	{
		mvaddstrAlt(6,  1, "The Liberal Guardian runs a story featuring cable news memos ", gamelog);
		moveAlt(7, 1);
		change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
		change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);
		switch (LCSrandom(4))

		{
		case 0:addstrAlt("calling their news 'the vanguard of Conservative thought'.", gamelog); break;
		case 1:addstrAlt("mandating negative coverage of Liberal politicians.", gamelog); break;
		case 2:addstrAlt("planning to drum up a false scandal about a Liberal figure.", gamelog); break;
		case 3:addstrAlt("instructing a female anchor to 'get sexier or get a new job'.", gamelog);


			break;
		}
		gamelog.newline();
		mvaddstrAlt(9,  1, major_news_take_it_up, gamelog);
		gamelog.newline();
		mvaddstrAlt(10,  1, "This is bound to get the Conservative masses a little riled up.", gamelog);
		gamelog.nextMessage();
		change_public_opinion(VIEW_CABLENEWS, 50);
		offended_cablenews = 1;

	}
	else if (lootIDName == tag_LOOT_AMRADIOFILES)

	{
		mvaddstrAlt(6,  1, "The Liberal Guardian runs a story featuring AM radio plans ", gamelog);
		moveAlt(7, 1);
		change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
		change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);
		switch (LCSrandom(3))

		{
		case 0:addstrAlt("calling listeners 'sheep to be told what to think'.", gamelog); break;
		case 1:addstrAlt("saying 'it's okay to lie, they don't need the truth'.", gamelog); break;
		case 2:addstrAlt("planning to drum up a false scandal about a Liberal figure.", gamelog); break;

		}
		gamelog.newline();
		mvaddstrAlt(9,  1, major_news_take_it_up, gamelog);
		gamelog.newline();
		mvaddstrAlt(10,  1, "This is bound to get the Conservative masses a little riled up.", gamelog);
		gamelog.nextMessage();
		change_public_opinion(VIEW_AMRADIO, 50);
		offended_amradio = 1;

	}
	getkeyAlt();
}
/* monthly - LCS finances report */
void fundreport(char &clearformess)
{
	if (disbanding) return;
	music.play(MUSIC_FINANCES);
	clearformess = true;
	int page = 0;
	bool showledger = false;
	std::string num;
	static const char dotdotdot[] = ". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ";
	int expenselines = 0;
	for (int i = 0; i < EXPENSETYPENUM; i++)
		if (ledger.expense[i])
			expenselines++;
	while (true)


	{
		eraseAlt();
		int y = 2, totalmoney = 0, dailymoney = 0, numpages = 1;
		set_color_easy(WHITE_ON_BLACK_BRIGHT);
		mvaddstrAlt(0,  0, "Liberal Crime Squad: Funding Report");
		for (int i = 0; i < INCOMETYPENUM; i++)

		{
			if (ledger.income[i])

			{
				showledger = true;
				if (page == numpages - 1)

				{
					set_color_easy(WHITE_ON_BLACK);
					mvaddstrAlt(y, 0, dotdotdot);
					set_color_easy(GREEN_ON_BLACK);
					num = "+$" + tostring(ledger.income[i]);
					mvaddstrAlt(y, 60 - len(num), num);
					if (ledger.dailyIncome[i])
						num = " (+$" + tostring(ledger.dailyIncome[i]) + closeParenthesis;


					else
					{
						set_color_easy(WHITE_ON_BLACK);


						num = " ($0)";
					}
					mvaddstrAlt(y, 73 - len(num), num);
					set_color_easy(WHITE_ON_BLACK);


















					if (incomeTypes.count(i)) {
						mvaddstrAlt(y, 0, incomeTypes[i]);
					}
					else {
						mvaddstrAlt(y, 0, incomeTypes[INCOMETYPENUM]);
					}
				}
				totalmoney += ledger.income[i];
				dailymoney += ledger.dailyIncome[i];
				if (++y >= 23) y = 2, numpages++;


			}
		}
		// If expenses are too long to fit on this page, start them on the next page so it isn't broken in half unnecessarily
		if (y + expenselines >= 23 && y > 2) y = 2, numpages++;
		for (int i = 0; i < EXPENSETYPENUM; i++)

		{
			if (ledger.expense[i])

			{
				showledger = true;
				if (page == numpages - 1)

				{
					set_color_easy(WHITE_ON_BLACK);
					mvaddstrAlt(y, 0, dotdotdot);
					set_color_easy(RED_ON_BLACK);
					num = "-$" + tostring(ledger.expense[i]);
					mvaddstrAlt(y, 60 - len(num), num);
					if (ledger.dailyExpense[i])
						num = " (-$" + tostring(ledger.dailyExpense[i]) + closeParenthesis;


					else
					{
						set_color_easy(WHITE_ON_BLACK);


						num = " ($0)";
					}
					mvaddstrAlt(y, 73 - len(num), num);
					set_color_easy(WHITE_ON_BLACK);





















					if (expenseTypes.count(i)) {
						mvaddstrAlt(y, 0, expenseTypes[i]);
					}
					else {
						mvaddstrAlt(y, 0, expenseTypes[EXPENSETYPENUM]);
					}
				}
				totalmoney -= ledger.expense[i];
				dailymoney -= ledger.dailyExpense[i];
				if (++y >= 23) y = 2, numpages++;


			}
		}
		if (showledger)

		{
			if (page == numpages - 1) makedelimiter(y);
			if (++y >= 23) y = 2, numpages++;
			if (page == numpages - 1)

			{
				set_color_easy(WHITE_ON_BLACK_BRIGHT);
				mvaddstrAlt(y, 0, "Net Change This Month (Day):");
				if (totalmoney > 0) { set_color_easy(GREEN_ON_BLACK_BRIGHT); num = "+"; }
				else if (totalmoney < 0) { set_color_easy(RED_ON_BLACK_BRIGHT); num = "-"; }
				else { set_color_easy(WHITE_ON_BLACK_BRIGHT); num = ""; }
				num += "$" + tostring(abs(totalmoney));
				mvaddstrAlt(y, 60 - len(num), num);
				if (dailymoney > 0)

				{
					set_color_easy(GREEN_ON_BLACK_BRIGHT);
					num = " (+$" + tostring(abs(dailymoney)) + closeParenthesis;

				}
				else if (dailymoney < 0)

				{
					set_color_easy(RED_ON_BLACK_BRIGHT);
					num = " (-$" + tostring(abs(dailymoney)) + closeParenthesis;



				}
				else
				{
					set_color_easy(WHITE_ON_BLACK_BRIGHT);


					num = " ($0)";
				}
				mvaddstrAlt(y, 73 - len(num), num);

			}
			if (++y >= 23) y = 2, numpages++;

		}
		if (y > 2) y++; // Blank line between income/expenses and assets if not starting a new page
		if (y + 7 >= 23) y = 2, numpages++; //Start a new page if the liquid assets won't fit on the rest of the current page.
											// tally up liquid assets
		long weaponValue = 0, armorValue = 0, clipValue = 0, lootValue = 0;
		LocationsPool::getInstance().getAssetValues(weaponValue, armorValue, clipValue, lootValue);
		
		if (page == numpages - 1)

		{
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(y, 0, dotdotdot);
			mvaddstrAlt(y, 0, "Cash");
			set_color_easy(ledger.get_funds() ? GREEN_ON_BLACK : WHITE_ON_BLACK);
			num = "$" + tostring(ledger.get_funds());
			mvaddstrAlt(y, 60 - len(num), num);

		}
		if (++y >= 23) y = 2, numpages++;
		if (page == numpages - 1)

		{
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(y, 0, dotdotdot);
			mvaddstrAlt(y, 0, "Tools and Weapons");
			set_color_easy(weaponValue ? GREEN_ON_BLACK : WHITE_ON_BLACK);
			num = "$" + tostring(weaponValue);
			mvaddstrAlt(y, 60 - len(num), num);

		}
		if (++y >= 23) y = 2, numpages++;
		if (page == numpages - 1)

		{
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(y, 0, dotdotdot);
			mvaddstrAlt(y, 0, "Clothing and Armor");
			set_color_easy(armorValue ? GREEN_ON_BLACK : WHITE_ON_BLACK);
			num = "$" + tostring(armorValue);
			mvaddstrAlt(y, 60 - len(num), num);

		}
		if (++y >= 23) y = 2, numpages++;
		if (page == numpages - 1)

		{
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(y, 0, dotdotdot);
			mvaddstrAlt(y, 0, "Ammunition");
			set_color_easy(clipValue ? GREEN_ON_BLACK : WHITE_ON_BLACK);
			num = "$" + tostring(clipValue);
			mvaddstrAlt(y, 60 - len(num), num);

		}
		if (++y >= 23) y = 2, numpages++;
		if (page == numpages - 1)

		{
			set_color_easy(WHITE_ON_BLACK);
			mvaddstrAlt(y, 0, dotdotdot);
			mvaddstrAlt(y, 0, "Miscellaneous Loot");
			set_color_easy(lootValue ? GREEN_ON_BLACK : WHITE_ON_BLACK);
			num = "$" + tostring(lootValue);
			mvaddstrAlt(y, 60 - len(num), num);

		}
		if (++y >= 23) y = 2, numpages++;
		if (page == numpages - 1) makedelimiter(y);
		if (++y >= 23) y = 2, numpages++;
		if (page == numpages - 1)

		{
			set_color_easy(WHITE_ON_BLACK_BRIGHT);
			mvaddstrAlt(y, 0, "Total Liquid Assets:");
			long netWorth = ledger.get_funds() + weaponValue + armorValue + clipValue + lootValue;
			set_color_easy(netWorth ? GREEN_ON_BLACK_BRIGHT : WHITE_ON_BLACK_BRIGHT);
			num = "$" + tostring(netWorth);
			mvaddstrAlt(y, 60 - len(num), num);

		}
		set_color_easy(WHITE_ON_BLACK);
		if (numpages > 1)

		{
			mvaddstrAlt(24, 0, "Press Enter to reflect on the report.  " +			addpagestr());
			while (true)

			{
				int c = getkeyAlt();
				if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR)

				{
					music.play(MUSIC_PREVIOUS);


					return;
				}
				//PAGE UP
				if (c == interface_pgup || c == KEY_UP || c == KEY_LEFT) { page--; if (page<0) page = numpages - 1; break; }
				//PAGE DOWN
				if (c == interface_pgdn || c == KEY_DOWN || c == KEY_RIGHT) { page++; if (page >= numpages) page = 0; break; }


			}
		}
		else

		{
			mvaddstrAlt(24, 0, "Press any key to reflect on the report.");
			getkeyAlt();
			music.play(MUSIC_PREVIOUS);
			return;


		}
	}
}
