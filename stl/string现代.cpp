#include <iostream>
#include <assert.h>
using namespace std;


//class String
//{
//public:
//	String(const char* str = "")//构造函数
//	{
//		// 构造string类对象时，如果传递nullptr指针，认为程序非法，此处断言下
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//		//_str = str;//浅拷贝形式，必然会报错
//
//		//深拷贝
//		_str = new char[strlen(str) + 1];//另开空间
//		strcpy(_str, str);//再把值拷贝到新空间
//	}
//	String(const String& s)//拷贝构造
//		:_str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//	String& operator=(const String& s)	
//	{
//		if (this != &s)//防止自己给自己赋值
//		{
//			char* tmp = new char[strlen(s._str) + 1];//新开空间 ，起一个临时传递的作用
//			strcpy(tmp, s._str);//拷贝数据
//			delete[]_str;//释放旧空间
//			_str = tmp; //得到新空间
//			
//		}
//		return *this;
//	}
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;//free空间
//			_str = nullptr;//置空
//		}
//	}
//private:
//	char* _str;
//};
//// 测试


class String
{
public:
	String(const char* str = "")//构造函数
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)//拷贝构造
		: _str(nullptr)
	{
		String strTmp(s._str);//复用构造函数，构造一个临时对象
		swap(_str, strTmp._str);//交换两者的指向，注意对象s的_str指向没有变，传参用的引用，变的是临时对象strTmp的_str的指向，且会临时对象会自动销毁的，不造成影响
	}
	 //对比下和上面的赋值那个实现比较好？
	String& operator=(String s)//传参的时候，就会调用构造函数，s相当于一个临时对象
	{
		swap(_str, s._str);//出作用域临时对象自动销毁
		return *this;
	}
	
	//String& operator=(const String& s)//传引用
	//{
	//	if(this != &s)
	//	{
	//		String strTmp(s);//显式调用一次拷贝构造 ，而在拷贝构造里，会调用一次构造函数，相比于上面的实现性能上有损失
	//		swap(_str, strTmp._str);
	//	}
	//	return *this;
	//}
	
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

void TestString()
{
	String s1("hello world!!");
	String s2(s1);
	String s3;
	s3 = s1;

}

int main()
{
	TestString();
	return 0;
}