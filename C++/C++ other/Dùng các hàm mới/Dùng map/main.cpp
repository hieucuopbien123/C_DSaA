#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> m;
    m.insert(pair<int, int>(0,1));
    m.insert(pair<int, int>(1,2));
    m.insert(pair<int, int>(2,3));
    m.insert(pair<int, int>(3,4));
    cout << m.size() << endl;
    // map<int, int>::iterator ite = --m.end();//có thể gán bằng giá trị trước của m.end bằng
    // //-- chứ k đc m.end() - 1 dù nó k đổi giá trị của m.end();
    // map<int, int>::iterator ite2 = --m.end();
    // cout << ite->first << " " << ite->second << endl;
    // cout << ite2->first << " " << ite2->second << endl;
    // m.erase(2);
    // cout << m.size() << endl;
    // cout << ite->first << " " << ite->second << endl;
    // cout << (--m.end())->first << " " << (--m.end())->second << endl;

    //duyệt và xóa đồng thời
    map<int, int>::iterator ite = m.begin();
    while(ite != m.end()){
        cout << ite->first << " " << ite->second << endl;
        int a = -1;
        if(ite->first == 2)
            a = ite->first;
        ite++;
        if(a != -1)
            m.erase(a);
    }
    
    return 0;
}


