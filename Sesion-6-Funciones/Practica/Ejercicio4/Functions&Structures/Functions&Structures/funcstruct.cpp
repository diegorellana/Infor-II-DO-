#include <iostream>
#include <iomanip> //for setw in cout
using namespace std;

struct student
{
	char name[30];
	double nota;
};

void Pedirdatos(student* lst, int& c); //ptr a student y referencia de contador
void Listar(student lst[], int c);

int main()
{
	const int MAX = 100;
	int cont = 0;
	student lista[MAX];

	for (int i = 0; i < 2; i++) //2 por poner un tamaño
	{
		Pedirdatos(lista, cont); //vamos cambiando cont por la referencia de la función
	}
}

void Pedirdatos(student* lst, int& c)
{
	cout << "Name: "; cin.getline(lst[c].name, 30);
	cout << "Nota: "; cin >> lst[c].nota;
	cin.ignore();
	c++;
}

void Listar(student lst[], int c)
{
	cout << "*** Listado ***" << endl;
	for (int i = 0; i < c; i++)
	{
		cout << setw(30) << lst[i].name << setw(10) << lst[i].nota << endl;
	}
}