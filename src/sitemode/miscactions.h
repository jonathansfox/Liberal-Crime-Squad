/*
miscactions.cpp
*/
/* unlock attempt */
<<<<<<< HEAD

UnlockAttempt unlock(short type);
/* bash attempt */
=======
enum UnlockAttempt {
	UNLOCKED,
	LOUD_FAILURE,
	NEVERMIND
};
UnlockAttempt unlock(short type);
/* bash attempt */
UnlockAttempt bash();
>>>>>>> acaa55987f7b177b662bdb7f42ebb6850475784a
/* computer hack attempt */
UnlockAttempt hack(short type);
/* run a radio broadcast */
//char radio_broadcast();
/* run a tv broadcast */
//char news_broadcast();
/* rescues people held at the activeparty's current location */
void partyrescue(short special);
/* everybody reload! */
//void reloadparty(bool wasteful = false);
