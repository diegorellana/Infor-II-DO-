#include "machine.h"

int main()
{
	machine* lista[100];
	lista[0] = new machine(130, 80, 1, 36, 18, 7);
	lista[1] = new machine(120, 80, 1, 36, 18, 5);
	lista[2] = new SPM(150, 80, 1, 36, 18, 5, 10);
	int cont = 3;
	int opc;

	while (true)
	{
		cout << "1. Agregar\n";
		cout << "2. Listado\n";
		cout << "3. Grabar a fichero\n";
		cout << "4. Leer de fichero\n";
		cout << "5. Salir\n";
		cout << "\t Opc: "; cin >> opc;

		if (opc == 1)
		{
			int opc2;
			cout << "1. Machine\n";
			cout << "2. SPM\n";
			cout << "\t Op: "; cin >> opc2;

			double w_t_s; //espesor del diente del estator
			double h_agap; //altura del entrehierro
			double h_slot; //altura de ranura
			int Q_s; //Numero de ranuras de estator
			double D_int_s; //diametro interior estator

			if (opc2 == 1)
			{
				double D_ext_s; //diametro exterior estator

				cout << "D_ext_s: "; cin >> D_ext_s;
				cout << "w_t_s: "; cin >> w_t_s;
				cout << "h_agap: "; cin >> h_agap;
				cout << "h_slot: "; cin >> h_slot;
				cout << "Q_s: "; cin >> Q_s;
				cout << "D_int_s: "; cin >> D_int_s;
				lista[cont++] = new machine(D_ext_s, D_int_s, w_t_s, h_agap, h_slot, Q_s);
			}

			else if (opc2 == 2)
			{
				double h_PM;
				double D_ext_PM;

				cout << "D_ext_PM: "; cin >> D_ext_PM;
				cout << "w_t_s: "; cin >> w_t_s;
				cout << "h_agap: "; cin >> h_agap;
				cout << "h_slot: "; cin >> h_slot;
				cout << "Q_s: "; cin >> Q_s;
				cout << "D_int_s: "; cin >> D_int_s;
				cout << "h_PM: "; cin >> h_PM;
				lista[cont++] = new SPM(D_ext_PM, D_int_s, w_t_s, h_agap, h_slot, Q_s, h_PM);
			}
		}

		if (opc == 2)
		{
			for (int i = 0; i < cont; i++)
			{
				lista[i]->prt();
			}
		}

		if (opc == 3)
		{
			string filename = "Datos.txt";
			ofstream objeto_escritura(filename);

			if (objeto_escritura.is_open())
			{
				for (int i = 0; i < cont; i++)
				{
					lista[i]->Escribir_fichero(objeto_escritura);
				}
			}

			cout << "Registrado en " << filename << endl;
			objeto_escritura.close();
		}

		if (opc == 4) 
		{
			//recorro y borro los datos hasta ahora
			for (int i = 0; i < cont; i++)
			{
				delete lista[i];
			}

			cont = 0;
			string filename = "Datos.txt";
			ifstream objeto_lectura(filename);

			if (objeto_lectura.is_open())
			{
				while (cont < 100)
				{
					//si no hay mas objetos, break
					if (!(objeto_lectura))
					{
						break;
					}

					//si siguen habiendo objetos
					machine* c = new machine();
					lista[cont] = c;
					lista[cont]->Cargar(objeto_lectura);
					cont++;
					
				}
			}
		}

		if (opc == 5)
		{
			for (int i = 0; i < cont; i++)
			{
				delete lista[i];
			}
			break;
		}
	}

	return 0;
}