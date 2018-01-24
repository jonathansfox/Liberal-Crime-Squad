
#include <includes.h>


#include "common/consolesupport.h"
// for void set_color(short,short,bool)

#include "log/log.h"
// for commondisplay.h
#include "common/commondisplay.h"
// for addchar

#include "common/getnames.h"
// for std::string getmonth

#include "daily/daily.h"
//for int monthday();


#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
extern unsigned char newstops[6][80][5][4];
extern int day;
extern int month;
extern int year;
extern string singleSpace;
extern string commaSpace;
void preparepage(newsstoryst& ns, bool liberalguardian)
{
   set_color(COLOR_WHITE,COLOR_WHITE,0);
   for(int x=0;x<80;x++)
      for(int y=0;y<25;y++)
         mvaddcharAlt(y,x,' ');
   set_color_easy(WHITE_ON_BLACK);
   if(ns.page==1||(liberalguardian&&ns.guardianpage==1))
   {
      //TOP
      int pap=LCSrandom(5);
      for(int x=0;x<80;x++)
      {
         for(int y=0;y<5;y++)
         {
            if(liberalguardian)
            {
               set_color(translateGraphicsColor(newstops[5][x][y][1]),
                         translateGraphicsColor(newstops[5][x][y][2]),
                         newstops[5][x][y][3]);
			   mvaddcharAlt(y,x, newstops[5][x][y][0]);
            }
            else
            {
               set_color(translateGraphicsColor(newstops[pap][x][y][1]),
                         translateGraphicsColor(newstops[pap][x][y][2]),
                         newstops[pap][x][y][3]);
			   mvaddcharAlt(y,x, newstops[pap][x][y][0]);
            }
         }
      }
      if(!liberalguardian) // Liberal Guardian graphics don't support adding a date
      {
         //DATE
         set_color(COLOR_BLACK,COLOR_WHITE,0);
         int pday=day, pmonth=month, pyear=year;
         if(pday>monthday()) // Day counter has increased but end-of-month has not yet
         {                   // been checked so it has to be accounted for here.
            pday=1,pmonth++;
            if(pmonth>12) pmonth=1,pyear++;
         }
         mvaddstrAlt(3,66+(pday<10), getmonth(pmonth,true));
         addstrAlt(singleSpace);
         addstrAlt(pday);
         addstrAlt(commaSpace);
         addstrAlt(pyear);
      }
   }
   else
   {
      //PAGE
      set_color(COLOR_BLACK,COLOR_WHITE,0);
      mvaddstrAlt(0,76, liberalguardian ? ns.guardianpage : ns.page);
   }
}
