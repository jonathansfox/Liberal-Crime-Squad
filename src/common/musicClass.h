
class MusicClass
{
private:
	bool enabled;
#ifndef DONT_INCLUDE_SDL
	bool songsinitialized;
	bool oggsupport;
	int musicmode, previous;
	Mix_Music* songs[MUSIC_OFF];
	/* helper function for initsongs() ... implemented in misc.cpp */
	void loadsong(int i, const char* filename);
#endif // DONT_INCLUDE_SDL
public:
	MusicClass();
	/* find out if music's enabled or disabled */
	bool isEnabled();
	/* enable or disable music */
	void enableIf(bool e);
	/* initialize SDL, SDL_mixer, and songs ... implemented in misc.cpp */
	void init();
	/* shut down SDL, SDL_mixer, and songs ... implemented in misc.cpp */
	void quit();
	/* play music specified by a MusicMode ... implemented in misc.cpp */
	void play(int _musicmode);
};
