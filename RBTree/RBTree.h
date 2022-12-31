#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<iostream>
#include<vector>
using namespace std;

enum Colour
{
	RED,
	BLACK,
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;

	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}
};

template<class K, class V>
struct RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		// 1���������Ĺ������
		// 2�����Ƿ�Υ��ƽ��������Υ������Ҫ������ת
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		cur->_parent = parent;

		// ����������ɫ�ڵ�
		while (parent && parent->_col == RED)
		{
			Node* grandfater = parent->_parent;
			assert(grandfater);

			if (grandfater->_left == parent)
			{
				Node* uncle = grandfater->_right;
				// ���һ��
				if (uncle && uncle->_col == RED) // ���������Ϊ��
				{
					// ��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfater->_col = RED;

					// �������ϴ���
					cur = grandfater;
					parent = cur->_parent;
				}
				else // ���岻���� ���� ���������Ϊ��
				{
					if (cur == parent->_left) // ����
					{
						//     g
						//   p
						// c
						RotateR(grandfater);
						parent->_col = BLACK;
						grandfater->_col = RED;
					}
					else // ˫��
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
				// ���һ��
				if (uncle && uncle->_col == RED)
				{
					// ��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfater->_col = RED;

					// �������ϴ���
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
					else // ˫��
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

		return true;
	}

	vector<vector<int>> levelOrder() {
		vector<vector<int>> vv;
		if (_root == nullptr)
			return vv;

		queue<Node*> q;
		int levelSize = 1;
		q.push(_root);

		while (!q.empty())
		{
			// levelSize����һ��һ���
			vector<int> levelV;
			while (levelSize--)
			{
				Node* front = q.front();
				q.pop();
				levelV.push_back(front->_kv.first);
				if (front->_left)
					q.push(front->_left);

				if (front->_right)
					q.push(front->_right);
			}
			vv.push_back(levelV);
			for (auto e : levelV)
			{
				cout << e << " ";
			}
			cout << endl;

			// ��һ����꣬��һ��Ͷ�������
			levelSize = q.size();
		}

		return vv;
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

	int _maxHeight(Node* root)
	{
		if (root == nullptr)
			return 0;

		int lh = _maxHeight(root->_left);
		int rh = _maxHeight(root->_right);

		return lh > rh ? lh + 1 : rh + 1;
	}

	int _minHeight(Node* root)
	{
		if (root == nullptr)
			return 0;

		int lh = _minHeight(root->_left);
		int rh = _minHeight(root->_right);

		return lh < rh ? lh + 1 : rh + 1;
	}


	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	bool _IsValidRBTree(Node* pRoot, size_t k, const size_t blackCount)
	{
		//�ߵ�null֮���ж�k��black�Ƿ����
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
				return false;
			}
			return true;
		}

		// ͳ�ƺ�ɫ�ڵ�ĸ���
		if (BLACK == pRoot->_col)
			k++;

		// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
		if (RED == pRoot->_col && pRoot->_parent && pRoot->_parent->_col == RED)
		{
			cout << "Υ������������������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		return _IsValidRBTree(pRoot->_left, k, blackCount) &&
			_IsValidRBTree(pRoot->_right, k, blackCount);
	}

public:

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void Height()
	{
		cout << "�·��:" << _maxHeight(_root) << endl;
		cout << "���·��:" << _minHeight(_root) << endl;
	}


	bool IsBalanceTree()
	{
		// ���������������

		Node* pRoot = _root;
		// ����Ҳ�Ǻ����
		if (nullptr == pRoot)
			return true;

		// �����ڵ��Ƿ��������
		if (BLACK != pRoot->_col)
		{
			cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
			return false;
		}

		// ��ȡ����һ��·���к�ɫ�ڵ�ĸ��� -- �Ƚϻ�׼ֵ
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_col)
				blackCount++;

			pCur = pCur->_left;
		}

		// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

private:
	Node* _root = nullptr;
};

void TestRBTree1()
{
	//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int a[] = { 30, 29, 28, 27, 26, 25, 24, 11, 8, 7, 6, 5, 4, 3, 2, 1 };
	RBTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
	t.levelOrder();
	t.InOrder();
	t.Height();
}

void TestRBTree2()
{
	const size_t N = 1024 * 1024;
	vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(rand());
		//v.push_back(i);
	}

	RBTree<int, int> t;
	for (auto e : v)
	{
		t.Insert(make_pair(e, e));
	}

	//t.levelOrder();
	//cout << endl;
	cout << "�Ƿ�ƽ��?" << t.IsBalanceTree() << endl;
	t.Height();

	//t.InOrder();
}