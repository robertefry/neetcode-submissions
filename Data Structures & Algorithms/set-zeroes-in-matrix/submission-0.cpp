
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

        auto zeros = vector<tuple<size_t,size_t>>{};

        for (size_t i = 0; i < n; ++i)
            for (size_t j = 0; j < m; ++j)
        {
            if (matrix[i][j] == 0) {
                zeros.push_back({i,j});
            }
        }

        for (auto [i,j] : zeros)
        {
            for (size_t k = 0; k < n; ++k) {
                matrix[k][j] = 0;
            }
            for (size_t k = 0; k < m; ++k) {
                matrix[i][k] = 0;
            }
        }
    }
};
