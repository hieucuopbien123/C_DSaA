#include <stdio.h>
#include <stdlib.h>

int doublePointer(int** a){}
int onePointer(int* a[10]){}//int*a[10] or int*a[] đều đc
int noPointer(int a[][11]){}//truyền mảng vào hàm bh cx khuyết slg ptu

int main()
{
    int **a;
    int *b[10];
    int c[10][11];
    //3 cái này có sự khác biệt vì tĩnh thì có vùng nhớ còn động thì lơ lửng. Ta coi là đã
    //khai báo bh sẽ truyền vào mảng.Do mảng tĩnh có kích thước cố định khác với con trỏ nên
    //coi là 2 kiểu khác nhau.Tức int(*)(10) khác với int(*)(*)
    //khác mảng 1 chiều,mảng 2 chiều phải tuân thủ đúng cú phát=>truyền cả a vào hàm có 3 TH
    doublePointer(a);
    onePointer(b);
    noPointer(c);

    return 0;
}
