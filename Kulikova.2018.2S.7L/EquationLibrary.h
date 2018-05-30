#pragma once

#ifdef EquationLibrary_EXPORTS
#define EQUATIONLIBRARY_API __declspec(dllexport) 
#else
#define EQUATIONLIBRARY_API __declspec(dllimport) 
#endif

namespace Equation
{
	EQUATIONLIBRARY_API double NewtonMethod(double, double, double);
	EQUATIONLIBRARY_API double ModifiedMethodOfSecans(double, double, double);
	EQUATIONLIBRARY_API double Function(double, double);
	EQUATIONLIBRARY_API double Derivative(double, double);
	EQUATIONLIBRARY_API double TwoDerivative(double);
}