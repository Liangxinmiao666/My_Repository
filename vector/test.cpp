#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

#include<vector>
using namespace std;

#include"bite_vector.h"
#include"vector.h"

//class Solution {
//    string NumToStr[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//public:
//    void letterCombine(string digits, size_t di, string combineStr, vector<string>& ans)
//    {
//        if (di == digits.size())
//        {
//            ans.push_back(combineStr);
//            return;
//        }
//        int num = digits[di] - '0';
//        string str = NumToStr[num];
//
//        for (auto c : str)
//        {
//            letterCombine(digits, di + 1, combineStr + str, ans);
//        }
//    }
//    vector<string> letterCombinations(string digits) {
//        vector<string> ans;
//        string str;
//        size_t i = 0;
//        letterCombine(digits, i, str, ans);
//        return ans;
//    }
//};
//
//int main()
//{
//    Solution().letterCombinations("23");
//    return 0;
//}

void test_vector0()
{
	std::vector<int> v;
	//v.reserve(10);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	cout << v.size() << ":" << v.capacity() << endl;
	auto pos = find(v.begin(), v.end(), 2);
	if (pos != v.end())
	{
		 /*v.insert(pos, 20);*/
		pos=v.insert(pos, 20);
	}

	cout << *pos << endl;
	*pos = 10;
	cout << *pos << endl;
}
void test_vector1()
{
	std::vector<int> v;
	v.reserve(100);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	cout << v.size() << ":" << v.capacity() << endl;
	auto pos = find(v.begin(), v.end(), 4);
	if (pos != v.end())
	{
		//v.erase(pos);
		pos=v.erase(pos);

	}
	
	cout << v.size() << ":" << v.capacity() << endl;
	cout << *pos<<endl;
	*pos = 10;
	cout << *pos << endl;
	for (auto e : v)
	{
		cout << e << endl;
	}
	cout << endl;
}
void test_vector2()
{
	std::vector<int> v;
	v.reserve(100);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	//v.push_back(4);
	cout << v.size() << ":" << v.capacity() << endl;
	auto pos = find(v.begin(), v.end(), 2);
	if (pos != v.end())
	{
		v.erase(pos);
	}

	cout << v.size() << ":" << v.capacity() << endl;
	pos++;
	cout << *pos << endl;
	*pos = 10;
	cout << *pos << endl << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector3()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(5);


	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_vector7()
{
	miao::vector<vector<int>> ret = miao::Solution().generate(5);

	for (size_t i = 0; i < ret.size(); ++i)
	{
		for (size_t j = 0; j < ret[i].size(); ++j)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;	
}


int main()
{
	test_vector7();
	return 0;
}