
class CreaturePool {
private:
	static bool creaturePoolInitiated;
	//CreaturePool();
public:
	void moveEverythingFrom(int cursite, int hs);
	void stop_riding_me(int id_);
	void stopAllBleeding();
	bool doesAnyoneLiveHere(int loc);
	void stop_preferring_me(int id_);
	void clearAllBleedingAndEscapeFlags();
	void outSleepers(int cursite, int base);
	void advanceCreaturesAtLocation(int cursite);
	void arrestOrKillCCSSleepers();
	int countLiberals(int cursite);
	static CreaturePool getInstance();
	int liberal_guardian_writing_power();
	int howManyLivingPeopleAreHere(int l);
	int lenpool();
	void delete_and_clear_pool();
	void setupDisband();
	bool isThisCarWantedByAnotherSquad(long vehicleID, int squadID);
	string getName(int p);
	void moveAllSquadMembers(int l);
};