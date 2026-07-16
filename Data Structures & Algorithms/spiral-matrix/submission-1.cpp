
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> const& matrix)
    {
        // assumption: Forall(i,j){ matrix[i].size() == matrix[j].size() }
        auto const n = matrix.size();
        auto const m = matrix[0].size();

        auto result = vector<int>{};
        result.reserve(n*m);

        for (size_t k = 0; 2*k < min(n,m); ++k)
        {
            auto const i_max = n-k-1;
            auto const j_max = m-k-1;

            if (k == i_max) {
                for (size_t j = k; j <= j_max; ++j) {
                    result.push_back(matrix[k][j]);
                }
                continue;
            }
            if (k == j_max) {
                for (size_t i = k; i <= i_max; ++i) {
                    result.push_back(matrix[i][k]);
                }
                continue;
            }

            auto i = k;
            auto j = k;

            while (j < j_max) {
                result.push_back(matrix[i][j++]);
            }
            while (i < i_max) {
                result.push_back(matrix[i++][j]);
            }
            while (j > k) {
                result.push_back(matrix[i][j--]);
            }
            while (i > k) {
                result.push_back(matrix[i--][j]);
            }
        }
        return result;
    }
};
