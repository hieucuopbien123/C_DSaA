#pragma once
#ifndef CLASS_H5
#define CLASS_H5

#include <iostream>
using namespace std;

class Computer {
public:
	virtual void Model() {
		cout << "Computer" << endl;
	}
};
class Macbook : public Computer
{
public:
	void Model() override {//override có or not đều đc
		cout << "Macbook" << endl;
	}
};

#endif // !CLASS_H5