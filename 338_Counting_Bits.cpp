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

			int first = 1;
			for(int i = 1; i <= num; i++)
			{
				first = ( i == 2 * first)? i : first;
				res[i] = 1 + res[i - first];
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
