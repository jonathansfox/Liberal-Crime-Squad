/*
sitedisplay.cpp
*/
/* prints the 'map graphics' on the bottom right */
void printsitemap(int x, int y, int z);
void printblock(int x, int y, int z, int px, int py);
/* prints the names of creatures you see */
void printencounter();
/* prints the names of creatures you see in car chases */
void printchaseencounter();
/* blanks a part of the screen */
void clearcommandarea();
void clearmessagearea(bool redrawmaparea = true);
void clearmaparea(bool lower = true, bool upper = true);
