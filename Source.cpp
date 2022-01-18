
#include <iostream>
#include <vector>
import LCAtwoNodes;
import TreeNode;
using namespace std;

int main()
{
	cout << "Hello world!" << endl;
	using namespace algorithms::treeAlgorithms;
	using namespace datastructures::trees;
	TreeNode *t = new TreeNode(1);
	t->left = new TreeNode(2);
	t->right = new TreeNode(3);
	t->left->left = new TreeNode(4);
	t->left->right = new TreeNode(5);
	t->right->right = new TreeNode(6);
	cout << lcaTwoNodes(t, 4, 5) << endl;
	cout << lcaTwoNodes(t, 6, 5) << endl;
	cout << lcaTwoNodes(t, 1, 5) << endl;
	cout << endl;
}