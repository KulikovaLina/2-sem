// StringLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "StringLibrary.h"
#include <iostream>
#include <stdexcept>
#include <cstring>

bool String::CompareWords(char ** words, char * word, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (word == words[i])
		{
			return 1;
		}
	}

	return 0;
}

char ** String::ObtainWords(char * source, int & n)
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

	n = 0;

	char * symbols = "          1234567890-=!@#$%^&*()_+{}|][;:'<>/?,.\2 ";
	char * pword = strtok(copy, symbols);
	char first = pword[0], last = pword[strlen(pword) - 1];

	if (first == last)
	{
		words[n] = new char[strlen(pword) + 1];
		strcpy(words[n], pword);
		n++;
	}

	while (pword)
	{
		pword = strtok("\0", symbols);
		first = pword[0], last = pword[strlen(pword) - 1];

		if (pword != 0 && first == last && CompareWords(words, pword, n) == 0)
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

	delete[] copy;
	return words;
}

void String::DisplayWords(char ** words, int n)
{
	if (words == nullptr)
	{
		throw std::bad_alloc();
	}

	for (int i = 0, j = 1; i < n; i++, j++)
	{
		std::cout << j << "). " << words[i] << std::endl;
	}
}

void String::FreeMemory(char ** words, int n)
{
	if (words == nullptr)
	{
		throw std::bad_alloc();
	}

	for (int i = 0; i < n; i++)
	{
		delete[] words[i];
	}

	delete[] words;
}
