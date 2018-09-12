
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
#include "../common/musicClass.h"
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
string sexdesc()
{
	return pickrandom(sexdescAcronym);
}
string sexwho()
{
	return pickrandom(sexwhoAcronym);
}
string sexseek()
{
	return pickrandom(sexseekAcronym);
}
string sextype()
{
	return pickrandom(sextypeAcronym);
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
	if (i < 0 || i >= len(listOfStates)) i = LCSrandom(len(listOfStates));
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
{
	extern Log gamelog;
	extern char artdir[MAX_PATH_SIZE];
	// the reason it prints progress on the screen is because it might be a little slow sometimes so this reassures the user progress is being made
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
	extern Log gamelog;
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
	extern MusicClass music;
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
	extern Log gamelog;
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
	class Ledger ledger;
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




	// Functions removed from elsewhere that require no #include
	// except for enumerators and standard libraries
	// Most of these can be simplified through use of maps and other data structured
	// Which will assist in future additions or changes



	bool sitealarm;
	bool isThereASiteAlarm() {
		return sitealarm;
	}
	void setSiteAlarmOne() {
		sitealarm = true;
	}
	void resetSiteAlarm() {
		sitealarm = false;
	}

	void addCrackhouse(int creaturearray[CREATURENUM]) {
		extern char endgamestate;
		extern short lawList[LAWNUM];

		if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
		if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 2;
		if (lawList[LAW_POLLUTION] == -2 &&
			lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 50;
		if (endgamestate<ENDGAME_CCS_DEFEATED && endgamestate>ENDGAME_NONE)
			creaturearray[CREATURE_CCS_VIGILANTE] += 5;
	}
	void addCigarbar(int creaturearray[CREATURENUM], const char sec) {
		extern char endgamestate;
		extern short lawList[LAWNUM];
		if (sec || isThereASiteAlarm())creaturearray[CREATURE_BOUNCER] += 100;
		else creaturearray[CREATURE_BOUNCER] += 10;
		if (sec)creaturearray[CREATURE_GUARDDOG] += 25;
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] += 2;
		if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] += 2;
		if (endgamestate<ENDGAME_CCS_DEFEATED && endgamestate>ENDGAME_NONE)
			creaturearray[CREATURE_CCS_VIGILANTE] += 5;

	}
	void addWhitehouse(int creaturearray[CREATURENUM], const char sec) {

		extern char endgamestate;
		extern short exec[EXECNUM];


		if (sec)creaturearray[CREATURE_SECRET_SERVICE] += 100;
		else creaturearray[CREATURE_SECRET_SERVICE] += 5;
		if (endgamestate<ENDGAME_CCS_DEFEATED && endgamestate>ENDGAME_NONE && exec[EXEC_PRESIDENT] < ALIGN_CONSERVATIVE)
			creaturearray[CREATURE_CCS_ARCHCONSERVATIVE] += 1;
	}
	void addLatteStandOrPark(int creaturearray[CREATURENUM]) {
		extern short lawList[LAWNUM];
		extern char endgamestate;



		if (lawList[LAW_LABOR] < 2)creaturearray[CREATURE_WORKER_FACTORY_NONUNION] += 5;
		if (lawList[LAW_LABOR] >= 0)creaturearray[CREATURE_WORKER_FACTORY_UNION] += 5;
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] += 2;
		if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] += 2;
		if (endgamestate<ENDGAME_CCS_DEFEATED && endgamestate>ENDGAME_NONE)
			creaturearray[CREATURE_CCS_VIGILANTE] += endgamestate * 4;
		if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 1;
		if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 1;
		if (lawList[LAW_POLLUTION] == -2 &&
			lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] += 1;
		else creaturearray[CREATURE_PRISONGUARD] += 1;
	}
	void addVeganCoop(int creaturearray[CREATURENUM]) {
		extern short lawList[LAWNUM];



		if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 1;
		if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 1;
		if (lawList[LAW_POLLUTION] == -2 &&
			lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
	}

	void addShelter(int creaturearray[CREATURENUM]) {
		extern short lawList[LAWNUM];



		if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
		if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 2;
		if (lawList[LAW_POLLUTION] == -2 &&
			lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 50;
	}
	void addTenement(int creaturearray[CREATURENUM]) {
		extern short lawList[LAWNUM];



		if (lawList[LAW_LABOR] < 2)creaturearray[CREATURE_WORKER_FACTORY_NONUNION] += 1;
		if (lawList[LAW_LABOR] >= 0)creaturearray[CREATURE_WORKER_FACTORY_UNION] += 1;
		if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
		if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 2;
		if (lawList[LAW_POLLUTION] == -2 &&
			lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 5;
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] += 1;
		else creaturearray[CREATURE_PRISONGUARD] += 1;
	}
	void addApartment(int creaturearray[CREATURENUM]) {
		extern short lawList[LAWNUM];


		if (lawList[LAW_LABOR] < 2)creaturearray[CREATURE_WORKER_FACTORY_NONUNION] = 1;
		if (lawList[LAW_LABOR] >= 0)creaturearray[CREATURE_WORKER_FACTORY_UNION] = 1;
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] += 1;
		if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] += 1;
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] += 1;
		else creaturearray[CREATURE_PRISONGUARD] += 1;
	}

	void addIntelligence(int creaturearray[CREATURENUM], const char sec) {


		if (sec)creaturearray[CREATURE_AGENT] += 1000;
		else creaturearray[CREATURE_AGENT] += 100;
		if (sec)creaturearray[CREATURE_GUARDDOG] += 450;

	}
	void addArmyBase(int creaturearray[CREATURENUM], const char sec) {

		if (sec)creaturearray[CREATURE_GUARDDOG] += 230;
		if (sec)creaturearray[CREATURE_MILITARYPOLICE] += 100;
	}
	void addSweatShop(int creaturearray[CREATURENUM], const char sec) {


		if (sec)creaturearray[CREATURE_SECURITYGUARD] += 1000;
		else creaturearray[CREATURE_SECURITYGUARD] += 100;
	}
	void addIndustryPolluter(int creaturearray[CREATURENUM], const char sec) {
		extern short lawList[LAWNUM];
		if (sec)creaturearray[CREATURE_SECURITYGUARD] += 100;

		if (lawList[LAW_LABOR] == -2)
		{
			creaturearray[CREATURE_WORKER_FACTORY_NONUNION] += 20;
			creaturearray[CREATURE_WORKER_FACTORY_CHILD] += 140;
		}
		else if (lawList[LAW_LABOR] == -1)
		{
			creaturearray[CREATURE_WORKER_FACTORY_NONUNION] += 160;
			creaturearray[CREATURE_WORKER_FACTORY_CHILD] += 1;
		}
		else if (lawList[LAW_LABOR] == 0)
		{
			creaturearray[CREATURE_WORKER_FACTORY_NONUNION] += 80;
			creaturearray[CREATURE_WORKER_FACTORY_UNION] += 80;
		}
		else if (lawList[LAW_LABOR] == 1)
		{
			creaturearray[CREATURE_WORKER_FACTORY_NONUNION] = 50;
			creaturearray[CREATURE_WORKER_FACTORY_UNION] = 110;
		}
		else creaturearray[CREATURE_WORKER_FACTORY_UNION] = 160;
	}
	void addCorpHQ(int creaturearray[CREATURENUM], const char sec) {

		if (sec)creaturearray[CREATURE_GUARDDOG] += 100;
		if (sec)creaturearray[CREATURE_SECURITYGUARD] = 400;
		else creaturearray[CREATURE_SECURITYGUARD] = 40;
	}
	void addCorpHouse(int creaturearray[CREATURENUM], const char sec) {



		if (sec)creaturearray[CREATURE_MERC] = 100;
		if (sec)creaturearray[CREATURE_GUARDDOG] = 50;
		else creaturearray[CREATURE_GUARDDOG] = 5;
	}
	void addMediaAMRadio(int creaturearray[CREATURENUM], const char sec) {


		if (sec)creaturearray[CREATURE_SECURITYGUARD] = 100;
		else creaturearray[CREATURE_SECURITYGUARD] = 10;
	}
	void addMediaCablenews(int creaturearray[CREATURENUM], const char sec) {

		if (sec)creaturearray[CREATURE_SECURITYGUARD] = 100;
		else creaturearray[CREATURE_SECURITYGUARD] = 10;

	}

	void addLaboratoryCosmetics(int creaturearray[CREATURENUM], const char sec) {


		if (sec)creaturearray[CREATURE_SECURITYGUARD] += 100;
		else creaturearray[CREATURE_SECURITYGUARD] += 3;
	}
	void addIndustryNuclear(int creaturearray[CREATURENUM], const char sec) {


		if (sec)creaturearray[CREATURE_SECURITYGUARD] += 100;
		else creaturearray[CREATURE_SECURITYGUARD] += 10;
	}
	void addLaboratoryGenetic(int creaturearray[CREATURENUM], const char sec) {



		if (sec)creaturearray[CREATURE_GUARDDOG] += 25;
		if (sec)creaturearray[CREATURE_SECURITYGUARD] += 100;
		else creaturearray[CREATURE_SECURITYGUARD] += 3;
	}
	void addPoliceStation(int creaturearray[CREATURENUM], const char sec) {
		extern short lawList[LAWNUM];



		if (lawList[LAW_LABOR] < 2)creaturearray[CREATURE_WORKER_FACTORY_NONUNION] = 1;
		if (lawList[LAW_LABOR] >= 0)creaturearray[CREATURE_WORKER_FACTORY_UNION] = 1;
		if (sec)creaturearray[CREATURE_COP] += 1000;
		else creaturearray[CREATURE_COP] += 500;
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] += 400;
		if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] += 400;
		if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
		if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 2;
		if (lawList[LAW_POLLUTION] == -2 &&
			lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 5;
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] = 1;
		else creaturearray[CREATURE_PRISONGUARD] = 1;
	}
	void addCourthouse(int creaturearray[CREATURENUM], const char sec) {

		extern short lawList[LAWNUM];


		if (sec)creaturearray[CREATURE_COP] = 2000;
		else creaturearray[CREATURE_COP] = 200;
		if (lawList[LAW_LABOR] < 2)creaturearray[CREATURE_WORKER_FACTORY_NONUNION] = 1;
		if (lawList[LAW_LABOR] >= 0)creaturearray[CREATURE_WORKER_FACTORY_UNION] = 1;
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] = 80;
		if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] = 80;
		if (lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 1;
		if (lawList[LAW_POLLUTION] == -2)creaturearray[CREATURE_MUTANT] += 1;
		if (lawList[LAW_POLLUTION] == -2 &&
			lawList[LAW_NUCLEARPOWER] == -2)creaturearray[CREATURE_MUTANT] += 2;
		if (lawList[LAW_DEATHPENALTY] == -2 &&
			lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_EDUCATOR] = 1;
		else creaturearray[CREATURE_PRISONGUARD] = 1;
	}
	void addFirestation(int creaturearray[CREATURENUM], const char sec) {


		extern short lawList[LAWNUM];

		if (sec)
		{
			if (lawList[LAW_DEATHPENALTY] == -2 &&
				lawList[LAW_POLICEBEHAVIOR] == -2)creaturearray[CREATURE_DEATHSQUAD] += 50;
			else if (lawList[LAW_POLICEBEHAVIOR] <= -1)creaturearray[CREATURE_GANGUNIT] += 50;
			else creaturearray[CREATURE_COP] += 50;
		}
	}

	/* prints a short blurb showing how to page forward */
	string addnextpagestr()
	{
		const string CONST_commondisplay223 = "PGDN";
		const string CONST_commondisplay222 = ":";
		const string CONST_commondisplay221 = "]";
		const string CONST_commondisplay22Z = " - Next";
		string output;
		extern short interface_pgup;
		if (interface_pgup == '[')
			output = CONST_commondisplay221;
		else if (interface_pgup == '.')
			output = CONST_commondisplay222;
		else output = CONST_commondisplay223;
		return output + CONST_commondisplay22Z;
	}
	/* prints a short blurb showing how to page back */
	string addprevpagestr()
	{
		const string CONST_commondisplay226 = "PGUP";
		const string CONST_commondisplay225 = ";";
		const string CONST_commondisplay224 = "[";
		const string CONST_commondisplay22Y = " - Previous";
		string output;
		extern short interface_pgup;
		if (interface_pgup == '[')
			output = CONST_commondisplay224;
		else if (interface_pgup == '.')
			output = CONST_commondisplay225;
		else output = CONST_commondisplay226;
		return output + CONST_commondisplay22Y;
	}
	/* prints a long blurb showing how to page forward and back */
	string addpagestr()
	{
		const string CONST_commondisplay229 = "PGUP/PGDN";
		const string CONST_commondisplay228 = "; and :";
		const string CONST_commondisplay227 = "[]";
		const string CONST_commondisplay22X = " to view other Liberal pages.";
		string output;
		extern short interface_pgup;
		if (interface_pgup == '[')
			output = CONST_commondisplay227;
		else if (interface_pgup == '.')
			output = CONST_commondisplay228;
		else output = CONST_commondisplay229;
		return output + CONST_commondisplay22X;
	}

	/* daily - returns the number of days in the current month */
	int monthday()
	{
		extern int month;
		extern int year;
		switch (month)
		{
		case 2: return 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); // February
		case 4: // April
		case 6: // June
		case 9: // September
		case 11: return 30; // November
		default: return 31; // January, March, May, July, August, October, & December
		}
	}

#include "locations/locationsEnums.h"
	bool populateEncounter(const int type, int creaturearray[CREATURENUM], const char sec) {
		switch (type)
		{
		case SITE_BUSINESS_CRACKHOUSE:
		{
			addCrackhouse(creaturearray);
			break;
		}
		case SITE_BUSINESS_JUICEBAR:
		{
			break;
		}
		case SITE_BUSINESS_CIGARBAR:
		{
			addCigarbar(creaturearray, sec);
			break;
		}
		case SITE_GOVERNMENT_WHITE_HOUSE:
		{
			addWhitehouse(creaturearray, sec);
			break;
		}
		case SITE_OUTDOOR_PUBLICPARK:
		case SITE_BUSINESS_LATTESTAND:
		{
			addLatteStandOrPark(creaturearray);
			break;
		}
		case SITE_BUSINESS_VEGANCOOP:
		{
			addVeganCoop(creaturearray);
			break;
		}
		case SITE_BUSINESS_INTERNETCAFE:
		{
			break;
		}
		default:
		case SITE_RESIDENTIAL_SHELTER:
		{
			addShelter(creaturearray);
			break;
		}
		case SITE_RESIDENTIAL_TENEMENT:
		{
			addTenement(creaturearray);
			return true;
		}
		case SITE_RESIDENTIAL_APARTMENT:
		{
			addApartment(creaturearray);
			return true;
		}

		case SITE_LABORATORY_COSMETICS:
		{
			addLaboratoryCosmetics(creaturearray, sec);
			break;
		}
		case SITE_INDUSTRY_NUCLEAR:
		{
			addIndustryNuclear(creaturearray, sec);
			break;
		}
		case SITE_LABORATORY_GENETIC:
		{
			addLaboratoryGenetic(creaturearray, sec);
			break;
		}
		case SITE_GOVERNMENT_POLICESTATION:
		{
			addPoliceStation(creaturearray, sec);
			break;
		}
		case SITE_GOVERNMENT_COURTHOUSE:
		{
			addCourthouse(creaturearray, sec);
			break;
		}
		case SITE_GOVERNMENT_FIRESTATION:
		{
			addFirestation(creaturearray, sec);
			break;
		}

		case SITE_GOVERNMENT_INTELLIGENCEHQ:
		{
			addIntelligence(creaturearray, sec);
			break;
		}
		case SITE_GOVERNMENT_ARMYBASE:
		{
			addArmyBase(creaturearray, sec);
			break;
		}
		case SITE_INDUSTRY_SWEATSHOP:
		{
			addSweatShop(creaturearray, sec);
			break;
		}
		case SITE_INDUSTRY_POLLUTER:
		{
			addIndustryPolluter(creaturearray, sec);
			break;
		}
		case SITE_CORPORATE_HEADQUARTERS:
		{
			addCorpHQ(creaturearray, sec);
			break;
		}
		case SITE_CORPORATE_HOUSE:
		{
			addCorpHouse(creaturearray, sec);
			break;
		}
		case SITE_MEDIA_AMRADIO:
		{
			addMediaAMRadio(creaturearray, sec);
			break;
		}
		case SITE_MEDIA_CABLENEWS:
		{
			addMediaCablenews(creaturearray, sec);
			break;
		}
		}
		return false;

	}

	int bodypartSeverAmount(const int w) {
		int severamount = 100;
		switch (w)
		{
		case BODYPART_HEAD:severamount = 100; break;
		case BODYPART_BODY:severamount = 1000; break;
		case BODYPART_ARM_RIGHT:severamount = 200; break;
		case BODYPART_ARM_LEFT:severamount = 200; break;
		case BODYPART_LEG_RIGHT:severamount = 400; break;
		case BODYPART_LEG_LEFT:severamount = 400; break;
		}
		return severamount;
	}
	std::string burstHitString(int bursthits) {
		if (bursthits < 1) {
			bursthits = 1;
		}
		const vector<string> numberTimesHit =
		{
			"",
			" twice",
			" three",
			" four",
			" five",
		};
		const string singleSpace = " ";
		const string CONST_fight035 = " times";
		string output;
		if (bursthits > 5) {
			output += singleSpace + tostring(bursthits);
		}
		else {
			output += numberTimesHit[bursthits - 1];
		}
		if (bursthits > 2) {
			output += CONST_fight035;
		}
		return output;
	}
	std::string getlaw(int l)
	{
		extern map<short, string> getLawString;
		const string CONST_getnames043 = "Software Bugs";
		if (getLawString.count(l)) {
			return getLawString[l];
		}
		else {
			return CONST_getnames043;
		}
	}
	std::string cityname()
	{
		extern vector<string> city_names;
		return pickrandom(city_names);
	}

	int getLawFromFlag(int type) {
		if (type == LAWFLAG_BURNFLAG) {
			return LAW_FLAGBURNING;
		}
		else if (type == LAWFLAG_HIREILLEGAL) {
			return LAW_IMMIGRATION;
		}
		return 0;
	}
	std::string getlawflag(int type)
	{
		extern string findingBugs;
		extern map<short, string> getLawFlagString;
		extern map<short, map<short, string> > getLawFlagStringFull;
		extern short lawList[LAWNUM];
		if (getLawFlagStringFull.count(type)) {
			return getLawFlagStringFull[type][lawList[getLawFromFlag(type)]];
		}
		else
			if (getLawFlagString.count(type)) {
				return getLawFlagString[type];
			}
			else {
				return findingBugs;
			}
	}

	/* returns true if the entire site is not open to public */
	char disguisesite(long type)
	{
		switch (type)
		{
		case SITE_LABORATORY_COSMETICS:
		case SITE_LABORATORY_GENETIC:
		case SITE_GOVERNMENT_PRISON:
		case SITE_GOVERNMENT_INTELLIGENCEHQ:
		case SITE_INDUSTRY_SWEATSHOP:
		case SITE_INDUSTRY_POLLUTER:
		case SITE_CORPORATE_HEADQUARTERS:
		case SITE_CORPORATE_HOUSE:
		case SITE_BUSINESS_CIGARBAR:
			return 1;
		}
		return 0;
	}

	/* common - random issue by public interest */
	int randomissue(bool core_only)
	{
		extern char newscherrybusted;
		extern char endgamestate;
		extern short public_interest[VIEWNUM];
		int interest_array[VIEWNUM], total_interest = 0;
		int numviews = core_only ? VIEWNUM - 5 : ((endgamestate >= ENDGAME_CCS_DEFEATED || newscherrybusted < 2) ? VIEWNUM - 1 : VIEWNUM);
		for (int i = 0; i < numviews; i++)
		{
			interest_array[i] = public_interest[i] + total_interest + 25;
			total_interest += public_interest[i] + 25;
		}
		int roll = LCSrandom(total_interest);
		for (int i = 0; i < numviews; i++) if (roll < interest_array[i]) return i;
		return VIEW_MOOD;
	}

	const string singleSpace = " ";
//	const string blankString = "";

	//extern string closeParenthesis;
	//extern string singleSpace;
	void generate_name(char *first, char *last, char gender);
	void firstname(char *str, char gender);
	string lastname(bool archconservative);

	/* fills a string with a proper name */
	void generate_name(char *str, char gender)
	{
		char first[80];
		char last[80];
		generate_name(first, last, gender);
		strcpy(str, first);
		strcat(str, singleSpace.data());
		strcat(str, last);
	}
	string generate_name(char gender) {
		char str[200];
		generate_name(str, gender);
		return str;
	}
	/* get a first and last name for the same person */
	void generate_name(char *first, char *last, char gender)
	{
		do {
			firstname(first, gender);
			strcpy(last, lastname(gender == GENDER_WHITEMALEPATRIARCH).data());
		} while (strcmp(first, last) == 0);
	}
	/* get a first, middle, and last name for the same person */
	void generate_long_name(char *first, char *middle, char *last, char gender)
	{
		// pick either male or female so we can have 75% chance of first and middle names having matching genders
		if (gender == GENDER_NEUTRAL)
			gender = (LCSrandom(2) ? GENDER_MALE : GENDER_FEMALE);
		do {
			firstname(first, gender);
			if (LCSrandom(2)) // middle name is a first name
				firstname(middle, (gender == GENDER_WHITEMALEPATRIARCH || LCSrandom(2) ? gender : GENDER_NEUTRAL)); // 25% chance for middle name of other gender unless white male patriarch
			else // middle name is a last name
				strcpy(middle, lastname(gender == GENDER_WHITEMALEPATRIARCH).data());
			strcpy(last, lastname(gender == GENDER_WHITEMALEPATRIARCH).data());
		} while (strcmp(first, middle) == 0 && strcmp(first, last) == 0 && strcmp(middle, last) == 0);
	}
	string firstname(const char default_gender) {
		string str;
		extern vector<string> male_first_names;
		extern vector<string> female_first_names;
		extern vector<string> gender_neutral_first_names;
		extern vector<string> great_white_male_patriarch_first_names;
		const string CONST_creaturenames009 = "Errol";
		int roll, nametable;
		// If we don't care if the name is male or female, pick one randomly
		// This ensures gender balance in the names chosen
		char gender;
		if (default_gender == GENDER_NEUTRAL) {
			gender = (LCSrandom(2) ? GENDER_MALE : GENDER_FEMALE);
		}
		else {
			gender = default_gender;
		}
		switch (gender) {
		case GENDER_MALE:
			roll = LCSrandom(len(male_first_names) +
				len(gender_neutral_first_names));

			if (roll >= len(gender_neutral_first_names))
				nametable = GENDER_MALE;
			else
				nametable = GENDER_NEUTRAL;
			break;
		case GENDER_FEMALE:
			roll = LCSrandom(len(female_first_names) +
				len(gender_neutral_first_names));
			if (roll >= len(gender_neutral_first_names))
				nametable = GENDER_FEMALE;
			else
				nametable = GENDER_NEUTRAL;
			break;
		case GENDER_WHITEMALEPATRIARCH:
			nametable = GENDER_WHITEMALEPATRIARCH;
			break;

		}
		switch (nametable) {
		case GENDER_MALE:
			str = pickrandom(male_first_names);
			break;
		case GENDER_FEMALE:
			str = pickrandom(female_first_names);
			break;
		case GENDER_NEUTRAL:
			str = pickrandom(gender_neutral_first_names);
			break;
		case GENDER_WHITEMALEPATRIARCH:
			str = pickrandom(great_white_male_patriarch_first_names);
			break;
		default:
			str = CONST_creaturenames009;
			break;
		}
		return str;
	}
	/* gets a random first name */
	void firstname(char *str, char gender)
	{
		strcpy(str, firstname(gender).c_str());
	}
	string lastname(bool archconservative)
		//{{{ Last Name
	{
		extern vector<string> regular_last_names;
		extern vector<string> archconservative_last_names;
		string str;
		// For non-Arch-Conservatives, pick from ALL last names
		if (!archconservative)
		{
			// Roll on the number of non-Arch-Conservative last names,
			// plus the number of regular last names
			int roll = LCSrandom(len(regular_last_names) +
				len(archconservative_last_names));
			// Decide whether to use an Arch-Conservative last name
			// or a regular last name
			archconservative = (roll >= len(regular_last_names));
		}
		// Now the archconservative variable might be true even if the function wasn't called that way,
		// but if it WAS called that way it's definitely true... this way non-Arch-Conservatives get
		// random last names out of all the last names, while Arch-Conservatives are limited to their own
		// last names
		if (archconservative)
			str = pickrandom(archconservative_last_names);
		else
			str = pickrandom(regular_last_names);
		return str;
	}


	vector<int> maleOrFemale = {
		GENDER_MALE,
		GENDER_FEMALE
	};
	/* fills a string with a proper name */
	void generate_name(char *str, char gender = GENDER_NEUTRAL);
	/* get a first and last name for the same person */
	void generate_name(char *first, char *last, char gender = GENDER_NEUTRAL);

	string lastname(bool archconservative = false);
	const char* statename(int state = -1);
	void generate_long_name(char *first, char *middle, char *last, char gender = GENDER_NEUTRAL);

	const string CONST_news700 = "her";
	const string CONST_news378 = "his";
	const string CONST_news647 = "[hurting spree]";
	string isInCustody() {
		char str[200];
		char str2[200];
		generate_name(str, str2);

		const string CONST_news242 = "called the police on a cellphone and they arrived shortly thereafter. ";
		const string CONST_news241 = "verses of the Bible at the stunned onlookers. Someone ";
		const string CONST_news240 = " remained at the scene after the shooting, screaming ";
		const string CONST_news239 = " Witnesses report that ";
		const string CONST_news238 = ", is in custody.&r";
		string output = str \
			+ singleSpace \
			+ str2 \
			+ CONST_news238 \
			+ CONST_news239 \
			+ str2 \
			+ CONST_news240 \
			+ CONST_news241 \
			+ CONST_news242 \
			+ str2;
		return output;
	}
	string atTheAbortionClinic() {
		string story;
		const string CONST_news230 = "Dr. ";
		const string CONST_news229 = " Clinic yesterday. ";
		story += lastname(true) \
			+ CONST_news229 \
			+ CONST_news230;
		return story;
	}
	string abortionDoctorShot() {
		const string CONST_news228 = "gunned down outside of the ";
		const string CONST_news227 = "A doctor that routinely performed abortions was ruthlessly ";
		const string CONST_news226 = "A doctor that routinely performed semi-legal abortions was ruthlessly ";
		const string CONST_news225 = "A doctor that routinely performed illegal abortions was ruthlessly ";
		const string CONST_news224 = "A doctor that routinely performed illegal abortion-murders was ruthlessly ";

		extern short lawList[LAWNUM];

		string story;
		if (lawList[LAW_ABORTION] == -2) story += CONST_news224;
		else if (lawList[LAW_ABORTION] == -1) story += CONST_news225;
		else if (lawList[LAW_ABORTION] == 0) story += CONST_news226;
		else story += CONST_news227;

		story += CONST_news228;

		return story;
	}

	string howCrazyIsKiller() {
		string story;
		extern short lawList[LAWNUM];

		const string CONST_news246 = "had been completed.&r";
		const string CONST_news245 = " surrendered without a struggle, reportedly saying that God's work ";
		const string CONST_news244 = " abortion doctors as opposed to arresting them.&r";
		const string CONST_news243 = " later admitted to being a rogue FBI vigilante, hunting down ";

		if (lawList[LAW_WOMEN] == -2)
		{
			story += CONST_news243 \
				+ CONST_news244;
		}
		else
		{
			story += CONST_news245 \
				+ CONST_news246;
		}


		return story;
	}

	string newsOnKiller() {
		string story;

		const string CONST_news250 = " and ";
		const string CONST_news249 = "wife";
		const string CONST_news248 = " is survived by ";

		const string CONST_news237 = "The suspected shooter, ";
		const string CONST_news236 = " times and died immediately in the parking lot. ";
		const string CONST_news235 = " was hit ";
		const string CONST_news234 = "shots were fired from a nearby vehicle. ";
		const string CONST_news233 = " car when, according to police reports, ";
		const string CONST_news232 = " was walking to ";

		const string CONST_newsB925 = "husband";

		extern short lawList[LAWNUM];

		const char gn = pickrandom(maleOrFemale);

		char dstr[200], dstr2[200];
		generate_name(dstr, dstr2, gn);

		story += dstr \
			+ singleSpace \
			+ dstr2;
		char gen[200];
		strcpy(gen, (gn == GENDER_FEMALE ? CONST_news700 : CONST_news378).data());

		story += CONST_news232 \
			+ gen;//TODO() Add more variety, not just in the parking lot.
		story += CONST_news233 \
			+ CONST_news234 \
			+ dstr2 \
			+ CONST_news235 \
			+ tostring(LCSrandom(15) + 3) \
			+ CONST_news236 \
			+ CONST_news237;


		story += isInCustody();
		story += howCrazyIsKiller();
		story += singleSpace \
			+ dstr2 \
			+ CONST_news248 \
			+ gen \
			+ singleSpace;

		char spouse = pickrandom(maleOrFemale);
		if (lawList[LAW_GAY] <= 1)
			spouse = (gn == GENDER_FEMALE ? GENDER_MALE : GENDER_FEMALE);

		story += (spouse == GENDER_FEMALE ? CONST_news249 : CONST_newsB925) \
			+ CONST_news250;

		return story;
	}
	string constructVIEW_WOMEN()
	{
		const string CONST_news255 = " children.&r";

		extern string spaceDashSpace;

		string story;

		story = cityname();
		story += spaceDashSpace;

		story += abortionDoctorShot();

		story += atTheAbortionClinic();
		story += newsOnKiller();

		vector<string> two_to_five = {
			"two",
			"three",
			"four",
			"five"
		};
		story += pickrandom(two_to_five) \
			+ CONST_news255;

		return story;
	}

	string getPhraseDrunkDriving() {

		string story;
		extern short lawList[LAWNUM];

		const string CONST_news270 = "taking swipes";
		const string CONST_news269 = "urinating out the window";
		const string CONST_news268 = "pissing out the window";
		const string CONST_news267 = "[relieving themselves] out the window";
		const string CONST_news266 = "throwing beer bottles";
		const string CONST_news265 = "throwing [juice boxes]";

		switch (LCSrandom(3))
		{
		case 0:
			if (lawList[LAW_FREESPEECH] == -2) story += CONST_news265;
			else story += CONST_news266;
			break;
		case 1:
			if (lawList[LAW_FREESPEECH] == -2) story += CONST_news267;
			else if (lawList[LAW_FREESPEECH] == 2) story += CONST_news268;
			else story += CONST_news269;
			break;
		case 2: story += CONST_news270; break;
		}

		return story;
	}

	string getPhraseKnownHomosexual() {


		const string CONST_news258 = "a homosexual, was ";
		const string CONST_news257 = "a known homosexual, was ";
		const string CONST_news256 = "a known sexual deviant, was ";

		string story;

		extern short lawList[LAWNUM];

		if (lawList[LAW_GAY] == -2) story += CONST_news256;
		else if (lawList[LAW_GAY] == -1) story += CONST_news257;
		else story += CONST_news258;


		return story;
	}

	string getPhraseNoEmpathyForHomosexual(const string dstr, const string dstr2) {

		extern string singleDot;
		const string CONST_news279 = ", even though being gay is deviant, as we all know.";
		const string CONST_news278 = " is a known faggot";
		const string CONST_news277 = ", despite the fact that ";
		string story;
		extern short lawList[LAWNUM];


		if (lawList[LAW_GAY] == -2 && lawList[LAW_FREESPEECH] != -2)
		{
			story += CONST_news277 \
				+ dstr \
				+ singleSpace \
				+ dstr2 \
				+ CONST_news278;
		}
		else if (lawList[LAW_GAY] == -2)story += CONST_news279;
		else story += singleDot;

		return story;
	}
	string constructVIEW_GAY()
	{
		const string CONST_news276 = "aggravated nature of the offense";
		const string CONST_news275 = "prosecute this case as a hate crime, due to the ";
		const string CONST_news274 = " Authorities have stated that they will vigorously ";
		const string CONST_news273 = "at which point they were taken into custody. Nobody was seriously injured during the incident.";
		const string CONST_news272 = "The chase ended when ";
		const string CONST_news271 = " at the pursuing police cruisers. ";

		const string CONST_news264 = "murderers swerving wildly, ";
		const string CONST_news263 = " Witnesses of the freeway chase described the pickup of the alleged ";
		const string CONST_news262 = "have not yet been released.";
		const string CONST_news261 = "were apprehended after a high speed chase. Their names ";
		const string CONST_news260 = "A police spokesperson reported that four suspects ";
		const string CONST_news259 = " here yesterday. ";


		extern string commaSpace;

		extern vector<string> vigilante_murder;
		extern vector<string> why_chase_ended;

		extern string spaceDashSpace;
		extern string ampersandR;

		string story;
		story = cityname();
		story += spaceDashSpace;

		char dstr[200], dstr2[200];
		generate_name(dstr, dstr2);

		story += dstr \
			+ singleSpace \
			+ dstr2 \
			+ commaSpace;


		story += getPhraseKnownHomosexual();

		story += pickrandom(vigilante_murder) \
			+ CONST_news259 \
			+ CONST_news260 \
			+ CONST_news261 \
			+ CONST_news262 \
			+ ampersandR \
			+ CONST_news263 \
			+ CONST_news264;

		story += getPhraseDrunkDriving();

		story += CONST_news271 \
			+ CONST_news272 \
			+ pickrandom(why_chase_ended) \
			+ " " \
			+ CONST_news273 \
			+ ampersandR \
			+ CONST_news274 \
			+ CONST_news275 \
			+ CONST_news276;

		story += getPhraseNoEmpathyForHomosexual(dstr, dstr2);

		story += ampersandR;

		return story;
	}
	string constructVIEW_FREESPEECH()
	{
		const string CONST_news441 = "_";

		const string CONST_news345 = "?";
		const string CONST_news344 = "Mamma, why did they kill ";
		const string CONST_news343 = " dead?";
		const string CONST_news342 = "Mamma, is ";
		const string CONST_news340 = "many area children spontaneously broke into tears. One child was ";
		const string CONST_news339 = " When the decision to ban the book was announced yesterday, ";
		const string CONST_news338 = " as key evidence of the dark nature of the book.";
		const string CONST_news337 = "a child that ";
		const string CONST_news336 = "a child that said a magic spell at her parents";
		const string CONST_news335 = "a child that swore in class";
		const string CONST_news334 = "In their complaint, the groups cited an incident involving ";
		const string CONST_news332 = "some conservatives feel that the books ";
		const string CONST_news331 = "Although the series is adored by children worldwide, ";
		const string CONST_news329 = ". ";
		const string CONST_news328 = " author ";
		const string CONST_news327 = "_, is the third in an immensely popular series by ";
		const string CONST_news325 = "_and_the_";
		const string CONST_news322 = " The book, ";
		const string CONST_news321 = "the city bowed to pressure from religious groups.";
		const string CONST_news320 = " - A children's story has been removed from libraries here after ";

		const string CONST_newsX02 = "heard saying, \"";

		const string CONST_news1030 = "\"";

		const string CONST_news485 = ". ";


		extern vector<string> book_title;
		extern vector<string> book_title_2;
		extern vector<string> random_nationality;
		extern vector<string> conservative_oppose_book;

		extern string spaceDashSpace;
		extern string ampersandR;
		extern string singleDot;
		extern vector<string> petty_violence;
		extern vector<string> his_her;
		extern vector<string> older_younger;
		extern vector<string> brother_sister;

		string story;
		story = cityname();
		story += CONST_news320 \
			+ CONST_news321 \
			+ ampersandR \
			+ CONST_news322 \
			+ CONST_news441;

		char dstr[200], nstr[200];

		generate_name(nstr, dstr);

		story += nstr \
			+ CONST_news441 \
			+ dstr \
			+ CONST_news325 \
			+ pickrandom(book_title) \
			+ CONST_news441 \
			+ pickrandom(book_title_2) \
			+ CONST_news327 \
			+ pickrandom(random_nationality) \
			+ CONST_news328;

		char c[2] = { 0,0 };

		c[0] = 'A' + LCSrandom(26);

		story += c \
			+ singleDot;

		c[0] = 'A' + LCSrandom(26);

		story += c \
			+ CONST_news329;

		strcpy(dstr, lastname().data());

		story += dstr \
			+ CONST_news485 \
			+ CONST_news331 \
			+ CONST_news332 \
			+ pickrandom(conservative_oppose_book) \
			+ singleSpace \
			+ CONST_news334;

		switch (LCSrandom(3))
		{
		case 0: story += CONST_news335; break;
		case 1: story += CONST_news336; break;
		case 2: story += CONST_news337 \
			+ pickrandom(petty_violence) \
			+ singleSpace \
			+ pickrandom(his_her) \
			+ singleSpace \
			+ pickrandom(older_younger) \
			+ singleSpace \
			+ pickrandom(brother_sister);
			break;
		}

		story += CONST_news338 \
			+ ampersandR \
			+ CONST_news339 \
			+ CONST_news340 \
			+ CONST_newsX02;

		switch (LCSrandom(2))
		{
		case 0:
			story += CONST_news342 \
				+ nstr \
				+ CONST_news343;
			break;
		case 1:
			story += CONST_news344 \
				+ nstr \
				+ CONST_news345;
			break;
		}

		story += CONST_news1030 \
			+ ampersandR;

		return story;
	}
	const string CONST_news1030 = "\"";
	string constructVIEW_DEATHPENALTY()
	{
		const string CONST_news458 = ".\"";

		const string CONST_news306 = "can be put to death in this country.";
		const string CONST_news305 = "tragedy, it will be that our nation is now evaluating the ease with which people ";
		const string CONST_news304 = "and more events are expected this evening. If there is a bright side to be found from this ";
		const string CONST_news303 = " Candlelight vigils were held throughout the country last night during the execution, ";
		const string CONST_news301 = "The family wants closure. We don't have time for another trial";
		const string CONST_news300 = "End of story";
		const string CONST_news299 = "Assassin, serial killer, either way ÄÄ guilty. ";
		const string CONST_news298 = "The convict is always referred to by three names. ";
		const string CONST_news297 = "Let's not forget the convict is colored. You know how their kind are";
		const string CONST_news295 = "spokesperson for the governor saying, ";
		const string CONST_news294 = "The state still went through with the execution, with a ";
		const string CONST_news293 = " was framed. ";
		const string CONST_news292 = "an admission from a former prosecutor that ";
		const string CONST_news291 = "a battery of negative DNA tests. ";
		const string CONST_news290 = "a confession from another convict. ";
		const string CONST_news289 = "have been produced, including ";
		const string CONST_news288 = "Since then, numerous pieces of exculpatory evidence ";
		const string CONST_news287 = " of 13 serial murders. ";
		const string CONST_news286 = " was convicted in ";
		const string CONST_news284 = " Correctional Facility.&r";
		const string CONST_news283 = " yesterday at the ";
		const string CONST_news282 = ":";
		const string CONST_news281 = " was pronounced dead at ";
		const string CONST_news280 = " - An innocent citizen has been put to death in the electric chair. ";



		extern string commaSpace;
		extern int year;

		extern string spaceDashSpace;
		extern string ampersandR;
		extern string singleDot;


		extern vector<string> AMorPM;
		string story;

		story += statename() \
			+ CONST_news280;

		char dstr[200], dstr2[200], dstr3[200];

		generate_long_name(dstr, dstr2, dstr3);

		story += dstr \
			+ singleSpace \
			+ dstr2 \
			+ singleSpace \
			+ dstr3 \
			+ CONST_news281 \
			+ tostring(LCSrandom(12) + 1) \
			+ CONST_news282 \
			+ tostring(LCSrandom(60)) \
			+ pickrandom(AMorPM) \
			+ CONST_news283;

		char jstr[200];

		strcpy(jstr, lastname(true).data());

		story += jstr \
			+ CONST_news284 \
			+ singleSpace \
			+ dstr3 \
			+ CONST_news286 \
			+ tostring(year - LCSrandom(11) - 10) \
			+ CONST_news287 \
			+ CONST_news288 \
			+ CONST_news289;

		switch (LCSrandom(3))
		{
		case 0: story += CONST_news290;
			break;
		case 1: story += CONST_news291;
			break;
		case 2:
			story += CONST_news292 \
				+ dstr3 \
				+ CONST_news293;
			break;
		}

		story += CONST_news294 \
			+ CONST_news295 \
			+ CONST_news1030;

		switch (LCSrandom(3))
		{
		case 0: story += CONST_news297;
			break;
		case 1:
			story += CONST_news298 \
				+ CONST_news299 \
				+ CONST_news300;
			break;
		case 2: story += CONST_news301;
			break;
		}

		story += CONST_news458 \
			+ ampersandR \
			+ CONST_news303 \
			+ CONST_news304 \
			+ CONST_news305 \
			+ CONST_news306 \
			+ ampersandR;

		return story;
	}
	string constructVIEW_INTELLIGENCE()
	{
		const string CONST_news458 = ".\"";

		const string CONST_news318 = "You think about that before you continue slanging accusations";
		const string CONST_news317 = "these files deal with the one and not the other. ";
		const string CONST_news316 = "It might be a bit presumptive to assume that ";
		const string CONST_news315 = "Well, you know, there's privacy, and there's privacy. ";
		const string CONST_news313 = " The FBI refused to comment initially, but when confronted with the information, ";
		const string CONST_news312 = "\"deal with the undesirables\", although this phrase is not clarified. ";
		const string CONST_news311 = " More disturbingly, the files make reference to a plan to ";
		const string CONST_news310 = "unions, working for liberal organizations ÄÄ even ";
		const string CONST_news309 = "The files contain information on which people have been attending demonstrations, organizing ";
		const string CONST_news308 = "This newspaper yesterday received a collection of files from a source in the Federal Bureau of Investigations. ";
		const string CONST_news307 = "Washington, DC - The FBI might be keeping tabs on you. ";

		const string CONST_newsX01 = "a spokesperson stated, \"";

		extern string ampersandR;
		extern string singleDot;

		extern vector<string> liberalCrime;

		string story;
		story += CONST_news307 \
			+ CONST_news308 \
			+ CONST_news309 \
			+ CONST_news310 \
			+ pickrandom(liberalCrime) \
			+ ampersandR \
			+ CONST_news311 \
			+ CONST_news312 \
			+ ampersandR \
			+ CONST_news313 \
			+ CONST_newsX01 \
			+ CONST_news315 \
			+ CONST_news316 \
			+ CONST_news317 \
			+ CONST_news318 \
			+ CONST_news458 \
			+ ampersandR;
		return story;
	}
	string getPhraseJudgeWithProstitute() {

		string story;

		extern short lawList[LAWNUM];

		extern vector<string> judge_with_prostitute;
		extern vector<string> judge_with_prostitute_no_free_speech;
		extern vector<string> judge_with_prostitute_full_free_speech;

		if (lawList[LAW_FREESPEECH] == -2) {
			story += pickrandom(judge_with_prostitute_no_free_speech);
		}
		else if (lawList[LAW_FREESPEECH] == 2) {
			story += pickrandom(judge_with_prostitute_full_free_speech);
		}
		else {
			story += pickrandom(judge_with_prostitute);
		}


		return story;
	}

	string getPhraseJudgeResigned() {

		extern short lawList[LAWNUM];
		string story;

		const string CONST_news349 = " has resigned in disgrace after being caught with a prostitute.";
		const string CONST_news348 = " has resigned in disgrace after being caught with a [civil servant].";

		if (lawList[LAW_FREESPEECH] == -2) story += CONST_news348;
		else story += CONST_news349;

		return story;
	}
	string constructVIEW_JUSTICES()
	{
		extern string ampersandR;

		const string CONST_news361 = "the judge would be going on a Bible retreat for a few weeks to ";
		const string CONST_news360 = " could not be reached for comment, although an aid stated that ";
		const string CONST_news358 = " in exchange for their silence.";
		const string CONST_news357 = " reportedly offered ";
		const string CONST_news355 = "when police broke into the hotel room they saw ";
		const string CONST_news354 = "According to sources familiar with the particulars, ";
		const string CONST_news353 = " last week in a hotel during a police sting operation. ";
		const string CONST_news352 = ", was found with ";
		const string CONST_news351 = ", who once ";
		const string CONST_news347 = " - Conservative federal judge ";


		const string CONST_newsB928 = "\"Make things right with the Almighty Father.\"";

		extern string commaSpace;
		extern int year;
		extern short presparty;
		extern vector<string> crazy_conservative_act;

		extern vector<string> bribe_officers;

		string story;
		story = cityname();
		story += CONST_news347;

		char dstr[200], dstr2[200];

		generate_name(dstr, dstr2, GENDER_WHITEMALEPATRIARCH);

		story += dstr \
			+ singleSpace \
			+ dstr2;

		story += getPhraseJudgeResigned();

		story += ampersandR \
			+ singleSpace \
			+ dstr2 \
			+ CONST_news351 \
			+ pickrandom(crazy_conservative_act) \
			+ CONST_news352;

		char pstr[200], pstr2[200];
		generate_name(pstr, pstr2);

		story += pstr \
			+ singleSpace \
			+ pstr2 \
			+ CONST_news353 \
			+ CONST_news354 \
			+ CONST_news355;


		story += getPhraseJudgeWithProstitute();

		story += singleSpace \
			+ pstr2 \
			+ CONST_news357 \
			+ pickrandom(bribe_officers) \
			+ CONST_news358 \
			+ ampersandR \
			+ singleSpace \
			+ dstr2 \
			+ CONST_news360 \
			+ CONST_news361 \
			+ CONST_newsB928 \
			+ ampersandR;

		return story;
	}

	string getPhraseRadioHostLostMind() {

		const string CONST_news381 = " g*dd*mn mind";
		const string CONST_news380 = " [gosh darn] mind";
		const string CONST_news379 = " goddamn mind";
		const string CONST_news377 = "lost ";
		string story;
		extern short lawList[LAWNUM];

		extern vector<string> radio_host_lost_mind;


		switch (LCSrandom(radio_host_lost_mind.size()))
		{
		case 0:
			story += CONST_news377 \
				+ CONST_news378; // the AM personality's a white male patriarch
			if (lawList[LAW_FREESPEECH] == 2)story += CONST_news379;
			else if (lawList[LAW_FREESPEECH] == -2)story += CONST_news380;
			else story += CONST_news381;
			break;
		default:
			story += pickrandom(radio_host_lost_mind);
		}

		return story;
	}
	string constructVIEW_AMRADIO()
	{
		const string CONST_news390 = "to the FM band.";
		const string CONST_news389 = "pastures. Of these, many said that they would be switching over ";
		const string CONST_news388 = "have decided to leave the program for saner ";
		const string CONST_news387 = "fully half of the host's most loyal supporters ";
		const string CONST_news386 = "According to a poll completed yesterday, ";
		const string CONST_news385 = "the damage might already be done. ";
		const string CONST_news384 = " issued an apology later in the program, but ";
		const string CONST_news376 = " had ";
		const string CONST_news374 = "\", a former fan of the show, ";
		const string CONST_news373 = "liberal media establishment!";
		const string CONST_news372 = "current president!";
		const string CONST_news371 = "and the greatest living example of a reverse racist is the ";
		const string CONST_news368 = "'s monologue for the evening began the way that fans ";
		const string CONST_news366 = "\".";
		const string CONST_news364 = " went off for fifteen minutes in an inexplicable rant ";
		const string CONST_news363 = " - Well-known AM radio personality ";

		const string CONST_newsX03 = "two nights ago during the syndicated radio program \"";
		const string CONST_newsX04 = "had come to expect, with attacks on the \"liberal media establishment\"";
		const string CONST_newsX05 = "the \"elite liberal agenda\". But when the radio icon said, \"";
		const string CONST_newsX06 = ", knew that \"";
		const string CONST_newsX07 = ". After that, it just got worse and worse.\"";


		extern string commaSpace;
		extern int year;
		extern short presparty;

		extern vector<string> radio_name;
		extern vector<string> radio_name_2;

		extern string spaceDashSpace;
		extern string ampersandR;
		extern string singleDot;

		extern vector<string> radio_host_crazy_quote;

		extern vector<string> my_idol;
		string story;
		story = cityname();
		story += CONST_news363;

		char dstr[200], dstr2[200];
		generate_name(dstr, dstr2, GENDER_WHITEMALEPATRIARCH);

		story += dstr \
			+ singleSpace \
			+ dstr2 \
			+ CONST_news364 \
			+ CONST_newsX03 \
			+ pickrandom(radio_name) \
			+ singleSpace \
			+ pickrandom(radio_name_2) \
			+ CONST_news366 \
			+ ampersandR \
			+ singleSpace \
			+ dstr2 \
			+ CONST_news368 \
			+ CONST_newsX04 \
			+ CONST_newsX05;

		switch (LCSrandom(radio_host_crazy_quote.size()))
		{
		case 0:
			story += CONST_news371;
			if (presparty != CONSERVATIVE_PARTY) story += CONST_news372; // Limbaugh
			else story += CONST_news373;
			break;
		default:
			story += pickrandom(radio_host_crazy_quote);
			break;
		}

		story += CONST_news374;

		char nstr[200], nstr2[200];
		generate_name(nstr, nstr2);

		story += nstr \
			+ singleSpace \
			+ nstr2 \
			+ CONST_newsX06 \
			+ pickrandom(my_idol) \
			+ CONST_news376;


		story += getPhraseRadioHostLostMind();

		story += CONST_newsX07 \
			+ ampersandR \
			+ singleSpace \
			+ dstr2 \
			+ CONST_news384 \
			+ CONST_news385 \
			+ CONST_news386 \
			+ CONST_news387; // XXX How many of them switch should
		story += CONST_news388; // depend on [LAW_FREESPEECH]
		story += CONST_news389 \
			+ CONST_news390 \
			+ ampersandR;

		return story;
	}

	string getSchool(const int schtype, const bool capitalized) {

		const string CONST_news398 = "university";
		const string CONST_news397 = "high school";
		const string CONST_news396 = "middle school";
		const string CONST_news395 = "elementary school";
		const string CONST_news407 = "University";
		const string CONST_news406 = "High School";
		const string CONST_news405 = "Middle School";
		const string CONST_news404 = "Elementary School";

		string story;
		if (capitalized) {

			switch (schtype)
			{
			case 0: story += CONST_news404; break;
			case 1: story += CONST_news405; break;
			case 2: story += CONST_news406; break;
			case 3: story += CONST_news407; break;
			}
		}
		else {

			switch (schtype)
			{
			case 0: story += CONST_news395; break;
			case 1: story += CONST_news396; break;
			case 2: story += CONST_news397; break;
			case 3: story += CONST_news398; break;
			}

		}
		return story;
	}

	string getAgeForSchoolStudent(const int schtype) {
		//6->11,10->15,14->19,18->23
		return tostring(6 + (schtype * 4) + LCSrandom(6)); //generate an age that would roughly correspond to the schtype
	}

	string getPhraseKillingSpree() {
		string story;
		extern short lawList[LAWNUM];
		const string CONST_news393 = "shooting rampage";

		if (lawList[LAW_FREESPEECH] == -2) story += CONST_news647;
		else story += CONST_news393;

		return story;
	}

	string getPhraseKilledSelf() {
		const string CONST_news428 = " committed suicide";
		const string CONST_news427 = " [feel deeply asleep]";
		extern short lawList[LAWNUM];
		string story;
		if (lawList[LAW_FREESPEECH] == -2)story += CONST_news427;
		else story += CONST_news428;

		return story;
	}

	string getPhraseMowedDown() {
		string story;
		extern short lawList[LAWNUM];
		const string CONST_news402 = "mow down";
		const string CONST_news401 = "[scare]";


		if (lawList[LAW_FREESPEECH] == -2)story += CONST_news401;
		else story += CONST_news402;

		return story;
	}

	string getGraphicShootingDetails(const int dg) {

		extern short lawList[LAWNUM];
		string story;

		const string CONST_newsB943 = "him";
		const string CONST_news864 = "killed ";

		const string CONST_news426 = " and wounded dozens more. ";
		const string CONST_news424 = "[hurt some people]. ";
		const string CONST_news423 = " When the police arrived, the student had already ";
		const string CONST_news422 = " as well.&r";
		const string CONST_news421 = "shot";
		const string CONST_news420 = "[unfortunately harmed]";
		const string CONST_news419 = ", they were ";
		const string CONST_news417 = "When other students tried to wrestle the weapons away from ";
		const string CONST_news416 = " students and teachers inside. ";
		const string CONST_news415 = "spraying bullets at";
		const string CONST_news414 = "[scaring]";

		if (lawList[LAW_FREESPEECH] == -2) story += CONST_news414;
		else story += CONST_news415;
		story += CONST_news416 \
			+ CONST_news417 \
			+ (dg == GENDER_FEMALE ? CONST_news700 : CONST_newsB943) \
			+ CONST_news419;

		if (lawList[LAW_FREESPEECH] == -2) story += CONST_news420;
		else story += CONST_news421;
		story += CONST_news422 \
			+ CONST_news423;

		if (lawList[LAW_FREESPEECH] == -2) story += CONST_news424;
		else
		{
			story += CONST_news864 \
				+ tostring(2 + LCSrandom(30)) \
				+ CONST_news426;
		}


		return story;
	}
	string constructVIEW_GUNCONTROL()
	{
		const string CONST_news433 = " was disturbingly obsessed with guns and death.&r";
		const string CONST_news432 = "she";
		const string CONST_news431 = "reports indicate that the student kept a journal that showed ";
		const string CONST_news430 = " Investigators are currently searching the student's belongings, and initial ";
		const string CONST_news429 = " shortly afterwards.&r";
		const string CONST_news413 = "classrooms, ";
		const string CONST_news412 = " while classes were in session, then systematically started breaking into ";
		const string CONST_news411 = "university ";
		const string CONST_news410 = "school ";
		const string CONST_news409 = " entered the ";
		const string CONST_news403 = " more than a dozen classmates and two teachers at ";
		const string CONST_news400 = ", used a variety of guns to ";
		const string CONST_news394 = " at a local ";
		const string CONST_news391 = "A student has gone on a ";

		const string CONST_news485 = ". ";

		const string CONST_newsB935 = "he";

		extern string commaSpace;
		extern int year;
		extern short presparty;

		extern string spaceDashSpace;
		extern string ampersandR;
		extern string singleDot;

		string story;
		const int schtype = LCSrandom(4);

		story = cityname();

		story += spaceDashSpace \
			+ CONST_news391;

		story += getPhraseKillingSpree();

		story += CONST_news394;

		story += getSchool(schtype, false);

		story += CONST_news485;

		char dstr[200], dstr2[200];
		const char dg = pickrandom(maleOrFemale);
		generate_name(dstr, dstr2, dg);

		story += dstr \
			+ singleSpace \
			+ dstr2 \
			+ commaSpace;

		story += getAgeForSchoolStudent(schtype);
		story += CONST_news400;
		story += getPhraseMowedDown();
		story += CONST_news403;


		story += lastname(true);

		story += singleSpace;

		story += getSchool(schtype, true);

		story += CONST_news485 \
			+ dstr2 \
			+ CONST_news409;

		if (schtype != 3) story += CONST_news410;
		else story += CONST_news411;
		story += CONST_news412 \
			+ CONST_news413;

		story += getGraphicShootingDetails(dg);

		story += dstr;

		story += getPhraseKilledSelf();

		story += CONST_news429 \
			+ CONST_news430 \
			+ CONST_news431 \
			+ (dg == GENDER_FEMALE ? CONST_news432 : CONST_newsB935) \
			+ CONST_news433;

		return story;
	}
	string getPhrasePrisonBook() {
		string story;

		const string CONST_news443 = "Buttlord";
		const string CONST_news442 = "[Bum]lord";
		extern short lawList[LAWNUM];
		extern vector<string> prison_book_title_2;

		if (!LCSrandom(prison_book_title_2.size())) {
			story;
			if (lawList[LAW_FREESPEECH] == -2) story += CONST_news442;
			else story += CONST_news443;
		}
		else {
			story;
			story += pickrandom(prison_book_title_2);
		}

		return story;
	}
	string getPhraseAIDS() {
		string story;
		const string CONST_news453 = "AIDS";
		const string CONST_news452 = "GRIDS";

		extern short lawList[LAWNUM];

		if (lawList[LAW_GAY] == -2)story += CONST_news452;// Gay Related Immunodeficiency Syndrome, an obsoleted/politically incorrect name for AIDS.
		else story += CONST_news453;

		return story;

	}
	string getPhraseDifficult() {
		string story;
		extern short lawList[LAWNUM];

		const string CONST_news456 = "helluva";
		const string CONST_news455 = "[difficult]";

		if (lawList[LAW_FREESPEECH] == -2)story += CONST_news455;
		else story += CONST_news456;

		return story;

	}
	string constructVIEW_PRISONS()
	{
		const string CONST_news458 = ".\"";
		const string CONST_news457 = " choice, and I would only have a few seconds before they made it for me";
		const string CONST_news454 = " the other. A ";
		const string CONST_news451 = "Maybe lose an eye the one way, maybe catch ";
		const string CONST_news450 = "My shank's under the mattress. Better to be brave and fight or chicken out and let them take it? ";
		const string CONST_news449 = "with dark glares of bare lust, as football players might stare at a stupefied, drunken, helpless teenager. ";
		const string CONST_news448 = "I was trapped with them now. There were three, looking me over ";
		const string CONST_news447 = "coming to a halt with a deafening clang that said it all ÄÄ ";
		const string CONST_news446 = "The steel bars grated forward in their rails, ";
		const string CONST_news445 = " Take this excerpt, \"";
		const string CONST_news444 = "_.&r";
		const string CONST_news441 = "_";
		const string CONST_news440 = "'s new tour-de-force, _";
		const string CONST_news438 = "have these works been as poignant as ";
		const string CONST_news437 = "prison theme lately in its offerings for mass consumption, rarely ";
		const string CONST_news436 = "Although popular culture has used, or perhaps overused, the ";
		const string CONST_news435 = "detail what goes on behind bars. ";
		const string CONST_news434 = " - A former prisoner has written a book describing in horrifying ";


		extern string commaSpace;
		extern vector<string> prison_book_title;
		extern string spaceDashSpace;
		extern string ampersandR;
		extern string singleDot;

		string story;
		story = cityname();
		story += CONST_news434 \
			+ CONST_news435 \
			+ CONST_news436 \
			+ CONST_news437 \
			+ CONST_news438;
		char dstr[200], dstr2[200];
		generate_name(dstr, dstr2); // allow either gender (look up 'Orange is the New Black' online to see why)
		story += dstr \
			+ singleSpace \
			+ dstr2 \
			+ CONST_news440 \
			+ pickrandom(prison_book_title) \
			+ CONST_news441;
		story += getPhrasePrisonBook();


		story += CONST_news444 \
			+ CONST_news445;//TODO() Add more excerpts, more variety.
		story += CONST_news446 \
			+ CONST_news447 \
			+ CONST_news448 \
			+ CONST_news449 \
			+ CONST_news450 \
			+ CONST_news451;


		story += getPhraseAIDS();

		story += CONST_news454;

		story += getPhraseDifficult();

		story += CONST_news457 \
			+ CONST_news458 \
			+ ampersandR;
		return story;
	}

	string constructPositiveEventStory(const short view) {

		string story = blankString;

		switch (view)
		{
		case VIEW_WOMEN:
		{
			story += constructVIEW_WOMEN();
			break;
		}
		case VIEW_GAY:
		{
			story += constructVIEW_GAY();
			break;
		}
		case VIEW_FREESPEECH:
		{
			story += constructVIEW_FREESPEECH();
			break;
		}
		case VIEW_DEATHPENALTY:
		{
			story += constructVIEW_DEATHPENALTY();

			break;
		}
		case VIEW_INTELLIGENCE:
		{
			story += constructVIEW_INTELLIGENCE();
			break;
		}

		case VIEW_JUSTICES:
		{
			story += constructVIEW_JUSTICES();
			break;
		}
		case VIEW_AMRADIO:
		{
			story += constructVIEW_AMRADIO();
			break;
		}
		case VIEW_GUNCONTROL:
		{
			story += constructVIEW_GUNCONTROL();
			break;
		}
		case VIEW_PRISONS:
		{
			story += constructVIEW_PRISONS();
			break;
		}
		}
		return story;
	}
	string getAnimalTestNation() {
		string story;

		extern vector<string> animal_research_country;

		extern short lawList[LAWNUM];
		const string CONST_news476 = "here report that they have discovered an amazing new wonder drug. ";
		const string CONST_news475 = " report that they have discovered an amazing new wonder drug. ";
		const string CONST_news474 = "from ";

		if (lawList[LAW_ANIMALRESEARCH] == 2)
		{
			story += CONST_news474;
			story += pickrandom(animal_research_country);
			story += CONST_news475;
		}
		else {
			story += CONST_news476;
		}


		return story;
	}

	string getPhraseDrugName() {

		string story;
		extern short lawList[LAWNUM];

		const string CONST_news479 = "Anal";
		const string CONST_news478 = "Bum-Bum";
		extern vector<string> drug_name;

		if (LCSrandom(drug_name.size())) {
			story += pickrandom(drug_name);
		}
		else {
			if (lawList[LAW_FREESPEECH] == -2)story += CONST_news478;
			else story += CONST_news479;
		}

		return story;
	}

	string getPhraseViagra() {
		string story;
		extern short lawList[LAWNUM];
		extern vector<string> chimp_drug_impact;
		const string CONST_news482 = "corrects erectile dysfunction in chimpanzees";
		const string CONST_news481 = "[helps chimpanzees reproduce]";


		if (LCSrandom(chimp_drug_impact.size())) {
			story += pickrandom(chimp_drug_impact);
		}
		else {
			if (lawList[LAW_FREESPEECH] == -2)story += CONST_news481;
			else story += CONST_news482;
		}


		return story;
	}
	string constructNegativeVIEW_ANIMALRESEARCH()
	{

		extern vector<string> drug_name_2;
		extern vector<string> chimp_drug_horror;


		const string CONST_news492 = " The first phase of human trials is slated to begin in a few months.";
		const string CONST_news490 = "I think the media should be focusing on the enormous benefits of this drug.";
		const string CONST_news489 = "While we understand your concerns, any worries are entirely unfounded. ";
		const string CONST_news488 = ". We have a very experienced research team. ";
		const string CONST_news487 = "a spokesperson for the research team stated that, \"It really isn't so bad as all that. Chimpanzees are very resilient creatures. ";
		const string CONST_news486 = "Fielding questions about the ethics of their experiments from reporters during a press conference yesterday, ";
		const string CONST_news485 = ". ";
		const string CONST_news484 = " Along with bonobos, chimpanzees are our closest cousins";
		const string CONST_news480 = ", the drug apparently ";
		const string CONST_news477 = "Called ";
		const string CONST_news473 = " - Researchers ";

		extern string singleDot;
		extern string ampersandR;
		string story = cityname()\
			+ CONST_news473;

		story += getAnimalTestNation();

		story += CONST_news477;

		story += getPhraseDrugName();


		story += pickrandom(drug_name_2)\
			+ CONST_news480;

		story += getPhraseViagra();

		story += CONST_news485 \
			+ ampersandR \
			+ CONST_news484 \
			+ CONST_news485 \
			+ CONST_news486 \
			+ CONST_news487\
			+ pickrandom(chimp_drug_horror)\
			+ CONST_news488\
			+ CONST_news489\
			+ CONST_news490\
			+ CONST_news1030\
			+ ampersandR\
			+ CONST_news492\
			+ ampersandR;
		return story;
	}
	string constructNegativeVIEW_POLLUTION() {


		extern vector<string> family_values_company_name;
		extern vector<string> family_values_company_name_2;
		extern vector<string> family_values_company_name_3;
		extern vector<string> pollution_consumption;
		extern vector<string> pollution_consumption_2;
		extern vector<string> i_like_polution;
		extern vector<string> distrust_liberals;

		const string CONST_news571 = "needs to take a breather on this one. We don't see why there's such a rush to judgment here. ";
		const string CONST_news570 = "before we urge any action. Society really just ";
		const string CONST_news569 = "there's work left to be done. We should study much more ";
		const string CONST_news568 = "Why is there contention on the pollution question? It's because ";
		const string CONST_news567 = "All we've done is introduced a little clarity into the ongoing debate. ";
		const string CONST_news566 = " these issues to their own advantage. ";
		const string CONST_news565 = ". You have to realize that ";
		const string CONST_news564 = "a spokesperson stated that, \"";
		const string CONST_news563 = " When questioned about the science behind these results, ";
		const string CONST_news562 = " might actually ";
		const string CONST_news561 = "Among the most startling of the think tank's findings is that ";
		const string CONST_news560 = "and the latest science on the issue. ";
		const string CONST_news559 = " recently released a wide-ranging report detailing recent trends ";
		const string CONST_news558 = " - Pollution might not be so bad after all. The ";

		extern string singleDot;
		extern string ampersandR;
		string story = cityname()\
			+ CONST_news558\
			+ pickrandom(family_values_company_name)\
			+ singleSpace\
			+ pickrandom(family_values_company_name_2)\
			+ singleSpace\
			+ pickrandom(family_values_company_name_3)\
			+ CONST_news559\
			+ CONST_news560\
			+ CONST_news561\
			+ pickrandom(pollution_consumption)\
			+ CONST_news562\
			+ pickrandom(pollution_consumption_2)\
			+ singleDot\
			+ ampersandR\
			+ CONST_news563\
			+ CONST_news564\
			+ pickrandom(i_like_polution)\
			+ CONST_news565\
			+ pickrandom(distrust_liberals)\
			+ CONST_news566\
			+ CONST_news567\
			+ CONST_news568\
			+ CONST_news569\
			+ CONST_news570\
			+ CONST_news571\
			+ ampersandR;
		return story;
	}
	string constructNegativeVIEW_CORPORATECULTURE() {


		extern vector<string> tech_giant_name;
		extern vector<string> tech_giant_name_2;


		const string CONST_news587 = "of the tech industry but is also indicative of a full economic recover.&r";
		const string CONST_news586 = "analysts suggest that not only does the expansion speak to the health ";
		const string CONST_news585 = "futures of some of the companies in the tech sector. On the whole, however, ";
		const string CONST_news584 = "although the dampened movement might be expected due to the uncertain ";
		const string CONST_news583 = "The markets reportedly responded to the announcement with mild interest, ";
		const string CONST_news582 = "this welcome news is bound to be a pleasant surprise to those in the unemployment lines. ";
		const string CONST_news581 = "of large corporations to export jobs overseas these days, ";
		const string CONST_news580 = "light of the tendency ";
		const string CONST_news579 = "Given the state of the economy recently and in ";
		const string CONST_news578 = " increasing its payrolls by over ten thousand workers alone. ";
		const string CONST_news577 = "tech giant ";
		const string CONST_news576 = "are expected in the first month, with ";
		const string CONST_news575 = "during the next quarter. Over thirty thousand jobs ";
		const string CONST_news574 = "will be expanding their work forces considerably ";
		const string CONST_news573 = "at a joint news conference here that they ";
		const string CONST_news572 = " - Several major companies have announced ";

		extern string singleDot;
		extern string ampersandR;
		string story = cityname()\
			+ CONST_news572\
			+ CONST_news573\
			+ CONST_news574\
			+ CONST_news575\
			+ CONST_news576\
			+ CONST_news577\
			+ pickrandom(tech_giant_name)\
			+ pickrandom(tech_giant_name_2)\
			+ CONST_news578\
			+ CONST_news579\
			+ CONST_news580\
			+ CONST_news581\
			+ CONST_news582\
			+ CONST_news583\
			+ CONST_news584\
			+ CONST_news585\
			+ CONST_news586\
			+ CONST_news587;
		return story;
	}
	string getPhraseBullshit() {

		string story;
		extern short lawList[LAWNUM];

		extern vector<string> bullshit_no_free_speech;
		extern vector<string> bullshit;

		if (lawList[LAW_FREESPEECH] == -2) {
			story += pickrandom(bullshit_no_free_speech);
		}
		else {
			story += pickrandom(bullshit);
		}


		return story;
	}
	string getCorporationNameAndProduct() {
		extern vector<string> gene_corp_name;
		extern vector<string> gene_corp_name_2;
		extern vector<string> gene_product_name;
		extern vector<string> gene_product_name_2;
		extern vector<string> gene_product_benefit;

		const string CONST_news517 = "this amazing new product actually ";
		const string CONST_news516 = "According to the public relations representative speaking, ";
		const string CONST_news515 = "\", during an afternoon PowerPoint presentation. ";
		const string CONST_news514 = ", presented their product, \"";

		extern string singleDot;

		string story = pickrandom(gene_corp_name)\
			+ singleSpace\
			+ pickrandom(gene_corp_name_2)\
			+ CONST_news514\
			+ pickrandom(gene_product_name)\
			+ singleSpace\
			+ pickrandom(gene_product_name_2)\
			+ CONST_news515\
			+ CONST_news516\
			+ CONST_news517\
			+ pickrandom(gene_product_benefit)\
			+ singleDot;

		return story;
	}
	string constructNegativeVIEW_GENETICS()
	{


		extern vector<string> gene_product_cost;

		const string CONST_news525 = "but the GM industry operates at a higher ethical standard. That goes without saying.";
		const string CONST_news524 = "No. That's just ridiculous. I mean, sure companies have put unsafe products out, ";
		const string CONST_news523 = ". Would we stake the reputation of our company on unsafe products? ";
		const string CONST_news522 = " is just a load of ";
		const string CONST_news521 = "Look, these products are safe. That thing about the ";
		const string CONST_news520 = "One in particular said, \"";
		const string CONST_news519 = "in their dismissal of the criticism which often follows the industry. ";
		const string CONST_news518 = " Spokespeople for the GM corporations were universal ";
		const string CONST_news513 = " One such corporation, ";
		const string CONST_news512 = "booths and gave talks to wide-eyed onlookers.";
		const string CONST_news511 = "to showcase its upcoming products. Over thirty companies set up ";
		const string CONST_news510 = " - The genetic foods industry staged a major event here yesterday ";

		extern string singleDot;
		extern string ampersandR;
		string story = cityname()\
			+ CONST_news510\
			+ CONST_news511\
			+ CONST_news512\
			+ ampersandR\
			+ CONST_news513;

		story += getCorporationNameAndProduct();

		story += ampersandR\
			+ CONST_news518\
			+ CONST_news519\
			+ CONST_news520\
			+ CONST_news521\
			+ pickrandom(gene_product_cost)\
			+ CONST_news522;

		story += getPhraseBullshit();

		story += CONST_news523\
			+ CONST_news524\
			+ CONST_news525\
			+ CONST_news1030\
			+ ampersandR;
		return story;
	}
	string getPhraseMutilatedCorpse() {
		string story;
		extern short lawList[LAWNUM];

		extern vector<string> mutilated_corpse;
		const string CONST_news467 = " dead and ";
		const string CONST_news466 = " [in a better place]";

		if (lawList[LAW_FREESPEECH] == -2)
			story += CONST_news466;
		else
		{
			story += CONST_news467;
			story += pickrandom(mutilated_corpse);
		}

		return story;
	}
	string getPhraseDeathPenalty() {
		string story;

		const string CONST_news472 = "the death penalty in this case.";
		const string CONST_news471 = "life imprisonment in this case.";

		extern short lawList[LAWNUM];

		if (lawList[LAW_DEATHPENALTY] == 2)
			story += CONST_news471;
		else
			story += CONST_news472;


		return story;
	}
	string constructNegativeVIEW_DEATHPENALTY()
	{

		extern vector<string> evidence_of_child_murder;
		extern vector<string> break_in_murder_case;

		const string CONST_news470 = "seeking ";
		const string CONST_news469 = " The district attorney's office has already repeatedly said it will be ";
		const string CONST_news468 = ". Sources say that the police got a break in the case when ";
		const string CONST_news465 = "only to turn up later";
		const string CONST_news464 = ". Over twenty children in the past two years have gone missing, ";
		const string CONST_news463 = " was detained yesterday afternoon, reportedly in possession of ";
		const string CONST_news462 = "according to a spokesperson for the police department here. ";
		const string CONST_news461 = "string of brutal child killings that has kept everyone in the area on edge, ";
		const string CONST_news460 = "The authorities have apprehended their primary suspect in the ";
		const string CONST_news459 = " - Perhaps parents can rest easier tonight. ";
		extern string singleDot;
		extern string ampersandR;
		char dstr[200], dstr2[200], dstr3[200];
		generate_long_name(dstr, dstr2, dstr3);
		string story = cityname()\
			+ CONST_news459\
			+ CONST_news460\
			+ CONST_news461\
			+ CONST_news462\
			+ dstr\
			+ singleSpace\
			+ dstr2\
			+ singleSpace\
			+ dstr3\
			+ CONST_news463\
			+ pickrandom(evidence_of_child_murder)\
			+ CONST_news464\
			+ CONST_news465;

		story += getPhraseMutilatedCorpse();

		story += CONST_news468\
			+ pickrandom(break_in_murder_case)\
			+ singleDot\
			+ ampersandR\
			+ CONST_news469\
			+ CONST_news470;
		story += getPhraseDeathPenalty();
		story += ampersandR;
		return story;
	}
	string getPhraseTerroristPlot() {
		string story;
		extern short lawList[LAWNUM];

		extern vector<string> terrorist_plot;
		extern vector<string> terrorist_plot_no_free_speech;

		if (lawList[LAW_FREESPEECH] == -2)story += pickrandom(terrorist_plot_no_free_speech);
		else story += pickrandom(terrorist_plot);

		return story;
	}
	string constructNegativeVIEW_INTELLIGENCE()
	{

		const string CONST_newsX08 = " The spokesperson further stated, \"";

		extern string commaSpace;


		extern vector<string> terrorist_group;


		const string CONST_news508 = "this new age.";
		const string CONST_news507 = "for what we feel are the essential tools for combating terrorism in ";
		const string CONST_news506 = "The Head of the Agency will be sending a request to Congress ";
		const string CONST_news505 = "However, let me also say that there's more that needs to be done. ";
		const string CONST_news504 = "civilization before they can destroy American families. ";
		const string CONST_news503 = "providing us with the tools we need to neutralize these enemies of ";
		const string CONST_news502 = "that we are grateful to the Congress and this Administration for ";
		const string CONST_news501 = "I won't compromise our sources and methods, but let me just say ";
		const string CONST_news499 = "was to occur.";
		const string CONST_news498 = "terrorist organization allowed the plot to be foiled just days before it ";
		const string CONST_news497 = ". However, intelligence garnered from deep within the mysterious ";
		const string CONST_news496 = " planned to ";
		const string CONST_news495 = " According to a spokesperson for the agency, ";
		const string CONST_news494 = "would have occurred on American soil.";
		const string CONST_news493 = "Washington, DC - The CIA announced yesterday that it has averted a terror attack that ";

		extern string singleDot;
		extern string ampersandR;
		string story;
		story += CONST_news493\
			+ CONST_news494\
			+ ampersandR\
			+ CONST_news495\
			+ pickrandom(terrorist_group)\
			+ CONST_news496;

		story += getPhraseTerroristPlot();

		story += CONST_news497\
			+ CONST_news498\
			+ CONST_news499\
			+ ampersandR\
			+ CONST_newsX08\
			+ CONST_news501\
			+ CONST_news502\
			+ CONST_news503\
			+ CONST_news504\
			+ CONST_news505\
			+ CONST_news506\
			+ CONST_news507\
			+ CONST_news508\
			+ CONST_news1030\
			+ ampersandR;
		return story;
	}
	string unreliableTestimony(const char gn, const string dstr3) {

		const string CONST_news541 = " consultations with a Magic 8-Ball";
		const string CONST_news540 = " family";
		const string CONST_news539 = " close personal friendship with the ";
		const string CONST_news538 = " personal philosophy of liberty";
		const string CONST_news537 = " deserved another chance";
		const string CONST_news536 = " belief that ";
		const string CONST_news535 = " belief that the crimes were a vast right-wing conspiracy";
		const string CONST_news534 = " general feeling about police corruption";
		const string CONST_news533 = "ten-year-old eyewitness testimony";

		string gen = (gn == GENDER_FEMALE ? CONST_news700 : CONST_news378);
		string story;
		switch (LCSrandom(7))
		{
		case 0:story = CONST_news533; break;
		case 1:story = gen; story += CONST_news534; break;
		case 2:story = gen; story += CONST_news535; break; // Clinton
		case 3:
			story = gen;
			story += CONST_news536;
			story += dstr3;
			story += CONST_news537;
			break;
		case 4:
			story = gen;
			story += CONST_news538; break;
		case 5:
			story = gen;
			story += CONST_news539;
			story += dstr3; // I know Charles Manson.
			story += CONST_news540; // Charles Manson was a friend of mine.
			break; // And you, sir, are no Charles Manson!
		case 6:story = gen; story += CONST_news541; break;
		}
		return story;
	}
	string constructNegativeVIEW_JUSTICES()
	{


		const string CONST_newsB937 = "If I were to be released, I would surely kill again.\"";

		const string CONST_news557 = "completely strapped for cash.&r";
		const string CONST_news556 = "to the current economic doldrums that have left the state ";
		const string CONST_news555 = "has stated that the case will not be retried, due ";
		const string CONST_news554 = " A spokesperson for the district attorney ";
		const string CONST_news552 = "Thank you for saving me from myself. ";
		const string CONST_news551 = " confessed and was sentenced to life, saying \"";
		const string CONST_news550 = "covered in the victims' blood. ";
		const string CONST_news549 = " was found with the murder weapon, ";
		const string CONST_news548 = "After an intensive manhunt, ";
		const string CONST_news547 = " slayings. ";
		const string CONST_news546 = " was convicted of the now-infamous ";
		const string CONST_news545 = " Ten years ago, ";
		const string CONST_news544 = " grants was not coerced in any way.&r";
		const string CONST_news543 = ", which even Justice ";
		const string CONST_news542 = ", despite the confession of ";

		const string CONST_news531 = "made the decision based on ";
		const string CONST_news530 = " of the notoriously liberal circuit of appeals here ";
		const string CONST_news529 = "Justice ";
		const string CONST_news528 = " was overturned by a federal judge yesterday. ";
		const string CONST_news527 = " - The conviction of confessed serial killer ";

		extern string singleDot;
		extern string ampersandR;
		char dstr[200], dstr2[200], dstr3[200];
		generate_long_name(dstr, dstr2, dstr3);
		char jstr[200], jstr2[200];
		const char gn = pickrandom(maleOrFemale);
		generate_name(jstr, jstr2, gn);
		string story = cityname()\
			+ CONST_news527\
			+ dstr\
			+ singleSpace\
			+ dstr2\
			+ singleSpace\
			+ dstr3\
			+ CONST_news528\
			+ CONST_news529\
			+ jstr\
			+ singleSpace\
			+ jstr2\
			+ CONST_news530\
			+ CONST_news531;
		story += unreliableTestimony(gn, dstr3);
		char sstr[200];
		strcpy(sstr, lastname().data());
		story += CONST_news542\
			+ dstr3\
			+ CONST_news543\
			+ jstr2\
			+ CONST_news544\
			+ CONST_news545\
			+ dstr3\
			+ CONST_news546\
			+ sstr\
			+ CONST_news547\
			+ CONST_news548\
			+ dstr3\
			+ CONST_news549\
			+ CONST_news550\
			+ dstr3\
			+ CONST_news551\
			+ CONST_news552\
			+ CONST_newsB937\
			+ CONST_news554\
			+ CONST_news555\
			+ CONST_news556\
			+ CONST_news557;
		return story;
	}
	string obsceneAct() {
		string story;
		extern short lawList[LAWNUM];

		const string CONST_news608 = "masturbated";
		const string CONST_news607 = "[had fun]";
		const string CONST_news606 = "breastfed from a lactating woman";
		const string CONST_news605 = "[fed] from a [woman]";
		const string CONST_news604 = "breastfed from an exposed woman";
		const string CONST_news603 = "[fed] from [an indecent] woman";
		const string CONST_news602 = "screamed \"f*ck the police those g*dd*mn m*th*f*ck*rs. I got a f*cking ticket this morning and I'm f*cking p*ss*d as sh*t.\"";
		const string CONST_news601 = "screamed \"[darn] the police those [big dumb jerks]. I got a [stupid] ticket this morning and I'm [so angry].\"";
		const string CONST_news599 = "encouraged listeners to call in and relieve themselves";
		const string CONST_news598 = "encouraged listeners to call in and take a piss";
		const string CONST_news597 = "encouraged listeners to call in and [urinate]";
		const string CONST_news596 = "had intercourse";
		const string CONST_news595 = "fucked";
		const string CONST_news594 = "[had consensual intercourse in the missionary position]";
		const string CONST_newsX09 = "screamed \"fuck the police those goddamn motherfuckers. I got a fucking ticket this morning and I'm fucking pissed as shit.\"";

		switch (LCSrandom(5))
		{
		case 0:
			if (lawList[LAW_FREESPEECH] == -2)story += CONST_news594;
			else if (lawList[LAW_FREESPEECH] == 2)story += CONST_news595;
			else story += CONST_news596; break;
		case 1:
			if (lawList[LAW_FREESPEECH] == -2)story += CONST_news597;
			else if (lawList[LAW_FREESPEECH] == 2)story += CONST_news598;
			else story += CONST_news599; break;
		case 2:
			if (lawList[LAW_FREESPEECH] == 2)story += CONST_newsX09;
			else if (lawList[LAW_FREESPEECH] == -2)story += CONST_news601;
			else story += CONST_news602; break;
		case 3:
			if (lawList[LAW_FREESPEECH] == -2 && lawList[LAW_WOMEN] == -2)story += CONST_news603;
			else if (lawList[LAW_FREESPEECH] != -2 && lawList[LAW_WOMEN] == -2)story += CONST_news604;
			else if (lawList[LAW_FREESPEECH] == -2 && lawList[LAW_WOMEN] != -2)story += CONST_news605;
			else story += CONST_news606; break;
		case 4:
			if (lawList[LAW_FREESPEECH] == -2)story += CONST_news607;
			else story += CONST_news608; break;
		}

		return story;
	}

	string howManyListeners() {
		string story;
		extern short lawList[LAWNUM];

		const string CONST_news616 = "some";
		const string CONST_news615 = "dozens of";
		const string CONST_news614 = "hundreds of";
		const string CONST_news613 = "several hundred";
		const string CONST_news612 = "thousands of";

		if (lawList[LAW_FREESPEECH] == -2) story += CONST_news612;
		else if (lawList[LAW_FREESPEECH] == -1) story += CONST_news613;
		else if (lawList[LAW_FREESPEECH] == 0) story += CONST_news614;
		else if (lawList[LAW_FREESPEECH] == 1) story += CONST_news615;
		else story += CONST_news616;


		return story;
	}

	string listenersFromWhere() {
		string story;
		extern short lawList[LAWNUM];

		const string CONST_news623 = "within the town. ";
		const string CONST_news622 = "in neighboring towns. ";
		const string CONST_news621 = "within the county. ";
		const string CONST_news620 = "from all over the state. ";
		const string CONST_news619 = "across the nation. ";

		if (lawList[LAW_FREESPEECH] == -2) story += CONST_news619;
		else if (lawList[LAW_FREESPEECH] == -1) story += CONST_news620;
		else if (lawList[LAW_FREESPEECH] == 0) story += CONST_news621;
		else if (lawList[LAW_FREESPEECH] == 1) story += CONST_news622;
		else story += CONST_news623;


		return story;

	}
	string constructNegativeVIEW_AMRADIO()
	{ //THIS ONE IS SHORTER BECAUSE OF DOUBLE HEADLINE


		extern vector<string> fm_radio_name;
		extern vector<string> fm_radio_name_2;


		const string CONST_news625 = "stated that the incident is under investigation.";
		const string CONST_news624 = " A spokesperson for the FCC ";
		const string CONST_news618 = "from irate listeners ";
		const string CONST_news617 = " complaints ";
		const string CONST_news611 = "the FCC received ";
		const string CONST_news610 = " later apologized, ";
		const string CONST_news609 = " on the air. Although ";

		const string CONST_news593 = " reportedly ";
		const string CONST_news592 = "\", ";
		const string CONST_news591 = "'s ";
		const string CONST_news590 = "broadcast of the program \"";
		const string CONST_news589 = " has brought radio entertainment to a new low. During yesterday's ";
		const string CONST_news588 = " - Infamous FM radio shock jock ";

		extern string singleDot;
		extern string ampersandR;
		char dstr[200], dstr2[200];
		generate_name(dstr, dstr2, GENDER_WHITEMALEPATRIARCH);


		string story = cityname();

		story += CONST_news588\
			+ dstr\
			+ singleSpace\
			+ dstr2\
			+ CONST_news589\
			+ CONST_news590\
			+ dstr\
			+ CONST_news591\
			+ pickrandom(fm_radio_name)\
			+ singleSpace\
			+ pickrandom(fm_radio_name_2)\
			+ CONST_news592\
			+ dstr2\
			+ CONST_news593;

		story += obsceneAct();

		story += CONST_news609\
			+ dstr2\
			+ CONST_news610\
			+ CONST_news611;

		story += howManyListeners();

		story += CONST_news617;
		story += CONST_news618;

		story += listenersFromWhere();

		story += CONST_news624;
		story += CONST_news625;
		story += ampersandR;
		return story;
	}

	string misterMissMrsOrMs(const int jg2) {
		const string CONST_newsB939 = "Miss ";
		const string CONST_news638 = "Mr. ";
		const string CONST_news637 = "Mrs. ";
		const string CONST_news636 = "Ms. ";
		extern short lawList[LAWNUM];
		string tg2;

		if (jg2 == GENDER_FEMALE)
		{
			if (LCSrandom(4) < lawList[LAW_WOMEN] + 2) // 0% chance at lawList[LAW_WOMEN]==-2, 100% chance at lawList[LAW_WOMEN]==2
				(tg2 = CONST_news636);
			else
				(tg2 = (LCSrandom(2) ? CONST_news637 : CONST_newsB939));
		}
		else (tg2 = CONST_news638);

		return tg2;
	}
	string getPhraseMassShooting() {
		string story;
		extern short lawList[LAWNUM];
		const string CONST_news648 = "mass shooting";

		if (lawList[LAW_FREESPEECH] == -2) story += CONST_news647;
		else story += CONST_news648;


		return story;
	}
	string getPhraseKillingAttacker() {

		string story;
		extern short lawList[LAWNUM];


		const string CONST_news642 = "firefight, killing the attacker ";
		const string CONST_news641 = "firefight, [putting the attacker to sleep] ";

		if (lawList[LAW_FREESPEECH] == -2) story += CONST_news641;
		else story += CONST_news642;

		return story;

	}
	string constructNegativeVIEW_GUNCONTROL()
	{
		extern vector<string> public_place;
		extern string commaSpace;

		const string CONST_newsB940 = "he ";

		const string CONST_news650 = "'s heroic actions.\"";
		const string CONST_news649 = " if not for ";
		const string CONST_news646 = " The spokesperson for the police department said, \"We'd have a yet another ";
		const string CONST_news645 = "could hurt anyone else.&r";
		const string CONST_news644 = "she ";
		const string CONST_news643 = "before ";

		const string CONST_news640 = " became more agitated, the heroic citizen was forced to engage the shooter in a ";
		const string CONST_news639 = " attempted to talk down the shooter, but as ";
		const string CONST_news635 = " Initially, ";
		const string CONST_news634 = " to take cover while others called the police.&r";
		const string CONST_news633 = "forcing ";
		const string CONST_news632 = "The citizen pulled a concealed handgun and fired once at the shooter, ";
		const string CONST_news631 = " sprung into action. ";
		const string CONST_news630 = " opened fire at the ";
		const string CONST_news629 = " After ";
		const string CONST_news628 = " was prevented by a bystander with a gun.";
		const string CONST_news626 = " - In a surprising turn, a ";

		extern string singleDot;
		extern string ampersandR;
		string story = cityname();
		char jstr[200], jstr2[200], jstr3[200], jstr4[200], jstr5[200];
		const char jg1 = pickrandom(maleOrFemale);
		const char jg2 = pickrandom(maleOrFemale);
		generate_long_name(jstr, jstr2, jstr3, jg1);
		generate_name(jstr4, jstr5, jg2);
		story += CONST_news626;

		story += getPhraseMassShooting();

		story += CONST_news628\
			+ CONST_news629\
			+ jstr\
			+ singleSpace\
			+ jstr2\
			+ CONST_news630\
			+ jstr3\
			+ singleSpace\
			+ pickrandom(public_place)\
			+ commaSpace\
			+ jstr4\
			+ singleSpace\
			+ jstr5\
			+ CONST_news631\
			+ CONST_news632\
			+ CONST_news633\
			+ jstr2\
			+ CONST_news634\
			+ CONST_news635;

		string tg2 = misterMissMrsOrMs(jg2);

		story += tg2;
		story += jstr5;
		story += CONST_news639;
		story += jstr2;
		story += CONST_news640;

		story += getPhraseKillingAttacker();

		story += CONST_news643;
		story += (jg1 == GENDER_FEMALE ? CONST_news644 : CONST_newsB940);
		story += CONST_news645;
		story += CONST_news646;

		story += getPhraseMassShooting();

		story += CONST_news649;
		story += tg2;
		story += jstr5;
		story += CONST_news650;
		return story;
	}
	string threatenToKillPolice() {
		const string CONST_news678 = "Imma kill all you b*tches, startin' with this m*th*f*ck*r here.";
		const string CONST_news677 = "[I will harm all police officers], startin' with this [one] here.";
		const string CONST_news676 = "Imma kill all you bitches, startin' with this mothafucker here.";
		const string CONST_news675 = "Why the f*ck am I talkin' to you? I'd rather kill this pig.";
		const string CONST_news674 = "Why [am I] talkin' to you? I'd rather [harm this police officer.]";
		const string CONST_news673 = "Why the fuck am I talkin' to you? I'd rather kill this pig.";
		const string CONST_news672 = "F*ck a m*th*f*ck*n' bull. I'm killin' this pig sh*t.";
		const string CONST_news671 = "[Too late.] [I am going to harm this police officer.]";
		const string CONST_news670 = "Fuck a muthafuckin' bull. I'm killin' this pig shit.";
		const string CONST_news669 = "Ah, f*ck this sh*t. This punk b*tch is f*ckin' dead!";
		const string CONST_news668 = "Ah, [no way.] This [police officer will be harmed!]";
		const string CONST_news667 = "Ah, fuck this shit. This punk bitch is fuckin' dead!";
		string story;
		extern short lawList[LAWNUM];
		switch (LCSrandom(4))
		{
		case 0:
			if (lawList[LAW_FREESPEECH] == 2)story += CONST_news667;
			else if (lawList[LAW_FREESPEECH] == -2)story += CONST_news668;
			else story += CONST_news669;
			break;
		case 1:
			if (lawList[LAW_FREESPEECH] == 2)story += CONST_news670;
			else if (lawList[LAW_FREESPEECH] == -2)story += CONST_news671;
			else story += CONST_news672;
			break;
		case 2:
			if (lawList[LAW_FREESPEECH] == 2)story += CONST_news673;
			else if (lawList[LAW_FREESPEECH] == -2)story += CONST_news674;
			else story += CONST_news675;
			break;
		case 3:
			if (lawList[LAW_FREESPEECH] == 2)story += CONST_news676;
			else if (lawList[LAW_FREESPEECH] == -2)story += CONST_news677;
			else story += CONST_news678;
			break;
		}
		return story;
	}
	string viciousGuardKilling(const char ggn, const char dgn) {
		string story;
		extern short lawList[LAWNUM];
		const string CONST_news684 = "killed the guard";
		const string CONST_news683 = "[harmed] the guard";

		const string CONST_newsB944 = "neo-pagan";
		const string CONST_newsB943 = "him";
		const string CONST_newsB942 = "Bloods";

		const string CONST_news708 = " altar";
		const string CONST_news707 = "Satanic";
		const string CONST_news706 = "sacrificed the guard on a makeshift ";

		const string CONST_news701 = " off";
		const string CONST_news699 = "taken the guard to the execution chamber and finished ";
		const string CONST_news695 = "Crips";
		const string CONST_news694 = "poisoned the guard with drugs smuggled into the prison by the ";
		const string CONST_news693 = " own gun";
		const string CONST_news691 = "shot the guard with ";
		const string CONST_news690 = " cell";
		const string CONST_news688 = "smashed the guard's skull with the toilet seat from ";

		vector<string> vicious_killing_of_guard = {
			"slit the guard's throat with a shank",
			"strangled the guard to death with a knotted bed sheet",
			"chewed out the guard's throat",
			"hit all 36 pressure points of death on the guard",
			"electrocuted the guard with high-voltage wires",
			"thrown the guard out the top-storey window",
			"tricked another guard into shooting the guard dead",
			"burnt the guard to a crisp using a lighter and some gasoline",
			"eaten the guard's liver with some fava beans and a nice chianti",
			"performed deadly experiments on the guard unheard of since Dr. Mengele"
		};
		if (lawList[LAW_FREESPEECH] == -2) story += CONST_news683;
		else if (lawList[LAW_FREESPEECH] == -1) story += CONST_news684;
		else switch (LCSrandom(15))
		{
		default:
			story += pickrandom(vicious_killing_of_guard);
			break;
		case 10: story += CONST_news688;
			story += (dgn == GENDER_FEMALE ? CONST_news700 : CONST_news378);
			story += CONST_news690; break;
		case 11: story += CONST_news691;
			story += (ggn == GENDER_FEMALE ? CONST_news700 : CONST_news378);
			story += CONST_news693; break;
		case 12: story += CONST_news694;
			story += (LCSrandom(2) ? CONST_news695 : CONST_newsB942); break;
		case 13: story += CONST_news699;
			story += (ggn == GENDER_FEMALE ? CONST_news700 : CONST_newsB943);
			story += CONST_news701; break;
		case 14: story += CONST_news706;
			story += (LCSrandom(2) ? CONST_news707 : CONST_newsB944);
			story += CONST_news708; break;
		}
		return story;
	}

	string getPhraseBeatenToDeath() {

		string story;
		extern short lawList[LAWNUM];


		const string CONST_news711 = "beaten to death";
		const string CONST_news710 = "[also harmed]";

		if (lawList[LAW_FREESPEECH] == -2) story += CONST_news710;
		else  story += CONST_news711;

		return story;
	}

	string getPhraseRapist() {
		string story;
		extern short lawList[LAWNUM];


		const string CONST_news657 = " Two weeks ago, convicted rapist ";
		const string CONST_news656 = " Two weeks ago, convicted [reproduction fiend] ";

		if (lawList[LAW_FREESPEECH] == -2)story += CONST_news656;
		else story += CONST_news657;

		return story;
	}
	string constructNegativeVIEW_PRISONS()
	{
		const string CONST_newsB941 = "himself";

		const string CONST_news712 = " while \"resisting capture\", according to a prison spokesperson.";
		const string CONST_news709 = ". The prisoner was ";
		const string CONST_news682 = " had already ";
		const string CONST_news681 = "the hostage, but ";
		const string CONST_news680 = " The tower was breached in an attempt to reach ";
		const string CONST_news666 = " reportedly screamed into the receiver \"";
		const string CONST_news665 = " days, but talks were cut short when ";
		const string CONST_news664 = "attempted to negotiate by phone for ";
		const string CONST_news663 = "Authorities locked down the prison and ";
		const string CONST_news662 = " with the guard in a prison tower. ";
		const string CONST_news661 = "herself";
		const string CONST_news660 = " and barricaded ";
		const string CONST_news659 = ", overpowered ";
		const string CONST_news658 = ", an inmate at ";
		const string CONST_news655 = " captor.";
		const string CONST_news653 = "death of both the prison guard being held hostage and ";
		const string CONST_news652 = " Correctional Facility ended tragically yesterday with the ";
		const string CONST_news651 = " - The hostage crisis at the ";

		extern string singleDot;
		extern string ampersandR;
		string story = cityname();
		story += CONST_news651;
		char jstr[200];
		strcpy(jstr, lastname(true).data());
		story += jstr;
		story += CONST_news652;
		story += CONST_news653;
		const char ggn = pickrandom(maleOrFemale);
		story += (ggn == GENDER_FEMALE ? CONST_news700 : CONST_news378);
		story += CONST_news655;
		story += ampersandR;

		story += getPhraseRapist();

		char dstr[200], dstr2[200];
		const char dgn = pickrandom(maleOrFemale);
		generate_name(dstr, dstr2, dgn);
		char gstr[200], gstr2[200];
		generate_name(gstr, gstr2, ggn);
		story += dstr\
			+ singleSpace\
			+ dstr2\
			+ CONST_news658\
			+ jstr\
			+ CONST_news659\
			+ gstr\
			+ singleSpace\
			+ gstr2\
			+ CONST_news660\
			+ (dgn == GENDER_FEMALE ? CONST_news661 : CONST_newsB941)\
			+ CONST_news662\
			+ CONST_news663\
			+ CONST_news664\
			+ tostring(LCSrandom(18) + 5)\
			+ CONST_news665\
			+ dstr2\
			+ CONST_news666\
			+ threatenToKillPolice()\
			+ CONST_news1030\
			+ CONST_news680\
			+ CONST_news681\
			+ dstr2\
			+ CONST_news682\
			+ viciousGuardKilling(ggn, dgn)\
			+ CONST_news709;

		story += getPhraseBeatenToDeath();

		story += CONST_news712;
		story += ampersandR;
		return story;
	}


	string constructNegativeEventStory(const short view) {
		string story = blankString;
		switch (view)
		{
		case VIEW_ANIMALRESEARCH:
		{
			story = constructNegativeVIEW_ANIMALRESEARCH();
			break;
		}
		case VIEW_POLLUTION: {
			story = constructNegativeVIEW_POLLUTION();
			break;
		}
		case VIEW_CORPORATECULTURE: {
			story = constructNegativeVIEW_CORPORATECULTURE();
			break;
		}
		case VIEW_GENETICS:
		{
			story = constructNegativeVIEW_GENETICS();
			break;
		}

		case VIEW_DEATHPENALTY:
		{
			story = constructNegativeVIEW_DEATHPENALTY();
			break;
		}

		case VIEW_INTELLIGENCE:
		{
			story = constructNegativeVIEW_INTELLIGENCE();
			break;
		}

		case VIEW_JUSTICES:
		{
			story = constructNegativeVIEW_JUSTICES();
			break;
		}

		case VIEW_AMRADIO:
		{
			story = constructNegativeVIEW_AMRADIO();
			break;
		}
		case VIEW_GUNCONTROL:
		{
			story = constructNegativeVIEW_GUNCONTROL();
			break;
		}
		case VIEW_PRISONS:
		{
			story = constructNegativeVIEW_PRISONS();
			break;
		}
		}
		return story;
	}

	/* news - constructs non-LCS related event stories */
	string constructeventstory(const short view, const char positive)
	{
		if (positive) {
			return constructPositiveEventStory(view);
		}
		else
		{
			return constructNegativeEventStory(view);
		}
	}



	string wasUnableToFind(const string old) {
		const string CONST_activities149 = " but did find a ";
		const string CONST_activities148 = " was unable to find a ";
		return CONST_activities148 + old + CONST_activities149;
	}

	string considerLeaving(const bool sensealarm, const bool alarmon, const string name) {
		const string singleDot = ".";
		const string CONST_activities186 = "Enter - Call it a day.";

		const string CONST_activities168 = "Enter - Yes, the Viper has deterred ";
		const string CONST_activities167 = " is deterred.";
		const string CONST_activities166 = "Enter - The Viper?   ";

		if (!sensealarm) return CONST_activities186;
		else
		{
			if (!alarmon)
			{
				return (CONST_activities166)+(name)+(CONST_activities167);
			}
			else
			{
				return (CONST_activities168)+(name)+(singleDot);
			}
		}
	}

	string getDespairString(const bool drugs, const bool restrain, const bool religion) {

		const string CONST_interrogation133 = " wonders about death.";
		const string CONST_interrogation132 = " wonders about apples.";
		const string CONST_interrogation131 = " cries helplessly.";
		const string CONST_interrogation130 = " barks helplessly.";
		const string CONST_interrogation129 = " curls up in the corner and doesn't move.";
		const string CONST_interrogation128 = " goes limp in the restraints.";
		const string CONST_interrogation127 = "mommy.";
		const string CONST_interrogation126 = "God's mercy.";
		const string CONST_interrogation125 = "John Lennon's mercy.";
		const string CONST_interrogation124 = " screams helplessly for ";

		string output;
		switch (LCSrandom(4))
		{
		case 0: output = CONST_interrogation124;
			if (drugs) output = CONST_interrogation125;
			else if (religion) output = CONST_interrogation126;
			else  output = CONST_interrogation127;
			break;
		case 1:
			if (restrain)  output = CONST_interrogation128;
			else  output = CONST_interrogation129; break;
		case 2:
			if (drugs && !LCSrandom(5))  output = CONST_interrogation130;
			else  output = CONST_interrogation131; break;
		case 3:
			if (drugs && !LCSrandom(3))  output = CONST_interrogation132;
			else  output = CONST_interrogation133;
			break;
		}
		return output;
	}

	string victimPrays(const bool onDrugs) {
		extern vector<string> prays;
		extern vector<string> prays_on_drugs;
		if (!onDrugs)
		{
			return pickrandom(prays);
		}
		else
		{
			return pickrandom(prays_on_drugs);
		}
	}

	string getFallsInLove(const string name, const bool restrain) {
		extern vector<vector<string> > fall_in_love;
		const string singleDot = ".";
		string output;

		const string CONST_interrogation143 = "talks about hugging ";
		const string CONST_interrogation142 = " stammers and ";

		const string CONST_interrogationB150 = "hugs ";

		switch (LCSrandom(fall_in_love.size() + 1))
		{
		case 0:
			output = CONST_interrogation142;
			output += restrain ? CONST_interrogation143 : CONST_interrogationB150;
			output += name;
			output += singleDot;
			break;
		default:
			int which_love = LCSrandom(fall_in_love.size());
			output = fall_in_love[which_love][0];
			output += name;
			output += fall_in_love[which_love][1];
			break;
		}
		return output;
	}

	string getBadTrip(const string name, const bool restrain, const bool rapport) {
		extern vector<vector<string> > bad_trip;
		const string singleDot = ".";

		const string CONST_interrogation148 = " begs for the nightmare to end.";
		const string CONST_interrogation147 = " curls up and";
		const string CONST_interrogation146 = " to stop looking like Hitler.";
		const string CONST_interrogation145 = " screams for ";
		const string CONST_interrogation144 = " begs Hitler to stay and kill ";

		string output;
		switch (LCSrandom(bad_trip.size() + 2))
		{
		case 0:
			if (rapport)
			{
				output = CONST_interrogation144;
				output += name;
				output += singleDot;
			}
			else
			{
				output = CONST_interrogation145;
				output += name;
				output += CONST_interrogation146;
			}
			break;
		case 1:
			if (!restrain) output = CONST_interrogation147;
			output = CONST_interrogation148;
			break;
		default:
			int which_trip = LCSrandom(bad_trip.size());
			output = (bad_trip[which_trip][0]);
			output += name;
			output += (bad_trip[which_trip][1]);
			break;
		}
		return output;
	}
	string outPsychologyCaptor(const string name) {
		extern vector<string> smarter_than_you_one_line;
		extern vector<vector<string> > smarter_than_you;
		string output;
		int which_smarter = LCSrandom(smarter_than_you.size() + smarter_than_you_one_line.size());
		if (which_smarter < smarter_than_you.size()) {
			output = smarter_than_you[which_smarter][0];
			output += name;
			output += smarter_than_you[which_smarter][1];
		}
		else {
			output = pickrandom(smarter_than_you_one_line);
		}
		return output;

	}

	string triedConvertingTheAbused(const string name) {
		extern vector<string> develops_hatred_one_line;
		extern vector<vector<string> > develops_hatred;
		string output;
		int which_hatred = LCSrandom(develops_hatred.size() + develops_hatred_one_line.size());
		if (which_hatred < develops_hatred.size())
		{
			output = develops_hatred[which_hatred][0];
			output += name;
			output += develops_hatred[which_hatred][1];
		}
		else {
			output = pickrandom(develops_hatred_one_line);
		}

		return output;
	}

	string feelsBadForAbused(const string name) {
		extern vector<string> interrogater_shows_compassion_one_line;
		extern vector<vector<string> > interrogater_shows_compassion;

		string output;
		int which_compassion = LCSrandom(interrogater_shows_compassion.size() + interrogater_shows_compassion_one_line.size());
		if (which_compassion < interrogater_shows_compassion.size()) {
			output = interrogater_shows_compassion[which_compassion][0];
			output += name;
			output += interrogater_shows_compassion[which_compassion][1];
		}
		else {
			output = pickrandom(interrogater_shows_compassion_one_line);
		}
		return output;
	}

	string stockholmSyndrome(const string name) {
		extern vector<vector<string> > cling_to_interrogater;
		extern vector<string> clinging_one_line;

		string output;
		int which_cling = LCSrandom(cling_to_interrogater.size() + clinging_one_line.size());
		if (which_cling < cling_to_interrogater.size()) {
			output = cling_to_interrogater[which_cling][0];
			output += name;
			output += cling_to_interrogater[which_cling][1];
		}
		else {
			output = pickrandom(clinging_one_line);
		}
		return output;
	}

	string failToBreakReligion(const string a, const string cr) {
		extern vector<vector<string> > cling_to_religion;
		extern vector<string> cling_to_religion_one_line;

		string output;
		int which_cling = LCSrandom(cling_to_religion.size() + cling_to_religion_one_line.size());
		if (which_cling < cling_to_religion.size()) {
			output = a;
			output += cling_to_religion[which_cling][0];
			output += cr;
			output += cling_to_religion[which_cling][1];
		}
		else {
			output = cr;
			output += pickrandom(cling_to_religion_one_line);
		}
		return output;
	}

	string failedToBreakBusiness(const string a, const string cr) {
		extern vector<vector<string> > cling_to_business;
		extern vector<string> cling_to_business_one_line;

		string output;
		int which_cling = LCSrandom(cling_to_business.size() + cling_to_business_one_line.size());
		if (which_cling < cling_to_business.size()) {
			output + cr;
			output += cling_to_business[which_cling][0];
			output += a;
			output += cling_to_business[which_cling][1];
		}
		else {
			output + cr;
			output += pickrandom(cling_to_business_one_line);
		}
		return output;
	}

	string failedToBreakScience(const string a, const string cr) {
		extern vector<vector<string> > cling_to_science;
		extern vector<string> cling_to_science_one_line;
		string output;
		int which_cling = LCSrandom(cling_to_science.size() + cling_to_science_one_line.size());
		if (which_cling < cling_to_science.size()) {
			output + cr;
			output += cling_to_science[which_cling][0];
			output += a;
			output += cling_to_science[which_cling][1];
		}
		else {
			output + cr;
			output += pickrandom(cling_to_science_one_line);
		}
		return output;
	}


	string howGracefulAttack(int handToHand) {

		const string CONST_fight126 = "gracefully strikes at";
		const string CONST_fight125 = "jump kicks";
		const string CONST_fight124 = "strikes at";
		const string CONST_fight123 = "kicks";
		const string CONST_fight122 = "grapples with";
		const string CONST_fight121 = "swings at";
		const string CONST_fight120 = "punches";

		if (!LCSrandom(handToHand + 1))
			return CONST_fight120;
		else if (!LCSrandom(handToHand))
			return CONST_fight121;
		else if (!LCSrandom(handToHand - 1))
			return CONST_fight122;
		else if (!LCSrandom(handToHand - 2))
			return CONST_fight123;
		else if (!LCSrandom(handToHand - 3))
			return CONST_fight124;
		else if (!LCSrandom(handToHand - 4))
			return CONST_fight125;
		else return CONST_fight126;
	}

	string dismemberingWound(const int w, const int wound) {

		const string CONST_fight152 = " BLOWING IT OFF!";
		const string CONST_fight151 = " CUTTING IT OFF!";
		const string CONST_fight150 = " BLOWING IT IN HALF!";
		const string CONST_fight149 = " BLOWING IT APART!";
		const string CONST_fight148 = " CUTTING IT IN HALF!";

		string output = blankString;

		if (w == BODYPART_HEAD && wound & WOUND_CLEANOFF) {
			output = CONST_fight151;
		}
		else if (w == BODYPART_BODY && wound & WOUND_CLEANOFF) {
			output = CONST_fight148;
		}
		else if (w == BODYPART_HEAD && wound & WOUND_NASTYOFF) {
			output = CONST_fight149;
		}
		else if (w == BODYPART_BODY && wound & WOUND_NASTYOFF) {
			output = CONST_fight150;
		}
		else if (wound & WOUND_CLEANOFF) {
			output = CONST_fight151;
		}
		else if (wound & WOUND_NASTYOFF) {
			output = CONST_fight152;
		}

		return output;
	}


	vector<string> printSpecialWounds(const char special[SPECIALWOUNDNUM]) {
		vector<string> woundList;
		const string CONST_commondisplay180 = "Missing Teeth";
		const string CONST_commondisplay178 = "No Teeth";
		const string CONST_commondisplay177 = "No Tongue";

		const string CONST_commondisplay188 = "Broken Ribs";
		const string CONST_commondisplay187 = "Broken Rib";
		const string CONST_commondisplay186 = "All Ribs Broken";
		const string CONST_commondisplay185 = "Busted Spleen";
		const string CONST_commondisplay184 = "Stomach Injured";
		const string CONST_commondisplay183 = "L. Kidney Damaged";
		const string CONST_commondisplay182 = "R. Kidney Damaged";
		const string CONST_commondisplay181 = "Liver Damaged";
		const string CONST_commondisplay179 = "Missing a Tooth";
		const string CONST_commondisplay176 = "No Nose";
		const string CONST_commondisplay175 = "No Left Eye";
		const string CONST_commondisplay174 = "No Right Eye";
		const string CONST_commondisplay173 = "Broken Lw Spine";
		const string CONST_commondisplay172 = "Broken Up Spine";
		const string CONST_commondisplay171 = "Broken Neck";
		const string CONST_commondisplay170 = "L. Lung Collapsed";
		const string CONST_commondisplay169 = "R. Lung Collapsed";
		const string CONST_commondisplay168 = "Heart Punctured";

		if (special[SPECIALWOUND_HEART] != 1)
		{
			woundList.push_back(CONST_commondisplay168);
		}
		if (special[SPECIALWOUND_RIGHTLUNG] != 1)
		{
			woundList.push_back(CONST_commondisplay169);
		}
		if (special[SPECIALWOUND_LEFTLUNG] != 1)
		{
			woundList.push_back(CONST_commondisplay170);
		}
		if (special[SPECIALWOUND_NECK] != 1)
		{
			woundList.push_back(CONST_commondisplay171);
		}
		if (special[SPECIALWOUND_UPPERSPINE] != 1)
		{
			woundList.push_back(CONST_commondisplay172);
		}
		if (special[SPECIALWOUND_LOWERSPINE] != 1)
		{
			woundList.push_back(CONST_commondisplay173);
		}
		if (special[SPECIALWOUND_RIGHTEYE] != 1)
		{
			woundList.push_back(CONST_commondisplay174);
		}
		if (special[SPECIALWOUND_LEFTEYE] != 1)
		{
			woundList.push_back(CONST_commondisplay175);
		}
		if (special[SPECIALWOUND_NOSE] != 1)
		{
			woundList.push_back(CONST_commondisplay176);
		}
		if (special[SPECIALWOUND_TONGUE] != 1)
		{
			woundList.push_back(CONST_commondisplay177);
		}
		if (special[SPECIALWOUND_TEETH] != TOOTHNUM)
		{
			if (special[SPECIALWOUND_TEETH] == 0)woundList.push_back(CONST_commondisplay178);
			else if (special[SPECIALWOUND_TEETH] == TOOTHNUM - 1)woundList.push_back(CONST_commondisplay179);
			else if (special[SPECIALWOUND_TEETH] < TOOTHNUM)woundList.push_back(CONST_commondisplay180);
		}
		if (special[SPECIALWOUND_LIVER] != 1)
		{
			woundList.push_back(CONST_commondisplay181);
		}
		if (special[SPECIALWOUND_RIGHTKIDNEY] != 1)
		{
			woundList.push_back(CONST_commondisplay182);
		}
		if (special[SPECIALWOUND_LEFTKIDNEY] != 1)
		{
			woundList.push_back(CONST_commondisplay183);
		}
		if (special[SPECIALWOUND_STOMACH] != 1)
		{
			woundList.push_back(CONST_commondisplay184);
		}
		if (special[SPECIALWOUND_SPLEEN] != 1)
		{
			woundList.push_back(CONST_commondisplay185);
		}
		if (special[SPECIALWOUND_RIBS] != RIBNUM)
		{
			if (special[SPECIALWOUND_RIBS] == 0)woundList.push_back(CONST_commondisplay186);
			else if (special[SPECIALWOUND_RIBS] == RIBNUM - 1)woundList.push_back(CONST_commondisplay187);
			else if (special[SPECIALWOUND_RIBS] < RIBNUM)woundList.push_back(CONST_commondisplay188);
		}
		return woundList;
	}
