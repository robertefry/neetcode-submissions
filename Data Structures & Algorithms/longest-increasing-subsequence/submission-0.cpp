
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.empty()) {
            return 0;
        }

        auto dp = vector<int>(nums.size(),1);

        for (size_t i = nums.size()-1; i < nums.size(); --i)
            for (size_t j = i+1; j < nums.size(); ++j)
        {
            if (nums[j] <= nums[i]) {
                continue;
            }
            // if (dp[i] > nums.size() - j) {
            //     // here, even if j..n is increasing meaning nums[j] is maximised,
            //     // nums[i] is already larger. so there's no point continuing.
            //     break;
            // }
            dp[i] = max(dp[i], 1 + dp[j]);
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};
