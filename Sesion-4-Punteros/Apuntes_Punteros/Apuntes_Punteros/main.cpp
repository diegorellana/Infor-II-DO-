#include <iostream>
#include <string.h>
using namespace std;

//Operador de direccion &: permite ver la direccion de una variable
//Operador de indireccion *: permite ver el valor almacenado en la zona de memoria

void basico_puntero();
void punteros_arrays();
void numbers();
void indexacion_puntero();
void asignacion_dinamica_memoria();
void ordenar_dinamico();
void estructuras_dinamicas();
void puntero_doble_matriz();

int main()
{
	int opc;
	while (true)
	{
		cout << "1. Salir \n";
		cout << "2. Basico Puntero\n";
		cout << "3. Punteros y Arrays \n";
		cout << "4. Numbers \n";
		cout << "5. Indexacion Punteros \n";
		cout << "6. Asignacion Dinamica Memoria \n";
		cout << "7. Ordenar Dinamico \n";
		cout << "8. Estructuras Dinamicas \n";
		cout << "9. Puntero Doble Matriz \n";
		cout << "Opcion: "; cin >> opc;

		if (opc == 1) { break; }

		if (opc == 2) { basico_puntero(); }

		if (opc == 3) { punteros_arrays(); }

		if (opc == 4) { numbers(); }

		if (opc == 5) { indexacion_puntero(); }

		if (opc == 6) { asignacion_dinamica_memoria(); }

		if (opc == 7) { ordenar_dinamico(); }

		if (opc == 8) { estructuras_dinamicas(); }

		if (opc == 9) { puntero_doble_matriz(); }
	}

	return 0;
}

void basico_puntero()
{
	int valor;
	int* ptr;

	valor = 10;
	ptr = &valor;

	cout << "El valor es " << valor << " y su direccion es: " << &valor << endl;
	cout << "Ahora voy a modificar el valor usando el ptr... " << endl;
	*ptr = 50;
	cout << "Ahora el valor es " << valor << " y su direccion es " << ptr << endl;
	cout << "Si nos damos cuenta, podemos acceder a la direccion usando &valor: " << &valor;
	cout << "\n O podemos acceder usando ptr: " << ptr << endl;
}

void punteros_arrays()
{
	//VER DATOS DE UN ARRAY USANDO PUNTEROS
	int data[20]; //creamos array de 20 espacios
	int* ptr_data = data; //con el ptr accedo al PRIMER valor del array

	//--- ASIGNAR VALOR INDIVIDUAL AL ARRAY ---
	*(ptr_data + 3) = 4; //con esto digo que quiero acceder al elemento 3 del array y asignarle el valor 4
	*(data + 4) = 5; //tambien puedo hacerlo de esta manera

	int datos[] = { 10,20,30,40,50 };
	int numDatos = sizeof(datos) / sizeof(int);
	cout << "Numero de datos: " << numDatos << endl;

	//acceder a datos con el indice
	for (int i = 0; i < numDatos; i++)
	{
		cout << "Datos [" << i << "]: " << datos[i] << endl;
	}	
}

void numbers()
{
	int numbers[5];
	int* p;
	p = numbers; 

	*(p + 0) = 1;
	*(numbers + 1) = 2;

	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		*(p + i) = i;
	}

	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		cout << "numbers [" << i << "]: " << numbers[i] << endl;
	}
}

void indexacion_puntero()
{
	const char *str = "Me gustan los punteros"; //SOLO funciona con const char
	cout << "Mensaje: " << endl << str << endl;

	const char* ptr = str;


	//Mensaje invertido
	cout << "Mensaje invertido: " << endl;
	for (int i = strlen(str); i > -1; i--)
	{
		cout << str[i];
	}
	cout << endl;

	//Mensaje normal con puntero
	cout << "\nMensaje normal:\n";
	for (int i = 0; i < strlen(str); i++)
	{
		cout << ptr[i];
	}
	cout << endl;
}

void asignacion_dinamica_memoria()
{
	int n;
	cout << "Introduzca el numero de datos: "; cin >> n;
	int* datos = new int[n];
	if (datos == NULL) { cout << "error. "; }

	for (int i = 0; i < n; i++)
	{
		datos[i] = i * 2;
	}

	for (int i = 0; i < n; i++)
	{
		cout << "datos [" << i << "]: " << datos[i] << endl;
	}

	delete[] datos; //elimina los datos pero no el ptr
}

void ordenar_dinamico()
{
	int n; int opc2;
	cout << "Num datos: "; cin >> n;
	int* datos = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "datos [" << i << "]: "; cin >> datos[i];
	}

	//ordenar los datos
	cout << "Ordenar: \n";
	cout << "1. De menor a mayor \n";
	cout << "2. De mayor a menor \n";
	cin >> opc2;

	if (opc2 == 1)
	{
		int tmp;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (datos[i] < datos[j])
				{
					tmp = datos[i];
					datos[i] = datos[j];
					datos[j] = tmp;
				}
			}
		}
	}

	if(opc2 == 2)
	{
		int tmp;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (datos[i] > datos[j])
				{
					tmp = datos[i];
					datos[i] = datos[j];
					datos[j] = tmp;
				}
			}
		}
	}

	cout << "Datos ordenados: \n";
	for (int i = 0; i < n; i++)
	{
		cout << "datos [" << i << "]: " << datos[i] << endl;
	}

	delete[] datos;
}

void estructuras_dinamicas()
{
	struct alumno
	{
		int carnet;
		char nombre[50];
	};

	alumno* ptr = new alumno;
	strcpy_s(ptr->nombre, 50, "Diego");
	ptr->carnet = 1000;

	cout << "INFO:" << endl;
	cout << "Nombre: " << ptr->nombre << endl;
	cout << "Carnet: " << ptr->carnet << endl;

	delete ptr;

	int n;
	cout << "\n Ahora lo voy a intentar con un array de estructuras: " << endl;
	cout << "Numero de alumnos: "; cin >> n;

	alumno* ptr_din = new alumno[n];
	for (int i = 0; i < n; i++)
	{
		char name_buff[50];
		cout << "Alumno " << i + 1 << ":\n";
		cout << "Nombre: "; 
		cin.ignore();
		cin.getline(name_buff,50);
		strcpy_s(ptr_din[i].nombre, 50, name_buff);
		cout << "Carnet: "; cin >> ptr_din[i].carnet;
	}

	cout << "INFO TOTAL: \n";
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Alumno " << i + 1 << ":\n";
		cout << "Nombre: " << ptr_din[i].nombre << endl;
		cout << "Carnet: " << ptr_din[i].carnet << endl;
	}

	delete[] ptr_din;
}

void puntero_doble_matriz()
{
	int row, col;
	int** mat;

	cout << "Num filas: "; cin >> row;
	cout << "Num columnas: "; cin >> col;

	// ASIGNAR VALORES...
	mat = new int*[row]; //Hago un array de row cantidad de punteros

	for (int i = 0; i < row; i++)
	{
		mat[i] = new int[col]; //por cada fila hago un array de columnas
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			mat[i][j] = rand() % (0 + 9);
		}
	}

	cout << "Los valores son: " << endl;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << mat[i][j] << "   ";
		}
		cout << endl;
	}
}