#include "../includes.h"
const string CONST_item007 = "a";
const string CONST_item006 = "an";
const string CONST_item005 = "number";
const string CONST_item004 = "itemtypeid";
const string CONST_item003 = "itemtypename";

#include "../creature/creatureEnums.h"
#include "../items/itemtype.h"
#include "../items/item.h"
//own header
Item::Item(const ItemType& seed, int number) : number_(number)
{
   itemtypename_=seed.get_idname();
   itemtypeid_=seed.get_id();
}
Item::Item(const std::string& inputXml)
{
   CMarkup xml;
   xml.SetDoc(inputXml);
   xml.FindElem();
   xml.IntoElem();
   while(xml.FindElem())
   {
      std::string tag=xml.GetTagName();
      if(tag==CONST_item003) itemtypename_=xml.GetData();
      else if(tag==CONST_item004) itemtypeid_=atoi(xml.GetData().c_str());
      else if(tag==CONST_item005) number_=atoi(xml.GetData().c_str());
   }
}
void Item::addBaseValues(CMarkup& xml) const
{
   xml.AddElem(CONST_item003,itemtypename_);
   xml.AddElem(CONST_item004,itemtypeid_);
   xml.AddElem(CONST_item005,tostring(number_));
}
/*Item* Item::split(int number)
{
   if(amount>number_) amount=number_;
   Item* newi=this->clone();
   newi->number_=amount;
   this->number_-=amount;
   return newi;
}*/
/* compares two items (in descending order, hence the flipped arguments), used in sorting gear */
bool Item::sort_compare(Item *b,Item *a)
{
   if(a->whatIsThis() == THIS_IS_WEAPON &&!(b->whatIsThis() == THIS_IS_WEAPON)) return false;
   else if(!(a->whatIsThis() == THIS_IS_WEAPON) &&b->whatIsThis() == THIS_IS_WEAPON) return true;
   else if(a->whatIsThis() == THIS_IS_ARMOR &&!(b->whatIsThis() == THIS_IS_ARMOR)) return false;
   else if(!(a->whatIsThis() == THIS_IS_ARMOR) &&b->whatIsThis() == THIS_IS_ARMOR) return true;
   else if(a->whatIsThis() == THIS_IS_CLIP&&!(b->whatIsThis() == THIS_IS_CLIP)) return false;
   else if(!(a->whatIsThis() == THIS_IS_CLIP)&&b->whatIsThis() == THIS_IS_CLIP) return true;
   else if(a->whatIsThis() == THIS_IS_LOOT&&!(b->whatIsThis() == THIS_IS_LOOT)) return false;
   else if(!(a->whatIsThis() == THIS_IS_LOOT)&&b->whatIsThis() == THIS_IS_LOOT) return true;
   else return a->sort_compare_special(b);
}
const char* Item::aan() const
{
   switch(get_name()[0])
   {
   case 'a': case 'A':
   case 'e': case 'E':
   case 'i': case 'I':
   case 'o': case 'O':
   case 'u': case 'U':
      return CONST_item006.c_str();
   default:
      return CONST_item007.c_str();
   }
}