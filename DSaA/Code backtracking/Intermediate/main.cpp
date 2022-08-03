#include <iostream>
using namespace std;
int n = 0;
int m = 0;
int count = 0;
int a[100];

void PrintSolution() 
{
    int i;
    count++ ;
    cout << "The subset #" << count << ": ";
    for(i=1 ; i<= m ;i++) 
    cout<< a[i] << " ";
    cout << endl;
}

void Try(int k)
{
    int j;
    for(j = a[k-1] +1; j<= n-m+k; j++) 
    {
        a[k] = j;
        if (k==m) 
        PrintSolution();
        else 
        Try(k+1);
    }
}
//Nếu dùng bruteforce sẽ tạo m vòng for mỗi vòng lại for các giá trị của tập hợp để lấy ra 1 giá trị k trùng với 
//giá trị đã lấy. Dùng backtracking mới là pro bài này(chỉ cần tìm số tập con)

//Giả sử tập hợp cho là: 1,2,...,n(số nguyên tăng dần-> tập nào chả đc vì chỉ cần tìm số lượng tập con)
//Các bước:
//1)Xây dựng tập candidate Sk: ta có S1 là mọi giá trị có thể của a[1] là phần tử đầu tiên của tập con thì hiển 
//nhiên S1 là {1,2,..,n-(m-1)}; Ta coi là chọn tập con có thứ tự để tính vì vc chọn tập con thứ tự khác nhau vẫn 
//chỉ tính là 1 tập=> Nếu để chọn loạn thì a1 có thể là bất cứ cái gì thì làm sao mà xđ S1 đc
//Tổng quát giả sử đã có được {a1,..,ak-1} thì Sk= {ak-1+1, ak-1+2, ..., n-(m-k)}(chú ý xây từ a[1] đổ đi)
//->giả sử có a[k] tìm a[k+1]=>đây mới là thứ qtr
//2)Lấy các phần tử Sk bằng vòng for

int main()
{
    cout << "Enter m, n: ";
    cin >> m >> n;
    Try(1);
    cout << "Number of subset having m elements is " << count << endl;

    return 0;
}



