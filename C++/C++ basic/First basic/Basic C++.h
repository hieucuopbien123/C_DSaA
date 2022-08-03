#include <iostream>
#include <conio.h>//_getch();
#include <math.h>
#include <string>
#include <iomanip>//setprecision,setw()
#include <ctime>//time(0)
#include <cstdlib> //srand(),rand(),exit() 
#include <random>
#include <functional>
#include <cstring>//strcpy_s(,,);
#include <vector>
#include <iterator>

using namespace std;

#define LENGTH_ARRAY 256
#define PI 2 * acos(0)
#define MAX 5

int bientoancuc = 90;

const extern int fix_v = 100;//extern cx dùng cho hàm
//extern chỉ dùng cho global vì khi gán một biến glo bất kì đâu trong 1 solution xog ta định nghĩa nó bằng extern ở bất cứ project nào 
//trong solution thì đều dùng được biến đó. Phạm vi quét ghê hơn cả global. Ta cx có thể dùng extern trong file.h r include ở file khác cx đc
//static thì hiển nhiên phạm vi không thể bằng extern nên k kết hợp đc rùi dù nó cx là global

//biến cục bộ < biến toàn cục < biến tĩnh< biến extern.biến cục bộ dùng trong câu lệnh, ra ngoài là mất. Biến toàn cục dùng trong 1 file trong 1 dự \
án.nêu ta include trong file khác cùng dự án thì vẫn dùng đc. biến tĩnh nếu khai báo trong 1 hàm nhỏ thì nó chỉ dùng trong hàm đó và k mất GT trong\
toàn bộ chương trình, khi khai báo như toàn cục thì nó lại mạnh như toàn cục. Biến extern kéo mẹ sang dự án khác.
//Tuy là v nhưng trong nh TH có thể bị lỗi. Do đó, ta sẽ có quy tắc. Khi dùng gloabal thì thêm g_ đằng trc. Khi dùng gloabal thì nên\
dùng const, còn global mà k const thì dùng static vô. Vì làm các biến trong thư viện động nh khi bị lỗi v

using I = int*;//dùng đc với class
typedef int i;

typedef struct Books
{
	int number = 0;
} Book;//=> Đặt tên khác cho 1 loại biến. Biến struct hay class cx là 1 loại biến. éo khác gì bth cả

//điểm lợi nếu sau này ta muốn đổi thành double ta đổi ở đây chú ko phải tìm đổi từng chữ
struct student
{
	unsigned int id = 0;
	char* name = new char[20]{};
	char sex = ' ';
	float mark = 0;
	void goodstudent(int MARK = 10)
	{
		mark = MARK;
	}
	void addmark()
	{
		mark = mark + 1;
	}
};
struct employee
{
	char name[20]{};
	float salary = 0;
	string exp = { "Low" };
};
struct circle
{
	double x = 0, y = 0;
	double radius = 0;
	void Circle(double& X, double& Y)
	{
		x = X;
		y = Y;
	}
	double perimeter()
	{
		return 2 * PI * radius;
	}
	void area()//hàm show giá trị thg là void
	{
		cout << "Area of the circle is " << PI * radius * radius << endl;
	}
};
struct person
{
	char sex = 'M';
	char name[20];
	string add;
};
struct school
{
	person* Person = new person;
};

inline void Simplify(int& num, int& deno)
{
	if (num == 0)
	{
		deno = 1;
	}
	else
	{
		int b = deno;
		int a = num;
		deno = abs(deno);
		num = abs(num);
		for (int a = num - 1; a >= 2; a--)
		{
			if (num % a == 0 && deno % a == 0)
			{
				num /= a;
				deno /= a;
				break;
			}
		}
		if (a * b < 0)
		{
			num = -num;
		}
	}
}
/*
int MaxValueArray(int& index, int x)
{
	int array[LENGTH_ARRAY]{};

	cout << "Insert number: \n";
	for (int i = 0; i <= 4; i++)
	{
		cout << "Input a[" << i << "]: "; cin >> array[i];
	}

	int MaxValueArray = array[0];
	index = 0;

	for (int i = 0; i <= 4; i++)
	{
		if (MaxValueArray < array[i])
		{
			MaxValueArray = array[i];
			index = i;
		}
	}
	cout << "\n";
	if (x > 0)
	{
		for (int i = 0; i <= 3; i++)
		{
			for (int j = i + 1; j <= 4; j++)
			{
				if (array[i] > array[j])
				{
					int a = 0;
					a = array[i];
					array[i] = array[j];
					array[j] = a;
				}
			}
		}
		for (int i = 0; i <= 4; i++)
		{
			cout << "Input a[" << i << "]: " << array[i] << endl;
		}
	}
	return MaxValueArray;
}
*/
/*
void test(int *ptr)//truyền vào địa chỉ
{
	cout << ptr << " va " << *ptr << endl;
	(ptr)? (cout << "You passed in " << *ptr << '\n') : (cout << "You passed in a null pointer\n");//?:
}
*/
/*
void Insert_array(int *array,const int &size)
{
	mt19937 random_engine(time(NULL));
	uniform_int_distribution<int> distribution(0,100);
	for (int i=0;i<size;i++)
	{
		array[i]=distribution(random_engine);
	}
}

void Print_array(int *array,const int& size)
{
	for (int i=0;i<size;i++)
	{
		cout << "Value[" << i << "]= " << array[i] << "\t";
	}
}
*/
/*
bool even(const int& a)
{
	return a%2==0;
}
bool (*Pntro)(const int& a);
bool odd(const int& a)
{
	return a%2!=0;
}

int Sum(int *array,const int &size, bool(*Pntr)(const int&)=even)
{
	int a=0;
	for(int i=0;i<size;i++)
	{
		if(Pntr(i))
		{
			a=a+array[i];
		}
	}
	return a;
}
*/
/*
student *InputInfo(const unsigned int& numberofstudent)
{
	student *Istudent=new student[numberofstudent];//vẫn 8bytes bth

	for (int i=0;i<numberofstudent;i++)
	{
		cout << "Input student " << i+1 << endl;
		cout << "Input name: "; rewind(stdin); cin.getline(Istudent[i].name, 19);
		cout << "Input id: "; cin >> (Istudent+i)->id;
		cout << "Input sex(M is male, F is female): "; cin >> (*(Istudent+i)).sex;
		cout << "Input mark: "; cin >> (*(Istudent+i)).mark;
		cout << endl;
	}
	Istudent[0].addmark();
	Istudent[0].goodstudent();

	return Istudent;
}
bool max(const float& a,const float& b)
{
	return a<b;
}
bool Fmin(const float& a,const float& b)
{
	return a>b;
}
int Find(const student* student,const unsigned int& numberofstudent,bool(*Pntr)(const float&,const float&)=max)
{//khi const struct thì mọi cái bên trong dều là const
	float mark=student->mark;
	int id=0;
	for (int i=0;i<numberofstudent;i++)
	{
		if (Pntr(mark,student[i].mark))
		{
			mark=student[i].mark;
			id=i;
		}
	}
	return id;
}
void OutputInfo(student *student,int numberofstudent)
{
	for(int i=0;i<numberofstudent;i++)
	{
		cout << "Info student " << i+1 << endl;
		cout << "Student name: " << (student+i)->name << endl;
		cout << "Student id: " << (student+i)->id << endl;
		cout << "Student sex: ";
		if (student[i].sex=='M')
		{
			cout << "Male\n";
		}else{
			cout << "Female\n";
		}
		cout << "Student mark: " << (student+i)->mark << endl;
	}
	cout << endl;
}
*/
/*
void Spin_number(int* number)
{
	int fix=*number;
	int a=(log10(*number));//tự ép kiểu về int khi khai báo gán
	do{
		*number=(*number/10)+(*number%10)*pow(10,a);//cách lây số mũ 10
		cout << *number << endl;
	}while(*number!=fix);
}
void Perfect_spin_number(char* number,int j)
{
	int c=j;
	do{
		for(int i=c;i<=j;i++)
		{
			cout << number[i];
		}
		for(int i=0;i<c;i++)
		{
			cout << number[i];
		}
		cout << endl;
		c--;
	}while (c!=-1);

}
*/

int64_t *Countsemi(const int64_t *n)
{
	int64_t *k=new int64_t;
	*k=1;
	if(*n%2==0)
	{
		for(int64_t i=2;i<=*n;i++)
		{
			if(i%2==0)
			{
				(*k)=(*k)*i;
			}
		}
	}else {
		for(int64_t i=1;i<=*n;i++)
		{
			if(i%2!=0)
			{
				(*k)=(*k)*i;
			}
		}
	}
	return k;
}

/*
void Emp()
{
	cout << "Insert the number of employees: ";
	int number; cin >> number;
	employee * Employee= new employee[number];

	for(int i=0;i<number;i++)
	{
		cout << "Input info employee " << i+1 << ": \n";
		cout << "Input name: ";
		cin.ignore();
		cin.getline(Employee[i].name,19);
		cout << "Input salary($): ";
		cin >> Employee[i].salary;
		cout << endl;
	}

	int sum_sal=0;
	for(int i=0;i<number;i++)
	{
		sum_sal=sum_sal+(Employee[i].salary);
	}

	cout << "Output employee: " << endl;
	for(int i=0;i<number;i++)
	{
		cout << "Employee " << i+1 << endl;
		cout << "Name: " << (Employee+i)->name << "\n";
		cout << "Salary: " << Employee[i].salary << "$\n";
		cout << endl;
	}
	cout << "Sum salary: " << sum_sal << endl;
	delete [] Employee;
}
*/

template <typename t, class T2>
inline void swap_number(t& num1, t& num2);

template <class t, typename T2>
inline void swap_number(t& num1, t& num2)
{//nạp chồng hàm với const chỉ đúng với con trỏ
	t tempt = num1;
	num1 = num2;
	num2 = tempt;
}

void IVector(vector<int>& vet)//vector cx thuoc namespace std;
{
	int number;
	cout << "Insert number: ";
	cin >> number;
	vet.resize(0);
	for (size_t i = 0; i < number; i++)
	{
		//giống unsigned long long int, cấm trừ thành âm
		int a = 0;
		cout << "Input value[" << i + 1 << "]= ";
		cin >> a;
		vet.push_back(a);
	}
}

void OVector(const vector<int>& vet)
{
	for (const auto& item : vet)
	{
		cout << item << " ";
	}
	cout << endl;
}

void set_(char* a)
{
	char b[20];
	char* p = b;
	p = a;
}

int main();
