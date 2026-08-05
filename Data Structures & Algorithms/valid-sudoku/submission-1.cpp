
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        // assumption: Forall(i){ board.size() == board[i].size() == 9 }

        auto const valid_partial = [&](array<bool,9>& seen, size_t i, size_t j)
        {
            if (board[i][j] == '.') {
                return true;
            }
            if (seen[board[i][j]-'1']) {
                return false;
            }
            seen[board[i][j]-'1'] = true;
            return true;
        };

        auto seen_row = array<bool,9>{};
        auto seen_col = array<bool,9>{};
        auto seen_box = array<bool,9>{};

        for (size_t x = 0; x < 9; ++x)
        {
            seen_row.fill(false);
            seen_col.fill(false);
            seen_box.fill(false);

            for (size_t y = 0; y < 9; ++y)
            {
                size_t i = (x % 3) * 3 + (y % 3);
                size_t j = (x / 3) * 3 + (y / 3);

                if (not valid_partial(seen_row, x, y)) return false;
                if (not valid_partial(seen_col, y, x)) return false;
                if (not valid_partial(seen_box, i, j)) return false;
            }
        }
        return true;
    }
};
