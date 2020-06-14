#pragma once

#include<algorithm>
#include<iostream>
using namespace std;



template<class K>
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
public:
	//构造函数不用写，在声明成员时已有缺省值
	BSTree() = default;//此语句表示使用默认的构造，因为下面实现了拷贝构造，编译器检测到了后会提示你实现构造函数
	
	BSTree(const BSTree<K>& bst)//拷贝构造
		:_root(nullptr)
	{
		_root=_copy(bst._root);
	}
	Node* _copy(Node* root)//递归拷贝
	{
		if (!root)
			return nullptr;
		Node* newroot = new Node(root->_key);
		newroot->_left = _copy(root->_left);
		newroot->_right = _copy(root->_right);
		return newroot;
	}

	~BSTree() //析构函数必须要自己写
	{
		_destroy(_root);
	}
	void _destroy(Node* root)//递归释放空间
	{
		if (!root)
			return;
		_destroy(root->_left);
		_destroy(root->_right);
		delete root;
	}
	//搜索二叉树的插入操作
	bool Insert(const K& key) 
	{
		if (_root == nullptr)//一开始没有任何节点
		{
			_root = new Node(key);
			return true;
		}
		//有节点时，需要利用二叉搜索树可以二分查找的特点去找可以插入的点
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key>key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else  //原本已存在
				return false;
		}
		//最终会停在某个满足的节点下，但是要考虑插入到左边还是右边
		if (parent->_key < key)
		{
			parent->_right = new Node(key);
		}
		else
			parent->_left = new Node(key);
		return true;
	}
	//递归插入
	bool _insertR(Node*& cur, const K& key)
	{
		if (cur == nullptr)
		{
			cur = new Node(key);
			return true;
		}
		if (cur->_key < key)
		{
			return _insertR(cur->_right, key);
		}
		else if (cur->_key > key)
			return _insertR(cur->_left, key);
		else
			return false;
	}
	bool InsertR(const K& key)  //因为成员函数有this指针，且由于递归函数参数的限制，
	{
		return _insertR(_root, key);
	}


	//查找操作
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key>key)
			{
				cur = cur->_left;
			}
			else
				return cur;
		}
		return nullptr;
	}
	//递归查找
	Node* _findR(Node*& cur, const K& key)
	{
		if (cur == nullptr)
			return cur;
		if (cur->_key < key)
			return _findR(cur->_right, key);
		else if (cur->_key>key)
			return _findR(cur->_left, key);
		else
			return cur;
	}
	Node* FindR(const K& key)
	{
		return _findR(_root, key);
	}

	//二叉树删除操作
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		//先找到该节点，再根据具体情况，再不破坏二叉搜索树的规则下，删除该节点
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key> key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else //找到了,根据具体情况删除
			{
				//1.没有左节点  将此节点的右树替换上来
				//2.没有右节点  将此节点的左树替换上来
				//3.左右节点都存在   替换法删除  左树的最大节点(最右节点) 或者是右树的最小节点(最左节点)
				//
				if (cur->_left == nullptr) //1
				{
					if (parent == nullptr)//也要先判断是不是根节点
					{
						_root=cur->_right;
					}
					else //不是根节点了 ,就替换到正确的位置去
					{
						if (parent->_left == cur)
							parent->_left = cur->_right;
						else
							parent->_right=cur->_right;
					}
					delete cur;
				}
				else if (cur->_right == nullptr)//2
				{
					if (parent == nullptr)
						_root = cur->_left;
					else
					{
						if (parent->_left == cur)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;
					}
					delete cur;
				}
				else//3 左右都在  替换法删除  左树的最大节点(最右节点) 或者是右树的最小节点(最左节点)
				{
					Node* minparent = cur;
					Node* minNode = cur->_right; //这里是去找右树的最左节点
					while (minNode->_left)
					{
						minparent = minNode;
						minNode = minNode->_left;
					}
					swap(cur->_key, minNode->_key);//替换key值，再将此节点删除

					//但是此被删除的这个最左节点可能还有右子节点，所以不能直接删除，问题退化到上面的只有左节点 或 右节点的情况
					minparent->_left=minNode->_right;

					//否则的话，不用处理，可以直接删除
					delete minNode;
				}
				return true;
			}
		}//此树为空
		return false;
	}

	//递归删除
	bool _eraseR(Node*& cur, const K& key)
	{
		if (cur == nullptr)//递归出口 ，没找到或为空树
			return false;
		//还是先去找要删除的节点
		if (cur->_key < key)
			return _eraseR(cur->_right, key);
		else if (cur->_key> key)
			return _eraseR(cur->_left, key);
		else  //找到后，还是根据三种情况来正确删除   //递归函数的参数里是节点指针的引用，所以不用再定义一个父节点来协助链接了
		{
			Node* del = cur;
			if (cur->_left == nullptr)
			{
				cur = cur->_right;
				delete del;
				return true;
			}
			else if (cur->_right == nullptr)
			{
				cur = cur->_left;
				delete del;
				return true;
			}
			else
			{
				//选择再其右子树中找最左节点
				Node* minNode = cur->_right;
				while (minNode->_left)
				{
					minNode = minNode->_left;
				}
				cur->_key = minNode->_key;//注意是赋值，
				return _eraseR(cur->_right, minNode->_key);//将问题转换（退化）成上面只有左节点或右节点的情况
			}
		}

	}
	bool EraseR(const K& key)
	{
		return _eraseR(_root, key);
	}
	
	void _inorder(Node* cur)
	{
		if (!cur)
			return;
		_inorder(cur->_left);
		cout << cur->_key << ' ';
		_inorder(cur->_right);
	}
	void InOrder()
	{
		_inorder(_root);
		cout << endl;
	}
private:
	Node* _root=nullptr; //缺省值
};

void TestBSTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> bst;
	for (auto e : a)
	{
		//bst.Insert(e);
		bst.InsertR(e);
	}
	bst.InOrder();

	/*bst.Erase(2);
	bst.InOrder();
	bst.Erase(8);
	bst.InOrder();
	bst.Erase(1);
	bst.InOrder();
	bst.Erase(5);
	bst.InOrder();*/
	BSTree<int> bst2(bst);

	bst2.InOrder();


	/*for (auto e : a)
	{
		bst.EraseR(e);
		bst.InOrder();
	}
	bst.InOrder();*/
}
