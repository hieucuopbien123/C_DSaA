//#define _CRT_NONSTDC_NO_DEPRECATE cản lỗi POSIX name is deprecated, hàm ko dùng nx
#include <iostream> 
#include <conio.h>
#include <string>//getline(cin)
#include <iomanip>//set
#include <sstream>//stringstream bao gồm istringstream và ostringstream, thùa kế từ iostream
#include <vector>
#include <cstring>
#include <array>
#include <algorithm>//sort
#include <thread>
#include <string_view>
#include <algorithm>
#include <map>
//#include <typeinfo>//typeid mà ko có cx đc
//#include <exception>//cho exception mà k có cx đc
//#include <fcntl.h> //_O_U16TEXT
//#include <io.h>    //_setmode()//cản log 

using namespace std;

#define END << "\n";

//tạo một namespace riêng nó gồm class, hàm , biến tránh trùng tên(VD namspace std, class ios biến iostate)
namespace StrWrk
{
	class StrWork
	{
	private:
		static int number;
	public:
		static wstring WcharToWstring(wchar_t* wsch);
		//hàm tĩnh chỉ có thể truy cập biến và hàm tĩnh thành viên,hàm bên ngoài.Nó bị giới hạn rất nhiều so với 1 hàm bth
	};
	int StrWork::number = 0;//khởi tạo static giá trị trc khi dùng 
}
namespace StrWrk
{
	wstring StrWork::WcharToWstring(wchar_t* wsch)
	{
		wstring str(L"\0");
		int index = 0;
		number += 1;
		while (wsch[index] != 0)
		{
			str += (char)wsch[index];
			++index;
		}
		return str;
	}
}
using namespace StrWrk;

_NODISCARD double division(int a, int b) //[[nodiscard]] ép giá trị trả về của 1 function phải đc sử dụng khi dùng hàm(k đc bỏ)
{//dùng với mọi hàm để đảm bảo rằng gọi hàm thì phải dùng->sai
	if (b == 0)
		throw "Division by zero!";
	return (a / b);
}
class customexception :public exception
{
private:
	string a;
public:
	customexception(string b) :a{ b } {};
	string whatc() { return a; }
	const char* what()const throw() //throw ở vị trí này cx đc để báo là hàm này k có chức năng throw chứ nó k có vai trò throw dừng CT, chỉ báo v thôi. chỉ đc phép throw các thứ ở bên trong (). Nếu throw(int) khai báo ở đầu hàm thì chỉ đc throw ra int trong hàm; nếu
//throw(int,string) thì chỉ đc throw hoặc int hoặc string; nếu sai thì sẽ abort k bắt lỗi; Hàm what() có throw() để đảm bảo hàm này
//kbh throw cj hết, nếu có throw sẽ abort ngay lập tức=> cx phải vì hàm hiển thị lỗi mà lại lỗi nx sao đc
	{//hàm what() chuẩn trong exception phải tạo có const char ms giống hàm bên trong có virtual
		string error="Cannot divide by 0.";
        	return error.c_str();//đừng quên có c_str() đổi từ string sang const char*
//chuẩn nhất thì trong này là switch case 1 enum error vào lỗi gì thì return khác nhau
	}
};
_NODISCARD double division2(int a, int b)
{
	if (b == 0) {
		throw customexception("Error test division by 0.");
	}
	return (a / b);
}

template <class T1, class T2>
auto mul(T1& a, T2& b) -> decltype(a* b) //nch cứ auto là decltype mặc dù biết k có cx đc
{
	return a * b;
}

void test_lambdafunction(const int& a, void(*func)(int))
{
	func(0);
}
template <class T>
void test_lambdafunction2(const int& a, T b)//nếu b là function cx đc, ta k cần truyền đối số function ở đây cx đc.
{
	b(10);
}

void printArray(const array<int, 10>& arr) noexcept(true) // truyền tham chiếu (hằng) vì hiệu suất và phải cùng số lượng phàn tử
{
	cout << "So phan tu: " << arr.size() << endl; // có thể biết số phần tử ở mọi hàm
	for (const auto& item : arr) // có thể sử dụng for-each loops ở mọi hàm như vector
	{
		cout << item << ' ';
	}
	cout << endl;
}

istream& operator>>(istream& in, float* n)//ostream sẽ thao tác với cout
{
	char name[20]{};
	rewind(stdin);
	in.getline(name, 20);
	cout << name END
		return in;
}

class Person
{
private:
	int a{ 1 };
public:
	operator int()
	{
		return a;
	}
};

constexpr void function(int a)
{
	int b = a;
	return;
}

template <std::size_t N1, std::size_t N2>
constexpr int add_arrays_size(const std::array<int, N1>& a, const std::array<int, N2>& b)
{
	return a.size() + b.size();
}

void dosth(string a)
{
	cout << "hello " << a END
}
void dosth1(char& b)
{
	b = 'b';
	cout << "do1: " END
}
void dosth2(char& b)
{
	b = 'a';
	cout << "do2: " END
}
class testexplicit {
	string iData;
public:
	testexplicit(char c) = delete;//cản trở vc khai báo là char, do tc khởi tạo ngầm thành int
	explicit testexplicit(int s) {
		iData.resize(s);
		cout << "wrong step!" << endl;
	}
	explicit operator bool() const { return false; }
	testexplicit(const char* str) {
		iData = str;
	}
	friend ostream& operator<<(ostream& out, testexplicit d) {
		out << d.iData;
		return out;
	}
};

void myunexpected()
{
	cerr << "unexpected called\n";
	throw 0;
}
void myfunction()
{
	throw 'x';
}

void mythread()
{
	// do stuff...
}

bool myfunctionCom(int i, int j) { return (i < j); }


int main()//còn có wmain biến dối số đầu vào chành wchar_t nx
{
	//cấp phát động
	/*int* p_malloc = (int*)malloc(5 * sizeof(int));
//void* ép về int*;GT rác;cấp phát 1 vùng nhớ trong ngoặc rồi trỏ đến vùng nhớ nếu thành công, ngc lại là NULL;giống new nhưng cả C
	char* p_calloc = (char*)calloc(5, sizeof(char));
	p_calloc[0] = 'T'; p_calloc[1] = 'r';
//gán =0 nên chậm hơn malloc.Auto con trỏ với các kiểu cấp phát động
	int* p_reall = (int*)realloc(0, sizeof(int));//là 0 thì nó sẽ cấp phát
	p_calloc = (char*)realloc(p_calloc, 4*sizeof(char));
//realloc chỉ có 2 cách dùng trên. Tuyệt đối ko gán cho 1 biến khác. c1 cấp phát nếu truyền con trỏ NULL.c2 đổi kích thước(mở rộng or thu hẹp nhưng k đổi địa chỉ nhé)
	free(p_malloc);
	delete p_calloc;
	free(p_reall);
	*/

	//test chuỗi wide char
	/*StrWork test;
	//_setmode(_fileno(stdout), _O_U16TEXT); //cần để viết được ký tự utf-16 ra stdout// thg dùng cho vc đọc file
	//_setmode(_fileno(stdin),  _O_U16TEXT); //cần để nhập đc ký tự vào.Tuy nhiên nó ép cả văn bản buộc dùng có w
	//Nếu xác định TV thì full w luôn
		wchar_t *wsch=new wchar_t{'\0'};
		wcout << StrWork::WcharToWstring(wsch);//dùng cho ngoài cx đc, hệt std
		wstring wstr{ L"ê" };
		wcin >> wstr;
		wcout << wstr END
	//UTF-8 là một kiểu encode các ký tự trong unicode, nhờ nó mà các ký tự cao tốn 2 byte(chứ k phải 1byte trong ASCII)cx đc encode và gõ đc TV
	//wstring là một kiểu chuỗi wchar tức wide character nên nó chứa rộng hơn trong ASCII tuy nhiên vẫn không ghi đc dấu tiếng việt(gõ đc ê nhưng
	//k gõ đc ế).Ta nên dùng wcin và wcout để viết widecharacter.Window k tự động hiển thị unicode nên ta phải set cho hiển thị
		*/

		//học sâu về nhập chuỗi mảng
	   /*char c[10];
	   cin.get(c, 10);
	//9 là số lượng ta có thể nhập, vì số 10 là kết thúc xâu.Để số bên trong đúng bằng số lượng phần tử mảng
	//cin.ignore() ko đối số thì chỉ xóa 1 ký tự mà thôi.
	//ta nên có cin.ignore(32767,'\n'); đằng sau phòng ta nhập thừa ký tự. Tuy nhiên cẩn thận cin.ignore() đằng trc, ta chỉ dùng đằng trc nếu\
	như trc đó ta phải nhập 1 cj khiến bộ nhớ đệm k trống.Nếu ko có ký tự thừa, hàm sẽ biến thành hàm nhập để xóa ký tự.Ignore ép có ký tự để xóa
	//cin.clear() sửa bit nhưng lại k xoa ký tự nào cả, vẫn phải ignore
	//cin.get() bị lỗi khi nhập ! ký tự enter.Còn cin.getline() khi nhập thừa ký tự thì còn gây lỗi về bit nên phải có cin.clear() đằng trc. \
	sau đó lại cin.ignore(323767,'\n') mới triệt để.
	//Vấn đề cin.ignore() đằng sau:Với cin.getline khi mà điền tràn bộ nhớ thì cin.ignore(32767,'\n') đằng sau sẽ giúp xóa.Tuy nhiên nếu như TH\
	ko điền thừa thì cin.ignore() sẽ gặp bộ nhớ đệm trống sẽ ép điền ký tự để xóa.Điều này k xảy ra vơi cin.get.Do đó dùng cin.get sẽ perfect hơn\
	//Còn vấn đề cin.ignore đằng trc(Hiểu tường tận):Nếu như ta dùng ignore đằng sau mà quên dùng ignore đằng trc thì cin. sẽ bỏ qua và cái ta \
	điền là điền cho ignore đăng sau(với cin.getline trong TH điền thừa).Nếu ta dùng cin.ignore đằng trc thì phải biết chắc là đằng trc có cái
	//điền r(với cả 2 loại).
	//Cách hoàn hảo luôn dùng cin.get() với cin.ignore đằng sau và đằng trc thì chú ý xem có điền k mà thêm cin.ignore()
	//fflush(stdin); nó bị lỗi với 1 số phiên bản nên ta thay bằng rewind(stdin); thế ignore dùng cả trc sau thoải mái k lỗi
		cin.ignore(32767, '\n');
		char c1[10];
		cin.getline(c1, 10);
		cin.clear();
		cin.ignore(32767,'\n');//lỗi nếu điền k thừa
		cout << c1 END
	//ý nghĩa của cin.ignore(32767,'\n'); nó xóa 32767 ký tự cho đến khi xóa đc ký tự \n thì thôi(nếu k có \n ép nhập).32767 là số \
	lớn nhất r. Tuy nhiên khai báo đúng phải là xóa ko giới hạn ký tự
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//numeric_limits là một mảng có template còn streamsize chính là long long. max này trả về GT lớn nhất, khác max() bth
		*/

		//bit cờ định dạng dòng
		/*cout << ios::skipws << " " << ios::left << " " << ios::right << " " << ios::internal << " " << ios::dec << " " << ios::hex \
	<< " " << ios::showbase << " " << ios::showpos << " " << ios::showpoint << " " << ios::scientific << " " << ios::fixed \
	<< " " << ios::adjustfield << " " << ios::basefield << " " << cout.adjustfield << " " << ios::oct END
	//dùng cout. or ios:: đều đc nhưng cout. cin. sẽ rõ hơn nhập hay xuất(vd cout.hex,...)
		cout << setw(6) << 1234 END
	//hàm setw thực chất là căn chỉnh bề rộng của kiểu dữ liệu xuất ra sau đó và đặt mặc định là căn lề phải, tức là chèn ký tự đệm\
	vào bên trái. Nếu ta setw nhỏ hơn thì nó full r tràn ra ko sao.
	//Ta có thể thay đổi mặc định này do ios cung cấp trong đầu ra các bit cờ chỉnh định dạng dòng.Nó nằm trong ostream tức luồng\
	cout.Hàm setf là hàm thay đổi định dạng cờ.Nó có 2 dạng truyền 1 tham số lFlag(định dạng GT bit cờ dùng | để kết hợp) và dạng \
	truyền 2 tham số lFlag và lMask(định dạng mặt nạ cờ=> cứ hiểu là bổ trợ cho cái đầu). Dạng 2 ko dùng | kết hợp đc
		cout.setf(ios::left,ios::adjustfield);
		cout << setw(6) << 1234 END
	//adjustified sẽ bổ trợ làm cho chỉ 1 in 3 định dạng căn lề đc tồn tại trong 1 cùng đoạn văn bản
	//Hiển nhiên đa năng như thế ta có thể bỏ qua thư viện iomanip mà dùng tt với hàm cout.width();
		cout.setf(ios::internal, ios::adjustfield);
		cout.setf(ios::showpos|ios::showpoint);
		cout.width(10); cout << 1234.0  END

	//sstream là 1 thư viện cx kế thừa từ ios. Nó giúp ta dùng các toán tử có trong ios cho kiểu chuỗi string(ta đã biết fstream là\
	cho file, iostream là cho số và chữ thông qua cin, cout).Chuỗi thuộc kiểu stringstream khác chuỗi bth và ko dùng cin cout như bth
		istringstream str{ "  123"};
		//bật cờ này sẽ khiến khoảng trắng trong ký tự luồng biến mất
	//1 số lưu ý khi ta dùng kiểu dữ liệu luồng ko thuộc iostream. ta luôn có thể truyền cho một biến bất kì khác lưu đc thông qua\
	toán tử >>(tự dịch con trỏ) và ko thể cout đc, nếu xuất phải lưu r xuất or tìm cách khác. Kiểu luồng ta luôn có con trỏ trỏ\
	vào chuỗi dữ liệu, tức là nếu ta dùng hay làm bất cứ 1 cj cx cần set lại con trỏ bằng hàm seekg và tellg đã biết.
	//Đậc biệt skipws là mặc định cho stringstream, tự bỏ space.Stringstream vào string noskipws sẽ mất hế dữ liệu(lỗi)
		//cout.setf(ios::skipws);
		char a, b, c;
		str >> a >> b >> c;
		cout << a << b << c END
		str.seekg(0);
		str >> noskipws >> a >> b >> c;
		cout << a << b << c END
	//Bản chất của ios là 1 class ở bên trong namespace std. Cho nên muốn dùng các hàm ở bên trong class khi chưa khai báo thì ta\
	phải dùng std::ios::<hàm,kiểu biến,biến>. Tuy nhiên ta đã usingnamespace std; và include thư viện r cho nên nếu các hàm ko nằm\
	ngoài iostream và ko trùng class thì ta dùng đc trực tiếp luôn mà ko cần std:: or ios::.Như vậy ta k cần dùng hàm cout.setf nx \
	mà ta dùng trực tiếp luôn.Lưu ý:các hàm no## ta ko dùng đc bằng cout.setf, 3 hàm căn lề khi dùng TT k cần adjustified nx, khi \
	dùng với kiểu cout ra hằng số hay truyền vào bằng đối số thì ta vẫn cần có ios::vì khi đó nó truyền binary dùng bitwise chỉnh cờ

		cout << noshowpoint << noshowpos << left << 123.4 END
		cout << showbase << uppercase << 123456 << " " << oct << 123456 << " " << hex << 123456 END
		cout << setbase(16) << 999 END //setbase(cơ số)
		cout.setf(ios::dec, ios::basefield);//basefield,floatfield là mask, chức năng TT adjustified
		cout.setf(ios::fixed, ios::floatfield);
	//số chấm động và hệ cơ số khác k kết hợp đc
		cout << scientific << 12345.6 END//số chấm động dạng KH ạ
		cout.flags(ios_base::fixed);//giống setf.(ios=ios_base) nhưng dùng flags k gán mask đc. Dùng setf buộc có mask nhé
		cout.unsetf(ios::fixed);//giống no thôi, dùng cố định vì no có khi thiếu hàm

	//Qtr:cout và cin ta ko coi nó là 1 hàm mà ta coi nó là 1 biến của class ios lưu vào bộ nhớ đệm và xuất or lưu tiếp vào bộ nhớ,\
	còn >> và << chính là operator khiến nó nhập xuất.cin là một biến luồng còn int a ko là một biến luồng, biến luồng mang kiểu thư\
	viện. Kiểu như thư viện là 1 class và biến luồng là 1 đối tượng class. int ko thuộc iostream nhé
	//Có 2 loại hàm, hàm chỉnh bit cờ và hàm bth.Bên trong hàm main ta có thể dùng các hàm của thư viện mà ta include: Th1: đó là\
	hàm dành riêng cho đối tượng luồng,để dùng ta dùng dấu chấm với đối tượng luồng. Có thể là hàm bit cờ .fail(),có thể là hàm bth\
	.open(,).Th2 là hàm public cho các đối tượng bên ngoài, ta dùng dấu () để truyền biến. Có thể là hàm bth max(,), có thể là\
	hàm bit cờ showpoint.Vc hàm có ngoặc or k thì t nhớ là đc. trong các hàm đó, có hàm trong std có hàm ko thuộc std nhg vẫn \
	trong thư viện.
	//cout thuộc luông stream nên hiển nhiên cũng có badbit failbit này nọ r

		cout.width(10); cout << showbase << internal << setfill('$') << hex << 9999 END//iomanip
		cout.width(10); cout.fill('*'); cout << showbase << internal << hex << 9999 END//iostream. Để bên ngoài tránh lỗi

		cout.flags(0);
		cout << cout.flags() END
	//thực chất nó cx giống như 4 bit trạng thái ta đã biết nhưng số lượng bit ở đây lớn vô cùng. cout.flags(); giống như hàm \
	setstate. cout.flags(0) sẽ tắt mọi cờ. còn cout ra thì sẽ ra tổng các cờ đang bật

	//fmtflags là 1 kiểu bitmask(giống số nguyên).Là kiểu biến trả về của hàm flags() và setf. Thực chất fmtflags chia làm 4 trường\
	đó là adjustified(internal,left,right), basefield(dec,hex,oct) và floatfield(fixed,scientific). Independent flags(boolalpha,...)\
	và chúng chính là các mask.GT của chúng là tổng các GT bên trong fmtflags là kiểu đối số truyền vào(giống int nên truyền int\
	cx đc) và cx là kiểu trả về of 2 hàm.các hàm ở trong đây đều có hàm hủy hàm khởi tạo.

		ios::fmtflags ff = cout.flags();
		ff |= cout.basefield;//gán cho biến ff hiển thị cơ số(bitmask dùng toán tử bitwise)
		ff &= ~cout.hex;//unset bit hex.cout. ko chỉ cout thì ra số mà còn cùng kiểu để gán cho biến fmtflags.
		cout.flags(ff);//kiểu of đối số truyền vào chuẩn phải là bitmask như này chứ k phải integer
	//Cách dùng, bth ta nhìn xem ta cần gán cj ta tạo biến fmtflags r gán cho nó, sau đó gán cờ như v.
		cout << ff END//Giá trị của dec+oct do ta loại field r. Có khả năng k đạt đc ý muốn vì k biết máy sẽ ghi dec hay oct
	//Vốn dĩ có hai cách dùng. C1 là dùng fmtflags hay dùng bit cờ. Còn c2 là ta dùng TT thì gọi là dùng manipulator

	//khi ta đã dùng đến cout.flags() tức là ta động đến các bit cờ bằng hàm chuẩn r. Sau đó nếu ta dùng setf or setiosflags()\
	cx k đc. Ta có thể đổi bằng TT hàm cout.flags() hoặc dùng manipulator mà thôi
		setiosflags(ios::showbase);// cũng đổi nhưng k hiệu quả ở đây.
	//sectionflags đặc điểm là yếu hơn cả manipulator và flags. Nó k thể sửa đổi khi đã 2 cái trc. Còn mani và fla mạnh ngang nhau\
	có thể đổi giá trị thoải mái.Hơn nx setiosflags() chỉ dùng cho trường independent flags. Còn resetiosflags() chỉ xóa những cái \
	j mà setiosflags vừa tạo. Do đó 2 cái này ít đc dùng
		*/

		//thao tác với stringstream
		/*//nhập
		//éo khác j string chỉ là cho số thành chữ đc và ngc lại
		stringstream sstr;
		sstr << "Hello I'm learning" << " " << "C++ programming language." << endl;//cho vào 1 string r gán cx là 1 kiểu nhập
		stringstream sstr2;
		sstr2.str("Hello I'm learning C++ programming language\n");
		string s{"Nguyen Thu Hieu\n"};
		stringstream sstr3{s};
		//xuất
		cout << sstr.str();
		//gán string với >> << tự dịch con trỏ(ko gán stringstream cho stringstream đc)
		string str3 = sstr2.str();//gán cả k/c và ko dịch con trỏ vs hàm str()
		string str1, str2;
		sstr >> str1; sstr >> str2;
		cout << str1 << "-" << str2 END
		//muốn thao tác với từng phần tử cho vô mảng
		vector<string> result;
		while (!sstr.eof())//tự dịch con trỏ mà
		{
			string str;
			sstr >> str;
			result.push_back(str);
		}
		for (size_t i = 0; i < result.size(); i++)
		{
			cout << result.at(i) << " ";//luôn dùng at nhé
		}cout END
		//number sang string(tự do với kiểu dữ liệu cơ bản)
		stringstream ss;
		int nValue = 12345;
		double dValue = 67.89;
		ss << nValue << " " << dValue;
		string strValue1, strValue2;
		ss >> strValue1 >> strValue2;
		cout << strValue1 << " " << strValue2 << endl;
		//string sang numbereach
		stringstream ss2;
		ss2 << "12345 67.899";
		int nValue2;
		double dValue2;
		ss2 >> nValue2 >> dValue2;
		cout << nValue2 << " " << dValue2 << endl;
		//xóa
		ss.str(""); //erase the buffer.Biến vẫn còn nha vì đây đâu phải bộ nhớ động, chỉ xóa buffer
		ss.clear(); //erase and reset error flags
		*/

		//thao tác với mảng ký tự 
		/*//khai báo
		char cha[6]{ "aBCde" };//tự có phần tử [5] là \0
	//vấn đề về nhập mảng ký tự, cout ra và lỗi với ignore đều đã học r.
	//nếu ta cin tràn mảng sẽ lỗi, nếu ta cin.getline thì tràn mảng ko lỗi mà nó sẽ tự bỏ đi phần tử thừa=> rewind(stdin);

	//pb:sizeof trả về kích thước toàn bộ mảng, strlen trả về kích thước toàn bộ ký tự trc \0
		//viết hoa,thg,copy,viêt tiếp
		_strlwr_s(cha); cout << cha END//dùng strlwr thì 4996
		_strupr_s(cha); cout << cha END
		strcpy_s(cha,20,"I'm Leaning C++");
		char cha2[100]{ "I'm leaning" };
		strcat_s(cha2, " C++");
	//strcpy_s sẽ cấp phát vùng nhớ theo đối số truyền vào như v sẽ tránh đc lỗi tràn tránh đc nhược điểm của strcpt còn strcat \
	thì k nên ta phải khai báo cấp phát cho nó vùng nhớ từ trước
		if (int res = strcmp(cha, cha2) < 0)
		{//UT1: chữ thg hơn chữ hoa, UT2: số lượng ký tự(nh ký tự hoa k bằng 1 ký tự thg)
			cout << "cha < char2" END
		}
		//tìm chuỗi,trả về NULL nếu k thấy,trả về giá trị con trỏ đầu tiên của chuỗi tìm thấy,cout ra phần chuỗi kế và tìm tiếp từ đó cx đc
		char szString1[] = "Hello Howkteam.com!";
		char szString2[] = "kteam";
		if (strstr(szString1, szString2) != NULL)
		cout << "Tim thay " << szString2 << " trong " << szString1 << " at " << strstr(szString1, szString2) END
		//nhân bản chuỗi
		char* s=_strdup(szString2);
		cout << s END
		free(s);
	//strdup(duplicate) TT, nó trả về mảng char* nên ta phải gán KQ, ta k thể gán 1 char tĩnh cho địa chỉ char động đc
	//pb strdup trả về char* nó tự cấp vùng nhớ r nhân bản, còn strcpy trả về 1 kiểu typedef errno_t, vùng nhớ phải cấp phát đủ
		errno_t t{ ENOMEM }; cout << t END//khi strcpy thất bại errno_t(1 kiểu trả lỗi) sẽ trả về ENOMEM mang GT 12,
	//khi dùng char mảng. Nếu cout thì sẽ là ra ký tự, còn khi dùng bth ví dụ gán hay j thì nó là con trỏ đến vùng nhớ [0]. Do đó\
	k thể gán mảng cho mảng tĩnh đc vì như thế là ta cố gán 2 địa chỉ khác nhau cho nhau,dùng các hàm đã biết mà gán.TT vs các TH\
	khác. Đa phần các hàm đối số truyền vào kiểu gán là const char* nên ta gán "..." cx đc
	    string newString{""};
		cout << newString.data()
		

		//thao tác chuỗi ký tự.(Chuỗi string cx là 1 mảng ký tự nên ta dùng đc các thao tác vs phần tử của mảng ký tự)//giống cả vector
		/*string str0{"98"};
		string str1{" 89hieu"};
		string str2 = str0 + str1;
		str0 += " hello ";
		cout << "str0 has " << str0.length() << " characters "  END
		cout << "str1 has " << str1.size() << " characters "  END//độ dài kbh tính \0
		cout << str0.front() << str0.back() << str0.at(0) << str0.length() END
		str0.assign(str1);
		str0.append(str1);
		str0.push_back('a');
		str0.pop_back();
		int ret1 = str1.compare(str0);
		str0.insert(1, str2);
		str0.insert(1, str1, 2, 3);//chèn 3 kí tự từ vị trí 2 chuỗi str1 và vị trí 1 chuỗi str0
		int n = str1.find(str2);//tìm chuỗi 2 có trong chuỗi 1 hay k => trả về vị trí đầu tiên
		int n1 = str1.find_first_of(str2);//tìm vị trí KÝ TỰ đầu tiên trong chuỗi 2 mà có ở chuỗi 1
		int n2 = str1.find_first_not_of(str2);
		int n3 = str1.find_last_of(str2);
		int n4 = str1.find_last_not_of(str2);
		cout << string::npos END//npos là giá trị max value of size_t cho 1 thành phần. Nếu dùng trong hàm string thì mang nghĩa"cho \
	đến VT cuối của string".dùng làm đk lấy VT.VD: while (!string::npos
		str0=str1.substr(0,4+1);//đối số count là số lượng ký tự, phải biến đổi thành số lượng ký tự(phép gán)
		string::iterator it =find(str0.begin(),str0.begin()+3,'K');
		cout << *it END
			cout << str0 END
		int n5=str1.find("hi",9);
		cout << n5;
	//các đối tượng chuỗi mảng đều có iterator. mảng ,string,vector,lớp array.
	//phân biệt hàm find trong iterator và hàm find trong string:hàm find() trong iterator dùng với mọi loại mảng. dùng bth find(đầu,\
	last,GT cần tìm) trong source thì GT cần tìm là template, trả về con trỏ iterator chỉ vị trí đầu tiên tìm thấy.ko thấy return last\
	ta buộc đặt điều kiện cho nó vì nếu iterator ra ngoài khoảng mảng thì rất dễ lỗi
	//hàm str.find() trong bản thân string thì có nhiều cách dùng (chuỗi cần tìm,tìm từ ký tự thứ bnh trong str); chuỗi KTu có thể\
	thay bằng ký tự '' nếu tìm 1 ký tự. Nếu chuỗi nhập const char* thì có thể thêm đối số 3 là tìm bao nhiêu ký tự trong const char*\
	kể từ KTu đầu tiên. Có thể chỉ điền mỗi string khi đó sẽ tìm ! string đầu tronng chuỗi như find_first_of.Nếu ko tìm thấy return -1.\
	ta nên đặt Đk cho nó trc khi nó để tránh GT -1.
		str0.erase(str0.begin() + 1);//xóa 1 phần tử
		str0.erase(str0.begin(), str0.begin() + 1);//xoa tu dau den dau
		str0.clear();//xoa het
		*/

		//try cast throw
		/*//exception chuẩn c++
		class Polymorphic { virtual void member() {} };//class cho trong cx đc
		try
		{
			Polymorphic* pb = 0;
			typeid(*pb);//lỗi id con trỏ khai báo k hợp lý
		}
		catch (exception& e)
		{
			cerr << "exception caught: " << e.what() << '\n';
			//throw; //or abort(); đều đc
		}
		//cerr chuyên dùng xuát lỗi với narrow characters(X wide characters-wcerr), có thể dùng cout chung cx đc
		//exception là 1 class base có rất nhiều class kế thừa. hàm thành viên what() trả về hằng char* là lỗi gì.Ta có thể dùng từng \
		class kế thừa với lỗi cụ thể or nếu dùng exception thì sẽ tự động khớp vs mọi lỗi. Vì what() là hàm virtual, nó sẽ tự khớp. \
		các class ké thừa thg thấy: logic_error, bad_typeid,bad_cast,bad_function_call,bad_weak_pointer,runtime_error,domain_error,\
		range_error,system_error,overflow_error,underflow_error,bad_array_new_length,invalid_argument,out_of_range,length_error,\
		Trong đó ios_base::failure là base class cho luồng. Dùng thế cho kiểu exception trong code
		//dùng exception thì CT sẽ k bị dừng, vẫn muốn dừng=> dùng throw;

			 //tạo exception CB
		//khi c++ khi có HĐ k bth thì sẽ ném ra 1 exception ngoai lệ, nó có nghĩa rộng hơn lỗi.Có 2 TH phát sinh: exception phát sinh\
		do c++ tự động tạo ra ta k kiểm soát đc(or kiểm soát 1 phần nhớ exception chuẩn của C++), và loại phát sinh theo ý muốn của ta.\
		cơ chế: Ct hoạt động mà có lỗi thì exception tương ứng sẽ tự động bị throw ném ra.Khi đó cái code block bị lỗi sẽ chấm dứt hoạt\
		động và CT vẫn sống. Exception đó sẽ bay đi đến các cấp function cao hơn chờ đc bắt(trong main()).Nếu ko đc bắt và đó là lỗi đỏ\
		error thì CT sẽ dừng lại và cái exception đó xuất hiện trên thanh lỗi.
		//Ta kiểm soát cái đó bằng exception chuẩn. Nếu ta cứ muốn tạo ra exception theo ý mình, tức là hiển thị ra cái khác với exception\
		chuẩn c++ thì ta phải chủ động throw lỗi trong try và bắt cái lỗi đó trong catch.
		int x = 50;
		int y = 0;
		double z = 0;
		try {
			z = division(x, y);
			cout << z << endl;
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}
		//trong division ta ném ra const char*, câu lệnh catch sẽ chờ bắt cái const char* đó cấp phát vào biến msg.
		//nếu muốn nó throw ra exception là đối tượng của 1 class thì ta phải khởi tạo constructor() cho class đó. Sau đó nó throw ra \
		biến class, khối catch sẽ bắt nó gán &(ta dùng gán & như ví dụ exception) cho biến và ta dùng hàm bên trong class cout ra lỗi.\
		ví dụ string là 1 class nên nếu muốn dùng string ta phải truyền vào constructor: throw string{"Division by zero!"};. string\
		có 3 hàm constructor truyền int, string khác,const char*.
		//có thể dùng xem nhiều câu lệnh try catch try catch lồng nhau
			//tạo exception class
		try {
			z = division2(x, y);
			cout << z END
		}
		catch (customexception & msg) {
			cerr << msg.what() << "  " << msg.whatc() END
		}
	//Unknown exception bởi cấu trúc bên trong exception. Data_What ko đc gán sẽ cout ra cái này. Nó là message trả về với lỗi tương\
	ứng đc định trong class exception. Ta nghiên cưu sau. Nếu ko tạo hàm what thì sẽ hiển thị Unknown exception khi dùng
		*/

		//malloc và new khác bọt
	/*//các kiểu dữ liệu CB k phải là class dù ta khai báo giống class int a(10); cx đc. hàm new khi dùng với class (giá trị khởi tạo)\
	sẽ gọi đến hàm khởi tạo nhưng với kiểu dữ liệu cơ bản thì không phải khởi tạo như vậy mà chỉ cấp vùng nhớ. malloc ko làm đc nv
	//new là 1 từ khóa toán tử, còn malloc là hẳn 1 hàm nhé\
	malloc trả về void và ta ép kiểu, thất bại => pointer NULL. new trả về kiểu chuẩn nhé, thất bại có warning\
	malloc kiểm soát đc kích thước bộ nhớ cấp phát, new thì trình biên dịch cấp
	*/

	//decltype
	/*int a = 2;
	decltype(2.0) b = 1.3;//1.0 khác 1 nhé
	cout << mul(a,b) << " " << typeid(mul(a,b)).name() END
	*/

	//lambda function.Với các hàm nhỏ dùng 1 lần ta k cần phải khai báo mà làm làm trực tiếp
	/*test_lambdafunction(1, [](int a) { cout << "Test lamba thoi" END });//TT
	void(*f)(int) = [](int a) { cout << "Test lamba" END };//khai báo con trỏ hàm và dùng bth
	f(10);
	int(*ft)(int) = [](int a){ return a; };//đơn giản thì nó tự định kiểu trả về
	int(*ff)(int) = [](int a)->int { return a; };//hàm phức tạp thì ta phải tự định kiểu trả về
	//các loại capture
	//khi ko có capture nó trả về một con trỏ và có thể gán trực tiếp vào hàm, nếu gán biến ta dùng con trỏ hàm.
	//khi có capture nó trả về kiểu dữ liệu lạ và k gán TT vào hàm đc, dùng auto nếu muốn gán và dùng
	int b = 9;
	auto fff=[&](int a=9) { cout << b END };
	fff(10);
	test_lambdafunction2<decltype(fff)>(1, fff);//ép bằng decltype truyền đc hết. K cần truyền đối số cho fff luôn do template
	//capture nhiều biến+tham chiếu[&a,b]; mọi biến bên ngoài gán tham chiếu[&]; mọi biến ngoài copy[=]; các biến ngoài là chỉ các\
	biến trong 1 hàm bên ngoài chứa lambda, k tính đối số truyền vào of hàm ngoài. Nếu muốn tính=> kết hợp [&,&biến ngoài]
		test_lambdafunction2(1, [&](int a=9){ cout << a END });//truyền hàm or gán lambda r truyền cx ok
	//pb [](){}() và [](){}
		if ([] (int a=1) {return a; }())
		{
			cout << "Test [](){}()" END
		}
		*/

		//lớp array 
		/*array<int,10>arr{1,2,3,4,5,6};//GT còn lại mặc định là 0 mà k cần nói
		cout << arr.at(4) << " " << arr.size() << " " << arr.max_size() END//max_size()=size()
	//điểm khác biệt array tĩnh và lớp dựng sẵn: lớp dựng sẵn buộc khai báo số phần tử dù khai báo cụ thể r;lớp array khi truyền vào\
	hàm sẽ ko biến đổi thành con trỏ như mảng tĩnh.Cho nên mảng tĩnh truyền hàm k dùng đc size() và vòng for each, nhưng vector và \
	lớp array thì dùng đc->biến array<,> kp là con trỏ mà là biến có giá trị là 1 list như v
		array<int, 10>::const_iterator position = arr.begin();//có iterator con trỏ như vector,k cout << position đc mà cout << *position
		array<int, 10>::reverse_iterator rposition = arr.rbegin();//nó còn có cả reverse_iterator(vector cx có)
	//thêm const trc iterator chỉ định rằng nó k thể bị đổi vd +=1=> lỗi
	//reverse_iterator ngược với iterator. Khi ta +=1 reverse_iterator thì nó lại giảm vị trí so với mảng
		cout << *rposition END
		sort(arr.begin(), arr.end());//đối sô truyền vào là iterator, .begin() và .end() trả về iterator nhé
		cout << *rposition END
		sort(arr.rbegin(), arr.rend());//truyền vào đối số là reverse iterator
	//rbegin() sẽ bắt đầu từ cuối chuỗi đến rend() đầu chuỗi
		cout << *rposition END
		printArray(arr);
	//iterator gắn liền với vị trí trên mảng cố định nhé

	//khi ta gán iterator và reverse_iterator với begin và rbegin là chuẩn và bth, còn khi ta gán với end và cout ra thì bị lỗi là vì\
	khi position đc gán với 1 mảng thì tức là ta chỉ có thể cout giá trị trong mảng đó, nếu như ta cout giá trị của iterator mà ở ngoài\
	thì lỗi do vùng nhớ chưa cấp phát mang GT rác nên chưa gán giá trị, mặc dù TA GÁN ĐC, nhưng k đc dùng(cout) khi chưa cấp phát.NN \
	là vì begin là vị trí ban đầu nhưng .end() thì là vị trí sau vị trí cuối cùng(chưa đc cấp phát),rend() là vị trí trc vị trí đầu mảng
	//kết hợp vector và lớp array chính là toàn bộ về iterator
		arr.fill(1);//đặc biệt
		for (auto check = arr.rbegin(); check != arr.rend(); check++)//vẫn là ++ vì ++ là -- trong reverse
		{//cout ngược ha
			cout << *check << " ";
		}
		cout END
		cout << arr.back() << " " << arr.front() END
	//lớp array ko bị phân rã thành con trỏ khi truyền hàm nên vẫn biết rõ số lượng phần từ(lợi thê so với mảng) + các hàm có sẵn
		*/

		//operator NC
		/*float *n=new float;
		cout << 123 END
		cin >> n;
	//ta chỉ có thể định nghĩa ra những cái chưa đc định nghĩa. Do k có hàm nhập địa chỉ nên ta ms định nghĩa hàm ms đc
	//dùng làm hàm xuất nhập class là perfect
		//conversion operator dùng làm hàm get là perfect
		Person person;
		int a = person; cout << a END
		 */

		 //static_assert vô dụng.
	 /*//Đầu vào 1 phải là dữ liệu const mang tính chất cờ đúng sai
	 //static_assert((1 + 1) == 2, "Error appears in error list.");*/

	 //constexpr
	/*//dùng constexpr sẽ tính toán tại thời điểm biên dịch.Đến khi thực thi chỉ cần thế vào mà k cần nhảy hàm=> tiết kiệm hiệu suất \
	Các marco hay hàm inline cx làm kiểu tương tự như v. constexpr dùng cho 3 đối tượng biến, hàm và hàm khởi tạo.(dùng vs hàm thì \
	hiểu là hệt inline).Do tính chất thực thi tại thời điểm biên dịch nên cần tính toán trc đc giá trị+k đổi(biến thì phải gán luôn ha). Ta hiểu compile time là\
thời điểm biên dịch của CT tức là lúc đầu CT chạy(compile-time error là lỗi lúc compile thấy ngay) còn run time là thời điểm CT compile thành công và chạy từng dòng\
(run-time error là lỗi phải chạy CT ms thấy) thì dùng constexpr đòi hỏi mọi giá trị biến, hàm,.. đều specific hết từ compile time r
		constexpr int a = 2;
		//biến constexpr là hằng số(cứ như dùng marco a 2 nhưng nó xác định int rõ hơn)
		//hàm constexpr chỉ là hàm đơn giản(như inline). Biến đầu vào phải là literaltype(vô hướng(các kiểu dữ liệu cơ bản),tham chiếu\
	địa chỉ, mảng,class với điều kiện có ít nhất 1 hàm constexpr constructor chuẩn và cả constexpr destructor...),hàm k ảo, kiểu trả\
	về là literal type(cả void cx tính, nch là toàn bộ cái CB đã biét).Bên trong hàm chỉ đc chứa return 1 lần duy nhất(ko dùng đệ quy)\
	assert, using or typedef.Nên các hàm constexpr thg return luôn,chỉ dùng lấy GT(khắt khe hơn inline)
        Các hàm constexpr chỉ lấy giá trị trả về mà thôi, nên bên trong constexpr chỉ đc gọi các hàm constexpr khác chứ 1 hàm constexpr k đc dùng cout<<"Hello"; bên\
trong vì nó kp 1 hàm constexpr chỉ trả về giá trị. Dùng như này sẽ báo lỗi. inline thì kiểu copy code hàm vào chỗ đó nhưng constexpr thì lấy giá trị trả về thôi, k in\
gì hết. Tương tự truyền vào hàm constexpr 1 số nhập từ bàn phím, nó k báo lỗi mà hiểu là nó lấy giá trị ta nhập thì bh dùng gì trong hàm coi như nhập thẳng \
vào luôn, tuy nhiên ta k nên làm như v mà chỉ dùng constexpr khi biết trc giá trị trả về thôi, làm như v nếu compiler nào đó trả ra lỗi thì k bt đường nào mà lần đâu
		int t = 10;
		function(t);//lúc biên dịch(trc khi thực thi main()), compiler đã tính toán đc giá trị của function r
		//constexpr constructor tương tự và có hàm cha ko virtual mà phải có hàm specific(specific con thì cha cx thế)
	//khi dùng hàm constexpr cần chú ý 1 điều nx là CT phải tính toán đc kết quả và phải là biểu thức hằng. Biếu thức hằng (constant \
	expression) là biểu thức mà có thể tính toán giá trị ngay tại thời điểm biến dịch, áp dụng nó với mọi đối tượng của constexpr.VD:
	#if 0
		int a = 3;
		cin >> a;
		array<int, a>arr;=> ko là constant expression vì tại thời điểm compile, giá trị của a ko cố định. ta có thể cho a lên 1000 or
	cho GT âm. Khi đó array<int,n> compiler k tính toán trc đc giá trị nên array<int, a>arr; ko là CE.Nếu ta dùng const int a thì là CE
	VD: constexpr int add_vectors_size(const std::vector<int>& a, const std::vector<int>& b)
		{
			return a.size() + b.size();
		}thì cx mắc lỗi.Hàm add_vectors_size k là một constexpr dù các đối tuong truyền vào là hằng vì lúc biên dịch nó eo biết vector
			có size là bao nhiêu.Ta chỉnh size bên như nào bên ngoài ai biết//trừ khi ngay bh ta tính ra đc kq luôn thì ok
	#endif
		const int c = 10;
		array<int,c> a1{ 1,2 };
		array<int,6> a2{ 2,3 };
		cout << add_arrays_size(a1, a2) END
	//do hàm add_arrays_size lấy ra giá trị N1,N2 nên nó là constant expression.GT đó k bị đổi nên trình biên dịch tính trc đc=>constexpr, và dù chuyện gì xảy ra khác nó vẫn là giá tri đó
	//đối số truyền vào hàm phải là biểu thức hằng. array rất thích hợp vì nó ép đối số truyền vào là hằng
	//=> nên dùng constexpr bất cứ khi nào có thể
        //vector k đc nhưng array lại là constexpr vì lúc compile time nó đã xác định đc c và biết đc luôn KQ r vì c là hso, còn size của vector rõ ràng kp hso, KQ trả về k phụ thuộc vào bất cứ 1 thao tác gì từ bàn phím trong qtr code
	*/

	//thread
		/*thread task(dosth, "NTH");
		if (task.joinable())//xem thread có trống hay k
		{
			cout << task.get_id() END //id là biến private(kiểu thread::id là 1 class,native_handler_type cx là 1 class)
			//còn 1 biến nx là native_handle_type lấy bằng native_handle() cx TT như id
			cout << task.joinable() << endl;
			task.detach();//thực hiện xog thì trở thành thread trống và id trống,k thể thực hiện lại lệnh cũ=> Sử dụng tiếp như 1 biến thread trống
		}
		//	task.join();//chỉ đc dùng 1 in 2 detach hoặc join, dùng join thà kệ mẹ mặc định cho nhanh

		//Khi khai báo biến thread mà có gán vs task, tức là joinable()=true thì các lệnh bên trong phải đc thực hiện(vì có id),nếu biến thread \
		k đc thực hiện thì sẽ bị abort() khi CT end.
		thread as;//task này đc khởi tạo =default constructor sẽ có joinable()==false và CT sẽ k bị abort()dù k thực hiện.K gán thì k có id(bđ là trống)
		thread task1(dosth, "NTH");
		task.swap(task1);
		task.detach();
		cout << task.joinable() << endl;//khi ta detach thì k cout đc joinable của lệnh đang thực hiện do trạng thái đang thực hiện thì\
	nó nửa vời vừa sắp =0 lại vừa hết =1 nên k cout đc. swap thì task1 trở nên trống ngay nên joinable=0,chỉ kiểm tra joinable trc khi join/detach
		cout << task1.joinable() << endl;
	//dùng thread đa luồng sẽ làm cho CT chạy nhanh hơn nhưng, 1600 thread sẽ làm CT trễ 1s, nên nếu thao tác với hàng triệu task thì \
	chỉ nên dùng bth thôi. Còn lại cứ ưu tiên chạy thread cho nhanh
		*/

		//atomic
		/*//1 vấn đề khi dùng thread là data races, dữ liệu bị đổi bởi nh task cùng lúc, khi đó sẽ ko đạt đc KQ mong muốn, xử lí bằng biến atomic
		//khi thread truyền vào tham chiếu thì dùng thêm std::ref() nếu k sẽ gây lỗi, bth chỉ dùng biến copy(k phải std::cref())
		//atomic_char a = 'N';
		char a = 'n';
		thread task(dosth1, ref(a));
		thread task2(dosth2, ref(a));
		task.detach();
		task2.detach();
	//khi dùng biến atomic(mọi kiểu dữ liệu cơ bản trừ string) mà tạo ra 2 thread detach cùng thay đổi 1 biến sẽ báo lỗi k cho compile
		*/

		//smart pointer
	/*
	#if 0
		Theo thứ tự phân vùng bộ nhớ từ trên xuống dưới :
		Code segment lưu các lệnh đã đc biên dịch của CT.
			data segment->các biến static or global có khởi tạo giá trị
			BSS segment->các biến static or global chưa đc khởi tạo GT cụ thể
			heap segment và stack
			heap nó lưu những cái cấp phát động, stack lưu biến toàn cục cấp phát tĩnh
			Ví dụ : ta có 1 class có các biến = > khi khai báo thì các biến đó lưu vào stack.Trong class đo có biến 1 biến class khác, nó tham
			chiếu đến biến class bằng cấp phát động, vd : student * stu = new student; và trong class student có 2 biến nx là p, q thì biến stu
			sẽ lưu vào trong stack, tham chiếu đến 2 biến p, q trong heap(đó là stu->p, stu->q).stack có tc j thì biết r
			Dùng ptr mà quên xóa thì nguy hiếm = > dùng smart pointer k cần xóa=> nên dùng thế con trỏ bth
	#endif
			//unique_ptr
			unique_ptr<int> abc = make_unique<int>(9);//dùng make_unique để gán, buộc dùng (), nó có VT tương đương new int
		unique_ptr<const int> abcd;//khai báo như này là sai,cx như khai báo con trỏ mà k có new int, k dùng đc mà phải có
		abcd = make_unique<int>(0);
		//có thể dùng con trỏ biến class hay mảng cx đc

	//khi dùng unique_ptr thì nó là duy nhất k thể có con trỏ thứ 2, nếu muốn dùng hàm move()
		unique_ptr<int> abcde = move(abc);
		//shared_ptr
		shared_ptr<int> bcd = make_shared<int>(90);
		shared_ptr<int> bcde = bcd;//unique phải dùng move
	//k nên dùng shared vì nó cho nh con trỏ cùng 1 vị trí, chỉ dùng khi cần chia sẻ như v chú dễ lẫn.
				//các smart pointer đều có hàm reset, gọi tới hàm hủy mặc định
		bcd.reset();//hủy GT
		bcd.release();//Trả lại quyền sở hữu,nhưng thg ta k dùng vì có mặc định hủy r
	#if 0
	smart_pointer sẽ tự động xóa vùng nhớ khi cấp phát cx như khi CT bị lỗi=>k sợ rò rỉ vùng nhớ. Tuy nhiên hiện tượng rò rỉ vẫn có\
		thể xảy ra, đó là khi tham chiếu vòng vs shared pointer
		struct House
		 {
			 std::shared_ptr<House> neighbour;
		 };
		shared_ptr<House> house1 = make_shared<House>();
		shared_ptr<House> house2 = make_shared<House>();
		house1->neighbour = house2;
		house2->neighbour = house1;
	nó k bh hủy đc biến, vd: nó định xóa house1, thì nó phải xóa neightbor của house1 trc, mà nó lại bằng house2, muốn xóa nó thì phải
	xóa house2, muốn xóa house2 thì phải xóa neighbor của house2, nó lại bằng house1,=> kbh xóa đc. Để khắc phục=> weak pointer
		struct House
		 {
			 weak_ptr<House> neighbour;
		 };
		shared_ptr<House> house1 = make_shared<House>();
		shared_ptr<House> house2 = make_shared<House>();
		house1->neighbour = house2;
		house2->neighbour = house1;
		Do yếu nên nếu shared pointer trỏ 1 đối tượng bị hủy hết thì dù còn weakpointer trỏ tới, nó vẫn bị xóa
			Do đó, cần KT xem đối tượng có còn hay k trc khi gán weak pointer, nó chỉ có thể đc dùng gán cho 1 shared pointer
	#endif
			weak_ptr<int> a;
			if (a.lock()=std::shared_ptr<int> sp) //= > hàm lock của weak sẽ return 1 shared từ weak
			{
				cout << "1. weak " << (a.expired() ? "is" : "is not") << " expired\n";// expired() trả về bool xem có GT hay k
			}
	//weak_ptr k dung đc gt nên chỉ để bổ trợ shared pointer mà thôi, ta dùng để KT xem có hay k
	//cách khác k dùng make_shared mà dùng new kết hợp với std::default_delete để khởi tạo
			shared_ptr<int[]> sh(new int[10]{}, std::default_delete<int[]>());//dấu {} để khởi tạo toàn 0
			sh.get()[2] = 1;
			//tuy nhiên bh nó xịn hơn k cần nv nx mà chỉ cần
			shared_ptr<int[]> sh1(new int[10]{});
			sh1[2] = 1;
			cout << endl << sh1[0] << endl;
			*/

			//explicit
		/*//Có hai kiểu khai báo phổ biến là direct_initialization(dùng () với 1 phần tử và {} với nh phần tử) và copy_initializatoin(dùng \
		dấu =). Khi có {} thì là list. VD int* a=new int[2]{1,2}=> khởi tạo copy_list_initialization
		//từ khóa explicit dùng cho constructor và operator trong class nhằm cản trở việc chuyển đổi ngầm định, và khai báo copy=>nên khai \
		direct vs các biến class,mảng, biến bth thì = là đc r
		#if 0
		ví dụ như chưa có explicit ở constructor của testexplicit(int s)
		= > nếu testexplicit a = 'z';=> sai vì nó sẽ gọi vào constructor trên và cout ra wrong step! là do nó ép kiểu ngầm định 'z' thành
		mã ASCII, điều này là sai, nếu muôn gọi vào constructor const char* thì phải là "z"=> nếu như ta muốn hàm khởi tạo nó phải chuẩn đúng
		là GT khai báo và chỉ khởi tạo trực tiếp thì dùng thêm explicit chủ yếu để tránh ép kiểu ngầm định.nếu có thì nó sẽ báo lỗi.
		#endif
			testexplicit abc{1};
			if(abc)//hàm operator bool còn j
			bool nb2 = static_cast<bool>(abc); //vẫn ép kiểu tường minh đc

		//nếu dùng explicit mà vẫn muốn dùng thì có thể tạo 1 hàm nx khai báo char. Còn 1 cách nx để cản việc khởi tạo sao là tính trc nó \
			rồi cho nó bằng delete
		*/

		//noexcept bỏ throw thôi có gì đâu khi đứng sau hàm
		/* cout << std::boolalpha << noexcept(printArray) << endl;//noexcept operator làm hàm kiểm tra, sẽ tính toán trc xem có exception k=> khá vô dụng
		//có thể chủ động thêm noexcept cx như noexcept(true) vào sau hàm để bảo rằng nó k throw , nếu hàm vẫn throw thì sẽ k bắt mà abort\
        	sẽ abort Ct, cout ra sẽ theo ta chủ động thêm thế nào kể cả thực tế nó có throw
		//nếu thêm noexcept(false) thì hàm có thể có exception hoặc k=> vô dụng
			*/

			//else
		/*//unexpected();=> đây là hàm terminate dừng CT khi ta dùng throw hay abort sẽ gọi đến hàm này
			try
			{
				myfunction();
			}
			catch (int) { cerr << "caught int\n"; }// k cần biến nếu ko dùng
			catch (...) { cerr << "caught some other exception type\n"; }//dấu 3 chấm là bắt dù throw bất cứ 1 cj

			cout << int(3.4);//cx transfer ra int đc

			cout << INT8_MIN << " " << INT64_MAX END
		*/

		//Thư viện algorithm
    //vòng for_each: vòng này sẽ thao tác vs 1 loại mảng từ vị trí này đến vị trí kia làm 1 thứ gì đó và đồng thời return về kiểu giá trị của hàm
//ta truyền vào.Chính vì tính chất return GT là kiểu biến của hàm nên ta thg chỉ dùng cho lambda function và operator trong class
 //   vector<int> myvector{ 10,20,30 };
	//auto ui=for_each(myvector.begin(), myvector.end(), [](int& n) { n++; });
	////với lambda function nó ta có thể khiến cho các thành phần trong mảng thay đổi ra sao.ta có thể k cần đặt biến return cx đc.Ở TH này ta 
	////k cần dùng biến return nhưng nếu cứ dùng thì có thể auto vì hàm này return void mà ta k biểu diễn đc
	////vs struct,class, ta chỉ dùng khi có operator
	//struct Sum
	//{
	//	void operator()(int n) { sum += n; }
	//	int sum{ 0 };
	//}test;
	//Sum s = std::for_each(myvector.begin(),myvector.end(), Sum());//gọi vào operator và truyền vào ope từ begin đến end của myvector
        //gọi sum(20) chẳng hạn là gọi sum operator r, truyền sum() tức là truyền operator(); nó sẽ chọn operator có kiểu trả về phù hợp
	////Sum s = std::for_each(myvector.begin(), myvector.end(), test);
	//cout << s.sum << endl;
	//vs class chỉ có 1 hàm operator khởi tạo là () thì ta có thể dùng <tên class>() làm hàm truyền vào or test nếu dùng tên sau
	//nó return ra 1 struct kiểu sum. Như v là ta đã vô tình khởi tạo 1 biến struct r, hàm này trả về chính là đối số thứ 3 ta truyền vào=> 1 biến
	//class bth sau khi thao tác vs từng phần tử của mảng
    //operator kiểu int trả về int nhưng kiểu void thì nó chỉ làm 1 cái gì đó.VD:
    //background_task task;\
    task();  // calls background_task::operator()
#if 0
	nghiên cứu về hàm operator().VD:
	class Fraction {
	private:
		int a, b;
	public:
		Fraction(): a{10},b{15}{}
		operator double() const//đổi chỗ vị trí operator và double đêu dc,  k có đối sô thì đẻ như này, nếu có thì giữ () và thêm(int đối số) đằng sau
		{
			return (double)a / (double)b;
		}
	};
	r dùng
		Fration a();
	double b = a;//gọi vào hàm operator đó
	//vs hàm operator void thì ta có thể dùng như bên trên, nếu k có nó thì k dùng foreach đc nv đâu
    dùng for each như v khi cần thao tác với 1 mảng dài mà dùng 1 hàm trong class or 1 hàm lambda ngắn
#endif
	//find, nó find bất cứ kiểu mảng nào vs bất cứ GT nào, đúng thì trả về GT trùng đầu tiên
	//int myints[] = { 10, 20, 30, 40 };
	//int* p = find(myints, myints + 4, 30);
	//if (p != myints + 4)
	//	std::cout << "Element found in myints: " << *p << '\n';
	//else
	//	std::cout << "Element not found in myints\n";//=>nó KT [first,last) tránh nhầm,k tìm đc sẽ trả về con trỏ last

	//vector<int> myvector(myints, myints + 4);
	//vector<int>::iterator it;
	//it = find(myvector.begin(), myvector.end(), 30);
	//if (it != myvector.end())
	//	std::cout << "Element found in myvector: " << *it << '\n';
	//else
	//	std::cout << "Element not found in myvector\n";
	////mảng thì dùng bth còn vector thì báo iterator. 

	////count, tính xem lặp bnh lần TT
	//int myints[] = { 10,20,30,30,20,10,10,20 };   
	//int mycount = count(myints, myints + 8, 10);
	//cout << "10 appears " << mycount << " times.\n";
	//vector<int> myvector(myints, myints + 8);
	//mycount = count(myvector.begin(), myvector.end(), 20);
	//cout << "20 appears " << mycount << " times.\n";

	int myints2[] = { 10,20,30,40,50,60,70,50 };
	vector<int> myvector2(7);
	copy(myints2, myints2 + 7, myvector2.begin());//copy từ đâu đến đâu vào chuỗi nào

	int myints[] = { 32, 71, 12, 45, 26, 80, 53, 33 };
	std::vector<int> myvector(myints, myints + 8);             // 32 71 12 45 26 80 53 33 1 cách khai báo vector khác nhanh
	std::sort(myvector.begin(), myvector.begin() + 4);         //(12 32 45 71)26 80 53 33
	std::sort(myvector.begin() + 4, myvector.end(), myfunctionCom); // 12 32 45 71(26 33 53 80)
	std::sort(myvector.begin(), myvector.end(), std::greater<int>());     // std::less<int>() by default, nhìn là biết nd hàm r
	//hàm này có thể truyền dùng mặc định or đối số thứ 3 là một hàm ss khác or là biến Com tức là std::greater or less tùy loại sx
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::vector<int> v(myints, myints + 8);
	std::vector<int>::iterator low, up;
	low = std::lower_bound(v.begin(), v.end(), 20);           
	up = std::upper_bound(v.begin(), v.end(), 20);//nếu mọi phần tử đêu nhỏ hơn 20 thì return last,luôn tìm từ [first,last)


	sort(v.begin(), v.end(), less<int>());// dùng greater k đc nhé, phải là sắp xếp tăng cho binary search, dùng less or mặc định cx tự là less r
	//phải sắp xếp trước mới tìm được
	if (binary_search(v.begin(), v.end(), 71))
	{
		cout << "found" << endl;
	}
        
	//operator ngoài cách dùng trên còn dùng để định nghĩa các phép toán cho lớp.Ví dụ cuối cùng
class vector
{
    public:
    vector(int a,int b): x{a}, y{b} {}
    int x;
    int y;
    vector* operator - (vector& v);//kiểu trả về  opeator  phép toán  (đối số) // còn muốn đổi vc nhập xuất tuân thủ & đối số và return
    void operator()(int a) { x+=a; }//chú ý là có dấu () k có gì đi kèm với(đối số truyền vào) khi ta dùng void 
};
vector* vector::operator - (vector& v)
{//vs nhập xuất thì phải có biến ostream truyền vào con vs vector thì nó tự hiểu v2-v1 thì v1 là cái truyền vào, v2 là this r nên k cần truyền vào nx, nếu k có thì this ví dụ ta dùng ostream hay istream với >> << k có this nên truyền vào bth
    this->x -= v.x;
    this->y -= v.y;
    return this;
}

ostream& operator<<(ostream& os, const vector& v)//các cái có sẵn nhớ dùng tham chiếu & và nếu nhập vào thì k có const còn lấy ra thì 
//thêm const vào, kết quả phải return biến.
{
    os << v.x << " " << v.y;
    return os;
}

int main()
{
   vector v1(1,6);
   vector v2(3,4);
   v2(1);
   vector* v3 = new vector(0,0);
   v3 = v2-v1;
   cout << *v3;//chú ý bên trên ta gán this, xong return this nên cả v3,v2 cùng bị đổi
//nếu muốn v2 k bị đổi thì chỉ cần tạo 1 biến vector khác và return nó chứ k đổi this như v
}
	//system("clear") dùng cho linux thôi
	int ENDMAIN = _getch();//do _getch() nó return int
	return 0;
}