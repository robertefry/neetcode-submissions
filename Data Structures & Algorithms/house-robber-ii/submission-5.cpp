
class Solution {
public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 0) {
            return 0;
        }

        auto dp = array<array<int,3>,2>{};
        dp[0][2] = nums[0];

        for (size_t i = 1; i < nums.size()-1; ++i) {
            dp[0] = { dp[0][1], dp[0][2], nums[i] + max(dp[0][0], dp[0][1]) };
            dp[1] = { dp[1][1], dp[1][2], nums[i] + max(dp[1][0], dp[1][1]) };
        }
        dp[1][2] = nums.back() + max(dp[1][0], dp[1][1]);

        return max(
            max(dp[0][1], dp[0][2]),
            max(dp[1][1], dp[1][2])
        );
    }
};
