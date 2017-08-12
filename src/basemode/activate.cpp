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
#include <externs.h>
#include "common\\customMaps.h"


extern vector<ActivityAndString> data_lessons;
extern ActivityToData data_activities;
extern charToVector activate_menu_items;
extern vector<recruitData> recruitable_creatures;



vector<Creature *> activatable_liberals()
{
   vector<Creature *> temppool;
   for (int p = 0; p < len(pool); p++)
   {
	   if (pool[p]->is_active_liberal())
	   {
		   if (pool[p]->squadid != -1)
		   {
			   int sq = getsquad(pool[p]->squadid);
			   if (sq != -1) if (squad[sq]->activity.type != ACTIVITY_NONE) continue;
		   }
		   temppool.push_back(pool[p]);
	   }
   }
   return temppool;
}

/* base - activate the uninvolved */
void activate()
{
   vector<Creature *> temppool = activatable_liberals();

   if(!len(temppool)) return;

   sortliberals(temppool,activesortingchoice[SORTINGCHOICE_ACTIVATE]);

   int page=0;

   while(true)
   {
      music.play(MUSIC_ACTIVATE);
      erase();

      set_color(COLOR_WHITE,COLOR_BLACK,0);
      printfunds();

      mvaddstr(0,0, "Activate Uninvolved Liberals");
      mvaddstr(1,0, "ÄÄÄÄCODE NAMEÄÄÄÄÄÄÄÄÄÄÄÄSKILLÄÄÄHEALTHÄÄÄLOCATIONÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
      mvaddstr(1,57,"ACTIVITY");

      int y=2;
      for(int p=page*19;p<len(temppool)&&p<page*19+19;p++,y++)
      {
         set_color(COLOR_WHITE,COLOR_BLACK,0);
         move(y,0);
         addchar(y+'A'-2);addstr(" - ");
         addstr(temppool[p]->name);

         char bright=0;
         int skill=0;
         for(int sk=0;sk<SKILLNUM;sk++)
         {
            skill+=temppool[p]->get_skill(sk);
            if(temppool[p]->get_skill_ip(sk)>=100+(10*temppool[p]->get_skill(sk))&&
               temppool[p]->get_skill(sk)<temppool[p]->skill_cap(sk,true))bright=1;
         }

         set_color(COLOR_WHITE,COLOR_BLACK,bright);

         mvaddstr(y,25, skill);

         printhealthstat(*temppool[p],y,33,TRUE);

         if(mode==REVIEWMODE_JUSTICE)set_color(COLOR_YELLOW,COLOR_BLACK,1);
         else set_color(COLOR_WHITE,COLOR_BLACK,0);
         mvaddstr(y,42, location[temppool[p]->location]->getname(true, true));

         move(y,57);
         // Let's add some color here...
         set_activity_color(temppool[p]->activity.type);
         addstr(getactivity(temppool[p]->activity));
      }

      set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(22,0, "Press a Letter to Assign an Activity.");
      move(23,0);
      addpagestr();
      addstr(" T to sort people.");
      mvaddstr(24,0, "Press Z to assign simple tasks in bulk.");

      int c=getkey();

      //PAGE UP
      if((c==interface_pgup||c==KEY_UP||c==KEY_LEFT)&&page>0) page--;
      //PAGE DOWN
      if((c==interface_pgdn||c==KEY_DOWN||c==KEY_RIGHT)&&(page+1)*19<len(temppool)) page++;

      if(c>='a'&&c<='s')
      {
         int p=page*19+c-'a';
         if(p<len(temppool)) activate(temppool[p]);
      }

      if(c=='t')
      {
         sorting_prompt(SORTINGCHOICE_ACTIVATE);
         sortliberals(temppool,activesortingchoice[SORTINGCHOICE_ACTIVATE],true);
      }

      if(c=='z') activatebulk();

      if(c=='x'||c==ENTER||c==ESC||c==SPACEBAR) break;
   }
}

// These two functions handle listing and updating class choices
int classlist=0;
void listclasses(Creature *cr)
{
	set_color(COLOR_WHITE,COLOR_BLACK,0);
	mvaddstr(10,40, "Classes cost $60 a day. Study what?");
	for (int i = 0; i < 5; ++i)
	{
		if (i + classlist < len(data_lessons))
		{
			set_color(COLOR_WHITE, COLOR_BLACK, cr->activity.type == data_lessons[i + classlist].activity);
			mvaddstr(12 + i, 40, to_string(i + 1).c_str());
			addstr(" - "); addstr(data_lessons[i + classlist].str);
		}
	}
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
	mvaddstr(17, 40, "6 - Other classes");
}

void updateclasschoice(Creature *cr, char choice)
{
	if (choice >= '1' && choice <= '5')
	{
		if (choice - '1' + classlist < len(data_lessons))
			cr->activity.type = data_lessons[choice - '1' + classlist].activity;
		listclasses(cr);
	}
	else if (choice == '6')
	{
		classlist += 5;
		if (classlist >= len(data_lessons))
			classlist = 0;
		listclasses(cr);
	}
}

void activate(Creature *cr)
{
   int hostagecount=0,state=0,oldstate=0,choice=0;
   char havedead=0;
   for(int p=0;p<len(pool);p++)
   {
      if(pool[p]->alive&&pool[p]->align!=1&&pool[p]->location==cr->location) hostagecount++;
      if(!pool[p]->alive) havedead=1;
   }

   while(true)
   {
      erase();

      set_color(COLOR_WHITE,COLOR_BLACK,0);
      printfunds();

      move(0,0);
      if(cr->income)
      {
         addstr(cr->name);
         addstr(" made $");
         addstr(cr->income);
         addstr(" yesterday. What now?");
      }
      else
      {
         addstr("Taking Action: What will ");
         addstr(cr->name);
         addstr(" be doing today?");
      }

      printcreatureinfo(cr);

      makedelimiter();

      data_activity activity = data_activities[(Activity)cr->activity.type];
	  if(!state) 
	  {
	     if(activity.key != 'x')
		    state = activity.key;
	  }
      oldstate=state;

      set_color(COLOR_WHITE,COLOR_BLACK,state=='a');
      mvaddstr(10,1,"A - Engaging in Liberal Activism");

      set_color(COLOR_WHITE,COLOR_BLACK,state=='b');
      mvaddstr(11,1,"B - Legal Fundraising");

      set_color(COLOR_WHITE,COLOR_BLACK,state=='c');
      mvaddstr(12,1,"C - Illegal Fundraising");

      set_color(COLOR_WHITE,COLOR_BLACK,state=='d');
      mvaddstr(13,1,"D - Recruitment and Acquisition");

      set_color(COLOR_WHITE,COLOR_BLACK,state=='t');
      mvaddstr(14,1,"T - Teaching Other Liberals");

      if(hostagecount>0)set_color(COLOR_WHITE,COLOR_BLACK,state=='i');
      else set_color(COLOR_BLACK,COLOR_BLACK,1);
      mvaddstr(15,1,"I - Tend to a Conservative hostage");

      set_color(COLOR_WHITE,COLOR_BLACK,state=='l');
      mvaddstr(16,1,"L - Learn in the University District");

      if(clinictime(*cr)) set_color(COLOR_WHITE,COLOR_BLACK,state=='m');
      else set_color(COLOR_BLACK,COLOR_BLACK,1);
      mvaddstr(17,1,"M - Move to the Free Clinic");

      if(cr->get_skill(SKILL_FIRSTAID)!=0)
         set_color(COLOR_WHITE,COLOR_BLACK,state=='h');
      else
         set_color(COLOR_BLACK,COLOR_BLACK,1);
      mvaddstr(18,1,"H - Heal Liberals");

      if(havedead)set_color(COLOR_WHITE,COLOR_BLACK,state=='z');
      else set_color(COLOR_BLACK,COLOR_BLACK,1);
      mvaddstr(19,1,"Z - Dispose of bodies");

      siegest *siege=NULL;
      if(selectedsiege!=-1) siege=&location[selectedsiege]->siege;
      if(activesquad) if(activesquad->squad[0]->location!=-1) siege=&location[activesquad->squad[0]->location]->siege;
      char sieged=0;
      if(siege) sieged=siege->siege;
      /*char underattack=0;
      if(siege&&sieged) underattack=siege->underattack;*/

      if(!sieged)
         set_color(COLOR_WHITE,COLOR_BLACK,0);
      else
         set_color(COLOR_BLACK,COLOR_BLACK,1);
      mvaddstr(20,1,"E - Equip this Liberal");

      if(state=='a'||state=='b'||state=='c'||state=='d')
      {
         set_color(COLOR_WHITE,COLOR_BLACK,0);
         mvaddstr(19,40,"? - Help");
      }

      set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(20,40,"Enter - Confirm Selection");

      set_color(COLOR_WHITE,COLOR_BLACK,state=='x');
      mvaddstr(21,1,"X - Nothing for Now");

	  addchar(state);

 	  if(state == 'l')
	  {
         listclasses(cr);
	  }
	  else
	  {
		  int ypos = 10;
		  for (ActivityAndString current_item : activate_menu_items[state]) {
			  set_color(COLOR_WHITE, COLOR_BLACK, cr->activity.type == current_item.activity);
			  move(ypos, 40);
			  if (current_item.i > 0)
			  {
				  addstr(current_item.i);
				  addstr(" - ");
			  }
			  ypos++;
			  string outputString;
			  if (current_item.skill == SKILLNUM) { outputString = current_item.str; }
			  else {
				  if (cr->get_skill(current_item.skill) >= 8) { outputString = current_item.str3; }else 
					  if (cr->get_skill(current_item.skill) >= 4) { outputString = current_item.str2; }
					  else {
						  outputString = current_item.str;
					  }

			  }
			  addstr(outputString);
		  }
	  }

	  set_color(COLOR_WHITE, COLOR_BLACK, 0);
	  move(22, 3);
	  if (activity.show_name)
	  {
		  addstr(cr->name); 
		  addstr(" will ");
	  }
	  addstr(activity.lineAttempt(0, cr));
	  mvaddstr(23, 1, activity.lineAttempt(1, cr));
	  mvaddstr(24, 1, activity.lineAttempt(2, cr));

      int c=getkey();

      if(c>='a'&&c<='z') state=c;
      if((c>='a'&&c<='z') || (c>='0'&&c<='9'))
      {
         choice=c;

         switch(state)
         {
         case 'a':
            switch(choice)
            {
            case '1':
            case '2':
            case '4':
            //case '5':cr->activity.type=ACTIVITY_DOS_ATTACKS;
            case '5':
            case '6':
				cr->activity.type = activate_menu_items['a'][choice - '1'].activity;
				break;
			case '3':cr->activity.type = ACTIVITY_GRAFFITI;
				cr->activity.arg = -1;
				break;
            case '7':
               if(cr->location!=-1&&
                  location[cr->location]->compound_walls & COMPOUND_PRINTINGPRESS)
               {
                  cr->activity.type=ACTIVITY_WRITE_GUARDIAN;break;
               }
            default:
               if(cr->get_attribute(ATTRIBUTE_WISDOM,true)>7||cr->juice<0)
                  cr->activity.type=ACTIVITY_COMMUNITYSERVICE;
               else if(cr->get_attribute(ATTRIBUTE_WISDOM,true)>4)
                  cr->activity.type=ACTIVITY_TROUBLE;
               else
               {
                  if(cr->get_skill(SKILL_COMPUTERS)>2)
                     cr->activity.type=ACTIVITY_HACKING;
                  else if(cr->get_skill(SKILL_ART)>1)
                  {
                     cr->activity.type=ACTIVITY_GRAFFITI;
                     cr->activity.arg=-1;
                  }
                  else
                     cr->activity.type=ACTIVITY_TROUBLE;
               }
            }
            break;
         case 'b':
            switch(choice)
            {
            case '1':
            case '2':
            case '3':
            case '4':
				cr->activity.type = activate_menu_items['b'][choice - '1'].activity;
				break;
            default:
               if(cr->get_weapon().is_instrument())
                  cr->activity.type=ACTIVITY_SELL_MUSIC;
               else if(cr->get_skill(SKILL_ART)>1)
                  cr->activity.type=ACTIVITY_SELL_ART;
               else if(cr->get_skill(SKILL_TAILORING)>1)
                  cr->activity.type=ACTIVITY_SELL_TSHIRTS;
               else if(cr->get_skill(SKILL_MUSIC)>1)
                  cr->activity.type=ACTIVITY_SELL_MUSIC;
               else cr->activity.type=ACTIVITY_DONATIONS;
            }
            break;
         case 'c':
            switch(choice)
            {
            case '1':
            case '3':
            //case '4':cr->activity.type=ACTIVITY_DOS_RACKET;break;
				cr->activity.type = activate_menu_items['c'][choice - '1'].activity;
				break;

			case '2':
#ifndef ZEROMORAL
				if (cr->age >= 18)
#endif
					cr->activity.type = ACTIVITY_PROSTITUTION; break;
            default:
               if(cr->get_skill(SKILL_COMPUTERS)>1)
                  cr->activity.type=ACTIVITY_CCFRAUD;
#ifndef ZEROMORAL
               else if(cr->get_skill(SKILL_SEDUCTION)>1 && cr->age >= 18)
#else
               else if(cr->get_skill(SKILL_SEDUCTION)>1)
#endif
                  cr->activity.type=ACTIVITY_PROSTITUTION;
               else cr->activity.type=ACTIVITY_SELL_DRUGS;
            }
            break;
         case 'd':
            switch(choice)
            {
            case '1': { // Pick type to recruit
               activityst oact=cr->activity;
               cr->activity.type=ACTIVITY_NONE;
               recruitSelect(*cr);
               if(cr->activity.type==ACTIVITY_RECRUITING) break;
               else cr->activity=oact;
               break; }
            case '2': { // Pick clothing to make
               activityst oact=cr->activity;
               cr->activity.type=ACTIVITY_NONE;
               select_makeclothing(cr);
               if(cr->activity.type==ACTIVITY_MAKE_ARMOR) break;
               else cr->activity=oact;
               break; }
            case '3':
				cr->activity.type = activate_menu_items['d'][choice - '1'].activity;
				break;
            case '4':
               if(cr->canwalk())
                  cr->activity.type=ACTIVITY_STEALCARS;
               else if(!(cr->flag & CREATUREFLAG_WHEELCHAIR))
                  cr->activity.type=ACTIVITY_WHEELCHAIR;
               break;
            case '5': {
               if(cr->get_skill(SKILL_SCIENCE)!=0) {
                  activityst oact=cr->activity;
                  cr->activity.type=ACTIVITY_NONE;
                  select_augmentation(cr);
                  if(cr->activity.type==ACTIVITY_AUGMENT) break;
                  else cr->activity=oact;
               }
               break; }
            }
            break;
         case 't':
            switch(choice)
            {
            case '1':
            case '2':
            case '3':
				// activate_menu_items['t'] starts its index at 0 with ACTIVITY_NONE, instead of starting at 1 the way the other maps do
				// This is a temporary fix as part of a move to basically remove switch(state) as well as switch(choice)
				cr->activity.type = activate_menu_items['t'][(choice - '1') + 1].activity;
				break;
            default:
               switch(cr->type)
               {
               // this first block are creatures with All Weapon Skills, Martial Arts, Dodge, and First Aid
               case CREATURE_ATHLETE:
               case CREATURE_BOUNCER: // for fighting skills
               case CREATURE_COP: // for fighting skills
               case CREATURE_CCS_ARCHCONSERVATIVE: // for fighting skills
               case CREATURE_CCS_MOLOTOV: // for fighting skills
               case CREATURE_CCS_SNIPER: // for fighting skills
               case CREATURE_CCS_VIGILANTE: // for fighting skills
               case CREATURE_DEATHSQUAD: // for fighting skills
               case CREATURE_DOCTOR: // for First Aid
               case CREATURE_FIREFIGHTER: // for fighting skills
               case CREATURE_GANGMEMBER: // for fighting skills
               case CREATURE_GANGUNIT: // for fighting skills
               case CREATURE_GUARDDOG:
               case CREATURE_GENETIC:
               case CREATURE_HARDENED_VETERAN: // for fighting skills
               case CREATURE_HICK:
               case CREATURE_MARTIALARTIST: // for fighting skills
               case CREATURE_MERC: // for fighting skills
               case CREATURE_MILITARYOFFICER: // for fighting skills
               case CREATURE_MILITARYPOLICE: // for fighting skills
               case CREATURE_MUTANT:
               case CREATURE_NURSE: // for First Aid
               case CREATURE_PRISONGUARD: // for fighting skills
               case CREATURE_SEAL: // for fighting skills
               case CREATURE_SECURITYGUARD: // for fighting skills
               case CREATURE_SOLDIER: // for fighting skills
               case CREATURE_SWAT: // for fighting skills
               case CREATURE_TANK: // fpr fighting skills
               case CREATURE_VETERAN: // for fighting skills
                  cr->activity.type=ACTIVITY_TEACH_FIGHTING;
                  break;
               // this second block are creatures with Computers, Security, Stealth, Disguise, Tailoring, Seduction, Psychology, & Driving
               case CREATURE_ACTOR: // for Disguise
               case CREATURE_AGENT: // for Driving & Psychology
               case CREATURE_AMATEURMAGICIAN:
               case CREATURE_BIKER: // for Driving
               case CREATURE_BUM:
               case CREATURE_CONSTRUCTIONWORKER: // for Driving
               case CREATURE_CRACKHEAD:
               case CREATURE_EDUCATOR: // for Psychology & Driving
               case CREATURE_FASHIONDESIGNER: // for Tailoring
               case CREATURE_GARBAGEMAN: // for Driving
               case CREATURE_HSDROPOUT:
               case CREATURE_LOCKSMITH: // for Security
               case CREATURE_MAILMAN:
               case CREATURE_PLUMBER:
               case CREATURE_PRISONER:
               case CREATURE_PROGRAMMER: // for Computers
               case CREATURE_PROSTITUTE: // for Seduction
               case CREATURE_PSYCHOLOGIST: // for Psychology
               case CREATURE_SECRET_SERVICE: // for Driving & Psychology
               case CREATURE_SEWERWORKER:
               case CREATURE_TAXIDRIVER: // for Driving
               case CREATURE_THIEF: // for Disguise, Security, & Stealth
               case CREATURE_TRUCKER: // for Driving
               case CREATURE_WORKER_FACTORY_CHILD:
               case CREATURE_WORKER_SERVANT:
               case CREATURE_WORKER_SWEATSHOP: // for Tailoring
                  cr->activity.type=ACTIVITY_TEACH_COVERT;
                  break;
               // this third block are creatures with Writing, Persuasion, Law, Street Sense, Science, Religion, Business, Music, & Art
               case CREATURE_AUTHOR: // for Writing & Persuasion
               case CREATURE_BANK_MANAGER: // for Business
               case CREATURE_BANK_TELLER:
               case CREATURE_CAMERAMAN: // for Art
               case CREATURE_CARSALESMAN: // for Business & Persuasion
               case CREATURE_CHEF:
               case CREATURE_CLERK:
               case CREATURE_COLLEGESTUDENT: // for Art, Music, Science, & Writing
               case CREATURE_CORPORATE_CEO: // for Business
               case CREATURE_CORPORATE_MANAGER: // for Business
               case CREATURE_CRITIC_ART: // for Writing, Persuasion, & Art
               case CREATURE_CRITIC_MUSIC: // for Writing, Persuasion, & Music
               case CREATURE_DANCER: // for Art & Music
               case CREATURE_ENGINEER: // for Science
               case CREATURE_FASTFOODWORKER:
			   case CREATURE_BAKER:
			   case CREATURE_BARISTA:
			   case CREATURE_BARTENDER:
			   case CREATURE_FOOTBALLCOACH: // for Persuasion
               case CREATURE_HAIRSTYLIST: // for Art
               case CREATURE_HIPPIE: // for Art & Music
               case CREATURE_JOURNALIST: // for Writing & Persuasion
               case CREATURE_JUDGE_CONSERVATIVE: // for Law & Writing
               case CREATURE_JUDGE_LIBERAL: // for Law & Writing
               case CREATURE_JUROR:
               case CREATURE_LANDLORD: // for Business
               case CREATURE_LAWYER: // for Law & Persuasion
               case CREATURE_MATHEMATICIAN: // for Science
               case CREATURE_MUSICIAN: // for Music
               case CREATURE_NEWSANCHOR:
               case CREATURE_NUN: // for Religion
               case CREATURE_OFFICEWORKER: // for Business
               case CREATURE_PAINTER: // for Art
               case CREATURE_PHOTOGRAPHER: // for Art
               case CREATURE_POLITICALACTIVIST: // for Persuasion, Law, & Writing
               case CREATURE_POLITICIAN: // for Law & Persuasion
               case CREATURE_PRIEST: // for Religion
               case CREATURE_RADIOPERSONALITY: // for Persuasion
               case CREATURE_RETIREE:
               case CREATURE_SCIENTIST_EMINENT: // for Science
               case CREATURE_SCIENTIST_LABTECH: // for Science
               case CREATURE_SCULPTOR: // for Art
               case CREATURE_SOCIALITE: // for Persuasion, Art, & Music
               case CREATURE_TEACHER:
               case CREATURE_TEENAGER:
               case CREATURE_TELEMARKETER: // for Persuasion
               case CREATURE_WORKER_FACTORY_NONUNION:
               case CREATURE_WORKER_FACTORY_UNION:
               case CREATURE_WORKER_JANITOR:
               case CREATURE_WORKER_SECRETARY: // for Writing
               case CREATURE_YOGAINSTRUCTOR:
               default:
                  cr->activity.type=ACTIVITY_TEACH_POLITICS;
                  break;
               }
               break;
            }
            break;
         case 'i':
            if(hostagecount>0)
            {
               activityst oact=cr->activity;
               cr->activity.type=ACTIVITY_NONE;
               select_tendhostage(cr);
               if(cr->activity.type==ACTIVITY_HOSTAGETENDING) break;
               else cr->activity=oact;
            }
            state=oldstate;
            break;
         case 'l':
            updateclasschoice(cr, choice);
            break;
         case 'm':
            if(clinictime(*cr)) cr->activity.type=ACTIVITY_CLINIC;
            else state=oldstate;
            break;
         case 'h':
            if(cr->get_skill(SKILL_FIRSTAID)) cr->activity.type=ACTIVITY_HEAL;
            else state=oldstate;
            break;
         case 'z':
            if(havedead) cr->activity.type=ACTIVITY_BURY;
            else state=oldstate;
            break;
         case 'e':
            if(!sieged)
            {
               //create a temp squad containing just this liberal
               int oldsquadid = cr->squadid;
               squadst *oldactivesquad = activesquad;
               activesquad=new squadst;
               strcpy(activesquad->name, "Temporary Squad");
               activesquad->id=cursquadid;
               activesquad->squad[0]=cr;
               cr->squadid = activesquad->id;
               //go to equipment screen
               equip(location[activesquad->squad[0]->location]->loot,-1);
               //once you're done, restore original squad status.
               delete activesquad;
               activesquad = oldactivesquad;
               cr->squadid = oldsquadid;
            }
            state=oldstate;
            break;
         /*case 'w':
            if(location[cr->location]->compound_walls==COMPOUND_PRINTINGPRESS)
            {
               activityst oact=cr->activity;
               cr->activity.type=ACTIVITY_NONE;
               if(select_view(cr,cr->activity.arg))
               {
                  cr->activity.type=ACTIVITY_WRITE_GUARDIAN;
                  break;
               }
               else cr->activity=oact;
            }
            state=oldstate;
            break;*/
         case 'x':
            cr->activity.type=ACTIVITY_NONE;
            break;
         default:
            state=oldstate;
            break;
         }
      }

      // Enter pressed
      if(c=='x'||c==ENTER||c==ESC||c==SPACEBAR) break;
      // ? Pressed
      if(c=='?')
         if(state=='a'||state=='b'||state=='c'||state=='d')
            HelpActivities(cr->activity.type); // Call activity help pages
   }
}


void activatebulk()
{
   vector<Creature *> temppool = activatable_liberals();

   if(!len(temppool)) return;

   int page=0,selectedactivity=0;

   while(true)
   {
      erase();

      set_color(COLOR_WHITE,COLOR_BLACK,0);
      printfunds();

      mvaddstr(0,0, "Activate Uninvolved Liberals");
      mvaddstr(1,0, "ÄÄÄÄCODE NAMEÄÄÄÄÄÄÄÄÄÄÄÄCURRENT ACTIVITYÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
      mvaddstr(1,51, "BULK ACTIVITY");

      if(selectedactivity==0) set_color(COLOR_WHITE,COLOR_BLACK,1);
      else set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(2,51, "1 - Liberal Activism");
      if(selectedactivity==1) set_color(COLOR_WHITE,COLOR_BLACK,1);
      else set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(3,51, "2 - Legal Fundraising");
      if(selectedactivity==2) set_color(COLOR_WHITE,COLOR_BLACK,1);
      else set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(4,51, "3 - Illegal Fundraising");
      if(selectedactivity==3) set_color(COLOR_WHITE,COLOR_BLACK,1);
      else set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(5,51, "4 - Checking Polls");
      if(selectedactivity==4) set_color(COLOR_WHITE,COLOR_BLACK,1);
      else set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(6,51, "5 - Stealing Cars");
      if(selectedactivity==5) set_color(COLOR_WHITE,COLOR_BLACK,1);
      else set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(7,51, "6 - Community Service");

      int y=2;
      for(int p=page*19;p<len(temppool)&&p<page*19+19;p++,y++)
      {
         set_color(COLOR_WHITE,COLOR_BLACK,0);
         move(y,0);
         addchar(y+'A'-2);addstr(" - ");
         addstr(temppool[p]->name);

         move(y,25);
         set_activity_color(temppool[p]->activity.type);
         addstr(getactivity(temppool[p]->activity));
         /*if(temppool[p]->activity.type==ACTIVITY_TROUBLE)
         {
         addstr(" ($");
         addstr(temppool[p]->activity.arg);
         addstr(")");
         }*/
      }

      set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(22,0, "Press a Letter to Assign an Activity.  Press a Number to select an Activity.");
      move(23,0);
      addpagestr();

      int c=getkey();

      //PAGE UP
      if((c==interface_pgup||c==KEY_UP||c==KEY_LEFT)&&page>0) page--;
      //PAGE DOWN
      if((c==interface_pgdn||c==KEY_DOWN||c==KEY_RIGHT)&&(page+1)*19<len(temppool)) page++;

      if(c>='a'&&c<='s')
      {
         int p=page*19+c-'a';
         if(p<len(temppool))
         {
            switch(selectedactivity)
            {
            case 0: //Activism
               if(temppool[p]->get_attribute(ATTRIBUTE_WISDOM,true)>7||temppool[p]->juice<0)
                  temppool[p]->activity.type=ACTIVITY_COMMUNITYSERVICE;
               else if(temppool[p]->get_attribute(ATTRIBUTE_WISDOM,true)>4)
                  temppool[p]->activity.type=ACTIVITY_TROUBLE;
               else
               {
                  if(temppool[p]->get_skill(SKILL_COMPUTERS)>2)
                     temppool[p]->activity.type=ACTIVITY_HACKING;
                  else if(temppool[p]->get_skill(SKILL_ART)>1)
                  {
                     temppool[p]->activity.type=ACTIVITY_GRAFFITI;
                     temppool[p]->activity.arg=-1;
                  }
                  else temppool[p]->activity.type=ACTIVITY_TROUBLE;
               }
               break;
            case 1: //Fundraising
               if(temppool[p]->get_weapon().is_instrument())
                  temppool[p]->activity.type=ACTIVITY_SELL_MUSIC;
               else if(temppool[p]->get_skill(SKILL_ART)>1)
                  temppool[p]->activity.type=ACTIVITY_SELL_ART;
               else if(temppool[p]->get_skill(SKILL_TAILORING)>1)
                  temppool[p]->activity.type=ACTIVITY_SELL_TSHIRTS;
               else if(temppool[p]->get_skill(SKILL_MUSIC)>1)
                  temppool[p]->activity.type=ACTIVITY_SELL_MUSIC;
               else temppool[p]->activity.type=ACTIVITY_DONATIONS;
               break;
            case 2: //Illegal Fundraising
               if(temppool[p]->get_skill(SKILL_COMPUTERS)>1)
                  temppool[p]->activity.type=ACTIVITY_CCFRAUD;
#ifndef ZEROMORAL
               else if(temppool[p]->get_skill(SKILL_SEDUCTION)>1 && temppool[p]->age >=18)
#else
               else if(temppool[p]->get_skill(SKILL_SEDUCTION)>1)
#endif
                  temppool[p]->activity.type=ACTIVITY_PROSTITUTION;
               else
                  temppool[p]->activity.type=ACTIVITY_SELL_DRUGS;
               break;
            case 3: //Check polls
               temppool[p]->activity.type=ACTIVITY_POLLS;
               break;
            case 4: //Steal cars
               temppool[p]->activity.type=ACTIVITY_STEALCARS;
               break;
            case 5: //Volunteer
               temppool[p]->activity.type=ACTIVITY_COMMUNITYSERVICE;
               break;
            }
         }
      }
      if(c>='1'&&c<='6')
         selectedactivity=c-'1';

      if(c=='x'||c==ENTER||c==ESC||c==SPACEBAR) break;
   }
}


/* base - activate - hostages */
void select_tendhostage(Creature *cr)
{
   vector<Creature *> temppool;

   for(int p=0;p<len(pool);p++)
   {
      if(pool[p]->align!=1&&
         pool[p]->alive&&
         pool[p]->location==cr->location)
      {
         temppool.push_back(pool[p]);
      }
   }

   if(!len(temppool))return;
   if(len(temppool)==1)
   {
      cr->activity.type=ACTIVITY_HOSTAGETENDING;
      cr->activity.arg=temppool[0]->id;
      return;
   }

   int page=0;

   while(true)
   {
      erase();

      set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(0,0, "Which hostage will ");
      addstr(cr->name);
      addstr(" be watching over?");
      mvaddstr(1,0, "ÄÄÄÄCODE NAMEÄÄÄÄÄÄÄÄÄÄÄÄSKILLÄÄÄHEALTHÄÄÄLOCATIONÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
      mvaddstr(1,57, "DAYS IN CAPTIVITY");

      int y=2;
      for(int p=page*19;p<len(temppool)&&p<page*19+19;p++,y++)
      {
         set_color(COLOR_WHITE,COLOR_BLACK,0);
         move(y,0);
         addchar(y+'A'-2);addstr(" - ");
         addstr(temppool[p]->name);

         char bright=0;
         int skill=0;
         for(int sk=0;sk<SKILLNUM;sk++)
         {
            skill+=temppool[p]->get_skill(sk);
            if(temppool[p]->get_skill_ip(sk)>=100+(10*temppool[p]->get_skill(sk))&&
               temppool[p]->get_skill(sk)<temppool[p]->skill_cap(sk,true))bright=1;
         }

         set_color(COLOR_WHITE,COLOR_BLACK,bright);

         mvaddstr(y,25, skill);

         printhealthstat(*temppool[p],y,33,TRUE);

         if(mode==REVIEWMODE_JUSTICE)set_color(COLOR_YELLOW,COLOR_BLACK,1);
         else set_color(COLOR_WHITE,COLOR_BLACK,0);
         mvaddstr(y,42,location[temppool[p]->location]->getname(true, true));

         set_color(COLOR_MAGENTA,COLOR_BLACK,1);
         mvaddstr(y,57, temppool[p]->joindays);
         addstr(" ");
         if(temppool[p]->joindays>1)addstr("Days");
         else addstr("Day");
      }

      set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(22,0, "Press a Letter to select a Conservative");
      move(23,0);
      addpagestr();

      int c=getkey();

      //PAGE UP
      if((c==interface_pgup||c==KEY_UP||c==KEY_LEFT)&&page>0) page--;
      //PAGE DOWN
      if((c==interface_pgdn||c==KEY_DOWN||c==KEY_RIGHT)&&(page+1)*19<len(temppool)) page++;

      if(c>='a'&&c<='s')
      {
         int p=page*19+(int)(c-'a');
         if(p<len(temppool))
         {
            cr->activity.type=ACTIVITY_HOSTAGETENDING;
            cr->activity.arg=temppool[p]->id;
            return;
         }
      }

      if(c=='x'||c==ENTER||c==ESC||c==SPACEBAR) break;
   }
}


long select_hostagefundinglevel(Creature *cr,Creature *hs)
{
   long flevel=-1;

   erase();

   set_color(COLOR_WHITE,COLOR_BLACK,0);
   printfunds();
   mvaddstr(0,0, "Select a Funding Level for this Operation:");

   mvaddstr(2,0, "A - Don't spend anything.  ");
   addstr(cr->name);
   addstr(" is just on watch duty.");

   mvaddstr(3,0, "B - Don't spend anything.  ");
   addstr(cr->name);
   addstr(" will turn the prisoner over time.");

   mvaddstr(4,0, "C - $20 per day.  Enough for some props.");

   mvaddstr(5,0, "D - $50 per day.  ");
   addstr(cr->name);
   addstr(" will go for a thrifty indoctrination.");

   mvaddstr(6,0, "E - $100 per day.  ");
   addstr(cr->name);
   addstr(" needs enough freedom to be creative.");

   mvaddstr(7,0, "F - $500 per day.  It is imperative that the Conservative be turned quickly.");

   mvaddstr(8,0, "K - This Conservative has become a liability and needs to be terminated.");

   mvaddstr(10,0, "Enter - On second thought, this isn't a job for ");
   addstr(cr->name);
   addstr(".");

   do
   {
      int c=getkey();

      if(c=='a')flevel=0;
      if(c=='b')flevel=1;
      if(c=='c')flevel=20;
      if(c=='d')flevel=50;
      if(c=='e')flevel=100;
      if(c=='f')flevel=500;
      if(c=='k')flevel=666;
      if(c=='x'||c==ENTER||c==ESC||c==SPACEBAR) break;
   } while(flevel==-1);

   return flevel;
}


// Return the difficulty of tracking this character type down, for the
// purpose of the activation menu. 0 is trivial, 10 is impossible.
int recruitFindDifficulty(int creatureType)
{
   for(int i=0; i<len(recruitable_creatures); i++)
      if(recruitable_creatures[i].type == creatureType)
         return recruitable_creatures[i].difficulty;
   return 10; // No recruitData; assume impossible to recruit
}

char* recruitName(int creatureType)
{
   for(int i=0; i<len(recruitable_creatures); i++)
      if(recruitable_creatures[i].type == creatureType)
         return recruitable_creatures[i].name;
   return (char*)"missingno";
}



void recruitSelect(Creature &cr)
{
   // Number of recruitable creatures
   int options = len(recruitable_creatures);
   for(int i=0; i<options; i++)
   {
      // Dynamic difficulty for certain creatures, recalculated each time the function is called
      if(recruitable_creatures[i].type == CREATURE_MUTANT)
      {
         if(law[LAW_NUCLEARPOWER] == -2 && law[LAW_POLLUTION] == -2)
            recruitable_creatures[i].difficulty = 2;
         else if(law[LAW_NUCLEARPOWER] == -2 || law[LAW_POLLUTION] == -2)
            recruitable_creatures[i].difficulty = 6;
         else
            recruitable_creatures[i].difficulty = 9;
      }
   }

   int page=0;
   while(true)
   {
      erase();
      set_color(COLOR_WHITE,COLOR_BLACK,1);
      mvaddstr(0,0, "What type of person will ");
      addstr(cr.name);
      addstr(" try to meet and recruit today?");
      set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(1,0, "ÄÄÄÄTYPEÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄDIFFICULTY TO ARRANGE MEETINGÄÄ");

      int y=2,difficulty;
      for(int p=page*19;p<options&&p<page*19+19;p++)
      {
         set_color(COLOR_WHITE,COLOR_BLACK,0);
         move(y,0);
         addchar(y+'A'-2);addstr(" - ");
         addstr(recruitable_creatures[p].name);

         move(y,49);
         difficulty=recruitable_creatures[p].difficulty;
		 displayDifficulty(difficulty);

         y++;
      }

      set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(22,0, "Press a Letter to select a Profession");
      move(23,0);
      addpagestr();

      int c=getkey();

      //PAGE UP
      if((c==interface_pgup||c==KEY_UP||c==KEY_LEFT)&&page>0)page--;
      //PAGE DOWN
      if((c==interface_pgdn||c==KEY_DOWN||c==KEY_RIGHT)&&(page+1)*19<options)page++;

      if(c>='a'&&c<='s')
      {
         int p=page*19+(int)(c-'a');
         if(p<options)
         {
            cr.activity.type = ACTIVITY_RECRUITING;
            cr.activity.arg = recruitable_creatures[p].type;
            break;
         }
      }

      if(c=='x'||c==ENTER||c==ESC||c==SPACEBAR) break;
   }

   return;
}

void show_victim_status(Creature *victim)
{
   set_color(COLOR_WHITE,COLOR_BLACK,0);
   mvaddstr(2,55,"Status:");
   printhealthstat(*victim,2,66,true);
   printwoundstat(*victim,4,55);
   set_color(COLOR_WHITE,COLOR_BLACK,0);
   mvaddstr(11,55,"Heart: ");mvaddstr(11,66,victim->get_attribute(ATTRIBUTE_HEART,true));
   mvaddstr(12,55,"Age: ");mvaddstr(12,66,victim->age);
}

vector<string>& split_string(const string &s, char delim, vector<string> &elems) {
   ostringstream oss;
   for(char c:s) {
      if(c==' ')
      {
         elems.push_back(oss.str());
         oss.str(string());
      }
      else if(c=='\n')
      {
         elems.push_back(oss.str());
         elems.push_back("");
         oss.str(string());
      }
      else oss<<c;
   }
   elems.push_back(oss.str());

   return elems;
}

void select_augmentation(Creature *cr) //TODO: Finish and general cleanup
{
   Creature *victim = 0;
   int culloc=cr->location;
   vector<Creature *> temppool;

   for(int p=0;p<len(pool);p++) {
      if(pool[p] == cr) continue;
      if(pool[p]->is_active_liberal() && (pool[p]->location==culloc))
      {
         temppool.push_back(pool[p]);
      }
   }

   int cur_step=0,page=0,c=0,aug_c=0;
   vector<AugmentType *> aug_type;
   AugmentType *selected_aug;

   while(true)
   {
      erase();

      int y,p;

      switch(cur_step) {

         case 0: //PAGE 0, selecting a liberal
         set_color(COLOR_WHITE,COLOR_BLACK,1);
         mvaddstr(0,0,"Select a Liberal to perform experiments on");
         set_color(COLOR_WHITE,COLOR_BLACK,0);
         mvaddstr(1,0,"ÄÄÄÄNAMEÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄHEALTHÄÄÄÄÄÄÄÄÄÄÄÄHEARTÄÄÄÄÄÄÄÄAGEÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
         for(p=page*19,y=2;p<len(temppool)&&p<page*19+19;p++,y++)
         {
            set_color(COLOR_WHITE,COLOR_BLACK,0); //c==y+'a'-2);
            move(y,0);
            addchar(y+'A'-2);addstr(" - ");
            addstr(temppool[p]->name);
            mvaddstr(y,49,temppool[p]->get_attribute(ATTRIBUTE_HEART,true));
            mvaddstr(y,62,temppool[p]->age);
            printhealthstat(*temppool[p],y,31,TRUE);
         }

         set_color(COLOR_WHITE,COLOR_BLACK,0);
         move(22,0);
         addstr("Press a Letter to select a Liberal");
         move(23,0);
         addpagestr();

         c = getkey();

         //PAGE UP
         if((c==interface_pgup||c==KEY_UP||c==KEY_LEFT)&&page>0)page--;
         //PAGE DOWN
         if((c==interface_pgdn||c==KEY_DOWN||c==KEY_RIGHT)&&(page+1)*19<len(temppool))page++;

         if(c>='a'&&c<='s')
         {
            int p=page*19+c-'a';
            if(p<len(temppool))
            {
               victim = temppool[p];
               cur_step = 1;
            }
            else
               victim = 0;
         }

         if(c=='x'||c==ESC||c==SPACEBAR||c==ENTER) return;

         break;



         case 1: //PAGE 1, selecting an augmentation
         set_color(COLOR_WHITE,COLOR_BLACK,1);
         mvaddstr(0,0,"Subject: ");
         set_color(COLOR_WHITE,COLOR_BLACK,0);
         addstr(victim->name);addstr(", ");addstr(gettitle(*victim));
         //mvaddstr(1,0,"ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");

         show_victim_status(victim);

         mvaddstr(2,1,"Select an Augmentation");
         for(p=page*19,y=4;p<AUGMENTATIONNUM&&p<page*19+19;p++,y++)
         {
            bool already_augmented = victim->get_augmentation(y-4).type!=-1;
            if(already_augmented) set_color(COLOR_BLACK,COLOR_BLACK,1);
            else set_color(COLOR_WHITE,COLOR_BLACK,aug_c==y+'a'-4);
            move(y,1);
            addchar(y+'A'-4);addstr(" - ");
            addstr(Augmentation::get_name(y-4));
         }

         if(aug_c>='a'&&aug_c<='e'&&c>='a'&&c<='e')
         {
            aug_type.clear();
            if(victim->get_augmentation(aug_c-'a').type==-1) //False if already augmented on that bodypart.
            {
               for(int x=0,y=5;x<augmenttype.size();x++)
               {
                  if(augmenttype[x]->get_type()==aug_c-'a'&&
                        (augmenttype[x]->get_max_age()==-1||victim->age<=augmenttype[x]->get_max_age())&&
                        (augmenttype[x]->get_min_age()==-1||victim->age>=augmenttype[x]->get_min_age())&&
                        augmenttype[x]->get_cost() <= ledger.get_funds())
                        //TODO: Make it so that if you don't have money, it just grays it out, not just not show it
                     aug_type.push_back(augmenttype[x]);
               }
            }
         }

         set_color(COLOR_WHITE,COLOR_BLACK,0);

         for(int x=0,y=4;x<aug_type.size();x++,y++)
         {
            //set_color(COLOR_WHITE,COLOR_BLACK,c==y+'1'-5);
            mvaddchar(y,26,y+'1'-4);addstr(" - ");
            addstr(aug_type[x]->get_name());
         }

         //Checks to see if valid input, and moves to next screen
         if(aug_c>='a'&&aug_c<='e'&&c>='1'&&c<='0'+aug_type.size())
         {
            cur_step=2;
            selected_aug=aug_type[c-'1'];
            break;
         }

         c = getkey();
         if(c>='a'&&c<='e') aug_c=c;
         else if(c==ESC)return;
         else if(c=='x'||c==SPACEBAR||c==ENTER) {cur_step=0;aug_type.clear();aug_c=0;}
         break;



         case 2: //PAGE 2, confirm your choices
         set_color(COLOR_WHITE,COLOR_BLACK,1);
         mvaddstr(0,0,"Subject: ");
         set_color(COLOR_WHITE,COLOR_BLACK,0);
         addstr(victim->name);addstr(", ");addstr(gettitle(*victim));

         set_color(COLOR_WHITE,COLOR_BLACK,1);
         mvaddstr(2,0,"Augmentation: ");
         set_color(COLOR_WHITE,COLOR_BLACK,0);
         addstr(selected_aug->get_name());

         show_victim_status(victim);

         set_color(COLOR_WHITE,COLOR_BLACK,1);
         mvaddstr(4, 0, "Effect: ");
         set_color(COLOR_WHITE,COLOR_BLACK,0);
         string selected_attribute = attribute_enum_to_string(selected_aug->get_attribute());
         addstr((char)(toupper(selected_attribute.at(0))) +
            selected_attribute.substr(1) +
            (selected_aug->get_effect() >= 0 ? " +" : " ") +
            tostring(selected_aug->get_effect()));

         set_color(COLOR_WHITE,COLOR_BLACK,1);
         mvaddstr(5, 0, "Chance at Success: ");
         int skills = cr->get_skill(SKILL_SCIENCE) + (cr->get_skill(SKILL_FIRSTAID)/2);
         int difficulty = selected_aug->get_difficulty();
         set_color(COLOR_WHITE, COLOR_BLACK, 0);
         addstr(to_string(100 * skills / difficulty));

         mvaddstr(7,0,"Description");
         set_color(COLOR_WHITE,COLOR_BLACK,0);
         mvaddstr(8,0,"ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");

         vector<string> desc;
         split_string(selected_aug->get_description(),' ',desc);

         int chars_left=50;
         int line = 9;
         for(int i=0;i<desc.size();i++)
         {
            if(desc[i].length()>50) continue;
            else if(desc[i] == "")
            {
               line++;
               chars_left=50;
               continue;
            }
            else if(chars_left<0||desc[i].length()>chars_left)
            {
               line++;
               chars_left=50;
               i--;
               continue;
            }
            else if(desc[i].length()<=chars_left)
            {
               mvaddstr(line,50-chars_left,desc[i]);
               chars_left-=(desc[i].length()+1);
            }
         }

         mvaddstr(23,1,"Are you sure? (y/n)");

         c = getkey();
         if(c=='y')
         {
            set_color(COLOR_WHITE,COLOR_BLACK,0);
            mvaddstr(23,1,"Press any key to return");
            move(21,1);

            int blood_saved = 10*cr->get_skill(SKILL_SCIENCE) + 15*cr->get_skill(SKILL_FIRSTAID);
            if(blood_saved>100) blood_saved = 100;
            victim->blood-=100 - blood_saved;

            if(skills < difficulty &&
               LCSrandom((100 * difficulty) / skills) < 100)
            {
               unsigned char* wound = nullptr;

               switch(selected_aug->get_type())
               {
               case AUGMENTATION_HEAD:
                  wound=&victim->wound[BODYPART_HEAD];
                  victim->blood-=100;
                  break;

               case AUGMENTATION_BODY:
                  wound=&victim->wound[BODYPART_BODY];
                  victim->blood-=100;
                  break;

               case AUGMENTATION_ARMS:
                  if(LCSrandom(2))
                     wound=&victim->wound[BODYPART_ARM_LEFT];
                  else
                     wound=&victim->wound[BODYPART_ARM_RIGHT];
                  victim->blood-=25;
                  break;

               case AUGMENTATION_LEGS:
                  if(LCSrandom(2))
                     wound=&victim->wound[BODYPART_LEG_LEFT];
                  else
                     wound=&victim->wound[BODYPART_LEG_RIGHT];
                  victim->blood-=25;
                  break;

               case AUGMENTATION_SKIN:
                  if(LCSrandom(2))
                     wound=&victim->wound[BODYPART_HEAD];
                  else
                     wound=&victim->wound[BODYPART_BODY];
                  victim->blood-=50;
                  break;
               }

               *wound|=WOUND_NASTYOFF;

               if(victim->blood>0)
               {
                  set_color(COLOR_RED,COLOR_BLACK,1);
                  addstr(string(victim->name)+" has been horribly disfigured", gamelog);
               }
            }

            else //It was successful... but not without some injuries
            {
               unsigned char* wound = nullptr;

               switch(selected_aug->get_type())
               {
               case AUGMENTATION_HEAD:
                  wound=&victim->wound[BODYPART_HEAD];
                  break;

               case AUGMENTATION_BODY:
                  wound=&victim->wound[BODYPART_BODY];
                  break;

               case AUGMENTATION_ARMS:
                  if(LCSrandom(2))
                     wound=&victim->wound[BODYPART_ARM_RIGHT];
                  else
                     wound=&victim->wound[BODYPART_ARM_LEFT];
                  break;

               case AUGMENTATION_LEGS:
                  if(LCSrandom(2))
                     wound=&victim->wound[BODYPART_LEG_RIGHT];
                  else
                     wound=&victim->wound[BODYPART_LEG_LEFT];
                  break;

               case AUGMENTATION_SKIN:
                  wound=&victim->wound[BODYPART_HEAD];
                  break;
               }

               *wound|=WOUND_BLEEDING;
               *wound|=WOUND_BRUISED;

               selected_aug->make_augment(victim->get_augmentation(selected_aug->get_type()));
               victim->adjust_attribute(selected_aug->get_attribute(), selected_aug->get_effect());
               cr->train(SKILL_SCIENCE,15);
               addjuice(*cr,10,1000);

               set_color(COLOR_GREEN,COLOR_BLACK,1);
               addstr(string(victim->name)+" has been augmented with "+selected_aug->get_name(), gamelog);
            }

            if(victim->blood<=0) //Lost too much blood, you killed 'em
            {
               set_color(COLOR_RED,COLOR_BLACK,1);
               victim->die();
               addstr(string(victim->name)+" has been brutally murdered by "+cr->name, gamelog);
            }

            gamelog.nextMessage();
            show_victim_status(victim);
            getkey();
            return;
         }

         else if(c==ESC)return;
         else if(c=='x'||c==SPACEBAR||c==ENTER||c=='n') {cur_step=1;selected_aug=nullptr;}
         break;
      }
   }
}
/* base - activate - make clothing */
void select_makeclothing(Creature *cr)
{
   vector<int> armortypei;
   for(int a=0;a<len(armortype);a++)
   {
      if(armortype[a]->get_make_difficulty() == 0)
         continue;

      if(armortype[a]->deathsquad_legality()
         && (law[LAW_POLICEBEHAVIOR]!=-2 || law[LAW_DEATHPENALTY]!=-2))
         continue;

      armortypei.push_back(a);
   }

   int page=0;

   while(true)
   {
      erase();

      set_color(COLOR_WHITE,COLOR_BLACK,1);
      mvaddstr(0,0, "Which will ");
      addstr(cr->name);
      addstr(" try to make?   (Note: Half Cost if you have cloth)");
      set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(1,0, "ÄÄÄÄNAMEÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄDIFFICULTYÄÄÄÄÄÄÄÄÄÄÄÄÄCOSTÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");

      int y=2,difficulty;
      for(int p=page*19;p<len(armortypei)&&p<page*19+19;p++,y++)
      {
         difficulty=armor_makedifficulty(*armortype[armortypei[p]],cr);
         if(difficulty<0) difficulty=0;

         set_color(COLOR_WHITE,COLOR_BLACK,0);
         move(y,0);
         addchar(y+'A'-2);addstr(" - ");
         addstr(armortype[armortypei[p]]->get_name());

         move(y,37);
		 displayDifficulty(difficulty);

         set_color(COLOR_GREEN,COLOR_BLACK,1);
         string price = '$'+tostring(armortype[armortypei[p]]->get_make_price());
         mvaddstr(y,64-len(price), price);
      }

      set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(22,0, "Press a Letter to select a Type of Clothing");
      move(23,0);
      addpagestr();

      int c=getkey();

      //PAGE UP
      if((c==interface_pgup||c==KEY_UP||c==KEY_LEFT)&&page>0)page--;
      //PAGE DOWN
      if((c==interface_pgdn||c==KEY_DOWN||c==KEY_RIGHT)&&(page+1)*19<len(armortypei))page++;

      if(c>='a'&&c<='s')
      {
         int p=page*19+c-'a';
         if(p<len(armortypei))
         {
            cr->activity.type=ACTIVITY_MAKE_ARMOR;
            cr->activity.arg=armortypei[p]; //Use id name of armor type instead? -XML
            return;
         }
      }

      if(c=='x'||c==ENTER||c==ESC||c==SPACEBAR) break;
   }
}

int armor_makedifficulty(Armor& type, Creature *cr)
{
   return armor_makedifficulty(*armortype[getarmortype(type.get_itemtypename())], cr);
}

int armor_makedifficulty(ArmorType& type,Creature *cr) //Make class method? -XML
{
   int basedif=type.get_make_difficulty()-cr->get_skill(SKILL_TAILORING)+3;
   return max(basedif,0);
}


/* base - activate - trouble */
long select_troublefundinglevel(Creature *cr)
{
   long flevel=-1;

   erase();

   set_color(COLOR_WHITE,COLOR_BLACK,0);
   printfunds();
   mvaddstr(0,0, "Select a Funding Level for this Operation:");

   mvaddstr(2,0, "A - Don't spend anything.  ");
   addstr(cr->name);
   addstr(" just needs something constructive to do.");

   mvaddstr(3,0, "B - $20 per day.  Some minor purchases are needed.");
   mvaddstr(4,0, "C - $50 per day.  Disobedience costs money.");
   mvaddstr(5,0, "D - $100 per day.  Enough to be really disobedient.");
   mvaddstr(6,0, "E - $500 per day.  The Machine will buckle under the weight of");
   
   mvaddstr(7,0, "    ");
   addstr(cr->name);
   addstr("'s Numerous and Varied Liberal Acts.");

   mvaddstr(9,0, "Enter - On second thought, this isn't a job for ");
   addstr(cr->name);
   addstr(".");

   do
   {
      int c=getkey();

      if(c=='a')flevel=0;
      if(c=='b')flevel=20;
      if(c=='c')flevel=50;
      if(c=='d')flevel=100;
      if(c=='e')flevel=500;
      if(c=='x'||c==ENTER||c==ESC||c==SPACEBAR) break;
   } while(flevel==-1);

   return flevel;
}



/* base - activate - select a topic to write about */
char select_view(Creature *cr,int &v)
{
   int page=0;

   while(true)
   {
      erase();

      set_color(COLOR_WHITE,COLOR_BLACK,1);
      mvaddstr(0,0, "Write a news story if the LCS makes the news on the selected topic today, or");
      mvaddstr(1,0, "write editorials if there is no current news but there is public interest.");
      set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(2,0, "ÄÄÄÄTOPICÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄINTERESTÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");

      int y=3,x=0;
      for(int p=page*18;p<VIEWNUM-3&&p<page*18+18;p++,y++)
      {
         set_color(COLOR_WHITE,COLOR_BLACK,0);
         move(y,x);
         addchar((p-page*18)+'A');addstr(" - ");
         addstr(getview(p,false));

         move(y,44);
         if(public_interest[p]>100)
         {
            set_color(COLOR_RED,COLOR_BLACK,1);
            addstr("Extremely Controversial");
         }
         else if(public_interest[p]>50)
         {
            set_color(COLOR_YELLOW,COLOR_BLACK,1);
            addstr("Dinner Table Topic");
         }
         else if(public_interest[p]>10)
         {
            set_color(COLOR_WHITE,COLOR_BLACK,1);
            addstr("Significant Interest");
         }
         else if(public_interest[p]>0)
         {
            set_color(COLOR_WHITE,COLOR_BLACK,0);
            addstr("Minor Discussion");
         }
         else
         {
            set_color(COLOR_BLACK,COLOR_BLACK,1);
            addstr("Exhausted");
         }
      }

      set_color(COLOR_WHITE,COLOR_BLACK,0);
      mvaddstr(22,0, "Press a Letter to select a Topic");
      move(23,0);
      addpagestr();

      int c=getkey();

      //PAGE UP
      if((c==interface_pgup||c==KEY_UP||c==KEY_LEFT)&&page>0) page--;
      //PAGE DOWN
      if((c==interface_pgdn||c==KEY_DOWN||c==KEY_RIGHT)&&(page+1)*16<VIEWNUM-3) page++;

      if(c>='a'&&c<='a'+18)
      {
         int p=page*18+c-'a';
         if(p<VIEWNUM-3)
         {
            v=p;
            return 1;
         }
      }

      if(c=='x'||c==ENTER||c==ESC||c==SPACEBAR) break;
   }

   return 0;
}