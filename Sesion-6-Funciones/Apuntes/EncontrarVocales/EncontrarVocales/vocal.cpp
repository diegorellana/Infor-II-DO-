#include <iostream>
using namespace std;

int count(char* frase, char vocales)
{
	int len = strlen(frase);
	int num_algo = 0;
	for (int i = 0; i < len; i++)
	{
		if (frase[i] == vocales)
		{
			num_algo++;
		}
	}

	return num_algo;
}

int main()
{
	char frase[50], voc[] = { 'a', 'e', 'i', 'o', 'u' };
	while (true)
	{
		cout << "Inserte frase: "; cin.getline(frase, 50);

		if (strcmp(frase, "exit") == 0)
		{
			break;
		}

		for (int i = 0; i < sizeof(voc) / sizeof(char); i++)
		{
			cout << "Numero de " << voc[i] << ": " << count(frase, voc[i]) << endl;
		}
	}
}