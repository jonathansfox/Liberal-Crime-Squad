
class Interval
{
public:
	int min, max;
	Interval();
	Interval(int value);
	Interval(int low, int high);
	void set_interval(int low, int high);
	// Sets the interval according to a string that is either a number or two
	// number separated by a dash. Returns false and does not change the
	// interval if the given string is not a valid interval.
	bool set_interval(const string& interval); // implemented in misc.cpp
	int roll() const;
private:
	// Checks if a string is a number. Assumes non-numeric characters other
	// than dashes have already been checked for.

};

