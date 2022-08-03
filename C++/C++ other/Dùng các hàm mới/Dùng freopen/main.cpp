#include <bits/stdc++.h>
using namespace std;

int main ()
{
    char str[] = "almost every programmer should know memset!";
    memset(str,'-',6);
    puts(str);
    
    //chú ý hàm freopen sẽ mở lại file với mode gì gán với stream nào. Mở lại file thì k nói
    //làm gì nhưng gán stream vào file làm cho nó k còn như bth nx, nếu ta close nó thì 
    //phải chú ý gán với cái gì khác nếu k thì cái stream sẽ k sử dụng đc
    freopen ("myfile.txt","w",stdout);// hàm này sẽ khiến mọi thứ write vào stdout sẽ write vào myfile.txt
    //mở file có thể viết, stdout sẽ là file đó, k còn hiện trên console nx
    printf ("This sentence is redirected to a file.");
    fclose (stdout);
    //đóng vào thế này thì cout bên dưới k hoạt động nx
  
    //VD stdin k thể nhập từ bàn phím đc nx mà lấy từ file kia
    if (fopen("input.txt", "r"))
        assert(freopen("input.txt", "r", stdin));
    int a;
    cin >> a;
    cout << a;//k hiện vì đóng file gán vs stdout r
  return 0;
}
