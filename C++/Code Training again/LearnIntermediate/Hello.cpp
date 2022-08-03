#include "Header.h"
#include <iostream>
using namespace std;

int b = 10;//riêng extern phải định nghĩa thêm như này dù đã include nó => sai, do chưa include nên ms phải include\
các file chưa include phải include như này
void test() {
	cout << a << " " << A << " " << b << " " << c << endl;
}