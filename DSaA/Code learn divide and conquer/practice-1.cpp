#include <bits/stdc++.h> 
using namespace std;

//tính pow bằng divide and conquer mà k dùng hàm pow
unsigned long long calculate(unsigned long long a, unsigned long long b){
    if(b ==  1)
        return a;
    unsigned long long temp = calculate(a, b/2);
    if(b%2 == 0){
        return temp*temp;
    }else{
        return temp*temp*a;
    }
}

int main()
{
    unsigned long long a = 0, b = 0;
    cin >> a >> b;
    //cách 1 dùng divide and conquer
    cout << calculate(a, b) << endl;
    //cách 2 dùng vòng lặp
    unsigned long long res = a;
    for(unsigned long long i = 1; i < b; i++){
        res *= a;
    }
    cout << res;

    return 0;
}

//phân tích chia để trị: 3 vấn đề như đã biết
//tìm cách chia bài toán: 2^8 = 2^4 * 2^4 cứ như v 2^2 2^1 là bằng 2 luôn và là base case
//tìm cách gọi từ 2^8 về base case là 2^2: pow(a,b/2)
//kết hợp lời giải từ con sang cha: pow(a,b) = pow(a,b/2)*pow(a,b/2)
//fix: b lẻ thì 2^7 = 2^6*2 = 2*(7/2)*2^(7/2)*2

//Độ phức tạp: cách vòng lặp: O(b)
//Cách divide and conquer: O(logb) => đưa ra phương pháp nhanh hơn cả tuyến tính
