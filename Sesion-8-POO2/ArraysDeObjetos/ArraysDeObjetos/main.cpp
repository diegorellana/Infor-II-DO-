#include "CAlumno.h"

int main()
{

	//Array de objetos estatico
	CAlumno al[3];
	al[0].Asignar((char*)"Juan", 22, 617732412);
	al[1].Asignar((char*)"Pedro", 20, 617018213);

	for (int i = 0; i < 2; i++)
	{
		al[i].Print();
	}


	//Array de objetos dinamico
	int num = 2;
	CAlumno* alumnos = new CAlumno[num];
	alumnos[0].Asignar((char*)"Diego", 21, 456018732);
	alumnos[1].Asignar((char*)"Javi", 26, 123955732);

	for (int i = 0; i < num; i++)
	{
		alumnos[i].Print();
	}

	delete[] alumnos;

	//Objeto unico dinamico 
	CAlumno* pAlumno = new CAlumno((char*)"Diego", 21, 617018732);
	pAlumno->Print();

	delete pAlumno;

	return 0;
}