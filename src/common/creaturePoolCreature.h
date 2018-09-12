void addCreature(DeprecatedCreature* cr);
void whoAreWaitingForRescue(vector<DeprecatedCreature *>& waiting_for_rescue, int cursite, short special);
DeprecatedCreature* findSleeperCarSalesman(int loc);
void findAllTendersToThisHostage(DeprecatedCreature* cr, vector<DeprecatedCreature *>& temppool);
void hostageEscapes(DeprecatedCreature* cr, char clearformess);
void setAllCreatureActivities(Activity cr, vector<DeprecatedCreature *>& temppool);
void selectOnlySleepersThatCanWork(vector<DeprecatedCreature *>& temppool);
vector<DeprecatedCreature *> activatable_liberals();
vector<DeprecatedCreature *> getLiberalsSharingLocation(DeprecatedCreature * cr);
vector<DeprecatedCreature *> getHostagesSharingLocation(DeprecatedCreature *cr);
int countHostagesSharingLocation(DeprecatedCreature *cr);
int countDeadSharingLocation(DeprecatedCreature *cr);
void dejuiceBoss(DeprecatedCreature &g);

DeprecatedCreature * getSleeperJudge(DeprecatedCreature g);
DeprecatedCreature * getSleeperLawyer(DeprecatedCreature g);
int otherPrisonersEscapeWithMe(DeprecatedCreature g, int prison);