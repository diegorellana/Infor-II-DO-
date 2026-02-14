#include "BankAcc.h"

double BankAcc::interest = 0.01;
int main()
{
	BankAcc acc1(100), acc2(200);
	cout << "Acc1: " << acc1.Balance() << endl;
	cout << "Acc2: " << acc2.Balance() << endl;

	acc1.IntPayment();
	acc2.IntPayment();

	acc1.Payment(50);
	acc2.Payment(20);

	cout << "Acc1: " << acc1.Balance() << endl;
	cout << "Acc2: " << acc2.Balance() << endl;

	if (acc1.Transfer(80, acc2) == true)
	{
		cout << "Transfer made" << endl;
	}

	else
	{
		cout << "  No Balance.." << endl;
		acc1.AddBalance(100);
	}
	
	cout << "Acc1: " << acc1.Balance() << " Acc2: " << acc2.Balance();
}