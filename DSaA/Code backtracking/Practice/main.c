#include <stdio.h>
#include <math.h>
//bài đếm số cách xếp n con hậu vào bàn cờ nxn k ăn nhau
int n = 5;
int re[100];
int count = 0;

void handleResult()
{
    count++;
    printf("Result #%d: ",count);
    for(int i = 1; i <= n; i++)
    {
        printf("%d",re[i]);
    }
    printf("\n");
}

void try(int k)
{
    int end = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < k; j++)
        {
            if(i == re[j])
            {
                end = 1;
                break;
            }
            if(fabs(k - j) == fabs(i - re[j]))
            {
                end = 1;
                break;
            }
        }
        if(end == 1) 
        {
            end = 0;
            continue;
        }
        re[k] = i;
        if(k == n) handleResult();
        else
            try(k + 1);
    }
    //xác định tập candidate Sk-> tìm cách viết chạy từng phần tử của Sk(->soát điều kiện đủ thì kết thúc
    //k thì chạy tiếp->backtrack nếu ngõ cụt)
    //tránh nhầm lẫn các biến k,n,i,j=> nhớ rằng backtrack+recur giúp ta rút gọn nhiều vòng for
}

int main()
{
    try(1);
    printf("Sum: %d",count);

    return 0;
}



