#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		int last_max = 0;
		int current_max = 0;
		unordered_map<char, int> char_2pos;
		
		for(size_t i = 0; i < s.size(); i++)
		{
			char c = s[i];
			if(char_2pos.find(c) == char_2pos.end())
			{
				char_2pos[c] = i;
				last_max += 1;

			}
			else
			{
				last_max = i - char_2pos[c];
				char_2pos[c] = i;

			}

			current_max = max(current_max, last_max);
		}
		return current_max;
	}
};

int main()
{
	cout << "length is " << Solution().lengthOfLongestSubstring("pwwkew") << endl;
}
