#include"string.h"
void TestString1()
{
	bit::string s1("1111");
	bit::string s2("11");
}

void TestString2()
{
	bit::string s3("hello world");
	s3.insert(0,"");
}

int main()
{
	TestString2();
	return 0;
}