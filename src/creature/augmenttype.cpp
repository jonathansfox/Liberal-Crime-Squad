
#include "../includes.h"
const string CONST_augmenttypeB014 = " lacks idname.";
const string CONST_augmenttype013 = "Augment type ";
const string CONST_augmenttype012 = "LACKS IDNAME ";

const string tag_difficulty = "difficulty";
const string tag_cost = "cost";
const string tag_min_age = "min_age";
const string tag_max_age = "max_age";
const string tag_description = "description";
const string tag_effect = "effect";
const string tag_attribute = "attribute";
const string tag_type = "type";
const string tag_name = "name";
const string tag_idname = "idname";
const string tag_id = "id";
const string blankString = "";
#include "augmentation.h"
#include "augmenttype.h"
//own header
#include "../log/log.h"
// for log
#include "../common/stringconversion.h"
int AugmentType::number_of_augmenttypes = 0;
AugmentType::AugmentType(const std::string& xmlstring): max_age_(-1), min_age_(-1), cost_(0), difficulty_(5)
{
	extern Log xmllog;
   id_=number_of_augmenttypes++;
   CMarkup xml;
   xml.SetDoc(xmlstring);
   xml.FindElem();
   idname_=xml.GetAttrib(tag_idname);
   if(!len(idname_))
   {
      idname_ = CONST_augmenttype012+tostring(id_);
      xmllog.log(CONST_augmenttype013+tostring(id_)+CONST_augmenttypeB014);
   }
   xml.IntoElem();
   while(xml.FindElem())
   {
      std::string element = xml.GetTagName();
      if(element==tag_name)
         name_=xml.GetData();
      else if(element==tag_type)
         type_=augment_string_to_enum(xml.GetData());
      else if(element==tag_attribute)
         attribute_= attribute_string_to_enum(xml.GetData());
      else if(element==tag_effect)
         effect_=atoi(xml.GetData().c_str());
      else if(element==tag_description)
         description_=xml.GetData();
      else if(element==tag_max_age)
         max_age_=atoi(xml.GetData().c_str());
      else if(element==tag_min_age)
         min_age_=atoi(xml.GetData().c_str());
      else if(element==tag_cost)
         cost_=atoi(xml.GetData().c_str());
      else if(element==tag_difficulty)
         difficulty_=atoi(xml.GetData().c_str());
   }
}
void AugmentType::make_augment(Augmentation& au)
{
   au.name=get_name();
   au.type=get_type();
   au.attribute=get_attribute();
   au.effect=get_effect();
}