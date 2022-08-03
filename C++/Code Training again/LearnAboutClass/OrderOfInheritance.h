#pragma once
#ifndef CLASS_H2
#define CLASS_H2

#include <iostream>
using namespace std;

class Cha
{
protected:
	Cha() {
		cout << "Cha constructor" << endl;
	};
public:
	~Cha() {
		cout << "Cha destructor" << endl;
	}
};
class Con: public Cha
{
public:
	Con() {
		cout << "Con constructor" << endl;
	}
	~Con() {
		cout << "Con destructor" << endl;
	}
};

#endif // !CLASS_H2
