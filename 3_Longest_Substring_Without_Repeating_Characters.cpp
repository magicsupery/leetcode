#include <algorithm>
#include <iostream>

using namespace std;
int char_2pos[128];

class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		size_t last_max = 0;
		size_t current_max = 0;
		
		for(size_t i = 0; i < s.size(); i++)
		{
			if(s.size() < 1)
				return 0;

			int c = s[i];
			if(char_2pos[c] == 0)
			{
				last_max += 1;

			}
			else
			{
				last_max = min(i + 1 - char_2pos[c], last_max + 1);

			}

			char_2pos[c] = i + 1;
			current_max = max(current_max, last_max);
		}
		return current_max;
	}
};

int main()
{
	cout << "length is " << Solution().lengthOfLongestSubstring("cdd") << endl;
}
