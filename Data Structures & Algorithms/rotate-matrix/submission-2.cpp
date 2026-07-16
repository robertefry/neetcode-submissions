
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        for (size_t i = 0; 2*i < matrix.size(); ++i)
        {
            auto const j = matrix.size() - i - 1;
            swap(matrix[i], matrix[j]);
        }

        for (size_t i = 0; i < matrix.size(); ++i)
            for (size_t j = i; j < matrix.size(); ++ j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
};
