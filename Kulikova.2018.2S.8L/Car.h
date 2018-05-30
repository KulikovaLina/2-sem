#pragma once

#ifdef Car_EXPORTS
#define CAR_API __declspec(dllexport) 
#else
#define CAR_API __declspec(dllimport) 
#endif

namespace Car
{
	struct Car
	{
	public:
		CAR_API Car() {};
		CAR_API Car(char*, char*, char*, char*, int, int, int);
		CAR_API ~Car();
		CAR_API void SetModel(char*);
		CAR_API void SetColor(char*);
		CAR_API void SetSerialNumber(char*);
		CAR_API void SetRegistrationNumber(char*);
		CAR_API void SetYearOfIssue(int);
		CAR_API void SetYearOfInspetion(int);
		CAR_API void SetPrice(int);
		CAR_API void SetCar(char*, char*, char*, char*, int, int, int);
		CAR_API char* GetModel();
		CAR_API char* GetColor();
		CAR_API char* GetSerialNumber();
		CAR_API char* GetRegistrationNumber();
		CAR_API int GetYearOfIssue();
		CAR_API int GetYearOfInspetion();
		CAR_API int GetPrice();
		CAR_API void EnterCar();
		CAR_API void DisplayCar();

	private:
		char * model;
		char * color;
		char * serialNumber;
		char * registrationNumber;
		int yearOfIssue;
		int yearOfInspection;
		int price;

		char* AllocateMemory(char*);
	};
}