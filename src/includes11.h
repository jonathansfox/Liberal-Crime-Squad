




/*
	File created by Chris Johnson.
	These were previously all in game.cpp.

	This file includes all the the enums, defines, and included headers required globally by all components.

	All code released under GNU GPL.
*/
#include <windows.h>
#include <vector>
#include <map>
#include <deque>
#include "cmarkup/Markup.h"
using namespace std;


const int BIT1 = (1 << 0);
const int BIT2 = (1 << 1);
const int BIT3 = (1 << 2);
const int BIT4 = (1 << 3);
const int BIT5 = (1 << 4);
const int BIT6 = (1 << 5);
const int BIT7 = (1 << 6);
const int BIT8 = (1 << 7);
const int BIT9 = (1 << 8);


const int MAX_PATH_SIZE = 2048;
const int RNG_SIZE = 4;

long LCSrandom(long max);

/* Determine size of vectors and any other container that implements the size() function.
This basically includes all types of containers except for the C++11 std::forward_list. */
template <class Container> inline long len(const Container& x)
{
	return x.size();
}
/* Determine array size in pickrandom() and various functions throughout the code.
Only works on actual arrays, not on vectors or other containers. */
template <typename T, size_t N> inline long len(const T(&x)[N])
{
	return N;
}
/* Override of the prior function for null-terminated C-strings as char arrays.
This override allows pickrandom() to pick a random character from a C-string we have as a char array. */
template <size_t N> inline long len(const char(&x)[N])
{
	return strlen(x);
}
/* Override of the prior function for null-terminated C-strings as char pointers.
This override allows pickrandom() to pick a random character from a C-string we have as a char pointer. */
inline long len(const char* x)
{
	return strlen(x);
}
/* Override for when it doesn't work with const in front of the char*
(compilers are weird about template function overrides) */
inline long len(char* x)
{
	return strlen(x);
}
/* Pick a random element from a vector/deque/map/std::string/C++11 std::array/etc. (e.g. a random string from a vector of strings).
It works on any container class that implements the [] operator, size() function, and value_type typename.
This doesn't work if the vector/deque/map/std::string/C++11 std::array/etc. has zero elements. */
template <class Container> inline typename Container::value_type& pickrandom(const Container& x)
{
	return const_cast<typename Container::value_type&>(x[LCSrandom(len(x))]);
}
/* Pick a random element from an array (e.g. a random string from an array of strings).
This doesn't work if the array has zero elements. */
template <typename T, size_t N> inline T& pickrandom(const T(&x)[N])
{
	return const_cast<T&>(x[LCSrandom(len(x))]);
}
/* Pick a random element from a C-string.
Returns '\x0' (null character) for empty string. */
inline char& pickrandom(const char* x)
{
	return const_cast<char&>(x[LCSrandom(len(x))]);
}
/* Override for when it doesn't work with const in front of the char*
(compilers are weird about template function overrides) */
inline char& pickrandom(char* x)
{
	return x[LCSrandom(len(x))];
}
/* Deletes a specified pointer and sets it to NULL. */
template <typename T> inline void delete_and_nullify(T* &o)
{
	delete o;
	o = NULL;
}
/* Deletes and removes a specified pointer from a container. */
template <class Container> inline void delete_and_remove(Container& c, int i)
{
	if (i <= -1) return; // check for invalid index, and don't delete anything in this case
	delete c[i];
	c.erase(c.begin() + i);
}
/* Deletes and removes a specified pointer from 2 containers it's in.
c1 and c2 must not be the same container! */
template <class Container> inline void delete_and_remove(Container& c1, int i1, Container& c2, int i2)
{
	if (i1 <= -1 || i2 <= -1) return; // check for invalid index, and don't delete anything in this case
	if (c1[i1] == c2[i2])
	{ // it's the same pointer, so just delete it once, then remove it from both containers
		delete_and_remove(c1, i1);
		if (c1 != c2 || i1 != i2) c2.erase(c2.begin() + i2); // remove it from 2nd location, unless 2nd location is identical to 1st location
	}
	else
	{ // it's 2 different pointers, so delete them both and remove them from both containers
		delete_and_remove(c1, i1);
		delete_and_remove(c2, i2);
	}
}
/* Deletes and removes all pointers in a container. */
template <class Container> inline void delete_and_clear(Container& c)
{
	while (len(c))
	{
		delete c.back();
		c.pop_back();
	}
}
/* Deletes and removes all pointers that 2 containers have in common. */
template <class Container> inline void delete_and_clear(Container& c1, Container& c2)
{
	for (int i1 = len(c1) - 1; i1 >= 0; i1--)
		for (int i2 = len(c2) - 1; i2 >= 0; i2--)
			if (c1[i1] == c2[i2]) delete_and_remove(c1, i1, c2, i2);
}

//#define CH_USE_CP437


const int ENTER = 10;
const int ESC = 27;
const int SPACEBAR = 32;




enum Laws
{
	LAW_STALIN = -2, // not a real law: this is -2 and is actually calculated based on views >=0 and <VIEWNUM-3
	LAW_MOOD, // not a real law: this is -1 and is likewise calculated based on views >=0 and <VIEWNUM-3
	LAW_ABORTION, // law #0, the first one that is actually in the law[] array
	LAW_ANIMALRESEARCH,
	LAW_POLICEBEHAVIOR,
	LAW_PRIVACY,
	LAW_DEATHPENALTY,
	LAW_NUCLEARPOWER,
	LAW_POLLUTION,
	LAW_LABOR,
	LAW_GAY,
	LAW_CORPORATE,
	LAW_FREESPEECH,
	LAW_FLAGBURNING,
	LAW_GUNCONTROL,
	LAW_TAX,
	LAW_WOMEN,
	LAW_CIVILRIGHTS,
	LAW_DRUGS,
	LAW_IMMIGRATION,
	LAW_ELECTIONS,
	LAW_MILITARY,
	LAW_PRISONS,
	LAW_TORTURE,
	LAWNUM
};

const int SQUAD_NAMELEN = 40;

//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

//int get_associated_attribute(int skill_type);



//#ifdef	SHOP_CPP
#include "bigListEnumTags.h"
// shop.cpp

#include "../creature/creature.h"
////

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../items/armortype.h"
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../items/loottype.h"
#include "../items/itemPool.h"
#include "../items/loottypePool.h"
#include "../items/loot.h"
#include "../sitemode/shop.h"
//own header 
#include "../common/stringconversion.h"
//for string conversion
#include "../common/commondisplay.h"
// for void printfunds(int,int,char*)
#include "../common/equipment.h"
//for void equip(vector<Item *> &loot,int loc);
#include "../common/translateid.h"
// for  int getweapontype
#include "../cursesAlternativeConstants.h"
#include "../common/musicClass.h"
#include <functional>

int getkeyAlt();

bool is_page_up(const int c);
bool is_page_down(const int c);
void pressAnyKey();

Item* getNewLoot(const string& newLootType, int num = 1);

void consolidateLoot(const int l);
string getLootTitle(const int base, const int l);
int getFenceValueLocation(int l, int slot);
int getLootNumber(const int base, const int l);
int getLocationLootNumber(int l, int slot);
bool getCanBeSoldLocation(int l, int slot);
void decreateLocationLoot(int loc, int loot, int num);
#include "locations/locationsPool.h"
void equipLoot(int l, int loc);
void deleteLocationLoot(int loc, int loot);
int whatIsThisItemInLocation(int loc, int l);
bool noQuickFenceLocation(int loc, int l);

extern class Ledger ledger;
extern short lawList[LAWNUM];
extern short party_status;
extern vector<ArmorType *> armortype;
extern vector<ClipType *> cliptype;
extern vector<Location *> location;
extern vector<WeaponType *> weapontype;

string asMoney(const int c);

void printBrowseHalfscreenHeader(const string cname);

void printShopOptions(const int y, const bool x, const char letter, const string description);
void printShopFooter(const int _y, const short party_status, const int partysize, const string exit_);
void printOptionsMiddle(const int _y, const bool sell_masks_, const bool left_side, const bool allow_selling_, const int loot);

void printMaskOptions(const int page, const string bname, const vector<int> masktype, const vector<string> mname, const vector<string> mdescription);
void printFenceAmount(const int fenceamount);
void printChooseALiberalTo();

void printReallySellAllThese(const char c);
void printSellLootHeader(const int loot, const int partysize, const short party_status);
void printCantSellDamage();
void printSellingFooter();
void printPageOptions(const bool prev, const bool next);

void printLootForSale(const int i, const int selectedl, const int lootNumber, const string lootTitle);
void printFenceHeader(const int ret);
void printFullscreenFooter(const string bname, const string exit_);
void printFullscreenHeader(const string bname);
void printFullscreenOption(const int p, const string dname);

extern MusicClass music;

//#endif//SHOP_CPP
//#endif// INCLUDES_H_INCLUDED
