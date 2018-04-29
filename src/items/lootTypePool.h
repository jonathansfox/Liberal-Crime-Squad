class LootTypePool : ItemTypePool {
private:
	static bool lootTypePoolInitiated;
public:
	static LootTypePool getInstance();
	int lenpool();
	const string getIdName(int i);
	void delete_and_clear_pool();
	const string getName(const string& str);
};