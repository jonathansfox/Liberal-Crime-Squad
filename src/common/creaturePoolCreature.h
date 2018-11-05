void whoAreWaitingForRescue(vector<DeprecatedCreature *>& waiting_for_rescue, int cursite, short special);
DeprecatedCreature* findSleeperCarSalesman(int loc);
void setAllCreatureActivities(Activity cr, vector<DeprecatedCreature *>& temppool);
vector<DeprecatedCreature *> selectOnlySleepersThatCanWork();
vector<DeprecatedCreature *> activatable_liberals();
vector<DeprecatedCreature *> getLiberalsSharingLocation(DeprecatedCreature * cr);
vector<DeprecatedCreature *> getHostagesSharingLocation(DeprecatedCreature *cr);