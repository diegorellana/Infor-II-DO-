#include <iostream>
using namespace std;
#include <vector>

class Employee
{
protected:
	double sal; //salary base
public:
	Employee(double s) { sal = s; }
	virtual double Payment() { return sal; }
	void prt() {
		cout << "Salary=" << Payment() << endl;
	}
};
class Manager : public Employee
{
	double inc;
public:
	Manager(double s, double i) : Employee(s) { inc = i; }
	double Payment() { return sal * inc; }
};

