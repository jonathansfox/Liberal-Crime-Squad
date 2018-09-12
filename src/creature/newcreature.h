
#include "../items/itemtype.h"
#include "../items/cliptype.h"
#include "../items/weapontype.h"
#include "../items/item.h"
#include "../items/clip.h"
#include "../items/weapon.h"
#include "../items/armor.h"
#include "augmentation.h"

#include "creatureEnums.h"
struct CreatureBools
{
	const bool exists;
	const bool alive;
	const bool enemy;
	CreatureBools(bool _exists, bool _alive, bool _enemy) :
		exists(_exists),
		alive(_alive),
		enemy(_enemy)
	{};
};
struct CreatureInts
{
	const int align;
	const int type;
	const int blood;
	CreatureInts(int _align, int _type, int _blood) :
		align(_align),
		type(_type),
		blood(_blood)
	{};
};
struct NameAndAlignment
{
	const bool exists;
	const bool alive;
	const bool enemy;
	const int align;
	const int type;
	const int blood;
	const string name;
	NameAndAlignment(CreatureBools creatureBools, CreatureInts creatureInts, string _name) :
		exists(creatureBools.exists),
		alive(creatureBools.alive),
		enemy(creatureBools.enemy),
		type(creatureInts.type),
		blood(creatureInts.blood),
		align(creatureInts.align),
		name(_name)
	{};
};
int get_XML_value(const std::string& inputXml);

void makecreature(int cr, short type);
/* fills a string with a proper name */
void generate_name(char *str, char gender = GENDER_NEUTRAL);
/* get a first and last name for the same person */
void generate_name(char *first, char *last, char gender = GENDER_NEUTRAL);

/* fills a string with a proper name */
string generate_name(char gender = GENDER_NEUTRAL);
/* get a first and last name for the same person */
//string generate_name(char *first, char *last, char gender = GENDER_NEUTRAL);

/* get a first, middle, and last name for the same person */
void generate_long_name(char *first, char *middle, char *last, char gender = GENDER_NEUTRAL);
/* gets a random first name */
void firstname(char *str, char gender = GENDER_NEUTRAL);
/* gets a random last name */
string lastname(bool archconservative = false);
