#include <iostream>
using namespace std;
int CountLetters(char* str, char key);
char* getPhrase(char& key);

int main()
{
	char ch;
	char* frase = getPhrase(ch);
	int n = CountLetters(frase, ch);
	cout << "In " << frase << " there are " << n << " " << ch << "'s " << endl;
}

int CountLetters(char* str, char key)
{
	int num = 0;
	int length = strlen(str);
	// code
	for (int i = 0; i < length; i++)
	{
		if (str[i] == key)
		{
			num++;
		}
	}

	return num;
}

char* getPhrase(char& key)
{
	char* frase = new char[100];

	//pido frase
	cout << "Enter phrase: "; cin.getline(frase, 100);
	cout << "Enter letter: "; cin >> key;

	return frase;
}
