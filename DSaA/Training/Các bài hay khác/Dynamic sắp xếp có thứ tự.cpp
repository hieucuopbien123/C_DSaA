#include <bits/stdc++.h>
using namespace std;

int main()
{
    int coins[3] = {1, 3, 5};
    int m = 6;
    int res[11];
    memset(res, 0 ,sizeof(res));
    res[0] = 1;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < 3; j++){
            if(coins[j] <= i){
                res[i] += res[i - coins[j]];
            }
            else{
                break;
            }
        }
    }
    cout << res[m];
    
    return 0;
}
/*Cơ chế: res[10] = res[10 - 1] + res[10 - 3] + res[10 - 5]
thì 3 cái đồng xu này sẽ thế chỗ cho nhau liên tục ở các vị trí này nên mới ra số cách mà lại có thứ tự
nhưng k thể nào cứ thế này mãi được mà phải có base case
base case là TH đầu tiên
nếu có 1 thì là 1
nếu có 2 thì là [2 - 1] = [1] là 1 tức là bắt đầu bằng 1
nếu có 3 thì là [2] + [0] tức 111 và 3 => quá đủ như v base case là 0 
*/
