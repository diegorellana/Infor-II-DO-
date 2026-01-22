#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class BankProduct
{
private:
	string holder;
public:
	BankProduct(string _holder)
	{
		holder = _holder;
	}

	BankProduct() {}
	
	void setHolder(string h) { holder = h; }
	string getHolder() { return holder; }
};

class BankAccount : public BankProduct 
{
public:
	vector<double> balance;
protected:
	vector<string> type;
public:
	BankAccount() {}

	BankAccount(string _holder, double _balance) : BankProduct(_holder)
	{
		balance.push_back(_balance);
		type.push_back("Initial");
	}
	
	double getBalance() { return balance.back(); }

	bool Transferencia(BankAccount* acc, double monto)
	{
		if (balance.back() > 0)
		{
			if (balance.back() > monto)
			{
				//quito dinero
				double new_b = balance.back() - monto;
				balance.push_back(new_b);

				//meto dinero
				new_b = acc->getBalance() + monto;
				acc->setBalance(new_b);
				return 1;
			}

			else
			{
				return 0;
			}
		}

		else
		{
			return 0;
		}
	}

	void setBalance(double b) { balance.push_back(b); }
	void setType(string t) { type.push_back(t); }

	void movements()
	{
		for (int i = 0; i < balance.size()-1; i++)
		{
			cout << i << ":  " << " Type: " << type[i] << "    " << "Balance : " << balance[i] << endl;
		}
	}
};

class SalaryAccount : public BankAccount 
{
public:
	SalaryAccount()
	{
		string _holder;
		cout << "Ingrese el nombre de su Salary Account: "; cin >> _holder;

		setHolder(_holder);
		balance.push_back(0);
		type.push_back("Initial");
	}

	SalaryAccount(string _holder, double _balance) : BankAccount(_holder, _balance) {}

	void prt()
	{
		cout << setw(21) << this; //direccion del propio objeto
		cout << setw(16) << getHolder();
		cout << setw(18) << balance.back();
		cout << endl;
	}
};

class SavingsAccount : public BankAccount
{
	double interest;
public:
	SavingsAccount()
	{
		string _holder;
		cout << "Ingrese el nombre de su Savings Account: "; cin >> _holder;

		setHolder(_holder);
		balance.push_back(0);
		type.push_back("Initial");
		interest = 0;
	}
	SavingsAccount(string _holder, double _balance) : BankAccount(_holder, _balance)
	{
		interest = 0;
	}
	
	void prt()
	{
		cout << setw(21) << this; //direccion del propio objeto
		cout << setw(16) << getHolder();
		cout << setw(18) << balance.back();
		cout << endl;
	}
};

class Card : public BankProduct 
{
protected:
	SalaryAccount* associated_account;
public:
	Card() {}
	Card(SalaryAccount* _associated_account)
	{
		associated_account = _associated_account;
		setHolder(associated_account->getHolder());
	}
	Card(string _holder, SalaryAccount* _associated_account)
	{
		associated_account = _associated_account;
		setHolder(_holder);
	}
	// Add more functions if necessary
	virtual double getCredit() { return -99; }
	virtual void prt() {}
	bool sameHolder()
	{
		if (associated_account->getHolder() == getHolder())
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}
	virtual bool Payment(double pay) { return 0; }
	virtual bool CreditLiquidation() { return 1; }

};

class DebitCard : public Card
{
public:
	DebitCard() 
	{
		string _holder;
		cout << "Ingresar nombre para su tarjeta de debito: "; cin >> _holder;

		setHolder(_holder);
		associated_account = new SalaryAccount(_holder, 0);
	}

	DebitCard(string _holder, SalaryAccount* _associated_account) : Card(_holder, _associated_account) {}
	DebitCard(SalaryAccount* _associated_account) : Card(_associated_account) {}
	string getType() { return "Debit"; }
	
	void prt()
	{
		cout << setw(24) << this << setw(10) << getType() << setw(15) << getHolder() << setw(21) << associated_account << setw(16) << associated_account->getHolder() << setw(18) << associated_account->getBalance() << endl;
	}

	double getCredit() { return -1; }

	bool Payment(double pay)
	{
		if (associated_account->getBalance() > 0)
		{
			if (associated_account->getBalance() > pay)
			{
				//quito dinero
				double new_b = associated_account->getBalance() - pay;
				associated_account->setBalance(new_b);
				associated_account->setType((string)"Debit card payment");
				return 1;
			}

			else
			{
				return 0;
			}
		}

		else
		{
			return 0;
		}
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
		cout << "Ingresar nombre para su tarjeta de credito: "; cin >> _holder;

		setHolder(_holder);
		associated_account = new SalaryAccount(_holder, 0);
		credit = 0;
	}
	CreditCard(SalaryAccount* _associated_account) : Card(_associated_account) 
	{
		credit = 0;
	}
	CreditCard(string _holder, SalaryAccount* _associated_account)  : Card(_holder, _associated_account)
	{
		credit = 0;
	}
	// Add more functions if necessary
	string getType() { return "Credit"; }

	void prt()
	{
		cout << setw(24) << this << setw(10) << getType() << setw(15) << getHolder() << setw(21) << associated_account << setw(16) << associated_account->getHolder() << setw(18) << associated_account->getBalance() << endl;
	}

	double getCredit() { return credit; }

	bool Payment(double pay)
	{
		credit += pay;
		return 1;
	}

	bool CreditLiquidation()
	{
		if (associated_account->getBalance() > credit)
		{
			double new_b = associated_account->getBalance() - credit;
			associated_account->setBalance(new_b);
			associated_account->setType((string)"Credit liquidation");
			return 1;
		}

		else
		{
			return 0;
		}
	}
};

