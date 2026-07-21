
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
#ifdef DEFENSIVE
        if (nums.empty()) throw std::invalid_argument(
            "The vector 'nums' cannot be empty for a non-empty subarray to be found."
        );
#endif

        auto max = nums[0];
        auto curr = nums[0];

        for (auto i = 1; i < nums.size(); ++i)
        {
            if (curr < 0) {
                // discard any previous subarray summing to a negative number
                curr = 0;
            }
            curr += nums[i];
            max = std::max(max, curr);
        }
        return max;
    }
};
