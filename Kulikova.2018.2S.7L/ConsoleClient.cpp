// ConsoleClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "EquationLibrary.h"
#include <iostream>

using namespace Equation;

int main()
{
	double root, epsilon;

	std::cout << " Enter the initial approximation : " << std::endl;
	std::cin >> root;

	while (true)
	{
		std::cout << "Enter accuracy : " << std::endl;
		std::cin >> epsilon;

		if (epsilon < 1 && epsilon > 0)
			break;
		std::cout << "Accuracy is incorrect! Try again! " << std::endl;
	}

	std::cout << "Newton Method : " << std::endl;

	for (double i = 0.5; i <= 4; i += 0.5)
	{
		std::cout << "a = " << i << " : " << NewtonMethod(root, epsilon, i) << std::endl;
	}

	std::cout << "Modified method of secans : " << std::endl;

	for (double i = 0.5; i <= 4; i += 0.5)
	{
		std::cout << "a = " << i << " : " << ModifiedMethodOfSecans(root, epsilon, i) << std::endl;
	}

	system("pause");
    return 0;
}

