#define  _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;
namespace mystring
{
	class String
	{
	public:
		typedef char* iterator;  //迭代器
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}
	public:

		//浅拷贝只是单纯的把变量值拷贝一份再赋值过去，要是涉及动态开辟的内存，就是把指针的地址拷贝一份再赋值给另一个变量，这样就会有两个指针变量指向同一个内存，当其中一个被释放后，但是另一个还指向这个地方，就会出错  
		//例如 ：拷贝构造函数和运算符重载时，用s1拷贝构造s2时调用默认拷贝构造函数，共用同一个内存，在析构时一块内存被释放两次会报错误

		//所以要使用深拷贝
		//String(const char* str==nullptr) 这是错误的缺省 strlen(str)会崩溃的
		String(const char* str = "")

		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];   //动态开辟空间      //开空间时要给\0留一个位置
			strcpy(_str, str); //另开空间再把数据拷贝过去
		}
		String(const String& s)
		{
			//String tmp = s;
			_str = new char[s._capacity + 1];
			_size = s._size;
			_capacity = s._capacity;
			strcpy(_str, s._str);
		}
		String& operator=(const String& s)   //对=重载
		{
			if (this != &s)//防止自己给自己赋值
			{
				delete[] _str;//先把自己原来的就空间释放掉
				_str = new char[s._capacity + 1];//重新开空间
				strcpy(_str, s._str);
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}
		~String()  //析构
		{
			if (_str)
			{
				delete[] _str;  //调用delete释放空间
				_str = nullptr;  //指针置空
				_size = _capacity = 0;
			}
		}

		// modify   修改操作
		void PushBack(char c) //尾插一个字符
		{
			if (_size == _capacity)//判断是否扩容
			{
				_capacity *= 2;
			}
			_str[_size++] = c;
			_str[_size] = '\0'; //末尾补上终止符
		}
		void Append(const char* str)   //链接字符串
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
				Reserve(_size + len);
			strcpy(_str + _size, str);
			_size += len;
		}
		String& operator+=(char c)  //重载 += 尾插一个字符
		{
			this->PushBack(c);
			return *this;
		}

		String& operator+=(const char* str)// 重载 += 链接字符串
		{
			this->Append(str);
			return *this;
		}
		void Clear()  //清除元素
		{
			_size = 0;
			_str[_size] = '\0';
		}
		void Swap(String& s)     //对象互相转换
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		const char* c_str() const  //转换成c格式字符串
		{
			return _str;
		}

		// capacity   对元素和容量空间操作
		size_t Size()const    //获取 元素个数
		{
			return _size;
		}
		size_t Capacity()const   //获取容量大小
		{
			return _capacity;
		}
		bool Empty()const   //判断是否为空
		{
			return _size == 0;
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n < _size) // 删除数据
			{
				_size = n;
				_str[_size] = '\0';
			}
			else // 插入数据
			{
				// 空间不够先增容
				if (n > _capacity)
					Reserve(n);

				for (size_t i = _size; i < n; ++i)
					_str[i] = ch;
				_size = n;
				_str[_size] = '\0';
			}
		}
		void Reserve(size_t newCapacity)
		{
			if (newCapacity > _capacity)   //也是另开空间存数据
			{
				char * tmp = new char[newCapacity + 1];
				strcpy(tmp, _str);
				//销毁旧空间
				delete[] _str;
				_str == nullptr;
				_str = tmp;
				_capacity = newCapacity;
			}
		}
		String& insert(size_t pos, const char ch)
		{
			assert(pos < _size);
			if (_size == _capacity)
			{
				Reserve(_capacity * 2);
			}
			size_t end = _size;
			while (end>pos)
			{
				_str[end + 1] = _str[end];//从pos开始往后移一位
			}
			_str[pos] = ch;
			_size += 1;
			return *this;
		}
		String& insert(size_t pos, const char* str) //插字符串
		{
			assert(pos < _size);
			int len = strlen(str);
			if (_size + len >= _capacity)
			{
				Reserve(_size + len);
			}
			size_t end = _size;
			while (end>pos)
			{
				_str[end + len] = _str[end];
				end--;
			}
			for (int i = 0; i < len; i++)
			{
				_str[i + pos] = str[i];
			}
			//strncpy(_str+pos,str,len);
			_size = _size + len;
			return *this;
		}

		// access   访问操作
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}

		//   关系运算
		// s1 < s2  s1==s2
		// 实现这两个，其他的比较复用实现
		bool operator<(const String& s)
		{
			return strcmp(_str, s._str) < 0;
		}

		bool operator==(const String& s)
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator<=(const String& s)
		{
			return *this < s || *this == s;
		}

		bool operator>(const String& s)
		{
			return !(*this <= s);
		}

		bool operator>=(const String& s)
		{
			return !(*this < s);
		}

		bool operator!=(const String& s)
		{
			return !(*this == s);
		}
		// 返回c在string中第一次出现的位置
		size_t Find(char c, size_t pos = 0) const
		{
			for (pos = 0; pos < _size; pos++)
			{
				if (_str[pos] == c)
				{
					return pos;
				}
			}
			return -1;
		}
		// 返回子串s在string中第一次出现的位置
		size_t Find(const char* s, size_t pos = 0) const
		{

		}

		// 删除pos之后的元素
		String& erase(size_t pos, size_t len = npos)//缺省参数
		{
			if (pos + len > _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		size_t find(const char ch, size_t pos = 0)
		{
			for (int i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
					return i;
			}
			return -1;
		}
		size_t find(const char* str, size_t pos = 0)
		{
			const char* tmp = strstr(_str + pos, str);
			if (tmp == nullptr)
				return -1;
			return tmp - _str;
		}
	private:
		friend ostream& operator<<(ostream& out, const String& s);
		friend istream& operator>>(istream& in, String& s);
	private:
		char * _str;
		size_t _capacity;
		size_t _size;
		static size_t npos;
	};


	size_t String::npos = -1;

	ostream& mystring::operator<<(ostream& out, const mystring::String& s)
	{
		for (size_t i = 0; i < s.Size(); ++i)
		{
			out << s[i];
		}

		return out;
	}

	istream& mystring::operator>>(istream& in, mystring::String& s)
	{
		while (1)
		{
			char ch = in.get();
			if (ch == ' ' || ch == '\n')
				break;
			else
				s += ch;
		}

		return in;
	}
}
int main()
{
	mystring::String s1("hello");
	s1.PushBack('x');
	s1.PushBack('y');
	s1.Append("world");
	s1 += '!';
	s1 += "hello world";
	cout << s1 << endl;

	//// 遍历+读写
	//for (size_t i = 0; i < s1.Size(); ++i)
	//{
	//	s1[i] += 1;
	//	cout << s1[i] << " ";
	//}
	//cout << endl;

	//// 遍历+读写
	//mystring::String::iterator it1 = s1.begin();
	//while (it1 != s1.end())
	//{
	//	*it1 -= 1;
	//	cout << *it1 << " ";
	//	++it1;
	//}
	//cout << endl;

	//// 遍历+读写  范围for是有迭代器支持的，这里会被编译器转换成迭代器遍历
	//for (auto& ch : s1)
	//{
	//	ch += 1;
	//	cout << ch << " ";
	//}
	//cout << endl;

	//mystring::String s2("hello");
	//s2 += 'x';
	//s2.resize(3);
	//s2.resize(7, 'x');
	//s2.resize(15, 'x');

	return 0;
}
