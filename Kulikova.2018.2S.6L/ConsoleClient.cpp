// ConsoleClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IntegralLibrary.h"
#include <iostream>

using namespace Integral;

int main()
{
	double beginSegm = 0, endSegm = 0, epsilon = 0, integral = 0;
	unsigned number = 0;
	const double PI = 3.14159265;
	endSegm = PI / 4;

	while (true)
	{
		std::cout << "Enter a : " << std::endl;
		std::cin >> beginSegm;
		std::cout << "Enter epsilon : " << std::endl;
		std::cin >> epsilon;
		std::cout << "Enter number of segments : " << std::endl;
		std::cin >> number;

		if ((beginSegm < endSegm) && (number > 0) && (epsilon < 1) && (epsilon > 0))
		{
			break;
		}

		std::cout << "Prameters are incorrect! Try again! " << std::endl;
	}

	integral = DoubleConverting(beginSegm, endSegm, epsilon, number, SinExp, TrapezoidalRule);
    std::cout << std::endl;
	std::cout << "Trapezoidal Rule : " << integral << std::endl;
	
	integral = DoubleConverting(beginSegm, endSegm, epsilon, number, SinExp, RuleOfSimpson);
	std::cout << std::endl;
	std::cout << "Simpson's Rule : " << integral << std::endl;

	system("pause");
    return 0;
}

