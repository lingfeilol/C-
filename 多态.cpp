#include<iostream>
using namespace std;
#include <algorithm>

//class Person {
//public:
//	virtual Person* BuyTicket() { cout << "Person:��Ʊ-ȫ��" << endl; return new Person(); }
//};
//class Student : public Person {
//public:
//	virtual Student* BuyTicket() { cout << "Student:��Ʊ-���" << endl; return new Student(); }
//	/*void BuyTicket() { cout << "��Ʊ-���" << endl; }*/
//	/*ע�⣺����д�����麯��ʱ����������麯���ڲ���virtual�ؼ���ʱ����ȻҲ���Թ�����д(��Ϊ��
//	�к������麯�����̳������������������ɱ����麯������),���Ǹ���д�����Ǻܹ淶������������ʹ��
//	*/
//	
//};
//void Func(Person& p)//���û�ָ����ã��������麯����д�������ɶ�̬��������ָ�������ö���Ĳ�ͬ��ȥ���øö�������ʵ��  ///�����ɶ�̬�����;������õ�ʵ�֣������ø����͵ĺ���ʵ��
//{
//	p.BuyTicket();
//}

//class Person {
//public:
//	virtual Person* BuyTicket() { 
//		cout << "Person:��Ʊ-ȫ��" << endl; 
//		return new Person();
//	}
//};
//class Student : public Person {
//public:
//	virtual Student* BuyTicket() { 
//		cout << "Student:��Ʊ-���" << endl; 
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
//// ֻ��������Student������������д��Person����������(����д��ֻ�Ǽ̳��˻�����麯��)�������delete��������������������ܹ��ɶ�̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;//Ҫ�ǲ��Ƕ�̬������p2ֻ�ܷ��ʻ����������������Ƭ���������̬�ˣ������������д��person�̳�������ͬ���������������������麯����������д,�ٸ�����ָ���������ȷ�������������������ִ���Լ����������ڵ��ø��������
//	return 0;
//}


//class A{
//public:
//	 void func(){}
//};
//class B :public A {
//public:
//	virtual void func()override{ cout << "!!!" << endl; } //�����ڶ��ԵĻ��ƣ�����override���Ļ�������ͬ�����������أ�����ʱ�Ǽ�ⲻ������û��ʵ��Ԥ�ڵĶ�̬��ʧ�󣬵�����ʱ����debug���͵ò���ʧ��
//};

//virtual �������� �������������б� = 0;



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
//	virtual void Func1(){           //�麯��
//		cout << "A::Func1()" << endl;
//	}
//	virtual void Func2(){           //�麯��
//		cout << "A::Func2()" << endl;
//	}
//	void Func3(){                   //��ͨ����
//		cout << "A::Func3()" << endl;
//	}
//private:
//	int _a = 1;
//};
//
//class B : public A
//{
//public:
//	virtual void Func1(){          //��д
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
//typedef void(*V_FUNC)();//����ָ�룬������Ķ����麯����ָ��
////int a[10]; 
////int* p = a;
//
//// V_FUNC table[10];//������ȫ�Ǻ���ָ��
//// V_FUNC* p = table;//ָ�������ַ��ָ�� ��������֮ǰ������void** ָ���麯�����ָ��
//
////��ӡ�麯��������ָ���麯����ָ��
//void PrintVFTable(V_FUNC* p)
//{
//	for (int i = 0; p[i] != 0; ++i) //�麯���������nullptr��β
//	{
//		printf("vtable[%d]:%p->", i, p[i]);
//		V_FUNC f = p[i]; //��ַ��ת��Ϊ����ָ��
//		f();
//	}
//}
//int main()
//{
//	A aa;
//	B bb;
//	A* ptr1 = &aa;
//	B* ptr2 = &bb;
//	//ָ���麯�����ָ����ڶ����ַ��ǰ�ĸ��ֽ�
//	//*(int*)ptr ȡ��ǰ�ĸ��ֽڵ�ָ��
//	//��ת����ָ���麯�����ָ�룬���ڴ��� (V_FUNC*)(*(int*)ptr)
//	cout << "����A������麯����" << endl;
//	PrintVFTable((V_FUNC*)(*(int*)ptr1));
//
//	/*cout << "������B������麯����" << endl;
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
//typedef void(*V_FUNC)();//����ָ�룬������Ķ����麯����ָ��
////��ӡ�麯��������ָ���麯����ָ��
//void PrintVFTable(V_FUNC* p)
//{
//	cout << "�麯�����ַ��" << p << endl;;
//	for (int i = 0; p[i] != 0; ++i) //�麯���������nullptr��β
//	{
//		printf("vtable[%d]:%p->", i, p[i]);
//		V_FUNC f = p[i]; //��ַ��ת��Ϊ����ָ��
//		f();
//	}
//}
//int main()
//{
//	C cc;
//	cout << sizeof(cc) << endl;//20 ���ű�ָ�����������
//	PrintVFTable((V_FUNC*)(*(int*)&cc));//  ��Ϊ�Ƕ�̳У�ȡ������cc������ǰ�ĸ��ֽڣ�������A���麯����
//
//	PrintVFTable((V_FUNC*)(*(int*) ((char*)&cc+sizeof(A)))); //ȡ��������cc�����ﱣ��Ļ���B���麯����
//
//	return 0;
//}


 //дһ�δ�����֤����Ǵ����ĵģ�

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
//	printf("ջ������ַ��%p\n", &i);
//
//	int* p1 = new int;
//	printf("�ѱ�����ַ��%p\n", p1);
//
//	static int j = 0;
//	printf("���ݶα�����ַ��%p\n", &j);
//
//	char* p2 = "hello world";
//	printf("�����(������)������ַ��%p\n", p2);
//
//	A aa;
//	printf("A����ַ��%p\n", *((int*)&aa));
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

// ʵ�ֶ�̬Ϊʲôֻ����ָ��������õ����أ�
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