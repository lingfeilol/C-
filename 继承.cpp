#include<iostream>
#include<string>
using namespace std;

//
//class Person 
//{
//public:
//	void print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//private:
//	string _name="faker";//���ﲻ�ǳ�ʼ��������ȱʡֵ
//	int _age=24;
//};
//class Student :public Person
//{
//private:
//	int _stuid;//ѧ��
//};
//class Teacher : public Person
//{
//private:
//	int _jobid;//��ʦ����
//};
//
//
//int main()
//{
//	Person p;
//	Student s;
//	s.print();
//	Teacher t;
//	t.print();
//
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // ����
//	string _sex; // �Ա�
//	int _age; // ����
//};
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//void Test()
//{
//	Student sobj;
//	// 1.���������Ը�ֵ���������/ָ��/����
//	Person pobj = sobj;
//	//ע�⸳ֵ����ͨ��������������������������ĳ�Ա
//	pobj._No = 15;//���󣬻�����󲻰�����������������ӵĳ�Ա
//	sobj._age = 2;
//
//
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	//2.��������ܸ�ֵ�����������
//	sobj = pobj;
//	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	pp = &sobj;
//	Student* ps1 = (Student*)pp; // �������ת��ʱ���Եġ�
//	ps1->_No = 10;
//	pp = &pobj;
//	Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
//	ps2->_No = 10;
//}




//class Person
//{
//public:
//	void print()
//	{
//		cout << "person _num" << _num << endl;
//	}
//public:
//	int _num = 111;
//};
//
//class Student : public Person
//{
//public:
//	void print()
//	{
//		cout << "student _num" << _num << endl;
//	}
//private:
//	int _num = 999; // ѧ��
//};
//void Test()
//{
//	Student s1;
//	s1.print();//�����˻����ͬ������������˵�����ͬ����Ա������
//	cout << s1.Person::_num << endl; //�������������s1�л�������ݳ�Ա
//	s1.Person::print();//���û����еı����ص�ͬ������
//};




//class Person
//{
//public:
//
//	//Person(const char* name = "faker") ȱʡ
//	Person(const char* name) //���캯��
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)//��������
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person& operator=" << endl;
//		if (&p != this)
//			_name = p._name;
//		return *this;
//	}
//	~Person()//����
//	{
//		cout << "~pPerson()" << endl;
//	}
//protected:
//	string _name;
//};
//
//
//class Student :public Person
//{
//public:
//	Student(const int id=15)
//		:Person("faker")//���ó�ʼ���б����ȵ��û���Ĺ��캯�����ٳ�ʼ���Լ������ĳ�Ա����
//		, _id(id)
//	{
//		cout << "Student()" << endl;
//	}
//	Student(const Student& s)
//		:Person(s)
//		, _id(s._id)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	Student& operator=(const Student& s) // ���ںͻ��ຯ������ͬ�����Ը������operator=�������أ��������Ա�ĸ�ֵ������û����operator= 
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_id = s._id;
//		}
//		
//		cout << "Student& operator=(const Student& s)" << endl;
//		return *this;
//	}
//
//	~Student()  // Ҳ�������~Person()�������أ���Ϊ�������Ὣ�������������ƴ����destrucator()���ʻ�������������������ͬ��
//	{
//		//Person::~Person();  ��Ҫ��ʾ���ã���Ϊ���ܱ�֤�ȵ����������ٵ�����������˳��
//		// ������������������ɺ󣬻��Զ��Զ����ø����
//		cout << "~Student()" << endl;
//	}
//
//protected:
//	int _id;
//};


//
//class Student;//������
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);//����displayΪPerson�����Ԫ������������������÷�����ǹ��г�Ա
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;//����ʱ���϶��������ʼ���
//	cout << s._stuNum << endl;//�ɼ���Ԫ������ϵ���ܼ̳�
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}


//class Student;//ǰ������
//class Person
//{
//	friend class Student;//����ѧ����Ϊ�������Ԫ�࣬��ѧ����ĳ�Ա�����൱���������Ԫ���������Է�������ķǹ��г�Ա��
//private:
//	string _name;
//	int _age;
//};
//
//class Student
//{
//public:
//	void Display(Person& p)
//	{
//		cout << p._name << endl;//������Ԫ��ϵ�˵ģ��Ϳ��Է�������ķǹ��г�Ա
//	}
//private:
//	int _stuNum;
//};
//class Midstudent :public Student //��ѧ����̳�ѧ����
//{
//public:
//	void Display(Person& p)
//	{
//		cout << p._name << endl;//�ɼ����ܼ̳�ѧ������������Ԫ���ϵ
//	}
//private:
//	int _grade;
//};



//class Person
//{
//public:
//	static int _num;
//
//}; 
//int Person::_num = 0; //��̬��Ա��Ҫ�������ʼ��
//
//class Student :public Person
//{
//public:
//	//static int _num;//ͬ����Ա���������ء�
//	//Ҫ��û��ͬ����̬��Ա�����������صĻ�������ͬһ�����̳������ģ�
//};
////int Student::_num = 0;
//int main()
//{
//class Person //��������
//{
//public:
//	string _name; // ����
//	int _age=10;
//};
//
//class Student : virtual public Person //����̳У���Person��Student�������
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : virtual  public Person //����̳У���Person��Teacher�������
//{
//protected:
//	int _id; // ��ְְ�����
//};
//class Dastudent : public Student, public Teacher
//{
//protected:
//	string _techerbook; // ����γ�
//};
//void Test()
//{
//	Dastudent a;
//	a._name = "peter";
//}


class A
{
public:
	int _a;
};
// class B : public A
class B : virtual public A
{
public:
	int _b;
};
// class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
int main()
{
	D d;
	cout << sizeof(d) << endl;

	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	
	return 0;
}

