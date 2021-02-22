
vector<string> founderQuestions;

const string error = "ERROR";


const string singleDot = ".";
const string singleSpace = " ";
const string city = "CITY: ";
const string spaceDashSpace = " - ";
const string pressAnyKeyString = "Press any other key when ready to begin...";
const string pressAnyOtherKey = "Press any other key to continue...";

vector<file_and_text_collection> newgame_file_collection = {
	/*newgame.cpp*/
	customText(&founderQuestions, "newgame\\founderQuestions.txt"),
};
const string ALL_OPTIONS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string pressBtoBeReborn = " (Press B to be born to a different family)";
const string pressCtoChangeSex = " (Press C to change your sex at birth)";
const string history = "HISTORY: ";
const string letMeChoose = "Let Me Choose";
const string letFateDecide = "Let Fate Decide";
const string pressDtoToggle = " (Press D to toggle childhood)";
const string pressEtoRelocate = " (Press E to relocate)";
const string sexIs = "SEX: ";
const string male = "Male";
const string female = "Female";
const string itsComplicated = "It's Complicated";
const string theFounder = "The Founder of the Liberal Crime Squad";
const string firstName = "FIRST NAME: ";
const string pressAtoReconsider = " (Press A to have your parents reconsider)";
const string lastName = "LAST NAME: ";
const string theDocSaid = "The doctor said I was ";
const string aBoy = "a boy";
const string aGirl = "a girl";
const string intersex = "an intersex baby";
const string myParents = "My parents ";
const string insistedOtherwise = "insisted otherwise.";
const string they = "They ";
const string namedMe = "named me ";
const string A_NEW_CON_ERA = "A NEW CONSERVATIVE ERA";
const string theYearIs = "The Year is ";
const string CONSERVATIVE_PRESIDENT = "Conservative President ";
const string endsSecondTerm = " ends his second term with approval";
const string highSeventiesApprovePres = "ratings in the high 70s, and is succeeded by hardcore Arch-Conservative";
const string WITH_CONSERVATIVES_SWEEPING_INTO_POWER = "With Conservatives sweeping into power in the House of Representatives";
const string senateConMajority = "and Senate, and a Conservative majority in the Supreme Court of the";
const string US_HAILING_BEGINNING_OF_A_NEW = "United States, commentators are hailing it as the beginning of a new";
const string conEra = "Conservative era.";
const string thePresident = "President ";
const string hasAskedCongressBeQuick = " has asked the new Congress to move quickly";
const string rubberStampArchCon = "to rubber stamp his radical Arch-Conservative agenda. ";
const string theLeftSeems = "The left seems";
const string powerlessToStop = "powerless to stop this imminent trampling of Liberal Sanity and Justice.";
const string inThisDarkTime = "In this dark time, the Liberal Crime Squad is born...";
const string unSelected = "[ ]";
const string isSelected = "[X]";
const string newGameAdvanced = "New Game of Liberal Crime Squad: Advanced Gameplay Options";
const string A_CLASSIC_MODE = " A - Classic Mode: No Conservative Crime Squad.";
const string B_CCS_STARTS_ACTIVE_AND_STRONG = " B - We Didn't Start The Fire: The CCS starts active and extremely strong.";
const string C_NIGHTMARE_MODE = " C - Nightmare Mode: Liberalism is forgotten. Is it too late to fight back?";
const string d_nationalLCS = " D - National LCS: Advanced play across multiple cities.";
const string e_marathonMode = " E - Marathon Mode: Prevent Liberals from amending the Constitution.";
const string f_stalinistMode = " F - Stalinist Mode: Enable Stalinist Comrade Squad (not fully implemented).";
const string newGameYourAgenda = "New Game of Liberal Crime Squad: Your Agenda";
const string A_NO_COMPROMISE = " A - No Compromise Classic - I will make all our laws Elite Liberal!";
const string B_DEMOCRAT_MODE = " B - Democrat Mode - Most laws must be Elite Liberal, some can be Liberal.";
const string newGameFieldLearn = "New Game of Liberal Crime Squad: Field Learning";
const string AFFECTS_THESE_SKILLS = "(affects Security, Stealth, Disguise, & Driving)";
const string A_FAST_SKILLS = " A - Fast skills - Grinding is Conservative!";
const string B_CLASSIC_EXCELLENCE_REQUIRES_PRACTICE = " B - Classic - Excellence requires practice.";
const string C_HARD_MODE = " C - Hard Mode - Learn from the best, or face arrest!";
const string notCreature = "Not a creature";
const string notValidMap = "Not a valid mappable site";
const string notSpecialWound = "Not a special wound";
const string notASkill = "Not a skill";
const string notAnAttribute = "Not an attribute";
const string tag_CLIP = "CLIP";
const string tag_CLIP_ASSAULT = "CLIP_ASSAULT";
const string tag_WEAPON = "WEAPON";
const string tag_WEAPON_AUTORIFLE_AK47 = "WEAPON_AUTORIFLE_AK47";
const string tag_SPORTS_CAR = "SPORTS_CAR";
const string tag_ASSAULT_RIFLE = "ASSAULT_RIFLE";
const string tag_RECRUITS_GANG = "RECRUITS_GANG";
const string tag_JUICE = "JUICE";
const string tag_ARMOR = "ARMOR";
const string tag_B = "B";
const string tag_BASE = "BASE";
const string tag_CREATURE = "CREATURE";
const string tag_HASMAPS = "HASMAPS";
const string tag_GAY = "GAY";
const string tag_D = "D";
const string tag_DATING_LAWYER = "DATING_LAWYER";
const string tag_MONEY = "MONEY";
const string tag_YEAR = "YEAR";
const string tag_DAY = "DAY";
const string tag_MONTH = "MONTH";
const string tag_BIRTHDAY_ = "BIRTHDAY_";
const string tag_STARTING_ = "STARTING_";
const string tag_ATTRIBUTE_ = "ATTRIBUTE_";
const string tag_SKILL_ = "SKILL_";
const string tag__2 = "_2";
const string tag_QUESTION = "QUESTION";
const string tag_ANSWER = "ANSWER";
const string tag_HEADER = "HEADER";
const string tag_ARMOR_CLOTHES = "ARMOR_CLOTHES";
const string tag_value = "value";
const string tag_attribute = "attribute";
const string tag_skill = "skill";
map<string, int> founderQuestionTags = {
	map<string, int>::value_type(tag_HEADER, ENUM_tag_HEADER),
	map<string, int>::value_type(tag_ANSWER, ENUM_tag_ANSWER),
	map<string, int>::value_type(tag_QUESTION, ENUM_tag_QUESTION),
	map<string, int>::value_type(tag_SKILL_, ENUM_tag_SKILL_),
	map<string, int>::value_type(tag_ATTRIBUTE_, ENUM_tag_ATTRIBUTE_),
	map<string, int>::value_type(tag_STARTING_, ENUM_tag_STARTING_),
	map<string, int>::value_type(tag_BIRTHDAY_, ENUM_tag_BIRTHDAY_),
	map<string, int>::value_type(tag_MONEY, ENUM_tag_MONEY),
	map<string, int>::value_type(tag_DATING_LAWYER, ENUM_tag_DATING_LAWYER),
	map<string, int>::value_type(tag_GAY, ENUM_tag_GAY),
	map<string, int>::value_type(tag_HASMAPS, ENUM_tag_HASMAPS),
	map<string, int>::value_type(tag_CREATURE, ENUM_tag_CREATURE),
	map<string, int>::value_type(tag_BASE, ENUM_tag_BASE),
	map<string, int>::value_type(tag_ARMOR, ENUM_tag_ARMOR),
	map<string, int>::value_type(tag_JUICE, ENUM_tag_JUICE),
	map<string, int>::value_type(tag_RECRUITS_GANG, ENUM_tag_RECRUITS_GANG),
	map<string, int>::value_type(tag_ASSAULT_RIFLE, ENUM_tag_ASSAULT_RIFLE),
	map<string, int>::value_type(tag_SPORTS_CAR, ENUM_tag_SPORTS_CAR),
};