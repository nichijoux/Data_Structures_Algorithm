#include <iostream>
#include "BSTree.h"
#include "AVLTree.h"
#include "../../BigInteger(大数类)/BigInteger(大数类)/BigInteger.h"
using namespace std;

int main()
{
	vector<int> nums = { 16,6,64,4,7,23,87,5,44,71,92,99 };
	AVL<int> tree;
	for (int num : nums)
	{
		tree.Insert(num);
	}
	tree.Delete(64);
	cout << tree.Get_Tree_Height() << endl;
	cout << "前序遍历是:  ";
	tree.PreOrder([](TreeNode<int>* node) {
		cout << node->val << " ";
		});
	cout << endl;
	cout << "中序遍历是:  ";
	tree.InOrder([](TreeNode<int>* node) {
		cout << node->val << " ";
		});

	//int arr[] = { 21,6 ,3 ,52, 36, 59 ,66 ,61 ,63 ,88 ,80 };
	//BST<int> bst;
	//srand(time(NULL));
	//for (int i = 0; i < 11; i++)
	//{
	//	bst.Insert(arr[i]);
	//}
	//cout << "前序遍历是:  ";
	//bst.PreOrder([](TreeNode<int>* node) {
	//	cout << node->val << " ";
	//	});
	//cout << endl;
	//cout << "中序遍历是:  ";
	//bst.InOrder([](TreeNode<int>* node) {
	//	cout << node->val << " ";
	//	});
	//cout << endl;
	//cout << "后序遍历是:  ";
	//bst.BackOrder([](TreeNode<int>* node) {
	//	cout << node->val << " ";
	//	});
	//cout << endl;
	//cout << bst.Get_Tree_Height() << endl;

	//bst.Delete(52);
	//bst.Delete(66);
	//bst.Delete(63);
	//cout << "中序遍历是:  ";
	//bst.InOrder([](TreeNode<int>* node) {
	//	cout << node->val << " ";
	//	});
	//cout << endl;
	return 0;
}
