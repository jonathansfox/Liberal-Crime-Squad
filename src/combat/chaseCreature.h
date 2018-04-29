
int driveskill(Creature &cr, Vehicle &v);
Vehicle* getChaseVehicle(const Creature &c);
Creature* getChaseDriver(const Creature &c);
/* the next two functions force a chase sequence with a specific liberal */
bool footchase(Creature &cr);
bool chasesequence(Creature &cr, Vehicle &v);