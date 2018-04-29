
class MusicClass
{
private:
	bool enabled;
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
