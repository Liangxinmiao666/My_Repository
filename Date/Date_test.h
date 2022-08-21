#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once
#include<iostream>
using std::cout;
using std::cin;
using std::endl;


class Date
{
public:
	friend std::ostream& operator<<(std::ostream& out ,const Date& d);
	friend std::istream& operator>>(std::istream& in , Date& d);

	bool IsLeapYear(int year) const;
	
	// 获取某年某月的天数
	int GetMonthDay(int year, int month) const;

	void Print() const
	{
		cout << _year << "." << _month << "." << _day << endl;
	}

	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1);
	// 拷贝构造函数
	// d2(d1)
	Date(const Date& d);
	// 赋值运算符重载
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);//不加const 右值权限放大
	// 析构函数
	~Date();
	// 日期+=天数
	Date& operator+=(int day);
	// 日期+天数
	Date operator+(int day) const;
	// 日期-天数
	Date operator-(int day) const;
	// 日期-=天数
	Date& operator-=(int day);
	// 前置++
	Date& operator++();
	// 后置++
	Date operator++(int);
	// 后置--
	Date operator--(int);
	// 前置--
	Date& operator--();
	// >运算符重载
	bool operator>(const Date& d) const; 
	// ==运算符重载
	bool operator==(const Date& d) const;
	// >=运算符重载
	bool operator >= (const Date& d) const; 
	// <运算符重载
	bool operator < (const Date& d) const; 
	// <=运算符重载
	bool operator <= (const Date& d) const; 
	// !=运算符重载
	bool operator != (const Date& d) const;  
	// 日期-日期 返回天数
	int operator-( Date& d);
private:
	int _year;
	int _month;
	int _day;
};

