
#include <includes.h>
//#include "creature/creature.h"

#include "augmentation.h"
//own header currently inside includes.h

#include "common/stringconversion.h"
//for atoi redefinition

#include <cursesAlternative.h>
#include "creature/creatureEnums.h"
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
std::string Augmentation::get_name(int au)
{
   switch(au)
   {
      case AUGMENTATION_HEAD: return "Head";
      case AUGMENTATION_BODY: return "Body";
      case AUGMENTATION_ARMS: return "Arms";
      case AUGMENTATION_LEGS: return "Legs";
      case AUGMENTATION_SKIN: return "Skin";
      default: return "Conservative Swine! (Bug)";
   }
}
std::string Augmentation::showXml() const
{
   CMarkup xml;
   xml.AddElem("augmentation");
   xml.IntoElem();
   xml.AddElem("name", name);
   xml.AddElem("type", type);
   xml.AddElem("attribute", attribute);
   xml.AddElem("effect", effect);
   xml.AddElem("value", value);
   return xml.GetDoc();
}
Augmentation::Augmentation(const std::string& inputXml)
{
   CMarkup xml;
   xml.SetDoc(inputXml);
   xml.FindElem();
   xml.IntoElem();
   while(xml.FindElem())
   {
      std::string tag = xml.GetTagName();
      if(tag == "name")
         name = xml.GetData();
      else if(tag == "type")
         type = atoi(xml.GetData());
      else if(tag == "attribute")
         attribute = atoi(xml.GetData());
      else if(tag == "effect")
         effect = atoi(xml.GetData());
      else if(tag == "value")
         value = atoi(xml.GetData());
   }
}

