export module TreeNode;

namespace algorithms
{
	namespace treeAlgorithms
	{
		export class TreeNode
		{
		public:
			int val;
			TreeNode* left, * right;
			TreeNode(int value): val(value), left(nullptr), right(nullptr)
			{

			}
		};
	}
}