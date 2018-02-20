
/* addstr with formatted output and logging */
int addstr_fl(Log &log, const char * format, ...);
/* mvaddstr with formatted output and logging */
int mvaddstr_fl(int y, int x, Log &log, const char * format, ...);