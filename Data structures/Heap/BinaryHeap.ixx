#include <queue>
#include <algorithm>
#include <unordered_map>
export module BinaryHeap;

namespace datastructures
{
	namespace heapDataStructure
	{
		using namespace std;
		class BinaryHeap : public priority_queue<pair<int, int>>
		{
		private:
			unordered_map<int, int> index;
			void decrease(int v, int value)
			{
				int cur = index[v], parent = (cur - 1) / 2;
				if (value < c[cur].second) c[cur].second = value;
				while (cur > 0 && (c[cur].second < c[parent].second))
				{
					std::swap(c[cur], c[parent]);
					std::swap(index[c[cur].first], index[c[parent].first]);
					cur = parent;
					parent = (cur - 1) / 2;
				}
			}
		public:
			void push(pair<int, int> edge)
			{
				if (!index.count(edge.first))
				{
					index[edge.first] = c.size();
					c.push_back(edge);
				}
				decrease(edge.first, edge.second);
			}
			void pop()
			{
				std::swap(c.front(), c.back());
				index[c.front().first] = 0;
				index.erase(c.back().first);
				c.pop_back();
				int cur = 0;
				while (2 * cur + 1 < c.size())
				{
					int smallchild = 2 * cur + 2 == c.size() ? 2 * cur + 1 : (c[2 * cur + 1].second < c[2 * cur + 2].second ? 2 * cur + 1 : 2 * cur + 2);
					if (c[smallchild].second < c[cur].second)
					{
						std::swap(c[cur], c[smallchild]);
						std::swap(index[c[cur].first], index[c[smallchild].first]);
						cur = smallchild;
					}
					else break;
				}
			}
		};
	}
}