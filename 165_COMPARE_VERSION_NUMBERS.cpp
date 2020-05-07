//
// Created by Administrator on 06/05/2020.
//
#include <memory>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int index1 = 0;
        int size1 = version1.size();
        int index2 = 0;
        int size2 = version2.size();
        int number1 = 0;
        int number2 = 0;
        while(index1 < size1 || index2 < size2)
        {
            number1 = findNextNumber(version1, index1);
            number2 = findNextNumber(version2, index2);
            if(number1 > number2)
            {
                return 1;
            }
            else if(number1 < number2)
            {
                return -1;
            }
        }

        return 0;

    }

    int findNextNumber(string & version, int& startIndex)
    {
        int endIndex = version.size();
        if(startIndex >= endIndex)
        {
            return 0;
        }

        size_t i = startIndex;
        for(; i < endIndex; i++)
        {
            if(version[i] == '.')
            {
                version[i] = '\0';
                break;
            }
        }

        auto result = atoi(version.c_str() + startIndex);
        startIndex = i + 1;
        return result;
    }
};

#include <iostream>
int main()
{
    std::cout << Solution().compareVersion("1.3.001", "1.3.1") << std::endl;
}
