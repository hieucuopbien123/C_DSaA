#pragma warning(disable:4996)//lỗi này là kiểu nhập vào nhưng sợ ko đủ bộ nhớ cấp phát từ trc hoặc yêu cầu dùng hàm mới sẽ khắc\
phục lỗi. Nếu như ta k sợ bộ nhớ thiếu thì bỏ qua

//#define _CRT_NONSTDC_NO_DEPRECATE //tránh lỗi về CRT file, or dùng các hàm cũ warning như trên

//tiền xử lý bỏ qua lỗi về 1 số hàm
//cách 2 
//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif
#include <fstream>//bao gồm ifstream và ofstream
#include <conio.h>
#include <iostream>//chứa cả istream và ostream
#include <cstring>
#include <string>//hàm getline
#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()

using namespace std;
using std::cin;

bool CheckFileExist(const string& name)
{
	bool is_exist = true;
	ifstream file;//tính năng này ở trong ifstream,cx có nghĩa là cả trong fstream
	file.open(name, ios::in);//out,binary,ate,app,trunc
	cout << ios::in << ios::out << ios::binary << ios::ate << ios::app << ios::trunc << endl;
	//các giá trị này ko thể hiện j cả(bitmask), qtr là tác dụng của nó với file. Chỉ cần nhớ cái qtr là:
	//in thì mở để đọc;out mở để ghi đè từ đầu+ko có thì tự tạo=> ta nên dùng app tốt hơn vì nó ghi tiếp cuối file;trunc thì ghi lại.
	if (!file.is_open())//is_open, nếu stream liên kết đc vs file thì true
	{
		is_exist = false;
	}
	else
	{
		is_exist = true;
	}
	/*
	Khi ta code với stream, 1 istream hoặc ostream thì sẽ có ios là một class có data và function. Đó là một class cha có hai class
	con là istream và ostream kế thừa.Nó có thuộc tính là error_state và function là good(),bad(),eof(),fail(). Trong đó thì
	eof(), trả về điều kiện đọc đến ký tự EOF cuối dùng của 1 file, fail()và bad() trả về 1 nếu lỗi. Còn good() bị phụ thuộc.
	Flag là cờ, tức là hai giá trị đúng và sai(1 and 0, có và k,...). Bất cứ loại dữ liệu hay biến nào chỉ có hai lựa chọn thì
	đều có thế gọi là "bật cờ(gán 1)" or "tắt cờ(gán 0)" cho nó. 4 hàm trên cũng là hàm gắn cờ với kiểu trả về là cờ 1,0,true,
	false, đó là kiểu iostate trong class ios, hiểu là hàm trả về trạng thái cờ lỗi bên trong một luồng(stream),luông này đc
	tạo ra khi ta có một đối tượng thuộc kiểu dữ liệu trong iostream library.
	Thư viện iostream của c++ thực chất có rất nhiều thư viện khác và cũng chỉ là 1 lớp thư viện con của lớp lớn nhất là ios
	ví dụ fstream(thao tác vs file) cx là một thư viện con của ios, các thư viện này sẽ cung cấp các hàm input output dữ liệu.
	Khi thao tác với 1 stream ta sẽ luôn có 4 hàm trả về flag, mà giá trị của chúng phụ thuộc vào 4 loại bit badbit,goodbit,eofbit
	và failbit. 4 bit loại này là giá trị của iostate, nó thuộc kiểu bitmask(1 kiểu integer) dùng được kiểu toán tử bitwise-1 loại
	thao tác trên bit(AND,XOR,...).(khi ta cout << sẽ ra số nguyên cố định ko đổi). Thực chất 4 loại bit trên nó cứ như 1 hằng
	số khi cout v,giá trị quan trong là flag. Mỗi đối tượng luồng stream sẽ có 4 bit riêng thể hiện flag của riêng đối tượng
	Khi ta muốn xem trạng thái của tất cả 1 lúc, ta dùng biến rdstate(),nó là một hàm trả về kiểu bitmask là tổng của 3 bit trừ
	goodbit, giống môn Linux gán quyền.Ta có goodbit=0, failbit=1, eofbit=2, badbit=4.Cái nào turn off thì x 0, on thì x1 r cộng lại
	goodbit chỉ true nếu ba cái kia false, khi đó rdstate()=0
	Có một bảng chỉ ra mối quan hệ giữa chúng nhưng ta chỉ cần quan tâm rằng goodbit giống với good(),tương tự chỉ có mỗi fail()chỉ
	=0 nếu failbit và badbit cùng =0(k xh lỗi)
	Mối quan hệ giữa good(),bad(),eof(),fail().bad() là true nếu có lỗi khi read or write lien quan đến i/o operation.Fail() sẽ
	turn on khi sai về mặt logic (tìm file ko có,điền sai kiểu ký tự ,...) và nó cx true nếu bad() true(cứ có lỗi là nó true),eof()
	turn on khi gặp ký tự EOF,kết thúc 1 file.(EOF là một ký tự trong window là ctrl+z và cx là ký tự kết thúc file).good()
	đúng khi tất cả cái kia đều là 0, ko có lỗi gì cả và file ko đọc or chưa đọc xog.
	*/
	cout << ios::goodbit << ios::badbit << ios::eofbit << ios::failbit << endl;
	ios::iostate flags = file.rdstate();

	file.clear();
	cout << file.bad() << file.fail() << file.eof() << flags << file.good() << endl;//cout chỉ ra 1 số mỗi loại chú k phải 4 số 0000 đâu
//0000 chỉ là GT ios:: dạng nhị phân thôi, thực chất nó chỉ trả ra GT thể hiện bit đó on hay off
	file.setstate(ios::eofbit | ios::failbit);
	cout << file.bad() << file.fail() << file.eof() << file.rdstate() << file.good() << endl;
	//khi dùng setstate dù kéo theo failbit đổi nhưng rdstate vẫn theo lệnh của ta. Các bit này k còn chia theo lỗi nx!
	file.clear(ios::failbit);
	cout << file.bad() << file.fail() << file.eof() << file.rdstate() << file.good() << endl;
	//Đó là tắt cờ trừ bit bất kì.Khi có lỗi và ta tắt cờ thì ct sẽ bỏ qua lỗi và biên dịch tiếp. Bản chất là hàm setstate và 
	//clear là 1; chỉ khác ở chỗ setstate bắt buộc truyền đối số. .4 loại "bit" này thuộc 1 enum iostate { goodbit=0, failbit=1, 
	//eofbit=2, badbit=4 } ở dạng nhị phân thì goodbit là 0000, eofbit là 0001, failbit là 0010, badbit là 0100. Do đó dùng toán 
	//tử bitwise để truyền

	cout << (file.eof() & file.fail()) << endl;// dùng toán tử bitwise với kiểu có flag
	file.close();
	return is_exist;
}
istream& Test_cin(istream& is)//k tạo biến istream đc vì k biết constructor. nếu ta tạo biến stream gán từ cin thì cx k đc vì k gán đc
{//phải truyền là istream có & thì ms cho cin vào đc
	return is;//GT trả ra phải có & thì ms return dc, nó nhất quyết k cho copy biến istream hay tạo biến ms, chỉ có thể dùng địa chỉ
}
void MethodToReadFile(const string& name)
{
	fstream file(name, ios::in);//tắt hàm open
	int begin = static_cast<int>(file.tellp());
	file.seekp(0, ios::end);
	streamoff end = file.tellp();
	file.seekp(0, ios::beg);
	char* input = new char[end - begin]{};//hack bộ nhớ
	__int64 i = 0;//kiểu nguyên vô cùng lớn
	if (!file.is_open())
	{
		perror("Cannot read file!");
	}
	else
	{
		while (!file.eof())
		{
			file.get(input[i]);//lỗi ngớ ngần, input đủ rộng để gán r, ko lo
			i++;
		}
		cout << input;
	}
	//vì cout << input bị dính lỗi *2 ký tự cuối khi nhập bằng get()
	//dùng getline ko thể lưu nội dung đc ra ngoài hàm
	//nếu mang ra ngoài thì gán con trỏ vs 1 mảng khác tạo ra để delete con trỏ đi
	// với file text quá nhỏ 1 dòng thì gán \n vào ms hết lỗi in giá trị rác.Chỉ nên dùng in file nh dòng
	file.close();
}
void PerfectMethodToReadFile(const string& name)
{
	char input[5000]{};
	fstream file;
	file.open(name, ios::in);
	int i = 0;
	if (!file.is_open())
	{
		cout << "Cannot read file!";
	}
	else { file.read(input, sizeof(input)); }
	cout << input;
	//thực chất đây là hàm đọc file binary nhưng nó lại hoạt động hiệu quả với file text bth nên lấy luôn. Nêu ta dùng con trỏ thì 
	//k dc sizeof(contro) vì nó luôn là 4 byte, ta k refer đến toàn bộ mảng con trỏ đc nên buộc đặt số cụ thể.Ta có thể mở rộng 
	//thành truyền vào 1 đối số nx là kích thước mảng con trỏ với file dài ngắn khác nhau để tối ưu ô nhớ. lấy đc nd ra ngoài.
	//tuy nhiên ép dùng mảng với cách này. Nếu lấy ra ngoài dùn cách này, xuất k thì dùng cách trên.Đọc file lớn dùng c1, nhỏ dùng perfect
	file.close();
}
void ReverseReading(const string& name)
{
	fstream file(name, ios::in);
	int begin = file.tellp();//ko hoàn toàn là int chính thống nên cảnh báo
	file.seekp(0, ios::end);
	int end = file.tellp();
	char* input = new char[end - begin]{};
	int a = 0;
	for (int i = end - 1; i >= 0; i--)
	{
		file.seekg(i, ios::beg);
		file.get(input[a]);
		a++;
		//ta ko nên làm kiểu lùi seekp liên tục vì cái nút enter thì phải lùi 2 lần chưa kể ta còn gán X vào ngay 1 phần
		//nút '\n' ko biết nó đi đâu.Dù cout sizeof \n cx chỉ 1 byte nhưng tốt nhất là cứ vòng for mà ốp
	}
	for (int j = 0; j < a; j++)
	{
		cout << input[j];
	}
	file.close();
}

void WriteFilec2(FILE* file)
{
	fputc('A', file);
	fputs("Hello", file);
	fprintf(file, "Chung\nH");//ghi cả đoạn văn
	//con trỏ để ở cuối chỗ ghi
	fseek(file, 0, SEEK_SET);
}
void ReadFilec2(FILE* file)
{
	/*cout << (char)fgetc(file) << (char)fgetc(file) << (char)fgetc(file) << endl;*/
    //con trỏ dịch sang ký tự tiếp theo nhưng con trỏ trên console bị ngc,in ngược

	char str[5];
	//cout << fgets(str, 4, file) << endl; //đọc sẽ dừng khi gặp \n//đọc lưu vào str
	while (fgets(str, 4, file) != NULL)//cout toàn bộ file luôn nhé, đâylà perfect
	{
		cout << str;
	}
	cout << endl;
	//char str1[2];
	//fscanf(file, "%[^\n]", str1);//hàm này bị lỗi
	//cout << str1 << std::endl;
}
void ReadFilec2w(FILE* file)
{
	wchar_t str[5];
	while (fgetws(str, 4, file) != NULL)
	{
		wcout << str;
	}
	wcout << endl;
}
void WriteFile_Bi(FILE* file)
{
	char* s = new char[10]{"Hello"};
	fwrite(s, strlen(s), 1, file);//số 1 là chép 1 lần
	fseek(file, 0, SEEK_SET);
}
void ReadFile_Bi(FILE* file)
{
	wchar_t* ptr = new wchar_t[100]{};
	fread(ptr, 100, 1, file);//hàm trả kiểu size_t
//copy 1 lần kích thước 100 từ file vô vùng nhớ đc quản lí bởi địa chỉ đầu tiên là ptr
	cout << ptr << endl;// tự for ra
}

int main()
{
	/*bool File_Demo_Exist = CheckFileExist("demo.txt");
	if (File_Demo_Exist)
	{
		cout << "demo.txt is exist\n";
	}
	else
	{
		cout << "demo.txt is not exist" << endl;
	}*/

	//fstream file{ "D:/C++/Visual Studio/Basic C++ Visual Studio/NQH.txt" };
//gán cho 1 file or bỏ trống chỉ cấp vùng nhớ.Mặc định là ios::out.Dấu gạch chéo / bị ngược vs link bth
	//if (file.fail())
	//{
	//	cout << "Failed to open this file!" << endl;
	//	return -1;
	//}

	//	cin.setstate(ios::badbit | ios::eofbit);//ở trạng thái này cin sẽ lỗi và kết thúc ct nếu ta dùng cin ở lệnh kế
	//	cin.clear();//bh thì dùng đc r
	////bản chất cin cx là một đối tượng luồng nằm trong thư viện istream bên trong iostream. Như v nó cx có các 4 loại bit chỉ trang
	////thái hoạt động. Ví dụ khi ta cin một char vào kiểu integer thì khi dùng cin lần kế sẽ lỗi. khi đó cin.fail()=1. Chính vì vậy,
	////khi cin xog 1 đoạn văn bản ng ta thg dùng combo cin.clear();+cin.ignore();đề phòng ng nhập ký tự sai.Nếu ko có cin.ignore()
	////thì dù đã hết lỗi thì cin vẫn có thể tiếp tục đọc ký tự sai tiếp theo. Ta ko thể tạo 1 biến istream đc hoặc do chưa đủ trình

	//	int m;
	//	cout << "M: ";
	//	Test_cin(cin) >> m;
	//	cout << sizeof(int) << sizeof(std::ios::iostate) << sizeof(ios::goodbit) << endl;//đều 4 byte cả kiểu bitmask ~ int

	/*fstream file_ios;
	file_ios.open("demo.txt", ios::out);
	cout << endl << file_ios.tellg() << file_ios.tellp() << endl;
	file_ios << "nguyen thu hieu\n" << "ict 01\n";//lưu vào string r gán cx ok
	file_ios.put('m');//ngc với get()
	file_ios.close();
	file_ios.open("demo.txt", ios::in);
	//hàm close() chỉ đóng file. file_close vẫn đc cấp bộ nhớ và trở thành k lưu j cả, dùng tiếp
	//ko thể vừa có nhập và xuất,nếu muốn xuất thì tạo riêng ra.
	char input{};
	while (file_ios >> input)//gán từng kí tự
	{
		cout << input;
	}
	//toán tử >> với file sẽ lưu từng chữ một vào input, hết chữ này sẽ lưu trữ kế. điều này chỉ hiệu quả khi ép vào vòng lặp while
	//và ta phải cout liên tục trong vòng. nếu như lưu có mỗi 1 phát thì nó sẽ chỉ lưu 1 phần tử, kể cả ta dùng với mảng.
	//ko đúng với ký tự space và enter=>> ko nên dùng, chỉ biết là có 
	
	char input2[100]{};
	while (!file_ios.eof())
	{
		file_ios.getline(input2, 100,'@');
		cout << input2;
	}
	
	file_ios.close();
	//kí hiệu << thực chất là một operator thuộc ios dành cho đối tượng luồng stream. các đối tượng là luồng đều dùng đc và có thể
	//mang ý nghĩa khác nhau, fstream nó hơi ngược với iostream
	//iostream có các function riêng dành cho các biến có kiểu thuộc iostream(các đối tượng stream cin,cout,endl,...).do nó là một
	//lớp nên ta truy cập bằng bằng dấu chấm.vd good(),eof(),getline(,,)
	//khác với cin.getline(,,@) ký tự bỏ @ sẽ lấy làm ký tự kết thúc việc nhập. file.getline sẽ chỉ bỏ qua ký tự đó.đưa vào vòng
	//lặp get đến cuối ko thì chỉ get 1 dòng
	PerfectMethodToReadFile("demo.txt");
	cout << endl;
	*/

	///*cout << ios::beg << ios::end << ios::cur << endl;*/
	//fstream ipf("demo.txt", ios::out | ios::in);
	//ipf.seekg(23, ios::beg);
	//ipf.put('X');
	//ipf.close();
	//MethodToReadFile("demo.txt");
	//khi ta gọi 1 file nào vs phương thức nào đó thì luôn có 2 con trỏ là đọc và viết, theo mặc định nó luôn trỏ vào vị trí đầu tiên
	//là vị trí 0 ở beginning.Đó là vị trí bắt đầu đọc và viết trong file. Có một trường hợp ngoại lệ ! là ios::app khi khai báo file
	//thì con trỏ vẫn v nhưng nó lại ghi tiếp vào cuối file, ko bị ảnh hưởng bởi vị trí con trỏ dù ta có thay đổi vị trí.ios cung cấp
	//hàm tellg(),tellp() để xem vị trí con trỏ, cung cấp cả seekg(),seekp() để thay đổi vị trí. Có 3 vị trí bắt đầu đổi là beg,cur,end
	//Tuy nhiên nếu ta dùng hàm out thì khi thay đổi vị trí để them văn bản vào file sẽ xóa sạch file trc, vì v, để ghi thêm vào ta 
	//dùng ios::out|ios::in sẽ ghi tiếp ko xóa, nhưng ta chỉ dùng để ghi thôi. ta sẽ k ghi đc nếu con trỏ ta âm vị trí, vị trí âm k hiện
	//dấu enter là 2 ký tự LF+CR.con trỏ tăng 2 khi đọc.
	//con trỏ đọc luôn đi với con trỏ viết ở cùng một vị trí=> đổi vị trí 1 con trỏ con trỏ còn lại cx tự đổi theo.Khi đọc 1 file nhớ
	//là con trỏ đọc phải luôn ở vị trí 0 là vị trí ban đầu muốn đọc.
	//khi ghi file xog con trỏ vẫn ở vị trí cuối mà nó ghi, còn khi đọc file xog con trỏ sẽ tự động về vị trí -1.Do đó sau mỗi lần đọc
	//ta hay chuyển nó về vị trí 0 begin nếu dùng tiếp.
		/*Reverse Reading*/
	//ReverseReading("demo.txt");
	//cout << endl;

	//ta có thể kết hợp hai cách xử lý file nếu tạo ra các hàm truyền vào string
	//FILE* filec2 = fopen("File.txt", "a+");//a(đ),w(g mới),r(g cuối,tự tạo mới),a+(đ,g cuối,tự tạo mới),r+(đ,g),w+(đ,g mới)
	//WriteFilec2(filec2);
	//fseek(filec2, 0, SEEK_SET);//SEEK_CUR,SEEK_END
    //ReadFilec2(filec2);
	//__int64 size = ftell(filec2);

	//WriteFile_Bi(filec2);// dùng đc với cả loại file k binary
	//ReadFile_Bi(filec2);// dùng đc với cả loại file k binary
	//if (remove("File.txt") != 0)//hàm xóa file và báo lỗi=> tự báo lỗi gì
	//	perror("File deletion failed");
	//else
	//	cout << "File deleted successfully";
	//rename("File.txt","newFile.txt");//lỗi ko có quyền giống remove
	//fclose(filec2);
   
 /*   //viết tv vào file
    //_setmode(_fileno(stdout), _O_U16TEXT);
    //_setmode(_fileno(stdin),  _O_U16TEXT);//full w cả project
    FILE* filec2 = _wfopen(L"wFile.txt", L"w+,ccs=UTF-16LE");
	if (!filec2)
	{
		wprintf(L"ERROR: Cannot open file\n");
		return EXIT_FAILURE;
	}
	wchar_t* str=new wchar_t[100];
	wcin.getline(str,100);
	fwprintf(filec2, str);
	fseek(filec2, 0, SEEK_SET);
	ReadFilec2w(filec2);
	fclose(filec2);
    //mọi ký tự khi viết trên đây đều phải có L"..."
*/

    //bổ sung
     int a=0;
     printf("hieu:%d is a number\n",a);//%d thay số điền sau dấu phẩy ngay đằng sau

	 char name[20];
	 sprintf_s(name, "Hello %d and %d", a, 1);
//hàm này lưu cái sau la 1 dạng format của hàm printf, tức là chuỗi "" có chứa %d %s các kiểu, sẽ lưu vào name, là 1 địa chỉ char*
	 cout << name << endl;



//ghi vào 1 file và xuất nó ra bằng tv. Test viết bth,setconsole,setmode
	
	_getch();
	return EXIT_SUCCESS;
}