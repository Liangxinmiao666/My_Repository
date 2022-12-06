#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<string>
namespace key {

	template<class K>
	//struct BinarySearchTreeNode
	struct BSTreeNode
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;

		K _key;

		BSTreeNode(const K& key)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}
	};

	template<class K>
	class BSTree
	{
		typedef BSTreeNode<K> Node;
	private:
		void DestoryTree(Node* root)
		{
			if (root == nullptr)
				return;

			DestoryTree(root->_left);
			DestoryTree(root->_right);
			delete root;
		}

		Node* CopyTree(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* copyNode = new Node(root->_key);
			copyNode->_left = CopyTree(root->_left);
			copyNode->_right = CopyTree(root->_right);

			return copyNode;
		}
	public:
		// 强制编译器自己生成构造
		// C++11
		BSTree() = default;

		BSTree(const BSTree<K>& t)
		{
			_root = CopyTree(t._root);
		}

		// t1 = t2
		BSTree<K>& operator=(BSTree<K> t)
		{
			swap(_root, t._root);
			return *this;
		}

		~BSTree()
		{
			DestoryTree(_root);
			_root = nullptr;
		}

		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			return true;
		}

		//const Node* Find(const K& key)
		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return true;
				}
			}

			return false;
		}
		//重要
		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// 一个孩子--左为空 or 右为空
					// 两个孩子 -- 替换法
					if (cur->_left == nullptr)
					{
						//if (parent == nullptr)
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						//if (parent == nullptr)
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}

						delete cur;
					}
					else // 两个孩子都不为空
					{
						//// 右子树的最小节点替代
						//Node* minParent = cur;//不能是nullptr 万一删除8 没进入下方的循环 minParent 就会是空值
						//Node* minRight = cur->_right;
						//while (minRight->_left)
						//{
						//	minParent = minRight;
						//	minRight = minRight->_left;
						//}

						//swap(minRight->_key, cur->_key);
						////cur->_key = minRight->_key;
						//if (minParent->_left == minRight)
						//{
						//	minParent->_left = minRight->_right;
						//}
						//else
						//{
						//	minParent->_right = minRight->_right;
						//}

						//delete minRight;

						//左子树最大节点
						Node* maxLeft = cur->_left;
						Node* maxParent = cur;//不能是nullptr 万一删除6 没进入下方的循环 maxParent 就会是空值
						while (maxLeft->_right)
						{
							maxParent = maxLeft;
							maxLeft = maxLeft->_right;
						}
						swap(maxLeft->_key, cur->_key);
						if (maxParent->_right == maxLeft)
						{
							maxParent->_right = maxLeft->_left;
						}
						else
						{
							maxParent->_left = maxLeft->_left;
						}
						delete maxLeft;

					}

					return true;
				}
			}

			return false;
		}


		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		void PreOrder()
		{
			_PreOrder(_root);
			cout << endl;
		}

		void PostOrder()
		{
			_PostOrder(_root);
			cout << endl;
		}

		bool FindR(const K& key)
		{
			return _FindR();
		}

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}
	private:
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}

		void _PreOrder(Node* root)
		{
			if (root == nullptr)
				return;

			cout << root->_key << " ";
			_PreOrder(root->_left);
			_InOrder(root->_right);
		}

		void PostOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_PreOrder(root->_left);
			_InOrder(root->_right);
			cout << root->_key << " ";
		}

		bool _FindR(Node*& root, const K& key) //为什么要用引用
		{
			if (root == nullptr)
				return false;

			if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else
			{
				return true;
			}
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (root->_key < key)
				return _InsertR(root->_right, key);
			else if (root->_key > key)
				return _InsertR(root->_left, key);
			else
				return false;
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else
			{
				Node* del = root;
				// 删除
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else
				{
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}

					swap(root->_key, minRight->_key);

					return _EraseR(root->_right, key);
				}

				delete del;
				return true;
			}
		}
	private:
		Node* _root = nullptr;
	};

	void TestBSTree()
	{
		BSTree<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (auto e : a)
		{
			t.Insert(e);
		}
		t.InOrder();

		t.Insert(16);
		t.Insert(9);
		t.Erase(14);
		t.Erase(3);

		t.InOrder();
	}
}


namespace key_value {
	template<class K,class V>
	//struct BinarySearchTreeNode
	struct BSTreeNode
	{
		BSTreeNode<K,V>* _left;
		BSTreeNode<K,V>* _right;
		
		//防止用Find()的返回值Node* 来改_key 
		//K _key;
		const K _key;
		V _value;

		BSTreeNode(const K& key,const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			,_value(value)
		{}
	};

	template<class K,class V>
	class BSTree
	{
		typedef BSTreeNode<K,V> Node;
	private:
		void DestoryTree(Node* root)
		{
			if (root == nullptr)
				return;

			DestoryTree(root->_left);
			DestoryTree(root->_right);
			delete root;
		}

		Node* CopyTree(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* copyNode = new Node(root->_key,root->_value);
			copyNode->_left = CopyTree(root->_left);
			copyNode->_right = CopyTree(root->_right);

			return copyNode;
		}
	public:
		// 强制编译器自己生成构造
		// C++11
		BSTree() = default;

		BSTree(const BSTree<K,V>& t)
		{
			_root = CopyTree(t._root);
		}

		// t1 = t2
		BSTree<K,V>& operator=(BSTree<K,V> t)
		{
			swap(_root, t._root);
			return *this;
		}

		~BSTree()
		{
			DestoryTree(_root);
			_root = nullptr;
		}

	//	bool Insert(const K& key)
	//	{
	//		if (_root == nullptr)
	//		{
	//			_root = new Node(key);
	//			return true;
	//		}
	//		Node* parent = nullptr;
	//		Node* cur = _root;
	//		while (cur)
	//		{
	//			if (cur->_key < key)
	//			{
	//				parent = cur;
	//				cur = cur->_right;
	//			}
	//			else if (cur->_key > key)
	//			{
	//				parent = cur;
	//				cur = cur->_left;
	//			}
	//			else
	//			{
	//				return false;
	//			}
	//		}

	//		cur = new Node(key);
	//		if (parent->_key < key)
	//		{
	//			parent->_right = cur;
	//		}
	//		else
	//		{
	//			parent->_left = cur;
	//		}

	//		return true;
	//	}

	//	//const Node* Find(const K& key)
	//	bool Find(const K& key)
	//	{
	//		Node* cur = _root;
	//		while (cur)
	//		{
	//			if (cur->_key < key)
	//			{
	//				cur = cur->_right;
	//			}
	//			else if (cur->_key > key)
	//			{
	//				cur = cur->_left;
	//			}
	//			else
	//			{
	//				return true;
	//			}
	//		}

	//		return false;
	//	}
	//	//重要
	//	bool Erase(const K& key)
	//	{
	//		Node* parent = nullptr;
	//		Node* cur = _root;
	//		while (cur)
	//		{
	//			if (cur->_key < key)
	//			{
	//				parent = cur;
	//				cur = cur->_right;
	//			}
	//			else if (cur->_key > key)
	//			{
	//				parent = cur;
	//				cur = cur->_left;
	//			}
	//			else
	//			{
	//				// 一个孩子--左为空 or 右为空
	//				// 两个孩子 -- 替换法
	//				if (cur->_left == nullptr)
	//				{
	//					//if (parent == nullptr)
	//					if (cur == _root)
	//					{
	//						_root = cur->_right;
	//					}
	//					else
	//					{
	//						if (cur == parent->_left)
	//						{
	//							parent->_left = cur->_right;
	//						}
	//						else
	//						{
	//							parent->_right = cur->_right;
	//						}
	//					}
	//					delete cur;
	//				}
	//				else if (cur->_right == nullptr)
	//				{
	//					//if (parent == nullptr)
	//					if (cur == _root)
	//					{
	//						_root = cur->_left;
	//					}
	//					else
	//					{
	//						if (cur == parent->_left)
	//						{
	//							parent->_left = cur->_left;
	//						}
	//						else
	//						{
	//							parent->_right = cur->_left;
	//						}
	//					}

	//					delete cur;
	//				}
	//				else // 两个孩子都不为空
	//				{
	//					//// 右子树的最小节点替代
	//					//Node* minParent = cur;//不能是nullptr 万一删除8 没进入下方的循环 minParent 就会是空值
	//					//Node* minRight = cur->_right;
	//					//while (minRight->_left)
	//					//{
	//					//	minParent = minRight;
	//					//	minRight = minRight->_left;
	//					//}

	//					//swap(minRight->_key, cur->_key);
	//					////cur->_key = minRight->_key;
	//					//if (minParent->_left == minRight)
	//					//{
	//					//	minParent->_left = minRight->_right;
	//					//}
	//					//else
	//					//{
	//					//	minParent->_right = minRight->_right;
	//					//}

	//					//delete minRight;

	//					//左子树最大节点
	//					Node* maxLeft = cur->_left;
	//					Node* maxParent = cur;//不能是nullptr 万一删除6 没进入下方的循环 maxParent 就会是空值
	//					while (maxLeft->_right)
	//					{
	//						maxParent = maxLeft;
	//						maxLeft = maxLeft->_right;
	//					}
	//					swap(maxLeft->_key, cur->_key);
	//					if (maxParent->_right == maxLeft)
	//					{
	//						maxParent->_right = maxLeft->_left;
	//					}
	//					else
	//					{
	//						maxParent->_left = maxLeft->_left;
	//					}
	//					delete maxLeft;

	//				}

	//				return true;
	//			}
	//		}

	//		return false;
	//	}

public:
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		//void PreOrder()
		//{
		//	_PreOrder(_root);
		//	cout << endl;
		//}

		//void PostOrder()
		//{
		//	_PostOrder(_root);
		//	cout << endl;
		//}

		Node* FindR(const K& key)
		{
			return _FindR(_root,key);
		}

		bool InsertR(const K& key,const V& value)
		{
			return _InsertR(_root, key,value);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}
	private:
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_key << " "<<root->_value;
			_InOrder(root->_right);
		}

		//void _PreOrder(Node* root)
		//{
		//	if (root == nullptr)
		//		return;

		//	cout << root->_key << " ";
		//	_PreOrder(root->_left);
		//	_InOrder(root->_right);
		//}

		//void PostOrder(Node* root)
		//{
		//	if (root == nullptr)
		//		return;

		//	_PreOrder(root->_left);
		//	_InOrder(root->_right);
		//	cout << root->_key << " ";
		//}

		//可以进行更改value
		Node* _FindR(Node* root, const K& key) //这里的const只能保证在函数内 不修改key
		{
			if (root == nullptr)
				return nullptr;

			if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else
			{
				return root;
			}
		}
		             //为什么要用引用(相当于二级指针) 否则连接不上
		bool _InsertR(Node*& root, const K& key,const V& value)
		{
			if (root == nullptr)
			{
				root = new Node(key,value);
				return true;
			}

			if (root->_key < key)
				return _InsertR(root->_right, key,value);
			else if (root->_key > key)
				return _InsertR(root->_left, key,value);
			else
				return false;
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else
			{
				Node* del = root;
				// 删除
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else
				{
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}

					swap(root->_key, minRight->_key);

					return _EraseR(root->_right, key);
				}

				delete del;
				return true;
			}
		}
	private:
		Node* _root = nullptr;
	};

	/*void TestBSTree()
	{
		BSTree<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (auto e : a)
		{
			t.Insert(e);
		}
		t.InOrder();

		t.Insert(16);
		t.Insert(9);
		t.Erase(14);
		t.Erase(3);

		t.InOrder();
	}*/
	void TestBSTree1()
	{
		BSTree<string, string> ETCDictionary;
		ETCDictionary.InsertR("root","根");
		ETCDictionary.InsertR("string", "字符串");
		ETCDictionary.InsertR("left", "左边");
		ETCDictionary.InsertR("right", "右边");

		string str;
		while (cin >> str)//while(scanf()!=EOF)
		{
			auto ret = ETCDictionary.FindR(str);
			if (ret != nullptr)
			{
				cout << "对应的中文：" << ret->_key << endl;
				//ret->_key = " ";
				//ret->_value = " ";
			}
		}
	}
	void TestBSTree2()
	{
		string arr[] = { "苹果", "西瓜","香蕉","西瓜","苹果" };
		//水果出现的次数
		BSTree<string, int> countTree;
		for (const auto& str : arr)
		{
			auto ret = countTree.FindR(str);
			if (ret == nullptr)
			{
				countTree.InsertR(str, 1);
			}
			else
			{
				ret->_value++;
			}
		}
		countTree.InOrder();
	}	
}