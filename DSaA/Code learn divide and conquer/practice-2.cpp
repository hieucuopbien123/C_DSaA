#include <bits/stdc++.h> 
using namespace std;
//bài toán tìm 2 số trong mảng có hiệu lớn nhất, số nhỏ trước số lớn
//Cách 1: quy hoạch động duyệt từ trái qua phải: lấy nó trừ min để cập nhập kết quả, nếu nhỏ hơn min thì thì cập 
//nhập min. Độ phức tạp O(n)
//Cách 2: brute force độ phức tạp O(n^2)
//Cách 3: chia để trị, độ phức tạp O(nlogn) vì T(n) = c + n + T(n/2) do ta có duyệt 1 lần nx bên trong nên theo
//định lý thợ là nlogn

int getMaxRight(int arrToFindMaxDiff[], int from, int to)
{
    int maxRight = from;
    for(int i = from; i <= to; i++){
        if(arrToFindMaxDiff[i] > arrToFindMaxDiff[maxRight]){
            maxRight = i;
        }
    }
    return maxRight;
}

int getMinLeft(int arrToFindMaxDiff[], int from, int to)
{
    int minLeft = from;
    for(int i = from; i <= to; i++){
        if(arrToFindMaxDiff[i] < arrToFindMaxDiff[minLeft])
            minLeft = i;
    }
    return minLeft;
}

int divideAndConquer(int arrToFindMaxDiff[], int from, int to)
{
    if(from >= to)
        return 0;
    int mid = (to - from)/2 + from;
    int maxRight = getMaxRight(arrToFindMaxDiff, mid + 1, to);
    int minLeft = getMinLeft(arrToFindMaxDiff, from, mid);
    int centerDiff = arrToFindMaxDiff[maxRight] - arrToFindMaxDiff[minLeft];
    cout << arrToFindMaxDiff[maxRight] << " " << arrToFindMaxDiff[minLeft] << " " << centerDiff << endl;
    return max(max(divideAndConquer(arrToFindMaxDiff, from, mid), 
                    divideAndConquer(arrToFindMaxDiff, mid + 1, to)),
                    centerDiff);
}

int main()
{
    int arrToFindMaxDiff[10] = { 1, 3, 20, 5, -15, 4, 1, 9, 0, 10 };
    cout << divideAndConquer(arrToFindMaxDiff, 0, 9);

    return 0;
}
//Phân tích chia để trị:
//chia nhỏ tìm base case: chia đôi phần tử, base case là khi from>=to thì giá trị là 0
//khi index to - from = 1 thì giá trị là to - from
//gọi đệ quy bài toán con: divideAndConquer(arr, from, to)
//kết hợp kết quả: kết quả là max của trái, phải và tính max phải - min trái
