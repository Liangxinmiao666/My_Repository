//#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once
//
//#include <iostream>
//#include <assert.h>
//using std::cout;
//using std::cin;
//using std::endl;
////using namespace std;
//
//class Date
//{
//public:
//	//friend ostream& operator<< (ostream& out, Date& d);
//	bool isLeapYear(int year)
//	{
//		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//	}
//
//	int GetMonthDay(int year, int month);
//
//	// Ĭ�����ɵ������������������ͳ�Ա���������Զ������ͳ�Ա��ȥ����������������
//	Date(int year = 1, int month = 1, int day = 1);
//
//	//Date(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//
//	//Date& operator=(const Date& d)
//	//{
//	//	if (this != &d)
//	//	{
//	//		_year = d._year;
//	//		_month = d._month;
//	//		_day = d._day;
//	//	}
//
//	//	return *this;
//	//}
//
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	Date operator+(int day)  const;
//	Date& operator+=(int day);
//
//	Date operator-(int day)  const;
//	Date& operator-=(int day);
//
//	// ++d1
//	Date& operator++()      // ǰ��
//	{
//		*this += 1;
//		return *this;
//	}
//
//	// d1++
//	Date operator++(int) // ����
//	{
//		Date tmp(*this);
//		*this += 1;
//		return tmp;
//	}
//
//	Date& operator--()     // ǰ��
//	{
//		*this -= 1;
//		return *this;
//	}
//
//	Date operator--(int) // ����
//	{
//		Date tmp(*this);
//		*this -= 1;
//		return tmp;
//	}
//
//	// d1 - d2
//	int operator-(const Date& d) const;
//
//	bool operator==(const Date& d)  const;
//	bool operator<(const Date& d)  const;
//
//	// inline��֧�������Ͷ���ֱ�ŵ�.h ��.cpp
//	// ���Գ�Ա������Ҫ��Ϊinline���ֱ���������涨��
//	// �����涨��Ĭ�Ͼ���inline
//	bool operator>(const Date& d)  const
//	{
//		return !(*this <= d);
//	}
//
//	bool operator>=(const Date& d)  const
//	{
//		return !(*this < d);
//	}
//
//	bool operator!=(const Date& d)  const
//	{
//		return  !(*this == d);
//	}
//
//	// d1 <= d2
//	bool operator<=(const Date& d)  const
//	{
//		return *this < d || *this == d;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////ostream& operator<< (ostream& out, Date& d)
////{
////	out << d._year << "-" << d._month << "-" << d._day << endl;
////	return out;
////}