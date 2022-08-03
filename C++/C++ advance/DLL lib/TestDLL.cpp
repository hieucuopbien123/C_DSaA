// MathClient.cpp : Client app for MathLibrary DLL.
// #include "pch.h" Uncomment for Visual Studio 2017 and earlier
#include <iostream>
#include <conio.h>
#include "MathLib.h"

using namespace std;

int main()
{
    int a[10] {};
    int b = 10;
    inputArray(a, b);
    cout << endl;
    outputArray(a, b);
    
    return 0;
}