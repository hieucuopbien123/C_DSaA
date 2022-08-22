#include <bits/stdc++.h>
using namespace std;
int array1[6] = { -2, 11, -4, 13, -5, 2 };
int cur[6];
int res;
//k được đặt tên là array

void Trace(int k){
    res -= array1[k];
    if(k != 0 && res != 0)
        Trace(k - 1);
    cout << array1[k] << " ";
}

//tìm maxsubarray r trace by loop
int main()
{
    res = array1[0];
    cur[0] = array1[0];
    int index = 0;
    for(int i = 1; i < 6; i++){
        int temp1 = array1[i];
        int temp2 = cur[i - 1] + array1[i];
        cur[i] = max(temp1, temp2);
        if(cur[i] > res){
            res = cur[i];
            index = i;
        }
    }
    cout << res << endl;
    Trace(index);

    return 0;
}
//Tùy vào bài khác nhau mà hàm trace khác nhau

