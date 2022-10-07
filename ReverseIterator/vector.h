#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<assert.h>
#include"ReverseIterator.h"
//ģ��ʵ��
namespace miao 
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		// �������������֧��
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			,_endofstoage(nullptr)
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
		vector(int  n, const T& val = T())
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
		void swap(vector<T>& x)
		{
			std::swap(_start, x._start);
			std::swap(_finish, x._finish);
			std::swap(_endofstoage, x._endofstoage);

		}

		vector(const vector<T>& x)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{
			vector<T> tmp(x.begin(), x.end());
			swap(tmp);
		}

		vector<T> & operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstoage = nullptr;

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

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin);
		}

		const_reverse_iterator rbegin() const
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rend() const
		{
			return reverse_iterator(begin());
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
				T* tmp = new T[n];//newʧ���� Ҳ������ ��Ϊnewʧ�������쳣
				if (_start)//
				{
					//memcpy(tmp, _start, n * sizeof(T));
					//�漰��Դ���� �ᵼ���ظ�����
					for (size_t i = 0; i < size(); ++i)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				//_finish=_start+size(); _finish����0x00000000 
				//��Ϊsize() ��ʵ���� retrun _finish - _start; _startһ�ı� size()Ҳ���Ÿ�
				_finish = _start + sz;
				_endofstoage = _start + n;
			}
			

		}

		//void resize(size_t n,const T&=T())
		void resize(size_t n,T val=T())
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
				_finish = _start + n;
		}

		void push_back(const T& x)
		{
			////if(capacity()==size())
			//if (_finish == _endofstoage)
			//{
			//	size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
			//	reserve(newCapacity);
			//}
			//*_finish = x;
			//_finish++;
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

		iterator insert(iterator pos,const T& x)
		{
			//���Ϸ���
			assert(pos >= _start && pos <= _finish);

			//�ռ䲻�� ����
			if (_finish == _endofstoage)
			{
				size_t n = pos - _start;
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);//_start _finish  ���Ѿ����� pos��ָ��ɿռ�
				pos = _start + n;
			}

			//Ų������
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
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
				it++;
			}

			_finish--;

			return pos;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstoage;

	};


	class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> vv;
			vv.resize(numRows);
			for (size_t i = 0; i < vv.size(); ++i)
			{
				// ������ǣ�ÿ�и������ε���
				vv[i].resize(i + 1, 0);

				// ��һ�������һ����ʼ����1
				vv[i][0] = 1;
				vv[i][vv[i].size() - 1] = 1;
			}

			for (size_t i = 0; i < vv.size(); ++i)
			{
				for (size_t j = 0; j < vv[i].size(); ++j)
				{
					if (vv[i][j] == 0)
					{
						// �м�λ�õ�����һ��j-1 �� j�����
						vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
					}
				}
			}

			for (size_t i = 0; i < vv.size(); ++i)//�������ּ���һ�ߴ�ӡ ��Ϊ�˿� ��return vv;ǰ ������ ����֮��������
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

}