#include <iostream>
#include <math.h>
using namespace std;

class complex
{
	double real;
	double imag;

public:

	//SetThings
	void setData()	//Assign Values
	{
		cout << "Real: "; cin >> real;
		cout << "Imag: "; cin >> imag;
	}
	void setReal(double r) { real = r; }
	void setImag(double i) { imag = i; }

	//GetThings
	double getReal() { return real; }
	double getImag() { return imag; }

	//Operations
	complex Add(complex& c)
	{
		complex cs;
		cs.real = real + c.real; 
		cs.imag = imag + c.imag;

		return cs;
	}

	complex Subtraction(complex& c) 
	{ 
		complex cs;
		cs.real = real - c.real;
		cs.imag = imag - c.imag;
		return cs;
	}
	complex Multiplication(complex& c)
	{ 
		complex cs;
		cs.real = real * c.real - imag * c.imag; 
		cs.imag = real * c.imag + imag * c.real; 
		return cs;
	}
	complex Division(complex& c)
	{
		complex cs;
		cs.real = (real * c.real + imag * c.imag) / (pow(c.real, 2) + pow(c.imag, 2));
		cs.imag = (imag * c.real) / (pow(c.real, 2) + pow(c.imag, 2));
		return cs;
	}
	void Prt()		//Print values
	{
		cout << real << " + " << imag << "i";
	}

	double modulus()
	{
		return (sqrt(pow(real, 2) + pow(imag, 2)));
	}
};

