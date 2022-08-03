#include <iostream>
using namespace std;
int n, count,k;
int a[100], s[100];
void PrintSolution() 
{
    int i, j;
    count++;
    cout << "String # " << count << ": ";
    for( i=1 ; i <= n ; i++) 
    cout << a[i] << " ";
    cout << endl;
}

//mảng có {0,1,3}
void GenerateString()
{
    k=1;
    s[k]=0;
    while(k > 0)
    {
        while(s[k] <= 3)
        {
            a[k] = s[k];
            if(s[k] != 1)
            s[k] = s[k] + 1;
            else{
                s[k] += 2;
            }
            if( k == n )
            PrintSolution();
            else
            {
                k++;
                s[k]=0;
            }
        }
        k--; // BackTrack
    }
}
int main()
{
    cout << "Enter value of  n = ";
    cin >> n;
    count = 0;
    GenerateString();
    cout << "Number of strings = " << count << endl;
    return 0;
}
