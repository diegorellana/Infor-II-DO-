#include <iostream>
using namespace std;
#include <string>

int main()
{
	string frase1;
	cout << "Write a sentence: ";
	getline(cin, frase1); //this is cin.getline() for strings

	cout << "Backwards: \n";
	for (int i = frase1.size(); i >=0; i--)
	{
		cout << frase1[i];
	}
	cout << endl;

	string n1, n2;
	cout << "\n Give me 2 names: "; cin >> n1 >> n2; //only use cin.ignore() when you put a string next to an int

	if (n1 == n2)
	{
		cout << "Equal names" << endl;
	}

	else if (n1 < n2)
	{
		cout << n1 << " is less than " << n2 << endl;
	}

	else if (n1 > n2)
	{
		cout << n1 << " is greater than " << n2 << endl;
	}
}