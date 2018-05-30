#pragma once

#ifdef StringLibrary_EXPORTS
#define STRINGLIBRARY_API __declspec(dllexport) 
#else
#define STRINGLIBRARY_API __declspec(dllimport) 
#endif

namespace String
{
	STRINGLIBRARY_API char ** ObtainWords(char *, int&);
	STRINGLIBRARY_API char toUppear(char);
	STRINGLIBRARY_API void DisplayWords(char **, int);
	STRINGLIBRARY_API void FreeHeap(char **, int);
}
