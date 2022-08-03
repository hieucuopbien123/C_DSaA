#include <iostream>
#include <conio.h>
#include "LearnAboutClass.h"

using namespace std;

int main()
{	
	Leader leader1{ 5 };
	cout << leader1.age_ << " " << leader1.mark_ << endl;

	const Person<int> person{};
	person.Get_age();

	Person<int> person2{};
	person2.Get_age() = 5;
	cout << person2.age_ << endl;
	//một điểm hay khi dùng tham chiếu ở Get_age là nó dùng chung địa chỉ với age nên gán đc cho age_ bằng copy initialization
	//lúc đầu ta thắc mắc tại sao age_ ko là biến hằng nhưng nạp chồng hàm Get_age với const lại đc là vì khai báo 2 kiểu Person có const
	//và k có const.

	Print print;
	PrintOut<int>(print, person2);
	print.PrintPerson(person2);

	Leader leader2{ 10 };
	cout << a(leader1, leader2).mark_final << " " << leader1 << endl;

	//	Leader leader3{ leader2 };Leader leader4; Leader4 = leader2; deleted function đã cản trở vc gán dù bth ta gán đc nv
	int number = 0;
	cout << "Insert number of array: "; cin >> number;
	Leader leader5;
	leader5.length_ = number;
	for (int i = 0; i < number; i++)
	{
		cout << leader5[i] << endl;
	}

	Fruit Apple_;
	Apple_.Fruit_T = Fruit::FruitType::APPLE_;
	cout << static_cast<int>(Fruit::FruitType::APPLE_) << static_cast<int>(Apple_.Fruit_T) << endl;

	Leader leader;
	Student<int>& student{ leader };
	Student<int>* student5{ new Leader{} };
	//khai báo student mà k gán cụ thể vs 1 leader nào đó+k có virtual thì chẳng khác j bth vì k có biến leader cx chả có virtual leader
	Person<int>* person1{ &leader };//làm éo có new mà delete, nếu delete lỗi delete leader
	cout << student.counter << endl;
	student.test_virtual();
	person1->test_virtual();//ko muốn xuất ở student thì chỉ cần student có virtual là đc r. Nhưng cứ virtual hết để phân biệt
	student5->test_virtual(); cout << endl;
	student5->Student::test_virtual(); cout << endl;

	delete student5;//tạo con trỏ ko tự xóa, delete thực chất sẽ đi vào destructor.Khi đi vào destructor thì nó chỉ delete
//student, nếu leader có con trỏ new int thì thành rò rỉ, còn nếu có virtual thì sẽ delete hoàn toàn cả Leader. 
//Do đó với lớp kế thừa nên luôn có virtual ở destructor

//occho: tại sao xóa mỗi leader thì student và person sẽ tự xóa sau đó? Vì nó dùng chung trong ô nhớ với leader(chỉ cần xóa con)
//với các hàm thành viên thông thường(ví dụ destructor) thì ko cần tạo tất cả chỉ để khai báo ảo hay k. Vì chỉ cần lớp cha là
//ảo thì các lớp còn cx ảo.Ko dùng hàm gán ảo vì sẽ có biến

	Leader leader10;
	Person<int>& person10{ leader10 };
	
	Apple apple;
	cout << apple.speak() << endl;

	Apple appl;
	cout << dynamic_cast<Vegetables*>(&appl)->vget << endl;
//nó ép con về cha thôi, các thành phần lớp con khác biến mất, chỉ đc với con trỏ or tham chiếu lớp
//nó chỉ ép đc từ cha về con khi bản chất nó là con xog vì lý do j đó biến thành cha+cha có tính đa hình
//dynamic cast nó k cấp vùng nhớ mới mà nó sẽ dùng chung vùng nhớ vs cái cũ, nên dynamic là thao tác vs chính nó
	Apple* apple_VN = new Apple;
	Print_veget(apple_VN);
//tối ưu con trỏ hết mức có thể. new int chỉ khi dùng giá trị. còn dùng địa chỉ gán+khai báo đồng thời luôn
	delete apple_VN;

	Vegetables veget;
//static_cast<apple*>(&veget)->apple = 59; ăn lỗi stack was corrupt. Ta ko nên gán cho static mà chỉ nên dùng bởi vì kiểu 
//dữ liệu to quá sẽ bị lỗi, do đó static_cast cho lớp cha thành con và const_cast hiếm khi dùng
	cout << static_cast<Apple*>(&veget)->apple << endl;
//static từ cha sang con đc và nếu chưa có vùng nhớ sẽ cấp phát.1 đối tượng chỉ đc cấp phát 1 lần cho tất cả các kiểu case.GT
//của mọi biến trong vùng nhớ ms sẽ như nhau và rác.khi cấp phát thì auto ra GT rác ko sửa đc, nhưng nếu biến là const thì vẫn dùng đc
	cout << reinterpret_cast<Person<int>*>(&veget)->con_value << endl;//con_value =200 là GT của vget=> k nên cast kiểu này

//cast luon đi với con trỏ nên const_cast ít dùng
	const char* concha{ "sample text" };
//const char* buộc khai báo ngay phần tử cho nên là ta khai báo luôn cx ok
//nếu chỉ là char* thì khai báo chuỗi ngay thì phải có [] vô, còn ko có [] chỉ có nghĩa khai báo 1 phần tử
	cout << const_cast<char*>(concha) << endl;//vô dụng
	char* conchachangeable = const_cast<char*>(concha);//gán const thành k const
	conchachangeable[1] = 'U';
	cout << typeid(concha).name() << endl;

	Leader::couthello();

	_getch();
	return 0;
}


