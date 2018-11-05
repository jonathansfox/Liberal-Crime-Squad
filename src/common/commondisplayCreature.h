
/* full screen character sheet, just skills */
void printliberalskills(CreatureJustice cr, ListOfCreatureSkills cr_2);
//void printliberalstats(CreatureStats cr);
/* Full screen character sheet, crime sheet */
void printliberalcrimes(CreatureJustice cr);
/* prints a character's general health description (One Leg, Liberal, NearDETH...) */
void printhealthstat(CreatureHealth g, int y, int x, char smll);
/* prints a character's health description for each bodypart (Head, Body...) */
void printwoundstat(CreatureHealth cr, int y, int x);