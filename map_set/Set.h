#define _CRT_SECURE_NO_WARNINGS 1
#include"RBTree.h"

namespace miao
{
	template<class K>
	class set {
	public:
		struct SetKeyOfValue
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

		typedef typename RBTree<K, K, SetKeyOfValue>::const_iterator iterator;//如何改的
		typedef typename RBTree<K, K, SetKeyOfValue>::const_iterator const_iterator;

		iterator begin() const //this是const _t.Begin() 调用的就是const_iteraotr的Begin() 就匹配了
		{
			return _t.Begin();
		}

		iterator end() const
		{
			return _t.End();
		}

		pair<iterator,bool> insert(const K& key)
		{
			//pair<typename RBTree<K, K, SetKeyOfT>::iterator, bool> ret = _t.Insert(key);
				auto ret = _t.Insert(key);
			return pair<iterator, bool>(iterator(ret.first._node), ret.second); //构造了一个const_iterator来匹配
		}

		iterator find(const K& key)
		{
			return _t.Find(key);
		}
	private:
		RBTree <K,K,SetKeyOfValue> _t;
	};


	void test_my_set1()
	{
		miao::set<int> s;
		s.insert(1);
		s.insert(2);
		s.insert(3);
		s.insert(4);
		s.insert(5);

	}

	void test_my_set2()
	{
		set<int> s;
		s.insert(8);
		s.insert(6);
		s.insert(11);
		s.insert(5);
		s.insert(6);
		s.insert(7);
		s.insert(10);
		s.insert(13);
		s.insert(12);
		s.insert(15);

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : s)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}

