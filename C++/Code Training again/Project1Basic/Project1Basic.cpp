#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

void test(int& a) {
	a = 1;
}

class Cha {
public:
	int cha;
	Cha(int a) : cha{ a } {};
	virtual void test() {
		cout << "Cha" << endl;
	}
	virtual ~Cha() {
		cout << "Cha huy" << endl;
	}
};
class Con: public Cha {
public:
	int con;
	Con(int a) : con{ a }, Cha {a+1} {};
	Con(Con& con) : Cha{1} {//định nghĩa lại copy constructor
		this->con = con.con;
	}
	void test() {
		cout << "Con" << endl;
	}
	~Con() {
		cout << "Con huy" << endl;
	}
};

int main()
{
	int* v1 = new int(1);
	int* v2 = v1;
	delete v1;//vẫn dùng được v2
	//khi ta xóa 1 biến con trỏ về bản chất là ta trả lại quyền kiểm soát biến đó cho hệ điều hành chứ 
	//k trả lại dịa chỉ vùng nhớ. 1 số compiler sẽ trỏ con trỏ đó đến 1 vùng nhớ rác khác, có cái giữ
	//nguyên vùng nhớ cũ nhưng v1 thì luôn k dùng được nx, còn v2 thì có. Đây là TH đặc biệt mà người ta
	//ít gặp vì kbh lại gán 2 biến vào cùng 1 con trỏ làm gì. Điều này k đúng khi truyền hàm vì hàm thì
	//là chính nó luôn

	//tham chiếu của 1 biến a bình thường cũng chỉ là 1 con trỏ như bình thường ta biết, điểm khác biệt
	//duy nhất là kp xp từ cấp phát động

	int* v3 = new int[10]();//cấp phát động mảng 10 giá trị 0
	int** v4 = new int*[10];//cấp phát động 1 mảng 10 phần tử, và mỗi phần tử bên trong là 1 int*
    for(int i = 0 ; i < 10; i++){
        v4[i] = new int[10];
	}
	for (int i = 0; i < 10; i++){
	    delete[] v4[i];
	}	
    delete[] v4;

	//1 cái cấp phát động, 1 cái cấp phát tĩnh. 
	//Khi cấp phát động ta có thể truyền vào hàm kiểu copy or truyền dùng chính nó
	//Khi cấp phát tĩnh ta cũng có thể truyền vào hàm kiểu copy or truyền dùng chính nó
	int v5 = 10;
	test(v5);
	cout << v5 << endl;

	int& v6 = v5;
	v5 = 2;
	cout << v6 << endl;

	Cha* cha{ new Con(10)};
	cha->test();
	delete cha;
	//Th cấp phát động như này nếu k có virtual sẽ rò rỉ bộ nhớ ở con. Nó chỉ đúng khi lấy con từ cha như này

	return 0;
}
