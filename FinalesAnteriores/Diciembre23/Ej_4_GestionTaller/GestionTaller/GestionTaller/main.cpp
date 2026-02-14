#include "coche.h"

int Menu()
{
	int op;
	cout << "**** Menu ****\n";
	cout << "1. Introducir coche\n";
	cout << "2. Mostrar datos \n";
	cout << "3. Grabar datos \n";
	cout << "4. Leer datos \n";
	cout << "5. Salir \n";
	cout << "Opcion: ";
	cin >> op;

	return op;
}

int main()
{
	int opc;
	coche* taller[100]; //todos los coches
	clasico* taller2[100]; //solo clasicos
	int ncoches = 0;
	int nclas = 0;

	while (true)
	{
		opc = Menu();



		if (opc == 1)
		{
			int anno, km; char placa[20];
			cout << "Anno Fabricacion: "; cin >> anno;
			cout << "Matricula: "; cin >> placa;
			cout << "Miles de km: "; cin >> km;

			if (anno < 1970)
			{
				taller2[nclas] = new clasico(anno, km, placa);
				taller[ncoches] = taller2[nclas];
				nclas++;
				ncoches++;
			}

			else
			{
				int tipo;
				cout << "Tipo (1 - Gasolina. 2 - Electrico): "; cin >> tipo;

				if (tipo == 1)
				{
					taller[ncoches] = new gasolina(anno, km, placa);
					ncoches++;
				}

				else if (tipo == 2)
				{
					taller[ncoches] = new electrico(anno, km, placa);
					ncoches++;
				}
			}
		}

		if (opc == 2)
		{
			int opc2;
			cout << "Mostrar lista coches (1) o clasicos (2): "; cin >> opc2;

			if (opc2 == 1)
			{
				for (int i = 0; i < ncoches; i++)
				{
					taller[i]->prt();
				}
			}

			else if (opc2 == 2)
			{
				for (int i = 0; i < nclas; i++)
				{
					taller2[i]->prt2();
				}
			}

		}

		if (opc == 3)
		{
			string filename = "Registro.txt";
			ofstream objeto_escritura(filename);
			int size2 = nclas;

			objeto_escritura << nclas;

			if (objeto_escritura.is_open())
			{
				for (int i = 0; i < nclas; i++)
				{
					taller2[i]->grabar(objeto_escritura);
				}
			}

			//5
			//1968
			//...

			objeto_escritura.close();
			cout << "Registrado correctamente en " << filename << endl;

		}

		if (opc == 4)
		{
			string filename = "Registro.txt";
			ifstream objeto_lectura(filename);

			//bubble sort y mando clasicos al final


			for (int i = 0; i < nclas; i++)
			{
				delete taller[i];
			}

			nclas = 0;

			//5
			//1968

			int size;
			objeto_lectura >> size;

			for (int i = 0; i < size; i++)
			{
				clasico* coche = new clasico();
				coche->leer(objeto_lectura);
				taller2[i] = coche;
			}
			
			while (nclas < 100)
			{
				clasico* c = new clasico();

				c->leer(objeto_lectura);

				if (!objeto_lectura)
				{
					delete c;
					break;
				}

				taller2[nclas] = c;
				nclas++;
			}

			cout << endl << "Leido correctamente" << endl;
			objeto_lectura.close();
		}

		if (opc == 5)
		{
			/*for (int i = 0; i < ncoches; i++)
			{
				delete taller[i];
			}*/

			break;
		}

	}
}