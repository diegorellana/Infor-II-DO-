#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	char tmp[120];
	char filename[80];
	cout << "Name of the file to be read: ";
	cin >> filename;
	fstream objeto_lectura(filename); //open file

	while (true)
	{
		objeto_lectura.getline(tmp, 120); //cin.getline
		if (objeto_lectura.eof()) //if end of file
		{
			break;
		}
		cout << tmp << endl; //print tmp to console
	}

	objeto_lectura.close();//close file

	return 0;
}