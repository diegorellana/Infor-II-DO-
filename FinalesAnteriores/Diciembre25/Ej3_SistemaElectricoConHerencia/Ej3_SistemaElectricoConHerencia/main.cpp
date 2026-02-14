#include <cstdlib>
#include "Central.h"
#include <fstream>
int Menu() {
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

int Menu2() {
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

int Menu3() {
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
	string aux;
	vector <string> names;

	while (!f.eof())
	{
		getline(f, aux); //capturo toda la linea del txt, ahora aux es cada nombre
		names.push_back(aux); //meto aux a names
	}

	return names;
}

void mostrarNombres(vector<string> names) //No es obligatoria, pero se recomienda
{
	int size = names.size();

	for (int i = 1; i < names.size(); i++)
	{
		cout << i << ": " << names[i] << endl;
	}
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
	vector<string> names;

	while (opc != 10)
	{
		opc = Menu();
		if (opc == 1) {
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
		if (opc == 2) {

			ifstream objeto_lectura("Nombres.txt");
			names = LeerDeFichero(objeto_lectura);


			cout << "\nNombres leidos de fichero: " << endl;


			//Voy a poner los nombres manualmente xq chuspa no me paso el .txt
			//vector <string> names;
			/*names.push_back("Cortes-La Muela");
			names.push_back("Aldeavilla");
			names.push_back("Valdellos II");
			names.push_back("Alto Cinca");
			names.push_back("Joaquin Costa");
			names.push_back("San Roque");
			names.push_back("Puente Nuevo");
			names.push_back("Almaraz");
			names.push_back("Cofrentes");
			names.push_back("Trillo");
			names.push_back("Villarino");
			names.push_back("Jose Maria del Sol");
			names.push_back("Saucelle");
			names.push_back("Cedillo");
			names.push_back("Estany-Gento Sallente");
			names.push_back("Tajo de la Encantada");
			names.push_back("Mequinenza");*/

			mostrarNombres(names);

			flag2 = 1;
			system("pause");


		}
		if (opc == 3 && flag2 == 1) {
			cout << "\nNombres ordenados alfabeticamente: " << endl;

			for (int i = 0; i < names.size(); i++)
			{
				for (int j = 0; j < names.size(); j++)
				{
					if (names[i] < names[j])
					{
						string tmp;
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
			if (opc2 == 1) //central eolica
			{
				mostrarNombres(names);
				int num, opcion;
				double costo_fijo;
				string nombre;
				cout << endl;
				cout << "Selecciona un numero: "; cin >> num;
				nombre = names[num];
				names[num] = "";
				cout << "Coste fijo (euros/MWh): "; cin >> costo_fijo;
				cout << "Es offshore? Si (1), No (0): "; cin >> opcion;

				if (opcion == 0)
				{
					listEolicas[contE] = new Eolica(nombre, costo_fijo);
					list[cont] = listEolicas[contE];
					double potencia;
					int op;

					while (true)
					{
						cout << "Potencia de turbina eolica (MW): "; cin >> potencia;

						//Construyo 
						listEolicas[contE]->AddTurbina(potencia);


						cout << "Agregar turbina? Si (1), No (0): "; cin >> op;

						if (op == 0) { contE++; cont++;  break; }

					}
				}

				if (opcion == 1)
				{
					listEolicas[contE] = new EolicaOffshore(nombre, costo_fijo);
					list[cont] = listEolicas[contE];
					double potencia;
					int op;

					while (true)
					{
						cout << "Potencia de turbina eolica (MW): "; cin >> potencia;

						//Construyo 
						listEolicas[contE]->AddTurbina(potencia);


						cout << "Agregar turbina? Si (1), No (0): "; cin >> op;

						if (op == 0) { contE++; cont++;  break; }

					}
				}

			}

			if (opc2 == 2) //central de gas
			{
				mostrarNombres(names);
				int num, opcion;
				double costo_fijo, consumo_gas, precio_gas;
				string nombre;
				cout << endl;
				cout << "Selecciona un numero: "; cin >> num;
				nombre = names[num];
				names[num] = "";
				cout << "Coste fijo (euros/MWh): "; cin >> costo_fijo;
				cout << "Consumo de gas (ton/MWh): "; cin >> consumo_gas;
				cout << "Costo de gas (euros/ton): "; cin >> precio_gas;

				listGas[contG] = new Gas(nombre , costo_fijo, precio_gas, consumo_gas);
				list[cont] = listGas[contG];

				double potencia;
				int opp;
				while (true)
				{
					cout << "Potencia de turbina (MW): "; cin >> potencia;
					listGas[contG]->AddTurbinaGas(potencia);
					cout << "Agregar turbina? Si(1) No(0): "; cin >> opp;

					if (opp == 0) { cont++; contG++; break; }
				}
			}
		}
		system("pause");

		if (opc == 5) {
			cout << "Añadir mantenimiento" << endl;

			int num, dia, mes, anno;
			string tarea;
			cout << "Lista de centrals\n";
			for (int i = 0; i < cont; i++)
			{
				cout << i << "    " << list[i]->getNombre() << endl;
			}
			cout << "Selecciona un numero: "; cin >> num;
			cout << "Dia: "; cin >> dia;
			cout << "Mes: "; cin >> mes;
			cout << "Anno: "; cin >> anno;
			cout << "Tarea: "; cin >> tarea;

			EUR::Fecha fecha_eur = EUR::Fecha(dia, mes, anno);
			mantenimiento mant = mantenimiento(fecha_eur, tarea);
			list[num]->historialMantenimiento.push_back(mant);

			system("pause");
		}
		if (opc == 6) {
			int option;
			cout << "\nMostrar informacion de centrales" << endl;

			cout << "SUB MENU\n";
			cout << "\t1. Mostrar centrales Eolicas\n";
			cout << "\t2. Mostrar centrales de Gas \n";
			cout << "\t3. Mostrar todas las centrales\n";
			cout << "Opcion: "; cin >> option;

			if (option == 1)
			{
				cout << "Centrales Eolicas\n";
				for (int i = 0; i < contE; i++)
				{
					listEolicas[i]->show_info();
				}
			}

			if (option == 2)
			{
				cout << "Centrales de Gas\n";
				for (int i = 0; i< contG; i++)
				{
					listGas[i]->show_info();
				}
			}

			if (option == 3)
			{
				cout << "Todas las centrales\n";
				for (int i = 0; i < cont; i++)
				{
					list[i]->show_info();
				}
			}

			system("pause");
		}

		if (opc == 7)
		{
			string name;
			cout << "Grabar datos en fichero\n";
			cout << "Nombre del fichero para guardar datos: "; cin >> name;

			string filename = name + ".txt";

			ofstream objeto_escritura(filename);

			for (int i = 0; i < cont; i++)
			{
				listEolicas[i]->GrabarEnFichero(objeto_escritura);
			}

			objeto_escritura.close();
			cout << "Archivo grabado correctamente\n";
			
		}
		if (opc == 8) {
			cout << "\nAjustar potencia de una Central" << endl;
			
			cout << "Lista de Centrales: " << endl;
			cout << "Num \t Potencia \t Nombre \t" << endl;
			for (int i = 0; i < cont; i++)
			{
				cout << i << "\t" << list[i]->CalcularPotenciaTotal() << "/" << list[i]->CalcularPotenciaMaxima() << "\t" << list[i]->getNombre() << endl;
			}

			int numero;
			cout << "Selecciona un numero: "; cin >> numero;

			list[numero]->show_info();

			double pot_obj;
			cout << "Potencia objetivo: "; cin >> pot_obj;

			if (list[numero]->AjustarCargaPotenciaObjetivo(pot_obj))
			{
				cout << "La potencia objetivo se ha alcanzado \n\n";
				list[numero]->show_info();
			}

			else
			{
				cout << "La potencia objetivo no se ha alcanzado \n\n";
				list[numero]->show_info();
			}

			system("pause");
		}
		if (opc == 9) {
			cout << "\nAjustar potencia del sistema" << endl;
			
			for (int i = 0; i < cont; i++)
			{
				cout << i << "\t" << list[i]->CalcularPotenciaTotal() << "/" << list[i]->CalcularPotenciaMaxima() << "\t" << list[i]->getTipo() << " " << list[i]->getNombre() << endl;
			}
			
			double potencia_objetivo;
			cout << endl << "Cual es la potencia objetivo: "; cin >> potencia_objetivo;

			int f2=0;
			for (int i = 0; i < cont; i++)
			{
				bool f = list[i]->AjustarCargaPotenciaObjetivo(potencia_objetivo);

				if (f == 0)
				{
					potencia_objetivo -= list[i]->CalcularPotenciaMaxima();
				}

				if (f == 1)
				{
					cout << "La potencia se ha ajustado correctamente\n";
					f2 = 1;
				}
			}

			if (f2 == 0)
			{
				cout << "No hay sufiiciente potencia. El ajuste es el siguiente: \n";
			}

			for (int i = 0; i < cont; i++)
			{
				cout << i << "\t" << list[i]->CalcularPotenciaTotal() << "/" << list[i]->CalcularPotenciaMaxima() << "\t" << list[i]->getTipo() << " " << list[i]->getNombre() << endl;
			}

			system("pause");
		}
		if (opc == 10) {
			cout << "\nSalir" << endl;
			
			for (int i = 0; i < cont; i++)
			{
				delete list[i];
			}

			break;
		}
	}
}

