#include <vector>
export module SegmentTree;

namespace datastructures
{
	namespace trees
	{
		using namespace std;
		export class SegmentTree
		{
		public:
			SegmentTree(vector<int>& originalarray) : arr(originalarray)
			{
				int n = arr.size();
				n |= n >> 1;
				n |= n >> 2;
				n |= n >> 4;
				n |= n >> 8;
				n |= n >> 16;
				// find the next power of two for the arr size and double it and subtract one to get the exact size of tree
				n = n << 1 | 1 ;
				t = vector<int>(n, INT_MAX);
				buildTree(0, 0, arr.size() - 1);
			}
			int rangeQuery(int start, int end)
			{
				return rangeMinQuery(0, 0, arr.size() - 1,start,end);
			}
			void update(int pos, int newValue)
			{
				update(0, 0, arr.size() - 1, pos, newValue);
			}
		private:
			vector<int> t, & arr;
			
			// post order build
			void buildTree(int index, int left, int right)
			{
				if (left == right)
					t[index] = arr[left];
				else
				{
					int mid = (left + right) / 2;
					buildTree(2 * index + 1, left, mid);
					buildTree(2 * index + 2, mid + 1, right);
					t[index] = min(t[2 * index + 1], t[2 * index + 2]);

				}
			}

			// post order update
			void update(int index, int left, int right, int pos, int newValue)
			{
				if (left == right) t[index] = newValue, arr[pos] = newValue;
				else
				{
					int mid = (left + right) / 2;
					if (pos <= mid) update(2 * index + 1, left, mid, pos, newValue);
					else update(2 * index + 2, mid + 1, right, pos, newValue);
					t[index] = min(t[2 * index + 1], t[2 * index + 2]);
				}
			}

			/*
			let's assume that we visit three or four vertices in the current level.
			From those vertices, we will analyze the vertices in the middle more carefully. 
			Since the sum query asks for the sum of a continuous subarray, 
			we know that segments corresponding to the visited vertices in the middle will be completely covered by the segment of the sum query.
			Therefore these vertices will not make any recursive calls. So only the most left, and the most right vertex will have the potential to make recursive calls.
			*/
			int rangeMinQuery(int index, int left, int right, int qleft, int qright)
			{
				if (qleft > qright) return INT_MAX;
				if (qleft == left && qright == right) return t[index];
				int mid = (left + right) / 2;
				return min(rangeMinQuery(2 * index + 1, left, mid, qleft, min(mid, qright)), rangeMinQuery(2 * index + 2, mid + 1, right, max(mid + 1, qleft), qright));
			}

		};
	}
}
