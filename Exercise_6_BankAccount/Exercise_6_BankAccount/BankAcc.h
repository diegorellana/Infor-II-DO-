#include <iostream>
using namespace std;
class BankAcc
{
	double balance;
	static double interest;

public:
	BankAcc(double b = 0) { balance = b; }
	void AddBalance(double quant)
	{
		balance += quant;
	}
	void Payment(double amount)
	{
		balance -= amount;
	}

	void IntPayment()
	{
		balance -= balance*interest;
	}

	double Balance() { return balance; }

	bool Transfer(double amount, BankAcc& c)
	{
		if (balance < amount) { cout << "Transfer not made";  return 0; }
		else
		{
			balance -= amount;
			return 1;
		}
	}
};

