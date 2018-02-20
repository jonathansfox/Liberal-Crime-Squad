
class Ledger
{
private:
	int funds;
public:
	int income[INCOMETYPENUM], expense[EXPENSETYPENUM], total_income, total_expense, dailyIncome[INCOMETYPENUM], dailyExpense[EXPENSETYPENUM];
	Ledger();
	int get_funds();
	void force_funds(int amount);
	void add_funds(int amount, int incometype);
	void subtract_funds(int amount, int expensetype);
	void resetMonthlyAmounts();
	void resetDailyAmounts();
};
