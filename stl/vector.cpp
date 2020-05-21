#if 0
namespace Myvector
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;          //���������ָ��
		typedef const T* const_iterator;

		vector()  //�޲�Ĭ�Ϲ��캯��
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		vector(size_t n, const T& value = T()) //����ȫȱʡ���캯��
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
		vector(const vector<T>& v)//��������
		{
			_start = new T[v.size()];//���ռ�
			_finish = _start + v.size();
			_endofstorage = _start + v._endofstorage;
			memcpy(_start, v._start, v.size()*sizeof(T); //��������

		}
		~vector()//����
		{
			delete _start;
			_start = _finish = _endofstorage = nullptr;
		}
		vector<T>& operator=(vector<T> v) //��ֵ���������
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
		//resize �� reserve
		void reserve(size_t n)//����
		{
			if (n > capacity())//��Ҫ���� �¿��ռ䣬�ٿ�������ɾȥԭ���Ŀռ䣬��Ҳ��vector��ȱ�㣬�����漰����Щ�ռ����
			{
				size_t size = size();
				T* tmp;
				 tmp = new T[n];
				 if (tmp)//���ٳɹ���������
				 {
					 memcpy(tmp, _start, size*sizeof(T));
				 }
				 _start = tmp;//�ٸı�ָ��
				 _finish = _start + size;
				 _endofstorage = _start + n;
			}
		}
		void resize(size_t n��const T& value=T())//����ЧԪ�ظ�������
		{
			if (n <= size())//С�ڵ���
			{
				_finish = _start + n;
			}
			else //����ԭʼ����
			{
				if (n > capacity())//�Ҵ���ԭʼ��������Ҫ����
				{
					reserve(n);
				}
				//������Ҫ��ֵ
				while (_finish != _start + n)
				{
					*_finish = value;
					_finish++;
				}
			}
		}

		//��ɾ���
		void push_back(const T& val)
		{
			//if (_finish == _endofstorage) //Ҫ����
			//{
			//	size_t newcapaticy = capacity() == 0 ? 1 : capacity() * 2;  //���ܸտ�ʼΪ�գ���Ҫ����
			//	reserve(newcapaticy);
			//}
			//*_finish = value;
			//_finish++;

			//����ֱ�Ӹ���insert()
			insert(end(), val);
		}
		void pop_back()
		{
			//--_finish;
			//����erase
			erase(--end());//zע�����һ��λ����_finish��ǰһ�������C����˳�����ı�ʾ��һ����
		}
		iterator insert(iterator pos, const T& val)//posλ�õ�ǰһ��λ�ò���һ��  
		{
			assert(pos < _finish);//�ж�pos��Ч��
			if (_finish == _endofstorage)//��Ҫ����
			{
				size_t len = pos - _start;//�������λ��  ,���ݺ�ԭ���ռ䲻��ͬ�ģ����Ա���posλ��
				size_t newcapacity = capacity() == 0 ? 1 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + len;

				iterator end = _finish - 1;//�����������ռ䣬���Բ������ݺ�Ҫ�������λ�ã����Ժ����Ԫ��Ҫ����һλ
				while (end>=pos)
				{
					*(end + 1) = *end;
					end--;
				}
				*pos = value;//����
				_finish++;//��Ч������һ
				return pos;
			}
		}

		iterator erase(iterator pos)//ɾ����ǰposλ�õ�Ԫ�� ����ֵΪɾ��λ�õ���һ��λ�á����ڵ�����ʧЧ�������ʧЧ����ָ�����޷�ʹ�û��߼���ʹ�û��������Ľ���ȵ�
		{
			assert(pos < _finish);
			//ֱ�������ú����Ԫ�ظ��Ǽ��ɴﵽɾ����Ч�� ������
			iterator begin = pos + 1;
			whiel(begin != _finish)
			{
				*(begin - 1) = *begin;
				begin++;
			}
			_finish--;
			return pos;//��ʱ��pos��ɾ��ǰpos����һ��λ��
		}

		//Ԫ�ط��ʣ���Ϊ�������ռ䣬����֧���������  []�±����
		T& operator[](size_t x)
		{
			return _start[x];
		}
		const T& operator[](size_t x) const
		{
			return _start[x];
		}
	private:
		iterator _start;    //ֻ�����ݿ�Ŀ�ʼ
		iterator _finish;   //ָ����ЧԪ�ص�ĩβ
		iterator _endofstorage;  //ָ��洢������β
		//��Ӧ��֮ǰдC����˳����  �ṹ���Ա   T* arr ָ�������ָ��, size_t size��ЧԪ�ظ���, size_t  capacity//��������ֻ����vector�ײ���������ָ�룬����ָ����������ʶ���� 
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