#include <iostream>
#include <string>
using namespace std;

class Laptop {
public:
	Laptop(const string& name, int tuoi, bool z = true): name(name), tuoitho(tuoi), con_zin(z) { }
	//trong 1 chương trình chuẩn họ phải dùng như này là khởi tạo kiểu initialization_list liệt kê tham số nhanh và gọn hơn
	//là explicit declaration; bên cạnh đó họ cũng dùng & nhiều nhất có thể để tránh copy tốn bộ nhớ, tốc độ nhanh hơn; Bên 
	//cạnh đó họ phải dùng const khi dùng với & vì đã dùng & thì họ cx k có nhu cầu đổi biến trong hàm => đủ 3 tiêu chuẩn này

	//tình trừu tượng, tùy ý ta cho phép như nào
	void va_zin() {
		if (tuoitho < 5) {
			con_zin = true;
		}
	}
	void show_zin() {
		cout << name << " " << (con_zin ? "con zin" : "khong con zin") << endl;
	}
private:
	bool con_zin;
	string name;
	int tuoitho;
};
class LightLaptop : public Laptop {
	//nếu kế thừa private thì mọi thứ của laptop đều k truy cập đc
public:
	LightLaptop(const string& name, int tuoi, bool z = true): Laptop(name, tuoi, z) { }
	void test() {
		cout << "LightLaptop" << endl;
	}
};
class DarkLaptop : public Laptop {
public:
	DarkLaptop(const string& name, int tuoi, bool z = true) : Laptop(name, tuoi, z) { }
	void test() {
		cout << "DarkLaptop" << endl;
	}
};

//đa kế thừa trong OOP. Ít dùng, có khả năng gây xung đột khi 2 class cùng 1 hàm. VD ở TH này nếu khởi tạo 1 instance của
//BrokenLaptop và gọi hàm test sẽ bị lỗi ambiguous mà phải khai báo thêm 1 hàm test ở class gốc BrokenLaptop mới được
class BrokenLaptop : public LightLaptop, public DarkLaptop {
public:
	BrokenLaptop(const string& name, int tuoi, bool z = true) : LightLaptop(name, tuoi, z), DarkLaptop(name, tuoi, z) { }
};

class base
{
public:
	int x;
protected:
	int y;
private:
	int z;
};
class publicDerived : public base
{
	// x có kiểu public
	// y có kiểu protected
	// z không thể được truy xuất từ publicDerived
};
class protectedDerived : protected base
{
	// x có kiểu protected
	// y có kiểu protected
	// z không thể được truy xuất từ protectedDerived
};
class privateDerived : private base
{
	// x có kiểu private
	// y có kiểu private
	// z không thể được truy xuất từ privateDerived
};
//Thực tế: kế thừa ta thường dùng public, chú còn protected và private không có nhiều ứng dụng thực tế
//Kiểu biến private thì các lớp con kbh truy xuất được, còn public thì các lớp con luôn truy xuất được. Nhưng thực tế
//theo tính đóng gói, các biến ta kbh để public, tức là luôn để private, nhưng nhiều thuộc tính lớp con kế thừa và ta 
//muốn lớp con cũng phải dùng được cơ nên ta dùng protected. Còn nếu lớp con cũng chỉ cần truy xuất qua get/set bị giới 
//hạn do ta muốn thì dùng private mãi cũng được

int main() 
{
	class Dan_ong {

	} *danong = new Dan_ong;
	delete danong;

	LightLaptop*laptop = new LightLaptop("Asus", 2, true);//tên class k viết hoa cx báo lỗi
	delete laptop;

	return 0;
}