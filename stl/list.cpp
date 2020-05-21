#include<iostream>

namespace mylist
{
	//list的节点类
	template<class T>
	struct ListNode
	{
		ListNode(const T& val = T())
		:_prev(nullptr)
		, _next(nullptr)
		, _val(val)
		{}

		ListNode<T>*  _prev;
		ListNode<T>*  _next;
		T _val;
	};

	/*
	List 的迭代器
	迭代器有两种实现方式，具体应根据容器底层数据结构实现：
	1. 原生态指针，比如：vector
	2. 将原生态指针进行封装，因迭代器使用形式与指针完全相同，因此在自定义的类中必须实现以下方法：
	·1. 指针可以解引用，迭代器的类中必须重载operator*()
	·2. 指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
	·3. 指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int)
	至于operator--()/operator--(int)释放需要重载，根据具体的结构来抉择，双向链表可以向前
	移动，所以需要重载，如果是forward_list就不需要重载--
	4. 迭代器需要进行是否相等的比较，因此还需要重载operator==()与operator!=()
	*/
	//由于链表结构元素地址不是连续的，不能使用原生指针，必须自己封装，且还要再重载指针相关的操作符 
	//迭代器类

	template <class T,class Ref,class Ptr>
	struct list_iterator
	{
		typedef ListNode<T> Node;  //节点类
		typedef list_iterator<T, Ref, Ptr> self;//  迭代器模板类    Ref对应T&,Ptr对应T*  模板参数来控制复用，实现出普通迭代器和const迭代器

		Node* _node;//节点指针 类成员
		list_iterator( Node* _node = nullptr)
			:_node(_node)
		{}

		// 链表的迭代器的核心还是节点的指针
		// 但是封装在类，可以通过运算符去控制++ * 等行为

		//链表指针解应用，取当前节点的_val
		//T& operator*()
		T& operator*() 
		{
			return _node->_val;
		}
		//指针访问成员变量符-> 
		//T* operator->()
		T* operator->()
		{
			return &_node->_val;
		}
		//利用模板参数控制复用
		self& operator++()//前置加加
		{
			_node = _node->_next;
			return *this;
		}
		self& operator--()
		{
			_node = _node->_prev;
			retunr *this;
		}
		self operator++(int) //后置加加
		{
			//保存当前值
			self tmp(*this); //list_iterator<T> tmp(*this);//
			_node = _node->_next;
			return tmp;
		}
		self operator--(int)//后置减减
		{
			list_iterator<T> tmp(*this);//self tmp(*this)
			_node = _node->_prev;
			return tmp;
		}
		bool operator==(const self& it)
		{
			return _node == it._node;
		}
		bool operator!=(const self& it)
		{
			return _node != it._node;
		}
	};



	//模拟实现list  增删查改访问等
	template <class T>
	class list
	{
		typedef ListNode<T> Node; //实例化的节点类
	public:
		//typedef list_iterator<T, Ref, Ptr> self; 

		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator< T, const T&, const T*> const_iterator;
		iterator begin()
		{
			return iterator(_head->_next);//第一个有效元素的迭代器类
		}
		iterator end()
		{
			return iterator(_head);//最后一个有效元素的下一个，即_head
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}
		list()//构造函数
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
		}
		list(const list<T>& li)//拷贝构造
		{
			//新开一个链表，把值都拷贝进来
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;

			for (auto e : li)
			{
				push_back(e);
			}
		}
		//list<T>& operator=(const list<T>& li)//赋值运算符重载
		//{
		//	if (this != &li)//排除自己赋值给自己
		//	{
		//		clear();//先把自己的元素清除
		//		for (quto e : li)
		//		{
		//			push_back(e);//再赋值
		//		}
		//	}
		//	return *this;
		//}
		list<T>& operator=( list<T> li)//赋值运算符重载
		{
			std::swap(_head, li._head);//和传参进来的临时变量交换地址
			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				iterator next = it;//存在迭代器失效，所以要先保存下一个位置
				++next;
				delete it._node;
				it = next;
			}
			//再把指向改回来
			_head->_prev = _head;
			_head->_next = _head;
		}
		void push_back(const T& x) //复习之前循环双向链表的增删查改
		{
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;
			//  _head ..   tail newnode
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;

			//复用insert
			//insert(end(),x);
		}
		void push_front(const T& x)
		{
			Node* newnode = new Node(x);
			Node* start = _head->_next;
			//_head  newnode start
			start->_prev = newnode;
			newnode->_next = start;
			newnode->_prev = _head;
			_head->_next = newnode;

			//insert(begin(),x);
		}
		void pop_back()
		{
			Node* tail = _head->_prev;
			tail->_prev->_next = _head;
			_head->_prev = tail->_prev;


			//复用erase
			//erase(--end());
		}
		void pop_front()
		{
			_head->_next = _head->_next->_next;
			_head->_next->_next->_prev = _head;
			//erase(begin());
		}
		void insert(iterator pos,const T& x)
		{
			Node* posnode = pos._node;
			Node* prev = posnode->_prev;

			Node* newnode = new Node(x);
			//prev newnode posnode
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = posnode;
			posnode->_prev = newnode;
		}
		iterator erase(iterator pos)
		{
			Node* posnode = pos._node;
			Node* prev = posnode->_prev;
			Node* next = posnode->_next;
			//prev posnode next
			prev->_next = next;
			next->_prev = prev;
			delete posnode;
			return iterator(next);//防止迭代器失效问题，设置返回值为下一个指向
		}

	private:
		Node* _head;//循环双向链表的头指针
	};

	void Test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			*it *= 2;
			std::cout << *it << " ";
			++it;
		}
	}
	void Test_list2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);

		ListNode<int>* it1 = lt.begin()._node;//节点类指针
		list_iterator<int, int&, int*> it2 = lt.begin();//迭代器类，本身就是指针

		std::cout << sizeof(it1) << std::endl;
		std::cout << sizeof(it2) << std::endl;
	}
	void Test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_front(0);
		lt.push_front(-1);

		for (auto e : lt)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;

		lt.pop_back();
		lt.pop_front();
		for (auto e : lt)
		{
			std::cout << e << " ";
		}
	}
	void Test_list4()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);

		list<int> lt2(lt1);
		for (auto e : lt2)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;

		list<int> lt3;
		lt3.push_back(10);
		lt3.push_back(20);
		lt3.push_back(30);

		lt1 = lt3;
		for (auto e : lt1)
		{
			std::cout << e << " ";
		}
	}
}

int main()
{
	mylist::Test_list4();
	return 0;
}