#pragma once

#include "Header.h"

class testError
{
public:
	testError();
	int getError() { return error; }
	void setError(int e) { error = e; };
	
	int teststatic;

	int testextern;

	static int error2;
private:
	static int error;
};
