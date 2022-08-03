#include <iostream>
#include <string>
using namespace std;

class Test{
public:
    Test(){};
    ~Test(){};
    string name;
    Test(Test &test){
        this->name = "Trang ";//định nghĩa lại copy constructor
    }
};

void run(Test t1){
    cout << t1.name;
}

int main()
{
    Test test;
    test.name = "hieu ";
    run(test);
    cout << test.name;

    return 0;
}
