
#include <utility>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        auto diff_map = unordered_map<int,size_t>{}; // (target-nums[i]) -> i

        for (size_t i = 0; i < nums.size(); ++i)
        {
            auto const found = diff_map.find(nums[i]);
            if (found != diff_map.end()) {
                return vector<int>{ (int)found->second, (int)i };
            }

            diff_map.insert({target - nums[i], i});
        }
        unreachable();
    }
};
