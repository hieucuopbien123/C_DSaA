#include <stdio.h>

//tìm UCLN:theo ô ơ clit thì UCLN(a,b) mà a=jb+k thì =UCLN(a-b,b) với b<a
//điều kiện trùng: trùng thuật toán là ucln(a,b)=ucln(a-b,b) nếu a>b và =ucln(b-a,a) nếu b>a
//điều kiện dừng a==b->đặt đệ quy trong return là bao hết TH
//đối số 2 số
int ucln(int a, int b)
{
    if(a == b)
    {
        return a;
    }
    if(a > b)
    {
        return ucln(a-b,b);
    }
    else
    {
        return ucln(b-a,a);
    }
}

//Tính P(n)=1.3.5...(2n+1): cơ chế nhập n vào và trả ra p(n)
//điều kiện trùng: phép toán->BT: P(n)=(2n+1)P(n-1)
//điều kiện dừng: n giảm xuống ==0
//đối số: truyền vào n và trả ra giá trị p(n)
int caculateP(int n)
{
    if(n == 0)
    {
        return  1;
    }
    return caculateP(n-1)*(2*n+1);//đệ quy tuyến tính-> fibonacii là đệ quy nhị phân// có thể đệ quy lông
}

//kiểm tra xem n có toàn chữ số lẻ hay k: cơ chế truyền vào 1 số và trả ra 1 là nó toàn lẻ, 0 nếu có chẵn
//điều kiện trùng:phần tử->1 phần tử r 2 phần tử r n phần tử->qh: nếu 1 phàn tử lẻ->thì nó *10+phần tử 2 cx lẻ ...
//=>điều kiện trùng nên đi từ lớn đến nhỏ chứ đừng đi từ nhỏ đến lớn như này của qhđ
//điều diện dừng:ta nên đi từ lơn đến nhỏ thì dừng khi n==0-> ta /10 liên tục->hàm ở return
//đối số:1 biến, trả về là 0 hay 1
//CL: bài toán con, kiểm tra n lẻ k, nếu lẻ trả về 1, ngc lại thì 0->bài toán mẹ: giả sử 2 phần tử,kiểm tra nếu
//1 phần tử bằng 1 thì return 1, nếu k thì kiểm tra 2 phần tử tương tự=>vc đi từ con đến mẹ ms là điều qtr
//cả qhđ và đệ quy: bài toán con là gì, bài toán mẹ giải ntn, áp dụng từ con giải mẹ ntn
int isEachOdd(int n)
{
    if(n == 0)
    {
        return 1;
    }
    if(n%2 == 0)
    {
        return 0;
    }
    else
    {
        return isEachOdd(n/10);
    }
}

//tính giai thừa vs đệ quy
//điều kiện trùng: f(n)=n*f(n-1)
int factorial(int n)
{
    if(n == 1)
    {
        return 1;
    }
    return factorial(n-1)*n;
}

//tính căn x: cơ chế chia đôi và test ss vs sai sô
//điều kiện trùng: phép toán chia đôi trùng và ss
//điều kiện dừng: ss nếu mid*mid-val<err thì dừng->hàm ở trong return
//đối số: để tính mid thì chỉ cần low , high; để ss cần val
//CL:bài toán con: tính mid từ low và high để ss->ss r gán low or high->truyền lại vào hàm và tính tiêp
double mySqrt(double low, double high, double n)
{//tùy biến đc, nó tương tự như binary search
    double mid = low + (high - low)/2;
    if(fabs(mid*mid - n) < 0.00001)
    {
        return mid;
    }
    if(mid*mid - n > 0)
    {
        high = mid;
    }
    else{
        low = mid;
    }
    return mySqrt(low,high,n);
}

//tính tổ hợp bằng đệ quy
int C(int a, int b)
{
    if(a > b)
    {
        return 0;
    }
    double dA = a, dB = b;
    if(a == 1)
    {
        return b;
    }
    return ((dB - dA + 1)/dA)*C(dA - 1,dB);//tính chú ý khi có phép chia phải đổi
    //vì ta cần thực hiện phép chia nên ta cần double như v là đc, vc truyền lại vào hàm C(int) thì k lo vì chắc
    //chắn số đó là int. Ta chỉ cần biết chỗ nào có phép chia thì hoặc là cast (double) trước phép chia thì nó
    //sẽ thực hiện cast r mới tính, hoặc là ta làm như trên là đổi sang double trc r mới cho tính toán
}

int main()
{
    //kinh nghiệm: khi ta return func(); tức là ta chỉ muốn lấy 1 kết quả cuối cùng vs phần tử nhỏ->nhưng nó lại
    //giúp ta duyệt qua tất cả các phần tử để làm gì đó cx đc; Còn return func()*n; thì giúp ta lấy phép toán chuỗi
    //có quy luật tính toán như nhau; Nhưng điều đó còn phụ thuộc vào điều kiện trùng là gì, nếu đk trùng là phần
    //tử thì vc return func() sẽ giúp ta duyệt qua mọi phần tử trong nó, duyệt qua các TH khi chia ra
    
    //điều kiện trùng nhau và điều kiện dừng->chia nhỏ:thuật toán->biểu thức or số lượng->từ nhỏ đến lớn có qh j
    /*//Tìm UCLN
    int a,b;
    printf("Input to find GCD: ");//bcnn là LCM
    scanf("%d %d", &a, &b);
    printf("GCD: %d", ucln(a,b));*/
    
    // /*//Tính P(n) CB
    // int a = 0;
    // printf("Input to find P(n): ");//bcnn là LCM
    // scanf("%d", &a);
    // printf("ấdf");
    // printf("P(n) = %d", caculateP(a));*/
    
    /*//kiểm tra xem n có toàn chữ số lẻ hay k
    int n = 0;
    printf("Input n: ");
    scanf("%d",&n);
    printf("n is each odd: %s",(isEachOdd(n)) ? "true" : "false");*/
    
    /*//tính giai thừa
    printf("factorial: %d\n", factorial(10));*/
    
    /*//Tính căn
    printf("Sqrt of 10 is %lf", mySqrt(1,10,10));*/
    
    return 0;
}

//CL 2 bước: 1)tìm điều kiện đi từ mẹ đến con bao mọi TH; 2) Tìm điều kiện dừng khi đi nv
