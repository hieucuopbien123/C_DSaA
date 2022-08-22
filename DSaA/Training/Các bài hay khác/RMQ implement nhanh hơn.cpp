#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000001
#define MAX 31
 
int a[MAXN];
int t[MAXN][MAX];
int n, m;
 
int main () {
    //lấy đầu vào
    ios_base::sync_with_stdio(false);    
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	t[i][0] = a[i];
	}
    
    //j chạy từ 1 đến <= log2(n). Đm viết 2^j thì thành 1<<j
    //i chạy từ 0 đến 1
    for (int j = 1; (1<<j) <= n; j++) {
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
            t[i][j] = min(t[i][j-1], t[i+(1<<(j-1))][j-1]);
        }
    }
    /*
    for(int j = 1; j < log2(n); j++){
        for(int i = 0; i < n + 1 - 2^j; i++){
            t[i][j] = min(t[i][j - 1], t[i + 2^(j - 1)][j - 1]);
        }
        min vị trí [4][4] = min(t[4][3], t[4 + 2^3][3])
    }
    t[i][j] là giá trị min của mảng gồm j phần tử bắt đầu từ vị trí i trong mảng gốc
    */
 
	int ans = 0;
    cin >> m;
    while(m--) {
        //lấy input xong tính luôn
    	int i,j;
        cin >> i >> j;
        int k = log2(j-i+1);
	    ans += min(t[i][k], t[j-(1<<k)+1][k]);
	    /*VD từ 1 đến 5, thì k = 2-> ta tìm min(t[1][2], t[2][2])
	    ta tính để nó rơi vào min số lượng phần tử đó bắt đầu từ 1 và lượng phần tử kết thúc tại 5
	    */
    }
    cout << ans;
    return 0;
}
/*Cơ chế giống segment tree:
Xây: ở mỗi phần tử, ta xây mảng cho nó lưu min bắt đầu từ phần tử đó, kết thúc tại phần tử 2^j
Lấy: trong khoảng bất kỳ ta lấy bắt đầu từ phần tử đầu tiên và kết thúc ở phần tử cuối cùng. 2 Th cùng số lượng
phần tử là 2^(j - i + 1)
Tương tự các TH khác cũng có thể implement như này
Nếu là tổng thì khi lấy phải chuẩn rõ ràng chứ k được bắt đầu kết thúc như này. VD TH trên là tổng
int k = log2(j-i+1);
ans += t[i][k];
if(j - i + 1 - 2^k)
    ans += t[i +(1<<k)][log2(j - i + 1 - 2^k)];
*/
