#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long maxValue(long arr[], long x, long y) {
    if(x == -1)
        return y;
    if(y == -1)
        return x;
    return (arr[x] > arr[y]) ? x : y;
}

long getMid(long s, long e) { 
    return s + (e - s)/2; 
}

long constructSTUtil(long arr[], long ss, long se, long *st, long si)
{
	if (ss == se){
		st[si] = ss;
		return ss;
	}
	long mid = getMid(ss, se);
	st[si] = maxValue(arr, constructSTUtil(arr, ss, mid, st, si*2 + 1), 
	        constructSTUtil(arr, mid + 1, se, st, si*2 + 2));
	return st[si];
}

long *constructST(long arr[], long n)
{
	long x = (long)(ceil(log2(n)));
	long max_size = 2*(long)pow(2, x) - 1;
	long *st = new long[max_size];
    
	constructSTUtil(arr, 0, n-1, st, 0);
	return st;
}

long getMaximumUtil(long arr[], long *st, long ss, long se, long qs, long qe, long si)
{
	if (qs <= ss && qe >= se)
		return st[si];

	if (se < qs || ss > qe){//return giá trị gì mà loại bỏ được đi
		return -1;
	}
	
	long mid = getMid(ss, se);
	return maxValue(arr, getMaximumUtil(arr, st, ss, mid, qs, qe, 2*si + 1),
		    getMaximumUtil(arr, st, mid + 1, se, qs, qe, 2*si + 2));
}
long getMaximum(long arr[], long *st, long n, long qs, long qe)
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
    long n;
    long b;
    cin >> n;
    long arr[n];
    cin >> b;
    for(long i = 0; i < n; i++){
        cin >> arr[i];
    }
    long *st = constructST(arr, n);
    long max1 = 0, max2 = 0;
    long finish = 0;
    long res = 0;
    for(long i = 1; i < n - 1; i++){
        if(arr[max1] - arr[i] >= b){
            max2 = getMaximum(arr, st, n, i + 1, n - 1);
            if(arr[max2] - arr[i] >= b){
                finish = 1;
                if(arr[max1] - arr[i] + arr[max2] - arr[i] > res){
                    res = arr[max1] - arr[i] + arr[max2] - arr[i];
                }
            }
        }
        else{
            if(arr[max1] < arr[i]){
                max1 = i;
            }
        }
    }
    if(finish == 0){
        cout << -1;
        return 0;
    }
    cout << res;

    return 0;
}

