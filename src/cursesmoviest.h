
void alarmset(int t);
void pause_ms(int t);
void alarmwait();
struct filelistst
{
	vector<char *> list;
	~filelistst();
	void clean();
	void open_diskload(FILE *h);
	void open_disksave(FILE *h);
	void smartappend(filelistst &list2);
};
const int PICMAX = 1000;
struct CursesMovie_framest
{
	short frame;
	long start, stop;
	short sound, song, effect;
	unsigned short flag;
	CursesMovie_framest() : frame(0), start(0), stop(0), sound(-1), song(-1), effect(-1), flag(0) { }
};
struct CursesMoviest
{
	unsigned char picture[PICMAX][80][25][4];
	int picnum, dimx, dimy;
	filelistst songlist, soundlist;
	vector<CursesMovie_framest *> frame;
	CursesMoviest() : picnum(1), dimx(80), dimy(25) { }
	~CursesMoviest() { clean(); }
	void savemovie(const char *filename, int flags);
	void loadmovie(const char *filename);
	void clean() { delete_and_clear(frame); }
	void convertindices_song(filelistst &master);
	void convertindices_sound(filelistst &master);
	void playmovie(int x, int y);
};
