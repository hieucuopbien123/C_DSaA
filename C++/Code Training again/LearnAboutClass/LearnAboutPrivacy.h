#pragma once
#ifndef CLASS_H
#define CLASS_H

#include <iostream>
using namespace std;

class LearnPrivacy
{
	int defaultVarIsPrivate;
private:
	int pivVar;
protected:
	int proVar;
public:
	LearnPrivacy(int a, int b, int c) : pivVar(1), proVar(2), defaultVarIsPrivate(3) {};
};
class SubLearnPrivacy: public LearnPrivacy
{
public:
	SubLearnPrivacy() : LearnPrivacy{ 1, 2, 3 } {};
	void printAll() {
		cout << proVar << endl;
	}
};

#endif // !CLASS_H
