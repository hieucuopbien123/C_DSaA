#include <iostream>
#include "./OrderOfInheritance.h"
#include "./Friend.h"
#include "./Interface.h"
#include "./AbstractClass.h"
#include "./StaticInClass.h"
#include "./OperatorAndEnum.h"
#include "./Casting.h"

using namespace std;

int main()
{
	Con2 con2;
	Cha2* cha2 = dynamic_cast<Cha2*>(&con2);
	cha2->intCha = 11;
	cout << con2.intCha << endl;

	Cha2 cha3;
	Con2* con3 = reinterpret_cast<Con2*>(&cha3);
	cout << con3->intCon << endl;

	EnumClass enumclass1;
	EnumClass::RANK rank1 = enumclass1[1];
	cout << static_cast<int>(rank1) << endl;
	//ta k thể in ra kiểu EnumClass::RANK được mà phải cast sang int
	int intVar1 = enumclass1;//operator cast int()
	cout << intVar1 << endl;
	cout << enumclass1 << endl;//nếu k có operator << thì nó hiểu là int() rồi in giá trị int ra
	EnumClass enumclass2;
	int intVar2 = enumclass1 + enumclass2;
	cout << "Val: " << intVar2 << endl;

	int intVar3 = enumclass2 - enumclass1;
	cout << intVar3 << endl;

	cout << TestStatic::staticVar << endl;
	TestStatic::staticFunc();

	Computer* comp = new Macbook();
	comp->Model();
	//Khi dùng abstract class thì 2 class thường giống hệt nhau(đó là usecase của abstract class) nên ta thg lấy
	//như này. Các hàm có virtual tức là gọi vào các hàm implement nó ở sau

	TestInterface t1;
	t1.func1(1);

	A a1;
	B b1;
	PrintAll(a1, b1);

	Con con1;

	return 0;
}