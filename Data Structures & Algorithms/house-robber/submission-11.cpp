
class Solution {
public:
    int rob(vector<int>& nums)
    {
        auto dp = array<int,3>{};

        for (size_t i = 0; i < nums.size(); ++i) {
            dp = { dp[1], dp[2], nums[i] + max(dp[0], dp[1]) };
        }
        return max(dp[1], dp[2]);
    }
};
