
/* names the new hostage and stashes them in your base */
void kidnaptransfer(Creature &cr);
/* roll on the kidnap attempt and show the results */
bool kidnap(Creature &a, Creature &t, bool &amateur);
/* hostage freed due to host unable to haul */
void freehostage(Creature &cr, char situation);