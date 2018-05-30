// EquationLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "EquationLibrary.h"
#include <cmath>

EQUATIONLIBRARY_API double Equation::NewtonMethod(double previous, double epsilon, double a)
{
	double following = previous - Function(previous, a) / Derivative(previous, a);

	while (fabs(previous - following) >= epsilon)
	{
		previous = following;
		following = previous - Function(previous, a) / Derivative(previous, a);
	}

	return following;
}

EQUATIONLIBRARY_API double Equation::ModifiedMethodOfSecans(double previous, double epsilon, double a)
{
	double following = 0;
	if (Function(a, a) * TwoDerivative(previous) > 0)
	{
		double following = previous - (previous - a) * Function(previous, a) / (Function(previous, a) - Function(a, a));
	}

	while (fabs(previous - following) >= epsilon && Function(a, a) * TwoDerivative(previous) > 0)
	{
		previous = following;
		following = previous - (previous - a) * Function(previous, a) / (Function(previous, a) - Function(a, a));

	}

	return following;
}

EQUATIONLIBRARY_API double Equation::Function(double x, double a)
{
	return (a * x - log(x) - 5);
}

EQUATIONLIBRARY_API double Equation::Derivative(double x, double a)
{
	return (a - 1 / x);
}

EQUATIONLIBRARY_API double Equation::TwoDerivative(double x)
{
	return (1 / x / x);
}
