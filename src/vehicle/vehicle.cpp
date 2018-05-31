#include "../includes.h"
const string CONST_vehicle007 = "Stolen ";

const string tag_id = "id";
const string tag_myear = "myear";
const string tag_location = "location";
const string tag_color = "color";
const string tag_vtypeid = "vtypeid";
const string tag_vtypeidname = "vtypeidname";
const string tag_vehicle = "vehicle";
const string singleSpace = " ";
#include "vehicletype.h"
vector<VehicleType *> vehicletype;
#include "vehicle.h"
//own header
long Vehicle::curcarid = 0;
#include "common/creaturePool.h"
string Vehicle::showXml() const
{
   CMarkup xml;
   xml.AddElem(tag_vehicle);
   xml.IntoElem();
   xml.AddElem(tag_vtypeidname, vtypeidname_);
   xml.AddElem(tag_vtypeid, tostring(vtypeid_));
   xml.AddElem(tag_color, color_);
   xml.AddElem(tag_heat, tostring(heat_));
   xml.AddElem(tag_location, tostring(location_));
   xml.AddElem(tag_myear, tostring(myear_));
   xml.AddElem(tag_id, tostring(id_));
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
      if(tag==tag_vtypeidname) vtypeidname_=xml.GetData();
      else if(tag==tag_vtypeid) vtypeid_=atoi(xml.GetData().c_str());
      else if(tag==tag_color) color_=xml.GetData();
      else if(tag==tag_heat) heat_=atoi(xml.GetData().c_str());
      else if(tag==tag_location) location_=atoi(xml.GetData().c_str());
      else if(tag==tag_myear) myear_=atoi(xml.GetData().c_str());
      else if(tag==tag_id) id_=atoi(xml.GetData().c_str());
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
	CreaturePool::getInstance().stop_riding_me(id_);
}
void Vehicle::stop_preferring_me() const
{
	CreaturePool::getInstance().stop_preferring_me(id_);
}
string Vehicle::fullname(bool halffull) const
{
   string s;
   int words=0;
   if(heat_)
   {
      s=CONST_vehicle007;
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

/* transforms a vehicle type id into the index of that vehicle type in the global vector */
int getvehicletype(const int id)
{
	for (int i = 0; i<len(vehicletype); i++) if (vehicletype[i]->id() == id) return i;
	return -1;
}
/* transforms a vehicle type idname into the index of that vehicle type in the global vector */
int getvehicletype(const string &idname)
{
	for (int i = 0; i<len(vehicletype); i++) if (vehicletype[i]->idname() == idname) return i;
	return -1;
}

int steal_difficultytofind(const int v) {
	return vehicletype[v]->steal_difficultytofind();
}
int lenVehicleType() {
	return len(vehicletype);
}

string vehicleTypelongname(const int p) {
	return vehicletype[p]->longname();
}

Vehicle* getVehicleOfThisType(const int cartype) {
	return new Vehicle(*vehicletype[cartype]);
}

Vehicle* getVehicleFromTypeYear(const int carchoice, const int colorchoice, const int year) {
	return new Vehicle(*vehicletype[carchoice],
		vehicletype[carchoice]->color()[colorchoice], year);
}

int getVehicleTypePrice(const int carchoice) {
	return vehicletype[carchoice]->price();

}

int getVehicleTypeSleeperPrice(const int carchoice) {
	return vehicletype[carchoice]->sleeperprice();
}

vector<string> getVehicleTypeColor(const int carchoice) {
	return vehicletype[carchoice]->color();
}

bool vehicletypeavailableatshop(const int i) {
	return vehicletype[i]->availableatshop();
}
string vehicleSportsCar;
Vehicle* newSportsCar() {
	return new Vehicle(*vehicletype[getvehicletype(vehicleSportsCar)]);
}

void delete_and_clear_vehicle_types() {
	delete_and_clear(vehicletype);
}