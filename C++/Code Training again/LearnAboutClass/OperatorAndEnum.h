#pragma once
#ifndef CLASS_H7
#define CLASS_H7

#include <iostream>
using namespace std;

class EnumClass {
public:
	enum class RANK {
		SIlVER,
		GOLD,
		DIAMOND
	};
	EnumClass() : intVar(9), arrayVar{RANK::SIlVER, RANK::DIAMOND} {};
	RANK arrayVar[100];
	RANK& operator[](const int& index) {
		return arrayVar[index];
	}
	int intVar;
	operator int() {
		return 18;
	}

	friend ostream& operator<<(ostream& out, EnumClass& data);
	friend int& operator+(EnumClass& a, EnumClass& b) {
		int temp = a.intVar + b.intVar;
		return temp;//phải return lvalue trong operator
	}
	
	int operator-(EnumClass& a);
};
int EnumClass::operator-(EnumClass& a) {
	int b = this->intVar + a.intVar + 1;
	return b;
	//Đây là a@a thì nếu return this sẽ ra pointer trả lại vào cái a bên trái
}
ostream& operator<<(ostream& out, EnumClass& data) {
	out << "Friend: " << data.intVar;
	return out;
}
//Tại sao có operator k là friend, có operator buộc là friend
//Ta có thể overload operator thoải mái trong C++ hầu hết mọi toán từ nhưng cần chú ý dạng toán tử là: a@b, a@,
//@a, a@a thì có thể có 2 tham số truyền vào operator or 1 tham số. TH có 2 tham số phải dùng hàm friend chứ
//với 2 tham số khác nhau a@b

#endif // !CLASS_H7