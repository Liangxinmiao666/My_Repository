#define _CRT_SECURE_NO_WARNINGS 1
#include"RBTree.h"

namespace miao
{
	template<class K,class V>
	class map 
	{
	public:
		struct MapKeyOfValue
		{
			const K& operator()(const pair<K,V>& kv)
			{
				return kv.first;
			}
		};
		typedef typename RBTree<K, pair<K,V>, MapKeyOfValue>::iterator iterator;
		typedef typename RBTree<K, pair<K,V>, MapKeyOfValue>::const_iterator const_iterator;

		iterator begin()
		{
			return _t.Begin();
		}

		iterator end() 
		{
			return _t.End();
		}

		pair<iterator,bool> insert(const pair<K,V>& kv)
		{
			return _t.Insert(kv);
		}
		iterator find(const K& key)
		{
			return _t.Find(key);
		}
		V& operator[](const K& key)
		{
			pair<iterator,bool> ret=insert(make_pair(key,V()));
			return ret.first->second;
		}
	private:
		RBTree <K, pair<K, V>,MapKeyOfValue> _t;
	};

	void test_my_map1()
	{
		miao::map<string, int> s;
		s.insert(make_pair("11", 1));
		s.insert(make_pair("22", 2));
		s.insert(make_pair("33", 3));
		s.insert(make_pair("44", 4));

		map<string, int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;

		for (auto& kv : s)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
		cout << endl;
	}

	void test_my_map2()
	{
		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };

		map<string, int> countmap;
		for (auto& str : arr)
		{
			map<string, int>::iterator it = countmap.find(str);
			if (it != countmap.end())
			{
				it->second++;
			}
			else
			{
				countmap.insert(make_pair(str, 1));
			}
		}
			map<string, int> countMap;
			for (auto& str : arr)
			{
				countMap[str]++;
			}
			for (const auto& kv : countMap)
			{
				cout << kv.first << ":" << kv.second << endl;
			}
	}

	void test_my_map3()
	{
		map<string, string> dict;
		dict["insert"];
		dict["insert"] = "插入";
		dict["left"] = "左边";

	}
}