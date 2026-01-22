#include <iostream>
using namespace std;

void dynamic_vectors();
void dynamic_structures();
void dynamic_over_dynamic();
void dynamic_matrices();
void vector_by_matrix();

int main()
{
	int opc;
	while (true)
	{
		cout << "1. Salir \n";
		cout << "2. Dynamic Memory Allocation For Vectors \n";
		cout << "3. Dynamic Structures \n";
		cout << "4. Dynamic Over Dynamic \n";
		cout << "5. Dynamic Matrices \n";
		cout << "6. Vector By Matrix \n";
		cout << "Opcion: "; cin >> opc;

		if (opc == 1) { break; }
		if (opc == 2) { dynamic_vectors(); }
		if (opc == 3) { dynamic_structures(); }
		if (opc == 4) { dynamic_over_dynamic(); }
		if (opc == 5) { dynamic_matrices(); }
		if (opc == 6) { vector_by_matrix(); }

	}
}

void dynamic_vectors()
{
	int* vec;
	int n;

	cout << "How much data: "; cin >> n;
	vec = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "vec [" << i + 1 << "]: "; cin >> vec[i];
	}

	cout << "Sorting..." << endl;
	int tmp;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vec[i] < vec[j])
			{
				tmp = vec[i];
				vec[i] = vec[j];
				vec[j] = tmp;
			}
		}
	}

	cout << "Data sorted: " << endl;

	for (int i = 0; i < n; i++)
	{
		cout << vec[i] << "  ";
	}
	cout << endl;

	delete[] vec;

}

void dynamic_structures()
{
	struct student
	{
		char name[50];
		double mark;
	};

	student* list;
	int num = 0, pos = 0;
	char ch;

	cout << "Num of students: "; cin >> num;
	list = new student[num];

	//Ask for name and grade
	for (int i = 0; i < num; i++)
	{
		cout << "Give name and mark of student " << i + 1 << ": "; cin >> list[i].name >> list[i].mark;
	}

	//Find the worst case
	for (int i = 0; i < num; i++)
	{
		if (i == 0)
		{
			pos = i;
		}

		else
		{
			if (list[pos].mark > list[i].mark)
			{
				pos = i;
			}
		}
	}

	cout << "The worst case is: " << list[pos].name << " with " << list[pos].mark << endl;

	delete[] list;
}

void dynamic_over_dynamic()
{
	struct student
	{
		char* name;
		double mark;
	};

	student* list;
	int num = 0, pos = 0;
	char ch;

	cout << "Num of students: "; cin >> num;
	list = new student[num];

	//Ask for name and grade
	for (int i = 0; i < num; i++)
	{
		char name_buff[50];
		cout << "Give name of student " << i + 1 << ": "; cin >> name_buff;
		list[i].name = new char[strlen(name_buff)+1]; //n+1 espacios
		list[i].name[strlen(name_buff)] = '\0';
		strcpy_s(list[i].name, strlen(name_buff)+1, name_buff); //size del destinatario
		cout << "Give grade of student " << i + 1 << ": "; cin >> list[i].mark;
		cin.ignore();
	}

	//Find the worst case
	for (int i = 0; i < num; i++)
	{
		if (i == 0)
		{
			pos = i;
		}

		else
		{
			if (list[pos].mark > list[i].mark)
			{
				pos = i;
			}
		}
	}

	cout << "The worst case is: " << list[pos].name << " with " << list[pos].mark << endl;

	for (int i = 0; i < num; i++)
	{
		delete[] list[i].name;
	}

	delete[] list;
}

void dynamic_matrices()
{
	float** data;
	int col, row;

	cout << "How many rows? "; cin >> row;

	data = new float* [row]; //array de punteros a cada row

	cout << "How many cols? "; cin >> col;

	for (int i = 0; i < row; i++)
	{
		data[i] = new float[col]; //array de valores (columna) en cada fila
	}

	//usando la matriz -- asignando valores
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[i][j] = rand() % (100)+10;
		}
	}


	//print a valores
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << data[i][j] << "   ";
		}
		cout << endl;
	}
}

void vector_by_matrix()
{
	int n_vector;
	int row, col;

	cout << "Number of rows? "; cin >> row;
	cout << "Number of cols? "; cin >> col;
	cout << "Number of data in vector? (must be equal to " << row << "): "; cin >> n_vector;

	if (n_vector != row) { cout << "Error. Try again"; }

	else
	{
		int* vector = new int[n_vector];
		int** mat = new int* [row];
		int* result = new int [col]; //1xcolumnas


		//Initialize matrix
		for (int i = 0; i < row; i++)
		{
			mat[i] = new int[col];
		}

		//Assign value to vector
		for (int i = 0; i < n_vector; i++)
		{
			vector[i] = rand() % (9) + 1;
		}

		//Assign values to matrix
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				mat[i][j] = rand() % (9) + 1;
			}
		}

		//Print vector and matrix
		cout << "Values for vector:\n";
		for (int i = 0; i < n_vector; i++)
		{
			cout << vector[i] << " ";
		}
		cout << endl;

		cout << "Values for matrix: \n";
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl;

		for (int i = 0; i < col; i++)
		{
			int sum = 0;
			for (int j = 0; j < row; j++)
			{
				sum += vector[j] * mat[j][i];
			}
			result[i] = sum;
		}

		cout << "Result: "; 
		for (int i = 0; i < col; i++)
		{
			cout << result[i] << " ";
		}

		cout << endl;

		//Delete memory from matrix
		for (int i = 0; i < row; i++)
		{
			delete[] mat[i];
		}

		delete[] mat;

		//Delete memory from vector and result
		delete[] vector;
		delete[] result;

	}
}