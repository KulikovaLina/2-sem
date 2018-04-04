#pragma once

#ifdef IntegralLibrary_EXPORTS
#define INTEGRALLIBRARY_API __declspec(dllexport) 
#else
#define INTEGRALLIBRARY_API __declspec(dllimport) 
#endif

namespace Integral
{
	INTEGRALLIBRARY_API typedef double(*IntegralFunction) (double);
	INTEGRALLIBRARY_API typedef double(*QuadratureFormula) (double, double, int, IntegralFunction);
	INTEGRALLIBRARY_API double SinExp(double);
	INTEGRALLIBRARY_API double TrapezoidalRule(double, double, int, IntegralFunction);
    INTEGRALLIBRARY_API double RuleOfSimpson(double, double, int, IntegralFunction);
	INTEGRALLIBRARY_API double DoubleConverting(double, double, double, int, IntegralFunction, QuadratureFormula);
}