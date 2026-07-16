
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        for (size_t i = 0; i+1 < matrix.size(); ++i)
            for (size_t j = i; j+i+1 < matrix.size(); ++j)
        {
            auto const u = matrix.size() - i - 1;
            auto const v = matrix.size() - j - 1;

            auto const tmp = matrix[i][j];
            matrix[i][j] = matrix[v][i];
            matrix[v][i] = matrix[u][v];
            matrix[u][v] = matrix[j][u];
            matrix[j][u] = tmp;
        }
    }
};
