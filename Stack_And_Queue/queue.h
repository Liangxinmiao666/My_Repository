#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<queue>

//using namespace std;//miao 和std 什么关系

namespace miao {
	template<class T, class Container = deque<T>>
	class queue {
	public:
		void push(const T& x)
		{
			_con.push_back(x);//为什么没有语法提示
		}
		void pop()
		{
			_con.pop_front();
		}
		const T& front()
		{
			return _con.front();
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

	// 仿函数/函数对象 -- 对象可以像调用函数一样去使用
	/*struct less
	{
	bool operator()(int x, int y)
	{
	return x < y;
	}
	};*/
	template<class T>
	struct less {
		bool operator()(const T& x,const T& y)
		{
			return x < y;
		}
	};

	template<class T>
	struct greater {
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

	// 优先级队列 -- 大堆 < less  小堆 > greater
	template<class T,class Container=deque<T>,class Compare =less<T>>
	class priority_queue{	
	public:

		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child>0)
			{
				//if (_con[parent] < _con[child])//还没引入仿函数
				if(com(_con[parent],_con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else 
				{
					break;
				}
			}
		}

		
		void push(const T& x)
		{
			_con.push_back(x);

			AdjustUp(_con.size()-1);
		}

		void AdjustDown(int parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			while(child<_con.size())
			{
				//比较左右孩子
				if (child + 1 < _con.size() && _con[child] > _con[child + 1])
				{
					child++;
				}
				//if (_con[child] > _con[parent])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else 
				{
					break;
				}
			}

		}

		void pop()
		{
			assert(!_con.empty());
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			AdjustDown(0);
		}

		const T& top()
		{
			return _con[0];
		}

		bool empty()
		{
			return _con.empty();
		}

		size_t size()
		{
			return _con.size();
		}

	private:
		Container _con;
	};

	void test_priority_queue()
	{
		/*less<int> LessCom;
		cout << LessCom(1, 2) << endl;

		greater<int> GreaterCom;
		cout << GreaterCom(1, 2) << endl;*/

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
}

