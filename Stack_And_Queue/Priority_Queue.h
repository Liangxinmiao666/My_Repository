#define _CRT_SECURE_NO_WARNINGS 1
namespace miao {

	// 仿函数/函数对象 -- 对象可以像调用函数一样去使用
		/*struct less
		{
		bool operator()(int x, int y)
		{
		return x < y;
		}
		};*/
	template<class T>
	struct Less {
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template<class T>
	struct Greater {
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};
	//利用函数指针 兼容C语言
	bool ComIntLess(int x1, int x2)
	{
		return x1 > x2;
	}

	// 优先级队列 -- 大堆 < Less  小堆 > Greater
	template<class T, class Container = deque<T>, class Compare = Less<T>>
	class Priority_Queue {
		Compare _comFunc;
	public:
		Priority_Queue(const Compare& comFunc=Compare())
			:_comFunc(comFunc)
		{}
		template <class InputIterator>
		Priority_Queue(InputIterator first, InputIterator last, const Compare& comFunc = Compare())
			:_comFunc(comFunc)
		{
			while (first != last)
			{
				_con.push_back(*first);
				++first;
			}

			// 建堆
			/*for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i)
			{
				AdjustDown(i);
			}*/
			for(int i=_con.size()-1;i>=1;--i)
			{
				AdjustUp(i);
			}
		}

		void AdjustUp(int child)
		{
			//Compare com; 有函数指针 就不用定义对象了
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[parent] < _con[child])//还没引入仿函数  写死了
				//if (com(_con[parent], _con[child]))//仿函数
				if(_comFunc(_con[parent],_con[child]))//函数指针
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

			AdjustUp(_con.size() - 1);
		}

		void AdjustDown(int parent)
		{
			//Compare com;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				//比较左右孩子
				//if (child + 1 < _con.size() && _con[child] > _con[child + 1])//仿函数
				if (child + 1 < _con.size()&&_comFunc(_con[child], _con[child+1]))
				{
					child++;
				}
				//if (_con[child] > _con[parent])//写死了
				//if (com(_con[parent], _con[child]))仿函数
				if(_comFunc(_con[parent],_con[child]))
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

	void test_Priority_Queue()
	{
		/*Less<int> LessCom;
		cout << LessCom(1, 2) << endl;

		Greater<int> GreaterCom;
		cout << GreaterCom(1, 2) << endl;*/

		//Priority_Queue<int> pq;
		//Priority_Queue<int, vector<int>, Greater<int>> pq;
		Priority_Queue<int, vector<int>, bool(*)(int, int)> pq(ComIntLess);
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

	void test_Priority_Queue2()
	{
		int a[] = { 1, 4, 2, 7, 8, 9 };
		Priority_Queue<int> pq(a, a + 6);
	}

}