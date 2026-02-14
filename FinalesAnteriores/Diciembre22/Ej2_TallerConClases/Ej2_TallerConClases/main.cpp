#include "servicio.h"
#define MAX 100
double mantenimiento::costo_hora = 40.0;

int main()
{
	int ns = 0;
	mantenimiento* lista[MAX];
	int cont = 0;

	int opc = 0;

	while (true)
	{
		cout << "** Taller Coches **\n";
		cout << "1. Agregar Coche\n";
		cout << "2. Pagar\n";
		cout << "3. Mostrar lista\n";
		cout << "4. Salir\n";
		cout << "\t Opc: "; cin >> opc;

		if (opc == 4)
		{
			for (int i = 0; i < cont; i++)
			{
				delete lista[i];
			}

			break;
		}

		if (opc == 1)
		{
			char mat[20]; int numServ; int hh_ini, mm_ini, hh_fin, mm_fin;
			cout << "Matricula: "; cin >> mat;
			cout << "Hora entrada (hh:mm): "; cin >> hh_ini >> mm_ini;
			cout << "Dar num servicios: "; cin >> numServ;

			Time tiempo = Time(hh_ini, mm_ini);
			lista[cont] = new mantenimiento(mat, tiempo, numServ);
			cont++;

			cout << "Coche registrado\n";
		}

		if (opc == 2)
		{
			char mat[20];
			int flag_mat = 0;
			int h_f, m_f;
			int num;
			cout << "Dar matricula: "; cin >> mat;


			//compruebo si existe la matricula
			for (int i = 0; i < cont; i++)
			{
				if (strcmp(lista[i]->getMatricula(),mat) == 0)
				{
					flag_mat = 1;
					num = i;
				}
			}

			if (flag_mat == 0)
			{
				cout << "Error! Reference Source not Found \n";
			}

			else
			{
				cout << "Dar hora fin: "; cin >> h_f >> m_f;

				lista[num]->setHoraFin(h_f, m_f);
				lista[num]->prt();
				cout << endl;
				lista[num]->pagar();

				//cuando ya paga, se elimina
				delete lista[num];

			}
		}

		if (opc == 3)
		{
			for (int i = 0; i < cont; i++)
			{
				lista[i]->prt();
			}
		}
	}

	return 0;
}