// IntegralLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "IntegralLibrary.h"
#include <cmath>

INTEGRALLIBRARY_API double Integral::Trapezoid(double lowerLimit, double uppearLimit, unsigned n)
{
	double step = (uppearLimit - lowerLimit) / n;
	double integral = SinExp(lowerLimit) + SinExp(uppearLimit);
	double t = lowerLimit + step;

	while (t < uppearLimit)
	{
		integral += 2 * SinExp(t);
		t += step;
	}

	return (integral * step / 2);
}

INTEGRALLIBRARY_API double Integral::Simpson(double lowerLimit, double uppearLimit, double n)
{
	double step = (uppearLimit - lowerLimit) / n;
	double integral = SinExp(lowerLimit) + SinExp(uppearLimit);
	double t = lowerLimit + step;
	
	while (t < uppearLimit)
	{
		integral += 4 * SinExp(t);
		t += step;
	}

	t = lowerLimit + 2 * step;

	while (t < uppearLimit - 1)
	{
		integral += 2 * SinExp(t);
		t += step;
	}

	return (integral * step / 3);
}

INTEGRALLIBRARY_API double Integral::SinExp(double x)
{
	return sin(x*x);
}
