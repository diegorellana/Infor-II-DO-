#include "BankProduct.h"
#include <iomanip>
int main()
{
	SalaryAccount* cn1, * cn2, * cn3;
	cn1 = new SalaryAccount("Andrea", 1700);
	cn2 = new SalaryAccount("Peter", 1500);
	cn3 = new SalaryAccount();

	cout << endl << endl;
	SavingsAccount* ca1, * ca2, * ca3;
	ca1 = new SavingsAccount("Diana", 2000);
	ca2 = new SavingsAccount("Paul", 2000);
	ca3 = new SavingsAccount();


	DebitCard* td1, * td2, * td3;
	CreditCard* tc1, * tc2, * tc3;
	// Same holder on the Card and on the account
	td1 = new DebitCard(cn1);
	tc1 = new CreditCard(cn1);


	// Different holder in the Card and in the account
	td2 = new DebitCard("Marc", cn1);
	tc2 = new CreditCard("Esther", cn2);

	// Same holder on the Card and on the account using default constructor
	td3 = new DebitCard();
	tc3 = new CreditCard();

	vector<SalaryAccount*> list_cn;
	list_cn.push_back(cn1);
	list_cn.push_back(cn2);
	list_cn.push_back(cn3);

	SavingsAccount** list_ca;
	list_ca = new SavingsAccount* [30];
	list_ca[0] = ca1;
	list_ca[1] = ca2;
	list_ca[2] = ca3;

	vector<Card*> list_t;
	list_t.push_back(td1);
	list_t.push_back(tc1);
	list_t.push_back(td2);
	list_t.push_back(tc2);
	list_t.push_back(td3);
	list_t.push_back(tc3);

	cout << endl << "------------ MENU ------------\n";
	cout << "Account List: " << endl;
	cout.setf(ios::left);
	cout << "Salary accounts " << endl;
	cout << setw(21) << " Account adress" << setw(16) << "Account holder" << setw(18) << "Account balance" << endl;
	for (int i = 0; i < list_cn.size(); i++)
	{
		list_cn[i]->prt(); // Print the SalaryAccount list
	}

	cout << endl << "----------------------------------------------------------" << endl;
	cout << "CARD LIST BY TYPE: " << endl;
	// Print debit cards
	cout << "Debit cards" << endl;
	cout << setw(24) << " Card adress" << setw(10) << "Type" << setw(15) << "Card holder" << setw(21) << " Account adress" << setw(16) << "Account holder" << setw(18) << "Account balance" << endl;

	for (int i = 0; i < list_t.size(); i++)
	{
		if (list_t[i]->getTipo() == "Debit Card")
		{
			list_t[i]->prt();
		}
	}
	return 0;
}