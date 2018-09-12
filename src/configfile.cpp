#include "includes.h"
const string CONST_configfile008 = "_Specials.csv";
const string CONST_configfile007 = "_Tiles.csv";
const string CONST_configfile006 = "mapCSV_Bank2_Tiles.csv";
const string CONST_configfile003 = "mapCSV_Bank_Tiles.csv";
const string CONST_configfile002 = "mapCSV_";
const string CONST_configfile001 = "OBJECT";
const string CONST_configfile000 = "Attempting to open filename: ";

#include "../items/itemtype.h"
#include "../items/item.h"
// needed for locations
#include "../locations/locations.h"
#include "../configfile.h"
//own header
#include "../cursesAlternative.h"
extern string singleSpace;
string attemptingToOpenFile = CONST_configfile000;
std::ifstream* openFile(const std::string& filename, std::ios_base::openmode format)
{
	extern char artdir[MAX_PATH_SIZE];
   std::ifstream* file = new std::ifstream();
   addstrAlt(attemptingToOpenFile);
   addstrAlt(filename);
   addstrAlt(singleSpace);
   file->open((artdir+filename).c_str(), format);
   return file;
}
// Reads in an entire configuration file
// Returns true for read successful, returns false if failed read
int readConfigFile(const std::string& filename)
{
   std::string command, value;
   configurable* object=0;
   std::ifstream* file = openFile(filename, ios::in);
   if(!file->is_open())
   {
      delete file;
      return false; // Unable to open; failed read
   }
   // loop through lines
   while(readLine(*file, command, value))
      // if COMMAND is OBJECT,
      // call a object creator factory, passing VALUE
      // (record pointer to that object)
      if(command==CONST_configfile001) object=createObject(value);
      // if I have an object,
      // pass COMMAND and VALUE to the object
      else if(object) object->configure(command, value);
      else
      {
         file->close();
         delete file;
         return false; // Unknown command and no object to give it to; failed read
      }
   file->close();
   delete file;
   return true;
}
// readLine reads a line from the file, parses it
int readLine(std::ifstream& file, std::string& command, std::string& value)
{
   std::string line;
   int source=0;
   // Search for a non-comment, non-empty line
   do
   {
      if(file.eof()) return false;
      getline(file,line);
      line.erase(std::remove(line.begin(),line.end(),'\r'),line.end());
      line.erase(std::remove(line.begin(),line.end(),'\n'),line.end());
   } while(!len(line)||line[0]=='#');
   // Parse the line
   command.clear();
   value.clear();
   // Leading whitespace
   for(;source<len(line)&&(line[source]==' '||line[source]=='\t');source++);
   // Command
   for(;source<len(line)&&(line[source]!=' '&&line[source]!='\t');command.push_back(line[source++]));
   // Delimiting whitespace
   for(;source<len(line)&&(line[source]==' '||line[source]=='\t');source++);
   // Value
   for(;source<len(line)&&(line[source]!=' '&&line[source]!='\t');value.push_back(line[source++]));
   return true;
}
map<int, SpecialBlocks> mapCBSpecial = {
	map<int, SpecialBlocks>::value_type(0,  SPECIAL_NONE),
	map<int, SpecialBlocks>::value_type(1,  SPECIAL_LAB_COSMETICS_CAGEDANIMALS),
	map<int, SpecialBlocks>::value_type(2,  SPECIAL_LAB_GENETIC_CAGEDANIMALS),
	map<int, SpecialBlocks>::value_type(3,  SPECIAL_POLICESTATION_LOCKUP),
	map<int, SpecialBlocks>::value_type(4,  SPECIAL_COURTHOUSE_LOCKUP),
	map<int, SpecialBlocks>::value_type(5,  SPECIAL_COURTHOUSE_JURYROOM),
	map<int, SpecialBlocks>::value_type(6,  SPECIAL_PRISON_CONTROL),
	map<int, SpecialBlocks>::value_type(7,  SPECIAL_PRISON_CONTROL_LOW),
	map<int, SpecialBlocks>::value_type(8,  SPECIAL_PRISON_CONTROL_MEDIUM),
	map<int, SpecialBlocks>::value_type(9,  SPECIAL_PRISON_CONTROL_HIGH),
	map<int, SpecialBlocks>::value_type(10,  SPECIAL_INTEL_SUPERCOMPUTER),
	map<int, SpecialBlocks>::value_type(11,  SPECIAL_SWEATSHOP_EQUIPMENT),
	map<int, SpecialBlocks>::value_type(12,  SPECIAL_POLLUTER_EQUIPMENT),
	map<int, SpecialBlocks>::value_type(13,  SPECIAL_NUCLEAR_ONOFF),
	map<int, SpecialBlocks>::value_type(14,  SPECIAL_HOUSE_PHOTOS),
	map<int, SpecialBlocks>::value_type(15,  SPECIAL_HOUSE_CEO),
	map<int, SpecialBlocks>::value_type(16,  SPECIAL_CORPORATE_FILES),
	map<int, SpecialBlocks>::value_type(17,  SPECIAL_RADIO_BROADCASTSTUDIO),
	map<int, SpecialBlocks>::value_type(18,  SPECIAL_NEWS_BROADCASTSTUDIO),
	map<int, SpecialBlocks>::value_type(19,  SPECIAL_APARTMENT_LANDLORD),
	map<int, SpecialBlocks>::value_type(20,  SPECIAL_SIGN_ONE),
	map<int, SpecialBlocks>::value_type(21,  SPECIAL_RESTAURANT_TABLE),
	map<int, SpecialBlocks>::value_type(22,  SPECIAL_CAFE_COMPUTER),
	map<int, SpecialBlocks>::value_type(23,  SPECIAL_PARK_BENCH),
	map<int, SpecialBlocks>::value_type(24,  SPECIAL_STAIRS_UP),
	map<int, SpecialBlocks>::value_type(25,  SPECIAL_STAIRS_DOWN),
	map<int, SpecialBlocks>::value_type(26,  SPECIAL_CLUB_BOUNCER),
	map<int, SpecialBlocks>::value_type(27,  SPECIAL_CLUB_BOUNCER_SECONDVISIT),
	map<int, SpecialBlocks>::value_type(28,  SPECIAL_ARMORY),
	map<int, SpecialBlocks>::value_type(29,  SPECIAL_DISPLAY_CASE),
	map<int, SpecialBlocks>::value_type(30,  SPECIAL_SIGN_TWO),
	map<int, SpecialBlocks>::value_type(31,  SPECIAL_SIGN_THREE),
	map<int, SpecialBlocks>::value_type(32,  SPECIAL_SECURITY_CHECKPOINT),
	map<int, SpecialBlocks>::value_type(33,  SPECIAL_SECURITY_METALDETECTORS),
	map<int, SpecialBlocks>::value_type(34,  SPECIAL_SECURITY_SECONDVISIT),
	map<int, SpecialBlocks>::value_type(35,  SPECIAL_BANK_VAULT),
	map<int, SpecialBlocks>::value_type(36,  SPECIAL_BANK_TELLER),
	map<int, SpecialBlocks>::value_type(37,  SPECIAL_BANK_MONEY),
	map<int, SpecialBlocks>::value_type(38,  SPECIAL_CCS_BOSS),
	map<int, SpecialBlocks>::value_type(39,  SPECIAL_OVAL_OFFICE_NW),
	map<int, SpecialBlocks>::value_type(40,  SPECIAL_OVAL_OFFICE_NE),
	map<int, SpecialBlocks>::value_type(41,  SPECIAL_OVAL_OFFICE_SW),
	map<int, SpecialBlocks>::value_type(42,  SPECIAL_OVAL_OFFICE_SE),
};
void readMapCBSpecials(int x, int y, int z, int i)
{
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
	if (mapCBSpecial.count(i) > 0) {
		levelmap[x][y][z].special = mapCBSpecial[i];
	}
	else {
		levelmap[x][y][z].special = mapCBSpecial[0];
	}
}
void makeDoor(int x,int y,int z,int flags=0)
{
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
   levelmap[x][y][z].flag=SITEBLOCK_DOOR|flags;
   if((x>0&&(levelmap[x-1][y][z].flag&SITEBLOCK_RESTRICTED))||
      (y>0&&(levelmap[x][y-1][z].flag&SITEBLOCK_RESTRICTED)))
      levelmap[x][y][z].flag|=SITEBLOCK_RESTRICTED;
}
void readMapCBTiles(int x, int y, int z, int i)
{
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
   switch(i)
   {
   default:
   case 0: levelmap[x][y][z].flag=0; break;
   case 2: levelmap[x][y][z].flag=SITEBLOCK_BLOCK; break;
   case 3: levelmap[x][y][z].flag=SITEBLOCK_EXIT; break;
   case 4: levelmap[x][y][z].flag=SITEBLOCK_GRASSY; break;
   case 5: makeDoor(x,y,z); break;
   case 6: makeDoor(x,y,z,SITEBLOCK_LOCKED); break;
   case 7:
      levelmap[x][y][z].flag=SITEBLOCK_RESTRICTED;
      if(x>0&&(levelmap[x-1][y][z].flag&SITEBLOCK_DOOR))
         levelmap[x-1][y][z].flag|=SITEBLOCK_RESTRICTED;
      if(y>0&&(levelmap[x][y-1][z].flag&SITEBLOCK_DOOR))
         levelmap[x][y-1][z].flag|=SITEBLOCK_RESTRICTED;
      break;
   case 8: levelmap[x][y][z].flag=SITEBLOCK_CHAINLINK; break;
   case 9: makeDoor(x,y,z,SITEBLOCK_LOCKED|SITEBLOCK_ALARMED); break;
   case 10: levelmap[x][y][z].flag=SITEBLOCK_BLOCK|SITEBLOCK_METAL; break;
   case 11: makeDoor(x,y,z,SITEBLOCK_LOCKED|SITEBLOCK_METAL); break;
   }
}
bool readMapFile(const string &filename, const int zLevel, void (*callback)(int,int,int,int))
{
   // open the file in question
   std::ifstream* file = openFile(filename, ios::in);
   // abort if the file couldn't be opened
   if(!file->is_open())
   {
      delete file;
      return false;
   }
   for(int y=0,z=zLevel;!file->eof();y++)
   {
      std::string line;
      getline(*file,line);
      line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
      line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
      for(int x=0,i=0,j=0;j<len(line);x++,i=++j)
      {
         for(;j<len(line)&&line[j]!=',';j++);
         if(j<len(line))
         {
            line[j]=0;
            (*callback)(x,y,z,atoi(line.substr(i).c_str()));
         }
      }
   }
   file->close();
   delete file;
   return true;
}
bool readMap(const std::string& filename)
{
	extern siteblockst levelmap[MAPX][MAPY][MAPZ];
   std::string prefix = std::string(CONST_configfile002);
   // clear any old map data
   for(int x=0;x<MAPX;x++)
   for(int y=0;y<MAPY;y++)
   for(int z=0;z<MAPZ;z++)
   {
      levelmap[x][y][z].flag=0;
      levelmap[x][y][z].special=SPECIAL_NONE;
      levelmap[x][y][z].siegeflag=0;
   }
   // Try first floor (eg CONST_configfile003), abort this method if it doesn't exist
   if(!readMapFile(prefix+filename+CONST_configfile007, 0, readMapCBTiles)) return false;
   if(!readMapFile(prefix+filename+CONST_configfile008, 0, readMapCBSpecials)) return false;
   // Try upper levels (eg CONST_configfile006), but don't sweat it if they don't exist
   for(int z=1;z<MAPZ;z++)
   {
      std::string str=tostring(z+1);
      if(!readMapFile(prefix+filename+str+CONST_configfile007, z, readMapCBTiles)) break;
      if(!readMapFile(prefix+filename+str+CONST_configfile008, z, readMapCBSpecials)) break;
   }
   return true;
}