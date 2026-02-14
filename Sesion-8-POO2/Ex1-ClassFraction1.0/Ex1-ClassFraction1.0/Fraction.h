#include <iostream>
using namespace std;

class Fraction
{
	int num, den;

	void simplify()
	{
		long m, n, r;
		if (num < den)
		{
			m = den;
			n = num;
		}

		else
		{
			m = num;
			n = den;
		}

		r = m % n; //r = resto entre m/n y n = max com divisor
		while (r != 0)
		{
			m = n;
			n = r;
			n = m % n;
		}

		num /= n;
		den /= n;
	}
public:
	Fraction(int n = 1, int d = 1) //Constructor "2 en 1"	
	{
		num = n; 
		if (d != 0) { den = d; simplify(); }
		else { cout << "ERROR. Prueba otra vez"; }
	}

	~Fraction() 
	{
		cout << "Destructor Fraction..." << endl;
	}

	void prt()
	{
		cout << "[" << num << "/" << den << "] ";
	}

	Fraction Add(Fraction& f)
	{
		Fraction fs;
		fs.den = den * f.den;
		fs.num = num * (fs.den / den) + f.num * (fs.den / f.den);

		return fs;
	}
};

