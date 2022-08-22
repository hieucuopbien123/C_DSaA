#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxValue(int arr[], int x, int y) {
    if(x == -1)
        return y;
    if(y == -1)
        return x;
    return (arr[x] > arr[y]) ? x : y;
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
	st[si] = maxValue(arr, constructSTUtil(arr, ss, mid, st, si*2 + 1), 
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

int getMaximumUtil(int arr[], int *st, int ss, int se, int qs, int qe, int si)
{
	if (qs <= ss && qe >= se)
		return st[si];

	if (se < qs || ss > qe){//return giá trị gì mà loại bỏ được đi
		return -1;
	}
	
	int mid = getMid(ss, se);
	return maxValue(arr, getMaximumUtil(arr, st, ss, mid, qs, qe, 2*si + 1),
		    getMaximumUtil(arr, st, mid + 1, se, qs, qe, 2*si + 2));
}
int getMaximum(int arr[], int *st, int n, int qs, int qe)
{
	if (qs < 0 || qe > n - 1 || qs > qe)
	{
		cout << "Invalid Input";
		return -1;
	}

	return getMaximumUtil(arr, st, 0, n - 1, qs, qe, 0);
}


int main()
{
    int arr[] = {1, 3, 2, 7, 0, 11};
    int n = 6;
    int * st = constructST(arr, 6);
    cout << getMaximum(arr, st, n, 0, 5);

    return 0;
}
