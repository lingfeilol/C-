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
	//���캯������д����������Աʱ����ȱʡֵ
	BSTree() = default;//������ʾʹ��Ĭ�ϵĹ��죬��Ϊ����ʵ���˿������죬��������⵽�˺����ʾ��ʵ�ֹ��캯��
	
	BSTree(const BSTree<K>& bst)//��������
		:_root(nullptr)
	{
		_root=_copy(bst._root);
	}
	Node* _copy(Node* root)//�ݹ鿽��
	{
		if (!root)
			return nullptr;
		Node* newroot = new Node(root->_key);
		newroot->_left = _copy(root->_left);
		newroot->_right = _copy(root->_right);
		return newroot;
	}

	~BSTree() //������������Ҫ�Լ�д
	{
		_destroy(_root);
	}
	void _destroy(Node* root)//�ݹ��ͷſռ�
	{
		if (!root)
			return;
		_destroy(root->_left);
		_destroy(root->_right);
		delete root;
	}
	//�����������Ĳ������
	bool Insert(const K& key) 
	{
		if (_root == nullptr)//һ��ʼû���κνڵ�
		{
			_root = new Node(key);
			return true;
		}
		//�нڵ�ʱ����Ҫ���ö������������Զ��ֲ��ҵ��ص�ȥ�ҿ��Բ���ĵ�
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
			else  //ԭ���Ѵ���
				return false;
		}
		//���ջ�ͣ��ĳ������Ľڵ��£�����Ҫ���ǲ��뵽��߻����ұ�
		if (parent->_key < key)
		{
			parent->_right = new Node(key);
		}
		else
			parent->_left = new Node(key);
		return true;
	}
	//�ݹ����
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
	bool InsertR(const K& key)  //��Ϊ��Ա������thisָ�룬�����ڵݹ麯�����������ƣ�
	{
		return _insertR(_root, key);
	}


	//���Ҳ���
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
	//�ݹ����
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

	//������ɾ������
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		//���ҵ��ýڵ㣬�ٸ��ݾ���������ٲ��ƻ������������Ĺ����£�ɾ���ýڵ�
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
			else //�ҵ���,���ݾ������ɾ��
			{
				//1.û����ڵ�  ���˽ڵ�������滻����
				//2.û���ҽڵ�  ���˽ڵ�������滻����
				//3.���ҽڵ㶼����   �滻��ɾ��  ���������ڵ�(���ҽڵ�) ��������������С�ڵ�(����ڵ�)
				//
				if (cur->_left == nullptr) //1
				{
					if (parent == nullptr)//ҲҪ���ж��ǲ��Ǹ��ڵ�
					{
						_root=cur->_right;
					}
					else //���Ǹ��ڵ��� ,���滻����ȷ��λ��ȥ
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
				else//3 ���Ҷ���  �滻��ɾ��  ���������ڵ�(���ҽڵ�) ��������������С�ڵ�(����ڵ�)
				{
					Node* minparent = cur;
					Node* minNode = cur->_right; //������ȥ������������ڵ�
					while (minNode->_left)
					{
						minparent = minNode;
						minNode = minNode->_left;
					}
					swap(cur->_key, minNode->_key);//�滻keyֵ���ٽ��˽ڵ�ɾ��

					//���Ǵ˱�ɾ�����������ڵ���ܻ������ӽڵ㣬���Բ���ֱ��ɾ���������˻��������ֻ����ڵ� �� �ҽڵ�����
					minparent->_left=minNode->_right;

					//����Ļ������ô�������ֱ��ɾ��
					delete minNode;
				}
				return true;
			}
		}//����Ϊ��
		return false;
	}

	//�ݹ�ɾ��
	bool _eraseR(Node*& cur, const K& key)
	{
		if (cur == nullptr)//�ݹ���� ��û�ҵ���Ϊ����
			return false;
		//������ȥ��Ҫɾ���Ľڵ�
		if (cur->_key < key)
			return _eraseR(cur->_right, key);
		else if (cur->_key> key)
			return _eraseR(cur->_left, key);
		else  //�ҵ��󣬻��Ǹ��������������ȷɾ��   //�ݹ麯���Ĳ������ǽڵ�ָ������ã����Բ����ٶ���һ�����ڵ���Э��������
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
				//ѡ��������������������ڵ�
				Node* minNode = cur->_right;
				while (minNode->_left)
				{
					minNode = minNode->_left;
				}
				cur->_key = minNode->_key;//ע���Ǹ�ֵ��
				return _eraseR(cur->_right, minNode->_key);//������ת�����˻���������ֻ����ڵ���ҽڵ�����
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
	Node* _root=nullptr; //ȱʡֵ
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
