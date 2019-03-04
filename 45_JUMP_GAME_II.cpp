#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
	public:
		int jump(vector<int>& nums) {
			size_t times = 0;
			size_t max_distance_index = 0;
			size_t last_max_distance_index = 0;
			for (size_t i = 0; i < nums.size() - 1; i++)
			{
				max_distance_index = std::max(max_distance_index, i + nums[i]);
				if (i == last_max_distance_index)
				{
					last_max_distance_index = max_distance_index;
					times ++;
				}
			}

			return times;
		}
};


int main()
{
	vector<int> nums = {2, 3, 1, 1, 4};
	cout << "output is " << Solution().jump(nums) << endl;
}
