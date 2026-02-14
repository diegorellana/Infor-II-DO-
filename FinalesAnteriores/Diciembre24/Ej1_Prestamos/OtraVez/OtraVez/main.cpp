#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Fecha
{
	int dia, mes, anno;
};

struct cuenta
{
	int numero; //pe 2001
	char* name; //puntero para nombre
};

struct prestamo
{
	cuenta cta; //cuenta asociada
	Fecha faper; //fecha apertura
	double cantidad; //euros
};

#define MAX 100 //num máximo de préstamos
#define INTERES 0.1 //interés diario en %.
void main()
{
	int np = 0;
	prestamo lstPres[MAX]; //array de préstamos
	int nc = 0;
	cuenta lstCuenta[MAX]; //array de cuentas
	int opc = 0;
	while (true) 
	{
		cout << "** Gestion de Prestamos **\n";
		cout << "1. Abrir cuenta\n";
		cout << "2. Abrir prestamo\n";
		cout << "3. Pago Intereses\n";
		cout << "4. Reporte\n";
		cout << "5. Salir\n";
		cout << "\t Opc: "; cin >> opc;

		if (opc == 1)
		{
			char name_buff[30];
			int num_cuenta;
			cout << "Dar nombre: "; cin >> name_buff;
			cout << "Dar numero Cta: "; cin >> num_cuenta;

			char* name = new char[strlen(name_buff) + 1];
			strcpy_s(name, strlen(name_buff)+1, name_buff);

			cuenta cta;
			cta.name = name;
			cta.numero = num_cuenta;
			lstCuenta[nc++] = cta;
		}

		if (opc == 2)
		{
			cout << "Listado de cuentas\n";

			for (int i = 0; i < nc; i++)
			{
				cout.setf(ios::left);
				cout <<setw(5) << i + 1 << " " << setw(10) << lstCuenta[i].name << " " << setw(10) << lstCuenta[i].numero << endl;
			}

			int num;
			cout << "Seleccione la cuenta: "; cin >> num;

			int n = num - 1;

			cout << "Cuenta seleccionada: " << lstCuenta[n].name << "   " << lstCuenta[n].numero << endl;
			Fecha f_aper;
			cout << "Dar fecha (dd,mm,aaaa): "; cin >> f_aper.dia >> f_aper.mes >> f_aper.anno;
			double cantidad;
			cout << "Cantidad (euros): "; cin >> cantidad;

			lstPres[np].cta = lstCuenta[n];
			lstPres[np].faper = f_aper;
			lstPres[np].cantidad = cantidad;

			np++;
		}

		if (opc == 3)
		{
			int d_hoy, m_hoy, a_hoy;

			cout << "Dar fecha actual (dd,mm,aaaa): "; cin >> d_hoy >> m_hoy >> a_hoy;

			cout << "Listado de prestamos y sus iintereses: \n";
			int dias;
			for (int i = 0; i < np; i++)
			{
				dias = abs(lstPres[i].faper.dia - d_hoy) + 30 * abs(lstPres[i].faper.mes - m_hoy) + 360 * abs(lstPres[i].faper.anno - a_hoy);
				cout << setw(15) << "Dias: " << dias << setw(10) << "Inter: " << (lstPres[i].cantidad * INTERES) * (dias) << setw(15) << "Fecha: " << lstPres[i].faper.dia << "/" << lstPres[i]
			}
		}

		if (opc == 5)
		{
			for (int i = 0; i < nc; i++)
			{
				delete[] lstCuenta[i].name;
			}

			break;
		}
	}
}

