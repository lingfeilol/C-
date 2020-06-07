#include<iostream>
using namespace std;
#include <algorithm>

//class Person {
//public:
//	virtual Person* BuyTicket() { cout << "Person:买票-全价" << endl; return new Person(); }
//};
//class Student : public Person {
//public:
//	virtual Student* BuyTicket() { cout << "Student:买票-半价" << endl; return new Student(); }
//	/*void BuyTicket() { cout << "买票-半价" << endl; }*/
//	/*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因为继
//	承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议这样使用
//	*/
//	
//};
//void Func(Person& p)//引用或指针调用，且满足虚函数重写，即构成多态，根据所指或所引用对象的不同，去调用该对象具体的实现  ///不构成多态，类型决定调用的实现，即调用该类型的函数实现
//{
//	p.BuyTicket();
//}

//class Person {
//public:
//	virtual Person* BuyTicket() { 
//		cout << "Person:买票-全价" << endl; 
//		return new Person();
//	}
//};
//class Student : public Person {
//public:
//	virtual Student* BuyTicket() { 
//		cout << "Student:买票-半价" << endl; 
//		return new Student(); 
//	}
//
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person Mike;
//	Student Johnson;
//	Func(Mike);
//	Func(Johnson);
//	return 0;
//}

//
//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//// 只有派生类Student的析构函数重写了Person的析构函数(不重写便只是继承了基类的虚函数)，下面的delete对象调用析构函数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;//要是不是多态，这里p2只能访问基类的析构函数（切片）。满足多态了，则派生类会重写从person继承下来的同名析构函数，由于我在虚函数表里已重写,再根据所指对象调用正确的析构，而派生类会先执行自己的析构，在调用父类的析构
//	return 0;
//}


//class A{
//public:
//	 void func(){}
//};
//class B :public A {
//public:
//	virtual void func()override{ cout << "!!!" << endl; } //类似于断言的机制，不加override检测的话，就是同名函数的隐藏，编译时是检测不到程序没有实现预期的多态的失误，当运行时在来debug，就得不偿失了
//};

//virtual 函数类型 函数名（参数列表） = 0;



//class A
//{
//public:
//	virtual void func(){ cout << "!!!" << endl; }
//private:
//	int _a = 1;
//};
//int main()
//{
//	A aa;
//	cout << sizeof(A) << endl;
//	return 0;
//
//class A
//{
//public:
//	virtual void Func1(){           //虚函数
//		cout << "A::Func1()" << endl;
//	}
//	virtual void Func2(){           //虚函数
//		cout << "A::Func2()" << endl;
//	}
//	void Func3(){                   //普通函数
//		cout << "A::Func3()" << endl;
//	}
//private:
//	int _a = 1;
//};
//
//class B : public A
//{
//public:
//	virtual void Func1(){          //重写
//		cout << "B::Func1()" << endl;
//	}
//	virtual void Func4(){
//		cout << "B::Func4()" << endl;
//	}
//private:
//	int _b = 2;
//};
//
//
//typedef void(*V_FUNC)();//函数指针，虚表里存的都是虚函数的指针
////int a[10]; 
////int* p = a;
//
//// V_FUNC table[10];//数组里全是函数指针
//// V_FUNC* p = table;//指向数组地址的指针 ，即我们之前看到的void** 指向虚函数表的指针
//
////打印虚函数表，传入指向虚函数的指针
//void PrintVFTable(V_FUNC* p)
//{
//	for (int i = 0; p[i] != 0; ++i) //虚函数表最后有nullptr结尾
//	{
//		printf("vtable[%d]:%p->", i, p[i]);
//		V_FUNC f = p[i]; //地址在转换为函数指针
//		f();
//	}
//}
//int main()
//{
//	A aa;
//	B bb;
//	A* ptr1 = &aa;
//	B* ptr2 = &bb;
//	//指向虚函数表的指针存在对象地址的前四个字节
//	//*(int*)ptr 取到前四个字节的指向
//	//再转换成指向虚函数表的指针，用于传参 (V_FUNC*)(*(int*)ptr)
//	cout << "基类A对象的虚函数表：" << endl;
//	PrintVFTable((V_FUNC*)(*(int*)ptr1));
//
//	/*cout << "派生类B对象的虚函数表：" << endl;
//	PrintVFTable((V_FUNC*)(*(int*)ptr2));*/
//	return 0;
//}



//class A
//{
//public:
//	virtual void Func1(){cout << "A::Func1()" << endl;}
//	virtual void Func2(){cout << "A::Func2()" << endl;}
//private:
//	int _a = 1;
//};
//
//class B
//{
//public:
//	virtual void Func1(){ cout << "B::Func1()" << endl;}
//	virtual void Func2(){ cout << "B::Func2()" << endl;}
//private:
//	int _b = 2;
//};
//
//class C : public A, public B {
//public:
//	virtual void func1() { cout << "C::func1" << endl; }
//	virtual void func3() { cout << "C::func3" << endl; }
//private:
//	int _c = 3;
//};
//
//typedef void(*V_FUNC)();//函数指针，虚表里存的都是虚函数的指针
////打印虚函数表，传入指向虚函数的指针
//void PrintVFTable(V_FUNC* p)
//{
//	cout << "虚函数表地址：" << p << endl;;
//	for (int i = 0; p[i] != 0; ++i) //虚函数表最后有nullptr结尾
//	{
//		printf("vtable[%d]:%p->", i, p[i]);
//		V_FUNC f = p[i]; //地址在转换为函数指针
//		f();
//	}
//}
//int main()
//{
//	C cc;
//	cout << sizeof(cc) << endl;//20 两张表指针和三个整型
//	PrintVFTable((V_FUNC*)(*(int*)&cc));//  因为是多继承，取派生类cc对象里前四个字节，即基类A的虚函数表
//
//	PrintVFTable((V_FUNC*)(*(int*) ((char*)&cc+sizeof(A)))); //取到派生类cc对象里保存的基类B的虚函数表
//
//	return 0;
//}


 //写一段代码验证虚表是存在哪的？

//class A{
//public:
//	virtual void func(){}
//};
//class B :public A {
//public:
//	virtual void func(){ cout << "!!!" << endl; } 
//};
//int main()
//{
//	int i = 0;
//	printf("栈变量地址：%p\n", &i);
//
//	int* p1 = new int;
//	printf("堆变量地址：%p\n", p1);
//
//	static int j = 0;
//	printf("数据段变量地址：%p\n", &j);
//
//	char* p2 = "hello world";
//	printf("代码段(常量区)变量地址：%p\n", p2);
//
//	A aa;
//	printf("A虚表地址：%p\n", *((int*)&aa));
//	return 0;
//}



class A
{
public:
	virtual void func1(int val = 1){ std::cout << "A->" << val << std::endl; }
	void func2(int val = 2){ std::cout << "A->" << val << std::endl; }
};

class B : public A
{
public:
	virtual void func1(int val){ std::cout << "B->" << val << std::endl; }
};

// 实现多态为什么只能是指针或者引用调用呢？
void f1(A* ptr)
{
	ptr->func1();
}
void f2(A& ref)
{
	ref.func1();
}
void f3(A obj)
{
	obj.func1();
}
int main()
{
	A aa;
	B bb;
	f1(&aa);
	f1(&bb);
	f2(aa);
	f2(bb);
	f3(aa);
	f3(bb);
	return 0;
}