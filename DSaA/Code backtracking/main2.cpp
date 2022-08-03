#include <iostream>
using namespace std;
//1>Xây Sk: Giả sử đã có {a1,...,ak-1} thì Sk=<Tập mẹ>\{a1,...,ak-1}
//2>Lấy từng phần tử của tập Sk: Đương nhiên để lấy từng phần tử của Sk ta đơn giản chỉ cần for tất cả, nếu trùng
//thì bỏ, nếu k trùng thì lấy-> làm hẳn thành 1 hàm kiểm tra đê
int n = 5;
int P[5] = { 1,2,3,4,6 };
int a[10];
int count = 0;

bool candidate(int j, int k) 
{
    for(int i = 0; i <= k - 1; i++ )
    if(P[j] == a[i]) 
    return false;
    return true;
}

void PrintfSol()
{
    count ++;
    cout << "Per " << count << ": ";
    for(int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int k)
{
    for (int j = 0; j < n; j++)//for các phần tử có thể có của a[k]
    if(candidate(j, k))//kiểm tra nếu P[j] chưa xuất hiện thì mới lấy
    {
        a[k] = P[j];//lấy a[k]
        if(k == n - 1)//đủ 5 phần tử thì in r chạy giá trị next
        {
            PrintfSol();
        }
        else{
            Try(k+1);//chưa đủ thì xây tiếp a[k+1] đến khi đủ
        }
    }
}
//k nên cho k đi từ 0 mà nên đi từ 1
int main()
{
    Try(0);
    cout << "Number of permutations: " << count << endl;

    return 0;
}