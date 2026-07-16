
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

        auto i_zeros = vector<bool>(n);
        auto j_zeros = vector<bool>(m);

        for (size_t i = 0; i < n; ++i)
            for (size_t j = 0; j < m; ++j)
        {
            if (matrix[i][j] == 0) {
                i_zeros[i] = true;
                j_zeros[j] = true;
            }
        }

        for (size_t i = 0; i < n; ++i)
            for (size_t j = 0; j < m; ++j)
        {
            if (i_zeros[i])
                matrix[i][j] = 0;
        }

        for (size_t j = 0; j < m; ++j)
            for (size_t i = 0; i < n; ++i)
        {
            if (j_zeros[j])
                matrix[i][j] = 0;
        }
    }
};
