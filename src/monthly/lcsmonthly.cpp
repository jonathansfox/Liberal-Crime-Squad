#define	LCSMONTHLY_CPP
#include "../includes.h"


const vector<int> viewAnimals = { VIEW_ANIMALRESEARCH, 15 };
const vector<int> viewJustice = { VIEW_JUSTICES, 15 };
const vector<int> viewGay = { VIEW_GAY, 15 };
const vector<int> emptyVector = {};
const vector<int> viewSweatshop = { VIEW_SWEATSHOPS, 10 };
const vector<int> viewGeneticAndPollution = { VIEW_GENETICS, 10, VIEW_POLLUTION, 10 };
const vector< pair<string, vector<int> > > CEOLoveLettersInfluence = {
	std::make_pair(CONST_lcsmonthly043, viewAnimals),
	std::make_pair(CONST_lcsmonthly044, viewJustice),
	std::make_pair(CONST_lcsmonthly045, viewGay),
	std::make_pair(CONST_lcsmonthly046, emptyVector),
	std::make_pair(CONST_lcsmonthly047, viewSweatshop),
	std::make_pair(CONST_lcsmonthly048, viewGeneticAndPollution),
	std::make_pair(CONST_lcsmonthly049, emptyVector),
	std::make_pair(CONST_lcsmonthly050, emptyVector),
};

const vector<int> viewPoliceAndJustice = { VIEW_POLICEBEHAVIOR, 15, VIEW_JUSTICES, 10 };
 const vector< pair<string, vector<int> > > CEOPhotosInfluence  = {
	std::make_pair(CONST_lcsmonthly032, viewAnimals),
	std::make_pair(CONST_lcsmonthly033, emptyVector),
	std::make_pair(CONST_lcsmonthly034, viewPoliceAndJustice),
	std::make_pair(CONST_lcsmonthly035, emptyVector),
	std::make_pair(CONST_lcsmonthly036, emptyVector),
	std::make_pair(CONST_lcsmonthly037, viewGeneticAndPollution),
	std::make_pair(CONST_lcsmonthly038, emptyVector),
	std::make_pair(CONST_lcsmonthly039, emptyVector),
	std::make_pair(CONST_lcsmonthly040, viewSweatshop),
	std::make_pair(CONST_lcsmonthly041, emptyVector),
};
const vector<int> viewTaxesStrong = { VIEW_TAXES, 25 };
const vector< pair<string, vector<int> > > CEOTaxesInfluence = {
	std::make_pair(CONST_lcsmonthly052, viewTaxesStrong),

};

const vector<int> strongGenetics = { VIEW_GENETICS, 50 };
const vector<int> strongGay = { VIEW_GAY, 50 };
const vector<int> strongWomen = { VIEW_WOMEN, 50 };
const vector<int> strongSweat = { VIEW_SWEATSHOPS, 50 };
const vector<int> strongTaxes = { VIEW_TAXES, 50 };
 const vector< pair<string, vector<int> > > CorpFilesInfluence = {
	std::make_pair(CONST_lcsmonthly054, strongGenetics),
	std::make_pair(CONST_lcsmonthly055, strongGay),
	std::make_pair(CONST_lcsmonthly056, strongWomen),
	std::make_pair(CONST_lcsmonthly057, strongSweat),
	std::make_pair(CONST_lcsmonthly058, strongTaxes),
};

const vector<int> strongJustice = { VIEW_JUSTICES, 50 };
const vector<int> strongFreeSpeech = { VIEW_FREESPEECH, 50 };
const vector< pair<string, vector<int> > > CIAPapersInfluence = {
	std::make_pair(CONST_lcsmonthly074, emptyVector),
	std::make_pair(CONST_lcsmonthly075, strongJustice),
	std::make_pair(CONST_lcsmonthly076, emptyVector),
	std::make_pair(CONST_lcsmonthly077, strongFreeSpeech),
	std::make_pair(CONST_lcsmonthly078, strongGay),
	std::make_pair(CONST_lcsmonthly079, strongWomen),

};


const vector<int> viewTorture = { VIEW_TORTURE , 15 };
const vector<int> strongTorture = { VIEW_TORTURE , 50 };
const vector<int> viewIntelligence = { VIEW_INTELLIGENCE , 15 };
const vector<int> viewDeathPrisons = { VIEW_DEATHPENALTY , 50, VIEW_PRISONS , 20 };
  const vector< pair<string, vector<int> > > PolicePapersInfluence =
{
	std::make_pair(CONST_lcsmonthly082, viewTorture),
	std::make_pair(CONST_lcsmonthly083, strongTorture),

	std::make_pair(CONST_lcsmonthly084, viewIntelligence),

	std::make_pair(CONST_lcsmonthly085, emptyVector),
	std::make_pair(CONST_lcsmonthly086, emptyVector),

	std::make_pair(CONST_lcsmonthly100, viewDeathPrisons),

};

const vector< pair<string, vector<int> > > JudgePapersInfluence =
{
	std::make_pair(CONST_lcsmonthly089, emptyVector),
	std::make_pair(CONST_lcsmonthly090, emptyVector),
};


const vector<int> strongAnimals = { VIEW_ANIMALRESEARCH, 50 };

const vector< pair<string, vector<int> > > ResearchPapersInfluence = {
	std::make_pair(CONST_lcsmonthly092, strongAnimals),
	std::make_pair(CONST_lcsmonthly093, strongAnimals),
	std::make_pair(CONST_lcsmonthly094, strongGenetics),
	std::make_pair(CONST_lcsmonthly095, strongGenetics),
};

const vector< pair<string, vector<int> > > PrisonPapersInfluence =
{
	std::make_pair(CONST_lcsmonthly097, emptyVector),
	std::make_pair(CONST_lcsmonthly098, strongTorture),

	std::make_pair(CONST_lcsmonthly099, emptyVector),
	std::make_pair(CONST_lcsmonthly100, emptyVector),
};

const vector< pair<string, vector<int> > > CablePapersInfluence  = {
	std::make_pair(CONST_lcsmonthly102, emptyVector),
	std::make_pair(CONST_lcsmonthly103, emptyVector),
	std::make_pair(CONST_lcsmonthly110, emptyVector),
	std::make_pair(CONST_lcsmonthly105, emptyVector),

};

const vector< pair<string, vector<int> > > RadioPapersInfluence  =
{
	std::make_pair(CONST_lcsmonthly108, emptyVector),
	std::make_pair(CONST_lcsmonthly109, emptyVector),
	std::make_pair(CONST_lcsmonthly110, emptyVector),
};


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
		  addstrAlt(CONST_lcsmonthly018, gamelog);
	  }
	  else
	  {
		  addstrAlt(CONST_lcsmonthly019, gamelog);
	  }
	  addstrAlt(CONST_lcsmonthly020, gamelog);
	  gamelog.newline();
	  moveAlt(7, 2);
	  if (power < 0)
	  {
		  addstrAlt(CONST_lcsmonthly021, gamelog);
	  }
	  else if (power == 0)
	  {
		  addstrAlt(CONST_lcsmonthly022, gamelog);
	  }
	  else if (power < 5)
	  {
		  addstrAlt(CONST_lcsmonthly023, gamelog);
	  }
	  else if (power < 50)
	  {
		  addstrAlt(CONST_lcsmonthly024, gamelog);
	  }
	  else if (power < 100)
	  {
		  addstrAlt(CONST_lcsmonthly025, gamelog);
	  }
	  else if (power < 250)
	  {
		  addstrAlt(CONST_lcsmonthly026, gamelog);
	  }
	  else
	  {
		  addstrAlt(CONST_lcsmonthly027, gamelog);
		  mvaddstrAlt(8, 2, CONST_lcsmonthly028, gamelog);
	  }
	  gamelog.nextMessage();
	  pressAnyKey();
	  return;
  }
  /* monthly - lets the player choose a special edition for the guardian */
  int choosespecialedition(char &clearformess)
  {
	  static const vector<string> dox(document_types, document_types + len(document_types));
	  int page = 0;
	  //char havetype[LOOTNUM];
	  //for(int l=0;l<LOOTNUM;l++)havetype[l]=0;
	  vector<bool> havetype(LootTypePool::getInstance().lenpool(), false);
	  vector<int> loottypeindex;
	  LocationsPool::getInstance().findAllLootTypes(havetype, loottypeindex, dox);
	  constructLootIndices(havetype, loottypeindex, dox);
	  if (!len(loottypeindex)) return -1;
	  clearformess = 1;
	  //PICK ONE
	  while (true)
	  {
		  music.play(MUSIC_NEWSPAPER);
		  eraseAlt();
		  set_color_easy(WHITE_ON_BLACK);
		  mvaddstrAlt(0, 0, CONST_lcsmonthly029);
		  int x = 1, y = 10;
		  char str[200];
		  for (int l = page * 18; l < len(loottypeindex) && l < page * 18 + 18; l++)
		  {
			  str[0] = l - page * 18 + 'A';
			  str[1] = '\x0';
			  strcat(str, spaceDashSpace.c_str());
			  strcat(str, LootTypePool::getInstance().getName(LootTypePool::getInstance().getIdName(loottypeindex[l])).c_str());
			  mvaddstrAlt(y, x, str);
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
			  mvaddstrAlt(17, 53, addnextpagestr());
		  }
		  mvaddstrAlt(24, 1, CONST_lcsmonthly030);
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
				  removeItemFromSquad(loottypeindex[slot]);
				  //WHOOPS!
				  return loottypeindex[slot];
			  }
		  }
		  if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR) return -1;
		  //PAGE UP
		  if (is_page_up(c) && page > 0) page--;
		  //PAGE DOWN
		  if (is_page_down(c) && (page + 1) * 18 < LootTypePool::getInstance().lenpool()) page++;
	  }
	  return -1;
  }
  void change_opinion_from_Influence(vector< pair<string, vector<int> > > Influence) {


	  vector<int>::iterator it;
	  int influence = LCSrandom(Influence.size());
	  addstrAlt(Influence[influence].first, gamelog);
	  for (it = Influence[influence].second.begin(); it != Influence[influence].second.end(); it += 2) {
		  change_public_opinion(*it, *(it + 1));
	  }

  }

  void printLootCCSBackers() {

	  mvaddstrAlt(5, 1, CONST_lcsmonthly059, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(6, 1, CONST_lcsmonthly060, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(7, 1, CONST_lcsmonthly061, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(8, 1, CONST_lcsmonthly062, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(9, 1, CONST_lcsmonthly063, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(10, 1, CONST_lcsmonthly064, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(11, 1, CONST_lcsmonthly065, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(12, 1, CONST_lcsmonthly066, gamelog);
	  mvaddstrAlt(14, 1, CONST_lcsmonthly067, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(15, 1, CONST_lcsmonthly068, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(16, 1, CONST_lcsmonthly069, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(17, 1, CONST_lcsmonthly070, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(18, 1, CONST_lcsmonthly071, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(20, 1, CONST_lcsmonthly072, gamelog);
	  gamelog.nextMessage();
	  change_public_opinion(VIEW_INTELLIGENCE, 50);
	  change_public_opinion(VIEW_CONSERVATIVECRIMESQUAD, 100);
	  ccsexposure = CCSEXPOSURE_EXPOSED;
  }

  void printLootCEOPhotos() {

	  mvaddstrAlt(6, 1, CONST_lcsmonthly031, gamelog);
	  moveAlt(7, 1);
	  change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
	  change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);

	  change_opinion_from_Influence(CEOPhotosInfluence);

	  gamelog.newline();
	  mvaddstrAlt(9, 1, major_news_take_it_up, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(10, 1, bound_to_rile_up, gamelog);
	  gamelog.nextMessage();
	  change_public_opinion(VIEW_CEOSALARY, 50);
	  change_public_opinion(VIEW_CORPORATECULTURE, 50);
	  offended_corps = 1;
  }
  void printLootCEOLoveLetters() {
	  mvaddstrAlt(6, 1, CONST_lcsmonthly042, gamelog);
	  moveAlt(7, 1);
	  change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
	  change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);


	  change_opinion_from_Influence(CEOLoveLettersInfluence);


	  gamelog.newline();
	  mvaddstrAlt(9, 1, major_news_take_it_up, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(10, 1, bound_to_rile_up, gamelog);
	  gamelog.nextMessage();
	  change_public_opinion(VIEW_CEOSALARY, 50);
	  change_public_opinion(VIEW_CORPORATECULTURE, 50);
	  offended_corps = 1;
  }
  void printLootCEOTaxes() {

	  mvaddstrAlt(6, 1, CONST_lcsmonthly051, gamelog);
	  moveAlt(7, 1);
	  change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
	  change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);

	  change_opinion_from_Influence(CEOTaxesInfluence);

	  gamelog.newline();
	  mvaddstrAlt(9, 1, major_news_take_it_up, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(10, 1, bound_to_rile_up, gamelog);
	  gamelog.nextMessage();
	  change_public_opinion(VIEW_CEOSALARY, 50);
	  change_public_opinion(VIEW_CORPORATECULTURE, 50);
	  offended_corps = 1;
  }

  void printLootCorpFiles(const short newspaper) {

	  mvaddstrAlt(6, 1, CONST_lcsmonthly053, gamelog);
	  moveAlt(7, 1);
	  change_public_opinion(VIEW_LIBERALCRIMESQUAD, newspaper * 10);
	  change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, newspaper * 10);


	  change_opinion_from_Influence(CEOPhotosInfluence);

	  gamelog.newline();
	  mvaddstrAlt(9, 1, major_news_take_it_up, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(10, 1, bound_to_rile_up, gamelog);
	  gamelog.nextMessage();
	  change_public_opinion(VIEW_CEOSALARY, 50);
	  change_public_opinion(VIEW_CORPORATECULTURE, 50);
	  offended_corps = 1;
  }
  void printLootCIAPapers() {
	  mvaddstrAlt(6, 1, CONST_lcsmonthly073, gamelog);
	  moveAlt(7, 1);
	  change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
	  change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);


	  change_opinion_from_Influence(CIAPapersInfluence);

	  gamelog.newline();
	  mvaddstrAlt(9, 1, major_news_take_it_up, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(10, 1, CONST_lcsmonthly080, gamelog);
	  gamelog.nextMessage();
	  change_public_opinion(VIEW_INTELLIGENCE, 50);
	  offended_cia = 1;
  }

  void printLootPolicePapers() {

	  mvaddstrAlt(6, 1, CONST_lcsmonthly081, gamelog);
	  moveAlt(7, 1);
	  change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
	  change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);


	  change_opinion_from_Influence(PolicePapersInfluence);

	  moveAlt(9, 1);
	  gamelog.newline();
	  addstrAlt(major_news_take_it_up, gamelog);
	  gamelog.nextMessage();
	  change_public_opinion(VIEW_POLICEBEHAVIOR, 50);
  }
  void printLootJudgePapers() {

	  mvaddstrAlt(6, 1, CONST_lcsmonthly088, gamelog);
	  moveAlt(7, 1);
	  change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
	  change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);


	  change_opinion_from_Influence(JudgePapersInfluence);

	  gamelog.newline();
	  mvaddstrAlt(8, 1, major_news_take_it_up, gamelog);
	  gamelog.nextMessage();
	  change_public_opinion(VIEW_JUSTICES, 50);
  }

  void printLootResearchPapers() {

	  mvaddstrAlt(6, 1, CONST_lcsmonthly091, gamelog);
	  moveAlt(7, 1);
	  change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
	  change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);


	  change_opinion_from_Influence(ResearchPapersInfluence);

	  gamelog.newline();
	  mvaddstrAlt(9, 1, major_news_take_it_up, gamelog);
	  gamelog.nextMessage();
  }

  void printLootPrisonPapers() {

	  mvaddstrAlt(6, 1, CONST_lcsmonthly096, gamelog);
	  moveAlt(7, 1);
	  change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
	  change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);
	  change_public_opinion(VIEW_PRISONS, 50);


	  change_opinion_from_Influence(PrisonPapersInfluence);

	  gamelog.newline();
	  mvaddstrAlt(9, 1, major_news_take_it_up, gamelog);
	  gamelog.nextMessage();
	  change_public_opinion(VIEW_DEATHPENALTY, 50);
  }

  void printLootCablePapers() {

	  mvaddstrAlt(6, 1, CONST_lcsmonthly101, gamelog);
	  moveAlt(7, 1);
	  change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
	  change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);


	  change_opinion_from_Influence(CablePapersInfluence);

	  gamelog.newline();
	  mvaddstrAlt(9, 1, major_news_take_it_up, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(10, 1, CONST_lcsmonthly111, gamelog);
	  gamelog.nextMessage();
	  change_public_opinion(VIEW_CABLENEWS, 50);
	  offended_cablenews = 1;
  }

//  vector< pair<string, vector<int> > > RadioPapersInfluence;
  void printLootRadioPapers() {


	  mvaddstrAlt(6, 1, CONST_lcsmonthly107, gamelog);
	  moveAlt(7, 1);
	  change_public_opinion(VIEW_LIBERALCRIMESQUAD, 10);
	  change_public_opinion(VIEW_LIBERALCRIMESQUADPOS, 10);


	  change_opinion_from_Influence(RadioPapersInfluence);

	  gamelog.newline();
	  mvaddstrAlt(9, 1, major_news_take_it_up, gamelog);
	  gamelog.newline();
	  mvaddstrAlt(10, 1, CONST_lcsmonthly111, gamelog);
	  gamelog.nextMessage();
	  change_public_opinion(VIEW_AMRADIO, 50);
	  offended_amradio = 1;
  }
  /* monthly - guardian - prints liberal guardian special editions */
  void printnews(short li, short newspaper)
  {
	  //// TODO Move to XML
	  music.play(MUSIC_NEWSPAPER);
	  if (lawList[LAW_FREESPEECH] == -2)offended_firemen = 1;
	  eraseAlt();
	  set_color_easy(WHITE_ON_BLACK_BRIGHT);

	  switch (lootTypeIDEnum[LootTypePool::getInstance().getIdName(li)]) {
	  case ENUM_tag_LOOT_CEOPHOTOS:

		  printLootCEOPhotos();
		  break;

	  case ENUM_tag_LOOT_CEOLOVELETTERS:


		  printLootCEOLoveLetters();
		  break;

	  case ENUM_tag_LOOT_CEOTAXPAPERS:


		  printLootCEOTaxes();
		  break;

	  case ENUM_tag_LOOT_CORPFILES:


		  printLootCorpFiles(newspaper);

	  case ENUM_tag_LOOT_CCS_BACKERLIST:


		  printLootCCSBackers();
		  break;

	  case ENUM_tag_LOOT_INTHQDISK:
	  case ENUM_tag_LOOT_SECRETDOCUMENTS:


		  printLootCIAPapers();
		  break;

	  case ENUM_tag_LOOT_POLICERECORDS:


		  printLootPolicePapers();
		  break;

	  case ENUM_tag_LOOT_JUDGEFILES:


		  printLootJudgePapers();
		  break;

	  case ENUM_tag_LOOT_RESEARCHFILES:


		  printLootResearchPapers();
		  break;

	  case ENUM_tag_LOOT_PRISONFILES:


		  printLootPrisonPapers();
		  break;

	  case ENUM_tag_LOOT_CABLENEWSFILES:


		  printLootCablePapers();
		  break;

	  case ENUM_tag_LOOT_AMRADIOFILES:


		  printLootRadioPapers();
		  break;

	  }

	  pressAnyKey();
  }
  void printIncomeTypes(const int y, const int i) {
	  set_color_easy(WHITE_ON_BLACK);
	  mvaddstrAlt(y, 0, dotdotdot);
	  set_color_easy(GREEN_ON_BLACK);
	  string num = CONST_lcsmonthly114 + tostring(ledger.income[i]);
	  mvaddstrAlt(y, 60 - len(num), num);
	  if (ledger.dailyIncome[i])
		  num = CONST_lcsmonthly124 + tostring(ledger.dailyIncome[i]) + closeParenthesis;
	  else
	  {
		  set_color_easy(WHITE_ON_BLACK);
		  num = CONST_lcsmonthly126;
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
  void printLedgerAmount(const int y, const int i) {
	  set_color_easy(WHITE_ON_BLACK);
	  mvaddstrAlt(y, 0, dotdotdot);
	  set_color_easy(RED_ON_BLACK);
	  string num = CONST_lcsmonthly117 + tostring(ledger.expense[i]);
	  mvaddstrAlt(y, 60 - len(num), num);
	  if (ledger.dailyExpense[i])
		  num = CONST_lcsmonthly125 + tostring(ledger.dailyExpense[i]) + closeParenthesis;
	  else
	  {
		  set_color_easy(WHITE_ON_BLACK);
		  num = CONST_lcsmonthly126;
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
  void printDailyMoney(const int y, const int dailymoney, const int totalmoney) {
	  string num;
	  set_color_easy(WHITE_ON_BLACK_BRIGHT);
	  mvaddstrAlt(y, 0, CONST_lcsmonthly120);
	  if (totalmoney > 0) { set_color_easy(GREEN_ON_BLACK_BRIGHT); num = CONST_lcsmonthly121; }
	  else if (totalmoney < 0) { set_color_easy(RED_ON_BLACK_BRIGHT); num = CONST_lcsmonthly122; }
	  else { set_color_easy(WHITE_ON_BLACK_BRIGHT); num = blankString; }
	  num += CONST_lcsmonthly138 + tostring(abs(totalmoney));
	  mvaddstrAlt(y, 60 - len(num), num);
	  if (dailymoney > 0)
	  {
		  set_color_easy(GREEN_ON_BLACK_BRIGHT);
		  num = CONST_lcsmonthly124 + tostring(abs(dailymoney)) + closeParenthesis;
	  }
	  else if (dailymoney < 0)
	  {
		  set_color_easy(RED_ON_BLACK_BRIGHT);
		  num = CONST_lcsmonthly125 + tostring(abs(dailymoney)) + closeParenthesis;
	  }
	  else
	  {
		  set_color_easy(WHITE_ON_BLACK_BRIGHT);
		  num = CONST_lcsmonthly126;
	  }
	  mvaddstrAlt(y, 73 - len(num), num);
  }
  void printLedgerPage(const int y, const string lcsmonthly, const long get_funds) {
	  string num = CONST_lcsmonthly138 + tostring(get_funds);
	  set_color_easy(WHITE_ON_BLACK);
	  mvaddstrAlt(y, 0, dotdotdot);
	  mvaddstrAlt(y, 0, lcsmonthly);
	  set_color_easy(get_funds ? GREEN_ON_BLACK : WHITE_ON_BLACK);
	  mvaddstrAlt(y, 60 - len(num), num);
  }
  /* monthly - LCS finances report */
  void fundreport(char &clearformess)
  {
	  if (disbanding) return;
	  music.play(MUSIC_FINANCES);
	  clearformess = true;
	  int page = 0;
	  bool showledger = false;
	  int expenselines = 0;
	  for (int i = 0; i < EXPENSETYPENUM; i++)
		  if (ledger.expense[i])
			  expenselines++;
	  while (true)
	  {
		  eraseAlt();
		  int y = 2, totalmoney = 0, dailymoney = 0, numpages = 1;
		  set_color_easy(WHITE_ON_BLACK_BRIGHT);
		  mvaddstrAlt(0, 0, CONST_lcsmonthly113);
		  for (int i = 0; i < INCOMETYPENUM; i++)
		  {
			  if (ledger.income[i])
			  {
				  showledger = true;
				  if (page == numpages - 1)
				  {
					  printIncomeTypes(y, i);
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
					  printLedgerAmount(y, i);
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
				  printDailyMoney(y, dailymoney, totalmoney);
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
			  printLedgerPage(y, CONST_lcsmonthly127, ledger.get_funds());
		  }
		  if (++y >= 23) y = 2, numpages++;
		  if (page == numpages - 1)
		  {
			  printLedgerPage(y, CONST_lcsmonthly129, weaponValue);
		  }
		  if (++y >= 23) y = 2, numpages++;
		  if (page == numpages - 1)
		  {
			  printLedgerPage(y, CONST_lcsmonthly131, armorValue);
		  }
		  if (++y >= 23) y = 2, numpages++;
		  if (page == numpages - 1)
		  {
			  printLedgerPage(y, CONST_lcsmonthly133, clipValue);
		  }
		  if (++y >= 23) y = 2, numpages++;
		  if (page == numpages - 1)
		  {
			  printLedgerPage(y, CONST_lcsmonthly135, lootValue);
		  }
		  if (++y >= 23) y = 2, numpages++;
		  if (page == numpages - 1) makedelimiter(y);
		  if (++y >= 23) y = 2, numpages++;
		  if (page == numpages - 1)
		  {
			  set_color_easy(WHITE_ON_BLACK_BRIGHT);
			  mvaddstrAlt(y, 0, CONST_lcsmonthly137);
			  long netWorth = ledger.get_funds() + weaponValue + armorValue + clipValue + lootValue;
			  set_color_easy(netWorth ? GREEN_ON_BLACK_BRIGHT : WHITE_ON_BLACK_BRIGHT);
			  string num = CONST_lcsmonthly138 + tostring(netWorth);
			  mvaddstrAlt(y, 60 - len(num), num);
		  }
		  set_color_easy(WHITE_ON_BLACK);
		  if (numpages > 1)
		  {
			  mvaddstrAlt(24, 0, CONST_lcsmonthly139 + addpagestr());
			  while (true)
			  {
				  int c = getkeyAlt();
				  if (c == 'x' || c == ENTER || c == ESC || c == SPACEBAR)
				  {
					  music.play(MUSIC_PREVIOUS);
					  return;
				  }
				  //PAGE UP
				  if (is_page_up(c)) { page--; if (page < 0) page = numpages - 1; break; }
				  //PAGE DOWN
				  if (is_page_down(c)) { page++; if (page >= numpages) page = 0; break; }
			  }
		  }
		  else
		  {
			  mvaddstrAlt(24, 0, CONST_lcsmonthly140);
			  pressAnyKey();
			  music.play(MUSIC_PREVIOUS);
			  return;
		  }
	  }
  }

