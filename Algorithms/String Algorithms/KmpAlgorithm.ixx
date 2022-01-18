module;
#include <vector>
#include <string>
export module KmpAlgorithm;

namespace algorithms
{
	namespace stringAlgorithms
	{
		using namespace std;
		export vector<int> lspFunction(const string& pattern)
		{
			vector<int> lsp(pattern.length());
			for (size_t i = 1; i < pattern.length(); i++)
			{
				// for this reason the first we should start the iteration through 1 because of accessing the previous index.
				int j = lsp[i - 1];
				while (j > 0 && pattern[i] != pattern[j])
					j = lsp[j - 1];
				lsp[i] = j + (pattern[i] == pattern[j]);
			}
			return lsp;
		}
		export vector<bool> KmpMatchPattern(const string& s, const string& pattern)
		{
			vector<int> lsp(lspFunction(pattern));
			vector<bool> res(s.length(), false);
			for (size_t i = 0, j = 0; i < s.length(); i++)
			{
				if (pattern[j] == s[i])
				{
					if (++j == pattern.length())
					{
						res[i] = true;
						j = lsp.back();

					}
				}
				else
				{
					while (j > 0 && s[i] != pattern[j])
						j = lsp[j - 1];
					j += s[i] == pattern[j];
				}
			}
			return res;
		}
	}
}

