#include<iostream>
using namespace std;


// ����һ��ģ�����͵ľ�̬����,���ھ�̬���飬һ�㶼Ҫ��ǰ֪�������Ŀռ䣬
template<class T, size_t N = 10>
class array
{
public:
	T& operator[](size_t index){ return _array[index]; }
	//...
private:
	T _array[N];//����ķ�����ģ�����N�����ռ�
	size_t _size;
};
//����ģ��
template<class T>
bool IsEqual(T& a, T& b)
{
	return a == b;
}
template<> //�ػ�
bool IsEqual<char*>(char*& a, char*& b)//�ػ��ɿ��Դ����ַ������͵�ģ�庯��
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

//��ģ��
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
//�ػ�
template<>
class Data<int, char>//�����ػ�
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
// �����ػ�  ���ڶ��������ػ�Ϊint
template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};

//��������ƫ�ػ�Ϊָ������
template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
//��������ƫ�ػ�Ϊ��������
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
	Data<int, double> d1; // ���û�����ģ��
	Data<double, int> d2; // ���ò����ػ���int�汾
	Data<int *, int*> d3; // �����ػ���ָ��汾
	Data<int&, int&> d4(1, 2); // �����ػ������ð汾
}

int main()
{
	Test2();
	return 0;
}


template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	memcpy(dst, src, sizeof(T)*size);///memcpy�ǰ��ֽڿ����ģ�����ǳ����
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
	// �����ڴ���Դ������Զ������ͣ�
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