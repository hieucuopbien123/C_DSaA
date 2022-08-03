#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include <ctime>
#include <random>
#include <iomanip>

using namespace std;

class Ong {
};

inline void Hello() {
	cout << "hello" << endl;
}

template<typename T>
void Test(T a) {
	cout << a << endl;
}

int Test0() {
	return 100;
}
void Test1(int&& a) {

}

void Test2(int&& a) {
	cout << a++ << endl;
}

class Mutable
{
	mutable int a;
	int b;
public:
	Mutable(int _a, int _b) :a(_a), b(_b) {};
	void fun() const //fun là hàm const không thể sửa đổi dữ liệu của đối tượng lớp, nhưng vì a được sửa đổi bởi mutable, nó có thể được sửa đổi, nhưng không thể sửa đổi B.
	{
		a += b;
	}
	void print()
	{
		cout << a << "," << b << endl;
	}
};

extern "C" {
	#include "stdio.h"
	void cFunction() {
		printf("hello");
	}
}

int main()
{
	//cFunction();

	//Mutable a(1, 2);
	//a.fun();
	//a.print();

	//cout << unsigned int(-25) << endl;

	//int a[] = { 1,2,3 };
	//int* b = new int[3];
	//memcpy(b, a, sizeof(a));
	//cout << (b[1]) << endl;
	//
	//char name[] = "Hello World";
	//char name_copy[100] = {};
	//strcpy_s(name_copy, name);
	//cout << name_copy << endl;

	//int a = 10;
	//Test2(move(a));
	//Test2(move(10));
	//cout << a;

	//int* a = new int(8);
	//int* b = a;
	//delete a;
	//*b = 1;
	//cout << *b << endl;

	//Test(1);

	//int a = 2;
	//int& b = a;
	//b = 4;
	//cout << a << endl;

	//int&& c = 2;//ảo thật đấy

	//Test1(Test0());

	//mt19937 random_engine(time(NULL));
	//uniform_int_distribution<int> distribution(1, 100);
	//cout << distribution(random_engine)%50 << endl;

	//uniform_real_distribution<float> float_distribution(1, 100);
	//cout << setprecision(6) << float_distribution(random_engine) << "\n";

	//Hello();

	//int* intsao1 = new int(8);
	//int* intsao2 = new int[8]{};
	//int** intsao3 = new int*[8]{};

	//fstream file1;
	//file1.open("text.txt", ios::out);
	//if (!file1.is_open()) {
	//	cerr << "Cannot open file" << endl;
	//	return -1;
	//}
	////file1.write("Hello\nWorld!!!", 15);
	//const char* constchar2 = "Hello\nWorld!!!";
	//file1 << constchar2;
	//file1.put('a');
	//file1.close();

	//fstream file2;
	//file2.open("text.txt", ios::in);
	//if (!file2.is_open()) {
	//	cerr << "Cannot open file" << endl;
	//	return -1;
	//}
	//char text[100] = {};
	//cout << (char)file2.get() << endl;
	//cout << file2.tellg() << " " << file2.tellp() << endl;
	//file2.seekg(0, ios::beg);
	//while (file2 >> text) {
	//	cout << text << endl;
	//}
	////đọc hết r thì k seek để dịch được
	//cout << file2.eof() << endl;
	//file2.close();

	//int int1 = 68;
	//cout << static_cast<char>(int1) << endl;

	//const char* constchar1 = "Hello";
	//char* char5 = const_cast<char*>(constchar1);
	//cout << char5 << endl;

	//Ong ong1;
	//Ong* a = dynamic_cast<Ong*>(&ong1);

	//rewind(stdin);

	//char char3[100] = "Hello World!!";
	//const char* char2 = "Hello World";
	//cout << char2 << endl;
	//cout << char3 << endl;

	//char char1 = cin.get();
	//cout << char1 << endl;

	//string string1;
	//getline(cin, string1);
	//cout << string1 << endl;

	return 0;
}