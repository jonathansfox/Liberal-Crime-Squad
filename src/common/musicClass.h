
enum MusicModes
{
	MUSIC_TITLEMODE,
	MUSIC_NEWGAME,
	MUSIC_BASEMODE,
	MUSIC_SIEGE,
	MUSIC_ACTIVATE,
	MUSIC_SLEEPERS,
	MUSIC_STOPEVIL,
	MUSIC_REVIEWMODE,
	MUSIC_LIBERALAGENDA,
	MUSIC_DISBANDED,
	MUSIC_FINANCES,
	MUSIC_CARTHEFT,
	MUSIC_ELECTIONS,
	MUSIC_SHOPPING,
	MUSIC_SITEMODE,
	MUSIC_SUSPICIOUS,
	MUSIC_ALARMED,
	MUSIC_HEAVYCOMBAT,
	MUSIC_DEFENSE,
	MUSIC_CONQUER,
	MUSIC_CARCHASE,
	MUSIC_FOOTCHASE,
	MUSIC_INTERROGATION,
	MUSIC_TRIAL,
	MUSIC_RECRUITING,
	MUSIC_DATING,
	MUSIC_NEWSPAPER,
	MUSIC_LACOPS,
	MUSIC_NEWSCAST,
	MUSIC_GLAMSHOW,
	MUSIC_ANCHOR,
	MUSIC_ABORT,
	MUSIC_VICTORY,
	MUSIC_DEFEAT,
	MUSIC_REAGANIFIED,
	MUSIC_STALINIZED,
	MUSIC_OFF, // this one must come immediately after the ones corresponding to music files (this one is to have silence)
	MUSIC_PREVIOUS, // this one must come after MUSIC_OFF (this one is to play the previous song)
	MUSIC_CURRENT, // this one must come after MUSIC_OFF (this one continues playing the current song)
	MUSIC_RANDOM // this one must come after MUSIC_OFF (this one plays a random song)
};

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
