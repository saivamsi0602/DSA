export module TreeNode;

namespace datastructures
{
	namespace trees
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
