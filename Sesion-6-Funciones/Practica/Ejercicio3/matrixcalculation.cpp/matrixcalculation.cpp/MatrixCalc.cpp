#include <iostream>
#include <iomanip>
using namespace std;
int** CreateMatrix(int& row, int& col);
void PrtMatrix(int** mat, int row, int col);
int** AddMatrix(int** mA, int** mB, int r, int c);
void DeleteMatrix(int** mat, int row, int col);

int main()
{
	int r, c;
	int** mA = CreateMatrix(r, c);
	PrtMatrix(mA, r, c);

	int** mB = CreateMatrix(r, c);
	PrtMatrix(mB, r, c);

	int** mC = AddMatrix(mA, mB, r, c);

	cout << "---------------" << endl;
	cout << "A+B is " << endl;
	PrtMatrix(mC, r, c);

	DeleteMatrix(mA, r, c);
	DeleteMatrix(mB, r, c);
	DeleteMatrix(mC, r, c);

}

int** CreateMatrix(int& row, int& col)
{
	int** mat;
	cout << "Give Rows & Cols: "; cin >> row >> col;
	mat = new int* [row];
	for (int i = 0; i < row; i++)
	{
		mat[i] = new int[col];
		for (int j = 0; j < col; j++)
		{
			mat[i][j] = rand() % 100;
		}
	}
	return mat;
}

void PrtMatrix(int** mat, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(5) << mat[i][j];
		}
		cout << endl;
	}
}

int** AddMatrix(int** mA, int** mB, int r, int c)
{
	int** mC;
	mC = new int* [r];
	for (int i = 0; i < r; i++)
	{
		mC[i] = new int[c];
		for (int j = 0; j < c; j++)
		{
			mC[i][j] = mA[i][j] + mB[i][j];
		}
	}
	return mC;
}

void DeleteMatrix(int** mat, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
}
