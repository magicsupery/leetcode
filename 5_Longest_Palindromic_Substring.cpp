#include <iostream>
#include <cstring>

using namespace std;
class Solution
{
	public:
		string longestPalindrome(string s)
		{
			if(s.size() < 1)
				return "";

			size_t max_start_p = 0;
			size_t max_end_p = 0;
			size_t start_p = 0;
			size_t end_p = 0;
			bool check = true;
			for(size_t i = 1; i< s.size(); i++, check=true)
			{
				if(i == end_p + 1)
				{
					if(s[i] == s[start_p])
					{
						end_p ++;
						check = false;
					}
					else if(start_p > 0 and s[i] == s[start_p - 1])
					{
						start_p --;
						end_p ++;
						check = false;
					}
				}	
				
				if(check)
				{
					if(i > 1 and s[i] == s[i - 2])
					{
						start_p = i - 2;
						end_p = i;

					}
					else if(s[i] == s[i - 1])
					{
						start_p = i - 1;
						end_p = i;
					}
				}

				if((end_p - start_p) > (max_end_p - max_start_p))
				{
					max_end_p = end_p;
					max_start_p = start_p;
				}

			}
			return s.substr(max_start_p, max_end_p - max_start_p + 1);

		}
};

int main()
{
	cout << "output is " << Solution().longestPalindrome("ababd") << endl;
}
