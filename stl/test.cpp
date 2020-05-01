#include <iostream>
#include <assert.h>
using namespace std;


//class String
//{
//public:
//	String(const char* str = "")//���캯��
//	{
//		// ����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//		//_str = str;//ǳ������ʽ����Ȼ�ᱨ��
//
//		//���
//		_str = new char[strlen(str) + 1];//���ռ�
//		strcpy(_str, str);//�ٰ�ֵ�������¿ռ�
//	}
//	String(const String& s)//��������
//		:_str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//	String& operator=(const String& s)	
//	{
//		if (this != &s)//��ֹ�Լ����Լ���ֵ
//		{
//			char* tmp = new char[strlen(s._str) + 1];//�¿��ռ� ����һ����ʱ���ݵ�����
//			strcpy(tmp, s._str);//��������
//			delete[]_str;//�ͷžɿռ�
//			_str = tmp; //�õ��¿ռ�
//			
//		}
//		return *this;
//	}
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;//free�ռ�
//			_str = nullptr;//�ÿ�
//		}
//	}
//private:
//	char* _str;
//};
//// ����


class String
{
public:
	String(const char* str = "")//���캯��
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)//��������
		: _str(nullptr)
	{
		String strTmp(s._str);//���ù��캯��������һ����ʱ����
		swap(_str, strTmp._str);//�������ߵ�ָ��ע�����s��_strָ��û�б䣬�����õ����ã��������ʱ����strTmp��_str��ָ���һ���ʱ������Զ����ٵģ������Ӱ��
	}
	 //�Ա��º�����ĸ�ֵ�Ǹ�ʵ�ֱȽϺã�
	String& operator=(String s)//���ε�ʱ�򣬾ͻ���ù��캯����s�൱��һ����ʱ����
	{
		swap(_str, s._str);//����������ʱ�����Զ�����
		return *this;
	}
	
	//String& operator=(const String& s)//������
	//{
	//	if(this != &s)
	//	{
	//		String strTmp(s);//��ʽ����һ�ο������� �����ڿ�������������һ�ι��캯��������������ʵ������������ʧ
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