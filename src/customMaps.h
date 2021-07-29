

typedef struct {
	vector<vector<string> >* super_collection;
	vector<string>* collection;
	int dimensions;
	string fileName;
	bool superCollection;
} file_and_text_collection;
file_and_text_collection customText(vector<string>  *, string);
file_and_text_collection customText(vector<vector<string> > *, string, int);
file_and_text_collection customText(string);
file_and_text_collection customText(string, int);
// The usage of the default constructor stringConnectedToView() is discouraged
// Currently it exists only because its current usage as an element of a map requires it
// When a map is given an unused key it creates a new reference for use with that key
// 
struct stringConnectedToView {
	const string aboveFifty;
	const string belowFifty;
	const string belowFiftyLiberalLaw;
	const string belowFiftyEliteLiberalLaw;
	stringConnectedToView() : stringConnectedToView("", "") {}
	stringConnectedToView(string aboveFifty_, string belowFifty_) : aboveFifty(aboveFifty_), belowFifty(belowFifty_), belowFiftyLiberalLaw(belowFifty_), belowFiftyEliteLiberalLaw(belowFifty_) {}
	stringConnectedToView(string aboveFifty_, string belowFifty_, string belowFiftyEliteLiberalLaw_) : aboveFifty(aboveFifty_), belowFifty(belowFifty_), belowFiftyLiberalLaw(belowFifty_), belowFiftyEliteLiberalLaw(belowFiftyEliteLiberalLaw_) {}
	stringConnectedToView(string aboveFifty_, string belowFifty_, string belowFiftyEliteLiberalLaw_, string belowFiftyLiberalLaw_) : aboveFifty(aboveFifty_), belowFifty(belowFifty_), belowFiftyLiberalLaw(belowFiftyLiberalLaw_), belowFiftyEliteLiberalLaw(belowFiftyEliteLiberalLaw_) {}
};

void displayDifficulty(int difficulty);