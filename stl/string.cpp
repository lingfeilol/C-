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
		typedef char* iterator;  //������
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}
	public:

		//ǳ����ֻ�ǵ����İѱ���ֵ����һ���ٸ�ֵ��ȥ��Ҫ���漰��̬���ٵ��ڴ棬���ǰ�ָ��ĵ�ַ����һ���ٸ�ֵ����һ�������������ͻ�������ָ�����ָ��ͬһ���ڴ棬������һ�����ͷź󣬵�����һ����ָ������ط����ͻ����  
		//���� ���������캯�������������ʱ����s1��������s2ʱ����Ĭ�Ͽ������캯��������ͬһ���ڴ棬������ʱһ���ڴ汻�ͷ����λᱨ����

		//����Ҫʹ�����
		//String(const char* str==nullptr) ���Ǵ����ȱʡ strlen(str)�������
		String(const char* str = "")

		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];   //��̬���ٿռ�      //���ռ�ʱҪ��\0��һ��λ��
			strcpy(_str, str); //���ռ��ٰ����ݿ�����ȥ
		}
		String(const String& s)
		{
			//String tmp = s;
			_str = new char[s._capacity + 1];
			_size = s._size;
			_capacity = s._capacity;
			strcpy(_str, s._str);
		}
		String& operator=(const String& s)   //��=����
		{
			if (this != &s)//��ֹ�Լ����Լ���ֵ
			{
				delete[] _str;//�Ȱ��Լ�ԭ���ľͿռ��ͷŵ�
				_str = new char[s._capacity + 1];//���¿��ռ�
				strcpy(_str, s._str);
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}
		~String()  //����
		{
			if (_str)
			{
				delete[] _str;  //����delete�ͷſռ�
				_str = nullptr;  //ָ���ÿ�
				_size = _capacity = 0;
			}
		}

		// modify   �޸Ĳ���
		void PushBack(char c) //β��һ���ַ�
		{
			if (_size == _capacity)//�ж��Ƿ�����
			{
				_capacity *= 2;
			}
			_str[_size++] = c;
			_str[_size] = '\0'; //ĩβ������ֹ��
		}
		void Append(const char* str)   //�����ַ���
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
				Reserve(_size + len);
			strcpy(_str + _size, str);
			_size += len;
		}
		String& operator+=(char c)  //���� += β��һ���ַ�
		{
			this->PushBack(c);
			return *this;
		}

		String& operator+=(const char* str)// ���� += �����ַ���
		{
			this->Append(str);
			return *this;
		}
		void Clear()  //���Ԫ��
		{
			_size = 0;
			_str[_size] = '\0';
		}
		void Swap(String& s)     //������ת��
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		const char* c_str() const  //ת����c��ʽ�ַ���
		{
			return _str;
		}

		// capacity   ��Ԫ�غ������ռ����
		size_t Size()const    //��ȡ Ԫ�ظ���
		{
			return _size;
		}
		size_t Capacity()const   //��ȡ������С
		{
			return _capacity;
		}
		bool Empty()const   //�ж��Ƿ�Ϊ��
		{
			return _size == 0;
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n < _size) // ɾ������
			{
				_size = n;
				_str[_size] = '\0';
			}
			else // ��������
			{
				// �ռ䲻��������
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
			if (newCapacity > _capacity)   //Ҳ�����ռ������
			{
				char * tmp = new char[newCapacity + 1];
				strcpy(tmp, _str);
				//���پɿռ�
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
				_str[end + 1] = _str[end];//��pos��ʼ������һλ
			}
			_str[pos] = ch;
			_size += 1;
			return *this;
		}
		String& insert(size_t pos, const char* str) //���ַ���
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

		// access   ���ʲ���
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

		//   ��ϵ����
		// s1 < s2  s1==s2
		// ʵ���������������ıȽϸ���ʵ��
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
		// ����c��string�е�һ�γ��ֵ�λ��
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
		// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
		size_t Find(const char* s, size_t pos = 0) const
		{

		}

		// ɾ��pos֮���Ԫ��
		String& erase(size_t pos, size_t len = npos)//ȱʡ����
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
		// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
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

	//// ����+��д
	//for (size_t i = 0; i < s1.Size(); ++i)
	//{
	//	s1[i] += 1;
	//	cout << s1[i] << " ";
	//}
	//cout << endl;

	//// ����+��д
	//mystring::String::iterator it1 = s1.begin();
	//while (it1 != s1.end())
	//{
	//	*it1 -= 1;
	//	cout << *it1 << " ";
	//	++it1;
	//}
	//cout << endl;

	//// ����+��д  ��Χfor���е�����֧�ֵģ�����ᱻ������ת���ɵ���������
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
