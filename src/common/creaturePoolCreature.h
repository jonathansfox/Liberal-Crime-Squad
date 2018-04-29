void addCreature(Creature* cr);
void whoAreWaitingForRescue(vector<Creature *>& waiting_for_rescue, int cursite, short special);
Creature* findSleeperCarSalesman(int loc);
void findAllTendersToThisHostage(Creature* cr, vector<Creature *>& temppool);
void hostageEscapes(Creature* cr, char clearformess);
void setAllCreatureActivities(Activity cr, vector<Creature *>& temppool);
void selectOnlySleepersThatCanWork(vector<Creature *>& temppool);
vector<Creature *> activatable_liberals();
vector<Creature *> getLiberalsSharingLocation(Creature * cr);
vector<Creature *> getHostagesSharingLocation(Creature *cr);
int countHostagesSharingLocation(Creature *cr);
int countDeadSharingLocation(Creature *cr);
void dejuiceBoss(Creature &g);

Creature * getSleeperJudge(Creature g);
Creature * getSleeperLawyer(Creature g);
int otherPrisonersEscapeWithMe(Creature g, int prison);