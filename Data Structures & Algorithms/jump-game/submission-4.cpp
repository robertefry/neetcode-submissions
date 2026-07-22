
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        if (nums.empty()) {
            return true; // vacuous truth
        }

        auto dp = vector<bool>(nums.size(),false);
        dp[0] = true;

        for (auto i = 0; i < nums.size(); ++i)
            if (dp[i])
                for (auto j = 1; j < std::min((size_t)nums[i]+1,nums.size()-i); ++j)
        {
            dp[i+j] = true;
        }

        return dp[nums.size()-1];
    }
};
