#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
       if(board.size() == 0)
        {
            return false;
        }

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(dfs(board, i, j, word, 0))
                    return true;
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string const& word, int pos)
    {
        if(pos == word.size())
        {
            return true;
        }

        if(i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] == '\0' || board[i][j] != word[pos])
        {
            return false;
        }

        board[i][j] = '\0';
        bool res = dfs(board, i - 1, j, word, pos + 1) || dfs(board, i + 1, j, word, pos + 1) || 
            dfs(board, i, j - 1, word, pos + 1) || dfs(board, i, j + 1, word, pos + 1);
        board[i][j] = word[pos];

        return res;
    }
};
int main()
{
    vector<vector<char>> board(4, vector<char>(4, '\0'));
    
}