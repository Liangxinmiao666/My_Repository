#define _CRT_SECURE_NO_WARNINGS 1
#include"Date_test.h"

bool Date::IsLeapYear(int year) const
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int Date::GetMonthDay(int year, int month) const
{
	//加static 因为这个函数使用次数很多 不加的话 每次都得开辟空间、销毁
	static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = days[month];
	if (month == 2
		&& (IsLeapYear(year)))
	{
		return 29;
	}
	else
		return days[month];
}

 Date:: Date(int year, int month, int day)//定义不要写默认参数(缺省参数)
{
	 if (year > 0 && month > 0 && month < 12 && day >= 1 && day <= GetMonthDay(year, month))
	 {
		 _year = year;
		 _month = month;
		 _day = day;
	 }
	 else
	 {
		 cout << "日期非法" << endl;
	 }
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date:: ~Date()
{
	cout << "~Date()" << endl;
}

Date& Date::operator=(const Date& d)
{
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
	return *this;

}

Date& Date::operator+=(int day)
{
	*this = *this + day;
	return *this;
}

Date Date:: operator+(int day) const
{
	Date tmp(*this);
	tmp._day += day;
	while (1)
	{
		if (tmp._day > GetMonthDay(tmp._year, tmp._month)) //因为有const修饰Date* const this  
			//所以不能直接调用GetMonthDay() [如果说GetMonthDay() 没有用const修饰]
			//相当于调用GetMonthDay(const Date* const this,tmp._year, tmp._month)
			//接收GetMonthDay(Date* const this,year,month)
		{
			tmp._day -=  GetMonthDay(tmp._year, tmp._month);
			tmp._month++;
		}

		else
		{
			break;
		}

		if (tmp._month > 12)
		{
			tmp._year++;
			tmp._month = 1;
		}
	}
	
	return tmp;
	
}

Date& Date::operator-=(int day)
{
	if (day < 0)
		return *this += -day;

	if (day < _day)
	{
		_day -= day;
		return *this;
	}
	//else
	//{
		while (_day <= day)
		{
			_month--;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
			day -= _day;
			_day = GetMonthDay(_year, _month);
		}
		/*if (GetMonthDay(_year, _month) < day)
		{
			*this -= day;
		}*/ 
		//_day = GetMonthDay(_year,_month)-day;
		return *this;
	//}

	//if (day < 0)
	//	return *this += -day;
	//	
	//_day -= day;
	//while (_day <= 0)
	//{
	//	--_month;
	//	if (_month == 0)
	//	{
	//		_month = 12;
	//		--_year;
	//	}
	//	
	//	_day += GetMonthDay(_year, _month);
	//}
	//	
	//return *this;
}

Date Date:: operator- (int day) const
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

Date& Date:: operator++()
{
	*this += 1;
	return *this;
}

Date Date:: operator++(int i)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date& Date:: operator--()
{
	*this -=1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
bool Date:: operator>(const Date& d) const
{
	/*if (this->_year > d._year 
		|| this->_year == d._year && this->_month > d._month 
		||this->_year == d._year && this->_month == d._month && this->_day > d._day)
	{
		return true;
	}
	else
		return false;*/
	return (_year > d._year
		|| _year == d._year && _month > d._month
		|| _year == d._year && _month == d._month && _day > d._day);
}

bool Date:: operator==(const Date& d) const
{
	return (this->_year == d._year && this->_month == d._month && this->_day == d._day);
}

bool Date:: operator>=(const Date& d)const
{
	/*if (*this > d || *this == d)
		return true;
	else
		return false;*/
	return (*this > d) || *this == d;

}

bool Date:: operator<(const Date& d)const
{
	/*if (d > *this)  //
		return true;
	else
		return false;*/
	return !(*this > d);
}

bool Date:: operator<= (const Date & d)const
{
	//if (*this < d || *this == d)
	//	return true;
	//else
	//	return false;
	return (*this < d) || *this == d;
}

bool Date:: operator!=(const Date& d)const
{
	//if (*this == d)
	//	return false;
	//else
	//	return true;
	return !(*this == d);
}

//2022.5.1 - 2022.3.28
int Date::operator-( Date& d)
{
	//Date max(this->_year,this->_month,1);
	//Date min(d._year, d._month, this->GetMonthDay(d._year,d._month));
	////Date min(d._year, d._month, d.GetMonthDay(d._year, d._month));//为什么无法调用d的GetMontthDay函数
	//int n = 1;
	//if (*this > d)
	//{
	//	while (max != min)
	//	{
	//		min++;
	//		n++;
	//	}
	//	return (n + this->_day + this->GetMonthDay(d._year, d._month) - d._day);

	//}

	//else
	//{
	//	max = d;
	//	min = *this;
	//	while (max != min)
	//	{
	//		min++;
	//		n++;
	//	}
	//	return -(n + this->_day + this->GetMonthDay(d._year, d._month) - d._day);

	//}
	

	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this < d)
	{
		min = *this;
		max = d;
		flag = -1;
	}
	
	int n = 0;
	while (min != max)
	{
		++n;
		++min;
	}
	
	return n * flag;
	
}
std::ostream& operator<<(std::ostream& out, const Date& d)
{
	out << d._year <<"-" << d._month <<"-" << d._day << endl;
	return out;
}
std::istream& operator>>(std::istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day ;
	return in;
}
