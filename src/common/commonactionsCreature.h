
/* common - tests if the person is a wanted criminal */
bool iscriminal(CreatureJustice cr);
/* common - sends somebody to the hospital */
//void hospitalize(int loc);
/* common - determines how long a creature's injuries will take to heal */
//int clinictime();
/* common - applies a crime to a person */
//void criminalize(short crime);
/* common - gives juice to a given creature */
//void add_juice(long juice, long cap);
/* common - removes the liberal from all squads */
//void removesquadinfo();
/* Determines the number of subordinates a creature may command */
//int maxsubordinates(
/* Determines the number of subordinates a creature may recruit,
based on their max and the number they already command */
//int subordinatesleft(
/* common - Sort a list of creatures.*/
void sortliberals(std::vector<DeprecatedCreature *>& liberals, short sortingchoice, bool dosortnone = false);
/* common - Functions used when sorting vectors of creatures. */
bool sort_none(const DeprecatedCreature* first, const DeprecatedCreature* second);

bool sort_locationandname(const DeprecatedCreature* first, const DeprecatedCreature* second);
bool sort_squadorname(const DeprecatedCreature* first, const DeprecatedCreature* second);
