#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
	public:
		bool canJump(vector<int>& nums) {
			size_t max_distance_index = 0;
			for (size_t i = 0; i < nums.size(); i++)
			{
				if(max_distance_index >= nums.size() - 1)
					return true;

				if(nums[i] != 0)
					max_distance_index = std::max(max_distance_index, nums[i] + i);
				else
				{
					if(i >= max_distance_index)
						return false;
				}
			}
			return false;
		}
};

int main()
{
	vector<int> nums = {2, 3, 1, 1, 4};
	cout << "output is " << Solution().canJump(nums) << endl;
}
