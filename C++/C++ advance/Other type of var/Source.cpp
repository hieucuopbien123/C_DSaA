#include "Header.h"
#include "testError.h"

using namespace std;

class A
{
public:
	static int a;
};
int A::a = 10;

extern int ab;
int ab = 80;

int main()
{      
	//testError test1;
	//testError test2;
	//cout << test1.getError();
	
	A l;
	cout << l.a << endl;

	cout << testError::error2;
	testError abcd;

	b = 9;
	cout << b << endl;

	cout << abcd.teststatic << endl; 

	cout << b << endl;

	cout << ab << endl;

	cout << abcd.testextern << endl;
	
	//phân biệt marco,static, biến toàn cục, biến cục bộ,extern.Với 3 TH dùng chung 1 file, chia ra 2 file h và cpp,
    //có hàng loạt file cpp và h nhưng nó include cái file h chứa extern r,tạo nhiều đối tượng khác nhau refer đến biến tĩnh và toàn cục
    
	//Ở đây ta chỉ xét TH dùng khi có include file chứa biến or truyền nó vào hàm thì với từng loại biến sẽ có đặc tính riêng

	//Biến cục bộ ta k cần nói vì ez

	//marco/const phải khai báo GT ngay lập tức(marco tạo biến k nên dùng, nếu có thì chỉ dùng chung trong cùng 1 file cpp mà thôi,các TH khác gây lỗi)
	//dùng thoải mái trong cùng file or sang file cpp khác cũng thoải mái, tự do như biến toàn cục nếu khai báo toàn cục.

	//biến toàn cục=>lỗi thg sai: chỉ dùng trong cùng 1 file cpp, nếu dùng một nơi khai báo 1 nơi khác file sẽ lỗi=>nếu dùng 1 biến cho nh file thì 
	//đừng có khai báo mỗi int hay j k thôi vì lối


	//như v ta nếu ta muốn khai báo 1 biến mà dùng xuyên file thì buộc là const, nếu ta muốn thay đổi GT biến mà dùng xuyên file thì...=>static,extern
	//biến static:có biến toàn cục static, biến class static(giống hàm có biến static), hàm static. GT của nó refer lúc nào cx đc
	
	//biến static trong hàm or là 1 thành phần của class.TH1:là cả class và main trong cùng 1 file=>biến static chỉ bị hủy khi kết thúc CT,mọi đối tượng
	//class đều dùng chung 1 biến static=> cx vì v nên ta buộc khai báo GT của biến static ngoài class bằng kiểu dữ liệu và tên class kèm toán tử phân giải
	//phạm vi. Dung thì ta dùng kèm biến class cụ thể dù chúng đều như nhau, nếu là public thì có thể <tên class>::<tên biến static> luôn 
	//TH2: lớp khai báo ở file khác, khai báo static vẫn v ở trong file cpp của class đó, k đc khai báo trong file h. Tính cục bộ thể hiện ở chỗ,chỉ đc dùng
	//như biến cục bộ, ví dụ khai báo trong hàm thì chỉ đc dùng trong hàm đó, tính toàn cục là tồn tại theo vòng đời hàm main.
	//class thì k đc khai báo ngay GT static vì..., còn hàm thì đc
    //(khai báo ngoài class mà là con trỏ thì cx v, VD: int* testError::a=nullptr; k đc khai báo trong constructor mà ở bên ngoài)

	//biến static khai báo toàn cục.TH1 là biến toàn cục bth thì như bth.
	//TH2: ta tạo 1 file h khai báo biến static, rồi include nó vào các file khác mà dùng=> biến static nó toàn cục nhưng vẫn chưa đủ mạnh để ta thao tác 
	//xuyên các file cpp với nhau.Mỗi lần file cpp(or 1 class có h và cpp) nào ta dùng biến static thì biến đó đc coi như mới luôn cho từng đối tượng đó. 
	//Dù ta có gán GT ban đầu hay k cx thế(nếu k gán sẽ mặc định là 0). Ví dụ ta vào file main ta gán nó =1; vào file cpp của class nào khác dùng nó thì coi
	//như 1 biến static mới khác ra đời như ban đầu, GT của nó k phải 1;

    //hàm static giống biến static.trong class thì mọi đối tượng sở hữu chung 1 hàm đó. Có thể truy cập hàm đó bth or dùng toán tử phân giải phạm vi với
	//tên class, thg chỉ dùng thao tác với các đổi tượng static của class.Hàm static bth cx v thôi(khai báo thì k đc chứ class ở file khác thì static vẫn ok)

	//Như v, static vẫn chưa đủ mạnh thao tác xuyên tất cả các file. Để làm đc ta dùng extern.
	//hàm này k dùng trong class hay cục bộ mà dùng toàn file.Th1: là dùng trong file main, thế chả khác j biến toàn cục nguyên thủy.ta dùng vd extern int a;
	//ta có thể khai báo gt luôn or k đều đc. Khi dùng extern ta thg k khai báo gt luôn mà chỉ declare nó ra rồi sau đó khai báo GT sau bỏ extern(VD file này)
    //TH2: dùng ở các file khác=> cũng là cách dùng ở mọi file cùng 1 biến trong 1 dự án=>ta khai báo extern trong 1 file h,r include nó ở bất kì file nào
	//khác nếu muốn dùng. Để kích hoạt vc sử dụng thì vô file có hàm main và khai báo bth bỏ từ khóa extern đi(các file cpp kia k cần làm nv, chỉ cần trong
	//main),khi dùng nv thì chỉ đc khai báo GT ban đầu ở hàm trong main kia thôi, k đc khai báo GT trong file h định nghĩa(vào file h khai báo extern k gán Gt
	//ra file main khai báo k có extern gán GT, dùng ở mọi file)


	return 0;
}