
#include <includes.h>

#include "augmentation.h"

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
         type = atoi(xml.GetData().c_str());
      else if(tag == "attribute")
         attribute = atoi(xml.GetData().c_str());
      else if(tag == "effect")
         effect = atoi(xml.GetData().c_str());
      else if(tag == "value")
         value = atoi(xml.GetData().c_str());
   }
}

int augment_string_to_enum(const string& augmentname)
{
	if (augmentname == "head")
		return AUGMENTATION_HEAD;
	else if (augmentname == "body")
		return AUGMENTATION_BODY;
	else if (augmentname == "arms")
		return AUGMENTATION_ARMS;
	else if (augmentname == "legs")
		return AUGMENTATION_LEGS;
	else if (augmentname == "skin")
		return AUGMENTATION_SKIN;
	else
		return -1;
}