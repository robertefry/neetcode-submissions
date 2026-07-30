
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        auto dp = vector<int>(nums.size(),1);
        auto dp_max = 0;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            for (size_t j = 0; j < i; ++j)
            {
                if (nums[j] >= nums[i]) {
                    continue;
                }
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            dp_max = max(dp_max, dp[i]);
        }

        return dp_max;
    }
};
