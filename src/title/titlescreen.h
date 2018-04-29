#ifndef TITLESCREEN_H
#define TITLESCREEN_H0

class title_screen {

private:
	static title_screen s_title_singleton;
	static vector<string> s_savefiles;
	static string savefile_name;
	bool static autosave;
	static bool titleInitiated;
	void title();
	void choose_savefile_name();
	void selectAndLoadSaveFile();
public:
	static title_screen getInstance();
	void mode_title();
	void reset();
	static void setautosaveoption(bool shouldautosave);
	void autosavegame();
};
/*
 titlescreen.cpp
*/
//void mode_title();


#endif //TITLESCREEN_H 