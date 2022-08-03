#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

bool myFunction(int a, int b){
    return true;
}//true hết thì thứ tự chỉ bị đảo ngược

int main()
{
    //sort-> sort kiểu nào tùy thuộc vào đầu vào
    int arr[6] = { 3, 5, 6, 4, 4, 1 };
    // sort(arr, arr + 6, greater<int>());//mặc định là less
    sort(arr, arr + 6, myFunction);//cú pháp k có (), greater lại có
    for(int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    //search
    //search trong sorted: là tìm số đầu tiên lớn hơn hoặc bằng 4. Nếu tất cả đều nhỏ hơn 4
    //trả về last
    int* low = lower_bound(arr, arr + 6, 4);//nó dùng binary search
    cout << *low << endl;
    //search trong unsorted: trả ra số == 4, k có ra rác
    int *x = find(arr, arr + 6, 4);
    cout << *x << endl;
    cout << string::npos << endl;
    //find trả ra vị trí xh đầu tiên của nó trong iterable kiểu size_t. 
    //Nếu k tìm đc, nó trả ra string::npos là hs static => sai nhé, cái này là  tìm của string thôi
    
    //biểu diễn tập hợp dạng binary
    int y = (1<<3) | (1<<0) | (1<<4);
    cout << y << endl;
    //toán tử dịch bit: số int có kích thước 32 bit biểu diễn số 1 là: 0000...001;
    //ta có: 0...01 | 0...01000 | 0...010000 thành 0...011001 binary là 25 decimal
    //Tương tự có các toán tử: - ; & ; ~(~ là complement set)
    //VD: lưu set có 3 phần tử là {0,3,4}-> chỉ lưu đc set kích thước nhỏ tầm 30 phần tử
    y = (1<<3) | (1<<0) | (1<<4);//các bit có số đó là 1
    //set trông là 0; set 1 phần tử là 1 << i; universal set: (1 << 30) - 1; => 29 bit đầu là 1 
    //complement of set: ~x & ((1 << n) - 1); 
    //kiểm tra xem phần tử 3 có thuộc set k
    if(y & (1 << 3))
        cout << "3 thuộc set" << endl;
    else
        cout << "3 k thuộc set" << endl;
    //nếu dữ liệu lớn mới dùng kiểu set<int>
    //dùng như này nếu chỉ cần kiểm tra 1 phần tử có thuộc set hay k, tiết kiệm bộ nhớ vì
    //chỉ cần 1 biến int lưu cả set
    //set tương tự phần tử trùng nó chả coi ra gì
    
    //heap: make_heap, pop_heap, push_heap, sort_heap
    //nó kp là 1 kiểu dữ liệu mới mà là ta sắp xếp lại ở các kiểu data có iterator cũ
    int myints[] = { 10, 20, 30, 5, 15 };
    vector<int> v(myints, myints + 5);
    
    make_heap(v.begin(), v.end(), less<int>());//mặc định cx là less, là max heap r
    cout << "initial max heap   : " << v.front() << '\n';
    
    pop_heap(v.begin(),v.end()); 
    //hàm pop heap cho phần tử đầu xuống cuối, bỏ qua nó và sắp xếp lại, ta phải pop thủ công
    //nó ra
    v.pop_back();
    cout << "max heap after pop : " << v.front() << '\n';
    
    v.push_back(99); push_heap (v.begin(),v.end());
    //hàm push_heap sẽ mở rộng heap của kiểu dữ liệu và sắp xếp lại heap sau khi thêm
    //vào 1 phần tử
    cout << "max heap after push: " << v.front() << '\n';
    
    sort_heap (v.begin(), v.end());//mặc định là less
    //sort cái heap hiện tại(là bất cứ kiểu dữ liệu gì) giống hàm sort như bth
    //thế tại sao k gọi sort bth mà gọi sort heap. Vì là heap sẵn r nó sẽ có cách sort
    //nhanh hơn bth nên sort đúng kiểu sẽ có thuật toán tối ưu
    
    reverse(v.begin(), v.end());
    //đảo ngược thứ tự, của data đã có(klq j đến sắp xếp)
    
    cout << "final sorted range :";
    for (unsigned i=0; i<v.size(); i++)
        cout << ' ' << v[i];
    cout << '\n';

    return 0;
}
