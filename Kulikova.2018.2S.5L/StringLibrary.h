#pragma once

#ifdef StringLibrary_EXPORTS
#define STRINGLIBRARY_API __declspec(dllexport) 
#else
#define STRINGLIBRARY_API __declspec(dllimport) 
#endif

namespace String
{ 
	bool CompareWords(char **, char*, int);
	char ** ObtainWords(char *, int&);
	void DisplayWords(char **, int);
	void FreeMemory(char **, int);
}