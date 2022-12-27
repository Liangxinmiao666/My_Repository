#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
#include<vector>
#include<list>
#include<queue>
#include<deque>
#include<assert.h>
#include<functional>
#include<time.h>

using namespace std;
#include"bit_queue.h"
#include"bit_stack.h"
#include"stack.h"
#include"queue.h"
#include"Priority_Queue.h"

namespace std {

	void test_stack()
	{
		stack<int, vector<int>> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);

		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
	}

	void test_queue()
	{
		queue<int> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}

	}

	void test_priority_queue()
	{
		//priority_queue<int> pq;
		priority_queue<int, vector<int>, greater<int>> pq;

		pq.push(2);
		pq.push(5);
		pq.push(1);
		pq.push(6);
		pq.push(8);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}

	// 商品
	struct Goods
	{
		string _name;
		double _price;
		size_t _saleNum;
		//...

		/*bool operator<(const Goods& g) const
		{
			return _price < g._price;
		}*/
	};

	struct LessPrice
	{
		bool operator()(const Goods& g1, const Goods& g2) const
		{
			return g1._price < g2._price;
		}
	};

	struct GreaterPrice
	{
		bool operator()(const Goods& g1, const Goods& g2) const
		{
			return g1._price > g2._price;
		}
	};

	struct LessSaleNum
	{
		bool operator()(const Goods& g1, const Goods& g2) const
		{
			return g1._saleNum < g2._saleNum;
		}
	};


	struct GreaterSaleNum
	{
		bool operator()(const Goods& g1, const Goods& g2) const
		{
			return g1._saleNum > g2._saleNum;
		}
	};
}
void test_Goods()
{
	// 指向数组的原生指针，本身就是天然迭代器
	int a[6] = { 1, 2, 5, 2, 5, 7 };
	sort(a, a + 6);
	sort(a, a + 6, greater<int>());

	Goods gds[4] = { { "苹果", 2.1, 1000}, { "香蕉", 3.0, 200}, { "橙子", 2.2,300}, { "菠萝", 1.5,50} };

	sort(gds, gds + 4, LessPrice());
	sort(gds, gds + 4, GreaterPrice());
	sort(gds, gds + 4, LessSaleNum());
	sort(gds, gds + 4, GreaterSaleNum());
}

void TestOP()
{
	srand(time(0));
	const int N = 10000000;
	vector<int> v;
	v.reserve(N);

	deque<int> dq1;
	deque<int> dq2;

	for (int i = 0; i < N; ++i)
	{
		auto e = rand();
		v.push_back(e);
		dq1.push_back(e);
		dq2.push_back(e);
	}

	int begin1 = clock();
	sort(v.begin(), v.end());
	int end1 = clock();

	int begin2 = clock();
	vector<int> copy(dq1.begin(), dq1.end());
	sort(copy.begin(), copy.end());
	dq1.assign(copy.begin(), copy.end());
	int end2 = clock();

	int begin3 = clock();
	sort(dq2.begin(), dq2.end());
	int end3 = clock();

	printf("vector Sort:%d\n", end1 - begin1);
	printf("vector sort copy back deque:%d\n", end2 - begin2);
	printf("deque Sort:%d\n", end3 - begin3);
}	

int main()
{
	//test_stack();
	//miao::test_stack();
	//miao::test_queue();
	//test_queue();
	miao::test_Priority_Queue();
	//test_priority_queue();
	
	//miao::test_Priority_Queue();
	//test_Goods();
	//miao::test_Priority_Queue2();
	TestOP();
	return 0;
}