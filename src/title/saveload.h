#ifndef SAVELOAD_H
#define SAVELOAD_H0


/*
 saveload.cpp
*/
/* saves the game to save.dat */
void savegame(const string& filename);
/* loads the game from save.dat */
char load(const string& filename);
/* deletes save.dat (used on endgame and for invalid save version) */
//void reset();
/* check if file exists */ 
bool file_exists(const std::string& filename);

#endif SAVELOAD_H 