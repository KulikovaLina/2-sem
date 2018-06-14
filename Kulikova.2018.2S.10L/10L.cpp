// 10L.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

void CreateFile(char*, int);
int** InitMatrix(char*, int);
int ** AllocateMemory(int);
void CreateNewMatrix(int ** const, int ** const, int);
void AddFile(char*, int**, int);
void FreeMemory(int ** const, int);

int main()
{
	const int N = 20;
	char fileName[N] = "";
	cout << "Enter the name of the file : " << endl;
	cin.getline(fileName, N, '\n');
	int n;
	cout << "Enter the size of the matrix : " << endl;
	cin >> n;
	CreateFile(fileName, n);
	int ** matrix = InitMatrix(fileName, n);
	int ** newmatrix = AllocateMemory(n);
	CreateNewMatrix(matrix, newmatrix, n);
	AddFile(fileName, newmatrix, n);
	FreeMemory(matrix, n);
	FreeMemory(newmatrix, n);
    return 0;
}

void CreateFile(char * fileName, int n)
{
	ofstream streamOut(fileName);

	if (!streamOut.is_open())
	{
		cout << " Cannot open file to write! " << endl;
		system("pause");
		exit(1);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
        int temp = rand() % 100 - 45;
		streamOut.width(5);
		streamOut << temp;
		}
	}

	streamOut.close();
}

int ** InitMatrix(char * fileName, int n)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open the file to read!" << endl;
		system("pause");
		exit(1);
	}

	int** matrix = AllocateMemory(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			streamIn >> matrix[i][j];
		}
	}
	streamIn.close();

	return matrix;
}

int ** AllocateMemory(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimension can not be less or equal zero!");
	}

	int ** a = new int*[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}

	return a;
}

void CreateNewMatrix(int ** const matrix, int ** const newmatrix, int n)
{
	for (int p = 0; p < n; p++)
	{
		for (int t = 0; t < n; t++)
		{
			int k = t;
			int max = matrix[p][t];

			for (int i = p; i < n; i++)
			{
				for (int j = k; j < n; j++)
				{
					if (max < matrix[i][j])
					{
						max = matrix[i][j];
					}
				}
				k++;
			}

			k = t;
			for (int i = p - 1; i >= 0; i--)
			{
				k++;
				for (int j = k; j < n; j++)
				{
					if (max < matrix[i][j])
					{
						max = matrix[i][j];
					}
				}
			}

			newmatrix[p][t] = max;
		}
	}
}

void FreeMemory(int ** const matrix, int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimension can not be less or equal zero!");
	}

	if (matrix == nullptr)
	{
		throw std::invalid_argument("Pointer can not be null!");
	}

	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

void AddFile(char * fileName, int ** matrix, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "\nSorted matrix!\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			streamOut.width(5);
			streamOut << matrix[i][j];
		}
	}
	streamOut.close();
}
