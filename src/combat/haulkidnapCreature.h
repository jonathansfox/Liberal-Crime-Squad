
/* names the new hostage and stashes them in your base */
void kidnaptransfer(DeprecatedCreature &cr);
/* roll on the kidnap attempt and show the results */
bool kidnap(DeprecatedCreature &a, DeprecatedCreature &t, bool &amateur);
/* hostage freed due to host unable to haul */
void freehostage(DeprecatedCreature &cr, char situation);