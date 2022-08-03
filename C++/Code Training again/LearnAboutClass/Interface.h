#pragma once
#ifndef CLASS_H4
#define CLASS_H4

#include <iostream>
using namespace std;

__interface I {
};
__interface ITest: public I {
	void func1(int a);
};
class TestInterface : public ITest {
public:
	void func1(int a) {
		cout << a << endl;
	};
};

class InterfaceClass {
private:
	int a;
public:
	InterfaceClass() : a(1) {};
	virtual void func1() = 0;
	void func2() {
		cout << a << endl;
	}
};
class ImplementInterface : public InterfaceClass {
public:
	void func1() {
		cout << "Call interface implementation function" << endl;
	}
};
//interface và abstract class khác nhau: 2 TH trên đều là interface Th1 hiển nhiên còn Th2 khi class có 1 pure
//virtual function(cái function = 0) thì nó là interface. 1 interface k thể khai báo 1 instance được mà phải thông
//qua implementation của nó để thực thi hàm
//class kế thừa từ interface buộc phải define mọi hàm trong interface. Còn abstract class thì không cần vì
//class kế thừa abstract class nếu k define hàm virtual của nó thì sẽ tự gọi vào hàm của abstract class nên k bắt
//buộc phải define mọi hàm trong abstract class
//interface dùng theo kiểu muốn thêm function nào vào class thì tạo ra interface các function đó và cho class kế 
//thừa interface và implement các function đó, xác định các function bổ sung tính năng
//abstract class thường dùng theo kiểu 2 class A và B có các hàm y hệt như nhau và hiểu rằng A is B. VD class 
//SonyTivi kế thừa class BaseTivi là abstract class => các hàm của BaseTivi mà SonyTivi k có sẽ gọi trong BaseTivi, 
//còn SonyTivi mà có thì gọi trong đúng nó thôi.
//Nghe chừng abstract class có vẻ giống kế thừa bình thường nhưng kp vì kế thừa bth Con kế thừa Cha, còn abstract
//class thường kế thừa kiểu, Con kế thừa ConNguoi thì hợp lý hơn. Khi đó ta dùng 'virtual' và 'override' để xử lý.

#endif // !CLASS_H4