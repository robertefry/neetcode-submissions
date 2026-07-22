
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        if (nums.empty()) {
            return true; // vacuous truth
        }

        auto max_range = 0;

        for (auto i = 0; i < nums.size(); ++i) {
            if (i > max_range) {
                return false;
            }
            max_range = std::max(max_range, i + nums[i]);
        }
        return true;
    }
};
