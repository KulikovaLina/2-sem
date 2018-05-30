// Car.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Car.h"
#include <cstring>
#include <stdexcept>
#include <iostream>

Car::Car::Car(char * model, char * color, char * serialNumber, char * registrationNumber, int yearOfIssue, int yearOfInspection, int price)
{
	this->SetCar(model, color, serialNumber, registrationNumber, yearOfIssue, yearOfInspection, price);
}

CAR_API void Car::Car::SetModel(char * model)
{
	if (model == nullptr)
	{
		throw std::bad_alloc();
	}

	this->model = AllocateMemory(model);

	strcpy(this->model, model);
}

CAR_API void Car::Car::SetColor(char * color)
{
	if (color == nullptr)
	{
		throw std::bad_alloc();
	}

	this->model = AllocateMemory(color);

	strcpy(this->color, color);
}

CAR_API void Car::Car::SetSerialNumber(char * serialNumber)
{
	if (serialNumber == nullptr)
	{
		throw std::bad_alloc();
	}

	this->serialNumber = AllocateMemory(serialNumber);

	strcpy(this->serialNumber, serialNumber);
}

CAR_API void Car::Car::SetRegistrationNumber(char * registrationNumber)
{
	if (registrationNumber == nullptr)
	{
		throw std::bad_alloc();
	}

	this->registrationNumber = AllocateMemory(registrationNumber);

	strcpy(this->registrationNumber, registrationNumber);
}

CAR_API void Car::Car::SetYearOfIssue(int yearOfIssue)
{
	if (yearOfIssue <= 0)
	{
		throw std::invalid_argument("Year of issue can not be less or equal zero!");
	}

	this->yearOfIssue = yearOfIssue;
}

CAR_API void Car::Car::SetYearOfInspetion(int yearOfInspection)
{

	if (yearOfInspection <= 0)
	{
		throw std::invalid_argument("Year of inspection can not be less or equal zero!");
	}

	this->yearOfInspection = yearOfInspection;
}

CAR_API void Car::Car::SetPrice(int price)
{

	if (price <= 0)
	{
		throw std::invalid_argument("Price can not be less or equal zero!");
	}

	this->price = price;
}

CAR_API void Car::Car::SetCar(char * model, char * color, char * serialNumber, char * registrationNumber, int yearOfIssue, int yearOfInspection, int price)
{
	this->SetModel(model);
	this->SetColor(color);
	this->SetSerialNumber(serialNumber);
	this->SetRegistrationNumber(registrationNumber);
	this->SetYearOfIssue(yearOfIssue);
	this->SetYearOfInspetion(yearOfInspection);
	this->SetPrice(price);
}

CAR_API char * Car::Car::GetModel()
{
	return this->model;
}

CAR_API char * Car::Car::GetColor()
{
	return this->color;
}

CAR_API char * Car::Car::GetSerialNumber()
{
	return this->serialNumber;
}

CAR_API char * Car::Car::GetRegistrationNumber()
{
	return this->registrationNumber;
}

CAR_API int Car::Car::GetYearOfIssue()
{
	return this->yearOfIssue;
}

CAR_API int Car::Car::GetYearOfInspetion()
{
	return this->yearOfInspection;
}

CAR_API int Car::Car::GetPrice()
{
	return this->price;
}

CAR_API void Car::Car::EnterCar()
{
	const int N = 256;
	char model[N] = "";
	std::cout << "Enter the model of car:";
	std::cin.ignore();
	std::cin.getline(model, N, '\n');

	char color[N] = "";
	std::cout << "Enter the color of car:";
	std::cin.getline(color, N, '\n');

	char serialNumber[N] = "";
	std::cout << "Enter the serial number of car:";
	std::cin.getline(serialNumber, N, '\n');

	char registrationNumber[N] = "";
	std::cout << "Enter the registration number of car:";
	std::cin.getline(registrationNumber, N, '\n');

	int yearOfIssue;
	std::cout << "Enter the year of issue of car:";
	std::cin >> yearOfIssue;

	int yearOfInspection;
	std::cout << "Enter the year of inspection of car:";
	std::cin >> yearOfInspection;

	int price;
	std::cout << "Enter price of car:";
	std::cin >> price;

	this->SetCar(model, color, serialNumber, registrationNumber, yearOfIssue, yearOfInspection, price);

}

CAR_API void Car::Car::DisplayCar()
{
	std::cout << std::endl << this->model << " " << this->color << " " << this->serialNumber <<" " << this->registrationNumber << ", \t";
	std::cout.precision(3);
	std:: cout << this->yearOfIssue << " " << this->yearOfInspection << " " << this -> price << "  , \t";
}

char * Car::Car::AllocateMemory(char * ch)
{
	if (ch == nullptr)
	{
		throw std::bad_alloc();
	}

	return new char[strlen(ch) + 1];
}



