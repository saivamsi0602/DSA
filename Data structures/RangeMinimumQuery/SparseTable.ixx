#include <vector>
#include <numeric>
#include <iostream>
export module SparseTable;

namespace datastructures
{
	namespace rangeMinimumQuery
	{
		using namespace std;
		/// Sparse tables can be used only on arrays with invariant data.
		/// This means if the data is being changed then the whole table needs to be recomputed again.
		/// Sparse table only works on idempotent functions i.e functions like min etc not sum of range
		/// Disjoint sparse table and sqrt tree handle range queries of associative functions in O(1).
		export class SparseTable
		{
		public:
			SparseTable(const vector<int>& arr):arr(arr)
			{
				// here +1 is added to log of size because j represents the 2 power j number of elements starting from the current element
				// hence 0 1 .. logn is 1+logn size
				int n = 1+log2(arr.size());
				table = vector<vector<int>>(n , vector<int>(arr.size()));
				iota(table.front().begin(), table.front().end(), 0);
				for (int i = 1; i < table.size(); i++) for (int j = 0; j -1 + (1 << i) < arr.size(); j++)
					table[i][j] = arr[table[i - 1][j]] < arr[table[i - 1][j + (1 << (i - 1))]] ? table[i - 1][j] : table[i - 1][j + (1 << (i - 1))];
			}
			int rangeQuery(int left, int right)
			{
				return rangeMinQuery(left, right);
			}
		private:
			vector<vector<int>> table;
			const vector<int>& arr;
			int rangeMinQuery(int l, int r)
			{
				int row = log2(r-l+1);
				return min(arr[table[row][l]], arr[table[row][r + 1 - (1 << row)]]);
			}
		};
	}
}
