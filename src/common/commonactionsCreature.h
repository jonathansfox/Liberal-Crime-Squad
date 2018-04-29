
/* tells how many total members a squad has (including dead members) */
int squadsize(const squadst *st);
/* tells how many members a squad has who are alive */
int squadalive(const squadst *st);

/* common - tests if the person is a wanted criminal */
bool iscriminal(Creature &cr);
/* common - sends somebody to the hospital */
void hospitalize(int loc, Creature &patient);
/* common - determines how long a creature's injuries will take to heal */
int clinictime(Creature &g);
/* common - applies a crime to a person */
void criminalize(Creature &cr, short crime);
/* common - gives juice to a given creature */
void addjuice(Creature &cr, long juice, long cap);
/* common - removes the liberal from all squads */
void removesquadinfo(Creature &cr);
/* Determines the number of subordinates a creature may command */
int maxsubordinates(const Creature& cr);
/* Determines the number of subordinates a creature may recruit,
based on their max and the number they already command */
int subordinatesleft(const Creature& cr);
// Determines the number of love slaves a creature has
int loveslaves(const Creature& cr);
/* Determines the number of loveslaves a creature may recruit,
based on their max and the number they already command */
int loveslavesleft(const Creature& cr);
// Determines the number of recruitment meetings a creature has scheduled
int scheduledmeetings(const Creature& cr);
// Determines the number of dates a creature has scheduled
int scheduleddates(const Creature& cr);
// Prompt to convert a new recruit into a sleeper
void sleeperize_prompt(Creature &converted, Creature &recruiter, int y);
/* common - Sort a list of creatures.*/
void sortliberals(std::vector<Creature *>& liberals, short sortingchoice, bool dosortnone = false);
/* common - Functions used when sorting vectors of creatures. */
bool sort_none(const Creature* first, const Creature* second);

bool sort_locationandname(const Creature* first, const Creature* second);
bool sort_squadorname(const Creature* first, const Creature* second);