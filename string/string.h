#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

namespace bit
{
	class string {
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			,_capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(string& s) 
			:_size(strlen(s._str))
			,_capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		~string()
		{
			if (_str)
			{
				_size = _capacity = 0;
				delete[] _str;
				_str = nullptr;
			}
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const 
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		char& operator[](int pos) 
		{
			assert(pos <= this->_size);
			return _str[pos];
		}

		const char& operator[](int pos) const
		{
			assert(pos <= this->_size);
			return _str[pos];
		}

		string& operator=(string& s)
		{
			/*delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
			return *this;*/
			if (this != &s)
			{
				char* tmp = new char[strlen(s._str) + 1];
				delete[] _str;
				_str = tmp;
				strcpy(_str, s._str);
			}
			return *this;
		}

		void reserve(int n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, this->_str);
				delete[] _str;
				_str = tmp;
			}
		}

		void push_back(char c)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity*2);
				//reserve(_capacity*2); //有可能是空字符串 
			}
			_str[_size] = c;
			_size++;
			_str[_size] = '\0';
		}

		void append(char* ch)
		{
			size_t len = strlen(ch) + _size;
			if (len > _capacity)
				reserve(len);

			strcpy(_str + _size, ch);
			_size = len;
		}

		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}

		string& operator+=(char* ch)
		{
			append(ch);
			return *this;
		}

		void resize(size_t n,char c='\0')
		{
			if (n < _size)
			{
				_size = n;
				_str[n] = '\0';
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = c;
				}
				_size = n;
				_str[_size] = '\0';

			}
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			/*	int end = _size;
				while (end >= (int)pos)
				{
					_str[end + 1] = _str[end];
					--end;
				}*/

			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}

			_str[pos] = ch;
			_size++;

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			/*if (len == 0)
			{
				return *this;
			}*/

			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			// 往后挪动len个位置
			size_t end = _size + len;
			while (end > pos + len - 1)
				//while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				--end;
			}

			strncpy(_str + pos, str, len);
			_size += len;

			return *this;
		}

		void erase(size_t pos,size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || len + pos >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t begin = pos + len;
				while (begin <= _size)
				{
					_str[begin - len] = _str[begin];
					begin++;
				}
				_size -= len;
			}
		}

		size_t find(const char* str,size_t pos = 0)
		{
			const char* p = strstr(_str+pos, str);
			if (pos == npos)
			{
				return npos;
			}
			else
				return p - _str;
		}

		size_t find(const char c, size_t pos = 0)
		{
			for (; pos < _size; pos++)
			{
				if (_str[pos] == c)
					return pos;
			}
				return npos;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
	private:
		size_t _size;
		size_t _capacity;
		char* _str;

		const static size_t npos ;
	};

	const size_t bit::string::npos = -1;

	bool operator<(string& s1, string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}

	bool operator==(string& s1, string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}

	bool operator<=(string& s1, string& s2)
	{
		return s1 < s2 || s1 == s2;
	}

	bool operator>(string& s1, string& s2)
	{
		return !(s1<=s2);
	}

	bool operator>=(string& s1, string& s2)
	{
		return s1>s2||s1==s2;
	}
	bool operator!=(string& s1, string& s2)
	{
		return !(s1 == s2);
	}
	istream& operator>>(istream& in, string& s)
	{
		//char ch;
		////in >> ch;
		//ch = in.get();
		//while (ch != ' ' && ch != '\n')
		//{
		//	s += ch;
		//	//in >> ch;
		//	ch = in.get();
		//}

		//return in;

		char ch;
		ch = in.get();
		char buff[128] = { '\0' };
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				s += buff;
				memset(buff, '\0', 128);
				i = 0;
			}

			ch = in.get();
		}

		s += buff;
		return in;
	}

	ostream& operator<<(ostream& out ,const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}
}