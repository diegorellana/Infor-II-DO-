#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <iomanip>

using namespace std;
class BankProduct
{
private:
	string holder;
public:
	BankProduct() { ; }
	BankProduct(string _holder)
	{
		holder = _holder;
	}
	void setHolder(string h) { holder = h; }
	string getHolder() { return holder; }
};

//-----------------ACCOUNTS--------------------
class BankAccount : public BankProduct 
{
public:
	vector<double> balance;
protected:
	vector<string> type;
public:
	BankAccount() { ; }
	BankAccount(string _holder, double _balance) : BankProduct(_holder)
	{
		balance.push_back(_balance);
		type.push_back("Initial");
	}
	// Add more functions if necessary
	virtual void prt()
	{
		cout << getTipo() << endl;
		cout << "Holder: " << getHolder() << endl;
		cout << "Actual balance: " << balance.back() << endl;
		cout << "Actual type: " << type.back() << endl;
		cout << endl;
	}

	virtual string getTipo() { return "Account"; }
};

class SalaryAccount : public BankAccount 
{
public:
	SalaryAccount() 
	{ 
		string h;
		cout << "Enter the name of the holder of the Salary Account: "; cin >> h;
		setHolder(h);

		balance.push_back(0);
		type.push_back("Initial");
	}
	SalaryAccount(string _holder, double _balance) : BankAccount(_holder, _balance) {}
	
	string getTipo() { return "Salary Account"; }

	void prt()
	{
		cout << setw(21) << this << setw(16) << getHolder() << setw(18) << balance.back() << endl;
	}
};

class SavingsAccount : public BankAccount 
{
	double interest;
public:
	SavingsAccount() 
	{ 
		string h;
		cout << "Enter the name of the holder of the Savings Account: "; cin >> h;
		setHolder(h);

		balance.push_back(0);
		type.push_back("Initial");
		interest = 0;
	}
	SavingsAccount(string _holder, double _balance) : BankAccount(_holder, _balance) 
	{
		interest = 0;
	}
	
	string getTipo() { return "Savings account"; }
};

//----------------CARDS----------------------

class Card : public BankProduct 
{
protected:
	SalaryAccount* associated_account;
public:
	Card() { ; }
	Card(SalaryAccount* _associated_account)
	{
		associated_account = _associated_account;
		string _holder = _associated_account->getHolder();
		setHolder(_holder);
	}

	Card(string _holder, SalaryAccount* _associated_account) : BankProduct(_holder)
	{
		associated_account = _associated_account;
	}
	
	virtual void prt()
	{
		cout << getTipo() << endl;
		cout << "Holder: " << getHolder() << endl;
		cout << "Associated Account's Holder: " << associated_account->getHolder() << endl;
	}

	virtual string getTipo() { return "Card"; }
};

class DebitCard : public Card 
{
public:
	DebitCard()
	{
		string _holder;
		cout << "Enter the Debit Card's holder name: "; cin >> _holder;
		setHolder(_holder);

		SalaryAccount* _associated_account = new SalaryAccount(_holder, 0);

		associated_account = _associated_account;
	}
	DebitCard(string _holder, SalaryAccount* _associated_account) : Card(_holder, _associated_account) {}
	DebitCard(SalaryAccount* _associated_account) : Card(_associated_account) {}
	string getTipo() { return "Debit Card"; }

	void prt()
	{
		cout << setw(24) << this << setw(10) << getTipo() << setw(15) << getHolder() << setw(21) << this->associated_account << setw(16) << associated_account->getHolder() << setw(18) << associated_account->balance.back() << endl;
	}
};

class CreditCard : public Card 
{
private:
	double credit;
public:
	CreditCard()
	{
		string _holder;
		cout << "Enter the Credit Card's holder name: "; cin >> _holder;

		setHolder(_holder);
		SalaryAccount* _associated_account = new SalaryAccount(_holder, 0);

		associated_account = _associated_account;
		credit = 0;
	}
	CreditCard(SalaryAccount* _associated_account) : Card(_associated_account) { credit = 0; }
	CreditCard(string _holder, SalaryAccount* _associated_account) : Card(_holder, _associated_account) { credit = 0; }
	string getTipo() { return "Credit Card"; }
	void prt()
	{
		cout << getTipo() << endl;
		cout << "Holder: " << getHolder() << endl;
		cout << "Associated Account's Holder: " << associated_account->getHolder() << endl;
		cout << "Credit: " << credit << endl;
	}
};