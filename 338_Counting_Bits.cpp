#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> countBits(int num) {
			if (num < 0)
			{
				return vector<int>();
			}	
			vector<int> res(num + 1, 0);

			int last_first = 1;
			int first = 1;
			for(int i = 1; i <= num; i++)
			{
				if( i == first)
				{
					res[i] = 1;
					last_first = first;
					first *= 2;
				}
				else
				{
					res[i] = res[last_first] + res[i - last_first];
				}
			}

			return res;
		}
};


int main()
{
	auto res = Solution().countBits(27);
	for(auto& i : res)
	{
		cout << i <<  " ,";
	}
}
