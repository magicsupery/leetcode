#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
	public:
		void sortColors(vector<int>& nums) {
				
			size_t color_num[3] = {0, 0, 0};
			
			auto len = nums.size();
			if(len < 1)
				return;

			color_num[nums[0]] += 1;
			for(size_t i = 1; i < len; i++)
			{
				auto current_color = nums[i];
				if(current_color == 2)
					continue;
				
				auto current_color_num = (current_color == 0)? color_num[0]: color_num[0] + color_num[1];
				if(current_color_num == i)
				{
					color_num[current_color] += 1;
					continue;
				}
			
				std::swap(nums[current_color_num], nums[i]);
				
				if(nums[i] == 1)
				{
					current_color_num = color_num[0] + color_num[1];
					
					if(current_color_num == i)
					{
						color_num[current_color] += 1;
						continue;
					}
				
					std::swap(nums[current_color_num], nums[i]);
				}
					
				
				
				color_num[current_color] += 1;
			}
				

		}
};

int main()
{
	vector<int> nums = {0, 0, 1};
	Solution().sortColors(nums);

	cout << "output is ";
	for(auto& num : nums)
	{
		cout << num << " , ";
	}
	cout << endl;
}
