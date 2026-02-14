#include "Fraction.h"

int main()
{
	int n, d;
	Fraction f1(1, 4);
	cout << "Enter n and d: "; cin >> n >> d;
	Fraction f2(n, d);

	cout << "\nF1: "; f1.prt(); cout << endl;
	cout << "F2: "; f2.prt(); cout << endl;

	Fraction fs = f1.Add(f2);
	cout << "F1 + F2 = "; fs.prt();
	cout << "\n Fin. \n";
	return 0;
}