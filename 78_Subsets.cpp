#include <iostream>
#include <vector>

using namespace std;
class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			vector<vector<int>> res = {{}, };
			size_t len = nums.size();
			for(size_t i = 0; i < len; i++)
			{
				size_t added_num = nums[i];
				vector<vector<int>> res_added;
				for(auto& vec : res)
				{
					auto copy(vec);
					copy.emplace_back(added_num);
					res_added.emplace_back(copy);
				}

				res.reserve(res.size() + distance(res_added.begin(), res_added.end()));
				res.insert(res.end(), res_added.begin(), res_added.end());

			}

			return res;
		}
};

int main()
{
	vector<int> tmp = {1, 2, 3};
	auto res = Solution().subsets(tmp);	
}
