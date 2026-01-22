#include <iostream>
#include <cstring>
using namespace std;
#define NUMMAX 30 //sin el = y sin ;
//Ejemplo de ordenar números dados por el teclado (usando array’s)

void ejercicio_array_chars();
void ejercicio_array_doubles();
void ejercicio_estructuras();
void ejercicio_array_de_estructuras();

int main()
{
	int opc;
	while (true)
	{
		cout << "Menu de ejercicios: " << endl;
		cout << "1. Ejercicio Array Doubles \n";
		cout << "2. Ejercicio Chars \n";
		cout << "3. Ejercicio Estructuras \n";
		cout << "4. Ejercicio Array de Estructuras \n";
		cout << "5. Salir \n";
		cout << "Selecciona: "; cin >> opc;

		if (opc == 1)
		{
			ejercicio_array_doubles();
		}

		if (opc == 2)
		{
			ejercicio_array_chars();
		}

		if (opc == 3)
		{
			ejercicio_estructuras();
		}

		if (opc == 4)
		{
			ejercicio_array_de_estructuras();
		}

		if (opc == 5)
		{
			break;
		}
	}

	return 0;
}

void ejercicio_array_doubles()
{
	int num, Max = 0, tmp;
	int datos[NUMMAX]; //creo un array de ints que pueda guardar el maximo. Luego esto cambiara...
	cout << "Cuantos numeros deseas ordenar (MAX 30)? "; cin >> num;

	if (num > NUMMAX) { cout << "Error.";}

	else
	{
		for (int i = 0; i < num; i++)
		{
			cout << "Dame el numero " << i + 1 << ": "; cin >> datos[i];
		}

		//Algoritmo para ordenar
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (datos[i] < datos[j]) //> es descendente y < es ascendente
				{
					tmp = datos[i];
					datos[i] = datos[j];
					datos[j] = tmp;
				}
			}
		}

		cout << "El arreglo ordenado es: " << endl;

		for (int i = 0; i < num; i++)
		{
			cout << datos[i] << " ";
		}
		cout << endl;

		cout << "Ahora buscamos el maximo: " << endl;
		for (int i = 0; i < num; i++)
		{
			if (datos[i] > Max)
			{
				Max = datos[i];
			}
		}

		cout << "El maximo es: " << Max << endl;
	}
}

void ejercicio_array_chars()
{
	char ciudad[20] = "San Sebastian";
	char name[] = "Juan Pablo"; //Viene bien si quieres modificar la cadena y sabes lo que quieres que ponga
	const char *direccion = "Paseo Manuel Lardizabal 13"; //solo sirve con const char

	cout << "Se puede acceder de manera independiente a cada elemento del char...\n";

	cout << "Con ciudad: " << endl;
	for (int i = 0; i < strlen(ciudad); i++) //strlen() te da el size hasta el \0 sin contar el \0
	{
		cout << i << ": " << ciudad[i] << endl;
	}

	cout << "Con el nombre: " << endl;
	for (int i = 0; i < strlen(name); i++) 
	{
		cout << i << ": " << name[i] << endl;
	}

	cout << "Con la direccion: " << endl;
	cout << direccion << endl;
	for (int i = 0; i < strlen(direccion); i++) //IMPORTANTE: USAR STRLEN()
	{
		cout << i << ": " << direccion[i] << endl;
	}

	char nombre[20];
	cin.ignore();
	cout << "Ahora haremos un ejercicio de capturar nombres: " << endl;
	cout << "Insertar nombre y apellido: ";
	cin.getline(nombre, 20); //cin.getline() ayuda a que tambien se capturen los espacios
	cout << "Tu nombre es:"; cout << nombre << endl;

	cout << "Y elemento a elemento: " << endl;
	for (int i = 0; i < (int)strlen(nombre); i++)
	{
		cout << nombre[i] << endl;
	}
	cout << "Ahora voy a modificar un elemento del nombre " << endl;
	nombre[2] = 'J'; nombre[3] = 'u'; nombre[4] = 'a'; nombre[5] = 'n';
	cout << "Tu nuevo nombre es: "; cout << nombre << endl;
}

void ejercicio_estructuras()
{
	//EJERCICIO DE ESTRUCTURA - ALUMNO
	//ESTRUCTURA: Forma de almacenar variables de distinto tipo
	struct alumno
	{
		char nombre[30];
		char apellido[30];
		int carnet;
	};

	alumno alumno1;
	cin.ignore();

	cout << "Introduzca su nombre: "; 
	cin.getline(alumno1.nombre, 30); //usas el mismo cin.getline pero con las variables de la estructura;

	cout << "Introduzca su apellido: ";
	cin.getline(alumno1.apellido, 30);

	cout << "Introduzca su carnet: "; 
	cin >> alumno1.carnet;

	cout << "Los datos son: " << endl;
	cout << "Nombre: " << alumno1.nombre << endl;
	cout << "Apellido: " << alumno1.apellido << endl;
	cout << "Carnet: " << alumno1.carnet << endl;
}

void ejercicio_array_de_estructuras()
{
	struct alumno
	{
		char nombre[30];
		char apellido[30];
		int carnet;
	};

	alumno alumnoTecnun[3]; //ARRAY DE ESTRUCTURAS
	cout << "Ingrese los datos de 3 alumnos" << endl;
	cin.ignore();

	for (int i = 0; i < 3; i++)
	{
		cout << " ---- Alumno " << i + 1 << " ----" << endl;
		cout << "Nombre: "; 
		cin.getline(alumnoTecnun[i].nombre, 30);
		cout << "Apellido: "; 
		cin.getline(alumnoTecnun[i].apellido, 30);
		cout << "Carnet: "; cin >> alumnoTecnun[i].carnet;

		cin.ignore(1000, '\n');
	}

	cout << "Los datos ingresados son: " << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << " ---- Alumno " << i + 1 << " ----" << endl;
		cout << "Nombre: " << alumnoTecnun[i].nombre << endl;
		cout << "Apellido: " << alumnoTecnun[i].apellido << endl;
		cout << "Carnet: " << alumnoTecnun[i].carnet << endl;
	}

}