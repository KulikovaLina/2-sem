// ConsoleClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringLibrary.h"
#include <iostream>

using namespace String;

int main()
{
	const int N = 256;

	char str[N];
	std::cout << "Enter your string : " << std::endl;
	std::cin >> str;

	int n = 0;
	char ** words = ObtainWords(str, n);

	std::cout << std::endl;
	DisplayWords(words, n);
	std::cout << std::endl;

	FreeMemory(words, n);

	system("pause");
    return 0;
}

