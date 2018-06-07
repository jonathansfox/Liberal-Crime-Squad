#include "../includes.h"
const string CONST_loottype009 = "::cloth: ";
const string CONST_loottype008 = "Invalid boolean value for loot type ";
const string CONST_loottype007 = "::no_quick_fencing: ";
const string CONST_loottype005 = "::stackable: ";

const string tag_cloth = "cloth";
const string tag_no = "no";
const string tag_no_quick_fencing = "no_quick_fencing";
const string tag_stackable = "stackable";
#include "../creature/creatureEnums.h"
#include "../items/itemtype.h"
#include "../items/loottype.h"
//own header
#include "../common/stringconversion.h"
//for stringtobool
LootType::LootType(MCD_STR xmlstring)
	: ItemType(xmlstring), stackable_(true),
	no_quick_fencing_(false), cloth_(false)
{
	CMarkup xml;
	xml.SetDoc(xmlstring);
	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem()) //Loop over all the elements inside the loottype element.
	{
		std::string element = xml.GetTagName();
		if (element == tag_stackable)
		{
			int b = stringtobool(xml.GetData());
			if (b == 1)
				stackable_ = true;
			else if (b == 0)
				stackable_ = false;
			/*else
			   errorlog << CONST_loottype008 << idname
						 << CONST_loottype005 << xml.GetData() << std::endl;*/
		}
		else if (element == tag_no_quick_fencing)
		{
			int b = stringtobool(xml.GetData());
			if (b == 1)
				no_quick_fencing_ = true;
			else if (b == 0)
				no_quick_fencing_ = false;
			/*else
			   errorlog << CONST_loottype008 << idname
						 << CONST_loottype007 << xml.GetData() << std::endl;*/
		}
		else if (element == tag_cloth)
		{
			int b = stringtobool(xml.GetData());
			if (b == 1)
				cloth_ = true;
			else if (b == 0)
				cloth_ = false;
			/*else
			   errorlog << CONST_loottype008 << idname
						 << CONST_loottype009 << xml.GetData() << std::endl;*/
		}
	}
}