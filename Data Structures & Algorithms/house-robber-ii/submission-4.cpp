
class Solution {
public:
    int rob(vector<int>& nums)
    {
        auto constexpr rob_linear = [](auto iter, auto const& end)
        {
            auto dp = array<int,3>{};

            for (; iter != end; ++iter) {
                dp = { dp[1], dp[2], *iter + max(dp[0], dp[1]) };
            }
            return max(dp[1], dp[2]);
        };

        switch (nums.size()) {
            break; case 0: return 0;
            break; case 1: return nums[0];
            break; default: return max(
                rob_linear(nums.cbegin(), std::prev(nums.cend())),
                rob_linear(std::next(nums.cbegin()), nums.cend())
            );
        }
    }
};
