#pragma once
struct PrintableStory {
	PrintableStory() { impactOnViews = {}; story = {};	}
	vector<string> story;
	// View, Power, is_Scaling
	vector<tuple<Views, int, bool> > impactOnViews;

	void addLine(string str) {
		story.push_back(str);
	}

	void addView(Views v, int power, bool is_Scaling) {
		impactOnViews.push_back(make_tuple(v, power, is_Scaling));
	}

	vector < tuple<Views, int, bool> > getViews() {
		return impactOnViews;
	}
};
struct AbstractStory {
	AbstractStory() {  ENUM_tags = {}; impactOnViews = {}; randomStories = {}; }
	AbstractStory(string _intro) : intro(_intro) { ENUM_tags = {}; impactOnViews = {}; randomStories = {}; }
	string intro;
	vector<int> ENUM_tags;
	// View, Power, is_Scaling
	vector<tuple<Views, int, bool> > impactOnViews;

	vector<PrintableStory> randomStories;

	PrintableStory chosenStory;
	void addIntro(string _intro) {
		intro = _intro;
	}
	void addTag(int x) {
		ENUM_tags.push_back(x);
	}
	bool hasTag(int x) {
		for (int i = 0; i < len(ENUM_tags); i++) {
			if (ENUM_tags[i] == x) {
				return true;
			}
		}
		return false;
	}

	void addView(Views v, int power, bool is_Scaling) {
		impactOnViews.push_back(make_tuple(v, power, is_Scaling));
	}

	void addStory(PrintableStory p) {
		randomStories.push_back(p);
	}

	void pickStory() {
		chosenStory = pickrandom(randomStories);
	}

	vector<string> getStory() {
		return chosenStory.story;
	}

	vector < tuple<Views, int, bool> > getViews() {
		vector<tuple<Views, int, bool> > nestedViews = chosenStory.getViews();
		for (int i = 0; i < len(nestedViews); i++) {
			impactOnViews.push_back(nestedViews[i]);
		}
		return impactOnViews;
	}

};

