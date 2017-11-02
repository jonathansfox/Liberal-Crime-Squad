
#include <includes.h>

#include <cursesAlternative.h>
#include <customMaps.h>
#include <constant_strings.h>
#include <gui_constants.h>
#include <set_color_support.h>
/**
ACTIVITY_VISIT, TODO
ACTIVITY_RECRUITING, TODO
ACTIVITY_HOSTAGETENDING, TODO
ACTIVITY_DOS_RACKET, TODO
ACTIVITY_MAKE_ARMOR, TODO
ACTIVITY_WHEELCHAIR, TODO
ACTIVITY_BURY, TODO
ACTIVITY_WRITE_BLOG, TODO
ACTIVITY_TEACH_GENERALED, TODO
ACTIVITY_TEACH_POLITICS, TODO
ACTIVITY_TEACH_SURVIVAL, TODO
ACTIVITY_TEACH_FIGHTING, TODO
ACTIVITY_TEACH_COVERT, TODO
ACTIVITY_CLINIC, TODO
ACTIVITY_HEAL, TODO
ACTIVITY_SLEEPER_LIBERAL, TODO
ACTIVITY_SLEEPER_CONSERVATIVE, TODO
ACTIVITY_SLEEPER_SPY, TODO
ACTIVITY_SLEEPER_RECRUIT, TODO
ACTIVITY_SLEEPER_SCANDAL, TODO
ACTIVITY_SLEEPER_EMBEZZLE, TODO
ACTIVITY_SLEEPER_STEAL, TODO
ACTIVITY_SLEEPER_JOINLCS, TODO
*/
// {{{ Various voids
// Help pages are drawn here.
// NOTE: This will probably need updating if there are any fundamental code
// changes that will change gameplay.
void help(const char* string)
{
	eraseAlt();
}
// Generates help page on activities.
// Just supply Activity type.
void HelpActivities(int activityType)
{
	// I have actually created a screen editor to help me create the code
	// for the help. It can probably be used all over the place for formatting
	// large pieces of text.
	//
	// Could you possibly put this in ../../dev/ ? -- LK
	if (activityType == ACTIVITY_NONE)
	{
		return;
	}
	eraseAlt();
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
	moveZeroZero();
	addstrAlt("Liberal help on:");
	switch (activityType)
	{
		// }}}
		// {{{ Liberal activism
		// {{{ ACTIVITY_COMMUNITYSERVICE
	case ACTIVITY_COMMUNITYSERVICE:
		moveAlt(2, 0);
		addstrAlt("===Community Service===");
		moveAlt(4, 0);
		addstrAlt(" Has a minor effect on public opinion and increases Juice.");
		break;
		// }}}
		// {{{ ACTIVITY_TROUBLE
	case ACTIVITY_TROUBLE:
		moveAlt(2, 0);
		addstrAlt("===Liberal Disobedience===");
		moveAlt(4, 0);
		addstrAlt(" Liberal Disobedience is an illegal activity and a form of Liberal Activism");
		moveAlt(5, 0);
		addstrAlt(" which has a positive effect on Public Opinion. It has very short prison");
		moveAlt(6, 0);
		addstrAlt(" sentences if you get convicted. It also increases juice.");
		moveAlt(8, 0);
		addstrAlt(" Persuasion, Charisma, Agility, Heart, Strength, Intelligence will increase ");
		moveAlt(9, 0);
		addstrAlt(" the effect you have on Public Opinion.");
		moveAlt(11, 0);
		addstrAlt(" There is a chance that someone will phone the police. Agility, intelligence,");
		moveAlt(12, 0);
		addstrAlt(" disguise and street sense will shake them off the scent. There is also a");
		moveAlt(13, 0);
		addstrAlt(" chance that an angry mob will beat the crap out of you.");
		break;
		// }}}
		// {{{ ACTIVITY_GRAFFITI
	case ACTIVITY_GRAFFITI:
		moveAlt(2, 0);
		addstrAlt("===Graffiti==");
		moveAlt(4, 0);
		addstrAlt(" Spraying political graffiti is a misdemeanor, carrying with it relatively ");
		moveAlt(5, 0);
		addstrAlt(" short jail sentences. This has a positive effect on public opinion. If you ");
		moveAlt(6, 0);
		addstrAlt(" do not have a can of spray paint, your character will spend a day purchasing  ");
		moveAlt(7, 0);
		addstrAlt(" one.");
		moveAlt(9, 0);
		addstrAlt(" A high art skill and heart will enhance the effect this has on public opinion.");
		break;
		// }}}
		// {{{ ACTIVITY_POLLS
	case ACTIVITY_POLLS:
		moveAlt(2, 0);
		addstrAlt("===Search Opinion Polls===");
		moveAlt(4, 0);
		addstrAlt(" Search Opinion Polls is a legal activity that lets you see what people think");
		moveAlt(5, 0);
		addstrAlt(" about various Issues. Unlike other activities listed as Liberal Activism,  ");
		moveAlt(6, 0);
		addstrAlt(" Search Opinion Polls does not have any effect on Public Opinion; it just ");
		moveAlt(7, 0);
		addstrAlt(" shows you what Public Opinion is without changing it.");
		moveAlt(9, 0);
		addstrAlt(" Skill in computers and intelligence will give better results.");
		break;
		// }}}
		// {{{ ACTIVITY_DOS_ATTACKS
	case ACTIVITY_DOS_ATTACKS:
		moveAlt(2, 0);
		addstrAlt("===Harassing Websites===");
		moveAlt(4, 0);
		addstrAlt(" Harassing Websites is an illegal activity and a form of Liberal Activism. It ");
		moveAlt(5, 0);
		addstrAlt(" is a weaker version of Hacking. Resulting in much shorter prison sentences, ");
		moveAlt(6, 0);
		addstrAlt(" and is much less likely to provoke a raid by the Police or other law  ");
		moveAlt(7, 0);
		addstrAlt(" enforcement. Harassing websites only requires a Computers skill of 1.");
		moveAlt(9, 0);
		addstrAlt(" Utilizes only the Computers skill.");
		break;
		// }}}
		// {{{ ACTIVITY_HACKING
	case ACTIVITY_HACKING:
		moveAlt(2, 0);
		addstrAlt("===Hacking===");
		moveAlt(4, 0);
		addstrAlt(" Hacking is a highly illegal form of Liberal Activism, which has a good effect");
		moveAlt(5, 0);
		addstrAlt(" on public opinion. With it, comes very long prison sentences.");
		moveAlt(7, 0);
		addstrAlt(" Generally you need a lot of the Computer skill and Intelligence before you");
		moveAlt(8, 0);
		addstrAlt(" can make a successful hacking attempt. You will need a minimum computer skill ");
		moveAlt(9, 0);
		addstrAlt(" of 6 to have an effect. The effect of having more hackers will compound the ");
		moveAlt(10, 0);
		addstrAlt(" chance of successfully penetrating a network.");
		moveAlt(12, 0);
		addstrAlt(" If you are successful there is a chance depending on Computer skill and ");
		moveAlt(13, 0);
		addstrAlt(" Intelligence of evading being criminalized. If you are criminalized, heat on ");
		moveAlt(14, 0);
		addstrAlt(" the activist increases. Additionally if you have made a successful hack it ");
		moveAlt(15, 0);
		addstrAlt(" will increase juice.");
		moveAlt(17, 0);
		addstrAlt(" Occasionally instead of effecting public opinion your hacker may find files");
		moveAlt(18, 0);
		addstrAlt(" that can be published in a special edition of the Liberal Guardian.");
		break;
		// }}}
		// {{{ ACTIVITY_WRITE_LETTERS
	case ACTIVITY_WRITE_LETTERS:
		moveAlt(2, 0);
		addstrAlt("===Write to Newspapers===");
		moveAlt(4, 0);
		addstrAlt(" Write to Newspapers is a legal activity and form of Liberal Activism that");
		moveAlt(5, 0);
		addstrAlt(" boosts the Writing skill and is more effective at influencing Public Opinion");
		moveAlt(6, 0);
		addstrAlt(" the higher the Writing skill is. A main reason for writing to newspapers is");
		moveAlt(7, 0);
		addstrAlt(" developing enough writing skill to effectively Write for the Liberal Guardian,");
		moveAlt(8, 0);
		addstrAlt(" which has a much bigger influence than Write to Newspapers and is still");
		moveAlt(9, 0);
		addstrAlt(" completely legal.");
		moveAlt(11, 0);
		addstrAlt(" Unlike writing for the Liberal Guardian, writing to other newspapers does not");
		moveAlt(12, 0);
		addstrAlt(" require you to own your own newspaper that you set up by deciding to Invest in");
		moveAlt(13, 0);
		addstrAlt(" a location and spending lots of money on the one-time fee for starting up your");
		moveAlt(14, 0);
		addstrAlt(" own newspaper, plus you can do it from anywhere, and it boosts your Writing");
		moveAlt(15, 0);
		addstrAlt(" skill much faster than writing for the Liberal Guardian.");
		moveAlt(17, 0);
		addstrAlt(" To have the option to write for the Liberal Guardian, you need to own your own ");
		moveAlt(18, 0);
		addstrAlt(" newspaper that you set up by deciding to Invest in a location, by pressing 'Z' ");
		moveAlt(19, 0);
		addstrAlt(" on the main screen untill you have an option to invest and spending $3,000 on ");
		moveAlt(20, 0);
		addstrAlt(" a Printing Press. Additionally a character must be physically located at that ");
		moveAlt(21, 0);
		addstrAlt(" safehouse.");
		break;
		// }}}
		// {{{ ACTIVITY_WRITE_GUARDIAN
	case ACTIVITY_WRITE_GUARDIAN:
		moveAlt(2, 0);
		addstrAlt("===Write for the Liberal Guardian ===");
		moveAlt(4, 0);
		addstrAlt(" Writing for the Liberal Guardian is a legal (or illegal depending on the ");
		moveAlt(5, 0);
		addstrAlt(" free speech laws) activity and a form of Liberal Activism that boosts the");
		moveAlt(6, 0);
		addstrAlt(" Writing skill very slowly and is more effective at influencing Public ");
		moveAlt(7, 0);
		addstrAlt(" Opinion the higher the Writing skill is. Writing for the Liberal Guardian ");
		moveAlt(8, 0);
		addstrAlt(" has three times the impact on Public Opinion that Write to Newspapers has.");
		moveAlt(10, 0);
		addstrAlt("Items that prompt a special edition");
		moveAlt(11, 0);
		addstrAlt(">     Police Records - Found in the Police Station.");
		moveAlt(12, 0);
		addstrAlt(">     Secret Corporate Files - Found in the Corporate Headquarters, or");
		moveAlt(13, 0);
		addstrAlt("      obtained through Hacking.");
		moveAlt(14, 0);
		addstrAlt(">     CEO Photos - Found in the CEO Residence.");
		moveAlt(15, 0);
		addstrAlt(">     Intel. HQ Data Disk - Found in the Intelligence HQ.");
		moveAlt(16, 0);
		addstrAlt(">     Cable News Memos - obtained through Hacking.");
		moveAlt(17, 0);
		addstrAlt(">     Research Papers - obtained through Hacking.");
		moveAlt(18, 0);
		addstrAlt(">     Judge Corruption Evidence - obtained through Hacking.");
		moveAlt(19, 0);
		addstrAlt(">     AM Radio Memos - obtained through Hacking.");
		moveAlt(20, 0);
		addstrAlt(" All of the above items can be delivered to the LCS from sleepers in the ");
		moveAlt(21, 0);
		addstrAlt(" appropriate location or from hackers.");
		break;
		// }}}
		// }}}
		// {{{ Legal fund raising
		// {{{ ACTIVITY_DONATIONS
	case ACTIVITY_DONATIONS:
		moveAlt(2, 0);
		addstrAlt("===Soliciting Donations===");
		moveAlt(4, 0);
		addstrAlt(" Income depends on persuasion. ");
		moveAlt(5, 0);
		addstrAlt(" This activity generates very little income when the country is very ");
		moveAlt(6, 0);
		addstrAlt(" Liberal, as people will have little reason to turn to the LCS. ");
		moveAlt(8, 0);
		addstrAlt(" This activity trains persuasion.");
		break;
		// }}}
		// {{{ ACTIVITY_SELL_TSHIRTS
	case ACTIVITY_SELL_TSHIRTS:
		moveAlt(2, 0);
		addstrAlt("===Sell Shirts===");
		moveAlt(4, 0);
		addstrAlt(" Income depends on tailoring and business skills.");
		moveAlt(5, 0);
		addstrAlt(" The income is lower if the public mood is Liberal.");
		moveAlt(7, 0);
		addstrAlt(" This activity trains tailoring and business and may.");
		moveAlt(8, 0);
		addstrAlt(" have a positive political effect if done well enough.");
		break;
		// }}}
		// {{{ ACTIVITY_SELL_ART
	case ACTIVITY_SELL_ART:
		moveAlt(2, 0);
		addstrAlt("===Sell Art===");
		moveAlt(4, 0);
		addstrAlt(" Income depends on art skill and is lower if the country");
		moveAlt(5, 0);
		addstrAlt(" is very Liberal.");
		moveAlt(7, 0);
		addstrAlt(" This activity trains art, and may have a positive political");
		moveAlt(8, 0);
		addstrAlt(" effect if done well enough.");
		break;
		// }}}
		// {{{ ACTIVITY_SELL_MUSIC
	case ACTIVITY_SELL_MUSIC:
		moveAlt(2, 0);
		addstrAlt("===Play Street Music===");
		moveAlt(4, 0);
		addstrAlt(" Income depends on music skill. ");
		moveAlt(6, 0);
		addstrAlt(" An equipped guitar will increase income substantially and speed skill gains.");
		moveAlt(7, 0);
		addstrAlt(" Income is lower if the public mood is Liberal.");
		moveAlt(9, 0);
		addstrAlt(" This activity trains music, and may have a positive political");
		moveAlt(10, 0);
		addstrAlt(" effect if done well enough.");
		break;
		// }}}
		// }}}
		// {{{ Illegal fund raising
		// {{{ ACTIVITY_SELL_DRUGS
	case ACTIVITY_SELL_DRUGS:
		moveAlt(2, 0);
		addstrAlt("===Selling Brownies===");
		moveAlt(4, 0);
		addstrAlt(" Selling brownies on the street is an illegal way to make money. Money earned is ");
		moveAlt(5, 0);
		addstrAlt(" based upon the activists persuasion, street sense and business skill.");
		moveAlt(7, 0);
		addstrAlt(" It raises persuasion, street sense, and business. Street sense is used ");
		moveAlt(8, 0);
		addstrAlt(" to avoid being caught. If caught and tried, the severity of the crime can vary ");
		moveAlt(9, 0);
		addstrAlt(" greatly based upon circumstances. ");
		moveAlt(11, 0);
		addstrAlt(" The more Conservative that the drug laws are, the more money you will make. However, ");
		moveAlt(12, 0);
		addstrAlt(" the consequences of being convicted will increase as well. ");
		break;
		// }}}
		// {{{ ACTIVITY_PROSTITUTION
	case ACTIVITY_PROSTITUTION:
		moveAlt(2, 0);
		addstrAlt("===Prostitution===");
		moveAlt(4, 0);
		addstrAlt(" Prostitution is an activity which raises money illegally. The amount of money");
		moveAlt(5, 0);
		addstrAlt(" made is based on seduction. The Seduction skill is trained and it also");
		moveAlt(6, 0);
		addstrAlt(" decreases your Juice every time you do it. Prostitution is quite lucrative ");
		moveAlt(7, 0);
		addstrAlt(" with seduction that is over 10.");
		moveAlt(9, 0);
		addstrAlt(" Street sense will help you evade being criminalized and caught.");
		break;
		// }}}
		// {{{ ACTIVITY_CCFRAUD
	case ACTIVITY_CCFRAUD:
		moveAlt(2, 0);
		addstrAlt("===Credit Card Fraud===");
		moveAlt(4, 0);
		addstrAlt(" To steal credit card numbers you need to have someone who has a computer ");
		moveAlt(5, 0);
		addstrAlt(" skill of at least 2. The more computer skill your hacker has the more money ");
		moveAlt(6, 0);
		addstrAlt(" you will make. This activity trains computer skill.");
		break;
		// }}}
		// {{{ ACTIVITY_REPAIR_ARMOR
	case ACTIVITY_REPAIR_ARMOR:
		moveAlt(2, 0);
		addstrAlt("===Repair Clothing===");
		moveAlt(4, 0);
		addstrAlt(" Repairing clothing will repair damaged armor and remove blood stains if there ");
		moveAlt(5, 0);
		addstrAlt(" are any. ");
		moveAlt(7, 0);
		addstrAlt(" The chance of repairing the clothing is dependant on the quality of ");
		moveAlt(8, 0);
		addstrAlt(" the clothing and the tailoring skill of the activist.");
		break;
		// }}}
		// }}}
		// {{{ Stealing {cars,wheelchairs}
	case ACTIVITY_STEALCARS:
		moveAlt(2, 0);
		addstrAlt("===Stealing a Car===");
		moveAlt(4, 0);
		addstrAlt(" Stealing a car will have the Liberal attempt to steal a car from the street. ");
		moveAlt(5, 0);
		addstrAlt(" if successful, the car will be added to your garage. ");
		moveAlt(7, 0);
		addstrAlt(" Street sense determines the chances of finding a specific type of car, ");
		moveAlt(8, 0);
		addstrAlt(" security determines the successfulness of any attempt to break into or hotwire ");
		moveAlt(9, 0);
		addstrAlt(" the car. ");
		moveAlt(11, 0);
		addstrAlt(" Strength determines the chances of effectively breaking a car window, intelligence ");
		moveAlt(12, 0);
		addstrAlt(" determines the ease of which the car keys are found. ");
		break;
		// }}}
		// {{{ default
	default:
		moveAlt(2, 0);
		addstrAlt("===THE GREAT UNKNOWN===");
		moveAlt(4, 0);
		addstrAlt("There is no help on this topic yet, as the help system is quite new.");
		moveAlt(5, 0);
		addstrAlt("However, if you want to help us, you could write one, and send it to us!");
		break;
		// }}}
	}
	set_color(COLOR_WHITE, COLOR_BLACK, 0);
	moveAlt(23, 0);
	addstrAlt("   Press any key - Return to previous screen");
	getkey();
}