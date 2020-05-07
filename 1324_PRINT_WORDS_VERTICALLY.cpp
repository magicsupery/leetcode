#include <memory>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> printVertically(string s) {
        int totalNum = 0;
        int indexs[202];
        indexs[0] = 0;
        int lengths[202];
        int length = s.size();
        bool startCheck = true;
        int maxSubLen = 0;
        for(size_t i = 0; i < length; i++)
        {
            if(s[i] != ' ' && startCheck)
            {
                indexs[++totalNum] = i;
                lengths[totalNum - 1] = indexs[totalNum]  - 1;
                maxSubLen = max(maxSubLen, indexs[totalNum] - indexs[totalNum - 1] - 1);
                startCheck = false;
            }
            else if(s[i] == ' ')
            {
                startCheck = true;
            }
        }


        indexs[++totalNum] = s.size() + 1;
        lengths[totalNum - 1] = indexs[totalNum]  - 1;
        maxSubLen = max(maxSubLen, indexs[totalNum] - indexs[totalNum - 1] - 1);

        std::vector<std::string> res;
        for(size_t j = 0; j < maxSubLen; j++)
        {
            std::string tmp(totalNum - 1, ' ');
            int lastEmpty = -1;
            for(size_t k = 1; k < totalNum; k++)
            {
                if(indexs[k] < lengths[k])
                {
                    auto c = s[indexs[k]];
                    tmp[k - 1] = c;
                    if(c != ' ')
                    {
                        lastEmpty = k - 1;
                    }
                    indexs[k] += 1;

                }
            }
            tmp.resize(lastEmpty + 1);
            res.emplace_back(tmp);
        }

        return  res;

    }
};

#include <iostream>
int main()
{
    auto result = Solution().printVertically("HOW U AK");
    for(auto& s: result)
    {
        std::cout << s << std::endl;
    }
}