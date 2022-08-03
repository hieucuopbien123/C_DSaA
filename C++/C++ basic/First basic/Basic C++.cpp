#include "Basic C++.h"

#define NDEBUG//chèn đằng trc #include <cassert> sẽ vô hiệu hóa nó
#include <cassert>

#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif//cái này nó tự define từ trc r. Công dụng là để tạo 1 Unicode program.Sẽ định nghĩa lại vài loại biến và hàm mà có liên
//quan đến char* string và wchar_t Unicode string bên trong

inline void  Simplify(int& num, int& dino);//có thể dùng * tương tự
inline void GCD(const unsigned int& num1, const unsigned int& num2, int& gcd);
int MaxValueArray(int& index, int x = 0);
void arrayandpointer();
void Insert_array(int* array, const int& size);
void Print_array(int* array, const int& size);
int Sum(int* array, const int& size, bool(*Pntr)(const int&));//ko đc có đối số hàm ngầm định khi khai báo ở đây
int Find(const student* student, const unsigned int& numberofstudent, bool(*Pntr)(const float&, const float&));

#define ABC 3+1//m định nghĩa trong hàm cx đc vì nó éo hiểu code c++
//3+1 ở đây khác 4

int main() {
	/*Count the number of words and characters in a sentence*/
	/*
		int w=1;
		int c=-1;
		char s='A';

		cout << "Insert a sentence: \n";
		while(s!='\n')
		{
			s=getchar();//=cin.get();
			if (s==' ')
			{
				w++;
			}else
			{
				c++;
			}
		}
		cout << "It has " << w << " words.\n";
		cout << "It has " << c << " characters.\n";
	//Khi coi là ký tự thì phải đặt trong dấu '', nó có thể thay thế phím bấm. ' ' là Space còn '\n' là Enter.
	//getchar() sẽ lấy kí tự một cách liên tiếp, còn cin thì lấy từng kí tự một ngăn nhau phím enter, cho nên while(!='\n') chỉ đúng với getcharsự
	//còn với cin thì nên while kí tự khác vì enter trong cin ko phải là \n mà mang vai trò là kết thúc việc nhập kí tự
	*/

	/*Options*/
	/*
		float num1=0.0;
		float num2=0.0;
		unsigned int gcd=0;

		cout << "Insert two number: \n";
		cout << "Num1: "; cin >> num1;
		fflush(stdin);
		cout << "Num2: "; cin >> num2;
		cout << endl;

		char key='a';

		cout << "Select your options by keyboard\n";
		cout << "\t1. Sum operation.\n";
		cout << "\t2. Sub operation.\n";
		cout << "\t3. Div operation.\n";
		cout << "\t4. Find GCD.\n";
		cout << "\t5. End.\n";

		while (key!='5')//ko đc enter vì cin k có nút '\n'
		{
		cout << "Your option is "; cin >> key;
		fflush(stdin);

		switch(key)
		{
			case '1': cout << "Sum is " << num1+num2 << endl; break;
			case '2': cout << "Sub is " << num1-num2 << endl; break;
			case '3':
			if (num2==0)
			{
				cout << "Can't find division.\n"; break;
			}else{
				cout << "Div is " << num1/num2 << endl; break;
			}
			case '4':
				if(num1>0 && num2>0)
				{
				GCD(static_cast<unsigned int>(num1),static_cast<unsigned int>(num2),gcd);
				cout << "GCD is " << gcd << endl;
				}else {
					cout << "Can't find GCD.\n";
				} break;
			case '5': cout << "Bye.\n";break;
				default: cout << "Not valid\n"; break;
		}
		}
	*/

	/*Print 100 random number*/
	/*
		cout << "Case 1" << endl;
		int random=0;
		srand(time(NULL));
		for (int i=0;i<100;i++)
		{
			random=rand()%100;
			cout << random << "\t";
		}
		cout << "\nMax: " << RAND_MAX << endl;

		cout << "Case 2(OPTIMAL)" << endl;
		mt19937 random_engine(time(NULL));//một máy phát engine sinh số ngẫu nhiên
		uniform_int_distribution<int> distribution(0,100);
	//một cái hàm phân phối số từ 1 đến 9 với xs như nhau, phải dùng với cá hàm thành phần khác mới sinh được số ngẫu nhiên
		for(int i=0;i<=100;i++)
		{
			cout << distribution(random_engine) << "\t";
		}
	//random_device cũng là một engine nhưng nó cố định do không truyền đc tg thực nên không dùng
	//default_random_engine cũng là một engine y hệt nhưng số đầu tiên luôn cố định nên ko dùng
	// có một cách khác lấy thời gian thực thông qua biến system_clock trong thư viện chronno và using namespace std::chrono là
	//time_t currentTime = system_clock::to_time_t(system_clock::now());cout << currentTime << endl;

		cout << "\n" << "Case 3(float)" << endl;
		uniform_real_distribution<float> float_distribution(1,100);
	//một cái hàm phân phối số từ 1 đến 9 với xs như nhau, phải dùng với cá hàm thành phần khác mới sinh được số ngẫu nhiên
		for(int i=0;i<100;i++)
		{
			cout << setprecision(4) << float_distribution(random_engine) << "\t";
		}
	*/

	/*Pointer*/
	/*
		int a=0;
		int &p=a;
	//khi truyền thì & sẽ mang ý nghĩa đặt cùng 1 tên nữa cho môt biến khác, ko đặt số cụ thể đc. nhớ là ko tồn tại &&a;

		int* p1=&a;
	//khi khai báo con trỏ trực tiếp thì nhớ quy tắc bình thường <kiểu dữ liệu>, <tên biến> và <giá trị gán> phải cùng loại, ở đây là địa chỉ

		int* p2=new int;
	//thông thường có hai kiểu khai báo, khi cần dùng bình thường kiểu cấp phát vùng nhớ động để giải quyết các vấn đề về dung lượng, kiểu không biết số lượng
	//là bao nhiêu thì ta khai báo và cấp phát new <tên kiểu dữ liệu> luôn. Còn nếu khai báo cần gán thì ta gán luôn như ví dụ trên. không đc khai báo con trỏ
	//sai kiểu int *p.Còn kiểu 3 là khai báo nullptr lúc đó chỉ có một cái tên chờ gán địa chỉ như kiểu 2 chú không dùng đc;
	//một con trỏ chỉ sẵn sàng được sử dụng khi có địa chỉ cụ thể, or khi ta gán địa chỉ cho nó, nếu ta gán địa chỉ thì trạng thái nào của con trỏ cx dùng đc

	//các trạng thái khai báo cho một con trỏ. nếu con trỏ Null, vùng nhớ ko đc cấp phát, giá trị thì k có chỉ tồn tại mỗi cái tên, cout sẽ ra lỗi. Nếu con trỏ
	//khai báo int*p;đây là cách khai báo sai, khi cout sẽ lỗi,gán cx lỗi(đừng tin codeblock) và giống con trỏ NULL, tuy nhiên thà khai báo như null hơn là
	// khai báo như v, muốn dùng thì gán kiểu 2 mà dùng. nếu con trỏ lơ lửng(vd delete) hoặc khai báo kiểu =new int; tức là nó được cấp phát vùng nhớ và
	//giá trị rác, sẵn sàng sử dụng(có lẽ sẽ thắc mắc là tại sao con trỏ lơ lửng sau delete lại vẫn dùng đc vì đơn giản là delete quyền trao lại cho hđh còn
	//con trỏ vẫn mang một vùng nhớ nào đo đc cấp phép và khi ta dùng thì nó lại thuộc quyền sở hữu của ta). Do đó cần nhớ khi khai báo
	// thì nên gán luôn new int{0}; or new int[10]{};(để tránh lơ lửng rác)còn khi delete thì nên gán =NULL(nếu ko bh dùng nx).Như v, dễ thấy con trỏ chỉ đc
	//sử dụng or cout khi nó đc cấp phát vùng nhớ. nếu ta gán trị và địa chỉ thì khi delete cx khác nhau nên gán địa chỉ để delete cho đẹp. Còn một kiểu khai báo
	//nữa đó là *& thì sao. Nó sẽ đặt một tên khác cho con trỏ. Tức là kết hợp từ hai cái trc, xóa sẽ k ảnh hưởng nhưng vùng nhớ của nó lại ko đc cấp phát thêm
	//(lưu ý ko dùng đc với hàm)1 kiểu gán trực tiếp nnx là int*a=p; thì nó giống cái trên chỉ khác là xóa a thì p cx mất hay a và p y hệt nhau(thg dùng cho hàm*()

	//đọc cái trên ta nhận ra rằng vấn đề rò rỉ bộ nhớ th int*a=new int;a=p;thì cái địa chỉ cũ của a sẽ rò rỉ bộ nhớ.Ta ko thể khắc phục đc bằng cách delete
	//vì delete và newint là con trỏ lơ lửng như nhau. Do đó ta phải delete sau đó mới gán =p; Nhưng mà như vậy chẳng phải quá occho, chi bằng ta
	//int *a=p; hoặc int*a=nullptr;a=p;phải hơn k; Tuy nhiên cần tránh th khai báo như vậy cũng như việc trỏ nhiều con trỏ vào 1 vùng nhớ trừ bất đắc dĩ(gán hàm)
	//nếu gán địa luôn thì ta sẽ gán+khai báo. còn không thì gán giá trị thôi.Gán trong trạng thái lơ lửng cho đỡ tốn vùng nhớ
		p5=nullptr;
	//một con trỏ trong quá trình sử dụng có ba trạng thái. 1 là con trỏ lơ lửng, tạo ra khi ta khai báo new int; ko gán, khi ta delete, khi ta cho nhiều con trỏ vào
	//một vùng nhớ mà không xóa hết từng con trỏ một. Con trỏ lơ lửng sẽ trỏ vào một vùng nhớ chưa cấp phát. 2 là con trỏ NULL(nullptr trong C++11),
	//là con trỏ không có vùng nhớ nào cấp phát cho nó hết. Chính vì thế khi xóa thì phải gán bằng NULL nữa mới đc sạch hoàn toàn. 3 là con trỏ đang có giá trị,
	//ta khai báo+cấp phát(kiểu 1)cho con trỏ và gán nó với 1 giá trị cụ thể thì con trỏ có một giá trị và địa chỉ riêng dùng hệt như một biến, còn nếu ta
	//khai báo và gán cho một địa chỉ của biến khác thì nó sẽ có chung một địa chỉ với biến đó.

		delete p2;
	//khi có new thì phải có delete, nó không thực sự xóa một cái gì hết mà nó trao lại quyền sử dụng vùng nhớ đó cho hệ điều hành. lúc này con trỏ trở thành
	//con trỏ lơ lửng và có thể được sử dụng(xem lại trạng thái sẵn sàng của con trỏ). ví dụ p đang có 1 địa chỉ nhớ a, ta delete p thì a quay về với hệ
	//điều hành còn p thành con trỏ lơ lửng, khi đó p chả có lợi gì cx chả có hại gì, tuy nhiên nếu ta sử dụng trong trạng thái lơ lửng thì sẽ có lỗi.()sai k lỗi đâu
	//ta tái sử dụng mà không đật tên khác bằng cách =new int or gán địa chỉ cx đc

	//vấn đề rò rỉ bộ nhớ khác với con trỏ lơ lửng, khi đã có một vùng nhớ rồi, nếu muốn trỏ sang vùng nhớ khác phải xóa nó trước. Nhớ có new là delete là đc

		int a=5;
		int *p;
		p=&a;
	//cách dùng thừa thãi đó là gán địa chỉ bởi vì ta có một biến rồi, mà lại gán vô thì chẳng phải là đổi tên à.Chính vì thế cách dùng kiểu 2 này không phổ
	//biến. ở đây nếu không dùng p nx ta chỉ có thể gán bằng nullptr thôi, không xóa đi đc vì xóa thì mất cả a

	//con trỏ giải quyết vấn đề về mảng ví dụ hiện tượng vùng nhớ ta ko dùng hay thiếu đc là vì khi khai báo int* p=new int; thì p nó nắm giữ một địa chỉ rồi
	//nếu ta muốn gán mảng thì chỉ cần *(p+i) trong for(int i) ra là ok. coi nó là một mảng vì vùng nhớ nó liên tiếp.Sai nhe, dung cấp phát động

		int *p3=new int;
	//nếu ta cho *p3=a gán giá trị và p=&a gán địa chỉ nó khác nhau nhé

		int array[MAX];
		p3=array;
	//cx tương đương p3=&array[0] vậy. array là địa chỉ của array[0]

	//chốt ta sử dụng con trỏ thay thế cho tham chiếu và khi giải quyết bài toán thừa thiếu dung lượng với bộ nhớ động, kiểu ta ko biết cấp phát bao nhiêu bộ nhớ
	//khi ta thấy một biến con trỏ thì ta hiểu là biến đó như biến bình thường nhưng nó trỏ trực tiếp vào bộ nhớ khi dùng giống gán &(và ng ta có thể tạo mảng)

		int **p7;
		*p7=&a;
	//địa chỉ của địa chỉ, nên giá trị của p7 là một địa chỉ khác.

		const int*p8;
		int const*p9;
		const int const *p10=&a;//cách khai báo duy nhất
	//th1 là con trỏ hằng tức là trỏ đến hằng int không đổi đc giá trị int. còn hằng con trỏ là hằng con trỏ, tức là địa chỉ của nó cố định éo đổi đc nhưng
	// giá trị thì đổi được, chỉ con trỏ hằng mới trỏ được đến biến hằng. hằng con trỏ hằng thì cố định cả hai

	//với một hàm, truyền tham chiếu là truyền thêm 1 tên nx, còn truyền tham trỏ thì giống truyền tham chiếu nhưng nó ta có thể dùng nó như 1 vùng ô nhớ,kiểu
	//biến thành mảng cx đc còn gì nx chưa khám phá ra

		*&a=10;
	//con trỏ dùng bth với kiểu biến bth
	//float *a1,*a2; khác float *a1,a2;

		cout << sizeof(p);
	//con trỏ  x64 luôn có kích thước 8 bytes ko bị ảnh hưởng bới kiểu dữ liệu

		int *&p9=p8;
	//đặt một tên khác vẫn cho địa chỉ con trỏ đấy
	//con trỏ null có địa chỉ là 0 và không xác định giá trị, tức là ta gán địa chỉ 0(ko phải giá trị 0) thì tạo ra con trỏ null
	//khi truyền mảng vào hàm thì mảng sẽ ngầm định chuyển thành con trỏ vd int*

		int* array[6];//gán giá trị là con trỏ vô
	//đây là một mảng gồm 6 con trỏ tức 6 địa chỉ. còn int *ptr=new int[6] là một mảng gồm 6 giá trị.Khi ta nhắc tới con trỏ mảng ở th thứ 2 thì ta luôn
	//hiểu là *(p+i) or p[i] mới là giá trị. do array cx là con trỏ nên ta hoàn toàn có thể delete [] array.TH thứ nhất tương đương với kiểu khai báo
	//int **ptr=new int*[6]; cũng gồm mảng gồm 6 con trỏ. Đây là con trỏ ** vì cái mảng gồm 6 con trỏ này bởi vì nó = 6 địa chỉ, mỗi địa chỉ gồm 1 con trỏ
	//lại chứa địa chỉ.ptr,ptr+1,ptr+2,... là các địa chỉ của địa chỉ. còn *ptr,*(ptr+1),... là các giá trị, mà giá trị lại là con trỏ bên trong, tức là address

	//các địa chỉ thì cách nhau theo đúng sizeof kiểu dữ liệu nhưng nó vẫn sẽ lưu giữ đc 8 bytes dữ liệu mỗi ô

		int *array = new int[10](); // mảng động có 10 phần tử 0

	//mảng tĩnh int a[1]; khác với mảng động int *a=new int[1](); ở chỗ là mảng động thì số lượng phần tử không cố định, ta có thể delete r resize
	//còn mảng tĩnh thì ko delete đc, ta phải dùng mảng mới và sẽ tồn tại trong suốt hàm, còn mảng động tùy biến ta sử dụng. Dù code dài nhưng hiệu quả hơn.

		int value = 10;
		void *voidPtr = &value;
		cout << *static_cast<int*>(voidPtr) << endl;
	//con trỏ void có thể trỏ đến bất cứ kiểu dữ liệu nào(auto) nhưng ko thể truy xuất do rõ địa chỉ nhưng lại ko biết kiểu dữ liệu nên phải ép kiểu
	//ta có thể ứng dụng con trỏ void cho hàm mà nhiều kiểu dữ liệu với, tránh mỗi kiểu dữ liệu lại phải viết một hàm

	//mỗi function khi đứng riêng thì nó lưu địa chỉ của hàm ví dụ hàm test thì cout << test; sẽ in ra địa chỉ của ham test
	*/

	/*Exercise Pointer two dimension array*/
	/*
		//case1
	//    int row=0;
	//    int col=0;
	//    cout << "Insert the row: "; cin >> row;
	//    cout << "Insert the col: "; cin >> col;
	//
	//    int **two_array=new int*[row];
	//    for(int i=0;i<row;i++)
	//    {
	//        two_array[i]=new int[col];
	//    }
	//
	//    for (int i=0;i<row;i++)
	//    {
	//        for (int j=0;j<col;j++)
	//        {
	//            cout << "Insert array[" << i << "][" << j << "]= ";
	//            cin >> two_array[i][j];
	//        }
	//    }
	//    cout << endl;
	//    for (int i=0;i<row;i++)
	//    {
	//        for (int j=0;j<col;j++)
	//        {
	//            cout << "Value[" << i << "][" << j << "]= " << two_array[i][j] << "\t";
	//        }
	//        cout << endl;
	//    }
	//
	//    for (int i=0;i<row;i++)
	//    {
	//        delete [] two_array[i];
	//    }
	//
	//    delete [] two_array;
	//    cout << endl;

		//case2
		int row2=0,col2=0;
		cout << "Insert the row: "; cin >> row2;
		cout << "Insert the col: "; cin >> col2;

		int *array=new int[row2*col2];

		for (int i=0;i<row2;i++)
		{
			for (int j=0;j<col2;j++)
			{
				cout << "Insert array[" << i << "][" << j << "]= ";
				cin >> array[i*col2+j];
			}
		}

		for (int i=0;i<row2;i++)
		{
			for (int j=0;j<col2;j++)
			{
				cout << "Value[" << i << "][" << j << "]= " << array[i*col2+j] << "\t";
			}
			cout << endl;
		}
	*/

	/*Function Pointer*/
	/*
		void(*FnctPntr)(int*)=test;//or =&test đều đc=>C1:k nên dùng

		int a=8;
		(*FnctPntr)(&a);
		(FnctPntr)(&a);//=>dùng * hay k *.khi khai báo test hay & test đều ok=>nó thoải mái k bh báo lỗi chỉ có mỗi lúc khai báo buộc có *FnctPntr thôi 
		cout << endl;
	//do biến con trỏ có thể thay thế cho hàm nên ta hoàn toàn có thể truyền vào một hàm cho một hàm. Nhờ vậy mọi bài toán đòi hỏi nhiều hàm mà code chỉ khác
	//nhau 1 tí thì ta hoàn toàn có thể gom chung lại và đặt điều kiện để thực hiện nhiều hàm khác nhau trong một hàm ta có thể dùng switch case nếu là giá
	//trị nào or dùng hàm bool nếu như có 2 điều kiện or phức tạp hơn nữa. Thay vì switch case vô dụng ta có thể truyền vào hàm phục vụ cho điều kiện if luôn
        //thay vì truyền số và điều kiện với số thì điều kiện vs hàm phong phú hơn nh

		//Ví dụ truyền mảng và tính tổng các số ở vị trí chẵn, lẻ có thêm đối số mặc định là hàm
		int size;

		cout << "Insert the size of array: "; cin >> size;

		int *array=new int[size];

		function<bool(const int&)> Pntreven=even;//thư viện functional-C2:nên dùng
		auto Pntrodd=odd;//C3:k nên dùng vì éo biết truyền cj vào

		int sum_even=Sum(array,size);
		int sum_odd=Sum(array,size,Pntro);//con trỏ hàm khai báo ngay trc hàm cx đc.
		//ta truyền trực tiếp hàm or con trỏ hàm đều đc nhưng đối số của hàm khi viết vẫn là giống con trỏ hàm=>nếu chỉ để truyền vào hàm v thì k cần con trỏ hàm mà truyền tt luôn, dùng con trỏ hàm vào mđ khác
		cout << endl;
		cout << "Sum even: " << sum_even << endl;
		cout << "Sum odd: " << sum_odd << endl;
		delete [] array;
	*/

	/*Insert name by array char*/
	/*
		//case1 kiểm soát nhập bao nhiêu
	//    char *name=new char;
	//    cout << "Insert name: ";
	//    int j=0;
	//    for (int i=0;i<20;i++)
	//    {
	//        cin.get(name);
	//        if(name[i]=='\n')
	//        {
	//            j=i;
	//            break;
	//        }
	//    }
	//
	//    cout << "\nUr name is:";
	//    for (int i=0;i<=j;i++)
	//    {
	//        cout << name[i];
	//    }

		//case2 nhập chuỗi bao nhiêu cx ok
	//    string name1=" ";
	//    cout << "Input name: ";
	//    getline(cin,name1);//dùng cin >> thì sẽ kết thúc khi có dấu space or enter, getline là cái chuyên dùng cho string
	//    cout << name1;

		//case3 nhập 2 tên
	//    string name2=" ";
	//    cout << "Input name: ";
	//    getline(cin,name2,'_');
	//    cout << "\n" << name2 << endl;

		 //case4 nhập tên trực tiếp với mảng char mà ko dùng vòng lặp nhưng ko kiểm soát đc
	//     char *name3=new char[10];
	//     int age=0;
	//     cout << "input age: "; cin >> age;
	//     cout << "Input name: ";
	//     cin.ignore(1,'\n');//có thể(32767,'\n')(tức là xóa 32767 ký tự đầu kèm hoặc đến khi gặp kí tự '\n')or(số bat kì,'\n')or(1)(nỏ kí tự trc đó)or((mặc định)
	//     cin.getline(name3,19);//1 ky tu ket thuc xâu
	//     cout << name3;
	//getline(cin,,) và cin.getline(,,) là hai cái như nhau chỉ khác ở cái đầu dùng cho string còn cái sau là dùng cho char array(or simmple fflush(stdin);)
	//2 cái trên là lấy cả dòng và dấu cách rồi enter thì mới kết thúc việc nhập ký tự.cin >> bth là nhập đến gặp dấu cách thì lưu vào bộ nhớ đệm và tự động
	//dùng phần đó để lưu vào cái đằng sau, enter để kết thúc. getchar()=cin.get(); là nhập kí tự liên tiếp, tính tất cả kể cả dấu xuống dòng và space, nếu là
	//char thì sẽ lưu từng ký tự một vào, chỉ đc 1 ký 1 lần, nếu là char array thì sẽ lưu lần lượt đến hết array, phải có đk if thì mới ngừng việc nhập mảng.
	//chú ý getchar và cinget có 1 ký tự kết thúc xâu là enter tính cả nên k lưu bộ nhớ đệm. hai cái kia sẽ lưu enter vô bộ nhớ đệm nên có flush.Khi dùng getchar
	//với kiểu char ta buộc cho vô vòng lặp+đk vì kết thúc 1 kí tự nó sẽ end

	//cin.getline và getchar có 1 điểm khác nx là getchar ta kiểm soát đc số lượng kí tự ta nhập bằng cách thêm điều kiện if và biến int j do. Nhờ v, getchar
	//đc vận dụng trong các bài mà ta can thiệp vào từng phần tử của mảng chứ ko phải ý nghĩa 1 sentence.còn getline dùng với các bài đơn giản hơn,ko kiểm soát đc
	//một điểm khác biệt của ký tự với số liệu là khi ta có array, ta cout << array số sẽ ra địa chỉ, còn cout << array ký tự sẽ ra toàn bộ dãy kí tự ta nhập,
	//các ky tự rác sẽ ko đc xuất ra.nhờ v, mảng ký tự ta cho cực lớn cũng chả sao, nó ko cout ký tự thừa.

	//vấn đề về cout có 2 cách.nếu dùng for thì ta phải kiểm soát đc phần tử(nếu ko sẽ ép cout ra space, ký tự lạ).Nếu ko kiểm soát đc thì
	//cách tối ưu nhất là ta cout bth với mảng char(auto dùng).Vì điểm khác biệt của int và char mà, tuy nhiên để tránh nó ra ký tự lạ thì lúc đầu
	//ta phải gán cho nó {} tức là \0 hết lúc tạo mảng.Đôi khi mảng có vấn đề nên vẫn phải cout kiểu for.
	*/

	/*Student Info*/
	/*
		unsigned int numberofstudent;
		cout << "how many student: "; cin >> numberofstudent;
		student *student=InputInfo(numberofstudent);
		OutputInfo(student,numberofstudent);

		auto Pntrmin=Fmin;
		int max=Find(student,numberofstudent);

		int min=Find(student,numberofstudent,Pntrmin);

		cout << endl;
		cout << "Student with max mark " << student[max].mark << " have id " << student[max].id << endl;
		cout << "Student with min mark " << student[min].mark << " have id " << student[min].id << endl;

		delete student;

	    Emp();
	    employee nth={"Nguyen thu hieu",700,"high"};//dùng làm kiểu trả về của hàm cx ok. Neu struct lồng struct =>{{}}
	//điểm khác biệt duy nhất của biến struct với một biến thông thường là nó éo khai báo giá trị đc. khi đứng bth nó vẫn là một giá trị(k phải địa chỉ)
	*/

	/*Spin number*/
	/*
		//case1
	//    int *number=new int;
	//    cout << "Insert a natural number: "; cin >> *number;
	//    Spin_number(number);
	//    delete number;

		//case2
	//    char *Pnumber=new char[20];
	//    cout << "Insert a natural number: ";
	//    fflush(stdin);
	//    int j=0;
	//    for (int i=0;i<20;i++)
	//    {
	//        (Pnumber[i])=getchar();
	//        if(Pnumber[i]=='\n')
	//        {
	//            j=i-1;
	//            break;
	//        }
	//    }
	//    Perfect_spin_number(Pnumber,j);
	//    delete Pnumber;
	*/

	/*String array+boolean*/
	/*
	//thống nhất với mảng khai báo dùng {}, còn với biến dùng = trực tiếp
	//mảng ký tự luôn kết thúc bằng \0-ký tự null(hay ký tự kết thúc chuỗi), cứ gặp \0 là kết thúc dù đằng sau vẫn còn.
	//Nếu gán"\0"thì cout nó k ra 1 kí tự j hết nhưng nếu nhét vào for rồi ép cout thì sẽ biến thành space
	//    char a[5]="12345";//sai vì thiếu a[4] auto='\0'
	//khai báo
	char a[5]{"1234"};char b[10]{};
	//gán thì gán từng phần tử ko gán trực tiếp đc
	//sự khác biệt giữa int và char mảng khi kết hợp con trỏ khai báo
	//khai báo
	int *Pa_int = new int[10]{10,5};int *Paint=new int[10]{};//ký tự ko dung thanh số 0=> có thể cấp phát 10 ô nhớ int như thế này như malloc v
	//ký tự con trỏ mảng ko khai báo "string" đc khi dùng con trỏ như char *Pa_cha=new char[10]{"Hell"};,vẫn khai báo đc ký tự
	char *Pa_cha=new char[10]{'H','l'};char *Pacha=new char[20]{};//Pacha="Hello";->sai// ký tư ko dùng thành \0 tức ko hiện ra j cả(mảng con trỏ buộc khai báo điền vào so luong phan tu)
	//gán ngược với char, char mảng con trỏ có thể gán "string"=>> k gán đc nhé, nếu gán dùng strcpy_s=> bh thì thành con trỏ KT gà hơn mảng KT
	//nếu khai báo hay gán từng phần tử thì luôn đc
	//với kiểu ký tự char ta không khai báo gì cả thì mặc định nó là \0 hết, tuy nhiên để tránh lý thuyết có vấn đề ta vẫn gán \0

	//về vấn đề gán mảng ký tự, thông thường với 1 mảng bất kì sau khi định nghĩa ta muốn gán, ta chỉ có thể gán mảng[từng ô] chứ ko thể gán chay toàn bộ
	//kể cả mảng ký tự. Ở phần trên tuy con trỏ mảng ký tự ta gán đc kiểu =""; nhưng sẽ sinh ra lỗi vì ta ko cin.getline đc nx. Lỗi này đc gọi là core dump.
	//Đó là lỗi cố tình chỉnh sửa vào bộ nhớ chỉ đc đọc,hoặc giải phóng bộ nhớ. Do đó ta chỉ có thể gán ngay từ lúc định nghĩa. ===>> ko nên gán riêng
	//mảng ký tự. Mà thực ra cx chẳng cần gán vì mặc định \0 het r
	//nếu vẫn chày cối gán thì chỉ có 1 cách ko lỗi đó là char[]+strcpy_s.Do đó khi thao tác với class ta màu mè lý thuyết vc gán mảng ký tự thì ko dùng con trỏ
	//(string thì có thể khai báo ="" r gán bằng phép cộng+="";)
	//Stored in read only part of data segment
	//   char *str;
	//   str = "GfG";//địa chỉ là bộ nhớ chỉ đọc ko đc gán=> gán thì là địa chỉ, cout thì là chuối kí tự
	//Problem:  trying to modify read only memory
	//   *(str+1) = 'n';
	//   cout << "Helo:";//==> lỗi. nếu muốn thì phải khai báo rõ mảng ra bao nhiêu phan tu. Nếu k thì dùng vector. Vì bộ nhớ ấy chưa đc cấp phát nên chỉ đọc
	//Nói là v nhưng vẫn có cách gán "string" cho kiểu char là ép dung hàm strcpy(,)(thực chất là hàm copy)
		strcpy_s(b,10,"Hello");//bỏ 10 cx đc nếu ko sợ lỗi thiếu.strcpy_s k dùng đc với con trỏ

		bool a1=true;
		cout << boolalpha << a1 << noboolalpha << a1;
	//cin bool vào thì luôn là 1 or 0

	//có 1 TH đb là const char* ta có thể khai báo gán ngay từ đầu dạng "", là đối số của hàm và cx là GT trả về vs ĐK nó là hằng\
    tuy nhiên ta nên dùng string thôi vì nó có thể chuyển sang const char ez. Char* k có const thì nó cout vẫn đc nhưng gán Kí tư thoi
	*/

	/*Vector*/
/*
		auto a9=9;
		vector<int> test(4,1);
		vector <int> test1(40);
		vector<double> double1{1,1,1,1};
		vector<bool>testb{ true, false, true, true };
		cout << testb[1] << endl;
		test.reserve(6);
		test.reserve(5);//capac ko làm nhỏ đc
		cout << test.size() << " and " << test.capacity() << " and " << test.at(3) << endl;
		test.resize(7);//size()kiểu trả về là size_t
		cout << test.size() << " and " << test.capacity() << " and " << test.at(4) << endl;
		//1vector có 2 phần: (size + phần dư) -> capacity trả ra (size+phần dư); resize(thay đỏi phần size); reserve chỉnh lên cả (size+phần dư);
		//size trả ra phần size
		for(auto const &item: test)//bản chất truyền mảng vào hàm là truyền con trỏ nên ko dùng đc kiểu này trong hàm
		{
			cout << item << " ";
		}
		test.push_back(5);
		test.pop_back();
		test.pop_front();
		cout << test.back() << endl;
		cout << test.front() << endl;
		cout << test.empty() << endl;
		IVector(test1);
		OVector(test1);
		vector<int>::iterator position = test.begin();
		vector<int>::iterator position1 = test.end();//end ko phải địa chỉ giá trị cuối mà là sau đó tức là giá trị 0
//iterator là một kiểu biến trỏ vào địa chỉ vùng nhớ STL, dùng với chuỗi số or ký tự(con trỏ vector)
//gán 1 biến position trỏ vào địa chỉ đầu tiên của mảng test1. nó là con trỏ địa chỉ k lq đến vector, ta trỏ ra ngoài cx k ảh
		position1 -= 0; //giảm 0 cục, giống như 1 pointer nhưng k cout đc địa chỉ
		vector<double> third(position, position1);
//điều đặc biệt là kiểu biến này truyền đc vào vector kiểu này,con tror đầu tiên sẽ lấy vị trí là 3
//còn position1 lấy giá trị.=>(3,)

		test.swap(test1);//như kiểu đổi tên cho nhau, con trỏ position thành của test1

		*position = 5;
		test1.insert(test1.end(), 5, 9);
		test1.insert(test1.begin(), 8);//x push_back
//hàm insert sẽ phá hủy iterator đang trỏ đến vector, vì nó ko đơn giản là đổi giá trị.K đc dùng các iterator trc

		vector<int>::iterator ptr1;//đỡ nghĩ nhiều
		for (ptr1 = test1.begin(); ptr1 < test1.end(); ptr1++)
			cout << *ptr1 << " ";
		cout << endl;

		OVector(test1);
		vector<int>::iterator ptr2 = test1.begin();
		advance(ptr2, 2);
		auto it = next(ptr2,1);//nó k tăng ptr2 thực lên mà trả về giá trị sau giá trị tăng 2 kiểu iterator.advance la void, con next tra ve iterator
		vector<int>::iterator it1 = prev(ptr2, 1);
		//đây là cách gán con trỏ ở vị trí bất kì chú k phải lúc nào cx end vs begin
		cout << "The position of new iterator using next() is: " << *it << endl;
		cout << "The position of new iterator using prev()  is: " << *it1 << endl;
		
		copy(test.begin(), test.end(), inserter(test1, it));//hàm inserter trả về insert_iterator buộc là đối số ở đây
		test1.erase(test1.begin() + 2);//dùng .begin() làm đối sô khi xóa mảng phần tủ chỉ định

		vector<vector<int>> abc(20);
		//khi tạo vector mảng 2 chiều thì muốn gán cho chiều thứ 2 thì chiều thứ nhất phải rõ số lượng phần từ khi ta dùng trực \
		tiếp, vì ta k thể push_back nó phần tử chiều 1 đc. Ý là có 2 cách dùng, 1 là khai báo như này rõ phần tử chiều dọc và gán\
		vào phần tử chiều 2, 2 là tạo ra vector<int> lần lượt r push_back từng vector vào abc(dùng k1 vì dùng TT đc)
	   abc[0].push_back(1);
	   cout << abc[0][0];
		
//khi gặp dạng ghép chuỗi vào chuỗi ở vị trí nào. Nhớ rằng các đối số là cố định đúng kiểu ko thể thay thế
//ko thể copy chính nó. Nếu muôn thì gán vào 1 iterator khác r copy VD: vector<int> copy{ test1 }; r hàm copy

//vector là một lớp và ta k nên dùng con trỏ với nó vì ... ko xóa con trỏ
//capacity chỉ tăng ko giảm với reserve nhưng trong quá trình code ta ko dùng đên nó, chỉ dùng resize.
//resize tùy ý, resize(0) nếu muốn xóa sạch
//để nhập mảng vector ta ko đc dùng cin trừ khi đã biết rõ có bao nhiêu phần tử. Để nhập ta dùng push_back.
//khi phần tử hiện có mà tăng lên vượt capacity thì capac se+ 50% size() hiện có. Đó là sự di chuyển sang vùng nhớ mới tự động
*/

//!
/*Else*/
#ifdef ABC*2 < 6
#undef ABC 
#define ABC (4+1)
	cout << "Hello";
#endif // ABC
#if 0//dùng làm comment vô hạn cx đc
	cout << "Hello"
#elif 1
	int e;
#else
	int a(6.7);//trực tiếp ép kiểu
//    int a1{6.7};
	int a0 = 6.7;//sao chép ép kiểu
//const và auto là 2 loại đặc biệt luôn là khai báo trực tiếp
	static int c;// nửa toàn cục, nửa cục bộ, dùng làm biến đếm quá hợp

	cout << c << endl;
	double b = 7.8;
	cout << b + a << endl;
#endif
	char d[10] = { '1','2' };
	int length = strlen(d);// với mảng char ko cần biến đếm nx
	cout << length;

	//muốn gán số trực tiếp có 2 kiểu là int và const int& thg dùng còn int& ko gán đc. Ta nhận ra rằng khi có const thì & ko còn mang
	//nghĩa đặt tên khác nữa(ko đúng vs const int *) mà là gán trực tiếp sau đó nó dùng địa chỉ, giống kiểu int& cho hàm ấy nhưng 
	//lại gán đc trực tiếp+là hằng số kbh có int&a; vì khai báo tham chiếu buộc đi kèm với 1 biến khác, ko số cụ thể, ko trực tiếp

	int Ptest = 9;
	const int* Ptest_ = &Ptest;
	const char* Pchar_test = "BUSS";
	//với const char nó khác hẳn cmn giữa int và char, char vẫn như cũ, nó vẫn gán trực tiếp 1 cục cố định đc.int phải đúng qtắc

	string s = "123456j789";
	for (int i = 0; i < 10; i++)
	{
		cout << s[i];//h ms biết string là mảng char
	}
	cout << endl;
	//ng ta thg dùng assert(pointer); để kt con trỏ truyền vào hàm ko null

	string strin;
	cin >> strin;
	if (cin.eof())
	{
		cout << "N" << endl;
	}//kiểm tra trong chuỗi có ký tự EOF là Ctrl Z ko=> éo bh dùng
	if (cin.good())//có ích, kiểm tra nhập đúng ez
	{
		cout << "Y" << endl;
	}

	cout << "The current line is " << __LINE__ << endl;
	cout << "The address of source file is " << __FILE__ << endl;
	cout << "Standard C++ conforming " << __cplusplus << endl;//6 là có theo chuẩn standard c++
	cout << "Function: " << __FUNCTION__ << " or " << __func__ << endl;

	//cách dùng define r ghi log là xog

#define S1(x) #x
#define S2(x) S1(x)
#define LOCATION __FILE__ " : " S2(__LINE__)
	cout << LOCATION;
	//phân tích cách hoạt động, bình thường #define A B C.... thì A sẽ bằng với chuỗi các giá trị đằng sau. Ta gọi là A và B
	//đầu tiên khi compile gặp 1 marco.Nếu marco ko có biến, nó sẽ thay luôn giá trị B và đó luôn. Do marco ko biết code C++
	//nó chỉ làm thế vào mà k biết j hơn. Nếu marco có biến A(x) thì nó sẽ giữ nguyên và gán chữ x đó vào A, sau đó nó gán x vào 
	//B bằng cách B có # thì lấy chữ x tiếp, nếu ko có # thì thế giá trị thực tế của x trong code của ta. Sau đó thế toàn bộ cục 
	//B đó vào A(x) trong code.Xét code trên đầu tiên là S2 có biến, nó thế chữ __LINE__ vô gặp S1(x) ko có # nó thế giá trị là
	//sô vào. Xog gặp # nên giá trị số ta chuyền vào thành chuỗi. Chuỗi đó chép vô LOCATION và cout ra. Câu hỏi đặt ra là tại sao
	//ta lại dùng #x dù đã chuyển thành số r sao k lấy số luôn? Là do nó là cơ chế thay thế nếu ko có # thì sẽ là <string>:<số>
	//thì ta ko cout ra đc nên biến cả LOCATION thành 1 string để cout ra. Đặc biệt marco khi thế vào số thì như bth nhưng nếu 
	//là chuỗi thì khi thế vào code sẽ tự động có "" khi cần thiết, còn lúc ta thế biến A cho B thì dấu "" chỉ biểu hiện bên trong
	//là ký tự chứ ko bị thế vào code tức LOCATION=<tênfile>:<string dòng> và nó là 1 string liên tiếp ko có " nào ở giữa
	//Tức là quyết định truyền vào dạng string hay là giá trị biến
#
#define PRINT_HW(name) cout << "HELLO WORLD, " << #name
	int xy = 9;
	PRINT_HW(xy);
#define ADD(x,y) (x+y)
	int w = 0, g = 1;
	int q = ADD(g, w);
#define ITEM_PRICE(type,name) type premium_##name, \
normal_##name, low_##name
	ITEM_PRICE(int, bike_price);
	low_bike_price = 20;
	premium_bike_price = 100;
	//define k pb đc ký tự j vs j, nó chỉ đơn giản thế chỗ thôi. ## nối 2 token
#define ITEM_FIGHT(type,name) \
type name##low_level; \
type name##_high_level; \
type name##_normal_level//dấu chấm phẩy thì ko lq j đến nhau; còn dấu , liệt kê 1 loại đối tượng
	ITEM_FIGHT(int, sword);
	sword_normal_level = 10;
	//dùng điều kiện ()?: cx khá phổ biến
	cout << EXIT_FAILURE;

	cout << endl << std::max(low_bike_price, premium_bike_price) << " " << std::min(low_bike_price, premium_bike_price) << endl;

	system("cls");
	cout << "heelo" << endl;
	system("pause");

	//Bá đạo về loại đối số: 
	//Khi truyền đối số cho hàm: & thì chỉ truyền giá trị còn * thì nó chỉ truyền địa chỉ, nó đều dùng TT.Tuy\
	nhiên như thế nó k tối ưu, nếu ta thêm const ở đầu thì có thể truyền cả hằng và trực tiếp giá trị. Sâu hơn nếu ta truyền *& thì \
	là đặt tên khác cho con trỏ, giống hệt con trỏ thôi nhưng xóa sẽ k ảnh hưởng con trỏ ban đầu, nếu truyền const*& thì cx thế nhưng\
	chỉ truyền đc hằng địa chỉ từ ngoài vào
	//Về giá trị trả về của hàm return: có 2 kiểu trả về là giá trị và địa chỉ(dùng trực tiếp cx v) Tuy nhiên khi ra khỏi hàm thì giá\
	trị bị xóa nên ta chỉ có thể gán địa chỉ, mà GT bị xóa nên tất cả ra bên ngoài chỉ còn là 0.Do đó k nên trả về với & * và const*\
	const& đặc biệt là tuyệt đối k dùng *&,const *&, vì nó phức tạp và toàn lỗi.Nếu ta cứ trả về thì * & vẫn như cũ. const* const& sẽ\
	ép chỉ gán vs hằng. tuy nhiên nh TH ta vẫn dùng đc nếu như ta tìm cách gán biến ra khỏi hàm mà nó k bị mất, đó là gán giá trị trực\
	tiếp và gán biến trong 1 class. vs class ta có thể gán địa chỉ hay giá trị đều ddc vì ra khỏi hàm k bị xóa ha. Còn TH2 là gán giá\
	trị trực tiếp thì chỉ đúng với ký tự vì 10 là int nhưng "10" là const char* nên ta gán "" vs const char *.Quy tắc: khi gán thì char\
	mảng(hay char*) mang theo địa chỉ(k tính cái return) còn khi cout thì nó lại là GT, nên gán ra ngoài là gán địa chỉ const char*
	//với con trỏ void hạn chế sử dụng. con trỏ void trỏ tới bất kỳ kiểu gì nhưng khi cout phải static_Cast

	cout << 1.9e4 << 1.9E-4 << 1.9f << 1.9L << endl;//e,E là 10 mũ ký hiệu KH, L=long double, f=float
	double zero{ 0.0 };
	double posinf{ 5.0 / zero }; cout << posinf << endl;//inf
	double neginf{ -5.0 / zero }; cout << neginf << endl;//-inf
	double nan{ zero / zero }; cout << nan << endl;//NaN(ind)

	//nullptr là con trỏ null chuẩn(1 con trỏ), còn NULL là số 0(1 giá trị). Khi truyền vào hàm máy sẽ hiểu pb 2 loại nv

	//toán tử ! có độ ưu tiên cực cao; && ưu tiên hơn ||
	//!(A&&B) = !A||!B ; !(A||B) = !A && !B (DeMorgan)
	//if(a!=b!=c!=d) chỉ đúng với boolean

//const int &a=b;thì k còn mang ý nghĩa đăt tên khác nữa mà đó là gán cấp vùng nhớ tĩnh bth

	cout << numeric_limits<wchar_t>::max() << endl;
	cout << numeric_limits<int>::min() << endl;//giá trị dương nhỏ nhất có thể biểu diễn đc (vs floating point)
	cout << numeric_limits<float>::epsilon() << endl;//kc giữa 1 và số kế tiếp của floating point(underflow) vì nó k bao hết
	cout << numeric_limits<int>::lowest() << endl;//GT nhỏ nhất X max
	cout << numeric_limits<float>::infinity() << endl;//ra inf(GT vô cực dương của chấm dộng)
	cout << numeric_limits<float>::signaling_NaN() << endl;//ra nan
	cout << numeric_limits<float>::quiet_NaN() << endl;//ra nan
	cout << numeric_limits<float>::denorm_min() << endl;//số dương nhỏ nhất(underflow)
//numeric_limits<> là 1 class template giúp ta hiển thị giới hạn. 

	int bientoancuc = 80;
	cout << bientoancuc << " ";
	cout << ::bientoancuc;

	cout << setprecision(3) << (float)1 / 3 << endl;
	cout.precision(2);
	cout << 1 / 3.f << endl;//f sau số sẽ biến kiểu chấm động float ko sẽ là int
	cout << 3 / 2 << endl;



	//mt19937 random_engine(time(NULL));
	//uniform_int_distribution<int> distribution(0, 100);
	//cout << distribution(random_engine);
	//int tel = distribution(random_engine);//ko gán đc địa chỉ đâu
	//cout << endl << tel << endl;
	//cout << endl << tel << endl;
	//cout << endl << tel << endl;
	//cout << endl << tel << endl;
	assert(0);
	cout << endl;
#line 10 "Hello.txt"// đổi tượng trưng chả để lm j
	cout << "The current line is " << __LINE__ << endl;
	cout << "The address of source file is " << __FILE__ << endl;
	cout << "The current line is " << __LINE__ << endl;

	// exit(0);cản trở class destructor//giống return cho hàm
	_getch();
	return 0;
}
