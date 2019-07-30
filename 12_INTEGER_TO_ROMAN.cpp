#include <iostream>
#include <string> 

using namespace std;
class Solution
{
public:
    string intToRoman(int num)
    {
        string res;
        help(num / 1000, res, 'M', 'P', 'P');
        num = num % 1000;
        help(num / 100, res, 'C', 'D', 'M');
        num = num % 100;
        help(num / 10, res, 'X', 'L', 'C');
        num = num % 10;
        help(num, res, 'I', 'V', 'X');

        return res;
    }

    void help(int digit, string &res, char a, char b, char c)
    {

        if (digit <= 3)
        {
            for (int i = 0; i < digit; i++)
            {
                res.push_back(a);
            }
        }
        else if (digit == 4)
        {
            res.push_back(a);
            res.push_back(b);
        }
        else if (digit == 5)
        {
            res.push_back(b);
        }
        else if (digit > 5 && digit < 9)
        {
            res.push_back(b);
            for (int i = 0; i < digit - 5; i++)
            {
                res.push_back(a);
            }
        }
        else if (digit == 9)
        {
            res.push_back(a);
            res.push_back(c);
        }
    }
};

int main()
{
    auto res = Solution().intToRoman(1994);

    std::cout << res << std::endl;

    system("pause");
}