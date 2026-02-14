#include <iostream>
#include <vector>
using namespace std;
int main()
{
	srand(time(NULL));

	vector <double> v1;
	int num = 0;
	cout << "Give num: "; cin >> num;

	for (int i = 0; i < num; i++)
	{
		v1.push_back(rand() * 100 / RAND_MAX);
	}

	int len = v1.size();

	for (int i = 0; i < len; i++)
	{
		cout << i << ": " << v1[i] << endl;
	}

	int pos;
	cout << "Erase? "; cin >> pos;
	v1.erase(v1.begin() + pos);

	len = v1.size();

	cout << "Again: " << endl;

	for (int i = 0; i < len; i++)
	{
		cout << i << ": " << v1[i] << endl;
	}

	v1.clear();
	return 0;
}