#include "../includes.h"

const string CONST_augmentation017 = "Conservative Swine! (Bug)";
const string CONST_augmentation016 = "Skin";
const string CONST_augmentation015 = "Legs";
const string CONST_augmentation014 = "Arms";
const string CONST_augmentation013 = "Body";
const string CONST_augmentation012 = "Head";
const string tag_skin = "skin";
const string tag_legs = "legs";
const string tag_arms = "arms";
const string tag_body = "body";
const string tag_head = "head";
const string tag_value = "value";
const string tag_effect = "effect";
const string tag_attribute = "attribute";
const string tag_type = "type";
const string tag_name = "name";
const string tag_augmentation = "augmentation";
const string blankString = "";
#include "augmentation.h"
std::string Augmentation::get_name(int au)
{
   switch(au)
   {
      case AUGMENTATION_HEAD: return CONST_augmentation012;
      case AUGMENTATION_BODY: return CONST_augmentation013;
      case AUGMENTATION_ARMS: return CONST_augmentation014;
      case AUGMENTATION_LEGS: return CONST_augmentation015;
      case AUGMENTATION_SKIN: return CONST_augmentation016;
      default: return CONST_augmentation017;
   }
}
std::string Augmentation::showXml() const
{
   CMarkup xml;
   xml.AddElem(tag_augmentation);
   xml.IntoElem();
   xml.AddElem(tag_name, name);
   xml.AddElem(tag_type, type);
   xml.AddElem(tag_attribute, attribute);
   xml.AddElem(tag_effect, effect);
   xml.AddElem(tag_value, value);
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
      if(tag == tag_name)
         name = xml.GetData();
      else if(tag == tag_type)
         type = atoi(xml.GetData().c_str());
      else if(tag == tag_attribute)
         attribute = atoi(xml.GetData().c_str());
      else if(tag == tag_effect)
         effect = atoi(xml.GetData().c_str());
      else if(tag == tag_value)
         value = atoi(xml.GetData().c_str());
   }
}
int augment_string_to_enum(const string& augmentname)
{
	if (augmentname == tag_head)
		return AUGMENTATION_HEAD;
	else if (augmentname == tag_body)
		return AUGMENTATION_BODY;
	else if (augmentname == tag_arms)
		return AUGMENTATION_ARMS;
	else if (augmentname == tag_legs)
		return AUGMENTATION_LEGS;
	else if (augmentname == tag_skin)
		return AUGMENTATION_SKIN;
	else
		return -1;
}