
class Solution {
public:
    int coinChange(vector<int>& coins, int target)
    {
        auto dp = vector<int>(target+1, -1);
        dp[0] = 0;

        for (size_t i = 0; i <= target; ++i)
            for (auto coin : coins)
                if (coin <= i && dp[i-coin] != -1)
        {
            if (dp[i] == -1) {
                dp[i] = 1 + dp[i-coin];
            } else {
                dp[i] = min(dp[i], 1 + dp[i-coin]);
            }
        }
        return dp[target];
    }
};
