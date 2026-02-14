#include "Employee.h"

int main()
{
	Employee e1(1500);
	Employee* e;
	Manager m1(1500, 1.5);
	cout << "Exercise about inheritance and polymorphism" << endl;
	cout << "Salary: " << e1.Payment() << endl;
	cout << "Salary: " << m1.Payment() << endl;
	e = &e1;
	cout << "Salary: " << e->Payment() << endl;
	e = &m1;
	cout << "Salary: " << e->Payment() << endl;
	e1.prt();
	m1.prt();
	return 0;
}