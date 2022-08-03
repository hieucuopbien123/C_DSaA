#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "MathLib.h"
#include <iostream>

void inputArray(int* a,int &size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "Input a[" << i + 1 << "] = ";
		std::cin >> a[i];
	}
}
void outputArray(int* a, int& size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "Input a[" << i + 1 << "] = " << a[i] << "\n";
	}
}