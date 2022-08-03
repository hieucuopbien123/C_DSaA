#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a = 2147483647;
    int b = 2147483647;
    cout << (0LL + a + b) << endl;
    cout << 2147483647LL + a << endl;
    //tính toán đc, lưu vào long long đc nhưng k lưu vào int đc vì quá khoảng. Nếu ta muốn
    //dùng int mà tính ra quá mà vẫn được như này thì dùng hậu tố LL
    
    //Thực chất có nhiều hậu tố cho các type: 
    cout << 1ULL << endl;//unsigned long long
    cout << 1.0f << endl;//float
    cout << 1.0 << endl;//tự là double
    cout << 1.0L << endl;//long double
    //Tương tự:
    cout << 'A' << endl;//char
    cout << L'A' << endl;//wchar_t
    cout << u'A' << endl;//ít dùng char16_t (C++0x only)
    cout << U'A' << endl;//char32_t (C++0x only)\
    
    //or tiền tố thì có 0x báo hiệu hexa, 0 là octa
    
    int arr[10] = {};
    fill_n(arr, 10, 9);//2 là số lượng, 3 là chất lượng
    cout << arr[9] << endl;
    
    vector<int> myvector (8,10);//khởi tạo 8 giá trị 10=> nên dùng vector thế hoàn toàn array

    return 0;
}


