#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100
#define INTERES 0.1

struct cuenta
{
	int numero; //pe 2001
	char* name; //puntero para nombre
};

struct Fecha
{
	int dia, mes, anno;
};

struct prestamo
{
	cuenta cta; //cuenta asociada
	Fecha faper; //fecha apertura
	double cantidad; //euros
};

int getDias(int d_hoy, int m_hoy, int a_hoy, Fecha& f)
{
	int Totaldias = 0;
	int annos = 0;
	int meses = 0;
	int dias = 0;

	annos = abs(a_hoy - f.anno);
	meses = abs(m_hoy - f.mes);
	dias = abs(d_hoy - f.dia);

	Totaldias = annos * 360 + meses * 30 + dias;
	return Totaldias;
}


int main()
{
	int np = 0;
	prestamo lstPres[MAX];
	int nc = 0;
	cuenta lstCuenta[MAX];

	int dd, mm, aa;

	int opc = 0;

	while (true)
	{
		cout << "** Gestion Prestamos **\n";
		cout << "1. Abrir Cuenta\n";
		cout << "2. Abrir Prestamo\n";
		cout << "3. Pago Intereses\n";
		cout << "4. Reporte \n";
		cout << "5. Salir \n";
		cout << "Opcion: "; cin >> opc;

		if (opc == 5) 
		{
			break;
		}

		if (opc == 1)
		{
			char name_buff[50]; 
			int num;
			cout << "Abrir cuenta\n";
			cout << "Nombre: "; cin >> name_buff;
			char* name = new char[strlen(name_buff) + 1];
			strcpy_s(name, strlen(name_buff) + 1, name_buff);

			cout << "Numero: "; cin >> num;

			lstCuenta[nc].name = name;
			lstCuenta[nc].numero = num;
			nc++;

			cout << "Cuenta registrada\n\n";
		}

		if (opc == 2)
		{
			cout << "Abrir prestamo\n\n";
			cout << "Listado de cuentas: " << endl;

			for (int i = 0; i < nc; i++)
			{
				cout << "   " << i + 1 << "   " << lstCuenta[i].name << "   " << lstCuenta[i].numero << endl;
			}

			int op, dia, mes, anno;
			double cant;
			cout << "Seleccione la cuenta: "; cin >> op;
			cout << "Dar fecha (dd/mm/aaaa): "; cin >> dia >> mes >> anno;
			cout << "Cantidad (euros): "; cin >> cant;

			//asigno fecha
			Fecha faper;
			faper.dia = dia;
			faper.mes = mes;
			faper.anno = anno;

			//asigno cuenta
			cuenta cta;
			cta.name = lstCuenta[op-1].name;
			cta.numero = lstCuenta[op-1].numero;

			//guardo en lista
			lstPres[np].faper = faper;
			lstPres[np].cta = cta;
			lstPres[np].cantidad = cant;

			np++;
			cout << endl;
		}

		if (opc == 3)
		{
			double interes;
			cout << "Fecha actual (dd/mm/aaaa): "; cin >> dd >> mm >> aa;
			cout << "Interes diario: "; cin >> interes;

			cout << "Listado de prestamos y sus intereses: \n";

			for (int i = 0; i < np; i++)
			{
				int dias = getDias(dd,mm,aa, lstPres[i].faper);
				cout << "Dias: " << dias << "   " << "Inter: " << dias * INTERES << "   " << "Monto: " << lstPres[i].cantidad << "   " << "Fecha: ";
				cout << lstPres[i].faper.dia << "/" << lstPres[i].faper.mes << "/" << lstPres[i].faper.anno << "   " << "Cuenta: " << lstPres[i].cta.name << "  " << lstPres[i].cta.numero;
				cout << endl;
			}
		}

		if (opc == 4)
		{
			string file;
			cout << "Indicar filename (sin extension): "; cin >> file;
			string filename = file + ".txt";
			ofstream objeto_escritura(filename);


			objeto_escritura << "Listado de cuentas: \n";
			for (int i = 0; i < nc; i++)
			{
				objeto_escritura << "   " << i + 1 << "   " << lstCuenta[i].name << "   " << lstCuenta[i].numero << endl;
			}

			cout << endl << endl;

			objeto_escritura << "Listado de prestamos: \n";
			
			cout << "Listado de prestamos y sus intereses: \n";

			for (int i = 0; i < np; i++)
			{
				int dias = getDias(dd, mm, aa, lstPres[i].faper);
				objeto_escritura << "Dias: " << dias << "   " << "Inter: " << dias * INTERES << "   " << "Monto: " << lstPres[i].cantidad << "   " << "Fecha: ";
				objeto_escritura << lstPres[i].faper.dia << "/" << lstPres[i].faper.mes << "/" << lstPres[i].faper.anno << "   " << "Cuenta: " << lstPres[i].cta.name << "  " << lstPres[i].cta.numero;
				objeto_escritura << endl;
			}

			cout << "Registrado correctamente en: " << filename << endl;
			objeto_escritura.close();
		}
	}


	return 0;
}