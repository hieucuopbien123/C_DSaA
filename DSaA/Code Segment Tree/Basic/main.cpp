#include <bits/stdc++.h>
using namespace std;
//Xét input array {1, 3, 5, 7, 9, 11} 
//mảng biểu diễn dưới dạng segment tree là:
//st[] = {36, 9, 27, 4, 5, 16, 11, 1, 3, DUMMY, DUMMY, 7, 9, DUMMY, DUMMY}
/*      36
    9       27
  4  5    16  11
1  3     7  9
biểu diễn dạng cây như này. 2 bên tree dạng như nhau, ta chia input array đôi ra liên tục
nếu n là power of 2 sẽ k có dummy node.Array có size:2n-1 với n node lá và n-1 node internal
n là 2*ceil(log2(n))
Chiều cao của cây là ceil(log2(n))+1. Node con của x là 2x+1 và 2x+2 và node cha của x là 
(x-1)/2
*/

int getMid(int s, int e) { 
    return s + (e - s)/2; 
}

//tạo quan hệ tổng từ arr[ss] đến arr[se] là st[si] r cứ đệ quy update 3 giá trị đó là xong
//update node i tăng thêm diff với si là giá trị chứa tổng từ ss đến se
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)
{
	if (i < ss || i > se)
		return;

	st[si] = st[si] + diff;
	if (se != ss)
	{
		int mid = getMid(ss, se);
		updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
		updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
	}
}

//update 1 value đồng nghĩa phải tính lại toàn bộ array vì tổng đã thay đổi
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
	if (i < 0 || i > n - 1){
		cout << "Invalid Input";
		return;
	}

	// Get the difference between new value and old value
	int diff = new_val - arr[i];

	// Update the value in array
	arr[i] = new_val;

	// Update the values of nodes in segment tree
	updateValueUtil(st, 0, n-1, i, diff, 0);
}

//st[si] là giá trị tổng của range từ ss đến se. Do ta đã duyệt hết mọi phần tử từ 0 đến n-1
//và chia nhỏ đến mức chỉ có 1 phần tử và cứ phần tử thuộc khoảng thì ta cộng lại nên k sót
//Mọi function đều phải đảm bảo st[si] là giá trị tổng từ arr[ss] đến arr[se]
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
    //thuộc khoảng là lấy, k sợ trùng vì ta chia đôi luôn xung khắc
	if (qs <= ss && qe >= se)
		return st[si];

    //k thuộc thì bỏ qua
	if (se < qs || ss > qe){
		return 0;
	}
	
	//nếu khoảng đang có k nằm trong khoảng cần tính tổng và k nằm ngoài mà phải chia nhỏ nx
	//mới đc thì gọi tiếp đệ quy
	int mid = getMid(ss, se);
	return getSumUtil(st, ss, mid, qs, qe, 2*si + 1) +
		    getSumUtil(st, mid + 1, se, qs, qe, 2*si + 2);
}
int getSum(int *st, int n, int qs, int qe)
{
	//Check input có sai k
	if (qs < 0 || qe > n - 1 || qs > qe)
	{
		cout << "Invalid Input";
		return -1;
	}

	return getSumUtil(st, 0, n - 1, qs, qe, 0);
}

//phạm vi xây dựng từ ss đến se vói si là index hiện tại của arr ban đầu
//cần xây và lưu vào st. Xây bằng đệ quy
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
	if (ss == se)//mảng có 1 phần tử thì arr cx chỉ có 1 phần tử nên lưu luôn
	{
		st[si] = arr[ss];
		return arr[ss];
	}
	int mid = getMid(ss, se);
	st[si] = constructSTUtil(arr, ss, mid, st, si*2 + 1) 
	            + constructSTUtil(arr, mid + 1, se, st, si*2 + 2);
	return st[si];
}
//hơi khó vì chia đệ quy theo chiều sâu dần chứ kp chia theo chiều ngang giảm kích thước
//như đệ quy bth

int *constructST(int arr[], int n)
{//người ta thg gọi hàm để khởi tạo or check điều kiện xong return kết quả lấy từ hàm
//util như thế này
	int x = (int)(ceil(log2(n)));
	int max_size = 2*(int)pow(2, x) - 1;
	//lấy được kích thước nguyên của mảng segment tree có bao nhiêu phần tử
	int *st = new int[max_size];//cấp phát 1 lượng bộ nhớ đủ cho segment tree
    
    //lưu giá trị vào bộ nhớ đó
	constructSTUtil(arr, 0, n-1, st, 0);
	return st;
}

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	int *st = constructST(arr, n);

	cout << "Sum of values in given range = " << getSum(st, n, 2, 3)<<endl;

	updateValue(arr, st, n, 1, 10);
    cout << "Updated sum of values in given range = " << getSum(st, n, 1, 3) << endl;
    
    //Segment tree k chỉ dùng để tính tổng như này, VD: segmemt tree dùng minimum query 
    //range, tương tự như tree này nhưng mỗi internal node là minimum của 2 node con chứ
    //k còn là tổng 2 node con nx. Sau đó ta sẽ có tương tự hàm query minimum là O(logn)
    
    delete st;
	return 0;
}
//Segment tree=> construct: O(n); query sum: O(logn); Update: O(logn)
//Array Linear=> construct: O(n); quert sum: O(n); Update: O(1)

//Đây là 1 hướng mới để tối ưu, dạng bài tính tổng từ m đến n của mảng hay tìm giá trị 
//nhỏ nhất từ m đến n hay bất cứ 1 cái gì khác tốn O(n) bh ta đều có thể implement mà chỉ
//tốn có O(logn). 
//VD: thuật toán chia để trị sẽ chia mảng ra thành nhiều phần và yêu cầu thao tác gì đó
//với từng phần, thao tác đó tốn O(n) bh sẽ chỉ tốn O(logn). Nó đặc biệt với chia để trị vì
//chia để trị thực hiện nhiều lần 1 phép đó trên 1 khoảng nào đó của mảng, tất cả thao tác 
//đó đều đc rg

