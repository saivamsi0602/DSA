#include <unordered_map>
export module Trie;

namespace datastructures
{
	namespace stringDataStructures
	{
		using namespace std;
		export class Trie
		{
		public:
			Trie() : isEnding(false), m(unordered_map<char, Trie*>())
			{

			}
			bool searchWordInTrie(const string& word)
			{
				return searchWord(word);
			}
			void insertWordInTrie(const string& word)
			{
				insertWord(word);
			}
			void deleteIfPresent(const string& word)
			{
				deleteWord(word);
			}
		private:
			bool isEnding;
			unordered_map<char, Trie*> m;
			// always travel to the child node using the -> operator.
			bool searchWord(const string& word, int index = 0)
			{
				if (index == word.length()) return isEnding;
				return m.contains(word[index]) && m[word[index]]->searchWord(word, index + 1);
			}
			void insertWord(const string& word, int index = 0)
			{
				if (index == word.length())
				{
					isEnding = true;
					return;
				}
				if (!m.contains(word[index])) m[word[index]] = new Trie();
				m[word[index]]->insertWord(word, index + 1);
			}
			bool deleteWord(const string& word, int index=0)
			{
				if (index == word.length()) isEnding = false;
				// (m.contains(word[index]) && deleteWord(word,index+1)) is wroong because function call doesnt travel
				// to the child node.
				else if (m.contains(word[index]) && m[word[index]]->deleteWord(word,index+1)) m.erase(word[index]);
				return !isEnding && m.empty();
			}
		};
	}
}
