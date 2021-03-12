#include <iostream>
#include <queue>
#include "BSTree.h"
#include "../../BigInteger(大数类)/BigInteger(大数类)/BigInteger.h"
using namespace std;

int main()
{
	BST<int> bst;
	for (int i = 0; i < 10; i++)
	{
		bst.Insert(rand() % 100);
	}
	cout << "前序遍历是:  ";
	bst.PreOrder([](TreeNode<int>* node) {
		cout << node->val << " ";
		});
	cout << endl;
	cout << "中序遍历是:  ";
	bst.InOrder([](TreeNode<int>* node) {
		cout << node->val << " ";
		});
	cout << endl;
	cout << "后序遍历是:  ";
	bst.BackOrder([](TreeNode<int>* node) {
		cout << node->val << " ";
		});
	cout << endl;
	cout << bst.Get_Tree_Height();
	//BST<BigInteger> bst;
	//srand(time(NULL));
	//for (int i = 0; i < 10; i++)
	//{
	//	BigInteger num;
	//	cin >> num;
	//	bst.Insert(num);
	//}
	//cout << "前序遍历是:  ";
	//bst.PreOrder([](TreeNode<BigInteger>* node) {
	//	cout << node->val << " ";
	//	});
	//cout << endl;
	//cout << "中序遍历是:  ";
	//bst.InOrder([](TreeNode<BigInteger>* node) {
	//	cout << node->val << " ";
	//	});
	//cout << endl;
	//cout << "后序遍历是:  ";
	//bst.BackOrder([](TreeNode<BigInteger>* node) {
	//	cout << node->val << " ";
	//	});
	//cout << endl;
	//cout << bst.Get_Tree_Height();
	return 0;
}
