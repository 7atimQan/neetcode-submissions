class Solution {
public:
    bool    checkLines(vector<vector<char>>& board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            string s;
            for (int j = 0; j < board[i].size(); j++)
            {
                if (s.find(board[i][j], 0) != string::npos)
                {
                    std::cout << s << std::endl;
                    return false;
                }
                if (isdigit(board[i][j]))
                    s += board[i][j];
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        if (checkLines(board))
            return true;
        return false;
    }
};
