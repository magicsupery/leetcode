#include <iostream>
using namespace std;
class Solution {
	public:
		string convert(string s, int numRows) {
			int l = s.size();
			if(l < 1 or numRows < 1)
			{
				return "";
			}
			
			char output[l];
			size_t index = 0;
			int k = 2 * numRows - 2;
			int p = l / k;
			int q = l % k;

			for(int r = 0; r < numRows; r++)
			{
				for(int c = 0; c < p; c++)
				{
					cout << "c is " << c << endl;
					//origin-part1
					output[index++] = s[c * k + r];
					//origin-part2
					if(r != 0 and r!= numRows - 1)
					{
						output[index++] = s[c * k + k - r];
					}
				}

				//addtional-part1
				if(q > r)
				{
					output[index++] = s[p * k + r];
				}
				//addtional-part2
				if(r != 0 and r!= numRows - 1)
				{
					if(q + r > k)
					{
						output[index++] = s[p * k + k -r];
					}
				}
			}
			return string(output, l);
		}
};

int main()
{
	cout << "output is " << Solution().convert("PAYP123", 4) << endl;
}
