#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
namespace miao {

	//template<class Iterator, class Ref, class Ptr>
	//struct Reverse_iterator {
	//	Iterator _it;
	//	typedef Reverse_iterator<Iterator, Ref, Ptr> Self;

	//	Reverse_iterator(Iterator it)
	//		:_it(it)
	//	{}

	//	Ref operator* ()
	//	{
	//		Iterator tmp = _it;
	//		return *(--tmp);
	//	}
	//	Ptr operator->()
	//	{
	//		return &(operator*());
	//	}
	//	Self operator++()
	//	{
	//		--_it;
	//		return *this;
	//	}
	//	Self operator--()
	//	{
	//		++_it;
	//		return *this;
	//	}
	//	bool operator!=(const Self& s)
	//	{
	//		return _it != s._it;
	//	}
	//};

	template<class Iterator>
	struct Reverse_iterator {
		Iterator _it;
		//typedef Reverse_iterator<Iterator, Ref, Ptr> Self;
		typedef Reverse_iterator<Iterator> Self;

		Reverse_iterator(Iterator it)
			:_it(it)
		{}
		
		typename Iterator::reference operator* ()
		{
			Iterator tmp = _it;
			return *(--tmp);
		}
		typename Iterator::pointer operator->()
		{
			return &(operator*());
		}
		Self operator++()
		{
			--_it;
			return *this;
		}
		Self operator--()
		{
			++_it;
			return *this;
		}
		bool operator!=(const Self& s)
		{
			return _it != s._it;
		}
	};
}