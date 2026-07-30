
class Solution {
public:
    int climbStairs(int n)
    {
        // dp[n] = dp[n-1] + dp[n-2] : dp[0] = dp[1] = 1
        auto dp = array{ 1, 1 };

        for (size_t i = 2; i <= n; ++i) {
            dp = array{ dp[1], dp[0] + dp[1] };
        }
        return dp[1];
    }
};
