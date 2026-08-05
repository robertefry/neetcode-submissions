
#include <utility>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        // assumption: Forall(i){ board.size() == board[i].size() == 9 }

        auto rows = array<bitset<9>,9>{};
        auto cols = array<bitset<9>,9>{};
        auto boxs = array<bitset<9>,9>{};

        auto const validate = [&](bitset<9>& bits, size_t i, size_t j)
        {
            // assumption: board[i][j] in '1'..='9'
            size_t val = board[i][j] - '1';

            if (bits[val]) {
                return false;
            }

            bits[val] = true;
            return true;
        };

        for (size_t i = 0; i < 9; ++i)
            for (size_t j = 0; j < 9; ++j)
        {
            if (board[i][j] == '.') {
                continue;
            }
            size_t k = (i / 3) * 3 + (j / 3);

            if (not validate(rows[i], i, j)) return false;
            if (not validate(cols[j], i, j)) return false;
            if (not validate(boxs[k], i, j)) return false;
        }
        return true;
    }
};
