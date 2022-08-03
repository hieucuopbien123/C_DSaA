#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int cur, int val){
    return (cur > val);
}

bool compBi(int cur, int val){
    cout << "T: " << cur << " " << val << endl;
    return (cur > val);
}

int main()
{
    int a[10] = {10, 30, 20, 40, 50, 60};
    int temp = distance(a, a + 10);
    cout << temp << endl;
    cout << *lower_bound(a, a + 5, 70) << endl;
    cout << distance(a, lower_bound(a, a + 5, 30)) << endl;
    //lower_bound trả ra con trỏ trỏ vào địa chỉ có giá trị đầu tiên lớn hơn hoặc bằng đối
    //số 3
    cout << *(a + 5) << endl;// có 6 phần tử thì max là +5 thôi
    
    //nếu muốn search từ cuối lên trên, ta k làm được với array nhưng làm được với vector
    //vì có rerverse iterator. Do nó chỉ nhận first và last và search bằng cách ++ cái first
    //lên cho đến hết last(cơ bản là thế chứ source code nó làm gì bên trong nhanh hơn hay
    //k k rõ) nên array k có reverse iterator nên k search ngược được-> dùng vector,..
    
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);
    cout << *lower_bound(arr.rbegin(), arr.rend(), 20, compare) << endl;//ra 50 chứ j nx
    //phải đảm bảo là dùng lower_bound thì arr đã đc sort
    //upper_bound là tìm số lớn hơn đối số 3, khác với lower_bound là >=
    //lower_bound sử dụng binary search. Nó có 2 ver. Ver 1 mặc định là tìm như v
    //còn ver2 có thêm compare function.
    //Compare function nhận (forward ite, val)-> trả ra bool cho biết ite có đứng trước
    //val hay k. Hay nói cách khác, nó lấy giá trị đầu tiên sau cái val. Và vc 1 giá trị 
    //đứng trước hay sau val do hàm compare quyết định. Mặc định nó dùng less<int> tức
    //return x<y tức nhỏ hơn val thì đứng trước
    //Ta tùy biến muốn lấy giá trị nhỏ đầu tiên nhỏ hơn val thì cho giá trị nhỏ hơn val nằm
    //sau val hay giá trị đứng trước val sẽ lớn hơn val-> giá trị lớn hơn val sẽ return true
    //nên ta làm hàm compare như bên trên
    
    //bên cạnh upper_bound, lower_bound, find(unsorted) còn binary_search
    cout << binary_search(arr.begin(), arr.end(), 20) << endl;
    cout << binary_search(arr.begin(), arr.end(), 20, compBi) << endl;
    //hàm comp của binary_search nhận vào 1 là giá trị search hiện tại và 2 là value cần 
    //search. trả ra bool rằng có nên search tiếp phía bên phải hay k. Binary_search này chỉ
    //dừng khi first bằng last. Ở trên ta tạo ra nó search tiếp bên phải nếu giá trị hiện tại
    //đang lớn hơn giá trị cần tìm, mà rõ ràng lớn hơn giá trị cần tìm thì phải search bên
    //trái mà đây ta search bên phải nên hiển nhiên là 0 có r. Mặc định nó dùng less là <
    
    //Ta chỉ dùng các compare nếu muốn custom lại hàm mặc định mà thôi. VD tạo 1 struct và
    //sort r search 1 trường nào đó chứ k còn là sort r search int như default nx.
    
    return 0;
}
