#include "BankProduct.h"

int main()
{
	SalaryAccount* cn1, * cn2, * cn3;
	cn1 = new SalaryAccount("Andrea", 1700);
	cn2 = new SalaryAccount("Peter", 1500);
	cn3 = new SalaryAccount();
	SavingsAccount* ca1, * ca2, * ca3;
	ca1 = new SavingsAccount("Diana", 2000);
	ca2 = new SavingsAccount("Paul", 2000);
	ca3 = new SavingsAccount();


	DebitCard* td1, * td2, *td3;
	CreditCard* tc1, * tc2, *tc3;
	// Same holder on the Card and on the account
	td1 = new DebitCard(cn1);
	tc1 = new CreditCard(cn1);
	// Different holder in the Card and in the account
	td2 = new DebitCard("Marc", cn1);
	tc2 = new CreditCard("Esther", cn2);

	// Same holder on the Card and on the account using default constructor
	td3 = new DebitCard();
	tc3 = new CreditCard();

	// Save all the created variables within next variables
	vector<SalaryAccount*> list_cn;
	SavingsAccount** list_ca;
	vector<Card*> list_t;

	//Save Salary Accounts
	list_cn.push_back(cn1);
	list_cn.push_back(cn2);
	list_cn.push_back(cn3);

	//Save Savings accounts
	list_ca = new SavingsAccount * [3];
	list_ca[0] = ca1;
	list_ca[1] = ca2;
	list_ca[2] = ca3;

	//Save Cards
	list_t.push_back(td1);
	list_t.push_back(tc1);
	list_t.push_back(td2);
	list_t.push_back(tc2);
	list_t.push_back(td3);
	list_t.push_back(tc3);

	// Main continuation
	cout << endl << "----------------------------------------------------------" << endl;
	cout << "ACCOUNT LIST: " << endl;
	cout.setf(ios::left);
	cout << "Salary accounts " << endl;
	cout << setw(21) << " Account adress" << setw(16) << "Account holder" << setw(18) << "Account balance" << endl;
	for (int i = 0; i < list_cn.size(); i++)
	{
		list_cn[i]->prt(); // Print the SalaryAccount list
	}

	cout << "Savings accounts " << endl;
	cout << setw(21) << " Account adress" << setw(16) << "Account holder" << setw(18) << "Account balance" << endl;
	for (int i = 0; i < 3; i++)
	{
		list_ca[i]->prt(); // Print the SavingsAccount list
	}

	cout << endl << "----------------------------------------------------------" << endl;
	cout << "CARD LIST BY TYPE: " << endl;
	// Print debit cards
	cout << "Debit cards" << endl;
	cout << setw(24) << " Card adress" << setw(10) << "Type" << setw(15) << "Card holder" << setw(21) << " Account adress" << setw(16) << "Account holder" << setw(18) << "Account balance" << endl;

	//Write your code
	for (int i = 0; i < list_t.size(); i++)
	{
		if (list_t[i]->getCredit() == -1)
		{
			list_t[i]->prt();
		}
	}

	// Print credit cards
	cout << "Credit cards" << endl;
	cout << setw(24) << " Card adress" << setw(10) << "Type" << setw(15) << "Card holder" << setw(21) << " Account adress" << setw(16) << "Account holder" << setw(18) << "Account balance" << endl;
	// Write your code
	for (int i = 0; i < list_t.size(); i++)
	{
		if (list_t[i]->getCredit() != -1)
		{
			list_t[i]->prt();
		}
	}

	cout << endl << "----------------------------------------------------------" << endl;
	cout << "LIST OF CARDS WITH THE SAME HOLDER AS THE ACCOUNT HOLDER: " << endl;
	cout << setw(24) << " Card adress" << setw(10) << "Type" << setw(15) << "Card holder" << setw(21) << " Account adress" << setw(16) << "Account holder" << setw(18) << "Account balance" << endl;
	for (int i = 0; i < list_t.size(); i++)
	{
		if (list_t[i]->sameHolder())
		{
			list_t[i]->prt();
		}
	}


	//Main continuation
	cout << endl << "----------------------------------------------------------" << endl;
	cout << "TRANSFER BETWEEN BANK ACCOUNTS: " << endl;
	bool b;

	list_cn[0]->prt();
	list_ca[1]->prt();

	b = list_cn[0]->Transferencia(list_ca[1], 100);
	cout << "Transfer done? (0=No, 1=Yes): " << b << endl;
	list_cn[0]->prt();
	list_ca[1]->prt();
	b = list_cn[0]->Transferencia(list_ca[1], 10000);
	cout << "Transfer done? (0=No, 1=Yes): " << b << endl;
	list_cn[0]->prt();
	list_ca[0]->prt();

	//Continuation
	cout << endl << "----------------------------------------------------------" << endl;
	cout << "PAYMENTS WITH CARDS: " << endl;
	b = list_t[0]->Payment(25);
	cout << "Paymentment done? (0=No, 1=Yes): " << b << endl;
	list_cn[0]->prt();

	b = list_t[0]->Payment(20000);
	cout << "Paymentment done? (0=No, 1=Yes): " << b << endl;
	list_cn[0]->prt();
	b = list_t[1]->Payment(3);
	cout << "Paymentment done? (0=No, 1=Yes): " << b << endl;
	list_cn[0]->prt();
	b = list_t[1]->Payment(7);
	cout << "Paymentment done? (0=No, 1=Yes): " << b << endl;
	list_cn[0]->prt();
	b = list_t[1]->Payment(8);
	cout << "Paymentment done? (0=No, 1=Yes): " << b << endl;
	list_cn[0]->prt();

	cout << endl;
	b = list_t[1]->CreditLiquidation();
	cout << "Credit card liquidation? (0=No, 1=Yes)" << b << endl;
	list_cn[0]->prt();

	cout << endl << "----------------------------------------------------------" << endl;
	cout << "ACCOUNT MOVEMENTS: " << endl;
	list_cn[0]->movements();
	cout << endl;
	list_ca[1]->movements();

	return 0;
}