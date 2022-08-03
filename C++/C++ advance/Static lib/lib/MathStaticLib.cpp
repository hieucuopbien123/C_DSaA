#include "pch.h"
#include "framework.h"
#include "MathStaticLib.h"
//daynhauhoc và cái trang chủ doc microsoft có hướng dẫn, tĩnh thì trang thứ nhất, dộng trang thứ 2
namespace MathLibrary
{
    double Arithmetic::Add(double a, double b)
    {
        return a + b;
    }

    double Arithmetic::Subtract(double a, double b)
    {
        return a - b;
    }

    double Arithmetic::Multiply(double a, double b)
    {
        return a * b;
    }

    double Arithmetic::Divide(double a, double b)
    {
        return a / b;
    }
}
