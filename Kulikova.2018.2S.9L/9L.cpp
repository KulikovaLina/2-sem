// 9L.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

void CreateFile(char*, int);
int ContentsFile(char*);
int* InitArray(char*, int);
int FindMinElement(int * const, int);
int * AllocateMemory(int);
void RemoveElement(int * const, int&, int);
void CreateNewArray(int * const, int&, int * const, int&, int);
int BinaryRepresentation(int);
void Swap(int&, int&);
void BubbleSort(int * const, int);
void AddFile(char*, int*, int);

int main()
{
	const int N = 20;
	char fileName[N] = "";
	cout << "Enter the name of the file : " << endl;
	cin.getline(fileName, N, '\n');
	int n;
	cout << "Enter count of numbers : " << endl;
	cin >> n;
	CreateFile(fileName, n);
	int count = ContentsFile(fileName);
	int * array = InitArray(fileName, count);
	int min = FindMinElement(array, count);
	int k = count;
	int* newarray = AllocateMemory(k);
	CreateNewArray(array, count, newarray, k, min);
	BubbleSort(newarray, k);
	AddFile(fileName, newarray, k);
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
		int temp = rand() % 100 - 45;
		streamOut.width(5);
		streamOut << temp;
	}

	streamOut.close();
}

int ContentsFile(char * fileName)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open the file to read! " << endl;
		system("pause");
		exit(1);
	}

	int count = 0, term;

	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}

	streamIn.close();
	return count;
}

int * InitArray(char * fileName, int n)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open the file to read!" << endl;
		system("pause");
		exit(1);
	}

	int* array = new int[n];
	for (int i = 0; i < n; i++)
		streamIn >> array[i];
	streamIn.close();

	return array;
}

int FindMinElement(int * const array, int n)
{
	int i = 0;

	while (array[i] == 0 && i < n)
	{
		i++;
	}

	int min = array[i];

	for (int j = 0; j < n; j++)
	{
		if (array[j] < min && array[j] != 0)
		{
			min = array[j];
		}
	}

	return min;
}

int * AllocateMemory(int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension must be more than zero!");
	}

	int * array = new int[n];

	if (array == nullptr)
	{
		throw std::bad_alloc();
	}

	return array;
}

void RemoveElement(int * const array, int & n, int index)
{
	for (int i = index; i < n - 1; i++)
	{
		array[i] = array[i + 1];
	}

	n--;
}

void CreateNewArray(int * const array, int & n, int * const newarray, int & k, int min)
{
	if (k <= 0)
	{
		throw std::out_of_range("Dimension must be more than zero!");
	}

	if (newarray == nullptr)
	{
		throw std::bad_alloc();
	}

	int j = 0;

	for (int i = 0; i < n - 1; i++)
	{
		if (array[i] % min == 0)
		{
			newarray[j] = array[i + 1];

			RemoveElement(array, n, i + 1);

			j++;
		}
	}

	k = j;
}

int BinaryRepresentation(int value)
{
	int counter = 0;

	while (value)
	{
		if (value % 2 != 0)
		{
			counter++;
		}

		value /= 2;

		if (value == 1)
		{
			counter++;
			break;
		}
	}

	return counter;
}

void Swap(int & a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int * const array, int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension must be more than zero!");
	}

	if (array == nullptr)
	{
		throw std::bad_alloc();
	}

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (BinaryRepresentation(array[i]) > BinaryRepresentation(array[i + 1]))
			{
				Swap(array[i], array[i + 1]);
			}
		}
	}
}

void AddFile(char * fileName, int * array, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "\nSorted array!\n";
	for (int i = 0; i < n; i++)
	{
		streamOut.width(5);
		streamOut << array[i];
	}
	streamOut.close();
}
