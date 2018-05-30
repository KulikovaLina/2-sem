#pragma once

#ifdef IntegralLibrary_EXPORTS
#define INTEGRALLIBRARY_API __declspec(dllexport) 
#else
#define INTEGRALLIBRARY_API __declspec(dllimport) 
#endif

namespace Integral
{
	INTEGRALLIBRARY_API double Trapezoid(double, double, unsigned);
	INTEGRALLIBRARY_API double Simpson(double, double, double);
	INTEGRALLIBRARY_API double SinExp(double);
}