// StringLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <cstring>
#include "StringLibrary.h"
#include <iostream>
#include <stdexcept>

STRINGLIBRARY_API char ** String::ObtainWords(char * source, int & n)
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
		pword = strtok("\0", symbols);
		char first = pword[0];
		char last = pword[strlen(pword) - 1];
		
		if (pword != nullptr && toUppear(first) == toUppear(last))
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

STRINGLIBRARY_API char String::toUppear(char symbol)
{
	int diff = 'a' - 'A';

	if (symbol >= 'A' && symbol <= 'Z')
		{
			return (symbol + diff);
		}

	return symbol;
}

STRINGLIBRARY_API void String::DisplayWords(char ** words, int n)
{
	if (words == nullptr)
	{
		throw std::bad_alloc();
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << (i + 1) << "). " << words[i] << std::endl;
	}
}

STRINGLIBRARY_API void String::FreeHeap(char ** words, int n)
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
