#include <iostream>
#include <cstring>

using namespace std;

class Trie {
	public:
		/** Initialize your data structure here. */
		Trie()
			:complete_(false)
	   	{
			memset(children_, 0, 26 * sizeof(int *));
		}
		
		Trie(bool complete)
			:complete_(complete)
		{
			memset(children_, 0, 26 * sizeof(int *));
		}
		/** Inserts a word into the trie. */
		void insert(string word) {
			insert_helper(word, 0);
		}

		void insert_helper(string const& word, size_t start)
		{
			size_t len = word.size();
			if(start == len - 1)
			{
				auto idx = word[start] - 'a';
				if(!children_[idx])
					children_[idx] = new Trie(true);
				else
				{
					children_[idx]->set_complete(true);
				}
				
			}
			else
			{
				auto idx = word[start] - 'a';
				if(!children_[idx])
					children_[idx] = new Trie(false);

				children_[idx]->insert_helper(word, ++start);
			}
		}

		/** Returns if the word is in the trie. */
		bool search(string word) {
			if(word.size() < 1)
				return false;

			return search_helper(word, 0);
		}
		
		bool search_helper(string const& word, size_t start, bool check_complete=true)
		{
			size_t len = word.size();
			size_t idx = word[start] - 'a';
			if(start == len - 1)
			{
				return children_[idx]?  
					(check_complete? children_[idx]->get_complete() : true): false;
			}
			else
			{

				return children_[idx]?  children_[idx]->search_helper(word, ++start, check_complete): false;
			}
		}

		/** Returns if there is any word in the trie that starts with the given prefix. */
		bool startsWith(string prefix) {
			if(prefix.size() < 1)
				return false;

			return search_helper(prefix, 0, false);
		}
		
		inline void set_complete(bool complete)
		{
			complete_ = complete;
		}

		inline bool get_complete()
		{
			return complete_;
		}

	private:
		Trie* children_[26];
		bool complete_;
};

/**
 *  * Your Trie object will be instantiated and called as such:
 *   * Trie obj = new Trie();
 *    * obj.insert(word);
 *     * bool param_2 = obj.search(word);
 *      * bool param_3 = obj.startsWith(prefix);
 *       */

int main()
{
	Trie obj;
	obj.insert("ab");

	cout << "output is " << obj.search("a") << endl;
	cout << "output is " << obj.search("ab") << endl;
	cout << "output is " << obj.startsWith("a") << endl;
}
