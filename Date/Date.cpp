//#define _CRT_SECURE_NO_WARNINGS 1
//#include "Date.h"
//
//bool Date::operator<(const Date& d) const
//{
//	if ((_year < d._year)
//		|| (_year == d._year && _month < d._month)
//		|| (_year == d._year && _month == d._month && d._day < d._day))
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//// d1 == d2
//bool Date::operator==(const Date& d)const
//{
//	return _year == d._year
//		&& _month == d._month
//		&& _day == d._day;
//}
//
//int Date::GetMonthDay(int year, int month)
//{
//	assert(year >= 0 && month > 0 && month < 13);
//
//	const static int monthDayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (month == 2 && isLeapYear(year))
//	{
//		return 29;
//	}
//	else
//	{
//		return monthDayArray[month];
//	}
//}
//
//Date::Date(int year, int month, int day)
//{
//	if (year >= 1 &&
//		month <= 12 && month >= 1 &&
//		day >= 1 && day <= GetMonthDay(year, month))
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	else
//	{
//		cout << "ڷǷ" << endl;
//	}
//}
//
//// Ϣ2004
//// d1 + 100 -->d1.operator+(day);
//
//// d1 += 100
////Date& Date::operator+=(int day)
////{
////	*this = *this + day;
////	return *this;
////}
////
////Date Date::operator+(int day)
////{
////	Date ret(*this);
////
////	ret._day += day;
////	while (ret._day > GetMonthDay(ret._year, ret._month))
////	{
////		ret._day -= GetMonthDay(ret._year, ret._month);
////		ret._month++;
////		if (ret._month == 13)
////		{
////			++ret._year;
////			ret._month = 1;
////		}
////	}
////
////	return ret;
////}
//
//Date Date::operator+(int day)const
//{
//	Date ret(*this);
//	ret += day;
//
//	return ret;
//}
//
//// d1 += 100
//Date& Date::operator+=(int day)
//{
//	if (day < 0)
//		return *this -= -day;
//
//	_day += day;
//	while (_day > GetMonthDay(_year, _month))
//	{
//		_day -= GetMonthDay(_year, _month);
//		_month++;
//		if (_month == 13)
//		{
//			++_year;
//			_month = 1;
//		}
//	}
//
//	return *this;
//}
//
//Date Date::operator-(int day)const
//{
//	Date ret = *this;
//	ret -= day;
//	return ret;
//}
//
//// d1 -= 100
//Date& Date::operator-=(int day)
//{
//	if (day < 0)
//		return *this += -day;
//
//	_day -= day;
//	while (_day <= 0)
//	{
//		--_month;
//		if (_month == 0)
//		{
//			_month = 12;
//			--_year;
//		}
//
//		_day += GetMonthDay(_year, _month);
//	}
//
//	return *this;
//}
//
//// d1 - d2
//int Date::operator-(const Date& d)const
//{
//	int flag = 1;
//	Date max = *this;
//	Date min = d;
//	if (*this < d)
//	{
//		min = *this;
//		max = d;
//		flag = -1;
//	}
//
//	int n = 0;
//	while (min != max)
//	{
//		++n;
//		++min;
//	}
//
//	return n * flag;
//}