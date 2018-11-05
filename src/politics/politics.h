#ifndef POLITICS_H
#define POLITICS_H0


/*
 politics.cpp
*/
/* politics - calculate presidential approval */
int presidentapproval();
/* politics -- gets the leaning of an issue voter for an election */
int getswingvoter(const bool stalin);
/* politics -- gets the leaning of a partyline voter for an election */
int getsimplevoter(const int leaning);

/* politics -- appoints a figure to an executive office, based on the President's alignment */
void fillCabinetPost(const int position);
/* politics - causes the people to vote (presidential, congressional, propositions) */
void elections(const char canseethings);
void elections_senate(const int senmod, const char canseethings);
void elections_house(const char canseethings);
/* politics - causes the supreme court to hand down decisions */
void supremecourt(const char canseethings);
/* politics - causes congress to act on legislation */
void congress(const char canseethings);
// letter of amnesty to the LCS from the President (you win)
//void amnesty();
/* politics - checks if the game is won */
char wincheck();
/* politics - checks the prevailing attitude on a specific law, or overall */
int publicmood(const int l);
/* returns true if Stalinists agree with Elite Liberals on a view/law, false if they strongly disagree with libs  *
 * the input bool islaw, if true, returns Stalinist opinion on laws, if false, returns Stalinist opinion on views */
bool stalinview(const short view, const bool islaw);

#endif // POLITICS_H 