
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
            dp[n%2][j] = 1;
        }

        while (--n > 0)
        {
            dp[n%2][0] = 1;
            for (auto j = 1; j < m; ++j) {
                dp[n%2][j] = dp[n%2][j-1] + dp[(n+1)%2][j];
            }
        }

        return dp[1][m-1];
    }
};
