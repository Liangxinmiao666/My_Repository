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
	
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month) const;

	void Print() const
	{
		cout << _year << "." << _month << "." << _day << endl;
	}

	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1);
	// �������캯��
	// d2(d1)
	Date(const Date& d);
	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);//����const ��ֵȨ�޷Ŵ�
	// ��������
	~Date();
	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day) const;
	// ����-����
	Date operator-(int day) const;
	// ����-=����
	Date& operator-=(int day);
	// ǰ��++
	Date& operator++();
	// ����++
	Date operator++(int);
	// ����--
	Date operator--(int);
	// ǰ��--
	Date& operator--();
	// >���������
	bool operator>(const Date& d) const; 
	// ==���������
	bool operator==(const Date& d) const;
	// >=���������
	bool operator >= (const Date& d) const; 
	// <���������
	bool operator < (const Date& d) const; 
	// <=���������
	bool operator <= (const Date& d) const; 
	// !=���������
	bool operator != (const Date& d) const;  
	// ����-���� ��������
	int operator-( Date& d);
private:
	int _year;
	int _month;
	int _day;
};

