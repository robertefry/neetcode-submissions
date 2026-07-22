
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        // assumption: Forall(i,j){ board[i].size() == board[j].size() }
        auto const n = board.size();
        auto const m = (n == 0) ? 0 : board[0].size();

        auto visited = vector<vector<bool>>(n,vector<bool>(m,false));

        auto const search = [&](auto const search, auto const k, auto const i, auto const j) -> bool
        {
            // assumption: 0 <= k < word.size()
            // assumption: 0 <= i < n && 0 <= j < m

            if (visited[i][j] || word[k] != board[i][j]) {
                return false;
            }
            if (k+1 == word.size()) {
                return true;
            }

            visited[i][j] = true;
            if (i+1 < n && search(search, k+1, i+1, j)) return true;
            if (i >= 1  && search(search, k+1, i-1, j)) return true;
            if (j+1 < m && search(search, k+1, i, j+1)) return true;
            if (j >= 1  && search(search, k+1, i, j-1)) return true;
            visited[i][j] = false;

            return false;
        };

        for (auto i = 0; i < board.size(); ++i)
            for (auto j = 0; j < board[i].size(); ++j)
        {
            if (search(search, 0, i, j)) {
                return true;
            }
        }
        return false;
    }
};
