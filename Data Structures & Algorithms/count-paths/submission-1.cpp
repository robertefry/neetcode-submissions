
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        if (m <= 0 || n <= 0) {
            return 0;
        }

        int* dp[2] = {
            static_cast<int*>(alloca(m * sizeof(int))),
            static_cast<int*>(alloca(m * sizeof(int)))
        };

        for (auto j = 0; j < m; ++j) {
            dp[0][j] = 1;
        }

        while (--n > 0)
        {
            dp[1][0] = 1;

            for (auto j = 1; j < m; ++j) {
                dp[1][j] = dp[1][j-1] + dp[0][j];
            }
            dp[0] = dp[1];
        }

        return dp[0][m-1];
    }
};
