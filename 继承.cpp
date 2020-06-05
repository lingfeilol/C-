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
//	string _name="faker";//这里不是初始化，而是缺省值
//	int _age=24;
//};
//class Student :public Person
//{
//private:
//	int _stuid;//学号
//};
//class Teacher : public Person
//{
//private:
//	int _jobid;//老师工号
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
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//void Test()
//{
//	Student sobj;
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;
//	//注意赋值后不能通过基类对象区访问派生类新增的成员
//	pobj._No = 15;//错误，基类对象不包括派生类对象中增加的成员
//	sobj._age = 2;
//
//
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	//2.基类对象不能赋值给派生类对象
//	sobj = pobj;
//	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//	pp = &sobj;
//	Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
//	ps1->_No = 10;
//	pp = &pobj;
//	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
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
//	int _num = 999; // 学号
//};
//void Test()
//{
//	Student s1;
//	s1.print();//隐藏了基类的同名函数，或者说基类的同名成员被屏蔽
//	cout << s1.Person::_num << endl; //引用派生类对象s1中基类的数据成员
//	s1.Person::print();//调用基类中的被隐藏的同名函数
//};




//class Person
//{
//public:
//
//	//Person(const char* name = "faker") 缺省
//	Person(const char* name) //构造函数
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)//拷贝构造
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
//	~Person()//析构
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
//		:Person("faker")//利用初始化列表来先调用基类的构造函数，再初始化自己新增的成员变量
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
//	Student& operator=(const Student& s) // 由于和基类函数名相同，所以跟基类的operator=构成隐藏，而基类成员的赋值必须调用基类的operator= 
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
//	~Student()  // 也跟父类的~Person()构成隐藏，因为编译器会将析构函数的名称处理成destrucator()，故基类和派生类的析构函数同名
//	{
//		//Person::~Person();  不要显示调用，因为不能保证先调子类析构再调父类析构的顺序
//		// 子类析构函数调用完成后，会自动自动调用父类的
//		cout << "~Student()" << endl;
//	}
//
//protected:
//	int _id;
//};


//
//class Student;//先声明
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);//声明display为Person类的友元函数，可以在类外调用访问其非公有成员
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;//访问时加上对象名访问即可
//	cout << s._stuNum << endl;//可见友元函数关系不能继承
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}


//class Student;//前置声明
//class Person
//{
//	friend class Student;//声明学生类为人类的友元类，则学生类的成员函数相当于人类的友元函数，可以访问人类的非公有成员了
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
//		cout << p._name << endl;//声明友元关系了的，就可以访问人类的非公有成员
//	}
//private:
//	int _stuNum;
//};
//class Midstudent :public Student //中学生类继承学生类
//{
//public:
//	void Display(Person& p)
//	{
//		cout << p._name << endl;//可见不能继承学生类对人类的友元类关系
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
//int Person::_num = 0; //静态成员需要在类外初始化
//
//class Student :public Person
//{
//public:
//	//static int _num;//同名成员，构成隐藏。
//	//要是没有同名静态成员，不构成隐藏的话，就是同一个（继承下来的）
//};
////int Student::_num = 0;
//int main()
//{
//class Person //声明基类
//{
//public:
//	string _name; // 姓名
//	int _age=10;
//};
//
//class Student : virtual public Person //虚拟继承，则Person是Student的虚基类
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual  public Person //虚拟继承，则Person是Teacher的虚基类
//{
//protected:
//	int _id; // 兼职职工编号
//};
//class Dastudent : public Student, public Teacher
//{
//protected:
//	string _techerbook; // 教书课程
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

