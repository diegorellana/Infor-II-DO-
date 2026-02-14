#include <iostream>
using namespace std;

int push_buffer(int num, int& cont, int size, int* buff)
{
	if (cont < size)
	{
		buff[cont++] = num;
		return 1;

	}

	else if (cont == size)
	{
		cout << "Buffer full!\n";
		return 0;
	}
}

int pop_buffer(int& read, int size, int* buff, int cont, int nvueltas)
{
	if (cont > 0 || nvueltas > 0)
	{
		return buff[read++];
	}
}

int main()
{
	int size;
	cout << "** CIRCULAR BUFFER ** \n";
	cout << "Give size of buffer: "; cin >> size;

	int* buff = new int[size];
	int opc;
	int cont = 0;
	int read = 0;
	int nvueltas = 0;
	while (true)
	{
		cout << "** CIRUCLAR BUFFER **\n";
		cout << "1. Put value to buffer\n";
		cout << "2. Get value from buffer\n";
		cout << "3. Check status of buffer\n";
		cout << "4. Exit program\n";
		cout << "\t Opc: "; cin >> opc;


		if (opc == 1)
		{
			int num;
			cout << "Put a number to store in buffer: "; cin >> num;

			if (push_buffer(num, cont, size, buff))
			{
				cout << "Number saved\n";
			}

			else
			{
				cout << "Buffer full!\n";
				cont = 0;
				nvueltas++;
			}
		}

		if (opc == 2)
		{
			if (cont > 0 || nvueltas > 0)
			{
				cout << "The output value is " << pop_buffer(read, size, buff, cont, nvueltas) << endl;
			}

			else
			{
				cout << "Buffer empty!\n";
			}
		}

		if (opc == 3)
		{
			if (cont > 0)
			{
				cout << "There are " << cont << " numbers in the buffer\n";
			}

			else
			{
				cout << "Buffer is empty!\n";
			}

		}
		if (opc == 4)
		{
			delete[] buff;
			break;
		}

	}

	return 0;
}