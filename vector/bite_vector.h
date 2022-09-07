#pragma once
#include <assert.h>

// 模拟实现 -- 加深对这个容器理解，不是为了造更好的轮子
namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(size_t n, const T& val = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		vector(int n, const T& val = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{
			reserve(n);
			for (int i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstoage, v._endofstoage);
		}

		// 休息11：37继续
		//vector(const vector& v);
		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		//vector& operator=(vector v)
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		// 资源管理
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstoage = nullptr;
			}
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstoage - _start;
		}

		void reserve(size_t n)
		{
			size_t sz = size();
			if (n > capacity())
			{
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, size()*sizeof(T));
					for (size_t i = 0; i < size(); ++i)
					{
						tmp[i] = _start[i];
					}

					delete[] _start;
				}

				_start = tmp;
			}

			_finish = _start + sz;
			_endofstoage = _start + n;
		}

		//void resize(size_t n, const T& val = T())
		void resize(size_t n, T val = T())
		{
			if (n > capacity())
			{
				reserve(n);
			}

			if (n > size())
			{
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				_finish = _start + n;
			}
		}

		void push_back(const T& x)
		{
			/*if (_finish == _endofstoage)
			{
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}

			*_finish = x;
			++_finish;*/

			insert(end(), x);
		}

		void pop_back()
		{
			/*if (_finish > _start)
			{
				--_finish;
			}*/
			erase(end() - 1);
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

		iterator insert(iterator pos, const T& x)
		{
			// 检查参数
			assert(pos >= _start && pos <= _finish);

			// 扩容
			// 扩容以后pos就失效了,需要更新一下
			if (_finish == _endofstoage)
			{
				size_t n = pos - _start;

				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);

				pos = _start + n;
			}

			// 挪动数据
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finish;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}

			--_finish;

			return pos;
		}

		void clear()
		{
			_finish = _start;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstoage;
	};

	//template<class T>
	//vector<T>::vector(const vector& v)
	//	: _start(nullptr)
	//	, _finish(nullptr)
	//	, _endofstoage(nullptr)
	//{
	//	vector tmp(v.begin(), v.end());
	//	swap(tmp);
	//}

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		v.pop_back();
		v.pop_back();
		v.pop_back();

		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		// C++中内置类型也可以认为有构造函数 析构函数
		// 这样才能更好支持模板
		// void resize(size_t n, T val = T())
		int i = 0;
		int j = int();
		int k = int(1);
	}

	void test_vector2()
	{
		/*vector<int> v;
		v.resize(10, -1);

		for (auto e : v)
		{
		cout << e << " ";
		}
		cout << endl;*/
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		//v.push_back(5);

		v.insert(v.begin(), 0);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}


	void test_vector3()
	{
		// 在所有的偶数的前面插入2
		vector<int> v;
		//v.reserve(10);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.insert(it, 20);
				++it;
			}

			++it;
		}

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector4()
	{
		vector<int> v;
		//v.reserve(10);
		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);
		v.push_back(5);
		cout << v.size() << ":" << v.capacity() << endl;
		auto pos = find(v.begin(), v.end(), 4);
		if (pos != v.end())
		{
			v.erase(pos);
		}

		cout << *pos << endl;
		*pos = 10;
		cout << *pos << endl << endl;

		cout << v.size() << ":" << v.capacity() << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector5()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		vector<int> v1(v.begin(), v.end());
		std::string s("hello");
		vector<int> v2(s.begin(), s.end());

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v3(v);
		for (auto e : v3)
		{
			cout << e << " ";
		}
		cout << endl;

		v1 = v2;
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector6()
	{
		// 排除法
		vector<int> v1(10, 2);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<char> v2(10, 'x');
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> vv;
			vv.resize(numRows);
			for (size_t i = 0; i < vv.size(); ++i)
			{
				// 杨辉三角，每行个数依次递增
				vv[i].resize(i + 1, 0);

				// 第一个和最后一个初始化成1
				vv[i][0] = 1;
				vv[i][vv[i].size() - 1] = 1;
			}

			for (size_t i = 0; i < vv.size(); ++i)
			{
				for (size_t j = 0; j < vv[i].size(); ++j)
				{
					if (vv[i][j] == 0)
					{
						// 中间位置等于上一行j-1 和 j个相加
						vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
					}
				}
			}

			for (size_t i = 0; i < vv.size(); ++i)//在里面又加了一边打印 是为了看 是return vv;前 有问题 还是之后有问题
			{
				for (size_t j = 0; j < vv[i].size(); ++j)
				{
					cout << vv[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;

			return vv;
		}
	};

	void test_vector7()
	{
		vector<vector<int>> ret = Solution().generate(5);

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
}