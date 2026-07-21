
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        if (m <= 0 || n <= 0) {
            return 0;
        }

        auto dp = vector<vector<int>>(m,vector<int>(n));
        dp[0][0] = 1;

        for (auto i = 1; i < m; ++i) {
            dp[i][0] = dp[i-1][0];
        }
        for (auto j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j-1];
        }

        for (auto i = 1; i < m; ++i)
            for (auto j = 1; j < n; ++j)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }

        return dp[m-1][n-1];
    }
};
