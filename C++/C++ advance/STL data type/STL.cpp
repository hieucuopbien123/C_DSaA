#include <iostream>
/*#include <utility>
#include <conio.h>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <windows.h>//messagebox
*/
using namespace std;
/*
#define END << "\n";

bool value_less_100(const int* value) { return *value < 100; }
*/
int main()
{   
	//pair and map
	/*pair<string,string> initPair("0", "a");//pair như phần tử của map 
	pair<string, string> copyPair(initPair);
	cout << initPair.first << initPair.second END
    
	map<string, string> dictionary;
	dictionary["eat"] = "an";
	dictionary["sleep"] = "ngu";
	//khởi tạo copy
	map<string, string> dictionary1(dictionary.begin(), dictionary.end());
	map<string, string> dictionay3(dictionary1);
	//gán
	dictionay3 = dictionary;
	map<int,const char*> map0, map1;//ta dùng const char * thì ms gán cho giá trị "" TT đc 
	map0[0] = "a";
	map0[1] = "b";
	map1 = map0;
	map<int, const char*>::iterator it = map0.begin();
//đặc biệt con trỏ iterator của map nó k cout << * đc vì nó mang 2 GT, ta phải dùng first second
//cx ko dùng đc các phép cộng trừ VD it+=1 là sai
	for (it = map0.begin(); it != map0.end(); it++)
	{
		cout << it->first << "- " << it->second END
	}
	cout << map0.size() END
	if (map0.empty())
	{
		cout << "map0 is empty " END
	}
	cout << dictionary.at("eat") << " " << dictionary["eat"] END
//tương tự các hàm của iterator nhưng do có 2 đối số nên khác
    //insert có 3 loại đối số.
    map0.insert(map1.begin(),map1.end());//đối sô iterator, chèn vào cuối từ đâu đến đâu
	map0.insert(map0.begin(), pair<int, const char*>(4, "insert"));//or đơn giản{,} cx đc
	

//gán 1 phần tử vào VT nào VT nào. Nếu bỏ đối số đầu thì chèn mặc định vào VT đầu
	//hàm find trong vector, array,string như nhau nhưng ở map có thêm chấm . tìm theo key
	map<int,const char*>::iterator var = map0.find(5);//ko thấy return map0.end()
	map1.clear();
	//erase
	map0.erase(1); //xóa theo key
	map0.erase(var);//truyen iterator 
	map0.erase(var,map0.end()); //xoa tu dau den dau, truyền iterator
//map thì các phần tử xếp theo thứ tự sắp xếp. nêu xét từ đâu đến đâu thì dùng iterator, 1 VT thì dùng int
    */
	//list ko có at như vector
	/*list<int> list_data;
	list_data.assign(5,100);
	//list is special than vector
	list_data.push_back(100);
	list_data.push_front(90); 
	list_data.pop_back();
	list_data.pop_front();
	list_data.emplace_front(70);
	list_data.emplace_back(200);
	int value1 = list_data.front();
	int value2 = list_data.back();
	int size = list_data.size();
	bool is_empty = list_data.empty();
	list<int>::iterator iValue = list_data.begin();
	for (iValue = list_data.begin(); iValue != list_data.end(); iValue++)
		cout << *iValue << " ";
//list doesnt have an index for each value, so we can only access to each element through iterator
	list_data.remove(100);//remove every value 100 in list
	list_data.remove_if(value_less_100);
//transmit only bool function we can create, bool function have argument with the same type as list<>
//erase chỉ truyền vào iterator TT xóa 1 phần tử or xóa từ đâu đến đâu
	list_data.clear();
*/
	//stack
	/*stack<int> stackData;
	stackData.push(0);
	stackData.push(1);
	stackData.push(2);
	int size = stackData.size();
	stackData.pop();
	bool is_empty = stackData.empty();
	while (!stackData.empty())
	{
		cout << '\t' << stackData.top();//lấy ra 1 phần tử theo stack
		stackData.pop();
	}
//stack k có clear nên ta làm v ha or stackData = stack<int>();
	stack<int> stackData2;
	stackData2.push(10);
	stackData2.emplace(11);
	stackData2.swap(stackData);
	*/
	//queue
	/*queue<int> queueData;
	queueData.push(0);
	queueData.push(1);
	queueData.push(2);
	queueData.pop();

	int length = queueData.size();
	int first = queueData.front();
	int last = queueData.back();

	queue <int> queueData2;
	queueData2.push(1);
	queueData2.push(2);
	queueData.swap(queueData2);

	while (!queueData.empty())
	{
		cout << '\t' << queueData.front();
		queueData.pop();
	}*/
    /*else*/
    /*printf("Code c dc");
	int* p=new int;
	*p = 10;
	vector<int*> test;

	test.push_back(p);
	//hàm erase cho phép xóa vector phần tử ở 1 vị trí chỉ định, tuy nhiên nó chỉ xóa khỏi vector chứ vùng nhớ của cái GT đó nếu có thì vẫn còn. Tức\
	là nếu GT đó đc gán cho 1 biên khác thì nó vẫn còn, cho nên ta nên gán địa chỉ r delete nó đi if nó k null như biến op bên dưới
	int* op = test.at(0);
	test.erase(test.begin());
	if (op != NULL)//éo cần
	{
		delete op;
		op = NULL;
	}//chú ý khi tạo bất cứ kiểu dữ liệu nào với con trỏ thì phải xóa con trỏ vì hàm pop của các data type chỉ xóa khỏi list mà thôi
	cout << *p;
	int q = 9;
	int* nm = &q;
	//delete nm;=> sai vì chỉ delete khi có new. ta k thể ép xóa biến bth bằng con trỏ đc
	*/
	
//    MessageBox(NULL, L"Content", L"Title", MB_OK );
//đây là lệnh in ra 1 box chứa thông điệp(ko dừng CT),Dối số 1 là NULL, 2 là nội dung, 3 là title, 4 là các chế độ, chỉ chần nhớ MB_OK là nút OK\
có thể kết hợp vs các chế độ khác hiển thị icon(thực chất là define các số thôi) MB_INFORMATION(MB_ICONASTERISK),MB_ICONSTOP(MB_ICONHAND,MB_ICONERROR),\
MB_ICONQUESTION(k kết hợp đc icon),MB_ICONEXCLAMATION(MB_ICONWARNING),MB_USERICON
//thực chất MessageBox=MessageBoxW trả về kiểu số nguyên là trạng thái lỗi trả về 1 là hiển thị thành công.Có các dạng là IDOK,IDCANCEL,IDABORT\
IDRETRY,IDIGNORE,IDYES,IDNO,IDCLOSE,IDHELP. thg ta chỉ xét ĐK if vs IDOK, or dùng nó làm ĐK trả về các nút bấm

//messagebox có thể di với điều kiện và nhiều nút bấm 
/*    int msgboxID = MessageBox(
		NULL,
		(LPCWSTR)L"Resource not available\nDo you want to try again?",
		(LPCWSTR)L"Account Details",
		MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON3
	);//LPCWSTR k ảnh hưởng j chỉ là chuỗi wstring đằng sau, có nh kiểu TT
	//có max 4 nút vd:MB_DEFBUTTON4, thêm kiểu MB_DEFBUTTON vào là sẽ in đậm buttion thôi

//để hiện thị nút có các lựa chọn là MB_OK,MB_OKCANCEL,MB_ABORTRETRYIGNORE,MB_YESNOCANCEL,MB_YESNO,MB_RETRYCANCEL,MB_CANCELTRYCONTINUE. Xog ta đưa \
vào switch case làm j tùy ý. Xog ta đưa toàn bộ vào 1 hàm r gọi hàm đó
	switch (msgboxID)
	{//ấn nút nào sẽ trả về ID đó
	case IDCANCEL:
		// TODO: add code
		break;
	case IDTRYAGAIN:
		// TODO: add code
		break;
	case IDCONTINUE:
		// TODO: add code
		break;
	}
*/	


 	return 0;
}