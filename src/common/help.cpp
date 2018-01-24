
#include <includes.h>


#include "common/help.h"
//own header

#include "common/consolesupport.h"
// for void set_color(short,short,bool)


#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
// {{{ Various voids
// Help pages are drawn here.
// NOTE: This will probably need updating if there are any fundamental code
// changes that will change gameplay.
typedef map<short, vector<string>> shortAndTwoStrings;
shortAndTwoStrings helpTopics;
string liberalHelpOn;
string pressAnyKeyToReturn;
void help(const char* string)
{
	eraseAlt();
}
// Generates help page on activities.
// Just supply Activity type.
void HelpActivities(int activityType)
{
	//
	if (activityType == ACTIVITY_NONE)
	{
		return;
	}
	eraseAlt();
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(0,  0, liberalHelpOn);
	vector<string> helpTopic;
	if (helpTopics.count(activityType)) {
		helpTopic = helpTopics[activityType];
	}
	else {
		helpTopic = helpTopics[-1];
	}
	mvaddstrAlt(2, 0, helpTopic[0]);
	for (int i = 0; i < len(helpTopic) - 1; i++) {
		mvaddstrAlt(4 + i, 0, helpTopic[i + 1]);
	}
	set_color_easy(WHITE_ON_BLACK);
	mvaddstrAlt(23,  0, pressAnyKeyToReturn);
	getkey();
}
