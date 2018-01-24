
#include <includes.h>

#include "vehicle/vehicle.h"
//own header

#include "common/stringconversion.h"
//for atoi


#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
extern vector<Creature *> pool;
long Vehicle::curcarid = 0;
extern string singleSpace;

string Vehicle::showXml() const
{
   CMarkup xml;
   xml.AddElem("vehicle");
   xml.IntoElem();
   xml.AddElem("vtypeidname", vtypeidname_);
   xml.AddElem("vtypeid", tostring(vtypeid_));
   xml.AddElem("color", color_);
   xml.AddElem("heat", tostring(heat_));
   xml.AddElem("location", tostring(location_));
   xml.AddElem("myear", tostring(myear_));
   xml.AddElem("id", tostring(id_));
   return xml.GetDoc();
}
Vehicle::Vehicle(const std::string& inputXml)
{
   CMarkup xml;
   xml.SetDoc(inputXml);
   xml.FindElem();
   xml.IntoElem();
   while(xml.FindElem())
   {
      std::string tag=xml.GetTagName();
      if(tag=="vtypeidname") vtypeidname_=xml.GetData();
      else if(tag=="vtypeid") vtypeid_=atoi(xml.GetData());
      else if(tag=="color") color_=xml.GetData();
      else if(tag=="heat") heat_=atoi(xml.GetData());
      else if(tag=="location") location_=atoi(xml.GetData());
      else if(tag=="myear") myear_=atoi(xml.GetData());
      else if(tag=="id") id_=atoi(xml.GetData());
   }
}
void Vehicle::init(const VehicleType& seed, const string& color, int myear)
{
   id_=curcarid++;
   heat_=0;
   location_=-1;
   vtypeidname_=seed.idname();
   vtypeid_=seed.id();
   color_=color;
   myear_=myear;
}
void Vehicle::stop_riding_me() const
{
   for(int p=0;p<len(pool);p++)
      if(pool[p]->carid==id_)
         pool[p]->carid=-1;
}
void Vehicle::stop_preferring_me() const
{
   for(int p=0;p<len(pool);p++)
      if(pool[p]->pref_carid==id_)
         pool[p]->pref_carid=-1;
}
string Vehicle::fullname(bool halffull) const
{
   string s;
   int words=0;
   if(heat_)
   {
      s="Stolen ";
      words++;
   }
   if(displayscolor())
   {
      s+=color_+singleSpace;
      words++;
   }
   if (myear_!=-1&&words<2) //don't print year if that will make the name too long.
      s+=tostring(myear_)+singleSpace;
   if(halffull) s+=shortname();
   else s+=longname();
   return s;
}
int Vehicle::modifieddriveskill(int skillLevel)
{
   return vehicletype[getvehicletype(vtypeidname_)]->modifieddriveskill(skillLevel); // Todo - add bonus if car is upgraded with nitro
}
int Vehicle::modifieddodgeskill(int skillLevel)
{
   return vehicletype[getvehicletype(vtypeidname_)]->modifieddodgeskill(skillLevel); // Todo - add bonus if car is upgraded
}
Vehicle::Vehicle(const VehicleType& seed) { init(seed, pickrandom(seed.color()), seed.makeyear()); }
Vehicle::Vehicle(const VehicleType& seed, const string& color, int myear) { init(seed, color, myear); }
Vehicle::~Vehicle() { stop_riding_me(); stop_preferring_me(); }
short Vehicle::get_heat() const { return heat_; }
void Vehicle::add_heat(short heat) { heat_ += heat; }
long Vehicle::get_location() const { return location_; }
void Vehicle::set_location(long new_location) { location_ = new_location; }
const string& Vehicle::vtypeidname() const { return vtypeidname_; }
long Vehicle::vtypeid() const { return vtypeid_; }
const string& Vehicle::color() const { return color_; }
bool Vehicle::displayscolor() const { return vehicletype[getvehicletype(vtypeidname_)]->displayscolor(); }
int Vehicle::myear() const { return myear_; }
long Vehicle::id() const { return id_; }
int Vehicle::attackbonus(bool isDriver) const { return vehicletype[getvehicletype(vtypeidname_)]->attackbonus(isDriver); }
int Vehicle::gethitlocation(int bodypart) { return vehicletype[getvehicletype(vtypeidname_)]->gethitlocation(bodypart); }
string Vehicle::getpartname(int hitlocation) { return vehicletype[getvehicletype(vtypeidname_)]->getpartname(hitlocation); }
int Vehicle::armorbonus(int hitlocation) const { return vehicletype[getvehicletype(vtypeidname_)]->armorbonus(hitlocation); }
const string& Vehicle::longname() const { return vehicletype[getvehicletype(vtypeidname_)]->longname(); }
const string& Vehicle::shortname() const { return vehicletype[getvehicletype(vtypeidname_)]->shortname(); }
int Vehicle::steal_difficultytofind() const { return vehicletype[getvehicletype(vtypeidname_)]->steal_difficultytofind(); }
int Vehicle::steal_juice() const { return vehicletype[getvehicletype(vtypeidname_)]->steal_juice(); }
int Vehicle::steal_extraheat() const { return vehicletype[getvehicletype(vtypeidname_)]->steal_extraheat(); }
int Vehicle::sensealarmchance() const { return vehicletype[getvehicletype(vtypeidname_)]->sensealarmchance(); }
int Vehicle::touchalarmchance() const { return vehicletype[getvehicletype(vtypeidname_)]->touchalarmchance(); }
bool Vehicle::availableatshop() const { return vehicletype[getvehicletype(vtypeidname_)]->availableatshop(); }
int Vehicle::price() const { return vehicletype[getvehicletype(vtypeidname_)]->price(); }
int Vehicle::sleeperprice() const { return vehicletype[getvehicletype(vtypeidname_)]->sleeperprice(); }