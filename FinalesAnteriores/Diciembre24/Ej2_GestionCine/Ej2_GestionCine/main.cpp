#include "sala.h"

int Menu()
{
	int opc;
	cout << "**Gestion Cine**\n";
	cout << "1. Comprar entradas\n";
	cout << "2. Devolver entradas\n";
	cout << "3. Ver salas y dinero recaudado\n";
	cout << "4. Salir\n";
	cout << "Opcion: "; cin >> opc;

	return opc;
}

int main()
{
	sala* lst; //vector lista de salas

	int numSal;
	cout << "Dar numero de salas: "; cin >> numSal;
	lst = new sala[numSal];
	
	for (int i = 0; i < numSal; i++)
	{
		int fils, cols; char pelicula[40]; int hh; int mm; hora h; double precio;
		cout << "\t Sala " << i + 1 << endl;
		cout << "Numero de filas: "; cin >> fils;
		cout << "Numero de columnas: "; cin >> cols;
		cout << "Pelicula? "; cin >> pelicula; //sin espacios
		cout << "Hora? "; cin >> hh >> mm;
		h = hora(hh, mm);
		cout << "Precio: "; cin >> precio;
		cout << endl;
		lst[i] = sala(fils, cols, pelicula, precio, hh, mm);
	}

	int opc;

	while (true)
	{
		opc = Menu();
		
		if (opc == 4)
		{
			delete[] lst;
			break;
		}

		if (opc == 1)
		{
			cout << "Listado de peliculas por sala: \n";

			for (int i = 0; i < numSal; i++)
			{
				cout << "Sala: " << i + 1 << "  " << "Pelicula: " << lst[i].getPeli() << endl;
			}

			int sala;
			cout << "Que sala desea comprar? "; cin >> sala;

			cout << "Pelicula: " << lst[sala - 1].getPeli();
			cout << "Hora: " << lst[sala - 1].getHora() << ":" << lst[sala - 1].getMin() << endl;
			lst[sala - 1].prt();
			cout << endl;
			int nent;
			cout << "Numero de entradas?: "; cin >> nent;

			for (int i = 0; i < nent; i++)
			{
				lst[sala - 1].comprar();
			}


			cout << "A pagar: " << nent * lst[sala - 1].getPrecio() << " euros\n";

		}

		if (opc == 2)
		{
			cout << "Listado de peliculas por sala: \n";

			for (int i = 0; i < numSal; i++)
			{
				cout << "Sala: " << i + 1 << "  " << "Pelicula: " << lst[i].getPeli() << endl;
			}

			int sala;
			cout << "De que sala desea devolver la entrada? "; cin >> sala;

			lst[sala - 1].prt();
			cout << endl;
			lst[sala - 1].devolver();

			cout << "Devuelto: " << lst[sala - 1].getPrecio() << " euros\n";

		}

		if (opc == 3)
		{
			double total_recaudado = 0;
			for (int i = 0; i < numSal; i++)
			{
				total_recaudado += lst[i].recaudado();
			}

			cout << "Total Recaudado: " << total_recaudado << " euros " << endl;
		}

	}
	cout << "Fin" << endl;


	return  0;
}