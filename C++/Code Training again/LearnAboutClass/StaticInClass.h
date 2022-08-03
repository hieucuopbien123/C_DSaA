#pragma once
#ifndef CLASS_H6
#define CLASS_H6

#include <iostream>

class TestStatic {
public:
	static int staticVar;
	static void staticFunc();
};
int TestStatic::staticVar = 10;
void TestStatic::staticFunc() {
	std::cout << "Call static function" << endl;;
}

#endif CLASS_H6