#include "Hora.h"
#define MAX_ACT 20
#define MAX_RES 100

int Menu()
{
	int op;
	cout << "**** Gestion Gimnasio ****\n";
	cout << "1. Agregar Actividad\n";
	cout << "2. Listar Actividades \n";
	cout << "3. Reservar Actividad\n";
	cout << "4. Lista de Reservas\n";
	cout << "5. Salir\n";
	cout << "\t Opcion: "; cin >> op;

	return op;
}

int main()
{
	Actividad* lstAct[MAX_ACT]; //vector para guardar las actividades
	Reserva* lstResv[MAX_RES]; //vector para guardar las reservas
	int ca = 0;
	int cr = 0;
	//definir las variables necesarias
	while (true) {
		int opc = Menu();
		if (opc == 5) 
		{
			delete lstAct;
			delete lstResv;
			break;
		}
		if (opc == 1)
		{
			char name[20]; char sala[20]; int np; int h_ini, m_ini, h_fin, m_fin;
			cout << "Act: "; cin >> name;
			char* name_p = new char[strlen(name) + 1];
			strcpy_s(name_p, strlen(name) + 1, name);
			cout << "Sala: "; cin >> sala;
			char* sala_p = new char[strlen(sala) + 1];
			strcpy_s(sala_p, strlen(sala) + 1, sala);

			cout << "Num Personas: "; cin >> np;
			cout << "Hora Inicio (hh:mm): "; cin >> h_ini >> m_ini;
			cout << "Hora Fin (hh:mm): "; cin >> h_fin >> m_fin;

			Hora h_i = Hora(h_ini, m_ini);
			Hora h_f = Hora(h_fin, m_fin);

			lstAct[ca] = new Actividad(name_p, sala_p, np, h_i, h_f);
			ca++;

		}

		if (opc == 2)
		{
			cout << "\t Listado de actividades\n";
			for (int i = 0; i < ca; i++)
			{
				lstAct[i]->prt();
			}
		}

		if (opc == 3)
		{
			string act;
			cout << "Que actividad quiere? "; cin >> act;

			cout << "Encontrados: \n";
			for (int i = 0; i < ca; i++)
			{
				if (act == lstAct[i]->getNombre())
				{
					cout << "[" << i + 1 << "]" << "\t"; lstAct[i]->prt();
				}
			}

			int sel;
			cout << "Selecciona actividad (0 para no): "; cin >> sel;

			int carnet;
			cout << "Actividad seleccionada: \n";
			cout << "\t"; lstAct[sel - 1]->prt();
			cout << "Dar carnet: "; cin >> carnet;

			lstResv[cr] = new Reserva(carnet, lstAct[sel - 1]);
			cr++;
			lstAct[sel - 1]->addReserva();
			cout << "Actividad registrada exitosamente\n\n";
		}

		if (opc == 4)
		{
			cout << "Listado de reservas\n";

			cout << "Carnet\tDatos de la actividad\n";
			for (int i = 0; i < cr; i++)
			{
				lstResv[i]->prt();
			}
			cout << endl << endl;
		}
	}
}