

#include "../includes20.h"
#include "specialeditions.h"
#include "../constStringlcsmonthly.h"

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
		  addstrAlt(CONST_THE_MONTHLY_LIBERAL_GUARDIAN_NEWSPAPER, gamelog);
	  }
	  else
	  {
		  addstrAlt(CONST_THE_MONTHLY_LIBERAL_GUARDIAN_ONLINE_NEWSLETTER, gamelog);
	  }
	  addstrAlt(CONST_IS_PUBLISHED, gamelog);
	  gamelog.newline();
	  moveAlt(7, 2);
	  if (power < 0)
	  {
		  addstrAlt(CONST_THE_ONLY_READERS_ARE_CONSERVATIVES_WHO_SEEM_TO_THINK_IT_S_FUNNY, gamelog);
	  }
	  else if (power == 0)
	  {
		  addstrAlt(CONST_UNFORTUNATELY_NOBODY_SEEMS_INTERESTED, gamelog);
	  }
	  else if (power < 5)
	  {
		  addstrAlt(CONST_VERY_FEW_PEOPLE_SEEM_TO_BE_INTERESTED, gamelog);
	  }
	  else if (power < 50)
	  {
		  addstrAlt(CONST_A_FAIR_NUMBER_OF_PEOPLE_ARE_READING_IT, gamelog);
	  }
	  else if (power < 100)
	  {
		  addstrAlt(CONST_MANY_PEOPLE_ARE_READING_IT, gamelog);
	  }
	  else if (power < 250)
	  {
		  addstrAlt(CONST_THE_RESPONSE_IS_VERY_STRONG_PEOPLE_ARE_CHANGING_THEIR_MINDS, gamelog);
	  }
	  else
	  {
		  addstrAlt(CONST_THE_RESPONSE_IS_ELECTRIC_EVERYONE_IS_TALKING_ABOUT_THIS_MONTH_S, gamelog);
		  mvaddstrAlt(8, 2, CONST_X_LIBERAL_GUARDIAN, gamelog);
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
		  mvaddstrAlt(0, 0, CONST_DO_YOU_WANT_TO_RUN_A_SPECIAL_EDITION);
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
		  mvaddstrAlt(24, 1, CONST_ENTER_NOT_IN_THIS_MONTH_S_LIBERAL_GUARDIAN);
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
  /* monthly - guardian - prints liberal guardian special editions */
// return whether printing counts as treason
  extern map<string, AbstractStory> specialEditionStories;
  bool printnews(short li, short newspaper) {

	  music.play(MUSIC_NEWSPAPER);
	  if (lawList[LAW_FREESPEECH] == -2)offended_firemen = 1;
	  eraseAlt();
	  set_color_easy(WHITE_ON_BLACK_BRIGHT);

	  bool treason = false;

	  AbstractStory abStory = specialEditionStories[LootTypePool::getInstance().getIdName(li)]; //Find the special edition in question
	  int y = 6;
	  
	  mvaddstrAlt(y++, 1, abStory.intro, gamelog);
	  abStory.pickStory();

	  for (int i = 0; i < len(abStory.getStory()); i++) {
		  mvaddstrAlt(y++, 1, abStory.getStory()[i], gamelog);
	  }

	  if (abStory.hasTag(ENUM_tag_MAJOR_NEWS)) {
		  mvaddstrAlt(y++, 1, major_news_take_it_up, gamelog);
	  }
	  if (abStory.hasTag(ENUM_tag_OFFEND_CORPS)) {
		  mvaddstrAlt(y++, 1, THIS_IS_BOUND_TO_RILE_UP_CORPS, gamelog);
		  offended_corps = 1;
	  }	
	  if (abStory.hasTag(ENUM_tag_OFFEND_CIA)) {
		  mvaddstrAlt(y++, 1, CONST_THIS_IS_BOUND_TO_GET_THE_GOVERNMENT_A_LITTLE_RILED_UP, gamelog);
		  offended_cia = 1;
	  }	  
	  if (abStory.hasTag(ENUM_tag_OFFEND_CABLE)) {
		  mvaddstrAlt(y++, 1, CONST_THIS_IS_BOUND_TO_GET_THE_CONSERVATIVE_MASSES_A_LITTLE_RILED_UP, gamelog);
		  offended_cablenews = 1;
	  }	
	  if (abStory.hasTag(ENUM_tag_OFFEND_AMRADIO)) {
		  mvaddstrAlt(y++, 1, CONST_THIS_IS_BOUND_TO_GET_THE_CONSERVATIVE_MASSES_A_LITTLE_RILED_UP, gamelog);
		  offended_amradio = 1;
	  }	
	  if (abStory.hasTag(ENUM_tag_EXPOSE_CCS)) {
		  ccsexposure = CCSEXPOSURE_EXPOSED;
	  }
	  if (abStory.hasTag(ENUM_tag_TREASONOUS)) {
		  treason = true;
	  }
	  vector<tuple<Views, int, bool> > impactOnViews = abStory.getViews();

	  for (int i = 0; i < len(impactOnViews); i++) {
		  tuple<Views, int, bool> nextView = impactOnViews[i];
		  change_public_opinion(get<0>(nextView), get<1>(nextView) * (get<2>(nextView) ? newspaper : 1));

	  }
	  pressAnyKey();
	  return treason;
  }

  void printIncomeTypes(const int y, const int i) {
	  set_color_easy(WHITE_ON_BLACK);
	  mvaddstrAlt(y, 0, dotdotdot);
	  set_color_easy(GREEN_ON_BLACK);
	  string num = PLUS_DOLLAR + tostring(ledger.income[i]);
	  mvaddstrAlt(y, 60 - len(num), num);
	  if (ledger.dailyIncome[i])
		  num = PAREN_PLUS_DOLLAR + tostring(ledger.dailyIncome[i]) + CLOSE_PARENTHESIS;
	  else
	  {
		  set_color_easy(WHITE_ON_BLACK);
		  num = DOLLAR_ZERO;
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
	  string num = MINUS_DOLLAR + tostring(ledger.expense[i]);
	  mvaddstrAlt(y, 60 - len(num), num);
	  if (ledger.dailyExpense[i])
		  num = PAREN_MINUS_DOLLAR + tostring(ledger.dailyExpense[i]) + CLOSE_PARENTHESIS;
	  else
	  {
		  set_color_easy(WHITE_ON_BLACK);
		  num = DOLLAR_ZERO;
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
	  mvaddstrAlt(y, 0, CONST_NET_CHANGE_THIS_MONTH_DAY);
	  if (totalmoney > 0) { set_color_easy(GREEN_ON_BLACK_BRIGHT); num = CONST_X_PLUS_SIGN; }
	  else if (totalmoney < 0) { set_color_easy(RED_ON_BLACK_BRIGHT); num = CONST_X_MINUS_SIGN; }
	  else { set_color_easy(WHITE_ON_BLACK_BRIGHT); num = ""; }
	  num += DOLLAR_SIGN + tostring(abs(totalmoney));
	  mvaddstrAlt(y, 60 - len(num), num);
	  if (dailymoney > 0)
	  {
		  set_color_easy(GREEN_ON_BLACK_BRIGHT);
		  num = PAREN_PLUS_DOLLAR + tostring(abs(dailymoney)) + CLOSE_PARENTHESIS;
	  }
	  else if (dailymoney < 0)
	  {
		  set_color_easy(RED_ON_BLACK_BRIGHT);
		  num = PAREN_MINUS_DOLLAR + tostring(abs(dailymoney)) + CLOSE_PARENTHESIS;
	  }
	  else
	  {
		  set_color_easy(WHITE_ON_BLACK_BRIGHT);
		  num = DOLLAR_ZERO;
	  }
	  mvaddstrAlt(y, 73 - len(num), num);
  }
  void printLedgerPage(const int y, const string lcsmonthly, const long get_funds) {
	  string num = DOLLAR_SIGN + tostring(get_funds);
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
		  mvaddstrAlt(0, 0, CONST_LIBERAL_CRIME_SQUAD_FUNDING_REPORT);
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
			  printLedgerPage(y, CONST_CASH, ledger.get_funds());
		  }
		  if (++y >= 23) y = 2, numpages++;
		  if (page == numpages - 1)
		  {
			  printLedgerPage(y, CONST_TOOLS_AND_WEAPONS, weaponValue);
		  }
		  if (++y >= 23) y = 2, numpages++;
		  if (page == numpages - 1)
		  {
			  printLedgerPage(y, CONST_CLOTHING_AND_ARMOR, armorValue);
		  }
		  if (++y >= 23) y = 2, numpages++;
		  if (page == numpages - 1)
		  {
			  printLedgerPage(y, CONST_AMMUNITION, clipValue);
		  }
		  if (++y >= 23) y = 2, numpages++;
		  if (page == numpages - 1)
		  {
			  printLedgerPage(y, CONST_MISCELLANEOUS_LOOT, lootValue);
		  }
		  if (++y >= 23) y = 2, numpages++;
		  if (page == numpages - 1) makedelimiter(y);
		  if (++y >= 23) y = 2, numpages++;
		  if (page == numpages - 1)
		  {
			  set_color_easy(WHITE_ON_BLACK_BRIGHT);
			  mvaddstrAlt(y, 0, CONST_TOTAL_LIQUID_ASSETS);
			  long netWorth = ledger.get_funds() + weaponValue + armorValue + clipValue + lootValue;
			  set_color_easy(netWorth ? GREEN_ON_BLACK_BRIGHT : WHITE_ON_BLACK_BRIGHT);
			  string num = DOLLAR_SIGN + tostring(netWorth);
			  mvaddstrAlt(y, 60 - len(num), num);
		  }
		  set_color_easy(WHITE_ON_BLACK);
		  if (numpages > 1)
		  {
			  mvaddstrAlt(24, 0, CONST_PRESS_ENTER_TO_REFLECT_ON_THE_REPORT + addpagestr());
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
			  mvaddstrAlt(24, 0, CONST_PRESS_ANY_KEY_TO_REFLECT_ON_THE_REPORT);
			  pressAnyKey();
			  music.play(MUSIC_PREVIOUS);
			  return;
		  }
	  }
  }