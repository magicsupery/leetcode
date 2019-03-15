#include <iostream>
#include <vector>

using namespace std;
class Solution
{
	public:
		bool search_string(string const& origin, string const& pattern)
		{
			int o_size = origin.size();
			int p_size = pattern.size();
			if(o_size < 1 or p_size < 1)
				return false;
			
			vector<int> next(p_size, 0);
			
			init_next(pattern, next);
			int i = 0;
			int j = 0;

			while(i < o_size and j < p_size)
			{
				if(j == -1  or origin[i] == pattern[j])
				{
					i++;
					j++;
				}
				else
				{
					j = next[j];
				}
			}
			return j == p_size;
		}

		void init_next(string const& pattern, vector<int>& next)
		{
			size_t len = next.size();
			for(size_t i = 2; i< len; i++)
			{
				int k = next[i - 1];
				while(k > 0)
				{
					if(pattern[i] == pattern[k])
					{
						break;
					}
					k = next[k];
				}
				
				next[i] = k > 0? k + 1 : (pattern[0] == pattern[i]? 1: 0);
			}
		}
};

int main()
{
	cout << "output is " << Solution().search_string("abcabcde", "abcd") << endl;
}
