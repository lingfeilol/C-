#include<iostream>
using namespace std;
class Date
{
public:
	int  GetYearMonthday(int year, int month)
	{
		static int monthday[13] = { 0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (year % 400 == 0 || ((year % 4 == 0) && (year % 100 == 0)))
		{
			monthday[2] = 29;
		}
		return monthday[month];
	}

	Date(int year = 1900, int month = 1, int day = 1)  //ȫȱʡĬ�Ϲ��캯��
	{
		if (year > 0 && (month > 0 && month<13) && (day>0 && day < GetYearMonthday(year, month)))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
			cout << "����ʱ�䲻�Ϸ���������������" << endl;
	}
	Date(const Date& d)   //�������캯��
	{
		_year = d._year;
		_month = d._month;
		this->_day = d._day;
	}
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	Date operator+(int days)
	{
		Date ret = *this;
		ret._day += days;
		while (ret._day > GetYearMonthday(ret._year, ret._month))
		{
			ret._day -= GetYearMonthday(ret._year, ret._month);
			ret._month++;
			if (ret._month == 13)
			{
				ret._year++;
				ret._month = 1;
			}
		}
		return ret;
	}
	Date operator-(int days)
	{
		Date ret = *this;
		
		while(days >ret._day)
		{
			days -= ret._day;
			ret._month--;
			if (ret._month == 0)
			{
				ret._year--;
				ret._month = 12;
			}
			if (GetYearMonthday(ret._year, ret._month) < days)
			{
				days = days - GetYearMonthday(ret._year, ret._month);
				ret._month--;
			}
		}
		ret._day = GetYearMonthday(ret._year, ret._month)-days;
		return ret;
	}
	int Allyearday(int year) //ȫ������
	{
		int allyear = 0;
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			allyear = 366;
		}
		else
			allyear = 365;
		return allyear;
	}
	int alldays(int _year, int _month, int _day)
	{
		int sum = 0;
		for (int i = 0; i < _year; i++)
		{
			sum += Allyearday(i);
		}
		int monthdays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((_year % 4 == 0 && _year % 100 != 0) && _year % 400 == 0 )
		{
			monthdays[2] = 29;
		}
		sum += monthdays[_month];
		sum += _day;

		return sum;
	}
	int operator-(const Date& d)    //������������
	{
		int ret = 0;
		int sum1 = 0;
		int sum2 = 0;
		sum1 = alldays(_year, _month, _day);
		sum2 = alldays(d._year, d._month, d._day);
		ret = sum1 - sum2;
		return ret;
	}
	Date& operator++()//ǰ���Լ�
	{
		if (_day + 1 > GetYearMonthday(_year, _month))
		{
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
				_day = 1;
			}
			_day = 1;
		}
		else
			_day++;
		return *this;
	}
	Date operator++(int) //�����Լ�   ���ص�ֵ��û�в�����
	{
		Date tmp = *this; //��������������� �����·��صľ�����
		if (_day + 1 > GetYearMonthday(_year, _month))
		{
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
				_day = 1;
			}
			_day = 1;
		}
		else
			_day++;
		return tmp;
	}

	Date& operator--() //ǰ���Լ�
	{
		if (_day - 1 == 0)
		{
			_month--;
			if (_month != 0)
			{
				_day = GetYearMonthday(_year, _month);
			}
			else
			{
				_year--;
				_month = 12;
				_day = GetYearMonthday(_year, _month);
			}
		}
		else
			_day--;
		return *this;
	}
	Date operator--(int) //�����Լ�
	{
		Date tmp = *this;
		if (_day - 1 == 0)
		{
			_month--;
			if (_month != 0)
			{
				_day = GetYearMonthday(_year, _month);
			}
			else
			{
				_year--;
				_month = 12;
				_day = GetYearMonthday(_year, _month);
			}
		}
		else
			_day--;
		return tmp;
	}

	bool operator>(const Date& d)const
	{
		if (_year > d._year)
			return 1;
		else if (_year < d._year)
			return 0;
		else
		{
			if (_month>d._month)
				return 1;
			else if (_month < d._month)
				return 0;
			else
			{
				if (_day>d._day)
					return 1;
				else
					return 0;
			}
		}
	}
	bool operator>=(const Date& d)const
	{
		if (_year > d._year)
			return 1;
		else if (_year < d._year)
			return 0;
		else
		{
			if (_month>d._month)
				return 1;
			else if (_month < d._month)
				return 0;
			else
			{
				if (_day>=d._day)
					return 1;
				else 
					return 0;
			}
		}
	}
	bool operator<(const Date& d)const
	{
		if (_year < d._year)
			return 1;
		else if (_year > d._year)
			return 0;
		else
		{
			if (_month<d._month)
				return 1;
			else if (_month > d._month)
				return 0;
			else
			{
				if (_day<d._day)
					return 1;
				else
					return 0;
			}
		}
	}
	bool operator<=(const Date& d)const
	{
		if (_year < d._year)
			return 1;
		else if (_year > d._year)
			return 0;
		else
		{
			if (_month<d._month)
				return 1;
			else if (_month > d._month)
				return 0;
			else
			{
				if (_day<=d._day)
					return 1;
				else
					return 0;
			}
		}
	}

	bool operator==(const Date& d)const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	bool operator!=(const Date& d)const
	{
		return _year != d._year
			&& _month != d._month
			&& _day != d._day;
	}
	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};



void test1()
{
	Date d1(2019, 1, 1);
	Date d2(d1);
	Date d3 = d2;
	d1.print();
	d2.print();
	d3.print();
	Date d4(2020, 0, 14);

	
}
void test2()
{
	Date d1(2020, 3, 14);
	Date d2(2020, 3, 15);
	cout << (d1>d2) << endl;
	cout << (d1<d2)<< endl;
	cout << (d1<=d2) << endl;

	Date d3(2020, 3, 14);
	Date d4(2020, 3, 14);
	cout << (d3==d4)<< endl;

}
void test3()
{
	Date d1(2020, 3, 14);
	Date d2(2030, 3, 14);
	cout << d1 - d2 << endl;
}
void test4()
{
	Date d1(2020, 3, 14);
	(d1 + 92).print();
	(d1 - 43).print();
}
int main()
{
	test4();
	return 0;
}
 