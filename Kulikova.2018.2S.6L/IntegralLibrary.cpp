// IntegralLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "IntegralLibrary.h"
#include <cmath>

INTEGRALLIBRARY_API double Integral::SinExp(double x)
{
	return sin(x * x);
}

INTEGRALLIBRARY_API double Integral::TrapezoidalRule(double lowerLimit, double upperLimit, int number, IntegralFunction F)
{
	double step = (upperLimit - lowerLimit) / number;
	double result = F(lowerLimit);

	for (int i = 1; i < number; i++)
	{
		result += 2 * F(lowerLimit + i * step);
	}

	result += F(upperLimit);

	return (result * step / 2);
}

INTEGRALLIBRARY_API double Integral::RuleOfSimpson(double lowerLimit , double upperLimit, int number, IntegralFunction F)
{
	double step = (upperLimit - lowerLimit) / number;
	double result = F(lowerLimit);

	for (int i = 2; i < number - 1; i++)
	{
		result += 2 * F(lowerLimit + i * step);
	}

	for (int i = 1; i < number; i++)
	{
		result += 4 * F(lowerLimit + i * step);
	}

	result += F(upperLimit);

	return (result * step / 3);
}

INTEGRALLIBRARY_API double Integral::DoubleConverting(double beginSegm, double endSegm, double epsilon , int number, IntegralFunction F, QuadratureFormula Q)
{
	double previosIntegral = 0, nextIntegral = 0;

	do
	{
		previosIntegral = Q(beginSegm, endSegm, number, F);
		nextIntegral = Q(beginSegm, endSegm, number * 2, F);
		number *= 2;
	} 
	while (fabs(previosIntegral - nextIntegral) > epsilon);
	
	return nextIntegral;
}
