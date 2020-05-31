#include<iostream>
using namespace std;


// 定义一个模板类型的静态数组,对于静态数组，一般都要提前知道开多大的空间，
template<class T, size_t N = 10>
class array
{
public:
	T& operator[](size_t index){ return _array[index]; }
	//...
private:
	T _array[N];//传入的非类型模板参数N，开空间
	size_t _size;
};
//函数模板
template<class T>
bool IsEqual(T& a, T& b)
{
	return a == b;
}
template<> //特化
bool IsEqual<char*>(char*& a, char*& b)//特化成可以处理字符串类型的模板函数
{
	if (strcmp(a, b) > 0)
		return true;
	return false;
}
void Test()
{
	char* p1 = "hello";
	char* p2 = "worl";
	if (IsEqual(p1, p2))
		cout << "IsEqual" << endl;
	else
		cout << "notisEqual" << endl;
}

//类模板
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
//特化
template<>
class Data<int, char>//参数特化
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};
void Test1()
{
	Data<int, int> d1;
	Data<int, char> d2;
}



template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
// 部分特化  将第二个参数特化为int
template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};

//两个参数偏特化为指针类型
template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
//两个参数偏特化为引用类型
template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		:_d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	const T1 & _d1;
	const T2 & _d2;
};
void Test2()
{
	Data<int, double> d1; // 调用基础的模板
	Data<double, int> d2; // 调用部分特化的int版本
	Data<int *, int*> d3; // 调用特化的指针版本
	Data<int&, int&> d4(1, 2); // 调用特化的引用版本
}

int main()
{
	Test2();
	return 0;
}


template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	memcpy(dst, src, sizeof(T)*size);///memcpy是按字节拷贝的，属于浅拷贝
}
int main()
{
	int a[3] = { 1, 2, 3 };
	int b[3];
	Copy(b, a, 3);
	for (int i = 0; i < 3; i++)
	{
		cout << b[i] <<' ';
	}
	// 而对于带资源管理的自定义类型，
	string strarr1[3] = { "11", "22", "33" };
	string strarr2[3];
	Copy(strarr2, strarr1, 3);
}


#include "a.h"
int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	return 0;
}