#pragma once//nên có ở mọi file header đỡ trùng
#ifndef CLASS_H
#define CLASS_H

extern int fix_v;

#include <iostream>

using namespace std;

__interface I {
	void f();
};
//công dụng của interface. Bên trong sẽ chứa 1 tập hợp các hàm ta chỉ định nghĩa chứ k khai báo. bát cứ lớp nào kế thừa cái \
interface này bắt buộc đều phải khai báo các hàm trong interface. Nếu k sẽ thành class ảo ngay lập tức. Interface sẽ biến cái hàm\
bên trong là tập hợp các virtual;có thể kết hợp vs override;nó giống kiểu 1 class hoàn toàn abstract nhưng có tc sau:có thể kế\
thừa từ interface khác,class kế thừa chỉ khai báo đc hàm trong public;ko đc vs hàm tạo, hủy và operator,static,data member;

template <class E>
class Person;

class Print;

template <class T>
void PrintOut(const Print&, const Person<int>&);
class Print
{
private:
	int number_;
public:
	Print() :number_{ 18 } {}

	template <class T>
	friend void PrintOut<int>(const Print&, const Person<int>&);
	void PrintPerson(const Person<int>& person);
};
//hàm bạn chỉ giúp ta ko phải dùng hàm get để truy cập và nếu là bạn nh lớp thì dùng mul biến multi class luôn
template <class T>
class Person
{
protected:
	Person(int a) :age_{ a }, con_value{ 5 }//khai báo có đổi số của base nhét vô protected
	{
		cout << "\tClass Base" << endl;
	}
public:
	const int con_value;
	int age_ = 0;
	Person() :con_value{ 5 } {}
	virtual ~Person()
	{
		cout << "Destrutor Person" << endl;
	}
	const int& Get_con_value() const { return con_value; }

	int& Get_age() { return age_; };
	const int& Get_age() const { return age_; }

	friend void PrintOut<int>(const Print&, const Person<T>&);
	friend class Print;
	void test_virtual()
	{
		cout << "Person test_virtual" << endl;
	}
};
template <class T>
class Student : public Person<T>
{
private:

public:
	int mark_;
	static int counter;
	Student(int a = 10, int b = 20) :mark_{ a }, Person<T>{ b }
	{
		cout << "\tStudent number " << counter << endl;
	}
	virtual ~Student()
	{
		cout << "Destructor Student" << endl;
	}
	virtual void test_virtual()
	{
		cout << "Student test_virtual" << endl;
	}
};
int Student<int>::counter = 0;

class Leader :public Student<int>//có thể kế thừa nh lớp thêm dấu phẩy là đc
{
private:
	int* account_;
public:
	int length_;
	int mark_final;
	Leader(int a = 10, int b = 10, int c = 10, int d = 10)
		:mark_final{ a }, Student{ b,c }, length_{ d }//cách hack bộ nhớ động, ko hiệu nghiệm với char
	{
		account_ = new int[length_] {};
		cout << "\tA leader is chosen" << endl;
	}
	~Leader()
	{
		cout << "Destructor Leader" << endl;
	}
	friend int operator>(const Leader& leader1, const Leader& leader2)//friend+operator
	{
		int a = 0;
		a = leader1.mark_final * 2 + leader2.mark_final;
		return a;
	}
	friend ostream& operator<<(ostream& out, const Leader& leader)//ostream +operator
	{
		out << leader.mark_final << " unit\n";
		return out;
	}
	int& operator[](const int& index)
	{
		return account_[index];
	}
	void test_virtual()
	{
		cout << "Leader test_virtual" << endl;
	}
	operator int()
	{
		return int(length_);
	}
	static void couthello();
};

template <class T>
T a(const T& leader1, const T& leader2)
{
	return ((leader1 > leader2 > 10) ? leader1 : leader2);
}
template <class T>
void PrintOut(const Print& print, const Person<int>& person)
{
	cout << print.number_ << " people " << person.age_ << " years old" << endl;
}

class Fruit
{
public:
	enum class FruitType//lồng using, lồng class khác cx đc(thà kế thừa còn hơn)
	{
		BANANA_,
		APPLE_,
		LEMON_,
	};
	FruitType Fruit_T;
};
class Vegetables//lớp cơ sở trừu tuong ko thể instantiate, vẫn gán cho phần veget của Apple đc 
{
public:
	int vget = 200;
	//virtual const char* speak() = 0;
	virtual const char* speak();
	virtual void Test_overr(int a) { cout << a << " H" << endl; }
};
class Apple :public Vegetables
{
public:
	int apple = 100;
	virtual const char* speak()//Nếu k ĐN cx thành lớp cơ sở trừu tượng
	{
		cout << "Endl";
		return Vegetables::speak();
	}
	void Test_overr(int a) override { cout << a << endl; }//overide chỉ ghi đè khi có hàm có virtual,tức có tính đa hình
	//hàm đa hình chỉ cần trùng tên và đối số vàoh
//tính đa hình: khi hai hàm trùng tên nhau+ta khai báo biến ở lớp kế thừa=>khi dùng sẽ vô hàm ở lớp kế thừa.đó là bth, còn bất bth\
//ở chỗ khi ta khai báo biến là phần cha của lớp kế thừa thì sẽ chạy vào hàm lớp cha ha, thêm virtual sẽ chạy vô lớp con.
};
void Print_veget(Vegetables* veget);
#endif