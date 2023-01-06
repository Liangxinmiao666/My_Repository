#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<iostream>
#include<vector>
#include<queue>
#include<assert.h>
using namespace std;

enum Colour
{
	RED,
	BLACK,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;//数据

	Colour _col;

	RBTreeNode(const T& data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}
};

template<class T,class Ref,class Ptr>
struct __RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __RBTreeIterator<T, Ref, Ptr> Self;
	Node* _node;

	__RBTreeIterator(Node* node)
		:_node(node)
	{}


	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	Self& operator++()
	{
		if (_node->_right == nullptr)
		{
			// 找祖先里面，孩子是父亲左的那个
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_right == cur)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}

			_node = parent;
		}
		else
		{
			// 右子树的最左节点
			Node* subLeft = _node->_right;
			while (subLeft->_left)
			{
				subLeft = subLeft->_left;
			}

			_node = subLeft;
		}

		return *this;
	}

	Self operator++(int)
	{
		Self tmp(*this);

		++(*this);

		return tmp;
	}

	Self& operator--()
	{
		if (_node->_left == nullptr)
		{
			// 找祖先里面，孩子是父亲
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}

			_node = parent;
		}
		else
		{
			// 左子树的最右节点
			Node* subRight = _node->_left;
			while (subRight->_right)
			{
				subRight = subRight->_right;
			}

			_node = subRight;
		}

		return *this;
	}

	Self operator--(int)
	{
		Self tmp(*this);

		--(*this);

		return tmp;
	}
	bool operator!=(const Self& s) const
	{
		return _node != s._node;
	}

	bool operator==(const Self& s) const
	{
		return _node == s->_node;
	}

};


// T决定红黑树存什么数据
// set  RBTree<K, K>
// map  RBTree<K, pair<K, V>>
// KeyOfT -> 支持取出T对象中key的仿函数
template<class K, class T,class KeyOfValue>
struct RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __RBTreeIterator<T, T&, T*> iterator;
	typedef __RBTreeIterator<T, const T&, const T*> const_iterator;


	// 构造 拷贝构造 赋值 和析构 跟搜索树实现方式是一样的

	iterator Begin()
	{
		Node* subLeft = _root;
		while (subLeft && subLeft->_left)
		{
			subLeft = subLeft->_left;
		}

		return iterator(subLeft);
	}

	iterator End()
	{
		return iterator(nullptr);
	}

	const_iterator Begin() const
	{
		Node* subLeft = _root;
		while (subLeft && subLeft->_left)
		{
			subLeft = subLeft->_left;
		}

		return const_iterator(subLeft);
	}

	const_iterator End() const
	{
		return const_iterator(nullptr);
	}

	pair<iterator,bool> Insert(const T& data)
	{
		// 1、搜索树的规则插入
		// 2、看是否违反平衡规则，如果违反就需要处理：旋转
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root),true);
		}

		KeyOfValue kotv;

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kotv(cur->_data) < kotv(data)) //pair支持比较大小
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kotv(cur->_data) > kotv(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}

		cur = new Node(data);
		Node* newnode = cur;
		cur->_col = RED;
		if (parent->_data < data)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		cur->_parent = parent;

		// 存在连续红色节点
		while (parent && parent->_col == RED)
		{
			Node* grandfater = parent->_parent;
			assert(grandfater);

			if (grandfater->_left == parent)
			{
				Node* uncle = grandfater->_right;
				// 情况一：
				if (uncle && uncle->_col == RED) // 叔叔存在且为红
				{
					// 变色
					parent->_col = uncle->_col = BLACK;
					grandfater->_col = RED;

					// 继续往上处理
					cur = grandfater;
					parent = cur->_parent;
				}
				else // 叔叔不存在 或者 叔叔存在且为黑
				{
					if (cur == parent->_left) // 单旋
					{
						//     g
						//   p
						// c
						RotateR(grandfater);
						parent->_col = BLACK;
						grandfater->_col = RED;
					}
					else // 双旋
					{
						//     g
						//   p
						//     c 
						RotateL(parent);
						RotateR(grandfater);
						cur->_col = BLACK;
						grandfater->_col = RED;
					}

					break;
				}
			}
			else //(grandfater->_right == parent)
			{
				Node* uncle = grandfater->_left;
				// 情况一：
				if (uncle && uncle->_col == RED)
				{
					// 变色
					parent->_col = uncle->_col = BLACK;
					grandfater->_col = RED;

					// 继续往上处理
					cur = grandfater;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						// g
						//   p
						//     c 
						RotateL(grandfater);
						parent->_col = BLACK;
						grandfater->_col = RED;
					}
					else // 双旋
					{
						// g
						//   p
						// c
						RotateR(parent);
						RotateL(grandfater);
						cur->_col = BLACK;
						grandfater->_col = RED;
					}

					break;
				}
			}
		}

		_root->_col = BLACK;

		return make_pair(iterator(newnode), true);
	}


	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* ppNode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (parent == ppNode->_left)
			{
				ppNode->_left = subR;
			}
			else
			{
				ppNode->_right = subR;
			}

			subR->_parent = ppNode;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* ppNode = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}
			subL->_parent = ppNode;
		}

	}

	iterator Find(const K& key)
	{
		Node* cur = _root;
		KeyOfValue kot;
		while (cur)
		{
			if (kot(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else if (kot(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else
			{
				return iterator(cur);
			}
		}

		return End();
	}


public:


private:
	Node* _root = nullptr;
};

//void TestRBTree1()
//{
//	//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	int a[] = { 30, 29, 28, 27, 26, 25, 24, 11, 8, 7, 6, 5, 4, 3, 2, 1 };
//	RBTree<int, int> t;
//	for (auto e : a)
//	{
//		t.Insert(e);
//	}
//	t.levelOrder();
//	t.InOrder();
//	t.Height();
//}
//
//void TestRBTree2()
//{
//	const size_t N = 1024 * 1024;
//	vector<int> v;
//	v.reserve(N);
//	srand(time(0));
//	for (size_t i = 0; i < N; ++i)
//	{
//		v.push_back(rand());
//		//v.push_back(i);
//	}
//
//	RBTree<int, int> t;
//	for (auto e : v)
//	{
//		t.Insert(e);
//	}
//
//	//t.levelOrder();
//	//cout << endl;
//	cout << "是否平衡?" << t.IsBalanceTree() << endl;
//	t.Height();
//
//	//t.InOrder();
//}