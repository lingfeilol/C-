#include<iostream>
#include<deque>
#include<vector>
#include <functional> // greater�㷨��ͷ�ļ�
using namespace std;

namespace Myadaper
{
	template<class T ,class container=deque<T>>
	class stack
	{
	public:
		void Push(const T& x)//��ջ
		{
			_con.push_back(x);
		}
		void Pop()//��ջ
		{
			_con.pop_back();
		}
		T& Top()//����ջ��Ԫ������
		{
			return _con.back();
		}
		const T& Top()const
		{
			return _con.back();
		}
		bool Empty()//�п�
		{
			return _con.empty();
		}
		size_t Size()//��ЧԪ�ظ���
		{
			return _con.size();
		}

	private:
		container _con;//�ײ�����
	};


	void TestStack()
	{
		//�ײ�����ò�ͬ������
		//Myadaper::stack<int, vector<int>> s;
		// Myadaper::stack<int, list<int>> s;
		//Myadaper::stack<int, deque<int>>
		stack<int,deque<int>> s;
		s.Push(1);
		s.Push(2);
		s.Push(3);
		s.Push(4);
		cout << s.Size() << endl;
		cout << s.Top() << endl;
		s.Pop();
		s.Pop();
		cout << s.Size() << endl;
		cout << s.Top() << endl;

		// FIFO first in last out
		while (!s.Empty())
		{
			cout << s.Top() << " ";
			s.Pop();
		}
		cout << endl;
	}


	template<class T,class container=deque<T>>
	class queue
	{
	public:
		void Push(const T& x)
		{
			_con.push_back(x);
		}
		void Pop()
		{
			_con.pop_front();
		}
		T& Front()
		{
			return _con.front();
		}
		T& Back()
		{
			return  _con.back();
		}
		const T& Front()const
		{
			return _con.front();
		}
		const T& Back()const
		{
			return _con.back();
		}
		size_t Size()
		{
			return _con.size();
		}
		bool Empty()
		{
			return _con.empty();
		}
	private:
		container _con;
	};


	void TestQueue()
	{
		// ���������ڵڶ���ģ���������ʹ�ò�ͬ��������Ȼ���������ɵ�queueЧ����һ���ġ�
		//queue<int, deque<int>> q;
		//queue<int, list<int>> q;
		queue<int,deque<int>> q;
		q.Push(1);
		q.Push(2);
		q.Push(3);
		q.Push(4);
		cout << q.Size() << endl;
		cout << q.Front() << endl;
		cout << q.Back() << endl;
		q.Pop();
		q.Pop();
		cout << q.Size() << endl;
		cout << q.Front() << endl;
		cout << q.Back() << endl;
		// FIFO first in first out
		while (!q.Empty())
		{
			cout << q.Front() << " ";
			q.Pop();
		}
		cout << endl;
	}

	//�������ȼ�������˵���û�������Ҫ�ṩ�Ƚ���������ȷ����������ȼ�˳��

	// Ĭ�ϸ���С�ڵķº�����ʵ�ֵĴ�ѣ�
	template<class T>
	struct less
	{
		bool operator()(const T& a, const T& b)
		{
			return a < b;
		}
	};
	// Ĭ�ϸ��Ĵ��ڵķº�����ʵ�ֵ�С�ѣ�
	template<class T>
	struct greater
	{
		bool operator()(const T& a, const T& b)
		{
			return a > b;
		}
	};

	template<class T,class container=vector<int>,class compare=less<T>>//ע��������ģ��������ֱ��ӦԪ�����͡��ײ��������Ƚ������򣨷º�����
	class priority_queue
	{
	public:
		void AdJustDown(size_t root)
		{
			compare com;//��Ӧ�ıȽϹ���
			size_t parent = root;
			size_t child = 2 * parent + 1;
			while (child < _con.size())
			{
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1])
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
					child++;
				//if (_con[child]>_con[parent])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
				{
					break;
				}
			}
		}
		void AdJustUp(size_t child)
		{
			compare com;
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[child] > _con[parent])
				if (com(_con[parent],_con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void Push(const T& x)
		{
			_con.push_back(x);
			AdJustUp(_con.size()-1);//�������ݺ����ϵ���
		}
		void Pop()
		{
			swap(_con[0], _con[_con.size() - 1]);//ɾ���Ѷ����ݣ��Ƚ�����β����ɾ�����������µ���
			_con.pop_back();
			AdJustDown(0);
		}
		const T& Top()const
		{
			return _con[0];
		}
		bool Empty()
		{
			return _con.empty();
		}
		size_t Size()
		{
			return _con.size();
		}

	private:
		container _con;
	};
	


	void test_priority_queue()
	{
		//priority_queue<int> pq; //Ĭ�ϴ��
		priority_queue<int, vector<int>, greater<int>> pq;//����Ƚϵķº���
		pq.Push(10);
		pq.Push(2);
		pq.Push(30);
		pq.Push(21);
		pq.Push(5);

		while (!pq.Empty())
		{
			cout << pq.Top() << " ";
			pq.Pop();
		}
		cout << endl;

		//�Ƚ���������
		less<int> less_func;
		cout << less_func(1, 2) << endl;
		cout << less_func.operator()(1, 2) << endl;

	}

}



int main()
{
	//Myadaper::TestStack();
	//Myadaper::TestQueue();
	Myadaper::test_priority_queue();
	return 0;
}