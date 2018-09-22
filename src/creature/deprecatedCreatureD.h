#pragma once

struct Deprecatedsquadst
{
	char name[SQUAD_NAMELEN];
	DeprecatedCreature *squad[6];
	ActivityST activity;
	int id;
	vector<Item *> loot;

	char stance; // Squad's site action stance: high profile, low profile, etc.

	Deprecatedsquadst()
	{
		for (int p = 0; p < 6; p++) squad[p] = NULL;
		strcpy(name, blankString.c_str());
		activity.type = ACTIVITY_NONE, id = -1, stance = SQUADSTANCE_STANDARD;
	}
	~Deprecatedsquadst() { delete_and_clear(loot); }
};
