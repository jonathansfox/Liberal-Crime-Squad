#ifndef ITEM_TYPE_POOL
#define ITEM_TYPE_POOL
class ItemTypePool {
public:
	virtual const int lenpool() = 0;
	virtual void delete_and_clear_pool() = 0;
};
#endif