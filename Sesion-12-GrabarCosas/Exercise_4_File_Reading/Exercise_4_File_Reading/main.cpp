#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include <filesystem>

int main()
{
	double suma = 0;;
	int n = 0;
	double max = 0;
	char filename[] = "data.txt";
	ifstream infile;

	//attempt to open the file
	infile.open(filename);

	//verify that the file actually opened
	if (infile.is_open())
	{
		double x;
		while (!infile.eof())
		{
			infile >> x;
			if (x > max)
			{
				max = x;
			}
			suma += x;
			n++;
			cout << "Number: " << x << endl;
		}
	}
	
	else
	{
		cout << "ERROR! FILE NOT FOUND!\n";
	}

	cout << "Media: " << suma / n << endl;
	cout << "Maximo: " << max << endl;

	return 0;
}