
#include "../includes.h"
const string CONST_miscC026 = "): ";

const string CONST_miscB025 = ".mid:  ";
const string CONST_miscB024 = ".mid";
const string CONST_miscB023 = ".ogg:  ";
const string CONST_miscB022 = ".ogg";
const string CONST_miscB021 = "/";
const string CONST_miscB020 = ".mid as MIDI fallback)";
const string CONST_misc019 = "1234567890-";
const string CONST_misc018 = "SDL_mixer function Mix_PlayMusic() failed:  ";
const string CONST_misc017 = "Pastorale";
const string CONST_misc016 = "Mars";
const string CONST_misc015 = "Ogg Vorbis support failed to load. MIDI music will be used instead if possible.";
const string CONST_misc014 = "Unable to initialize SDL_mixer:  ";
const string CONST_misc013 = "Unable to initialize SDL:  ";
const string CONST_misc012 = "SDL_mixer function Mix_LoadMUS() failed to load ";
const string CONST_misc011 = "midi/";
const string CONST_misc009 = "ogg/";
const string CONST_misc008 = "Loading MIDI music (";
const string CONST_misc007 = "(with ";
const string CONST_misc006 = "Loading Ogg Vorbis music (";
const string CONST_misc005 = "listOfStates.txt";
const string CONST_misc004 = "sextypeAcronym.txt";
const string CONST_misc003 = "sexseekAcronym.txt";
const string CONST_misc002 = "sexwhoAcronym.txt";
const string CONST_misc001 = "sexdescAcronym.txt";

const string blankString = "";
#include "../common/ledgerEnums.h"
#include "../common/ledger.h"
#include "../common/interval.h"
#include "../log/log.h"
#include "../cursesAlternative.h"
#include "../creature/creatureEnums.h"
#include "../customMaps.h"
extern Log gamelog;
extern char homedir[MAX_PATH_SIZE];
extern char artdir[MAX_PATH_SIZE];
#include "../common/musicClass.h"
extern MusicClass music;
/* pick a descriptor acronym */
 vector<string> sexdescAcronym;
/* what kind of person? */
 vector<string> sexwhoAcronym;
/* seeking acronym */
 vector<string> sexseekAcronym;
/* what type of sex? */
 vector<string> sextypeAcronym;
 map<short, string> musicList;
void sexdesc(char *str)
{
	strcpy(str, pickrandom(sexdescAcronym).c_str());
}
void sexwho(char *str)
{
	strcpy(str, pickrandom(sexwhoAcronym).c_str());
}
void sexseek(char *str)
{
	strcpy(str, pickrandom(sexseekAcronym).c_str());
}
void sextype(char *str)
{
	strcpy(str, pickrandom(sextypeAcronym).c_str());
}
 vector<string> listOfStates;
 const string mostlyendings = "mostlyendings\\";
 vector<file_and_text_collection> misc_text_file_collection = {
	 customText(&sexdescAcronym, mostlyendings + CONST_misc001),
	 customText(&sexwhoAcronym, mostlyendings + CONST_misc002),
	 customText(&sexseekAcronym, mostlyendings + CONST_misc003),
	 customText(&sextypeAcronym, mostlyendings + CONST_misc004),
	 customText(&listOfStates, mostlyendings + CONST_misc005),
 };
const char* statename(int i)
{
	if (i < 0 || i >= len(listOfStates)) i = LCSrandom(50);
	return listOfStates[i].data();
}
/* EndGameStatus - converts an integer into a roman numeral for amendments */
string romannumeral(int amendnum)
{
	string roman = blankString;
	while (amendnum >= 1000)
	{
		amendnum -= 1000;
		(roman += 'M');
	}
	if (amendnum >= 900)
	{
		amendnum -= 900;
		(roman += 'C');
		(roman += 'M');
	}
	if (amendnum >= 500)
	{
		amendnum -= 500;
		(roman += 'D');
	}
	if (amendnum >= 400)
	{
		amendnum -= 400;
		(roman += 'C');
		(roman += 'D');
	}
	while (amendnum >= 100)
	{
		amendnum -= 100;
		(roman += 'C');
	}
	if (amendnum >= 90)
	{
		amendnum -= 90;
		(roman += 'X');
		(roman += 'C');
	}
	if (amendnum >= 50)
	{
		amendnum -= 50;
		(roman += 'L');
	}
	if (amendnum >= 40)
	{
		amendnum -= 40;
		(roman += 'X');
		(roman += 'L');
	}
	while (amendnum >= 10)
	{
		amendnum -= 10;
		(roman += 'X');
	}
	if (amendnum >= 9)
	{
		amendnum -= 9;
		(roman += 'I');
		(roman += 'X');
	}
	if (amendnum >= 5)
	{
		amendnum -= 5;
		(roman += 'V');
	}
	if (amendnum >= 4)
	{
		amendnum -= 4;
		(roman += 'I');
		(roman += 'V');
	}
	while (amendnum >= 1)
	{
		amendnum -= 1;
		(roman += 'I');
	}
	return roman;
}
#ifndef DONT_INCLUDE_SDL
bool oggsupport = true;
Mix_Music* songs[MUSIC_OFF];
bool songsinitialized = false;
int musicmode = MUSIC_OFF;
int previous = MUSIC_OFF;
/* helper function for initsongs() */
void loadsong(int i, const char* filename)
{  // the reason it prints progress on the screen is because it might be a little slow sometimes so this reassures the user progress is being made
	eraseAlt();
	if (oggsupport)
	{
		mvaddstrAlt(12, 0, CONST_misc006 + tostring(i + 1) + CONST_miscB021 + tostring(MUSIC_OFF) + CONST_miscC026 + artdir + CONST_misc009 + filename + CONST_miscB022);
		mvaddstrAlt(13, 0, string(CONST_misc007) + artdir + CONST_misc011 + filename + CONST_miscB020);
	}
	else mvaddstrAlt(12, 0, CONST_misc008 + tostring(i + 1) + CONST_miscB021 + tostring(MUSIC_OFF) + CONST_miscC026 + artdir + CONST_misc011 + filename + CONST_miscB024);
	refreshAlt();
	if (oggsupport) songs[i] = Mix_LoadMUS((string(artdir) + CONST_misc009 + filename + CONST_miscB022).c_str()); // only attempt loading Ogg if we have Ogg support
	if (!songs[i] || !oggsupport) // it failed to load Ogg Vorbis music or Ogg support doesn't exist, let's try MIDI instead
	{
		if (oggsupport) gamelog.log(string(CONST_misc012) + artdir + CONST_misc009 + filename + CONST_miscB023 + Mix_GetError()); // Ogg Vorbis music failed to load
		songs[i] = Mix_LoadMUS((string(artdir) + CONST_misc011 + filename + CONST_miscB024).c_str());
	}
	if (!songs[i]) // there was an error with Mix_LoadMUS() when called on the MIDI file
		gamelog.log(string(CONST_misc012) + artdir + CONST_misc011 + filename + CONST_miscB025 + Mix_GetError()); // MIDI music failed to load
}
#endif // DONT_INCLUDE_SDL
/* initialize SDL, SDL_mixer, and songs */
void MusicClass::init()
{
#ifndef DONT_INCLUDE_SDL
	if (songsinitialized) return; // only initialize once
	if (SDL_Init(SDL_INIT_AUDIO) != 0) // initialize what we need from SDL for audio
	{  // SDL failed to initialize, so log it and exit
		addstrAlt(string(CONST_misc013) + SDL_GetError(), gamelog);
		gamelog.nextMessage();
 	pressAnyKey();
		endwinAlt();
		exit(EXIT_FAILURE);
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) != 0) // initialize the audio mixer at 44.1 kHz with a large buffer size, since we're just playing music not sound effects
	{  // SDL_mixer failed to initialize, so log it and exit
		addstrAlt(string(CONST_misc014) + Mix_GetError(), gamelog);
		gamelog.nextMessage();
 	pressAnyKey();
		SDL_Quit();
		endwinAlt();
		exit(EXIT_FAILURE);
	}
	if ((Mix_Init(MIX_INIT_OGG | MIX_INIT_FLUIDSYNTH)&MIX_INIT_OGG) != MIX_INIT_OGG) // initialize Ogg Vorbis support (and FluidSynth if it's there for better MIDI quality)
	{  // Ogg Vorbis support failed to load, we'll use MIDI instead
		gamelog.log(CONST_misc015);
		gamelog.nextMessage();
		oggsupport = false;
	}
	else oggsupport = true; // we have Ogg Vorbis support!
		
	// titlemode.ogg or .mid - Also sprach Zarathustra, introduction by Richard Strauss
	loadsong(MUSIC_TITLEMODE, musicList[MUSIC_TITLEMODE].data()), // load title mode music
																  // newgame.ogg or .mid- The Liberty Bell March by John Philip Sousa
		loadsong(MUSIC_NEWGAME, musicList[MUSIC_NEWGAME].data()), // load new game music
																  // basemode.ogg or .mid - The Stars and Stripes Forever by John Philip Sousa
		loadsong(MUSIC_BASEMODE, musicList[MUSIC_BASEMODE].data()), // load regular base mode music
																	// siege.ogg or .mid- The Planets, 1st Movement CONST_misc016 by Gustav Holst
		loadsong(MUSIC_SIEGE, musicList[MUSIC_SIEGE].data()), // load base mode while under siege music
															  // activate.ogg or .mid - Piano Sonata #11, 3rd Movement "Rondo Alla Turca" by Wolfgang Amadeus Mozart
		loadsong(MUSIC_ACTIVATE, musicList[MUSIC_ACTIVATE].data()), // load activate Liberals music
																	// sleepers.ogg or .mid - Toccata and Fugue in D Minor, BWV 565 by Johann Sebastian Bach
		loadsong(MUSIC_SLEEPERS, musicList[MUSIC_SLEEPERS].data()), // load activate Sleepers music
																	// stopevil.ogg or .mid - Hungarian Dance #5 by Johannes Brahms (based on the csardas "Bartfai emlek" by Bela Keler)
		loadsong(MUSIC_STOPEVIL, musicList[MUSIC_STOPEVIL].data()), // load go forth to stop evil music
																	// reviewmode.ogg or .mid - Symphony #94, 2nd Movement "Surprise Symphony" by Joseph Haydn
		loadsong(MUSIC_REVIEWMODE, musicList[MUSIC_REVIEWMODE].data()), // load review mode music
																		// liberalagenda.ogg or .mid - Beautiful Dreamer by Stephen Foster
		loadsong(MUSIC_LIBERALAGENDA, musicList[MUSIC_LIBERALAGENDA].data()), // load status of the Liberal agenda music
																			  // disbanded.ogg or .mid - La Cucaracha, a traditional Mexican folk song originally from Spain
		loadsong(MUSIC_DISBANDED, musicList[MUSIC_DISBANDED].data()), // load disbanded music
																	  // finances.ogg or .mid - Minuet in G Major by Christian Petzold (falsely attributed to Johann Sebastian Bach until 1970)
		loadsong(MUSIC_FINANCES, musicList[MUSIC_FINANCES].data()), // load finance report music
																	// cartheft.ogg or .mid - The Ride of the Valkyries by Richard Wanger
		loadsong(MUSIC_CARTHEFT, musicList[MUSIC_CARTHEFT].data()), // load car theft music
																	// elections.ogg or .mid - Habanera from Carmen by Georges Bizet
		loadsong(MUSIC_ELECTIONS, musicList[MUSIC_ELECTIONS].data()), // load elections music
																	  // shopping.ogg or .mid - The Entertainer by Scott Joplin
		loadsong(MUSIC_SHOPPING, musicList[MUSIC_SHOPPING].data()), // load shopping music
																	// sitemode.ogg or .mid - Dance of the Sugar Plum Fairy by Pyotr Ilyich Tchaikovsky
		loadsong(MUSIC_SITEMODE, musicList[MUSIC_SITEMODE].data()), // load site mode music
																	// suspicious.ogg or .mid - Hall of the Mountain King by Edvard Grieg
		loadsong(MUSIC_SUSPICIOUS, musicList[MUSIC_SUSPICIOUS].data()), // load suspicious music
																		// alarmed.ogg or .mid - 5th Symphony, 1st Movement by Ludwig van Beethoven
		loadsong(MUSIC_ALARMED, musicList[MUSIC_ALARMED].data()), // load alarmed music
																  // heavycombat.ogg or .mid - 6th Symphony CONST_misc017, 4th Movement by Ludwig van Beethoven
		loadsong(MUSIC_HEAVYCOMBAT, musicList[MUSIC_HEAVYCOMBAT].data()), // load massive Conservative response music
																		  // defense.ogg or .mid - Danse Macabre by Camille Saint-Saens
		loadsong(MUSIC_DEFENSE, musicList[MUSIC_DEFENSE].data()), // load escaping/engaging a siege music
																  // conquer.ogg or .mid - Infernal Galop / Can-Can from Orpheus in the Underworld by Jacques Offenbach
		loadsong(MUSIC_CONQUER, musicList[MUSIC_CONQUER].data()), // load success in conquering a siege or safehouse or the CCS music
																  // carchase.ogg or .mid - The William Tell Overture by Gioacchino Antonio Rossini
		loadsong(MUSIC_CARCHASE, musicList[MUSIC_CARCHASE].data()), // load car chase music
																	// footchase.ogg or .mid - The Maple Leaf Rag by Scott Joplin
		loadsong(MUSIC_FOOTCHASE, musicList[MUSIC_FOOTCHASE].data()), // load foot chase music
																	  // InterrogationST.ogg or .mid - Night on Bald Mountain by Modest Mussorgsky
		loadsong(MUSIC_INTERROGATION, musicList[MUSIC_INTERROGATION].data()), // load InterrogationST music
																			  // trial.ogg or .mid - Hungarian Rhapsody #2 by Franz Liszt
		loadsong(MUSIC_TRIAL, musicList[MUSIC_TRIAL].data()), // load trial music
															  // recruiting.ogg or .mid - Dance of the Hours by Amilcare Ponchielli
		loadsong(MUSIC_RECRUITING, musicList[MUSIC_RECRUITING].data()), // load recruiting music
																		// dating.ogg or .mid - The Blue Danube Waltz by Johann Strauss Jr.
		loadsong(MUSIC_DATING, musicList[MUSIC_DATING].data()), // load dating music
																// newspaper.ogg or .mid - Eine Kleine Nachtmusik, 1st Movement by Wolfgang Amadeus Mozart
		loadsong(MUSIC_NEWSPAPER, musicList[MUSIC_NEWSPAPER].data()), // load newspaper music
																	  // lacops.ogg or .mid - The Flight of the Bumblebee by Nikolai Rimsky-Korsakov
		loadsong(MUSIC_LACOPS, musicList[MUSIC_LACOPS].data()), // load LA cops beating black man and getting caught on video music
																// newscast.ogg or .mid - La Marseillaise, The French National Anthem by Claude Joseph Rouget de Lisle
		loadsong(MUSIC_NEWSCAST, musicList[MUSIC_NEWSCAST].data()), // load newscast where smart liberal guest gets some words in edgewise music
																	// glamshow.ogg or .mid - Das Deutschlandlied, The German National Anthem by Joseph Haydn
		loadsong(MUSIC_GLAMSHOW, musicList[MUSIC_GLAMSHOW].data()), // load glamorous TV show about lifestyles of the rich and famous music
																	// anchor.ogg or .mid - I Am the Very Model of a Modern Major-General by Sir Arthur Seymour Sullivan
		loadsong(MUSIC_ANCHOR, musicList[MUSIC_ANCHOR].data()), // load handsome charismatic new Conservative cable news anchor music
																// abort.ogg or .mid - Tarantella Napoletana, a traditional Italian folk song from Naples
		loadsong(MUSIC_ABORT, musicList[MUSIC_ABORT].data()), // load failed partial birth abortion on trashy daytime talk show music
															  // victory.ogg or .mid - The Star-Spangled Banner, The U.S. National Anthem by John Stafford Smith
		loadsong(MUSIC_VICTORY, musicList[MUSIC_VICTORY].data()), // load victory music
																  // defeat.ogg or .mid - Piano Sonata #2, 3rd Movement "Funeral March" by Frederic Francois Chopin
		loadsong(MUSIC_DEFEAT, musicList[MUSIC_DEFEAT].data()), // load defeat music
																// reagainified.ogg or .mid - Dixie, The Confederate National Anthem by Daniel Decatur Emmett
		loadsong(MUSIC_REAGANIFIED, musicList[MUSIC_REAGANIFIED].data()), // load Reaganified music
																		  // stalinized.ogg or .mid - The Soviet (and now Russian) National Anthem by Alexander Vasilyevich Alexandrov
		loadsong(MUSIC_STALINIZED, musicList[MUSIC_STALINIZED].data()), // load Stalinized music
		eraseAlt();
	refreshAlt();
	songsinitialized = true;
#endif // DONT_INCLUDE_SDL
}
/* shut down SDL, SDL_mixer, and songs */
void MusicClass::quit()
{
#ifndef DONT_INCLUDE_SDL
	if (!songsinitialized) return; // only shut down once
	music.play(MUSIC_OFF);
	for (int c = 0; c < MUSIC_OFF; c++) if (songs[c]) Mix_FreeMusic(songs[c]);
	while (Mix_Init(0)) Mix_Quit();
	Mix_CloseAudio();
	SDL_Quit();
	songsinitialized = false;
#endif // DONT_INCLUDE_SDL
}
/* play music specified by a MusicMode */
void MusicClass::play(int _musicmode)
{
#ifndef DONT_INCLUDE_SDL
	if (!songsinitialized) init(); // if it hasn't been initialized already, do it now
	if (_musicmode == MUSIC_CURRENT) return; // keep playing current music if that's what's requested
	if (_musicmode == MUSIC_RANDOM) _musicmode = LCSrandom(MUSIC_OFF); // play a random song if that's what's requested
	if (_musicmode == MUSIC_PREVIOUS) _musicmode = previous; // restore previous setting if that's what's requested
	if (musicmode == _musicmode) return; // already playing the right music
	previous = musicmode; // store previous setting
	musicmode = _musicmode; // set musicmode to input
	Mix_HaltMusic(); // stop any music that we're playing
	if (musicmode < 0 || musicmode >= MUSIC_OFF)
	{
		musicmode = MUSIC_OFF; // just in case we had odd input, make sure we keep track that music is off
		return; // return without playing music
	}
	if (!songs[musicmode]) // there was an error with Mix_LoadMUS() back when it was called on this song
		return; // we can't play music if it isn't loaded, might as well return
	if (Mix_PlayMusic(songs[musicmode], -1) != 0) // start playing the music, and have it loop indefinitely
		gamelog.log(string(CONST_misc018) + Mix_GetError()); // Music failed to play
	enableIf(isEnabled());
#endif // DONT_INCLUDE_SDL
}
	Interval::Interval() : min(0), max(0) { }
	Interval::Interval(int value) : min(value), max(value) { }
	Interval::Interval(int low, int high) : min(low), max(high) { }
	void Interval::set_interval(int low, int high) { min = low, max = high; }
	// Sets the interval according to a string that is either a number or two
	// number separated by a dash. Returns false and does not change the
	// interval if the given string is not a valid interval.
	// Sets the interval according to a string that is either a number or two
	// number separated by a dash. Returns false and does not change the
	// interval if the given string is not a valid interval.
	bool valid(const string& v);
	bool Interval::set_interval(const string& interval)
	{
		if (!len(interval) ||
			interval.find_first_not_of(CONST_misc019) != string::npos)
			return false;
		size_t dashpos = interval.find('-', 1);
		if (dashpos == string::npos) // Just a constant.
		{
			if (!valid(interval)) return false;
			max = min = atoi(interval.c_str());
		}
		else
		{
			string smin = interval.substr(0, dashpos), smax = interval.substr(dashpos + 1);
			if (!valid(smin) || !valid(smax)) return false;
			int tmin = atoi(smin.c_str()), tmax = atoi(smax.c_str());
			if (tmin > tmax) return false;
			min = tmin, max = tmax;
		}
		return true;
	}
	int Interval::roll() const { return LCSrandom(max - min + 1) + min; }
	bool valid(const string& v)
	{
		return len(v) &&                       // Blank string is invalid.
			(len(v) != 1 || v[0] != '-') &&        // Just a dash is invalid.
			v.find('-', 1) == string::npos;
	} 
	Ledger::Ledger() : funds(7), total_income(0), total_expense(0)
	{
		for (int i = 0; i<INCOMETYPENUM; i++) income[i] = 0, dailyIncome[i] = 0;
		for (int e = 0; e<EXPENSETYPENUM; e++) expense[e] = 0, dailyExpense[e] = 0;
	}
	int Ledger::get_funds() { return funds; }
	void Ledger::force_funds(int amount) { funds = amount; }
	void Ledger::add_funds(int amount, int incometype)
	{
		funds += amount,
			income[incometype] += amount,
			dailyIncome[incometype] += amount,
			total_income += amount;
	}
	void Ledger::subtract_funds(int amount, int expensetype)
	{
		funds -= amount,
			expense[expensetype] += amount,
			dailyExpense[expensetype] += amount,
			total_expense += amount;
	}
	void Ledger::resetMonthlyAmounts()
	{
		for (int i = 0; i<INCOMETYPENUM; i++) income[i] = 0;
		for (int e = 0; e<EXPENSETYPENUM; e++) expense[e] = 0;
	}
	void Ledger::resetDailyAmounts()
	{
		for (int i = 0; i<INCOMETYPENUM; i++) dailyIncome[i] = 0;
		for (int e = 0; e<EXPENSETYPENUM; e++) dailyExpense[e] = 0;
	}
	MusicClass::MusicClass() : enabled(true) { }
	bool MusicClass::isEnabled() { return enabled; }
	void MusicClass::enableIf(bool e)
	{
		enabled = e;
#ifndef DONT_INCLUDE_SDL
		Mix_VolumeMusic(enabled*(MIX_MAX_VOLUME / 2)); // half volume if music enabled, muted if music disabled
#endif // DONT_INCLUDE_SDL
	}