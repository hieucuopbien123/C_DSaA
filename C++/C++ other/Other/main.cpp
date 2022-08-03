#include <stdio.h>

int main()
{
	char a = 10;
	char b = 'b';
	printf("%c\n%s",b,"abc");//phải đúng thứ tự và nó là ký tự hay số đc k là do ta, nh TH k đc
	//hàm %c là ký tư,%d là decimal,%s là chuỗi kí tự;%e,E là ký hiệu khoa học,f là chấm động,x là hexa,0 là octa,%u là unsigned integer,%l long
	//X là hexa và các chũ cái viết hoa,hd là short int, tương tự lli long long int;g,G thì giống e,E nhưng k có số 0;
	//%p là giá trị con trỏ
	//file.c-(compiler)->hello.0-(link library)->hello.exe
	//kí hiệu hexa bắt đầu bằng 0x,octa là 0

	printf("%9.3f\n",45677433.67576);//số đầu tiên trước dấu chấm là tổng kí tự xuất hiện, nếu nhiều hơn thì tạo khoảng trống bên trái, nếu thêm - thì thành
	//bên trái. Số sau dấu chấm là phần thập phân; nếu số trước dấu chấm nhỏ hơn số thì sẽ in hết
	printf("%*.*f\n", 7, 2, 98.736);//điền vào *
	printf("%9d\n",466);//tự cách phần nguyên ra tương tự, chỉ là với d thì k có số sau dấu chấm
	//với string thì tương tự, số trước dấu chấm là khoảng cách căn lề mong muốn(chữ cx chiếm k trống), còn sau dấu chấm thì là số lượng kí tự hiển thị
	printf("%30.11s", "Happy Birthday");
	//thêm # ngay sau % hiển thị kèm 0 or 0x vs octa,hexa,còn vs floatingpoint number thì ép có phần thập phân
	double uio = 10.123;
	printf("%#f", uio);

	int c;
	scanf_s("%d",&c);//nhập lưu vào b
	//dùng _s or bỏ warning, buộc có & từ đối số 2 trở đi

	//trong c ta dùng con trỏ mà k cần new vẫn đc
	//dùng sizeof trả về %ld khi in ra printf, sai kiểu là lỗi
	
	register int d = 10;
	//register là kiểu biến lưu trên thanh ghi. Thông thường, nó phải nạp GT vùng nhớ chứa biến.register r ALU xử lí nó rồi bắn lại ra vùng nhớ chứa biến bên ngoài(RAM)
	//(ALU là nơi chuyên xử lí số học đó).Nếu dùng register no sẽ đặc cách lưu vào 1 vùng trong thanh ghi luôn. Như v sẽ bỏ qua bước lưu vào thanh ghi r lại trả ra bộ nhớ
	//bên ngoài làm tăng hiệu suất. Nhc điểm: số lượng thanh ghi k nhiều nên k dùng dc nh

	volatile int* a1;
	int volatile b1=5;
	int i = 5;
	printf("%d%d%d", i, i++, ++i);
	printf("%d%d%d", b1, b1++, ++b1);
	//biến này có lợi trong ngoại vi, đa luồng,... ta sẽ hiểu về no khi học đến hợp ngữ
	//nó cho phép dùng giá trị trực tiếp từ thanh ghi

	union testUnion
	{
		short a;
		int b;
	};
	testUnion test;
	test.a = 4;
	test.b = 10;
	printf("\n%d\n", test.a);
    //union là 1 lớp giúp tiết kiệm bộ nhớ vs CT có dữ liệu nhỏ.Struct thì nó bằng tổng các kích thước bên trong thậm chí lớn hơn do Aligment Struct, còn Union sẽ
	//mang kích thước của biến có kiểu dữ liệu lớn nhất bên trong.Do cơ chế dùng chung 1 ô nhớ lớn nhất đó dẫn đến union giúp tiết kiệm bộ nhớ. Khi ta đã khai báo
	//các biến thì chỉ dùng đc 1 biến ở 1 thời điểm runtime. Dùng xog r ms đc dùng biến khác.Như v k khác 1 biến đổi tên là mấy. 
	
	//0x... là hexa, 0... là octa,\" và \',%%,\\

	rewind(stdin);
	char f = getchar();
	putchar(f);

	rewind(stdin);
	char str[50];
	printf("Enter a string : ");
	gets_s(str,10);

	puts(str);//hàm puts cũng in ra màn hình cái gì đó nhưng k có string "" như printf
	printf("You entered: %s\n", str);
	//thao tác với file thì các hàm thêm f đằng trc

	//pb | & là thao tác với bit theo phép logic mathI còn && và || là bth và hoặc. Tương tự thì >> << là phép dịch bit, ~ đảo ngc bit, ^ là XOR
	//Ví dụ C= A<<2; với A 100 thì C là 10000, các bit trái phải là số 0
    
	//phép if(a=) trả về GT của a nhưng lại theo kiểu bool. Nếu a=9 thì ở đây là true đk if xảy ra

	int x = 20;
	printf("%d %d %d ", x, x++, ++x);
	x = 20;
	printf("%d %d %d ", x, ++x, x++);
	//cái này là undefined behavior, k có 1 thứ tự thực hiện chuẩn nào cho nó hết, k nên dùng như v.


	//các thư viện có c đằng trc là c++ còn .h là chuẩn c, trong c ta buộc dùng chuẩn. Vd ctime time.h cmath mth.h
	return 0;
}
