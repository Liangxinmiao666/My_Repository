#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<deque>

namespace miao{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		const T& top()
		{
			return _con.back();
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};

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
}