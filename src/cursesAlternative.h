
inline int translateGraphicsChar(const unsigned char c);
inline short translateGraphicsColor(const short c);
int clearAlt(void);
int refreshAlt(void);
int moveAlt(const int, const int);
int	mvaddstrAlt(const int, const int, const std::string);
int	mvaddstrAlt(const int, const int, const std::string, Log &a);
int	mvaddstrAlt(const int, const int, const char*, Log &a);
int	mvaddstrAlt(const int, const int, const int, Log &a);
int	mvaddstrAlt(const int, const int, const char*);
int	mvaddstrAlt(const int, const int, const int);
int	mvaddstrAlt(const int x, const int y, const  char *z);
int addstrAlt(const char *text);
int addstrAlt(const std::string&);
int addstrAlt(const std::string&, Log &log);
int addstrAlt(const char *text, Log &log);
int addstrAlt(const long num);
int addstrAlt(const long num, Log &log);
int addcharAlt(const char ch);
int addcharAlt(const char ch, Log &log);
int mvaddcharAlt(int y, int x, char ch);
int mvaddcharAlt(int y, int x, char ch, Log &log);
/* addstr with formatted output */
int addstr_f(const char * format, ...);
/* mvaddstr with formatted output */
int mvaddstr_f(int y, int x, const char * format, ...);
/* addstr with formatted output and logging */
int addstr_fl(Log &log, const char * format, ...);
/* mvaddstr with formatted output and logging */
int mvaddstr_fl(int y, int x, Log &log, const char * format, ...);
int eraseAlt(void);
int mvaddchAlt(int, int, const int);
int mvgetnstrAlt(int, int, char *, int);
int addchAlt(const int);
void PDC_set_titleAlt(const char *);
int endwinAlt();
int mvaddstrCenter(int i, string str);
int mvaddstrCenter(int i, string str, Log &log);