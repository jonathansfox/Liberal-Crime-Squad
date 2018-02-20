class LocationsPool {
private:
	static bool locationPoolInitiated;
public:
	static LocationsPool getInstance();
	int lenpool();
	void delete_and_clear_pool();
	bool isThereASiegeHere(int cursite);
	bool isThisPlaceHighSecurity(int cursite);
	void isThereASiegeHere(int cursite, bool newCondition);
	void isThisPlaceHighSecurity(int cursite, int newCondition);
	char getLocationType(int cursite);
	char getSiegeType(int cursite);
	char getSiegeEscalationState(int cursite);
	char getRentingType(int cursite);
	void initSite(int loc);
	void eraseAndReplaceGraffiti(int cursite, int locx, int locy, int locz);
	string getLocationName(int cursite);
	int getLocationCity(int cursite);
	void hideCCSSafehouses();
	void addHeat(int cursite, int heat);
	void findAllLootTypes(vector<bool>& havetype, vector<int>& loottypeindex, const vector<string> dox);
	bool isLocationMapped(int cursite);
	bool isLocationHidden(int cursite);
	void setLocationMappedAndUnhidden(int cursite);
	string getLocationNameWithGetnameMethod(int cursite, bool a, bool b);
	int getCompoundWalls(int cursite);
	void setTimeUntilSiege(int cursite, int time);
	bool isNewRental(int cursite);
	void evictLCSFrom(int l);
	bool isThisSiteClosed(int cursite);
	bool doesThisPlaceNeedACar(int cursite);
	int findTravelLocation();
	int getLocationParent(int cursite);
	int deleteSpecialItem(int slot, vector<int> loottypeindex);
	void getAssetValues(long & weaponValue, long & armorValue, long & clipValue, long & lootValue);
	bool canBeFortified(int cursite);
};
