#include "Central.h"
#include <cstdlib>

int Menu()
{
	int opc = 0;
	while (opc < 1 || opc > 10) {
		system("cls"); // Limpia la pantalla de la consola
		cout << "MENU" << endl;
		cout << "\t1. Mostrar fecha con distintos formatos" << endl;
		cout << "\t2. Leer nombres de fichero y mostrar por pantalla" << endl;
		cout << "\t3. Ordenar nombres leidos y mostrar por pantalla" << endl;
		cout << "\t4. Añadir Central" << endl;
		cout << "\t5. Añadir mantenimiento" << endl;
		cout << "\t6. Mostrar informacion" << endl;
		cout << "\t7. Grabar datos en fichero" << endl;
		cout << "\t8. Ajustar potencia de una central" << endl;
		cout << "\t9. Ajustar potencia del sistema" << endl;
		cout << "\t10. Salir" << endl;
		cout << " Opcion: ";
		cin >> opc;
	}
	return opc;
};

int Menu2() 
{
	int opc = 0;
	while (opc < 1 || opc > 2) {
		cout << "\nSUB MENU" << endl;
		cout << "\t1. Añadir central Eolica" << endl;
		cout << "\t2. Añadir central de Gas" << endl;
		cout << " Opcion: ";
		cin >> opc;
		cout << endl;
	}
	return opc;
};

int Menu3() 
{
	int opc = 0;
	while (opc < 1 || opc > 3) {
		cout << "\nSUB MENU" << endl;
		cout << "\t1. Mostrar centrales Eolicas" << endl;
		cout << "\t2. Mostrar centrales de Gas" << endl;
		cout << "\t3. Mostrar todas las centrales" << endl;
		cout << " Opcion: ";
		cin >> opc;
		cout << endl;
	}
	return opc;
};

vector<string> LeerDeFichero(ifstream& f)
{
	vector<string> names;
	string name_aux;

	while (!f.eof())
	{
		getline(f,name_aux); //es de #include <string>
		names.push_back(name_aux);
	}

	return names;
}


void mostrarNombres(vector<string> names) //No es obligatoria, pero se recomienda
{
	for (int i = 0; i < names.size(); i++)
	{
		cout.setf(ios::left);
		cout << i << ": " << setw(25) << names[i] << endl;
	}

	cout.unsetf(ios::left);
}

void main() 
{
	Eolica* listEolicas[100]; //Si lo desea puede utilizar vector<Eolica*>
	Gas* listGas[100]; //Si lo desea puede utilizar vector<Gas*>
	Central* list[200]; //Si lo desea puede utilizar vector<Planta*>
	int contE = 0; // Contador de centrales eólicas
	int contG = 0; // Contador de centrales de gas
	int cont = 0; // Contador de centrales
	int opc2 = 0, opc = 0;
	bool flag = 0, flag2 = 0;
	vector<string> names; // Vector con nombres disponibles para las centrales

	struct mantenimiento
	{
		EUR::Fecha fecha;
		string tarea;
	};

	while (opc != 10)
	{
		opc = Menu();
		if (opc == 1)
		{
			cout << "\nUso de namespaces: " << endl;
			int d, y, m;
			cout << "Dia: "; cin >> d;
			cout << "Mes: "; cin >> m;
			cout << "Año: "; cin >> y;
			cout << "Fecha con formato europeo: ";
			
			EUR::Fecha fecha_eur = EUR::Fecha(d, m, y);
			fecha_eur.prt();
			cout << endl;

			cout << "Fecha con formato internacional: ";
			
			INT::Fecha fecha_int = INT::Fecha(d, m, y);
			fecha_int.prt();
			cout << endl;

			system("pause");
		}
		if (opc == 2) 
		{
			cout << "\nNombres leidos de fichero: " << endl;
			
			ifstream objeto_lectura("Nombres.txt");

			if (objeto_lectura.is_open())
			{
				names = LeerDeFichero(objeto_lectura);
			}
			objeto_lectura.close();

			mostrarNombres(names);

			flag2 = 1;
			system("pause");
		}
		if (opc == 3 && flag2 == 1) 
		{
			cout << "\nNombres ordenados alfabeticamente: " << endl;
			
			//bubble sort
			string tmp;
			for (int i = 0; i < names.size(); i++)
			{
				for (int j = 0; j < names.size(); j++)
				{
					if (names[i] < names[j])
					{
						tmp = names[i];
						names[i] = names[j];
						names[j] = tmp;
					}
				}
			}

			mostrarNombres(names);

			system("pause");
		}
		if (opc == 4 && flag2 == 1) 
		{
			cout << "\nAñadir central: " << endl;
			opc2 = Menu2();
			
			if (opc2 == 1) //eolica
			{
				mostrarNombres(names);
				cout << endl;
				int num; double coste_base; int opc_off;
				cout << "Selecciona un numero: "; cin >> num;

				string nombre_aux = names[num];
				names[num] = "";

				cout << "Coste fijo (euros/MWh): "; cin >> coste_base;
				cout << "Es offshore? Si(1) No(0): "; cin >> opc_off;


				if (opc_off == 1) //si es offshore
				{
					listEolicas[contE] = new EolicaOffshore(nombre_aux, coste_base);
					list[cont] = listEolicas[contE];

					int opc_turb;
					while (true)
					{
						double potencia;
						cout << "Potencia de turbina eolica (MW): "; cin >> potencia;
						listEolicas[contE]->AddTurbina(potencia);

						cout << "Agregar otra turbina? Si(1) No(0): "; cin >> opc_turb;

						if (opc_turb == 0) { break; }
					}

					cont++;
					contE++;
				}

				if (opc_off == 0) //si no es offshore
				{
					listEolicas[contE] = new Eolica(nombre_aux, coste_base);
					list[cont] = listEolicas[contE];

					int opc_turb;
					while (true)
					{
						double potencia;
						cout << "Potencia de turbina eolica (MW): "; cin >> potencia;
						listEolicas[contE]->AddTurbina(potencia);

						cout << "Agregar otra turbina? Si(1) No(0): "; cin >> opc_turb;

						if (opc_turb == 0) { break; }
					}

					cont++;
					contE++;
				}
			}

			if (opc2 == 2) //Gas
			{
				mostrarNombres(names);
				cout << endl;
				int num; double coste_base; int opc_off;
				cout << "Selecciona un numero: "; cin >> num;

				string nombre_aux = names[num];
				names[num] = "";

				double consumo_gas, precio_gas;
				cout << "Coste fijo (euros/MWh): "; cin >> coste_base;
				cout << "Consumo gas (ton/Mwh): "; cin >> consumo_gas;
				cout << "Precio gas (euros/ton): "; cin >> precio_gas;

				listGas[contG] = new Gas(nombre_aux, coste_base, precio_gas, consumo_gas);
				list[cont] = listGas[contG];

				int opc_turb;
				while (true)
				{
					double potencia;
					cout << "Potencia de turbina gas (MW): "; cin >> potencia;
					listGas[contG]->AddTurbinaGas(potencia);

					cout << "Agregar otra turbina? Si(1) No(0): "; cin >> opc_turb;

					if (opc_turb == 0) { break; }
				}

				cont++;
				contG++;
			}
			system("pause");
		}

		if (opc == 5)
		{
			cout << "Añadir mantenimiento" << endl;
			
			cout << "\n Lista de Centrales\n";
			for (int i = 0; i < cont; i++)
			{
				cout.setf(ios::left);
				cout << i << setw(25) << list[cont]->getID() << endl;
			}

			int num, dia, mes, anno;
			string tarea;
			cout << "Selecciona un numero: "; cin >> num;
			cout << "Dia (1-31): "; cin >> dia;
			cout << "Mes(1-12): "; cin >> mes;
			cout << "Anno: "; cin >> anno;
			cout << "Dime tarea realizada: "; cin >> tarea;
			EUR::Fecha fecha_mantenimiento = EUR::Fecha(dia, mes, anno);
			


			system("pause");
		}
		if (opc == 6)
		{
			cout << "\nMostrar informacion de centrales" << endl;
			// Añadir código necesario
			system("pause");
		}
		if (opc == 8) 
		{
			cout << "\nAjustar potencia de una Central" << endl;
			// Añadir código necesario
			system("pause");
		}
		if (opc == 9) 
		{
			cout << "\nAjustar potencia del sistema" << endl;
			// Añadir código necesario
			system("pause");
		}
		if (opc == 10)
		{
			cout << "\nSalir" << endl;
			// Añadir código necesario
		}
	}
}