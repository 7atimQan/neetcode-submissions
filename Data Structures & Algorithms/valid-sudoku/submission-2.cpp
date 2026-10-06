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

        checkLines(board);
        vector<vector<char>> square(9, vector<char>(9));
        vector<vector<char>> vertical(9, vector<char>(9));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                vertical[j][i] = board[i][j];

                int line = i % 3;
                int k = 0;
                square[(j / 3) + i - line][(j % 3) + (3 * line)] = board[i][j];
            }
        }

        if(!checkLines(board))
            return false;
        if(!checkLines(vertical))
            return false;
        if(!checkLines(square))
            return false;
        // for (int i = 0; i < square.size(); i++)
        // {
        //     for (int j = 0; j < square[i].size(); j++)
        //         cout << square[i][j];
        //     cout << endl;
        // }
        return true;
    }
};
