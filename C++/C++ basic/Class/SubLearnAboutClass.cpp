#include "LearnAboutClass.h"

void Print::PrintPerson(const Person<int>& person)
{
	cout << person.age_ << endl;
}
const char* Vegetables::speak()
{
	return "buzz"; //ko cho đúng file sẽ lỗi
}
void Print_veget(Vegetables* veget)//điểm lợi là truyền vào loại rau củ j cx ok, ta cứ đối số lớp base r ép ra lớp con
{
	if (Apple* ap = dynamic_cast<Apple*>(veget))//gán = tức nếu gán thành công
	{
		cout << veget->speak() << endl;
	}
}
void Leader::couthello()
//Phương thức tĩnh(hàm static trong 1 class khi dịnh nghĩa thì k cần từ khóa static nx)
//Nó k thể dùng các thuộc tính của lớp=> chẳng khác gì 1 hàm bth cả; ta có thể dùng nó với điều kiện có chỉ thị tiền xử lí\
của class mà k cần gọi 1 biến đối tượng class=> làm như v có tác dụng gom các hàm có chung 1 đặc điểm nào đó vào 1 class và tránh đc TH trùng tên do có ::
{
	cout << "Hello" << endl;
}