
#include <iostream>
#include <vector>
import SegmentTree;
using namespace std;

int main()
{
	cout << "Hello world!" << endl;
	vector<int> v{ 4,3,5,7,1,6,2,9 };
	datastructures::trees::SegmentTree s(v);
	cout << s.rangeQuery(0, 7) << endl;
	cout << s.rangeQuery(3, 6) << endl;
	cout << s.rangeQuery(0, 3) << endl;
	cout << s.rangeQuery(5, 7) << endl;
	s.update(2, 0);
	cout << s.rangeQuery(0, 7) << endl;
	cout << s.rangeQuery(3, 6) << endl;
	cout << s.rangeQuery(0, 3) << endl;
	cout << s.rangeQuery(5, 7) << endl;

	cout << endl;
}