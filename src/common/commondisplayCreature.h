
/* character info at top of screen */
void printcreatureinfo(DeprecatedCreature *cr, unsigned char knowledge = 255);
/* full screen character sheet, just skills */
void printliberalskills(DeprecatedCreature &cr);
/* full screen character sheet */
void printliberalstats(DeprecatedCreature &cr);
/* Full screen character sheet, crime sheet */
void printliberalcrimes(DeprecatedCreature &cr);
/* prints a character's general health description (One Leg, Liberal, NearDETH...) */
void printhealthstat(DeprecatedCreature &g, int y, int x, char smll);
/* prints a character's health description for each bodypart (Head, Body...) */
void printwoundstat(DeprecatedCreature &cr, int y, int x);