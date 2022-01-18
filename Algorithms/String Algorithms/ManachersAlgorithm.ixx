module;
#include <vector>
#include <string>
export module ManachersAlgorithm;

namespace algorithms
{
	namespace stringAlgorithms
	{
		using namespace std;
		export vector<vector<int>> findAllPalindromes(const string& s)
		{
			int n = s.length();
			vector<int> odd(n), even(n);
			for (int i = 0, l = 0, r = -1; i < n; i++)
			{
				// here 1 is necessary because we are checking for odd length palindromes
				int k = i > r ? 1 : min(r - i + 1, odd[l + r - i]);
				while (i - k >= 0 && i + k < n && s[i + k] == s[i - k])
					k++;
				odd[i] = k--;
				if (i + k > r)
					l = i - k, r = i + k;
			}
			for (int i = 0, l = 0, r = -1; i < n; i++)
			{
				// here 0 because there can't be odd length palindrome when checking for even length
				int k = i > r ? 0 : min(r - i + 1, even[l + r + 1 - i]);
				while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k])
					k++;
				even[i] = k;
				if (i + k - 1 > r)
					l = i - k, r = i + k - 1;
			}
			return { odd,even };
		}
	}
}