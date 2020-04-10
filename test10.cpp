#include<iostream>
using namespace std;

template<typename T>
class Vector
{
public :
	Vector(size_t capacity = 10)
		: _pData(new T[capacity])//�����漰��ǳ���������⣬��ƪ��ϸ˵
		, _size(0)
		, _capacity(capacity)
	{}
	// ʹ������������ʾ�������������������ⶨ���ע������
	void PushBack(const T& data);
	void PopBack();
	~Vector();
	//....
	T& operator[](size_t pos)  //����ķ���ֵ����ҲҪע�⣬
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
	Vector<int> v1;//��ģ��ʵ����
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.operator[](0) = 0;

	return 0;
}
#if 0
// ר�Ŵ���int�ļӷ�����
int Add(int a, int b)
{
	return a+ b;
}
// ͨ�üӷ�����
template<class T1, class T2>
T1 Add(T1 a, T2 b)
{
	return a+ b;
}
int main()
{
	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
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
	Max(a1, (int)d1);  //�Լ�ǿ��ת��
	Max<int>(a1, d1);// ��ʽʵ����,�Լ�ָ����������
	return 0;
}



class Date
{
public:
	/*Date(int year)
		:_year(year)
	{}*/
	explicit Date(int year)  //explicit�ؼ����Ż��Ĺ��캯��
		:_year(year)
	{}
private:
	int _year;
	int _month;
	int _day;
};
void TestDate()
{
	Date d1(2020);//ֱ�ӵ��ù��캯��

	// ��һ�����α������������Ͷ���ֵ
	// ʵ�ʱ������������2020����һ������������������������d1������и�ֵ
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
	int _year ; // ��
	int _month ; // ��
	int _day ; // ��
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
	//Date()//�޲εĹ��캯��
	//{
	//	_year = 1900 ;
	//	_month = 1 ;
	//	_day = 1;
	//}
	//Date (int year = 1900, int month = 1, int day = 1) //ȫȱʡ�Ĺ��캯��
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
// ���²��Ժ�����ͨ��������
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
