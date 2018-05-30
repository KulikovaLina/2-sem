// ConsoleClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IntegralLibrary.h"
#include <iostream>

using namespace Integral;


int main()
{
	double epsilon = 0.0005;
	double previosIntegral = 0, nextIntegral = 1;
	double lowerLimit, uppearLimit, n;
	
	while (true)
	{
		std::cout << "Enter lower limit : " << std::endl;
		std::cin >> lowerLimit;
		std::cout << "Enter uppear limit : " << std::endl;
		std::cin >> uppearLimit;
		std::cout << "Enter number of segments : " << std::endl;
		std::cin >> n;

		if (lowerLimit < uppearLimit && n > 0)
			break;
		else
			std::cout << "Try again!" << std::endl;
	}

	while (fabs(previosIntegral - nextIntegral) > epsilon)
	{
		previosIntegral = Trapezoid(lowerLimit, uppearLimit, n);
		nextIntegral = Trapezoid(lowerLimit, uppearLimit, n);
		n *= 2;
	}

	std::cout << "(Trapezoid) : The value of integral = " << previosIntegral << std::endl;

	previosIntegral = 0;
	nextIntegral = 1;

	while (fabs(previosIntegral - nextIntegral) > epsilon)
	{
		previosIntegral = Simpson(lowerLimit, uppearLimit, n);
		nextIntegral = Simpson(lowerLimit, uppearLimit, n);
		n *= 2;
	}

	std::cout << "(Simpson) : The value of integral = " << previosIntegral << std::endl;

	system("pause");
    return 0;
}

