#include<iostream>
#include<deque>
#include<vector>
#include <functional> // greater算法的头文件
using namespace std;

namespace Myadaper
{
	template<class T ,class container=deque<T>>
	class stack
	{
	public:
		void Push(const T& x)//入栈
		{
			_con.push_back(x);
		}
		void Pop()//出栈
		{
			_con.pop_back();
		}
		T& Top()//返回栈顶元素引用
		{
			return _con.back();
		}
		const T& Top()const
		{
			return _con.back();
		}
		bool Empty()//判空
		{
			return _con.empty();
		}
		size_t Size()//有效元素个数
		{
			return _con.size();
		}

	private:
		container _con;//底层容器
	};


	void TestStack()
	{
		//底层可以用不同的容器
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
		// 适配体现在第二个模板参数可以使用不同的容器，然后适配生成的queue效果是一样的。
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

	//对于优先级队列来说，用户可能需要提供比较器规则来确定具体的优先级顺序

	// 默认给的小于的仿函数，实现的大堆，
	template<class T>
	struct less
	{
		bool operator()(const T& a, const T& b)
		{
			return a < b;
		}
	};
	// 默认给的大于的仿函数，实现的小堆，
	template<class T>
	struct greater
	{
		bool operator()(const T& a, const T& b)
		{
			return a > b;
		}
	};

	template<class T,class container=vector<int>,class compare=less<T>>//注意是三个模板参数，分别对应元素类型、底层容器、比较器规则（仿函数）
	class priority_queue
	{
	public:
		void AdJustDown(size_t root)
		{
			compare com;//对应的比较规则
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
			AdJustUp(_con.size()-1);//插入数据后向上调整
		}
		void Pop()
		{
			swap(_con[0], _con[_con.size() - 1]);//删除堆顶数据，先交换首尾，在删除，接着向下调整
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
		//priority_queue<int> pq; //默认大堆
		priority_queue<int, vector<int>, greater<int>> pq;//传入比较的仿函数
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

		//比较器规则类
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