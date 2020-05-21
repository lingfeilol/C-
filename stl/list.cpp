#include<iostream>

namespace mylist
{
	//list�Ľڵ���
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
	List �ĵ�����
	������������ʵ�ַ�ʽ������Ӧ���������ײ����ݽṹʵ�֣�
	1. ԭ��ָ̬�룬���磺vector
	2. ��ԭ��ָ̬����з�װ���������ʹ����ʽ��ָ����ȫ��ͬ��������Զ�������б���ʵ�����·�����
	��1. ָ����Խ����ã������������б�������operator*()
	��2. ָ�����ͨ��->��������ָ�ռ��Ա�����������б�������oprator->()
	��3. ָ�����++����ƶ������������б�������operator++()��operator++(int)
	����operator--()/operator--(int)�ͷ���Ҫ���أ����ݾ���Ľṹ������˫�����������ǰ
	�ƶ���������Ҫ���أ������forward_list�Ͳ���Ҫ����--
	4. ��������Ҫ�����Ƿ���ȵıȽϣ���˻���Ҫ����operator==()��operator!=()
	*/
	//��������ṹԪ�ص�ַ���������ģ�����ʹ��ԭ��ָ�룬�����Լ���װ���һ�Ҫ������ָ����صĲ����� 
	//��������

	template <class T,class Ref,class Ptr>
	struct list_iterator
	{
		typedef ListNode<T> Node;  //�ڵ���
		typedef list_iterator<T, Ref, Ptr> self;//  ������ģ����    Ref��ӦT&,Ptr��ӦT*  ģ����������Ƹ��ã�ʵ�ֳ���ͨ��������const������

		Node* _node;//�ڵ�ָ�� ���Ա
		list_iterator( Node* _node = nullptr)
			:_node(_node)
		{}

		// ����ĵ������ĺ��Ļ��ǽڵ��ָ��
		// ���Ƿ�װ���࣬����ͨ�������ȥ����++ * ����Ϊ

		//����ָ���Ӧ�ã�ȡ��ǰ�ڵ��_val
		//T& operator*()
		T& operator*() 
		{
			return _node->_val;
		}
		//ָ����ʳ�Ա������-> 
		//T* operator->()
		T* operator->()
		{
			return &_node->_val;
		}
		//����ģ��������Ƹ���
		self& operator++()//ǰ�üӼ�
		{
			_node = _node->_next;
			return *this;
		}
		self& operator--()
		{
			_node = _node->_prev;
			retunr *this;
		}
		self operator++(int) //���üӼ�
		{
			//���浱ǰֵ
			self tmp(*this); //list_iterator<T> tmp(*this);//
			_node = _node->_next;
			return tmp;
		}
		self operator--(int)//���ü���
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



	//ģ��ʵ��list  ��ɾ��ķ��ʵ�
	template <class T>
	class list
	{
		typedef ListNode<T> Node; //ʵ�����Ľڵ���
	public:
		//typedef list_iterator<T, Ref, Ptr> self; 

		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator< T, const T&, const T*> const_iterator;
		iterator begin()
		{
			return iterator(_head->_next);//��һ����ЧԪ�صĵ�������
		}
		iterator end()
		{
			return iterator(_head);//���һ����ЧԪ�ص���һ������_head
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}
		list()//���캯��
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
		}
		list(const list<T>& li)//��������
		{
			//�¿�һ��������ֵ����������
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;

			for (auto e : li)
			{
				push_back(e);
			}
		}
		//list<T>& operator=(const list<T>& li)//��ֵ���������
		//{
		//	if (this != &li)//�ų��Լ���ֵ���Լ�
		//	{
		//		clear();//�Ȱ��Լ���Ԫ�����
		//		for (quto e : li)
		//		{
		//			push_back(e);//�ٸ�ֵ
		//		}
		//	}
		//	return *this;
		//}
		list<T>& operator=( list<T> li)//��ֵ���������
		{
			std::swap(_head, li._head);//�ʹ��ν�������ʱ����������ַ
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
				iterator next = it;//���ڵ�����ʧЧ������Ҫ�ȱ�����һ��λ��
				++next;
				delete it._node;
				it = next;
			}
			//�ٰ�ָ��Ļ���
			_head->_prev = _head;
			_head->_next = _head;
		}
		void push_back(const T& x) //��ϰ֮ǰѭ��˫���������ɾ���
		{
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;
			//  _head ..   tail newnode
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;

			//����insert
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


			//����erase
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
			return iterator(next);//��ֹ������ʧЧ���⣬���÷���ֵΪ��һ��ָ��
		}

	private:
		Node* _head;//ѭ��˫�������ͷָ��
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

		ListNode<int>* it1 = lt.begin()._node;//�ڵ���ָ��
		list_iterator<int, int&, int*> it2 = lt.begin();//�������࣬�������ָ��

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