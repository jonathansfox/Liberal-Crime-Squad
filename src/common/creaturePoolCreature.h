void addCreature(Creature* cr);
void whoAreWaitingForRescue(vector<Creature *>& waiting_for_rescue, int cursite, short special);
Creature* findSleeperCarSalesman(int loc);
void findAllTendersToThisHostage(Creature* cr, vector<Creature *>& temppool);
void hostageEscapes(Creature* cr, char clearformess);
void setAllCreatureActivities(Activity cr, vector<Creature *>& temppool);
void selectOnlySleepersThatCanWork(vector<Creature *>& temppool);