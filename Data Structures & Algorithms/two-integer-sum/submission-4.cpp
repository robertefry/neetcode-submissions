
#include <utility>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        auto diff_map = unordered_map<int,int>{}; // (target-nums[i]) -> i

        for (int i = 0; i < nums.size(); ++i)
        {
            if (diff_map.contains(nums[i])) {
                return vector<int>{ diff_map[nums[i]], i };
            }
            diff_map.insert({target - nums[i], i});
        }
        unreachable();
    }
};
