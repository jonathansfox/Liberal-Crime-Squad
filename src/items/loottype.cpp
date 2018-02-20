
#include <includes.h>
#include "creature/creatureEnums.h"
#include "items/itemtype.h"
#include "items/loottype.h"
//own header

#include "common/stringconversion.h"
//for stringtobool


#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
LootType::LootType(MCD_STR xmlstring)
 : ItemType(xmlstring), stackable_(true),
   no_quick_fencing_(false), cloth_(false)
{
   CMarkup xml;
   xml.SetDoc(xmlstring);
   xml.FindElem();
   xml.IntoElem();
   while(xml.FindElem()) //Loop over all the elements inside the loottype element.
   {
      std::string element = xml.GetTagName();
      if (element == "stackable")
      {
         int b = stringtobool(xml.GetData());
         if (b == 1)
            stackable_ = true;
         else if (b == 0)
            stackable_ = false;
         /*else
            errorlog << "Invalid boolean value for loot type " << idname
                      << "::stackable: " << xml.GetData() << std::endl;*/
      }
      else if (element == "no_quick_fencing")
      {
         int b = stringtobool(xml.GetData());
         if (b == 1)
            no_quick_fencing_ = true;
         else if (b == 0)
            no_quick_fencing_ = false;
         /*else
            errorlog << "Invalid boolean value for loot type " << idname
                      << "::no_quick_fencing: " << xml.GetData() << std::endl;*/
      }
      else if (element == "cloth")
      {
         int b = stringtobool(xml.GetData());
         if (b == 1)
            cloth_ = true;
         else if (b == 0)
            cloth_ = false;
         /*else
            errorlog << "Invalid boolean value for loot type " << idname
                      << "::cloth: " << xml.GetData() << std::endl;*/
      }
   }
}
