#define _CRT_SECURE_NO_WARNINGS 1
#include"Date_test.h"
void Test1()
{
	Date d1(2022, 1, 1);
	(d1 + 50).Print();
}
void Test2()
{
	Date d2(2022,1,31);
	d2 += 10000;
	d2.Print();
	d2 -= 10000;
	d2.Print();
}

void Test3()
 {
	Date d3(2022, 1, 1);
	Date d4=d3+15;
	d4.Print();
}

void Test4()
{
	Date d5(2020, 2, 28);
	Date d6(d5);
	Date d7(d5);
	d6 -= 4;
	d7++;
	d6.Print();
	d7.Print();

}
void Test5()
{
	Date d8(2022, 5, 31);
	Date d9(2022, 3, 31);
	cout << (d9 - d8) << endl;
}
void Test6()
{
	Date d10(2022, 8, 3);
	cout << d10;
	Date d11;
	cin >> d11;
}

int main()
{
	Test6();

	
	return 0;
}