#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<string> get_candidates(string const& cur, vector<string> const& pre_list, vector<string> const& word_list)
    {
        //ROV 优化
        vector<string> candidates;
        
        int diff_size = 0;
        int len = cur.size(); 
        for(auto & word : word_list)
        {
            diff_size = 0;
            for(size_t i = 0; i < len; i++)
            {
                if(word[i] != cur[i])
                {
                    diff_size ++;
                    if(diff_size > 1)
                    {
                        break;
                    }
                }
            }

            if(diff_size == 1)
            {
                if(find(pre_list.begin(), pre_list.end(), word) == pre_list.end())
                {
                    candidates.emplace_back(word);
                }
            }

        }
        return candidates;
    }
    void find_next(string const& cur, string const& end_str,
     vector<string>& pre_list, vector<string> const& word_list,
     vector<vector<string>> res_list)
    {
        if(cur == end_str)
        {
            if(find(word_list.begin(), word_list.end(), cur) != word_list.end())
            {
                pre_list.emplace_back(cur);
                res_list.emplace_back(pre_list);
            }
            return;
        }

        vector<string> next_candidates = get_candidates(cur, pre_list, word_list);

        for(auto& candidate : next_candidates)
        {
            pre_list.emplace_back(candidate);
            find_next(candidate, end_str, pre_list, word_list, res_list);
            pre_list.pop_back();
        }
        
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res_list;
        vector<string> pre_list;
        find_next(beginWord, endWord, pre_list, wordList, res_list);
        return res_list;
    }
};

int main()
{
    vector<string> word_list;
    word_list.emplace_back("hot");
    word_list.emplace_back("dot");
    word_list.emplace_back("dog");
    word_list.emplace_back("lot");
    word_list.emplace_back("log");
    word_list.emplace_back("cog");

    auto res = Solution().findLadders("hit", "cog", word_list);

    std::cout << "[" << std::endl;
    for(vector<string>& word_list: res)
    {
        cout << " [ ";

        for(auto& word: word_list)
        {
            cout << word << " , ";
        }
        cout << " ] " << endl;
    }

    cout << "]" << endl;

    system("pause");
}