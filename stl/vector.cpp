#if 0
namespace Myvector
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;          //定义迭代器指针
		typedef const T* const_iterator;

		vector()  //无参默认构造函数
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		vector(size_t n, const T& value = T()) //带参全缺省构造函数
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}
		vector(const vector<T>& v)//拷贝构造
		{
			_start = new T[v.size()];//开空间
			_finish = _start + v.size();
			_endofstorage = _start + v._endofstorage;
			memcpy(_start, v._start, v.size()*sizeof(T); //拷贝数据

		}
		~vector()//析构
		{
			delete _start;
			_start = _finish = _endofstorage = nullptr;
		}
		vector<T>& operator=(vector<T> v) //赋值运算符重载
		{
			this->swap(v);
			return *this;
		}
		iterator begin() { return _start;}
		const_iterator begin() const { return _start; }
		iterator end(){ return _finish; }
		const_iterator end() const { return _finish; }
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}
		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _endofstorage - _start;
		}
		//resize 与 reserve
		void reserve(size_t n)//增容
		{
			if (n > capacity())//需要扩容 新开空间，再拷贝，再删去原来的空间，这也是vector的缺点，就是涉及的这些空间操作
			{
				size_t size = size();
				T* tmp;
				 tmp = new T[n];
				 if (tmp)//开辟成功，拷数据
				 {
					 memcpy(tmp, _start, size*sizeof(T));
				 }
				 _start = tmp;//再改变指向
				 _finish = _start + size;
				 _endofstorage = _start + n;
			}
		}
		void resize(size_t n，const T& value=T())//对有效元素个数操作
		{
			if (n <= size())//小于等于
			{
				_finish = _start + n;
			}
			else //大于原始数量
			{
				if (n > capacity())//且大于原始容量，需要扩容
				{
					reserve(n);
				}
				//增长的要赋值
				while (_finish != _start + n)
				{
					*_finish = value;
					_finish++;
				}
			}
		}

		//增删查改
		void push_back(const T& val)
		{
			//if (_finish == _endofstorage) //要扩容
			//{
			//	size_t newcapaticy = capacity() == 0 ? 1 : capacity() * 2;  //可能刚开始为空，需要特判
			//	reserve(newcapaticy);
			//}
			//*_finish = value;
			//_finish++;

			//可以直接复用insert()
			insert(end(), val);
		}
		void pop_back()
		{
			//--_finish;
			//复用erase
			erase(--end());//z注意最后一个位置是_finish的前一个，这和C语言顺序表里的表示是一样的
		}
		iterator insert(iterator pos, const T& val)//pos位置的前一个位置插入一个  
		{
			assert(pos < _finish);//判断pos有效性
			if (_finish == _endofstorage)//需要扩容
			{
				size_t len = pos - _start;//保留相对位置  ,扩容后原来空间不会同的，所以保存pos位置
				size_t newcapacity = capacity() == 0 ? 1 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + len;

				iterator end = _finish - 1;//由于是连续空间，所以插入数据后还要保持相对位置，所以后面的元素要后移一位
				while (end>=pos)
				{
					*(end + 1) = *end;
					end--;
				}
				*pos = value;//插入
				_finish++;//有效个数加一
				return pos;
			}
		}

		iterator erase(iterator pos)//删除当前pos位置的元素 返回值为删除位置的下一个位置。存在迭代器失效的情况，失效具体指的是无法使用或者继续使用会输出错误的结果等等
		{
			assert(pos < _finish);
			//直接依次让后面的元素覆盖即可达到删除的效果 ，但是
			iterator begin = pos + 1;
			whiel(begin != _finish)
			{
				*(begin - 1) = *begin;
				begin++;
			}
			_finish--;
			return pos;//此时的pos是删除前pos的下一个位置
		}

		//元素访问，因为是连续空间，所以支持随机访问  []下标访问
		T& operator[](size_t x)
		{
			return _start[x];
		}
		const T& operator[](size_t x) const
		{
			return _start[x];
		}
	private:
		iterator _start;    //只想数据块的开始
		iterator _finish;   //指向有效元素的末尾
		iterator _endofstorage;  //指向存储容量的尾
		//对应于之前写C语言顺序表的  结构体成员   T* arr 指向数组的指针, size_t size有效元素个数, size_t  capacity//总容量，只不过vector底层用了三个指针，利用指针运算来标识数量 
	};
}
#endif


#include<iostream>
#include<vector>
int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//std::vector<int>::iterator it = v.begin();
	auto pos = find(v.begin(), v.end(), 3);
	v.erase(pos);
	std::cout << *pos << std::endl;

	//pos++;
	return 0;
}