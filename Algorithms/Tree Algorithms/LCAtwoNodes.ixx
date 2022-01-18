module;
#include <functional>
import TreeNode;
export module LCAtwoNodes;

namespace algorithms
{
	namespace treeAlgorithms
	{
		using namespace std;
		using namespace datastructures::trees;
		// returns -1 if there is no lca
		export int lcaTwoNodes(TreeNode* root, int A, int B)
		{
			int count = 0;
			// assuming all the nodes are unique and the values are greater than zero
			function<int(TreeNode*)> lca = [&](TreeNode* node)->int {
				if (!node) return 0;
				int left = lca(node->left), right = lca(node->right);
				if (node->val == A || node->val == B)
				{
					count++;
					return node->val;
				}
				return left && right ? node->val : left | right;
			};
			int res = lca(root);
			return !res || (A != B && count != 2) ? -1 : res;
		}
	}
}
