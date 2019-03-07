#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s)
		{
			if(s.size() < 1)
				return 0;

			int char_2pos[128];
			memset(char_2pos, 0, 128 * 4);
			size_t last_max = 0;
			size_t current_max = 0;

			for(size_t i = 0; i < s.size(); i++)
			{

				int c = s[i];
				last_max = char_2pos[c] == 0 ? last_max + 1: min(i + 1 - char_2pos[c], last_max + 1);
				char_2pos[c] = i + 1;
				current_max = max(current_max, last_max);
			}
			return current_max;
		}
};

int main()
{
	cout << "length is " << Solution().lengthOfLongestSubstring(" ") << endl;
}
