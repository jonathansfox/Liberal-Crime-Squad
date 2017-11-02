
#include <includes.h>

#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
/* news - draws the specified block of text to the screen */
void displaynewsstory(char *story, const short *storyx_s, const short *storyx_e, int y);
extern int year;
 vector<string> personalAds;
 vector<string> personalAdsLG;
extern string ampersandR;
 string ampersandC;
 vector<vector<string>> adListB;
 vector<vector<string>> adList;
void displaysinglead(bool liberalguardian, char addplace[2][3], short* storyx_s, short* storyx_e, int& it2)
{
	int x, y;
	do x = LCSrandom(2), y = LCSrandom(3); while (addplace[x][y]);
	char choice = LCSrandom(6) + 1; // choose an ad from 1 to 6 that isn't already taken
	for (int x2 = 0; x2 < 2; x2++) for (int y2 = 0; y2 < 3; y2++) // loop thru ad places to see ads already up
		if (addplace[x2][y2] == choice) choice = LCSrandom(6) + 1, x2 = 0, y2 = -1; // choose again and restart loop if already taken
	addplace[x][y] = choice; // we got an ad chosen that isn't a duplicate
	int sx = 0, ex = 0, sy = 0, ey = 0;
	if (x == 0) sx = 0, ex = 23 + LCSrandom(4);
	if (x == 1) sx = 57 - LCSrandom(4), ex = 79;
	if (y == 0) sy = 2, ey = 9;
	if (y == 1) sy = 10, ey = 17;
	if (y == 2) sy = 18, ey = 24;
	int ch = '?';
	switch (LCSrandom(6))
	{
	case 0: ch = CH_LIGHT_SHADE; break;
	case 1: ch = CH_MEDIUM_SHADE; break;
	case 2: ch = CH_DARK_SHADE; break;
	case 3: ch = CH_FULL_BLOCK; break;
	case 4: ch = CH_BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL; break;
	case 5: ch = '*'; break;
	}
	for (y = sy; y <= ey; y++)
	{
		if (storyx_s[y] < ex&&ex < 43) storyx_s[y] = ex + 2;
		if (storyx_e[y] > sx&&sx>43) storyx_e[y] = sx - 2;
		if (ey == 9 && y == 9) continue;
		if (ey == 17 && y == 17) continue;
		for (x = sx; x <= ex; x++)
			if (y == sy || y == 8 || y == 16 || y == 24 || x == sx || x == ex)
				mvaddchAlt(y, x, ch);
	}
	//AD CONTENT
	{
		short storyx_s[25], storyx_e[25];
		for (it2 = 0; it2 < 25; it2++) storyx_s[it2] = 40, storyx_e[it2] = 40;
		for (it2 = sy + 1; it2 <= ey - 1; it2++) storyx_s[it2] = sx + 1, storyx_e[it2] = ex - 1;
		char ad[500];
		if (!liberalguardian)
		{ // regular newspaper (not Liberal Guardian)
			switch (choice) // should be 6 choices from 1 to 6
			{ // location[]->name?
			case 1:
			case 3:
			case 5:
			default:
				strcpy(ad, "");
				for (string str : pickrandom(adList)) {
					strcat(ad, str);
				}
				break;
			case 2:
				strcpy(ad, ampersandC + "Fine Leather Chairs" + ampersandR + ampersandR);
				strcat(ad, ampersandC + "Special Purchase" + ampersandR);
				strcat(ad, ampersandC + "Now $");
				strcat(ad, LCSrandom(201) + 400);
				strcat(ad, ampersandR);
				break;
			case 4:
				strcpy(ad, ampersandC + "Quality Pre-Owned" + ampersandR);
				strcat(ad, ampersandC + "Vehicles&r");
				strcat(ad, ampersandC);
				strcat(ad, year - LCSrandom(15));
				strcat(ad, singleSpace);
				//          strcat(ad,cartype);
				//TODO: leading zeros, etc.
				strcat(ad, "Lexus GS 300" + ampersandR);
				strcat(ad, ampersandC + "Sedan 4D" + ampersandR);
				strcat(ad, ampersandC + "Only $");
				strcat(ad, LCSrandom(16) + 15);
				strcat(ad, ampersandR);
				break;
			case 6:
			{
				strcpy(ad, ampersandC);
				strcat(ad, pickrandom(personalAds));
				char str[10];
				strcat(ad, ampersandR + ampersandR);
				strcat(ad, ampersandC);
				sexdesc(str);
				strcat(ad, str);
				strcat(ad, singleSpace);
				sexwho(str);
				strcat(ad, str);
				strcat(ad, singleSpace);
				sexseek(str);
				strcat(ad, str);
				strcat(ad, ampersandR);
				strcat(ad, ampersandC);
				sextype(str);
				strcat(ad, str);
				strcat(ad, " w/ ");
				sexwho(str);
				strcat(ad, str);
				strcat(ad, ampersandR);
				break;
			}
			}
		}
		else
		{ // Liberal Guardian Ads
			switch (choice)  // should be 6 choices from 1 to 6
			{
			case 1:
			case 3:
			case 4:
			case 5:
			default:
				strcpy(ad, "");
				for (string str : pickrandom(adListB)) {
					strcat(ad, str);
				}
				break;
			case 2:
				strcpy(ad, ampersandC + "Liberal Defense Lawyer" + ampersandR);
				strcat(ad, ampersandC);
				strcat(ad, LCSrandom(11) + 20);
				strcat(ad, " Years Experience" + ampersandR + ampersandR);
				strcat(ad, ampersandC + "Call Today" + ampersandR);
				break;
			case 6:
			{
				strcpy(ad, ampersandC);
				strcat(ad, pickrandom(personalAdsLG));
				char str[10];
				strcat(ad, ampersandR + ampersandR);
				strcat(ad, ampersandC);
				sexdesc(str);
				strcat(ad, str);
				strcat(ad, singleSpace);
				sexwho(str);
				strcat(ad, str);
				strcat(ad, singleSpace);
				sexseek(str);
				strcat(ad, str);
				strcat(ad, ampersandR);
				strcat(ad, ampersandC);
				sextype(str);
				strcat(ad, str);
				strcat(ad, " w/ ");
				sexwho(str);
				strcat(ad, str);
				strcat(ad, ampersandR);
				break;
			}
			}
		}
		displaynewsstory(ad, storyx_s, storyx_e, sy + 1);
	}
}
void displayads(newsstoryst& ns, bool liberalguardian, short* storyx_s, short* storyx_e, int& it2)
{
	int adnumber = 0;
	if (!liberalguardian)
	{
		if (ns.page >= 10)adnumber++;
		if (ns.page >= 20)adnumber += LCSrandom(2) + 1;
		if (ns.page >= 30)adnumber += LCSrandom(2) + 1;
		if (ns.page >= 40)adnumber += LCSrandom(2) + 1;
		if (ns.page >= 50)adnumber += LCSrandom(2) + 1;
	}
	else
	{
		if (ns.guardianpage >= 2)adnumber++;
		if (ns.guardianpage >= 3)adnumber += LCSrandom(2) + 1;
		if (ns.guardianpage >= 4)adnumber += LCSrandom(2) + 1;
		if (ns.guardianpage >= 5)adnumber += LCSrandom(2) + 1;
		if (ns.guardianpage >= 6)adnumber += LCSrandom(2) + 1;
	}
	char addplace[2][3] = { { 0,0,0 },{ 0,0,0 } };
	for (adnumber = (adnumber > 6 ? 6 : adnumber); adnumber > 0; adnumber--)
		displaysinglead(liberalguardian, addplace, storyx_s, storyx_e, it2);
}

