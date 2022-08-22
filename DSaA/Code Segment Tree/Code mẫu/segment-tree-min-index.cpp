#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minValue(int arr[], int x, int y) {
    if(x == -1)
        return y;
    if(y == -1)
        return x;
    return (arr[x] > arr[y]) ? y : x;
}

int getMid(int s, int e) { 
    return s + (e - s)/2; 
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
	if (ss == se){
		st[si] = ss;
		return ss;
	}
	int mid = getMid(ss, se);
	st[si] = minValue(arr, constructSTUtil(arr, ss, mid, st, si*2 + 1), 
	        constructSTUtil(arr, mid + 1, se, st, si*2 + 2));
	return st[si];
}

int *constructST(int arr[], int n)
{
	int x = (int)(ceil(log2(n)));
	int max_size = 2*(int)pow(2, x) - 1;
	int *st = new int[max_size];
    
	constructSTUtil(arr, 0, n-1, st, 0);
	return st;
}

int getMinimumUtil(int arr[], int *st, int ss, int se, int qs, int qe, int si)
{
	if (qs <= ss && qe >= se)
		return st[si];

	if (se < qs || ss > qe){//return giá trị gì mà loại bỏ được đi
		return -1;//nên để INT_MAX
	}
	
	int mid = getMid(ss, se);
	return minValue(arr, getMinimumUtil(arr, st, ss, mid, qs, qe, 2*si + 1),
		    getMinimumUtil(arr, st, mid + 1, se, qs, qe, 2*si + 2));
}
int getMinimum(int arr[], int *st, int n, int qs, int qe)
{
	if (qs < 0 || qe > n - 1 || qs > qe)
	{
		cout << "Invalid Input";
		return -1;
	}

	return getMinimumUtil(arr, st, 0, n - 1, qs, qe, 0);
}

int main()
{
    int arr[] = {1, 3, 2, 7, 9, 11};
    int n  = 6;
    int * st = constructST(arr, n);
    cout << getMinimum(arr, st, n, 0, 5);//nhập vào index từ đâu đến đâu, trả ra index luôn

    return 0;
}
