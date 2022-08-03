#include <iostream>
#include <typeinfo>
using namespace std;
class Hello
{
    int a = 2;
    public:
    int test()
    {
        cout << "test is calling here \n";
        return a;
    }
};

void hello()
{
    
}

int main()
{
    cout << "Hello: " << hello;
    cout << &Hello::test << endl;//in địa chỉ hàm của class phải có & như này->dạng cơ bản nhất
    //bh ta sẽ lưu nó vào 1 con trỏ hàm thủ công
    int (Hello::* func)() = &Hello::test;//(tức "Hello::" là 1 kiểu biến)
    cout << func << endl;
    //như v func = &Hello::test => cú pháp củ chuối vl. Nếu chỉ cần dùng bth thì auto cx đc
    //<giá trị trả về>(<kiểu class tên>::* tên)(<đối số truyền vào hàm>)
    
    //nếu k đặt tên func thì ta có thể dùng là kiểu dữ liệu bth, chỉ là vị trí biến nó nv
    //bởi vì con trỏ hàm cx là 1 kiểu dữ liệu nên có thể cast như các kiểu int,double,.. bth
    cout << static_cast<int (Hello::*)()>(&Hello::test) << endl;
    //cast con trỏ hàm sang 1 con trỏ hàm khác là chính nó->k có ý nghĩa gì->chỉ biết là có thể
    //làm đc nv
    
    /*Nếu hàm test là bth kp của class thì ta dùng: int (*func)() = test;=> dùng func và test là 1.
    Nhưng khi hàm test là 1 thành phần của class, thì hàm đó cũng có địa chỉ và địa chỉ này trỏ đến
    hàm gọi là con trỏ hàm của class. Bh t muốn gán nó vào con trỏ để sử dụng con trỏ hàm thì nên 
    nhớ rằng 1 hàm có 1 địa chỉ. Nếu ta tạo 2 biến class Hello a; Hello b; thì địa chỉ của hàm test
    ta dùng của 2 biến là như nhau. Khi gọi hàm test nó sẽ mò sang địa chỉ của test của class Hello 
    và sử dụng.
    */
    
    return 0;
}
