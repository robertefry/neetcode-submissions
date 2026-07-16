
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 0) {
            return;
        }

        // assumption: Forall(i,j){ matrix[i].size() == matrix[j].size() }
        auto const n = matrix.size();
        auto const m = matrix[0].size();

        auto i_zeros = unordered_set<size_t>{};
        auto j_zeros = unordered_set<size_t>{};

        for (size_t i = 0; i < n; ++i)
            for (size_t j = 0; j < m; ++j)
        {
            if (matrix[i][j] == 0) {
                i_zeros.insert(i);
                j_zeros.insert(j);
            }
        }

        for (auto const i : i_zeros)
            for (size_t j = 0; j < m; ++j)
        {
            matrix[i][j] = 0;
        }

        for (auto const j : j_zeros)
            for (size_t i = 0; i < n; ++i)
        {
            matrix[i][j] = 0;
        }
    }
};
