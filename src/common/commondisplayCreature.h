
/* character info at top of screen */
void printcreatureinfo(Creature *cr, unsigned char knowledge = 255);
/* full screen character sheet, just skills */
void printliberalskills(Creature &cr);
/* full screen character sheet */
void printliberalstats(Creature &cr);
/* Full screen character sheet, crime sheet */
void printliberalcrimes(Creature &cr);
/* prints a character's general health description (One Leg, Liberal, NearDETH...) */
void printhealthstat(Creature &g, int y, int x, char smll);
/* prints a character's health description for each bodypart (Head, Body...) */
void printwoundstat(Creature &cr, int y, int x);