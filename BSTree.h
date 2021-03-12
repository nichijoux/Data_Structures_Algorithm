#pragma once
#ifndef _BSTTREE_H
#define _BSTTREE_H
#include "Tree.h"

template<class T, class compare = Less<T>>
class BST :public Tree<T, compare>
{
public:
	//构造函数
	BST() { Tree<T, compare>(); }

	//插入节点的函数
	void Insert(const T& val);
	//删除节点的函数
	void Remove(const T& val);
	//判断BST中是否存在val
	bool IsHaveVal(const T& val);
};
#endif // !BSTtree.h


//函数的实现,分离头文件和源文件需要BSTree.h和BSTree.cpp 使用时必须#include "BSTree.cpp"不然编译器找不到文件
//但是.cpp太难看了,去掉.cpp使得BSTree.cpp变为BSTree文件(就像iostream一样)也可以编译使用,但感觉还是挺难看的
//所以还是直接全都写在一起算了,定义在前,实现在后

//插入函数的实现
template<class T, class compare>
void BST<T, compare>::Insert(const T& val)
{
	if (this->root == nullptr)
	{
		this->root = new TreeNode<T>(val);
		this->NodeSize++;
	}
	else
	{
		//否则寻找合适的位置插入
		TreeNode<T>* tempNode = this->root;
		while (tempNode != nullptr)
		{
			if (tempNode->val >= val)
			{
				//说明应该向左走
				if (tempNode->left == nullptr)
				{
					tempNode->left = new TreeNode<T>(val);
					this->NodeSize++;
					return;
				}
				tempNode = tempNode->left;
			}
			else
			{
				//否则走右边
				if (tempNode->right == nullptr)
				{
					tempNode->right = new TreeNode<T>(val);
					this->NodeSize++;
					return;
				}
				tempNode = tempNode->right;
			}
		}
	}
}

//删除节点
template<class T, class compare>
void BST<T, compare>::Remove(const T& val)
{
	if (IsHaveVal(val) == true)
	{
		//有多种情况
		//case 1: 要删除的节点为叶子节点
		//case 2: 要删除的节点只有左子树/右子树
		//case 3: 要删除的节点既有左子树又有右子树(利用前驱节点来修改)
		
		//摸了摸了,后面来写
	}
}

//判断BST中是否存在val
template<class T, class compare>
bool BST<T, compare>::IsHaveVal(const T& val)
{
	TreeNode<T>* tempNode = this->root;
	while (tempNode != nullptr)
	{
		if (tempNode->val == val)
		{
			return true;
		}
		else if (tempNode->val > val)
		{
			//val可能在tempNode的左边
			tempNode = tempNode->left;
		}
		else
		{
			//val可能在tempNode的右边
			tempNode = tempNode->right;
		}
	}
	//表示未找到
	return false;
}
