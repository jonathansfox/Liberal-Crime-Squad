#ifndef MISC_H
#define MISC_H0

// brutally ripped from includes.h --Schmel924
/*
implementations should be in misc.cpp
*/
/* pick a descriptor acronym */
void sexdesc(char *str);
/* what kind of person? */
void sexwho(char *str);
/* seeking acronym */
void sexseek(char *str);
/* what type of sex? */
void sextype(char *str);
/* generate a vanity plate for the squad. */
//void vanity(char *str);
/* return a letter, number, or one of either. */
void chooseLetterOrNumber(char *str,int type);
/* generate a non-vanity plate for the squad. */
void plate(char *str);
/* name of a state (random state, by default) */
const char* statename(int state=-1);
/* EndGameStatus - converts an integer into a roman numeral for amendments */
std::string romannumeral(int amendnum);
/* code for bool Interval::set_interval(const string& interval); is also in misc.cpp */


#endif // MISC_H 