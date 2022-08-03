#pragma once
#ifndef CLASS_H3
#define CLASS_H3

#include <iostream>
using namespace std;

class B;//Chú ý
class A {
private:
	int pivVar;
public:
	A() : pivVar(1) {};
	friend void PrintAll(A a, B b);
};
class B {
private:
	int pivVar;
public:
	B() : pivVar(2) {};
	friend void PrintAll(A a, B b);

	friend class C;
};
void PrintAll(A a, B b) {
	cout << a.pivVar << " " << b.pivVar << endl;
}

class C {
public:
	void printPivVarOfB(B b) {
		cout << b.pivVar << endl;
	}
};

#endif // !CLASS_H3