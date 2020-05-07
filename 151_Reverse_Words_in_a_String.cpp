#include <iostream>
#include <memory>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        
        std::string output;
        output.reserve(s.size());

        int outputIndex = 0;
        int inputIndex = s.size() - 1;
        int endIndex = 0;
        int startIndex = 0;
        bool hasLast = false;
        while(true)
        {
            endIndex = findNextNoneSpacePos(s, inputIndex);
            if(endIndex >= 0)
            {
                if(hasLast)
                {
                    output[outputIndex++] = ' ';
                }
                startIndex = findNextSpacePos(s, endIndex - 1);
                memcpy((void *) (output.data() + outputIndex), s.data() + startIndex + 1, endIndex - startIndex);
                outputIndex += (endIndex - startIndex);
                inputIndex = startIndex - 1;
                hasLast = true;
            }
            else
            {
                break;
            }
        }
        output[outputIndex] = '\0';
        return output;
    }

    int findNextSpacePos(string const& s, int index)
    {

        for(int i = index; i >= 0; i--)
        {
            if(s[i] == ' ')
            {
                return i;
            }
        }
        return -1;
    }
    int findNextNoneSpacePos(string const& s, int index)
    {
        for(int i = index; i >= 0; i--)
        {
            if(s[i] != ' ')
            {
                return i;
            }
        }

        return -1;
    }

};
int main()
{
    std::cout << Solution().reverseWords("a good   example").c_str() << std::endl;
}