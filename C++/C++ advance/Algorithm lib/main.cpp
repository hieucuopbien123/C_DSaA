#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

void printFunction (int i) { 
    cout << i << " ";
}

bool myfn(int a, int b) {
    return a < b;
}

int main(){
    //thư viện algorithm
    //for_each
    vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);
    for_each(myvector.begin(), myvector.end(), printFunction);
    cout << "\n";
    
    //find. pb hàm: std::find() và string.find()
    //string.find()
    string str = "hello worldello";
    size_t pos = str.find("hellqo");
    cout << (pos == string::npos) << " ";
    pos = -1;
    pos = str.find("ello2", pos + 1, 4);
    cout << pos << " ";
    pos = str.find("ello2", pos + 1, 4);
    cout << pos << "\n";
    //std:find()
    vector<int>::iterator p = find(myvector.begin(), myvector.end(), 40);//giá trị 2 là vị trí cuối + 1 đó
    cout << (p == myvector.end()) << "\n";
    //count
    int myints[] = {10,20,30,30,20,10,10,20};   // 8 elements
    int mycount = count (myints, myints+8, 10);//nó luôn thao tác trên [first,last) khi hàm nhận first last
    cout << "10 appears " << mycount << " times.\n";
    
    //copy
    int myints1[]={10,20,30,40,50,60,70};
    vector<int> myvector1 (10,100);//khởi tạo 10 giá trị 100
    copy(myints1, myints1 + 7, myvector1.begin() );//copy từ mảng vào vector, các vị trí từ 8->10 vẫn là 100
    for_each(myvector1.begin(), myvector1.end(), printFunction);
    
    //swap
    int x = 10, y = 20;// x:10 y:20
    swap(x, y);// x:20 y:10

    vector<int> foo (4,x), bar (6,y);//foo:4x20 bar:6x10
    swap(foo,bar);// foo:6x10 bar:4x20
    
    //min
    cout << "min(2,1)==" << min(2,1) << '\n';
    cout << "min('a','z')==" << min('a','z') << '\n';
    
    //min_element
    cout << "The smallest element is " << *min_element(myints, myints + 7) << '\n';
    cout << "The largest element is "  << *max_element(myints, myints + 7) << '\n';
    
    cout << "The smallest element is " << *min_element(myints,myints + 7, myfn) << '\n';
    cout << "The largest element is "  << *max_element(myints,myints + 7, myfn) << '\n';
    //hàm compare định nghĩa phần tử thứ nhất gọi là nhỏ hơn phần tử thứ 2 tức là sao
    //ví dụ thao tác với struct thì phần tử thứ nhất nhỏ hơn thứ 2 khi 1 trường đang xét nhỏ hơn chẳng hạn
    
    //prev_permutation
    int myints2[] = {1,2,3};
    int check = prev_permutation(myints2, myints2 + 3);
    cout << check << "\n";//có tìm được con nào nhỏ hơn con này theo thứ tự từ điển k, trả ra true or false
    for_each(myints2, myints2 + 3, printFunction);
    cout << "\n";
    
    //distance của utility
    cout << distance(myints2 + 1, myints2 + 3);

    int arr1[5] = {1,3,5,7,9};
    int arr2[7] = {2,4,6,8,9,10,11};
    int arr3[12];
    merge(arr1, arr1 + 5, arr2, arr2 + 7, arr3);
    //hàm merge sẽ merge 2 tập đã sắp xếp thành 1
    for(int i = 0; i < 12; i++){
        cout << arr3[i] << " ";
    }
    
    return 0;
}