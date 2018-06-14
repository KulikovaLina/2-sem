// 11L.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int ContentsFile(char*);
char* InitString(char*, int);
char ** ObtainWords(char *, int &);
char toUppear(char);
void AddFile(char*, char**, int);


int main()
{
	const int N = 25;
	char fileName[N] = "text.txt";
	int n = ContentsFile(fileName);
	char * source = InitString(fileName, n);
	int k = 0;
	char ** words = ObtainWords(source, k);
	AddFile(fileName, words, k);
    return 0;
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

char * InitString(char * fileName, int n)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open the file to read!" << endl;
		system("pause");
		exit(1);
	}

	char* string = new char[n];
	for (int i = 0; i < n; i++)
		streamIn >> string[i];
	streamIn.close();

	return string;
}

char ** ObtainWords(char * source, int & n)
{
	char * copy = new char[strlen(source) + 1];

	if (copy == nullptr)
	{
		throw std::bad_alloc();
	}

	strcpy(copy, source);

	char ** words = new char*[strlen(copy) / 2];

	if (words == nullptr)
	{
		throw std::bad_alloc();
	}

	char * symbols = "    123456789000-=!@#$%^&*()_+{}|][;:',.<>/?\ ";
	char * pword = strtok(copy, symbols);
	char first = pword[0];
	char last = pword[strlen(pword) - 1];

	if (toUppear(first) == toUppear(last))
	{
		words[n] = new char[strlen(pword) + 1];

		if (words[n] == nullptr)
		{
			throw std::bad_alloc();
		}

		strcpy(words[n], pword);
		n++;
	}

	while (pword)
	{
		pword = strtok('\0', symbols);

		if (pword)
		{
			char first = pword[0];
			char last = pword[strlen(pword) - 1];

			if (toUppear(first) == toUppear(last))
			{

				words[n] = new char[strlen(pword) + 1];

				if (words[n] == nullptr)
				{
					throw std::bad_alloc();
				}

				strcpy(words[n], pword);
				n++;
			}
		}
	}

	delete[] copy;
	return words;
}

char toUppear(char symbol)
{
	int diff = 'a' - 'A';

	if (symbol >= 'A' && symbol <= 'Z')
	{
		return (symbol + diff);
	}

	return symbol;
}

void AddFile(char * fileName, char ** words, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "\nResult:\n";
	for (int i = 0; i < n; i++)
	{
		streamOut.width(5);
		streamOut << words[i];
	}
	streamOut.close();
}
