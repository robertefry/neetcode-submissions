
#include <utility>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        // assumption: Forall(i){ board.size() == board[i].size() == 9 }

        enum Selector {
            ROW, COL, BOX
        };
        auto bits = bitset<3*9*9>{};

        auto const validate = [&](Selector s, size_t x, size_t i, size_t j)
        {
            // assumption: board[i][j] in '1'..='9'
            size_t idx = (s * 9*9) + (x * 9) + (board[i][j]-'1');

            if (bits[idx]) {
                return false;
            }
            bits[idx] = true;
            return true;
        };

        for (size_t i = 0; i < 9; ++i)
            for (size_t j = 0; j < 9; ++j)
        {
            if (board[i][j] == '.') {
                continue;
            }
            size_t k = (i / 3) * 3 + (j / 3);

            if (not validate(ROW, i, i, j)) return false;
            if (not validate(COL, j, i, j)) return false;
            if (not validate(BOX, k, i, j)) return false;
        }
        return true;
    }
};
