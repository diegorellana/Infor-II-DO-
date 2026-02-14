#include "complex.h"

int main()
{
	// complex numbers declarations
	complex c1, c2, c3;
	c1.setData();
	c2.setData();
	c3.setData(); //ask data for c3
	//assign data to c4
	double r, i;
	cout << "Give r, i of c4 : "; cin >> r >> i;
	complex c4;
	c4.setReal(r); c4.setImag(i);
	// arithmetic operators
	complex add = c1.Add(c2); //c1+c2
	complex sub = c1.Subtraction(c3); //c1-c3
	complex mul = c2.Multiplication(c4); //c2*c4
	complex div = c1.Division(c3); //c1/c3
	cout << "First complex: "; c1.Prt();
	cout << "Real : " << c1.getReal();
	cout << "Imagin.: " << c1.getImag();
	cout << "Second complex: "; c2.Prt();
	cout << "Third complex: "; c3.Prt();
	cout << "Addition: "; add.Prt();
	cout << "Subtraction: "; sub.Prt();
	cout << "Multiplication: "; mul.Prt();
	cout << "Division: "; div.Prt();
	cout << "I’ve already finished." << endl;
}

