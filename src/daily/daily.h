
void advanceday(char &clearformess, char canseethings);

/* promote a subordinate to maintain chain of command when boss is lost */
bool promotesubordinates(Creature &cr, char &clearformess);
/* daily - manages too hot timer and when a site map should be re-seeded and renamed */
void advancelocations();
/* daily - returns true if the site type supports high security */
char securityable(int type);

/* daily - returns the number of days in the current month */
int monthday();