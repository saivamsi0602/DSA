#include <vector>
import BinaryHeap;
export module PrimsAlgorithm;

namespace algorithms
{
	namespace graphAlgorithms
	{
		using namespace std;
		export int PrimsMST(vector<vector<pair<int, int>>> g)
		{
			datastructures::heapDataStructure::BinaryHeap b;
			b.push({ 0,0 });
			vector<bool> inMst(4, false);
			int total = 0;
			while (!b.empty())
			{
				auto temp = b.top();
				b.pop();
				total += temp.second;
				inMst[temp.first] = true;
				for (auto& edge : g[temp.first]) if (!inMst[edge.first])
					b.push(edge);
			}
			return total;
		}
	}
}