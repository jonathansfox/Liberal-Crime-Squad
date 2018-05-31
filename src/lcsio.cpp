#include "../includes.h"
const string CONST_lcsio014 = ".dat";
const string CONST_lcsio013 = ".";
const string CONST_lcsio012 = ".lcs/";
const string CONST_lcsio011 = "/";
const string CONST_lcsio010 = "./";
const string CONST_lcsio009 = "HOME";
const string CONST_lcsio008 = "../art/";
const string CONST_lcsio007 = "./art/";
const string CONST_lcsio006 = "/usr/games/lcs/art/";
const string CONST_lcsio005 = "/usr/games/share/lcs/art/";
const string CONST_lcsio004 = "/usr/share/lcs/art/";
const string CONST_lcsio003 = "/usr/local/share/lcs/art/";
const string CONST_lcsio002 = "/lcs/art/";
const string CONST_lcsioX01 = "score";

const string blankString = "";
/*
This file is a complete rewrite of the LCS I/O system.
The original lcsio.h can be found in lcsio-old.h in the sourceforge Subversion
repository.
This file is part of Liberal Crime Squad.
    Liberal Crime Squad is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
    Liberal Crime Squad is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.   See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with Liberal Crime Squad; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA   02111-1307   USA
*/
#include <tinydir.h>
const char* arttest="newspic.cpc";
bool initialized=false;
const char *art_search_paths[]=
{
   #ifdef INSTALL_DATA_DIR
   INSTALL_DATA_DIR CONST_lcsio002,
   #endif
   #ifndef WIN32
   CONST_lcsio003.c_str(),
   CONST_lcsio004.c_str(),
   CONST_lcsio005.c_str(),
   CONST_lcsio006.c_str(),
   #endif
   CONST_lcsio007.c_str(),
   CONST_lcsio008.c_str(),
   NULL
};
//Check if filename exists on the system.
//Filename is the full path to the file.
//This works on directories too, but only in Linux!
bool LCSFileExists(const char* filename)
{
   struct stat st;
   return(stat(filename,&st)==0);
}
//Put the home directory prefix in homedir.
//Create the home directory if it does not exist.
bool LCSInitHomeDir()
{
	extern char homedir[MAX_PATH_SIZE];
   #ifndef WIN32
   char* homeenv=getenv(CONST_lcsio009.c_str());
   #else
   char* homeenv=(char*)CONST_lcsio010.c_str();
   #endif
   //Do everything using STL String, it is safer that way.
   std::string str=homeenv;
   if(str[len(str)-1]!='/')
      str+=CONST_lcsio011;
   #ifndef WIN32
   str+=CONST_lcsio012;
   #endif
   strncpy(homedir,str.c_str(),MAX_PATH_SIZE);
   if((!LCSFileExists(homedir)) && (strncmp(homedir,CONST_lcsio013.c_str(),1)!=0))
   {
      #ifdef WIN32
      if(_mkdir(homedir)!=0)
         return false;
      #else
      if(mkdir(homedir,0750)!=0)
         return false;
      #endif
   }
   return true;
}
//Put the art directory prefix in artdir.
bool LCSInitArtDir()
{
	extern char artdir[MAX_PATH_SIZE];
   const char* artprefix;
   artprefix=art_search_paths[0];
   std::string tester;
   for(int i=1;artprefix!=NULL;i++)
   {
      tester=artprefix;
      tester.append(arttest);
      if(LCSFileExists(tester.c_str()))
         break;
      artprefix=art_search_paths[i];
   }
   if(artprefix==NULL)
      return false;
   strncpy(artdir,artprefix,MAX_PATH_SIZE);
   return true;
}
void LCSRenameFile(const char* old_filename,const char* new_filename,int flags)
{
	extern char homedir[MAX_PATH_SIZE];
	extern char artdir[MAX_PATH_SIZE];
   if(!initialized)
   {
      LCSInitHomeDir();
      LCSInitArtDir();
      initialized=true;
   }
   std::string old_filepath;
   std::string new_filepath;
   if(flags & LCSIO_PRE_ART)
      old_filepath=artdir;
   else if(flags & LCSIO_PRE_HOME)
      old_filepath=homedir;
   new_filepath = old_filepath;
   old_filepath.append(old_filename);
   new_filepath.append(new_filename);
   rename(old_filepath.c_str(), new_filepath.c_str());
}
FILE* LCSOpenFile(const char* filename,const char* mode,int flags)
{
	extern char homedir[MAX_PATH_SIZE];
	extern char artdir[MAX_PATH_SIZE];
   if(!initialized)
   {
      LCSInitHomeDir();
      LCSInitArtDir();
      initialized=true;
   }
   std::string filepath;
   if(flags & LCSIO_PRE_ART)
      filepath=artdir;
   else if(flags & LCSIO_PRE_HOME)
      filepath=homedir;
   filepath.append(filename);
   return fopen(filepath.c_str(),mode);
}
vector<string> LCSSaveFiles()
{
	extern char homedir[MAX_PATH_SIZE];
   vector<string> save_files;
   tinydir_dir dir;
   tinydir_open(&dir, homedir);
   while (dir.has_next)
   {
      tinydir_file file;
      tinydir_readfile(&dir, &file);
      if(strstr(file.name, CONST_lcsio014.c_str()) != NULL &&strstr(file.name, CONST_lcsioX01.c_str()) == NULL)
         save_files.push_back(file.name);
      tinydir_next(&dir);
   }
   tinydir_close(&dir);
   return save_files;
}
//C++ file i/o version of the above.
bool LCSOpenFileCPP(std::string filename, std::ios_base::openmode mode, int flags, std::fstream &file)
{
	extern char homedir[MAX_PATH_SIZE];
	extern char artdir[MAX_PATH_SIZE];
   if(!initialized) //Check if the directories have not been initialized.
   {
      LCSInitHomeDir(); //Initialize the home directory of LCS. Where stuff like the save and score files are stored.
      LCSInitArtDir(); //Initialize the art dir.
      initialized = true; //Initialized.
   }
   std::string filepath = blankString; //The actual path to the file.
   //This ifelse block decides which directory the file gets saved to.
   if(flags & LCSIO_PRE_ART) //Art dir specified.
      filepath = artdir; //Set the filepath to the artdir.
   else if(flags & LCSIO_PRE_HOME) //Home dir specified.
      filepath = homedir; //Set the filepath to the homedir.
   filepath.append(filename); //Append the file's name/relative path to the filepath.
   file.open(filepath.c_str(), mode); //Opens the file.
   return file.is_open(); //Check if file opened successfully.
}
void LCSDeleteFile(const char* filename,int flags)
{
	extern char homedir[MAX_PATH_SIZE];
	extern char artdir[MAX_PATH_SIZE];
   if(!initialized)
   {
      LCSInitHomeDir();
      LCSInitArtDir();
      initialized=true;
   }
   std::string str;
   if(flags & LCSIO_PRE_ART)
      str.append(artdir);
   else if(flags & LCSIO_PRE_HOME)
      str.append(homedir);
   str.append(filename);
   remove(str.c_str());
}
void LCSCloseFile(FILE* handle)
{
   fclose(handle);
}
//C++ file i/o version of the above.
void LCSCloseFileCPP(std::fstream &file)
{
   if(file.is_open()) //Check if the file even is open so that we don't bother closing a file that isn't open.
      file.close();
}