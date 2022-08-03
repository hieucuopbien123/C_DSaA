#include <iostream>
#include <set>
#include <deque>
#include <queue>//chúa cả priority_queue
using namespace std;

class comparison{
    public: 
        bool operator()(int a, int b){
            return true;
        }
};

class Plane{
    public: 
        Plane(int q) {
            this->fuel = q;
        }
        int fuel;
        bool operator >(const Plane& foo) const{
            return fuel > foo.fuel;
        }
};

int main()
{
    //set k truy cập được với at
    set<int> test;
    set<int, greater<int>> test1;
    cout << "Empty: " << test.empty() << endl;
    test1.insert(1); test1.insert(2); test1.insert(1);
    //tự sắp xếp. set k nhận phần tử bị trùng(giống set của js)
    set<int, greater<int> >::iterator itr;
    cout << "The set s1 is : ";
    for (itr = test1.begin(); itr != test1.end(); itr++)
        cout << *itr<<" ";
    cout << endl;
    test1.erase(1);
    cout << "The set s1 is : ";
    for (itr = test1.begin(); itr != test1.end(); itr++)
        cout << *itr<<" ";
    cout << endl;
    
    itr = test1.find(2);
    cout << *itr << endl;
    test1.clear();
    
    int arr[] = {1, 3, 2};
    set<int> first (arr, arr + 3);
    test.swap(first);//muốn swap phải cùng template
    cout << "The set s1 is : ";
    for (itr = test.begin(); itr != test.end(); itr++)
        cout << *itr << " ";
    cout << endl;
    
    itr = test.lower_bound(3);//tìm số đầu tiên lớn hơn hoặc bằng 3 trong set
    //nếu lower_bound lớn hơn tất cả-> return số lớn nhất
    cout << *itr << endl;
    
    
    //deque
    std::deque<unsigned> mydeque (10);   // 10 zero-initialized unsigneds
    // mydeque.assign(7,100); //gán 7 phần tử thành 0
    for (unsigned i = 0; i < mydeque.size(); i++)
        mydeque.at(i) = i + 1;
    cout << "mydeque contains:";
    for(unsigned i = 0; i < mydeque.size(); i++)
        cout << ' ' << mydeque.at(i);
    cout << '\n';
    mydeque.erase(mydeque.begin());//xóa phát tự biến phần tử 1 thành phần tử 0
    cout << mydeque.at(0) << endl;
    cout << mydeque.size() << endl;//tự co lại thành 9 phần tử khi xóa
    mydeque.resize(11, 9);// k có tham số 2 mặc định là 0
    cout << mydeque.size() << endl;
    mydeque.shrink_to_fit();
    cout << mydeque.size() << endl;
    cout << "mydeque contains:";
    for(unsigned i = 0; i < mydeque.size(); i++)
        cout << ' ' << mydeque.at(i);
    cout << '\n';
    //ít dùng resize thôi. shrink_to_fit là giảm capacity tiêu tốn bộ nhớ, khi resize từ
    //bộ nhớ lớn về nhỏ phải gọi hàm này dù size được giảm nhưng bộ nhớ ngầm tiêu thụ
    //nên gọi sau hàm clear
    
    //back, begin, empty, clear, rbegin, emplace, emplace_back, emplace_end,
    //front, insert, max_size, pop_back, pop_front, push_back, push_font, resize, swap


    //priority_queue
    //hàng đợi ưu tiên do ta quy định tiêu chuẩn gì được coi là ưu tiên và sẽ pop, push
    //theo sự ưu tiên đó. Mỗi ptu được liên kết với 1 mức độ ưu tiên. Độ ưu tiên lớn nhất
    //luôn ở top
    //Cấu trúc mảng lưu max heap chính là 1 ví dụ của hàng đợi ưu tiên. Cơ chế:
    //thêm 1 ptu: chèn vào cuối-> build lại heap
    //xóa 1 phần tử bky: hoán đổi phần tử cuối-> xóa cuối-> build lại heap(tự implement thì
    //có thể có hàm này còn hàng đợi thì chỉ có push và pop chung thôi)
    //lấy top: lấy phần tử mảng ở [0] hay đỉnh của heap
    //pop: xóa top và build heap
    //k duyệt. Trong STL có sẵn
    
    priority_queue<string> mypq;
    priority_queue<int, vector<int>, greater<int>> testpQueue(arr, arr + 3);
    priority_queue<int, vector<int>, greater<int>> testpQueue2;
    priority_queue<int, vector<int>, comparison> testpQueue3(arr, arr + 1);
    //đối số 2 mặc định là vector<T>
    //có sẵn:equal_to, not_equal_to, greater, less, greater_equal, less_equal->default: less
    mypq.emplace("Orange");
    cout << "Empty: " << mypq.empty() << endl;
    testpQueue2.swap(testpQueue);
    int a = testpQueue2.top();
    testpQueue2.pop();
    testpQueue2.push(10);
    cout << a << endl;
    cout << "size: " << testpQueue2.size() << endl;
    
    vector<Plane> vP;
    vP.push_back(Plane(4));
    vP.push_back(Plane(3));
    priority_queue<Plane, vector<Plane>, greater<Plane>> PQPlane(vP.begin(), vP.end());
    cout << PQPlane.top().fuel;
    PQPlane.pop();
    cout << PQPlane.top().fuel << endl;
    
    return 0;
}
