#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
namespace miao {

	template<class T>
	struct list_node {//���
		list_node<T>* _prev;
		list_node<T>* _next;
		T _data;

		list_node(const T& val=T())
			:_prev(nullptr)
			,_next(nullptr)
			,_data(val)//���ﲻ����0
		{}
	};

	template<class T,class Ref,class Ptr>
	struct __list_iterator {

		typedef list_node<T> Node;
		typedef __list_iterator<T,Ref,Ptr> self;

		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		//��д�������� Ĭ�����ɵ�����������_node,����list_node���������������ʲô��Ҳ����
		//Ҳ����д��������͸�ֵ --- ����Ҫ���,���Ҽ�Ȼ��������������ǳ�����㹻�ˡ�

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &(_node->_data);
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		self operator++(int)
		{
			self tmp = *this;
			_node = _node->_next;
			return tmp;
		}
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp(*this);
			_node = _node->prev;
			return *this;
		}
		bool operator==(const self& it)
		{
			return _node == it._node;
		}	
		bool operator!=(const self& it)
		{
			return _node == it._node;
		}
	};

	template<class T>
	class list {
		typedef list_node<T> Node;
		//typedef __list_iterator<T> iterator;

	public:
		typedef __list_iterator<T, T& , T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		const_iterator begin() const
		{
			return const_iterator(_head->_next);//����ҿ�
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}
		iterator begin()
		{
			return iterator(_head->_next);
			//return _head->_next; ��������������ʽ����ת��
		}

		iterator end()
		{
			return iterator(_head);//����ҿ�
		}

		list()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}

		//�������� 
		//��ͳд��
		//list(const list<T>& l)
		//{
		//	_head = new Node();
		//	_head->_next = _head;
		//	_head->_prev = _head;

		//	for (auto e : l)
		//	{
		//		push_back(e);
		//	}
		//}
		void empty_init()
		{
			_head = new Node();
			_head->_prev = _head;
			_head->_next = _head;
		}
		template <class InputInterator>
		list(InputInterator first,InputInterator end)
		{
			empty_init();
			
			while (first != end)2
			{
				push_back(*first);
				first++;
			}
		}
		
		void swap()
		{
			std::swap(_head, lt._head);
		}

		//�ִ�д��
		list(const list<T>& l)
		{
			empty_init();
			list tmp=list(l.begin(), l.end());
			swap(tmp);
		}
		
		list<T>& operator=(list<T>& l)
		{
			swap(l);
			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it!=end())
			{
				it = erase(it);
			}
		}

		void push_back(const T& x)
		{
			//Node* tail = _head->_prev;
			//Node* newnode = new Node(x);

			////_head  tail newnode
			//newnode->_prev = tail;
			//newnode->_next = _head;
			//tail->_next = newnode;
			//_head->_prev = newnode;
			insert(end(), x);
		}
		
		void push_front(const T& x)
		{
			insert(begin(),x);
		}

		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		
		//����posλ��֮ǰ
		iterator insert(iterator pos,const T&x)
		{
			Node* newnode = new Node(x);
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			// prev newnode cur 
			newnode->_prev = prev;
			newnode->_next = cur;
			prev->_next = newnode;
			cur->_prev = newnode;

			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = cur;
			next->_prev = cur;
			delete cur;
			 
			return iterator(next);
		}
	

	private:
		Node* _head;
	};

	struct AA
	{
		AA(int a1 = 0, int a2 = 0)
			:_a1(a1)
			, _a2(a2)
		{}

		int _a1;
		int _a2;
	};

	void test_list2()
	{
		list<AA> lt;
		lt.push_back(AA(1, 1));
		lt.push_back(AA(2, 2));
		lt.push_back(AA(3, 3));
		lt.push_back(AA(4, 4));

		// ������ģ�����ָ����Ϊ
		// int* it  *it
		// AA*  it  *it  it->
		list<AA>:: iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << (*it)._a1 << "-"<< (*it)._a2 <<" ";
			cout << it->_a1 << "-" << it->_a2 << " ";
			++it;
		}
		cout << endl;
	}





}