#include <iostream>
#include <typeinfo>
using namespace std;
  
int main()
{
    /*
    //string lưu chuỗi bth, cin dừng khi gặp dấu cách or \n
    string str1 = "Hello";
    cin >> str1;
    cout << str1 << " " << str1[0] << endl;
    
    //char[] ez specific số lượng và phần tử cuối là 0
    char str2[5] = "Hell";
    cin >> str2;
    cout << str2;
    
    //'P' là char còn "P" là const char*. 
    //char* giống string nhưng k có tc của 1 biến bth như string nên k gán = đc như string
    //Kiểu dữ liệu của string và char* là khác nhau, k dùng đc trong 1 số Th
    //Còn char* và char[] giống nhau chỉ là 1 cái phần tử động
    char* str3 = new char();
    str3[3] = 'P';
    cout << str3 << " " << str3[10];
    
    //char* khai báo phần tử ban đầu chả có ý nghĩa gì, ta có thể dùng nhưng chỉ để tạo đc -> éo đc dùng quá
    //initialize từng phần tử, số phần tử phải lớn hơn initialization
    char* str5 = new char[2]{'a','b'};
    cin >> str5;
    str5[12] = 'H';
    cout << str5 << endl;
    */
    
    /*
    //cin.get(char*,maxsize) k dùng đc với string cho phép nhập 1 dòng với giới hạn ký tự
    //dùng cin.get ngay sau cin phải xóa đệm
    char* str4 = new char();
    string str8 = "";
    cin >> str8;
    cin.ignore(32767, '\n');
    cin.get(str4, 10);
    cout << str4 << " " << str8 << endl;
    
    //Ngược lại getline(cin,string) lại chỉ dùng riêng với string, get 1 dòng
    //khi dùng getline ngay sau cin thì phải xóa đệm với cin.ignore(32767, '\n');
    string str6 = "";
    string str7 = "";
    cin >> str6;
    cin.ignore(32767, '\n');
    getline(cin, str7);
    cout << str6 << " " << str7 << endl;
    
    //đối số 3 sẽ giúp nhập dừng lại khi gặp dấu nào, mặc định là \n. Tương tự cin.get
    //kết hợp với cin đằng trước và stdin đằng sau: đằng trước: sẽ k bị dừng nx mà \n sẽ
    //lưu tiếp vào getline phía sau và k dừng lại vì chưa gặp _; đằng sau: các ký tự sau
    //_ sẽ k bị xóa và lưu tiếp vào cin đằng sau => fix hết với cin.ignore
	string str9 = "";
	string str10 = "";
	string str11 = "";
	cin >> str9;
    getline(cin, str10, '_');
    cin >> str11;
    cout << str9 << " " << str10 << " " << str11 << endl;
    //gõ a\nbc_ed\n= được a \nbc _ed
    */
    
    //cin.getline() y hệt cin.get()
    //cin.clear() chỉ clear cái flag mà thôi
    
    
    return 0;
}

