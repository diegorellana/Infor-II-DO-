#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string frase1;
	cout << "Enter phrase: "; cin >> frase1;

	cout << "Backwards: \n";
	for (int i = frase1.size(); i >= 0; i--)
	{
		cout << frase1[i];
	}
	cout << endl;

	string n1, n2;
	cout << "Give two names: "; cin >> n1 >> n2;
	if (n1 == n2) { cout << "Both names are equal" << endl; }
	if (n1 > n2) { cout << n1 << " is greater than " << n2 << endl; }
	if (n1 < n2) { cout << n1 << " is less than " << n2 << endl; }
}