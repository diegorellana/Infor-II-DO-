#include <iostream>
#include <vector>
#include <string>
using namespace std;

string words_to_phrase(string words1[], int len)
{
	string phrase = "";
	for (int i = 0; i < len; i++)
	{
		phrase = phrase + words1[i] + " ";
	}
	return phrase;
}

string words_to_phrase(vector<string> words)
{
	string phrase = "";
	for (int i = 0; i < words.size(); i++)
	{
		phrase += words[i] + " ";
	}
	return phrase;
}

vector <string> phrase_to_words(string phrase)
{
	vector <string> words;
	string word = "";
	for (int i = 0; i < phrase.size(); i++)
	{
		if (phrase[i] != ' ')
		{
			word += phrase[i];
		}

		if (phrase[i] == ' ')
		{
			words.push_back(word);
			word = "";
		}

	}
	return words;
}

string* phrase_to_words(string phrase, int& len)
{
	string* words; int pos = 0; string word = ""; len = 0;
	
	//Contar palabras
	for (int i = 1; i < phrase.size(); i++)
	{
		//Si encuentro un espacio luego de una letra, aumento el numero de palabras
		if (phrase[i] == ' ' && isalpha(phrase[i - 1]))
		{
			len++;
		}
	}

	//Si el primer espacio es una letra, aumento el numero de palabras
	if (isalpha(phrase[0])) { len++; }

	//Asigno el numero de palabras a new string
	words = new string[len];

	//Busco y asigno palabras
	for (int i = 0; i < phrase.size(); i++)
	{
		if (phrase[i] != ' ')
		{
			word += phrase[i];
		}

		if (phrase[i] == ' ')
		{
			words[pos] = word;
			pos++;
			word = "";
		}
	}

	if (word != "")
	{
		words[pos] = word;
		pos++;
	}

	return words;
}

int main()
{
	string words1[5] = { "red", "blue", "green", "yellow", "black" };
	vector<string> words2 = { "red", "blue", "green", "yellow", "black" };
	int len = sizeof(words1) / sizeof(string);
	string phrase1 = words_to_phrase(words1, len);
	string phrase2 = words_to_phrase(words2);
	cout << "phrase 2: " << phrase2;

	int len2;
	vector <string> words3 = phrase_to_words(phrase1);
	string* words4 = phrase_to_words(phrase2, len2);
}