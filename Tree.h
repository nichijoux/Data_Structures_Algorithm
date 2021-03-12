#pragma once
#ifndef _TREE_H
#define _TREE_H

//大于的仿函数
template <class T>
struct Greater
{
	bool operator()(const T& a, const T& b) { return a > b; }
};

//小于的仿函数
template <class T>
struct Less
{
	bool operator()(const T& a, const T& b) { return a < b; }
};

template<class E>
struct TreeNode
{
	E val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(E x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(E x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//默认模板;compare为比较器,默认为小于的仿函数
template<class T, class compare = Less<T>>
class Tree
{
protected:
	TreeNode<T>* root;
	int NodeSize;			//Tree中的节点数量
	//前序遍历的辅助函数(TreeNode* 可更改node的值)
	void preOrderHelp(TreeNode<T>* root, void(*function)(TreeNode<T>* node));
	//中序遍历的辅助函数(TreeNode* 可更改node的值)
	void inOrderHelp(TreeNode<T>* root, void(*function)(TreeNode<T>* node));
	//后序遍历的辅助函数(TreeNode* 可更改node的值)
	void backOrderHelp(TreeNode<T>* root, void(*function)(TreeNode<T>* node));
	//得到树的高度的辅助函数
	int get_Height_Help(TreeNode<T>* root);
public:
	//构造函数
	Tree() { root = nullptr; NodeSize = 0; }

	//前序遍历
	void PreOrder(void(*function)(TreeNode<T>* node)) { preOrderHelp(root, function); };
	//中序遍历
	void InOrder(void(*function)(TreeNode<T>* node)) { inOrderHelp(root, function); }
	//后续遍历
	void BackOrder(void(*function)(TreeNode<T>* node)) { backOrderHelp(root, function); }
	//得到树的高度
	int Get_Tree_Height() { return get_Height_Help(root); }
	//得到节点数
	int GetNodeSize() { return NodeSize; }
};

#endif // Tree.h


//函数实现

//前序遍历的辅助函数
template<class T, class compare>
void Tree<T, compare>::preOrderHelp(TreeNode<T>* root, void(*function)(TreeNode<T>* node))
{
	if (root == nullptr) { return; }
	function(root);
	preOrderHelp(root->left, function);
	preOrderHelp(root->right, function);
}

//中序遍历的辅助函数
template<class T, class compare>
void Tree<T, compare>::inOrderHelp(TreeNode<T>* root, void(*function)(TreeNode<T>* node))
{
	if (root == nullptr) { return; }
	inOrderHelp(root->left, function);
	function(root);
	inOrderHelp(root->right, function);
}

//后序遍历的辅助函数
template<class T, class compare>
void Tree<T, compare>::backOrderHelp(TreeNode<T>* root, void(*function)(TreeNode<T>* node))
{
	if (root == nullptr) { return; }
	backOrderHelp(root->left, function);
	backOrderHelp(root->right, function);
	function(root);
}

//得到树的高度的辅助函数
template<class T, class compare>
int Tree<T, compare>::get_Height_Help(TreeNode<T>* root)
{
	if (root == nullptr) { return 0; }
	int TreeLHeight = get_Height_Help(root->left);
	int TreeRHeight = get_Height_Help(root->right);
	return TreeLHeight >= TreeRHeight ? TreeLHeight + 1 : TreeRHeight + 1;
}
