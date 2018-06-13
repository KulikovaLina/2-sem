// ConsoleClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringLibrary.h"
#include <iostream>

using namespace String;

int main()
{
	const int N = 256;

	char source[N];
	std::cout << " Enter your string : " << std::endl;
	std::cin.getline(source, N, '\n');

	int n = 0;

	char ** words = ObtainWords(source, n);

	DisplayWords(words, n);

	FreeHeap(words, n);

	system("pause");
    return 0;
}

