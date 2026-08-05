
#include <utility>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        // assumption: Forall(i){ board.size() == board[i].size() == 9 }

        auto rows = array<array<bool,9>,9>{};
        auto cols = array<array<bool,9>,9>{};
        auto boxs = array<array<bool,9>,9>{};

        for (size_t i = 0; i < 9; ++i)
            for (size_t j = 0; j < 9; ++j)
        {
            if (board[i][j] == '.') {
                continue;
            }
            size_t k = (i / 3) * 3 + (j / 3);

            if (exchange(rows[i][board[i][j]-'1'], true)) {
                return false;
            }
            if (exchange(cols[j][board[i][j]-'1'], true)) {
                return false;
            }
            if (exchange(boxs[k][board[i][j]-'1'], true)) {
                return false;
            }
        }
        return true;
    }
};
