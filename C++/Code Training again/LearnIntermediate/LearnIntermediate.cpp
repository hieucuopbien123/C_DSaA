#include <iostream>
#include <sstream>
#include "./Header.h"
#include "./Hello.h"

using namespace std;

int main()
{
	string var1 = to_string(10);
	cout << var1 << endl;

	string var2 = "Hello world";
	const char* var3 = var2.data();
	cout << var3 << endl;
	var3 = var2.c_str();//dùng 1 hàm data() thôi
	cout << var3 << endl;

	//Cơ chế chia file: file main.cpp, file.h, file.cpp
	//File gọi include cũng giống như việc copy code vào file v.
	//Khi include 1 file.h và gọi 1 hàm hay 1 cái gì đó của file.h, nếu hàm đó k được khai báo body trong file.h
	//thì nó sẽ duyệt qua mọi file.cpp, file nào có hàm tương ứng thì sẽ tự include cả file cpp đó vào
	//=> Đó là tất cả. Thế câu hỏi đặt ra là file.cpp có được include file.h không
	//Được nhưng chú ý lỗi re-definition
	//VD: file main include file.h, xong file.cpp cũng include file.h nhưng trong file.h khai báo 1 biến int a;
	//Đầu tiên compiler compile file main và link các file cpp vào, bên trong cpp nó link thì lại có file.h
	//như v nó bị include 2 lần => redefinition. 
	//Điều này chỉ lỗi với kiểu biến global như v bởi vì bản chất biến global và biến cục bộ khi compiler chạy
	//tới sẽ thực thi, nếu lần sau lặp lại thì sẽ tiếp tục thực thi. Trong khi các biến extern, marco,
	//const, định nghĩa class thì khi compiler chạy tới sẽ thực thi và nếu vì lý do nào đó gặp lại, nó sẽ bỏ qua
	//như kiểu xóa phần code đó đi rồi ấy. Do đó phải chuyển sang static or extern mới được.
	//static nó y hệt global nhưng thay vì báo lỗi redefinition nó sẽ redefinition luôn, tạo ra nhiều biến global
	//trùng tên nhau, mỗi file 1 biến
	//Họ thường dùng kiểu: main.cpp include file h, file h định nghĩa mọi thứ, file.cpp include file.h và 
	//implement mọi thứ định nghĩa trong file.h => file h phải có marco trống implement nhiều lần
	c = 90;
	test();
	cout << a << " " << A << " " << b << " " << c << endl;

	return 0;
}