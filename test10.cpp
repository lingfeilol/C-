#include<iostream>
using namespace std;

template<typename T>
class Vector
{
public :
	Vector(size_t capacity = 10)
		: _pData(new T[capacity])//这里涉及深浅拷贝的问题，下篇再细说
		, _size(0)
		, _capacity(capacity)
	{}
	// 使用析构函数演示：在类中声明，在类外定义的注意事项
	void PushBack(const T& data);
	void PopBack();
	~Vector();
	//....
	T& operator[](size_t pos)  //这里的返回值类型也要注意，
	{
		return _pData[pos];
	}
private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};
int main()
{
	Vector<int> v1;//类模板实例化
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.operator[](0) = 0;

	return 0;
}
#if 0
// 专门处理int的加法函数
int Add(int a, int b)
{
	return a+ b;
}
// 通用加法函数
template<class T1, class T2>
T1 Add(T1 a, T2 b)
{
	return a+ b;
}
int main()
{
	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
	return 0;
}


template<typename T>
T Max(const T& a, const T& b)
{
	return a > b ? a : b;
}
int main()
{
	int a1 = 10, a2 = 20;
	double d1 = 11.1, d2 = 22.2;
	Max(a1, (int)d1);  //自己强制转换
	Max<int>(a1, d1);// 显式实例化,自己指定参数类型
	return 0;
}



class Date
{
public:
	/*Date(int year)
		:_year(year)
	{}*/
	explicit Date(int year)  //explicit关键字优化的构造函数
		:_year(year)
	{}
private:
	int _year;
	int _month;
	int _day;
};
void TestDate()
{
	Date d1(2020);//直接调用构造函数

	// 用一个整形变量给日期类型对象赋值
	// 实际编译器背后会用2020构造一个无名对象，最后用无名对象给d1对象进行赋值
	Date d2 = 2020;
}
int main()
{
	TestDate();
	return 0;
}

class Time
{
public:
	Time(int hour = 0)
		:_hour(hour)
	{
		cout << "Time()" << endl;
	}
private:
	int _hour;
};
class Date
{
public:
	Date(int day)
	{}
private:
	int _day;
	Time _t;
};
int main()
{
	Date d(1);
}

class Date
{
public :
	/*void Display ()
	{
	cout<<"Display ()" <<endl;
	cout<<"year:" <<_year<< endl;
	cout<<"month:" <<_month<< endl;
	cout<<"day:" <<_day<< endl<<endl ;

	}*/
	void Display () const
	{
	cout<<"Display () const" <<endl;
	cout<<"year:" <<_year<< endl;
	cout<<"month:" <<_month<< endl;
	cout<<"day:" <<_day<< endl<<endl;
	}
private :
	int _year ; // 年
	int _month ; // 月
	int _day ; // 日
};
int main()
{
	Date d1 ;
	d1.Display ();
	/*const Date d2;
	d2.Display ();*/
	return 0;
}


class Date
{
	
public:
	//Date()//无参的构造函数
	//{
	//	_year = 1900 ;
	//	_month = 1 ;
	//	_day = 1;
	//}
	//Date (int year = 1900, int month = 1, int day = 1) //全缺省的构造函数
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	friend ostream& operator <<(ostream & out, Date & d);

private :
	int _year ;
	int _month ;
	int _day ;
};
ostream& operator <<(ostream & out, Date & d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}
// 以下测试函数能通过编译吗？
int main()
{
	Date d1;
	cout << d1 << endl;
	return 0;
}


//int main()
//{
//	int year, month, day;
//	int ret = 0;
//	int i = 0;
//	int monthday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	while (cin >> year >> month >> day)
//	{
//		for (i = 0; i < month; i++)
//		{
//			ret += monthday[i];
//		}
//		ret += day;
//		if ((year % 4 == 0) || (year % 4 == 0 && year % 100 != 0))
//			ret++;
//		cout << ret << endl;
//	}
//	return 0;
//}
class A
{
public:
	void f1();
};
int main()
{
	int x = 0;
	x=sizeof(A);
	cout << x;
	return 0;
}
#endif
